#ifndef N_LIST_HPP_INCLUDED
#define N_LIST_HPP_INCLUDED

#include <Core/NType.hpp>
namespace Neurotec { namespace Collections { namespace Internal
{
#include <Collections/NList.h>
}}}

namespace Neurotec { namespace Collections
{

class NList : private Internal::NList
{
	N_DECLARE_PRIMITIVE_CLASS(NList)

public:
	explicit NList(NSizeType elementSize)
	{
		NCheck(Internal::NListInit(this, elementSize, NULL));
	}

	template<typename T> NList()
	{
		NCheck(Internal::NListInit(this, 0, NTypeTraits<T>::GetNativeType().GetHandle()));
	}

	NList(const NType & elementType)
	{
		NCheck(Internal::NListInit(this, 0, elementType.GetHandle()));
	}

	NList(NTypeOfProc pElementTypeOf)
	{
		NCheck(Internal::NListInitP(this, 0, pElementTypeOf));
	}

	NList(NSizeType elementSize, NInt capacity)
	{
		NCheck(Internal::NListInitWithCapacity(this, elementSize, NULL, capacity));
	}

	template<typename T> NList(NInt capacity)
	{
		NCheck(Internal::NListInit(this, 0, NTypeTraits<T>::GetNativeType().GetHandle(), capacity));
	}

	NList(NSizeType elementSize, const NType & elementType, NInt capacity)
	{
		NCheck(Internal::NListInitWithCapacity(this, elementSize, elementType.GetHandle(), capacity));
	}

	NList(NTypeOfProc pElementTypeOf, NInt capacity)
	{
		NCheck(Internal::NListInitWithCapacityP(this, 0, pElementTypeOf, capacity));
	}

	NList(NInt capacity, NInt maxCapacity, NInt growthDelta, NSizeType alignment)
	{
		NCheck(Internal::NListInitEx(this, 0, NULL, capacity, maxCapacity, growthDelta, alignment));
	}

	template<typename T> NList(NInt capacity, NInt maxCapacity, NInt growthDelta, NSizeType alignment)
	{
		NCheck(Internal::NListInitEx(this, 0, NTypeTraits<T>::GetNativeType().GetHandle(), capacity, maxCapacity, growthDelta, alignment));
	}

	NList(const NType & elementType, NInt capacity, NInt maxCapacity, NInt growthDelta, NSizeType alignment)
	{
		NCheck(Internal::NListInitEx(this, 0, elementType.GetHandle(), capacity, maxCapacity, growthDelta, alignment));
	}

	NList(NTypeOfProc pElementTypeOf, NInt capacity, NInt maxCapacity, NInt growthDelta, NSizeType alignment)
	{
		NCheck(Internal::NListInitExP(this, 0, pElementTypeOf, capacity, maxCapacity, growthDelta, alignment));
	}

	~NList()
	{
		NCheck(Internal::NListDispose(this));
	}

	NInt GetCapacity()
	{
		NInt value;
		NCheck(Internal::NListGetCapacity(this, &value));
		return value;
	}

	void SetCapacity(NInt value)
	{
		NCheck(Internal::NListSetCapacity(this, value));
	}

	NInt GetCount()
	{
		NInt value;
		NCheck(Internal::NListGetCount(this, &value));
		return value;
	}

	void SetCount(NInt value)
	{
		NCheck(Internal::NListSetCount(this, value));
	}

	NInt IndexOf(const void * pValue, NSizeType valueSize, NInt startIndex, NInt count)
	{
		NInt result;
		NCheck(Internal::NListIndexOfInRange(this, NULL, pValue, valueSize, startIndex, count, &result));
		return result;
	}

	template<typename T> NInt IndexOf(const T & value, NInt startIndex, NInt count)
	{
		typename NTypeTraits<T>::NativeType v = NTypeTraits<T>::ToNative(value);
		NInt result;
		NCheck(Internal::NListIndexOfInRange(this, NTypeTraits<T>::GetNativeType().GetHandle(), &v, sizeof(v), startIndex, count, &result));
		return result;
	}

