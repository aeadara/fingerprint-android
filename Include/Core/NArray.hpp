#include <Core/NValue.hpp>
#include <iterator>

#ifndef N_ARRAY_HPP_INCLUDED
#define N_ARRAY_HPP_INCLUDED

namespace Neurotec
{
#include <Core/NArray.h>
}

namespace Neurotec
{

class NArray : public NValue
{
	N_DECLARE_OBJECT_CLASS(NArray, NValue)

private:
	static HNArray Create(const NType & type, const void * arValues, NSizeType valuesSize, NInt valuesLength, NAttributes attributes = naNone)
	{
		HNArray hValue;
		NCheck(NArrayCreate(type.GetHandle(), arValues, valuesSize, valuesLength, attributes, &hValue));
		return hValue;
	}

	template<typename InputIt>
	static HNArray Create(InputIt first, InputIt last, NAttributes attributes = naNone)
	{
		typedef typename std::iterator_traits<InputIt>::value_type T;
		NArrayWrapper<T> values(first, last);
		HNArray hValue;
		NCheck(NArrayCreate(NTypeTraits<T>::GetNativeType().GetHandle(), values.GetPtr(), sizeof(typename NTypeTraits<T>::NativeType) * values.GetCount(), values.GetCount(), (NAttributes)(attributes | naPromoteValue), &hValue));
		values.Release();
		return hValue;
	}

	static HNArray Create(const void * const * arValues, NInt valuesLength, NTypes::PointerFreeProc pFree, void * pFreeParam,
		NTypes::PointerGetHashCodeProc pGetHashCode, void * pGetHashCodeParam, NTypes::PointerEqualsProc pEquals, void * pEqualsParam, NAttributes attributes)
	{
		NCallback free = NTypes::CreateCallback(NTypes::PointerFreeProcImpl, pFree, pFreeParam);
		NCallback getHashCode = NTypes::CreateCallback(NTypes::PointerGetHashCodeImpl, pGetHashCode, pGetHashCodeParam);
		NCallback equals = NTypes::CreateCallback(NTypes::PointerEqualsImpl, pEquals, pEqualsParam);
		HNArray hValue;
		NCheck(NArrayCreateCustomN(arValues, valuesLength, free.GetHandle(), getHashCode.GetHandle(), equals.GetHandle(), attributes, &hValue));
		return hValue;
	}

	static HNArray Create(const NByte * arValues, NInt valuesLength, NAttributes attributes)
	{
		HNArray hValue;
		NCheck(NArrayCreateFromByteArray(arValues, valuesLength, attributes, &hValue));
		return hValue;
	}

	static HNArray Create(const NSByte * arValues, NInt valuesLength, NAttributes attributes)
	{
		HNArray hValue;
		NCheck(NArrayCreateFromSByteArray(arValues, valuesLength, attributes, &hValue));
		return hValue;
	}

	static HNArray Create(const NUShort * arValues, NInt valuesLength, NAttributes attributes)
	{
		HNArray hValue;
		NCheck(NArrayCreateFromUInt16Array(arValues, valuesLength, attributes, &hValue));
		return hValue;
	}

	static HNArray Create(const NShort * arValues, NInt valuesLength, NAttributes attributes)
	{
		HNArray hValue;
		NCheck(NArrayCreateFromInt16Array(arValues, valuesLength, attributes, &hValue));
		return hValue;
	}

	static HNArray Create(const NUInt * arValues, NInt valuesLength, NAttributes attributes)
	{
		HNArray hValue;
		NCheck(NArrayCreateFromUInt32Array(arValues, valuesLength, attributes, &hValue));
		return hValue;
	}

	static HNArray Create(const NInt * arValues, NInt valuesLength, NAttributes attributes)
	{
		HNArray hValue;
		NCheck(NArrayCreateFromInt32Array(arValues, valuesLength, attributes, &hValue));
		return hValue;
	}

	static HNArray Create(const NULong * arValues, NInt valuesLength, NAttributes attributes)
	{
		HNArray hValue;
		NCheck(NArrayCreateFromUInt64Array(arValues, valuesLength, attributes, &hValue));
		return hValue;
	}

	static HNArray Create(const NLong * arValues, NInt valuesLength, NAttributes attributes)
	{
		HNArray hValue;
		NCheck(NArrayCreateFromInt64Array(arValues, valuesLength, attributes, &hValue));
		return hValue;
	}

