#ifndef AN_FP_IMAGE_ASCII_BINARY_RECORD_HPP_INCLUDED
#define AN_FP_IMAGE_ASCII_BINARY_RECORD_HPP_INCLUDED

#include <Biometrics/Standards/ANImageAsciiBinaryRecord.hpp>
namespace Neurotec { namespace Biometrics { namespace Standards
{
#include <Biometrics/Standards/ANFPImageAsciiBinaryRecord.h>
}}}

N_DEFINE_ENUM_TYPE_TRAITS(Neurotec::Biometrics::Standards, ANFMajorCase)

namespace Neurotec { namespace Biometrics { namespace Standards
{

#undef AN_FP_IMAGE_ASCII_BINARY_RECORD_FIELD_IMP
#undef AN_FP_IMAGE_ASCII_BINARY_RECORD_FIELD_FGP
#undef AN_FP_IMAGE_ASCII_BINARY_RECORD_FIELD_PD
#undef AN_FP_IMAGE_ASCII_BINARY_RECORD_FIELD_PPC

#undef AN_FP_IMAGE_ASCII_BINARY_RECORD_MAX_POSITION_COUNT
#undef AN_FP_IMAGE_ASCII_BINARY_RECORD_MAX_PRINT_POSITION_COUNT

const NInt AN_FP_IMAGE_ASCII_BINARY_RECORD_FIELD_IMP = 3;
const NInt AN_FP_IMAGE_ASCII_BINARY_RECORD_FIELD_FGP = 13;
const NInt AN_FP_IMAGE_ASCII_BINARY_RECORD_FIELD_PD = 14;
const NInt AN_FP_IMAGE_ASCII_BINARY_RECORD_FIELD_PPC = 15;

const NInt AN_FP_IMAGE_ASCII_BINARY_RECORD_MAX_POSITION_COUNT = 6;
const NInt AN_FP_IMAGE_ASCII_BINARY_RECORD_MAX_PRINT_POSITION_COUNT = 12;

class ANFPositionDescriptor : public ANFPositionDescriptor_
{
	N_DECLARE_EQUATABLE_STRUCT_CLASS(ANFPositionDescriptor)

public:
	ANFPositionDescriptor(BdifFPPosition position, ANFMajorCase portion)
	{
		Position = position;
		Portion = portion;
	}
};

class ANFPrintPosition : public ANFPrintPosition_
{
	N_DECLARE_EQUATABLE_STRUCT_CLASS(ANFPrintPosition)

public:
	ANFPrintPosition(ANFMajorCase fingerView, ANFMajorCase segment, NInt left, NInt right, NInt top, NInt bottom)
	{
		FingerView = fingerView;
		Segment = segment;
		Left = left;
		Right = right;
		Top = top;
		Bottom = bottom;
	}
};

class ANFPQualityMetric : public ANFPQualityMetric_
{
	N_DECLARE_EQUATABLE_STRUCT_CLASS(ANFPQualityMetric)

public:
	ANFPQualityMetric(BdifFPPosition position, NByte score, NUShort algorithmVendorId, NUShort algorithmProductId)
	{
		Position = position;
		Score = score;
		AlgorithmVendorId = algorithmVendorId;
		AlgorithmProductId = algorithmProductId;
	}
};

}}}

N_DEFINE_STRUCT_TYPE_TRAITS(Neurotec::Biometrics::Standards, ANFPositionDescriptor)
N_DEFINE_STRUCT_TYPE_TRAITS(Neurotec::Biometrics::Standards, ANFPrintPosition)
N_DEFINE_STRUCT_TYPE_TRAITS(Neurotec::Biometrics::Standards, ANFPQualityMetric)

