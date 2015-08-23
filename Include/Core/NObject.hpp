#include <Core/NTypes.hpp>

#ifndef N_OBJECT_HPP_INCLUDED
#define N_OBJECT_HPP_INCLUDED

#include <Core/NParameters.hpp>
#include <Core/NCallback.hpp>
namespace Neurotec
{
namespace IO
{
extern "C"
{
N_DECLARE_OBJECT_TYPE(NBuffer, NObject)
N_DECLARE_OBJECT_TYPE(NStream, NObject)
}
}
namespace Reflection
{
extern "C"
{
N_DECLARE_OBJECT_TYPE(NParameterInfo, NObject)
N_DECLARE_OBJECT_TYPE(NMemberInfo, NObject)
N_DECLARE_OBJECT_TYPE(NEnumConstantInfo, NMemberInfo)
N_DECLARE_OBJECT_TYPE(NConstantInfo, NMemberInfo)
N_DECLARE_OBJECT_TYPE(NMethodInfo, NMemberInfo)
N_DECLARE_OBJECT_TYPE(NPropertyInfo, NMemberInfo)
N_DECLARE_OBJECT_TYPE(NEventInfo, NMemberInfo)
N_DECLARE_OBJECT_TYPE(NObjectPartInfo, NMemberInfo)
N_DECLARE_OBJECT_TYPE(NCollectionInfo, NObjectPartInfo)
N_DECLARE_OBJECT_TYPE(NDictionaryInfo, NObjectPartInfo)
N_DECLARE_OBJECT_TYPE(NArrayCollectionInfo, NObjectPartInfo)
}
}
namespace Collections
{
extern "C"
{
N_DECLARE_OBJECT_TYPE(NCollection, NObjectPart)
N_DECLARE_OBJECT_TYPE(NDictionary, NObjectPart)
N_DECLARE_OBJECT_TYPE(NArrayCollection, NObjectPart)
}
}
using ::Neurotec::IO::HNBuffer;
using ::Neurotec::IO::HNStream;
using ::Neurotec::Reflection::HNMemberInfo;
using ::Neurotec::Reflection::HNConstantInfo;
using ::Neurotec::Reflection::HNEnumConstantInfo;
using ::Neurotec::Reflection::HNMethodInfo;
using ::Neurotec::Reflection::HNPropertyInfo;
using ::Neurotec::Reflection::HNEventInfo;
using ::Neurotec::Reflection::HNObjectPartInfo;
using ::Neurotec::Reflection::HNCollectionInfo;
using ::Neurotec::Reflection::HNDictionaryInfo;
using ::Neurotec::Reflection::HNArrayCollectionInfo;
#include <Core/NObject.h>
}
#include <Interop/NWindows.hpp>
#include <Threading/NMonitor.hpp>
#include <memory>
#include <cstring>

namespace Neurotec
{

#undef N_OBJECT_REF_RET

const NUInt N_OBJECT_REF_RET = 0x00000010;

namespace Collections
{
template<typename TOwner> class NStringReadOnlyCollection;
template<typename TOwner> class NStringCollection;
}

class NType;

class NObject : public NObjectBase
{
private:
	typedef NType (* NativeTypeOfProc)();

private:
	HNObject handle;
#ifdef N_DEBUG
	bool isDisposed;
#endif

public:
	class PropertyChangedEventArgs;

protected:
	template<typename F>
	class EventHandler;
	template<typename F>
	class PropertyChangedEventHandler;

#ifdef N_DEBUG
	void Check() const
	{
		if (IsDisposed()) NThrowInvalidOperationException(N_T("Native object is disposed"));
	}
#endif

	void SetHandle(HNObject handle, bool claimHandle = false)
	{
		if (this->handle == handle)
			return;
		if (this->handle)
		{
			Unref();
			this->handle = NULL;
		}
		this->handle = handle;
		if (this->handle && !claimHandle)
			Ref();
	}

//#include <Core/NNoDeprecate.h>
	template<typename THandle> NString GetString(NResult (N_CALLBACK pGetString)(THandle handle, HNString * phValue)) const;
	template<typename THandle> void SetString(NResult (N_CALLBACK pSetString)(THandle handle, HNString hValue), const NStringWrapper & value);
	template<typename THandle, typename T> T GetObject(NResult (N_CALLBACK pGetObject)(THandle handle, typename T::HandleType * phValue), bool ownsHandle = true) const;

	template<typename THandle, typename T> void SetObject(NResult (N_CALLBACK pSetObject)(THandle handle, typename T::HandleType hValue), const T& value)
	{
		THandle hObj = static_cast<THandle>(GetHandle());
		NCheck(pSetObject(hObj, value.GetHandle()));
	}

