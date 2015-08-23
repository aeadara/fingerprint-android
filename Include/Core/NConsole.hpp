#ifndef N_CONSOLE_HPP_INCLUDED
#define N_CONSOLE_HPP_INCLUDED

#include <IO/NTextReader.hpp>
#include <IO/NTextWriter.hpp>
namespace Neurotec
{
using ::Neurotec::IO::HNTextReader;
using ::Neurotec::IO::HNTextWriter;
#include <Core/NConsole.h>
}

namespace Neurotec
{

class NConsole
{
	N_DECLARE_STATIC_OBJECT_CLASS(NConsole)

public:
	static ::Neurotec::IO::NTextReader GetIn()
	{
		HNTextReader hValue;
		NCheck(NConsoleGetIn(&hValue));
		return NObject::FromHandle< ::Neurotec::IO::NTextReader>(hValue);
	}

	static ::Neurotec::IO::NTextWriter GetOut()
	{
		HNTextWriter hValue;
		NCheck(NConsoleGetOut(&hValue));
		return NObject::FromHandle< ::Neurotec::IO::NTextWriter>(hValue);
	}

	static ::Neurotec::IO::NTextWriter GetError()
	{
		HNTextWriter hValue;
		NCheck(NConsoleGetError(&hValue));
		return NObject::FromHandle< ::Neurotec::IO::NTextWriter>(hValue);
	}

	static void SetIn(const ::Neurotec::IO::NTextReader & value)
	{
		NCheck(NConsoleSetIn(value.GetHandle()));
	}

	static void SetOut(const ::Neurotec::IO::NTextWriter & value)
	{
		NCheck(NConsoleSetOut(value.GetHandle()));
	}

	static void SetError(const ::Neurotec::IO::NTextWriter & value)
	{
		NCheck(NConsoleSetError(value.GetHandle()));
	}

	static NInt ReadChar()
	{
		NInt value;
		NCheck(NConsoleReadChar(&value));
		return value;
	}

	static NString ReadLine()
	{
		HNString hValue;
		NCheck(NConsoleReadLine(&hValue));
		return NString(hValue, true);
	}

	static void WriteChar(NChar value)
	{
		NCheck(NConsoleWriteChar(value));
	}

	static void Write(const NChar * arValue, NInt valueLength)
	{
		NCheck(NConsoleWriteChars(arValue, valueLength));
	}

	static void Write(NUInt value)
	{
		NCheck(NConsoleWriteUInt32(value));
	}

	static void Write(NInt value)
	{
		NCheck(NConsoleWriteInt32(value));
	}

	static void Write(NUInt64 value)
	{
		NCheck(NConsoleWriteUInt64(value));
	}

	static void Write(NInt64 value)
	{
		NCheck(NConsoleWriteInt64(value));
	}

	static void Write(NFloat value)
	{
		NCheck(NConsoleWriteSingle(value));
	}

	static void Write(NDouble value)
	{
		NCheck(NConsoleWriteDouble(value));
	}

	static void Write(bool value)
	{
		NCheck(NConsoleWriteBoolean(value ? NTrue : NFalse));
	}

	static void WriteSizeType(NSizeType value)
	{
		NCheck(NConsoleWriteSizeType(value));
	}

	static void WriteSSizeType(NSSizeType value)
	{
		NCheck(NConsoleWriteSSizeType(value));
	}

	static void Write(const void * value)
	{
		NCheck(NConsoleWritePointer(value));
	}

	static void WriteResult(NResult value)
	{
		NCheck(NConsoleWriteResult(value));
	}

	static void Write(const NType & type, const void * pValue, NSizeType valueSize)
	{
		NCheck(NConsoleWriteValue(type.GetHandle(), pValue, valueSize));
	}

	static void Write(const NObject & value)
	{
		NCheck(NConsoleWriteObject(value.GetHandle()));
	}

	static void Write(const NStringWrapper & value)
	{
		NCheck(NConsoleWriteN(value.GetHandle()));
	}

	static void Write(const NStringWrapper format, ...)
	{
		va_list args;
		va_start(args, format);
		try
		{
			Write(format, args);
			va_end(args);
		}
		catch (...)
		{
			va_end(args);
			throw;
		}
	}

	static void Write(const NStringWrapper & value, va_list args)
	{
		NCheck(NConsoleWriteFormatN(value.GetHandle(), args));
	}

	static void WriteLine()
	{
		NCheck(NConsoleWriteEmptyLine());
	}

	static void WriteCharLine(NChar value)
	{
		NCheck(NConsoleWriteCharLine(value));
	}

	static void WriteLine(const NChar * arValue, NInt valueLength)
	{
		NCheck(NConsoleWriteCharsLine(arValue, valueLength));
	}

	static void WriteLine(NUInt value)
	{
		NCheck(NConsoleWriteUInt32Line(value));
	}

	static void WriteLine(NInt value)
	{
		NCheck(NConsoleWriteInt32Line(value));
	}

	static void WriteLine(NUInt64 value)
	{
		NCheck(NConsoleWriteUInt64Line(value));
	}

	static void WriteLine(NInt64 value)
	{
		NCheck(NConsoleWriteInt64Line(value));
	}

	static void WriteLine(NFloat value)
	{
		NCheck(NConsoleWriteSingleLine(value));
	}

	static void WriteLine(NDouble value)
	{
		NCheck(NConsoleWriteDoubleLine(value));
	}

	static void WriteLine(bool value)
	{
		NCheck(NConsoleWriteBooleanLine(value ? NTrue : NFalse));
	}

	static void WriteSizeTypeLine(NSizeType value)
	{
		NCheck(NConsoleWriteSizeTypeLine(value));
	}

	static void WriteSSizeTypeLine(NSSizeType value)
	{
		NCheck(NConsoleWriteSSizeTypeLine(value));
	}

	static void WriteLine(const void * value)
	{
		NCheck(NConsoleWritePointerLine(value));
	}

	static void WriteResultLine(NResult value)
	{
		NCheck(NConsoleWriteResultLine(value));
	}

	static void WriteLine(const NType & type, const void * pValue, NSizeType valueSize)
	{
		NCheck(NConsoleWriteValueLine(type.GetHandle(), pValue, valueSize));
	}

	static void WriteLine(const NObject & value)
	{
		NCheck(NConsoleWriteObjectLine(value.GetHandle()));
	}

	static void WriteLine(const NStringWrapper & value)
	{
		NCheck(NConsoleWriteLineN(value.GetHandle()));
	}

	static void WriteLine(const NStringWrapper format, ...)
	{
		va_list args;
		va_start(args, format);
		try
		{
			WriteLine(format, args);
			va_end(args);
		}
		catch (...)
		{
			va_end(args);
			throw;
		}
	}

	static void WriteLine(const NStringWrapper & value, va_list args)
	{
		NCheck(NConsoleWriteFormatLineN(value.GetHandle(), args));
	}
};

}

#endif // !N_CONSOLE_HPP_INCLUDED
