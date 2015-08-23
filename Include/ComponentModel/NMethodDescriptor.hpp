#include <ComponentModel/NMemberDescriptor.hpp>
#include <ComponentModel/NParameterDescriptor.hpp>
#include <Core/NValue.hpp>

#ifndef N_METHOD_DESCRIPTOR_HPP_INCLUDED
#define N_METHOD_DESCRIPTOR_HPP_INCLUDED

namespace Neurotec { namespace ComponentModel
{
#include <ComponentModel/NMethodDescriptor.h>
}}

namespace Neurotec { namespace ComponentModel
{

class NMethodDescriptor : public NMemberDescriptor
{
	N_DECLARE_OBJECT_CLASS(NMethodDescriptor, NMemberDescriptor)

public:
	class ParameterCollection : public ::Neurotec::Collections::NCollectionWithAllOutBase<NParameterDescriptor, NMethodDescriptor,
		NMethodDescriptorGetParameterCount, NMethodDescriptorGetParameter, NMethodDescriptorGetParameters>
	{
		ParameterCollection(const NMethodDescriptor & owner)
		{
			SetOwner(owner);
		}

		friend class NMethodDescriptor;
	};

public:
	NParameterDescriptor GetReturnParameter() const
	{
		return GetObject<HandleType, NParameterDescriptor>(NMethodDescriptorGetReturnParameter);
	}

	template<typename InputIt>
	NValue Invoke(const NObject & object, InputIt first, InputIt last) const
	{
		NArrayWrapper<NValue> parameters(first, last);
		HNValue hResult;
		NCheck(NMethodDescriptorInvoke(GetHandle(), object.GetHandle(), parameters.GetPtr(), parameters.GetCount(), &hResult));
		return FromHandle<NValue>(hResult);
	}

	NValue Invoke(const NObject & object, const NPropertyBag & parameters) const
	{
		HNValue hResult;
		NCheck(NMethodDescriptorInvokeWithPropertyBag(GetHandle(), object.GetHandle(), parameters.GetHandle(), &hResult));
		return FromHandle<NValue>(hResult);
	}

	NValue Invoke(const NObject & object, const NStringWrapper & parameters) const
	{
		HNValue hResult;
		NCheck(NMethodDescriptorInvokeWithStringN(GetHandle(), object.GetHandle(), parameters.GetHandle(), &hResult));
		return FromHandle<NValue>(hResult);
	}

	const ParameterCollection GetParameters() const
	{
		return ParameterCollection(*this);
	}
};

}}

#endif // !N_METHOD_DESCRIPTOR_HPP_INCLUDED
