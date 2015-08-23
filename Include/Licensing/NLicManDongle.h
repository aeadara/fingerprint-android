#ifndef N_LIC_MAN_DONGLE_H_INCLUDED
#define N_LIC_MAN_DONGLE_H_INCLUDED

#include <Licensing/NLicenseProductInfo.h>
#include <Licensing/NLicManDongleUpdateTicketInfo.h>

#ifdef N_CPP
extern "C"
{
#endif

N_DECLARE_OBJECT_TYPE(NLicManDongle, NObject)

NResult N_API NLicManDongleGetDistributorId(HNLicManDongle hDongle, NInt * pDistributorId);
NResult N_API NLicManDongleGetHardwareId(HNLicManDongle hDongle, NUInt * pHardwareId);
NResult N_API NLicManDongleGetLicenses(HNLicManDongle hDongle, HNLicenseProductInfo * * parhProductInfo, NInt * pProductInfoCount);

NResult N_API NLicManDongleUpdateOnline(HNLicManDongle hDongle, HNLicManDongleUpdateTicketInfo hTicket);
NResult N_API NLicManDongleUpdateOnlineWithDump(HNLicManDongle hDongle, HNLicManDongleUpdateTicketInfo hTicket, void * pBuffer, NSizeType bufferSize);
NResult N_API NLicManDongleUpdateOnlineWithDumpN(HNLicManDongle hDongle, HNLicManDongleUpdateTicketInfo hTicket, HNBuffer hBuffer);
NResult N_API NLicManDongleUpdate(HNLicManDongle hDongle, void * pBuffer, NSizeType bufferSize);
NResult N_API NLicManDongleUpdateN(HNLicManDongle hDongle, HNBuffer hBuffer);
NResult N_API NLicManDongleDumpN(HNLicManDongle hDongle, HNBuffer * phBuffer);

#ifdef N_CPP
}
#endif

#endif // !N_LIC_MAN_DONGLE_H_INCLUDED
