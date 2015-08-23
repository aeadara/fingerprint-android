#ifndef N_WAIT_OBJECT_H_INCLUDED
#define N_WAIT_OBJECT_H_INCLUDED

#include <Core/NObject.h>

#ifdef N_CPP
extern "C"
{
#endif

#define N_INFINITE -1

N_DECLARE_OBJECT_TYPE(NWaitObject, NObject)

NResult N_API NWaitObjectWaitFor(HNWaitObject hWaitObject);
NResult N_API NWaitObjectWaitForTimed(HNWaitObject hWaitObject, NInt timeOutMilliseconds, NBool * pResult);
#define NWaitObjectTimedWaitFor(hWaitObject, timeOutMilliseconds, pResult) NWaitObjectWaitForTimed(hWaitObject, timeOutMilliseconds, pResult)

#ifdef N_MSVC
	#pragma deprecated("NWaitObjectTimedWaitFor")
#endif

#ifdef N_CPP
}
#endif

#endif // !N_WAIT_OBJECT_H_INCLUDED
