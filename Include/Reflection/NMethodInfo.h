#include <Reflection/NMemberInfo.h>

#ifndef N_METHOD_INFO_H_INCLUDED
#define N_METHOD_INFO_H_INCLUDED

#include <Reflection/NParameterInfo.h>
#include <Core/NPropertyBag.h>

#ifdef N_CPP
extern "C"
{
#endif

NResult N_API NMethodInfoGetParameterCount(HNMethodInfo hMethodInfo, NInt * pValue);
NResult N_API NMethodInfoGetParameter(HNMethodInfo hMethodInfo, NInt index, HNParameterInfo * phValue);
NResult N_API NMethodInfoGetParameters(HNMethodInfo hMethodInfo, HNParameterInfo * * parhValues, NInt * pValueCount);

NResult N_API NMethodInfoGetNativeName(HNMethodInfo hMethodInfo, HNString * phValue);
NResult N_API NMethodInfoGetReturnParameter(HNMethodInfo hMethodInfo, HNParameterInfo * phValue);

NResult N_API NMethodInfoInvoke(HNMethodInfo hMethodInfo, HNObject hObject, HNValue * arhParameters, NInt parameterCount, HNValue * phResult);
NResult N_API NMethodInfoInvokeWithPropertyBag(HNMethodInfo hMethodInfo, HNObject hObject, HNPropertyBag hParameters, HNValue * phResult);
NResult N_API NMethodInfoInvokeWithStringN(HNMethodInfo hMethodInfo, HNObject hObject, HNString hParameters, HNValue * phResult);
#ifndef N_NO_ANSI_FUNC
NResult N_API NMethodInfoInvokeWithStringA(HNMethodInfo hMethodInfo, HNObject hObject, const NAChar * szParameters, HNValue * phResult);
#endif
#ifndef N_NO_UNICODE
NResult N_API NMethodInfoInvokeWithStringW(HNMethodInfo hMethodInfo, HNObject hObject, const NWChar * szParameters, HNValue * phResult);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NMethodInfoInvokeWithString(HNMethodInfo hMethodInfo, HNObject hObject, const NChar * szParameters, HNValue * phResult);
#endif
#define NMethodInfoInvokeWithString N_FUNC_AW(NMethodInfoInvokeWithString)

#ifdef N_CPP
}
#endif

#endif // !N_METHOD_INFO_H_INCLUDED
