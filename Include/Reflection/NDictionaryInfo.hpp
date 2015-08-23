#include <Reflection/NObjectPartInfo.hpp>

#ifndef N_DICTIONARY_INFO_HPP_INCLUDED
#define N_DICTIONARY_INFO_HPP_INCLUDED

namespace Neurotec { namespace Reflection
{
#include <Reflection/NDictionaryInfo.h>
}}

namespace Neurotec { namespace Reflection
{

class NDictionaryInfo : public NObjectPartInfo
{
	N_DECLARE_OBJECT_CLASS(NDictionaryInfo, NObjectPartInfo)

public:
	class KeyStdValueCollection : public ::Neurotec::Collections::NCollectionWithAllOutBase<NNameValuePair, NDictionaryInfo,
		NDictionaryInfoGetKeyStdValueCount, NDictionaryInfoGetKeyStdValue, NDictionaryInfoGetKeyStdValues>
	{
		KeyStdValueCollection(const NDictionaryInfo & owner)
		{
			SetOwner(owner);
		}

		friend class NDictionaryInfo;
	};

	class ValueStdValueCollection : public ::Neurotec::Collections::NCollectionWithAllOutBase<NNameValuePair, NDictionaryInfo,
		NDictionaryInfoGetValueStdValueCount, NDictionaryInfoGetValueStdValue, NDictionaryInfoGetValueStdValues>
	{
		ValueStdValueCollection(const NDictionaryInfo & owner)
		{
			SetOwner(owner);
		}

		friend class NDictionaryInfo;
	};

public:
	NType GetItemType() const
	{
		return GetObject<HandleType, NType>(NDictionaryInfoGetItemType, true);
	}

	NAttributes GetItemAttributes() const
	{
		NAttributes value;
		NCheck(NDictionaryInfoGetItemAttributes(GetHandle(), &value));
		return value;
	}

	NType GetKeyType() const
	{
		return GetObject<HandleType, NType>(NDictionaryInfoGetKeyType, true);
	}

	NAttributes GetKeyAttributes() const
	{
		NAttributes value;
		NCheck(NDictionaryInfoGetKeyAttributes(GetHandle(), &value));
		return value;
	}

	NString GetKeyFormat() const
	{
		return GetString<HandleType>(NDictionaryInfoGetKeyFormat);
	}

	NValue GetKeyMinValue() const
	{
		return GetObject<HandleType, NValue>(NDictionaryInfoGetKeyMinValue);
	}

	NValue GetKeyMaxValue() const
	{
		return GetObject<HandleType, NValue>(NDictionaryInfoGetKeyMaxValue);
	}

	NType GetValueType() const
	{
		return GetObject<HandleType, NType>(NDictionaryInfoGetValueType, true);
	}

	NAttributes GetValueAttributes() const
	{
		NAttributes value;
		NCheck(NDictionaryInfoGetValueAttributes(GetHandle(), &value));
		return value;
	}

	NString GetValueFormat() const
	{
		return GetString<HandleType>(NDictionaryInfoGetValueFormat);
	}

	NValue GetValueMinValue() const
	{
		return GetObject<HandleType, NValue>(NDictionaryInfoGetValueMinValue);
	}

	NValue GetValueMaxValue() const
	{
		return GetObject<HandleType, NValue>(NDictionaryInfoGetValueMaxValue);
	}

	NMethodInfo GetGetCountMethod() const
	{
		return GetObject<HandleType, NMethodInfo>(NDictionaryInfoGetGetCountMethod);
	}

	NMethodInfo GetGetAtMethod() const
	{
		return GetObject<HandleType, NMethodInfo>(NDictionaryInfoGetGetAtMethod);
	}

	NMethodInfo GetToArrayMethod() const
	{
		return GetObject<HandleType, NMethodInfo>(NDictionaryInfoGetToArrayMethod);
	}

	NMethodInfo GetGetKeyMethod() const
	{
		return GetObject<HandleType, NMethodInfo>(NDictionaryInfoGetGetKeyMethod);
	}

	NMethodInfo GetToKeyArrayMethod() const
	{
		return GetObject<HandleType, NMethodInfo>(NDictionaryInfoGetToKeyArrayMethod);
	}

	NMethodInfo GetGetValueMethod() const
	{
		return GetObject<HandleType, NMethodInfo>(NDictionaryInfoGetGetValueMethod);
	}

	NMethodInfo GetToValueArrayMethod() const
	{
		return GetObject<HandleType, NMethodInfo>(NDictionaryInfoGetToValueArrayMethod);
	}

	NMethodInfo GetAddPairMethod() const
	{
		return GetObject<HandleType, NMethodInfo>(NDictionaryInfoGetAddPairMethod);
	}

	NMethodInfo GetRemoveAtMethod() const
	{
		return GetObject<HandleType, NMethodInfo>(NDictionaryInfoGetRemoveAtMethod);
	}

	NMethodInfo GetClearMethod() const
	{
		return GetObject<HandleType, NMethodInfo>(NDictionaryInfoGetClearMethod);
	}

	NMethodInfo GetContainsMethod() const
	{
		return GetObject<HandleType, NMethodInfo>(NDictionaryInfoGetContainsMethod);
	}

	NMethodInfo GetGetMethod() const
	{
		return GetObject<HandleType, NMethodInfo>(NDictionaryInfoGetGetMethod);
	}

	NMethodInfo GetTryGetMethod() const
	{
		return GetObject<HandleType, NMethodInfo>(NDictionaryInfoGetTryGetMethod);
	}

	NMethodInfo GetAddMethod() const
	{
		return GetObject<HandleType, NMethodInfo>(NDictionaryInfoGetAddMethod);
	}

	NMethodInfo GetSetMethod() const
	{
		return GetObject<HandleType, NMethodInfo>(NDictionaryInfoGetSetMethod);
	}

	NMethodInfo GetRemoveMethod() const
	{
		return GetObject<HandleType, NMethodInfo>(NDictionaryInfoGetRemoveMethod);
	}

	NMethodInfo GetAddCollectionChangedMethod() const
	{
		return GetObject<HandleType, NMethodInfo>(NDictionaryInfoGetAddCollectionChangedMethod);
	}

	NMethodInfo GetAddCollectionChangedCallbackMethod() const
	{
		return GetObject<HandleType, NMethodInfo>(NDictionaryInfoGetAddCollectionChangedCallbackMethod);
	}

	NMethodInfo GetRemoveCollectionChangedMethod() const
	{
		return GetObject<HandleType, NMethodInfo>(NDictionaryInfoGetRemoveCollectionChangedMethod);
	}

	NMethodInfo GetRemoveCollectionChangedCallbackMethod() const
	{
		return GetObject<HandleType, NMethodInfo>(NDictionaryInfoGetRemoveCollectionChangedCallbackMethod);
	}

	const KeyStdValueCollection GetKeyStdValues() const
	{
		return KeyStdValueCollection(*this);
	}

	const ValueStdValueCollection GetValueStdValues() const
	{
		return ValueStdValueCollection(*this);
	}
};

}}

#endif // !N_DICTIONARY_INFO_HPP_INCLUDED
