#ifndef AN_FINGERPRINT_IMAGE_BINARY_RECORD_H_INCLUDED
#define AN_FINGERPRINT_IMAGE_BINARY_RECORD_H_INCLUDED

#include <Biometrics/Standards/ANImageBinaryRecord.h>
#include <Biometrics/Standards/BdifTypes.h>

#ifdef N_CPP
extern "C"
{
#endif

N_DECLARE_OBJECT_TYPE(ANFImageBinaryRecord, ANImageBinaryRecord)

#define AN_F_IMAGE_BINARY_RECORD_FIELD_IMP 3
#define AN_F_IMAGE_BINARY_RECORD_FIELD_FGP 4
#define AN_F_IMAGE_BINARY_RECORD_FIELD_CA  8

#define AN_F_IMAGE_BINARY_RECORD_MAX_POSITION_COUNT 6

NResult N_API ANFImageBinaryRecordGetPositionCount(HANFImageBinaryRecord hRecord, NInt * pValue);
NResult N_API ANFImageBinaryRecordGetPosition(HANFImageBinaryRecord hRecord, NInt index, BdifFPPosition * pValue);
N_DEPRECATED("function is deprecated, use ANFImageBinaryRecordGetPositions instead")
NResult N_API ANFImageBinaryRecordGetPositionsEx(HANFImageBinaryRecord hRecord, BdifFPPosition * arValue, NInt valueLength);
NResult N_API ANFImageBinaryRecordGetPositions(HANFImageBinaryRecord hRecord, BdifFPPosition * * parValues, NInt * pValueCount);
NResult N_API ANFImageBinaryRecordSetPosition(HANFImageBinaryRecord hRecord, NInt index, BdifFPPosition value);
N_DEPRECATED("function is deprecated, use ANFImageBinaryRecordAddPositionEx instead")
NResult N_API ANFImageBinaryRecordAddPosition(HANFImageBinaryRecord hRecord, BdifFPPosition value);
NResult N_API ANFImageBinaryRecordAddPositionEx(HANFImageBinaryRecord hRecord, BdifFPPosition value, NInt * pIndex);
NResult N_API ANFImageBinaryRecordInsertPosition(HANFImageBinaryRecord hRecord, NInt index, BdifFPPosition value);
N_DEPRECATED("function is deprecated, use ANFImageBinaryRecordRemovePositionAt instead")
NResult N_API ANFImageBinaryRecordRemovePosition(HANFImageBinaryRecord hRecord, NInt index);
NResult N_API ANFImageBinaryRecordRemovePositionAt(HANFImageBinaryRecord hRecord, NInt index);
NResult N_API ANFImageBinaryRecordClearPositions(HANFImageBinaryRecord hRecord);

NResult N_API ANFImageBinaryRecordGetImpressionType(HANFImageBinaryRecord hRecord, BdifFPImpressionType * pValue);
NResult N_API ANFImageBinaryRecordSetImpressionType(HANFImageBinaryRecord hRecord, BdifFPImpressionType value);

#ifdef N_CPP
}
#endif

#endif // !AN_FINGERPRINT_IMAGE_BINARY_RECORD_H_INCLUDED
