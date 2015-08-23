#ifndef NF_RECORD_H_INCLUDED
#define NF_RECORD_H_INCLUDED

#include <Core/NObject.h>
#include <Biometrics/NBiometricTypes.h>
#include <Biometrics/NBiometricEngineTypes.h>

#ifdef N_CPP
extern "C"
{
#endif

#define NFR_RESOLUTION 500

#define NFR_MAX_FINGER_DIMENSION 2047

#define NFR_MAX_FINGER_MINUTIA_COUNT     255
#define NFR_MAX_FINGER_CORE_COUNT         15
#define NFR_MAX_FINGER_DELTA_COUNT        15
#define NFR_MAX_FINGER_DOUBLE_CORE_COUNT  15

#define NFR_MAX_PALM_DIMENSION 16383

#define NFR_MAX_PALM_MINUTIA_COUNT     65535
#define NFR_MAX_PALM_CORE_COUNT          255
#define NFR_MAX_PALM_DELTA_COUNT         255
#define NFR_MAX_PALM_DOUBLE_CORE_COUNT   255

#define NFR_MAX_POSSIBLE_POSITION_COUNT 255

N_DECLARE_OBJECT_TYPE(NFRecord, NObject)

NResult N_API NFRecordGetMaxSize(NInt version, NBool isPalm, NFMinutiaFormat minutiaFormat, NInt minutiaCount, NFRidgeCountsType ridgeCountsType,
	NInt coreCount, NInt deltaCount, NInt doubleCoreCount, NInt boWidth, NInt boHeight, NSizeType * pSize);
NResult N_API NFRecordCheckN(HNBuffer hBuffer);
NResult N_API NFRecordCheck(const void * pBuffer, NSizeType bufferSize);
NResult N_API NFRecordGetSizeMemN(HNBuffer hBuffer, NSizeType * pValue);
NResult N_API NFRecordGetSizeMem(const void * pBuffer, NSizeType bufferSize, NSizeType * pValue);
NResult N_API NFRecordGetWidthMemN(HNBuffer hBuffer, NUShort * pValue);
NResult N_API NFRecordGetWidthMem(const void * pBuffer, NSizeType bufferSize, NUShort * pValue);
NResult N_API NFRecordGetHeightMemN(HNBuffer hBuffer, NUShort * pValue);
NResult N_API NFRecordGetHeightMem(const void * pBuffer, NSizeType bufferSize, NUShort * pValue);
NResult N_API NFRecordGetHorzResolutionMemN(HNBuffer hBuffer, NUShort * pValue);
NResult N_API NFRecordGetHorzResolutionMem(const void * pBuffer, NSizeType bufferSize, NUShort * pValue);
NResult N_API NFRecordGetVertResolutionMemN(HNBuffer hBuffer, NUShort * pValue);
NResult N_API NFRecordGetVertResolutionMem(const void * pBuffer, NSizeType bufferSize, NUShort * pValue);
NResult N_API NFRecordGetPositionMemN(HNBuffer hBuffer, NFPosition * pValue);
NResult N_API NFRecordGetPositionMem(const void * pBuffer, NSizeType bufferSize, NFPosition * pValue);
NResult N_API NFRecordGetImpressionTypeMemN(HNBuffer hBuffer, NFImpressionType * pValue);
NResult N_API NFRecordGetImpressionTypeMem(const void * pBuffer, NSizeType bufferSize, NFImpressionType * pValue);
NResult N_API NFRecordGetPatternClassMemN(HNBuffer hBuffer, NFPatternClass * pValue);
NResult N_API NFRecordGetPatternClassMem(const void * pBuffer, NSizeType bufferSize, NFPatternClass * pValue);
NResult N_API NFRecordGetQualityMemN(HNBuffer hBuffer, NByte * pValue);
NResult N_API NFRecordGetQualityMem(const void * pBuffer, NSizeType bufferSize, NByte * pValue);
NResult N_API NFRecordGetGMemN(HNBuffer hBuffer, NByte * pValue);
NResult N_API NFRecordGetGMem(const void * pBuffer, NSizeType bufferSize, NByte * pValue);
NResult N_API NFRecordGetCbeffProductTypeMemN(HNBuffer hBuffer, NUShort * pValue);
NResult N_API NFRecordGetCbeffProductTypeMem(const void * pBuffer, NSizeType bufferSize, NUShort * pValue);

typedef enum NFMinutiaOrder_
{
	nfmoNone = 0,
	nfmoAscending = 0x01,
	nfmoDescending = 0x02,
	nfmoCartesianXY = 0x04,
	nfmoCartesianYX = 0x08,
	nfmoAngle = 0x0C,
	nfmoPolar = 0x10,
	nfmoQuality = 0x01000000,
	nfmoMatching = 0x80000000
} NFMinutiaOrder;

N_DECLARE_TYPE(NFMinutiaOrder)

typedef enum NFMinutiaTruncationAlgorithm_
{
	nfmtaConvexHull = 0,
	nfmtaCenterOfMass = 1,
	nfmtaQualityAndCenterOfMass = 2
} NFMinutiaTruncationAlgorithm;

N_DECLARE_TYPE(NFMinutiaTruncationAlgorithm)

#define NFR_SKIP_RIDGE_COUNTS            0x00010000
#define NFR_SKIP_SINGULAR_POINTS         0x00020000
#define NFR_SKIP_BLOCKED_ORIENTS         0x00040000
#define NFR_SAVE_BLOCKED_ORIENTS         0x00040000
#define NFR_ALLOW_OUT_OF_BOUNDS_FEATURES 0x00080000
#define NFR_SKIP_QUALITIES               0x00100000
#define NFR_SKIP_CURVATURES              0x00200000
#define NFR_SKIP_GS                      0x00400000
#define NFR_SAVE_V1                      0x10000000
#define NFR_SAVE_V2                      0x20000000
#define NFR_SAVE_V3                      0x30000000

NResult N_API NFRecordCreateEx(NBool isPalm, NUShort width, NUShort height, NUShort horzResolution, NUShort vertResolution, NUInt flags, HNFRecord * phRecord);
NResult N_API NFRecordCreateFromMemoryN(HNBuffer hBuffer, NUInt flags, NSizeType * pSize, HNFRecord * phRecord);
NResult N_API NFRecordCreateFromMemory(const void * pBuffer, NSizeType bufferSize, NUInt flags, NSizeType * pSize, HNFRecord * phRecord);
NResult N_API NFRecordCreateFromNFRecord(HNFRecord hSrcRecord, NTemplateSize dstTemplateSize, NUInt flags, HNFRecord * phDstRecord);

NResult N_API NFRecordGetMinutiaCount(HNFRecord hRecord, NInt * pValue);
NResult N_API NFRecordGetMinutia(HNFRecord hRecord, NInt index, struct NFMinutia_ * pValue);
NResult N_API NFRecordSetMinutia(HNFRecord hRecord, NInt index, const struct NFMinutia_ * pValue);
N_DEPRECATED("function is deprecated, use NFRecordGetMinutiae instead")
NResult N_API NFRecordGetMinutiaeEx(HNFRecord hRecord, struct NFMinutia_ * arMinutiae, NInt valueLength);
NResult N_API NFRecordGetMinutiae(HNFRecord hRecord, struct NFMinutia_ * * parValues, NInt * pValueCount);
NResult N_API NFRecordGetMinutiaCapacity(HNFRecord hRecord, NInt * pValue);
NResult N_API NFRecordSetMinutiaCapacity(HNFRecord hRecord, NInt value);
N_DEPRECATED("function is deprecated, use NFRecordAddMinutiaEx instead")
NResult N_API NFRecordAddMinutia(HNFRecord hRecord, const struct NFMinutia_ * pValue);
NResult N_API NFRecordAddMinutiaEx(HNFRecord hRecord, const struct NFMinutia_ * pValue, NInt * pIndex);
NResult N_API NFRecordInsertMinutia(HNFRecord hRecord, NInt index, const struct NFMinutia_ * pValue);
N_DEPRECATED("function is deprecated, use NFRecordRemoveMinutiaAt instead")
NResult N_API NFRecordRemoveMinutia(HNFRecord hRecord, NInt index);
NResult N_API NFRecordRemoveMinutiaAt(HNFRecord hRecord, NInt index);
NResult N_API NFRecordClearMinutiae(HNFRecord hRecord);

NResult N_API NFRecordGetMinutiaNeighborCount(HNFRecord hRecord, NInt minutiaIndex, NInt * pValue);
NResult N_API NFRecordGetMinutiaNeighbor(HNFRecord hRecord, NInt minutiaIndex, NInt index, struct NFMinutiaNeighbor_ * pValue);
NResult N_API NFRecordSetMinutiaNeighbor(HNFRecord hRecord, NInt minutiaIndex, NInt index, const struct NFMinutiaNeighbor_ * pValue);
N_DEPRECATED("function is deprecated, use NFRecordGetMinutiaNeighbors instead")
NResult N_API NFRecordGetMinutiaNeighborsEx(HNFRecord hRecord, NInt minutiaIndex, struct NFMinutiaNeighbor_ * arMinutiaNeighbors, NInt valueLength);
NResult N_API NFRecordGetMinutiaNeighbors(HNFRecord hRecord, NInt minutiaIndex, struct NFMinutiaNeighbor_ * * parValues, NInt * pValueCount);

NResult N_API NFRecordGetCoreCount(HNFRecord hRecord, NInt * pValue);
NResult N_API NFRecordGetCore(HNFRecord hRecord, NInt index, struct NFCore_ * pValue);
NResult N_API NFRecordSetCore(HNFRecord hRecord, NInt index, const struct NFCore_ * pValue);
N_DEPRECATED("function is deprecated, use NFRecordGetCores instead")
NResult N_API NFRecordGetCoresEx(HNFRecord hRecord, struct NFCore_ * arCores, NInt valueLength);
NResult N_API NFRecordGetCores(HNFRecord hRecord, struct NFCore_ * * parValues, NInt * pValueCount);
NResult N_API NFRecordGetCoreCapacity(HNFRecord hRecord, NInt * pValue);
NResult N_API NFRecordSetCoreCapacity(HNFRecord hRecord, NInt value);
N_DEPRECATED("function is deprecated, use NFRecordAddCoreEx instead")
NResult N_API NFRecordAddCore(HNFRecord hRecord, const struct NFCore_ * pValue);
NResult N_API NFRecordAddCoreEx(HNFRecord hRecord, const struct NFCore_ * pValue, NInt * pIndex);
NResult N_API NFRecordInsertCore(HNFRecord hRecord, NInt index, const struct NFCore_ * pValue);
N_DEPRECATED("function is deprecated, use NFRecordRemoveCoreAt instead")
NResult N_API NFRecordRemoveCore(HNFRecord hRecord, NInt index);
NResult N_API NFRecordRemoveCoreAt(HNFRecord hRecord, NInt index);
NResult N_API NFRecordClearCores(HNFRecord hRecord);

NResult N_API NFRecordGetDeltaCount(HNFRecord hRecord, NInt * pValue);
NResult N_API NFRecordGetDelta(HNFRecord hRecord, NInt index, struct NFDelta_ * pValue);
NResult N_API NFRecordSetDelta(HNFRecord hRecord, NInt index, const struct NFDelta_ * pValue);
N_DEPRECATED("function is deprecated, use NFRecordGetDeltas instead")
NResult N_API NFRecordGetDeltasEx(HNFRecord hRecord, struct NFDelta_ * arDeltas, NInt valueLength);
NResult N_API NFRecordGetDeltas(HNFRecord hRecord, struct NFDelta_ * * parValues, NInt * pValueCount);
NResult N_API NFRecordGetDeltaCapacity(HNFRecord hRecord, NInt * pValue);
NResult N_API NFRecordSetDeltaCapacity(HNFRecord hRecord, NInt value);
N_DEPRECATED("function is deprecated, use NFRecordAddDeltaEx instead")
NResult N_API NFRecordAddDelta(HNFRecord hRecord, const struct NFDelta_ * pValue);
NResult N_API NFRecordAddDeltaEx(HNFRecord hRecord, const struct NFDelta_ * pValue, NInt * pIndex);
NResult N_API NFRecordInsertDelta(HNFRecord hRecord, NInt index, const struct NFDelta_ * pValue);
N_DEPRECATED("function is deprecated, use NFRecordRemoveDeltaAt instead")
NResult N_API NFRecordRemoveDelta(HNFRecord hRecord, NInt index);
NResult N_API NFRecordRemoveDeltaAt(HNFRecord hRecord, NInt index);
NResult N_API NFRecordClearDeltas(HNFRecord hRecord);

NResult N_API NFRecordGetDoubleCoreCount(HNFRecord hRecord, NInt * pValue);
NResult N_API NFRecordGetDoubleCore(HNFRecord hRecord, NInt index, struct NFDoubleCore_ * pValue);
NResult N_API NFRecordSetDoubleCore(HNFRecord hRecord, NInt index, const struct NFDoubleCore_ * pValue);
N_DEPRECATED("function is deprecated, use NFRecordGetDoubleCores instead")
NResult N_API NFRecordGetDoubleCoresEx(HNFRecord hRecord, struct NFDoubleCore_ * arDoubleCores, NInt valueLength);
NResult N_API NFRecordGetDoubleCores(HNFRecord hRecord, struct NFDoubleCore_ * * parValues, NInt * pValueCount);
NResult N_API NFRecordGetDoubleCoreCapacity(HNFRecord hRecord, NInt * pValue);
NResult N_API NFRecordSetDoubleCoreCapacity(HNFRecord hRecord, NInt value);
N_DEPRECATED("function is deprecated, use NFRecordAddDoubleCoreEx instead")
NResult N_API NFRecordAddDoubleCore(HNFRecord hRecord, const struct NFDoubleCore_ * pValue);
NResult N_API NFRecordAddDoubleCoreEx(HNFRecord hRecord, const struct NFDoubleCore_ * pValue, NInt * pIndex);
NResult N_API NFRecordInsertDoubleCore(HNFRecord hRecord, NInt index, const struct NFDoubleCore_ * pValue);
N_DEPRECATED("function is deprecated, use NFRecordRemoveDoubleCoreAt instead")
NResult N_API NFRecordRemoveDoubleCore(HNFRecord hRecord, NInt index);
NResult N_API NFRecordRemoveDoubleCoreAt(HNFRecord hRecord, NInt index);
NResult N_API NFRecordClearDoubleCores(HNFRecord hRecord);

NResult N_API NFRecordGetPossiblePositionCount(HNFRecord hRecord, NInt * pValue);
NResult N_API NFRecordGetPossiblePosition(HNFRecord hRecord, NInt index, NFPosition * pValue);
NResult N_API NFRecordSetPossiblePosition(HNFRecord hRecord, NInt index, NFPosition value);
N_DEPRECATED("function is deprecated, use NFRecordGetPossiblePositionsEx instead")
NResult N_API NFRecordGetPossiblePositions(HNFRecord hRecord, NFPosition * arValues, NInt valueLength);
NResult N_API NFRecordGetPossiblePositionsEx(HNFRecord hRecord, NFPosition * * parValues, NInt * pValueCount);
N_DEPRECATED("function is deprecated, use NFRecordAddPossiblePositionEx instead")
NResult N_API NFRecordAddPossiblePosition(HNFRecord hRecord, NFPosition value);
NResult N_API NFRecordAddPossiblePositionEx(HNFRecord hRecord, NFPosition value, NInt * pIndex);
NResult N_API NFRecordInsertPossiblePosition(HNFRecord hRecord, NInt index, NFPosition value);
N_DEPRECATED("function is deprecated, use NFRecordRemovePossiblePositionAt instead")
NResult N_API NFRecordRemovePossiblePosition(HNFRecord hRecord, NInt index);
NResult N_API NFRecordRemovePossiblePositionAt(HNFRecord hRecord, NInt index);
NResult N_API NFRecordClearPossiblePositions(HNFRecord hRecord);

NResult N_API NFRecordSortMinutiae(HNFRecord hRecord, NFMinutiaOrder order);
NResult N_API NFRecordTruncateMinutiaeByQuality(HNFRecord hRecord, NByte threshold, NInt maxCount);
NResult N_API NFRecordTruncateMinutiae(HNFRecord hRecord, NInt maxCount);
NResult N_API NFRecordTruncateMinutiaeEx(HNFRecord hRecord, NFMinutiaTruncationAlgorithm minutiaeTruncation, NInt maxCount);

NResult N_API NFRecordGetRequiresUpdate(HNFRecord hRecord, NBool * pValue);
NResult N_API NFRecordSetRequiresUpdate(HNFRecord hRecord, NBool value);
NResult N_API NFRecordGetWidth(HNFRecord hRecord, NUShort * pValue);
NResult N_API NFRecordGetHeight(HNFRecord hRecord, NUShort * pValue);
NResult N_API NFRecordGetHorzResolution(HNFRecord hRecord, NUShort * pValue);
NResult N_API NFRecordGetVertResolution(HNFRecord hRecord, NUShort * pValue);
NResult N_API NFRecordGetPosition(HNFRecord hRecord, NFPosition * pValue);
NResult N_API NFRecordSetPosition(HNFRecord hRecord, NFPosition value);
NResult N_API NFRecordGetImpressionType(HNFRecord hRecord, NFImpressionType * pValue);
NResult N_API NFRecordSetImpressionType(HNFRecord hRecord, NFImpressionType value);
NResult N_API NFRecordGetPatternClass(HNFRecord hRecord, NFPatternClass * pValue);
NResult N_API NFRecordSetPatternClass(HNFRecord hRecord, NFPatternClass value);
NResult N_API NFRecordGetQuality(HNFRecord hRecord, NByte * pValue);
NResult N_API NFRecordSetQuality(HNFRecord hRecord, NByte value);
NResult N_API NFRecordGetG(HNFRecord hRecord, NByte * pValue);
NResult N_API NFRecordSetG(HNFRecord hRecord, NByte value);
NResult N_API NFRecordGetCbeffProductType(HNFRecord hRecord, NUShort * pValue);
NResult N_API NFRecordSetCbeffProductType(HNFRecord hRecord, NUShort value);
NResult N_API NFRecordGetRidgeCountsType(HNFRecord hRecord, NFRidgeCountsType * pValue);
NResult N_API NFRecordSetRidgeCountsType(HNFRecord hRecord, NFRidgeCountsType value);
NResult N_API NFRecordGetMinutiaFormat(HNFRecord hRecord, NFMinutiaFormat * pValue);
NResult N_API NFRecordSetMinutiaFormat(HNFRecord hRecord, NFMinutiaFormat value);

#ifdef N_CPP
}
#endif

#endif // !NF_RECORD_H_INCLUDED
