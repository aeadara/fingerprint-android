#ifndef NE_TEMPLATE_H_INCLUDED
#define NE_TEMPLATE_H_INCLUDED

#include <Biometrics/NERecord.h>

#ifdef N_CPP
extern "C"
{
#endif

#define NET_MAX_RECORD_COUNT 255

N_DECLARE_OBJECT_TYPE(NETemplate, NObject)

NResult N_API NETemplateCalculateSize(NInt recordCount, NSizeType * arRecordSizes, NSizeType * pSize);
NResult N_API NETemplatePack(NInt recordCount, const void * * arpRecords, NSizeType * arRecordSizes, void * pBuffer, NSizeType bufferSize, NSizeType * pSize);
NResult N_API NETemplateUnpack(const void * pBuffer, NSizeType bufferSize, NVersion_ * pVersion, NUInt * pSize, NByte * pHeaderSize,
	NInt * pRecordCount, const void * * arpRecords, NSizeType * arRecordSizes);
NResult N_API NETemplateCheckN(HNBuffer hBuffer);
NResult N_API NETemplateCheck(const void * pBuffer, NSizeType bufferSize);
NResult N_API NETemplateGetSizeMemN(HNBuffer hBuffer, NSizeType * pValue);
NResult N_API NETemplateGetSizeMem(const void * pBuffer, NSizeType bufferSize, NSizeType * pValue);
NResult N_API NETemplateGetRecordCountMemN(HNBuffer hBuffer, NInt * pValue);
NResult N_API NETemplateGetRecordCountMem(const void * pBuffer, NSizeType bufferSize, NInt * pValue);

#define NET_PROCESS_FIRST_RECORD_ONLY 0x00000100

NResult N_API NETemplateCreateEx(NUInt flags, HNETemplate * phTemplate);
NResult N_API NETemplateCreateFromMemoryN(HNBuffer hBuffer, NUInt flags, NSizeType * pSize, HNETemplate * phTemplate);
NResult N_API NETemplateCreateFromMemory(const void * pBuffer, NSizeType bufferSize, NUInt flags, NSizeType * pSize, HNETemplate * phTemplate);

NResult N_API NETemplateGetRecordCount(HNETemplate hTemplate, NInt * pValue);
NResult N_API NETemplateGetRecordEx(HNETemplate hTemplate, NInt index, HNERecord * phValue);
NResult N_API NETemplateGetRecordCapacity(HNETemplate hTemplate, NInt * pValue);
NResult N_API NETemplateSetRecordCapacity(HNETemplate hTemplate, NInt value);
NResult N_API NETemplateSetRecord(HNETemplate hTemplate, NInt index, HNERecord hValue);
NResult N_API NETemplateAddRecordEx(HNETemplate hTemplate, HNERecord hValue, NInt * pIndex);
NResult N_API NETemplateInsertRecord(HNETemplate hTemplate, NInt index, HNERecord hValue);
N_DEPRECATED("function is deprecated, use NETemplateRemoveRecordAt instead")
NResult N_API NETemplateRemoveRecord(HNETemplate hTemplate, NInt index);
NResult N_API NETemplateRemoveRecordAt(HNETemplate hTemplate, NInt index);

NResult N_API NETemplateClearRecords(HNETemplate hTemplate);

#ifdef N_CPP
}
#endif

#endif // !NE_TEMPLATE_H_INCLUDED
