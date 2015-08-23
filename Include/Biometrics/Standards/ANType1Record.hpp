#ifndef AN_TYPE_1_RECORD_HPP_INCLUDED
#define AN_TYPE_1_RECORD_HPP_INCLUDED

#include <Biometrics/Standards/ANAsciiRecord.hpp>
#include <Core/NDateTime.hpp>
namespace Neurotec {
	namespace Biometrics {
		namespace Standards
{
#include <Biometrics/Standards/ANType1Record.h>
}}}

namespace Neurotec { namespace Biometrics { namespace Standards
{

#undef AN_TYPE_1_RECORD_FIELD_LEN

#undef AN_TYPE_1_RECORD_FIELD_VER
#undef AN_TYPE_1_RECORD_FIELD_CNT
#undef AN_TYPE_1_RECORD_FIELD_TOT
#undef AN_TYPE_1_RECORD_FIELD_DAT
#undef AN_TYPE_1_RECORD_FIELD_PRY
#undef AN_TYPE_1_RECORD_FIELD_DAI
#undef AN_TYPE_1_RECORD_FIELD_ORI
#undef AN_TYPE_1_RECORD_FIELD_TCN
#undef AN_TYPE_1_RECORD_FIELD_TCR
#undef AN_TYPE_1_RECORD_FIELD_NSR
#undef AN_TYPE_1_RECORD_FIELD_NTR
#undef AN_TYPE_1_RECORD_FIELD_DOM
#undef AN_TYPE_1_RECORD_FIELD_GMT
#undef AN_TYPE_1_RECORD_FIELD_DCS

#undef AN_CHARSET_ASCII
#undef AN_CHARSET_LATIN
#undef AN_CHARSET_UNICODE
#undef AN_CHARSET_UTF_8

#undef AN_CHARSET_USER_DEFINED_FROM
#undef AN_CHARSET_USER_DEFINED_TO

#undef AN_TYPE_1_RECORD_MAX_RESOLUTION
#undef AN_TYPE_1_RECORD_MAX_RESOLUTION_V4

#undef AN_TYPE_1_RECORD_MIN_SCANNING_RESOLUTION

#undef AN_TYPE_1_RECORD_MIN_NATIVE_SCANNING_RESOLUTION

#undef AN_TYPE_1_RECORD_MIN_LOW_TRANSMITTING_RESOLUTION
#undef AN_TYPE_1_RECORD_MAX_LOW_TRANSMITTING_RESOLUTION

#undef AN_TYPE_1_RECORD_MIN_HIGH_TRANSMITTING_RESOLUTION
#undef AN_TYPE_1_RECORD_MAX_HIGH_TRANSMITTING_RESOLUTION

#undef AN_TYPE_1_RECORD_MIN_TRANSACTION_TYPE_LENGTH_V4
#undef AN_TYPE_1_RECORD_MAX_TRANSACTION_TYPE_LENGTH_V4

#undef AN_TYPE_1_RECORD_MAX_PRIORITY
#undef AN_TYPE_1_RECORD_MAX_PRIORITY_V3

const NInt AN_TYPE_1_RECORD_FIELD_LEN = AN_RECORD_FIELD_LEN;

const NInt AN_TYPE_1_RECORD_FIELD_VER = 2;
const NInt AN_TYPE_1_RECORD_FIELD_CNT = 3;
const NInt AN_TYPE_1_RECORD_FIELD_TOT = 4;
const NInt AN_TYPE_1_RECORD_FIELD_DAT = 5;
const NInt AN_TYPE_1_RECORD_FIELD_PRY = 6;
const NInt AN_TYPE_1_RECORD_FIELD_DAI = 7;
const NInt AN_TYPE_1_RECORD_FIELD_ORI = 8;
const NInt AN_TYPE_1_RECORD_FIELD_TCN = 9;
const NInt AN_TYPE_1_RECORD_FIELD_TCR = 10;
const NInt AN_TYPE_1_RECORD_FIELD_NSR = 11;
const NInt AN_TYPE_1_RECORD_FIELD_NTR = 12;
const NInt AN_TYPE_1_RECORD_FIELD_DOM = 13;
const NInt AN_TYPE_1_RECORD_FIELD_GMT = 14;
const NInt AN_TYPE_1_RECORD_FIELD_DCS = 15;

const NInt AN_CHARSET_ASCII = 0;
const NInt AN_CHARSET_LATIN = 1;
const NInt AN_CHARSET_UNICODE = 2;
const NInt AN_CHARSET_UTF_8 = 3;

const NInt AN_CHARSET_USER_DEFINED_FROM = 128;
const NInt AN_CHARSET_USER_DEFINED_TO = 999;

const NUInt AN_TYPE_1_RECORD_MAX_RESOLUTION = 99990;
const NUInt AN_TYPE_1_RECORD_MAX_RESOLUTION_V4 = 999990;

const NUInt AN_TYPE_1_RECORD_MIN_SCANNING_RESOLUTION = 19690;

const NUInt AN_TYPE_1_RECORD_MIN_NATIVE_SCANNING_RESOLUTION = 19490;

const NUInt AN_TYPE_1_RECORD_MIN_LOW_TRANSMITTING_RESOLUTION = 9740;
const NUInt AN_TYPE_1_RECORD_MAX_LOW_TRANSMITTING_RESOLUTION = 10340;

const NUInt AN_TYPE_1_RECORD_MIN_HIGH_TRANSMITTING_RESOLUTION = 19490;
const NUInt AN_TYPE_1_RECORD_MAX_HIGH_TRANSMITTING_RESOLUTION = 20670;

const NInt AN_TYPE_1_RECORD_MIN_TRANSACTION_TYPE_LENGTH_V4 = 3;
const NInt AN_TYPE_1_RECORD_MAX_TRANSACTION_TYPE_LENGTH_V4 = 4;

const NInt AN_TYPE_1_RECORD_MAX_PRIORITY = 4;
const NInt AN_TYPE_1_RECORD_MAX_PRIORITY_V3 = 9;

class ANDomain : public ANDomain_
{
	N_DECLARE_DISPOSABLE_STRUCT_CLASS(ANDomain)

public:
	ANDomain(const NStringWrapper & name, const NStringWrapper & version)
	{
		NCheck(ANDomainCreateN(name.GetHandle(), version.GetHandle(), this));
	}

