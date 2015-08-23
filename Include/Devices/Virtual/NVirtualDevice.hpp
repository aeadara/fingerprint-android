#ifndef N_VIRTUAL_DEVICE_HPP_INCLUDED
#define N_VIRTUAL_DEVICE_HPP_INCLUDED

#include <Devices/NDevice.hpp>
#include <Biometrics/NBiometricTypes.hpp>
#include <Media/NVideoFormat.hpp>
#include <Media/NAudioFormat.hpp>

namespace Neurotec { namespace Devices { namespace Virtual
{
using Neurotec::Biometrics::NFImpressionType;
using Neurotec::Biometrics::NFPosition;
using Neurotec::Biometrics::NEPosition;
using Neurotec::Media::HNMediaFormat;
using Neurotec::Media::HNVideoFormat;
using Neurotec::Media::HNAudioFormat;
#include <Devices/Virtual/NVirtualDevice.h>
}}}

N_DEFINE_ENUM_TYPE_TRAITS(Neurotec::Devices::Virtual, NVirtualDeviceOptions)

namespace Neurotec { namespace Devices { namespace Virtual
{

class NVirtualDevice : public NObject
{
	N_DECLARE_OBJECT_CLASS(NVirtualDevice, NObject)

private:
	static HNVirtualDevice Create()
	{
		HNVirtualDevice handle;
		NCheck(NVirtualDeviceCreate(&handle));
		return handle;
	}

public:
	class SupportedImpressionTypeCollection : public ::Neurotec::Collections::NCollectionBase<NFImpressionType, NVirtualDevice,
		NVirtualDeviceGetSupportedImpressionTypeCount, NVirtualDeviceGetSupportedImpressionType>
	{
		SupportedImpressionTypeCollection(const NVirtualDevice & owner)
		{
			SetOwner(owner);
		}

		friend class NVirtualDevice;
	public:
		void Set(NInt index, NFImpressionType value)
		{
			NCheck(NVirtualDeviceSetSupportedImpressionType(this->GetOwnerHandle(), index, value));
		}

		NInt Add(NFImpressionType value)
		{
			NInt result;
			NCheck(NVirtualDeviceAddSupportedImpressionType(this->GetOwnerHandle(), value, &result));
			return result;
		}

		void Insert(NInt index, NFImpressionType value)
		{
			NCheck(NVirtualDeviceInsertSupportedImpressionType(this->GetOwnerHandle(), index, value));
		}

		void RemoveAt(NInt index)
		{
			NCheck(NVirtualDeviceRemoveSupportedImpressionTypeAt(this->GetOwnerHandle(), index));
		}

		void Clear()
		{
			NCheck(NVirtualDeviceClearSupportedImpressionTypes(this->GetOwnerHandle()));
		}

	};
	class SupportedFingerPositionCollection : public ::Neurotec::Collections::NCollectionBase<NFPosition, NVirtualDevice,
		NVirtualDeviceGetSupportedFingerPositionCount, NVirtualDeviceGetSupportedFingerPosition>
	{
		SupportedFingerPositionCollection(const NVirtualDevice & owner)
		{
			SetOwner(owner);
		}

		friend class NVirtualDevice;
	public:
		void Set(NInt index, NFPosition value)
		{
			NCheck(NVirtualDeviceSetSupportedFingerPosition(this->GetOwnerHandle(), index, value));
		}

		NInt Add(NFPosition value)
		{
			NInt result;
			NCheck(NVirtualDeviceAddSupportedFingerPosition(this->GetOwnerHandle(), value, &result));
			return result;
		}

		void Insert(NInt index, NFPosition value)
		{
			NCheck(NVirtualDeviceInsertSupportedFingerPosition(this->GetOwnerHandle(), index, value));
		}

		void RemoveAt(NInt index)
		{
			NCheck(NVirtualDeviceRemoveSupportedFingerPositionAt(this->GetOwnerHandle(), index));
		}

		void Clear()
		{
			NCheck(NVirtualDeviceClearSupportedFingerPositions(this->GetOwnerHandle()));
		}

	};
	class SupportedIrisPositionCollection : public ::Neurotec::Collections::NCollectionBase<NEPosition, NVirtualDevice,
		NVirtualDeviceGetSupportedIrisPositionCount, NVirtualDeviceGetSupportedIrisPosition>
	{
		SupportedIrisPositionCollection(const NVirtualDevice & owner)
		{
			SetOwner(owner);
		}

		friend class NVirtualDevice;
	public:
		void Set(NInt index, NEPosition value)
		{
			NCheck(NVirtualDeviceSetSupportedIrisPosition(this->GetOwnerHandle(), index, value));
		}

		NInt Add(NEPosition value)
		{
			NInt result;
			NCheck(NVirtualDeviceAddSupportedIrisPosition(this->GetOwnerHandle(), value, &result));
			return result;
		}

		void Insert(NInt index, NEPosition value)
		{
			NCheck(NVirtualDeviceInsertSupportedIrisPosition(this->GetOwnerHandle(), index, value));
		}

		void RemoveAt(NInt index)
		{
			NCheck(NVirtualDeviceRemoveSupportedIrisPositionAt(this->GetOwnerHandle(), index));
		}

		void Clear()
		{
			NCheck(NVirtualDeviceClearSupportedIrisPositions(this->GetOwnerHandle()));
		}

	};
	class VideoFormatCollection : public ::Neurotec::Collections::NCollectionBase< ::Neurotec::Media::NVideoFormat, NVirtualDevice,
		NVirtualDeviceGetVideoFormatCount, NVirtualDeviceGetVideoFormat>
	{
		VideoFormatCollection(const NVirtualDevice & owner)
		{
			SetOwner(owner);
		}

		friend class NVirtualDevice;
	public:
		void Set(NInt index, const ::Neurotec::Media::NVideoFormat & value)
		{
			NCheck(NVirtualDeviceSetVideoFormat(this->GetOwnerHandle(), index, value.GetHandle()));
		}

		NInt Add(const ::Neurotec::Media::NVideoFormat & value)
		{
			NInt result;
			NCheck(NVirtualDeviceAddVideoFormat(this->GetOwnerHandle(), value.GetHandle(), &result));
			return result;
		}

		void Insert(NInt index, const ::Neurotec::Media::NVideoFormat & value)
		{
			NCheck(NVirtualDeviceInsertVideoFormat(this->GetOwnerHandle(), index, value.GetHandle()));
		}

		void RemoveAt(NInt index)
		{
			NCheck(NVirtualDeviceRemoveVideoFormatAt(this->GetOwnerHandle(), index));
		}

		void Clear()
		{
			NCheck(NVirtualDeviceClearVideoFormats(this->GetOwnerHandle()));
		}

	};
	class AudioFormatCollection : public ::Neurotec::Collections::NCollectionBase< ::Neurotec::Media::NAudioFormat, NVirtualDevice,
		NVirtualDeviceGetAudioFormatCount, NVirtualDeviceGetAudioFormat>
	{
		AudioFormatCollection(const NVirtualDevice & owner)
		{
			SetOwner(owner);
		}

		friend class NVirtualDevice;
	public:
		void Set(NInt index, const ::Neurotec::Media::NAudioFormat & value)
		{
			NCheck(NVirtualDeviceSetAudioFormat(this->GetOwnerHandle(), index, value.GetHandle()));
		}

		NInt Add(const ::Neurotec::Media::NAudioFormat & value)
		{
			NInt result;
			NCheck(NVirtualDeviceAddAudioFormat(this->GetOwnerHandle(), value.GetHandle(), &result));
			return result;
		}

		void Insert(NInt index, const ::Neurotec::Media::NAudioFormat & value)
		{
			NCheck(NVirtualDeviceInsertAudioFormat(this->GetOwnerHandle(), index, value.GetHandle()));
		}

		void RemoveAt(NInt index)
		{
			NCheck(NVirtualDeviceRemoveAudioFormatAt(this->GetOwnerHandle(), index));
		}

		void Clear()
		{
			NCheck(NVirtualDeviceClearAudioFormats(this->GetOwnerHandle()));
		}

	};
	class SourceCollection : public ::Neurotec::Collections::NCollectionBase<NString, NVirtualDevice,
		NVirtualDeviceGetSourceCount, NVirtualDeviceGetSource>
	{
		SourceCollection(const NVirtualDevice & owner)
		{
			SetOwner(owner);
		}

		friend class NVirtualDevice;
	public:
		void Set(NInt index, const NStringWrapper & value)
		{
			NCheck(NVirtualDeviceSetSourceN(this->GetOwnerHandle(), index, value.GetHandle()));
		}

		NInt Add(const NStringWrapper & value)
		{
			NInt result;
			NCheck(NVirtualDeviceAddSourceN(this->GetOwnerHandle(), value.GetHandle(), &result));
			return result;
		}

		void Insert(NInt index, const NStringWrapper & value)
		{
			NCheck(NVirtualDeviceInsertSourceN(this->GetOwnerHandle(), index, value.GetHandle()));
		}

		void RemoveAt(NInt index)
		{
			NCheck(NVirtualDeviceRemoveSourceAt(this->GetOwnerHandle(), index));
		}

		void Clear()
		{
			NCheck(NVirtualDeviceClearSources(this->GetOwnerHandle()));
		}

	};

public:
	static NType NVirtualDeviceOptionsNativeTypeOf()
	{
		return NObject::GetObject<NType>(N_TYPE_OF(NVirtualDeviceOptions), true);
	}

