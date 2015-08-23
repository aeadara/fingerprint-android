#ifndef NE_ATTRIBUTES_H_INCLUDED
#define NE_ATTRIBUTES_H_INCLUDED

#include <Biometrics/NBiometricAttributes.h>
#include <Biometrics/NERecord.h>
#include <Geometry/NGeometry.h>

#ifdef N_CPP
extern "C"
{
#endif

N_DECLARE_OBJECT_TYPE(NEAttributes, NBiometricAttributes)

NResult N_API NEAttributesCreate(NEPosition position, HNEAttributes * phAttributes);

NResult N_API NEAttributesGetTemplate(HNEAttributes hAttributes, HNERecord * phValue);
NResult N_API NEAttributesSetTemplate(HNEAttributes hAttributes, HNERecord hValue);
NResult N_API NEAttributesGetPosition(HNEAttributes hAttributes, NEPosition * pValue);
NResult N_API NEAttributesGetImageIndex(HNEAttributes hAttributes, NInt * pValue);
NResult N_API NEAttributesSetImageIndex(HNEAttributes hAttributes, NInt value);
NResult N_API NEAttributesGetBoundingRect(HNEAttributes hAttributes, struct NRect_ * pValue);
NResult N_API NEAttributesSetBoundingRect(HNEAttributes hAttributes, const struct NRect_ * pValue);
NResult N_API NEAttributesGetUsableIrisArea(HNEAttributes hAttributes, NByte * pValue);
NResult N_API NEAttributesGetIrisScleraContrast(HNEAttributes hAttributes, NByte * pValue);
NResult N_API NEAttributesGetIrisPupilContrast(HNEAttributes hAttributes, NByte * pValue);
NResult N_API NEAttributesGetPupilBoundaryCircularity(HNEAttributes hAttributes, NByte * pValue);
NResult N_API NEAttributesGetGrayScaleUtilisation(HNEAttributes hAttributes, NByte * pValue);
NResult N_API NEAttributesGetIrisRadius(HNEAttributes hAttributes, NByte * pValue);
NResult N_API NEAttributesGetPupilToIrisRatio(HNEAttributes hAttributes, NByte * pValue);
NResult N_API NEAttributesGetIrisPupilConcentricity(HNEAttributes hAttributes, NByte * pValue);
NResult N_API NEAttributesGetMarginAdequacy(HNEAttributes hAttributes, NByte * pValue);
NResult N_API NEAttributesGetSharpness(HNEAttributes hAttributes, NByte * pValue);
NResult N_API NEAttributesGetInterlace(HNEAttributes hAttributes, NByte * pValue);
NResult N_API NEAttributesIsInnerBoundaryAvailable(HNEAttributes hAttributes, NBool * pValue);
NResult N_API NEAttributesIsOuterBoundaryAvailable(HNEAttributes hAttributes, NBool * pValue);

NResult N_API NEAttributesGetInnerBoundaryPointCount(HNEAttributes hAttributes, NInt * pValue);
NResult N_API NEAttributesGetInnerBoundaryPoint(HNEAttributes hAttributes, NInt index, struct NPoint_ * pValue);
NResult N_API NEAttributesGetInnerBoundaryPoints(HNEAttributes hAttributes, struct NPoint_ * * parValues, NInt * pValueCount);
NResult N_API NEAttributesGetInnerBoundaryPointCapacity(HNEAttributes hAttributes, NInt * pValue);
NResult N_API NEAttributesSetInnerBoundaryPointCapacity(HNEAttributes hAttributes, NInt value);
NResult N_API NEAttributesSetInnerBoundaryPoint(HNEAttributes hAttributes, NInt index, const struct NPoint_ * pValue);
NResult N_API NEAttributesAddInnerBoundaryPoint(HNEAttributes hAttributes, const struct NPoint_ * pValue, NInt * pIndex);
NResult N_API NEAttributesInsertInnerBoundaryPoint(HNEAttributes hAttributes, NInt index, const struct NPoint_ * pValue);
NResult N_API NEAttributesRemoveInnerBoundaryPointAt(HNEAttributes hAttributes, NInt index);
NResult N_API NEAttributesClearInnerBoundaryPoints(HNEAttributes hAttributes);

NResult N_API NEAttributesAddInnerBoundaryPointsCollectionChanged(HNEAttributes hAttributes, HNCallback hCallback);
NResult N_API NEAttributesAddInnerBoundaryPointsCollectionChangedCallback(HNEAttributes hAttributes, N_COLLECTION_CHANGED_CALLBACK_ARG(struct NPoint_, pCallback), void * pParam);
NResult N_API NEAttributesRemoveInnerBoundaryPointsCollectionChanged(HNEAttributes hAttributes, HNCallback hCallback);
NResult N_API NEAttributesRemoveInnerBoundaryPointsCollectionChangedCallback(HNEAttributes hAttributes, N_COLLECTION_CHANGED_CALLBACK_ARG(struct NPoint_, pCallback), void * pParam);

NResult N_API NEAttributesGetOuterBoundaryPointCount(HNEAttributes hAttributes, NInt * pValue);
NResult N_API NEAttributesGetOuterBoundaryPoint(HNEAttributes hAttributes, NInt index, struct NPoint_ * pValue);
NResult N_API NEAttributesGetOuterBoundaryPoints(HNEAttributes hAttributes, struct NPoint_ * * parValues, NInt * pValueCount);
NResult N_API NEAttributesGetOuterBoundaryPointCapacity(HNEAttributes hAttributes, NInt * pValue);
NResult N_API NEAttributesSetOuterBoundaryPointCapacity(HNEAttributes hAttributes, NInt value);
NResult N_API NEAttributesSetOuterBoundaryPoint(HNEAttributes hAttributes, NInt index, const struct NPoint_ * pValue);
NResult N_API NEAttributesAddOuterBoundaryPoint(HNEAttributes hAttributes, const struct NPoint_ * pValue, NInt * pIndex);
NResult N_API NEAttributesInsertOuterBoundaryPoint(HNEAttributes hAttributes, NInt index, const struct NPoint_ * pValue);
NResult N_API NEAttributesRemoveOuterBoundaryPointAt(HNEAttributes hAttributes, NInt index);
NResult N_API NEAttributesClearOuterBoundaryPoints(HNEAttributes hAttributes);

NResult N_API NEAttributesAddOuterBoundaryPointsCollectionChanged(HNEAttributes hAttributes, HNCallback hCallback);
NResult N_API NEAttributesAddOuterBoundaryPointsCollectionChangedCallback(HNEAttributes hAttributes, N_COLLECTION_CHANGED_CALLBACK_ARG(struct NPoint_, pCallback), void * pParam);
NResult N_API NEAttributesRemoveOuterBoundaryPointsCollectionChanged(HNEAttributes hAttributes, HNCallback hCallback);
NResult N_API NEAttributesRemoveOuterBoundaryPointsCollectionChangedCallback(HNEAttributes hAttributes, N_COLLECTION_CHANGED_CALLBACK_ARG(struct NPoint_, pCallback), void * pParam);

#ifdef N_CPP
}
#endif

#endif // !NE_ATTRIBUTES_H_INCLUDED