	NString GetName() const
	{
		return NString(hName, false);
	}

	void SetName(const NStringWrapper & value)
	{
		NCheck(NStringSet(value.GetHandle(), &hName));
	}

	NString GetVersion() const
	{
		return NString(hVersion, false);
	}

	void SetVersion(const NStringWrapper & value)
	{
		NCheck(NStringSet(value.GetHandle(), &hVersion));
	}
};

class ANCharset : public ANCharset_
{
	N_DECLARE_DISPOSABLE_STRUCT_CLASS(ANCharset)

public:
	ANCharset(NInt index, const NStringWrapper & name, const NStringWrapper & version)
	{
		NCheck(ANCharsetCreateN(index, name.GetHandle(), version.GetHandle(), this));
	}

	NString GetName() const
	{
		return NString(hName, false);
	}

	void SetName(const NStringWrapper & value)
	{
		NCheck(NStringSet(value.GetHandle(), &hName));
	}

	NString GetVersion() const
	{
		return NString(hVersion, false);
	}

	void SetVersion(const NStringWrapper & value)
	{
		NCheck(NStringSet(value.GetHandle(), &hVersion));
	}
};
}}}

N_DEFINE_DISPOSABLE_STRUCT_TYPE_TRAITS(Neurotec::Biometrics::Standards, ANDomain)
N_DEFINE_DISPOSABLE_STRUCT_TYPE_TRAITS(Neurotec::Biometrics::Standards, ANCharset)

namespace Neurotec { namespace Biometrics { namespace Standards
{

class ANType1Record : public ANAsciiRecord
{
	N_DECLARE_OBJECT_CLASS(ANType1Record, ANAsciiRecord)

public:
	class CharsetCollection : public ::Neurotec::Collections::NCollectionBase<ANCharset, ANType1Record,
		ANType1RecordGetCharsetCount, ANType1RecordGetCharset>
	{
		CharsetCollection(const ANType1Record & owner)
		{
			SetOwner(owner);
		}

		friend class ANType1Record;
	public:
		void Set(NInt index, const ANCharset & value)
		{
			NCheck(ANType1RecordSetCharset(this->GetOwnerHandle(), index, &value));
		}

		NInt Add(const ANCharset & value)
		{
			NInt index;
			NCheck(ANType1RecordAddCharsetEx(this->GetOwnerHandle(), &value, &index));
			return index;
		}

		void Insert(NInt index, const ANCharset & value)
		{
			NCheck(ANType1RecordInsertCharset(this->GetOwnerHandle(), index, &value));
		}

		void RemoveAt(NInt index)
		{
			NCheck(ANType1RecordRemoveCharsetAt(this->GetOwnerHandle(), index));
		}

		void Clear()
		{
			NCheck(ANType1RecordClearCharsets(this->GetOwnerHandle()));
		}

		bool Contains(NInt charsetIndex)
		{
			NBool value;
			NCheck(ANType1RecordContainsCharset(this->GetOwnerHandle(), charsetIndex, &value));
			return value != 0;
		}
	};

public:
	static NInt GetStandardCharsetIndexes(const NVersion & version, NInt * arValue, NInt valueLength)
	{
		return NCheck(ANType1RecordGetStandardCharsetIndexes(version.GetValue(), arValue, valueLength));
	}

	static NArrayWrapper<NInt> GetStandardCharsetIndexes(const NVersion & version)
	{
		NInt count = GetStandardCharsetIndexes(version, NULL, 0);
		NArrayWrapper<NInt> values(count);
		count = GetStandardCharsetIndexes(version, values.GetPtr(), count);
		values.SetCount(count);
		return values;
	}

	static bool IsCharsetKnown(const NVersion & version, NInt charsetIndex)
	{
		NBool value;
		NCheck(ANType1RecordIsCharsetKnown(version.GetValue(), charsetIndex, &value));
		return value != 0;
	}

