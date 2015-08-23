#ifndef N_RW_LOCK_H_INCLUDED
#define N_RW_LOCK_H_INCLUDED

#include <Core/NTypes.h>

#ifdef N_CPP
extern "C"
{
#endif

#if defined(N_APPLE)
	#ifdef N_64
		#define N_RW_LOCK_SIZE 200
	#else
		#define N_RW_LOCK_SIZE 128
	#endif
#elif defined(N_ANDROID)
	#define N_RW_LOCK_SIZE 40
#elif defined (N_WINDOWS)
	#define N_RW_LOCK_SIZE N_PTR_SIZE
#elif defined (N_LINUX)
	#ifdef N_64
		#define N_RW_LOCK_SIZE 56
	#else
		#define N_RW_LOCK_SIZE 32
	#endif
#elif defined (N_QNX)
	#define N_RW_LOCK_SIZE 48
#else
	#error NRWLock is unsupported on this platform
#endif

N_DECLATE_PRIMITIVE(NRWLock, N_RW_LOCK_SIZE)
N_DECLARE_TYPE(NRWLock)

void N_API NRWLockInit(NRWLock * pLock);
void N_API NRWLockDispose(NRWLock * pLock);
void N_API NRWLockEnterRead(NRWLock * pLock);
NBool N_API NRWLockTryEnterRead(NRWLock * pLock);
void N_API NRWLockExitRead(NRWLock * pLock);
void N_API NRWLockEnterWrite(NRWLock * pLock);
NBool N_API NRWLockTryEnterWrite(NRWLock * pLock);
void N_API NRWLockExitWrite(NRWLock * pLock);

#ifdef N_CPP
}
#endif

#endif // !N_RW_LOCK_H_INCLUDED
