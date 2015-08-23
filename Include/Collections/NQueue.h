#ifndef N_QUEUE_H_INCLUDED
#define N_QUEUE_H_INCLUDED

#include <Core/NType.h>

#ifdef N_CPP
extern "C"
{
#endif

#ifdef N_64
	#define N_QUEUE_SIZE 56
#else
	#define N_QUEUE_SIZE 36
#endif

N_DECLATE_PRIMITIVE(NQueue, N_QUEUE_SIZE)
N_DECLARE_TYPE(NQueue)

NResult N_API NQueueInitP(NQueue * pQueue, NSizeType elementSize, NTypeOfProc pElementTypeOf);
NResult N_API NQueueInit(NQueue * pQueue, NSizeType elementSize, HNType hElementType);
NResult N_API NQueueInitWithCapacityP(NQueue * pQueue, NSizeType elementSize, NTypeOfProc pElementTypeOf, NInt capacity);
NResult N_API NQueueInitWithCapacity(NQueue * pQueue, NSizeType elementSize, HNType hElementType, NInt capacity);
NResult N_API NQueueInitExP(NQueue * pQueue, NSizeType elementSize, NTypeOfProc pElementTypeOf, NInt capacity, NInt maxCapacity, NInt growthDelta, NSizeType alignment);
NResult N_API NQueueInitEx(NQueue * pQueue, NSizeType elementSize, HNType hElementType, NInt capacity, NInt maxCapacity, NInt growthDelta, NSizeType alignment);
NResult N_API NQueueDispose(NQueue * pQueue);
NResult N_API NQueueGetCapacity(NQueue * pQueue, NInt * pValue);
NResult N_API NQueueSetCapacity(NQueue * pQueue, NInt value);
NResult N_API NQueueGetCount(NQueue * pQueue, NInt * pValue);
NResult N_API NQueueContains(NQueue * pQueue, HNType hValueType, const void * pValue, NSizeType valueSize, NBool * pResult);
NResult N_API NQueueContainsP(NQueue * pQueue, NTypeOfProc pValueTypeOf, const void * pValue, NSizeType valueSize, NBool * pResult);
NResult N_API NQueueGetFront(NQueue * pQueue, NSizeType elementSize, HNType hValueType, void * * ppValue);
NResult N_API NQueueGetFrontP(NQueue * pQueue, NSizeType elementSize, NTypeOfProc pValueTypeOf, void * * ppValue);
NResult N_API NQueuePeek(NQueue * pQueue, HNType hValueType, void * pValue, NSizeType valueSize);
NResult N_API NQueuePeekP(NQueue * pQueue, NTypeOfProc pValueTypeOf, void * pValue, NSizeType valueSize);
NResult N_API NQueueDequeue(NQueue * pQueue, HNType hValueType, void * pValue, NSizeType valueSize);
NResult N_API NQueueDequeueP(NQueue * pQueue, NTypeOfProc pValueTypeOf, void * pValue, NSizeType valueSize);
NResult N_API NQueueEnqueue(NQueue * pQueue, HNType hValueType, const void * pValue, NSizeType valueSize);
NResult N_API NQueueEnqueueP(NQueue * pQueue, NTypeOfProc pValueTypeOf, const void * pValue, NSizeType valueSize);
NResult N_API NQueueClear(NQueue * pQueue);
NResult N_API NQueueCopyTo(NQueue * pQueue, HNType hValueType, void * pValues, NSizeType valuesSize, NInt valuesLength);
NResult N_API NQueueCopyToP(NQueue * pQueue, NTypeOfProc pValueTypeOf, void * pValues, NSizeType valuesSize, NInt valuesLength);
NResult N_API NQueueToArray(NQueue * pQueue, NSizeType elementSize, HNType hValueType, void * * ppValues, NInt * pValuesLength);
NResult N_API NQueueToArrayP(NQueue * pQueue, NSizeType elementSize, NTypeOfProc pValueTypeOf, void * * ppValues, NInt * pValuesLength);

#ifdef N_CPP
}
#endif

#endif // !N_QUEUE_H_INCLUDED
