#include <Core/NObject.hpp>
#include <Core/NObjectPartBase.hpp>

#ifndef N_TYPE_HPP_INCLUDED
#define N_TYPE_HPP_INCLUDED

namespace Neurotec
{
#include <Core/NType.h>
}

namespace Neurotec
{

class NType : public NObject
{
	N_DECLARE_OBJECT_CLASS(NType, NObject)

public:
	template <typename T, typename NativeType,
		NResult (N_CALLBACK pGetCount)(HNType handle, NInt * pValue),
		NResult (N_CALLBACK pGet)(HNType handle, NInt index, NativeType * phValue),
		NResult (N_CALLBACK pGetAllOut)(HNType handle, NativeType * * parhValues, NInt * pValueCount)>
	class BaseCollection : public NObjectPartBase<NType>
	{
	public:
		typedef NCollectionIterator<BaseCollection, T> iterator;
		typedef NConstCollectionIterator<BaseCollection, T> const_iterator;
		typedef NCollectionIterator<BaseCollection, T> reverse_iterator;
		typedef NConstCollectionIterator<BaseCollection, T> reverse_const_iterator;

	protected:
		typedef T ItemType;

	public:
		NInt GetCount() const
		{
			NInt value;
			NCheck(pGetCount(this->GetOwnerHandle(), &value));
			return value;
		}

		T Get(NInt index) const
		{
			NativeType hValue;
			NCheck(pGet(this->GetOwnerHandle(), index, &hValue));
			return FromHandle<T>(hValue, true);
		}

		NArrayWrapper<ItemType> GetAll() const
		{
			NativeType * arhValues;
			NInt valueCount;
			NCheck(pGetAllOut(this->GetOwnerHandle(), &arhValues, &valueCount));
			return NArrayWrapper<ItemType>(arhValues, valueCount);
		}

		iterator begin()
		{
			return iterator(*this, 0);
		}

		const_iterator begin() const
		{
			return const_iterator(*this, 0);
		}

		iterator end()
		{
			return iterator(*this, GetCount());
		}

		const_iterator end() const
		{
			return const_iterator(*this, GetCount());
		}

		reverse_iterator rbegin()
		{
			return reverse_iterator(*this, GetCount() - 1, true);
		}

		reverse_const_iterator rbegin() const
		{
			return reverse_const_iterator(*this, GetCount() - 1, true);
		}

		reverse_iterator rend()
		{
			return reverse_iterator(*this, 0, true);
		}

		reverse_const_iterator rend() const
		{
			return reverse_const_iterator(*this, 0, true);
		}

		friend class ::Neurotec::NType;
	};

	class DeclaredEnumConstantCollection : public BaseCollection<  ::Neurotec::Reflection::NEnumConstantInfo, HNEnumConstantInfo,
		NTypeGetDeclaredEnumConstantCount, NTypeGetDeclaredEnumConstant, NTypeGetDeclaredEnumConstants>
	{
		DeclaredEnumConstantCollection(const NType & owner)
		{
			this->SetOwner(owner);
		}

		friend class ::Neurotec::NType;
	};

	class DeclaredFieldCollection : public BaseCollection< ::Neurotec::Reflection::NPropertyInfo, HNPropertyInfo,
		NTypeGetDeclaredFieldCount, NTypeGetDeclaredField, NTypeGetDeclaredFields>
	{
		DeclaredFieldCollection(const NType & owner)
		{
			this->SetOwner(owner);
		}

		friend class ::Neurotec::NType;
	};

	class DeclaredConstantCollection : public BaseCollection< ::Neurotec::Reflection::NConstantInfo, HNConstantInfo,
		NTypeGetDeclaredConstantCount, NTypeGetDeclaredConstant, NTypeGetDeclaredConstants>
	{
		DeclaredConstantCollection(const NType & owner)
		{
			this->SetOwner(owner);
		}

		friend class ::Neurotec::NType;
	};

	class DeclaredConstructorCollection : public BaseCollection< ::Neurotec::Reflection::NMethodInfo, HNMethodInfo,
		NTypeGetDeclaredConstructorCount, NTypeGetDeclaredConstructor, NTypeGetDeclaredConstructors>
	{
		DeclaredConstructorCollection(const NType & owner)
		{
			this->SetOwner(owner);
		}

		friend class ::Neurotec::NType;
	};

	class DeclaredMethodCollection : public BaseCollection< ::Neurotec::Reflection::NMethodInfo, HNMethodInfo,
		NTypeGetDeclaredMethodCount, NTypeGetDeclaredMethod, NTypeGetDeclaredMethods>
	{
		DeclaredMethodCollection(const NType & owner)
		{
			this->SetOwner(owner);
		}

		friend class ::Neurotec::NType;
	};

