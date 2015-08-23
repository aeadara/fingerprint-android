#ifndef AN_IMAGE_HPP_INCLUDED
#define AN_IMAGE_HPP_INCLUDED

#include <Images/NImage.hpp>
namespace Neurotec { namespace Biometrics { namespace Standards
{
#include <Biometrics/Standards/ANImage.h>
}}}

N_DEFINE_ENUM_TYPE_TRAITS(Neurotec::Biometrics::Standards, ANImageCompressionAlgorithm)
N_DEFINE_ENUM_TYPE_TRAITS(Neurotec::Biometrics::Standards, ANBinaryImageCompressionAlgorithm)
N_DEFINE_ENUM_TYPE_TRAITS(Neurotec::Biometrics::Standards, ANImageColorSpace)

namespace Neurotec { namespace Biometrics { namespace Standards
{

class ANImage
{
	N_DECLARE_STATIC_OBJECT_CLASS(ANImage)

public:
	static NType ANImageCompressionAlgorithmNativeTypeOf()
	{
		return NObject::GetObject<NType>(N_TYPE_OF(ANImageCompressionAlgorithm), true);
	}

	static NType ANBinaryImageCompressionAlgorithmNativeTypeOf()
	{
		return NObject::GetObject<NType>(N_TYPE_OF(ANBinaryImageCompressionAlgorithm), true);
	}

	static NType ANImageColorSpaceNativeTypeOf()
	{
		return NObject::GetObject<NType>(N_TYPE_OF(ANImageColorSpace), true);
	}
};

}}}

#endif // !AN_IMAGE_HPP_INCLUDED
