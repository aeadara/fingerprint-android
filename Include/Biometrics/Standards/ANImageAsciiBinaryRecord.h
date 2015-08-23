#ifndef AN_IMAGE_ASCII_BINARY_RECORD_H_INCLUDED
#define AN_IMAGE_ASCII_BINARY_RECORD_H_INCLUDED

#include <Biometrics/Standards/ANAsciiBinaryRecord.h>
#include <Biometrics/Standards/ANImage.h>
#include <Biometrics/Standards/BdifTypes.h>

#ifdef N_CPP
extern "C"
{
#endif

N_DECLARE_OBJECT_TYPE(ANImageAsciiBinaryRecord, ANAsciiBinaryRecord)

#define AN_IMAGE_ASCII_BINARY_RECORD_FIELD_HLL   6
#define AN_IMAGE_ASCII_BINARY_RECORD_FIELD_VLL   7
#define AN_IMAGE_ASCII_BINARY_RECORD_FIELD_SLC   8
#define AN_IMAGE_ASCII_BINARY_RECORD_FIELD_HPS   9
#define AN_IMAGE_ASCII_BINARY_RECORD_FIELD_VPS  10
#define AN_IMAGE_ASCII_BINARY_RECORD_FIELD_CGA  11
#define AN_IMAGE_ASCII_BINARY_RECORD_FIELD_BPX  12
#define AN_IMAGE_ASCII_BINARY_RECORD_FIELD_CSP  13
#define AN_IMAGE_ASCII_BINARY_RECORD_FIELD_SHPS 16
#define AN_IMAGE_ASCII_BINARY_RECORD_FIELD_SVPS 17
#define AN_IMAGE_ASCII_BINARY_RECORD_FIELD_COM  20
#define AN_IMAGE_ASCII_BINARY_RECORD_FIELD_IQM  24
#define AN_IMAGE_ASCII_BINARY_RECORD_FIELD_DMM  30

#define AN_IMAGE_ASCII_BINARY_RECORD_MAX_LINE_LENGTH 9999
#define AN_IMAGE_ASCII_BINARY_RECORD_MAX_PIXEL_SCALE 9999

#define AN_IMAGE_ASCII_BINARY_RECORD_MIN_SCAN_PIXEL_SCALE_PPCM        195
#define AN_IMAGE_ASCII_BINARY_RECORD_MIN_SCAN_PIXEL_SCALE_PPI         495
#define AN_IMAGE_ASCII_BINARY_RECORD_MIN_LATENT_SCAN_PIXEL_SCALE_PPCM 195
#define AN_IMAGE_ASCII_BINARY_RECORD_MIN_LATENT_SCAN_PIXEL_SCALE_PPI  495
#define AN_IMAGE_ASCII_BINARY_RECORD_MIN_LATENT_SCAN_PIXEL_SCALE_V4_PPCM 390
#define AN_IMAGE_ASCII_BINARY_RECORD_MIN_LATENT_SCAN_PIXEL_SCALE_V4_PPI  990

#define AN_IMAGE_ASCII_BINARY_RECORD_MIN_PIXEL_SCALE_PPCM           195
#define AN_IMAGE_ASCII_BINARY_RECORD_MIN_PIXEL_SCALE_PPI            495
#define AN_IMAGE_ASCII_BINARY_RECORD_MIN_LATENT_PIXEL_SCALE_PPCM    195
#define AN_IMAGE_ASCII_BINARY_RECORD_MIN_LATENT_PIXEL_SCALE_PPI     495
#define AN_IMAGE_ASCII_BINARY_RECORD_MIN_LATENT_PIXEL_SCALE_V4_PPCM 390
#define AN_IMAGE_ASCII_BINARY_RECORD_MIN_LATENT_PIXEL_SCALE_V4_PPI  990

#define AN_IMAGE_ASCII_BINARY_RECORD_MIN_VENDOR_COMPRESSION_ALGORITHM_LENGTH   3
#define AN_IMAGE_ASCII_BINARY_RECORD_MAX_VENDOR_COMPRESSION_ALGORITHM_LENGTH   6
#define AN_IMAGE_ASCII_BINARY_RECORD_MAX_COMMENT_LENGTH                      127

typedef enum ANDeviceMonitoringMode_
{
	andmmUnspecified = 0,
	andmmControlled = 1,
	andmmAssisted = 2,
	andmmObserved = 3,
	andmmUnattended = 4,
	andmmUnknown = 255
} ANDeviceMonitoringMode;

N_DECLARE_TYPE(ANDeviceMonitoringMode)

NResult N_API ANImageAsciiBinaryRecordToNImage(HANImageAsciiBinaryRecord hRecord, NUInt flags, HNImage * phImage);

NResult N_API ANImageAsciiBinaryRecordGetHorzLineLength(HANImageAsciiBinaryRecord hRecord, NUShort * pValue);
NResult N_API ANImageAsciiBinaryRecordGetVertLineLength(HANImageAsciiBinaryRecord hRecord, NUShort * pValue);
NResult N_API ANImageAsciiBinaryRecordGetScaleUnits(HANImageAsciiBinaryRecord hRecord, BdifScaleUnits * pValue);
NResult N_API ANImageAsciiBinaryRecordGetHorzPixelScale(HANImageAsciiBinaryRecord hRecord, NUShort * pValue);
NResult N_API ANImageAsciiBinaryRecordGetVertPixelScale(HANImageAsciiBinaryRecord hRecord, NUShort * pValue);
NResult N_API ANImageAsciiBinaryRecordGetCompressionAlgorithm(HANImageAsciiBinaryRecord hRecord, ANImageCompressionAlgorithm * pValue);

NResult N_API ANImageAsciiBinaryRecordGetVendorCompressionAlgorithmN(HANImageAsciiBinaryRecord hRecord, HNString * phValue);
NResult N_API ANImageAsciiBinaryRecordGetBitsPerPixel(HANImageAsciiBinaryRecord hRecord, NByte * pValue);
NResult N_API ANImageAsciiBinaryRecordGetColorSpace(HANImageAsciiBinaryRecord hRecord, ANImageColorSpace * pValue);
NResult N_API ANImageAsciiBinaryRecordGetScanHorzPixelScale(HANImageAsciiBinaryRecord hRecord, NInt * pValue);
NResult N_API ANImageAsciiBinaryRecordSetScanHorzPixelScale(HANImageAsciiBinaryRecord hRecord, NInt value);
NResult N_API ANImageAsciiBinaryRecordGetScanVertPixelScale(HANImageAsciiBinaryRecord hRecord, NInt * pValue);
NResult N_API ANImageAsciiBinaryRecordSetScanVertPixelScale(HANImageAsciiBinaryRecord hRecord, NInt value);

NResult N_API ANImageAsciiBinaryRecordGetCommentN(HANImageAsciiBinaryRecord hRecord, HNString * phValue);
NResult N_API ANImageAsciiBinaryRecordSetCommentN(HANImageAsciiBinaryRecord hRecord, HNString hValue);
#ifndef N_NO_ANSI_FUNC
NResult N_API ANImageAsciiBinaryRecordSetCommentA(HANImageAsciiBinaryRecord hRecord, const NAChar * szValue);
#endif
#ifndef N_NO_UNICODE
NResult N_API ANImageAsciiBinaryRecordSetCommentW(HANImageAsciiBinaryRecord hRecord, const NWChar * szValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API ANImageAsciiBinaryRecordSetComment(HANImageAsciiBinaryRecord hRecord, const NChar * szValue);
#endif
#define ANImageAsciiBinaryRecordSetComment N_FUNC_AW(ANImageAsciiBinaryRecordSetComment)

NResult N_API ANImageAsciiBinaryRecordGetDeviceMonitoringMode(HANImageAsciiBinaryRecord hRecord, ANDeviceMonitoringMode * pValue);
NResult N_API ANImageAsciiBinaryRecordSetDeviceMonitoringMode(HANImageAsciiBinaryRecord hRecord, ANDeviceMonitoringMode value);

#ifdef N_CPP
}
#endif

#endif // !AN_IMAGE_ASCII_BINARY_RECORD_H_INCLUDED
