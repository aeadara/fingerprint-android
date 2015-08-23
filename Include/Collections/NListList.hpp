#ifndef N_LIST_LIST_HPP_INCLUDED
#define N_LIST_LIST_HPP_INCLUDED

#include <Core/NType.hpp>
namespace Neurotec { namespace Collections { namespace Internal
{
#include <Collections/NListList.h>
}}}

namespace Neurotec { namespace Collections
{

class NListList : private Internal::NListList
{
	N_DECLARE_PRIMITIVE_CLASS(NListList)

public:
	explicit NListList(NSizeType elementSize)
	{
		NCheck(Internal::NListListInit(this, elementSize, NULL));
	}

	template<typename T> NListList()
	{
		NCheck(Internal::NListListInit(this, 0, NTypeTraits<T>::GetNativeType().GetHandle()));
	}

	NListList(const NType & elementType)
	{
		NCheck(Internal::NListListInit(this, 0, elementType.GetHandle()));
	}

	NListList(NTypeOfProc pElementTypeOf)
	{
		NCheck(Internal::NListListInitP(this, 0, pElementTypeOf));
	}

	NListList(NSizeType elementSize, NInt capacity)
	{
		NCheck(Internal::NListListInitWithCapacity(this, elementSize, NULL, capacity));
	}

	template<typename T> NListList(NInt capacity)
	{
		NCheck(Internal::NListListInit(this, 0, NTypeTraits<T>::GetNativeType().GetHandle(), capacity));
	}

	NListList(NSizeType elementSize, const NType & elementType, NInt capacity)
	{
		NCheck(Internal::NListListInitWithCapacity(this, elementSize, elementType.GetHandle(), capacity));
	}

	NListList(NTypeOfProc pElementTypeOf, NInt capacity)
	{
		NCheck(Internal::NListListInitWithCapacityP(this, 0, pElementTypeOf, capacity));
	}

	NListList(NInt capacity, NInt maxCapacity, NInt growthDelta, NInt itemDefaultCapacity, NInt itemMaxCapacity, NInt itemGrowthDelta, NSizeType itemAlignment)
	{
		NCheck(Internal::NListListInitEx(this, 0, NULL, capacity, maxCapacity, growthDelta, itemDefaultCapacity, itemMaxCapacity, itemGrowthDelta, itemAlignment));
	}

	template<typename T> NListList(NInt capacity, NInt maxCapacity, NInt growthDelta, NInt itemDefaultCapacity, NInt itemMaxCapacity, NInt itemGrowthDelta, NSizeType itemAlignment)
	{
		NCheck(Internal::NListListInitEx(this, 0, NTypeTraits<T>::GetNativeType().GetHandle(), capacity, maxCapacity, growthDelta, itemDefaultCapacity, itemMaxCapacity, itemGrowthDelta, itemAlignment));
	}

	NListList(const NType & elementType, NInt capacity, NInt maxCapacity, NInt growthDelta, NInt itemDefaultCapacity, NInt itemMaxCapacity, NInt itemGrowthDelta, NSizeType itemAlignment)
	{
		NCheck(Internal::NListListInitEx(this, 0, elementType.GetHandle(), capacity, maxCapacity, growthDelta, itemDefaultCapacity, itemMaxCapacity, itemGrowthDelta, itemAlignment));
	}

	NListList(NTypeOfProc pElementTypeOf, NInt capacity, NInt maxCapacity, NInt growthDelta, NInt itemDefaultCapacity, NInt itemMaxCapacity, NInt itemGrowthDelta, NSizeType itemAlignment)
	{
		NCheck(Internal::NListListInitExP(this, 0, pElementTypeOf, capacity, maxCapacity, growthDelta, itemDefaultCapacity, itemMaxCapacity, itemGrowthDelta, itemAlignment));
	}

	~NListList()
	{
		NCheck(Internal::NListListDispose(this));
	}

	NInt GetCapacity()
	{
		NInt value;
		NCheck(Internal::NListListGetCapacity(this, &value));
		return value;
	}

	void SetCapacity(NInt value)
	{
		NCheck(Internal::NListListSetCapacity(this, value));
	}

	NInt GetCount()
	{
		NInt value;
		NCheck(Internal::NListListGetCount(this, &value));
		return value;
	}

	void SetCount(NInt value)
	{
		NCheck(Internal::NListListSetCount(this, value));
	}

