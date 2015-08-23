#ifndef SIMPLE_TAG_H_INCLUDED
#define SIMPLE_TAG_H_INCLUDED

#include <Core/NTypes.h>

#ifdef N_CPP
extern "C"
{
#endif

typedef NByte SimpleTag_;
#ifndef SIMPLE_TAG_HPP_INCLUDED
typedef SimpleTag_ SimpleTag;
#endif
N_DECLARE_TYPE(SimpleTag)

NBool N_API SimpleTagIsValid(SimpleTag_ value);

NResult N_API SimpleTagToStringN(SimpleTag_ value, HNString hFormat, HNString * phValue);
NResult N_API SimpleTagToStringA(SimpleTag_ value, const NAChar * szFormat, HNString * phValue);
#ifndef N_NO_UNICODE
NResult N_API SimpleTagToStringW(SimpleTag_ value, const NWChar * szFormat, HNString * phValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API SimpleTagToString(SimpleTag value, const NChar * szFormat, HNString * phValue);
#endif
#define SimpleTagToString N_FUNC_AW(SimpleTagToString)

#ifdef N_CPP
}
#endif

#endif // !SIMPLE_TAG_H_INCLUDED
