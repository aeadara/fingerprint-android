#ifndef CBEFF_RECORD_HPP_INCLUDED
#define CBEFF_RECORD_HPP_INCLUDED

#include <Biometrics/Standards/BdifTypes.hpp>
#include <Biometrics/Standards/CbeffBiometricOrganizations.hpp>
#include <Biometrics/Standards/CbeffBdbFormatIdentifiers.hpp>
#include <Biometrics/Standards/CbeffPatronFormatIdentifiers.hpp>
#include <Biometrics/Standards/CbeffProductIdentifiers.hpp>
#include <Biometrics/Standards/CbeffDeviceIdentifiers.hpp>
#include <Biometrics/NTemplate.hpp>
#include <Biometrics/Standards/FMRecord.hpp>
#include <Biometrics/Standards/FIRecord.hpp>
#include <Biometrics/Standards/FCRecord.hpp>
#include <Biometrics/Standards/IIRecord.hpp>
#include <Biometrics/Standards/ANTemplate.hpp>
#include <Biometrics/Standards/ANRecord.hpp>

namespace Neurotec { namespace Biometrics { namespace Standards
{
#include <Biometrics/Standards/CbeffRecord.h>

class CbeffTimeInterval : public CbeffTimeInterval_
{
	N_DECLARE_STRUCT_CLASS(CbeffTimeInterval)

public:
	CbeffTimeInterval(NDateTime from, NDateTime to)
	{
		this->from = from;
		this->to = to;
	}
};
}}}

N_DEFINE_ENUM_TYPE_TRAITS(Neurotec::Biometrics::Standards, CbeffIntegrityOptions)
N_DEFINE_ENUM_TYPE_TRAITS(Neurotec::Biometrics::Standards, CbeffBiometricType)
N_DEFINE_ENUM_TYPE_TRAITS(Neurotec::Biometrics::Standards, CbeffBiometricSubType)
N_DEFINE_ENUM_TYPE_TRAITS(Neurotec::Biometrics::Standards, CbeffPurpose)
N_DEFINE_ENUM_TYPE_TRAITS(Neurotec::Biometrics::Standards, CbeffProcessedLevel)
N_DEFINE_STRUCT_TYPE_TRAITS(Neurotec::Biometrics::Standards, CbeffTimeInterval)

namespace Neurotec { namespace Biometrics { namespace Standards
{

class CbeffRecord : public NObject
{
	N_DECLARE_OBJECT_CLASS(CbeffRecord, NObject)

public:
	class RecordCollection;

private:
	static HCbeffRecord Create(NUInt patronFormat)
	{
		HCbeffRecord handle;
		NCheck(CbeffRecordCreate(patronFormat, &handle));
		return handle;
	}

	static HCbeffRecord Create(const IO::NStream & stream, NUInt patronFormat)
	{
		HCbeffRecord handle;
		NCheck(CbeffRecordCreateFromStream(stream.GetHandle(), patronFormat, &handle));
		return handle;
	}

	static HCbeffRecord Create(const IO::NBuffer & buffer, NUInt patronFormat, NSizeType * pSize)
	{
		HCbeffRecord handle;
		NCheck(CbeffRecordCreateFromMemoryN(buffer.GetHandle(), patronFormat, pSize, &handle));
		return handle;
	}

	static HCbeffRecord Create(const void * pBuffer, NSizeType bufferSize, NUInt patronFormat, NSizeType * pSize)
	{
		HCbeffRecord handle;
		NCheck(CbeffRecordCreateFromMemory(pBuffer, bufferSize, patronFormat, pSize, &handle));
		return handle;
	}

	static HCbeffRecord Create(NUInt bdbFormat, const IO::NBuffer & bdbBuffer, NUInt patronFormat)
	{
		HCbeffRecord handle;
		NCheck(CbeffRecordCreateFromDataN(bdbFormat, bdbBuffer.GetHandle(), patronFormat, &handle));
		return handle;
	}

	static HCbeffRecord Create(NUInt bdbFormat, const void * pBdbBuffer, NSizeType bdbBufferSize, NUInt patronFormat)
	{
		HCbeffRecord handle;
		NCheck(CbeffRecordCreateFromData(bdbFormat, pBdbBuffer, bdbBufferSize, patronFormat, &handle));
		return handle;
	}

	static HCbeffRecord Create(const IIRecord & record, NUInt patronFormat)
	{
		HCbeffRecord handle;
		NCheck(CbeffRecordCreateFromIIRecord(record.GetHandle(), patronFormat, &handle));
		return handle;
	}

