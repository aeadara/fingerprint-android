#ifndef N_GRAYSCALE_IMAGE_PROC_HPP_INCLUDED
#define N_GRAYSCALE_IMAGE_PROC_HPP_INCLUDED

#include <Images/NImage.hpp>
#include <Geometry/NGeometry.hpp>
namespace Neurotec { namespace Images { namespace Processing
{
using ::Neurotec::Geometry::NInterpolationMode;
#include <Images/Processing/NGrayscaleImageProc.h>
}}}

namespace Neurotec { namespace Images { namespace Processing
{

class Ngip
{
	N_DECLARE_STATIC_OBJECT_CLASS(Ngip)

public:
	static NImage Invert(const NImage & image)
	{
		HNImage hResultImage;
		NCheck(NgipInvert(image.GetHandle(), &hResultImage));
		return NObject::FromHandle<NImage>(hResultImage);
	}

	static void Invert(const NImage & image, const NImage & dstImage)
	{
		NCheck(NgipInvertDst(image.GetHandle(), dstImage.GetHandle()));
	}

	static void InvertSame(const NImage & image)
	{
		NCheck(NgipInvertSame(image.GetHandle()));
	}

	static NImage Scale(const NImage & srcImage, NUInt srcLeft, NUInt srcTop, NUInt srcWidth, NUInt srcHeight,
		NUInt resultWidth, NUInt resultHeight, NInterpolationMode interpolationMode)
	{
		HNImage hResultImage;
		NCheck(NgipScale(srcImage.GetHandle(), srcLeft, srcTop, srcWidth, srcHeight, resultWidth, resultHeight, interpolationMode, &hResultImage));
		return NObject::FromHandle<NImage>(hResultImage);
	}

	static NImage Scale(const NImage & srcImage, NUInt resultWidth, NUInt resultHeight, NInterpolationMode interpolationMode)
	{
		HNImage hResultImage;
		NCheck(NgipScale(srcImage.GetHandle(), 0, 0, srcImage.GetWidth(), srcImage.GetHeight(), resultWidth, resultHeight, interpolationMode, &hResultImage));
		return NObject::FromHandle<NImage>(hResultImage);
	}

	static void Scale(const NImage & srcImage, NUInt srcLeft, NUInt srcTop, NUInt srcWidth, NUInt srcHeight,
		const NImage & dstImage, NUInt dstLeft, NUInt dstTop, NUInt dstWidth, NUInt dstHeight, NInterpolationMode interpolationMode)
	{
		NCheck(NgipScaleDst(srcImage.GetHandle(), srcLeft, srcTop, srcWidth, srcHeight, dstImage.GetHandle(), dstLeft, dstTop, dstWidth, dstHeight, interpolationMode));
	}

	static void Scale(const NImage & srcImage, const NImage & dstImage, NUInt dstLeft, NUInt dstTop, NUInt dstWidth, NUInt dstHeight, NInterpolationMode interpolationMode)
	{
		NCheck(NgipScaleDst(srcImage.GetHandle(), 0, 0, dstImage.GetWidth(), srcImage.GetHeight(), srcImage.GetHandle(), dstLeft, dstTop, dstWidth, dstHeight, interpolationMode));
	}

	static NImage AdjustBrightnessContrast(const NImage & image, NDouble brightness, NDouble contrast)
	{
		HNImage hResultImage;
		NCheck(NgipAdjustBrightnessContrast(image.GetHandle(), brightness, contrast, &hResultImage));
		return NObject::FromHandle<NImage>(hResultImage);
	}

	static void AdjustBrightnessContrast(const NImage & image, const NImage & dstImage, NDouble brightness, NDouble contrast)
	{
		NCheck(NgipAdjustBrightnessContrastDst(image.GetHandle(), dstImage.GetHandle(), brightness, contrast));
	}

	static void AdjustBrightnessContrastSame(const NImage & image, NDouble brightness, NDouble contrast)
	{
		NCheck(NgipAdjustBrightnessContrastSame(image.GetHandle(), brightness, contrast));
	}

	static NImage IFFT(const NImage & srcReal, const NImage & srcImaginary)
	{
		HNImage hDst;
		NCheck(NgipIFFT(srcReal.GetHandle(), srcImaginary.GetHandle(), &hDst));
		return NObject::FromHandle<NImage>(hDst);
	}

	static void FFT(const NImage & src, NImage * pDstReal, NImage * pDstImaginary)
	{
		if (!pDstReal) NThrowArgumentNullException(N_T("pDstReal"));
		if (!pDstImaginary) NThrowArgumentNullException(N_T("pDstImaginary"));
		HNImage hDstReal;
		HNImage hDstImaginary;
		NCheck(NgipFFT(src.GetHandle(), &hDstReal, &hDstImaginary));
		*pDstReal = NObject::FromHandle<NImage>(hDstReal);
		*pDstImaginary = NObject::FromHandle<NImage>(hDstImaginary);
	}

	static void ApplyMaskToSpectrum(const NImage & srcReal, const NImage & srcImaginary, const NImage & mask)
	{
		NCheck(NgipApplyMaskToSpectrum(srcReal.GetHandle(), srcImaginary.GetHandle(), mask.GetHandle()));
	}

	static NImage CreateMagnitudeFromSpectrum(const NImage & srcReal, const NImage & srcImaginary)
	{
		HNImage hMagnitude;
		NCheck(NgipCreateMagnitudeFromSpectrum(srcReal.GetHandle(), srcImaginary.GetHandle(), &hMagnitude));
		return NObject::FromHandle<NImage>(hMagnitude);
	}

	static void FFTGetOptimalSize(const NImage & src, NUInt * pWidth, NUInt * pHeight)
	{
		NCheck(NgipFFTGetOptimalSize(src.GetHandle(), pWidth, pHeight));
	}
};

}}}

#endif // !N_GRAYSCALE_IMAGE_PROC_HPP_INCLUDED
