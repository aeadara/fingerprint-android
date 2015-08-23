#ifndef N_LICENSING_SERVICE_HPP_INCLUDED
#define N_LICENSING_SERVICE_HPP_INCLUDED

#include <Core/NObject.hpp>
namespace Neurotec { namespace Licensing
{
#include <Licensing/NLicensingService.h>
}}

namespace Neurotec { namespace Licensing
{

class NLicensingService
{
	N_DECLARE_STATIC_OBJECT_CLASS(NLicensingService)

public:
	static NType NLicensingServiceStatusNativeTypeOf()
	{
		return NObject::GetObject<NType>(N_TYPE_OF(NLicensingServiceStatus), true);
	}

	static void Install(const NStringWrapper & binPath, const NStringWrapper & conf)
	{
		NCheck(NLicensingServiceInstallN(binPath.GetHandle(), conf.GetHandle()));
	}

	static void Uninstall(void)
	{
		NCheck(NLicensingServiceUninstall());
	}

	static void Start(void)
	{
		NCheck(NLicensingServiceStart());
	}

	static void Stop(void)
	{
		NCheck(NLicensingServiceStop());
	}

	static NLicensingServiceStatus GetStatus(void)
	{
		NLicensingServiceStatus s;
		NCheck(NLicensingServiceGetStatus(&s));
		return s;
	}

	static NString GetBinPath(void)
	{
		HNString hValue;
		NCheck(NLicensingServiceGetBinPath(&hValue));
		return NString(hValue, true);
	}

	static NString GetConfPath(void)
	{
		HNString hValue;
		NCheck(NLicensingServiceGetConfPath(&hValue));
		return NString(hValue, true);
	}

	static bool IsTrial(void)
	{
		NBool isTrial;
		NCheck(NLicensingServiceIsTrial(&isTrial));
		return isTrial != 0;
	}
};

}}

#endif // !N_LICENSING_SERVICE_HPP_INCLUDED