	static HCbeffRecord Create(const FCRecord & record, NUInt patronFormat)
	{
		HCbeffRecord handle;
		NCheck(CbeffRecordCreateFromFCRecord(record.GetHandle(), patronFormat, &handle));
		return handle;
	}

	static HCbeffRecord Create(const FIRecord & record, NUInt patronFormat)
	{
		HCbeffRecord handle;
		NCheck(CbeffRecordCreateFromFIRecord(record.GetHandle(), patronFormat, &handle));
		return handle;
	}

	static HCbeffRecord Create(const FMRecord & record, NUInt patronFormat)
	{
		HCbeffRecord handle;
		NCheck(CbeffRecordCreateFromFMRecord(record.GetHandle(), patronFormat, &handle));
		return handle;
	}

	static HCbeffRecord Create(const ANTemplate & anTemplate, NUInt patronFormat)
	{
		HCbeffRecord handle;
		NCheck(CbeffRecordCreateFromANTemplate(anTemplate.GetHandle(), patronFormat, &handle));
		return handle;
	}

	static HCbeffRecord Create(const ANRecord & record, NUInt patronFormat)
	{
		HCbeffRecord handle;
		NCheck(CbeffRecordCreateFromANRecord(record.GetHandle(), patronFormat, &handle));
		return handle;
	}

public:
	static NType CbeffIntegrityOptionsNativeTypeOf()
	{
		return NObject::GetObject<NType>(N_TYPE_OF(CbeffIntegrityOptions), true);
	}

	static NType CbeffBiometricTypeNativeTypeOf()
	{
		return NObject::GetObject<NType>(N_TYPE_OF(CbeffBiometricType), true);
	}

	static NType CbeffBiometricSubTypeNativeTypeOf()
	{
		return NObject::GetObject<NType>(N_TYPE_OF(CbeffBiometricSubType), true);
	}

	static NType CbeffPurposeNativeTypeOf()
	{
		return NObject::GetObject<NType>(N_TYPE_OF(CbeffPurpose), true);
	}

	static NType CbeffProcessedLevelNativeTypeOf()
	{
		return NObject::GetObject<NType>(N_TYPE_OF(CbeffProcessedLevel), true);
	}

	static NType CbeffTimeIntervalNativeTypeOf()
	{
		return NObject::GetObject<NType>(N_TYPE_OF(CbeffTimeInterval), true);
	}

	explicit CbeffRecord(NUInt patronFormat)
		: NObject(Create(patronFormat), true)
	{
	}

	CbeffRecord(const IO::NStream & stream, NUInt patronFormat)
		: NObject(Create(stream, patronFormat), true)
	{
	}

	CbeffRecord(const IO::NBuffer & buffer, NUInt patronFormat, NSizeType * pSize = NULL)
		: NObject(Create(buffer, patronFormat, pSize), true)
	{
	}

	CbeffRecord(const void * pBuffer, NSizeType bufferSize, NUInt patronFormat, NSizeType * pSize = NULL)
		: NObject(Create(pBuffer, bufferSize, patronFormat, pSize), true)
	{
	}

	explicit CbeffRecord(NUInt bdbFormat, const IO::NBuffer & bdbBuffer, NUInt patronFormat)
		: NObject(Create(bdbFormat, bdbBuffer, patronFormat), true)
	{
	}

	CbeffRecord(NUInt bdbFormat, const void * pBuffer, NSizeType bufferSize, NUInt patronFormat)
		: NObject(Create(bdbFormat, pBuffer, bufferSize, patronFormat), true)
	{
	}

	CbeffRecord(const IIRecord & record, NUInt patronFormat)
		: NObject(Create(record, patronFormat), true)
	{
	}

	CbeffRecord(const FCRecord & record, NUInt patronFormat)
		: NObject(Create(record, patronFormat), true)
	{
	}

	CbeffRecord(const FIRecord & record, NUInt patronFormat)
		: NObject(Create(record, patronFormat), true)
	{
	}

	CbeffRecord(const FMRecord & record, NUInt patronFormat)
		: NObject(Create(record, patronFormat), true)
	{
	}

	CbeffRecord(const ANTemplate & anTemplate, NUInt patronFormat)
		: NObject(Create(anTemplate, patronFormat), true)
	{
	}

	CbeffRecord(const ANRecord & record, NUInt patronFormat)
		: NObject(Create(record, patronFormat), true)
	{
	}

	static bool IsSupportedCbeffFormat(NUInt patronFormat)
	{
		NBool value;
		NCheck(CbeffRecordIsSupportedCbeffFormat(patronFormat, &value));
		return value != NFalse;
	}

