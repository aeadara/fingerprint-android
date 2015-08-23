#ifndef NF_TEMPLATE_HPP_INCLUDED
#define NF_TEMPLATE_HPP_INCLUDED

#include <Biometrics/NFRecord.hpp>
namespace Neurotec { namespace Biometrics
{
#include <Biometrics/NFTemplate.h>
}}

namespace Neurotec { namespace Biometrics
{
#undef NFT_MAX_RECORD_COUNT
#undef NFT_PROCESS_FIRST_RECORD_ONLY

const NInt NFT_MAX_RECORD_COUNT = 255;
const NUInt NFT_PROCESS_FIRST_RECORD_ONLY = 0x00000100;

class NFTemplate : public NObject
{
	N_DECLARE_OBJECT_CLASS(NFTemplate, NObject)

public:
	class RecordCollection : public ::Neurotec::Collections::NCollectionBase<NFRecord, NFTemplate,
		NFTemplateGetRecordCount, NFTemplateGetRecordEx>
	{
		RecordCollection(const NFTemplate & owner)
		{
			SetOwner(owner);
		}

		friend class NFTemplate;
	public:
		NInt GetCapacity() const
		{
			NInt value;
			NCheck(NFTemplateGetRecordCapacity(this->GetOwnerHandle(), &value));
			return value;
		}

		void SetCapacity(NInt value)
		{
			NCheck(NFTemplateSetRecordCapacity(this->GetOwnerHandle(), value));
		}

		void Set(NInt index, const NFRecord & value)
		{
			NCheck(NFTemplateSetRecord(this->GetOwnerHandle(), index, value.GetHandle()));
		}

		NInt Add(const NFRecord & value)
		{
			NInt index;
			NCheck(NFTemplateAddRecordEx(this->GetOwnerHandle(), value.GetHandle(), &index));
			return index;
		}

		void Insert(NInt index, const NFRecord & value)
		{
			NCheck(NFTemplateInsertRecord(this->GetOwnerHandle(), index, value.GetHandle()));
		}

		void RemoveAt(NInt index)
		{
			NCheck(NFTemplateRemoveRecordAt(this->GetOwnerHandle(), index));
		}

		void Clear()
		{
			NCheck(NFTemplateClearRecords(this->GetOwnerHandle()));
		}
	};

private:
	static HNFTemplate Create(bool isPalm, NUInt flags)
	{
		HNFTemplate handle;
		NCheck(NFTemplateCreateEx(isPalm, flags, &handle));
		return handle;
	}

	static HNFTemplate Create(const ::Neurotec::IO::NBuffer & buffer, NUInt flags, NSizeType * pSize)
	{
		HNFTemplate handle;
		NCheck(NFTemplateCreateFromMemoryN(buffer.GetHandle(), flags, pSize, &handle));
		return handle;
	}

	static HNFTemplate Create(const void * pBuffer, NSizeType bufferSize, NUInt flags, NSizeType * pSize)
	{
		HNFTemplate handle;
		NCheck(NFTemplateCreateFromMemory(pBuffer, bufferSize, flags, pSize, &handle));
		return handle;
	}

public:
	static NSizeType CalculateSize(NBool isPalm, NInt recordCount, NSizeType * arRecordSizes)
	{
		NSizeType value;
		NCheck(NFTemplateCalculateSize(isPalm, recordCount, arRecordSizes, &value));
		return value;
	}

	static NSizeType Pack(bool isPalm, NInt recordCount, const void * * arPRecords, NSizeType * arRecordSizes, void * pBuffer, NSizeType bufferSize)
	{
		NSizeType value;
		NCheck(NFTemplatePack(isPalm ? NTrue : NFalse, recordCount, arPRecords, arRecordSizes, pBuffer, bufferSize, &value));
		return value;
	}

	static void Unpack(const void * pBuffer, NSizeType bufferSize, NBool *isPalm,
		NVersion * pVersion, NUInt * pSize, NByte * pHeaderSize,
		NInt * pRecordCount, const void * * arPRecords, NSizeType * arRecordSizes)
	{
		NVersion_ v = 0;
		NCheck(NFTemplateUnpack(pBuffer, bufferSize, isPalm,
			pVersion ? &v : NULL, pSize, pHeaderSize,
			pRecordCount, arPRecords, arRecordSizes));
		if (pVersion) *pVersion = NVersion(v);
	}

#ifdef N_DEBUG
	using NObject::Check;
#endif

	static void Check(const ::Neurotec::IO::NBuffer & buffer)
	{
		NCheck(NFTemplateCheckN(buffer.GetHandle()));
	}

	static void Check(const void * pBuffer, NSizeType bufferSize)
	{
		NCheck(NFTemplateCheck(pBuffer, bufferSize));
	}

	static bool IsPalm(const ::Neurotec::IO::NBuffer & buffer)
	{
		NBool value;
		NCheck(NFTemplateIsPalmMemN(buffer.GetHandle(), &value));
		return value != 0;
	}

	static bool IsPalm(const void * pBuffer, NSizeType bufferSize)
	{
		NBool value;
		NCheck(NFTemplateIsPalmMem(pBuffer, bufferSize, &value));
		return value != 0;
	}

	using NObject::GetSize;

	static NSizeType GetSize(const ::Neurotec::IO::NBuffer & buffer)
	{
		NSizeType value;
		NCheck(NFTemplateGetSizeMemN(buffer.GetHandle(), &value));
		return value;
	}

	static NSizeType GetSize(const void * pBuffer, NSizeType bufferSize)
	{
		NSizeType value;
		NCheck(NFTemplateGetSizeMem(pBuffer, bufferSize, &value));
		return value;
	}

	static NInt GetRecordCount(const ::Neurotec::IO::NBuffer & buffer)
	{
		NInt value;
		NCheck(NFTemplateGetRecordCountMemN(buffer.GetHandle(), &value));
		return value;
	}

	static NInt GetRecordCount(const void * pBuffer, NSizeType bufferSize)
	{
		NInt value;
		NCheck(NFTemplateGetRecordCountMem(pBuffer, bufferSize, &value));
		return value;
	}

	explicit NFTemplate(bool isPalm = false, NUInt flags = 0)
		: NObject(Create(isPalm, flags), true)
	{
	}

	explicit NFTemplate(const ::Neurotec::IO::NBuffer & buffer, NUInt flags = 0, NSizeType * pSize = NULL)
		: NObject(Create(buffer, flags, pSize), true)
	{
	}

	NFTemplate(const void * pBuffer, NSizeType bufferSize, NUInt flags = 0, NSizeType * pSize = NULL)
		: NObject(Create(pBuffer, bufferSize, flags, pSize), true)
	{
	}

	bool IsPalm() const
	{
		NBool value;
		NCheck(NFTemplateIsPalm((HNFTemplate)GetHandle(), &value));
		return value != 0;
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

#endif // !NF_TEMPLATE_HPP_INCLUDED
