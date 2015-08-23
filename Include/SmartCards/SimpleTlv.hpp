#ifndef SIMPLE_TLV_HPP_INCLUDED
#define SIMPLE_TLV_HPP_INCLUDED

#include <SmartCards/SimpleTag.hpp>
namespace Neurotec { namespace SmartCards
{
#include <SmartCards/SimpleTlv.h>
}}

namespace Neurotec { namespace SmartCards
{

class SimpleTlv : public NObject
{
	N_DECLARE_OBJECT_CLASS(SimpleTlv, NObject)

private:
	static HSimpleTlv Create(SimpleTag tag, NUInt flags)
	{
		HSimpleTlv handle;
		NCheck(SimpleTlvCreateEx(tag.GetValue(), flags, &handle));
		return handle;
	}

	static HSimpleTlv Create(const ::Neurotec::IO::NBuffer & buffer, NUInt flags, NSizeType * pSize)
	{
		HSimpleTlv handle;
		NCheck(SimpleTlvCreateFromMemoryN(buffer.GetHandle(), flags, pSize, &handle));
		return handle;
	}

	static HSimpleTlv Create(const void * pBuffer, NSizeType bufferSize, NUInt flags, NSizeType * pSize)
	{
		HSimpleTlv handle;
		NCheck(SimpleTlvCreateFromMemoryEx(pBuffer, bufferSize, flags, pSize, &handle));
		return handle;
	}

public:
	static NArrayWrapper<SimpleTlv> LoadMany(const ::Neurotec::IO::NBuffer & buffer, NUInt flags = 0, NSizeType * pSize = NULL)
	{
		HSimpleTlv * arhSimpleTlvs;
		NInt count;
		NCheck(SimpleTlvLoadManyFromMemoryN(buffer.GetHandle(), flags, pSize, &arhSimpleTlvs, &count));
		return NArrayWrapper<SimpleTlv>(arhSimpleTlvs, count);
	}

	static NArrayWrapper<SimpleTlv> LoadMany(const void * pBuffer, NSizeType bufferSize, NUInt flags = 0, NSizeType * pSize = NULL)
	{
		HSimpleTlv * arhSimpleTlvs;
		NInt count;
		NCheck(SimpleTlvLoadManyFromMemoryEx(pBuffer, bufferSize, flags, pSize, &arhSimpleTlvs, &count));
		return NArrayWrapper<SimpleTlv>(arhSimpleTlvs, count);
	}

	explicit SimpleTlv(SimpleTag tag, NUInt flags = 0)
		: NObject(Create(tag, flags), true)
	{
	}

	explicit SimpleTlv(const ::Neurotec::IO::NBuffer & buffer, NUInt flags = 0, NSizeType * pSize = NULL)
		: NObject(Create(buffer, flags, pSize), true)
	{
	}

	SimpleTlv(const void * pBuffer, NSizeType bufferSize, NUInt flags = 0, NSizeType * pSize = NULL)
		: NObject(Create(pBuffer, bufferSize, flags, pSize), true)
	{
	}

	SimpleTag GetTag() const
	{
		SimpleTag_ value;
		NCheck(SimpleTlvGetTag(GetHandle(), &value));
		return SimpleTag(value);
	}

	NSizeType GetLength() const
	{
		NSizeType value;
		NCheck(SimpleTlvGetLength(GetHandle(), &value));
		return value;
	}

	bool GetUseThreeByteLengthAlways() const
	{
		NBool value;
		NCheck(SimpleTlvGetUseThreeByteLengthAlways(GetHandle(), &value));
		return value != 0;
	}

	void SetUseThreeByteLengthAlways(bool value)
	{
		NCheck(SimpleTlvSetUseThreeByteLengthAlways(GetHandle(), value ? NTrue : NFalse));
	}

	::Neurotec::IO::NBuffer GetValue() const
	{
		return GetObject<HandleType, ::Neurotec::IO::NBuffer>(SimpleTlvGetValueN, true);
	}

	void SetValue(const ::Neurotec::IO::NBuffer & value)
	{
		SetObject(SimpleTlvSetValueN, value);
	}

	void SetValue(const void * pValue, NSizeType valueSize, bool copy = true)
	{
		NCheck(SimpleTlvSetValueEx(GetHandle(), pValue, valueSize, copy ? NTrue : NFalse));
	}
};

}}

#endif // !SIMPLE_TLV_HPP_INCLUDED