	void Add(NInt itemCapacity = -1)
	{
		NCheck(Internal::NListListAdd(this, itemCapacity));
	}

	void AddRange(NInt count, NInt itemCapacity = -1)
	{
		NCheck(Internal::NListListAddRange(this, count, itemCapacity));
	}

	void AddListList(NListList & srcList)
	{
		NCheck(Internal::NListListAddListList(this, &srcList));
	}

	void Insert(NInt index, NInt itemCapacity = -1)
	{
		NCheck(Internal::NListListInsert(this, index, itemCapacity));
	}

	void InsertRange(NInt index, NInt count, NInt itemCapacity = -1)
	{
		NCheck(Internal::NListListInsertRange(this, index, count, itemCapacity));
	}

	void InsertListList(NInt index, NListList & srcList)
	{
		NCheck(Internal::NListListInsertListList(this, index, &srcList));
	}

	void RemoveAt(NInt index)
	{
		NCheck(Internal::NListListRemoveAt(this, index));
	}

	void RemoveRange(NInt index, NInt count)
	{
		NCheck(Internal::NListListRemoveRange(this, index, count));
	}

	void Clear()
	{
		NCheck(Internal::NListListClear(this));
	}

	NInt GetCapacity(NInt listIndex)
	{
		NInt value;
		NCheck(Internal::NListListGetItemCapacity(this, listIndex, &value));
		return value;
	}

	void SetCapacity(NInt listIndex, NInt value)
	{
		NCheck(Internal::NListListSetItemCapacity(this, listIndex, value));
	}

	NInt GetCount(NInt listIndex)
	{
		NInt value;
		NCheck(Internal::NListListGetItemCount(this, listIndex, &value));
		return value;
	}

	void SetCount(NInt listIndex, NInt value)
	{
		NCheck(Internal::NListListSetItemCount(this, listIndex, value));
	}

	NInt IndexOf(NInt listIndex, const void * pValue, NSizeType valueSize, NInt startIndex, NInt count)
	{
		NInt result;
		NCheck(Internal::NListListIndexOfItemInRange(this, listIndex, NULL, pValue, valueSize, startIndex, count, &result));
		return result;
	}

	template<typename T> NInt IndexOf(NInt listIndex, const T & value, NInt startIndex, NInt count)
	{
		typename NTypeTraits<T>::NativeType v = NTypeTraits<T>::ToNative(value);
		NInt result;
		NCheck(Internal::NListListIndexOfItemInRange(this, listIndex, NTypeTraits<T>::GetNativeType().GetHandle(), &v, sizeof(v), startIndex, count, &result));
		return result;
	}

	NInt IndexOf(NInt listIndex, const NType & valueType, const void * pValue, NSizeType valueSize, NInt startIndex, NInt count)
	{
		NInt result;
		NCheck(Internal::NListListIndexOfItemInRange(this, listIndex, valueType.GetHandle(), pValue, valueSize, startIndex, count, &result));
		return result;
	}

	NInt IndexOf(NInt listIndex, NTypeOfProc pValueTypeOf, const void * pValue, NSizeType valueSize, NInt startIndex, NInt count)
	{
		NInt result;
		NCheck(Internal::NListListIndexOfItemInRangeP(this, listIndex, pValueTypeOf, pValue, valueSize, startIndex, count, &result));
		return result;
	}

	NInt IndexOf(NInt listIndex, const void * pValue, NSizeType valueSize, NInt startIndex)
	{
		NInt result;
		NCheck(Internal::NListListIndexOfItemFrom(this, listIndex, NULL, pValue, valueSize, startIndex, &result));
		return result;
	}

	template<typename T> NInt IndexOf(NInt listIndex, const T & value, NInt startIndex)
	{
		typename NTypeTraits<T>::NativeType v = NTypeTraits<T>::ToNative(value);
		NInt result;
		NCheck(Internal::NListListIndexOfItemFrom(this, listIndex, NTypeTraits<T>::GetNativeType().GetHandle(), &v, sizeof(v), startIndex, &result));
		return result;
	}

	NInt IndexOf(NInt listIndex, const NType & valueType, const void * pValue, NSizeType valueSize, NInt startIndex)
	{
		NInt result;
		NCheck(Internal::NListListIndexOfItemFrom(this, listIndex, valueType.GetHandle(), pValue, valueSize, startIndex, &result));
		return result;
	}

