#include <Core/NTypes.h>

#ifdef N_MSVC
	#pragma warning(default: 4995 4996)
#endif

#if defined(N_GCC) &&  N_GCC_VERSION >= 40201
	#pragma GCC diagnostic warning "-Wdeprecated"
	#pragma GCC diagnostic warning "-Wdeprecated-declarations"
#endif
