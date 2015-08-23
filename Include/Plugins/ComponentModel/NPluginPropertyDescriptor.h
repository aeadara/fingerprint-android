#include <ComponentModel/NCustomPropertyDescriptor.h>
#include <Plugins/NPlugin.h>

#ifndef N_PLUGIN_PROPERTY_DESCRIPTOR_H_INCLUDED
#define N_PLUGIN_PROPERTY_DESCRIPTOR_H_INCLUDED

#ifdef N_CPP
extern "C"
{
#endif

N_DECLARE_OBJECT_TYPE(NPluginPropertyDescriptor, NCustomPropertyDescriptor)

typedef NResult (N_CALLBACK NPluginPropertyDescriptorGetValueProc)(HNPluginPropertyDescriptor hPropertyDescriptor, void * arValues, NSizeType valuesSize, NInt valuesLength, NBool * pHasValue, void * pParam);
typedef NResult (N_CALLBACK NPluginPropertyDescriptorSetValueProc)(HNPluginPropertyDescriptor hPropertyDescriptor, const void * arValues, NSizeType valuesSize, NInt valuesLength, NBool hasValue, void * pParam);
typedef NResult (N_CALLBACK NPluginPropertyDescriptorResetValueProc)(HNPluginPropertyDescriptor hPropertyDescriptor, void * pParam);

NResult N_API NPluginPropertyDescriptorCreate(HNString hName, HNType hPropertyType, NAttributes attributes, HNString hFormat, HNValue hDefaultValue, HNValue hMinValue, HNValue hMaxValue,
	const struct NNameValuePair_ * arStdValues, NInt stdValueCount, HNValue hData, HNCallback hGetValue, HNCallback hSetValue, HNCallback hResetValue, HNPluginPropertyDescriptor * phPropertyDescriptor);

#ifdef N_CPP
}
#endif

#endif // !N_PLUGIN_PROPERTY_DESCRIPTOR_H_INCLUDED
