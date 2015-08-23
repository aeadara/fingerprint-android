#include <Devices/NBiometricDevice.h>

#ifndef N_IRIS_SCANNER_H_INCLUDED
#define N_IRIS_SCANNER_H_INCLUDED

#include <Images/NImage.h>
#include <Biometrics/NEAttributes.h>

#ifdef N_CPP
extern "C"
{
#endif

N_DECLARE_OBJECT_TYPE(NIrisScanner, NBiometricDevice)

typedef NResult (N_CALLBACK NIrisScannerPreviewCallback)(HNIrisScanner hDevice, HNImage hImage, NBiometricStatus * pStatus, const HNEAttributes * arhObjects, NInt objectCount, void * pParam);
N_DECLARE_TYPE(NIrisScannerPreviewCallback)

NResult N_API NIrisScannerGetSupportedPositions(HNIrisScanner hDevice, NEPosition * arValue, NInt valueLength);
N_DEPRECATED("function is deprecated, use NBiometricDeviceCapture instead")
NResult N_API NIrisScannerCapture(HNIrisScanner hDevice, NEPosition position, NInt timeoutMilliseconds, HNImage * phImage);
N_DEPRECATED("function is deprecated, use NBiometricDeviceCapture instead")
NResult N_API NIrisScannerCaptureEx(HNIrisScanner hDevice, NEPosition position, const NEPosition * arMissingPositions, NInt missingPositionCount,
	NBool automatic, NInt timeoutMilliseconds, NBiometricStatus * pStatus, HNEAttributes * * parhObjects, NInt * pObjectCount, HNImage * phImage);

N_DEPRECATED("function is deprecated, use NBiometricDeviceAddCapturePreview instead")
NResult N_API NIrisScannerAddPreview(HNIrisScanner hDevice, HNCallback hCallback);
N_DEPRECATED("function is deprecated, use NBiometricDeviceAddCapturePreviewCallback instead")
NResult N_API NIrisScannerAddPreviewCallback(HNIrisScanner hDevice, NIrisScannerPreviewCallback pCallback, void * pParam);
N_DEPRECATED("function is deprecated, use NBiometricDeviceRemoveCapturePreview instead")
NResult N_API NIrisScannerRemovePreview(HNIrisScanner hDevice, HNCallback hCallback);
N_DEPRECATED("function is deprecated, use NBiometricDeviceRemoveCapturePreviewCallback instead")
NResult N_API NIrisScannerRemovePreviewCallback(HNIrisScanner hDevice, NIrisScannerPreviewCallback pCallback, void * pParam);

#ifdef N_CPP
}
#endif

#endif // !N_IRIS_SCANNER_H_INCLUDED
