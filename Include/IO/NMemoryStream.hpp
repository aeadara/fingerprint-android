#ifndef N_MEMORY_STREAM_HPP_INCLUDED
#define N_MEMORY_STREAM_HPP_INCLUDED

#include <IO/NStream.hpp>
namespace Neurotec { namespace IO
{
#include <IO/NMemoryStream.h>
}}

namespace Neurotec { namespace IO
{

class NMemoryStream : public NStream
{
	N_DECLARE_OBJECT_CLASS(NMemoryStream, NStream)

private:
	static HNMemoryStream Create()
	{
		HNMemoryStream handle;
		NCheck(NMemoryStreamCreate(&handle));
		return handle;
	}

	static HNMemoryStream Create(NSizeType capacity)
	{
		HNMemoryStream handle;
		NCheck(NMemoryStreamCreateWithCapacity(capacity, &handle));
		return handle;
	}

	static HNMemoryStream Create(const NBuffer & buffer, NFileAccess access, bool bufferExposable)
	{
		HNMemoryStream handle;
		NCheck(NMemoryStreamCreateFromBufferN(buffer.GetHandle(), access, bufferExposable ? NTrue : NFalse, &handle));
		return handle;
	}

	static HNMemoryStream Create(void * pBuffer, NSizeType bufferSize, NFileAccess access, bool bufferExposable)
	{
		HNMemoryStream handle;
		NCheck(NMemoryStreamCreateFromBuffer(pBuffer, bufferSize, access, bufferExposable ? NTrue : NFalse, &handle));
		return handle;
	}

	static HNMemoryStream Create(const void * pBuffer, NSizeType bufferSize)
	{
		HNMemoryStream handle;
		NCheck(NMemoryStreamCreateFromBufferForRead(pBuffer, bufferSize, &handle));
		return handle;
	}

public:
	NMemoryStream()
		: NStream(Create(), true)
	{
	}

	explicit NMemoryStream(NSizeType capacity)
		: NStream(Create(capacity), true)
	{
	}

	explicit NMemoryStream(const NBuffer & buffer, NFileAccess access = nfaRead, bool bufferExposable = false)
		:NStream (Create(buffer, access, bufferExposable), true)
	{
	}

	NMemoryStream(void * pBuffer, NSizeType bufferSize, NFileAccess access = nfaRead, bool bufferExposable = false)
		: NStream(Create(pBuffer, bufferSize, access, bufferExposable), true)
	{
	}

	NMemoryStream(const void * pBuffer, NSizeType bufferSize)
		: NStream(Create(pBuffer, bufferSize), true)
	{
	}

	NBuffer GetBuffer()
	{
		HNBuffer hValue;
		NCheck(NMemoryStreamGetBuffer(GetHandle(), &hValue));
		return FromHandle<NBuffer>(hValue);
	}

	void WriteTo(const NStream & dstStream)
	{
		NCheck(NMemoryStreamWriteTo(GetHandle(), dstStream.GetHandle()));
	}

	NSizeType GetPosition()
	{
		NSizeType value;
		NCheck(NMemoryStreamGetCapacity(GetHandle(), &value));
		return value;
	}

	void SetPosition(NSizeType value)
	{
		NCheck(NMemoryStreamSetCapacity(GetHandle(), value));
	}

	void * GetPositionPtr()
	{
		void * value;
		NCheck(NMemoryStreamGetPositionPtr(GetHandle(), &value));
		return value;
	}

	void SetPositionPtr(void * value)
	{
		NCheck(NMemoryStreamSetPositionPtr(GetHandle(), value));
	}

	void * ToPtr(NSizeType * pBufferSize)
	{
		void * pBuffer;
		NCheck(NMemoryStreamToPtr(GetHandle(), pBufferSize, &pBuffer));
		return pBuffer;
	}
};

}}

#endif // !N_MEMORY_STREAM_HPP_INCLUDED
