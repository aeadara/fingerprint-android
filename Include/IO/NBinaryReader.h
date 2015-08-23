#ifndef N_BINARY_READER_H_INCLUDED
#define N_BINARY_READER_H_INCLUDED

#include <IO/NIOTypes.h>
#include <Text/NEncoding.h>

#ifdef N_CPP
extern "C"
{
#endif

N_DECLARE_OBJECT_TYPE(NBinaryReader, NObject)

NResult N_API NBinaryReaderGetNull(HNBinaryReader * phValue);

NResult N_API NBinaryReaderCreate(HNStream hStream, NByteOrder byteOrder, HNBinaryReader * phReader);
NResult N_API NBinaryReaderCreateWithEncoding(HNStream hStream, NByteOrder byteOrder, NEncoding encoding, HNBinaryReader * phReader);

NResult N_API NBinaryReaderSeek(HNBinaryReader hReader, NLong offset, NSeekOrigin origin);

#ifndef N_NO_ANSI_FUNC
NResult N_API NBinaryReaderReadA(HNBinaryReader hReader, NInt * pValue);
#endif
#ifndef N_NO_UNICODE
NResult N_API NBinaryReaderReadW(HNBinaryReader hReader, NInt * pValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NBinaryReaderRead(HNBinaryReader hReader, NInt * pValue);
#endif
#define NBinaryReaderRead N_FUNC_AW(NBinaryReaderRead)

NResult N_API NBinaryReaderReadByte(HNBinaryReader hReader, NByte * pValue);
NResult N_API NBinaryReaderReadSByte(HNBinaryReader hReader, NSByte * pValue);
NResult N_API NBinaryReaderReadUInt16(HNBinaryReader hReader, NUInt16 * pValue);
NResult N_API NBinaryReaderReadInt16(HNBinaryReader hReader, NInt16 * pValue);
NResult N_API NBinaryReaderReadUInt32(HNBinaryReader hReader, NUInt32 * pValue);
NResult N_API NBinaryReaderReadInt32(HNBinaryReader hReader, NInt32 * pValue);
#ifndef N_NO_INT_64
NResult N_API NBinaryReaderReadUInt64(HNBinaryReader hReader, NUInt64 * pValue);
NResult N_API NBinaryReaderReadInt64(HNBinaryReader hReader, NInt64 * pValue);
#endif
#ifndef N_NO_FLOAT
NResult N_API NBinaryReaderReadSingle(HNBinaryReader hReader, NSingle * pValue);
NResult N_API NBinaryReaderReadDouble(HNBinaryReader hReader, NDouble * pValue);
#endif
NResult N_API NBinaryReaderReadBoolean(HNBinaryReader hReader, NBoolean * pValue);

#ifndef N_NO_ANSI_FUNC
NResult N_API NBinaryReaderPeekCharA(HNBinaryReader hReader, NInt * pValue);
#endif
#ifndef N_NO_UNICODE
NResult N_API NBinaryReaderPeekCharW(HNBinaryReader hReader, NInt * pValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NBinaryReaderPeekChar(HNBinaryReader hReader, NInt * pValue);
#endif
#define NBinaryReaderPeekChar N_FUNC_AW(NBinaryReaderPeekChar)

#ifndef N_NO_ANSI_FUNC
NResult N_API NBinaryReaderReadCharA(HNBinaryReader hReader, NAChar * pValue);
#endif
#ifndef N_NO_UNICODE
NResult N_API NBinaryReaderReadCharW(HNBinaryReader hReader, NWChar * pValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NBinaryReaderReadChar(HNBinaryReader hReader, NChar * pValue);
#endif
#define NBinaryReaderReadChar N_FUNC_AW(NBinaryReaderReadChar)

NResult N_API NBinaryReaderReadBytesDst(HNBinaryReader hReader, void * pBuffer, NSizeType bufferSize, NBool readAll, NSizeType * pSizeRead);
NResult N_API NBinaryReaderReadBytesDstN(HNBinaryReader hReader, HNBuffer hBuffer, NBool readAll, NSizeType * pSizeRead);
NResult N_API NBinaryReaderReadBytesN(HNBinaryReader hReader, NSizeType size, NBool readAll, HNBuffer * phBuffer);

#ifndef N_NO_ANSI_FUNC
NResult N_API NBinaryReaderReadCharsDstA(HNBinaryReader hReader, NAChar * arChars, NInt count, NBool readAll, NInt * pCountRead);
#endif
#ifndef N_NO_UNICODE
NResult N_API NBinaryReaderReadCharsDstW(HNBinaryReader hReader, NWChar * arChars, NInt count, NBool readAll, NInt * pCountRead);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NBinaryReaderReadCharsDst(HNBinaryReader hReader, NChar * arChars, NInt count, NBool readAll, NInt * pCountRead);
#endif
#define NBinaryReaderReadCharsDst N_FUNC_AW(NBinaryReaderReadCharsDst)

#ifndef N_NO_ANSI_FUNC
NResult N_API NBinaryReaderReadCharsA(HNBinaryReader hReader, NInt count, NBool readAll, NInt * pCharCount, NAChar * * parChars);
#endif
#ifndef N_NO_UNICODE
NResult N_API NBinaryReaderReadCharsW(HNBinaryReader hReader, NInt count, NBool readAll, NInt * pCharCount, NWChar * * parChars);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NBinaryReaderReadChars(HNBinaryReader hReader, NInt count, NBool readAll, NInt * pCharCount, NChar * * parChars);
#endif
#define NBinaryReaderReadChars N_FUNC_AW(NBinaryReaderReadChars)

NResult N_API NBinaryReaderGetBaseStream(HNBinaryReader hReader, HNStream * phValue);
NResult N_API NBinaryReaderGetByteOrder(HNBinaryReader hReader, NByteOrder * pValue);
NResult N_API NBinaryReaderGetPosition(HNBinaryReader hReader, NLong * pValue);
NResult N_API NBinaryReaderSetPosition(HNBinaryReader hReader, NLong value);

#ifdef N_CPP
}
#endif

#endif // !N_BINARY_READER_H_INCLUDED
