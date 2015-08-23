#ifndef N_PLUGIN_INTERNAL_H_INCLUDED
#define N_PLUGIN_INTERNAL_H_INCLUDED

#include <Plugins/NPlugin.h>

#ifdef N_CPP
extern "C"
{
#endif

typedef struct NPluginInterfaceVersionInfo_
{
	NVersionRange_ versionRange;
	const void * pInterface;
} NPluginInterfaceVersionInfo;

#define NPluginInterfaceVersionInfoConst(majorVersion, minorVersionFrom, minorVersionTo, functionTable) { NVersionRangeMake(NVersionMake(majorVersion, minorVersionFrom), NVersionMake(majorVersion, minorVersionTo)), &(functionTable) }

NResult N_API NPluginGetSelectedInterface(HNPlugin hPlugin, const void * * ppValue);

#ifdef N_CPP
}
#endif

#endif // !N_PLUGIN_INTERNAL_H_INCLUDED
