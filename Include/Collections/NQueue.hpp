#ifndef N_QUEUE_HPP_INCLUDED
#define N_QUEUE_HPP_INCLUDED

#include <Core/NType.hpp>
namespace Neurotec { namespace Collections { namespace Internal
{
#include <Collections/NQueue.h>
}}}

namespace Neurotec { namespace Collections
{

class NQueue : private Internal::NQueue
{
	N_DECLARE_PRIMITIVE_CLASS(NQueue)

public:
	explicit NQueue(NSizeType elementSize)
	{
		NCheck(Internal::NQueueInit(this, elementSize, NULL));
	}

	template<typename T> NQueue()
	{
		NCheck(Internal::NQueueInit(this, 0, NTypeTraits<T>::GetNativeType().GetHandle()));
	}

	NQueue(const NType & elementType)
	{
		NCheck(Internal::NQueueInit(this, 0, elementType.GetHandle()));
	}

	NQueue(NTypeOfProc pElementTypeOf)
	{
		NCheck(Internal::NQueueInitP(this, 0, pElementTypeOf));
	}

	NQueue(NSizeType elementSize, NInt capacity)
	{
		NCheck(Internal::NQueueInitWithCapacity(this, elementSize, NULL, capacity));
	}

	template<typename T> NQueue(NInt capacity)
	{
		NCheck(Internal::NQueueInit(this, 0, NTypeTraits<T>::GetNativeType().GetHandle(), capacity));
	}

	NQueue(const NType & elementType, NInt capacity)
	{
		NCheck(Internal::NQueueInitWithCapacity(this, 0, elementType.GetHandle(), capacity));
	}

	NQueue(NTypeOfProc pElementTypeOf, NInt capacity)
	{
		NCheck(Internal::NQueueInitWithCapacityP(this, 0, pElementTypeOf, capacity));
	}

	NQueue(NSizeType elementSize, NInt capacity, NInt maxCapacity, NInt growthDelta, NSizeType alignment)
	{
		NCheck(Internal::NQueueInitEx(this, elementSize, NULL, capacity, maxCapacity, growthDelta, alignment));
	}

	template<typename T> NQueue(NInt capacity, NInt maxCapacity, NInt growthDelta, NSizeType alignment)
	{
		NCheck(Internal::NQueueInitEx(this, 0, NTypeTraits<T>::GetNativeType().GetHandle(), capacity, maxCapacity, growthDelta, alignment));
	}

	NQueue(const NType & elementType, NInt capacity, NInt maxCapacity, NInt growthDelta, NSizeType alignment)
	{
		NCheck(Internal::NQueueInitEx(this, 0, elementType.GetHandle(), capacity, maxCapacity, growthDelta, alignment));
	}

	NQueue(NTypeOfProc pElementTypeOf, NInt capacity, NInt maxCapacity, NInt growthDelta, NSizeType alignment)
	{
		NCheck(Internal::NQueueInitExP(this, 0, pElementTypeOf, capacity, maxCapacity, growthDelta, alignment));
	}

	~NQueue()
	{
		NCheck(Internal::NQueueDispose(this));
	}

	NInt GetCapacity()
	{
		NInt value;
		NCheck(Internal::NQueueGetCapacity(this, &value));
		return value;
	}

	void SetCapacity(NInt value)
	{
		NCheck(Internal::NQueueSetCapacity(this, value));
	}

	NInt GetCount()
	{
		NInt value;
		NCheck(Internal::NQueueGetCount(this, &value));
		return value;
	}

	bool Contains(const void * pValue, NSizeType valueSize)
	{
		NBool result;
		NCheck(Internal::NQueueContains(this, NULL, pValue, valueSize, &result));
		return result != 0;
	}

	template<typename T> bool Contains(const T & value)
	{
		typename NTypeTraits<T>::NativeType v = NTypeTraits<T>::ToNative(value);
		NBool result;
		NCheck(Internal::NQueueContains(this, NTypeTraits<T>::GetNativeType().GetHandle(), &v, sizeof(v), &result));
		return result != 0;
	}

	bool Contains(const NType & valueType, const void * pValue, NSizeType valueSize)
	{
		NBool result;
		NCheck(Internal::NQueueContains(this, valueType.GetHandle(), pValue, valueSize, &result));
		return result != 0;
	}

	bool Contains(NTypeOfProc pValueTypeOf, const void * pValue, NSizeType valueSize)
	{
		NBool result;
		NCheck(Internal::NQueueContainsP(this, pValueTypeOf, pValue, valueSize, &result));
		return result != 0;
	}

	void * GetFront(NSizeType elementSize)
	{
		void * pValue;
		NCheck(Internal::NQueueGetFront(this, elementSize, NULL, &pValue));
		return pValue;
	}

	template<typename T> typename NTypeTraits<T>::NativeType * GetFront()
	{
		typename NTypeTraits<T>::NativeType * pValue;
		NCheck(Internal::NQueueGetFront(this, 0, NTypeTraits<T>::GetNativeType().GetHandle(), (void * *)&pValue));
		return pValue;
	}

	void * GetFront(const NType & elementType)
	{
		void * pValue;
		NCheck(Internal::NQueueGetFront(this, 0, elementType.GetHandle(), &pValue));
		return pValue;
	}

