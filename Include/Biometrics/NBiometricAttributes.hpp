#ifndef N_BIOMETRIC_ATTRIBUTES_HPP_INCLUDED
#define N_BIOMETRIC_ATTRIBUTES_HPP_INCLUDED

#include <Biometrics/NBiometricTypes.hpp>
#include <Core/NObject.hpp>
namespace Neurotec { namespace Biometrics
{
#include <Biometrics/NBiometricAttributes.h>
}}

namespace Neurotec { namespace Biometrics
{

class NBiometricAttributes : public NObject
{
	N_DECLARE_OBJECT_CLASS(NBiometricAttributes, NObject)

public:
	NBiometricType GetBiometricType() const
	{
		NBiometricType value;
		NCheck(NBiometricAttributesGetBiometricType(GetHandle(), &value));
		return value;
	}

	NBiometricStatus GetStatus() const
	{
		NBiometricStatus value;
		NCheck(NBiometricAttributesGetStatus(GetHandle(), &value));
		return value;
	}

	void SetStatus(NBiometricStatus value)
	{
		NCheck(NBiometricAttributesSetStatus(GetHandle(), value));
	}

	NByte GetQuality() const
	{
		NByte value;
		NCheck(NBiometricAttributesGetQuality(GetHandle(), &value));
		return value;
	}

	void SetQuality(NByte value)
	{
		NCheck(NBiometricAttributesSetQuality(GetHandle(), value));
	}

	NObject GetChild()
	{
		HNObject hValue;
		NCheck(NBiometricAttributesGetChild(GetHandle(), &hValue));
		return FromHandle<NObject>(hValue);
	}

	NObject GetChildSubject()
	{
		HNObject hValue;
		NCheck(NBiometricAttributesGetChildSubject(GetHandle(), &hValue));
		return FromHandle<NObject>(hValue);
	}
};

}}

#endif // !N_BIOMETRIC_ATTRIBUTES_HPP_INCLUDED
