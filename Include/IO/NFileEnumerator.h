#ifndef N_FILE_ENUMERATOR_H_INCLUDED
#define N_FILE_ENUMERATOR_H_INCLUDED

#include <IO/NFile.h>

#ifdef N_CPP
extern "C"
{
#endif

N_DECLARE_OBJECT_TYPE(NFileEnumerator, NObject)

NResult N_API NFileEnumeratorCreateN(HNString hPath, HNFileEnumerator * phFileEnumerator);

#ifndef N_NO_ANSI_FUNC
NResult N_API NFileEnumeratorCreateA(const NAChar * szPath, HNFileEnumerator * phFileEnumerator);
#endif
#ifndef N_NO_UNICODE
NResult N_API NFileEnumeratorCreateW(const NWChar * szPath, HNFileEnumerator * phFileEnumerator);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NFileEnumeratorCreate(const NChar * szPath, HNFileEnumerator * phFileEnumerator);
#endif
#define NFileEnumeratorCreate N_FUNC_AW(NFileEnumeratorCreate)

NResult N_API NFileEnumeratorMoveNext(HNFileEnumerator hFileEnumerator, NBool * pValue);
NResult N_API NFileEnumeratorGetFileName(HNFileEnumerator hFileEnumerator, HNString * phValue);
NResult N_API NFileEnumeratorGetFileAttributes(HNFileEnumerator hFileEnumerator, NFileAttributes * pValue);

#ifdef N_CPP
}
#endif

#endif // !N_FILE_ENUMERATOR_H_INCLUDED
