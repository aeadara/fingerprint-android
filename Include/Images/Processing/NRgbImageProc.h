#ifndef N_RGB_IMAGE_PROC_H_INCLUDED
#define N_RGB_IMAGE_PROC_H_INCLUDED

#include <Images/NImage.h>
#include <Images/NRgb.h>

#ifdef N_CPP
extern "C"
{
#endif

N_DECLARE_STATIC_OBJECT_TYPE(Nrgbip)

// Invert

NResult N_API NrgbipInvert(HNImage hImage, HNImage * pHResultImage);
NResult N_API NrgbipInvertDst(HNImage hImage, HNImage hDstImage);
NResult N_API NrgbipInvertSame(HNImage hImage);

// Brightness & Contrast

NResult N_API NrgbipAdjustBrightnessContrast(HNImage hImage, NDouble brightness, NDouble contrast, HNImage * pHResultImage);
NResult N_API NrgbipAdjustBrightnessContrastDst(HNImage hImage, HNImage hDstImage, NDouble brightness, NDouble contrast);
NResult N_API NrgbipAdjustBrightnessContrastSame(HNImage hImage, NDouble brightness, NDouble contrast);

NResult N_API NrgbipAdjustChannelsBrightnessContrast(HNImage hImage,
	NDouble redBrightness, NDouble redContrast, NDouble greenBrightness, NDouble greenContrast, NDouble blueBrightness, NDouble blueContrast, HNImage * pHResultImage);
NResult N_API NrgbipAdjustChannelsBrightnessContrastDst(HNImage hImage, HNImage hDstImage,
	NDouble redBrightness, NDouble redContrast, NDouble greenBrightness, NDouble greenContrast, NDouble blueBrightness, NDouble blueContrast);
NResult N_API NrgbipAdjustChannelsBrightnessContrastSame(HNImage hImage,
	NDouble redBrightness, NDouble redContrast, NDouble greenBrightness, NDouble greenContrast, NDouble blueBrightness, NDouble blueContrast);

// Color Matrix transformation

NResult N_API NrgbipColorMatrixTransform(HNImage hImage, const NDouble * pColorMatrix, HNImage * pHResultImage);
NResult N_API NrgbipColorMatrixTransformDst(HNImage hImage, HNImage hDstImage, const NDouble * pColorMatrix);
NResult N_API NrgbipColorMatrixTransformSame(HNImage hImage, const NDouble * pColorMatrix);

// Tools for mask painting

NResult N_API NrgbipAlphaBlend(HNImage hImageA, HNImage hImageB, NDouble alpha, HNImage *pHResultImage);
NResult N_API NrgbipAlphaBlendDst(HNImage hImageA, HNImage hImageB, HNImage hDstImage, NDouble alpha);
NResult N_API NrgbipAlphaBlendSame(HNImage hImageA, HNImage hImageB, NDouble alpha);

NResult N_API NrgbipAlphaBlendColor(HNImage hImageA, HNImage hImageB, NDouble r, NDouble g, NDouble b, NDouble a, HNImage * pHResultImage);
NResult N_API NrgbipAlphaBlendColorDst(HNImage hImageA, HNImage hImageB, HNImage hDstImage, NDouble r, NDouble g, NDouble b, NDouble a);
NResult N_API NrgbipAlphaBlendColorSame(HNImage hImageA, HNImage hImageB, NDouble r, NDouble g, NDouble b, NDouble a);

NResult N_API NrgbipAlphaBlendColorMatrix(HNImage hImageA, HNImage hImageB, const NDouble * pColorMatrix, HNImage * pHResultImage);
NResult N_API NrgbipAlphaBlendColorMatrixDst(HNImage hImageA, HNImage hImageB, HNImage hDstImage, const NDouble * pColorMatrix);
NResult N_API NrgbipAlphaBlendColorMatrixSame(HNImage hImageA, HNImage hImageB, const NDouble * pColorMatrix);

#ifdef N_CPP
}
#endif

#endif // !N_RGB_IMAGE_PROC_H_INCLUDED
