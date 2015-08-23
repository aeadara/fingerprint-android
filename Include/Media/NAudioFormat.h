#ifndef N_AUDIO_FORMAT_H_INCLUDED
#define N_AUDIO_FORMAT_H_INCLUDED

#include <Media/NMediaFormat.h>

#ifdef N_CPP
extern "C"
{
#endif

#define N_AUDIO_FORMAT_UNKNOWN                0
#define N_AUDIO_FORMAT_PCM                    1
#define N_AUDIO_FORMAT_FLOAT             0x0003
#define N_AUDIO_FORMAT_DTS               0x0008
#define N_AUDIO_FORMAT_DRM               0x0009
#define N_AUDIO_FORMAT_MSP1              0x000A
#define N_AUDIO_FORMAT_MPEG              0x0050
#define N_AUDIO_FORMAT_MP3               0x0055
#define N_AUDIO_FORMAT_DOLBY_AC3_SPDIF   0x0092
#define N_AUDIO_FORMAT_RAW_AAC1          0x00FF
#define N_AUDIO_FORMAT_WM_AUDIO_V8       0x0161
#define N_AUDIO_FORMAT_WM_AUDIO_V9       0x0162
#define N_AUDIO_FORMAT_WM_AUDIO_LOSSLESS 0x0163
#define N_AUDIO_FORMAT_WMA_SPDIF         0x0164
#define N_AUDIO_FORMAT_ADTS              0x1600
#define N_AUDIO_FORMAT_AAC               0x1610

NResult N_API NAudioFormatMediaSubtypeToStringN(NUInt value, HNString hFormat, HNString * phValue);
NResult N_API NAudioFormatMediaSubtypeToStringA(NUInt value, const NAChar * szFormat, HNString * phValue);
#ifndef N_NO_UNICODE
NResult N_API NAudioFormatMediaSubtypeToStringW(NUInt value, const NWChar * szFormat, HNString * phValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NAudioFormatMediaSubtypeToString(NUInt value, const NChar * szFormat, HNString * phValue);
#endif
#define NAudioFormatMediaSubtypeToString N_FUNC_AW(NAudioFormatMediaSubtypeToString)

N_DECLARE_OBJECT_TYPE(NAudioFormat, NMediaFormat)

NResult N_API NAudioFormatCreate(HNAudioFormat * phAudioFormat);

NResult N_API NAudioFormatGetChannelCount(HNAudioFormat hAudioFormat, NInt * pValue);
NResult N_API NAudioFormatSetChannelCount(HNAudioFormat hAudioFormat, NInt value);
NResult N_API NAudioFormatGetSampleRate(HNAudioFormat hAudioFormat, NInt * pValue);
NResult N_API NAudioFormatSetSampleRate(HNAudioFormat hAudioFormat, NInt value);
NResult N_API NAudioFormatGetBitsPerChannel(HNAudioFormat hAudioFormat, NInt * pValue);
NResult N_API NAudioFormatSetBitsPerChannel(HNAudioFormat hAudioFormat, NInt value);

#ifdef N_CPP
}
#endif

#endif // !N_AUDIO_FORMAT_H_INCLUDED
