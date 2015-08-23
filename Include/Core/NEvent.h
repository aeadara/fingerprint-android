#ifndef N_EVENT_H_INCLUDED
#define N_EVENT_H_INCLUDED

#include <Core/NCallback.h>

#ifdef N_CPP
extern "C"
{
#endif

#ifdef N_64
	#define N_EVENT_SIZE 16
#else
	#define N_EVENT_SIZE 8
#endif

N_DECLATE_PRIMITIVE(NEvent, N_EVENT_SIZE)
N_DECLARE_TYPE(NEvent)

NResult N_API NEventInit(NEvent * pEvent);
NResult N_API NEventDispose(NEvent * pEvent);
NResult N_API NEventIsEmpty(NEvent * pEvent, NBool * pResult);
NResult N_API NEventAddN(NEvent * pEvent, HNCallback hCallback);
NResult N_API NEventAddRaw(NEvent * pEvent, void * pProc, void * pParam);
#define NEventAdd(pEvent, pProc, pParam) NEventAddRaw(pEvent, (void *)(NSizeType)pProc, pParam)
NResult N_API NEventRemoveN(NEvent * pEvent, HNCallback hCallback);
NResult N_API NEventRemoveRaw(NEvent * pEvent, void * pProc, void * pParam);
#define NEventRemove(pEvent, pProc, pParam) NEventRemoveRaw(pEvent, (void *)(NSizeType)pProc, pParam)
NResult N_API NEventGetCallbacks(NEvent * pEvent, HNCallback * * parhCallbacks, NInt * pCount);
NResult N_API NEventReleaseCallbacks(NEvent * pEvent, HNCallback * arhCallbacks, NInt count);

#define N_EVENT_RAISE_RAW(callbackType, pEvent, args) \
	{\
		NResult N_EVENT_RAISE_RAW_res = N_OK;\
		HNCallback * N_EVENT_RAISE_RAW_arhCallbacks;\
		NInt N_EVENT_RAISE_RAW_count;\
		N_CHECK(NEventGetCallbacks(pEvent, &N_EVENT_RAISE_RAW_arhCallbacks, &N_EVENT_RAISE_RAW_count));\
		N_FOREACH(HNCallback, N_EVENT_RAISE_RAW_hCallback, N_EVENT_RAISE_RAW_arhCallbacks, N_EVENT_RAISE_RAW_count)\
			N_EVENT_RAISE_RAW_res = NCallbackInvokeRaw(callbackType, N_EVENT_RAISE_RAW_hCallback, args);\
			if (NFailed(N_EVENT_RAISE_RAW_res)) break;\
		N_FOREACH_END\
		N_CHECK(NEventReleaseCallbacks(pEvent, N_EVENT_RAISE_RAW_arhCallbacks, N_EVENT_RAISE_RAW_count));\
		N_CHECK(N_EVENT_RAISE_RAW_res);\
	}

#define N_EVENT_RAISE_1(callbackType, pEvent, arg1) N_EVENT_RAISE_RAW(callbackType, pEvent, ((arg1), NCallbackGetParam(N_EVENT_RAISE_RAW_hCallback)))
#define N_EVENT_RAISE_2(callbackType, pEvent, arg1, arg2) N_EVENT_RAISE_RAW(callbackType, pEvent, ((arg1), (arg2), NCallbackGetParam(N_EVENT_RAISE_RAW_hCallback)))
#define N_EVENT_RAISE_3(callbackType, pEvent, arg1, arg2, arg3) N_EVENT_RAISE_RAW(callbackType, pEvent, ((arg1), (arg2), (arg3), NCallbackGetParam(N_EVENT_RAISE_RAW_hCallback)))
#define N_EVENT_RAISE_4(callbackType, pEvent, arg1, arg2, arg3, arg4) N_EVENT_RAISE_RAW(callbackType, pEvent, ((arg1), (arg2), (arg3), (arg4), NCallbackGetParam(N_EVENT_RAISE_RAW_hCallback)))
#define N_EVENT_RAISE_5(callbackType, pEvent, arg1, arg2, arg3, arg4, arg5) N_EVENT_RAISE_RAW(callbackType, pEvent, ((arg1), (arg2), (arg3), (arg4), (arg5), NCallbackGetParam(N_EVENT_RAISE_RAW_hCallback)))
#define N_EVENT_RAISE_6(callbackType, pEvent, arg1, arg2, arg3, arg4, arg5, arg6) N_EVENT_RAISE_RAW(callbackType, pEvent, ((arg1), (arg2), (arg3), (arg4), (arg5), (arg6), NCallbackGetParam(N_EVENT_RAISE_RAW_hCallback)))
#define N_EVENT_RAISE_7(callbackType, pEvent, arg1, arg2, arg3, arg4, arg5, arg6, arg7) N_EVENT_RAISE_RAW(callbackType, pEvent, ((arg1), (arg2), (arg3), (arg4), (arg5), (arg6), (arg7), NCallbackGetParam(N_EVENT_RAISE_RAW_hCallback)))
#define N_EVENT_RAISE_8(callbackType, pEvent, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8) N_EVENT_RAISE_RAW(callbackType, pEvent, ((arg1), (arg2), (arg3), (arg4), (arg5), (arg6), (arg7), (arg8), NCallbackGetParam(N_EVENT_RAISE_RAW_hCallback)))

#ifdef N_CPP
}
#endif

#endif // !N_EVENT_H_INCLUDED
