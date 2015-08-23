#ifndef N_BIOMETRIC_CLIENT_H_INCLUDED
#define N_BIOMETRIC_CLIENT_H_INCLUDED

#include <Biometrics/NBiometrics.h>
#include <Devices/NDevices.h>
#include <Licensing/NLicensing.h>
#include <Devices/NDeviceManager.h>
#include <Devices/NCamera.h>
#include <Devices/NFScanner.h>
#include <Devices/NIrisScanner.h>
#include <Devices/NMicrophone.h>
#include <Biometrics/NBiometricEngine.h>
#include <Biometrics/NSubject.h>
#include <Biometrics/Client/NSQLiteBiometricConnection.h>
#include <Biometrics/Client/NOdbcBiometricConnection.h>
#include <Biometrics/Client/NClusterBiometricConnection.h>

#ifdef N_CPP
extern "C"
{
#endif

N_DECLARE_MODULE(NBiometricClient)

N_DECLARE_OBJECT_TYPE(NBiometricClient, NBiometricEngine)

NResult N_API NBiometricClientCreate(HNBiometricClient * phBiometricClient);

NResult N_API NBiometricClientGetRemoteConnectionCount(HNBiometricClient hBiometricClient, NInt * pValue);
NResult N_API NBiometricClientGetRemoteConnection(HNBiometricClient hBiometricClient, NInt index, HNRemoteBiometricConnection * phValue);
NResult N_API NBiometricClientGetRemoteConnections(HNBiometricClient hBiometricClient, HNRemoteBiometricConnection * * parhValues, NInt * pValueCount);
NResult N_API NBiometricClientGetRemoteConnectionCapacity(HNBiometricClient hBiometricClient, NInt * pValue);
NResult N_API NBiometricClientSetRemoteConnectionCapacity(HNBiometricClient hBiometricClient, NInt value);
NResult N_API NBiometricClientSetRemoteConnection(HNBiometricClient hBiometricClient, NInt index, HNRemoteBiometricConnection hValue);
NResult N_API NBiometricClientAddRemoteConnection(HNBiometricClient hBiometricClient, HNRemoteBiometricConnection hValue, NInt * pIndex);
NResult N_API NBiometricClientAddRemoteConnectionToClusterN(HNBiometricClient hBiometricClient, HNString hHost, NInt port, NInt adminPort, HNClusterBiometricConnection * phConnection);
#ifndef N_NO_ANSI_FUNC
NResult N_API NBiometricClientAddRemoteConnectionToClusterA(HNBiometricClient hBiometricClient, const NAChar * szHost, NInt port, NInt adminPort, HNClusterBiometricConnection * phConnection);
#endif
#ifndef N_NO_UNICODE
NResult N_API NBiometricClientAddRemoteConnectionToClusterW(HNBiometricClient hBiometricClient, const NWChar * szHost, NInt port, NInt adminPort, HNClusterBiometricConnection * phConnection);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NBiometricClientAddRemoteConnectionToCluster(HNBiometricClient hBiometricClient, const NChar * szHost, NInt port, NInt adminPort, HNClusterBiometricConnection * phConnection);
#endif
#define NBiometricClientAddRemoteConnectionToCluster N_FUNC_AW(NBiometricClientAddRemoteConnectionToCluster)
NResult N_API NBiometricClientInsertRemoteConnection(HNBiometricClient hBiometricClient, NInt index, HNRemoteBiometricConnection hValue);
NResult N_API NBiometricClientRemoveRemoteConnectionAt(HNBiometricClient hBiometricClient, NInt index);
NResult N_API NBiometricClientClearRemoteConnections(HNBiometricClient hBiometricClient);

NResult N_API NBiometricClientGetBiometricTypes(HNBiometricClient hBiometricClient, NBiometricType * pValue);
NResult N_API NBiometricClientSetBiometricTypes(HNBiometricClient hBiometricClient, NBiometricType value);
NResult N_API NBiometricClientGetUseDeviceManager(HNBiometricClient hBiometricClient, NBool * pValue);
NResult N_API NBiometricClientSetUseDeviceManager(HNBiometricClient hBiometricClient, NBool value);
NResult N_API NBiometricClientGetLocalOperations(HNBiometricClient hBiometricClient, NBiometricOperations * pValue);
NResult N_API NBiometricClientSetLocalOperations(HNBiometricClient hBiometricClient, NBiometricOperations value);
NResult N_API NBiometricClientGetDatabaseConnection(HNBiometricClient hBiometricClient, HNDatabaseBiometricConnection * phValue);
NResult N_API NBiometricClientSetDatabaseConnection(HNBiometricClient hBiometricClient, HNDatabaseBiometricConnection hValue);
NResult N_API NBiometricClientGetDeviceManager(HNBiometricClient hBiometricClient, HNDeviceManager * phValue);
NResult N_API NBiometricClientGetFaceCaptureDevice(HNBiometricClient hBiometricClient, HNCamera * phValue);
NResult N_API NBiometricClientSetFaceCaptureDevice(HNBiometricClient hBiometricClient, HNCamera hValue);
NResult N_API NBiometricClientGetFingerScanner(HNBiometricClient hBiometricClient, HNFScanner * phValue);
NResult N_API NBiometricClientSetFingerScanner(HNBiometricClient hBiometricClient, HNFScanner hValue);
NResult N_API NBiometricClientGetIrisScanner(HNBiometricClient hBiometricClient, HNIrisScanner * phValue);
NResult N_API NBiometricClientSetIrisScanner(HNBiometricClient hBiometricClient, HNIrisScanner hValue);
NResult N_API NBiometricClientGetPalmScanner(HNBiometricClient hBiometricClient, HNFScanner * phValue);
NResult N_API NBiometricClientSetPalmScanner(HNBiometricClient hBiometricClient, HNFScanner hValue);
NResult N_API NBiometricClientGetVoiceCaptureDevice(HNBiometricClient hBiometricClient, HNMicrophone * phValue);
NResult N_API NBiometricClientSetVoiceCaptureDevice(HNBiometricClient hBiometricClient, HNMicrophone hValue);

NResult N_API NBiometricClientGetCurrentBiometric(HNBiometricClient hBiometricClient, HNBiometric * phValue);
NResult N_API NBiometricClientGetCurrentSubject(HNBiometricClient hBiometricClient, HNSubject * phValue);

NResult N_API NBiometricClientAddCurrentBiometricCompleted(HNBiometricClient hBiometricClient, HNCallback hCallback);
NResult N_API NBiometricClientAddCurrentBiometricCompletedCallback(HNBiometricClient hBiometricClient, NObjectCallback * pCallback, void * pParam);
NResult N_API NBiometricClientRemoveCurrentBiometricCompleted(HNBiometricClient hBiometricClient, HNCallback hCallback);
NResult N_API NBiometricClientRemoveCurrentBiometricCompletedCallback(HNBiometricClient hBiometricClient, NObjectCallback * pCallback, void * pParam);

NResult N_API NBiometricClientAddCurrentSubjectCompleted(HNBiometricClient hBiometricClient, HNCallback hCallback);
NResult N_API NBiometricClientAddCurrentSubjectCompletedCallback(HNBiometricClient hBiometricClient, NObjectCallback * pCallback, void * pParam);
NResult N_API NBiometricClientRemoveCurrentSubjectCompleted(HNBiometricClient hBiometricClient, HNCallback hCallback);
NResult N_API NBiometricClientRemoveCurrentSubjectCompletedCallback(HNBiometricClient hBiometricClient, NObjectCallback * pCallback, void * pParam);

NResult N_API NBiometricClientSetDatabaseConnectionToSQLiteN(HNBiometricClient hBiometricClient, HNString hFileName, HNSQLiteBiometricConnection * phConnection);
#ifndef N_NO_ANSI_FUNC
NResult N_API NBiometricClientSetDatabaseConnectionToSQLiteA(HNBiometricClient hBiometricClient, const NAChar * szFileName, HNSQLiteBiometricConnection * phConnection);
#endif
#ifndef N_NO_UNICODE
NResult N_API NBiometricClientSetDatabaseConnectionToSQLiteW(HNBiometricClient hBiometricClient, const NWChar * szFileName, HNSQLiteBiometricConnection * phConnection);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NBiometricClientSetDatabaseConnectionToSQLite(HNBiometricClient hBiometricClient, const NChar * szFileName, HNSQLiteBiometricConnection * phConnection);
#endif
#define NBiometricClientSetDatabaseConnectionToSQLite N_FUNC_AW(NBiometricClientSetDatabaseConnectionToSQLite)
NResult N_API NBiometricClientSetDatabaseConnectionToOdbcN(HNBiometricClient hBiometricClient, HNString hConnectionString, HNString hTableName, HNOdbcBiometricConnection * phConnection);
#ifndef N_NO_ANSI_FUNC
NResult N_API NBiometricClientSetDatabaseConnectionToOdbcA(HNBiometricClient hBiometricClient, const NAChar * szConnectionString, const NAChar * szTableName, HNOdbcBiometricConnection * phConnection);
#endif
#ifndef N_NO_UNICODE
NResult N_API NBiometricClientSetDatabaseConnectionToOdbcW(HNBiometricClient hBiometricClient, const NWChar * szConnectionString, const NWChar * szTableName, HNOdbcBiometricConnection * phConnection);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NBiometricClientSetDatabaseConnectionToOdbc(HNBiometricClient hBiometricClient, const NChar * szConnectionString, const NChar * szTableName, HNOdbcBiometricConnection * phConnection);
#endif
#define NBiometricClientSetDatabaseConnectionToOdbc N_FUNC_AW(NBiometricClientSetDatabaseConnectionToOdbc)
NResult N_API NBiometricClientCaptureBiometric(HNBiometricEngine hBiometricEngine, HNBiometric hBiometric, NBiometricStatus * pResult);
NResult N_API NBiometricClientCaptureBiometricAsync(HNBiometricClient hBiometricClient, HNBiometric hBiometric, HNAsyncOperation * phAsyncOperation);
NResult N_API NBiometricClientCapture(HNBiometricClient hBiometricClient, HNSubject hSubject, NBiometricStatus * pResult);
NResult N_API NBiometricClientCaptureAsync(HNBiometricClient hBiometricClient, HNSubject hSubject, HNAsyncOperation * phAsyncOperation);
NResult N_API NBiometricClientCancel(HNBiometricClient hBiometricClient);
NResult N_API NBiometricClientForceStart(HNBiometricClient hBiometricClient);
NResult N_API NBiometricClientForce(HNBiometricClient hBiometricClient);
NResult N_API NBiometricClientRepeat(HNBiometricClient hBiometricClient);
NResult N_API NBiometricClientSkip(HNBiometricClient hBiometricClient);

#ifdef N_CPP
}
#endif

#endif // !N_BIOMETRIC_CLIENT_H_INCLUDED
