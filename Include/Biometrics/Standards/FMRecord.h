#ifndef FM_RECORD_H_INCLUDED
#define FM_RECORD_H_INCLUDED

#include <Biometrics/Standards/BdifTypes.h>
#include <Biometrics/NTemplate.h>

#ifdef N_CPP
extern "C"
{
#endif

N_DECLARE_OBJECT_TYPE(FMRecord, NObject)

#ifdef N_CPP
}
#endif

#include <Biometrics/Standards/FmrFinger.h>
#include <Biometrics/Standards/FmrFingerView.h>

#ifdef N_CPP
extern "C"
{
#endif

typedef enum FmrCaptureEquipmentCompliance_
{
	fmrcecNone = 0,
	fmrcecFbi = 0x80,
	fmrcecIso = 0x01
} FmrCaptureEquipmentCompliance;

N_DECLARE_TYPE(FmrCaptureEquipmentCompliance)

#define FMR_VERSION_ANSI_2_0 0x0200
#define FMR_VERSION_ANSI_3_5 0x0305
#define FMR_VERSION_ISO_2_0  0x0200
#define FMR_VERSION_ISO_3_0  0x0300

#define FMR_VERSION_ANSI_CURRENT FMR_VERSION_ANSI_3_5
#define FMR_VERSION_ISO_CURRENT  FMR_VERSION_ISO_3_0

#define FMR_MAX_FINGER_VIEW_COUNT_PER_FINGER 16
#define FMR_MAX_FINGER_COUNT 11
#define FMR_MAX_FINGER_VIEW_COUNT (FMR_MAX_FINGER_COUNT * FMR_MAX_FINGER_VIEW_COUNT_PER_FINGER)

#define FMR_MAX_FINGER_COUNT_3_0 22
#define FMR_MAX_FINGER_VIEW_COUNT_3_0 (FMR_MAX_FINGER_COUNT_3_0 * FMR_MAX_FINGER_VIEW_COUNT_PER_FINGER)

#define FMR_PROCESS_FIRST_FINGER_ONLY      0x00000100
#define FMR_PROCESS_FIRST_FINGER_VIEW_ONLY (FMR_PROCESS_FIRST_FINGER_ONLY | FMRF_PROCESS_FIRST_FINGER_VIEW_ONLY)

N_DEPRECATED("function is deprecated, use FMRecordGetSize instead")
NResult N_API FMRecordCalculateSize(BdifStandard standard, NInt fingerViewCount, const NSizeType * arFingerViewSizes, NSizeType * pSize);
N_DEPRECATED("function is deprecated, use FMRecordGetSize instead")
NResult N_API FMRecordCalculateSizeWithFingers(BdifStandard standard, NInt fingerCount, const NSizeType * arFingerSizes, NSizeType * pSize);

N_DEPRECATED("function is deprecated, use FMRecordCreateEx, FMRecordSetSizeX, FMRecordSetSizeY, FMRecordSetResolutionX, FMRecordSetResolutionY instead")
NResult N_API FMRecordCreate(NUShort sizeX, NUShort sizeY, NUShort resolutionX, NUShort resolutionY, NUInt flags, BdifStandard standard, HFMRecord * phRecord);
NResult N_API FMRecordCreateEx(BdifStandard standard, NVersion_ version, NUInt flags, HFMRecord * phRecord);
NResult N_API FMRecordCreateFromMemoryN(HNBuffer hBuffer, NUInt flags, BdifStandard standard, NSizeType * pSize, HFMRecord * phRecord);
NResult N_API FMRecordCreateFromMemory(const void * pBuffer, NSizeType bufferSize, NUInt flags, BdifStandard standard, NSizeType * pSize, HFMRecord * phRecord);
N_DEPRECATED("function is deprecated, use FMRecordCreateFromFMRecordEx instead")
NResult N_API FMRecordCreateFromFMRecord(HFMRecord hSrcRecord, NUInt flags, BdifStandard standard, HFMRecord * phRecord);
NResult N_API FMRecordCreateFromFMRecordEx(HFMRecord hSrcRecord, NUInt flags, BdifStandard standard, NVersion_ version, HFMRecord * phRecord);
N_DEPRECATED("function is deprecated, use FMRecordCreateFromNFRecordEx instead")
NResult N_API FMRecordCreateFromNFRecord(HNFRecord hNFRecord, NUInt flags, BdifStandard standard, HFMRecord * phRecord);
NResult N_API FMRecordCreateFromNFRecordEx(HNFRecord hNFRecord, NUInt flags, BdifStandard standard, NVersion_ version, HFMRecord * phRecord);
N_DEPRECATED("function is deprecated, use FMRecordCreateFromNFTemplateEx instead")
NResult N_API FMRecordCreateFromNFTemplate(HNFTemplate hNFTemplate, NUInt flags, BdifStandard standard, HFMRecord * phRecord);
NResult N_API FMRecordCreateFromNFTemplateEx(HNFTemplate hNFTemplate, NUInt flags, BdifStandard standard, NVersion_ version, HFMRecord * phRecord);

NResult N_API FMRecordToNFTemplate(HFMRecord hRecord, NUInt flags, HNFTemplate * phNFTemplate);
NResult N_API FMRecordToNTemplate(HFMRecord hRecord, NUInt flags, HNTemplate * phNTemplate);

NResult N_API FMRecordGetStandard(HFMRecord hRecord, BdifStandard * pValue);
NResult N_API FMRecordGetVersion(HFMRecord hRecord, NVersion_ * pValue);
NResult N_API FMRecordGetCbeffProductId(HFMRecord hRecord, NUInt * pValue);
NResult N_API FMRecordSetCbeffProductId(HFMRecord hRecord, NUInt value);
NResult N_API FMRecordGetCertificationFlag(HFMRecord hRecord, NBool * pValue);
NResult N_API FMRecordSetCertificationFlag(HFMRecord hRecord, NBool value);

N_DEPRECATED("function is deprecated")
NResult N_API FMRecordGetFingerCount(HFMRecord hRecord, NInt * pValue);
N_DEPRECATED("function is deprecated")
NResult N_API FMRecordGetFingerEx(HFMRecord hRecord, NInt index, HFmrFinger * phValue);
N_DEPRECATED("function is deprecated")
NResult N_API FMRecordGetFingerCapacity(HFMRecord hRecord, NInt * pValue);
N_DEPRECATED("function is deprecated")
NResult N_API FMRecordSetFingerCapacity(HFMRecord hRecord, NInt value);
N_DEPRECATED("function is deprecated")
NResult N_API FMRecordAddFinger(HFMRecord hRecord, BdifFPPosition fingerPosition, NUInt flags, HFmrFinger * phFinger);
N_DEPRECATED("function is deprecated")
NResult N_API FMRecordRemoveFinger(HFMRecord hRecord, NInt index);
N_DEPRECATED("function is deprecated")
NResult N_API FMRecordClearFingers(HFMRecord hRecord);

NResult N_API FMRecordAddFingerView(HFMRecord hRecord, HFmrFingerView hFingerView, NInt * pIndex);
NResult N_API FMRecordGetFingerViewCount(HFMRecord hRecord, NInt * pValue);
NResult N_API FMRecordGetFingerView(HFMRecord hRecord, NInt index, HFmrFingerView * phValue);
NResult N_API FMRecordGetFingerViews(HFMRecord hRecord, HFmrFingerView * * parValues, NInt * pValueCount);
NResult N_API FMRecordGetFingerViewCapacity(HFMRecord hRecord, NInt * pValue);
NResult N_API FMRecordSetFingerViewCapacity(HFMRecord hRecord, NInt value);
NResult N_API FMRecordRemoveFingerViewAt(HFMRecord hRecord, NInt index);
NResult N_API FMRecordClearFingerViews(HFMRecord hRecord);

NResult N_API FMRecordGetCaptureEquipmentCompliance(HFMRecord hRecord, FmrCaptureEquipmentCompliance * pValue);
NResult N_API FMRecordSetCaptureEquipmentCompliance(HFMRecord hRecord, FmrCaptureEquipmentCompliance value);
NResult N_API FMRecordGetCaptureEquipmentId(HFMRecord hRecord, NUShort * pValue);
NResult N_API FMRecordSetCaptureEquipmentId(HFMRecord hRecord, NUShort value);
NResult N_API FMRecordGetSizeX(HFMRecord hRecord, NUShort * pValue);
NResult N_API FMRecordSetSizeX(HFMRecord hRecord, NUShort value);
NResult N_API FMRecordGetSizeY(HFMRecord hRecord, NUShort * pValue);
NResult N_API FMRecordSetSizeY(HFMRecord hRecord, NUShort value);
NResult N_API FMRecordGetResolutionX(HFMRecord hRecord, NUShort * pValue);
NResult N_API FMRecordSetResolutionX(HFMRecord hRecord, NUShort value);
NResult N_API FMRecordGetResolutionY(HFMRecord hRecord, NUShort * pValue);
NResult N_API FMRecordSetResolutionY(HFMRecord hRecord, NUShort value);

#define FMRecordRemoveFingerView(hRecord, index) FMRecordRemoveFingerViewAt(hRecord, index);
#define FMRecordGetFingerViewEx(hRecord, index, phValue) FMRecordGetFingerView(hRecord, index, phValue);

#ifdef N_MSVC
	#pragma deprecated("FMRecordRemoveFingerView")
	#pragma deprecated("FMRecordGetFingerViewEx")
#endif

#ifdef N_CPP
}
#endif

#endif // !FM_RECORD_H_INCLUDED
