#ifndef N_BIOMETRIC_CONNECTION_HPP_INCLUDED
#define N_BIOMETRIC_CONNECTION_HPP_INCLUDED

#include <Core/NExpandableObject.hpp>
namespace Neurotec { namespace Biometrics
{
#include <Biometrics/NBiometricConnection.h>
}}

namespace Neurotec { namespace Biometrics
{

class NBiometricEngine;

class NBiometricConnection : public NExpandableObject
{
	N_DECLARE_OBJECT_CLASS(NBiometricConnection, NExpandableObject)

public:
	NBiometricEngine GetOwner() const;

	NString GetName() const
	{
		return GetString(NBiometricConnectionGetName);
	}

	void SetName(const NStringWrapper & value)
	{
		SetString(NBiometricConnectionSetNameN, value);
	}
};

}}

#include <Biometrics/NBiometricEngine.hpp>

namespace Neurotec { namespace Biometrics
{

inline NBiometricEngine NBiometricConnection::GetOwner() const
{
	return NObject::GetOwner<NBiometricEngine>();
}

}}

#endif // !N_BIOMETRIC_CONNECTION_HPP_INCLUDED
