#ifndef AN_TYPE_9_RECORD_H_INCLUDED
#define AN_TYPE_9_RECORD_H_INCLUDED

#include <Biometrics/Standards/ANAsciiRecord.h>
#include <Biometrics/Standards/BdifTypes.h>
#include <Biometrics/NFRecord.h>

#ifdef N_CPP
extern "C"
{
#endif

N_DECLARE_OBJECT_TYPE(ANType9Record, ANAsciiRecord)

#define AN_TYPE_9_RECORD_FIELD_LEN AN_RECORD_FIELD_LEN
#define AN_TYPE_9_RECORD_FIELD_IDC AN_RECORD_FIELD_IDC

#define AN_TYPE_9_RECORD_FIELD_IMP 3
#define AN_TYPE_9_RECORD_FIELD_FMT 4

#define AN_TYPE_9_RECORD_FIELD_OFR  5
#define AN_TYPE_9_RECORD_FIELD_FGP  6
#define AN_TYPE_9_RECORD_FIELD_FPC  7
#define AN_TYPE_9_RECORD_FIELD_CRP  8
#define AN_TYPE_9_RECORD_FIELD_DLT  9
#define AN_TYPE_9_RECORD_FIELD_MIN 10
#define AN_TYPE_9_RECORD_FIELD_RDG 11
#define AN_TYPE_9_RECORD_FIELD_MRC 12

#define AN_TYPE_9_RECORD_FIELD_ALL_FROM AN_TYPE_9_RECORD_FIELD_LEN
#define AN_TYPE_9_RECORD_FIELD_ALL_TO   AN_TYPE_9_RECORD_FIELD_FMT

#define AN_TYPE_9_RECORD_FIELD_STANDARD_FORMAT_FEATURES_FROM AN_TYPE_9_RECORD_FIELD_OFR
#define AN_TYPE_9_RECORD_FIELD_STANDARD_FORMAT_FEATURES_TO   AN_TYPE_9_RECORD_FIELD_MRC

#define AN_TYPE_9_RECORD_FIELD_VENDOR_DEFINED_FEATURES_FROM (AN_TYPE_9_RECORD_FIELD_MRC + 1)
#define AN_TYPE_9_RECORD_FIELD_VENDOR_DEFINED_FEATURES_TO   AN_ASCII_RECORD_MAX_FIELD_NUMBER

#define AN_TYPE_9_RECORD_MAX_FINGERPRINT_X  4999
#define AN_TYPE_9_RECORD_MAX_FINGERPRINT_Y  4999
#define AN_TYPE_9_RECORD_MAX_PALMPRINT_X   13999
#define AN_TYPE_9_RECORD_MAX_PALMPRINT_Y   20999

#define AN_TYPE_9_RECORD_MINUTIA_QUALITY_MANUAL         0
#define AN_TYPE_9_RECORD_MINUTIA_QUALITY_NOT_AVAILABLE  1
#define AN_TYPE_9_RECORD_MINUTIA_QUALITY_BEST           2
#define AN_TYPE_9_RECORD_MINUTIA_QUALITY_WORST         63

typedef enum ANFPMinutiaeMethod_
{
	anfpmmUnspecified = 0,
	anfpmmAutomatic = 1,
	anfpmmNotEdited = 2,
	anfpmmEdited = 3,
	anfpmmManual = 4
} ANFPMinutiaeMethod;

N_DECLARE_TYPE(ANFPMinutiaeMethod)

struct ANOfrs_
{
	HNString hName;
	ANFPMinutiaeMethod method;
	HNString hEquipment;
};
#ifndef AN_TYPE_9_RECORD_HPP_INCLUDED
typedef struct ANOfrs_ ANOfrs;
#endif

N_DECLARE_TYPE(ANOfrs)

struct ANFPatternClass_
{
	BdifFPatternClass value;
	HNString hVendorValue;
};
#ifndef AN_TYPE_9_RECORD_HPP_INCLUDED
typedef struct ANFPatternClass_ ANFPatternClass;
#endif

N_DECLARE_TYPE(ANFPatternClass)

struct ANFCore_
{
	NUShort X;
	NUShort Y;
};
#ifndef AN_TYPE_9_RECORD_HPP_INCLUDED
typedef struct ANFCore_ ANFCore;
#endif

N_DECLARE_TYPE(ANFCore)

struct ANFDelta_
{
	NUShort X;
	NUShort Y;
};
#ifndef AN_TYPE_9_RECORD_HPP_INCLUDED
typedef struct ANFDelta_ ANFDelta;
#endif

N_DECLARE_TYPE(ANFDelta)

struct ANFPMinutia_
{
	NUInt X;
	NUInt Y;
	NUShort Theta;
	NByte Quality;
	BdifFPMinutiaType Type;
};
#ifndef AN_TYPE_9_RECORD_HPP_INCLUDED
typedef struct ANFPMinutia_ ANFPMinutia;
#endif

N_DECLARE_TYPE(ANFPMinutia)

NResult N_API ANOfrsCreateN(HNString hName, ANFPMinutiaeMethod method, HNString hEquipment, struct ANOfrs_ * pValue);
#ifndef N_NO_ANSI_FUNC
NResult N_API ANOfrsCreateA(const NAChar * szName, ANFPMinutiaeMethod method, const NAChar * szEquipment, struct ANOfrs_ * pValue);
#endif
#ifndef N_NO_UNICODE
NResult N_API ANOfrsCreateW(const NWChar * szName, ANFPMinutiaeMethod method, const NWChar * szEquipment, struct ANOfrs_ * pValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API ANOfrsCreate(const NChar * szName, ANFPMinutiaeMethod method, const NChar * szEquipment, ANOfrs * pValue);
#endif
#define ANOfrsCreate N_FUNC_AW(ANOfrsCreate)

NResult N_API ANOfrsDispose(struct ANOfrs_ * pValue);
NResult N_API ANOfrsCopy(const struct ANOfrs_ * pSrcValue, struct ANOfrs_ * pDstValue);
NResult N_API ANOfrsSet(const struct ANOfrs_ * pSrcValue, struct ANOfrs_ * pDstValue);

NResult N_API ANFPatternClassCreateN(BdifFPatternClass value, HNString hVendorValue, struct ANFPatternClass_ * pValue);
#ifndef N_NO_ANSI_FUNC
NResult N_API ANFPatternClassCreateA(BdifFPatternClass value, const NAChar * szVendorValue, struct ANFPatternClass_ * pValue);
#endif
#ifndef N_NO_UNICODE
NResult N_API ANFPatternClassCreateW(BdifFPatternClass value, const NWChar * szVendorValue, struct ANFPatternClass_ * pValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API ANFPatternClassCreate(BdifFPatternClass value, const NChar * szVendorValue, ANFPatternClass * pValue);
#endif
#define ANFPatternClassCreate N_FUNC_AW(ANFPatternClassCreate)

NResult N_API ANFPatternClassDispose(struct ANFPatternClass_ * pValue);
NResult N_API ANFPatternClassCopy(const struct ANFPatternClass_ * pSrcValue, struct ANFPatternClass_ * pDstValue);
NResult N_API ANFPatternClassSet(const struct ANFPatternClass_ * pSrcValue, struct ANFPatternClass_ * pDstValue);

NResult N_API ANType9RecordGetPositionCount(HANType9Record hRecord, NInt * pValue);
NResult N_API ANType9RecordGetPosition(HANType9Record hRecord, NInt index, BdifFPPosition * pValue);
N_DEPRECATED("function is deprecated, use ANType9RecordGetPositions instead")
NResult N_API ANType9RecordGetPositionsEx(HANType9Record hRecord, BdifFPPosition * arValue, NInt valueLength);
NResult N_API ANType9RecordGetPositions(HANType9Record hRecord, BdifFPPosition * * parValues, NInt * pValueCount);
NResult N_API ANType9RecordSetPosition(HANType9Record hRecord, NInt index, BdifFPPosition value);
N_DEPRECATED("function is deprecated, use ANType9RecordAddPositionEx instead")
NResult N_API ANType9RecordAddPosition(HANType9Record hRecord, BdifFPPosition value);
NResult N_API ANType9RecordAddPositionEx(HANType9Record hRecord, BdifFPPosition value, NInt * pIndex);
NResult N_API ANType9RecordInsertPosition(HANType9Record hRecord, NInt index, BdifFPPosition value);
N_DEPRECATED("function is deprecated, use ANType9RecordRemovePositionAt instead")
NResult N_API ANType9RecordRemovePosition(HANType9Record hRecord, NInt index);
NResult N_API ANType9RecordRemovePositionAt(HANType9Record hRecord, NInt index);
NResult N_API ANType9RecordClearPositions(HANType9Record hRecord);

NResult N_API ANType9RecordGetPatternClassCount(HANType9Record hRecord, NInt * pValue);
NResult N_API ANType9RecordGetPatternClass(HANType9Record hRecord, NInt index, struct ANFPatternClass_ * pValue);
NResult N_API ANType9RecordSetPatternClass(HANType9Record hRecord, NInt index, const struct ANFPatternClass_ * pValue);
N_DEPRECATED("function is deprecated, use ANType9RecordAddPatternClassEx instead")
NResult N_API ANType9RecordAddPatternClass(HANType9Record hRecord, const struct ANFPatternClass_ * pValue);
NResult N_API ANType9RecordAddPatternClassEx(HANType9Record hRecord, const struct ANFPatternClass_ * pValue, NInt * pIndex);
NResult N_API ANType9RecordInsertPatternClass(HANType9Record hRecord, NInt index, const struct ANFPatternClass_ * pValue);
N_DEPRECATED("function is deprecated, use ANType9RecordRemovePatternClassAt instead")
NResult N_API ANType9RecordRemovePatternClass(HANType9Record hRecord, NInt index);
NResult N_API ANType9RecordRemovePatternClassAt(HANType9Record hRecord, NInt index);
NResult N_API ANType9RecordClearPatternClasses(HANType9Record hRecord);

NResult N_API ANType9RecordGetCoreCount(HANType9Record hRecord, NInt * pValue);
NResult N_API ANType9RecordGetCore(HANType9Record hRecord, NInt index, struct ANFCore_ * pValue);
N_DEPRECATED("function is deprecated, use ANType9RecordGetCores instead")
NResult N_API ANType9RecordGetCoresEx(HANType9Record hRecord, struct ANFCore_ * arValue, NInt valueLength);
NResult N_API ANType9RecordGetCores(HANType9Record hRecord, struct ANFCore_ * * parValues, NInt * pValueCount);
NResult N_API ANType9RecordSetCore(HANType9Record hRecord, NInt index, const struct ANFCore_ * pValue);
N_DEPRECATED("function is deprecated, use ANType9RecordAddCoreEx instead")
NResult N_API ANType9RecordAddCore(HANType9Record hRecord, const struct ANFCore_ * pValue);
NResult N_API ANType9RecordAddCoreEx(HANType9Record hRecord, const struct ANFCore_ * pValue, NInt * pIndex);
NResult N_API ANType9RecordInsertCore(HANType9Record hRecord, NInt index, const struct ANFCore_ * pValue);
N_DEPRECATED("function is deprecated, use ANType9RecordRemoveCoreAt instead")
NResult N_API ANType9RecordRemoveCore(HANType9Record hRecord, NInt index);
NResult N_API ANType9RecordRemoveCoreAt(HANType9Record hRecord, NInt index);
NResult N_API ANType9RecordClearCores(HANType9Record hRecord);

NResult N_API ANType9RecordGetDeltaCount(HANType9Record hRecord, NInt * pValue);
NResult N_API ANType9RecordGetDelta(HANType9Record hRecord, NInt index, struct ANFDelta_ * pValue);
N_DEPRECATED("function is deprecated, use ANType9RecordGetDeltas instead")
NResult N_API ANType9RecordGetDeltasEx(HANType9Record hRecord, struct ANFDelta_ * arValue, NInt valueLength);
NResult N_API ANType9RecordGetDeltas(HANType9Record hRecord, struct ANFDelta_ * * parValues, NInt * pValueCount);
NResult N_API ANType9RecordSetDelta(HANType9Record hRecord, NInt index, const struct ANFDelta_ * pValue);
N_DEPRECATED("function is deprecated, use ANType9RecordAddDeltaEx instead")
NResult N_API ANType9RecordAddDelta(HANType9Record hRecord, const struct ANFDelta_ * pValue);
NResult N_API ANType9RecordAddDeltaEx(HANType9Record hRecord, const struct ANFDelta_ * pValue, NInt * pIndex);
NResult N_API ANType9RecordInsertDelta(HANType9Record hRecord, NInt index, const struct ANFDelta_ * pValue);
N_DEPRECATED("function is deprecated, use ANType9RecordRemoveDeltaAt instead")
NResult N_API ANType9RecordRemoveDelta(HANType9Record hRecord, NInt index);
NResult N_API ANType9RecordRemoveDeltaAt(HANType9Record hRecord, NInt index);
NResult N_API ANType9RecordClearDeltas(HANType9Record hRecord);

NResult N_API ANType9RecordGetMinutiaCount(HANType9Record hRecord, NInt * pValue);
NResult N_API ANType9RecordGetMinutia(HANType9Record hRecord, NInt index, struct ANFPMinutia_ * pValue);
N_DEPRECATED("function is deprecated, use ANType9RecordGetMinutiae instead")
NResult N_API ANType9RecordGetMinutiaeEx(HANType9Record hRecord, struct ANFPMinutia_ * arValue, NInt valueLength);
NResult N_API ANType9RecordGetMinutiae(HANType9Record hRecord, struct ANFPMinutia_ * * parValues, NInt * pValueCount);
NResult N_API ANType9RecordSetMinutia(HANType9Record hRecord, NInt index, const struct ANFPMinutia_ * pValue);
N_DEPRECATED("function is deprecated, use ANType9RecordAddMinutiaEx instead")
NResult N_API ANType9RecordAddMinutia(HANType9Record hRecord, const struct ANFPMinutia_ * pValue);
NResult N_API ANType9RecordAddMinutiaEx(HANType9Record hRecord, const struct ANFPMinutia_ * pValue, NInt * pIndex);
NResult N_API ANType9RecordInsertMinutia(HANType9Record hRecord, NInt index, const struct ANFPMinutia_ * pValue);
N_DEPRECATED("function is deprecated, use ANType9RecordRemoveMinutiaAt instead")
NResult N_API ANType9RecordRemoveMinutia(HANType9Record hRecord, NInt index);
NResult N_API ANType9RecordRemoveMinutiaAt(HANType9Record hRecord, NInt index);
NResult N_API ANType9RecordClearMinutiae(HANType9Record hRecord);

NResult N_API ANType9RecordGetMinutiaNeighborCount(HANType9Record hRecord, NInt minutiaIndex, NInt * pValue);
NResult N_API ANType9RecordGetMinutiaNeighbor(HANType9Record hRecord, NInt minutiaIndex, NInt index, struct BdifFPMinutiaNeighbor_ * pValue);
N_DEPRECATED("function is deprecated, use ANType9RecordGetMinutiaNeighbors instead")
NResult N_API ANType9RecordGetMinutiaNeighborsEx(HANType9Record hRecord, NInt minutiaIndex, struct BdifFPMinutiaNeighbor_ * arValue, NInt valueLength);
NResult N_API ANType9RecordGetMinutiaNeighbors(HANType9Record hRecord, NInt minutiaIndex, struct BdifFPMinutiaNeighbor_ * * parValues, NInt * pValueCount);
NResult N_API ANType9RecordSetMinutiaNeighbor(HANType9Record hRecord, NInt minutiaIndex, NInt index, const struct BdifFPMinutiaNeighbor_ * pValue);
N_DEPRECATED("function is deprecated, use ANType9RecordAddMinutiaNeighborEx instead")
NResult N_API ANType9RecordAddMinutiaNeighbor(HANType9Record hRecord, NInt minutiaIndex, const struct BdifFPMinutiaNeighbor_ * pValue);
NResult N_API ANType9RecordAddMinutiaNeighborEx(HANType9Record hRecord, NInt minutiaIndex, const struct BdifFPMinutiaNeighbor_ * pValue, NInt * pIndex);
NResult N_API ANType9RecordInsertMinutiaNeighbor(HANType9Record hRecord, NInt minutiaIndex, NInt index, const struct BdifFPMinutiaNeighbor_ * pValue);
N_DEPRECATED("function is deprecated, use ANType9RecordRemoveMinutiaNeighborAt instead")
NResult N_API ANType9RecordRemoveMinutiaNeighbor(HANType9Record hRecord, NInt minutiaIndex, NInt index);
NResult N_API ANType9RecordRemoveMinutiaNeighborAt(HANType9Record hRecord, NInt minutiaIndex, NInt index);
NResult N_API ANType9RecordClearMinutiaNeighbors(HANType9Record hRecord, NInt minutiaIndex);

NResult N_API ANType9RecordToNFRecord(HANType9Record hRecord, NUInt flags, HNFRecord * phNFRecord);

NResult N_API ANType9RecordGetImpressionType(HANType9Record hRecord, BdifFPImpressionType * pValue);
NResult N_API ANType9RecordSetImpressionType(HANType9Record hRecord, BdifFPImpressionType value);
NResult N_API ANType9RecordGetMinutiaeFormat(HANType9Record hRecord, NBool * pValue);
NResult N_API ANType9RecordHasMinutiae(HANType9Record hRecord, NBool * pValue);
NResult N_API ANType9RecordHasMinutiaeRidgeCounts(HANType9Record hRecord, NBool * pValue);
NResult N_API ANType9RecordHasMinutiaeRidgeCountsIndicator(HANType9Record hRecord, NBool * pValue);
NResult N_API ANType9RecordGetOfrs(HANType9Record hRecord, struct ANOfrs_ * pValue, NBool * pHasValue);
NResult N_API ANType9RecordGetOfrsNameN(HANType9Record hRecord, HNString * phValue);
NResult N_API ANType9RecordGetOfrsMethod(HANType9Record hRecord, ANFPMinutiaeMethod * pValue);
NResult N_API ANType9RecordGetOfrsEquipmentN(HANType9Record hRecord, HNString * phValue);
NResult N_API ANType9RecordSetOfrsEx(HANType9Record hRecord, const struct ANOfrs_ * pValue);

NResult N_API ANType9RecordSetOfrsN(HANType9Record hRecord, HNString hName, ANFPMinutiaeMethod method, HNString hEquipment);
#ifndef N_NO_ANSI_FUNC
NResult N_API ANType9RecordSetOfrsA(HANType9Record hRecord, const NAChar * szName, ANFPMinutiaeMethod method, const NAChar * szEquipment);
#endif
#ifndef N_NO_UNICODE
NResult N_API ANType9RecordSetOfrsW(HANType9Record hRecord, const NWChar * szName, ANFPMinutiaeMethod method, const NWChar * szEquipment);
#endif
#ifdef N_DOCUMENTATION
NResult N_API ANType9RecordSetOfrs(HANType9Record hRecord, const NChar * szName, ANFPMinutiaeMethod method, const NChar * szEquipment);
#endif
#define ANType9RecordSetOfrs N_FUNC_AW(ANType9RecordSetOfrs)

#ifdef N_CPP
}
#endif

#endif // !AN_TYPE_9_RECORD_H_INCLUDED
