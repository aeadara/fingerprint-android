#ifndef N_WAIT_OBJECT_HPP_INCLUDED
#define N_WAIT_OBJECT_HPP_INCLUDED

#include <Core/NObject.hpp>
namespace Neurotec { namespace Threading
{
#include <Threading/NWaitObject.h>
}}

namespace Neurotec { namespace Threading
{
#undef N_INFINITE

const NInt N_INFINITE = -1;

class NWaitObject : public NObject
{
	N_DECLARE_OBJECT_CLASS(NWaitObject, NObject)

public:
	bool WaitFor(NInt timeOutMilliseconds = N_INFINITE)
	{
		NBool result;
		NCheck(NWaitObjectWaitForTimed(GetHandle(), timeOutMilliseconds, &result));
		return result != 0;
	}
};

}}

#endif // !N_WAIT_OBJECT_HPP_INCLUDED
