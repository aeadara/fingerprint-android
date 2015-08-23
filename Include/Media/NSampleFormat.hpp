#ifndef N_SAMPLE_FORMAT_HPP_INCLUDED
#define N_SAMPLE_FORMAT_HPP_INCLUDED

#include <Core/NTypes.hpp>
namespace Neurotec { namespace Media
{
#include <Media/NSampleFormat.h>
}}

N_DEFINE_ENUM_TYPE_TRAITS(Neurotec::Media, NExtraChannel)
N_DEFINE_ENUM_TYPE_TRAITS(Neurotec::Media, NChannelFormat)

namespace Neurotec { namespace Media
{
#undef N_SAMPLE_FORMAT_MAX_CHANNEL_COUNT

const NInt N_SAMPLE_FORMAT_MAX_CHANNEL_COUNT = 15;

class NSampleFormat
{
	N_DECLARE_BASIC_CLASS_BASE(NSampleFormat)

public:
	static NType NExtraChannelNativeTypeOf()
	{
		return NObject::GetObject<NType>(N_TYPE_OF(NExtraChannel), true);
	}

	static NType NChannelFormatNativeTypeOf()
	{
		return NObject::GetObject<NType>(N_TYPE_OF(NChannelFormat), true);
	}

	static bool IsExtraChannelValid(NExtraChannel value)
	{
		return NExtraChannelIsValid(value) != 0;
	}

	static bool IsChannelFormatValid(NChannelFormat value)
	{
		return NChannelFormatIsValid(value) != 0;
	}

	NExtraChannel GetExtraChannel() const
	{
		return NSampleFormatGetExtraChannel(value);
	}

	NInt GetChannelCount() const
	{
		return NSampleFormatGetChannelCount(value);
	}

	NChannelFormat GetChannelFormat() const
	{
		return NSampleFormatGetChannelFormat(value);
	}

	NInt GetBitsPerChannel() const
	{
		return NSampleFormatGetBitsPerChannel(value);
	}

	bool IsIndexed() const
	{
		return NSampleFormatIsIndexed(value) != 0;
	}

	NInt GetBitsPerIndex() const
	{
		return NSampleFormatGetBitsPerIndex(value);
	}

	NInt GetMaxPaletteLength() const
	{
		return NSampleFormatGetMaxPaletteLength(value);
	}

	bool IsSeparated() const
	{
		return NSampleFormatIsSeparated(value) != 0;
	}

	NInt GetPlaneCount() const
	{
		return NSampleFormatGetPlaneCount(value);
	}

	NInt GetBitsPerValue() const
	{
		return NSampleFormatGetBitsPerValue(value);
	}

	NInt GetBitsPerSample() const
	{
		return NSampleFormatGetBitsPerSample(value);
	}

	NInt GetBitsPerPaletteEntry() const
	{
		return NSampleFormatGetBitsPerPaletteEntry(value);
	}

	NSizeType GetBytesPerChannel() const
	{
		return NSampleFormatGetBytesPerChannel(value);
	}

	NSizeType GetBytesPerValue() const
	{
		return NSampleFormatGetBytesPerValue(value);
	}

	NSizeType GetBytesPerSample() const
	{
		return NSampleFormatGetBytesPerSample(value);
	}

	NSizeType GetBytesPerPaletteEntry() const
	{
		return NSampleFormatGetBytesPerPaletteEntry(value);
	}

	NType GetChannelType() const
	{
		HNType hValue;
		NCheck(NSampleFormatGetChannelType(value, &hValue));
		return NObject::FromHandle<NType>(hValue);
	}
};

}}

#endif // !N_SAMPLE_FORMAT_HPP_INCLUDED
