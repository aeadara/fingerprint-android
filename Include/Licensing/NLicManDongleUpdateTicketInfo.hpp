#ifndef N_LIC_MAN_DONGLE_UPDATE_TICKET_INFO_HPP_INCLUDED
#define N_LIC_MAN_DONGLE_UPDATE_TICKET_INFO_HPP_INCLUDED

#include <Core/NDateTime.hpp>
#include <Licensing/NLicenseProductInfo.hpp>

namespace Neurotec { namespace Licensing
{
#include <Licensing/NLicManDongleUpdateTicketInfo.h>
}}

N_DEFINE_ENUM_TYPE_TRAITS(Neurotec::Licensing, NLicManDongleUpdateTicketStatus)

namespace Neurotec { namespace Licensing
{

class NLicManDongleUpdateTicketInfo : public NObject
{
	N_DECLARE_OBJECT_CLASS(NLicManDongleUpdateTicketInfo, NObject)

public:
	NString GetNumber() const
	{
		HNString handle;
		NCheck(NLicManDongleUpdateTicketInfoGetNumber(GetHandle(), &handle));
		return NString(handle, true);
	}

	NDateTime GetIssueDate() const
	{
		NDateTime_ value;
		NCheck(NLicManDongleUpdateTicketInfoGetIssueDate(GetHandle(), &value));
		return NDateTime(value);
	}

	NLicManDongleUpdateTicketStatus GetStatus() const
	{
		NLicManDongleUpdateTicketStatus value;
		NCheck(NLicManDongleUpdateTicketInfoGetStatus(GetHandle(), &value));
		return value;
	}

	NArrayWrapper<NLicenseProductInfo> GetLicenses()
	{
		return GetObjects<HNLicManDongleUpdateTicketInfo, NLicenseProductInfo>(NLicManDongleUpdateTicketInfoGetLicenses);
	}

	NInt GetDongleDistributorId()
	{
		NInt value;
		NCheck(NLicManDongleUpdateTicketInfoGetDongleDistributorId(GetHandle(), &value));
		return value;
	}

	NUInt GetDongleHardwareId()
	{
		NUInt value;
		NCheck(NLicManDongleUpdateTicketInfoGetDongleHardwareId(GetHandle(), &value));
		return value;
	}
};

}}

#endif // !N_LIC_MAN_DONGLE_UPDATE_TICKET_INFO_HPP_INCLUDED
