#ifndef N_BIOMETRIC_HPP_INCLUDED
#define N_BIOMETRIC_HPP_INCLUDED

#include <Core/NExpandableObject.hpp>
#include <Biometrics/NBiometricTypes.hpp>
#include <Biometrics/NBiometricAttributes.hpp>
namespace Neurotec { namespace Biometrics
{
#include <Biometrics/NBiometric.h>
}}

N_DEFINE_ENUM_TYPE_TRAITS(Neurotec::Biometrics, NBiometricCaptureOptions)

namespace Neurotec { namespace Biometrics
{

class NSubject;

class NBiometric : public NObject
{
	N_DECLARE_OBJECT_CLASS(NBiometric, NObject)

public:
	static bool IsBiometricCaptureOptionsValid(NBiometricCaptureOptions value)
	{
		return NBiometricCaptureOptionsIsValid(value) != 0;
	}

	NSubject GetOwner() const;

	NBiometricType GetBiometricType() const
	{
		NBiometricType value;
		NCheck(NBiometricGetBiometricType(GetHandle(), &value));
		return value;
	}

	NBiometricCaptureOptions GetCaptureOptions() const
	{
		NBiometricCaptureOptions value;
		NCheck(NBiometricGetCaptureOptions(GetHandle(), &value));
		return value;
	}

	void SetCaptureOptions(NBiometricCaptureOptions value)
	{
		NCheck(NBiometricSetCaptureOptions(GetHandle(), value));
	}

	NBiometricStatus GetStatus() const
	{
		NBiometricStatus value;
		NCheck(NBiometricGetStatus(GetHandle(), &value));
		return value;
	}

	void SetStatus(NBiometricStatus value)
	{
		NCheck(NBiometricSetStatus(GetHandle(), value));
	}

	bool GetHasMoreSamples() const
	{
		NBool value;
		NCheck(NBiometricGetHasMoreSamples(GetHandle(), &value));
		return value != 0;
	}

	void SetHasMoreSamples(bool value)
	{
		NCheck(NBiometricSetHasMoreSamples(GetHandle(), value ? NTrue : NFalse));
	}

	NInt GetSessionId() const
	{
		NInt value;
		NCheck(NBiometricGetSessionId(GetHandle(), &value));
		return value;
	}

	void SetSessionId(NInt value)
	{
		NCheck(NBiometricSetSessionId(GetHandle(), value));
	}

	NBiometricAttributes GetParentObject() const
	{
		return GetObject<HandleType, NBiometricAttributes>(NBiometricGetParentObject, true);
	}

	NString GetFileName() const
	{
		return GetString(NBiometricGetFileName);
	}

	void SetFileName(const NStringWrapper & value)
	{
		SetString(NBiometricSetFileNameN, value);
	}

	NError GetError() const
	{
		HNError hError;
		NCheck(NBiometricGetError(GetHandle(), &hError));
		return FromHandle<NError>(hError);
	}
};

}}

#include <Biometrics/NSubject.hpp>

namespace Neurotec { namespace Biometrics
{

inline NSubject NBiometric::GetOwner() const
{
	return NObject::GetOwner<NSubject>();
}

}}

#endif // !N_BIOMETRIC_HPP_INCLUDED
