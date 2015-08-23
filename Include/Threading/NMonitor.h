#ifndef N_MONITOR_H_INCLUDED
#define N_MONITOR_H_INCLUDED

#include <Core/NTypes.h>

#ifdef N_CPP
extern "C"
{
#endif

#if defined(N_APPLE)
	#ifdef N_64
		#define N_MONITOR_SIZE 64
	#else
		#define N_MONITOR_SIZE 44
	#endif
#elif defined(N_ANDROID)
	#define N_MONITOR_SIZE N_PTR_SIZE
#elif defined(N_WINDOWS_CE)
	#define N_MONITOR_SIZE 20
#elif defined (N_QNX)
	#define N_MONITOR_SIZE 8
#else
	#ifdef N_64
		#define N_MONITOR_SIZE 40
	#else
		#define N_MONITOR_SIZE 24
	#endif
#endif

N_DECLATE_PRIMITIVE(NMonitor, N_MONITOR_SIZE)
N_DECLARE_TYPE(NMonitor)

void N_API NMonitorInit(NMonitor * pMonitor);
void N_API NMonitorDispose(NMonitor * pMonitor);
void N_API NMonitorEnter(NMonitor * pMonitor);
NBool N_API NMonitorTryEnter(NMonitor * pMonitor);
void N_API NMonitorExit(NMonitor * pMonitor);

#ifdef N_CPP
}
#endif

#endif // !N_MONITOR_H_INCLUDED
