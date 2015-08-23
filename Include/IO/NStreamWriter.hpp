#ifndef N_STREAM_WRITER_HPP_INCLUDED
#define N_STREAM_WRITER_HPP_INCLUDED

#include <IO/NTextWriter.hpp>
namespace Neurotec { namespace IO
{
#include <IO/NStreamWriter.h>
}}

namespace Neurotec { namespace IO
{

class NStreamWriter : public NTextWriter
{
	N_DECLARE_OBJECT_CLASS(NStreamWriter, NTextWriter)

private:
	static HNStreamWriter Create(const NStream & stream)
	{
		HNStreamWriter handle;
		NCheck(NStreamWriterCreate(stream.GetHandle(), &handle));
		return handle;
	}

	static HNStreamWriter Create(const NStream & stream, NEncoding encoding)
	{
		HNStreamWriter handle;
		NCheck(NStreamWriterCreateWithEncoding(stream.GetHandle(), encoding, &handle));
		return handle;
	}

	static HNStreamWriter Create(const NStream & stream, NEncoding encoding, NSizeType bufferSize)
	{
		HNStreamWriter handle;
		NCheck(NStreamWriterCreateWithEncodingAndBufferSize(stream.GetHandle(), encoding, bufferSize, &handle));
		return handle;
	}

	static HNStreamWriter Create(const NStringWrapper & path, bool append)
	{
		HNStreamWriter handle;
		NCheck(NStreamWriterCreateFromFileN(path.GetHandle(), append ? NTrue : NFalse, &handle));
		return handle;
	}

	static HNStreamWriter Create(const NStringWrapper & path, bool append, NEncoding encoding)
	{
		HNStreamWriter handle;
		NCheck(NStreamWriterCreateFromFileWithEncodingN(path.GetHandle(), append ? NTrue : NFalse, encoding, &handle));
		return handle;
	}

	static HNStreamWriter Create(const NStringWrapper & path, bool append, NEncoding encoding, NSizeType bufferSize)
	{
		HNStreamWriter handle;
		NCheck(NStreamWriterCreateFromFileWithEncodingAndBufferSizeN(path.GetHandle(), append ? NTrue : NFalse, encoding, bufferSize, &handle));
		return handle;
	}

public:
	static NStreamWriter GetNull()
	{
		HNStreamWriter hValue;
		NCheck(NStreamWriterGetNull(&hValue));
		return FromHandle<NStreamWriter>(hValue, true);
	}

	explicit NStreamWriter(const NStream & stream)
		: NTextWriter(Create(stream), true)
	{
	}

	NStreamWriter(const NStream & stream, NEncoding encoding)
		: NTextWriter(Create(stream, encoding), true)
	{
	}

	NStreamWriter(const NStream & stream, NEncoding encoding, NSizeType bufferSize)
		: NTextWriter(Create(stream, encoding, bufferSize), true)
	{
	}

	explicit NStreamWriter(const NStringWrapper & path, bool append = false)
		: NTextWriter(Create(path, append), true)
	{
	}

	NStreamWriter(const NStringWrapper & path, bool append, NEncoding encoding)
		: NTextWriter(Create(path, append, encoding), true)
	{
	}

	NStreamWriter(const NStringWrapper & path, bool append, NEncoding encoding, NSizeType bufferSize)
		: NTextWriter(Create(path, append, encoding, bufferSize), true)
	{
	}

	NStream GetBaseStream() const
	{
		HNStream hValue;
		NCheck(NStreamWriterGetBaseStream(GetHandle(), &hValue));
		return FromHandle<NStream>(hValue, true);
	}

	bool GetAutoFlush() const
	{
		NBool value;
		NCheck(NStreamWriterGetAutoFlush(GetHandle(), &value));
		return value != 0;
	}

	void SetAutoFlush(bool value)
	{
		NCheck(NStreamWriterSetAutoFlush(GetHandle(), value ? NTrue : NFalse));
	}
};

}}

#endif // !N_STREAM_WRITER_HPP_INCLUDED
