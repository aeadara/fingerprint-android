#ifndef AN_TYPE_14_RECORD_HPP_INCLUDED
#define AN_TYPE_14_RECORD_HPP_INCLUDED

#include <Biometrics/Standards/ANFPImageAsciiBinaryRecord.hpp>
#include <Geometry/NGeometry.hpp>
namespace Neurotec { namespace Biometrics { namespace Standards
{
using ::Neurotec::Geometry::NPoint_;
#include <Biometrics/Standards/ANType14Record.h>
}}}

N_DEFINE_ENUM_TYPE_TRAITS(Neurotec::Biometrics::Standards, ANFAmputationType)

namespace Neurotec { namespace Biometrics { namespace Standards
{

#undef AN_TYPE_14_RECORD_FIELD_LEN
#undef AN_TYPE_14_RECORD_FIELD_IDC
#undef AN_TYPE_14_RECORD_FIELD_IMP
#undef AN_TYPE_14_RECORD_FIELD_SRC
#undef AN_TYPE_14_RECORD_FIELD_FCD
#undef AN_TYPE_14_RECORD_FIELD_HLL
#undef AN_TYPE_14_RECORD_FIELD_VLL
#undef AN_TYPE_14_RECORD_FIELD_SLC
#undef AN_TYPE_14_RECORD_FIELD_HPS
#undef AN_TYPE_14_RECORD_FIELD_VPS
#undef AN_TYPE_14_RECORD_FIELD_CGA
#undef AN_TYPE_14_RECORD_FIELD_BPX
#undef AN_TYPE_14_RECORD_FIELD_FGP
#undef AN_TYPE_14_RECORD_FIELD_PPD
#undef AN_TYPE_14_RECORD_FIELD_PPC
#undef AN_TYPE_14_RECORD_FIELD_SHPS
#undef AN_TYPE_14_RECORD_FIELD_SVPS

#undef AN_TYPE_14_RECORD_FIELD_AMP

#undef AN_TYPE_14_RECORD_FIELD_COM

#undef AN_TYPE_14_RECORD_FIELD_SEG
#undef AN_TYPE_14_RECORD_FIELD_NQM
#undef AN_TYPE_14_RECORD_FIELD_SQM

#undef AN_TYPE_14_RECORD_FIELD_FQM

#undef AN_TYPE_14_RECORD_FIELD_ASEG

#undef AN_TYPE_14_RECORD_FIELD_DMM

#undef AN_TYPE_14_RECORD_FIELD_UDF_FROM
#undef AN_TYPE_14_RECORD_FIELD_UDF_TO

#undef AN_TYPE_14_RECORD_FIELD_DATA

#undef AN_TYPE_14_RECORD_MAX_AMPUTATION_COUNT
#undef AN_TYPE_14_RECORD_MAX_NIST_QUALITY_METRIC_COUNT
#undef AN_TYPE_14_RECORD_MAX_ALTERNATE_SEGMENT_COUNT

#undef AN_TYPE_14_RECORD_MIN_ALTERNATE_SEGMENT_VERTEX_COUNT
#undef AN_TYPE_14_RECORD_MAX_ALTERNATE_SEGMENT_VERTEX_COUNT

#undef AN_TYPE_14_RECORD_NIST_QUALITY_METRIC_SCORE_EXCELLENT
#undef AN_TYPE_14_RECORD_NIST_QUALITY_METRIC_SCORE_VERY_GOOD
#undef AN_TYPE_14_RECORD_NIST_QUALITY_METRIC_SCORE_GOOD
#undef AN_TYPE_14_RECORD_NIST_QUALITY_METRIC_SCORE_FAIR
#undef AN_TYPE_14_RECORD_NIST_QUALITY_METRIC_SCORE_POOR
#undef AN_TYPE_14_RECORD_NIST_QUALITY_METRIC_SCORE_NOT_AVAILABLE
#undef AN_TYPE_14_RECORD_NIST_QUALITY_METRIC_SCORE_FAILED

const NInt AN_TYPE_14_RECORD_FIELD_LEN = AN_RECORD_FIELD_LEN;
const NInt AN_TYPE_14_RECORD_FIELD_IDC = AN_RECORD_FIELD_IDC;
const NInt AN_TYPE_14_RECORD_FIELD_IMP = AN_FP_IMAGE_ASCII_BINARY_RECORD_FIELD_IMP;
const NInt AN_TYPE_14_RECORD_FIELD_SRC = AN_ASCII_BINARY_RECORD_FIELD_SRC;
const NInt AN_TYPE_14_RECORD_FIELD_FCD = AN_ASCII_BINARY_RECORD_FIELD_DAT;
const NInt AN_TYPE_14_RECORD_FIELD_HLL = AN_IMAGE_ASCII_BINARY_RECORD_FIELD_HLL;
const NInt AN_TYPE_14_RECORD_FIELD_VLL = AN_IMAGE_ASCII_BINARY_RECORD_FIELD_VLL;
const NInt AN_TYPE_14_RECORD_FIELD_SLC = AN_IMAGE_ASCII_BINARY_RECORD_FIELD_SLC;
const NInt AN_TYPE_14_RECORD_FIELD_HPS = AN_IMAGE_ASCII_BINARY_RECORD_FIELD_HPS;
const NInt AN_TYPE_14_RECORD_FIELD_VPS = AN_IMAGE_ASCII_BINARY_RECORD_FIELD_VPS;
const NInt AN_TYPE_14_RECORD_FIELD_CGA = AN_IMAGE_ASCII_BINARY_RECORD_FIELD_CGA;
const NInt AN_TYPE_14_RECORD_FIELD_BPX = AN_IMAGE_ASCII_BINARY_RECORD_FIELD_BPX;
const NInt AN_TYPE_14_RECORD_FIELD_FGP = AN_FP_IMAGE_ASCII_BINARY_RECORD_FIELD_FGP;
const NInt AN_TYPE_14_RECORD_FIELD_PPD = AN_FP_IMAGE_ASCII_BINARY_RECORD_FIELD_PD;
const NInt AN_TYPE_14_RECORD_FIELD_PPC = AN_FP_IMAGE_ASCII_BINARY_RECORD_FIELD_PPC;
const NInt AN_TYPE_14_RECORD_FIELD_SHPS = AN_IMAGE_ASCII_BINARY_RECORD_FIELD_SHPS;
const NInt AN_TYPE_14_RECORD_FIELD_SVPS = AN_IMAGE_ASCII_BINARY_RECORD_FIELD_SVPS;

const NInt AN_TYPE_14_RECORD_FIELD_AMP = 18;

const NInt AN_TYPE_14_RECORD_FIELD_COM = AN_IMAGE_ASCII_BINARY_RECORD_FIELD_COM;

const NInt AN_TYPE_14_RECORD_FIELD_SEG = 21;
const NInt AN_TYPE_14_RECORD_FIELD_NQM = 22;
const NInt AN_TYPE_14_RECORD_FIELD_SQM = 23;

const NInt AN_TYPE_14_RECORD_FIELD_FQM = AN_IMAGE_ASCII_BINARY_RECORD_FIELD_IQM;

const NInt AN_TYPE_14_RECORD_FIELD_ASEG = 25;

const NInt AN_TYPE_14_RECORD_FIELD_DMM = AN_IMAGE_ASCII_BINARY_RECORD_FIELD_DMM;

const NInt AN_TYPE_14_RECORD_FIELD_UDF_FROM = AN_ASCII_BINARY_RECORD_FIELD_UDF_FROM;
const NInt AN_TYPE_14_RECORD_FIELD_UDF_TO = AN_ASCII_BINARY_RECORD_FIELD_UDF_TO;

const NInt AN_TYPE_14_RECORD_FIELD_DATA = AN_RECORD_FIELD_DATA;

const NInt AN_TYPE_14_RECORD_MAX_AMPUTATION_COUNT = 4;
const NInt AN_TYPE_14_RECORD_MAX_NIST_QUALITY_METRIC_COUNT = 4;
const NInt AN_TYPE_14_RECORD_MAX_ALTERNATE_SEGMENT_COUNT = 4;

const NInt AN_TYPE_14_RECORD_MIN_ALTERNATE_SEGMENT_VERTEX_COUNT = 3;
const NInt AN_TYPE_14_RECORD_MAX_ALTERNATE_SEGMENT_VERTEX_COUNT = 99;

const NByte AN_TYPE_14_RECORD_NIST_QUALITY_METRIC_SCORE_EXCELLENT = 1;
const NByte AN_TYPE_14_RECORD_NIST_QUALITY_METRIC_SCORE_VERY_GOOD = 2;
const NByte AN_TYPE_14_RECORD_NIST_QUALITY_METRIC_SCORE_GOOD = 3;
const NByte AN_TYPE_14_RECORD_NIST_QUALITY_METRIC_SCORE_FAIR = 4;
const NByte AN_TYPE_14_RECORD_NIST_QUALITY_METRIC_SCORE_POOR = 5;
const NByte AN_TYPE_14_RECORD_NIST_QUALITY_METRIC_SCORE_NOT_AVAILABLE = 254;
const NByte AN_TYPE_14_RECORD_NIST_QUALITY_METRIC_SCORE_FAILED = 255;

class ANFAmputation : public ANFAmputation_
{
	N_DECLARE_STRUCT_CLASS(ANFAmputation)

public:
	ANFAmputation(BdifFPPosition position, ANFAmputationType type)
	{
		Position = position;
		Type = type;
	}
};

class ANFSegment : public ANFSegment_
{
	N_DECLARE_EQUATABLE_STRUCT_CLASS(ANFSegment)

public:
	ANFSegment(BdifFPPosition position, NInt left, NInt right, NInt top, NInt bottom)
	{
		Position = position;
		Left = left;
		Right = right;
		Top = top;
		Bottom = bottom;
	}
};

class ANNistQualityMetric : public ANNistQualityMetric_
{
	N_DECLARE_EQUATABLE_STRUCT_CLASS(ANNistQualityMetric)

public:
	ANNistQualityMetric(BdifFPPosition position, NByte score)
	{
		Position = position;
		Score = score;
	}
};

class ANFAlternateSegment : public ANFAlternateSegment_
{
	N_DECLARE_STRUCT_CLASS(ANFAlternateSegment)

public:
	ANFAlternateSegment(BdifFPPosition position)
	{
		Position = position;
	}
};

}}}

