#ifndef N_LICENSE_INFO_H_INCLUDED
#define N_LICENSE_INFO_H_INCLUDED

#include <Core/NObject.h>
#include <Licensing/NLicenseProductInfo.h>

#ifdef N_CPP
extern "C"
{
#endif

typedef enum NLicenseInfoType_
{
	nlitUnknown = 0,
	nlitSerialNumber = 1,
	nlitHardwareId = 2,
	nlitLicense = 3
} NLicenseInfoType;

typedef enum NLicenseInfoSourceType_
{
	nlistUnknown = 0,
	nlistFile = 1,
	nlistDongle = 2,
	nlistInternet = 3
} NLicenseInfoSourceType;

typedef enum NLicenseInfoStatus_
{
	nlisUnknown = 0,
	nlisValid = 1,
	nlisInvalid = 2
} NLicenseInfoStatus;

N_DECLARE_TYPE(NLicenseInfoType)
N_DECLARE_TYPE(NLicenseInfoSourceType)
N_DECLARE_TYPE(NLicenseInfoStatus)

N_DECLARE_OBJECT_TYPE(NLicenseInfo, NObject)

NResult N_API NLicenseInfoGetType(HNLicenseInfo hLicenseInfo, NLicenseInfoType * pValue);
NResult N_API NLicenseInfoGetSourceType(HNLicenseInfo hLicenseInfo, NLicenseInfoSourceType * pValue);
NResult N_API NLicenseInfoGetStatus(HNLicenseInfo hLicenseInfo, NLicenseInfoStatus * pValue);
NResult N_API NLicenseInfoGetLicenseId(HNLicenseInfo hLicenseInfo, HNString * phValue);
NResult N_API NLicenseInfoGetDistributorId(HNLicenseInfo hLicenseInfo, NInt * pValue);
NResult N_API NLicenseInfoGetSequenceNumber(HNLicenseInfo hLicenseInfo, NInt * pValue);
NResult N_API NLicenseInfoGetLicenses(HNLicenseInfo hLicenseInfo, HNLicenseProductInfo * * parhProductInfo, NInt * pProductInfoCount);

#ifdef N_CPP
}
#endif

#endif // !N_LICENSE_INFO_H_INCLUDED
