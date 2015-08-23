#ifndef N_SOUND_BUFFER_HPP_INCLUDED
#define N_SOUND_BUFFER_HPP_INCLUDED

#include <Sound/NSoundFormat.hpp>
#include <Core/NArray.hpp>
#include <Media/NAudioFormat.hpp>
namespace Neurotec { namespace Sound
{
using ::Neurotec::Media::HNAudioFormat;
#include <Sound/NSoundBuffer.h>
}}

namespace Neurotec { namespace Sound
{

#undef NSB_ALL_DST
#undef NSB_ALL_SRC
#undef NSB_ALL_DST_AND_SRC

const NUInt NSB_ALL_DST = 0x00000F00;
const NUInt NSB_ALL_SRC = 0x0000F000;
const NUInt NSB_ALL_DST_AND_SRC = (NSB_ALL_DST | NSB_ALL_SRC);

class NSoundBuffer : public NObject
{
	N_DECLARE_OBJECT_CLASS(NSoundBuffer, NObject)

public:
	static NSoundBuffer GetWrapper(const NSoundFormat & soundFormat, NInt sampleRate, NInt sampleCount, const ::Neurotec::IO::NBuffer & samples, NUInt flags = 0)
	{
		HNSoundBuffer handle;
		NCheck(NSoundBufferCreateWrapperN(soundFormat.GetValue(), sampleRate, sampleCount, samples.GetHandle(), flags, &handle));
		return FromHandle<NSoundBuffer>(handle);
	}

	static NSoundBuffer GetWrapper(const NSoundFormat & soundFormat, NInt sampleRate, NInt sampleCount, void * pSamples, NSizeType samplesSize, bool ownsSamples, NUInt flags = 0)
	{
		HNSoundBuffer handle;
		NCheck(NSoundBufferCreateWrapper(soundFormat.GetValue(), sampleRate, sampleCount, pSamples, samplesSize, ownsSamples ? NTrue : NFalse, flags, &handle));
		return FromHandle<NSoundBuffer>(handle);
	}

	static NSoundBuffer GetWrapper(const NSoundFormat & soundFormat, NInt sampleRate, NInt srcSampleCount, const ::Neurotec::IO::NBuffer & samples, NInt sampleIndex, NInt sampleCount, NUInt flags = 0)
	{
		HNSoundBuffer handle;
		NCheck(NSoundBufferCreateWrapperForPartN(soundFormat.GetValue(), sampleRate, srcSampleCount, samples.GetHandle(), sampleIndex, sampleCount, flags, &handle));
		return FromHandle<NSoundBuffer>(handle);
	}

	static NSoundBuffer GetWrapper(const NSoundFormat & soundFormat, NInt sampleRate, NInt srcSampleCount, void * pSamples, NSizeType samplesSize, NInt sampleIndex, NInt sampleCount, NUInt flags = 0)
	{
		HNSoundBuffer handle;
		NCheck(NSoundBufferCreateWrapperForPart(soundFormat.GetValue(), sampleRate, srcSampleCount, pSamples, samplesSize, sampleIndex, sampleCount, flags, &handle));
		return FromHandle<NSoundBuffer>(handle);
	}

	static NSoundBuffer GetWrapper(const NSoundBuffer & srcSoundBuffer, NInt sampleIndex, NInt sampleCount, NUInt flags = 0)
	{
		HNSoundBuffer handle;
		NCheck(NSoundBufferCreateWrapperForSoundBufferPart(srcSoundBuffer.GetHandle(), sampleIndex, sampleCount, flags, &handle));
		return FromHandle<NSoundBuffer>(handle);
	}

	static NSoundBuffer Create(const NSoundFormat & soundFormat, NInt sampleRate, NInt sampleCount, NUInt flags = 0)
	{
		HNSoundBuffer handle;
		NCheck(NSoundBufferCreate(soundFormat.GetValue(), sampleRate, sampleCount, flags, &handle));
		return FromHandle<NSoundBuffer>(handle);
	}

