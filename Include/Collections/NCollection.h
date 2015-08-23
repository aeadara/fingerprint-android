#include <Core/NObjectPart.h>
#include <Core/NArray.h>

#ifndef N_COLLECTION_H_INCLUDED
#define N_COLLECTION_H_INCLUDED

#ifdef N_CPP
extern "C"
{
#endif

typedef enum NCollectionChangedAction_
{
	nccaAdd = 0,
	nccaRemove = 1,
	nccaReplace = 2,
	nccaMove = 3,
	nccaReset = 4
} NCollectionChangedAction;

N_DECLARE_TYPE(NCollectionChangedAction)

#define N_COLLECTION_CHANGED_CALLBACK(itemType) NResult (N_CALLBACK)(HNObject hObject, NCollectionChangedAction action, NInt newIndex, itemType const * arNewItems, NInt newItemCount, NInt oldIndex, itemType const * arOldItems, NInt oldItemCount, void * pParam)
#define N_COLLECTION_CHANGED_CALLBACK_ARG(itemType, name) NResult (N_CALLBACK name)(HNObject hObject, NCollectionChangedAction action, NInt newIndex, itemType const * arNewItems, NInt newItemCount, NInt oldIndex, itemType const * arOldItems, NInt oldItemCount, void * pParam)

typedef NResult (N_CALLBACK NCollectionCollectionChangedCallback)(HNObject hObject, NCollectionChangedAction action, NInt newIndex, const HNValue * arhNewItems, NInt newItemCount, NInt oldIndex, const HNValue * arhOldItems, NInt oldItemCount, void * pParam);
N_DECLARE_TYPE(NCollectionCollectionChangedCallback);

typedef NResult (N_CALLBACK NCollectionItemCollectionChangedCallback)(HNObject hObject, NCollectionChangedAction action, NInt newIndex, HNArray hNewItems, NInt oldIndex, HNArray hOldItems, void * pParam);
N_DECLARE_TYPE(NCollectionItemCollectionChangedCallback);

NResult N_API NCollectionIsReadOnly(HNCollection hCollection, NBool * pValue);
NResult N_API NCollectionGetCount(HNCollection hCollection, NInt * pValue);
NResult N_API NCollectionGetCapacity(HNCollection hCollection, NInt * pValue);
NResult N_API NCollectionSetCapacity(HNCollection hCollection, NInt value);
NResult N_API NCollectionGetN(HNCollection hCollection, NInt index, HNValue * phValue);
NResult N_API NCollectionGet(HNCollection hCollection, NInt index, HNType hValueType, NAttributes attributes, void * pValue, NSizeType valueSize);
NResult N_API NCollectionGetP(HNCollection hCollection, NInt index, NTypeOfProc pValueTypeOf, NAttributes attributes, void * pValue, NSizeType valueSize);
NResult N_API NCollectionToArrayN(HNCollection hCollection, HNValue * * parhValues, NInt * pValueCount);
NResult N_API NCollectionToItemArray(HNCollection hCollection, HNArray * phValues);
NResult N_API NCollectionToArray(HNCollection hCollection, HNType hValueType, NAttributes attributes, NSizeType valueSize, void * * parValues, NInt * pValueCount);
NResult N_API NCollectionToArrayP(HNCollection hCollection, NTypeOfProc pValueTypeOf, NAttributes attributes, NSizeType valueSize, void * * parValues, NInt * pValueCount);
NResult N_API NCollectionSetN(HNCollection hCollection, NInt index, HNValue hValue);
NResult N_API NCollectionSet(HNCollection hCollection, NInt index, HNType hValueType, NAttributes attributes, const void * pValue, NSizeType valueSize);
NResult N_API NCollectionSetP(HNCollection hCollection, NInt index, NTypeOfProc pValueTypeOf, NAttributes attributes, const void * pValue, NSizeType valueSize);
NResult N_API NCollectionAddN(HNCollection hCollection, HNValue hValue, NInt * pIndex);
NResult N_API NCollectionAdd(HNCollection hCollection, HNType hValueType, NAttributes attributes, const void * pValue, NSizeType valueSize, NInt * pIndex);
NResult N_API NCollectionAddP(HNCollection hCollection, NTypeOfProc pValueTypeOf, NAttributes attributes, const void * pValue, NSizeType valueSize, NInt * pIndex);
NResult N_API NCollectionAddRangeN(HNCollection hCollection, const HNValue * arhValues, NInt valueCount, NInt * pIndex);
NResult N_API NCollectionAddItemRange(HNCollection hCollection, HNArray hValues, NInt * pIndex);
NResult N_API NCollectionAddRange(HNCollection hCollection, HNType hValueType, NAttributes attributes, const void * arValues, NSizeType valuesSize, NInt valueCount, NInt * pIndex);
NResult N_API NCollectionAddRangeP(HNCollection hCollection, NTypeOfProc pValueTypeOf, NAttributes attributes, const void * arValues, NSizeType valuesSize, NInt valueCount, NInt * pIndex);
NResult N_API NCollectionInsertN(HNCollection hCollection, NInt index, HNValue hValue);
NResult N_API NCollectionInsert(HNCollection hCollection, NInt index, HNType hValueType, NAttributes attributes, const void * pValue, NSizeType valueSize);
NResult N_API NCollectionInsertP(HNCollection hCollection, NInt index, NTypeOfProc pValueTypeOf, NAttributes attributes, const void * pValue, NSizeType valueSize);
NResult N_API NCollectionInsertRangeN(HNCollection hCollection, NInt index, const HNValue * arhValues, NInt valueCount);
NResult N_API NCollectionInsertItemRange(HNCollection hCollection, NInt index, HNArray hValues);
NResult N_API NCollectionInsertRange(HNCollection hCollection, NInt index, HNType hValueType, NAttributes attributes, const void * arValues, NSizeType valuesSize, NInt valueCount);
NResult N_API NCollectionInsertRangeP(HNCollection hCollection, NInt index, NTypeOfProc pValueTypeOf, NAttributes attributes, const void * arValues, NSizeType valuesSize, NInt valueCount);
NResult N_API NCollectionRemoveN(HNCollection hCollection, HNValue hValue, NInt * pIndex);
NResult N_API NCollectionRemove(HNCollection hCollection, HNType hValueType, NAttributes attributes, const void * pValue, NSizeType valueSize, NInt * pIndex);
NResult N_API NCollectionRemoveP(HNCollection hCollection, NTypeOfProc pValueTypeOf, NAttributes attributes, const void * pValue, NSizeType valueSize, NInt * pIndex);
NResult N_API NCollectionRemoveAt(HNCollection hCollection, NInt index);
NResult N_API NCollectionRemoveRange(HNCollection hCollection, NInt startIndex, NInt count);
NResult N_API NCollectionClear(HNCollection hCollection);
NResult N_API NCollectionIndexOfN(HNCollection hCollection, HNValue hValue, NInt * pResult);
NResult N_API NCollectionIndexOf(HNCollection hCollection, HNType hValueType, NAttributes attributes, const void * pValue, NSizeType valueSize, NInt * pResult);
NResult N_API NCollectionIndexOfP(HNCollection hCollection, NTypeOfProc pValueTypeOf, NAttributes attributes, const void * pValue, NSizeType valueSize, NInt * pResult);
NResult N_API NCollectionContainsN(HNCollection hCollection, HNValue hValue, NBool * pResult);
NResult N_API NCollectionContains(HNCollection hCollection, HNType hValueType, NAttributes attributes, const void * pValue, NSizeType valueSize, NBool * pResult);
NResult N_API NCollectionContainsP(HNCollection hCollection, NTypeOfProc pValueTypeOf, NAttributes attributes, const void * pValue, NSizeType valueSize, NBool * pResult);

NResult N_API NCollectionAddCollectionChanged(HNCollection hCollection, HNCallback hCallback);
NResult N_API NCollectionAddCollectionChangedCallback(HNCollection hCollection, NCollectionCollectionChangedCallback pCallback, void * pParam);
NResult N_API NCollectionRemoveCollectionChanged(HNCollection hCollection, HNCallback hCallback);
NResult N_API NCollectionRemoveCollectionChangedCallback(HNCollection hCollection, NCollectionCollectionChangedCallback pCallback, void * pParam);
NResult N_API NCollectionAddItemCollectionChanged(HNCollection hCollection, HNCallback hCallback);
NResult N_API NCollectionAddItemCollectionChangedCallback(HNCollection hCollection, NCollectionItemCollectionChangedCallback pCallback, void * pParam);
NResult N_API NCollectionRemoveItemCollectionChanged(HNCollection hCollection, HNCallback hCallback);
NResult N_API NCollectionRemoveItemCollectionChangedCallback(HNCollection hCollection, NCollectionItemCollectionChangedCallback pCallback, void * pParam);

#ifdef N_CPP
}
#endif

#endif // !N_COLLECTION_H_INCLUDED
