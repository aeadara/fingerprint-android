#ifndef N_MONITOR_HPP_INCLUDED
#define N_MONITOR_HPP_INCLUDED

#include <Core/NTypes.hpp>
namespace Neurotec { namespace Threading { namespace Internal
{
#include <Threading/NMonitor.h>
}}}
#if defined(N_FRAMEWORK_MFC)
	#include <afxmt.h>
#elif defined(N_FRAMEWORK_WX)
	#include <wx/thread.h>
#elif defined(N_FRAMEWORK_QT)
	#include <QMutex>
	#include <QMutexLocker>
#endif

namespace Neurotec { namespace Threading
{

class NMonitor : private Internal::NMonitor
{
	N_DECLARE_PRIMITIVE_CLASS(NMonitor)

public:
	NMonitor()
	{
		Internal::NMonitorInit(this);
	}

	~NMonitor()
	{
		Internal::NMonitorDispose(this);
	}

	void Enter()
	{
		Internal::NMonitorEnter(this);
	}

	bool TryEnter()
	{
		return Internal::NMonitorTryEnter(this) != 0;
	}

	void Exit()
	{
		Internal::NMonitorExit(this);
	}
};

class NMonitorLocker
{
	N_DECLARE_NON_COPYABLE(NMonitorLocker)

private:
	NMonitor & monitor;

public:
	NMonitorLocker(NMonitor & monitor)
		: monitor(monitor)
	{
		monitor.Enter();
	}

	~NMonitorLocker()
	{
		monitor.Exit();
	}
};

#if defined(N_FRAMEWORK_MFC)
	typedef CCriticalSection NMonitorType;
	typedef CSingleLock NMonitorLockerType;

	#define N_MONITOR_ARGS
	#define N_MONITOR_ARGS_P
	#define N_MONITOR_LOCKER_ARGS(monitor) &monitor, TRUE

	inline void NEnterMonitor(NMonitorType & monitor)
	{
		monitor.Lock();
	}

	inline void NExitMonitor(NMonitorType & monitor)
	{
		monitor.Unlock();
	}
#elif defined(N_FRAMEWORK_WX)
	typedef wxMutex NMonitorType;
	typedef wxMutexLocker NMonitorLockerType;

	#define N_MONITOR_ARGS wxMUTEX_RECURSIVE
	#define N_MONITOR_ARGS_P (N_MONITOR_ARGS)
	#define N_MONITOR_LOCKER_ARGS(monitor) monitor

	inline void NEnterMonitor(NMonitorType & monitor)
	{
		monitor.Lock();
	}

	inline void NExitMonitor(NMonitorType & monitor)
	{
		monitor.Unlock();
	}
#elif defined(N_FRAMEWORK_QT)
	typedef QMutex NMonitorType;
	typedef QMutexLocker NMonitorLockerType;

	#define N_MONITOR_ARGS QMutex::Recursive
	#define N_MONITOR_ARGS_P (N_MONITOR_ARGS)
	#define N_MONITOR_LOCKER_ARGS(monitor) &monitor

	inline void NEnterMonitor(NMonitorType & monitor)
	{
		monitor.lock();
	}

	inline void NExitMonitor(NMonitorType & monitor)
	{
		monitor.unlock();
	}
#else
	typedef NMonitor NMonitorType;
	typedef NMonitorLocker NMonitorLockerType;

	#define N_MONITOR_ARGS
	#define N_MONITOR_ARGS_P
	#define N_MONITOR_LOCKER_ARGS(monitor) monitor

	inline void NEnterMonitor(NMonitorType & monitor)
	{
		monitor.Enter();
	}

	inline void NExitMonitor(NMonitorType & monitor)
	{
		monitor.Exit();
	}
#endif

}}

#endif // !N_MONITOR_HPP_INCLUDED
