#include <ComponentModel/NDescriptor.hpp>

#ifndef N_PARAMETER_DESCRIPTOR_HPP_INCLUDED
#define N_PARAMETER_DESCRIPTOR_HPP_INCLUDED

namespace Neurotec { namespace ComponentModel
{
#include <ComponentModel/NParameterDescriptor.h>
}}

namespace Neurotec { namespace ComponentModel
{

class NParameterDescriptor : public NDescriptor
{
	N_DECLARE_OBJECT_CLASS(NParameterDescriptor, NDescriptor)

public:
	class StdValueCollection : public ::Neurotec::Collections::NCollectionWithAllOutBase<NNameValuePair, NParameterDescriptor,
		NParameterDescriptorGetStdValueCount, NParameterDescriptorGetStdValue, NParameterDescriptorGetStdValues>
	{
		StdValueCollection(const NParameterDescriptor & owner)
		{
			SetOwner(owner);
		}

		friend class NParameterDescriptor;
	};

public:
	NType GetParameterType() const
	{
		return GetObject<HandleType, NType>(NParameterDescriptorGetParameterType, true);
	}

	NString GetFormat() const
	{
		return GetString<HandleType>(NParameterDescriptorGetFormat);
	}

	NValue GetDefaultValue() const
	{
		return GetObject<HandleType, NValue>(NParameterDescriptorGetDefaultValue);
	}

	NValue GetMinValue() const
	{
		return GetObject<HandleType, NValue>(NParameterDescriptorGetMinValue);
	}

	NValue GetMaxValue() const
	{
		return GetObject<HandleType, NValue>(NParameterDescriptorGetMaxValue);
	}

	const StdValueCollection GetStdValues() const
	{
		return StdValueCollection(*this);
	}
};

}}

#endif // !N_PARAMETER_DESCRIPTOR_HPP_INCLUDED