namespace Neurotec { namespace Biometrics { namespace Standards
{

class ANFPImageAsciiBinaryRecord : public ANImageAsciiBinaryRecord
{
	N_DECLARE_OBJECT_CLASS(ANFPImageAsciiBinaryRecord, ANImageAsciiBinaryRecord)

public:
	class PositionCollection : public ::Neurotec::Collections::NCollectionWithAllOutBase<BdifFPPosition, ANFPImageAsciiBinaryRecord,
		ANFPImageAsciiBinaryRecordGetPositionCount, ANFPImageAsciiBinaryRecordGetPosition, ANFPImageAsciiBinaryRecordGetPositions>
	{
		PositionCollection(const ANFPImageAsciiBinaryRecord & owner)
		{
			SetOwner(owner);
		}

		friend class ANFPImageAsciiBinaryRecord;
	public:
#include <Core/NNoDeprecate.h>
		N_DEPRECATED("use NArrayWrapper<BdifFPPosition> GetAll() instead")
		NInt GetAll(BdifFPPosition * arValues, NInt valuesLength) const
		{
			NInt count;
			NCheck(count = ANFPImageAsciiBinaryRecordGetPositionsEx(this->GetOwnerHandle(), arValues, valuesLength));
			return count;
		}
#include <Core/NReDeprecate.h>

		using ::Neurotec::Collections::NCollectionWithAllOutBase<BdifFPPosition, ANFPImageAsciiBinaryRecord,
			ANFPImageAsciiBinaryRecordGetPositionCount, ANFPImageAsciiBinaryRecordGetPosition, ANFPImageAsciiBinaryRecordGetPositions>::GetAll;

		void Set(NInt index, BdifFPPosition value)
		{
			NCheck(ANFPImageAsciiBinaryRecordSetPosition(this->GetOwnerHandle(), index, value));
		}

		NInt Add(BdifFPPosition value)
		{
			NInt index;
			NCheck(ANFPImageAsciiBinaryRecordAddPositionEx(this->GetOwnerHandle(), value, &index));
			return index;
		}

		void Insert(NInt index, BdifFPPosition value)
		{
			NCheck(ANFPImageAsciiBinaryRecordInsertPosition(this->GetOwnerHandle(), index, value));
		}

		void RemoveAt(NInt index)
		{
			NCheck(ANFPImageAsciiBinaryRecordRemovePositionAt(this->GetOwnerHandle(), index));
		}

		void Clear()
		{
			NCheck(ANFPImageAsciiBinaryRecordClearPositions(this->GetOwnerHandle()));
		}
	};

	class PrintPositionCollection : public ::Neurotec::Collections::NCollectionWithAllOutBase<ANFPrintPosition, ANFPImageAsciiBinaryRecord,
		ANFPImageAsciiBinaryRecordGetPrintPositionCount, ANFPImageAsciiBinaryRecordGetPrintPosition, ANFPImageAsciiBinaryRecordGetPrintPositions>
	{
		PrintPositionCollection(const ANFPImageAsciiBinaryRecord & owner)
		{
			SetOwner(owner);
		}

		friend class ANFPImageAsciiBinaryRecord;
	public:
#include <Core/NNoDeprecate.h>
		N_DEPRECATED("use NArrayWrapper<ANFPrintPosition> GetAll() instead")
		NInt GetAll(ANFPrintPosition * arValues, NInt valuesLength) const
		{
			NInt count;
			NCheck(count = ANFPImageAsciiBinaryRecordGetPrintPositionsEx(this->GetOwnerHandle(), arValues, valuesLength));
			return count;
		}
#include <Core/NReDeprecate.h>

		using ::Neurotec::Collections::NCollectionWithAllOutBase<ANFPrintPosition, ANFPImageAsciiBinaryRecord,
			ANFPImageAsciiBinaryRecordGetPrintPositionCount, ANFPImageAsciiBinaryRecordGetPrintPosition, ANFPImageAsciiBinaryRecordGetPrintPositions>::GetAll;

		void Set(NInt index, const ANFPrintPosition & value)
		{
			NCheck(ANFPImageAsciiBinaryRecordSetPrintPosition(this->GetOwnerHandle(), index, &value));
		}

		NInt Add(const ANFPrintPosition & value)
		{
			NInt index;
			NCheck(ANFPImageAsciiBinaryRecordAddPrintPositionEx(this->GetOwnerHandle(), &value, &index));
			return index;
		}

		void Insert(NInt index, const ANFPrintPosition & value)
		{
			NCheck(ANFPImageAsciiBinaryRecordInsertPrintPosition(this->GetOwnerHandle(), index, &value));
		}

		void RemoveAt(NInt index)
		{
			NCheck(ANFPImageAsciiBinaryRecordRemovePrintPositionAt(this->GetOwnerHandle(), index));
		}

		void Clear()
		{
			NCheck(ANFPImageAsciiBinaryRecordClearPrintPositions(this->GetOwnerHandle()));
		}
	};

