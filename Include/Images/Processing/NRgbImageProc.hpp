#ifndef N_RGB_IMAGE_PROC_HPP_INCLUDED
#define N_RGB_IMAGE_PROC_HPP_INCLUDED

#include <Images/NImage.hpp>
#include <Images/NRgb.hpp>
namespace Neurotec { namespace Images { namespace Processing
{
#include <Images/Processing/NRgbImageProc.h>
}}}

namespace Neurotec { namespace Images { namespace Processing
{

class Nrgbip
{
	N_DECLARE_STATIC_OBJECT_CLASS(Nrgbip)

public:
	static NImage Invert(const NImage & image)
	{
		HNImage hResultImage;
		NCheck(NrgbipInvert(image.GetHandle(), &hResultImage));
		return NObject::FromHandle<NImage>(hResultImage);
	}

	static void Invert(const NImage & image, const NImage & dstImage)
	{
		NCheck(NrgbipInvertDst(image.GetHandle(), dstImage.GetHandle()));
	}

	static void InvertSame(const NImage & image)
	{
		NCheck(NrgbipInvertSame(image.GetHandle()));
	}

	static NImage AdjustBrightnessContrast(const NImage & image, NDouble brightness, NDouble contrast)
	{
		HNImage hResultImage;
		NCheck(NrgbipAdjustBrightnessContrast(image.GetHandle(), brightness, contrast, &hResultImage));
		return NObject::FromHandle<NImage>(hResultImage);
	}

	static void AdjustBrightnessContrast(const NImage & image, const NImage & dstImage, NDouble brightness, NDouble contrast)
	{
		NCheck(NrgbipAdjustBrightnessContrastDst(image.GetHandle(), dstImage.GetHandle(), brightness, contrast));
	}

	static void AdjustBrightnessContrastSame(const NImage & image, NDouble brightness, NDouble contrast)
	{
		NCheck(NrgbipAdjustBrightnessContrastSame(image.GetHandle(), brightness, contrast));
	}

	static NImage AdjustBrightnessContrast(const NImage & image,
		NDouble redBrightness, NDouble redContrast, NDouble greenBrightness, NDouble greenContrast, NDouble blueBrightness, NDouble blueContrast)
	{
		HNImage hResultImage;
		NCheck(NrgbipAdjustChannelsBrightnessContrast(image.GetHandle(), redBrightness, redContrast, greenBrightness, greenContrast, blueBrightness, blueContrast, &hResultImage));
		return NObject::FromHandle<NImage>(hResultImage);
	}

	static void AdjustBrightnessContrast(const NImage & image, const NImage & dstImage,
		NDouble redBrightness, NDouble redContrast, NDouble greenBrightness, NDouble greenContrast, NDouble blueBrightness, NDouble blueContrast)
	{
		NCheck(NrgbipAdjustChannelsBrightnessContrastDst(image.GetHandle(), dstImage.GetHandle(), redBrightness, redContrast, greenBrightness, greenContrast, blueBrightness, blueContrast));
	}

	static void AdjustBrightnessContrastSame(const NImage & image,
		NDouble redBrightness, NDouble redContrast, NDouble greenBrightness, NDouble greenContrast, NDouble blueBrightness, NDouble blueContrast)
	{
		NCheck(NrgbipAdjustChannelsBrightnessContrastSame(image.GetHandle(), redBrightness, redContrast, greenBrightness, greenContrast, blueBrightness, blueContrast));
	}

	static NImage ColorMatrixTransform(const NImage & image, const NDouble * pColorMatrix)
	{
		HNImage hResultImage;
		NCheck(NrgbipColorMatrixTransform(image.GetHandle(), pColorMatrix, &hResultImage));
		return NObject::FromHandle<NImage>(hResultImage);
	}

	static void ColorMatrixTransform(const NImage & image, const NImage & dstImage, const NDouble * pColorMatrix)
	{
		NCheck(NrgbipColorMatrixTransformDst(image.GetHandle(), dstImage.GetHandle(), pColorMatrix));
	}

	static void ColorMatrixTransformSame(const NImage & image, const NDouble * pColorMatrix)
	{
		NCheck(NrgbipColorMatrixTransformSame(image.GetHandle(), pColorMatrix));
	}

	static NImage AlphaBlend(const NImage & imageA, const NImage & imageB, NDouble alpha)
	{
		HNImage hResultImage;
		NCheck(NrgbipAlphaBlend(imageA.GetHandle(), imageB.GetHandle(), alpha, &hResultImage));
		return NObject::FromHandle<NImage>(hResultImage);
	}

	static void AlphaBlend(const NImage & imageA, const NImage & imageB, NDouble alpha, const NImage & dstImage)
	{
		NCheck(NrgbipAlphaBlendDst(imageA.GetHandle(), imageB.GetHandle(), dstImage.GetHandle(), alpha));
	}

	static void AlphaBlendSame(const NImage & imageA, const NImage & imageB, NDouble alpha)
	{
		NCheck(NrgbipAlphaBlendSame(imageA.GetHandle(), imageB.GetHandle(), alpha));
	}

	static NImage AlphaBlend(const NImage & imageA, const NImage & imageB, NDouble r, NDouble g, NDouble b, NDouble a)
	{
		HNImage hResultImage;
		NCheck(NrgbipAlphaBlendColor(imageA.GetHandle(), imageB.GetHandle(), r, g, b, a, &hResultImage));
		return NObject::FromHandle<NImage>(hResultImage);
	}

	static void AlphaBlend(const NImage & imageA, const NImage & imageB, NDouble r, NDouble g, NDouble b, NDouble a, const NImage & dstImage)
	{
		NCheck(NrgbipAlphaBlendColorDst(imageA.GetHandle(), imageB.GetHandle(), dstImage.GetHandle(), r, g, b, a));
	}

	static void AlphaBlendSame(const NImage & imageA, const NImage & imageB, NDouble r, NDouble g, NDouble b, NDouble a)
	{
		NCheck(NrgbipAlphaBlendColorSame(imageA.GetHandle(), imageB.GetHandle(), r, g, b, a));
	}

	static NImage AlphaBlend(const NImage & imageA, const NImage & imageB, const NDouble * pColorMatrix)
	{
		HNImage hResultImage;
		NCheck(NrgbipAlphaBlendColorMatrix(imageA.GetHandle(), imageB.GetHandle(), pColorMatrix, &hResultImage));
		return NObject::FromHandle<NImage>(hResultImage);
	}

	static void AlphaBlend(const NImage & imageA, const NImage & imageB, const NDouble * pColorMatrix, const NImage & dstImage)
	{
		NCheck(NrgbipAlphaBlendColorMatrixDst(imageA.GetHandle(), imageB.GetHandle(), dstImage.GetHandle(), pColorMatrix));
	}

	static void AlphaBlendSame(const NImage & imageA, const NImage & imageB, const NDouble * pColorMatrix)
	{
		NCheck(NrgbipAlphaBlendColorMatrixSame(imageA.GetHandle(), imageB.GetHandle(), pColorMatrix));
	}
};

}}}

#endif // !N_RGB_IMAGE_PROC_HPP_INCLUDED
