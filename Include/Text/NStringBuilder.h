#ifndef N_STRING_BUILDER_H_INCLUDED
#define N_STRING_BUILDER_H_INCLUDED

#include <Core/NTypes.h>
#include <Core/NString.h>

#ifdef N_CPP
extern "C"
{
#endif

#ifdef N_64
	#define N_STRING_BUILDER_SIZE 24
#else
	#define N_STRING_BUILDER_SIZE 20
#endif

N_DECLATE_PRIMITIVE(NStringBuilderA, N_STRING_BUILDER_SIZE)
N_DECLARE_TYPE(NStringBuilderA)
#ifndef N_NO_UNICODE
N_DECLATE_PRIMITIVE(NStringBuilderW, N_STRING_BUILDER_SIZE)
N_DECLARE_TYPE(NStringBuilderW)
#endif
#ifdef N_DOCUMENTATION
N_DECLATE_PRIMITIVE(NStringBuilder, N_STRING_BUILDER_SIZE)
#endif
typedef N_TYPE_AW(NStringBuilder) NStringBuilder;
#ifdef N_UNICODE
	#define NStringBuilderTypeOf NStringBuilderWTypeOf
#else
	#define NStringBuilderTypeOf NStringBuilderATypeOf
#endif

NResult N_API NStringBuilderInitA(NStringBuilderA * pStringBuilder);
#ifndef N_NO_UNICODE
NResult N_API NStringBuilderInitW(NStringBuilderW * pStringBuilder);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NStringBuilderInit(NStringBuilder * pStringBuilder);
#endif
#define NStringBuilderInit N_FUNC_AW(NStringBuilderInit)

NResult N_API NStringBuilderInitWithCapacityA(NStringBuilderA * pStringBuilder, NInt capacity);
#ifndef N_NO_UNICODE
NResult N_API NStringBuilderInitWithCapacityW(NStringBuilderW * pStringBuilder, NInt capacity);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NStringBuilderInitWithCapacity(NStringBuilder * pStringBuilder, NInt capacity);
#endif
#define NStringBuilderInitWithCapacity N_FUNC_AW(NStringBuilderInitWithCapacity)

NResult N_API NStringBuilderInitExA(NStringBuilderA * pStringBuilder, NInt capacity, NInt maxCapacity, NInt growthDelta);
#ifndef N_NO_UNICODE
NResult N_API NStringBuilderInitExW(NStringBuilderW * pStringBuilder, NInt capacity, NInt maxCapacity, NInt growthDelta);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NStringBuilderInitEx(NStringBuilder * pStringBuilder, NInt capacity, NInt maxCapacity, NInt growthDelta);
#endif
#define NStringBuilderInitEx N_FUNC_AW(NStringBuilderInitEx)

NResult N_API NStringBuilderInitWithStringNA(NStringBuilderA * pStringBuilder, HNString hString);
#ifndef N_NO_UNICODE
NResult N_API NStringBuilderInitWithStringNW(NStringBuilderW * pStringBuilder, HNString hString);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NStringBuilderInitWithStringN(NStringBuilder * pStringBuilder, HNString hString);
#endif
#define NStringBuilderInitWithStringN N_FUNC_AW(NStringBuilderInitWithStringN)

NResult N_API NStringBuilderInitWithStrOrCharsA(NStringBuilderA * pStringBuilder, const NAChar * arValue, NInt valueLength);
#ifndef N_NO_UNICODE
NResult N_API NStringBuilderInitWithStrOrCharsW(NStringBuilderW * pStringBuilder, const NWChar * arValue, NInt valueLength);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NStringBuilderInitWithStrOrChars(NStringBuilder * pStringBuilder, const NChar * arValue, NInt valueLength);
#endif
#define NStringBuilderInitWithStrOrChars N_FUNC_AW(NStringBuilderInitWithStrOrChars)

#define NStringBuilderInitWithStringA(pStringBuilder, szValue) NStringBuilderInitWithStrOrCharsA(pStringBuilder, szValue, -1)
#define NStringBuilderInitWithStringW(pStringBuilder, szValue) NStringBuilderInitWithStrOrCharsW(pStringBuilder, szValue, -1)
#define NStringBuilderInitWithString(pStringBuilder, szValue) NStringBuilderInitWithStrOrChars(pStringBuilder, szValue, -1)
#define NStringBuilderInitWithCharsA(pStringBuilder, arValue, valueLength) NStringBuilderInitWithStrOrCharsA(pStringBuilder, arValue, valueLength)
#define NStringBuilderInitWithCharsW(pStringBuilder, arValue, valueLength) NStringBuilderInitWithStrOrCharsW(pStringBuilder, arValue, valueLength)
#define NStringBuilderInitWithChars(pStringBuilder, arValue, valueLength) NStringBuilderInitWithStrOrChars(pStringBuilder, arValue, valueLength)

NResult N_API NStringBuilderDisposeA(NStringBuilderA * pStringBuilder);
#ifndef N_NO_UNICODE
NResult N_API NStringBuilderDisposeW(NStringBuilderW * pStringBuilder);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NStringBuilderDispose(NStringBuilder * pStringBuilder);
#endif
#define NStringBuilderDispose N_FUNC_AW(NStringBuilderDispose)

NResult N_API NStringBuilderGetCapacityA(NStringBuilderA * pStringBuilder, NInt * pValue);
#ifndef N_NO_UNICODE
NResult N_API NStringBuilderGetCapacityW(NStringBuilderW * pStringBuilder, NInt * pValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NStringBuilderGetCapacity(NStringBuilder * pStringBuilder, NInt * pValue);
#endif
#define NStringBuilderGetCapacity N_FUNC_AW(NStringBuilderGetCapacity)

NResult N_API NStringBuilderSetCapacityA(NStringBuilderA * pStringBuilder, NInt value);
#ifndef N_NO_UNICODE
NResult N_API NStringBuilderSetCapacityW(NStringBuilderW * pStringBuilder, NInt value);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NStringBuilderSetCapacity(NStringBuilder * pStringBuilder, NInt value);
#endif
#define NStringBuilderSetCapacity N_FUNC_AW(NStringBuilderSetCapacity)

NResult N_API NStringBuilderGetLengthA(NStringBuilderA * pStringBuilder, NInt * pValue);
#ifndef N_NO_UNICODE
NResult N_API NStringBuilderGetLengthW(NStringBuilderW * pStringBuilder, NInt * pValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NStringBuilderGetLength(NStringBuilder * pStringBuilder, NInt * pValue);
#endif
#define NStringBuilderGetLength N_FUNC_AW(NStringBuilderGetLength)

NResult N_API NStringBuilderSetLengthA(NStringBuilderA * pStringBuilder, NInt value);
#ifndef N_NO_UNICODE
NResult N_API NStringBuilderSetLengthW(NStringBuilderW * pStringBuilder, NInt value);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NStringBuilderSetLength(NStringBuilder * pStringBuilder, NInt value);
#endif
#define NStringBuilderSetLength N_FUNC_AW(NStringBuilderSetLength)

NResult N_API NStringBuilderGetCharA(NStringBuilderA * pStringBuilder, NInt index, NAChar * pValue);
#ifndef N_NO_UNICODE
NResult N_API NStringBuilderGetCharW(NStringBuilderW * pStringBuilder, NInt index, NWChar * pValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NStringBuilderGetChar(NStringBuilder * pStringBuilder, NInt index, NChar * pValue);
#endif
#define NStringBuilderGetChar N_FUNC_AW(NStringBuilderGetChar)

NResult N_API NStringBuilderSetCharA(NStringBuilderA * pStringBuilder, NInt index, NAChar value);
#ifndef N_NO_UNICODE
NResult N_API NStringBuilderSetCharW(NStringBuilderW * pStringBuilder, NInt index, NWChar value);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NStringBuilderSetChar(NStringBuilder * pStringBuilder, NInt index, NChar value);
#endif
#define NStringBuilderSetChar N_FUNC_AW(NStringBuilderSetChar)

NResult N_API NStringBuilderAppendBooleanA(NStringBuilderA * pStringBuilder, NBool value);
#ifndef N_NO_UNICODE
NResult N_API NStringBuilderAppendBooleanW(NStringBuilderW * pStringBuilder, NBool value);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NStringBuilderAppendBoolean(NStringBuilder * pStringBuilder, NBool value);
#endif
#define NStringBuilderAppendBoolean N_FUNC_AW(NStringBuilderAppendBoolean)

NResult N_API NStringBuilderAppendSingleA(NStringBuilderA * pStringBuilder, NFloat value);
#ifndef N_NO_UNICODE
NResult N_API NStringBuilderAppendSingleW(NStringBuilderW * pStringBuilder, NFloat value);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NStringBuilderAppendSingle(NStringBuilder * pStringBuilder, NFloat value);
#endif
#define NStringBuilderAppendSingle N_FUNC_AW(NStringBuilderAppendSingle)

NResult N_API NStringBuilderAppendDoubleA(NStringBuilderA * pStringBuilder, NDouble value);
#ifndef N_NO_UNICODE
NResult N_API NStringBuilderAppendDoubleW(NStringBuilderW * pStringBuilder, NDouble value);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NStringBuilderAppendDouble(NStringBuilder * pStringBuilder, NDouble value);
#endif
#define NStringBuilderAppendDouble N_FUNC_AW(NStringBuilderAppendDouble)

NResult N_API NStringBuilderAppendSByteA(NStringBuilderA * pStringBuilder, NSByte value);
#ifndef N_NO_UNICODE
NResult N_API NStringBuilderAppendSByteW(NStringBuilderW * pStringBuilder, NSByte value);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NStringBuilderAppendSByte(NStringBuilder * pStringBuilder, NSByte value);
#endif
#define NStringBuilderAppendSByte N_FUNC_AW(NStringBuilderAppendSByte)

NResult N_API NStringBuilderAppendInt16A(NStringBuilderA * pStringBuilder, NShort value);
#ifndef N_NO_UNICODE
NResult N_API NStringBuilderAppendInt16W(NStringBuilderW * pStringBuilder, NShort value);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NStringBuilderAppendInt16(NStringBuilder * pStringBuilder, NShort value);
#endif
#define NStringBuilderAppendInt16 N_FUNC_AW(NStringBuilderAppendInt16)

NResult N_API NStringBuilderAppendInt32A(NStringBuilderA * pStringBuilder, NInt value);
#ifndef N_NO_UNICODE
NResult N_API NStringBuilderAppendInt32W(NStringBuilderW * pStringBuilder, NInt value);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NStringBuilderAppendInt32(NStringBuilder * pStringBuilder, NInt value);
#endif
#define NStringBuilderAppendInt32 N_FUNC_AW(NStringBuilderAppendInt32)

NResult N_API NStringBuilderAppendInt64A(NStringBuilderA * pStringBuilder, NLong value);
#ifndef N_NO_UNICODE
NResult N_API NStringBuilderAppendInt64W(NStringBuilderW * pStringBuilder, NLong value);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NStringBuilderAppendInt64(NStringBuilder * pStringBuilder, NLong value);
#endif
#define NStringBuilderAppendInt64 N_FUNC_AW(NStringBuilderAppendInt64)

NResult N_API NStringBuilderAppendByteA(NStringBuilderA * pStringBuilder, NByte value);
#ifndef N_NO_UNICODE
NResult N_API NStringBuilderAppendByteW(NStringBuilderW * pStringBuilder, NByte value);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NStringBuilderAppendByte(NStringBuilder * pStringBuilder, NByte value);
#endif
#define NStringBuilderAppendByte N_FUNC_AW(NStringBuilderAppendByte)

NResult N_API NStringBuilderAppendUInt16A(NStringBuilderA * pStringBuilder, NUShort value);
#ifndef N_NO_UNICODE
NResult N_API NStringBuilderAppendUInt16W(NStringBuilderW * pStringBuilder, NUShort value);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NStringBuilderAppendUInt16(NStringBuilder * pStringBuilder, NUShort value);
#endif
#define NStringBuilderAppendUInt16 N_FUNC_AW(NStringBuilderAppendUInt16)

NResult N_API NStringBuilderAppendUInt32A(NStringBuilderA * pStringBuilder, NUInt value);
#ifndef N_NO_UNICODE
NResult N_API NStringBuilderAppendUInt32W(NStringBuilderW * pStringBuilder, NUInt value);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NStringBuilderAppendUInt32(NStringBuilder * pStringBuilder, NUInt value);
#endif
#define NStringBuilderAppendUInt32 N_FUNC_AW(NStringBuilderAppendUInt32)

NResult N_API NStringBuilderAppendUInt64A(NStringBuilderA * pStringBuilder, NULong value);
#ifndef N_NO_UNICODE
NResult N_API NStringBuilderAppendUInt64W(NStringBuilderW * pStringBuilder, NULong value);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NStringBuilderAppendUInt64(NStringBuilder * pStringBuilder, NULong value);
#endif
#define NStringBuilderAppendUInt64 N_FUNC_AW(NStringBuilderAppendUInt64)

NResult N_API NStringBuilderAppendSizeTypeA(NStringBuilderA * pStringBuilder, NSizeType value);
#ifndef N_NO_UNICODE
NResult N_API NStringBuilderAppendSizeTypeW(NStringBuilderW * pStringBuilder, NSizeType value);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NStringBuilderAppendSizeType(NStringBuilder * pStringBuilder, NSizeType value);
#endif
#define NStringBuilderAppendSizeType N_FUNC_AW(NStringBuilderAppendSizeType)

NResult N_API NStringBuilderAppendSSizeTypeA(NStringBuilderA * pStringBuilder, NSSizeType value);
#ifndef N_NO_UNICODE
NResult N_API NStringBuilderAppendSSizeTypeW(NStringBuilderW * pStringBuilder, NSSizeType value);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NStringBuilderAppendSSizeType(NStringBuilder * pStringBuilder, NSSizeType value);
#endif
#define NStringBuilderAppendSSizeType N_FUNC_AW(NStringBuilderAppendSSizeType)

NResult N_API NStringBuilderAppendPointerA(NStringBuilderA * pStringBuilder, const void * value);
#ifndef N_NO_UNICODE
NResult N_API NStringBuilderAppendPointerW(NStringBuilderW * pStringBuilder, const void * value);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NStringBuilderAppendPointer(NStringBuilder * pStringBuilder, const void * value);
#endif
#define NStringBuilderAppendPointer N_FUNC_AW(NStringBuilderAppendPointer)

NResult N_API NStringBuilderAppendResultA(NStringBuilderA * pStringBuilder, NResult value);
#ifndef N_NO_UNICODE
NResult N_API NStringBuilderAppendResultW(NStringBuilderW * pStringBuilder, NResult value);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NStringBuilderAppendResult(NStringBuilder * pStringBuilder, NResult value);
#endif
#define NStringBuilderAppendResult N_FUNC_AW(NStringBuilderAppendResult)

NResult N_API NStringBuilderAppendValueA(NStringBuilderA * pStringBuilder, HNType hType, const void * pValue, NSizeType valueSize);
#ifndef N_NO_UNICODE
NResult N_API NStringBuilderAppendValueW(NStringBuilderW * pStringBuilder, HNType hType, const void * pValue, NSizeType valueSize);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NStringBuilderAppendValue(NStringBuilder * pStringBuilder, HNType hType, const void * pValue, NSizeType valueSize);
#endif
#define NStringBuilderAppendValue N_FUNC_AW(NStringBuilderAppendValue)

NResult N_API NStringBuilderAppendValuePA(NStringBuilderA * pStringBuilder, NTypeOfProc pTypeOf, const void * pValue, NSizeType valueSize);
#ifndef N_NO_UNICODE
NResult N_API NStringBuilderAppendValuePW(NStringBuilderW * pStringBuilder, NTypeOfProc pTypeOf, const void * pValue, NSizeType valueSize);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NStringBuilderAppendValueP(NStringBuilder * pStringBuilder, NTypeOfProc pTypeOf, const void * pValue, NSizeType valueSize);
#endif
#define NStringBuilderAppendValueP N_FUNC_AW(NStringBuilderAppendValueP)

NResult N_API NStringBuilderAppendObjectA(NStringBuilderA * pStringBuilder, HNObject hObject);
#ifndef N_NO_UNICODE
NResult N_API NStringBuilderAppendObjectW(NStringBuilderW * pStringBuilder, HNObject hObject);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NStringBuilderAppendObject(NStringBuilder * pStringBuilder, HNObject hObject);
#endif
#define NStringBuilderAppendObject N_FUNC_AW(NStringBuilderAppendObject)

NResult N_API NStringBuilderAppendCharA(NStringBuilderA * pStringBuilder, NAChar value);
#ifndef N_NO_UNICODE
NResult N_API NStringBuilderAppendCharW(NStringBuilderW * pStringBuilder, NWChar value);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NStringBuilderAppendChar(NStringBuilder * pStringBuilder, NChar value);
#endif
#define NStringBuilderAppendChar N_FUNC_AW(NStringBuilderAppendChar)

NResult N_API NStringBuilderAppendCharRepeatA(NStringBuilderA * pStringBuilder, NAChar value, NInt repeatCount);
#ifndef N_NO_UNICODE
NResult N_API NStringBuilderAppendCharRepeatW(NStringBuilderW * pStringBuilder, NWChar value, NInt repeatCount);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NStringBuilderAppendCharRepeat(NStringBuilder * pStringBuilder, NChar value, NInt repeatCount);
#endif
#define NStringBuilderAppendCharRepeat N_FUNC_AW(NStringBuilderAppendCharRepeat)

NResult N_API NStringBuilderAppendCharsA(NStringBuilderA * pStringBuilder, const NAChar * arValue, NInt valueLength);
#ifndef N_NO_UNICODE
NResult N_API NStringBuilderAppendCharsW(NStringBuilderW * pStringBuilder, const NWChar * arValue, NInt valueLength);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NStringBuilderAppendChars(NStringBuilder * pStringBuilder, const NChar * arValue, NInt valueLength);
#endif
#define NStringBuilderAppendChars N_FUNC_AW(NStringBuilderAppendChars)

NResult N_API NStringBuilderAppendNA(NStringBuilderA * pStringBuilder, HNString hValue);
#ifndef N_NO_UNICODE
NResult N_API NStringBuilderAppendNW(NStringBuilderW * pStringBuilder, HNString hValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NStringBuilderAppendN(NStringBuilder * pStringBuilder, HNString hValue);
#endif
#define NStringBuilderAppendN N_FUNC_AW(NStringBuilderAppendN)

NResult N_API NStringBuilderAppendA(NStringBuilderA * pStringBuilder, const NAChar * szValue);
#ifndef N_NO_UNICODE
NResult N_API NStringBuilderAppendW(NStringBuilderW * pStringBuilder, const NWChar * szValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NStringBuilderAppend(NStringBuilder * pStringBuilder, const NChar * szValue);
#endif
#define NStringBuilderAppend N_FUNC_AW(NStringBuilderAppend)

NResult N_API NStringBuilderAppendFormatNA(NStringBuilderA * pStringBuilder, HNString hFormat, ...);
#ifndef N_NO_UNICODE
NResult N_API NStringBuilderAppendFormatNW(NStringBuilderW * pStringBuilder, HNString hFormat, ...);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NStringBuilderAppendFormatN(NStringBuilder * pStringBuilder, HNString hFormat, ... multipleParameters);
#endif
#define NStringBuilderAppendFormatN N_FUNC_AW(NStringBuilderAppendFormatN)

NResult N_API NStringBuilderAppendFormatA(NStringBuilderA * pStringBuilder, const NAChar * szFormat, ...);
#ifndef N_NO_UNICODE
NResult N_API NStringBuilderAppendFormatW(NStringBuilderW * pStringBuilder, const NWChar * szFormat, ...);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NStringBuilderAppendFormat(NStringBuilder * pStringBuilder, const NChar * szFormat, ... multipleParameters);
#endif
#define NStringBuilderAppendFormat N_FUNC_AW(NStringBuilderAppendFormat)

NResult N_API NStringBuilderAppendFormatVANA(NStringBuilderA * pStringBuilder, HNString hFormat, va_list args);
#ifndef N_NO_UNICODE
NResult N_API NStringBuilderAppendFormatVANW(NStringBuilderW * pStringBuilder, HNString hFormat, va_list args);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NStringBuilderAppendFormatVAN(NStringBuilder * pStringBuilder, HNString hFormat, va_list args);
#endif
#define NStringBuilderAppendFormatVAN N_FUNC_AW(NStringBuilderAppendFormatVAN)

NResult N_API NStringBuilderAppendFormatVAA(NStringBuilderA * pStringBuilder, const NAChar * szFormat, va_list args);
#ifndef N_NO_UNICODE
NResult N_API NStringBuilderAppendFormatVAW(NStringBuilderW * pStringBuilder, const NWChar * szFormat, va_list args);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NStringBuilderAppendFormatVA(NStringBuilder * pStringBuilder, const NChar * szFormat, va_list args);
#endif
#define NStringBuilderAppendFormatVA N_FUNC_AW(NStringBuilderAppendFormatVA)

NResult N_API NStringBuilderAppendEmptyLineA(NStringBuilderA * pStringBuilder);
#ifndef N_NO_UNICODE
NResult N_API NStringBuilderAppendEmptyLineW(NStringBuilderW * pStringBuilder);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NStringBuilderAppendEmptyLine(NStringBuilder * pStringBuilder);
#endif
#define NStringBuilderAppendEmptyLine N_FUNC_AW(NStringBuilderAppendEmptyLine)

NResult N_API NStringBuilderAppendLineNA(NStringBuilderA * pStringBuilder, HNString hValue);
#ifndef N_NO_UNICODE
NResult N_API NStringBuilderAppendLineNW(NStringBuilderW * pStringBuilder, HNString hValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NStringBuilderAppendLineN(NStringBuilder * pStringBuilder, HNString hValue);
#endif
#define NStringBuilderAppendLineN N_FUNC_AW(NStringBuilderAppendLineN)

NResult N_API NStringBuilderAppendLineA(NStringBuilderA * pStringBuilder, const NAChar * szValue);
#ifndef N_NO_UNICODE
NResult N_API NStringBuilderAppendLineW(NStringBuilderW * pStringBuilder, const NWChar * szValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NStringBuilderAppendLine(NStringBuilder * pStringBuilder, const NChar * szValue);
#endif
#define NStringBuilderAppendLine N_FUNC_AW(NStringBuilderAppendLine)

NResult N_API NStringBuilderInsertBooleanA(NStringBuilderA * pStringBuilder, NInt index, NBool value);
#ifndef N_NO_UNICODE
NResult N_API NStringBuilderInsertBooleanW(NStringBuilderW * pStringBuilder, NInt index, NBool value);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NStringBuilderInsertBoolean(NStringBuilder * pStringBuilder, NInt index, NBool value);
#endif
#define NStringBuilderInsertBoolean N_FUNC_AW(NStringBuilderInsertBoolean)

NResult N_API NStringBuilderInsertSingleA(NStringBuilderA * pStringBuilder, NInt index, NFloat value);
#ifndef N_NO_UNICODE
NResult N_API NStringBuilderInsertSingleW(NStringBuilderW * pStringBuilder, NInt index, NFloat value);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NStringBuilderInsertSingle(NStringBuilder * pStringBuilder, NInt index, NFloat value);
#endif
#define NStringBuilderInsertSingle N_FUNC_AW(NStringBuilderInsertSingle)

NResult N_API NStringBuilderInsertDoubleA(NStringBuilderA * pStringBuilder, NInt index, NDouble value);
#ifndef N_NO_UNICODE
NResult N_API NStringBuilderInsertDoubleW(NStringBuilderW * pStringBuilder, NInt index, NDouble value);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NStringBuilderInsertDouble(NStringBuilder * pStringBuilder, NInt index, NDouble value);
#endif
#define NStringBuilderInsertDouble N_FUNC_AW(NStringBuilderInsertDouble)

NResult N_API NStringBuilderInsertSByteA(NStringBuilderA * pStringBuilder, NInt index, NSByte value);
#ifndef N_NO_UNICODE
NResult N_API NStringBuilderInsertSByteW(NStringBuilderW * pStringBuilder, NInt index, NSByte value);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NStringBuilderInsertSByte(NStringBuilder * pStringBuilder, NInt index, NSByte value);
#endif
#define NStringBuilderInsertSByte N_FUNC_AW(NStringBuilderInsertSByte)

NResult N_API NStringBuilderInsertInt16A(NStringBuilderA * pStringBuilder, NInt index, NShort value);
#ifndef N_NO_UNICODE
NResult N_API NStringBuilderInsertInt16W(NStringBuilderW * pStringBuilder, NInt index, NShort value);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NStringBuilderInsertInt16(NStringBuilder * pStringBuilder, NInt index, NShort value);
#endif
#define NStringBuilderInsertInt16 N_FUNC_AW(NStringBuilderInsertInt16)

NResult N_API NStringBuilderInsertInt32A(NStringBuilderA * pStringBuilder, NInt index, NInt value);
#ifndef N_NO_UNICODE
NResult N_API NStringBuilderInsertInt32W(NStringBuilderW * pStringBuilder, NInt index, NInt value);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NStringBuilderInsertInt32(NStringBuilder * pStringBuilder, NInt index, NInt value);
#endif
#define NStringBuilderInsertInt32 N_FUNC_AW(NStringBuilderInsertInt32)

NResult N_API NStringBuilderInsertInt64A(NStringBuilderA * pStringBuilder, NInt index, NLong value);
#ifndef N_NO_UNICODE
NResult N_API NStringBuilderInsertInt64W(NStringBuilderW * pStringBuilder, NInt index, NLong value);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NStringBuilderInsertInt64(NStringBuilder * pStringBuilder, NInt index, NLong value);
#endif
#define NStringBuilderInsertInt64 N_FUNC_AW(NStringBuilderInsertInt64)

NResult N_API NStringBuilderInsertByteA(NStringBuilderA * pStringBuilder, NInt index, NByte value);
#ifndef N_NO_UNICODE
NResult N_API NStringBuilderInsertByteW(NStringBuilderW * pStringBuilder, NInt index, NByte value);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NStringBuilderInsertByte(NStringBuilder * pStringBuilder, NInt index, NByte value);
#endif
#define NStringBuilderInsertByte N_FUNC_AW(NStringBuilderInsertByte)

NResult N_API NStringBuilderInsertUInt16A(NStringBuilderA * pStringBuilder, NInt index, NUShort value);
#ifndef N_NO_UNICODE
NResult N_API NStringBuilderInsertUInt16W(NStringBuilderW * pStringBuilder, NInt index, NUShort value);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NStringBuilderInsertUInt16(NStringBuilder * pStringBuilder, NInt index, NUShort value);
#endif
#define NStringBuilderInsertUInt16 N_FUNC_AW(NStringBuilderInsertUInt16)

NResult N_API NStringBuilderInsertUInt32A(NStringBuilderA * pStringBuilder, NInt index, NUInt value);
#ifndef N_NO_UNICODE
NResult N_API NStringBuilderInsertUInt32W(NStringBuilderW * pStringBuilder, NInt index, NUInt value);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NStringBuilderInsertUInt32(NStringBuilder * pStringBuilder, NInt index, NUInt value);
#endif
#define NStringBuilderInsertUInt32 N_FUNC_AW(NStringBuilderInsertUInt32)

NResult N_API NStringBuilderInsertUInt64A(NStringBuilderA * pStringBuilder, NInt index, NULong value);
#ifndef N_NO_UNICODE
NResult N_API NStringBuilderInsertUInt64W(NStringBuilderW * pStringBuilder, NInt index, NULong value);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NStringBuilderInsertUInt64(NStringBuilder * pStringBuilder, NInt index, NULong value);
#endif
#define NStringBuilderInsertUInt64 N_FUNC_AW(NStringBuilderInsertUInt64)

NResult N_API NStringBuilderInsertSizeTypeA(NStringBuilderA * pStringBuilder, NInt index, NSizeType value);
#ifndef N_NO_UNICODE
NResult N_API NStringBuilderInsertSizeTypeW(NStringBuilderW * pStringBuilder, NInt index, NSizeType value);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NStringBuilderInsertSizeType(NStringBuilder * pStringBuilder, NInt index, NSizeType value);
#endif
#define NStringBuilderInsertSizeType N_FUNC_AW(NStringBuilderInsertSizeType)

NResult N_API NStringBuilderInsertSSizeTypeA(NStringBuilderA * pStringBuilder, NInt index, NSSizeType value);
#ifndef N_NO_UNICODE
NResult N_API NStringBuilderInsertSSizeTypeW(NStringBuilderW * pStringBuilder, NInt index, NSSizeType value);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NStringBuilderInsertSSizeType(NStringBuilder * pStringBuilder, NInt index, NSSizeType value);
#endif
#define NStringBuilderInsertSSizeType N_FUNC_AW(NStringBuilderInsertSSizeType)

NResult N_API NStringBuilderInsertPointerA(NStringBuilderA * pStringBuilder, NInt index, const void * value);
#ifndef N_NO_UNICODE
NResult N_API NStringBuilderInsertPointerW(NStringBuilderW * pStringBuilder, NInt index, const void * value);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NStringBuilderInsertPointer(NStringBuilder * pStringBuilder, NInt index, const void * value);
#endif
#define NStringBuilderInsertPointer N_FUNC_AW(NStringBuilderInsertPointer)

NResult N_API NStringBuilderInsertResultA(NStringBuilderA * pStringBuilder, NInt index, NResult value);
#ifndef N_NO_UNICODE
NResult N_API NStringBuilderInsertResultW(NStringBuilderW * pStringBuilder, NInt index, NResult value);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NStringBuilderInsertResult(NStringBuilder * pStringBuilder, NInt index, NResult value);
#endif
#define NStringBuilderInsertResult N_FUNC_AW(NStringBuilderInsertResult)

NResult N_API NStringBuilderInsertValueA(NStringBuilderA * pStringBuilder, NInt index, HNType hType, const void * pValue, NSizeType valueSize);
#ifndef N_NO_UNICODE
NResult N_API NStringBuilderInsertValueW(NStringBuilderW * pStringBuilder, NInt index, HNType hType, const void * pValue, NSizeType valueSize);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NStringBuilderInsertValue(NStringBuilder * pStringBuilder, NInt index, HNType hType, const void * pValue, NSizeType valueSize);
#endif
#define NStringBuilderInsertValue N_FUNC_AW(NStringBuilderInsertValue)

NResult N_API NStringBuilderInsertValuePA(NStringBuilderA * pStringBuilder, NInt index, NTypeOfProc pTypeOf, const void * pValue, NSizeType valueSize);
#ifndef N_NO_UNICODE
NResult N_API NStringBuilderInsertValuePW(NStringBuilderW * pStringBuilder, NInt index, NTypeOfProc pTypeOf, const void * pValue, NSizeType valueSize);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NStringBuilderInsertValueP(NStringBuilder * pStringBuilder, NInt index, NTypeOfProc pTypeOf, const void * pValue, NSizeType valueSize);
#endif
#define NStringBuilderInsertValueP N_FUNC_AW(NStringBuilderInsertValueP)

NResult N_API NStringBuilderInsertObjectA(NStringBuilderA * pStringBuilder, NInt index, HNObject hObject);
#ifndef N_NO_UNICODE
NResult N_API NStringBuilderInsertObjectW(NStringBuilderW * pStringBuilder, NInt index, HNObject hObject);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NStringBuilderInsertObject(NStringBuilder * pStringBuilder, NInt index, HNObject hObject);
#endif
#define NStringBuilderInsertObject N_FUNC_AW(NStringBuilderInsertObject)

NResult N_API NStringBuilderInsertCharA(NStringBuilderA * pStringBuilder, NInt index, NAChar value);
#ifndef N_NO_UNICODE
NResult N_API NStringBuilderInsertCharW(NStringBuilderW * pStringBuilder, NInt index, NWChar value);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NStringBuilderInsertChar(NStringBuilder * pStringBuilder, NInt index, NChar value);
#endif
#define NStringBuilderInsertChar N_FUNC_AW(NStringBuilderInsertChar)

NResult N_API NStringBuilderInsertCharsA(NStringBuilderA * pStringBuilder, NInt index, const NAChar * arValue, NInt valueLength);
#ifndef N_NO_UNICODE
NResult N_API NStringBuilderInsertCharsW(NStringBuilderW * pStringBuilder, NInt index, const NWChar * arValue, NInt valueLength);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NStringBuilderInsertChars(NStringBuilder * pStringBuilder, NInt index, const NChar * arValue, NInt valueLength);
#endif
#define NStringBuilderInsertChars N_FUNC_AW(NStringBuilderInsertChars)

NResult N_API NStringBuilderInsertNA(NStringBuilderA * pStringBuilder, NInt index, HNString hValue);
#ifndef N_NO_UNICODE
NResult N_API NStringBuilderInsertNW(NStringBuilderW * pStringBuilder, NInt index, HNString hValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NStringBuilderInsertN(NStringBuilder * pStringBuilder, NInt index, HNString hValue);
#endif
#define NStringBuilderInsertN N_FUNC_AW(NStringBuilderInsertN)

NResult N_API NStringBuilderInsertA(NStringBuilderA * pStringBuilder, NInt index, const NAChar * szValue);
#ifndef N_NO_UNICODE
NResult N_API NStringBuilderInsertW(NStringBuilderW * pStringBuilder, NInt index, const NWChar * szValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NStringBuilderInsert(NStringBuilder * pStringBuilder, NInt index, const NChar * szValue);
#endif
#define NStringBuilderInsert N_FUNC_AW(NStringBuilderInsert)

NResult N_API NStringBuilderClearA(NStringBuilderA * pStringBuilder);
#ifndef N_NO_UNICODE
NResult N_API NStringBuilderClearW(NStringBuilderW * pStringBuilder);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NStringBuilderClear(NStringBuilder * pStringBuilder);
#endif
#define NStringBuilderClear N_FUNC_AW(NStringBuilderClear)

NResult N_API NStringBuilderCopyToStrOrCharsA(NStringBuilderA * pStringBuilder, NInt sourceIndex, NAChar * arValue, NInt valueLength, NBool nullTerminate, NInt count);
#ifndef N_NO_UNICODE
NResult N_API NStringBuilderCopyToStrOrCharsW(NStringBuilderW * pStringBuilder, NInt sourceIndex, NWChar * arValue, NInt valueLength, NBool nullTerminate, NInt count);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NStringBuilderCopyToStrOrChars(NStringBuilder * pStringBuilder, NInt sourceIndex, NChar * arValue, NInt valueLength, NBool nullTerminate, NInt count);
#endif
#define NStringBuilderCopyToStrOrChars N_FUNC_AW(NStringBuilderCopyToStrOrChars)

#define NStringBuilderCopyToStringA(pStringBuilder, sourceIndex, szValue, valueSize, count) NStringBuilderCopyToStrOrCharsA(pStringBuilder, sourceIndex, szValue, valueSize, NTrue, count)
#define NStringBuilderCopyToStringW(pStringBuilder, sourceIndex, szValue, valueSize, count) NStringBuilderCopyToStrOrCharsW(pStringBuilder, sourceIndex, szValue, valueSize, NTrue, count)
#define NStringBuilderCopyToString(pStringBuilder, sourceIndex, szValue, valueSize, count) NStringBuilderCopyToStrOrChars(pStringBuilder, sourceIndex, szValue, valueSize, NTrue, count)

#define NStringBuilderCopyToA(pStringBuilder, sourceIndex, arValue, valueLength, count) NStringBuilderCopyToStrOrCharsA(pStringBuilder, sourceIndex, arValue, valueLength, NFalse, count)
#define NStringBuilderCopyToW(pStringBuilder, sourceIndex, arValue, valueLength, count) NStringBuilderCopyToStrOrCharsW(pStringBuilder, sourceIndex, arValue, valueLength, NFalse, count)
#define NStringBuilderCopyTo(pStringBuilder, sourceIndex, arValue, valueLength, count) NStringBuilderCopyToStrOrChars(pStringBuilder, sourceIndex, arValue, valueLength, NFalse, count)

NResult N_API NStringBuilderRemoveA(NStringBuilderA * pStringBuilder, NInt startIndex, NInt count);
#ifndef N_NO_UNICODE
NResult N_API NStringBuilderRemoveW(NStringBuilderW * pStringBuilder, NInt startIndex, NInt count);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NStringBuilderRemove(NStringBuilder * pStringBuilder, NInt startIndex, NInt count);
#endif
#define NStringBuilderRemove N_FUNC_AW(NStringBuilderRemove)

NResult N_API NStringBuilderReplaceA(NStringBuilderA * pStringBuilder, NAChar oldValue, NAChar newValue);
#ifndef N_NO_UNICODE
NResult N_API NStringBuilderReplaceW(NStringBuilderW * pStringBuilder, NWChar oldValue, NWChar newValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NStringBuilderReplace(NStringBuilder * pStringBuilder, NChar oldValue, NChar newValue);
#endif
#define NStringBuilderReplace N_FUNC_AW(NStringBuilderReplace)

NResult N_API NStringBuilderReplaceInRangeA(NStringBuilderA * pStringBuilder, NAChar oldValue, NAChar newValue, NInt startIndex, NInt count);
#ifndef N_NO_UNICODE
NResult N_API NStringBuilderReplaceInRangeW(NStringBuilderW * pStringBuilder, NWChar oldValue, NWChar newValue, NInt startIndex, NInt count);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NStringBuilderReplaceInRange(NStringBuilder * pStringBuilder, NChar oldValue, NChar newValue, NInt startIndex, NInt count);
#endif
#define NStringBuilderReplaceInRange N_FUNC_AW(NStringBuilderReplaceInRange)

NResult N_API NStringBuilderReplaceStringNA(NStringBuilderA * pStringBuilder, HNString hOldValue, HNString hNewValue);
#ifndef N_NO_UNICODE
NResult N_API NStringBuilderReplaceStringNW(NStringBuilderW * pStringBuilder, HNString hOldValue, HNString hNewValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NStringBuilderReplaceStringN(NStringBuilder * pStringBuilder, HNString hOldValue, HNString hNewValue);
#endif
#define NStringBuilderReplaceStringN N_FUNC_AW(NStringBuilderReplaceStringN)

NResult N_API NStringBuilderReplaceStrOrCharsA(NStringBuilderA * pStringBuilder, const NAChar * arOldValue, NInt oldValueLength, const NAChar * arNewValue, NInt newValueLength);
#ifndef N_NO_UNICODE
NResult N_API NStringBuilderReplaceStrOrCharsW(NStringBuilderW * pStringBuilder, const NWChar * arOldValue, NInt oldValueLength, const NWChar * arNewValue, NInt newValueLength);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NStringBuilderReplaceStrOrChars(NStringBuilder * pStringBuilder, const NChar * arOldValue, NInt oldValueLength, const NChar * arNewValue, NInt newValueLength);
#endif
#define NStringBuilderReplaceStrOrChars N_FUNC_AW(NStringBuilderReplaceStrOrChars)

#define NStringBuilderReplaceStringA(pStringBuilder, szOldValue, szNewValue) NStringBuilderReplaceStrOrCharsA(pStringBuilder, szOldValue, -1, szNewValue, -1)
#define NStringBuilderReplaceStringW(pStringBuilder, szOldValue, szNewValue) NStringBuilderReplaceStrOrCharsW(pStringBuilder, szOldValue, -1, szNewValue, -1)
#define NStringBuilderReplaceString(pStringBuilder, szOldValue, szNewValue) NStringBuilderReplaceStrOrChars(pStringBuilder, szOldValue, -1, szNewValue, -1)
#define NStringBuilderReplaceCharsA(pStringBuilder, arOldValue, oldValueLength, arNewValue, newValueLength) NStringBuilderReplaceStrOrCharsA(pStringBuilder, arOldValue, oldValueLength, arNewValue, newValueLength)
#define NStringBuilderReplaceCharsW(pStringBuilder, arOldValue, oldValueLength, arNewValue, newValueLength) NStringBuilderReplaceStrOrCharsW(pStringBuilder, arOldValue, oldValueLength, arNewValue, newValueLength)
#define NStringBuilderReplaceChars(pStringBuilder, arOldValue, oldValueLength, arNewValue, newValueLength) NStringBuilderReplaceStrOrChars(pStringBuilder, arOldValue, oldValueLength, arNewValue, newValueLength)

NResult N_API NStringBuilderReplaceStringInRangeNA(NStringBuilderA * pStringBuilder, HNString hOldValue, HNString hNewValue, NInt startIndex, NInt count);
#ifndef N_NO_UNICODE
NResult N_API NStringBuilderReplaceStringInRangeNW(NStringBuilderW * pStringBuilder, HNString hOldValue, HNString hNewValue, NInt startIndex, NInt count);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NStringBuilderReplaceStringInRangeN(NStringBuilder * pStringBuilder, HNString hOldValue, HNString hNewValue, NInt startIndex, NInt count);
#endif
#define NStringBuilderReplaceStringInRangeN N_FUNC_AW(NStringBuilderReplaceStringInRangeN)

NResult N_API NStringBuilderReplaceStrOrCharsInRangeA(NStringBuilderA * pStringBuilder, const NAChar * arOldValue, NInt oldValueLength, const NAChar * arNewValue, NInt newValueLength, NInt startIndex, NInt count);
#ifndef N_NO_UNICODE
NResult N_API NStringBuilderReplaceStrOrCharsInRangeW(NStringBuilderW * pStringBuilder, const NWChar * arOldValue, NInt oldValueLength, const NWChar * arNewValue, NInt newValueLength, NInt startIndex, NInt count);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NStringBuilderReplaceStrOrCharsInRange(NStringBuilder * pStringBuilder, const NChar * arOldValue, NInt oldValueLength, const NChar * arNewValue, NInt newValueLength, NInt startIndex, NInt count);
#endif
#define NStringBuilderReplaceStrOrCharsInRange N_FUNC_AW(NStringBuilderReplaceStrOrCharsInRange)

#define NStringBuilderReplaceStringInRangeA(pStringBuilder, szOldValue, szNewValue, startIndex, count) NStringBuilderReplaceStrOrCharsInRangeA(pStringBuilder, szOldValue, -1, szNewValue, -1, startIndex, count)
#define NStringBuilderReplaceStringInRangeW(pStringBuilder, szOldValue, szNewValue, startIndex, count) NStringBuilderReplaceStrOrCharsInRangeW(pStringBuilder, szOldValue, -1, szNewValue, -1, startIndex, count)
#define NStringBuilderReplaceStringInRange(pStringBuilder, szOldValue, szNewValue, startIndex, count) NStringBuilderReplaceStrOrCharsInRange(pStringBuilder, szOldValue, -1, szNewValue, -1, startIndex, count)
#define NStringBuilderReplaceCharsInRangeA(pStringBuilder, arOldValue, oldValueLength, arNewValue, newValueLength, startIndex, count) NStringBuilderReplaceStrOrCharsInRangeA(pStringBuilder, arOldValue, oldValueLength, arNewValue, newValueLength, startIndex, count)
#define NStringBuilderReplaceCharsInRangeW(pStringBuilder, arOldValue, oldValueLength, arNewValue, newValueLength, startIndex, count) NStringBuilderReplaceStrOrCharsInRangeW(pStringBuilder, arOldValue, oldValueLength, arNewValue, newValueLength, startIndex, count)
#define NStringBuilderReplaceCharsInRange(pStringBuilder, arOldValue, oldValueLength, arNewValue, newValueLength, startIndex, count) NStringBuilderReplaceStrOrCharsInRange(pStringBuilder, arOldValue, oldValueLength, arNewValue, newValueLength, startIndex, count)

NResult N_API NStringBuilderToStringRangeA(NStringBuilderA * pStringBuilder, NInt startIndex, NInt length, HNString * phValue);
#ifndef N_NO_UNICODE
NResult N_API NStringBuilderToStringRangeW(NStringBuilderW * pStringBuilder, NInt startIndex, NInt length, HNString * phValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NStringBuilderToStringRange(NStringBuilder * pStringBuilder, NInt startIndex, NInt length, HNString * phValue);
#endif
#define NStringBuilderToStringRange N_FUNC_AW(NStringBuilderToStringRange)

NResult N_API NStringBuilderToStringA(NStringBuilderA * pStringBuilder, HNString * phValue);
#ifndef N_NO_UNICODE
NResult N_API NStringBuilderToStringW(NStringBuilderW * pStringBuilder, HNString * phValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NStringBuilderToString(NStringBuilder * pStringBuilder, HNString * phValue);
#endif
#define NStringBuilderToString N_FUNC_AW(NStringBuilderToString)

NResult N_API NStringBuilderDetachStringNA(NStringBuilderA * pStringBuilder, HNString * phValue);
#ifndef N_NO_UNICODE
NResult N_API NStringBuilderDetachStringNW(NStringBuilderW * pStringBuilder, HNString * phValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NStringBuilderDetachStringN(NStringBuilder * pStringBuilder, HNString * phValue);
#endif
#define NStringBuilderDetachStringN N_FUNC_AW(NStringBuilderDetachStringN)

NResult N_API NStringBuilderGetStrOrCharsBufferA(NStringBuilderA * pStringBuilder, NBool nullTerminate, NInt * pValueLength, NAChar * * parValue);
#ifndef N_NO_UNICODE
NResult N_API NStringBuilderGetStrOrCharsBufferW(NStringBuilderW * pStringBuilder, NBool nullTerminate, NInt * pValueLength, NWChar * * parValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NStringBuilderGetStrOrCharsBuffer(NStringBuilder * pStringBuilder, NBool nullTerminate, NInt * pValueLength, NChar * * parValue);
#endif
#define NStringBuilderGetStrOrCharsBuffer N_FUNC_AW(NStringBuilderGetStrOrCharsBuffer)

#define NStringBuilderGetBufferA(pStringBuilder, pValueLength, pszValue) NStringBuilderGetStrOrCharsBufferA(pStringBuilder, NTrue, pValueLength, pszValue)
#define NStringBuilderGetBufferW(pStringBuilder, pValueLength, pszValue) NStringBuilderGetStrOrCharsBufferW(pStringBuilder, NTrue, pValueLength, pszValue)
#define NStringBuilderGetBuffer(pStringBuilder, pValueLength, pszValue) NStringBuilderGetStrOrCharsBuffer(pStringBuilder, NTrue, pValueLength, pszValue)
#define NStringBuilderGetCharsBufferA(pStringBuilder, pValueLength, parValue) NStringBuilderGetStrOrCharsBufferA(pStringBuilder, NFalse, pValueLength, parValue)
#define NStringBuilderGetCharsBufferW(pStringBuilder, pValueLength, parValue) NStringBuilderGetStrOrCharsBufferW(pStringBuilder, NFalse, pValueLength, parValue)
#define NStringBuilderGetCharsBuffer(pStringBuilder, pValueLength, parValue) NStringBuilderGetStrOrCharsBuffer(pStringBuilder, NFalse, pValueLength, parValue)

NResult N_API NStringBuilderDetachStrOrCharsA(NStringBuilderA * pStringBuilder, NBool nullTerminate, NAChar * * parValue, NInt * pValueLength);
#ifndef N_NO_UNICODE
NResult N_API NStringBuilderDetachStrOrCharsW(NStringBuilderW * pStringBuilder, NBool nullTerminatex, NWChar * * parValue, NInt * pValueLength);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NStringBuilderDetachStrOrChars(NStringBuilder * pStringBuilder, NBool nullTerminate, NChar * * parValue, NInt * pValueLength);
#endif
#define NStringBuilderDetachStrOrChars N_FUNC_AW(NStringBuilderDetachStrOrChars)

#define NStringBuilderDetachStringA(pStringBuilder, pszValue, pValueLength) NStringBuilderDetachStrOrCharsA(pStringBuilder, NTrue, pszValue, pValueLength)
#define NStringBuilderDetachStringW(pStringBuilder, pszValue, pValueLength) NStringBuilderDetachStrOrCharsW(pStringBuilder, NTrue, pszValue, pValueLength)
#define NStringBuilderDetachString(pStringBuilder, pszValue, pValueLength) NStringBuilderDetachStrOrChars(pStringBuilder, NTrue, pszValue, pValueLength)
#define NStringBuilderDetachCharArrayA(pStringBuilder, parValue, pValueLength) NStringBuilderDetachStrOrCharsA(pStringBuilder, NFalse, parValue, pValueLength)
#define NStringBuilderDetachCharArrayW(pStringBuilder, parValue, pValueLength) NStringBuilderDetachStrOrCharsW(pStringBuilder, NFalse, parValue, pValueLength)
#define NStringBuilderDetachCharArray(pStringBuilder, parValue, pValueLength) NStringBuilderDetachStrOrChars(pStringBuilder, NFalse, parValue, pValueLength)

NResult N_API NStringBuilderGetStringWrapperA(NStringBuilderA * pStringBuilder, NStringHeader * pStringHeader, HNString * phValue);
#ifndef N_NO_UNICODE
NResult N_API NStringBuilderGetStringWrapperW(NStringBuilderW * pStringBuilder, NStringHeader * pStringHeader, HNString * phValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NStringBuilderGetStringWrapper(NStringBuilder * pStringBuilder, NStringHeader * pStringHeader, HNString * phValue);
#endif
#define NStringBuilderGetStringWrapper N_FUNC_AW(NStringBuilderGetStringWrapper)

#ifdef N_CPP
}
#endif

#endif // !N_STRING_BUILDER_H_INCLUDED