	NUInt GetPatronFormat() const
	{
		NUInt value;
		NCheck(CbeffRecordGetPatronFormat(GetHandle(), &value));
		return value;
	}

	bool GetEncryption() const
	{
		NBool value;
		NCheck(CbeffRecordGetEncryption(GetHandle(), &value));
		return value != NFalse;
	}

	void SetEncryption(bool value)
	{
		NCheck(CbeffRecordSetEncryption(GetHandle(), value));
	}

	bool GetIntegrity() const
	{
		NBool value;
		NCheck(CbeffRecordGetIntegrity(GetHandle(), &value));
		return value != NFalse;
	}

	void SetIntegrity(bool value)
	{
		NCheck(CbeffRecordSetIntegrity(GetHandle(), value));
	}

	bool GetIntegrityOptions(CbeffIntegrityOptions * pValue) const
	{
		NBool hasValue;
		NCheck(CbeffRecordGetIntegrityOptions(GetHandle(), pValue, &hasValue));
		return hasValue != NFalse;
	}

	void SetIntegrityOptions(const CbeffIntegrityOptions * pValue)
	{
		NCheck(CbeffRecordSetIntegrityOptions(GetHandle(), pValue));
	}

	NUInt GetBdbFormat() const
	{
		NUInt value;
		NCheck(CbeffRecordGetBdbFormat(GetHandle(), &value));
		return value;
	}

	void SetBdbFormat(NUInt value)
	{
		NCheck(CbeffRecordSetBdbFormat(GetHandle(), value));
	}

	IO::NBuffer GetBdbBuffer() const
	{
		HNBuffer handle;
		NCheck(CbeffRecordGetBdbBuffer(GetHandle(), &handle));
		return FromHandle<IO::NBuffer>(handle);
	}

	void SetBdbBuffer(const IO::NBuffer & buffer)
	{
		NCheck(CbeffRecordSetBdbBuffer(GetHandle(), buffer.GetHandle()));
	}

	CbeffBiometricType GetBiometricType() const
	{
		CbeffBiometricType value;
		NCheck(CbeffRecordGetBiometricType(GetHandle(), &value));
		return value;
	}

	void SetBiometricType(CbeffBiometricType value)
	{
		NCheck(CbeffRecordSetBiometricType(GetHandle(), value));
	}

	CbeffBiometricSubType GetBiometricSubType() const
	{
		CbeffBiometricSubType value;
		NCheck(CbeffRecordGetBiometricSubType(GetHandle(), &value));
		return value;
	}

	void SetBiometricSubType(CbeffBiometricSubType value)
	{
		NCheck(CbeffRecordSetBiometricSubType(GetHandle(), value));
	}

	IO::NBuffer GetChallengeResponse() const
	{
		HNBuffer handle;
		NCheck(CbeffRecordGetChallengeResponse(GetHandle(), &handle));
		return FromHandle<IO::NBuffer>(handle);
	}

	void SetChallengeResponse(const IO::NBuffer & buffer)
	{
		NCheck(CbeffRecordSetChallengeResponse(GetHandle(), buffer.GetHandle()));
	}

	bool GetBdbCreationDate(NDateTime * pValue) const
	{
		NBool hasValue;
		NCheck(CbeffRecordGetBdbCreationDate(GetHandle(), (NDateTime_ *)pValue, &hasValue));
		return hasValue != NFalse;
	}

	void SetBdbCreationDate(const NDateTime * pValue)
	{
		NCheck(CbeffRecordSetBdbCreationDate(GetHandle(), (const NDateTime_ *)pValue));
	}

	IO::NBuffer GetBdbIndex() const
	{
		HNBuffer handle;
		NCheck(CbeffRecordGetBdbIndex(GetHandle(), &handle));
		return FromHandle<IO::NBuffer>(handle);
	}

	void SetBdbIndex(const IO::NBuffer & buffer)
	{
		NCheck(CbeffRecordSetBdbIndex(GetHandle(), buffer.GetHandle()));
	}

	bool GetProduct(NUInt * pValue) const
	{
		NBool hasValue;
		NCheck(CbeffRecordGetProduct(GetHandle(), pValue, &hasValue));
		return hasValue != NFalse;
	}

	void SetProduct(const NUInt * pValue)
	{
		NCheck(CbeffRecordSetProduct(GetHandle(), pValue));
	}

	bool GetCaptureDevice(NUInt * pValue) const
	{
		NBool hasValue;
		NCheck(CbeffRecordGetCaptureDevice(GetHandle(), pValue, &hasValue));
		return hasValue != NFalse;
	}

