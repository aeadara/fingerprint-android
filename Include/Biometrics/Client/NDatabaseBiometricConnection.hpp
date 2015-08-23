#ifndef N_DATABASE_BIOMETRIC_CONNECTION_HPP_INCLUDED
#define N_DATABASE_BIOMETRIC_CONNECTION_HPP_INCLUDED

#include <Biometrics/NBiometricConnection.hpp>
namespace Neurotec { namespace Biometrics { namespace Client
{
#include <Biometrics/Client/NDatabaseBiometricConnection.h>
}}}

namespace Neurotec { namespace Biometrics { namespace Client
{

class NDatabaseBiometricConnection : public NBiometricConnection
{
	N_DECLARE_OBJECT_CLASS(NDatabaseBiometricConnection, NBiometricConnection)

public:
};

}}}

#endif // !N_DATABASE_BIOMETRIC_CONNECTION_HPP_INCLUDED
