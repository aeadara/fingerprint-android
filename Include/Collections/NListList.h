#ifndef N_LIST_LIST_H_INCLUDED
#define N_LIST_LIST_H_INCLUDED

#include <Core/NType.h>

#ifdef N_CPP
extern "C"
{
#endif

#ifdef N_64
	#define N_LIST_LIST_SIZE 64
#else
	#define N_LIST_LIST_SIZE 44
#endif

N_DECLATE_PRIMITIVE(NListList, N_LIST_LIST_SIZE)
N_DECLARE_TYPE(NListList)

NResult N_API NListListInitP(NListList * pList, NSizeType elementSize, NTypeOfProc pElementTypeOf);
NResult N_API NListListInit(NListList * pList, NSizeType elementSize, HNType hElementType);
NResult N_API NListListInitWithCapacityP(NListList * pList, NSizeType elementSize, NTypeOfProc pElementTypeOf, NInt capacity);
NResult N_API NListListInitWithCapacity(NListList * pList, NSizeType elementSize, HNType hElementType, NInt capacity);
NResult N_API NListListInitExP(NListList * pList, NSizeType elementSize, NTypeOfProc pElementTypeOf, NInt capacity, NInt maxCapacity, NInt growthDelta,
	NInt itemDefaultCapacity, NInt itemMaxCapacity, NInt itemGrowthDelta, NSizeType itemAlignment);
NResult N_API NListListInitEx(NListList * pList, NSizeType elementSize, HNType hElementType, NInt capacity, NInt maxCapacity, NInt growthDelta,
	NInt itemDefaultCapacity, NInt itemMaxCapacity, NInt itemGrowthDelta, NSizeType itemAlignment);
NResult N_API NListListDispose(NListList * pList);
NResult N_API NListListGetCapacity(NListList * pList, NInt * pValue);
NResult N_API NListListSetCapacity(NListList * pList, NInt value);
NResult N_API NListListGetCount(NListList * pList, NInt * pValue);
NResult N_API NListListSetCount(NListList * pList, NInt value);
NResult N_API NListListAdd(NListList * pList, NInt itemCapacity);
NResult N_API NListListAddRange(NListList * pList, NInt count, NInt itemCapacity);
NResult N_API NListListAddListList(NListList * pList, NListList * pSrcList);
NResult N_API NListListInsert(NListList * pList, NInt index, NInt itemCapacity);
NResult N_API NListListInsertRange(NListList * pList, NInt index, NInt count, NInt itemCapacity);
NResult N_API NListListInsertListList(NListList * pList, NInt index, NListList * pSrcList);
NResult N_API NListListRemoveAt(NListList * pList, NInt index);
NResult N_API NListListRemoveRange(NListList * pList, NInt index, NInt count);
NResult N_API NListListClear(NListList * pList);

NResult N_API NListListGetItemCapacity(NListList * pList, NInt listIndex, NInt * pValue);
NResult N_API NListListSetItemCapacity(NListList * pList, NInt listIndex, NInt value);
NResult N_API NListListGetItemCount(NListList * pList, NInt listIndex, NInt * pValue);
NResult N_API NListListSetItemCount(NListList * pList, NInt listIndex, NInt value);
NResult N_API NListListIndexOfItemInRange(NListList * pList, NInt listIndex, HNType hValueType, const void * pValue, NSizeType valueSize, NInt startIndex, NInt count, NInt * pResult);
NResult N_API NListListIndexOfItemInRangeP(NListList * pList, NInt listIndex, NTypeOfProc pValueTypeOf, const void * pValue, NSizeType valueSize, NInt startIndex, NInt count, NInt * pResult);
NResult N_API NListListIndexOfItemFrom(NListList * pList, NInt listIndex, HNType hValueType, const void * pValue, NSizeType valueSize, NInt startIndex, NInt * pResult);
NResult N_API NListListIndexOfItemFromP(NListList * pList, NInt listIndex, NTypeOfProc pValueTypeOf, const void * pValue, NSizeType valueSize, NInt startIndex, NInt * pResult);
NResult N_API NListListIndexOfItem(NListList * pList, NInt listIndex, HNType hValueType, const void * pValue, NSizeType valueSize, NInt * pResult);
NResult N_API NListListIndexOfItemP(NListList * pList, NInt listIndex, NTypeOfProc pValueTypeOf, const void * pValue, NSizeType valueSize, NInt * pResult);
NResult N_API NListListLastIndexOfItemInRange(NListList * pList, NInt listIndex, HNType hValueType, const void * pValue, NSizeType valueSize, NInt startIndex, NInt count, NInt * pResult);
NResult N_API NListListLastIndexOfItemInRangeP(NListList * pList, NInt listIndex, NTypeOfProc pValueTypeOf, const void * pValue, NSizeType valueSize, NInt startIndex, NInt count, NInt * pResult);
NResult N_API NListListLastIndexOfItemFrom(NListList * pList, NInt listIndex, HNType hValueType, const void * pValue, NSizeType valueSize, NInt startIndex, NInt * pResult);
NResult N_API NListListLastIndexOfItemFromP(NListList * pList, NInt listIndex, NTypeOfProc pValueTypeOf, const void * pValue, NSizeType valueSize, NInt startIndex, NInt * pResult);
NResult N_API NListListLastIndexOfItem(NListList * pList, NInt listIndex, HNType hValueType, const void * pValue, NSizeType valueSize, NInt * pResult);
NResult N_API NListListLastIndexOfItemP(NListList * pList, NInt listIndex, NTypeOfProc pValueTypeOf, const void * pValue, NSizeType valueSize, NInt * pResult);
NResult N_API NListListContainsItem(NListList * pList, NInt listIndex, HNType hValueType, const void * pValue, NSizeType valueSize, NBool * pResult);
NResult N_API NListListContainsItemP(NListList * pList, NInt listIndex, NTypeOfProc pValueTypeOf, const void * pValue, NSizeType valueSize, NBool * pResult);
NResult N_API NListListGetItemsStart(NListList * pList, NInt listIndex, NSizeType elementSize, HNType hValueType, void * * ppValue);
NResult N_API NListListGetItemsStartP(NListList * pList, NInt listIndex, NSizeType elementSize, NTypeOfProc pValueTypeOf, void * * ppValue);
NResult N_API NListListGetItemsEnd(NListList * pList, NInt listIndex, NSizeType elementSize, HNType hValueType, void * * ppValue);
NResult N_API NListListGetItemsEndP(NListList * pList, NInt listIndex, NSizeType elementSize, NTypeOfProc pValueTypeOf, void * * ppValue);
NResult N_API NListListGetItemPtr(NListList * pList, NInt listIndex, NInt index, NSizeType elementSize, HNType hValueType, void * * ppValue);
NResult N_API NListListGetItemPtrP(NListList * pList, NInt listIndex, NInt index, NSizeType elementSize, NTypeOfProc pValueTypeOf, void * * ppValue);
NResult N_API NListListGetItem(NListList * pList, NInt listIndex, NInt index, HNType hValueType, void * pValue, NSizeType valueSize);
NResult N_API NListListGetItemP(NListList * pList, NInt listIndex, NInt index, NTypeOfProc pValueTypeOf, void * pValue, NSizeType valueSize);
NResult N_API NListListSetItem(NListList * pList, NInt listIndex, NInt index, HNType hValueType, const void * pValue, NSizeType valueSize);
NResult N_API NListListSetItemP(NListList * pList, NInt listIndex, NInt index, NTypeOfProc pValueTypeOf, const void * pValue, NSizeType valueSize);
NResult N_API NListListAddItem(NListList * pList, NInt listIndex, HNType hValueType, const void * pValue, NSizeType valueSize);
NResult N_API NListListAddItemP(NListList * pList, NInt listIndex, NTypeOfProc pValueTypeOf, const void * pValue, NSizeType valueSize);
NResult N_API NListListAddItemRange(NListList * pList, NInt listIndex, HNType hValueType, const void * pValues, NSizeType valuesSize, NInt valuesLength);
NResult N_API NListListAddItemRangeP(NListList * pList, NInt listIndex, NTypeOfProc pValueTypeOf, const void * pValues, NSizeType valuesSize, NInt valuesLength);
NResult N_API NListListAddListListItems(NListList * pList, NInt listIndex, NListList * pSrcList, NInt srcListIndex);
NResult N_API NListListInsertItem(NListList * pList, NInt listIndex, NInt index, HNType hValueType, const void * pValue, NSizeType valueSize);
NResult N_API NListListInsertItemP(NListList * pList, NInt listIndex, NInt index, NTypeOfProc pValueTypeOf, const void * pValue, NSizeType valueSize);
NResult N_API NListListInsertItemRange(NListList * pList, NInt listIndex, NInt index, HNType hValueType, const void * pValues, NSizeType valuesSize, NInt valuesLength);
NResult N_API NListListInsertItemRangeP(NListList * pList, NInt listIndex, NInt index, NTypeOfProc pValueTypeOf, const void * pValues, NSizeType valuesSize, NInt valuesLength);
NResult N_API NListListInsertListListItems(NListList * pList, NInt listIndex, NInt index, NListList * pSrcList, NInt srcListIndex);
NResult N_API NListListRemoveItemAt(NListList * pList, NInt listIndex, NInt index);
NResult N_API NListListRemoveItemRange(NListList * pList, NInt listIndex, NInt index, NInt count);
NResult N_API NListListRemoveItem(NListList * pList, NInt listIndex, HNType hValueType, const void * pValue, NSizeType valueSize, NInt * pIndex);
NResult N_API NListListRemoveItemP(NListList * pList, NInt listIndex, NTypeOfProc pValueTypeOf, const void * pValue, NSizeType valueSize, NInt * pIndex);
NResult N_API NListListClearItems(NListList * pList, NInt listIndex);
NResult N_API NListListCopyItemsToRange(NListList * pList, NInt listIndex, NInt index, NInt count, HNType hValueType, void * pValues, NSizeType valuesSize, NInt valuesLength);
NResult N_API NListListCopyItemsToRangeP(NListList * pList, NInt listIndex, NInt index, NInt count, NTypeOfProc pValueTypeOf, void * pValues, NSizeType valuesSize, NInt valuesLength);
NResult N_API NListListCopyItemsTo(NListList * pList, NInt listIndex, HNType hValueType, void * pValues, NSizeType valuesSize, NInt valuesLength);
NResult N_API NListListCopyItemsToP(NListList * pList, NInt listIndex, NTypeOfProc pValueTypeOf, void * pValues, NSizeType valuesSize, NInt valuesLength);
NResult N_API NListListItemsToArrayRange(NListList * pList, NInt listIndex, NInt index, NInt count, NSizeType elementSize, HNType hValueType, void * * ppValues, NInt * pValuesLength);
NResult N_API NListListItemsToArrayRangeP(NListList * pList, NInt listIndex, NInt index, NInt count, NSizeType elementSize, NTypeOfProc pValueTypeOf, void * * ppValues, NInt * pValuesLength);
NResult N_API NListListItemsToArray(NListList * pList, NInt listIndex, NSizeType elementSize, HNType hValueType, void * * ppValues, NInt * pValuesLength);
NResult N_API NListListItemsToArrayP(NListList * pList, NInt listIndex, NSizeType elementSize, NTypeOfProc pValueTypeOf, void * * ppValues, NInt * pValuesLength);
NResult N_API NListListDetachItemsArray(NListList * pList, NInt listIndex, NSizeType elementSize, HNType hValueType, void * * ppValues, NInt * pValuesLength);
NResult N_API NListListDetachItemsArrayP(NListList * pList, NInt listIndex, NSizeType elementSize, NTypeOfProc pValueTypeOf, void * * ppValues, NInt * pValuesLength);

#ifdef N_CPP
}
#endif

#endif // !N_LIST_LIST_H_INCLUDED
