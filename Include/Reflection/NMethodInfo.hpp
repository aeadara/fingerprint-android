#include <Reflection/NMemberInfo.hpp>

#ifndef N_METHOD_INFO_HPP_INCLUDED
#define N_METHOD_INFO_HPP_INCLUDED

#include <Reflection/NParameterInfo.hpp>
#include <Collections/NCollections.hpp>
#include <Core/NPropertyBag.hpp>
namespace Neurotec { namespace Reflection
{
#include <Reflection/NMethodInfo.h>
}}

namespace Neurotec { namespace Reflection
{

class NMethodInfo : public NMemberInfo
{
	N_DECLARE_OBJECT_CLASS(NMethodInfo, NMemberInfo)

public:
	class ParameterCollection : public ::Neurotec::Collections::NCollectionWithAllOutBase<NParameterInfo, NMethodInfo,
		NMethodInfoGetParameterCount, NMethodInfoGetParameter, NMethodInfoGetParameters>
	{
		ParameterCollection(const NMethodInfo & owner)
		{
			SetOwner(owner);
		}

	protected:
		friend class NMethodInfo;
	};

public:
	NString GetNativeName() const
	{
		return GetString(NMethodInfoGetNativeName);
	}

	NParameterInfo GetReturnParameter() const
	{
		return GetObject<HandleType, NParameterInfo>(NMethodInfoGetReturnParameter);
	}

	template<typename InputIt>
	NValue Invoke(const NObject & object, InputIt firstParameter, InputIt lastParameter) const
	{
		NArrayWrapper<NValue> parameters(firstParameter, lastParameter);
		HNValue hResult;
		NCheck(NMethodInfoInvoke(GetHandle(), object.GetHandle(), parameters.GetPtr(), parameters.GetCount(), &hResult));
		return FromHandle<NValue>(hResult);
	}

	NValue Invoke(const NObject & object, const NPropertyBag & parameters) const
	{
		HNValue hResult;
		NCheck(NMethodInfoInvokeWithPropertyBag(GetHandle(), object.GetHandle(), parameters.GetHandle(), &hResult));
		return FromHandle<NValue>(hResult);
	}

	NValue Invoke(const NObject & object, const NStringWrapper & parameters) const
	{
		HNValue hResult;
		NCheck(NMethodInfoInvokeWithStringN(GetHandle(), object.GetHandle(), parameters.GetHandle(), &hResult));
		return FromHandle<NValue>(hResult);
	}

	const ParameterCollection GetParameters() const
	{
		return ParameterCollection(*this);
	}
};

}}

#endif // !N_METHOD_INFO_HPP_INCLUDED
