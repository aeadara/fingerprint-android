#ifndef N_LICENSE_PRODUCT_INFO_H_INCLUDED
#define N_LICENSE_PRODUCT_INFO_H_INCLUDED

#include <Core/NObject.h>

#ifdef N_CPP
extern "C"
{
#endif

typedef enum NLicenseType_
{
	nltSingleComputer = 0,
	nltConcurrent = 1,
	nltSigned = 2,
} NLicenseType;

N_DECLARE_TYPE(NLicenseType)

N_DECLARE_OBJECT_TYPE(NLicenseProductInfo, NObject)

NResult N_API NLicenseProductInfoGetId(HNLicenseProductInfo hProductInfo, NUInt * pValue);
NResult N_API NLicenseProductInfoGetLicenseType(HNLicenseProductInfo hProductInfo, NLicenseType * pValue);
NResult N_API NLicenseProductInfoGetOSFamily(HNLicenseProductInfo hProductInfo, NOSFamily * pValue);
NResult N_API NLicenseProductInfoGetLicenseCount(HNLicenseProductInfo hProductInfo, NInt * pValue);

#ifdef N_CPP
}
#endif

#endif // !N_LICENSE_PRODUCT_INFO_H_INCLUDED