	static NSoundBuffer FromData(const NSoundFormat & soundFormat, NInt sampleRate, NInt sampleCount, const ::Neurotec::IO::NBuffer & samples, NUInt flags = 0)
	{
		HNSoundBuffer handle;
		NCheck(NSoundBufferCreateFromDataN(soundFormat.GetValue(), sampleRate, sampleCount, samples.GetHandle(), flags, &handle));
		return FromHandle<NSoundBuffer>(handle);
	}

	static NSoundBuffer FromData(const NSoundFormat & soundFormat, NInt sampleRate, NInt sampleCount, const void * pSamples, NSizeType samplesSize, NUInt flags = 0)
	{
		HNSoundBuffer handle;
		NCheck(NSoundBufferCreateFromData(soundFormat.GetValue(), sampleRate, sampleCount, pSamples, samplesSize, flags, &handle));
		return FromHandle<NSoundBuffer>(handle);
	}

	static NSoundBuffer FromData(const NSoundFormat & soundFormat, NInt sampleRate, NInt srcSampleCount, const ::Neurotec::IO::NBuffer & samples, NInt sampleIndex, NInt sampleCount, NUInt flags = 0)
	{
		HNSoundBuffer handle;
		NCheck(NSoundBufferCreateFromDataPartN(soundFormat.GetValue(), sampleRate, srcSampleCount, samples.GetHandle(), sampleIndex, sampleCount, flags, &handle));
		return FromHandle<NSoundBuffer>(handle);
	}

	static NSoundBuffer FromData(const NSoundFormat & soundFormat, NInt sampleRate, NInt srcSampleCount, const void * pSamples, NSizeType samplesSize, NInt sampleIndex, NInt sampleCount, NUInt flags = 0)
	{
		HNSoundBuffer handle;
		NCheck(NSoundBufferCreateFromDataPart(soundFormat.GetValue(), sampleRate, srcSampleCount, pSamples, samplesSize, sampleIndex, sampleCount, flags, &handle));
		return FromHandle<NSoundBuffer>(handle);
	}

	static NSoundBuffer FromSoundBuffer(const NSoundFormat & soundFormat, const NSoundBuffer & srcSoundBuffer, NUInt flags = 0)
	{
		HNSoundBuffer handle;
		NCheck(NSoundBufferCreateFromSoundBuffer(soundFormat.GetValue(), srcSoundBuffer.GetHandle(), flags, &handle));
		return FromHandle<NSoundBuffer>(handle);
	}

	static NSoundBuffer FromSoundBuffer(const NSoundFormat & soundFormat, const NSoundBuffer & srcSoundBuffer, NInt sampleIndex, NInt sampleCount, NUInt flags = 0)
	{
		HNSoundBuffer handle;
		NCheck(NSoundBufferCreateFromSoundBufferPart(soundFormat.GetValue(), srcSoundBuffer.GetHandle(), sampleIndex, sampleCount, flags, &handle));
		return FromHandle<NSoundBuffer>(handle);
	}

	static NSoundBuffer FromFile(const NStringWrapper & fileName, NUInt flags = 0)
	{
		HNSoundBuffer hSoundBuffer;
		NCheck(NSoundBufferCreateFromFileN(fileName.GetHandle(), flags, &hSoundBuffer));
		return FromHandle<NSoundBuffer>(hSoundBuffer);
	}

	static NSoundBuffer FromMemory(const ::Neurotec::IO::NBuffer & buffer, NUInt flags = 0, NSizeType * pSize = NULL)
	{
		HNSoundBuffer hSoundBuffer;
		NCheck(NSoundBufferCreateFromMemoryN(buffer.GetHandle(), flags, pSize, &hSoundBuffer));
		return FromHandle<NSoundBuffer>(hSoundBuffer);
	}

	static NSoundBuffer FromMemory(const void * pBuffer, NSizeType bufferSize, NUInt flags = 0, NSizeType * pSize = NULL)
	{
		HNSoundBuffer hSoundBuffer;
		NCheck(NSoundBufferCreateFromMemory(pBuffer, bufferSize, flags, pSize, &hSoundBuffer));
		return FromHandle<NSoundBuffer>(hSoundBuffer);
	}

