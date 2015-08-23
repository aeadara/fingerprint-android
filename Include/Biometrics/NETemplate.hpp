#ifndef NE_TEMPLATE_HPP_INCLUDED
#define NE_TEMPLATE_HPP_INCLUDED

#include <Biometrics/NERecord.hpp>
namespace Neurotec { namespace Biometrics
{
#include <Biometrics/NETemplate.h>
}}

namespace Neurotec { namespace Biometrics
{
#undef NET_MAX_RECORD_COUNT
#undef NET_PROCESS_FIRST_RECORD_ONLY

const NInt NET_MAX_RECORD_COUNT = 255;
const NUInt NET_PROCESS_FIRST_RECORD_ONLY = 0x00000100;

class NETemplate : public NObject
{
	N_DECLARE_OBJECT_CLASS(NETemplate, NObject)

public:
	class RecordCollection : public ::Neurotec::Collections::NCollectionBase<NERecord, NETemplate,
		NETemplateGetRecordCount, NETemplateGetRecordEx>
	{
		RecordCollection(const NETemplate & owner)
		{
			SetOwner(owner);
		}

		friend class NETemplate;
	public:
		NInt GetCapacity() const
		{
			NInt value;
			NCheck(NETemplateGetRecordCapacity(this->GetOwnerHandle(), &value));
			return value;
		}

		void SetCapacity(NInt value)
		{
			NCheck(NETemplateSetRecordCapacity(this->GetOwnerHandle(), value));
		}

		void Set(NInt index, const NERecord & value)
		{
			NCheck(NETemplateSetRecord(this->GetOwnerHandle(), index, value.GetHandle()));
		}

		NInt Add(const NERecord & value)
		{
			NInt index;
			NCheck(NETemplateAddRecordEx(this->GetOwnerHandle(), value.GetHandle(), &index));
			return index;
		}

		void Insert(NInt index, const NERecord & value)
		{
			NCheck(NETemplateInsertRecord(this->GetOwnerHandle(), index, value.GetHandle()));
		}

		void RemoveAt(NInt index)
		{
			NCheck(NETemplateRemoveRecordAt(this->GetOwnerHandle(), index));
		}

		void Clear()
		{
			NCheck(NETemplateClearRecords(this->GetOwnerHandle()));
		}
	};

private:
	static HNETemplate Create(NUInt flags)
	{
		HNETemplate handle;
		NCheck(NETemplateCreateEx(flags, &handle));
		return handle;
	}

	static HNETemplate Create(const ::Neurotec::IO::NBuffer & buffer, NUInt flags, NSizeType * pSize)
	{
		HNETemplate handle;
		NCheck(NETemplateCreateFromMemoryN(buffer.GetHandle(), flags, pSize, &handle));
		return handle;
	}

	static HNETemplate Create(const void * pBuffer, NSizeType bufferSize, NUInt flags, NSizeType * pSize)
	{
		HNETemplate handle;
		NCheck(NETemplateCreateFromMemory(pBuffer, bufferSize, flags, pSize, &handle));
		return handle;
	}

public:
	static NSizeType CalculateSize(NInt recordCount, NSizeType * arRecordSizes)
	{
		NSizeType value;
		NCheck(NETemplateCalculateSize(recordCount, arRecordSizes, &value));
		return value;
	}

	static NSizeType Pack(NInt recordCount, const void * * arPRecords, NSizeType * arRecordSizes, void * pBuffer, NSizeType bufferSize)
	{
		NSizeType value;
		NCheck(NETemplatePack(recordCount, arPRecords, arRecordSizes, pBuffer, bufferSize, &value));
		return value;
	}

	static void Unpack(const void * pBuffer, NSizeType bufferSize,
		NVersion * pVersion, NUInt * pSize, NByte * pHeaderSize,
		NInt * pRecordCount, const void * * arPRecords, NSizeType * arRecordSizes)
	{
		NVersion_ v = 0;
		NCheck(NETemplateUnpack(pBuffer, bufferSize,
			pVersion ? &v : NULL, pSize, pHeaderSize,
			pRecordCount, arPRecords, arRecordSizes));
		if (pVersion) *pVersion = NVersion(v);
	}

#ifdef N_DEBUG
	using NObject::Check;
#endif

	static void Check(const ::Neurotec::IO::NBuffer & buffer)
	{
		NCheck(NETemplateCheckN(buffer.GetHandle()));
	}

	static void Check(const void * pBuffer, NSizeType bufferSize)
	{
		NCheck(NETemplateCheck(pBuffer, bufferSize));
	}

	using NObject::GetSize;

	static NSizeType GetSize(const ::Neurotec::IO::NBuffer & buffer)
	{
		NSizeType value;
		NCheck(NETemplateGetSizeMemN(buffer.GetHandle(), &value));
		return value;
	}

	static NSizeType GetSize(const void * pBuffer, NSizeType bufferSize)
	{
		NSizeType value;
		NCheck(NETemplateGetSizeMem(pBuffer, bufferSize, &value));
		return value;
	}

	static NInt GetRecordCount(const ::Neurotec::IO::NBuffer & buffer)
	{
		NInt value;
		NCheck(NETemplateGetRecordCountMemN(buffer.GetHandle(), &value));
		return value;
	}

	static NInt GetRecordCount(const void * pBuffer, NSizeType bufferSize)
	{
		NInt value;
		NCheck(NETemplateGetRecordCountMem(pBuffer, bufferSize, &value));
		return value;
	}

	explicit NETemplate(NUInt flags = 0)
		: NObject(Create(flags), true)
	{
	}

	explicit NETemplate(const ::Neurotec::IO::NBuffer & buffer, NUInt flags = 0, NSizeType * pSize = NULL)
		: NObject(Create(buffer, flags, pSize), true)
	{
	}

	NETemplate(const void * pBuffer, NSizeType bufferSize, NUInt flags = 0, NSizeType * pSize = NULL)
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

#endif // !NE_TEMPLATE_HPP_INCLUDED
