#ifndef CONSTRUCTED_BER_TLV_H_INCLUDED
#define CONSTRUCTED_BER_TLV_H_INCLUDED

#include <SmartCards/BerTlv.h>

#ifdef N_CPP
extern "C"
{
#endif

N_DECLARE_OBJECT_TYPE(ConstructedBerTlv, BerTlv)

NResult N_API ConstructedBerTlvGetDataObjectCount(HConstructedBerTlv hBerTlv, NInt * pValue);
NResult N_API ConstructedBerTlvGetDataObjectEx(HConstructedBerTlv hBerTlv, NInt index, HBerTlv * phValue);
NResult N_API ConstructedBerTlvGetDataObjectCapacity(HConstructedBerTlv hBerTlv, NInt * pValue);
NResult N_API ConstructedBerTlvSetDataObjectCapacity(HConstructedBerTlv hBerTlv, NInt value);
NResult N_API ConstructedBerTlvSetDataObject(HConstructedBerTlv hBerTlv, NInt index, HBerTlv hValue);
NResult N_API ConstructedBerTlvAddDataObjectEx2(HConstructedBerTlv hBerTlv, HBerTlv hValue, NInt * pIndex);
NResult N_API ConstructedBerTlvInsertDataObject(HConstructedBerTlv hBerTlv, NInt index, HBerTlv hValue);
N_DEPRECATED("function is deprecated, use ConstructedBerTlvRemoveDataObjectAt instead")
NResult N_API ConstructedBerTlvRemoveDataObject(HConstructedBerTlv hBerTlv, NInt index);
NResult N_API ConstructedBerTlvRemoveDataObjectAt(HConstructedBerTlv hBerTlv, NInt index);
NResult N_API ConstructedBerTlvClearDataObjects(HConstructedBerTlv hBerTlv);
NResult N_API ConstructedBerTlvFindDataObjectIndex(HConstructedBerTlv hBerTlv, BerTag_ tag, NInt * pIndex);
NResult N_API ConstructedBerTlvFindDataObjectEx(HConstructedBerTlv hBerTlv, BerTag_ tag, HBerTlv * phDataObject);

#ifdef N_CPP
}
#endif

#endif // !CONSTRUCTED_BER_TLV_H_INCLUDED
