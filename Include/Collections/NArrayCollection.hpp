#include <Core/NObjectPart.hpp>
#include <Core/NArray.hpp>
#include <Core/NError.hpp>

#ifndef N_ARRAY_COLLECTION_HPP_INCLUDED
#define N_ARRAY_COLLECTION_HPP_INCLUDED

namespace Neurotec { namespace Collections
{
#include <Collections/NArrayCollection.h>
}}

namespace Neurotec { namespace Collections
{

class NArrayCollection : public NObjectPart
{
	N_DECLARE_OBJECT_CLASS(NArrayCollection, NObjectPart)

public:
	bool IsReadOnly() const
	{
		NBool value;
		NCheck(NArrayCollectionIsReadOnly(GetHandle(), &value));
		return value != 0;
	}

	NInt GetBaseCount() const
	{
		NInt value;
		NCheck(NArrayCollectionGetBaseCount(GetHandle(), &value));
		return value;
	}

	NInt GetCount(NInt baseIndex) const
	{
		NInt value;
		NCheck(NArrayCollectionGetCount(GetHandle(), baseIndex, &value));
		return value;
	}

	NValue Get(NInt baseIndex, NInt index) const
	{
		HNValue hValue;
		NCheck(NArrayCollectionGetN(GetHandle(), baseIndex, index, &hValue));
		return FromHandle<NValue>(hValue);
	}

	void Get(NInt baseIndex, NInt index, const NType & valueType, NAttributes attributes, void * pValue, NSizeType valueSize) const
	{
		NCheck(NArrayCollectionGet(GetHandle(), baseIndex, index, valueType.GetHandle(), attributes, pValue, valueSize));
	}

	template<typename T> T Get(NInt baseIndex, NInt index, NAttributes attributes = naNone) const
	{
		typename NTypeTraits<T>::NativeType value;
		NCheck(NArrayCollectionGet(GetHandle(), baseIndex, index, NTypeTraits<T>::GetNativeType().GetHandle(), attributes, &value, sizeof(value)));
		return NTypeTraits<T>::FromNative(value, true);
	}

	NArrayWrapper<NValue> ToArray(NInt baseIndex) const
	{
		HNValue * arhValues;
		NInt valueCount;
		NCheck(NArrayCollectionToArrayN(GetHandle(), baseIndex, &arhValues, &valueCount));
		return NArrayWrapper<NValue>(arhValues, valueCount);
	}

	NArray ToItemArray(NInt baseIndex) const
	{
		HNArray hValue;
		NCheck(NArrayCollectionToItemArray(GetHandle(), baseIndex, &hValue));
		return FromHandle<NArray>(hValue);
	}

	template<typename T> NArrayWrapper<T> ToArray(NInt baseIndex, NAttributes attributes = naNone) const
	{
		typename NTypeTraits<T>::NativeType * arValues;
		NInt valueCount;
		NCheck(NArrayCollectionToArray(GetHandle(), baseIndex, NTypeTraits<T>::GetNativeType().GetHandle(), attributes, sizeof(NTypeTraits<T>::NativeType), &arValues, &valueCount));
		return NArrayWrapper<T>(arValues, valueCount);
	}

	void Set(NInt baseIndex, NInt index, const NValue & value)
	{
		NCheck(NArrayCollectionSetN(GetHandle(), baseIndex, index, value.GetHandle()));
	}

	void Set(NInt baseIndex, NInt index, const NType & valueType, NAttributes attributes, const void * pValue, NSizeType valueSize)
	{
		NCheck(NArrayCollectionSet(GetHandle(), baseIndex, index, valueType.GetHandle(), attributes, pValue, valueSize));
	}

	template<typename T> void Set(NInt baseIndex, NInt index, const T & value, NAttributes attributes = naNone)
	{
		typename NTypeTraits<T>::NativeType v = NTypeTraits<T>::ToNative(value);
		NCheck(NArrayCollectionSet(GetHandle(), baseIndex, index, NTypeTraits<T>::GetNativeType().GetHandle(), attributes, &v, sizeof(v)));
	}