	template<typename THandle, typename T> NArrayWrapper<T> GetObjects(NResult (N_CALLBACK pGetObjects)(THandle handle, typename T::HandleType * * parhValues, NInt * pValueCount), bool ownsHandles = true) const;
	template<typename THandle, typename T> NArrayWrapper<T> GetObjects(NResult (N_CALLBACK pGetObjects)(THandle handle, typename T::HandleType * parhValues, NInt valueCount), bool ownsHandles = true) const;
//#include <Core/NReDeprecate.h>

public:
	typedef void (* Callback)(NObject * pObject, void * pParam);
	typedef void (* PropertyChangedCallback)(NObject * pObject, NString propertyName, void * pParam);

	static ::Neurotec::NType NObjectCallbackNativeTypeOf();
	static ::Neurotec::NType NObjectPropertyChangedCallbackNativeTypeOf();

	static void Unref(HNObject handle)
	{
		if (handle) NCheck(NObjectUnref(handle));
	}

	template<typename THandle> static void UnrefElements(THandle * arhObjects, NInt objectCount)
	{
		THandle p0 = NULL;
		HNObject p = p0;
		NCheck(NObjectUnrefElements(reinterpret_cast<HNObject *>(arhObjects), objectCount));
		N_UNREFERENCED_PARAMETER(p);
	}

	template<typename THandle> static void UnrefArray(THandle * arhObjects, NInt objectCount)
	{
		THandle p0 = NULL;
		HNObject p = p0;
		NCheck(NObjectUnrefArray(reinterpret_cast<HNObject *>(arhObjects), objectCount));
		N_UNREFERENCED_PARAMETER(p);
	}

	static bool Equals(const NObject & object1, const NObject & object2)
	{
		return object1.Equals(object2);
	}

#include <Core/NNoDeprecate.h>
	template<typename T> static T FromHandle(typename T::HandleType handle, bool ownsHandle = true);

	template<typename T> static NInt ToHandleArray(const T * arpObjects, NInt objectCount, typename T::HandleType * arhObjects, NInt objectsLength, bool addRef = false);

	template<typename T> static T GetObject(NResult (N_CALLBACK pGetObject)(typename T::HandleType * phValue), bool ownsHandle = true);

	template<typename T> static void SetObject(NResult (N_CALLBACK pSetObject)(typename T::HandleType hValue), const T & value)
	{
		NCheck(pSetObject(value.GetHandle()));
	}

	template<typename T> static NArrayWrapper<T> GetObjects(NResult (N_CALLBACK pGetObjects)(typename T::HandleType * * parhValues, NInt * pValueCount), bool ownsHandle = true);
#include <Core/NReDeprecate.h>

	static NString GetString(NResult (N_CALLBACK pGetString)(HNString * phValue))
	{
		HNString hValue;
		NCheck(pGetString(&hValue));
		return NString(hValue, true);
	}

	static void SetString(NResult (N_CALLBACK pSetString)(HNString hValue), const NStringWrapper & value)
	{
		NCheck(pSetString(value.GetHandle()));
	}

	static void CopyProperties(NObject * pDstObject, const NObject * pSrcObject)
	{
		if (!pDstObject) NThrowArgumentNullException(N_T("pDstObject"));
		if (!pSrcObject) NThrowArgumentNullException(N_T("pSrcObject"));
		NCheck(NObjectCopyProperties(pDstObject->GetHandle(), pSrcObject->GetHandle()));
	}

	template<typename T> static void SaveMany(const T * arpObjects, NInt objectCount, ::Neurotec::IO::NStream & stream, NUInt flags = 0);
	template<typename T> static ::Neurotec::IO::NBuffer SaveMany(const T * arpObjects, NInt objectCount, NUInt flags = 0);
	template<typename T> static NSizeType GetSizeMany(const T * arpObjects, NInt objectCount, NUInt flags = 0);
	template<typename T> static NSizeType SaveMany(const T * arpObjects, NInt objectCount, ::Neurotec::IO::NBuffer & buffer, NUInt flags = 0);
	template<typename T> static NSizeType SaveMany(const T * arpObjects, NInt objectCount, void * pBuffer, NSizeType bufferSize, NUInt flags = 0);

public:
	NObject(HNObject handle, bool claimHandle = false)
		: handle(handle)
#ifdef N_DEBUG
		, isDisposed(false)
#endif
	{
		if (handle && !claimHandle)
			Ref();
	}

