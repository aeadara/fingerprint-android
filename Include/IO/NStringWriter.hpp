#ifndef N_STRING_WRITER_HPP_INCLUDED
#define N_STRING_WRITER_HPP_INCLUDED

#include <IO/NTextWriter.hpp>
#include <Text/NStringBuilder.hpp>
namespace Neurotec { namespace IO
{
#include <IO/NStringWriter.h>
}}

namespace Neurotec { namespace IO
{

class NStringWriter : public NTextWriter
{
	N_DECLARE_OBJECT_CLASS(NStringWriter, NTextWriter)

private:
	static HNStringWriter Create()
	{
		HNStringWriter handle;
		NCheck(NStringWriterCreate(&handle));
		return handle;
	}

	static HNStringWriter Create(NInt capacity)
	{
		HNStringWriter handle;
		NCheck(NStringWriterCreateWithCapacity(capacity, &handle));
		return handle;
	}

	static HNStringWriter Create(NInt capacity, NInt maxCapacity, NInt growthDelta)
	{
		HNStringWriter handle;
		NCheck(NStringWriterCreateEx(capacity, maxCapacity, growthDelta, &handle));
		return handle;
	}

public:
	NStringWriter()
		: NTextWriter(Create(), true)
	{
	}

	explicit NStringWriter(NInt capacity)
		: NTextWriter(Create(capacity), true)
	{
	}

	NStringWriter(NInt capacity, NInt maxCapacity, NInt growthDelta)
		: NTextWriter(Create(capacity, maxCapacity, growthDelta), true)
	{
	}

	NString DetachString()
	{
		HNString hValue;
		NCheck(NStringWriterDetachString(GetHandle(), &hValue));
		return NString(hValue, true);
	}
};

}}

#endif // !N_STRING_WRITER_HPP_INCLUDED
