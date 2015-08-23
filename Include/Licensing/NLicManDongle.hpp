#ifndef N_LIC_MAN_DONGLE_HPP_INCLUDED
#define N_LIC_MAN_DONGLE_HPP_INCLUDED

#include <Licensing/NLicenseProductInfo.hpp>
#include <Licensing/NLicManDongleUpdateTicketInfo.hpp>

namespace Neurotec { namespace Licensing
{
#include <Licensing/NLicManDongle.h>
}}

namespace Neurotec { namespace Licensing
{

class NLicManDongle : public NObject
{
	N_DECLARE_OBJECT_CLASS(NLicManDongle, NObject)

public:
	NInt GetDistributorId() const
	{
		NInt value;
		NCheck(NLicManDongleGetDistributorId(GetHandle(), &value));
		return value;
	}

	NUInt GetHardwareId() const
	{
		NUInt value;
		NCheck(NLicManDongleGetHardwareId(GetHandle(), &value));
		return value;
	}

	NArrayWrapper<NLicenseProductInfo> GetLicenses() const
	{
		return GetObjects<HNLicManDongle, NLicenseProductInfo>(NLicManDongleGetLicenses);
	}

	void UpdateOnline(const NLicManDongleUpdateTicketInfo & ticket)
	{
		NCheck(NLicManDongleUpdateOnline(GetHandle(), ticket.GetHandle()));
	}

	void UpdateOnline(const NLicManDongleUpdateTicketInfo & ticket, const IO::NBuffer & buffer)
	{
		NCheck(NLicManDongleUpdateOnlineWithDumpN(GetHandle(), ticket.GetHandle(), buffer.GetHandle()));
	}

	void UpdateOnline(const NLicManDongleUpdateTicketInfo & ticket, void * pBuffer, NSizeType bufferSize)
	{
		NCheck(NLicManDongleUpdateOnlineWithDump(GetHandle(), ticket.GetHandle(), pBuffer, bufferSize));
	}

	void Update(const IO::NBuffer & buffer)
	{
		NCheck(NLicManDongleUpdateN(GetHandle(), buffer.GetHandle()));
	}

	void Update(void * pBuffer, NSizeType bufferSize)
	{
		NCheck(NLicManDongleUpdate(GetHandle(), pBuffer, bufferSize));
	}

	IO::NBuffer Dump()
	{
		HNBuffer handle;
		NCheck(NLicManDongleDumpN(GetHandle(), &handle));
		return FromHandle<IO::NBuffer>(handle);
	}
};

}}

#endif // !N_LIC_MAN_DONGLE_HPP_INCLUDED
