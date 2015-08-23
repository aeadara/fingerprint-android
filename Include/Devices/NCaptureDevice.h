#include <Devices/NDevice.h>

#ifndef N_CAPTURE_DEVICE_H_INCLUDED
#define N_CAPTURE_DEVICE_H_INCLUDED

#include <Media/NMediaFormat.h>

#ifdef N_CPP
extern "C"
{
#endif

N_DECLARE_OBJECT_TYPE(NCaptureDevice, NDevice)

NResult N_API NCaptureDeviceStartCapturing(HNCaptureDevice hDevice);
NResult N_API NCaptureDeviceStopCapturing(HNCaptureDevice hDevice);
NResult N_API NCaptureDeviceGetFormats(HNCaptureDevice hDevice, HNMediaFormat * * parhFormats, NInt * pFormatCount);
NResult N_API NCaptureDeviceGetCurrentFormat(HNCaptureDevice hDevice, HNMediaFormat * phFormat);
NResult N_API NCaptureDeviceSetCurrentFormat(HNCaptureDevice hDevice, HNMediaFormat hFormat);

NResult N_API NCaptureDeviceIsCapturing(HNCaptureDevice hDevice, NBool * pValue);
NResult N_API NCaptureDeviceGetMediaType(HNCaptureDevice hDevice, NMediaType * pValue);

NResult N_API NCaptureDeviceAddIsCapturingChanged(HNCaptureDevice hDevice, HNCallback hCallback);
NResult N_API NCaptureDeviceAddIsCapturingChangedCallback(HNCaptureDevice hDevice, NObjectCallback pCallback, void * pParam);
NResult N_API NCaptureDeviceRemoveIsCapturingChanged(HNCaptureDevice hDevice, HNCallback hCallback);
NResult N_API NCaptureDeviceRemoveIsCapturingChangedCallback(HNCaptureDevice hDevice, NObjectCallback pCallback, void * pParam);

#ifdef N_CPP
}
#endif

#endif // !N_CAPTURE_DEVICE_H_INCLUDED
