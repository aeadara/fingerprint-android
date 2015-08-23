#ifndef N_MEDIA_TYPES_H_INCLUDED
#define N_MEDIA_TYPES_H_INCLUDED

#include <Core/NTypes.h>

#ifdef N_CPP
extern "C"
{
#endif

typedef enum NMediaType_
{
	nmtNone = 0,
	nmtAudio = 1,
	nmtVideo = 2
} NMediaType;

N_DECLARE_TYPE(NMediaType)

typedef enum NMediaState_
{
	nmsStopped = 0,
	nmsPaused = 1,
	nmsRunning = 2
} NMediaState;

N_DECLARE_TYPE(NMediaState)

typedef enum NVideoInterlaceMode_
{
	nvimUnknown = 0,
	nvimInterlaced = 1,
	nvimProgressive = 2
} NVideoInterlaceMode;

N_DECLARE_TYPE(NVideoInterlaceMode)

NBool N_API NMediaTypeIsValid(NMediaType value);
NBool N_API NMediaTypeIsValidSingle(NMediaType value);

NBool N_API NVideoInterlaceModeIsValid(NVideoInterlaceMode value);

N_DECLARE_STATIC_OBJECT_TYPE(NMediaTypes)

#ifdef N_CPP
}
#endif

#endif // !N_MEDIA_TYPES_H_INCLUDED
