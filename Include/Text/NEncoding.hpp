#ifndef N_ENCODING_HPP_INCLUDED
#define N_ENCODING_HPP_INCLUDED

#include <Core/NTypes.hpp>
namespace Neurotec {
	namespace Text
{
#include <Text/NEncoding.h>
}}

N_DEFINE_ENUM_TYPE_TRAITS(Neurotec::Text, NEncoding)

namespace Neurotec { namespace Text
{

#undef N_ACHAR_ENCODING
#undef N_WCHAR_ENCODING
#undef N_CHAR_ENCODING

const NEncoding N_ACHAR_ENCODING = neDefault;

#if N_WCHAR_SIZE == 2
	#ifdef N_BIG_ENDIAN
		const NEncoding N_WCHAR_ENCODING = neUtf16BE;
	#else
		const NEncoding N_WCHAR_ENCODING = neUtf16LE;
	#endif
#else
	#ifdef N_BIG_ENDIAN
		const NEncoding N_WCHAR_ENCODING = neUtf32BE;
	#else
		const NEncoding N_WCHAR_ENCODING = neUtf32LE;
	#endif
#endif

#ifdef N_UNICODE
	const NEncoding N_CHAR_ENCODING = N_WCHAR_ENCODING;
#else
	const NEncoding N_CHAR_ENCODING = N_ACHAR_ENCODING;
#endif

class NEncodingEx
{
public:
	static NType NativeTypeOf()
	{
		return NObject::GetObject<NType>(N_TYPE_OF(NEncoding), true);
	}

	static bool IsValid(NEncoding value)
	{
		return NEncodingIsValid(value) != 0;
	}

	static bool Convert(NEncoding srcEncoding, const void * pSrcData, NSizeType srcDataSize, NBool srcIsBlock, NSizeType * pSrcDataUsed,
		NEncoding dstEncoding, void * pDstData, NSizeType dstDataSize, NBool dstIsBlock, NSizeType * pDstDataUsed)
	{
		NBool completed;
		NCheck(NEncodingConvert(srcEncoding, pSrcData, srcDataSize, srcIsBlock, pSrcDataUsed,
			dstEncoding, pDstData, dstDataSize, dstIsBlock, pDstDataUsed, &completed));
		return completed != 0;
	}

	static NSizeType GetPreambleLength(NEncoding encoding)
	{
		NSizeType value;
		NCheck(NEncodingGetPreambleLength(encoding, &value));
		return value;
	}

	static NSizeType GetPreamble(NEncoding encoding, void * pData, NSizeType dataSize)
	{
		NSizeType dataWritten;
		NCheck(NEncodingGetPreamble(encoding, pData, dataSize, &dataWritten));
		return dataWritten;
	}

	static bool IsSingleByte(NEncoding encoding)
	{
		NBool value;
		NCheck(NEncodingIsSingleByte(encoding, &value));
		return value != 0;
	}

	static NSizeType GetMinBytesPerChar(NEncoding encoding)
	{
		NSizeType value;
		NCheck(NEncodingGetMinBytesPerChar(encoding, &value));
		return value;
	}

	static NSizeType GetMaxByteCount(NEncoding encoding, NInt charCount)
	{
		NSizeType byteCount;
		NCheck(NEncodingGetMaxByteCount(encoding, charCount, &byteCount));
		return byteCount;
	}

	static NInt GetMaxCharCount(NEncoding encoding, NSizeType byteCount)
	{
		NInt charCount;
		NCheck(NEncodingGetMaxCharCount(encoding, byteCount, &charCount));
		return charCount;
	}

	static NString GetString(NEncoding encoding, const void * pData, NSizeType dataSize)
	{
		HNString hValue;
		NCheck(NEncodingGetStringN(encoding, pData, dataSize, &hValue));
		return NString(hValue, true);
	}

	static NInt GetChars(NEncoding encoding, const void * pData, NSizeType dataSize, NBool dataIsBlock, NSizeType * pDataUsed,
		NChar * arChars, NInt charsLength)
	{
		NInt charsUsed;
		NCheck(NEncodingGetChars(encoding, pData, dataSize, dataIsBlock, pDataUsed, arChars, charsLength, &charsUsed));
		return charsUsed;
	}

	static NSizeType GetBytes(NEncoding encoding, const NStringWrapper & value, void * pData, NSizeType dataSize)
	{
		NSizeType dataUsed;
		NCheck(NEncodingGetBytesN(encoding, value.GetHandle(), pData, dataSize, &dataUsed));
		return dataUsed;
	}

	static NSizeType GetBytes(NEncoding encoding, const NChar * szValue, void * pData, NSizeType dataSize)
	{
		NSizeType dataUsed;
		NCheck(NEncodingGetBytes(encoding, szValue, pData, dataSize, &dataUsed));
		return dataUsed;
	}

	static NSizeType GetBytes(NEncoding encoding, const NChar * arChars, NInt charsLength, NBool charsAreBlock, NInt * pCharsUsed, void * pData, NSizeType dataSize)
	{
		NSizeType dataUsed;
		NCheck(NEncodingGetBytesForChars(encoding, arChars, charsLength, charsAreBlock, pCharsUsed, pData, dataSize, &dataUsed));
		return dataUsed;
	}
};

}}

#endif // !N_ENCODING_HPP_INCLUDED
