#include <Core/NObjectPart.h>
#include <Core/NArray.h>

#ifndef N_ARRAY_COLLECTION_H_INCLUDED
#define N_ARRAY_COLLECTION_H_INCLUDED

#ifdef N_CPP
extern "C"
{
#endif

NResult N_API NArrayCollectionIsReadOnly(HNArrayCollection hArrayCollection, NBool * pValue);
NResult N_API NArrayCollectionGetBaseCount(HNArrayCollection hArrayCollection, NInt * pValue);
NResult N_API NArrayCollectionGetCount(HNArrayCollection hArrayCollection, NInt baseIndex, NInt * pValue);
NResult N_API NArrayCollectionGetN(HNArrayCollection hArrayCollection, NInt baseIndex, NInt index, HNValue * phValue);
NResult N_API NArrayCollectionGet(HNArrayCollection hArrayCollection, NInt baseIndex, NInt index, HNType hValueType, NAttributes attributes, void * pValue, NSizeType valueSize);
NResult N_API NArrayCollectionGetP(HNArrayCollection hArrayCollection, NInt baseIndex, NInt index, NTypeOfProc pValueTypeOf, NAttributes attributes, void * pValue, NSizeType valueSize);
NResult N_API NArrayCollectionToArrayN(HNArrayCollection hArrayCollection, NInt baseIndex, HNValue * * parhValues, NInt * pValueCount);
NResult N_API NArrayCollectionToItemArray(HNArrayCollection hArrayCollection, NInt baseIndex, HNArray * phValues);
NResult N_API NArrayCollectionToArray(HNArrayCollection hArrayCollection, NInt baseIndex, HNType hValueType, NAttributes attributes, NSizeType valueSize, void * * parValues, NInt * pValueCount);
NResult N_API NArrayCollectionToArrayP(HNArrayCollection hArrayCollection, NInt baseIndex, NTypeOfProc pValueTypeOf, NAttributes attributes, NSizeType valueSize, void * * parValues, NInt * pValueCount);
NResult N_API NArrayCollectionSetN(HNArrayCollection hArrayCollection, NInt baseIndex, NInt index, HNValue hValue);
NResult N_API NArrayCollectionSet(HNArrayCollection hArrayCollection, NInt baseIndex, NInt index, HNType hValueType, NAttributes attributes, const void * pValue, NSizeType valueSize);
NResult N_API NArrayCollectionSetP(HNArrayCollection hArrayCollection, NInt baseIndex, NInt index, NTypeOfProc pValueTypeOf, NAttributes attributes, const void * pValue, NSizeType valueSize);
NResult N_API NArrayCollectionAddN(HNArrayCollection hArrayCollection, NInt baseIndex, HNValue hValue, NInt * pIndex);
NResult N_API NArrayCollectionAdd(HNArrayCollection hArrayCollection, NInt baseIndex, HNType hValueType, NAttributes attributes, const void * pValue, NSizeType valueSize, NInt * pIndex);
NResult N_API NArrayCollectionAddP(HNArrayCollection hArrayCollection, NInt baseIndex, NTypeOfProc pValueTypeOf, NAttributes attributes, const void * pValue, NSizeType valueSize, NInt * pIndex);
NResult N_API NArrayCollectionAddRangeN(HNArrayCollection hArrayCollection, NInt baseIndex, const HNValue * arhValues, NInt valueCount, NInt * pIndex);
NResult N_API NArrayCollectionAddItemRange(HNArrayCollection hArrayCollection, NInt baseIndex, HNArray hValues, NInt * pIndex);
NResult N_API NArrayCollectionAddRange(HNArrayCollection hArrayCollection, NInt baseIndex, HNType hValueType, NAttributes attributes, const void * arValues, NSizeType valuesSize, NInt valueCount, NInt * pIndex);
NResult N_API NArrayCollectionAddRangeP(HNArrayCollection hArrayCollection, NInt baseIndex, NTypeOfProc pValueTypeOf, NAttributes attributes, const void * arValues, NSizeType valuesSize, NInt valueCount, NInt * pIndex);
NResult N_API NArrayCollectionInsertN(HNArrayCollection hArrayCollection, NInt baseIndex, NInt index, HNValue hValue);
NResult N_API NArrayCollectionInsert(HNArrayCollection hArrayCollection, NInt baseIndex, NInt index, HNType hValueType, NAttributes attributes, const void * pValue, NSizeType valueSize);
NResult N_API NArrayCollectionInsertP(HNArrayCollection hArrayCollection, NInt baseIndex, NInt index, NTypeOfProc pValueTypeOf, NAttributes attributes, const void * pValue, NSizeType valueSize);
NResult N_API NArrayCollectionInsertRangeN(HNArrayCollection hArrayCollection, NInt baseIndex, NInt index, const HNValue * arhValues, NInt valueCount);
NResult N_API NArrayCollectionInsertItemRange(HNArrayCollection hArrayCollection, NInt baseIndex, NInt index, HNArray hValues);
NResult N_API NArrayCollectionInsertRange(HNArrayCollection hArrayCollection, NInt baseIndex, NInt index, HNType hValueType, NAttributes attributes, const void * arValues, NSizeType valuesSize, NInt valueCount);
NResult N_API NArrayCollectionInsertRangeP(HNArrayCollection hArrayCollection, NInt baseIndex, NInt index, NTypeOfProc pValueTypeOf, NAttributes attributes, const void * arValues, NSizeType valuesSize, NInt valueCount);
NResult N_API NArrayCollectionRemoveN(HNArrayCollection hArrayCollection, NInt baseIndex, HNValue hValue, NInt * pIndex);
NResult N_API NArrayCollectionRemove(HNArrayCollection hArrayCollection, NInt baseIndex, HNType hValueType, NAttributes attributes, const void * pValue, NSizeType valueSize, NInt * pIndex);
NResult N_API NArrayCollectionRemoveP(HNArrayCollection hArrayCollection, NInt baseIndex, NTypeOfProc pValueTypeOf, NAttributes attributes, const void * pValue, NSizeType valueSize, NInt * pIndex);
NResult N_API NArrayCollectionRemoveAt(HNArrayCollection hArrayCollection, NInt baseIndex, NInt index);
NResult N_API NArrayCollectionRemoveRange(HNArrayCollection hArrayCollection, NInt baseIndex, NInt startIndex, NInt count);
NResult N_API NArrayCollectionClear(HNArrayCollection hArrayCollection, NInt baseIndex);
NResult N_API NArrayCollectionIndexOfN(HNArrayCollection hArrayCollection, NInt baseIndex, HNValue hValue, NInt * pResult);
NResult N_API NArrayCollectionIndexOf(HNArrayCollection hArrayCollection, NInt baseIndex, HNType hValueType, NAttributes attributes, const void * pValue, NSizeType valueSize, NInt * pResult);
NResult N_API NArrayCollectionIndexOfP(HNArrayCollection hArrayCollection, NInt baseIndex, NTypeOfProc pValueTypeOf, NAttributes attributes, const void * pValue, NSizeType valueSize, NInt * pResult);
NResult N_API NArrayCollectionContainsN(HNArrayCollection hArrayCollection, NInt baseIndex, HNValue hValue, NBool * pResult);
NResult N_API NArrayCollectionContains(HNArrayCollection hArrayCollection, NInt baseIndex, HNType hValueType, NAttributes attributes, const void * pValue, NSizeType valueSize, NBool * pResult);
NResult N_API NArrayCollectionContainsP(HNArrayCollection hArrayCollection, NInt baseIndex, NTypeOfProc pValueTypeOf, NAttributes attributes, const void * pValue, NSizeType valueSize, NBool * pResult);

#ifdef N_CPP
}
#endif

#endif // !N_ARRAY_COLLECTION_H_INCLUDED
