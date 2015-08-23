#ifndef BER_TLV_H_INCLUDED
#define BER_TLV_H_INCLUDED

#include <SmartCards/BerTag.h>

#ifdef N_CPP
extern "C"
{
#endif

N_DECLARE_OBJECT_TYPE(BerTlv, NObject)

#define BER_TLV_FF_IS_VALID_FOR_THE_TAG_FIRST_BYTE 1

NResult N_API BerTlvLoadManyFromMemoryN(HNBuffer hBuffer, NUInt flags, NSizeType * pSize, HBerTlv * * parhBerTlvs, NInt * pCount);
NResult N_API BerTlvLoadManyFromMemoryEx(const void * pBuffer, NSizeType bufferSize, NUInt flags, NSizeType * pSize, HBerTlv * * parhBerTlvs, NInt * pCount);

NResult N_API BerTlvCreateEx(BerTag_ tag, NUInt flags, HBerTlv * phBerTlv);
NResult N_API BerTlvCreateFromMemoryN(HNBuffer hBuffer, NUInt flags, NSizeType * pSize, HBerTlv * phBerTlv);
NResult N_API BerTlvCreateFromMemoryEx(const void * pBuffer, NSizeType bufferSize, NUInt flags, NSizeType * pSize, HBerTlv * phBerTlv);

NResult N_API BerTlvGetTag(HBerTlv hBerTlv, BerTag_ * pValue);
NResult N_API BerTlvGetLength(HBerTlv hBerTlv, NSizeType * pValue);
NResult N_API BerTlvGetMinLengthSize(HBerTlv hBerTlv, NInt * pValue);
NResult N_API BerTlvSetMinLengthSize(HBerTlv hBerTlv, NInt value);

#ifdef N_CPP
}
#endif

#endif // !BER_TLV_H_INCLUDED
