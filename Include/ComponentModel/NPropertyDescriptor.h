#include <ComponentModel/NMemberDescriptor.h>
#include <Core/NValue.h>

#ifndef N_PROPERTY_DESCRIPTOR_H_INCLUDED
#define N_PROPERTY_DESCRIPTOR_H_INCLUDED

#ifdef N_CPP
extern "C"
{
#endif

N_DECLARE_OBJECT_TYPE(NPropertyDescriptor, NMemberDescriptor)

NResult N_API NPropertyDescriptorGetPropertyType(HNPropertyDescriptor hPropertyDescriptor, HNType * phValue);
NResult N_API NPropertyDescriptorGetFormat(HNPropertyDescriptor hPropertyDescriptor, HNString * phValue);
NResult N_API NPropertyDescriptorGetDefaultValue(HNPropertyDescriptor hPropertyDescriptor, HNValue * phValue);
NResult N_API NPropertyDescriptorGetMinValue(HNPropertyDescriptor hPropertyDescriptor, HNValue * phValue);
NResult N_API NPropertyDescriptorGetMaxValue(HNPropertyDescriptor hPropertyDescriptor, HNValue * phValue);
NResult N_API NPropertyDescriptorGetStdValueCount(HNPropertyDescriptor hPropertyDescriptor, NInt * pValue);
NResult N_API NPropertyDescriptorGetStdValue(HNPropertyDescriptor hPropertyDescriptor, NInt index, struct NNameValuePair_ * pValue);
NResult N_API NPropertyDescriptorGetStdValues(HNPropertyDescriptor hPropertyDescriptor, struct NNameValuePair_ * * parValues, NInt * pValueCount);
NResult N_API NPropertyDescriptorGetValueN(HNPropertyDescriptor hPropertyDescriptor, HNObject hComponent, HNValue * phValue);
NResult N_API NPropertyDescriptorGetValue(HNPropertyDescriptor hPropertyDescriptor, HNObject hComponent, HNType hValueType, NAttributes attributes, void * arValues, NSizeType valuesSize, NInt valuesLength, NBool * pHasValue);
NResult N_API NPropertyDescriptorGetValueP(HNPropertyDescriptor hPropertyDescriptor, HNObject hComponent, NTypeOfProc pValueTypeOf, NAttributes attributes, void * arValues, NSizeType valuesSize, NInt valuesLength, NBool * pHasValue);
NResult N_API NPropertyDescriptorSetValueN(HNPropertyDescriptor hPropertyDescriptor, HNObject hComponent, HNValue hValue);
NResult N_API NPropertyDescriptorSetValue(HNPropertyDescriptor hPropertyDescriptor, HNObject hComponent, HNType hValueType, NAttributes attributes, const void * arValues, NSizeType valuesSize, NInt valuesLength, NBool hasValue);
NResult N_API NPropertyDescriptorSetValueP(HNPropertyDescriptor hPropertyDescriptor, HNObject hComponent, NTypeOfProc pValueTypeOf, NAttributes attributes, const void * arValues, NSizeType valuesSize, NInt valuesLength, NBool hasValue);
NResult N_API NPropertyDescriptorCanResetValue(HNPropertyDescriptor hPropertyDescriptor, HNObject hComponent, NBool * pValue);
NResult N_API NPropertyDescriptorResetValue(HNPropertyDescriptor hPropertyDescriptor, HNObject hComponent);
NResult N_API NPropertyDescriptorAddValueChanged(HNPropertyDescriptor hPropertyDescriptor, HNObject hComponent, HNCallback hCallback);
NResult N_API NPropertyDescriptorAddValueChangedCallback(HNPropertyDescriptor hPropertyDescriptor, HNObject hComponent, NObjectCallback pCallback, void * pParam);
NResult N_API NPropertyDescriptorRemoveValueChanged(HNPropertyDescriptor hPropertyDescriptor, HNObject hComponent, HNCallback hCallback);
NResult N_API NPropertyDescriptorRemoveValueChangedCallback(HNPropertyDescriptor hPropertyDescriptor, HNObject hComponent, NObjectCallback pCallback, void * pParam);

#ifdef N_CPP
}
#endif

#endif // !N_PROPERTY_DESCRIPTOR_H_INCLUDED
