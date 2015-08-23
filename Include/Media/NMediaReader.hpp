#ifndef N_MEDIA_READER_HPP_INCLUDED
#define N_MEDIA_READER_HPP_INCLUDED

#include <Media/NMediaSource.hpp>
#include <Sound/NSoundBuffer.hpp>
#include <Images/NImage.hpp>
#include <Core/NTimeSpan.hpp>
namespace Neurotec {
	namespace Media
{
using ::Neurotec::Sound::HNSoundBuffer;
using ::Neurotec::Images::HNImage;
#include <Media/NMediaReader.h>
}}

namespace Neurotec { namespace Media
{

class NMediaReader : public NObject
{
	N_DECLARE_OBJECT_CLASS(NMediaReader, NObject)

private:
	static HNMediaReader Create(const NMediaSource & source, NMediaType mediaTypes, bool isLive, NUInt flags)
	{
		HNMediaReader handle;
		NCheck(NMediaReaderCreate(source.GetHandle(), mediaTypes, isLive, flags, &handle));
		return handle;
	}

public:
	NMediaReader(const NMediaSource & source, NMediaType mediaTypes, bool isLive, NUInt flags = 0)
		: NObject(Create(source, mediaTypes, isLive, flags), true)
	{
	}

	static NMediaReader FromUrl(const NStringWrapper & url, NMediaType mediaTypes, bool isLive, NUInt flags)
	{
		HNMediaReader handle;
		NCheck(NMediaReaderCreateFromUrlN(url.GetHandle(), mediaTypes, isLive, flags, &handle));
		return FromHandle<NMediaReader>(handle);
	}

	static NMediaReader FromFile(const NStringWrapper & fileName, NMediaType mediaTypes, bool isLive, NUInt flags)
	{
		HNMediaReader handle;
		NCheck(NMediaReaderCreateFromFileN(fileName.GetHandle(), mediaTypes, isLive, flags, &handle));
		return FromHandle<NMediaReader>(handle);
	}

	NMediaSource GetSource()
	{
		return GetObject<HandleType, NMediaSource>(NMediaReaderGetSource, true);
	}

	void Start()
	{
		NCheck(NMediaReaderStart(GetHandle()));
	}

	void Stop()
	{
		NCheck(NMediaReaderStop(GetHandle()));
	}

	void Pause()
	{
		NCheck(NMediaReaderPause(GetHandle()));
	}

	::Neurotec::Sound::NSoundBuffer ReadAudioSample(NTimeSpan * pTimeStamp = NULL, NTimeSpan * pDuration = NULL)
	{
		HNSoundBuffer hSoundBuffer;
		NTimeSpan_ ts = 0, d = 0;
		NCheck(NMediaReaderReadAudioSample(GetHandle(), pTimeStamp ? &ts : NULL, pDuration ? &d : NULL, &hSoundBuffer));
		if (pTimeStamp) *pTimeStamp = NTimeSpan(ts);
		if (pDuration) *pDuration = NTimeSpan(d);
		return FromHandle< ::Neurotec::Sound::NSoundBuffer>(hSoundBuffer);
	}

#ifndef N_FRAMEWORK_NATIVE
	::Neurotec::Sound::NSoundBuffer ReadAudioSample(NTimeSpanType * pTimeStamp, NTimeSpanType * pDuration = NULL)
	{
		HNSoundBuffer hSoundBuffer;
		NTimeSpan_ ts = 0, d = 0;
		NCheck(NMediaReaderReadAudioSample(GetHandle(), pTimeStamp ? &ts : NULL, pDuration ? &d : NULL, &hSoundBuffer));
		if (pTimeStamp) *pTimeStamp = NTimeSpan(ts);
		if (pDuration) *pDuration = NTimeSpan(d);
		return FromHandle< ::Neurotec::Sound::NSoundBuffer>(hSoundBuffer);
	}
#endif

	::Neurotec::Images::NImage ReadVideoSample(NTimeSpan * pTimeStamp = NULL, NTimeSpan * pDuration = NULL)
	{
		HNImage hImage;
		NTimeSpan_ ts = 0, d = 0;
		NCheck(NMediaReaderReadVideoSample(GetHandle(), pTimeStamp ? &ts : NULL, pDuration ? &d : NULL, &hImage));
		if (pTimeStamp) *pTimeStamp = NTimeSpan(ts);
		if (pDuration) *pDuration = NTimeSpan(d);
		return FromHandle< ::Neurotec::Images::NImage>(hImage);
	}

#ifndef N_FRAMEWORK_NATIVE
	::Neurotec::Images::NImage ReadVideoSample(NTimeSpanType * pTimeStamp, NTimeSpanType * pDuration = NULL)
	{
		HNImage hImage;
		NTimeSpan_ ts = 0, d = 0;
		NCheck(NMediaReaderReadVideoSample(GetHandle(), pTimeStamp ? &ts : NULL, pDuration ? &d : NULL, &hImage));
		if (pTimeStamp) *pTimeStamp = NTimeSpan(ts);
		if (pDuration) *pDuration = NTimeSpan(d);
		return FromHandle< ::Neurotec::Images::NImage>(hImage);
	}
#endif

	bool IsLive()
	{
		NBool value;
		NCheck(NMediaReaderIsLive(GetHandle(), &value));
		return value != 0;
	}

	NMediaState GetState()
	{
		NMediaState value;
		NCheck(NMediaReaderGetState(GetHandle(), &value));
		return value;
	}

	NTimeSpan GetLength()
	{
		NTimeSpan_ value;
		NCheck(NMediaReaderGetLength(GetHandle(), &value));
		return NTimeSpan(value);
	}

	NTimeSpan GetPosition()
	{
		NTimeSpan_ value;
		NCheck(NMediaReaderGetPosition(GetHandle(), &value));
		return NTimeSpan(value);
	}

	void SetPosition(NTimeSpan value)
	{
		NCheck(NMediaReaderSetPosition(GetHandle(), value.GetValue()));
	}
};

}}

#endif // !N_MEDIA_READER_HPP_INCLUDED
