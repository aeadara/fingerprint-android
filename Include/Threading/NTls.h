#ifndef N_TLS_H_INCLUDED
#define N_TLS_H_INCLUDED

#include <Core/NTypes.h>

#ifdef N_CPP
extern "C"
{
#endif

N_DECLARE_HANDLE_TYPE(NTls)

typedef void (N_CALLBACK NTlsDisposeProc)(void * pValue);

NResult N_API NTlsCreate(NTlsDisposeProc pDispose, HNTls * pHTls);
NResult N_API NTlsCreateForObject(HNTls * phTls);
NResult N_API NTlsFree(HNTls hTls);
NResult N_API NTlsGetValue(HNTls hTls, void * * ppValue);
NResult N_API NTlsSetValue(HNTls hTls, void * pValue);
NResult N_API NTlsGetObject(HNTls hTls, HNObject * phValue);
NResult N_API NTlsSetObject(HNTls hTls, HNObject hValue);

#ifdef N_CPP
}
#endif

#endif // !N_TLS_H_INCLUDED