	void * GetFront(NTypeOfProc pElementTypeOf)
	{
		void * pValue;
		NCheck(Internal::NQueueGetFrontP(this, 0, pElementTypeOf, &pValue));
		return pValue;
	}

	void Peek(void * pValue, NSizeType valueSize)
	{
		NCheck(Internal::NQueuePeek(this, NULL, pValue, valueSize));
	}

	template<typename T> T Peek()
	{
		typename NTypeTraits<T>::NativeType value;
		NCheck(Internal::NQueuePeek(this, NTypeTraits<T>::GetNativeType().GetHandle(), &value, sizeof(value)));
		return NTypeTraits<T>::FromNative(value, true);
	}

	void Peek(const NType & valueType, void * pValue, NSizeType valueSize)
	{
		NCheck(Internal::NQueuePeek(this, valueType.GetHandle(), pValue, valueSize));
	}

	void Peek(NTypeOfProc pValueTypeOf, void * pValue, NSizeType valueSize)
	{
		NCheck(Internal::NQueuePeekP(this, pValueTypeOf, pValue, valueSize));
	}

	void Dequeue(void * pValue, NSizeType valueSize)
	{
		NCheck(Internal::NQueueDequeue(this, NULL, pValue, valueSize));
	}

	template<typename T> T Dequeue()
	{
		typename NTypeTraits<T>::NativeType value;
		NCheck(Internal::NQueueDequeue(this, NTypeTraits<T>::GetNativeType().GetHandle(), &value, sizeof(value)));
		return NTypeTraits<T>::FromNative(value, true);
	}

	void Dequeue(const NType & valueType, void * pValue, NSizeType valueSize)
	{
		NCheck(Internal::NQueueDequeue(this, valueType.GetHandle(), pValue, valueSize));
	}

	void Dequeue(NTypeOfProc pValueTypeOf, void * pValue, NSizeType valueSize)
	{
		NCheck(Internal::NQueueDequeueP(this, pValueTypeOf, pValue, valueSize));
	}

	void Enqueue(const void * pValue, NSizeType valueSize)
	{
		NCheck(Internal::NQueueEnqueue(this, NULL, pValue, valueSize));
	}

	template<typename T> void Enqueue(const T & value)
	{
		typename NTypeTraits<T>::NativeType v = NTypeTraits<T>::ToNative(value);
		NCheck(Internal::NQueueEnqueue(this, NTypeTraits<T>::GetNativeType().GetHandle(), &v, sizeof(v)));
	}

	void Enqueue(const NType & valueType, const void * pValue, NSizeType valueSize)
	{
		NCheck(Internal::NQueueEnqueue(this, valueType.GetHandle(), pValue, valueSize));
	}

	void Enqueue(NTypeOfProc pValueTypeOf, const void * pValue, NSizeType valueSize)
	{
		NCheck(Internal::NQueueEnqueueP(this, pValueTypeOf, pValue, valueSize));
	}

	void Clear()
	{
		NCheck(Internal::NQueueClear(this));
	}

	NInt CopyTo(void * pValues, NSizeType valuesSize, NInt valuesLength)
	{
		return NCheck(Internal::NQueueCopyTo(this, NULL, pValues, valuesSize, valuesLength));
	}

	template<typename T> NInt CopyTo(T * arValues, NInt valuesLength)
	{
		typename NTypeTraits<T>::NativeArrayType values(arValues ? valuesLength : 0);
		NInt count = NCheck(Internal::NQueueCopyTo(this, NTypeTraits<T>::GetNativeType().GetHandle(), arValues ? NTypeTraits<T>::GetNativeArray(values, arValues) : NULL,
			(NSizeType)valuesLength * sizeof(NTypeTraits<T>::NativeType), valuesLength));
		return values.CopyTo(arValues, valuesLength, count);
	}

	NInt CopyTo(const NType & valueType, void * pValues, NSizeType valuesSize, NInt valuesLength)
	{
		return NCheck(Internal::NQueueCopyTo(this, valueType.GetHandle(), pValues, valuesSize, valuesLength));
	}

	NInt CopyTo(NTypeOfProc pValueTypeOf, void * pValues, NSizeType valuesSize, NInt valuesLength)
	{
		return NCheck(Internal::NQueueCopyToP(this, pValueTypeOf, pValues, valuesSize, valuesLength));
	}

	void * ToArray(NSizeType elementSize, NInt * pCount)
	{
		void * pValues;
		NCheck(Internal::NQueueToArray(this, elementSize, NULL, &pValues, pCount));
		return pValues;
	}

	template<typename T> NArrayWrapper<T> ToArray()
	{
		void * pValues;
		NInt count;
		NCheck(Internal::NQueueToArray(this, 0, NTypeTraits<T>::GetNativeType().GetHandle(), &pValues, &count));
		return NArrayWrapper<T>(pValues, count);
	}

	void * ToArray(const NType & valueType, NInt * pCount)
	{
		void * pValues;
		NCheck(Internal::NQueueToArray(this, 0, valueType.GetHandle(), &pValues, pCount));
		return pValues;
	}

	void * ToArray(NTypeOfProc pValueTypeOf, NInt * pCount)
	{
		void * pValues;
		NCheck(Internal::NQueueToArrayP(this, 0, pValueTypeOf, &pValues, pCount));
		return pValues;
	}
};

}}

#endif // !N_QUEUE_HPP_INCLUDED
