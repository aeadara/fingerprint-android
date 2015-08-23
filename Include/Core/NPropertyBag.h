#include <Core/NValue.h>
#include <Collections/NCollection.h>

#ifndef N_PROPERTY_BAG_H_INCLUDED
#define N_PROPERTY_BAG_H_INCLUDED

#ifdef N_CPP
extern "C"
{
#endif

NResult N_API NPropertyBagCreate(HNPropertyBag * phPropertyBag);
NResult N_API NPropertyBagGetCount(HNPropertyBag hPropertyBag, NInt * pValue);
NResult N_API NPropertyBagGetAt(HNPropertyBag hPropertyBag, NInt index, struct NNameValuePair_ * pValue);
NResult N_API NPropertyBagToArray(HNPropertyBag hPropertyBag, struct NNameValuePair_ * * parValues, NInt * pValueCount);
NResult N_API NPropertyBagGetKey(HNPropertyBag hPropertyBag, NInt index, HNString * phValue);
NResult N_API NPropertyBagGetKeys(HNPropertyBag hPropertyBag, HNString * * parhValues, NInt * pValueCount);
NResult N_API NPropertyBagGetValue(HNPropertyBag hPropertyBag, NInt index, HNValue * phValue);
NResult N_API NPropertyBagGetValues(HNPropertyBag hPropertyBag, HNValue * * parhValues, NInt * pValueCount);
NResult N_API NPropertyBagAddPair(HNPropertyBag hPropertyBag, const struct NNameValuePair_ * pValue);
NResult N_API NPropertyBagRemoveAt(HNPropertyBag hPropertyBag, NInt index);
NResult N_API NPropertyBagClear(HNPropertyBag hPropertyBag);

NResult N_API NPropertyBagContainsN(HNPropertyBag hPropertyBag, HNString hKey, NBool * pResult);
#ifndef N_NO_ANSI_FUNC
NResult N_API NPropertyBagContainsA(HNPropertyBag hPropertyBag, const NAChar * szKey, NBool * pResult);
#endif
#ifndef N_NO_UNICODE
NResult N_API NPropertyBagContainsW(HNPropertyBag hPropertyBag, const NWChar * szKey, NBool * pResult);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NPropertyBagContains(HNPropertyBag hPropertyBag, const NChar * szKey, NBool * pResult);
#endif
#define NPropertyBagContains N_FUNC_AW(NPropertyBagContains)

NResult N_API NPropertyBagGetN(HNPropertyBag hPropertyBag, HNString hKey, HNValue * phValue);
#ifndef N_NO_ANSI_FUNC
NResult N_API NPropertyBagGetA(HNPropertyBag hPropertyBag, const NAChar * szKey, HNValue * phValue);
#endif
#ifndef N_NO_UNICODE
NResult N_API NPropertyBagGetW(HNPropertyBag hPropertyBag, const NWChar * szKey, HNValue * phValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NPropertyBagGet(HNPropertyBag hPropertyBag, const NChar * szKey, HNValue * phValue);
#endif
#define NPropertyBagGet N_FUNC_AW(NPropertyBagGet)

NResult N_API NPropertyBagTryGetN(HNPropertyBag hPropertyBag, HNString hKey, HNValue * phValue, NBool * pResult);
#ifndef N_NO_ANSI_FUNC
NResult N_API NPropertyBagTryGetA(HNPropertyBag hPropertyBag, const NAChar * szKey, HNValue * phValue, NBool * pResult);
#endif
#ifndef N_NO_UNICODE
NResult N_API NPropertyBagTryGetW(HNPropertyBag hPropertyBag, const NWChar * szKey, HNValue * phValue, NBool * pResult);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NPropertyBagTryGet(HNPropertyBag hPropertyBag, const NChar * szKey, HNValue * phValue, NBool * pResult);
#endif
#define NPropertyBagTryGet N_FUNC_AW(NPropertyBagTryGet)

NResult N_API NPropertyBagAddN(HNPropertyBag hPropertyBag, HNString hKey, HNValue hValue);
#ifndef N_NO_ANSI_FUNC
NResult N_API NPropertyBagAddA(HNPropertyBag hPropertyBag, const NAChar * szKey, HNValue hValue);
#endif
#ifndef N_NO_UNICODE
NResult N_API NPropertyBagAddW(HNPropertyBag hPropertyBag, const NWChar * szKey, HNValue hValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NPropertyBagAdd(HNPropertyBag hPropertyBag, const NChar * szKey, HNValue hValue);
#endif
#define NPropertyBagAdd N_FUNC_AW(NPropertyBagAdd)

NResult N_API NPropertyBagSetN(HNPropertyBag hPropertyBag, HNString hKey, HNValue hValue);
#ifndef N_NO_ANSI_FUNC
NResult N_API NPropertyBagSetA(HNPropertyBag hPropertyBag, const NAChar * szKey, HNValue hValue);
#endif
#ifndef N_NO_UNICODE
NResult N_API NPropertyBagSetW(HNPropertyBag hPropertyBag, const NWChar * szKey, HNValue hValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NPropertyBagSet(HNPropertyBag hPropertyBag, const NChar * szKey, HNValue hValue);
#endif
#define NPropertyBagSet N_FUNC_AW(NPropertyBagSet)

NResult N_API NPropertyBagRemoveN(HNPropertyBag hPropertyBag, HNString hKey, NBool * pResult);
#ifndef N_NO_ANSI_FUNC
NResult N_API NPropertyBagRemoveA(HNPropertyBag hPropertyBag, const NAChar * szKey, NBool * pResult);
#endif
#ifndef N_NO_UNICODE
NResult N_API NPropertyBagRemoveW(HNPropertyBag hPropertyBag, const NWChar * szKey, NBool * pResult);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NPropertyBagRemove(HNPropertyBag hPropertyBag, const NChar * szKey, NBool * pResult);
#endif
#define NPropertyBagRemove N_FUNC_AW(NPropertyBagRemove)

NResult N_API NPropertyBagCopyTo(HNPropertyBag hPropertyBag, HNPropertyBag hOtherPropertyBag);
NResult N_API NPropertyBagApplyTo(HNPropertyBag hPropertyBag, HNObject hObject);

NResult N_API NPropertyBagTryParseN(HNString hValue, HNString hFormat, HNPropertyBag * phPropertyBag, NBool * pResult);

#ifndef N_NO_ANSI_FUNC
NResult N_API NPropertyBagTryParseVNA(HNString hValue, const NAChar * szFormat, HNPropertyBag * phPropertyBag, NBool * pResult);
#endif
#ifndef N_NO_UNICODE
NResult N_API NPropertyBagTryParseVNW(HNString hValue, const NWChar * szFormat, HNPropertyBag * phPropertyBag, NBool * pResult);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NPropertyBagTryParseVN(HNString hValue, const NChar * szFormat, HNPropertyBag * phPropertyBag, NBool * pResult);
#endif
#define NPropertyBagTryParseVN N_FUNC_AW(NPropertyBagTryParseVN)

#ifndef N_NO_ANSI_FUNC
NResult N_API NPropertyBagTryParseA(const NAChar * szValue, const NAChar * szFormat, HNPropertyBag * phPropertyBag, NBool * pResult);
#endif
#ifndef N_NO_UNICODE
NResult N_API NPropertyBagTryParseW(const NWChar * szValue, const NWChar * szFormat, HNPropertyBag * phPropertyBag, NBool * pResult);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NPropertyBagTryParse(const NChar * szValue, const NChar * szFormat, HNPropertyBag * phPropertyBag, NBool * pResult);
#endif
#define NPropertyBagTryParse N_FUNC_AW(NPropertyBagTryParse)

NResult N_API NPropertyBagParseN(HNString hValue, HNString hFormat, HNPropertyBag * phPropertyBag);

#ifndef N_NO_ANSI_FUNC
NResult N_API NPropertyBagParseVNA(HNString hValue, const NAChar * szFormat, HNPropertyBag * phPropertyBag);
#endif
#ifndef N_NO_UNICODE
NResult N_API NPropertyBagParseVNW(HNString hValue, const NWChar * szFormat, HNPropertyBag * phPropertyBag);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NPropertyBagParseVN(HNString hValue, const NChar * szFormat, HNPropertyBag * phPropertyBag);
#endif
#define NPropertyBagParseVN N_FUNC_AW(NPropertyBagParseVN)

#ifndef N_NO_ANSI_FUNC
NResult N_API NPropertyBagParseA(const NAChar * szValue, const NAChar * szFormat, HNPropertyBag * phPropertyBag);
#endif
#ifndef N_NO_UNICODE
NResult N_API NPropertyBagParseW(const NWChar * szValue, const NWChar * szFormat, HNPropertyBag * phPropertyBag);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NPropertyBagParse(const NChar * szValue, const NChar * szFormat, HNPropertyBag * phPropertyBag);
#endif
#define NPropertyBagParse N_FUNC_AW(NPropertyBagParse)

NResult N_API NPropertyBagAddCollectionChanged(HNPropertyBag hPropertyBag, HNCallback hCallback);
NResult N_API NPropertyBagAddCollectionChangedCallback(HNPropertyBag hPropertyBag, N_COLLECTION_CHANGED_CALLBACK_ARG(struct NNameValuePair_, pCallback), void * pParam);
NResult N_API NPropertyBagRemoveCollectionChanged(HNPropertyBag hPropertyBag, HNCallback hCallback);
NResult N_API NPropertyBagRemoveCollectionChangedCallback(HNPropertyBag hPropertyBag, N_COLLECTION_CHANGED_CALLBACK_ARG(struct NNameValuePair_, pCallback), void * pParam);

#ifdef N_CPP
}
#endif

#endif // !N_PROPERTY_BAG_H_INCLUDED
