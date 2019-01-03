/* -LICENSE-START-
** Copyright (c) 2014 Blackmagic Design
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

#ifndef BMD_DECKLINKAPI_H
#define BMD_DECKLINKAPI_H


#ifndef BMD_CONST
    #if defined(_MSC_VER)
        #define BMD_CONST __declspec(selectany) static const
    #else
        #define BMD_CONST static const
    #endif
#endif

/* DeckLink API */

#include <stdint.h>
#include "LinuxCOM.h"

#include "DeckLinkAPITypes.h"
#include "DeckLinkAPIModes.h"
#include "DeckLinkAPIDiscovery.h"
#include "DeckLinkAPIConfiguration.h"
#include "DeckLinkAPIDeckControl.h"

#define BLACKMAGIC_DECKLINK_API_MAGIC	1


 // Declarations


// Interface ID Declarations

BMD_CONST REFIID IID_IDeckLinkVideoOutputCallback                 = /* 20AA5225-1958-47CB-820B-80A8D521A6EE */ {0x20,0xAA,0x52,0x25,0x19,0x58,0x47,0xCB,0x82,0x0B,0x80,0xA8,0xD5,0x21,0xA6,0xEE};
BMD_CONST REFIID IID_IDeckLinkInputCallback                       = /* DD04E5EC-7415-42AB-AE4A-E80C4DFC044A */ {0xDD,0x04,0xE5,0xEC,0x74,0x15,0x42,0xAB,0xAE,0x4A,0xE8,0x0C,0x4D,0xFC,0x04,0x4A};
BMD_CONST REFIID IID_IDeckLinkMemoryAllocator                     = /* B36EB6E7-9D29-4AA8-92EF-843B87A289E8 */ {0xB3,0x6E,0xB6,0xE7,0x9D,0x29,0x4A,0xA8,0x92,0xEF,0x84,0x3B,0x87,0xA2,0x89,0xE8};
BMD_CONST REFIID IID_IDeckLinkAudioOutputCallback                 = /* 403C681B-7F46-4A12-B993-2BB127084EE6 */ {0x40,0x3C,0x68,0x1B,0x7F,0x46,0x4A,0x12,0xB9,0x93,0x2B,0xB1,0x27,0x08,0x4E,0xE6};
BMD_CONST REFIID IID_IDeckLinkIterator                            = /* 50FB36CD-3063-4B73-BDBB-958087F2D8BA */ {0x50,0xFB,0x36,0xCD,0x30,0x63,0x4B,0x73,0xBD,0xBB,0x95,0x80,0x87,0xF2,0xD8,0xBA};
BMD_CONST REFIID IID_IDeckLinkAPIInformation                      = /* 7BEA3C68-730D-4322-AF34-8A7152B532A4 */ {0x7B,0xEA,0x3C,0x68,0x73,0x0D,0x43,0x22,0xAF,0x34,0x8A,0x71,0x52,0xB5,0x32,0xA4};
BMD_CONST REFIID IID_IDeckLinkOutput                              = /* CC5C8A6E-3F2F-4B3A-87EA-FD78AF300564 */ {0xCC,0x5C,0x8A,0x6E,0x3F,0x2F,0x4B,0x3A,0x87,0xEA,0xFD,0x78,0xAF,0x30,0x05,0x64};
BMD_CONST REFIID IID_IDeckLinkInput                               = /* AF22762B-DFAC-4846-AA79-FA8883560995 */ {0xAF,0x22,0x76,0x2B,0xDF,0xAC,0x48,0x46,0xAA,0x79,0xFA,0x88,0x83,0x56,0x09,0x95};
BMD_CONST REFIID IID_IDeckLinkVideoFrame                          = /* 3F716FE0-F023-4111-BE5D-EF4414C05B17 */ {0x3F,0x71,0x6F,0xE0,0xF0,0x23,0x41,0x11,0xBE,0x5D,0xEF,0x44,0x14,0xC0,0x5B,0x17};
BMD_CONST REFIID IID_IDeckLinkMutableVideoFrame                   = /* 69E2639F-40DA-4E19-B6F2-20ACE815C390 */ {0x69,0xE2,0x63,0x9F,0x40,0xDA,0x4E,0x19,0xB6,0xF2,0x20,0xAC,0xE8,0x15,0xC3,0x90};
BMD_CONST REFIID IID_IDeckLinkVideoFrame3DExtensions              = /* DA0F7E4A-EDC7-48A8-9CDD-2DB51C729CD7 */ {0xDA,0x0F,0x7E,0x4A,0xED,0xC7,0x48,0xA8,0x9C,0xDD,0x2D,0xB5,0x1C,0x72,0x9C,0xD7};
BMD_CONST REFIID IID_IDeckLinkVideoInputFrame                     = /* 05CFE374-537C-4094-9A57-680525118F44 */ {0x05,0xCF,0xE3,0x74,0x53,0x7C,0x40,0x94,0x9A,0x57,0x68,0x05,0x25,0x11,0x8F,0x44};
BMD_CONST REFIID IID_IDeckLinkVideoFrameAncillary                 = /* 732E723C-D1A4-4E29-9E8E-4A88797A0004 */ {0x73,0x2E,0x72,0x3C,0xD1,0xA4,0x4E,0x29,0x9E,0x8E,0x4A,0x88,0x79,0x7A,0x00,0x04};
BMD_CONST REFIID IID_IDeckLinkAudioInputPacket                    = /* E43D5870-2894-11DE-8C30-0800200C9A66 */ {0xE4,0x3D,0x58,0x70,0x28,0x94,0x11,0xDE,0x8C,0x30,0x08,0x00,0x20,0x0C,0x9A,0x66};
BMD_CONST REFIID IID_IDeckLinkScreenPreviewCallback               = /* B1D3F49A-85FE-4C5D-95C8-0B5D5DCCD438 */ {0xB1,0xD3,0xF4,0x9A,0x85,0xFE,0x4C,0x5D,0x95,0xC8,0x0B,0x5D,0x5D,0xCC,0xD4,0x38};
BMD_CONST REFIID IID_IDeckLinkGLScreenPreviewHelper               = /* 504E2209-CAC7-4C1A-9FB4-C5BB6274D22F */ {0x50,0x4E,0x22,0x09,0xCA,0xC7,0x4C,0x1A,0x9F,0xB4,0xC5,0xBB,0x62,0x74,0xD2,0x2F};
BMD_CONST REFIID IID_IDeckLinkNotificationCallback                = /* B002A1EC-070D-4288-8289-BD5D36E5FF0D */ {0xB0,0x02,0xA1,0xEC,0x07,0x0D,0x42,0x88,0x82,0x89,0xBD,0x5D,0x36,0xE5,0xFF,0x0D};
BMD_CONST REFIID IID_IDeckLinkNotification                        = /* 0A1FB207-E215-441B-9B19-6FA1575946C5 */ {0x0A,0x1F,0xB2,0x07,0xE2,0x15,0x44,0x1B,0x9B,0x19,0x6F,0xA1,0x57,0x59,0x46,0xC5};
BMD_CONST REFIID IID_IDeckLinkAttributes                          = /* ABC11843-D966-44CB-96E2-A1CB5D3135C4 */ {0xAB,0xC1,0x18,0x43,0xD9,0x66,0x44,0xCB,0x96,0xE2,0xA1,0xCB,0x5D,0x31,0x35,0xC4};
BMD_CONST REFIID IID_IDeckLinkKeyer                               = /* 89AFCAF5-65F8-421E-98F7-96FE5F5BFBA3 */ {0x89,0xAF,0xCA,0xF5,0x65,0xF8,0x42,0x1E,0x98,0xF7,0x96,0xFE,0x5F,0x5B,0xFB,0xA3};
BMD_CONST REFIID IID_IDeckLinkVideoConversion                     = /* 3BBCB8A2-DA2C-42D9-B5D8-88083644E99A */ {0x3B,0xBC,0xB8,0xA2,0xDA,0x2C,0x42,0xD9,0xB5,0xD8,0x88,0x08,0x36,0x44,0xE9,0x9A};
BMD_CONST REFIID IID_IDeckLinkDeviceNotificationCallback          = /* 4997053B-0ADF-4CC8-AC70-7A50C4BE728F */ {0x49,0x97,0x05,0x3B,0x0A,0xDF,0x4C,0xC8,0xAC,0x70,0x7A,0x50,0xC4,0xBE,0x72,0x8F};
BMD_CONST REFIID IID_IDeckLinkDiscovery                           = /* CDBF631C-BC76-45FA-B44D-C55059BC6101 */ {0xCD,0xBF,0x63,0x1C,0xBC,0x76,0x45,0xFA,0xB4,0x4D,0xC5,0x50,0x59,0xBC,0x61,0x01};

