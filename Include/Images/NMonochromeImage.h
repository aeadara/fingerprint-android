#ifndef N_MONOCHROME_IMAGE_H_INCLUDED
#define N_MONOCHROME_IMAGE_H_INCLUDED

#include <Images/NImage.h>

#ifdef N_CPP
extern "C"
{
#endif

N_DEPRECATED("function is deprecated, use NImageGetMinValue instead")
NResult N_API NMonochromeImageGetMinValue(HNMonochromeImage hImage, NBool * pValue);
N_DEPRECATED("function is deprecated, use NImageSetMinValue instead")
NResult N_API NMonochromeImageSetMinValue(HNMonochromeImage hImage, NBool value);
N_DEPRECATED("function is deprecated, use NImageGetMaxValue instead")
NResult N_API NMonochromeImageGetMaxValue(HNMonochromeImage hImage, NBool * pValue);
N_DEPRECATED("function is deprecated, use NImageGetMaxValue instead")
NResult N_API NMonochromeImageSetMaxValue(HNMonochromeImage hImage, NBool value);
N_DEPRECATED("function is deprecated, use NImageGetPixel instead")
NResult N_API NMonochromeImageGetPixel(HNMonochromeImage hImage, NUInt x, NUInt y, NBool * pValue);
N_DEPRECATED("function is deprecated, use NImageSetPixel instead")
NResult N_API NMonochromeImageSetPixel(HNMonochromeImage hImage, NUInt x, NUInt y, NBool value);

#ifdef N_CPP
}
#endif

#endif // !N_MONOCHROME_IMAGE_H_INCLUDED