	static HNArray Create(const NFloat * arValues, NInt valuesLength, NAttributes attributes)
	{
		HNArray hValue;
		NCheck(NArrayCreateFromSingleArray(arValues, valuesLength, attributes, &hValue));
		return hValue;
	}

	static HNArray Create(const NDouble * arValues, NInt valuesLength, NAttributes attributes)
	{
		HNArray hValue;
		NCheck(NArrayCreateFromDoubleArray(arValues, valuesLength, attributes, &hValue));
		return hValue;
	}

	static HNArray Create(const bool * arValues, NInt valuesLength, NAttributes attributes)
	{
		if (valuesLength < 0) NThrowArgumentLessThanZeroException(N_T("valuesLength"));
		if (!arValues && valuesLength != 0) NThrowArgumentNullException("arValues");
		NAutoFree values(NAlloc(valuesLength * sizeof(NBool)));
		for (NInt i = 0; i < valuesLength; i++)
		{
			((NBool *)values.Get())[i] = arValues[i] ? NTrue : NFalse;
		}
		HNArray hValue;
		NCheck(NArrayCreateFromBooleanArray((NBool *)values.Get(), valuesLength, (NAttributes)(attributes | naPromoteValue), &hValue));
		values.Release();
		return hValue;
	}

	static HNArray Create(const void * const * arValues, NInt valuesLength, NAttributes attributes)
	{
		HNArray hValue;
		NCheck(NArrayCreateFromPointerArray(arValues, valuesLength, attributes, &hValue));
		return hValue;
	}

	static HNArray Create(const NString * arValues, NInt valuesLength, NAttributes attributes = naNone)
	{
		HNArray hValue;
		NCheck(NArrayCreateFromStringArrayN(reinterpret_cast<const HNString *>(arValues), valuesLength, (NAttributes)(attributes & ~naPromoteValue), &hValue));
		return hValue;
	}

	static HNArray Create(const NChar * const * arszValues, NInt valuesLength, NAttributes attributes)
	{
		HNArray hValue;
		NCheck(NArrayCreateFromStringArray(arszValues, valuesLength, attributes, &hValue));
		return hValue;
	}

	static HNArray Create(const NType & type, const NArrayWrapper<NObject>& values, NAttributes attributes)
	{
		HNArray hValue;
		NCheck(NArrayCreateFromObjectArray(type.GetHandle(), values.GetPtr(), values.GetCount(), attributes, &hValue));
		return hValue;
	}

	static HNArray Create(const NType & type, const NCallback * arValues, NInt valuesLength, NAttributes attributes)
	{
		HNArray hValue;
		NCheck(NArrayCreateFromCallbackArray(type.GetHandle(), reinterpret_cast<const HNCallback *>(arValues), valuesLength, (NAttributes)(attributes | naPromoteValue), &hValue));
		return hValue;
	}

public:
	static NArray FromSizeTypeArray(const NSizeType * arValues, NInt valuesLength, NAttributes attributes = naNone)
	{
		HNArray hValue;
		NCheck(NArrayCreateFromSizeTypeArray(arValues, valuesLength, attributes, &hValue));
		return FromHandle<NArray>(hValue);
	}

	static NArray FromSSizeTypeArray(const NSSizeType * arValues, NInt valuesLength, NAttributes attributes = naNone)
	{
		HNArray hValue;
		NCheck(NArrayCreateFromSSizeTypeArray(arValues, valuesLength, attributes, &hValue));
		return FromHandle<NArray>(hValue);
	}

	static NArray FromResultArray(const NResult * arValues, NInt valuesLength, NAttributes attributes = naNone)
	{
		HNArray hValue;
		NCheck(NArrayCreateFromResultArray(arValues, valuesLength, attributes, &hValue));
		return FromHandle<NArray>(hValue);
	}

	static NArray FromCharArray(const NChar * arValues, NInt valuesLength, NAttributes attributes = naNone)
	{
		HNArray hValue;
		NCheck(NArrayCreateFromCharArray(arValues, valuesLength, attributes, &hValue));
		return FromHandle<NArray>(hValue);
	}

	NArray(const NType & type, const void * const * arValues, NSizeType valuesSize, NInt valuesLength, NAttributes attributes = naNone)
		: NValue(Create(type, arValues, valuesSize, valuesLength, attributes), true)
	{
	}

