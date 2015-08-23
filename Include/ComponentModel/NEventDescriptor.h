#include <ComponentModel/NMemberDescriptor.h>
#include <Core/NValue.h>

#ifndef N_EVENT_DESCRIPTOR_H_INCLUDED
#define N_EVENT_DESCRIPTOR_H_INCLUDED

#ifdef N_CPP
extern "C"
{
#endif

N_DECLARE_OBJECT_TYPE(NEventDescriptor, NMemberDescriptor)

NResult N_API NEventDescriptorGetEventType(HNEventDescriptor hEventDescriptor, HNType * phValue);
NResult N_API NEventDescriptorAddHandlerN(HNEventDescriptor hEventDescriptor, HNObject hComponent, HNValue hCallback);
NResult N_API NEventDescriptorAddHandler(HNEventDescriptor hEventDescriptor, HNObject hComponent, HNType hCallbackType, HNCallback hCallback);
NResult N_API NEventDescriptorAddHandlerP(HNEventDescriptor hEventDescriptor, HNObject hComponent, NTypeOfProc pCallbackTypeOf, HNCallback hCallback);
NResult N_API NEventDescriptorRemoveHandlerN(HNEventDescriptor hEventDescriptor, HNObject hComponent, HNValue hCallback);
NResult N_API NEventDescriptorRemoveHandler(HNEventDescriptor hEventDescriptor, HNObject hComponent, HNType hCallbackType, HNCallback hCallback);
NResult N_API NEventDescriptorRemoveHandlerP(HNEventDescriptor hEventDescriptor, HNObject hComponent, NTypeOfProc pCallbackTypeOf, HNCallback hCallback);

#ifdef N_CPP
}
#endif

#endif // !N_EVENT_DESCRIPTOR_H_INCLUDED
