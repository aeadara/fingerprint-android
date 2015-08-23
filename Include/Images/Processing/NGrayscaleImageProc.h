#ifndef N_GRAYSCALE_IMAGE_PROC_H_INCLUDED
#define N_GRAYSCALE_IMAGE_PROC_H_INCLUDED

#include <Images/NImage.h>
#include <Geometry/NGeometry.h>

#ifdef N_CPP
extern "C"
{
#endif

N_DECLARE_STATIC_OBJECT_TYPE(Ngip)

// Invert

NResult N_API NgipInvert(HNImage hImage, HNImage * pHResultImage);
NResult N_API NgipInvertDst(HNImage hImage, HNImage hDstImage);
NResult N_API NgipInvertSame(HNImage hImage);

// Scale

NResult N_API NgipScale(HNImage hSrcImage, NUInt srcLeft, NUInt srcTop, NUInt srcWidth, NUInt srcHeight,
	NUInt resultWidth, NUInt resultHeight, NInterpolationMode interpolationMode, HNImage * pHResultImage);
NResult N_API NgipScaleDst(HNImage hSrcImage, NUInt srcLeft, NUInt srcTop, NUInt srcWidth, NUInt srcHeight,
	HNImage hDstImage, NUInt dstLeft, NUInt dstTop, NUInt dstWidth, NUInt dstHeight, NInterpolationMode interpolationMode);

// Brightness & Contrast

NResult N_API NgipAdjustBrightnessContrast(HNImage hImage, NDouble brightness, NDouble contrast, HNImage * pHResultImage);
NResult N_API NgipAdjustBrightnessContrastDst(HNImage hImage, HNImage hDstImage, NDouble brightness, NDouble contrast);
NResult N_API NgipAdjustBrightnessContrastSame(HNImage hImage, NDouble brightness, NDouble contrast);

// FFT

NResult N_API NgipIFFT(HNImage hSrcReal, HNImage hSrcImaginary, HNImage * pHDst);
NResult N_API NgipFFT(HNImage hSrc, HNImage * pHDstReal, HNImage * pHDstImaginary);
NResult N_API NgipApplyMaskToSpectrum(HNImage hSrcReal, HNImage hSrcImaginary, HNImage hMask);
NResult N_API NgipCreateMagnitudeFromSpectrum(HNImage hSrcReal, HNImage hSrcImaginary, HNImage * pHMagnitude);
NResult N_API NgipFFTGetOptimalSize(HNImage hSrc, NUInt * pWidth, NUInt * pHeight);

#ifdef N_CPP
}
#endif

#endif // !N_GRAYSCALE_IMAGE_PROC_H_INCLUDED
