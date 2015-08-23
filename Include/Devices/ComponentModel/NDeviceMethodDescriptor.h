#include <ComponentModel/NCustomMethodDescriptor.h>
#include <ComponentModel/NCustomParameterDescriptor.h>
#include <Devices/NDevice.h>

#ifndef N_DEVICE_METHOD_DESCRIPTOR_H_INCLUDED
#define N_DEVICE_METHOD_DESCRIPTOR_H_INCLUDED

#ifdef N_CPP
extern "C"
{
#endif

N_DECLARE_OBJECT_TYPE(NDeviceMethodDescriptor, NCustomMethodDescriptor)

typedef NResult (N_CALLBACK NDeviceMethodDescriptorInvokeProc)(HNDeviceMethodDescriptor hMethodDescriptor, NHandle hDevice, HNValue * arhParameters, NInt parameterCount, HNValue * phResult, void * pDeviceParam, void * pParam);

NResult N_API NDeviceMethodDescriptorCreate(HNString hName, NAttributes attributes, HNCustomParameterDescriptor hReturnParameter, HNCustomParameterDescriptor * arhParameters, NInt parameterCount,
	HNValue hData, HNCallback hInvoke, HNDeviceMethodDescriptor * phMethodDescriptor);

#ifdef N_CPP
}
#endif

#endif // !N_DEVICE_METHOD_DESCRIPTOR_H_INCLUDED