	NInt IndexOf(const NType & valueType, const void * pValue, NSizeType valueSize, NInt startIndex, NInt count)
	{
		NInt result;
		NCheck(Internal::NListIndexOfInRange(this, valueType.GetHandle(), pValue, valueSize, startIndex, count, &result));
		return result;
	}

	NInt IndexOf(NTypeOfProc pValueTypeOf, const void * pValue, NSizeType valueSize, NInt startIndex, NInt count)
	{
		NInt result;
		NCheck(Internal::NListIndexOfInRangeP(this, pValueTypeOf, pValue, valueSize, startIndex, count, &result));
		return result;
	}

	NInt IndexOf(const void * pValue, NSizeType valueSize, NInt startIndex)
	{
		NInt result;
		NCheck(Internal::NListIndexOfFrom(this, NULL, pValue, valueSize, startIndex, &result));
		return result;
	}

	template<typename T> NInt IndexOf(const T & value, NInt startIndex)
	{
		typename NTypeTraits<T>::NativeType v = NTypeTraits<T>::ToNative(value);
		NInt result;
		NCheck(Internal::NListIndexOfFrom(this, NTypeTraits<T>::GetNativeType().GetHandle(), &v, sizeof(v), startIndex, &result));
		return result;
	}

	NInt IndexOf(const NType & valueType, const void * pValue, NSizeType valueSize, NInt startIndex)
	{
		NInt result;
		NCheck(Internal::NListIndexOfFrom(this, valueType.GetHandle(), pValue, valueSize, startIndex, &result));
		return result;
	}

	NInt IndexOf(NTypeOfProc pValueTypeOf, const void * pValue, NSizeType valueSize, NInt startIndex)
	{
		NInt result;
		NCheck(Internal::NListIndexOfFromP(this, pValueTypeOf, pValue, valueSize, startIndex, &result));
		return result;
	}

	NInt IndexOf(const void * pValue, NSizeType valueSize)
	{
		NInt result;
		NCheck(Internal::NListIndexOf(this, NULL, pValue, valueSize, &result));
		return result;
	}

	template<typename T> NInt IndexOf(const T & value)
	{
		typename NTypeTraits<T>::NativeType v = NTypeTraits<T>::ToNative(value);
		NInt result;
		NCheck(Internal::NListIndexOf(this, NTypeTraits<T>::GetNativeType().GetHandle(), &v, sizeof(v), &result));
		return result;
	}

	NInt IndexOf(const NType & valueType, const void * pValue, NSizeType valueSize)
	{
		NInt result;
		NCheck(Internal::NListIndexOf(this, valueType.GetHandle(), pValue, valueSize, &result));
		return result;
	}

	NInt IndexOf(NTypeOfProc pValueTypeOf, const void * pValue, NSizeType valueSize)
	{
		NInt result;
		NCheck(Internal::NListIndexOfP(this, pValueTypeOf, pValue, valueSize, &result));
		return result;
	}

	NInt LastIndexOf(const void * pValue, NSizeType valueSize, NInt startIndex, NInt count)
	{
		NInt result;
		NCheck(Internal::NListLastIndexOfInRange(this, NULL, pValue, valueSize, startIndex, count, &result));
		return result;
	}

	template<typename T> NInt LastIndexOf(const T & value, NInt startIndex, NInt count)
	{
		typename NTypeTraits<T>::NativeType v = NTypeTraits<T>::ToNative(value);
		NInt result;
		NCheck(Internal::NListLastIndexOfInRange(this, NTypeTraits<T>::GetNativeType().GetHandle(), &v, sizeof(v), startIndex, count, &result));
		return result;
	}

	NInt LastIndexOf(const NType & valueType, const void * pValue, NSizeType valueSize, NInt startIndex, NInt count)
	{
		NInt result;
		NCheck(Internal::NListLastIndexOfInRange(this, valueType.GetHandle(), pValue, valueSize, startIndex, count, &result));
		return result;
	}

