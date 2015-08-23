#ifndef N_ASYNC_OPERATION_H_INCLUDED
#define N_ASYNC_OPERATION_H_INCLUDED

#include <Core/NObject.h>
#include <Core/NCallback.h>

#ifdef N_CPP
extern "C"
{
#endif

typedef enum NAsyncStatus_
{
	nasNone = 0,
	nasStarted = 1,
	nasCompleted = 2,
	nasCanceled = 3,
	nasFaulted = 4
} NAsyncStatus;

N_DECLARE_TYPE(NAsyncStatus)

N_DECLARE_OBJECT_TYPE(NAsyncOperation, NObject)

typedef NResult (N_CALLBACK NAsyncCallback)(HNAsyncOperation hAsyncOperation, void * pParam);

NResult N_API NAsyncOperationWaitAny(HNAsyncOperation * arhAsyncOperations, NInt asyncOperationCount, NInt * pResult);
NResult N_API NAsyncOperationWaitAnyTimed(HNAsyncOperation * arhAsyncOperations, NInt asyncOperationCount, NInt timeoutMilliseconds, NInt * pResult);
NResult N_API NAsyncOperationWaitAll(HNAsyncOperation * arhAsyncOperations, NInt asyncOperationCount);
NResult N_API NAsyncOperationWaitAllTimed(HNAsyncOperation * arhAsyncOperations, NInt asyncOperationCount, NInt timeoutMilliseconds, NBool * pResult);

NResult N_API NAsyncOperationCancel(HNAsyncOperation hAsyncOperation, NBool block);
NResult N_API NAsyncOperationWait(HNAsyncOperation hAsyncOperation);
NResult N_API NAsyncOperationWaitTimed(HNAsyncOperation hAsyncOperation, NInt timeoutMilliseconds, NBool * pResult);

NResult N_API NAsyncOperationGetStatus(HNAsyncOperation hAsyncOperation, NAsyncStatus * pValue);
NResult N_API NAsyncOperationIsCompleted(HNAsyncOperation hAsyncOperation, NBool * pValue);
NResult N_API NAsyncOperationIsCanceled(HNAsyncOperation hAsyncOperation, NBool * pValue);
NResult N_API NAsyncOperationIsFaulted(HNAsyncOperation hAsyncOperation, NBool * pValue);
NResult N_API NAsyncOperationGetError(HNAsyncOperation hAsyncOperation, HNError * phValue);
NResult N_API NAsyncOperationGetResult(HNAsyncOperation hAsyncOperation, HNValue * phValue);

NResult N_API NAsyncOperationAddCompleted(HNAsyncOperation hAsyncOperation, HNCallback hCallback);
NResult N_API NAsyncOperationAddCompletedCallback(HNAsyncOperation hAsyncOperation, NObjectCallback pCallback, void * pParam);
NResult N_API NAsyncOperationRemoveCompleted(HNAsyncOperation hAsyncOperation, HNCallback hCallback);
NResult N_API NAsyncOperationRemoveCompletedCallback(HNAsyncOperation hAsyncOperation, NObjectCallback pCallback, void * pParam);

#ifdef N_CPP
}
#endif

#endif // !N_ASYNC_OPERATION_H_INCLUDED