	template<typename InputIt>
	NArray(InputIt first, InputIt last, NAttributes attributes = naNone)
		: NValue(Create<InputIt>(first, last, attributes), true)
	{
	}

	NArray(const NByte * arValues, NInt valuesLength, NAttributes attributes = naNone)
		: NValue(Create(arValues, valuesLength, attributes), true)
	{
	}

	NArray(const NSByte * arValues, NInt valuesLength, NAttributes attributes = naNone)
		: NValue(Create(arValues, valuesLength, attributes), true)
	{
	}

	NArray(const NUShort * arValues, NInt valuesLength, NAttributes attributes = naNone)
		: NValue(Create(arValues, valuesLength, attributes), true)
	{
	}

	NArray(const NShort * arValues, NInt valuesLength, NAttributes attributes = naNone)
		: NValue(Create(arValues, valuesLength, attributes), true)
	{
	}

	NArray(const NUInt * arValues, NInt valuesLength, NAttributes attributes = naNone)
		: NValue(Create(arValues, valuesLength, attributes), true)
	{
	}

	NArray(const NInt * arValues, NInt valuesLength, NAttributes attributes = naNone)
		: NValue(Create(arValues, valuesLength, attributes), true)
	{
	}

	NArray(const NULong * arValues, NInt valuesLength, NAttributes attributes = naNone)
		: NValue(Create(arValues, valuesLength, attributes), true)
	{
	}

	NArray(const NLong * arValues, NInt valuesLength, NAttributes attributes = naNone)
		: NValue(Create(arValues, valuesLength, attributes), true)
	{
	}

	NArray(const NFloat * arValues, NInt valuesLength, NAttributes attributes = naNone)
		: NValue(Create(arValues, valuesLength, attributes), true)
	{
	}

	NArray(const NDouble * arValues, NInt valuesLength, NAttributes attributes = naNone)
		: NValue(Create(arValues, valuesLength, attributes), true)
	{
	}

	NArray(const bool * arValues, NInt valuesLength, NAttributes attributes = naNone)
		: NValue(Create(arValues, valuesLength, attributes), true)
	{
	}

	NArray(const void * const * arValues, NInt valuesLength, NAttributes attributes = naNone)
		: NValue(Create(arValues, valuesLength, attributes), true)
	{
	}

	NArray(const NString * arValues, NInt valuesLength, NAttributes attributes = naNone)
		: NValue(Create(arValues, valuesLength, attributes), true)
	{
	}

	NArray(const NChar * const * arszValues, NInt valuesLength, NAttributes attributes = naNone)
		: NValue(Create(arszValues, valuesLength, attributes), true)
	{
	}

	NArray(const NType & type, const NArrayWrapper<NObject>& values, NAttributes attributes = naNone)
		: NValue(Create(type, values, attributes), true)
	{
	}

	NArray(const NType & type, const NCallback * arValues, NInt valuesLength, NAttributes attributes = naNone)
		: NValue(Create(type, arValues, valuesLength, attributes), true)
	{
	}

	NInt GetLength() const
	{
		NInt value;
		NCheck(NArrayGetLength(GetHandle(), &value));
		return value;
	}

	void CopyTo(const NType & type, void * arValues, NSizeType valuesSize, NInt valuesLength, NAttributes attributes = naNone, const NStringWrapper & format = NString()) const
	{
		NCheck(NArrayCopyTo(GetHandle(), type.GetHandle(), attributes, format.GetHandle(), arValues, valuesSize, valuesLength));
	}

	void CopyTo(NByte * arValues, NInt valuesLength, NAttributes attributes = naNone, const NStringWrapper & format = NString()) const
	{
		NCheck(NArrayCopyToByteArray(GetHandle(), attributes, format.GetHandle(), arValues, valuesLength));
	}
	NArrayWrapper<NByte> ToByteArray(NAttributes attributes = naNone, const NStringWrapper & format = NString()) const
	{
		NArrayWrapper<NByte> values(GetLength());
		CopyTo(values.GetPtr(), values.GetCount(), attributes, format);
		return values;
	}

	void CopyTo(NSByte * arValues, NInt valuesLength, NAttributes attributes = naNone, const NStringWrapper & format = NString()) const
	{
		NCheck(NArrayCopyToSByteArray(GetHandle(), attributes, format.GetHandle(), arValues, valuesLength));
	}
	NArrayWrapper<NSByte> ToSByteArray(NAttributes attributes = naNone, const NStringWrapper & format = NString()) const
	{
		NArrayWrapper<NSByte> values(GetLength());
		CopyTo(values.GetPtr(), values.GetCount(), attributes, format);
		return values;
	}

