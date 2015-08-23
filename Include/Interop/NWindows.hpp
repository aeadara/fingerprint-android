#ifndef N_WINDOWS_HPP_INCLUDED
#define N_WINDOWS_HPP_INCLUDED

#include <Core/NDefs.h>

#ifdef N_WINDOWS
	#include <Interop/NWindows.h>
	#ifdef N_FRAMEWORK_WX
		#include <wx/msw/winundef.h>
	#else
		#ifdef GetObject
			#undef GetObject
			inline int GetObject(HGDIOBJ h, int i, LPVOID buffer)
			{
			#ifdef _UNICODE
				return GetObjectW(h, i, buffer);
			#else
				return GetObjectA(h, i, buffer);
			#endif
			}
		#endif
	#endif
#endif

#endif // !N_WINDOWS_HPP_INCLUDED
