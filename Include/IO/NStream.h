#ifndef N_STREAM_H_INCLUDED
#define N_STREAM_H_INCLUDED

#include <Core/NObject.h>
#include <IO/NBuffer.h>
#include <IO/NIOTypes.h>

#ifdef N_CPP
extern "C"
{
#endif

NResult N_API NStreamSynchronized(HNStream hStream, HNStream * phValue);

NResult N_API NStreamGetNull(HNStream * phValue);

NResult N_API NStreamCopyTo(HNStream hStream, HNStream hDstStream);
NResult N_API NStreamCopyToWithBufferSize(HNStream hStream, HNStream hDstStream, NSizeType bufferSize);
NResult N_API NStreamFlush(HNStream hStream);
NResult N_API NStreamSetLength(HNStream hStream, NLong value);
NResult N_API NStreamSeek(HNStream hStream, NLong offset, NSeekOrigin origin);
NResult N_API NStreamReadByte(HNStream hStream, NInt * pValue);
NResult N_API NStreamRead(HNStream hStream, void * pBuffer, NSizeType bufferSize, NSizeType * pSizeRead);
NResult N_API NStreamReadN(HNStream hStream, HNBuffer hBuffer, NSizeType * pSizeRead);
NResult N_API NStreamWriteByte(HNStream hStream, NByte value);
NResult N_API NStreamWrite(HNStream hStream, const void * pBuffer, NSizeType bufferSize);
NResult N_API NStreamWriteN(HNStream hStream, HNBuffer hBuffer);

NResult N_API NStreamCanRead(HNStream hStream, NBool * pValue);
NResult N_API NStreamCanWrite(HNStream hStream, NBool * pValue);
NResult N_API NStreamCanSeek(HNStream hStream, NBool * pValue);
NResult N_API NStreamGetLength(HNStream hStream, NLong * pValue);
NResult N_API NStreamGetPosition(HNStream hStream, NLong * pValue);
NResult N_API NStreamSetPosition(HNStream hStream, NLong value);

#ifdef N_CPP
}
#endif

#endif // !N_STREAM_H_INCLUDED
