#ifndef N_MATCHING_DETAILS_H_INCLUDED
#define N_MATCHING_DETAILS_H_INCLUDED

#include <Biometrics/NFMatchingDetails.h>
#include <Biometrics/NLMatchingDetails.h>
#include <Biometrics/NEMatchingDetails.h>
#include <Biometrics/NSMatchingDetails.h>
#include <Core/NObject.h>

#ifdef N_CPP
extern "C"
{
#endif

N_DECLARE_OBJECT_TYPE(NMatchingDetails, NMatchingDetailsBase)

NResult N_API NMatchingDetailsCreateFromMemoryN(HNBuffer hBuffer, NUInt flags, NSizeType * pSize, HNMatchingDetails * phMatchingDetails);
NResult N_API NMatchingDetailsCreateFromMemory(const void * pBuffer, NSizeType bufferSize, NUInt flags, NSizeType * pSize, HNMatchingDetails * phMatchingDetails);
NResult N_API NMatchingDetailsCreateFromStream(HNStream hStream, NUInt flags, HNMatchingDetails * phMatchingDetails);

NResult N_API NMatchingDetailsGetFingersScore(HNMatchingDetails hMatchingDetails, NInt * pValue);
NResult N_API NMatchingDetailsGetFingerCount(HNMatchingDetails hMatchingDetails, NInt * pValue);
NResult N_API NMatchingDetailsGetFingerEx(HNMatchingDetails hMatchingDetails, NInt index, HNFMatchingDetails * phValue);

NResult N_API NMatchingDetailsGetFacesScore(HNMatchingDetails hMatchingDetails, NInt * pValue);
NResult N_API NMatchingDetailsGetFacesMatchedIndex(HNMatchingDetails hMatchingDetails, NInt * pValue);
NResult N_API NMatchingDetailsGetFaceCount(HNMatchingDetails hMatchingDetails, NInt * pValue);
NResult N_API NMatchingDetailsGetFaceEx(HNMatchingDetails hMatchingDetails, NInt index, HNLMatchingDetails * phValue);

NResult N_API NMatchingDetailsGetIrisesScore(HNMatchingDetails hMatchingDetails, NInt * pValue);
NResult N_API NMatchingDetailsGetIrisCount(HNMatchingDetails hMatchingDetails, NInt * pValue);
NResult N_API NMatchingDetailsGetIrisEx(HNMatchingDetails hMatchingDetails, NInt index, HNEMatchingDetails * phValue);

NResult N_API NMatchingDetailsGetPalmsScore(HNMatchingDetails hMatchingDetails, NInt * pValue);
NResult N_API NMatchingDetailsGetPalmCount(HNMatchingDetails hMatchingDetails, NInt * pValue);
NResult N_API NMatchingDetailsGetPalmEx(HNMatchingDetails hMatchingDetails, NInt index, HNFMatchingDetails * phValue);

NResult N_API NMatchingDetailsGetVoicesScore(HNMatchingDetails hMatchingDetails, NInt * pValue);
NResult N_API NMatchingDetailsGetVoiceCount(HNMatchingDetails hMatchingDetails, NInt * pValue);
NResult N_API NMatchingDetailsGetVoiceEx(HNMatchingDetails hMatchingDetails, NInt index, HNSMatchingDetails * phValue);

#ifdef N_CPP
}
#endif

#endif // !N_MATCHING_DETAILS_H_INCLUDED
