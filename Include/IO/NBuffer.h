#ifndef N_BUFFER_H_INCLUDED
#define N_BUFFER_H_INCLUDED

#include <Core/NObject.h>

#ifdef N_CPP
extern "C"
{
#endif

NResult N_API NBufferCopy(HNBuffer hSrcBuffer, NSizeType srcOffset, HNBuffer hDstBuffer, NSizeType dstOffset, NSizeType size);

NResult N_API NBufferGetEmpty(HNBuffer * phValue);

NResult N_API NBufferCreate(NSizeType size, HNBuffer * phBuffer);
NResult N_API NBufferCreateFromPtr(void * ptr, NSizeType size, NBool ownsPtr, HNBuffer * phBuffer);
#define NBufferCreateFromConstPtr(ptr, size, phBuffer) NBufferCreateFromPtr((void *)ptr, size, NFalse, phBuffer)
NResult N_API NBufferCreateFromPtrEx(void * ptr, NSizeType size, NMemoryType ptrType, HNBuffer * phBuffer);
NResult N_API NBufferCreateFromPtrWithFree(void * ptr, NSizeType size, HNCallback hFree, HNBuffer * phBuffer);
NResult N_API NBufferCreateFromPtrWithFreeProc(void * ptr, NSizeType size, NPointerFreeProc pFree, void * pFreeParam, HNBuffer * phBuffer);
NResult N_API NBufferCreateFromBuffer(HNBuffer hSrcBuffer, NSizeType offset, NSizeType size, HNBuffer * phBuffer);

NResult N_API NBufferCopyTo(HNBuffer hBuffer, HNBuffer hDstBuffer, NSizeType dstOffset);
NResult N_API NBufferCopyToPtr(HNBuffer hBuffer, void * pDstBuffer, NSizeType dstBufferSize);
NResult N_API NBufferCopyToPtrRange(HNBuffer hBuffer, NSizeType offset, void * pDstBuffer, NSizeType dstBufferSize, NSizeType size);
NResult N_API NBufferCopyFromPtr(HNBuffer hBuffer, const void * pSrcBuffer, NSizeType srcBufferSize, NSizeType offset);
NResult N_API NBufferToPtr(HNBuffer hBuffer, NSizeType * pBufferSize, void * * ppBuffer);

NResult N_API NBufferGetPtr(HNBuffer hBuffer, void * * pValue);
NResult N_API NBufferGetSize(HNBuffer hBuffer, NSizeType * pValue);

#ifdef N_CPP
}
#endif

#endif // !N_BUFFER_H_INCLUDED
