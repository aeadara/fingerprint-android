#include <Collections/NCollection.h>

#ifndef N_DICTIONARY_H_INCLUDED
#define N_DICTIONARY_H_INCLUDED

#ifdef N_CPP
extern "C"
{
#endif

typedef NResult (N_CALLBACK NDictionaryCollectionChangedCallback)(HNObject hObject, NCollectionChangedAction action, NInt newIndex, struct NKeyValuePair_ * arNewItems, NInt newItemCount,
	NInt oldIndex, struct NKeyValuePair_ * arOldItems, NInt oldItemCount, void * pParam);
N_DECLARE_TYPE(NDictionaryCollectionChangedCallback);

NResult N_API NDictionaryIsReadOnly(HNDictionary hDictionary, NBool * pValue);
NResult N_API NDictionaryGetCount(HNDictionary hDictionary, NInt * pValue);
NResult N_API NDictionaryGetAtN(HNDictionary hDictionary, NInt index, struct NKeyValuePair_ * pItem);
NResult N_API NDictionaryGetItemAt(HNDictionary hDictionary, NInt index, HNValue * phItem);
NResult N_API NDictionaryGetAt(HNDictionary hDictionary, NInt index, HNType hItemType, NAttributes itemAttributes, void * pItem, NSizeType itemSize);
NResult N_API NDictionaryGetAtP(HNDictionary hDictionary, NInt index, NTypeOfProc pItemTypeOf, NAttributes itemAttributes, void * pItem, NSizeType itemSize);
NResult N_API NDictionaryToArrayN(HNDictionary hDictionary, struct NKeyValuePair_ * * parItems, NInt * pItemCount);
NResult N_API NDictionaryToItemArray(HNDictionary hDictionary, HNArray * phItems);
NResult N_API NDictionaryToArray(HNDictionary hDictionary, HNType hItemType, NAttributes itemAttributes, NSizeType itemSize, void * * parItems, NInt * pItemCount);
NResult N_API NDictionaryToArrayP(HNDictionary hDictionary, NTypeOfProc pItemTypeOf, NAttributes itemAttributes, NSizeType itemSize, void * * parItems, NInt * pItemCount);
NResult N_API NDictionaryGetKeyN(HNDictionary hDictionary, NInt index, HNValue * phKey);
NResult N_API NDictionaryGetKey(HNDictionary hDictionary, NInt index, HNType hKeyType, NAttributes keyAttributes, void * pKey, NSizeType keySize);
NResult N_API NDictionaryGetKeyP(HNDictionary hDictionary, NInt index, NTypeOfProc pKeyTypeOf, NAttributes keyAttributes, void * pKey, NSizeType keySize);
NResult N_API NDictionaryGetKeysN(HNDictionary hDictionary, HNValue * * parhKeys, NInt * pKeyCount);
NResult N_API NDictionaryToKeyArray(HNDictionary hDictionary, HNArray * phKeys);
NResult N_API NDictionaryGetKeys(HNDictionary hDictionary, HNType hKeyType, NAttributes keyAttributes, NSizeType keySize, void * * parKeys, NInt * pKeyCount);
NResult N_API NDictionaryGetKeysP(HNDictionary hDictionary, NTypeOfProc pKeyTypeOf, NAttributes keyAttributes, NSizeType keySize, void * * parKeys, NInt * pKeyCount);
NResult N_API NDictionaryGetValueN(HNDictionary hDictionary, NInt index, HNValue * phValue);
NResult N_API NDictionaryGetValue(HNDictionary hDictionary, NInt index, HNType hValueType, NAttributes valueAttributes, void * pValue, NSizeType valueSize);
NResult N_API NDictionaryGetValueP(HNDictionary hDictionary, NInt index, NTypeOfProc pValueTypeOf, NAttributes valueAttributes, void * pValue, NSizeType valueSize);
NResult N_API NDictionaryGetValuesN(HNDictionary hDictionary, HNValue * * parhValues, NInt * pValueCount);
NResult N_API NDictionaryToValueArray(HNDictionary hDictionary, HNArray * phValues);
NResult N_API NDictionaryGetValues(HNDictionary hDictionary, HNType hValueType, NAttributes valueAttributes, NSizeType valueSize, void * * parValues, NInt * pValueCount);
NResult N_API NDictionaryGetValuesP(HNDictionary hDictionary, NTypeOfProc pValueTypeOf, NAttributes valueAttributes, NSizeType valueSize, void * * parValues, NInt * pValueCount);
NResult N_API NDictionaryAddPairN(HNDictionary hDictionary, const struct NKeyValuePair_ * pItem);
NResult N_API NDictionaryAddItemPair(HNDictionary hDictionary, HNValue hItem);
NResult N_API NDictionaryAddPair(HNDictionary hDictionary, HNType hItemType, NAttributes itemAttributes, const void * pItem, NSizeType itemSize);
NResult N_API NDictionaryAddPairP(HNDictionary hDictionary, NTypeOfProc pItemTypeOf, NAttributes itemAttributes, const void * pItem, NSizeType itemSize);
NResult N_API NDictionaryRemoveAt(HNDictionary hDictionary, NInt index);
NResult N_API NDictionaryClear(HNDictionary hDictionary);
NResult N_API NDictionaryContainsN(HNDictionary hDictionary, HNValue hKey, NBool * pResult);
NResult N_API NDictionaryContains(HNDictionary hDictionary, HNType hKeyType, NAttributes keyAttributes, const void * pKey, NSizeType keySize, NBool * pResult);
NResult N_API NDictionaryContainsP(HNDictionary hDictionary, NTypeOfProc pKeyTypeOf, NAttributes keyAttributes, const void * pKey, NSizeType keySize, NBool * pResult);
NResult N_API NDictionaryGetN(HNDictionary hDictionary, HNValue hKey, HNValue * phValue);
NResult N_API NDictionaryGet(HNDictionary hDictionary, HNType hKeyType, NAttributes keyAttributes, const void * pKey, NSizeType keySize, HNType hValueType, NAttributes valueAttributes, void * pValue, NSizeType valueSize);
NResult N_API NDictionaryGetP(HNDictionary hDictionary, NTypeOfProc pKeyTypeOf, NAttributes keyAttributes, const void * pKey, NSizeType keySize, NTypeOfProc pValueTypeOf, NAttributes valueAttributes, void * pValue, NSizeType valueSize);
NResult N_API NDictionaryTryGetN(HNDictionary hDictionary, HNValue hKey, HNValue * phValue, NBool * pResult);
NResult N_API NDictionaryTryGet(HNDictionary hDictionary, HNType hKeyType, NAttributes keyAttributes, const void * pKey, NSizeType keySize, HNType hValueType, NAttributes valueAttributes, void * pValue, NSizeType valueSize, NBool * pResult);
NResult N_API NDictionaryTryGetP(HNDictionary hDictionary, NTypeOfProc pKeyTypeOf, NAttributes keyAttributes, const void * pKey, NSizeType keySize, NTypeOfProc pValueTypeOf, NAttributes valueAttributes, void * pValue, NSizeType valueSize, NBool * pResult);
NResult N_API NDictionaryAddN(HNDictionary hDictionary, HNValue hKey, HNValue hValue);
NResult N_API NDictionaryAdd(HNDictionary hDictionary, HNType hKeyType, NAttributes keyAttributes, const void * pKey, NSizeType keySize, HNType hValueType, NAttributes valueAttributes, const void * pValue, NSizeType valueSize);
NResult N_API NDictionaryAddP(HNDictionary hDictionary, NTypeOfProc pKeyTypeOf, NAttributes keyAttributes, const void * pKey, NSizeType keySize, NTypeOfProc pValueTypeOf, NAttributes valueAttributes, const void * pValue, NSizeType valueSize);
NResult N_API NDictionarySetN(HNDictionary hDictionary, HNValue hKey, HNValue hValue);
NResult N_API NDictionarySet(HNDictionary hDictionary, HNType hKeyType, NAttributes keyAttributes, const void * pKey, NSizeType keySize, HNType hValueType, NAttributes valueAttributes, const void * pValue, NSizeType valueSize);
NResult N_API NDictionarySetP(HNDictionary hDictionary, NTypeOfProc pKeyTypeOf, NAttributes keyAttributes, const void * pKey, NSizeType keySize, NTypeOfProc pValueTypeOf, NAttributes valueAttributes, const void * pValue, NSizeType valueSize);
NResult N_API NDictionaryRemoveN(HNDictionary hDictionary, HNValue hKey, NBool * pResult);
NResult N_API NDictionaryRemove(HNDictionary hDictionary, HNType hKeyType, NAttributes keyAttributes, const void * pKey, NSizeType keySize, NBool * pResult);
NResult N_API NDictionaryRemoveP(HNDictionary hDictionary, NTypeOfProc pKeyTypeOf, NAttributes keyAttributes, const void * pKey, NSizeType keySize, NBool * pResult);

NResult N_API NDictionaryAddCollectionChanged(HNDictionary hDictionary, HNCallback hCallback);
NResult N_API NDictionaryAddCollectionChangedCallback(HNDictionary hDictionary, NDictionaryCollectionChangedCallback pCallback, void * pParam);
NResult N_API NDictionaryRemoveCollectionChanged(HNDictionary hDictionary, HNCallback hCallback);
NResult N_API NDictionaryRemoveCollectionChangedCallback(HNDictionary hDictionary, NDictionaryCollectionChangedCallback pCallback, void * pParam);
NResult N_API NDictionaryAddItemCollectionChanged(HNDictionary hDictionary, HNCallback hCallback);
NResult N_API NDictionaryAddItemCollectionChangedCallback(HNDictionary hDictionary, NCollectionItemCollectionChangedCallback pCallback, void * pParam);
NResult N_API NDictionaryRemoveItemCollectionChanged(HNDictionary hDictionary, HNCallback hCallback);
NResult N_API NDictionaryRemoveItemCollectionChangedCallback(HNDictionary hDictionary, NCollectionItemCollectionChangedCallback pCallback, void * pParam);

#ifdef N_CPP
}
#endif

#endif // !N_DICTIONARY_H_INCLUDED
