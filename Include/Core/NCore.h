#ifndef N_CORE_H_INCLUDED
#define N_CORE_H_INCLUDED

#include <Core/NObject.h>
#include <Core/NModule.h>

#ifdef N_CPP
extern "C"
{
#endif

N_DECLARE_MODULE(NCore)

N_DECLARE_STATIC_OBJECT_TYPE(NCore)

NResult N_API NCoreOnStart(void);
NResult N_API NCoreOnThreadStart(void);
NResult N_API NCoreOnThreadExit(void);
NResult N_API NCoreOnExitEx(NBool isProcessTermination);

typedef NResult (N_CALLBACK NErrorSuppressedCallback)(NResult errorCode, HNError hError, void * pParam);
N_DECLARE_TYPE(NErrorSuppressedCallback)

NResult N_API NCoreAddErrorSuppressed(HNCallback hCallback);
NResult N_API NCoreAddErrorSuppressedCallback(NErrorSuppressedCallback pCallback, void * pParam);
NResult N_API NCoreRemoveErrorSuppressed(HNCallback hCallback);
NResult N_API NCoreRemoveErrorSuppressedCallback(NErrorSuppressedCallback pCallback, void * pParam);

#ifdef N_CPP
}
#endif

#endif // !N_CORE_H_INCLUDED
