#ifndef N_STRING_HPP_INCLUDED
#define N_STRING_HPP_INCLUDED

#include <Core/NTypes.hpp>
#include <Core/NMemory.hpp>
namespace Neurotec
{
#include <Core/NString.h>
namespace Text
{
#include <Text/NEncoding.h>
}
}

namespace Neurotec
{

class NString
{
private:
	HNString handle;

	void Set(HNString hValue)
	{
		if (handle != NULL)
		{
			NStringFree(handle);
		}
		handle = hValue;
	}

public:
	static NString PromoteBuffer(NAChar * szValue, NInt length = -1, NMemoryType memoryType = nmmtDefault)
	{
		NString value;
		NCheck(NStringPromoteBufferA(szValue, length, memoryType, &value.handle));
		return value;
	}

#ifndef N_NO_UNICODE
	static NString PromoteBuffer(NWChar * szValue, NInt length = -1, NMemoryType memoryType = nmmtDefault)
	{
		NString value;
		NCheck(NStringPromoteBufferW(szValue, length, memoryType, &value.handle));
		return value;
	}
#endif

	static NInt Compare(const NString & value, NInt index, const NString & otherValue, NInt otherIndex, NInt length, bool ignoreCase = false)
	{
		NInt result;
		NCheck(NStringCompareRangeN(value.GetHandle(), index, otherValue.GetHandle(), otherIndex, length, ignoreCase ? NTrue : NFalse, &result));
		return result;
	}

	static NInt CompareA(const NString & value, NInt index, const NString & otherValue, NInt otherIndex, NInt length, bool ignoreCase = false)
	{
		NInt result;
		NCheck(NStringCompareRangeNA(value.GetHandle(), index, otherValue.GetHandle(), otherIndex, length, ignoreCase ? NTrue : NFalse, &result));
		return result;
	}

#ifndef N_NO_UNICODE
	static NInt CompareW(const NString & value, NInt index, const NString & otherValue, NInt otherIndex, NInt length, bool ignoreCase = false)
	{
		NInt result;
		NCheck(NStringCompareRangeNW(value.GetHandle(), index, otherValue.GetHandle(), otherIndex, length, ignoreCase ? NTrue : NFalse, &result));
		return result;
	}
#endif

	static NInt Compare(const NString & value, const NString & otherValue, bool ignoreCase = false)
	{
		NInt result;
		NCheck(NStringCompareRangeN(value.GetHandle(), 0, otherValue.GetHandle(), 0, N_INT_MAX, ignoreCase ? NTrue : NFalse, &result));
		return result;
	}

	static NInt CompareA(const NString & value, const NString & otherValue, bool ignoreCase = false)
	{
		NInt result;
		NCheck(NStringCompareRangeNA(value.GetHandle(), 0, otherValue.GetHandle(), 0, N_INT_MAX, ignoreCase ? NTrue : NFalse, &result));
		return result;
	}

#ifndef N_NO_UNICODE
	static NInt CompareW(const NString & value, const NString & otherValue, bool ignoreCase = false)
	{
		NInt result;
		NCheck(NStringCompareRangeNW(value.GetHandle(), 0, otherValue.GetHandle(), 0, N_INT_MAX, ignoreCase ? NTrue : NFalse, &result));
		return result;
	}
#endif

	static bool Equals(const NString & value, const NString & otherValue, bool ignoreCase = false)
	{
		NBool result;
		NCheck(NStringEqualsN(value.GetHandle(), otherValue.GetHandle(), ignoreCase, &result));
		return result != 0;
	}

	static NString Concat(const NString & value1, const NString & value2)
	{
		HNString hResult;
		NCheck(NStringConcatN(value1.GetHandle(), value2.GetHandle(), &hResult));
		return NString(hResult, true);
	}

	static NString Concat(const NAChar * szValue1, const NAChar * szValue2)
	{
		HNString hResult;
		NCheck(NStringConcatA(szValue1, szValue2, &hResult));
		return NString(hResult, true);
	}

#ifndef N_NO_UNICODE
	static NString Concat(const NWChar * szValue1, const NWChar * szValue2)
	{
		HNString hResult;
		NCheck(NStringConcatW(szValue1, szValue2, &hResult));
		return NString(hResult, true);
	}
#endif

	static NString Concat(const NAChar * arValue1, NInt value1Length, const NAChar * arValue2, NInt value2Length)
	{
		HNString hResult;
		NCheck(NStringConcatCharsA(arValue1, value1Length, arValue2, value2Length, &hResult));
		return NString(hResult, true);
	}

#ifndef N_NO_UNICODE
	static NString Concat(const NWChar * arValue1, NInt value1Length, const NWChar * arValue2, NInt value2Length)
	{
		HNString hResult;
		NCheck(NStringConcatCharsW(arValue1, value1Length, arValue2, value2Length, &hResult));
		return NString(hResult, true);
	}
#endif

	static NString ConcatN(const NString * arValues, NInt count)
	{
		HNString hResult;
		NCheck(NStringConcatArrayN(reinterpret_cast<const HNString *>(arValues), count, &hResult));
		return NString(hResult, true);
	}

	static NString Concat(const NAChar * const * arszValues, NInt count)
	{
		HNString hResult;
		NCheck(NStringConcatArrayA(arszValues, count, &hResult));
		return NString(hResult, true);
	}

#ifndef N_NO_UNICODE
	static NString Concat(const NWChar * const * arszValues, NInt count)
	{
		HNString hResult;
		NCheck(NStringConcatArrayW(arszValues, count, &hResult));
		return NString(hResult, true);
	}
#endif

	static NString Concat(NInt count, va_list args)
	{
		HNString hResult;
		NCheck(NStringConcatManyVA(&hResult, count, args));
		return NString(hResult, true);
	}

	static NString ConcatA(NInt count, va_list args)
	{
		HNString hResult;
		NCheck(NStringConcatManyVAA(&hResult, count, args));
		return NString(hResult, true);
	}

#ifndef N_NO_UNICODE
	static NString ConcatW(NInt count, va_list args)
	{
		HNString hResult;
		NCheck(NStringConcatManyVAW(&hResult, count, args));
		return NString(hResult, true);
	}
#endif

	static NString Concat(NInt count, ...)
	{
		va_list args;
		va_start(args, count);
		try
		{
			NString v = Concat(count, args);
			va_end(args);
			return v;
		}
		catch (...)
		{
			va_end(args);
			throw;
		}
	}

	static NString ConcatA(NInt count, ...)
	{
		va_list args;
		va_start(args, count);
		try
		{
			NString v = ConcatA(count, args);
			va_end(args);
			return v;
		}
		catch (...)
		{
			va_end(args);
			throw;
		}
	}

#ifndef N_NO_UNICODE
	static NString ConcatW(NInt count, ...)
	{
		va_list args;
		va_start(args, count);
		try
		{
			NString v = ConcatW(count, args);
			va_end(args);
			return v;
		}
		catch (...)
		{
			va_end(args);
			throw;
		}
	}
#endif

	static NString Join(const NString & separator, const NString * arValues, NInt count)
	{
		HNString hResult;
		NCheck(NStringJoinArrayN(separator.GetHandle(), reinterpret_cast<const HNString *>(arValues), count, &hResult));
		return NString(hResult, true);
	}

	static NString Join(const NAChar * szSeparator, const NString * arValues, NInt count)
	{
		HNString hResult;
		NCheck(NStringJoinArrayVNA(szSeparator, reinterpret_cast<const HNString *>(arValues), count, &hResult));
		return NString(hResult, true);
	}

#ifndef N_NO_UNICODE
	static NString Join(const NWChar * szSeparator, const NString * arValues, NInt count)
	{
		HNString hResult;
		NCheck(NStringJoinArrayVNW(szSeparator, reinterpret_cast<const HNString *>(arValues), count, &hResult));
		return NString(hResult, true);
	}
#endif

	static NString Join(const NAChar * szSeparator, const NAChar * const * arszValues, NInt count)
	{
		HNString hResult;
		NCheck(NStringJoinArrayA(szSeparator, arszValues, count, &hResult));
		return NString(hResult, true);
	}

#ifndef N_NO_UNICODE
	static NString Join(const NWChar * szSeparator, const NWChar * const * arszValues, NInt count)
	{
		HNString hResult;
		NCheck(NStringJoinArrayW(szSeparator, arszValues, count, &hResult));
		return NString(hResult, true);
	}
#endif

