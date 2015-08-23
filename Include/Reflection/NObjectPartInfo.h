#include <Reflection/NMemberInfo.h>
#include <Reflection/NConstantInfo.h>
#include <Reflection/NMethodInfo.h>
#include <Reflection/NPropertyInfo.h>
#include <Reflection/NEventInfo.h>

#ifndef N_OBJECT_PART_INFO_H_INCLUDED
#define N_OBJECT_PART_INFO_H_INCLUDED

#ifdef N_CPP
extern "C"
{
#endif

NResult N_API NObjectPartInfoGetPropertyName(HNObjectPartInfo hObjectPartInfo, HNString * phValue);

NResult N_API NObjectPartInfoGetDeclaredConstantCount(HNObjectPartInfo hObjectPartInfo, NInt * pValue);
NResult N_API NObjectPartInfoGetDeclaredConstant(HNObjectPartInfo hObjectPartInfo, NInt index, HNConstantInfo * phValue);
NResult N_API NObjectPartInfoGetDeclaredConstants(HNObjectPartInfo hObjectPartInfo, HNConstantInfo * * parhValues, NInt * pValueCount);

NResult N_API NObjectPartInfoGetDeclaredConstantWithNameN(HNObjectPartInfo hObjectPartInfo, HNString hName, HNConstantInfo * phValue);
#ifndef N_NO_ANSI_FUNC
NResult N_API NObjectPartInfoGetDeclaredConstantWithNameA(HNObjectPartInfo hObjectPartInfo, const NAChar * szName, HNConstantInfo * phValue);
#endif
#ifndef N_NO_UNICODE
NResult N_API NObjectPartInfoGetDeclaredConstantWithNameW(HNObjectPartInfo hObjectPartInfo, const NWChar * szName, HNConstantInfo * phValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NObjectPartInfoGetDeclaredConstantWithName(HNObjectPartInfo hObjectPartInfo, const NChar * szName, HNConstantInfo * phValue);
#endif
#define NObjectPartInfoGetDeclaredConstantWithName N_FUNC_AW(NObjectPartInfoGetDeclaredConstantWithName)

NResult N_API NObjectPartInfoGetDeclaredMethodCount(HNObjectPartInfo hObjectPartInfo, NInt * pValue);
NResult N_API NObjectPartInfoGetDeclaredMethod(HNObjectPartInfo hObjectPartInfo, NInt index, HNMethodInfo * phValue);
NResult N_API NObjectPartInfoGetDeclaredMethods(HNObjectPartInfo hObjectPartInfo, HNMethodInfo * * parhValues, NInt * pValueCount);

NResult N_API NObjectPartInfoGetDeclaredMethodWithNameN(HNObjectPartInfo hObjectPartInfo, HNString hName, HNMethodInfo * phValue);
#ifndef N_NO_ANSI_FUNC
NResult N_API NObjectPartInfoGetDeclaredMethodWithNameA(HNObjectPartInfo hObjectPartInfo, const NAChar * szName, HNMethodInfo * phValue);
#endif
#ifndef N_NO_UNICODE
NResult N_API NObjectPartInfoGetDeclaredMethodWithNameW(HNObjectPartInfo hObjectPartInfo, const NWChar * szName, HNMethodInfo * phValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NObjectPartInfoGetDeclaredMethodWithName(HNObjectPartInfo hObjectPartInfo, const NChar * szName, HNMethodInfo * phValue);
#endif
#define NObjectPartInfoGetDeclaredMethodWithName N_FUNC_AW(NObjectPartInfoGetDeclaredMethodWithName)

NResult N_API NObjectPartInfoGetDeclaredMethodsWithNameN(HNObjectPartInfo hObjectPartInfo, HNString hName, HNMethodInfo * * parhValues, NInt * pValueCount);
#ifndef N_NO_ANSI_FUNC
NResult N_API NObjectPartInfoGetDeclaredMethodsWithNameA(HNObjectPartInfo hObjectPartInfo, const NAChar * szName, HNMethodInfo * * parhValues, NInt * pValueCount);
#endif
#ifndef N_NO_UNICODE
NResult N_API NObjectPartInfoGetDeclaredMethodsWithNameW(HNObjectPartInfo hObjectPartInfo, const NWChar * szName, HNMethodInfo * * parhValues, NInt * pValueCount);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NObjectPartInfoGetDeclaredMethodsWithName(HNObjectPartInfo hObjectPartInfo, const NChar * szName, HNMethodInfo * * parhValues, NInt * pValueCount);
#endif
#define NObjectPartInfoGetDeclaredMethodsWithName N_FUNC_AW(NObjectPartInfoGetDeclaredMethodsWithName)

NResult N_API NObjectPartInfoGetDeclaredPropertyCount(HNObjectPartInfo hObjectPartInfo, NInt * pValue);
NResult N_API NObjectPartInfoGetDeclaredProperty(HNObjectPartInfo hObjectPartInfo, NInt index, HNPropertyInfo * phValue);
NResult N_API NObjectPartInfoGetDeclaredProperties(HNObjectPartInfo hObjectPartInfo, HNPropertyInfo * * parhValues, NInt * pValueCount);

NResult N_API NObjectPartInfoGetDeclaredPropertyWithNameN(HNObjectPartInfo hObjectPartInfo, HNString hName, HNPropertyInfo * phValue);
#ifndef N_NO_ANSI_FUNC
NResult N_API NObjectPartInfoGetDeclaredPropertyWithNameA(HNObjectPartInfo hObjectPartInfo, const NAChar * szName, HNPropertyInfo * phValue);
#endif
#ifndef N_NO_UNICODE
NResult N_API NObjectPartInfoGetDeclaredPropertyWithNameW(HNObjectPartInfo hObjectPartInfo, const NWChar * szName, HNPropertyInfo * phValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NObjectPartInfoGetDeclaredPropertyWithName(HNObjectPartInfo hObjectPartInfo, const NChar * szName, HNPropertyInfo * phValue);
#endif
#define NObjectPartInfoGetDeclaredPropertyWithName N_FUNC_AW(NObjectPartInfoGetDeclaredPropertyWithName)

NResult N_API NObjectPartInfoGetDeclaredEventCount(HNObjectPartInfo hObjectPartInfo, NInt * pValue);
NResult N_API NObjectPartInfoGetDeclaredEvent(HNObjectPartInfo hObjectPartInfo, NInt index, HNEventInfo * phValue);
NResult N_API NObjectPartInfoGetDeclaredEvents(HNObjectPartInfo hObjectPartInfo, HNEventInfo * * parhValues, NInt * pValueCount);

NResult N_API NObjectPartInfoGetDeclaredEventWithNameN(HNObjectPartInfo hObjectPartInfo, HNString hName, HNEventInfo * phValue);
#ifndef N_NO_ANSI_FUNC
NResult N_API NObjectPartInfoGetDeclaredEventWithNameA(HNObjectPartInfo hObjectPartInfo, const NAChar * szName, HNEventInfo * phValue);
#endif
#ifndef N_NO_UNICODE
NResult N_API NObjectPartInfoGetDeclaredEventWithNameW(HNObjectPartInfo hObjectPartInfo, const NWChar * szName, HNEventInfo * phValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NObjectPartInfoGetDeclaredEventWithName(HNObjectPartInfo hObjectPartInfo, const NChar * szName, HNEventInfo * phValue);
#endif
#define NObjectPartInfoGetDeclaredEventWithName N_FUNC_AW(NObjectPartInfoGetDeclaredEventWithName)

NResult N_API NObjectPartInfoGetObjectPart(HNObjectPartInfo hObjectPartInfo, HNObject hObject, HNObjectPart * phObjectPart);

#ifdef N_CPP
}
#endif

#endif // !N_OBJECT_PART_INFO_H_INCLUDED
