#include <Core/NType.hpp>

#ifndef N_VALUE_HPP_INCLUDED
#define N_VALUE_HPP_INCLUDED

namespace Neurotec
{
#include <Core/NValue.h>
}

namespace Neurotec
{

class NValue : public NObject
{
	N_DECLARE_OBJECT_CLASS(NValue, NObject)

private:
	static HNValue Create(const void * value, NTypes::PointerFreeProc pFree, void * pFreeParam,
		NTypes::PointerGetHashCodeProc pGetHashCode, void * pGetHashCodeParam, NTypes::PointerEqualsProc pEquals, void * pEqualsParam, NAttributes attributes);

	static HNValue Create(NByte value, NAttributes attributes)
	{
		HNValue hValue;
		NCheck(NValueCreateFromByte(value, attributes, &hValue));
		return hValue;
	}

	static HNValue Create(NSByte value, NAttributes attributes)
	{
		HNValue hValue;
		NCheck(NValueCreateFromSByte(value, attributes, &hValue));
		return hValue;
	}

	static HNValue Create(NUShort value, NAttributes attributes)
	{
		HNValue hValue;
		NCheck(NValueCreateFromUInt16(value, attributes, &hValue));
		return hValue;
	}

	static HNValue Create(NShort value, NAttributes attributes)
	{
		HNValue hValue;
		NCheck(NValueCreateFromInt16(value, attributes, &hValue));
		return hValue;
	}

	static HNValue Create(NUInt value, NAttributes attributes)
	{
		HNValue hValue;
		NCheck(NValueCreateFromUInt32(value, attributes, &hValue));
		return hValue;
	}

	static HNValue Create(NInt value, NAttributes attributes)
	{
		HNValue hValue;
		NCheck(NValueCreateFromInt32(value, attributes, &hValue));
		return hValue;
	}

	static HNValue Create(NULong value, NAttributes attributes)
	{
		HNValue hValue;
		NCheck(NValueCreateFromUInt64(value, attributes, &hValue));
		return hValue;
	}

	static HNValue Create(NLong value, NAttributes attributes)
	{
		HNValue hValue;
		NCheck(NValueCreateFromInt64(value, attributes, &hValue));
		return hValue;
	}

	static HNValue Create(NFloat value, NAttributes attributes)
	{
		HNValue hValue;
		NCheck(NValueCreateFromSingle(value, attributes, &hValue));
		return hValue;
	}

	static HNValue Create(NDouble value, NAttributes attributes)
	{
		HNValue hValue;
		NCheck(NValueCreateFromDouble(value, attributes, &hValue));
		return hValue;
	}

	static HNValue Create(bool value, NAttributes attributes)
	{
		HNValue hValue;
		NCheck(NValueCreateFromBoolean(value ? NTrue : NFalse, attributes, &hValue));
		return hValue;
	}

public:
	static NValue FromValue(const NType & type, const void * pValue, NSizeType valueSize, bool hasValue = true, NAttributes attributes = naNone)
	{
		HNValue hValue;
		NCheck(NValueCreate(type.GetHandle(), pValue, valueSize, hasValue ? NTrue : NFalse, attributes, &hValue));
		return FromHandle<NValue>(hValue, true);
	}

	static NValue FromSizeType(NSizeType value, NAttributes attributes = naNone)
	{
		HNValue hValue;
		NCheck(NValueCreateFromSizeType(value, attributes, &hValue));
		return FromHandle<NValue>(hValue, true);
	}

	static NValue FromSSizeType(NSSizeType value, NAttributes attributes = naNone)
	{
		HNValue hValue;
		NCheck(NValueCreateFromSSizeType(value, attributes, &hValue));
		return FromHandle<NValue>(hValue, true);
	}

	static NValue FromResult(NResult value, NAttributes attributes = naNone)
	{
		HNValue hValue;
		NCheck(NValueCreateFromResult(value, attributes, &hValue));
		return FromHandle<NValue>(hValue, true);
	}

	static NValue FromChar(NChar value, NAttributes attributes = naNone)
	{
		HNValue hValue;
		NCheck(NValueCreateFromChar(value, attributes, &hValue));
		return FromHandle<NValue>(hValue, true);
	}

	static NValue FromString(const NStringWrapper & value, NAttributes attributes = naNone)
	{
		HNValue hValue;
		NCheck(NValueCreateFromStringN(value.GetHandle(), attributes, &hValue));
		return FromHandle<NValue>(hValue, true);
	}

	static NValue FromObject(const NType & type, const NObject & value, NAttributes attributes = naNone)
	{
		HNValue hValue;
		NCheck(NValueCreateFromObject(type.GetHandle(), value.GetHandle(), attributes, &hValue));
		return FromHandle<NValue>(hValue);
	}