	class DeclaredPropertyCollection : public BaseCollection< ::Neurotec::Reflection::NPropertyInfo, HNPropertyInfo,
		NTypeGetDeclaredPropertyCount, NTypeGetDeclaredProperty, NTypeGetDeclaredProperties>
	{
		DeclaredPropertyCollection(const NType & owner)
		{
			this->SetOwner(owner);
		}

		friend class ::Neurotec::NType;
	};

	class DeclaredEventCollection : public BaseCollection< ::Neurotec::Reflection::NEventInfo, HNEventInfo,
		NTypeGetDeclaredEventCount, NTypeGetDeclaredEvent, NTypeGetDeclaredEvents>
	{
		DeclaredEventCollection(const NType & owner)
		{
			this->SetOwner(owner);
		}

		friend class ::Neurotec::NType;
	};

	class DeclaredPartCollection : public BaseCollection< ::Neurotec::Reflection::NObjectPartInfo, HNObjectPartInfo,
		NTypeGetDeclaredPartCount, NTypeGetDeclaredPart, NTypeGetDeclaredParts>
	{
		DeclaredPartCollection(const NType & owner)
		{
			this->SetOwner(owner);
		}

		friend class ::Neurotec::NType;
	};

public:
	static NType NTypeCodeNativeTypeOf()
	{
		return NObject::GetObject<NType>(N_TYPE_OF(NTypeCode), true);
	}

	static bool IsInstanceOfType(NTypeOfProc pTypeOf, const NObject & object)
	{
		NBool result;
		NCheck(NTypeIsInstanceOfTypeP(pTypeOf, object.GetHandle(), &result));
		return result != 0;
	}

	static NString IdentifierToString(const NStringWrapper & value, const NStringWrapper & format = NString())
	{
		HNString hValue;
		NCheck(NTypeIdentifierToStringN(value.GetHandle(), format.GetHandle(), &hValue));
		return NString(hValue, true);
	}

	static NType GetType(const NStringWrapper & name, bool mustExist = false)
	{
		HNType hValue;
		NCheck(NTypeGetTypeWithNameN(name.GetHandle(), mustExist ? NTrue : NFalse, &hValue));
		return FromHandle<NType>(hValue, true);
	}

	static NValue CreateInstance(const NStringWrapper & name, NAttributes attributes = naNone);

	NValue CreateInstance(NAttributes attributes = naNone) const;

	bool IsSubclassOf(const NType & type) const
	{
		NBool value;
		NCheck(NTypeIsSubclassOf(GetHandle(), type.GetHandle(), &value));
		return value != 0;
	}

	bool IsAssignableFrom(const NType & type) const
	{
		NBool value;
		NCheck(NTypeIsAssignableFrom(GetHandle(), type.GetHandle(), &value));
		return value != 0;
	}

	bool IsInstanceOfType(const NObject & object) const
	{
		NBool value;
		NCheck(NTypeIsInstanceOfType(GetHandle(), object.GetHandle(), &value));
		return value != 0;
	}

	void Reset(const NObject & object) const
	{
		NCheck(NTypeReset(GetHandle(), object.GetHandle()));
	}

	NValue GetPropertyValue(const NObject & object, const NStringWrapper & name) const;
	bool GetPropertyValue(const NObject & object, const NStringWrapper & name, NType & valueType, NAttributes attributes, void * arValues, NSizeType valuesSize, NInt valuesLength) const
	{
		NBool hasValue;
		NCheck(NTypeGetPropertyValueNN(GetHandle(), object.GetHandle(), name.GetHandle(), valueType.GetHandle(), attributes, arValues, valuesSize, valuesLength, &hasValue));
		return hasValue != 0;
	}
	template<typename T> T GetPropertyValue(const NObject & object, const NStringWrapper & name, NAttributes attributes = naNone, bool * pHasValue = NULL) const
	{
		typename NTypeTraits<T>::NativeType value;
		NBool hasValue;
		NCheck(NTypeGetPropertyValueNN(GetHandle(), object.GetHandle(), name.GetHandle(), NTypeTraits<T>::GetNativeType().GetHandle(), attributes, &value, sizeof(value), 1, pHasValue ? &hasValue : NULL));
		T v = NTypeTraits<T>::FromNative(value, true);
		if (pHasValue) *pHasValue = hasValue != 0;
		return v;
	}

