#ifndef N_MEMORY_H_INCLUDED
#define N_MEMORY_H_INCLUDED

#include <Core/NTypes.h>
#include <memory.h>
#include <string.h>

#ifdef N_CPP
extern "C"
{
#endif

typedef enum NMemoryType_
{
	nmmtNone = 0,
	nmmtDefault = 1,
	nmmtAligned = 2,
	nmmtStandard = 3,
	nmmtWin32Local = 4,
	nmmtWin32Global = 5,
	nmmtCustom = 15
} NMemoryType;

N_DECLARE_TYPE(NMemoryType)

NBool N_API NMemoryTypeIsValid(NMemoryType value);
NBool N_API NMemoryTypeIsValidForFree(NMemoryType value);

NResult N_API NAlloc(NSizeType size, void * * ppBlock);
NResult N_API NCAlloc(NSizeType size, void * * ppBlock);
NResult N_API NReAlloc(void * * ppBlock, NSizeType size);
void N_API NFree(void * pBlock);
void N_API NFreeEx(void * pBlock, NMemoryType memoryType);

NResult N_API NCopy(void * pDstBlock, const void * pSrcBlock, NSizeType size);
NResult N_API NMove(void * pDstBlock, const void * pSrcBlock, NSizeType size);
NResult N_API NFill(void * pBlock, NByte value, NSizeType size);
#define NClear(pBlock, size) NFill(pBlock, 0, size)
NResult N_API NCompare(const void * pBlock1, const void * pBlock2, NSizeType size, NInt * pResult);

NResult N_API NAlignedOffsetAlloc(NSizeType size, NSizeType alignment, NSizeType offset, void * * ppBlock);
NResult N_API NAlignedOffsetCAlloc(NSizeType size, NSizeType alignment, NSizeType offset, void * * ppBlock);
NResult N_API NAlignedOffsetReAlloc(void * * ppBlock, NSizeType size, NSizeType alignment, NSizeType offset);
void N_API NAlignedFree(void * pBlock);
#define NAlignedAlloc(size, alignment, ppBlock) NAlignedOffsetAlloc(size, alignment, 0, ppBlock)
#define NAlignedCAlloc(size, alignment, ppBlock) NAlignedOffsetCAlloc(size, alignment, 0, ppBlock)
#define NAlignedReAlloc(ppBlock, size, alignment) NAlignedOffsetReAlloc(ppBlock, size, alignment, 0)

NResult N_API NPageAlloc(NSizeType size, void * * ppMem);
NResult N_API NPageFree(void * pMem, NSizeType size);

NResult N_API NAllocArray(NSizeType elementSize, NInt length, void * * ppValues);
NResult N_API NCAllocArray(NSizeType elementSize, NInt length, void * * ppValues);
NResult N_API NReAllocArray(NSizeType elementSize, void * * ppValues, NInt length);
NResult N_API NCopyArray(NSizeType elementSize, void * pDstValues, const void * pSrcValues, NInt length);
NResult N_API NMoveArray(NSizeType elementSize, void * pDstValues, const void * pSrcValues, NInt length);
NResult N_API NClearArray(NSizeType elementSize, void * pValues, NInt length);

NResult N_API NAlignedOffsetAllocArray(NSizeType elementSize, NInt length, NSizeType alignment, NInt offset, void * * ppValues);
NResult N_API NAlignedOffsetCAllocArray(NSizeType elementSize, NInt length, NSizeType alignment, NInt offset, void * * ppValues);
NResult N_API NAlignedOffsetReAllocArray(NSizeType elementSize, void * * ppValues, NInt length, NSizeType alignment, NInt offset);
#define NAlignedAllocArray(elementSize, length, alignment, ppValues) NAlignedOffsetAllocArray(elementSize, length, alignment, 0, ppValues)
#define NAlignedCAllocArray(elementSize, length, alignment, ppValues) NAlignedOffsetCAllocArray(elementSize, length, alignment, 0, ppValues)
#define NAlignedReAllocArray(elementSize, length, alignment, ppValues) NAlignedOffsetReAllocArray(elementSize, ppValues, length, alignment, 0)

NResult N_API NDisposeElementsRaw(NSizeType elementSize, NResult (N_CALLBACK pDisposeValue)(void * pValue), void * pValues, NInt length);
#define NDisposeElements(type, pValues, length) NDisposeElementsRaw(sizeof(type), (NResult (N_CALLBACK)(void * pValue))type##Dispose, pValues, length)

NResult N_API NDisposeArrayRaw(NSizeType elementSize, NResult (N_CALLBACK pDisposeValue)(void * pValue), void * pValues, NInt length);
#define NDisposeArray(type, pValues, length) NDisposeArrayRaw(sizeof(type), (NResult (N_CALLBACK)(void * pValue))type##Dispose, pValues, length)

NResult N_API NGetElementsRaw(NSizeType elementSize, NResult (N_CALLBACK pCopyValue)(const void * pSrcValue, void * pDstValue), const void * pSrcValues, NInt srcLength, void * pDstValues, NInt dstLength);
NResult N_API NGetArrayRaw(NSizeType elementSize, NResult (N_CALLBACK pCopyValue)(const void * pSrcValue, void * pDstValue), const void * pSrcValues, NInt srcLength, void * * ppDstValues, NInt * pDstValueCount);

#define NGetElements(type, pSrcValues, srcLength, pDstValues, dstLength) NGetElementsRaw(sizeof(type), NULL, pSrcValues, srcLength, pDstValues, dstLength)
#define NGetArray(type, pSrcValues, srcLength, ppDstValues, pDstValueCount) NGetArrayRaw(sizeof(type), NULL, pSrcValues, srcLength, ppDstValues, pDstValueCount)

#define NGetDisposableElements(type, pSrcValues, srcLength, pDstValues, dstLength) NGetElementsRaw(sizeof(type), (NResult (N_CALLBACK)(const void * pSrcValue, void * pDstValue))type##Copy, pSrcValues, srcLength, pDstValues, dstLength)
#define NGetDisposableArray(type, pSrcValues, srcLength, ppDstValues, pDstValueCount) NGetArrayRaw(sizeof(type), (NResult (N_CALLBACK)(const void * pSrcValue, void * pDstValue))type##Copy, pSrcValues, srcLength, ppDstValues, pDstValueCount)

#ifdef N_CPP
}
#endif

#endif // !N_MEMORY_H_INCLUDED
