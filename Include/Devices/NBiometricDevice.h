#ifndef N_BIOMETRIC_DEVICE_H_INCLUDED
#define N_BIOMETRIC_DEVICE_H_INCLUDED

#include <Devices/NDevice.h>
#include <Biometrics/NBiometricTypes.h>
#include <Biometrics/NBiometric.h>

#ifdef N_CPP
extern "C"
{
#endif

N_DECLARE_OBJECT_TYPE(NBiometricDevice, NDevice)

typedef NResult (N_CALLBACK NBiometricDeviceCapturePreviewCallback)(HNBiometricDevice hDevice, HNBiometric hBiometric, void * pParam);
N_DECLARE_TYPE(NBiometricDeviceCapturePreviewCallback)

NResult N_API NBiometricDeviceCancel(HNBiometricDevice hDevice);
NResult N_API NBiometricDeviceStartSequence(HNBiometricDevice hDevice);
NResult N_API NBiometricDeviceEndSequence(HNBiometricDevice hDevice);
NResult N_API NBiometricDeviceCapture(HNBiometricDevice hDevice, HNBiometric hBiometric, NInt timeoutMilliseconds, NBiometricStatus * pStatus);

NResult N_API NBiometricDeviceGetBiometricType(HNBiometricDevice hDevice, NBiometricType * pValue);
NResult N_API NBiometricDeviceGetVendorId(HNBiometricDevice hDevice, NUShort * pValue);
NResult N_API NBiometricDeviceGetProductId(HNBiometricDevice hDevice, NUShort * pValue);
NResult N_API NBiometricDeviceIsSpoofDetectionSupported(HNBiometricDevice hDevice, NBool * pValue);
NResult N_API NBiometricDeviceGetSpoofDetection(HNBiometricDevice hDevice, NBool * pValue);
NResult N_API NBiometricDeviceSetSpoofDetection(HNBiometricDevice hDevice, NBool value);

NResult N_API NBiometricDeviceAddCapturePreview(HNBiometricDevice hDevice, HNCallback hCallback);
NResult N_API NBiometricDeviceAddCapturePreviewCallback(HNBiometricDevice hDevice, NBiometricDeviceCapturePreviewCallback pCallback, void * pParam);
NResult N_API NBiometricDeviceRemoveCapturePreview(HNBiometricDevice hDevice, HNCallback hCallback);
NResult N_API NBiometricDeviceRemoveCapturePreviewCallback(HNBiometricDevice hDevice, NBiometricDeviceCapturePreviewCallback pCallback, void * pParam);

#ifdef N_CPP
}
#endif

#endif // !N_BIOMETRIC_DEVICE_H_INCLUDED