N_DEFINE_STRUCT_TYPE_TRAITS(Neurotec::Biometrics::Standards, ANFAmputation)
N_DEFINE_STRUCT_TYPE_TRAITS(Neurotec::Biometrics::Standards, ANFSegment)
N_DEFINE_STRUCT_TYPE_TRAITS(Neurotec::Biometrics::Standards, ANNistQualityMetric)
N_DEFINE_STRUCT_TYPE_TRAITS(Neurotec::Biometrics::Standards, ANFAlternateSegment)

namespace Neurotec { namespace Biometrics { namespace Standards
{

class ANType14Record : public ANFPImageAsciiBinaryRecord
{
	N_DECLARE_OBJECT_CLASS(ANType14Record, ANFPImageAsciiBinaryRecord)

public:
	class AmputationCollection : public ::Neurotec::Collections::NCollectionWithAllOutBase<ANFAmputation, ANType14Record,
		ANType14RecordGetAmputationCount, ANType14RecordGetAmputation, ANType14RecordGetAmputations>
	{
		AmputationCollection(const ANType14Record & owner)
		{
			SetOwner(owner);
		}

		friend class ANType14Record;
	public:
#include <Core/NNoDeprecate.h>
		N_DEPRECATED("use NArrayWrapper<ANFAmputation> GetAll() instead")
		NInt GetAll(ANFAmputation * arValues, NInt valuesLength) const
		{
			NInt count;
			NCheck(count = ANType14RecordGetAmputationsEx(this->GetOwnerHandle(), arValues, valuesLength));
			return count;
		}
#include <Core/NReDeprecate.h>

		using ::Neurotec::Collections::NCollectionWithAllOutBase<ANFAmputation, ANType14Record,
			ANType14RecordGetAmputationCount, ANType14RecordGetAmputation, ANType14RecordGetAmputations>::GetAll;

		void Set(NInt index, const ANFAmputation & value)
		{
			NCheck(ANType14RecordSetAmputation(this->GetOwnerHandle(), index, &value));
		}

		NInt Add(const ANFAmputation & value)
		{
			NInt index;
			NCheck(ANType14RecordAddAmputationEx(this->GetOwnerHandle(), &value, &index));
			return index;
		}

		void Insert(NInt index, const ANFAmputation & value)
		{
			NCheck(ANType14RecordInsertAmputation(this->GetOwnerHandle(), index, &value));
		}

		void RemoveAt(NInt index)
		{
			NCheck(ANType14RecordRemoveAmputationAt(this->GetOwnerHandle(), index));
		}

		void Clear()
		{
			NCheck(ANType14RecordClearAmputations(this->GetOwnerHandle()));
		}
	};