	NInt IndexOf(NInt listIndex, NTypeOfProc pValueTypeOf, const void * pValue, NSizeType valueSize, NInt startIndex)
	{
		NInt result;
		NCheck(Internal::NListListIndexOfItemFromP(this, listIndex, pValueTypeOf, pValue, valueSize, startIndex, &result));
		return result;
	}

	NInt IndexOf(NInt listIndex, const void * pValue, NSizeType valueSize)
	{
		NInt result;
		NCheck(Internal::NListListIndexOfItem(this, listIndex, NULL, pValue, valueSize, &result));
		return result;
	}

	template<typename T> NInt IndexOf(NInt listIndex, const T & value)
	{
		typename NTypeTraits<T>::NativeType v = NTypeTraits<T>::ToNative(value);
		NInt result;
		NCheck(Internal::NListListIndexOfItem(this, listIndex, NTypeTraits<T>::GetNativeType().GetHandle(), &v, sizeof(v), &result));
		return result;
	}

	NInt IndexOf(NInt listIndex, const NType & valueType, const void * pValue, NSizeType valueSize)
	{
		NInt result;
		NCheck(Internal::NListListIndexOfItem(this, listIndex, valueType.GetHandle(), pValue, valueSize, &result));
		return result;
	}

	NInt IndexOf(NInt listIndex, NTypeOfProc pValueTypeOf, const void * pValue, NSizeType valueSize)
	{
		NInt result;
		NCheck(Internal::NListListIndexOfItemP(this, listIndex, pValueTypeOf, pValue, valueSize, &result));
		return result;
	}

	NInt LastIndexOf(NInt listIndex, const void * pValue, NSizeType valueSize, NInt startIndex, NInt count)
	{
		NInt result;
		NCheck(Internal::NListListLastIndexOfItemInRange(this, listIndex, NULL, pValue, valueSize, startIndex, count, &result));
		return result;
	}

	template<typename T> NInt LastIndexOf(NInt listIndex, const T & value, NInt startIndex, NInt count)
	{
		typename NTypeTraits<T>::NativeType v = NTypeTraits<T>::ToNative(value);
		NInt result;
		NCheck(Internal::NListListLastIndexOfItemInRange(this, listIndex, NTypeTraits<T>::GetNativeType().GetHandle(), &v, sizeof(v), startIndex, count, &result));
		return result;
	}

	NInt LastIndexOf(NInt listIndex, const NType & valueType, const void * pValue, NSizeType valueSize, NInt startIndex, NInt count)
	{
		NInt result;
		NCheck(Internal::NListListLastIndexOfItemInRange(this, listIndex, valueType.GetHandle(), pValue, valueSize, startIndex, count, &result));
		return result;
	}

	NInt LastIndexOf(NInt listIndex, NTypeOfProc pValueTypeOf, const void * pValue, NSizeType valueSize, NInt startIndex, NInt count)
	{
		NInt result;
		NCheck(Internal::NListListLastIndexOfItemInRangeP(this, listIndex, pValueTypeOf, pValue, valueSize, startIndex, count, &result));
		return result;
	}

	NInt LastIndexOf(NInt listIndex, const void * pValue, NSizeType valueSize, NInt startIndex)
	{
		NInt result;
		NCheck(Internal::NListListLastIndexOfItemFrom(this, listIndex, NULL, pValue, valueSize, startIndex, &result));
		return result;
	}

	template<typename T> NInt LastIndexOf(NInt listIndex, const T & value, NInt startIndex)
	{
		typename NTypeTraits<T>::NativeType v = NTypeTraits<T>::ToNative(value);
		NInt result;
		NCheck(Internal::NListListLastIndexOfItemFrom(this, listIndex, NTypeTraits<T>::GetNativeType().GetHandle(), &v, sizeof(v), startIndex, &result));
		return result;
	}

	NInt LastIndexOf(NInt listIndex, const NType & valueType, const void * pValue, NSizeType valueSize, NInt startIndex)
	{
		NInt result;
		NCheck(Internal::NListListLastIndexOfItemFrom(this, listIndex, valueType.GetHandle(), pValue, valueSize, startIndex, &result));
		return result;
	}

	NInt LastIndexOf(NInt listIndex, NTypeOfProc pValueTypeOf, const void * pValue, NSizeType valueSize, NInt startIndex)
	{
		NInt result;
		NCheck(Internal::NListListLastIndexOfItemFromP(this, listIndex, pValueTypeOf, pValue, valueSize, startIndex, &result));
		return result;
	}

