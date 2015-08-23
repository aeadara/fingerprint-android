#include <Core/NTypes.h>

#ifdef N_WINDOWS
	#ifndef _WINDEF_
		#undef HBITMAP
	#endif
	#ifndef _WINGDI_
		#undef BITMAPINFO
	#endif
#endif
