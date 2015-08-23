#ifndef N_SOUND_PROC_HPP_INCLUDED
#define N_SOUND_PROC_HPP_INCLUDED

#include <Sound/NSoundBuffer.hpp>
namespace Neurotec { namespace Sound { namespace Processing
{
using ::Neurotec::Sound::HNSoundBuffer;
#include <Sound/Processing/NSoundProc.h>
}}}

namespace Neurotec { namespace Sound { namespace Processing
{

class NSoundProc
{
	N_DECLARE_STATIC_OBJECT_CLASS(NSoundProc)

public:
	static NDouble GetSoundLevel(const NSoundBuffer & soundBuffer)
	{
		NDouble soundLevel;
		NCheck(NspGetSoundLevel(soundBuffer.GetHandle(), &soundLevel));
		return soundLevel;
	}
};

}}}

#endif // !N_SOUND_PROC_HPP_INCLUDED
