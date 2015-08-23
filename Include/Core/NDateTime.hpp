#ifndef N_DATE_TIME_HPP_INCLUDED
#define N_DATE_TIME_HPP_INCLUDED

#include <Core/NTimeSpan.hpp>
namespace Neurotec
{
#include <Core/NDateTime.h>
}
#if defined(N_FRAMEWORK_MFC)
	typedef CFileTime NDateTimeType;
#elif defined(N_FRAMEWORK_WX)
	typedef wxDateTime NDateTimeType;
#elif defined(N_FRAMEWORK_QT)
	#include <QDate>
	#include <QDateTime>
	typedef QDateTime NDateTimeType;
#endif

N_DEFINE_ENUM_TYPE_TRAITS(Neurotec, NDayOfWeek)

namespace Neurotec
{

class NDateTime
{
	N_DECLARE_COMPARABLE_BASIC_CLASS(NDateTime)

private:
	static const NLong Win32FileEpoch = 504911232000000000LL;
	static const NLong UnixEpoch = 621355968000000000LL;

public:
	static bool IsLeapYear(NInt year)
	{
		NBool value;
		NCheck(NDateTimeIsLeapYear(year, &value));
		return value != 0;
	}

	static NInt DaysInMonth(NInt year, NInt month)
	{
		NInt value;
		NCheck(NDateTimeDaysInMonth(year, month, &value));
		return value;
	}

	static bool IsDateValid(NInt year, NInt month, NInt day)
	{
		return NDateTimeIsDateValid(year, month, day) != 0;
	}

	static bool IsDateTimeValid(NInt year, NInt month, NInt day, NInt hour, NInt minute, NInt second, NInt millisecond)
	{
		return NDateTimeIsDateTimeValid(year, month, day, hour, minute, second, millisecond) != 0;
	}

	static NDateTime GetUtcNow()
	{
		NDateTime_ value;
		NCheck(NDateTimeGetUtcNow(&value));
		return NDateTime(value);
	}

	static NDateTime GetNow()
	{
		NDateTime_ value;
		NCheck(NDateTimeGetNow(&value));
		return NDateTime(value);
	}

	static NDateTime GetToday()
	{
		NDateTime_ value;
		NCheck(NDateTimeGetToday(&value));
		return NDateTime(value);
	}

	static NDateTime FromTicks(NLong ticks)
	{
		NDateTime_ value;
		NCheck(NDateTimeCreateFromTicks(ticks, &value));
		return NDateTime(value);
	}

	static NInt Compare(NDateTime value1, NDateTime value2)
	{
		NInt result;
		NCheck(NDateTimeCompare(value1.value, value2.value, &result));
		return result;
	}

	NDateTime(NInt year, NInt month, NInt day, NInt hour, NInt minute, NInt second, NInt millisecond)
	{
		NCheck(NDateTimeCreate(year, month, day, hour, minute, second, millisecond, &value));
	}

	NDateTime(NInt year, NInt month, NInt day)
	{
		NCheck(NDateTimeCreateDate(year, month, day, &value));
	}

#if defined(N_FRAMEWORK_MFC)
	NDateTime(CFileTime value)
	{
		NLong theValue = (NLong)value.GetTime();
		if (theValue + Win32FileEpoch < 0 || N_DATE_TIME_MAX - Win32FileEpoch < theValue) NThrowOverflowException();
		this->value = Win32FileEpoch + theValue;
	}

	NDateTime(CTime value)
	{
		NLong theValue = (NLong)value.GetTime();
		if (theValue < 0 || (N_DATE_TIME_MAX - UnixEpoch) / N_TIME_SPAN_TICKS_PER_SECOND < theValue) NThrowOverflowException();
		this->value = UnixEpoch + theValue * N_TIME_SPAN_TICKS_PER_SECOND;
	}
#elif defined(N_FRAMEWORK_WX)
	NDateTime(wxDateTime value)
	{
		NLong value1 = (NLong)value.GetTicks();
		NLong value2 = (NLong)value.GetMillisecond();
		NLong result;
		if (N_DATE_TIME_MIN / N_TIME_SPAN_TICKS_PER_SECOND - UnixEpoch / N_TIME_SPAN_TICKS_PER_SECOND > value1
			|| (N_DATE_TIME_MAX - UnixEpoch) / N_TIME_SPAN_TICKS_PER_SECOND < value1) NThrowOverflowException();
		result = UnixEpoch + value1 * N_TIME_SPAN_TICKS_PER_SECOND;
		if (value2 < 0 || (N_DATE_TIME_MAX - result) / N_TIME_SPAN_TICKS_PER_MILLISECOND < value2) NThrowOverflowException();
		result += value2 * N_TIME_SPAN_TICKS_PER_MILLISECOND;
		this->value = result;
	}
#elif defined(N_FRAMEWORK_QT)
	NDateTime(QDateTime value)
	{
		NLong value1 = (NLong)value.toTime_t();
		NLong value2 = (NLong)value.time().msec();
		NLong result;
		if (N_DATE_TIME_MIN / N_TIME_SPAN_TICKS_PER_SECOND - UnixEpoch / N_TIME_SPAN_TICKS_PER_SECOND > value1
			|| (N_DATE_TIME_MAX - UnixEpoch) / N_TIME_SPAN_TICKS_PER_SECOND < value1) NThrowOverflowException();
		result = UnixEpoch + value1 * N_TIME_SPAN_TICKS_PER_SECOND;
		if (value2 < 0 || (N_DATE_TIME_MAX - result) / N_TIME_SPAN_TICKS_PER_MILLISECOND < value2) NThrowOverflowException();
		result += value2 * N_TIME_SPAN_TICKS_PER_MILLISECOND;
		this->value = result;
	}
#endif