	NInt LastIndexOf(NInt listIndex, const void * pValue, NSizeType valueSize)
	{
		NInt result;
		NCheck(Internal::NListListLastIndexOfItem(this, listIndex, NULL, pValue, valueSize, &result));
		return result;
	}

	template<typename T> NInt LastIndexOf(NInt listIndex, const T & value)
	{
		typename NTypeTraits<T>::NativeType v = NTypeTraits<T>::ToNative(value);
		NInt result;
		NCheck(Internal::NListListLastIndexOfItem(this, listIndex, NTypeTraits<T>::GetNativeType().GetHandle(), &v, sizeof(v), &result));
		return result;
	}

	NInt LastIndexOf(NInt listIndex, const NType & valueType, const void * pValue, NSizeType valueSize)
	{
		NInt result;
		NCheck(Internal::NListListLastIndexOfItem(this, listIndex, valueType.GetHandle(), pValue, valueSize, &result));
		return result;
	}

	NInt LastIndexOf(NInt listIndex, NTypeOfProc pValueTypeOf, const void * pValue, NSizeType valueSize)
	{
		NInt result;
		NCheck(Internal::NListListLastIndexOfItemP(this, listIndex, pValueTypeOf, pValue, valueSize, &result));
		return result;
	}

	bool Contains(NInt listIndex, const void * pValue, NSizeType valueSize)
	{
		NBool result;
		NCheck(Internal::NListListContainsItem(this, listIndex, NULL, pValue, valueSize, &result));
		return result != 0;
	}

	template<typename T> bool Contains(NInt listIndex, const T & value)
	{
		typename NTypeTraits<T>::NativeType v = NTypeTraits<T>::ToNative(value);
		NBool result;
		NCheck(Internal::NListListContainsItem(this, listIndex, NTypeTraits<T>::GetNativeType().GetHandle(), &v, sizeof(v), &result));
		return result != 0;
	}

	bool Contains(NInt listIndex, const NType & valueType, const void * pValue, NSizeType valueSize)
	{
		NBool result;
		NCheck(Internal::NListListContainsItem(this, listIndex, valueType.GetHandle(), pValue, valueSize, &result));
		return result != 0;
	}

	bool Contains(NInt listIndex, NTypeOfProc pValueTypeOf, const void * pValue, NSizeType valueSize)
	{
		NBool result;
		NCheck(Internal::NListListContainsItemP(this, listIndex, pValueTypeOf, pValue, valueSize, &result));
		return result != 0;
	}

	void * GetStart(NInt listIndex, NSizeType elementSize)
	{
		void * pValue;
		NCheck(Internal::NListListGetItemsStart(this, listIndex, elementSize, NULL, &pValue));
		return pValue;
	}

	template<typename T> typename NTypeTraits<T>::NativeType * GetStart(NInt listIndex)
	{
		typename NTypeTraits<T>::NativeType * pValue;
		NCheck(Internal::NListListGetItemsStart(this, listIndex, 0, NTypeTraits<T>::GetNativeType().GetHandle(), (void * *)&pValue));
		return pValue;
	}

	void * GetStart(NInt listIndex, const NType & elementType)
	{
		void * pValue;
		NCheck(Internal::NListListGetItemsStart(this, listIndex, 0, elementType.GetHandle(), &pValue));
		return pValue;
	}

	void * GetStart(NInt listIndex, NTypeOfProc pElementTypeOf)
	{
		void * pValue;
		NCheck(Internal::NListListGetItemsStartP(this, listIndex, 0, pElementTypeOf, &pValue));
		return pValue;
	}

	void * GetEnd(NInt listIndex, NSizeType elementSize)
	{
		void * pValue;
		NCheck(Internal::NListListGetItemsEnd(this, listIndex, elementSize, NULL, &pValue));
		return pValue;
	}

	template<typename T> typename NTypeTraits<T>::NativeType * GetEnd(NInt listIndex)
	{
		typename NTypeTraits<T>::NativeType * pValue;
		NCheck(Internal::NListListGetItemsEnd(this, listIndex, 0, NTypeTraits<T>::GetNativeType().GetHandle(), (void * *)&pValue));
		return pValue;
	}

