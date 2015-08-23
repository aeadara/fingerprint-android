#ifndef SIMPLE_TLV_H_INCLUDED
#define SIMPLE_TLV_H_INCLUDED

#include <SmartCards/SimpleTag.h>
#include <IO/NBuffer.h>

#ifdef N_CPP
extern "C"
{
#endif

N_DECLARE_OBJECT_TYPE(SimpleTlv, NObject)

NResult N_API SimpleTlvLoadManyFromMemoryN(HNBuffer hBuffer, NUInt flags, NSizeType * pSize, HSimpleTlv * * parhSimpleTlvs, NInt * pCount);
NResult N_API SimpleTlvLoadManyFromMemoryEx(const void * pBuffer, NSizeType bufferSize, NUInt flags, NSizeType * pSize, HSimpleTlv * * parhSimpleTlvs, NInt * pCount);

NResult N_API SimpleTlvCreateEx(SimpleTag_ tag, NUInt flags, HSimpleTlv * phSimpleTlv);
NResult N_API SimpleTlvCreateFromMemoryN(HNBuffer hBuffer, NUInt flags, NSizeType * pSize, HSimpleTlv * phSimpleTlv);
NResult N_API SimpleTlvCreateFromMemoryEx(const void * pBuffer, NSizeType bufferSize, NUInt flags, NSizeType * pSize, HSimpleTlv * phSimpleTlv);

NResult N_API SimpleTlvGetTag(HSimpleTlv hSimpleTlv, SimpleTag_ * pValue);
NResult N_API SimpleTlvGetLength(HSimpleTlv hSimpleTlv, NSizeType * pValue);
NResult N_API SimpleTlvGetUseThreeByteLengthAlways(HSimpleTlv hSimpleTlv, NBool * pValue);
NResult N_API SimpleTlvSetUseThreeByteLengthAlways(HSimpleTlv hSimpleTlv, NBool value);
NResult N_API SimpleTlvGetValueN(HSimpleTlv hSimpleTlv, HNBuffer * phValue);
NResult N_API SimpleTlvSetValueN(HSimpleTlv hSimpleTlv, HNBuffer hValue);
NResult N_API SimpleTlvSetValueEx(HSimpleTlv hSimpleTlv, const void * pValue, NSizeType valueSize, NBool copy);

#ifdef N_CPP
}
#endif

#endif // !SIMPLE_TLV_H_INCLUDED