	void SetPropertyValue(const NObject & object, const NStringWrapper & name, const NValue & value) const;
	void SetPropertyValue(const NObject & object, const NStringWrapper & name, const NType & valueType, NAttributes attributes, const void * arValues, NSizeType valuesSize, NInt valuesLength, bool hasValue = true) const
	{
		NCheck(NTypeSetPropertyValueNN(GetHandle(), object.GetHandle(), name.GetHandle(), valueType.GetHandle(), attributes, arValues, valuesSize, valuesLength, hasValue ? NTrue : NFalse));
	}
	template<typename T> void SetPropertyValue(const NObject & object, const NStringWrapper & name, const T & value, NAttributes attributes = naNone, bool hasValue = true) const
	{
		typename NTypeTraits<T>::NativeType v = NTypeTraits<T>::ToNative(value);
		NCheck(NTypeSetPropertyValueNN(GetHandle(), object.GetHandle(), name.GetHandle(), NTypeTraits<T>::GetNativeType().GetHandle(), attributes, &v, sizeof(v), 1, hasValue ? NTrue : NFalse));
	}

	void ResetPropertyValue(const NObject & object, const NStringWrapper & name) const
	{
		NCheck(NTypeResetPropertyValueN(GetHandle(), object.GetHandle(), name.GetHandle()));
	}

	void CopyPropertyValues(const NObject & dstObject, const NObject srcObject) const
	{
		NCheck(NTypeCopyPropertyValues(GetHandle(), dstObject.GetHandle(), srcObject.GetHandle()));
	}

	void CaptureProperties(const NObject & object, const NPropertyBag & properties) const;

	template<typename InputIt>
	NValue InvokeMethod(const NObject & object, const NStringWrapper & name, InputIt firstParameter, InputIt lastParameter) const;
	NValue InvokeMethod(const NObject & object, const NStringWrapper & name, const NPropertyBag & parameters) const;
	NValue InvokeMethod(const NObject & object, const NStringWrapper & name, const NStringWrapper & parameters) const;

	void AddEventHandler(const NObject & object, const NStringWrapper & name, const NValue & callback) const;
	void AddEventHandler(const NObject & object, const NStringWrapper & name, const NType & callbackType, const NCallback & callback) const;
	void RemoveEventHandler(const NObject & object, const NStringWrapper & name, const NValue & callback) const;
	void RemoveEventHandler(const NObject & object, const NStringWrapper & name, const NType & callbackType, const NCallback & callback) const;

	NModule GetModule() const;

	NString GetName() const
	{
		return GetString(NTypeGetNameN);
	}

	NType GetBaseType() const
	{
		return GetObject<HandleType, NType>(NTypeGetBaseType, true);
	}

	NTypeCode GetTypeCode() const
	{
		NTypeCode value;
		NCheck(NTypeGetTypeCode(GetHandle(), &value));
		return value;
	}

	NType GetRootType() const
	{
		return GetObject<HandleType, NType>(NTypeGetRootType, true);
	}

	NTypeCode GetRootTypeCode() const
	{
		NTypeCode value;
		NCheck(NTypeGetRootTypeCode(GetHandle(), &value));
		return value;
	}

	NSizeType GetValueSize() const
	{
		NSizeType value;
		NCheck(NTypeGetValueSize(GetHandle(), &value));
		return value;
	}

	bool IsBasic() const
	{
		NBool value;
		NCheck(NTypeIsBasic(GetHandle(), &value));
		return value != 0;
	}

	bool IsPrimitive() const
	{
		NBool value;
		NCheck(NTypeIsPrimitive(GetHandle(), &value));
		return value != 0;
	}

	bool IsEnum() const
	{
		NBool value;
		NCheck(NTypeIsEnum(GetHandle(), &value));
		return value != 0;
	}

	bool IsStruct() const
	{
		NBool value;
		NCheck(NTypeIsStruct(GetHandle(), &value));
		return value != 0;
	}

	bool IsHandle() const
	{
		NBool value;
		NCheck(NTypeIsHandle(GetHandle(), &value));
		return value != 0;
	}

	bool IsCallback() const
	{
		NBool value;
		NCheck(NTypeIsCallback(GetHandle(), &value));
		return value != 0;
	}

	bool IsObject() const
	{
		NBool value;
		NCheck(NTypeIsObject(GetHandle(), &value));
		return value != 0;
	}

	NAttributes GetAttributes() const
	{
		NAttributes value;
		NCheck(NTypeGetAttributes(GetHandle(), &value));
		return value;
	}

	bool IsDisposable() const
	{
		NBool value;
		NCheck(NTypeIsDisposable(GetHandle(), &value));
		return value != 0;
	}

	bool IsPublic() const
	{
		NBool value;
		NCheck(NTypeIsPublic(GetHandle(), &value));
		return value != 0;
	}