	bool IsValid() const
	{
		return NDateTimeIsValid(value) != 0;
	}

	NTimeSpan Subtract(NDateTime value) const
	{
		NTimeSpan_ result;
		NCheck(NDateTimeSubtract(this->value, value.value, &result));
		return NTimeSpan(result);
	}

	NDateTime Add(NTimeSpan timeSpan) const
	{
		NDateTime_ result;
		NCheck(NDateTimeAddTimeSpan(this->value, timeSpan.GetValue(), &result));
		return NDateTime(result);
	}

	NDateTime Subtract(NTimeSpan timeSpan) const
	{
		NDateTime_ result;
		NCheck(NDateTimeSubtractTimeSpan(this->value, timeSpan.GetValue(), &result));
		return NDateTime(result);
	}

	NDateTime AddTicks(NLong value) const
	{
		NDateTime_ result;
		NCheck(NDateTimeAddTicks(this->value, value, &result));
		return NDateTime(result);
	}

	NDateTime AddYears(NInt value) const
	{
		NDateTime_ result;
		NCheck(NDateTimeAddYears(this->value, value, &result));
		return NDateTime(result);
	}

	NDateTime AddMonths(NInt value) const
	{
		NDateTime_ result;
		NCheck(NDateTimeAddMonths(this->value, value, &result));
		return NDateTime(result);
	}

	NDateTime AddDays(NDouble value) const
	{
		NDateTime_ result;
		NCheck(NDateTimeAddDays(this->value, value, &result));
		return NDateTime(result);
	}

	NDateTime AddHours(NDouble value) const
	{
		NDateTime_ result;
		NCheck(NDateTimeAddHours(this->value, value, &result));
		return NDateTime(result);
	}

	NDateTime AddMinutes(NDouble value) const
	{
		NDateTime_ result;
		NCheck(NDateTimeAddMinutes(this->value, value, &result));
		return NDateTime(result);
	}

	NDateTime AddSeconds(NDouble value) const
	{
		NDateTime_ result;
		NCheck(NDateTimeAddSeconds(this->value, value, &result));
		return NDateTime(result);
	}

	NDateTime AddMilliseconds(NDouble value) const
	{
		NDateTime_ result;
		NCheck(NDateTimeAddMilliseconds(this->value, value, &result));
		return NDateTime(result);
	}

	NInt CompareTo(NDateTime value) const
	{
		NInt result;
		NCheck(NDateTimeCompare(this->value, value.value, &result));
		return result;
	}

	NDateTime ToLocalTime() const
	{
		NDateTime_ value;
		NCheck(NDateTimeToLocalTime(this->value, &value));
		return NDateTime(value);
	}

	NDateTime ToUniversalTime() const
	{
		NDateTime_ value;
		NCheck(NDateTimeToUniversalTime(this->value, &value));
		return NDateTime(value);
	}

	void Decode(NInt * pYear, NInt * pDayOfYear, NInt * pMonth, NInt * pDay, NDayOfWeek * pDayOfWeek, NInt * pHour, NInt * pMinute, NInt * pSecond, NInt * pMillisecond) const
	{
		NCheck(NDateTimeDecode(value, pYear, pDayOfYear, pMonth, pDay, pDayOfWeek, pHour, pMinute, pSecond, pMillisecond));
	}

	NString ToString(const NStringWrapper & format = NString()) const
	{
		HNString hValue;
		NCheck(NDateTimeToStringN(value, format.GetHandle(), &hValue));
		return NString(hValue, true);
	}

	NLong GetTicks() const
	{
		NLong value;
		NCheck(NDateTimeGetTicks(this->value, &value));
		return value;
	}

	NInt GetYear() const
	{
		NInt value;
		NCheck(NDateTimeGetYear(this->value, &value));
		return value;
	}

	NInt GetDayOfYear() const
	{
		NInt value;
		NCheck(NDateTimeGetDayOfYear(this->value, &value));
		return value;
	}

	NInt GetMonth() const
	{
		NInt value;
		NCheck(NDateTimeGetMonth(this->value, &value));
		return value;
	}

