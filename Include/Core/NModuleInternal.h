#ifndef N_MODULE_INTERNAL_H_INCLUDED
#define N_MODULE_INTERNAL_H_INCLUDED

#include <Core/NModule.h>

#ifdef N_CPP
extern "C"
{
#endif

typedef NResult (N_CALLBACK NModuleCreateProc)(HNModule * phModule);

typedef NResult (N_CALLBACK NModuleInitProc)(void);
typedef NResult (N_CALLBACK NModuleLazyInitProc)(void);
typedef NResult (N_CALLBACK NModuleThreadInitProc)(void);
typedef NResult (N_CALLBACK NModuleThreadUninitProc)(NBool isProcessTermination);
typedef NResult (N_CALLBACK NModuleUninitProc)(NBool isProcessTermination);
typedef NResult (N_CALLBACK NModuleGetActivatedProc)(HNString * phValue);

NResult N_API NModuleRegister(NModuleCreateProc pCreate, HNModule * phModule);
NResult N_API NModuleUnregister(HNModule * phModule);

NResult N_API NModuleSetDependences(HNModule hModule, NModuleOfProc * arpValues, NInt count);
NResult N_API NModuleSetInit(HNModule hModule, NModuleInitProc pValue);
NResult N_API NModuleSetLazyInit(HNModule hModule, NModuleLazyInitProc pValue);
NResult N_API NModuleSetThreadInit(HNModule hModule, NModuleThreadInitProc pValue);
NResult N_API NModuleSetThreadUninit(HNModule hModule, NModuleThreadUninitProc pValue);
NResult N_API NModuleSetUninit(HNModule hModule, NModuleUninitProc pValue);

NResult N_API NModuleSetActivatedProc(HNModule hModule, NModuleGetActivatedProc pValue);

NResult N_API NModuleSetTypes(HNModule hModule, NTypeOfProc * arpValues, NInt count);

#ifdef N_CPP
}
#endif

#endif // !N_MODULE_INTERNAL_H_INCLUDED