	static NSoundBuffer FromStream(const ::Neurotec::IO::NStream & stream, NUInt flags = 0)
	{
		HNSoundBuffer hSoundBuffer;
		NCheck(NSoundBufferCreateFromStream(stream.GetHandle(), flags, &hSoundBuffer));
		return FromHandle<NSoundBuffer>(hSoundBuffer);
	}

	static NArrayWrapper<NUInt> GetSupportedAudioSubtypes()
	{
		NUInt * arValues;
		NInt valueCount;
		NCheck(NSoundBufferGetSupportedAudioSubtypes(&arValues, &valueCount));
		return NArrayWrapper<NUInt>(arValues, valueCount);
	}

	static bool IsAudioSubtypeSupported(NUInt value)
	{
		NBool result;
		NCheck(NSoundBufferIsAudioSubtypeSupported(value, &result));
		return result != 0;
	}

	static bool IsAudioFormatSupported(const ::Neurotec::Media::NAudioFormat & format)
	{
		NBool result;
		NCheck(NSoundBufferIsAudioFormatSupported(format.GetHandle(), &result));
		return result != 0;
	}

	static NSoundBuffer FromAudioSample(const ::Neurotec::Media::NAudioFormat & format, const ::Neurotec::IO::NBuffer & sample)
	{
		HNSoundBuffer hSoundBuffer;
		NCheck(NSoundBufferCreateFromAudioSampleN(format.GetHandle(), sample.GetHandle(), &hSoundBuffer));
		return FromHandle<NSoundBuffer>(hSoundBuffer);
	}

	static NSoundBuffer FromAudioSample(const ::Neurotec::Media::NAudioFormat & format, const void * pSample, NSizeType sampleSize)
	{
		HNSoundBuffer hSoundBuffer;
		NCheck(NSoundBufferCreateFromAudioSample(format.GetHandle(), pSample, sampleSize, &hSoundBuffer));
		return FromHandle<NSoundBuffer>(hSoundBuffer);
	}

	static void Copy(const NSoundFormat & srcSoundFormat, NInt srcSampleRate, const NArray & srcMinValue, const NArray & srcMaxValue, NInt srcSampleCount, const ::Neurotec::IO::NBuffer & srcSamples, NInt srcSampleIndex,
		const NSoundFormat & dstSoundFormat, NInt dstSampleRate, const NArray & dstMinValue, const NArray & dstMaxValue, NInt dstSampleCount, const ::Neurotec::IO::NBuffer & dstSamples, NInt dstSampleIndex, NInt sampleCount, NUInt flags = 0)
	{
		NCheck(NSoundBufferCopyDataExN(srcSoundFormat.GetValue(), srcSampleRate, srcMinValue.GetHandle(), srcMaxValue.GetHandle(), srcSampleCount, srcSamples.GetHandle(), srcSampleIndex,
			dstSoundFormat.GetValue(), dstSampleRate, dstMinValue.GetHandle(), dstMaxValue.GetHandle(), dstSampleCount, dstSamples.GetHandle(), dstSampleIndex, sampleCount, flags));
	}

	static void Copy(const NSoundFormat & srcSoundFormat, NInt srcSampleRate, const NArray & srcMinValue, const NArray & srcMaxValue, NInt srcSampleCount, const void * pSrcSamples, NSizeType srcSamplesSize, NInt srcSampleIndex,
		const NSoundFormat & dstSoundFormat, NInt dstSampleRate, const NArray & dstMinValue, const NArray & dstMaxValue, NInt dstSampleCount, void * pDstSamples, NSizeType dstSamplesSize, NInt dstSampleIndex, NInt sampleCount, NUInt flags = 0)
	{
		NCheck(NSoundBufferCopyDataEx(srcSoundFormat.GetValue(), srcSampleRate, srcMinValue.GetHandle(), srcMaxValue.GetHandle(), srcSampleCount, pSrcSamples, srcSamplesSize, srcSampleIndex,
			dstSoundFormat.GetValue(), dstSampleRate, dstMinValue.GetHandle(), dstMaxValue.GetHandle(), dstSampleCount, pDstSamples, dstSamplesSize, dstSampleIndex, sampleCount, flags));
	}

