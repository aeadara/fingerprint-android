#ifndef N_SAMPLE_FORMAT_H_INCLUDED
#define N_SAMPLE_FORMAT_H_INCLUDED

#include <Core/NTypes.h>

#ifdef N_CPP
extern "C"
{
#endif

#define N_SAMPLE_FORMAT_MAX_CHANNEL_COUNT 15

typedef enum NExtraChannel_
{
	necNone = 0,
	necAlpha = 1,
	necPAlpha = 2
} NExtraChannel;

N_DECLARE_TYPE(NExtraChannel)

typedef enum NChannelFormat_
{
	ncfUnsignedInteger = 0,
	ncfSignedInteger = 1,
	ncfFloatingPoint = 2
} NChannelFormat;

N_DECLARE_TYPE(NChannelFormat)

NBool N_API NExtraChannelIsValid(NExtraChannel value);
NBool N_API NChannelFormatIsValid(NChannelFormat value);

typedef NUInt NSampleFormat_;
#ifndef N_SAMPLE_FORMAT_HPP_INCLUDED
typedef NSampleFormat_ NSampleFormat;
#endif
N_DECLARE_TYPE(NSampleFormat)

NExtraChannel N_API NSampleFormatGetExtraChannel(NSampleFormat_ sampleFormat);
NInt N_API NSampleFormatGetChannelCount(NSampleFormat_ sampleFormat);
NChannelFormat N_API NSampleFormatGetChannelFormat(NSampleFormat_ sampleFormat);
NInt N_API NSampleFormatGetBitsPerChannel(NSampleFormat_ sampleFormat);
NBool N_API NSampleFormatIsIndexed(NSampleFormat_ sampleFormat);
NInt N_API NSampleFormatGetBitsPerIndex(NSampleFormat_ sampleFormat);
NInt N_API NSampleFormatGetMaxPaletteLength(NSampleFormat_ sampleFormat);
NBool N_API NSampleFormatIsSeparated(NSampleFormat_ sampleFormat);
NInt N_API NSampleFormatGetPlaneCount(NSampleFormat_ sampleFormat);
NInt N_API NSampleFormatGetBitsPerValue(NSampleFormat_ sampleFormat);
NInt N_API NSampleFormatGetBitsPerSample(NSampleFormat_ sampleFormat);
NInt N_API NSampleFormatGetBitsPerPaletteEntry(NSampleFormat_ sampleFormat);
NSizeType N_API NSampleFormatGetBytesPerChannel(NSampleFormat_ sampleFormat);
NSizeType N_API NSampleFormatGetBytesPerValue(NSampleFormat_ sampleFormat);
NSizeType N_API NSampleFormatGetBytesPerSample(NSampleFormat_ sampleFormat);
NSizeType N_API NSampleFormatGetBytesPerPaletteEntry(NSampleFormat_ sampleFormat);
NResult N_API NSampleFormatGetChannelType(NSampleFormat_ sampleFormat, HNType * phValue);

#ifdef N_CPP
}
#endif

#endif // !N_SAMPLE_FORMAT_H_INCLUDED