	NInt GetDay() const
	{
		NInt value;
		NCheck(NDateTimeGetDay(this->value, &value));
		return value;
	}

	NDayOfWeek GetDayOfWeek() const
	{
		NDayOfWeek value;
		NCheck(NDateTimeGetDayOfWeek(this->value, &value));
		return value;
	}

	NInt GetHour() const
	{
		NInt value;
		NCheck(NDateTimeGetHour(this->value, &value));
		return value;
	}

	NInt GetMinute() const
	{
		NInt value;
		NCheck(NDateTimeGetMinute(this->value, &value));
		return value;
	}

	NInt GetSecond() const
	{
		NInt value;
		NCheck(NDateTimeGetSecond(this->value, &value));
		return value;
	}

	NInt GetMillisecond() const
	{
		NInt value;
		NCheck(NDateTimeGetMillisecond(this->value, &value));
		return value;
	}

	NDateTime GetDate() const
	{
		NDateTime_ value;
		NCheck(NDateTimeGetDate(this->value, &value));
		return NDateTime(value);
	}

	NTimeSpan GetTimeOfDay() const
	{
		NTimeSpan_ value;
		NCheck(NDateTimeGetTimeOfDay(this->value, &value));
		return NTimeSpan(value);
	}

	NDateTime operator+(const NTimeSpan & value) const
	{
		return Add(value);
	}

	NTimeSpan operator-(const NDateTime & value) const
	{
		return Subtract(value);
	}

	NDateTime operator-(const NTimeSpan & value) const
	{
		return Subtract(value);
	}

#if defined(N_FRAMEWORK_MFC)
	operator CFileTime() const
	{
		NLong value = this->value - Win32FileEpoch;
		if (value < 0) NThrowOverflowException();
		return CFileTime((ULONGLONG)value);
	}

	operator CTime() const
	{
		NLong value = this->value;
		NLong value1 = value / N_TIME_SPAN_TICKS_PER_SECOND;
		NLong value0 = value - value1 * N_TIME_SPAN_TICKS_PER_SECOND;
		if (value0 >= (N_TIME_SPAN_TICKS_PER_SECOND / 2)) value1++;\
		value1 -= UnixEpoch / N_TIME_SPAN_TICKS_PER_SECOND;
		if (value < 0 || value1 > (NLong)(((NULong)((__time64_t)-1)) / 2)) NThrowOverflowException();
		return CTime((__time64_t)value1);
	}
#elif defined(N_FRAMEWORK_WX)
	operator wxDateTime() const
	{
		NLong value = this->value;
		NLong value1 = value / N_TIME_SPAN_TICKS_PER_SECOND;
		NLong value2 = (value - value1 * N_TIME_SPAN_TICKS_PER_SECOND) / N_TIME_SPAN_TICKS_PER_MILLISECOND;
		NLong value0 = value - value1 * N_TIME_SPAN_TICKS_PER_SECOND - value2 * N_TIME_SPAN_TICKS_PER_MILLISECOND;
		if (value0 >= N_TIME_SPAN_TICKS_PER_MILLISECOND / 2) { if (++value2 == 1000) { value2 = 0; value1++; } }
		value1 -= UnixEpoch / N_TIME_SPAN_TICKS_PER_SECOND;
		if (value1 < -(NLong)(((NULong)((time_t)-1)) / 2) || value1 >= (NLong)(((NULong)((time_t)-1)) / 2)) NThrowOverflowException();
		wxDateTime dateTime((time_t)value1);
		dateTime.SetMillisecond((wxDateTime::wxDateTime_t)value2);
		return dateTime;
	}
#elif defined(N_FRAMEWORK_QT)
	operator QDateTime() const
	{
		NLong value = this->value;
		NLong value1 = value / N_TIME_SPAN_TICKS_PER_SECOND;
		NLong value2 = (value - value1 * N_TIME_SPAN_TICKS_PER_SECOND) / N_TIME_SPAN_TICKS_PER_MILLISECOND;
		NLong value0 = value - value1 * N_TIME_SPAN_TICKS_PER_SECOND - value2 * N_TIME_SPAN_TICKS_PER_MILLISECOND;
		if (value0 >= N_TIME_SPAN_TICKS_PER_MILLISECOND / 2) { if (++value2 == 1000) { value2 = 0; value1++; } }
		value1 -= UnixEpoch / N_TIME_SPAN_TICKS_PER_SECOND;
		if (value < -(NLong)(((NULong)((uint)-1)) / 2) || value1 >= (NLong)(((NULong)((uint)-1)) / 2)) NThrowOverflowException();
		return QDateTime::fromTime_t((uint)value1).addMSecs((qint64)value2);
	}
#endif
};

#undef N_DATE_TIME_MIN
#undef N_DATE_TIME_MAX
const NDateTime N_DATE_TIME_MIN(0LL);
const NDateTime N_DATE_TIME_MAX(3155378975999999999LL);
}

#endif // !N_DATE_TIME_HPP_INCLUDED