	static NValue FromObject(const NObject & value, NAttributes attributes = naNone)
	{
		HNValue hValue;
		NCheck(NValueCreateFromObject(value.GetNativeType().GetHandle(), value.GetHandle(), attributes, &hValue));
		return FromHandle<NValue>(hValue);
	}

	static NValue FromCallback(const NType & type, const NCallback & value, NAttributes attributes = naNone)
	{
		HNValue hValue;
		NCheck(NValueCreateFromCallback(type.GetHandle(), value.GetHandle(), attributes, &hValue));
		return FromHandle<NValue>(hValue);
	}

	static NValue FromPointer(const void * value, NAttributes attributes = naNone)
	{
		HNValue hValue;
		NCheck(NValueCreateFromPointer(value, attributes, &hValue));
		return FromHandle<NValue>(hValue);
	}

	static void Set(const NValue & val, const NType & type, NAttributes attributes, void * pValue, NSizeType valueSize, bool * pHasValue = NULL)
	{
		NBool hasValue = pHasValue != NULL && *pHasValue ? NTrue : NFalse;
		NCheck(NValueSet(val.GetHandle(), type.GetHandle(), attributes, pValue, valueSize, pHasValue ? &hasValue : NULL));
	}

	static NValue ChangeType(const NValue & srcValue, const NType & type, NAttributes attributes = naNone, const NStringWrapper & format = NString())
	{
		HNValue hValue;
		NCheck(NValueChangeType(srcValue.GetHandle(), type.GetHandle(), attributes, format.GetHandle(), &hValue));
		return FromHandle<NValue>(hValue, true);
	}

	NValue(void * value, NTypes::PointerFreeProc pFree, void * pFreeParam,
		NTypes::PointerGetHashCodeProc pGetHashCode, void * pGetHashCodeParam, NTypes::PointerEqualsProc pEquals, void * pEqualsParam, NAttributes attributes = naNone)
		: NObject(Create(value, pFree, pFreeParam, pGetHashCode, pGetHashCodeParam, pEquals, pEqualsParam, attributes), true)
	{
	}

	explicit NValue(NByte value, NAttributes attributes = naNone)
		: NObject(Create(value, attributes), true)
	{
	}

	explicit NValue(NSByte value, NAttributes attributes = naNone)
		: NObject(Create(value, attributes), true)
	{
	}

	explicit NValue(NUShort value, NAttributes attributes = naNone)
		: NObject(Create(value, attributes), true)
	{
	}

	explicit NValue(NShort value, NAttributes attributes = naNone)
		: NObject(Create(value, attributes), true)
	{
	}

	explicit NValue(NUInt value, NAttributes attributes = naNone)
		: NObject(Create(value, attributes), true)
	{
	}

	explicit NValue(NInt value, NAttributes attributes = naNone)
		: NObject(Create(value, attributes), true)
	{
	}

	explicit NValue(NULong value, NAttributes attributes = naNone)
		: NObject(Create(value, attributes), true)
	{
	}

	explicit NValue(NLong value, NAttributes attributes = naNone)
		: NObject(Create(value, attributes), true)
	{
	}

	explicit NValue(NFloat value, NAttributes attributes = naNone)
		: NObject(Create(value, attributes), true)
	{
	}

	explicit NValue(NDouble value, NAttributes attributes = naNone)
		: NObject(Create(value, attributes), true)
	{
	}

	explicit NValue(bool value, NAttributes attributes = naNone)
		: NObject(Create(value, attributes), true)
	{
	}

	NType GetValueType() const
	{
		return GetObject<HandleType, NType>(NValueGetValueType);
	}

	NAttributes GetAttributes() const
	{
		NAttributes value;
		NCheck(NValueGetAttributes(GetHandle(), &value));
		return value;
	}

	NCallback GetFree() const
	{
		HNCallback hValue;
		NCheck(NValueGetFree(GetHandle(), &hValue));
		return NCallback(hValue, true);
	}

	NTypes::PointerFreeProc GetFreeProc(void * * ppParam) const;

	const void * GetPtr() const
	{
		const void * value;
		NCheck(NValueGetPtr(GetHandle(), &value));
		return value;
	}

	NSizeType GetSize() const
	{
		NSizeType value;
		NCheck(NValueGetSize(GetHandle(), &value));
		return value;
	}

	NTypeCode GetTypeCode() const
	{
		NTypeCode value;
		NCheck(NValueGetTypeCode(GetHandle(), &value));
		return value;
	}

