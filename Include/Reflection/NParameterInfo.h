#include <Core/NValue.h>

#ifndef N_PARAMETER_INFO_H_INCLUDED
#define N_PARAMETER_INFO_H_INCLUDED

#ifdef N_CPP
extern "C"
{
#endif

NResult N_API NParameterInfoGetName(HNParameterInfo hParameterInfo, HNString * phValue);
NResult N_API NParameterInfoGetParameterType(HNParameterInfo hParameterInfo, HNType * phValue);
NResult N_API NParameterInfoGetAttributes(HNParameterInfo hParameterInfo, NAttributes * pValue);
NResult N_API NParameterInfoGetFormat(HNParameterInfo hParameterInfo, HNString * phValue);
NResult N_API NParameterInfoGetDefaultValue(HNParameterInfo hParameterInfo, HNValue * phValue);
NResult N_API NParameterInfoGetMinValue(HNParameterInfo hParameterInfo, HNValue * phValue);
NResult N_API NParameterInfoGetMaxValue(HNParameterInfo hParameterInfo, HNValue * phValue);
NResult N_API NParameterInfoGetStdValueCount(HNParameterInfo hParameterInfo, NInt * pValue);
NResult N_API NParameterInfoGetStdValue(HNParameterInfo hParameterInfo, NInt index, struct NNameValuePair_ * pValue);
NResult N_API NParameterInfoGetStdValues(HNParameterInfo hParameterInfo, struct NNameValuePair_ * * parValues, NInt * pValueCount);

#ifdef N_CPP
}
#endif

#endif // !N_PARAMETER_INFO_H_INCLUDED
