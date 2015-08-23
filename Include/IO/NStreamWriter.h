#ifndef N_STREAM_WRITER_H_INCLUDED
#define N_STREAM_WRITER_H_INCLUDED

#include <IO/NTextWriter.h>

#ifdef N_CPP
extern "C"
{
#endif

N_DECLARE_OBJECT_TYPE(NStreamWriter, NTextWriter)

NResult N_API NStreamWriterGetNull(HNStreamWriter * phValue);

NResult N_API NStreamWriterCreate(HNStream hStream, HNStreamWriter * phWriter);
NResult N_API NStreamWriterCreateWithEncoding(HNStream hStream, NEncoding encoding, HNStreamWriter * phWriter);
NResult N_API NStreamWriterCreateWithEncodingAndBufferSize(HNStream hStream, NEncoding encoding, NSizeType bufferSize, HNStreamWriter * phWriter);

NResult N_API NStreamWriterCreateFromFileN(HNString hFileName, NBool append, HNStreamWriter * phWriter);
#ifndef N_NO_ANSI_FUNC
NResult N_API NStreamWriterCreateFromFileA(const NAChar * szFileName, NBool append, HNStreamWriter * phWriter);
#endif
#ifndef N_NO_UNICODE
NResult N_API NStreamWriterCreateFromFileW(const NWChar * szFileName, NBool append, HNStreamWriter * phWriter);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NStreamWriterCreateFromFile(const NChar * szFileName, NBool append, HNStreamWriter * phWriter);
#endif
#define NStreamWriterCreateFromFile N_FUNC_AW(NStreamWriterCreateFromFile)

NResult N_API NStreamWriterCreateFromFileWithEncodingN(HNString hFileName, NBool append, NEncoding encoding, HNStreamWriter * phWriter);
#ifndef N_NO_ANSI_FUNC
NResult N_API NStreamWriterCreateFromFileWithEncodingA(const NAChar * szFileName, NBool append, NEncoding encoding, HNStreamWriter * phWriter);
#endif
#ifndef N_NO_UNICODE
NResult N_API NStreamWriterCreateFromFileWithEncodingW(const NWChar * szFileName, NBool append, NEncoding encoding, HNStreamWriter * phWriter);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NStreamWriterCreateFromFileWithEncoding(const NChar * szFileName, NBool append, NEncoding encoding, HNStreamWriter * phWriter);
#endif
#define NStreamWriterCreateFromFileWithEncoding N_FUNC_AW(NStreamWriterCreateFromFileWithEncoding)

NResult N_API NStreamWriterCreateFromFileWithEncodingAndBufferSizeN(HNString hFileName, NBool append, NEncoding encoding, NSizeType bufferSize, HNStreamWriter * phWriter);
#ifndef N_NO_ANSI_FUNC
NResult N_API NStreamWriterCreateFromFileWithEncodingAndBufferSizeA(const NAChar * szFileName, NBool append, NEncoding encoding, NSizeType bufferSize, HNStreamWriter * phWriter);
#endif
#ifndef N_NO_UNICODE
NResult N_API NStreamWriterCreateFromFileWithEncodingAndBufferSizeW(const NWChar * szFileName, NBool append, NEncoding encoding, NSizeType bufferSize, HNStreamWriter * phWriter);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NStreamWriterCreateFromFileWithEncodingAndBufferSize(const NChar * szFileName, NBool append, NEncoding encoding, NSizeType bufferSize, HNStreamWriter * phWriter);
#endif
#define NStreamWriterCreateFromFileWithEncodingAndBufferSize N_FUNC_AW(NStreamWriterCreateFromFileWithEncodingAndBufferSize)

NResult N_API NStreamWriterGetBaseStream(HNStreamWriter hWriter, HNStream * phValue);
NResult N_API NStreamWriterGetAutoFlush(HNStreamWriter hWriter, NBool * pValue);
NResult N_API NStreamWriterSetAutoFlush(HNStreamWriter hWriter, NBool value);

#ifdef N_CPP
}
#endif

#endif // !N_STREAM_WRITER_H_INCLUDED
