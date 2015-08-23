#ifndef CBEFF_RECORD_H_INCLUDED
#define CBEFF_RECORD_H_INCLUDED

#include <Core/NObject.h>
#include <Biometrics/Standards/BdifTypes.h>
#include <Biometrics/Standards/CbeffBiometricOrganizations.h>
#include <Biometrics/Standards/CbeffBdbFormatIdentifiers.h>
#include <Biometrics/Standards/CbeffPatronFormatIdentifiers.h>
#include <Biometrics/Standards/CbeffProductIdentifiers.h>
#include <Biometrics/Standards/CbeffDeviceIdentifiers.h>
#include <Biometrics/NTemplate.h>
#include <Biometrics/Standards/FMRecord.h>
#include <Biometrics/Standards/FIRecord.h>
#include <Biometrics/Standards/FCRecord.h>
#include <Biometrics/Standards/IIRecord.h>
#include <Biometrics/Standards/ANTemplate.h>
#include <Biometrics/Standards/ANRecord.h>

#ifdef N_CPP
extern "C"
{
#endif

N_DECLARE_OBJECT_TYPE(CbeffRecord, NObject)

typedef enum CbeffIntegrityOptions_
{
	cbeffioMAC = 0,
	cbeffioSigned = 1
} CbeffIntegrityOptions;

N_DECLARE_TYPE(CbeffIntegrityOptions)

// Defines the type of biometric technology
typedef enum CbeffBiometricType_
{
	cbeffbtNoInformationGiven         = 0x00000000,
	cbeffbtMultipleBiometricTypesUsed = 0x00000001,
	cbeffbtFace                       = 0x00000002,
	cbeffbtVoice                      = 0x00000004,
	cbeffbtFinger                     = 0x00000008,
	cbeffbtIris                       = 0x00000010,
	cbeffbtRetina                     = 0x00000020,
	cbeffbtHandGeometry               = 0x00000040,
	cbeffbtSignatureSign              = 0x00000080,
	cbeffbtKeystrokeDynamics          = 0x00000100,
	cbeffbtLipMovement                = 0x00000200,
	cbeffbtGait                       = 0x00001000,
	cbeffbtVein                       = 0x00002000,
	cbeffbtDNA                        = 0x00004000,
	cbeffbtEar                        = 0x00008000,
	cbeffbtFoot                       = 0x00010000,
	cbeffbtScent                      = 0x00020000,
	cbeffbtOther                      = 0x40000000,
	cbeffbtPassword                   = 0x80000000
} CbeffBiometricType;

N_DECLARE_TYPE(CbeffBiometricType)

// More specifically defines the type of biometric data
typedef enum CbeffBiometricSubType_
{
	// ANIS/INCITS 398 and and ISO_IEC_19785_1_2006 biometric subtypes
	cbeffbstNoInformationGiven = 0x00,
	cbeffbstLeft               = 0x01,
	cbeffbstRight              = 0x02,

	// ANIS/INCITS 398 biometric subtypes
	cbeffbstThumb          = 0x04,
	cbeffbstPointerFinger  = 0x08,
	cbeffbstMiddleFinger   = 0x10,
	cbeffbstRingFinger     = 0x20,
	cbeffbstLittleFinger   = 0x40,
	cbeffbstVeinMask       = 0x80,
	cbeffbstVeinPalm       = 0x04,
	cbeffbstVeinBackOfHand = 0x08,
	cbeffbstVeinWrist      = 0x10,

	// ISO_IEC_19785_1_2006 biometric subtypes
	cbeffbstLeftThumb          = 0x05,
	cbeffbstLeftPointerFinger  = 0x09,
	cbeffbstLeftMiddleFinger   = 0x11,
	cbeffbstLeftRingFinger     = 0x21,
	cbeffbstLeftLittleFinger   = 0x41,
	cbeffbstRightThumb         = 0x06,
	cbeffbstRightPointerFinger = 0x0A,
	cbeffbstRightMiddleFinger  = 0x12,
	cbeffbstRighttRingFinger   = 0x22,
	cbeffbstRightLittleFinger  = 0x42,
	cbeffbstLeftPalm           = 0x85,
	cbeffbstLeftBackOfHand     = 0x89,
	cbeffbstLeftWrist          = 0x91,
	cbeffbstRightPalm          = 0x86,
	cbeffbstRightBackOfHand    = 0x8A,
	cbeffbstRightWrist         = 0x92
} CbeffBiometricSubType;

N_DECLARE_TYPE(CbeffBiometricSubType)

// Specifies the intended use of the data
typedef enum CbeffPurpose_
{
	cbeffpNoInformationGiven          = 0x00,
	cbeffpVerify                      = 0x01,
	cbeffpIdentify                    = 0x02,
	cbeffpEnroll                      = 0x03,
	cbeffpEnrollForVerificationOnly   = 0x04,
	cbeffpEnrollForIdentificationOnly = 0x05,
	cbeffpAudit                       = 0x06
} CbeffPurpose;

N_DECLARE_TYPE(CbeffPurpose)

typedef enum CbeffProcessedLevel_
{
	cbeffplNoInformationGiven = 0x00,
	cbeffplRaw = 0x01,
	cbeffplIntermediate = 0x02,
	cbeffplProcessed = 0x04,
	cbeffplScore = 0x08,
	cbeffplDecision = 0x09,
	cbeffplBiographic = 0x0A
} CbeffProcessedLevel;

N_DECLARE_TYPE(CbeffProcessedLevel)

struct CbeffTimeInterval_
{
	NDateTime from;
	NDateTime to;
};
#ifndef CBEFF_RECORD_HPP_INCLUDED
typedef struct CbeffTimeInterval_ CbeffTimeInterval;
#endif

N_DECLARE_TYPE(CbeffTimeInterval)

#define CBEFF_PATRON_FORMAT_INCITS_TC_M1_BIOMETRICS_A                              0x001B0001
#define CBEFF_PATRON_FORMAT_INCITS_TC_M1_BIOMETRICS_B                              0x001B0002
#define CBEFF_PATRON_FORMAT_NIST_D                                                 0x000F0001
#define CBEFF_PATRON_FORMAT_ISO_IEC_JTC_1_SC_37_BIOMETRICS_SIMPLE_BYTE_ORIENTED    0x01010002
#define CBEFF_PATRON_FORMAT_ISO_IEC_JTC_1_SC_37_BIOMETRICS_PRESENCE_BYTE_ORIENTED  0x01010003
#define CBEFF_PATRON_FORMAT_ISO_IEC_JTC_1_SC_37_BIOMETRICS_COMPLEX                 0x01010006
#define CBEFF_PATRON_FORMAT_ISO_IEC_JTC_1_SC_37_BIOMETRICS_WITH_ADD_ELEM           0x0101000A

NResult N_API CbeffRecordCreate(NUInt patronFormat, HCbeffRecord * phRecord);
NResult N_API CbeffRecordIsSupportedCbeffFormat(NUInt patronFormat, NBool * pValue);

NResult N_API CbeffRecordCreateFromStream(HNStream hStream, NUInt patronFormat, HCbeffRecord * phRecord);
NResult N_API CbeffRecordCreateFromMemoryN(HNBuffer hBuffer, NUInt patronFormat, NSizeType * pSize, HCbeffRecord * phRecord);
NResult N_API CbeffRecordCreateFromMemory(const void * pBuffer, NSizeType bufferSize, NUInt patronFormat, NSizeType * pSize, HCbeffRecord * phRecord);

NResult N_API CbeffRecordCreateFromDataN(NUInt bdbFormat, HNBuffer hBdbBuffer, NUInt patronFormat, HCbeffRecord * phRecord);
NResult N_API CbeffRecordCreateFromData(NUInt bdbFormat, const void * pBdbBuffer, NSizeType bdbBufferSize, NUInt patronFormat, HCbeffRecord * phRecord);
NResult N_API CbeffRecordCreateFromIIRecord(HIIRecord hIIRecord, NUInt patronFormat, HCbeffRecord * phRecord);
NResult N_API CbeffRecordCreateFromFCRecord(HFCRecord hFCRecord, NUInt patronFormat, HCbeffRecord * phRecord);
NResult N_API CbeffRecordCreateFromFIRecord(HFIRecord hFIRecord, NUInt patronFormat, HCbeffRecord * phRecord);
NResult N_API CbeffRecordCreateFromFMRecord(HFMRecord hFMRecord, NUInt patronFormat, HCbeffRecord * phRecord);
NResult N_API CbeffRecordCreateFromANTemplate(HANTemplate hANTemplate, NUInt patronFormat, HCbeffRecord * phRecord);
NResult N_API CbeffRecordCreateFromANRecord(HANRecord hANRecord, NUInt patronFormat, HCbeffRecord * phRecord);

NResult N_API CbeffRecordGetPatronFormat(HCbeffRecord hRecord, NUInt * pValue);
NResult N_API CbeffRecordGetEncryption(HCbeffRecord hRecord, NBool * pValue);
NResult N_API CbeffRecordSetEncryption(HCbeffRecord hRecord, NBool value);
NResult N_API CbeffRecordGetIntegrity(HCbeffRecord hRecord, NBool * pValue);
NResult N_API CbeffRecordSetIntegrity(HCbeffRecord hRecord, NBool value);
NResult N_API CbeffRecordGetIntegrityOptions(HCbeffRecord hRecord, CbeffIntegrityOptions * pValue, NBool * pHasValue);
NResult N_API CbeffRecordSetIntegrityOptions(HCbeffRecord hRecord, const CbeffIntegrityOptions * pValue);
NResult N_API CbeffRecordGetBdbFormat(HCbeffRecord hRecord, NUInt * pValue);
NResult N_API CbeffRecordSetBdbFormat(HCbeffRecord hRecord, NUInt value);
NResult N_API CbeffRecordGetBdbBuffer(HCbeffRecord hRecord, HNBuffer * phValue);
NResult N_API CbeffRecordSetBdbBuffer(HCbeffRecord hRecord, HNBuffer hValue);
NResult N_API CbeffRecordGetBiometricType(HCbeffRecord hRecord, CbeffBiometricType * pValue);
NResult N_API CbeffRecordSetBiometricType(HCbeffRecord hRecord, CbeffBiometricType value);
NResult N_API CbeffRecordGetBiometricSubType(HCbeffRecord hRecord, CbeffBiometricSubType * pValue);
NResult N_API CbeffRecordSetBiometricSubType(HCbeffRecord hRecord, CbeffBiometricSubType value);
NResult N_API CbeffRecordGetChallengeResponse(HCbeffRecord hRecord, HNBuffer * phValue);
NResult N_API CbeffRecordSetChallengeResponse(HCbeffRecord hRecord, HNBuffer hValue);
NResult N_API CbeffRecordGetBdbCreationDate(HCbeffRecord hRecord, NDateTime_ * pValue, NBool * pHasValue);
NResult N_API CbeffRecordSetBdbCreationDate(HCbeffRecord hRecord, const NDateTime_ * pValue);
NResult N_API CbeffRecordGetBdbIndex(HCbeffRecord hRecord, HNBuffer * phValue);
NResult N_API CbeffRecordSetBdbIndex(HCbeffRecord hRecord, HNBuffer hValue);
NResult N_API CbeffRecordGetProduct(HCbeffRecord hRecord, NUInt * pValue, NBool * pHasValue);
NResult N_API CbeffRecordSetProduct(HCbeffRecord hRecord, const NUInt * pValue);
NResult N_API CbeffRecordGetCaptureDevice(HCbeffRecord hRecord, NUInt * pValue, NBool * pHasValue);
NResult N_API CbeffRecordSetCaptureDevice(HCbeffRecord hRecord, const NUInt * pValue);
NResult N_API CbeffRecordGetFeatureExtractionAlgorithm(HCbeffRecord hRecord, NUInt * pValue, NBool * pHasValue);
NResult N_API CbeffRecordSetFeatureExtractionAlgorithm(HCbeffRecord hRecord, const NUInt * pValue);
NResult N_API CbeffRecordGetComparisonAlgorithm(HCbeffRecord hRecord, NUInt * pValue, NBool * pHasValue);
NResult N_API CbeffRecordSetComparisonAlgorithm(HCbeffRecord hRecord, const NUInt * pValue);
NResult N_API CbeffRecordGetQualityAlgorithm(HCbeffRecord hRecord, NUInt * pValue, NBool * pHasValue);
NResult N_API CbeffRecordSetQualityAlgorithm(HCbeffRecord hRecord, const NUInt * pValue);
NResult N_API CbeffRecordGetCompressionAlgorithm(HCbeffRecord hRecord, NUInt * pValue, NBool * pHasValue);
NResult N_API CbeffRecordSetCompressionAlgorithm(HCbeffRecord hRecord, const NUInt * pValue);
NResult N_API CbeffRecordGetProcessedLevel(HCbeffRecord hRecord, CbeffProcessedLevel * pValue);
NResult N_API CbeffRecordSetProcessedLevel(HCbeffRecord hRecord, CbeffProcessedLevel value);
NResult N_API CbeffRecordGetPurpose(HCbeffRecord hRecord, CbeffPurpose * pValue);
NResult N_API CbeffRecordSetPurpose(HCbeffRecord hRecord, CbeffPurpose value);
NResult N_API CbeffRecordGetQuality(HCbeffRecord hRecord, NByte * pValue, NBool * pHasValue);
NResult N_API CbeffRecordSetQuality(HCbeffRecord hRecord, const NByte * pValue);
NResult N_API CbeffRecordGetBdbValidityPeriod(HCbeffRecord hRecord, struct CbeffTimeInterval_ * pValue, NBool * pHasValue);
NResult N_API CbeffRecordSetBdbValidityPeriod(HCbeffRecord hRecord, const struct CbeffTimeInterval_ * pValue);
NResult N_API CbeffRecordGetBirCreationDate(HCbeffRecord hRecord, NDateTime_ * pValue, NBool * pHasValue);
NResult N_API CbeffRecordSetBirCreationDate(HCbeffRecord hRecord, const NDateTime_ * pValue);
NResult N_API CbeffRecordGetCreator(HCbeffRecord hRecord, HNString * phValue);
NResult N_API CbeffRecordSetCreator(HCbeffRecord hRecord, HNString hValue);
NResult N_API CbeffRecordGetBirIndex(HCbeffRecord hRecord, HNBuffer * phValue);
NResult N_API CbeffRecordSetBirIndex(HCbeffRecord hRecord, HNBuffer hValue);
NResult N_API CbeffRecordGetPayload(HCbeffRecord hRecord, HNBuffer * phValue);
NResult N_API CbeffRecordSetPayload(HCbeffRecord hRecord, HNBuffer hValue);
NResult N_API CbeffRecordGetBirValidityPeriod(HCbeffRecord hRecord, struct CbeffTimeInterval_ * pValue, NBool * pHasValue);
NResult N_API CbeffRecordSetBirValidityPeriod(HCbeffRecord hRecord, const struct CbeffTimeInterval_ * pValue);
NResult N_API CbeffRecordGetCbeffVersion(HCbeffRecord hRecord, NByte * pValue);
NResult N_API CbeffRecordGetPatronHeaderVersion(HCbeffRecord hRecord, NByte * pValue);
NResult N_API CbeffRecordGetFascnBuffer(HCbeffRecord hRecord, HNBuffer * phValue);
NResult N_API CbeffRecordSetFascnBuffer(HCbeffRecord hRecord, HNBuffer hValue);
NResult N_API CbeffRecordGetSbFormat(HCbeffRecord hRecord, NUInt * pValue, NBool * pHasValue);
NResult N_API CbeffRecordSetSbFormat(HCbeffRecord hRecord, const NUInt * pValue);
NResult N_API CbeffRecordGetSbBuffer(HCbeffRecord hRecord, HNBuffer * phValue);
NResult N_API CbeffRecordSetSbBuffer(HCbeffRecord hRecord, HNBuffer hValue);

NResult N_API CbeffRecordGetRecordCount(HCbeffRecord hRecord, NInt * pValue);
NResult N_API CbeffRecordGetRecord(HCbeffRecord hRecord, NInt index, HCbeffRecord * phValue);
NResult N_API CbeffRecordGetRecords(HCbeffRecord hRecord, HCbeffRecord * * parhValues, NInt * pValueCount);
NResult N_API CbeffRecordSetRecord(HCbeffRecord hRecord, NInt index, HCbeffRecord hValue);
NResult N_API CbeffRecordAddRecord(HCbeffRecord hRecord, HCbeffRecord hValue, NInt * pIndex);
NResult N_API CbeffRecordInsertRecord(HCbeffRecord hRecord, NInt index, HCbeffRecord hValue);
NResult N_API CbeffRecordRemoveRecordAt(HCbeffRecord hRecord, NInt index);
NResult N_API CbeffRecordClearRecords(HCbeffRecord hRecord);

#ifdef N_CPP
}
#endif

#endif // !CBEFF_RECORD_H_INCLUDED
