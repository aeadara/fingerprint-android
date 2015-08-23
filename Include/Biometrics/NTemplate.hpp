#ifndef N_TEMPLATE_HPP_INCLUDED
#define N_TEMPLATE_HPP_INCLUDED

#include <Biometrics/NFTemplate.hpp>
#include <Biometrics/NLTemplate.hpp>
#include <Biometrics/NETemplate.hpp>
#include <Biometrics/NSTemplate.hpp>
namespace Neurotec { namespace Biometrics
{
#include <Biometrics/NTemplate.h>
}}

namespace Neurotec { namespace Biometrics
{

class NTemplate : public NObject
{
	N_DECLARE_OBJECT_CLASS(NTemplate, NObject)

private:
	static HNTemplate Create(NUInt flags)
	{
		HNTemplate handle;
		NCheck(NTemplateCreateEx(flags, &handle));
		return handle;
	}

	static HNTemplate Create(const ::Neurotec::IO::NBuffer & buffer, NUInt flags, NSizeType * pSize)
	{
		HNTemplate handle;
		NCheck(NTemplateCreateFromMemoryN(buffer.GetHandle(), flags, pSize, &handle));
		return handle;
	}

	static HNTemplate Create(const void * pBuffer, NSizeType bufferSize, NUInt flags, NSizeType * pSize)
	{
		HNTemplate handle;
		NCheck(NTemplateCreateFromMemory(pBuffer, bufferSize, flags, pSize, &handle));
		return handle;
	}

public:
	static NSizeType CalculateSize(NSizeType fingersTemplateSize, NSizeType facesTemplateSize, NSizeType irisesTemplateSize, NSizeType palmsTemplateSize, NSizeType voicesTemplateSize)
	{
		NSizeType value;
		NCheck(NTemplateCalculateSize(fingersTemplateSize, facesTemplateSize, irisesTemplateSize, palmsTemplateSize, voicesTemplateSize, &value));
		return value;
	}

	static NSizeType Pack(const void * pFingersTemplate, NSizeType fingersTemplateSize,
		const void * pFacesTemplate, NSizeType facesTemplateSize,
		const void * pIrisesTemplate, NSizeType irisesTemplateSize,
		const void * pPalmsTemplate, NSizeType palmsTemplateSize,
		const void * pVoicesTemplate, NSizeType voicesTemplateSize,
		void * pBuffer, NSizeType bufferSize)
	{
		NSizeType value;
		NCheck(NTemplatePack(pFingersTemplate, fingersTemplateSize,
			pFacesTemplate, facesTemplateSize,
			pIrisesTemplate, irisesTemplateSize,
			pPalmsTemplate, palmsTemplateSize,
			pVoicesTemplate, voicesTemplateSize,
			pBuffer, bufferSize, &value));
		return value;
	}

	static void Unpack(const void * pBuffer, NSizeType bufferSize,
		NVersion * pVersion, NUInt * pSize, NByte * pHeaderSize,
		const void * * ppFingersTemplate, NSizeType * pFingersTemplateSize,
		const void * * ppFacesTemplate, NSizeType * pFacesTemplateSize,
		const void * * ppIrisesTemplate, NSizeType * pIrisesTemplateSize,
		const void * * ppPalmsTemplate, NSizeType * pPalmsTemplateSize,
		const void * * ppVoicesTemplate, NSizeType * pVoicesTemplateSize)
	{
		NVersion_ v = 0;
		NCheck(NTemplateUnpack(pBuffer, bufferSize,
			pVersion ? &v : NULL, pSize, pHeaderSize,
			ppFingersTemplate, pFingersTemplateSize,
			ppFacesTemplate, pFacesTemplateSize,
			ppIrisesTemplate, pIrisesTemplateSize,
			ppPalmsTemplate, pPalmsTemplateSize,
			ppVoicesTemplate, pVoicesTemplateSize));
		if (pVersion) *pVersion = NVersion(v);
	}

#ifdef N_DEBUG
	using NObject::Check;
#endif

	static void Check(const ::Neurotec::IO::NBuffer & buffer)
	{
		NCheck(NTemplateCheckN(buffer.GetHandle()));
	}

	static void Check(const void * pBuffer, NSizeType bufferSize)
	{
		NCheck(NTemplateCheck(pBuffer, bufferSize));
	}

	using NObject::GetSize;

	static NSizeType GetSize(const ::Neurotec::IO::NBuffer & buffer)
	{
		NSizeType value;
		NCheck(NTemplateGetSizeMemN(buffer.GetHandle(), &value));
		return value;
	}

	static NSizeType GetSize(const void * pBuffer, NSizeType bufferSize)
	{
		NSizeType value;
		NCheck(NTemplateGetSizeMem(pBuffer, bufferSize, &value));
		return value;
	}

	explicit NTemplate(NUInt flags = 0)
		: NObject(Create(flags), true)
	{
	}

	explicit NTemplate(const ::Neurotec::IO::NBuffer & buffer, NUInt flags = 0, NSizeType * pSize = NULL)
		: NObject(Create(buffer, flags, pSize), true)
	{
	}

	NTemplate(const void * pBuffer, NSizeType bufferSize, NUInt flags = 0, NSizeType * pSize = NULL)
		: NObject(Create(pBuffer, bufferSize, flags, pSize), true)
	{
	}

	NFTemplate GetFingers()
	{
		return GetObject<HandleType, NFTemplate>(NTemplateGetFingersEx, true);
	}

	void SetFingers(const NFTemplate & value)
	{
		return SetObject(NTemplateSetFingers, value);
	}

	NLTemplate GetFaces()
	{
		return GetObject<HandleType, NLTemplate>(NTemplateGetFacesEx, true);
	}

	void SetFaces(const NLTemplate & value)
	{
		return SetObject(NTemplateSetFaces, value);
	}

	NETemplate GetIrises()
	{
		return GetObject<HandleType, NETemplate>(NTemplateGetIrisesEx, true);
	}

	void SetIrises(const NETemplate & value)
	{
		return SetObject(NTemplateSetIrises, value);
	}

	NFTemplate GetPalms()
	{
		return GetObject<HandleType, NFTemplate>(NTemplateGetPalmsEx, true);
	}

	void SetPalms(const NFTemplate & value)
	{
		return SetObject(NTemplateSetPalms, value);
	}

	NSTemplate GetVoices()
	{
		return GetObject<HandleType, NSTemplate>(NTemplateGetVoicesEx, true);
	}

	void SetVoices(const NSTemplate & value)
	{
		return SetObject(NTemplateSetVoices, value);
	}

	void Clear()
	{
		NCheck(NTemplateClear(GetHandle()));
	}
};

}}

#endif // !N_TEMPLATE_HPP_INCLUDED
