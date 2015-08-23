#ifndef NS_EXTRACTOR_H_INCLUDED
#define NS_EXTRACTOR_H_INCLUDED

#include <Sound/NSoundBuffer.h>
#include <Biometrics/NSRecord.h>
#include <Biometrics/NSExtractorParams.h>
#include <Biometrics/NSAttributes.h>

#ifdef N_CPP
extern "C"
{
#endif

typedef N_DEPRECATED("enum is deprecated, use NBiometricStatus instead")
enum NseExtractionStatus_
{
	nseesNone = 0,
	nseesTemplateCreated = 1,
	nseesTooFewFeatures = 90,
} NseExtractionStatus;

N_DECLARE_TYPE(NseExtractionStatus)

N_DECLARE_OBJECT_TYPE(NSExtractor, NObject)

#include <Core/NNoDeprecate.h>

NResult N_API NseCreate(HNSExtractor * phExtractor);

NResult N_API NseExtractEx(HNSExtractor hExtractor, NInt phraseId, HNSoundBuffer hSoundBuffer, NTimeSpan_ * pVoiceStart, NTimeSpan_ * pVoiceDuration, NseExtractionStatus * pStatus, HNSRecord * phRecord);

NResult N_API NseExtractStart(HNSExtractor hExtractor, NInt phraseId);
NResult N_API NseExtractNextEx(HNSExtractor hExtractor, HNSoundBuffer hSoundBuffer, NBool * pVoiceDetected, NseExtractionStatus * pStatus);
NResult N_API NseExtractEndEx(HNSExtractor hExtractor, NTimeSpan_ * pVoiceStart, NTimeSpan_ * pVoiceDuration, HNSoundBuffer * phVoice, NseExtractionStatus * pStatus, HNSRecord * phRecord);

#include <Core/NReDeprecate.h>

#ifdef N_CPP
}
#endif

#endif // !NS_EXTRACTOR_H_INCLUDED