	NInt LastIndexOf(NTypeOfProc pValueTypeOf, const void * pValue, NSizeType valueSize, NInt startIndex, NInt count)
	{
		NInt result;
		NCheck(Internal::NListLastIndexOfInRangeP(this, pValueTypeOf, pValue, valueSize, startIndex, count, &result));
		return result;
	}

	NInt LastIndexOf(const void * pValue, NSizeType valueSize, NInt startIndex)
	{
		NInt result;
		NCheck(Internal::NListLastIndexOfFrom(this, NULL, pValue, valueSize, startIndex, &result));
		return result;
	}

	template<typename T> NInt LastIndexOf(const T & value, NInt startIndex)
	{
		typename NTypeTraits<T>::NativeType v = NTypeTraits<T>::ToNative(value);
		NInt result;
		NCheck(Internal::NListLastIndexOfFrom(this, NTypeTraits<T>::GetNativeType().GetHandle(), &v, sizeof(v), startIndex, &result));
		return result;
	}

	NInt LastIndexOf(const NType & valueType, const void * pValue, NSizeType valueSize, NInt startIndex)
	{
		NInt result;
		NCheck(Internal::NListLastIndexOfFrom(this, valueType.GetHandle(), pValue, valueSize, startIndex, &result));
		return result;
	}

	NInt LastIndexOf(NTypeOfProc pValueTypeOf, const void * pValue, NSizeType valueSize, NInt startIndex)
	{
		NInt result;
		NCheck(Internal::NListLastIndexOfFromP(this, pValueTypeOf, pValue, valueSize, startIndex, &result));
		return result;
	}

	NInt LastIndexOf(const void * pValue, NSizeType valueSize)
	{
		NInt result;
		NCheck(Internal::NListLastIndexOf(this, NULL, pValue, valueSize, &result));
		return result;
	}

	template<typename T> NInt LastIndexOf(const T & value)
	{
		typename NTypeTraits<T>::NativeType v = NTypeTraits<T>::ToNative(value);
		NInt result;
		NCheck(Internal::NListLastIndexOf(this, NTypeTraits<T>::GetNativeType().GetHandle(), &v, sizeof(v), &result));
		return result;
	}

	NInt LastIndexOf(const NType & valueType, const void * pValue, NSizeType valueSize)
	{
		NInt result;
		NCheck(Internal::NListLastIndexOf(this, valueType.GetHandle(), pValue, valueSize, &result));
		return result;
	}

	NInt LastIndexOf(NTypeOfProc pValueTypeOf, const void * pValue, NSizeType valueSize)
	{
		NInt result;
		NCheck(Internal::NListLastIndexOfP(this, pValueTypeOf, pValue, valueSize, &result));
		return result;
	}

	bool Contains(const void * pValue, NSizeType valueSize)
	{
		NBool result;
		NCheck(Internal::NListContains(this, NULL, pValue, valueSize, &result));
		return result != 0;
	}

	template<typename T> bool Contains(const T & value)
	{
		typename NTypeTraits<T>::NativeType v = NTypeTraits<T>::ToNative(value);
		NBool result;
		NCheck(Internal::NListContains(this, NTypeTraits<T>::GetNativeType().GetHandle(), &v, sizeof(v), &result));
		return result != 0;
	}

	bool Contains(const NType & valueType, const void * pValue, NSizeType valueSize)
	{
		NBool result;
		NCheck(Internal::NListContains(this, valueType.GetHandle(), pValue, valueSize, &result));
		return result != 0;
	}

	bool Contains(NTypeOfProc pValueTypeOf, const void * pValue, NSizeType valueSize)
	{
		NBool result;
		NCheck(Internal::NListContainsP(this, pValueTypeOf, pValue, valueSize, &result));
		return result != 0;
	}

	void * GetStart(NSizeType elementSize)
	{
		void * pValue;
		NCheck(Internal::NListGetStart(this, elementSize, NULL, &pValue));
		return pValue;
	}

