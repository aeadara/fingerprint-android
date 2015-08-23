#ifndef N_THREAD_H_INCLUDED
#define N_THREAD_H_INCLUDED

#include <Core/NObject.h>

#ifdef N_CPP
extern "C"
{
#endif

N_DECLARE_OBJECT_TYPE(NThread, NObject)

NResult N_API NThreadSleep(NInt milliseconds);
NResult N_API NThreadGetCurrentId(NSizeType * pValue);
NResult N_API NThreadGetCurrent(HNThread * phValue);

typedef NResult (N_CALLBACK NThreadStartProc)(void * pParam);
typedef NResult (N_CALLBACK NParameterizedThreadStartProc)(HNObject hObj, void * pParam);

NResult N_API NThreadCreateN(HNCallback hThreadStart, HNThread * phThread);
NResult N_API NThreadCreate(NThreadStartProc pThreadStart, void * pThreadStartParam, HNThread * phThread);
NResult N_API NThreadCreateParameterizedN(HNCallback hThreadStart, HNObject hParameter, HNThread * phThread);
NResult N_API NThreadCreateParameterized(NParameterizedThreadStartProc pThreadStart, void * pThreadStartParam, HNObject hParameter, HNThread * phThread);
NResult N_API NThreadCreateFromOSHandle(NHandle handle, NBool ownsHandle, HNThread * phThread);
NResult N_API NThreadJoin(HNThread hThread);
NResult N_API NThreadGetOSHandle(HNThread hThread, NHandle * phValue);
NResult N_API NThreadGetId(HNThread hThread, NSizeType * pValue);

#ifdef N_CPP
}
#endif

#endif // !N_THREAD_H_INCLUDED
