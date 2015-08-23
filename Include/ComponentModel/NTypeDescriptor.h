#ifndef N_TYPE_DESCRIPTOR_H_INCLUDED
#define N_TYPE_DESCRIPTOR_H_INCLUDED

#include <ComponentModel/NMethodDescriptor.h>
#include <ComponentModel/NPropertyDescriptor.h>
#include <ComponentModel/NEventDescriptor.h>

#ifdef N_CPP
extern "C"
{
#endif

N_DECLARE_STATIC_OBJECT_TYPE(NTypeDescriptor)

NResult N_API NTypeDescriptorGetMethods(HNObject hObject, HNMethodDescriptor * * parhMethods, NInt * pMethodCount);
NResult N_API NTypeDescriptorGetMethodsForType(HNType hType, HNMethodDescriptor * * parhMethods, NInt * pMethodCount);
NResult N_API NTypeDescriptorGetProperties(HNObject hObject, HNPropertyDescriptor * * parhProperties, NInt * pPropertyCount);
NResult N_API NTypeDescriptorGetPropertiesForType(HNType hType, HNPropertyDescriptor * * parhProperties, NInt * pPropertyCount);
NResult N_API NTypeDescriptorGetDefaultPropertyName(HNObject hObject, HNString * phValue);
NResult N_API NTypeDescriptorGetDefaultPropertyNameForType(HNType hType, HNString * phValue);
NResult N_API NTypeDescriptorGetEvents(HNObject hObject, HNEventDescriptor * * parhEvents, NInt * pEventCount);
NResult N_API NTypeDescriptorGetEventsForType(HNType hType, HNEventDescriptor * * parhEvents, NInt * pEventCount);

#ifdef N_CPP
}
#endif

#endif // !N_TYPE_DESCRIPTOR_H_INCLUDED
