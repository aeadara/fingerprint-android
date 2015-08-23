#ifndef JPEG_2K_H_INCLUDED
#define JPEG_2K_H_INCLUDED

#include "NImage.h"

#ifdef N_CPP
extern "C"
{
#endif

typedef enum Jpeg2KProfile_
{
	jpeg2kpNone = 0,
	jpeg2kpFingerprint1000Ppi = 1000,
	jpeg2kpFingerprintLossless = 1001,
	jpeg2kpFaceLossy = 2000,
	jpeg2kpFaceLossless = 2001,
} Jpeg2KProfile;

N_DECLARE_TYPE(Jpeg2KProfile)

#define JPEG_2K_DEFAULT_RATIO 10.0f

N_DECLARE_OBJECT_TYPE(Jpeg2KInfo, NImageInfo)

NResult N_API Jpeg2KInfoGetProfile(HJpeg2KInfo hInfo, Jpeg2KProfile * pValue);
NResult N_API Jpeg2KInfoSetProfile(HJpeg2KInfo hInfo, Jpeg2KProfile value);
NResult N_API Jpeg2KInfoGetRatio(HJpeg2KInfo hInfo, NFloat * pValue);
NResult N_API Jpeg2KInfoSetRatio(HJpeg2KInfo hInfo, NFloat value);

#ifdef N_CPP
}
#endif

#endif // !JPEG_2K_H_INCLUDED
