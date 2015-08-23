#ifndef NS_ATTRIBUTES_HPP_INCLUDED
#define NS_ATTRIBUTES_HPP_INCLUDED

#include <Biometrics/NBiometricAttributes.hpp>
#include <Biometrics/NSRecord.hpp>
#include <Core/NTimeSpan.hpp>
namespace Neurotec { namespace Biometrics
{
#include <Biometrics/NSAttributes.h>
}}

namespace Neurotec { namespace Biometrics
{

class NVoice;

class NSAttributes : public NBiometricAttributes
{
	N_DECLARE_OBJECT_CLASS(NSAttributes, NBiometricAttributes)

private:
	static HNSAttributes Create(NInt phraseId)
	{
		HNSAttributes handle;
		NCheck(NSAttributesCreate(phraseId, &handle));
		return handle;
	}

public:
	explicit NSAttributes(NInt phraseId)
		: NBiometricAttributes(Create(phraseId), true)
	{
	}

	NVoice GetOwner() const;

	NInt GetPhraseId() const
	{
		NInt value;
		NCheck(NSAttributesGetPhraseId(GetHandle(), &value));
		return value;
	}

	NTimeSpan GetVoiceStart() const
	{
		NTimeSpan_ value;
		NCheck(NSAttributesGetVoiceStart(GetHandle(), &value));
		return NTimeSpan(value);
	}

	NTimeSpan GetVoiceDuration() const
	{
		NTimeSpan_ value;
		NCheck(NSAttributesGetVoiceDuration(GetHandle(), &value));
		return NTimeSpan(value);
	}

	bool IsVoiceDetected() const
	{
		NBool value;
		NCheck(NSAttributesIsVoiceDetected(GetHandle(), &value));
		return value != 0;
	}

	NDouble GetSoundLevel() const
	{
		NDouble value;
		NCheck(NSAttributesGetSoundLevel(GetHandle(), &value));
		return value;
	}

	NSRecord GetTemplate() const
	{
		return GetObject<HandleType, NSRecord>(NSAttributesGetTemplate, true);
	}

	void SetTemplate(const NSRecord & value)
	{
		NCheck(NSAttributesSetTemplate(GetHandle(), value.GetHandle()));
	}
};

}}

#include <Biometrics/NVoice.hpp>

namespace Neurotec { namespace Biometrics
{

inline NVoice NSAttributes::GetOwner() const
{
	return NObject::GetOwner<NVoice>();
}

}}

#endif // !NS_ATTRIBUTES_HPP_INCLUDED
