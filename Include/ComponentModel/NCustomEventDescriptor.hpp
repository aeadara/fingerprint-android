#include <ComponentModel/NEventDescriptor.hpp>

#ifndef N_CUSTOM_EVENT_DESCRIPTOR_HPP_INCLUDED
#define N_CUSTOM_EVENT_DESCRIPTOR_HPP_INCLUDED

namespace Neurotec { namespace ComponentModel
{
#include <ComponentModel/NCustomEventDescriptor.h>
}}

namespace Neurotec { namespace ComponentModel
{

class NCustomEventDescriptor : public NEventDescriptor
{
	N_DECLARE_OBJECT_CLASS(NCustomEventDescriptor, NEventDescriptor)

public:
	NValue GetData() const
	{
		return GetObject<HandleType, NValue>(NCustomEventDescriptorGetData);
	}
};

}}

#endif // !N_CUSTOM_EVENT_DESCRIPTOR_HPP_INCLUDED
