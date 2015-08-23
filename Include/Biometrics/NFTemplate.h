#ifndef NF_TEMPLATE_H_INCLUDED
#define NF_TEMPLATE_H_INCLUDED

#include <Biometrics/NFRecord.h>

#ifdef N_CPP
extern "C"
{
#endif

#define NFT_MAX_RECORD_COUNT 255

N_DECLARE_OBJECT_TYPE(NFTemplate, NObject)

NResult N_API NFTemplateCalculateSize(NBool isPalm, NInt recordCount, NSizeType * arRecordSizes, NSizeType * pSize);
NResult N_API NFTemplatePack(NBool isPalm, NInt recordCount, const void * * arpRecords, NSizeType * arRecordSizes, void * pBuffer, NSizeType bufferSize, NSizeType * pSize);
NResult N_API NFTemplateUnpack(const void * pBuffer, NSizeType bufferSize, NBool * pIsPalm, NVersion_ * pVersion, NUInt * pSize, NByte * pHeaderSize,
	NInt * pRecordCount, const void * * arpRecords, NSizeType * arRecordSizes);
NResult N_API NFTemplateCheckN(HNBuffer hBuffer);
NResult N_API NFTemplateCheck(const void * pBuffer, NSizeType bufferSize);
NResult N_API NFTemplateIsPalmMemN(HNBuffer hBuffer, NBool * pValue);
NResult N_API NFTemplateIsPalmMem(const void * pBuffer, NSizeType bufferSize, NBool * pValue);
NResult N_API NFTemplateGetSizeMemN(HNBuffer hBuffer, NSizeType * pValue);
NResult N_API NFTemplateGetSizeMem(const void * pBuffer, NSizeType bufferSize, NSizeType * pValue);
NResult N_API NFTemplateGetRecordCountMemN(HNBuffer hBuffer, NInt * pValue);
NResult N_API NFTemplateGetRecordCountMem(const void * pBuffer, NSizeType bufferSize, NInt * pValue);

#define NFT_PROCESS_FIRST_RECORD_ONLY 0x00000100

NResult N_API NFTemplateCreateEx(NBool isPalm, NUInt flags, HNFTemplate * phTemplate);
NResult N_API NFTemplateCreateFromMemoryN(HNBuffer hBuffer, NUInt flags, NSizeType * pSize, HNFTemplate * phTemplate);
NResult N_API NFTemplateCreateFromMemory(const void * pBuffer, NSizeType bufferSize, NUInt flags, NSizeType * pSize, HNFTemplate * phTemplate);

NResult N_API NFTemplateGetRecordCount(HNFTemplate hTemplate, NInt * pValue);
NResult N_API NFTemplateGetRecordEx(HNFTemplate hTemplate, NInt index, HNFRecord * phValue);
NResult N_API NFTemplateGetRecordCapacity(HNFTemplate hTemplate, NInt * pValue);
NResult N_API NFTemplateSetRecordCapacity(HNFTemplate hTemplate, NInt value);
NResult N_API NFTemplateSetRecord(HNFTemplate hTemplate, NInt index, HNFRecord hValue);
NResult N_API NFTemplateAddRecordEx(HNFTemplate hTemplate, HNFRecord hValue, NInt * pIndex);
NResult N_API NFTemplateInsertRecord(HNFTemplate hTemplate, NInt index, HNFRecord hValue);
N_DEPRECATED("function is deprecated, use NFTemplateRemoveRecordAt instead")
NResult N_API NFTemplateRemoveRecord(HNFTemplate hTemplate, NInt index);
NResult N_API NFTemplateRemoveRecordAt(HNFTemplate hTemplate, NInt index);
NResult N_API NFTemplateClearRecords(HNFTemplate hTemplate);

NResult N_API NFTemplateIsPalm(HNFTemplate hTemplate, NBool * pValue);

#ifdef N_CPP
}
#endif

#endif // !NF_TEMPLATE_H_INCLUDED