	static NString Join(const NAChar * szSeparator, NInt count, va_list args)
	{
		HNString hResult;
		NCheck(NStringJoinManyVAA(szSeparator, &hResult, count, args));
		return NString(hResult, true);
	}

#ifndef N_NO_UNICODE
	static NString Join(const NWChar * szSeparator, NInt count, va_list args)
	{
		HNString hResult;
		NCheck(NStringJoinManyVAW(szSeparator, &hResult, count, args));
		return NString(hResult, true);
	}
#endif

	static NString Join(const NAChar * szSeparator, NInt count, ...)
	{
		va_list args;
		va_start(args, count);
		try
		{
			NString v = Join(szSeparator, count, args);
			va_end(args);
			return v;
		}
		catch (...)
		{
			va_end(args);
			throw;
		}
	}

#ifndef N_NO_UNICODE
	static NString Join(const NWChar * szSeparator, NInt count, ...)
	{
		va_list args;
		va_start(args, count);
		try
		{
			NString v = Join(szSeparator, count, args);
			va_end(args);
			return v;
		}
		catch (...)
		{
			va_end(args);
			throw;
		}
	}
#endif

	static NString Format(const NString & format, va_list args)
	{
		HNString hResult;
		NCheck(NStringFormatVAN(&hResult, format.GetHandle(), args));
		return NString(hResult, true);
	}

	static NString Format(const NAChar * szFormat, va_list args)
	{
		HNString hResult;
		NCheck(NStringFormatVAA(&hResult, szFormat, args));
		return NString(hResult, true);
	}

#ifndef N_NO_UNICODE
	static NString Format(const NWChar * szFormat, va_list args)
	{
		HNString hResult;
		NCheck(NStringFormatVAW(&hResult, szFormat, args));
		return NString(hResult, true);
	}
#endif

	static NString Format(const NString format, ...)
	{
		va_list args;
		va_start(args, format);
		try
		{
			NString v = Format(format, args);
			va_end(args);
			return v;
		}
		catch (...)
		{
			va_end(args);
			throw;
		}
	}

	static NString Format(const NAChar * szFormat, ...)
	{
		va_list args;
		va_start(args, szFormat);
		try
		{
			NString v = Format(szFormat, args);
			va_end(args);
			return v;
		}
		catch (...)
		{
			va_end(args);
			throw;
		}
	}

#ifndef N_NO_UNICODE
	static NString Format(const NWChar * szFormat, ...)
	{
		va_list args;
		va_start(args, szFormat);
		try
		{
			NString v = Format(szFormat, args);
			va_end(args);
			return v;
		}
		catch (...)
		{
			va_end(args);
			throw;
		}
	}
#endif

	NString()
		: handle(NULL)
	{
	}

	NString(const NString & other)
		: handle(NULL)
	{
		this->operator=(other);
	}

#ifdef N_CPP11
	NString(NString && other)
		: handle(other.handle)
	{
		other.handle = NULL;
	}

	NString& operator=(NString && other)
	{
		if (this != &other)
		{
			Set(nullptr);
			handle = other.handle;
			other.handle = nullptr;
		}
		return *this;
	}
#endif

	NString(HNString hValue, bool ownsHandle)
		: handle(ownsHandle ? hValue : NULL)
	{
		if (!ownsHandle) NCheck(NStringClone(hValue, &handle));
	}

	NString(NAChar value, NInt count)
		: handle(NULL)
	{
		NCheck(NStringCreateFromCharA(value, count, &handle));
	}

	NString(const NAChar * szValue)
		: handle(NULL)
	{
		*this = szValue;
	}

#ifndef N_NO_UNICODE
	NString(const NWChar * szValue)
		: handle(NULL)
	{
		*this = szValue;
	}
#endif

	NString(const NAChar * arValue, NInt valueLength)
		: handle(NULL)
	{
		NCheck(NStringCreateFromCharsA(arValue, valueLength, &handle));
	}

#ifndef N_NO_UNICODE
	NString(const NWChar * arValue, NInt valueLength)
		: handle(NULL)
	{
		NCheck(NStringCreateFromCharsW(arValue, valueLength, &handle));
	}
#endif

	~NString()
	{
		Set(NULL);
	}

	HNString GetHandle() const
	{
		return handle;
	}

	HNString CloneHandle() const
	{
		HNString hValue;
		NCheck(NStringClone(handle, &hValue));
		return hValue;
	}

	bool IsNull() const
	{
		return handle == NULL;
	}

	bool IsEmpty() const
	{
		return NStringIsEmpty(handle) != 0;
	}

	bool IsA() const
	{
		return NStringIsA(handle) != 0;
	}

#ifndef N_NO_UNICODE
	bool IsW() const
	{
		return NStringIsW(handle) != 0;
	}
#endif

	bool HasEmbeddedNull() const
	{
		NBool value;
		NCheck(NStringHasEmbeddedNull(handle, &value));
		return value != 0;
	}

	bool IsWhiteSpace() const
	{
		NBool value;
		NCheck(NStringIsWhiteSpace(handle, &value));
		return value != 0;
	}

	NInt GetHashCode() const
	{
		NInt value;
		NCheck(NStringGetHashCode(handle, &value));
		return value;
	}

	NInt GetLength() const
	{
		NInt value;
		NCheck(NStringGetLength(handle, &value));
		return value;
	}

	NInt GetLengthA() const
	{
		NInt value;
		NCheck(NStringGetLengthA(handle, &value));
		return value;
	}

#ifndef N_NO_UNICODE
	NInt GetLengthW() const
	{
		NInt value;
		NCheck(NStringGetLengthW(handle, &value));
		return value;
	}
#endif

	const NChar * GetBuffer(NInt * pLength = NULL) const
	{
		const NChar * szValue;
		NCheck(NStringGetBuffer(handle, pLength, &szValue));
		return szValue;
	}

	const NAChar * GetBufferA(NInt * pLength = NULL) const
	{
		const NAChar * szValue;
		NCheck(NStringGetBufferA(handle, pLength, &szValue));
		return szValue;
	}

#ifndef N_NO_UNICODE
	const NWChar * GetBufferW(NInt * pLength = NULL) const
	{
		const NWChar * szValue;
		NCheck(NStringGetBufferW(handle, pLength, &szValue));
		return szValue;
	}
#endif

	NChar GetChar(NInt index) const
	{
		NChar value;
		NCheck(NStringGetChar(handle, index, &value));
		return value;
	}

	NAChar GetCharA(NInt index) const
	{
		NAChar value;
		NCheck(NStringGetCharA(handle, index, &value));
		return value;
	}

#ifndef N_NO_UNICODE
	NWChar GetCharW(NInt index) const
	{
		NWChar value;
		NCheck(NStringGetCharW(handle, index, &value));
		return value;
	}
#endif

	NInt CompareTo(const NString & value, bool ignoreCase = false) const
	{
		NInt result;
		NCheck(NStringCompareN(GetHandle(), value.GetHandle(), ignoreCase, &result));
		return result;
	}

	NInt CompareToA(const NString & value, bool ignoreCase = false) const
	{
		NInt result;
		NCheck(NStringCompareNA(GetHandle(), value.GetHandle(), ignoreCase, &result));
		return result;
	}

#ifndef N_NO_UNICODE
	NInt CompareToW(const NString & value, bool ignoreCase = false) const
	{
		NInt result;
		NCheck(NStringCompareNW(GetHandle(), value.GetHandle(), ignoreCase, &result));
		return result;
	}
#endif

	NInt CompareTo(const NAChar * arValue, NInt valueLength = -1, bool ignoreCase = false) const
	{
		NInt result;
		NCheck(NStringCompareStrOrCharsA(GetHandle(), arValue, valueLength, ignoreCase, &result));
		return result;
	}

#ifndef N_NO_UNICODE
	NInt CompareTo(const NWChar * arValue, NInt valueLength = -1, bool ignoreCase = false) const
	{
		NInt result;
		NCheck(NStringCompareStrOrCharsW(GetHandle(), arValue, valueLength, ignoreCase, &result));
		return result;
	}
#endif

	bool Equals(const NString & value, bool ignoreCase = false) const
	{
		NBool result;
		NCheck(NStringEqualsN(GetHandle(), value.GetHandle(), ignoreCase, &result));
		return result != 0;
	}

