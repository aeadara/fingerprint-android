#include <Core/NObject.hpp>

#ifndef N_ERROR_HPP_INCLUDED
#define N_ERROR_HPP_INCLUDED

#include <Core/NTypes.hpp>
#include <Core/NMemory.hpp>
namespace Neurotec
{
#include <Core/NError.h>
}
#include <stdexcept>
#include <ios>
#include <typeinfo>
#include <string>
#if defined(N_MSVC) && !defined(N_NO_UNICODE)
	#include <Interop/NWindows.hpp>
	#include <comdef.h>
#endif
#include <Text/NStringBuilder.hpp>

namespace Neurotec
{
#undef N_OK
#undef N_E_FAILED
#undef N_E_CORE
#undef N_E_ABANDONED_MUTEX
#undef N_E_AGGREGATE
#undef N_E_ARGUMENT
#undef N_E_ARGUMENT_NULL
#undef N_E_ARGUMENT_OUT_OF_RANGE
#undef N_E_INVALID_ENUM_ARGUMENT
#undef N_E_ARITHMETIC
#undef N_E_OVERFLOW
#undef N_E_BAD_IMAGE_FORMAT
#undef N_E_DLL_NOT_FOUND
#undef N_E_ENTRY_POINT_NOT_FOUND
#undef N_E_FORMAT
#undef N_E_FILE_FORMAT
#undef N_E_INDEX_OUT_OF_RANGE
#undef N_E_INVALID_CAST
#undef N_E_INVALID_OPERATION
#undef N_E_IO
#undef N_E_DIRECTORY_NOT_FOUND
#undef N_E_DRIVE_NOT_FOUND
#undef N_E_END_OF_STREAM
#undef N_E_FILE_NOT_FOUND
#undef N_E_FILE_LOAD
#undef N_E_PATH_TOO_LONG
#undef N_E_SOCKET
#undef N_E_KEY_NOT_FOUND
#undef N_E_NOT_IMPLEMENTED
#undef N_E_NOT_SUPPORTED
#undef N_E_NULL_REFERENCE
#undef N_E_OPERATION_CANCELED
#undef N_E_OUT_OF_MEMORY
#undef N_E_SECURITY
#undef N_E_TIMEOUT
#undef N_E_EXTERNAL
#undef N_E_CLR
#undef N_E_COM
#undef N_E_CPP
#undef N_E_JVM
#undef N_E_MAC
#undef N_E_SYS
#undef N_E_WIN32
#undef N_E_PARAMETER
#undef N_E_PARAMETER_READ_ONLY
#undef N_E_NOT_ACTIVATED

#undef NFailed
#undef NSucceeded

#undef NE_PRESERVE_INNER_ERROR
#undef NE_NO_CALL_STACK
#undef NE_MERGE_CALL_STACK
#undef NE_IS_DIRECTORY_ACCESS
#undef NE_SKIP_ONE_FRAME

const NResult N_OK                            =   0;
const NResult N_E_FAILED                      =  -1;
  const NResult N_E_CORE                      =  -2;
    const NResult N_E_ABANDONED_MUTEX         = -25;
    const NResult N_E_AGGREGATE               = -33;
    const NResult N_E_ARGUMENT                = -10;
      const NResult N_E_ARGUMENT_NULL         = -11;
      const NResult N_E_ARGUMENT_OUT_OF_RANGE = -12;
      const NResult N_E_INVALID_ENUM_ARGUMENT = -16;
    const NResult N_E_ARITHMETIC              = -17;
      const NResult N_E_OVERFLOW              =  -8;
    const NResult N_E_BAD_IMAGE_FORMAT        = -26;
    const NResult N_E_DLL_NOT_FOUND           = -27;
    const NResult N_E_ENTRY_POINT_NOT_FOUND   = -28;
    const NResult N_E_FORMAT                  = -13;
      const NResult N_E_FILE_FORMAT           = -29;
    const NResult N_E_INDEX_OUT_OF_RANGE      =  -9;
    const NResult N_E_INVALID_CAST            = -18;
    const NResult N_E_INVALID_OPERATION       =  -7;
    const NResult N_E_IO                      = -14;
      const NResult N_E_DIRECTORY_NOT_FOUND   = -19;
      const NResult N_E_DRIVE_NOT_FOUND       = -20;
      const NResult N_E_END_OF_STREAM         = -15;
      const NResult N_E_FILE_NOT_FOUND        = -21;
      const NResult N_E_FILE_LOAD             = -22;
      const NResult N_E_PATH_TOO_LONG         = -23;
      const NResult N_E_SOCKET                = -31;
    const NResult N_E_KEY_NOT_FOUND           = -32;
    const NResult N_E_NOT_IMPLEMENTED         =  -5;
    const NResult N_E_NOT_SUPPORTED           =  -6;
    const NResult N_E_NULL_REFERENCE          =  -3;
    const NResult N_E_OPERATION_CANCELED      = -34;
    const NResult N_E_OUT_OF_MEMORY           =  -4;
    const NResult N_E_SECURITY                = -24;
    const NResult N_E_TIMEOUT                 = -30;

