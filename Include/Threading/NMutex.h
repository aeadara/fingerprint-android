#ifndef N_MUTEX_H_INCLUDED
#define N_MUTEX_H_INCLUDED

#include <Threading/NWaitObject.h>

#ifdef N_CPP
extern "C"
{
#endif

N_DECLARE_OBJECT_TYPE(NMutex, NWaitObject)

NResult N_API NMutexCreate(NBool initiallyOwned, HNMutex * phMutex);
NResult N_API NMutexCreateFromOSHandle(NHandle handle, NBool ownsHandle, HNMutex * phMutex);
NResult N_API NMutexRelease(HNMutex hMutex);
NResult N_API NMutexGetOSHandle(HNMutex hMutex, NHandle * phValue);

#ifdef N_CPP
}
#endif

#endif // !N_MUTEX_H_INCLUDED
