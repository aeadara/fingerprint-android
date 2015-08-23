#ifndef N_RW_LOCK_HPP_INCLUDED
#define N_RW_LOCK_HPP_INCLUDED

#include <Core/NTypes.hpp>
namespace Neurotec { namespace Threading { namespace Internal
{
#include <Threading/NRWLock.h>
}}}

namespace Neurotec { namespace Threading
{

class NRWLock : private Internal::NRWLock
{
	N_DECLARE_PRIMITIVE_CLASS(NRWLock)

public:
	NRWLock()
	{
		Internal::NRWLockInit(this);
	}

	~NRWLock()
	{
		Internal::NRWLockDispose(this);
	}

	void EnterRead()
	{
		Internal::NRWLockEnterRead(this);
	}

	bool TryEnterRead()
	{
		return Internal::NRWLockTryEnterRead(this) != 0;
	}

	void ExitRead()
	{
		Internal::NRWLockExitRead(this);
	}

	void EnterWrite()
	{
		Internal::NRWLockEnterWrite(this);
	}

	bool TryEnterWrite()
	{
		return Internal::NRWLockTryEnterWrite(this) != 0;
	}

	void ExitWrite()
	{
		Internal::NRWLockExitWrite(this);
	}
};

class NRWLockReadLocker
{
	N_DECLARE_NON_COPYABLE(NRWLockReadLocker)

private:
	NRWLock & rwLock;

public:
	NRWLockReadLocker(NRWLock & rwLock)
		: rwLock(rwLock)
	{
		rwLock.EnterRead();
	}

	~NRWLockReadLocker()
	{
		rwLock.ExitRead();
	}
};

class NRWLockWriteLocker
{
private:
	NRWLock & rwLock;

	NRWLockWriteLocker(const NRWLockWriteLocker &);
	NRWLockWriteLocker & operator=(const NRWLockWriteLocker &);

public:
	NRWLockWriteLocker(NRWLock & rwLock)
		: rwLock(rwLock)
	{
		rwLock.EnterWrite();
	}

	~NRWLockWriteLocker()
	{
		rwLock.ExitWrite();
	}
};

}}

#endif // !N_RW_LOCK_HPP_INCLUDED