	NObject(const NObject & other)
		: handle(NULL)
#ifdef N_DEBUG
		, isDisposed(false)
#endif
	{
		SetHandle(other.handle);
	}

#ifdef N_CPP11
	NObject(NObject && other)
		: handle(other.handle)
#ifdef N_DEBUG
		, isDisposed(false)
#endif
	{
		other.handle = nullptr;
	}

	NObject& operator=(NObject && other)
	{
		if (this != &other)
		{
			SetHandle(nullptr);
			handle = other.handle;
			other.handle = nullptr;
		#ifdef N_DEBUG
			isDisposed = other.isDisposed;
			other.isDisposed = false;
		#endif
		}
		return *this;
	}
#endif

	NObject& operator=(const NObject & other)
	{
		if (this != &other)
		{
			SetHandle(other.handle);
		}
		return *this;
	}

	virtual ~NObject()
	{
		SetHandle(NULL);
	#ifdef N_DEBUG
		isDisposed = true;
	#endif
	}

#ifdef N_DEBUG
	bool IsDisposed() const
	{
		if (this == NULL) NThrowNullReferenceException();
		return isDisposed;
	}
#endif

	HNObject GetHandle() const
	{
	#ifdef N_DEBUG
		Check();
	#endif
		return handle;
	}

	NInt Ref()
	{
		return NCheck(NObjectRef(GetHandle()));
	}

	NInt Unref()
	{
		return NCheck(NObjectUnref(GetHandle()));
	}

	HNObject RefHandle() const
	{
		NCheck(NObjectRef(GetHandle()));
		return handle;
	}

	NObject RefObject() const
	{
		return FromHandle<NObject>(RefHandle());
	}

	bool IsNull() const
	{
		return handle == NULL;
	}

	NType GetNativeType() const;

	template<typename T>
	T GetOwner() const
	{
		typename T::HandleType hOwner;
		NCheck(NObjectGetOwnerEx(GetHandle(), (HNObject *)&hOwner));
		return FromHandle<T>(hOwner, true);
	}

	NUInt GetFlags() const
	{
		NUInt value;
		NCheck(NObjectGetFlags(GetHandle(), &value));
		return value;
	}

	void SetFlags(NUInt value)
	{
		NCheck(NObjectSetFlags(GetHandle(), value));
	}

	bool Equals(const NObject & object) const
	{
		NBool result;
		NCheck(NObjectEquals(GetHandle(), object.GetHandle(), &result));
		return result != 0;
	}

	NInt CompareTo(const NObject & object) const
	{
		NInt result;
		NCheck(NObjectCompareTo(GetHandle(), object.GetHandle(), &result));
		return result;
	}

	NInt GetHashCode() const
	{
		NInt value;
		NCheck(NObjectGetHashCode(GetHandle(), &value));
		return value;
	}

	NString ToString(const NStringWrapper & format = NString()) const
	{
		HNString hValue;
		NCheck(NObjectToStringN(GetHandle(), format.GetHandle(), &hValue));
		return NString(hValue, true);
	}

	NObject Clone() const
	{
		HNObject hClonedObject;
		NCheck(NObjectClone(GetHandle(), &hClonedObject));
		return FromHandle<NObject>(hClonedObject);
	}

	template<typename T>
	T Clone() const
	{
		HNObject hClonedObject;
		NCheck(NObjectClone(GetHandle(), &hClonedObject));
		return FromHandle<T>((typename T::HandleType)hClonedObject);
	}

	void Reset()
	{
		NCheck(NObjectReset(GetHandle()));
	}

	NValue GetProperty(const NStringWrapper & name) const;
	bool GetProperty(const NStringWrapper & name, NType * pValueType, NAttributes attributes, void * arValues, NSizeType valuesSize, NInt valuesLength) const;
	template<typename T> T GetProperty(const NStringWrapper & name, NAttributes attributes = naNone, bool * pHasValue = NULL) const;

	void SetProperty(const NStringWrapper & name, const NValue & value);
	void SetProperty(const NStringWrapper & name, const NType & valueType, NAttributes attributes, const void * arValues, NSizeType valuesSize, NInt valuesLength, bool hasValue = true);
	template<typename T> void SetProperty(const NStringWrapper & name, const T & value, NAttributes attributes = naNone, bool hasValue = true);

	void ResetProperty(const NStringWrapper & name)
	{
		NCheck(NObjectResetPropertyN(GetHandle(), name.GetHandle()));
	}

