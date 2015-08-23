#include <Biometrics/Standards/ANSubField.hpp>

#ifndef AN_FIELD_HPP_INCLUDED
#define AN_FIELD_HPP_INCLUDED

namespace Neurotec { namespace Biometrics { namespace Standards
{
#include <Biometrics/Standards/ANField.h>
}}}

namespace Neurotec { namespace Biometrics { namespace Standards
{

class ANRecord;

class ANField : public NObject
{
	N_DECLARE_OBJECT_CLASS(ANField, NObject)

public:
	class ItemCollection : public ::Neurotec::Collections::NCollectionBase<NString, ANField,
		ANFieldGetItemCount, ANFieldGetItemN>
	{
		ItemCollection(const ANField & owner)
		{
			SetOwner(owner);
		}

		friend class ANField;
	public:
		NInt GetCapacity() const
		{
			NInt value;
			NCheck(ANFieldGetItemCapacity(this->GetOwnerHandle(), &value));
			return value;
		}

		void SetCapacity(NInt value)
		{
			NCheck(ANFieldSetItemCapacity(this->GetOwnerHandle(), value));
		}

		void Set(NInt index, const NStringWrapper & value)
		{
			NCheck(ANFieldSetItemN(this->GetOwnerHandle(), index, value.GetHandle()));
		}

		NInt Add(const NStringWrapper & value)
		{
			NInt index;
			NCheck(ANFieldAddItemN(this->GetOwnerHandle(), value.GetHandle(), &index));
			return index;
		}

		void Insert(NInt index, const NStringWrapper & value)
		{
			NCheck(ANFieldInsertItemN(this->GetOwnerHandle(), index, value.GetHandle()));
		}

		void RemoveAt(NInt index)
		{
			NCheck(ANFieldRemoveItemAt(this->GetOwnerHandle(), index));
		}

		void RemoveRange(NInt index, NInt count)
		{
			NCheck(ANFieldRemoveItemRange(this->GetOwnerHandle(), index, count));
		}
	};

	class SubFieldCollection : public ::Neurotec::Collections::NCollectionBase<ANSubField, ANField,
		ANFieldGetSubFieldCount, ANFieldGetSubFieldEx>
	{
		SubFieldCollection(const ANField & owner)
		{
			SetOwner(owner);
		}

		friend class ANField;
	public:
		NInt GetCapacity() const
		{
			NInt value;
			NCheck(ANFieldGetSubFieldCapacity(this->GetOwnerHandle(), &value));
			return value;
		}

		void SetCapacity(NInt value)
		{
			NCheck(ANFieldSetSubFieldCapacity(this->GetOwnerHandle(), value));
		}

		void RemoveAt(NInt index)
		{
			NCheck(ANFieldRemoveSubFieldAt(this->GetOwnerHandle(), index));
		}

		void RemoveRange(NInt index, NInt count)
		{
			NCheck(ANFieldRemoveSubFieldRange(this->GetOwnerHandle(), index, count));
		}

		ANSubField Add(const NStringWrapper & value, NInt * pIndex = NULL)
		{
			HANSubField hValue;
			NCheck(ANFieldAddSubFieldN(this->GetOwnerHandle(), value.GetHandle(), pIndex, &hValue));
			return FromHandle<ANSubField>(hValue, true);
		}

		ANSubField Insert(NInt index, const NStringWrapper & value)
		{
			HANSubField hValue;
			NCheck(ANFieldInsertSubFieldN(this->GetOwnerHandle(), index, value.GetHandle(), &hValue));
			return FromHandle<ANSubField>(hValue, true);
		}
	};

public:
	NString GetValue() const
	{
		return GetString(ANFieldGetValueN);
	}

	void SetValue(const NStringWrapper & value)
	{
		SetString(ANFieldSetValueN, value);
	}

	NInt GetNumber() const
	{
		NInt value;
		NCheck(ANFieldGetNumber(GetHandle(), &value));
		return value;
	}

	NString GetHeader() const
	{
		return GetString(ANFieldGetHeader);
	}

	ItemCollection GetItems()
	{
		return ItemCollection(*this);
	}

	const ItemCollection GetItems() const
	{
		return ItemCollection(*this);
	}

	SubFieldCollection GetSubFields()
	{
		return SubFieldCollection(*this);
	}

	const SubFieldCollection GetSubFields() const
	{
		return SubFieldCollection(*this);
	}

	ANRecord GetOwner() const;
};

}}}

#include <Biometrics/Standards/ANRecord.hpp>

namespace Neurotec { namespace Biometrics { namespace Standards
{

inline ANRecord ANField::GetOwner() const
{
	return NObject::GetOwner<ANRecord>();
}

}}}

#endif // !AN_FIELD_HPP_INCLUDED
