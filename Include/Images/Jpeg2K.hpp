#ifndef JPEG2K_HPP_INCLUDED
#define JPEG2K_HPP_INCLUDED

#include <Images/NImage.hpp>
namespace Neurotec { namespace Images
{
#include <Images/Jpeg2K.h>
}}

N_DEFINE_ENUM_TYPE_TRAITS(Neurotec::Images, Jpeg2KProfile)

namespace Neurotec { namespace Images
{

#undef JPEG_2K_DEFAULT_RATIO

const NFloat JPEG_2K_DEFAULT_RATIO = 10.0f;

class Jpeg2KInfo : public NImageInfo
{
	N_DECLARE_OBJECT_CLASS(Jpeg2KInfo, NImageInfo)

public:
	static NType Jpeg2KProfileNativeTypeOf()
	{
		return NObject::GetObject<NType>(N_TYPE_OF(Jpeg2KProfile), true);
	}

	Jpeg2KProfile GetProfile() const
	{
		Jpeg2KProfile value;
		NCheck(Jpeg2KInfoGetProfile(GetHandle(), &value));
		return value;
	}

	void SetProfile(Jpeg2KProfile value)
	{
		NCheck(Jpeg2KInfoSetProfile(GetHandle(), value));
	}

	NFloat GetRatio() const
	{
		NFloat value;
		NCheck(Jpeg2KInfoGetRatio(GetHandle(), &value));
		return value;
	}

	void SetRatio(NFloat value)
	{
		NCheck(Jpeg2KInfoSetRatio(GetHandle(), value));
	}
};

}}

#endif // !JPEG2K_HPP_INCLUDED
