#include <ComponentModel/NDescriptor.h>

#ifndef N_PARAMETER_DESCRIPTOR_H_INCLUDED
#define N_PARAMETER_DESCRIPTOR_H_INCLUDED

#ifdef N_CPP
extern "C"
{
#endif

N_DECLARE_OBJECT_TYPE(NParameterDescriptor, NDescriptor)

NResult N_API NParameterDescriptorGetParameterType(HNParameterDescriptor hParameterDescriptor, HNType * phValue);
NResult N_API NParameterDescriptorGetFormat(HNParameterDescriptor hParameterDescriptor, HNString * phValue);
NResult N_API NParameterDescriptorGetDefaultValue(HNParameterDescriptor hParameterDescriptor, HNValue * phValue);
NResult N_API NParameterDescriptorGetMinValue(HNParameterDescriptor hParameterDescriptor, HNValue * phValue);
NResult N_API NParameterDescriptorGetMaxValue(HNParameterDescriptor hParameterDescriptor, HNValue * phValue);
NResult N_API NParameterDescriptorGetStdValueCount(HNParameterDescriptor hParameterDescriptor, NInt * pValue);
NResult N_API NParameterDescriptorGetStdValue(HNParameterDescriptor hParameterDescriptor, NInt index, struct NNameValuePair_ * pValue);
NResult N_API NParameterDescriptorGetStdValues(HNParameterDescriptor hParameterDescriptor, struct NNameValuePair_ * * parValues, NInt * pValueCount);

#ifdef N_CPP
}
#endif

#endif // !N_PARAMETER_DESCRIPTOR_H_INCLUDED