	class SegmentCollection : public ::Neurotec::Collections::NCollectionWithAllOutBase<ANFSegment, ANType14Record,
		ANType14RecordGetSegmentCount, ANType14RecordGetSegment, ANType14RecordGetSegments>
	{
		SegmentCollection(const ANType14Record & owner)
		{
			SetOwner(owner);
		}

		friend class ANType14Record;
	public:
#include <Core/NNoDeprecate.h>
		N_DEPRECATED("use NArrayWrapper<ANFSegment> GetAll() instead")
		NInt GetAll(ANFSegment * arValues, NInt valuesLength) const
		{
			NInt count;
			NCheck(count = ANType14RecordGetSegmentsEx(this->GetOwnerHandle(), arValues, valuesLength));
			return count;
		}
#include <Core/NReDeprecate.h>

		using ::Neurotec::Collections::NCollectionWithAllOutBase<ANFSegment, ANType14Record,
			ANType14RecordGetSegmentCount, ANType14RecordGetSegment, ANType14RecordGetSegments>::GetAll;

		void Set(NInt index, const ANFSegment & value)
		{
			NCheck(ANType14RecordSetSegment(this->GetOwnerHandle(), index, &value));
		}

		NInt Add(const ANFSegment & value)
		{
			NInt index;
			NCheck(ANType14RecordAddSegmentEx(this->GetOwnerHandle(), &value, &index));
			return index;
		}

		void Insert(NInt index, const ANFSegment & value)
		{
			NCheck(ANType14RecordInsertSegment(this->GetOwnerHandle(), index, &value));
		}

		void RemoveAt(NInt index)
		{
			NCheck(ANType14RecordRemoveSegmentAt(this->GetOwnerHandle(), index));
		}

		void Clear()
		{
			NCheck(ANType14RecordClearSegments(this->GetOwnerHandle()));
		}
	};

