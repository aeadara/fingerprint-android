#ifndef N_SMART_CARDS_BIOMETRY_H_INCLUDED
#define N_SMART_CARDS_BIOMETRY_H_INCLUDED

#include <SmartCards/BerTag.h>

#ifdef N_CPP
extern "C"
{
#endif

typedef enum SCardBiometricType_
{
	scbtNone = 0x00,
	scbtMultipleBiometrics = 0x01,
	scbtFacialFeatures = 0x02,
	scbtVoice = 0x04,
	scbtFingerprint = 0x08,
	scbtIris = 0x10,
	scbtRetina = 0x20,
	scbtHandGeometry = 0x40,
	scbtSignatureDynamics = 0x80,
	scbtKeystrokeDynamics = 0x0100,
	scbtLipMovement = 0x0200,
	scbtThermalFaceImage = 0x0400,
	scbtThermalHandImage = 0x0800,
	scbtGait = 0x1000,
	scbtBodyOdor = 0x2000,
	scbtDna = 0x4000,
	scbtEarShape = 0x8000,
	scbtFingerGeometry = 0x010000,
	scbtPalmPrint = 0x020000,
	scbtVeinPattern = 0x040000,
	scbtFootPrint = 0x080000
} SCardBiometricType;

N_DECLARE_TYPE(SCardBiometricType)

typedef enum SCardBiometricSubtype_
{
	scbsNone = 0x00,
	scbsRight = 0x01,
	scbsLeft = 0x02,
	scbsThumb = 0x04,
	scbsPointerFinger = 0x08,
	scbsMiddleFinger = 0x0C,
	scbsRingFinger = 0x10,
	scbsLittleFinger = 0x14
} SCardBiometricSubtype;

N_DECLARE_TYPE(SCardBiometricSubtype)

typedef enum SCardChallengeQualifier_
{
	sccqUnspecified = 0,
	sccqUtf8Coding = 1
} SCardChallengeQualifier;

N_DECLARE_TYPE(SCardChallengeQualifier)

// SCARD_TAG_BIOMETRIC_INFORMATION_TEMPLATE

#define SCARD_BIT_TAG_ALGORITHM_REFERENCE                   0x80
#define SCARD_BIT_TAG_REFERENCE_DATA_QUALIFIER              0x83
#define SCARD_BIT_TAG_STANDARD_DATA_OBJECTS                 0xA0
#define SCARD_BIT_TAG_TAG_ALLOCATION_AUTHORITY_DATA_OBJECTS 0xA1
#define SCARD_BIT_TAG_BIOMETRIC_HEADER_TEMPLATE             SCARD_BIT_TAG_TAG_ALLOCATION_AUTHORITY_DATA_OBJECTS

// SCARD_BIT_TAG_BIOMETRIC_HEADER_TEMPLATE

#define SCARD_BIT_BHT_TAG_PATRON_HEADER_VERSION                   0x80
#define SCARD_BIT_BHT_TAG_INDEX                                   0x90
#define SCARD_BIT_BHT_TAG_BIOMETRIC_TYPE                          0x81
#define SCARD_BIT_BHT_TAG_BIOMETRIC_SUBTYPE                       0x82
#define SCARD_BIT_BHT_TAG_CREATION_DATE                           0x83
#define SCARD_BIT_BHT_TAG_CREATOR                                 0x84
#define SCARD_BIT_BHT_TAG_VALIDITY_PERIOD                         0x85
#define SCARD_BIT_BHT_TAG_PRODUCT_IDENTIFIER                      0x86
#define SCARD_BIT_BHT_TAG_FORMAT_OWNER                            0x87
#define SCARD_BIT_BHT_TAG_FORMAT_TYPE                             0x88
#define SCARD_BIT_BHT_TAG_BIOMETRIC_ALGORITHM_PARAMETERS_DATA     0x91
#define SCARD_BIT_BHT_TAG_BIOMETRIC_ALGORITHM_PARAMETERS_TEMPLATE 0xB1
#define SCARD_BIT_BHT_TAG_STANDARD_BHT                            0xA1
#define SCARD_BIT_BHT_TAG_PROPRIETARY_BHT                         0xA2

// SCARD_TAG_BIOMETRIC_DATA_TEMPLATE

#define SCARD_BDT_TAG_CHALLENGE_DATA                     0x80
#define SCARD_BDT_TAG_CHALLENGE_TEMPLATE                 0xA0
#define SCARD_BDT_TAG_STANDARD_BIOMETRIC_DATA            0x81
#define SCARD_BDT_TAG_STANDARD_BIOMETRIC_DATA_OBJECTS    0xA1
#define SCARD_BDT_TAG_PROPRIETARY_BIOMETRIC_DATA         0x82
#define SCARD_BDT_TAG_PROPRIETARY_BIOMETRIC_DATA_OBJECTS 0xA2

// SCARD_BDT_TAG_CHALLENGE_TEMPLATE

#define SCARD_BDT_CT_TAG_CHALLENGE_QUALIFIER 0x90
#define SCARD_BDT_CT_TAG_CHALLENGE           0x80

N_DECLARE_STATIC_OBJECT_TYPE(NSmartCardsBiometry)

#ifdef N_CPP
}
#endif

#endif // !N_SMART_CARDS_BIOMETRY_H_INCLUDED
