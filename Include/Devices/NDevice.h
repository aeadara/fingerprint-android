#ifndef N_DEVICE_H_INCLUDED
#define N_DEVICE_H_INCLUDED

#include <Core/NObject.h>
#include <Plugins/NPlugin.h>

#ifdef N_CPP
extern "C"
{
#endif

typedef enum NDeviceType_
{
	ndtNone = 0,
	ndtCamera = 0x01,
	ndtBiometricDevice = 0x02,
	ndtFScanner = 0x04,
	ndtFingerScanner = 0x08,
	ndtPalmScanner = 0x10,
	ndtIrisScanner = 0x20,
	ndtCaptureDevice = 0x40,
	ndtMicrophone = 0x80,
	ndtAny = 0x80000000
} NDeviceType;

N_DECLARE_TYPE(NDeviceType)

N_DECLARE_OBJECT_TYPE(NDevice, NObject)

NResult N_API NDeviceGetChildCount(HNDevice hDevice, NInt * pValue);
NResult N_API NDeviceGetChild(HNDevice hDevice, NInt index, HNDevice * phValue);
NResult N_API NDeviceGetChildren(HNDevice hDevice, HNDevice * * parhValues, NInt * pValueCount);

NResult N_API NDeviceGetPlugin(HNDevice hDevice, HNPlugin * phValue);
NResult N_API NDeviceGetDeviceType(HNDevice hDevice, NDeviceType * pValue);
NResult N_API NDeviceIsAvailable(HNDevice hDevice, NBool * pValue);
NResult N_API NDeviceIsPrivate(HNDevice hDevice, NBool * pValue);
NResult N_API NDeviceIsDisconnectable(HNDevice hDevice, NBool * pValue);
NResult N_API NDeviceGetParent(HNDevice hDevice, HNDevice * phValue);

NResult N_API NDeviceGetIdN(HNDevice hDevice, HNString * phValue);
#ifdef N_DOCUMENTATION
N_DEPRECATED("function is deprecated, use NDeviceGetIdN instead")
NResult N_API NDeviceGetId(HNDevice hDevice, NChar * szValue, NInt valueSize);
#endif
#ifndef N_NO_ANSI_FUNC
N_DEPRECATED("function is deprecated, use NDeviceGetIdN instead")
NResult N_API NDeviceGetIdA(HNDevice hDevice, NAChar * szValue, NInt valueSize);
#endif
#ifndef N_NO_UNICODE
NResult N_API NDeviceGetIdW(HNDevice hDevice, NWChar * szValue, NInt valueSize);
#endif
#define NDeviceGetId N_FUNC_AW(NDeviceGetId)

NResult N_API NDeviceGetDisplayNameN(HNDevice hDevice, HNString * phValue);
#ifdef N_DOCUMENTATION
N_DEPRECATED("function is deprecated, use NDeviceGetDisplayNameN instead")
NResult N_API NDeviceGetDisplayName(HNDevice hDevice, NChar * szValue, NInt valueSize);
#endif
#ifndef N_NO_ANSI_FUNC
N_DEPRECATED("function is deprecated, use NDeviceGetDisplayNameN instead")
NResult N_API NDeviceGetDisplayNameA(HNDevice hDevice, NAChar * szValue, NInt valueSize);
#endif
#ifndef N_NO_UNICODE
NResult N_API NDeviceGetDisplayNameW(HNDevice hDevice, NWChar * szValue, NInt valueSize);
#endif
#define NDeviceGetDisplayName N_FUNC_AW(NDeviceGetDisplayName)

NResult N_API NDeviceGetMakeN(HNDevice hDevice, HNString * phValue);
#ifdef N_DOCUMENTATION
N_DEPRECATED("function is deprecated, use NDeviceGetMakeN instead")
NResult N_API NDeviceGetMake(HNDevice hDevice, NChar * szValue, NInt valueSize);
#endif
#ifndef N_NO_ANSI_FUNC
N_DEPRECATED("function is deprecated, use NDeviceGetMakeN instead")
NResult N_API NDeviceGetMakeA(HNDevice hDevice, NAChar * szValue, NInt valueSize);
#endif
#ifndef N_NO_UNICODE
NResult N_API NDeviceGetMakeW(HNDevice hDevice, NWChar * szValue, NInt valueSize);
#endif
#define NDeviceGetMake N_FUNC_AW(NDeviceGetMake)

NResult N_API NDeviceGetModelN(HNDevice hDevice, HNString * phValue);
#ifdef N_DOCUMENTATION
N_DEPRECATED("function is deprecated, use NDeviceGetModelN instead")
NResult N_API NDeviceGetModel(HNDevice hDevice, NChar * szValue, NInt valueSize);
#endif
#ifndef N_NO_ANSI_FUNC
N_DEPRECATED("function is deprecated, use NDeviceGetModelN instead")
NResult N_API NDeviceGetModelA(HNDevice hDevice, NAChar * szValue, NInt valueSize);
#endif
#ifndef N_NO_UNICODE
NResult N_API NDeviceGetModelW(HNDevice hDevice, NWChar * szValue, NInt valueSize);
#endif
#define NDeviceGetModel N_FUNC_AW(NDeviceGetModel)

NResult N_API NDeviceGetSerialNumberN(HNDevice hDevice, HNString * phValue);
#ifdef N_DOCUMENTATION
N_DEPRECATED("function is deprecated, use NDeviceGetSerialNumberN instead")
NResult N_API NDeviceGetSerialNumber(HNDevice hDevice, NChar * szValue, NInt valueSize);
#endif
#ifndef N_NO_ANSI_FUNC
N_DEPRECATED("function is deprecated, use NDeviceGetSerialNumberN instead")
NResult N_API NDeviceGetSerialNumberA(HNDevice hDevice, NAChar * szValue, NInt valueSize);
#endif
#ifndef N_NO_UNICODE
NResult N_API NDeviceGetSerialNumberW(HNDevice hDevice, NWChar * szValue, NInt valueSize);
#endif
#define NDeviceGetSerialNumber N_FUNC_AW(NDeviceGetSerialNumber)

#ifdef N_CPP
}
#endif

#endif // !N_DEVICE_H_INCLUDED
