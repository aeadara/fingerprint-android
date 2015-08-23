#ifndef N_DEVICE_HPP_INCLUDED
#define N_DEVICE_HPP_INCLUDED

#include <Core/NObject.hpp>
#include <Plugins/NPlugin.hpp>

namespace Neurotec { namespace Devices
{
using Neurotec::Plugins::HNPlugin;
#include <Devices/NDevice.h>
}}

N_DEFINE_ENUM_TYPE_TRAITS(Neurotec::Devices, NDeviceType)

namespace Neurotec { namespace Devices
{
class NDeviceManager;

class NDevice : public NObject
{
	N_DECLARE_OBJECT_CLASS(NDevice, NObject)

public:
	class ChildCollection;

public:
	static NType NDeviceTypeNativeTypeOf()
	{
		return NObject::GetObject<NType>(N_TYPE_OF(NDeviceType), true);
	}

	NDeviceManager GetOwner() const;

	::Neurotec::Plugins::NPlugin GetPlugin() const
	{
		return GetObject<HandleType, ::Neurotec::Plugins::NPlugin>(NDeviceGetPlugin, true);
	}

	NDeviceType GetDeviceType() const
	{
		NDeviceType type;
		NCheck(NDeviceGetDeviceType(GetHandle(), &type));
		return type;
	}

	bool IsAvailable() const
	{
		NBool isAvailable;
		NCheck(NDeviceIsAvailable(GetHandle(), &isAvailable));
		return isAvailable != 0;
	}

	bool IsPrivate() const
	{
		NBool isPrivate;
		NCheck(NDeviceIsPrivate(GetHandle(), &isPrivate));
		return isPrivate != 0;
	}

	bool IsDisconnectable() const
	{
		NBool isPrivate;
		NCheck(NDeviceIsDisconnectable(GetHandle(), &isPrivate));
		return isPrivate != 0;
	}

	NDevice GetParent() const
	{
		return GetObject<HandleType, NDevice>(NDeviceGetParent, true);
	}

	NString GetId() const
	{
		return GetString(NDeviceGetIdN);
	}

	NString GetDisplayName() const
	{
		return GetString(NDeviceGetDisplayNameN);
	}

	NString GetMake() const
	{
		return GetString(NDeviceGetMakeN);
	}

	NString GetModel() const
	{
		return GetString(NDeviceGetModelN);
	}

	NString GetSerialNumber() const
	{
		return GetString(NDeviceGetSerialNumberN);
	}

	ChildCollection GetChildren();
	const ChildCollection GetChildren() const;
};

}}

#include <Devices/NDeviceManager.hpp>

namespace Neurotec { namespace Devices
{

class NDevice::ChildCollection : public ::Neurotec::Collections::NCollectionWithAllOutBase<NDevice, NDevice,
	NDeviceGetChildCount, NDeviceGetChild, NDeviceGetChildren>
{
	ChildCollection(const NDevice & owner)
	{
		SetOwner(owner);
	}

	friend class NDevice;
};

inline NDevice::ChildCollection NDevice::GetChildren()
{
	return NDevice::ChildCollection(*this);
}

inline const NDevice::ChildCollection NDevice::GetChildren() const
{
	return NDevice::ChildCollection(*this);
}

inline NDeviceManager NDevice::GetOwner() const
{
	return NObject::GetOwner<NDeviceManager>();
}

}}

#endif // !N_DEVICE_HPP_INCLUDED
