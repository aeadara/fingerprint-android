#ifndef N_EVENT_HPP_INCLUDED
#define N_EVENT_HPP_INCLUDED

#include <Core/NCallback.hpp>
namespace Neurotec { namespace Internal
{
#include <Core/NEvent.h>
}}

namespace Neurotec
{

#define N_EVENT_IMPL(argCount, argsDef, callbackArgTypes, callbackArgs) \
		N_DECLARE_PRIMITIVE_CLASS(NEvent##argCount)\
	private:\
		typedef void (* CallbackType)callbackArgTypes;\
	public:\
		NEvent##argCount()\
		{\
			NCheck(Internal::NEventInit(this));\
		}\
		~NEvent##argCount()\
		{\
			NCheck(Internal::NEventDispose(this));\
		}\
		bool IsEmpty()\
		{\
			NBool value;\
			NCheck(Internal::NEventIsEmpty(this, &value));\
			return value != 0;\
		}\
		void Add(const NCallback & callback)\
		{\
			NCheck(Internal::NEventAddN(this, callback.GetHandle()));\
		}\
		void Add(CallbackType pCallback, void * pParam)\
		{\
			NCheck(Internal::NEventAdd(this, pCallback, pParam));\
		}\
		void Remove(const NCallback & callback)\
		{\
			NCheck(Internal::NEventRemoveN(this, callback.GetHandle()));\
		}\
		void Remove(CallbackType pCallback, void * pParam)\
		{\
			NCheck(Internal::NEventRemove(this, pCallback, pParam));\
		}\
		void operator()argsDef\
		{\
			HNCallback * arhCallbacks, * phCallback;\
			NInt count, i;\
			NCheck(Internal::NEventGetCallbacks(this, &arhCallbacks, &count));\
			try\
			{\
				for (i = 0, phCallback = arhCallbacks; i < count; i++, phCallback++)\
				{\
					NCallbackInvokeRaw(CallbackType, *phCallback, callbackArgs);\
				}\
				NCheck(Internal::NEventReleaseCallbacks(this, arhCallbacks, count));\
			}\
			catch (...)\
			{\
				NCheck(Internal::NEventReleaseCallbacks(this, arhCallbacks, count));\
				throw;\
			}\
		}\
		operator bool()\
		{\
			return !IsEmpty();\
		}\
		bool operator !()\
		{\
			return IsEmpty();\
		}

template<typename T1> class NEvent1 : private Internal::NEvent
{
	N_EVENT_IMPL(1, (T1 p1), (T1, void *), (p1, NCallbackGetParam(*phCallback)))
};

template<typename T1, typename T2> class NEvent2 : private Internal::NEvent
{
	N_EVENT_IMPL(2, (T1 p1, T2 p2), (T1, T2, void *), (p1, p2, NCallbackGetParam(*phCallback)))
};

template<typename T1, typename T2, typename T3> class NEvent3 : private Internal::NEvent
{
	N_EVENT_IMPL(3, (T1 p1, T2 p2, T3 p3), (T1, T2, T3, void *), (p1, p2, p3, NCallbackGetParam(*phCallback)))
};

template<typename T1, typename T2, typename T3, typename T4> class NEvent4 : private Internal::NEvent
{
	N_EVENT_IMPL(4, (T1 p1, T2 p2, T3 p3, T4 p4), (T1, T2, T3, T4, void *), (p1, p2, p3, p4, NCallbackGetParam(*phCallback)))
};

template<typename T1, typename T2, typename T3, typename T4, typename T5> class NEvent5 : private Internal::NEvent
{
	N_EVENT_IMPL(5, (T1 p1, T2 p2, T3 p3, T4 p4, T5 p5), (T1, T2, T3, T4, T5, void *), (p1, p2, p3, p4, p5, NCallbackGetParam(*phCallback)))
};

template<typename T1, typename T2, typename T3, typename T4, typename T5, typename T6> class NEvent6 : private Internal::NEvent
{
	N_EVENT_IMPL(6, (T1 p1, T2 p2, T3 p3, T4 p4, T5 p5, T6 p6), (T1, T2, T3, T4, T5, T6, void *), (p1, p2, p3, p4, p5, p6, NCallbackGetParam(*phCallback)))
};

}

#endif // !N_EVENT_HPP_INCLUDED
