#ifndef N_SOUND_PROC_H_INCLUDED
#define N_SOUND_PROC_H_INCLUDED

#include <Sound/NSoundBuffer.h>

#ifdef N_CPP
extern "C"
{
#endif

N_DECLARE_STATIC_OBJECT_TYPE(NSoundProc)

NResult N_API NspGetSoundLevel(HNSoundBuffer hSoundBuffer, NDouble * pSoundLevel);

#ifdef N_CPP
}
#endif

#endif // !N_SOUND_PROC_H_INCLUDED
