#include <Core/NType.hpp>

#ifndef N_DESCRIPTOR_HPP_INCLUDED
#define N_DESCRIPTOR_HPP_INCLUDED

namespace Neurotec { namespace ComponentModel
{
#include <ComponentModel/NDescriptor.h>
}}

namespace Neurotec { namespace ComponentModel
{

class NDescriptor : public NObject
{
	N_DECLARE_OBJECT_CLASS(NDescriptor, NObject)

public:
	NString GetName() const
	{
		return GetString(NDescriptorGetName);
	}

	NAttributes GetAttributes() const
	{
		NAttributes value;
		NCheck(NDescriptorGetAttributes(GetHandle(), &value));
		return value;
	}
};

}}

#endif // !N_DESCRIPTOR_HPP_INCLUDED
