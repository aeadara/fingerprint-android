#ifndef N_LICENSE_MANAGER_HPP_INCLUDED
#define N_LICENSE_MANAGER_HPP_INCLUDED

#include <Core/NObject.hpp>
#include <Licensing/NLicenseProductInfo.hpp>
#include <Licensing/NLicManDongle.hpp>

namespace Neurotec { namespace Licensing
{
#include <Licensing/NLicenseManager.h>
}}

#undef N_LIC_MAN_MAX_SERIAL_LENGTH
#undef N_LIC_MAN_MAX_LICENSE_LENGTH

namespace Neurotec { namespace Licensing
{
const NInt N_LIC_MAN_MAX_SERIAL_LENGTH = 39;
const NInt N_LIC_MAN_MAX_LICENSE_LENGTH = 6400;

class NLicenseManager
{
	N_DECLARE_STATIC_OBJECT_CLASS(NLicenseManager)

public:
	static NString GenerateSerial(NUInt productId, NInt sequenceNumber, NInt * pDistributorId)
	{
		HNString handle;
		NCheck(NLicManGenerateSerialN(productId, sequenceNumber, pDistributorId, &handle));
		return NString(handle, true);
	}

	static NString GenerateLicense(const NStringWrapper & id, NInt * pSequenceNumber, NUInt * pProductId)
	{
		HNString handle;
		NCheck(NLicManGenerateLicenseN(id.GetHandle(), pSequenceNumber, pProductId, &handle));
		return NString(handle, true);
	}

	static void GetLicenseData(const NStringWrapper & id, NInt * pSequenceNumber, NUInt * pProductId, NInt * pDistributorId)
	{
		NCheck(NLicManGetLicenseDataN(id.GetHandle(), pSequenceNumber, pProductId, pDistributorId));
	}

	static NLicManDongle FindFirstDongle()
	{
		HNLicManDongle handle;
		NCheck(NLicManFindFirstDongle(&handle));
		return NObject::FromHandle<NLicManDongle>(handle);
	}

	static NLicManDongle FindNextDongle()
	{
		HNLicManDongle handle;
		NCheck(NLicManFindNextDongle(&handle));
		return NObject::FromHandle<NLicManDongle>(handle);
	}

	static NLicManDongleUpdateTicketInfo GetUpdateTicketInfo(const NStringWrapper & ticketNumber)
	{
		HNLicManDongleUpdateTicketInfo handle;
		NCheck(NLicManGetUpdateTicketInfoN(ticketNumber.GetHandle(), &handle));
		return NObject::FromHandle<NLicManDongleUpdateTicketInfo>(handle);
	}

	static NArrayWrapper<NUInt> GetProductIds()
	{
		NInt count = NLicManGetProductIds(NULL);
		NCheck(count);
		NArrayWrapper<NUInt> result(count);
		NCheck(NLicManGetProductIds(result.GetPtr()));
		return result;
	}

	static bool IsLicenseTypeSupported(NUInt productId, NLicenseType licenseType)
	{
		NBool isSupported;
		NCheck(NLicManIsLicenseTypeSupported(productId, licenseType, &isSupported));
		return isSupported != NFalse;
	}

	static NString GetShortProductName(const NLicenseProductInfo & productInfo)
	{
		HNString handle;
		NCheck(NLicManGetShortProductNameForProductInfoN(productInfo.GetHandle(), &handle));
		return NString(handle, true);
	}

	static NString GetShortProductName(NUInt productId, NLicenseType type)
	{
		HNString handle;
		NCheck(NLicManGetShortProductNameN(productId, type, &handle));
		return NString(handle, true);
	}

	static NString GetLongProductName(const NLicenseProductInfo & productInfo)
	{
		HNString handle;
		NCheck(NLicManGetLongProductNameForProductInfoN(productInfo.GetHandle(), &handle));
		return NString(handle, true);
	}

	static NString GetLongProductName(NUInt productId, NLicenseType type)
	{
		HNString handle;
		NCheck(NLicManGetLongProductNameN(productId, type, &handle));
		return NString(handle, true);
	}
};

}}

#endif // !N_LICENSE_MANAGER_HPP_INCLUDED
