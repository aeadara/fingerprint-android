#ifndef NL_RECORD_H_INCLUDED
#define NL_RECORD_H_INCLUDED

#include <Core/NObject.h>
#include <Biometrics/NBiometricEngineTypes.h>

#ifdef N_CPP
extern "C"
{
#endif

N_DECLARE_OBJECT_TYPE(NLRecord, NObject)

NResult N_API NLRecordCheckN(HNBuffer hBuffer);
NResult N_API NLRecordCheck(const void * pBuffer, NSizeType bufferSize);
NResult N_API NLRecordGetSizeMemN(HNBuffer hBuffer, NSizeType * pValue);
NResult N_API NLRecordGetSizeMem(const void * pBuffer, NSizeType bufferSize, NSizeType * pValue);
NResult N_API NLRecordGetQualityMemN(HNBuffer hBuffer, NByte *pValue);
NResult N_API NLRecordGetQualityMem(const void *pBuffer, NSizeType bufferSize, NByte *pValue);
NResult N_API NLRecordGetCbeffProductTypeMemN(HNBuffer hBuffer, NUShort * pValue);
NResult N_API NLRecordGetCbeffProductTypeMem(const void * pBuffer, NSizeType bufferSize, NUShort * pValue);

NResult N_API NLRecordCreate(NUInt flags, HNLRecord * phRecord);
NResult N_API NLRecordCreateFromMemoryN(HNBuffer hBuffer, NUInt flags, NSizeType * pSize, HNLRecord * phRecord);
NResult N_API NLRecordCreateFromMemory(const void * pBuffer, NSizeType bufferSize, NUInt flags, NSizeType * pSize, HNLRecord * phRecord);
NResult N_API NLRecordCreateFromNLRecord(HNLRecord hSrcRecord, NTemplateSize dstTemplateSize, NUInt flags, HNLRecord * phDstRecord);

NResult N_API NLRecordGetQuality(HNLRecord hRecord, NByte *pValue);
NResult N_API NLRecordSetQuality(HNLRecord hRecord, NByte value);
NResult N_API NLRecordGetCbeffProductType(HNLRecord hRecord, NUShort *pValue);
NResult N_API NLRecordSetCbeffProductType(HNLRecord hRecord, NUShort value);

#ifdef N_CPP
}
#endif

#endif // !NL_RECORD_H_INCLUDED
