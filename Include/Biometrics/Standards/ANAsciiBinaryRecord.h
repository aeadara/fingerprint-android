#ifndef AN_ASCII_BINARY_RECORD_H_INCLUDED
#define AN_ASCII_BINARY_RECORD_H_INCLUDED

#include <Biometrics/Standards/ANRecord.h>
#include <Core/NDateTime.h>

#ifdef N_CPP
extern "C"
{
#endif

N_DECLARE_OBJECT_TYPE(ANAsciiBinaryRecord, ANRecord)

#define AN_ASCII_BINARY_RECORD_FIELD_SRC 4
#define AN_ASCII_BINARY_RECORD_FIELD_DAT 5

#define AN_ASCII_BINARY_RECORD_FIELD_UDF_FROM 200
#define AN_ASCII_BINARY_RECORD_FIELD_UDF_TO   998

#define AN_ASCII_BINARY_RECORD_MIN_SOURCE_AGENCY_LENGTH     9
#define AN_ASCII_BINARY_RECORD_MAX_SOURCE_AGENCY_LENGTH    20
#define AN_ASCII_BINARY_RECORD_MAX_SOURCE_AGENCY_LENGTH_V4 35

#define AN_ASCII_BINARY_RECORD_QUALITY_METRIC_SCORE_NOT_AVAILABLE 254
#define AN_ASCII_BINARY_RECORD_QUALITY_METRIC_SCORE_FAILED        255

#define AN_ASCII_BINARY_RECORD_MAX_QUALITY_METRIC_SCORE 100

struct ANQualityMetric_
{
	NByte Score;
	NUShort AlgorithmVendorId;
	NUShort AlgorithmProductId;
};
#ifndef AN_ASCII_BINARY_RECORD_HPP_INCLUDED
typedef struct ANQualityMetric_ ANQualityMetric;
#endif

N_DECLARE_TYPE(ANQualityMetric)

NResult N_API ANAsciiBinaryRecordGetSourceAgencyN(HANAsciiBinaryRecord hRecord, HNString * phValue);

NResult N_API ANAsciiBinaryRecordSetSourceAgencyN(HANAsciiBinaryRecord hRecord, HNString hValue);
#ifndef N_NO_ANSI_FUNC
NResult N_API ANAsciiBinaryRecordSetSourceAgencyA(HANAsciiBinaryRecord hRecord, const NAChar * szValue);
#endif
#ifndef N_NO_UNICODE
NResult N_API ANAsciiBinaryRecordSetSourceAgencyW(HANAsciiBinaryRecord hRecord, const NWChar * szValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API ANAsciiBinaryRecordSetSourceAgency(HANAsciiBinaryRecord hRecord, const NChar * szValue);
#endif
#define ANAsciiBinaryRecordSetSourceAgency N_FUNC_AW(ANAsciiBinaryRecordSetSourceAgency)

NResult N_API ANAsciiBinaryRecordGetDate(HANAsciiBinaryRecord hRecord, NDateTime_ * pValue);
NResult N_API ANAsciiBinaryRecordSetDate(HANAsciiBinaryRecord hRecord, NDateTime_ value);

#ifdef N_CPP
}
#endif

#endif // !AN_ASCII_BINARY_RECORD_H_INCLUDED
