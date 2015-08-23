#ifndef N_CLUSTER_BIOMETRIC_CONNECTION_H_INCLUDED
#define N_CLUSTER_BIOMETRIC_CONNECTION_H_INCLUDED

#include <Biometrics/Client/NRemoteBiometricConnection.h>

#ifdef N_CPP
extern "C"
{
#endif

struct NClusterAddress_
{
	HNString hHost;
	NInt port;
	NInt adminPort;
};
#ifndef N_CLUSTER_BIOMETRIC_CONNECTION_HPP_INCLUDED
typedef struct NClusterAddress_ NClusterAddress;
#endif
N_DECLARE_TYPE(NClusterAddress)

NResult N_API NClusterAddressCreateN(HNString hHost, NInt port, NInt adminPort, struct NClusterAddress_ * pValue);
#ifndef N_NO_ANSI_FUNC
NResult N_API NClusterAddressCreateA(const NAChar * szHost, NInt port, NInt adminPort, struct NClusterAddress_ * pValue);
#endif
#ifndef N_NO_UNICODE
NResult N_API NClusterAddressCreateW(const NWChar * szHost, NInt port, NInt adminPort, struct NClusterAddress_ * pValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NClusterAddressCreate(const NChar * szHost, NInt port, NInt adminPort, NClusterAddress_ * pValue);
#endif
#define NClusterAddressCreate N_FUNC_AW(NClusterAddressCreate)

NResult N_API NClusterAddressDispose(struct NClusterAddress_ * pValue);
NResult N_API NClusterAddressCopy(const struct NClusterAddress_ * pSrcValue, struct NClusterAddress_ * pDstValue);
NResult N_API NClusterAddressSet(const struct NClusterAddress_ * pSrcValue, struct NClusterAddress_ * pDstValue);

N_DECLARE_OBJECT_TYPE(NClusterBiometricConnection, NRemoteBiometricConnection)

NResult N_API NClusterBiometricConnectionCreate(HNClusterBiometricConnection * phConnection);
NResult N_API NClusterBiometricConnectionCreateWithAddress(const struct NClusterAddress_ * pAddress, HNClusterBiometricConnection * phConnection);
NResult N_API NClusterBiometricConnectionCreateWithHostN(HNString hHost, NInt port, NInt adminPort, HNClusterBiometricConnection * phConnection);
#ifndef N_NO_ANSI_FUNC
NResult N_API NClusterBiometricConnectionCreateWithHostA(const NAChar * szHost, NInt port, NInt adminPort, HNClusterBiometricConnection * phConnection);
#endif
#ifndef N_NO_UNICODE
NResult N_API NClusterBiometricConnectionCreateWithHostW(const NWChar * szHost, NInt port, NInt adminPort, HNClusterBiometricConnection * phConnection);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NClusterBiometricConnectionCreateWithHost(const NChar * szHost, NInt port, NInt adminPort, HNClusterBiometricConnection * phConnection);
#endif
#define NClusterBiometricConnectionCreateWithHost N_FUNC_AW(NClusterBiometricConnectionCreateWithHost)

NResult N_API NClusterBiometricConnectionGetAddressCount(HNClusterBiometricConnection hConnection, NInt * pValue);
NResult N_API NClusterBiometricConnectionGetAddress(HNClusterBiometricConnection hConnection, NInt index, struct NClusterAddress_ * pValue);
NResult N_API NClusterBiometricConnectionGetAddresses(HNClusterBiometricConnection hConnection, struct NClusterAddress_ * * parValues, NInt * pValueCount);
NResult N_API NClusterBiometricConnectionGetAddressCapacity(HNClusterBiometricConnection hConnection, NInt * pValue);
NResult N_API NClusterBiometricConnectionSetAddressCapacity(HNClusterBiometricConnection hConnection, NInt value);
NResult N_API NClusterBiometricConnectionSetAddress(HNClusterBiometricConnection hConnection, NInt index, const struct NClusterAddress_ * pValue);
NResult N_API NClusterBiometricConnectionAddAddress(HNClusterBiometricConnection hConnection, const struct NClusterAddress_ * pValue, NInt * pIndex);
NResult N_API NClusterBiometricConnectionInsertAddress(HNClusterBiometricConnection hConnection, NInt index, const struct NClusterAddress_ * pValue);
NResult N_API NClusterBiometricConnectionRemoveAddressAt(HNClusterBiometricConnection hConnection, NInt index);
NResult N_API NClusterBiometricConnectionClearAddresses(HNClusterBiometricConnection hConnection);

NResult N_API NClusterBiometricConnectionGetHost(HNClusterBiometricConnection hConnection, HNString * phValue);
NResult N_API NClusterBiometricConnectionSetHostN(HNClusterBiometricConnection hConnection, HNString hValue);
#ifndef N_NO_ANSI_FUNC
NResult N_API NClusterBiometricConnectionSetHostA(HNClusterBiometricConnection hConnection, const NAChar * szValue);
#endif
#ifndef N_NO_UNICODE
NResult N_API NClusterBiometricConnectionSetHostW(HNClusterBiometricConnection hConnection, const NWChar * szValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NClusterBiometricConnectionSetHost(HNClusterBiometricConnection hConnection, const NChar * szValue);
#endif
#define NClusterBiometricConnectionSetHost N_FUNC_AW(NClusterBiometricConnectionSetHost)
NResult N_API NClusterBiometricConnectionGetPort(HNClusterBiometricConnection hConnection, NInt * pValue);
NResult N_API NClusterBiometricConnectionSetPort(HNClusterBiometricConnection hConnection, NInt value);
NResult N_API NClusterBiometricConnectionGetAdminPort(HNClusterBiometricConnection hConnection, NInt * pValue);
NResult N_API NClusterBiometricConnectionSetAdminPort(HNClusterBiometricConnection hConnection, NInt value);
NResult N_API NClusterBiometricConnectionGetRetryCount(HNClusterBiometricConnection hConnection, NInt * pValue);
NResult N_API NClusterBiometricConnectionSetRetryCount(HNClusterBiometricConnection hConnection, NInt value);

#ifdef N_CPP
}
#endif

#endif // !N_CLUSTER_BIOMETRIC_CONNECTION_H_INCLUDED
