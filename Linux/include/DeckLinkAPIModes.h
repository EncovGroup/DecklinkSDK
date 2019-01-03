/* -LICENSE-START-
** Copyright (c) 2015 Blackmagic Design
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

#ifndef BMD_DECKLINKAPIMODES_H
#define BMD_DECKLINKAPIMODES_H


#ifndef BMD_CONST
    #if defined(_MSC_VER)
        #define BMD_CONST __declspec(selectany) static const
    #else
        #define BMD_CONST static const
    #endif
#endif

// Type Declarations


// Interface ID Declarations

BMD_CONST REFIID IID_IDeckLinkDisplayModeIterator                 = /* 9C88499F-F601-4021-B80B-032E4EB41C35 */ {0x9C,0x88,0x49,0x9F,0xF6,0x01,0x40,0x21,0xB8,0x0B,0x03,0x2E,0x4E,0xB4,0x1C,0x35};
BMD_CONST REFIID IID_IDeckLinkDisplayMode                         = /* 3EB2C1AB-0A3D-4523-A3AD-F40D7FB14E78 */ {0x3E,0xB2,0xC1,0xAB,0x0A,0x3D,0x45,0x23,0xA3,0xAD,0xF4,0x0D,0x7F,0xB1,0x4E,0x78};

/* Enum BMDDisplayMode - Video display modes */

typedef uint32_t BMDDisplayMode;
enum _BMDDisplayMode {

    /* SD Modes */

    bmdModeNTSC                                                  = /* 'ntsc' */ 0x6E747363,
    bmdModeNTSC2398                                              = /* 'nt23' */ 0x6E743233,	// 3:2 pulldown
    bmdModePAL                                                   = /* 'pal ' */ 0x70616C20,
    bmdModeNTSCp                                                 = /* 'ntsp' */ 0x6E747370,
    bmdModePALp                                                  = /* 'palp' */ 0x70616C70,

    /* HD 1080 Modes */

    bmdModeHD1080p2398                                           = /* '23ps' */ 0x32337073,
    bmdModeHD1080p24                                             = /* '24ps' */ 0x32347073,
    bmdModeHD1080p25                                             = /* 'Hp25' */ 0x48703235,
    bmdModeHD1080p2997                                           = /* 'Hp29' */ 0x48703239,
    bmdModeHD1080p30                                             = /* 'Hp30' */ 0x48703330,
    bmdModeHD1080i50                                             = /* 'Hi50' */ 0x48693530,
    bmdModeHD1080i5994                                           = /* 'Hi59' */ 0x48693539,
    bmdModeHD1080i6000                                           = /* 'Hi60' */ 0x48693630,	// N.B. This _really_ is 60.00 Hz.
    bmdModeHD1080p50                                             = /* 'Hp50' */ 0x48703530,
    bmdModeHD1080p5994                                           = /* 'Hp59' */ 0x48703539,
    bmdModeHD1080p6000                                           = /* 'Hp60' */ 0x48703630,	// N.B. This _really_ is 60.00 Hz.

    /* HD 720 Modes */

    bmdModeHD720p50                                              = /* 'hp50' */ 0x68703530,
    bmdModeHD720p5994                                            = /* 'hp59' */ 0x68703539,
    bmdModeHD720p60                                              = /* 'hp60' */ 0x68703630,

    /* 2k Modes */

    bmdMode2k2398                                                = /* '2k23' */ 0x326B3233,
    bmdMode2k24                                                  = /* '2k24' */ 0x326B3234,
    bmdMode2k25                                                  = /* '2k25' */ 0x326B3235,

    /* DCI Modes (output only) */

    bmdMode2kDCI2398                                             = /* '2d23' */ 0x32643233,
    bmdMode2kDCI24                                               = /* '2d24' */ 0x32643234,
    bmdMode2kDCI25                                               = /* '2d25' */ 0x32643235,

    /* 4k Modes */

    bmdMode4K2160p2398                                           = /* '4k23' */ 0x346B3233,
    bmdMode4K2160p24                                             = /* '4k24' */ 0x346B3234,
    bmdMode4K2160p25                                             = /* '4k25' */ 0x346B3235,
    bmdMode4K2160p2997                                           = /* '4k29' */ 0x346B3239,
    bmdMode4K2160p30                                             = /* '4k30' */ 0x346B3330,
    bmdMode4K2160p50                                             = /* '4k50' */ 0x346B3530,
    bmdMode4K2160p5994                                           = /* '4k59' */ 0x346B3539,
    bmdMode4K2160p60                                             = /* '4k60' */ 0x346B3630,

