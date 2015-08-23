#ifndef NDM_INTERFACE_H_INCLUDED
#define NDM_INTERFACE_H_INCLUDED

#include <Devices/NDeviceManager.h>
#include <Devices/NCaptureDevice.h>
#include <Devices/NCamera.h>
#include <Devices/NMicrophone.h>
#include <Devices/NBiometricDevice.h>
#include <Devices/NFScanner.h>
#include <Devices/NFingerScanner.h>
#include <Devices/NPalmScanner.h>
#include <Devices/NIrisScanner.h>
#include <Plugins/NPluginInternal.h>
#include <ComponentModel/NParameterDescriptor.h>
#include <Core/NPropertyBag.h>
#include <Devices/ComponentModel/NDeviceMethodDescriptor.h>
#include <Devices/ComponentModel/NDevicePropertyDescriptor.h>
#include <Devices/ComponentModel/NDeviceEventDescriptor.h>

#ifdef N_CPP
extern "C"
{
#endif

typedef NResult (N_CALLBACK NdmIsCaptureDeviceCapturingChangedProc)(NHandle hDevice, void * pParam);
typedef NResult (N_CALLBACK NdmPreviewFScannerProc)(NHandle hDevice, HNObject hCaptureInfo, const HNImage * arhImages, NInt imageCount, NBiometricStatus * pStatus, void * pParam);
typedef NResult (N_CALLBACK NdmPreviewIrisScannerProc)(NHandle hDevice, HNObject hCaptureInfo, const HNImage * arhImages, NInt imageCount, NBiometricStatus * pStatus, void * pParam);
typedef NResult (N_CALLBACK NdmCameraStillCapturedProc)(NHandle hDevice, HNStream hStream, HNValue hId, HNPropertyBag hProperties, void * pParam);

typedef struct NdmInterfaceV1_
{
	// The comments below specify which functions are required for different device types.
	
	// Mandatory.
	NResult (N_CALLBACK GetSupportedDeviceTypes)(NDeviceType * pValue);
	// Optional. Can be omitted if plugin knows better when to trigger device update cycle.
	NResult (N_CALLBACK UpdateDeviceList)(void);
	// Optional. Used in some complex plugins.
	NResult (N_CALLBACK CanUse)(HNPlugin hOtherPlugin, NBool * pValue);
	// Optional. Used in some complex plugins.
	NResult (N_CALLBACK DeviceAdded)(NHandle hDevice, HNPlugin hPlugin, void * pParam);
	// Optional. Used in some complex plugins.
	NResult (N_CALLBACK DeviceLost)(NHandle hDevice, HNPlugin hPlugin, void * pParam);
	// Optional. Used in some complex plugins.
	NResult (N_CALLBACK DeviceRemoved)(NHandle hDevice, HNPlugin hPlugin, void * pParam);
	// Recommended. If the function missing, the default value of ndtNone will be used, and only basic device functionality will be usable.
	NResult (N_CALLBACK GetDeviceType)(NHandle hDevice, NDeviceType * pValue);
	// Optional. Used for multi-biometric devices and in some complex plugins.
	NResult (N_CALLBACK GetDeviceParent)(NHandle hDevice, HNPlugin * phParentPlugin, NHandle * phParentHandle);
	// Mandatory.
	NResult (N_CALLBACK GetDeviceId)(NHandle hDevice, HNString * phValue);
	// Mandatory.
	NResult (N_CALLBACK GetDeviceDisplayName)(NHandle hDevice, HNString * phValue);
	// Optional.
	NResult (N_CALLBACK GetDeviceMake)(NHandle hDevice, HNString * phValue);
	// Optional.
	NResult (N_CALLBACK GetDeviceModel)(NHandle hDevice, HNString * phValue);
	// Optional.
	NResult (N_CALLBACK GetDeviceSerialNumber)(NHandle hDevice, HNString * phValue);
	// Mandatory for ndtCaptureDevice.
	NResult (N_CALLBACK StartCaptureDeviceCapturing)(NHandle hDevice, NdmIsCaptureDeviceCapturingChangedProc pIsCapturingChanged, void * pParam);
	// Mandatory for ndtCamera.
	NResult (N_CALLBACK GetCameraFrame)(NHandle hDevice, HNImage * phImage, void * pParam);
	// Mandatory for ndtCaptureDevice.
	NResult (N_CALLBACK StopCaptureDeviceCapturing)(NHandle hDevice, void * pParam);
	// Mandatory for ndtCaptureDevice.
	NResult (N_CALLBACK IsCaptureDeviceCapturing)(NHandle hDevice, NBool * pValue, void * pParam);
	// Recommended for ndtBiometricDevice. The default value will be inferred from GetDeviceType if the function is missing.
	NResult (N_CALLBACK GetBiometricDeviceBiometricType)(NHandle hDevice, NBiometricType * pValue);
	// Optional for ndtBiometricDevice. If present, GetBiometricDeviceProductId is also required.
	NResult (N_CALLBACK GetBiometricDeviceVendorId)(NHandle hDevice, NUShort * pValue);
	// Optional for ndtBiometricDevice. If present, GetBiometricDeviceVendorId is also required.
	NResult (N_CALLBACK GetBiometricDeviceProductId)(NHandle hDevice, NUShort * pValue);
	// Optional for ndtBiometricDevice. If present, GetBiometricDeviceSpoofDetection and SetBiometricDeviceSpoofDetection are also required.
	NResult (N_CALLBACK IsBiometricDeviceSpoofDetectionSupported)(NHandle hDevice, NBool * pValue);
	// Optional for ndtBiometricDevice. If present, IsBiometricDeviceSpoofDetectionSupported and SetBiometricDeviceSpoofDetection are also required.
	NResult (N_CALLBACK GetBiometricDeviceSpoofDetection)(NHandle hDevice, NBool * pValue);
	// Optional for ndtBiometricDevice. If present, IsBiometricDeviceSpoofDetectionSupported and GetBiometricDeviceSpoofDetection are also required.
	NResult (N_CALLBACK SetBiometricDeviceSpoofDetection)(NHandle hDevice, NBool value, void * pParam);
	// Mandatory for ndtBiometricDevice.
	NResult (N_CALLBACK CancelBiometricDevice)(NHandle hDevice, void * pParam);
	// Recommended for ndtFScanner. The default value of nfitLiveScanPlain or nfitLiveScanPalm (according to NDeviceType) will be used if the function is missing.
	NResult (N_CALLBACK GetFScannerSupportedImpressionTypes)(NHandle hDevice, NFImpressionType * arValue, NInt valueLength);
	// Recommended for ndtFScanner. The default value of nfpUnknown or nfpUnknownPalm (according to NDeviceType) will be used if the function is missing.
	NResult (N_CALLBACK GetFScannerSupportedPositions)(NHandle hDevice, NFPosition * arValue, NInt valueLength);
	// Mandatory for ndtFScanner.
	NResult (N_CALLBACK CaptureFScanner)(NHandle hDevice, HNObject hCaptureInfo, NFImpressionType impressionType, NFPosition position, const NFPosition * arMissingPositions, NInt missingPositionCount,
		NBool automatic, NInt timeoutMilliseconds, const HNFAttributes * arhObjects, NInt objectCount, HNImage * arhImages, NInt imagesLength, NInt * pImageCount, NBiometricStatus * pStatus,
		NdmPreviewFScannerProc pPreview, void * pParam);
	// Recommended for ndtIrisScanner. The default value of nepUnknown will be used if the function is missing.
	NResult (N_CALLBACK GetIrisScannerSupportedPositions)(NHandle hDevice, NEPosition * arValue, NInt valueLength);
	// Mandatory for ndtIrisScanner.
	NResult (N_CALLBACK CaptureIrisScanner)(NHandle hDevice, HNObject hCaptureInfo, NEPosition position, const NEPosition * arMissingPositions, NInt missingPositionCount,
		NBool automatic, NInt timeoutMilliseconds, const HNEAttributes * arhObjects, NInt objectCount, HNImage * arhImages, NInt imagesLength, NInt * pImageCount, NBiometricStatus * pStatus,
		NdmPreviewIrisScannerProc pPreview, void * pParam);
	//--------
	// V1.1
	//--------
	// Optional for ndtCaptureDevice. The default value will be inferred from GetDeviceType if the function is missing.
	NResult (N_CALLBACK GetCaptureDeviceMediaType)(NHandle hDevice, NMediaType * pValue);
	// Recommended for ndtCaptureDevice. If present, SetCaptureDeviceCurrentFormat is also required. Empty array will be used if the function is missing.
	NResult (N_CALLBACK GetCaptureDeviceFormats)(NHandle hDevice, HNMediaFormat * * parhFormats, NInt * pFormatCount);
	// Recommended for ndtCaptureDevice. If present, SetCaptureDeviceCurrentFormat is also required. NULL will be used if the function is missing.
	NResult (N_CALLBACK GetCaptureDeviceCurrentFormat)(NHandle hDevice, HNMediaFormat * phFormat);
	// Recommended for ndtCaptureDevice.
	NResult (N_CALLBACK SetCaptureDeviceCurrentFormat)(NHandle hDevice, HNMediaFormat hFormat, void * pParam);
	// Mandatory for ndtMicrophone.
	NResult (N_CALLBACK GetMicrophoneSoundSample)(NHandle hDevice, HNSoundBuffer * phSoundBuffer, void * pParam);
	//--------
	// V1.2
	//--------
	// Optional for ndtBiometricDevice. If present, EndBiometricDeviceSequence is also required.
	NResult (N_CALLBACK StartBiometricDeviceSequence)(NHandle hDevice, void * pParam);
	// Optional for ndtBiometricDevice. If present, StartBiometricDeviceSequence is also required.
	NResult (N_CALLBACK EndBiometricDeviceSequence)(NHandle hDevice, void * pParam);
	//--------
	// V1.3
	//--------
	// Optional. If present GetConnectToDeviceParameters, ConnectToDevice and DisconnectFromDevice are also required
	NResult (N_CALLBACK IsConnectToDeviceSupported)(NBool * pValue);
	// Optional. If present IsConnectToDeviceSupported, ConnectToDevice and DisconnectFromDevice are also required
	NResult (N_CALLBACK GetConnectToDeviceParameters)(HNParameterDescriptor * * parhParameters, NInt * pParameterCount);
	// Optional. If present IsConnectToDeviceSupported, GetConnectToDeviceParameters and DisconnectFromDevice are also required
	NResult (N_CALLBACK ConnectToDevice)(HNPropertyBag hParameters, NHandle * phDevice, void * pParam);
	// Optional. If present IsConnectToDeviceSupported, GetConnectToDeviceParameters and ConnectToDevice are also required
	NResult (N_CALLBACK DisconnectFromDevice)(NHandle hDevice, void * pParam);
	// Optional
	NResult (N_CALLBACK GetDeviceProperties)(NHandle hDevice, HNDevicePropertyDescriptor * * parhProperties, NInt * pPropertyCount);
	// Optional. Used in some complex plugins.
	NResult (N_CALLBACK DevicePropertyChanged)(NHandle hDevice, HNPlugin hPlugin, HNString hPropertyName, void * pParam);
	// Optional for ndtCamera. If present, ResetCameraFocus and FocusCamera are also required.
	NResult (N_CALLBACK IsCameraFocusSupported)(NHandle hDevice, NBool * pValue);
	// Optional for ndtCamera. If present, GetCameraFocusRegion and SetCameraFocusRegion are also required.
	NResult (N_CALLBACK IsCameraFocusRegionSupported)(NHandle hDevice, NBool * pValue);
	// Optional for ndtCamera. If present, IsCameraFocusRegionSupported and SetCameraFocusRegion are also required.
	NResult (N_CALLBACK GetCameraFocusRegion)(NHandle hDevice, struct NRectF_ * pValue, NBool * pHasValue);
	// Optional for ndtCamera. If present, IsCameraFocusRegionSupported and GetCameraFocusRegion are also required.
	NResult (N_CALLBACK SetCameraFocusRegion)(NHandle hDevice, const struct NRectF_ * pValue, void * pParam);
	// Optional for ndtCamera. If present, IsCameraFocusSupported and FocusCamera are also required.
	NResult (N_CALLBACK ResetCameraFocus)(NHandle hDevice, void * pParam);
	// Optional for ndtCamera. If present, IsCameraFocusSupported and ResetCameraFocus are also required.
	NResult (N_CALLBACK FocusCamera)(NHandle hDevice, NCameraStatus * pStatus, void * pParam);
	// Optional for ndtCamera. If present StartCameraCapturing and CaptureCameraStill are also required.
	NResult (N_CALLBACK IsCameraStillCaptureSupported)(NHandle hDevice, NBool * pValue);
	// Recommended for ndtCamera with IsCameraStillCaptureSupported. If present, SetCameraCurrentStillFormat is also required. Empty array will be used if the function is missing.
	NResult (N_CALLBACK GetCameraStillFormats)(NHandle hDevice, HNVideoFormat * * parhFormats, NInt * pFormatCount);
	// Recommended for ndtCamera with IsCameraStillCaptureSupported. If present, SetCameraCurrentStillFormat is also required. NULL will be used if the function is missing.
	NResult (N_CALLBACK GetCameraCurrentStillFormat)(NHandle hDevice, HNVideoFormat * phFormat);
	// Recommended for ndtCamera with IsCameraStillCaptureSupported.
	NResult (N_CALLBACK SetCameraCurrentStillFormat)(NHandle hDevice, HNVideoFormat hFormat, void * pParam);
	// Optional for ndtCamera. If present IsCameraStillCaptureSupported and CaptureCameraStill are also required.
	NResult (N_CALLBACK StartCameraCapturing)(NHandle hDevice, NdmIsCaptureDeviceCapturingChangedProc pIsCapturingChanged, NdmCameraStillCapturedProc pStillCaptured, void * pParam);
	// Optional for ndtCamera. If present IsCameraStillCaptureSupported and StartCameraCapturing are also required.
	NResult (N_CALLBACK CaptureCameraStill)(NHandle hDevice, NCameraStatus * pStatus, void * pParam);
	//--------
	// V1.5
	//--------
	// Optional
	NResult (N_CALLBACK GetDeviceMethods)(NHandle hDevice, HNDeviceMethodDescriptor * * parhMethods, NInt * pMethodCount);
	// Optional
	NResult (N_CALLBACK GetDeviceEvents)(NHandle hDevice, HNDeviceEventDescriptor * * parhEvents, NInt * pEventCount);
} NdmInterfaceV1;

typedef struct NdmHostInterfaceV1_
{
	NResult (N_CALLBACK IsDriverLoaded)(HNString hName, NBool * pValue);
	NResult (N_CALLBACK AddDevice)(NHandle hDevice, HNPlugin hPlugin, void * pParam);
	NResult (N_CALLBACK LoseDevice)(NHandle hDevice, HNPlugin hPlugin, void * pParam);
	NResult (N_CALLBACK RemoveDevice)(NHandle hDevice, HNPlugin hPlugin, void * pParam);
	//--------
	// V1.3
	//--------
	NResult (N_CALLBACK DevicePropertyChanged)(NHandle hDevice, HNPlugin hPlugin, HNString hPropertyName, void * pParam);
	//--------
	// V1.4
	//--------
	NResult (N_CALLBACK IsDevicePresent)(HNString hClass, HNString hMake, HNString hModels, NBool * pValue);
} NdmHostInterfaceV1;

#ifdef N_CPP
}
#endif

#endif // !NDM_INTERFACE_H_INCLUDED