/* Enum BMDVideoOutputFlags - Flags to control the output of ancillary data along with video. */

typedef uint32_t BMDVideoOutputFlags;
enum _BMDVideoOutputFlags {
    bmdVideoOutputFlagDefault                                    = 0,
    bmdVideoOutputVANC                                           = 1 << 0,
    bmdVideoOutputVITC                                           = 1 << 1,
    bmdVideoOutputRP188                                          = 1 << 2,
    bmdVideoOutputDualStream3D                                   = 1 << 4
};

/* Enum BMDFrameFlags - Frame flags */

typedef uint32_t BMDFrameFlags;
enum _BMDFrameFlags {
    bmdFrameFlagDefault                                          = 0,
    bmdFrameFlagFlipVertical                                     = 1 << 0,

    /* Flags that are applicable only to instances of IDeckLinkVideoInputFrame */

    bmdFrameHasNoInputSource                                     = 1 << 31
};

/* Enum BMDVideoInputFlags - Flags applicable to video input */

typedef uint32_t BMDVideoInputFlags;
enum _BMDVideoInputFlags {
    bmdVideoInputFlagDefault                                     = 0,
    bmdVideoInputEnableFormatDetection                           = 1 << 0,
    bmdVideoInputDualStream3D                                    = 1 << 1
};

/* Enum BMDVideoInputFormatChangedEvents - Bitmask passed to the VideoInputFormatChanged notification to identify the properties of the input signal that have changed */

typedef uint32_t BMDVideoInputFormatChangedEvents;
enum _BMDVideoInputFormatChangedEvents {
    bmdVideoInputDisplayModeChanged                              = 1 << 0,
    bmdVideoInputFieldDominanceChanged                           = 1 << 1,
    bmdVideoInputColorspaceChanged                               = 1 << 2
};

/* Enum BMDDetectedVideoInputFormatFlags - Flags passed to the VideoInputFormatChanged notification to describe the detected video input signal */

typedef uint32_t BMDDetectedVideoInputFormatFlags;
enum _BMDDetectedVideoInputFormatFlags {
    bmdDetectedVideoInputYCbCr422                                = 1 << 0,
    bmdDetectedVideoInputRGB444                                  = 1 << 1,
    bmdDetectedVideoInputDualStream3D                            = 1 << 2
};

/* Enum BMDDeckLinkCapturePassthroughMode - Enumerates whether the video output is electrically connected to the video input or if the clean switching mode is enabled */

typedef uint32_t BMDDeckLinkCapturePassthroughMode;
enum _BMDDeckLinkCapturePassthroughMode {
    bmdDeckLinkCapturePassthroughModeDirect                      = /* 'pdir' */ 0x70646972,
    bmdDeckLinkCapturePassthroughModeCleanSwitch                 = /* 'pcln' */ 0x70636C6E
};

/* Enum BMDOutputFrameCompletionResult - Frame Completion Callback */

