#ifndef N_FRICTION_RIDGE_H_INCLUDED
#define N_FRICTION_RIDGE_H_INCLUDED

#include <Biometrics/NBiometric.h>
#include <Images/NImage.h>
#include <Biometrics/NFAttributes.h>

#ifdef N_CPP
extern "C"
{
#endif

N_DECLARE_OBJECT_TYPE(NFrictionRidge, NBiometric)

NResult N_API NFrictionRidgeFromPosition(NFPosition position, HNFrictionRidge * phFrictionRidge);
NResult N_API NFrictionRidgeFromImageAndTemplate(HNImage hImage, HNFRecord hTemplate, HNFrictionRidge * phFrictionRidge);

NResult N_API NFrictionRidgeGetImage(HNFrictionRidge hFrictionRidge, HNImage * phValue);
NResult N_API NFrictionRidgeSetImage(HNFrictionRidge hFrictionRidge, HNImage hValue);
NResult N_API NFrictionRidgeGetProcessedImage(HNFrictionRidge hFrictionRidge, HNImage * phValue);
NResult N_API NFrictionRidgeSetProcessedImage(HNFrictionRidge hFrictionRidge, HNImage hValue);
NResult N_API NFrictionRidgeGetPosition(HNFrictionRidge hFrictionRidge, NFPosition * pValue);
NResult N_API NFrictionRidgeSetPosition(HNFrictionRidge hFrictionRidge, NFPosition value);
NResult N_API NFrictionRidgeGetImpressionType(HNFrictionRidge hFrictionRidge, NFImpressionType * pValue);
NResult N_API NFrictionRidgeSetImpressionType(HNFrictionRidge hFrictionRidge, NFImpressionType value);

NResult N_API NFrictionRidgeGetObjectCount(HNFrictionRidge hFrictionRidge, NInt * pValue);
NResult N_API NFrictionRidgeGetObject(HNFrictionRidge hFrictionRidge, NInt index, HNFAttributes * phValue);
NResult N_API NFrictionRidgeGetObjects(HNFrictionRidge hFrictionRidge, HNFAttributes * * parhValues, NInt * pValueCount);

NResult N_API NFrictionRidgeAddObjectsCollectionChanged(HNFrictionRidge hFrictionRidge, HNCallback hCallback);
NResult N_API NFrictionRidgeAddObjectsCollectionChangedCallback(HNFrictionRidge hFrictionRidge, N_COLLECTION_CHANGED_CALLBACK_ARG(HNFAttributes, pCallback), void * pParam);
NResult N_API NFrictionRidgeRemoveObjectsCollectionChanged(HNFrictionRidge hFrictionRidge, HNCallback hCallback);
NResult N_API NFrictionRidgeRemoveObjectsCollectionChangedCallback(HNFrictionRidge hFrictionRidge, N_COLLECTION_CHANGED_CALLBACK_ARG(HNFAttributes, pCallback), void * pParam);
N_DEPRECATED("function is deprecated, use NFrictionRidgeAddObjectsCollectionChangedCallback instead")
NResult N_API NFrictionRidgeObjectsCollectionChangedCallback(HNFrictionRidge hFrictionRidge, N_COLLECTION_CHANGED_CALLBACK_ARG(HNFAttributes, pCallback), void * pParam);

NResult N_API NFrictionRidgeGetPossiblePositionCount(HNFrictionRidge hFrictionRidge, NInt * pValue);
NResult N_API NFrictionRidgeGetPossiblePosition(HNFrictionRidge hFrictionRidge, NInt index, NFPosition * pValue);
NResult N_API NFrictionRidgeSetPossiblePosition(HNFrictionRidge hFrictionRidge, NInt index, NFPosition value);
NResult N_API NFrictionRidgeGetPossiblePositions(HNFrictionRidge hFrictionRidge, NFPosition * * parValues, NInt * pValueCount);
NResult N_API NFrictionRidgeAddPossiblePosition(HNFrictionRidge hFrictionRidge, NFPosition value, NInt * pIndex);
NResult N_API NFrictionRidgeInsertPossiblePosition(HNFrictionRidge hFrictionRidge, NInt index, NFPosition value);
NResult N_API NFrictionRidgeRemovePossiblePositionAt(HNFrictionRidge hFrictionRidge, NInt index);
NResult N_API NFrictionRidgeClearPossiblePositions(HNFrictionRidge hFrictionRidge);

#ifdef N_CPP
}
#endif

#endif // !N_FRICTION_RIDGE_H_INCLUDED
