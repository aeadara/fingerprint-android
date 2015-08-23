#ifndef AN_RECORD_TYPE_HPP_INCLUDED
#define AN_RECORD_TYPE_HPP_INCLUDED

#include <Core/NObject.hpp>
namespace Neurotec { namespace Biometrics { namespace Standards
{
#include <Biometrics/Standards/ANRecordType.h>
}}}

N_DEFINE_ENUM_TYPE_TRAITS(Neurotec::Biometrics::Standards, ANRecordDataType)

namespace Neurotec { namespace Biometrics { namespace Standards
{

#undef AN_RECORD_TYPE_MAX_NUMBER

const NInt AN_RECORD_TYPE_MAX_NUMBER = 99;

class ANRecordType : public NObject
{
	N_DECLARE_OBJECT_CLASS(ANRecordType, NObject)

public:
	class RecordTypeCollection;

public:
	static NType ANRecordDataTypeNativeTypeOf()
	{
		return NObject::GetObject<NType>(N_TYPE_OF(ANRecordDataType), true);
	}

	static ANRecordType GetType1()
	{
		return GetObject<ANRecordType>(ANRecordTypeGetType1Ex, true);
	}

	static ANRecordType GetType2()
	{
		return GetObject<ANRecordType>(ANRecordTypeGetType2Ex, true);
	}

	static ANRecordType GetType3()
	{
		return GetObject<ANRecordType>(ANRecordTypeGetType3Ex, true);
	}

	static ANRecordType GetType4()
	{
		return GetObject<ANRecordType>(ANRecordTypeGetType4Ex, true);
	}

	static ANRecordType GetType5()
	{
		return GetObject<ANRecordType>(ANRecordTypeGetType5Ex, true);
	}

	static ANRecordType GetType6()
	{
		return GetObject<ANRecordType>(ANRecordTypeGetType6Ex, true);
	}

	static ANRecordType GetType7()
	{
		return GetObject<ANRecordType>(ANRecordTypeGetType7Ex, true);
	}

	static ANRecordType GetType8()
	{
		return GetObject<ANRecordType>(ANRecordTypeGetType8Ex, true);
	}

	static ANRecordType GetType9()
	{
		return GetObject<ANRecordType>(ANRecordTypeGetType9Ex, true);
	}

	static ANRecordType GetType10()
	{
		return GetObject<ANRecordType>(ANRecordTypeGetType10Ex, true);
	}

	static ANRecordType GetType13()
	{
		return GetObject<ANRecordType>(ANRecordTypeGetType13Ex, true);
	}

	static ANRecordType GetType14()
	{
		return GetObject<ANRecordType>(ANRecordTypeGetType14Ex, true);
	}

	static ANRecordType GetType15()
	{
		return GetObject<ANRecordType>(ANRecordTypeGetType15Ex, true);
	}

	static ANRecordType GetType16()
	{
		return GetObject<ANRecordType>(ANRecordTypeGetType16Ex, true);
	}

	static ANRecordType GetType17()
	{
		return GetObject<ANRecordType>(ANRecordTypeGetType17Ex, true);
	}

	static ANRecordType GetType99()
	{
		return GetObject<ANRecordType>(ANRecordTypeGetType99Ex, true);
	}

	static ANRecordType GetTypeByNumber(NInt number)
	{
		HANRecordType handle;
		NCheck(ANRecordTypeGetTypeByNumberEx(number, &handle));
		return FromHandle<ANRecordType>(handle, true);
	}

	NInt GetMaxFieldNumber(const NVersion & version) const
	{
		NInt value;
		NCheck(ANRecordTypeGetMaxFieldNumber(GetHandle(), version.GetValue(), &value));
		return value;
	}

	NInt GetStandardFieldNumbers(const NVersion & version, NInt * arValue, NInt valueLength) const
	{
		return NCheck(ANRecordTypeGetStandardFieldNumbersEx(GetHandle(), version.GetValue(), arValue, valueLength));
	}

