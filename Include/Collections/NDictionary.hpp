#include <Collections/NCollection.hpp>

#ifndef N_DICTIONARY_HPP_INCLUDED
#define N_DICTIONARY_HPP_INCLUDED

namespace Neurotec { namespace Collections
{
#include <Collections/NDictionary.h>
}}

namespace Neurotec { namespace Collections
{

class NDictionary : public NObjectPart
{
	N_DECLARE_OBJECT_CLASS(NDictionary, NObjectPart)

public:
	typedef NCollectionIterator<NDictionary, NKeyValuePair> iterator;
	typedef NConstCollectionIterator<NDictionary, NKeyValuePair> const_iterator;
	typedef NCollectionIterator<NDictionary, NKeyValuePair> reverse_iterator;
	typedef NConstCollectionIterator<NDictionary, NKeyValuePair> reverse_const_iterator;

	class KeyCollection : public ::Neurotec::Collections::NCollectionWithAllOutBase<NValue, NDictionary,
		NDictionaryGetCount, NDictionaryGetKeyN, NDictionaryGetKeysN>
	{
		KeyCollection(const NDictionary & owner)
		{
			SetOwner(owner);
		}

	public:
		void Get(NInt index, const NType & keyType, NAttributes keyAttributes, void * pKey, NSizeType keySize) const
		{
			NCheck(NDictionaryGetKey(this->GetOwnerHandle(), index, keyType.GetHandle(), keyAttributes, pKey, keySize));
		}

		template<typename TKey>
		TKey Get(NInt index, NAttributes keyAttributes = naNone) const
		{
			typename NTypeTraits<TKey>::NativeType key;
			NCheck(NDictionaryGetKey(this->GetOwnerHandle(), index, NTypeTraits<TKey>::GetNativeType().GetHandle(), keyAttributes, &key, sizeof(key)));
			return NTypeTraits<TKey>::FromNative(key, true);
		}

		NArray ToItemArray() const
		{
			HNArray hKeys;
			NCheck(NDictionaryToKeyArray(this->GetOwnerHandle(), &hKeys));
			return FromHandle<NArray>(hKeys);
		}

		template<typename TKey>
		NArrayWrapper<TKey> ToArray(NAttributes keyAttributes = naNone) const
		{
			typename NTypeTraits<TKey>::NativeType * arKeys;
			NInt keyCount;
			NCheck(NDictionaryGetKeys(this->GetOwnerHandle(), NTypeTraits<TKey>::GetNativeType().GetHandle(), keyAttributes, sizeof(typename NTypeTraits<TKey>::NativeType), (void * *)&arKeys, &keyCount));
			return NArrayWrapper<TKey>(arKeys, keyCount);
		}

		friend class NDictionary;
	};

	class ValueCollection : public ::Neurotec::Collections::NCollectionWithAllOutBase<NValue, NDictionary,
		NDictionaryGetCount, NDictionaryGetValueN, NDictionaryGetValuesN>
	{
		ValueCollection(const NDictionary & owner)
		{
			SetOwner(owner);
		}

	public:
		void Get(NInt index, const NType & valueType, NAttributes valueAttributes, void * pValue, NSizeType valueSize) const
		{
			NCheck(NDictionaryGetValue(this->GetOwnerHandle(), index, valueType.GetHandle(), valueAttributes, pValue, valueSize));
		}

		template<typename TValue>
		TValue Get(NInt index, NAttributes valueAttributes = naNone) const
		{
			typename NTypeTraits<TValue>::NativeType value;
			NCheck(NDictionaryGetValue(this->GetOwnerHandle(), index, NTypeTraits<TValue>::GetNativeType().GetHandle(), valueAttributes, &value, sizeof(value)));
			return NTypeTraits<TValue>::FromNative(value, true);
		}

		NArray ToItemArray() const
		{
			HNArray hValues;
			NCheck(NDictionaryToValueArray(this->GetOwnerHandle(), &hValues));
			return FromHandle<NArray>(hValues);
		}

		template<typename TValue>
		NArrayWrapper<TValue> ToArray(NAttributes valueAttributes = naNone) const
		{
			typename NTypeTraits<TValue>::NativeType * arValues;
			NInt valueCount;
			NCheck(NDictionaryGetValues(this->GetOwnerHandle(), NTypeTraits<TValue>::GetNativeType().GetHandle(), valueAttributes, sizeof(typename NTypeTraits<TValue>::NativeType), (void * *)&arValues, &valueCount));
			return NArrayWrapper<TValue>(arValues, valueCount);
		}

		friend class NDictionary;
	};

private:
	template<typename F>
	class CollectionChangedCallbackKeyValue : public EventHandlerBase<F>
	{
	public:
		CollectionChangedCallbackKeyValue(F f)
			: EventHandlerBase<F>(f)
		{
		}

