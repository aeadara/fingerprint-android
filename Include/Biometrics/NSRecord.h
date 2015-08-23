#ifndef NS_RECORD_H_INCLUDED
#define NS_RECORD_H_INCLUDED

#include <Core/NObject.h>

#ifdef N_CPP
extern "C"
{
#endif

N_DECLARE_OBJECT_TYPE(NSRecord, NObject)

NResult N_API NSRecordCheckN(HNBuffer hBuffer);
NResult N_API NSRecordCheck(const void * pBuffer, NSizeType bufferSize);
NResult N_API NSRecordGetSizeMemN(HNBuffer hBuffer, NSizeType * pValue);
NResult N_API NSRecordGetSizeMem(const void * pBuffer, NSizeType bufferSize, NSizeType * pValue);
NResult N_API NSRecordGetPhraseIdMemN(HNBuffer hBuffer, NInt * pValue);
NResult N_API NSRecordGetPhraseIdMem(const void * pBuffer, NSizeType bufferSize, NInt * pValue);
NResult N_API NSRecordGetCbeffProductTypeMemN(HNBuffer hBuffer, NUShort * pValue);
NResult N_API NSRecordGetCbeffProductTypeMem(const void * pBuffer, NSizeType bufferSize, NUShort * pValue);
NResult N_API NSRecordGetQualityMemN(HNBuffer hBuffer, NByte * pValue);
NResult N_API NSRecordGetQualityMem(const void * pBuffer, NSizeType bufferSize, NByte * pValue);
NResult N_API NSRecordGetSnrMemN(HNBuffer hBuffer, NByte * pValue);
NResult N_API NSRecordGetSnrMem(const void * pBuffer, NSizeType bufferSize, NByte * pValue);

NResult N_API NSRecordCreate(NUInt flags, HNSRecord * phRecord);
NResult N_API NSRecordCreateFromMemoryN(HNBuffer hBuffer, NUInt flags, NSizeType * pSize, HNSRecord * phRecord);
NResult N_API NSRecordCreateFromMemory(const void * pBuffer, NSizeType bufferSize, NUInt flags, NSizeType * pSize, HNSRecord * phRecord);

NResult N_API NSRecordGetPhraseId(HNSRecord hRecord, NInt * pValue);
NResult N_API NSRecordSetPhraseId(HNSRecord hRecord, NInt value);
NResult N_API NSRecordGetCbeffProductType(HNSRecord hRecord, NUShort * pValue);
NResult N_API NSRecordSetCbeffProductType(HNSRecord hRecord, NUShort value);
NResult N_API NSRecordGetQuality(HNSRecord hRecord, NByte * pValue);
NResult N_API NSRecordSetQuality(HNSRecord hRecord, NByte value);
NResult N_API NSRecordGetSnr(HNSRecord hRecord, NByte * pValue);
NResult N_API NSRecordSetSnr(HNSRecord hRecord, NByte value);
NResult N_API NSRecordGetHasTextDependentFeatures(HNSRecord hRecord, NBool * pValue);
NResult N_API NSRecordSetHasTextDependentFeatures(HNSRecord hRecord, NBool value);
NResult N_API NSRecordGetHasTextIndependentFeatures(HNSRecord hRecord, NBool * pValue);
NResult N_API NSRecordSetHasTextIndependentFeatures(HNSRecord hRecord, NBool value);

#ifdef N_CPP
}
#endif

#endif // !NS_RECORD_H_INCLUDED
