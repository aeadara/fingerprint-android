#ifndef N_BIOMETRIC_H_INCLUDED
#define N_BIOMETRIC_H_INCLUDED

#include <Core/NExpandableObject.h>
#include <Biometrics/NBiometricTypes.h>
#include <Biometrics/NBiometricAttributes.h>

#ifdef N_CPP
extern "C"
{
#endif

N_DECLARE_OBJECT_TYPE(NSubject, NExpandableObject)

typedef enum NBiometricCaptureOptions_
{
	nbcoNone = 0,
	nbcoManual = 1,
	nbcoStream = 2
} NBiometricCaptureOptions;

N_DECLARE_TYPE(NBiometricCaptureOptions)

NBool N_API NBiometricCaptureOptionsIsValid(NBiometricCaptureOptions value);

N_DECLARE_OBJECT_TYPE(NBiometric, NObject)

NResult N_API NBiometricGetBiometricType(HNBiometric hBiometric, NBiometricType * pValue);
NResult N_API NBiometricGetCaptureOptions(HNBiometric hBiometric, NBiometricCaptureOptions * pValue);
NResult N_API NBiometricSetCaptureOptions(HNBiometric hBiometric, NBiometricCaptureOptions value);
NResult N_API NBiometricGetStatus(HNBiometric hBiometric, NBiometricStatus * pValue);
NResult N_API NBiometricSetStatus(HNBiometric hBiometric, NBiometricStatus value);
NResult N_API NBiometricGetHasMoreSamples(HNBiometric hBiometric, NBool * pValue);
NResult N_API NBiometricSetHasMoreSamples(HNBiometric hBiometric, NBool value);
NResult N_API NBiometricGetSessionId(HNBiometric hBiometric, NInt * pValue);
NResult N_API NBiometricSetSessionId(HNBiometric hBiometric, NInt value);
NResult N_API NBiometricGetParentObject(HNBiometric hBiometric, HNBiometricAttributes * phValue);
NResult N_API NBiometricGetFileName(HNBiometric hBiometric, HNString * phValue);
NResult N_API NBiometricSetFileNameN(HNBiometric hBiometric, HNString hValue);
#ifndef N_NO_ANSI_FUNC
NResult N_API NBiometricSetFileNameA(HNBiometric hBiometric, const NAChar * szValue);
#endif
#ifndef N_NO_UNICODE
NResult N_API NBiometricSetFileNameW(HNBiometric hBiometric, const NWChar * szValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NBiometricSetFileName(HNBiometric hBiometric, const NChar * szValue);
#endif
#define NBiometricSetFileName N_FUNC_AW(NBiometricSetFileName)
NResult N_API NBiometricGetError(HNBiometric hBiometric, HNError * phValue);

#ifdef N_CPP
}
#endif

#endif // !N_BIOMETRIC_H_INCLUDED
