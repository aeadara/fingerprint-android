#ifndef NL_TEMPLATE_HPP_INCLUDED
#define NL_TEMPLATE_HPP_INCLUDED

#include <Biometrics/NLRecord.hpp>
namespace Neurotec { namespace Biometrics
{
#include <Biometrics/NLTemplate.h>
}}

namespace Neurotec { namespace Biometrics
{
#undef NLT_MAX_RECORD_COUNT
#undef NLT_PROCESS_FIRST_RECORD_ONLY

const NInt NLT_MAX_RECORD_COUNT = 255;
const NUInt NLT_PROCESS_FIRST_RECORD_ONLY = 0x00000100;

class NLTemplate : public NObject
{
	N_DECLARE_OBJECT_CLASS(NLTemplate, NObject)

public:
	class RecordCollection : public ::Neurotec::Collections::NCollectionBase<NLRecord, NLTemplate,
		NLTemplateGetRecordCount, NLTemplateGetRecordEx>
	{
		RecordCollection(const NLTemplate & owner)
		{
			SetOwner(owner);
		}

		friend class NLTemplate;
	public:
		NInt GetCapacity() const
		{
			NInt value;
			NCheck(NLTemplateGetRecordCapacity(this->GetOwnerHandle(), &value));
			return value;
		}

		void SetCapacity(NInt value)
		{
			NCheck(NLTemplateSetRecordCapacity(this->GetOwnerHandle(), value));
		}

		void Set(NInt index, const NLRecord & value)
		{
			NCheck(NLTemplateSetRecord(this->GetOwnerHandle(), index, value.GetHandle()));
		}

		NInt Add(const NLRecord & value)
		{
			NInt index;
			NCheck(NLTemplateAddRecordEx(this->GetOwnerHandle(), value.GetHandle(), &index));
			return index;
		}

		void Insert(NInt index, const NLRecord & value)
		{
			NCheck(NLTemplateInsertRecord(this->GetOwnerHandle(), index, value.GetHandle()));
		}

		void RemoveAt(NInt index)
		{
			NCheck(NLTemplateRemoveRecordAt(this->GetOwnerHandle(), index));
		}

		void Clear()
		{
			NCheck(NLTemplateClearRecords(this->GetOwnerHandle()));
		}
	};

private:
	static HNLTemplate Create(NUInt flags)
	{
		HNLTemplate handle;
		NCheck(NLTemplateCreateEx(flags, &handle));
		return handle;
	}

	static HNLTemplate Create(const ::Neurotec::IO::NBuffer & buffer, NUInt flags, NSizeType * pSize)
	{
		HNLTemplate handle;
		NCheck(NLTemplateCreateFromMemoryN(buffer.GetHandle(), flags, pSize, &handle));
		return handle;
	}

	static HNLTemplate Create(const void * pBuffer, NSizeType bufferSize, NUInt flags, NSizeType * pSize)
	{
		HNLTemplate handle;
		NCheck(NLTemplateCreateFromMemory(pBuffer, bufferSize, flags, pSize, &handle));
		return handle;
	}

public:
	static NSizeType CalculateSize(NInt recordCount, NSizeType * arRecordSizes)
	{
		NSizeType value;
		NCheck(NLTemplateCalculateSize(recordCount, arRecordSizes, &value));
		return value;
	}

	static NSizeType Pack(NInt recordCount, const void * * arPRecords, NSizeType * arRecordSizes, void * pBuffer, NSizeType bufferSize)
	{
		NSizeType value;
		NCheck(NLTemplatePack(recordCount, arPRecords, arRecordSizes, pBuffer, bufferSize, &value));
		return value;
	}

	static void Unpack(const void * pBuffer, NSizeType bufferSize,
		NVersion * pVersion, NUInt * pSize, NByte * pHeaderSize,
		NInt * pRecordCount, const void * * arPRecords, NSizeType * arRecordSizes)
	{
		NVersion_ v = 0;
		NCheck(NLTemplateUnpack(pBuffer, bufferSize,
			pVersion ? &v : NULL, pSize, pHeaderSize,
			pRecordCount, arPRecords, arRecordSizes));
		if (pVersion) *pVersion = NVersion(v);
	}

#ifdef N_DEBUG
	using NObject::Check;
#endif

	static void Check(const ::Neurotec::IO::NBuffer & buffer)
	{
		NCheck(NLTemplateCheckN(buffer.GetHandle()));
	}

	static void Check(const void * pBuffer, NSizeType bufferSize)
	{
		NCheck(NLTemplateCheck(pBuffer, bufferSize));
	}

	using NObject::GetSize;

	static NSizeType GetSize(const ::Neurotec::IO::NBuffer & buffer)
	{
		NSizeType value;
		NCheck(NLTemplateGetSizeMemN(buffer.GetHandle(), &value));
		return value;
	}

	static NSizeType GetSize(const void * pBuffer, NSizeType bufferSize)
	{
		NSizeType value;
		NCheck(NLTemplateGetSizeMem(pBuffer, bufferSize, &value));
		return value;
	}

	static NInt GetRecordCount(const ::Neurotec::IO::NBuffer & buffer)
	{
		NInt value;
		NCheck(NLTemplateGetRecordCountMemN(buffer.GetHandle(), &value));
		return value;
	}

	static NInt GetRecordCount(const void * pBuffer, NSizeType bufferSize)
	{
		NInt value;
		NCheck(NLTemplateGetRecordCountMem(pBuffer, bufferSize, &value));
		return value;
	}

	explicit NLTemplate(NUInt flags = 0)
		: NObject(Create(flags), true)
	{
	}

	explicit NLTemplate(const ::Neurotec::IO::NBuffer & buffer, NUInt flags = 0, NSizeType * pSize = NULL)
		: NObject(Create(buffer, flags, pSize), true)
	{
	}

	NLTemplate(const void * pBuffer, NSizeType bufferSize, NUInt flags = 0, NSizeType * pSize = NULL)
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

#endif // !NL_TEMPLATE_HPP_INCLUDED
