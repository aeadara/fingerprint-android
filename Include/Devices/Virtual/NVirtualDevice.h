#ifndef N_VIRTUAL_DEVICE_H_INCLUDED
#define N_VIRTUAL_DEVICE_H_INCLUDED

#include <Devices/NDevice.h>
#include <Biometrics/NBiometricTypes.h>
#include <Media/NVideoFormat.h>
#include <Media/NAudioFormat.h>

#ifdef N_CPP
extern "C"
{
#endif

typedef enum NVirtualDeviceOptions_
{
	nvdoNone = 0,
	nvdoCaptureIndefinetly = 1,
	nvdoSupportsSpoofDetection = 2,
	nvdoNoCaptureStatus = 4,
	nvdoReturnMultipleImages = 8
} NVirtualDeviceOptions;

N_DECLARE_TYPE(NVirtualDeviceOptions)

N_DECLARE_OBJECT_TYPE(NVirtualDevice, NObject)

NResult N_API NVirtualDeviceCreate(HNVirtualDevice * phDevice);

NResult N_API NVirtualDeviceGetDeviceType(HNVirtualDevice hDevice, NDeviceType * pValue);
NResult N_API NVirtualDeviceSetDeviceType(HNVirtualDevice hDevice, NDeviceType value);
NResult N_API NVirtualDeviceGetDisplayName(HNVirtualDevice hDevice, HNString * phValue);
NResult N_API NVirtualDeviceSetDisplayName(HNVirtualDevice hDevice, HNString hValue);
NResult N_API NVirtualDeviceGetCurrentFormat(HNVirtualDevice hDevice, HNMediaFormat * phFormat);
NResult N_API NVirtualDeviceSetCurrentFormat(HNVirtualDevice hDevice, HNMediaFormat hFormat);
NResult N_API NVirtualDeviceGetOptions(HNVirtualDevice hDevice, NVirtualDeviceOptions * pValue);
NResult N_API NVirtualDeviceSetOptions(HNVirtualDevice hDevice, NVirtualDeviceOptions value);
NResult N_API NVirtualDeviceGetIsPluggedIn(HNVirtualDevice hDevice, NBool * pValue);
NResult N_API NVirtualDeviceSetIsPluggedIn(HNVirtualDevice hDevice, NBool value);

NResult N_API NVirtualDeviceGetSupportedImpressionTypeCount(HNVirtualDevice hDevice, NInt * pValue);
NResult N_API NVirtualDeviceGetSupportedImpressionType(HNVirtualDevice hDevice, NInt index, NFImpressionType * pValue);
N_DEPRECATED("function is deprecated, use NVirtualDeviceGetSupportedImpressionTypesEx instead")
NResult N_API NVirtualDeviceGetSupportedImpressionTypes(HNVirtualDevice hDevice, NFImpressionType * arValue, NInt valueLength);
NResult N_API NVirtualDeviceGetSupportedImpressionTypesEx(HNVirtualDevice hDevice, NFImpressionType * * parValues, NInt * pValueCount);
NResult N_API NVirtualDeviceAddSupportedImpressionType(HNVirtualDevice hDevice, NFImpressionType value, NInt * pIndex);
NResult N_API NVirtualDeviceSetSupportedImpressionType(HNVirtualDevice hDevice, NInt index, NFImpressionType value);
NResult N_API NVirtualDeviceInsertSupportedImpressionType(HNVirtualDevice hDevice, NInt index, NFImpressionType value);
N_DEPRECATED("function is deprecated, use NVirtualDeviceRemoveSupportedImpressionTypeAt instead")
NResult N_API NVirtualDeviceRemoveSupportedImpressionType(HNVirtualDevice hDevice, NInt index);
NResult N_API NVirtualDeviceRemoveSupportedImpressionTypeAt(HNVirtualDevice hDevice, NInt index);
NResult N_API NVirtualDeviceClearSupportedImpressionTypes(HNVirtualDevice hDevice);

NResult N_API NVirtualDeviceGetSupportedFingerPositionCount(HNVirtualDevice hDevice, NInt * pValue);
NResult N_API NVirtualDeviceGetSupportedFingerPosition(HNVirtualDevice hDevice, NInt index, NFPosition * pValue);
N_DEPRECATED("function is deprecated, use NVirtualDeviceGetSupportedFingerPositionsEx instead")
NResult N_API NVirtualDeviceGetSupportedFingerPositions(HNVirtualDevice hDevice, NFPosition * arValue, NInt valueLength);
NResult N_API NVirtualDeviceGetSupportedFingerPositionsEx(HNVirtualDevice hDevice, NFPosition * * parValues, NInt * pValueCount);
NResult N_API NVirtualDeviceAddSupportedFingerPosition(HNVirtualDevice hDevice, NFPosition value, NInt * pIndex);
NResult N_API NVirtualDeviceSetSupportedFingerPosition(HNVirtualDevice hDevice, NInt index, NFPosition value);
NResult N_API NVirtualDeviceInsertSupportedFingerPosition(HNVirtualDevice hDevice, NInt index, NFPosition value);
N_DEPRECATED("function is deprecated, use NVirtualDeviceRemoveSupportedFingerPositionAt instead")
NResult N_API NVirtualDeviceRemoveSupportedFingerPosition(HNVirtualDevice hDevice, NInt index);
NResult N_API NVirtualDeviceRemoveSupportedFingerPositionAt(HNVirtualDevice hDevice, NInt index);
NResult N_API NVirtualDeviceClearSupportedFingerPositions(HNVirtualDevice hDevice);

NResult N_API NVirtualDeviceGetSupportedIrisPositionCount(HNVirtualDevice hDevice, NInt * pValue);
NResult N_API NVirtualDeviceGetSupportedIrisPosition(HNVirtualDevice hDevice, NInt index, NEPosition * pValue);
N_DEPRECATED("function is deprecated, use NVirtualDeviceGetSupportedIrisPositionsEx instead")
NResult N_API NVirtualDeviceGetSupportedIrisPositions(HNVirtualDevice hDevice, NEPosition * arValue, NInt valueLength);
NResult N_API NVirtualDeviceGetSupportedIrisPositionsEx(HNVirtualDevice hDevice, NEPosition * * parValues, NInt * pValueCount);
NResult N_API NVirtualDeviceAddSupportedIrisPosition(HNVirtualDevice hDevice, NEPosition value, NInt * pIndex);
NResult N_API NVirtualDeviceSetSupportedIrisPosition(HNVirtualDevice hDevice, NInt index, NEPosition value);
N_DEPRECATED("function is deprecated, use NVirtualDeviceRemoveSupportedIrisPositionAt instead")
NResult N_API NVirtualDeviceRemoveSupportedIrisPosition(HNVirtualDevice hDevice, NInt index);
NResult N_API NVirtualDeviceRemoveSupportedIrisPositionAt(HNVirtualDevice hDevice, NInt index);
NResult N_API NVirtualDeviceInsertSupportedIrisPosition(HNVirtualDevice hDevice, NInt index, NEPosition value);
NResult N_API NVirtualDeviceClearSupportedIrisPositions(HNVirtualDevice hDevice);

NResult N_API NVirtualDeviceGetVideoFormatCount(HNVirtualDevice hDevice, NInt * pValue);
NResult N_API NVirtualDeviceGetVideoFormat(HNVirtualDevice hDevice, NInt index, HNVideoFormat * phFormat);
NResult N_API NVirtualDeviceAddVideoFormat(HNVirtualDevice hDevice, HNVideoFormat hFormat, NInt * pIndex);
NResult N_API NVirtualDeviceSetVideoFormat(HNVirtualDevice hDevice, NInt index, HNVideoFormat hFormat);
NResult N_API NVirtualDeviceInsertVideoFormat(HNVirtualDevice hDevice, NInt index, HNVideoFormat hFormat);
N_DEPRECATED("function is deprecated, use NVirtualDeviceRemoveVideoFormatAt instead")
NResult N_API NVirtualDeviceRemoveVideoFormat(HNVirtualDevice hDevice, NInt index);
NResult N_API NVirtualDeviceRemoveVideoFormatAt(HNVirtualDevice hDevice, NInt index);
NResult N_API NVirtualDeviceClearVideoFormats(HNVirtualDevice hDevice);

NResult N_API NVirtualDeviceGetAudioFormatCount(HNVirtualDevice hDevice, NInt * pValue);
NResult N_API NVirtualDeviceGetAudioFormat(HNVirtualDevice hDevice, NInt index, HNAudioFormat * phFormat);
NResult N_API NVirtualDeviceAddAudioFormat(HNVirtualDevice hDevice, HNAudioFormat hFormat, NInt * pIndex);
NResult N_API NVirtualDeviceSetAudioFormat(HNVirtualDevice hDevice, NInt index, HNAudioFormat hFormat);
NResult N_API NVirtualDeviceInsertAudioFormat(HNVirtualDevice hDevice, NInt index, HNAudioFormat hFormat);
N_DEPRECATED("function is deprecated, use NVirtualDeviceRemoveAudioFormatAt instead")
NResult N_API NVirtualDeviceRemoveAudioFormat(HNVirtualDevice hDevice, NInt index);
NResult N_API NVirtualDeviceRemoveAudioFormatAt(HNVirtualDevice hDevice, NInt index);
NResult N_API NVirtualDeviceClearAudioFormats(HNVirtualDevice hDevice);

NResult N_API NVirtualDeviceGetSourceCount(HNVirtualDevice hDevice, NInt * pValue);
NResult N_API NVirtualDeviceGetSource(HNVirtualDevice hDevice, NInt index, HNString * phValue);

NResult N_API NVirtualDeviceSetSourceN(HNVirtualDevice hDevice, NInt index, HNString hValue);
#ifndef N_NO_ANSI_FUNC
NResult N_API NVirtualDeviceSetSourceA(HNVirtualDevice hDevice, NInt index, const NAChar * szValue);
#endif
#ifndef N_NO_UNICODE
NResult N_API NVirtualDeviceSetSourceW(HNVirtualDevice hDevice, NInt index, const NWChar * szValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NVirtualDeviceSetSource(HNVirtualDevice hDevice, NInt index, const NChar * szValue);
#endif
#define NVirtualDeviceSetSource N_FUNC_AW(NVirtualDeviceSetSource)

NResult N_API NVirtualDeviceAddSourceN(HNVirtualDevice hDevice, HNString hValue, NInt * pIndex);
#ifndef N_NO_ANSI_FUNC
NResult N_API NVirtualDeviceAddSourceA(HNVirtualDevice hDevice, const NAChar * szValue, NInt * pIndex);
#endif
#ifndef N_NO_UNICODE
NResult N_API NVirtualDeviceAddSourceW(HNVirtualDevice hDevice, const NWChar * szValue, NInt * pIndex);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NVirtualDeviceAddSource(HNVirtualDevice hDevice, const NChar * szValue, NInt * pIndex);
#endif
#define NVirtualDeviceAddSource N_FUNC_AW(NVirtualDeviceAddSource)

NResult N_API NVirtualDeviceInsertSourceN(HNVirtualDevice hDevice, NInt index, HNString hValue);
#ifndef N_NO_ANSI_FUNC
NResult N_API NVirtualDeviceInsertSourceA(HNVirtualDevice hDevice, NInt index, const NAChar * szValue);
#endif
#ifndef N_NO_UNICODE
NResult N_API NVirtualDeviceInsertSourceW(HNVirtualDevice hDevice, NInt index, const NWChar * szValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NVirtualDeviceInsertSource(HNVirtualDevice hDevice, NInt index, const NChar * szValue);
#endif
#define NVirtualDeviceInsertSource N_FUNC_AW(NVirtualDeviceInsertSource)

N_DEPRECATED("function is deprecated, use NVirtualDeviceRemoveSourceAt instead")
NResult N_API NVirtualDeviceRemoveSource(HNVirtualDevice hDevice, NInt index);
NResult N_API NVirtualDeviceRemoveSourceAt(HNVirtualDevice hDevice, NInt index);
NResult N_API NVirtualDeviceClearSources(HNVirtualDevice hDevice);

#ifdef N_CPP
}
#endif

#endif
