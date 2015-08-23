#include <Devices/NBiometricDevice.h>

#ifndef NF_SCANNER_H_INCLUDED
#define NF_SCANNER_H_INCLUDED

#include <Geometry/NGeometry.h>
#include <Images/NImage.h>
#include <Biometrics/NFAttributes.h>

#ifdef N_CPP
extern "C"
{
#endif

N_DECLARE_OBJECT_TYPE(NFScanner, NBiometricDevice)

typedef NResult (N_CALLBACK NFScannerPreviewCallback)(HNFScanner hDevice, HNImage hImage, NBiometricStatus * pStatus, const HNFAttributes * arhObjects, NInt objectCount, void * pParam);
N_DECLARE_TYPE(NFScannerPreviewCallback)

NResult N_API NFScannerGetSupportedImpressionTypes(HNFScanner hDevice, NFImpressionType * arValue, NInt valueLength);
NResult N_API NFScannerGetSupportedPositions(HNFScanner hDevice, NFPosition * arValue, NInt valueLength);
N_DEPRECATED("function is deprecated, use NBiometricDeviceCapture instead")
NResult N_API NFScannerCapture(HNFScanner hDevice, NInt timeoutMilliseconds, HNImage * phImage);
N_DEPRECATED("function is deprecated, use NBiometricDeviceCapture instead")
NResult N_API NFScannerCaptureEx(HNFScanner hDevice, NFImpressionType impressionType, NFPosition position, const NFPosition * arMissingPositions, NInt missingPositionCount,
	NBool automatic, NInt timeoutMilliseconds, NBiometricStatus * pStatus, HNFAttributes * * parhObjects, NInt * pObjectCount, HNImage * phImage);

N_DEPRECATED("function is deprecated, use NBiometricDeviceAddCapturePreview instead")
NResult N_API NFScannerAddPreview(HNFScanner hDevice, HNCallback hCallback);
N_DEPRECATED("function is deprecated, use NBiometricDeviceAddCapturePreviewCallback instead")
NResult N_API NFScannerAddPreviewCallback(HNFScanner hDevice, NFScannerPreviewCallback pCallback, void * pParam);
N_DEPRECATED("function is deprecated, use NBiometricDeviceRemoveCapturePreview instead")
NResult N_API NFScannerRemovePreview(HNFScanner hDevice, HNCallback hCallback);
N_DEPRECATED("function is deprecated, use NBiometricDeviceRemoveCapturePreviewCallback instead")
NResult N_API NFScannerRemovePreviewCallback(HNFScanner hDevice, NFScannerPreviewCallback pCallback, void * pParam);

#ifdef N_CPP
}
#endif

#endif // !NF_SCANNER_H_INCLUDED
