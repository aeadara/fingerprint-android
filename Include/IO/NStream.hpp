#ifndef N_STREAM_HPP_INCLUDED
#define N_STREAM_HPP_INCLUDED

#include <Core/NObject.hpp>
#include <IO/NBuffer.hpp>
#include <IO/NIOTypes.hpp>
namespace Neurotec { namespace IO
{
#include <IO/NStream.h>
}}

namespace Neurotec { namespace IO
{

class NStream : public NObject
{
	N_DECLARE_OBJECT_CLASS(NStream, NObject)

public:
	static NStream Synchronized(NStream & stream)
	{
		HNStream hValue;
		NCheck(NStreamSynchronized(stream.GetHandle(), &hValue));
		return FromHandle<NStream>(hValue);
	}

	static NStream GetNull()
	{
		HNStream hValue;
		NCheck(NStreamGetNull(&hValue));
		return FromHandle<NStream>(hValue, true);
	}

	void CopyTo(const NStream & dstStream)
	{
		NCheck(NStreamCopyTo(GetHandle(), dstStream.GetHandle()));
	}

	void CopyTo(const NStream & dstStream, NSizeType bufferSize)
	{
		NCheck(NStreamCopyToWithBufferSize(GetHandle(), dstStream.GetHandle(), bufferSize));
	}

	void Flush()
	{
		NCheck(NStreamFlush(GetHandle()));
	}

	NLong GetLength()
	{
		NLong value;
		NCheck(NStreamGetLength(GetHandle(), &value));
		return value;
	}

	void SetLength(NLong value)
	{
		NCheck(NStreamSetLength(GetHandle(), value));
	}

	void Seek(NLong offset, NSeekOrigin origin)
	{
		NCheck(NStreamSeek(GetHandle(), offset, origin));
	}

	NInt ReadByte()
	{
		NInt value;
		NCheck(NStreamReadByte(GetHandle(), &value));
		return value;
	}

	NSizeType Read(void * pBuffer, NSizeType bufferSize)
	{
		NSizeType sizeRead;
		NCheck(NStreamRead(GetHandle(), pBuffer, bufferSize, &sizeRead));
		return sizeRead;
	}

	NSizeType Read(const NBuffer & buffer)
	{
		NSizeType sizeRead;
		NCheck(NStreamReadN(GetHandle(), buffer.GetHandle(), &sizeRead));
		return sizeRead;
	}

	void WriteByte(NByte value)
	{
		NCheck(NStreamWriteByte(GetHandle(), value));
	}

	void Write(const void * pBuffer, NSizeType bufferSize)
	{
		NCheck(NStreamWrite(GetHandle(), pBuffer, bufferSize));
	}

	void Write(const NBuffer & buffer)
	{
		NCheck(NStreamWriteN(GetHandle(), buffer.GetHandle()));
	}

	bool CanRead()
	{
		NBool value;
		NCheck(NStreamCanRead(GetHandle(), &value));
		return value != 0;
	}

	bool CanWrite()
	{
		NBool value;
		NCheck(NStreamCanWrite(GetHandle(), &value));
		return value != 0;
	}

	bool CanSeek()
	{
		NBool value;
		NCheck(NStreamCanSeek(GetHandle(), &value));
		return value != 0;
	}

	NLong GetPosition()
	{
		NLong value;
		NCheck(NStreamGetPosition(GetHandle(), &value));
		return value;
	}

	void SetPosition(NLong value)
	{
		NCheck(NStreamSetPosition(GetHandle(), value));
	}
};

}}

#endif // !N_STREAM_HPP_INCLUDED