    const NResult N_E_EXTERNAL                = -90;
      const NResult N_E_CLR                   = -93;
      const NResult N_E_COM                   = -92;
      const NResult N_E_CPP                   = -96;
      const NResult N_E_JVM                   = -97;
      const NResult N_E_MAC                   = -95;
      const NResult N_E_SYS                   = -94;
      const NResult N_E_WIN32                 = -91;

    const NResult N_E_NOT_ACTIVATED          = -200;

inline bool NFailed(NResult result)
{
	return result < 0;
}

inline bool NSucceeded(NResult result)
{
	return result >= 0;
}

const NUInt NE_PRESERVE_INNER_ERROR = 0x00000001;
const NUInt NE_NO_CALL_STACK = 0x00000002;
const NUInt NE_MERGE_CALL_STACK = 0x00000004;
const NUInt NE_IS_DIRECTORY_ACCESS = 0x00000100;
const NUInt NE_SKIP_ONE_FRAME = 0x01000000;

class NCallStackEntry : public NCallStackEntry_
{
	N_DECLARE_DISPOSABLE_STRUCT_CLASS(NCallStackEntry)

public:
	NCallStackEntry(void * addr, const NStringWrapper & function, const NStringWrapper & file, NInt line)
	{
		NCheck(NCallStackEntryCreateN(addr, function.GetHandle(), file.GetHandle(), line, this));
	}

	NString GetFunction() const
	{
		return NString(hFunction, false);
	}

	void SetFunction(const NStringWrapper & value)
	{
		NCheck(NStringSet(value.GetHandle(), &hFunction));
	}

	NString GetFile() const
	{
		return NString(hFile, false);
	}

	void SetFile(const NStringWrapper & value)
	{
		NCheck(NStringSet(value.GetHandle(), &hFile));
	}
};

class NError : public NObject
{
	N_DECLARE_OBJECT_CLASS(NError, NObject)

private:
	static HNError Create(NResult code, const NStringWrapper & message, const NStringWrapper & param, NInt externalError, const NString & externalCallStack, const HNError * arhInnerErrors, NInt innerErrorCount)
	{
		HNError handle;
		NCheck(NErrorCreateN(code, message.GetHandle(), param.GetHandle(), externalError, externalCallStack.GetHandle(), arhInnerErrors, innerErrorCount, &handle));
		return handle;
	}

public:
	explicit NError(NResult code, const NStringWrapper & message = NString(), const NStringWrapper & param = NString(), NInt externalError = 0, const NString & externalCallStack = NString(), const HNError * arhInnerErrors = NULL, NInt innerErrorCount = 0)
		: NObject(Create(code, message, param, externalError, externalCallStack, arhInnerErrors, innerErrorCount), true)
	{
	}

	static NInt GetLastSysError(void)
	{
		return NErrorGetLastSysError();
	}

	static NUInt GetLastWin32Error(void)
	{
		return NErrorGetLastWin32Error();
	}

	static NString GetDefaultMessage(NResult code)
	{
		HNString hValue;
		return NFailed(NErrorGetDefaultMessageN(code, &hValue)) ? NString() : NString(hValue, true);
	}

	static NString GetSysErrorMessage(NInt errnum)
	{
		HNString hValue;
		return NFailed(NErrorGetSysErrorMessageN(errnum, &hValue)) ? NString() : NString(hValue, true);
	}

	static NString GetMachErrorMessage(NInt err)
	{
		HNString hValue;
		return NFailed(NErrorGetMachErrorMessageN(err, &hValue)) ? NString() : NString(hValue, true);
	}