	template<typename InputIt>
	NValue Invoke(const NStringWrapper & name, InputIt first, InputIt last);
	NValue Invoke(const NStringWrapper & name, NPropertyBag & parameters);
	NValue Invoke(const NStringWrapper & name, const NStringWrapper & parameters);

	void AddHandler(const NStringWrapper & name, NValue & callback);
	void AddHandler(const NStringWrapper & name, NType & callbackType, const NCallback & callback);
	void RemoveHandler(const NStringWrapper & name, NValue & callback);
	void RemoveHandler(const NStringWrapper & name, NType & callbackType, const NCallback & callback);

	void Save(::Neurotec::IO::NStream & stream, NUInt flags = 0) const;
	::Neurotec::IO::NBuffer Save(NUInt flags = 0) const;

	NSizeType GetSize(NUInt flags = 0) const
	{
		NSizeType value;
		NCheck(NObjectGetSize(GetHandle(), flags, &value));
		return value;
	}

	NSizeType Save(::Neurotec::IO::NBuffer & buffer, NUInt flags = 0) const;

	NSizeType Save(void * pBuffer, NSizeType bufferSize, NUInt flags = 0) const
	{
		NSizeType size;
		NCheck(NObjectSaveToMemoryDst(GetHandle(), pBuffer, bufferSize, flags, &size));
		return size;
	}

	void CaptureProperties(NPropertyBag & properties) const;

	void AddPropertyChangedCallback(const NCallback & callback)
	{
		NCheck(NObjectAddPropertyChanged(GetHandle(), callback.GetHandle()));
	}

	template<typename F>
	NCallback AddPropertyChangedCallback(const F & callback, void * pParam = NULL)
	{
		NCallback cb = NTypes::CreateCallback<PropertyChangedEventHandler<F> >(callback, pParam);
		AddPropertyChangedCallback(cb);
		return cb;
	}

	void RemovePropertyChangedCallback(const NCallback & callback)
	{
		NCheck(NObjectRemovePropertyChanged(GetHandle(), callback.GetHandle()));
	}

	template<typename F>
	NCallback RemovePropertyChangedCallback(const F & callback, void * pParam = NULL)
	{
		NCallback cb = NTypes::CreateCallback<PropertyChangedEventHandler<F> >(callback, pParam);
		RemovePropertyChangedCallback(cb);
		return cb;
	}

	template<typename TOwner> friend class ::Neurotec::Collections::NStringReadOnlyCollection;
	template<typename TOwner> friend class ::Neurotec::Collections::NStringCollection;

	typedef HNObject HandleType;
	static ::Neurotec::NType NativeTypeOf();

	template<typename F> class CallbackDelegate;