	bool Equals(const NAChar * arValue, NInt valueLength = -1, bool ignoreCase = false) const
	{
		NBool result;
		NCheck(NStringEqualsStrOrCharsA(GetHandle(), arValue, valueLength, ignoreCase, &result));
		return result != 0;
	}

#ifndef N_NO_UNICODE
	bool Equals(const NWChar * arValue, NInt valueLength = -1, bool ignoreCase = false) const
	{
		NBool result;
		NCheck(NStringEqualsStrOrCharsW(GetHandle(), arValue, valueLength, ignoreCase, &result));
		return result != 0;
	}
#endif

	bool StartsWith(const NString & value, bool ignoreCase = false) const
	{
		NBool result;
		NCheck(NStringStartsWithN(GetHandle(), value.GetHandle(), ignoreCase, &result));
		return result != 0;
	}

	bool StartsWith(const NAChar * arValue, NInt valueLength = -1, bool ignoreCase = false) const
	{
		NBool result;
		NCheck(NStringStartsWithStrOrCharsA(GetHandle(), arValue, valueLength, ignoreCase, &result));
		return result != 0;
	}

#ifndef N_NO_UNICODE
	bool StartsWith(const NWChar * arValue, NInt valueLength = -1, bool ignoreCase = false) const
	{
		NBool result;
		NCheck(NStringStartsWithStrOrCharsW(GetHandle(), arValue, valueLength, ignoreCase, &result));
		return result != 0;
	}
#endif

	bool EndsWith(const NString & value, bool ignoreCase = false) const
	{
		NBool result;
		NCheck(NStringEndsWithN(GetHandle(), value.GetHandle(), ignoreCase, &result));
		return result != 0;
	}

	bool EndsWith(const NAChar * arValue, NInt valueLength = -1, bool ignoreCase = false) const
	{
		NBool result;
		NCheck(NStringEndsWithStrOrCharsA(GetHandle(), arValue, valueLength, ignoreCase, &result));
		return result != 0;
	}

#ifndef N_NO_UNICODE
	bool EndsWith(const NWChar * arValue, NInt valueLength = -1, bool ignoreCase = false) const
	{
		NBool result;
		NCheck(NStringEndsWithStrOrCharsW(GetHandle(), arValue, valueLength, ignoreCase, &result));
		return result != 0;
	}
#endif

	NInt IndexOfAny(const NAChar * arAnyOf, NInt anyOfLength, NInt startIndex, NInt count) const
	{
		NInt index;
		NCheck(NStringIndexOfAnyInRangeA(GetHandle(), arAnyOf, anyOfLength, startIndex, count, &index));
		return index;
	}

#ifndef N_NO_UNICODE
	NInt IndexOfAny(const NWChar * arAnyOf, NInt anyOfLength, NInt startIndex, NInt count) const
	{
		NInt index;
		NCheck(NStringIndexOfAnyInRangeW(GetHandle(), arAnyOf, anyOfLength, startIndex, count, &index));
		return index;
	}
#endif

	NInt IndexOfAny(const NAChar * arAnyOf, NInt anyOfLength, NInt startIndex) const
	{
		NInt index;
		NCheck(NStringIndexOfAnyFromA(GetHandle(), arAnyOf, anyOfLength, startIndex, &index));
		return index;
	}

#ifndef N_NO_UNICODE
	NInt IndexOfAny(const NWChar * arAnyOf, NInt anyOfLength, NInt startIndex) const
	{
		NInt index;
		NCheck(NStringIndexOfAnyFromW(GetHandle(), arAnyOf, anyOfLength, startIndex, &index));
		return index;
	}
#endif

	NInt IndexOfAny(const NAChar * arAnyOf, NInt anyOfLength) const
	{
		NInt index;
		NCheck(NStringIndexOfAnyA(GetHandle(), arAnyOf, anyOfLength, &index));
		return index;
	}

#ifndef N_NO_UNICODE
	NInt IndexOfAny(const NWChar * arAnyOf, NInt anyOfLength) const
	{
		NInt index;
		NCheck(NStringIndexOfAnyW(GetHandle(), arAnyOf, anyOfLength, &index));
		return index;
	}
#endif

	NInt LastIndexOfAny(const NAChar * arAnyOf, NInt anyOfLength, NInt startIndex, NInt count) const
	{
		NInt index;
		NCheck(NStringLastIndexOfAnyInRangeA(GetHandle(), arAnyOf, anyOfLength, startIndex, count, &index));
		return index;
	}

#ifndef N_NO_UNICODE
	NInt LastIndexOfAny(const NWChar * arAnyOf, NInt anyOfLength, NInt startIndex, NInt count) const
	{
		NInt index;
		NCheck(NStringLastIndexOfAnyInRangeW(GetHandle(), arAnyOf, anyOfLength, startIndex, count, &index));
		return index;
	}
#endif

	NInt LastIndexOfAny(const NAChar * arAnyOf, NInt anyOfLength, NInt startIndex) const
	{
		NInt index;
		NCheck(NStringLastIndexOfAnyFromA(GetHandle(), arAnyOf, anyOfLength, startIndex, &index));
		return index;
	}

#ifndef N_NO_UNICODE
	NInt LastIndexOfAny(const NWChar * arAnyOf, NInt anyOfLength, NInt startIndex) const
	{
		NInt index;
		NCheck(NStringLastIndexOfAnyFromW(GetHandle(), arAnyOf, anyOfLength, startIndex, &index));
		return index;
	}
#endif

	NInt LastIndexOfAny(const NAChar * arAnyOf, NInt anyOfLength) const
	{
		NInt index;
		NCheck(NStringLastIndexOfAnyA(GetHandle(), arAnyOf, anyOfLength, &index));
		return index;
	}

#ifndef N_NO_UNICODE
	NInt LastIndexOfAny(const NWChar * arAnyOf, NInt anyOfLength) const
	{
		NInt index;
		NCheck(NStringLastIndexOfAnyW(GetHandle(), arAnyOf, anyOfLength, &index));
		return index;
	}
#endif

	NInt IndexOf(NAChar value, NInt startIndex, NInt count) const
	{
		NInt index;
		NCheck(NStringIndexOfInRangeA(GetHandle(), value, startIndex, count, &index));
		return index;
	}

#ifndef N_NO_UNICODE
	NInt IndexOf(NWChar value, NInt startIndex, NInt count) const
	{
		NInt index;
		NCheck(NStringIndexOfInRangeW(GetHandle(), value, startIndex, count, &index));
		return index;
	}
#endif

	NInt IndexOf(NAChar value, NInt startIndex) const
	{
		NInt index;
		NCheck(NStringIndexOfFromA(GetHandle(), value, startIndex, &index));
		return index;
	}

#ifndef N_NO_UNICODE
	NInt IndexOf(NWChar value, NInt startIndex) const
	{
		NInt index;
		NCheck(NStringIndexOfFromW(GetHandle(), value, startIndex, &index));
		return index;
	}
#endif

	NInt IndexOf(NAChar value) const
	{
		NInt index;
		NCheck(NStringIndexOfA(GetHandle(), value, &index));
		return index;
	}

#ifndef N_NO_UNICODE
	NInt IndexOf(NWChar value) const
	{
		NInt index;
		NCheck(NStringIndexOfW(GetHandle(), value, &index));
		return index;
	}
#endif

	NInt LastIndexOf(NAChar value, NInt startIndex, NInt count) const
	{
		NInt index;
		NCheck(NStringLastIndexOfInRangeA(GetHandle(), value, startIndex, count, &index));
		return index;
	}

#ifndef N_NO_UNICODE
	NInt LastIndexOf(NWChar value, NInt startIndex, NInt count) const
	{
		NInt index;
		NCheck(NStringLastIndexOfInRangeW(GetHandle(), value, startIndex, count, &index));
		return index;
	}
#endif

	NInt LastIndexOf(NAChar value, NInt startIndex) const
	{
		NInt index;
		NCheck(NStringLastIndexOfFromA(GetHandle(), value, startIndex, &index));
		return index;
	}

#ifndef N_NO_UNICODE
	NInt LastIndexOf(NWChar value, NInt startIndex) const
	{
		NInt index;
		NCheck(NStringLastIndexOfFromW(GetHandle(), value, startIndex, &index));
		return index;
	}
#endif

