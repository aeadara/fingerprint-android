#include <Biometrics/NBiometric.hpp>
#include <Biometrics/NSAttributes.hpp>

#ifndef N_VOICE_HPP_INCLUDED
#define N_VOICE_HPP_INCLUDED

#include <Sound/NSoundBuffer.hpp>
namespace Neurotec { namespace Biometrics
{
using ::Neurotec::Sound::HNSoundBuffer;
#include <Biometrics/NVoice.h>
}}

namespace Neurotec { namespace Biometrics
{

class NVoice : public NBiometric
{
	N_DECLARE_OBJECT_CLASS(NVoice, NBiometric)

public:
	class ObjectCollection : public ::Neurotec::Collections::NCollectionWithChangeNotifications<NSAttributes, NVoice,
		NVoiceGetObjectCount, NVoiceGetObject, NVoiceGetObjects,
		NVoiceAddObjectsCollectionChanged, NVoiceRemoveObjectsCollectionChanged>
	{
		ObjectCollection(const NVoice & owner)
		{
			SetOwner(owner);
		}

		friend class NVoice;
	};

private:
	static HNVoice Create()
	{
		HNVoice handle;
		NCheck(NVoiceCreate(&handle));
		return handle;
	}

public:
	NVoice()
		: NBiometric(Create(), true)
	{
	}

	static NVoice FromSoundBufferAndTemplate(const ::Neurotec::Sound::NSoundBuffer & soundBuffer, const NSRecord & record)
	{
		HNVoice hVoice;
		NCheck(NVoiceFromSoundBufferAndTemplate(soundBuffer.GetHandle(), record.GetHandle(), &hVoice));
		return FromHandle<NVoice>(hVoice);
	}

	::Neurotec::Sound::NSoundBuffer GetSoundBuffer() const
	{
		HNSoundBuffer hValue;
		NCheck(NVoiceGetSoundBuffer(GetHandle(), &hValue));
		return FromHandle< ::Neurotec::Sound::NSoundBuffer>(hValue, true);
	}

	void SetSoundBuffer(const ::Neurotec::Sound::NSoundBuffer & value)
	{
		NCheck(NVoiceSetSoundBuffer(GetHandle(), value.GetHandle()));
	}

	NInt GetPhraseId() const
	{
		NInt value;
		NCheck(NVoiceGetPhraseId(GetHandle(), &value));
		return value;
	}

	void SetPhraseId(NInt value)
	{
		NCheck(NVoiceSetPhraseId(GetHandle(), value));
	}

	ObjectCollection GetObjects()
	{
		return ObjectCollection(*this);
	}

	const ObjectCollection GetObjects() const
	{
		return ObjectCollection(*this);
	}
};

}}

#endif // !N_VOICE_HPP_INCLUDED