	void CopyTo(NUShort * arValues, NInt valuesLength, NAttributes attributes = naNone, const NStringWrapper & format = NString()) const
	{
		NCheck(NArrayCopyToUInt16Array(GetHandle(), attributes, format.GetHandle(), arValues, valuesLength));
	}
	NArrayWrapper<NUShort> ToUInt16Array(NAttributes attributes = naNone, const NStringWrapper & format = NString()) const
	{
		NArrayWrapper<NUShort> values(GetLength());
		CopyTo(values.GetPtr(), values.GetCount(), attributes, format);
		return values;
	}

	void CopyTo(NShort * arValues, NInt valuesLength, NAttributes attributes = naNone, const NStringWrapper & format = NString()) const
	{
		NCheck(NArrayCopyToInt16Array(GetHandle(), attributes, format.GetHandle(), arValues, valuesLength));
	}
	NArrayWrapper<NShort> ToInt16Array(NAttributes attributes = naNone, const NStringWrapper & format = NString()) const
	{
		NArrayWrapper<NShort> values(GetLength());
		CopyTo(values.GetPtr(), values.GetCount(), attributes, format);
		return values;
	}

	void CopyTo(NUInt * arValues, NInt valuesLength, NAttributes attributes = naNone, const NStringWrapper & format = NString()) const
	{
		NCheck(NArrayCopyToUInt32Array(GetHandle(), attributes, format.GetHandle(), arValues, valuesLength));
	}
	NArrayWrapper<NUInt> ToUInt32Array(NAttributes attributes = naNone, const NStringWrapper & format = NString()) const
	{
		NArrayWrapper<NUInt> values(GetLength());
		CopyTo(values.GetPtr(), values.GetCount(), attributes, format);
		return values;
	}

	void CopyTo(NInt * arValues, NInt valuesLength, NAttributes attributes = naNone, const NStringWrapper & format = NString()) const
	{
		NCheck(NArrayCopyToInt32Array(GetHandle(), attributes, format.GetHandle(), arValues, valuesLength));
	}
	NArrayWrapper<NInt> ToInt32Array(NAttributes attributes = naNone, const NStringWrapper & format = NString()) const
	{
		NArrayWrapper<NInt> values(GetLength());
		CopyTo(values.GetPtr(), values.GetCount(), attributes, format);
		return values;
	}

	void CopyTo(NULong * arValues, NInt valuesLength, NAttributes attributes = naNone, const NStringWrapper & format = NString()) const
	{
		NCheck(NArrayCopyToUInt64Array(GetHandle(), attributes, format.GetHandle(), arValues, valuesLength));
	}
	NArrayWrapper<NULong> ToUInt64Array(NAttributes attributes = naNone, const NStringWrapper & format = NString()) const
	{
		NArrayWrapper<NULong> values(GetLength());
		CopyTo(values.GetPtr(), values.GetCount(), attributes, format);
		return values;
	}

	void CopyTo(NLong * arValues, NInt valuesLength, NAttributes attributes = naNone, const NStringWrapper & format = NString()) const
	{
		NCheck(NArrayCopyToInt64Array(GetHandle(), attributes, format.GetHandle(), arValues, valuesLength));
	}
	NArrayWrapper<NLong> ToInt64Array(NAttributes attributes = naNone, const NStringWrapper & format = NString()) const
	{
		NArrayWrapper<NLong> values(GetLength());
		CopyTo(values.GetPtr(), values.GetCount(), attributes, format);
		return values;
	}

	void CopyTo(NFloat * arValues, NInt valuesLength, NAttributes attributes = naNone, const NStringWrapper & format = NString()) const
	{
		NCheck(NArrayCopyToSingleArray(GetHandle(), attributes, format.GetHandle(), arValues, valuesLength));
	}
	NArrayWrapper<NFloat> ToSingleArray(NAttributes attributes = naNone, const NStringWrapper & format = NString()) const
	{
		NArrayWrapper<NFloat> values(GetLength());
		CopyTo(values.GetPtr(), values.GetCount(), attributes, format);
		return values;
	}

