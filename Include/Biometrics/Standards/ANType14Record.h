#ifndef AN_TYPE_14_RECORD_H_INCLUDED
#define AN_TYPE_14_RECORD_H_INCLUDED

#include <Biometrics/Standards/ANFPImageAsciiBinaryRecord.h>
#include <Geometry/NGeometry.h>

#ifdef N_CPP
extern "C"
{
#endif

N_DECLARE_OBJECT_TYPE(ANType14Record, ANFPImageAsciiBinaryRecord)

#define AN_TYPE_14_RECORD_FIELD_LEN  AN_RECORD_FIELD_LEN
#define AN_TYPE_14_RECORD_FIELD_IDC  AN_RECORD_FIELD_IDC
#define AN_TYPE_14_RECORD_FIELD_IMP  AN_FP_IMAGE_ASCII_BINARY_RECORD_FIELD_IMP
#define AN_TYPE_14_RECORD_FIELD_SRC  AN_ASCII_BINARY_RECORD_FIELD_SRC
#define AN_TYPE_14_RECORD_FIELD_FCD  AN_ASCII_BINARY_RECORD_FIELD_DAT
#define AN_TYPE_14_RECORD_FIELD_HLL  AN_IMAGE_ASCII_BINARY_RECORD_FIELD_HLL
#define AN_TYPE_14_RECORD_FIELD_VLL  AN_IMAGE_ASCII_BINARY_RECORD_FIELD_VLL
#define AN_TYPE_14_RECORD_FIELD_SLC  AN_IMAGE_ASCII_BINARY_RECORD_FIELD_SLC
#define AN_TYPE_14_RECORD_FIELD_HPS  AN_IMAGE_ASCII_BINARY_RECORD_FIELD_HPS
#define AN_TYPE_14_RECORD_FIELD_VPS  AN_IMAGE_ASCII_BINARY_RECORD_FIELD_VPS
#define AN_TYPE_14_RECORD_FIELD_CGA  AN_IMAGE_ASCII_BINARY_RECORD_FIELD_CGA
#define AN_TYPE_14_RECORD_FIELD_BPX  AN_IMAGE_ASCII_BINARY_RECORD_FIELD_BPX
#define AN_TYPE_14_RECORD_FIELD_FGP  AN_FP_IMAGE_ASCII_BINARY_RECORD_FIELD_FGP
#define AN_TYPE_14_RECORD_FIELD_PPD  AN_FP_IMAGE_ASCII_BINARY_RECORD_FIELD_PD
#define AN_TYPE_14_RECORD_FIELD_PPC  AN_FP_IMAGE_ASCII_BINARY_RECORD_FIELD_PPC
#define AN_TYPE_14_RECORD_FIELD_SHPS AN_IMAGE_ASCII_BINARY_RECORD_FIELD_SHPS
#define AN_TYPE_14_RECORD_FIELD_SVPS AN_IMAGE_ASCII_BINARY_RECORD_FIELD_SVPS

#define AN_TYPE_14_RECORD_FIELD_AMP 18

#define AN_TYPE_14_RECORD_FIELD_COM AN_IMAGE_ASCII_BINARY_RECORD_FIELD_COM

#define AN_TYPE_14_RECORD_FIELD_SEG 21
#define AN_TYPE_14_RECORD_FIELD_NQM 22
#define AN_TYPE_14_RECORD_FIELD_SQM 23

#define AN_TYPE_14_RECORD_FIELD_FQM AN_IMAGE_ASCII_BINARY_RECORD_FIELD_IQM

#define AN_TYPE_14_RECORD_FIELD_ASEG 25

#define AN_TYPE_14_RECORD_FIELD_DMM AN_IMAGE_ASCII_BINARY_RECORD_FIELD_DMM

#define AN_TYPE_14_RECORD_FIELD_UDF_FROM AN_ASCII_BINARY_RECORD_FIELD_UDF_FROM
#define AN_TYPE_14_RECORD_FIELD_UDF_TO   AN_ASCII_BINARY_RECORD_FIELD_UDF_TO

#define AN_TYPE_14_RECORD_FIELD_DATA AN_RECORD_FIELD_DATA

#define AN_TYPE_14_RECORD_MAX_AMPUTATION_COUNT          4
#define AN_TYPE_14_RECORD_MAX_NIST_QUALITY_METRIC_COUNT 4
#define AN_TYPE_14_RECORD_MAX_ALTERNATE_SEGMENT_COUNT   4

#define AN_TYPE_14_RECORD_MIN_ALTERNATE_SEGMENT_VERTEX_COUNT  3
#define AN_TYPE_14_RECORD_MAX_ALTERNATE_SEGMENT_VERTEX_COUNT 99

#define AN_TYPE_14_RECORD_NIST_QUALITY_METRIC_SCORE_EXCELLENT       1
#define AN_TYPE_14_RECORD_NIST_QUALITY_METRIC_SCORE_VERY_GOOD       2
#define AN_TYPE_14_RECORD_NIST_QUALITY_METRIC_SCORE_GOOD            3
#define AN_TYPE_14_RECORD_NIST_QUALITY_METRIC_SCORE_FAIR            4
#define AN_TYPE_14_RECORD_NIST_QUALITY_METRIC_SCORE_POOR            5
#define AN_TYPE_14_RECORD_NIST_QUALITY_METRIC_SCORE_NOT_AVAILABLE 254
#define AN_TYPE_14_RECORD_NIST_QUALITY_METRIC_SCORE_FAILED        255

typedef enum ANFAmputationType_
{
	anfatAmputation = 0,
	anfatUnableToPrint = 1
} ANFAmputationType;

N_DECLARE_TYPE(ANFAmputationType)

struct ANFAmputation_
{
	BdifFPPosition Position;
	ANFAmputationType Type;
};
#ifndef AN_TYPE_14_RECORD_HPP_INCLUDED
typedef struct ANFAmputation_ ANFAmputation;
#endif

N_DECLARE_TYPE(ANFAmputation)

struct ANFSegment_
{
	BdifFPPosition Position;
	NInt Left;
	NInt Right;
	NInt Top;
	NInt Bottom;
};
#ifndef AN_TYPE_14_RECORD_HPP_INCLUDED
typedef struct ANFSegment_ ANFSegment;
#endif

N_DECLARE_TYPE(ANFSegment)

struct ANNistQualityMetric_
{
	BdifFPPosition Position;
	NByte Score;
};
#ifndef AN_TYPE_14_RECORD_HPP_INCLUDED
typedef struct ANNistQualityMetric_ ANNistQualityMetric;
#endif

N_DECLARE_TYPE(ANNistQualityMetric)

struct ANFAlternateSegment_
{
	BdifFPPosition Position;
};
#ifndef AN_TYPE_14_RECORD_HPP_INCLUDED
typedef struct ANFAlternateSegment_ ANFAlternateSegment;
#endif

N_DECLARE_TYPE(ANFAlternateSegment)

NResult N_API ANType14RecordGetPrintPositionDescriptor(HANType14Record hRecord, struct ANFPositionDescriptor_ * pValue, NBool * pHasValue);
NResult N_API ANType14RecordSetPrintPositionDescriptor(HANType14Record hRecord, const struct ANFPositionDescriptor_ * pValue);

NResult N_API ANType14RecordGetAmputationCount(HANType14Record hRecord, NInt * pValue);
NResult N_API ANType14RecordGetAmputation(HANType14Record hRecord, NInt index, struct ANFAmputation_ * pValue);
N_DEPRECATED("function is deprecated, use ANType14RecordGetAmputations instead")
NResult N_API ANType14RecordGetAmputationsEx(HANType14Record hRecord, struct ANFAmputation_ * arValue, NInt valueLength);
NResult N_API ANType14RecordGetAmputations(HANType14Record hRecord, struct ANFAmputation_ * * parValues, NInt * pValueCount);
NResult N_API ANType14RecordSetAmputation(HANType14Record hRecord, NInt index, const struct ANFAmputation_ * pValue);
N_DEPRECATED("function is deprecated, use ANType14RecordAddAmputationEx instead")
NResult N_API ANType14RecordAddAmputation(HANType14Record hRecord, const struct ANFAmputation_ * pValue);
NResult N_API ANType14RecordAddAmputationEx(HANType14Record hRecord, const struct ANFAmputation_ * pValue, NInt * pIndex);
NResult N_API ANType14RecordInsertAmputation(HANType14Record hRecord, NInt index, const struct ANFAmputation_ * pValue);
N_DEPRECATED("function is deprecated, use ANType14RecordRemoveAmputationAt instead")
NResult N_API ANType14RecordRemoveAmputation(HANType14Record hRecord, NInt index);
NResult N_API ANType14RecordRemoveAmputationAt(HANType14Record hRecord, NInt index);
NResult N_API ANType14RecordClearAmputations(HANType14Record hRecord);

NResult N_API ANType14RecordGetSegmentCount(HANType14Record hRecord, NInt * pValue);
NResult N_API ANType14RecordGetSegment(HANType14Record hRecord, NInt index, struct ANFSegment_ * pValue);
N_DEPRECATED("function is deprecated, use ANType14RecordGetSegments instead")
NResult N_API ANType14RecordGetSegmentsEx(HANType14Record hRecord, struct ANFSegment_ * arValue, NInt valueLength);
NResult N_API ANType14RecordGetSegments(HANType14Record hRecord, struct ANFSegment_ * * parValues, NInt * pValueCount);
NResult N_API ANType14RecordSetSegment(HANType14Record hRecord, NInt index, const struct ANFSegment_ * pValue);
N_DEPRECATED("function is deprecated, use ANType14RecordAddSegmentEx instead")
NResult N_API ANType14RecordAddSegment(HANType14Record hRecord, const struct ANFSegment_ * pValue);
NResult N_API ANType14RecordAddSegmentEx(HANType14Record hRecord, const struct ANFSegment_ * pValue, NInt * pIndex);
NResult N_API ANType14RecordInsertSegment(HANType14Record hRecord, NInt index, const struct ANFSegment_ * pValue);
N_DEPRECATED("function is deprecated, use ANType14RecordRemoveSegmentAt instead")
NResult N_API ANType14RecordRemoveSegment(HANType14Record hRecord, NInt index);
NResult N_API ANType14RecordRemoveSegmentAt(HANType14Record hRecord, NInt index);
NResult N_API ANType14RecordClearSegments(HANType14Record hRecord);

NResult N_API ANType14RecordGetNistQualityMetricCount(HANType14Record hRecord, NInt * pValue);
NResult N_API ANType14RecordGetNistQualityMetric(HANType14Record hRecord, NInt index, struct ANNistQualityMetric_ * pValue);
N_DEPRECATED("function is deprecated, use ANType14RecordGetNistQualityMetrics instead")
NResult N_API ANType14RecordGetNistQualityMetricsEx(HANType14Record hRecord, struct ANNistQualityMetric_ * arValue, NInt valueLength);
NResult N_API ANType14RecordGetNistQualityMetrics(HANType14Record hRecord, struct ANNistQualityMetric_ * * parValues, NInt * pValueCount);
NResult N_API ANType14RecordSetNistQualityMetric(HANType14Record hRecord, NInt index, const struct ANNistQualityMetric_ * pValue);
N_DEPRECATED("function is deprecated, use ANType14RecordAddNistQualityMetricEx instead")
NResult N_API ANType14RecordAddNistQualityMetric(HANType14Record hRecord, const struct ANNistQualityMetric_ * pValue);
NResult N_API ANType14RecordAddNistQualityMetricEx(HANType14Record hRecord, const struct ANNistQualityMetric_ * pValue, NInt * pIndex);
NResult N_API ANType14RecordInsertNistQualityMetric(HANType14Record hRecord, NInt index, const struct ANNistQualityMetric_ * pValue);
N_DEPRECATED("function is deprecated, use ANType14RecordRemoveNistQualityMetricAt instead")
NResult N_API ANType14RecordRemoveNistQualityMetric(HANType14Record hRecord, NInt index);
NResult N_API ANType14RecordRemoveNistQualityMetricAt(HANType14Record hRecord, NInt index);
NResult N_API ANType14RecordClearNistQualityMetrics(HANType14Record hRecord);

NResult N_API ANType14RecordGetSegmentationQualityMetricCount(HANType14Record hRecord, NInt * pValue);
NResult N_API ANType14RecordGetSegmentationQualityMetric(HANType14Record hRecord, NInt index, struct ANFPQualityMetric_ * pValue);
N_DEPRECATED("function is deprecated, use ANType14RecordGetSegmentationQualityMetrics instead")
NResult N_API ANType14RecordGetSegmentationQualityMetricsEx(HANType14Record hRecord, struct ANFPQualityMetric_ * arValue, NInt valueLength);
NResult N_API ANType14RecordGetSegmentationQualityMetrics(HANType14Record hRecord, struct ANFPQualityMetric_ * * parValues, NInt * pValueCount);
NResult N_API ANType14RecordSetSegmentationQualityMetric(HANType14Record hRecord, NInt index, const struct ANFPQualityMetric_ * pValue);
N_DEPRECATED("function is deprecated, use ANType14RecordAddSegmentationQualityMetricEx instead")
NResult N_API ANType14RecordAddSegmentationQualityMetric(HANType14Record hRecord, const struct ANFPQualityMetric_ * pValue);
NResult N_API ANType14RecordAddSegmentationQualityMetricEx(HANType14Record hRecord, const struct ANFPQualityMetric_ * pValue, NInt * pIndex);
NResult N_API ANType14RecordInsertSegmentationQualityMetric(HANType14Record hRecord, NInt index, const struct ANFPQualityMetric_ * pValue);
N_DEPRECATED("function is deprecated, use ANType14RecordRemoveSegmentationQualityMetricAt instead")
NResult N_API ANType14RecordRemoveSegmentationQualityMetric(HANType14Record hRecord, NInt index);
NResult N_API ANType14RecordRemoveSegmentationQualityMetricAt(HANType14Record hRecord, NInt index);
NResult N_API ANType14RecordClearSegmentationQualityMetrics(HANType14Record hRecord);

NResult N_API ANType14RecordGetAlternateSegmentCount(HANType14Record hRecord, NInt * pValue);
NResult N_API ANType14RecordGetAlternateSegment(HANType14Record hRecord, NInt index, struct ANFAlternateSegment_ * pValue);
N_DEPRECATED("function is deprecated, use ANType14RecordGetAlternateSegments instead")
NResult N_API ANType14RecordGetAlternateSegmentsEx(HANType14Record hRecord, struct ANFAlternateSegment_ * arValue, NInt valueLength);
NResult N_API ANType14RecordGetAlternateSegments(HANType14Record hRecord, struct ANFAlternateSegment_ * * parValues, NInt * pValueCount);
NResult N_API ANType14RecordSetAlternateSegment(HANType14Record hRecord, NInt index, const struct ANFAlternateSegment_ * pValue);
N_DEPRECATED("function is deprecated, use ANType14RecordAddAlternateSegmentEx instead")
NResult N_API ANType14RecordAddAlternateSegment(HANType14Record hRecord, const struct ANFAlternateSegment_ * pValue);
NResult N_API ANType14RecordAddAlternateSegmentEx(HANType14Record hRecord, const struct ANFAlternateSegment_ * pValue, NInt * pIndex);
NResult N_API ANType14RecordInsertAlternateSegment(HANType14Record hRecord, NInt index, const struct ANFAlternateSegment_ * pValue);
N_DEPRECATED("function is deprecated, use ANType14RecordRemoveAlternateSegmentAt instead")
NResult N_API ANType14RecordRemoveAlternateSegment(HANType14Record hRecord, NInt index);
NResult N_API ANType14RecordRemoveAlternateSegmentAt(HANType14Record hRecord, NInt index);
NResult N_API ANType14RecordClearAlternateSegments(HANType14Record hRecord);

NResult N_API ANType14RecordGetAlternateSegmentVertexCount(HANType14Record hRecord, NInt segmentIndex, NInt * pValue);
NResult N_API ANType14RecordGetAlternateSegmentVertex(HANType14Record hRecord, NInt segmentIndex, NInt index, struct NPoint_ * pValue);
N_DEPRECATED("function is deprecated, use ANType14RecordGetAlternateSegmentVertices instead")
NResult N_API ANType14RecordGetAlternateSegmentVerticesEx(HANType14Record hRecord, NInt segmentIndex, struct NPoint_ * arValue, NInt valueLength);
NResult N_API ANType14RecordGetAlternateSegmentVertices(HANType14Record hRecord, NInt segmentIndex, struct NPoint_ * * parValues, NInt * pValueCount);
NResult N_API ANType14RecordSetAlternateSegmentVertex(HANType14Record hRecord, NInt segmentIndex, NInt index, const struct NPoint_ * pValue);
N_DEPRECATED("function is deprecated, use ANType14RecordAddAlternateSegmentVertexEx instead")
NResult N_API ANType14RecordAddAlternateSegmentVertex(HANType14Record hRecord, NInt segmentIndex, const struct NPoint_ * pValue);
NResult N_API ANType14RecordAddAlternateSegmentVertexEx(HANType14Record hRecord, NInt segmentIndex, const struct NPoint_ * pValue, NInt * pIndex);
NResult N_API ANType14RecordInsertAlternateSegmentVertex(HANType14Record hRecord, NInt segmentIndex, NInt index, const struct NPoint_ * pValue);
N_DEPRECATED("function is deprecated, use ANType14RecordRemoveAlternateSegmentVertexAt instead")
NResult N_API ANType14RecordRemoveAlternateSegmentVertex(HANType14Record hRecord, NInt segmentIndex, NInt index);
NResult N_API ANType14RecordRemoveAlternateSegmentVertexAt(HANType14Record hRecord, NInt segmentIndex, NInt index);
NResult N_API ANType14RecordClearAlternateSegmentVertices(HANType14Record hRecord, NInt segmentIndex);

#ifdef N_CPP
}
#endif

#endif // !AN_TYPE_14_RECORD_H_INCLUDED
