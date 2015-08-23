#ifndef FMR_FINGER_VIEW_H_INCLUDED
#define FMR_FINGER_VIEW_H_INCLUDED

#include <Biometrics/Standards/BdifTypes.h>
#include <Biometrics/NFRecord.h>
#include <Core/NDateTime.h>

#ifdef N_CPP
extern "C"
{
#endif

N_DECLARE_OBJECT_TYPE(FmrFingerView, NObject)

#ifdef N_CPP
}
#endif

#include <Biometrics/Standards/FMRecord.h>
#include <Biometrics/Standards/FmrFinger.h>

#ifdef N_CPP
extern "C"
{
#endif

#define FMRFV_MAX_DIMENSION 16383
#define FMRFV_MAX_MINUTIA_COUNT 255
#define FMRFV_MAX_CORE_COUNT 15
#define FMRFV_MAX_DELTA_COUNT 15

struct FmrMinutia_
{
	NUShort X;
	NUShort Y;
	BdifFPMinutiaType Type;
	NByte Angle;
	NByte Quality;
};
#ifndef FMR_FINGER_VIEW_HPP_INCLUDED
typedef struct FmrMinutia_ FmrMinutia;
#endif

N_DECLARE_TYPE(FmrMinutia)

NResult N_API FmrMinutiaToStringN(const struct FmrMinutia_ * pValue, HNString hFormat, HNString * phValue);
NResult N_API FmrMinutiaToStringA(const struct FmrMinutia_ * pValue, const NAChar * szFormat, HNString * phValue);
#ifndef N_NO_UNICODE
NResult N_API FmrMinutiaToStringW(const struct FmrMinutia_ * pValue, const NWChar * szFormat, HNString * phValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API FmrMinutiaToString(const FmrMinutia * pValue, const NChar * szFormat, HNString * phValue);
#endif
#define FmrMinutiaToString N_FUNC_AW(FmrMinutiaToString)

struct FmrCore_
{
	NUShort X;
	NUShort Y;
	NInt Angle;
};
#ifndef FMR_FINGER_VIEW_HPP_INCLUDED
typedef struct FmrCore_ FmrCore;
#endif

N_DECLARE_TYPE(FmrCore)

NResult N_API FmrCoreToStringN(const struct FmrCore_ * pValue, HNString hFormat, HNString * phValue);
NResult N_API FmrCoreToStringA(const struct FmrCore_ * pValue, const NAChar * szFormat, HNString * phValue);
#ifndef N_NO_UNICODE
NResult N_API FmrCoreToStringW(const struct FmrCore_ * pValue, const NWChar * szFormat, HNString * phValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API FmrCoreToString(const FmrCore * pValue, const NChar * szFormat, HNString * phValue);
#endif
#define FmrCoreToString N_FUNC_AW(FmrCoreToString)

struct FmrDelta_
{
	NUShort X;
	NUShort Y;
	NInt Angle1;
	NInt Angle2;
	NInt Angle3;
};
#ifndef FMR_FINGER_VIEW_HPP_INCLUDED
typedef struct FmrDelta_ FmrDelta;
#endif

N_DECLARE_TYPE(FmrDelta)

NResult N_API FmrDeltaToStringN(const struct FmrDelta_ * pValue, HNString hFormat, HNString * phValue);
NResult N_API FmrDeltaToStringA(const struct FmrDelta_ * pValue, const NAChar * szFormat, HNString * phValue);
#ifndef N_NO_UNICODE
NResult N_API FmrDeltaToStringW(const struct FmrDelta_ * pValue, const NWChar * szFormat, HNString * phValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API FmrDeltaToString(const FmrDelta * pValue, const NChar * szFormat, HNString * phValue);
#endif
#define FmrDeltaToString N_FUNC_AW(FmrDeltaToString)

N_DEPRECATED("function is deprecated, use FmrFingerViewGetSize instead")
NResult N_API FmrFingerViewGetMaxSize(BdifStandard standard, NInt minutiaCount, NBool hasFourNeighborRidgeCounts, NBool hasEightNeighborRidgeCounts,
	NInt coreWithAngleCount, NInt coreCount, NInt deltaWithAngleCount, NInt deltaCount, NSizeType * pSize);
N_DEPRECATED("function is deprecated, use FmrFingerViewGetSize instead")
NResult N_API FmrFingerViewGetMaxSizeEx(BdifStandard standard, NInt minutiaCount, NBool hasFourNeighborRidgeCounts, NBool hasEightNeighborRidgeCounts,
	NInt coreWithAngleCount, NInt coreCount, NInt deltaWithAngleCount, NInt deltaCount,
	NBool hasNeurotecCurvatures, NBool hasNeurotecGs, NInt neurotecBOWidth, NInt neurotecBOHeight, NSizeType * pSize);

#define FMRFV_SKIP_RIDGE_COUNTS         NFR_SKIP_RIDGE_COUNTS
#define FMRFV_SKIP_SINGULAR_POINTS      NFR_SKIP_SINGULAR_POINTS
#define FMRFV_PROCESS_ALL_EXTENDED_DATA 0x01000000
#define FMRFV_OLD_CONVERT               0x20000000
#define FMRFV_SKIP_NEUROTEC_FIELDS      0x40000000
#define FMRFV_USE_NEUROTEC_FIELDS       0x80000000

#define FMRFV_NEIGHBOR_MINUTIA_NOT_AVAILABLE -1
#define FMRFV_RIDGE_COUNT_NOT_AVAILABLE      255

NResult N_API FmrFingerViewCreate(BdifStandard standard, NVersion_ version, HFmrFingerView * phFingerView);

NResult N_API FmrFingerViewGetVersion(HFmrFingerView hFingerView, NVersion_ * pValue);
NResult N_API FmrFingerViewGetStandard(HFmrFingerView hFingerView, BdifStandard * pValue);

NResult N_API FmrFingerViewGetCaptureDateAndTime(HFmrFingerView hFingerView, struct BdifCaptureDateTime_ * pValue);
NResult N_API FmrFingerViewSetCaptureDateAndTime(HFmrFingerView hFingerView, struct BdifCaptureDateTime_ value);
NResult N_API FmrFingerViewGetCaptureDeviceTechnology(HFmrFingerView hFingerView, BdifFPCaptureDeviceTechnology * pValue);
NResult N_API FmrFingerViewSetCaptureDeviceTechnology(HFmrFingerView hFingerView, BdifFPCaptureDeviceTechnology value);
NResult N_API FmrFingerViewGetCaptureDeviceVendorId(HFmrFingerView hFingerView, NUShort * pValue);
NResult N_API FmrFingerViewSetCaptureDeviceVendorId(HFmrFingerView hFingerView, NUShort value);
NResult N_API FmrFingerViewGetCaptureDeviceTypeId(HFmrFingerView hFingerView, NUShort * pValue);
NResult N_API FmrFingerViewSetCaptureDeviceTypeId(HFmrFingerView hFingerView, NUShort value);

NResult N_API FmrFingerViewGetQualityBlockCount(HFmrFingerView hFingerView, NInt * pValue);
NResult N_API FmrFingerViewGetQualityBlock(HFmrFingerView hFingerView, NInt index, struct BdifQualityBlock_ * pValue);
NResult N_API FmrFingerViewSetQualityBlock(HFmrFingerView hFingerView, NInt index, const struct BdifQualityBlock_ * pValue);
NResult N_API FmrFingerViewGetQualityBlocks(HFmrFingerView hFingerView, struct BdifQualityBlock_ * * parValues, NInt * pValueCount);
NResult N_API FmrFingerViewGetQualityBlockCapacity(HFmrFingerView hFingerView, NInt * pValue);
NResult N_API FmrFingerViewSetQualityBlockCapacity(HFmrFingerView hFingerView, NInt value);
NResult N_API FmrFingerViewAddQualityBlock(HFmrFingerView hFingerView, const struct BdifQualityBlock_ * pValue, NInt * pIndex);
NResult N_API FmrFingerViewInsertQualityBlock(HFmrFingerView hFingerView, NInt index, const struct BdifQualityBlock_ * pValue);
NResult N_API FmrFingerViewRemoveQualityBlockAt(HFmrFingerView hFingerView, NInt index);
NResult N_API FmrFingerViewClearQualityBlocks(HFmrFingerView hFingerView);

NResult N_API FmrFingerViewGetCertificationBlockCount(HFmrFingerView hFingerView, NInt * pValue);
NResult N_API FmrFingerViewGetCertificationBlock(HFmrFingerView hFingerView, NInt index, struct BdifCertificationBlock_ * pValue);
NResult N_API FmrFingerViewSetCertificationBlock(HFmrFingerView hFingerView, NInt index, const struct BdifCertificationBlock_ * pValue);
NResult N_API FmrFingerViewGetCertificationBlocks(HFmrFingerView hFingerView, struct BdifCertificationBlock_ * * parValues, NInt * pValueCount);
NResult N_API FmrFingerViewGetCertificationBlockCapacity(HFmrFingerView hFingerView, NInt * pValue);
NResult N_API FmrFingerViewSetCertificationBlockCapacity(HFmrFingerView hFingerView, NInt value);
NResult N_API FmrFingerViewAddCertificationBlock(HFmrFingerView hFingerView, const struct BdifCertificationBlock_ * pValue, NInt * pIndex);
NResult N_API FmrFingerViewInsertCertificationBlock(HFmrFingerView hFingerView, NInt index, const struct BdifCertificationBlock_ * pValue);
NResult N_API FmrFingerViewRemoveCertificationBlockAt(HFmrFingerView hFingerView, NInt index);
NResult N_API FmrFingerViewClearCertificationBlocks(HFmrFingerView hFingerView);

NResult N_API FmrFingerViewGetMinutiaCount(HFmrFingerView hFingerView, NInt * pValue);
NResult N_API FmrFingerViewGetMinutia(HFmrFingerView hFingerView, NInt index, struct FmrMinutia_ * pValue);
NResult N_API FmrFingerViewSetMinutia(HFmrFingerView hFingerView, NInt index, const struct FmrMinutia_ * pValue);
N_DEPRECATED("function is deprecated, use FmrFingerViewGetMinutiae instead")
NResult N_API FmrFingerViewGetMinutiaeEx(HFmrFingerView hFingerView, struct FmrMinutia_ * arValue, NInt valueLength);
NResult N_API FmrFingerViewGetMinutiae(HFmrFingerView hFingerView, struct FmrMinutia_ * * parValues, NInt * pValueCount);
NResult N_API FmrFingerViewGetMinutiaCapacity(HFmrFingerView hFingerView, NInt * pValue);
NResult N_API FmrFingerViewSetMinutiaCapacity(HFmrFingerView hFingerView, NInt value);
N_DEPRECATED("function is deprecated, use FmrFingerViewAddMinutiaEx instead")
NResult N_API FmrFingerViewAddMinutia(HFmrFingerView hFingerView, const struct FmrMinutia_ * pValue);
NResult N_API FmrFingerViewAddMinutiaEx(HFmrFingerView hFingerView, const struct FmrMinutia_ * pValue, NInt * pIndex);
NResult N_API FmrFingerViewInsertMinutia(HFmrFingerView hFingerView, NInt index, const struct FmrMinutia_ * pValue);
N_DEPRECATED("function is deprecated, use FmrFingerViewRemoveMinutiaAt instead")
NResult N_API FmrFingerViewRemoveMinutia(HFmrFingerView hFingerView, NInt index);
NResult N_API FmrFingerViewRemoveMinutiaAt(HFmrFingerView hFingerView, NInt index);
NResult N_API FmrFingerViewClearMinutiae(HFmrFingerView hFingerView);

NResult N_API FmrFingerViewGetMinutiaFourNeighbor(HFmrFingerView hFingerView, NInt minutiaIndex, NInt index, struct BdifFPMinutiaNeighbor_ * pValue);
NResult N_API FmrFingerViewSetMinutiaFourNeighbor(HFmrFingerView hFingerView, NInt minutiaIndex, NInt index, const struct BdifFPMinutiaNeighbor_ * pValue);
N_DEPRECATED("function is deprecated, use FmrFingerViewGetMinutiaFourNeighbors instead")
NResult N_API FmrFingerViewGetMinutiaFourNeighborsEx(HFmrFingerView hFingerView, NInt minutiaIndex, struct BdifFPMinutiaNeighbor_ * arValue, NInt valueLength);
NResult N_API FmrFingerViewGetMinutiaFourNeighbors(HFmrFingerView hFingerView, NInt minutiaIndex, struct BdifFPMinutiaNeighbor_ * * parValues, NInt * pValueCount);

NResult N_API FmrFingerViewGetMinutiaEightNeighbor(HFmrFingerView hFingerView, NInt minutiaIndex, NInt index, struct BdifFPMinutiaNeighbor_ * pValue);
NResult N_API FmrFingerViewSetMinutiaEightNeighbor(HFmrFingerView hFingerView, NInt minutiaIndex, NInt index, const struct BdifFPMinutiaNeighbor_ * pValue);
N_DEPRECATED("function is deprecated, use FmrFingerViewGetMinutiaEightNeighbors instead")
NResult N_API FmrFingerViewGetMinutiaEightNeighborsEx(HFmrFingerView hFingerView, NInt minutiaIndex, struct BdifFPMinutiaNeighbor_ * arValue, NInt valueLength);
NResult N_API FmrFingerViewGetMinutiaEightNeighbors(HFmrFingerView hFingerView, NInt minutiaIndex, struct BdifFPMinutiaNeighbor_ * * parValues, NInt * pValueCount);

NResult N_API FmrFingerViewGetCoreCount(HFmrFingerView hFingerView, NInt * pValue);
NResult N_API FmrFingerViewGetCore(HFmrFingerView hFingerView, NInt index, struct FmrCore_ * pValue);
NResult N_API FmrFingerViewSetCore(HFmrFingerView hFingerView, NInt index, const struct FmrCore_ * pValue);
N_DEPRECATED("function is deprecated, use FmrFingerViewGetCores instead")
NResult N_API FmrFingerViewGetCoresEx(HFmrFingerView hFingerView, struct FmrCore_ * arValue, NInt valueLength);
NResult N_API FmrFingerViewGetCores(HFmrFingerView hFingerView, struct FmrCore_ * * parValues, NInt * pValueCount);
NResult N_API FmrFingerViewGetCoreCapacity(HFmrFingerView hFingerView, NInt * pValue);
NResult N_API FmrFingerViewSetCoreCapacity(HFmrFingerView hFingerView, NInt value);
N_DEPRECATED("function is deprecated, use FmrFingerViewAddCoreEx instead")
NResult N_API FmrFingerViewAddCore(HFmrFingerView hFingerView, const struct FmrCore_ * pValue);
NResult N_API FmrFingerViewAddCoreEx(HFmrFingerView hFingerView, const struct FmrCore_ * pValue, NInt * pIndex);
NResult N_API FmrFingerViewInsertCore(HFmrFingerView hFingerView, NInt index, const struct FmrCore_ * pValue);
N_DEPRECATED("function is deprecated, use FmrFingerViewRemoveCoreAt instead")
NResult N_API FmrFingerViewRemoveCore(HFmrFingerView hFingerView, NInt index);
NResult N_API FmrFingerViewRemoveCoreAt(HFmrFingerView hFingerView, NInt index);
NResult N_API FmrFingerViewClearCores(HFmrFingerView hFingerView);

NResult N_API FmrFingerViewGetDeltaCount(HFmrFingerView hFingerView, NInt * pValue);
NResult N_API FmrFingerViewGetDelta(HFmrFingerView hFingerView, NInt index, struct FmrDelta_ * pValue);
NResult N_API FmrFingerViewSetDelta(HFmrFingerView hFingerView, NInt index, const struct FmrDelta_ * pValue);
N_DEPRECATED("function is deprecated, use FmrFingerViewGetDeltasinstead")
NResult N_API FmrFingerViewGetDeltasEx(HFmrFingerView hFingerView, struct FmrDelta_ * arValue, NInt valueLength);
NResult N_API FmrFingerViewGetDeltas(HFmrFingerView hFingerView, struct FmrDelta_ * * parValues, NInt * pValueCount);
NResult N_API FmrFingerViewGetDeltaCapacity(HFmrFingerView hFingerView, NInt * pValue);
NResult N_API FmrFingerViewSetDeltaCapacity(HFmrFingerView hFingerView, NInt value);
N_DEPRECATED("function is deprecated, use FmrFingerViewAddDeltaEx instead")
NResult N_API FmrFingerViewAddDelta(HFmrFingerView hFingerView, const struct FmrDelta_ * pValue);
NResult N_API FmrFingerViewAddDeltaEx(HFmrFingerView hFingerView, const struct FmrDelta_ * pValue, NInt * pIndex);
NResult N_API FmrFingerViewInsertDelta(HFmrFingerView hFingerView, NInt index, const struct FmrDelta_ * pValue);
N_DEPRECATED("function is deprecated, use FmrFingerViewRemoveDeltaAt instead")
NResult N_API FmrFingerViewRemoveDelta(HFmrFingerView hFingerView, NInt index);
NResult N_API FmrFingerViewRemoveDeltaAt(HFmrFingerView hFingerView, NInt index);
NResult N_API FmrFingerViewClearDeltas(HFmrFingerView hFingerView);

NResult N_API FmrFingerViewToNFRecord(HFmrFingerView hFingerView, NUInt flags, HNFRecord * phNFRecord);

NResult N_API FmrFingerViewGetFingerPosition(HFmrFingerView hFingerView, BdifFPPosition * pValue);
NResult N_API FmrFingerViewSetFingerPosition(HFmrFingerView hFingerView, BdifFPPosition value);

NResult N_API FmrFingerViewGetHorzImageResolution(HFmrFingerView hFingerView, NUShort * pValue);
NResult N_API FmrFingerViewSetHorzImageResolution(HFmrFingerView hFingerView, NUShort value);
NResult N_API FmrFingerViewGetVertImageResolution(HFmrFingerView hFingerView, NUShort * pValue);
NResult N_API FmrFingerViewSetVertImageResolution(HFmrFingerView hFingerView, NUShort value);
NResult N_API FmrFingerViewGetImpressionType(HFmrFingerView hFingerView, BdifFPImpressionType * pValue);
NResult N_API FmrFingerViewSetImpressionType(HFmrFingerView hFingerView, BdifFPImpressionType value);
NResult N_API FmrFingerViewGetSizeX(HFmrFingerView hFingerView, NUShort * pValue);
NResult N_API FmrFingerViewSetSizeX(HFmrFingerView hFingerView, NUShort value);
NResult N_API FmrFingerViewGetSizeY(HFmrFingerView hFingerView, NUShort * pValue);
NResult N_API FmrFingerViewSetSizeY(HFmrFingerView hFingerView, NUShort value);
NResult N_API FmrFingerViewGetMinutiaeQualityFlag(HFmrFingerView hFingerView, NBool * pValue);
NResult N_API FmrFingerViewSetMinutiaeQualityFlag(HFmrFingerView hFingerView, NBool value);
NResult N_API FmrFingerViewGetRidgeEndingType(HFmrFingerView hFingerView, BdifFPMinutiaRidgeEndingType * pValue);
NResult N_API FmrFingerViewSetRidgeEndingType(HFmrFingerView hFingerView, BdifFPMinutiaRidgeEndingType value);
N_DEPRECATED("function is deprecated")
NResult N_API FmrFingerViewGetViewCount(HFmrFingerView hFingerView, NInt * pValue);
NResult N_API FmrFingerViewGetViewNumber(HFmrFingerView hFingerView, NInt * pValue);
NResult N_API FmrFingerViewGetFingerQuality(HFmrFingerView hFingerView, NByte * pValue);
NResult N_API FmrFingerViewSetFingerQuality(HFmrFingerView hFingerView, NByte value);
NResult N_API FmrFingerViewHasFourNeighborRidgeCounts(HFmrFingerView hFingerView, NBool * pValue);
NResult N_API FmrFingerViewSetHasFourNeighborRidgeCounts(HFmrFingerView hFingerView, NBool value);
NResult N_API FmrFingerViewHasEightNeighborRidgeCounts(HFmrFingerView hFingerView, NBool * pValue);
NResult N_API FmrFingerViewSetHasEightNeighborRidgeCounts(HFmrFingerView hFingerView, NBool value);

NResult N_API FmrFingerViewValidateMinutiaeUniqueness(HFmrFingerView hFingerView, NBool * pIsUnique);

#ifdef N_CPP
}
#endif

#endif // !FMR_FINGER_VIEW_H_INCLUDED