	class NistQualityMetricCollection : public ::Neurotec::Collections::NCollectionWithAllOutBase<ANNistQualityMetric, ANType14Record,
		ANType14RecordGetNistQualityMetricCount, ANType14RecordGetNistQualityMetric, ANType14RecordGetNistQualityMetrics>
	{
		NistQualityMetricCollection(const ANType14Record & owner)
		{
			SetOwner(owner);
		}

		friend class ANType14Record;
	public:
#include <Core/NNoDeprecate.h>
		N_DEPRECATED("use NArrayWrapper<ANNistQualityMetric> GetAll() instead")
		NInt GetAll(ANNistQualityMetric * arValues, NInt valuesLength) const
		{
			NInt count;
			NCheck(count = ANType14RecordGetNistQualityMetricsEx(this->GetOwnerHandle(), arValues, valuesLength));
			return count;
		}
#include <Core/NReDeprecate.h>

		using ::Neurotec::Collections::NCollectionWithAllOutBase<ANNistQualityMetric, ANType14Record,
			ANType14RecordGetNistQualityMetricCount, ANType14RecordGetNistQualityMetric, ANType14RecordGetNistQualityMetrics>::GetAll;

		void Set(NInt index, const ANNistQualityMetric & value)
		{
			NCheck(ANType14RecordSetNistQualityMetric(this->GetOwnerHandle(), index, &value));
		}

		NInt Add(const ANNistQualityMetric & value)
		{
			NInt index;
			NCheck(ANType14RecordAddNistQualityMetricEx(this->GetOwnerHandle(), &value, &index));
			return index;
		}

		void Insert(NInt index, const ANNistQualityMetric & value)
		{
			NCheck(ANType14RecordInsertNistQualityMetric(this->GetOwnerHandle(), index, &value));
		}

		void RemoveAt(NInt index)
		{
			NCheck(ANType14RecordRemoveNistQualityMetricAt(this->GetOwnerHandle(), index));
		}

		void Clear()
		{
			NCheck(ANType14RecordClearNistQualityMetrics(this->GetOwnerHandle()));
		}
	};

