#ifndef AN_TYPE_10_RECORD_H_INCLUDED
#define AN_TYPE_10_RECORD_H_INCLUDED

#include <Biometrics/Standards/ANImageAsciiBinaryRecord.h>
#include <Geometry/NGeometry.h>

#ifdef N_CPP
extern "C"
{
#endif

N_DECLARE_OBJECT_TYPE(ANType10Record, ANImageAsciiBinaryRecord)

#define AN_TYPE_10_RECORD_FIELD_LEN AN_RECORD_FIELD_LEN
#define AN_TYPE_10_RECORD_FIELD_IDC AN_RECORD_FIELD_IDC

#define AN_TYPE_10_RECORD_FIELD_IMT 3

#define AN_TYPE_10_RECORD_FIELD_SRC AN_ASCII_BINARY_RECORD_FIELD_SRC
#define AN_TYPE_10_RECORD_FIELD_PHD AN_ASCII_BINARY_RECORD_FIELD_DAT
#define AN_TYPE_10_RECORD_FIELD_HLL AN_IMAGE_ASCII_BINARY_RECORD_FIELD_HLL
#define AN_TYPE_10_RECORD_FIELD_VLL AN_IMAGE_ASCII_BINARY_RECORD_FIELD_VLL
#define AN_TYPE_10_RECORD_FIELD_SLC AN_IMAGE_ASCII_BINARY_RECORD_FIELD_SLC
#define AN_TYPE_10_RECORD_FIELD_HPS AN_IMAGE_ASCII_BINARY_RECORD_FIELD_HPS
#define AN_TYPE_10_RECORD_FIELD_VPS AN_IMAGE_ASCII_BINARY_RECORD_FIELD_VPS
#define AN_TYPE_10_RECORD_FIELD_CGA AN_IMAGE_ASCII_BINARY_RECORD_FIELD_CGA

#define AN_TYPE_10_RECORD_FIELD_CSP 12
#define AN_TYPE_10_RECORD_FIELD_SAP 13

#define AN_TYPE_10_RECORD_FIELD_SHPS AN_IMAGE_ASCII_BINARY_RECORD_FIELD_SHPS
#define AN_TYPE_10_RECORD_FIELD_SVPS AN_IMAGE_ASCII_BINARY_RECORD_FIELD_SVPS

#define AN_TYPE_10_RECORD_FIELD_POS 20
#define AN_TYPE_10_RECORD_FIELD_POA 21
#define AN_TYPE_10_RECORD_FIELD_PXS 22
#define AN_TYPE_10_RECORD_FIELD_PAS 23

#define AN_TYPE_10_RECORD_FIELD_SQS AN_IMAGE_ASCII_BINARY_RECORD_FIELD_IQM

#define AN_TYPE_10_RECORD_FIELD_SPA 25
#define AN_TYPE_10_RECORD_FIELD_SXS 26
#define AN_TYPE_10_RECORD_FIELD_SEC 27
#define AN_TYPE_10_RECORD_FIELD_SHC 28
#define AN_TYPE_10_RECORD_FIELD_FFP 29

#define AN_TYPE_10_RECORD_FIELD_DMM AN_IMAGE_ASCII_BINARY_RECORD_FIELD_DMM

#define AN_TYPE_10_RECORD_FIELD_SMT 40
#define AN_TYPE_10_RECORD_FIELD_SMS 41
#define AN_TYPE_10_RECORD_FIELD_SMD 42
#define AN_TYPE_10_RECORD_FIELD_COL 43

#define AN_TYPE_10_RECORD_FIELD_UDF_FROM AN_ASCII_BINARY_RECORD_FIELD_UDF_FROM
#define AN_TYPE_10_RECORD_FIELD_UDF_TO   AN_ASCII_BINARY_RECORD_FIELD_UDF_TO

#define AN_TYPE_10_RECORD_FIELD_DATA AN_RECORD_FIELD_DATA

#define AN_TYPE_10_RECORD_SAP_UNKNOWN                         0
#define AN_TYPE_10_RECORD_SAP_SURVEILLANCE_FACIAL_IMAGE       1
#define AN_TYPE_10_RECORD_SAP_DRIVERS_LICENSE_IMAGE          10
#define AN_TYPE_10_RECORD_SAP_ANSI_FULL_FRONTAL_FACIAL_IMAGE 11
#define AN_TYPE_10_RECORD_SAP_ANSI_TOKEN_FACIAL_IMAGE        12
#define AN_TYPE_10_RECORD_SAP_ISO_FULL_FRONTAL_FACIAL_IMAGE  13
#define AN_TYPE_10_RECORD_SAP_ISO_TOKEN_FACIAL_IMAGE         14
#define AN_TYPE_10_RECORD_SAP_PIV_FACIAL_IMAGE               15
#define AN_TYPE_10_RECORD_SAP_LEGACY_MUGSHOT                 20
#define AN_TYPE_10_RECORD_SAP_BPA_LEVEL_30                   30
#define AN_TYPE_10_RECORD_SAP_BPA_LEVEL_40                   40
#define AN_TYPE_10_RECORD_SAP_BPA_LEVEL_50                   50
#define AN_TYPE_10_RECORD_SAP_BPA_LEVEL_51                   51

#define AN_TYPE_10_RECORD_MAX_PHOTO_DESCRIPTION_COUNT           9
#define AN_TYPE_10_RECORD_MAX_QUALITY_METRIC_COUNT              9
#define AN_TYPE_10_RECORD_MAX_SUBJECT_FACIAL_DESCRIPTION_COUNT 50
#define AN_TYPE_10_RECORD_MAX_FACIAL_FEATURE_POINT_COUNT       88
#define AN_TYPE_10_RECORD_MAX_NCIC_DESIGNATION_CODE_COUNT       3
#define AN_TYPE_10_RECORD_MAX_SMT_COUNT                         9

#define AN_TYPE_10_RECORD_MAX_PHYSICAL_PHOTO_CHARACTERISTIC_LENGTH   11
#define AN_TYPE_10_RECORD_MAX_OTHER_PHOTO_CHARACTERISTIC_LENGTH      14
#define AN_TYPE_10_RECORD_MIN_SUBJECT_FACIAL_CHARACTERISTIC_LENGTH    5
#define AN_TYPE_10_RECORD_MAX_SUBJECT_FACIAL_CHARACTERISTIC_LENGTH   20
#define AN_TYPE_10_RECORD_MAX_VENDOR_PHOTO_ACQUISITION_SOURCE_LENGTH  7
#define AN_TYPE_10_RECORD_MIN_NCIC_DESIGNATION_CODE_LENGTH            3
#define AN_TYPE_10_RECORD_MAX_NCIC_DESIGNATION_CODE_LENGTH           10

#define AN_TYPE_10_RECORD_MAX_SMT_SIZE 99

typedef enum ANImageType_
{
	anitFace = 0,
	anitScar = 1,
	anitMark = 2,
	anitTattoo = 3,
	anitOther = 255
} ANImageType;

N_DECLARE_TYPE(ANImageType)

typedef enum ANSubjectPose_
{
	anspUnspecified = 0,
	anspFullFaceFrontal = 1,
	anspRightProfile = 2,
	anspLeftProfile = 3,
	anspAngled = 4,
	anspDetermined3D = 5
} ANSubjectPose;

N_DECLARE_TYPE(ANSubjectPose)

typedef enum ANSmtSource_
{
	anssScar = 0,
	anssMark = 1,
	anssTattoo = 2,
	anssChemical = 3,
	anssBranded = 4,
	anssCut = 5
} ANSmtSource;

N_DECLARE_TYPE(ANSmtSource)

typedef enum ANTattooClass_
{
	antcHuman = 0,
	antcAnimal = 1,
	antcPlant = 2,
	antcFlag = 3,
	antcObject = 4,
	antcAbstract = 5,
	antcSymbol = 6,
	antcOther = 7
} ANTattooClass;

N_DECLARE_TYPE(ANTattooClass)

typedef enum ANTattooSubclass_
{
	antsMiscHuman = antcHuman * 256 + 0,
	antsMaleFace = antcHuman * 256 + 1,
	antsFemaleFace = antcHuman * 256 + 2,
	antsAbstractFace = antcHuman * 256 + 3,
	antsMaleBody = antcHuman * 256 + 4,
	antsFemaleBody = antcHuman * 256 + 5,
	antsAbstractBody = antcHuman * 256 + 6,
	antsRole = antcHuman * 256 + 7,
	antsSportFigure = antcHuman * 256 + 8,
	antsMaleBodyPart = antcHuman * 256 + 9,
	antsFemaleBodyPart = antcHuman * 256 + 10,
	antsAbstractBodyPart = antcHuman * 256 + 11,
	antsSkull = antcHuman * 256 + 12,

	antsMiscAnimal = antcAnimal * 256 + 0,
	antsCat = antcAnimal * 256 + 1,
	antsDog = antcAnimal * 256 + 2,
	antsDomestic = antcAnimal * 256 + 3,
	antsVicious = antcAnimal * 256 + 4,
	antsHorse = antcAnimal * 256 + 5,
	antsWild = antcAnimal * 256 + 6,
	antsSnake = antcAnimal * 256 + 7,
	antsDragon = antcAnimal * 256 + 8,
	antsBird = antcAnimal * 256 + 9,
	antsInsect = antcAnimal * 256 + 10,
	antsAbstractAnimal = antcAnimal * 256 + 11,
	antsAnimalPart = antcAnimal * 256 + 12,

	antsMiscPlant = antcPlant * 256 + 0,
	antsNarcotic = antcPlant * 256 + 1,
	antsRedFlower = antcPlant * 256 + 2,
	antsBlueFlower = antcPlant * 256 + 3,
	antsYellowFlower = antcPlant * 256 + 4,
	antsDrawing = antcPlant * 256 + 5,
	antsRose = antcPlant * 256 + 6,
	antsTulip = antcPlant * 256 + 7,
	antsLily = antcPlant * 256 + 8,

	antsMiscFlag = antcFlag * 256 + 0,
	antsUsa = antcFlag * 256 + 1,
	antsState = antcFlag * 256 + 2,
	antsNazi = antcFlag * 256 + 3,
	antsConfederate = antcFlag * 256 + 4,
	antsBritish = antcFlag * 256 + 5,

	antsMiscObject = antcObject * 256 + 0,
	antsFire = antcObject * 256 + 1,
	antsWeapon = antcObject * 256 + 2,
	antsAirplane = antcObject * 256 + 3,
	antsVessel = antcObject * 256 + 4,
	antsTrain = antcObject * 256 + 5,
	antsVehicle = antcObject * 256 + 6,
	antsMythical = antcObject * 256 + 7,
	antsSporting = antcObject * 256 + 8,
	antsNature = antcObject * 256 + 9,

	antsMiscAbstract = antcAbstract * 256 + 0,
	antsFigure = antcAbstract * 256 + 1,
	antsSleeve = antcAbstract * 256 + 2,
	antsBracelet = antcAbstract * 256 + 3,
	antsAnklet = antcAbstract * 256 + 4,
	antsNecklace = antcAbstract * 256 + 5,
	antsShirt = antcAbstract * 256 + 6,
	antsBodyBand = antcAbstract * 256 + 7,
	antsHeadBand = antcAbstract * 256 + 8,

	antsMiscSymbol = antcSymbol * 256 + 0,
	antsNational = antcSymbol * 256 + 1,
	antsPolitical = antcSymbol * 256 + 2,
	antsMilitary = antcSymbol * 256 + 3,
	antsFraternal = antcSymbol * 256 + 4,
	antsProfessional = antcSymbol * 256 + 5,
	antsGang = antcSymbol * 256 + 6,

	antsMisc = antcOther * 256 + 0,
	antsWording = antcOther * 256 + 1,
	antsFreeform = antcOther * 256 + 2
} ANTattooSubclass;

N_DECLARE_TYPE(ANTattooSubclass)

struct ANSmt_
{
	ANSmtSource source;
	ANTattooClass tattooClass;
	ANTattooSubclass tattooSubclass;
	HNString hDescription;
};
#ifndef AN_TYPE_10_RECORD_HPP_INCLUDED
typedef struct ANSmt_ ANSmt;
#endif

N_DECLARE_TYPE(ANSmt)

typedef enum ANColor_
{
	ancBlack = 1,
	ancBrown = 2,
	ancGray = 3,
	ancBlue = 4,
	ancGreen = 5,
	ancOrange = 6,
	ancPurple = 7,
	ancRed = 8,
	ancYellow = 9,
	ancWhite = 10,
	ancMultiColored = 11,
	ancOutlined = 12
} ANColor;

N_DECLARE_TYPE(ANColor)

struct ANImageSourceType_
{
	BdifImageSourceType value;
	HNString hVendorValue;
};
#ifndef AN_TYPE_10_RECORD_HPP_INCLUDED
typedef struct ANImageSourceType_ ANImageSourceType;
#endif

N_DECLARE_TYPE(ANImageSourceType)

struct ANPoseAngles_
{
	NInt yaw;
	NInt pitch;
	NInt roll;
	NInt yawUncertainty;
	NInt pitchUncertainty;
	NInt rollUncertainty;
};
#ifndef AN_TYPE_10_RECORD_HPP_INCLUDED
typedef struct ANPoseAngles_ ANPoseAngles;
#endif

N_DECLARE_TYPE(ANPoseAngles)

struct ANHairColor_
{
	BdifHairColor value;
	BdifHairColor baldValue;
};
#ifndef AN_TYPE_10_RECORD_HPP_INCLUDED
typedef struct ANHairColor_ ANHairColor;
#endif

N_DECLARE_TYPE(ANHairColor)

NResult N_API ANSmtCreateN(ANSmtSource source, ANTattooClass tattooClass, ANTattooSubclass tattooSubclass, HNString hDescription, struct ANSmt_ * pValue);
#ifndef N_NO_ANSI_FUNC
NResult N_API ANSmtCreateA(ANSmtSource source, ANTattooClass tattooClass, ANTattooSubclass tattooSubclass, const NAChar * szDescription, struct ANSmt_ * pValue);
#endif
#ifndef N_NO_UNICODE
NResult N_API ANSmtCreateW(ANSmtSource source, ANTattooClass tattooClass, ANTattooSubclass tattooSubclass, const NWChar * szDescription, struct ANSmt_ * pValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API ANSmtCreate(ANSmtSource source, ANTattooClass tattooClass, ANTattooSubclass tattooSubclass, const NChar * szDescription, ANSmt * pValue);
#endif
#define ANSmtCreate N_FUNC_AW(ANSmtCreate)

NResult N_API ANSmtDispose(struct ANSmt_ * pValue);
NResult N_API ANSmtCopy(const struct ANSmt_ * pSrcValue, struct ANSmt_ * pDstValue);
NResult N_API ANSmtSet(const struct ANSmt_ * pSrcValue, struct ANSmt_ * pDstValue);

NResult N_API ANImageSourceTypeCreateN(BdifImageSourceType value, HNString hVendorValue, struct ANImageSourceType_ * pValue);
#ifndef N_NO_ANSI_FUNC
NResult N_API ANImageSourceTypeCreateA(BdifImageSourceType value, const NAChar * szVendorValue, struct ANImageSourceType_ * pValue);
#endif
#ifndef N_NO_UNICODE
NResult N_API ANImageSourceTypeCreateW(BdifImageSourceType value, const NWChar * szVendorValue, struct ANImageSourceType_ * pValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API ANImageSourceTypeCreate(BdifImageSourceType value, const NChar * szVendorValue, ANImageSourceType * pValue);
#endif
#define ANImageSourceTypeCreate N_FUNC_AW(ANImageSourceTypeCreate)

NResult N_API ANImageSourceTypeDispose(struct ANImageSourceType_ * pValue);
NResult N_API ANImageSourceTypeCopy(const struct ANImageSourceType_ * pSrcValue, struct ANImageSourceType_ * pDstValue);
NResult N_API ANImageSourceTypeSet(const struct ANImageSourceType_ * pSrcValue, struct ANImageSourceType_ * pDstValue);

NResult N_API ANType10RecordGetPhysicalPhotoCharacteristicCount(HANType10Record hRecord, NInt * pValue);

NResult N_API ANType10RecordGetPhysicalPhotoCharacteristicN(HANType10Record hRecord, NInt index, HNString * phValue);

NResult N_API ANType10RecordSetPhysicalPhotoCharacteristicN(HANType10Record hRecord, NInt index, HNString hValue);
#ifndef N_NO_ANSI_FUNC
NResult N_API ANType10RecordSetPhysicalPhotoCharacteristicA(HANType10Record hRecord, NInt index, const NAChar * szValue);
#endif
#ifndef N_NO_UNICODE
NResult N_API ANType10RecordSetPhysicalPhotoCharacteristicW(HANType10Record hRecord, NInt index, const NWChar * szValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API ANType10RecordSetPhysicalPhotoCharacteristic(HANType10Record hRecord, NInt index, const NChar * szValue);
#endif
#define ANType10RecordSetPhysicalPhotoCharacteristic N_FUNC_AW(ANType10RecordSetPhysicalPhotoCharacteristic)

N_DEPRECATED("function is deprecated, use ANType10RecordAddPhysicalPhotoCharacteristicExN instead")
NResult N_API ANType10RecordAddPhysicalPhotoCharacteristicN(HANType10Record hRecord, HNString hValue);
#ifndef N_NO_ANSI_FUNC
N_DEPRECATED("function is deprecated, use ANType10RecordAddPhysicalPhotoCharacteristicExA instead")
NResult N_API ANType10RecordAddPhysicalPhotoCharacteristicA(HANType10Record hRecord, const NAChar * szValue);
#endif
#ifndef N_NO_UNICODE
N_DEPRECATED("function is deprecated, use ANType10RecordAddPhysicalPhotoCharacteristicExW instead")
NResult N_API ANType10RecordAddPhysicalPhotoCharacteristicW(HANType10Record hRecord, const NWChar * szValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API ANType10RecordAddPhysicalPhotoCharacteristic(HANType10Record hRecord, const NChar * szValue);
#endif
#define ANType10RecordAddPhysicalPhotoCharacteristic N_FUNC_AW(ANType10RecordAddPhysicalPhotoCharacteristic)

NResult N_API ANType10RecordAddPhysicalPhotoCharacteristicExN(HANType10Record hRecord, HNString hValue, NInt * pIndex);
#ifndef N_NO_ANSI_FUNC
NResult N_API ANType10RecordAddPhysicalPhotoCharacteristicExA(HANType10Record hRecord, const NAChar * szValue, NInt * pIndex);
#endif
#ifndef N_NO_UNICODE
NResult N_API ANType10RecordAddPhysicalPhotoCharacteristicExW(HANType10Record hRecord, const NWChar * szValue, NInt * pIndex);
#endif
#ifdef N_DOCUMENTATION
NResult N_API ANType10RecordAddPhysicalPhotoCharacteristicEx(HANType10Record hRecord, const NChar * szValue, NInt * pIndex);
#endif
#define ANType10RecordAddPhysicalPhotoCharacteristicEx N_FUNC_AW(ANType10RecordAddPhysicalPhotoCharacteristicEx)

NResult N_API ANType10RecordInsertPhysicalPhotoCharacteristicN(HANType10Record hRecord, NInt index, HNString hValue);
#ifndef N_NO_ANSI_FUNC
NResult N_API ANType10RecordInsertPhysicalPhotoCharacteristicA(HANType10Record hRecord, NInt index, const NAChar * szValue);
#endif
#ifndef N_NO_UNICODE
NResult N_API ANType10RecordInsertPhysicalPhotoCharacteristicW(HANType10Record hRecord, NInt index, const NWChar * szValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API ANType10RecordInsertPhysicalPhotoCharacteristic(HANType10Record hRecord, NInt index, const NChar * szValue);
#endif
#define ANType10RecordInsertPhysicalPhotoCharacteristic N_FUNC_AW(ANType10RecordInsertPhysicalPhotoCharacteristic)

N_DEPRECATED("function is deprecated, use ANType10RecordRemovePhysicalPhotoCharacteristicAt instead")
NResult N_API ANType10RecordRemovePhysicalPhotoCharacteristic(HANType10Record hRecord, NInt index);
NResult N_API ANType10RecordRemovePhysicalPhotoCharacteristicAt(HANType10Record hRecord, NInt index);
NResult N_API ANType10RecordClearPhysicalPhotoCharacteristics(HANType10Record hRecord);

NResult N_API ANType10RecordGetOtherPhotoCharacteristicCount(HANType10Record hRecord, NInt * pValue);

NResult N_API ANType10RecordGetOtherPhotoCharacteristicN(HANType10Record hRecord, NInt index, HNString * phValue);

NResult N_API ANType10RecordSetOtherPhotoCharacteristicN(HANType10Record hRecord, NInt index, HNString hValue);
#ifndef N_NO_ANSI_FUNC
NResult N_API ANType10RecordSetOtherPhotoCharacteristicA(HANType10Record hRecord, NInt index, const NAChar * szValue);
#endif
#ifndef N_NO_UNICODE
NResult N_API ANType10RecordSetOtherPhotoCharacteristicW(HANType10Record hRecord, NInt index, const NWChar * szValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API ANType10RecordSetOtherPhotoCharacteristic(HANType10Record hRecord, NInt index, const NChar * szValue);
#endif
#define ANType10RecordSetOtherPhotoCharacteristic N_FUNC_AW(ANType10RecordSetOtherPhotoCharacteristic)

N_DEPRECATED("function is deprecated, use ANType10RecordAddOtherPhotoCharacteristicExN instead")
NResult N_API ANType10RecordAddOtherPhotoCharacteristicN(HANType10Record hRecord, HNString hValue);
#ifndef N_NO_ANSI_FUNC
N_DEPRECATED("function is deprecated, use ANType10RecordAddOtherPhotoCharacteristicExA instead")
NResult N_API ANType10RecordAddOtherPhotoCharacteristicA(HANType10Record hRecord, const NAChar * szValue);
#endif
#ifndef N_NO_UNICODE
N_DEPRECATED("function is deprecated, use ANType10RecordAddOtherPhotoCharacteristicExW instead")
NResult N_API ANType10RecordAddOtherPhotoCharacteristicW(HANType10Record hRecord, const NWChar * szValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API ANType10RecordAddOtherPhotoCharacteristic(HANType10Record hRecord, const NChar * szValue);
#endif
#define ANType10RecordAddOtherPhotoCharacteristic N_FUNC_AW(ANType10RecordAddOtherPhotoCharacteristic)

NResult N_API ANType10RecordAddOtherPhotoCharacteristicExN(HANType10Record hRecord, HNString hValue, NInt * pIndex);
#ifndef N_NO_ANSI_FUNC
NResult N_API ANType10RecordAddOtherPhotoCharacteristicExA(HANType10Record hRecord, const NAChar * szValue, NInt * pIndex);
#endif
#ifndef N_NO_UNICODE
NResult N_API ANType10RecordAddOtherPhotoCharacteristicExW(HANType10Record hRecord, const NWChar * szValue, NInt * pIndex);
#endif
#ifdef N_DOCUMENTATION
NResult N_API ANType10RecordAddOtherPhotoCharacteristicEx(HANType10Record hRecord, const NChar * szValue, NInt * pIndex);
#endif
#define ANType10RecordAddOtherPhotoCharacteristicEx N_FUNC_AW(ANType10RecordAddOtherPhotoCharacteristicEx)

NResult N_API ANType10RecordInsertOtherPhotoCharacteristicN(HANType10Record hRecord, NInt index, HNString hValue);
#ifndef N_NO_ANSI_FUNC
NResult N_API ANType10RecordInsertOtherPhotoCharacteristicA(HANType10Record hRecord, NInt index, const NAChar * szValue);
#endif
#ifndef N_NO_UNICODE
NResult N_API ANType10RecordInsertOtherPhotoCharacteristicW(HANType10Record hRecord, NInt index, const NWChar * szValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API ANType10RecordInsertOtherPhotoCharacteristic(HANType10Record hRecord, NInt index, const NChar * szValue);
#endif
#define ANType10RecordInsertOtherPhotoCharacteristic N_FUNC_AW(ANType10RecordInsertOtherPhotoCharacteristic)

N_DEPRECATED("function is deprecated, use ANType10RecordRemoveOtherPhotoCharacteristicAt instead")
NResult N_API ANType10RecordRemoveOtherPhotoCharacteristic(HANType10Record hRecord, NInt index);
NResult N_API ANType10RecordRemoveOtherPhotoCharacteristicAt(HANType10Record hRecord, NInt index);
NResult N_API ANType10RecordClearOtherPhotoCharacteristics(HANType10Record hRecord);

NResult N_API ANType10RecordGetSubjectQualityScoreCount(HANType10Record hRecord, NInt * pValue);
NResult N_API ANType10RecordGetSubjectQualityScore(HANType10Record hRecord, NInt index, struct ANQualityMetric_ * pValue);
N_DEPRECATED("function is deprecated, use ANType10RecordGetSubjectQualityScores instead")
NResult N_API ANType10RecordGetSubjectQualityScoresEx(HANType10Record hRecord, struct ANQualityMetric_ * arValue, NInt valueLength);
NResult N_API ANType10RecordGetSubjectQualityScores(HANType10Record hRecord, struct ANQualityMetric_ * * parValues, NInt * pValueCount);
NResult N_API ANType10RecordSetSubjectQualityScore(HANType10Record hRecord, NInt index, const struct ANQualityMetric_ * pValue);
N_DEPRECATED("function is deprecated, use ANType10RecordAddSubjectQualityScoreEx instead")
NResult N_API ANType10RecordAddSubjectQualityScore(HANType10Record hRecord, const struct ANQualityMetric_ * pValue);
NResult N_API ANType10RecordAddSubjectQualityScoreEx(HANType10Record hRecord, const struct ANQualityMetric_ * pValue, NInt * pIndex);
NResult N_API ANType10RecordInsertSubjectQualityScore(HANType10Record hRecord, NInt index, const struct ANQualityMetric_ * pValue);
N_DEPRECATED("function is deprecated, use ANType10RecordRemoveSubjectQualityScoreAt instead")
NResult N_API ANType10RecordRemoveSubjectQualityScore(HANType10Record hRecord, NInt index);
NResult N_API ANType10RecordRemoveSubjectQualityScoreAt(HANType10Record hRecord, NInt index);
NResult N_API ANType10RecordClearSubjectQualityScores(HANType10Record hRecord);

NResult N_API ANType10RecordGetSubjectFacialCharacteristicCount(HANType10Record hRecord, NInt * pValue);

NResult N_API ANType10RecordGetSubjectFacialCharacteristicN(HANType10Record hRecord, NInt index, HNString * phValue);

NResult N_API ANType10RecordSetSubjectFacialCharacteristicN(HANType10Record hRecord, NInt index, HNString hValue);
#ifndef N_NO_ANSI_FUNC
NResult N_API ANType10RecordSetSubjectFacialCharacteristicA(HANType10Record hRecord, NInt index, const NAChar * szValue);
#endif
#ifndef N_NO_UNICODE
NResult N_API ANType10RecordSetSubjectFacialCharacteristicW(HANType10Record hRecord, NInt index, const NWChar * szValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API ANType10RecordSetSubjectFacialCharacteristic(HANType10Record hRecord, NInt index, const NChar * szValue);
#endif
#define ANType10RecordSetSubjectFacialCharacteristic N_FUNC_AW(ANType10RecordSetSubjectFacialCharacteristic)

N_DEPRECATED("function is deprecated, use ANType10RecordAddSubjectFacialCharacteristicExN instead")
NResult N_API ANType10RecordAddSubjectFacialCharacteristicN(HANType10Record hRecord, HNString hValue);
#ifndef N_NO_ANSI_FUNC
N_DEPRECATED("function is deprecated, use ANType10RecordAddSubjectFacialCharacteristicExA instead")
NResult N_API ANType10RecordAddSubjectFacialCharacteristicA(HANType10Record hRecord, const NAChar * szValue);
#endif
#ifndef N_NO_UNICODE
N_DEPRECATED("function is deprecated, use ANType10RecordAddSubjectFacialCharacteristicExW instead")
NResult N_API ANType10RecordAddSubjectFacialCharacteristicW(HANType10Record hRecord, const NWChar * szValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API ANType10RecordAddSubjectFacialCharacteristic(HANType10Record hRecord, const NChar * szValue);
#endif
#define ANType10RecordAddSubjectFacialCharacteristic N_FUNC_AW(ANType10RecordAddSubjectFacialCharacteristic)

NResult N_API ANType10RecordAddSubjectFacialCharacteristicExN(HANType10Record hRecord, HNString hValue, NInt * pIndex);
#ifndef N_NO_ANSI_FUNC
NResult N_API ANType10RecordAddSubjectFacialCharacteristicExA(HANType10Record hRecord, const NAChar * szValue, NInt * pIndex);
#endif
#ifndef N_NO_UNICODE
NResult N_API ANType10RecordAddSubjectFacialCharacteristicExW(HANType10Record hRecord, const NWChar * szValue, NInt * pIndex);
#endif
#ifdef N_DOCUMENTATION
NResult N_API ANType10RecordAddSubjectFacialCharacteristicEx(HANType10Record hRecord, const NChar * szValue, NInt * pIndex);
#endif
#define ANType10RecordAddSubjectFacialCharacteristicEx N_FUNC_AW(ANType10RecordAddSubjectFacialCharacteristicEx)

NResult N_API ANType10RecordInsertSubjectFacialCharacteristicN(HANType10Record hRecord, NInt index, HNString hValue);
#ifndef N_NO_ANSI_FUNC
NResult N_API ANType10RecordInsertSubjectFacialCharacteristicA(HANType10Record hRecord, NInt index, const NAChar * szValue);
#endif
#ifndef N_NO_UNICODE
NResult N_API ANType10RecordInsertSubjectFacialCharacteristicW(HANType10Record hRecord, NInt index, const NWChar * szValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API ANType10RecordInsertSubjectFacialCharacteristic(HANType10Record hRecord, NInt index, const NChar * szValue);
#endif
#define ANType10RecordInsertSubjectFacialCharacteristic N_FUNC_AW(ANType10RecordInsertSubjectFacialCharacteristic)

N_DEPRECATED("function is deprecated, use ANType10RecordRemoveSubjectFacialCharacteristicAt instead")
NResult N_API ANType10RecordRemoveSubjectFacialCharacteristic(HANType10Record hRecord, NInt index);
NResult N_API ANType10RecordRemoveSubjectFacialCharacteristicAt(HANType10Record hRecord, NInt index);
NResult N_API ANType10RecordClearSubjectFacialCharacteristics(HANType10Record hRecord);

NResult N_API ANType10RecordGetFacialFeaturePointCount(HANType10Record hRecord, NInt * pValue);
NResult N_API ANType10RecordGetFacialFeaturePoint(HANType10Record hRecord, NInt index, struct BdifFaceFeaturePoint_ * pValue);
N_DEPRECATED("function is deprecated, use ANType10RecordGetFacialFeaturePoints instead")
NResult N_API ANType10RecordGetFacialFeaturePointsEx(HANType10Record hRecord, struct BdifFaceFeaturePoint_ * arValue, NInt valueLength);
NResult N_API ANType10RecordGetFacialFeaturePoints(HANType10Record hRecord, struct BdifFaceFeaturePoint_ * * parValues, NInt * pValueCount);
NResult N_API ANType10RecordSetFacialFeaturePoint(HANType10Record hRecord, NInt index, const struct BdifFaceFeaturePoint_ * pValue);
N_DEPRECATED("function is deprecated, use ANType10RecordAddFacialFeaturePointEx instead")
NResult N_API ANType10RecordAddFacialFeaturePoint(HANType10Record hRecord, const struct BdifFaceFeaturePoint_ * pValue);
NResult N_API ANType10RecordAddFacialFeaturePointEx(HANType10Record hRecord, const struct BdifFaceFeaturePoint_ * pValue, NInt * pIndex);
NResult N_API ANType10RecordInsertFacialFeaturePoint(HANType10Record hRecord, NInt index, const struct BdifFaceFeaturePoint_ * pValue);
N_DEPRECATED("function is deprecated, use ANType10RecordRemoveFacialFeaturePointAt instead")
NResult N_API ANType10RecordRemoveFacialFeaturePoint(HANType10Record hRecord, NInt index);
NResult N_API ANType10RecordRemoveFacialFeaturePointAt(HANType10Record hRecord, NInt index);
NResult N_API ANType10RecordClearFacialFeaturePoints(HANType10Record hRecord);

NResult N_API ANType10RecordGetNcicDesignationCodeCount(HANType10Record hRecord, NInt * pValue);

NResult N_API ANType10RecordGetNcicDesignationCodeN(HANType10Record hRecord, NInt index, HNString * phValue);

NResult N_API ANType10RecordSetNcicDesignationCodeN(HANType10Record hRecord, NInt index, HNString hValue);
#ifndef N_NO_ANSI_FUNC
NResult N_API ANType10RecordSetNcicDesignationCodeA(HANType10Record hRecord, NInt index, const NAChar * szValue);
#endif
#ifndef N_NO_UNICODE
NResult N_API ANType10RecordSetNcicDesignationCodeW(HANType10Record hRecord, NInt index, const NWChar * szValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API ANType10RecordSetNcicDesignationCode(HANType10Record hRecord, NInt index, const NChar * szValue);
#endif
#define ANType10RecordSetNcicDesignationCode N_FUNC_AW(ANType10RecordSetNcicDesignationCode)

N_DEPRECATED("function is deprecated, use ANType10RecordAddNcicDesignationCodeExN instead")
NResult N_API ANType10RecordAddNcicDesignationCodeN(HANType10Record hRecord, HNString hValue);
#ifndef N_NO_ANSI_FUNC
N_DEPRECATED("function is deprecated, use ANType10RecordAddNcicDesignationCodeExA instead")
NResult N_API ANType10RecordAddNcicDesignationCodeA(HANType10Record hRecord, const NAChar * szValue);
#endif
#ifndef N_NO_UNICODE
N_DEPRECATED("function is deprecated, use ANType10RecordAddNcicDesignationCodeExW instead")
NResult N_API ANType10RecordAddNcicDesignationCodeW(HANType10Record hRecord, const NWChar * szValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API ANType10RecordAddNcicDesignationCode(HANType10Record hRecord, const NChar * szValue);
#endif
#define ANType10RecordAddNcicDesignationCode N_FUNC_AW(ANType10RecordAddNcicDesignationCode);

NResult N_API ANType10RecordAddNcicDesignationCodeExN(HANType10Record hRecord, HNString hValue, NInt * pIndex);
#ifndef N_NO_ANSI_FUNC
NResult N_API ANType10RecordAddNcicDesignationCodeExA(HANType10Record hRecord, const NAChar * szValue, NInt * pIndex);
#endif
#ifndef N_NO_UNICODE
NResult N_API ANType10RecordAddNcicDesignationCodeExW(HANType10Record hRecord, const NWChar * szValue, NInt * pIndex);
#endif
#ifdef N_DOCUMENTATION
NResult N_API ANType10RecordAddNcicDesignationCodeEx(HANType10Record hRecord, const NChar * szValue, NInt * pIndex);
#endif
#define ANType10RecordAddNcicDesignationCodeEx N_FUNC_AW(ANType10RecordAddNcicDesignationCodeEx);

NResult N_API ANType10RecordInsertNcicDesignationCodeN(HANType10Record hRecord, NInt index, HNString hValue);
#ifndef N_NO_ANSI_FUNC
NResult N_API ANType10RecordInsertNcicDesignationCodeA(HANType10Record hRecord, NInt index, const NAChar * szValue);
#endif
#ifndef N_NO_UNICODE
NResult N_API ANType10RecordInsertNcicDesignationCodeW(HANType10Record hRecord, NInt index, const NWChar * szValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API ANType10RecordInsertNcicDesignationCode(HANType10Record hRecord, NInt index, const NChar * szValue);
#endif
#define ANType10RecordInsertNcicDesignationCode N_FUNC_AW(ANType10RecordInsertNcicDesignationCode)

N_DEPRECATED("function is deprecated, use ANType10RecordRemoveNcicDesignationCodeAt instead")
NResult N_API ANType10RecordRemoveNcicDesignationCode(HANType10Record hRecord, NInt index);
NResult N_API ANType10RecordRemoveNcicDesignationCodeAt(HANType10Record hRecord, NInt index);
NResult N_API ANType10RecordClearNcicDesignationCodes(HANType10Record hRecord);

NResult N_API ANType10RecordGetSmtCount(HANType10Record hRecord, NInt * pValue);
NResult N_API ANType10RecordGetSmt(HANType10Record hRecord, NInt index, struct ANSmt_ * pValue);
NResult N_API ANType10RecordSetSmtEx(HANType10Record hRecord, NInt index, const struct ANSmt_ * pValue);
N_DEPRECATED("function is deprecated, use ANType10RecordAddSmt instead")
NResult N_API ANType10RecordAddSmtEx(HANType10Record hRecord, const struct ANSmt_ * pValue);
NResult N_API ANType10RecordAddSmt(HANType10Record hRecord, const struct ANSmt_ * pValue, NInt * pIndex);
NResult N_API ANType10RecordInsertSmtEx(HANType10Record hRecord, NInt index, const struct ANSmt_ * pValue);
N_DEPRECATED("function is deprecated, use ANType10RecordRemoveSmtAt instead")
NResult N_API ANType10RecordRemoveSmt(HANType10Record hRecord, NInt index);
NResult N_API ANType10RecordRemoveSmtAt(HANType10Record hRecord, NInt index);
NResult N_API ANType10RecordClearSmts(HANType10Record hRecord);

NResult N_API ANType10RecordGetSmtColorCount(HANType10Record hRecord, NInt smtIndex, NInt * pValue);
NResult N_API ANType10RecordGetSmtColor(HANType10Record hRecord, NInt smtIndex, NInt index, ANColor * pValue);
N_DEPRECATED("function is deprecated, use ANType10RecordGetSmtColors instead")
NResult N_API ANType10RecordGetSmtColorsEx(HANType10Record hRecord, NInt smtIndex, ANColor * arValue, NInt valueLength);
NResult N_API ANType10RecordGetSmtColors(HANType10Record hRecord, NInt smtIndex, ANColor * * parValues, NInt * pValueCount);
NResult N_API ANType10RecordSetSmtColor(HANType10Record hRecord, NInt smtIndex, NInt index, ANColor value);
N_DEPRECATED("function is deprecated, use ANType10RecordAddSmtColorEx instead")
NResult N_API ANType10RecordAddSmtColor(HANType10Record hRecord, NInt smtIndex, ANColor value);
NResult N_API ANType10RecordAddSmtColorEx(HANType10Record hRecord, NInt smtIndex, ANColor value, NInt * pIndex);
NResult N_API ANType10RecordInsertSmtColor(HANType10Record hRecord, NInt smtIndex, NInt index, ANColor value);
N_DEPRECATED("function is deprecated, use ANType10RecordRemoveSmtColorAt instead")
NResult N_API ANType10RecordRemoveSmtColor(HANType10Record hRecord, NInt smtIndex, NInt index);
NResult N_API ANType10RecordRemoveSmtColorAt(HANType10Record hRecord, NInt smtIndex, NInt index);
NResult N_API ANType10RecordClearSmtColors(HANType10Record hRecord, NInt smtIndex);

NResult N_API ANType10RecordGetImageType(HANType10Record hRecord, ANImageType * pValue);
NResult N_API ANType10RecordGetSubjectAcquisitionProfile(HANType10Record hRecord, NInt * pValue);
NResult N_API ANType10RecordSetSubjectAcquisitionProfile(HANType10Record hRecord, NInt value);
NResult N_API ANType10RecordGetSubjectPose(HANType10Record hRecord, ANSubjectPose * pValue);
NResult N_API ANType10RecordSetSubjectPose(HANType10Record hRecord, ANSubjectPose value);
NResult N_API ANType10RecordGetPoseOffsetAngle(HANType10Record hRecord, NInt * pValue, NBool * pHasValue);
NResult N_API ANType10RecordSetPoseOffsetAngle(HANType10Record hRecord, const NInt * pValue);
NResult N_API ANType10RecordGetPhotoAttributes(HANType10Record hRecord, BdifFaceProperties * pValue);
NResult N_API ANType10RecordSetPhotoAttributes(HANType10Record hRecord, BdifFaceProperties value);
NResult N_API ANType10RecordGetPhotoAcquisitionSourceEx(HANType10Record hRecord, struct ANImageSourceType_ * pValue, NBool * pHasValue);
NResult N_API ANType10RecordGetPhotoAcquisitionSource(HANType10Record hRecord, BdifImageSourceType * pValue);

NResult N_API ANType10RecordGetVendorPhotoAcquisitionSourceN(HANType10Record hRecord, HNString * phValue);

NResult N_API ANType10RecordSetPhotoAcquisitionSourceEx(HANType10Record hRecord, const struct ANImageSourceType_ * pValue);

NResult N_API ANType10RecordSetPhotoAcquisitionSourceN(HANType10Record hRecord, BdifImageSourceType value, HNString hVendorValue);
#ifndef N_NO_ANSI_FUNC
NResult N_API ANType10RecordSetPhotoAcquisitionSourceA(HANType10Record hRecord, BdifImageSourceType value, const NAChar * szVendorValue);
#endif
#ifndef N_NO_UNICODE
NResult N_API ANType10RecordSetPhotoAcquisitionSourceW(HANType10Record hRecord, BdifImageSourceType value, const NWChar * szVendorValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API ANType10RecordSetPhotoAcquisitionSource(HANType10Record hRecord, BdifImageSourceType value, const NChar * szVendorValue);
#endif
#define ANType10RecordSetVendorPhotoAcquisitionSource N_FUNC_AW(ANType10RecordSetVendorPhotoAcquisitionSource)

NResult N_API ANType10RecordGetSubjectPoseAnglesEx(HANType10Record hRecord, struct ANPoseAngles_ * pValue, NBool * pHasValue);
NResult N_API ANType10RecordGetSubjectPoseAnglesYaw(HANType10Record hRecord, NInt * pValue);
NResult N_API ANType10RecordGetSubjectPoseAnglesPitch(HANType10Record hRecord, NInt * pValue);
NResult N_API ANType10RecordGetSubjectPoseAnglesRoll(HANType10Record hRecord, NInt * pValue);
NResult N_API ANType10RecordGetSubjectPoseAnglesYawUncertainty(HANType10Record hRecord, NInt * pValue);
NResult N_API ANType10RecordGetSubjectPoseAnglesPitchUncertainty(HANType10Record hRecord, NInt * pValue);
NResult N_API ANType10RecordGetSubjectPoseAnglesRollUncertainty(HANType10Record hRecord, NInt * pValue);
NResult N_API ANType10RecordGetSubjectPoseAngles(HANType10Record hRecord, NInt * pYaw, NInt * pPitch, NInt * pRoll, NInt * pYawUncertainty, NInt * pPitchUncertainty, NInt * pRollUncertainty);
NResult N_API ANType10RecordSetSubjectPoseAnglesEx(HANType10Record hRecord, const struct ANPoseAngles_ * pValue);
NResult N_API ANType10RecordSetSubjectPoseAngles(HANType10Record hRecord, NInt yaw, NInt pitch, NInt roll, NInt yawUncertainty, NInt pitchUncertainty, NInt rollUncertainty);
NResult N_API ANType10RecordGetSubjectFacialExpression(HANType10Record hRecord, BdifFaceExpression * pValue);
NResult N_API ANType10RecordSetSubjectFacialExpression(HANType10Record hRecord, BdifFaceExpression value);
NResult N_API ANType10RecordGetSubjectFacialAttributes(HANType10Record hRecord, BdifFaceProperties * pValue);
NResult N_API ANType10RecordSetSubjectFacialAttributes(HANType10Record hRecord, BdifFaceProperties value);
NResult N_API ANType10RecordGetSubjectEyeColor(HANType10Record hRecord, BdifEyeColor * pValue);
NResult N_API ANType10RecordSetSubjectEyeColor(HANType10Record hRecord, BdifEyeColor value);
NResult N_API ANType10RecordGetSubjectHairColorEx(HANType10Record hRecord, struct ANHairColor_ * pValue, NBool * pHasValue);
NResult N_API ANType10RecordGetSubjectHairColor(HANType10Record hRecord, BdifHairColor * pValue);
NResult N_API ANType10RecordGetBaldSubjectHairColor(HANType10Record hRecord, BdifHairColor * pValue);
NResult N_API ANType10RecordSetSubjectHairColorEx(HANType10Record hRecord, const struct ANHairColor_ * pValue);
NResult N_API ANType10RecordSetSubjectHairColor(HANType10Record hRecord, BdifHairColor value, BdifHairColor baldValue);
NResult N_API ANType10RecordGetSmtSize(HANType10Record hRecord, struct NSize_ * pValue, NBool * pHasValue);
NResult N_API ANType10RecordSetSmtSize(HANType10Record hRecord, const struct NSize_ * pValue);

#ifdef N_CPP
}
#endif

#endif // !AN_TYPE_10_RECORD_H_INCLUDED
