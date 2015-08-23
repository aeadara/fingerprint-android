#ifndef NS_TEMPLATE_H_INCLUDED
#define NS_TEMPLATE_H_INCLUDED

#include <Biometrics/NSRecord.h>

#ifdef N_CPP
extern "C"
{
#endif

#define NST_MAX_RECORD_COUNT 255

N_DECLARE_OBJECT_TYPE(NSTemplate, NObject)

NResult N_API NSTemplateCalculateSize(NInt recordCount, NSizeType * arRecordSizes, NSizeType * pSize);
NResult N_API NSTemplatePack(NInt recordCount, const void * * arpRecords, NSizeType * arRecordSizes, void * pBuffer, NSizeType bufferSize, NSizeType * pSize);
NResult N_API NSTemplateUnpack(const void * pBuffer, NSizeType bufferSize, NVersion_ * pVersion, NUInt * pSize, NByte * pHeaderSize,
	NInt * pRecordCount, const void * * arpRecords, NSizeType * arRecordSizes);
NResult N_API NSTemplateCheckN(HNBuffer hBuffer);
NResult N_API NSTemplateCheck(const void * pBuffer, NSizeType bufferSize);
NResult N_API NSTemplateGetSizeMemN(HNBuffer hBuffer, NSizeType * pValue);
NResult N_API NSTemplateGetSizeMem(const void * pBuffer, NSizeType bufferSize, NSizeType * pValue);
NResult N_API NSTemplateGetRecordCountMemN(HNBuffer hBuffer, NInt * pValue);
NResult N_API NSTemplateGetRecordCountMem(const void * pBuffer, NSizeType bufferSize, NInt * pValue);

#define NST_PROCESS_FIRST_RECORD_ONLY 0x00000100

NResult N_API NSTemplateCreateEx(NUInt flags, HNSTemplate * phTemplate);
NResult N_API NSTemplateCreateFromMemoryN(HNBuffer hBuffer, NUInt flags, NSizeType * pSize, HNSTemplate * phTemplate);
NResult N_API NSTemplateCreateFromMemory(const void * pBuffer, NSizeType bufferSize, NUInt flags, NSizeType * pSize, HNSTemplate * phTemplate);

NResult N_API NSTemplateGetRecordCount(HNSTemplate hTemplate, NInt * pValue);
NResult N_API NSTemplateGetRecordEx(HNSTemplate hTemplate, NInt index, HNSRecord * phValue);
NResult N_API NSTemplateGetRecordCapacity(HNSTemplate hTemplate, NInt * pValue);
NResult N_API NSTemplateSetRecordCapacity(HNSTemplate hTemplate, NInt value);
NResult N_API NSTemplateSetRecord(HNSTemplate hTemplate, NInt index, HNSRecord hValue);
NResult N_API NSTemplateAddRecordEx(HNSTemplate hTemplate, HNSRecord hValue, NInt * pIndex);
NResult N_API NSTemplateInsertRecord(HNSTemplate hTemplate, NInt index, HNSRecord hValue);
N_DEPRECATED("function is deprecated, use NSTemplateRemoveRecordAt instead")
NResult N_API NSTemplateRemoveRecord(HNSTemplate hTemplate, NInt index);
NResult N_API NSTemplateRemoveRecordAt(HNSTemplate hTemplate, NInt index);
NResult N_API NSTemplateClearRecords(HNSTemplate hTemplate);

#ifdef N_CPP
}
#endif

#endif // !NS_TEMPLATE_H_INCLUDED