	NInt Add(NInt baseIndex, const NValue & value)
	{
		NInt index;
		NCheck(NArrayCollectionAddN(GetHandle(), baseIndex, value.GetHandle(), &index));
		return index;
	}

	NInt Add(NInt baseIndex, const NType & valueType, NAttributes attributes, const void * pValue, NSizeType valueSize)
	{
		NInt index;
		NCheck(NArrayCollectionAdd(GetHandle(), baseIndex, valueType.GetHandle(), attributes, pValue, valueSize, &index));
		return index;
	}

	template<typename T> NInt Add(NInt baseIndex, const T & value, NAttributes attributes = naNone)
	{
		typename NTypeTraits<T>::NativeType v = NTypeTraits<T>::ToNative(value);
		NInt index;
		NCheck(NArrayCollectionAdd(GetHandle(), baseIndex, NTypeTraits<T>::GetNativeType().GetHandle(), attributes, &v, sizeof(v), &index));
		return index;
	}

	template<typename InputIt>
	NInt AddRange(NInt baseIndex, InputIt first, InputIt last)
	{
		NArrayWrapper<NValue> values(first, last);
		NInt index;
		NCheck(NArrayCollectionAddRangeN(GetHandle(), baseIndex, values.GetPtr(), values.GetCount(), &index));
		return index;
	}

	NInt AddRange(NInt baseIndex, const NArray & values)
	{
		NInt index;
		NCheck(NArrayCollectionAddItemRange(GetHandle(), baseIndex, values.GetHandle(), &index));
		return index;
	}

	NInt AddRange(NInt baseIndex, const NType & valueType, NAttributes attributes, const void * arValues, NSizeType valuesSize, NInt valueCount)
	{
		NInt index;
		NCheck(NArrayCollectionAddRange(GetHandle(), baseIndex, valueType.GetHandle(), attributes, arValues, valuesSize, valueCount, &index));
		return index;
	}

	template<typename T> NInt AddRange(NInt baseIndex, const T * arValues, NInt valueCount, NAttributes attributes = naNone)
	{
		typename NTypeTraits<T>::NativeArrayType values(arValues, valueCount, false);
		NInt index;
		NCheck(NArrayCollectionAddRange(GetHandle(), baseIndex, NTypeTraits<T>::GetNativeType().GetHandle(), attributes, values.GetPtr(), values.GetSize(), values.GetCount(), &index));
		return index;
	}

	void Insert(NInt baseIndex, NInt index, const NValue & value)
	{
		NCheck(NArrayCollectionInsertN(GetHandle(), baseIndex, index, value.GetHandle()));
	}

	void Insert(NInt baseIndex, NInt index, const NType & valueType, NAttributes attributes, const void * pValue, NSizeType valueSize)
	{
		NCheck(NArrayCollectionInsert(GetHandle(), baseIndex, index, valueType.GetHandle(), attributes, pValue, valueSize));
	}

	template<typename T> void Insert(NInt baseIndex, NInt index, const T & value, NAttributes attributes = naNone)
	{
		typename NTypeTraits<T>::NativeType v = NTypeTraits<T>::ToNative(value);
		NCheck(NArrayCollectionInsert(GetHandle(), baseIndex, index, NTypeTraits<T>::GetNativeType().GetHandle(), attributes, &v, sizeof(v)));
	}

	template<typename InputIt>
	void InsertRange(NInt baseIndex, NInt index, InputIt first, InputIt last)
	{
		NArrayWrapper<NValue> values(first, last);
		NCheck(NArrayCollectionInsertRangeN(GetHandle(), baseIndex, index, values.GetPtr(), values.GetCount()));
	}

	void InsertRange(NInt baseIndex, NInt index, const NArray & values)
	{
		NCheck(NArrayCollectionInsertItemRange(GetHandle(), baseIndex, index, values.GetHandle()));
	}

	void InsertRange(NInt baseIndex, NInt index, const NType & valueType, NAttributes attributes, const void * arValues, NSizeType valuesSize, NInt valueCount)
	{
		NCheck(NArrayCollectionInsertRange(GetHandle(), baseIndex, index, valueType.GetHandle(), attributes, arValues, valuesSize, valueCount));
	}

