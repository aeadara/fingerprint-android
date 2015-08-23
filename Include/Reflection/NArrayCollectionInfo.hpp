#include <Reflection/NCollectionInfo.hpp>

#ifndef N_ARRAY_COLLECTION_INFO_HPP_INCLUDED
#define N_ARRAY_COLLECTION_INFO_HPP_INCLUDED

namespace Neurotec { namespace Reflection
{
#include <Reflection/NArrayCollectionInfo.h>
}}

namespace Neurotec { namespace Reflection
{

class NArrayCollectionInfo : public NObjectPartInfo
{
	N_DECLARE_OBJECT_CLASS(NArrayCollectionInfo, NObjectPartInfo)

public:
	class ItemStdValueCollection : public ::Neurotec::Collections::NCollectionWithAllOutBase<NNameValuePair, NArrayCollectionInfo,
		NArrayCollectionInfoGetItemStdValueCount, NArrayCollectionInfoGetItemStdValue, NArrayCollectionInfoGetItemStdValues>
	{
		ItemStdValueCollection(const NArrayCollectionInfo & owner)
		{
			this->owner = owner;
		}

	protected:

		friend class NArrayCollectionInfo;
	};

public:
	NCollectionInfo GetBaseCollection() const
	{
		return GetObject<HandleType, NCollectionInfo>(NArrayCollectionInfoGetBaseCollection);
	}

	NType GetItemType() const
	{
		return GetObject<HandleType, NType>(NArrayCollectionInfoGetItemType, true);
	}

	NAttributes GetItemAttributes() const
	{
		NAttributes value;
		NCheck(NArrayCollectionInfoGetItemAttributes(GetHandle(), &value));
		return value;
	}

	NString GetItemFormat() const
	{
		return GetString<HandleType>(NArrayCollectionInfoGetItemFormat);
	}

	NValue GetItemMinValue() const
	{
		return GetObject<HandleType, NValue>(NArrayCollectionInfoGetItemMinValue);
	}

	NValue GetItemMaxValue() const
	{
		return GetObject<HandleType, NValue>(NArrayCollectionInfoGetItemMaxValue);
	}

	NMethodInfo GetGetCountMethod() const
	{
		return GetObject<HandleType, NMethodInfo>(NArrayCollectionInfoGetGetCountMethod);
	}

	NMethodInfo GetGetMethod() const
	{
		return GetObject<HandleType, NMethodInfo>(NArrayCollectionInfoGetGetMethod);
	}

	NMethodInfo GetToArrayMethod() const
	{
		return GetObject<HandleType, NMethodInfo>(NArrayCollectionInfoGetToArrayMethod);
	}

	NMethodInfo GetSetMethod() const
	{
		return GetObject<HandleType, NMethodInfo>(NArrayCollectionInfoGetSetMethod);
	}

	NMethodInfo GetAddMethod() const
	{
		return GetObject<HandleType, NMethodInfo>(NArrayCollectionInfoGetAddMethod);
	}

	NMethodInfo GetAddRangeMethod() const
	{
		return GetObject<HandleType, NMethodInfo>(NArrayCollectionInfoGetAddRangeMethod);
	}

	NMethodInfo GetInsertMethod() const
	{
		return GetObject<HandleType, NMethodInfo>(NArrayCollectionInfoGetInsertMethod);
	}

	NMethodInfo GetInsertRangeMethod() const
	{
		return GetObject<HandleType, NMethodInfo>(NArrayCollectionInfoGetInsertRangeMethod);
	}

	NMethodInfo GetRemoveMethod() const
	{
		return GetObject<HandleType, NMethodInfo>(NArrayCollectionInfoGetRemoveMethod);
	}

	NMethodInfo GetIndexOfMethod() const
	{
		return GetObject<HandleType, NMethodInfo>(NArrayCollectionInfoGetIndexOfMethod);
	}

	NMethodInfo GetRemoveAtMethod() const
	{
		return GetObject<HandleType, NMethodInfo>(NArrayCollectionInfoGetRemoveAtMethod);
	}

	NMethodInfo GetRemoveRangeMethod() const
	{
		return GetObject<HandleType, NMethodInfo>(NArrayCollectionInfoGetRemoveRangeMethod);
	}

	NMethodInfo GetClearMethod() const
	{
		return GetObject<HandleType, NMethodInfo>(NArrayCollectionInfoGetClearMethod);
	}

	const ItemStdValueCollection GetItemStdValues() const
	{
		return ItemStdValueCollection(*this);
	}
};

}}

#endif // !N_ARRAY_COLLECTION_INFO_HPP_INCLUDED
