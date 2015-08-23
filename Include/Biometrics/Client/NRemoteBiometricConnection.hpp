#ifndef N_REMOTE_BIOMETRIC_CONNECTION_HPP_INCLUDED
#define N_REMOTE_BIOMETRIC_CONNECTION_HPP_INCLUDED

#include <Biometrics/NBiometricConnection.hpp>
#include <Biometrics/NBiometricTask.hpp>
namespace Neurotec { namespace Biometrics { namespace Client
{
#include <Biometrics/Client/NRemoteBiometricConnection.h>
}}}

namespace Neurotec { namespace Biometrics { namespace Client
{

class NRemoteBiometricConnection : public NBiometricConnection
{
	N_DECLARE_OBJECT_CLASS(NRemoteBiometricConnection, NBiometricConnection)

public:
	NBiometricOperations GetOperations() const
	{
		NBiometricOperations value;
		NCheck(NRemoteBiometricConnectionGetOperations(GetHandle(), &value));
		return value;
	}

	void SetOperations(NBiometricOperations value)
	{
		NCheck(NRemoteBiometricConnectionSetOperations(GetHandle(), value));
	}
};

}}}

#endif // !N_REMOTE_BIOMETRIC_CONNECTION_HPP_INCLUDED
