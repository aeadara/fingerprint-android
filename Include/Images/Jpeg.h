#ifndef JPEG_H_INCLUDED
#define JPEG_H_INCLUDED

#include "NImage.h"

#ifdef N_CPP
extern "C"
{
#endif

#define JPEG_DEFAULT_QUALITY 75

N_DECLARE_OBJECT_TYPE(JpegInfo, NImageInfo)

NResult N_API JpegInfoGetQuality(HJpegInfo hInfo, NInt * pValue);
NResult N_API JpegInfoSetQuality(HJpegInfo hInfo, NInt value);
NResult N_API JpegInfoIsLossless(HJpegInfo hInfo, NBool * pValue);
NResult N_API JpegInfoSetLossless(HJpegInfo hInfo, NBool value);

#ifdef N_CPP
}
#endif

#endif // !JPEG_H_INCLUDED