	template<typename T> typename NTypeTraits<T>::NativeType * GetStart()
	{
		typename NTypeTraits<T>::NativeType * pValue;
		NCheck(Internal::NListGetStart(this, 0, NTypeTraits<T>::GetNativeType().GetHandle(), (void * *)&pValue));
		return pValue;
	}

	void * GetStart(const NType & elementType)
	{
		void * pValue;
		NCheck(Internal::NListGetStart(this, 0, elementType.GetHandle(), &pValue));
		return pValue;
	}

	void * GetStart(NTypeOfProc pElementTypeOf)
	{
		void * pValue;
		NCheck(Internal::NListGetStartP(this, 0, pElementTypeOf, &pValue));
		return pValue;
	}

	void * GetEnd(NSizeType elementSize)
	{
		void * pValue;
		NCheck(Internal::NListGetEnd(this, elementSize, NULL, &pValue));
		return pValue;
	}

	template<typename T> typename NTypeTraits<T>::NativeType * GetEnd()
	{
		typename NTypeTraits<T>::NativeType * pValue;
		NCheck(Internal::NListGetEnd(this, 0, NTypeTraits<T>::GetNativeType().GetHandle(), (void * *)&pValue));
		return pValue;
	}

	void * GetEnd(const NType & elementType)
	{
		void * pValue;
		NCheck(Internal::NListGetEnd(this, 0, elementType.GetHandle(), &pValue));
		return pValue;
	}

	void * GetEnd(NTypeOfProc pElementTypeOf)
	{
		void * pValue;
		NCheck(Internal::NListGetEndP(this, 0, pElementTypeOf, &pValue));
		return pValue;
	}

	void * GetPtr(NInt index, NSizeType elementSize)
	{
		void * pValue;
		NCheck(Internal::NListGetPtr(this, index, elementSize, NULL, &pValue));
		return pValue;
	}

	template<typename T> typename NTypeTraits<T>::NativeType * GetPtr(NInt index)
	{
		typename NTypeTraits<T>::NativeType * pValue;
		NCheck(Internal::NListGetPtr(this, index, 0, NTypeTraits<T>::GetNativeType().GetHandle(), (void * *)&pValue));
		return pValue;
	}

	void * GetPtr(NInt index, const NType & elementType)
	{
		void * pValue;
		NCheck(Internal::NListGetPtr(this, index, 0, elementType.GetHandle(), &pValue));
		return pValue;
	}

	void * GetPtr(NInt index, NTypeOfProc pElementTypeOf)
	{
		void * pValue;
		NCheck(Internal::NListGetPtrP(this, index, 0, pElementTypeOf, &pValue));
		return pValue;
	}

	void Get(NInt index, void * pValue, NSizeType valueSize)
	{
		NCheck(Internal::NListGet(this, index, NULL, pValue, valueSize));
	}

	template<typename T> T Get(NInt index)
	{
		typename NTypeTraits<T>::NativeType value;
		NCheck(Internal::NListGet(this, index, NTypeTraits<T>::GetNativeType().GetHandle(), &value, sizeof(value)));
		return NTypeTraits<T>::FromNative(value, true);
	}

	void Get(NInt index, const NType & valueType, void * pValue, NSizeType valueSize)
	{
		NCheck(Internal::NListGet(this, index, valueType.GetHandle(), pValue, valueSize));
	}

	void Get(NInt index, NTypeOfProc pValueTypeOf, void * pValue, NSizeType valueSize)
	{
		NCheck(Internal::NListGetP(this, index, pValueTypeOf, pValue, valueSize));
	}

	void Set(NInt index, const void * pValue, NSizeType valueSize)
	{
		NCheck(Internal::NListSet(this, index, NULL, pValue, valueSize));
	}

	template<typename T> void Set(NInt index, const T & value)
	{
		typename NTypeTraits<T>::NativeType v = NTypeTraits<T>::ToNative(value);
		NCheck(Internal::NListSet(this, index, NTypeTraits<T>::GetNativeType().GetHandle(), &v, sizeof(v)));
	}

	void Set(NInt index, const NType & valueType, const void * pValue, NSizeType valueSize)
	{
		NCheck(Internal::NListSet(this, index, valueType.GetHandle(), pValue, valueSize));
	}