	friend class NValue;
	friend class NArray;
};

#ifdef N_CPP11
#define N_OBJECT_MOVE_CONSTRUCTOR(name, baseName)\
	name(name && other)\
		: baseName(std::move(other))\
	{\
	}\
	name& operator=(name && other)\
	{\
		baseName::operator=(std::move(other));\
		return *this;\
	}
#else
#define N_OBJECT_MOVE_CONSTRUCTOR(name, baseName)
#endif

#define N_DECLARE_STATIC_OBJECT_CLASS(name) \
	N_DECLARE_TYPE_CLASS(name)\
	N_DECLARE_NON_COPYABLE(name)\
	private:\
		name();
#define N_DECLARE_OBJECT_CLASS(name, baseName) \
	private:\
		static ::Neurotec::NObject N_JOIN_SYMBOLS(name, FromHandle)(HNObject handle) { return name(handle, true); }\
	public:\
		typedef H##name HandleType;\
		static ::Neurotec::NType NativeTypeOf()\
		{\
			return ::Neurotec::NObject::GetObject< ::Neurotec::NType>(N_TYPE_OF(name), true);\
		}\
		H##name GetHandle() const { return static_cast<H##name>(baseName::GetHandle()); }\
		H##name RefHandle() const { return static_cast<H##name>(baseName::RefHandle()); }\
		name(HNObject handle, bool ownsHandle = false)\
			: baseName(handle, ownsHandle)\
		{\
		}\
		name(const name & other)\
			: baseName(other)\
		{\
		}\
		N_OBJECT_MOVE_CONSTRUCTOR(name, baseName)\
		name & operator=(const name & other)\
		{\
			baseName::operator=(other);\
			return *this;\
		}\
	private:\

template<typename T> class NAutoUnref
{
private:
	T * pObject;

public:
	explicit NAutoUnref(T * pObject = NULL)
		: pObject(pObject)
	{
	}

	NAutoUnref(NAutoUnref & value)
		: pObject(value.Release())
	{
	}

	~NAutoUnref()
	{
		Reset();
	}

	NAutoUnref & operator=(NAutoUnref & value)
	{
		Reset(value.Release());
		return (*this);
	}

	T * Get() const
	{
		return pObject;
	}

	T * Release()
	{
		T * pObject = this->pObject;
		this->pObject = NULL;
		return pObject;
	}

	void Reset(T * pObject = NULL)
	{
		if (pObject != this->pObject)
		{
			if (this->pObject) this->pObject->Unref();
			this->pObject = pObject;
		}
	}

	T * operator->() const
	{
		return Get();
	}

	T & operator*() const
	{
		return *Get();
	}
};

template<typename T> class NAutoUnrefArray
{
private:
	T * * ptr;
	NInt count;

public:
	NAutoUnrefArray()
		: ptr(NULL), count(0)
	{
	}

	NAutoUnrefArray(T * * ptr, NInt count)
		: ptr(ptr), count(count)
	{
	}

	NAutoUnrefArray(NInt count)
		: ptr((T * *)NCAlloc(sizeof(T *) * count)), count(count)
	{
	}

	NAutoUnrefArray(NAutoUnrefArray & value)
		: ptr(value.ptr), count(value.count)
	{
		value.Release();
	}

	~NAutoUnrefArray()
	{
		Reset();
	}

	NAutoUnrefArray & operator=(NAutoUnrefArray & value)
	{
		NInt count = value.count;
		Reset(value.Release(), count);
		return (*this);
	}

	T * & operator[](int index) const
	{
		return Get()[index];
	}

	T * * Get() const
	{
		return ptr;
	}

	T * & Get(int index) const
	{
		return ptr[index];
	}

	int GetCount() const
	{
		return count;
	}

	T * * Release()
	{
		T * * ptr = this->ptr;
		this->ptr = NULL;
		count = 0;
		return ptr;
	}

	void Reset()
	{
		Reset(NULL, 0);
	}

	void Reset(T * * ptr, NInt count)
	{
		if (ptr != this->ptr)
		{
			if (this->ptr)
			{
				for (NInt i = 0; i < this->count; i++)
				{
					if (this->ptr[i]) this->ptr[i]->Unref();
				}
				NFree(this->ptr);
			}
			this->ptr = ptr;
		}
		this->count = count;
	}
};

}

namespace Neurotec
{

template<typename T> struct NTypeTraitsBase<T, true>
{
	typedef typename T::HandleType NativeType;
	static NType GetNativeType();
	static const NUShort TypeId = 0;
	static typename T::HandleType ToNative(const T & value) { return value.GetHandle(); }
	static void SetNative(NativeType sourceValue, NativeType * destinationValue) { NCheck(NObjectSet(sourceValue, (HNObject *)destinationValue)); }
	static T FromNative(typename T::HandleType value, bool claimHandle) { return NObject::FromHandle<T>(value, claimHandle); }
	static void FreeNative(typename T::HandleType value) { NObject::Unref(value); }
};

template<>
struct NTypeTraits<NObject> : public NTypeTraitsBase<NObject, true>
{
};

}

#include <Core/NType.hpp>
#include <Core/NError.hpp>

namespace Neurotec
{
template<typename T>
NType NTypeTraitsBase<T, true>::GetNativeType()
{
	return T::NativeTypeOf();
}

inline ::Neurotec::NType NObject::NObjectCallbackNativeTypeOf()
{
	return NObject::GetObject< ::Neurotec::NType>(N_TYPE_OF(NObjectCallback), true);
}

inline ::Neurotec::NType NObject::NObjectPropertyChangedCallbackNativeTypeOf()
{
	return NObject::GetObject< ::Neurotec::NType>(N_TYPE_OF(NObjectPropertyChangedCallback), true);
}

inline ::Neurotec::NType NObject::NativeTypeOf()
{
	return NObject::GetObject< ::Neurotec::NType>(N_TYPE_OF(NObject), true);
}

inline void NObject::AddHandler(const NStringWrapper & name, NValue & callback)
{
	NCheck(NObjectAddHandlerN(GetHandle(), name.GetHandle(), callback.GetHandle()));
}

inline void NObject::AddHandler(const NStringWrapper & name, NType & callbackType, const NCallback & callback)
{
	NCheck(NObjectAddHandlerNN(GetHandle(), name.GetHandle(), callbackType.GetHandle(), callback.GetHandle()));
}

inline void NObject::RemoveHandler(const NStringWrapper & name, NValue & callback)
{
	NCheck(NObjectRemoveHandlerN(GetHandle(), name.GetHandle(), callback.GetHandle()));
}

inline void NObject::RemoveHandler(const NStringWrapper & name, NType & callbackType, const NCallback & callback)
{
	NCheck(NObjectRemoveHandlerNN(GetHandle(), name.GetHandle(), callbackType.GetHandle(), callback.GetHandle()));
}

inline bool operator==(const NObject & value1, const NObject & value2)
{
	return NObject::Equals(value1, value2);
}

inline bool operator!=(const NObject & value1, const NObject & value2)
{
	return NObject::Equals(value1, value2);
}

}