		static NResult N_API NativeCallback(HNObject hObject, NCollectionChangedAction action, NInt newIndex, NKeyValuePair * arNewItems, NInt newItemCount,
			NInt oldIndex, NKeyValuePair * arOldItems, NInt oldItemCount, void * pParam)
		{
			NResult result = N_OK;
			try
			{
				CollectionChangedCallbackKeyValue<F> * p = reinterpret_cast<CollectionChangedCallbackKeyValue<F> *>(pParam);
				NArrayWrapper<NKeyValuePair> newItems(arNewItems, newItemCount, false, false);
				NArrayWrapper<NKeyValuePair> oldItems(arOldItems, oldItemCount, false, false);
				p->f(p->pTarget, action, newIndex, newItems, oldIndex, oldItems);
			}
			N_EXCEPTION_CATCH_AND_SET_LAST(result);
			return result;
		};
	};

public:
	static NType NDictionaryCollectionChangedCallbackNativeTypeOf()
	{
		return NObject::GetObject<NType>(N_TYPE_OF(NDictionaryCollectionChangedCallback), true);
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
		NCheck(NDictionaryIsReadOnly(GetHandle(), &value));
		return value != 0;
	}

	NInt GetCount() const
	{
		NInt value;
		NCheck(NDictionaryGetCount(GetHandle(), &value));
		return value;
	}

	NKeyValuePair GetAt(NInt index) const
	{
		NKeyValuePair item;
		NCheck(NDictionaryGetAtN(GetHandle(), index, &item));
		return item;
	}

	NValue GetItemAt(NInt index) const
	{
		HNValue hItem;
		NCheck(NDictionaryGetItemAt(GetHandle(), index, &hItem));
		return FromHandle<NValue>(hItem);
	}

	void GetAt(NInt index, const NType & itemType, NAttributes itemAttributes, void * pItem, NSizeType itemSize) const
	{
		NCheck(NDictionaryGetAt(GetHandle(), index, itemType.GetHandle(), itemAttributes, pItem, itemSize));
	}

	template<typename TItem> TItem GetAt(NInt index, NAttributes itemAttributes = naNone) const
	{
		typename NTypeTraits<TItem>::NativeType item;
		NCheck(NDictionaryGetAt(GetHandle(), index, NTypeTraits<TItem>::GetNativeType().GetHandle(), itemAttributes, &item, sizeof(item)));
		return NTypeTraits<TItem>::FromNative(item, true);
	}

	NArrayWrapper<NKeyValuePair> ToArray() const
	{
		struct NKeyValuePair_ * arItems;
		NInt itemCount;
		NCheck(NDictionaryToArrayN(GetHandle(), &arItems, &itemCount));
		NArrayWrapper<NKeyValuePair> items(static_cast<NKeyValuePair *>(arItems), itemCount);
		return items;
	}

	NArray ToItemArray() const
	{
		HNArray hItems;
		NCheck(NDictionaryToItemArray(GetHandle(), &hItems));
		return FromHandle<NArray>(hItems);
	}

	template<typename TItem> NArrayWrapper<TItem> ToArray(NAttributes itemAttributes = naNone) const
	{
		typename NTypeTraits<TItem>::NativeType * arItems;
		NInt itemCount;
		NCheck(NDictionaryToArray(GetHandle(), NTypeTraits<TItem>::GetNativeType().GetHandle(), itemAttributes, sizeof(NTypeTraits<TItem>::NativeType), &arItems, &itemCount));
		return NArrayWrapper<TItem>(arItems, itemCount);
	}

	void Add(const NKeyValuePair & item)
	{
		NCheck(NDictionaryAddPairN(GetHandle(), &item));
	}

	void Add(const NValue & item)
	{
		NCheck(NDictionaryAddItemPair(GetHandle(), item.GetHandle()));
	}

	void Add(const NType & itemType, NAttributes itemAttributes, const void * pItem, NSizeType itemSize)
	{
		NCheck(NDictionaryAddPair(GetHandle(), itemType.GetHandle(), itemAttributes, pItem, itemSize));
	}