	static NString GetMacErrorMessage(NInt err)
	{
		HNString hValue;
		return NFailed(NErrorGetMacErrorMessageN(err, &hValue)) ? NString() : NString(hValue, true);
	}

	static NString GetWin32ErrorMessage(NUInt errorCode)
	{
		HNString hValue;
		return NFailed(NErrorGetWin32ErrorMessageN(errorCode, &hValue)) ? NString() : NString(hValue, true);
	}

	static void SetLast(const NError & error, NUInt flags = 0)
	{
		NCheck(NErrorSetLastEx(error.GetHandle(), flags));
	}

	void Raise()
	{
		NCheck(NErrorRaise(GetHandle()));
	}

	static NResult SetLast(NResult code, const NStringWrapper & message, const NStringWrapper & param = NString(), NInt externalError = 0, const NStringWrapper & externalCallStack = NString(), NUInt flags = 0)
	{
		return NErrorSetLastN(code, message.GetHandle(), param.GetHandle(), externalError, externalCallStack.GetHandle(), flags);
	}

	static NResult SetCom(NInt comError, const NStringWrapper & message, const NStringWrapper & param = NString(), const NStringWrapper & externalCallStack = NString(), NUInt flags = 0)
	{
		return NErrorSetComN(comError, message.GetHandle(), param.GetHandle(), externalCallStack.GetHandle(), flags);
	}

	static NResult SetMach(NInt32 machError, const NStringWrapper & message, const NStringWrapper & param = NString(), const NStringWrapper & externalCallStack = NString(), NUInt flags = 0)
	{
		return NErrorSetMachN(machError, message.GetHandle(), param.GetHandle(), externalCallStack.GetHandle(), flags);
	}

	static NResult SetMac(NInt32 macError, const NStringWrapper & message, const NStringWrapper & param = NString(), const NStringWrapper & externalCallStack = NString(), NUInt flags = 0)
	{
		return NErrorSetMacN(macError, message.GetHandle(), param.GetHandle(), externalCallStack.GetHandle(), flags);
	}

	static NResult SetSys(NInt sysError, const NStringWrapper & message, const NStringWrapper & param = NString(), const NStringWrapper & externalCallStack = NString(), NUInt flags = 0)
	{
		return NErrorSetSysN(sysError, message.GetHandle(), param.GetHandle(), externalCallStack.GetHandle(), flags);
	}

	static NResult SetWin32(NUInt win32Error, const NStringWrapper & message, const NStringWrapper & param = NString(), const NStringWrapper & externalCallStack = NString(), NUInt flags = 0)
	{
		return NErrorSetWin32N(win32Error, message.GetHandle(), param.GetHandle(), externalCallStack.GetHandle(), flags);
	}

	static void Append(void * addr, const NStringWrapper & function, const NStringWrapper & file = NString(), NInt line = -1)
	{
		NErrorAppendN(addr, function.GetHandle(), file.GetHandle(), line);
	}

	static void Report(NResult errorCode, NError & error)
	{
		NCheck(NErrorReportEx(errorCode, error.GetHandle()));
	}

	static void Suppress(NResult result)
	{
		NErrorSuppress(result);
	}

	static NError GetLast(NUInt flags = 0)
	{
		HNError handle;
		NCheck(NErrorGetLastEx(flags, &handle));
		return FromHandle<NError>(handle, true);
	}

	static NError Capture(NResult result)
	{
		HNError handle;
		NCheck(NErrorCapture(result, &handle));
		return FromHandle<NError>(handle, true);
	}

	NInt GetCode() const
	{
		NInt value;
		return NFailed(NErrorGetCodeEx(GetHandle(), &value)) ? N_OK : value;
	}

	NString GetMessage() const
	{
		HNString hValue;
		return NFailed(NErrorGetMessageN(GetHandle(), &hValue)) ? NString() : NString(hValue, true);
	}

	NString GetParam() const
	{
		HNString hValue;
		return NFailed(NErrorGetParamN(GetHandle(), &hValue)) ? NString() : NString(hValue, true);
	}

	NInt GetExternalError() const
	{
		NInt value;
		return NFailed(NErrorGetExternalErrorEx(GetHandle(), &value)) ? 0 : value;
	}

	NString GetExternalCallStack() const
	{
		HNString hValue;
		return NFailed(NErrorGetExternalCallStackN(GetHandle(), &hValue)) ? NString() : NString(hValue, true);
	}