	bool IsStatic() const
	{
		NBool value;
		NCheck(NTypeIsStatic(GetHandle(), &value));
		return value != 0;
	}

	bool IsSealed() const
	{
		NBool value;
		NCheck(NTypeIsAbstract(GetHandle(), &value));
		return value != 0;
	}

	bool IsAbstract() const
	{
		NBool value;
		NCheck(NTypeIsAbstract(GetHandle(), &value));
		return value != 0;
	}

	bool IsDeprecated() const
	{
		NBool value;
		NCheck(NTypeIsDeprecated(GetHandle(), &value));
		return value != 0;
	}

	NType GetUseInsteadType() const
	{
		return GetObject<HandleType, NType>(NTypeGetUseInsteadType, true);
	}

	bool IsEquatable() const
	{
		NBool value;
		NCheck(NTypeIsEquatable(GetHandle(), &value));
		return value != 0;
	}

	bool IsComparable() const
	{
		NBool value;
		NCheck(NTypeIsComparable(GetHandle(), &value));
		return value != 0;
	}

	bool IsParsable() const
	{
		NBool value;
		NCheck(NTypeIsParsable(GetHandle(), &value));
		return value != 0;
	}

	bool IsSingNeutral() const
	{
		NBool value;
		NCheck(NTypeIsSignNeutral(GetHandle(), &value));
		return value != 0;
	}

	bool IsFlagsEnum() const
	{
		NBool value;
		NCheck(NTypeIsFlagsEnum(GetHandle(), &value));
		return value != 0;
	}

	bool IsCloneable() const
	{
		NBool value;
		NCheck(NTypeIsCloneable(GetHandle(), &value));
		return value != 0;
	}

	bool IsSerializable() const
	{
		NBool value;
		NCheck(NTypeIsSerializable(GetHandle(), &value));
		return value != 0;
	}

	bool IsMemorySerializable() const
	{
		NBool value;
		NCheck(NTypeIsMemorySerializable(GetHandle(), &value));
		return value != 0;
	}

	NType GetOwnerType() const
	{
		return GetObject<HandleType, NType>(NTypeGetOwnerType, true);
	}

	bool HasOwnerType() const
	{
		NBool value;
		NCheck(NTypeHasOwnerType(GetHandle(), &value));
		return value != 0;
	}

	void DisposeValue(void * pValue, NSizeType valueSize) const
	{
		NCheck(NTypeDisposeValue(GetHandle(), pValue, valueSize));
	}

	void DisposeValues(void * arValues, NSizeType valuesSize, NInt valuesLength) const
	{
		NCheck(NTypeDisposeValues(GetHandle(), arValues, valuesSize, valuesLength));
	}

	void FreeValues(void * arValues, NSizeType valuesSize, NInt valuesLength) const
	{
		NCheck(NTypeFreeValues(GetHandle(), arValues, valuesSize, valuesLength));
	}

	void CopyValue(const void * pSrcValue, NSizeType srcValueSize, void * pDstValue, NSizeType dstValueSize) const
	{
		NCheck(NTypeCopyValue(GetHandle(), pSrcValue, srcValueSize, pDstValue, dstValueSize));
	}

	void SetValue(const void * pSrcValue, NSizeType srcValueSize, void * pDstValue, NSizeType dstValueSize) const
	{
		NCheck(NTypeSetValue(GetHandle(), pSrcValue, srcValueSize, pDstValue, dstValueSize));
	}

	bool AreValuesEqual(const void * pValue1, NSizeType value1Size, const void * pValue2, NSizeType value2Size) const
	{
		NBool result;
		NCheck(NTypeAreValuesEqual(GetHandle(), pValue1, value1Size, pValue2, value2Size, &result));
		return result != 0;
	}

	NInt CompareValues(const void * pValue1, NSizeType value1Size, const void * pValue2, NSizeType value2Size) const
	{
		NInt result;
		NCheck(NTypeCompareValues(GetHandle(), pValue1, value1Size, pValue2, value2Size, &result));
		return result;
	}

	NInt GetValueHashCode(const void * pValue, NSizeType valueSize) const
	{
		NInt value;
		NCheck(NTypeGetValueHashCode(GetHandle(), pValue, valueSize, &value));
		return value;
	}

	NString ValueToString(const void * pValue, NSizeType valueSize, const NStringWrapper & format = NString()) const
	{
		HNString hValue;
		NCheck(NTypeValueToStringN(GetHandle(), pValue, valueSize, format.GetHandle(), &hValue));
		return NString(hValue, true);
	}

