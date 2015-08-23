#ifndef N_BUFFERED_STREAM_HPP_INCLUDED
#define N_BUFFERED_STREAM_HPP_INCLUDED

#include <IO/NStream.hpp>
namespace Neurotec { namespace IO
{
#include <IO/NBufferedStream.h>
}}

namespace Neurotec { namespace IO
{

class NBufferedStream : public NStream
{
	N_DECLARE_OBJECT_CLASS(NBufferedStream, NStream)

private:
	static HNBufferedStream Create(const NStream & innerStream)
	{
		HNBufferedStream handle;
		NCheck(NBufferedStreamCreate(innerStream.GetHandle(), &handle));
		return handle;
	}

	static HNBufferedStream Create(const NStream & innerStream, NSizeType bufferSize)
	{
		HNBufferedStream handle;
		NCheck(NBufferedStreamCreateWithBufferSize(innerStream.GetHandle(), bufferSize, &handle));
		return handle;
	}

public:
	NBufferedStream(const NStream & innerStream)
		: NStream(Create(innerStream), true)
	{
	}

	NBufferedStream(const NStream & innerStream, NSizeType bufferSize)
		: NStream(Create(innerStream, bufferSize), true)
	{
	}
};

}}

#endif // !N_BUFFERED_STREAM_HPP_INCLUDED
