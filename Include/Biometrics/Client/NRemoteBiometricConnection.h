#ifndef N_REMOTE_BIOMETRIC_CONNECTION_H_INCLUDED
#define N_REMOTE_BIOMETRIC_CONNECTION_H_INCLUDED

#include <Biometrics/NBiometricConnection.h>
#include <Biometrics/NBiometricTask.h>

#ifdef N_CPP
extern "C"
{
#endif

N_DECLARE_OBJECT_TYPE(NRemoteBiometricConnection, NBiometricConnection)

NResult N_API NRemoteBiometricConnectionGetOperations(HNRemoteBiometricConnection hConnection, NBiometricOperations * pValue);
NResult N_API NRemoteBiometricConnectionSetOperations(HNRemoteBiometricConnection hConnection, NBiometricOperations value);

#ifdef N_CPP
}
#endif

#endif // !N_REMOTE_BIOMETRIC_CONNECTION_H_INCLUDED
