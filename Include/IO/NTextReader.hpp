#ifndef N_TEXT_READER_HPP_INCLUDED
#define N_TEXT_READER_HPP_INCLUDED

#include <Core/NObject.hpp>
namespace Neurotec { namespace IO
{
#include <IO/NTextReader.h>
}}

namespace Neurotec { namespace IO
{

class NTextReader : public NObject
{
	N_DECLARE_OBJECT_CLASS(NTextReader, NObject)

public:
	static NTextReader Synchronized(NTextReader & reader)
	{
		HNTextReader hValue;
		NCheck(NTextReaderSynchronized(reader.GetHandle(), &hValue));
		return FromHandle<NTextReader>(hValue);
	}

	static NTextReader GetNull()
	{
		HNTextReader hValue;
		NCheck(NTextReaderGetNull(&hValue));
		return FromHandle<NTextReader>(hValue, true);
	}

	NInt PeekChar()
	{
		NInt value;
		NCheck(NTextReaderPeekChar(GetHandle(), &value));
		return value;
	}

	NInt ReadChar()
	{
		NInt value;
		NCheck(NTextReaderReadChar(GetHandle(), &value));
		return value;
	}

	NInt ReadChars(NChar * szBuffer, NInt count)
	{
		NInt charsRead;
		NCheck(NTextReaderReadChars(GetHandle(), szBuffer, count, &charsRead));
		return charsRead;
	}

	NString ReadLine()
	{
		HNString hValue;
		NCheck(NTextReaderReadLine(GetHandle(), &hValue));
		return NString(hValue, true);
	}

	NString ReadToEnd()
	{
		HNString hValue;
		NCheck(NTextReaderReadToEnd(GetHandle(), &hValue));
		return NString(hValue, true);
	}
};

}}

#endif // !N_TEXT_READER_HPP_INCLUDED
