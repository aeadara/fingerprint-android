#include <Core/NObjectPart.hpp>
#include <Core/NArray.hpp>
#include <Core/NError.hpp>
#include <iterator>

#ifndef N_COLLECTION_HPP_INCLUDED
#define N_COLLECTION_HPP_INCLUDED

namespace Neurotec { namespace Collections
{
#include <Collections/NCollection.h>
}}

N_DEFINE_ENUM_TYPE_TRAITS(Neurotec::Collections, NCollectionChangedAction)

namespace Neurotec { namespace Collections
{

class NCollection : public NObjectPart
{
	N_DECLARE_OBJECT_CLASS(NCollection, NObjectPart)

public:
	typedef NCollectionIterator<NCollection, NValue> iterator;
	typedef NConstCollectionIterator<NCollection, NValue> const_iterator;
	typedef NCollectionIterator<NCollection, NValue> reverse_iterator;
	typedef NConstCollectionIterator<NCollection, NValue> reverse_const_iterator;

public:

	static NType NCollectionChangedActionNativeTypeOf()
	{
		return NObject::GetObject<NType>(N_TYPE_OF(NCollectionChangedAction), true);
	}

	static NType NCollectionCollectionChangedCallbackNativeTypeOf()
	{
		return NObject::GetObject<NType>(N_TYPE_OF(NCollectionCollectionChangedCallback), true);
	}

	static NType NCollectionItemCollectionChangedCallbackNativeTypeOf()
	{
		return NObject::GetObject<NType>(N_TYPE_OF(NCollectionItemCollectionChangedCallback), true);
	}

	iterator begin()
	{
		return iterator(*this, 0);
	}

	const_iterator begin() const
	{
		return const_iterator(*this, 0);
	}

	iterator end()
	{
		return iterator(*this, GetCount());
	}

	const_iterator end() const
	{
		return const_iterator(*this, GetCount());
	}

	reverse_iterator rbegin()
	{
		return reverse_iterator(*this, GetCount() - 1, true);
	}

	reverse_const_iterator rbegin() const
	{
		return reverse_const_iterator(*this, GetCount() - 1, true);
	}

	reverse_iterator rend()
	{
		return reverse_iterator(*this, 0, true);
	}

	reverse_const_iterator rend() const
	{
		return reverse_const_iterator(*this, 0, true);
	}

	bool IsReadOnly() const
	{
		NBool value;
		NCheck(NCollectionIsReadOnly(GetHandle(), &value));
		return value != 0;
	}

	NInt GetCount() const
	{
		NInt value;
		NCheck(NCollectionGetCount(GetHandle(), &value));
		return value;
	}

	NInt GetCapacity() const
	{
		NInt value;
		NCheck(NCollectionGetCapacity(GetHandle(), &value));
		return value;
	}

	void SetCapacity(NInt value)
	{
		NCheck(NCollectionSetCapacity(GetHandle(), value));
	}

	NValue Get(NInt index) const
	{
		HNValue hValue;
		NCheck(NCollectionGetN(GetHandle(), index, &hValue));
		return FromHandle<NValue>(hValue);
	}

	void Get(NInt index, const NType & valueType, NAttributes attributes, void * pValue, NSizeType valueSize) const
	{
		NCheck(NCollectionGet(GetHandle(), index, valueType.GetHandle(), attributes, pValue, valueSize));
	}

	template<typename T> T Get(NInt index, NAttributes attributes = naNone) const
	{
		typename NTypeTraits<T>::NativeType value;
		NCheck(NCollectionGet(GetHandle(), index, NTypeTraits<T>::GetNativeType().GetHandle(), attributes, &value, sizeof(value)));
		return NTypeTraits<T>::FromNative(value, true);
	}

	NArrayWrapper<NValue> ToArray() const
	{
		HNValue * arhValues;
		NInt valueCount;
		NCheck(NCollectionToArrayN(GetHandle(), &arhValues, &valueCount));
		return NArrayWrapper<NValue>(arhValues, valueCount);
	}

	NArray ToItemArray() const
	{
		HNArray hValue;
		NCheck(NCollectionToItemArray(GetHandle(), &hValue));
		return FromHandle<NArray>(hValue);
	}

	template<typename T> NArrayWrapper<T> ToArray(NAttributes attributes = naNone) const
	{
		typename NTypeTraits<T>::NativeType * arValues;
		NInt valueCount;
		NCheck(NCollectionToArray(GetHandle(), NTypeTraits<T>::GetNativeType().GetHandle(), attributes, sizeof(NTypeTraits<T>::NativeType), (void * *)&arValues, &valueCount));
		return NArrayWrapper<T>(arValues, valueCount);
	}

	void Set(NInt index, const NValue & value)
	{
		NCheck(NCollectionSetN(GetHandle(), index, value.GetHandle()));
	}

