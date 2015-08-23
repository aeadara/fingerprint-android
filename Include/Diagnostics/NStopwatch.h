#ifndef N_STOPWATCH_H_INCLUDED
#define N_STOPWATCH_H_INCLUDED

#include <Core/NObject.h>
#include <Core/NTimeSpan.h>

#ifdef N_CPP
extern "C"
{
#endif

N_DECLARE_OBJECT_TYPE(NStopwatch, NObject)

NResult N_API NStopwatchGetTimestamp(NLong * pValue);
NResult N_API NStopwatchStartNew(HNStopwatch * phStopwatch);

NResult N_API NStopwatchIsHighResolution(NBool * pValue);
NResult N_API NStopwatchGetFrequency(NLong * pValue);

NResult N_API NStopwatchCreate(HNStopwatch * phStopwatch);

NResult N_API NStopwatchStart(HNStopwatch hStopwatch);
NResult N_API NStopwatchStop(HNStopwatch hStopwatch);
NResult N_API NStopwatchReset(HNStopwatch hStopwatch);
NResult N_API NStopwatchRestart(HNStopwatch hStopwatch);

NResult N_API NStopwatchGetElapsedTicks(HNStopwatch hStopwatch, NLong * pValue);
NResult N_API NStopwatchGetElapsed(HNStopwatch hStopwatch, NTimeSpan_ * pValue);
NResult N_API NStopwatchGetElapsedMilliseconds(HNStopwatch hStopwatch, NLong * pValue);
NResult N_API NStopwatchIsRunning(HNStopwatch hStopwatch, NBool * pValue);

#ifdef N_CPP
}
#endif

#endif // N_STOPWATCH_H_INCLUDED