	NInt LastIndexOf(NAChar value) const
	{
		NInt index;
		NCheck(NStringLastIndexOfA(GetHandle(), value, &index));
		return index;
	}

#ifndef N_NO_UNICODE
	NInt LastIndexOf(NWChar value) const
	{
		NInt index;
		NCheck(NStringLastIndexOfW(GetHandle(), value, &index));
		return index;
	}
#endif

	NInt IndexOf(const NString & value, NInt startIndex, NInt count, bool ignoreCase = false) const
	{
		NInt index;
		NCheck(NStringIndexOfStrInRangeN(GetHandle(), value.GetHandle(), startIndex, count, ignoreCase, &index));
		return index;
	}

	NInt IndexOfA(const NString & value, NInt startIndex, NInt count, bool ignoreCase = false) const
	{
		NInt index;
		NCheck(NStringIndexOfStrInRangeNA(GetHandle(), value.GetHandle(), startIndex, count, ignoreCase, &index));
		return index;
	}

#ifndef N_NO_UNICODE
	NInt IndexOfW(const NString & value, NInt startIndex, NInt count, bool ignoreCase = false) const
	{
		NInt index;
		NCheck(NStringIndexOfStrInRangeNW(GetHandle(), value.GetHandle(), startIndex, count, ignoreCase, &index));
		return index;
	}
#endif

	NInt IndexOf(const NString & value, NInt startIndex, bool ignoreCase = false) const
	{
		NInt index;
		NCheck(NStringIndexOfStrFromN(GetHandle(), value.GetHandle(), startIndex, ignoreCase, &index));
		return index;
	}

	NInt IndexOfA(const NString & value, NInt startIndex, bool ignoreCase = false) const
	{
		NInt index;
		NCheck(NStringIndexOfStrFromNA(GetHandle(), value.GetHandle(), startIndex, ignoreCase, &index));
		return index;
	}

#ifndef N_NO_UNICODE
	NInt IndexOfW(const NString & value, NInt startIndex, bool ignoreCase = false) const
	{
		NInt index;
		NCheck(NStringIndexOfStrFromNW(GetHandle(), value.GetHandle(), startIndex, ignoreCase, &index));
		return index;
	}
#endif

	NInt IndexOf(const NString & value, bool ignoreCase = false) const
	{
		NInt index;
		NCheck(NStringIndexOfStrN(GetHandle(), value.GetHandle(), ignoreCase, &index));
		return index;
	}

	NInt IndexOfA(const NString & value, bool ignoreCase = false) const
	{
		NInt index;
		NCheck(NStringIndexOfStrNA(GetHandle(), value.GetHandle(), ignoreCase, &index));
		return index;
	}

#ifndef N_NO_UNICODE
	NInt IndexOfW(const NString & value, bool ignoreCase = false) const
	{
		NInt index;
		NCheck(NStringIndexOfStrNW(GetHandle(), value.GetHandle(), ignoreCase, &index));
		return index;
	}
#endif

	NInt IndexOf(const NAChar * szValue, NInt startIndex, NInt count, bool ignoreCase = false) const
	{
		NInt index;
		NCheck(NStringIndexOfStrInRangeA(GetHandle(), szValue, startIndex, count, ignoreCase, &index));
		return index;
	}

#ifndef N_NO_UNICODE
	NInt IndexOf(const NWChar * szValue, NInt startIndex, NInt count, bool ignoreCase = false) const
	{
		NInt index;
		NCheck(NStringIndexOfStrInRangeW(GetHandle(), szValue, startIndex, count, ignoreCase, &index));
		return index;
	}
#endif

	NInt IndexOf(const NAChar * szValue, NInt startIndex, bool ignoreCase = false) const
	{
		NInt index;
		NCheck(NStringIndexOfStrFromA(GetHandle(), szValue, startIndex, ignoreCase, &index));
		return index;
	}

#ifndef N_NO_UNICODE
	NInt IndexOf(const NWChar * szValue, NInt startIndex, bool ignoreCase = false) const
	{
		NInt index;
		NCheck(NStringIndexOfStrFromW(GetHandle(), szValue, startIndex, ignoreCase, &index));
		return index;
	}
#endif

	NInt IndexOf(const NAChar * szValue, bool ignoreCase = false) const
	{
		NInt index;
		NCheck(NStringIndexOfStrA(GetHandle(), szValue, ignoreCase, &index));
		return index;
	}

#ifndef N_NO_UNICODE
	NInt IndexOf(const NWChar * szValue, bool ignoreCase = false) const
	{
		NInt index;
		NCheck(NStringIndexOfStrW(GetHandle(), szValue, ignoreCase, &index));
		return index;
	}
#endif

	NInt IndexOfChars(const NAChar * arValue, NInt valueLength, NInt startIndex, NInt count, bool ignoreCase = false) const
	{
		NInt index;
		NCheck(NStringIndexOfCharsInRangeA(GetHandle(), arValue, valueLength, startIndex, count, ignoreCase, &index));
		return index;
	}

#ifndef N_NO_UNICODE
	NInt IndexOfChars(const NWChar * arValue, NInt valueLength, NInt startIndex, NInt count, bool ignoreCase = false) const
	{
		NInt index;
		NCheck(NStringIndexOfCharsInRangeW(GetHandle(), arValue, valueLength, startIndex, count, ignoreCase, &index));
		return index;
	}
#endif

	NInt IndexOfChars(const NAChar * arValue, NInt valueLength, NInt startIndex, bool ignoreCase = false) const
	{
		NInt index;
		NCheck(NStringIndexOfCharsFromA(GetHandle(), arValue, valueLength, startIndex, ignoreCase, &index));
		return index;
	}

#ifndef N_NO_UNICODE
	NInt IndexOfChars(const NWChar * arValue, NInt valueLength, NInt startIndex, bool ignoreCase = false) const
	{
		NInt index;
		NCheck(NStringIndexOfCharsFromW(GetHandle(), arValue, valueLength, startIndex, ignoreCase, &index));
		return index;
	}
#endif

	NInt IndexOfChars(const NAChar * arValue, NInt valueLength, bool ignoreCase = false) const
	{
		NInt index;
		NCheck(NStringIndexOfCharsA(GetHandle(), arValue, valueLength, ignoreCase, &index));
		return index;
	}

#ifndef N_NO_UNICODE
	NInt IndexOfChars(const NWChar * arValue, NInt valueLength, bool ignoreCase = false) const
	{
		NInt index;
		NCheck(NStringIndexOfCharsW(GetHandle(), arValue, valueLength, ignoreCase, &index));
		return index;
	}
#endif

	NInt LastIndexOf(const NString & value, NInt startIndex, NInt count, bool ignoreCase = false) const
	{
		NInt index;
		NCheck(NStringLastIndexOfStrInRangeN(GetHandle(), value.GetHandle(), startIndex, count, ignoreCase, &index));
		return index;
	}

	NInt LastIndexOfA(const NString & value, NInt startIndex, NInt count, bool ignoreCase = false) const
	{
		NInt index;
		NCheck(NStringLastIndexOfStrInRangeNA(GetHandle(), value.GetHandle(), startIndex, count, ignoreCase, &index));
		return index;
	}

#ifndef N_NO_UNICODE
	NInt LastIndexOfW(const NString & value, NInt startIndex, NInt count, bool ignoreCase = false) const
	{
		NInt index;
		NCheck(NStringLastIndexOfStrInRangeNW(GetHandle(), value.GetHandle(), startIndex, count, ignoreCase, &index));
		return index;
	}
#endif

	NInt LastIndexOf(const NString & value, NInt startIndex, bool ignoreCase = false) const
	{
		NInt index;
		NCheck(NStringLastIndexOfStrFromN(GetHandle(), value.GetHandle(), startIndex, ignoreCase, &index));
		return index;
	}

	NInt LastIndexOfA(const NString & value, NInt startIndex, bool ignoreCase = false) const
	{
		NInt index;
		NCheck(NStringLastIndexOfStrFromNA(GetHandle(), value.GetHandle(), startIndex, ignoreCase, &index));
		return index;
	}

#ifndef N_NO_UNICODE
	NInt LastIndexOfW(const NString & value, NInt startIndex, bool ignoreCase = false) const
	{
		NInt index;
		NCheck(NStringLastIndexOfStrFromNW(GetHandle(), value.GetHandle(), startIndex, ignoreCase, &index));
		return index;
	}
#endif

