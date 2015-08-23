#ifndef AN_TYPE_17_RECORD_H_INCLUDED
#define AN_TYPE_17_RECORD_H_INCLUDED

#include <Biometrics/Standards/ANImageAsciiBinaryRecord.h>

#ifdef N_CPP
extern "C"
{
#endif

N_DECLARE_OBJECT_TYPE(ANType17Record, ANImageAsciiBinaryRecord)

#define AN_TYPE_17_RECORD_FIELD_LEN AN_RECORD_FIELD_LEN
#define AN_TYPE_17_RECORD_FIELD_IDC AN_RECORD_FIELD_IDC

#define AN_TYPE_17_RECORD_FIELD_FID 3

#define AN_TYPE_17_RECORD_FIELD_SRC AN_ASCII_BINARY_RECORD_FIELD_SRC
#define AN_TYPE_17_RECORD_FIELD_ICD AN_ASCII_BINARY_RECORD_FIELD_DAT
#define AN_TYPE_17_RECORD_FIELD_HLL AN_IMAGE_ASCII_BINARY_RECORD_FIELD_HLL
#define AN_TYPE_17_RECORD_FIELD_VLL AN_IMAGE_ASCII_BINARY_RECORD_FIELD_VLL
#define AN_TYPE_17_RECORD_FIELD_SLC AN_IMAGE_ASCII_BINARY_RECORD_FIELD_SLC
#define AN_TYPE_17_RECORD_FIELD_HPS AN_IMAGE_ASCII_BINARY_RECORD_FIELD_HPS
#define AN_TYPE_17_RECORD_FIELD_VPS AN_IMAGE_ASCII_BINARY_RECORD_FIELD_VPS
#define AN_TYPE_17_RECORD_FIELD_CGA AN_IMAGE_ASCII_BINARY_RECORD_FIELD_CGA
#define AN_TYPE_17_RECORD_FIELD_BPX AN_IMAGE_ASCII_BINARY_RECORD_FIELD_BPX
#define AN_TYPE_17_RECORD_FIELD_CSP AN_IMAGE_ASCII_BINARY_RECORD_FIELD_CSP

#define AN_TYPE_17_RECORD_FIELD_RAE  14
#define AN_TYPE_17_RECORD_FIELD_RAU  15
#define AN_TYPE_17_RECORD_FIELD_IPC  16
#define AN_TYPE_17_RECORD_FIELD_DUI  17
#define AN_TYPE_17_RECORD_FIELD_GUI  18
#define AN_TYPE_17_RECORD_FIELD_MMS  19
#define AN_TYPE_17_RECORD_FIELD_ECL  20
#define AN_TYPE_17_RECORD_FIELD_COM  21
#define AN_TYPE_17_RECORD_FIELD_SHPS 22
#define AN_TYPE_17_RECORD_FIELD_SVPS 23

#define AN_TYPE_17_RECORD_FIELD_IQS AN_IMAGE_ASCII_BINARY_RECORD_FIELD_IQM

#define AN_TYPE_17_RECORD_FIELD_ALS 25
#define AN_TYPE_17_RECORD_FIELD_IRD 26

#define AN_TYPE_17_RECORD_FIELD_DMM AN_IMAGE_ASCII_BINARY_RECORD_FIELD_DMM

#define AN_TYPE_17_RECORD_FIELD_UDF_FROM AN_ASCII_BINARY_RECORD_FIELD_UDF_FROM
#define AN_TYPE_17_RECORD_FIELD_UDF_TO   AN_ASCII_BINARY_RECORD_FIELD_UDF_TO

#define AN_TYPE_17_RECORD_FIELD_DATA AN_RECORD_FIELD_DATA

#define AN_TYPE_17_RECORD_MAX_IRIS_DIAMETER 9999

#define AN_TYPE_17_RECORD_MAX_MAKE_LENGTH          50
#define AN_TYPE_17_RECORD_MAX_MODEL_LENGTH         50
#define AN_TYPE_17_RECORD_MAX_SERIAL_NUMBER_LENGTH 50

typedef enum ANIrisAcquisitionLightingSpectrum_
{
	anialsUnspecified = 0,
	anialsNir = 1,
	anialsVis = 2,
	anialsOther = 255
} ANIrisAcquisitionLightingSpectrum;

N_DECLARE_TYPE(ANIrisAcquisitionLightingSpectrum)

struct ANIrisImageProperties_
{
	BdifIrisOrientation HorzOrientation;
	BdifIrisOrientation VertOrientation;
	BdifIrisScanType ScanType;
};
#ifndef AN_TYPE_17_RECORD_HPP_INCLUDED
typedef struct ANIrisImageProperties_ ANIrisImageProperties;
#endif

N_DECLARE_TYPE(ANIrisImageProperties)

struct ANMakeModelSerialNumber_
{
	HNString hMake;
	HNString hModel;
	HNString hSerialNumber;
};
#ifndef AN_TYPE_17_RECORD_HPP_INCLUDED
typedef struct ANMakeModelSerialNumber_ ANMakeModelSerialNumber;
#endif

N_DECLARE_TYPE(ANMakeModelSerialNumber)

NResult N_API ANMakeModelSerialNumberCreateN(HNString hMake, HNString hModel, HNString hSerialNumber, struct ANMakeModelSerialNumber_ * pValue);
#ifndef N_NO_ANSI_FUNC
NResult N_API ANMakeModelSerialNumberCreateA(const NAChar * szMake, const NAChar * szModel, const NAChar * szSerialNumber, struct ANMakeModelSerialNumber_ * pValue);
#endif
#ifndef N_NO_UNICODE
NResult N_API ANMakeModelSerialNumberCreateW(const NWChar * szMake, const NWChar * szModel, const NWChar * szSerialNumber, struct ANMakeModelSerialNumber_ * pValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API ANMakeModelSerialNumberCreate(const NChar * szMake, const NChar * szModel, const NChar * szSerialNumber, ANMakeModelSerialNumber * pValue);
#endif
#define ANMakeModelSerialNumberCreate N_FUNC_AW(ANMakeModelSerialNumberCreate)

NResult N_API ANMakeModelSerialNumberDispose(struct ANMakeModelSerialNumber_ * pValue);
NResult N_API ANMakeModelSerialNumberCopy(const struct ANMakeModelSerialNumber_ * pSrcValue, struct ANMakeModelSerialNumber_ * pDstValue);
NResult N_API ANMakeModelSerialNumberSet(const struct ANMakeModelSerialNumber_ * pSrcValue, struct ANMakeModelSerialNumber_ * pDstValue);

NResult N_API ANType17RecordGetFeatureIdentifier(HANType17Record hRecord, BdifEyePosition * pValue);
NResult N_API ANType17RecordSetFeatureIdentifier(HANType17Record hRecord, BdifEyePosition value);
NResult N_API ANType17RecordGetRotationAngle(HANType17Record hRecord, NInt * pValue);
NResult N_API ANType17RecordSetRotationAngle(HANType17Record hRecord, NInt value);
NResult N_API ANType17RecordGetRotationAngleUncertainty(HANType17Record hRecord, NInt * pValue);
NResult N_API ANType17RecordSetRotationAngleUncertainty(HANType17Record hRecord, NInt value);
NResult N_API ANType17RecordGetImageProperties(HANType17Record hRecord, struct ANIrisImageProperties_ * pValue, NBool * pHasValue);
NResult N_API ANType17RecordSetImageProperties(HANType17Record hRecord, const struct ANIrisImageProperties_ * pValue);

NResult N_API ANType17RecordGetDeviceUniqueIdentifierN(HANType17Record hRecord, HNString * phValue);

NResult N_API ANType17RecordSetDeviceUniqueIdentifierN(HANRecord hRecord, HNString hValue);
#ifndef N_NO_ANSI_FUNC
NResult N_API ANType17RecordSetDeviceUniqueIdentifierA(HANRecord hRecord, const NAChar * szValue);
#endif
#ifndef N_NO_UNICODE
NResult N_API ANType17RecordSetDeviceUniqueIdentifierW(HANRecord hRecord, const NWChar * szValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API ANType17RecordSetDeviceUniqueIdentifier(HANRecord hRecord, const NChar * szValue);
#endif
#define ANType17RecordSetDeviceUniqueIdentifier N_FUNC_AW(ANType17RecordSetDeviceUniqueIdentifier)

NResult N_API ANType17RecordGetGuid(HANRecord hRecord, struct NGuid_ * pValue, NBool * pHasValue);
NResult N_API ANType17RecordSetGuid(HANRecord hRecord, const struct NGuid_ * pValue);

NResult N_API ANType17RecordGetMakeModelSerialNumber(HANRecord hRecord, struct ANMakeModelSerialNumber_ * pValue, NBool * pHasValue);
NResult N_API ANType17RecordGetMakeN(HANRecord hRecord, HNString * phValue);
NResult N_API ANType17RecordGetModelN(HANRecord hRecord, HNString * phValue);
NResult N_API ANType17RecordGetSerialNumberN(HANRecord hRecord, HNString * phValue);
NResult N_API ANType17RecordSetMakeModelSerialNumberEx(HANRecord hRecord, const struct ANMakeModelSerialNumber_ * pValue);

NResult N_API ANType17RecordSetMakeModelSerialNumberN(HANRecord hRecord, HNString hMake, HNString hModel, HNString hSerialNumber);
#ifndef N_NO_ANSI_FUNC
NResult N_API ANType17RecordSetMakeModelSerialNumberA(HANRecord hRecord, const NAChar * szMake, const NAChar * szModel, const NAChar * szSerialNumber);
#endif
#ifndef N_NO_UNICODE
NResult N_API ANType17RecordSetMakeModelSerialNumberW(HANRecord hRecord, const NWChar * szMake, const NWChar * szModel, const NWChar * szSerialNumber);
#endif
#ifdef N_DOCUMENTATION
NResult N_API ANType17RecordSetMakeModelSerialNumber(HANRecord hRecord, const NChar * szMake, const NChar * szModel, const NChar * szSerialNumber);
#endif
#define ANType17RecordSetMakeModelSerialNumber N_FUNC_AW(ANType17RecordSetMakeModelSerialNumber)

NResult N_API ANType17RecordGetEyeColor(HANRecord hRecord, BdifEyeColor * pValue);
NResult N_API ANType17RecordSetEyeColor(HANRecord hRecord, BdifEyeColor value);
NResult N_API ANType17RecordGetImageQualityScore(HANRecord hRecord, struct ANQualityMetric_ * pValue, NBool * pHasValue);
NResult N_API ANType17RecordSetImageQualityScore(HANRecord hRecord, const struct ANQualityMetric_ * pValue);
NResult N_API ANType17RecordGetAcquisitionLightingSpectrum(HANRecord hRecord, ANIrisAcquisitionLightingSpectrum * pValue);
NResult N_API ANType17RecordSetAcquisitionLightingSpectrum(HANRecord hRecord, ANIrisAcquisitionLightingSpectrum value);
NResult N_API ANType17RecordGetIrisDiameter(HANRecord hRecord, NInt * pValue);
NResult N_API ANType17RecordSetIrisDiameter(HANRecord hRecord, NInt value);

#ifdef N_CPP
}
#endif

#endif // !AN_TYPE_17_RECORD_H_INCLUDED
