#ifndef N_LICENSE_HPP_INCLUDED
#define N_LICENSE_HPP_INCLUDED

#include <Core/NObject.hpp>
#include <Licensing/NLicenseInfo.hpp>

namespace Neurotec { namespace Licensing
{
#include <Licensing/NLicense.h>
}}

namespace Neurotec { namespace Licensing
{

class NLicense
{
	N_DECLARE_STATIC_OBJECT_CLASS(NLicense)

public:
	static bool Obtain(const NStringWrapper & address, const NStringWrapper & port, const NStringWrapper & products)
	{
		NBool available;
		NCheck(NLicenseObtainN(address.GetHandle(), port.GetHandle(), products.GetHandle(), &available));
		return available != 0;
	}

	static bool ObtainComponents(const NStringWrapper & address, const NStringWrapper & port, const NStringWrapper & components)
	{
		NBool available;
		NCheck(NLicenseObtainComponentsN(address.GetHandle(), port.GetHandle(), components.GetHandle(), &available));
		return available != 0;
	}

	static void Release(const NStringWrapper & products)
	{
		NCheck(NLicenseReleaseN(products.GetHandle()));
	}

	static void ReleaseComponents(const NStringWrapper & components)
	{
		NCheck(NLicenseReleaseComponentsN(components.GetHandle()));
	}

	static NLicenseInfo GetLicenseInfoOnline(const NStringWrapper & product)
	{
		HNLicenseInfo handle;
		NCheck(NLicenseGetLicenseInfoOnlineN(product.GetHandle(), &handle));
		return NObject::FromHandle<NLicenseInfo>(handle);
	}

	static NLicenseInfo GetObtainedLicenseInfo(const NStringWrapper & product)
	{
		HNLicenseInfo handle;
		NCheck(NLicenseGetObtainedLicenseInfoN(product.GetHandle(), &handle));
		return NObject::FromHandle<NLicenseInfo>(handle);
	}

	static NLicenseInfo GetObtainedLicenseInfoForComponent(const NStringWrapper & component)
	{
		HNLicenseInfo handle;
		NCheck(NLicenseGetObtainedLicenseInfoForComponentN(component.GetHandle(), &handle));
		return NObject::FromHandle<NLicenseInfo>(handle);
	}

	static bool IsComponentActivated(const NStringWrapper & name)
	{
		NBool value;
		NCheck(NLicenseIsComponentActivatedN(name.GetHandle(), &value));
		return value != 0;
	}

	static NString GenerateId(const NStringWrapper & serialNumber)
	{
		HNString hValue;
		NCheck(NLicenseGenerateIdN(NULL, serialNumber.GetHandle(), &hValue));
		return NString(hValue, true);
	}

	static NString GenerateId(const NStringWrapper & idGenPath, const NStringWrapper & serialNumber)
	{
		HNString hValue;
		NCheck(NLicenseGenerateIdN(idGenPath.GetHandle(), serialNumber.GetHandle(), &hValue));
		return NString(hValue, true);
	}

	static NString GenerateDeactivationId(const NStringWrapper & productName)
	{
		HNString hValue;
		NCheck(NLicenseGenerateDeactivationIdN(NULL, productName.GetHandle(), &hValue));
		return NString(hValue, true);
	}

	static NString GenerateDeactivationId(const NStringWrapper & idGenPath, const NStringWrapper & productName)
	{
		HNString hValue;
		NCheck(NLicenseGenerateDeactivationIdN(idGenPath.GetHandle(), productName.GetHandle(), &hValue));
		return NString(hValue, true);
	}

	static NString GenerateDeactivationIdForLicense(const NStringWrapper & license)
	{
		HNString hValue;
		NCheck(NLicenseGenerateDeactivationIdForLicenseN(NULL, license.GetHandle(), &hValue));
		return NString(hValue, true);
	}

	static NString GenerateDeactivationIdForLicense(const NStringWrapper & idGenPath, const NStringWrapper & license)
	{
		HNString hValue;
		NCheck(NLicenseGenerateDeactivationIdForLicenseN(idGenPath.GetHandle(), license.GetHandle(), &hValue));
		return NString(hValue, true);
	}

	static NString ActivateOnline(const NStringWrapper & id)
	{
		HNString hValue;
		NCheck(NLicenseActivateOnlineN(id.GetHandle(), &hValue));
		return NString(hValue, true);
	}

	static void DeactivateOnline(const NStringWrapper & license)
	{
		NCheck(NLicenseDeactivateOnlineN(NULL, license.GetHandle()));
	}

	static void DeactivateOnline(const NStringWrapper & idGenPath, const NStringWrapper & license)
	{
		NCheck(NLicenseDeactivateOnlineN(idGenPath.GetHandle(), license.GetHandle()));
	}

	static void DeactivateOnlineWithId(const NStringWrapper & license, const NStringWrapper & deactivationId)
	{
		NCheck(NLicenseDeactivateOnlineWithIdN(license.GetHandle(), deactivationId.GetHandle()));
	}
};

}}

#endif // !N_LICENSE_HPP_INCLUDED
