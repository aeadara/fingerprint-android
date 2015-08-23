#include <ComponentModel/NCustomPropertyDescriptor.h>
#include <Devices/NDevice.h>

#ifndef N_DEVICE_PROPERTY_DESCRIPTOR_H_INCLUDED
#define N_DEVICE_PROPERTY_DESCRIPTOR_H_INCLUDED

#ifdef N_CPP
extern "C"
{
#endif

N_DECLARE_OBJECT_TYPE(NDevicePropertyDescriptor, NCustomPropertyDescriptor)

typedef NResult (N_CALLBACK NDevicePropertyDescriptorGetValueProc)(HNDevicePropertyDescriptor hPropertyDescriptor, NHandle hDevice, void * arValues, NSizeType valuesSize, NInt valuesLength, NBool * pHasValue, void * pParam);
typedef NResult (N_CALLBACK NDevicePropertyDescriptorSetValueProc)(HNDevicePropertyDescriptor hPropertyDescriptor, NHandle hDevice, const void * arValues, NSizeType valuesSize, NInt valuesLength, NBool hasValue, void * pDeviceParam, void * pParam);
typedef NResult (N_CALLBACK NDevicePropertyDescriptorResetValueProc)(HNDevicePropertyDescriptor hPropertyDescriptor, NHandle hDevice, void * pDeviceParam, void * pParam);

NResult N_API NDevicePropertyDescriptorCreate(HNString hName, HNType hPropertyType, NAttributes attributes, HNString hFormat, HNValue hDefaultValue, HNValue hMinValue, HNValue hMaxValue,
	const struct NNameValuePair_ * arStdValues, NInt stdValueCount, HNValue hData, HNCallback hGetValue, HNCallback hSetValue, HNCallback hResetValue, HNDevicePropertyDescriptor * phPropertyDescriptor);

#ifdef N_CPP
}
#endif

#endif // !N_DEVICE_PROPERTY_DESCRIPTOR_H_INCLUDED
