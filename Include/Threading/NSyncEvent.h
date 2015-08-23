#ifndef N_SYNC_EVENT_H_INCLUDED
#define N_SYNC_EVENT_H_INCLUDED

#include <Threading/NWaitObject.h>

#ifdef N_CPP
extern "C"
{
#endif

N_DECLARE_OBJECT_TYPE(NSyncEvent, NWaitObject)

NResult N_API NSyncEventCreate(NBool manualReset, NBool initialState, HNSyncEvent * phSyncEvent);
NResult N_API NSyncEventCreateFromOSHandle(NHandle handle, NBool ownsHandle, HNSyncEvent * phSyncEvent);
#define NSyncEventReset(hSyncEvent) NObjectReset(hSyncEvent)
NResult N_API NSyncEventSet(HNSyncEvent hSyncEvent);
NResult N_API NSyncEventGetOSHandle(HNSyncEvent hSyncEvent, NHandle * phValue);

#ifdef N_CPP
}
#endif

#endif // !N_SYNC_EVENT_H_INCLUDED
