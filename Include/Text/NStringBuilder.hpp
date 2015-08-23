#ifndef N_STRING_BUILDER_HPP_INCLUDED
#define N_STRING_BUILDER_HPP_INCLUDED

#include <Core/NTypes.hpp>
#include <Core/NString.hpp>
namespace Neurotec {
	namespace Text {
		namespace Internal
{
#include <Text/NStringBuilder.h>
}}}

namespace Neurotec { namespace Text
{

class NStringBuilder : private Internal::NStringBuilder
{
public:
	NStringBuilder()
	{
		NCheck(Internal::NStringBuilderInit(this));
	}

	NStringBuilder(NInt capacity)
	{
		NCheck(Internal::NStringBuilderInitWithCapacity(this, capacity));
	}

	NStringBuilder(NInt capacity, NInt maxCapacity, NInt growthDelta)
	{
		NCheck(Internal::NStringBuilderInitEx(this, capacity, maxCapacity, growthDelta));
	}

	NStringBuilder(const NString & value)
	{
		NCheck(Internal::NStringBuilderInitWithStringN(this, value.GetHandle()));
	}

	NStringBuilder(const NStringWrapper & value)
	{
		NCheck(Internal::NStringBuilderInitWithStringN(this, value.GetHandle()));
	}

	NStringBuilder(const NChar * arValue, NInt valueLength = -1)
	{
		NCheck(Internal::NStringBuilderInitWithStrOrChars(this, arValue, valueLength));
	}

	~NStringBuilder()
	{
		NCheck(Internal::NStringBuilderDispose(this));
	}

	NInt GetCapacity()
	{
		NInt value;
		NCheck(Internal::NStringBuilderGetCapacity(this, &value));
		return value;
	}

	void SetCapacity(NInt value)
	{
		NCheck(Internal::NStringBuilderSetCapacity(this, value));
	}

	NInt GetLength()
	{
		NInt value;
		NCheck(Internal::NStringBuilderGetLength(this, &value));
		return value;
	}

	void SetLength(NInt value)
	{
		NCheck(Internal::NStringBuilderSetLength(this, value));
	}

	NChar GetChar(NInt index)
	{
		NChar value;
		NCheck(Internal::NStringBuilderGetChar(this, index, &value));
		return value;
	}

	void SetChar(NInt index, NChar value)
	{
		NCheck(Internal::NStringBuilderSetChar(this, index, value));
	}

	NStringBuilder & Append(bool value)
	{
		NCheck(Internal::NStringBuilderAppendBoolean(this, value ? NTrue : NFalse));
		return *this;
	}

	NStringBuilder & Append(NFloat value)
	{
		NCheck(Internal::NStringBuilderAppendSingle(this, value));
		return *this;
	}

	NStringBuilder & Append(NDouble value)
	{
		NCheck(Internal::NStringBuilderAppendDouble(this, value));
		return *this;
	}

	NStringBuilder & Append(NSByte value)
	{
		NCheck(Internal::NStringBuilderAppendSByte(this, value));
		return *this;
	}

	NStringBuilder & Append(NShort value)
	{
		NCheck(Internal::NStringBuilderAppendInt16(this, value));
		return *this;
	}

	NStringBuilder & Append(NInt value)
	{
		NCheck(Internal::NStringBuilderAppendInt32(this, value));
		return *this;
	}

	NStringBuilder & Append(NLong value)
	{
		NCheck(Internal::NStringBuilderAppendInt64(this, value));
		return *this;
	}

	NStringBuilder & Append(NByte value)
	{
		NCheck(Internal::NStringBuilderAppendByte(this, value));
		return *this;
	}

	NStringBuilder & Append(NUShort value)
	{
		NCheck(Internal::NStringBuilderAppendUInt16(this, value));
		return *this;
	}

	NStringBuilder & Append(NUInt value)
	{
		NCheck(Internal::NStringBuilderAppendUInt32(this, value));
		return *this;
	}

	NStringBuilder & Append(NULong value)
	{
		NCheck(Internal::NStringBuilderAppendUInt64(this, value));
		return *this;
	}

	NStringBuilder & AppendSizeType(NSizeType value)
	{
		NCheck(Internal::NStringBuilderAppendSizeType(this, value));
		return *this;
	}