	void CopyTo(NDouble * arValues, NInt valuesLength, NAttributes attributes = naNone, const NStringWrapper & format = NString()) const
	{
		NCheck(NArrayCopyToDoubleArray(GetHandle(), attributes, format.GetHandle(), arValues, valuesLength));
	}
	NArrayWrapper<NDouble> ToDoubleArray(NAttributes attributes = naNone, const NStringWrapper & format = NString()) const
	{
		NArrayWrapper<NDouble> values(GetLength());
		CopyTo(values.GetPtr(), values.GetCount(), attributes, format);
		return values;
	}

	void CopyTo(bool * arValues, NInt valuesLength, NAttributes attributes = naNone, const NStringWrapper & format = NString()) const
	{
		if (valuesLength < 0) NThrowArgumentLessThanZeroException(N_T("valuesLength"));
		if (!arValues && valuesLength != 0) NThrowArgumentNullException("arValues");
		auto_array<NBool> values(valuesLength);
		NCheck(NArrayCopyToBooleanArray(GetHandle(), attributes, format.GetHandle(), values.get(), values.size()));
		for (NInt i = 0; i < valuesLength; i++)
		{
			arValues[i] = values[i] != 0;
		}
	}
	NArrayWrapper<bool> ToBooleanArray(NAttributes attributes = naNone, const NStringWrapper & format = NString()) const
	{
		NArrayWrapper<bool> values(GetLength());
		NCheck(NArrayCopyToBooleanArray(GetHandle(), attributes, format.GetHandle(), values.GetPtr(), values.GetCount()));
		return values;
	}

	void CopyToSizeTypeArray(NSizeType * arValues, NInt valuesLength, NAttributes attributes = naNone, const NStringWrapper & format = NString()) const
	{
		NCheck(NArrayCopyToSizeTypeArray(GetHandle(), attributes, format.GetHandle(), arValues, valuesLength));
	}
	NArrayWrapper<NSizeType> ToSizeTypeArray(NAttributes attributes = naNone, const NStringWrapper & format = NString()) const
	{
		NArrayWrapper<NSizeType> values(GetLength());
		CopyToSizeTypeArray(values.GetPtr(), values.GetCount(), attributes, format);
		return values;
	}

	void CopyToSSizeTypeArray(NSSizeType * arValues, NInt valuesLength, NAttributes attributes = naNone, const NStringWrapper & format = NString()) const
	{
		NCheck(NArrayCopyToSSizeTypeArray(GetHandle(), attributes, format.GetHandle(), arValues, valuesLength));
	}
	NArrayWrapper<NSSizeType> ToSSizeTypeArray(NAttributes attributes = naNone, const NStringWrapper & format = NString()) const
	{
		NArrayWrapper<NSSizeType> values(GetLength());
		CopyToSSizeTypeArray(values.GetPtr(), values.GetCount(), attributes, format);
		return values;
	}

	void CopyTo(void * * arValues, NInt valuesLength, NAttributes attributes = naNone, const NStringWrapper & format = NString()) const
	{
		NCheck(NArrayCopyToPointerArray(GetHandle(), attributes, format.GetHandle(), arValues, valuesLength));
	}
	NArrayWrapper<void *> ToPointerArray(NAttributes attributes = naNone, const NStringWrapper & format = NString()) const
	{
		NArrayWrapper<void *> values(GetLength());
		CopyTo(values.GetPtr(), values.GetCount(), attributes, format);
		return values;
	}

	void CopyToResultArray(NResult * arValues, NInt valuesLength, NAttributes attributes = naNone, const NStringWrapper & format = NString()) const
	{
		NCheck(NArrayCopyToResultArray(GetHandle(), attributes, format.GetHandle(), arValues, valuesLength));
	}
	NArrayWrapper<NResult> ToResultArray(NAttributes attributes = naNone, const NStringWrapper & format = NString()) const
	{
		NArrayWrapper<NResult> values(GetLength());
		CopyToResultArray(values.GetPtr(), values.GetCount(), attributes, format);
		return values;
	}

	void CopyToCharArray(NChar * arValues, NInt valuesLength, NAttributes attributes = naNone, const NStringWrapper & format = NString()) const
	{
		NCheck(NArrayCopyToCharArray(GetHandle(), attributes, format.GetHandle(), arValues, valuesLength));
	}
	NArrayWrapper<NChar> ToCharArray(NAttributes attributes = naNone, const NStringWrapper & format = NString()) const
	{
		NArrayWrapper<NChar> values(GetLength());
		CopyToCharArray(values.GetPtr(), values.GetCount(), attributes, format);
		return values;
	}

