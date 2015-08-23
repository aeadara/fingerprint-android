#ifndef NIST_COM_H_INCLUDED
#define NIST_COM_H_INCLUDED

#include <Core/NObject.h>

#ifdef N_CPP
extern "C"
{
#endif

N_DECLARE_OBJECT_TYPE(NistCom, NObject)

NResult N_API NistComCreate(NUInt flags, HNistCom * phNistCom);

NResult N_API NistComCreateFromFileN(HNString hFileName, NUInt flags, HNistCom * phNistCom);
#ifndef N_NO_ANSI_FUNC
NResult N_API NistComCreateFromFileA(const NAChar * szFileName, NUInt flags, HNistCom * phNistCom);
#endif
#ifndef N_NO_UNICODE
NResult N_API NistComCreateFromFileW(const NWChar * szFileName, NUInt flags, HNistCom * phNistCom);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NistComCreateFromFile(const NChar * szFileName, NUInt flags, HNistCom * phNistCom);
#endif
#define NistComCreateFromFile N_FUNC_AW(NistComCreateFromFile)

NResult N_API NistComCreateFromMemoryN(HNBuffer hBuffer, NUInt flags, NSizeType * pSize, HNistCom * phNistCom);
NResult N_API NistComCreateFromMemory(const void * pBuffer, NSizeType bufferSize, NUInt flags, NSizeType * pSize, HNistCom * phNistCom);
NResult N_API NistComCreateFromStream(HNStream hStream, NUInt flags, HNistCom * phNistCom);

NResult N_API NistComGetItemCount(HNistCom hNistCom, NInt * pValue);
NResult N_API NistComGetItem(HNistCom hNistCom, NInt index, struct NNameStringPair_ * pValue);
NResult N_API NistComSetItem(HNistCom hNistCom, NInt index, const struct NNameStringPair_ * pValue);
NResult N_API NistComAddItem(HNistCom hNistCom, const struct NNameStringPair_ * pValue);
NResult N_API NistComInsertItem(HNistCom hNistCom, NInt index, const struct NNameStringPair_ * pValue);
NResult N_API NistComRemoveItemAt(HNistCom hNistCom, NInt index);
NResult N_API NistComClearItems(HNistCom hNistCom);

NResult N_API NistComGetValueN(HNistCom hNistCom, HNString hKey, HNString * phValue);
#ifndef N_NO_ANSI_FUNC
NResult N_API NistComGetValueA(HNistCom hNistCom, const NAChar * szKey, HNString * phValue);
#endif
#ifndef N_NO_UNICODE
NResult N_API NistComGetValueW(HNistCom hNistCom, const NWChar * szKey, HNString * phValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NistComGetValue(HNistCom hNistCom, const NChar * szKey, HNString * phValue);
#endif
#define NistComGetValue N_FUNC_AW(NistComGetValue)

NResult N_API NistComSetValueN(HNistCom hNistCom, HNString hKey, HNString hValue);

#ifndef N_NO_ANSI_FUNC
NResult N_API NistComSetValueVNA(HNistCom hNistCom, const NAChar * szKey, HNString hValue);
#endif
#ifndef N_NO_UNICODE
NResult N_API NistComSetValueVNW(HNistCom hNistCom, const NWChar * szKey, HNString hValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NistComSetValueVN(HNistCom hNistCom, const NChar * szKey, HNString hValue);
#endif
#define NistComSetValueVN N_FUNC_AW(NistComSetValueVN)

#ifndef N_NO_ANSI_FUNC
NResult N_API NistComSetValueA(HNistCom hNistCom, const NAChar * szKey, const NAChar * szValue);
#endif
#ifndef N_NO_UNICODE
NResult N_API NistComSetValueW(HNistCom hNistCom, const NWChar * szKey, const NWChar * szValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NistComSetValue(HNistCom hNistCom, const NChar * szKey, const NChar * szValue);
#endif
#define NistComSetValue N_FUNC_AW(NistComSetValue)

NResult N_API NistComAddValueN(HNistCom hNistCom, HNString hKey, HNString hValue);

#ifndef N_NO_ANSI_FUNC
NResult N_API NistComAddValueVNA(HNistCom hNistCom, const NAChar * szKey, HNString hValue);
#endif
#ifndef N_NO_UNICODE
NResult N_API NistComAddValueVNW(HNistCom hNistCom, const NWChar * szKey, HNString hValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NistComAddValueVN(HNistCom hNistCom, const NChar * szKey, HNString hValue);
#endif
#define NistComAddValueVN N_FUNC_AW(NistComAddValueVN)

#ifndef N_NO_ANSI_FUNC
NResult N_API NistComAddValueA(HNistCom hNistCom, const NAChar * szKey, const NAChar * szValue);
#endif
#ifndef N_NO_UNICODE
NResult N_API NistComAddValueW(HNistCom hNistCom, const NWChar * szKey, const NWChar * szValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NistComAddValue(HNistCom hNistCom, const NChar * szKey, const NChar * szValue);
#endif
#define NistComAddValue N_FUNC_AW(NistComAddValue)

NResult N_API NistComSaveToFileN(HNistCom hNistCom, HNString hFileName, NUInt flags);
#ifndef N_NO_ANSI_FUNC
NResult N_API NistComSaveToFileA(HNistCom hNistCom, const NAChar * szFileName, NUInt flags);
#endif
#ifndef N_NO_UNICODE
NResult N_API NistComSaveToFileW(HNistCom hNistCom, const NWChar * szFileName, NUInt flags);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NistComSaveToFile(HNistCom hNistCom, const NChar * szFileName, NUInt flags);
#endif
#define NistComSaveToFile N_FUNC_AW(NistComSaveToFile)

#ifdef N_CPP
}
#endif

#endif // !NIST_COM_H_INCLUDED
