#include <Core/NTypes.h>

#ifdef N_MSVC
	#pragma warning(disable: 4995 4996)
#endif

#if defined(N_GCC) &&  N_GCC_VERSION >= 40201
	#pragma GCC diagnostic ignored "-Wdeprecated"
	#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
#endif
