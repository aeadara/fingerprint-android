#ifndef N_DEFS_H_INCLUDED
#define N_DEFS_H_INCLUDED

#ifdef N_DOCUMENTATION
	#define N_64
	#define N_ANSI_C
	#define N_BIG_ENDIAN
	#define N_CPP
	#define N_DEBUG
	#define N_SLOW_FLOAT
	#define N_GCC
	#define N_CLANG
	#define N_LIB
	#define N_LINUX
	#define N_MAC
	#define N_MSVC
	#define N_NO_ANSI_FUNC
	#define N_NO_INT_64
	#define N_UNICODE
	#define N_WINDOWS
#endif

#ifdef __cplusplus
	#define N_CPP
#endif

#ifdef _DEBUG
	#define N_DEBUG
#endif

#ifndef N_NO_TRACE
	#define N_TRACE
#endif

#ifdef _LIB
	#define N_LIB
#endif

#if defined(N_LIB) && defined(N_EXE)
	#error N_LIB and N_EXE defined simultaneously
#endif

#if defined(_WIN32) || defined(WIN32) || defined(_WIN64) || defined(WIN64)
	#define N_WINDOWS
	#ifdef WINAPI_FAMILY
		#if WINAPI_FAMILY == WINAPI_FAMILY_APP
			#define N_WINDOWS_STORE
		#endif
	#endif
#endif

#ifdef WINCE
	#define N_WINDOWS_CE
#endif

#ifdef __linux__
	#define N_LINUX
#endif

#ifdef __QNX__
	#define N_QNX
#endif

#if defined(__APPLE__) && defined(__MACH__)
	#define N_APPLE
	#if defined(__ENVIRONMENT_MAC_OS_X_VERSION_MIN_REQUIRED__)
		#define N_MAC
	#elif defined(__ENVIRONMENT_IPHONE_OS_VERSION_MIN_REQUIRED__)
		#define N_IOS
	#else
		#error Unknown APPLE OS
	#endif
#endif

#ifdef _AIX
	#define N_AIX
#endif

#ifdef ANDROID
	#define N_ANDROID
#endif

#ifndef N_WINDOWS
	#define N_NO_UNICODE
#endif

#if defined(N_WINDOWS) && (defined(_UNICODE) || defined(UNICODE))
	#define N_UNICODE
#endif

#if defined(N_NO_UNICODE) && defined(N_UNICODE)
	#error "N_NO_UNICODE and N_UNICODE defined simultaneously"
#endif

#ifdef N_WINDOWS_CE
	#define N_NO_ANSI_FUNC
	#ifndef N_UNICODE
		#error "N_UNICODE must be defined under Windows CE"
	#endif
#endif

#if defined(N_NO_ANSI_FUNC) && !defined(N_UNICODE)
	#error "N_NO_ANSI_FUNC defined when N_UNICODE is not defined"
#endif

#ifdef _MSC_VER
	#if (_MSC_VER >= 1300)
		#define N_MSVC
	#else
		#define N_NO_INT_64
	#endif
#endif

#ifdef __GNUC__
	#define N_GCC
	#define N_GCC_VERSION (__GNUC__ * 10000 + __GNUC_MINOR__ * 100 + __GNUC_PATCHLEVEL__)
#endif

#ifdef __clang__
	#define N_CLANG
	#define N_CLANG_VERSION (__clang_major__ * 10000 + __clang_minor__ * 100 + __clang_patchlevel__)
#endif

#ifdef __MINGW32_VERSION
	#define N_MINGW
#endif

#if defined(__STDC__) && !defined(N_GCC) && !defined(N_CLANG)
	#define N_ANSI_C
#endif

#define N_STATIC_ASSERT(x) ((void)sizeof(char[1 - 2 * !(x)]))

#if defined(N_MSVC)
	#define N_DEPRECATED(message) __declspec(deprecated(message))
	#define N_NO_RETURN __declspec(noreturn)
	#define N_NO_INLINE __declspec(noinline)
	#define N_RETURN_ADDRESS _ReturnAddress()
	#define N_PACKED
	#define N_ALIGN(x) __declspec(align(x))
	#define N_LIKELY(x) (x)
	#define N_UNLIKELY(x) (x)
	#define N_INLINE __inline
#elif defined(N_GCC)
	#define N_DEPRECATED(message) __attribute__((deprecated))
	#define N_NO_RETURN __attribute__((noreturn))
	#define N_NO_INLINE __attribute__((noinline))
	#define N_RETURN_ADDRESS __builtin_return_address(0)
	#define N_PACKED __attribute__((__packed__))
	#define N_ALIGN(x) __attribute__((aligned (x)))
	#define N_LIKELY(x) __builtin_expect((x),1)
	#define N_UNLIKELY(x) __builtin_expect((x),0)
	#define N_INLINE inline
#else
	#define N_DEPRECATED(message)
	#define N_NO_RETURN
	#define N_NO_INLINE
	#define N_RETURN_ADDRESS NULL
	#define N_PACKED
	#define N_ALIGN(x)
	#define N_LIKELY(x) (x)
	#define N_UNLIKELY(x) (x)
	#define N_INLINE inline
#endif