#include <Core/NType.hpp>
#include <Core/NPropertyBag.hpp>
#include <IO/NBuffer.hpp>
#include <IO/NStream.hpp>

namespace Neurotec
{
#include <Core/NNoDeprecate.h>
template<typename T> inline T NObject::FromHandle(typename T::HandleType handle, bool ownsHandle)
{
	return T(handle, ownsHandle);
}

template<typename T> inline NInt NObject::ToHandleArray(const T * arpObjects, NInt objectCount, typename T::HandleType * arhObjects, NInt objectsLength, bool addRef)
{
	if (!arpObjects && objectCount != 0) NThrowArgumentNullException(N_T("arpObjects"));
	if (objectCount < 0) NThrowArgumentLessThanZeroException(N_T("objectCount"));
	if (arhObjects)
	{
		if (objectsLength < objectCount) NThrowArgumentInsufficientException(N_T("objectsLength"));
		const T * pObject = arpObjects;
		typename T::HandleType * phObject = arhObjects;
		NInt i = 0;
		try
		{
			for (; i < objectCount; i++, pObject++, phObject++)
			{
				if (pObject->GetHandle() == NULL)
				{
					*phObject = NULL;
				}
				else
				{
					*phObject = addRef ? pObject->RefHandle() : pObject->GetHandle();
				}
			}
		}
		catch (...)
		{
			if (addRef)
			{
				for (; i >= 0; i--, phObject--)
				{
					Unref(*phObject);
				}
			}
			throw;
		}
	}
	return objectCount;
}

template<typename T> inline T NObject::GetObject(NResult (N_CALLBACK pGetObject)(typename T::HandleType * phValue), bool ownsHandle)
{
	typename T::HandleType hValue;
	NCheck(pGetObject(&hValue));
	return FromHandle<T>(hValue, ownsHandle);
}

template<typename T> inline NArrayWrapper<T> NObject::GetObjects(NResult (N_CALLBACK pGetObjects)(typename T::HandleType * * parhValues, NInt * pValueCount), bool ownsHandles)
{
	typename T::HandleType * arhValues = NULL;
	NInt valueCount = 0;
	NCheck(pGetObjects(&arhValues, &valueCount));
	return NArrayWrapper<T>(arhValues, valueCount, true, ownsHandles);
}

template<typename THandle> inline NString NObject::GetString(NResult (N_CALLBACK pGetString)(THandle handle, HNString * phValue)) const
{
	HNString hValue;
	NCheck(pGetString(static_cast<THandle>(GetHandle()), &hValue));
	return NString(hValue, true);
}

template<typename THandle> inline void NObject::SetString(NResult (N_CALLBACK pSetString)(THandle handle, HNString hValue), const NStringWrapper & value)
{
	NCheck(pSetString(static_cast<THandle>(GetHandle()), value.GetHandle()));
}

template<typename THandle, typename T> inline T NObject::GetObject(NResult (N_CALLBACK pGetObject)(THandle handle, typename T::HandleType * phValue), bool ownsHandle) const
{
	THandle hObj = static_cast<THandle>(GetHandle());
	typename T::HandleType hValue;
	NCheck(pGetObject(hObj, &hValue));
	return FromHandle<T>(hValue, ownsHandle);
}

template<typename THandle, typename T> inline NArrayWrapper<T> NObject::GetObjects(NResult (N_CALLBACK pGetObjects)(THandle handle, typename T::HandleType * * parhValues, NInt * pValueCount), bool ownsHandles) const
{
	typename T::HandleType * arhValues = NULL;
	NInt valueCount = 0;
	NCheck(pGetObjects(static_cast<THandle>(GetHandle()), &arhValues, &valueCount));
	return NArrayWrapper<T>(arhValues, valueCount, true, ownsHandles);
}

template<typename THandle, typename T> inline NArrayWrapper<T> NObject::GetObjects(NResult (N_CALLBACK pGetObjects)(THandle handle, typename T::HandleType * parhValues, NInt valueCount), bool ownsHandles) const
{
	THandle hObj = static_cast<THandle>(GetHandle());
	NInt valueCount = 0;
	valueCount = NCheck(pGetObjects(hObj, NULL, 0));
	NArrayWrapper<T> objects(valueCount, ownsHandles);
	valueCount = NCheck(pGetObjects(hObj, objects.GetPtr(), valueCount));
	objects.SetCount(valueCount);
	return objects;
}

#include <Core/NReDeprecate.h>

inline NValue NObject::GetProperty(const NStringWrapper & name) const
{
	HNValue hValue;
	NCheck(NObjectGetPropertyN(GetHandle(), name.GetHandle(), &hValue));
	return FromHandle<NValue>(hValue);
}

inline bool NObject::GetProperty(const NStringWrapper & name, NType * pValueType, NAttributes attributes, void * arValues, NSizeType valuesSize, NInt valuesLength) const
{
	if (!pValueType) NThrowArgumentNullException(N_T("pValueType"));
	NBool hasValue;
	NCheck(NObjectGetPropertyNN(GetHandle(), name.GetHandle(), pValueType->GetHandle(), attributes, arValues, valuesSize, valuesLength, &hasValue));
	return hasValue != 0;
}

template<typename T> inline T NObject::GetProperty(const NStringWrapper & name, NAttributes attributes, bool * pHasValue) const
{
	typename NTypeTraits<T>::NativeType value;
	NBool hasValue = NFalse;
	NCheck(NObjectGetPropertyNN(GetHandle(), name.GetHandle(), NTypeTraits<T>::GetNativeType().GetHandle(), attributes, &value, sizeof(value), 1, pHasValue ? &hasValue : NULL));
	T v = NTypeTraits<T>::FromNative(value, true);
	if (pHasValue) *pHasValue = hasValue != 0;
	return v;
}

inline void NObject::SetProperty(const NStringWrapper & name, const NValue & value)
{
	NCheck(NObjectSetPropertyN(GetHandle(), name.GetHandle(), value.GetHandle()));
}

inline void NObject::SetProperty(const NStringWrapper & name, const NType & valueType, NAttributes attributes, const void * arValues, NSizeType valuesSize, NInt valuesLength, bool hasValue)
{
	NCheck(NObjectSetPropertyNN(GetHandle(), name.GetHandle(), valueType.GetHandle(), attributes, arValues, valuesSize, valuesLength, hasValue ? NTrue : NFalse));
}

template<typename T> inline void NObject::SetProperty(const NStringWrapper & name, const T & value, NAttributes attributes, bool hasValue)
{
	typename NTypeTraits<T>::NativeType v = NTypeTraits<T>::ToNative(value);
	NCheck(NObjectSetPropertyNN(GetHandle(), name.GetHandle(), NTypeTraits<T>::GetNativeType().GetHandle(), attributes, &v, sizeof(v), 1, hasValue ? NTrue : NFalse));
}

template<typename InputIt>
inline NValue NObject::Invoke(const NStringWrapper & name, InputIt firstParameter, InputIt lastParameter)
{
	NArrayWrapper<NValue> parameters(firstParameter, lastParameter);
	HNValue hResult;
	NCheck(NObjectInvokeN(GetHandle(), name.GetHandle(), parameters.GetPtr(), parameters.GetCount(), &hResult));
	return FromHandle<NValue>(hResult);
}

inline NValue NObject::Invoke(const NStringWrapper & name, NPropertyBag & parameters)
{
	HNValue hResult;
	NCheck(NObjectInvokeWithPropertyBagN(GetHandle(), name.GetHandle(), parameters.GetHandle(), &hResult));
	return FromHandle<NValue>(hResult);
}

inline NValue NObject::Invoke(const NStringWrapper & name, const NStringWrapper & parameters)
{
	HNValue hResult;
	NCheck(NObjectInvokeWithStringN(GetHandle(), name.GetHandle(), parameters.GetHandle(), &hResult));
	return FromHandle<NValue>(hResult);
}

template<typename T> inline void NObject::SaveMany(const T * arpObjects, NInt objectCount, ::Neurotec::IO::NStream & stream, NUInt flags)
{
	NArrayWrapper<T> objects(arpObjects, objectCount);
	NCheck(NObjectSaveManyToStream(objects.GetPtr(), objects.GetCount(), stream.GetHandle(), flags));
}

template<typename T> inline ::Neurotec::IO::NBuffer NObject::SaveMany(const T * arpObjects, NInt objectCount, NUInt flags)
{
	NArrayWrapper<T> objects(arpObjects, objectCount);
	HNBuffer hBuffer;
	NCheck(NObjectSaveManyToMemoryN(objects.GetPtr(), objects.GetCount(), flags, &hBuffer));
	return FromHandle< ::Neurotec::IO::NBuffer>(hBuffer);
}

template<typename T> inline NSizeType GetSizeMany(const T * arpObjects, NInt objectCount, NUInt flags)
{
	NArrayWrapper<T> objects(arpObjects, objectCount);
	NSizeType size;
	NCheck(NObjectGetSizeMany(objects.GetPtr(), objects.GetCount(), flags, &size));
	return size;
}

template<typename T> inline NSizeType NObject::SaveMany(const T * arpObjects, NInt objectCount, ::Neurotec::IO::NBuffer & buffer, NUInt flags)
{
	NArrayWrapper<T> objects(arpObjects, objectCount);
	NSizeType size;
	NCheck(NObjectSaveManyToMemoryDstN(objects.GetPtr(), objects.GetCount(), buffer.GetHandle(), flags, &size));
	return size;
}

template<typename T> inline NSizeType SaveMany(T * const * arpObjects, NInt objectCount, void * pBuffer, NSizeType bufferSize, NUInt flags)
{
	NArrayWrapper<T> objects(arpObjects, objectCount);
	NSizeType size;
	NCheck(NObjectSaveManyToMemoryDst(objects.GetPtr(), objects.GetCount(), pBuffer, bufferSize, flags, &size));
	return size;
}

inline void NObject::Save(::Neurotec::IO::NStream & stream, NUInt flags) const
{
	NCheck(NObjectSaveToStream(GetHandle(), stream.GetHandle(), flags));
}

inline ::Neurotec::IO::NBuffer NObject::Save(NUInt flags) const
{
	HNBuffer hBuffer;
	NCheck(NObjectSaveToMemoryN(GetHandle(), flags, &hBuffer));
	return FromHandle< ::Neurotec::IO::NBuffer>(hBuffer);
}

inline NSizeType NObject::Save(::Neurotec::IO::NBuffer & buffer, NUInt flags) const
{
	NSizeType size;
	NCheck(NObjectSaveToMemoryDstN(GetHandle(), buffer.GetHandle(), flags, &size));
	return size;
}

inline void NObject::CaptureProperties(NPropertyBag & properties) const
{
	NCheck(NObjectCaptureProperties(GetHandle(), properties.GetHandle()));
}

template<typename F>
class NObject::EventHandler : public EventHandlerBase<F>
{
public:
	EventHandler(F f)
		: EventHandlerBase<F>(f)
	{
	}