	NStringBuilder & AppendSSizeType(NSSizeType value)
	{
		NCheck(Internal::NStringBuilderAppendSSizeType(this, value));
		return *this;
	}

	NStringBuilder & Append(const void * value)
	{
		NCheck(Internal::NStringBuilderAppendPointer(this, value));
		return *this;
	}

	NStringBuilder & AppendResult(NResult value)
	{
		NCheck(Internal::NStringBuilderAppendResult(this, value));
		return *this;
	}

	NStringBuilder & Append(NType & type, const void * pValue, NSizeType valueSize)
	{
		NCheck(Internal::NStringBuilderAppendValue(this, type.GetHandle(), pValue, valueSize));
		return *this;
	}

	NStringBuilder & Append(NObject & object)
	{
		NCheck(Internal::NStringBuilderAppendObject(this, object.GetHandle()));
		return *this;
	}

	NStringBuilder & AppendChar(NChar value)
	{
		NCheck(Internal::NStringBuilderAppendChar(this, value));
		return *this;
	}

	NStringBuilder & AppendChar(NChar value, NInt repeatCount)
	{
		NCheck(Internal::NStringBuilderAppendCharRepeat(this, value, repeatCount));
		return *this;
	}

	NStringBuilder & Append(const NChar * arValue, NInt valueLength)
	{
		NCheck(Internal::NStringBuilderAppendChars(this, arValue, valueLength));
		return *this;
	}

	NStringBuilder & Append(const NString & value)
	{
		NCheck(Internal::NStringBuilderAppendN(this, value.GetHandle()));
		return *this;
	}

	NStringBuilder & Append(const NStringWrapper & value)
	{
		NCheck(Internal::NStringBuilderAppendN(this, value.GetHandle()));
		return *this;
	}

	NStringBuilder & Append(const NChar * szValue)
	{
		NCheck(Internal::NStringBuilderAppend(this, szValue));
		return *this;
	}

	NStringBuilder & AppendFormat(const NChar * szFormat, ...)
	{
		va_list args;
		va_start(args, szFormat);
		try
		{
			AppendFormat(szFormat, args);
			va_end(args);
			return *this;
		}
		catch (...)
		{
			va_end(args);
			throw;
		}
	}

	NStringBuilder & AppendFormat(const NString & value, va_list args)
	{
		NCheck(Internal::NStringBuilderAppendFormatVAN(this, value.GetHandle(), args));
		return *this;
	}

	NStringBuilder & AppendFormat(const NStringWrapper & value, va_list args)
	{
		NCheck(Internal::NStringBuilderAppendFormatVAN(this, value.GetHandle(), args));
		return *this;
	}

	NStringBuilder & AppendFormat(const NChar * szValue, va_list args)
	{
		NCheck(Internal::NStringBuilderAppendFormatVA(this, szValue, args));
		return *this;
	}

	NStringBuilder & AppendLine()
	{
		NCheck(Internal::NStringBuilderAppendEmptyLine(this));
		return *this;
	}

	NStringBuilder & AppendLine(const NString & value)
	{
		NCheck(Internal::NStringBuilderAppendLineN(this, value.GetHandle()));
		return *this;
	}

	NStringBuilder & AppendLine(const NStringWrapper & value)
	{
		NCheck(Internal::NStringBuilderAppendLineN(this, value.GetHandle()));
		return *this;
	}

	NStringBuilder & AppendLine(const NChar * szValue)
	{
		NCheck(Internal::NStringBuilderAppendLine(this, szValue));
		return *this;
	}

	NStringBuilder & Insert(NInt index, bool value)
	{
		NCheck(Internal::NStringBuilderInsertBoolean(this, index, value ? NTrue : NFalse));
		return *this;
	}

	NStringBuilder & Insert(NInt index, NFloat value)
	{
		NCheck(Internal::NStringBuilderInsertSingle(this, index, value));
		return *this;
	}

	NStringBuilder & Insert(NInt index, NDouble value)
	{
		NCheck(Internal::NStringBuilderInsertDouble(this, index, value));
		return *this;
	}

	NStringBuilder & Insert(NInt index, NSByte value)
	{
		NCheck(Internal::NStringBuilderInsertSByte(this, index, value));
		return *this;
	}

	NStringBuilder & Insert(NInt index, NShort value)
	{
		NCheck(Internal::NStringBuilderInsertInt16(this, index, value));
		return *this;
	}

