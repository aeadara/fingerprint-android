#ifndef N_PARAMETER_BAG_H_INCLUDED
#define N_PARAMETER_BAG_H_INCLUDED

#include <ComponentModel/NParameterDescriptor.h>
#include <Core/NPropertyBag.h>

#ifdef N_CPP
extern "C"
{
#endif

N_DECLARE_OBJECT_TYPE(NParameterBag, NObject)

NResult N_API NParameterBagCreate(const HNParameterDescriptor * arhParameters, NInt parameterCount, HNParameterBag * phParameterBag);
NResult N_API NParameterBagGetCount(HNParameterBag hParameterBag, NInt * pValue);
NResult N_API NParameterBagGetAt(HNParameterBag hParameterBag, NInt index, struct NNameValuePair_ * pValue);
NResult N_API NParameterBagToArray(HNParameterBag hParameterBag, struct NNameValuePair_ * * parValues, NInt * pValueCount);
NResult N_API NParameterBagGetKey(HNParameterBag hParameterBag, NInt index, HNString * phValue);
NResult N_API NParameterBagGetKeys(HNParameterBag hParameterBag, HNString * * parhValues, NInt * pValueCount);
NResult N_API NParameterBagGetValue(HNParameterBag hParameterBag, NInt index, HNValue * phValue);
NResult N_API NParameterBagGetValues(HNParameterBag hParameterBag, HNValue * * parhValues, NInt * pValueCount);
NResult N_API NParameterBagSetValue(HNParameterBag hParameterBag, NInt index, HNValue hValue);

NResult N_API NParameterBagContainsN(HNParameterBag hParameterBag, HNString hKey, NBool * pResult);
#ifndef N_NO_ANSI_FUNC
NResult N_API NParameterBagContainsA(HNParameterBag hParameterBag, const NAChar * szKey, NBool * pResult);
#endif
#ifndef N_NO_UNICODE
NResult N_API NParameterBagContainsW(HNParameterBag hParameterBag, const NWChar * szKey, NBool * pResult);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NParameterBagContains(HNParameterBag hParameterBag, const NChar * szKey, NBool * pResult);
#endif
#define NParameterBagContains N_FUNC_AW(NParameterBagContains)

NResult N_API NParameterBagGetN(HNParameterBag hParameterBag, HNString hKey, HNValue * phValue);
#ifndef N_NO_ANSI_FUNC
NResult N_API NParameterBagGetA(HNParameterBag hParameterBag, const NAChar * szKey, HNValue * phValue);
#endif
#ifndef N_NO_UNICODE
NResult N_API NParameterBagGetW(HNParameterBag hParameterBag, const NWChar * szKey, HNValue * phValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NParameterBagGet(HNParameterBag hParameterBag, const NChar * szKey, HNValue * phValue);
#endif
#define NParameterBagGet N_FUNC_AW(NParameterBagGet)

NResult N_API NParameterBagTryGetN(HNParameterBag hParameterBag, HNString hKey, HNValue * phValue, NBool * pResult);
#ifndef N_NO_ANSI_FUNC
NResult N_API NParameterBagTryGetA(HNParameterBag hParameterBag, const NAChar * szKey, HNValue * phValue, NBool * pResult);
#endif
#ifndef N_NO_UNICODE
NResult N_API NParameterBagTryGetW(HNParameterBag hParameterBag, const NWChar * szKey, HNValue * phValue, NBool * pResult);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NParameterBagTryGet(HNParameterBag hParameterBag, const NChar * szKey, HNValue * phValue, NBool * pResult);
#endif
#define NParameterBagTryGet N_FUNC_AW(NParameterBagTryGet)

NResult N_API NParameterBagSetN(HNParameterBag hParameterBag, HNString hKey, HNValue hValue);
#ifndef N_NO_ANSI_FUNC
NResult N_API NParameterBagSetA(HNParameterBag hParameterBag, const NAChar * szKey, HNValue hValue);
#endif
#ifndef N_NO_UNICODE
NResult N_API NParameterBagSetW(HNParameterBag hParameterBag, const NWChar * szKey, HNValue hValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NParameterBagSet(HNParameterBag hParameterBag, const NChar * szKey, HNValue hValue);
#endif
#define NParameterBagSet N_FUNC_AW(NParameterBag)

NResult N_API NParameterBagApplyPropertyBag(HNParameterBag hParameterBag, HNPropertyBag hValue, NBool ignoreUknown);
NResult N_API NParameterBagToPropertyBag(HNParameterBag hParameterBag, HNPropertyBag * phValue);

#ifdef N_CPP
}
#endif

#endif // !N_PARAMETER_BAG_H_INCLUDED
