#include <ComponentModel/NMemberDescriptor.hpp>
#include <Core/NValue.hpp>

#ifndef N_EVENT_DESCRIPTOR_HPP_INCLUDED
#define N_EVENT_DESCRIPTOR_HPP_INCLUDED

namespace Neurotec { namespace ComponentModel
{
#include <ComponentModel/NEventDescriptor.h>
}}

namespace Neurotec { namespace ComponentModel
{

class NEventDescriptor : public NMemberDescriptor
{
	N_DECLARE_OBJECT_CLASS(NEventDescriptor, NMemberDescriptor)

public:
	NType GetEventType() const
	{
		return GetObject<HandleType, NType>(NEventDescriptorGetEventType, true);
	}

	void AddHandler(const NObject & object, const NValue & callback) const
	{
		NCheck(NEventDescriptorAddHandlerN(GetHandle(), object.GetHandle(), callback.GetHandle()));
	}

	void AddHandler(const NObject & object, const NType & callbackType, const NCallback & callback) const
	{
		NCheck(NEventDescriptorAddHandler(GetHandle(), object.GetHandle(), callbackType.GetHandle(), callback.GetHandle()));
	}

	void RemoveHandler(const NObject & object, const NValue & callback) const
	{
		NCheck(NEventDescriptorRemoveHandlerN(GetHandle(), object.GetHandle(), callback.GetHandle()));
	}

	void RemoveHandler(const NObject & object, const NType & callbackType, const NCallback & callback) const
	{
		NCheck(NEventDescriptorRemoveHandler(GetHandle(), object.GetHandle(), callbackType.GetHandle(), callback.GetHandle()));
	}
};

}}

#endif // !N_EVENT_DESCRIPTOR_HPP_INCLUDED
