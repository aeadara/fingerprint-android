#ifndef N_DIRECTORY_H_INCLUDED
#define N_DIRECTORY_H_INCLUDED

#include <Core/NObject.h>

#ifdef N_CPP
extern "C"
{
#endif

N_DECLARE_STATIC_OBJECT_TYPE(NDirectory)

NResult N_API NDirectoryExistsN(HNString hPath, NBool * pValue);

#ifndef N_NO_ANSI_FUNC
NResult N_API NDirectoryExistsA(const NAChar * szPath, NBool * pValue);
#endif
#ifndef N_NO_UNICODE
NResult N_API NDirectoryExistsW(const NWChar * szPath, NBool * pValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NDirectoryExists(const NChar * szPath, NBool * pValue);
#endif
#define NDirectoryExists N_FUNC_AW(NDirectoryExists)

#ifdef N_CPP
}
#endif

#endif // !N_DIRECTORY_H_INCLUDED
