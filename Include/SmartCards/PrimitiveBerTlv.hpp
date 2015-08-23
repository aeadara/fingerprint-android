#ifndef PRIMITIVE_BER_TLV_HPP_INCLUDED
#define PRIMITIVE_BER_TLV_HPP_INCLUDED

#include <SmartCards/BerTlv.hpp>
namespace Neurotec { namespace SmartCards
{
#include <SmartCards/PrimitiveBerTlv.h>
}}

namespace Neurotec { namespace SmartCards
{

class PrimitiveBerTlv : public BerTlv
{
	N_DECLARE_OBJECT_CLASS(PrimitiveBerTlv, BerTlv)

public:
	::Neurotec::IO::NBuffer GetValue() const
	{
		return GetObject<HandleType, ::Neurotec::IO::NBuffer>(PrimitiveBerTlvGetValueN, true);
	}

	bool GetValueAsBoolean() const
	{
		NBool value;
		NCheck(PrimitiveBerTlvGetValueAsBoolean(GetHandle(), &value));
		return value != 0;
	}

	NInt GetValueAsInteger() const
	{
		NInt value;
		NCheck(PrimitiveBerTlvGetValueAsInteger(GetHandle(), &value));
		return value;
	}

	NByte GetValueAsByte() const
	{
		NByte value;
		NCheck(PrimitiveBerTlvGetValueAsByte(GetHandle(), &value));
		return value;
	}

	NSByte GetValueAsSByte() const
	{
		NSByte value;
		NCheck(PrimitiveBerTlvGetValueAsSByte(GetHandle(), &value));
		return value;
	}

	NUShort GetValueAsUInt16() const
	{
		NUShort value;
		NCheck(PrimitiveBerTlvGetValueAsUInt16(GetHandle(), &value));
		return value;
	}

	NShort GetValueAsInt16() const
	{
		NShort value;
		NCheck(PrimitiveBerTlvGetValueAsInt16(GetHandle(), &value));
		return value;
	}

	NUInt GetValueAsUInt32() const
	{
		NUInt value;
		NCheck(PrimitiveBerTlvGetValueAsUInt32(GetHandle(), &value));
		return value;
	}

	NInt GetValueAsInt32() const
	{
		NInt value;
		NCheck(PrimitiveBerTlvGetValueAsInt32(GetHandle(), &value));
		return value;
	}

	void SetValue(const ::Neurotec::IO::NBuffer & value)
	{
		SetObject(PrimitiveBerTlvSetValueN, value);
	}

	void SetValue(const void * pValue, NSizeType valueSize, bool copy = true)
	{
		NCheck(PrimitiveBerTlvSetValueEx(GetHandle(), pValue, valueSize, copy ? NTrue : NFalse));
	}

	void SetValue(bool value)
	{
		NCheck(PrimitiveBerTlvSetValueAsBoolean(GetHandle(), value ? NTrue : NFalse));
	}

	void SetValueAsInteger(NInt value)
	{
		NCheck(PrimitiveBerTlvSetValueAsInteger(GetHandle(), value));
	}

	void SetValue(NByte value)
	{
		NCheck(PrimitiveBerTlvSetValueAsByte(GetHandle(), value));
	}

	void SetValue(NSByte value)
	{
		NCheck(PrimitiveBerTlvSetValueAsSByte(GetHandle(), value));
	}

	void SetValue(NUInt16 value)
	{
		NCheck(PrimitiveBerTlvSetValueAsUInt16(GetHandle(), value));
	}

	void SetValue(NInt16 value)
	{
		NCheck(PrimitiveBerTlvSetValueAsInt16(GetHandle(), value));
	}

	void SetValue(NUInt32 value)
	{
		NCheck(PrimitiveBerTlvSetValueAsUInt32(GetHandle(), value));
	}

	void SetValue(NInt32 value)
	{
		NCheck(PrimitiveBerTlvSetValueAsInt32(GetHandle(), value));
	}
};

}}

#endif // !PRIMITIVE_BER_TLV_HPP_INCLUDED
