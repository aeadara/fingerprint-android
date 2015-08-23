#include <Core/NTypes.h>

#ifdef N_WINDOWS
	#ifndef _WINDEF_
		#define HBITMAP void *
	#endif
	#ifndef _WINGDI_
		#define BITMAPINFO void *
	#endif
#endif
