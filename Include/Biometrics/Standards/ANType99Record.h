#ifndef AN_TYPE_99_RECORD_H_INCLUDED
#define AN_TYPE_99_RECORD_H_INCLUDED

#include <Biometrics/Standards/ANAsciiBinaryRecord.h>

#ifdef N_CPP
extern "C"
{
#endif

N_DECLARE_OBJECT_TYPE(ANType99Record, ANAsciiBinaryRecord)

#define AN_TYPE_99_RECORD_FIELD_LEN AN_RECORD_FIELD_LEN
#define AN_TYPE_99_RECORD_FIELD_IDC AN_RECORD_FIELD_IDC
#define AN_TYPE_99_RECORD_FIELD_SRC AN_ASCII_BINARY_RECORD_FIELD_SRC
#define AN_TYPE_99_RECORD_FIELD_BCD AN_ASCII_BINARY_RECORD_FIELD_DAT

#define AN_TYPE_99_RECORD_FIELD_HDV 100
#define AN_TYPE_99_RECORD_FIELD_BTY 101
#define AN_TYPE_99_RECORD_FIELD_BDQ 102
#define AN_TYPE_99_RECORD_FIELD_BFO 103
#define AN_TYPE_99_RECORD_FIELD_BFT 104

#define AN_TYPE_99_RECORD_FIELD_UDF_FROM AN_ASCII_BINARY_RECORD_FIELD_UDF_FROM
#define AN_TYPE_99_RECORD_FIELD_UDF_TO   AN_ASCII_BINARY_RECORD_FIELD_UDF_TO

#define AN_TYPE_99_RECORD_FIELD_BDB AN_RECORD_FIELD_DATA

#define AN_TYPE_99_RECORD_HEADER_VERSION_1_0 0x0100
#define AN_TYPE_99_RECORD_HEADER_VERSION_1_1 0x0101

typedef enum ANBiometricType_
{
	anbtNoInformationGiven     = 0x00000000,
	anbtMultipleBiometricsUsed = 0x00000001,
	anbtFacialFeatures         = 0x00000002,
	anbtVoice                  = 0x00000004,
	anbtFingerprint            = 0x00000008,
	anbtIris                   = 0x00000010,
	anbtRetina                 = 0x00000020,
	anbtHandGeometry           = 0x00000040,
	anbtSignatureDynamics      = 0x00000080,
	anbtKeystrokeDynamics      = 0x00000100,
	anbtLipMovement            = 0x00000200,
	anbtThermalFaceImage       = 0x00000400,
	anbtThermalHandImage       = 0x00000800,
	anbtGait                   = 0x00001000,
	anbtBodyOdor               = 0x00002000,
	anbtDna                    = 0x00004000,
	anbtEarShape               = 0x00008000,
	anbtFingerGeometry         = 0x00010000,
	anbtPalmPrint              = 0x00020000,
	anbtVeinPattern            = 0x00040000,
	anbtFootPrint              = 0x00080000
} ANBiometricType;

N_DECLARE_TYPE(ANBiometricType)

NResult N_API ANType99RecordGetHeaderVersion(HANType99Record hRecord, NVersion_ * pValue);
NResult N_API ANType99RecordGetBiometricType(HANType99Record hRecord, ANBiometricType * pValue);
NResult N_API ANType99RecordGetBiometricDataQuality(HANType99Record hRecord, struct ANQualityMetric_ * pValue, NBool * pHasValue);
NResult N_API ANType99RecordSetBiometricDataQuality(HANType99Record hRecord, const struct ANQualityMetric_ * pValue);
NResult N_API ANType99RecordGetBdbFormatOwner(HANType99Record hRecord, NUShort * pValue);
NResult N_API ANType99RecordGetBdbFormatType(HANType99Record hRecord, NUShort * pValue);

#ifdef N_CPP
}
#endif

#endif // !AN_TYPE_99_RECORD_H_INCLUDED
