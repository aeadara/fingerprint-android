#ifndef N_PLUGIN_MODULE_H_INCLUDED
#define N_PLUGIN_MODULE_H_INCLUDED

#include <Core/NModule.h>

#ifdef N_CPP
extern "C"
{
#endif

N_DECLARE_OBJECT_TYPE(NPluginModule, NModule)

typedef NResult (N_CALLBACK NPluginModuleOfProc)(HNPluginModule * phValue);

NResult N_API NPluginModuleCreate(HNPluginModule * phModule);

NResult N_API NPluginModuleGetPluginNameN(HNPluginModule hModule, HNString * phValue);
#ifndef N_NO_ANSI_FUNC
N_DEPRECATED("function is deprecated, use NPluginModuleGetPluginNameN instead")
NResult N_API NPluginModuleGetPluginNameA(HNPluginModule hModule, NAChar * szValue, NInt valueSize);
#endif
#ifndef N_NO_UNICODE
N_DEPRECATED("function is deprecated, use NPluginModuleGetPluginNameN instead")
NResult N_API NPluginModuleGetPluginNameW(HNPluginModule hModule, NWChar * szValue, NInt valueSize);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NPluginModuleGetPluginName(HNPluginModule hModule, NChar * szValue, NInt valueSize);
#endif
#define NPluginModuleGetPluginName N_FUNC_AW(NPluginModuleGetPluginName)

NResult N_API NPluginModuleSetPluginNameN(HNPluginModule hModule, HNString hValue);
#ifndef N_NO_ANSI_FUNC
NResult N_API NPluginModuleSetPluginNameA(HNPluginModule hModule, const NAChar * szValue);
#endif
#ifndef N_NO_UNICODE
NResult N_API NPluginModuleSetPluginNameW(HNPluginModule hModule, const NWChar * szValue);
#endif
#define NPluginModuleSetPluginName N_FUNC_AW(NPluginModuleSetPluginName)

NResult N_API NPluginModuleGetInterfaceTypeN(HNPluginModule hModule, HNString * phValue);
#ifndef N_NO_ANSI_FUNC
N_DEPRECATED("function is deprecated, use NPluginModuleGetInterfaceTypeN instead")
NResult N_API NPluginModuleGetInterfaceTypeA(HNPluginModule hModule, NAChar * szValue, NInt valueSize);
#endif
#ifndef N_NO_UNICODE
N_DEPRECATED("function is deprecated, use NPluginModuleGetInterfaceTypeN instead")
NResult N_API NPluginModuleGetInterfaceTypeW(HNPluginModule hModule, NWChar * szValue, NInt valueSize);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NPluginModuleGetInterfaceType(HNPluginModule hModule, NChar * szValue, NInt valueSize);
#endif
#define NPluginModuleGetInterfaceType N_FUNC_AW(NPluginModuleGetInterfaceType)

NResult N_API NPluginModuleSetInterfaceTypeN(HNPluginModule hModule, HNString hValue);
#ifndef N_NO_ANSI_FUNC
NResult N_API NPluginModuleSetInterfaceTypeA(HNPluginModule hModule, const NAChar * szValue);
#endif
#ifndef N_NO_UNICODE
NResult N_API NPluginModuleSetInterfaceTypeW(HNPluginModule hModule, const NWChar * szValue);
#endif
#define NPluginModuleSetInterfaceType N_FUNC_AW(NPluginModuleSetInterfaceType)

NResult N_API NPluginModuleGetInterfaceVersions(HNPluginModule hModule, NVersionRange_ * arValues, NInt valuesLength);

NResult N_API NPluginModuleGetPriority(HNPluginModule hModule, NInt * pValue);
NResult N_API NPluginModuleSetPriority(HNPluginModule hModule, NInt value);

NResult N_API NPluginModuleGetIncompatiblePluginsN(HNPluginModule hModule, HNString * phValue);
#ifndef N_NO_ANSI_FUNC
N_DEPRECATED("function is deprecated, use NPluginModuleGetIncompatiblePluginsN instead")
NResult N_API NPluginModuleGetIncompatiblePluginsA(HNPluginModule hModule, NAChar * szValue, NInt valueSize);
#endif
#ifndef N_NO_UNICODE
N_DEPRECATED("function is deprecated, use NPluginModuleGetIncompatiblePluginsN instead")
NResult N_API NPluginModuleGetIncompatiblePluginsW(HNPluginModule hModule, NWChar * szValue, NInt valueSize);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NPluginModuleGetIncompatiblePlugins(HNPluginModule hModule, NChar * szValue, NInt valueSize);
#endif
#define NPluginModuleGetIncompatiblePlugins N_FUNC_AW(NPluginModuleGetIncompatiblePlugins)

NResult N_API NPluginModuleSetIncompatiblePluginsN(HNPluginModule hModule, HNString hValue);
#ifndef N_NO_ANSI_FUNC
NResult N_API NPluginModuleSetIncompatiblePluginsA(HNPluginModule hModule, const NAChar * szValue);
#endif
#ifndef N_NO_UNICODE
NResult N_API NPluginModuleSetIncompatiblePluginsW(HNPluginModule hModule, const NWChar * szValue);
#endif
#define NPluginModuleSetIncompatiblePlugins N_FUNC_AW(NPluginModuleSetIncompatiblePlugins)

#define N_DECLARE_PLUGIN_MODULE(name) \
	NResult N_API name##ModuleOf(HNPluginModule * phValue);

#ifdef N_CPP
}
#endif

#endif // !N_PLUGIN_MODULE_H_INCLUDED
