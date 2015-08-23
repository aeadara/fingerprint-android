#include <ComponentModel/NParameterDescriptor.hpp>

#ifndef N_CUSTOM_PARAMETER_DESCRIPTOR_HPP_INCLUDED
#define N_CUSTOM_PARAMETER_DESCRIPTOR_HPP_INCLUDED

namespace Neurotec { namespace ComponentModel
{
#include <ComponentModel/NCustomParameterDescriptor.h>
}}

namespace Neurotec { namespace ComponentModel
{

class NCustomParameterDescriptor : public NParameterDescriptor
{
	N_DECLARE_OBJECT_CLASS(NCustomParameterDescriptor, NParameterDescriptor)

private:
	static HNCustomParameterDescriptor Create(const NStringWrapper & name, const NType & parameterType, NAttributes attributes, const NStringWrapper & format,
		const NValue & defaultValue, const NValue & minValue, const NValue & maxValue, NNameValuePair * arStdValues, NInt stdValueCount, const NValue & data)
	{
		HNCustomParameterDescriptor handle;
		NCheck(NCustomParameterDescriptorCreate(name.GetHandle(), parameterType.GetHandle(), attributes, format.GetHandle(),
			defaultValue.GetHandle(), minValue.GetHandle(), maxValue.GetHandle(), arStdValues, stdValueCount, data.GetHandle(),
			&handle));
		return handle;
	}

public:
	NCustomParameterDescriptor(const NStringWrapper & name, const NType & parameterType, NAttributes attributes, const NStringWrapper & format,
		const NValue & defaultValue, const NValue & minValue, const NValue & maxValue, NNameValuePair * arStdValues, NInt stdValueCount, const NValue & data)
		: NParameterDescriptor(Create(name, parameterType, attributes, format, defaultValue, minValue, maxValue, arStdValues, stdValueCount, data), true)
	{
	}

	NValue GetData() const
	{
		return GetObject<HandleType, NValue>(NCustomParameterDescriptorGetData);
	}
};

}}


#endif // !N_CUSTOM_PARAMETER_DESCRIPTOR_HPP_INCLUDED
