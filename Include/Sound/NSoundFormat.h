#ifndef N_SOUND_FORMAT_H_INCLUDED
#define N_SOUND_FORMAT_H_INCLUDED

#include <Media/NSampleFormat.h>

#ifdef N_CPP
extern "C"
{
#endif

typedef enum NSoundType_
{
	nstUndefined = 0,
	nstMono = 1,
	nstStereo = 2,
} NSoundType;

N_DECLARE_TYPE(NSoundType)

NBool N_API NSoundTypeIsValid(NSoundType value);

typedef NSampleFormat_ NSoundFormat_;
#ifndef N_SOUND_FORMAT_HPP_INCLUDED
typedef NSoundFormat_ NSoundFormat;
#endif
N_DECLARE_TYPE(NSoundFormat)

#define NSF_UNDEFINED  0

#define NSF_MONO_8U    0x00301001
#define NSF_MONO_8S    0x00311001
#define NSF_MONO_16U   0x00401001
#define NSF_MONO_16S   0x00411001
#define NSF_MONO_32U   0x00501001
#define NSF_MONO_32S   0x00511001
#define NSF_MONO_64U   0x00601001
#define NSF_MONO_64S   0x00611001
#define NSF_MONO_32F   0x00521001
#define NSF_MONO_64F   0x00621001

#define NSF_STEREO_8U  0x00302002
#define NSF_STEREO_8S  0x00312002
#define NSF_STEREO_16U 0x00402002
#define NSF_STEREO_16S 0x00412002
#define NSF_STEREO_32U 0x00502002
#define NSF_STEREO_32S 0x00512002
#define NSF_STEREO_64U 0x00602002
#define NSF_STEREO_64S 0x00612002
#define NSF_STEREO_32F 0x00522002
#define NSF_STEREO_64F 0x00622002

NResult N_API NSoundFormatCalcBlockSize(NInt bitsPerSample, NInt length, NSizeType * pValue);

NResult N_API NSoundFormatCreate(NSoundType soundType, NInt channelCount, NChannelFormat channelFormat, NInt bitsPerChannel, NSoundFormat_ * pValue);

NBool N_API NSoundFormatIsValid(NSoundFormat_ value);
NResult N_API NSoundFormatGetBlockSize(NSoundFormat_ soundFormat, NInt length, NSizeType * pValue);

NResult N_API NSoundFormatToStringN(NSoundFormat_ soundFormat, HNString hFormat, HNString * phValue);
NResult N_API NSoundFormatToStringA(NSoundFormat_ soundFormat, const NAChar * szFormat, HNString * phValue);
#ifndef N_NO_UNICODE
NResult N_API NSoundFormatToStringW(NSoundFormat_ soundFormat, const NWChar * szFormat, HNString * phValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NSoundFormatToString(NSoundFormat soundFormat, const NChar * szFormat, HNString * phValue);
#endif
#define NSoundFormatToString N_FUNC_AW(NSoundFormatToString)

NSoundType N_API NSoundFormatGetSoundType(NSoundFormat_ soundFormat);

#ifdef N_CPP
}
#endif

#endif // !N_SOUND_FORMAT_H_INCLUDED
