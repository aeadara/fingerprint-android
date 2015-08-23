#ifndef N_PLUGIN_MODULE_INTERNAL_H_INCLUDED
#define N_PLUGIN_MODULE_INTERNAL_H_INCLUDED

#include <Plugins/NPluginModule.h>
#include <Plugins/ComponentModel/NPluginMethodDescriptor.h>
#include <Plugins/ComponentModel/NPluginPropertyDescriptor.h>
#include <Plugins/ComponentModel/NPluginEventDescriptor.h>
#include <Core/NModuleInternal.h>
#include <Plugins/NPluginInternal.h>

#ifdef N_CPP
extern "C"
{
#endif

typedef NResult (N_CALLBACK NPluginModulePlugProc)(HNString hDirectory, NVersion_ interfaceVersion, const void * pHostInterface, HNPlugin hPlugin);
typedef NResult (N_CALLBACK NPluginModuleUnplugProc)(void);
typedef NResult (N_CALLBACK NPluginGetMethodsProc)(HNPluginMethodDescriptor * * parhMethods, NInt * pMethodCount);
typedef NResult (N_CALLBACK NPluginGetPropertiesProc)(HNPluginPropertyDescriptor * * parhProperties, NInt * pPropertyCount);
typedef NResult (N_CALLBACK NPluginGetEventsProc)(HNPluginEventDescriptor * * parhEvents, NInt * pEventCount);

NResult N_API NPluginModuleSetInterfaceVersions(HNPluginModule hModule, const NPluginInterfaceVersionInfo * arValues, NInt count);

NResult N_API NPluginModuleSetPlug(HNPluginModule hModule, NPluginModulePlugProc pValue);
NResult N_API NPluginModuleSetUnplug(HNPluginModule hModule, NPluginModuleUnplugProc pValue);
NResult N_API NPluginModuleSetGetMethods(HNPluginModule hModule, NPluginGetMethodsProc pValue);
NResult N_API NPluginModuleSetGetProperties(HNPluginModule hModule, NPluginGetPropertiesProc pValue);
NResult N_API NPluginModuleSetGetEvents(HNPluginModule hModule, NPluginGetEventsProc pValue);

#ifdef N_CPP
}
#endif

#endif // !N_PLUGIN_MODULE_INTERNAL_H_INCLUDED
