#ifndef NE_RECORD_H_INCLUDED
#define NE_RECORD_H_INCLUDED

#include <Core/NObject.h>
#include <Biometrics/NBiometricTypes.h>
#include <Biometrics/NBiometricEngineTypes.h>

#ifdef N_CPP
extern "C"
{
#endif

N_DECLARE_OBJECT_TYPE(NERecord, NObject)

NResult N_API NERecordCheckN(HNBuffer hBuffer);
NResult N_API NERecordCheck(const void * pBuffer, NSizeType bufferSize);
NResult N_API NERecordGetSizeMemN(HNBuffer hBuffer, NSizeType * pValue);
NResult N_API NERecordGetSizeMem(const void * pBuffer, NSizeType bufferSize, NSizeType * pValue);
NResult N_API NERecordGetWidthMemN(HNBuffer hBuffer, NUShort * pValue);
NResult N_API NERecordGetWidthMem(const void * pBuffer, NSizeType bufferSize, NUShort * pValue);
NResult N_API NERecordGetHeightMemN(HNBuffer hBuffer, NUShort * pValue);
NResult N_API NERecordGetHeightMem(const void * pBuffer, NSizeType bufferSize, NUShort * pValue);
NResult N_API NERecordGetPositionMemN(HNBuffer hBuffer, NEPosition * pValue);
NResult N_API NERecordGetPositionMem(const void * pBuffer, NSizeType bufferSize, NEPosition * pValue);
NResult N_API NERecordGetQualityMemN(HNBuffer hBuffer, NByte * pValue);
NResult N_API NERecordGetQualityMem(const void * pBuffer, NSizeType bufferSize, NByte * pValue);
NResult N_API NERecordGetCbeffProductTypeMemN(HNBuffer hBuffer, NUShort * pValue);
NResult N_API NERecordGetCbeffProductTypeMem(const void * pBuffer, NSizeType bufferSize, NUShort * pValue);

NResult N_API NERecordCreate(NUShort width, NUShort height, NUInt flags, HNERecord * phRecord);
NResult N_API NERecordCreateFromMemoryN(HNBuffer hBuffer, NUInt flags, NSizeType * pSize, HNERecord * phRecord);
NResult N_API NERecordCreateFromMemory(const void * pBuffer, NSizeType bufferSize, NUInt flags, NSizeType * pSize, HNERecord * phRecord);
NResult N_API NERecordCreateFromNERecord(HNERecord hSrcRecord, NTemplateSize dstTemplateSize, NUInt flags, HNERecord * phDstRecord);

NResult N_API NERecordGetWidth(HNERecord hRecord, NUShort * pValue);
NResult N_API NERecordGetHeight(HNERecord hRecord, NUShort * pValue);
NResult N_API NERecordGetPosition(HNERecord hRecord, NEPosition * pValue);
NResult N_API NERecordSetPosition(HNERecord hRecord, NEPosition value);
NResult N_API NERecordGetQuality(HNERecord hRecord, NByte * pValue);
NResult N_API NERecordSetQuality(HNERecord hRecord, NByte value);
NResult N_API NERecordGetCbeffProductType(HNERecord hRecord, NUShort * pValue);
NResult N_API NERecordSetCbeffProductType(HNERecord hRecord, NUShort value);

#ifdef N_CPP
}
#endif

#endif // !NE_RECORD_H_INCLUDED
