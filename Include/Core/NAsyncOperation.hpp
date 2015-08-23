#ifndef N_ASYNC_OPERATION_HPP_INCLUDED
#define N_ASYNC_OPERATION_HPP_INCLUDED

#include <Core/NObject.hpp>
#include <Core/NCallback.hpp>
namespace Neurotec
{
#include <Core/NAsyncOperation.h>
}

N_DEFINE_ENUM_TYPE_TRAITS(Neurotec, NAsyncStatus)

namespace Neurotec
{

class NAsyncOperation : public NObject
{
	N_DECLARE_OBJECT_CLASS(NAsyncOperation, NObject)

public:
	static NType NAsyncStatusNativeTypeOf()
	{
		return NObject::GetObject<NType>(N_TYPE_OF(NAsyncStatus), true);
	}

	template<typename InputIt>
	static NInt WaitAny(InputIt first, InputIt last)
	{
		NArrayWrapper<NAsyncOperation> asyncOperations(first, last);
		NInt result;
		NCheck(NAsyncOperationWaitAny(asyncOperations.GetPtr(), asyncOperations.GetCount(), &result));
		return result;
	}

	template<typename InputIt>
	static NInt WaitAny(InputIt first, InputIt last, NInt timeoutMilliseconds)
	{
		NArrayWrapper<NAsyncOperation> asyncOperations(first, last);
		NInt result;
		NCheck(NAsyncOperationWaitAnyTimed(asyncOperations.GetPtr(), asyncOperations.GetCount(), timeoutMilliseconds, &result));
		return result != 0;
	}

	template<typename InputIt>
	static void WaitAll(InputIt first, InputIt last)
	{
		NArrayWrapper<NAsyncOperation> asyncOperations(first, last);
		NCheck(NAsyncOperationWaitAll(asyncOperations.GetPtr(), asyncOperations.GetCount()));
	}

	template<typename InputIt>
	static bool WaitAll(InputIt first, InputIt last, NInt timeoutMilliseconds)
	{
		NArrayWrapper<NAsyncOperation> asyncOperations(first, last);
		NBool result;
		NCheck(NAsyncOperationWaitAllTimed(asyncOperations.GetPtr(), asyncOperations.GetCount(), timeoutMilliseconds, &result));
		return result != 0;
	}

	void Cancel(bool block = false)
	{
		NCheck(NAsyncOperationCancel(GetHandle(), block ? NTrue : NFalse));
	}

	void Wait() const
	{
		NCheck(NAsyncOperationWait(GetHandle()));
	}

	bool Wait(NInt timeoutMilliseconds) const
	{
		NBool result;
		NCheck(NAsyncOperationWaitTimed(GetHandle(), timeoutMilliseconds, &result));
		return result != 0;
	}

	NValue GetResult() const
	{
		HNValue hValue;
		NCheck(NAsyncOperationGetResult(GetHandle(), &hValue));
		return FromHandle<NValue>(hValue);
	}

	NAsyncStatus GetStatus() const
	{
		NAsyncStatus value;
		NCheck(NAsyncOperationGetStatus(GetHandle(), &value));
		return value;
	}

	bool IsCompleted() const
	{
		NBool value;
		NCheck(NAsyncOperationIsCompleted(GetHandle(), &value));
		return value != 0;
	}

	bool IsCanceled() const
	{
		NBool value;
		NCheck(NAsyncOperationIsCanceled(GetHandle(), &value));
		return value != 0;
	}

	bool IsFaulted() const
	{
		NBool value;
		NCheck(NAsyncOperationIsFaulted(GetHandle(), &value));
		return value != 0;
	}

	NError GetError() const
	{
		HNError hValue;
		NCheck(NAsyncOperationGetError(GetHandle(), &hValue));
		return FromHandle<NError>(hValue);
	}

	void AddCompletedCallback(const NCallback & callback)
	{
		NCheck(NAsyncOperationAddCompleted(GetHandle(), callback.GetHandle()));
	}

	template<typename F>
	NCallback AddCompletedCallback(const F & callback, void * pParam = NULL)
	{
		NCallback cb = NTypes::CreateCallback<NObject::EventHandler<F> >(callback, pParam);
		AddCompletedCallback(cb);
		return cb;
	}

	void RemoveCompletedCallback(const NCallback & callback)
	{
		NCheck(NAsyncOperationRemoveCompleted(GetHandle(), callback.GetHandle()));
	}

	template<typename F>
	NCallback RemoveCompletedCallback(const F & callback, void * pParam = NULL)
	{
		NCallback cb = NTypes::CreateCallback<NObject::EventHandler<F> >(callback, pParam);
		RemoveCompletedCallback(cb);
		return cb;
	}
};

}

#endif // !N_ASYNC_OPERATION_HPP_INCLUDED
