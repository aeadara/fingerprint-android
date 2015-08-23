#include <Core/NValue.hpp>
#include <Collections/NCollection.hpp>
#include <Collections/NCollections.hpp>

#ifndef N_PROPERTY_BAG_HPP_INCLUDED
#define N_PROPERTY_BAG_HPP_INCLUDED

namespace Neurotec
{
using ::Neurotec::Collections::NCollectionChangedAction;
#include <Core/NPropertyBag.h>
}

namespace Neurotec
{

class NPropertyBag : public NObject
{
	N_DECLARE_OBJECT_CLASS(NPropertyBag, NObject)

public:
	typedef NCollectionIterator<NPropertyBag, NNameValuePair> iterator;
	typedef NConstCollectionIterator<NPropertyBag, NNameValuePair> const_iterator;
	typedef NCollectionIterator<NPropertyBag, NNameValuePair> reverse_iterator;
	typedef NConstCollectionIterator<NPropertyBag, NNameValuePair> reverse_const_iterator;

	class KeyCollection : public ::Neurotec::Collections::NCollectionWithAllOutBase<NString, NPropertyBag,
		NPropertyBagGetCount, NPropertyBagGetKey, NPropertyBagGetKeys>
	{
		KeyCollection(const NPropertyBag & owner)
		{
			SetOwner(owner);
		}

	public:
		bool Contains(const NString & value) const
		{
			return GetOwner()->Contains(value);
		}

		bool Contains(const NStringWrapper & value) const
		{
			return GetOwner()->Contains(value);
		}

		friend class NPropertyBag;
	};

	class ValueCollection : public ::Neurotec::Collections::NCollectionWithAllOutBase<NValue, NPropertyBag,
		NPropertyBagGetCount, NPropertyBagGetValue, NPropertyBagGetValues>
	{
		ValueCollection(const NPropertyBag & owner)
		{
			SetOwner(owner);
		}

	protected:
		friend class NPropertyBag;
	};

private:
	static HNPropertyBag Create()
	{
		HNPropertyBag handle;
		NCheck(NPropertyBagCreate(&handle));
		return handle;
	}

public:
	static bool TryParse(const NStringWrapper & value, const NStringWrapper & format, NPropertyBag * pValue)
	{
		if (!pValue) NThrowArgumentNullException(N_T("pValue"));
		NBool result;
		HNPropertyBag hValue;
		NCheck(NPropertyBagTryParseN(value.GetHandle(), format.GetHandle(), &hValue, &result));
		*pValue = FromHandle<NPropertyBag>(hValue);
		return result != 0;
	}
	static bool TryParse(const NStringWrapper & value, NPropertyBag * pValue)
	{
		return TryParse(value, NString(), pValue);
	}

	static NPropertyBag Parse(const NStringWrapper & value, const NStringWrapper & format = NString())
	{
		HNPropertyBag hValue;
		NCheck(NPropertyBagParseN(value.GetHandle(), format.GetHandle(), &hValue));
		return FromHandle<NPropertyBag>(hValue);
	}

