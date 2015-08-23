#include <ComponentModel/NDescriptor.hpp>

#ifndef N_MEMBER_DESCRIPTOR_HPP_INCLUDED
#define N_MEMBER_DESCRIPTOR_HPP_INCLUDED

namespace Neurotec { namespace ComponentModel
{
#include <ComponentModel/NMemberDescriptor.h>
}}

namespace Neurotec { namespace ComponentModel
{

class NMemberDescriptor : public NDescriptor
{
	N_DECLARE_OBJECT_CLASS(NMemberDescriptor, NDescriptor)

	NType GetComponentType() const
	{
		return GetObject<HandleType, NType>(NMemberDescriptorGetComponentType, true);
	}
};

}}

#endif // !N_MEMBER_DESCRIPTOR_HPP_INCLUDED