	static void Copy(const NSoundFormat & srcSoundFormat, NInt srcSampleRate, NInt srcSampleCount, const ::Neurotec::IO::NBuffer & srcSamples, NInt srcSampleIndex,
		const NSoundFormat & dstSoundFormat, NInt dstSampleRate, NInt dstSampleCount, const ::Neurotec::IO::NBuffer & dstSamples, NInt dstSampleIndex, NInt sampleCount, NUInt flags = 0)
	{
		NCheck(NSoundBufferCopyDataN(srcSoundFormat.GetValue(), srcSampleRate, srcSampleCount, srcSamples.GetHandle(), srcSampleIndex,
			dstSoundFormat.GetValue(), dstSampleRate, dstSampleCount, dstSamples.GetHandle(), dstSampleIndex, sampleCount, flags));
	}

	static void Copy(const NSoundFormat & srcSoundFormat, NInt srcSampleRate, NInt srcSampleCount, const void * pSrcSamples, NSizeType srcSamplesSize, NInt srcSampleIndex,
		const NSoundFormat & dstSoundFormat, NInt dstSampleRate, NInt dstSampleCount, void * pDstSamples, NSizeType dstSamplesSize, NInt dstSampleIndex, NInt sampleCount, NUInt flags = 0)
	{
		NCheck(NSoundBufferCopyData(srcSoundFormat.GetValue(), srcSampleRate, srcSampleCount, pSrcSamples, srcSamplesSize, srcSampleIndex,
			dstSoundFormat.GetValue(), dstSampleRate, dstSampleCount, pDstSamples, dstSamplesSize, dstSampleIndex, sampleCount, flags));
	}

	static void Copy(const NSoundBuffer & srcSoundBuffer, NInt sampleIndex, const NSoundBuffer & dstSoundBuffer, NInt dstSampleIndex, NInt sampleCount)
	{
		NCheck(NSoundBufferCopy(srcSoundBuffer.GetHandle(), sampleIndex, dstSoundBuffer.GetHandle(), dstSampleIndex, sampleCount));
	}

	void CopyFrom(const NSoundFormat & srcSoundFormat, NInt srcSampleRate, NInt srcSampleCount, const ::Neurotec::IO::NBuffer & srcSamples, NInt sampleIndex, NUInt flags = 0)
	{
		NCheck(NSoundBufferCopyFromDataN(GetHandle(), srcSoundFormat.GetValue(), srcSampleRate, srcSampleCount, srcSamples.GetHandle(), sampleIndex, flags));
	}

	void CopyFrom(const NSoundFormat & srcSoundFormat, NInt srcSampleRate, NInt srcSampleCount, const void * pSrcSamples, NSizeType srcSamplesSize, NInt sampleIndex, NUInt flags = 0)
	{
		NCheck(NSoundBufferCopyFromData(GetHandle(), srcSoundFormat.GetValue(), srcSampleRate, srcSampleCount, pSrcSamples, srcSamplesSize, sampleIndex, flags));
	}

	void CopyFrom(const NSoundFormat & srcSoundFormat, NInt srcSampleRate, NInt srcSampleCount, const ::Neurotec::IO::NBuffer & srcSamples, NInt srcSampleIndex, NInt sampleIndex, NInt sampleCount, NUInt flags = 0)
	{
		NCheck(NSoundBufferCopyFromDataPartN(GetHandle(), srcSoundFormat.GetValue(), srcSampleRate, srcSampleCount, srcSamples.GetHandle(), srcSampleIndex, sampleIndex, sampleCount, flags));
	}