	NPropertyBag()
		: NObject(Create(), true)
	{
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

	NInt GetCount() const
	{
		NInt value;
		NCheck(NPropertyBagGetCount(GetHandle(), &value));
		return value;
	}

	NNameValuePair Get(NInt index) const
	{
		NNameValuePair value;
		NCheck(NPropertyBagGetAt(GetHandle(), index, &value));
		return value;
	}

	NArrayWrapper<NNameValuePair> ToArray() const
	{
		struct NNameValuePair_ * arValues;
		NInt valueCount;
		NCheck(NPropertyBagToArray(GetHandle(), &arValues, &valueCount));
		return NArrayWrapper<NNameValuePair>(arValues, valueCount);
	}

	void Add(const NNameValuePair & value)
	{
		NCheck(NPropertyBagAddPair(GetHandle(), &value));
	}

	void RemoveAt(NInt index)
	{
		NCheck(NPropertyBagRemoveAt(GetHandle(), index));
	}

	void Clear()
	{
		NCheck(NPropertyBagClear(GetHandle()));
	}

	bool Contains(const NStringWrapper & key) const
	{
		NBool result;
		NCheck(NPropertyBagContainsN(GetHandle(), key.GetHandle(), &result));
		return result != 0;
	}

	NValue Get(const NStringWrapper & key) const
	{
		HNValue hValue;
		NCheck(NPropertyBagGetN(GetHandle(), key.GetHandle(), &hValue));
		return FromHandle<NValue>(hValue);
	}

	bool TryGet(const NStringWrapper & key, NValue * pValue) const
	{
		if (!pValue) NThrowArgumentNullException(N_T("pValue"));
		HNValue hValue;
		NBool result;
		NCheck(NPropertyBagTryGetN(GetHandle(), key.GetHandle(), &hValue, &result));
		*pValue = FromHandle<NValue>(hValue);
		return result != 0;
	}

	void Add(const NStringWrapper & key, const NValue & value)
	{
		NCheck(NPropertyBagAddN(GetHandle(), key.GetHandle(), value.GetHandle()));
	}

	void Set(const NStringWrapper & key, const NValue & value)
	{
		NCheck(NPropertyBagSetN(GetHandle(), key.GetHandle(), value.GetHandle()));
	}

	bool Remove(const NStringWrapper & key)
	{
		NBool result;
		NCheck(NPropertyBagRemoveN(GetHandle(), key.GetHandle(), &result));
		return result != 0;
	}

	void CopyTo(const NPropertyBag & otherPropertyBag) const
	{
		NCheck(NPropertyBagCopyTo(GetHandle(), otherPropertyBag.GetHandle()));
	}

	void ApplyTo(const NObject & object) const
	{
		NCheck(NPropertyBagApplyTo(GetHandle(), object.GetHandle()));
	}

	const KeyCollection GetKeys() const
	{
		return KeyCollection(*this);
	}

	const ValueCollection GetValues() const
	{
		return ValueCollection(*this);
	}

	NNameValuePair operator[](NInt index) const
	{
		return Get(index);
	}

	NValue operator[](const NStringWrapper & key) const
	{
		return Get(key);
	}

	void AddCollectionChangedCallback(const NCallback & callback);
	template<typename CallbackType>
	NCallback AddCollectionChangedCallback(const CallbackType & callback, void * pParam = NULL);
	void RemoveCollectionChangedCallback(const NCallback & callback);
	template<typename CallbackType>
	NCallback RemoveCollectionChangedCallback(const CallbackType & callback, void * pParam = NULL);
};

}

#include <Core/NTypes.hpp>

namespace Neurotec
{

inline void NPropertyBag::AddCollectionChangedCallback(const NCallback & callback)
{
	NCheck(NPropertyBagAddCollectionChanged(GetHandle(), callback.GetHandle()));
}

template<typename CallbackType>
inline NCallback NPropertyBag::AddCollectionChangedCallback(const CallbackType & callback, void * pParam)
{
	NCallback cb = NTypes::CreateCallback<Collections::CollectionChangedEventHandler<NNameValuePair, CallbackType> >(callback, pParam);
	AddCollectionChangedCallback(cb);
	return cb;
}

inline void NPropertyBag::RemoveCollectionChangedCallback(const NCallback & callback)
{
	NCheck(NPropertyBagRemoveCollectionChanged(GetHandle(), callback.GetHandle()));
}

template<typename CallbackType>
inline NCallback NPropertyBag::RemoveCollectionChangedCallback(const CallbackType & callback, void * pParam)
{
	NCallback cb = NTypes::CreateCallback<Collections::CollectionChangedEventHandler<NNameValuePair, CallbackType> >(callback, pParam);
	RemoveCollectionChangedCallback(cb);
	return cb;
}

}
#endif // !N_PROPERTY_BAG_HPP_INCLUDED
