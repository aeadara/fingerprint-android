#ifndef N_WEAK_REFERENCE_H_INCLUDED
#define N_WEAK_REFERENCE_H_INCLUDED

#include <Core/NObject.h>

#ifdef N_CPP
extern "C"
{
#endif

#ifdef N_64
	#define N_WEAK_REFERENCE_SIZE 8
#else
	#define N_WEAK_REFERENCE_SIZE 4
#endif

N_DECLATE_PRIMITIVE(NWeakReference, N_WEAK_REFERENCE_SIZE)
N_DECLARE_TYPE(NWeakReference)

NResult N_API NWeakReferenceInit(NWeakReference * pWeakReference);
NResult N_API NWeakReferenceInitWith(NWeakReference * pWeakReference, HNObject hValue);
NResult N_API NWeakReferenceDispose(NWeakReference * pWeakReference);
NResult N_API NWeakReferenceGet(NWeakReference * pWeakReference, HNObject * phValue);
NResult N_API NWeakReferenceSet(NWeakReference * pWeakReference, HNObject hValue);

#ifdef N_CPP
}
#endif

#endif // !N_WEAK_REFERENCE_H_INCLUDED
