#include <Threading/NWaitObject.hpp>

#ifndef N_MUTEX_HPP_INCLUDED
#define N_MUTEX_HPP_INCLUDED

namespace Neurotec { namespace Threading
{
#include <Threading/NMutex.h>
}}

namespace Neurotec { namespace Threading
{

class NMutex : public NWaitObject
{
	N_DECLARE_OBJECT_CLASS(NMutex, NWaitObject)

private:
	static HNMutex Create(bool initiallyOwned)
	{
		HNMutex handle;
		NCheck(NMutexCreate(initiallyOwned ? NTrue : NFalse, &handle));
		return handle;
	}

	static HNMutex Create(NHandle handle, bool ownsHandle)
	{
		HNMutex hMutex;
		NCheck(NMutexCreateFromOSHandle(handle, ownsHandle ? NTrue : NFalse, &hMutex));
		return hMutex;
	}

public:
	explicit NMutex(bool initiallyOwned)
		: NWaitObject(Create(initiallyOwned), true)
	{
	}

	explicit NMutex(NHandle handle, bool ownsHandle = true)
		: NWaitObject(Create(handle, ownsHandle), true)
	{
	}

	void Release()
	{
		NCheck(NMutexRelease(GetHandle()));
	}

	NHandle GetOSHandle() const
	{
		NHandle hValue;
		NCheck(NMutexGetOSHandle(GetHandle(), &hValue));
		return hValue;
	}
};

}}

#endif // !N_MUTEX_HPP_INCLUDED
