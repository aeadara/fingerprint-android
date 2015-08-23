#ifndef N_PARAMETERS_HPP_INCLUDED
#define N_PARAMETERS_HPP_INCLUDED

#include <Core/NTypes.hpp>
namespace Neurotec
{
#include <Core/NParameters.h>
}

namespace Neurotec
{
#undef N_TYPE_BYTE
#undef N_TYPE_SBYTE
#undef N_TYPE_USHORT
#undef N_TYPE_SHORT
#undef N_TYPE_UINT
#undef N_TYPE_INT
#ifndef N_NO_INT_64
	#undef N_TYPE_ULONG
	#undef N_TYPE_LONG
#endif
#undef N_TYPE_BOOL
#undef N_TYPE_CHAR
#ifndef N_NO_FLOAT
	#undef N_TYPE_FLOAT
	#undef N_TYPE_DOUBLE
#endif
#undef N_TYPE_STRING

#undef N_PC_TYPE_ID

#undef NParameterMakeId

const NInt N_TYPE_BYTE = 1;
const NInt N_TYPE_SBYTE = 2;
const NInt N_TYPE_USHORT = 3;
const NInt N_TYPE_SHORT = 4;
const NInt N_TYPE_UINT = 5;
const NInt N_TYPE_INT = 6;
#ifndef N_NO_INT_64
	const NInt N_TYPE_ULONG = 7;
	const NInt N_TYPE_LONG = 8;
#endif
const NInt N_TYPE_BOOL = 10;
const NInt N_TYPE_CHAR = 20;
#ifndef N_NO_FLOAT
	const NInt N_TYPE_FLOAT = 30;
	const NInt N_TYPE_DOUBLE = 31;
#endif
const NInt N_TYPE_STRING = 100;

const NByte N_PC_TYPE_ID = 1;

inline NUInt NParameterMakeId(NByte code, NByte index, NUShort id)
{
	return (NUInt)((code << 24) | (index << 16) | id);
}
}

#endif // !N_PARAMETERS_HPP_INCLUDED
