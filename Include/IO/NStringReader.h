#ifndef N_STRING_READER_H_INCLUDED
#define N_STRING_READER_H_INCLUDED

#include <IO/NTextReader.h>

#ifdef N_CPP
extern "C"
{
#endif

N_DECLARE_OBJECT_TYPE(NStringReader, NTextReader)

NResult N_API NStringReaderCreateN(HNString hValue, HNStringReader * phReader);
#ifndef N_NO_ANSI_FUNC
NResult N_API NStringReaderCreateFromStrOrCharsA(const NAChar * arValue, NInt valueLength, HNStringReader * phReader);
#endif
#ifndef N_NO_UNICODE
NResult N_API NStringReaderCreateFromStrOrCharsW(const NWChar * arValue, NInt valueLength, HNStringReader * phReader);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NStringReaderCreateFromStrOrChars(const NChar * arValue, NInt valueLength, HNStringReader * phReader);
#endif
#define NStringReaderCreateFromStrOrChars N_FUNC_AW(NStringReaderCreateFromStrOrChars)

#define NStringReaderCreateA(szValue, phReader) NStringReaderCreateFromStrOrCharsA(szValue, -1, phReader)
#define NStringReaderCreateW(szValue, phReader) NStringReaderCreateFromStrOrCharsW(szValue, -1, phReader)
#define NStringReaderCreate(szValue, phReader) NStringReaderCreateFromStrOrChars(szValue, -1, phReader)
#define NStringReaderCreateFromCharsA(arValue, valueLength, phReader) NStringReaderCreateFromStrOrCharsA(arValue, valueLength, phReader)
#define NStringReaderCreateFromCharsW(arValue, valueLength, phReader) NStringReaderCreateFromStrOrCharsA(arValue, valueLength, phReader)
#define NStringReaderCreateFromChars(arValue, valueLength, phReader) NStringReaderCreateFromStrOrChars(arValue, valueLength, phReader)

#ifdef N_CPP
}
#endif

#endif // !N_STRING_READER_H_INCLUDED