typedef uint32_t BMDOutputFrameCompletionResult;
enum _BMDOutputFrameCompletionResult {
    bmdOutputFrameCompleted,                                    
    bmdOutputFrameDisplayedLate,                                
    bmdOutputFrameDropped,                                      
    bmdOutputFrameFlushed                                       
};

/* Enum BMDReferenceStatus - GenLock input status */

typedef uint32_t BMDReferenceStatus;
enum _BMDReferenceStatus {
    bmdReferenceNotSupportedByHardware                           = 1 << 0,
    bmdReferenceLocked                                           = 1 << 1
};

/* Enum BMDAudioSampleRate - Audio sample rates supported for output/input */

typedef uint32_t BMDAudioSampleRate;
enum _BMDAudioSampleRate {
    bmdAudioSampleRate48kHz                                      = 48000
};

/* Enum BMDAudioSampleType - Audio sample sizes supported for output/input */

typedef uint32_t BMDAudioSampleType;
enum _BMDAudioSampleType {
    bmdAudioSampleType16bitInteger                               = 16,
    bmdAudioSampleType32bitInteger                               = 32
};

/* Enum BMDAudioOutputStreamType - Audio output stream type */

typedef uint32_t BMDAudioOutputStreamType;
enum _BMDAudioOutputStreamType {
    bmdAudioOutputStreamContinuous,                             
    bmdAudioOutputStreamContinuousDontResample,                 
    bmdAudioOutputStreamTimestamped                             
};

/* Enum BMDDisplayModeSupport - Output mode supported flags */

typedef uint32_t BMDDisplayModeSupport;
enum _BMDDisplayModeSupport {
    bmdDisplayModeNotSupported                                   = 0,
    bmdDisplayModeSupported,                                    
    bmdDisplayModeSupportedWithConversion                       
};

/* Enum BMDTimecodeFormat - Timecode formats for frame metadata */

typedef uint32_t BMDTimecodeFormat;
enum _BMDTimecodeFormat {
    bmdTimecodeRP188VITC1                                        = /* 'rpv1' */ 0x72707631,	// RP188 timecode where DBB1 equals VITC1 (line 9)
    bmdTimecodeRP188VITC2                                        = /* 'rp12' */ 0x72703132,	// RP188 timecode where DBB1 equals VITC2 (line 9 for progressive or line 571 for interlaced/PsF)
    bmdTimecodeRP188LTC                                          = /* 'rplt' */ 0x72706C74,	// RP188 timecode where DBB1 equals LTC (line 10)
    bmdTimecodeRP188Any                                          = /* 'rp18' */ 0x72703138,	// For capture: return the first valid timecode in {VITC1, LTC ,VITC2} - For playback: set the timecode as VITC1
    bmdTimecodeVITC                                              = /* 'vitc' */ 0x76697463,
    bmdTimecodeVITCField2                                        = /* 'vit2' */ 0x76697432,
    bmdTimecodeSerial                                            = /* 'seri' */ 0x73657269
};

/* Enum BMDAnalogVideoFlags - Analog video display flags */

typedef uint32_t BMDAnalogVideoFlags;
enum _BMDAnalogVideoFlags {
    bmdAnalogVideoFlagCompositeSetup75                           = 1 << 0,
    bmdAnalogVideoFlagComponentBetacamLevels                     = 1 << 1
};

/* Enum BMDAudioOutputAnalogAESSwitch - Audio output Analog/AESEBU switch */

typedef uint32_t BMDAudioOutputAnalogAESSwitch;
enum _BMDAudioOutputAnalogAESSwitch {
    bmdAudioOutputSwitchAESEBU                                   = /* 'aes ' */ 0x61657320,
    bmdAudioOutputSwitchAnalog                                   = /* 'anlg' */ 0x616E6C67
};

/* Enum BMDVideoOutputConversionMode - Video/audio conversion mode */

typedef uint32_t BMDVideoOutputConversionMode;
enum _BMDVideoOutputConversionMode {
    bmdNoVideoOutputConversion                                   = /* 'none' */ 0x6E6F6E65,
    bmdVideoOutputLetterboxDownconversion                        = /* 'ltbx' */ 0x6C746278,
    bmdVideoOutputAnamorphicDownconversion                       = /* 'amph' */ 0x616D7068,
    bmdVideoOutputHD720toHD1080Conversion                        = /* '720c' */ 0x37323063,
    bmdVideoOutputHardwareLetterboxDownconversion                = /* 'HWlb' */ 0x48576C62,
    bmdVideoOutputHardwareAnamorphicDownconversion               = /* 'HWam' */ 0x4857616D,
    bmdVideoOutputHardwareCenterCutDownconversion                = /* 'HWcc' */ 0x48576363,
    bmdVideoOutputHardware720p1080pCrossconversion               = /* 'xcap' */ 0x78636170,
    bmdVideoOutputHardwareAnamorphic720pUpconversion             = /* 'ua7p' */ 0x75613770,
    bmdVideoOutputHardwareAnamorphic1080iUpconversion            = /* 'ua1i' */ 0x75613169,
    bmdVideoOutputHardwareAnamorphic149To720pUpconversion        = /* 'u47p' */ 0x75343770,
    bmdVideoOutputHardwareAnamorphic149To1080iUpconversion       = /* 'u41i' */ 0x75343169,
    bmdVideoOutputHardwarePillarbox720pUpconversion              = /* 'up7p' */ 0x75703770,
    bmdVideoOutputHardwarePillarbox1080iUpconversion             = /* 'up1i' */ 0x75703169
};

/* Enum BMDVideoInputConversionMode - Video input conversion mode */

