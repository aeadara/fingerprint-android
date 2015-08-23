#ifndef N_BINARY_WRITER_H_INCLUDED
#define N_BINARY_WRITER_H_INCLUDED

#include <IO/NIOTypes.h>
#include <Text/NEncoding.h>

#ifdef N_CPP
extern "C"
{
#endif

N_DECLARE_OBJECT_TYPE(NBinaryWriter, NObject)

NResult N_API NBinaryWriterGetNull(HNBinaryWriter * phValue);

NResult N_API NBinaryWriterCreate(HNStream hStream, NByteOrder byteOrder, HNBinaryWriter * phWriter);
NResult N_API NBinaryWriterCreateWithEncoding(HNStream hStream, NByteOrder byteOrder, NEncoding encoding, HNBinaryWriter * phWriter);

NResult N_API NBinaryWriterFlush(HNBinaryWriter hWriter);
NResult N_API NBinaryWriterSeek(HNBinaryWriter hWriter, NLong offset, NSeekOrigin origin);
NResult N_API NBinaryWriterWriteByte(HNBinaryWriter hWriter, NByte value);
NResult N_API NBinaryWriterWriteSByte(HNBinaryWriter hWriter, NSByte value);
NResult N_API NBinaryWriterWriteUInt16(HNBinaryWriter hWriter, NUInt16 value);
NResult N_API NBinaryWriterWriteInt16(HNBinaryWriter hWriter, NInt16 value);
NResult N_API NBinaryWriterWriteUInt32(HNBinaryWriter hWriter, NUInt32 value);
NResult N_API NBinaryWriterWriteInt32(HNBinaryWriter hWriter, NInt32 value);
#ifndef N_NO_INT_64
NResult N_API NBinaryWriterWriteUInt64(HNBinaryWriter hWriter, NUInt64 value);
NResult N_API NBinaryWriterWriteInt64(HNBinaryWriter hWriter, NInt64 value);
#endif
#ifndef N_NO_FLOAT
NResult N_API NBinaryWriterWriteSingle(HNBinaryWriter hWriter, NSingle value);
NResult N_API NBinaryWriterWriteDouble(HNBinaryWriter hWriter, NDouble value);
#endif
NResult N_API NBinaryWriterWriteBoolean(HNBinaryWriter hWriter, NBoolean value);
NResult N_API NBinaryWriterWriteBytes(HNBinaryWriter hWriter, const void * pBuffer, NSizeType bufferSize);
NResult N_API NBinaryWriterWriteBytesN(HNBinaryWriter hWriter, HNBuffer hBuffer);

#ifndef N_NO_ANSI_FUNC
NResult N_API NBinaryWriterWriteCharA(HNBinaryWriter hWriter, NAChar value);
#endif
#ifndef N_NO_UNICODE
NResult N_API NBinaryWriterWriteCharW(HNBinaryWriter hWriter, NWChar value);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NBinaryWriterWriteChar(HNBinaryWriter hWriter, NChar value);
#endif
#define NBinaryWriterWriteChar N_FUNC_AW(NBinaryWriterWriteChar)

#ifndef N_NO_ANSI_FUNC
NResult N_API NBinaryWriterWriteCharsA(HNBinaryWriter hWriter, const NAChar * arChars, NInt count);
#endif
#ifndef N_NO_UNICODE
NResult N_API NBinaryWriterWriteCharsW(HNBinaryWriter hWriter, const NWChar * arChars, NInt count);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NBinaryWriterWriteChars(HNBinaryWriter hWriter, const NChar * arChars, NInt count);
#endif
#define NBinaryWriterWriteChars N_FUNC_AW(NBinaryWriterWriteChars)

NResult N_API NBinaryWriterGetBaseStream(HNBinaryWriter hWriter, HNStream * phValue);
NResult N_API NBinaryWriterGetByteOrder(HNBinaryWriter hWriter, NByteOrder * pValue);
NResult N_API NBinaryWriterGetPosition(HNBinaryWriter hWriter, NLong * pValue);
NResult N_API NBinaryWriterSetPosition(HNBinaryWriter hWriter, NLong value);

#ifdef N_CPP
}
#endif

#endif // !N_BINARY_WRITER_H_INCLUDED