	NInt LastIndexOf(const NString & value, bool ignoreCase = false) const
	{
		NInt index;
		NCheck(NStringLastIndexOfStrN(GetHandle(), value.GetHandle(), ignoreCase, &index));
		return index;
	}

	NInt LastIndexOfA(const NString & value, bool ignoreCase = false) const
	{
		NInt index;
		NCheck(NStringLastIndexOfStrNA(GetHandle(), value.GetHandle(), ignoreCase, &index));
		return index;
	}

#ifndef N_NO_UNICODE
	NInt LastIndexOfW(const NString & value, bool ignoreCase = false) const
	{
		NInt index;
		NCheck(NStringLastIndexOfStrNW(GetHandle(), value.GetHandle(), ignoreCase, &index));
		return index;
	}
#endif

	NInt LastIndexOf(const NAChar * szValue, NInt startIndex, NInt count, bool ignoreCase = false) const
	{
		NInt index;
		NCheck(NStringLastIndexOfStrInRangeA(GetHandle(), szValue, startIndex, count, ignoreCase, &index));
		return index;
	}

#ifndef N_NO_UNICODE
	NInt LastIndexOf(const NWChar * szValue, NInt startIndex, NInt count, bool ignoreCase = false) const
	{
		NInt index;
		NCheck(NStringLastIndexOfStrInRangeW(GetHandle(), szValue, startIndex, count, ignoreCase, &index));
		return index;
	}
#endif

	NInt LastIndexOf(const NAChar * szValue, NInt startIndex, bool ignoreCase = false) const
	{
		NInt index;
		NCheck(NStringLastIndexOfStrFromA(GetHandle(), szValue, startIndex, ignoreCase, &index));
		return index;
	}

#ifndef N_NO_UNICODE
	NInt LastIndexOf(const NWChar * szValue, NInt startIndex, bool ignoreCase = false) const
	{
		NInt index;
		NCheck(NStringLastIndexOfStrFromW(GetHandle(), szValue, startIndex, ignoreCase, &index));
		return index;
	}
#endif

	NInt LastIndexOf(const NAChar * szValue, bool ignoreCase = false) const
	{
		NInt index;
		NCheck(NStringLastIndexOfStrA(GetHandle(), szValue, ignoreCase, &index));
		return index;
	}

#ifndef N_NO_UNICODE
	NInt LastIndexOf(const NWChar * szValue, bool ignoreCase = false) const
	{
		NInt index;
		NCheck(NStringLastIndexOfStrW(GetHandle(), szValue, ignoreCase, &index));
		return index;
	}
#endif

	NInt LastIndexOfChars(const NAChar * arValue, NInt valueLength, NInt startIndex, NInt count, bool ignoreCase = false) const
	{
		NInt index;
		NCheck(NStringLastIndexOfCharsInRangeA(GetHandle(), arValue, valueLength, startIndex, count, ignoreCase, &index));
		return index;
	}

#ifndef N_NO_UNICODE
	NInt LastIndexOfChars(const NWChar * arValue, NInt valueLength, NInt startIndex, NInt count, bool ignoreCase = false) const
	{
		NInt index;
		NCheck(NStringLastIndexOfCharsInRangeW(GetHandle(), arValue, valueLength, startIndex, count, ignoreCase, &index));
		return index;
	}
#endif

	NInt LastIndexOfChars(const NAChar * arValue, NInt valueLength, NInt startIndex, bool ignoreCase = false) const
	{
		NInt index;
		NCheck(NStringLastIndexOfCharsFromA(GetHandle(), arValue, valueLength, startIndex, ignoreCase, &index));
		return index;
	}

#ifndef N_NO_UNICODE
	NInt LastIndexOfChars(const NWChar * arValue, NInt valueLength, NInt startIndex, bool ignoreCase = false) const
	{
		NInt index;
		NCheck(NStringLastIndexOfCharsFromW(GetHandle(), arValue, valueLength, startIndex, ignoreCase, &index));
		return index;
	}
#endif

	NInt LastIndexOfChars(const NAChar * arValue, NInt valueLength, bool ignoreCase = false) const
	{
		NInt index;
		NCheck(NStringLastIndexOfCharsA(GetHandle(), arValue, valueLength, ignoreCase, &index));
		return index;
	}

#ifndef N_NO_UNICODE
	NInt LastIndexOfChars(const NWChar * arValue, NInt valueLength, bool ignoreCase = false) const
	{
		NInt index;
		NCheck(NStringLastIndexOfCharsW(GetHandle(), arValue, valueLength, ignoreCase, &index));
		return index;
	}
#endif

	bool Contains(const NString & value) const
	{
		NBool result;
		NCheck(NStringContainsStrN(GetHandle(), value.GetHandle(), &result));
		return result != 0;
	}

	bool Contains(const NAChar * arValue, NInt valueLength = -1) const
	{
		NBool result;
		NCheck(NStringContainsStrOrCharsA(GetHandle(), arValue, valueLength, &result));
		return result != 0;
	}

#ifndef N_NO_UNICODE
	bool Contains(const NWChar * arValue, NInt valueLength = -1) const
	{
		NBool result;
		NCheck(NStringContainsStrOrCharsW(GetHandle(), arValue, valueLength, &result));
		return result != 0;
	}
#endif

	NString * Split(const NAChar * arSeparators, NInt separatorCount, NInt * pValueCount, bool removeEmptyEntries = false, NInt count = N_INT_MAX) const
	{
		HNString * arhValues;
		NCheck(NStringSplitWithCountA(GetHandle(), arSeparators, separatorCount, count, removeEmptyEntries, &arhValues, pValueCount));
		return reinterpret_cast<NString *>(arhValues);
	}

#ifndef N_NO_UNICODE
	NString * Split(const NWChar * arSeparators, NInt separatorCount, NInt * pValueCount, bool removeEmptyEntries = false, NInt count = N_INT_MAX) const
	{
		HNString * arhValues;
		NCheck(NStringSplitWithCountW(GetHandle(), arSeparators, separatorCount, count, removeEmptyEntries, &arhValues, pValueCount));
		return reinterpret_cast<NString *>(arhValues);
	}
#endif

	NString * Split(const NString * arSeparators, NInt separatorCount, NInt * pValueCount, bool removeEmptyEntries = false, NInt count = N_INT_MAX) const
	{
		HNString * arhValues;
		NCheck(NStringSplitWithStrsAndCountN(GetHandle(), reinterpret_cast<const HNString *>(arSeparators), separatorCount, count, removeEmptyEntries, &arhValues, pValueCount));
		return reinterpret_cast<NString *>(arhValues);
	}

	NString * Split(const NAChar * const * arszSeparators, NInt separatorCount, NInt * pValueCount, bool removeEmptyEntries = false, NInt count = N_INT_MAX) const
	{
		HNString * arhValues;
		NCheck(NStringSplitWithStrsAndCountA(GetHandle(), arszSeparators, separatorCount, count, removeEmptyEntries, &arhValues, pValueCount));
		return reinterpret_cast<NString *>(arhValues);
	}

#ifndef N_NO_UNICODE
	NString * Split(const NWChar * const * arszSeparators, NInt separatorCount, NInt * pValueCount, bool removeEmptyEntries = false, NInt count = N_INT_MAX) const
	{
		HNString * arhValues;
		NCheck(NStringSplitWithStrsAndCountW(GetHandle(), arszSeparators, separatorCount, count, removeEmptyEntries, &arhValues, pValueCount));
		return reinterpret_cast<NString *>(arhValues);
	}
#endif

	void CopyToString(NInt sourceIndex, NAChar * szValue, NInt valueSize, NInt count) const
	{
		NCheck(NStringCopyToStringA(GetHandle(), sourceIndex, szValue, valueSize, count));
	}

#ifndef N_NO_UNICODE
	void CopyToString(NInt sourceIndex, NWChar * szValue, NInt valueSize, NInt count) const
	{
		NCheck(NStringCopyToStringW(GetHandle(), sourceIndex, szValue, valueSize, count));
	}
#endif

