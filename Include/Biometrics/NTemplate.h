#ifndef N_TEMPLATE_H_INCLUDED
#define N_TEMPLATE_H_INCLUDED

#include <Biometrics/NFTemplate.h>
#include <Biometrics/NLTemplate.h>
#include <Biometrics/NETemplate.h>
#include <Biometrics/NSTemplate.h>

#ifdef N_CPP
extern "C"
{
#endif

N_DECLARE_OBJECT_TYPE(NTemplate, NObject)

NResult N_API NTemplateCalculateSize(NSizeType fingersTemplateSize, NSizeType facesTemplateSize, NSizeType irisesTemplateSize, NSizeType palmsTemplateSize, NSizeType voicesTemplateSize, NSizeType * pSize);
NResult N_API NTemplatePack(
	const void * pFingersTemplate, NSizeType fingersTemplateSize,
	const void * pFacesTemplate, NSizeType facesTemplateSize,
	const void * pIrisesTemplate, NSizeType irisesTemplateSize,
	const void * pPalmsTemplate, NSizeType palmsTemplateSize,
	const void * pVoicesTemplate, NSizeType voicesTemplateSize,
	void * pBuffer, NSizeType bufferSize, NSizeType * pSize);
NResult N_API NTemplateUnpack(const void * pBuffer, NSizeType bufferSize,
	NVersion_ * pVersion, NUInt * pSize, NByte * pHeaderSize,
	const void * * ppFingersTemplate, NSizeType * pFingersTemplateSize,
	const void * * ppFacesTemplate, NSizeType * pFacesTemplateSize,
	const void * * ppIrisesTemplate, NSizeType * pIrisesTemplateSize,
	const void * * ppPalmsTemplate, NSizeType * pPalmsTemplateSize,
	const void * * ppVoicesTemplate, NSizeType * pVoicesTemplateSize);
NResult N_API NTemplateCheckN(HNBuffer hBuffer);
NResult N_API NTemplateCheck(const void * pBuffer, NSizeType bufferSize);
NResult N_API NTemplateGetSizeMemN(HNBuffer hBuffer, NSizeType * pValue);
NResult N_API NTemplateGetSizeMem(const void * pBuffer, NSizeType bufferSize, NSizeType * pValue);

NResult N_API NTemplateCreateEx(NUInt flags, HNTemplate * phTemplate);
NResult N_API NTemplateCreateFromMemoryN(HNBuffer hBuffer, NUInt flags, NSizeType * pSize, HNTemplate * phTemplate);
NResult N_API NTemplateCreateFromMemory(const void * pBuffer, NSizeType bufferSize, NUInt flags, NSizeType * pSize, HNTemplate * phTemplate);
NResult N_API NTemplateGetFingersEx(HNTemplate hTemplate, HNFTemplate * phValue);
NResult N_API NTemplateSetFingers(HNTemplate hTemplate, HNFTemplate hValue);
NResult N_API NTemplateGetFacesEx(HNTemplate hTemplate, HNLTemplate * phValue);
NResult N_API NTemplateSetFaces(HNTemplate hTemplate, HNLTemplate hValue);
NResult N_API NTemplateGetIrisesEx(HNTemplate hTemplate, HNETemplate * phValue);
NResult N_API NTemplateSetIrises(HNTemplate hTemplate, HNETemplate hValue);
NResult N_API NTemplateGetPalmsEx(HNTemplate hTemplate, HNFTemplate * phValue);
NResult N_API NTemplateSetPalms(HNTemplate hTemplate, HNFTemplate hValue);
NResult N_API NTemplateGetVoicesEx(HNTemplate hTemplate, HNSTemplate * phValue);
NResult N_API NTemplateSetVoices(HNTemplate hTemplate, HNSTemplate hValue);
NResult N_API NTemplateClear(HNTemplate hTemplate);

#ifdef N_CPP
}
#endif

#endif // !N_TEMPLATE_H_INCLUDED
