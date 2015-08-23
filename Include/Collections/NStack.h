#ifndef N_STACK_H_INCLUDED
#define N_STACK_H_INCLUDED

#include <Core/NType.h>

#ifdef N_CPP
extern "C"
{
#endif

#ifdef N_64
	#define N_STACK_SIZE 48
#else
	#define N_STACK_SIZE 32
#endif

N_DECLATE_PRIMITIVE(NStack, N_STACK_SIZE)
N_DECLARE_TYPE(NStack)

NResult N_API NStackInitP(NStack * pStack, NSizeType elementSize, NTypeOfProc pElementTypeOf);
NResult N_API NStackInit(NStack * pStack, NSizeType elementSize, HNType hElementType);
NResult N_API NStackInitWithCapacityP(NStack * pStack, NSizeType elementSize, NTypeOfProc pElementTypeOf, NInt capacity);
NResult N_API NStackInitWithCapacity(NStack * pStack, NSizeType elementSize, HNType hElementType, NInt capacity);
NResult N_API NStackInitExP(NStack * pStack, NSizeType elementSize, NTypeOfProc pElementTypeOf, NInt capacity, NInt maxCapacity, NInt growthDelta, NSizeType alignment);
NResult N_API NStackInitEx(NStack * pStack, NSizeType elementSize, HNType hElementType, NInt capacity, NInt maxCapacity, NInt growthDelta, NSizeType alignment);
NResult N_API NStackDispose(NStack * pStack);
NResult N_API NStackGetCapacity(NStack * pStack, NInt * pValue);
NResult N_API NStackSetCapacity(NStack * pStack, NInt value);
NResult N_API NStackGetCount(NStack * pStack, NInt * pValue);
NResult N_API NStackContains(NStack * pStack, HNType hValueType, const void * pValue, NSizeType valueSize, NBool * pResult);
NResult N_API NStackContainsP(NStack * pStack, NTypeOfProc pValueTypeOf, const void * pValue, NSizeType valueSize, NBool * pResult);
NResult N_API NStackGetTop(NStack * pStack, NSizeType elementSize, HNType hValueType, void * * ppValue);
NResult N_API NStackGetTopP(NStack * pStack, NSizeType elementSize, NTypeOfProc pValueTypeOf, void * * ppValue);
NResult N_API NStackPeek(NStack * pStack, HNType hValueType, void * pValue, NSizeType valueSize);
NResult N_API NStackPeekP(NStack * pStack, NTypeOfProc pValueTypeOf, void * pValue, NSizeType valueSize);
NResult N_API NStackPop(NStack * pStack, HNType hValueType, void * pValue, NSizeType valueSize);
NResult N_API NStackPopP(NStack * pStack, NTypeOfProc pValueTypeOf, void * pValue, NSizeType valueSize);
NResult N_API NStackPush(NStack * pStack, HNType hValueType, const void * pValue, NSizeType valueSize);
NResult N_API NStackPushP(NStack * pStack, NTypeOfProc pValueTypeOf, const void * pValue, NSizeType valueSize);
NResult N_API NStackClear(NStack * pStack);
NResult N_API NStackCopyTo(NStack * pStack, HNType hValueType, void * pValues, NSizeType valuesSize, NInt valuesLength);
NResult N_API NStackCopyToP(NStack * pStack, NTypeOfProc pValueTypeOf, void * pValues, NSizeType valuesSize, NInt valuesLength);
NResult N_API NStackToArray(NStack * pStack, NSizeType elementSize, HNType hValueType, void * * ppValues, NInt * pValuesLength);
NResult N_API NStackToArrayP(NStack * pStack, NSizeType elementSize, NTypeOfProc pValueTypeOf, void * * ppValues, NInt * pValuesLength);

#ifdef N_CPP
}
#endif

#endif // !N_STACK_H_INCLUDED