	NArrayWrapper<NInt> GetStandardFieldNumbers(const NVersion & version) const
	{
		NInt count = GetStandardFieldNumbers(version, NULL, 0);
		NArrayWrapper<NInt> values(count);
		count = GetStandardFieldNumbers(version, values.GetPtr(), count);
		values.SetCount(count);
		return values;
	}

	NInt GetUserDefinedFieldNumbers(const NVersion & version, NRange * arValue, NInt valueLength) const
	{
		return NCheck(ANRecordTypeGetUserDefinedFieldNumbersEx(GetHandle(), version.GetValue(), arValue, valueLength));
	}

	NArrayWrapper<NRange> GetUserDefinedFieldNumbers(const NVersion & version) const
	{
		NInt count = NCheck(ANRecordTypeGetUserDefinedFieldNumbersEx(GetHandle(), version.GetValue(), NULL, 0));
		NArrayWrapper<NRange> values(count);
		count = NCheck(ANRecordTypeGetUserDefinedFieldNumbersEx(GetHandle(), version.GetValue(), values.GetPtr(), count));
		values.SetCount(count);
		return values;
	}

	NInt GetFieldNumberById(const NVersion & version, const NStringWrapper & id) const
	{
		NInt value;
		NCheck(ANRecordTypeGetFieldNumberByIdN(GetHandle(), version.GetValue(), id.GetHandle(), &value));
		return value;
	}

	bool IsFieldKnown(const NVersion & version, NInt fieldNumber) const
	{
		NBool value;
		NCheck(ANRecordTypeIsFieldKnown(GetHandle(), version.GetValue(), fieldNumber, &value));
		return value != 0;
	}

	bool IsFieldStandard(const NVersion & version, NInt fieldNumber) const
	{
		NBool value;
		NCheck(ANRecordTypeIsFieldStandard(GetHandle(), version.GetValue(), fieldNumber, &value));
		return value != 0;
	}

	bool IsFieldMandatory(const NVersion & version, NInt fieldNumber) const
	{
		NBool value;
		NCheck(ANRecordTypeIsFieldMandatory(GetHandle(), version.GetValue(), fieldNumber, &value));
		return value != 0;
	}

	NString GetFieldId(const NVersion & version, NInt fieldNumber) const
	{
		HNString hValue;
		NCheck(ANRecordTypeGetFieldIdN(GetHandle(), version.GetValue(), fieldNumber, &hValue));
		return NString(hValue, true);
	}

	NString GetFieldName(const NVersion & version, NInt fieldNumber) const
	{
		HNString hValue;
		NCheck(ANRecordTypeGetFieldNameN(GetHandle(), version.GetValue(), fieldNumber, &hValue));
		return NString(hValue, true);
	}

	NVersion GetVersion() const
	{
		NVersion_ value;
		NCheck(ANRecordTypeGetVersion(GetHandle(), &value));
		return NVersion(value);
	}

	NInt GetNumber() const
	{
		NInt value;
		NCheck(ANRecordTypeGetNumber(GetHandle(), &value));
		return value;
	}

	NString GetName() const
	{
		return GetString(ANRecordTypeGetNameN);
	}

	ANRecordDataType GetDataType() const
	{
		ANRecordDataType value;
		NCheck(ANRecordTypeGetDataType(GetHandle(), &value));
		return value;
	}

	RecordTypeCollection GetRecordTypes();
	const RecordTypeCollection GetRecordTypes() const;
};

class ANRecordType::RecordTypeCollection : public ::Neurotec::Collections::NStaticCollectionBase<ANRecordType,
	ANRecordTypeGetTypeCount, ANRecordTypeGetTypeEx>
{
	friend class ANRecordType;
};

inline ANRecordType::RecordTypeCollection ANRecordType::GetRecordTypes()
{
	return ANRecordType::RecordTypeCollection();
}

inline const ANRecordType::RecordTypeCollection ANRecordType::GetRecordTypes() const
{
	return ANRecordType::RecordTypeCollection();
}

}}}

#endif // !AN_RECORD_TYPE_HPP_INCLUDED
