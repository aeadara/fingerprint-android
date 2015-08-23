#ifndef N_BIOMETRIC_DEVICE_HPP_INCLUDED
#define N_BIOMETRIC_DEVICE_HPP_INCLUDED

#include <Devices/NDevice.hpp>
#include <Biometrics/NBiometricTypes.hpp>
#include <Biometrics/NBiometric.hpp>
namespace Neurotec { namespace Devices
{
using ::Neurotec::Biometrics::NBiometricType;
using ::Neurotec::Biometrics::NBiometricStatus;
using ::Neurotec::Biometrics::HNBiometric;
#include <Devices/NBiometricDevice.h>
}}

namespace Neurotec { namespace Devices
{

class NBiometricDevice : public NDevice
{
	N_DECLARE_OBJECT_CLASS(NBiometricDevice, NDevice)

public:
	class CapturePreviewEventArgs : public EventArgs
	{
	private:
		HNBiometric hBiometric;

	public:
		CapturePreviewEventArgs(HNBiometricDevice hDevice, HNBiometric hBiometric, void * pParam)
			: EventArgs(hDevice, pParam), hBiometric(hBiometric)
		{
		}

		::Neurotec::Biometrics::NBiometric GetBiometric() const
		{
			return FromHandle< ::Neurotec::Biometrics::NBiometric>(hBiometric);
		}
	};

private:
	template<typename F>
	class CapturePreviewEventHandler : public EventHandlerBase<F>
	{
	public:
		CapturePreviewEventHandler(F f)
			: EventHandlerBase<F>(f)
		{
		}

		static NResult N_API NativeCallback(HNBiometricDevice hDevice, HNBiometric hBiometric, void * pParam)
		{
			NResult result = N_OK;
			try
			{
				CapturePreviewEventHandler<F> * pHandler = reinterpret_cast<CapturePreviewEventHandler<F> *>(pParam);
				CapturePreviewEventArgs e(hDevice, hBiometric, pHandler->pParam);
				pHandler->callback(e);
			}
			N_EXCEPTION_CATCH_AND_SET_LAST(result);
			return result;
		}
	};

public:
	static NType NBiometricDeviceCapturePreviewCallbackNativeTypeOf()
	{
		return NObject::GetObject<NType>(N_TYPE_OF(NBiometricDeviceCapturePreviewCallback), true);
	}

	void Cancel()
	{
		NCheck(NBiometricDeviceCancel(GetHandle()));
	}

	void StartSequence()
	{
		NCheck(NBiometricDeviceStartSequence(GetHandle()));
	}

	void EndSequence()
	{
		NCheck(NBiometricDeviceEndSequence(GetHandle()));
	}

	NBiometricStatus Capture(const ::Neurotec::Biometrics::NBiometric & biometric, NInt timeoutMilliseconds = -1)
	{
		NBiometricStatus status;
		NCheck(NBiometricDeviceCapture(GetHandle(), biometric.GetHandle(), timeoutMilliseconds, &status));
		return status;
	}

	NBiometricType GetBiometricType() const
	{
		NBiometricType type;
		NCheck(NBiometricDeviceGetBiometricType(GetHandle(), &type));
		return type;
	}

	NUShort GetVendorId() const
	{
		NUShort value;
		NCheck(NBiometricDeviceGetVendorId(GetHandle(), &value));
		return value;
	}

	NUShort GetProductId() const
	{
		NUShort value;
		NCheck(NBiometricDeviceGetProductId(GetHandle(), &value));
		return value;
	}

	bool IsSpoofDetectionSupported() const
	{
		NBool value;
		NCheck(NBiometricDeviceIsSpoofDetectionSupported(GetHandle(), &value));
		return value != 0;
	}

	bool GetSpoofDetection() const
	{
		NBool value;
		NCheck(NBiometricDeviceGetSpoofDetection(GetHandle(), &value));
		return value != 0;
	}

	void SetSpoofDetection(bool value)
	{
		NCheck(NBiometricDeviceSetSpoofDetection(GetHandle(), value ? NTrue : NFalse));
	}

	void AddCapturePreviewCallback(const NCallback & callback)
	{
		NCheck(NBiometricDeviceAddCapturePreview(GetHandle(), callback.GetHandle()));
	}

	template<typename F>
	NCallback AddCapturePreviewCallback(const F & callback, void * pParam = NULL)
	{
		NCallback cb = NTypes::CreateCallback<CapturePreviewEventHandler<F> >(callback, pParam);
		AddCapturePreviewCallback(cb);
		return cb;
	}

	void RemoveCapturePreviewCallback(const NCallback & callback)
	{
		NCheck(NBiometricDeviceRemoveCapturePreview(GetHandle(), callback.GetHandle()));
	}

	template<typename F>
	NCallback RemoveCapturePreviewCallback(const F & callback, void * pParam = NULL)
	{
		NCallback cb = NTypes::CreateCallback<CapturePreviewEventHandler<F> >(callback, pParam);
		RemoveCapturePreviewCallback(cb);
		return cb;
	}
};

}}

#endif // !N_BIOMETRIC_DEVICE_HPP_INCLUDED
