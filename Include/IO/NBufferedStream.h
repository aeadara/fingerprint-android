#ifndef N_BUFFERED_STREAM_H_INCLUDED
#define N_BUFFERED_STREAM_H_INCLUDED

#include <IO/NStream.h>

#ifdef N_CPP
extern "C"
{
#endif

N_DECLARE_OBJECT_TYPE(NBufferedStream, NStream)

NResult N_API NBufferedStreamCreate(HNStream hInnerStream, HNBufferedStream * phStream);
NResult N_API NBufferedStreamCreateWithBufferSize(HNStream hInnerStream, NSizeType bufferSize, HNBufferedStream * phStream);

#ifdef N_CPP
}
#endif

#endif // !N_BUFFERED_STREAM_H_INCLUDED