	NInt GetCallStackCount() const
	{
		NInt value;
		return NFailed(NErrorGetCallStackCount(GetHandle(), &value)) ? 0 : value;
	}

	NCallStackEntry GetCallStackEntry(NInt index) const
	{
		NCallStackEntry entry;
		NCheck(NErrorGetCallStackEntry(GetHandle(), index, &entry));
		return entry;
	}

	NString GetCallStack() const
	{
		HNString hValue;
		return NFailed(NErrorGetCallStackN(GetHandle(), &hValue)) ? NString() : NString(hValue, true);
	}

	NError GetInnerError() const
	{
		HNError hValue;
		return FromHandle< ::Neurotec::NError>(NFailed(NErrorGetInnerErrorEx(GetHandle(), &hValue)) ? NULL : hValue);
	}

	NInt GetInnerErrorCount() const
	{
		NInt value;
		return NFailed(NErrorGetInnerErrorCount(GetHandle(), &value)) ? 0 : value;
	}

	NError GetInnerErrorAt(NInt index) const
	{
		HNError hValue;
		return FromHandle< ::Neurotec::NError>(NFailed(NErrorGetInnerErrorAt(GetHandle(), index, &hValue)) ? NULL : hValue);
	}

public:
	static N_NO_INLINE NResult SetLast(const std::exception & e)
	{
		NResult code;
		const std::type_info & eType = typeid(e);
		NString fullMessage;
		const NAChar * szMessage = NULL;
		if (typeid(std::exception) == eType)
		{
			code = N_E_FAILED;
		}
		else if (dynamic_cast<const std::bad_alloc *>(&e))
		{
			code = N_E_OUT_OF_MEMORY;
		}
		else if (dynamic_cast<const std::bad_cast *>(&e))
		{
			code = N_E_INVALID_CAST;
		}
		else if (dynamic_cast<const std::runtime_error *>(&e))
		{
			if (typeid(std::runtime_error) == eType)
			{
				code = N_E_CORE;
			}
			else if (dynamic_cast<const std::overflow_error *>(&e))
			{
				code = N_E_OVERFLOW;
			}
			else if (dynamic_cast<const std::range_error *>(&e))
			{
				code = N_E_ARITHMETIC;
			}
			else if (dynamic_cast<const std::underflow_error *>(&e))
			{
				code = N_E_ARITHMETIC;
			}
			else if (dynamic_cast<const std::ios_base::failure *>(&e))
			{
				code = N_E_IO;
			}
			else
			{
				code = N_E_CPP;
			}
		}
		else if (dynamic_cast<const std::logic_error *>(&e))
		{
			if (typeid(std::logic_error) == eType)
			{
				code = N_E_CORE;
			}
			else if (dynamic_cast<const std::invalid_argument *>(&e))
			{
				code = N_E_ARGUMENT;
			}
			else if (dynamic_cast<const std::out_of_range *>(&e))
			{
				code = N_E_ARGUMENT_OUT_OF_RANGE;
			}
			else if (dynamic_cast<const std::domain_error *>(&e))
			{
				code = N_E_ARGUMENT;
			}
			else
			{
				code = N_E_CPP;
			}
		}
		else
		{
			code = N_E_CPP;
		}
		try
		{
			szMessage = e.what();
			fullMessage = szMessage && szMessage[0] ? NString::ConcatA(3, eType.name(), ": ", szMessage) : NString(eType.name());
		}
		catch (...)
		{
		}
		NErrorSetLastN(N_E_CPP, fullMessage.GetHandle(), NULL, 0, NULL, (code == N_E_CPP ? 0 : NE_NO_CALL_STACK) | NE_SKIP_ONE_FRAME);
		if (code != N_E_CPP)
		{
			NErrorSetLastA(code, szMessage, NULL, 0, NULL, NE_PRESERVE_INNER_ERROR | NE_SKIP_ONE_FRAME);
		}
		return code;
	}

#if defined(N_MSVC) && !defined(N_NO_UNICODE)
	static N_NO_INLINE NResult SetLast(const _com_error & e)
	{
		const std::type_info & eType = typeid(e);
		_bstr_t message;
		NString fullMessage;
		HRESULT comError = 0;
		const NWChar * szMessage = NULL;
		const NWChar * szExternalCallStack = NULL;
		try
		{
			comError = e.Error();
			IErrorInfo * pErrorInfo = e.ErrorInfo();
			if (pErrorInfo) pErrorInfo->Release(); // pointer is unusable from here
			if (pErrorInfo)
			{
				szMessage = e.Description();
				szExternalCallStack = e.Source();
			}
			else
			{
				szMessage = message = e.ErrorMessage();
				szExternalCallStack = NULL;
			}
			fullMessage = szMessage && szMessage[0] ? NString::ConcatW(3, eType.name(), L": ", szMessage) : NString(eType.name());
		}
		catch (...)
		{
		}
		NErrorSetLastN(N_E_CPP, fullMessage.GetHandle(), NULL, 0, NULL, NE_NO_CALL_STACK | NE_SKIP_ONE_FRAME);
		return NErrorSetComW(comError, szMessage, NULL, szExternalCallStack, NE_PRESERVE_INNER_ERROR | NE_SKIP_ONE_FRAME);
	}
#endif
};

inline NInt NCheck(NResult result)
{
	if (NFailed(result))
	{
		throw NError::GetLast();
	}
	return result;
}

inline void N_NO_RETURN NThrowException(NResult code = N_E_FAILED, const NStringWrapper & message = NString(), const NStringWrapper & paramName = NString()) { throw ::Neurotec::NError(code, message, paramName); }
inline void N_NO_RETURN NThrowException(const NStringWrapper & message, const NStringWrapper & paramName = NString()) { NThrowException(N_E_FAILED, message, paramName); }
inline void N_NO_RETURN NThrowAbandonedMutexException() { NThrowException(N_E_ABANDONED_MUTEX); }
inline void N_NO_RETURN NThrowAbandonedMutexException(const NStringWrapper & message) { NThrowException(N_E_ABANDONED_MUTEX, message); }
inline void N_NO_RETURN NThrowArgumentException(const NStringWrapper & message, const NStringWrapper & paramName) { NThrowException(N_E_ARGUMENT, message, paramName); }
inline void N_NO_RETURN NThrowArgumentException(const NStringWrapper & message) { NThrowArgumentException(message, NString()); }
inline void N_NO_RETURN NThrowArgumentValueException(const NStringWrapper & paramName) { NThrowArgumentException(paramName + N_T(" is invalid"), paramName); }
inline void N_NO_RETURN NThrowArgumentNotNullException(const NStringWrapper & paramName) { NThrowArgumentException(paramName + N_T(" is not NULL"), paramName); }
inline void N_NO_RETURN NThrowArgumentNotZeroException(const NStringWrapper & paramName) { NThrowArgumentException(paramName + N_T(" is not zero"), paramName); }
inline void N_NO_RETURN NThrowArgumentTypeException(const NStringWrapper & paramName) { NThrowArgumentException(paramName + N_T(" type is not the one that is expected"), paramName); }
inline void N_NO_RETURN NThrowArgumentElementTypeException(const NStringWrapper & paramName) { NThrowArgumentException(N_T("One of ") + paramName + N_T(" elements type is not the one that is expected"), paramName); }
inline void N_NO_RETURN NThrowEmptyStringArgumentException(const NStringWrapper & paramName) { NThrowArgumentException(paramName + N_T(" is an empty string"), paramName); }
inline void N_NO_RETURN NThrowNotEmptyStringArgumentException(const NStringWrapper & paramName) { NThrowArgumentException(paramName + N_T(" is not an empty string"), paramName); }
inline void N_NO_RETURN NThrowEmptyStringArgumentElementException(const NStringWrapper & paramName) { NThrowArgumentException(N_T("One of ") + paramName + N_T(" elements is an empty string"), paramName); }
inline void N_NO_RETURN NThrowArgumentElementException(const NStringWrapper & paramName) { NThrowArgumentException(N_T("One of ") + paramName + N_T(" elements is invalid"), paramName); }
inline void N_NO_RETURN NThrowArgumentInsufficientException(const NStringWrapper & paramName) { NThrowArgumentException(paramName + N_T(" is insufficient"), paramName); }
inline void N_NO_RETURN NThrowArgumentPointerException(const NStringWrapper & paramName) { NThrowArgumentException(N_T("Value ") + paramName + N_T(" points to is invalid"), paramName); }
inline void N_NO_RETURN NThrowArgumentNullException(const NStringWrapper & paramName, const NStringWrapper & message) { NThrowException(N_E_ARGUMENT_NULL, message, paramName); }
inline void N_NO_RETURN NThrowArgumentNullException(const NStringWrapper & paramName) { NThrowArgumentNullException(paramName, NString()); }
inline void N_NO_RETURN NThrowArgumentElementNullException(const NStringWrapper & paramName) { NThrowArgumentNullException(N_T("One of ") + paramName + N_T(" elements is NULL"), paramName); }
inline void N_NO_RETURN NThrowArgumentOutOfRangeException(const NStringWrapper & paramName, const NStringWrapper & message) { NThrowException(N_E_ARGUMENT_OUT_OF_RANGE, message, paramName); }
inline void N_NO_RETURN NThrowArgumentOutOfRangeException(const NStringWrapper & paramName = NString()) { NThrowArgumentOutOfRangeException(paramName, NString()); }
inline void N_NO_RETURN NThrowArgumentLessThanZeroException(const NStringWrapper & paramName) { NThrowArgumentOutOfRangeException(paramName, paramName + N_T(" is less than zero")); }
inline void N_NO_RETURN NThrowArgumentLessThanOneException(const NStringWrapper & paramName) { NThrowArgumentOutOfRangeException(paramName, paramName + N_T(" is less than one")); }
inline void N_NO_RETURN NThrowArgumentLessThanMinusOneException(const NStringWrapper & paramName) { NThrowArgumentOutOfRangeException(paramName, paramName + N_T(" is less than minus one")); }
inline void N_NO_RETURN NThrowArgumentZeroException(const NStringWrapper & paramName) { NThrowArgumentOutOfRangeException(paramName, paramName + N_T(" is zero")); }
inline void N_NO_RETURN NThrowInvalidEnumArgumentException(const NStringWrapper & paramName = NString(), const NStringWrapper & message = NString()) { NThrowException(N_E_INVALID_ENUM_ARGUMENT, message, paramName); }
inline void N_NO_RETURN NThrowArithmeticException(const NStringWrapper & message = NString()) { NThrowException(N_E_ARITHMETIC, message); }
inline void N_NO_RETURN NThrowOverflowException(const NStringWrapper & message) { NThrowException(N_E_OVERFLOW, message); }
inline void N_NO_RETURN NThrowOverflowException() { NThrowOverflowException(NString()); }
inline void N_NO_RETURN NThrowBadImageFormatException(const NStringWrapper & message = NString(), const NStringWrapper & fileName = NString()) { NThrowException(N_E_BAD_IMAGE_FORMAT, message, fileName); }
inline void N_NO_RETURN NThrowDllNotFoundException(const NStringWrapper & message = NString(), const NStringWrapper & fileName = NString()) { NThrowException(N_E_DLL_NOT_FOUND, message, fileName); }
inline void N_NO_RETURN NThrowEntryPointNotFoundException(const NStringWrapper & message = NString(), const NStringWrapper & symbolName = NString()) { NThrowException(N_E_ENTRY_POINT_NOT_FOUND, message, symbolName); }
inline void N_NO_RETURN NThrowFormatException(const NStringWrapper & paramName = NString(), const NStringWrapper & message = NString()) { NThrowException(N_E_FORMAT, message, paramName); }
inline void N_NO_RETURN NThrowFileFormatException(const NStringWrapper & message = NString(), const NStringWrapper & fileName = NString()) { NThrowException(N_E_FILE_FORMAT, message, fileName); }
inline void N_NO_RETURN NThrowIndexOutOfRangeException(const NStringWrapper & message = NString()) { NThrowException(N_E_INDEX_OUT_OF_RANGE, message); }
inline void N_NO_RETURN NThrowInvalidCastException(const NStringWrapper & message = NString()) { NThrowException(N_E_INVALID_CAST, message); }
inline void N_NO_RETURN NThrowInvalidOperationException(const NStringWrapper & message) { NThrowException(N_E_INVALID_OPERATION, message); }
inline void N_NO_RETURN NThrowInvalidOperationException() { NThrowInvalidOperationException(NString()); }
inline void N_NO_RETURN NThrowIOException(const NStringWrapper & message = NString()) { NThrowException(N_E_IO, message); }
inline void N_NO_RETURN NThrowDirectoryNotFoundException(const NStringWrapper & message = NString(), const NStringWrapper & path = NString()) { NThrowException(N_E_DIRECTORY_NOT_FOUND, message, path); }
inline void N_NO_RETURN NThrowDriveNotFoundException(const NStringWrapper & message = NString(), const NStringWrapper & path = NString()) { NThrowException(N_E_DRIVE_NOT_FOUND, message, path); }
inline void N_NO_RETURN NThrowEndOfStreamException(const NStringWrapper & message = NString()) { NThrowException(N_E_END_OF_STREAM, message); }
inline void N_NO_RETURN NThrowFileNotFoundException(const NStringWrapper & message = NString(), const NStringWrapper & fileName = NString()) { NThrowException(N_E_FILE_NOT_FOUND, message, fileName); }
inline void N_NO_RETURN NThrowFileLoadException(const NStringWrapper & message = NString(), const NStringWrapper & fileName = NString()) { NThrowException(N_E_FILE_LOAD, message, fileName); }
inline void N_NO_RETURN NThrowPathTooLongException(const NStringWrapper & message = NString(), const NStringWrapper & path = NString()) { NThrowException(N_E_PATH_TOO_LONG, message, path); }
inline void N_NO_RETURN NThrowSocketException(const NStringWrapper & message = NString()) { NThrowException(N_E_SOCKET, message); }
inline void N_NO_RETURN NThrowKeyNotFoundException(const NStringWrapper & message = NString()) { NThrowException(N_E_KEY_NOT_FOUND, message); }
inline void N_NO_RETURN NThrowNotImplementedException(const NStringWrapper & message) { NThrowException(N_E_NOT_IMPLEMENTED, message); }
inline void N_NO_RETURN NThrowNotImplementedException() { NThrowNotImplementedException(NString()); }
inline void N_NO_RETURN NThrowNotSupportedException(const NStringWrapper & message) { NThrowException(N_E_NOT_SUPPORTED, message); }
inline void N_NO_RETURN NThrowNotSupportedException() { NThrowNotSupportedException(NString()); }
inline void N_NO_RETURN NThrowNullReferenceException(const NStringWrapper & message) { NThrowException(N_E_NULL_REFERENCE, message); }
inline void N_NO_RETURN NThrowNullReferenceException() { NThrowNullReferenceException(NString()); }
inline void N_NO_RETURN NThrowOperationCanceledException(const NStringWrapper & message = NString()) { NThrowException(N_E_OPERATION_CANCELED, message); }
inline void N_NO_RETURN NThrowOutOfMemoryException(const NStringWrapper & message = NString()) { NThrowException(N_E_OUT_OF_MEMORY, message); }
inline void N_NO_RETURN NThrowSecurityException(const NStringWrapper & message = NString()) { NThrowException(N_E_SECURITY, message); }
inline void N_NO_RETURN NThrowTimeoutException(const NStringWrapper & message = NString()) { NThrowException(N_E_TIMEOUT, message); }
inline void N_NO_RETURN NThrowExternalException(NInt errorCode, NInt externalErrorCode, const NStringWrapper & message = NString()) { throw NError(errorCode, message, NString(), externalErrorCode); }
inline void N_NO_RETURN NThrowExternalException(NInt errorCode, const NStringWrapper & message = NString()) { NThrowExternalException(N_E_EXTERNAL, errorCode, message); }
inline void N_NO_RETURN NThrowClrException(NInt errorCode, const NStringWrapper & message = NString()) { NThrowExternalException(N_E_CLR, errorCode, message); }
inline void N_NO_RETURN NThrowComException(NInt errorCode, const NStringWrapper & message = NString()) { NThrowExternalException(N_E_COM, errorCode, message); }
inline void N_NO_RETURN NThrowCppException(const NStringWrapper & message = NString()) { NThrowException(N_E_CPP, message); }
inline void N_NO_RETURN NThrowJvmException(const NStringWrapper & message = NString()) { NThrowException(N_E_JVM, message); }
inline void N_NO_RETURN NThrowMacException(NInt errorCode, const NStringWrapper & message = NString()) { NThrowExternalException(N_E_MAC, errorCode, message); }
inline void N_NO_RETURN NThrowSysException(NInt errorCode, const NStringWrapper & message = NString()) { NThrowExternalException(N_E_SYS, errorCode, message); }
inline void N_NO_RETURN NThrowWin32Exception(NUInt errorCode, const NStringWrapper & message = NString()) { NThrowExternalException(N_E_WIN32, errorCode, message); }
inline void N_NO_RETURN NThrowNotActivatedException(const NStringWrapper & message = NString()) { NThrowException(N_E_NOT_ACTIVATED, message); }


#if defined(N_MSVC) && !defined(N_NO_UNICODE)
	#define N_EXCEPTION_CATCH_AND_SET_COM(result) \
		catch (const _com_error & e)\
		{\
			(result) = ::Neurotec::NError::SetLast(e);\
		}
#else
	#define N_EXCEPTION_CATCH_AND_SET_COM(result)
#endif

#define N_EXCEPTION_CATCH_AND_SET_FRAMEWORK(result)

#define N_EXCEPTION_CATCH_AND_SET_LAST(result) \
	catch (::Neurotec::NError & error)\
	{\
		::Neurotec::NError::SetLast(error);\
		(result) = error.GetCode();\
	}\
	N_EXCEPTION_CATCH_AND_SET_FRAMEWORK(result)\
	N_EXCEPTION_CATCH_AND_SET_COM(result)\
	catch (const std::exception & e)\
	{\
		(result) = ::Neurotec::NError::SetLast(e);\
	}\
	catch (...)\
	{\
		(result) = NErrorSetLast(N_E_CPP, N_T("A C++ exception was thrown"), NULL, 0, NULL, 0);\
	}

#define N_EXCEPTION_CATCH_AND_SUPPRESS(result) \
	N_EXCEPTION_CATCH_AND_SET_LAST(result)\
	if (NFailed(result)) NErrorSuppress(result);

#define N_TRY_CPP \
	NResult N_TRY_CPP_result = N_OK;\
	try\
	{

#define N_TRY_CPP_NR \
	NResult N_TRY_CPP_result = N_OK;\
	HNError N_TRY_CPP_hError;\
	NResult N_TRY_CPP_NR_result = NErrorGetLastEx(0, &N_TRY_CPP_hError);\
	try\
	{

inline NInt NCheckContext(NResult &result, HNError &hError)
{
	if (NFailed(result))
	{
		NResult r = result;
		NErrorSetLastEx(hError, NE_MERGE_CALL_STACK | NE_SKIP_ONE_FRAME);
		N_ERROR_APPEND
		result = N_OK;
		if (hError) { NObjectUnref(hError); hError = NULL; }
		NCheck(r);
	}
	return result;
}

#define N_TRY_END_CPP_R \
	}\
	N_EXCEPTION_CATCH_AND_SET_LAST(N_TRY_CPP_result)\
	if (NFailed(N_TRY_CPP_result))\
	{\
		N_ERROR_APPEND\
	}\
	return N_TRY_CPP_result;

#define N_TRY_END_CPP \
	return N_OK;\
	N_TRY_END_CPP_R

#define N_TRY_END_CPP_NR \
	}\
	N_EXCEPTION_CATCH_AND_SET_LAST(N_TRY_CPP_result)\
	if (NFailed(N_TRY_CPP_result))\
	{\
		N_ERROR_APPEND\
		NErrorSuppress(N_TRY_CPP_result);\
	}\
	if (NSucceeded(N_TRY_CPP_NR_result))\
	{\
		NErrorSetLastEx(N_TRY_CPP_hError, NE_NO_CALL_STACK);\
		if (N_TRY_CPP_hError) NObjectUnref(N_TRY_CPP_hError);\
	}

#define N_TRY_END_CPP_C(result, hError) \
	}\
	N_EXCEPTION_CATCH_AND_SET_LAST(N_TRY_CPP_result)\
	if (NFailed(N_TRY_CPP_result))\
	{\
		(result) = N_TRY_CPP_result;\
		NErrorGetLastEx(0, &(hError));\
	}

#define N_TRY_END_CPP_C_NR(useContext, result, hError) \
	}\
	N_EXCEPTION_CATCH_AND_SET_LAST(N_TRY_CPP_result)\
	if (NFailed(N_TRY_CPP_result))\
	{\
		if (useContext) \
		{\
			(result) = N_TRY_CPP_result;\
			NErrorGetLastEx(0, &(hError));\
		}\
		else\
		{\
			NErrorSuppress(N_TRY_CPP_result);\
		}\
	}

}

#endif // !N_ERROR_HPP_INCLUDED