	bool TryParseValue(const NStringWrapper & value, const NStringWrapper & format, void * pValue, NSizeType valueSize)
	{
		NBool result;
		NCheck(NTypeTryParseValueN(GetHandle(), value.GetHandle(), format.GetHandle(), pValue, valueSize, &result));
		return result != 0;
	}
	bool TryParseValue(const NStringWrapper & value, void * pValue, NSizeType valueSize) { return TryParseValue(value, NString(), pValue, valueSize); }

	void ParseValue(const NStringWrapper & value, const NStringWrapper & format, void * pValue, NSizeType valueSize)
	{
		NCheck(NTypeParseValueN(GetHandle(), value.GetHandle(), format.GetHandle(), pValue, valueSize));
	}
	void ParseValue(const NStringWrapper & value, void * pValue, NSizeType valueSize) { ParseValue(value, NString(), pValue, valueSize); }

	::Neurotec::Reflection::NEnumConstantInfo GetDeclaredEnumConstant(const NStringWrapper & name) const;
	::Neurotec::Reflection::NPropertyInfo GetDeclaredField(const NStringWrapper & name) const;
	::Neurotec::Reflection::NConstantInfo GetDeclaredConstant(const NStringWrapper & name) const;
	::Neurotec::Reflection::NMethodInfo GetDeclaredMethod(const NStringWrapper & name) const;
	::Neurotec::NArrayWrapper< ::Neurotec::Reflection::NMethodInfo> GetDeclaredMethods(const NStringWrapper & name) const;
	::Neurotec::Reflection::NPropertyInfo GetDeclaredProperty(const NStringWrapper & name) const;
	::Neurotec::Reflection::NEventInfo GetDeclaredEvent(const NStringWrapper & name) const;
	::Neurotec::Reflection::NObjectPartInfo GetDeclaredPart(const NStringWrapper & name) const;

	NType GetEnumAlternative() const
	{
		return GetObject<HandleType, NType>(NTypeGetEnumAlternative, true);
	}

	const DeclaredEnumConstantCollection GetDeclaredEnumConstants() const
	{
		return DeclaredEnumConstantCollection(*this);
	}

	const DeclaredFieldCollection GetDeclaredFields() const
	{
		return DeclaredFieldCollection(*this);
	}

	const DeclaredConstantCollection GetDeclaredConstants() const
	{
		return DeclaredConstantCollection(*this);
	}

	const DeclaredConstructorCollection GetDeclaredConstructors() const
	{
		return DeclaredConstructorCollection(*this);
	}

	const DeclaredMethodCollection GetDeclaredMethods() const
	{
		return DeclaredMethodCollection(*this);
	}

	const DeclaredPropertyCollection GetDeclaredProperties() const
	{
		return DeclaredPropertyCollection(*this);
	}

	const DeclaredEventCollection GetDeclaredEvents() const
	{
		return DeclaredEventCollection(*this);
	}

