#ifndef N_BINARY_WRITER_HPP_INCLUDED
#define N_BINARY_WRITER_HPP_INCLUDED

#include <IO/NIOTypes.hpp>
#include <Text/NEncoding.hpp>
namespace Neurotec { namespace IO
{
using ::Neurotec::Text::NEncoding;
#include <IO/NBinaryWriter.h>
}}

namespace Neurotec { namespace IO
{

class NBinaryWriter : public NObject
{
	N_DECLARE_OBJECT_CLASS(NBinaryWriter, NObject)

private:
	static HNBinaryWriter Create(const NStream & stream, NByteOrder byteOrder)
	{
		HNBinaryWriter handle;
		NCheck(NBinaryWriterCreate(stream.GetHandle(), byteOrder, &handle));
		return handle;
	}

	static HNBinaryWriter Create(const NStream & stream, NByteOrder byteOrder, NEncoding encoding)
	{
		HNBinaryWriter handle;
		NCheck(NBinaryWriterCreateWithEncoding(stream.GetHandle(), byteOrder, encoding, &handle));
		return handle;
	}

public:
	static NBinaryWriter GetNull()
	{
		HNBinaryWriter hValue;
		NCheck(NBinaryWriterGetNull(&hValue));
		return FromHandle<NBinaryWriter>(hValue, true);
	}

	NBinaryWriter(const NStream & stream, NByteOrder byteOrder)
		: NObject(Create(stream, byteOrder), true)
	{
	}

	NBinaryWriter(const NStream & stream, NByteOrder byteOrder, NEncoding encoding)
		: NObject(Create(stream, byteOrder, encoding), true)
	{
	}

	void Flush()
	{
		NCheck(NBinaryWriterFlush(GetHandle()));
	}

	void Seek(NLong offset, NSeekOrigin origin)
	{
		NCheck(NBinaryWriterSeek(GetHandle(), offset, origin));
	}

	void Write(NByte value)
	{
		NCheck(NBinaryWriterWriteByte(GetHandle(), value));
	}

	void Write(NSByte value)
	{
		NCheck(NBinaryWriterWriteSByte(GetHandle(), value));
	}

	void Write(NUInt16 value)
	{
		NCheck(NBinaryWriterWriteUInt16(GetHandle(), value));
	}

	void Write(NInt16 value)
	{
		NCheck(NBinaryWriterWriteInt16(GetHandle(), value));
	}

	void Write(NUInt32 value)
	{
		NCheck(NBinaryWriterWriteUInt32(GetHandle(), value));
	}

	void Write(NInt32 value)
	{
		NCheck(NBinaryWriterWriteInt32(GetHandle(), value));
	}

#ifndef N_NO_INT_64
	void Write(NUInt64 value)
	{
		NCheck(NBinaryWriterWriteUInt64(GetHandle(), value));
	}

	void Write(NInt64 value)
	{
		NCheck(NBinaryWriterWriteInt64(GetHandle(), value));
	}
#endif

#ifndef N_NO_FLOAT
	void Write(NSingle value)
	{
		NCheck(NBinaryWriterWriteSingle(GetHandle(), value));
	}

	void Write(NDouble value)
	{
		NCheck(NBinaryWriterWriteDouble(GetHandle(), value));
	}
#endif

	void Write(bool value)
	{
		NCheck(NBinaryWriterWriteBoolean(GetHandle(), value ? NTrue : NFalse));
	}

	void Write(const void * pBuffer, NSizeType bufferSize)
	{
		NCheck(NBinaryWriterWriteBytes(GetHandle(), pBuffer, bufferSize));
	}

	void Write(const NBuffer & buffer)
	{
		NCheck(NBinaryWriterWriteBytesN(GetHandle(), buffer.GetHandle()));
	}

	void WriteChar(NChar value)
	{
		NCheck(NBinaryWriterWriteChar(GetHandle(), value));
	}

	void WriteChars(const NChar * arChars, NInt count)
	{
		NCheck(NBinaryWriterWriteChars(GetHandle(), arChars, count));
	}

	NStream GetBaseStream()
	{
		HNStream hValue;
		NCheck(NBinaryWriterGetBaseStream(GetHandle(), &hValue));
		return FromHandle<NStream>(hValue, true);
	}

	NByteOrder GetByteOrder()
	{
		NByteOrder value;
		NCheck(NBinaryWriterGetByteOrder(GetHandle(), &value));
		return value;
	}

	NLong GetPosition()
	{
		NLong value;
		NCheck(NBinaryWriterGetPosition(GetHandle(), &value));
		return value;
	}

	void SetPosition(NLong value)
	{
		NCheck(NBinaryWriterSetPosition(GetHandle(), value));
	}
};

}}

#endif // !N_BINARY_WRITER_HPP_INCLUDED