	class QualityMetricCollection : public ::Neurotec::Collections::NCollectionWithAllOutBase<ANFPQualityMetric, ANFPImageAsciiBinaryRecord,
		ANFPImageAsciiBinaryRecordGetQualityMetricCount, ANFPImageAsciiBinaryRecordGetQualityMetric, ANFPImageAsciiBinaryRecordGetQualityMetrics>
	{
		QualityMetricCollection(const ANFPImageAsciiBinaryRecord & owner)
		{
			SetOwner(owner);
		}

		friend class ANFPImageAsciiBinaryRecord;
	public:
#include <Core/NNoDeprecate.h>
		N_DEPRECATED("use NArrayWrapper<ANFPQualityMetric> GetAll() instead")
		NInt GetAll(ANFPQualityMetric * arValues, NInt valuesLength) const
		{
			NInt count;
			NCheck(count = ANFPImageAsciiBinaryRecordGetQualityMetricsEx(this->GetOwnerHandle(), arValues, valuesLength));
			return count;
		}
#include <Core/NReDeprecate.h>

		using ::Neurotec::Collections::NCollectionWithAllOutBase<ANFPQualityMetric, ANFPImageAsciiBinaryRecord,
			ANFPImageAsciiBinaryRecordGetQualityMetricCount, ANFPImageAsciiBinaryRecordGetQualityMetric, ANFPImageAsciiBinaryRecordGetQualityMetrics>::GetAll;

		void Set(NInt index, const ANFPQualityMetric & value)
		{
			NCheck(ANFPImageAsciiBinaryRecordSetQualityMetric(this->GetOwnerHandle(), index, &value));
		}

		NInt Add(const ANFPQualityMetric & value)
		{
			NInt index;
			NCheck(ANFPImageAsciiBinaryRecordAddQualityMetricEx(this->GetOwnerHandle(), &value, &index));
			return index;
		}

		void Insert(NInt index, const ANFPQualityMetric & value)
		{
			NCheck(ANFPImageAsciiBinaryRecordInsertQualityMetric(this->GetOwnerHandle(), index, &value));
		}

		void RemoveAt(NInt index)
		{
			NCheck(ANFPImageAsciiBinaryRecordRemoveQualityMetricAt(this->GetOwnerHandle(), index));
		}

		void Clear()
		{
			NCheck(ANFPImageAsciiBinaryRecordClearQualityMetrics(this->GetOwnerHandle()));
		}
	};

public:
	static NType ANFMajorCaseNativeTypeOf()
	{
		return NObject::GetObject<NType>(N_TYPE_OF(ANFMajorCase), true);
	}

	BdifFPImpressionType GetImpressionType() const
	{
		BdifFPImpressionType value;
		NCheck(ANFPImageAsciiBinaryRecordGetImpressionType(GetHandle(), &value));
		return value;
	}

	void SetImpressionType(BdifFPImpressionType value)
	{
		NCheck(ANFPImageAsciiBinaryRecordSetImpressionType(GetHandle(), value));
	}

	PositionCollection GetPositions()
	{
		return PositionCollection(*this);
	}

	const PositionCollection GetPositions() const
	{
		return PositionCollection(*this);
	}

	PrintPositionCollection GetPrintPositions()
	{
		return PrintPositionCollection(*this);
	}

	const PrintPositionCollection GetPrintPositions() const
	{
		return PrintPositionCollection(*this);
	}

	QualityMetricCollection GetQualityMetrics()
	{
		return QualityMetricCollection(*this);
	}

	const QualityMetricCollection GetQualityMetrics() const
	{
		return QualityMetricCollection(*this);
	}
};

}}}

#endif // !AN_FP_IMAGE_ASCII_BINARY_RECORD_HPP_INCLUDED
