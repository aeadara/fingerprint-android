#include <Reflection/NMemberInfo.h>
#include <Reflection/NMethodInfo.h>
#include <Core/NValue.h>

#ifndef N_PROPERTY_INFO_H_INCLUDED
#define N_PROPERTY_INFO_H_INCLUDED

#ifdef N_CPP
extern "C"
{
#endif

NResult N_API NPropertyInfoGetPropertyType(HNPropertyInfo hPropertyInfo, HNType * phValue);
NResult N_API NPropertyInfoGetFormat(HNPropertyInfo hPropertyInfo, HNString * phValue);
NResult N_API NPropertyInfoGetDefaultValue(HNPropertyInfo hPropertyInfo, HNValue * phValue);
NResult N_API NPropertyInfoGetMinValue(HNPropertyInfo hPropertyInfo, HNValue * phValue);
NResult N_API NPropertyInfoGetMaxValue(HNPropertyInfo hPropertyInfo, HNValue * phValue);
NResult N_API NPropertyInfoGetStdValueCount(HNPropertyInfo hPropertyInfo, NInt * pValue);
NResult N_API NPropertyInfoGetStdValue(HNPropertyInfo hPropertyInfo, NInt index, struct NNameValuePair_ * pValue);
NResult N_API NPropertyInfoGetStdValues(HNPropertyInfo hPropertyInfo, struct NNameValuePair_ * * parValues, NInt * pValueCount);
NResult N_API NPropertyInfoGetGetMethod(HNPropertyInfo hPropertyInfo, HNMethodInfo * phValue);
NResult N_API NPropertyInfoGetSetMethod(HNPropertyInfo hPropertyInfo, HNMethodInfo * phValue);
NResult N_API NPropertyInfoGetValueN(HNPropertyInfo hPropertyInfo, HNObject hObject, HNValue * phValue);
NResult N_API NPropertyInfoGetValue(HNPropertyInfo hPropertyInfo, HNObject hObject, HNType hValueType, NAttributes attributes, void * arValues, NSizeType valuesSize, NInt valuesLength, NBool * pHasValue);
NResult N_API NPropertyInfoGetValueP(HNPropertyInfo hPropertyInfo, HNObject hObject, NTypeOfProc pValueTypeOf, NAttributes attributes, void * arValues, NSizeType valuesSize, NInt valuesLength, NBool * pHasValue);
NResult N_API NPropertyInfoSetValueN(HNPropertyInfo hPropertyInfo, HNObject hObject, HNValue hValue);
NResult N_API NPropertyInfoSetValue(HNPropertyInfo hPropertyInfo, HNObject hObject, HNType hValueType, NAttributes attributes, const void * arValues, NSizeType valuesSize, NInt valuesLength, NBool hasValue);
NResult N_API NPropertyInfoSetValueP(HNPropertyInfo hPropertyInfo, HNObject hObject, NTypeOfProc pValueTypeOf, NAttributes attributes, const void * arValues, NSizeType valuesSize, NInt valuesLength, NBool hasValue);
NResult N_API NPropertyInfoCanResetValue(HNPropertyInfo hPropertyInfo, NBool * pValue);
NResult N_API NPropertyInfoResetValue(HNPropertyInfo hPropertyInfo, HNObject hObject);

#ifdef N_CPP
}
#endif

#endif // !N_PROPERTY_INFO_H_INCLUDED