typedef uint32_t BMDVideoInputConversionMode;
enum _BMDVideoInputConversionMode {
    bmdNoVideoInputConversion                                    = /* 'none' */ 0x6E6F6E65,
    bmdVideoInputLetterboxDownconversionFromHD1080               = /* '10lb' */ 0x31306C62,
    bmdVideoInputAnamorphicDownconversionFromHD1080              = /* '10am' */ 0x3130616D,
    bmdVideoInputLetterboxDownconversionFromHD720                = /* '72lb' */ 0x37326C62,
    bmdVideoInputAnamorphicDownconversionFromHD720               = /* '72am' */ 0x3732616D,
    bmdVideoInputLetterboxUpconversion                           = /* 'lbup' */ 0x6C627570,
    bmdVideoInputAnamorphicUpconversion                          = /* 'amup' */ 0x616D7570
};

/* Enum BMDVideo3DPackingFormat - Video 3D packing format */

typedef uint32_t BMDVideo3DPackingFormat;
enum _BMDVideo3DPackingFormat {
    bmdVideo3DPackingSidebySideHalf                              = /* 'sbsh' */ 0x73627368,
    bmdVideo3DPackingLinebyLine                                  = /* 'lbyl' */ 0x6C62796C,
    bmdVideo3DPackingTopAndBottom                                = /* 'tabo' */ 0x7461626F,
    bmdVideo3DPackingFramePacking                                = /* 'frpk' */ 0x6672706B,
    bmdVideo3DPackingLeftOnly                                    = /* 'left' */ 0x6C656674,
    bmdVideo3DPackingRightOnly                                   = /* 'righ' */ 0x72696768
};

/* Enum BMDIdleVideoOutputOperation - Video output operation when not playing video */

typedef uint32_t BMDIdleVideoOutputOperation;
enum _BMDIdleVideoOutputOperation {
    bmdIdleVideoOutputBlack                                      = /* 'blac' */ 0x626C6163,
    bmdIdleVideoOutputLastFrame                                  = /* 'lafa' */ 0x6C616661,
    bmdIdleVideoOutputDesktop                                    = /* 'desk' */ 0x6465736B
};

/* Enum BMDDeckLinkAttributeID - DeckLink Attribute ID */

typedef uint32_t BMDDeckLinkAttributeID;
enum _BMDDeckLinkAttributeID {

    /* Flags */

    BMDDeckLinkSupportsInternalKeying                            = /* 'keyi' */ 0x6B657969,
    BMDDeckLinkSupportsExternalKeying                            = /* 'keye' */ 0x6B657965,
    BMDDeckLinkSupportsHDKeying                                  = /* 'keyh' */ 0x6B657968,
    BMDDeckLinkSupportsInputFormatDetection                      = /* 'infd' */ 0x696E6664,
    BMDDeckLinkHasReferenceInput                                 = /* 'hrin' */ 0x6872696E,
    BMDDeckLinkHasSerialPort                                     = /* 'hspt' */ 0x68737074,
    BMDDeckLinkHasAnalogVideoOutputGain                          = /* 'avog' */ 0x61766F67,
    BMDDeckLinkCanOnlyAdjustOverallVideoOutputGain               = /* 'ovog' */ 0x6F766F67,
    BMDDeckLinkHasVideoInputAntiAliasingFilter                   = /* 'aafl' */ 0x6161666C,
    BMDDeckLinkHasBypass                                         = /* 'byps' */ 0x62797073,
    BMDDeckLinkSupportsDesktopDisplay                            = /* 'extd' */ 0x65787464,
    BMDDeckLinkSupportsClockTimingAdjustment                     = /* 'ctad' */ 0x63746164,
    BMDDeckLinkSupportsFullDuplex                                = /* 'fdup' */ 0x66647570,
    BMDDeckLinkSupportsFullFrameReferenceInputTimingOffset       = /* 'frin' */ 0x6672696E,

    /* Integers */

    BMDDeckLinkMaximumAudioChannels                              = /* 'mach' */ 0x6D616368,
    BMDDeckLinkMaximumAnalogAudioChannels                        = /* 'aach' */ 0x61616368,
    BMDDeckLinkNumberOfSubDevices                                = /* 'nsbd' */ 0x6E736264,
    BMDDeckLinkSubDeviceIndex                                    = /* 'subi' */ 0x73756269,
    BMDDeckLinkPersistentID                                      = /* 'peid' */ 0x70656964,
    BMDDeckLinkTopologicalID                                     = /* 'toid' */ 0x746F6964,
    BMDDeckLinkVideoOutputConnections                            = /* 'vocn' */ 0x766F636E,
    BMDDeckLinkVideoInputConnections                             = /* 'vicn' */ 0x7669636E,
    BMDDeckLinkAudioOutputConnections                            = /* 'aocn' */ 0x616F636E,
    BMDDeckLinkAudioInputConnections                             = /* 'aicn' */ 0x6169636E,
    BMDDeckLinkDeviceBusyState                                   = /* 'dbst' */ 0x64627374,
    BMDDeckLinkVideoIOSupport                                    = /* 'vios' */ 0x76696F73,	// Returns a BMDVideoIOSupport bit field

    /* Floats */

    BMDDeckLinkVideoInputGainMinimum                             = /* 'vigm' */ 0x7669676D,
    BMDDeckLinkVideoInputGainMaximum                             = /* 'vigx' */ 0x76696778,
    BMDDeckLinkVideoOutputGainMinimum                            = /* 'vogm' */ 0x766F676D,
    BMDDeckLinkVideoOutputGainMaximum                            = /* 'vogx' */ 0x766F6778,

    /* Strings */

    BMDDeckLinkSerialPortDeviceName                              = /* 'slpn' */ 0x736C706E
};

/* Enum BMDDeckLinkAPIInformationID - DeckLinkAPI information ID */

typedef uint32_t BMDDeckLinkAPIInformationID;
enum _BMDDeckLinkAPIInformationID {
    BMDDeckLinkAPIVersion                                        = /* 'vers' */ 0x76657273
};

/* Enum BMDDeviceBusyState - Current device busy state */