	void * GetEnd(NInt listIndex, const NType & elementType)
	{
		void * pValue;
		NCheck(Internal::NListListGetItemsEnd(this, listIndex, 0, elementType.GetHandle(), &pValue));
		return pValue;
	}

	void * GetEnd(NInt listIndex, NTypeOfProc pElementTypeOf)
	{
		void * pValue;
		NCheck(Internal::NListListGetItemsEndP(this, listIndex, 0, pElementTypeOf, &pValue));
		return pValue;
	}

	void * GetPtr(NInt listIndex, NInt index, NSizeType elementSize)
	{
		void * pValue;
		NCheck(Internal::NListListGetItemPtr(this, listIndex, index, elementSize, NULL, &pValue));
		return pValue;
	}

	template<typename T> typename NTypeTraits<T>::NativeType * GetPtr(NInt listIndex, NInt index)
	{
		typename NTypeTraits<T>::NativeType * pValue;
		NCheck(Internal::NListListGetItemPtr(this, listIndex, index, 0, NTypeTraits<T>::GetNativeType().GetHandle(), (void * *)&pValue));
		return pValue;
	}

	void * GetPtr(NInt listIndex, NInt index, const NType & elementType)
	{
		void * pValue;
		NCheck(Internal::NListListGetItemPtr(this, listIndex, index, 0, elementType.GetHandle(), &pValue));
		return pValue;
	}

	void * GetPtr(NInt listIndex, NInt index, NTypeOfProc pElementTypeOf)
	{
		void * pValue;
		NCheck(Internal::NListListGetItemPtrP(this, listIndex, index, 0, pElementTypeOf, &pValue));
		return pValue;
	}

	void Get(NInt listIndex, NInt index, void * pValue, NSizeType valueSize)
	{
		NCheck(Internal::NListListGetItem(this, listIndex, index, NULL, pValue, valueSize));
	}

	template<typename T> T Get(NInt listIndex, NInt index)
	{
		typename NTypeTraits<T>::NativeType value;
		NCheck(Internal::NListListGetItem(this, listIndex, index, NTypeTraits<T>::GetNativeType().GetHandle(), &value, sizeof(value)));
		return NTypeTraits<T>::FromNative(value, true);
	}

	void Get(NInt listIndex, NInt index, const NType & valueType, void * pValue, NSizeType valueSize)
	{
		NCheck(Internal::NListListGetItem(this, listIndex, index, valueType.GetHandle(), pValue, valueSize));
	}

	void Get(NInt listIndex, NInt index, NTypeOfProc pValueTypeOf, void * pValue, NSizeType valueSize)
	{
		NCheck(Internal::NListListGetItemP(this, listIndex, index, pValueTypeOf, pValue, valueSize));
	}

	void Set(NInt listIndex, NInt index, const void * pValue, NSizeType valueSize)
	{
		NCheck(Internal::NListListSetItem(this, listIndex, index, NULL, pValue, valueSize));
	}

	template<typename T> void Set(NInt listIndex, NInt index, const T & value)
	{
		typename NTypeTraits<T>::NativeType v = NTypeTraits<T>::ToNative(value);
		NCheck(Internal::NListListSetItem(this, listIndex, index, NTypeTraits<T>::GetNativeType().GetHandle(), &v, sizeof(v)));
	}

	void Set(NInt listIndex, NInt index, const NType & valueType, const void * pValue, NSizeType valueSize)
	{
		NCheck(Internal::NListListSetItem(this, listIndex, index, valueType.GetHandle(), pValue, valueSize));
	}

	void Set(NInt listIndex, NInt index, NTypeOfProc pValueTypeOf, const void * pValue, NSizeType valueSize)
	{
		NCheck(Internal::NListListSetItemP(this, listIndex, index, pValueTypeOf, pValue, valueSize));
	}

	void Add(NInt listIndex, const void * pValue, NSizeType valueSize)
	{
		NCheck(Internal::NListListAddItem(this, listIndex, NULL, pValue, valueSize));
	}

	template<typename T> void Add(NInt listIndex, const T & value)
	{
		typename NTypeTraits<T>::NativeType v = NTypeTraits<T>::ToNative(value);
		NCheck(Internal::NListListAddItem(this, listIndex, NTypeTraits<T>::GetNativeType().GetHandle(), &v, sizeof(v)));
	}

