#include <Core/NType.h>

#ifndef N_VALUE_H_INCLUDED
#define N_VALUE_H_INCLUDED

#ifdef N_CPP
extern "C"
{
#endif

NResult N_API NValueCreate(HNType hType, const void * pValue, NSizeType valueSize, NBool hasValue, NAttributes attributes, HNValue * phValue);
NResult N_API NValueCreateP(NTypeOfProc pTypeOf, const void * pValue, NSizeType valueSize, NBool hasValue, NAttributes attributes, HNValue * phValue);
NResult N_API NValueCreateCustomN(const void * value, HNCallback hFree, HNCallback hGetHashCode, HNCallback hEquals, NAttributes attributes, HNValue * phValue);
NResult N_API NValueCreateCustom(const void * value, NPointerFreeProc pFree, void * pFreeParam, NPointerGetHashCodeProc pGetHashCode, void * pGetHashCodeParam,
	NPointerEqualsProc pEquals, void * pEqualsParam, NAttributes attributes, HNValue * phValue);
NResult N_API NValueCreateFromByte(NByte value, NAttributes attributes, HNValue * phValue);
NResult N_API NValueCreateFromSByte(NSByte value, NAttributes attributes, HNValue * phValue);
NResult N_API NValueCreateFromUInt16(NUShort value, NAttributes attributes, HNValue * phValue);
NResult N_API NValueCreateFromInt16(NShort value, NAttributes attributes, HNValue * phValue);
NResult N_API NValueCreateFromUInt32(NUInt value, NAttributes attributes, HNValue * phValue);
NResult N_API NValueCreateFromInt32(NInt value, NAttributes attributes, HNValue * phValue);
NResult N_API NValueCreateFromUInt64(NULong value, NAttributes attributes, HNValue * phValue);
NResult N_API NValueCreateFromInt64(NLong value, NAttributes attributes, HNValue * phValue);
NResult N_API NValueCreateFromSingle(NFloat value, NAttributes attributes, HNValue * phValue);
NResult N_API NValueCreateFromDouble(NDouble value, NAttributes attributes, HNValue * phValue);
NResult N_API NValueCreateFromBoolean(NBool value, NAttributes attributes, HNValue * phValue);
NResult N_API NValueCreateFromSizeType(NSizeType value, NAttributes attributes, HNValue * phValue);
NResult N_API NValueCreateFromSSizeType(NSSizeType value, NAttributes attributes, HNValue * phValue);
NResult N_API NValueCreateFromPointer(const void * value, NAttributes attributes, HNValue * phValue);
NResult N_API NValueCreateFromResult(NResult value, NAttributes attributes, HNValue * phValue);

NResult N_API NValueCreateFromCharA(NAChar value, NAttributes attributes, HNValue * phValue);
#ifndef N_NO_UNICODE
NResult N_API NValueCreateFromCharW(NWChar value, NAttributes attributes, HNValue * phValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NValueCreateFromChar(NChar value, NAttributes attributes, HNValue * phValue);
#endif
#define NValueCreateFromChar N_FUNC_AW(NValueCreateFromChar)

NResult N_API NValueCreateFromStringN(HNString hValue, NAttributes attributes, HNValue * phValue);
NResult N_API NValueCreateFromStringA(const NAChar * szValue, NAttributes attributes, HNValue * phValue);
#ifndef N_NO_UNICODE
NResult N_API NValueCreateFromStringW(const NWChar * szValue, NAttributes attributes, HNValue * phValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NValueCreateFromString(const NChar * szValue, NAttributes attributes, HNValue * phValue);
#endif
#define NValueCreateFromString N_FUNC_AW(NValueCreateFromString)

NResult N_API NValueCreateFromObject(HNType hType, HNObject hValue, NAttributes attributes, HNValue * phValue);
NResult N_API NValueCreateFromObjectP(NTypeOfProc pTypeOf, HNObject hValue, NAttributes attributes, HNValue * phValue);
NResult N_API NValueCreateFromCallback(HNType hType, HNCallback hValue, NAttributes attributes, HNValue * phValue);
NResult N_API NValueCreateFromCallbackP(NTypeOfProc pTypeOf, HNCallback hValue, NAttributes attributes, HNValue * phValue);

NResult N_API NValueSet(HNValue hValue, HNType hType, NAttributes attributes, void * pValue, NSizeType valueSize, NBool * pHasValue);
NResult N_API NValueSetP(HNValue hValue, NTypeOfProc pTypeOf, NAttributes attributes, void * pValue, NSizeType valueSize, NBool * pHasValue);
NResult N_API NValueChangeType(HNValue hSrcValue, HNType hType, NAttributes attributes, HNString hFormat, HNValue * phValue);
NResult N_API NValueChangeTypeP(HNValue hSrcValue, NTypeOfProc pTypeOf, NAttributes attributes, HNString hFormat, HNValue * phValue);

NResult N_API NValueGetValueType(HNValue hValue, HNType * phResult);
NResult N_API NValueGetAttributes(HNValue hValue, NAttributes * pResult);
NResult N_API NValueGetFree(HNValue hValue, HNCallback * phResult);
NResult N_API NValueGetPtr(HNValue hValue, const void * * pResult);
NResult N_API NValueGetSize(HNValue hValue, NSizeType * pResult);
NResult N_API NValueGetTypeCode(HNValue hValue, NTypeCode * pResult);

NResult N_API NValueToValue(HNValue hValue, HNType hType, NAttributes attributes, HNString hFormat, void * pResult, NSizeType resultSize);
NResult N_API NValueToValueP(HNValue hValue, NTypeOfProc pTypeOf, NAttributes attributes, HNString hFormat, void * pResult, NSizeType resultSize);
NResult N_API NValueToByte(HNValue hValue, NAttributes attributes, HNString hFormat, NByte * pResult);
NResult N_API NValueToSByte(HNValue hValue, NAttributes attributes, HNString hFormat, NSByte * pResult);
NResult N_API NValueToUInt16(HNValue hValue, NAttributes attributes, HNString hFormat, NUShort * pResult);
NResult N_API NValueToInt16(HNValue hValue, NAttributes attributes, HNString hFormat, NShort * pResult);
NResult N_API NValueToUInt32(HNValue hValue, NAttributes attributes, HNString hFormat, NUInt * pResult);
NResult N_API NValueToInt32(HNValue hValue, NAttributes attributes, HNString hFormat, NInt * pResult);
NResult N_API NValueToUInt64(HNValue hValue, NAttributes attributes, HNString hFormat, NULong * pResult);
NResult N_API NValueToInt64(HNValue hValue, NAttributes attributes, HNString hFormat, NLong * pResult);
NResult N_API NValueToSingle(HNValue hValue, NAttributes attributes, HNString hFormat, NFloat * pResult);
NResult N_API NValueToDouble(HNValue hValue, NAttributes attributes, HNString hFormat, NDouble * pResult);
NResult N_API NValueToBoolean(HNValue hValue, NAttributes attributes, HNString hFormat, NBool * pResult);
NResult N_API NValueToSizeType(HNValue hValue, NAttributes attributes, HNString hFormat, NSizeType * pResult);
NResult N_API NValueToSSizeType(HNValue hValue, NAttributes attributes, HNString hFormat, NSSizeType * pResult);
NResult N_API NValueToPointer(HNValue hValue, NAttributes attributes, HNString hFormat, void * * pResult);
NResult N_API NValueToResult(HNValue hValue, NAttributes attributes, HNString hFormat, NResult * pResult);

NResult N_API NValueToCharA(HNValue hValue, NAttributes attributes, HNString hFormat, NAChar * pResult);
#ifndef N_NO_UNICODE
NResult N_API NValueToCharW(HNValue hValue, NAttributes attributes, HNString hFormat, NWChar * pResult);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NValueToChar(HNValue hValue, NAttributes attributes, HNString hFormat, NChar * pResult);
#endif
#define NValueToChar N_FUNC_AW(NValueToChar)

NResult N_API NValueToString(HNValue hValue, NAttributes attributes, HNString hFormat, HNString * phResult);
NResult N_API NValueToObject(HNValue hValue, HNType hType, NAttributes attributes, HNString hFormat, HNObject * phResult);
NResult N_API NValueToObjectP(HNValue hValue, NTypeOfProc pTypeOf, NAttributes attributes, HNString hFormat, HNObject * phResult);
NResult N_API NValueToCallback(HNValue hValue, HNType hType, NAttributes attributes, HNString hFormat, HNCallback * phResult);
NResult N_API NValueToCallbackP(HNValue hValue, NTypeOfProc pTypeOf, NAttributes attributes, HNString hFormat, HNCallback * phResult);

N_DECLARE_TYPE(NKeyValuePair)

struct NKeyValuePair_
{
	HNValue hKey;
	HNValue hValue;
};
#if !defined(N_VALUE_HPP_INCLUDED) && !defined(N_TYPE_HPP_INCLUDED) && !defined(N_OBJECT_HPP_INCLUDED)
typedef struct NKeyValuePair_ NKeyValuePair;
#endif

NResult N_API NKeyValuePairCreate(HNValue hKey, HNValue hValue, struct NKeyValuePair_ * pValue);
NResult N_API NKeyValuePairDispose(struct NKeyValuePair_ * pValue);
NResult N_API NKeyValuePairCopy(const struct NKeyValuePair_ * pSrcValue, struct NKeyValuePair_ * pDstValue);
NResult N_API NKeyValuePairSet(const struct NKeyValuePair_ * pSrcValue, struct NKeyValuePair_ * pDstValue);

N_DECLARE_TYPE(NNameValuePair)

struct NNameValuePair_
{
	HNString hKey;
	HNValue hValue;
};
#if !defined(N_VALUE_HPP_INCLUDED) && !defined(N_TYPE_HPP_INCLUDED) && !defined(N_OBJECT_HPP_INCLUDED)
typedef struct NNameValuePair_ NNameValuePair;
#endif

NResult N_API NNameValuePairCreateN(HNString hKey, HNValue hValue, struct NNameValuePair_ * pValue);
#ifndef N_NO_ANSI_FUNC
NResult N_API NNameValuePairCreateA(const NAChar * szKey, HNValue hValue, struct NNameValuePair_ * pValue);
#endif
#ifndef N_NO_UNICODE
NResult N_API NNameValuePairCreateW(const NWChar * szKey, HNValue hValue, struct NNameValuePair_ * pValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NNameValuePairCreate(const NChar * szKey, HNValue hValue, NNameValuePair * pValue);
#endif
#define NNameValuePairCreate N_FUNC_AW(NNameValuePairCreate)

NResult N_API NNameValuePairDispose(struct NNameValuePair_ * pValue);
NResult N_API NNameValuePairCopy(const struct NNameValuePair_ * pSrcValue, struct NNameValuePair_ * pDstValue);
NResult N_API NNameValuePairSet(const struct NNameValuePair_ * pSrcValue, struct NNameValuePair_ * pDstValue);

#ifdef N_CPP
}
#endif

#endif // !N_VALUE_H_INCLUDED