typedef uint32_t BMDDeviceBusyState;
enum _BMDDeviceBusyState {
    bmdDeviceCaptureBusy                                         = 1 << 0,
    bmdDevicePlaybackBusy                                        = 1 << 1,
    bmdDeviceSerialPortBusy                                      = 1 << 2
};

/* Enum BMDVideoIOSupport - Device video input/output support */

typedef uint32_t BMDVideoIOSupport;
enum _BMDVideoIOSupport {
    bmdDeviceSupportsCapture                                     = 1 << 0,
    bmdDeviceSupportsPlayback                                    = 1 << 1
};

/* Enum BMD3DPreviewFormat - Linked Frame preview format */

typedef uint32_t BMD3DPreviewFormat;
enum _BMD3DPreviewFormat {
    bmd3DPreviewFormatDefault                                    = /* 'defa' */ 0x64656661,
    bmd3DPreviewFormatLeftOnly                                   = /* 'left' */ 0x6C656674,
    bmd3DPreviewFormatRightOnly                                  = /* 'righ' */ 0x72696768,
    bmd3DPreviewFormatSideBySide                                 = /* 'side' */ 0x73696465,
    bmd3DPreviewFormatTopBottom                                  = /* 'topb' */ 0x746F7062
};

/* Enum BMDNotifications - Events that can be subscribed through IDeckLinkNotification */

typedef uint32_t BMDNotifications;
enum _BMDNotifications {
    bmdPreferencesChanged                                        = /* 'pref' */ 0x70726566
};

#if defined(__cplusplus)

// Forward Declarations

class IDeckLinkVideoOutputCallback;
class IDeckLinkInputCallback;
class IDeckLinkMemoryAllocator;
class IDeckLinkAudioOutputCallback;
class IDeckLinkIterator;
class IDeckLinkAPIInformation;
class IDeckLinkOutput;
class IDeckLinkInput;
class IDeckLinkVideoFrame;
class IDeckLinkMutableVideoFrame;
class IDeckLinkVideoFrame3DExtensions;
class IDeckLinkVideoInputFrame;
class IDeckLinkVideoFrameAncillary;
class IDeckLinkAudioInputPacket;
class IDeckLinkScreenPreviewCallback;
class IDeckLinkGLScreenPreviewHelper;
class IDeckLinkNotificationCallback;
class IDeckLinkNotification;
class IDeckLinkAttributes;
class IDeckLinkKeyer;
class IDeckLinkVideoConversion;
class IDeckLinkDeviceNotificationCallback;
class IDeckLinkDiscovery;

/* Interface IDeckLinkVideoOutputCallback - Frame completion callback. */

class IDeckLinkVideoOutputCallback : public IUnknown
{
public:
    virtual HRESULT ScheduledFrameCompleted (/* in */ IDeckLinkVideoFrame *completedFrame, /* in */ BMDOutputFrameCompletionResult result) = 0;
    virtual HRESULT ScheduledPlaybackHasStopped (void) = 0;

protected:
    virtual ~IDeckLinkVideoOutputCallback () {} // call Release method to drop reference count
};

/* Interface IDeckLinkInputCallback - Frame arrival callback. */

class IDeckLinkInputCallback : public IUnknown
{
public:
    virtual HRESULT VideoInputFormatChanged (/* in */ BMDVideoInputFormatChangedEvents notificationEvents, /* in */ IDeckLinkDisplayMode *newDisplayMode, /* in */ BMDDetectedVideoInputFormatFlags detectedSignalFlags) = 0;
    virtual HRESULT VideoInputFrameArrived (/* in */ IDeckLinkVideoInputFrame* videoFrame, /* in */ IDeckLinkAudioInputPacket* audioPacket) = 0;

protected:
    virtual ~IDeckLinkInputCallback () {} // call Release method to drop reference count
};

/* Interface IDeckLinkMemoryAllocator - Memory allocator for video frames. */

class IDeckLinkMemoryAllocator : public IUnknown
{
public:
    virtual HRESULT AllocateBuffer (/* in */ uint32_t bufferSize, /* out */ void **allocatedBuffer) = 0;
    virtual HRESULT ReleaseBuffer (/* in */ void *buffer) = 0;

    virtual HRESULT Commit (void) = 0;
    virtual HRESULT Decommit (void) = 0;
};

/* Interface IDeckLinkAudioOutputCallback - Optional callback to allow audio samples to be pulled as required. */

class IDeckLinkAudioOutputCallback : public IUnknown
{
public:
    virtual HRESULT RenderAudioSamples (/* in */ bool preroll) = 0;
};

/* Interface IDeckLinkIterator - enumerates installed DeckLink hardware */

class IDeckLinkIterator : public IUnknown
{
public:
    virtual HRESULT Next (/* out */ IDeckLink **deckLinkInstance) = 0;
};

/* Interface IDeckLinkAPIInformation - DeckLinkAPI attribute interface */

class IDeckLinkAPIInformation : public IUnknown
{
public:
    virtual HRESULT GetFlag (/* in */ BMDDeckLinkAPIInformationID cfgID, /* out */ bool *value) = 0;
    // virtual HRESULT GetInt (/* in */ BMDDeckLinkAPIInformationID cfgID, /* out */ int64_t *value) = 0;
    virtual HRESULT GetInt (/* in */ BMDDeckLinkAPIInformationID cfgID, /* out */ signed long long int *value) = 0;
    
    virtual HRESULT GetFloat (/* in */ BMDDeckLinkAPIInformationID cfgID, /* out */ double *value) = 0;
    virtual HRESULT GetString (/* in */ BMDDeckLinkAPIInformationID cfgID, /* out */ const char **value) = 0;

protected:
    virtual ~IDeckLinkAPIInformation () {} // call Release method to drop reference count
};

/* Interface IDeckLinkOutput - Created by QueryInterface from IDeckLink. */