	void CopyFrom(const NSoundFormat & srcSoundFormat, NInt srcSampleRate, NInt srcSampleCount, const void * pSrcSamples, NSizeType srcSamplesSize, NInt srcSampleIndex, NInt sampleIndex, NInt sampleCount, NUInt flags = 0)
	{
		NCheck(NSoundBufferCopyFromDataPart(GetHandle(), srcSoundFormat.GetValue(), srcSampleRate, srcSampleCount, pSrcSamples, srcSamplesSize, srcSampleIndex, sampleIndex, sampleCount, flags));
	}

	void CopyFrom(const NSoundFormat & srcSoundFormat, NInt srcSampleRate, const NArray & srcMinValue, const NArray & srcMaxValue, NInt srcSampleCount, const ::Neurotec::IO::NBuffer & srcSamples, NInt srcSampleIndex, NInt sampleIndex, NInt sampleCount, NUInt flags = 0)
	{
		NCheck(NSoundBufferCopyFromDataPartExN(GetHandle(), srcSoundFormat.GetValue(), srcSampleRate, srcMinValue.GetHandle(), srcMaxValue.GetHandle(), srcSampleCount, srcSamples.GetHandle(), srcSampleIndex, sampleIndex, sampleCount, flags));
	}

	void CopyFrom(const NSoundFormat & srcSoundFormat, NInt srcSampleRate, const NArray & srcMinValue, const NArray & srcMaxValue, NInt srcSampleCount, const void * pSrcSamples, NSizeType srcSamplesSize, NInt srcSampleIndex, NInt sampleIndex, NInt sampleCount, NUInt flags = 0)
	{
		NCheck(NSoundBufferCopyFromDataPartEx(GetHandle(), srcSoundFormat.GetValue(), srcSampleRate, srcMinValue.GetHandle(), srcMaxValue.GetHandle(), srcSampleCount, pSrcSamples, srcSamplesSize, srcSampleIndex, sampleIndex, sampleCount, flags));
	}

	void Append(const NSoundBuffer & other)
	{
		NCheck(NSoundBufferAppend(GetHandle(), other.GetHandle()));
	}

	void Append(const NSoundFormat & soundFormat, NInt sampleRate, NInt sampleCount, const ::Neurotec::IO::NBuffer & samples, NUInt flags = 0)
	{
		NCheck(NSoundBufferAppendDataN(GetHandle(), soundFormat.GetValue(), sampleRate, sampleCount, samples.GetHandle(), flags));
	}

	void Append(const NSoundFormat & soundFormat, NInt sampleRate, NInt sampleCount, const void * pSamples, NSizeType samplesSize, NUInt flags = 0)
	{
		NCheck(NSoundBufferAppendData(GetHandle(), soundFormat.GetValue(), sampleRate, sampleCount, pSamples, samplesSize, flags));
	}

	void Append(const NSoundFormat & soundFormat, NInt sampleRate, const NArray & minValue, const NArray & maxValue, NInt sampleCount, const ::Neurotec::IO::NBuffer & samples, NUInt flags = 0)
	{
		NCheck(NSoundBufferAppendDataExN(GetHandle(), soundFormat.GetValue(), sampleRate, minValue.GetHandle(), maxValue.GetHandle(), sampleCount, samples.GetHandle(), flags));
	}

	void Append(const NSoundFormat & soundFormat, NInt sampleRate, const NArray & minValue, const NArray & maxValue, NInt sampleCount, const void * pSamples, NSizeType samplesSize, NUInt flags = 0)
	{
		NCheck(NSoundBufferAppendDataEx(GetHandle(), soundFormat.GetValue(), sampleRate, minValue.GetHandle(), maxValue.GetHandle(), sampleCount, pSamples, samplesSize, flags));
	}

	void Clear()
	{
		NCheck(NSoundBufferClear(GetHandle()));
	}

	void CopyTo(const NSoundBuffer & dstSoundBuffer, NInt dstSampleIndex) const
	{
		NCheck(NSoundBufferCopyTo(GetHandle(), dstSoundBuffer.GetHandle(), dstSampleIndex));
	}

