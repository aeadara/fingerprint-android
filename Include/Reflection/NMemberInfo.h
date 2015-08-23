#include <Core/NType.h>

#ifndef N_MEMBER_INFO_H_INCLUDED
#define N_MEMBER_INFO_H_INCLUDED

#ifdef N_CPP
extern "C"
{
#endif

NResult N_API NMemberInfoGetDeclaringType(HNMemberInfo hMemberInfo, HNType * phValue);
NResult N_API NMemberInfoGetId(HNMemberInfo hMemberInfo, NInt * pValue);
NResult N_API NMemberInfoGetName(HNMemberInfo hMemberInfo, HNString * phValue);
NResult N_API NMemberInfoGetAttributes(HNMemberInfo hMemberInfo, NAttributes * pValue);

#ifdef N_CPP
}
#endif

#endif // !N_MEMBER_INFO_H_INCLUDED
