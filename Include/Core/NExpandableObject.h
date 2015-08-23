#ifndef N_EXPANDABLE_OBJECT_H_INCLUDED
#define N_EXPANDABLE_OBJECT_H_INCLUDED

#include <Core/NObject.h>
#include <Core/NPropertyBag.h>

#ifdef N_CPP
extern "C"
{
#endif

N_DECLARE_OBJECT_TYPE(NExpandableObject, NObject)

NResult N_API NExpandableObjectGetProperties(HNExpandableObject hObject, HNPropertyBag * phValue);

#ifdef N_CPP
}
#endif

#endif // !N_EXPANDABLE_OBJECT_H_INCLUDED