	void ToValue(const NType & type, NAttributes attributes, const NStringWrapper & format, void * pResult, NSizeType resultSize) const
	{
		NCheck(NValueToValue(GetHandle(), type.GetHandle(), attributes, format.GetHandle(), pResult, resultSize));
	}
	void ToValue(const NType & type, NAttributes attributes, void * pResult, NSizeType resultSize) const { return ToValue(type, attributes, NString(), pResult, resultSize); }
	void ToValue(const NType & type, void * pResult, NSizeType resultSize) const { return ToValue(type, naNone, NString(), pResult, resultSize); }

	NByte ToByte(NAttributes attributes = naNone, const NStringWrapper & format = NString()) const
	{
		NByte value;
		NCheck(NValueToByte(GetHandle(), attributes, format.GetHandle(), &value));
		return value;
	}

	NSByte ToSByte(NAttributes attributes = naNone, const NStringWrapper & format = NString()) const
	{
		NSByte value;
		NCheck(NValueToSByte(GetHandle(), attributes, format.GetHandle(), &value));
		return value;
	}

	NUShort ToUInt16(NAttributes attributes = naNone, const NStringWrapper & format = NString()) const
	{
		NUShort value;
		NCheck(NValueToUInt16(GetHandle(), attributes, format.GetHandle(), &value));
		return value;
	}

	NShort ToInt16(NAttributes attributes = naNone, const NStringWrapper & format = NString()) const
	{
		NShort value;
		NCheck(NValueToInt16(GetHandle(), attributes, format.GetHandle(), &value));
		return value;
	}

	NUInt ToUInt32(NAttributes attributes = naNone, const NStringWrapper & format = NString()) const
	{
		NUInt value;
		NCheck(NValueToUInt32(GetHandle(), attributes, format.GetHandle(), &value));
		return value;
	}

	NInt ToInt32(NAttributes attributes = naNone, const NStringWrapper & format = NString()) const
	{
		NInt value;
		NCheck(NValueToInt32(GetHandle(), attributes, format.GetHandle(), &value));
		return value;
	}

	NULong ToUInt64(NAttributes attributes = naNone, const NStringWrapper & format = NString()) const
	{
		NULong value;
		NCheck(NValueToUInt64(GetHandle(), attributes, format.GetHandle(), &value));
		return value;
	}

	NLong ToInt64(NAttributes attributes = naNone, const NStringWrapper & format = NString()) const
	{
		NLong value;
		NCheck(NValueToInt64(GetHandle(), attributes, format.GetHandle(), &value));
		return value;
	}

	NFloat ToSingle(NAttributes attributes = naNone, const NStringWrapper & format = NString()) const
	{
		NFloat value;
		NCheck(NValueToSingle(GetHandle(), attributes, format.GetHandle(), &value));
		return value;
	}

	NDouble ToDouble(NAttributes attributes = naNone, const NStringWrapper & format = NString()) const
	{
		NDouble value;
		NCheck(NValueToDouble(GetHandle(), attributes, format.GetHandle(), &value));
		return value;
	}

	bool ToBoolean(NAttributes attributes = naNone, const NStringWrapper & format = NString()) const
	{
		NBool value;
		NCheck(NValueToBoolean(GetHandle(), attributes, format.GetHandle(), &value));
		return value != 0;
	}

	NSizeType ToSizeType(NAttributes attributes = naNone, const NStringWrapper & format = NString()) const
	{
		NSizeType value;
		NCheck(NValueToSizeType(GetHandle(), attributes, format.GetHandle(), &value));
		return value;
	}

	NSSizeType ToSSizeType(NAttributes attributes = naNone, const NStringWrapper & format = NString()) const
	{
		NSSizeType value;
		NCheck(NValueToSSizeType(GetHandle(), attributes, format.GetHandle(), &value));
		return value;
	}

	void * ToPointer(NAttributes attributes = naNone, const NStringWrapper & format = NString()) const
	{
		void * value;
		NCheck(NValueToPointer(GetHandle(), attributes, format.GetHandle(), &value));
		return value;
	}

	NResult ToResult(NAttributes attributes = naNone, const NStringWrapper & format = NString()) const
	{
		NResult value;
		NCheck(NValueToResult(GetHandle(), attributes, format.GetHandle(), &value));
		return value;
	}

	NChar ToChar(NAttributes attributes = naNone, const NStringWrapper & format = NString()) const
	{
		NChar value;
		NCheck(NValueToChar(GetHandle(), attributes, format.GetHandle(), &value));
		return value;
	}

	NString ToString(NAttributes attributes = naNone, const NStringWrapper & format = NString()) const
	{
		HNString hValue;
		NCheck(NValueToString(GetHandle(), attributes, format.GetHandle(), &hValue));
		return NString(hValue, true);
	}

	NObject ToObject(const NType & type, NAttributes attributes = naNone, const NStringWrapper & format = NString()) const
	{
		HNObject hValue;
		NCheck(NValueToObject(GetHandle(), type.GetHandle(), attributes, format.GetHandle(), &hValue));
		return FromHandle<NObject>(hValue, true);
	}

