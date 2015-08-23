#ifndef NE_RECORD_HPP_INCLUDED
#define NE_RECORD_HPP_INCLUDED

#include <Core/NObject.hpp>
#include <Biometrics/NBiometricTypes.hpp>
namespace Neurotec { namespace Biometrics
{
#include <Biometrics/NERecord.h>
}}

namespace Neurotec { namespace Biometrics
{

class NERecord : public NObject
{
	N_DECLARE_OBJECT_CLASS(NERecord, NObject)

private:
	static HNERecord Create(NUShort width, NUShort height, NUInt flags)
	{
		HNERecord handle;
		NCheck(NERecordCreate(width, height, flags, &handle));
		return handle;
	}

	static HNERecord Create(const ::Neurotec::IO::NBuffer & buffer, NUInt flags, NSizeType * pSize)
	{
		HNERecord handle;
		NCheck(NERecordCreateFromMemoryN(buffer.GetHandle(), flags, pSize, &handle));
		return handle;
	}

	static HNERecord Create(const void * pBuffer, NSizeType bufferSize, NUInt flags, NSizeType * pSize)
	{
		HNERecord handle;
		NCheck(NERecordCreateFromMemory(pBuffer, bufferSize, flags, pSize, &handle));
		return handle;
	}

	static HNERecord Create(const NERecord & srcRecord, NTemplateSize dstTemplateSize, NUInt flags)
	{
		HNERecord handle;
		NCheck(NERecordCreateFromNERecord(srcRecord.GetHandle(), dstTemplateSize, flags, &handle));
		return handle;
	}

public:
	using NObject::GetSize;

	static NSizeType GetSize(const ::Neurotec::IO::NBuffer & buffer)
	{
		NSizeType value;
		NCheck(NERecordGetSizeMemN(buffer.GetHandle(), &value));
		return value;
	}

	static NSizeType GetSize(const void * pBuffer, NSizeType bufferSize)
	{
		NSizeType value;
		NCheck(NERecordGetSizeMem(pBuffer, bufferSize, &value));
		return value;
	}

	static NUShort GetWidth(const ::Neurotec::IO::NBuffer & buffer)
	{
		NUShort value;
		NCheck(NERecordGetWidthMemN(buffer.GetHandle(), &value));
		return value;
	}

	static NUShort GetWidth(const void * pBuffer, NSizeType bufferSize)
	{
		NUShort value;
		NCheck(NERecordGetWidthMem(pBuffer, bufferSize, &value));
		return value;
	}

	static NUShort GetHeight(const ::Neurotec::IO::NBuffer & buffer)
	{
		NUShort value;
		NCheck(NERecordGetHeightMemN(buffer.GetHandle(), &value));
		return value;
	}

	static NUShort GetHeight(const void * pBuffer, NSizeType bufferSize)
	{
		NUShort value;
		NCheck(NERecordGetHeightMem(pBuffer, bufferSize, &value));
		return value;
	}

	static NEPosition GetPosition(const ::Neurotec::IO::NBuffer & buffer)
	{
		NEPosition value;
		NCheck(NERecordGetPositionMemN(buffer.GetHandle(), &value));
		return value;
	}

	static NEPosition GetPosition(const void * pBuffer, NSizeType bufferSize)
	{
		NEPosition value;
		NCheck(NERecordGetPositionMem(pBuffer, bufferSize, &value));
		return value;
	}

	static NByte GetQuality(const ::Neurotec::IO::NBuffer & buffer)
	{
		NByte value;
		NCheck(NERecordGetQualityMemN(buffer.GetHandle(), &value));
		return value;
	}

	static NByte GetQuality(const void * pBuffer, NSizeType bufferSize)
	{
		NByte value;
		NCheck(NERecordGetQualityMem(pBuffer, bufferSize, &value));
		return value;
	}

	static NUShort GetCbeffProductType(const ::Neurotec::IO::NBuffer & buffer)
	{
		NUShort value;
		NCheck(NERecordGetCbeffProductTypeMemN(buffer.GetHandle(), &value));
		return value;
	}

	static NUShort GetCbeffProductType(const void * pBuffer, NSizeType bufferSize)
	{
		NUShort value;
		NCheck(NERecordGetCbeffProductTypeMem(pBuffer, bufferSize, &value));
		return value;
	}

	static void Check(const ::Neurotec::IO::NBuffer & buffer)
	{
		NCheck(NERecordCheckN(buffer.GetHandle()));
	}

	static void Check(const void * pBuffer, NSizeType bufferSize)
	{
		NCheck(NERecordCheck(pBuffer, bufferSize));
	}

	NERecord(NUShort width, NUShort height, NUInt flags = 0)
		: NObject(Create(width, height, flags), true)
	{
	}

	explicit NERecord(const ::Neurotec::IO::NBuffer & buffer, NUInt flags = 0, NSizeType * pSize = NULL)
		: NObject(Create(buffer, flags, pSize), true)
	{
	}

	NERecord(const void * pBuffer, NSizeType bufferSize, NUInt flags = 0, NSizeType *pSize = NULL)
		: NObject(Create(pBuffer, bufferSize, flags, pSize), true)
	{
	}

	NERecord(NERecord & srcRecord, NTemplateSize dstTemplateSize, NUInt flags = 0)
		: NObject(Create(srcRecord, dstTemplateSize, flags), true)
	{
	}

	NUShort GetWidth() const
	{
		NUShort value;
		NCheck(NERecordGetWidth((HNERecord)GetHandle(), &value));
		return value;
	}

	NUShort GetHeight() const
	{
		NUShort value;
		NCheck(NERecordGetHeight((HNERecord)GetHandle(), &value));
		return value;
	}

	NEPosition GetPosition() const
	{
		NEPosition value;
		NCheck(NERecordGetPosition((HNERecord)GetHandle(), &value));
		return value;
	}

	void SetPosition(NEPosition value)
	{
		NCheck(NERecordSetPosition((HNERecord)GetHandle(), value));
	}

	NByte GetQuality() const
	{
		NByte value;
		NCheck(NERecordGetQuality((HNERecord)GetHandle(), &value));
		return value;
	}

	void SetQuality(NByte value)
	{
		NCheck(NERecordSetQuality((HNERecord)GetHandle(), value));
	}

	NUShort GetCbeffProductType() const
	{
		NUShort value;
		NCheck(NERecordGetCbeffProductType((HNERecord)GetHandle(), &value));
		return value;
	}

	void SetCbeffProductType(NUShort value)
	{
		NCheck(NERecordSetCbeffProductType((HNERecord)GetHandle(), value));
	}
};

}}

#endif // !NE_RECORD_HPP_INCLUDED
