#ifndef AN_FIELD_H_INCLUDED
#define AN_FIELD_H_INCLUDED

#include <Biometrics/Standards/ANSubField.h>

#ifdef N_CPP
extern "C"
{
#endif

N_DECLARE_OBJECT_TYPE(ANField, NObject)

NResult N_API ANFieldGetItemCount(HANField hField, NInt * pValue);

NResult N_API ANFieldGetItemN(HANField hField, NInt index, HNString * phValue);
NResult N_API ANFieldGetItemCapacity(HANField hField, NInt * pValue);
NResult N_API ANFieldSetItemCapacity(HANField hField, NInt value);

NResult N_API ANFieldSetItemN(HANField hField, NInt index, HNString hValue);
#ifndef N_NO_ANSI_FUNC
NResult N_API ANFieldSetItemExA(HANField hField, NInt index, const NAChar * szValue);
#endif
#ifndef N_NO_UNICODE
NResult N_API ANFieldSetItemExW(HANField hField, NInt index, const NWChar * szValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API ANFieldSetItemEx(HANField hField, NInt index, const NChar * szValue);
#endif
#define ANFieldSetItemEx N_FUNC_AW(ANFieldSetItemEx)

NResult N_API ANFieldAddItemN(HANField hField, HNString hValue, NInt * pIndex);
#ifndef N_NO_ANSI_FUNC
NResult N_API ANFieldAddItemExA(HANField hField, const NAChar * szValue, NInt * pIndex);
#endif
#ifndef N_NO_UNICODE
NResult N_API ANFieldAddItemExW(HANField hField, const NWChar * szValue, NInt * pIndex);
#endif
#ifdef N_DOCUMENTATION
NResult N_API ANFieldAddItemEx(HANField hField, const NChar * szValue, NInt * pIndex);
#endif
#define ANFieldAddItemEx N_FUNC_AW(ANFieldAddItemEx)

NResult N_API ANFieldInsertItemN(HANField hField, NInt index, HNString hValue);
#ifndef N_NO_ANSI_FUNC
NResult N_API ANFieldInsertItemExA(HANField hField, NInt index, const NAChar * szValue);
#endif
#ifndef N_NO_UNICODE
NResult N_API ANFieldInsertItemExW(HANField hField, NInt index, const NWChar * szValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API ANFieldInsertItemEx(HANField hField, NInt index, const NChar * szValue);
#endif
#define ANFieldInsertItemEx N_FUNC_AW(ANFieldInsertItemEx)

N_DEPRECATED("function is deprecated, use ANFieldRemoveItemAt instead")
NResult N_API ANFieldRemoveItem(HANField hField, NInt index);
NResult N_API ANFieldRemoveItemAt(HANField hField, NInt index);
NResult N_API ANFieldRemoveItemRange(HANField hField, NInt index, NInt count);

NResult N_API ANFieldGetSubFieldCount(HANField hField, NInt * pValue);
NResult N_API ANFieldGetSubFieldEx(HANField hField, NInt index, HANSubField * phValue);
NResult N_API ANFieldGetSubFieldCapacity(HANField hField, NInt * pValue);
NResult N_API ANFieldSetSubFieldCapacity(HANField hField, NInt value);

NResult N_API ANFieldAddSubFieldN(HANField hField, HNString hValue, NInt * pIndex, HANSubField * phValue);
#ifndef N_NO_ANSI_FUNC
NResult N_API ANFieldAddSubFieldExA(HANField hField, const NAChar * szValue, NInt * pIndex, HANSubField * phValue);
#endif
#ifndef N_NO_UNICODE
NResult N_API ANFieldAddSubFieldExW(HANField hField, const NWChar * szValue, NInt * pIndex, HANSubField * phValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API ANFieldAddSubFieldEx(HANField hField, const NChar * szValue, NInt * pIndex, HANSubField * phValue);
#endif
#define ANFieldAddSubFieldEx N_FUNC_AW(ANFieldAddSubFieldEx)

NResult N_API ANFieldInsertSubFieldN(HANField hField, NInt index, HNString hValue, HANSubField * phValue);
#ifndef N_NO_ANSI_FUNC
NResult N_API ANFieldInsertSubFieldExA(HANField hField, NInt index, const NAChar * szValue, HANSubField * phValue);
#endif
#ifndef N_NO_UNICODE
NResult N_API ANFieldInsertSubFieldExW(HANField hField, NInt index, const NWChar * szValue, HANSubField * phValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API ANFieldInsertSubFieldEx(HANField hField, NInt index, const NChar * szValue, HANSubField * phValue);
#endif
#define ANFieldInsertSubFieldEx N_FUNC_AW(ANFieldInsertSubFieldEx)

N_DEPRECATED("function is deprecated, use ANFieldRemoveSubFieldAt instead")
NResult N_API ANFieldRemoveSubField(HANField hField, NInt index);
NResult N_API ANFieldRemoveSubFieldAt(HANField hField, NInt index);
NResult N_API ANFieldRemoveSubFieldRange(HANField hField, NInt index, NInt count);

NResult N_API ANFieldGetValueN(HANField hField, HNString * phValue);

NResult N_API ANFieldSetValueN(HANField hField, HNString hValue);
#ifndef N_NO_ANSI_FUNC
NResult N_API ANFieldSetValueExA(HANField hField, const NAChar * szValue);
#endif
#ifndef N_NO_UNICODE
NResult N_API ANFieldSetValueExW(HANField hField, const NWChar * szValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API ANFieldSetValueEx(HANField hField, const NChar * szValue);
#endif
#define ANFieldSetValueEx N_FUNC_AW(ANFieldSetValueEx)

NResult N_API ANFieldGetNumber(HANField hField, NInt * pValue);
NResult N_API ANFieldGetHeader(HANField hField, HNString * phValue);

#ifdef N_CPP
}
#endif

#endif // !AN_FIELD_H_INCLUDED
