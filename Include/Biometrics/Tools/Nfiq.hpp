#ifndef NFIQ_HPP_INCLUDED
#define NFIQ_HPP_INCLUDED

#include <Images/NImage.hpp>
namespace Neurotec { namespace Biometrics { namespace Tools
{
using ::Neurotec::Images::HNGrayscaleImage;
#include <Biometrics/Tools/Nfiq.h>
}}}

namespace Neurotec { namespace Biometrics { namespace Tools
{

class Nfiq
{
	N_DECLARE_STATIC_OBJECT_CLASS(Nfiq)

public:
	static NfiqQuality Compute(const ::Neurotec::Images::NImage & image)
	{
		NfiqQuality quality;
		NCheck(NfiqCompute((HNGrayscaleImage)image.GetHandle(), &quality));
		return quality;
	}
};

}}}

#endif // !NFIQ_HPP_INCLUDED