	void Set(NInt index, NTypeOfProc pValueTypeOf, const void * pValue, NSizeType valueSize)
	{
		NCheck(Internal::NListSetP(this, index, pValueTypeOf, pValue, valueSize));
	}

	void Add(const void * pValue, NSizeType valueSize)
	{
		NCheck(Internal::NListAdd(this, NULL, pValue, valueSize));
	}

	template<typename T> void Add(const T & value)
	{
		typename NTypeTraits<T>::NativeType v = NTypeTraits<T>::ToNative(value);
		NCheck(Internal::NListAdd(this, NTypeTraits<T>::GetNativeType().GetHandle(), &v, sizeof(v)));
	}

	void Add(const NType & valueType, const void * pValue, NSizeType valueSize)
	{
		NCheck(Internal::NListAdd(this, valueType.GetHandle(), pValue, valueSize));
	}

	void Add(NTypeOfProc pValueTypeOf, const void * pValue, NSizeType valueSize)
	{
		NCheck(Internal::NListAddP(this, pValueTypeOf, pValue, valueSize));
	}

	void AddRange(const void * pValues, NSizeType valuesSize, NInt valuesLength)
	{
		NCheck(Internal::NListAddRange(this, NULL, pValues, valuesSize, valuesLength));
	}

	template<typename T> void AddRange(const T * arValues, NInt valuesLength)
	{
		typename NTypeTraits<T>::NativeArrayType values(arValues, valuesLength, false);
		NCheck(Internal::NListAddRange(this, NTypeTraits<T>::GetNativeType().GetHandle(), values.GetPtr(),
			(NSizeType)valuesLength * sizeof(NTypeTraits<T>::NativeType), valuesLength));
	}

	void AddRange(const NType & valueType, const void * pValues, NSizeType valuesSize, NInt valuesLength)
	{
		NCheck(Internal::NListAddRange(this, valueType.GetHandle(), pValues, valuesSize, valuesLength));
	}

	void AddRange(NTypeOfProc pValueTypeOf, const void * pValues, NSizeType valuesSize, NInt valuesLength)
	{
		NCheck(Internal::NListAddRangeP(this, pValueTypeOf, pValues, valuesSize, valuesLength));
	}

	void AddList(NList & srcList)
	{
		NCheck(Internal::NListAddList(this, &srcList));
	}

	void Insert(NInt index, const void * pValue, NSizeType valueSize)
	{
		NCheck(Internal::NListInsert(this, index, NULL, pValue, valueSize));
	}

	template<typename T> void Insert(NInt index, const T & value)
	{
		typename NTypeTraits<T>::NativeType v = NTypeTraits<T>::ToNative(value);
		NCheck(Internal::NListInsert(this, index, NTypeTraits<T>::GetNativeType().GetHandle(), &v, sizeof(v)));
	}

	void Insert(NInt index, const NType & valueType, const void * pValue, NSizeType valueSize)
	{
		NCheck(Internal::NListInsert(this, index, valueType.GetHandle(), pValue, valueSize));
	}

	void Insert(NInt index, NTypeOfProc pValueTypeOf, const void * pValue, NSizeType valueSize)
	{
		NCheck(Internal::NListInsertP(this, index, pValueTypeOf, pValue, valueSize));
	}

	void InsertRange(NInt index, const void * pValues, NSizeType valuesSize, NInt valuesLength)
	{
		NCheck(Internal::NListInsertRange(this, index, NULL, pValues, valuesSize, valuesLength));
	}

	template<typename T> void InsertRange(NInt index, const T * arValues, NInt valuesLength)
	{
		typename NTypeTraits<T>::NativeArrayType values(arValues, valuesLength, false);
		NCheck(Internal::NListInsertRange(this, index, NTypeTraits<T>::GetNativeType().GetHandle(), values.GetPtr(),
			(NSizeType)valuesLength * sizeof(NTypeTraits<T>::NativeType), valuesLength));
	}

