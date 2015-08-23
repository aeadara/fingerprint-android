#ifndef FI_RECORD_H_INCLUDED
#define FI_RECORD_H_INCLUDED

#include <Biometrics/Standards/BdifTypes.h>
#include <Images/NImage.h>

#ifdef N_CPP
extern "C"
{
#endif

N_DECLARE_OBJECT_TYPE(FIRecord, NObject)

#ifdef N_CPP
}
#endif

typedef enum FirImageCompressionAlgorithm_
{
	firicaNotBitPacked = 0,
	firicaBitPacked = 1,
	firicaWsq = 2,
	firicaJpeg = 3,
	firicaJpeg2000 = 4,
	firicaPng = 5,
	firicaJpeg2000Lossless = 6
} FirImageCompressionAlgorithm;

N_DECLARE_TYPE(FirImageCompressionAlgorithm)

#include <Biometrics/Standards/FirFinger.h>
#include <Biometrics/Standards/FirFingerView.h>

#ifdef N_CPP
extern "C"
{
#endif

#define FIR_VERSION_ANSI_1_0 0x0100
#define FIR_VERSION_ANSI_2_5 0x0205
#define FIR_VERSION_ISO_1_0  0x0100
#define FIR_VERSION_ISO_2_0  0x0200

#define FIR_VERSION_ANSI_CURRENT FIR_VERSION_ANSI_2_5
#define FIR_VERSION_ISO_CURRENT  FIR_VERSION_ISO_2_0

#define FIR_MAX_FINGER_VIEW_COUNT_PER_FINGER 16

#define FIR_MAX_FINGER_COUNT      255
#define FIR_MAX_FINGER_VIEW_COUNT (FIR_MAX_FINGER_COUNT * FIRF_MAX_FINGER_VIEW_COUNT)

#define FIR_MAX_FINGER_COUNT_2_0       42
#define FIR_MAX_FINGER_VIEW_COUNT_2_0  (FIR_MAX_FINGER_COUNT_2_0 * FIR_MAX_FINGER_VIEW_COUNT_PER_FINGER)
#define FIR_MAX_FINGER_VIEW_COUNT_2_5  N_BYTE_MAX

N_DEPRECATED("function is deprecated, use FIRecordGetSize instead")
NResult N_API FIRecordCalculateSize(BdifStandard standard, NInt fingerViewCount, const NSizeType * arFingerViewSizes, NSizeType * pSize);
N_DEPRECATED("function is deprecated, use FIRecordGetSize instead")
NResult N_API FIRecordCalculateSizeWithFingers(BdifStandard standard, NInt fingerCount, const NSizeType * arFingerSizes, NSizeType * pSize);

#define FIR_PROCESS_FIRST_FINGER_ONLY      0x00000100
#define FIR_PROCESS_FIRST_FINGER_VIEW_ONLY (FIR_PROCESS_FIRST_FINGER_ONLY | FIRF_PROCESS_FIRST_FINGER_VIEW_ONLY)

N_DEPRECATED("function is deprecated, use FIRecordCreateEx, FIRecordSetImageAcquisitionLevel, FIRecordSetScaleUnits, FIRecordSetHorzScanResolution, FIRecordSetVertScanResolution, FIRecordSetHorzImageResolution, FIRecordSetVertImageResolution, FIRecordSetPixelDepth, FIRecordSetImageCompressionAlgorithm instead")
NResult N_API FIRecordCreate(NUShort imageAcquisitionLevel, BdifScaleUnits scaleUnits,
	NUShort horzScanResolution, NUShort vertScanResolution, NUShort horzImageResolution, NUShort vertImageResolution,
	NByte pixelDepth, FirImageCompressionAlgorithm imageCompressionAlgorithm,
	NUInt flags, BdifStandard standard, HFIRecord * phRecord);
NResult N_API FIRecordCreateEx(BdifStandard standard, NVersion_ version, NUInt flags, HFIRecord * phRecord);
NResult N_API FIRecordCreateFromMemoryN(HNBuffer hBuffer, NUInt flags, BdifStandard standard, NSizeType * pSize, HFIRecord * phRecord);
NResult N_API FIRecordCreateFromMemory(const void * pBuffer, NSizeType bufferSize, NUInt flags, BdifStandard standard, NSizeType * pSize, HFIRecord * phRecord);
N_DEPRECATED("function is deprecated, use FIRecordCreateFromFIRecordEx instead")
NResult N_API FIRecordCreateFromFIRecord(HFIRecord hSrcRecord, NUInt flags, BdifStandard standard, HFIRecord * phRecord);
NResult N_API FIRecordCreateFromFIRecordEx(HFIRecord hSrcRecord, NUInt flags, BdifStandard standard, NVersion_ version, HFIRecord * phRecord);

N_DEPRECATED("function is deprecated, use FIRecordCreateFromNImageEx instead")
NResult N_API FIRecordCreateFromNImage(HNImage hImage,
	NUShort imageAcquisitionLevel, BdifScaleUnits scaleUnits, NUShort horzScanResolution, NUShort vertScanResolution,
	NByte pixelDepth, FirImageCompressionAlgorithm imageCompressionAlgorithm,
	BdifFPPosition fingerPosition, NUInt flags, BdifStandard standard, HFIRecord * phRecord);
NResult N_API FIRecordCreateFromNImageEx(HNImage hImage,
	NUShort imageAcquisitionLevel, BdifScaleUnits scaleUnits, NUShort horzScanResolution, NUShort vertScanResolution,
	NByte pixelDepth, FirImageCompressionAlgorithm imageCompressionAlgorithm,
	BdifFPPosition fingerPosition, NUInt flags, BdifStandard standard, NVersion_ version, HFIRecord * phRecord);

N_DEPRECATED("function is deprecated")
NResult N_API FIRecordGetFingerCount(HFIRecord hRecord, NInt * pValue);
N_DEPRECATED("function is deprecated")
NResult N_API FIRecordGetFingerEx(HFIRecord hRecord, NInt index, HFirFinger * phValue);
N_DEPRECATED("function is deprecated")
NResult N_API FIRecordGetFingerCapacity(HFIRecord hRecord, NInt * pValue);
N_DEPRECATED("function is deprecated")
NResult N_API FIRecordSetFingerCapacity(HFIRecord hRecord, NInt value);
N_DEPRECATED("function is deprecated")
NResult N_API FIRecordAddFinger(HFIRecord hRecord, BdifFPPosition fingerPosition, NUInt flags, HFirFinger * phFinger);
N_DEPRECATED("function is deprecated")
NResult N_API FIRecordAddFingerFromNImage(HFIRecord hRecord, BdifFPPosition fingerPosition, HNImage hImage, NUInt flags, HFirFinger * phFinger);
N_DEPRECATED("function is deprecated")
NResult N_API FIRecordRemoveFinger(HFIRecord hRecord, NInt index);
N_DEPRECATED("function is deprecated")
NResult N_API FIRecordClearFingers(HFIRecord hRecord);

NResult N_API FIRecordAddFingerView(HFIRecord hRecord, HFirFingerView hFingerView, NInt * pIndex);
NResult N_API FIRecordGetFingerViewCount(HFIRecord hRecord, NInt * pValue);
NResult N_API FIRecordGetFingerView(HFIRecord hRecord, NInt index, HFirFingerView * phValue);
NResult N_API FIRecordGetFingerViewCapacity(HFIRecord hRecord, NInt * pValue);
NResult N_API FIRecordSetFingerViewCapacity(HFIRecord hRecord, NInt value);
NResult N_API FIRecordRemoveFingerViewAt(HFIRecord hRecord, NInt index);
NResult N_API FIRecordClearFingerViews(HFIRecord hRecord);

NResult N_API FIRecordGetVersion(HFIRecord hRecord, NVersion_ * pValue);
NResult N_API FIRecordGetStandard(HFIRecord hRecord, BdifStandard * pValue);
NResult N_API FIRecordGetCertificationFlag(HFIRecord hRecord, NBool * pValue);
NResult N_API FIRecordSetCertificationFlag(HFIRecord hRecord, NBool value);
NResult N_API FIRecordGetCbeffProductId(HFIRecord hRecord, NUInt * pValue);
NResult N_API FIRecordSetCbeffProductId(HFIRecord hRecord, NUInt value);
NResult N_API FIRecordGetCaptureDeviceId(HFIRecord hRecord, NUShort * pValue);
NResult N_API FIRecordSetCaptureDeviceId(HFIRecord hRecord, NUShort value);
NResult N_API FIRecordGetImageAcquisitionLevel(HFIRecord hRecord, NUShort * pValue);
NResult N_API FIRecordSetImageAcquisitionLevel(HFIRecord hRecord, NUShort value);
NResult N_API FIRecordGetScaleUnits(HFIRecord hRecord, BdifScaleUnits * pValue);
NResult N_API FIRecordSetScaleUnits(HFIRecord hRecord, BdifScaleUnits value);
NResult N_API FIRecordGetHorzScanResolution(HFIRecord hRecord, NUShort * pValue);
NResult N_API FIRecordSetHorzScanResolution(HFIRecord hRecord, NUShort value);
NResult N_API FIRecordGetVertScanResolution(HFIRecord hRecord, NUShort * pValue);
NResult N_API FIRecordSetVertScanResolution(HFIRecord hRecord, NUShort value);
NResult N_API FIRecordGetHorzImageResolution(HFIRecord hRecord, NUShort * pValue);
NResult N_API FIRecordSetHorzImageResolution(HFIRecord hRecord, NUShort value);
NResult N_API FIRecordGetVertImageResolution(HFIRecord hRecord, NUShort * pValue);
NResult N_API FIRecordSetVertImageResolution(HFIRecord hRecord, NUShort value);
NResult N_API FIRecordGetPixelDepth(HFIRecord hRecord, NByte * pValue);
NResult N_API FIRecordSetPixelDepth(HFIRecord hRecord, NByte value);
NResult N_API FIRecordGetImageCompressionAlgorithm(HFIRecord hRecord, FirImageCompressionAlgorithm * pValue);
NResult N_API FIRecordSetImageCompressionAlgorithm(HFIRecord hRecord, FirImageCompressionAlgorithm value);

#define FIRecordRemoveFingerView(hRecord, index) FIRecordRemoveFingerViewAt(hRecord, index)
#define FIRecordGetFingerViewEx(hRecord, index, phValue) FIRecordGetFingerView(hRecord, index, phValue)

#ifdef N_MSVC
	#pragma deprecated("FIRecordGetFingerViewEx")
	#pragma deprecated("FIRecordRemoveFingerView")
#endif

#ifdef N_CPP
}
#endif

#endif // !FI_RECORD_H_INCLUDED