	void SetCaptureDevice(const NUInt * pValue)
	{
		NCheck(CbeffRecordSetCaptureDevice(GetHandle(), pValue));
	}

	bool GetFeatureExtractionAlgorithm(NUInt * pValue) const
	{
		NBool hasValue;
		NCheck(CbeffRecordGetFeatureExtractionAlgorithm(GetHandle(), pValue, &hasValue));
		return hasValue != NFalse;
	}

	void SetFeatureExtractionAlgorithm(const NUInt * pValue)
	{
		NCheck(CbeffRecordSetFeatureExtractionAlgorithm(GetHandle(), pValue));
	}

	bool GetComparisonAlgorithm(NUInt * pValue) const
	{
		NBool hasValue;
		NCheck(CbeffRecordGetComparisonAlgorithm(GetHandle(), pValue, &hasValue));
		return hasValue != NFalse;
	}

	void SetComparisonAlgorithm(const NUInt * pValue)
	{
		NCheck(CbeffRecordSetComparisonAlgorithm(GetHandle(), pValue));
	}

	bool GetQualityAlgorithm(NUInt * pValue) const
	{
		NBool hasValue;
		NCheck(CbeffRecordGetQualityAlgorithm(GetHandle(), pValue, &hasValue));
		return hasValue != NFalse;
	}

	void SetQualityAlgorithm(const NUInt * pValue)
	{
		NCheck(CbeffRecordSetQualityAlgorithm(GetHandle(), pValue));
	}

	bool GetCompressionAlgorithm(NUInt * pValue) const
	{
		NBool hasValue;
		NCheck(CbeffRecordGetCompressionAlgorithm(GetHandle(), pValue, &hasValue));
		return hasValue != NFalse;
	}

	void SetCompressionAlgorithm(const NUInt * pValue)
	{
		NCheck(CbeffRecordSetCompressionAlgorithm(GetHandle(), pValue));
	}

	CbeffProcessedLevel GetProcessedLevel() const
	{
		CbeffProcessedLevel value;
		NCheck(CbeffRecordGetProcessedLevel(GetHandle(), &value));
		return value;
	}

	void SetProcessedLevel(CbeffProcessedLevel value)
	{
		NCheck(CbeffRecordSetProcessedLevel(GetHandle(), value));
	}

	CbeffPurpose GetPurpose() const
	{
		CbeffPurpose value;
		NCheck(CbeffRecordGetPurpose(GetHandle(), &value));
		return value;
	}

	void SetPurpose(CbeffPurpose value)
	{
		NCheck(CbeffRecordSetPurpose(GetHandle(), value));
	}

	bool GetQuality(NByte * pValue) const
	{
		NBool hasValue;
		NCheck(CbeffRecordGetQuality(GetHandle(), pValue, &hasValue));
		return hasValue != NFalse;
	}

	void SetQuality(const NByte * pValue)
	{
		NCheck(CbeffRecordSetQuality(GetHandle(), pValue));
	}

	bool GetBdbValidityPeriod(CbeffTimeInterval * pValue) const
	{
		NBool hasValue;
		NCheck(CbeffRecordGetBdbValidityPeriod(GetHandle(), (CbeffTimeInterval_ *)pValue, &hasValue));
		return hasValue != NFalse;
	}

	void SetBdbValidityPeriod(const CbeffTimeInterval * pValue)
	{
		NCheck(CbeffRecordSetBdbValidityPeriod(GetHandle(), (const CbeffTimeInterval_ *)pValue));
	}

	bool GetBirCreationDate(NDateTime * pValue) const
	{
		NBool hasValue;
		NCheck(CbeffRecordGetBirCreationDate(GetHandle(), (NDateTime_ *)pValue, &hasValue));
		return hasValue != NFalse;
	}

	void SetBirCreationDate(const NDateTime * pValue)
	{
		NCheck(CbeffRecordSetBirCreationDate(GetHandle(), (const NDateTime_ *)pValue));
	}

	NString GetCreator() const
	{
		HNString hValue;
		NCheck(CbeffRecordGetCreator(GetHandle(), &hValue));
		return NString(hValue, true);
	}

	void SetCreator(const NStringWrapper & value)
	{
		NCheck(CbeffRecordSetCreator(GetHandle(), value.GetHandle()));
	}

	IO::NBuffer GetBirIndex() const
	{
		HNBuffer hValue;
		NCheck(CbeffRecordGetBirIndex(GetHandle(), &hValue));
		return FromHandle<IO::NBuffer>(hValue);
	}