class IDeckLinkOutput : public IUnknown
{
public:
    virtual HRESULT DoesSupportVideoMode (/* in */ BMDDisplayMode displayMode, /* in */ BMDPixelFormat pixelFormat, /* in */ BMDVideoOutputFlags flags, /* out */ BMDDisplayModeSupport *result, /* out */ IDeckLinkDisplayMode **resultDisplayMode) = 0;
    virtual HRESULT GetDisplayModeIterator (/* out */ IDeckLinkDisplayModeIterator **iterator) = 0;

    virtual HRESULT SetScreenPreviewCallback (/* in */ IDeckLinkScreenPreviewCallback *previewCallback) = 0;

    /* Video Output */

    virtual HRESULT EnableVideoOutput (/* in */ BMDDisplayMode displayMode, /* in */ BMDVideoOutputFlags flags) = 0;
    virtual HRESULT DisableVideoOutput (void) = 0;

    virtual HRESULT SetVideoOutputFrameMemoryAllocator (/* in */ IDeckLinkMemoryAllocator *theAllocator) = 0;
    virtual HRESULT CreateVideoFrame (/* in */ int32_t width, /* in */ int32_t height, /* in */ int32_t rowBytes, /* in */ BMDPixelFormat pixelFormat, /* in */ BMDFrameFlags flags, /* out */ IDeckLinkMutableVideoFrame **outFrame) = 0;
    virtual HRESULT CreateAncillaryData (/* in */ BMDPixelFormat pixelFormat, /* out */ IDeckLinkVideoFrameAncillary **outBuffer) = 0;

    virtual HRESULT DisplayVideoFrameSync (/* in */ IDeckLinkVideoFrame *theFrame) = 0;
    virtual HRESULT ScheduleVideoFrame (/* in */ IDeckLinkVideoFrame *theFrame, /* in */ BMDTimeValue displayTime, /* in */ BMDTimeValue displayDuration, /* in */ BMDTimeScale timeScale) = 0;
    virtual HRESULT SetScheduledFrameCompletionCallback (/* in */ IDeckLinkVideoOutputCallback *theCallback) = 0;
    virtual HRESULT GetBufferedVideoFrameCount (/* out */ uint32_t *bufferedFrameCount) = 0;

    /* Audio Output */

    virtual HRESULT EnableAudioOutput (/* in */ BMDAudioSampleRate sampleRate, /* in */ BMDAudioSampleType sampleType, /* in */ uint32_t channelCount, /* in */ BMDAudioOutputStreamType streamType) = 0;
    virtual HRESULT DisableAudioOutput (void) = 0;

    virtual HRESULT WriteAudioSamplesSync (/* in */ void *buffer, /* in */ uint32_t sampleFrameCount, /* out */ uint32_t *sampleFramesWritten) = 0;

    virtual HRESULT BeginAudioPreroll (void) = 0;
    virtual HRESULT EndAudioPreroll (void) = 0;
    virtual HRESULT ScheduleAudioSamples (/* in */ void *buffer, /* in */ uint32_t sampleFrameCount, /* in */ BMDTimeValue streamTime, /* in */ BMDTimeScale timeScale, /* out */ uint32_t *sampleFramesWritten) = 0;

    virtual HRESULT GetBufferedAudioSampleFrameCount (/* out */ uint32_t *bufferedSampleFrameCount) = 0;
    virtual HRESULT FlushBufferedAudioSamples (void) = 0;

    virtual HRESULT SetAudioCallback (/* in */ IDeckLinkAudioOutputCallback *theCallback) = 0;

    /* Output Control */

    virtual HRESULT StartScheduledPlayback (/* in */ BMDTimeValue playbackStartTime, /* in */ BMDTimeScale timeScale, /* in */ double playbackSpeed) = 0;
    virtual HRESULT StopScheduledPlayback (/* in */ BMDTimeValue stopPlaybackAtTime, /* out */ BMDTimeValue *actualStopTime, /* in */ BMDTimeScale timeScale) = 0;
    virtual HRESULT IsScheduledPlaybackRunning (/* out */ bool *active) = 0;
    virtual HRESULT GetScheduledStreamTime (/* in */ BMDTimeScale desiredTimeScale, /* out */ BMDTimeValue *streamTime, /* out */ double *playbackSpeed) = 0;
    virtual HRESULT GetReferenceStatus (/* out */ BMDReferenceStatus *referenceStatus) = 0;

    /* Hardware Timing */

    virtual HRESULT GetHardwareReferenceClock (/* in */ BMDTimeScale desiredTimeScale, /* out */ BMDTimeValue *hardwareTime, /* out */ BMDTimeValue *timeInFrame, /* out */ BMDTimeValue *ticksPerFrame) = 0;
    virtual HRESULT GetFrameCompletionReferenceTimestamp (/* in */ IDeckLinkVideoFrame *theFrame, /* in */ BMDTimeScale desiredTimeScale, /* out */ BMDTimeValue *frameCompletionTimestamp) = 0;

protected:
    virtual ~IDeckLinkOutput () {} // call Release method to drop reference count
};

/* Interface IDeckLinkInput - Created by QueryInterface from IDeckLink. */

class IDeckLinkInput : public IUnknown
{
public:
    virtual HRESULT DoesSupportVideoMode (/* in */ BMDDisplayMode displayMode, /* in */ BMDPixelFormat pixelFormat, /* in */ BMDVideoInputFlags flags, /* out */ BMDDisplayModeSupport *result, /* out */ IDeckLinkDisplayMode **resultDisplayMode) = 0;
    virtual HRESULT GetDisplayModeIterator (/* out */ IDeckLinkDisplayModeIterator **iterator) = 0;

    virtual HRESULT SetScreenPreviewCallback (/* in */ IDeckLinkScreenPreviewCallback *previewCallback) = 0;

    /* Video Input */

