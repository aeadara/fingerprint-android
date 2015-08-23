#include <ComponentModel/NMethodDescriptor.h>

#ifndef N_CUSTOM_METHOD_DESCRIPTOR_H_INCLUDED
#define N_CUSTOM_METHOD_DESCRIPTOR_H_INCLUDED

#ifdef N_CPP
extern "C"
{
#endif

N_DECLARE_OBJECT_TYPE(NCustomMethodDescriptor, NMethodDescriptor)

NResult N_API NCustomMethodDescriptorGetData(HNCustomMethodDescriptor hMethodDescriptor, HNValue * phData);

#ifdef N_CPP
}
#endif

#endif // !N_CUSTOM_METHOD_DESCRIPTOR_H_INCLUDED
