#ifndef NS_TEMPLATE_HPP_INCLUDED
#define NS_TEMPLATE_HPP_INCLUDED

#include <Biometrics/NSRecord.hpp>
namespace Neurotec { namespace Biometrics
{
#include <Biometrics/NSTemplate.h>
}}

namespace Neurotec { namespace Biometrics
{
#undef NST_MAX_RECORD_COUNT
#undef NST_PROCESS_FIRST_RECORD_ONLY

const NInt NST_MAX_RECORD_COUNT = 255;
const NUInt NST_PROCESS_FIRST_RECORD_ONLY = 0x00000100;

class NSTemplate : public NObject
{
	N_DECLARE_OBJECT_CLASS(NSTemplate, NObject)

public:
	class RecordCollection : public ::Neurotec::Collections::NCollectionBase<NSRecord, NSTemplate,
		NSTemplateGetRecordCount, NSTemplateGetRecordEx>
	{
		RecordCollection(const NSTemplate & owner)
		{
			SetOwner(owner);
		}

		friend class NSTemplate;
	public:
		NInt GetCapacity() const
		{
			NInt value;
			NCheck(NSTemplateGetRecordCapacity(this->GetOwnerHandle(), &value));
			return value;
		}

		void SetCapacity(NInt value)
		{
			NCheck(NSTemplateSetRecordCapacity(this->GetOwnerHandle(), value));
		}

		void Set(NInt index, const NSRecord & value)
		{
			NCheck(NSTemplateSetRecord(this->GetOwnerHandle(), index, value.GetHandle()));
		}

		NInt Add(const NSRecord & value)
		{
			NInt index;
			NCheck(NSTemplateAddRecordEx(this->GetOwnerHandle(), value.GetHandle(), &index));
			return index;
		}

		void Insert(NInt index, const NSRecord & value)
		{
			NCheck(NSTemplateInsertRecord(this->GetOwnerHandle(), index, value.GetHandle()));
		}

		void RemoveAt(NInt index)
		{
			NCheck(NSTemplateRemoveRecordAt(this->GetOwnerHandle(), index));
		}

		void Clear()
		{
			NCheck(NSTemplateClearRecords(this->GetOwnerHandle()));
		}
	};

private:
	static HNSTemplate Create(NUInt flags)
	{
		HNSTemplate handle;
		NCheck(NSTemplateCreateEx(flags, &handle));
		return handle;
	}

	static HNSTemplate Create(const ::Neurotec::IO::NBuffer & buffer, NUInt flags, NSizeType * pSize)
	{
		HNSTemplate handle;
		NCheck(NSTemplateCreateFromMemoryN(buffer.GetHandle(), flags, pSize, &handle));
		return handle;
	}

	static HNSTemplate Create(const void * pBuffer, NSizeType bufferSize, NUInt flags, NSizeType * pSize)
	{
		HNSTemplate handle;
		NCheck(NSTemplateCreateFromMemory(pBuffer, bufferSize, flags, pSize, &handle));
		return handle;
	}

public:
	static NSizeType CalculateSize(NInt recordCount, NSizeType * arRecordSizes)
	{
		NSizeType value;
		NCheck(NSTemplateCalculateSize(recordCount, arRecordSizes, &value));
		return value;
	}

	static NSizeType Pack(NInt recordCount, const void * * arPRecords, NSizeType * arRecordSizes, void * pBuffer, NSizeType bufferSize)
	{
		NSizeType value;
		NCheck(NSTemplatePack(recordCount, arPRecords, arRecordSizes, pBuffer, bufferSize, &value));
		return value;
	}

	static void Unpack(const void * pBuffer, NSizeType bufferSize,
		NVersion * pVersion, NUInt * pSize, NByte * pHeaderSize,
		NInt * pRecordCount, const void * * arPRecords, NSizeType * arRecordSizes)
	{
		NVersion_ v = 0;
		NCheck(NSTemplateUnpack(pBuffer, bufferSize,
			pVersion ? &v : NULL, pSize, pHeaderSize,
			pRecordCount, arPRecords, arRecordSizes));
		if (pVersion) *pVersion = NVersion(v);
	}

#ifdef N_DEBUG
	using NObject::Check;
#endif

	static void Check(const ::Neurotec::IO::NBuffer & buffer)
	{
		NCheck(NSTemplateCheckN(buffer.GetHandle()));
	}

	static void Check(const void * pBuffer, NSizeType bufferSize)
	{
		NCheck(NSTemplateCheck(pBuffer, bufferSize));
	}

	using NObject::GetSize;

	static NSizeType GetSize(const ::Neurotec::IO::NBuffer & buffer)
	{
		NSizeType value;
		NCheck(NSTemplateGetSizeMemN(buffer.GetHandle(), &value));
		return value;
	}

	static NSizeType GetSize(const void * pBuffer, NSizeType bufferSize)
	{
		NSizeType value;
		NCheck(NSTemplateGetSizeMem(pBuffer, bufferSize, &value));
		return value;
	}

	static NInt GetRecordCount(const ::Neurotec::IO::NBuffer & buffer)
	{
		NInt value;
		NCheck(NSTemplateGetRecordCountMemN(buffer.GetHandle(), &value));
		return value;
	}

	static NInt GetRecordCount(const void * pBuffer, NSizeType bufferSize)
	{
		NInt value;
		NCheck(NSTemplateGetRecordCountMem(pBuffer, bufferSize, &value));
		return value;
	}

	explicit NSTemplate(NUInt flags = 0)
		: NObject(Create(flags), true)
	{
	}

	explicit NSTemplate(const ::Neurotec::IO::NBuffer & buffer, NUInt flags = 0, NSizeType * pSize = NULL)
		: NObject(Create(buffer, flags, pSize), true)
	{
	}

	NSTemplate(const void * pBuffer, NSizeType bufferSize, NUInt flags = 0, NSizeType * pSize = NULL)
		: NObject(Create(pBuffer, bufferSize, flags, pSize), true)
	{
	}

	RecordCollection GetRecords()
	{
		return RecordCollection(*this);
	}

	const RecordCollection GetRecords() const
	{
		return RecordCollection(*this);
	}
};

}}

#endif // !NS_TEMPLATE_HPP_INCLUDED
