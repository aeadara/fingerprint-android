#ifndef WSQ_H_INCLUDED
#define WSQ_H_INCLUDED

#include <Images/NImage.h>
#include <Images/NistCom.h>

#ifdef N_CPP
extern "C"
{
#endif

#define WSQ_DEFAULT_BIT_RATE 0.75f

#define WSQ_IMPLEMENTATION_NEUROTECHNOLOGY_WIN32_X86 10150
#define WSQ_IMPLEMENTATION_NEUROTECHNOLOGY_WIN64_X64 10151

#define WSQ_IMPLEMENTATION_NEUROTECHNOLOGY_DEBIAN_I386 10152
#define WSQ_IMPLEMENTATION_NEUROTECHNOLOGY_DEBIAN_AMD64 10153

#define WSQ_IMPLEMENTATION_NEUROTECHNOLOGY_MACOSX_INTEL 10154
#define WSQ_IMPLEMENTATION_NEUROTECHNOLOGY_MACOSX_INTEL64 10155
#define WSQ_IMPLEMENTATION_NEUROTECHNOLOGY_MACOSX_POWERPC 10156

N_DECLARE_OBJECT_TYPE(WsqInfo, NImageInfo)

NResult N_API WsqInfoGetBitRate(HWsqInfo hInfo, NFloat * pValue);
NResult N_API WsqInfoSetBitRate(HWsqInfo hInfo, NFloat value);
NResult N_API WsqInfoGetImplementationNumber(HWsqInfo hInfo, NUShort * pValue);
NResult N_API WsqInfoHasNistCom(HWsqInfo hInfo, NBool * pValue);
NResult N_API WsqInfoSetHasNistCom(HWsqInfo hInfo, NBool value);
NResult N_API WsqInfoGetNistCom(HWsqInfo hInfo, HNistCom * phValue);

#ifdef N_CPP
}
#endif

#endif // !WSQ_H_INCLUDED