	const DeclaredPartCollection GetDeclaredParts() const
	{
		return DeclaredPartCollection(*this);
	}
};

template<> struct NTypeTraitsBase<NUInt8>
{
	typedef NUInt8 NativeType;
	static NType GetNativeType() { return NTypes::NUInt8NativeTypeOf(); }
	static NUInt8 ToNative(const NUInt8 & value) { return value; }
	static NUInt8 FromNative(NUInt8 value, bool) { return value; }
	static void SetNative(const NativeType & sourceValue, NativeType * destinationValue) { *destinationValue = sourceValue; }
	static void FreeNative(NUInt8 value) { N_UNREFERENCED_PARAMETER(value); }
};

template<> struct NTypeTraitsBase<NInt8>
{
	typedef NInt8 NativeType;
	static NType GetNativeType() { return NTypes::NInt8NativeTypeOf(); }
	static NInt8 ToNative(const NInt8 & value) { return value; }
	static NInt8 FromNative(NInt8 value, bool) { return value; }
	static void SetNative(const NativeType & sourceValue, NativeType * destinationValue) { *destinationValue = sourceValue; }
	static void FreeNative(NInt8 value) { N_UNREFERENCED_PARAMETER(value); }
};

template<> struct NTypeTraitsBase<NUInt16>
{
	typedef NUInt16 NativeType;
	static NType GetNativeType() { return NTypes::NUInt16NativeTypeOf(); }
	static NUInt16 ToNative(const NUInt16 & value) { return value; }
	static NUInt16 FromNative(NUInt16 value, bool) { return value; }
	static void SetNative(const NativeType & sourceValue, NativeType * destinationValue) { *destinationValue = sourceValue; }
	static void FreeNative(NUInt16 value) { N_UNREFERENCED_PARAMETER(value); }
};

template<> struct NTypeTraitsBase<NInt16>
{
	typedef NInt16 NativeType;
	static NType GetNativeType() { return NTypes::NInt16NativeTypeOf(); }
	static NInt16 ToNative(const NInt16 & value) { return value; }
	static NInt16 FromNative(NInt16 value, bool) { return value; }
	static void SetNative(const NativeType & sourceValue, NativeType * destinationValue) { *destinationValue = sourceValue; }
	static void FreeNative(NInt16 value) { N_UNREFERENCED_PARAMETER(value); }
};

template<> struct NTypeTraitsBase<NUInt32>
{
	typedef NUInt32 NativeType;
	static NType GetNativeType() { return NTypes::NUInt32NativeTypeOf(); }
	static NUInt32 ToNative(const NUInt32 & value) { return value; }
	static NUInt32 FromNative(NUInt32 value, bool) { return value; }
	static void SetNative(const NativeType & sourceValue, NativeType * destinationValue) { *destinationValue = sourceValue; }
	static void FreeNative(NUInt32 value) { N_UNREFERENCED_PARAMETER(value); }
};

template<> struct NTypeTraitsBase<NInt32>
{
	typedef NInt32 NativeType;
	static NType GetNativeType() { return NTypes::NInt32NativeTypeOf(); }
	static NInt32 ToNative(const NInt32 & value) { return value; }
	static NInt32 FromNative(NInt32 value, bool) { return value; }
	static void SetNative(const NativeType & sourceValue, NativeType * destinationValue) { *destinationValue = sourceValue; }
	static void FreeNative(NInt32 value) { N_UNREFERENCED_PARAMETER(value); }
};

template<> struct NTypeTraitsBase<NUInt64>
{
	typedef NUInt64 NativeType;
	static NType GetNativeType() { return NTypes::NUInt64NativeTypeOf(); }
	static NUInt64 ToNative(const NUInt64 & value) { return value; }
	static NUInt64 FromNative(NUInt64 value, bool) { return value; }
	static void SetNative(const NativeType & sourceValue, NativeType * destinationValue) { *destinationValue = sourceValue; }
	static void FreeNative(NUInt64 value) { N_UNREFERENCED_PARAMETER(value); }
};

template<> struct NTypeTraitsBase<NInt64>
{
	typedef NInt64 NativeType;
	static NType GetNativeType() { return NTypes::NInt64NativeTypeOf(); }
	static NInt64 ToNative(const NInt64 & value) { return value; }
	static NInt64 FromNative(NInt64 value, bool) { return value; }
	static void SetNative(const NativeType & sourceValue, NativeType * destinationValue) { *destinationValue = sourceValue; }
	static void FreeNative(NInt64 value) { N_UNREFERENCED_PARAMETER(value); }
};

template<> struct NTypeTraitsBase<NSingle>
{
	typedef NSingle NativeType;
	static NType GetNativeType() { return NTypes::NSingleNativeTypeOf(); }
	static NSingle ToNative(const NSingle & value) { return value; }
	static NSingle FromNative(NSingle value, bool) { return value; }
	static void SetNative(const NativeType & sourceValue, NativeType * destinationValue) { *destinationValue = sourceValue; }
	static void FreeNative(NSingle value) { N_UNREFERENCED_PARAMETER(value); }
};

template<> struct NTypeTraitsBase<NDouble>
{
	typedef NDouble NativeType;
	static NType GetNativeType() { return NTypes::NDoubleNativeTypeOf(); }
	static NDouble ToNative(const NDouble & value) { return value; }
	static NDouble FromNative(NDouble value, bool) { return value; }
	static void SetNative(const NativeType & sourceValue, NativeType * destinationValue) { *destinationValue = sourceValue; }
	static void FreeNative(NDouble value) { N_UNREFERENCED_PARAMETER(value); }
};

template<> struct NTypeTraitsBase<bool>
{
	typedef NBoolean NativeType;
	static NType GetNativeType() { return NTypes::NBooleanNativeTypeOf(); }
	static NativeType ToNative(const bool & value) { return value ? NTrue : NFalse; }
	static bool FromNative(NBoolean value, bool) { return value != 0; }
	static void SetNative(const NativeType & sourceValue, NativeType * destinationValue) { *destinationValue = sourceValue; }
	static void FreeNative(NBoolean value) { N_UNREFERENCED_PARAMETER(value); }
};

template<> struct NTypeTraitsBase<NString>
{
	typedef HNString NativeType;
	static NType GetNativeType() { return NTypes::NStringNativeTypeOf(); }
	static HNString ToNative(const NString & value) { return value.GetHandle(); }
	static void SetNative(NativeType sourceValue, NativeType * destinationValue) { NCheck(NStringSet(sourceValue, destinationValue)); }
	static NString FromNative(HNString value, bool claimHandle) { return NString(value, claimHandle); }
	static void FreeNative(HNString value) { NStringFree(value); }
};

template<> struct NTypeTraitsBase<NStringWrapper>
{
	typedef HNString NativeType;
	static NType GetNativeType() { return NTypes::NStringNativeTypeOf(); }
	static HNString ToNative(const NStringWrapper & value) { return value.GetHandle(); }
	static void SetNative(NativeType sourceValue, NativeType * destinationValue) { NCheck(NStringSet(sourceValue, destinationValue)); }
	static NString FromNative(HNString value, bool claimHandle) { return NString(value, claimHandle); }
	static void FreeNative(HNString value) { NStringFree(value); }
};

template<> struct NTypeTraitsBase<NCallback>
{
	typedef HNCallback NativeType;
	static NType GetNativeType() { return NTypes::NCallbackNativeTypeOf(); }
	static NativeType ToNative(const NCallback & value) { return value.GetHandle(); }
	static void SetNative(NativeType sourceValue, NativeType * destinationValue) { NCheck(NCallbackSet(sourceValue, destinationValue)); }
	static NCallback FromNative(NativeType value, bool claimHandle) { return NCallback(value, claimHandle); }
	static void FreeNative(NativeType value) { NCallbackFree(value); }
};

}

