#ifndef AN_TYPE_99_RECORD_HPP_INCLUDED
#define AN_TYPE_99_RECORD_HPP_INCLUDED

#include <Biometrics/Standards/ANAsciiBinaryRecord.hpp>
namespace Neurotec { namespace Biometrics { namespace Standards
{
#include <Biometrics/Standards/ANType99Record.h>
}}}

N_DEFINE_ENUM_TYPE_TRAITS(Neurotec::Biometrics::Standards, ANBiometricType)

namespace Neurotec { namespace Biometrics { namespace Standards
{

#undef AN_TYPE_99_RECORD_FIELD_LEN
#undef AN_TYPE_99_RECORD_FIELD_IDC
#undef AN_TYPE_99_RECORD_FIELD_SRC
#undef AN_TYPE_99_RECORD_FIELD_BCD

#undef AN_TYPE_99_RECORD_FIELD_HDV
#undef AN_TYPE_99_RECORD_FIELD_BTY
#undef AN_TYPE_99_RECORD_FIELD_BDQ
#undef AN_TYPE_99_RECORD_FIELD_BFO
#undef AN_TYPE_99_RECORD_FIELD_BFT

#undef AN_TYPE_99_RECORD_FIELD_UDF_FROM
#undef AN_TYPE_99_RECORD_FIELD_UDF_TO

#undef AN_TYPE_99_RECORD_FIELD_BDB

#undef AN_TYPE_99_RECORD_HEADER_VERSION_1_0
#undef AN_TYPE_99_RECORD_HEADER_VERSION_1_1

const NInt AN_TYPE_99_RECORD_FIELD_LEN = AN_RECORD_FIELD_LEN;
const NInt AN_TYPE_99_RECORD_FIELD_IDC = AN_RECORD_FIELD_IDC;
const NInt AN_TYPE_99_RECORD_FIELD_SRC = AN_ASCII_BINARY_RECORD_FIELD_SRC;
const NInt AN_TYPE_99_RECORD_FIELD_BCD = AN_ASCII_BINARY_RECORD_FIELD_DAT;

const NInt AN_TYPE_99_RECORD_FIELD_HDV = 100;
const NInt AN_TYPE_99_RECORD_FIELD_BTY = 101;
const NInt AN_TYPE_99_RECORD_FIELD_BDQ = 102;
const NInt AN_TYPE_99_RECORD_FIELD_BFO = 103;
const NInt AN_TYPE_99_RECORD_FIELD_BFT = 104;

const NInt AN_TYPE_99_RECORD_FIELD_UDF_FROM = AN_ASCII_BINARY_RECORD_FIELD_UDF_FROM;
const NInt AN_TYPE_99_RECORD_FIELD_UDF_TO = AN_ASCII_BINARY_RECORD_FIELD_UDF_TO;

const NInt AN_TYPE_99_RECORD_FIELD_BDB = AN_RECORD_FIELD_DATA;

const NVersion AN_TYPE_99_RECORD_HEADER_VERSION_1_0(0x0100);
const NVersion AN_TYPE_99_RECORD_HEADER_VERSION_1_1(0x0101);

class ANType99Record : public ANAsciiBinaryRecord
{
	N_DECLARE_OBJECT_CLASS(ANType99Record, ANAsciiBinaryRecord)

public:
	static NType ANBiometricTypeNativeTypeOf()
	{
		return NObject::GetObject<NType>(N_TYPE_OF(ANBiometricType), true);
	}

	NVersion GetHeaderVersion() const
	{
		NVersion_ value;
		NCheck(ANType99RecordGetHeaderVersion(GetHandle(), &value));
		return NVersion(value);
	}

	ANBiometricType GetBiometricType() const
	{
		ANBiometricType value;
		NCheck(ANType99RecordGetBiometricType(GetHandle(), &value));
		return value;
	}

	bool GetBiometricDataQuality(ANQualityMetric * pValue) const
	{
		NBool hasValue;
		NCheck(ANType99RecordGetBiometricDataQuality(GetHandle(), pValue, &hasValue));
		return hasValue != 0;
	}

	void SetBiometricDataQuality(const ANQualityMetric * pValue)
	{
		NCheck(ANType99RecordSetBiometricDataQuality(GetHandle(), pValue));
	}

	NUShort GetBdbFormatOwner() const
	{
		NUShort value;
		NCheck(ANType99RecordGetBdbFormatOwner(GetHandle(), &value));
		return value;
	}

	NUShort GetBdbFormatType() const
	{
		NUShort value;
		NCheck(ANType99RecordGetBdbFormatType(GetHandle(), &value));
		return value;
	}
};

}}}

#endif // !AN_TYPE_99_RECORD_HPP_INCLUDED
