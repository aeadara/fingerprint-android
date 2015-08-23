#ifndef N_STRING_READER_HPP_INCLUDED
#define N_STRING_READER_HPP_INCLUDED

#include <IO/NTextReader.hpp>
namespace Neurotec { namespace IO
{
#include <IO/NStringReader.h>
}}

namespace Neurotec { namespace IO
{

class NStringReader : public NTextReader
{
	N_DECLARE_OBJECT_CLASS(NStringReader, NTextReader)

private:
	static HNStringReader Create(const NStringWrapper & value)
	{
		HNStringReader handle;
		NCheck(NStringReaderCreateN(value.GetHandle(), &handle));
		return handle;
	}

	static HNStringReader Create(const NChar * arValue, NInt valueLength)
	{
		HNStringReader handle;
		NCheck(NStringReaderCreateFromChars(arValue, valueLength, &handle));
		return handle;
	}

public:
	explicit NStringReader(const NStringWrapper & value)
		: NTextReader(Create(value), true)
	{
	}

	NStringReader(const NChar * arValue, NInt valueLength)
		: NTextReader(Create(arValue, valueLength), true)
	{
	}
};

}}

#endif // !N_STRING_READER_HPP_INCLUDED
