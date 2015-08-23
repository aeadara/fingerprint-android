#include <Media/NMediaFormat.hpp>

#ifndef N_VIDEO_FORMAT_HPP_INCLUDED
#define N_VIDEO_FORMAT_HPP_INCLUDED

namespace Neurotec { namespace Media
{
#include <Media/NVideoFormat.h>
}}

namespace Neurotec { namespace Media
{

#undef N_VIDEO_FORMAT_UNKNOWN
#undef N_VIDEO_FORMAT_RGB24
#undef N_VIDEO_FORMAT_ARGB32
#undef N_VIDEO_FORMAT_RGB32
#undef N_VIDEO_FORMAT_RGB555
#undef N_VIDEO_FORMAT_RGB565
#undef N_VIDEO_FORMAT_RGB8
#undef N_VIDEO_FORMAT_L8
#undef N_VIDEO_FORMAT_L16
#undef N_VIDEO_FORMAT_AI44
#undef N_VIDEO_FORMAT_AYUV
#undef N_VIDEO_FORMAT_YUY2
#undef N_VIDEO_FORMAT_YVYU
#undef N_VIDEO_FORMAT_YVU9
#undef N_VIDEO_FORMAT_UYVY
#undef N_VIDEO_FORMAT_NV11
#undef N_VIDEO_FORMAT_NV12
#undef N_VIDEO_FORMAT_NV21
#undef N_VIDEO_FORMAT_YV12
#undef N_VIDEO_FORMAT_I420
#undef N_VIDEO_FORMAT_IYUV
#undef N_VIDEO_FORMAT_Y210
#undef N_VIDEO_FORMAT_Y216
#undef N_VIDEO_FORMAT_Y410
#undef N_VIDEO_FORMAT_Y416
#undef N_VIDEO_FORMAT_Y41P
#undef N_VIDEO_FORMAT_Y41T
#undef N_VIDEO_FORMAT_Y42T
#undef N_VIDEO_FORMAT_P210
#undef N_VIDEO_FORMAT_P216
#undef N_VIDEO_FORMAT_P010
#undef N_VIDEO_FORMAT_P016
#undef N_VIDEO_FORMAT_V210
#undef N_VIDEO_FORMAT_V216
#undef N_VIDEO_FORMAT_V410
#undef N_VIDEO_FORMAT_MP43
#undef N_VIDEO_FORMAT_MP4S
#undef N_VIDEO_FORMAT_M4S2
#undef N_VIDEO_FORMAT_MP4V
#undef N_VIDEO_FORMAT_WMV1
#undef N_VIDEO_FORMAT_WMV2
#undef N_VIDEO_FORMAT_WMV3
#undef N_VIDEO_FORMAT_WVC1
#undef N_VIDEO_FORMAT_MSS1
#undef N_VIDEO_FORMAT_MSS2
#undef N_VIDEO_FORMAT_MPG1
#undef N_VIDEO_FORMAT_DVSL
#undef N_VIDEO_FORMAT_DVSD
#undef N_VIDEO_FORMAT_DVHD
#undef N_VIDEO_FORMAT_DV25
#undef N_VIDEO_FORMAT_DV50
#undef N_VIDEO_FORMAT_DVH1
#undef N_VIDEO_FORMAT_DVC
#undef N_VIDEO_FORMAT_H264
#undef N_VIDEO_FORMAT_MJPG
#undef N_VIDEO_FORMAT_DX50

const NUInt N_VIDEO_FORMAT_UNKNOWN =          0;
const NUInt N_VIDEO_FORMAT_RGB24   =         20;
const NUInt N_VIDEO_FORMAT_ARGB32  =         21;
const NUInt N_VIDEO_FORMAT_RGB32   =         22;
const NUInt N_VIDEO_FORMAT_RGB555  =         24;
const NUInt N_VIDEO_FORMAT_RGB565  =         23;
const NUInt N_VIDEO_FORMAT_RGB8    =         41;
const NUInt N_VIDEO_FORMAT_L8      =         50;
const NUInt N_VIDEO_FORMAT_L16     =         81;
const NUInt N_VIDEO_FORMAT_AI44    = 0x34344941;
const NUInt N_VIDEO_FORMAT_AYUV    = 0x56555941;
const NUInt N_VIDEO_FORMAT_YUY2    = 0x32595559;
const NUInt N_VIDEO_FORMAT_YVYU    = 0x55595659;
const NUInt N_VIDEO_FORMAT_YVU9    = 0x39555659;
const NUInt N_VIDEO_FORMAT_UYVY    = 0x59565955;
const NUInt N_VIDEO_FORMAT_NV11    = 0x3131564E;
const NUInt N_VIDEO_FORMAT_NV12    = 0x3231564E;
const NUInt N_VIDEO_FORMAT_NV21    = 0x3132564E;
const NUInt N_VIDEO_FORMAT_YV12    = 0x32315659;
const NUInt N_VIDEO_FORMAT_I420    = 0x30323449;
const NUInt N_VIDEO_FORMAT_IYUV    = 0x56555949;
const NUInt N_VIDEO_FORMAT_Y210    = 0x30313259;
const NUInt N_VIDEO_FORMAT_Y216    = 0x36313259;
const NUInt N_VIDEO_FORMAT_Y410    = 0x30313459;
const NUInt N_VIDEO_FORMAT_Y416    = 0x36313459;
const NUInt N_VIDEO_FORMAT_Y41P    = 0x50313459;
const NUInt N_VIDEO_FORMAT_Y41T    = 0x54313459;
const NUInt N_VIDEO_FORMAT_Y42T    = 0x54323459;
const NUInt N_VIDEO_FORMAT_P210    = 0x30313250;
const NUInt N_VIDEO_FORMAT_P216    = 0x36313250;
const NUInt N_VIDEO_FORMAT_P010    = 0x30313050;
const NUInt N_VIDEO_FORMAT_P016    = 0x36313050;
const NUInt N_VIDEO_FORMAT_V210    = 0x30313276;
const NUInt N_VIDEO_FORMAT_V216    = 0x36313276;
const NUInt N_VIDEO_FORMAT_V410    = 0x30313476;
const NUInt N_VIDEO_FORMAT_MP43    = 0x3334504D;
const NUInt N_VIDEO_FORMAT_MP4S    = 0x5334504D;
const NUInt N_VIDEO_FORMAT_M4S2    = 0x3253344D;
const NUInt N_VIDEO_FORMAT_MP4V    = 0x5634504D;
const NUInt N_VIDEO_FORMAT_WMV1    = 0x31564D57;
const NUInt N_VIDEO_FORMAT_WMV2    = 0x32564D57;
const NUInt N_VIDEO_FORMAT_WMV3    = 0x33564D57;
const NUInt N_VIDEO_FORMAT_WVC1    = 0x31435657;
const NUInt N_VIDEO_FORMAT_MSS1    = 0x3153534D;
const NUInt N_VIDEO_FORMAT_MSS2    = 0x3253534D;
const NUInt N_VIDEO_FORMAT_MPG1    = 0x3147504D;
const NUInt N_VIDEO_FORMAT_DVSL    = 0x6C737664;
const NUInt N_VIDEO_FORMAT_DVSD    = 0x64737664;
const NUInt N_VIDEO_FORMAT_DVHD    = 0x64687664;
const NUInt N_VIDEO_FORMAT_DV25    = 0x35327664;
const NUInt N_VIDEO_FORMAT_DV50    = 0x30357664;
const NUInt N_VIDEO_FORMAT_DVH1    = 0x31687664;
const NUInt N_VIDEO_FORMAT_DVC     = 0x20637664;
const NUInt N_VIDEO_FORMAT_H264    = 0x34363248;
const NUInt N_VIDEO_FORMAT_MJPG    = 0x47504A4D;
const NUInt N_VIDEO_FORMAT_DX50    = 0x30355844;

class NVideoFormat : public NMediaFormat
{
	N_DECLARE_OBJECT_CLASS(NVideoFormat, NMediaFormat)

private:
	static HNVideoFormat Create()
	{
		HNVideoFormat handle;
		NCheck(NVideoFormatCreate(&handle));
		return handle;
	}

public:
	static NString MediaSubtypeToString(NUInt value, const NStringWrapper & format = NString())
	{
		HNString hValue;
		NCheck(NVideoFormatMediaSubtypeToStringN(value, format.GetHandle(), &hValue));
		return NString(hValue, true);
	}

