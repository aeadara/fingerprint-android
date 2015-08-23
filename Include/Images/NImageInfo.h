#ifndef N_IMAGE_INFO_H_INCLUDED
#define N_IMAGE_INFO_H_INCLUDED

#include <Core/NExpandableObject.h>

#ifdef N_CPP
extern "C"
{
#endif

N_DECLARE_OBJECT_TYPE(NImageInfo, NExpandableObject)

typedef enum NImageRotateFlipType_
{
	nirftRotateNone = 0,
	nirftRotate90 = 1,
	nirftRotate180 = 2,
	nirftRotate270 = 3,
	nirftFlipNone = 0,
	nirftFlipX = 4,
	nirftFlipY = 8,
	nirftFlipXY = nirftFlipX | nirftFlipY,
	nirftNone = nirftRotateNone | nirftFlipNone,
	nirftUnspecified = -1
} NImageRotateFlipType;

N_DECLARE_TYPE(NImageRotateFlipType)

#ifdef N_CPP
}
#endif

#include <Images/NImageFormat.h>

#ifdef N_CPP
extern "C"
{
#endif

NBool N_API NImageRotateFlipTypeIsValid(NImageRotateFlipType value);
NBool N_API NImageRotateFlipTypeRotateTypeIsValid(NImageRotateFlipType value);
NBool N_API NImageRotateFlipTypeFlipTypeIsValid(NImageRotateFlipType value);
NImageRotateFlipType N_API NImageRotateFlipTypeGetRotateType(NImageRotateFlipType value);
NImageRotateFlipType N_API NImageRotateFlipTypeGetFlipType(NImageRotateFlipType value);
NImageRotateFlipType N_API NImageRotateFlipTypeMinimizeRotation(NImageRotateFlipType value);
NImageRotateFlipType N_API NImageRotateFlipTypeMinimizeFlip(NImageRotateFlipType value);
NResult N_API NImageRotateFlipTypeCreate(NImageRotateFlipType rotate, NImageRotateFlipType flip, NImageRotateFlipType * pValue);

NResult N_API NImageInfoCreate(HNImageInfo * phInfo);

N_DEPRECATED("function is deprecated, use NImageInfoGetFormatEx instead")
NResult N_API NImageInfoGetFormat(HNImageInfo hInfo, HNImageFormat * phValue);
NResult N_API NImageInfoGetFormatEx(HNImageInfo hInfo, HNImageFormat * phValue);
NResult N_API NImageInfoGetWidth(HNImageInfo hInfo, NUInt * pValue);
NResult N_API NImageInfoGetHeight(HNImageInfo hInfo, NUInt * pValue);
NResult N_API NImageInfoGetTransform(HNImageInfo hInfo, NImageRotateFlipType * pValue);
NResult N_API NImageInfoSetTransform(HNImageInfo hInfo, NImageRotateFlipType value);

#ifdef N_CPP
}
#endif

#endif // !N_IMAGE_INFO_H_INCLUDED
