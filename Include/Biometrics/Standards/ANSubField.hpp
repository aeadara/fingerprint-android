#ifndef AN_SUB_FIELD_HPP_INCLUDED
#define AN_SUB_FIELD_HPP_INCLUDED

#include <Core/NObject.hpp>
namespace Neurotec { namespace Biometrics { namespace Standards
{
#include <Biometrics/Standards/ANSubField.h>
}}}

namespace Neurotec { namespace Biometrics { namespace Standards
{

class ANField;

class ANSubField : public NObject
{
	N_DECLARE_OBJECT_CLASS(ANSubField, NObject)

public:
	class ItemCollection : public ::Neurotec::Collections::NCollectionBase<NString, ANSubField,
		ANSubFieldGetItemCount, ANSubFieldGetItemN>
	{
		ItemCollection(const ANSubField & owner)
		{
			SetOwner(owner);
		}

		friend class ANSubField;
	public:
		NInt GetCapacity() const
		{
			NInt value;
			NCheck(ANSubFieldGetItemCapacity(this->GetOwnerHandle(), &value));
			return value;
		}

		void SetCapacity(NInt value)
		{
			NCheck(ANSubFieldSetItemCapacity(this->GetOwnerHandle(), value));
		}

		void Set(NInt index, const NStringWrapper & value)
		{
			NCheck(ANSubFieldSetItemN(this->GetOwnerHandle(), index, value.GetHandle()));
		}

		NInt Add(const NStringWrapper & value)
		{
			NInt index;
			NCheck(ANSubFieldAddItemN(this->GetOwnerHandle(), value.GetHandle(), &index));
			return index;
		}

		void Insert(NInt index, const NStringWrapper & value)
		{
			NCheck(ANSubFieldInsertItemN(this->GetOwnerHandle(), index, value.GetHandle()));
		}

		void RemoveAt(NInt index)
		{
			NCheck(ANSubFieldRemoveItemAt(this->GetOwnerHandle(), index));
		}

		void RemoveRange(NInt index, NInt count)
		{
			NCheck(ANSubFieldRemoveItemRange(this->GetOwnerHandle(), index, count));
		}
	};

public:
	NString GetValue() const
	{
		return GetString(ANSubFieldGetValueN);
	}

	void SetValue(const NStringWrapper & value)
	{
		SetString(ANSubFieldSetValueN, value);
	}

	ItemCollection GetItems()
	{
		return ItemCollection(*this);
	}

	const ItemCollection GetItems() const
	{
		return ItemCollection(*this);
	}

	ANField GetOwner() const;
};

}}}

#include <Biometrics/Standards/ANField.hpp>

namespace Neurotec { namespace Biometrics { namespace Standards
{

inline ANField ANSubField::GetOwner() const
{
	return NObject::GetOwner<ANField>();
}

}}}

#endif // !AN_SUB_FIELD_HPP_INCLUDED
