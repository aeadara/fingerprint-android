#include <Core/NObject.h>

#ifndef N_MODULE_H_INCLUDED
#define N_MODULE_H_INCLUDED

#ifdef N_CPP
extern "C"
{
#endif

typedef enum NModuleOptions_
{
	nmoNone = 0,
	nmoDebug = 0x01,
	nmoProtected = 0x02,
	nmoUnicode = 0x04,
	nmoNoAnsiFunc = 0x08,
	nmoNoUnicode = 0x10,
	nmoLib = 0x20,
	nmoExe = 0x40,
} NModuleOptions;

N_DECLARE_TYPE(NModuleOptions)

typedef NResult (N_CALLBACK NModuleOfProc)(HNModule * phValue);

NResult N_API NModuleGetLoadedModules(HNModule * * parhValues, NInt * pValueCount);
NResult N_API NModuleLoadFromFileN(HNString hFileName, HNModule * phModule);
#ifndef N_NO_ANSI_FUNC
NResult N_API NModuleLoadFromFileA(const NAChar * szFileName, HNModule * phModule);
#endif
#ifndef N_NO_UNICODE
NResult N_API NModuleLoadFromFileW(const NWChar * szFileName, HNModule * phModule);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NModuleLoadFromFile(const NChar * szFileName, HNModule * phModule);
#endif
#define NModuleLoadFromFile N_FUNC_AW(NModuleLoadFromFile)

NResult N_API NModuleCreate(HNModule * phModule);

NResult N_API NModuleCheckInit(HNModule hModule, NBool lazy);
NResult N_API NModuleCheckInitP(NModuleOfProc pModuleOf, NBool lazy);

NResult N_API NModuleGetOptions(HNModule hModule, NModuleOptions * pValue);
NResult N_API NModuleSetOptions(HNModule hModule, NModuleOptions value);
NResult N_API NModuleGetDependences(HNModule hModule, HNModule * arhValues, NInt valuesLength);

NResult N_API NModuleGetNameN(HNModule hModule, HNString * phValue);
#ifndef N_NO_ANSI_FUNC
N_DEPRECATED("function is deprecated, use NModuleGetNameN instead")
NResult N_API NModuleGetNameA(HNModule hModule, NAChar * szValue, NInt valueSize);
#endif
#ifndef N_NO_UNICODE
N_DEPRECATED("function is deprecated, use NModuleGetNameN instead")
NResult N_API NModuleGetNameW(HNModule hModule, NWChar * szValue, NInt valueSize);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NModuleGetName(HNModule hModule, NChar * szValue, NInt valueSize);
#endif
#define NModuleGetName N_FUNC_AW(NModuleGetName)

NResult N_API NModuleSetNameN(HNModule hModule, HNString hValue);
#ifndef N_NO_ANSI_FUNC
NResult N_API NModuleSetNameA(HNModule hModule, const NAChar * szValue);
#endif
#ifndef N_NO_UNICODE
NResult N_API NModuleSetNameW(HNModule hModule, const NWChar * szValue);
#endif
#define NModuleSetName N_FUNC_AW(NModuleSetName)

NResult N_API NModuleGetTitleN(HNModule hModule, HNString * phValue);
#ifndef N_NO_ANSI_FUNC
N_DEPRECATED("function is deprecated, use NModuleGetTitleN instead")
NResult N_API NModuleGetTitleA(HNModule hModule, NAChar * szValue, NInt valueSize);
#endif
#ifndef N_NO_UNICODE
N_DEPRECATED("function is deprecated, use NModuleGetTitleN instead")
NResult N_API NModuleGetTitleW(HNModule hModule, NWChar * szValue, NInt valueSize);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NModuleGetTitle(HNModule hModule, NChar * szValue, NInt valueSize);
#endif
#define NModuleGetTitle N_FUNC_AW(NModuleGetTitle)

NResult N_API NModuleSetTitleN(HNModule hModule, HNString hValue);
#ifndef N_NO_ANSI_FUNC
NResult N_API NModuleSetTitleA(HNModule hModule, const NAChar * szValue);
#endif
#ifndef N_NO_UNICODE
NResult N_API NModuleSetTitleW(HNModule hModule, const NWChar * szValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NModuleSetTitle(HNModule hModule, const NChar * szValue);
#endif
#define NModuleSetTitle N_FUNC_AW(NModuleSetTitle)

NResult N_API NModuleGetProductN(HNModule hModule, HNString * phValue);
#ifndef N_NO_ANSI_FUNC
N_DEPRECATED("function is deprecated, use NModuleGetProductN instead")
NResult N_API NModuleGetProductA(HNModule hModule, NAChar * szValue, NInt valueSize);
#endif
#ifndef N_NO_UNICODE
N_DEPRECATED("function is deprecated, use NModuleGetProductN instead")
NResult N_API NModuleGetProductW(HNModule hModule, NWChar * szValue, NInt valueSize);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NModuleGetProduct(HNModule hModule, NChar * szValue, NInt valueSize);
#endif
#define NModuleGetProduct N_FUNC_AW(NModuleGetProduct)

NResult N_API NModuleSetProductN(HNModule hModule, HNString hValue);
#ifndef N_NO_ANSI_FUNC
NResult N_API NModuleSetProductA(HNModule hModule, const NAChar * szValue);
#endif
#ifndef N_NO_UNICODE
NResult N_API NModuleSetProductW(HNModule hModule, const NWChar * szValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NModuleSetProduct(HNModule hModule, const NChar * szValue);
#endif
#define NModuleSetProduct N_FUNC_AW(NModuleSetProduct)

NResult N_API NModuleGetCompanyN(HNModule hModule, HNString * phValue);
#ifndef N_NO_ANSI_FUNC
N_DEPRECATED("function is deprecated, use NModuleGetCompanyN instead")
NResult N_API NModuleGetCompanyA(HNModule hModule, NAChar * szValue, NInt valueSize);
#endif
#ifndef N_NO_UNICODE
N_DEPRECATED("function is deprecated, use NModuleGetCompanyN instead")
NResult N_API NModuleGetCompanyW(HNModule hModule, NWChar * szValue, NInt valueSize);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NModuleGetCompany(HNModule hModule, NChar * szValue, NInt valueSize);
#endif
#define NModuleGetCompany N_FUNC_AW(NModuleGetCompany)

NResult N_API NModuleSetCompanyN(HNModule hModule, HNString hValue);
#ifndef N_NO_ANSI_FUNC
NResult N_API NModuleSetCompanyA(HNModule hModule, const NAChar * szValue);
#endif
#ifndef N_NO_UNICODE
NResult N_API NModuleSetCompanyW(HNModule hModule, const NWChar * szValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NModuleSetCompany(HNModule hModule, const NChar * szValue);
#endif
#define NModuleSetCompany N_FUNC_AW(NModuleSetCompany)

NResult N_API NModuleGetCopyrightN(HNModule hModule, HNString * phValue);
#ifndef N_NO_ANSI_FUNC
N_DEPRECATED("function is deprecated, use NModuleGetCopyrightN instead")
NResult N_API NModuleGetCopyrightA(HNModule hModule, NAChar * szValue, NInt valueSize);
#endif
#ifndef N_NO_UNICODE
N_DEPRECATED("function is deprecated, use NModuleGetCopyrightN instead")
NResult N_API NModuleGetCopyrightW(HNModule hModule, NWChar * szValue, NInt valueSize);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NModuleGetCopyright(HNModule hModule, NChar * szValue, NInt valueSize);
#endif
#define NModuleGetCopyright N_FUNC_AW(NModuleGetCopyright)

NResult N_API NModuleSetCopyrightN(HNModule hModule, HNString hValue);
#ifndef N_NO_ANSI_FUNC
NResult N_API NModuleSetCopyrightA(HNModule hModule, const NAChar * szValue);
#endif
#ifndef N_NO_UNICODE
NResult N_API NModuleSetCopyrightW(HNModule hModule, const NWChar * szValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NModuleSetCopyright(HNModule hModule, const NChar * szValue);
#endif
#define NModuleSetCopyright N_FUNC_AW(NModuleSetCopyright)

NResult N_API NModuleGetId(HNModule hModule, HNString * phValue);
NResult N_API NModuleSetIdN(HNModule hModule, HNString hValue);
#ifndef N_NO_ANSI_FUNC
NResult N_API NModuleSetIdA(HNModule hModule, const NAChar * szValue);
#endif
#ifndef N_NO_UNICODE
NResult N_API NModuleSetIdW(HNModule hModule, const NWChar * szValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NModuleSetId(HNModule hModule, const NChar * szValue);
#endif
#define NModuleSetId N_FUNC_AW(NModuleSetId)

NResult N_API NModuleGetNativeId(HNModule hModule, HNString * phValue);
NResult N_API NModuleSetNativeIdN(HNModule hModule, HNString hValue);
#ifndef N_NO_ANSI_FUNC
NResult N_API NModuleSetNativeIdA(HNModule hModule, const NAChar * szValue);
#endif
#ifndef N_NO_UNICODE
NResult N_API NModuleSetNativeIdW(HNModule hModule, const NWChar * szValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NModuleSetNativeId(HNModule hModule, const NChar * szValue);
#endif
#define NModuleSetNativeId N_FUNC_AW(NModuleSetNativeId)

NResult N_API NModuleGetVersionMajor(HNModule hModule, NInt * pValue);
NResult N_API NModuleSetVersionMajor(HNModule hModule, NInt value);
NResult N_API NModuleGetVersionMinor(HNModule hModule, NInt * pValue);
NResult N_API NModuleSetVersionMinor(HNModule hModule, NInt value);
NResult N_API NModuleGetVersionBuild(HNModule hModule, NInt * pValue);
NResult N_API NModuleSetVersionBuild(HNModule hModule, NInt value);
NResult N_API NModuleGetVersionRevision(HNModule hModule, NInt * pValue);
NResult N_API NModuleSetVersionRevision(HNModule hModule, NInt value);

NResult N_API NModuleGetFileName(HNModule hModule, HNString * phValue);

NResult N_API NModuleGetActivatedN(HNModule hModule, HNString * phValue);
#ifndef N_NO_ANSI_FUNC
N_DEPRECATED("function is deprecated, use NModuleGetActivatedN instead")
NResult N_API NModuleGetActivatedA(HNModule hModule, NAChar * szValue, NInt valueSize);
#endif
#ifndef N_NO_UNICODE
N_DEPRECATED("function is deprecated, use NModuleGetActivatedN instead")
NResult N_API NModuleGetActivatedW(HNModule hModule, NWChar * szValue, NInt valueSize);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NModuleGetActivated(HNModule hModule, NChar * szValue, NInt valueSize);
#endif
#define NModuleGetActivated N_FUNC_AW(NModuleGetActivated)

NResult N_API NModuleGetDefinedTypeCount(HNModule hModule, NInt * pValue);
NResult N_API NModuleGetDefinedType(HNModule hModule, NInt index, HNType * phValue);
NResult N_API NModuleGetDefinedTypes(HNModule hModule, HNType * * parhValues, NInt * pValueCount);

NResult N_API NModuleGetTypeWithNameN(HNModule hModule, HNString hName, NBool mustExist, HNType * phValue);
#ifndef N_NO_ANSI_FUNC
NResult N_API NModuleGetTypeWithNameA(HNModule hModule, const NAChar * szName, NBool mustExist, HNType * phValue);
#endif
#ifndef N_NO_UNICODE
NResult N_API NModuleGetTypeWithNameW(HNModule hModule, const NWChar * szName, NBool mustExist, HNType * phValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NModuleGetTypeWithName(HNModule hModule, const NChar * szName, NBool mustExist, HNType * phValue);
#endif
#define NModuleGetTypeWithName N_FUNC_AW(NModuleGetTypeWithName)

NResult N_API NModuleCreateInstanceN(HNModule hModule, HNString hName, NAttributes attributes, HNValue * phValue);
#ifndef N_NO_ANSI_FUNC
NResult N_API NModuleCreateInstanceA(HNModule hModule, const NAChar * szName, NAttributes attributes, HNValue * phValue);
#endif
#ifndef N_NO_UNICODE
NResult N_API NModuleCreateInstanceW(HNModule hModule, const NWChar * szName, NAttributes attributes, HNValue * phValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NModuleCreateInstance(HNModule hModule, const NChar * szName, NAttributes attributes, HNValue * phValue);
#endif
#define NModuleCreateInstance N_FUNC_AW(NModuleCreateInstance)

#define N_DECLARE_MODULE(name) \
	NResult N_API name##ModuleOf(HNModule * phValue);

#define N_MODULE_OF(name) N_JOIN_SYMBOLS(name, ModuleOf)

#ifdef N_CPP
}
#endif

#endif // !N_MODULE_H_INCLUDED
