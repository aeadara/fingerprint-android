#ifndef PNG_H_INCLUDED
#define PNG_H_INCLUDED

#include <Images/NImage.h>

#ifdef N_CPP
extern "C"
{
#endif

#define PNG_DEFAULT_COMPRESSION_LEVEL 6

N_DECLARE_OBJECT_TYPE(PngInfo, NImageInfo)

NResult N_API PngInfoGetCompressionLevel(HPngInfo hInfo, NInt * pValue);
NResult N_API PngInfoSetCompressionLevel(HPngInfo hInfo, NInt value);

#ifdef N_CPP
}
#endif

#endif // !PNG_H_INCLUDED
