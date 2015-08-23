#include <Reflection/NMemberInfo.hpp>
#include <Reflection/NMethodInfo.hpp>
#include <Core/NValue.hpp>

#ifndef N_PROPERTY_INFO_HPP_INCLUDED
#define N_PROPERTY_INFO_HPP_INCLUDED

#include <Collections/NCollections.hpp>
namespace Neurotec { namespace Reflection
{
#include <Reflection/NPropertyInfo.h>
}}

namespace Neurotec { namespace Reflection
{

class NPropertyInfo : public NMemberInfo
{
	N_DECLARE_OBJECT_CLASS(NPropertyInfo, NMemberInfo)

public:
	class StdValueCollection : public ::Neurotec::Collections::NCollectionWithAllOutBase<NNameValuePair, NPropertyInfo,
		NPropertyInfoGetStdValueCount, NPropertyInfoGetStdValue, NPropertyInfoGetStdValues>
	{
		StdValueCollection(const NPropertyInfo & owner)
		{
			SetOwner(owner);
		}

	protected:
		friend class NPropertyInfo;
	};

public:
	NType GetPropertyType() const
	{
		return GetObject<HandleType, NType>(NPropertyInfoGetPropertyType, true);
	}

	NString GetFormat() const
	{
		return GetString<HandleType>(NPropertyInfoGetFormat);
	}

	NValue GetDefaultValue() const
	{
		return GetObject<HandleType, NValue>(NPropertyInfoGetDefaultValue);
	}

	NValue GetMinValue() const
	{
		return GetObject<HandleType, NValue>(NPropertyInfoGetMinValue);
	}

	NValue GetMaxValue() const
	{
		return GetObject<HandleType, NValue>(NPropertyInfoGetMaxValue);
	}

	NMethodInfo GetGetMethod() const
	{
		return GetObject<HandleType, NMethodInfo>(NPropertyInfoGetGetMethod);
	}

	NMethodInfo GetSetMethod() const
	{
		return GetObject<HandleType, NMethodInfo>(NPropertyInfoGetSetMethod);
	}

	NValue GetValue(const NObject & object) const
	{
		HNValue hValue;
		NCheck(NPropertyInfoGetValueN(GetHandle(), object.GetHandle(), &hValue));
		return FromHandle<NValue>(hValue);
	}

	bool GetValue(const NObject & object, const NType & valueType, NAttributes attributes, void * arValues, NSizeType valuesSize, NInt valuesLength) const
	{
		NBool hasValue;
		NCheck(NPropertyInfoGetValue(GetHandle(), object.GetHandle(), valueType.GetHandle(), attributes, arValues, valuesSize, valuesLength, &hasValue));
		return hasValue != 0;
	}

	template<typename T> T GetValue(const NObject & object, NAttributes attributes = naNone, bool * pHasValue = NULL) const
	{
		typename NTypeTraits<T>::NativeType value;
		NBool hasValue;
		NCheck(NPropertyInfoGetValue(GetHandle(), object.GetHandle(), NTypeTraits<T>::GetNativeType().GetHandle(), attributes, &value, sizeof(value), 1, pHasValue ? &hasValue : NULL));
		T v = NTypeTraits<T>::FromNative(value, true);
		if (pHasValue) *pHasValue = hasValue != 0;
		return v;
	}

	void SetValue(const NObject & object, const NValue & value) const
	{
		NCheck(NPropertyInfoSetValueN(GetHandle(), object.GetHandle(), value.GetHandle()));
	}

	void SetValue(const NObject & object, const NType & valueType, NAttributes attributes, const void * arValues, NSizeType valuesSize, NInt valuesLength, bool hasValue = true) const
	{
		NCheck(NPropertyInfoSetValue(GetHandle(), object.GetHandle(), valueType.GetHandle(), attributes, arValues, valuesSize, valuesLength, hasValue ? NTrue : NFalse));
	}

	template<typename T> void SetValue(const NObject & object, const T & value, NAttributes attributes = naNone, bool hasValue = true) const
	{
		typename NTypeTraits<T>::NativeType v = NTypeTraits<T>::ToNative(value);
		NCheck(NPropertyInfoSetValue(GetHandle(), object.GetHandle(), NTypeTraits<T>::GetNativeType().GetHandle(), attributes, &value, sizeof(value), 1, hasValue ? NTrue : NFalse));
	}

	bool CanResetValue() const
	{
		NBool value;
		NCheck(NPropertyInfoCanResetValue(GetHandle(), &value));
		return value != 0;
	}

	void ResetValue(const NObject & object) const
	{
		NCheck(NPropertyInfoResetValue(GetHandle(), object.GetHandle()));
	}

	const StdValueCollection GetStdValues() const
	{
		return StdValueCollection(*this);
	}
};

}}

#endif // !N_PROPERTY_INFO_HPP_INCLUDED
