#include <Devices/NCaptureDevice.hpp>

#ifndef N_MICROPHONE_HPP_INCLUDED
#define N_MICROPHONE_HPP_INCLUDED

#include <Sound/NSoundBuffer.hpp>
namespace Neurotec { namespace Devices
{
using ::Neurotec::Sound::HNSoundBuffer;
#include <Devices/NMicrophone.h>
}}

namespace Neurotec { namespace Devices
{
class NMicrophone : public NCaptureDevice
{
	N_DECLARE_OBJECT_CLASS(NMicrophone, NCaptureDevice)

public:
	::Neurotec::Sound::NSoundBuffer GetSoundSample()
	{
		HNSoundBuffer hSoundBuffer = NULL;
		NCheck(NMicrophoneGetSoundSample(GetHandle(), &hSoundBuffer));
		return FromHandle< ::Neurotec::Sound::NSoundBuffer>(hSoundBuffer);
	}
};

}}

#endif // !N_MICROPHONE_HPP_INCLUDED
