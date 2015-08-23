#include <Devices/NDevice.hpp>

#ifndef N_CAPTURE_DEVICE_HPP_INCLUDED
#define N_CAPTURE_DEVICE_HPP_INCLUDED

#include <Media/NMediaFormat.hpp>
namespace Neurotec { namespace Devices
{
using ::Neurotec::Media::HNMediaFormat;
using ::Neurotec::Media::NMediaType;
#include <Devices/NCaptureDevice.h>
}}

namespace Neurotec { namespace Devices
{
class NCaptureDevice : public NDevice
{
	N_DECLARE_OBJECT_CLASS(NCaptureDevice, NDevice)

public:
	void StartCapturing()
	{
		NCheck(NCaptureDeviceStartCapturing(GetHandle()));
	}

	void StopCapturing()
	{
		NCheck(NCaptureDeviceStopCapturing(GetHandle()));
	}

	NArrayWrapper< ::Neurotec::Media::NMediaFormat> GetFormats() const
	{
		return GetObjects<HandleType, ::Neurotec::Media::NMediaFormat>(NCaptureDeviceGetFormats);
	}

	::Neurotec::Media::NMediaFormat GetCurrentFormat() const
	{
		return GetObject<HandleType, ::Neurotec::Media::NMediaFormat>(NCaptureDeviceGetCurrentFormat);
	}

	void SetCurrentFormat(const ::Neurotec::Media::NMediaFormat & value)
	{
		NCheck(NCaptureDeviceSetCurrentFormat(GetHandle(), value.GetHandle()));
	}

	bool IsCapturing() const
	{
		NBool value;
		NCheck(NCaptureDeviceIsCapturing(GetHandle(), &value));
		return value != 0;
	}

	NMediaType GetMediaType() const
	{
		NMediaType value;
		NCheck(NCaptureDeviceGetMediaType(GetHandle(), &value));
		return value;
	}

	void AddIsCapturingChangedCallback(const NCallback & callback)
	{
		NCheck(NCaptureDeviceAddIsCapturingChanged(GetHandle(), callback.GetHandle()));
	}

	template<typename F>
	NCallback AddIsCapturingChangedCallback(const F & callback, void * pParam = NULL)
	{
		NCallback cb = NTypes::CreateCallback<NObject::EventHandler<F> >(callback, pParam);
		AddIsCapturingChangedCallback(cb);
		return cb;
	}

	void RemoveIsCapturingChangedCallback(const NCallback & callback)
	{
		NCheck(NCaptureDeviceRemoveIsCapturingChanged(GetHandle(), callback.GetHandle()));
	}

	template<typename F>
	NCallback RemoveIsCapturingChangedCallback(const F & callback, void * pParam = NULL)
	{
		NCallback cb = NTypes::CreateCallback<NObject::EventHandler<F> >(callback, pParam);
		RemoveIsCapturingChangedCallback(cb);
		return cb;
	}
};

}}

#endif // !N_CAPTURE_DEVICE_HPP_INCLUDED