	void CopyTo(const NSoundFormat & dstSoundFormat, NInt dstSampleRate, NInt dstSampleCount, const ::Neurotec::IO::NBuffer & dstSamples, NInt dstSampleIndex, NUInt flags = 0) const
	{
		NCheck(NSoundBufferCopyToDataN(GetHandle(), dstSoundFormat.GetValue(), dstSampleRate, dstSampleCount, dstSamples.GetHandle(), dstSampleIndex, flags));
	}

	void CopyTo(const NSoundFormat & dstSoundFormat, NInt dstSampleRate, NInt dstSampleCount, void * pDstSamples, NSizeType dstSamplesSize, NInt dstSampleIndex, NUInt flags = 0) const
	{
		NCheck(NSoundBufferCopyToData(GetHandle(), dstSoundFormat.GetValue(), dstSampleRate, dstSampleCount, pDstSamples, dstSamplesSize, dstSampleIndex, flags));
	}

	void CopyTo(NInt sampleIndex, const NSoundFormat & dstSoundFormat, NInt dstSampleRate, NInt dstSampleCount, const ::Neurotec::IO::NBuffer & dstSamples, NInt dstSampleIndex, NInt sampleCount, NUInt flags = 0) const
	{
		NCheck(NSoundBufferCopyToDataPartN(GetHandle(), sampleIndex, dstSoundFormat.GetValue(), dstSampleRate, dstSampleCount, dstSamples.GetHandle(), dstSampleIndex, sampleCount, flags));
	}

	void CopyTo(NInt sampleIndex, const NSoundFormat & dstSoundFormat, NInt dstSampleRate, NInt dstSampleCount, void * pDstSamples, NSizeType dstSamplesSize, NInt dstSampleIndex, NInt sampleCount, NUInt flags = 0) const
	{
		NCheck(NSoundBufferCopyToDataPart(GetHandle(), sampleIndex, dstSoundFormat.GetValue(), dstSampleRate, dstSampleCount, pDstSamples, dstSamplesSize, dstSampleIndex, sampleCount, flags));
	}

	void CopyTo(NInt sampleIndex, const NSoundFormat & dstSoundFormat, NInt dstSampleRate, const NArray & dstMinValue, const NArray & dstMaxValue, NInt dstSampleCount, const ::Neurotec::IO::NBuffer & dstSamples, NInt dstSampleIndex, NInt sampleCount, NUInt flags = 0) const
	{
		NCheck(NSoundBufferCopyToDataPartExN(GetHandle(), sampleIndex, dstSoundFormat.GetValue(), dstSampleRate, dstMinValue.GetHandle(), dstMaxValue.GetHandle(), dstSampleCount, dstSamples.GetHandle(), dstSampleIndex, sampleCount, flags));
	}

	void CopyTo(NInt sampleIndex, const NSoundFormat & dstSoundFormat, NInt dstSampleRate, const NArray & dstMinValue, const NArray & dstMaxValue, NInt dstSampleCount, void * pDstSamples, NSizeType dstSamplesSize, NInt dstSampleIndex, NInt sampleCount, NUInt flags = 0) const
	{
		NCheck(NSoundBufferCopyToDataPartEx(GetHandle(), sampleIndex, dstSoundFormat.GetValue(), dstSampleRate, dstMinValue.GetHandle(), dstMaxValue.GetHandle(), dstSampleCount, pDstSamples, dstSamplesSize, dstSampleIndex, sampleCount, flags));
	}

	NSoundBuffer Crop(NInt sampleIndex, NInt sampleCount) const
	{
		HNSoundBuffer handle;
		NCheck(NSoundBufferCrop(GetHandle(), sampleIndex, sampleCount, &handle));
		return FromHandle<NSoundBuffer>(handle);
	}

	void Save(const NStringWrapper & fileName, const NObject & reserved = NULL, NUInt flags = 0) const;
	::Neurotec::IO::NBuffer Save(const NObject & reserved = NULL, NUInt flags = 0) const;
	void Save(const ::Neurotec::IO::NStream & stream, const NObject & reserved = NULL, NUInt flags = 0) const;

