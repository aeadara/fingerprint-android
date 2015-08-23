#ifndef NF_MATCHING_DETAILS_H_INCLUDED
#define NF_MATCHING_DETAILS_H_INCLUDED

#include <Biometrics/NXMatchingDetails.h>

#ifdef N_CPP
extern "C"
{
#endif

N_DECLARE_OBJECT_TYPE(NFMatchingDetails, NXMatchingDetails)

NResult N_API NFMatchingDetailsGetCenterX(HNFMatchingDetails hMatchingDetails, NInt * pValue);
NResult N_API NFMatchingDetailsGetCenterY(HNFMatchingDetails hMatchingDetails, NInt * pValue);
NResult N_API NFMatchingDetailsGetRotation(HNFMatchingDetails hMatchingDetails, NByte * pValue);
NResult N_API NFMatchingDetailsGetTranslationX(HNFMatchingDetails hMatchingDetails, NInt * pValue);
NResult N_API NFMatchingDetailsGetTranslationY(HNFMatchingDetails hMatchingDetails, NInt * pValue);
NResult N_API NFMatchingDetailsGetMatedMinutiae(HNFMatchingDetails hMatchingDetails, struct NIndexPair_ * arValue, NInt valueLength);

#ifdef N_CPP
}
#endif

#endif // !NF_MATCHING_DETAILS_H_INCLUDED