    virtual HRESULT EnableVideoInput (/* in */ BMDDisplayMode displayMode, /* in */ BMDPixelFormat pixelFormat, /* in */ BMDVideoInputFlags flags) = 0;
    virtual HRESULT DisableVideoInput (void) = 0;
    virtual HRESULT GetAvailableVideoFrameCount (/* out */ uint32_t *availableFrameCount) = 0;
    virtual HRESULT SetVideoInputFrameMemoryAllocator (/* in */ IDeckLinkMemoryAllocator *theAllocator) = 0;

    /* Audio Input */

    virtual HRESULT EnableAudioInput (/* in */ BMDAudioSampleRate sampleRate, /* in */ BMDAudioSampleType sampleType, /* in */ uint32_t channelCount) = 0;
    virtual HRESULT DisableAudioInput (void) = 0;
    virtual HRESULT GetAvailableAudioSampleFrameCount (/* out */ uint32_t *availableSampleFrameCount) = 0;

    /* Input Control */

    virtual HRESULT StartStreams (void) = 0;
    virtual HRESULT StopStreams (void) = 0;
    virtual HRESULT PauseStreams (void) = 0;
    virtual HRESULT FlushStreams (void) = 0;
    virtual HRESULT SetCallback (/* in */ IDeckLinkInputCallback *theCallback) = 0;

    /* Hardware Timing */

    virtual HRESULT GetHardwareReferenceClock (/* in */ BMDTimeScale desiredTimeScale, /* out */ BMDTimeValue *hardwareTime, /* out */ BMDTimeValue *timeInFrame, /* out */ BMDTimeValue *ticksPerFrame) = 0;

protected:
    virtual ~IDeckLinkInput () {} // call Release method to drop reference count
};

/* Interface IDeckLinkVideoFrame - Interface to encapsulate a video frame; can be caller-implemented. */

class IDeckLinkVideoFrame : public IUnknown
{
public:
    virtual long GetWidth (void) = 0;
    virtual long GetHeight (void) = 0;
    virtual long GetRowBytes (void) = 0;
    virtual BMDPixelFormat GetPixelFormat (void) = 0;
    virtual BMDFrameFlags GetFlags (void) = 0;
    virtual HRESULT GetBytes (/* out */ void **buffer) = 0;

    virtual HRESULT GetTimecode (/* in */ BMDTimecodeFormat format, /* out */ IDeckLinkTimecode **timecode) = 0;
    virtual HRESULT GetAncillaryData (/* out */ IDeckLinkVideoFrameAncillary **ancillary) = 0;

protected:
    virtual ~IDeckLinkVideoFrame () {} // call Release method to drop reference count
};

/* Interface IDeckLinkMutableVideoFrame - Created by IDeckLinkOutput::CreateVideoFrame. */

class IDeckLinkMutableVideoFrame : public IDeckLinkVideoFrame
{
public:
    virtual HRESULT SetFlags (/* in */ BMDFrameFlags newFlags) = 0;

    virtual HRESULT SetTimecode (/* in */ BMDTimecodeFormat format, /* in */ IDeckLinkTimecode *timecode) = 0;
    virtual HRESULT SetTimecodeFromComponents (/* in */ BMDTimecodeFormat format, /* in */ uint8_t hours, /* in */ uint8_t minutes, /* in */ uint8_t seconds, /* in */ uint8_t frames, /* in */ BMDTimecodeFlags flags) = 0;
    virtual HRESULT SetAncillaryData (/* in */ IDeckLinkVideoFrameAncillary *ancillary) = 0;
    virtual HRESULT SetTimecodeUserBits (/* in */ BMDTimecodeFormat format, /* in */ BMDTimecodeUserBits userBits) = 0;

protected:
    virtual ~IDeckLinkMutableVideoFrame () {} // call Release method to drop reference count
};

/* Interface IDeckLinkVideoFrame3DExtensions - Optional interface implemented on IDeckLinkVideoFrame to support 3D frames */

class IDeckLinkVideoFrame3DExtensions : public IUnknown
{
public:
    virtual BMDVideo3DPackingFormat Get3DPackingFormat (void) = 0;
    virtual HRESULT GetFrameForRightEye (/* out */ IDeckLinkVideoFrame* *rightEyeFrame) = 0;

protected:
    virtual ~IDeckLinkVideoFrame3DExtensions () {} // call Release method to drop reference count
};

/* Interface IDeckLinkVideoInputFrame - Provided by the IDeckLinkVideoInput frame arrival callback. */

class IDeckLinkVideoInputFrame : public IDeckLinkVideoFrame
{
public:
    virtual HRESULT GetStreamTime (/* out */ BMDTimeValue *frameTime, /* out */ BMDTimeValue *frameDuration, /* in */ BMDTimeScale timeScale) = 0;
    virtual HRESULT GetHardwareReferenceTimestamp (/* in */ BMDTimeScale timeScale, /* out */ BMDTimeValue *frameTime, /* out */ BMDTimeValue *frameDuration) = 0;

protected:
    virtual ~IDeckLinkVideoInputFrame () {} // call Release method to drop reference count
};

/* Interface IDeckLinkVideoFrameAncillary - Obtained through QueryInterface() on an IDeckLinkVideoFrame object. */

class IDeckLinkVideoFrameAncillary : public IUnknown
{
public:

    virtual HRESULT GetBufferForVerticalBlankingLine (/* in */ uint32_t lineNumber, /* out */ void **buffer) = 0;
    virtual BMDPixelFormat GetPixelFormat (void) = 0;
    virtual BMDDisplayMode GetDisplayMode (void) = 0;

protected:
    virtual ~IDeckLinkVideoFrameAncillary () {} // call Release method to drop reference count
};

/* Interface IDeckLinkAudioInputPacket - Provided by the IDeckLinkInput callback. */

