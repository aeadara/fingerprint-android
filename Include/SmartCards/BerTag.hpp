#ifndef BER_TAG_HPP_INCLUDED
#define BER_TAG_HPP_INCLUDED

#include <IO/NBuffer.hpp>
namespace Neurotec { namespace SmartCards
{
#include <SmartCards/BerTag.h>
}}

N_DEFINE_ENUM_TYPE_TRAITS(Neurotec::SmartCards, BerTagClass)
N_DEFINE_ENUM_TYPE_TRAITS(Neurotec::SmartCards, BerTagEncoding)

namespace Neurotec { namespace SmartCards
{

#undef BER_TAG_END_OF_CONTENTS
#undef BER_TAG_BOOLEAN
#undef BER_TAG_INTEGER
#undef BER_TAG_BIT_STRING
#undef BER_TAG_OCTET_STRING
#undef BER_TAG_NULL
#undef BER_TAG_OBJECT_IDENTIFIER
#undef BER_TAG_OBJECT_DESCRIPTOR
#undef BER_TAG_EXTERNAL
#undef BER_TAG_INSTANCE_OF
#undef BER_TAG_REAL
#undef BER_TAG_ENUMERATED
#undef BER_TAG_EMBEDDED_PDV
#undef BER_TAG_UTF8_STRING
#undef BER_TAG_RELATIVE_OBJECT_IDENTIFIER
#undef BER_TAG_SEQUENCE
#undef BER_TAG_SEQUENCE_OF
#undef BER_TAG_SET
#undef BER_TAG_SET_OF
#undef BER_TAG_NUMERIC_STRING
#undef BER_TAG_PRINTABLE_STRING
#undef BER_TAG_TELETEX_STRING
#undef BER_TAG_T61_STRING
#undef BER_TAG_VIDEOTEX_STRING
#undef BER_TAG_IA5_STRING
#undef BER_TAG_UTC_TIME
#undef BER_TAG_GENERALIZED_TIME
#undef BER_TAG_GRAPHIC_STRING
#undef BER_TAG_VISIBLE_STRING
#undef BER_TAG_ISO646_STRING
#undef BER_TAG_GENERAL_STRING
#undef BER_TAG_UNIVERSAL_STRING
#undef BER_TAG_CHARACTER_STRING
#undef BER_TAG_BMP_STRING

class BerTag
{
	N_DECLARE_BASIC_CLASS(BerTag)

public:
	static NType BerTagClassNativeTypeOf()
	{
		return NObject::GetObject<NType>(N_TYPE_OF(BerTagClass), true);
	}

	static NType BerTagEncodingNativeTypeOf()
	{
		return NObject::GetObject<NType>(N_TYPE_OF(BerTagEncoding), true);
	}

	static BerTag Read(const ::Neurotec::IO::NBuffer & buffer, NSizeType * pSize = NULL)
	{
		BerTag_ tag;
		NCheck(BerTagReadN(buffer.GetHandle(), pSize, &tag));
		return BerTag(tag);
	}

	static BerTag Read(const void * pBuffer, NSizeType bufferSize, NSizeType * pSize = NULL)
	{
		BerTag_ tag;
		NCheck(BerTagReadEx(pBuffer, bufferSize, pSize, &tag));
		return BerTag(tag);
	}

	BerTag(BerTagClass cls, BerTagEncoding encoding, NInt number)
	{
		NCheck(BerTagCreate(cls, encoding, number, &value));
	}

	bool IsValid(bool ffIsValidForTheFirstByte = false) const
	{
		return BerTagIsValid(value, ffIsValidForTheFirstByte ? NTrue : NFalse) != 0;
	}

	NSizeType Write(const ::Neurotec::IO::NBuffer & buffer) const
	{
		NSizeType size;
		NCheck(BerTagWriteN(value, buffer.GetHandle(), &size));
		return size;
	}

	NSizeType Write(void * pBuffer, NSizeType bufferSize) const
	{
		NSizeType size;
		NCheck(BerTagWrite(value, pBuffer, bufferSize, &size));
		return size;
	}

	::Neurotec::IO::NBuffer Save() const
	{
		HNBuffer hBuffer;
		NCheck(BerTagSaveToMemoryN(value, &hBuffer));
		return NObject::FromHandle< ::Neurotec::IO::NBuffer>(hBuffer);
	}

	NString ToString(const NStringWrapper & format = NString()) const
	{
		HNString hValue;
		NCheck(BerTagToStringN(value, format.GetHandle(), &hValue));
		return NString(hValue, true);
	}

	BerTagClass GetClass() const
	{
		return BerTagGetClass(value);
	}

	BerTagEncoding GetEncoding() const
	{
		return BerTagGetEncoding(value);
	}

	NInt GetNumber() const
	{
		return BerTagGetNumber(value);
	}

	NSizeType GetLength() const
	{
		return BerTagGetLength(value);
	}
};

const BerTag BER_TAG_END_OF_CONTENTS(0);
const BerTag BER_TAG_BOOLEAN(1);
const BerTag BER_TAG_INTEGER(2);
const BerTag BER_TAG_BIT_STRING(3);
const BerTag BER_TAG_OCTET_STRING(4);
const BerTag BER_TAG_NULL(5);
const BerTag BER_TAG_OBJECT_IDENTIFIER(6);
const BerTag BER_TAG_OBJECT_DESCRIPTOR(7);
const BerTag BER_TAG_EXTERNAL(8);
const BerTag BER_TAG_INSTANCE_OF(8);
const BerTag BER_TAG_REAL(9);
const BerTag BER_TAG_ENUMERATED(10);
const BerTag BER_TAG_EMBEDDED_PDV(11);
const BerTag BER_TAG_UTF8_STRING(12);
const BerTag BER_TAG_RELATIVE_OBJECT_IDENTIFIER(13);
const BerTag BER_TAG_SEQUENCE(16);
const BerTag BER_TAG_SEQUENCE_OF(16);
const BerTag BER_TAG_SET(17);
const BerTag BER_TAG_SET_OF(17);
const BerTag BER_TAG_NUMERIC_STRING(18);
const BerTag BER_TAG_PRINTABLE_STRING(19);
const BerTag BER_TAG_TELETEX_STRING(20);
const BerTag BER_TAG_T61_STRING(20);
const BerTag BER_TAG_VIDEOTEX_STRING(21);
const BerTag BER_TAG_IA5_STRING(22);
const BerTag BER_TAG_UTC_TIME(23);
const BerTag BER_TAG_GENERALIZED_TIME(24);
const BerTag BER_TAG_GRAPHIC_STRING(25);
const BerTag BER_TAG_VISIBLE_STRING(26);
const BerTag BER_TAG_ISO646_STRING(26);
const BerTag BER_TAG_GENERAL_STRING(27);
const BerTag BER_TAG_UNIVERSAL_STRING(28);
const BerTag BER_TAG_CHARACTER_STRING(29);
const BerTag BER_TAG_BMP_STRING(30);

}}

#endif // !BER_TAG_HPP_INCLUDED