	NStringBuilder & Insert(NInt index, NInt value)
	{
		NCheck(Internal::NStringBuilderInsertInt32(this, index, value));
		return *this;
	}

	NStringBuilder & Insert(NInt index, NLong value)
	{
		NCheck(Internal::NStringBuilderInsertInt64(this, index, value));
		return *this;
	}

	NStringBuilder & Insert(NInt index, NByte value)
	{
		NCheck(Internal::NStringBuilderInsertByte(this, index, value));
		return *this;
	}

	NStringBuilder & Insert(NInt index, NUShort value)
	{
		NCheck(Internal::NStringBuilderInsertUInt16(this, index, value));
		return *this;
	}

	NStringBuilder & Insert(NInt index, NUInt value)
	{
		NCheck(Internal::NStringBuilderInsertUInt32(this, index, value));
		return *this;
	}

	NStringBuilder & Insert(NInt index, NULong value)
	{
		NCheck(Internal::NStringBuilderInsertUInt64(this, index, value));
		return *this;
	}

	NStringBuilder & InsertSizeType(NInt index, NSizeType value)
	{
		NCheck(Internal::NStringBuilderInsertSizeType(this, index, value));
		return *this;
	}

	NStringBuilder & InsertSSizeType(NInt index, NSSizeType value)
	{
		NCheck(Internal::NStringBuilderInsertSSizeType(this, index, value));
		return *this;
	}

	NStringBuilder & Insert(NInt index, const void * value)
	{
		NCheck(Internal::NStringBuilderInsertPointer(this, index, value));
		return *this;
	}

	NStringBuilder & InsertResult(NInt index, NResult value)
	{
		NCheck(Internal::NStringBuilderInsertResult(this, index, value));
		return *this;
	}

	NStringBuilder & Insert(NInt index, NType & type, const void * pValue, NSizeType valueSize)
	{
		NCheck(Internal::NStringBuilderInsertValue(this, index, type.GetHandle(), pValue, valueSize));
		return *this;
	}

	NStringBuilder & Insert(NInt index, NObject & object)
	{
		NCheck(Internal::NStringBuilderInsertObject(this, index, object.GetHandle()));
		return *this;
	}

	NStringBuilder & InsertChar(NInt index, NChar value)
	{
		NCheck(Internal::NStringBuilderInsertChar(this, index, value));
		return *this;
	}

	NStringBuilder & Insert(NInt index, const NChar * arValue, NInt valueLength)
	{
		NCheck(Internal::NStringBuilderInsertChars(this, index, arValue, valueLength));
		return *this;
	}

	NStringBuilder & Insert(NInt index, const NString & value)
	{
		NCheck(Internal::NStringBuilderInsertN(this, index, value.GetHandle()));
		return *this;
	}

	NStringBuilder & Insert(NInt index, const NStringWrapper & value)
	{
		NCheck(Internal::NStringBuilderInsertN(this, index, value.GetHandle()));
		return *this;
	}

	NStringBuilder & Insert(NInt index, const NChar * szValue)
	{
		NCheck(Internal::NStringBuilderInsert(this, index, szValue));
		return *this;
	}

	NStringBuilder & Clear()
	{
		NCheck(Internal::NStringBuilderClear(this));
		return *this;
	}

	void CopyToStr(NInt sourceIndex, NChar * szValue, NInt valueSize, NInt count)
	{
		NCheck(Internal::NStringBuilderCopyToString(this, sourceIndex, szValue, valueSize, count));
	}

	void CopyTo(NInt sourceIndex, NChar * arValue, NInt valueLength, NInt count)
	{
		NCheck(Internal::NStringBuilderCopyTo(this, sourceIndex, arValue, valueLength, count));
	}

	NStringBuilder & Remove(NInt startIndex, NInt count)
	{
		NCheck(Internal::NStringBuilderRemove(this, startIndex, count));
		return *this;
	}

	NStringBuilder & Replace(NChar oldValue, NChar newValue)
	{
		NCheck(Internal::NStringBuilderReplace(this, oldValue, newValue));
		return *this;
	}

	NStringBuilder & Replace(NChar oldValue, NChar newValue, NInt startIndex, NInt count)
	{
		NCheck(Internal::NStringBuilderReplaceInRange(this, oldValue, newValue, startIndex, count));
		return *this;
	}

