#ifndef N_TYPE_DESCRIPTOR_HPP_INCLUDED
#define N_TYPE_DESCRIPTOR_HPP_INCLUDED

#include <ComponentModel/NMethodDescriptor.hpp>
#include <ComponentModel/NPropertyDescriptor.hpp>
#include <ComponentModel/NEventDescriptor.hpp>
namespace Neurotec { namespace ComponentModel
{
#include <ComponentModel/NTypeDescriptor.h>
}}

namespace Neurotec { namespace ComponentModel
{

class NTypeDescriptor
{
	N_DECLARE_STATIC_OBJECT_CLASS(NTypeDescriptor)

public:
	static NArrayWrapper<NMethodDescriptor> GetMethods(const NObject & object)
	{
		HNMethodDescriptor * arhMethods;
		NInt methodCount;
		NCheck(NTypeDescriptorGetMethods(object.GetHandle(), &arhMethods, &methodCount));
		return NArrayWrapper<NMethodDescriptor>(arhMethods, methodCount);
	}

	static NArrayWrapper<NMethodDescriptor> GetMethods(const NType & type)
	{
		HNMethodDescriptor * arhMethods;
		NInt methodCount;
		NCheck(NTypeDescriptorGetMethodsForType(type.GetHandle(), &arhMethods, &methodCount));
		return NArrayWrapper<NMethodDescriptor>(arhMethods, methodCount);
	}

	static NArrayWrapper<NPropertyDescriptor> GetProperties(const NObject & object)
	{
		HNPropertyDescriptor * arhProperties;
		NInt propertyCount;
		NCheck(NTypeDescriptorGetProperties(object.GetHandle(), &arhProperties, &propertyCount));
		return NArrayWrapper<NPropertyDescriptor>(arhProperties, propertyCount);
	}

	static NArrayWrapper<NPropertyDescriptor> GetProperties(const NType & type)
	{
		HNPropertyDescriptor * arhProperties;
		NInt propertyCount;
		NCheck(NTypeDescriptorGetPropertiesForType(type.GetHandle(), &arhProperties, &propertyCount));
		return NArrayWrapper<NPropertyDescriptor>(arhProperties, propertyCount);
	}

	static NString GetDefaultPropertyName(const NObject & object)
	{
		HNString hValue;
		NCheck(NTypeDescriptorGetDefaultPropertyName(object.GetHandle(), &hValue));
		return NString(hValue, true);
	}

	static NString GetDefaultPropertyName(const NType & type)
	{
		HNString hValue;
		NCheck(NTypeDescriptorGetDefaultPropertyNameForType(type.GetHandle(), &hValue));
		return NString(hValue, true);
	}

	static NArrayWrapper<NEventDescriptor> GetEvents(const NObject & object)
	{
		HNEventDescriptor * arhEvents;
		NInt eventCount;
		NCheck(NTypeDescriptorGetEvents(object.GetHandle(), &arhEvents, &eventCount));
		return NArrayWrapper<NEventDescriptor>(arhEvents, eventCount);
	}

	static NArrayWrapper<NEventDescriptor> GetEvents(const NType & type)
	{
		HNEventDescriptor * arhEvents;
		NInt eventCount;
		NCheck(NTypeDescriptorGetEventsForType(type.GetHandle(), &arhEvents, &eventCount));
		return NArrayWrapper<NEventDescriptor>(arhEvents, eventCount);
	}
};

}}

#endif // !N_TYPE_DESCRIPTOR_HPP_INCLUDED
