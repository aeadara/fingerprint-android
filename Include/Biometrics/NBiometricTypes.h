#ifndef N_BIOMETRIC_TYPES_H_INCLUDED
#define N_BIOMETRIC_TYPES_H_INCLUDED

#include <Core/NTypes.h>

#ifdef N_CPP
extern "C"
{
#endif

#define N_BIOMETRIC_QUALITY_MIN 0
#define N_BIOMETRIC_QUALITY_MAX 100
#define N_BIOMETRIC_QUALITY_UNKNOWN 254
#define N_BIOMETRIC_QUALITY_FAILED 255

#define N_PHRASE_ID_UNKNOWN 0

typedef enum NBiometricType_
{
	nbtNone = 0x000000,
	nbtMultipleBiometrics = 0x000001,
	nbtFace = 0x000002,
	nbtFacialFeatures = nbtFace,
	nbtVoice = 0x000004,
	nbtFinger = 0x000008,
	nbtFingerprint = nbtFinger,
	nbtIris = 0x000010,
	nbtRetina = 0x000020,
	nbtHandGeometry = 0x000040,
	nbtSignatureOrSign = 0x000080,
	nbtSignatureDynamics = nbtSignatureOrSign,
	nbtKeystroke = 0x000100,
	nbtKeystrokeDynamics = nbtKeystroke,
	nbtLipMovement = 0x000200,
	nbtThermalFace = 0x000400,
	nbtThermalHand = 0x000800,
	nbtThermalFaceImage = nbtThermalFace,
	nbtThermalHandImage = nbtThermalHand,
	nbtGait = 0x001000,
	nbtScent = 0x002000,
	nbtBodyOdor = nbtScent,
	nbtDna = 0x004000,
	nbtEar = 0x008000,
	nbtEarShape = nbtEar,
	nbtFingerGeometry = 0x010000,
	nbtPalm = 0x020000,
	nbtPalmPrint = nbtPalm,
	nbtVein = 0x040000,
	nbtVeinPattern = nbtVein,
	nbtFoot = 0x080000,
	nbtFootPrint = nbtFoot,
	nbtPalmGeometry = 0x100000,
	nbtAll = 0x1FFFFF
} NBiometricType;

N_DECLARE_TYPE(NBiometricType)

typedef enum NBiometricSubtype_
{
	nbstNone = 0x000000,
	nbstLeft = 0x000001,
	nbstRight = 0x000002,
	nbstLeftThumb = 0x000004,
	nbstLeftPointerFinger = 0x000008,
	nbstLeftMiddleFinger = 0x000010,
	nbstLeftRingFinger = 0x000020,
	nbstLeftLittleFinger = 0x000040,
	nbstRightThumb = 0x000080,
	nbstRightPointerFinger = 0x000100,
	nbstRightMiddleFinger = 0x000200,
	nbstRightRingFinger = 0x000400,
	nbstRightLittleFinger = 0x000800,
	nbstLeftPalm = 0x001000,
	nbstLeftBackOfHand = 0x002000,
	nbstLeftWrist = 0x004000,
	nbstRightPalm = 0x008000,
	nbstRightBackOfHand = 0x010000,
	nbstRightWrist = 0x020000
} NBiometricSubtype;

N_DECLARE_TYPE(NBiometricSubtype)

typedef enum NBiometricStatus_
{
	nbsNone = 0,
	nbsOk = 1,
	nbsCanceled = 2,
	nbsTimeout = 3,
	nbsSourceMissing = 9,
	nbsCleaningNeeded = 10,
	nbsObjectsNotRemoved = 20,
	nbsObjectMissing = 21,
	nbsObjectNotFound = 22,
	nbsTooFewObjects = 23,
	nbsTooManyObjects = 24,
	nbsBadObjectSequence = 25,
	nbsSpoofDetected = 30,
	nbsBadObject = 40,
	nbsBadDynamicRange = 41,
	nbsBadExposure = 42,
	nbsBadSharpness = 43,
	nbsTooFewFeatures = 49,
	nbsTooSoft = 51,
	nbsTooHard = 52,
	nbsBadPosition = 60,
	nbsTooNorth = 61,
	nbsTooEast = 62,
	nbsTooSouth = 63,
	nbsTooWest = 64,
	nbsTooClose = 65,
	nbsTooFar = 66,
	nbsBadSpeed = 70,
	nbsTooSlow = 71,
	nbsTooFast = 72,
	nbsBadSize = 80,
	nbsTooShort = 81,
	nbsTooLong = 82,
	nbsTooNarrow = 83,
	nbsTooWide = 84,
	nbsTooSkewed = 91,
	nbsWrongDirection = 92,
	nbsTooFewSamples = 100,
	nbsIncompatibleSamples = 101,
	nbsSourceNotFound = 501,
	nbsIncompatibleSource = 502,
	nbsIdNotFound = 601,
	nbsDuplicateId = 602,
	nbsMatchNotFound = 610,
	nbsDuplicateFound = 611,
	nbsInvalidOperations = 900,
	nbsInvalidId = 901,
	nbsInvalidQuery = 902,
	nbsInvalidPropertyValue = 903,
	nbsInvalidFieldValue = 904,
	nbsInvalidSampleResolution = 905,
	nbsOperationNotSupported = 990,
	nbsOperationNotActivated = 991,
	nbsSourceError = 996,
	nbsCaptureError = 997,
	nbsCommunicationError = 998,
	nbsInternalError = 999
} NBiometricStatus;

N_DECLARE_TYPE(NBiometricStatus)

typedef enum NFImpressionType_
{
	nfitLiveScanPlain = 0,
	nfitLiveScanRolled = 1,
	nfitNonliveScanPlain = 2,
	nfitNonliveScanRolled = 3,
	nfitLatentImpression = 4,
	nfitLatentTracing = 5,
	nfitLatentPhoto = 6,
	nfitLatentLift = 7,
	nfitLiveScanVerticalSwipe = 8,
	nfitSwipe = nfitLiveScanVerticalSwipe,
	nfitLiveScanContactless = 9,
	nfitLiveScanPalm = 10,
	nfitNonliveScanPalm = 11,
	nfitLatentPalmImpression = 12,
	nfitLatentPalmTracing = 13,
	nfitLatentPalmPhoto = 14,
	nfitLatentPalmLift = 15,
	nfitLiveScanOpticalContactPlain = 20,
	nfitLiveScanOpticalContactRolled = 21,
	nfitLiveScanNonOpticalContactPlain = 22,
	nfitLiveScanNonOpticalContactRolled = 23,
	nfitLiveScanOpticalContactlessPlain = 24,
	nfitLiveScanOpticalContactlessRolled = 25,
	nfitLiveScanNonOpticalContactlessPlain = 26,
	nfitLiveScanNonOpticalContactlessRolled = 27,
	nfitOther = 28,
	nfitUnknown = 29
} NFImpressionType;

N_DECLARE_TYPE(NFImpressionType)

typedef enum NFPosition_
{
	nfpUnknown = 0,
	nfpRightThumb = 1,
	nfpRightIndexFinger = 2,
	nfpRightIndex = nfpRightIndexFinger,
	nfpRightMiddleFinger = 3,
	nfpRightMiddle = nfpRightMiddleFinger,
	nfpRightRingFinger = 4,
	nfpRightRing = nfpRightRingFinger,
	nfpRightLittleFinger = 5,
	nfpRightLittle = nfpRightLittleFinger,
	nfpLeftThumb = 6,
	nfpLeftIndexFinger = 7,
	nfpLeftIndex = nfpLeftIndexFinger,
	nfpLeftMiddleFinger = 8,
	nfpLeftMiddle = nfpLeftMiddleFinger,
	nfpLeftRingFinger = 9,
	nfpLeftRing = nfpLeftRingFinger,
	nfpLeftLittleFinger = 10,
	nfpLeftLittle = nfpLeftLittleFinger,
	nfpPlainRightThumb = 11,
	nfpPlainLeftThumb = 12,
	nfpPlainRightFourFingers = 13,
	nfpPlainLeftFourFingers = 14,
	nfpPlainThumbs = 15,
	nfpUnknownPalm = 20,
	nfpRightFullPalm = 21,
	nfpRightWritersPalm = 22,
	nfpLeftFullPalm = 23,
	nfpLeftWritersPalm = 24,
	nfpRightLowerPalm = 25,
	nfpRightUpperPalm = 26,
	nfpLeftLowerPalm = 27,
	nfpLeftUpperPalm = 28,
	nfpRightOther = 29,
	nfpLeftOther = 30,
	nfpRightInterdigital = 31,
	nfpRightThenar = 32,
	nfpRightHypothenar = 33,
	nfpLeftInterdigital = 34,
	nfpLeftThenar = 35,
	nfpLeftHypothenar = 36,
	nfpRightIndexMiddleFingers = 40,
	nfpRightMiddleRingFingers = 41,
	nfpRightRingLittleFingers = 42,
	nfpLeftIndexMiddleFingers = 43,
	nfpLeftMiddleRingFingers = 44,
	nfpLeftRingLittleFingers = 45,
	nfpRightIndexLeftIndexFingers = 46,
	nfpRightIndexMiddleRingFingers = 47,
	nfpRightMiddleRingLittleFingers = 48,
	nfpLeftIndexMiddleRingFingers = 49,
	nfpLeftMiddleRingLittleFingers = 50,
	nfpUnknownTwoFingers = -2,
	nfpUnknownThreeFingers = -3,
	nfpUnknownFourFingers = -4
} NFPosition;

N_DECLARE_TYPE(NFPosition)

typedef enum NEPosition_
{
	nepUnknown = 0,
	nepRight = 1,
	nepLeft = 2,
	nepBoth = 3
} NEPosition;

N_DECLARE_TYPE(NEPosition)

typedef enum NFPatternClass_
{
	nfpcUnknown = 0,
	nfpcPlainArch = 1,
	nfpcTentedArch = 2,
	nfpcRadialLoop = 3,
	nfpcUlnarLoop = 4,
	nfpcPlainWhorl = 5,
	nfpcCentralPocketLoop = 6,
	nfpcDoubleLoop = 7,
	nfpcAccidentalWhorl = 8,
	nfpcWhorl = 9,
	nfpcRightSlantLoop = 10,
	nfpcLeftSlantLoop = 11,
	nfpcScar = 12,
	nfpcAmputation = 15
} NFPatternClass;

N_DECLARE_TYPE(NFPatternClass)

typedef enum NFMinutiaFormat_
{
	nfmfNone = 0,
	nfmfHasQuality = 1,
	nfmfHasCurvature = 2,
	nfmfHasG = 4
} NFMinutiaFormat;

N_DECLARE_TYPE(NFMinutiaFormat)

typedef enum NFMinutiaType_
{
	nfmtUnknown = 0,
	nfmtEnd = 1,
	nfmtBifurcation = 2,
	nfmtOther = 3
} NFMinutiaType;

N_DECLARE_TYPE(NFMinutiaType)

struct NFMinutia_
{
	NUShort X;
	NUShort Y;
	NFMinutiaType Type;
	NByte Angle;
	NByte Quality;
	NByte Curvature;
	NByte G;
};
#ifndef N_BIOMETRIC_TYPES_HPP_INCLUDED
typedef struct NFMinutia_ NFMinutia;
#endif

N_DECLARE_TYPE(NFMinutia)

NResult N_API NFMinutiaToStringN(const struct NFMinutia_ * pValue, HNString hFormat, HNString * phValue);
NResult N_API NFMinutiaToStringA(const struct NFMinutia_ * pValue, const NAChar * szFormat, HNString * phValue);
#ifndef N_NO_UNICODE
NResult N_API NFMinutiaToStringW(const struct NFMinutia_ * pValue, const NWChar * szFormat, HNString * phValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NFMinutiaToString(const NFMinutia * pValue, const NChar * szFormat, HNString * phValue);
#endif
#define NFMinutiaToString N_FUNC_AW(NFMinutiaToString)

typedef enum NFRidgeCountsType_
{
	nfrctNone = 0,
	nfrctFourNeighbors = 1,
	nfrctEightNeighbors = 2,
	nfrctFourNeighborsWithIndexes = 5,
	nfrctEightNeighborsWithIndexes = 6,
	nfrctUnspecified = 128 + 4
} NFRidgeCountsType;

N_DECLARE_TYPE(NFRidgeCountsType)

struct NFMinutiaNeighbor_
{
	NInt Index;
	NByte RidgeCount;
};
#ifndef N_BIOMETRIC_TYPES_HPP_INCLUDED
typedef struct NFMinutiaNeighbor_ NFMinutiaNeighbor;
#endif

N_DECLARE_TYPE(NFMinutiaNeighbor)

NResult N_API NFMinutiaNeighborToStringN(const struct NFMinutiaNeighbor_ * pValue, HNString hFormat, HNString * phValue);
NResult N_API NFMinutiaNeighborToStringA(const struct NFMinutiaNeighbor_ * pValue, const NAChar * szFormat, HNString * phValue);
#ifndef N_NO_UNICODE
NResult N_API NFMinutiaNeighborToStringW(const struct NFMinutiaNeighbor_ * pValue, const NWChar * szFormat, HNString * phValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NFMinutiaNeighborToString(const NFMinutiaNeighbor * pValue, const NChar * szFormat, HNString * phValue);
#endif
#define NFMinutiaNeighborToString N_FUNC_AW(NFMinutiaNeighborToString)

struct NFCore_
{
	NUShort X;
	NUShort Y;
	NInt Angle;
};
#ifndef N_BIOMETRIC_TYPES_HPP_INCLUDED
typedef struct NFCore_ NFCore;
#endif

N_DECLARE_TYPE(NFCore)

NResult N_API NFCoreToStringN(const struct NFCore_ * pValue, HNString hFormat, HNString * phValue);
NResult N_API NFCoreToStringA(const struct NFCore_ * pValue, const NAChar * szFormat, HNString * phValue);
#ifndef N_NO_UNICODE
NResult N_API NFCoreToStringW(const struct NFCore_ * pValue, const NWChar * szFormat, HNString * phValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NFCoreToString(const NFCore * pValue, const NChar * szFormat, HNString * phValue);
#endif
#define NFCoreToString N_FUNC_AW(NFCoreToString)

struct NFDelta_
{
	NUShort X;
	NUShort Y;
	NInt Angle1;
	NInt Angle2;
	NInt Angle3;
};
#ifndef N_BIOMETRIC_TYPES_HPP_INCLUDED
typedef struct NFDelta_ NFDelta;
#endif

N_DECLARE_TYPE(NFDelta)

NResult N_API NFDeltaToStringN(const struct NFDelta_ * pValue, HNString hFormat, HNString * phValue);
NResult N_API NFDeltaToStringA(const struct NFDelta_ * pValue, const NAChar * szFormat, HNString * phValue);
#ifndef N_NO_UNICODE
NResult N_API NFDeltaToStringW(const struct NFDelta_ * pValue, const NWChar * szFormat, HNString * phValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NFDeltaToString(const NFDelta * pValue, const NChar * szFormat, HNString * phValue);
#endif
#define NFDeltaToString N_FUNC_AW(NFDeltaToString)

struct NFDoubleCore_
{
	NUShort X;
	NUShort Y;
};
#ifndef N_BIOMETRIC_TYPES_HPP_INCLUDED
typedef struct NFDoubleCore_ NFDoubleCore;
#endif

N_DECLARE_TYPE(NFDoubleCore)

NResult N_API NFDoubleCoreToStringN(const struct NFDoubleCore_ * pValue, HNString hFormat, HNString * phValue);
NResult N_API NFDoubleCoreToStringA(const struct NFDoubleCore_ * pValue, const NAChar * szFormat, HNString * phValue);
#ifndef N_NO_UNICODE
NResult N_API NFDoubleCoreToStringW(const struct NFDoubleCore_ * pValue, const NWChar * szFormat, HNString * phValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NFDoubleCoreToString(const NFDoubleCore * pValue, const NChar * szFormat, HNString * phValue);
#endif
#define NFDoubleCoreToString N_FUNC_AW(NFDoubleCoreToString)

struct NLFeaturePoint_
{
	NUShort Code;
	NUShort X;
	NUShort Y;
	NByte Confidence;
};
#ifndef N_BIOMETRIC_TYPES_HPP_INCLUDED
typedef struct NLFeaturePoint_ NLFeaturePoint;
#endif

N_DECLARE_TYPE(NLFeaturePoint)

NResult N_API NLFeaturePointToStringN(const struct NLFeaturePoint_ * pValue, HNString hFormat, HNString * phValue);
NResult N_API NLFeaturePointToStringA(const struct NLFeaturePoint_ * pValue, const NAChar * szFormat, HNString * phValue);
#ifndef N_NO_UNICODE
NResult N_API NLFeaturePointToStringW(const struct NLFeaturePoint_ * pValue, const NWChar * szFormat, HNString * phValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NLFeaturePointToString(const NLFeaturePoint * pValue, const NChar * szFormat, HNString * phValue);
#endif
#define NLFeaturePointToString N_FUNC_AW(NLFeaturePointToString)

typedef enum NGender_
{
	ngUnspecified = 0,
	ngMale = 1,
	ngFemale = 2,
	ngUnknown = 255
} NGender;

N_DECLARE_TYPE(NGender)

typedef enum NLProperties_
{
	nlpNotSpecified = 0,
	nlpSpecified = 0x000001,
	nlpGlasses = 0x000002,
	nlpMoustache = 0x000004,
	nlpBeard = 0x000008,
	nlpTeethVisible = 0x000010,
	nlpBlink = 0x000020,
	nlpMouthOpen = 0x000040,
	nlpLeftEyePatch = 0x000080,
	nlpRightEyePatch = 0x000100,
	nlpBothEyePatch = 0x000200,
	nlpDarkGlasses = 0x000400,
	nlpDistortingCondition = 0x000800,
	nlpHat = 0x01000000,
	nlpScarf = 0x02000000,
	nlpNoEar = 0x04000000
} NLProperties;

N_DECLARE_TYPE(NLProperties)

typedef enum NLExpression_
{
	nleUnspecified = 0,
	nleNeutral = 1,
	nleSmile = 2,
	nleSmileOpenedJaw = 3,
	nleRaisedBrows = 4,
	nleEyesAway = 5,
	nleSquinting = 6,
	nleFrowning = 7,
	nleUnknown = 0xFFFF
} NLExpression;

N_DECLARE_TYPE(NLExpression)

typedef enum NEImageType_
{
	neitUncropped = 1,
	neitVga = 2,
	neitCropped = 3,
	neitCroppedAndMasked = 7,
} NEImageType;

N_DECLARE_TYPE(NEImageType)

typedef enum NfiqQuality_
{
	nfqPoor = 5,
	nfqFair = 4,
	nfqGood = 3,
	nfqVeryGood = 2,
	nfqExcellent = 1,
	nfqUnknown = 0
} NfiqQuality;

N_DECLARE_TYPE(NfiqQuality)

NBool N_API NBiometricTypeIsValid(NBiometricType value);

NBool N_API NBiometricSubtypeIsValid(NBiometricSubtype value);

NBool N_API NBiometricStatusIsValid(NBiometricStatus value);
NBool N_API NBiometricStatusIsFinal(NBiometricStatus value);

NBool N_API NFImpressionTypeIsValidFinger(NFImpressionType value);
NBool N_API NFImpressionTypeIsValidPalm(NFImpressionType value);
NBool N_API NFImpressionTypeIsValid(NFImpressionType value);
NBool N_API NFImpressionTypeIsGeneric(NFImpressionType value);
NBool N_API NFImpressionTypeIsFinger(NFImpressionType value);
NBool N_API NFImpressionTypeIsPalm(NFImpressionType value);
NFImpressionType N_API NFImpressionTypeToFinger(NFImpressionType value);
NBool N_API NFImpressionTypeIsPlain(NFImpressionType value);
NBool N_API NFImpressionTypeIsRolled(NFImpressionType value);
NBool N_API NFImpressionTypeIsSwipe(NFImpressionType value);
NBool N_API NFImpressionTypeIsContactless(NFImpressionType value);
NBool N_API NFImpressionTypeIsContact(NFImpressionType value);
NBool N_API NFImpressionTypeIsLiveScan(NFImpressionType value);
NBool N_API NFImpressionTypeIsNonliveScan(NFImpressionType value);
NBool N_API NFImpressionTypeIsLatent(NFImpressionType value);
NBool N_API NFImpressionTypeIsOptical(NFImpressionType value);
NBool N_API NFImpressionTypeIsNonOptical(NFImpressionType value);
NBool N_API NFImpressionTypeIsCompatibleWith(NFImpressionType value, NFImpressionType otherValue);
NResult N_API NFImpressionTypeIsOneOf(NFImpressionType value, NFImpressionType * arSupportedImpressionTypes, NInt supportedImressionTypeCount, NBool * pResult);

NBool N_API NFPositionIsValidTheFinger(NFPosition value);
NBool N_API NFPositionIsValidFinger(NFPosition value);
NBool N_API NFPositionIsValidPalm(NFPosition value);
NBool N_API NFPositionIsValid(NFPosition value);
NBool N_API NFPositionIsTheFinger(NFPosition value);
NBool N_API NFPositionIsFinger(NFPosition value);
NBool N_API NFPositionIsThePalm(NFPosition value);
NBool N_API NFPositionIsPalm(NFPosition value);
NBool N_API NFPositionIsSingleFinger(NFPosition value);
NBool N_API NFPositionIsTwoFingers(NFPosition value);
NBool N_API NFPositionIsThreeFingers(NFPosition value);
NBool N_API NFPositionIsFourFingers(NFPosition value);
NBool N_API NFPositionIsKnown(NFPosition value);
NBool N_API NFPositionIsRight(NFPosition value);
NBool N_API NFPositionIsLeft(NFPosition value);
NBool N_API NFPositionIsLeftAndRight(NFPosition value);
NBool N_API NFPositionIsCompatibleWith(NFPosition value, NFPosition otherValue);
NBool N_API NFPositionIsCompatibleWithImpressionType(NFPosition value, NFImpressionType imp);
NResult N_API NFPositionIsOneOf(NFPosition value, NFPosition * arSupportedPositions, NInt supportedPositionCount, NBool * pResult);
NResult N_API NFPositionGetAvailableParts(NFPosition value, const NFPosition * arMissingPositions, NInt missingPositionCount, NFPosition * arResults, NInt resultsLength);

NBool N_API NEPositionIsValidTheEye(NEPosition value);
NBool N_API NEPositionIsValid(NEPosition value);
NBool N_API NEPositionIsTheEye(NEPosition value);
NBool N_API NEPositionIsSingleEye(NEPosition value);
NBool N_API NEPositionIsTwoEyes(NEPosition value);
NBool N_API NEPositionIsKnown(NEPosition value);
NBool N_API NEPositionIsRight(NEPosition value);
NBool N_API NEPositionIsLeft(NEPosition value);
NBool N_API NEPositionIsRightAndLeft(NEPosition value);
NResult N_API NEPositionIsOneOf(NEPosition value, NEPosition * arSupportedPositions, NInt supportedPositionCount, NBool * pResult);
NResult N_API NEPositionGetAvailableParts(NEPosition value, const NEPosition * arMissingPositions, NInt missingPositionCount, NEPosition * arResults, NInt resultsLength);

NBool N_API NFPatternClassIsValid(NFPatternClass value);
NBool N_API NFPatternClassIsValidForPosition(NFPatternClass value, NFPosition pos);

NBool N_API NfiqQualityIsValid(NfiqQuality value);

NFloat N_API NBiometricAngleToDegrees(NInt value);
NInt N_API NBiometricAngleFromDegrees(NFloat value);
NDouble N_API NBiometricAngleToRadians(NInt value);
NInt N_API NBiometricAngleFromRadians(NDouble value);

NResult N_API NBiometricAngleToStringN(NInt value, HNString hFormat, HNString * phValue);
NResult N_API NBiometricAngleToStringA(NInt value, const NAChar * szFormat, HNString * phValue);
#ifndef N_NO_UNICODE
NResult N_API NBiometricAngleToStringW(NInt value, const NWChar * szFormat, HNString * phValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NBiometricAngleToString(NInt value, const NChar * szFormat, HNString * phValue);
#endif
#define NBiometricAngleToString N_FUNC_AW(NBiometricAngleToString)

NBool N_API NBiometricQualityIsValid(NByte value);

NResult N_API NBiometricQualityToStringN(NByte value, HNString hFormat, HNString * phValue);
NResult N_API NBiometricQualityToStringA(NByte value, const NAChar * szFormat, HNString * phValue);
#ifndef N_NO_UNICODE
NResult N_API NBiometricQualityToStringW(NByte value, const NWChar * szFormat, HNString * phValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NBiometricQualityToString(NByte value, const NChar * szFormat, HNString * phValue);
#endif
#define NBiometricQualityToString N_FUNC_AW(NBiometricQualityToString)

N_DECLARE_STATIC_OBJECT_TYPE(NBiometricTypes)

#ifdef N_CPP
}
#endif

#endif // !N_BIOMETRIC_TYPES_H_INCLUDED