	static bool IsCharsetStandard(const NVersion & version, NInt charsetIndex)
	{
		NBool value;
		NCheck(ANType1RecordIsCharsetStandard(version.GetValue(), charsetIndex, &value));
		return value != 0;
	}

	static bool IsCharsetUserDefined(const NVersion & version, NInt charsetIndex)
	{
		NBool value;
		NCheck(ANType1RecordIsCharsetUserDefined(version.GetValue(), charsetIndex, &value));
		return value != 0;
	}

	static NString GetStandardCharsetName(const NVersion & version, NInt charsetIndex)
	{
		HNString hValue;
		NCheck(ANType1RecordGetStandardCharsetNameN(version.GetValue(), charsetIndex, &hValue));
		return NString(hValue, true);
	}

	static NString GetStandardCharsetDescription(const NVersion & version, NInt charsetIndex)
	{
		HNString hValue;
		NCheck(ANType1RecordGetStandardCharsetDescriptionN(version.GetValue(), charsetIndex, &hValue));
		return NString(hValue, true);
	}

	static NInt GetStandardCharsetIndexByName(const NVersion & version, const NString & name)
	{
		NInt value;
		NCheck(ANType1RecordGetStandardCharsetIndexByNameN(version.GetValue(), name.GetHandle(), &value));
		return value;
	}

	NString GetTransactionType() const
	{
		return GetString(ANType1RecordGetTransactionTypeN);
	}

	void SetTransactionType(const NStringWrapper & value)
	{
		return SetString(ANType1RecordSetTransactionTypeN, value);
	}

	NDateTime GetDate() const
	{
		NDateTime_ value;
		NCheck(ANType1RecordGetDate(GetHandle(), &value));
		return NDateTime(value);
	}

	void SetDate(const NDateTime & value)
	{
		NCheck(ANType1RecordSetDate(GetHandle(), value.GetValue()));
	}

	NInt GetPriority() const
	{
		NInt value;
		NCheck(ANType1RecordGetPriority(GetHandle(), &value));
		return value;
	}

	void SetPriority(NInt value)
	{
		NCheck(ANType1RecordSetPriority(GetHandle(), value));
	}

	NString GetDestinationAgency() const
	{
		return GetString(ANType1RecordGetDestinationAgencyN);
	}

	void SetDestinationAgency(const NStringWrapper & value)
	{
		return SetString(ANType1RecordSetDestinationAgencyN, value);
	}

	NString GetOriginatingAgency() const
	{
		return GetString(ANType1RecordGetOriginatingAgencyN);
	}

	void SetOriginatingAgency(const NStringWrapper & value)
	{
		return SetString(ANType1RecordSetOriginatingAgencyN, value);
	}

	NString GetTransactionControl() const
	{
		return GetString(ANType1RecordGetTransactionControlN);
	}

	void SetTransactionControl(const NStringWrapper & value)
	{
		return SetString(ANType1RecordSetTransactionControlN, value);
	}

	NString GetTransactionControlReference() const
	{
		return GetString(ANType1RecordGetTransactionControlReferenceN);
	}

	void SetTransactionControlReference(const NStringWrapper & value)
	{
		return SetString(ANType1RecordSetTransactionControlReferenceN, value);
	}

	NUInt GetNativeScanningResolution() const
	{
		NUInt value;
		NCheck(ANType1RecordGetNativeScanningResolution(GetHandle(), &value));
		return value;
	}

	NUInt GetNominalTransmittingResolution() const
	{
		NUInt value;
		NCheck(ANType1RecordGetNominalTransmittingResolution(GetHandle(), &value));
		return value;
	}

	bool GetDomain(ANDomain * pValue) const
	{
		NBool hasValue;
		NCheck(ANType1RecordGetDomain(GetHandle(), pValue, &hasValue));
		return hasValue != 0;
	}

	NString GetDomainName() const
	{
		return GetString(ANType1RecordGetDomainNameN);
	}

	NString GetDomainVersion() const
	{
		return GetString(ANType1RecordGetDomainVersionN);
	}

	void SetDomain(const ANDomain * pValue)
	{
		NCheck(ANType1RecordSetDomainEx(GetHandle(), pValue));
	}

	void SetDomain(const NStringWrapper & name, const NStringWrapper & version)
	{
		NCheck(ANType1RecordSetDomainN(GetHandle(), name.GetHandle(), version.GetHandle()));
	}

	NDateTime GetGmt() const
	{
		NDateTime_ value;
		NCheck(ANType1RecordGetGmt(GetHandle(), &value));
		return NDateTime(value);
	}

	void SetGmt(const NDateTime & value)
	{
		NCheck(ANType1RecordSetGmt(GetHandle(), value.GetValue()));
	}

	CharsetCollection GetCharsets()
	{
		return CharsetCollection(*this);
	}

	const CharsetCollection GetCharsets() const
	{
		return CharsetCollection(*this);
	}
};

}}}

#endif // !AN_TYPE_1_RECORD_HPP_INCLUDED
