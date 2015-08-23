#include <Threading/NWaitObject.hpp>

#ifndef N_SYNC_EVENT_HPP_INCLUDED
#define N_SYNC_EVENT_HPP_INCLUDED

namespace Neurotec { namespace Threading
{
#include <Threading/NSyncEvent.h>
}}

namespace Neurotec { namespace Threading
{

class NSyncEvent : public NWaitObject
{
	N_DECLARE_OBJECT_CLASS(NSyncEvent, NWaitObject)

private:
	static HNSyncEvent Create(bool manualReset, bool initialState)
	{
		HNSyncEvent handle;
		NCheck(NSyncEventCreate(manualReset ? NTrue : NFalse, initialState ? NTrue : NFalse, &handle));
		return handle;
	}

	static HNSyncEvent Create(NHandle handle, bool ownsHandle)
	{
		HNSyncEvent hSyncEvent;
		NCheck(NSyncEventCreateFromOSHandle(handle, ownsHandle ? NTrue : NFalse, &hSyncEvent));
		return hSyncEvent;
	}

public:
	explicit NSyncEvent(bool manualReset, bool initialState)
		: NWaitObject(Create(manualReset, initialState), true)
	{
	}

	explicit NSyncEvent(NHandle handle, bool ownsHandle = true)
		: NWaitObject(Create(handle, ownsHandle), true)
	{
	}

	void Set()
	{
		NCheck(NSyncEventSet(GetHandle()));
	}

	NHandle GetOSHandle() const
	{
		NHandle hValue;
		NCheck(NSyncEventGetOSHandle(GetHandle(), &hValue));
		return hValue;
	}
};

}}

#endif // !N_SYNC_EVENT_HPP_INCLUDED
