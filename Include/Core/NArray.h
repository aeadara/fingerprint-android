#include <Core/NValue.h>

#ifndef N_ARRAY_H_INCLUDED
#define N_ARRAY_H_INCLUDED

#ifdef N_CPP
extern "C"
{
#endif

NResult N_API NArrayCreate(HNType hType, const void * arValues, NSizeType valuesSize, NInt valuesLength, NAttributes attributes, HNArray * phArray);
NResult N_API NArrayCreateP(NTypeOfProc pTypeOf, const void * arValues, NSizeType valuesSize, NInt valuesLength, NAttributes attributes, HNArray * phArray);
NResult N_API NArrayCreateCustomN(const void * const * arValues, NInt valuesLength, HNCallback hFree, HNCallback hGetHashCode, HNCallback hEquals, NAttributes attributes, HNArray * phArray);
NResult N_API NArrayCreateCustom(const void * const * arValues, NInt valuesLength, NPointerFreeProc pFree, void * pFreeParam,
	NPointerGetHashCodeProc pGetHashCode, void * pGetHashCodeParam, NPointerEqualsProc pEquals, void * pEqualsParam, NAttributes attributes, HNArray * phArray);
NResult N_API NArrayCreateFromByteArray(const NByte * arValues, NInt valuesLength, NAttributes attributes, HNArray * phArray);
NResult N_API NArrayCreateFromSByteArray(const NSByte * arValues, NInt valuesLength, NAttributes attributes, HNArray * phArray);
NResult N_API NArrayCreateFromUInt16Array(const NUShort * arValues, NInt valuesLength, NAttributes attributes, HNArray * phArray);
NResult N_API NArrayCreateFromInt16Array(const NShort * arValues, NInt valuesLength, NAttributes attributes, HNArray * phArray);
NResult N_API NArrayCreateFromUInt32Array(const NUInt * arValues, NInt valuesLength, NAttributes attributes, HNArray * phArray);
NResult N_API NArrayCreateFromInt32Array(const NInt * arValues, NInt valuesLength, NAttributes attributes, HNArray * phArray);
NResult N_API NArrayCreateFromUInt64Array(const NULong * arValues, NInt valuesLength, NAttributes attributes, HNArray * phArray);
NResult N_API NArrayCreateFromInt64Array(const NLong * arValues, NInt valuesLength, NAttributes attributes, HNArray * phArray);
NResult N_API NArrayCreateFromSingleArray(const NFloat * arValues, NInt valuesLength, NAttributes attributes, HNArray * phArray);
NResult N_API NArrayCreateFromDoubleArray(const NDouble * arValues, NInt valuesLength, NAttributes attributes, HNArray * phArray);
NResult N_API NArrayCreateFromBooleanArray(const NBool * arValues, NInt valuesLength, NAttributes attributes, HNArray * phArray);
NResult N_API NArrayCreateFromSizeTypeArray(const NSizeType * arValues, NInt valuesLength, NAttributes attributes, HNArray * phArray);
NResult N_API NArrayCreateFromSSizeTypeArray(const NSSizeType * arValues, NInt valuesLength, NAttributes attributes, HNArray * phArray);
NResult N_API NArrayCreateFromPointerArray(const void * const * arValues, NInt valuesLength, NAttributes attributes, HNArray * phArray);
NResult N_API NArrayCreateFromResultArray(const NResult * arValues, NInt valuesLength, NAttributes attributes, HNArray * phArray);

NResult N_API NArrayCreateFromCharArrayA(const NAChar * arValues, NInt valuesLength, NAttributes attributes, HNArray * phArray);
#ifndef N_NO_UNICODE
NResult N_API NArrayCreateFromCharArrayW(const NWChar * arValues, NInt valuesLength, NAttributes attributes, HNArray * phArray);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NArrayCreateFromCharArray(const NChar * arValues, NInt valuesLength, NAttributes attributes, HNArray * phArray);
#endif
#define NArrayCreateFromCharArray N_FUNC_AW(NArrayCreateFromCharArray)

NResult N_API NArrayCreateFromStringArrayN(const HNString * arhValues, NInt valuesLength, NAttributes attributes, HNArray * phArray);
NResult N_API NArrayCreateFromStringArrayA(const NAChar * const * arszValues, NInt valuesLength, NAttributes attributes, HNArray * phArray);
#ifndef N_NO_UNICODE
NResult N_API NArrayCreateFromStringArrayW(const NWChar * const * arszValues, NInt valuesLength, NAttributes attributes, HNArray * phArray);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NArrayCreateFromStringArray(const NChar * const * arszValues, NInt valuesLength, NAttributes attributes, HNArray * phArray);
#endif
#define NArrayCreateFromStringArray N_FUNC_AW(NArrayCreateFromStringArray)

NResult N_API NArrayCreateFromObjectArray(HNType hType, const HNObject * arhValues, NInt valuesLength, NAttributes attributes, HNArray * phArray);
NResult N_API NArrayCreateFromObjectArrayP(NTypeOfProc pTypeOf, const HNObject * arhValues, NInt valuesLength, NAttributes attributes, HNArray * phArray);
NResult N_API NArrayCreateFromCallbackArray(HNType hType, const HNCallback * arhValues, NInt valuesLength, NAttributes attributes, HNArray * phArray);
NResult N_API NArrayCreateFromCallbackArrayP(NTypeOfProc pTypeOf, const HNCallback * arhValues, NInt valuesLength, NAttributes attributes, HNArray * phArray);

NResult N_API NArrayGetLength(HNArray hArray, NInt * pValue);

NResult N_API NArrayCopyTo(HNArray hArray, HNType hType, NAttributes attributes, HNString hFormat, void * arValues, NSizeType valuesSize, NInt valuesLength);
NResult N_API NArrayCopyToP(HNArray hArray, NTypeOfProc pTypeOf, NAttributes attributes, HNString hFormat, void * arValues, NSizeType valuesSize, NInt valuesLength);
NResult N_API NArrayCopyToByteArray(HNArray hArray, NAttributes attributes, HNString hFormat, NByte * arValues, NInt valuesLength);
NResult N_API NArrayCopyToSByteArray(HNArray hArray, NAttributes attributes, HNString hFormat, NSByte * arValues, NInt valuesLength);
NResult N_API NArrayCopyToUInt16Array(HNArray hArray, NAttributes attributes, HNString hFormat, NUShort * arValues, NInt valuesLength);
NResult N_API NArrayCopyToInt16Array(HNArray hArray, NAttributes attributes, HNString hFormat, NShort * arValues, NInt valuesLength);
NResult N_API NArrayCopyToUInt32Array(HNArray hArray, NAttributes attributes, HNString hFormat, NUInt * arValues, NInt valuesLength);
NResult N_API NArrayCopyToInt32Array(HNArray hArray, NAttributes attributes, HNString hFormat, NInt * arValues, NInt valuesLength);
NResult N_API NArrayCopyToUInt64Array(HNArray hArray, NAttributes attributes, HNString hFormat, NULong * arValues, NInt valuesLength);
NResult N_API NArrayCopyToInt64Array(HNArray hArray, NAttributes attributes, HNString hFormat, NLong * arValues, NInt valuesLength);
NResult N_API NArrayCopyToSingleArray(HNArray hArray, NAttributes attributes, HNString hFormat, NFloat * arValues, NInt valuesLength);
NResult N_API NArrayCopyToDoubleArray(HNArray hArray, NAttributes attributes, HNString hFormat, NDouble * arValues, NInt valuesLength);
NResult N_API NArrayCopyToBooleanArray(HNArray hArray, NAttributes attributes, HNString hFormat, NBool * arValues, NInt valuesLength);
NResult N_API NArrayCopyToSizeTypeArray(HNArray hArray, NAttributes attributes, HNString hFormat, NSizeType * arValues, NInt valuesLength);
NResult N_API NArrayCopyToSSizeTypeArray(HNArray hArray, NAttributes attributes, HNString hFormat, NSSizeType * arValues, NInt valuesLength);
NResult N_API NArrayCopyToPointerArray(HNArray hArray, NAttributes attributes, HNString hFormat, void * * arValues, NInt valuesLength);
NResult N_API NArrayCopyToResultArray(HNArray hArray, NAttributes attributes, HNString hFormat, NResult * arValues, NInt valuesLength);

NResult N_API NArrayCopyToCharArrayA(HNArray hArray, NAttributes attributes, HNString hFormat, NAChar * arValues, NInt valuesLength);
#ifndef N_NO_UNICODE
NResult N_API NArrayCopyToCharArrayW(HNArray hArray, NAttributes attributes, HNString hFormat, NWChar * arValues, NInt valuesLength);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NArrayCopyToCharArray(HNArray hArray, NAttributes attributes, HNString hFormat, NChar * arValues, NInt valuesLength);
#endif
#define NArrayCopyToCharArray N_FUNC_AW(NArrayCopyToCharArray)

NResult N_API NArrayCopyToStringArray(HNArray hArray, NAttributes attributes, HNString hFormat, HNString * arhValues, NInt valuesLength);
NResult N_API NArrayCopyToObjectArray(HNArray hArray, HNType hType, NAttributes attributes, HNString hFormat, HNObject * arhValues, NInt valuesLength);
NResult N_API NArrayCopyToObjectArrayP(HNArray hArray, NTypeOfProc pTypeOf, NAttributes attributes, HNString hFormat, HNObject * arhValues, NInt valuesLength);
NResult N_API NArrayCopyToCallbackArray(HNArray hArray, HNType hType, NAttributes attributes, HNString hFormat, HNCallback * arhValues, NInt valuesLength);
NResult N_API NArrayCopyToCallbackArrayP(HNArray hArray, NTypeOfProc pTypeOf, NAttributes attributes, HNString hFormat, HNCallback * arhValues, NInt valuesLength);

NResult N_API NArrayGetValue(HNArray hArray, NInt index, HNValue * phValue);
NResult N_API NArrayGetValueAs(HNArray hArray, NInt index, HNType hType, NAttributes attributes, HNString hFormat, void * pValue, NSizeType elementSize);
NResult N_API NArrayGetValueAsP(HNArray hArray, NInt index, NTypeOfProc pTypeOf, NAttributes attributes, HNString hFormat, void * pValue, NSizeType elementSize);
NResult N_API NArrayGetValueAsByte(HNArray hArray, NInt index, NAttributes attributes, HNString hFormat, NByte * pValue);
NResult N_API NArrayGetValueAsSByte(HNArray hArray, NInt index, NAttributes attributes, HNString hFormat, NSByte * pValue);
NResult N_API NArrayGetValueAsUInt16(HNArray hArray, NInt index, NAttributes attributes, HNString hFormat, NUShort * pValue);
NResult N_API NArrayGetValueAsInt16(HNArray hArray, NInt index, NAttributes attributes, HNString hFormat, NShort * pValue);
NResult N_API NArrayGetValueAsUInt32(HNArray hArray, NInt index, NAttributes attributes, HNString hFormat, NUInt * pValue);
NResult N_API NArrayGetValueAsInt32(HNArray hArray, NInt index, NAttributes attributes, HNString hFormat, NInt * pValue);
NResult N_API NArrayGetValueAsUInt64(HNArray hArray, NInt index, NAttributes attributes, HNString hFormat, NULong * pValue);
NResult N_API NArrayGetValueAsInt64(HNArray hArray, NInt index, NAttributes attributes, HNString hFormat, NLong * pValue);
NResult N_API NArrayGetValueAsSingle(HNArray hArray, NInt index, NAttributes attributes, HNString hFormat, NFloat * pValue);
NResult N_API NArrayGetValueAsDouble(HNArray hArray, NInt index, NAttributes attributes, HNString hFormat, NDouble * pValue);
NResult N_API NArrayGetValueAsBoolean(HNArray hArray, NInt index, NAttributes attributes, HNString hFormat, NBoolean * pValue);
NResult N_API NArrayGetValueAsSizeType(HNArray hArray, NInt index, NAttributes attributes, HNString hFormat, NSizeType * pValue);
NResult N_API NArrayGetValueAsSSizeType(HNArray hArray, NInt index, NAttributes attributes, HNString hFormat, NSSizeType * pValue);
NResult N_API NArrayGetValueAsPointer(HNArray hArray, NInt index, NAttributes attributes, HNString hFormat, void * * pValue);
NResult N_API NArrayGetValueAsResult(HNArray hArray, NInt index, NAttributes attributes, HNString hFormat, NResult * pValue);

NResult N_API NArrayGetValueAsCharA(HNArray hArray, NInt index, NAttributes attributes, HNString hFormat, NAChar * pValue);
#ifndef N_NO_UNICODE
NResult N_API NArrayGetValueAsCharW(HNArray hArray, NInt index, NAttributes attributes, HNString hFormat, NWChar * pValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NArrayGetValueAsChar(HNArray hArray, NInt index, NAttributes attributes, HNString hFormat, NChar * pValue);
#endif
#define NArrayGetValueAsChar N_FUNC_AW(NArrayGetValueAsChar)

NResult N_API NArrayGetValueAsString(HNArray hArray, NInt index, NAttributes attributes, HNString hFormat, HNString * phValue);
NResult N_API NArrayGetValueAsObject(HNArray hArray, NInt index, HNType hType, NAttributes attributes, HNString hFormat, HNObject * phValue);
NResult N_API NArrayGetValueAsObjectP(HNArray hArray, NInt index, NTypeOfProc pTypeOf, NAttributes attributes, HNString hFormat, HNObject * phValue);
NResult N_API NArrayGetValueAsCallback(HNArray hArray, NInt index, HNType hType, NAttributes attributes, HNString hFormat, HNCallback * phValue);
NResult N_API NArrayGetValueAsCallbackP(HNArray hArray, NInt index, NTypeOfProc pTypeOf, NAttributes attributes, HNString hFormat, HNCallback * phValue);

#ifdef N_CPP
}
#endif

#endif // !N_ARRAY_H_INCLUDED