class IDeckLinkAudioInputPacket : public IUnknown
{
public:
    virtual long GetSampleFrameCount (void) = 0;
    virtual HRESULT GetBytes (/* out */ void **buffer) = 0;
    virtual HRESULT GetPacketTime (/* out */ BMDTimeValue *packetTime, /* in */ BMDTimeScale timeScale) = 0;

protected:
    virtual ~IDeckLinkAudioInputPacket () {} // call Release method to drop reference count
};

/* Interface IDeckLinkScreenPreviewCallback - Screen preview callback */

class IDeckLinkScreenPreviewCallback : public IUnknown
{
public:
    virtual HRESULT DrawFrame (/* in */ IDeckLinkVideoFrame *theFrame) = 0;

protected:
    virtual ~IDeckLinkScreenPreviewCallback () {} // call Release method to drop reference count
};

/* Interface IDeckLinkGLScreenPreviewHelper - Created with CoCreateInstance(). */

class IDeckLinkGLScreenPreviewHelper : public IUnknown
{
public:

    /* Methods must be called with OpenGL context set */

    virtual HRESULT InitializeGL (void) = 0;
    virtual HRESULT PaintGL (void) = 0;
    virtual HRESULT SetFrame (/* in */ IDeckLinkVideoFrame *theFrame) = 0;
    virtual HRESULT Set3DPreviewFormat (/* in */ BMD3DPreviewFormat previewFormat) = 0;

protected:
    virtual ~IDeckLinkGLScreenPreviewHelper () {} // call Release method to drop reference count
};

/* Interface IDeckLinkNotificationCallback - DeckLink Notification Callback Interface */

class IDeckLinkNotificationCallback : public IUnknown
{
public:
    // virtual HRESULT Notify (/* in */ BMDNotifications topic, /* in */ uint64_t param1, /* in */ uint64_t param2) = 0;
    virtual HRESULT Notify (/* in */ BMDNotifications topic, /* in */ unsigned long long int param1, /* in */ unsigned long long int param2) = 0;

};

/* Interface IDeckLinkNotification - DeckLink Notification interface */

class IDeckLinkNotification : public IUnknown
{
public:
    virtual HRESULT Subscribe (/* in */ BMDNotifications topic, /* in */ IDeckLinkNotificationCallback *theCallback) = 0;
    virtual HRESULT Unsubscribe (/* in */ BMDNotifications topic, /* in */ IDeckLinkNotificationCallback *theCallback) = 0;
};

/* Interface IDeckLinkAttributes - DeckLink Attribute interface */

class IDeckLinkAttributes : public IUnknown
{
public:
    virtual HRESULT GetFlag (/* in */ BMDDeckLinkAttributeID cfgID, /* out */ bool *value) = 0;
    // virtual HRESULT GetInt (/* in */ BMDDeckLinkAttributeID cfgID, /* out */ int64_t *value) = 0;
    virtual HRESULT GetInt (/* in */ BMDDeckLinkAttributeID cfgID, /* out */ unsigned long long int *value) = 0;
    virtual HRESULT GetFloat (/* in */ BMDDeckLinkAttributeID cfgID, /* out */ double *value) = 0;
    virtual HRESULT GetString (/* in */ BMDDeckLinkAttributeID cfgID, /* out */ const char **value) = 0;

protected:
    virtual ~IDeckLinkAttributes () {} // call Release method to drop reference count
};

/* Interface IDeckLinkKeyer - DeckLink Keyer interface */

class IDeckLinkKeyer : public IUnknown
{
public:
    virtual HRESULT Enable (/* in */ bool isExternal) = 0;
    virtual HRESULT SetLevel (/* in */ uint8_t level) = 0;
    virtual HRESULT RampUp (/* in */ uint32_t numberOfFrames) = 0;
    virtual HRESULT RampDown (/* in */ uint32_t numberOfFrames) = 0;
    virtual HRESULT Disable (void) = 0;

protected:
    virtual ~IDeckLinkKeyer () {} // call Release method to drop reference count
};

/* Interface IDeckLinkVideoConversion - Created with CoCreateInstance(). */

class IDeckLinkVideoConversion : public IUnknown
{
public:
    virtual HRESULT ConvertFrame (/* in */ IDeckLinkVideoFrame* srcFrame, /* in */ IDeckLinkVideoFrame* dstFrame) = 0;

protected:
    virtual ~IDeckLinkVideoConversion () {} // call Release method to drop reference count
};

/* Interface IDeckLinkDeviceNotificationCallback - DeckLink device arrival/removal notification callbacks */

class IDeckLinkDeviceNotificationCallback : public IUnknown
{
public:
    virtual HRESULT DeckLinkDeviceArrived (/* in */ IDeckLink* deckLinkDevice) = 0;
    virtual HRESULT DeckLinkDeviceRemoved (/* in */ IDeckLink* deckLinkDevice) = 0;

protected:
    virtual ~IDeckLinkDeviceNotificationCallback () {} // call Release method to drop reference count
};

/* Interface IDeckLinkDiscovery - DeckLink device discovery */

class IDeckLinkDiscovery : public IUnknown
{
public:
    virtual HRESULT InstallDeviceNotifications (/* in */ IDeckLinkDeviceNotificationCallback* deviceNotificationCallback) = 0;
    virtual HRESULT UninstallDeviceNotifications (void) = 0;

protected:
    virtual ~IDeckLinkDiscovery () {} // call Release method to drop reference count
};

/* Functions */

extern "C" {

    IDeckLinkIterator* CreateDeckLinkIteratorInstance (void);
    IDeckLinkDiscovery* CreateDeckLinkDiscoveryInstance (void);
    IDeckLinkAPIInformation* CreateDeckLinkAPIInformationInstance (void);
    IDeckLinkGLScreenPreviewHelper* CreateOpenGLScreenPreviewHelper (void);
    IDeckLinkVideoConversion* CreateVideoConversionInstance (void);

}


#endif      // defined(__cplusplus)
#endif /* defined(BMD_DECKLINKAPI_H) */