	template<typename T> void InsertRange(NInt baseIndex, NInt index, const T * arValues, NInt valueCount, NAttributes attributes = naNone)
	{
		typename NTypeTraits<T>::NativeArrayType values(arValues, valueCount, false);
		NCheck(NArrayCollectionInsertRange(GetHandle(), baseIndex, index, NTypeTraits<T>::GetNativeType().GetHandle(), attributes, values.GetPtr(), values.GetSize(), values.GetCount()));
	}

	NInt Remove(NInt baseIndex, const NValue & value)
	{
		NInt index;
		NCheck(NArrayCollectionRemoveN(GetHandle(), baseIndex, value.GetHandle(), &index));
		return index;
	}

	NInt Remove(NInt baseIndex, const NType & valueType, NAttributes attributes, const void * pValue, NSizeType valueSize)
	{
		NInt index;
		NCheck(NArrayCollectionRemove(GetHandle(), baseIndex, valueType.GetHandle(), attributes, pValue, valueSize, &index));
		return index;
	}

	template<typename T> NInt Remove(NInt baseIndex, const T & value, NAttributes attributes = naNone)
	{
		typename NTypeTraits<T>::NativeType v = NTypeTraits<T>::ToNative(value);
		NInt index;
		NCheck(NArrayCollectionRemove(GetHandle(), baseIndex, NTypeTraits<T>::GetNativeType().GetHandle(), attributes, &v, sizeof(v), &index));
		return index;
	}

	void RemoveAt(NInt baseIndex, NInt index)
	{
		NCheck(NArrayCollectionRemoveAt(GetHandle(), baseIndex, index));
	}

	void RemoveRange(NInt baseIndex, NInt startIndex, NInt count)
	{
		NCheck(NArrayCollectionRemoveRange(GetHandle(), baseIndex, startIndex, count));
	}

	void Clear(NInt baseIndex)
	{
		NCheck(NArrayCollectionClear(GetHandle(), baseIndex));
	}

	NInt IndexOf(NInt baseIndex, const NValue & value) const
	{
		NInt index;
		NCheck(NArrayCollectionIndexOfN(GetHandle(), baseIndex, value.GetHandle(), &index));
		return index;
	}

	NInt IndexOf(NInt baseIndex, const NType & valueType, NAttributes attributes, const void * pValue, NSizeType valueSize) const
	{
		NInt index;
		NCheck(NArrayCollectionIndexOf(GetHandle(), baseIndex, valueType.GetHandle(), attributes, pValue, valueSize, &index));
		return index;
	}

	template<typename T> NInt IndexOf(NInt baseIndex, const T & value, NAttributes attributes = naNone) const
	{
		typename NTypeTraits<T>::NativeType v = NTypeTraits<T>::ToNative(value);
		NInt index;
		NCheck(NArrayCollectionIndexOf(GetHandle(), baseIndex, NTypeTraits<T>::GetNativeType().GetHandle(), attributes, &v, sizeof(v), &index));
		return index;
	}

	bool Contains(NInt baseIndex, const NValue & value) const
	{
		NBool result;
		NCheck(NArrayCollectionContainsN(GetHandle(), baseIndex, value.GetHandle(), &result));
		return result != 0;
	}

	bool Contains(NInt baseIndex, const NType & valueType, NAttributes attributes, const void * pValue, NSizeType valueSize) const
	{
		NBool result;
		NCheck(NArrayCollectionContains(GetHandle(), baseIndex, valueType.GetHandle(), attributes, pValue, valueSize, &result));
		return result != 0;
	}

	template<typename T> bool Contains(NInt baseIndex, const T & value, NAttributes attributes = naNone)
	{
		typename NTypeTraits<T>::NativeType v = NTypeTraits<T>::ToNative(value);
		NBool result;
		NCheck(NArrayCollectionContains(GetHandle(), baseIndex, NTypeTraits<T>::GetNativeType().GetHandle(), attributes, &v, sizeof(v), &result));
		return result != 0;
	}
};

}}

#endif // !N_ARRAY_COLLECTION_HPP_INCLUDED
