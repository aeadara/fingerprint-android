#ifndef N_PIXEL_FORMAT_H_INCLUDED
#define N_PIXEL_FORMAT_H_INCLUDED

#include <Media/NSampleFormat.h>

#ifdef N_CPP
extern "C"
{
#endif

typedef enum NPixelType_
{
	nptUndefined = 0,
	nptGrayscale = 1,
	nptRgb = 3,
} NPixelType;

N_DECLARE_TYPE(NPixelType)

NBool N_API NPixelTypeIsValid(NPixelType value);
NBool N_API NPixelTypeCanBeIndexed(NPixelType pixelType);

typedef NSampleFormat_ NPixelFormat_;
#ifndef N_PIXEL_FORMAT_HPP_INCLUDED
typedef NPixelFormat_ NPixelFormat;
#endif
N_DECLARE_TYPE(NPixelFormat)

#define NPF_UNDEFINED          0

#define NPF_GRAYSCALE_1U       0x00001001
#define NPF_GRAYSCALE_2U       0x00101001
#define NPF_GRAYSCALE_4U       0x00201001
#define NPF_GRAYSCALE_8U       0x00301001
#define NPF_GRAYSCALE_8S       0x00311001
#define NPF_GRAYSCALE_A_8U     0x00302101
#define NPF_GRAYSCALE_A_8S     0x00312101
#define NPF_GRAYSCALE_PA_8U    0x00302201
#define NPF_GRAYSCALE_PA_8S    0x00312201
#define NPF_GRAYSCALE_16U      0x00401001
#define NPF_GRAYSCALE_16S      0x00411001
#define NPF_GRAYSCALE_A_16U    0x00402101
#define NPF_GRAYSCALE_A_16S    0x00412101
#define NPF_GRAYSCALE_PA_16U   0x00402201
#define NPF_GRAYSCALE_PA_16S   0x00412201
#define NPF_GRAYSCALE_32U      0x00501001
#define NPF_GRAYSCALE_32S      0x00511001
#define NPF_GRAYSCALE_A_32U    0x00502101
#define NPF_GRAYSCALE_A_32S    0x00512101
#define NPF_GRAYSCALE_PA_32U   0x00502201
#define NPF_GRAYSCALE_PA_32S   0x00512201
#define NPF_GRAYSCALE_64U      0x00601001
#define NPF_GRAYSCALE_64S      0x00611001
#define NPF_GRAYSCALE_A_64U    0x00602101
#define NPF_GRAYSCALE_A_64S    0x00612101
#define NPF_GRAYSCALE_PA_64U   0x00602201
#define NPF_GRAYSCALE_PA_64S   0x00612201
#define NPF_GRAYSCALE_32F      0x00521001
#define NPF_GRAYSCALE_A_32F    0x00522101
#define NPF_GRAYSCALE_PA_32F   0x00522201
#define NPF_GRAYSCALE_64F      0x00621001
#define NPF_GRAYSCALE_A_64F    0x00622101
#define NPF_GRAYSCALE_PA_64F   0x00622201

#define NPF_RGB_8U             0x00303003
#define NPF_RGB_8S             0x00313003
#define NPF_RGB_A_8U           0x00304103
#define NPF_RGB_A_8S           0x00314103
#define NPF_RGB_PA_8U          0x00304203
#define NPF_RGB_PA_8S          0x00314203
#define NPF_RGB_16U            0x00403003
#define NPF_RGB_16S            0x00413003
#define NPF_RGB_A_16U          0x00404103
#define NPF_RGB_A_16S          0x00414103
#define NPF_RGB_PA_16U         0x00404203
#define NPF_RGB_PA_16S         0x00414203
#define NPF_RGB_32U            0x00503003
#define NPF_RGB_32S            0x00513003
#define NPF_RGB_A_32U          0x00504103
#define NPF_RGB_A_32S          0x00514103
#define NPF_RGB_PA_32U         0x00504203
#define NPF_RGB_PA_32S         0x00514203
#define NPF_RGB_64U            0x00603003
#define NPF_RGB_64S            0x00613003
#define NPF_RGB_A_64U          0x00604103
#define NPF_RGB_A_64S          0x00614103
#define NPF_RGB_PA_64U         0x00604203
#define NPF_RGB_PA_64S         0x00614203
#define NPF_RGB_32F            0x00523003
#define NPF_RGB_A_32F          0x00524103
#define NPF_RGB_PA_32F         0x00524203
#define NPF_RGB_64F            0x00623003
#define NPF_RGB_A_64F          0x00624103
#define NPF_RGB_PA_64F         0x00624203
#define NPF_RGB_8U_INDEXED_1   0x01303003
#define NPF_RGB_8U_INDEXED_2   0x02303003
#define NPF_RGB_8U_INDEXED_4   0x03303003
#define NPF_RGB_8U_INDEXED_8   0x04303003
#define NPF_RGB_A_8U_INDEXED_1 0x01304103
#define NPF_RGB_A_8U_INDEXED_2 0x02304103
#define NPF_RGB_A_8U_INDEXED_4 0x03304103
#define NPF_RGB_A_8U_INDEXED_8 0x04304103

NResult N_API NPixelFormatCalcRowSize(NInt bitsPerPixel, NUInt length, NSizeType alignment, NSizeType * pValue);

NResult N_API NPixelFormatCreate(NPixelType pixelType, NExtraChannel extraChannel, NInt channelCount, NChannelFormat channelFormat, NInt bitsPerChannel, NInt bitsPerIndex, NBool isSeparated, NPixelFormat_ * pValue);

NBool N_API NPixelFormatIsValid(NPixelFormat_ value);
NResult N_API NPixelFormatGetIndexed(NPixelFormat_ pixelFormat, NInt bitsPerIndex, NPixelFormat_ * pValue);
NResult N_API NPixelFormatGetNonIndexed(NPixelFormat_ pixelFormat, NPixelFormat_ * pValue);
NResult N_API NPixelFormatGetSeparated(NPixelFormat_ pixelFormat, NPixelFormat_ * pValue);
NResult N_API NPixelFormatGetNonSeparated(NPixelFormat_ pixelFormat, NPixelFormat_ * pValue);
NResult N_API NPixelFormatGetWithExtraChannel(NPixelFormat_ pixelFormat, NExtraChannel extraChannel, NPixelFormat_ * pValue);
NResult N_API NPixelFormatGetRowSize(NPixelFormat_ pixelFormat, NUInt length, NSizeType alignment, NSizeType * pValue);
NResult N_API NPixelFormatGetPaletteSize(NPixelFormat_ pixelFormat, NInt length, NSizeType * pValue);

NResult N_API NPixelFormatToStringN(NPixelFormat_ pixelFormat, HNString hFormat, HNString * phValue);
NResult N_API NPixelFormatToStringA(NPixelFormat_ pixelFormat, const NAChar * szFormat, HNString * phValue);
#ifndef N_NO_UNICODE
NResult N_API NPixelFormatToStringW(NPixelFormat_ pixelFormat, const NWChar * szFormat, HNString * phValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NPixelFormatToString(NPixelFormat pixelFormat, const NChar * szFormat, HNString * phValue);
#endif
#define NPixelFormatToString N_FUNC_AW(NPixelFormatToString)

NPixelType N_API NPixelFormatGetPixelType(NPixelFormat_ pixelFormat);
NInt N_API NPixelFormatGetBitsPerPixel(NPixelFormat_ pixelFormat);
NSizeType N_API NPixelFormatGetBytesPerPixel(NPixelFormat_ pixelFormat);

#ifndef N_PIXEL_FORMAT_HPP_INCLUDED

#endif

#ifdef N_CPP
}
#endif

#endif // !N_PIXEL_FORMAT_H_INCLUDED
