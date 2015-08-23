#ifndef N_LICENSE_MANAGER_H_INCLUDED
#define N_LICENSE_MANAGER_H_INCLUDED

#include <Core/NObject.h>
#include <Licensing/NLicenseProductInfo.h>
#include <Licensing/NLicManDongle.h>

#ifdef N_CPP
extern "C"
{
#endif

N_DECLARE_STATIC_OBJECT_TYPE(NLicenseManager)

#define N_LIC_MAN_MAX_SERIAL_LENGTH    39
#define N_LIC_MAN_MAX_LICENSE_LENGTH 6400

NResult N_API NLicManGenerateSerialN(NUInt productId, NInt sequenceNumber, NInt * pDistributorId, HNString * phValue);

NResult N_API NLicManGenerateLicenseN(HNString hId, NInt * pSequenceNumber, NUInt * pProductId, HNString * phValue);

NResult N_API NLicManGetLicenseDataN(HNString hId, NInt * pSequenceNumber, NUInt * pProductId, NInt * pDistributorId);
#ifndef N_NO_ANSI_FUNC
NResult N_API NLicManGetLicenseDataA(const NAChar * szId, NInt * pSequenceNumber, NUInt * pProductId, NInt * pDistributorId);
#endif
#ifndef N_NO_UNICODE
NResult N_API NLicManGetLicenseDataW(const NWChar * szId, NInt * pSequenceNumber, NUInt * pProductId, NInt * pDistributorId);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NLicManGetLicenseData(const NChar * szId, NInt * pSequenceNumber, NUInt * pProductId, NInt * pDistributorId);
#endif
#define NLicManGetLicenseData N_FUNC_AW(NLicManGetLicenseData)

NResult N_API NLicManFindFirstDongle(HNLicManDongle * phDongle);
NResult N_API NLicManFindNextDongle(HNLicManDongle * phDongle);

NResult N_API NLicManGetUpdateTicketInfoN(HNString hTicketNumber, HNLicManDongleUpdateTicketInfo * phTicket);
#ifndef N_NO_ANSI_FUNC
NResult N_API NLicManGetUpdateTicketInfoA(const NAChar * szTicketNumber, HNLicManDongleUpdateTicketInfo * phTicket);
#endif
#ifndef N_NO_UNICODE
NResult N_API NLicManGetUpdateTicketInfoW(const NWChar * szTicketNumber, HNLicManDongleUpdateTicketInfo * phTicket);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NLicManGetUpdateTicketInfo(const NChar * szTicketNumber, HNLicManDongleUpdateTicketInfo * phTicket);
#endif
#define NLicManGetUpdateTicketInfo N_FUNC_AW(NLicManGetUpdateTicketInfo)

NResult N_API NLicManGetProductIds(NUInt * arProductsIds);

NResult N_API NLicManIsLicenseTypeSupported(NUInt productId, NLicenseType type, NBool * pValue);

NResult N_API NLicManGetShortProductNameForProductInfoN(HNLicenseProductInfo hProductInfo, HNString * phValue);
NResult N_API NLicManGetShortProductNameN(NUInt productId, NLicenseType type, HNString * phValue);
NResult N_API NLicManGetLongProductNameForProductInfoN(HNLicenseProductInfo hProductInfo, HNString * phValue);
NResult N_API NLicManGetLongProductNameN(NUInt productId, NLicenseType type, HNString * phValue);

#ifdef N_CPP
}
#endif

#endif // !N_LICENSE_MANAGER_H_INCLUDED
