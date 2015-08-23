#include <ComponentModel/NPropertyDescriptor.h>

#ifndef N_CUSTOM_PROPERTY_DESCRIPTOR_H_INCLUDED
#define N_CUSTOM_PROPERTY_DESCRIPTOR_H_INCLUDED

#ifdef N_CPP
extern "C"
{
#endif

N_DECLARE_OBJECT_TYPE(NCustomPropertyDescriptor, NPropertyDescriptor)

NResult N_API NCustomPropertyDescriptorGetData(HNCustomPropertyDescriptor hPropertyDescriptor, HNValue * phData);

#ifdef N_CPP
}
#endif

#endif // !N_CUSTOM_PROPERTY_DESCRIPTOR_H_INCLUDED