	NVirtualDevice()
		: NObject(Create(), true)
	{
	}

	NDeviceType GetDeviceType() const
	{
		NDeviceType value;
		NCheck(NVirtualDeviceGetDeviceType(GetHandle(), &value));
		return value;
	}

	void SetDeviceType(NDeviceType value)
	{
		NCheck(NVirtualDeviceSetDeviceType(GetHandle(), value));
	}

	NString GetDisplayName() const
	{
		HNString hValue;
		NCheck(NVirtualDeviceGetDisplayName(GetHandle(), &hValue));
		return NString(hValue, true);
	}

	void SetDisplayName(const NStringWrapper & value)
	{
		NCheck(NVirtualDeviceSetDisplayName(GetHandle(), value.GetHandle()));
	}

	::Neurotec::Media::NMediaFormat GetCurrentFormat() const
	{
		return GetObject<HandleType, ::Neurotec::Media::NMediaFormat>(NVirtualDeviceGetCurrentFormat);
	}

	void SetCurrentFormat(const ::Neurotec::Media::NMediaFormat & value)
	{
		NCheck(NVirtualDeviceSetCurrentFormat(GetHandle(), value.GetHandle()));
	}

	NVirtualDeviceOptions GetOptions() const
	{
		NVirtualDeviceOptions value;
		NCheck(NVirtualDeviceGetOptions(GetHandle(), &value));
		return value;
	}

