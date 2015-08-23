#ifndef AN_IMAGE_BINARY_RECORD_H_INCLUDED
#define AN_IMAGE_BINARY_RECORD_H_INCLUDED

#include <Biometrics/Standards/ANBinaryRecord.h>
#include <Biometrics/Standards/ANImage.h>

#ifdef N_CPP
extern "C"
{
#endif

N_DECLARE_OBJECT_TYPE(ANImageBinaryRecord, ANBinaryRecord)

#define AN_IMAGE_BINARY_RECORD_FIELD_ISR 5
#define AN_IMAGE_BINARY_RECORD_FIELD_HLL 6
#define AN_IMAGE_BINARY_RECORD_FIELD_VLL 7

NResult N_API ANImageBinaryRecordToNImage(HANImageBinaryRecord hRecord, NUInt flags, HNImage * phImage);

NResult N_API ANImageBinaryRecordGetImageScanResolution(HANImageBinaryRecord hRecord, NBool * pValue);
NResult N_API ANImageBinaryRecordGetImageScanResolutionValue(HANImageBinaryRecord hRecord, NUInt * pValue);
NResult N_API ANImageBinaryRecordGetImageResolution(HANImageBinaryRecord hRecord, NUInt * pValue);
NResult N_API ANImageBinaryRecordGetHorzLineLength(HANImageBinaryRecord hRecord, NUShort * pValue);
NResult N_API ANImageBinaryRecordGetVertLineLength(HANImageBinaryRecord hRecord, NUShort * pValue);

#ifdef N_CPP
}
#endif

#endif // !AN_IMAGE_BINARY_RECORD_H_INCLUDED
