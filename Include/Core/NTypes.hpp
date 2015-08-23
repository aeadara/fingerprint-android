#ifndef N_TYPES_HPP_INCLUDED
#define N_TYPES_HPP_INCLUDED

#include <stdarg.h>
#include <iterator>

#include <iostream>

namespace Neurotec
{
#include <Core/NTypes.h>
}

#ifndef N_CPP
	#error Only C++ is supported.
#endif

#ifndef N_FRAMEWORK_NO_AUTO_DETECT
	// Try auto-detect the framework
	#if defined(_MFC_VER)
		#define N_FRAMEWORK_MFC
	#elif defined(wxMAJOR_VERSION)
		#define N_FRAMEWORK_WX
	#elif defined(QT_VERSION) || defined(QT_CORE_LIB)
		#define N_FRAMEWORK_QT
	#else
	#endif
#endif

#if !defined(N_NO_CPP11) && (_MSC_VER >= 1700 || __cplusplus >= 201103L)
	#define N_CPP11
#endif

#if defined(N_MAC)
	#include <AvailabilityMacros.h>
#endif

#include <Core/NNoDeprecate.h>
#if defined(N_CPP11) || (defined(N_MAC) && defined(MAC_OS_X_VERSION_10_9) && \
	MAC_OS_X_VERSION_MIN_REQUIRED >= MAC_OS_X_VERSION_10_9)
	#include <unordered_map>
	#include <unordered_set>
	#define N_HASH_MAP ::std::unordered_map
	#define N_HASH_SET ::std::unordered_set
	#define N_HASH_NAMESPACE_BEGIN namespace std {
	#define N_HASH_NAMESPACE_END }
#elif defined(N_MSVC)
	#if _MSC_VER >= 1600
		#include <unordered_map>
		#include <unordered_set>
		#define N_HASH_MAP ::std::unordered_map
		#define N_HASH_SET ::std::unordered_set
		#define N_HASH_NAMESPACE_BEGIN namespace std {
		#define N_HASH_NAMESPACE_END }
	#elif _MSC_VER >= 1500
		#include <unordered_map>
		#include <unordered_set>
		#define N_HASH_MAP ::std::tr1::unordered_map
		#define N_HASH_SET ::std::tr1::unordered_set
		#define N_HASH_NAMESPACE_BEGIN namespace std { namespace tr1 {
		#define N_HASH_NAMESPACE_END } }
	#else
		#include <hash_map>
		#include <hash_set>
		#define N_HASH_MAP ::stdext::hash_map
		#define N_HASH_SET ::stdext::hash_set
		#define N_HASH_NAMESPACE_BEGIN namespace stdext {
		#define N_HASH_NAMESPACE_END }
	#endif
#elif defined(N_GCC)
	#if N_GCC_VERSION >= 40000
		#include <tr1/unordered_map>
		#include <tr1/unordered_set>
		#define N_HASH_MAP ::std::tr1::unordered_map
		#define N_HASH_SET ::std::tr1::unordered_set
		#define N_NEED_HASH
		#define N_HASH_NAMESPACE_BEGIN namespace std { namespace tr1 {
		#define N_HASH_NAMESPACE_END } }
	#else
		#include <ext/hash_map>
		#include <ext/hash_set>
		#define N_HASH_MAP ::__gnu_cxx::hash_map
		#define N_HASH_SET ::__gnu_cxx::hash_set
		#define N_NEED_HASH
		#define N_HASH_NAMESPACE_BEGIN namespace __gnu_cxx {
		#define N_HASH_NAMESPACE_END }
		N_HASH_NAMESPACE_BEGIN
			template<typename T> struct hash<const T *>
			{
				size_t operator()(const T * const & k) const
				{
					return (size_t)k;
				}
			};
			template<typename T> struct hash<T *>
			{
				size_t operator()(T * const & k) const
				{
					return (size_t)k;
				}
			};
		N_HASH_NAMESPACE_END
	#endif
#else
	#include <hash_map>
	#include <hash_set>
	#define N_HASH_MAP ::std::hash_map
	#define N_HASH_SET ::std::hash_set
#endif
#include <Core/NReDeprecate.h>

#ifdef N_MSVC
	#define N_THROW(args) throw(...)
	#define N_THROW_NONE throw()
	#define N_THROW_ANY throw(...)
#else
	#define N_THROW(args) throw args
	#define N_THROW_NONE throw()
	#define N_THROW_ANY throw(...)
#endif

namespace Neurotec
{
#undef N_UINT8_MIN
#undef N_UINT8_MAX
#undef N_INT8_MIN
#undef N_INT8_MAX
#undef N_UINT16_MIN
#undef N_UINT16_MAX
#undef N_INT16_MIN
#undef N_INT16_MAX
#undef N_UINT32_MIN
#undef N_UINT32_MAX
#undef N_INT32_MIN
#undef N_INT32_MAX
#ifndef N_NO_INT_64
	#undef N_UINT64_MIN
	#undef N_UINT64_MAX
	#undef N_INT64_MIN
	#undef N_INT64_MAX
#endif
#undef N_BYTE_MIN
#undef N_BYTE_MAX
#undef N_SBYTE_MIN
#undef N_SBYTE_MAX
#undef N_USHORT_MIN
#undef N_USHORT_MAX
#undef N_SHORT_MIN
#undef N_SHORT_MAX
#undef N_UINT_MIN
#undef N_UINT_MAX
#undef N_INT_MIN
#undef N_INT_MAX
#ifndef N_NO_INT_64
	#undef N_ULONG_MIN
	#undef N_ULONG_MAX
	#undef N_LONG_MIN
	#undef N_LONG_MAX
#endif
#ifndef N_NO_FLOAT
	#undef N_SINGLE_MIN
	#undef N_SINGLE_MAX
	#undef N_SINGLE_EPSILON
	#undef N_DOUBLE_MIN
	#undef N_DOUBLE_MAX
	#undef N_DOUBLE_EPSILON
	#undef N_FLOAT_MIN
	#undef N_FLOAT_MAX
	#undef N_FLOAT_EPSILON
#endif
#undef NTrue
#undef NFalse
#ifndef N_NO_UNICODE
	#undef N_WCHAR_SIZE
#endif
#undef N_SIZE_TYPE_MIN
#undef N_SIZE_TYPE_MAX
#undef N_SSIZE_TYPE_MIN
#undef N_SSIZE_TYPE_MAX

#undef NMakeByte
#undef NHiNibble
#undef NLoNibble
#undef NSwapNibbles
#undef NMakeWord
#undef NHiByte
#undef NLoByte
#undef NMakeDWord
#undef NHiWord
#undef NLoWord
#ifndef N_NO_INT_64
#undef NMakeQWord
#undef NHiDWord
#undef NLoDWord
#endif
#undef NSwapWord
#undef NSwapDWord
#ifndef N_NO_INT_64
#undef NSwapQWord
#endif
#undef NHostToNetworkWord
#undef NHostToNetworkDWord
#undef NNetworkToHostWord
#undef NNetworkToHostDWord

#undef NIsFlagSet
#undef NSetFlag
#undef NResetFlag
#undef NSetFlagValue
#undef NSetFlagIf
#undef NResetFlagIf
#undef NIsMoreThanOneFlagSet

#undef NMax
#undef NMin
#undef NRound
#undef NRoundP
#undef NRoundF
#undef NRoundFP
#undef NSqr

#undef N_SWAP

#ifdef N_MSVC
	const NUInt8 N_UINT8_MIN = 0x00ui8;
	const NUInt8 N_UINT8_MAX = 0xFFui8;
	const NInt8 N_INT8_MIN = 0x80i8;
	const NInt8 N_INT8_MAX = 0x7Fi8;
	const NUInt16 N_UINT16_MIN = 0x0000ui16;
	const NUInt16 N_UINT16_MAX = 0xFFFFui16;
	const NInt16 N_INT16_MIN = 0x8000i16;
	const NInt16 N_INT16_MAX = 0x7FFFi16;
	const NUInt32 N_UINT32_MIN = 0x00000000ui32;
	const NUInt32 N_UINT32_MAX = 0xFFFFFFFFui32;
	const NInt32 N_INT32_MIN = 0x80000000i32;
	const NInt32 N_INT32_MAX = 0x7FFFFFFFi32;
#else
	const NUInt8 N_UINT8_MIN = ((NUInt8)0x00u);
	const NUInt8 N_UINT8_MAX = ((NUInt8)0xFFu);
	const NInt8 N_INT8_MIN = ((NInt8)0x80);
	const NInt8 N_INT8_MAX = ((NInt8)0x7F);
	const NUInt16 N_UINT16_MIN = ((NUInt16)0x0000u);
	const NUInt16 N_UINT16_MAX = ((NUInt16)0xFFFFu);
	const NInt16 N_INT16_MIN = ((NInt16)0x8000);
	const NInt16 N_INT16_MAX = ((NInt16)0x7FFF);
	const NUInt32 N_UINT32_MIN = 0x00000000u;
	const NUInt32 N_UINT32_MAX = 0xFFFFFFFFu;
	const NInt32 N_INT32_MIN = 0x80000000;
	const NInt32 N_INT32_MAX = 0x7FFFFFFF;
#endif

#ifndef N_NO_INT_64
	#ifdef N_MSVC
		const NUInt64 N_UINT64_MIN = 0x0000000000000000ui64;
		const NUInt64 N_UINT64_MAX = 0xFFFFFFFFFFFFFFFFui64;
		const NInt64 N_INT64_MIN = 0x8000000000000000i64;
		const NInt64 N_INT64_MAX = 0x7FFFFFFFFFFFFFFFi64;
	#else
		const NUInt64 N_UINT64_MIN = 0x0000000000000000ull;
		const NUInt64 N_UINT64_MAX = 0xFFFFFFFFFFFFFFFFull;
		const NInt64 N_INT64_MIN = 0x8000000000000000ll;
		const NInt64 N_INT64_MAX = 0x7FFFFFFFFFFFFFFFll;
	#endif
#endif

const NByte N_BYTE_MIN = N_UINT8_MIN;
const NByte N_BYTE_MAX = N_UINT8_MAX;
const NSByte N_SBYTE_MIN = N_INT8_MIN;
const NSByte N_SBYTE_MAX = N_INT8_MAX;
const NUShort N_USHORT_MIN = N_UINT16_MIN;
const NUShort N_USHORT_MAX = N_UINT16_MAX;
const NShort N_SHORT_MIN = N_INT16_MIN;
const NShort N_SHORT_MAX = N_INT16_MAX;
const NUInt N_UINT_MIN = N_UINT32_MIN;
const NUInt N_UINT_MAX = N_UINT32_MAX;
const NInt N_INT_MIN = N_INT32_MIN;
const NInt N_INT_MAX = N_INT32_MAX;

#ifndef N_NO_INT_64
	const NULong N_ULONG_MIN = N_UINT64_MIN;
	const NULong N_ULONG_MAX = N_UINT64_MAX;
	const NLong N_LONG_MIN = N_INT64_MIN;
	const NLong N_LONG_MAX = N_INT64_MAX;
#endif

#ifndef N_NO_FLOAT
	const NSingle N_SINGLE_MIN = -3.402823466e+38F;
	const NSingle N_SINGLE_MAX = 3.402823466e+38F;
	const NSingle N_SINGLE_EPSILON = 1.192092896e-07F;
	const NDouble N_DOUBLE_MIN = -1.7976931348623158e+308;
	const NDouble N_DOUBLE_MAX = 1.7976931348623158e+308;
	const NDouble N_DOUBLE_EPSILON = 2.2204460492503131e-016;