	void SetBirIndex(const IO::NBuffer & value)
	{
		NCheck(CbeffRecordSetBirIndex(GetHandle(), value.GetHandle()));
	}

	IO::NBuffer GetPayload() const
	{
		HNBuffer hValue;
		NCheck(CbeffRecordGetPayload(GetHandle(), &hValue));
		return FromHandle<IO::NBuffer>(hValue);
	}

	void SetPayload(const IO::NBuffer & value)
	{
		NCheck(CbeffRecordSetPayload(GetHandle(), value.GetHandle()));
	}

	bool GetBirValidityPeriod(CbeffTimeInterval * pValue) const
	{
		NBool hasValue = NFalse;
		NCheck(CbeffRecordGetBirValidityPeriod(GetHandle(), (CbeffTimeInterval_ *)pValue, &hasValue));
		return hasValue != NFalse;
	}

	void SetBirValidityPeriod(const CbeffTimeInterval * pValue)
	{
		NCheck(CbeffRecordSetBirValidityPeriod(GetHandle(), (const CbeffTimeInterval_ *)pValue));
	}

	bool GetCbeffVersion(NByte * pValue) const
	{
		NBool hasValue = NFalse;
		NCheck(CbeffRecordGetCbeffVersion(GetHandle(), pValue));
		return hasValue != NFalse;
	}

	bool GetPatronHeaderVersion(NByte * pValue) const
	{
		NBool hasValue = NFalse;
		NCheck(CbeffRecordGetPatronHeaderVersion(GetHandle(), pValue));
		return hasValue != NFalse;
	}

	IO::NBuffer GetFascnBuffer() const
	{
		HNBuffer hValue;
		NCheck(CbeffRecordGetFascnBuffer(GetHandle(), &hValue));
		return FromHandle<IO::NBuffer>(hValue);
	}

	void SetFascnBuffer(const IO::NBuffer & value)
	{
		NCheck(CbeffRecordSetFascnBuffer(GetHandle(), value.GetHandle()));
	}

	bool GetSbFormat(NUInt * pValue) const
	{
		NBool hasValue = NFalse;
		NCheck(CbeffRecordGetSbFormat(GetHandle(), pValue, &hasValue));
		return hasValue != NFalse;
	}

	void SetSbFormat(const NUInt * pValue)
	{
		NCheck(CbeffRecordSetSbFormat(GetHandle(), pValue));
	}

	IO::NBuffer GetSbBuffer() const
	{
		HNBuffer hValue;
		NCheck(CbeffRecordGetSbBuffer(GetHandle(), &hValue));
		return FromHandle<IO::NBuffer>(hValue);
	}

	void SetSbBuffer(const IO::NBuffer & value)
	{
		NCheck(CbeffRecordSetSbBuffer(GetHandle(), value.GetHandle()));
	}

	RecordCollection GetRecords();
	const RecordCollection GetRecords() const;
};

class CbeffRecord::RecordCollection : public ::Neurotec::Collections::NCollectionWithAllOutBase<CbeffRecord, CbeffRecord,
	CbeffRecordGetRecordCount, CbeffRecordGetRecord, CbeffRecordGetRecords>
{
	RecordCollection(const CbeffRecord & owner)
	{
		SetOwner(owner);
	}

	friend class CbeffRecord;

public:
	void Set(NInt index, const CbeffRecord & value)
	{
		NCheck(CbeffRecordSetRecord(this->GetOwnerHandle(), index, value.GetHandle()));
	}

	NInt Add(const CbeffRecord & value)
	{
		NInt index;
		NCheck(CbeffRecordAddRecord(this->GetOwnerHandle(), value.GetHandle(), &index));
		return index;
	}

	void Insert(NInt index, const CbeffRecord & value)
	{
		NCheck(CbeffRecordInsertRecord(this->GetOwnerHandle(), index, value.GetHandle()));
	}

	void RemoveAt(NInt index)
	{
		NCheck(CbeffRecordRemoveRecordAt(this->GetOwnerHandle(), index));
	}

	void Clear()
	{
		NCheck(CbeffRecordClearRecords(this->GetOwnerHandle()));
	}
};

inline CbeffRecord::RecordCollection CbeffRecord::GetRecords()
{
	return CbeffRecord::RecordCollection(*this);
}

inline const CbeffRecord::RecordCollection CbeffRecord::GetRecords() const
{
	return CbeffRecord::RecordCollection(*this);
}

}}}

#endif // !CBEFF_RECORD_HPP_INCLUDED