	void SetOptions(NVirtualDeviceOptions value)
	{
		NCheck(NVirtualDeviceSetOptions(GetHandle(), value));
	}

	bool GetIsPluggedIn() const
	{
		NBool value;
		NCheck(NVirtualDeviceGetIsPluggedIn(GetHandle(), &value));
		return value != 0;
	}

	void SetIsPluggedIn(bool value)
	{
		NCheck(NVirtualDeviceSetIsPluggedIn(GetHandle(), value ? NTrue : NFalse));
	}

	SourceCollection GetSources()
	{
		return SourceCollection(*this);
	}

	const SourceCollection GetSources() const
	{
		return SourceCollection(*this);
	}

	VideoFormatCollection GetVideoFormats()
	{
		return VideoFormatCollection(*this);
	}

	const VideoFormatCollection GetVideoFormats() const
	{
		return VideoFormatCollection(*this);
	}

	AudioFormatCollection GetAudioFormats()
	{
		return AudioFormatCollection(*this);
	}

	const AudioFormatCollection GetAudioFormats() const
	{
		return AudioFormatCollection(*this);
	}

	SupportedImpressionTypeCollection GetImpressionTypes()
	{
		return SupportedImpressionTypeCollection(*this);
	}

	const SupportedImpressionTypeCollection GetImpressionTypes() const
	{
		return SupportedImpressionTypeCollection(*this);
	}

	SupportedFingerPositionCollection GetFingerPositions()
	{
		return SupportedFingerPositionCollection(*this);
	}

	const SupportedFingerPositionCollection GetFingerPositions() const
	{
		return SupportedFingerPositionCollection(*this);
	}

	SupportedIrisPositionCollection GetIrisPositions()
	{
		return SupportedIrisPositionCollection(*this);
	}

	const SupportedIrisPositionCollection GetIrisPositions() const
	{
		return SupportedIrisPositionCollection(*this);
	}
};

}}}

#endif //!N_VIRTUAL_DEVICE_HPP_INCLUDED
