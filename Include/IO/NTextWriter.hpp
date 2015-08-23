#ifndef N_TEXT_WRITER_HPP_INCLUDED
#define N_TEXT_WRITER_HPP_INCLUDED

#include <Core/NObject.hpp>
#include <Text/NEncoding.hpp>
namespace Neurotec { namespace IO
{
using ::Neurotec::Text::NEncoding;
#include <IO/NTextWriter.h>
}}

namespace Neurotec { namespace IO
{

class NTextWriter : public NObject
{
	N_DECLARE_OBJECT_CLASS(NTextWriter, NObject)

public:
	static NTextWriter Synchronized(NTextWriter & writer)
	{
		HNTextWriter hValue;
		NCheck(NTextWriterSynchronized(writer.GetHandle(), &hValue));
		return FromHandle<NTextWriter>(hValue);
	}

	static NTextWriter GetNull()
	{
		HNTextWriter hValue;
		NCheck(NTextWriterGetNull(&hValue));
		return FromHandle<NTextWriter>(hValue, true);
	}

	::Neurotec::Text::NEncoding GetEncoding() const
	{
		::Neurotec::Text::NEncoding value;
		NCheck(NTextWriterGetEncoding(GetHandle(), &value));
		return value;
	}

	NString GetNewLine() const
	{
		HNString hValue;
		NCheck(NTextWriterGetNewLine(GetHandle(), &hValue));
		return NString(hValue, true);
	}

	void SetNewLine(const NStringWrapper & value)
	{
		NCheck(NTextWriterSetNewLineN(GetHandle(), value.GetHandle()));
	}

	void Flush()
	{
		NCheck(NTextWriterFlush(GetHandle()));
	}

	void WriteChar(NChar value)
	{
		NCheck(NTextWriterWriteChar(GetHandle(), value));
	}

	void Write(const NChar * arValue, NInt valueLength)
	{
		NCheck(NTextWriterWriteChars(GetHandle(), arValue, valueLength));
	}

	void Write(NUInt value)
	{
		NCheck(NTextWriterWriteUInt32(GetHandle(), value));
	}

	void Write(NInt value)
	{
		NCheck(NTextWriterWriteInt32(GetHandle(), value));
	}

	void Write(NUInt64 value)
	{
		NCheck(NTextWriterWriteUInt64(GetHandle(), value));
	}

	void Write(NInt64 value)
	{
		NCheck(NTextWriterWriteInt64(GetHandle(), value));
	}

	void Write(NFloat value)
	{
		NCheck(NTextWriterWriteSingle(GetHandle(), value));
	}

	void Write(NDouble value)
	{
		NCheck(NTextWriterWriteDouble(GetHandle(), value));
	}

	void Write(bool value)
	{
		NCheck(NTextWriterWriteBoolean(GetHandle(), value ? NTrue : NFalse));
	}

	void WriteSizeType(NSizeType value)
	{
		NCheck(NTextWriterWriteSizeType(GetHandle(), value));
	}

	void WriteSSizeType(NSSizeType value)
	{
		NCheck(NTextWriterWriteSSizeType(GetHandle(), value));
	}

	void Write(const void * value)
	{
		NCheck(NTextWriterWritePointer(GetHandle(), value));
	}

	void WriteResult(NResult value)
	{
		NCheck(NTextWriterWriteResult(GetHandle(), value));
	}

	void Write(const NType & type, const void * pValue, NSizeType valueSize)
	{
		NCheck(NTextWriterWriteValue(GetHandle(), type.GetHandle(), pValue, valueSize));
	}

	void Write(const NObject & value)
	{
		NCheck(NTextWriterWriteObject(GetHandle(), value.GetHandle()));
	}

	void Write(const NStringWrapper & value)
	{
		NCheck(NTextWriterWriteN(GetHandle(), value.GetHandle()));
	}

	void Write(const NStringWrapper format, ...)
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

	void Write(const NStringWrapper & value, va_list args)
	{
		NCheck(NTextWriterWriteFormatN(GetHandle(), value.GetHandle(), args));
	}

	void WriteLine()
	{
		NCheck(NTextWriterWriteEmptyLine(GetHandle()));
	}

	void WriteCharLine(NChar value)
	{
		NCheck(NTextWriterWriteCharLine(GetHandle(), value));
	}

	void WriteLine(const NChar * arValue, NInt valueLength)
	{
		NCheck(NTextWriterWriteCharsLine(GetHandle(), arValue, valueLength));
	}

	void WriteLine(NUInt value)
	{
		NCheck(NTextWriterWriteUInt32Line(GetHandle(), value));
	}

	void WriteLine(NInt value)
	{
		NCheck(NTextWriterWriteInt32Line(GetHandle(), value));
	}

	void WriteLine(NUInt64 value)
	{
		NCheck(NTextWriterWriteUInt64Line(GetHandle(), value));
	}

	void WriteLine(NInt64 value)
	{
		NCheck(NTextWriterWriteInt64Line(GetHandle(), value));
	}

	void WriteLine(NFloat value)
	{
		NCheck(NTextWriterWriteSingleLine(GetHandle(), value));
	}

	void WriteLine(NDouble value)
	{
		NCheck(NTextWriterWriteDoubleLine(GetHandle(), value));
	}

	void WriteLine(bool value)
	{
		NCheck(NTextWriterWriteBooleanLine(GetHandle(), value ? NTrue : NFalse));
	}

	void WriteSizeTypeLine(NSizeType value)
	{
		NCheck(NTextWriterWriteSizeTypeLine(GetHandle(), value));
	}

	void WriteSSizeTypeLine(NSSizeType value)
	{
		NCheck(NTextWriterWriteSSizeTypeLine(GetHandle(), value));
	}

	void WriteLine(const void * value)
	{
		NCheck(NTextWriterWritePointerLine(GetHandle(), value));
	}

	void WriteResultLine(NResult value)
	{
		NCheck(NTextWriterWriteResultLine(GetHandle(), value));
	}

	void WriteLine(const NType & type, const void * pValue, NSizeType valueSize)
	{
		NCheck(NTextWriterWriteValueLine(GetHandle(), type.GetHandle(), pValue, valueSize));
	}

	void WriteLine(const NObject & value)
	{
		NCheck(NTextWriterWriteObjectLine(GetHandle(), value.GetHandle()));
	}

	void WriteLine(const NStringWrapper & value)
	{
		NCheck(NTextWriterWriteLineN(GetHandle(), value.GetHandle()));
	}

	void WriteLine(const NStringWrapper format, ...)
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

	void WriteLine(const NStringWrapper & value, va_list args)
	{
		NCheck(NTextWriterWriteFormatLineN(GetHandle(), value.GetHandle(), args));
	}
};

}}

#endif // !N_TEXT_WRITER_HPP_INCLUDED
