#ifndef BER_TLV_HPP_INCLUDED
#define BER_TLV_HPP_INCLUDED

#include <SmartCards/BerTag.hpp>
namespace Neurotec { namespace SmartCards
{
#include <SmartCards/BerTlv.h>
}}

namespace Neurotec { namespace SmartCards
{

class BerTlv : public NObject
{
	N_DECLARE_OBJECT_CLASS(BerTlv, NObject)

public:
	static NArrayWrapper<BerTlv> LoadMany(const ::Neurotec::IO::NBuffer & buffer, NUInt flags = 0, NSizeType * pSize = NULL)
	{
		HBerTlv * arhBerTlvs;
		NInt count;
		NCheck(BerTlvLoadManyFromMemoryN(buffer.GetHandle(), flags, pSize, &arhBerTlvs, &count));
		return NArrayWrapper<BerTlv>(arhBerTlvs, count);
	}

	static NArrayWrapper<BerTlv> LoadMany(const void * pBuffer, NSizeType bufferSize, NUInt flags = 0, NSizeType * pSize = NULL)
	{
		HBerTlv * arhBerTlvs;
		NInt count;
		NCheck(BerTlvLoadManyFromMemoryEx(pBuffer, bufferSize, flags, pSize, &arhBerTlvs, &count));
		return NArrayWrapper<BerTlv>(arhBerTlvs, count);
	}

	static BerTlv Create(BerTag tag, NUInt flags = 0)
	{
		HBerTlv handle;
		NCheck(BerTlvCreateEx(tag.GetValue(), flags, &handle));
		return FromHandle<BerTlv>(handle);
	}

	static BerTlv Create(const ::Neurotec::IO::NBuffer & buffer, NUInt flags = 0, NSizeType * pSize = NULL)
	{
		HBerTlv handle;
		NCheck(BerTlvCreateFromMemoryN(buffer.GetHandle(), flags, pSize, &handle));
		return FromHandle<BerTlv>(handle);
	}

	static BerTlv Create(const void * pBuffer, NSizeType bufferSize, NUInt flags = 0, NSizeType * pSize = NULL)
	{
		HBerTlv handle;
		NCheck(BerTlvCreateFromMemoryEx(pBuffer, bufferSize, flags, pSize, &handle));
		return FromHandle<BerTlv>(handle);
	}

	BerTag GetTag() const
	{
		BerTag_ value;
		NCheck(BerTlvGetTag(GetHandle(), &value));
		return BerTag(value);
	}

	NSizeType GetLength() const
	{
		NSizeType value;
		NCheck(BerTlvGetLength(GetHandle(), &value));
		return value;
	}

	N_DEPRECATED("method is deprecated, use GetMinLengthSize() instead.")
	NInt MinLengthSize() const
	{
		NInt value;
		NCheck(BerTlvGetMinLengthSize(GetHandle(), &value));
		return value;
	}

	NInt GetMinLengthSize() const
	{
		NInt value;
		NCheck(BerTlvGetMinLengthSize(GetHandle(), &value));
		return value;
	}

	void SetMinLengthSize(NInt value)
	{
		NCheck(BerTlvSetMinLengthSize(GetHandle(), value));
	}

	BerTlv GetOwner() const
	{
		return NObject::GetOwner<BerTlv>();
	}
};

}}

#endif // !BER_TLV_HPP_INCLUDED