	template<typename TItem> void Add(const TItem & item, NAttributes itemAttributes = naNone)
	{
		typename NTypeTraits<TItem>::NativeType i = NTypeTraits<TItem>::ToNative(item);
		NCheck(NDictionaryAddPair(GetHandle(), NTypeTraits<TItem>::GetNativeType().GetHandle(), itemAttributes, &i, sizeof(i)));
	}

	void RemoveAt(NInt index)
	{
		NCheck(NDictionaryRemoveAt(GetHandle(), index));
	}

	void Clear()
	{
		NCheck(NDictionaryClear(GetHandle()));
	}

	bool Contains(const NValue & key) const
	{
		NBool result;
		NCheck(NDictionaryContainsN(GetHandle(), key.GetHandle(), &result));
		return result != 0;
	}

	bool Contains(const NType & keyType, NAttributes keyAttributes, const void * pKey, NSizeType keySize) const
	{
		NBool result;
		NCheck(NDictionaryContains(GetHandle(), keyType.GetHandle(), keyAttributes, pKey, keySize, &result));
		return result != 0;
	}

	template<typename TKey> bool Contains(const TKey & key, NAttributes keyAttributes = naNone) const
	{
		typename NTypeTraits<TKey>::NativeType k = NTypeTraits<TKey>::ToNative(key);
		NBool result;
		NCheck(NDictionaryContainsP(GetHandle(), NTypeTraits<TKey>::GetNativeType().GetHandle(), keyAttributes, &k, sizeof(k), &result));
		return result != 0;
	}

	NValue Get(const NValue & key) const
	{
		HNValue hValue;
		NCheck(NDictionaryGetN(GetHandle(), key.GetHandle(), &hValue));
		return FromHandle<NValue>(hValue);
	}

	void Get(const NType & keyType, NAttributes keyAttributes, const void * pKey, NSizeType keySize, const NType & valueType, NAttributes valueAttributes, void * pValue, NSizeType valueSize) const
	{
		NCheck(NDictionaryGet(GetHandle(), keyType.GetHandle(), keyAttributes, pKey, keySize, valueType.GetHandle(), valueAttributes, pValue, valueSize));
	}

	template<typename TKey, typename TValue> TValue Get(const TKey & key, NAttributes keyAttributes = naNone, NAttributes valueAttributes = naNone) const
	{
		typename NTypeTraits<TKey>::NativeType k = NTypeTraits<TKey>::ToNative(key);
		typename NTypeTraits<TValue>::NativeType v;
		NCheck(NDictionaryGet(GetHandle(), NTypeTraits<TKey>::GetNativeType().GetHandle(), keyAttributes, &k, sizeof(k), NTypeTraits<TValue>::GetNativeType().GetHandle(), valueAttributes, &v, sizeof(v)));
		return NTypeTraits<TValue>::FromNative(v, true);
	}

	bool TryGet(const NValue & key, NValue * pValue) const
	{
		HNValue hValue;
		NBool result;
		if (!pValue) NThrowArgumentNullException(N_T("pValue"));
		NCheck(NDictionaryTryGetN(GetHandle(), key.GetHandle(), &hValue, &result));
		*pValue = FromHandle<NValue>(hValue);
		return result != 0;
	}

	bool TryGet(const NType & keyType, NAttributes keyAttributes, const void * pKey, NSizeType keySize, const NType & valueType, NAttributes valueAttributes, void * pValue, NSizeType valueSize) const
	{
		NBool result;
		NCheck(NDictionaryTryGet(GetHandle(), keyType.GetHandle(), keyAttributes, pKey, keySize, valueType.GetHandle(), valueAttributes, pValue, valueSize, &result));
		return result != 0;
	}

	template<typename TKey, typename TValue> bool TryGet(const TKey & key, TValue * pValue, NAttributes keyAttributes = naNone, NAttributes valueAttributes = naNone) const
	{
		if (!pValue) NThrowArgumentNullException(N_T("pValue"));
		typename NTypeTraits<TKey>::NativeType k = NTypeTraits<TKey>::ToNative(key);
		typename NTypeTraits<TValue>::NativeType v;
		NBool result;
		NCheck(NDictionaryTryGet(GetHandle(), NTypeTraits<TKey>::GetNativeType().GetHandle(), keyAttributes, &k, sizeof(k), NTypeTraits<TValue>::GetNativeType().GetHandle(), valueAttributes, &v, sizeof(v), &result));
		*pValue = NTypeTraits<TValue>::FromNative(v, true);
		return result != 0;
	}