	void Add(NInt listIndex, const NType & valueType, const void * pValue, NSizeType valueSize)
	{
		NCheck(Internal::NListListAddItem(this, listIndex, valueType.GetHandle(), pValue, valueSize));
	}

	void Add(NInt listIndex, NTypeOfProc pValueTypeOf, const void * pValue, NSizeType valueSize)
	{
		NCheck(Internal::NListListAddItemP(this, listIndex, pValueTypeOf, pValue, valueSize));
	}

	void AddRange(NInt listIndex, const void * pValues, NSizeType valuesSize, NInt valuesLength)
	{
		NCheck(Internal::NListListAddItemRange(this, listIndex, NULL, pValues, valuesSize, valuesLength));
	}

	template<typename T> void AddRange(NInt listIndex, const T * arValues, NInt valuesLength)
	{
		typename NTypeTraits<T>::NativeArrayType values(arValues, valuesLength, false);
		NCheck(Internal::NListListAddItemRange(this, listIndex, NTypeTraits<T>::GetNativeType().GetHandle(), values.GetPtr(),
			(NSizeType)valuesLength * sizeof(NTypeTraits<T>::NativeType), valuesLength));
	}

	void AddRange(NInt listIndex, const NType & valueType, const void * pValues, NSizeType valuesSize, NInt valuesLength)
	{
		NCheck(Internal::NListListAddItemRange(this, listIndex, valueType.GetHandle(), pValues, valuesSize, valuesLength));
	}

	void AddRange(NInt listIndex, NTypeOfProc pValueTypeOf, const void * pValues, NSizeType valuesSize, NInt valuesLength)
	{
		NCheck(Internal::NListListAddItemRangeP(this, listIndex, pValueTypeOf, pValues, valuesSize, valuesLength));
	}

	void AddList(NInt listIndex, NListList & srcList, NInt srcListIndex)
	{
		NCheck(Internal::NListListAddListListItems(this, listIndex, &srcList, srcListIndex));
	}

	void Insert(NInt listIndex, NInt index, const void * pValue, NSizeType valueSize)
	{
		NCheck(Internal::NListListInsertItem(this, listIndex, index, NULL, pValue, valueSize));
	}

	template<typename T> void Insert(NInt listIndex, NInt index, const T & value)
	{
		typename NTypeTraits<T>::NativeType v = NTypeTraits<T>::ToNative(value);
		NCheck(Internal::NListListInsertItem(this, listIndex, index, NTypeTraits<T>::GetNativeType().GetHandle(), &v, sizeof(v)));
	}

	void Insert(NInt listIndex, NInt index, const NType & valueType, const void * pValue, NSizeType valueSize)
	{
		NCheck(Internal::NListListInsertItem(this, listIndex, index, valueType.GetHandle(), pValue, valueSize));
	}

	void Insert(NInt listIndex, NInt index, NTypeOfProc pValueTypeOf, const void * pValue, NSizeType valueSize)
	{
		NCheck(Internal::NListListInsertItemP(this, listIndex, index, pValueTypeOf, pValue, valueSize));
	}

	void InsertRange(NInt listIndex, NInt index, const void * pValues, NSizeType valuesSize, NInt valuesLength)
	{
		NCheck(Internal::NListListInsertItemRange(this, listIndex, index, NULL, pValues, valuesSize, valuesLength));
	}

	template<typename T> void InsertRange(NInt listIndex, NInt index, const T * arValues, NInt valuesLength)
	{
		typename NTypeTraits<T>::NativeArrayType values(arValues, valuesLength, false);
		NCheck(Internal::NListListInsertItemRange(this, listIndex, index, NTypeTraits<T>::GetNativeType().GetHandle(), values.GetPtr(),
			(NSizeType)valuesLength * sizeof(NTypeTraits<T>::NativeType), valuesLength));
	}

	void InsertRange(NInt listIndex, NInt index, const NType & valueType, const void * pValues, NSizeType valuesSize, NInt valuesLength)
	{
		NCheck(Internal::NListListInsertItemRange(this, listIndex, index, valueType.GetHandle(), pValues, valuesSize, valuesLength));
	}

	void InsertRange(NInt listIndex, NInt index, NTypeOfProc pValueTypeOf, const void * pValues, NSizeType valuesSize, NInt valuesLength)
	{
		NCheck(Internal::NListListInsertItemRangeP(this, listIndex, index, pValueTypeOf, pValues, valuesSize, valuesLength));
	}

