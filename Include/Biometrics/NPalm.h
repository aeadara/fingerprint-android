#ifndef N_PALM_H_INCLUDED
#define N_PALM_H_INCLUDED

#include <Biometrics/NFrictionRidge.h>

#ifdef N_CPP
extern "C"
{
#endif

N_DECLARE_OBJECT_TYPE(NPalm, NFrictionRidge)

NResult N_API NPalmCreate(HNPalm * phPalm);

#ifdef N_CPP
}
#endif

#endif // !N_PALM_H_INCLUDED
