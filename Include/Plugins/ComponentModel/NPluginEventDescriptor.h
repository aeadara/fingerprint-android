#include <ComponentModel/NCustomEventDescriptor.h>
#include <Plugins/NPlugin.h>

#ifndef N_PLUGIN_EVENT_DESCRIPTOR_H_INCLUDED
#define N_PLUGIN_EVENT_DESCRIPTOR_H_INCLUDED

#ifdef N_CPP
extern "C"
{
#endif

N_DECLARE_OBJECT_TYPE(NPluginEventDescriptor, NCustomEventDescriptor)

typedef NResult (N_CALLBACK NPluginEventDescriptorModifyHandlerProc)(HNPluginEventDescriptor hEventDescriptor, HNCallback hCallback, void * pParam);

NResult N_API NPluginEventDescriptorCreate(HNString hName, HNType hEventType, NAttributes attributes, HNValue hData, HNCallback hAddHandler, HNCallback hRemoveHandler, HNPluginEventDescriptor * phEventDescriptor);

#ifdef N_CPP
}
#endif

#endif // !N_PLUGIN_EVENT_DESCRIPTOR_H_INCLUDED