	void Add(const NValue & key, const NValue & value)
	{
		NCheck(NDictionaryAddN(GetHandle(), key.GetHandle(), value.GetHandle()));
	}

	void Add(const NType & keyType, NAttributes keyAttributes, const void * pKey, NSizeType keySize, const NType & valueType, NAttributes valueAttributes, const void * pValue, NSizeType valueSize)
	{
		NCheck(NDictionaryAdd(GetHandle(), keyType.GetHandle(), keyAttributes, pKey, keySize, valueType.GetHandle(), valueAttributes, pValue, valueSize));
	}

	template<typename TKey, typename TValue> void Add(const TKey & key, const TValue & value, NAttributes keyAttributes = naNone, NAttributes valueAttributes = naNone)
	{
		typename NTypeTraits<TKey>::NativeType k = NTypeTraits<TKey>::ToNative(key);
		typename NTypeTraits<TValue>::NativeType v = NTypeTraits<TValue>::ToNative(value);
		NCheck(NDictionaryAdd(GetHandle(), NTypeTraits<TKey>::GetNativeType().GetHandle(), keyAttributes, &k, sizeof(k), NTypeTraits<TValue>::GetNativeType().GetHandle(), valueAttributes, &v, sizeof(v)));
	}

	void Set(const NValue & key, const NValue & value)
	{
		NCheck(NDictionarySetN(GetHandle(), key.GetHandle(), value.GetHandle()));
	}

	void Set(const NType & keyType, NAttributes keyAttributes, const void * pKey, NSizeType keySize, const NType & valueType, NAttributes valueAttributes, const void * pValue, NSizeType valueSize)
	{
		NCheck(NDictionarySet(GetHandle(), keyType.GetHandle(), keyAttributes, pKey, keySize, valueType.GetHandle(), valueAttributes, pValue, valueSize));
	}

	template<typename TKey, typename TValue> void Set(const TKey & key, const TValue & value, NAttributes keyAttributes = naNone, NAttributes valueAttributes = naNone)
	{
		typename NTypeTraits<TKey>::NativeType k = NTypeTraits<TKey>::ToNative(key);
		typename NTypeTraits<TValue>::NativeType v = NTypeTraits<TValue>::ToNative(value);
		NCheck(NDictionarySet(GetHandle(), NTypeTraits<TKey>::GetNativeType().GetHandle(), keyAttributes, &k, sizeof(k), NTypeTraits<TValue>::GetNativeType().GetHandle(), valueAttributes, &v, sizeof(v)));
	}

	bool Remove(const NValue & key)
	{
		NInt result;
		NCheck(NDictionaryRemoveN(GetHandle(), key.GetHandle(), &result));
		return result != 0;
	}

	bool Remove(const NType & keyType, NAttributes keyAttributes, const void * pKey, NSizeType keySize)
	{
		NBool result;
		NCheck(NDictionaryRemove(GetHandle(), keyType.GetHandle(), keyAttributes, pKey, keySize, &result));
		return result != 0;
	}

	template<typename TKey> bool Remove(const TKey & key, NAttributes keyAttributes = naNone)
	{
		typename NTypeTraits<TKey>::NativeType k = NTypeTraits<TKey>::ToNative(key);
		NInt result;
		NCheck(NDictionaryRemove(GetHandle(), NTypeTraits<TKey>::GetNativeType().GetHandle(), keyAttributes, &k, sizeof(k), &result));
		return result != 0;
	}

	const KeyCollection GetKeys() const
	{
		return KeyCollection(*this);
	}

	const ValueCollection GetValues() const
	{
		return ValueCollection(*this);
	}

	NKeyValuePair operator[](NInt index) const
	{
		return GetAt(index);
	}

	NValue operator[](NValue & key) const
	{
		return Get(key);
	}

	void AddCollectionChangedCallback(const NCallback & callback)
	{
		NCheck(NDictionaryAddCollectionChanged(GetHandle(), callback.GetHandle()));
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
		NCheck(NDictionaryRemoveCollectionChanged(GetHandle(), callback.GetHandle()));
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
		NCheck(NDictionaryAddItemCollectionChanged(GetHandle(), callback.GetHandle()));
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
		NCheck(NDictionaryRemoveItemCollectionChanged(GetHandle(), callback.GetHandle()));
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

#endif // !N_DICTIONARY_HPP_INCLUDED
