#include <Reflection/NMemberInfo.h>
#include <Core/NValue.h>

#ifndef N_CONSTANT_INFO_H_INCLUDED
#define N_CONSTANT_INFO_H_INCLUDED

#ifdef N_CPP
extern "C"
{
#endif

NResult N_API NConstantInfoGetConstantType(HNConstantInfo hConstantInfo, HNType * phValue);
NResult N_API NConstantInfoGetValue(HNConstantInfo hConstantInfo, HNValue * phValue);

#ifdef N_CPP
}
#endif

#endif // !N_CONSTANT_INFO_H_INCLUDED
