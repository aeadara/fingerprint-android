#ifndef AN_SUB_FIELD_H_INCLUDED
#define AN_SUB_FIELD_H_INCLUDED

#include <Core/NObject.h>

#ifdef N_CPP
extern "C"
{
#endif

N_DECLARE_OBJECT_TYPE(ANSubField, NObject)

NResult N_API ANSubFieldGetItemCount(HANSubField hSubField, NInt * pValue);

NResult N_API ANSubFieldGetItemN(HANSubField hSubField, NInt index, HNString * phValue);
NResult N_API ANSubFieldGetItemCapacity(HANSubField hSubField, NInt * pValue);
NResult N_API ANSubFieldSetItemCapacity(HANSubField hSubField, NInt value);

NResult N_API ANSubFieldSetItemN(HANSubField hSubField, NInt index, HNString hValue);
#ifndef N_NO_ANSI_FUNC
NResult N_API ANSubFieldSetItemExA(HANSubField hSubField, NInt index, const NAChar * szValue);
#endif
#ifndef N_NO_UNICODE
NResult N_API ANSubFieldSetItemExW(HANSubField hSubField, NInt index, const NWChar * szValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API ANSubFieldSetItemEx(HANSubField hSubField, NInt index, const NChar * szValue);
#endif
#define ANSubFieldSetItemEx N_FUNC_AW(ANSubFieldSetItemEx)

NResult N_API ANSubFieldAddItemN(HANSubField hSubField, HNString hValue, NInt * pIndex);
#ifndef N_NO_ANSI_FUNC
NResult N_API ANSubFieldAddItemExA(HANSubField hSubField, const NAChar * szValue, NInt * pIndex);
#endif
#ifndef N_NO_UNICODE
NResult N_API ANSubFieldAddItemExW(HANSubField hSubField, const NWChar * szValue, NInt * pIndex);
#endif
#ifdef N_DOCUMENTATION
NResult N_API ANSubFieldAddItemEx(HANSubField hSubField, const NChar * szValue, NInt * pIndex);
#endif
#define ANSubFieldAddItemEx N_FUNC_AW(ANSubFieldAddItemEx)

NResult N_API ANSubFieldInsertItemN(HANSubField hSubField, NInt index, HNString hValue);
#ifndef N_NO_ANSI_FUNC
NResult N_API ANSubFieldInsertItemExA(HANSubField hSubField, NInt index, const NAChar * szValue);
#endif
#ifndef N_NO_UNICODE
NResult N_API ANSubFieldInsertItemExW(HANSubField hSubField, NInt index, const NWChar * szValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API ANSubFieldInsertItemEx(HANSubField hSubField, NInt index, const NChar * szValue);
#endif
#define ANSubFieldInsertItemEx N_FUNC_AW(ANSubFieldInsertItemEx)

N_DEPRECATED("function is deprecated, use ANSubFieldRemoveItemAt instead")
NResult N_API ANSubFieldRemoveItem(HANSubField hSubField, NInt index);
NResult N_API ANSubFieldRemoveItemAt(HANSubField hSubField, NInt index);
NResult N_API ANSubFieldRemoveItemRange(HANSubField hSubField, NInt index, NInt count);

NResult N_API ANSubFieldGetValueN(HANSubField hSubField, HNString * phValue);
NResult N_API ANSubFieldSetValueN(HANSubField hSubField, HNString hValue);
#ifndef N_NO_ANSI_FUNC
NResult N_API ANSubFieldSetValueExA(HANSubField hSubField, const NAChar * szValue);
#endif
#ifndef N_NO_UNICODE
NResult N_API ANSubFieldSetValueExW(HANSubField hSubField, const NWChar * szValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API ANSubFieldSetValueEx(HANSubField hSubField, const NChar * szValue);
#endif
#define ANSubFieldSetValueEx N_FUNC_AW(ANSubFieldSetValueEx)

#ifdef N_CPP
}
#endif

#endif // !AN_SUB_FIELD_H_INCLUDED
