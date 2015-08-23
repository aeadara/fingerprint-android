#ifndef N_VOICE_H_INCLUDED
#define N_VOICE_H_INCLUDED

#include <Biometrics/NBiometric.h>
#include <Sound/NSoundBuffer.h>
#include <Biometrics/NSAttributes.h>

#ifdef N_CPP
extern "C"
{
#endif

N_DECLARE_OBJECT_TYPE(NVoice, NBiometric)

NResult N_API NVoiceCreate(HNVoice * phVoice);
NResult N_API NVoiceFromSoundBufferAndTemplate(HNSoundBuffer hSoundBuffer, HNSRecord hTemplate, HNVoice * phVoice);

NResult N_API NVoiceGetSoundBuffer(HNVoice hVoice, HNSoundBuffer * phValue);
NResult N_API NVoiceSetSoundBuffer(HNVoice hVoice, HNSoundBuffer hValue);
NResult N_API NVoiceGetPhraseId(HNVoice hVoice, NInt * pValue);
NResult N_API NVoiceSetPhraseId(HNVoice hVoice, NInt value);

NResult N_API NVoiceGetObjectCount(HNVoice hVoice, NInt * pValue);
NResult N_API NVoiceGetObject(HNVoice hVoice, NInt index, HNSAttributes * phValue);
NResult N_API NVoiceGetObjects(HNVoice hVoice, HNSAttributes * * parhValues, NInt * pValueCount);

NResult N_API NVoiceAddObjectsCollectionChanged(HNVoice hVoice, HNCallback hCallback);
NResult N_API NVoiceAddObjectsCollectionChangedCallback(HNVoice hVoice, N_COLLECTION_CHANGED_CALLBACK_ARG(HNSAttributes, pCallback), void * pParam);
NResult N_API NVoiceRemoveObjectsCollectionChanged(HNVoice hVoice, HNCallback hCallback);
NResult N_API NVoiceRemoveObjectsCollectionChangedCallback(HNVoice hVoice, N_COLLECTION_CHANGED_CALLBACK_ARG(HNSAttributes, pCallback), void * pParam);

#ifdef N_CPP
}
#endif

#endif // !N_VOICE_H_INCLUDED
