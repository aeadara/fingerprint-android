#ifndef AN_TYPE_1_RECORD_H_INCLUDED
#define AN_TYPE_1_RECORD_H_INCLUDED

#include <Biometrics/Standards/ANAsciiRecord.h>
#include <Core/NDateTime.h>

#ifdef N_CPP
extern "C"
{
#endif

N_DECLARE_OBJECT_TYPE(ANType1Record, ANAsciiRecord)

#define AN_TYPE_1_RECORD_FIELD_LEN AN_RECORD_FIELD_LEN

#define AN_TYPE_1_RECORD_FIELD_VER  2
#define AN_TYPE_1_RECORD_FIELD_CNT  3
#define AN_TYPE_1_RECORD_FIELD_TOT  4
#define AN_TYPE_1_RECORD_FIELD_DAT  5
#define AN_TYPE_1_RECORD_FIELD_PRY  6
#define AN_TYPE_1_RECORD_FIELD_DAI  7
#define AN_TYPE_1_RECORD_FIELD_ORI  8
#define AN_TYPE_1_RECORD_FIELD_TCN  9
#define AN_TYPE_1_RECORD_FIELD_TCR 10
#define AN_TYPE_1_RECORD_FIELD_NSR 11
#define AN_TYPE_1_RECORD_FIELD_NTR 12
#define AN_TYPE_1_RECORD_FIELD_DOM 13
#define AN_TYPE_1_RECORD_FIELD_GMT 14
#define AN_TYPE_1_RECORD_FIELD_DCS 15

#define AN_CHARSET_ASCII   0
#define AN_CHARSET_LATIN   1
#define AN_CHARSET_UNICODE 2
#define AN_CHARSET_UTF_8   3

#define AN_CHARSET_USER_DEFINED_FROM 128
#define AN_CHARSET_USER_DEFINED_TO   999

#define AN_TYPE_1_RECORD_MAX_RESOLUTION     99990
#define AN_TYPE_1_RECORD_MAX_RESOLUTION_V4 999990

#define AN_TYPE_1_RECORD_MIN_SCANNING_RESOLUTION         19690

#define AN_TYPE_1_RECORD_MIN_NATIVE_SCANNING_RESOLUTION        19490

#define AN_TYPE_1_RECORD_MIN_LOW_TRANSMITTING_RESOLUTION  9740
#define AN_TYPE_1_RECORD_MAX_LOW_TRANSMITTING_RESOLUTION 10340

#define AN_TYPE_1_RECORD_MIN_HIGH_TRANSMITTING_RESOLUTION 19490
#define AN_TYPE_1_RECORD_MAX_HIGH_TRANSMITTING_RESOLUTION 20670

#define AN_TYPE_1_RECORD_MIN_TRANSACTION_TYPE_LENGTH_V4 3
#define AN_TYPE_1_RECORD_MAX_TRANSACTION_TYPE_LENGTH_V4 4

#define AN_TYPE_1_RECORD_MAX_PRIORITY    4
#define AN_TYPE_1_RECORD_MAX_PRIORITY_V3 9

struct ANDomain_
{
	HNString hName;
	HNString hVersion;
};
#ifndef AN_TYPE_1_RECORD_HPP_INCLUDED
typedef struct ANDomain_ ANDomain;
#endif

N_DECLARE_TYPE(ANDomain)

struct ANCharset_
{
	NInt index;
	HNString hName;
	HNString hVersion;
};
#ifndef AN_TYPE_1_RECORD_HPP_INCLUDED
typedef struct ANCharset_ ANCharset;
#endif

N_DECLARE_TYPE(ANCharset)

NResult N_API ANDomainCreateN(HNString hName, HNString hVersion, struct ANDomain_ * pValue);
#ifndef N_NO_ANSI_FUNC
NResult N_API ANDomainCreateA(const NAChar * szName, const NAChar * szVersion, struct ANDomain_ * pValue);
#endif
#ifndef N_NO_UNICODE
NResult N_API ANDomainCreateW(const NWChar * szName, const NWChar * szVersion, struct ANDomain_ * pValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API ANDomainCreate(const NChar * szName, const NChar * szVersion, ANDomain * pValue);
#endif
#define ANDomainCreate N_FUNC_AW(ANDomainCreate)

NResult N_API ANDomainDispose(struct ANDomain_ * pValue);
NResult N_API ANDomainCopy(const struct ANDomain_ * pSrcValue, struct ANDomain_ * pDstValue);
NResult N_API ANDomainSet(const struct ANDomain_ * pSrcValue, struct ANDomain_ * pDstValue);

NResult N_API ANCharsetCreateN(NInt index, HNString hName, HNString hVersion, struct ANCharset_ * pValue);
#ifndef N_NO_ANSI_FUNC
NResult N_API ANCharsetCreateA(NInt index, const NAChar * szName, const NAChar * szVersion, struct ANCharset_ * pValue);
#endif
#ifndef N_NO_UNICODE
NResult N_API ANCharsetCreateW(NInt index, const NWChar * szName, const NWChar * szVersion, struct ANCharset_ * pValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API ANCharsetCreate(NInt index, const NChar * szName, const NChar * szVersion, ANCharset * pValue);
#endif
#define ANCharsetCreate N_FUNC_AW(ANCharsetCreate)

NResult N_API ANCharsetDispose(struct ANCharset_ * pValue);
NResult N_API ANCharsetCopy(const struct ANCharset_ * pSrcValue, struct ANCharset_ * pDstValue);
NResult N_API ANCharsetSet(const struct ANCharset_ * pSrcValue, struct ANCharset_ * pDstValue);

NResult N_API ANType1RecordGetStandardCharsetIndexes(NVersion_ version, NInt * arValue, NInt valueLength);

NResult N_API ANType1RecordIsCharsetKnown(NVersion_ version, NInt charsetIndex, NBool * pValue);
NResult N_API ANType1RecordIsCharsetStandard(NVersion_ version, NInt charsetIndex, NBool * pValue);
NResult N_API ANType1RecordIsCharsetUserDefined(NVersion_ version, NInt charsetIndex, NBool * pValue);

NResult N_API ANType1RecordGetStandardCharsetNameN(NVersion_ version, NInt charsetIndex, HNString * phValue);
NResult N_API ANType1RecordGetStandardCharsetDescriptionN(NVersion_ version, NInt charsetIndex, HNString * phValue);

NResult N_API ANType1RecordGetStandardCharsetIndexByNameN(NVersion_ version, HNString hName, NInt * pValue);
#ifndef N_NO_ANSI_FUNC
NResult N_API ANType1RecordGetStandardCharsetIndexByNameA(NVersion_ version, const NAChar * szName, NInt * pValue);
#endif
#ifndef N_NO_UNICODE
NResult N_API ANType1RecordGetStandardCharsetIndexByNameW(NVersion_ version, const NWChar * szName, NInt * pValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API ANType1RecordGetStandardCharsetIndexByName(NVersion version, const NChar * szName, NInt * pValue);
#endif
#define ANType1RecordGetStandardCharsetIndexByName N_FUNC_AW(ANType1RecordGetStandardCharsetIndexByName)

NResult N_API ANType1RecordGetCharsetCount(HANType1Record hRecord, NInt * pValue);
NResult N_API ANType1RecordGetCharset(HANType1Record hRecord, NInt index, struct ANCharset_ * pValue);
NResult N_API ANType1RecordSetCharset(HANType1Record hRecord, NInt index, const struct ANCharset_ * pValue);

NResult N_API ANType1RecordAddCharsetEx(HANType1Record hRecord, const struct ANCharset_ * pValue, NInt * pIndex);
NResult N_API ANType1RecordInsertCharset(HANType1Record hRecord, NInt index, const struct ANCharset_ * pValue);
N_DEPRECATED("function is deprecated, use ANType1RecordRemoveCharsetAt instead")
NResult N_API ANType1RecordRemoveCharset(HANType1Record hRecord, NInt index);
NResult N_API ANType1RecordRemoveCharsetAt(HANType1Record hRecord, NInt index);
NResult N_API ANType1RecordClearCharsets(HANType1Record hRecord);
NResult N_API ANType1RecordContainsCharset(HANType1Record hRecord, NInt charsetIndex, NBool * pValue);

NResult N_API ANType1RecordGetTransactionTypeN(HANType1Record hRecord, HNString * phValue);

NResult N_API ANType1RecordSetTransactionTypeN(HANType1Record hRecord, HNString hValue);
#ifndef N_NO_ANSI_FUNC
NResult N_API ANType1RecordSetTransactionTypeA(HANType1Record hRecord, const NAChar * szValue);
#endif
#ifndef N_NO_UNICODE
NResult N_API ANType1RecordSetTransactionTypeW(HANType1Record hRecord, const NWChar * szValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API ANType1RecordSetTransactionType(HANType1Record hRecord, const NChar * szValue);
#endif
#define ANType1RecordSetTransactionType N_FUNC_AW(ANType1RecordSetTransactionType)

NResult N_API ANType1RecordGetDate(HANType1Record hRecord, NDateTime_ * pValue);
NResult N_API ANType1RecordSetDate(HANType1Record hRecord, NDateTime_ value);

NResult N_API ANType1RecordGetPriority(HANType1Record hRecord, NInt * pValue);
NResult N_API ANType1RecordSetPriority(HANType1Record hRecord, NInt value);

NResult N_API ANType1RecordGetDestinationAgencyN(HANType1Record hRecord, HNString * phValue);

NResult N_API ANType1RecordSetDestinationAgencyN(HANType1Record hRecord, HNString hValue);
#ifndef N_NO_ANSI_FUNC
NResult N_API ANType1RecordSetDestinationAgencyA(HANType1Record hRecord, const NAChar * szValue);
#endif
#ifndef N_NO_UNICODE
NResult N_API ANType1RecordSetDestinationAgencyW(HANType1Record hRecord, const NWChar * szValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API ANType1RecordSetDestinationAgency(HANType1Record hRecord, const NChar * szValue);
#endif
#define ANType1RecordSetDestinationAgency N_FUNC_AW(ANType1RecordSetDestinationAgency)

NResult N_API ANType1RecordGetOriginatingAgencyN(HANType1Record hRecord, HNString * phValue);

NResult N_API ANType1RecordSetOriginatingAgencyN(HANType1Record hRecord, HNString hValue);
#ifndef N_NO_ANSI_FUNC
NResult N_API ANType1RecordSetOriginatingAgencyA(HANType1Record hRecord, const NAChar * szValue);
#endif
#ifndef N_NO_UNICODE
NResult N_API ANType1RecordSetOriginatingAgencyW(HANType1Record hRecord, const NWChar * szValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API ANType1RecordSetOriginatingAgency(HANType1Record hRecord, const NChar * szValue);
#endif
#define ANType1RecordSetOriginatingAgency N_FUNC_AW(ANType1RecordSetOriginatingAgency)

NResult N_API ANType1RecordGetTransactionControlN(HANType1Record hRecord, HNString * phValue);

NResult N_API ANType1RecordSetTransactionControlN(HANType1Record hRecord, HNString hValue);
#ifndef N_NO_ANSI_FUNC
NResult N_API ANType1RecordSetTransactionControlA(HANType1Record hRecord, const NAChar * szValue);
#endif
#ifndef N_NO_UNICODE
NResult N_API ANType1RecordSetTransactionControlW(HANType1Record hRecord, const NWChar * szValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API ANType1RecordSetTransactionControl(HANType1Record hRecord, const NChar * szValue);
#endif
#define ANType1RecordSetTransactionControl N_FUNC_AW(ANType1RecordSetTransactionControl)

NResult N_API ANType1RecordGetTransactionControlReferenceN(HANType1Record hRecord, HNString * phValue);

NResult N_API ANType1RecordSetTransactionControlReferenceN(HANType1Record hRecord, HNString hValue);
#ifndef N_NO_ANSI_FUNC
NResult N_API ANType1RecordSetTransactionControlReferenceA(HANType1Record hRecord, const NAChar * szValue);
#endif
#ifndef N_NO_UNICODE
NResult N_API ANType1RecordSetTransactionControlReferenceW(HANType1Record hRecord, const NWChar * szValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API ANType1RecordSetTransactionControlReference(HANType1Record hRecord, const NChar * szValue);
#endif
#define ANType1RecordSetTransactionControlReference N_FUNC_AW(ANType1RecordSetTransactionControlReference)

NResult N_API ANType1RecordGetNativeScanningResolution(HANType1Record hRecord, NUInt * pValue);
NResult N_API ANType1RecordGetNominalTransmittingResolution(HANType1Record hRecord, NUInt * pValue);

NResult N_API ANType1RecordGetDomain(HANType1Record hRecord, struct ANDomain_ * pValue, NBool * pHasValue);
NResult N_API ANType1RecordGetDomainNameN(HANType1Record hRecord, HNString * phValue);
NResult N_API ANType1RecordGetDomainVersionN(HANType1Record hRecord, HNString * phValue);
NResult N_API ANType1RecordSetDomainEx(HANType1Record hRecord, const struct ANDomain_ * pValue);

NResult N_API ANType1RecordSetDomainN(HANType1Record hRecord, HNString hName, HNString hVersion);
#ifndef N_NO_ANSI_FUNC
NResult N_API ANType1RecordSetDomainA(HANType1Record hRecord, const NAChar * szName, const NAChar * szVersion);
#endif
#ifndef N_NO_UNICODE
NResult N_API ANType1RecordSetDomainW(HANType1Record hRecord, const NWChar * szName, const NWChar * szVersion);
#endif
#ifdef N_DOCUMENTATION
NResult N_API ANType1RecordSetDomain(HANType1Record hRecord, NChar * szName, NChar * szVersion);
#endif
#define ANType1RecordSetDomain N_FUNC_AW(ANType1RecordSetDomain)

NResult N_API ANType1RecordGetGmt(HANType1Record hRecord, NDateTime_ * pValue);
NResult N_API ANType1RecordSetGmt(HANType1Record hRecord, NDateTime_ value);

#ifdef N_CPP
}
#endif

#endif // !AN_TYPE_1_RECORD_H_INCLUDED