N_DEFINE_ENUM_TYPE_TRAITS(Neurotec, NTypeCode)

#include <Core/NValue.hpp>
#include <Core/NModule.hpp>
#include <Core/NPropertyBag.hpp>
#include <Reflection/NEnumConstantInfo.hpp>
#include <Reflection/NConstantInfo.hpp>
#include <Reflection/NMethodInfo.hpp>
#include <Reflection/NPropertyInfo.hpp>
#include <Reflection/NEventInfo.hpp>
#include <Reflection/NObjectPartInfo.hpp>
#include <Reflection/NCollectionInfo.hpp>
#include <Reflection/NDictionaryInfo.hpp>
#include <Reflection/NArrayCollectionInfo.hpp>

namespace Neurotec
{

inline NValue NType::CreateInstance(const NStringWrapper & name, NAttributes attributes)
{
	HNValue hValue;
	NCheck(NTypeCreateInstanceWithNameN(name.GetHandle(), attributes, &hValue));
	return FromHandle<NValue>(hValue);
}

inline NValue NType::CreateInstance(NAttributes attributes) const
{
	HNValue hValue;
	NCheck(NTypeCreateInstance(GetHandle(), attributes, &hValue));
	return FromHandle<NValue>(hValue);
}

inline NModule NType::GetModule() const
{
	return GetObject<HandleType, NModule>(NTypeGetModule, true);
}

inline NValue NType::GetPropertyValue(const NObject & object, const NStringWrapper & name) const
{
	HNValue hValue;
	NCheck(NTypeGetPropertyValueN(GetHandle(), object.GetHandle(), name.GetHandle(), &hValue));
	return FromHandle<NValue>(hValue);
}

inline void NType::SetPropertyValue(const NObject & object, const NStringWrapper & name, const NValue & value) const
{
	NCheck(NTypeSetPropertyValueN(GetHandle(), object.GetHandle(), name.GetHandle(), value.GetHandle()));
}

inline void NType::CaptureProperties(const NObject & object, const NPropertyBag & properties) const
{
	NCheck(NTypeCapturePropertyValues(GetHandle(), object.GetHandle(), properties.GetHandle()));
}

template<typename InputIt>
inline NValue NType::InvokeMethod(const NObject & object, const NStringWrapper & name, InputIt firstParameter, InputIt lastParameter) const
{
	NArrayWrapper<NValue> parameters(firstParameter, lastParameter);
	HNValue hResult;
	NCheck(NTypeInvokeMethodN(GetHandle(), object.GetHandle(), name.GetHandle(), parameters.GetPtr(), parameters.GetCount(), &hResult));
	return FromHandle<NValue>(hResult);
}

inline NValue NType::InvokeMethod(const NObject & object, const NStringWrapper & name, const NPropertyBag & parameters) const
{
	HNValue hResult;
	NCheck(NTypeInvokeMethodWithPropertyBagN(GetHandle(), object.GetHandle(), name.GetHandle(), parameters.GetHandle(), &hResult));
	return FromHandle<NValue>(hResult);
}

inline NValue NType::InvokeMethod(const NObject & object, const NStringWrapper & name, const NStringWrapper & parameters) const
{
	HNValue hResult;
	NCheck(NTypeInvokeMethodWithStringN(GetHandle(), object.GetHandle(), name.GetHandle(), parameters.GetHandle(), &hResult));
	return FromHandle<NValue>(hResult);
}

inline void NType::AddEventHandler(const NObject & object, const NStringWrapper & name, const NValue & callback) const
{
	NCheck(NTypeAddEventHandlerN(GetHandle(), object.GetHandle(), name.GetHandle(), callback.GetHandle()));
}

inline void NType::AddEventHandler(const NObject & object, const NStringWrapper & name, const NType & callbackType, const NCallback & callback) const
{
	NCheck(NTypeAddEventHandlerNN(GetHandle(), object.GetHandle(), name.GetHandle(), callbackType.GetHandle(), callback.GetHandle()));
}

inline void NType::RemoveEventHandler(const NObject & object, const NStringWrapper & name, const NValue & callback) const
{
	NCheck(NTypeRemoveEventHandlerN(GetHandle(), object.GetHandle(), name.GetHandle(), callback.GetHandle()));
}

inline void NType::RemoveEventHandler(const NObject & object, const NStringWrapper & name, const NType & callbackType, const NCallback & callback) const
{
	NCheck(NTypeRemoveEventHandlerNN(GetHandle(), object.GetHandle(), name.GetHandle(), callbackType.GetHandle(), callback.GetHandle()));
}

inline ::Neurotec::Reflection::NEnumConstantInfo NType::GetDeclaredEnumConstant(const NStringWrapper & name) const
{
	HNEnumConstantInfo hValue;
	NCheck(NTypeGetDeclaredEnumConstantWithNameN(GetHandle(), name.GetHandle(), &hValue));
	return FromHandle< ::Neurotec::Reflection::NEnumConstantInfo>(hValue);
}

inline ::Neurotec::Reflection::NPropertyInfo NType::GetDeclaredField(const NStringWrapper & name) const
{
	HNPropertyInfo hValue;
	NCheck(NTypeGetDeclaredFieldWithNameN(GetHandle(), name.GetHandle(), &hValue));
	return FromHandle< ::Neurotec::Reflection::NPropertyInfo>(hValue);
}

inline ::Neurotec::Reflection::NConstantInfo NType::GetDeclaredConstant(const NStringWrapper & name) const
{
	HNConstantInfo hValue;
	NCheck(NTypeGetDeclaredConstantWithNameN(GetHandle(), name.GetHandle(), &hValue));
	return FromHandle< ::Neurotec::Reflection::NConstantInfo>(hValue);
}

inline ::Neurotec::Reflection::NMethodInfo NType::GetDeclaredMethod(const NStringWrapper & name) const
{
	HNMethodInfo hValue;
	NCheck(NTypeGetDeclaredMethodWithNameN(GetHandle(), name.GetHandle(), &hValue));
	return FromHandle< ::Neurotec::Reflection::NMethodInfo>(hValue);
}

inline Neurotec::NArrayWrapper< ::Neurotec::Reflection::NMethodInfo> NType::GetDeclaredMethods(const NStringWrapper & name) const
{
	HNMethodInfo * arhValues;
	NInt valueCount;
	NCheck(NTypeGetDeclaredMethodsWithNameN(GetHandle(), name.GetHandle(), &arhValues, &valueCount));
	return NArrayWrapper< ::Neurotec::Reflection::NMethodInfo>(arhValues, valueCount);
}

inline ::Neurotec::Reflection::NPropertyInfo NType::GetDeclaredProperty(const NStringWrapper & name) const
{
	HNPropertyInfo hValue;
	NCheck(NTypeGetDeclaredPropertyWithNameN(GetHandle(), name.GetHandle(), &hValue));
	return FromHandle< ::Neurotec::Reflection::NPropertyInfo>(hValue);
}

inline ::Neurotec::Reflection::NEventInfo NType::GetDeclaredEvent(const NStringWrapper & name) const
{
	HNEventInfo hValue;
	NCheck(NTypeGetDeclaredEventWithNameN(GetHandle(), name.GetHandle(), &hValue));
	return FromHandle< ::Neurotec::Reflection::NEventInfo>(hValue);
}

inline ::Neurotec::Reflection::NObjectPartInfo NType::GetDeclaredPart(const NStringWrapper & name) const
{
	HNObjectPartInfo hValue;
	NCheck(NTypeGetDeclaredPartWithNameN(GetHandle(), name.GetHandle(), &hValue));
	return FromHandle< ::Neurotec::Reflection::NObjectPartInfo>(hValue);
}

}

#endif // !N_TYPE_HPP_INCLUDED
