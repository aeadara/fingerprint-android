#include <ComponentModel/NParameterDescriptor.h>

#ifndef N_CUSTOM_PARAMETER_DESCRIPTOR_H_INCLUDED
#define N_CUSTOM_PARAMETER_DESCRIPTOR_H_INCLUDED

#ifdef N_CPP
extern "C"
{
#endif

N_DECLARE_OBJECT_TYPE(NCustomParameterDescriptor, NParameterDescriptor)

NResult N_API NCustomParameterDescriptorCreate(HNString hName, HNType hParameterType, NAttributes attributes, HNString hFormat,
	HNValue hDefaultValue, HNValue hMinValue, HNValue hMaxValue, const struct NNameValuePair_ * arStdValues, NInt stdValueCount, HNValue hData,
	HNCustomParameterDescriptor * phParameterDescriptor);

NResult N_API NCustomParameterDescriptorGetData(HNCustomParameterDescriptor hParameterDescriptor, HNValue * phData);

#ifdef N_CPP
}
#endif

#endif // !N_CUSTOM_PARAMETER_DESCRIPTOR_H_INCLUDED
