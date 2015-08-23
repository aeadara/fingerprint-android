#ifndef NL_TEMPLATE_H_INCLUDED
#define NL_TEMPLATE_H_INCLUDED

#include <Biometrics/NLRecord.h>

#ifdef N_CPP
extern "C"
{
#endif

#define NLT_MAX_RECORD_COUNT 255

N_DECLARE_OBJECT_TYPE(NLTemplate, NObject)

NResult N_API NLTemplateCalculateSize(NInt recordCount, NSizeType * arRecordSizes, NSizeType * pSize);
NResult N_API NLTemplatePack(NInt recordCount, const void * * arpRecords, NSizeType * arRecordSizes, void * pBuffer, NSizeType bufferSize, NSizeType * pSize);
NResult N_API NLTemplateUnpack(const void * pBuffer, NSizeType bufferSize, NVersion_ * pVersion, NUInt * pSize, NByte * pHeaderSize,
	NInt * pRecordCount, const void * * arpRecords, NSizeType * arRecordSizes);
NResult N_API NLTemplateCheckN(HNBuffer hBuffer);
NResult N_API NLTemplateCheck(const void * pBuffer, NSizeType bufferSize);
NResult N_API NLTemplateGetSizeMemN(HNBuffer hBuffer, NSizeType * pValue);
NResult N_API NLTemplateGetSizeMem(const void * pBuffer, NSizeType bufferSize, NSizeType * pValue);
NResult N_API NLTemplateGetRecordCountMemN(HNBuffer hBuffer, NInt * pValue);
NResult N_API NLTemplateGetRecordCountMem(const void * pBuffer, NSizeType bufferSize, NInt * pValue);

#define NLT_PROCESS_FIRST_RECORD_ONLY 0x00000100

NResult N_API NLTemplateCreateEx(NUInt flags, HNLTemplate * phTemplate);
NResult N_API NLTemplateCreateFromMemoryN(HNBuffer hBuffer, NUInt flags, NSizeType * pSize, HNLTemplate * phTemplate);
NResult N_API NLTemplateCreateFromMemory(const void * pBuffer, NSizeType bufferSize, NUInt flags, NSizeType * pSize, HNLTemplate * phTemplate);

NResult N_API NLTemplateGetRecordCount(HNLTemplate hTemplate, NInt * pValue);
NResult N_API NLTemplateGetRecordEx(HNLTemplate hTemplate, NInt index, HNLRecord * phValue);
NResult N_API NLTemplateGetRecordCapacity(HNLTemplate hTemplate, NInt * pValue);
NResult N_API NLTemplateSetRecordCapacity(HNLTemplate hTemplate, NInt value);
NResult N_API NLTemplateSetRecord(HNLTemplate hTemplate, NInt index, HNLRecord hValue);
NResult N_API NLTemplateAddRecordEx(HNLTemplate hTemplate, HNLRecord hValue, NInt * pIndex);
NResult N_API NLTemplateInsertRecord(HNLTemplate hTemplate, NInt index, HNLRecord hValue);
N_DEPRECATED("function is deprecated, use NLTemplateRemoveRecordAt instead")
NResult N_API NLTemplateRemoveRecord(HNLTemplate hTemplate, NInt index);
NResult N_API NLTemplateRemoveRecordAt(HNLTemplate hTemplate, NInt index);
NResult N_API NLTemplateClearRecords(HNLTemplate hTemplate);

#ifdef N_CPP
}
#endif

#endif // !NL_TEMPLATE_H_INCLUDED
