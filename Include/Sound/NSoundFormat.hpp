#ifndef N_SOUND_FORMAT_HPP_INCLUDED
#define N_SOUND_FORMAT_HPP_INCLUDED

#include <Media/NSampleFormat.hpp>
namespace Neurotec { namespace Sound
{
using ::Neurotec::Media::NChannelFormat;
using ::Neurotec::Media::NSampleFormat_;
#include <Sound/NSoundFormat.h>
}}

N_DEFINE_ENUM_TYPE_TRAITS(Neurotec::Sound, NSoundType)

namespace Neurotec { namespace Sound
{

#undef NSF_UNDEFINED

#undef NSF_MONO_8U
#undef NSF_MONO_8S
#undef NSF_MONO_16U
#undef NSF_MONO_16S
#undef NSF_MONO_32U
#undef NSF_MONO_32S
#undef NSF_MONO_64U
#undef NSF_MONO_64S
#undef NSF_MONO_32F
#undef NSF_MONO_64F

#undef NSF_STEREO_8U
#undef NSF_STEREO_8S
#undef NSF_STEREO_16U
#undef NSF_STEREO_16S
#undef NSF_STEREO_32U
#undef NSF_STEREO_32S
#undef NSF_STEREO_64U
#undef NSF_STEREO_64S
#undef NSF_STEREO_32F
#undef NSF_STEREO_64F

class NSoundFormat : public ::Neurotec::Media::NSampleFormat
{
	N_DECLARE_BASIC_CLASS_DERIVED(NSoundFormat, ::Neurotec::Media::NSampleFormat)

public:
	static NType NSoundTypeNativeTypeOf()
	{
		return NObject::GetObject<NType>(N_TYPE_OF(NSoundType), true);
	}

	static bool IsSoundTypeValid(NSoundType value)
	{
		return NSoundTypeIsValid(value) != 0;
	}

	static NSizeType CalcBlockSize(NInt bitsPerSample, NInt length)
	{
		NSizeType value;
		NCheck(NSoundFormatCalcBlockSize(bitsPerSample, length, &value));
		return value;
	}

	NSoundFormat(NSoundType soundType, NInt channelCount, NChannelFormat channelFormat, NInt bitsPerChannel)
	{
		NCheck(NSoundFormatCreate(soundType, channelCount, channelFormat, bitsPerChannel, &value));
	}

	bool IsValid()
	{
		return NSoundFormatIsValid(value) != 0;
	}

	NSizeType GetBlockSize(NInt length) const
	{
		NSizeType value;
		NCheck(NSoundFormatGetBlockSize(this->value, length, &value));
		return value;
	}

	NString ToString(const NStringWrapper & format = NString()) const
	{
		HNString hValue;
		NCheck(NSoundFormatToStringN(value, format.GetHandle(), &hValue));
		return NString(hValue, true);
	}

	NSoundType GetSoundType() const
	{
		return NSoundFormatGetSoundType(value);
	}
};

const NSoundFormat NSF_UNDEFINED(0);

const NSoundFormat NSF_MONO_8U(0x00301001);
const NSoundFormat NSF_MONO_8S(0x00311001);
const NSoundFormat NSF_MONO_16U(0x00401001);
const NSoundFormat NSF_MONO_16S(0x00411001);
const NSoundFormat NSF_MONO_32U(0x00501001);
const NSoundFormat NSF_MONO_32S(0x00511001);
const NSoundFormat NSF_MONO_64U(0x00601001);
const NSoundFormat NSF_MONO_64S(0x00611001);
const NSoundFormat NSF_MONO_32F(0x00521001);
const NSoundFormat NSF_MONO_64F(0x00621001);

const NSoundFormat NSF_STEREO_8U(0x00302002);
const NSoundFormat NSF_STEREO_8S(0x00312002);
const NSoundFormat NSF_STEREO_16U(0x00402002);
const NSoundFormat NSF_STEREO_16S(0x00412002);
const NSoundFormat NSF_STEREO_32U(0x00502002);
const NSoundFormat NSF_STEREO_32S(0x00512002);
const NSoundFormat NSF_STEREO_64U(0x00602002);
const NSoundFormat NSF_STEREO_64S(0x00612002);
const NSoundFormat NSF_STEREO_32F(0x00522002);
const NSoundFormat NSF_STEREO_64F(0x00622002);

}}

#endif // !N_SOUND_FORMAT_HPP_INCLUDED