	class SegmentationQualityMetricCollection : public ::Neurotec::Collections::NCollectionWithAllOutBase<ANFPQualityMetric, ANType14Record,
		ANType14RecordGetSegmentationQualityMetricCount, ANType14RecordGetSegmentationQualityMetric, ANType14RecordGetSegmentationQualityMetrics>
	{
		SegmentationQualityMetricCollection(const ANType14Record & owner)
		{
			SetOwner(owner);
		}

		friend class ANType14Record;
	public:
#include <Core/NNoDeprecate.h>
		N_DEPRECATED("use NArrayWrapper<ANFPQualityMetric> GetAll() instead")
		NInt GetAll(ANFPQualityMetric * arValues, NInt valuesLength) const
		{
			NInt count;
			NCheck(count = ANType14RecordGetSegmentationQualityMetricsEx(this->GetOwnerHandle(), arValues, valuesLength));
			return count;
		}
#include <Core/NReDeprecate.h>

		using ::Neurotec::Collections::NCollectionWithAllOutBase<ANFPQualityMetric, ANType14Record,
			ANType14RecordGetSegmentationQualityMetricCount, ANType14RecordGetSegmentationQualityMetric, ANType14RecordGetSegmentationQualityMetrics>::GetAll;

		void Set(NInt index, const ANFPQualityMetric & value)
		{
			NCheck(ANType14RecordSetSegmentationQualityMetric(this->GetOwnerHandle(), index, &value));
		}

		NInt Add(const ANFPQualityMetric & value)
		{
			NInt index;
			NCheck(ANType14RecordAddSegmentationQualityMetricEx(this->GetOwnerHandle(), &value, &index));
			return index;
		}

		void Insert(NInt index, const ANFPQualityMetric & value)
		{
			NCheck(ANType14RecordInsertSegmentationQualityMetric(this->GetOwnerHandle(), index, &value));
		}

		void RemoveAt(NInt index)
		{
			NCheck(ANType14RecordRemoveSegmentationQualityMetricAt(this->GetOwnerHandle(), index));
		}

		void Clear()
		{
			NCheck(ANType14RecordClearSegmentationQualityMetrics(this->GetOwnerHandle()));
		}
	};

	class AlternateSegmentCollection : public ::Neurotec::Collections::NCollectionWithAllOutBase<ANFAlternateSegment, ANType14Record,
		ANType14RecordGetAlternateSegmentCount, ANType14RecordGetAlternateSegment, ANType14RecordGetAlternateSegments>
	{
		AlternateSegmentCollection(const ANType14Record & owner)
		{
			SetOwner(owner);
		}

		friend class ANType14Record;
	public:
#include <Core/NNoDeprecate.h>
		N_DEPRECATED("use NArrayWrapper<ANFAlternateSegment> GetAll() instead")
		NInt GetAll(ANFAlternateSegment * arValues, NInt valuesLength) const
		{
			NInt count;
			NCheck(count = ANType14RecordGetAlternateSegmentsEx(this->GetOwnerHandle(), arValues, valuesLength));
			return count;
		}
#include <Core/NReDeprecate.h>

		using ::Neurotec::Collections::NCollectionWithAllOutBase<ANFAlternateSegment, ANType14Record,
			ANType14RecordGetAlternateSegmentCount, ANType14RecordGetAlternateSegment, ANType14RecordGetAlternateSegments>::GetAll;

		void Set(NInt index, const ANFAlternateSegment & value)
		{
			NCheck(ANType14RecordSetAlternateSegment(this->GetOwnerHandle(), index, &value));
		}

		NInt Add(const ANFAlternateSegment & value)
		{
			NInt index;
			NCheck(ANType14RecordAddAlternateSegmentEx(this->GetOwnerHandle(), &value, &index));
			return index;
		}

		void Insert(NInt index, const ANFAlternateSegment & value)
		{
			NCheck(ANType14RecordInsertAlternateSegment(this->GetOwnerHandle(), index, &value));
		}

		void RemoveAt(NInt index)
		{
			NCheck(ANType14RecordRemoveAlternateSegmentAt(this->GetOwnerHandle(), index));
		}

		void Clear()
		{
			NCheck(ANType14RecordClearAlternateSegments(this->GetOwnerHandle()));
		}
	};

	class AlternateSegmentVerticesCollection : public ::Neurotec::NObjectPartBase<ANType14Record>
	{
		AlternateSegmentVerticesCollection(const ANType14Record & owner)
		{
			SetOwner(owner);
		}

		friend class ANType14Record;
	public:
		NInt GetCount(NInt baseIndex) const
		{
			NInt value;
			NCheck(ANType14RecordGetAlternateSegmentVertexCount(this->GetOwnerHandle(), baseIndex, &value));
			return value;
		}

		void Get(NInt baseIndex, NInt index, ::Neurotec::Geometry::NPoint * pValue) const
		{
			NCheck(ANType14RecordGetAlternateSegmentVertex(this->GetOwnerHandle(), baseIndex, index, pValue));
		}

