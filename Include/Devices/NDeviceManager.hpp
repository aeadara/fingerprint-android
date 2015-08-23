#include <Devices/NDevice.hpp>
#include <Biometrics/NBiometricEngine.hpp>

#ifndef N_DEVICE_MANAGER_HPP_INCLUDED
#define N_DEVICE_MANAGER_HPP_INCLUDED

#include <Plugins/NPluginManager.hpp>
#include <Collections/NCollection.hpp>
#include <ComponentModel/NParameterDescriptor.hpp>
#include <Core/NPropertyBag.hpp>
#include <Collections/NCollections.hpp>
namespace Neurotec { namespace Devices
{
using ::Neurotec::Plugins::HNPluginManager;
using ::Neurotec::Collections::NCollectionChangedAction;
using ::Neurotec::ComponentModel::HNParameterDescriptor;
using ::Neurotec::Biometrics::HNBiometricEngine;
#include <Devices/NDeviceManager.h>
}}

namespace Neurotec { namespace Devices
{

class NDeviceManager : public NObject
{
	N_DECLARE_OBJECT_CLASS(NDeviceManager, NObject)

public:
	class NDeviceCollection : public ::Neurotec::Collections::NCollectionWithChangeNotifications<NDevice, NDeviceManager,
		NDeviceManagerGetDeviceCount, NDeviceManagerGetDevice, NDeviceManagerGetDevices,
		NDeviceManagerAddDevicesCollectionChanged, NDeviceManagerRemoveDevicesCollectionChanged>
	{
		NDeviceCollection(const NDeviceManager & owner)
		{
			SetOwner(owner);
		}

		friend class NDeviceManager;
	public:
		using ::Neurotec::Collections::NCollectionBase<NDevice, NDeviceManager, NDeviceManagerGetDeviceCount, NDeviceManagerGetDevice>::Get;
		NDevice Get(const NStringWrapper & id) const
		{
			HNDevice hDevice;
			NCheck(NDeviceManagerGetDeviceByIdN(this->GetOwnerHandle(), id.GetHandle(), &hDevice));
			return FromHandle<NDevice>(hDevice, true);
		}

		NDevice operator[](const NStringWrapper & id) const
		{
			return Get(id);
		}

	};

private:
	static HNDeviceManager Create()
	{
		HNDeviceManager handle;
		NCheck(NDeviceManagerCreateEx(&handle));
		return handle;
	}

	template<typename F>
	class DeviceCallbackDelegate : public EventHandlerBase<F>
	{
	public:
		DeviceCallbackDelegate(F f)
			: EventHandlerBase<F>(f)
		{
		}

		static NResult N_API NativeCallback(HNDeviceManager hDeviceManager, HNDevice hDevice, void * pParam)
		{
			NResult result = N_OK;
			try
			{
				EventHandlerBase<F> * wrapper = reinterpret_cast<EventHandlerBase<F> *>(pParam);
				wrapper->f(wrapper->pTarget, FromHandle<NDevice>(hDevice, false));
			}
			N_EXCEPTION_CATCH_AND_SET_LAST(result);
			return result;
		}
	};

public:
	typedef void (* DeviceCallback)(NDeviceManager * pDeviceManager, const NDevice & Device);

	static NType NDeviceManagerDeviceCallbackNativeTypeOf()
	{
		return NObject::GetObject<NType>(N_TYPE_OF(NDeviceManagerDeviceCallback), true);
	}

	static ::Neurotec::Plugins::NPluginManager GetPluginManager()
	{
		return GetObject< ::Neurotec::Plugins::NPluginManager>(NDeviceManagerGetPluginManager, true);
	}

	static bool IsConnectToDeviceSupported(const ::Neurotec::Plugins::NPlugin & plugin)
	{
		NBool value;
		NCheck(NDeviceManagerIsConnectToDeviceSupported(plugin.GetHandle(), &value));
		return value != 0;
	}

	static NArrayWrapper< ::Neurotec::ComponentModel::NParameterDescriptor> GetConnectToDeviceParameters(const ::Neurotec::Plugins::NPlugin & plugin)
	{
		HNParameterDescriptor * arhParameters;
		NInt parameterCount;
		NCheck(NDeviceManagerGetConnectToDeviceParameters(plugin.GetHandle(), &arhParameters, &parameterCount));
		return NArrayWrapper< ::Neurotec::ComponentModel::NParameterDescriptor>(arhParameters, parameterCount);
	}

	NDeviceManager()
		: NObject(Create(), true)
	{
	}

	void Initialize()
	{
		NCheck(NDeviceManagerInitialize(GetHandle()));
	}

	NDevice ConnectToDevice(const ::Neurotec::Plugins::NPlugin & plugin, const NPropertyBag & parameters)
	{
		HNDevice hDevice;
		NCheck(NDeviceManagerConnectToDevice(GetHandle(), plugin.GetHandle(), parameters.GetHandle(), &hDevice));
		return FromHandle<NDevice>(hDevice, true);
	}

	NDevice ConnectToDevice(const NStringWrapper & plugin, const NStringWrapper & parameters)
	{
		HNDevice hDevice;
		NCheck(NDeviceManagerConnectToDeviceWithStringN(GetHandle(), plugin.GetHandle(), parameters.GetHandle(), &hDevice));
		return FromHandle<NDevice>(hDevice, true);
	}

	void DisconnectFromDevice(const NDevice & device)
	{
		NCheck(NDeviceManagerDisconnectFromDevice(GetHandle(), device.GetHandle()));
	}

	bool IsInitialized()
	{
		NBool value;
		NCheck(NDeviceManagerIsInitialized(GetHandle(), &value));
		return value != 0;
	}

	NDeviceType GetDeviceTypes()
	{
		NDeviceType value;
		NCheck(NDeviceManagerGetDeviceTypes(GetHandle(), &value));
		return value;
	}

	void SetDeviceTypes(NDeviceType value)
	{
		NCheck(NDeviceManagerSetDeviceTypes(GetHandle(), value));
	}

	bool GetAutoPlug()
	{
		NBool value;
		NCheck(NDeviceManagerGetAutoPlug(GetHandle(), &value));
		return value != 0;
	}

	void SetAutoPlug(bool value)
	{
		NCheck(NDeviceManagerSetAutoPlug(GetHandle(), value ? NTrue : NFalse));
	}

	::Neurotec::Biometrics::NBiometricEngine GetBiometricEngine() const
	{
		return GetObject<HandleType, ::Neurotec::Biometrics::NBiometricEngine>(NDeviceManagerGetBiometricEngine, true);
	}

	void SetBiometricEngine(const ::Neurotec::Biometrics::NBiometricEngine & value)
	{
		SetObject(NDeviceManagerSetBiometricEngine, value);
	}

	NDeviceCollection GetDevices()
	{
		return NDeviceCollection(*this);
	}

	const NDeviceCollection GetDevices() const
	{
		return NDeviceCollection(*this);
	}
};

}}

#endif // !N_DEVICE_MANAGER_HPP_INCLUDED