	NStringBuilder & Replace(const NString & oldValue, const NString & newValue)
	{
		NCheck(Internal::NStringBuilderReplaceStringN(this, oldValue.GetHandle(), newValue.GetHandle()));
		return *this;
	}

	NStringBuilder & Replace(const NStringWrapper & oldValue, const NStringWrapper & newValue)
	{
		NCheck(Internal::NStringBuilderReplaceStringN(this, oldValue.GetHandle(), newValue.GetHandle()));
		return *this;
	}

	NStringBuilder & Replace(const NChar * szOldValue, const NChar * szNewValue)
	{
		NCheck(Internal::NStringBuilderReplaceString(this, szOldValue, szNewValue));
		return *this;
	}

	NStringBuilder & Replace(const NChar * arOldValue, NInt oldValueLength, const NChar * arNewValue, NInt newValueLength)
	{
		NCheck(Internal::NStringBuilderReplaceChars(this, arOldValue, oldValueLength, arNewValue, newValueLength));
		return *this;
	}

	NStringBuilder & Replace(const NString & oldValue, const NString & newValue, NInt startIndex, NInt count)
	{
		NCheck(Internal::NStringBuilderReplaceStringInRangeN(this, oldValue.GetHandle(), newValue.GetHandle(), startIndex, count));
		return *this;
	}

	NStringBuilder & Replace(const NStringWrapper & oldValue, const NStringWrapper & newValue, NInt startIndex, NInt count)
	{
		NCheck(Internal::NStringBuilderReplaceStringInRangeN(this, oldValue.GetHandle(), newValue.GetHandle(), startIndex, count));
		return *this;
	}

	NStringBuilder & Replace(const NChar * szOldValue, const NChar * szNewValue, NInt startIndex, NInt count)
	{
		NCheck(Internal::NStringBuilderReplaceStringInRange(this, szOldValue, szNewValue, startIndex, count));
		return *this;
	}

	NStringBuilder & Replace(const NChar * arOldValue, NInt oldValueLength, const NChar * arNewValue, NInt newValueLength, NInt startIndex, NInt count)
	{
		NCheck(Internal::NStringBuilderReplaceCharsInRange(this, arOldValue, oldValueLength, arNewValue, newValueLength, startIndex, count));
		return *this;
	}

	NString ToString(NInt startIndex, NInt length)
	{
		HNString hValue;
		NCheck(Internal::NStringBuilderToStringRange(this, startIndex, length, &hValue));
		return NString(hValue, true);
	}

	NString ToString()
	{
		HNString hValue;
		NCheck(Internal::NStringBuilderToString(this, &hValue));
		return NString(hValue, true);
	}

	NString DetachStringN()
	{
		HNString hValue;
		NCheck(Internal::NStringBuilderDetachStringN(this, &hValue));
		return NString(hValue, true);
	}

	NChar * GetBuffer(NInt * pLength = NULL)
	{
		NChar * szValue;
		NCheck(Internal::NStringBuilderGetBuffer(this, pLength, &szValue));
		return szValue;
	}

	NChar * GetCharsBuffer(NInt * pLength)
	{
		NChar * arValue;
		NCheck(Internal::NStringBuilderGetCharsBuffer(this, pLength, &arValue));
		return arValue;
	}

	NChar * DetachString(NInt * pLength = NULL)
	{
		NChar * szValue;
		NCheck(Internal::NStringBuilderDetachString(this, &szValue, pLength));
		return szValue;
	}

	NChar * DetachCharArray(NInt * pLength)
	{
		NChar * arValue;
		NCheck(Internal::NStringBuilderDetachCharArray(this, &arValue, pLength));
		return arValue;
	}

	NChar operator[](NInt index)
	{
		return GetChar(index);
	}

	friend class ::Neurotec::NStringWrapper;
};

}}

namespace Neurotec
{

inline NStringWrapper::NStringWrapper(::Neurotec::Text::NStringBuilder & value)
	: header(), handle(NULL), ownsHandle(true)
{
	NCheck(::Neurotec::Text::Internal::NStringBuilderGetStringWrapper(&value, &header, &handle));
}

}

#endif // !N_STRING_BUILDER_HPP_INCLUDED