	void InsertRange(NInt index, const NType & valueType, const void * pValues, NSizeType valuesSize, NInt valuesLength)
	{
		NCheck(Internal::NListInsertRange(this, index, valueType.GetHandle(), pValues, valuesSize, valuesLength));
	}

	void InsertRange(NInt index, NTypeOfProc pValueTypeOf, const void * pValues, NSizeType valuesSize, NInt valuesLength)
	{
		NCheck(Internal::NListInsertRangeP(this, index, pValueTypeOf, pValues, valuesSize, valuesLength));
	}

	void InsertList(NInt index, NList & srcList)
	{
		NCheck(Internal::NListInsertList(this, index, &srcList));
	}

	void RemoveAt(NInt index)
	{
		NCheck(Internal::NListRemoveAt(this, index));
	}

	void RemoveRange(NInt index, NInt count)
	{
		NCheck(Internal::NListRemoveRange(this, index, count));
	}

	NInt Remove(const void * pValue, NSizeType valueSize)
	{
		NInt result;
		NCheck(Internal::NListRemove(this, NULL, pValue, valueSize, &result));
		return result;
	}

	template<typename T> NInt Remove(const T & value)
	{
		typename NTypeTraits<T>::NativeType v = NTypeTraits<T>::ToNative(value);
		NInt result;
		NCheck(Internal::NListRemove(this, NTypeTraits<T>::GetNativeType().GetHandle(), &v, sizeof(v), &result));
		return result;
	}

	NInt Remove(const NType & valueType, const void * pValue, NSizeType valueSize)
	{
		NInt result;
		NCheck(Internal::NListRemove(this, valueType.GetHandle(), pValue, valueSize, &result));
		return result;
	}

	NInt Remove(NTypeOfProc pValueTypeOf, const void * pValue, NSizeType valueSize)
	{
		NInt result;
		NCheck(Internal::NListRemoveP(this, pValueTypeOf, pValue, valueSize, &result));
		return result;
	}

	void Clear()
	{
		NCheck(Internal::NListClear(this));
	}

	NInt CopyTo(NInt index, NInt count, void * pValues, NSizeType valuesSize, NInt valuesLength)
	{
		return NCheck(Internal::NListCopyToRange(this, index, count, NULL, pValues, valuesSize, valuesLength));
	}

	template<typename T> NInt CopyTo(NInt index, NInt count, T * arValues, NInt valuesLength)
	{
		typename NTypeTraits<T>::NativeArrayType values(arValues ? valuesLength : 0);
		NInt realCount = NCheck(Internal::NListCopyToRange(this, index, count, NTypeTraits<T>::GetNativeType().GetHandle(), arValues ? NTypeTraits<T>::GetNativeArray(values, arValues) : NULL,
			(NSizeType)valuesLength * sizeof(NTypeTraits<T>::NativeType), valuesLength));
		return values.CopyTo(arValues, valuesLength, realCount);
	}

	NInt CopyTo(NInt index, NInt count, const NType & valueType, void * pValues, NSizeType valuesSize, NInt valuesLength)
	{
		return NCheck(Internal::NListCopyToRange(this, index, count, valueType.GetHandle(), pValues, valuesSize, valuesLength));
	}

	NInt CopyTo(NInt index, NInt count, NTypeOfProc pValueTypeOf, void * pValues, NSizeType valuesSize, NInt valuesLength)
	{
		return NCheck(Internal::NListCopyToRangeP(this, index, count, pValueTypeOf, pValues, valuesSize, valuesLength));
	}

	NInt CopyTo(void * pValues, NSizeType valuesSize, NInt valuesLength)
	{
		return NCheck(Internal::NListCopyTo(this, NULL, pValues, valuesSize, valuesLength));
	}

	template<typename T> NInt CopyTo(T * arValues, NInt valuesLength)
	{
		typename NTypeTraits<T>::NativeArrayType values(arValues ? valuesLength : 0);
		NInt count = NCheck(Internal::NListCopyTo(this, NTypeTraits<T>::GetNativeType().GetHandle(), arValues ? NTypeTraits<T>::GetNativeArray(values, arValues) : NULL,
			(NSizeType)valuesLength * sizeof(NTypeTraits<T>::NativeType), valuesLength));
		return values.CopyTo(arValues, valuesLength, count);
	}