	template<typename T>
	T ToObject(NAttributes attributes = naNone, const NStringWrapper & format = NString()) const
	{
		HNObject hValue;
		NCheck(NValueToObject(GetHandle(), T::NativeTypeOf().GetHandle(), attributes, format.GetHandle(), &hValue));
		return FromHandle<T>((typename T::HandleType)hValue, true);
	}

	NCallback ToCallback(const NType & type, NAttributes attributes = naNone, const NStringWrapper & format = NString()) const
	{
		HNCallback hValue;
		NCheck(NValueToCallback(GetHandle(), type.GetHandle(), attributes, format.GetHandle(), &hValue));
		return NCallback(hValue, true);
	}
};

class NKeyValuePair : public NKeyValuePair_
{
	N_DECLARE_DISPOSABLE_STRUCT_CLASS(NKeyValuePair)

public:
	NKeyValuePair(const NValue & key, const NValue & value)
	{
		NCheck(NKeyValuePairCreate(key.GetHandle(), value.GetHandle(), this));
	}

	NValue GetKey() const
	{
		HNValue hKey;
		NCheck(NObjectGet(this->hKey, (HNObject *)&hKey));
		return NObject::FromHandle<NValue>(hKey, true);
	}

	void SetKey(const NValue & value)
	{
		NCheck(NObjectSet(value.GetHandle(), (HNObject *)&hKey));
	}

	NValue GetValue() const
	{
		HNValue hValue;
		NCheck(NObjectGet(this->hValue, (HNObject *)&hValue));
		return NObject::FromHandle<NValue>(hValue, true);
	}

	void SetValue(const NValue & value)
	{
		NCheck(NObjectSet(value.GetHandle(), (HNObject *)&hValue));
	}
};

class NNameValuePair : public NNameValuePair_
{
	N_DECLARE_DISPOSABLE_STRUCT_CLASS(NNameValuePair)

public:
	NNameValuePair(const NStringWrapper & key, const NValue & value)
	{
		NCheck(NNameValuePairCreateN(key.GetHandle(), value.GetHandle(), this));
	}

	NString GetKey() const
	{
		return NString(hKey, false);
	}

	void SetName(const NStringWrapper & value)
	{
		NCheck(NStringSet(value.GetHandle(), &hKey));
	}

	NValue GetValue() const
	{
		HNValue hValue;
		NCheck(NObjectGet(this->hValue, (HNObject *)&hValue));
		return NObject::FromHandle<NValue>(hValue, true);
	}

	void SetValue(const NValue & value)
	{
		NCheck(NObjectSet(value.GetHandle(), (HNObject *)&hValue));
	}
};

}

N_DEFINE_DISPOSABLE_STRUCT_TYPE_TRAITS(Neurotec, NKeyValuePair);
N_DEFINE_DISPOSABLE_STRUCT_TYPE_TRAITS(Neurotec, NNameValuePair);

#include <Core/NTypes.hpp>

namespace Neurotec
{

inline HNValue NValue::Create(const void * value, NTypes::PointerFreeProc pFree, void * pFreeParam,
		NTypes::PointerGetHashCodeProc pGetHashCode, void * pGetHashCodeParam, NTypes::PointerEqualsProc pEquals, void * pEqualsParam, NAttributes attributes)
{
	NCallback free = NTypes::CreateCallback(NTypes::PointerFreeProcImpl, pFree, pFreeParam);
	NCallback getHashCode = NTypes::CreateCallback(NTypes::PointerGetHashCodeImpl, pGetHashCode, pGetHashCodeParam);
	NCallback equals = NTypes::CreateCallback(NTypes::PointerEqualsImpl, pEquals, pEqualsParam);
	HNValue hValue;
	NCheck(NValueCreateCustomN(value, free.GetHandle(), getHashCode.GetHandle(), equals.GetHandle(), attributes, &hValue));
	return hValue;
}

inline NTypes::PointerFreeProc NValue::GetFreeProc(void * * ppParam) const
{
	if (!ppParam) NThrowArgumentNullException(N_T("ppParam"));
	NCallback free = GetFree();
	if (free.GetProc<NPointerFreeProc>() != NTypes::PointerFreeProcImpl)
	{
		ppParam = NULL;
		return NULL;
	}
	NTypes::CallbackParam * p = reinterpret_cast<NTypes::CallbackParam *>(free.GetParam());
	*ppParam = p->GetCallbackParam();
	return reinterpret_cast<NTypes::PointerFreeProc>(p->GetCallback());
}

}

#endif // !N_VALUE_HPP_INCLUDED
