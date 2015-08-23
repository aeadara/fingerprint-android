#include <Core/NObject.h>

#ifndef N_OBJECT_PART_H_INCLUDED
#define N_OBJECT_PART_H_INCLUDED

#ifdef N_CPP
extern "C"
{
#endif

NResult N_API NObjectPartGetObjectPartInfo(HNObjectPart hObjectPart, HNObjectPartInfo * phValue);

#ifdef N_CPP
}
#endif

#endif // !N_OBJECT_PART_H_INCLUDED
