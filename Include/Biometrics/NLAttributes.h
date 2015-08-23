#ifndef NL_ATTRIBUTES_H_INCLUDED
#define NL_ATTRIBUTES_H_INCLUDED

#include <Biometrics/NBiometricAttributes.h>
#include <Biometrics/NLTemplate.h>
#include <Geometry/NGeometry.h>
#include <Images/NImage.h>

#ifdef N_CPP
extern "C"
{
#endif

N_DECLARE_OBJECT_TYPE(NLAttributes, NBiometricAttributes)

NResult N_API NLAttributesCreate(HNLAttributes * phAttributes);

NResult N_API NLAttributesGetTemplate(HNLAttributes hAttributes, HNLTemplate * phValue);
NResult N_API NLAttributesSetTemplate(HNLAttributes hAttributes, HNLTemplate hTemplate);
NResult N_API NLAttributesGetBoundingRect(HNLAttributes hAttributes, struct NRect_ * pValue);
NResult N_API NLAttributesSetBoundingRect(HNLAttributes hAttributes, const struct NRect_ * pValue);
NResult N_API NLAttributesGetYaw(HNLAttributes hAttributes, NFloat * pValue);
NResult N_API NLAttributesSetYaw(HNLAttributes hAttributes, NFloat value);
NResult N_API NLAttributesGetPitch(HNLAttributes hAttributes, NFloat * pValue);
NResult N_API NLAttributesSetPitch(HNLAttributes hAttributes, NFloat value);
NResult N_API NLAttributesSetRoll(HNLAttributes hAttributes, NFloat value);
NResult N_API NLAttributesGetRoll(HNLAttributes hAttributes, NFloat * pValue);
NResult N_API NLAttributesGetExpression(HNLAttributes hAttributes, NLExpression * pValue);
NResult N_API NLAttributesSetExpression(HNLAttributes hAttributes, NLExpression value);
NResult N_API NLAttributesGetProperties(HNLAttributes hAttributes, NLProperties * pValue);
NResult N_API NLAttributesSetProperties(HNLAttributes hAttributes, NLProperties value);
NResult N_API NLAttributesGetSharpness(HNLAttributes hAttributes, NByte * pValue);
NResult N_API NLAttributesGetBackgroundUniformity(HNLAttributes hAttributes, NByte * pValue);
NResult N_API NLAttributesGetGrayscaleDensity(HNLAttributes hAttributes, NByte * pValue);
NResult N_API NLAttributesGetRightEyeCenter(HNLAttributes hAttributes, NLFeaturePoint * pValue);
NResult N_API NLAttributesSetRightEyeCenter(HNLAttributes hAttributes, const NLFeaturePoint * pValue);
NResult N_API NLAttributesGetLeftEyeCenter(HNLAttributes hAttributes, NLFeaturePoint * pValue);
NResult N_API NLAttributesSetLeftEyeCenter(HNLAttributes hAttributes, const NLFeaturePoint * pValue);
NResult N_API NLAttributesGetNoseTip(HNLAttributes hAttributes, NLFeaturePoint * pValue);
NResult N_API NLAttributesGetMouthCenter(HNLAttributes hAttributes, NLFeaturePoint * pValue);
NResult N_API NLAttributesGetGender(HNLAttributes hAttributes, NGender * pValue);
NResult N_API NLAttributesGetGenderConfidence(HNLAttributes hAttributes, NByte * pValue);
NResult N_API NLAttributesGetExpressionConfidence(HNLAttributes hAttributes, NByte * pValue);
NResult N_API NLAttributesGetGlassesConfidence(HNLAttributes hAttributes, NByte * pValue);
NResult N_API NLAttributesGetDarkGlassesConfidence(HNLAttributes hAttributes, NByte * pValue);
NResult N_API NLAttributesGetBlinkConfidence(HNLAttributes hAttributes, NByte * pValue);
NResult N_API NLAttributesGetMouthOpenConfidence(HNLAttributes hAttributes, NByte * pValue);
NResult N_API NLAttributesGetEmotionNeutralConfidence(HNLAttributes hAttributes, NByte * pValue);
NResult N_API NLAttributesGetEmotionAngerConfidence(HNLAttributes hAttributes, NByte * pValue);
NResult N_API NLAttributesGetEmotionDisgustConfidence(HNLAttributes hAttributes, NByte * pValue);
NResult N_API NLAttributesGetEmotionFearConfidence(HNLAttributes hAttributes, NByte * pValue);
NResult N_API NLAttributesGetEmotionHappinessConfidence(HNLAttributes hAttributes, NByte * pValue);
NResult N_API NLAttributesGetEmotionSadnessConfidence(HNLAttributes hAttributes, NByte * pValue);
NResult N_API NLAttributesGetEmotionSurpriseConfidence(HNLAttributes hAttributes, NByte * pValue);
NResult N_API NLAttributesGetBaseFrameIndex(HNLAttributes hAttributes, NInt * pValue);
NResult N_API NLAttributesGetThumbnail(HNLAttributes hAttributes, HNImage * phValue);
NResult N_API NLAttributesSetThumbnail(HNLAttributes hAttributes, HNImage hValue);

NResult N_API NLAttributesGetFeaturePointCount(HNLAttributes hAttributes, NInt * pValue);
NResult N_API NLAttributesGetFeaturePoint(HNLAttributes hAttributes, NInt index, struct NLFeaturePoint_ * pValue);
NResult N_API NLAttributesGetFeaturePoints(HNLAttributes hAttributes, struct NLFeaturePoint_ * * parValues, NInt * pValueCount);
NResult N_API NLAttributesGetFeaturePointCapacity(HNLAttributes hAttributes, NInt * pValue);
NResult N_API NLAttributesSetFeaturePointCapacity(HNLAttributes hAttributes, NInt value);
NResult N_API NLAttributesSetFeaturePoint(HNLAttributes hAttributes, NInt index, const struct NLFeaturePoint_ * pValue);
NResult N_API NLAttributesAddFeaturePoint(HNLAttributes hAttributes, const struct NLFeaturePoint_ * pValue, NInt * pIndex);
NResult N_API NLAttributesInsertFeaturePoint(HNLAttributes hAttributes, NInt index, const struct NLFeaturePoint_ * pValue);
NResult N_API NLAttributesRemoveFeaturePointAt(HNLAttributes hAttributes, NInt index);
NResult N_API NLAttributesClearFeaturePoints(HNLAttributes hAttributes);

#ifdef N_CPP
}
#endif

#endif // !NL_ATTRIBUTES_H_INCLUDED
