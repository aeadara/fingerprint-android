#ifndef AN_IMAGE_H_INCLUDED
#define AN_IMAGE_H_INCLUDED

#include <Images/NImage.h>

#ifdef N_CPP
extern "C"
{
#endif

typedef enum ANImageCompressionAlgorithm_
{
	anicaNone = 0,
	anicaWsq20 = 1,
	anicaJpegB = 2,
	anicaJpegL = 3,
	anicaJP2 = 4,
	anicaJP2L = 5,
	anicaPng = 6,
	anicaVendor = 255
} ANImageCompressionAlgorithm;

N_DECLARE_TYPE(ANImageCompressionAlgorithm)

typedef enum ANBinaryImageCompressionAlgorithm_
{
	anbicaNone = 0,
	anbicaFacsimile = 1,
	anbicaVendor = 255
} ANBinaryImageCompressionAlgorithm;

N_DECLARE_TYPE(ANBinaryImageCompressionAlgorithm)

typedef enum ANImageColorSpace_
{
	anicsUnspecified = 0,
	anicsGray = 1,
	anicsRgb = 2,
	anicsSRgb = 3,
	anicsYcc = 4,
	anicsSYcc = 5,
	anicsUnknown = 255
} ANImageColorSpace;

N_DECLARE_TYPE(ANImageColorSpace)

N_DECLARE_STATIC_OBJECT_TYPE(ANImage)

#ifdef N_CPP
}
#endif

#endif // !AN_IMAGE_H_INCLUDED
