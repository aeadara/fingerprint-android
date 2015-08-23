#ifndef N_SEMAPHORE_H_INCLUDED
#define N_SEMAPHORE_H_INCLUDED

#include <Threading/NWaitObject.h>

#ifdef N_CPP
extern "C"
{
#endif

N_DECLARE_OBJECT_TYPE(NSemaphore, NWaitObject)

NResult N_API NSemaphoreCreate(NInt initialCount, HNSemaphore * phSemaphore);
NResult N_API NSemaphoreCreateFromOSHandle(NHandle handle, NBool ownsHandle, HNSemaphore * phSemaphore);
NResult N_API NSemaphoreRelease(HNSemaphore hSemaphore);
NResult N_API NSemaphoreGetOSHandle(HNSemaphore hSemaphore, NHandle * phValue);

#ifdef N_CPP
}
#endif

#endif // !N_SEMAPHORE_H_INCLUDED
