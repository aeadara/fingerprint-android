#include <ComponentModel/NPropertyDescriptor.hpp>

#ifndef N_CUSTOM_PROPERTY_DESCRIPTOR_HPP_INCLUDED
#define N_CUSTOM_PROPERTY_DESCRIPTOR_HPP_INCLUDED

namespace Neurotec { namespace ComponentModel
{
#include <ComponentModel/NCustomPropertyDescriptor.h>
}}

namespace Neurotec { namespace ComponentModel
{

class NCustomPropertyDescriptor : public NPropertyDescriptor
{
	N_DECLARE_OBJECT_CLASS(NCustomPropertyDescriptor, NPropertyDescriptor)

public:
	NValue GetData() const
	{
		return GetObject<HandleType, NValue>(NCustomPropertyDescriptorGetData);
	}
};

}}

#endif // !N_CUSTOM_PROPERTY_DESCRIPTOR_HPP_INCLUDED
