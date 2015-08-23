#ifndef PRIMITIVE_BER_TLV_H_INCLUDED
#define PRIMITIVE_BER_TLV_H_INCLUDED

#include <SmartCards/BerTlv.h>

#ifdef N_CPP
extern "C"
{
#endif

N_DECLARE_OBJECT_TYPE(PrimitiveBerTlv, BerTlv)

NResult N_API PrimitiveBerTlvGetValueN(HPrimitiveBerTlv hBerTlv, HNBuffer * phValue);
NResult N_API PrimitiveBerTlvGetValueAsBoolean(HPrimitiveBerTlv hBerTlv, NBool * pValue);
NResult N_API PrimitiveBerTlvGetValueAsInteger(HPrimitiveBerTlv hBerTlv, NInt * pValue);
NResult N_API PrimitiveBerTlvGetValueAsByte(HPrimitiveBerTlv hBerTlv, NByte * pValue);
NResult N_API PrimitiveBerTlvGetValueAsSByte(HPrimitiveBerTlv hBerTlv, NSByte * pValue);
NResult N_API PrimitiveBerTlvGetValueAsUInt16(HPrimitiveBerTlv hBerTlv, NUShort * pValue);
NResult N_API PrimitiveBerTlvGetValueAsInt16(HPrimitiveBerTlv hBerTlv, NShort * pValue);
NResult N_API PrimitiveBerTlvGetValueAsUInt32(HPrimitiveBerTlv hBerTlv, NUInt * pValue);
NResult N_API PrimitiveBerTlvGetValueAsInt32(HPrimitiveBerTlv hBerTlv, NInt * pValue);
NResult N_API PrimitiveBerTlvSetValueN(HPrimitiveBerTlv hBerTlv, HNBuffer hValue);
NResult N_API PrimitiveBerTlvSetValueEx(HPrimitiveBerTlv hBerTlv, const void * pValue, NSizeType valueSize, NBool copy);
NResult N_API PrimitiveBerTlvSetValueAsBoolean(HPrimitiveBerTlv hBerTlv, NBool value);
NResult N_API PrimitiveBerTlvSetValueAsInteger(HPrimitiveBerTlv hBerTlv, NInt value);
NResult N_API PrimitiveBerTlvSetValueAsByte(HPrimitiveBerTlv hBerTlv, NByte value);
NResult N_API PrimitiveBerTlvSetValueAsSByte(HPrimitiveBerTlv hBerTlv, NSByte value);
NResult N_API PrimitiveBerTlvSetValueAsUInt16(HPrimitiveBerTlv hBerTlv, NUShort value);
NResult N_API PrimitiveBerTlvSetValueAsInt16(HPrimitiveBerTlv hBerTlv, NShort value);
NResult N_API PrimitiveBerTlvSetValueAsUInt32(HPrimitiveBerTlv hBerTlv, NUInt value);
NResult N_API PrimitiveBerTlvSetValueAsInt32(HPrimitiveBerTlv hBerTlv, NInt value);

#ifdef N_CPP
}
#endif

#endif // !PRIMITIVE_BER_TLV_H_INCLUDED