	void Set(NInt index, const NType & valueType, NAttributes attributes, const void * pValue, NSizeType valueSize)
	{
		NCheck(NCollectionSet(GetHandle(), index, valueType.GetHandle(), attributes, pValue, valueSize));
	}

	template<typename T> void Set(NInt index, const T & value, NAttributes attributes = naNone)
	{
		typename NTypeTraits<T>::NativeType v = NTypeTraits<T>::ToNative(value);
		NCheck(NCollectionSet(GetHandle(), index, NTypeTraits<T>::GetNativeType().GetHandle(), attributes, &v, sizeof(v)));
	}

	NInt Add(const NValue & value)
	{
		NInt index;
		NCheck(NCollectionAddN(GetHandle(), value.GetHandle(), &index));
		return index;
	}

	NInt Add(const NType & valueType, NAttributes attributes, const void * pValue, NSizeType valueSize)
	{
		NInt index;
		NCheck(NCollectionAdd(GetHandle(), valueType.GetHandle(), attributes, pValue, valueSize, &index));
		return index;
	}

	template<typename T> NInt Add(const T & value, NAttributes attributes = naNone)
	{
		typename NTypeTraits<T>::NativeType v = NTypeTraits<T>::ToNative(value);
		NInt index;
		NCheck(NCollectionAdd(GetHandle(), NTypeTraits<T>::GetNativeType().GetHandle(), attributes, &v, sizeof(v), &index));
		return index;
	}

	template<typename InputIt>
	NInt AddRange(InputIt first, InputIt last)
	{
		NArrayWrapper<NValue> values(first, last);
		NInt index;
		NCheck(NCollectionAddRangeN(GetHandle(), values.GetPtr(), values.GetCount(), &index));
		return index;
	}

	NInt AddRange(const NArray & values)
	{
		NInt index;
		NCheck(NCollectionAddItemRange(GetHandle(), values.GetHandle(), &index));
		return index;
	}

	NInt AddRange(const NType & valueType, NAttributes attributes, const void * arValues, NSizeType valuesSize, NInt valueCount)
	{
		NInt index;
		NCheck(NCollectionAddRange(GetHandle(), valueType.GetHandle(), attributes, arValues, valuesSize, valueCount, &index));
		return index;
	}

	template<typename T> NInt AddRange(const T * arValues, NInt valueCount, NAttributes attributes = naNone)
	{
		typename NTypeTraits<T>::NativeArrayType values(arValues, valueCount, false);
		NInt index;
		NCheck(NCollectionAddRange(GetHandle(), NTypeTraits<T>::GetNativeType().GetHandle(), attributes, values.GetPtr(), values.GetSize(), values.GetCount(), &index));
		return index;
	}

	void Insert(NInt index, const NValue & value)
	{
		NCheck(NCollectionInsertN(GetHandle(), index, value.GetHandle()));
	}

	void Insert(NInt index, const NType & valueType, NAttributes attributes, const void * pValue, NSizeType valueSize)
	{
		NCheck(NCollectionInsert(GetHandle(), index, valueType.GetHandle(), attributes, pValue, valueSize));
	}

	template<typename T> void Insert(NInt index, const T & value, NAttributes attributes = naNone)
	{
		typename NTypeTraits<T>::NativeType v = NTypeTraits<T>::ToNative(value);
		NCheck(NCollectionInsert(GetHandle(), index, NTypeTraits<T>::GetNativeType().GetHandle(), attributes, &v, sizeof(v)));
	}

	template<typename InputIt>
	void InsertRange(NInt index, InputIt first, InputIt last)
	{
		NArrayWrapper<NValue> values(first, last);
		NCheck(NCollectionInsertRangeN(GetHandle(), index, values.GetPtr(), values.GetCount()));
	}

	void InsertRange(NInt index, const NArray & values)
	{
		NCheck(NCollectionInsertItemRange(GetHandle(), index, values.GetHandle()));
	}

	void InsertRange(NInt index, const NType & valueType, NAttributes attributes, const void * arValues, NSizeType valuesSize, NInt valueCount)
	{
		NCheck(NCollectionInsertRange(GetHandle(), index, valueType.GetHandle(), attributes, arValues, valuesSize, valueCount));
	}

	template<typename InputIt>
	void InsertRange(NInt index, InputIt first, InputIt last, NAttributes attributes = naNone)
	{
		typedef typename std::iterator_traits<InputIt>::value_type T;
		NArrayWrapper<T> values(first, last);
		NCheck(NCollectionInsertRange(GetHandle(), index, NTypeTraits<T>::GetNativeType().GetHandle(), attributes, values.GetPtr(), values.GetSize(), values.GetCount()));
	}

	NInt Remove(const NValue & value)
	{
		NInt index;
		NCheck(NCollectionRemoveN(GetHandle(), value.GetHandle(), &index));
		return index;
	}

