#ifndef N_GRAYSCALE_IMAGE_H_INCLUDED
#define N_GRAYSCALE_IMAGE_H_INCLUDED

#include <Images/NImage.h>

#ifdef N_CPP
extern "C"
{
#endif

N_DEPRECATED("function is deprecated, use NImageGetMinValue instead")
NResult N_API NGrayscaleImageGetMinValue(HNGrayscaleImage hImage, NByte * pValue);
N_DEPRECATED("function is deprecated, use NImageSetMinValue instead")
NResult N_API NGrayscaleImageSetMinValue(HNGrayscaleImage hImage, NByte value);
N_DEPRECATED("function is deprecated, use NImageGetMaxValue instead")
NResult N_API NGrayscaleImageGetMaxValue(HNGrayscaleImage hImage, NByte * pValue);
N_DEPRECATED("function is deprecated, use NImageGetMaxValue instead")
NResult N_API NGrayscaleImageSetMaxValue(HNGrayscaleImage hImage, NByte value);
N_DEPRECATED("function is deprecated, use NImageGetPixel instead")
NResult N_API NGrayscaleImageGetPixel(HNGrayscaleImage hImage, NUInt x, NUInt y, NByte * pValue);
N_DEPRECATED("function is deprecated, use NImageSetPixel instead")
NResult N_API NGrayscaleImageSetPixel(HNGrayscaleImage hImage, NUInt x, NUInt y, NByte value);

#ifdef N_CPP
}
#endif

#endif // !N_GRAYSCALE_IMAGE_H_INCLUDED
