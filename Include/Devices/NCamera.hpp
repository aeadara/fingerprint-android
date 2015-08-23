#include <Devices/NCaptureDevice.hpp>

#ifndef N_CAMERA_HPP_INCLUDED
#define N_CAMERA_HPP_INCLUDED

#include <Images/NImage.hpp>
#include <Geometry/NGeometry.hpp>
#include <Media/NVideoFormat.hpp>
namespace Neurotec { namespace Devices
{
using ::Neurotec::Images::HNImage;
using ::Neurotec::Geometry::NRectF_;
using ::Neurotec::Media::HNVideoFormat;
#include <Devices/NCamera.h>
}}

N_DEFINE_ENUM_TYPE_TRAITS(Neurotec::Devices, NCameraStatus)

namespace Neurotec { namespace Devices
{
class NCamera : public NCaptureDevice
{
	N_DECLARE_OBJECT_CLASS(NCamera, NCaptureDevice)

public:
	class StillCapturedEventArgs : public EventArgs
	{
	private:
		HNStream hStream;
		HNValue hId;
		HNPropertyBag hProperties;

	public:
		StillCapturedEventArgs(HNCamera hCamera, HNStream hStream, HNValue hId, HNPropertyBag hProperties, void * pParam)
			: EventArgs(hCamera, pParam), hStream(hStream), hId(hId), hProperties(hProperties)
		{
		}

		::Neurotec::IO::NStream GetStream() const
		{
			return FromHandle< ::Neurotec::IO::NStream>(hStream, false);
		}

		NValue GetId() const
		{
			return FromHandle<NValue>(hId, false);
		}

		NPropertyBag GetProperties() const
		{
			return FromHandle<NPropertyBag>(hProperties, false);
		}
	};

private:
	template<typename F>
	class StillCapturedEventHandler : public EventHandlerBase<F>
	{
	public:
		StillCapturedEventHandler(F f)
			: EventHandlerBase<F>(f)
		{
		}

		static NResult N_API NativeCallback(HNCamera hCamera, HNStream hStream, HNValue hId, HNPropertyBag hProperties, void * pParam)
		{
			NResult result = N_OK;
			try
			{
				StillCapturedEventHandler<F> * pHandler = reinterpret_cast<StillCapturedEventHandler<F> *>(pParam);
				StillCapturedEventArgs e(hCamera, hStream, hId, hProperties, pHandler->pParam);
				pHandler->callback(e);
			}
			N_EXCEPTION_CATCH_AND_SET_LAST(result);
			return result;
		}
	};

public:
	static NType NCameraStillCapturedCallbackNativeTypeOf()
	{
		return NObject::GetObject<NType>(N_TYPE_OF(NCameraStillCapturedCallback), true);
	}

	static NType NCameraStatusNativeTypeOf()
	{
		return NObject::GetObject<NType>(N_TYPE_OF(NCameraStatus), true);
	}

	::Neurotec::Images::NImage GetFrame()
	{
		HNImage hImage = NULL;
		NCheck(NCameraGetFrame(GetHandle(), &hImage));
		return FromHandle< ::Neurotec::Images::NImage>(hImage);
	}

	bool IsFocusSupported() const
	{
		NBool value;
		NCheck(NCameraIsFocusSupported(GetHandle(), &value));
		return value != 0;
	}

	bool IsFocusRegionSupported() const
	{
		NBool value;
		NCheck(NCameraIsFocusRegionSupported(GetHandle(), &value));
		return value != 0;
	}

	bool GetFocusRegion(::Neurotec::Geometry::NRectF * pValue) const
	{
		NBool hasValue;
		NCheck(NCameraGetFocusRegion(GetHandle(), pValue, &hasValue));
		return hasValue != 0;
	}

	void SetFocusRegion(const ::Neurotec::Geometry::NRectF * pValue)
	{
		NCheck(NCameraSetFocusRegion(GetHandle(), pValue));
	}

	void ResetFocus()
	{
		NCheck(NCameraResetFocus(GetHandle()));
	}

	NCameraStatus Focus()
	{
		NCameraStatus status;
		NCheck(NCameraFocus(GetHandle(), &status));
		return status;
	}

	bool IsStillCaptureSupported() const
	{
		NBool value;
		NCheck(NCameraIsStillCaptureSupported(GetHandle(), &value));
		return value != 0;
	}

	NArrayWrapper< ::Neurotec::Media::NVideoFormat> GetStillFormats() const
	{
		return GetObjects<HandleType, ::Neurotec::Media::NVideoFormat>(NCameraGetStillFormats);
	}

	::Neurotec::Media::NVideoFormat GetCurrentStillFormat() const
	{
		return GetObject<HandleType, ::Neurotec::Media::NVideoFormat>(NCameraGetCurrentStillFormat);
	}

	void SetCurrentStillFormat(const ::Neurotec::Media::NVideoFormat & value)
	{
		NCheck(NCameraSetCurrentStillFormat(GetHandle(), value.GetHandle()));
	}

	NCameraStatus CaptureStill()
	{
		NCameraStatus status;
		NCheck(NCameraCaptureStill(GetHandle(), &status));
		return status;
	}

	void AddStillCapturedCallback(const NCallback & callback)
	{
		NCheck(NCameraAddStillCaptured(GetHandle(), callback.GetHandle()));
	}

	template<typename F>
	NCallback AddStillCapturedCallback(const F & callback, void * pParam = NULL)
	{
		NCallback cb = NTypes::CreateCallback<StillCapturedEventHandler<F> >(callback, pParam);
		AddStillCapturedCallback(cb);
		return cb;
	}

	void RemoveStillCapturedCallback(const NCallback & callback)
	{
		NCheck(NCameraRemoveStillCaptured(GetHandle(), callback.GetHandle()));
	}

	template<typename F>
	NCallback RemoveStillCapturedCallback(const F & callback, void * pParam = NULL)
	{
		NCallback cb = NTypes::CreateCallback<StillCapturedEventHandler<F> >(callback, pParam);
		RemoveStillCapturedCallback(cb);
		return cb;
	}
};

}}

#endif // !N_CAMERA_HPP_INCLUDED
