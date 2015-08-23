#ifndef N_CALLBACK_H_INCLUDED
#define N_CALLBACK_H_INCLUDED

#include <Core/NTypes.h>

#ifdef N_CPP
extern "C"
{
#endif

NResult N_API NCallbackCreateRaw(void * pProc, void * pParam, HNCallback * phCallback);
#define NCallbackCreate(pProc, pParam, phCallback) NCallbackCreateRaw((void *)(NSizeType)pProc, pParam, phCallback)
NResult N_API NCallbackCreateCustomRaw(void * pProc, void * pParam, NPointerFreeProc pFree, NPointerGetHashCodeProc pGetHashCode, NPointerEqualsProc pEquals, HNCallback * phCallback);
#define NCallbackCreateCustom(pProc, pParam, pFree, pGetHashCode, pEquals, phCallback) NCallbackCreateCustomRaw((void *)(NSizeType)pProc, pParam, pFree, pGetHashCode, pEquals, phCallback)
NResult N_API NCallbackCreateWithObjectRaw(void * pProc, HNObject hObject, HNCallback * phCallback);
#define NCallbackCreateWithObject(pProc, hObject, phCallback) NCallbackCreateWithObjectRaw((void *)(NSizeType)pProc, hObject, phCallback)
NResult N_API NCallbackClone(HNCallback hCallback, HNCallback * phClonedCallback);
NResult N_API NCallbackFree(HNCallback hCallback);
#define NCallbackGet(hValue, phValue) NCallbackClone(hValue, phValue)
NResult N_API NCallbackSet(HNCallback hValue, HNCallback * phVariable);
NResult N_API NCallbackGetHashCode(HNCallback hCallback, NInt * pValue);
NResult N_API NCallbackEquals(HNCallback hCallback, HNCallback hOtherCallback, NBool * pResult);
void * N_API_PTR_RET NCallbackGetProcRaw(HNCallback hCallback);
#define NCallbackGetProc(callbackType, hCallback) ((callbackType)(NSizeType)NCallbackGetProcRaw(hCallback))
void * N_API_PTR_RET NCallbackGetParam(HNCallback hCallback);

#define NCallbackInvokeRaw(callbackType, hCallback, args) (NCallbackGetProc(callbackType, hCallback)args)

#define NCallbackInvoke0(callbackType, hCallback) NCallbackInvokeRaw(callbackType, hCallback, (NCallbackGetParam(hCallback)))
#define NCallbackInvoke1(callbackType, hCallback, arg1) NCallbackInvokeRaw(callbackType, hCallback, ((arg1), NCallbackGetParam(hCallback)))
#define NCallbackInvoke2(callbackType, hCallback, arg1, arg2) NCallbackInvokeRaw(callbackType, hCallback, ((arg1), (arg2), NCallbackGetParam(hCallback)))
#define NCallbackInvoke3(callbackType, hCallback, arg1, arg2, arg3) NCallbackInvokeRaw(callbackType, hCallback, ((arg1), (arg2), (arg3), NCallbackGetParam(hCallback)))
#define NCallbackInvoke4(callbackType, hCallback, arg1, arg2, arg3, arg4) NCallbackInvokeRaw(callbackType, hCallback, ((arg1), (arg2), (arg3), (arg4), NCallbackGetParam(hCallback)))
#define NCallbackInvoke5(callbackType, hCallback, arg1, arg2, arg3, arg4, arg5) NCallbackInvokeRaw(callbackType, hCallback, ((arg1), (arg2), (arg3), (arg4), (arg5), NCallbackGetParam(hCallback)))
#define NCallbackInvoke6(callbackType, hCallback, arg1, arg2, arg3, arg4, arg5, arg6) NCallbackInvokeRaw(callbackType, hCallback, ((arg1), (arg2), (arg3), (arg4), (arg5), (arg6), NCallbackGetParam(hCallback)))
#define NCallbackInvoke7(callbackType, hCallback, arg1, arg2, arg3, arg4, arg5, arg6, arg7) NCallbackInvokeRaw(callbackType, hCallback, ((arg1), (arg2), (arg3), (arg4), (arg5), (arg6), (arg7), NCallbackGetParam(hCallback)))
#define NCallbackInvoke8(callbackType, hCallback, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8) NCallbackInvokeRaw(callbackType, hCallback, ((arg1), (arg2), (arg3), (arg4), (arg5), (arg6), (arg7), (arg8), NCallbackGetParam(hCallback)))
#define NCallbackInvoke9(callbackType, hCallback, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9) NCallbackInvokeRaw(callbackType, hCallback, ((arg1), (arg2), (arg3), (arg4), (arg5), (arg6), (arg7), (arg8), (arg9), NCallbackGetParam(hCallback)))

#ifdef N_CPP
}
#endif

#endif // !N_CALLBACK_H_INCLUDED
