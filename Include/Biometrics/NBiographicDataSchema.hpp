#include <Core/NObject.hpp>

#ifndef N_BIOGRAPHIC_DATA_SCHEMA_HPP_INCLUDED
#define N_BIOGRAPHIC_DATA_SCHEMA_HPP_INCLUDED

namespace Neurotec { namespace Biometrics
{
#include <Biometrics/NBiographicDataSchema.h>
}}

N_DEFINE_ENUM_TYPE_TRAITS(Neurotec::Biometrics, NDBType)

namespace Neurotec { namespace Biometrics
{

class NBiographicDataElement : public NBiographicDataElement_
{
	N_DECLARE_EQUATABLE_DISPOSABLE_STRUCT_CLASS(NBiographicDataElement)

public:
	NBiographicDataElement(const NStringWrapper & name, const NStringWrapper & dbColumn, NDBType dbType)
	{
		NCheck(NBiographicDataElementCreateN(name.GetHandle(), dbColumn.GetHandle(), dbType, this));
	}

	NString GetName() const
	{
		return NString(hName, false);
	}

	void SetName(const NStringWrapper & value)
	{
		NCheck(NStringSet(value.GetHandle(), &hName));
	}

	NString GetDbColumn() const
	{
		return NString(hDbColumn, false);
	}

	void SetDbColumn(const NStringWrapper & value)
	{
		NCheck(NStringSet(value.GetHandle(), &hDbColumn));
	}
};

}}

N_DEFINE_DISPOSABLE_STRUCT_TYPE_TRAITS(Neurotec::Biometrics, NBiographicDataElement);

namespace Neurotec { namespace Biometrics
{

class NBiographicDataSchema : public NObject
{
	N_DECLARE_OBJECT_CLASS(NBiographicDataSchema, NObject)

public:
	class ElementCollection : public ::Neurotec::Collections::NCollectionWithAllOutBase<NBiographicDataElement, NBiographicDataSchema,
		NBiographicDataSchemaGetElementCount, NBiographicDataSchemaGetElement, NBiographicDataSchemaGetElements>
	{
		ElementCollection(const NBiographicDataSchema & owner)
		{
			SetOwner(owner);
		}

		friend class NBiographicDataSchema;
	public:
		NInt GetCapacity() const
		{
			NInt result;
			NCheck(NBiographicDataSchemaGetElementCapacity(this->GetOwnerHandle(), &result));
			return result;
		}

		void SetCapacity(NInt value)
		{
			NCheck(NBiographicDataSchemaSetElementCapacity(this->GetOwnerHandle(), value));
		}

		void Set(NInt index, const NBiographicDataElement & value)
		{
			NCheck(NBiographicDataSchemaSetElement(this->GetOwnerHandle(), index, &value));
		}

		NInt Add(const NBiographicDataElement & value)
		{
			NInt index;
			NCheck(NBiographicDataSchemaAddElement(this->GetOwnerHandle(), &value, &index));
			return index;
		}

		void Insert(NInt index, const NBiographicDataElement & value)
		{
			NCheck(NBiographicDataSchemaInsertElement(this->GetOwnerHandle(), index, &value));
		}

		void RemoveAt(NInt index)
		{
			NCheck(NBiographicDataSchemaRemoveElementAt(this->GetOwnerHandle(), index));
		}

		void Clear()
		{
			NCheck(NBiographicDataSchemaClearElements(this->GetOwnerHandle()));
		}
	};

private:
	static HNBiographicDataSchema Create()
	{
		HNBiographicDataSchema handle;
		NCheck(NBiographicDataSchemaCreate(&handle));
		return handle;
	}

public:
	static NType NDBTypeNativeTypeOf()
	{
		return NObject::GetObject<NType>(N_TYPE_OF(NDBType), true);
	}

	static bool TryParse(const NStringWrapper & value, const NStringWrapper & format, NBiographicDataSchema * pValue)
	{
		if (!pValue) NThrowArgumentNullException(N_T("pValue"));
		NBool result;
		HNBiographicDataSchema hValue;
		NCheck(NBiographicDataSchemaTryParseN(value.GetHandle(), format.GetHandle(), &hValue, &result));
		*pValue = FromHandle<NBiographicDataSchema>(hValue);
		return result != 0;
	}

	static bool TryParse(const NStringWrapper & value, NBiographicDataSchema * pValue)
	{
		return TryParse(value, NString(), pValue);
	}

	static NBiographicDataSchema Parse(const NStringWrapper & value, const NStringWrapper & format = NString())
	{
		HNBiographicDataSchema hValue;
		NCheck(NBiographicDataSchemaParseN(value.GetHandle(), format.GetHandle(), &hValue));
		return FromHandle<NBiographicDataSchema>(hValue);
	}

	NBiographicDataSchema()
		: NObject(Create(), true)
	{
	}

	ElementCollection GetElements()
	{
		return ElementCollection(*this);
	}

	const ElementCollection GetElements() const
	{
		return ElementCollection(*this);
	}
};

}}

#endif // !N_BIOGRAPHIC_DATA_SCHEMA_HPP_INCLUDED