	NVideoFormat()
		: NMediaFormat(Create(), true)
	{
	}

	NUInt GetWidth() const
	{
		NUInt value;
		NCheck(NVideoFormatGetWidth(GetHandle(), &value));
		return value;
	}

	void SetWidth(NUInt value)
	{
		NCheck(NVideoFormatSetWidth(GetHandle(), value));
	}

	NUInt GetHeight() const
	{
		NUInt value;
		NCheck(NVideoFormatGetHeight(GetHandle(), &value));
		return value;
	}

	void SetHeight(NUInt value)
	{
		NCheck(NVideoFormatSetHeight(GetHandle(), value));
	}

	NSSizeType GetStride() const
	{
		NSSizeType value;
		NCheck(NVideoFormatGetStride(GetHandle(), &value));
		return value;
	}

	void SetStride(NSSizeType value)
	{
		NCheck(NVideoFormatSetStride(GetHandle(), value));
	}

	NURational GetFrameRate() const
	{
		NURational value;
		NCheck(NVideoFormatGetFrameRate(GetHandle(), &value));
		return value;
	}

	void SetFrameRate(const NURational & value)
	{
		NCheck(NVideoFormatSetFrameRate(GetHandle(), &value));
	}

	NVideoInterlaceMode GetInterlaceMode() const
	{
		NVideoInterlaceMode value;
		NCheck(NVideoFormatGetInterlaceMode(GetHandle(), &value));
		return value;
	}

	void SetInterlaceMode(NVideoInterlaceMode value)
	{
		NCheck(NVideoFormatSetInterlaceMode(GetHandle(), value));
	}

	NURational GetPixelAspectRatio() const
	{
		NURational value;
		NCheck(NVideoFormatGetPixelAspectRatio(GetHandle(), &value));
		return value;
	}

	void SetPixelAspectRatio(const NURational & value)
	{
		NCheck(NVideoFormatSetPixelAspectRatio(GetHandle(), &value));
	}
};

}}

#endif // !N_VIDEO_FORMAT_HPP_INCLUDED
