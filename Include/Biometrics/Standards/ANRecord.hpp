#include <Biometrics/Standards/ANField.hpp>

#ifndef AN_RECORD_HPP_INCLUDED
#define AN_RECORD_HPP_INCLUDED

#include <Biometrics/Standards/ANRecordType.hpp>
namespace Neurotec { namespace Biometrics { namespace Standards
{
#include <Biometrics/Standards/ANRecord.h>
}}}

namespace Neurotec { namespace Biometrics { namespace Standards
{

#undef AN_RECORD_MAX_FIELD_NUMBER

#undef AN_RECORD_FIELD_LEN
#undef AN_RECORD_FIELD_IDC
#undef AN_RECORD_FIELD_DATA

#undef AN_RECORD_MAX_IDC

#undef ANR_MERGE_DUPLICATE_FIELDS
#undef ANR_RECOVER_FROM_BINARY_DATA

const NInt AN_RECORD_MAX_FIELD_NUMBER = 999;

const NInt AN_RECORD_FIELD_LEN = 1;
const NInt AN_RECORD_FIELD_IDC = 2;
const NInt AN_RECORD_FIELD_DATA = 999;

const NInt AN_RECORD_MAX_IDC = 255;

const NUInt ANR_MERGE_DUPLICATE_FIELDS = 0x00000100;
const NUInt ANR_RECOVER_FROM_BINARY_DATA = 0x00000200;

class ANTemplate;

class ANRecord : public NObject
{
	N_DECLARE_OBJECT_CLASS(ANRecord, NObject)

public:
	class FieldCollection : public ::Neurotec::Collections::NCollectionBase<ANField, ANRecord,
		ANRecordGetFieldCount, ANRecordGetFieldEx>
	{
		FieldCollection(const ANRecord & owner)
		{
			SetOwner(owner);
		}

		friend class ANRecord;
	public:
		NInt GetCapacity() const
		{
			NInt value;
			NCheck(ANRecordGetFieldCapacity(this->GetOwnerHandle(), &value));
			return value;
		}

		void SetCapacity(NInt value)
		{
			NCheck(ANRecordSetFieldCapacity(this->GetOwnerHandle(), value));
		}

		void RemoveAt(NInt index)
		{
			NCheck(ANRecordRemoveFieldAt(this->GetOwnerHandle(), index));
		}

		ANField Add(NInt fieldNumber, const NStringWrapper & value, NInt * pIndex = NULL)
		{
			HANField hValue;
			NCheck(ANRecordAddFieldN(this->GetOwnerHandle(), fieldNumber, value.GetHandle(), pIndex, &hValue));
			return FromHandle<ANField>(hValue, true);
		}

		ANField Insert(NInt index, NInt fieldNumber, const NStringWrapper & value)
		{
			HANField hValue;
			NCheck(ANRecordInsertFieldN(this->GetOwnerHandle(), index, fieldNumber, value.GetHandle(), &hValue));
			return FromHandle<ANField>(hValue, true);
		}

		NInt IndexOf(NInt fieldNumber) const
		{
			NInt index;
			NCheck(ANRecordGetFieldIndexByNumber(this->GetOwnerHandle(), fieldNumber, &index));
			return index;
		}

		bool Contains(NInt fieldNumber) const
		{
			return IndexOf(fieldNumber) != -1;
		}

		ANField GetByNumber(NInt fieldNumber) const
		{
			HANField hField;
			NCheck(ANRecordGetFieldByNumberEx(this->GetOwnerHandle(), fieldNumber, &hField));
			return FromHandle<ANField>(hField, true);
		}
	};

public:
	void BeginUpdate()
	{
		NCheck(ANRecordBeginUpdate(GetHandle()));
	}

	void EndUpdate()
	{
		NCheck(ANRecordEndUpdate(GetHandle()));
	}

	ANRecordType GetRecordType() const
	{
		return GetObject<HandleType, ANRecordType>(ANRecordGetRecordTypeEx, true);
	}

	bool GetIsValidated() const
	{
		NBool value;
		NCheck(ANRecordIsValidated(GetHandle(), &value));
		return value != 0;
	}

	NSizeType GetLength() const
	{
		NSizeType value;
		NCheck(ANRecordGetLength(GetHandle(), &value));
		return value;
	}

	NInt GetIdc() const
	{
		NInt value;
		NCheck(ANRecordGetIdc(GetHandle(), &value));
		return value;
	}

	::Neurotec::IO::NBuffer GetData() const
	{
		return GetObject<HandleType, ::Neurotec::IO::NBuffer>(ANRecordGetDataN, true);
	}

	void SetData(const ::Neurotec::IO::NBuffer & value)
	{
		SetObject(ANRecordSetDataN, value);
	}

	void SetData(const void * pValue, NSizeType valueSize, bool copy = true)
	{
		NCheck(ANRecordSetDataEx(GetHandle(), pValue, valueSize, copy ? NTrue : NFalse));
	}

	FieldCollection GetFields()
	{
		return FieldCollection(*this);
	}

	const FieldCollection GetFields() const
	{
		return FieldCollection(*this);
	}

	ANTemplate GetOwner() const;
};

}}}

#include <Biometrics/Standards/ANTemplate.hpp>

namespace Neurotec { namespace Biometrics { namespace Standards
{

inline ANTemplate ANRecord::GetOwner() const
{
	return NObject::GetOwner<ANTemplate>();
}

}}}

#endif // !AN_RECORD_HPP_INCLUDED
