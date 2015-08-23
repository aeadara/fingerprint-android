#ifndef N_CORE_HPP_INCLUDED
#define N_CORE_HPP_INCLUDED

#include <Core/NObject.hpp>
namespace Neurotec
{
#include <Core/NCore.h>
}

namespace Neurotec
{

class NCore
{
	N_DECLARE_STATIC_OBJECT_CLASS(NCore)

public:
	class ErrorSuppressedEventArgs : EventArgs
	{
	private:
		NResult errorCode;
		HNError hError;
	public:
		ErrorSuppressedEventArgs(NResult errorCode, HNError hError, void * pParam)
			: EventArgs(NULL, pParam), errorCode(errorCode), hError(hError)
		{
		}

		NError GetError() const
		{
			return hError ? NObject::FromHandle<NError>(hError) : NError(errorCode);
		}
	};

private:

	template<typename F>
	class ErrorSuppressedEventHandler : EventHandlerBase<F>
	{
	public:
		ErrorSuppressedEventHandler(const F & callback)
			: EventHandlerBase<F>(callback)
		{
		}

		static NResult N_API NativeCallback(NResult errorCode, HNError hError, void * pParam)
		{
			NResult result = N_OK;
			try
			{
				EventHandlerBase<F> * pHandler = reinterpret_cast<EventHandlerBase<F> *>(pParam);
				ErrorSuppressedEventArgs e(errorCode, hError, pHandler->pParam);
				pHandler->callback(e);
			}
			N_EXCEPTION_CATCH_AND_SET_LAST(result);
			return result;
		}
	};


public:

	static NType NErrorSuppressedCallbackNativeTypeOf()
	{
		return NObject::GetObject<NType>(N_TYPE_OF(NErrorSuppressedCallback), true);
	}

	static void OnStart()
	{
		NCheck(NCoreOnStart());
	}

	static void OnThreadStart()
	{
		NCheck(NCoreOnThreadStart());
	}

	static void OnThreadExit()
	{
		NCheck(NCoreOnThreadExit());
	}

	static void OnExit(bool isProcessTermination)
	{
		NCheck(NCoreOnExitEx(isProcessTermination ? NTrue : NFalse));
	}

	static void AddErrorSuppressedCallback(const NCallback & callback)
	{
		NCheck(NCoreAddErrorSuppressed(callback.GetHandle()));
	}

	template<typename F>
	static NCallback AddErrorSuppressedCallback(const F & callback, void * pParam = NULL)
	{
		NCallback cb = NTypes::CreateCallback<ErrorSuppressedEventHandler<F> >(callback, pParam);
		NCheck(NCoreAddErrorSuppressed(cb.GetHandle()));
		return cb;
	}

	static void RemoveErrorSuppressedCallback(const NCallback & callback)
	{
		NCheck(NCoreRemoveErrorSuppressed(callback.GetHandle()));
	}

	template<typename F>
	static NCallback RemoveErrorSuppressedCallback(const F & callback, void * pParam = NULL)
	{
		NCallback cb = NTypes::CreateCallback<ErrorSuppressedEventHandler<F> >(callback, pParam);
		RemoveErrorSuppressedCallback(cb.GetHandle());
		return cb;
	}

	N_DECLARE_MODULE_CLASS(NCore)
};

} // namespace Neurotec

#endif // !N_CORE_HPP_INCLUDED
