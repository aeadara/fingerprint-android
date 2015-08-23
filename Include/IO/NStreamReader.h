#ifndef N_STREAM_READER_H_INCLUDED
#define N_STREAM_READER_H_INCLUDED

#include <IO/NTextReader.h>
#include <Text/NEncoding.h>

#ifdef N_CPP
extern "C"
{
#endif

N_DECLARE_OBJECT_TYPE(NStreamReader, NTextReader)

NResult N_API NStreamReaderGetNull(HNStreamReader * phValue);

NResult N_API NStreamReaderCreate(HNStream hStream, HNStreamReader * phReader);
NResult N_API NStreamReaderCreateWithEncoding(HNStream hStream, NEncoding encoding, NBool detectEncodingFromByteOrderMarks, HNStreamReader * phReader);
NResult N_API NStreamReaderCreateWithEncodingAndBufferSize(HNStream hStream, NEncoding encoding, NBool detectEncodingFromByteOrderMarks, NSizeType bufferSize, HNStreamReader * phReader);

NResult N_API NStreamReaderCreateFromFileN(HNString hPath, HNStreamReader * phReader);
#ifndef N_NO_ANSI_FUNC
NResult N_API NStreamReaderCreateFromFileA(const NAChar * szFileName, HNStreamReader * phReader);
#endif
#ifndef N_NO_UNICODE
NResult N_API NStreamReaderCreateFromFileW(const NWChar * szFileName, HNStreamReader * phReader);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NStreamReaderCreateFromFile(const NChar * szFileName, HNStreamReader * phReader);
#endif
#define NStreamReaderCreateFromFile N_FUNC_AW(NStreamReaderCreateFromFile)

NResult N_API NStreamReaderCreateFromFileWithEncodingN(HNString hPath, NEncoding encoding, NBool detectEncodingFromByteOrderMarks, HNStreamReader * phReader);
#ifndef N_NO_ANSI_FUNC
NResult N_API NStreamReaderCreateFromFileWithEncodingA(const NAChar * szFileName, NEncoding encoding, NBool detectEncodingFromByteOrderMarks, HNStreamReader * phReader);
#endif
#ifndef N_NO_UNICODE
NResult N_API NStreamReaderCreateFromFileWithEncodingW(const NWChar * szFileName, NEncoding encoding, NBool detectEncodingFromByteOrderMarks, HNStreamReader * phReader);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NStreamReaderCreateFromFileWithEncoding(const NChar * szFileName, NEncoding encoding, NBool detectEncodingFromByteOrderMarks, HNStreamReader * phReader);
#endif
#define NStreamReaderCreateFromFileWithEncoding N_FUNC_AW(NStreamReaderCreateFromFileWithEncoding)

NResult N_API NStreamReaderCreateFromFileWithEncodingAndBufferSizeN(HNString hPath, NEncoding encoding, NBool detectEncodingFromByteOrderMarks, NSizeType bufferSize, HNStreamReader * phReader);
#ifndef N_NO_ANSI_FUNC
NResult N_API NStreamReaderCreateFromFileWithEncodingAndBufferSizeA(const NAChar * szFileName, NEncoding encoding, NBool detectEncodingFromByteOrderMarks, NSizeType bufferSize, HNStreamReader * phReader);
#endif
#ifndef N_NO_UNICODE
NResult N_API NStreamReaderCreateFromFileWithEncodingAndBufferSizeW(const NWChar * szFileName, NEncoding encoding, NBool detectEncodingFromByteOrderMarks, NSizeType bufferSize, HNStreamReader * phReader);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NStreamReaderCreateFromFileWithEncodingAndBufferSize(const NChar * szFileName, NEncoding encoding, NBool detectEncodingFromByteOrderMarks, NSizeType bufferSize, HNStreamReader * phReader);
#endif
#define NStreamReaderCreateFromFileWithEncodingAndBufferSize N_FUNC_AW(NStreamReaderCreateFromFileWithEncodingAndBufferSize)

NResult N_API NStreamReaderGetCurrentEncoding(HNStreamReader hReader, NEncoding * pValue);
NResult N_API NStreamReaderGetBaseStream(HNStreamReader hReader, HNStream * phValue);
NResult N_API NStreamReaderIsEndOfStream(HNStreamReader hReader, NBool * pValue);

#ifdef N_CPP
}
#endif

#endif // !N_STREAM_READER_H_INCLUDED
