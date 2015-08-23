#ifndef AN_FINGERPRINT_IMAGE_BINARY_RECORD_HPP_INCLUDED
#define AN_FINGERPRINT_IMAGE_BINARY_RECORD_HPP_INCLUDED

#include <Biometrics/Standards/ANImageBinaryRecord.hpp>
#include <Biometrics/Standards/BdifTypes.hpp>
namespace Neurotec { namespace Biometrics { namespace Standards
{
#include <Biometrics/Standards/ANFImageBinaryRecord.h>
}}}

namespace Neurotec { namespace Biometrics { namespace Standards
{

#undef AN_F_IMAGE_BINARY_RECORD_FIELD_IMP
#undef AN_F_IMAGE_BINARY_RECORD_FIELD_FGP
#undef AN_F_IMAGE_BINARY_RECORD_FIELD_CA

#undef AN_F_IMAGE_BINARY_RECORD_MAX_POSITION_COUNT

const NInt AN_F_IMAGE_BINARY_RECORD_FIELD_IMP = 3;
const NInt AN_F_IMAGE_BINARY_RECORD_FIELD_FGP = 4;
const NInt AN_F_IMAGE_BINARY_RECORD_FIELD_CA = 8;

const NInt AN_F_IMAGE_BINARY_RECORD_MAX_POSITION_COUNT = 6;

class ANFImageBinaryRecord : public ANImageBinaryRecord
{
	N_DECLARE_OBJECT_CLASS(ANFImageBinaryRecord, ANImageBinaryRecord)

public:
	class PositionCollection : public ::Neurotec::Collections::NCollectionBase<BdifFPPosition, ANFImageBinaryRecord,
		ANFImageBinaryRecordGetPositionCount, ANFImageBinaryRecordGetPosition>
	{
		PositionCollection(const ANFImageBinaryRecord & owner)
		{
			SetOwner(owner);
		}

		friend class ANFImageBinaryRecord;
	public:
#include <Core/NNoDeprecate.h>
		N_DEPRECATED("use NArrayWrapper<BdifFPPosition> GetAll() instead")
		NInt GetAll(BdifFPPosition * arValues, NInt valuesLength) const
		{
			NInt count;
			NCheck(count = ANFImageBinaryRecordGetPositionsEx(this->GetOwnerHandle(), arValues, valuesLength));
			return count;
		}
#include <Core/NReDeprecate.h>

		NArrayWrapper<BdifFPPosition> GetAll() const
		{
			BdifFPPosition * arValues = NULL;
			NInt valueCount = 0;
			NCheck(ANFImageBinaryRecordGetPositions(this->GetOwnerHandle(), &arValues, &valueCount));
			return NArrayWrapper<BdifFPPosition>(arValues, valueCount);
		}

		void Set(NInt index, BdifFPPosition value)
		{
			NCheck(ANFImageBinaryRecordSetPosition(this->GetOwnerHandle(), index, value));
		}

		NInt Add(BdifFPPosition value)
		{
			NInt index;
			NCheck(ANFImageBinaryRecordAddPositionEx(this->GetOwnerHandle(), value, &index));
			return index;
		}

		void Insert(NInt index, BdifFPPosition value)
		{
			NCheck(ANFImageBinaryRecordInsertPosition(this->GetOwnerHandle(), index, value));
		}

		void RemoveAt(NInt index)
		{
			NCheck(ANFImageBinaryRecordRemovePositionAt(this->GetOwnerHandle(), index));
		}

		void Clear()
		{
			NCheck(ANFImageBinaryRecordClearPositions(this->GetOwnerHandle()));
		}
	};

public:
	BdifFPImpressionType GetImpressionType() const
	{
		BdifFPImpressionType value;
		NCheck(ANFImageBinaryRecordGetImpressionType(GetHandle(), &value));
		return value;
	}

	void SetImpressionType(BdifFPImpressionType value)
	{
		NCheck(ANFImageBinaryRecordSetImpressionType(GetHandle(), value));
	}

	PositionCollection GetPositions()
	{
		return PositionCollection(*this);
	}

	const PositionCollection GetPositions() const
	{
		return PositionCollection(*this);
	}
};

}}}

#endif // !AN_FINGERPRINT_IMAGE_BINARY_RECORD_HPP_INCLUDED
