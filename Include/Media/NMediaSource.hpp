#ifndef N_MEDIA_SOURCE_HPP_INCLUDED
#define N_MEDIA_SOURCE_HPP_INCLUDED

#include <Media/NMediaFormat.hpp>
namespace Neurotec { namespace Media
{
#include <Media/NMediaSource.h>
}}

namespace Neurotec { namespace Media
{

#undef NMS_DO_NOT_USE_DIRECT_SHOW
#undef NMS_DO_NOT_USE_WINDOWS_MEDIA_FOUNDATION
#undef NMS_PREFER_DIRECT_SHOW
#undef NMS_ALLOW_DUPLICATE_DEVICES

const NUInt NMS_DO_NOT_USE_DIRECT_SHOW              = 0x00000001;
const NUInt NMS_DO_NOT_USE_WINDOWS_MEDIA_FOUNDATION = 0x00000002;
const NUInt NMS_PREFER_DIRECT_SHOW                  = 0x00000004;
const NUInt NMS_ALLOW_DUPLICATE_DEVICES             = 0x00000008;

class NMediaSource : public NObject
{
	N_DECLARE_OBJECT_CLASS(NMediaSource, NObject)

public:
	static NArrayWrapper<NMediaSource> EnumDevices(NMediaType mediaType, NUInt flags = 0)
	{
		HNMediaSource * arhDevices = NULL;
		NInt deviceCount = 0;
		NCheck(NMediaSourceEnumDevices(mediaType, flags, &arhDevices, &deviceCount));
		return NArrayWrapper<NMediaSource>(arhDevices, deviceCount);
	}

	static NMediaSource FromFile(const NStringWrapper & fileName, NUInt flags = 0)
	{
		HNMediaSource handle;
		NCheck(NMediaSourceCreateFromFileN(fileName.GetHandle(), flags, &handle));
		return FromHandle<NMediaSource>(handle);
	}

	static NMediaSource FromUrl(const NStringWrapper & url, NUInt flags = 0)
	{
		HNMediaSource handle;
		NCheck(NMediaSourceCreateFromUrlN(url.GetHandle(), flags, &handle));
		return FromHandle<NMediaSource>(handle);
	}

	NArrayWrapper<NMediaFormat> GetFormats(NMediaType mediaType) const
	{
		HNMediaFormat * arhFormats = NULL;
		NInt formatCount = 0;
		NCheck(NMediaSourceGetFormats(GetHandle(), mediaType, &arhFormats, &formatCount));
		return NArrayWrapper<NMediaFormat>(arhFormats, formatCount);
	}

	NMediaFormat GetCurrentFormat(NMediaType mediaType) const
	{
		HNMediaFormat hFormat;
		NCheck(NMediaSourceGetCurrentFormat(GetHandle(), mediaType, &hFormat));
		return FromHandle<NMediaFormat>(hFormat);
	}

	void SetCurrentFormat(NMediaType mediaType, const NMediaFormat & value)
	{
		NCheck(NMediaSourceSetCurrentFormat(GetHandle(), mediaType, value.GetHandle()));
	}

	NString GetId() const
	{
		return GetString(NMediaSourceGetIdN);
	}

	NString GetDisplayName() const
	{
		return GetString(NMediaSourceGetDisplayNameN);
	}

	NMediaType GetMediaType() const
	{
		NMediaType value;
		NCheck(NMediaSourceGetMediaType(GetHandle(), &value));
		return value;
	}
};

}}

#endif // !N_MEDIA_SOURCE_HPP_INCLUDED
