#include <ComponentModel/NMemberDescriptor.hpp>
#include <Core/NValue.hpp>

#ifndef N_PROPERTY_DESCRIPTOR_HPP_INCLUDED
#define N_PROPERTY_DESCRIPTOR_HPP_INCLUDED

#include <Collections/NCollections.hpp>
namespace Neurotec { namespace ComponentModel
{
#include <ComponentModel/NPropertyDescriptor.h>
}}

namespace Neurotec { namespace ComponentModel
{

class NPropertyDescriptor : public NMemberDescriptor
{
	N_DECLARE_OBJECT_CLASS(NPropertyDescriptor, NMemberDescriptor)

public:
	class StdValueCollection : public ::Neurotec::Collections::NCollectionWithAllOutBase<NNameValuePair, NPropertyDescriptor,
		NPropertyDescriptorGetStdValueCount, NPropertyDescriptorGetStdValue, NPropertyDescriptorGetStdValues>
	{
		StdValueCollection(const NPropertyDescriptor & owner)
		{
			SetOwner(owner);
		}

		friend class NPropertyDescriptor;
	};

public:
	NType GetPropertyType() const
	{
		return GetObject<HandleType, NType>(NPropertyDescriptorGetPropertyType, true);
	}

	NString GetFormat() const
	{
		return GetString<HandleType>(NPropertyDescriptorGetFormat);
	}

	NValue GetDefaultValue() const
	{
		return GetObject<HandleType, NValue>(NPropertyDescriptorGetDefaultValue);
	}

	NValue GetMinValue() const
	{
		return GetObject<HandleType, NValue>(NPropertyDescriptorGetMinValue);
	}

	NValue GetMaxValue() const
	{
		return GetObject<HandleType, NValue>(NPropertyDescriptorGetMaxValue);
	}

	NValue GetValue(const NObject & component) const
	{
		HNValue hValue;
		NCheck(NPropertyDescriptorGetValueN(GetHandle(), component.GetHandle(), &hValue));
		return FromHandle<NValue>(hValue);
	}

	bool GetValue(const NObject & component, const NType & valueType, NAttributes attributes, void * arValues, NSizeType valuesSize, NInt valuesLength) const
	{
		NBool hasValue;
		NCheck(NPropertyDescriptorGetValue(GetHandle(), component.GetHandle(), valueType.GetHandle(), attributes, arValues, valuesSize, valuesLength, &hasValue));
		return hasValue != 0;
	}

	template<typename T> T GetValue(const NObject & component, NAttributes attributes = naNone, bool * pHasValue = NULL) const
	{
		typename NTypeTraits<T>::NativeType value;
		NBool hasValue;
		NCheck(NPropertyDescriptorGetValue(GetHandle(), component.GetHandle(), NTypeTraits<T>::GetNativeType().GetHandle(), attributes, &value, sizeof(value), 1, pHasValue ? &hasValue : NULL));
		T v = NTypeTraits<T>::FromNative(value, true);
		if (pHasValue) *pHasValue = hasValue != 0;
		return v;
	}

	void SetValue(const NObject & component, const NValue & value) const
	{
		NCheck(NPropertyDescriptorSetValueN(GetHandle(), component.GetHandle(), value.GetHandle()));
	}

	void SetValue(const NObject & component, const NType & valueType, NAttributes attributes, const void * arValues, NSizeType valuesSize, NInt valuesLength, bool hasValue = true) const
	{
		NCheck(NPropertyDescriptorSetValue(GetHandle(), component.GetHandle(), valueType.GetHandle(), attributes, arValues, valuesSize, valuesLength, hasValue ? NTrue : NFalse));
	}

	template<typename T> void SetValue(const NObject & component, const T & value, NAttributes attributes = naNone, bool hasValue = true) const
	{
		typename NTypeTraits<T>::NativeType v = NTypeTraits<T>::ToNative(value);
		NCheck(NPropertyDescriptorSetValue(GetHandle(), component.GetHandle(), NTypeTraits<T>::GetNativeType().GetHandle(), attributes, &value, sizeof(value), 1, hasValue ? NTrue : NFalse));
	}

	bool CanResetValue(const NObject & component) const
	{
		NBool value;
		NCheck(NPropertyDescriptorCanResetValue(GetHandle(), component.GetHandle(), &value));
		return value != 0;
	}

	void ResetValue(const NObject & component) const
	{
		NCheck(NPropertyDescriptorResetValue(GetHandle(), component.GetHandle()));
	}

	void AddValueChangedCallback(const NObject & component, const NCallback & callback)
	{
		NCheck(NPropertyDescriptorAddValueChanged(GetHandle(), component.GetHandle(), callback.GetHandle()));
	}

	template<typename F>
	NCallback AddValueChangedCallback(const NObject & component, const F & callback, void * pParam = NULL)
	{
		NCallback cb = NTypes::CreateCallback<NObject::EventHandler<F> >(callback, pParam);
		AddValueChangedCallback(component, cb);
		return cb;
	}

	void RemoveValueChangedCallback(const NObject & component, const NCallback & callback)
	{
		NCheck(NPropertyDescriptorRemoveValueChanged(GetHandle(), component.GetHandle(), callback.GetHandle()));
	}

	template<typename F>
	NCallback RemoveValueChangedCallback(const NObject & component, const F & callback, void * pParam = NULL)
	{
		NCallback cb = NTypes::CreateCallback<NObject::EventHandler<F> >(callback, pParam);
		RemoveValueChangedCallback(component, cb);
		return cb;
	}

	const StdValueCollection GetStdValues() const
	{
		return StdValueCollection(*this);
	}
};

}}

#endif // !N_PROPERTY_DESCRIPTOR_HPP_INCLUDED
