/* -LICENSE-START-
 ** Copyright (c) 2010 Blackmagic Design
 **
 ** Permission is hereby granted, free of charge, to any person or organization
 ** obtaining a copy of the software and accompanying documentation covered by
 ** this license (the "Software") to use, reproduce, display, distribute,
 ** execute, and transmit the Software, and to prepare derivative works of the
 ** Software, and to permit third-parties to whom the Software is furnished to
 ** do so, all subject to the following:
 ** 
 ** The copyright notices in the Software and this entire statement, including
 ** the above license grant, this restriction and the following disclaimer,
 ** must be included in all copies of the Software, in whole or in part, and
 ** all derivative works of the Software, unless such copies or derivative
 ** works are solely in the form of machine-executable object code generated by
 ** a source language processor.
 ** 
 ** THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 ** IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 ** FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
 ** SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
 ** FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
 ** ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 ** DEALINGS IN THE SOFTWARE.
 ** -LICENSE-END-
 */
//
//  BMDOpenGLOutput.cpp
//  OpenGLOutput
//

#include "BMDOpenGLOutput.h"

BMDOpenGLOutput::BMDOpenGLOutput()
        : pFrameBuf(NULL), pDL(NULL), pDLOutput(NULL), pDLVideoFrame(NULL)
{
	QGLFormat fmt;
	fmt.setRedBufferSize(8);
	fmt.setGreenBufferSize(8);
	fmt.setBlueBufferSize(8);
	fmt.setAlphaBufferSize(8);
	fmt.setDepthBufferSize(16);
	pContext = new QGLWidget(fmt);
	getGLExtensions().ResolveExtensions(pContext->context());
	pGLScene = new GLScene();
}

BMDOpenGLOutput::~BMDOpenGLOutput()
{
	if (pDLOutput != NULL)
	{
		pDLOutput->Release();
		pDLOutput = NULL;
	}		
	if (pDL != NULL)
	{
		pDL->Release();
		pDL = NULL;
	}		
	
	delete pRenderDelegate;
	pRenderDelegate = NULL;

	delete pGLScene;
	pGLScene = NULL;

	delete pContext;
	pContext = NULL;
}

void BMDOpenGLOutput::ResetFrame()
{
	// Fill frame with black
	void*	pFrame;
	pDLVideoFrame->GetBytes((void**)&pFrame);
	memset(pFrame, 0x00, pDLVideoFrame->GetRowBytes() * uiFrameHeight);
}

void BMDOpenGLOutput::SetPreroll()
{
	// Set 1 second preroll
	for (uint32_t i=0; i < uiFPS; i++)
	{
		if (pDLOutput->ScheduleVideoFrame(pDLVideoFrame, (uiTotalFrames * frameDuration), frameDuration, frameTimescale) != S_OK)
			return;
		uiTotalFrames++;
	}
}

bool BMDOpenGLOutput::InitDeckLink()
{
	bool bSuccess = FALSE;
	IDeckLinkIterator* pDLIterator = NULL;

	pDLIterator = CreateDeckLinkIteratorInstance();
	if (pDLIterator == NULL)
	{
		QMessageBox::critical(NULL,"This application requires the DeckLink drivers installed.", "Please install the Blackmagic DeckLink drivers to use the features of this application.");
		goto error;
	}

	if (pDLIterator->Next(&pDL) != S_OK)
	{
		QMessageBox::critical(NULL,"This application requires a DeckLink device.", "You will not be able to use the features of this application until a DeckLink device is installed.");
		goto error;
	}
	
	if (pDL->QueryInterface(IID_IDeckLinkOutput, (void**)&pDLOutput) != S_OK)
		goto error;
	
	pRenderDelegate = new RenderDelegate(this);
	if (pRenderDelegate == NULL)
		goto error;
	
	if (pDLOutput->SetScheduledFrameCompletionCallback(pRenderDelegate) != S_OK)
		goto error;
	
	bSuccess = TRUE;

error:
	
	if (!bSuccess)
	{
		if (pDLOutput != NULL)
		{
			pDLOutput->Release();
			pDLOutput = NULL;
		}
		if (pDL != NULL)
		{
			pDL->Release();
			pDL = NULL;
		}
	}
	
	if (pDLIterator != NULL)
	{
		pDLIterator->Release();
		pDLIterator = NULL;
	}

	return bSuccess;
}

bool BMDOpenGLOutput::InitGUI(IDeckLinkScreenPreviewCallback *previewCallback)
{
	// Set preview
	if (previewCallback != NULL)
	{
		pDLOutput->SetScreenPreviewCallback(previewCallback);
	}
	return true;
}

bool BMDOpenGLOutput::InitOpenGL()
{
	const GLubyte * strExt;
	GLboolean isFBO;
	
	pContext->makeCurrent();
	strExt = glGetString (GL_EXTENSIONS);
	isFBO = gluCheckExtension ((const GLubyte*)"GL_EXT_framebuffer_object", strExt);
	
	if (!isFBO)
	{
		QMessageBox::critical(NULL,"OpenGL initialization error.", "OpenGL extention \"GL_EXT_framebuffer_object\" is not supported.");
		return false;
	}

	return true;
}

uint32_t BMDOpenGLOutput::GetFPS()
{
    return uiFPS;
}

