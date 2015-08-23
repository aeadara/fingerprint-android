#include <ComponentModel/NEventDescriptor.h>

#ifndef N_CUSTOM_EVENT_DESCRIPTOR_H_INCLUDED
#define N_CUSTOM_EVENT_DESCRIPTOR_H_INCLUDED

#ifdef N_CPP
extern "C"
{
#endif

N_DECLARE_OBJECT_TYPE(NCustomEventDescriptor, NEventDescriptor)

NResult N_API NCustomEventDescriptorGetData(HNCustomEventDescriptor hEventDescriptor, HNValue * phData);

#ifdef N_CPP
}
#endif

#endif // !N_CUSTOM_EVENT_DESCRIPTOR_H_INCLUDED