		::Neurotec::Geometry::NPoint Get(NInt baseIndex, NInt index) const
		{
			::Neurotec::Geometry::NPoint value;
			NCheck(ANType14RecordGetAlternateSegmentVertex(this->GetOwnerHandle(), baseIndex, index, &value));
			return value;
		}

#include <Core/NNoDeprecate.h>
		N_DEPRECATED("use NArrayWrapper<NPoint> GetAll(NInt baseIndex) instead")
		NInt GetAll(NInt baseIndex, ::Neurotec::Geometry::NPoint * arValues, NInt valuesLength) const
		{
			NInt count;
			NCheck(count = ANType14RecordGetAlternateSegmentVerticesEx(this->GetOwnerHandle(), baseIndex, arValues, valuesLength));
			return count;
		}
#include <Core/NReDeprecate.h>

		NArrayWrapper< ::Neurotec::Geometry::NPoint> GetAll(NInt baseIndex) const
		{
			::Neurotec::Geometry::NPoint::NativeType * arValues = NULL;
			NInt valueCount = 0;
			NCheck(ANType14RecordGetAlternateSegmentVertices(this->GetOwnerHandle(), baseIndex, &arValues, &valueCount));
			return NArrayWrapper< ::Neurotec::Geometry::NPoint>(arValues, valueCount);
		}

		void Set(NInt baseIndex, NInt index, const ::Neurotec::Geometry::NPoint & value)
		{
			NCheck(ANType14RecordSetAlternateSegmentVertex(this->GetOwnerHandle(), baseIndex, index, &value));
		}

		NInt Add(NInt baseIndex, const ::Neurotec::Geometry::NPoint & value)
		{
			NInt index;
			NCheck(ANType14RecordAddAlternateSegmentVertexEx(this->GetOwnerHandle(), baseIndex, &value, &index));
			return index;
		}

		void Insert(NInt baseIndex, NInt index, const ::Neurotec::Geometry::NPoint & value)
		{
			NCheck(ANType14RecordInsertAlternateSegmentVertex(this->GetOwnerHandle(), baseIndex, index, &value));
		}

		void RemoveAt(NInt baseIndex, NInt index)
		{
			NCheck(ANType14RecordRemoveAlternateSegmentVertexAt(this->GetOwnerHandle(), baseIndex, index));
		}

		void Clear(NInt baseIndex)
		{
			NCheck(ANType14RecordClearAlternateSegmentVertices(this->GetOwnerHandle(), baseIndex));
		}
	};

public:
	static NType ANFAmputationTypeNativeTypeOf()
	{
		return NObject::GetObject<NType>(N_TYPE_OF(ANFAmputationType), true);
	}

	bool GetPrintPositionDescriptor(ANFPositionDescriptor * pValue) const
	{
		NBool hasValue;
		NCheck(ANType14RecordGetPrintPositionDescriptor(GetHandle(), pValue, &hasValue));
		return hasValue != 0;
	}

	void SetPrintPositionDescriptor(const ANFPositionDescriptor * pValue)
	{
		NCheck(ANType14RecordSetPrintPositionDescriptor(GetHandle(), pValue));
	}

	AmputationCollection GetAmputations()
	{
		return AmputationCollection(*this);
	}

	const AmputationCollection GetAmputations() const
	{
		return AmputationCollection(*this);
	}

	SegmentCollection GetSegments()
	{
		return SegmentCollection(*this);
	}

	const SegmentCollection GetSegments() const
	{
		return SegmentCollection(*this);
	}

	NistQualityMetricCollection GetNistQualityMetrics()
	{
		return NistQualityMetricCollection(*this);
	}

	const NistQualityMetricCollection GetNistQualityMetrics() const
	{
		return NistQualityMetricCollection(*this);
	}

	SegmentationQualityMetricCollection GetSegmentationQualityMetrics()
	{
		return SegmentationQualityMetricCollection(*this);
	}

	const SegmentationQualityMetricCollection GetSegmentationQualityMetrics() const
	{
		return SegmentationQualityMetricCollection(*this);
	}

	AlternateSegmentCollection GetAlternateSegments()
	{
		return AlternateSegmentCollection(*this);
	}

	const AlternateSegmentCollection GetAlternateSegments() const
	{
		return AlternateSegmentCollection(*this);
	}

	AlternateSegmentVerticesCollection GetAlternateSegmentsVertices()
	{
		return AlternateSegmentVerticesCollection(*this);
	}

	const AlternateSegmentVerticesCollection GetAlternateSegmentsVertices() const
	{
		return AlternateSegmentVerticesCollection(*this);
	}
};

}}}

#endif // !AN_TYPE_14_RECORD_HPP_INCLUDED