    /* DCI Modes (output only) */

    bmdMode4kDCI2398                                             = /* '4d23' */ 0x34643233,
    bmdMode4kDCI24                                               = /* '4d24' */ 0x34643234,
    bmdMode4kDCI25                                               = /* '4d25' */ 0x34643235,

    /* Special Modes */

    bmdModeUnknown                                               = /* 'iunk' */ 0x69756E6B
};

/* Enum BMDFieldDominance - Video field dominance */

typedef uint32_t BMDFieldDominance;
enum _BMDFieldDominance {
    bmdUnknownFieldDominance                                     = 0,
    bmdLowerFieldFirst                                           = /* 'lowr' */ 0x6C6F7772,
    bmdUpperFieldFirst                                           = /* 'uppr' */ 0x75707072,
    bmdProgressiveFrame                                          = /* 'prog' */ 0x70726F67,
    bmdProgressiveSegmentedFrame                                 = /* 'psf ' */ 0x70736620
};

/* Enum BMDPixelFormat - Video pixel formats supported for output/input */

typedef uint32_t BMDPixelFormat;
enum _BMDPixelFormat {
    bmdFormat8BitYUV                                             = /* '2vuy' */ 0x32767579,
    bmdFormat10BitYUV                                            = /* 'v210' */ 0x76323130,
    bmdFormat8BitARGB                                            = 32,
    bmdFormat8BitBGRA                                            = /* 'BGRA' */ 0x42475241,
    bmdFormat10BitRGB                                            = /* 'r210' */ 0x72323130,	// Big-endian RGB 10-bit per component with SMPTE video levels (64-960). Packed as 2:10:10:10
    bmdFormat12BitRGB                                            = /* 'R12B' */ 0x52313242,	// Big-endian RGB 12-bit per component with full range (0-4095). Packed as 12-bit per component
    bmdFormat12BitRGBLE                                          = /* 'R12L' */ 0x5231324C,	// Little-endian RGB 12-bit per component with full range (0-4095). Packed as 12-bit per component
    bmdFormat10BitRGBXLE                                         = /* 'R10l' */ 0x5231306C,	// Little-endian 10-bit RGB with SMPTE video levels (64-940)
    bmdFormat10BitRGBX                                           = /* 'R10b' */ 0x52313062	// Big-endian 10-bit RGB with SMPTE video levels (64-940)
};

/* Enum BMDDisplayModeFlags - Flags to describe the characteristics of an IDeckLinkDisplayMode. */

typedef uint32_t BMDDisplayModeFlags;
enum _BMDDisplayModeFlags {
    bmdDisplayModeSupports3D                                     = 1 << 0,
    bmdDisplayModeColorspaceRec601                               = 1 << 1,
    bmdDisplayModeColorspaceRec709                               = 1 << 2
};

// Forward Declarations

class IDeckLinkDisplayModeIterator;
class IDeckLinkDisplayMode;

/* Interface IDeckLinkDisplayModeIterator - enumerates over supported input/output display modes. */

class IDeckLinkDisplayModeIterator : public IUnknown
{
public:
    virtual HRESULT Next (/* out */ IDeckLinkDisplayMode **deckLinkDisplayMode) = 0;

protected:
    virtual ~IDeckLinkDisplayModeIterator () {} // call Release method to drop reference count
};

/* Interface IDeckLinkDisplayMode - represents a display mode */

class IDeckLinkDisplayMode : public IUnknown
{
public:
    virtual HRESULT GetName (/* out */ const char **name) = 0;
    virtual BMDDisplayMode GetDisplayMode (void) = 0;
    virtual long GetWidth (void) = 0;
    virtual long GetHeight (void) = 0;
    virtual HRESULT GetFrameRate (/* out */ BMDTimeValue *frameDuration, /* out */ BMDTimeScale *timeScale) = 0;
    virtual BMDFieldDominance GetFieldDominance (void) = 0;
    virtual BMDDisplayModeFlags GetFlags (void) = 0;

protected:
    virtual ~IDeckLinkDisplayMode () {} // call Release method to drop reference count
};

/* Functions */

extern "C" {


}


#endif /* defined(BMD_DECKLINKAPIMODES_H) */
