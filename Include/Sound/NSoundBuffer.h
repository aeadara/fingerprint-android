#ifndef N_SOUND_BUFFER_H_INCLUDED
#define N_SOUND_BUFFER_H_INCLUDED

#include <Sound/NSoundFormat.h>
#include <Core/NArray.h>
#include <Media/NAudioFormat.h>

#ifdef N_CPP
extern "C"
{
#endif

#define NSB_ALL_DST 0x00000F00
#define NSB_ALL_SRC 0x0000F000
#define NSB_ALL_DST_AND_SRC (NSB_ALL_DST | NSB_ALL_SRC)

N_DECLARE_OBJECT_TYPE(NSoundBuffer, NObject)

NResult N_API NSoundBufferCreateWrapperN(NSoundFormat_ soundFormat, NInt sampleRate, NInt sampleCount, HNBuffer hSamples, NUInt flags, HNSoundBuffer * phSoundBuffer);
NResult N_API NSoundBufferCreateWrapper(NSoundFormat_ soundFormat, NInt sampleRate, NInt sampleCount, void * pSamples, NSizeType samplesSize, NBool ownsSamples, NUInt flags, HNSoundBuffer * phSoundBuffer);
NResult N_API NSoundBufferCreateWrapperForPartN(NSoundFormat_ soundFormat, NInt sampleRate, NInt srcSampleCount, HNBuffer hSamples, NInt sampleIndex, NInt sampleCount, NUInt flags, HNSoundBuffer * phSoundBuffer);
NResult N_API NSoundBufferCreateWrapperForPart(NSoundFormat_ soundFormat, NInt sampleRate, NInt srcSampleCount, void * pSamples, NSizeType samplesSize, NInt sampleIndex, NInt sampleCount, NUInt flags, HNSoundBuffer * phSoundBuffer);
NResult N_API NSoundBufferCreateWrapperForSoundBufferPart(HNSoundBuffer hSrcSoundBuffer, NInt sampleIndex, NInt sampleCount, NUInt flags, HNSoundBuffer * phSoundBuffer);

NResult N_API NSoundBufferCreate(NSoundFormat_ soundFormat, NInt sampleRate, NInt sampleCount, NUInt flags, HNSoundBuffer * phSoundBuffer);

NResult N_API NSoundBufferCreateFromDataN(NSoundFormat_ soundFormat, NInt sampleRate, NInt sampleCount, HNBuffer hSamples, NUInt flags, HNSoundBuffer * phSoundBuffer);
NResult N_API NSoundBufferCreateFromData(NSoundFormat_ soundFormat, NInt sampleRate, NInt sampleCount, const void * pSamples, NSizeType samplesSize, NUInt flags, HNSoundBuffer * phSoundBuffer);
NResult N_API NSoundBufferCreateFromDataPartN(NSoundFormat_ soundFormat, NInt sampleRate, NInt srcSampleCount, HNBuffer hSamples, NInt sampleIndex, NInt sampleCount, NUInt flags, HNSoundBuffer * phSoundBuffer);
NResult N_API NSoundBufferCreateFromDataPart(NSoundFormat_ soundFormat, NInt sampleRate, NInt srcSampleCount, const void * pSamples, NSizeType samplesSize, NInt sampleIndex, NInt sampleCount, NUInt flags, HNSoundBuffer * phSoundBuffer);

NResult N_API NSoundBufferCreateFromSoundBuffer(NSoundFormat_ soundFormat, HNSoundBuffer hSrcSoundBuffer, NUInt flags, HNSoundBuffer * phSoundBuffer);
NResult N_API NSoundBufferCreateFromSoundBufferPart(NSoundFormat_ soundFormat, HNSoundBuffer hSrcSoundBuffer, NInt sampleIndex, NInt sampleCount, NUInt flags, HNSoundBuffer * phSoundBuffer);

NResult N_API NSoundBufferCreateFromFileN(HNString hFileName, NUInt flags, HNSoundBuffer * phSoundBuffer);
#ifndef N_NO_ANSI_FUNC
NResult N_API NSoundBufferCreateFromFileA(const NAChar * szFileName, NUInt flags, HNSoundBuffer * phSoundBuffer);
#endif
#ifndef N_NO_UNICODE
NResult N_API NSoundBufferCreateFromFileW(const NWChar * szFileName, NUInt flags, HNSoundBuffer * phSoundBuffer);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NSoundBufferCreateFromFile(const NChar * szFileName, NUInt flags, HNSoundBuffer * phSoundBuffer);
#endif
#define NSoundBufferCreateFromFile N_FUNC_AW(NSoundBufferCreateFromFile)

NResult N_API NSoundBufferCreateFromMemoryN(HNBuffer hBuffer, NUInt flags, NSizeType * pSize, HNSoundBuffer * phSoundBuffer);
NResult N_API NSoundBufferCreateFromMemory(const void * pBuffer, NSizeType bufferSize, NUInt flags, NSizeType * pSize, HNSoundBuffer * phSoundBuffer);
NResult N_API NSoundBufferCreateFromStream(HNStream hStream, NUInt flags, HNSoundBuffer * phSoundBuffer);

NResult N_API NSoundBufferGetSupportedAudioSubtypes(NUInt * * parValues, NInt * pValueCount);
NResult N_API NSoundBufferIsAudioSubtypeSupported(NUInt value, NBool * pResult);
NResult N_API NSoundBufferIsAudioFormatSupported(HNAudioFormat hFormat, NBool * pResult);
NResult N_API NSoundBufferCreateFromAudioSampleN(HNAudioFormat hFormat, HNBuffer hSample, HNSoundBuffer * phSoundBuffer);
NResult N_API NSoundBufferCreateFromAudioSample(HNAudioFormat hFormat, const void * pSample, NSizeType sampleSize, HNSoundBuffer * phSoundBuffer);

NResult N_API NSoundBufferCopyDataExN(NSoundFormat_ srcSoundFormat, NInt srcSampleRate, HNArray hSrcMinValue, HNArray hSrcMaxValue,
	NInt srcSampleCount, HNBuffer hSrcSamples, NInt srcSampleIndex,
	NSoundFormat_ dstSoundFormat, NInt dstSampleRate, HNArray hDstMinValue, HNArray hDstMaxValue,
	NInt dstSampleCount, HNBuffer hDstSamples, NInt dstSampleIndex, NInt sampleCount, NUInt flags);
NResult N_API NSoundBufferCopyDataEx(NSoundFormat_ srcSoundFormat, NInt srcSampleRate, HNArray hSrcMinValue, HNArray hSrcMaxValue,
	NInt srcSampleCount, const void * pSrcSamples, NSizeType srcSamplesSize, NInt srcSampleIndex,
	NSoundFormat_ dstSoundFormat, NInt dstSampleRate, HNArray hDstMinValue, HNArray hDstMaxValue,
	NInt dstSampleCount, void * pDstSamples, NSizeType dstSamplesSize, NInt dstSampleIndex, NInt sampleCount, NUInt flags);
NResult N_API NSoundBufferCopyDataN(NSoundFormat_ srcSoundFormat, NInt srcSampleRate, NInt srcSampleCount, HNBuffer hSrcSamples, NInt srcSampleIndex,
	NSoundFormat_ dstSoundFormat, NInt dstSampleRate, NInt dstSampleCount, HNBuffer hDstSamples, NInt dstSampleIndex, NInt sampleCount, NUInt flags);
NResult N_API NSoundBufferCopyData(NSoundFormat_ srcSoundFormat, NInt srcSampleRate, NInt srcSampleCount, const void * pSrcSamples, NSizeType srcSamplesSize, NInt srcSampleIndex,
	NSoundFormat_ dstSoundFormat, NInt dstSampleRate, NInt dstSampleCount, void * pDstSamples, NSizeType dstSamplesSize, NInt dstSampleIndex, NInt sampleCount, NUInt flags);
NResult N_API NSoundBufferCopy(HNSoundBuffer hSrcSoundBuffer, NInt sampleIndex, HNSoundBuffer hDstSoundBuffer, NInt dstSampleIndex, NInt sampleCount);

NResult N_API NSoundBufferCopyFromDataN(HNSoundBuffer hSoundBuffer, NSoundFormat_ srcSoundFormat, NInt srcSampleRate,
	NInt srcSampleCount, HNBuffer hSrcSamples, NInt sampleIndex, NUInt flags);
NResult N_API NSoundBufferCopyFromData(HNSoundBuffer hSoundBuffer, NSoundFormat_ srcSoundFormat, NInt srcSampleRate,
	NInt srcSampleCount, const void * pSrcSamples, NSizeType srcSamplesSize, NInt sampleIndex, NUInt flags);
NResult N_API NSoundBufferCopyFromDataPartN(HNSoundBuffer hSoundBuffer, NSoundFormat_ srcSoundFormat, NInt srcSampleRate,
	NInt srcSampleCount, HNBuffer hSrcSamples, NInt srcSampleIndex, NInt sampleIndex, NInt sampleCount, NUInt flags);
NResult N_API NSoundBufferCopyFromDataPart(HNSoundBuffer hSoundBuffer, NSoundFormat_ srcSoundFormat, NInt srcSampleRate,
	NInt srcSampleCount, const void * pSrcSamples, NSizeType srcSamplesSize, NInt srcSampleIndex, NInt sampleIndex, NInt sampleCount, NUInt flags);
NResult N_API NSoundBufferCopyFromDataPartExN(HNSoundBuffer hSoundBuffer,
	NSoundFormat_ srcSoundFormat, NInt srcSampleRate, HNArray hSrcMinValue, HNArray hSrcMaxValue,
	NInt srcSampleCount, HNBuffer hSrcSamples, NInt srcSampleIndex, NInt sampleIndex, NInt sampleCount, NUInt flags);
NResult N_API NSoundBufferCopyFromDataPartEx(HNSoundBuffer hSoundBuffer,
	NSoundFormat_ srcSoundFormat, NInt srcSampleRate, HNArray hSrcMinValue, HNArray hSrcMaxValue,
	NInt srcSampleCount, const void * pSrcSamples, NSizeType srcSamplesSize, NInt srcSampleIndex, NInt sampleIndex, NInt sampleCount, NUInt flags);

NResult N_API NSoundBufferAppend(HNSoundBuffer hSoundBuffer, HNSoundBuffer hOther);
NResult N_API NSoundBufferAppendDataN(HNSoundBuffer hSoundBuffer, NSoundFormat_ soundFormat, NInt sampleRate, NInt sampleCount, HNBuffer hSamples, NUInt flags);
NResult N_API NSoundBufferAppendData(HNSoundBuffer hSoundBuffer, NSoundFormat_ soundFormat, NInt sampleRate, NInt sampleCount,
	const void * pSamples, NSizeType samplesSize, NUInt flags);
NResult N_API NSoundBufferAppendDataExN(HNSoundBuffer hSoundBuffer,
	NSoundFormat_ soundFormat, NInt sampleRate, HNArray hMinValue, HNArray hMaxValue,
	NInt sampleCount, HNBuffer hSamples, NUInt flags);
NResult N_API NSoundBufferAppendDataEx(HNSoundBuffer hSoundBuffer,
	NSoundFormat_ soundFormat, NInt sampleRate, HNArray hMinValue, HNArray hMaxValue,
	NInt sampleCount, const void * pSamples, NSizeType samplesSize, NUInt flags);
NResult N_API NSoundBufferClear(HNSoundBuffer hSoundBuffer);

NResult N_API NSoundBufferCopyTo(HNSoundBuffer hSoundBuffer, HNSoundBuffer hDstSoundBuffer, NInt dstSampleIndex);
NResult N_API NSoundBufferCopyToDataN(HNSoundBuffer hSoundBuffer, NSoundFormat_ dstSoundFormat, NInt dstSampleRate,
	NInt dstSampleCount, HNBuffer hDstSamples, NInt dstSampleIndex, NUInt flags);
NResult N_API NSoundBufferCopyToData(HNSoundBuffer hSoundBuffer, NSoundFormat_ dstSoundFormat, NInt dstSampleRate,
	NInt dstSampleCount, void * pDstSamples, NSizeType dstSamplesSize, NInt dstSampleIndex, NUInt flags);
NResult N_API NSoundBufferCopyToDataPartN(HNSoundBuffer hSoundBuffer, NInt sampleIndex,
	NSoundFormat_ dstSoundFormat, NInt dstSampleRate, NInt dstSampleCount, HNBuffer hDstSamples, NInt dstSampleIndex, NInt sampleCount, NUInt flags);
NResult N_API NSoundBufferCopyToDataPart(HNSoundBuffer hSoundBuffer, NInt sampleIndex,
	NSoundFormat_ dstSoundFormat, NInt dstSampleRate, NInt dstSampleCount, void * pDstSamples, NSizeType dstSamplesSize, NInt dstSampleIndex, NInt sampleCount, NUInt flags);
NResult N_API NSoundBufferCopyToDataPartExN(HNSoundBuffer hSoundBuffer, NInt sampleIndex,
	NSoundFormat_ dstSoundFormat, NInt dstSampleRate, HNArray hDstMinValue, HNArray hDstMaxValue,
	NInt dstSampleCount, HNBuffer hDstSamples, NInt dstSampleIndex, NInt sampleCount, NUInt flags);
NResult N_API NSoundBufferCopyToDataPartEx(HNSoundBuffer hSoundBuffer, NInt sampleIndex,
	NSoundFormat_ dstSoundFormat, NInt dstSampleRate, HNArray hDstMinValue, HNArray hDstMaxValue,
	NInt dstSampleCount, void * pDstSamples, NSizeType dstSamplesSize, NInt dstSampleIndex, NInt sampleCount, NUInt flags);

NResult N_API NSoundBufferCrop(HNSoundBuffer hSoundBuffer, NInt sampleIndex, NInt sampleCount, HNSoundBuffer * phResultSoundBuffer);

NResult N_API NSoundBufferSaveToFileN(HNSoundBuffer hSoundBuffer, HNString hFileName, HNObject hReserved, NUInt flags);
#ifndef N_NO_ANSI_FUNC
NResult N_API NSoundBufferSaveToFileA(HNSoundBuffer hSoundBuffer, const NAChar * szFileName, HNObject hReserved, NUInt flags);
#endif
#ifndef N_NO_UNICODE
NResult N_API NSoundBufferSaveToFileW(HNSoundBuffer hSoundBuffer, const NWChar * szFileName, HNObject hReserved, NUInt flags);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NSoundBufferSaveToFile(HNSoundBuffer hSoundBuffer, const NChar * szFileName, HNObject hReserved, NUInt flags);
#endif
#define NSoundBufferSaveToFile N_FUNC_AW(NSoundBufferSaveToFile)

NResult N_API NSoundBufferSaveToMemoryN(HNSoundBuffer hSoundBuffer, HNObject hReserved, NUInt flags, HNBuffer * phBuffer);
NResult N_API NSoundBufferSaveToStream(HNSoundBuffer hSoundBuffer, HNStream hStream, HNObject hReserved, NUInt flags);

NResult N_API NSoundBufferGetSoundFormat(HNSoundBuffer hSoundBuffer, NSoundFormat_ * pValue);
NResult N_API NSoundBufferGetSampleRate(HNSoundBuffer hSoundBuffer, NInt * pValue);
NResult N_API NSoundBufferGetMinValue(HNSoundBuffer hSoundBuffer, HNArray * phValue);
NResult N_API NSoundBufferSetMinValue(HNSoundBuffer hSoundBuffer, HNArray hValue);
NResult N_API NSoundBufferGetMaxValue(HNSoundBuffer hSoundBuffer, HNArray * phValue);
NResult N_API NSoundBufferSetMaxValue(HNSoundBuffer hSoundBuffer, HNArray hValue);
NResult N_API NSoundBufferGetLength(HNSoundBuffer hSoundBuffer, NInt * pValue);
NResult N_API NSoundBufferSetLength(HNSoundBuffer hSoundBuffer, NInt value);
NResult N_API NSoundBufferGetCapacity(HNSoundBuffer hSoundBuffer, NInt * pValue);
NResult N_API NSoundBufferSetCapacity(HNSoundBuffer hSoundBuffer, NInt value);
NResult N_API NSoundBufferGetSample(HNSoundBuffer hSoundBuffer, NInt sampleIndex, HNArray * phValue);
NResult N_API NSoundBufferSetSample(HNSoundBuffer hSoundBuffer, NInt sampleIndex, HNArray hValue);
NResult N_API NSoundBufferGetSamplesN(HNSoundBuffer hSoundBuffer, HNBuffer * phValue);
NResult N_API NSoundBufferGetSamplesPtr(HNSoundBuffer hSoundBuffer, void * * pValue);
NResult N_API NSoundBufferGetSamplesSize(HNSoundBuffer hSoundBuffer, NSizeType * pValue);

#ifdef N_CPP
}
#endif

#endif // !N_SOUND_BUFFER_H_INCLUDED
