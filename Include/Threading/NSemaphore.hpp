#include <Threading/NWaitObject.hpp>

#ifndef N_SEMAPHORE_HPP_INCLUDED
#define N_SEMAPHORE_HPP_INCLUDED

namespace Neurotec { namespace Threading
{
#include <Threading/NSemaphore.h>
}}

namespace Neurotec { namespace Threading
{

class NSemaphore : public NWaitObject
{
	N_DECLARE_OBJECT_CLASS(NSemaphore, NWaitObject)

private:
	static HNSemaphore Create(NInt initialCount)
	{
		HNSemaphore handle;
		NCheck(NSemaphoreCreate(initialCount, &handle));
		return handle;
	}

	static HNSemaphore Create(NHandle handle, bool ownsHandle)
	{
		HNSemaphore hSemaphore;
		NCheck(NSemaphoreCreateFromOSHandle(handle, ownsHandle ? NTrue : NFalse, &hSemaphore));
		return hSemaphore;
	}

public:
	explicit NSemaphore(NInt initialCount)
		: NWaitObject(Create(initialCount), true)
	{
	}

	explicit NSemaphore(NHandle handle, bool ownsHandle = true)
		: NWaitObject(Create(handle, ownsHandle), true)
	{
	}

	void Release()
	{
		NCheck(NSemaphoreRelease(GetHandle()));
	}

	NHandle GetOSHandle() const
	{
		NHandle hValue;
		NCheck(NSemaphoreGetOSHandle(GetHandle(), &hValue));
		return hValue;
	}
};

}}

#endif // !N_SEMAPHORE_HPP_INCLUDED
