#ifndef NF_ATTRIBUTES_H_INCLUDED
#define NF_ATTRIBUTES_H_INCLUDED

#include <Biometrics/NBiometricAttributes.h>
#include <Biometrics/NFRecord.h>
#include <Geometry/NGeometry.h>

#ifdef N_CPP
extern "C"
{
#endif

N_DECLARE_OBJECT_TYPE(NFAttributes, NBiometricAttributes)

NResult N_API NFAttributesCreate(NFImpressionType impressionType, NFPosition position, HNFAttributes * phAttributes);

NResult N_API NFAttributesGetTemplate(HNFAttributes hAttributes, HNFRecord * phValue);
NResult N_API NFAttributesSetTemplate(HNFAttributes hAttributes, HNFRecord hValue);
NResult N_API NFAttributesGetImpressionType(HNFAttributes hAttributes, NFImpressionType * pValue);
NResult N_API NFAttributesGetPosition(HNFAttributes hAttributes, NFPosition * pValue);
NResult N_API NFAttributesGetImageIndex(HNFAttributes hAttributes, NInt * pValue);
NResult N_API NFAttributesSetImageIndex(HNFAttributes hAttributes, NInt value);
NResult N_API NFAttributesGetBoundingRect(HNFAttributes hAttributes, struct NRect_ * pValue);
NResult N_API NFAttributesSetBoundingRect(HNFAttributes hAttributes, const struct NRect_ * pValue);
NResult N_API NFAttributesGetRotation(HNFAttributes hAttributes, NFloat * pValue);
NResult N_API NFAttributesSetRotation(HNFAttributes hAttributes, NFloat value);
NResult N_API NFAttributesGetPatternClass(HNFAttributes hAttributes, NFPatternClass * pValue);
NResult N_API NFAttributesSetPatternClass(HNFAttributes hAttributes, NFPatternClass value);
NResult N_API NFAttributesGetPatternClassConfidence(HNFAttributes hAttributes, NByte * pValue);
NResult N_API NFAttributesSetPatternClassConfidence(HNFAttributes hAttributes, NByte value);
NResult N_API NFAttributesGetNfiqQuality(HNFAttributes hAttributes, NfiqQuality * pValue);
NResult N_API NFAttributesSetNfiqQuality(HNFAttributes hAttributes, NfiqQuality value);

NResult N_API NFAttributesGetPossiblePositionCount(HNFAttributes hAttributes, NInt * pValue);
NResult N_API NFAttributesGetPossiblePosition(HNFAttributes hAttributes, NInt index, NFPosition * pValue);
NResult N_API NFAttributesSetPossiblePosition(HNFAttributes hAttributes, NInt index, NFPosition value);
NResult N_API NFAttributesGetPossiblePositions(HNFAttributes hAttributes, NFPosition * * parValues, NInt *pValueCount);
NResult N_API NFAttributesAddPossiblePosition(HNFAttributes hAttributes, NFPosition value, NInt * pIndex);
NResult N_API NFAttributesInsertPossiblePosition(HNFAttributes hAttributes, NInt index, NFPosition value);
NResult N_API NFAttributesRemovePossiblePositionAt(HNFAttributes hAttributes, NInt index);
NResult N_API NFAttributesClearPossiblePositions(HNFAttributes hAttributes);

#ifdef N_CPP
}
#endif

#endif // !NF_ATTRIBUTES_H_INCLUDED
