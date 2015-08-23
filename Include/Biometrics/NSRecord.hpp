#ifndef NS_RECORD_HPP_INCLUDED
#define NS_RECORD_HPP_INCLUDED

#include <Core/NObject.hpp>
namespace Neurotec { namespace Biometrics
{
#include <Biometrics/NSRecord.h>
}}

namespace Neurotec { namespace Biometrics
{

class NSRecord : public NObject
{
	N_DECLARE_OBJECT_CLASS(NSRecord, NObject)

private:
	static HNSRecord Create(NUInt flags)
	{
		HNSRecord handle;
		NCheck(NSRecordCreate(flags, &handle));
		return handle;
	}

	static HNSRecord Create(const ::Neurotec::IO::NBuffer & buffer, NUInt flags, NSizeType * pSize)
	{
		HNSRecord handle;
		NCheck(NSRecordCreateFromMemoryN(buffer.GetHandle(), flags, pSize, &handle));
		return handle;
	}

	static HNSRecord Create(const void * pBuffer, NSizeType bufferSize, NUInt flags, NSizeType * pSize)
	{
		HNSRecord handle;
		NCheck(NSRecordCreateFromMemory(pBuffer, bufferSize, flags, pSize, &handle));
		return handle;
	}

public:
	using NObject::GetSize;

	static NSizeType GetSize(const ::Neurotec::IO::NBuffer & buffer)
	{
		NSizeType value;
		NCheck(NSRecordGetSizeMemN(buffer.GetHandle(), &value));
		return value;
	}

	static NSizeType GetSize(const void * pBuffer, NSizeType bufferSize)
	{
		NSizeType value;
		NCheck(NSRecordGetSizeMem(pBuffer, bufferSize, &value));
		return value;
	}

	static NInt GetPhraseId(const ::Neurotec::IO::NBuffer & buffer)
	{
		NInt value;
		NCheck(NSRecordGetPhraseIdMemN(buffer.GetHandle(), &value));
		return value;
	}

	static NInt GetPhraseId(const void * pBuffer, NSizeType bufferSize)
	{
		NInt value;
		NCheck(NSRecordGetPhraseIdMem(pBuffer, bufferSize, &value));
		return value;
	}

	static NUShort GetCbeffProductType(const ::Neurotec::IO::NBuffer & buffer)
	{
		NUShort value;
		NCheck(NSRecordGetCbeffProductTypeMemN(buffer.GetHandle(), &value));
		return value;
	}

	static NUShort GetCbeffProductType(const void * pBuffer, NSizeType bufferSize)
	{
		NUShort value;
		NCheck(NSRecordGetCbeffProductTypeMem(pBuffer, bufferSize, &value));
		return value;
	}

	static NByte GetQuality(const ::Neurotec::IO::NBuffer & buffer)
	{
		NByte value;
		NCheck(NSRecordGetQualityMemN(buffer.GetHandle(), &value));
		return value;
	}

	static NByte GetQuality(const void * pBuffer, NSizeType bufferSize)
	{
		NByte value;
		NCheck(NSRecordGetQualityMem(pBuffer, bufferSize, &value));
		return value;
	}

	static NByte GetSnr(const ::Neurotec::IO::NBuffer & buffer)
	{
		NByte value;
		NCheck(NSRecordGetSnrMemN(buffer.GetHandle(), &value));
		return value;
	}

	static NByte GetSnr(const void * pBuffer, NSizeType bufferSize)
	{
		NByte value;
		NCheck(NSRecordGetSnrMem(pBuffer, bufferSize, &value));
		return value;
	}

	static void Check(const ::Neurotec::IO::NBuffer & buffer)
	{
		NCheck(NSRecordCheckN(buffer.GetHandle()));
	}

	static void Check(const void * pBuffer, NSizeType bufferSize)
	{
		NCheck(NSRecordCheck(pBuffer, bufferSize));
	}

	explicit NSRecord(NUInt flags = 0)
		: NObject(Create(flags), true)
	{
	}

	explicit NSRecord(const ::Neurotec::IO::NBuffer & buffer, NUInt flags = 0, NSizeType * pSize = NULL)
		: NObject(Create(buffer, flags, pSize), true)
	{
	}

	NSRecord(const void * pBuffer, NSizeType bufferSize, NUInt flags = 0, NSizeType * pSize = NULL)
		: NObject(Create(pBuffer, bufferSize, flags, pSize), true)
	{
	}

	NInt GetPhraseId() const
	{
		NInt value;
		NCheck(NSRecordGetPhraseId(GetHandle(), &value));
		return value;
	}

	void SetPhraseId(NInt value)
	{
		NCheck(NSRecordSetPhraseId(GetHandle(), value));
	}

	NUShort GetCbeffProductType() const
	{
		NUShort value;
		NCheck(NSRecordGetCbeffProductType(GetHandle(), &value));
		return value;
	}

	void SetCbeffProductType(NUShort value)
	{
		NCheck(NSRecordSetCbeffProductType(GetHandle(), value));
	}

	NByte GetQuality() const
	{
		NByte value;
		NCheck(NSRecordGetQuality(GetHandle(), &value));
		return value;
	}

	void SetQuality(NByte value)
	{
		NCheck(NSRecordSetQuality(GetHandle(), value));
	}

	NByte GetSnr() const
	{
		NByte value;
		NCheck(NSRecordGetSnr(GetHandle(), &value));
		return value;
	}

	void SetSnr(NByte value)
	{
		NCheck(NSRecordSetSnr(GetHandle(), value));
	}

	NBool GetHasTextDependentFeatures() const
	{
		NBool value;
		NCheck(NSRecordGetHasTextDependentFeatures(GetHandle(), &value));
		return value;
	}

	void SetHasTextDependentFeatures(NBool value)
	{
		NCheck(NSRecordSetHasTextDependentFeatures(GetHandle(), value));
	}

	NBool GetHasTextIndependentFeatures() const
	{
		NBool value;
		NCheck(NSRecordGetHasTextIndependentFeatures(GetHandle(), &value));
		return value;
	}

	void SetHasTextIndependentFeatures(NBool value)
	{
		NCheck(NSRecordSetHasTextIndependentFeatures(GetHandle(), value));
	}
};

}}

#endif // !NS_RECORD_HPP_INCLUDED
