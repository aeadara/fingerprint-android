#ifndef N_STOPWATCH_HPP_INCLUDED
#define N_STOPWATCH_HPP_INCLUDED

#include <Core/NObject.hpp>
#include <Core/NTimeSpan.hpp>
namespace Neurotec { namespace Diagnostics
{
#include <Diagnostics/NStopwatch.h>
}}

namespace Neurotec { namespace Diagnostics
{

class NStopwatch : public NObject
{
	N_DECLARE_OBJECT_CLASS(NStopwatch, NObject)

private:
	static HNStopwatch Create()
	{
		HNStopwatch hStopwatch;
		NCheck(NStopwatchCreate(&hStopwatch));
		return hStopwatch;
	}

public:
	static NLong GetTimestamp()
	{
		NLong value;
		NCheck(NStopwatchGetTimestamp(&value));
		return value;
	}

	static NStopwatch StartNew()
	{
		HNStopwatch hStopwatch;
		NCheck(NStopwatchStartNew(&hStopwatch));
		try
		{
			return FromHandle<NStopwatch>(hStopwatch);
		}
		catch (...)
		{
			Unref(hStopwatch);
			throw;
		}
	}

	static bool IsHighResolution()
	{
		NBool value;
		NCheck(NStopwatchIsHighResolution(&value));
		return value != 0;
	}

	static NLong GetFrequency()
	{
		NLong value;
		NCheck(NStopwatchGetFrequency(&value));
		return value;
	}

	NStopwatch()
		: NObject(Create(), true)
	{
	}

	void Start()
	{
		NCheck(NStopwatchStart(GetHandle()));
	}

	void Stop()
	{
		NCheck(NStopwatchStop(GetHandle()));
	}

	void Reset()
	{
		NCheck(NStopwatchReset(GetHandle()));
	}

	void Restart()
	{
		NCheck(NStopwatchRestart(GetHandle()));
	}

	NLong GetElapsedTicks() const
	{
		NLong value;
		NCheck(NStopwatchGetElapsedTicks(GetHandle(), &value));
		return value;
	}

	NTimeSpan GetElapsed() const
	{
		NTimeSpan_ value;
		NCheck(NStopwatchGetElapsed(GetHandle(), &value));
		return NTimeSpan(value);
	}

	NLong GetElapsedMilliseconds() const
	{
		NLong value;
		NCheck(NStopwatchGetElapsedMilliseconds(GetHandle(), &value));
		return value;
	}

	bool IsRunning() const
	{
		NBool value;
		NCheck(NStopwatchIsRunning(GetHandle(), &value));
		return value != 0;
	}
};

}}

#endif // !N_STOPWATCH_HPP_INCLUDED
