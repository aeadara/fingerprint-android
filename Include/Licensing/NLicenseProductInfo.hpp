#ifndef N_LICENSE_PRODUCT_INFO_HPP_INCLUDED
#define N_LICENSE_PRODUCT_INFO_HPP_INCLUDED

#include <Core/NObject.hpp>

namespace Neurotec { namespace Licensing
{
#include <Licensing/NLicenseProductInfo.h>
}}

N_DEFINE_ENUM_TYPE_TRAITS(Neurotec::Licensing, NLicenseType)

namespace Neurotec { namespace Licensing
{

class NLicenseProductInfo : public NObject
{
	N_DECLARE_OBJECT_CLASS(NLicenseProductInfo, NObject)

public:
	NUInt GetId() const
	{
		NUInt value;
		NCheck(NLicenseProductInfoGetId(GetHandle(), &value));
		return value;
	}

	NLicenseType GetLicenseType() const
	{
		NLicenseType value;
		NCheck(NLicenseProductInfoGetLicenseType(GetHandle(), &value));
		return value;
	}

	NOSFamily GetOSFamily() const
	{
		NOSFamily value;
		NCheck(NLicenseProductInfoGetOSFamily(GetHandle(), &value));
		return value;
	}

	NInt GetLicenseCount() const
	{
		NInt value;
		NCheck(NLicenseProductInfoGetLicenseCount(GetHandle(), &value));
		return value;
	}
};

}}

#endif // !N_LICENSE_PRODUCT_INFO_HPP_INCLUDED
