#ifndef NL_RECORD_HPP_INCLUDED
#define NL_RECORD_HPP_INCLUDED

#include <Core/NObject.hpp>
#include <Biometrics/NBiometricTypes.hpp>
#include <Biometrics/NBiometricEngineTypes.hpp>
namespace Neurotec { namespace Biometrics
{
#include <Biometrics/NLRecord.h>
}}

namespace Neurotec { namespace Biometrics
{

class NLRecord : public NObject
{
	N_DECLARE_OBJECT_CLASS(NLRecord, NObject)

private:
	static HNLRecord Create(NUInt flags)
	{
		HNLRecord handle;
		NCheck(NLRecordCreate(flags, &handle));
		return handle;
	}

	static HNLRecord Create(const ::Neurotec::IO::NBuffer & buffer, NUInt flags, NSizeType * pSize)
	{
		HNLRecord handle;
		NCheck(NLRecordCreateFromMemoryN(buffer.GetHandle(), flags, pSize, &handle));
		return handle;
	}

	static HNLRecord Create(const void * pBuffer, NSizeType bufferSize, NUInt flags, NSizeType * pSize)
	{
		HNLRecord handle;
		NCheck(NLRecordCreateFromMemory(pBuffer, bufferSize, flags, pSize, &handle));
		return handle;
	}

	static HNLRecord Create(const NLRecord & srcRecord, NTemplateSize dstTemplateSize, NUInt flags)
	{
		HNLRecord handle;
		NCheck(NLRecordCreateFromNLRecord(srcRecord.GetHandle(), dstTemplateSize, flags, &handle));
		return handle;
	}
public:
	using NObject::GetSize;

	static NSizeType GetSize(const ::Neurotec::IO::NBuffer & buffer)
	{
		NSizeType value;
		NCheck(NLRecordGetSizeMemN(buffer.GetHandle(), &value));
		return value;
	}

	static NSizeType GetSize(const void * pBuffer, NSizeType bufferSize)
	{
		NSizeType value;
		NCheck(NLRecordGetSizeMem(pBuffer, bufferSize, &value));
		return value;
	}

	static NByte GetQuality(const ::Neurotec::IO::NBuffer & buffer)
	{
		NByte value;
		NCheck(NLRecordGetQualityMemN(buffer.GetHandle(), &value));
		return value;
	}

	static NByte GetQuality(const void *pBuffer, NSizeType bufferSize)
	{
		NByte value;
		NCheck(NLRecordGetQualityMem(pBuffer, bufferSize, &value));
		return value;
	}

	static NUShort GetCbeffProductType(const ::Neurotec::IO::NBuffer & buffer)
	{
		NUShort value;
		NCheck(NLRecordGetCbeffProductTypeMemN(buffer.GetHandle(), &value));
		return value;
	}

	static NUShort GetCbeffProductType(const void *pBuffer, NSizeType bufferSize)
	{
		NUShort value;
		NCheck(NLRecordGetCbeffProductTypeMem(pBuffer, bufferSize, &value));
		return value;
	}

	static void Check(const ::Neurotec::IO::NBuffer & buffer)
	{
		NCheck(NLRecordCheckN(buffer.GetHandle()));
	}

	static void Check(const void *pBuffer, NSizeType bufferSize)
	{
		NCheck(NLRecordCheck(pBuffer, bufferSize));
	}

	explicit NLRecord(NUInt flags = 0)
		: NObject(Create(flags), true)
	{
	}

	explicit NLRecord(const ::Neurotec::IO::NBuffer & buffer, NUInt flags = 0, NSizeType * pSize = NULL)
		: NObject(Create(buffer, flags, pSize), true)
	{
	}

	NLRecord(const void * pBuffer, NSizeType bufferSize, NUInt flags = 0, NSizeType * pSize = NULL)
		: NObject(Create(pBuffer, bufferSize, flags, pSize), true)
	{
	}

	NLRecord(const NLRecord & srcRecord, NTemplateSize dstTemplateSize, NUInt flags = 0)
		: NObject(Create(srcRecord, dstTemplateSize, flags), true)
	{
	}

	NByte GetQuality() const
	{
		NByte value;
		NCheck(NLRecordGetQuality((HNLRecord)GetHandle(), &value));
		return value;
	}

	void SetQuality(NByte value)
	{
		NCheck(NLRecordSetQuality((HNLRecord)GetHandle(), value));
	}

	NUShort GetCbeffProductType() const
	{
		NUShort value;
		NCheck(NLRecordGetCbeffProductType((HNLRecord)GetHandle(), &value));
		return value;
	}

	void SetCbeffProductType(NUShort value)
	{
		NCheck(NLRecordSetCbeffProductType((HNLRecord)GetHandle(), value));
	}
};

}}

#endif // !NL_RECORD_HPP_INCLUDED
