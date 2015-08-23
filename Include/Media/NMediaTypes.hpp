#ifndef N_MEDIA_TYPES_HPP_INCLUDED
#define N_MEDIA_TYPES_HPP_INCLUDED

#include <Core/NTypes.hpp>
namespace Neurotec { namespace Media
{
#include <Media/NMediaTypes.h>
}}

N_DEFINE_ENUM_TYPE_TRAITS(Neurotec::Media, NMediaType)
N_DEFINE_ENUM_TYPE_TRAITS(Neurotec::Media, NMediaState)
N_DEFINE_ENUM_TYPE_TRAITS(Neurotec::Media, NVideoInterlaceMode)

namespace Neurotec { namespace Media
{

class NMediaTypes
{
	N_DECLARE_STATIC_OBJECT_CLASS(NMediaTypes)

public:
	static NType NMediaTypeNativeTypeOf()
	{
		return NObject::GetObject<NType>(N_TYPE_OF(NMediaType), true);
	}

	static NType NMediaStateNativeTypeOf()
	{
		return NObject::GetObject<NType>(N_TYPE_OF(NMediaState), true);
	}

	static NType NVideoInterlaceModeNativeTypeOf()
	{
		return NObject::GetObject<NType>(N_TYPE_OF(NVideoInterlaceMode), true);
	}

	static bool IsMediaTypeValid(NMediaType value)
	{
		return NMediaTypeIsValid(value) != 0;
	}

	static bool IsMediaTypeValidSingle(NMediaType value)
	{
		return NMediaTypeIsValidSingle(value) != 0;
	}

	static bool IsVideoInterlaceModeValid(NVideoInterlaceMode value)
	{
		return NVideoInterlaceModeIsValid(value) != 0;
	}
};

}}

#endif // !N_MEDIA_TYPES_HPP_INCLUDED