	void InsertList(NInt listIndex, NInt index, NListList & srcList, NInt srcListIndex)
	{
		NCheck(Internal::NListListInsertListListItems(this, listIndex, index, &srcList, srcListIndex));
	}

	void RemoveAt(NInt listIndex, NInt index)
	{
		NCheck(Internal::NListListRemoveItemAt(this, listIndex, index));
	}

	void RemoveRange(NInt listIndex, NInt index, NInt count)
	{
		NCheck(Internal::NListListRemoveItemRange(this, listIndex, index, count));
	}

	NInt Remove(NInt listIndex, const void * pValue, NSizeType valueSize)
	{
		NInt result;
		NCheck(Internal::NListListRemoveItem(this, listIndex, NULL, pValue, valueSize, &result));
		return result;
	}

	template<typename T> NInt Remove(NInt listIndex, const T & value)
	{
		typename NTypeTraits<T>::NativeType v = NTypeTraits<T>::ToNative(value);
		NInt result;
		NCheck(Internal::NListListRemoveItem(this, listIndex, NTypeTraits<T>::GetNativeType().GetHandle(), &v, sizeof(v), &result));
		return result;
	}

	NInt Remove(NInt listIndex, const NType & valueType, const void * pValue, NSizeType valueSize)
	{
		NInt result;
		NCheck(Internal::NListListRemoveItem(this, listIndex, valueType.GetHandle(), pValue, valueSize, &result));
		return result;
	}

	NInt Remove(NInt listIndex, NTypeOfProc pValueTypeOf, const void * pValue, NSizeType valueSize)
	{
		NInt result;
		NCheck(Internal::NListListRemoveItemP(this, listIndex, pValueTypeOf, pValue, valueSize, &result));
		return result;
	}

	void Clear(NInt listIndex)
	{
		NCheck(Internal::NListListClearItems(this, listIndex));
	}

	NInt CopyTo(NInt listIndex, NInt index, NInt count, void * pValues, NSizeType valuesSize, NInt valuesLength)
	{
		return NCheck(Internal::NListListCopyItemsToRange(this, listIndex, index, count, NULL, pValues, valuesSize, valuesLength));
	}

	template<typename T> NInt CopyTo(NInt listIndex, NInt index, NInt count, T * arValues, NInt valuesLength)
	{
		typename NTypeTraits<T>::NativeArrayType values(arValues ? valuesLength : 0);
		NInt realCount = NCheck(Internal::NListListCopyItemsToRange(this, listIndex, index, count, NTypeTraits<T>::GetNativeType().GetHandle(), arValues ? NTypeTraits<T>::GetNativeArray(values, arValues) : NULL,
			(NSizeType)valuesLength * sizeof(NTypeTraits<T>::NativeType), valuesLength));
		return values.CopyTo(arValues, valuesLength, realCount);
	}

	NInt CopyTo(NInt listIndex, NInt index, NInt count, const NType & valueType, void * pValues, NSizeType valuesSize, NInt valuesLength)
	{
		return NCheck(Internal::NListListCopyItemsToRange(this, listIndex, index, count, valueType.GetHandle(), pValues, valuesSize, valuesLength));
	}

	NInt CopyTo(NInt listIndex, NInt index, NInt count, NTypeOfProc pValueTypeOf, void * pValues, NSizeType valuesSize, NInt valuesLength)
	{
		return NCheck(Internal::NListListCopyItemsToRangeP(this, listIndex, index, count, pValueTypeOf, pValues, valuesSize, valuesLength));
	}

	NInt CopyTo(NInt listIndex, void * pValues, NSizeType valuesSize, NInt valuesLength)
	{
		return NCheck(Internal::NListListCopyItemsTo(this, listIndex, NULL, pValues, valuesSize, valuesLength));
	}

	template<typename T> NInt CopyTo(NInt listIndex, T * arValues, NInt valuesLength)
	{
		typename NTypeTraits<T>::NativeArrayType values(arValues ? valuesLength : 0);
		NInt count = NCheck(Internal::NListListCopyItemsTo(this, listIndex, NTypeTraits<T>::GetNativeType().GetHandle(), arValues ? NTypeTraits<T>::GetNativeArray(values, arValues) : NULL,
			(NSizeType)valuesLength * sizeof(NTypeTraits<T>::NativeType), valuesLength));
		return values.CopyTo(arValues, valuesLength, count);
	}

