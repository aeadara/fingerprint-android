#ifndef N_LICENSE_INFO_HPP_INCLUDED
#define N_LICENSE_INFO_HPP_INCLUDED

#include <Core/NObject.hpp>
#include <Licensing/NLicenseProductInfo.hpp>

namespace Neurotec { namespace Licensing
{
#include <Licensing/NLicenseInfo.h>
}}

N_DEFINE_ENUM_TYPE_TRAITS(Neurotec::Licensing, NLicenseInfoType)
N_DEFINE_ENUM_TYPE_TRAITS(Neurotec::Licensing, NLicenseInfoSourceType)
N_DEFINE_ENUM_TYPE_TRAITS(Neurotec::Licensing, NLicenseInfoStatus)

namespace Neurotec { namespace Licensing
{

class NLicenseInfo : public NObject
{
	N_DECLARE_OBJECT_CLASS(NLicenseInfo, NObject)

public:
	NLicenseInfoType GetType() const
	{
		NLicenseInfoType value;
		NCheck(NLicenseInfoGetType(GetHandle(), &value));
		return value;
	}

	NLicenseInfoSourceType GetSourceType() const
	{
		NLicenseInfoSourceType value;
		NCheck(NLicenseInfoGetSourceType(GetHandle(), &value));
		return value;
	}

	NLicenseInfoStatus GetStatus() const
	{
		NLicenseInfoStatus value;
		NCheck(NLicenseInfoGetStatus(GetHandle(), &value));
		return value;
	}

	NString GetLicenseId() const
	{
		HNString handle;
		NCheck(NLicenseInfoGetLicenseId(GetHandle(), &handle));
		return NString(handle, true);
	}

	NInt GetDistributorId() const
	{
		NInt value;
		NCheck(NLicenseInfoGetDistributorId(GetHandle(), &value));
		return value;
	}

	NInt GetSequenceNumber() const
	{
		NInt value;
		NCheck(NLicenseInfoGetSequenceNumber(GetHandle(), &value));
		return value;
	}

	NArrayWrapper<NLicenseProductInfo> GetLicenses()
	{
		return GetObjects<HNLicenseInfo, NLicenseProductInfo>(NLicenseInfoGetLicenses);
	}
};

}}

#endif // !N_LICENSE_INFO_HPP_INCLUDED
