#ifndef N_BIOMETRIC_ATTRIBUTES_H_INCLUDED
#define N_BIOMETRIC_ATTRIBUTES_H_INCLUDED

#include <Biometrics/NBiometricTypes.h>
#include <Core/NObject.h>

#ifdef N_CPP
extern "C"
{
#endif

N_DECLARE_OBJECT_TYPE(NBiometricAttributes, NObject)

NResult N_API NBiometricAttributesGetBiometricType(HNBiometricAttributes hAttributes, NBiometricType * pValue);
NResult N_API NBiometricAttributesGetStatus(HNBiometricAttributes hAttributes, NBiometricStatus * pValue);
NResult N_API NBiometricAttributesSetStatus(HNBiometricAttributes hAttributes, NBiometricStatus value);
NResult N_API NBiometricAttributesGetQuality(HNBiometricAttributes hAttributes, NByte * pValue);
NResult N_API NBiometricAttributesSetQuality(HNBiometricAttributes hAttributes, NByte value);

NResult N_API NBiometricAttributesGetChild(HNBiometricAttributes hAttributes, HNObject * phValue);
NResult N_API NBiometricAttributesGetChildSubject(HNBiometricAttributes hAttributes, HNObject * phValue);

#ifdef N_CPP
}
#endif

#endif // !N_BIOMETRIC_ATTRIBUTES_H_INCLUDED