	NInt CopyTo(NInt listIndex, const NType & valueType, void * pValues, NSizeType valuesSize, NInt valuesLength)
	{
		return NCheck(Internal::NListListCopyItemsTo(this, listIndex, valueType.GetHandle(), pValues, valuesSize, valuesLength));
	}

	NInt CopyTo(NInt listIndex, NTypeOfProc pValueTypeOf, void * pValues, NSizeType valuesSize, NInt valuesLength)
	{
		return NCheck(Internal::NListListCopyItemsToP(this, listIndex, pValueTypeOf, pValues, valuesSize, valuesLength));
	}

	void * ToArray(NInt listIndex, NInt index, NInt count, NSizeType elementSize, NInt * pCount)
	{
		void * pValues;
		NCheck(Internal::NListListItemsToArrayRange(this, listIndex, index, count, elementSize, NULL, &pValues, pCount));
		return pValues;
	}

	template<typename T> NArrayWrapper<T> ToArray(NInt listIndex, NInt index, NInt count)
	{
		void * pValues;
		NInt realCount;
		NCheck(Internal::NListListItemsToArrayRange(this, listIndex, index, count, 0, NTypeTraits<T>::GetNativeType().GetHandle(), &pValues, &realCount));
		return NArrayWrapper<T>(pValues, realCount);
	}

	void * ToArray(NInt listIndex, NInt index, NInt count, const NType & valueType, NInt * pCount)
	{
		void * pValues;
		NCheck(Internal::NListListItemsToArrayRange(this, listIndex, index, count, 0, valueType.GetHandle(), &pValues, pCount));
		return pValues;
	}

	void * ToArray(NInt listIndex, NInt index, NInt count, NTypeOfProc pValueTypeOf, NInt * pCount)
	{
		void * pValues;
		NCheck(Internal::NListListItemsToArrayRangeP(this, listIndex, index, count, 0, pValueTypeOf, &pValues, pCount));
		return pValues;
	}

	void * ToArray(NInt listIndex, NSizeType elementSize, NInt * pCount)
	{
		void * pValues;
		NCheck(Internal::NListListItemsToArray(this, listIndex, elementSize, NULL, &pValues, pCount));
		return pValues;
	}

	template<typename T> NArrayWrapper<T> ToArray(NInt listIndex)
	{
		void * pValues;
		NInt count;
		NCheck(Internal::NListListItemsToArray(this, listIndex, 0, NTypeTraits<T>::GetNativeType().GetHandle(), &pValues, &count));
		return NArrayWrapper<T>(pValues, count);
	}

	void * ToArray(NInt listIndex, const NType & valueType, NInt * pCount)
	{
		void * pValues;
		NCheck(Internal::NListListItemsToArray(this, listIndex, 0, valueType.GetHandle(), &pValues, pCount));
		return pValues;
	}

	void * ToArray(NInt listIndex, NTypeOfProc pValueTypeOf, NInt * pCount)
	{
		void * pValues;
		NCheck(Internal::NListListItemsToArrayP(this, listIndex, 0, pValueTypeOf, &pValues, pCount));
		return pValues;
	}

	void * DetachArray(NInt listIndex, NSizeType elementSize, NInt * pCount)
	{
		void * pValues;
		NCheck(Internal::NListListDetachItemsArray(this, listIndex, elementSize, NULL, &pValues, pCount));
		return pValues;
	}

	template<typename T> NArrayWrapper<T> DetachArray(NInt listIndex)
	{
		void * pValues;
		NInt count;
		NCheck(Internal::NListListDetachItemsArray(this, listIndex, 0, NTypeTraits<T>::GetNativeType().GetHandle(), &pValues, &count));
		return NArrayWrapper<T>(pValues, count);
	}

	void * DetachArray(NInt listIndex, const NType & valueType, NInt * pCount)
	{
		void * pValues;
		NCheck(Internal::NListListDetachItemsArray(this, listIndex, 0, valueType.GetHandle(), &pValues, pCount));
		return pValues;
	}

	void * DetachArray(NInt listIndex, NTypeOfProc pValueTypeOf, NInt * pCount)
	{
		void * pValues;
		NCheck(Internal::NListListDetachItemsArrayP(this, listIndex, 0, pValueTypeOf, &pValues, pCount));
		return pValues;
	}
};

}}

#endif // !N_LIST_LIST_HPP_INCLUDED
