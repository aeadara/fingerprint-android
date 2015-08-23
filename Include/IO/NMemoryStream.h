#ifndef N_MEMORY_STREAM_H_INCLUDED
#define N_MEMORY_STREAM_H_INCLUDED

#include <IO/NStream.h>

#ifdef N_CPP
extern "C"
{
#endif

N_DECLARE_OBJECT_TYPE(NMemoryStream, NStream)

NResult N_API NMemoryStreamCreate(HNMemoryStream * phStream);
NResult N_API NMemoryStreamCreateWithCapacity(NSizeType capacity, HNMemoryStream * phStream);
NResult N_API NMemoryStreamCreateFromBufferN(HNBuffer hBuffer, NFileAccess access, NBool bufferExposable, HNMemoryStream * phStream);
NResult N_API NMemoryStreamCreateFromBuffer(void * pBuffer, NSizeType bufferSize, NFileAccess access, NBool bufferExposable, HNMemoryStream * phStream);
#define NMemoryStreamCreateFromBufferForRead(pBuffer, bufferSize, phStream) NMemoryStreamCreateFromBuffer((void *)pBuffer, bufferSize, nfaRead, NFalse, phStream)

NResult N_API NMemoryStreamGetBuffer(HNMemoryStream hStream, HNBuffer * phValue);
NResult N_API NMemoryStreamWriteTo(HNMemoryStream hStream, HNStream hDstStream);
NResult N_API NMemoryStreamToPtr(HNMemoryStream hStream, NSizeType * pBufferSize, void * * ppBuffer);

NResult N_API NMemoryStreamGetCapacity(HNMemoryStream hStream, NSizeType * pValue);
NResult N_API NMemoryStreamSetCapacity(HNMemoryStream hStream, NSizeType value);
NResult N_API NMemoryStreamGetPositionPtr(HNMemoryStream hStream, void * * pValue);
NResult N_API NMemoryStreamSetPositionPtr(HNMemoryStream hStream, void * value);

#ifdef N_CPP
}
#endif

#endif // !N_MEMORY_STREAM_H_INCLUDED
