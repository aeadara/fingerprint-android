#include <Devices/NCaptureDevice.h>

#ifndef N_MICROPHONE_H_INCLUDED
#define N_MICROPHONE_H_INCLUDED

#include <Sound/NSoundBuffer.h>

#ifdef N_CPP
extern "C"
{
#endif

N_DECLARE_OBJECT_TYPE(NMicrophone, NCaptureDevice)

NResult N_API NMicrophoneGetSoundSample(HNMicrophone hDevice, HNSoundBuffer * phSoundBuffer);

#ifdef N_CPP
}
#endif

#endif // !N_MICROPHONE_H_INCLUDED
