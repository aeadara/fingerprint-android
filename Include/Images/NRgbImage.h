#ifndef N_RGB_IMAGE_H_INCLUDED
#define N_RGB_IMAGE_H_INCLUDED

#include <Images/NImage.h>
#include <Images/NRgb.h>

#ifdef N_CPP
extern "C"
{
#endif

N_DEPRECATED("function is deprecated, use NImageGetMinValue instead")
NResult N_API NRgbImageGetMinValue(HNRgbImage hImage, struct NRgb_ * pValue);
N_DEPRECATED("function is deprecated, use NImageSetMinValue instead")
NResult N_API NRgbImageSetMinValue(HNRgbImage hImage, const struct NRgb_ * pValue);
N_DEPRECATED("function is deprecated, use NImageGetMaxValue instead")
NResult N_API NRgbImageGetMaxValue(HNRgbImage hImage, struct NRgb_ * pValue);
N_DEPRECATED("function is deprecated, use NImageGetMaxValue instead")
NResult N_API NRgbImageSetMaxValue(HNRgbImage hImage, const struct NRgb_ * pValue);
N_DEPRECATED("function is deprecated, use NImageGetPixel instead")
NResult N_API NRgbImageGetPixel(HNRgbImage hImage, NUInt x, NUInt y, struct NRgb_ * pValue);
N_DEPRECATED("function is deprecated, use NImageSetPixel instead")
NResult N_API NRgbImageSetPixel(HNRgbImage hImage, NUInt x, NUInt y, const struct NRgb_ * pValue);

#ifdef N_CPP
}
#endif

#endif // !N_RGB_IMAGE_H_INCLUDED
