#include <Reflection/NMemberInfo.hpp>
#include <Reflection/NConstantInfo.hpp>
#include <Reflection/NMethodInfo.hpp>
#include <Reflection/NPropertyInfo.hpp>
#include <Reflection/NEventInfo.hpp>

#ifndef N_OBJECT_PART_INFO_HPP_INCLUDED
#define N_OBJECT_PART_INFO_HPP_INCLUDED

#include <Collections/NCollections.hpp>
namespace Neurotec { namespace Reflection
{
#include <Reflection/NObjectPartInfo.h>
}}

namespace Neurotec { namespace Reflection
{

class NObjectPartInfo : public NMemberInfo
{
	N_DECLARE_OBJECT_CLASS(NObjectPartInfo, NMemberInfo)

public:
	class DeclaredConstantCollection : public ::Neurotec::Collections::NCollectionWithAllOutBase< ::Neurotec::Reflection::NConstantInfo, NObjectPartInfo,
		NObjectPartInfoGetDeclaredConstantCount, NObjectPartInfoGetDeclaredConstant, NObjectPartInfoGetDeclaredConstants>
	{
		DeclaredConstantCollection(const NObjectPartInfo & owner)
		{
			SetOwner(owner);
		}

	protected:

		friend class NObjectPartInfo;
	};

	class DeclaredMethodCollection : public ::Neurotec::Collections::NCollectionWithAllOutBase< ::Neurotec::Reflection::NMethodInfo, NObjectPartInfo,
		NObjectPartInfoGetDeclaredMethodCount, NObjectPartInfoGetDeclaredMethod, NObjectPartInfoGetDeclaredMethods>
	{
		DeclaredMethodCollection(const NObjectPartInfo & owner)
		{
			SetOwner(owner);
		}

	protected:
		friend class NObjectPartInfo;
	};

	class DeclaredPropertyCollection : public ::Neurotec::Collections::NCollectionWithAllOutBase< ::Neurotec::Reflection::NPropertyInfo, NObjectPartInfo,
		NObjectPartInfoGetDeclaredPropertyCount, NObjectPartInfoGetDeclaredProperty, NObjectPartInfoGetDeclaredProperties>
	{
		DeclaredPropertyCollection(const NObjectPartInfo & owner)
		{
			SetOwner(owner);
		}

	protected:
		friend class NObjectPartInfo;
	};

	class DeclaredEventCollection : public ::Neurotec::Collections::NCollectionWithAllOutBase< ::Neurotec::Reflection::NEventInfo, NObjectPartInfo,
		NObjectPartInfoGetDeclaredEventCount, NObjectPartInfoGetDeclaredEvent, NObjectPartInfoGetDeclaredEvents>
	{
		DeclaredEventCollection(const NObjectPartInfo & owner)
		{
			SetOwner(owner);
		}

	protected:
		friend class NObjectPartInfo;
	};

public:
	NString GetPropertyName() const
	{
		return GetString(NObjectPartInfoGetPropertyName);
	}

	NConstantInfo GetDeclaredConstant(const NStringWrapper & name) const
	{
		HNConstantInfo hValue;
		NCheck(NObjectPartInfoGetDeclaredConstantWithNameN(GetHandle(), name.GetHandle(), &hValue));
		return FromHandle<NConstantInfo>(hValue);
	}

	NMethodInfo GetDeclaredMethod(const NStringWrapper & name) const
	{
		HNMethodInfo hValue;
		NCheck(NObjectPartInfoGetDeclaredMethodWithNameN(GetHandle(), name.GetHandle(), &hValue));
		return FromHandle<NMethodInfo>(hValue);
	}

	NArrayWrapper<NMethodInfo> GetDeclaredMethods(const NStringWrapper & name) const
	{
		HNMethodInfo * arhValues;
		NInt valueCount;
		NCheck(NObjectPartInfoGetDeclaredMethodsWithNameN(GetHandle(), name.GetHandle(), &arhValues, &valueCount));
		return NArrayWrapper<NMethodInfo>(arhValues, valueCount);
	}

	NPropertyInfo GetDeclaredProperty(const NStringWrapper & name) const
	{
		HNPropertyInfo hValue;
		NCheck(NObjectPartInfoGetDeclaredPropertyWithNameN(GetHandle(), name.GetHandle(), &hValue));
		return FromHandle<NPropertyInfo>(hValue);
	}

	NEventInfo GetDeclaredEvent(const NStringWrapper & name) const
	{
		HNEventInfo hValue;
		NCheck(NObjectPartInfoGetDeclaredEventWithNameN(GetHandle(), name.GetHandle(), &hValue));
		return FromHandle<NEventInfo>(hValue);
	}

	NObjectPart GetObjectPart(const NObject & object) const
	{
		HNObjectPart hObjectPart;
		NCheck(NObjectPartInfoGetObjectPart(GetHandle(), object.GetHandle(), &hObjectPart));
		return FromHandle<NObjectPart>(hObjectPart);
	}

	const DeclaredConstantCollection GetDeclaredConstants() const
	{
		return DeclaredConstantCollection(*this);
	}

	const DeclaredMethodCollection GetDeclaredMethods() const
	{
		return DeclaredMethodCollection(*this);
	}

	const DeclaredPropertyCollection GetDeclaredProperties() const
	{
		return DeclaredPropertyCollection(*this);
	}

	const DeclaredEventCollection GetDeclaredEvents() const
	{
		return DeclaredEventCollection(*this);
	}
};

}}

#endif // !N_OBJECT_PART_INFO_HPP_INCLUDED
