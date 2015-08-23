#ifndef N_ENVIRONMENT_H_INCLUDED
#define N_ENVIRONMENT_H_INCLUDED

#include <Core/NObject.h>

#ifdef N_CPP
extern "C"
{
#endif

N_DECLARE_STATIC_OBJECT_TYPE(NEnvironment)

NResult N_NO_INLINE N_API NEnvironmentGetCallStack(NInt framesToSkip, HNString * phValue);
NResult N_API NEnvironmentGetCurrentDirectory(HNString * phPath);
NResult N_API NEnvironmentGetSystemDirectory(HNString * phPath);

#ifdef N_CPP
}
#endif

#endif // !N_ENVIRONMENT_H_INCLUDED