	void CopyTo(NString * arValues, NInt valuesLength, NAttributes attributes = naNone, const NStringWrapper & format = NString()) const
	{
		NCheck(NArrayCopyToStringArray(GetHandle(), attributes, format.GetHandle(), reinterpret_cast<HNString *>(arValues), valuesLength));
	}
	NArrayWrapper<NString> ToStringArray(NAttributes attributes = naNone, const NStringWrapper & format = NString()) const
	{
		NArrayWrapper<NString> values(GetLength());
		NCheck(NArrayCopyToStringArray(GetHandle(), attributes, format.GetHandle(), values.GetPtr(), values.GetCount()));
		return values;
	}

	void CopyTo(const NType & type, NObject * arValues, NInt valuesLength, NAttributes attributes = naNone, const NStringWrapper & format = NString()) const
	{
		NArrayWrapper<NObject> values(valuesLength, true);
		NCheck(NArrayCopyToObjectArray(GetHandle(), type.GetHandle(), attributes, format.GetHandle(), values.GetPtr(), values.GetCount()));
		values.CopyTo(arValues, valuesLength);
	}
	NArrayWrapper<NObject> ToObjectArray(const NType & type, NAttributes attributes = naNone, const NStringWrapper & format = NString()) const
	{
		NArrayWrapper<NObject> values(GetLength(), true);
		NCheck(NArrayCopyToObjectArray(GetHandle(), type.GetHandle(), attributes, format.GetHandle(), values.GetPtr(), values.GetCount()));
		return values;
	}

	void CopyTo(const NType & type, NCallback * arValues, NInt valuesLength, NAttributes attributes = naNone, const NStringWrapper & format = NString()) const
	{
		NCheck(NArrayCopyToCallbackArray(GetHandle(), type.GetHandle(), attributes, format.GetHandle(), reinterpret_cast<HNCallback *>(arValues), valuesLength));
	}

	NArrayWrapper<NCallback> ToCallbackArray(const NType & type, NAttributes attributes = naNone, const NStringWrapper & format = NString()) const
	{
		NArrayWrapper<NCallback> values(GetLength());
		NCheck(NArrayCopyToCallbackArray(GetHandle(), type.GetHandle(), attributes, format.GetHandle(), values.GetPtr(), values.GetCount()));
		return values;
	}

	NValue GetValue(NInt index) const
	{
		HNValue hValue;
		NCheck(NArrayGetValue(GetHandle(), index, &hValue));
		return FromHandle<NValue>(hValue);
	}

	void GetValueAs(NInt index, const NType & type, void * pResult, NSizeType resultSize, NAttributes attributes = naNone, const NStringWrapper & format = NString()) const
	{
		NCheck(NArrayGetValueAs(GetHandle(), index, type.GetHandle(), attributes, format.GetHandle(), pResult, resultSize));
	}

	NByte GetValueAsByte(NInt index, NAttributes attributes = naNone, const NStringWrapper & format = NString()) const
	{
		NByte value;
		NCheck(NArrayGetValueAsByte(GetHandle(), index, attributes, format.GetHandle(), &value));
		return value;
	}

	NSByte GetValueAsSByte(NInt index, NAttributes attributes = naNone, const NStringWrapper & format = NString()) const
	{
		NSByte value;
		NCheck(NArrayGetValueAsSByte(GetHandle(), index, attributes, format.GetHandle(), &value));
		return value;
	}

	NUShort GetValueAsUInt16(NInt index, NAttributes attributes = naNone, const NStringWrapper & format = NString()) const
	{
		NUShort value;
		NCheck(NArrayGetValueAsUInt16(GetHandle(), index, attributes, format.GetHandle(), &value));
		return value;
	}

	NShort GetValueAsInt16(NInt index, NAttributes attributes = naNone, const NStringWrapper & format = NString()) const
	{
		NShort value;
		NCheck(NArrayGetValueAsInt16(GetHandle(), index, attributes, format.GetHandle(), &value));
		return value;
	}

	NUInt GetValueAsUInt32(NInt index, NAttributes attributes = naNone, const NStringWrapper & format = NString()) const
	{
		NUInt value;
		NCheck(NArrayGetValueAsUInt32(GetHandle(), index, attributes, format.GetHandle(), &value));
		return value;
	}

