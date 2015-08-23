#ifndef N_BIOMETRIC_CONNECTION_H_INCLUDED
#define N_BIOMETRIC_CONNECTION_H_INCLUDED

#include <Core/NExpandableObject.h>

#ifdef N_CPP
extern "C"
{
#endif

N_DECLARE_OBJECT_TYPE(NBiometricConnection, NExpandableObject)

NResult N_API NBiometricConnectionGetName(HNBiometricConnection hConnection, HNString * phValue);
NResult N_API NBiometricConnectionSetNameN(HNBiometricConnection hConnection, HNString hValue);
#ifndef N_NO_ANSI_FUNC
NResult N_API NBiometricConnectionSetNameA(HNBiometricConnection hConnection, const NAChar * szValue);
#endif
#ifndef N_NO_UNICODE
NResult N_API NBiometricConnectionSetNameW(HNBiometricConnection hConnection, const NWChar * szValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NBiometricConnectionSetName(HNBiometricConnection hConnection, const NChar * szValue);
#endif
#define NBiometricConnectionSetName N_FUNC_AW(NBiometricConnectionSetName)

#ifdef N_CPP
}
#endif

#endif // !N_BIOMETRIC_CONNECTION_H_INCLUDED