bool BMDOpenGLOutput::Start()
{
	IDeckLinkDisplayModeIterator*		pDLDisplayModeIterator;
	IDeckLinkDisplayMode*				pDLDisplayMode = NULL;
	
	// Get first avaliable video mode for Output
	if (pDLOutput->GetDisplayModeIterator(&pDLDisplayModeIterator) == S_OK)
	{
		if (pDLDisplayModeIterator->Next(&pDLDisplayMode) != S_OK)
		{
			QMessageBox::critical(NULL,"DeckLink error.", "Cannot find video mode.");
			pDLDisplayModeIterator->Release();
			return false;
		}
		pDLDisplayModeIterator->Release();
	}
	
	uiFrameWidth = pDLDisplayMode->GetWidth();
	uiFrameHeight = pDLDisplayMode->GetHeight();
	pDLDisplayMode->GetFrameRate(&frameDuration, &frameTimescale);
	
	uiFPS = ((frameTimescale + (frameDuration-1))  /  frameDuration);
	
	if (pDLOutput->EnableVideoOutput(pDLDisplayMode->GetDisplayMode(), bmdVideoOutputFlagDefault) != S_OK)
		return false;
	
	// Flip frame vertical, because OpenGL rendering starts from left bottom corner
	if (pDLOutput->CreateVideoFrame(uiFrameWidth, uiFrameHeight, uiFrameWidth*4, bmdFormat8BitBGRA, bmdFrameFlagFlipVertical, &pDLVideoFrame) != S_OK)
		return false;
	
	uiTotalFrames = 0;
	
	ResetFrame();
	SetPreroll();

	pContext->makeCurrent();

	pGLScene->InitScene();

	glGenFramebuffersEXT(1, &idFrameBuf);
	glGenRenderbuffersEXT(1, &idColorBuf);
	glGenRenderbuffersEXT(1, &idDepthBuf);
		
	glBindFramebufferEXT(GL_FRAMEBUFFER_EXT, idFrameBuf);
	
	glBindRenderbufferEXT(GL_RENDERBUFFER_EXT, idColorBuf);
	glRenderbufferStorageEXT(GL_RENDERBUFFER_EXT, GL_RGBA8, uiFrameWidth, uiFrameHeight);
	glBindRenderbufferEXT(GL_RENDERBUFFER_EXT, idDepthBuf);
	glRenderbufferStorageEXT(GL_RENDERBUFFER_EXT, GL_DEPTH_COMPONENT, uiFrameWidth, uiFrameHeight);
		
	glFramebufferRenderbufferEXT(GL_FRAMEBUFFER_EXT, GL_COLOR_ATTACHMENT0_EXT, GL_RENDERBUFFER_EXT, idColorBuf);
	glFramebufferRenderbufferEXT(GL_FRAMEBUFFER_EXT, GL_DEPTH_ATTACHMENT_EXT, GL_RENDERBUFFER_EXT, idDepthBuf);
	
	glStatus = glCheckFramebufferStatusEXT(GL_FRAMEBUFFER_EXT);
	if (glStatus != GL_FRAMEBUFFER_COMPLETE_EXT)
	{
		QMessageBox::critical(NULL,"OpenGL initialization error.", "Cannot initialize framebuffer.");
		return false;
	}

	pFrameBuf = (char*)malloc(pDLVideoFrame->GetRowBytes() * uiFrameHeight);
	UpdateScene();

	pDLOutput->StartScheduledPlayback(0, 100, 1.0);
	
	return true;
}

bool BMDOpenGLOutput::Stop()
{
	pDLOutput->StopScheduledPlayback(0, NULL, 0);
	pDLOutput->DisableVideoOutput();
	
	Mutex.lock();
	if (pDLVideoFrame != NULL)
	{
		pDLVideoFrame->Release();
		pDLVideoFrame = NULL;
	}
	
	glBindFramebufferEXT(GL_FRAMEBUFFER_EXT, 0);
		
	glDeleteRenderbuffersEXT(1, &idDepthBuf);
	glDeleteRenderbuffersEXT(1, &idColorBuf);
	glDeleteFramebuffersEXT(1, &idFrameBuf);	

	free(pFrameBuf);
	pFrameBuf = NULL;

	Mutex.unlock();
	return true;
}

void BMDOpenGLOutput::UpdateScene()
{
    Mutex.lock();

    pContext->makeCurrent();

    pGLScene->DrawScene(0, 0, uiFrameWidth, uiFrameHeight);

    glReadPixels(0, 0, uiFrameWidth, uiFrameHeight, GL_BGRA, GL_UNSIGNED_INT_8_8_8_8_REV, pFrameBuf);

    Mutex.unlock();
}

void BMDOpenGLOutput::RenderToDevice()
{
	Mutex.lock();

	void*	pFrame;

	pDLVideoFrame->GetBytes((void**)&pFrame);	

	memcpy(pFrame, pFrameBuf, pDLVideoFrame->GetRowBytes() * uiFrameHeight);

	if (pDLOutput->ScheduleVideoFrame(pDLVideoFrame, (uiTotalFrames * frameDuration), frameDuration, frameTimescale) != S_OK)
	{
		Mutex.unlock();
		return;
	}
	
	uiTotalFrames++;

	Mutex.unlock();
}

////////////////////////////////////////////
// Render Delegate Class
////////////////////////////////////////////
RenderDelegate::RenderDelegate (BMDOpenGLOutput* pOwner)
{
	m_pOwner = pOwner;
}

RenderDelegate::~RenderDelegate ()
{

}

HRESULT	RenderDelegate::ScheduledFrameCompleted (IDeckLinkVideoFrame* /*completedFrame*/, BMDOutputFrameCompletionResult /*result*/)
{
	m_pOwner->RenderToDevice();
	return S_OK;
}


HRESULT	RenderDelegate::ScheduledPlaybackHasStopped ()
{
	return S_OK;
}
