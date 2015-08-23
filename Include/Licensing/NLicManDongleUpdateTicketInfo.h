#ifndef N_LIC_MAN_DONGLE_UPDATE_TICKET_INFO_H_INCLUDED
#define N_LIC_MAN_DONGLE_UPDATE_TICKET_INFO_H_INCLUDED

#include <Core/NDateTime.h>
#include <Licensing/NLicenseProductInfo.h>

#ifdef N_CPP
extern "C"
{
#endif

typedef enum NLicManDongleUpdateTicketStatus_
{
	nlmdutsEnabled = 0,
	nlmdutsDisabled = 1,
	nlmdutsUsed = 2,
	nlmdutsReturned = 3
} NLicManDongleUpdateTicketStatus;

N_DECLARE_TYPE(NLicManDongleUpdateTicketStatus)

N_DECLARE_OBJECT_TYPE(NLicManDongleUpdateTicketInfo, NObject)

NResult N_API NLicManDongleUpdateTicketInfoGetNumber(HNLicManDongleUpdateTicketInfo hUpdateTicketInfo, HNString * phValue);
NResult N_API NLicManDongleUpdateTicketInfoGetIssueDate(HNLicManDongleUpdateTicketInfo hUpdateTicketInfo, NDateTime_ * pValue);
NResult N_API NLicManDongleUpdateTicketInfoGetStatus(HNLicManDongleUpdateTicketInfo hUpdateTicketInfo, NLicManDongleUpdateTicketStatus * pValue);
NResult N_API NLicManDongleUpdateTicketInfoGetLicenses(HNLicManDongleUpdateTicketInfo hUpdateTicketInfo, HNLicenseProductInfo * * parhProductInfo, NInt * pProductInfoCount);

NResult N_API NLicManDongleUpdateTicketInfoGetDongleDistributorId(HNLicManDongleUpdateTicketInfo hUpdateTicketInfo, NInt * pValue);
NResult N_API NLicManDongleUpdateTicketInfoGetDongleHardwareId(HNLicManDongleUpdateTicketInfo hUpdateTicketInfo, NUInt * pValue);

#ifdef N_CPP
}
#endif

#endif // !N_LIC_MAN_DONGLE_UPDATE_TICKET_INFO_H_INCLUDED