	const NFloat N_FLOAT_MIN = N_SINGLE_MIN;
	const NFloat N_FLOAT_MAX = N_SINGLE_MAX;
	const NFloat N_FLOAT_EPSILON = N_SINGLE_EPSILON;
#endif

const NBool NTrue = 1;
const NBool NFalse = 0;

#ifndef N_NO_UNICODE
	#if defined(N_WINDOWS) || (defined(__SIZEOF_WCHAR_T__) && __SIZEOF_WCHAR_T__ == 2)
		#define N_WCHAR_SIZE 2
	#else // !defined(N_WINDOWS) && (!defined(__SIZEOF_WCHAR_T__) || __SIZEOF_WCHAR_T__ != 2)
		#define N_WCHAR_SIZE 4
	#endif // !defined(N_WINDOWS) && (!defined(__SIZEOF_WCHAR_T__) || __SIZEOF_WCHAR_T__ != 2)
#endif // !N_NO_UNICODE

#ifdef N_64
	const NSizeType N_SIZE_TYPE_MIN = N_UINT64_MIN;
	const NSizeType N_SIZE_TYPE_MAX = N_UINT64_MAX;
	const NSSizeType N_SSIZE_TYPE_MIN = N_INT64_MIN;
	const NSSizeType N_SSIZE_TYPE_MAX = N_INT64_MAX;
#else
	const NSizeType N_SIZE_TYPE_MIN = N_UINT32_MIN;
	const NSizeType N_SIZE_TYPE_MAX = N_UINT32_MAX;
	const NSSizeType N_SSIZE_TYPE_MIN = N_INT32_MIN;
	const NSSizeType N_SSIZE_TYPE_MAX = N_INT32_MAX;
#endif

inline NByte NMakeByte(NByte lowNibble, NByte highNibble)
{
	return (NByte)((highNibble << 4) | (lowNibble & 0x0F));
}

inline NByte NHiNibble(NByte value)
{
	return (NByte)((value >> 4) & 0x0F);
}

inline NByte NLoNibble(NByte value)
{
	return (NByte)(value & 0x0F);
}

inline NByte NSwapNibbles(NByte value)
{
	return (NByte)((value << 4) | ((value >> 4) & 0x0F));
}

inline NUShort NMakeWord(NByte low, NByte high)
{
	return (NUShort)(low | (high << 8));
}

inline NByte NHiByte(NUShort value)
{
	return (NByte)(value >> 8);
}

inline NByte NLoByte(NUShort value)
{
	return (NByte)value;
}

inline NUInt NMakeDWord(NUShort low, NUShort high)
{
	return (NUInt)(low | (high << 16));
}

inline NUShort NHiWord(NUInt value)
{
	return (NUShort)(value >> 16);
}

inline NUShort NLoWord(NUInt value)
{
	return (NUShort)value;
}

#ifndef N_NO_INT_64

inline NULong NMakeQWord(NUInt low, NUInt high)
{
	return (NULong)(low | (((NULong)high) << 32));
}

inline NUInt NHiDWord(NULong value)
{
	return (NUInt)(value >> 32);
}

inline NUInt NLoDWord(NULong value)
{
	return (NUInt)value;
}

#endif

inline NUShort NSwapWord(NUShort value)
{
	return (NUShort)((((NByte)value) << 8) | ((NByte)(value >> 8)));
}

inline NUInt NSwapDWord(NUInt value)
{
	return (NUInt)((NSwapWord((NUShort)value) << 16) | NSwapWord((NUShort)(value >> 16)));
}

#ifndef N_NO_INT_64
inline NULong NSwapQWord(NULong value)
{
	return (NULong)(((NULong)NSwapDWord((NUInt)value) << 32) | NSwapDWord((NUInt)(value >> 32)));
}
#endif

inline NUShort NHostToNetworkWord(NUShort value)
{
#ifndef N_BIG_ENDIAN
	return NSwapWord(value);
#else
	return value;
#endif
}

inline NUInt NHostToNetworkDWord(NUInt value)
{
#ifndef N_BIG_ENDIAN
	return NSwapDWord(value);
#else
	return value;
#endif
}

inline NUShort NNetworkToHostWord(NUShort value)
{
#ifndef N_BIG_ENDIAN
	return NSwapWord(value);
#else
	return value;
#endif
}

inline NUInt NNetworkToHostDWord(NUInt value)
{
#ifndef N_BIG_ENDIAN
	return NSwapDWord(value);
#else
	return value;
#endif
}

inline bool NIsFlagSet(NUInt flags, NUInt flag)
{
	return (flags & flag) == flag;
}

inline NUInt NSetFlag(NUInt & flags, NUInt flag)
{
	return flags |= flag;
}

inline NUInt NResetFlag(NUInt & flags, NUInt flag)
{
	return flags &= ~flag;
}

inline NUInt NSetFlagValue(NUInt & flags, NUInt flag, bool value)
{
	return value ? NSetFlag(flags, flag) : NResetFlag(flags, flag);
}

inline NUInt NSetFlagIf(NUInt & flags, NUInt flag, bool condition)
{
	return condition ? NSetFlag(flags, flag) : flags;
}

inline NUInt NResetFlagIf(NUInt & flags, NUInt flag, bool condition)
{
	return condition ? NResetFlag(flags, flag) : flags;
}

inline bool NIsMoreThanOneFlagSet(NUInt value)
{
	return (value & (value - 1)) != 0;
}

template<typename T> T NMax(T a, T b)
{
	return b > a ? b : a;
}

template<typename T> T NMin(T a, T b)
{
	return b < a ? b : a;
}

inline NInt NRound(NFloat x)
{
	return (NInt)(x >= 0 ? x + 0.5f : x - 0.5f);
}

inline NUInt NRoundP(NFloat x)
{
	return (NUInt)(x + 0.5f);
}

inline NInt NRound(NDouble x)
{
	return (NInt)(x >= 0 ? x + 0.5 : x - 0.5);
}

inline NUInt NRoundP(NDouble x)
{
	return (NUInt)(x + 0.5);
}

inline NInt NSqr(NInt x)
{
	return x * x;
}

inline NFloat NSqr(NFloat x)
{
	return x * x;
}

inline NDouble NSqr(NDouble x)
{
	return x * x;
}

template<typename T> void NSwap(T & a, T & b)
{
	T temp = a;
	a = b;
	b = temp;
}

}

// Define various types
#if defined(N_FRAMEWORK_MFC)
	#include <Core/NNoDeprecate.h>
	#include <afx.h>
	#include <Core/NReDeprecate.h>

#elif defined(N_FRAMEWORK_WX)
	#include <Core/NNoDeprecate.h>
	#include <memory>
	#include <wx/string.h>
	#include <wx/object.h>
	#include <Core/NReDeprecate.h>
#elif defined(N_FRAMEWORK_QT)
	#include <Core/NNoDeprecate.h>
	#include <memory>
	#include <QString>
	#include <QObject>
	#include <Core/NReDeprecate.h>
#else
	#define N_FRAMEWORK_NATIVE

	#include <Core/NNoDeprecate.h>
	#include <memory>
	#include <string>
	#include <Core/NReDeprecate.h>
#endif

#define N_DECLARE_NON_COPYABLE(name) \
	private:\
		name(const name &);\
		name & operator=(const name &);

#define N_NATIVE_TYPE_OF(name) (name::NativeTypeOf())

#define N_DECLARE_TYPE_CLASS(name) \
	public:\
		static ::Neurotec::NType NativeTypeOf()\
		{\
			return ::Neurotec::NObject::GetObject< ::Neurotec::NType>(N_TYPE_OF(name), true);\
		}
#define N_DECLARE_PRIMITIVE_CLASS(name) \
	N_DECLARE_NON_COPYABLE(name)
#define N_DECLARE_BASIC_CLASS_EX(name, fieldAccess) \
	N_DECLARE_TYPE_CLASS(name)\
fieldAccess:\
	name##_ value;\
