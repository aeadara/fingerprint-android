#ifndef AN_TYPE_13_RECORD_H_INCLUDED
#define AN_TYPE_13_RECORD_H_INCLUDED

#include <Biometrics/Standards/ANFPImageAsciiBinaryRecord.h>

#ifdef N_CPP
extern "C"
{
#endif

N_DECLARE_OBJECT_TYPE(ANType13Record, ANFPImageAsciiBinaryRecord)

#define AN_TYPE_13_RECORD_FIELD_LEN  AN_RECORD_FIELD_LEN
#define AN_TYPE_13_RECORD_FIELD_IDC  AN_RECORD_FIELD_IDC
#define AN_TYPE_13_RECORD_FIELD_IMP  AN_FP_IMAGE_ASCII_BINARY_RECORD_FIELD_IMP
#define AN_TYPE_13_RECORD_FIELD_SRC  AN_ASCII_BINARY_RECORD_FIELD_SRC
#define AN_TYPE_13_RECORD_FIELD_LCD  AN_ASCII_BINARY_RECORD_FIELD_DAT
#define AN_TYPE_13_RECORD_FIELD_HLL  AN_IMAGE_ASCII_BINARY_RECORD_FIELD_HLL
#define AN_TYPE_13_RECORD_FIELD_VLL  AN_IMAGE_ASCII_BINARY_RECORD_FIELD_VLL
#define AN_TYPE_13_RECORD_FIELD_SLC  AN_IMAGE_ASCII_BINARY_RECORD_FIELD_SLC
#define AN_TYPE_13_RECORD_FIELD_HPS  AN_IMAGE_ASCII_BINARY_RECORD_FIELD_HPS
#define AN_TYPE_13_RECORD_FIELD_VPS  AN_IMAGE_ASCII_BINARY_RECORD_FIELD_VPS
#define AN_TYPE_13_RECORD_FIELD_CGA  AN_IMAGE_ASCII_BINARY_RECORD_FIELD_CGA
#define AN_TYPE_13_RECORD_FIELD_BPX  AN_IMAGE_ASCII_BINARY_RECORD_FIELD_BPX
#define AN_TYPE_13_RECORD_FIELD_FGP  AN_FP_IMAGE_ASCII_BINARY_RECORD_FIELD_FGP
#define AN_TYPE_13_RECORD_FIELD_SPD  AN_FP_IMAGE_ASCII_BINARY_RECORD_FIELD_PD
#define AN_TYPE_13_RECORD_FIELD_PPC  AN_FP_IMAGE_ASCII_BINARY_RECORD_FIELD_PPC
#define AN_TYPE_13_RECORD_FIELD_SHPS AN_IMAGE_ASCII_BINARY_RECORD_FIELD_SHPS
#define AN_TYPE_13_RECORD_FIELD_SVPS AN_IMAGE_ASCII_BINARY_RECORD_FIELD_SVPS
#define AN_TYPE_13_RECORD_FIELD_COM  AN_IMAGE_ASCII_BINARY_RECORD_FIELD_COM
#define AN_TYPE_13_RECORD_FIELD_LQM  AN_IMAGE_ASCII_BINARY_RECORD_FIELD_IQM

#define AN_TYPE_13_RECORD_FIELD_UDF_FROM AN_ASCII_BINARY_RECORD_FIELD_UDF_FROM
#define AN_TYPE_13_RECORD_FIELD_UDF_TO   AN_ASCII_BINARY_RECORD_FIELD_UDF_TO

#define AN_TYPE_13_RECORD_FIELD_DATA AN_RECORD_FIELD_DATA

#define AN_TYPE_13_RECORD_MAX_SEARCH_POSITION_DESCRIPTOR_COUNT 9
#define AN_TYPE_13_RECORD_MAX_QUALITY_METRIC_COUNT             4

NResult N_API ANType13RecordGetSearchPositionDescriptorCount(HANType13Record hRecord, NInt * pValue);
NResult N_API ANType13RecordGetSearchPositionDescriptor(HANType13Record hRecord, NInt index, struct ANFPositionDescriptor_ * pValue);
N_DEPRECATED("function is deprecated, use ANType13RecordGetSearchPositionDescriptors instead")
NResult N_API ANType13RecordGetSearchPositionDescriptorsEx(HANType13Record hRecord, struct ANFPositionDescriptor_ * arValue, NInt valueLength);
NResult N_API ANType13RecordGetSearchPositionDescriptors(HANType13Record hRecord, struct ANFPositionDescriptor_ * * parValues, NInt * pValueCount);
NResult N_API ANType13RecordSetSearchPositionDescriptor(HANType13Record hRecord, NInt index, const struct ANFPositionDescriptor_ * pValue);
N_DEPRECATED("function is deprecated, use ANType13RecordAddSearchPositionDescriptorEx instead")
NResult N_API ANType13RecordAddSearchPositionDescriptor(HANType13Record hRecord, const struct ANFPositionDescriptor_ * pValue);
NResult N_API ANType13RecordAddSearchPositionDescriptorEx(HANType13Record hRecord, const struct ANFPositionDescriptor_ * pValue, NInt * pIndex);
NResult N_API ANType13RecordInsertSearchPositionDescriptor(HANType13Record hRecord, NInt index, const struct ANFPositionDescriptor_ * pValue);
N_DEPRECATED("function is deprecated, use ANType13RecordRemoveSearchPositionDescriptorAt instead")
NResult N_API ANType13RecordRemoveSearchPositionDescriptor(HANType13Record hRecord, NInt index);
NResult N_API ANType13RecordRemoveSearchPositionDescriptorAt(HANType13Record hRecord, NInt index);
NResult N_API ANType13RecordClearSearchPositionDescriptors(HANType13Record hRecord);

#ifdef N_CPP
}
#endif

#endif // !AN_TYPE_13_RECORD_H_INCLUDED
