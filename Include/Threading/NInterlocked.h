#ifndef N_INTERLOCKED_H_INCLUDED
#define N_INTERLOCKED_H_INCLUDED

#include <Core/NTypes.h>
#include <Interop/NWindows.h>

#ifdef N_CPP
extern "C"
{
#endif

NInt N_API NInterlockedCompareExchangeImpl(NInt volatile * pDst, NInt exch, NInt comp);
void * N_API_PTR_RET NInterlockedCompareExchangePointerImpl(void * volatile * pDst, void * exch, void * comp);
NInt N_API NInterlockedIncrementImpl(NInt volatile * pDst);
NInt N_API NInterlockedDecrementImpl(NInt volatile * pDst);
NInt N_API NInterlockedAddImpl(NInt volatile * pDst, NInt val);
NInt N_API NInterlockedAndImpl(NInt volatile * pDst, NInt val);
NInt N_API NInterlockedOrImpl(NInt volatile * pDst, NInt val);
NInt N_API NInterlockedXorImpl(NInt volatile * pDst, NInt val);
NInt N_API NInterlockedExchangeImpl(NInt volatile * pDst, NInt exch);
void * N_API_PTR_RET NInterlockedExchangePointerImpl(void * volatile * pDst, void * exch);
NInt N_API NInterlockedExchangeAddImpl(NInt volatile * pDst, NInt val);

#if defined(N_WINDOWS)

#ifdef N_WINDOWS_CE
	#define N_INTERLOCKED_VOLATILE
#else
	#define N_INTERLOCKED_VOLATILE volatile
#endif

#define NInterlockedCompareExchange(pDst, exch, comp) (NInt)InterlockedCompareExchange((long N_INTERLOCKED_VOLATILE *)pDst, (long)(exch), (long)(comp))
#define NInterlockedCompareExchangePointer(pDst, exch, comp) InterlockedCompareExchangePointer(pDst, exch, comp)
#define NInterlockedIncrement(pDst) (NInt)InterlockedIncrement((long N_INTERLOCKED_VOLATILE *)pDst)
#define NInterlockedDecrement(pDst) (NInt)InterlockedDecrement((long N_INTERLOCKED_VOLATILE *)pDst)
#define NInterlockedAdd(pDst, val) ((NInt)InterlockedExchangeAdd((long N_INTERLOCKED_VOLATILE *)pDst, (long)(val)) + (NInt)val)
#define NInterlockedAnd(pDst, val) (NInt)_InterlockedAnd((long N_INTERLOCKED_VOLATILE *)pDst, (long)(val))
#define NInterlockedOr(pDst, val) (NInt)_InterlockedOr((long N_INTERLOCKED_VOLATILE *)pDst, (long)(val))
#define NInterlockedXor(pDst, val) (NInt)_InterlockedXor((long N_INTERLOCKED_VOLATILE *)pDst, (long)(val))
#define NInterlockedExchange(pDst, exch) (NInt)InterlockedExchange((long N_INTERLOCKED_VOLATILE *)pDst, (long)(exch))
#define NInterlockedExchangePointer(pDst, exch) InterlockedExchangePointer(pDst, exch)
#define NInterlockedExchangeAdd(pDst, val) (NInt)InterlockedExchangeAdd((long N_INTERLOCKED_VOLATILE *)pDst, (long)(val))

#elif defined(N_GCC) && (!defined(N_ARM) || N_GCC_VERSION >= 40400)

#define NInterlockedCompareExchange(pDst, exch, comp) __sync_val_compare_and_swap(pDst, comp, exch)
#define NInterlockedCompareExchangePointer(pDst, exch, comp) __sync_val_compare_and_swap(pDst, comp, exch)
#define NInterlockedIncrement(pDst) __sync_add_and_fetch(pDst, 1)
#define NInterlockedDecrement(pDst) __sync_sub_and_fetch(pDst, 1)
#define NInterlockedAdd(pDst, val) __sync_add_and_fetch(pDst, val)
#define NInterlockedAnd(pDst, val) __sync_fetch_and_and(pDst, val)
#define NInterlockedOr(pDst, val) __sync_fetch_and_or(pDst, val)
#define NInterlockedXor(pDst, val) __sync_fetch_and_xor(pDst, val)
#define NInterlockedExchange(pDst, exch) __sync_lock_test_and_set(pDst, exch)
#define NInterlockedExchangePointer(pDst, exch) __sync_lock_test_and_set(pDst, exch)
#define NInterlockedExchangeAdd(pDst, val) __sync_fetch_and_add(pDst, val)

#else

#define N_SLOW_INTERLOCKED

#define NInterlockedCompareExchange(pDst, exch, comp) NInterlockedCompareExchangeImpl(pDst, exch, comp)
#define NInterlockedCompareExchangePointer(pDst, exch, comp) NInterlockedCompareExchangePointerImpl(pDst, exch, comp)
#define NInterlockedIncrement(pDst) NInterlockedIncrementImpl(pDst)
#define NInterlockedDecrement(pDst) NInterlockedDecrementImpl(pDst)
#define NInterlockedAdd(pDst, val) NInterlockedAddImpl(pDst, val)
#define NInterlockedAnd(pDst, val) NInterlockedAndImpl(pDst, val)
#define NInterlockedOr(pDst, val) NInterlockedOrImpl(pDst, val)
#define NInterlockedXor(pDst, val) NInterlockedXorImpl(pDst, val)
#define NInterlockedExchange(pDst, exch) NInterlockedExchangeImpl(pDst, exch)
#define NInterlockedExchangePointer(pDst, exch) NInterlockedExchangePointerImpl(pDst, exch)
#define NInterlockedExchangeAdd(pDst, val) NInterlockedExchangeAddImpl(pDst, val)

#endif

#ifdef N_CPP
}
#endif

#endif // !N_INTERLOCKED_H_INCLUDED
