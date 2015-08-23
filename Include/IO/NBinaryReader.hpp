#ifndef N_BINARY_READER_HPP_INCLUDED
#define N_BINARY_READER_HPP_INCLUDED

#include <IO/NIOTypes.hpp>
#include <Text/NEncoding.hpp>
namespace Neurotec { namespace IO
{
using ::Neurotec::Text::NEncoding;
#include <IO/NBinaryReader.h>
}}

namespace Neurotec { namespace IO
{

class NBinaryReader : public NObject
{
	N_DECLARE_OBJECT_CLASS(NBinaryReader, NObject)

private:
	static HNBinaryReader Create(const NStream & stream, NByteOrder byteOrder)
	{
		HNBinaryReader handle;
		NCheck(NBinaryReaderCreate(stream.GetHandle(), byteOrder, &handle));
		return handle;
	}

	static HNBinaryReader Create(const NStream & stream, NByteOrder byteOrder, NEncoding encoding)
	{
		HNBinaryReader handle;
		NCheck(NBinaryReaderCreateWithEncoding(stream.GetHandle(), byteOrder, encoding, &handle));
		return handle;
	}

public:
	static NBinaryReader GetNull()
	{
		HNBinaryReader hValue;
		NCheck(NBinaryReaderGetNull(&hValue));
		return FromHandle<NBinaryReader>(hValue, true);
	}

	NBinaryReader(const NStream & stream, NByteOrder byteOrder)
		: NObject(Create(stream, byteOrder), true)
	{
	}

	NBinaryReader(const NStream & stream, NByteOrder byteOrder, NEncoding encoding)
		: NObject(Create(stream, byteOrder, encoding), true)
	{
	}

	void Seek(NLong offset, NSeekOrigin origin)
	{
		NCheck(NBinaryReaderSeek(GetHandle(), offset, origin));
	}

	NInt Read()
	{
		NInt value;
		NCheck(NBinaryReaderRead(GetHandle(), &value));
		return value;
	}

	NByte ReadByte()
	{
		NByte value;
		NCheck(NBinaryReaderReadByte(GetHandle(), &value));
		return value;
	}

	NSByte ReadSByte()
	{
		NSByte value;
		NCheck(NBinaryReaderReadSByte(GetHandle(), &value));
		return value;
	}

	NUInt16 ReadUInt16()
	{
		NUInt16 value;
		NCheck(NBinaryReaderReadUInt16(GetHandle(), &value));
		return value;
	}

	NInt16 ReadInt16()
	{
		NInt16 value;
		NCheck(NBinaryReaderReadInt16(GetHandle(), &value));
		return value;
	}

	NUInt32 ReadUInt32()
	{
		NUInt32 value;
		NCheck(NBinaryReaderReadUInt32(GetHandle(), &value));
		return value;
	}

	NInt32 ReadInt32()
	{
		NInt32 value;
		NCheck(NBinaryReaderReadInt32(GetHandle(), &value));
		return value;
	}

#ifndef N_NO_INT_64
	NUInt64 ReadUInt64()
	{
		NUInt64 value;
		NCheck(NBinaryReaderReadUInt64(GetHandle(), &value));
		return value;
	}

	NInt64 ReadInt64()
	{
		NInt64 value;
		NCheck(NBinaryReaderReadInt64(GetHandle(), &value));
		return value;
	}
#endif

#ifndef N_NO_FLOAT
	NSingle ReadSingle()
	{
		NSingle value;
		NCheck(NBinaryReaderReadSingle(GetHandle(), &value));
		return value;
	}

	NDouble ReadDouble()
	{
		NDouble value;
		NCheck(NBinaryReaderReadDouble(GetHandle(), &value));
		return value;
	}
#endif

	bool ReadBoolean()
	{
		NBoolean value;
		NCheck(NBinaryReaderReadBoolean(GetHandle(), &value));
		return value != 0;
	}

	NInt PeekChar()
	{
		NInt value;
		NCheck(NBinaryReaderPeekChar(GetHandle(), &value));
		return value;
	}

	NChar ReadChar()
	{
		NChar value;
		NCheck(NBinaryReaderReadChar(GetHandle(), &value));
		return value;
	}

	NSizeType ReadBytes(void * pBuffer, NSizeType bufferSize, bool readAll = false)
	{
		NSizeType sizeRead;
		NCheck(NBinaryReaderReadBytesDst(GetHandle(), pBuffer, bufferSize, readAll ? NTrue : NFalse, &sizeRead));
		return sizeRead;
	}

	NSizeType ReadBytes(const NBuffer & buffer, bool readAll = false)
	{
		NSizeType sizeRead;
		NCheck(NBinaryReaderReadBytesDstN(GetHandle(), buffer.GetHandle(), readAll ? NTrue : NFalse, &sizeRead));
		return sizeRead;
	}

	NBuffer ReadBytes(NSizeType size, bool readAll = false)
	{
		HNBuffer hBuffer;
		NCheck(NBinaryReaderReadBytesN(GetHandle(), size, readAll ? NTrue : NFalse, &hBuffer));
		return FromHandle<NBuffer>(hBuffer);
	}

	NInt ReadChars(NChar * arChars, NInt count, bool readAll = false)
	{
		NInt countRead;
		NCheck(NBinaryReaderReadCharsDst(GetHandle(), arChars, count, readAll ? NTrue : NFalse, &countRead));
		return countRead;
	}

	NChar * ReadChars(NInt count, NInt * pCharCount, bool readAll = false)
	{
		NChar * arChars;
		NCheck(NBinaryReaderReadChars(GetHandle(), count, readAll ? NTrue : NFalse, pCharCount, &arChars));
		return arChars;
	}

	NStream GetBaseStream()
	{
		HNStream hValue;
		NCheck(NBinaryReaderGetBaseStream(GetHandle(), &hValue));
		return FromHandle<NStream>(hValue, true);
	}

	NByteOrder GetByteOrder()
	{
		NByteOrder value;
		NCheck(NBinaryReaderGetByteOrder(GetHandle(), &value));
		return value;
	}

	NLong GetPosition()
	{
		NLong value;
		NCheck(NBinaryReaderGetPosition(GetHandle(), &value));
		return value;
	}

	void SetPosition(NLong value)
	{
		NCheck(NBinaryReaderSetPosition(GetHandle(), value));
	}
};

}}

#endif // !N_BINARY_READER_HPP_INCLUDED