	NSoundFormat GetSoundFormat() const
	{
		NSoundFormat_ value;
		NCheck(NSoundBufferGetSoundFormat(GetHandle(), &value));
		return NSoundFormat(value);
	}

	NArray GetMinValue() const
	{
		HNArray hValue;
		NCheck(NSoundBufferGetMinValue(GetHandle(), &hValue));
		return FromHandle<NArray>(hValue, true);
	}

	void SetMinValue(const NArray & value)
	{
		NCheck(NSoundBufferSetMinValue(GetHandle(), value.GetHandle()));
	}

	NArray GetMaxValue() const
	{
		HNArray hValue;
		NCheck(NSoundBufferGetMaxValue(GetHandle(), &hValue));
		return FromHandle<NArray>(hValue, true);
	}

	void SetMaxValue(const NArray & value)
	{
		NCheck(NSoundBufferSetMaxValue(GetHandle(), value.GetHandle()));
	}

	NInt GetSampleRate() const
	{
		NInt value;
		NCheck(NSoundBufferGetSampleRate(GetHandle(), &value));
		return value;
	}

	NInt GetLength() const
	{
		NInt value;
		NCheck(NSoundBufferGetLength(GetHandle(), &value));
		return value;
	}

	void SetLength(NInt value)
	{
		NCheck(NSoundBufferSetLength(GetHandle(), value));
	}

	NInt GetCapacity() const
	{
		NInt value;
		NCheck(NSoundBufferGetCapacity(GetHandle(), &value));
		return value;
	}

	void SetCapacity(NInt value)
	{
		NCheck(NSoundBufferSetCapacity(GetHandle(), value));
	}

	NArray GetSample(NInt sampleIndex) const
	{
		HNArray hValue;
		NCheck(NSoundBufferGetSample(GetHandle(), sampleIndex, &hValue));
		return FromHandle<NArray>(hValue, true);
	}

	void SetSample(NInt sampleIndex, const NArray & value)
	{
		NCheck(NSoundBufferSetSample(GetHandle(), sampleIndex, value.GetHandle()));
	}

	::Neurotec::IO::NBuffer GetSamples()
	{
		HNBuffer hValue;
		NCheck(NSoundBufferGetSamplesN(GetHandle(), &hValue));
		return FromHandle< ::Neurotec::IO::NBuffer>(hValue);
	}

	const void * GetSamplesPtr() const
	{
		void * pValue;
		NCheck(NSoundBufferGetSamplesPtr(GetHandle(), &pValue));
		return pValue;
	}

	void * GetSamplesPtr()
	{
		void * pValue;
		NCheck(NSoundBufferGetSamplesPtr(GetHandle(), &pValue));
		return pValue;
	}

	NSizeType GetSamplesSize() const
	{
		NSizeType value;
		NCheck(NSoundBufferGetSamplesSize(GetHandle(), &value));
		return value;
	}
};

}}

namespace Neurotec { namespace Sound
{

inline void NSoundBuffer::Save(const NStringWrapper & fileName, const NObject & reserved, NUInt flags) const
{
	NCheck(NSoundBufferSaveToFileN(GetHandle(), fileName.GetHandle(), reserved.GetHandle(), flags));
}

inline ::Neurotec::IO::NBuffer NSoundBuffer::Save(const NObject & reserved, NUInt flags) const
{
	HNBuffer hBuffer;
	NCheck(NSoundBufferSaveToMemoryN(GetHandle(), reserved.GetHandle(), flags, &hBuffer));
	return FromHandle< ::Neurotec::IO::NBuffer>(hBuffer);
}

inline void NSoundBuffer::Save(const ::Neurotec::IO::NStream & stream, const NObject & reserved, NUInt flags) const
{
	NCheck(NSoundBufferSaveToStream(GetHandle(), stream.GetHandle(), reserved.GetHandle(), flags));
}

}}

#endif // !N_SOUND_BUFFER_HPP_INCLUDED
