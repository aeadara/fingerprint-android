#ifndef N_TYPES_H_INCLUDED
#define N_TYPES_H_INCLUDED

#include <Core/NDefs.h>
#include <stdarg.h>

#ifdef N_CPP
extern "C"
{
#endif
	
#ifdef N_MSVC
	#define N_VA_LIST_INIT = 0
	#if _MSC_VER < 1800
		#define va_copy(dest, src) (dest) = (src)
	#endif
#else
	#define N_VA_LIST_INIT = { 0 }
#endif

#define N_DECLATE_PRIMITIVE(name, size) typedef struct { union { void * ptr; /* for correct alignment */ NByte data[size]; } unused; } name;
#define N_DECLARE_HANDLE(name) typedef struct name##_ { int unused; } * name;

#ifdef N_MSVC
	typedef signed __int32 NResult;
#else
	typedef signed int NResult;
#endif

#define N_TYPE_OF(name) N_JOIN_SYMBOLS(name, TypeOf)

#define N_DECLARE_TYPE(name) \
	NResult N_API name##TypeOf(HNType * phValue);

#define N_DECLARE_STATIC_OBJECT_TYPE(name) \
	N_DECLARE_TYPE(name)

#ifdef N_CPP
	#define N_DECLARE_OBJECT_TYPE(name, baseName) \
		typedef class H##name##_ : public H##baseName##_ { } * H##name;\
		N_DECLARE_STATIC_OBJECT_TYPE(name)
#else
	#define N_DECLARE_OBJECT_TYPE(name, baseName) \
		typedef H##baseName H##name;\
		N_DECLARE_STATIC_OBJECT_TYPE(name)
#endif

N_DECLARE_HANDLE(HNObject)
N_DECLARE_OBJECT_TYPE(NType, NObject)
N_DECLARE_OBJECT_TYPE(NObjectPart, NObject)
N_DECLARE_TYPE(NObject)

#define N_DECLARE_HANDLE_TYPE(name) \
	N_DECLARE_HANDLE(H##name)\
	N_DECLARE_TYPE(name)

N_DECLARE_HANDLE_TYPE(NString)
N_DECLARE_HANDLE_TYPE(NCallback)

N_DECLARE_TYPE(NResult)

#ifdef N_MSVC
	typedef unsigned __int8  NUInt8;
	typedef signed   __int8  NInt8;
	typedef unsigned __int16 NUInt16;
	typedef signed   __int16 NInt16;
	typedef unsigned __int32 NUInt32;
	typedef signed   __int32 NInt32;

	#define N_UINT8_MIN 0x00ui8
	#define N_UINT8_MAX 0xFFui8
	#define N_INT8_MIN 0x80i8
	#define N_INT8_MAX 0x7Fi8
	#define N_UINT16_MIN 0x0000ui16
	#define N_UINT16_MAX 0xFFFFui16
	#define N_INT16_MIN 0x8000i16
	#define N_INT16_MAX 0x7FFFi16
	#define N_UINT32_MIN 0x00000000ui32
	#define N_UINT32_MAX 0xFFFFFFFFui32
	#define N_INT32_MIN 0x80000000i32
	#define N_INT32_MAX 0x7FFFFFFFi32
#else
	typedef unsigned char  NUInt8;
	typedef signed   char  NInt8;
	typedef unsigned short NUInt16;
	typedef signed   short NInt16;
	typedef unsigned int   NUInt32;
	typedef signed   int   NInt32;

	#define N_UINT8_MIN ((NUInt8)0x00u)
	#define N_UINT8_MAX ((NUInt8)0xFFu)
	#define N_INT8_MIN ((NInt8)0x80)
	#define N_INT8_MAX ((NInt8)0x7F)
	#define N_UINT16_MIN ((NUInt16)0x0000u)
	#define N_UINT16_MAX ((NUInt16)0xFFFFu)
	#define N_INT16_MIN ((NInt16)0x8000)
	#define N_INT16_MAX ((NInt16)0x7FFF)
	#define N_UINT32_MIN 0x00000000u
	#define N_UINT32_MAX 0xFFFFFFFFu
	#define N_INT32_MIN ((NInt32)0x80000000)
	#define N_INT32_MAX 0x7FFFFFFF
#endif
N_DECLARE_TYPE(NUInt8)
N_DECLARE_TYPE(NInt8)
N_DECLARE_TYPE(NUInt16)
N_DECLARE_TYPE(NInt16)
N_DECLARE_TYPE(NUInt32)
N_DECLARE_TYPE(NInt32)

#ifndef N_NO_INT_64
	#ifdef N_MSVC
		typedef unsigned __int64 NUInt64;
		typedef signed   __int64 NInt64;

		#define N_UINT64_MIN 0x0000000000000000ui64
		#define N_UINT64_MAX 0xFFFFFFFFFFFFFFFFui64
		#define N_INT64_MIN 0x8000000000000000i64
		#define N_INT64_MAX 0x7FFFFFFFFFFFFFFFi64
	#else
		typedef unsigned long long NUInt64;
		typedef signed   long long NInt64;

		#define N_UINT64_MIN 0x0000000000000000ull
		#define N_UINT64_MAX 0xFFFFFFFFFFFFFFFFull
		#define N_INT64_MIN ((NInt64)0x8000000000000000ull)
		#define N_INT64_MAX 0x7FFFFFFFFFFFFFFFll
	#endif
	N_DECLARE_TYPE(NUInt64)
	N_DECLARE_TYPE(NInt64)
#endif


typedef NUInt8 NByte;
typedef NInt8 NSByte;
typedef NUInt16 NUShort;
typedef NInt16 NShort;
typedef NUInt32 NUInt;
typedef NInt32 NInt;

#ifndef N_NO_INT_64
	typedef NUInt64 NULong;
	typedef NInt64 NLong;
#endif

#define N_BYTE_MIN N_UINT8_MIN
#define N_BYTE_MAX N_UINT8_MAX
#define N_SBYTE_MIN N_INT8_MIN
#define N_SBYTE_MAX N_INT8_MAX
#define N_USHORT_MIN N_UINT16_MIN
#define N_USHORT_MAX N_UINT16_MAX
#define N_SHORT_MIN N_INT16_MIN
#define N_SHORT_MAX N_INT16_MAX
#define N_UINT_MIN N_UINT32_MIN
#define N_UINT_MAX N_UINT32_MAX
#define N_INT_MIN N_INT32_MIN
#define N_INT_MAX N_INT32_MAX

#ifndef N_NO_INT_64
	#define N_ULONG_MIN N_UINT64_MIN
	#define N_ULONG_MAX N_UINT64_MAX
	#define N_LONG_MIN N_INT64_MIN
	#define N_LONG_MAX N_INT64_MAX
#endif

#ifndef N_NO_FLOAT
	typedef float NSingle;
	typedef double NDouble;
	N_DECLARE_TYPE(NSingle)
	N_DECLARE_TYPE(NDouble)

	#define N_SINGLE_MIN -3.402823466e+38F
	#define N_SINGLE_MAX 3.402823466e+38F
	#define N_SINGLE_EPSILON 1.192092896e-07F
	#define N_DOUBLE_MIN -1.7976931348623158e+308
	#define N_DOUBLE_MAX 1.7976931348623158e+308
	#define N_DOUBLE_EPSILON 2.2204460492503131e-016

	typedef NSingle NFloat;

	#define N_FLOAT_MIN N_SINGLE_MIN
	#define N_FLOAT_MAX N_SINGLE_MAX
	#define N_FLOAT_EPSILON N_SINGLE_EPSILON
#endif

typedef NInt NBoolean;
N_DECLARE_TYPE(NBoolean)

#define NTrue 1
#define NFalse 0

typedef NBoolean NBool;

typedef char NAChar;

#if defined(N_WINDOWS) || (defined(__SIZEOF_WCHAR_T__) && __SIZEOF_WCHAR_T__ == 2)
	#define N_WCHAR_SIZE 2

	#if !defined(N_NO_UNICODE) && !defined(_WCHAR_T_DEFINED)
		typedef NUShort NWChar;
	#endif
#else // !defined(N_WINDOWS) && (!defined(__SIZEOF_WCHAR_T__) || __SIZEOF_WCHAR_T__ != 2)
	#define N_WCHAR_SIZE 4

	#if !defined(N_NO_UNICODE) && !defined(_WCHAR_T_DEFINED) && !defined(_WCHAR_T)
		#ifdef N_CPP
			typedef wchar_t NWChar;
		#else
			#ifdef __WCHAR_TYPE__
				typedef __WCHAR_TYPE__ NWChar;
			#else
				typedef int NWChar;
			#endif
		#endif
	#endif
#endif // !defined(N_WINDOWS) && (!defined(__SIZEOF_WCHAR_T__) || __SIZEOF_WCHAR_T__ != 2)

#if !defined(N_NO_UNICODE) && defined(_WCHAR_T_DEFINED) || defined(_WCHAR_T)
	typedef wchar_t NWChar;
#endif

N_DECLARE_TYPE(NAChar)
#ifndef N_NO_UNICODE
N_DECLARE_TYPE(NWChar)
#endif
#ifdef N_DOCUMENTATION
N_DECLARE_TYPE(NChar)
#endif
#ifdef N_UNICODE
	typedef NWChar NChar;
	#define NCharTypeOf NWCharTypeOf
#else
	typedef NAChar NChar;
	#define NCharTypeOf NACharTypeOf
#endif

#ifdef N_64
	typedef NUInt64 NSizeType;
	typedef NInt64 NSSizeType;

	#define N_SIZE_TYPE_MIN N_UINT64_MIN
	#define N_SIZE_TYPE_MAX N_UINT64_MAX
	#define N_SSIZE_TYPE_MIN N_INT64_MIN
	#define N_SSIZE_TYPE_MAX N_INT64_MAX
#else
	#ifdef N_MSVC
		typedef __w64 NUInt32 NSizeType;
		typedef __w64 NInt32 NSSizeType;
	#else
		typedef NUInt32 NSizeType;
		typedef NInt32 NSSizeType;
	#endif

	#define N_SIZE_TYPE_MIN N_UINT32_MIN
	#define N_SIZE_TYPE_MAX N_UINT32_MAX
	#define N_SSIZE_TYPE_MIN N_INT32_MIN
	#define N_SSIZE_TYPE_MAX N_INT32_MAX
#endif
N_DECLARE_TYPE(NSizeType)
N_DECLARE_TYPE(NSSizeType)

#define N_PTR_SIZE sizeof(void *)
N_DECLARE_TYPE(NPointer)

#ifndef NULL
	#define NULL 0
#endif

#ifdef N_MSVC
#define N_UNREFERENCED_PARAMETER(parameter) (parameter)
#define N_UNUSED_VARIABLE(variable)
#else
#define N_UNREFERENCED_PARAMETER(parameter) (void)(parameter)
#define N_UNUSED_VARIABLE(variable) (void)(variable)
#endif

typedef void * NHandle;
N_DECLARE_TYPE(NHandle)

#define NMakeByte(lowNibble, highNibble) ((NByte)(((highNibble) << 4) | ((lowNibble) & 0x0F)))
#define NHiNibble(value) ((NByte)(((value) >> 4) & 0x0F))
#define NLoNibble(value) ((NByte)((value) & 0x0F))
#define NSwapNibbles(value) ((NByte)(((value) << 4) | (((value) >> 4) & 0x0F)))

#define NMakeWord(low, high) ((NUShort)(((NByte)(low)) | ((high) << 8)))
#define NHiByte(value) ((NByte)((value) >> 8))
#define NLoByte(value) ((NByte)(value))

#define NMakeDWord(low, high) ((NUInt)(((NUShort)(low)) | ((high) << 16)))
#define NHiWord(value) ((NUShort)((value) >> 16))
#define NLoWord(value) ((NUShort)(value))

#ifndef N_NO_INT_64

#define NMakeQWord(low, high) ((NULong)(((NUInt)(low)) | (((NULong)(high)) << 32)))
#define NHiDWord(value) ((NUInt)((value) >> 32))
#define NLoDWord(value) ((NUInt)(value))

#endif

#define NSwapWord(value) ((NUShort)((((NByte)(value)) << 8) | ((NByte)((value) >> 8))))
#define NSwapDWord(value) ((NUInt)((NSwapWord(value) << 16) | NSwapWord((value) >> 16)))

#ifndef N_NO_INT_64
#define NSwapQWord(value) ((NULong)(((NULong)NSwapDWord(value) << 32) | NSwapDWord((value) >> 32)))
#endif

#ifndef N_NO_FLOAT
NSingle N_API NSwapSingle(NSingle value);
NDouble N_API NSwapDouble(NDouble value);
#endif

#ifndef N_BIG_ENDIAN
	#define NHostToNetworkWord(value) NSwapWord(value)
	#define NHostToNetworkDWord(value) NSwapDWord(value)
	#define NNetworkToHostWord(value) NSwapWord(value)
	#define NNetworkToHostDWord(value) NSwapDWord(value)
#else
	#define NHostToNetworkWord(value) (value)
	#define NHostToNetworkDWord(value) (value)
	#define NNetworkToHostWord(value) (value)
	#define NNetworkToHostDWord(value) (value)
#endif

NByte N_API NReverseBits(NByte value);

NResult N_API NSwapWordArray(NUShort * pDstArray, const NUShort * pSrcArray, NInt length);
NResult N_API NSwapDWordArray(NUInt * pDstArray, const NUInt * pSrcArray, NInt length);
#ifndef N_NO_INT_64
NResult N_API NSwapQWordArray(NULong * pDstArray, const NULong * pSrcArray, NInt length);
#endif
#ifndef N_NO_FLOAT
NResult N_API NSwapSingleArray(NFloat * pDstArray, const NFloat * pSrcArray, NInt length);
NResult N_API NSwapDoubleArray(NDouble * pDstArray, const NDouble * pSrcArray, NInt length);
#endif

NResult N_API NInvertBufferBits(void * pDstBuffer, const void * pSrcBuffer, NSizeType bufferSize);
NResult N_API NReverseBufferBits(void * pDstBuffer, const void * pSrcBuffer, NSizeType bufferSize);

#define NIsFlagSet(flags, flag) (((flags) & (flag)) == (flag))
#define NSetFlag(flags, flag) ((flags) |= (flag))
#define NResetFlag(flags, flag) ((flags) &= ~(flag))
#define NSetFlagValue(flags, flag, value) ((value) ? NSetFlag(flags, flag) : NResetFlag(flags, flag))
#define NSetFlagIf(flags, flag, condition) ((condition) ? NSetFlag(flags, flag) : (flags))
#define NResetFlagIf(flags, flag, condition) ((condition) ? NResetFlag(flags, flag) : (flags))
#define NIsMoreThanOneFlagSet(value) ((value) & ((value) - 1))

#define NFieldOffset(type, field) ((NSizeType)((NByte *)&(((type *)(NSizeType)1)->field) - (NByte *)((type *)(NSizeType)1)))
#define NArrayLength(array) ((NInt)(sizeof(array) / sizeof(array[0])))

#define NMax(a, b) ((b) > (a) ? (b) : (a))
#define NMin(a, b) ((b) < (a) ? (b) : (a))
#define NRound(x) ((NInt)((x) >= 0 ? (x) + 0.5 : (x) - 0.5))
#define NRoundP(x) ((NUInt)((x) + 0.5))
#define NRoundF(x) ((NInt)((x) >= 0 ? (x) + 0.5f : (x) - 0.5f))
#define NRoundFP(x) ((NUInt)((x) + 0.5f))
#define NSqr(x) ((x) * (x))

#define N_SWAP(type, a, b) \
	{\
		type N_SWAP_temp = a;\
		a = b;\
		b = N_SWAP_temp;\
	}

#define N_FOREACH_P_(type, name, array, count) \
	{\
		type * name = (array);\
		type * N_FOREACH_P_##name##sEnd = name + (count);\
		for(; name < N_FOREACH_P_##name##sEnd; name++)\
		{

#define N_FOREACH_RP_(type, name, array, count) \
	{\
		type * N_FOREACH_RP_##name##sStart = (array);\
		type * name = N_FOREACH_RP_##name##sStart + (count) - 1;\
		for(; N_FOREACH_RP_##name##sStart != NULL && name >= N_FOREACH_RP_##name##sStart; name--)\
		{

#define N_FOREACH_P(type, name, array, count) \
	N_FOREACH_P_(type, name, array, count)\
	{

#define N_FOREACH_RP(type, name, array, count) \
	N_FOREACH_RP_(type, name, array, count)\
	{

#define N_FOREACH(type, name, array, count) \
	N_FOREACH_P_(type const, N_FOREACH_p##name, array, count)\
		type name = *N_FOREACH_p##name;\
		{

#define N_FOREACH_R(type, name, array, count) \
	N_FOREACH_RP_(type const, N_FOREACH_R_p##name, array, count)\
		type name = *N_FOREACH_R_p##name;\
		{

#define N_FOREACH_END \
			}\
		}\
	}

#define N_FOREACH_LP_(type, name, pList) \
	{\
		type * name;\
		type * N_FOREACH_LP_##name##sEnd;\
		N_CHECK(NListGetStart(pList, sizeof(*name), NULL, (void * *)&name));\
		N_CHECK(NListGetEnd(pList, sizeof(*name), NULL, (void * *)&N_FOREACH_LP_##name##sEnd));\
		for (; name < N_FOREACH_LP_##name##sEnd; name++)\
		{

#define N_FOREACH_LRP_(type, name, pList) \
	{\
		type * N_FOREACH_LRP_##name##sStart;\
		type * name;\
		N_CHECK(NListGetStart(pList, sizeof(*name), NULL, (void * *)&N_FOREACH_LRP_##name##sStart));\
		N_CHECK(NListGetEnd(pList, sizeof(*name), NULL, (void * *)&name));\
		name--;\
		for(; N_FOREACH_LRP_##name##sStart != NULL && name >= N_FOREACH_LRP_##name##sStart; name--)\
		{

#define N_FOREACH_LP(type, name, pList) \
	N_FOREACH_LP_(type, name, pList)\
	{

#define N_FOREACH_LRP(type, name, pList) \
	N_FOREACH_LRP_(type, name, pList)\
	{

#define N_FOREACH_L(type, name, pList) \
	N_FOREACH_LP_(type const, N_FOREACH_L_p##name, pList)\
		type name = *N_FOREACH_L_p##name;\
		{

#define N_FOREACH_LR(type, name, pList) \
	N_FOREACH_LRP_(type const, N_FOREACH_LR_p##name, pList)\
		type name = *N_FOREACH_LR_p##name;\
		{

#define N_FOREACH_LLP_(type, name, pList, listIndex) \
	{\
		type * name;\
		type * N_FOREACH_LLP_##name##sEnd;\
		N_CHECK(NListListGetItemsStart(pList, listIndex, sizeof(*name), NULL, (void * *)&name));\
		N_CHECK(NListListGetItemsEnd(pList, listIndex, sizeof(*name), NULL, (void * *)&N_FOREACH_LLP_##name##sEnd));\
		for (; name < N_FOREACH_LLP_##name##sEnd; name++)\
		{

#define N_FOREACH_LLRP_(type, name, pList, listIndex) \
	{\
		type * N_FOREACH_LLRP_##name##sStart;\
		type * name;\
		N_CHECK(NListListGetItemsStart(pList, listIndex, sizeof(*name), NULL, (void * *)&N_FOREACH_LLRP_##name##sStart));\
		N_CHECK(NListListGetItemsEnd(pList, listIndex, sizeof(*name), NULL, (void * *)&name));\
		name--;\
		for(; N_FOREACH_LLRP_##name##sStart != NULL && name >= N_FOREACH_LLRP_##name##sStart; name--)\
		{

#define N_FOREACH_LLP(type, name, pList, listIndex) \
	N_FOREACH_LLP_(type, name, pList, listIndex)\
	{

#define N_FOREACH_LLRP(type, name, pList, listIndex) \
	N_FOREACH_LLRP_(type, name, pList, listIndex)\
	{

#define N_FOREACH_LL(type, name, pList, listIndex) \
	N_FOREACH_LLP_(type const, N_FOREACH_LL_p##name, pList, listIndex)\
		type name = *N_FOREACH_LL_p##name;\
		{

#define N_FOREACH_LLR(type, name, pList, listIndex) \
	N_FOREACH_LLRP_(type const, N_FOREACH_LLR_p##name, pList, listIndex)\
		type name = *N_FOREACH_LLR_p##name;\
		{

#define N_FOREACH_C(type, name, hObject, pGetCount, pGet) \
	{\
		NInt N_FOREACH_C_c, N_FOREACH_C_i;\
		N_CHECK((pGetCount)(hObject, &N_FOREACH_C_c));\
		for (N_FOREACH_C_i = 0; N_FOREACH_C_i < N_FOREACH_C_c; N_FOREACH_C_i++)\
		{\
			type name;\
			N_CHECK((pGet)(hObject, N_FOREACH_C_i, &name));\
			{

#define N_FOREACH_CR(type, name, hObject, pGetCount, pGet) \
	{\
		NInt N_FOREACH_CR_c, N_FOREACH_CR_i;\
		N_CHECK((pGetCount)(hObject, &N_FOREACH_CR_c));\
		for (N_FOREACH_CR_i = N_FOREACH_CR_c - 1; N_FOREACH_CR_i >= 0; N_FOREACH_CR_i--)\
		{\
			type name;\
			N_CHECK((pGet)(hObject, N_FOREACH_CR_i, &name));\
			{

#define N_FOREACH_OC(var, hObject, pGetCount, pGet) \
	{\
		NInt N_FOREACH_OC_n, N_FOREACH_OC_c, N_FOREACH_OC_i;\
		N_CHECK((pGetCount)(hObject, &N_FOREACH_OC_c));\
		for (N_FOREACH_OC_n = 0; N_FOREACH_OC_n < 2; N_FOREACH_OC_n++)\
		for (N_FOREACH_OC_i = 0; N_FOREACH_OC_i < N_FOREACH_OC_c; N_FOREACH_OC_i++)\
		{\
			if ((N_FOREACH_OC_i != 0 || N_FOREACH_OC_n != 0) && var != NULL) { N_CHECK(NObjectSet(NULL, &var)); }\
			if (N_FOREACH_OC_n != 0) break;\
			N_CHECK((pGet)(hObject, N_FOREACH_OC_i, &var));\
			{

#define N_FOREACH_OCR(var, hObject, pGetCount, pGet) \
	{\
		NInt N_FOREACH_OCR_n, N_FOREACH_OCR_c, N_FOREACH_OCR_i;\
		N_CHECK((pGetCount)(hObject, &N_FOREACH_OCR_c));\
		for (N_FOREACH_OCR_n = 0; N_FOREACH_OCR_n < 2; N_FOREACH_OCR_n++)\
		for (N_FOREACH_OCR_i = N_FOREACH_OCR_c - 1; N_FOREACH_OCR_i >= 0; N_FOREACH_OCR_i--)\
		{\
			if ((N_FOREACH_OCR_i != N_FOREACH_OCR_c - 1 || N_FOREACH_OCR_n != 0) && var != NULL) { N_CHECK(NObjectSet(NULL, &var)); }\
			if (N_FOREACH_OCR_n != 0) break;\
			N_CHECK((pGet)(hObject, N_FOREACH_OCR_i, &var));\
			{

#define N_FOREACH_SC(var, hObject, pGetCount, pGet) \
	{\
		NInt N_FOREACH_SC_n, N_FOREACH_SC_c, N_FOREACH_SC_i;\
		N_CHECK((pGetCount)(hObject, &N_FOREACH_SC_c));\
		for (N_FOREACH_SC_n = 0; N_FOREACH_SC_n < 2; N_FOREACH_SC_n++)\
		for (N_FOREACH_SC_i = 0; N_FOREACH_SC_i < N_FOREACH_SC_c; N_FOREACH_SC_i++)\
		{\
			if (N_FOREACH_SC_i != 0 || N_FOREACH_SC_n != 0) { N_CHECK(NStringSet(NULL, &var)); }\
			if (N_FOREACH_SC_n != 0) break;\
			N_CHECK((pGet)(hObject, N_FOREACH_SC_i, &var));\
			{

#define N_FOREACH_SCR(var, hObject, pGetCount, pGet) \
	{\
		NInt N_FOREACH_SCR_n, N_FOREACH_SCR_c, N_FOREACH_SCR_i;\
		N_CHECK((pGetCount)(hObject, &N_FOREACH_SCR_c));\
		for (N_FOREACH_SCR_n = 0; N_FOREACH_SCR_n < 2; N_FOREACH_SCR_n++)\
		for (N_FOREACH_SCR_i = N_FOREACH_SCR_c - 1; N_FOREACH_SCR_i >= 0; N_FOREACH_SCR_i--)\
		{\
			if (N_FOREACH_SCR_i != N_FOREACH_SCR_c - 1 || N_FOREACH_SCR_n != 0) { N_CHECK(NStringSet(NULL, &var)); }\
			if (N_FOREACH_SCR_n != 0) break;\
			N_CHECK((pGet)(hObject, N_FOREACH_SCR_i, &var));\
			{

#define N_FOREACH_DC(type, var, hObject, pGetCount, pGet) \
	{\
		NInt N_FOREACH_DC_n, N_FOREACH_DC_c, N_FOREACH_DC_i;\
		N_CHECK((pGetCount)(hObject, &N_FOREACH_DC_c));\
		for (N_FOREACH_DC_n = 0; N_FOREACH_DC_n < 2; N_FOREACH_DC_n++)\
		for (N_FOREACH_DC_i = 0; N_FOREACH_DC_i < N_FOREACH_DC_c; N_FOREACH_DC_i++)\
		{\
			if (N_FOREACH_DC_i != 0 || N_FOREACH_DC_n != 0) { N_CHECK(type##Dispose(&var)); }\
			if (N_FOREACH_DC_n != 0) break;\
			N_CHECK((pGet)(hObject, N_FOREACH_DC_i, &var));\
			{

#define N_FOREACH_DCR(var, hObject, pGetCount, pGet) \
	{\
		NInt N_FOREACH_DCR_n, N_FOREACH_DCR_c, N_FOREACH_DCR_i;\
		N_CHECK((pGetCount)(hObject, &N_FOREACH_DCR_c));\
		for (N_FOREACH_DCR_n = 0; N_FOREACH_DCR_n < 2; N_FOREACH_DCR_n++)\
		for (N_FOREACH_DCR_i = N_FOREACH_DCR_c - 1; N_FOREACH_DCR_i >= 0; N_FOREACH_DCR_i--)\
		{\
			if (N_FOREACH_DCR_i != N_FOREACH_DCR_c - 1 || N_FOREACH_DCR_n != 0) { N_CHECK(type##Dispose(&var)); }\
			if (N_FOREACH_DCR_n != 0) break;\
			N_CHECK((pGet)(hObject, N_FOREACH_DCR_i, &var));\
			{

#ifndef N_NO_UNICODE
	#define N_FUNC_AW_IMPL_A_ALWAYS(funcAW) \
		funcAW(A)\
		funcAW(W)
	#ifdef N_NO_ANSI_FUNC
		#define N_FUNC_AW_IMPL(funcAW) \
			funcAW(W)
		#define N_FUNC_AW_IMPL_N(funcAW) \
			funcAW(W, W)
	#else // !N_NO_ANSI_FUNC
		#define N_FUNC_AW_IMPL(funcAW) \
			funcAW(A)\
			funcAW(W)
		#ifdef N_UNICODE
			#define N_FUNC_AW_IMPL_N(funcAW) \
				funcAW(A, W)\
				funcAW(W, W)
		#else
			#define N_FUNC_AW_IMPL_N(funcAW) \
				funcAW(A, A)\
				funcAW(W, A)
		#endif
	#endif
#else // N_NO_UNICODE
	#define N_FUNC_AW_IMPL_A_ALWAYS(funcAW) \
		funcAW(A)
	#define N_FUNC_AW_IMPL(funcAW) \
		funcAW(A)
	#define N_FUNC_AW_IMPL_N(funcAW) \
		funcAW(A, A)
#endif

#ifndef N_NO_FLOAT

#define N_FLOAT_NAN_STRINGA "NaN"
#ifndef N_NO_UNICODE
#define N_FLOAT_NAN_STRINGW L"NaN"
#endif
#define N_FLOAT_NAN_STRING N_MACRO_AW(N_FLOAT_NAN_STRING)

#define N_FLOAT_INFINITY_STRINGA "Infinity"
#ifndef N_NO_UNICODE
#define N_FLOAT_INFINITY_STRINGW L"Infinity"
#endif
#define N_FLOAT_INFINITY_STRING N_MACRO_AW(N_FLOAT_INFINITY_STRING)

#endif

#define N_BOOLEAN_TRUE_STRINGA "True"
#ifndef N_NO_UNICODE
#define N_BOOLEAN_TRUE_STRINGW L"True"
#endif
#define N_BOOLEAN_TRUE_STRING N_MACRO_AW(N_BOOLEAN_TRUE_STRING)

#define N_BOOLEAN_FALSE_STRINGA "False"
#ifndef N_NO_UNICODE
#define N_BOOLEAN_FALSE_STRINGW L"False"
#endif
#define N_BOOLEAN_FALSE_STRING N_MACRO_AW(N_BOOLEAN_FALSE_STRING)

struct NGuid_
{
	NUInt Data1;
	NUShort Data2;
	NUShort Data3;
	NByte Data4[8];
};
#ifndef N_TYPES_HPP_INCLUDED
typedef struct NGuid_ NGuid;
#endif
N_DECLARE_TYPE(NGuid)

struct NURational_
{
	NUInt Numerator;
	NUInt Denominator;
};
#ifndef N_TYPES_HPP_INCLUDED
typedef struct NURational_ NURational;
#endif
N_DECLARE_TYPE(NURational)

struct NRational_
{
	NInt Numerator;
	NInt Denominator;
};
#ifndef N_TYPES_HPP_INCLUDED
typedef struct NRational_ NRational;
#endif
N_DECLARE_TYPE(NRational)

struct NComplex_
{
	NDouble Real;
	NDouble Imaginary;
};
#ifndef N_TYPES_HPP_INCLUDED
typedef struct NComplex_ NComplex;
#endif
N_DECLARE_TYPE(NComplex)

struct NIndexPair_
{
	NInt Index1;
	NInt Index2;
};
#ifndef N_TYPES_HPP_INCLUDED
typedef struct NIndexPair_ NIndexPair;
#endif
N_DECLARE_TYPE(NIndexPair)

struct NRange_
{
	NInt From;
	NInt To;
};
#ifndef N_TYPES_HPP_INCLUDED
typedef struct NRange_ NRange;
#endif
N_DECLARE_TYPE(NRange)

typedef NUShort NVersion_;
#ifndef N_TYPES_HPP_INCLUDED
typedef NVersion_ NVersion;
#endif
N_DECLARE_TYPE(NVersion)

typedef NUInt NVersionRange_;
#ifndef N_TYPES_HPP_INCLUDED
typedef NVersionRange_ NVersionRange;
#endif
N_DECLARE_TYPE(NVersionRange)

typedef NResult (N_CALLBACK NPointerFreeProc)(void * ptr, void * pParam);
typedef NResult (N_CALLBACK NPointerGetHashCodeProc)(void * ptr, NInt * pValue, void * pParam);
typedef NResult (N_CALLBACK NPointerEqualsProc)(void * ptr, void * otherPtr, NBool * pResult, void * pParam);

void * N_API_PTR_RET NTypesGetPointer(void * value);

#ifndef N_NO_FLOAT

NSingle N_API NSingleGetPositiveInfinity();
NSingle N_API NSingleGetNegativeInfinity();
NSingle N_API NSingleGetNaN();

NBool N_API NSingleIsInfinity(NSingle value);
NBool N_API NSingleIsNegativeInfinity(NSingle value);
NBool N_API NSingleIsPositiveInfinity(NSingle value);
NBool N_API NSingleIsNaN(NSingle value);

NDouble N_API NDoubleGetPositiveInfinity();
NDouble N_API NDoubleGetNegativeInfinity();
NDouble N_API NDoubleGetNaN();

NBool N_API NDoubleIsInfinity(NDouble value);
NBool N_API NDoubleIsNegativeInfinity(NDouble value);
NBool N_API NDoubleIsPositiveInfinity(NDouble value);
NBool N_API NDoubleIsNaN(NDouble value);

#endif // !N_NO_FLOAT

NAChar N_API NCharFromDigitA(NInt value);
#ifndef N_NO_UNICODE
NWChar N_API NCharFromDigitW(NInt value);
#endif
#ifdef N_DOCUMENTATION
NChar N_API NCharFromDigit(NInt value);
#endif
#define NCharFromDigit N_FUNC_AW(NCharFromDigit)

NAChar N_API NCharFromHexDigitA(NInt value, NBool lowercase);
#ifndef N_NO_UNICODE
NWChar N_API NCharFromHexDigitW(NInt value, NBool lowercase);
#endif
#ifdef N_DOCUMENTATION
NChar N_API NCharFromHexDigit(NInt value, NBool lowercase);
#endif
#define NCharFromHexDigit N_FUNC_AW(NCharFromHexDigit)

NAChar N_API NCharFromOctDigitA(NInt value);
#ifndef N_NO_UNICODE
NWChar N_API NCharFromOctDigitW(NInt value);
#endif
#ifdef N_DOCUMENTATION
NChar N_API NCharFromOctDigit(NInt value);
#endif
#define NCharFromOctDigit N_FUNC_AW(NCharFromOctDigit)

NAChar N_API NCharFromBinDigitA(NInt value);
#ifndef N_NO_UNICODE
NWChar N_API NCharFromBinDigitW(NInt value);
#endif
#ifdef N_DOCUMENTATION
NChar N_API NCharFromBinDigit(NInt value);
#endif
#define NCharFromBinDigit N_FUNC_AW(NCharFromBinDigit)

NResult N_API NACharToCharsA(NAChar value, const NAChar * szFormat, NAChar * arValue, NInt valueLength);
#ifndef N_NO_UNICODE
NResult N_API NACharToCharsW(NAChar value, const NWChar * szFormat, NWChar * arValue, NInt valueLength);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NACharToChars(NAChar value, const NChar * szFormat, NChar * arValue, NInt valueLength);
#endif
#define NACharToChars N_FUNC_AW(NACharToChars)

#ifndef N_NO_UNICODE
NResult N_API NWCharToCharsA(NWChar value, const NAChar * szFormat, NAChar * arValue, NInt valueLength);
NResult N_API NWCharToCharsW(NWChar value, const NWChar * szFormat, NWChar * arValue, NInt valueLength);
#ifdef N_DOCUMENTATION
NResult N_API NWCharToChars(NWChar value, const NChar * szFormat, NChar * arValue, NInt valueLength);
#endif
#define NWCharToChars N_FUNC_AW(NWCharToChars)
#endif

#ifdef N_DOCUMENTATION
NResult N_API NCharToCharsA(NChar value, const NAChar * szFormat, NAChar * arValue, NInt valueLength);
NResult N_API NCharToCharsW(NChar value, const NWChar * szFormat, NWChar * arValue, NInt valueLength);
NResult N_API NCharToChars(NChar value, const NChar * szFormat, NChar * arValue, NInt valueLength);
#endif

#ifdef N_UNICODE
	#define NCharToCharsA NWCharToCharsA
	#define NCharToCharsW NWCharToCharsW
	#define NCharToChars NWCharToChars
#else
	#define NCharToCharsA NACharToCharsA
	#define NCharToCharsW NACharToCharsW
	#define NCharToChars NACharToChars
#endif

NResult N_API NResultToCharsA(NResult value, const NAChar * szFormat, NAChar * arValue, NInt valueLength);
#ifndef N_NO_UNICODE
NResult N_API NResultToCharsW(NResult value, const NWChar * szFormat, NWChar * arValue, NInt valueLength);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NResultToChars(NResult value, const NChar * szFormat, NChar * arValue, NInt valueLength);
#endif
#define NResultToChars N_FUNC_AW(NResultToChars)

NResult N_API NUInt8ToCharsA(NUInt8 value, const NAChar * szFormat, NAChar * arValue, NInt valueLength);
#ifndef N_NO_UNICODE
NResult N_API NUInt8ToCharsW(NUInt8 value, const NWChar * szFormat, NWChar * arValue, NInt valueLength);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NUInt8ToChars(NUInt8 value, const NChar * szFormat, NChar * arValue, NInt valueLength);
#endif
#define NUInt8ToChars N_FUNC_AW(NUInt8ToChars)

NResult N_API NInt8ToCharsA(NInt8 value, const NAChar * szFormat, NAChar * arValue, NInt valueLength);
#ifndef N_NO_UNICODE
NResult N_API NInt8ToCharsW(NInt8 value, const NWChar * szFormat, NWChar * arValue, NInt valueLength);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NInt8ToChars(NInt8 value, const NChar * szFormat, NChar * arValue, NInt valueLength);
#endif
#define NInt8ToChars N_FUNC_AW(NInt8ToChars)

NResult N_API NUInt16ToCharsA(NUInt16 value, const NAChar * szFormat, NAChar * arValue, NInt valueLength);
#ifndef N_NO_UNICODE
NResult N_API NUInt16ToCharsW(NUInt16 value, const NWChar * szFormat, NWChar * arValue, NInt valueLength);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NUInt16ToChars(NUInt16 value, const NChar * szFormat, NChar * arValue, NInt valueLength);
#endif
#define NUInt16ToChars N_FUNC_AW(NUInt16ToChars)

NResult N_API NInt16ToCharsA(NInt16 value, const NAChar * szFormat, NAChar * arValue, NInt valueLength);
#ifndef N_NO_UNICODE
NResult N_API NInt16ToCharsW(NInt16 value, const NWChar * szFormat, NWChar * arValue, NInt valueLength);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NInt16ToChars(NInt16 value, const NChar * szFormat, NChar * arValue, NInt valueLength);
#endif
#define NInt16ToChars N_FUNC_AW(NInt16ToChars)

NResult N_API NUInt32ToCharsA(NUInt32 value, const NAChar * szFormat, NAChar * arValue, NInt valueLength);
#ifndef N_NO_UNICODE
NResult N_API NUInt32ToCharsW(NUInt32 value, const NWChar * szFormat, NWChar * arValue, NInt valueLength);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NUInt32ToChars(NUInt32 value, const NChar * szFormat, NChar * arValue, NInt valueLength);
#endif
#define NUInt32ToChars N_FUNC_AW(NUInt32ToChars)

NResult N_API NInt32ToCharsA(NInt32 value, const NAChar * szFormat, NAChar * arValue, NInt valueLength);
#ifndef N_NO_UNICODE
NResult N_API NInt32ToCharsW(NInt32 value, const NWChar * szFormat, NWChar * arValue, NInt valueLength);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NInt32ToChars(NInt32 value, const NChar * szFormat, NChar * arValue, NInt valueLength);
#endif
#define NInt32ToChars N_FUNC_AW(NInt32ToChars)

#ifndef N_NO_INT_64

NResult N_API NUInt64ToCharsA(NUInt64 value, const NAChar * szFormat, NAChar * arValue, NInt valueLength);
#ifndef N_NO_UNICODE
NResult N_API NUInt64ToCharsW(NUInt64 value, const NWChar * szFormat, NWChar * arValue, NInt valueLength);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NUInt64ToChars(NUInt64 value, const NChar * szFormat, NChar * arValue, NInt valueLength);
#endif
#define NUInt64ToChars N_FUNC_AW(NUInt64ToChars)

NResult N_API NInt64ToCharsA(NInt64 value, const NAChar * szFormat, NAChar * arValue, NInt valueLength);
#ifndef N_NO_UNICODE
NResult N_API NInt64ToCharsW(NInt64 value, const NWChar * szFormat, NWChar * arValue, NInt valueLength);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NInt64ToChars(NInt64 value, const NChar * szFormat, NChar * arValue, NInt valueLength);
#endif
#define NInt64ToChars N_FUNC_AW(NInt64ToChars)

#endif // !N_NO_INT_64

NResult N_API NSizeTypeToCharsA(NSizeType value, const NAChar * szFormat, NAChar * arValue, NInt valueLength);
#ifndef N_NO_UNICODE
NResult N_API NSizeTypeToCharsW(NSizeType value, const NWChar * szFormat, NWChar * arValue, NInt valueLength);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NSizeTypeToChars(NSizeType value, const NChar * szFormat, NChar * arValue, NInt valueLength);
#endif
#define NSizeTypeToChars N_FUNC_AW(NSizeTypeToChars)

NResult N_API NSSizeTypeToCharsA(NSSizeType value, const NAChar * szFormat, NAChar * arValue, NInt valueLength);
#ifndef N_NO_UNICODE
NResult N_API NSSizeTypeToCharsW(NSSizeType value, const NWChar * szFormat, NWChar * arValue, NInt valueLength);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NSSizeTypeToChars(NSSizeType value, const NChar * szFormat, NChar * arValue, NInt valueLength);
#endif
#define NSSizeTypeToChars N_FUNC_AW(NSSizeTypeToChars)

NResult N_API NPointerToCharsA(const void * value, const NAChar * szFormat, NAChar * arValue, NInt valueLength);
#ifndef N_NO_UNICODE
NResult N_API NPointerToCharsW(const void * value, const NWChar * szFormat, NWChar * arValue, NInt valueLength);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NPointerToChars(const void * value, const NChar * szFormat, NChar * arValue, NInt valueLength);
#endif
#define NPointerToChars N_FUNC_AW(NPointerToChars)

#ifndef N_NO_FLOAT

NResult N_API NSingleToCharsA(NSingle value, const NAChar * szFormat, NAChar * arValue, NInt valueLength);
#ifndef N_NO_UNICODE
NResult N_API NSingleToCharsW(NSingle value, const NWChar * szFormat, NWChar * arValue, NInt valueLength);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NSingleToChars(NSingle value, const NChar * szFormat, NChar * arValue, NInt valueLength);
#endif
#define NSingleToChars N_FUNC_AW(NSingleToChars)

NResult N_API NDoubleToCharsA(NDouble value, const NAChar * szFormat, NAChar * arValue, NInt valueLength);
#ifndef N_NO_UNICODE
NResult N_API NDoubleToCharsW(NDouble value, const NWChar * szFormat, NWChar * arValue, NInt valueLength);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NDoubleToChars(NDouble value, const NChar * szFormat, NChar * arValue, NInt valueLength);
#endif
#define NDoubleToChars N_FUNC_AW(NDoubleToChars)

#endif // !N_NO_FLOAT

NResult N_API NBooleanToCharsA(NBoolean value, const NAChar * szFormat, NAChar * arValue, NInt valueLength);
#ifndef N_NO_UNICODE
NResult N_API NBooleanToCharsW(NBoolean value, const NWChar * szFormat, NWChar * arValue, NInt valueLength);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NBooleanToChars(NBoolean value, const NChar * szFormat, NChar * arValue, NInt valueLength);
#endif
#define NBooleanToChars N_FUNC_AW(NBooleanToChars)

NResult N_API NACharToStringN(NAChar value, HNString hFormat, HNString * phValue);
NResult N_API NACharToStringA(NAChar value, const NAChar * szFormat, HNString * phValue);
#ifndef N_NO_UNICODE
NResult N_API NACharToStringW(NAChar value, const NWChar * szFormat, HNString * phValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NACharToString(NAChar value, const NChar * szFormat, HNString * phValue);
#endif
#define NACharToString N_FUNC_AW(NACharToString)

#ifndef N_NO_UNICODE
NResult N_API NWCharToStringN(NWChar value, HNString hFormat, HNString * phValue);
NResult N_API NWCharToStringA(NWChar value, const NAChar * szFormat, HNString * phValue);
NResult N_API NWCharToStringW(NWChar value, const NWChar * szFormat, HNString * phValue);
#ifdef N_DOCUMENTATION
NResult N_API NWCharToString(NWChar value, const NChar * szFormat, HNString * phValue);
#endif
#define NWCharToString N_FUNC_AW(NWCharToString)
#endif

#ifdef N_DOCUMENTATION
NResult N_API NCharToStringN(NChar value, HNString hFormat, HNString * phValue);
NResult N_API NCharToStringA(NChar value, const NAChar * szFormat, HNString * phValue);
NResult N_API NCharToStringW(NChar value, const NWChar * szFormat, HNString * phValue);
NResult N_API NCharToString(NChar value, const NChar * szFormat, HNString * phValue);
#endif

#ifdef N_UNICODE
	#define NCharToStringN NWCharToStringN
	#define NCharToStringA NWCharToStringA
	#define NCharToStringW NWCharToStringW
	#define NCharToString NWCharToString
#else
	#define NCharToStringN NACharToStringN
	#define NCharToStringA NACharToCharsA
	#define NCharToStringW NACharToCharsW
	#define NCharToString NACharToString
#endif

NResult N_API NResultToStringN(NResult value, HNString hFormat, HNString * phValue);
NResult N_API NResultToStringA(NResult value, const NAChar * szFormat, HNString * phValue);
#ifndef N_NO_UNICODE
NResult N_API NResultToStringW(NResult value, const NWChar * szFormat, HNString * phValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NResultToString(NResult value, const NChar * szFormat, HNString * phValue);
#endif
#define NResultToString N_FUNC_AW(NResultToString)

NResult N_API NUInt8ToStringN(NUInt8 value, HNString hFormat, HNString * phValue);
NResult N_API NUInt8ToStringA(NUInt8 value, const NAChar * szFormat, HNString * phValue);
#ifndef N_NO_UNICODE
NResult N_API NUInt8ToStringW(NUInt8 value, const NWChar * szFormat, HNString * phValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NUInt8ToString(NUInt8 value, const NChar * szFormat, HNString * phValue);
#endif
#define NUInt8ToString N_FUNC_AW(NUInt8ToString)

NResult N_API NInt8ToStringN(NInt8 value, HNString hFormat, HNString * phValue);
NResult N_API NInt8ToStringA(NInt8 value, const NAChar * szFormat, HNString * phValue);
#ifndef N_NO_UNICODE
NResult N_API NInt8ToStringW(NInt8 value, const NWChar * szFormat, HNString * phValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NInt8ToString(NInt8 value, const NChar * szFormat, HNString * phValue);
#endif
#define NInt8ToString N_FUNC_AW(NInt8ToString)

NResult N_API NUInt16ToStringN(NUInt16 value, HNString hFormat, HNString * phValue);
NResult N_API NUInt16ToStringA(NUInt16 value, const NAChar * szFormat, HNString * phValue);
#ifndef N_NO_UNICODE
NResult N_API NUInt16ToStringW(NUInt16 value, const NWChar * szFormat, HNString * phValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NUInt16ToString(NUInt16 value, const NChar * szFormat, HNString * phValue);
#endif
#define NUInt16ToString N_FUNC_AW(NUInt16ToString)

NResult N_API NInt16ToStringN(NInt16 value, HNString hFormat, HNString * phValue);
NResult N_API NInt16ToStringA(NInt16 value, const NAChar * szFormat, HNString * phValue);
#ifndef N_NO_UNICODE
NResult N_API NInt16ToStringW(NInt16 value, const NWChar * szFormat, HNString * phValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NInt16ToString(NInt16 value, const NChar * szFormat, HNString * phValue);
#endif
#define NInt16ToString N_FUNC_AW(NInt16ToString)

NResult N_API NUInt32ToStringN(NUInt32 value, HNString hFormat, HNString * phValue);
NResult N_API NUInt32ToStringA(NUInt32 value, const NAChar * szFormat, HNString * phValue);
#ifndef N_NO_UNICODE
NResult N_API NUInt32ToStringW(NUInt32 value, const NWChar * szFormat, HNString * phValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NUInt32ToString(NUInt32 value, const NChar * szFormat, HNString * phValue);
#endif
#define NUInt32ToString N_FUNC_AW(NUInt32ToString)

NResult N_API NInt32ToStringN(NInt32 value, HNString hFormat, HNString * phValue);
NResult N_API NInt32ToStringA(NInt32 value, const NAChar * szFormat, HNString * phValue);
#ifndef N_NO_UNICODE
NResult N_API NInt32ToStringW(NInt32 value, const NWChar * szFormat, HNString * phValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NInt32ToString(NInt32 value, const NChar * szFormat, HNString * phValue);
#endif
#define NInt32ToString N_FUNC_AW(NInt32ToString)

#ifndef N_NO_INT_64

NResult N_API NUInt64ToStringN(NUInt64 value, HNString hFormat, HNString * phValue);
NResult N_API NUInt64ToStringA(NUInt64 value, const NAChar * szFormat, HNString * phValue);
#ifndef N_NO_UNICODE
NResult N_API NUInt64ToStringW(NUInt64 value, const NWChar * szFormat, HNString * phValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NUInt64ToString(NUInt64 value, const NChar * szFormat, HNString * phValue);
#endif
#define NUInt64ToString N_FUNC_AW(NUInt64ToString)

NResult N_API NInt64ToStringN(NInt64 value, HNString hFormat, HNString * phValue);
NResult N_API NInt64ToStringA(NInt64 value, const NAChar * szFormat, HNString * phValue);
#ifndef N_NO_UNICODE
NResult N_API NInt64ToStringW(NInt64 value, const NWChar * szFormat, HNString * phValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NInt64ToString(NInt64 value, const NChar * szFormat, HNString * phValue);
#endif
#define NInt64ToString N_FUNC_AW(NInt64ToString)

#endif // !N_NO_INT_64

NResult N_API NSizeTypeToStringN(NSizeType value, HNString hFormat, HNString * phValue);
NResult N_API NSizeTypeToStringA(NSizeType value, const NAChar * szFormat, HNString * phValue);
#ifndef N_NO_UNICODE
NResult N_API NSizeTypeToStringW(NSizeType value, const NWChar * szFormat, HNString * phValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NSizeTypeToString(NSizeType value, const NChar * szFormat, HNString * phValue);
#endif
#define NSizeTypeToString N_FUNC_AW(NSizeTypeToString)

NResult N_API NSSizeTypeToStringN(NSSizeType value, HNString hFormat, HNString * phValue);
NResult N_API NSSizeTypeToStringA(NSSizeType value, const NAChar * szFormat, HNString * phValue);
#ifndef N_NO_UNICODE
NResult N_API NSSizeTypeToStringW(NSSizeType value, const NWChar * szFormat, HNString * phValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NSSizeTypeToString(NSSizeType value, const NChar * szFormat, HNString * phValue);
#endif
#define NSSizeTypeToString N_FUNC_AW(NSSizeTypeToString)

NResult N_API NPointerToStringN(const void * value, HNString hFormat, HNString * phValue);
NResult N_API NPointerToStringA(const void * value, const NAChar * szFormat, HNString * phValue);
#ifndef N_NO_UNICODE
NResult N_API NPointerToStringW(const void * value, const NWChar * szFormat, HNString * phValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NPointerToString(const void * value, const NChar * szFormat, HNString * phValue);
#endif
#define NPointerToString N_FUNC_AW(NPointerToString)

#ifndef N_NO_FLOAT

NResult N_API NSingleToStringN(NSingle value, HNString hFormat, HNString * phValue);
NResult N_API NSingleToStringA(NSingle value, const NAChar * szFormat, HNString * phValue);
#ifndef N_NO_UNICODE
NResult N_API NSingleToStringW(NSingle value, const NWChar * szFormat, HNString * phValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NSingleToString(NSingle value, const NChar * szFormat, HNString * phValue);
#endif
#define NSingleToString N_FUNC_AW(NSingleToString)

NResult N_API NDoubleToStringN(NDouble value, HNString hFormat, HNString * phValue);
NResult N_API NDoubleToStringA(NDouble value, const NAChar * szFormat, HNString * phValue);
#ifndef N_NO_UNICODE
NResult N_API NDoubleToStringW(NDouble value, const NWChar * szFormat, HNString * phValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NDoubleToString(NDouble value, const NChar * szFormat, HNString * phValue);
#endif
#define NDoubleToString N_FUNC_AW(NDoubleToString)

#endif // !N_NO_FLOAT

NResult N_API NBooleanToStringN(NBoolean value, HNString hFormat, HNString * phValue);
NResult N_API NBooleanToStringA(NBoolean value, const NAChar * szFormat, HNString * phValue);
#ifndef N_NO_UNICODE
NResult N_API NBooleanToStringW(NBoolean value, const NWChar * szFormat, HNString * phValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NBooleanToString(NBoolean value, const NChar * szFormat, HNString * phValue);
#endif
#define NBooleanToString N_FUNC_AW(NBooleanToString)

NBool N_API NCharIsWhiteSpaceA(NAChar value);
#ifndef N_NO_UNICODE
NBool N_API NCharIsWhiteSpaceW(NWChar value);
#endif
#ifdef N_DOCUMENTATION
NBool N_API NCharIsWhiteSpace(NChar value);
#endif
#define NCharIsWhiteSpace N_FUNC_AW(NCharIsWhiteSpace)

NBool N_API NCharIsAsciiA(NAChar value);
#ifndef N_NO_UNICODE
NBool N_API NCharIsAsciiW(NWChar value);
#endif
#ifdef N_DOCUMENTATION
NBool N_API NCharIsAscii(NChar value);
#endif
#define NCharIsAscii N_FUNC_AW(NCharIsAscii)

NBool N_API NCharIsLetterA(NAChar value);
#ifndef N_NO_UNICODE
NBool N_API NCharIsLetterW(NWChar value);
#endif
#ifdef N_DOCUMENTATION
NBool N_API NCharIsLetter(NChar value);
#endif
#define NCharIsLetter N_FUNC_AW(NCharIsLetter)

NBool N_API NCharIsLowerA(NAChar value);
#ifndef N_NO_UNICODE
NBool N_API NCharIsLowerW(NWChar value);
#endif
#ifdef N_DOCUMENTATION
NBool N_API NCharIsLower(NChar value);
#endif
#define NCharIsLower N_FUNC_AW(NCharIsLower)

NBool N_API NCharIsUpperA(NAChar value);
#ifndef N_NO_UNICODE
NBool N_API NCharIsUpperW(NWChar value);
#endif
#ifdef N_DOCUMENTATION
NBool N_API NCharIsUpper(NChar value);
#endif
#define NCharIsUpper N_FUNC_AW(NCharIsUpper)

NBool N_API NCharIsDigitA(NAChar value);
#ifndef N_NO_UNICODE
NBool N_API NCharIsDigitW(NWChar value);
#endif
#ifdef N_DOCUMENTATION
NBool N_API NCharIsDigit(NChar value);
#endif
#define NCharIsDigit N_FUNC_AW(NCharIsDigit)

NBool N_API NCharIsHexDigitA(NAChar value);
#ifndef N_NO_UNICODE
NBool N_API NCharIsHexDigitW(NWChar value);
#endif
#ifdef N_DOCUMENTATION
NBool N_API NCharIsHexDigit(NChar value);
#endif
#define NCharIsHexDigit N_FUNC_AW(NCharIsHexDigit)

NBool N_API NCharIsOctDigitA(NAChar value);
#ifndef N_NO_UNICODE
NBool N_API NCharIsOctDigitW(NWChar value);
#endif
#ifdef N_DOCUMENTATION
NBool N_API NCharIsOctDigit(NChar value);
#endif
#define NCharIsOctDigit N_FUNC_AW(NCharIsOctDigit)

NBool N_API NCharIsBinDigitA(NAChar value);
#ifndef N_NO_UNICODE
NBool N_API NCharIsBinDigitW(NWChar value);
#endif
#ifdef N_DOCUMENTATION
NBool N_API NCharIsBinDigit(NChar value);
#endif
#define NCharIsBinDigit N_FUNC_AW(NCharIsBinDigit)

NAChar N_API NCharToLowerA(NAChar value);
#ifndef N_NO_UNICODE
NWChar N_API NCharToLowerW(NWChar value);
#endif
#ifdef N_DOCUMENTATION
NChar N_API NCharToLower(NChar value);
#endif
#define NCharToLower N_FUNC_AW(NCharToLower)

NAChar N_API NCharToUpperA(NAChar value);
#ifndef N_NO_UNICODE
NWChar N_API NCharToUpperW(NWChar value);
#endif
#ifdef N_DOCUMENTATION
NChar N_API NCharToUpper(NChar value);
#endif
#define NCharToUpper N_FUNC_AW(NCharToUpper)

NInt N_API NCharToDigitA(NAChar value);
#ifndef N_NO_UNICODE
NInt N_API NCharToDigitW(NWChar value);
#endif
#ifdef N_DOCUMENTATION
NInt N_API NCharToDigit(NChar value);
#endif
#define NCharToDigit N_FUNC_AW(NCharToDigit)

NInt N_API NCharToHexDigitA(NAChar value);
#ifndef N_NO_UNICODE
NInt N_API NCharToHexDigitW(NWChar value);
#endif
#ifdef N_DOCUMENTATION
NInt N_API NCharToHexDigit(NChar value);
#endif
#define NCharToHexDigit N_FUNC_AW(NCharToHexDigit)

NInt N_API NCharToOctDigitA(NAChar value);
#ifndef N_NO_UNICODE
NInt N_API NCharToOctDigitW(NWChar value);
#endif
#ifdef N_DOCUMENTATION
NInt N_API NCharToOctDigit(NChar value);
#endif
#define NCharToOctDigit N_FUNC_AW(NCharToOctDigit)

NInt N_API NCharToBinDigitA(NAChar value);
#ifndef N_NO_UNICODE
NInt N_API NCharToBinDigitW(NWChar value);
#endif
#ifdef N_DOCUMENTATION
NInt N_API NCharToBinDigit(NChar value);
#endif
#define NCharToBinDigit N_FUNC_AW(NCharToBinDigit)

NResult N_API NACharTryParseStrOrCharsA(const NAChar * arValue, NInt valueLength, const NAChar * szFormat, NAChar * pValue, NBool * pResult);
#ifndef N_NO_UNICODE
NResult N_API NACharTryParseStrOrCharsW(const NWChar * arValue, NInt valueLength, const NWChar * szFormat, NAChar * pValue, NBool * pResult);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NACharTryParseStrOrChars(const NChar * arValue, NInt valueLength, const NChar * szFormat, NAChar * pValue, NBool * pResult);
#endif
#define NACharTryParseStrOrChars N_FUNC_AW(NACharTryParseStrOrChars)

#ifndef N_NO_UNICODE
NResult N_API NWCharTryParseStrOrCharsA(const NAChar * arValue, NInt valueLength, const NAChar * szFormat, NWChar * pValue, NBool * pResult);
NResult N_API NWCharTryParseStrOrCharsW(const NWChar * arValue, NInt valueLength, const NWChar * szFormat, NWChar * pValue, NBool * pResult);
#ifdef N_DOCUMENTATION
NResult N_API NWCharTryParseStrOrChars(const NChar * arValue, NInt valueLength, const NChar * szFormat, NWChar * pValue, NBool * pResult);
#endif
#define NWCharTryParseStrOrChars N_FUNC_AW(NWCharTryParseStrOrChars)
#endif

#ifdef N_DOCUMENTATION
NResult N_API NCharTryParseStrOrCharsA(const NAChar * arValue, NInt valueLength, const NAChar * szFormat, NChar * pValue, NBool * pResult);
NResult N_API NCharTryParseStrOrCharsW(const NWChar * arValue, NInt valueLength, const NWChar * szFormat, NChar * pValue, NBool * pResult);
NResult N_API NCharTryParseStrOrChars(const NChar * arValue, NInt valueLength, const NChar * szFormat, NChar * pValue, NBool * pResult);
#endif

#ifdef N_UNICODE
	#define NCharTryParseStrOrCharsA NWCharTryParseStrOrCharsA
	#define NCharTryParseStrOrCharsW NWCharTryParseStrOrCharsW
	#define NCharTryParseStrOrChars NWCharTryParseStrOrChars
#else
	#define NCharTryParseStrOrCharsA NACharTryParseStrOrCharsA
	#define NCharTryParseStrOrCharsW NACharTryParseStrOrCharsW
	#define NCharTryParseStrOrChars NACharTryParseStrOrChars
#endif

NResult N_API NResultTryParseStrOrCharsA(const NAChar * arValue, NInt valueLength, const NAChar * szFormat, NResult * pValue, NBool * pResult);
#ifndef N_NO_UNICODE
NResult N_API NResultTryParseStrOrCharsW(const NWChar * arValue, NInt valueLength, const NWChar * szFormat, NResult * pValue, NBool * pResult);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NResultTryParseStrOrChars(const NChar * arValue, NInt valueLength, const NChar * szFormat, NResult * pValue, NBool * pResult);
#endif
#define NResultTryParseStrOrChars N_FUNC_AW(NResultTryParseStrOrChars)

NResult N_API NUInt8TryParseStrOrCharsA(const NAChar * arValue, NInt valueLength, const NAChar * szFormat, NUInt8 * pValue, NBool * pResult);
#ifndef N_NO_UNICODE
NResult N_API NUInt8TryParseStrOrCharsW(const NWChar * arValue, NInt valueLength, const NWChar * szFormat, NUInt8 * pValue, NBool * pResult);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NUInt8TryParseStrOrChars(const NChar * arValue, NInt valueLength, const NChar * szFormat, NUInt8 * pValue, NBool * pResult);
#endif
#define NUInt8TryParseStrOrChars N_FUNC_AW(NUInt8TryParseStrOrChars)

NResult N_API NInt8TryParseStrOrCharsA(const NAChar * arValue, NInt valueLength, const NAChar * szFormat, NInt8 * pValue, NBool * pResult);
#ifndef N_NO_UNICODE
NResult N_API NInt8TryParseStrOrCharsW(const NWChar * arValue, NInt valueLength, const NWChar * szFormat, NInt8 * pValue, NBool * pResult);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NInt8TryParseStrOrChars(const NChar * arValue, NInt valueLength, const NChar * szFormat, NInt8 * pValue, NBool * pResult);
#endif
#define NInt8TryParseStrOrChars N_FUNC_AW(NInt8TryParseStrOrChars)

NResult N_API NUInt16TryParseStrOrCharsA(const NAChar * arValue, NInt valueLength, const NAChar * szFormat, NUInt16 * pValue, NBool * pResult);
#ifndef N_NO_UNICODE
NResult N_API NUInt16TryParseStrOrCharsW(const NWChar * arValue, NInt valueLength, const NWChar * szFormat, NUInt16 * pValue, NBool * pResult);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NUInt16TryParseStrOrChars(const NChar * arValue, NInt valueLength, const NChar * szFormat, NUInt16 * pValue, NBool * pResult);
#endif
#define NUInt16TryParseStrOrChars N_FUNC_AW(NUInt16TryParseStrOrChars)

NResult N_API NInt16TryParseStrOrCharsA(const NAChar * arValue, NInt valueLength, const NAChar * szFormat, NInt16 * pValue, NBool * pResult);
#ifndef N_NO_UNICODE
NResult N_API NInt16TryParseStrOrCharsW(const NWChar * arValue, NInt valueLength, const NWChar * szFormat, NInt16 * pValue, NBool * pResult);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NInt16TryParseStrOrChars(const NChar * arValue, NInt valueLength, const NChar * szFormat, NInt16 * pValue, NBool * pResult);
#endif
#define NInt16TryParseStrOrChars N_FUNC_AW(NInt16TryParseStrOrChars)

NResult N_API NUInt32TryParseStrOrCharsA(const NAChar * arValue, NInt valueLength, const NAChar * szFormat, NUInt32 * pValue, NBool * pResult);
#ifndef N_NO_UNICODE
NResult N_API NUInt32TryParseStrOrCharsW(const NWChar * arValue, NInt valueLength, const NWChar * szFormat, NUInt32 * pValue, NBool * pResult);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NUInt32TryParseStrOrChars(const NChar * arValue, NInt valueLength, const NChar * szFormat, NUInt32 * pValue, NBool * pResult);
#endif
#define NUInt32TryParseStrOrChars N_FUNC_AW(NUInt32TryParseStrOrChars)

NResult N_API NInt32TryParseStrOrCharsA(const NAChar * arValue, NInt valueLength, const NAChar * szFormat, NInt32 * pValue, NBool * pResult);
#ifndef N_NO_UNICODE
NResult N_API NInt32TryParseStrOrCharsW(const NWChar * arValue, NInt valueLength, const NWChar * szFormat, NInt32 * pValue, NBool * pResult);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NInt32TryParseStrOrChars(const NChar * arValue, NInt valueLength, const NChar * szFormat, NInt32 * pValue, NBool * pResult);
#endif
#define NInt32TryParseStrOrChars N_FUNC_AW(NInt32TryParseStrOrChars)

#ifndef N_NO_INT_64

NResult N_API NUInt64TryParseStrOrCharsA(const NAChar * arValue, NInt valueLength, const NAChar * szFormat, NUInt64 * pValue, NBool * pResult);
#ifndef N_NO_UNICODE
NResult N_API NUInt64TryParseStrOrCharsW(const NWChar * arValue, NInt valueLength, const NWChar * szFormat, NUInt64 * pValue, NBool * pResult);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NUInt64TryParseStrOrChars(const NChar * arValue, NInt valueLength, const NChar * szFormat, NUInt64 * pValue, NBool * pResult);
#endif
#define NUInt64TryParseStrOrChars N_FUNC_AW(NUInt64TryParseStrOrChars)

NResult N_API NInt64TryParseStrOrCharsA(const NAChar * arValue, NInt valueLength, const NAChar * szFormat, NInt64 * pValue, NBool * pResult);
#ifndef N_NO_UNICODE
NResult N_API NInt64TryParseStrOrCharsW(const NWChar * arValue, NInt valueLength, const NWChar * szFormat, NInt64 * pValue, NBool * pResult);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NInt64TryParseStrOrChars(const NChar * arValue, NInt valueLength, const NChar * szFormat, NInt64 * pValue, NBool * pResult);
#endif
#define NInt64TryParseStrOrChars N_FUNC_AW(NInt64TryParseStrOrChars)

#endif // !N_NO_INT_64

NResult N_API NSizeTypeTryParseStrOrCharsA(const NAChar * arValue, NInt valueLength, const NAChar * szFormat, NSizeType * pValue, NBool * pResult);
#ifndef N_NO_UNICODE
NResult N_API NSizeTypeTryParseStrOrCharsW(const NWChar * arValue, NInt valueLength, const NWChar * szFormat, NSizeType * pValue, NBool * pResult);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NSizeTypeTryParseStrOrChars(const NChar * arValue, NInt valueLength, const NChar * szFormat, NSizeType * pValue, NBool * pResult);
#endif
#define NSizeTypeTryParseStrOrChars N_FUNC_AW(NSizeTypeTryParseStrOrChars)

NResult N_API NSSizeTypeTryParseStrOrCharsA(const NAChar * arValue, NInt valueLength, const NAChar * szFormat, NSSizeType * pValue, NBool * pResult);
#ifndef N_NO_UNICODE
NResult N_API NSSizeTypeTryParseStrOrCharsW(const NWChar * arValue, NInt valueLength, const NWChar * szFormat, NSSizeType * pValue, NBool * pResult);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NSSizeTypeTryParseStrOrChars(const NChar * arValue, NInt valueLength, const NChar * szFormat, NSSizeType * pValue, NBool * pResult);
#endif
#define NSSizeTypeTryParseStrOrChars N_FUNC_AW(NSSizeTypeTryParseStrOrChars)

NResult N_API NPointerTryParseStrOrCharsA(const NAChar * arValue, NInt valueLength, const NAChar * szFormat, void * * pValue, NBool * pResult);
#ifndef N_NO_UNICODE
NResult N_API NPointerTryParseStrOrCharsW(const NWChar * arValue, NInt valueLength, const NWChar * szFormat, void * * pValue, NBool * pResult);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NPointerTryParseStrOrChars(const NChar * arValue, NInt valueLength, const NChar * szFormat, void * * pValue, NBool * pResult);
#endif
#define NPointerTryParseStrOrChars N_FUNC_AW(NPointerTryParseStrOrChars)

#ifndef N_NO_FLOAT

NResult N_API NSingleTryParseStrOrCharsA(const NAChar * arValue, NInt valueLength, const NAChar * szFormat, NSingle * pValue, NBool * pResult);
#ifndef N_NO_UNICODE
NResult N_API NSingleTryParseStrOrCharsW(const NWChar * arValue, NInt valueLength, const NWChar * szFormat, NSingle * pValue, NBool * pResult);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NSingleTryParseStrOrChars(const NChar * arValue, NInt valueLength, const NChar * szFormat, NSingle * pValue, NBool * pResult);
#endif
#define NSingleTryParseStrOrChars N_FUNC_AW(NSingleTryParseStrOrChars)

NResult N_API NDoubleTryParseStrOrCharsA(const NAChar * arValue, NInt valueLength, const NAChar * szFormat, NDouble * pValue, NBool * pResult);
#ifndef N_NO_UNICODE
NResult N_API NDoubleTryParseStrOrCharsW(const NWChar * arValue, NInt valueLength, const NWChar * szFormat, NDouble * pValue, NBool * pResult);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NDoubleTryParseStrOrChars(const NChar * arValue, NInt valueLength, const NChar * szFormat, NDouble * pValue, NBool * pResult);
#endif
#define NDoubleTryParseStrOrChars N_FUNC_AW(NDoubleTryParseStrOrChars)

#endif // !N_NO_FLOAT

NResult N_API NBooleanTryParseStrOrCharsA(const NAChar * arValue, NInt valueLength, const NAChar * szFormat, NBoolean * pValue, NBool * pResult);
#ifndef N_NO_UNICODE
NResult N_API NBooleanTryParseStrOrCharsW(const NWChar * arValue, NInt valueLength, const NWChar * szFormat, NBoolean * pValue, NBool * pResult);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NBooleanTryParseStrOrChars(const NChar * arValue, NInt valueLength, const NChar * szFormat, NBoolean * pValue, NBool * pResult);
#endif
#define NBooleanTryParseStrOrChars N_FUNC_AW(NBooleanTryParseStrOrChars)

NResult N_API NACharTryParseN(HNString hValue, HNString hFormat, NAChar * pValue, NBool * pResult);
NResult N_API NACharTryParseVNA(HNString hValue, const NAChar * szFormat, NAChar * pValue, NBool * pResult);
#ifndef N_NO_UNICODE
NResult N_API NACharTryParseVNW(HNString hValue, const NWChar * szFormat, NAChar * pValue, NBool * pResult);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NACharTryParseVN(HNString hValue, const NChar * szFormat, NAChar * pValue, NBool * pResult);
#endif
#define NACharTryParseVN N_FUNC_AW(NACharTryParseVN)

#ifndef N_NO_UNICODE
NResult N_API NWCharTryParseN(HNString hValue, HNString hFormat, NWChar * pValue, NBool * pResult);
NResult N_API NWCharTryParseVNA(HNString hValue, const NAChar * szFormat, NWChar * pValue, NBool * pResult);
NResult N_API NWCharTryParseVNW(HNString hValue, const NWChar * szFormat, NWChar * pValue, NBool * pResult);
#ifdef N_DOCUMENTATION
NResult N_API NWCharTryParseVN(HNString hValue, const NChar * szFormat, NWChar * pValue, NBool * pResult);
#endif
#define NWCharTryParseVN N_FUNC_AW(NWCharTryParseVN)
#endif

#ifdef N_DOCUMENTATION
NResult N_API NCharTryParseN(HNString hValue, HNString hFormat, NChar * pValue, NBool * pResult);
NResult N_API NCharTryParseVNA(HNString hValue, const NAChar * szFormat, NChar * pValue, NBool * pResult);
NResult N_API NCharTryParseVNW(HNString hValue, const NWChar * szFormat, NChar * pValue, NBool * pResult);
NResult N_API NCharTryParseVN(HNString hValue, const NChar * szFormat, NChar * pValue, NBool * pResult);
#endif

#ifdef N_UNICODE
	#define NCharTryParseN NWCharTryParseN
	#define NCharTryParseVNA NWCharTryParseVNA
	#define NCharTryParseVNW NWCharTryParseVNW
	#define NCharTryParseVN NWCharTryParseVN
#else
	#define NCharTryParseN NACharTryParseN
	#define NCharTryParseVNA NACharTryParseVNA
	#define NCharTryParseVNW NACharTryParseVNW
	#define NCharTryParseVN NACharTryParseVN
#endif

NResult N_API NResultTryParseN(HNString hValue, HNString hFormat, NResult * pValue, NBool * pResult);
NResult N_API NResultTryParseVNA(HNString hValue, const NAChar * szFormat, NResult * pValue, NBool * pResult);
#ifndef N_NO_UNICODE
NResult N_API NResultTryParseVNW(HNString hValue, const NWChar * szFormat, NResult * pValue, NBool * pResult);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NResultTryParseVN(HNString hValue, const NChar * szFormat, NResult * pValue, NBool * pResult);
#endif
#define NResultTryParseVN N_FUNC_AW(NResultTryParseVN)

NResult N_API NUInt8TryParseN(HNString hValue, HNString hFormat, NUInt8 * pValue, NBool * pResult);
NResult N_API NUInt8TryParseVNA(HNString hValue, const NAChar * szFormat, NUInt8 * pValue, NBool * pResult);
#ifndef N_NO_UNICODE
NResult N_API NUInt8TryParseVNW(HNString hValue, const NWChar * szFormat, NUInt8 * pValue, NBool * pResult);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NUInt8TryParseVN(HNString hValue, const NChar * szFormat, NUInt8 * pValue, NBool * pResult);
#endif
#define NUInt8TryParseVN N_FUNC_AW(NUInt8TryParseVN)

NResult N_API NInt8TryParseN(HNString hValue, HNString hFormat, NInt8 * pValue, NBool * pResult);
NResult N_API NInt8TryParseVNA(HNString hValue, const NAChar * szFormat, NInt8 * pValue, NBool * pResult);
#ifndef N_NO_UNICODE
NResult N_API NInt8TryParseVNW(HNString hValue, const NWChar * szFormat, NInt8 * pValue, NBool * pResult);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NInt8TryParseVN(HNString hValue, const NChar * szFormat, NInt8 * pValue, NBool * pResult);
#endif
#define NInt8TryParseVN N_FUNC_AW(NInt8TryParseVN)

NResult N_API NUInt16TryParseN(HNString hValue, HNString hFormat, NUInt16 * pValue, NBool * pResult);
NResult N_API NUInt16TryParseVNA(HNString hValue, const NAChar * szFormat, NUInt16 * pValue, NBool * pResult);
#ifndef N_NO_UNICODE
NResult N_API NUInt16TryParseVNW(HNString hValue, const NWChar * szFormat, NUInt16 * pValue, NBool * pResult);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NUInt16TryParseVN(HNString hValue, const NChar * szFormat, NUInt16 * pValue, NBool * pResult);
#endif
#define NUInt16TryParseVN N_FUNC_AW(NUInt16TryParseVN)

NResult N_API NInt16TryParseN(HNString hValue, HNString hFormat, NInt16 * pValue, NBool * pResult);
NResult N_API NInt16TryParseVNA(HNString hValue, const NAChar * szFormat, NInt16 * pValue, NBool * pResult);
#ifndef N_NO_UNICODE
NResult N_API NInt16TryParseVNW(HNString hValue, const NWChar * szFormat, NInt16 * pValue, NBool * pResult);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NInt16TryParseVN(HNString hValue, const NChar * szFormat, NInt16 * pValue, NBool * pResult);
#endif
#define NInt16TryParseVN N_FUNC_AW(NInt16TryParseVN)

NResult N_API NUInt32TryParseN(HNString hValue, HNString hFormat, NUInt32 * pValue, NBool * pResult);
NResult N_API NUInt32TryParseVNA(HNString hValue, const NAChar * szFormat, NUInt32 * pValue, NBool * pResult);
#ifndef N_NO_UNICODE
NResult N_API NUInt32TryParseVNW(HNString hValue, const NWChar * szFormat, NUInt32 * pValue, NBool * pResult);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NUInt32TryParseVN(HNString hValue, const NChar * szFormat, NUInt32 * pValue, NBool * pResult);
#endif
#define NUInt32TryParseVN N_FUNC_AW(NUInt32TryParseVN)

NResult N_API NInt32TryParseN(HNString hValue, HNString hFormat, NInt32 * pValue, NBool * pResult);
NResult N_API NInt32TryParseVNA(HNString hValue, const NAChar * szFormat, NInt32 * pValue, NBool * pResult);
#ifndef N_NO_UNICODE
NResult N_API NInt32TryParseVNW(HNString hValue, const NWChar * szFormat, NInt32 * pValue, NBool * pResult);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NInt32TryParseVN(HNString hValue, const NChar * szFormat, NInt32 * pValue, NBool * pResult);
#endif
#define NInt32TryParseVN N_FUNC_AW(NInt32TryParseVN)

#ifndef N_NO_INT_64

NResult N_API NUInt64TryParseN(HNString hValue, HNString hFormat, NUInt64 * pValue, NBool * pResult);
NResult N_API NUInt64TryParseVNA(HNString hValue, const NAChar * szFormat, NUInt64 * pValue, NBool * pResult);
#ifndef N_NO_UNICODE
NResult N_API NUInt64TryParseVNW(HNString hValue, const NWChar * szFormat, NUInt64 * pValue, NBool * pResult);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NUInt64TryParseVN(HNString hValue, const NChar * szFormat, NUInt64 * pValue, NBool * pResult);
#endif
#define NUInt64TryParseVN N_FUNC_AW(NUInt64TryParseVN)

NResult N_API NInt64TryParseN(HNString hValue, HNString hFormat, NInt64 * pValue, NBool * pResult);
NResult N_API NInt64TryParseVNA(HNString hValue, const NAChar * szFormat, NInt64 * pValue, NBool * pResult);
#ifndef N_NO_UNICODE
NResult N_API NInt64TryParseVNW(HNString hValue, const NWChar * szFormat, NInt64 * pValue, NBool * pResult);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NInt64TryParseVN(HNString hValue, const NChar * szFormat, NInt64 * pValue, NBool * pResult);
#endif
#define NInt64TryParseVN N_FUNC_AW(NInt64TryParseVN)

#endif // !N_NO_INT_64

NResult N_API NSizeTypeTryParseN(HNString hValue, HNString hFormat, NSizeType * pValue, NBool * pResult);
NResult N_API NSizeTypeTryParseVNA(HNString hValue, const NAChar * szFormat, NSizeType * pValue, NBool * pResult);
#ifndef N_NO_UNICODE
NResult N_API NSizeTypeTryParseVNW(HNString hValue, const NWChar * szFormat, NSizeType * pValue, NBool * pResult);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NSizeTypeTryParseVN(HNString hValue, const NChar * szFormat, NSizeType * pValue, NBool * pResult);
#endif
#define NSizeTypeTryParseVN N_FUNC_AW(NSizeTypeTryParseVN)

NResult N_API NSSizeTypeTryParseN(HNString hValue, HNString hFormat, NSSizeType * pValue, NBool * pResult);
NResult N_API NSSizeTypeTryParseVNA(HNString hValue, const NAChar * szFormat, NSSizeType * pValue, NBool * pResult);
#ifndef N_NO_UNICODE
NResult N_API NSSizeTypeTryParseVNW(HNString hValue, const NWChar * szFormat, NSSizeType * pValue, NBool * pResult);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NSSizeTypeTryParseVN(HNString hValue, const NChar * szFormat, NSSizeType * pValue, NBool * pResult);
#endif
#define NSSizeTypeTryParseVN N_FUNC_AW(NSSizeTypeTryParseVN)

NResult N_API NPointerTryParseN(HNString hValue, HNString hFormat, void * * pValue, NBool * pResult);
NResult N_API NPointerTryParseVNA(HNString hValue, const NAChar * szFormat, void * * pValue, NBool * pResult);
#ifndef N_NO_UNICODE
NResult N_API NPointerTryParseVNW(HNString hValue, const NWChar * szFormat, void * * pValue, NBool * pResult);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NPointerTryParseVN(HNString hValue, const NChar * szFormat, void * * pValue, NBool * pResult);
#endif
#define NPointerTryParseVN N_FUNC_AW(NPointerTryParseVN)

#ifndef N_NO_FLOAT

NResult N_API NSingleTryParseN(HNString hValue, HNString hFormat, NSingle * pValue, NBool * pResult);
NResult N_API NSingleTryParseVNA(HNString hValue, const NAChar * szFormat, NSingle * pValue, NBool * pResult);
#ifndef N_NO_UNICODE
NResult N_API NSingleTryParseVNW(HNString hValue, const NWChar * szFormat, NSingle * pValue, NBool * pResult);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NSingleTryParseVN(HNString hValue, const NChar * szFormat, NSingle * pValue, NBool * pResult);
#endif
#define NSingleTryParseVN N_FUNC_AW(NSingleTryParseVN)

NResult N_API NDoubleTryParseN(HNString hValue, HNString hFormat, NDouble * pValue, NBool * pResult);
NResult N_API NDoubleTryParseVNA(HNString hValue, const NAChar * szFormat, NDouble * pValue, NBool * pResult);
#ifndef N_NO_UNICODE
NResult N_API NDoubleTryParseVNW(HNString hValue, const NWChar * szFormat, NDouble * pValue, NBool * pResult);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NDoubleTryParseVN(HNString hValue, const NChar * szFormat, NDouble * pValue, NBool * pResult);
#endif
#define NDoubleTryParseVN N_FUNC_AW(NDoubleTryParseVN)

#endif // !N_NO_FLOAT

NResult N_API NBooleanTryParseN(HNString hValue, HNString hFormat, NBoolean * pValue, NBool * pResult);
NResult N_API NBooleanTryParseVNA(HNString hValue, const NAChar * szFormat, NBoolean * pValue, NBool * pResult);
#ifndef N_NO_UNICODE
NResult N_API NBooleanTryParseVNW(HNString hValue, const NWChar * szFormat, NBoolean * pValue, NBool * pResult);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NBooleanTryParseVN(HNString hValue, const NChar * szFormat, NBoolean * pValue, NBool * pResult);
#endif
#define NBooleanTryParseVN N_FUNC_AW(NBooleanTryParseVN)

#define NACharTryParseA(szValue, szFormat, pValue, pResult) NACharTryParseStrOrCharsA(szValue, -1, szFormat, pValue, pResult)
#define NACharTryParseW(szValue, szFormat, pValue, pResult) NACharTryParseStrOrCharsW(szValue, -1, szFormat, pValue, pResult)
#define NACharTryParse(szValue, szFormat, pValue, pResult) NACharTryParseStrOrChars(szValue, -1, szFormat, pValue, pResult)
#define NACharTryParseCharsA(arValue, valueLength, szFormat, pValue, pResult) NACharTryParseStrOrCharsA(arValue, valueLength, szFormat, pValue, pResult)
#define NACharTryParseCharsW(arValue, valueLength, szFormat, pValue, pResult) NACharTryParseStrOrCharsW(arValue, valueLength, szFormat, pValue, pResult)
#define NACharTryParseChars(arValue, valueLength, szFormat, pValue, pResult) NACharTryParseStrOrChars(arValue, valueLength, szFormat, pValue, pResult)
#define NWCharTryParseA(szValue, szFormat, pValue, pResult) NWCharTryParseStrOrCharsA(szValue, -1, szFormat, pValue, pResult)
#define NWCharTryParseW(szValue, szFormat, pValue, pResult) NWCharTryParseStrOrCharsW(szValue, -1, szFormat, pValue, pResult)
#define NWCharTryParse(szValue, szFormat, pValue, pResult) NWCharTryParseStrOrChars(szValue, -1, szFormat, pValue, pResult)
#define NWCharTryParseCharsA(arValue, valueLength, szFormat, pValue, pResult) NWCharTryParseStrOrCharsA(arValue, valueLength, szFormat, pValue, pResult)
#define NWCharTryParseCharsW(arValue, valueLength, szFormat, pValue, pResult) NWCharTryParseStrOrCharsW(arValue, valueLength, szFormat, pValue, pResult)
#define NWCharTryParseChars(arValue, valueLength, szFormat, pValue, pResult) NWCharTryParseStrOrChars(arValue, valueLength, szFormat, pValue, pResult)
#define NCharTryParseA(szValue, szFormat, pValue, pResult) NCharTryParseStrOrCharsA(szValue, -1, szFormat, pValue, pResult)
#define NCharTryParseW(szValue, szFormat, pValue, pResult) NCharTryParseStrOrCharsW(szValue, -1, szFormat, pValue, pResult)
#define NCharTryParse(szValue, szFormat, pValue, pResult) NCharTryParseStrOrChars(szValue, -1, szFormat, pValue, pResult)
#define NCharTryParseCharsA(arValue, valueLength, szFormat, pValue, pResult) NCharTryParseStrOrCharsA(arValue, valueLength, szFormat, pValue, pResult)
#define NCharTryParseCharsW(arValue, valueLength, szFormat, pValue, pResult) NCharTryParseStrOrCharsW(arValue, valueLength, szFormat, pValue, pResult)
#define NCharTryParseChars(arValue, valueLength, szFormat, pValue, pResult) NCharTryParseStrOrChars(arValue, valueLength, szFormat, pValue, pResult)
#define NResultTryParseA(szValue, szFormat, pValue, pResult) NResultTryParseStrOrCharsA(szValue, -1, szFormat, pValue, pResult)
#define NResultTryParseW(szValue, szFormat, pValue, pResult) NResultTryParseStrOrCharsW(szValue, -1, szFormat, pValue, pResult)
#define NResultTryParse(szValue, szFormat, pValue, pResult) NResultTryParseStrOrChars(szValue, -1, szFormat, pValue, pResult)
#define NResultTryParseCharsA(arValue, valueLength, szFormat, pValue, pResult) NResultTryParseStrOrCharsA(arValue, valueLength, szFormat, pValue, pResult)
#define NResultTryParseCharsW(arValue, valueLength, szFormat, pValue, pResult) NResultTryParseStrOrCharsW(arValue, valueLength, szFormat, pValue, pResult)
#define NResultTryParseChars(arValue, valueLength, szFormat, pValue, pResult) NResultTryParseStrOrChars(arValue, valueLength, szFormat, pValue, pResult)
#define NUInt8TryParseA(szValue, szFormat, pValue, pResult) NUInt8TryParseStrOrCharsA(szValue, -1, szFormat, pValue, pResult)
#define NUInt8TryParseW(szValue, szFormat, pValue, pResult) NUInt8TryParseStrOrCharsW(szValue, -1, szFormat, pValue, pResult)
#define NUInt8TryParse(szValue, szFormat, pValue, pResult) NUInt8TryParseStrOrChars(szValue, -1, szFormat, pValue, pResult)
#define NUInt8TryParseCharsA(arValue, valueLength, szFormat, pValue, pResult) NUInt8TryParseStrOrCharsA(arValue, valueLength, szFormat, pValue, pResult)
#define NUInt8TryParseCharsW(arValue, valueLength, szFormat, pValue, pResult) NUInt8TryParseStrOrCharsW(arValue, valueLength, szFormat, pValue, pResult)
#define NUInt8TryParseChars(arValue, valueLength, szFormat, pValue, pResult) NUInt8TryParseStrOrChars(arValue, valueLength, szFormat, pValue, pResult)
#define NInt8TryParseA(szValue, szFormat, pValue, pResult) NInt8TryParseStrOrCharsA(szValue, -1, szFormat, pValue, pResult)
#define NInt8TryParseW(szValue, szFormat, pValue, pResult) NInt8TryParseStrOrCharsW(szValue, -1, szFormat, pValue, pResult)
#define NInt8TryParse(szValue, szFormat, pValue, pResult) NInt8TryParseStrOrChars(szValue, -1, szFormat, pValue, pResult)
#define NInt8TryParseCharsA(arValue, valueLength, szFormat, pValue, pResult) NInt8TryParseStrOrCharsA(arValue, valueLength, szFormat, pValue, pResult)
#define NInt8TryParseCharsW(arValue, valueLength, szFormat, pValue, pResult) NInt8TryParseStrOrCharsW(arValue, valueLength, szFormat, pValue, pResult)
#define NInt8TryParseChars(arValue, valueLength, szFormat, pValue, pResult) NInt8TryParseStrOrChars(arValue, valueLength, szFormat, pValue, pResult)
#define NUInt16TryParseA(szValue, szFormat, pValue, pResult) NUInt16TryParseStrOrCharsA(szValue, -1, szFormat, pValue, pResult)
#define NUInt16TryParseW(szValue, szFormat, pValue, pResult) NUInt16TryParseStrOrCharsW(szValue, -1, szFormat, pValue, pResult)
#define NUInt16TryParse(szValue, szFormat, pValue, pResult) NUInt16TryParseStrOrChars(szValue, -1, szFormat, pValue, pResult)
#define NUInt16TryParseCharsA(arValue, valueLength, szFormat, pValue, pResult) NUInt16TryParseStrOrCharsA(arValue, valueLength, szFormat, pValue, pResult)
#define NUInt16TryParseCharsW(arValue, valueLength, szFormat, pValue, pResult) NUInt16TryParseStrOrCharsW(arValue, valueLength, szFormat, pValue, pResult)
#define NUInt16TryParseChars(arValue, valueLength, szFormat, pValue, pResult) NUInt16TryParseStrOrChars(arValue, valueLength, szFormat, pValue, pResult)
#define NInt16TryParseA(szValue, szFormat, pValue, pResult) NInt16TryParseStrOrCharsA(szValue, -1, szFormat, pValue, pResult)
#define NInt16TryParseW(szValue, szFormat, pValue, pResult) NInt16TryParseStrOrCharsW(szValue, -1, szFormat, pValue, pResult)
#define NInt16TryParse(szValue, szFormat, pValue, pResult) NInt16TryParseStrOrChars(szValue, -1, szFormat, pValue, pResult)
#define NInt16TryParseCharsA(arValue, valueLength, szFormat, pValue, pResult) NInt16TryParseStrOrCharsA(arValue, valueLength, szFormat, pValue, pResult)
#define NInt16TryParseCharsW(arValue, valueLength, szFormat, pValue, pResult) NInt16TryParseStrOrCharsW(arValue, valueLength, szFormat, pValue, pResult)
#define NInt16TryParseChars(arValue, valueLength, szFormat, pValue, pResult) NInt16TryParseStrOrChars(arValue, valueLength, szFormat, pValue, pResult)
#define NUInt32TryParseA(szValue, szFormat, pValue, pResult) NUInt32TryParseStrOrCharsA(szValue, -1, szFormat, pValue, pResult)
#define NUInt32TryParseW(szValue, szFormat, pValue, pResult) NUInt32TryParseStrOrCharsW(szValue, -1, szFormat, pValue, pResult)
#define NUInt32TryParse(szValue, szFormat, pValue, pResult) NUInt32TryParseStrOrChars(szValue, -1, szFormat, pValue, pResult)
#define NUInt32TryParseCharsA(arValue, valueLength, szFormat, pValue, pResult) NUInt32TryParseStrOrCharsA(arValue, valueLength, szFormat, pValue, pResult)
#define NUInt32TryParseCharsW(arValue, valueLength, szFormat, pValue, pResult) NUInt32TryParseStrOrCharsW(arValue, valueLength, szFormat, pValue, pResult)
#define NUInt32TryParseChars(arValue, valueLength, szFormat, pValue, pResult) NUInt32TryParseStrOrChars(arValue, valueLength, szFormat, pValue, pResult)
#define NInt32TryParseA(szValue, szFormat, pValue, pResult) NInt32TryParseStrOrCharsA(szValue, -1, szFormat, pValue, pResult)
#define NInt32TryParseW(szValue, szFormat, pValue, pResult) NInt32TryParseStrOrCharsW(szValue, -1, szFormat, pValue, pResult)
#define NInt32TryParse(szValue, szFormat, pValue, pResult) NInt32TryParseStrOrChars(szValue, -1, szFormat, pValue, pResult)
#define NInt32TryParseCharsA(arValue, valueLength, szFormat, pValue, pResult) NInt32TryParseStrOrCharsA(arValue, valueLength, szFormat, pValue, pResult)
#define NInt32TryParseCharsW(arValue, valueLength, szFormat, pValue, pResult) NInt32TryParseStrOrCharsW(arValue, valueLength, szFormat, pValue, pResult)
#define NInt32TryParseChars(arValue, valueLength, szFormat, pValue, pResult) NInt32TryParseStrOrChars(arValue, valueLength, szFormat, pValue, pResult)
#define NUInt64TryParseA(szValue, szFormat, pValue, pResult) NUInt64TryParseStrOrCharsA(szValue, -1, szFormat, pValue, pResult)
#define NUInt64TryParseW(szValue, szFormat, pValue, pResult) NUInt64TryParseStrOrCharsW(szValue, -1, szFormat, pValue, pResult)
#define NUInt64TryParse(szValue, szFormat, pValue, pResult) NUInt64TryParseStrOrChars(szValue, -1, szFormat, pValue, pResult)
#define NUInt64TryParseCharsA(arValue, valueLength, szFormat, pValue, pResult) NUInt64TryParseStrOrCharsA(arValue, valueLength, szFormat, pValue, pResult)
#define NUInt64TryParseCharsW(arValue, valueLength, szFormat, pValue, pResult) NUInt64TryParseStrOrCharsW(arValue, valueLength, szFormat, pValue, pResult)
#define NUInt64TryParseChars(arValue, valueLength, szFormat, pValue, pResult) NUInt64TryParseStrOrChars(arValue, valueLength, szFormat, pValue, pResult)
#define NInt64TryParseA(szValue, szFormat, pValue, pResult) NInt64TryParseStrOrCharsA(szValue, -1, szFormat, pValue, pResult)
#define NInt64TryParseW(szValue, szFormat, pValue, pResult) NInt64TryParseStrOrCharsW(szValue, -1, szFormat, pValue, pResult)
#define NInt64TryParse(szValue, szFormat, pValue, pResult) NInt64TryParseStrOrChars(szValue, -1, szFormat, pValue, pResult)
#define NInt64TryParseCharsA(arValue, valueLength, szFormat, pValue, pResult) NInt64TryParseStrOrCharsA(arValue, valueLength, szFormat, pValue, pResult)
#define NInt64TryParseCharsW(arValue, valueLength, szFormat, pValue, pResult) NInt64TryParseStrOrCharsW(arValue, valueLength, szFormat, pValue, pResult)
#define NInt64TryParseChars(arValue, valueLength, szFormat, pValue, pResult) NInt64TryParseStrOrChars(arValue, valueLength, szFormat, pValue, pResult)
#define NSingleTryParseA(szValue, szFormat, pValue, pResult) NSingleTryParseStrOrCharsA(szValue, -1, szFormat, pValue, pResult)
#define NSingleTryParseW(szValue, szFormat, pValue, pResult) NSingleTryParseStrOrCharsW(szValue, -1, szFormat, pValue, pResult)
#define NSingleTryParse(szValue, szFormat, pValue, pResult) NSingleTryParseStrOrChars(szValue, -1, szFormat, pValue, pResult)
#define NSingleTryParseCharsA(arValue, valueLength, szFormat, pValue, pResult) NSingleTryParseStrOrCharsA(arValue, valueLength, szFormat, pValue, pResult)
#define NSingleTryParseCharsW(arValue, valueLength, szFormat, pValue, pResult) NSingleTryParseStrOrCharsW(arValue, valueLength, szFormat, pValue, pResult)
#define NSingleTryParseChars(arValue, valueLength, szFormat, pValue, pResult) NSingleTryParseStrOrChars(arValue, valueLength, szFormat, pValue, pResult)
#define NDoubleTryParseA(szValue, szFormat, pValue, pResult) NDoubleTryParseStrOrCharsA(szValue, -1, szFormat, pValue, pResult)
#define NDoubleTryParseW(szValue, szFormat, pValue, pResult) NDoubleTryParseStrOrCharsW(szValue, -1, szFormat, pValue, pResult)
#define NDoubleTryParse(szValue, szFormat, pValue, pResult) NDoubleTryParseStrOrChars(szValue, -1, szFormat, pValue, pResult)
#define NDoubleTryParseCharsA(arValue, valueLength, szFormat, pValue, pResult) NDoubleTryParseStrOrCharsA(arValue, valueLength, szFormat, pValue, pResult)
#define NDoubleTryParseCharsW(arValue, valueLength, szFormat, pValue, pResult) NDoubleTryParseStrOrCharsW(arValue, valueLength, szFormat, pValue, pResult)
#define NDoubleTryParseChars(arValue, valueLength, szFormat, pValue, pResult) NDoubleTryParseStrOrChars(arValue, valueLength, szFormat, pValue, pResult)
#define NBooleanTryParseA(szValue, szFormat, pValue, pResult) NBooleanTryParseStrOrCharsA(szValue, -1, szFormat, pValue, pResult)
#define NBooleanTryParseW(szValue, szFormat, pValue, pResult) NBooleanTryParseStrOrCharsW(szValue, -1, szFormat, pValue, pResult)
#define NBooleanTryParse(szValue, szFormat, pValue, pResult) NBooleanTryParseStrOrChars(szValue, -1, szFormat, pValue, pResult)
#define NBooleanTryParseCharsA(arValue, valueLength, szFormat, pValue, pResult) NBooleanTryParseStrOrCharsA(arValue, valueLength, szFormat, pValue, pResult)
#define NBooleanTryParseCharsW(arValue, valueLength, szFormat, pValue, pResult) NBooleanTryParseStrOrCharsW(arValue, valueLength, szFormat, pValue, pResult)
#define NBooleanTryParseChars(arValue, valueLength, szFormat, pValue, pResult) NBooleanTryParseStrOrChars(arValue, valueLength, szFormat, pValue, pResult)
#define NSizeTypeTryParseA(szValue, szFormat, pValue, pResult) NSizeTypeTryParseStrOrCharsA(szValue, -1, szFormat, pValue, pResult)
#define NSizeTypeTryParseW(szValue, szFormat, pValue, pResult) NSizeTypeTryParseStrOrCharsW(szValue, -1, szFormat, pValue, pResult)
#define NSizeTypeTryParse(szValue, szFormat, pValue, pResult) NSizeTypeTryParseStrOrChars(szValue, -1, szFormat, pValue, pResult)
#define NSizeTypeTryParseCharsA(arValue, valueLength, szFormat, pValue, pResult) NSizeTypeTryParseStrOrCharsA(arValue, valueLength, szFormat, pValue, pResult)
#define NSizeTypeTryParseCharsW(arValue, valueLength, szFormat, pValue, pResult) NSizeTypeTryParseStrOrCharsW(arValue, valueLength, szFormat, pValue, pResult)
#define NSizeTypeTryParseChars(arValue, valueLength, szFormat, pValue, pResult) NSizeTypeTryParseStrOrChars(arValue, valueLength, szFormat, pValue, pResult)
#define NSSizeTypeTryParseA(szValue, szFormat, pValue, pResult) NSSizeTypeTryParseStrOrCharsA(szValue, -1, szFormat, pValue, pResult)
#define NSSizeTypeTryParseW(szValue, szFormat, pValue, pResult) NSSizeTypeTryParseStrOrCharsW(szValue, -1, szFormat, pValue, pResult)
#define NSSizeTypeTryParse(szValue, szFormat, pValue, pResult) NSSizeTypeTryParseStrOrChars(szValue, -1, szFormat, pValue, pResult)
#define NSSizeTypeTryParseCharsA(arValue, valueLength, szFormat, pValue, pResult) NSSizeTypeTryParseStrOrCharsA(arValue, valueLength, szFormat, pValue, pResult)
#define NSSizeTypeTryParseCharsW(arValue, valueLength, szFormat, pValue, pResult) NSSizeTypeTryParseStrOrCharsW(arValue, valueLength, szFormat, pValue, pResult)
#define NSSizeTypeTryParseChars(arValue, valueLength, szFormat, pValue, pResult) NSSizeTypeTryParseStrOrChars(arValue, valueLength, szFormat, pValue, pResult)
#define NPointerTryParseA(szValue, szFormat, pValue, pResult) NPointerTryParseStrOrCharsA(szValue, -1, szFormat, pValue, pResult)
#define NPointerTryParseW(szValue, szFormat, pValue, pResult) NPointerTryParseStrOrCharsW(szValue, -1, szFormat, pValue, pResult)
#define NPointerTryParse(szValue, szFormat, pValue, pResult) NPointerTryParseStrOrChars(szValue, -1, szFormat, pValue, pResult)
#define NPointerTryParseCharsA(arValue, valueLength, szFormat, pValue, pResult) NPointerTryParseStrOrCharsA(arValue, valueLength, szFormat, pValue, pResult)
#define NPointerTryParseCharsW(arValue, valueLength, szFormat, pValue, pResult) NPointerTryParseStrOrCharsW(arValue, valueLength, szFormat, pValue, pResult)
#define NPointerTryParseChars(arValue, valueLength, szFormat, pValue, pResult) NPointerTryParseStrOrChars(arValue, valueLength, szFormat, pValue, pResult)

NResult N_API NACharParseStrOrCharsA(const NAChar * arValue, NInt valueLength, const NAChar * szFormat, NAChar * pValue);
#ifndef N_NO_UNICODE
NResult N_API NACharParseStrOrCharsW(const NWChar * arValue, NInt valueLength, const NWChar * szFormat, NAChar * pValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NACharParseStrOrChars(const NChar * arValue, NInt valueLength, const NChar * szFormat, NAChar * pValue);
#endif
#define NACharParseStrOrChars N_FUNC_AW(NACharParseStrOrChars)

#ifndef N_NO_UNICODE
NResult N_API NWCharParseStrOrCharsA(const NAChar * arValue, NInt valueLength, const NAChar * szFormat, NWChar * pValue);
NResult N_API NWCharParseStrOrCharsW(const NWChar * arValue, NInt valueLength, const NWChar * szFormat, NWChar * pValue);
#ifdef N_DOCUMENTATION
NResult N_API NWCharParseStrOrChars(const NChar * arValue, NInt valueLength, const NChar * szFormat, NWChar * pValue);
#endif
#define NWCharParseStrOrChars N_FUNC_AW(NWCharParseStrOrChars)
#endif

#ifdef N_DOCUMENTATION
NResult N_API NCharParseStrOrCharsA(const NAChar * arValue, NInt valueLength, const NAChar * szFormat, NChar * pValue);
NResult N_API NCharParseStrOrCharsW(const NWChar * arValue, NInt valueLength, const NWChar * szFormat, NChar * pValue);
NResult N_API NCharParseStrOrChars(const NChar * arValue, NInt valueLength, const NChar * szFormat, NChar * pValue);
#endif

#ifdef N_UNICODE
	#define NCharParseStrOrCharsA NWCharParseStrOrCharsA
	#define NCharParseStrOrCharsW NWCharParseStrOrCharsW
	#define NCharParseStrOrChars NWCharParseStrOrChars
#else
	#define NCharParseStrOrCharsA NACharParseStrOrCharsA
	#define NCharParseStrOrCharsW NACharParseStrOrCharsW
	#define NCharParseStrOrChars NACharParseStrOrChars
#endif

NResult N_API NResultParseStrOrCharsA(const NAChar * arValue, NInt valueLength, const NAChar * szFormat, NResult * pValue);
#ifndef N_NO_UNICODE
NResult N_API NResultParseStrOrCharsW(const NWChar * arValue, NInt valueLength, const NWChar * szFormat, NResult * pValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NResultParseStrOrChars(const NChar * arValue, NInt valueLength, const NChar * szFormat, NResult * pValue);
#endif
#define NResultParseStrOrChars N_FUNC_AW(NResultParseStrOrChars)

NResult N_API NUInt8ParseStrOrCharsA(const NAChar * arValue, NInt valueLength, const NAChar * szFormat, NUInt8 * pValue);
#ifndef N_NO_UNICODE
NResult N_API NUInt8ParseStrOrCharsW(const NWChar * arValue, NInt valueLength, const NWChar * szFormat, NUInt8 * pValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NUInt8ParseStrOrChars(const NChar * arValue, NInt valueLength, const NChar * szFormat, NUInt8 * pValue);
#endif
#define NUInt8ParseStrOrChars N_FUNC_AW(NUInt8ParseStrOrChars)

NResult N_API NInt8ParseStrOrCharsA(const NAChar * arValue, NInt valueLength, const NAChar * szFormat, NInt8 * pValue);
#ifndef N_NO_UNICODE
NResult N_API NInt8ParseStrOrCharsW(const NWChar * arValue, NInt valueLength, const NWChar * szFormat, NInt8 * pValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NInt8ParseStrOrChars(const NChar * arValue, NInt valueLength, const NChar * szFormat, NInt8 * pValue);
#endif
#define NInt8ParseStrOrChars N_FUNC_AW(NInt8ParseStrOrChars)

NResult N_API NUInt16ParseStrOrCharsA(const NAChar * arValue, NInt valueLength, const NAChar * szFormat, NUInt16 * pValue);
#ifndef N_NO_UNICODE
NResult N_API NUInt16ParseStrOrCharsW(const NWChar * arValue, NInt valueLength, const NWChar * szFormat, NUInt16 * pValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NUInt16ParseStrOrChars(const NChar * arValue, NInt valueLength, const NChar * szFormat, NUInt16 * pValue);
#endif
#define NUInt16ParseStrOrChars N_FUNC_AW(NUInt16ParseStrOrChars)

NResult N_API NInt16ParseStrOrCharsA(const NAChar * arValue, NInt valueLength, const NAChar * szFormat, NInt16 * pValue);
#ifndef N_NO_UNICODE
NResult N_API NInt16ParseStrOrCharsW(const NWChar * arValue, NInt valueLength, const NWChar * szFormat, NInt16 * pValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NInt16ParseStrOrChars(const NChar * arValue, NInt valueLength, const NChar * szFormat, NInt16 * pValue);
#endif
#define NInt16ParseStrOrChars N_FUNC_AW(NInt16ParseStrOrChars)

NResult N_API NUInt32ParseStrOrCharsA(const NAChar * arValue, NInt valueLength, const NAChar * szFormat, NUInt32 * pValue);
#ifndef N_NO_UNICODE
NResult N_API NUInt32ParseStrOrCharsW(const NWChar * arValue, NInt valueLength, const NWChar * szFormat, NUInt32 * pValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NUInt32ParseStrOrChars(const NChar * arValue, NInt valueLength, const NChar * szFormat, NUInt32 * pValue);
#endif
#define NUInt32ParseStrOrChars N_FUNC_AW(NUInt32ParseStrOrChars)

NResult N_API NInt32ParseStrOrCharsA(const NAChar * arValue, NInt valueLength, const NAChar * szFormat, NInt32 * pValue);
#ifndef N_NO_UNICODE
NResult N_API NInt32ParseStrOrCharsW(const NWChar * arValue, NInt valueLength, const NWChar * szFormat, NInt32 * pValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NInt32ParseStrOrChars(const NChar * arValue, NInt valueLength, const NChar * szFormat, NInt32 * pValue);
#endif
#define NInt32ParseStrOrChars N_FUNC_AW(NInt32ParseStrOrChars)

#ifndef N_NO_INT_64

NResult N_API NUInt64ParseStrOrCharsA(const NAChar * arValue, NInt valueLength, const NAChar * szFormat, NUInt64 * pValue);
#ifndef N_NO_UNICODE
NResult N_API NUInt64ParseStrOrCharsW(const NWChar * arValue, NInt valueLength, const NWChar * szFormat, NUInt64 * pValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NUInt64ParseStrOrChars(const NChar * arValue, NInt valueLength, const NChar * szFormat, NUInt64 * pValue);
#endif
#define NUInt64ParseStrOrChars N_FUNC_AW(NUInt64ParseStrOrChars)

NResult N_API NInt64ParseStrOrCharsA(const NAChar * arValue, NInt valueLength, const NAChar * szFormat, NInt64 * pValue);
#ifndef N_NO_UNICODE
NResult N_API NInt64ParseStrOrCharsW(const NWChar * arValue, NInt valueLength, const NWChar * szFormat, NInt64 * pValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NInt64ParseStrOrChars(const NChar * arValue, NInt valueLength, const NChar * szFormat, NInt64 * pValue);
#endif
#define NInt64ParseStrOrChars N_FUNC_AW(NInt64ParseStrOrChars)

#endif // !N_NO_INT_64

NResult N_API NSizeTypeParseStrOrCharsA(const NAChar * arValue, NInt valueLength, const NAChar * szFormat, NSizeType * pValue);
#ifndef N_NO_UNICODE
NResult N_API NSizeTypeParseStrOrCharsW(const NWChar * arValue, NInt valueLength, const NWChar * szFormat, NSizeType * pValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NSizeTypeParseStrOrChars(const NChar * arValue, NInt valueLength, const NChar * szFormat, NSizeType * pValue);
#endif
#define NSizeTypeParseStrOrChars N_FUNC_AW(NSizeTypeParseStrOrChars)

NResult N_API NSSizeTypeParseStrOrCharsA(const NAChar * arValue, NInt valueLength, const NAChar * szFormat, NSSizeType * pValue);
#ifndef N_NO_UNICODE
NResult N_API NSSizeTypeParseStrOrCharsW(const NWChar * arValue, NInt valueLength, const NWChar * szFormat, NSSizeType * pValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NSSizeTypeParseStrOrChars(const NChar * arValue, NInt valueLength, const NChar * szFormat, NSSizeType * pValue);
#endif
#define NSSizeTypeParseStrOrChars N_FUNC_AW(NSSizeTypeParseStrOrChars)

NResult N_API NPointerParseStrOrCharsA(const NAChar * arValue, NInt valueLength, const NAChar * szFormat, void * * pValue);
#ifndef N_NO_UNICODE
NResult N_API NPointerParseStrOrCharsW(const NWChar * arValue, NInt valueLength, const NWChar * szFormat, void * * pValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NPointerParseStrOrChars(const NChar * arValue, NInt valueLength, const NChar * szFormat, void * * pValue);
#endif
#define NPointerParseStrOrChars N_FUNC_AW(NPointerParseStrOrChars)

#ifndef N_NO_FLOAT

NResult N_API NSingleParseStrOrCharsA(const NAChar * arValue, NInt valueLength, const NAChar * szFormat, NSingle * pValue);
#ifndef N_NO_UNICODE
NResult N_API NSingleParseStrOrCharsW(const NWChar * arValue, NInt valueLength, const NWChar * szFormat, NSingle * pValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NSingleParseStrOrChars(const NChar * arValue, NInt valueLength, const NChar * szFormat, NSingle * pValue);
#endif
#define NSingleParseStrOrChars N_FUNC_AW(NSingleParseStrOrChars)

NResult N_API NDoubleParseStrOrCharsA(const NAChar * arValue, NInt valueLength, const NAChar * szFormat, NDouble * pValue);
#ifndef N_NO_UNICODE
NResult N_API NDoubleParseStrOrCharsW(const NWChar * arValue, NInt valueLength, const NWChar * szFormat, NDouble * pValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NDoubleParseStrOrChars(const NChar * arValue, NInt valueLength, const NChar * szFormat, NDouble * pValue);
#endif
#define NDoubleParseStrOrChars N_FUNC_AW(NDoubleParseStrOrChars)

#endif // !N_NO_FLOAT

NResult N_API NBooleanParseStrOrCharsA(const NAChar * arValue, NInt valueLength, const NAChar * szFormat, NBoolean * pValue);
#ifndef N_NO_UNICODE
NResult N_API NBooleanParseStrOrCharsW(const NWChar * arValue, NInt valueLength, const NWChar * szFormat, NBoolean * pValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NBooleanParseStrOrChars(const NChar * arValue, NInt valueLength, const NChar * szFormat, NBoolean * pValue);
#endif
#define NBooleanParseStrOrChars N_FUNC_AW(NBooleanParseStrOrChars)

NResult N_API NACharParseN(HNString hValue, HNString hFormat, NAChar * pValue);
NResult N_API NACharParseVNA(HNString hValue, const NAChar * szFormat, NAChar * pValue);
#ifndef N_NO_UNICODE
NResult N_API NACharParseVNW(HNString hValue, const NWChar * szFormat, NAChar * pValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NACharParseVN(HNString hValue, const NChar * szFormat, NAChar * pValue);
#endif
#define NACharParseVN N_FUNC_AW(NACharParseVN)

#ifndef N_NO_UNICODE
NResult N_API NWCharParseN(HNString hValue, HNString hFormat, NWChar * pValue);
NResult N_API NWCharParseVNA(HNString hValue, const NAChar * szFormat, NWChar * pValue);
NResult N_API NWCharParseVNW(HNString hValue, const NWChar * szFormat, NWChar * pValue);
#ifdef N_DOCUMENTATION
NResult N_API NWCharParseVN(HNString hValue, const NChar * szFormat, NWChar * pValue);
#endif
#define NWCharParseVN N_FUNC_AW(NWCharParseVN)
#endif

#ifdef N_DOCUMENTATION
NResult N_API NCharParseN(HNString hValue, HNString hFormat, NChar * pValue);
NResult N_API NCharParseVNA(HNString hValue, const NAChar * szFormat, NChar * pValue);
NResult N_API NCharParseVNW(HNString hValue, const NWChar * szFormat, NChar * pValue);
NResult N_API NCharParseVN(HNString hValue, const NChar * szFormat, NChar * pValue);
#endif

#ifdef N_UNICODE
	#define NCharParseN NWCharParseN
	#define NCharParseVNA NWCharParseVNA
	#define NCharParseVNW NWCharParseVNW
	#define NCharParseVN NWCharParseVN
#else
	#define NCharParseN NACharParseN
	#define NCharParseVNA NACharParseVNA
	#define NCharParseVNW NACharParseVNW
	#define NCharParseVN NACharParseVN
#endif

NResult N_API NResultParseN(HNString hValue, HNString hFormat, NResult * pValue);
NResult N_API NResultParseVNA(HNString hValue, const NAChar * szFormat, NResult * pValue);
#ifndef N_NO_UNICODE
NResult N_API NResultParseVNW(HNString hValue, const NWChar * szFormat, NResult * pValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NResultParseVN(HNString hValue, const NChar * szFormat, NResult * pValue);
#endif
#define NResultParseVN N_FUNC_AW(NResultParseVN)

NResult N_API NUInt8ParseN(HNString hValue, HNString hFormat, NUInt8 * pValue);
NResult N_API NUInt8ParseVNA(HNString hValue, const NAChar * szFormat, NUInt8 * pValue);
#ifndef N_NO_UNICODE
NResult N_API NUInt8ParseVNW(HNString hValue, const NWChar * szFormat, NUInt8 * pValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NUInt8ParseVN(HNString hValue, const NChar * szFormat, NUInt8 * pValue);
#endif
#define NUInt8ParseVN N_FUNC_AW(NUInt8ParseVN)

NResult N_API NInt8ParseN(HNString hValue, HNString hFormat, NInt8 * pValue);
NResult N_API NInt8ParseVNA(HNString hValue, const NAChar * szFormat, NInt8 * pValue);
#ifndef N_NO_UNICODE
NResult N_API NInt8ParseVNW(HNString hValue, const NWChar * szFormat, NInt8 * pValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NInt8ParseVN(HNString hValue, const NChar * szFormat, NInt8 * pValue);
#endif
#define NInt8ParseVN N_FUNC_AW(NInt8ParseVN)

NResult N_API NUInt16ParseN(HNString hValue, HNString hFormat, NUInt16 * pValue);
NResult N_API NUInt16ParseVNA(HNString hValue, const NAChar * szFormat, NUInt16 * pValue);
#ifndef N_NO_UNICODE
NResult N_API NUInt16ParseVNW(HNString hValue, const NWChar * szFormat, NUInt16 * pValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NUInt16ParseVN(HNString hValue, const NChar * szFormat, NUInt16 * pValue);
#endif
#define NUInt16ParseVN N_FUNC_AW(NUInt16ParseVN)

NResult N_API NInt16ParseN(HNString hValue, HNString hFormat, NInt16 * pValue);
NResult N_API NInt16ParseVNA(HNString hValue, const NAChar * szFormat, NInt16 * pValue);
#ifndef N_NO_UNICODE
NResult N_API NInt16ParseVNW(HNString hValue, const NWChar * szFormat, NInt16 * pValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NInt16ParseVN(HNString hValue, const NChar * szFormat, NInt16 * pValue);
#endif
#define NInt16ParseVN N_FUNC_AW(NInt16ParseVN)

NResult N_API NUInt32ParseN(HNString hValue, HNString hFormat, NUInt32 * pValue);
NResult N_API NUInt32ParseVNA(HNString hValue, const NAChar * szFormat, NUInt32 * pValue);
#ifndef N_NO_UNICODE
NResult N_API NUInt32ParseVNW(HNString hValue, const NWChar * szFormat, NUInt32 * pValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NUInt32ParseVN(HNString hValue, const NChar * szFormat, NUInt32 * pValue);
#endif
#define NUInt32ParseVN N_FUNC_AW(NUInt32ParseVN)

NResult N_API NInt32ParseN(HNString hValue, HNString hFormat, NInt32 * pValue);
NResult N_API NInt32ParseVNA(HNString hValue, const NAChar * szFormat, NInt32 * pValue);
#ifndef N_NO_UNICODE
NResult N_API NInt32ParseVNW(HNString hValue, const NWChar * szFormat, NInt32 * pValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NInt32ParseVN(HNString hValue, const NChar * szFormat, NInt32 * pValue);
#endif
#define NInt32ParseVN N_FUNC_AW(NInt32ParseVN)

#ifndef N_NO_INT_64

NResult N_API NUInt64ParseN(HNString hValue, HNString hFormat, NUInt64 * pValue);
NResult N_API NUInt64ParseVNA(HNString hValue, const NAChar * szFormat, NUInt64 * pValue);
#ifndef N_NO_UNICODE
NResult N_API NUInt64ParseVNW(HNString hValue, const NWChar * szFormat, NUInt64 * pValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NUInt64ParseVN(HNString hValue, const NChar * szFormat, NUInt64 * pValue);
#endif
#define NUInt64ParseVN N_FUNC_AW(NUInt64ParseVN)

NResult N_API NInt64ParseN(HNString hValue, HNString hFormat, NInt64 * pValue);
NResult N_API NInt64ParseVNA(HNString hValue, const NAChar * szFormat, NInt64 * pValue);
#ifndef N_NO_UNICODE
NResult N_API NInt64ParseVNW(HNString hValue, const NWChar * szFormat, NInt64 * pValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NInt64ParseVN(HNString hValue, const NChar * szFormat, NInt64 * pValue);
#endif
#define NInt64ParseVN N_FUNC_AW(NInt64ParseVN)

#endif // !N_NO_INT_64

NResult N_API NSizeTypeParseN(HNString hValue, HNString hFormat, NSizeType * pValue);
NResult N_API NSizeTypeParseVNA(HNString hValue, const NAChar * szFormat, NSizeType * pValue);
#ifndef N_NO_UNICODE
NResult N_API NSizeTypeParseVNW(HNString hValue, const NWChar * szFormat, NSizeType * pValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NSizeTypeParseVN(HNString hValue, const NChar * szFormat, NSizeType * pValue);
#endif
#define NSizeTypeParseVN N_FUNC_AW(NSizeTypeParseVN)

NResult N_API NSSizeTypeParseN(HNString hValue, HNString hFormat, NSSizeType * pValue);
NResult N_API NSSizeTypeParseVNA(HNString hValue, const NAChar * szFormat, NSSizeType * pValue);
#ifndef N_NO_UNICODE
NResult N_API NSSizeTypeParseVNW(HNString hValue, const NWChar * szFormat, NSSizeType * pValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NSSizeTypeParseVN(HNString hValue, const NChar * szFormat, NSSizeType * pValue);
#endif
#define NSSizeTypeParseVN N_FUNC_AW(NSSizeTypeParseVN)

NResult N_API NPointerParseN(HNString hValue, HNString hFormat, void * * pValue);
NResult N_API NPointerParseVNA(HNString hValue, const NAChar * szFormat, void * * pValue);
#ifndef N_NO_UNICODE
NResult N_API NPointerParseVNW(HNString hValue, const NWChar * szFormat, void * * pValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NPointerParseVN(HNString hValue, const NChar * szFormat, void * * pValue);
#endif
#define NPointerParseVN N_FUNC_AW(NPointerParseVN)

#ifndef N_NO_FLOAT

NResult N_API NSingleParseN(HNString hValue, HNString hFormat, NSingle * pValue);
NResult N_API NSingleParseVNA(HNString hValue, const NAChar * szFormat, NSingle * pValue);
#ifndef N_NO_UNICODE
NResult N_API NSingleParseVNW(HNString hValue, const NWChar * szFormat, NSingle * pValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NSingleParseVN(HNString hValue, const NChar * szFormat, NSingle * pValue);
#endif
#define NSingleParseVN N_FUNC_AW(NSingleParseVN)

NResult N_API NDoubleParseN(HNString hValue, HNString hFormat, NDouble * pValue);
NResult N_API NDoubleParseVNA(HNString hValue, const NAChar * szFormat, NDouble * pValue);
#ifndef N_NO_UNICODE
NResult N_API NDoubleParseVNW(HNString hValue, const NWChar * szFormat, NDouble * pValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NDoubleParseVN(HNString hValue, const NChar * szFormat, NDouble * pValue);
#endif
#define NDoubleParseVN N_FUNC_AW(NDoubleParseVN)

#endif // !N_NO_FLOAT

NResult N_API NBooleanParseN(HNString hValue, HNString hFormat, NBoolean * pValue);
NResult N_API NBooleanParseVNA(HNString hValue, const NAChar * szFormat, NBoolean * pValue);
#ifndef N_NO_UNICODE
NResult N_API NBooleanParseVNW(HNString hValue, const NWChar * szFormat, NBoolean * pValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NBooleanParseVN(HNString hValue, const NChar * szFormat, NBoolean * pValue);
#endif
#define NBooleanParseVN N_FUNC_AW(NBooleanParseVN)

#define NACharParseA(szValue, szFormat, pValue) NACharParseStrOrCharsA(szValue, -1, szFormat, pValue)
#define NACharParseW(szValue, szFormat, pValue) NACharParseStrOrCharsW(szValue, -1, szFormat, pValue)
#define NACharParse(szValue, szFormat, pValue) NACharParseStrOrChars(szValue, -1, szFormat, pValue)
#define NACharParseCharsA(arValue, valueLength, szFormat, pValue) NACharParseStrOrCharsA(arValue, valueLength, szFormat, pValue)
#define NACharParseCharsW(arValue, valueLength, szFormat, pValue) NACharParseStrOrCharsW(arValue, valueLength, szFormat, pValue)
#define NACharParseChars(arValue, valueLength, szFormat, pValue) NACharParseStrOrChars(arValue, valueLength, szFormat, pValue)
#define NWCharParseA(szValue, szFormat, pValue) NWCharParseStrOrCharsA(szValue, -1, szFormat, pValue)
#define NWCharParseW(szValue, szFormat, pValue) NWCharParseStrOrCharsW(szValue, -1, szFormat, pValue)
#define NWCharParse(szValue, szFormat, pValue) NWCharParseStrOrChars(szValue, -1, szFormat, pValue)
#define NWCharParseCharsA(arValue, valueLength, szFormat, pValue) NWCharParseStrOrCharsA(arValue, valueLength, szFormat, pValue)
#define NWCharParseCharsW(arValue, valueLength, szFormat, pValue) NWCharParseStrOrCharsW(arValue, valueLength, szFormat, pValue)
#define NWCharParseChars(arValue, valueLength, szFormat, pValue) NWCharParseStrOrChars(arValue, valueLength, szFormat, pValue)
#define NCharParseA(szValue, szFormat, pValue) NCharParseStrOrCharsA(szValue, -1, szFormat, pValue)
#define NCharParseW(szValue, szFormat, pValue) NCharParseStrOrCharsW(szValue, -1, szFormat, pValue)
#define NCharParse(szValue, szFormat, pValue) NCharParseStrOrChars(szValue, -1, szFormat, pValue)
#define NCharParseCharsA(arValue, valueLength, szFormat, pValue) NCharParseStrOrCharsA(arValue, valueLength, szFormat, pValue)
#define NCharParseCharsW(arValue, valueLength, szFormat, pValue) NCharParseStrOrCharsW(arValue, valueLength, szFormat, pValue)
#define NCharParseChars(arValue, valueLength, szFormat, pValue) NCharParseStrOrChars(arValue, valueLength, szFormat, pValue)
#define NResultParseA(szValue, szFormat, pValue) NResultParseStrOrCharsA(szValue, -1, szFormat, pValue)
#define NResultParseW(szValue, szFormat, pValue) NResultParseStrOrCharsW(szValue, -1, szFormat, pValue)
#define NResultParse(szValue, szFormat, pValue) NResultParseStrOrChars(szValue, -1, szFormat, pValue)
#define NResultParseCharsA(arValue, valueLength, szFormat, pValue) NResultParseStrOrCharsA(arValue, valueLength, szFormat, pValue)
#define NResultParseCharsW(arValue, valueLength, szFormat, pValue) NResultParseStrOrCharsW(arValue, valueLength, szFormat, pValue)
#define NResultParseChars(arValue, valueLength, szFormat, pValue) NResultParseStrOrChars(arValue, valueLength, szFormat, pValue)
#define NUInt8ParseA(szValue, szFormat, pValue) NUInt8ParseStrOrCharsA(szValue, -1, szFormat, pValue)
#define NUInt8ParseW(szValue, szFormat, pValue) NUInt8ParseStrOrCharsW(szValue, -1, szFormat, pValue)
#define NUInt8Parse(szValue, szFormat, pValue) NUInt8ParseStrOrChars(szValue, -1, szFormat, pValue)
#define NUInt8ParseCharsA(arValue, valueLength, szFormat, pValue) NUInt8ParseStrOrCharsA(arValue, valueLength, szFormat, pValue)
#define NUInt8ParseCharsW(arValue, valueLength, szFormat, pValue) NUInt8ParseStrOrCharsW(arValue, valueLength, szFormat, pValue)
#define NUInt8ParseChars(arValue, valueLength, szFormat, pValue) NUInt8ParseStrOrChars(arValue, valueLength, szFormat, pValue)
#define NInt8ParseA(szValue, szFormat, pValue) NInt8ParseStrOrCharsA(szValue, -1, szFormat, pValue)
#define NInt8ParseW(szValue, szFormat, pValue) NInt8ParseStrOrCharsW(szValue, -1, szFormat, pValue)
#define NInt8Parse(szValue, szFormat, pValue) NInt8ParseStrOrChars(szValue, -1, szFormat, pValue)
#define NInt8ParseCharsA(arValue, valueLength, szFormat, pValue) NInt8ParseStrOrCharsA(arValue, valueLength, szFormat, pValue)
#define NInt8ParseCharsW(arValue, valueLength, szFormat, pValue) NInt8ParseStrOrCharsW(arValue, valueLength, szFormat, pValue)
#define NInt8ParseChars(arValue, valueLength, szFormat, pValue) NInt8ParseStrOrChars(arValue, valueLength, szFormat, pValue)
#define NUInt16ParseA(szValue, szFormat, pValue) NUInt16ParseStrOrCharsA(szValue, -1, szFormat, pValue)
#define NUInt16ParseW(szValue, szFormat, pValue) NUInt16ParseStrOrCharsW(szValue, -1, szFormat, pValue)
#define NUInt16Parse(szValue, szFormat, pValue) NUInt16ParseStrOrChars(szValue, -1, szFormat, pValue)
#define NUInt16ParseCharsA(arValue, valueLength, szFormat, pValue) NUInt16ParseStrOrCharsA(arValue, valueLength, szFormat, pValue)
#define NUInt16ParseCharsW(arValue, valueLength, szFormat, pValue) NUInt16ParseStrOrCharsW(arValue, valueLength, szFormat, pValue)
#define NUInt16ParseChars(arValue, valueLength, szFormat, pValue) NUInt16ParseStrOrChars(arValue, valueLength, szFormat, pValue)
#define NInt16ParseA(szValue, szFormat, pValue) NInt16ParseStrOrCharsA(szValue, -1, szFormat, pValue)
#define NInt16ParseW(szValue, szFormat, pValue) NInt16ParseStrOrCharsW(szValue, -1, szFormat, pValue)
#define NInt16Parse(szValue, szFormat, pValue) NInt16ParseStrOrChars(szValue, -1, szFormat, pValue)
#define NInt16ParseCharsA(arValue, valueLength, szFormat, pValue) NInt16ParseStrOrCharsA(arValue, valueLength, szFormat, pValue)
#define NInt16ParseCharsW(arValue, valueLength, szFormat, pValue) NInt16ParseStrOrCharsW(arValue, valueLength, szFormat, pValue)
#define NInt16ParseChars(arValue, valueLength, szFormat, pValue) NInt16ParseStrOrChars(arValue, valueLength, szFormat, pValue)
#define NUInt32ParseA(szValue, szFormat, pValue) NUInt32ParseStrOrCharsA(szValue, -1, szFormat, pValue)
#define NUInt32ParseW(szValue, szFormat, pValue) NUInt32ParseStrOrCharsW(szValue, -1, szFormat, pValue)
#define NUInt32Parse(szValue, szFormat, pValue) NUInt32ParseStrOrChars(szValue, -1, szFormat, pValue)
#define NUInt32ParseCharsA(arValue, valueLength, szFormat, pValue) NUInt32ParseStrOrCharsA(arValue, valueLength, szFormat, pValue)
#define NUInt32ParseCharsW(arValue, valueLength, szFormat, pValue) NUInt32ParseStrOrCharsW(arValue, valueLength, szFormat, pValue)
#define NUInt32ParseChars(arValue, valueLength, szFormat, pValue) NUInt32ParseStrOrChars(arValue, valueLength, szFormat, pValue)
#define NInt32ParseA(szValue, szFormat, pValue) NInt32ParseStrOrCharsA(szValue, -1, szFormat, pValue)
#define NInt32ParseW(szValue, szFormat, pValue) NInt32ParseStrOrCharsW(szValue, -1, szFormat, pValue)
#define NInt32Parse(szValue, szFormat, pValue) NInt32ParseStrOrChars(szValue, -1, szFormat, pValue)
#define NInt32ParseCharsA(arValue, valueLength, szFormat, pValue) NInt32ParseStrOrCharsA(arValue, valueLength, szFormat, pValue)
#define NInt32ParseCharsW(arValue, valueLength, szFormat, pValue) NInt32ParseStrOrCharsW(arValue, valueLength, szFormat, pValue)
#define NInt32ParseChars(arValue, valueLength, szFormat, pValue) NInt32ParseStrOrChars(arValue, valueLength, szFormat, pValue)
#define NUInt64ParseA(szValue, szFormat, pValue) NUInt64ParseStrOrCharsA(szValue, -1, szFormat, pValue)
#define NUInt64ParseW(szValue, szFormat, pValue) NUInt64ParseStrOrCharsW(szValue, -1, szFormat, pValue)
#define NUInt64Parse(szValue, szFormat, pValue) NUInt64ParseStrOrChars(szValue, -1, szFormat, pValue)
#define NUInt64ParseCharsA(arValue, valueLength, szFormat, pValue) NUInt64ParseStrOrCharsA(arValue, valueLength, szFormat, pValue)
#define NUInt64ParseCharsW(arValue, valueLength, szFormat, pValue) NUInt64ParseStrOrCharsW(arValue, valueLength, szFormat, pValue)
#define NUInt64ParseChars(arValue, valueLength, szFormat, pValue) NUInt64ParseStrOrChars(arValue, valueLength, szFormat, pValue)
#define NInt64ParseA(szValue, szFormat, pValue) NInt64ParseStrOrCharsA(szValue, -1, szFormat, pValue)
#define NInt64ParseW(szValue, szFormat, pValue) NInt64ParseStrOrCharsW(szValue, -1, szFormat, pValue)
#define NInt64Parse(szValue, szFormat, pValue) NInt64ParseStrOrChars(szValue, -1, szFormat, pValue)
#define NInt64ParseCharsA(arValue, valueLength, szFormat, pValue) NInt64ParseStrOrCharsA(arValue, valueLength, szFormat, pValue)
#define NInt64ParseCharsW(arValue, valueLength, szFormat, pValue) NInt64ParseStrOrCharsW(arValue, valueLength, szFormat, pValue)
#define NInt64ParseChars(arValue, valueLength, szFormat, pValue) NInt64ParseStrOrChars(arValue, valueLength, szFormat, pValue)
#define NSingleParseA(szValue, szFormat, pValue) NSingleParseStrOrCharsA(szValue, -1, szFormat, pValue)
#define NSingleParseW(szValue, szFormat, pValue) NSingleParseStrOrCharsW(szValue, -1, szFormat, pValue)
#define NSingleParse(szValue, szFormat, pValue) NSingleParseStrOrChars(szValue, -1, szFormat, pValue)
#define NSingleParseCharsA(arValue, valueLength, szFormat, pValue) NSingleParseStrOrCharsA(arValue, valueLength, szFormat, pValue)
#define NSingleParseCharsW(arValue, valueLength, szFormat, pValue) NSingleParseStrOrCharsW(arValue, valueLength, szFormat, pValue)
#define NSingleParseChars(arValue, valueLength, szFormat, pValue) NSingleParseStrOrChars(arValue, valueLength, szFormat, pValue)
#define NDoubleParseA(szValue, szFormat, pValue) NDoubleParseStrOrCharsA(szValue, -1, szFormat, pValue)
#define NDoubleParseW(szValue, szFormat, pValue) NDoubleParseStrOrCharsW(szValue, -1, szFormat, pValue)
#define NDoubleParse(szValue, szFormat, pValue) NDoubleParseStrOrChars(szValue, -1, szFormat, pValue)
#define NDoubleParseCharsA(arValue, valueLength, szFormat, pValue) NDoubleParseStrOrCharsA(arValue, valueLength, szFormat, pValue)
#define NDoubleParseCharsW(arValue, valueLength, szFormat, pValue) NDoubleParseStrOrCharsW(arValue, valueLength, szFormat, pValue)
#define NDoubleParseChars(arValue, valueLength, szFormat, pValue) NDoubleParseStrOrChars(arValue, valueLength, szFormat, pValue)
#define NBooleanParseA(szValue, szFormat, pValue) NBooleanParseStrOrCharsA(szValue, -1, szFormat, pValue)
#define NBooleanParseW(szValue, szFormat, pValue) NBooleanParseStrOrCharsW(szValue, -1, szFormat, pValue)
#define NBooleanParse(szValue, szFormat, pValue) NBooleanParseStrOrChars(szValue, -1, szFormat, pValue)
#define NBooleanParseCharsA(arValue, szFormat, szFalseString, pValue) NBooleanParseStrOrCharsA(arValue, valueLength, szFormat, pValue)
#define NBooleanParseCharsW(arValue, szFormat, szFalseString, pValue) NBooleanParseStrOrCharsW(arValue, valueLength, szFormat, pValue)
#define NBooleanParseChars(arValue, szFormat, szFalseString, pValue) NBooleanParseStrOrChars(arValue, valueLength, szFormat, pValue)
#define NSizeTypeParseA(szValue, szFormat, pValue) NSizeTypeParseStrOrCharsA(szValue, -1, szFormat, pValue)
#define NSizeTypeParseW(szValue, szFormat, pValue) NSizeTypeParseStrOrCharsW(szValue, -1, szFormat, pValue)
#define NSizeTypeParse(szValue, szFormat, pValue) NSizeTypeParseStrOrChars(szValue, -1, szFormat, pValue)
#define NSizeTypeParseCharsA(arValue, valueLength, szFormat, pValue) NSizeTypeParseStrOrCharsA(arValue, valueLength, szFormat, pValue)
#define NSizeTypeParseCharsW(arValue, valueLength, szFormat, pValue) NSizeTypeParseStrOrCharsW(arValue, valueLength, szFormat, pValue)
#define NSizeTypeParseChars(arValue, valueLength, szFormat, pValue) NSizeTypeParseStrOrChars(arValue, valueLength, szFormat, pValue)
#define NSSizeTypeParseA(szValue, szFormat, pValue) NSSizeTypeParseStrOrCharsA(szValue, -1, szFormat, pValue)
#define NSSizeTypeParseW(szValue, szFormat, pValue) NSSizeTypeParseStrOrCharsW(szValue, -1, szFormat, pValue)
#define NSSizeTypeParse(szValue, szFormat, pValue) NSSizeTypeParseStrOrChars(szValue, -1, szFormat, pValue)
#define NSSizeTypeParseCharsA(arValue, valueLength, szFormat, pValue) NSSizeTypeParseStrOrCharsA(arValue, valueLength, szFormat, pValue)
#define NSSizeTypeParseCharsW(arValue, valueLength, szFormat, pValue) NSSizeTypeParseStrOrCharsW(arValue, valueLength, szFormat, pValue)
#define NSSizeTypeParseChars(arValue, valueLength, szFormat, pValue) NSSizeTypeParseStrOrChars(arValue, valueLength, szFormat, pValue)
#define NPointerParseA(szValue, szFormat, pValue) NPointerParseStrOrCharsA(szValue, -1, szFormat, pValue)
#define NPointerParseW(szValue, szFormat, pValue) NPointerParseStrOrCharsW(szValue, -1, szFormat, pValue)
#define NPointerParse(szValue, szFormat, pValue) NPointerParseStrOrChars(szValue, -1, szFormat, pValue)
#define NPointerParseCharsA(arValue, szFormat, szFalseString, pValue) NPointerParseStrOrCharsA(arValue, valueLength, szFormat, pValue)
#define NPointerParseCharsW(arValue, szFormat, szFalseString, pValue) NPointerParseStrOrCharsW(arValue, valueLength, szFormat, pValue)
#define NPointerParseChars(arValue, szFormat, szFalseString, pValue) NPointerParseStrOrChars(arValue, valueLength, szFormat, pValue)

NResult N_API NGuidToStringN(const struct NGuid_ * pValue, HNString hFormat, HNString * phValue);
NResult N_API NGuidToStringA(const struct NGuid_ * pValue, const NAChar * szFormat, HNString * phValue);
#ifndef N_NO_UNICODE
NResult N_API NGuidToStringW(const struct NGuid_ * pValue, const NWChar * szFormat, HNString * phValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NGuidToString(const NGuid * pValue, const NChar * szFormat, HNString * phValue);
#endif
#define NGuidToString N_FUNC_AW(NGuidToString)

NResult N_API NGuidTryParseN(HNString hValue, HNString hFormat, struct NGuid_ * pValue, NBool * pResult);
NResult N_API NGuidTryParseVNA(HNString hValue, const NAChar * szFormat, struct NGuid_ * pValue, NBool * pResult);
#ifndef N_NO_UNICODE
NResult N_API NGuidTryParseVNW(HNString hValue, const NWChar * szFormat, struct NGuid_ * pValue, NBool * pResult);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NGuidTryParseVN(HNString hValue, const NChar * szFormat, NGuid * pValue, NBool * pResult);
#endif
#define NGuidTryParseVN N_FUNC_AW(NGuidTryParseVN)

NResult N_API NGuidTryParseA(const NAChar * szValue, const NAChar * szFormat, struct NGuid_ * pValue, NBool * pResult);
#ifndef N_NO_UNICODE
NResult N_API NGuidTryParseW(const NWChar * szValue, const NWChar * szFormat, struct NGuid_ * pValue, NBool * pResult);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NGuidTryParse(const NChar * szValue, const NChar * szFormat, NGuid * pValue, NBool * pResult);
#endif
#define NGuidTryParse N_FUNC_AW(NGuidTryParse)

NResult N_API NGuidParseN(HNString hValue, HNString hFormat, struct NGuid_ * pValue);

NResult N_API NGuidParseVNA(HNString hValue, const NAChar * szFormat, struct NGuid_ * pValue);
#ifndef N_NO_UNICODE
NResult N_API NGuidParseVNW(HNString hValue, const NWChar * szFormat, struct NGuid_ * pValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NGuidParseVN(HNString hValue, const NChar * szFormat, NGuid * pValue);
#endif
#define NGuidParseVN N_FUNC_AW(NGuidParseVN)

NResult N_API NGuidParseA(const NAChar * szValue, const NAChar * szFormat, struct NGuid_ * pValue);
#ifndef N_NO_UNICODE
NResult N_API NGuidParseW(const NWChar * szValue, const NWChar * szFormat, struct NGuid_ * pValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NGuidParse(const NChar * szValue, const NChar * szFormat, NGuid * pValue);
#endif
#define NGuidParse N_FUNC_AW(NGuidParse)

NResult N_API NGuidToByteArray(const struct NGuid_ * pValue, NByte * pDstArray, NInt dstLength);

NResult N_API NURationalToStringN(const struct NURational_ * pValue, HNString hFormat, HNString * phValue);
NResult N_API NURationalToStringA(const struct NURational_ * pValue, const NAChar * szFormat, HNString * phValue);
#ifndef N_NO_UNICODE
NResult N_API NURationalToStringW(const struct NURational_ * pValue, const NWChar * szFormat, HNString * phValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NURationalToString(const NURational * pValue, const NChar * szFormat, HNString * phValue);
#endif
#define NURationalToString N_FUNC_AW(NURationalToString)

NResult N_API NRationalToStringN(const struct NRational_ * pValue, HNString hFormat, HNString * phValue);
NResult N_API NRationalToStringA(const struct NRational_ * pValue, const NAChar * szFormat, HNString * phValue);
#ifndef N_NO_UNICODE
NResult N_API NRationalToStringW(const struct NRational_ * pValue, const NWChar * szFormat, HNString * phValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NRationalToString(const NRational * pValue, const NChar * szFormat, HNString * phValue);
#endif
#define NRationalToString N_FUNC_AW(NRationalToString)

NResult N_API NComplexToStringN(const struct NComplex_ * pValue, HNString hFormat, HNString * phValue);
NResult N_API NComplexToStringA(const struct NComplex_ * pValue, const NAChar * szFormat, HNString * phValue);
#ifndef N_NO_UNICODE
NResult N_API NComplexToStringW(const struct NComplex_ * pValue, const NWChar * szFormat, HNString * phValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NComplexToString(const NComplex * pValue, const NChar * szFormat, HNString * phValue);
#endif
#define NComplexToString N_FUNC_AW(NComplexToString)

NResult N_API NIndexPairToStringN(const struct NIndexPair_ * pValue, HNString hFormat, HNString * phValue);
NResult N_API NIndexPairToStringA(const struct NIndexPair_ * pValue, const NAChar * szFormat, HNString * phValue);
#ifndef N_NO_UNICODE
NResult N_API NIndexPairToStringW(const struct NIndexPair_ * pValue, const NWChar * szFormat, HNString * phValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NIndexPairToString(const NIndexPair * pValue, const NChar * szFormat, HNString * phValue);
#endif
#define NIndexPairToString N_FUNC_AW(NIndexPairToString)

NResult N_API NRangeToStringN(const struct NRange_ * pValue, HNString hFormat, HNString * phValue);
NResult N_API NRangeToStringA(const struct NRange_ * pValue, const NAChar * szFormat, HNString * phValue);
#ifndef N_NO_UNICODE
NResult N_API NRangeToStringW(const struct NRange_ * pValue, const NWChar * szFormat, HNString * phValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NRangeToString(const NRange * pValue, const NChar * szFormat, HNString * phValue);
#endif
#define NRangeToString N_FUNC_AW(NRangeToString)

#define NVersionMake(major, minor) ((NVersion_)(((NByte)(minor)) | ((major) << 8)))
#define NVersionGetMajor(value) ((NByte)((value) >> 8))
#define NVersionGetMinor(value) ((NByte)((value) & 0xFF))

NResult N_API NVersionToStringN(NVersion_ value, HNString hFormat, HNString * phValue);
NResult N_API NVersionToStringA(NVersion_ value, const NAChar * szFormat, HNString * phValue);
#ifndef N_NO_UNICODE
NResult N_API NVersionToStringW(NVersion_ value, const NWChar * szFormat, HNString * phValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NVersionToString(NVersion value, const NChar * szFormat, HNString * phValue);
#endif
#define NVersionToString N_FUNC_AW(NVersionToString)

#define NVersionRangeMake(from, to) ((NUInt)(((NUShort)(to)) | ((from) << 16)))
#define NVersionRangeGetFrom(value) ((NVersion_)((value) >> 16))
#define NVersionRangeGetTo(value) ((NVersion_)((value) & 0xFFFF))
NBool N_API NVersionRangeContains(NVersionRange_ value, NVersion_ version);
NBool N_API NVersionRangeContainsRange(NVersionRange_ value, NVersionRange_ versionRange);
NBool N_API NVersionRangeIntersectsWith(NVersionRange_ value, NVersionRange_ otherValue);
NVersionRange_ N_API NVersionRangeIntersect(NVersionRange_ value1, NVersionRange_ value2);

NResult N_API NVersionRangeToStringN(NVersionRange_ value, HNString hFormat, HNString * phValue);
NResult N_API NVersionRangeToStringA(NVersionRange_ value, const NAChar * szFormat, HNString * phValue);
#ifndef N_NO_UNICODE
NResult N_API NVersionRangeToStringW(NVersionRange_ value, const NWChar * szFormat, HNString * phValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NVersionRangeToString(NVersionRange value, const NChar * szFormat, HNString * phValue);
#endif
#define NVersionRangeToString N_FUNC_AW(NVersionRangeToString)

N_DECLARE_STATIC_OBJECT_TYPE(NTypes)

typedef NResult (N_CALLBACK NTypeOfProc)(HNType * phValue);

typedef enum NAttributes_
{
	naNone = 0,
	naSignNeutral = 0x00000001,
	naSingleValue = 0x00000002,
	naArray = 0x00000004,
	naNullable = 0x00000008,
	naLocal = 0x00000010,
	naGlobal = 0x00000020,
	naSet = 0x00000040,
	naCache = 0x00000080,
	naDeprecated = 0x00000100,
	naAbstract = 0x00001000,
	naStatic = 0x00002000,
	naPublic = 0x00004000,
	naSealed = 0x00008000,
	naMinValue = 0x00100000,
	naMaxValue = 0x00200000,
	naStdValues = 0x00400000,
	naStdValuesExclusive = 0x00800000,
	naNoRead = 0x01000000,
	naNoWrite = 0x02000000,
	naByRef = 0x04000000,
	naRetValue = 0x08000000,
	naDefaultValue = 0x10000000,
	naOptional = 0x20000000,
	naPromoteValue = 0x80000000
} NAttributes;

N_DECLARE_TYPE(NAttributes)

typedef enum NOSFamily_
{
	nosfNone = 0,
	nosfWindows = 1,
	nosfWindowsCE = 2,
	nosfWindowsPhone = 4,
	nosfMacOSX = 8,
	nosfIOS = 16,
	nosfLinux = 32,
	nosfEmbeddedLinux = 64,
	nosfAndroid = 128,
	nosfUnix = 256
} NOSFamily;

N_DECLARE_TYPE(NOSFamily)

NOSFamily N_API NOSFamilyGetCurrent(void);

N_DECLARE_TYPE(NNameStringPair)

struct NNameStringPair_
{
	HNString hKey;
	HNString hValue;
};
#ifndef N_TYPES_HPP_INCLUDED
typedef struct NNameStringPair_ NNameStringPair;
#endif

NResult N_API NNameStringPairCreateN(HNString hKey, HNString hValue, struct NNameStringPair_ * pValue);
#ifndef N_NO_ANSI_FUNC
NResult N_API NNameStringPairCreateA(const NAChar * szKey, const NAChar * szValue, struct NNameStringPair_ * pValue);
#endif
#ifndef N_NO_UNICODE
NResult N_API NNameStringPairCreateW(const NWChar * szKey, const NWChar * szValue, struct NNameStringPair_ * pValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NNameStringPairCreate(const NChar * szKey, const NChar * szValue, NNameStringPair * pValue);
#endif
#define NNameStringPairCreate N_FUNC_AW(NNameStringPairCreate)

NResult N_API NNameStringPairDispose(struct NNameStringPair_ * pValue);
NResult N_API NNameStringPairCopy(const struct NNameStringPair_ * pSrcValue, struct NNameStringPair_ * pDstValue);
NResult N_API NNameStringPairSet(const struct NNameStringPair_ * pSrcValue, struct NNameStringPair_ * pDstValue);

#ifdef N_CPP
}
#endif

#endif // !N_TYPES_H_INCLUDED
