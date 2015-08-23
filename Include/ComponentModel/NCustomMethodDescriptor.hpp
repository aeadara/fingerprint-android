#include <ComponentModel/NMethodDescriptor.hpp>

#ifndef N_CUSTOM_METHOD_DESCRIPTOR_HPP_INCLUDED
#define N_CUSTOM_METHOD_DESCRIPTOR_HPP_INCLUDED

namespace Neurotec { namespace ComponentModel
{
#include <ComponentModel/NCustomMethodDescriptor.h>
}}

namespace Neurotec { namespace ComponentModel
{

class NCustomMethodDescriptor : public NMethodDescriptor
{
	N_DECLARE_OBJECT_CLASS(NCustomMethodDescriptor, NMethodDescriptor)

public:
	NValue GetData() const
	{
		return GetObject<HandleType, NValue>(NCustomMethodDescriptorGetData);
	}
};

}}

#endif // !N_CUSTOM_METHOD_DESCRIPTOR_HPP_INCLUDED
