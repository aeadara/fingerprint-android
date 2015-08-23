#ifndef N_MEDIA_READER_H_INCLUDED
#define N_MEDIA_READER_H_INCLUDED

#include <Media/NMediaSource.h>
#include <Sound/NSoundBuffer.h>
#include <Images/NImage.h>
#include <Core/NTimeSpan.h>

#ifdef N_CPP
extern "C"
{
#endif

N_DECLARE_OBJECT_TYPE(NMediaReader, NObject)

NResult N_API NMediaReaderCreate(HNMediaSource hMediaSource, NMediaType mediaTypes, NBool isLive, NUInt flags, HNMediaReader * phReader);

NResult N_API NMediaReaderCreateFromFileN(HNString hFileName, NMediaType mediaTypes, NBool isLive, NUInt flags, HNMediaReader * phReader);
#ifndef N_NO_ANSI_FUNC
NResult N_API NMediaReaderCreateFromFileA(const NAChar * szFileName, NMediaType mediaTypes, NBool isLive, NUInt flags, HNMediaReader * phReader);
#endif
#ifndef N_NO_UNICODE
NResult N_API NMediaReaderCreateFromFileW(const NWChar * szFileName, NMediaType mediaTypes, NBool isLive, NUInt flags, HNMediaReader * phReader);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NMediaReaderCreateFromFile(const NChar * szFileName, NMediaType mediaTypes, NBool isLive, NUInt flags, HNMediaReader * phReader);
#endif
#define NMediaReaderCreateFromFile N_FUNC_AW(NMediaReaderCreateFromFile)

NResult N_API NMediaReaderCreateFromUrlN(HNString hUrl, NMediaType mediaTypes, NBool isLive, NUInt flags, HNMediaReader * phReader);
#ifndef N_NO_ANSI_FUNC
NResult N_API NMediaReaderCreateFromUrlA(const NAChar * szUrl, NMediaType mediaTypes, NBool isLive, NUInt flags, HNMediaReader * phReader);
#endif
#ifndef N_NO_UNICODE
NResult N_API NMediaReaderCreateFromUrlW(const NWChar * szUrl, NMediaType mediaTypes, NBool isLive, NUInt flags, HNMediaReader * phReader);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NMediaReaderCreateFromUrl(const NChar * szUrl, NMediaType mediaTypes, NBool isLive, NUInt flags, HNMediaReader * phReader);
#endif
#define NMediaReaderCreateFromUrl N_FUNC_AW(NMediaReaderCreateFromUrl)

NResult N_API NMediaReaderStart(HNMediaReader hReader);
NResult N_API NMediaReaderStop(HNMediaReader hReader);
NResult N_API NMediaReaderPause(HNMediaReader hReader);
NResult N_API NMediaReaderReadAudioSample(HNMediaReader hReader, NTimeSpan_ * pTimeStamp, NTimeSpan_ * pDuration, HNSoundBuffer * phSoundBuffer);
NResult N_API NMediaReaderReadVideoSample(HNMediaReader hReader, NTimeSpan_ * pTimeStamp, NTimeSpan_ * pDuration, HNImage * phImage);

NResult N_API NMediaReaderGetSource(HNMediaReader hReader, HNMediaSource * phValue);
NResult N_API NMediaReaderIsLive(HNMediaReader hReader, NBool * pValue);
NResult N_API NMediaReaderGetState(HNMediaReader hReader, NMediaState * pValue);
NResult N_API NMediaReaderGetLength(HNMediaReader hReader, NTimeSpan_ * pValue);
NResult N_API NMediaReaderGetPosition(HNMediaReader hReader, NTimeSpan_ * pValue);
NResult N_API NMediaReaderSetPosition(HNMediaReader hReader, NTimeSpan_ value);

#ifdef N_CPP
}
#endif

#endif // !N_MEDIA_READER_H_INCLUDED