	static NResult N_API NativeCallback(HNObject hObject, void * pParam)
	{
		NResult result = N_OK;
		try
		{
			EventHandler<F> * pHandler = static_cast<EventHandler *>(pParam);
			EventArgs e(hObject, pHandler->pParam);
			pHandler->callback(e);
		}
		N_EXCEPTION_CATCH_AND_SET_LAST(result);
		return result;
	}
};

class NObject::PropertyChangedEventArgs : public EventArgs
{
private:
	HNString hPropertyName;

public:
	PropertyChangedEventArgs(HNObject hObject, HNString hPropertyName, void * pParam)
		: EventArgs(hObject, pParam), hPropertyName(hPropertyName)
	{
	}

	NString GetPropertyName() const
	{
		return NString(hPropertyName, false);
	}
};

template<typename F>
class NObject::PropertyChangedEventHandler : public EventHandlerBase<F>
{
public:
	PropertyChangedEventHandler(F f)
		: EventHandlerBase<F>(f)
	{
	}

	static NResult N_API NativeCallback(HNObject hObject, HNString hPropertyName, void * pParam)
	{
		NResult result = N_OK;
		try
		{
			PropertyChangedEventHandler<F> * pHandler = static_cast<PropertyChangedEventHandler *>(pParam);
			NObject::PropertyChangedEventArgs e(hObject, hPropertyName, pHandler->pParam);
			pHandler->callback(e);
		}
		N_EXCEPTION_CATCH_AND_SET_LAST(result);
		return result;
	}
};

inline NType NObject::GetNativeType() const
{
	return GetObject<HandleType, NType>(NObjectGetType, true);
}

template<typename T>
inline T NObjectDynamicCast(const NObject & obj)
{
	if (!T::NativeTypeOf().IsInstanceOfType(obj))
		NThrowInvalidCastException();
	return NObject::FromHandle<T>((typename T::HandleType)(obj.GetHandle()), false);
}

}

#endif // !N_OBJECT_HPP_INCLUDED
