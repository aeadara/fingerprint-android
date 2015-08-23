#ifndef N_STREAM_READER_HPP_INCLUDED
#define N_STREAM_READER_HPP_INCLUDED

#include <IO/NTextReader.hpp>
#include <Text/NEncoding.hpp>
namespace Neurotec { namespace IO
{
using ::Neurotec::Text::NEncoding;
#include <IO/NStreamReader.h>
}}

namespace Neurotec { namespace IO
{

class NStreamReader : public NTextReader
{
	N_DECLARE_OBJECT_CLASS(NStreamReader, NTextReader)

private:
	static HNStreamReader Create(const NStream & stream)
	{
		HNStreamReader handle;
		NCheck(NStreamReaderCreate(stream.GetHandle(), &handle));
		return handle;
	}

	static HNStreamReader Create(const NStream & stream, NEncoding encoding, bool detectEncodingFromByteOrderMarks)
	{
		HNStreamReader handle;
		NCheck(NStreamReaderCreateWithEncoding(stream.GetHandle(), encoding, detectEncodingFromByteOrderMarks ? NTrue : NFalse, &handle));
		return handle;
	}

	static HNStreamReader Create(const NStream & stream, NEncoding encoding, bool detectEncodingFromByteOrderMarks, NSizeType bufferSize)
	{
		HNStreamReader handle;
		NCheck(NStreamReaderCreateWithEncodingAndBufferSize(stream.GetHandle(), encoding, detectEncodingFromByteOrderMarks ? NTrue : NFalse, bufferSize, &handle));
		return handle;
	}

	static HNStreamReader Create(const NStringWrapper & path)
	{
		HNStreamReader handle;
		NCheck(NStreamReaderCreateFromFileN(path.GetHandle(), &handle));
		return handle;
	}

	static HNStreamReader Create(const NStringWrapper & path, NEncoding encoding, bool detectEncodingFromByteOrderMarks)
	{
		HNStreamReader handle;
		NCheck(NStreamReaderCreateFromFileWithEncodingN(path.GetHandle(), encoding, detectEncodingFromByteOrderMarks ? NTrue : NFalse, &handle));
		return handle;
	}

	static HNStreamReader Create(const NStringWrapper & path, NEncoding encoding, bool detectEncodingFromByteOrderMarks, NSizeType bufferSize)
	{
		HNStreamReader handle;
		NCheck(NStreamReaderCreateFromFileWithEncodingAndBufferSizeN(path.GetHandle(), encoding, detectEncodingFromByteOrderMarks ? NTrue : NFalse, bufferSize, &handle));
		return handle;
	}

public:
	static NStreamReader GetNull()
	{
		HNStreamReader hValue;
		NCheck(NStreamReaderGetNull(&hValue));
		return FromHandle<NStreamReader>(hValue, true);
	}

	explicit NStreamReader(const NStream & stream)
		: NTextReader(Create(stream), true)
	{
	}

	NStreamReader(const NStream & stream, NEncoding encoding, bool detectEncodingFromByteOrderMarks = true)
		: NTextReader(Create(stream, encoding, detectEncodingFromByteOrderMarks), true)
	{
	}

	NStreamReader(const NStream & stream, NEncoding encoding, bool detectEncodingFromByteOrderMarks, NSizeType bufferSize)
		: NTextReader(Create(stream, encoding, detectEncodingFromByteOrderMarks, bufferSize), true)
	{
	}

	explicit NStreamReader(const NStringWrapper & path)
		: NTextReader(Create(path), true)
	{
	}

	NStreamReader(const NStringWrapper & path, NEncoding encoding, bool detectEncodingFromByteOrderMarks = true)
		: NTextReader(Create(path, encoding, detectEncodingFromByteOrderMarks), true)
	{
	}

	NStreamReader(const NStringWrapper & path, NEncoding encoding, bool detectEncodingFromByteOrderMarks, NSizeType bufferSize)
		: NTextReader(Create(path, encoding, detectEncodingFromByteOrderMarks, bufferSize), true)
	{
	}

	::Neurotec::Text::NEncoding GetEncoding() const
	{
		::Neurotec::Text::NEncoding value;
		NCheck(NStreamReaderGetCurrentEncoding(GetHandle(), &value));
		return value;
	}

	NStream GetBaseStream() const
	{
		HNStream hValue;
		NCheck(NStreamReaderGetBaseStream(GetHandle(), &hValue));
		return FromHandle<NStream>(hValue, true);
	}

	bool IsEndOfStream() const
	{
		NBool value;
		NCheck(NStreamReaderIsEndOfStream(GetHandle(), &value));
		return value != 0;
	}
};

}}

#endif // !N_STREAM_READER_HPP_INCLUDED