	NInt Remove(const NType & valueType, NAttributes attributes, const void * pValue, NSizeType valueSize)
	{
		NInt index;
		NCheck(NCollectionRemove(GetHandle(), valueType.GetHandle(), attributes, pValue, valueSize, &index));
		return index;
	}

	template<typename T> NInt Remove(const T & value, NAttributes attributes = naNone)
	{
		typename NTypeTraits<T>::NativeType v = NTypeTraits<T>::ToNative(value);
		NInt index;
		NCheck(NCollectionRemove(GetHandle(), NTypeTraits<T>::GetNativeType().GetHandle(), attributes, &v, sizeof(v), &index));
		return index;
	}

	void RemoveAt(NInt index)
	{
		NCheck(NCollectionRemoveAt(GetHandle(), index));
	}

	void RemoveRange(NInt startIndex, NInt count)
	{
		NCheck(NCollectionRemoveRange(GetHandle(), startIndex, count));
	}

	void Clear()
	{
		NCheck(NCollectionClear(GetHandle()));
	}

	NInt IndexOf(const NValue & value) const
	{
		NInt index;
		NCheck(NCollectionIndexOfN(GetHandle(), value.GetHandle(), &index));
		return index;
	}

	NInt IndexOf(const NType & valueType, NAttributes attributes, const void * pValue, NSizeType valueSize) const
	{
		NInt index;
		NCheck(NCollectionIndexOf(GetHandle(), valueType.GetHandle(), attributes, pValue, valueSize, &index));
		return index;
	}

	template<typename T> NInt IndexOf(const T & value, NAttributes attributes = naNone) const
	{
		typename NTypeTraits<T>::NativeType v = NTypeTraits<T>::ToNative(value);
		NInt index;
		NCheck(NCollectionIndexOf(GetHandle(), NTypeTraits<T>::GetNativeType().GetHandle(), attributes, &v, sizeof(v), &index));
		return index;
	}

	bool Contains(const NValue & value) const
	{
		NBool result;
		NCheck(NCollectionContainsN(GetHandle(), value.GetHandle(), &result));
		return result != 0;
	}

	bool Contains(const NType & valueType, NAttributes attributes, const void * pValue, NSizeType valueSize) const
	{
		NBool result;
		NCheck(NCollectionContains(GetHandle(), valueType.GetHandle(), attributes, pValue, valueSize, &result));
		return result != 0;
	}

	template<typename T> bool Contains(const T & value, NAttributes attributes = naNone) const
	{
		typename NTypeTraits<T>::NativeType v = NTypeTraits<T>::ToNative(value);
		NBool result;
		NCheck(NCollectionContains(GetHandle(), NTypeTraits<T>::GetNativeType().GetHandle(), attributes, &v, sizeof(v), &result));
		return result != 0;
	}

	void AddCollectionChangedCallback(const NCallback & callback)
	{
		NCheck(NCollectionAddCollectionChanged(GetHandle(), callback.GetHandle()));
	}

	template<typename F>
	NCallback AddCollectionChangedCallback(const F & callback, void * pParam = NULL)
	{
		NCallback cb = NTypes::CreateCallback<CollectionChangedEventHandler<NValue, F> >(callback, pParam);
		AddCollectionChangedCallback(cb);
		return cb;
	}

	void RemoveCollectionChangedCallback(const NCallback & callback)
	{
		NCheck(NCollectionRemoveCollectionChanged(GetHandle(), callback.GetHandle()));
	}

	template<typename F>
	NCallback RemoveCollectionChangedCallback(const F & callback, void * pParam = NULL)
	{
		NCallback cb = NTypes::CreateCallback<CollectionChangedEventHandler<NValue, F> >(callback, pParam);
		RemoveCollectionChangedCallback(cb);
		return cb;
	}

	void AddItemCollectionChangedCallback(const NCallback & callback)
	{
		NCheck(NCollectionAddItemCollectionChanged(GetHandle(), callback.GetHandle()));
	}

	template<typename F>
	NCallback AddItemCollectionChangedCallback(const F & callback, void * pParam = NULL)
	{
		NCallback cb = NTypes::CreateCallback<ItemCollectionChangedEventHandler<F> >(callback, pParam);
		AddItemCollectionChangedCallback(cb);
		return cb;
	}

	void RemoveItemCollectionChangedCallback(const NCallback & callback)
	{
		NCheck(NCollectionRemoveItemCollectionChanged(GetHandle(), callback.GetHandle()));
	}

	template<typename F>
	NCallback RemoveItemCollectionChangedCallback(const F & callback, void * pParam = NULL)
	{
		NCallback cb = NTypes::CreateCallback<ItemCollectionChangedEventHandler<F> >(callback, pParam);
		RemoveItemCollectionChangedCallback(cb);
		return cb;
	}
};

}}

#endif // !N_COLLECTION_HPP_INCLUDED
