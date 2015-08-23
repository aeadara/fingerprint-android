#include <Reflection/NObjectPartInfo.hpp>

#ifndef N_COLLECTION_INFO_HPP_INCLUDED
#define N_COLLECTION_INFO_HPP_INCLUDED

namespace Neurotec { namespace Reflection
{
#include <Reflection/NCollectionInfo.h>
}}

namespace Neurotec { namespace Reflection
{

class NCollectionInfo : public NObjectPartInfo
{
	N_DECLARE_OBJECT_CLASS(NCollectionInfo, NObjectPartInfo)

public:
	class ItemStdValueCollection : public ::Neurotec::Collections::NCollectionWithAllOutBase<NNameValuePair, NCollectionInfo,
		NCollectionInfoGetItemStdValueCount, NCollectionInfoGetItemStdValue, NCollectionInfoGetItemStdValues>
	{
		ItemStdValueCollection(const NCollectionInfo & owner)
		{
			SetOwner(owner);
		}
	protected:

		friend class NCollectionInfo;
	};

public:
	NType GetItemType() const
	{
		return GetObject<HandleType, NType>(NCollectionInfoGetItemType, true);
	}

	NAttributes GetItemAttributes() const
	{
		NAttributes value;
		NCheck(NCollectionInfoGetItemAttributes(GetHandle(), &value));
		return value;
	}

	NString GetItemFormat() const
	{
		return GetString<HandleType>(NCollectionInfoGetItemFormat);
	}

	NValue GetItemMinValue() const
	{
		return GetObject<HandleType, NValue>(NCollectionInfoGetItemMinValue);
	}

	NValue GetItemMaxValue() const
	{
		return GetObject<HandleType, NValue>(NCollectionInfoGetItemMaxValue);
	}

	NMethodInfo GetGetCountMethod() const
	{
		return GetObject<HandleType, NMethodInfo>(NCollectionInfoGetGetCountMethod);
	}

	NMethodInfo GetGetMethod() const
	{
		return GetObject<HandleType, NMethodInfo>(NCollectionInfoGetGetMethod);
	}

	NMethodInfo GetToArrayMethod() const
	{
		return GetObject<HandleType, NMethodInfo>(NCollectionInfoGetToArrayMethod);
	}

	NMethodInfo GetGetCapacityMethod() const
	{
		return GetObject<HandleType, NMethodInfo>(NCollectionInfoGetGetCapacityMethod);
	}

	NMethodInfo GetSetCapacityMethod() const
	{
		return GetObject<HandleType, NMethodInfo>(NCollectionInfoGetSetCapacityMethod);
	}

	NMethodInfo GetSetMethod() const
	{
		return GetObject<HandleType, NMethodInfo>(NCollectionInfoGetSetMethod);
	}

	NMethodInfo GetAddMethod() const
	{
		return GetObject<HandleType, NMethodInfo>(NCollectionInfoGetAddMethod);
	}

	NMethodInfo GetAddRangeMethod() const
	{
		return GetObject<HandleType, NMethodInfo>(NCollectionInfoGetAddRangeMethod);
	}

	NMethodInfo GetInsertMethod() const
	{
		return GetObject<HandleType, NMethodInfo>(NCollectionInfoGetInsertMethod);
	}

	NMethodInfo GetInsertRangeMethod() const
	{
		return GetObject<HandleType, NMethodInfo>(NCollectionInfoGetInsertRangeMethod);
	}

	NMethodInfo GetRemoveMethod() const
	{
		return GetObject<HandleType, NMethodInfo>(NCollectionInfoGetRemoveMethod);
	}

	NMethodInfo GetIndexOfMethod() const
	{
		return GetObject<HandleType, NMethodInfo>(NCollectionInfoGetIndexOfMethod);
	}

	NMethodInfo GetRemoveAtMethod() const
	{
		return GetObject<HandleType, NMethodInfo>(NCollectionInfoGetRemoveAtMethod);
	}

	NMethodInfo GetRemoveRangeMethod() const
	{
		return GetObject<HandleType, NMethodInfo>(NCollectionInfoGetRemoveRangeMethod);
	}

	NMethodInfo GetClearMethod() const
	{
		return GetObject<HandleType, NMethodInfo>(NCollectionInfoGetClearMethod);
	}

	NMethodInfo GetAddCollectionChangedMethod() const
	{
		return GetObject<HandleType, NMethodInfo>(NCollectionInfoGetAddCollectionChangedMethod);
	}

	NMethodInfo GetAddCollectionChangedCallbackMethod() const
	{
		return GetObject<HandleType, NMethodInfo>(NCollectionInfoGetAddCollectionChangedCallbackMethod);
	}

	NMethodInfo GetRemoveCollectionChangedMethod() const
	{
		return GetObject<HandleType, NMethodInfo>(NCollectionInfoGetRemoveCollectionChangedMethod);
	}

	NMethodInfo GetRemoveCollectionChangedCallbackMethod() const
	{
		return GetObject<HandleType, NMethodInfo>(NCollectionInfoGetRemoveCollectionChangedCallbackMethod);
	}

	const ItemStdValueCollection GetItemStdValues() const
	{
		return ItemStdValueCollection(*this);
	}
};

}}

#endif // !N_COLLECTION_INFO_HPP_INCLUDED