public:\
	name(const name & other)\
		: value(other.value)\
	{\
	}\
	name & operator=(const name & other)\
	{\
		this->value = other.value;\
		return *this;\
	}\
	explicit name(name##_ value)\
		: value(value)\
	{\
	}\
	name()\
	{\
	}\
	bool operator==(const name & value) const\
	{\
		return this->value == value.value;\
	}\
	bool operator!=(const name & value) const\
	{\
		return this->value != value.value;\
	}\
public:\
	typedef name##_ NativeType;\
	name##_ GetValue() const\
	{\
		return value;\
	}
#define N_DECLARE_COMPARABLE_BASIC_CLASS_EX(name, fieldAccess) \
	N_DECLARE_BASIC_CLASS_EX(name, fieldAccess)\
public:\
	bool operator>(const name & value) const\
	{\
		return this->value > value.value;\
	}\
	bool operator<(const name & value) const\
	{\
		return this->value < value.value;\
	}\
	bool operator>=(const name & value) const\
	{\
		return this->value > value.value;\
	}\
	bool operator<=(const name & value) const\
	{\
		return this->value < value.value;\
	}
#define N_DECLARE_BASIC_CLASS(name) N_DECLARE_BASIC_CLASS_EX(name, private)
#define N_DECLARE_COMPARABLE_BASIC_CLASS(name) N_DECLARE_COMPARABLE_BASIC_CLASS_EX(name, private)
#define N_DECLARE_BASIC_CLASS_BASE(name) N_DECLARE_BASIC_CLASS_EX(name, protected)
#define N_DECLARE_COMPARABLE_BASIC_CLASS_BASE(name) N_DECLARE_COMPARABLE_BASIC_CLASS_EX(name, protected)
#define N_DECLARE_BASIC_CLASS_DERIVED(name, baseName) \
	N_DECLARE_TYPE_CLASS(name)\
public:\
	name(const name & other)\
		: baseName(other)\
	{\
	}\
	name & operator=(const name & other)\
	{\
		return (name &)baseName::operator=(other);\
	}\
	explicit name(name##_ value)\
		: baseName(value)\
	{\
	}\
	name()\
	{\
	}\
	bool operator==(const name & value) const\
	{\
		return baseName::operator==(value);\
	}\
	bool operator!=(const name & value) const\
	{\
		return baseName::operator!=(value);\
	}
#define N_DECLARE_COMPARABLE_BASIC_CLASS_DERIVED(name) \
	N_DECLARE_BASIC_CLASS_DERIVED(name)\
public:\
	bool operator>(const name & value) const\
	{\
		return baseName::operator>(value);\
	}\
	bool operator<(const name & value) const\
	{\
		return baseName::operator<(value);\
	}\
	bool operator>=(const name & value) const\
	{\
		return baseName::operator>=(value);\
	}\
	bool operator<=(const name & value) const\
	{\
		return baseName::operator<=(value);\
	}
#define N_DECLARE_STRUCT_CLASS(name) \
	N_DECLARE_TYPE_CLASS(name)\
public:\
	typedef struct name##_ NativeType;\
	name()\
	{\
	}\
	name(const struct name##_ & value)\
	{\
		memcpy(this, &value, sizeof(value));\
	}\
	name & operator=(const struct name##_ & value)\
	{\
		memcpy(this, &value, sizeof(value));\
		return *this;\
	}
#ifdef N_CPP11
#define N_DISPOSABLE_STRUCT_MOVE_CONSTRUCTOR(name)\
	name(name && other)\
	{\
		memcpy(this, &other, sizeof(other));\
		memset(&other, 0, sizeof(other));\
	}\
	name& operator=(name && other)\
	{\
		if (this != &other)\
		{\
			NCheck(name##Dispose(this));\
			memcpy(this, &other, sizeof(other));\
			memset(&other, 0, sizeof(other));\
		}\
		return *this;\
	}
#else
#define N_DISPOSABLE_STRUCT_MOVE_CONSTRUCTOR(name)
#endif
#define N_DECLARE_DISPOSABLE_STRUCT_CLASS(name) \
	N_DECLARE_TYPE_CLASS(name)\
public:\
	typedef struct name##_ NativeType;\
	name()\
	{\
		memset(this, 0, sizeof(*this));\
	}\
	name(const name & other)\
	{\
		NCheck(name##Copy(&other, this));\
	}\
	N_DISPOSABLE_STRUCT_MOVE_CONSTRUCTOR(name)\
	~name()\
	{\
		NCheck(name##Dispose(this));\
	}\
	name & operator=(const name & other)\
	{\
		NCheck(name##Set(&other, this));\
		return *this;\
	}
#define N_EQUATABLE_STRUCT_OPERATOR(name)\
public:\
	bool operator==(const name & value) const\
	{\
		return name::NativeTypeOf().AreValuesEqual(this, sizeof(value), &value, sizeof(value));\
	}
#define N_DECLARE_EQUATABLE_STRUCT_CLASS(name)\
	N_DECLARE_STRUCT_CLASS(name)\
	N_EQUATABLE_STRUCT_OPERATOR(name)
#define N_DECLARE_EQUATABLE_DISPOSABLE_STRUCT_CLASS(name)\
	N_DECLARE_DISPOSABLE_STRUCT_CLASS(name)\
	N_EQUATABLE_STRUCT_OPERATOR(name)
	
namespace Neurotec
{

class NObject;
class NModule;
class NType;
class NValue;
class NArray;
class NString;
class NStringWrapper;
class NPropertyBag;
class NObjectPart;
namespace Text
{
class NStringBuilder;
}
namespace IO
{
class NBuffer;
class NStream;
}
namespace Reflection
{
class NParameterInfo;
class NMemberInfo;
class NEnumConstantInfo;
class NConstantInfo;
class NMethodInfo;
class NPropertyInfo;
class NEventInfo;
class NObjectPartInfo;
class NCollectionInfo;
class NDictionaryInfo;
class NArrayCollectionInfo;
}
namespace Collections
{
class NCollection;
class NDictionary;
class NArrayCollection;
}
NInt NCheck(NResult result);
void N_NO_RETURN NThrowArgumentNullException(const NStringWrapper & paramName);
void N_NO_RETURN NThrowArgumentOutOfRangeException(const NStringWrapper & paramName);
void N_NO_RETURN NThrowArgumentLessThanZeroException(const NStringWrapper & paramName);
void N_NO_RETURN NThrowArgumentInsufficientException(const NStringWrapper & paramName);
void N_NO_RETURN NThrowArgumentException(const NStringWrapper & paramName);
void N_NO_RETURN NThrowInvalidOperationException(const NStringWrapper & message);
void N_NO_RETURN NThrowInvalidOperationException();
void N_NO_RETURN NThrowArgumentNotImplementedException();
void N_NO_RETURN NThrowOverflowException();
void N_NO_RETURN NThrowNullReferenceException();
void N_NO_RETURN NThrowNotImplementedException();
void N_NO_RETURN NThrowNotSupportedException();

template<typename T, bool IsNObject = false> struct NTypeTraitsBase
{
	typedef T NativeType;
	static NType GetNativeType();
	static NativeType ToNative(const T & value) { return value; }
	static T FromNative(NativeType & value, bool claimHandle = true) { return value; N_UNREFERENCED_PARAMETER(claimHandle); }
	static void SetNative(const NativeType & sourceValue, NativeType * destinationValue) { *destinationValue = sourceValue; }
	static void FreeNative(NativeType & value) { N_UNREFERENCED_PARAMETER(value); }
};

template <typename B, typename D>
struct NIsBaseOf
{
	typedef char(&yes)[1];
	typedef char(&no)[2];

	struct Host
	{
		operator B*() const;
		operator D*();
	};

	template <typename T>
	static yes check(D*, T);
	static no check(B*, int);

	static const bool value = sizeof(check(Host(), int())) == sizeof(yes);
};

template<typename T> struct NTypeTraitsBase<T, true>;

template<typename T>
struct NTypeTraits : public NTypeTraitsBase<T, NIsBaseOf<NObject, T>::value >
{
};

#define N_DEFINE_ENUM_TYPE_TRAITS(typeNamespace, type) \
	namespace Neurotec\
	{\
		template<> struct NTypeTraitsBase<typeNamespace::type>\
		{\
			typedef typeNamespace::type NativeType;\
			static NType GetNativeType() { HNType hValue; NCheck(typeNamespace::N_TYPE_OF(type)(&hValue)); return NObject::FromHandle<NType>(hValue, true); }\
			static typeNamespace::type ToNative(const typeNamespace::type & value) { return value; }\
			static void SetNative(const NativeType & sourceValue, NativeType * destinationValue) { *destinationValue = sourceValue; }\
			static typeNamespace::type FromNative(typeNamespace::type value, bool) { return value; }\
			static void FreeNative(typeNamespace::type value) { N_UNREFERENCED_PARAMETER(value); }\
		};\
	}

#define N_DEFINE_DISPOSABLE_STRUCT_TYPE_TRAITS(typeNamespace, type) \
	namespace Neurotec\
	{\
		template<> struct NTypeTraitsBase<typeNamespace::type>\
		{\
			typedef typeNamespace::type##_ NativeType;\
			static NType GetNativeType() { HNType hValue; NCheck(typeNamespace::N_TYPE_OF(type)(&hValue)); return NObject::FromHandle<NType>(hValue, true); }\
			static NativeType ToNative(const typeNamespace::type & value) { return static_cast<NativeType>(value); }\
			static void SetNative(const NativeType & sourceValue, NativeType * destinationValue) { NCheck(type##Set(&sourceValue, destinationValue)); }\
			static typeNamespace::type FromNative(NativeType value, bool ownsHandle) { typeNamespace::type s; if (ownsHandle) memcpy(&s, &value, sizeof(NativeType)); else type##Set(&value, &s); return s; }\
			static void FreeNative(NativeType & value) { type##Dispose(&value); }\
		};\
	}

#define N_DEFINE_STRUCT_TYPE_TRAITS(typeNamespace, type) \
	namespace Neurotec\
	{\
		template<> struct NTypeTraitsBase<typeNamespace::type>\
		{\
			typedef typeNamespace::type##_ NativeType;\
			static NType GetNativeType() { HNType hValue; NCheck(typeNamespace::N_TYPE_OF(type)(&hValue)); return NObject::FromHandle<NType>(hValue, true); }\
			static NativeType ToNative(const typeNamespace::type & value) { return static_cast<NativeType>(value); }\
			static void SetNative(const NativeType & sourceValue, NativeType * destinationValue) { *destinationValue = sourceValue; }\
			static typeNamespace::type FromNative(NativeType value, bool ownsHandle) { return static_cast<typeNamespace::type>(value); N_UNREFERENCED_PARAMETER(ownsHandle); }\
			static void FreeNative(NativeType & value) { N_UNREFERENCED_PARAMETER(value); }\
		};\
	}
}

#include <Core/NString.hpp>
#include <Core/NCallback.hpp>

namespace Neurotec
{
	class NObjectBase
	{
	protected:
		NObjectBase()
		{
		}

		NObjectBase(const NObjectBase&)
		{
		}

		NObjectBase& operator=(const NObjectBase&)
		{
			return *this;
		}

	public:
		virtual ~NObjectBase()
		{
		}
	};

#undef NCharTypeOf
inline NResult N_API NCharTypeOf(HNType * phValue)
{
#ifdef N_UNICODE
	return NWCharTypeOf(phValue);
#else
	return NACharTypeOf(phValue);
#endif
}

class EventArgs
{
private:
	HNObject hObject;
	void * pParam;

public:
	EventArgs(HNObject hObject, void * pParam)
	{
		this->hObject = hObject;
		this->pParam = pParam;
	}

	template<typename T>
	T GetObject() const
	{
		return T(hObject, false);
	}

	void * GetParam() const
	{
		return pParam;
	}
};

template<typename F>
class EventHandlerBase
{
public:
	F callback;
	void * pParam;

	EventHandlerBase(const F & callback)
		: callback(callback)
	{
	}

private:
	static NResult N_API OnFree(void * ptr, void *)
	{
		delete static_cast<EventHandlerBase<F> *>(ptr);
		return 0;
	}

	static NResult N_API OnGetHashCode(void * ptr, NInt * pValue, void *)
	{
		EventHandlerBase<F> * pHandler = static_cast<EventHandlerBase<F> *>(ptr);
	#ifdef N_64
		*pValue = (NInt)(NHiDWord((NSizeType)pHandler->callback) ^ NLoDWord((NSizeType)pHandler->callback));
	#else
		*pValue = (NInt)(pHandler->callback);
	#endif
		return 0;
	}

	static NResult N_API OnEquals(void * ptr, void * otherPtr, NBool * pResult, void *)
	{
		EventHandlerBase<F> * pHandler = static_cast<EventHandlerBase<F> *>(ptr);
		EventHandlerBase<F> * pOtherHandler = static_cast<EventHandlerBase<F> *>(otherPtr);
		*pResult = (pHandler->callback == pOtherHandler->callback) ? NTrue : NFalse;
		return 0;
	}

	template<typename T>
	static NPointerGetHashCodeProc GetGetHashCodeProc(const T &)
	{
		return NULL;
	}

	template<typename T>
	static NPointerGetHashCodeProc GetGetHashCodeProc(T *)
	{
		return OnGetHashCode;
	}

	template<typename T>
	static NPointerEqualsProc GetEqualsProc(const T &)
	{
		return NULL;
	}

	template<typename T>
	static NPointerEqualsProc GetEqualsProc(T *)
	{
		return OnEquals;
	}

	friend class NTypes;
};

class NTypes
{
public:
	struct CallbackParam
	{
	private:
		void * pParam;
		void * pCallback;
		void * pCallbackParam;

	public:
		CallbackParam(void * pParam, void * pCallback, void * pCallbackParam)
			: pParam(pParam), pCallback(pCallback), pCallbackParam(pCallbackParam)
		{
		}

		void * GetParam() const
		{
			return pParam;
		}

		void * GetCallback() const
		{
			return pCallback;
		}

		void * GetCallbackParam() const
		{
			return pCallbackParam;
		}

		operator size_t() const
		{
			return (size_t)pCallback ^ (size_t)pCallbackParam;
		}

		bool operator==(const CallbackParam & other) const
		{
			return this->pCallback == other.pCallback && this->pCallbackParam == other.pCallbackParam;
		}
	};

	template<typename DelegateType, typename CallbackType>
	static NCallback CreateCallback(CallbackType callback, void * pParam)
	{
		std::auto_ptr<DelegateType> callbackDelegate(new DelegateType(callback));
		callbackDelegate->pParam = pParam;
		NCallback cb(DelegateType::NativeCallback, callbackDelegate.get(), DelegateType::OnFree,
			DelegateType::GetGetHashCodeProc(callback), DelegateType::GetEqualsProc(callback));
		callbackDelegate.release();
		return cb;
	}

private:
	static NResult N_API OnCallbackFree(void * ptr, void *);
	static NResult N_API OnCallbackGetHashCode(void * ptr, NInt * pValue, void *);
	static NResult N_API OnCallbackEquals(void * ptr, void * otherPtr, NBool * pResult, void *);
	template<typename T>
	static NResult N_API OnCallbackWrapperFree(void * ptr, void *);
	static NResult N_API PointerFreeProcImpl(void * ptr, void * pParam);
	static NResult N_API PointerGetHashCodeImpl(void * ptr, NInt * pValue, void * pParam);
	static NResult N_API PointerEqualsImpl(void * ptr, void * otherPtr, NBool * pResult, void * pParam);

	NTypes();
	NTypes & operator=(const NTypes &);

public:
	typedef void (* PointerFreeProc)(const void * ptr, void * pParam);
	typedef NInt (* PointerGetHashCodeProc)(void * ptr, void * pParam);
	typedef bool (* PointerEqualsProc)(void * ptr, void * otherPtr, void * pParam);

	template<typename TNative, typename T> static NCallback CreateCallback(TNative pNativeCallback, T pCallback, void * pCallbackParam)
	{
		return CreateCallback<TNative, T>(pNativeCallback, NULL, pCallback, pCallbackParam);
	}

	template<typename TNative, typename T> static NCallback CreateCallback(TNative pNativeCallback, void * pParam, T pCallback, void * pCallbackParam)
	{
		if (!pCallback)
		{
			if (pCallbackParam) NThrowArgumentNullException(N_T("pCallback"));
			return NCallback();
		}
		::std::auto_ptr<CallbackParam> p(new CallbackParam(pParam, reinterpret_cast<void *>(pCallback), pCallbackParam));
		NCallback callback(pNativeCallback, p.get(), OnCallbackFree, OnCallbackGetHashCode, OnCallbackEquals);
		p.release();
		return callback;
	}

	static NType NUInt8NativeTypeOf();
	static NType NInt8NativeTypeOf();
	static NType NUInt16NativeTypeOf();
	static NType NInt16NativeTypeOf();
	static NType NUInt32NativeTypeOf();
	static NType NInt32NativeTypeOf();
	static NType NUInt64NativeTypeOf();
	static NType NInt64NativeTypeOf();
	static NType NSingleNativeTypeOf();
	static NType NDoubleNativeTypeOf();
	static NType NBooleanNativeTypeOf();
	static NType NSizeTypeNativeTypeOf();
	static NType NSSizeTypeNativeTypeOf();
	static NType NPointerNativeTypeOf();
	static NType NResultNativeTypeOf();
	static NType NACharNativeTypeOf();
#ifndef N_NO_UNICODE
	static NType NWCharNativeTypeOf();
#endif
	static NType NCharNativeTypeOf();
	static NType NStringNativeTypeOf();
	static NType NCallbackNativeTypeOf();
	static NType NMemoryTypeNativeTypeOf();
	static NType NAttributesNativeTypeOf();
	static NType NOSFamilyNativeTypeOf();
	static NType NativeTypeOf();

#ifndef N_NO_FLOAT
	static NSingle GetSinglePositiveInfinity() { return NSingleGetPositiveInfinity(); }
	static NSingle GetSingleNegativeInfinity() { return NSingleGetNegativeInfinity(); }
	static NSingle GetSingleNaN() { return NSingleGetNaN(); }
	static bool IsSingleInfinity(NSingle value) { return NSingleIsInfinity(value) != 0; }
	static bool IsSingleNegativeInfinity(NSingle value) { return NSingleIsNegativeInfinity(value) != 0; }
	static bool IsSinglePositiveInfinity(NSingle value) { return NSingleIsPositiveInfinity(value) != 0; }
	static bool IsSingleNaN(NSingle value) { return NSingleIsNaN(value) != 0; }
	static NDouble GetDoublePositiveInfinity() { return NDoubleGetPositiveInfinity(); }
	static NDouble GetDoubleNegativeInfinity() { return NDoubleGetNegativeInfinity(); }
	static NDouble GetDoubleNaN() { return NDoubleGetNaN(); }
	static bool IsDoubleInfinity(NDouble value) { return NDoubleIsInfinity(value) != 0; }
	static bool IsDoubleNegativeInfinity(NDouble value) { return NDoubleIsNegativeInfinity(value) != 0; }
	static bool IsDoublePositiveInfinity(NDouble value) { return NDoubleIsPositiveInfinity(value) != 0; }
	static bool IsDoubleNaN(NDouble value) { return NDoubleIsNaN(value) != 0; }
#endif // !N_NO_FLOAT

	static NChar CharFromDigit(NInt value) { return NCharFromDigit(value); }
	static NChar CharFromHexDigit(NInt value, bool lowercase = false) { return NCharFromHexDigit(value, lowercase); }
	static NChar CharFromOctDigit(NInt value) { return NCharFromOctDigit(value); }
	static NChar CharFromBinDigit(NInt value) { return NCharFromBinDigit(value); }

	static NInt CharToChars(NChar value, const NChar * szFormat, NChar * arValue, NInt valueLength) { return NCheck(NCharToChars(value, szFormat, arValue, valueLength)); }
	static NInt UInt8ToChars(NUInt8 value, const NChar * szFormat, NChar * arValue, NInt valueLength) { return NCheck(NUInt8ToChars(value, szFormat, arValue, valueLength)); }
	static NInt Int8ToChars(NInt8 value, const NChar * szFormat, NChar * arValue, NInt valueLength) { return NCheck(NInt8ToChars(value, szFormat, arValue, valueLength)); }
	static NInt UInt16ToChars(NUInt16 value, const NChar * szFormat, NChar * arValue, NInt valueLength) { return NCheck(NUInt16ToChars(value, szFormat, arValue, valueLength)); }
	static NInt Int16ToChars(NInt16 value, const NChar * szFormat, NChar * arValue, NInt valueLength) { return NCheck(NInt16ToChars(value, szFormat, arValue, valueLength)); }
	static NInt UInt32ToChars(NUInt32 value, const NChar * szFormat, NChar * arValue, NInt valueLength) { return NCheck(NUInt32ToChars(value, szFormat, arValue, valueLength)); }
	static NInt Int32ToChars(NInt32 value, const NChar * szFormat, NChar * arValue, NInt valueLength) { return NCheck(NInt32ToChars(value, szFormat, arValue, valueLength)); }
#ifndef N_NO_INT_64
	static NInt UInt64ToChars(NUInt64 value, const NChar * szFormat, NChar * arValue, NInt valueLength) { return NCheck(NUInt64ToChars(value, szFormat, arValue, valueLength)); }
	static NInt Int64ToChars(NInt64 value, const NChar * szFormat, NChar * arValue, NInt valueLength) { return NCheck(NInt64ToChars(value, szFormat, arValue, valueLength)); }
#endif // !N_NO_INT_64
	static NInt SizeTypeToChars(NSizeType value, const NChar * szFormat, NChar * arValue, NInt valueLength) { return NCheck(NSizeTypeToChars(value, szFormat, arValue, valueLength)); }
	static NInt SSizeTypeToChars(NSSizeType value, const NChar * szFormat, NChar * arValue, NInt valueLength) { return NCheck(NSSizeTypeToChars(value, szFormat, arValue, valueLength)); }
	static NInt PointerToChars(const void * value, const NChar * szFormat, NChar * arValue, NInt valueLength) { return NCheck(NPointerToChars(value, szFormat, arValue, valueLength)); }
#ifndef N_NO_FLOAT
	static NInt SingleToChars(NSingle value, const NChar * szFormat, NChar * arValue, NInt valueLength) { return NCheck(NSingleToChars(value, szFormat, arValue, valueLength)); }
	static NInt DoubleToChars(NDouble value, const NChar * szFormat, NChar * arValue, NInt valueLength) { return NCheck(NDoubleToChars(value, szFormat, arValue, valueLength)); }
#endif // !N_NO_FLOAT
	static NInt BooleanToChars(NBoolean value, const NChar * szFormat, NChar * arValue, NInt valueLength) { return NCheck(NBooleanToChars(value, szFormat, arValue, valueLength)); }

	static NString CharToString(NChar value, const NStringWrapper & format = NString())
	{
		HNString hValue;
		NCheck(NCharToStringN(value, format.GetHandle(), &hValue));
		return NString(hValue, true);
	}

	static NString UInt8ToString(NUInt8 value, const NStringWrapper & format = NString())
	{
		HNString hValue;
		NCheck(NUInt8ToStringN(value, format.GetHandle(), &hValue));
		return NString(hValue, true);
	}

	static NString Int8ToString(NInt8 value, const NStringWrapper & format = NString())
	{
		HNString hValue;
		NCheck(NInt8ToStringN(value, format.GetHandle(), &hValue));
		return NString(hValue, true);
	}

	static NString UInt16ToString(NUInt16 value, const NStringWrapper & format = NString())
	{
		HNString hValue;
		NCheck(NUInt16ToStringN(value, format.GetHandle(), &hValue));
		return NString(hValue, true);
	}

	static NString Int16ToString(NInt16 value, const NStringWrapper & format = NString())
	{
		HNString hValue;
		NCheck(NInt16ToStringN(value, format.GetHandle(), &hValue));
		return NString(hValue, true);
	}

	static NString UInt32ToString(NUInt32 value, const NStringWrapper & format = NString())
	{
		HNString hValue;
		NCheck(NUInt32ToStringN(value, format.GetHandle(), &hValue));
		return NString(hValue, true);
	}

	static NString Int32ToString(NInt32 value, const NStringWrapper & format = NString())
	{
		HNString hValue;
		NCheck(NInt32ToStringN(value, format.GetHandle(), &hValue));
		return NString(hValue, true);
	}

#ifndef N_NO_INT_64
	static NString UInt64ToString(NUInt64 value, const NStringWrapper & format = NString())
	{
		HNString hValue;
		NCheck(NUInt64ToStringN(value, format.GetHandle(), &hValue));
		return NString(hValue, true);
	}

	static NString Int64ToString(NInt64 value, const NStringWrapper & format = NString())
	{
		HNString hValue;
		NCheck(NInt64ToStringN(value, format.GetHandle(), &hValue));
		return NString(hValue, true);
	}
#endif // !N_NO_INT_64

	static NString SizeTypeToString(NSizeType value, const NStringWrapper & format = NString())
	{
		HNString hValue;
		NCheck(NSizeTypeToStringN(value, format.GetHandle(), &hValue));
		return NString(hValue, true);
	}

	static NString SSizeTypeToString(NSSizeType value, const NStringWrapper & format = NString())
	{
		HNString hValue;
		NCheck(NSSizeTypeToStringN(value, format.GetHandle(), &hValue));
		return NString(hValue, true);
	}

	static NString PointerToString(const void * value, const NStringWrapper & format = NString())
	{
		HNString hValue;
		NCheck(NPointerToStringN(value, format.GetHandle(), &hValue));
		return NString(hValue, true);
	}

#ifndef N_NO_FLOAT
	static NString SingleToString(NSingle value, const NStringWrapper & format = NString())
	{
		HNString hValue;
		NCheck(NSingleToStringN(value, format.GetHandle(), &hValue));
		return NString(hValue, true);
	}

	static NString DoubleToString(NDouble value, const NStringWrapper & format = NString())
	{
		HNString hValue;
		NCheck(NDoubleToStringN(value, format.GetHandle(), &hValue));
		return NString(hValue, true);
	}
#endif // !N_NO_FLOAT

	static NString BooleanToString(NBoolean value, const NStringWrapper & format = NString())
	{
		HNString hValue;
		NCheck(NBooleanToStringN(value, format.GetHandle(), &hValue));
		return NString(hValue, true);
	}

	static bool CharIsWhiteSpace(NChar value) { return NCharIsWhiteSpace(value) != 0; }
	static bool CharIsAscii(NChar value) { return NCharIsAscii(value) != 0; }
	static bool CharIsLetter(NChar value) { return NCharIsLetter(value) != 0; }
	static bool CharIsLower(NChar value) { return NCharIsLower(value) != 0; }
	static bool CharIsUpper(NChar value) { return NCharIsUpper(value) != 0; }
	static bool CharIsDigit(NChar value) { return NCharIsDigit(value) != 0; }
	static bool CharIsHexDigit(NChar value) { return NCharIsHexDigit(value) != 0; }
	static bool CharIsOctDigit(NChar value) { return NCharIsOctDigit(value) != 0; }
	static bool CharIsBinDigit(NChar value) { return NCharIsBinDigit(value) != 0; }
	static NChar CharToLower(NChar value) { return NCharToLower(value); }
	static NChar CharToUpper(NChar value) { return NCharToUpper(value); }
	static NInt CharToDigit(NChar value) { return NCharToDigit(value); }
	static NInt CharToHexDigit(NChar value) { return NCharToHexDigit(value); }
	static NInt CharToOctDigit(NChar value) { return NCharToOctDigit(value); }
	static NInt CharToBinDigit(NChar value) { return NCharToBinDigit(value); }

	static bool CharTryParse(const NChar * arValue, NInt valueLength, const NChar * szFormat, NChar * pValue)
	{
		NBool result;
		NCheck(NCharTryParseStrOrChars(arValue, valueLength, szFormat, pValue, &result));
		return result != 0;
	}

	static bool UInt8TryParse(const NChar * arValue, NInt valueLength, const NChar * szFormat, NUInt8 * pValue)
	{
		NBool result;
		NCheck(NUInt8TryParseStrOrChars(arValue, valueLength, szFormat, pValue, &result));
		return result != 0;
	}

	static bool Int8TryParse(const NChar * arValue, NInt valueLength, const NChar * szFormat, NInt8 * pValue)
	{
		NBool result;
		NCheck(NInt8TryParseStrOrChars(arValue, valueLength, szFormat, pValue, &result));
		return result != 0;
	}

	static bool UInt16TryParse(const NChar * arValue, NInt valueLength, const NChar * szFormat, NUInt16 * pValue)
	{
		NBool result;
		NCheck(NUInt16TryParseStrOrChars(arValue, valueLength, szFormat, pValue, &result));
		return result != 0;
	}

	static bool Int16TryParse(const NChar * arValue, NInt valueLength, const NChar * szFormat, NInt16 * pValue)
	{
		NBool result;
		NCheck(NInt16TryParseStrOrChars(arValue, valueLength, szFormat, pValue, &result));
		return result != 0;
	}

	static bool UInt32TryParse(const NChar * arValue, NInt valueLength, const NChar * szFormat, NUInt32 * pValue)
	{
		NBool result;
		NCheck(NUInt32TryParseStrOrChars(arValue, valueLength, szFormat, pValue, &result));
		return result != 0;
	}

	static bool Int32TryParse(const NChar * arValue, NInt valueLength, const NChar * szFormat, NInt32 * pValue)
	{
		NBool result;
		NCheck(NInt32TryParseStrOrChars(arValue, valueLength, szFormat, pValue, &result));
		return result != 0;
	}

#ifndef N_NO_INT_64
	static bool UInt64TryParse(const NChar * arValue, NInt valueLength, const NChar * szFormat, NUInt64 * pValue)
	{
		NBool result;
		NCheck(NUInt64TryParseStrOrChars(arValue, valueLength, szFormat, pValue, &result));
		return result != 0;
	}

	static bool Int64TryParse(const NChar * arValue, NInt valueLength, const NChar * szFormat, NInt64 * pValue)
	{
		NBool result;
		NCheck(NInt64TryParseStrOrChars(arValue, valueLength, szFormat, pValue, &result));
		return result != 0;
	}
#endif // !N_NO_INT_64

	static bool SizeTypeTryParse(const NChar * arValue, NInt valueLength, const NChar * szFormat, NSizeType * pValue)
	{
		NBool result;
		NCheck(NSizeTypeTryParseStrOrChars(arValue, valueLength, szFormat, pValue, &result));
		return result != 0;
	}

	static bool SSizeTypeTryParse(const NChar * arValue, NInt valueLength, const NChar * szFormat, NSSizeType * pValue)
	{
		NBool result;
		NCheck(NSSizeTypeTryParseStrOrChars(arValue, valueLength, szFormat, pValue, &result));
		return result != 0;
	}

	static bool PointerTryParse(const NChar * arValue, NInt valueLength, const NChar * szFormat, void * * pValue)
	{
		NBool result;
		NCheck(NPointerTryParseStrOrChars(arValue, valueLength, szFormat, pValue, &result));
		return result != 0;
	}

#ifndef N_NO_FLOAT
	static bool SingleTryParse(const NChar * arValue, NInt valueLength, const NChar * szFormat, NSingle * pValue)
	{
		NBool result;
		NCheck(NSingleTryParseStrOrChars(arValue, valueLength, szFormat, pValue, &result));
		return result != 0;
	}

	static bool DoubleTryParse(const NChar * arValue, NInt valueLength, const NChar * szFormat, NDouble * pValue)
	{
		NBool result;
		NCheck(NDoubleTryParseStrOrChars(arValue, valueLength, szFormat, pValue, &result));
		return result != 0;
	}
#endif // !N_NO_FLOAT

	static bool BooleanTryParse(const NChar * arValue, NInt valueLength, const NChar * szFormat, NBoolean * pValue)
	{
		NBool result;
		NCheck(NBooleanTryParseStrOrChars(arValue, valueLength, szFormat, pValue, &result));
		return result != 0;
	}

	static bool CharTryParse(const NStringWrapper & value, const NStringWrapper & format, NChar * pValue)
	{
		NBool result;
		NCheck(NCharTryParseN(value.GetHandle(), format.GetHandle(), pValue, &result));
		return result != 0;
	}
	static bool CharTryParse(const NStringWrapper & value, NChar * pValue) { return CharTryParse(value, NString(), pValue); }

	static bool UInt8TryParse(const NStringWrapper & value, const NStringWrapper & format, NUInt8 * pValue)
	{
		NBool result;
		NCheck(NUInt8TryParseN(value.GetHandle(), format.GetHandle(), pValue, &result));
		return result != 0;
	}
	static bool UInt8TryParse(const NStringWrapper & value, NUInt8 * pValue) { return UInt8TryParse(value, NString(), pValue); }

	static bool Int8TryParse(const NStringWrapper & value, const NStringWrapper & format, NInt8 * pValue)
	{
		NBool result;
		NCheck(NInt8TryParseN(value.GetHandle(), format.GetHandle(), pValue, &result));
		return result != 0;
	}
	static bool Int8TryParse(const NStringWrapper & value, NInt8 * pValue) { return Int8TryParse(value, NString(), pValue); }

	static bool UInt16TryParse(const NStringWrapper & value, const NStringWrapper & format, NUInt16 * pValue)
	{
		NBool result;
		NCheck(NUInt16TryParseN(value.GetHandle(), format.GetHandle(), pValue, &result));
		return result != 0;
	}
	static bool UInt16TryParse(const NStringWrapper & value, NUInt16 * pValue) { return UInt16TryParse(value, NString(), pValue); }

	static bool Int16TryParse(const NStringWrapper & value, const NStringWrapper & format, NInt16 * pValue)
	{
		NBool result;
		NCheck(NInt16TryParseN(value.GetHandle(), format.GetHandle(), pValue, &result));
		return result != 0;
	}
	static bool Int16TryParse(const NStringWrapper & value, NInt16 * pValue) { return Int16TryParse(value, NString(), pValue); }

	static bool UInt32TryParse(const NStringWrapper & value, const NStringWrapper & format, NUInt32 * pValue)
	{
		NBool result;
		NCheck(NUInt32TryParseN(value.GetHandle(), format.GetHandle(), pValue, &result));
		return result != 0;
	}
	static bool UInt32TryParse(const NStringWrapper & value, NUInt32 * pValue) { return UInt32TryParse(value, NString(), pValue); }

	static bool Int32TryParse(const NStringWrapper & value, const NStringWrapper & format, NInt32 * pValue)
	{
		NBool result;
		NCheck(NInt32TryParseN(value.GetHandle(), format.GetHandle(), pValue, &result));
		return result != 0;
	}
	static bool Int32TryParse(const NStringWrapper & value, NInt32 * pValue) { return Int32TryParse(value, NString(), pValue); }

#ifndef N_NO_INT_64
	static bool UInt64TryParse(const NStringWrapper & value, const NStringWrapper & format, NUInt64 * pValue)
	{
		NBool result;
		NCheck(NUInt64TryParseN(value.GetHandle(), format.GetHandle(), pValue, &result));
		return result != 0;
	}
	static bool UInt64TryParse(const NStringWrapper & value, NUInt64 * pValue) { return UInt64TryParse(value, NString(), pValue); }

	static bool Int64TryParse(const NStringWrapper & value, const NStringWrapper & format, NInt64 * pValue)
	{
		NBool result;
		NCheck(NInt64TryParseN(value.GetHandle(), format.GetHandle(), pValue, &result));
		return result != 0;
	}
	static bool Int64TryParse(const NStringWrapper & value, NInt64 * pValue) { return Int64TryParse(value, NString(), pValue); }
#endif // !N_NO_INT_64

	static bool SizeTypeTryParse(const NStringWrapper & value, const NStringWrapper & format, NSizeType * pValue)
	{
		NBool result;
		NCheck(NSizeTypeTryParseN(value.GetHandle(), format.GetHandle(), pValue, &result));
		return result != 0;
	}
	static bool SizeTypeTryParse(const NStringWrapper & value, NSizeType * pValue) { return SizeTypeTryParse(value, NString(), pValue); }

	static bool SSizeTypeTryParse(const NStringWrapper & value, const NStringWrapper & format, NSSizeType * pValue)
	{
		NBool result;
		NCheck(NSSizeTypeTryParseN(value.GetHandle(), format.GetHandle(), pValue, &result));
		return result != 0;
	}
	static bool SSizeTypeTryParse(const NStringWrapper & value, NSSizeType * pValue) { return SSizeTypeTryParse(value, NString(), pValue); }

	static bool PointerTryParse(const NStringWrapper & value, const NStringWrapper & format, void * * pValue)
	{
		NBool result;
		NCheck(NPointerTryParseN(value.GetHandle(), format.GetHandle(), pValue, &result));
		return result != 0;
	}
	static bool PointerTryParse(const NStringWrapper & value, void * * pValue) { return PointerTryParse(value, NString(), pValue); }

#ifndef N_NO_FLOAT
	static bool SingleTryParse(const NStringWrapper & value, const NStringWrapper & format, NSingle * pValue)
	{
		NBool result;
		NCheck(NSingleTryParseN(value.GetHandle(), format.GetHandle(), pValue, &result));
		return result != 0;
	}
	static bool SingleTryParse(const NStringWrapper & value, NSingle * pValue) { return SingleTryParse(value, NString(), pValue); }

	static bool DoubleTryParse(const NStringWrapper & value, const NStringWrapper & format, NDouble * pValue)
	{
		NBool result;
		NCheck(NDoubleTryParseN(value.GetHandle(), format.GetHandle(), pValue, &result));
		return result != 0;
	}
	static bool DoubleTryParse(const NStringWrapper & value, NDouble * pValue) { return DoubleTryParse(value, NString(), pValue); }
#endif // !N_NO_FLOAT

	static bool BooleanTryParse(const NStringWrapper & value, const NStringWrapper & format, NBoolean * pValue)
	{
		NBool result;
		NCheck(NBooleanTryParseN(value.GetHandle(), format.GetHandle(), pValue, &result));
		return result != 0;
	}
	static bool BooleanTryParse(const NStringWrapper & value, NBoolean * pValue) { return BooleanTryParse(value, NString(), pValue); }

	static NChar CharParse(const NChar * arValue, NInt valueLength, const NChar * szFormat = NULL)
	{
		NChar value;
		NCheck(NCharParseStrOrChars(arValue, valueLength, szFormat, &value));
		return value;
	}

	static NUInt8 UInt8Parse(const NChar * arValue, NInt valueLength, const NChar * szFormat = NULL)
	{
		NUInt8 value;
		NCheck(NUInt8ParseStrOrChars(arValue, valueLength, szFormat, &value));
		return value;
	}

	static NInt8 Int8Parse(const NChar * arValue, NInt valueLength, const NChar * szFormat = NULL)
	{
		NInt8 value;
		NCheck(NInt8ParseStrOrChars(arValue, valueLength, szFormat, &value));
		return value;
	}

	static NUInt16 UInt16Parse(const NChar * arValue, NInt valueLength, const NChar * szFormat = NULL)
	{
		NUInt16 value;
		NCheck(NUInt16ParseStrOrChars(arValue, valueLength, szFormat, &value));
		return value;
	}

	static NInt16 Int16Parse(const NChar * arValue, NInt valueLength, const NChar * szFormat = NULL)
	{
		NInt16 value;
		NCheck(NInt16ParseStrOrChars(arValue, valueLength, szFormat, &value));
		return value;
	}

	static NUInt32 UInt32Parse(const NChar * arValue, NInt valueLength, const NChar * szFormat = NULL)
	{
		NUInt32 value;
		NCheck(NUInt32ParseStrOrChars(arValue, valueLength, szFormat, &value));
		return value;
	}

	static NInt32 Int32Parse(const NChar * arValue, NInt valueLength, const NChar * szFormat = NULL)
	{
		NInt32 value;
		NCheck(NInt32ParseStrOrChars(arValue, valueLength, szFormat, &value));
		return value;
	}

#ifndef N_NO_INT_64
	static NUInt64 UInt64Parse(const NChar * arValue, NInt valueLength, const NChar * szFormat = NULL)
	{
		NUInt64 value;
		NCheck(NUInt64ParseStrOrChars(arValue, valueLength, szFormat, &value));
		return value;
	}

	static NInt64 Int64Parse(const NChar * arValue, NInt valueLength, const NChar * szFormat = NULL)
	{
		NInt64 value;
		NCheck(NInt64ParseStrOrChars(arValue, valueLength, szFormat, &value));
		return value;
	}
#endif // !N_NO_INT_64

	static NSizeType SizeTypeParse(const NChar * arValue, NInt valueLength, const NChar * szFormat = NULL)
	{
		NSizeType value;
		NCheck(NSizeTypeParseStrOrChars(arValue, valueLength, szFormat, &value));
		return value;
	}

	static NSSizeType SSizeTypeParse(const NChar * arValue, NInt valueLength, const NChar * szFormat = NULL)
	{
		NSSizeType value;
		NCheck(NSSizeTypeParseStrOrChars(arValue, valueLength, szFormat, &value));
		return value;
	}

	static void * PointerParse(const NChar * arValue, NInt valueLength, const NChar * szFormat = NULL)
	{
		void * value;
		NCheck(NPointerParseStrOrChars(arValue, valueLength, szFormat, &value));
		return value;
	}

#ifndef N_NO_FLOAT
	static NSingle SingleParse(const NChar * arValue, NInt valueLength, const NChar * szFormat = NULL)
	{
		NSingle value;
		NCheck(NSingleParseStrOrChars(arValue, valueLength, szFormat, &value));
		return value;
	}

	static NDouble DoubleParse(const NChar * arValue, NInt valueLength, const NChar * szFormat = NULL)
	{
		NDouble value;
		NCheck(NDoubleParseStrOrChars(arValue, valueLength, szFormat, &value));
		return value;
	}
#endif // !N_NO_FLOAT

	static NBoolean BooleanParse(const NChar * arValue, NInt valueLength, const NChar * szFormat = NULL)
	{
		NBoolean value;
		NCheck(NBooleanParseStrOrChars(arValue, valueLength, szFormat, &value));
		return value;
	}

	static NChar CharParse(const NStringWrapper & value, const NStringWrapper & format = NString())
	{
		NChar result;
		NCheck(NCharParseN(value.GetHandle(), format.GetHandle(), &result));
		return result;
	}

	static NUInt8 UInt8Parse(const NStringWrapper & value, const NStringWrapper & format = NString())
	{
		NUInt8 result;
		NCheck(NUInt8ParseN(value.GetHandle(), format.GetHandle(), &result));
		return result;
	}

	static NInt8 Int8Parse(const NStringWrapper & value, const NStringWrapper & format = NString())
	{
		NInt8 result;
		NCheck(NInt8ParseN(value.GetHandle(), format.GetHandle(), &result));
		return result;
	}

	static NUInt16 UInt16Parse(const NStringWrapper & value, const NStringWrapper & format = NString())
	{
		NUInt16 result;
		NCheck(NUInt16ParseN(value.GetHandle(), format.GetHandle(), &result));
		return result;
	}

	static NInt16 Int16Parse(const NStringWrapper & value, const NStringWrapper & format = NString())
	{
		NInt16 result;
		NCheck(NInt16ParseN(value.GetHandle(), format.GetHandle(), &result));
		return result;
	}

	static NUInt32 UInt32Parse(const NStringWrapper & value, const NStringWrapper & format = NString())
	{
		NUInt32 result;
		NCheck(NUInt32ParseN(value.GetHandle(), format.GetHandle(), &result));
		return result;
	}

	static NInt32 Int32Parse(const NStringWrapper & value, const NStringWrapper & format = NString())
	{
		NInt32 result;
		NCheck(NInt32ParseN(value.GetHandle(), format.GetHandle(), &result));
		return result;
	}

#ifndef N_NO_INT_64
	static NUInt64 UInt64Parse(const NStringWrapper & value, const NStringWrapper & format = NString())
	{
		NUInt64 result;
		NCheck(NUInt64ParseN(value.GetHandle(), format.GetHandle(), &result));
		return result;
	}

	static NInt64 Int64Parse(const NStringWrapper & value, const NStringWrapper & format = NString())
	{
		NInt64 result;
		NCheck(NInt64ParseN(value.GetHandle(), format.GetHandle(), &result));
		return result;
	}
#endif // !N_NO_INT_64

	static NSizeType SizeTypeParse(const NStringWrapper & value, const NStringWrapper & format = NString())
	{
		NSizeType result;
		NCheck(NSizeTypeParseN(value.GetHandle(), format.GetHandle(), &result));
		return result;
	}

	static NSSizeType SSizeTypeParse(const NStringWrapper & value, const NStringWrapper & format = NString())
	{
		NSSizeType result;
		NCheck(NSSizeTypeParseN(value.GetHandle(), format.GetHandle(), &result));
		return result;
	}

	static void * PointerParse(const NStringWrapper & value, const NStringWrapper & format = NString())
	{
		void * result;
		NCheck(NPointerParseN(value.GetHandle(), format.GetHandle(), &result));
		return result;
	}

#ifndef N_NO_FLOAT
	static NSingle SingleParse(const NStringWrapper & value, const NStringWrapper & format = NString())
	{
		NSingle result;
		NCheck(NSingleParseN(value.GetHandle(), format.GetHandle(), &result));
		return result;
	}

	static NDouble DoubleParse(const NStringWrapper & value, const NStringWrapper & format = NString())
	{
		NDouble result;
		NCheck(NDoubleParseN(value.GetHandle(), format.GetHandle(), &result));
		return result;
	}
#endif // !N_NO_FLOAT

	static NBoolean BooleanParse(const NStringWrapper & value, const NStringWrapper & format = NString())
	{
		NBoolean result;
		NCheck(NBooleanParseN(value.GetHandle(), format.GetHandle(), &result));
		return result;
	}

	static NOSFamily GetOSFamilyCurrent()
	{
		return NOSFamilyGetCurrent();
	}

	friend class NValue;
	friend class NArray;
	friend class IO::NBuffer;
};

#include <Core/NNoDeprecate.h>
template<typename T>
class NCollectionItemWrapper
{
private:
	NByte itemData[sizeof(T)];
	bool containsItem;

	T * GetItemPtr()
	{
		return reinterpret_cast<T *>(itemData);
	}

public:
	NCollectionItemWrapper()
		: containsItem(false)
	{
	}

	NCollectionItemWrapper(const NCollectionItemWrapper & other)
		: containsItem(false)
	{
		Set(other.Get());
	}

	NCollectionItemWrapper& operator=(const NCollectionItemWrapper & other)
	{
		Set(other.Get());
		return *this;
	}

	~NCollectionItemWrapper()
	{
		Set((const T *)NULL);
	}

	T * Get()
	{
		return containsItem ? GetItemPtr() : NULL;
	}

	const T * Get() const
	{
		return containsItem ? reinterpret_cast<const T *>(itemData) : NULL;
	}

	void Set(const T * pValue)
	{
		if (containsItem)
		{
			GetItemPtr()->~T();
			containsItem = false;
		}
		if (pValue)
		{
			new (GetItemPtr()) T(*pValue);
			containsItem = true;
		}
	}

	void Set(const T & value)
	{
		Set(&value);
	}
};

template<typename TCollection, typename TElement>
class NCollectionIterator : public std::iterator<std::input_iterator_tag, TElement>
{
private:
	const TCollection & collection;
	NCollectionItemWrapper<TElement> currentItem;
	bool reverse;
	NInt index;
	NInt count;

public:
	NCollectionIterator(const TCollection & collection, NInt index, bool reverse = false)
		: collection(collection), reverse(reverse), index(index), count(collection.GetCount())
	{
	}

	NCollectionIterator()
		: collection(), reverse(false), index(), count()
	{
	}

	NCollectionIterator & operator++()
	{
		if (reverse) index--;
		else index++;
		return *this;
	}

	NCollectionIterator & operator++(int)
	{
		if (reverse) index--;
		else index++;
		return *this;
	}

	NCollectionIterator & operator--()
	{
		if (reverse) index++;
		else index--;
		return *this;
	}

	NCollectionIterator & operator--(int)
	{
		if (reverse) index++;
		else index--;
		return *this;
	}

	TElement operator*() const
	{
		return collection.Get(index);
	}

	TElement * operator->()
	{
		currentItem.Set(collection.Get(index));
		return currentItem.Get();
	}

	bool operator==(const NCollectionIterator & value) const
	{
		return index == value.index;
	}

	bool operator!=(const NCollectionIterator & value) const
	{
		return index != value.index;
	}

	bool operator>(const NCollectionIterator & value) const
	{
		return index > value.index;
	}

	bool operator>=(const NCollectionIterator & value) const
	{
		return index >= value.index;
	}

	bool operator<(const NCollectionIterator & value) const
	{
		return index < value.index;
	}

	bool operator<=(const NCollectionIterator & value) const
	{
		return index <= value.index;
	}

	NCollectionIterator & operator=(const NCollectionIterator & value)
	{
		index = value.index;
		return *this;
	}
};

template<typename TCollection, typename TElement>
class NConstCollectionIterator : public NCollectionIterator<TCollection, TElement>
{
public:
	NConstCollectionIterator(const TCollection & collection, NInt index, bool reverse = false)
		: NCollectionIterator<TCollection, TElement>(collection, index, reverse)
	{
	}

	NConstCollectionIterator()
	{
	}

	const TElement operator*() const
	{
		return NCollectionIterator<TCollection, TElement>::operator*();
	}

	const TElement * operator->()
	{
		return NCollectionIterator<TCollection, TElement>::operator->();
	}
};

template<typename T> class NArrayWrapper
{
public:
	typedef T value_type;
	typedef NCollectionIterator<NArrayWrapper, T> iterator;
	typedef NConstCollectionIterator<NArrayWrapper, T> const_iterator;
	typedef NCollectionIterator<NArrayWrapper, T> reverse_iterator;
	typedef NConstCollectionIterator<NArrayWrapper, T> reverse_const_iterator;

private:
	typedef typename NTypeTraits<T>::NativeType THandle;

	THandle * arNativeValues;
	NInt count;
	bool ownsHandles;
	bool ownsPtr;

	static THandle * Alloc(NInt count)
	{
		if (count == 0) return NULL;
		if (count < 0) NThrowArgumentLessThanZeroException(N_T("count"));
		if (N_SIZE_TYPE_MAX / sizeof(THandle) < (NSizeType)count) NThrowOverflowException();
		return reinterpret_cast<THandle *>(NCAlloc((NSizeType)count * sizeof(THandle)));
	}

	void ClearInternal()
	{
		if (ownsHandles)
		{
			for (int i = 0; i < count; i++)
				NTypeTraits<T>::FreeNative(arNativeValues[i]);
		}
		if (ownsPtr) NFree(arNativeValues);
	}

public:
	explicit NArrayWrapper(NInt count, bool ownsHandles = true)
		: arNativeValues(Alloc(count)), count(count), ownsHandles(ownsHandles), ownsPtr(true)
	{
	}

	NArrayWrapper(THandle * arNativeValues, NInt count, bool ownsHandles = true, bool ownsPtr = true)
		: arNativeValues(arNativeValues), count(count), ownsHandles(ownsHandles), ownsPtr(ownsPtr)
	{
	}

	template<typename InputIt>
	NArrayWrapper(InputIt first, InputIt last)
		: arNativeValues(NULL), count(0), ownsHandles(true), ownsPtr(true)
	{
		NInt allocatedCount = 0;
		for (; first != last; ++first)
		{
			if (allocatedCount <= count)
			{
				NInt newCount = count == 0 ? 16 : count * 3 / 2;
				NSizeType newSize = (NSizeType)newCount * sizeof(THandle);
				arNativeValues = reinterpret_cast<THandle *>(NReAlloc(arNativeValues, newSize));
				allocatedCount = newCount;
			}
			memset(&arNativeValues[count], 0, sizeof(arNativeValues[0]));
			NTypeTraits<T>::SetNative(NTypeTraits<T>::ToNative(*first), &arNativeValues[count]);
			count++;
		}
	}

	NArrayWrapper(const NArrayWrapper<T> & other)
	{
		this->count = other.count;
		this->ownsHandles = other.ownsHandles;
		this->ownsPtr = other.ownsPtr;
		if (other.ownsPtr)
		{
			arNativeValues = Alloc(other.count);
			if (other.ownsHandles)
			{
				for (int i = 0; i < count; i++)
				{
					NTypeTraits<T>::SetNative(other.arNativeValues[i], &arNativeValues[i]);
				}
			}
			else
			{
				memcpy(arNativeValues, other.arNativeValues, sizeof(other.arNativeValues[0]) * count);
			}
		}
		else
		{
			arNativeValues = other.arNativeValues;
		}
	}

#ifdef N_CPP11
	NArrayWrapper(NArrayWrapper<T> && other)
		: arNativeValues(other.arNativeValues), count(other.count), ownsHandles(other.ownsHandles), ownsPtr(other.ownsPtr)
	{
		other.arNativeValues = NULL;
		other.count = 0;
		other.ownsHandles = false;
		other.ownsPtr = false;
	}
#endif

	NArrayWrapper<T>& operator=(NArrayWrapper<T> other)
	{
		std::swap(arNativeValues, other.arNativeValues);
		std::swap(count, other.count);
		std::swap(ownsHandles, other.ownsHandles);
		std::swap(ownsPtr, other.ownsPtr);
		return *this;
	}

	~NArrayWrapper()
	{
		ClearInternal();
	}

	void SetCount(int value)
	{
		if (ownsHandles)
		{
			for (int i = value; i < count; i++)
				NTypeTraits<T>::FreeNative(arNativeValues[i]);
		}
		count = value;
	}

	int GetCount() const
	{
		return count;
	}

	const THandle * GetPtr() const
	{
		return arNativeValues;
	}

	THandle * GetPtr()
	{
		return arNativeValues;
	}

	THandle * Release(NInt * pCount = NULL)
	{
		THandle * ptr = arNativeValues;
		if (pCount) *pCount = count;
		arNativeValues = NULL;
		count = 0;
		return ptr;
	}

	T Get(int index) const
	{
		if (index < 0
			|| index >= count) NThrowArgumentOutOfRangeException(N_T("index"));
		return NTypeTraits<T>::FromNative(arNativeValues[index], false);
	}

	T operator[](int index) const
	{
		return NTypeTraits<T>::FromNative(arNativeValues[index], false);
	}

	/*
	T * ToArray(NInt * pCount = NULL)
	{
		return ToArray(count, pCount);
	}

	T * ToArray(NInt realCount, NInt * pCount = NULL)
	{
		if (realCount < 0) NThrowArgumentLessThanZeroException(N_T("realCount"));
		auto_array<T> pObjects(realCount);
		CopyTo(pObjects.get(), realCount, realCount);
		if (pCount) *pCount = realCount;
		return pObjects.release();
	}
	*/

	NInt CopyTo(T * arpValues, NInt valuesLength)
	{
		return CopyTo(arpValues, valuesLength, count);
	}

	NInt CopyTo(T * arpValues, NInt valuesLength, NInt realCount) const
	{
		if (!arpValues && valuesLength != 0) NThrowArgumentNullException(N_T("arpValues"));
		if (valuesLength < 0) NThrowArgumentLessThanZeroException(N_T("valuesLength"));
		if (valuesLength < realCount) NThrowArgumentInsufficientException(N_T("valuesLength"));
		if (realCount < 0) NThrowArgumentLessThanZeroException(N_T("realCount"));
		if (realCount > count) NThrowArgumentException(N_T("realCount is greater than count"));
		const THandle * phObject = arNativeValues;
		T * pObject = arpValues;
		NInt i = 0;
		for (; i < realCount; i++, phObject++, pObject++)
		{
			THandle hObject = *phObject;
			*pObject = NTypeTraits<T>::FromNative(hObject, false);
		}
		return realCount;
	}

	iterator begin()
	{
		return iterator(*this, 0);
	}

	const_iterator begin() const
	{
		return const_iterator(*this, 0);
	}

	iterator end()
	{
		return iterator(*this, GetCount());
	}

	const_iterator end() const
	{
		return const_iterator(*this, GetCount());
	}

	reverse_iterator rbegin()
	{
		return reverse_iterator(*this, GetCount() - 1, true);
	}

	reverse_const_iterator rbegin() const
	{
		return reverse_const_iterator(*this, GetCount() - 1, true);
	}

	reverse_iterator rend()
	{
		return reverse_iterator(*this, 0, true);
	}

	reverse_const_iterator rend() const
	{
		return reverse_const_iterator(*this, 0, true);
	}
};
#include <Core/NReDeprecate.h>

}

#ifdef N_NEED_HASH
	N_HASH_NAMESPACE_BEGIN
		template<> struct hash< ::Neurotec::NTypes::CallbackParam>
		{
			size_t operator()(::Neurotec::NTypes::CallbackParam const & k) const
			{
				return (size_t)k;
			}
		};
	N_HASH_NAMESPACE_END
#endif

#include <Core/NType.hpp>

N_DEFINE_ENUM_TYPE_TRAITS(Neurotec, NAttributes)
N_DEFINE_ENUM_TYPE_TRAITS(Neurotec, NOSFamily)
N_DEFINE_ENUM_TYPE_TRAITS(Neurotec, NMemoryType)

namespace Neurotec
{
template<typename T, bool IsNObject> inline NType NTypeTraitsBase<T, IsNObject>::GetNativeType()
{
	return T::NativeTypeOf();
}

inline NResult N_API NTypes::OnCallbackFree(void * ptr, void *)
{
	delete reinterpret_cast<CallbackParam *>(ptr);
	return N_OK;
}

inline NResult N_API NTypes::OnCallbackGetHashCode(void * ptr, NInt * pValue, void *)
{
	NResult result = N_OK;
	try
	{
		if (!pValue) NThrowArgumentNullException(N_T("pValue"));
		size_t hashCode = (size_t)*reinterpret_cast<CallbackParam *>(ptr);
	#ifdef N_64
		*pValue = (NInt)((hashCode >> 32) ^ (hashCode & 0xFFFFFFFF));
	#else
		*pValue = (NInt)hashCode;
	#endif
	}
	N_EXCEPTION_CATCH_AND_SET_LAST(result);
	return result;
}

inline NResult N_API NTypes::OnCallbackEquals(void * ptr, void * otherPtr, NBool * pResult, void *)
{
	NResult result = N_OK;
	try
	{
		if (!pResult) NThrowArgumentNullException(N_T("pResult"));
		*pResult = *reinterpret_cast<CallbackParam *>(ptr) == *reinterpret_cast<CallbackParam *>(otherPtr);
	}
	N_EXCEPTION_CATCH_AND_SET_LAST(result);
	return result;
}

template<typename T>
inline NResult N_API NTypes::OnCallbackWrapperFree(void * ptr, void *)
{
	delete reinterpret_cast<T *>(ptr);
	return N_OK;
}

inline NResult N_API NTypes::PointerFreeProcImpl(void * ptr, void * pParam)
{
	NResult result = N_OK;
	try
	{
		CallbackParam * p = reinterpret_cast<CallbackParam *>(pParam);
		reinterpret_cast<PointerFreeProc>(p->GetCallback())(ptr, p->GetCallbackParam());
	}
	N_EXCEPTION_CATCH_AND_SET_LAST(result);
	return result;
}

inline NResult N_API NTypes::PointerGetHashCodeImpl(void * ptr, NInt * pValue, void * pParam)
{
	NResult result = N_OK;
	try
	{
		if (!pValue) NThrowArgumentNullException(N_T("pValue"));
		CallbackParam * p = reinterpret_cast<CallbackParam *>(pParam);
		*pValue = reinterpret_cast<PointerGetHashCodeProc>(p->GetCallback())(ptr, p->GetCallbackParam());
	}
	N_EXCEPTION_CATCH_AND_SET_LAST(result);
	return result;
}

inline NResult N_API NTypes::PointerEqualsImpl(void * ptr, void * otherPtr, NBool * pResult, void * pParam)
{
	NResult result = N_OK;
	try
	{
		if (!pResult) NThrowArgumentNullException(N_T("pResult"));
		CallbackParam * p = reinterpret_cast<CallbackParam *>(pParam);
		*pResult = reinterpret_cast<PointerEqualsProc>(p->GetCallback())(ptr, otherPtr, p->GetCallbackParam());
	}
	N_EXCEPTION_CATCH_AND_SET_LAST(result);
	return result;
}

inline NCallback::NCallback(void * pProc, const NObject & object)
	: handle(NULL)
{
	NCheck(NCallbackCreateWithObjectRaw(pProc, object.GetHandle(), &handle));
}

template<typename T> inline NCallback::NCallback(T pProc, const NObject & object)
	: handle(NULL)
{
	NCheck(NCallbackCreateWithObject(pProc, object.GetHandle(), &handle));
}


class NGuid : public NGuid_
{
	N_DECLARE_STRUCT_CLASS(NGuid)

public:
	static bool TryParse(const NStringWrapper & value, const NStringWrapper & format, NGuid * pValue)
	{
		NBool result;
		NCheck(NGuidTryParseN(value.GetHandle(), format.GetHandle(), pValue, &result));
		return result != 0;
	}
	static bool TryParse(const NStringWrapper & value, NGuid * pValue) { return TryParse(value, NString(), pValue); }

	static NGuid Parse(const NStringWrapper & value, const NStringWrapper & format = NString())
	{
		NGuid theValue;
		NCheck(NGuidParseN(value.GetHandle(), format.GetHandle(), &theValue));
		return theValue;
	}

	NString ToString(const NStringWrapper & format = NString()) const
	{
		HNString hValue;
		NCheck(NGuidToStringN(this, format.GetHandle(), &hValue));
		return NString(hValue, true);
	}
};

class NURational : public NURational_
{
	N_DECLARE_STRUCT_CLASS(NURational)

public:
	NURational(NUInt numerator, NUInt denominator)
	{
		Numerator = numerator;
		Denominator = denominator;
	}

	NString ToString(const NStringWrapper & format = NString()) const
	{
		HNString hValue;
		NCheck(NURationalToStringN(this, format.GetHandle(), &hValue));
		return NString(hValue, true);
	}
};

class NRational : public NRational_
{
	N_DECLARE_STRUCT_CLASS(NRational)

public:
	NRational(NInt numerator, NInt denominator)
	{
		Numerator = numerator;
		Denominator = denominator;
	}

	NString ToString(const NStringWrapper & format = NString()) const
	{
		HNString hValue;
		NCheck(NRationalToStringN(this, format.GetHandle(), &hValue));
		return NString(hValue, true);
	}
};

class NComplex : public NComplex_
{
	N_DECLARE_STRUCT_CLASS(NComplex)

public:
	NComplex(NDouble real, NDouble imaginary)
	{
		Real = real;
		Imaginary = imaginary;
	}

	NString ToString(const NStringWrapper & format = NString()) const
	{
		HNString hValue;
		NCheck(NComplexToStringN(this, format.GetHandle(), &hValue));
		return NString(hValue, true);
	}
};

class NIndexPair : public NIndexPair_
{
	N_DECLARE_STRUCT_CLASS(NIndexPair)

public:
	NIndexPair(NInt index1, NInt index2)
	{
		Index1 = index1;
		Index2 = index2;
	}

	NString ToString(const NStringWrapper & format = NString()) const
	{
		HNString hValue;
		NCheck(NIndexPairToStringN(this, format.GetHandle(), &hValue));
		return NString(hValue, true);
	}
};

class NRange : public NRange_
{
	N_DECLARE_STRUCT_CLASS(NRange)

public:
	NRange(NInt from, NInt to)
	{
		From = from;
		To = to;
	}

	NString ToString(const NStringWrapper & format = NString()) const
	{
		HNString hValue;
		NCheck(NRangeToStringN(this, format.GetHandle(), &hValue));
		return NString(hValue, true);
	}
};

class NVersion
{
	N_DECLARE_COMPARABLE_BASIC_CLASS(NVersion)

public:
	NVersion(NInt major, NInt minor)
		: value(NVersionMake(major, minor))
	{
		if (major < N_BYTE_MIN || major > N_BYTE_MAX) NThrowArgumentOutOfRangeException(N_T("major"));
		if (minor < N_BYTE_MIN || minor > N_BYTE_MAX) NThrowArgumentOutOfRangeException(N_T("minor"));
	}

	NString ToString(const NStringWrapper & format = NString()) const
	{
		HNString hValue;
		NCheck(NVersionToStringN(value, format.GetHandle(), &hValue));
		return NString(hValue, true);
	}

	NInt GetMajor() const
	{
		return NVersionGetMajor(value);
	}

	NInt GetMinor() const
	{
		return NVersionGetMinor(value);
	}
};

class NVersionRange
{
	N_DECLARE_BASIC_CLASS(NVersionRange)

public:
	static NVersionRange Intersect(const NVersionRange & value1, const NVersionRange & value2)
	{
		return NVersionRange(NVersionRangeIntersect(value1.value, value2.value));
	}

	NVersionRange(const NVersion & from, const NVersion & to)
		: value(NVersionRangeMake(from.GetValue(), to.GetValue()))
	{
	}

	NString ToString(const NStringWrapper & format = NString()) const
	{
		HNString hValue;
		NCheck(NVersionRangeToStringN(value, format.GetHandle(), &hValue));
		return NString(hValue, true);
	}

	bool Contains(const NVersion & value) const
	{
		return NVersionRangeContains(this->value, value.GetValue()) != 0;
	}

	bool Contains(const NVersionRange & value) const
	{
		return NVersionRangeContainsRange(this->value, value.value) != 0;
	}

	bool IntersectsWith(const NVersionRange & value) const
	{
		return NVersionRangeIntersectsWith(this->value, value.value) != 0;
	}

	NVersionRange Intersect(const NVersionRange & value) const
	{
		return Intersect(*this, value);
	}

	NVersion GetFrom() const
	{
		return NVersion(NVersionRangeGetFrom(value));
	}

	NVersion GetTo() const
	{
		return NVersion(NVersionRangeGetTo(value));
	}
};

class NNameStringPair : public NNameStringPair_
{
	N_DECLARE_EQUATABLE_DISPOSABLE_STRUCT_CLASS(NNameStringPair)

public:
	NNameStringPair(const NStringWrapper & key, const NStringWrapper & value)
	{
		NCheck(NNameStringPairCreateN(key.GetHandle(), value.GetHandle(), this));
	}

	NString GetKey() const
	{
		return NString(hKey, false);
	}

	void SetName(const NStringWrapper & value)
	{
		NCheck(NStringSet(value.GetHandle(), &hKey));
	}

	NString GetValue() const
	{
		return NString(hValue, false);
	}

	void SetValue(const NStringWrapper & value)
	{
		NCheck(NStringSet(value.GetHandle(), &hValue));
	}
};

inline NType NTypes::NUInt8NativeTypeOf()
{
	return NObject::GetObject<NType>(N_TYPE_OF(NUInt8), true);
}

inline NType NTypes::NInt8NativeTypeOf()
{
	return NObject::GetObject<NType>(N_TYPE_OF(NInt8), true);
}

inline NType NTypes::NUInt16NativeTypeOf()
{
	return NObject::GetObject<NType>(N_TYPE_OF(NUInt16), true);
}

inline NType NTypes::NInt16NativeTypeOf()
{
	return NObject::GetObject<NType>(N_TYPE_OF(NInt16), true);
}

inline NType NTypes::NUInt32NativeTypeOf()
{
	return NObject::GetObject<NType>(N_TYPE_OF(NUInt32), true);
}

inline NType NTypes::NInt32NativeTypeOf()
{
	return NObject::GetObject<NType>(N_TYPE_OF(NInt32), true);
}

inline NType NTypes::NUInt64NativeTypeOf()
{
	return NObject::GetObject<NType>(N_TYPE_OF(NUInt64), true);
}

inline NType NTypes::NInt64NativeTypeOf()
{
	return NObject::GetObject<NType>(N_TYPE_OF(NInt64), true);
}

inline NType NTypes::NSingleNativeTypeOf()
{
	return NObject::GetObject<NType>(N_TYPE_OF(NSingle), true);
}

inline NType NTypes::NDoubleNativeTypeOf()
{
	return NObject::GetObject<NType>(N_TYPE_OF(NDouble), true);
}

inline NType NTypes::NBooleanNativeTypeOf()
{
	return NObject::GetObject<NType>(N_TYPE_OF(NBoolean), true);
}

inline NType NTypes::NSizeTypeNativeTypeOf()
{
	return NObject::GetObject<NType>(N_TYPE_OF(NSizeType), true);
}

inline NType NTypes::NSSizeTypeNativeTypeOf()
{
	return NObject::GetObject<NType>(N_TYPE_OF(NSSizeType), true);
}

inline NType NTypes::NPointerNativeTypeOf()
{
	return NObject::GetObject<NType>(N_TYPE_OF(NPointer), true);
}

inline NType NTypes::NResultNativeTypeOf()
{
	return NObject::GetObject<NType>(N_TYPE_OF(NResult), true);
}

inline NType NTypes::NACharNativeTypeOf()
{
	return NObject::GetObject<NType>(N_TYPE_OF(NAChar), true);
}

#ifndef N_NO_UNICODE
inline NType NTypes::NWCharNativeTypeOf()
{
	return NObject::GetObject<NType>(N_TYPE_OF(NAChar), true);
}
#endif

inline NType NTypes::NCharNativeTypeOf()
{
	return NObject::GetObject<NType>(N_TYPE_OF(NChar), true);
}

inline NType NTypes::NStringNativeTypeOf()
{
	return NObject::GetObject<NType>(N_TYPE_OF(NString), true);
}

inline NType NTypes::NCallbackNativeTypeOf()
{
	return NObject::GetObject<NType>(N_TYPE_OF(NCallback), true);
}

inline NType NTypes::NMemoryTypeNativeTypeOf()
{
	return NObject::GetObject<NType>(N_TYPE_OF(NMemoryType), true);
}

inline NType NTypes::NAttributesNativeTypeOf()
{
	return NObject::GetObject<NType>(N_TYPE_OF(NAttributes), true);
}

inline NType NTypes::NOSFamilyNativeTypeOf()
{
	return NObject::GetObject<NType>(N_TYPE_OF(NOSFamily), true);
}

inline NType NTypes::NativeTypeOf()
{
	return NObject::GetObject<NType>(N_TYPE_OF(NTypes), true);
}

}

N_DEFINE_DISPOSABLE_STRUCT_TYPE_TRAITS(Neurotec, NNameStringPair);


#endif // !N_TYPES_HPP_INCLUDED
