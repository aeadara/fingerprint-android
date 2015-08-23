#ifndef N_SQLITE_BIOMETRIC_CONNECTION_H_INCLUDED
#define N_SQLITE_BIOMETRIC_CONNECTION_H_INCLUDED

#include <Biometrics/Client/NDatabaseBiometricConnection.h>

#ifdef N_CPP
extern "C"
{
#endif

N_DECLARE_OBJECT_TYPE(NSQLiteBiometricConnection, NDatabaseBiometricConnection)

NResult N_API NSQLiteBiometricConnectionCreate(HNSQLiteBiometricConnection * phConnection);
NResult N_API NSQLiteBiometricConnectionCreateWithFileNameN(HNString hFileName, HNSQLiteBiometricConnection * phConnection);
#ifndef N_NO_ANSI_FUNC
NResult N_API NSQLiteBiometricConnectionCreateWithFileNameA(const NAChar * szFileName, HNSQLiteBiometricConnection * phConnection);
#endif
#ifndef N_NO_UNICODE
NResult N_API NSQLiteBiometricConnectionCreateWithFileNameW(const NWChar * szFileName, HNSQLiteBiometricConnection * phConnection);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NSQLiteBiometricConnectionCreateWithFileName(const NChar * szFileName, HNSQLiteBiometricConnection * phConnection);
#endif
#define NSQLiteBiometricConnectionCreateWithFileName N_FUNC_AW(NSQLiteBiometricConnectionCreateWithFileName)

NResult N_API NSQLiteBiometricConnectionGetFileName(HNSQLiteBiometricConnection hConnection, HNString * phValue);
NResult N_API NSQLiteBiometricConnectionSetFileNameN(HNSQLiteBiometricConnection hConnection, HNString hValue);
#ifndef N_NO_ANSI_FUNC
NResult N_API NSQLiteBiometricConnectionSetFileNameA(HNSQLiteBiometricConnection hConnection, const NAChar * szValue);
#endif
#ifndef N_NO_UNICODE
NResult N_API NSQLiteBiometricConnectionSetFileNameW(HNSQLiteBiometricConnection hConnection, const NWChar * szValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NSQLiteBiometricConnectionSetFileName(HNSQLiteBiometricConnection hConnection, const NChar * szValue);
#endif
#define NSQLiteBiometricConnectionSetFileName N_FUNC_AW(NSQLiteBiometricConnectionSetFileName)

#ifdef N_CPP
}
#endif

#endif // !N_SQLITE_BIOMETRIC_CONNECTION_H_INCLUDED
