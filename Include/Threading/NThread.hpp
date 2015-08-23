#ifndef N_THREAD_HPP_INCLUDED
#define N_THREAD_HPP_INCLUDED

#include <Core/NObject.hpp>
namespace Neurotec { namespace Threading
{
#include <Threading/NThread.h>
}}

namespace Neurotec { namespace Threading
{

class NThread : public NObject
{
	N_DECLARE_OBJECT_CLASS(NThread, NObject)

public:
	typedef void (* StartProc)(void * pParam);
	typedef void (* ParameterizedStartProc)(const NObject & obj, void * pParam);

private:
	static NResult N_API ThreadStartProcImpl(void * pParam)
	{
		NResult result = N_OK;
		try
		{
			NTypes::CallbackParam * p = reinterpret_cast<NTypes::CallbackParam *>(pParam);
			reinterpret_cast<StartProc>(p->GetCallback())(p->GetCallbackParam());
		}
		N_EXCEPTION_CATCH_AND_SET_LAST(result);
		return result;
	}

	static NResult N_API ParameterizedThreadStartProcImpl(HNObject hObj, void * pParam)
	{
		NResult result = N_OK;
		try
		{
			NTypes::CallbackParam * p = reinterpret_cast<NTypes::CallbackParam *>(pParam);
			reinterpret_cast<ParameterizedStartProc>(p->GetCallback())(NObject(hObj, false), p->GetCallbackParam());
		}
		N_EXCEPTION_CATCH_AND_SET_LAST(result);
		return result;
	}

	static HNThread Create(StartProc pThreadStart, void * pThreadStartParam)
	{
		NCallback threadStart = NTypes::CreateCallback(ThreadStartProcImpl, pThreadStart, pThreadStartParam);
		HNThread handle;
		NCheck(NThreadCreateN(threadStart.GetHandle(), &handle));
		return handle;
	}

	static HNThread Create(ParameterizedStartProc pThreadStart, void * pThreadStartParam, const NObject & parameter)
	{
		NCallback threadStart = NTypes::CreateCallback(ParameterizedThreadStartProcImpl, pThreadStart, pThreadStartParam);
		HNThread handle;
		NCheck(NThreadCreateParameterizedN(threadStart.GetHandle(), parameter.GetHandle(), &handle));
		return handle;
	}

	static HNThread Create(NHandle handle, bool ownsHandle)
	{
		HNThread hThread;
		NCheck(NThreadCreateFromOSHandle(handle, ownsHandle ? NTrue : NFalse, &hThread));
		return hThread;
	}

public:
	static void Sleep(NInt milliseconds)
	{
		NCheck(NThreadSleep(milliseconds));
	}

	static NSizeType GetCurrentId()
	{
		NSizeType value;
		NCheck(NThreadGetCurrentId(&value));
		return value;
	}

	static NThread GetCurrent()
	{
		return GetObject<NThread>(NThreadGetCurrent, true);
	}

	NThread(StartProc pThreadStart, void * pThreadStartParam)
		: NObject(Create(pThreadStart, pThreadStartParam), true)
	{
	}

	NThread(ParameterizedStartProc pThreadStart, void * pThreadStartParam, const NObject & parameter)
		: NObject(Create(pThreadStart, pThreadStartParam, parameter), true)
	{
	}

	explicit NThread(NHandle handle, bool ownsHandle = true)
		: NObject(Create(handle, ownsHandle), true)
	{
	}

	void Join()
	{
		NCheck(NThreadJoin(GetHandle()));
	}

	NHandle GetOSHandle() const
	{
		NHandle hValue;
		NCheck(NThreadGetOSHandle(GetHandle(), &hValue));
		return hValue;
	}

	NSizeType GetId() const
	{
		NSizeType value;
		NCheck(NThreadGetId(GetHandle(), &value));
		return value;
	}
};

}}

#endif // !N_THREAD_HPP_INCLUDED
