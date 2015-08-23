#ifndef N_BIOMETRIC_ENGINE_TYPES_HPP_INCLUDED
#define N_BIOMETRIC_ENGINE_TYPES_HPP_INCLUDED

#include <Core/NTypes.hpp>
namespace Neurotec { namespace Biometrics
{
#include <Biometrics/NBiometricEngineTypes.h>
}}

N_DEFINE_ENUM_TYPE_TRAITS(Neurotec::Biometrics, NMatchingSpeed)
N_DEFINE_ENUM_TYPE_TRAITS(Neurotec::Biometrics, NMFusionType)
N_DEFINE_ENUM_TYPE_TRAITS(Neurotec::Biometrics, NTemplateSize)

namespace Neurotec { namespace Biometrics
{
class NBiometricEngineTypes
{
	N_DECLARE_STATIC_OBJECT_CLASS(NBiometricEngineTypes)

public:
	static NType NMatchingSpeedNativeTypeOf()
	{
		return NObject::GetObject<NType>(N_TYPE_OF(NMatchingSpeed), true);
	}

	static NType NMFusionTypeNativeTypeOf()
	{
		return NObject::GetObject<NType>(N_TYPE_OF(NMFusionType), true);
	}

	static NType NTemplateSizeNativeTypeOf()
	{
		return NObject::GetObject<NType>(N_TYPE_OF(NTemplateSize), true);
	}
};

}}

#endif // !N_BIOMETRIC_ENGINE_TYPES_HPP_INCLUDED