	void CopyTo(NInt sourceIndex, NAChar * arValue, NInt valueLength, NInt count) const
	{
		NCheck(NStringCopyToA(GetHandle(), sourceIndex, arValue, valueLength, count));
	}

#ifndef N_NO_UNICODE
	void CopyTo(NInt sourceIndex, NWChar * arValue, NInt valueLength, NInt count) const
	{
		NCheck(NStringCopyToW(GetHandle(), sourceIndex, arValue, valueLength, count));
	}
#endif

	NString ToString(const NString & format) const
	{
		HNString hValue;
		NCheck(NStringToStringN(GetHandle(), format.GetHandle(), &hValue));
		return NString(hValue, true);
	}

	NString ToString(const NAChar * szFormat) const
	{
		HNString hValue;
		NCheck(NStringToStringA(GetHandle(), szFormat, &hValue));
		return NString(hValue, true);
	}

#ifndef N_NO_UNICODE
	NString ToString(const NWChar * szFormat) const
	{
		HNString hValue;
		NCheck(NStringToStringW(GetHandle(), szFormat, &hValue));
		return NString(hValue, true);
	}
#endif

	NChar * ToNewString(NInt * pLength = NULL) const
	{
		NChar * szValue;
		NCheck(NStringToNewString(GetHandle(), &szValue, pLength));
		return szValue;
	}

	NAChar * ToNewStringA(NInt * pLength = NULL) const
	{
		NAChar * szValue;
		NCheck(NStringToNewStringA(GetHandle(), &szValue, pLength));
		return szValue;
	}

#ifndef N_NO_UNICODE
	NWChar * ToNewStringW(NInt * pLength = NULL) const
	{
		NWChar * szValue;
		NCheck(NStringToNewStringW(GetHandle(), &szValue, pLength));
		return szValue;
	}
#endif

	NChar * ToCharArray(NInt * pLength) const
	{
		NChar * arValue;
		NCheck(NStringToCharArray(GetHandle(), &arValue, pLength));
		return arValue;
	}

	NAChar * ToCharArrayA(NInt * pLength) const
	{
		NAChar * arValue;
		NCheck(NStringToCharArrayA(GetHandle(), &arValue, pLength));
		return arValue;
	}

#ifndef N_NO_UNICODE
	NWChar * ToCharArrayW(NInt * pLength) const
	{
		NWChar * arValue;
		NCheck(NStringToCharArrayW(GetHandle(), &arValue, pLength));
		return arValue;
	}
#endif

	NChar * ToNewString(NInt startIndex, NInt length, NInt * pLength = NULL) const
	{
		NChar * szValue;
		NCheck(NStringToNewStringRange(GetHandle(), startIndex, length, &szValue, pLength));
		return szValue;
	}

	NAChar * ToNewStringA(NInt startIndex, NInt length, NInt * pLength = NULL) const
	{
		NAChar * szValue;
		NCheck(NStringToNewStringRangeA(GetHandle(), startIndex, length, &szValue, pLength));
		return szValue;
	}

#ifndef N_NO_UNICODE
	NWChar * ToNewStringW(NInt startIndex, NInt length, NInt * pLength = NULL) const
	{
		NWChar * szValue;
		NCheck(NStringToNewStringRangeW(GetHandle(), startIndex, length, &szValue, pLength));
		return szValue;
	}
#endif

	NChar * ToCharArray(NInt startIndex, NInt length, NInt * pLength = NULL) const
	{
		NChar * arValue;
		NCheck(NStringToCharArrayRange(GetHandle(), startIndex, length, &arValue, pLength));
		return arValue;
	}

	NAChar * ToCharArrayA(NInt startIndex, NInt length, NInt * pLength = NULL) const
	{
		NAChar * arValue;
		NCheck(NStringToCharArrayRangeA(GetHandle(), startIndex, length, &arValue, pLength));
		return arValue;
	}

#ifndef N_NO_UNICODE
	NWChar * ToCharArrayW(NInt startIndex, NInt length, NInt * pLength = NULL) const
	{
		NWChar * arValue;
		NCheck(NStringToCharArrayRangeW(GetHandle(), startIndex, length, &arValue, pLength));
		return arValue;
	}
#endif

	NString Insert(NInt index, const NString & value) const
	{
		HNString hResult;
		NCheck(NStringInsertN(GetHandle(), index, value.GetHandle(), &hResult));
		return NString(hResult, true);
	}

	NString InsertA(NInt index, const NString & value) const
	{
		HNString hResult;
		NCheck(NStringInsertNA(GetHandle(), index, value.GetHandle(), &hResult));
		return NString(hResult, true);
	}

#ifndef N_NO_UNICODE
	NString InsertW(NInt index, const NString & value) const
	{
		HNString hResult;
		NCheck(NStringInsertNW(GetHandle(), index, value.GetHandle(), &hResult));
		return NString(hResult, true);
	}
#endif

	NString Insert(NInt index, const NAChar * arValue, NInt valueLength = -1) const
	{
		HNString hResult;
		NCheck(NStringInsertStrOrCharsA(GetHandle(), index, arValue, valueLength, &hResult));
		return NString(hResult, true);
	}

#ifndef N_NO_UNICODE
	NString Insert(NInt index, const NWChar * arValue, NInt valueLength = -1) const
	{
		HNString hResult;
		NCheck(NStringInsertStrOrCharsW(GetHandle(), index, arValue, valueLength, &hResult));
		return NString(hResult, true);
	}
#endif

	NString Remove(NInt startIndex, NInt count) const
	{
		HNString hResult;
		NCheck(NStringRemove(GetHandle(), startIndex, count, &hResult));
		return NString(hResult, true);
	}

	NString RemoveA(NInt startIndex, NInt count) const
	{
		HNString hResult;
		NCheck(NStringRemoveA(GetHandle(), startIndex, count, &hResult));
		return NString(hResult, true);
	}

#ifndef N_NO_UNICODE
	NString RemoveW(NInt startIndex, NInt count) const
	{
		HNString hResult;
		NCheck(NStringRemoveW(GetHandle(), startIndex, count, &hResult));
		return NString(hResult, true);
	}
#endif

	NString Remove(NInt startIndex) const
	{
		HNString hResult;
		NCheck(NStringRemoveFrom(GetHandle(), startIndex, &hResult));
		return NString(hResult, true);
	}

	NString RemoveA(NInt startIndex) const
	{
		HNString hResult;
		NCheck(NStringRemoveFromA(GetHandle(), startIndex, &hResult));
		return NString(hResult, true);
	}

#ifndef N_NO_UNICODE
	NString RemoveW(NInt startIndex) const
	{
		HNString hResult;
		NCheck(NStringRemoveFromW(GetHandle(), startIndex, &hResult));
		return NString(hResult, true);
	}
#endif

	NString Substring(NInt startIndex, NInt count) const
	{
		HNString hResult;
		NCheck(NStringSubstring(GetHandle(), startIndex, count, &hResult));
		return NString(hResult, true);
	}

	NString SubstringA(NInt startIndex, NInt count) const
	{
		HNString hResult;
		NCheck(NStringSubstringA(GetHandle(), startIndex, count, &hResult));
		return NString(hResult, true);
	}

#ifndef N_NO_UNICODE
	NString SubstringW(NInt startIndex, NInt count) const
	{
		HNString hResult;
		NCheck(NStringSubstringW(GetHandle(), startIndex, count, &hResult));
		return NString(hResult, true);
	}
#endif

	NString Substring(NInt startIndex) const
	{
		HNString hResult;
		NCheck(NStringSubstringFrom(GetHandle(), startIndex, &hResult));
		return NString(hResult, true);
	}

	NString SubstringA(NInt startIndex) const
	{
		HNString hResult;
		NCheck(NStringSubstringFromA(GetHandle(), startIndex, &hResult));
		return NString(hResult, true);
	}

#ifndef N_NO_UNICODE
	NString SubstringW(NInt startIndex) const
	{
		HNString hResult;
		NCheck(NStringSubstringFromW(GetHandle(), startIndex, &hResult));
		return NString(hResult, true);
	}
#endif

	NString Trim() const
	{
		HNString hResult;
		NCheck(NStringTrim(GetHandle(), &hResult));
		return NString(hResult, true);
	}

	NString TrimStart() const
	{
		HNString hResult;
		NCheck(NStringTrimStart(GetHandle(), &hResult));
		return NString(hResult, true);
	}

