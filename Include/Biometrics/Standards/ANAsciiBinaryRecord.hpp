#ifndef AN_ASCII_BINARY_RECORD_HPP_INCLUDED
#define AN_ASCII_BINARY_RECORD_HPP_INCLUDED

#include <Biometrics/Standards/ANRecord.hpp>
#include <Core/NDateTime.hpp>
namespace Neurotec {
	namespace Biometrics {
		namespace Standards
{
#include <Biometrics/Standards/ANAsciiBinaryRecord.h>
}}}

namespace Neurotec { namespace Biometrics { namespace Standards
{

#undef AN_ASCII_BINARY_RECORD_FIELD_SRC
#undef AN_ASCII_BINARY_RECORD_FIELD_DAT

#undef AN_ASCII_BINARY_RECORD_FIELD_UDF_FROM
#undef AN_ASCII_BINARY_RECORD_FIELD_UDF_TO

#undef AN_ASCII_BINARY_RECORD_MIN_SOURCE_AGENCY_LENGTH
#undef AN_ASCII_BINARY_RECORD_MAX_SOURCE_AGENCY_LENGTH
#undef AN_ASCII_BINARY_RECORD_MAX_SOURCE_AGENCY_LENGTH_V4

#undef AN_ASCII_BINARY_RECORD_QUALITY_METRIC_SCORE_NOT_AVAILABLE
#undef AN_ASCII_BINARY_RECORD_QUALITY_METRIC_SCORE_FAILED

#undef AN_ASCII_BINARY_RECORD_MAX_QUALITY_METRIC_SCORE

const NInt AN_ASCII_BINARY_RECORD_FIELD_SRC = 4;
const NInt AN_ASCII_BINARY_RECORD_FIELD_DAT = 5;

const NInt AN_ASCII_BINARY_RECORD_FIELD_UDF_FROM = 200;
const NInt AN_ASCII_BINARY_RECORD_FIELD_UDF_TO = 998;

const NInt AN_ASCII_BINARY_RECORD_MIN_SOURCE_AGENCY_LENGTH = 9;
const NInt AN_ASCII_BINARY_RECORD_MAX_SOURCE_AGENCY_LENGTH = 20;
const NInt AN_ASCII_BINARY_RECORD_MAX_SOURCE_AGENCY_LENGTH_V4 = 35;

const NByte AN_ASCII_BINARY_RECORD_QUALITY_METRIC_SCORE_NOT_AVAILABLE = 254;
const NByte AN_ASCII_BINARY_RECORD_QUALITY_METRIC_SCORE_FAILED = 255;

const NByte AN_ASCII_BINARY_RECORD_MAX_QUALITY_METRIC_SCORE = 100;

class ANQualityMetric : public ANQualityMetric_
{
	N_DECLARE_EQUATABLE_STRUCT_CLASS(ANQualityMetric)

public:
	ANQualityMetric(NByte score, NUShort algorithmVendorId, NUShort algorithmProductId)
	{
		Score = score;
		AlgorithmVendorId = algorithmVendorId;
		AlgorithmProductId = algorithmProductId;
	}
};

}}}

N_DEFINE_STRUCT_TYPE_TRAITS(Neurotec::Biometrics::Standards, ANQualityMetric)

namespace Neurotec { namespace Biometrics { namespace Standards
{

class ANAsciiBinaryRecord : public ANRecord
{
	N_DECLARE_OBJECT_CLASS(ANAsciiBinaryRecord, ANRecord)

public:
	NString GetSourceAgency() const
	{
		return GetString(ANAsciiBinaryRecordGetSourceAgencyN);
	}

	void SetSourceAgency(const NStringWrapper & value)
	{
		SetString(ANAsciiBinaryRecordSetSourceAgencyN, value);
	}

	NDateTime GetDate() const
	{
		NDateTime_ value;
		NCheck(ANAsciiBinaryRecordGetDate(GetHandle(), &value));
		return NDateTime(value);
	}

	void SetDate(const NDateTime & value)
	{
		NCheck(ANAsciiBinaryRecordSetDate(GetHandle(), value.GetValue()));
	}
};

}}}

#endif // !AN_ASCII_BINARY_RECORD_HPP_INCLUDED
