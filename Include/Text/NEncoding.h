#ifndef N_ENCODING_H_INCLUDED
#define N_ENCODING_H_INCLUDED

#include <Core/NTypes.h>

#ifdef N_CPP
extern "C"
{
#endif

typedef enum NEncoding_
{
	neDefault = 0,
	neUtf8 = 1,
	neAscii = 2,
	neUtf7 = 3,
	neUtf16BE = 4,
	neUtf16LE = 5,
	neUtf32BE = 6,
	neUtf32LE = 7
} NEncoding;

N_DECLARE_TYPE(NEncoding)

#define N_ACHAR_ENCODING neDefault

#if N_WCHAR_SIZE == 2
	#ifdef N_BIG_ENDIAN
		#define N_WCHAR_ENCODING neUtf16BE
	#else
		#define N_WCHAR_ENCODING neUtf16LE
	#endif
#else
	#ifdef N_BIG_ENDIAN
		#define N_WCHAR_ENCODING neUtf32BE
	#else
		#define N_WCHAR_ENCODING neUtf32LE
	#endif
#endif

#ifdef N_UNICODE
	#define N_CHAR_ENCODING N_WCHAR_ENCODING
#else
	#define N_CHAR_ENCODING N_ACHAR_ENCODING
#endif

NBool N_API NEncodingIsValid(NEncoding value);

NResult N_API NEncodingConvert(NEncoding srcEncoding, const void * pSrcData, NSizeType srcDataSize, NBool srcIsBlock, NSizeType * pSrcDataUsed,
	NEncoding dstEncoding, void * pDstData, NSizeType dstDataSize, NBool dstIsBlock, NSizeType * pDstDataUsed, NBool * pCompleted);
NResult N_API NEncodingDetect(const void * pData, NSizeType dataSize, NSizeType * pPreambleLength, NEncoding * pEncoding);

NResult N_API NEncodingGetPreambleLength(NEncoding encoding, NSizeType * pValue);
NResult N_API NEncodingGetPreamble(NEncoding encoding, void * pData, NSizeType dataSize, NSizeType * pDataWritten);
NResult N_API NEncodingIsSingleByte(NEncoding encoding, NBool * pValue);
NResult N_API NEncodingGetMinBytesPerChar(NEncoding encoding, NSizeType * pValue);

NResult N_API NEncodingGetMaxByteCountA(NEncoding encoding, NInt charCount, NSizeType * pByteCount);
#ifndef N_NO_UNICODE
NResult N_API NEncodingGetMaxByteCountW(NEncoding encoding, NInt charCount, NSizeType * pByteCount);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NEncodingGetMaxByteCount(NEncoding encoding, NInt charCount, NSizeType * pByteCount);
#endif
#define NEncodingGetMaxByteCount N_FUNC_AW(NEncodingGetMaxByteCount)

NResult N_API NEncodingGetMaxCharCountA(NEncoding encoding, NSizeType byteCount, NInt * pCharCount);
#ifndef N_NO_UNICODE
NResult N_API NEncodingGetMaxCharCountW(NEncoding encoding, NSizeType byteCount, NInt * pCharCount);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NEncodingGetMaxCharCount(NEncoding encoding, NSizeType byteCount, NInt * pCharCount);
#endif
#define NEncodingGetMaxCharCount N_FUNC_AW(NEncodingGetMaxCharCount)

NResult N_API NEncodingGetStringN(NEncoding encoding, const void * pData, NSizeType dataSize, HNString * phValue);

NResult N_API NEncodingGetCharsA(NEncoding encoding, const void * pData, NSizeType dataSize, NBool dataIsBlock, NSizeType * pDataUsed,
	NAChar * arChars, NInt charsLength, NInt * pCharsUsed);
#ifndef N_NO_UNICODE
NResult N_API NEncodingGetCharsW(NEncoding encoding, const void * pData, NSizeType dataSize, NBool dataIsBlock, NSizeType * pDataUsed,
	NWChar * arChars, NInt charsLength, NInt * pCharsUsed);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NEncodingGetChars(NEncoding encoding, const void * pData, NSizeType dataSize, NBool dataIsBlock, NSizeType * pDataUsed,
	NChar * arChars, NInt charsLength, NInt * pCharsUsed);
#endif
#define NEncodingGetChars N_FUNC_AW(NEncodingGetChars)

NResult N_API NEncodingGetBytesN(NEncoding encoding, HNString hValue, void * pData, NSizeType dataSize, NSizeType * pDataUsed);

NResult N_API NEncodingGetBytesA(NEncoding encoding, const NAChar * szValue, void * pData, NSizeType dataSize, NSizeType * pDataUsed);
#ifndef N_NO_UNICODE
NResult N_API NEncodingGetBytesW(NEncoding encoding, const NWChar * szValue, void * pData, NSizeType dataSize, NSizeType * pDataUsed);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NEncodingGetBytes(NEncoding encoding, const NChar * szValue, void * pData, NSizeType dataSize, NSizeType * pDataUsed);
#endif
#define NEncodingGetBytes N_FUNC_AW(NEncodingGetBytes)

NResult N_API NEncodingGetBytesForCharsA(NEncoding encoding, const NAChar * arChars, NInt charsLength, NBool charsAreBlock, NInt * pCharsUsed,
	void * pData, NSizeType dataSize, NSizeType * pDataUsed);
#ifndef N_NO_UNICODE
NResult N_API NEncodingGetBytesForCharsW(NEncoding encoding, const NWChar * arChars, NInt charsLength, NBool charsAreBlock, NInt * pCharsUsed,
	void * pData, NSizeType dataSize, NSizeType * pDataUsed);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NEncodingGetBytesForChars(NEncoding encoding, const NChar * arChars, NInt charsLength, NBool charsAreBlock, NInt * pCharsUsed,
	void * pData, NSizeType dataSize, NSizeType * pDataUsed);
#endif
#define NEncodingGetBytesForChars N_FUNC_AW(NEncodingGetBytesForChars)

#ifdef N_CPP
}
#endif

#endif // !N_ENCODING_H_INCLUDED
