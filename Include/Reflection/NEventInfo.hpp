#include <Reflection/NMemberInfo.hpp>
#include <Reflection/NMethodInfo.hpp>

#ifndef N_EVENT_INFO_HPP_INCLUDED
#define N_EVENT_INFO_HPP_INCLUDED

namespace Neurotec { namespace Reflection
{
#include <Reflection/NEventInfo.h>
}}

namespace Neurotec { namespace Reflection
{

class NEventInfo : public NMemberInfo
{
	N_DECLARE_OBJECT_CLASS(NEventInfo, NMemberInfo)

public:
	NType GetEventType() const
	{
		return GetObject<HandleType, NType>(NEventInfoGetEventType, true);
	}

	NMethodInfo GetAddMethod() const
	{
		return GetObject<HandleType, NMethodInfo>(NEventInfoGetAddMethod);
	}

	NMethodInfo GetAddCallbackMethod() const
	{
		return GetObject<HandleType, NMethodInfo>(NEventInfoGetAddCallbackMethod);
	}

	NMethodInfo GetRemoveMethod() const
	{
		return GetObject<HandleType, NMethodInfo>(NEventInfoGetRemoveMethod);
	}

	NMethodInfo GetRemoveCallbackMethod() const
	{
		return GetObject<HandleType, NMethodInfo>(NEventInfoGetRemoveCallbackMethod);
	}

	void AddHandler(const NObject & object, const NValue & callback) const
	{
		NCheck(NEventInfoAddHandlerN(GetHandle(), object.GetHandle(), callback.GetHandle()));
	}

	void AddHandler(const NObject & object, const NType & callbackType, const NCallback & callback) const
	{
		NCheck(NEventInfoAddHandler(GetHandle(), object.GetHandle(), callbackType.GetHandle(), callback.GetHandle()));
	}

	void RemoveHandler(const NObject & object, const NValue & callback) const
	{
		NCheck(NEventInfoRemoveHandlerN(GetHandle(), object.GetHandle(), callback.GetHandle()));
	}

	void RemoveHandler(const NObject & object, const NType & callbackType, const NCallback & callback) const
	{
		NCheck(NEventInfoRemoveHandler(GetHandle(), object.GetHandle(), callbackType.GetHandle(), callback.GetHandle()));
	}
};

}}

#endif // !N_EVENT_INFO_HPP_INCLUDED