	NInt GetValueAsInt32(NInt index, NAttributes attributes = naNone, const NStringWrapper & format = NString()) const
	{
		NInt value;
		NCheck(NArrayGetValueAsInt32(GetHandle(), index, attributes, format.GetHandle(), &value));
		return value;
	}

	NULong GetValueAsUInt64(NInt index, NAttributes attributes = naNone, const NStringWrapper & format = NString()) const
	{
		NULong value;
		NCheck(NArrayGetValueAsUInt64(GetHandle(), index, attributes, format.GetHandle(), &value));
		return value;
	}

	NLong GetValueAsInt64(NInt index, NAttributes attributes = naNone, const NStringWrapper & format = NString()) const
	{
		NLong value;
		NCheck(NArrayGetValueAsInt64(GetHandle(), index, attributes, format.GetHandle(), &value));
		return value;
	}

	NFloat GetValueAsSingle(NInt index, NAttributes attributes = naNone, const NStringWrapper & format = NString()) const
	{
		NFloat value;
		NCheck(NArrayGetValueAsSingle(GetHandle(), index, attributes, format.GetHandle(), &value));
		return value;
	}

	NDouble GetValueAsDouble(NInt index, NAttributes attributes = naNone, const NStringWrapper & format = NString()) const
	{
		NDouble value;
		NCheck(NArrayGetValueAsDouble(GetHandle(), index, attributes, format.GetHandle(), &value));
		return value;
	}

	bool GetValueAsBoolean(NInt index, NAttributes attributes = naNone, const NStringWrapper & format = NString()) const
	{
		NBool value;
		NCheck(NArrayGetValueAsBoolean(GetHandle(), index, attributes, format.GetHandle(), &value));
		return value != 0;
	}

	NSizeType GetValueAsSizeType(NInt index, NAttributes attributes = naNone, const NStringWrapper & format = NString()) const
	{
		NSizeType value;
		NCheck(NArrayGetValueAsSizeType(GetHandle(), index, attributes, format.GetHandle(), &value));
		return value;
	}

	NSSizeType GetValueAsSSizeType(NInt index, NAttributes attributes = naNone, const NStringWrapper & format = NString()) const
	{
		NSSizeType value;
		NCheck(NArrayGetValueAsSSizeType(GetHandle(), index, attributes, format.GetHandle(), &value));
		return value;
	}

	void * GetValueAsPointer(NInt index, NAttributes attributes = naNone, const NStringWrapper & format = NString()) const
	{
		void * value;
		NCheck(NArrayGetValueAsPointer(GetHandle(), index, attributes, format.GetHandle(), &value));
		return value;
	}

	NResult GetValueAsResult(NInt index, NAttributes attributes = naNone, const NStringWrapper & format = NString()) const
	{
		NResult value;
		NCheck(NArrayGetValueAsResult(GetHandle(), index, attributes, format.GetHandle(), &value));
		return value;
	}

	NChar GetValueAsChar(NInt index, NAttributes attributes = naNone, const NStringWrapper & format = NString()) const
	{
		NChar value;
		NCheck(NArrayGetValueAsChar(GetHandle(), index, attributes, format.GetHandle(), &value));
		return value;
	}

	NString GetValueAsString(NInt index, NAttributes attributes = naNone, const NStringWrapper & format = NString()) const
	{
		HNString hValue;
		NCheck(NArrayGetValueAsString(GetHandle(), index, attributes, format.GetHandle(), &hValue));
		return NString(hValue, true);
	}

	NObject GetValueAsObject(NInt index, const NType & type, NAttributes attributes = naNone, const NStringWrapper & format = NString()) const
	{
		HNObject hValue;
		NCheck(NArrayGetValueAsObject(GetHandle(), index, type.GetHandle(), attributes, format.GetHandle(), &hValue));
		return FromHandle<NObject>(hValue, true);
	}

	NCallback GetValueAsCallback(NInt index, const NType & type, NAttributes attributes = naNone, const NStringWrapper & format = NString()) const
	{
		HNCallback hValue;
		NCheck(NArrayGetValueAsCallback(GetHandle(), index, type.GetHandle(), attributes, format.GetHandle(), &hValue));
		return NCallback(hValue, true);
	}
};

}

#endif // !N_ARRAY_HPP_INCLUDED
