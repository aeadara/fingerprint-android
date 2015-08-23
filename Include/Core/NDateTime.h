#ifndef N_DATE_TIME_H_INCLUDED
#define N_DATE_TIME_H_INCLUDED

#include <Core/NTimeSpan.h>

#ifdef N_CPP
extern "C"
{
#endif

#define N_DATE_TIME_MIN 0LL
#define N_DATE_TIME_MAX 3155378975999999999LL

typedef enum NDayOfWeek_
{
	ndowSunday = 0,
	ndowMonday = 1,
	ndowTuesday = 2,
	ndowWednesday = 3,
	ndowThursday = 4,
	ndowFriday = 5,
	ndowSaturday = 6
} NDayOfWeek;

N_DECLARE_TYPE(NDayOfWeek)

typedef NLong NDateTime_;
#ifndef N_DATE_TIME_HPP_INCLUDED
typedef NDateTime_ NDateTime;
#endif
N_DECLARE_TYPE(NDateTime)

NResult N_API NDateTimeIsLeapYear(NInt year, NBool * pValue);
NResult N_API NDateTimeDaysInMonth(NInt year, NInt month, NInt * pValue);
NBool N_API NDateTimeIsValid(NDateTime_ value);
NBool N_API NDateTimeIsDateValid(NInt year, NInt month, NInt day);
NBool N_API NDateTimeIsDateTimeValid(NInt year, NInt month, NInt day, NInt hour, NInt minute, NInt second, NInt millisecond);

NResult N_API NDateTimeGetUtcNow(NDateTime_ * pValue);
NResult N_API NDateTimeGetNow(NDateTime_ * pValue);
NResult N_API NDateTimeGetToday(NDateTime_ * pValue);

NResult N_API NDateTimeCreateFromTicks(NLong ticks, NDateTime_ * pDateTime);
NResult N_API NDateTimeCreate(NInt year, NInt month, NInt day, NInt hour, NInt minute, NInt second, NInt millisecond, NDateTime_ * pDateTime);
NResult N_API NDateTimeCreateDate(NInt year, NInt month, NInt day, NDateTime_ * pDateTime);

NResult N_API NDateTimeSubtract(NDateTime_ value1, NDateTime_ value2, NTimeSpan_ * pTimeSpan);
NResult N_API NDateTimeAddTimeSpan(NDateTime_ dateTime, NTimeSpan_ timeSpan, NDateTime_ * pResult);
NResult N_API NDateTimeSubtractTimeSpan(NDateTime_ dateTime, NTimeSpan_ timeSpan, NDateTime_ * pResult);
NResult N_API NDateTimeAddTicks(NDateTime_ dateTime, NLong value, NDateTime_ * pResult);
NResult N_API NDateTimeAddYears(NDateTime_ dateTime, NInt value, NDateTime_ * pResult);
NResult N_API NDateTimeAddMonths(NDateTime_ dateTime, NInt value, NDateTime_ * pResult);
NResult N_API NDateTimeAddDays(NDateTime_ dateTime, NDouble value, NDateTime_ * pResult);
NResult N_API NDateTimeAddHours(NDateTime_ dateTime, NDouble value, NDateTime_ * pResult);
NResult N_API NDateTimeAddMinutes(NDateTime_ dateTime, NDouble value, NDateTime_ * pResult);
NResult N_API NDateTimeAddSeconds(NDateTime_ dateTime, NDouble value, NDateTime_ * pResult);
NResult N_API NDateTimeAddMilliseconds(NDateTime_ dateTime, NDouble value, NDateTime_ * pResult);
NResult N_API NDateTimeCompare(NDateTime_ value1, NDateTime_ value2, NInt * pResult);
NResult N_API NDateTimeToLocalTime(NDateTime_ dateTime, NDateTime_ * pValue);
NResult N_API NDateTimeToUniversalTime(NDateTime_ dateTime, NDateTime_ * pValue);
NResult N_API NDateTimeDecode(NDateTime_ dateTime, NInt * pYear, NInt * pDayOfYear, NInt * pMonth, NInt * pDay, NDayOfWeek * pDayOfWeek, NInt * pHour, NInt * pMinute, NInt * pSecond, NInt * pMillisecond);

NResult N_API NDateTimeToStringN(NDateTime_ value, HNString hFormat, HNString * phValue);
NResult N_API NDateTimeToStringA(NDateTime_ value, const NAChar * szFormat, HNString * phValue);
#ifndef N_NO_UNICODE
NResult N_API NDateTimeToStringW(NDateTime_ value, const NWChar * szFormat, HNString * phValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NDateTimeToString(NDateTime value, const NChar * szFormat, HNString * phValue);
#endif
#define NDateTimeToString N_FUNC_AW(NDateTimeToString)

NResult N_API NDateTimeGetTicks(NDateTime_ dateTime, NLong * pValue);
NResult N_API NDateTimeGetYear(NDateTime_ dateTime, NInt * pValue);
NResult N_API NDateTimeGetDayOfYear(NDateTime_ dateTime, NInt * pValue);
NResult N_API NDateTimeGetMonth(NDateTime_ dateTime, NInt * pValue);
NResult N_API NDateTimeGetDay(NDateTime_ dateTime, NInt * pValue);
NResult N_API NDateTimeGetDayOfWeek(NDateTime_ dateTime, NDayOfWeek * pValue);
NResult N_API NDateTimeGetHour(NDateTime_ dateTime, NInt * pValue);
NResult N_API NDateTimeGetMinute(NDateTime_ dateTime, NInt * pValue);
NResult N_API NDateTimeGetSecond(NDateTime_ dateTime, NInt * pValue);
NResult N_API NDateTimeGetMillisecond(NDateTime_ dateTime, NInt * pValue);
NResult N_API NDateTimeGetDate(NDateTime_ dateTime, NDateTime_ * pValue);
NResult N_API NDateTimeGetTimeOfDay(NDateTime_ dateTime, NTimeSpan_ * pValue);

#ifdef N_CPP
}
#endif

#endif // !N_DATE_TIME_H_INCLUDED
