#ifndef N_PARAMETERS_H_INCLUDED
#define N_PARAMETERS_H_INCLUDED

#include <Core/NTypes.h>

#ifdef N_CPP
extern "C"
{
#endif

#define N_TYPE_BYTE 1
#define N_TYPE_SBYTE 2
#define N_TYPE_USHORT 3
#define N_TYPE_SHORT 4
#define N_TYPE_UINT 5
#define N_TYPE_INT 6
#ifndef N_NO_INT_64
	#define N_TYPE_ULONG 7
	#define N_TYPE_LONG 8
#endif
#define N_TYPE_BOOL 10
#ifndef N_NO_FLOAT
	#define N_TYPE_FLOAT 30
	#define N_TYPE_DOUBLE 31
#endif
#define N_TYPE_STRING 100

#define N_PC_TYPE_ID 1

#define NParameterMakeId(code, index, id) ((NUInt)(((code) << 24) | (((index) & 0xFF) << 16) | ((id) & 0xFFFF)))

#ifdef N_CPP
}
#endif

#endif // !N_PARAMETERS_H_INCLUDED
