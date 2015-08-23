#ifndef N_TIME_SPAN_H_INCLUDED
#define N_TIME_SPAN_H_INCLUDED

#include <Core/NTypes.h>
#include <Core/NError.h>

#ifdef N_CPP
extern "C"
{
#endif

#define N_TIME_SPAN_MIN N_LONG_MIN
#define N_TIME_SPAN_MAX N_LONG_MAX
#define N_TIME_SPAN_TICKS_PER_MILLISECOND        10000LL
#define N_TIME_SPAN_TICKS_PER_SECOND          10000000LL
#define N_TIME_SPAN_TICKS_PER_MINUTE         600000000LL
#define N_TIME_SPAN_TICKS_PER_HOUR         36000000000LL
#define N_TIME_SPAN_TICKS_PER_DAY         864000000000LL

typedef NLong NTimeSpan_;
#ifndef N_TIME_SPAN_HPP_INCLUDED
typedef NTimeSpan_ NTimeSpan;
#endif
N_DECLARE_TYPE(NTimeSpan)

NBool N_API NTimeSpanIsValid(NTimeSpan_ value);
NBool N_API NTimeSpanIsTimeValid(NInt days, NInt hours, NInt minutes, NInt seconds, NInt milliseconds);

NResult N_API NTimeSpanCreateFromTicks(NLong value, NTimeSpan_ * pTimeSpan);
NResult N_API NTimeSpanCreate(NInt days, NInt hours, NInt minutes, NInt seconds, NInt milliseconds, NTimeSpan_ * pTimeSpan);
NResult N_API NTimeSpanCreateFromDays(NDouble value, NTimeSpan_ * pTimeSpan);
NResult N_API NTimeSpanCreateFromHours(NDouble value, NTimeSpan_ * pTimeSpan);
NResult N_API NTimeSpanCreateFromMinutes(NDouble value, NTimeSpan_ * pTimeSpan);
NResult N_API NTimeSpanCreateFromSeconds(NDouble value, NTimeSpan_ * pTimeSpan);
NResult N_API NTimeSpanCreateFromMilliseconds(NDouble value, NTimeSpan_ * pTimeSpan);

NResult N_API NTimeSpanAdd(NTimeSpan_ value1, NTimeSpan_ value2, NTimeSpan_ * pResult);
NResult N_API NTimeSpanSubtract(NTimeSpan_ value1, NTimeSpan_ value2, NTimeSpan_ * pResult);
NResult N_API NTimeSpanCompare(NTimeSpan_ value1, NTimeSpan_ value2, NInt * pResult);
NResult N_API NTimeSpanNegate(NTimeSpan_ value, NTimeSpan_ * pResult);
NResult N_API NTimeSpanDuration(NTimeSpan_ value, NTimeSpan_ * pResult);
NResult N_API NTimeSpanDecode(NTimeSpan_ timeSpan, NInt * pDays, NInt * pHours, NInt * pMinutes, NInt * pSeconds, NInt * pMilliseconds);

NResult N_API NTimeSpanToStringN(NTimeSpan_ value, HNString hFormat, HNString * phValue);

NResult N_API NTimeSpanToStringA(NTimeSpan_ value, const NAChar * szFormat, HNString * phValue);
#ifndef N_NO_UNICODE
NResult N_API NTimeSpanToStringW(NTimeSpan_ value, const NWChar * szFormat, HNString * phValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NTimeSpanToString(NTimeSpan value, const NChar * szFormat, HNString * phValue);
#endif
#define NTimeSpanToString N_FUNC_AW(NTimeSpanToString)

NResult N_API NTimeSpanGetTicks(NTimeSpan_ timeSpan, NLong * pValue);
NResult N_API NTimeSpanGetDays(NTimeSpan_ timeSpan, NInt * pValue);
NResult N_API NTimeSpanGetHours(NTimeSpan_ timeSpan, NInt * pValue);
NResult N_API NTimeSpanGetMinutes(NTimeSpan_ timeSpan, NInt * pValue);
NResult N_API NTimeSpanGetSeconds(NTimeSpan_ timeSpan, NInt * pValue);
NResult N_API NTimeSpanGetMilliseconds(NTimeSpan_ timeSpan, NInt * pValue);
NResult N_API NTimeSpanGetTotalDays(NTimeSpan_ timeSpan, NDouble * pValue);
NResult N_API NTimeSpanGetTotalHours(NTimeSpan_ timeSpan, NDouble * pValue);
NResult N_API NTimeSpanGetTotalMinutes(NTimeSpan_ timeSpan, NDouble * pValue);
NResult N_API NTimeSpanGetTotalSeconds(NTimeSpan_ timeSpan, NDouble * pValue);
NResult N_API NTimeSpanGetTotalMilliseconds(NTimeSpan_ timeSpan, NDouble * pValue);

#ifdef N_CPP
}
#endif

#endif // !N_TIME_SPAN_H_INCLUDED