#ifdef N_CPP
	#if defined(N_MSVC)
		#define N_NO_THROW __declspec(nothrow)
	#elif defined(N_GCC) || defined(N_CLANG)
		#define N_NO_THROW __attribute__ ((nothrow))
	#else
		#define N_NO_THROW
	#endif
	#define N_EXTERN_C extern "C"
#else
	#define N_NO_THROW
	#define N_EXTERN_C
#endif

#if defined(_M_IX86) || defined(__i386__)
	#define N_X86
#endif

#if defined(_M_X64) || defined(__x86_64__)
	#define N_X64
#endif

#if defined(N_X86) || defined(N_X64)
	#define N_X86_FAMILY
#endif

#if defined(_M_IA64)
	#define N_IA64
#endif

#if defined(__POWERPC__) || defined(_POWER) || defined(_ARCH_PPC)
	#define N_POWER_PC
#endif

#if defined(N_POWER_PC)
	#define N_POWER_PC_FAMILY
#endif

#if defined(N_POWER_PC_FAMILY)
	#define N_BIG_ENDIAN
#endif

#if defined(_M_ARM) ||  defined(__arm__)
	#define N_ARM
#endif

#if defined(__arm64)
	#define N_ARM64
#endif

#if defined(N_ARM) || defined(N_ARM64)
	#define N_ARM_FAMILY
#endif

#if defined(N_X64) || defined(N_IA64) || defined(N_ARM64)
	#define N_64
#endif

#if defined(N_64) && defined(N_NO_INT_64)
	#error N_64 and N_NO_INT_64 defined simultaneously
#endif

#if 0
	#define N_SLOW_FLOAT
#endif

#if defined(__ARM_NEON__) && defined(N_GCC) && !defined(N_CLANG)
	#define N_ARM_NEON
#endif

#if defined(N_WINDOWS_CE) || defined(N_ANDROID) || (defined(N_WINDOWS) && defined(N_ARM_FAMILY))
	#define N_NO_CALL_STACK
#endif

#ifndef N_CALL_CONV
	#ifdef N_WINDOWS
		#define N_CALL_CONV __stdcall
	#else
		#define N_CALL_CONV
	#endif
#endif

#define N_API N_NO_THROW N_CALL_CONV
#ifdef N_MSVC
	#define N_API_PTR_RET N_CALL_CONV
#else
	#define N_API_PTR_RET N_NO_THROW N_CALL_CONV
#endif
#define N_CALLBACK N_CALL_CONV *

#define N_EMPTY_STRINGA ""
#define N_T_A(text) text
#define N_TA(text) N_T_A(text)
#define N_STRINGIZE_A(value) N_TA(#value)
#define N_STRINGIZEA(value) N_STRINGIZE_A(value)

#ifndef N_NO_UNICODE
#define N_EMPTY_STRINGW L""
#define N_T_W(text) L##text
#define N_TW(text) N_T_W(text)
#define N_STRINGIZE_W(value) N_TW(#value)
#define N_STRINGIZEW(value) N_STRINGIZE_W(value)
#endif

#ifdef N_UNICODE
	#define N_AW W
	#define N_T_ N_T_W
	#define N_T N_TW
	#define N_EMPTY_STRING N_EMPTY_STRINGW
	#define N_STRINGIZE_ N_STRINGIZE_W
	#define N_STRINGIZE N_STRINGIZEW
#else
	#define N_AW A
	#define N_T_ N_T_A
	#define N_T N_TA
	#define N_EMPTY_STRING N_EMPTY_STRINGA
	#define N_STRINGIZE_ N_STRINGIZE_A
	#define N_STRINGIZE N_STRINGIZEA
#endif

#define N_JOIN_SYMBOLS_(name1, name2) name1##name2
#define N_JOIN_SYMBOLS(name1, name2) N_JOIN_SYMBOLS_(name1, name2)

#define N_JOIN_SYMBOLS2_(name1, name2) name1##name2
#define N_JOIN_SYMBOLS2(name1, name2) N_JOIN_SYMBOLS2_(name1, name2)

#define N_SYMBOL_AW(name) N_JOIN_SYMBOLS2(name, N_AW)

#define N_MACRO_AW(name) N_SYMBOL_AW(name)
#define N_FUNC_AW(name) N_SYMBOL_AW(name)
#define N_CALLBACK_AW(name) N_SYMBOL_AW(name)
#define N_STRUCT_AW(name) N_SYMBOL_AW(name)
#define N_VAR_AW(name) N_SYMBOL_AW(name)
#define N_FIELD_AW(name) N_SYMBOL_AW(name)
#define N_TYPE_AW(name) N_SYMBOL_AW(name)

#ifdef N_WINDOWS
	#define N_NEW_LINEA "\r\n"
	#ifndef N_NO_UNICODE
		#define N_NEW_LINEW L"\r\n"
	#endif
#else
	#define N_NEW_LINEA "\n"
	#ifndef N_NO_UNICODE
		#define N_NEW_LINEW L"\n"
	#endif
#endif
#define N_NEW_LINE N_MACRO_AW(N_NEW_LINE)

#endif // !N_DEFS_H_INCLUDED