	NInt CopyTo(const NType & valueType, void * pValues, NSizeType valuesSize, NInt valuesLength)
	{
		return NCheck(Internal::NListCopyTo(this, valueType.GetHandle(), pValues, valuesSize, valuesLength));
	}

	NInt CopyTo(NTypeOfProc pValueTypeOf, void * pValues, NSizeType valuesSize, NInt valuesLength)
	{
		return NCheck(Internal::NListCopyToP(this, pValueTypeOf, pValues, valuesSize, valuesLength));
	}

	void * ToArray(NInt index, NInt count, NSizeType elementSize, NInt * pCount)
	{
		void * pValues;
		NCheck(Internal::NListToArrayRange(this, index, count, elementSize, NULL, &pValues, pCount));
		return pValues;
	}

	template<typename T> NArrayWrapper<T> ToArray(NInt index, NInt count)
	{
		void * pValues;
		NInt realCount;
		NCheck(Internal::NListToArrayRange(this, index, count, 0, NTypeTraits<T>::GetNativeType().GetHandle(), &pValues, &realCount));
		return NArrayWrapper<T>(pValues, realCount);
	}

	void * ToArray(NInt index, NInt count, const NType & valueType, NInt * pCount)
	{
		void * pValues;
		NCheck(Internal::NListToArrayRange(this, index, count, 0, valueType.GetHandle(), &pValues, pCount));
		return pValues;
	}

	void * ToArray(NInt index, NInt count, NTypeOfProc pValueTypeOf, NInt * pCount)
	{
		void * pValues;
		NCheck(Internal::NListToArrayRangeP(this, index, count, 0, pValueTypeOf, &pValues, pCount));
		return pValues;
	}

	void * ToArray(NSizeType elementSize, NInt * pCount)
	{
		void * pValues;
		NCheck(Internal::NListToArray(this, elementSize, NULL, &pValues, pCount));
		return pValues;
	}

	template<typename T> NArrayWrapper<T> ToArray()
	{
		void * pValues;
		NInt count;
		NCheck(Internal::NListToArray(this, 0, NTypeTraits<T>::GetNativeType().GetHandle(), &pValues, &count));
		return NArrayWrapper<T>(pValues, count);
	}

	void * ToArray(const NType & valueType, NInt * pCount)
	{
		void * pValues;
		NCheck(Internal::NListToArray(this, 0, valueType.GetHandle(), &pValues, pCount));
		return pValues;
	}

	void * ToArray(NTypeOfProc pValueTypeOf, NInt * pCount)
	{
		void * pValues;
		NCheck(Internal::NListToArrayP(this, 0, pValueTypeOf, &pValues, pCount));
		return pValues;
	}

	void * DetachArray(NSizeType elementSize, NInt * pCount)
	{
		void * pValues;
		NCheck(Internal::NListDetachArray(this, elementSize, NULL, &pValues, pCount));
		return pValues;
	}

	template<typename T> NArrayWrapper<T> DetachArray()
	{
		void * pValues;
		NInt count;
		NCheck(Internal::NListDetachArray(this, 0, NTypeTraits<T>::GetNativeType().GetHandle(), &pValues, &count));
		return NArrayWrapper<T>(pValues, count);
	}

	void * DetachArray(const NType & valueType, NInt * pCount)
	{
		void * pValues;
		NCheck(Internal::NListDetachArray(this, 0, valueType.GetHandle(), &pValues, pCount));
		return pValues;
	}

	void * DetachArray(NTypeOfProc pValueTypeOf, NInt * pCount)
	{
		void * pValues;
		NCheck(Internal::NListDetachArrayP(this, 0, pValueTypeOf, &pValues, pCount));
		return pValues;
	}
};

}}

#endif // !N_LIST_HPP_INCLUDED
