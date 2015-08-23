#ifndef AN_TYPE_13_RECORD_HPP_INCLUDED
#define AN_TYPE_13_RECORD_HPP_INCLUDED

#include <Biometrics/Standards/ANFPImageAsciiBinaryRecord.hpp>
namespace Neurotec { namespace Biometrics { namespace Standards
{
#include <Biometrics/Standards/ANType13Record.h>
}}}

namespace Neurotec { namespace Biometrics { namespace Standards
{

#undef AN_TYPE_13_RECORD_FIELD_LEN
#undef AN_TYPE_13_RECORD_FIELD_IDC
#undef AN_TYPE_13_RECORD_FIELD_IMP
#undef AN_TYPE_13_RECORD_FIELD_SRC
#undef AN_TYPE_13_RECORD_FIELD_LCD
#undef AN_TYPE_13_RECORD_FIELD_HLL
#undef AN_TYPE_13_RECORD_FIELD_VLL
#undef AN_TYPE_13_RECORD_FIELD_SLC
#undef AN_TYPE_13_RECORD_FIELD_HPS
#undef AN_TYPE_13_RECORD_FIELD_VPS
#undef AN_TYPE_13_RECORD_FIELD_CGA
#undef AN_TYPE_13_RECORD_FIELD_BPX
#undef AN_TYPE_13_RECORD_FIELD_FGP
#undef AN_TYPE_13_RECORD_FIELD_SPD
#undef AN_TYPE_13_RECORD_FIELD_PPC
#undef AN_TYPE_13_RECORD_FIELD_SHPS
#undef AN_TYPE_13_RECORD_FIELD_SVPS
#undef AN_TYPE_13_RECORD_FIELD_COM
#undef AN_TYPE_13_RECORD_FIELD_LQM

#undef AN_TYPE_13_RECORD_FIELD_UDF_FROM
#undef AN_TYPE_13_RECORD_FIELD_UDF_TO

#undef AN_TYPE_13_RECORD_FIELD_DATA

#undef AN_TYPE_13_RECORD_MAX_SEARCH_POSITION_DESCRIPTOR_COUNT
#undef AN_TYPE_13_RECORD_MAX_QUALITY_METRIC_COUNT

const NInt AN_TYPE_13_RECORD_FIELD_LEN = AN_RECORD_FIELD_LEN;
const NInt AN_TYPE_13_RECORD_FIELD_IDC = AN_RECORD_FIELD_IDC;
const NInt AN_TYPE_13_RECORD_FIELD_IMP = AN_FP_IMAGE_ASCII_BINARY_RECORD_FIELD_IMP;
const NInt AN_TYPE_13_RECORD_FIELD_SRC = AN_ASCII_BINARY_RECORD_FIELD_SRC;
const NInt AN_TYPE_13_RECORD_FIELD_LCD = AN_ASCII_BINARY_RECORD_FIELD_DAT;
const NInt AN_TYPE_13_RECORD_FIELD_HLL = AN_IMAGE_ASCII_BINARY_RECORD_FIELD_HLL;
const NInt AN_TYPE_13_RECORD_FIELD_VLL = AN_IMAGE_ASCII_BINARY_RECORD_FIELD_VLL;
const NInt AN_TYPE_13_RECORD_FIELD_SLC = AN_IMAGE_ASCII_BINARY_RECORD_FIELD_SLC;
const NInt AN_TYPE_13_RECORD_FIELD_HPS = AN_IMAGE_ASCII_BINARY_RECORD_FIELD_HPS;
const NInt AN_TYPE_13_RECORD_FIELD_VPS = AN_IMAGE_ASCII_BINARY_RECORD_FIELD_VPS;
const NInt AN_TYPE_13_RECORD_FIELD_CGA = AN_IMAGE_ASCII_BINARY_RECORD_FIELD_CGA;
const NInt AN_TYPE_13_RECORD_FIELD_BPX = AN_IMAGE_ASCII_BINARY_RECORD_FIELD_BPX;
const NInt AN_TYPE_13_RECORD_FIELD_FGP = AN_FP_IMAGE_ASCII_BINARY_RECORD_FIELD_FGP;
const NInt AN_TYPE_13_RECORD_FIELD_SPD = AN_FP_IMAGE_ASCII_BINARY_RECORD_FIELD_PD;
const NInt AN_TYPE_13_RECORD_FIELD_PPC = AN_FP_IMAGE_ASCII_BINARY_RECORD_FIELD_PPC;
const NInt AN_TYPE_13_RECORD_FIELD_SHPS = AN_IMAGE_ASCII_BINARY_RECORD_FIELD_SHPS;
const NInt AN_TYPE_13_RECORD_FIELD_SVPS = AN_IMAGE_ASCII_BINARY_RECORD_FIELD_SVPS;
const NInt AN_TYPE_13_RECORD_FIELD_COM = AN_IMAGE_ASCII_BINARY_RECORD_FIELD_COM;
const NInt AN_TYPE_13_RECORD_FIELD_LQM = AN_IMAGE_ASCII_BINARY_RECORD_FIELD_IQM;

const NInt AN_TYPE_13_RECORD_FIELD_UDF_FROM = AN_ASCII_BINARY_RECORD_FIELD_UDF_FROM;
const NInt AN_TYPE_13_RECORD_FIELD_UDF_TO = AN_ASCII_BINARY_RECORD_FIELD_UDF_TO;

const NInt AN_TYPE_13_RECORD_FIELD_DATA = AN_RECORD_FIELD_DATA;

const NInt AN_TYPE_13_RECORD_MAX_SEARCH_POSITION_DESCRIPTOR_COUNT = 9;
const NInt AN_TYPE_13_RECORD_MAX_QUALITY_METRIC_COUNT = 4;

class ANType13Record : public ANFPImageAsciiBinaryRecord
{
	N_DECLARE_OBJECT_CLASS(ANType13Record, ANFPImageAsciiBinaryRecord)

public:
	class SearchPositionDescriptorCollection : public ::Neurotec::Collections::NCollectionWithAllOutBase<ANFPositionDescriptor, ANType13Record,
		ANType13RecordGetSearchPositionDescriptorCount, ANType13RecordGetSearchPositionDescriptor, ANType13RecordGetSearchPositionDescriptors>
	{
		SearchPositionDescriptorCollection(const ANType13Record & owner)
		{
			SetOwner(owner);
		}

	public:
#include <Core/NNoDeprecate.h>
		N_DEPRECATED("use NArrayWrapper<ANFPositionDescriptor> GetAll() instead")
		NInt GetAll(ANFPositionDescriptor * arValues, NInt valuesLength) const
		{
			NInt count;
			NCheck(count = ANType13RecordGetSearchPositionDescriptorsEx(this->GetOwnerHandle(), arValues, valuesLength));
			return count;
		}
#include <Core/NReDeprecate.h>

		using ::Neurotec::Collections::NCollectionWithAllOutBase<ANFPositionDescriptor, ANType13Record,
			ANType13RecordGetSearchPositionDescriptorCount, ANType13RecordGetSearchPositionDescriptor, ANType13RecordGetSearchPositionDescriptors>::GetAll;

		void Set(NInt index, const ANFPositionDescriptor & value)
		{
			NCheck(ANType13RecordSetSearchPositionDescriptor(this->GetOwnerHandle(), index, &value));
		}

		NInt Add(const ANFPositionDescriptor & value)
		{
			NInt index;
			NCheck(ANType13RecordAddSearchPositionDescriptorEx(this->GetOwnerHandle(), &value, &index));
			return index;
		}

		void Insert(NInt index, const ANFPositionDescriptor & value)
		{
			NCheck(ANType13RecordInsertSearchPositionDescriptor(this->GetOwnerHandle(), index, &value));
		}

		void RemoveAt(NInt index)
		{
			NCheck(ANType13RecordRemoveSearchPositionDescriptorAt(this->GetOwnerHandle(), index));
		}

		void Clear()
		{
			NCheck(ANType13RecordClearSearchPositionDescriptors(this->GetOwnerHandle()));
		}

		friend class ANType13Record;
	};

public:
	SearchPositionDescriptorCollection GetSearchPositionDescriptors()
	{
		return SearchPositionDescriptorCollection(*this);
	}

	const SearchPositionDescriptorCollection GetSearchPositionDescriptors() const
	{
		return SearchPositionDescriptorCollection(*this);
	}
};

}}}

#endif // !AN_TYPE_13_RECORD_HPP_INCLUDED
