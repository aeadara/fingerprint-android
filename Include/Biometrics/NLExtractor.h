#ifndef NL_EXTRACTOR_H_INCLUDED
#define NL_EXTRACTOR_H_INCLUDED

#include <Images/NGrayscaleImage.h>
#include <Geometry/NGeometry.h>
#include <Biometrics/NLTemplate.h>
#include <Biometrics/NLExtractorParams.h>
#include <Biometrics/NBiometricTypes.h>

#ifdef N_CPP
extern "C"
{
#endif

N_DECLARE_TYPE(NleRotation)
N_DECLARE_TYPE(NleFace)
N_DECLARE_TYPE(NleEyes)

typedef struct NleRotation_
{
	NShort Yaw;
	NShort Pitch;
	NShort Roll;
} NleRotation;

typedef struct NleFace_
{
	struct NRect_ Rectangle;
	NleRotation Rotation;
	NDouble Confidence;
} NleFace;

typedef struct NleEyes_
{
	struct NPoint_ First;
	NDouble FirstConfidence;
	struct NPoint_ Second;
	NDouble SecondConfidence;
} NleEyes;

#define NLE_FEATURE_POINT_COUNT 68

struct NleDetectionDetails_
{
	NBool FaceAvailable;
	NInt Padding1;
	NleFace Face;
	NGender Gender;
	NLExpression Expression;
	NLProperties Properties;
	NByte GenderConfidence;
	NByte ExpressionConfidence;
	NByte GlassesConfidence;
	NByte DarkGlassesConfidence;
	NByte BlinkConfidence;
	NByte MouthOpenConfidence;
	NByte ReservedConfidence[6];
	NByte EmotionNeutralConfidence;
	NByte EmotionAngerConfidence;
	NByte EmotionDisgustConfidence;
	NByte EmotionFearConfidence;
	NByte EmotionHappinessConfidence;
	NByte EmotionSadnessConfidence;
	NByte EmotionSurpriseConfidence;
	NByte EmotionReservedConfidence1;
	NByte EmotionReservedConfidence2;
	struct NLFeaturePoint_ RightEyeCenter;
	struct NLFeaturePoint_ LeftEyeCenter;
	struct NLFeaturePoint_ NoseTip;
	struct NLFeaturePoint_ MouthCenter;
	struct NLFeaturePoint_ Reserved[4];
	struct NLFeaturePoint_ Points[NLE_FEATURE_POINT_COUNT];
};
typedef N_DEPRECATED("struct is deprecated, use NLAttributes instead")
struct NleDetectionDetails_ NleDetectionDetails;

typedef N_DEPRECATED("enum is deprecated, use NBiometricStatus instead")
enum NleExtractionStatus_
{
	nleesNone = 0,
	nleesTemplateCreated = 1,
	nleesFaceNotDetected = 2,
	nleesEyesNotDetected = 3,
	nleesFaceTooCloseToImageBorder = 4,
	nleesQualityCheckGrayscaleDensityFailed = 100,
	nleesQualityCheckExposureFailed = 101,
	nleesQualityCheckSharpnessFailed = 102,
	nleesLivenessCheckFailed = 200,
	nleesGeneralizationFailed = 300,
} NleExtractionStatus;

N_DECLARE_TYPE(NleExtractionStatus)

#include <Core/NNoDeprecate.h>

NResult N_API NleDetectionDetailsClear(struct NleDetectionDetails_ * pDetectionDetails);

#include <Core/NReDeprecate.h>

N_DECLARE_OBJECT_TYPE(NLExtractor, NObject)

#include <Core/NNoDeprecate.h>

NResult N_API NleCompressEx(HNLTemplate hSrcTemplate, NleTemplateSize dstTemplateSize, HNLTemplate * phDstTemplate);

NResult N_API NleCreate(HNLExtractor * phExtractor);

NResult N_API NleDetectFace(HNLExtractor hExtractor, HNGrayscaleImage hImage, NBool * pDetected, NleFace * pFace);
NResult N_API NleDetectFaces(HNLExtractor hExtractor, HNGrayscaleImage hImage, NInt * pFaceCount, NleFace * * parFaces);

NResult N_API NleDetectFacialFeatures(HNLExtractor hExtractor, HNGrayscaleImage hImage, const NleFace * pFace, struct NleDetectionDetails_ * pDetectionDetails);

NResult N_API NleExtract(HNLExtractor hExtractor, HNGrayscaleImage hImage, struct NleDetectionDetails_ * pDetectionDetails, NleExtractionStatus * pStatus, HNLTemplate * phTemplate);

NResult N_API NleExtractStartEx(HNLExtractor hExtractor);
NResult N_API NleExtractNextEx2(HNLExtractor hExtractor, HNGrayscaleImage hImage, struct NleDetectionDetails_ * pDetectionDetails, NleExtractionStatus * pStatus);
NResult N_API NleExtractEndEx(HNLExtractor hExtractor, NInt * pBaseFrameIndex, struct NleDetectionDetails_ * pDetectionDetails, NleExtractionStatus * pStatus, HNLTemplate *phTemplate);

NResult N_API NleExtractUsingDetails(HNLExtractor hExtractor, HNGrayscaleImage hImage,
	struct NleDetectionDetails_ * pDetectionDetails, NleExtractionStatus * pStatus, HNLTemplate * phTemplate);

NResult N_API NleGeneralizeEx(HNLExtractor hExtractor, NInt templateCount, const HNLTemplate * arhTemplates,
	NleExtractionStatus * pStatus, NInt * pBaseTemplateIndex, HNLTemplate * phTemplate);

#include <Core/NReDeprecate.h>

#ifdef N_CPP
}
#endif

#endif // !NL_EXTRACTOR_H_INCLUDED
