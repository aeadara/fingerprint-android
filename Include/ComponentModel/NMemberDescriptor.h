#include <ComponentModel/NDescriptor.h>

#ifndef N_MEMBER_DESCRIPTOR_H_INCLUDED
#define N_MEMBER_DESCRIPTOR_H_INCLUDED

#ifdef N_CPP
extern "C"
{
#endif

N_DECLARE_OBJECT_TYPE(NMemberDescriptor, NDescriptor)

NResult N_API NMemberDescriptorGetComponentType(HNMemberDescriptor hMemberDescriptor, HNType * phValue);

#ifdef N_CPP
}
#endif

#endif // !N_MEMBER_DESCRIPTOR_H_INCLUDED
