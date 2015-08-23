#ifndef N_PARAMETER_BAG_HPP_INCLUDED
#define N_PARAMETER_BAG_HPP_INCLUDED

#include <ComponentModel/NParameterDescriptor.hpp>
#include <Core/NPropertyBag.hpp>
#include <Collections/NCollections.hpp>
namespace Neurotec { namespace ComponentModel
{
#include <ComponentModel/NParameterBag.h>
}}

namespace Neurotec { namespace ComponentModel
{

class NParameterBag : public NObject
{
	N_DECLARE_OBJECT_CLASS(NParameterBag, NObject)

public:
	typedef NCollectionIterator<NParameterBag, NNameValuePair> iterator;
	typedef NConstCollectionIterator<NParameterBag, NNameValuePair> const_iterator;
	typedef NCollectionIterator<NParameterBag, NNameValuePair> reverse_iterator;
	typedef NConstCollectionIterator<NParameterBag, NNameValuePair> reverse_const_iterator;

	class KeyCollection : public ::Neurotec::Collections::NCollectionWithAllOutBase<NString, NParameterBag,
		NParameterBagGetCount, NParameterBagGetKey, NParameterBagGetKeys>
	{
		KeyCollection(const NParameterBag & owner)
		{
			SetOwner(owner);
		}

		friend class NParameterBag;
	};

	class ValueCollection : public ::Neurotec::Collections::NCollectionWithAllOutBase<NValue, NParameterBag,
		NParameterBagGetCount, NParameterBagGetValue, NParameterBagGetValues>
	{
		ValueCollection(const NParameterBag & owner)
		{
			SetOwner(owner);
		}

		friend class NParameterBag;

	public:
		void Set(NInt index, const NValue & value)
		{
			NCheck(NParameterBagSetValue(this->GetOwnerHandle(), index, value.GetHandle()));
		}
	};

private:
	template<typename InputIt>
	static HNParameterBag Create(InputIt first, InputIt last)
	{
		NArrayWrapper<NParameterDescriptor> parameters(first, last);
		HNParameterBag handle;
		NCheck(NParameterBagCreate(parameters.GetPtr(), parameters.GetCount(), &handle));
		return handle;
	}

public:
	template<typename InputIt>
	NParameterBag(InputIt first, InputIt last)
		: NObject(Create(first, last), true)
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
		NCheck(NParameterBagGetCount(GetHandle(), &value));
		return value;
	}

	NNameValuePair Get(NInt index) const
	{
		NNameValuePair value;
		NCheck(NParameterBagGetAt(GetHandle(), index, &value));
		return value;
	}

	NArrayWrapper<NNameValuePair> ToArray() const
	{
		struct NNameValuePair_ * arValues;
		NInt valueCount;
		NCheck(NParameterBagToArray(GetHandle(), &arValues, &valueCount));
		return NArrayWrapper<NNameValuePair>(arValues, valueCount);
	}

	bool Contains(const NStringWrapper & key) const
	{
		NBool result;
		NCheck(NParameterBagContainsN(GetHandle(), key.GetHandle(), &result));
		return result != 0;
	}

	NValue Get(const NStringWrapper & key) const
	{
		HNValue hValue;
		NCheck(NParameterBagGetN(GetHandle(), key.GetHandle(), &hValue));
		return FromHandle<NValue>(hValue);
	}

	bool TryGet(const NStringWrapper & key, NValue * pValue) const
	{
		if (!pValue) NThrowArgumentNullException(N_T("pValue"));
		HNValue hValue;
		NBool result;
		NCheck(NParameterBagTryGetN(GetHandle(), key.GetHandle(), &hValue, &result));
		*pValue = FromHandle<NValue>(hValue);
		return result != 0;
	}

	void Set(const NStringWrapper & key, const NValue & value)
	{
		NCheck(NParameterBagSetN(GetHandle(), key.GetHandle(), value.GetHandle()));
	}

	void Apply(const NPropertyBag & value, bool ignoreUnknown = false)
	{
		NCheck(NParameterBagApplyPropertyBag(GetHandle(), value.GetHandle(), ignoreUnknown ? NTrue : NFalse));
	}

	NPropertyBag ToPropertyBag() const
	{
		HNPropertyBag hValue;
		NCheck(NParameterBagToPropertyBag(GetHandle(), &hValue));
		return FromHandle<NPropertyBag>(hValue);
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
};

}}

#endif // !N_PARAMETER_BAG_HPP_INCLUDED
