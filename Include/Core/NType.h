#include <Core/NObject.h>

#ifndef N_TYPE_H_INCLUDED
#define N_TYPE_H_INCLUDED

#ifdef N_CPP
extern "C"
{
#endif

typedef enum NTypeCode_
{
	ntcNone = 0,
	ntcOther = 1,
	ntcByte = 2,
	ntcSByte = 3,
	ntcUInt16 = 4,
	ntcInt16 = 5,
	ntcUInt32 = 6,
	ntcInt32 = 7,
	ntcUInt64 = 8,
	ntcInt64 = 9,
	ntcSingle = 10,
	ntcDouble = 11,
	ntcBoolean = 12,
	ntcSizeType = 13,
	ntcSSizeType = 14,
	ntcPointer = 15,
	ntcResult = 16,
	ntcAChar = 17,
#ifndef N_NO_UNICODE
	ntcWChar = 18,
#endif
#ifdef N_UNICODE
	ntcChar = ntcWChar,
#else
	ntcChar = ntcAChar,
#endif
	ntcString = 19,
	ntcObject = 20,
	ntcValue = 21,
	ntcArray = 22,
	ntcTimeSpan = 23,
	ntcDateTime = 24,
	ntcURational = 25,
	ntcRational = 26,
	ntcComplex = 27,
	ntcGuid = 28,
	ntcBuffer = 29,
	ntcCallback = 30,
	ntcAsyncOperation = 31,
	ntcObjectPart = 32,
	ntcCollection = 33,
	ntcDictionary = 34,
	ntcArrayCollection = 35
} NTypeCode;

N_DECLARE_TYPE(NTypeCode)

NResult N_API NTypeGetTypeWithNameN(HNString hName, NBool mustExist, HNType * phValue);
#ifndef N_NO_ANSI_FUNC
NResult N_API NTypeGetTypeWithNameA(const NAChar * szName, NBool mustExist, HNType * phValue);
#endif
#ifndef N_NO_UNICODE
NResult N_API NTypeGetTypeWithNameW(const NWChar * szName, NBool mustExist, HNType * phValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NTypeGetTypeWithName(const NChar * szName, NBool mustExist, HNType * phValue);
#endif
#define NTypeGetTypeWithName N_FUNC_AW(NTypeGetTypeWithName)

NResult N_API NTypeCreateInstanceWithNameN(HNString hName, NAttributes attributes, HNValue * phValue);
#ifndef N_NO_ANSI_FUNC
NResult N_API NTypeCreateInstanceWithNameA(const NAChar * szName, NAttributes attributes, HNValue * phValue);
#endif
#ifndef N_NO_UNICODE
NResult N_API NTypeCreateInstanceWithNameW(const NWChar * szName, NAttributes attributes, HNValue * phValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NTypeCreateInstanceWithName(const NChar * szName, NAttributes attributes, HNValue * phValue);
#endif
#define NTypeCreateInstanceWithName N_FUNC_AW(NTypeCreateInstanceWithName)

NResult N_API NTypeCreateInstance(HNType hType, NAttributes attributes, HNValue * phValue);
NResult N_API NTypeIsSubclassOf(HNType hType, HNType hOtherType, NBool * pValue);
NResult N_API NTypeIsAssignableFrom(HNType hType, HNType hOtherType, NBool * pValue);
NResult N_API NTypeIsInstanceOfType(HNType hType, HNObject hObject, NBool * pValue);
NResult N_API NTypeIsInstanceOfTypeP(NTypeOfProc pTypeOf, HNObject hObject, NBool * pValue);
NResult N_API NTypeReset(HNType hType, HNObject hObject);

NResult N_API NTypeGetPropertyValueN(HNType hType, HNObject hObject, HNString hName, HNValue * phValue);
NResult N_API NTypeGetPropertyValueNN(HNType hType, HNObject hObject, HNString hName, HNType hValueType, NAttributes attributes, void * arValues, NSizeType valuesSize, NInt valuesLength, NBool * pHasValue);
#ifndef N_NO_ANSI_FUNC
NResult N_API NTypeGetPropertyValuePA(HNType hType, HNObject hObject, const NAChar * szName, NTypeOfProc pValueTypeOf, NAttributes attributes, void * arValues, NSizeType valuesSize, NInt valuesLength, NBool * pHasValue);
#endif
#ifndef N_NO_UNICODE
NResult N_API NTypeGetPropertyValuePW(HNType hType, HNObject hObject, const NWChar * szName, NTypeOfProc pValueTypeOf, NAttributes attributes, void * arValues, NSizeType valuesSize, NInt valuesLength, NBool * pHasValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NTypeGetPropertyValueP(HNType hType, HNObject hObject, const NChar * szName, NTypeOfProc pValueTypeOf, NAttributes attributes, void * arValues, NSizeType valuesSize, NInt valuesLength, NBool * pHasValue);
#endif
#define NTypeGetPropertyValueP N_FUNC_AW(NTypeGetPropertyValueP)

N_DEPRECATED("function is deprecated, use NTypeGetPropertyN instead")
NResult N_API NTypeGetParameterExN(HNType hType, HNObject hObject, NUShort partId, NUInt parameterId, HNValue * phValue);
N_DEPRECATED("function is deprecated, use NTypeGetPropertyP instead")
NResult N_API NTypeGetParameterEx(HNType hType, HNObject hObject, NUShort partId, NUInt parameterId, NInt typeId, void * pValue, NSizeType valueSize);

NResult N_API NTypeSetPropertyValueN(HNType hType, HNObject hObject, HNString hName, HNValue hValue);
NResult N_API NTypeSetPropertyValueNN(HNType hType, HNObject hObject, HNString hName, HNType hValueType, NAttributes attributes, const void * arValues, NSizeType valuesSize, NInt valuesLength, NBool hasValue);
#ifndef N_NO_ANSI_FUNC
NResult N_API NTypeSetPropertyValuePA(HNType hType, HNObject hObject, const NAChar * szName, NTypeOfProc pValueTypeOf, NAttributes attributes, const void * arValues, NSizeType valuesSize, NInt valuesLength, NBool hasValue);
#endif
#ifndef N_NO_UNICODE
NResult N_API NTypeSetPropertyValuePW(HNType hType, HNObject hObject, const NWChar * szName, NTypeOfProc pValueTypeOf, NAttributes attributes, const void * arValues, NSizeType valuesSize, NInt valuesLength, NBool hasValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NTypeSetPropertyValueP(HNType hType, HNObject hObject, const NChar * szName, NTypeOfProc pValueTypeOf, NAttributes attributes, const void * arValues, NSizeType valuesSize, NInt valuesLength, NBool hasValue);
#endif
#define NTypeSetPropertyValueP N_FUNC_AW(NTypeSetPropertyValueP)

N_DEPRECATED("function is deprecated, use NTypeSetPropertyN instead")
NResult N_API NTypeSetParameterExN(HNType hType, HNObject hObject, NUShort partId, NUInt parameterId, HNValue hValue);
N_DEPRECATED("function is deprecated, use NTypeSetPropertyP instead")
NResult N_API NTypeSetParameterEx(HNType hType, HNObject hObject, NUShort partId, NUInt parameterId, NInt typeId, const void * pValue, NSizeType valueSize);

NResult N_API NTypeResetPropertyValueN(HNType hType, HNObject hObject, HNString hName);
#ifndef N_NO_ANSI_FUNC
NResult N_API NTypeResetPropertyValueA(HNType hType, HNObject hObject, const NAChar * szName);
#endif
#ifndef N_NO_UNICODE
NResult N_API NTypeResetPropertyValueW(HNType hType, HNObject hObject, const NWChar * szName);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NTypeResetPropertyValue(HNType hType, HNObject hObject, const NChar * szName);
#endif
#define NTypeResetPropertyValueP N_FUNC_AW(NTypeResetPropertyValue)

NResult N_API NTypeCopyPropertyValues(HNType hType, HNObject hDstObject, HNObject hSrcObject);
NResult N_API NTypeCapturePropertyValues(HNType hType, HNObject hObject, HNPropertyBag hProperties);

NResult N_API NTypeInvokeMethodN(HNType hType, HNObject hObject, HNString hName, HNValue * arhParameters, NInt parameterCount, HNValue * phResult);
#ifndef N_NO_ANSI_FUNC
NResult N_API NTypeInvokeMethodA(HNType hType, HNObject hObject, const NAChar * szName, HNValue * arhParameters, NInt parameterCount, HNValue * phResult);
#endif
#ifndef N_NO_UNICODE
NResult N_API NTypeInvokeMethodW(HNType hType, HNObject hObject, const NWChar * szName, HNValue * arhParameters, NInt parameterCount, HNValue * phResult);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NTypeInvokeMethod(HNType hType, HNObject hObject, const NChar * szName, HNValue * arhParameters, NInt parameterCount, HNValue * phResult);
#endif
#define NTypeInvokeMethod N_FUNC_AW(NTypeInvokeMethod)

NResult N_API NTypeInvokeMethodWithPropertyBagN(HNType hType, HNObject hObject, HNString hName, HNPropertyBag hParameters, HNValue * phResult);
#ifndef N_NO_ANSI_FUNC
NResult N_API NTypeInvokeMethodWithPropertyBagA(HNType hType, HNObject hObject, const NAChar * szName, HNPropertyBag hParameters, HNValue * phResult);
#endif
#ifndef N_NO_UNICODE
NResult N_API NTypeInvokeMethodWithPropertyBagW(HNType hType, HNObject hObject, const NWChar * szName, HNPropertyBag hParameters, HNValue * phResult);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NTypeInvokeMethodWithPropertyBag(HNType hType, HNObject hObject, const NChar * szName, HNPropertyBag hParameters, HNValue * phResult);
#endif
#define NTypeInvokeMethodWithPropertyBag N_FUNC_AW(NTypeInvokeMethodWithPropertyBag)

NResult N_API NTypeInvokeMethodWithStringN(HNType hType, HNObject hObject, HNString hName, HNString hParameters, HNValue * phResult);
#ifndef N_NO_ANSI_FUNC
NResult N_API NTypeInvokeMethodWithStringA(HNType hType, HNObject hObject, const NAChar * szName, const NAChar * szParameters, HNValue * phResult);
#endif
#ifndef N_NO_UNICODE
NResult N_API NTypeInvokeMethodWithStringW(HNType hType, HNObject hObject, const NWChar * szName, const NWChar * szParameters, HNValue * phResult);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NTypeInvokeMethodWithString(HNType hType, HNObject hObject, const NChar * szName, const NChar * szParameters, HNValue * phResult);
#endif
#define NTypeInvokeMethodWithString N_FUNC_AW(NTypeInvokeMethodWithString)

NResult N_API NTypeAddEventHandlerN(HNType hType, HNObject hObject, HNString hName, HNValue hCallback);
NResult N_API NTypeAddEventHandlerNN(HNType hType, HNObject hObject, HNString hName, HNType hCallbackType, HNCallback hCallback);
#ifndef N_NO_ANSI_FUNC
NResult N_API NTypeAddEventHandlerPA(HNType hType, HNObject hObject, const NAChar * szName, NTypeOfProc pCallbackTypeOf, HNCallback hCallback);
#endif
#ifndef N_NO_UNICODE
NResult N_API NTypeAddEventHandlerPW(HNType hType, HNObject hObject, const NWChar * szName, NTypeOfProc pCallbackTypeOf, HNCallback hCallback);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NTypeAddEventHandlerP(HNType hType, HNObject hObject, const NChar * szName, NTypeOfProc pCallbackTypeOf, HNCallback hCallback);
#endif
#define NTypeAddEventHandlerP N_FUNC_AW(NTypeAddEventHandlerP)

NResult N_API NTypeRemoveEventHandlerN(HNType hType, HNObject hObject, HNString hName, HNValue hCallback);
NResult N_API NTypeRemoveEventHandlerNN(HNType hType, HNObject hObject, HNString hName, HNType hCallbackType, HNCallback hCallback);
#ifndef N_NO_ANSI_FUNC
NResult N_API NTypeRemoveEventHandlerPA(HNType hType, HNObject hObject, const NAChar * szName, NTypeOfProc pCallbackTypeOf, HNCallback hCallback);
#endif
#ifndef N_NO_UNICODE
NResult N_API NTypeRemoveEventHandlerPW(HNType hType, HNObject hObject, const NWChar * szName, NTypeOfProc pCallbackTypeOf, HNCallback hCallback);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NTypeRemoveEventHandlerP(HNType hType, HNObject hObject, const NChar * szName, NTypeOfProc pCallbackTypeOf, HNCallback hCallback);
#endif
#define NTypeRemoveEventHandlerP N_FUNC_AW(NTypeRemoveEventHandlerP)

NResult N_API NTypeGetModule(HNType hType, HNModule * phValue);

NResult N_API NTypeGetNameN(HNType hType, HNString * phValue);
#ifndef N_NO_ANSI_FUNC
N_DEPRECATED("function is deprecated, use NTypeGetNameN instead")
NResult N_API NTypeGetNameExA(HNType hType, NAChar * szValue, NInt valueSize);
#endif
#ifndef N_NO_UNICODE
N_DEPRECATED("function is deprecated, use NTypeGetNameN instead")
NResult N_API NTypeGetNameExW(HNType hType, NWChar * szValue, NInt valueSize);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NTypeGetNameEx(HNType hType, NChar * szValue, NInt valueSize);
#endif
#define NTypeGetNameEx N_FUNC_AW(NTypeGetNameEx)

NResult N_API NTypeGetBaseType(HNType hType, HNType * phValue);
NResult N_API NTypeGetTypeCode(HNType hType, NTypeCode * pValue);
NResult N_API NTypeGetRootType(HNType hType, HNType * phValue);
NResult N_API NTypeGetRootTypeCode(HNType hType, NTypeCode * pValue);
NResult N_API NTypeGetValueSize(HNType hType, NSizeType * pValue);
NResult N_API NTypeIsBasic(HNType hType, NBool * pValue);
NResult N_API NTypeIsPrimitive(HNType hType, NBool * pValue);
NResult N_API NTypeIsEnum(HNType hType, NBool * pValue);
NResult N_API NTypeIsStruct(HNType hType, NBool * pValue);
NResult N_API NTypeIsCallback(HNType hType, NBool * pValue);
NResult N_API NTypeIsHandle(HNType hType, NBool * pValue);
NResult N_API NTypeIsObject(HNType hType, NBool * pValue);
NResult N_API NTypeGetAttributes(HNType hType, NAttributes * pValue);
NResult N_API NTypeIsDisposable(HNType hType, NBool * pValue);
NResult N_API NTypeIsPublic(HNType hType, NBool * pValue);
NResult N_API NTypeIsStatic(HNType hType, NBool * pValue);
NResult N_API NTypeIsSealed(HNType hType, NBool * pValue);
NResult N_API NTypeIsAbstract(HNType hType, NBool * pValue);
NResult N_API NTypeIsDeprecated(HNType hType, NBool * pValue);
NResult N_API NTypeGetUseInsteadType(HNType hType, HNType * phValue);
NResult N_API NTypeIsEquatable(HNType hType, NBool * pValue);
NResult N_API NTypeIsComparable(HNType hType, NBool * pValue);
NResult N_API NTypeIsParsable(HNType hType, NBool * pValue);
NResult N_API NTypeIsSignNeutral(HNType hType, NBool * pValue);
NResult N_API NTypeIsFlagsEnum(HNType hType, NBool * pValue);
NResult N_API NTypeIsCloneable(HNType hType, NBool * pValue);
NResult N_API NTypeIsSerializable(HNType hType, NBool * pValue);
NResult N_API NTypeIsMemorySerializable(HNType hType, NBool * pValue);
NResult N_API NTypeGetOwnerType(HNType hType, HNType * phValue);
NResult N_API NTypeHasOwnerType(HNType hType, NBool * pValue);
NResult N_API NTypeDisposeValue(HNType hType, void * pValue, NSizeType valueSize);
NResult N_API NTypeDisposeValues(HNType hType, void * arValues, NSizeType valuesSize, NInt valuesLength);
NResult N_API NTypeFreeValues(HNType hType, void * arValues, NSizeType valuesSize, NInt valuesLength);
NResult N_API NTypeCopyValue(HNType hType, const void * pSrcValue, NSizeType srcValueSize, void * pDstValue, NSizeType dstValueSize);
NResult N_API NTypeSetValue(HNType hType, const void * pSrcValue, NSizeType srcValueSize, void * pDstValue, NSizeType dstValueSize);
NResult N_API NTypeAreValuesEqual(HNType hType, const void * pValue1, NSizeType value1Size, const void * pValue2, NSizeType value2Size, NBool * pResult);
NResult N_API NTypeCompareValues(HNType hType, const void * pValue1, NSizeType value1Size, const void * pValue2, NSizeType value2Size, NInt * pResult);
NResult N_API NTypeGetValueHashCode(HNType hType, const void * pValue, NSizeType valueSize, NInt * pResult);
NResult N_API NTypeValueToStringN(HNType hType, const void * pValue, NSizeType valueSize, HNString hFormat, HNString * phValue);
NResult N_API NTypeValueToStringA(HNType hType, const void * pValue, NSizeType valueSize, const NAChar * szFormat, HNString * phValue);
#ifndef N_NO_UNICODE
NResult N_API NTypeValueToStringW(HNType hType, const void * pValue, NSizeType valueSize, const NWChar * szFormat, HNString * phValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NTypeValueToString(HNType hType, const void * pValue, NSizeType valueSize, const NChar * szFormat, HNString * phValue);
#endif
#define NTypeValueToString N_FUNC_AW(NTypeValueToString)

NResult N_API NTypeTryParseValueN(HNType hType, HNString hValue, HNString hFormat, void * pValue, NSizeType valueSize, NBool * pResult);
NResult N_API NTypeTryParseValueVNA(HNType hType, HNString hValue, const NAChar * szFormat, void * pValue, NSizeType valueSize, NBool * pResult);
#ifndef N_NO_UNICODE
NResult N_API NTypeTryParseValueVNW(HNType hType, HNString hValue, const NWChar * szFormat, void * pValue, NSizeType valueSize, NBool * pResult);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NTypeTryParseValueVN(HNType hType, HNString hValue, const NChar * szFormat, void * pValue, NSizeType valueSize, NBool * pResult);
#endif
#define NTypeTryParseValueVN N_FUNC_AW(NTypeTryParseValueVN)

NResult N_API NTypeTryParseValueA(HNType hType, const NAChar * szValue, const NAChar * szFormat, void * pValue, NSizeType valueSize, NBool * pResult);
#ifndef N_NO_UNICODE
NResult N_API NTypeTryParseValueW(HNType hType, const NWChar * szValue, const NWChar * szFormat, void * pValue, NSizeType valueSize, NBool * pResult);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NTypeTryParseValue(HNType hType, const NChar * szValue, const NChar * szFormat, void * pValue, NSizeType valueSize, NBool * pResult);
#endif
#define NTypeTryParseValue N_FUNC_AW(NTypeTryParseValue)

NResult N_API NTypeParseValueN(HNType hType, HNString hValue, HNString hFormat, void * pValue, NSizeType valueSize);
NResult N_API NTypeParseValueVNA(HNType hType, HNString hValue, const NAChar * szFormat, void * pValue, NSizeType valueSize);
#ifndef N_NO_UNICODE
NResult N_API NTypeParseValueVNW(HNType hType, HNString hValue, const NWChar * szFormat, void * pValue, NSizeType valueSize);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NTypeParseValueVN(HNType hType, HNString hValue, const NChar * szFormat, void * pValue, NSizeType valueSize);
#endif
#define NTypeParseValueVN N_FUNC_AW(NTypeParseValueVN)

NResult N_API NTypeParseValueA(HNType hType, const NAChar * szValue, const NAChar * szFormat, void * pValue, NSizeType valueSize);
#ifndef N_NO_UNICODE
NResult N_API NTypeParseValueW(HNType hType, const NWChar * szValue, const NWChar * szFormat, void * pValue, NSizeType valueSize);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NTypeParseValue(HNType hType, const NChar * szValue, const NChar * szFormat, void * pValue, NSizeType valueSize);
#endif
#define NTypeParseValue N_FUNC_AW(NTypeParseValue)

NResult N_API NTypeGetDeclaredEnumConstantCount(HNType hType, NInt * pValue);
NResult N_API NTypeGetDeclaredEnumConstant(HNType hType, NInt index, HNEnumConstantInfo * phValue);
NResult N_API NTypeGetDeclaredEnumConstants(HNType hType, HNEnumConstantInfo * * parhValues, NInt * pValueCount);

NResult N_API NTypeGetDeclaredEnumConstantWithNameN(HNType hType, HNString hName, HNEnumConstantInfo * phValue);
#ifndef N_NO_ANSI_FUNC
NResult N_API NTypeGetDeclaredEnumConstantWithNameA(HNType hType, const NAChar * szName, HNEnumConstantInfo * phValue);
#endif
#ifndef N_NO_UNICODE
NResult N_API NTypeGetDeclaredEnumConstantWithNameW(HNType hType, const NWChar * szName, HNEnumConstantInfo * phValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NTypeGetDeclaredEnumConstantWithName(HNType hType, const NChar * szName, HNEnumConstantInfo * phValue);
#endif
#define NTypeGetDeclaredEnumConstantWithName N_FUNC_AW(NTypeGetDeclaredEnumConstantWithName)

NResult N_API NTypeGetEnumAlternative(HNType hType, HNType * phValue);

NResult N_API NTypeGetDeclaredFieldCount(HNType hType, NInt * pValue);
NResult N_API NTypeGetDeclaredField(HNType hType, NInt index, HNPropertyInfo * phValue);
NResult N_API NTypeGetDeclaredFields(HNType hType, HNPropertyInfo * * parhValues, NInt * pValueCount);

NResult N_API NTypeGetDeclaredFieldWithNameN(HNType hType, HNString hName, HNPropertyInfo * phValue);
#ifndef N_NO_ANSI_FUNC
NResult N_API NTypeGetDeclaredFieldWithNameA(HNType hType, const NAChar * szName, HNPropertyInfo * phValue);
#endif
#ifndef N_NO_UNICODE
NResult N_API NTypeGetDeclaredFieldWithNameW(HNType hType, const NWChar * szName, HNPropertyInfo * phValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NTypeGetDeclaredFieldWithName(HNType hType, const NChar * szName, HNPropertyInfo * phValue);
#endif
#define NTypeGetDeclaredFieldWithName N_FUNC_AW(NTypeGetDeclaredFieldWithName)

NResult N_API NTypeGetDeclaredConstantCount(HNType hType, NInt * pValue);
NResult N_API NTypeGetDeclaredConstant(HNType hType, NInt index, HNConstantInfo * phValue);
NResult N_API NTypeGetDeclaredConstants(HNType hType, HNConstantInfo * * parhValues, NInt * pValueCount);

NResult N_API NTypeGetDeclaredConstantWithNameN(HNType hType, HNString hName, HNConstantInfo * phValue);
#ifndef N_NO_ANSI_FUNC
NResult N_API NTypeGetDeclaredConstantWithNameA(HNType hType, const NAChar * szName, HNConstantInfo * phValue);
#endif
#ifndef N_NO_UNICODE
NResult N_API NTypeGetDeclaredConstantWithNameW(HNType hType, const NWChar * szName, HNConstantInfo * phValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NTypeGetDeclaredConstantWithName(HNType hType, const NChar * szName, HNConstantInfo * phValue);
#endif
#define NTypeGetDeclaredConstantWithName N_FUNC_AW(NTypeGetDeclaredConstantWithName)

NResult N_API NTypeGetDeclaredConstructorCount(HNType hType, NInt * pValue);
NResult N_API NTypeGetDeclaredConstructor(HNType hType, NInt index, HNMethodInfo * phValue);
NResult N_API NTypeGetDeclaredConstructors(HNType hType, HNMethodInfo * * parhValues, NInt * pValueCount);

NResult N_API NTypeGetDeclaredMethodCount(HNType hType, NInt * pValue);
NResult N_API NTypeGetDeclaredMethod(HNType hType, NInt index, HNMethodInfo * phValue);
NResult N_API NTypeGetDeclaredMethods(HNType hType, HNMethodInfo * * parhValues, NInt * pValueCount);

NResult N_API NTypeGetDeclaredMethodWithNameN(HNType hType, HNString hName, HNMethodInfo * phValue);
#ifndef N_NO_ANSI_FUNC
NResult N_API NTypeGetDeclaredMethodWithNameA(HNType hType, const NAChar * szName, HNMethodInfo * phValue);
#endif
#ifndef N_NO_UNICODE
NResult N_API NTypeGetDeclaredMethodWithNameW(HNType hType, const NWChar * szName, HNMethodInfo * phValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NTypeGetDeclaredMethodWithName(HNType hType, const NChar * szName, HNMethodInfo * phValue);
#endif
#define NTypeGetDeclaredMethodWithName N_FUNC_AW(NTypeGetDeclaredMethodWithName)

NResult N_API NTypeGetDeclaredMethodsWithNameN(HNType hType, HNString hName, HNMethodInfo * * parhValues, NInt * pValueCount);
#ifndef N_NO_ANSI_FUNC
NResult N_API NTypeGetDeclaredMethodsWithNameA(HNType hType, const NAChar * szName, HNMethodInfo * * parhValues, NInt * pValueCount);
#endif
#ifndef N_NO_UNICODE
NResult N_API NTypeGetDeclaredMethodsWithNameW(HNType hType, const NWChar * szName, HNMethodInfo * * parhValues, NInt * pValueCount);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NTypeGetDeclaredMethodsWithName(HNType hType, const NChar * szName, HNMethodInfo * * parhValues, NInt * pValueCount);
#endif
#define NTypeGetDeclaredMethodsWithName N_FUNC_AW(NTypeGetDeclaredMethodsWithName)

NResult N_API NTypeGetDeclaredPropertyCount(HNType hType, NInt * pValue);
NResult N_API NTypeGetDeclaredProperty(HNType hType, NInt index, HNPropertyInfo * phValue);
NResult N_API NTypeGetDeclaredProperties(HNType hType, HNPropertyInfo * * parhValues, NInt * pValueCount);

NResult N_API NTypeGetDeclaredPropertyWithNameN(HNType hType, HNString hName, HNPropertyInfo * phValue);
#ifndef N_NO_ANSI_FUNC
NResult N_API NTypeGetDeclaredPropertyWithNameA(HNType hType, const NAChar * szName, HNPropertyInfo * phValue);
#endif
#ifndef N_NO_UNICODE
NResult N_API NTypeGetDeclaredPropertyWithNameW(HNType hType, const NWChar * szName, HNPropertyInfo * phValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NTypeGetDeclaredPropertyWithName(HNType hType, const NChar * szName, HNPropertyInfo * phValue);
#endif
#define NTypeGetDeclaredPropertyWithName N_FUNC_AW(NTypeGetDeclaredPropertyWithName)

NResult N_API NTypeGetDeclaredEventCount(HNType hType, NInt * pValue);
NResult N_API NTypeGetDeclaredEvent(HNType hType, NInt index, HNEventInfo * phValue);
NResult N_API NTypeGetDeclaredEvents(HNType hType, HNEventInfo * * parhValues, NInt * pValueCount);

NResult N_API NTypeGetDeclaredEventWithNameN(HNType hType, HNString hName, HNEventInfo * phValue);
#ifndef N_NO_ANSI_FUNC
NResult N_API NTypeGetDeclaredEventWithNameA(HNType hType, const NAChar * szName, HNEventInfo * phValue);
#endif
#ifndef N_NO_UNICODE
NResult N_API NTypeGetDeclaredEventWithNameW(HNType hType, const NWChar * szName, HNEventInfo * phValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NTypeGetDeclaredEventWithName(HNType hType, const NChar * szName, HNEventInfo * phValue);
#endif
#define NTypeGetDeclaredEventWithName N_FUNC_AW(NTypeGetDeclaredEventWithName)

NResult N_API NTypeGetDeclaredPartCount(HNType hType, NInt * pValue);
NResult N_API NTypeGetDeclaredPart(HNType hType, NInt index, HNObjectPartInfo * phValue);
NResult N_API NTypeGetDeclaredParts(HNType hType, HNObjectPartInfo * * parhValues, NInt * pValueCount);

NResult N_API NTypeGetDeclaredPartWithNameN(HNType hType, HNString hName, HNObjectPartInfo * phValue);
#ifndef N_NO_ANSI_FUNC
NResult N_API NTypeGetDeclaredPartWithNameA(HNType hType, const NAChar * szName, HNObjectPartInfo * phValue);
#endif
#ifndef N_NO_UNICODE
NResult N_API NTypeGetDeclaredPartWithNameW(HNType hType, const NWChar * szName, HNObjectPartInfo * phValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NTypeGetDeclaredPartWithName(HNType hType, const NChar * szName, HNObjectPartInfo * phValue);
#endif
#define NTypeGetDeclaredPartWithName N_FUNC_AW(NTypeGetDeclaredPartWithName)

NResult N_API NTypeIdentifierToStringN(HNString hValue, HNString hFormat, HNString * phValue);
#ifndef N_NO_ANSI_FUNC
NResult N_API NTypeIdentifierToStringVNA(HNString hValue, const NAChar * szFormat, HNString * phValue);
#endif
#ifndef N_NO_UNICODE
NResult N_API NTypeIdentifierToStringVNW(HNString hValue, const NWChar * szFormat, HNString * phValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NTypeIdentifierToStringVN(HNString hValue, const NChar * szFormat, HNString * phValue);
#endif
#define NTypeIdentifierToStringVN N_FUNC_AW(NTypeIdentifierToStringVN)
#ifndef N_NO_ANSI_FUNC
NResult N_API NTypeIdentifierToStringFNA(const NAChar * szValue, HNString hFormat, HNString * phValue);
#endif
#ifndef N_NO_UNICODE
NResult N_API NTypeIdentifierToStringFNW(const NWChar * szValue, HNString hFormat, HNString * phValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NTypeIdentifierToStringFN(const NChar * szValue, HNString hFormat, HNString * phValue);
#endif
#define NTypeIdentifierToStringFN N_FUNC_AW(NTypeIdentifierToStringFN)
#ifndef N_NO_ANSI_FUNC
NResult N_API NTypeIdentifierToStringA(const NAChar * szValue, const NAChar * szFormat, HNString * phValue);
#endif
#ifndef N_NO_UNICODE
NResult N_API NTypeIdentifierToStringW(const NWChar * szValue, const NWChar * szFormat, HNString * phValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NTypeIdentifierToString(const NChar * szValue, const NChar * szFormat, HNString * phValue);
#endif
#define NTypeIdentifierToString N_FUNC_AW(NTypeIdentifierToString)

#define NTypeCopyParameters(hType, hDstObject, hSrcObject) NTypeCopyPropertyValues(hType, hDstObject, hSrcObject)

#ifdef N_MSVC
	#pragma deprecated("NTypeCopyParameters")
#endif

#ifdef N_CPP
}
#endif

#include <Core/NValue.h>
#include <Core/NModule.h>
#if !defined(N_TYPE_HPP_INCLUDED) && !defined(N_OBJECT_HPP_INCLUDED)
#include <Reflection/NPropertyInfo.h>
#endif

#endif // !N_TYPE_H_INCLUDED
