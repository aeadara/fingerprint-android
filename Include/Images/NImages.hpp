#ifndef N_IMAGES_HPP_INCLUDED
#define N_IMAGES_HPP_INCLUDED

#include <Images/NImage.hpp>
#include <Images/NRgb.hpp>
namespace Neurotec { namespace Images
{
#include <Images/NImages.h>
}}
#include <Text/NStringBuilder.hpp>

namespace Neurotec { namespace Images
{

class NImages
{
	N_DECLARE_STATIC_OBJECT_CLASS(NImages)

public:
	static NImage GetGrayscaleColorWrapper(const NImage & image, const NRgb & minColor, const NRgb & maxColor)
	{
		HNImage hImage;
		NCheck(NImagesGetGrayscaleColorWrapperEx(image.GetHandle(), &minColor, &maxColor, &hImage));
		return NObject::FromHandle<NImage>(hImage);
	}

	static NImage RecolorImage(const NImage & image, const NPixelFormat & pixelFormat, const NArray & minValue, const NArray & maxValue)
	{
		HNImage hImage;
		NCheck(NImagesRecolorImage(image.GetHandle(), pixelFormat.GetValue(), minValue.GetHandle(), maxValue.GetHandle(), &hImage));
		return NObject::FromHandle<NImage>(hImage);
	}
};

}}

#endif // !N_IMAGES_HPP_INCLUDED
