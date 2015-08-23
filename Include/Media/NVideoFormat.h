#ifndef N_VIDEO_FORMAT_H_INCLUDED
#define N_VIDEO_FORMAT_H_INCLUDED

#include <Media/NMediaFormat.h>

#ifdef N_CPP
extern "C"
{
#endif

#define N_VIDEO_FORMAT_UNKNOWN          0
#define N_VIDEO_FORMAT_RGB24           20
#define N_VIDEO_FORMAT_ARGB32          21
#define N_VIDEO_FORMAT_RGB32           22
#define N_VIDEO_FORMAT_RGB555          24
#define N_VIDEO_FORMAT_RGB565          23
#define N_VIDEO_FORMAT_RGB8            41
#define N_VIDEO_FORMAT_L8              50
#define N_VIDEO_FORMAT_L16             81
#define N_VIDEO_FORMAT_AI44    0x34344941
#define N_VIDEO_FORMAT_AYUV    0x56555941
#define N_VIDEO_FORMAT_YUY2    0x32595559
#define N_VIDEO_FORMAT_YVYU    0x55595659
#define N_VIDEO_FORMAT_YVU9    0x39555659
#define N_VIDEO_FORMAT_UYVY    0x59565955
#define N_VIDEO_FORMAT_NV11    0x3131564E
#define N_VIDEO_FORMAT_NV12    0x3231564E
#define N_VIDEO_FORMAT_NV21    0x3132564E
#define N_VIDEO_FORMAT_YV12    0x32315659
#define N_VIDEO_FORMAT_I420    0x30323449
#define N_VIDEO_FORMAT_IYUV    0x56555949
#define N_VIDEO_FORMAT_Y210    0x30313259
#define N_VIDEO_FORMAT_Y216    0x36313259
#define N_VIDEO_FORMAT_Y410    0x30313459
#define N_VIDEO_FORMAT_Y416    0x36313459
#define N_VIDEO_FORMAT_Y41P    0x50313459
#define N_VIDEO_FORMAT_Y41T    0x54313459
#define N_VIDEO_FORMAT_Y42T    0x54323459
#define N_VIDEO_FORMAT_P210    0x30313250
#define N_VIDEO_FORMAT_P216    0x36313250
#define N_VIDEO_FORMAT_P010    0x30313050
#define N_VIDEO_FORMAT_P016    0x36313050
#define N_VIDEO_FORMAT_V210    0x30313276
#define N_VIDEO_FORMAT_V216    0x36313276
#define N_VIDEO_FORMAT_V410    0x30313476
#define N_VIDEO_FORMAT_MP43    0x3334504D
#define N_VIDEO_FORMAT_MP4S    0x5334504D
#define N_VIDEO_FORMAT_M4S2    0x3253344D
#define N_VIDEO_FORMAT_MP4V    0x5634504D
#define N_VIDEO_FORMAT_WMV1    0x31564D57
#define N_VIDEO_FORMAT_WMV2    0x32564D57
#define N_VIDEO_FORMAT_WMV3    0x33564D57
#define N_VIDEO_FORMAT_WVC1    0x31435657
#define N_VIDEO_FORMAT_MSS1    0x3153534D
#define N_VIDEO_FORMAT_MSS2    0x3253534D
#define N_VIDEO_FORMAT_MPG1    0x3147504D
#define N_VIDEO_FORMAT_DVSL    0x6C737664
#define N_VIDEO_FORMAT_DVSD    0x64737664
#define N_VIDEO_FORMAT_DVHD    0x64687664
#define N_VIDEO_FORMAT_DV25    0x35327664
#define N_VIDEO_FORMAT_DV50    0x30357664
#define N_VIDEO_FORMAT_DVH1    0x31687664
#define N_VIDEO_FORMAT_DVC     0x20637664
#define N_VIDEO_FORMAT_H264    0x34363248
#define N_VIDEO_FORMAT_MJPG    0x47504A4D
#define N_VIDEO_FORMAT_DX50    0x30355844
#define N_VIDEO_FORMAT_AVC1    0x31435641

NResult N_API NVideoFormatMediaSubtypeToStringN(NUInt value, HNString hFormat, HNString * phValue);
NResult N_API NVideoFormatMediaSubtypeToStringA(NUInt value, const NAChar * szFormat, HNString * phValue);
#ifndef N_NO_UNICODE
NResult N_API NVideoFormatMediaSubtypeToStringW(NUInt value, const NWChar * szFormat, HNString * phValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NVideoFormatMediaSubtypeToString(NUInt value, const NChar * szFormat, HNString * phValue);
#endif
#define NVideoFormatMediaSubtypeToString N_FUNC_AW(NVideoFormatMediaSubtypeToString)

N_DECLARE_OBJECT_TYPE(NVideoFormat, NMediaFormat)

NResult N_API NVideoFormatCreate(HNVideoFormat * phVideoFormat);

NResult N_API NVideoFormatGetWidth(HNVideoFormat hVideoFormat, NUInt * pValue);
NResult N_API NVideoFormatSetWidth(HNVideoFormat hVideoFormat, NUInt value);
NResult N_API NVideoFormatGetHeight(HNVideoFormat hVideoFormat, NUInt * pValue);
NResult N_API NVideoFormatSetHeight(HNVideoFormat hVideoFormat, NUInt value);
NResult N_API NVideoFormatGetStride(HNVideoFormat hVideoFormat, NSSizeType * pValue);
NResult N_API NVideoFormatSetStride(HNVideoFormat hVideoFormat, NSSizeType value);
NResult N_API NVideoFormatGetFrameRate(HNVideoFormat hVideoFormat, struct NURational_ * pValue);
NResult N_API NVideoFormatSetFrameRate(HNVideoFormat hVideoFormat, const struct NURational_ * pValue);
NResult N_API NVideoFormatGetInterlaceMode(HNVideoFormat hVideoFormat, NVideoInterlaceMode * pValue);
NResult N_API NVideoFormatSetInterlaceMode(HNVideoFormat hVideoFormat, NVideoInterlaceMode value);
NResult N_API NVideoFormatGetPixelAspectRatio(HNVideoFormat hVideoFormat, struct NURational_ * pValue);
NResult N_API NVideoFormatSetPixelAspectRatio(HNVideoFormat hVideoFormat, const struct NURational_ * pValue);

#ifdef N_CPP
}
#endif

#endif // !N_VIDEO_FORMAT_H_INCLUDED
