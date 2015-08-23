#ifndef N_STRING_H_INCLUDED
#define N_STRING_H_INCLUDED

#include <Core/NTypes.h>
#include <Core/NMemory.h>

#ifdef N_CPP
extern "C"
{
#endif

#ifdef N_64
	#define N_STRING_SIZE 32
#else
	#define N_STRING_SIZE 24
#endif

N_DECLATE_PRIMITIVE(NStringHeader, N_STRING_SIZE)

NResult N_API NStringGetEmpty(HNString * phValue);

NResult N_API NStringCreateFromStrOrCharsA(const NAChar * arValue, NInt length, HNString * phString);
#ifndef N_NO_UNICODE
NResult N_API NStringCreateFromStrOrCharsW(const NWChar * arValue, NInt length, HNString * phString);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NStringCreateFromStrOrChars(const NChar * arValue, NInt length, HNString * phString);
#endif
#define NStringCreateFromStrOrChars N_FUNC_AW(NStringCreateFromStrOrChars)

#define NStringCreateA(szValue, phString) NStringCreateFromStrOrCharsA(szValue, -1, phString)
#define NStringCreateW(szValue, phString) NStringCreateFromStrOrCharsW(szValue, -1, phString)
#define NStringCreate(szValue, phString) NStringCreateFromStrOrChars(szValue, -1, phString)
#define NStringCreateFromCharsA(arValue, length, phString) NStringCreateFromStrOrCharsA(arValue, length, phString)
#define NStringCreateFromCharsW(arValue, length, phString) NStringCreateFromStrOrCharsW(arValue, length, phString)
#define NStringCreateFromChars(arValue, length, phString) NStringCreateFromStrOrChars(arValue, length, phString)

NResult N_API NStringCreateFromCharA(NAChar value, NInt count, HNString * phString);
#ifndef N_NO_UNICODE
NResult N_API NStringCreateFromCharW(NWChar value, NInt count, HNString * phString);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NStringCreateFromChar(NChar value, NInt count, HNString * phString);
#endif
#define NStringCreateFromChar N_FUNC_AW(NStringCreateFromChar)

NResult N_API NStringCreateWrapperA(const NAChar * szValue, NInt length, NStringHeader * pStringHeader, HNString * phString);
#ifndef N_NO_UNICODE
NResult N_API NStringCreateWrapperW(const NWChar * szValue, NInt length, NStringHeader * pStringHeader, HNString * phString);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NStringCreateWrapper(const NChar * szValue, NInt length, NStringHeader * pStringHeader, HNString * phString);
#endif
#define NStringCreateWrapper N_FUNC_AW(NStringCreateWrapper)

NResult N_API NStringPromoteBufferA(NAChar * szValue, NInt length, NMemoryType memoryType, HNString * phString);
#ifndef N_NO_UNICODE
NResult N_API NStringPromoteBufferW(NWChar * szValue, NInt length, NMemoryType memoryType, HNString * phString);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NStringPromoteBuffer(NChar * szValue, NInt length, NMemoryType memoryType, HNString * phString);
#endif
#define NStringPromoteBuffer N_FUNC_AW(NStringPromoteBuffer)

NResult N_API NStringClone(HNString hString, HNString * phResultString);
void N_API NStringFree(HNString hString);
void N_API NStringFreeElements(HNString * arhStrings, NInt count);
void N_API NStringFreeArray(HNString * arhStrings, NInt count);
#define NStringGet(hValue, phValue) NStringClone(hValue, phValue)
NResult N_API NStringSet(HNString hValue, HNString * phVariable);
NResult N_API NStringGetConcurrent(volatile HNString * phVariable, HNString * phValue);
NResult N_API NStringSetConcurrent(HNString hValue, volatile HNString * phVariable);
NResult N_API NStringGetElements(const HNString * arhStrings, NInt stringCount, HNString * arhValues, NInt valuesLength);
NResult N_API NStringGetArray(const HNString * arhStrings, NInt stringCount, HNString * * parhValues, NInt * pValueCount);

NResult N_API NStringGetLengthA(HNString hString, NInt * pValue);
#ifndef N_NO_UNICODE
NResult N_API NStringGetLengthW(HNString hString, NInt * pValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NStringGetLength(HNString hString, NInt * pValue);
#endif
#define NStringGetLength N_FUNC_AW(NStringGetLength)

NResult N_API NStringGetBufferA(HNString hString, NInt * pLength, const NAChar * * pszBuffer);
#ifndef N_NO_UNICODE
NResult N_API NStringGetBufferW(HNString hString, NInt * pLength, const NWChar * * pszBuffer);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NStringGetBuffer(HNString hString, NInt * pLength, const NChar * * pszBuffer);
#endif
#define NStringGetBuffer N_FUNC_AW(NStringGetBuffer)

NBool N_API NStringIsEmpty(HNString hString);

NBool N_API NStringIsA(HNString hString);
#ifndef N_NO_UNICODE
NBool N_API NStringIsW(HNString hString);
#endif

NResult N_API NStringHasEmbeddedNull(HNString hString, NBool * pValue);
NResult N_API NStringIsWhiteSpace(HNString hString, NBool * pValue);
NResult N_API NStringGetHashCode(HNString hString, NInt * pHashCode);

NResult N_API NStringGetCharA(HNString hString, NInt index, NAChar * pValue);
#ifndef N_NO_UNICODE
NResult N_API NStringGetCharW(HNString hString, NInt index, NWChar * pValue);
#endif
#ifndef N_DOCUMENTATION
NResult N_API NStringGetChar(HNString hString, NInt index, NChar * pValue);
#endif
#define NStringGetChar N_FUNC_AW(NStringGetChar)

NResult N_API NStringCompareRangeNA(HNString hString, NInt index, HNString hOtherString, NInt otherIndex, NInt length, NBool ignoreCase, NInt * pResult);
#ifndef N_NO_UNICODE
NResult N_API NStringCompareRangeNW(HNString hString, NInt index, HNString hOtherString, NInt otherIndex, NInt length, NBool ignoreCase, NInt * pResult);
#endif
#ifndef N_DOCUMENTATION
NResult N_API NStringCompareRangeN(HNString hString, NInt index, HNString hOtherString, NInt otherIndex, NInt length, NBool ignoreCase, NInt * pResult);
#endif
#define NStringCompareRangeN N_FUNC_AW(NStringCompareRangeN)

NResult N_API NStringCompareRangeStrOrCharsA(HNString hString, NInt index, const NAChar * arValue, NInt valueLength, NInt length, NBool ignoreCase, NInt * pResult);
#ifndef N_NO_UNICODE
NResult N_API NStringCompareRangeStrOrCharsW(HNString hString, NInt index, const NWChar * arValue, NInt valueLength, NInt length, NBool ignoreCase, NInt * pResult);
#endif
#ifndef N_DOCUMENTATION
NResult N_API NStringCompareRangeStrOrChars(HNString hString, NInt index, const NChar * arValue, NInt valueLength, NInt length, NBool ignoreCase, NInt * pResult);
#endif
#define NStringCompareRangeStrOrChars N_FUNC_AW(NStringCompareRangeStrOrChars)

#define NStringCompareRangeA(hString, index, szValue, length, ignoreCase, pResult) NStringCompareRangeStrOrCharsA(hString, index, szValue, -1, length, ignoreCase, pResult)
#define NStringCompareRangeW(hString, index, szValue, length, ignoreCase, pResult) NStringCompareRangeStrOrCharsW(hString, index, szValue, -1, length, ignoreCase, pResult)
#define NStringCompareRange(hString, index, szValue, length, ignoreCase, pResult) NStringCompareRangeStrOrChars(hString, index, szValue, -1, length, ignoreCase, pResult)
#define NStringCompareRangeCharsA(hString, index, arValue, valueLength, length, ignoreCase, pResult) NStringCompareRangeStrOrCharsA(hString, index, arValue, valueLength, length, ignoreCase, pResult)
#define NStringCompareRangeCharsW(hString, index, arValue, valueLength, length, ignoreCase, pResult) NStringCompareRangeStrOrCharsW(hString, index, arValue, valueLength, length, ignoreCase, pResult)
#define NStringCompareRangeChars(hString, index, arValue, valueLength, length, ignoreCase, pResult) NStringCompareRangeStrOrChars(hString, index, arValue, valueLength, length, ignoreCase, pResult)

#define NStringCompareNA(hString, hOtherString, ignoreCase, pResult) NStringCompareRangeNA(hString, 0, hOtherString, 0, N_INT_MAX, ignoreCase, pResult)
#define NStringCompareNW(hString, hOtherString, ignoreCase, pResult) NStringCompareRangeNW(hString, 0, hOtherString, 0, N_INT_MAX, ignoreCase, pResult)
#define NStringCompareN(hString, hOtherString, ignoreCase, pResult) NStringCompareRangeN(hString, 0, hOtherString, 0, N_INT_MAX, ignoreCase, pResult)

#define NStringCompareStrOrCharsA(hString, arValue, valueLength, ignoreCase, pResult) NStringCompareRangeStrOrCharsA(hString, 0, arValue, valueLength, N_INT_MAX, ignoreCase, pResult)
#define NStringCompareStrOrCharsW(hString, arValue, valueLength, ignoreCase, pResult) NStringCompareRangeStrOrCharsW(hString, 0, arValue, valueLength, N_INT_MAX, ignoreCase, pResult)
#define NStringCompareStrOrChars(hString, arValue, valueLength, ignoreCase, pResult) NStringCompareRangeStrOrChars(hString, 0, arValue, valueLength, N_INT_MAX, ignoreCase, pResult)

#define NStringCompareA(hString, szValue, ignoreCase, pResult) NStringCompareStrOrCharsA(hString, szValue, -1, ignoreCase, pResult)
#define NStringCompareW(hString, szValue, ignoreCase, pResult) NStringCompareStrOrCharsW(hString, szValue, -1, ignoreCase, pResult)
#define NStringCompare(hString, szValue, ignoreCase, pResult) NStringCompareStrOrChars(hString, szValue, -1, ignoreCase, pResult)
#define NStringCompareCharsA(hString, arValue, valueLength, ignoreCase, pResult) NStringCompareStrOrCharsA(hString, arValue, valueLength, ignoreCase, pResult)
#define NStringCompareCharsW(hString, arValue, valueLength, ignoreCase, pResult) NStringCompareStrOrCharsW(hString, arValue, valueLength, ignoreCase, pResult)
#define NStringCompareChars(hString, arValue, valueLength, ignoreCase, pResult) NStringCompareStrOrChars(hString, arValue, valueLength, ignoreCase, pResult)

NResult N_API NStringEqualsN(HNString hString, HNString hOtherString, NBool ignoreCase, NBool * pResult);

NResult N_API NStringEqualsStrOrCharsA(HNString hString, const NAChar * arValue, NInt valueLength, NBool ignoreCase, NBool * pResult);
#ifndef N_NO_UNICODE
NResult N_API NStringEqualsStrOrCharsW(HNString hString, const NWChar * arValue, NInt valueLength, NBool ignoreCase, NBool * pResult);
#endif
#ifndef N_DOCUMENTATION
NResult N_API NStringEqualsStrOrChars(HNString hString, const NChar * arValue, NInt valueLength, NBool ignoreCase, NBool * pResult);
#endif
#define NStringEqualsStrOrChars N_FUNC_AW(NStringEqualsStrOrChars)

#define NStringEqualsA(hString, szValue, ignoreCase, pResult) NStringEqualsStrOrCharsA(hString, szValue, -1, ignoreCase, pResult)
#define NStringEqualsW(hString, szValue, ignoreCase, pResult) NStringEqualsStrOrCharsW(hString, szValue, -1, ignoreCase, pResult)
#define NStringEquals(hString, szValue, ignoreCase, pResult) NStringEqualsStrOrChars(hString, szValue, -1, ignoreCase, pResult)
#define NStringEqualsCharsA(hString, arValue, valueLength, ignoreCase, pResult) NStringEqualsStrOrCharsA(hString, arValue, valueLength, ignoreCase, pResult)
#define NStringEqualsCharsW(hString, arValue, valueLength, ignoreCase, pResult) NStringEqualsStrOrCharsW(hString, arValue, valueLength, ignoreCase, pResult)
#define NStringEqualsChars(hString, arValue, valueLength, ignoreCase, pResult) NStringEqualsStrOrChars(hString, arValue, valueLength, ignoreCase, pResult)

NResult N_API NStringStartsWithN(HNString hString, HNString hOtherString, NBool ignoreCase, NBool * pResult);

NResult N_API NStringStartsWithStrOrCharsA(HNString hString, const NAChar * arValue, NInt valueLength, NBool ignoreCase, NBool * pResult);
#ifndef N_NO_UNICODE
NResult N_API NStringStartsWithStrOrCharsW(HNString hString, const NWChar * arValue, NInt valueLength, NBool ignoreCase, NBool * pResult);
#endif
#ifndef N_DOCUMENTATION
NResult N_API NStringStartsWithStrOrChars(HNString hString, const NChar * arValue, NInt valueLength, NBool ignoreCase, NBool * pResult);
#endif
#define NStringStartsWithStrOrChars N_FUNC_AW(NStringStartsWithStrOrChars)

#define NStringStartsWithA(hString, szValue, ignoreCase, pResult) NStringStartsWithStrOrCharsA(hString, szValue, -1, ignoreCase, pResult)
#define NStringStartsWithW(hString, szValue, ignoreCase, pResult) NStringStartsWithStrOrCharsW(hString, szValue, -1, ignoreCase, pResult)
#define NStringStartsWith(hString, szValue, ignoreCase, pResult) NStringStartsWithStrOrChars(hString, szValue, -1, ignoreCase, pResult)
#define NStringStartsWithCharsA(hString, arValue, valueLength, ignoreCase, pResult) NStringStartsWithStrOrCharsA(hString, arValue, valueLength, ignoreCase, pResult)
#define NStringStartsWithCharsW(hString, arValue, valueLength, ignoreCase, pResult) NStringStartsWithStrOrCharsW(hString, arValue, valueLength, ignoreCase, pResult)
#define NStringStartsWithChars(hString, arValue, valueLength, ignoreCase, pResult) NStringStartsWithStrOrChars(hString, arValue, valueLength, ignoreCase, pResult)

NResult N_API NStringEndsWithN(HNString hString, HNString hOtherString, NBool ignoreCase, NBool * pResult);

NResult N_API NStringEndsWithStrOrCharsA(HNString hString, const NAChar * arValue, NInt valueLength, NBool ignoreCase, NBool * pResult);
#ifndef N_NO_UNICODE
NResult N_API NStringEndsWithStrOrCharsW(HNString hString, const NWChar * arValue, NInt valueLength, NBool ignoreCase, NBool * pResult);
#endif
#ifndef N_DOCUMENTATION
NResult N_API NStringEndsWithStrOrChars(HNString hString, const NChar * arValue, NInt valueLength, NBool ignoreCase, NBool * pResult);
#endif
#define NStringEndsWithStrOrChars N_FUNC_AW(NStringEndsWithStrOrChars)

#define NStringEndsWithA(hString, szValue, ignoreCase, pResult) NStringEndsWithStrOrCharsA(hString, szValue, -1, ignoreCase, pResult)
#define NStringEndsWithW(hString, szValue, ignoreCase, pResult) NStringEndsWithStrOrCharsW(hString, szValue, -1, ignoreCase, pResult)
#define NStringEndsWith(hString, szValue, ignoreCase, pResult) NStringEndsWithStrOrChars(hString, szValue, -1, ignoreCase, pResult)
#define NStringEndsWithCharsA(hString, arValue, valueLength, ignoreCase, pResult) NStringEndsWithStrOrCharsA(hString, arValue, valueLength, ignoreCase, pResult)
#define NStringEndsWithCharsW(hString, arValue, valueLength, ignoreCase, pResult) NStringEndsWithStrOrCharsW(hString, arValue, valueLength, ignoreCase, pResult)
#define NStringEndsWithChars(hString, arValue, valueLength, ignoreCase, pResult) NStringEndsWithStrOrChars(hString, arValue, valueLength, ignoreCase, pResult)

NResult N_API NStringIndexOfAnyInRangeA(HNString hString, const NAChar * arAnyOf, NInt anyOfLength, NInt startIndex, NInt count, NInt * pIndex);
#ifndef N_NO_UNICODE
NResult N_API NStringIndexOfAnyInRangeW(HNString hString, const NWChar * arAnyOf, NInt anyOfLength, NInt startIndex, NInt count, NInt * pIndex);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NStringIndexOfAnyInRange(HNString hString, const NChar * arAnyOf, NInt anyOfLength, NInt startIndex, NInt count, NInt * pIndex);
#endif
#define NStringIndexOfAnyInRange N_FUNC_AW(NStringIndexOfAnyInRange)

NResult N_API NStringIndexOfAnyFromA(HNString hString, const NAChar * arAnyOf, NInt anyOfLength, NInt startIndex, NInt * pIndex);
#ifndef N_NO_UNICODE
NResult N_API NStringIndexOfAnyFromW(HNString hString, const NWChar * arAnyOf, NInt anyOfLength, NInt startIndex, NInt * pIndex);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NStringIndexOfAnyFrom(HNString hString, const NChar * arAnyOf, NInt anyOfLength, NInt startIndex, NInt * pIndex);
#endif
#define NStringIndexOfAnyFrom N_FUNC_AW(NStringIndexOfAnyFrom)

NResult N_API NStringIndexOfAnyA(HNString hString, const NAChar * arAnyOf, NInt anyOfLength, NInt * pIndex);
#ifndef N_NO_UNICODE
NResult N_API NStringIndexOfAnyW(HNString hString, const NWChar * arAnyOf, NInt anyOfLength, NInt * pIndex);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NStringIndexOfAny(HNString hString, const NChar * arAnyOf, NInt anyOfLength, NInt * pIndex);
#endif
#define NStringIndexOfAny N_FUNC_AW(NStringIndexOfAny)

NResult N_API NStringLastIndexOfAnyInRangeA(HNString hString, const NAChar * arAnyOf, NInt anyOfLength, NInt startIndex, NInt count, NInt * pIndex);
#ifndef N_NO_UNICODE
NResult N_API NStringLastIndexOfAnyInRangeW(HNString hString, const NWChar * arAnyOf, NInt anyOfLength, NInt startIndex, NInt count, NInt * pIndex);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NStringLastIndexOfAnyInRange(HNString hString, const NChar * arAnyOf, NInt anyOfLength, NInt startIndex, NInt count, NInt * pIndex);
#endif
#define NStringLastIndexOfAnyInRange N_FUNC_AW(NStringLastIndexOfAnyInRange)

NResult N_API NStringLastIndexOfAnyFromA(HNString hString, const NAChar * arAnyOf, NInt anyOfLength, NInt startIndex, NInt * pIndex);
#ifndef N_NO_UNICODE
NResult N_API NStringLastIndexOfAnyFromW(HNString hString, const NWChar * arAnyOf, NInt anyOfLength, NInt startIndex, NInt * pIndex);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NStringLastIndexOfAnyFrom(HNString hString, const NChar * arAnyOf, NInt anyOfLength, NInt startIndex, NInt * pIndex);
#endif
#define NStringLastIndexOfAnyFrom N_FUNC_AW(NStringLastIndexOfAnyFrom)

NResult N_API NStringLastIndexOfAnyA(HNString hString, const NAChar * arAnyOf, NInt anyOfLength, NInt * pIndex);
#ifndef N_NO_UNICODE
NResult N_API NStringLastIndexOfAnyW(HNString hString, const NWChar * arAnyOf, NInt anyOfLength, NInt * pIndex);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NStringLastIndexOfAny(HNString hString, const NChar * arAnyOf, NInt anyOfLength, NInt * pIndex);
#endif
#define NStringLastIndexOfAny N_FUNC_AW(NStringLastIndexOfAny)

NResult N_API NStringIndexOfInRangeA(HNString hString, NAChar value, NInt startIndex, NInt count, NInt * pIndex);
#ifndef N_NO_UNICODE
NResult N_API NStringIndexOfInRangeW(HNString hString, NWChar value, NInt startIndex, NInt count, NInt * pIndex);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NStringIndexOfInRange(HNString hString, NChar value, NInt startIndex, NInt count, NInt * pIndex);
#endif
#define NStringIndexOfInRange N_FUNC_AW(NStringIndexOfInRange)

NResult N_API NStringIndexOfFromA(HNString hString, NAChar value, NInt startIndex, NInt * pIndex);
#ifndef N_NO_UNICODE
NResult N_API NStringIndexOfFromW(HNString hString, NWChar value, NInt startIndex, NInt * pIndex);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NStringIndexOfFrom(HNString hString, NChar value, NInt startIndex, NInt * pIndex);
#endif
#define NStringIndexOfFrom N_FUNC_AW(NStringIndexOfFrom)

NResult N_API NStringIndexOfA(HNString hString, NAChar value, NInt * pIndex);
#ifndef N_NO_UNICODE
NResult N_API NStringIndexOfW(HNString hString, NWChar value, NInt * pIndex);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NStringIndexOf(HNString hString, NChar value, NInt * pIndex);
#endif
#define NStringIndexOf N_FUNC_AW(NStringIndexOf)

NResult N_API NStringLastIndexOfInRangeA(HNString hString, NAChar value, NInt startIndex, NInt count, NInt * pIndex);
#ifndef N_NO_UNICODE
NResult N_API NStringLastIndexOfInRangeW(HNString hString, NWChar value, NInt startIndex, NInt count, NInt * pIndex);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NStringLastIndexOfInRange(HNString hString, NChar value, NInt startIndex, NInt count, NInt * pIndex);
#endif
#define NStringLastIndexOfInRange N_FUNC_AW(NStringLastIndexOfInRange)

NResult N_API NStringLastIndexOfFromA(HNString hString, NAChar value, NInt startIndex, NInt * pIndex);
#ifndef N_NO_UNICODE
NResult N_API NStringLastIndexOfFromW(HNString hString, NWChar value, NInt startIndex, NInt * pIndex);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NStringLastIndexOfFrom(HNString hString, NChar value, NInt startIndex, NInt * pIndex);
#endif
#define NStringLastIndexOfFrom N_FUNC_AW(NStringLastIndexOfFrom)

NResult N_API NStringLastIndexOfA(HNString hString, NAChar value, NInt * pIndex);
#ifndef N_NO_UNICODE
NResult N_API NStringLastIndexOfW(HNString hString, NWChar value, NInt * pIndex);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NStringLastIndexOf(HNString hString, NChar value, NInt * pIndex);
#endif
#define NStringLastIndexOf N_FUNC_AW(NStringLastIndexOf)

NResult N_API NStringIndexOfStrInRangeNA(HNString hString, HNString hValue, NInt startIndex, NInt count, NBool ignoreCase, NInt * pIndex);
#ifndef N_NO_UNICODE
NResult N_API NStringIndexOfStrInRangeNW(HNString hString, HNString hValue, NInt startIndex, NInt count, NBool ignoreCase, NInt * pIndex);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NStringIndexOfStrInRangeN(HNString hString, HNString hValue, NInt startIndex, NInt count, NBool ignoreCase, NInt * pIndex);
#endif
#define NStringIndexOfStrInRangeN N_FUNC_AW(NStringIndexOfStrInRangeN)

NResult N_API NStringIndexOfStrFromNA(HNString hString, HNString hValue, NInt startIndex, NBool ignoreCase, NInt * pIndex);
#ifndef N_NO_UNICODE
NResult N_API NStringIndexOfStrFromNW(HNString hString, HNString hValue, NInt startIndex, NBool ignoreCase, NInt * pIndex);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NStringIndexOfStrFromN(HNString hString, HNString hValue, NInt startIndex, NBool ignoreCase, NInt * pIndex);
#endif
#define NStringIndexOfStrFromN N_FUNC_AW(NStringIndexOfStrFromN)

NResult N_API NStringIndexOfStrNA(HNString hString, HNString hValue, NBool ignoreCase, NInt * pIndex);
#ifndef N_NO_UNICODE
NResult N_API NStringIndexOfStrNW(HNString hString, HNString hValue, NBool ignoreCase, NInt * pIndex);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NStringIndexOfStrN(HNString hString, HNString hValue, NBool ignoreCase, NInt * pIndex);
#endif
#define NStringIndexOfStrN N_FUNC_AW(NStringIndexOfStrN)

NResult N_API NStringIndexOfStrOrCharsInRangeA(HNString hString, const NAChar * arValue, NInt valueLength, NInt startIndex, NInt count, NBool ignoreCase, NInt * pIndex);
#ifndef N_NO_UNICODE
NResult N_API NStringIndexOfStrOrCharsInRangeW(HNString hString, const NWChar * arValue, NInt valueLength, NInt startIndex, NInt count, NBool ignoreCase, NInt * pIndex);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NStringIndexOfStrOrCharsInRange(HNString hString, const NChar * arValue, NInt valueLength, NInt startIndex, NInt count, NBool ignoreCase, NInt * pIndex);
#endif
#define NStringIndexOfStrOrCharsInRange N_FUNC_AW(NStringIndexOfStrOrCharsInRange)

#define NStringIndexOfStrInRangeA(hString, szValue, startIndex, count, ignoreCase, pIndex) NStringIndexOfStrOrCharsInRangeA(hString, szValue, -1, startIndex, count, ignoreCase, pIndex)
#define NStringIndexOfStrInRangeW(hString, szValue, startIndex, count, ignoreCase, pIndex) NStringIndexOfStrOrCharsInRangeW(hString, szValue, -1, startIndex, count, ignoreCase, pIndex)
#define NStringIndexOfStrInRange(hString, szValue, startIndex, count, ignoreCase, pIndex) NStringIndexOfStrOrCharsInRange(hString, szValue, -1, startIndex, count, ignoreCase, pIndex)
#define NStringIndexOfCharsInRangeA(hString, arValue, valueLength, startIndex, count, ignoreCase, pIndex) NStringIndexOfStrOrCharsInRangeA(hString, arValue, valueLength, startIndex, count, ignoreCase, pIndex)
#define NStringIndexOfCharsInRangeW(hString, arValue, valueLength, startIndex, count, ignoreCase, pIndex) NStringIndexOfStrOrCharsInRangeW(hString, arValue, valueLength, startIndex, count, ignoreCase, pIndex)
#define NStringIndexOfCharsInRange(hString, arValue, valueLength, startIndex, count, ignoreCase, pIndex) NStringIndexOfStrOrCharsInRange(hString, arValue, valueLength, startIndex, count, ignoreCase, pIndex)

NResult N_API NStringIndexOfStrOrCharsFromA(HNString hString, const NAChar * arValue, NInt valueLength, NInt startIndex, NBool ignoreCase, NInt * pIndex);
#ifndef N_NO_UNICODE
NResult N_API NStringIndexOfStrOrCharsFromW(HNString hString, const NWChar * arValue, NInt valueLength, NInt startIndex, NBool ignoreCase, NInt * pIndex);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NStringIndexOfStrOrCharsFrom(HNString hString, const NChar * arValue, NInt valueLength, NInt startIndex, NBool ignoreCase, NInt * pIndex);
#endif
#define NStringIndexOfStrOrCharsFrom N_FUNC_AW(NStringIndexOfStrOrCharsFrom)

#define NStringIndexOfStrFromA(hString, szValue, startIndex, ignoreCase, pIndex) NStringIndexOfStrOrCharsFromA(hString, szValue, -1, startIndex, ignoreCase, pIndex)
#define NStringIndexOfStrFromW(hString, szValue, startIndex, ignoreCase, pIndex) NStringIndexOfStrOrCharsFromW(hString, szValue, -1, startIndex, ignoreCase, pIndex)
#define NStringIndexOfStrFrom(hString, szValue, startIndex, ignoreCase, pIndex) NStringIndexOfStrOrCharsFrom(hString, szValue, -1, startIndex, ignoreCase, pIndex)
#define NStringIndexOfCharsFromA(hString, arValue, valueLength, startIndex, ignoreCase, pIndex) NStringIndexOfStrOrCharsFromA(hString, arValue, valueLength, startIndex, ignoreCase, pIndex)
#define NStringIndexOfCharsFromW(hString, arValue, valueLength, startIndex, ignoreCase, pIndex) NStringIndexOfStrOrCharsFromW(hString, arValue, valueLength, startIndex, ignoreCase, pIndex)
#define NStringIndexOfCharsFrom(hString, arValue, valueLength, startIndex, ignoreCase, pIndex) NStringIndexOfStrOrCharsFrom(hString, arValue, valueLength, startIndex, ignoreCase, pIndex)

NResult N_API NStringIndexOfStrOrCharsA(HNString hString, const NAChar * arValue, NInt valueLength, NBool ignoreCase, NInt * pIndex);
#ifndef N_NO_UNICODE
NResult N_API NStringIndexOfStrOrCharsW(HNString hString, const NWChar * arValue, NInt valueLength, NBool ignoreCase, NInt * pIndex);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NStringIndexOfStrOrChars(HNString hString, const NChar * arValue, NInt valueLength, NBool ignoreCase, NInt * pIndex);
#endif
#define NStringIndexOfStrOrChars N_FUNC_AW(NStringIndexOfStrOrChars)

#define NStringIndexOfStrA(hString, szValue, ignoreCase, pIndex) NStringIndexOfStrOrCharsA(hString, szValue, -1, ignoreCase, pIndex)
#define NStringIndexOfStrW(hString, szValue, ignoreCase, pIndex) NStringIndexOfStrOrCharsW(hString, szValue, -1, ignoreCase, pIndex)
#define NStringIndexOfStr(hString, szValue, ignoreCase, pIndex) NStringIndexOfStrOrChars(hString, szValue, -1, ignoreCase, pIndex)
#define NStringIndexOfCharsA(hString, arValue, valueLength, ignoreCase, pIndex) NStringIndexOfStrOrCharsA(hString, arValue, valueLength, ignoreCase, pIndex)
#define NStringIndexOfCharsW(hString, arValue, valueLength, ignoreCase, pIndex) NStringIndexOfStrOrCharsW(hString, arValue, valueLength, ignoreCase, pIndex)
#define NStringIndexOfChars(hString, arValue, valueLength, ignoreCase, pIndex) NStringIndexOfStrOrChars(hString, arValue, valueLength, ignoreCase, pIndex)

NResult N_API NStringLastIndexOfStrInRangeNA(HNString hString, HNString hValue, NInt startIndex, NInt count, NBool ignoreCase, NInt * pIndex);
#ifndef N_NO_UNICODE
NResult N_API NStringLastIndexOfStrInRangeNW(HNString hString, HNString hValue, NInt startIndex, NInt count, NBool ignoreCase, NInt * pIndex);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NStringLastIndexOfStrInRangeN(HNString hString, HNString hValue, NInt startIndex, NInt count, NBool ignoreCase, NInt * pIndex);
#endif
#define NStringLastIndexOfStrInRangeN N_FUNC_AW(NStringLastIndexOfStrInRangeN)

NResult N_API NStringLastIndexOfStrFromNA(HNString hString, HNString hValue, NInt startIndex, NBool ignoreCase, NInt * pIndex);
#ifndef N_NO_UNICODE
NResult N_API NStringLastIndexOfStrFromNW(HNString hString, HNString hValue, NInt startIndex, NBool ignoreCase, NInt * pIndex);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NStringLastIndexOfStrFromN(HNString hString, HNString hValue, NInt startIndex, NBool ignoreCase, NInt * pIndex);
#endif
#define NStringLastIndexOfStrFromN N_FUNC_AW(NStringLastIndexOfStrFromN)

NResult N_API NStringLastIndexOfStrNA(HNString hString, HNString hValue, NBool ignoreCase, NInt * pIndex);
#ifndef N_NO_UNICODE
NResult N_API NStringLastIndexOfStrNW(HNString hString, HNString hValue, NBool ignoreCase, NInt * pIndex);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NStringLastIndexOfStrN(HNString hString, HNString hValue, NBool ignoreCase, NInt * pIndex);
#endif
#define NStringLastIndexOfStrN N_FUNC_AW(NStringLastIndexOfStrN)

NResult N_API NStringLastIndexOfStrOrCharsInRangeA(HNString hString, const NAChar * arValue, NInt valueLength, NInt startIndex, NInt count, NBool ignoreCase, NInt * pIndex);
#ifndef N_NO_UNICODE
NResult N_API NStringLastIndexOfStrOrCharsInRangeW(HNString hString, const NWChar * arValue, NInt valueLength, NInt startIndex, NInt count, NBool ignoreCase, NInt * pIndex);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NStringLastIndexOfStrOrCharsInRange(HNString hString, const NChar * arValue, NInt valueLength, NInt startIndex, NInt count, NBool ignoreCase, NInt * pIndex);
#endif
#define NStringLastIndexOfStrOrCharsInRange N_FUNC_AW(NStringLastIndexOfStrOrCharsInRange)

#define NStringLastIndexOfStrInRangeA(hString, szValue, startIndex, count, ignoreCase, pIndex) NStringLastIndexOfStrOrCharsInRangeA(hString, szValue, -1, startIndex, count, ignoreCase, pIndex)
#define NStringLastIndexOfStrInRangeW(hString, szValue, startIndex, count, ignoreCase, pIndex) NStringLastIndexOfStrOrCharsInRangeW(hString, szValue, -1, startIndex, count, ignoreCase, pIndex)
#define NStringLastIndexOfStrInRange(hString, szValue, startIndex, count, ignoreCase, pIndex) NStringLastIndexOfStrOrCharsInRange(hString, szValue, -1, startIndex, count, ignoreCase, pIndex)
#define NStringLastIndexOfCharsInRangeA(hString, arValue, valueLength, startIndex, count, ignoreCase, pIndex) NStringLastIndexOfStrOrCharsInRangeA(hString, arValue, valueLength, startIndex, count, ignoreCase, pIndex)
#define NStringLastIndexOfCharsInRangeW(hString, arValue, valueLength, startIndex, count, ignoreCase, pIndex) NStringLastIndexOfStrOrCharsInRangeW(hString, arValue, valueLength, startIndex, count, ignoreCase, pIndex)
#define NStringLastIndexOfCharsInRange(hString, arValue, valueLength, startIndex, count, ignoreCase, pIndex) NStringLastIndexOfStrOrCharsInRange(hString, arValue, valueLength, startIndex, count, ignoreCase, pIndex)

NResult N_API NStringLastIndexOfStrOrCharsFromA(HNString hString, const NAChar * arValue, NInt valueLength, NInt startIndex, NBool ignoreCase, NInt * pIndex);
#ifndef N_NO_UNICODE
NResult N_API NStringLastIndexOfStrOrCharsFromW(HNString hString, const NWChar * arValue, NInt valueLength, NInt startIndex, NBool ignoreCase, NInt * pIndex);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NStringLastIndexOfStrOrCharsFrom(HNString hString, const NChar * arValue, NInt valueLength, NInt startIndex, NBool ignoreCase, NInt * pIndex);
#endif
#define NStringLastIndexOfStrOrCharsFrom N_FUNC_AW(NStringLastIndexOfStrOrCharsFrom)

#define NStringLastIndexOfStrFromA(hString, szValue, startIndex, ignoreCase, pIndex) NStringLastIndexOfStrOrCharsFromA(hString, szValue, -1, startIndex, ignoreCase, pIndex)
#define NStringLastIndexOfStrFromW(hString, szValue, startIndex, ignoreCase, pIndex) NStringLastIndexOfStrOrCharsFromW(hString, szValue, -1, startIndex, ignoreCase, pIndex)
#define NStringLastIndexOfStrFrom(hString, szValue, startIndex, ignoreCase, pIndex) NStringLastIndexOfStrOrCharsFrom(hString, szValue, -1, startIndex, ignoreCase, pIndex)
#define NStringLastIndexOfCharsFromA(hString, arValue, valueLength, startIndex, ignoreCase, pIndex) NStringLastIndexOfStrOrCharsFromA(hString, arValue, valueLength, startIndex, ignoreCase, pIndex)
#define NStringLastIndexOfCharsFromW(hString, arValue, valueLength, startIndex, ignoreCase, pIndex) NStringLastIndexOfStrOrCharsFromW(hString, arValue, valueLength, startIndex, ignoreCase, pIndex)
#define NStringLastIndexOfCharsFrom(hString, arValue, valueLength, startIndex, ignoreCase, pIndex) NStringLastIndexOfStrOrCharsFrom(hString, arValue, valueLength, startIndex, ignoreCase, pIndex)

NResult N_API NStringLastIndexOfStrOrCharsA(HNString hString, const NAChar * arValue, NInt valueLength, NBool ignoreCase, NInt * pIndex);
#ifndef N_NO_UNICODE
NResult N_API NStringLastIndexOfStrOrCharsW(HNString hString, const NWChar * arValue, NInt valueLength, NBool ignoreCase, NInt * pIndex);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NStringLastIndexOfStrOrChars(HNString hString, const NChar * arValue, NInt valueLength, NBool ignoreCase, NInt * pIndex);
#endif
#define NStringLastIndexOfStrOrChars N_FUNC_AW(NStringLastIndexOfStrOrChars)

#define NStringLastIndexOfStrA(hString, szValue, ignoreCase, pIndex) NStringLastIndexOfStrOrCharsA(hString, szValue, -1, ignoreCase, pIndex)
#define NStringLastIndexOfStrW(hString, szValue, ignoreCase, pIndex) NStringLastIndexOfStrOrCharsW(hString, szValue, -1, ignoreCase, pIndex)
#define NStringLastIndexOfStr(hString, szValue, ignoreCase, pIndex) NStringLastIndexOfStrOrChars(hString, szValue, -1, ignoreCase, pIndex)
#define NStringLastIndexOfCharsA(hString, arValue, valueLength, ignoreCase, pIndex) NStringLastIndexOfStrOrCharsA(hString, arValue, valueLength, ignoreCase, pIndex)
#define NStringLastIndexOfCharsW(hString, arValue, valueLength, ignoreCase, pIndex) NStringLastIndexOfStrOrCharsW(hString, arValue, valueLength, ignoreCase, pIndex)
#define NStringLastIndexOfChars(hString, arValue, valueLength, ignoreCase, pIndex) NStringLastIndexOfStrOrChars(hString, arValue, valueLength, ignoreCase, pIndex)

NResult N_API NStringContainsStrN(HNString hString, HNString hValue, NBool * pResult);

NResult N_API NStringContainsStrOrCharsA(HNString hString, const NAChar * arValue, NInt valueLength, NBool * pResult);
#ifndef N_NO_UNICODE
NResult N_API NStringContainsStrOrCharsW(HNString hString, const NWChar * arValue, NInt valueLength, NBool * pResult);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NStringContainsStrOrChars(HNString hString, const NChar * arValue, NInt valueLength, NBool * pResult);
#endif
#define NStringContainsStrOrChars N_FUNC_AW(NStringContainsStrOrChars)

#define NStringContainsStrA(hString, szValue, pResult) NStringContainsStrOrCharsA(hString, szValue, -1, pResult)
#define NStringContainsStrW(hString, szValue, pResult) NStringContainsStrOrCharsW(hString, szValue, -1, pResult)
#define NStringContainsStr(hString, szValue, pResult) NStringContainsStrOrChars(hString, szValue, -1, pResult)
#define NStringContainsCharsA(hString, arValue, valueLength, pResult) NStringContainsStrOrCharsA(hString, arValue, valueLength, pResult)
#define NStringContainsCharsW(hString, arValue, valueLength, pResult) NStringContainsStrOrCharsW(hString, arValue, valueLength, pResult)
#define NStringContainsChars(hString, arValue, valueLength, pResult) NStringContainsStrOrChars(hString, arValue, valueLength, pResult)

NResult N_API NStringSplitWithCountA(HNString hString, const NAChar * arSeparators, NInt separatorCount, NInt count, NBool removeEmptyEntries, HNString * * parhValues, NInt * pValueCount);
#ifndef N_NO_UNICODE
NResult N_API NStringSplitWithCountW(HNString hString, const NWChar * arSeparators, NInt separatorCount, NInt count, NBool removeEmptyEntries, HNString * * parhValues, NInt * pValueCount);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NStringSplitWithCount(HNString hString, const NChar * arSeparators, NInt separatorCount, NInt count, NBool removeEmptyEntries, HNString * * parhValues, NInt * pValueCount);
#endif
#define NStringSplitWithCount N_FUNC_AW(NStringSplitWithCount)

#define NStringSplitA(hString, arSeparators, separatorCount, removeEmptyEntries, parhValues, pValueCount) NStringSplitWithCountA(hString, arSeparators, separatorCount, N_INT_MAX, removeEmptyEntries, parhValues, pValueCount)
#define NStringSplitW(hString, arSeparators, separatorCount, removeEmptyEntries, parhValues, pValueCount) NStringSplitWithCountW(hString, arSeparators, separatorCount, N_INT_MAX, removeEmptyEntries, parhValues, pValueCount)
#define NStringSplit(hString, arSeparators, separatorCount, removeEmptyEntries, parhValues, pValueCount) NStringSplitWithCount(hString, arSeparators, separatorCount, N_INT_MAX, removeEmptyEntries, parhValues, pValueCount)

NResult N_API NStringSplitWithStrsAndCountN(HNString hString, const HNString * arhSeparators, NInt separatorCount, NInt count, NBool removeEmptyEntries, HNString * * parhValues, NInt * pValueCount);
#define NStringSplitWithStrsN(hString, arhSeparators, separatorCount, removeEmptyEntries, parhValues, pValueCount) NStringSplitWithStrsAndCountN(hString, arhSeparators, separatorCount, N_INT_MAX, removeEmptyEntries, parhValues, pValueCount)

NResult N_API NStringSplitWithStrsAndCountA(HNString hString, const NAChar * const * arszSeparators, NInt separatorCount, NInt count, NBool removeEmptyEntries, HNString * * parhValues, NInt * pValueCount);
#ifndef N_NO_UNICODE
NResult N_API NStringSplitWithStrsAndCountW(HNString hString, const NWChar * const * arszSeparators, NInt separatorCount, NInt count, NBool removeEmptyEntries, HNString * * parhValues, NInt * pValueCount);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NStringSplitWithStrsAndCount(HNString hString, const NChar * const * arszSeparators, NInt separatorCount, NInt count, NBool removeEmptyEntries, HNString * * parhValues, NInt * pValueCount);
#endif
#define NStringSplitWithStrsAndCount N_FUNC_AW(NStringSplitWithStrsAndCount)

#define NStringSplitWithStrsA(hString, arszSeparators, separatorCount, removeEmptyEntries, parhValues, pValueCount) NStringSplitWithStrsAndCountA(hString, arszSeparators, separatorCount, N_INT_MAX, removeEmptyEntries, parhValues, pValueCount)
#define NStringSplitWithStrsW(hString, arszSeparators, separatorCount, removeEmptyEntries, parhValues, pValueCount) NStringSplitWithStrsAndCountW(hString, arszSeparators, separatorCount, N_INT_MAX, removeEmptyEntries, parhValues, pValueCount)
#define NStringSplitWithStrs(hString, arszSeparators, separatorCount, removeEmptyEntries, parhValues, pValueCount) NStringSplitWithStrsAndCount(hString, arszSeparators, separatorCount, N_INT_MAX, removeEmptyEntries, parhValues, pValueCount)

NResult N_API NStringCopyToStrOrCharsA(HNString hString, NInt sourceIndex, NAChar * arValue, NInt valueLength, NBool nullTerminate, NInt count);
#ifndef N_NO_UNICODE
NResult N_API NStringCopyToStrOrCharsW(HNString hString, NInt sourceIndex, NWChar * arValue, NInt valueLength, NBool nullTerminate, NInt count);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NStringCopyToStrOrChars(HNString hString, NInt sourceIndex, NChar * arValue, NInt valueLength, NBool nullTerminate, NInt count);
#endif
#define NStringCopyToStrOrChars N_FUNC_AW(NStringCopyToStrOrChars)

#define NStringCopyToStringA(hString, sourceIndex, szValue, valueSize, count) NStringCopyToStrOrCharsA(hString, sourceIndex, szValue, valueSize, NTrue, count)
#define NStringCopyToStringW(hString, sourceIndex, szValue, valueSize, count) NStringCopyToStrOrCharsW(hString, sourceIndex, szValue, valueSize, NTrue, count)
#define NStringCopyToString(hString, sourceIndex, szValue, valueSize, count) NStringCopyToStrOrChars(hString, sourceIndex, szValue, valueSize, NTrue, count)

#define NStringCopyToA(hString, sourceIndex, arValue, valueLength, count) NStringCopyToStrOrCharsA(hString, sourceIndex, arValue, valueLength, NFalse, count)
#define NStringCopyToW(hString, sourceIndex, arValue, valueLength, count) NStringCopyToStrOrCharsW(hString, sourceIndex, arValue, valueLength, NFalse, count)
#define NStringCopyTo(hString, sourceIndex, arValue, valueLength, count) NStringCopyToStrOrChars(hString, sourceIndex, arValue, valueLength, NFalse, count)

NResult N_API NStringToStringN(HNString hString, HNString hFormat, HNString * phValue);
NResult N_API NStringToStringA(HNString hString, const NAChar * szFormat, HNString * phValue);
#ifndef N_NO_UNICODE
NResult N_API NStringToStringW(HNString hString, const NWChar * szFormat, HNString * phValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NStringToString(HNString hString, const NChar * szFormat, HNString * phValue);
#endif
#define NStringToString N_FUNC_AW(NStringToString)

N_DEPRECATED("function is deprecated, do not use")
NResult N_API NStringToStringOldA(HNString hString, NAChar * szValue, NInt valueSize);
#ifndef N_NO_UNICODE
N_DEPRECATED("function is deprecated, do not use")
NResult N_API NStringToStringOldW(HNString hString, NWChar * szValue, NInt valueSize);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NStringToStringOld(HNString hString, NChar * szValue, NInt valueSize);
#endif
#define NStringToStringOld N_FUNC_AW(NStringToStringOld)

NResult N_API NStringToStrOrCharArrayA(HNString hString, NBool nullTerminate, NAChar * * parValues, NInt * pLength);
#ifndef N_NO_UNICODE
NResult N_API NStringToStrOrCharArrayW(HNString hString, NBool nullTerminate, NWChar * * parValues, NInt * pLength);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NStringToStrOrCharArray(HNString hString, NBool nullTerminate, NChar * * parValues, NInt * pLength);
#endif
#define NStringToStrOrCharArray N_FUNC_AW(NStringToStrOrCharArray)

#define NStringToNewStringA(hString, pszValue, pLength) NStringToStrOrCharArrayA(hString, NTrue, pszValue, pLength)
#define NStringToNewStringW(hString, pszValue, pLength) NStringToStrOrCharArrayW(hString, NTrue, pszValue, pLength)
#define NStringToNewString(hString, pszValue, pLength) NStringToStrOrCharArray(hString, NTrue, pszValue, pLength)
#define NStringToCharArrayA(hString, parValue, pLength) NStringToStrOrCharArrayA(hString, NFalse, parValue, pLength)
#define NStringToCharArrayW(hString, parValue, pLength) NStringToStrOrCharArrayW(hString, NFalse, parValue, pLength)
#define NStringToCharArray(hString, parValue, pLength) NStringToStrOrCharArray(hString, NFalse, parValue, pLength)

NResult N_API NStringToStrOrCharArrayRangeA(HNString hString, NBool nullTerminate, NInt startIndex, NInt length, NAChar * * parValues, NInt * pLength);
#ifndef N_NO_UNICODE
NResult N_API NStringToStrOrCharArrayRangeW(HNString hString, NBool nullTerminate, NInt startIndex, NInt length, NWChar * * parValues, NInt * pLength);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NStringToStrOrCharArrayRange(HNString hString, NBool nullTerminate, NInt startIndex, NInt length, NChar * * parValues, NInt * pLength);
#endif
#define NStringToStrOrCharArrayRange N_FUNC_AW(NStringToStrOrCharArrayRange)

#define NStringToNewStringRangeA(hString, startIndex, length, pszValue, pLength) NStringToStrOrCharArrayRangeA(hString, NTrue, startIndex, length, pszValue, pLength)
#define NStringToNewStringRangeW(hString, startIndex, length, pszValue, pLength) NStringToStrOrCharArrayRangeW(hString, NTrue, startIndex, length, pszValue, pLength)
#define NStringToNewStringRange(hString, startIndex, length, pszValue, pLength) NStringToStrOrCharArrayRange(hString, NTrue, startIndex, length, pszValue, pLength)
#define NStringToCharArrayRangeA(hString, startIndex, length, parValue, pLength) NStringToStrOrCharArrayRangeA(hString, NFalse, startIndex, length, parValue, pLength)
#define NStringToCharArrayRangeW(hString, startIndex, length, parValue, pLength) NStringToStrOrCharArrayRangeW(hString, NFalse, startIndex, length, parValue, pLength)
#define NStringToCharArrayRange(hString, startIndex, length, parValue, pLength) NStringToStrOrCharArrayRange(hString, NFalse, startIndex, length, parValue, pLength)

NResult N_API NStringInsertNA(HNString hString, NInt index, HNString hValue, HNString * phResultString);
#ifndef N_NO_UNICODE
NResult N_API NStringInsertNW(HNString hString, NInt index, HNString hValue, HNString * phResultString);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NStringInsertN(HNString hString, NInt index, HNString hValue, HNString * phResultString);
#endif
#define NStringInsertN N_FUNC_AW(NStringInsertN)

NResult N_API NStringInsertStrOrCharsA(HNString hString, NInt index, const NAChar * arValue, NInt valueLength, HNString * phResultString);
#ifndef N_NO_UNICODE
NResult N_API NStringInsertStrOrCharsW(HNString hString, NInt index, const NWChar * arValue, NInt valueLength, HNString * phResultString);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NStringInsertStrOrChars(HNString hString, NInt index, const NChar * arValue, NInt valueLength, HNString * phResultString);
#endif
#define NStringInsertStrOrChars N_FUNC_AW(NStringInsertStrOrChars)

#define NStringInsertA(hString, index, szValue, phResultString) NStringInsertStrOrCharsA(hString, index, szValue, -1, phResultString)
#define NStringInsertW(hString, index, szValue, phResultString) NStringInsertStrOrCharsW(hString, index, szValue, -1, phResultString)
#define NStringInsert(hString, index, szValue, phResultString) NStringInsertStrOrChars(hString, index, szValue, -1, phResultString)
#define NStringInsertCharsA(hString, index, arValue, valueLength, phResultString) NStringInsertStrOrCharsA(hString, index, arValue, valueLength, phResultString)
#define NStringInsertCharsW(hString, index, arValue, valueLength, phResultString) NStringInsertStrOrCharsW(hString, index, arValue, valueLength, phResultString)
#define NStringInsertChars(hString, index, arValue, valueLength, phResultString) NStringInsertStrOrChars(hString, index, arValue, valueLength, phResultString)

NResult N_API NStringRemoveA(HNString hString, NInt startIndex, NInt count, HNString * phResultString);
#ifndef N_NO_UNICODE
NResult N_API NStringRemoveW(HNString hString, NInt startIndex, NInt count, HNString * phResultString);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NStringRemove(HNString hString, NInt startIndex, NInt count, HNString * phResultString);
#endif
#define NStringRemove N_FUNC_AW(NStringRemove)

NResult N_API NStringRemoveFromA(HNString hString, NInt startIndex, HNString * phResultString);
#ifndef N_NO_UNICODE
NResult N_API NStringRemoveFromW(HNString hString, NInt startIndex, HNString * phResultString);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NStringRemoveFrom(HNString hString, NInt startIndex, HNString * phResultString);
#endif
#define NStringRemoveFrom N_FUNC_AW(NStringRemoveFrom)

NResult N_API NStringSubstringA(HNString hString, NInt startIndex, NInt length, HNString * phResultString);
#ifndef N_NO_UNICODE
NResult N_API NStringSubstringW(HNString hString, NInt startIndex, NInt length, HNString * phResultString);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NStringSubstring(HNString hString, NInt startIndex, NInt length, HNString * phResultString);
#endif
#define NStringSubstring N_FUNC_AW(NStringSubstring)

NResult N_API NStringSubstringFromA(HNString hString, NInt startIndex, HNString * phResultString);
#ifndef N_NO_UNICODE
NResult N_API NStringSubstringFromW(HNString hString, NInt startIndex, HNString * phResultString);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NStringSubstringFrom(HNString hString, NInt startIndex, HNString * phResultString);
#endif
#define NStringSubstringFrom N_FUNC_AW(NStringSubstringFrom)

NResult N_API NStringTrim(HNString hString, HNString * phResultString);
NResult N_API NStringTrimStart(HNString hString, HNString * phResultString);
NResult N_API NStringTrimEnd(HNString hString, HNString * phResultString);

NResult N_API NStringTrimAnyA(HNString hString, const NAChar * arChars, NInt charCount, HNString * phResultString);
#ifndef N_NO_UNICODE
NResult N_API NStringTrimAnyW(HNString hString, const NWChar * arChars, NInt charCount, HNString * phResultString);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NStringTrimAny(HNString hString, const NChar * arChars, NInt charCount, HNString * phResultString);
#endif
#define NStringTrimAny N_FUNC_AW(NStringTrimAny)

NResult N_API NStringTrimStartAnyA(HNString hString, const NAChar * arChars, NInt charCount, HNString * phResultString);
#ifndef N_NO_UNICODE
NResult N_API NStringTrimStartAnyW(HNString hString, const NWChar * arChars, NInt charCount, HNString * phResultString);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NStringTrimStartAny(HNString hString, const NChar * arChars, NInt charCount, HNString * phResultString);
#endif
#define NStringTrimStartAny N_FUNC_AW(NStringTrimStartAny)

NResult N_API NStringTrimEndAnyA(HNString hString, const NAChar * arChars, NInt charCount, HNString * phResultString);
#ifndef N_NO_UNICODE
NResult N_API NStringTrimEndAnyW(HNString hString, const NWChar * arChars, NInt charCount, HNString * phResultString);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NStringTrimEndAny(HNString hString, const NChar * arChars, NInt charCount, HNString * phResultString);
#endif
#define NStringTrimEndAny N_FUNC_AW(NStringTrimEndAny)

NResult N_API NStringPadLeftA(HNString hString, NInt totalWidth, HNString * phResultString);
#ifndef N_NO_UNICODE
NResult N_API NStringPadLeftW(HNString hString, NInt totalWidth, HNString * phResultString);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NStringPadLeft(HNString hString, NInt totalWidth, HNString * phResultString);
#endif
#define NStringPadLeft N_FUNC_AW(NStringPadLeft)

NResult N_API NStringPadRightA(HNString hString, NInt totalWidth, HNString * phResultString);
#ifndef N_NO_UNICODE
NResult N_API NStringPadRightW(HNString hString, NInt totalWidth, HNString * phResultString);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NStringPadRight(HNString hString, NInt totalWidth, HNString * phResultString);
#endif
#define NStringPadRight N_FUNC_AW(NStringPadRight)

NResult N_API NStringPadLeftWithA(HNString hString, NInt totalWidth, NAChar paddingChar, HNString * phResultString);
#ifndef N_NO_UNICODE
NResult N_API NStringPadLeftWithW(HNString hString, NInt totalWidth, NWChar paddingChar, HNString * phResultString);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NStringPadLeftWith(HNString hString, NInt totalWidth, NChar paddingChar, HNString * phResultString);
#endif
#define NStringPadLeftWith N_FUNC_AW(NStringPadLeftWith)

NResult N_API NStringPadRightWithA(HNString hString, NInt totalWidth, NAChar paddingChar, HNString * phResultString);
#ifndef N_NO_UNICODE
NResult N_API NStringPadRightWithW(HNString hString, NInt totalWidth, NWChar paddingChar, HNString * phResultString);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NStringPadRightWith(HNString hString, NInt totalWidth, NChar paddingChar, HNString * phResultString);
#endif
#define NStringPadRightWith N_FUNC_AW(NStringPadRightWith)

NResult N_API NStringReplaceA(HNString hString, NAChar oldChar, NAChar newChar, HNString * phResultString);
#ifndef N_NO_UNICODE
NResult N_API NStringReplaceW(HNString hString, NWChar oldChar, NWChar newChar, HNString * phResultString);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NStringReplace(HNString hString, NChar oldChar, NChar newChar, HNString * phResultString);
#endif
#define NStringReplace N_FUNC_AW(NStringReplace)

NResult N_API NStringReplaceStrN(HNString hString, HNString hOldValue, HNString hNewValue, HNString * phResultString);

NResult N_API NStringReplaceStrOrCharsA(HNString hString, const NAChar * arOldValue, NInt oldValueLength, const NAChar * arNewValue, NInt newValueLength, HNString * phResultString);
#ifndef N_NO_UNICODE
NResult N_API NStringReplaceStrOrCharsW(HNString hString, const NWChar * arOldValue, NInt oldValueLength, const NWChar * arNewValue, NInt newValueLength, HNString * phResultString);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NStringReplaceStrOrChars(HNString hString, const NChar * arOldValue, NInt oldValueLength, const NChar * arNewValue, NInt newValueLength, HNString * phResultString);
#endif
#define NStringReplaceStrOrChars N_FUNC_AW(NStringReplaceStrOrChars)

#define NStringReplaceStrA(hString, szOldValue, szNewValue, phResultString) NStringReplaceStrOrCharsA(hString, szOldValue, -1, szNewValue, -1, phResultString)
#define NStringReplaceStrW(hString, szOldValue, szNewValue, phResultString) NStringReplaceStrOrCharsW(hString, szOldValue, -1, szNewValue, -1, phResultString)
#define NStringReplaceStr(hString, szOldValue, szNewValue, phResultString) NStringReplaceStrOrChars(hString, szOldValue, -1, szNewValue, -1, phResultString)
#define NStringReplaceCharsA(hString, arOldValue, oldValueLength, arNewValue, newValueLength, phResultString) NStringReplaceStrOrCharsA(hString, arOldValue, oldValueLength, arNewValue, newValueLength, phResultString)
#define NStringReplaceCharsW(hString, arOldValue, oldValueLength, arNewValue, newValueLength, phResultString) NStringReplaceStrOrCharsW(hString, arOldValue, oldValueLength, arNewValue, newValueLength, phResultString)
#define NStringReplaceChars(hString, arOldValue, oldValueLength, arNewValue, newValueLength, phResultString) NStringReplaceStrOrChars(hString, arOldValue, oldValueLength, arNewValue, newValueLength, phResultString)

NResult N_API NStringToLower(HNString hString, HNString * phResultString);
NResult N_API NStringToUpper(HNString hString, HNString * phResultString);

NResult N_API NStringConcatN(HNString hValue1, HNString hValue2, HNString * phResultString);

NResult N_API NStringConcatStrOrCharsA(const NAChar * arValue1, NInt value1Length, const NAChar * arValue2, NInt value2Length, HNString * phResultString);
#ifndef N_NO_UNICODE
NResult N_API NStringConcatStrOrCharsW(const NWChar * arValue1, NInt value1Length, const NWChar * arValue2, NInt value2Length, HNString * phResultString);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NStringConcatStrOrChars(const NChar * arValue1, NInt value1Length, const NChar * arValue2, NInt value2Length, HNString * phResultString);
#endif
#define NStringConcatStrOrChars N_FUNC_AW(NStringConcatStrOrChars)

#define NStringConcatA(szValue1, szValue2, phResultString) NStringConcatStrOrCharsA(szValue1, -1, szValue2, -1, phResultString)
#define NStringConcatW(szValue1, szValue2, phResultString) NStringConcatStrOrCharsW(szValue1, -1, szValue2, -1, phResultString)
#define NStringConcat(szValue1, szValue2, phResultString) NStringConcatStrOrChars(szValue1, -1, szValue2, -1, phResultString)
#define NStringConcatCharsA(arValue1, value1Length, arValue2, value2Length, phResultString) NStringConcatStrOrCharsA(arValue1, value1Length, arValue2, value2Length, phResultString)
#define NStringConcatCharsW(arValue1, value1Length, arValue2, value2Length, phResultString) NStringConcatStrOrCharsW(arValue1, value1Length, arValue2, value2Length, phResultString)
#define NStringConcatChars(arValue1, value1Length, arValue2, value2Length, phResultString) NStringConcatStrOrChars(arValue1, value1Length, arValue2, value2Length, phResultString)

NResult N_API NStringPrependStrOrCharsA(HNString hString, const NAChar * arValue, NInt valueLength, HNString * phResultString);
#ifndef N_NO_UNICODE
NResult N_API NStringPrependStrOrCharsW(HNString hString, const NWChar * arValue, NInt valueLength, HNString * phResultString);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NStringPrependStrOrChars(HNString hString, const NChar * arValue, NInt valueLength, HNString * phResultString);
#endif
#define NStringPrependStrOrChars N_FUNC_AW(NStringPrependStrOrChars)

#define NStringPrependA(hString, szValue, phResultString) NStringPrependStrOrCharsA(hString, szValue, -1, phResultString)
#define NStringPrependW(hString, szValue, phResultString) NStringPrependStrOrCharsW(hString, szValue, -1, phResultString)
#define NStringPrepend(hString, szValue, phResultString) NStringPrependStrOrChars(hString, szValue, -1, phResultString)
#define NStringPrependCharsA(hString, arValue, valueLength, phResultString) NStringPrependStrOrCharsA(hString, arValue, valueLength, phResultString)
#define NStringPrependCharsW(hString, arValue, valueLength, phResultString) NStringPrependStrOrCharsW(hString, arValue, valueLength, phResultString)
#define NStringPrependChars(hString, arValue, valueLength, phResultString) NStringPrependStrOrChars(hString, arValue, valueLength, phResultString)

NResult N_API NStringAppendStrOrCharsA(HNString hString, const NAChar * arValue, NInt valueLength, HNString * phResultString);
#ifndef N_NO_UNICODE
NResult N_API NStringAppendStrOrCharsW(HNString hString, const NWChar * arValue, NInt valueLength, HNString * phResultString);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NStringAppendStrOrChars(HNString hString, const NChar * arValue, NInt valueLength, HNString * phResultString);
#endif
#define NStringAppendStrOrChars N_FUNC_AW(NStringAppendStrOrChars)

#define NStringAppendA(hString, szValue, phResultString) NStringAppendStrOrCharsA(hString, szValue, -1, phResultString)
#define NStringAppendW(hString, szValue, phResultString) NStringAppendStrOrCharsW(hString, szValue, -1, phResultString)
#define NStringAppend(hString, szValue, phResultString) NStringAppendStrOrChars(hString, szValue, -1, phResultString)
#define NStringAppendCharsA(hString, arValue, valueLength, phResultString) NStringAppendStrOrCharsA(hString, arValue, valueLength, phResultString)
#define NStringAppendCharsW(hString, arValue, valueLength, phResultString) NStringAppendStrOrCharsW(hString, arValue, valueLength, phResultString)
#define NStringAppendChars(hString, arValue, valueLength, phResultString) NStringAppendStrOrChars(hString, arValue, valueLength, phResultString)

NResult N_API NStringConcatArrayN(const HNString * arhValues, NInt count, HNString * phResultString);

NResult N_API NStringConcatArrayA(const NAChar * const * arszValues, NInt count, HNString * phResultString);
#ifndef N_NO_UNICODE
NResult N_API NStringConcatArrayW(const NWChar * const * arszValues, NInt count, HNString * phResultString);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NStringConcatArray(const NChar * const * arszValues, NInt count, HNString * phResultString);
#endif
#define NStringConcatArray N_FUNC_AW(NStringConcatArray)

NResult N_API NStringConcatManyVAN(HNString * phResultString, NInt count, va_list args);

NResult N_API NStringConcatManyVAA(HNString * phResultString, NInt count, va_list args);
#ifndef N_NO_UNICODE
NResult N_API NStringConcatManyVAW(HNString * phResultString, NInt count, va_list args);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NStringConcatManyVA(HNString * phResultString, NInt count, va_list args);
#endif
#define NStringConcatManyVA N_FUNC_AW(NStringConcatManyVA)

NResult N_API NStringConcatManyN(HNString * phResultString, NInt count, ...);

NResult N_API NStringConcatManyA(HNString * phResultString, NInt count, ...);
#ifndef N_NO_UNICODE
NResult N_API NStringConcatManyW(HNString * phResultString, NInt count, ...);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NStringConcatMany(HNString * phResultString, NInt count, ... multipleParameters);
#endif
#define NStringConcatMany N_FUNC_AW(NStringConcatMany)

NResult N_API NStringJoinArrayN(HNString hSeparator, const HNString * arhValues, NInt count, HNString * phResultString);

NResult N_API NStringJoinArrayVNA(const NAChar * szSeparator, const HNString * arhValues, NInt count, HNString * phResultString);
#ifndef N_NO_UNICODE
NResult N_API NStringJoinArrayVNW(const NWChar * szSeparator, const HNString * arhValues, NInt count, HNString * phResultString);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NStringJoinArrayVN(const NChar * szSeparator, const HNString * arhValues, NInt count, HNString * phResultString);
#endif
#define NStringJoinArrayVN N_FUNC_AW(NStringJoinArrayVN)

NResult N_API NStringJoinArrayA(const NAChar * szSeparator, const NAChar * const * arszValues, NInt count, HNString * phResultString);
#ifndef N_NO_UNICODE
NResult N_API NStringJoinArrayW(const NWChar * szSeparator, const NWChar * const * arszValues, NInt count, HNString * phResultString);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NStringJoinArray(const NChar * szSeparator, const NChar * const * arszValues, NInt count, HNString * phResultString);
#endif
#define NStringJoinArray N_FUNC_AW(NStringJoinArray)

NResult N_API NStringJoinManyVAN(HNString hSeparator, HNString * phResultString, NInt count, va_list args);

NResult N_API NStringJoinManyVAVNA(const NAChar * szSeparator, HNString * phResultString, NInt count, va_list args);
#ifndef N_NO_UNICODE
NResult N_API NStringJoinManyVAVNW(const NWChar * szSeparator, HNString * phResultString, NInt count, va_list args);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NStringJoinManyVAVN(const NChar * szSeparator, HNString * phResultString, NInt count, va_list args);
#endif
#define NStringJoinManyVAVN N_FUNC_AW(NStringJoinManyVAVN)

NResult N_API NStringJoinManyVAA(const NAChar * szSeparator, HNString * phResultString, NInt count, va_list args);
#ifndef N_NO_UNICODE
NResult N_API NStringJoinManyVAW(const NWChar * szSeparator, HNString * phResultString, NInt count, va_list args);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NStringJoinManyVA(const NChar * szSeparator, HNString * phResultString, NInt count, va_list args);
#endif
#define NStringJoinManyVA N_FUNC_AW(NStringJoinManyVA)

NResult N_API NStringJoinManyN(HNString hSeparator, HNString * phResultString, NInt count, ...);

NResult N_API NStringJoinManyVNA(const NAChar * szSeparator, HNString * phResultString, NInt count, ...);
#ifndef N_NO_UNICODE
NResult N_API NStringJoinManyVNW(const NWChar * szSeparator, HNString * phResultString, NInt count, ...);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NStringJoinManyVN(const NChar * szSeparator, HNString * phResultString, NInt count, ... multipleParameters);
#endif
#define NStringJoinManyVN N_FUNC_AW(NStringJoinManyVN)

NResult N_API NStringJoinManyA(const NAChar * szSeparator, HNString * phResultString, NInt count, ...);
#ifndef N_NO_UNICODE
NResult N_API NStringJoinManyW(const NWChar * szSeparator, HNString * phResultString, NInt count, ...);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NStringJoinMany(const NChar * szSeparator, HNString * phResultString, NInt count, ... multipleParameters);
#endif
#define NStringJoinMany N_FUNC_AW(NStringJoinMany)

NResult N_API NStringFormatVAN(HNString * phValue, HNString hFormat, va_list args);
NResult N_API NStringFormatN(HNString * phValue, HNString hFormat, ...);

NResult N_API NStringFormatVAA(HNString * phValue, const NAChar * szFormat, va_list args);
#ifndef N_NO_UNICODE
NResult N_API NStringFormatVAW(HNString * phValue, const NWChar * szFormat, va_list args);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NStringFormatVA(HNString * phValue, const NChar * szFormat, va_list args);
#endif
#define NStringFormatVA N_FUNC_AW(NStringFormatVA)

NResult N_API NStringFormatA(HNString * phValue, const NAChar * szFormat, ...);
#ifndef N_NO_UNICODE
NResult N_API NStringFormatW(HNString * phValue, const NWChar * szFormat, ...);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NStringFormat(HNString * phValue, const NChar * szFormat, ... multipleParameters);
#endif
#define NStringFormat N_FUNC_AW(NStringFormat)

#ifdef N_CPP
}
#endif

#endif // !N_STRING_H_INCLUDED