	NString TrimEnd() const
	{
		HNString hResult;
		NCheck(NStringTrimEnd(GetHandle(), &hResult));
		return NString(hResult, true);
	}

	NString Trim(const NAChar * arChars, NInt charCount) const
	{
		HNString hResult;
		NCheck(NStringTrimAnyA(GetHandle(), arChars, charCount, &hResult));
		return NString(hResult, true);
	}

#ifndef N_NO_UNICODE
	NString Trim(const NWChar * arChars, NInt charCount) const
	{
		HNString hResult;
		NCheck(NStringTrimAnyW(GetHandle(), arChars, charCount, &hResult));
		return NString(hResult, true);
	}
#endif

	NString TrimStart(const NAChar * arChars, NInt charCount) const
	{
		HNString hResult;
		NCheck(NStringTrimStartAnyA(GetHandle(), arChars, charCount, &hResult));
		return NString(hResult, true);
	}

#ifndef N_NO_UNICODE
	NString TrimStart(const NWChar * arChars, NInt charCount) const
	{
		HNString hResult;
		NCheck(NStringTrimStartAnyW(GetHandle(), arChars, charCount, &hResult));
		return NString(hResult, true);
	}
#endif

	NString TrimEnd(const NAChar * arChars, NInt charCount) const
	{
		HNString hResult;
		NCheck(NStringTrimEndAnyA(GetHandle(), arChars, charCount, &hResult));
		return NString(hResult, true);
	}

#ifndef N_NO_UNICODE
	NString TrimEnd(const NWChar * arChars, NInt charCount) const
	{
		HNString hResult;
		NCheck(NStringTrimEndAnyW(GetHandle(), arChars, charCount, &hResult));
		return NString(hResult, true);
	}
#endif

	NString PadLeft(NInt totalWidth) const
	{
		HNString hResult;
		NCheck(NStringPadLeft(GetHandle(), totalWidth, &hResult));
		return NString(hResult, true);
	}

	NString PadLeftA(NInt totalWidth) const
	{
		HNString hResult;
		NCheck(NStringPadLeftA(GetHandle(), totalWidth, &hResult));
		return NString(hResult, true);
	}

#ifndef N_NO_UNICODE
	NString PadLeftW(NInt totalWidth) const
	{
		HNString hResult;
		NCheck(NStringPadLeftW(GetHandle(), totalWidth, &hResult));
		return NString(hResult, true);
	}
#endif

	NString PadRight(NInt totalWidth) const
	{
		HNString hResult;
		NCheck(NStringPadRightA(GetHandle(), totalWidth, &hResult));
		return NString(hResult, true);
	}

	NString PadRightA(NInt totalWidth) const
	{
		HNString hResult;
		NCheck(NStringPadRightA(GetHandle(), totalWidth, &hResult));
		return NString(hResult, true);
	}

#ifndef N_NO_UNICODE
	NString PadRightW(NInt totalWidth) const
	{
		HNString hResult;
		NCheck(NStringPadRightW(GetHandle(), totalWidth, &hResult));
		return NString(hResult, true);
	}
#endif

	NString PadLeft(NInt totalWidth, NAChar paddingChar) const
	{
		HNString hResult;
		NCheck(NStringPadLeftWithA(GetHandle(), totalWidth, paddingChar, &hResult));
		return NString(hResult, true);
	}

#ifndef N_NO_UNICODE
	NString PadLeft(NInt totalWidth, NWChar paddingChar) const
	{
		HNString hResult;
		NCheck(NStringPadLeftWithW(GetHandle(), totalWidth, paddingChar, &hResult));
		return NString(hResult, true);
	}
#endif

	NString PadRight(NInt totalWidth, NAChar paddingChar) const
	{
		HNString hResult;
		NCheck(NStringPadRightWithA(GetHandle(), totalWidth, paddingChar, &hResult));
		return NString(hResult, true);
	}

#ifndef N_NO_UNICODE
	NString PadRight(NInt totalWidth, NWChar paddingChar) const
	{
		HNString hResult;
		NCheck(NStringPadRightWithW(GetHandle(), totalWidth, paddingChar, &hResult));
		return NString(hResult, true);
	}
#endif

	NString Replace(NAChar oldChar, NAChar newChar) const
	{
		HNString hResult;
		NCheck(NStringReplaceA(GetHandle(), oldChar, newChar, &hResult));
		return NString(hResult, true);
	}

#ifndef N_NO_UNICODE
	NString Replace(NWChar oldChar, NWChar newChar) const
	{
		HNString hResult;
		NCheck(NStringReplaceW(GetHandle(), oldChar, newChar, &hResult));
		return NString(hResult, true);
	}
#endif

	NString Replace(const NString & oldValue, const NString & newValue) const
	{
		HNString hResult;
		NCheck(NStringReplaceStrN(GetHandle(), oldValue.GetHandle(), newValue.GetHandle(), &hResult));
		return NString(hResult, true);
	}

	NString Replace(const NAChar * szOldValue, const NAChar * szNewValue) const
	{
		HNString hResult;
		NCheck(NStringReplaceStrA(GetHandle(), szOldValue, szNewValue, &hResult));
		return NString(hResult, true);
	}

#ifndef N_NO_UNICODE
	NString Replace(const NWChar * szOldValue, const NWChar * szNewValue) const
	{
		HNString hResult;
		NCheck(NStringReplaceStrW(GetHandle(), szOldValue, szNewValue, &hResult));
		return NString(hResult, true);
	}
#endif

	NString Replace(const NAChar * arOldValue, NInt oldValueLength, const NAChar * arNewValue, NInt newValueLength) const
	{
		HNString hResult;
		NCheck(NStringReplaceCharsA(GetHandle(), arOldValue, oldValueLength, arNewValue, newValueLength, &hResult));
		return NString(hResult, true);
	}

#ifndef N_NO_UNICODE
	NString Replace(const NWChar * arOldValue, NInt oldValueLength, const NWChar * arNewValue, NInt newValueLength) const
	{
		HNString hResult;
		NCheck(NStringReplaceCharsW(GetHandle(), arOldValue, oldValueLength, arNewValue, newValueLength, &hResult));
		return NString(hResult, true);
	}
#endif

	NString ToUpper() const
	{
		HNString hResult;
		NCheck(NStringToUpper(GetHandle(), &hResult));
		return NString(hResult, true);
	}

	NString ToLower() const
	{
		HNString hResult;
		NCheck(NStringToLower(GetHandle(), &hResult));
		return NString(hResult, true);
	}

	NString Prepend(const NAChar * arValue, NInt valueLength = -1) const
	{
		HNString hResult;
		NCheck(NStringPrependStrOrCharsA(GetHandle(), arValue, valueLength, &hResult));
		return NString(hResult, true);
	}

#ifndef N_NO_UNICODE
	NString Prepend(const NWChar * arValue, NInt valueLength = -1) const
	{
		HNString hResult;
		NCheck(NStringPrependStrOrCharsW(GetHandle(), arValue, valueLength, &hResult));
		return NString(hResult, true);
	}
#endif

	NString Append(const NAChar * arValue, NInt valueLength = -1) const
	{
		HNString hResult;
		NCheck(NStringAppendStrOrCharsA(GetHandle(), arValue, valueLength, &hResult));
		return NString(hResult, true);
	}

#ifndef N_NO_UNICODE
	NString Append(const NWChar * arValue, NInt valueLength = -1) const
	{
		HNString hResult;
		NCheck(NStringAppendStrOrCharsW(GetHandle(), arValue, valueLength, &hResult));
		return NString(hResult, true);
	}
#endif

	NString & operator=(const NString & other)
	{
		return this->operator=(other.handle);
	}

	NString & operator=(HNString hOtherValue)
	{
		if (handle != hOtherValue)
		{
			HNString hValue = NULL;
			if (hOtherValue)
			{
				NCheck(NStringClone(hOtherValue, &hValue));
			}
			Set(hValue);
		}
		return *this;
	}

	NString & operator=(const NAChar * szValue)
	{
		HNString hValue;
		NCheck(NStringCreateA(szValue, &hValue));
		Set(hValue);
		return *this;
	}

#ifndef N_NO_UNICODE
	NString & operator=(const NWChar * szValue)
	{
		HNString hValue;
		NCheck(NStringCreateW(szValue, &hValue));
		Set(hValue);
		return *this;
	}
#endif

	NChar operator[](NInt index) const
	{
		return GetChar(index);
	}

#ifdef N_FRAMEWORK_NATIVE
	operator std::string() const
	{
		const NAChar * szValue;
		NInt length;
		NCheck(NStringGetBufferA(handle, &length, &szValue));
		return std::string(szValue, length);
	}

#ifndef N_NO_UNICODE
	operator std::wstring() const
	{
		const NWChar * szValue;
		NInt length;
		NCheck(NStringGetBufferW(handle, &length, &szValue));
		return std::wstring(szValue, length);
	}
#endif
#endif

#ifdef N_FRAMEWORK_MFC
	operator CStringA() const
	{
		const NAChar * szValue;
		NInt length;
		NCheck(NStringGetBufferA(handle, &length, &szValue));
		return CStringA(szValue, length);
	}

	operator CStringW() const
	{
		const NWChar * szValue;
		NInt length;
		NCheck(NStringGetBufferW(handle, &length, &szValue));
		return CStringW(szValue, length);
	}
#endif

#ifdef N_FRAMEWORK_WX
	operator wxString() const
	{
	#if wxUSE_UNICODE == 1 && defined(N_NO_UNICODE)
		const NAChar * szValue;
		NInt length;
		NCheck(NStringGetBufferA(handle, &length, &szValue));
		return wxString(szValue, wxConvLibc, length);
	#else
		const NChar * szValue;
		NInt length;
		NCheck(NStringGetBuffer(handle, &length, &szValue));
		return wxString(szValue, length);
	#endif
	}
#endif

#ifdef N_FRAMEWORK_QT
	operator QString() const
	{
	#ifndef N_NO_UNICODE
		const NWChar * szValue;
		NInt length;
		NCheck(NStringGetBufferW(handle, &length, &szValue));
		#if N_WCHAR_SIZE == 2
			return QString::fromUtf16(reinterpret_cast<const ushort *>(szValue), length);
		#else
			return QString::fromUcs4(reinterpret_cast<const ushort *>(szValue), length);
		#endif
	#else
		const NAChar * szValue;
		NInt length;
		NCheck(NStringGetBufferA(handle, &length, &szValue));
		return QString::fromLocal8Bit(szValue, length);
	#endif
	}
#endif
};

inline bool operator==(const NString & value1, const NString & value2)
{
	return NString::Equals(value1, value2);
}

inline bool operator!=(const NString & value1, const NString & value2)
{
	return !NString::Equals(value1, value2);
}

inline bool operator==(const NString & value1, const NAChar * szValue2)
{
	return value1.Equals(szValue2);
}

inline bool operator!=(const NString & value1, const NAChar * szValue2)
{
	return !value1.Equals(szValue2);
}

#ifndef N_NO_UNICODE
inline bool operator==(const NString & value1, const NWChar * szValue2)
{
	return value1.Equals(szValue2);
}

inline bool operator!=(const NString & value1, const NWChar * szValue2)
{
	return !value1.Equals(szValue2);
}
#endif

inline bool operator==(const NAChar * szValue1, const NString & value2)
{
	return value2.Equals(szValue1);
}

inline bool operator!=(const NAChar * szValue1, const NString & value2)
{
	return !value2.Equals(szValue1);
}

#ifndef N_NO_UNICODE
inline bool operator==(const NWChar * szValue1, const NString & value2)
{
	return value2.Equals(szValue1);
}

inline bool operator!=(const NWChar * szValue1, const NString & value2)
{
	return !value2.Equals(szValue1);
}
#endif

inline NString operator +(const NString & value1, const NString & value2)
{
	return NString::Concat(value1, value2);
}

inline NString operator +(const NString & value1, const NAChar * szValue2)
{
	return value1.Append(szValue2);
}

#ifndef N_NO_UNICODE
inline NString operator +(const NString & value1, const NWChar * szValue2)
{
	return value1.Append(szValue2);
}
#endif

inline NString operator +(const NAChar * szValue1, const NString & value2)
{
	return value2.Prepend(szValue1);
}

#ifndef N_NO_UNICODE
inline NString operator +(const NWChar * szValue1, const NString & value2)
{
	return value2.Prepend(szValue1);
}
#endif

class NStringWrapper
{
private:
	NStringHeader header;
	HNString handle;
	bool ownsHandle;

	NStringWrapper(const NStringWrapper &);
	NStringWrapper & operator=(const NStringWrapper &);

public:
	NStringWrapper(const NAChar * szValue, NInt length = -1)
		: header(), handle(NULL), ownsHandle(true)
	{
		NCheck(NStringCreateWrapperA(szValue, length, &header, &handle));
	}

#ifndef N_NO_UNICODE
	NStringWrapper(const NWChar * szValue, NInt length = -1)
		: header(), handle(NULL), ownsHandle(true)
	{
		NCheck(NStringCreateWrapperW(szValue, length, &header, &handle));
	}
#endif

	NStringWrapper(HNString hValue)
		: header(), handle(hValue), ownsHandle(false)
	{
	}

	NStringWrapper(const NString & value)
		: header(), handle(value.GetHandle()), ownsHandle(false)
	{
	}

	NStringWrapper(::Neurotec::Text::NStringBuilder & value);

#ifdef N_FRAMEWORK_NATIVE
	NStringWrapper(const std::string & value)
		: header(), handle(NULL), ownsHandle(true)
	{
		NCheck(NStringCreateWrapperA(value.c_str(), (NInt)value.size(), &header, &handle));
	}

#ifndef N_NO_UNICODE
	NStringWrapper(const std::wstring & value)
		: header(), handle(NULL), ownsHandle(true)
	{
		NCheck(NStringCreateWrapperW(value.c_str(), (NInt)value.size(), &header, &handle));
	}
#endif
#endif

#ifdef N_FRAMEWORK_MFC
	NStringWrapper(const CStringA & value)
		: header(), handle(NULL), ownsHandle(true)
	{
		NCheck(NStringCreateWrapperA(value.GetString(), value.GetLength(), &header, &handle));
	}

	NStringWrapper(const CStringW & value)
		: header(), handle(NULL), ownsHandle(true)
	{
		NCheck(NStringCreateWrapperW(value.GetString(), value.GetLength(), &header, &handle));
	}
#endif

#ifdef N_FRAMEWORK_WX
	#if wxUSE_UNICODE == 1 && defined(N_NO_UNICODE)
		NStringWrapper(const wxChar * szValue, NInt length = -1)
			: header(), handle(NULL), ownsHandle(true)
		{
			NCheck(NEncodingGetStringN(::Neurotec::Text::N_WCHAR_ENCODING, szValue, length == -1 ? N_SIZE_TYPE_MAX : length * sizeof(wxChar), &handle));
		}
	#endif

	NStringWrapper(const wxString & value)
		: header(), handle(NULL), ownsHandle(true)
	{
	#if wxUSE_UNICODE == 1 && defined(N_NO_UNICODE)
		NCheck(NEncodingGetStringN(Neurotec::Text::N_WCHAR_ENCODING, (const wxChar *)value.c_str(), value.Length() * sizeof(wxChar), &handle));
	#else
		NCheck(NStringCreateWrapper((const wxChar *)value.c_str(), (NInt)value.Length(), &header, &handle));
	#endif
	}
#endif

#ifdef N_FRAMEWORK_QT
	NStringWrapper(const QString & value)
		: header(), handle(NULL), ownsHandle(true)
	{
	#if !defined(N_NO_UNICODE) && N_WCHAR_SIZE == 2
		NCheck(NStringCreateWrapperW(reinterpret_cast<const NWChar *>(value.constData()), value.length(), &header, &handle));
	#else
		NCheck(::Neurotec::Text::NEncodingGetStringN(
		#ifdef N_BIG_ENDIAN
			::Neurotec::Text::neUtf16BE,
		#else
			::Neurotec::Text::neUtf16LE,
		#endif
			value.constData(), value.length() * 2, &handle));
	#endif
	}
#endif

	~NStringWrapper()
	{
		if (ownsHandle)
			NStringFree(handle);
	}

	HNString GetHandle() const
	{
		return handle;
	}

	NString GetString() const
	{
		return NString(handle, false);
	}

	operator NString() const
	{
		return GetString();
	}
};

}

#endif // !N_STRING_HPP_INCLUDED
