#ifndef N_FILE_STREAM_H_INCLUDED
#define N_FILE_STREAM_H_INCLUDED

#include <IO/NStream.h>

#ifdef N_CPP
extern "C"
{
#endif

N_DECLARE_OBJECT_TYPE(NFileStream, NStream)

NResult N_API NFileStreamCreateN(HNString hPath, NFileMode mode, HNFileStream * phStream);
#ifndef N_NO_ANSI_FUNC
NResult N_API NFileStreamCreateA(const NAChar * szPath, NFileMode mode, HNFileStream * phStream);
#endif
#ifndef N_NO_UNICODE
NResult N_API NFileStreamCreateW(const NWChar * szPath, NFileMode mode, HNFileStream * phStream);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NFileStreamCreate(const NChar * szPath, NFileMode mode, HNFileStream * phStream);
#endif
#define NFileStreamCreate N_FUNC_AW(NFileStreamCreate)

NResult N_API NFileStreamCreateWithAccessN(HNString hPath, NFileMode mode, NFileAccess access, HNFileStream * phStream);
#ifndef N_NO_ANSI_FUNC
NResult N_API NFileStreamCreateWithAccessA(const NAChar * szPath, NFileMode mode, NFileAccess access, HNFileStream * phStream);
#endif
#ifndef N_NO_UNICODE
NResult N_API NFileStreamCreateWithAccessW(const NWChar * szPath, NFileMode mode, NFileAccess access, HNFileStream * phStream);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NFileStreamCreateWithAccess(const NChar * szPath, NFileMode mode, NFileAccess access, HNFileStream * phStream);
#endif
#define NFileStreamCreateWithAccess N_FUNC_AW(NFileStreamCreateWithAccess)

NResult N_API NFileStreamCreateWithAccessAndShareN(HNString hPath, NFileMode mode, NFileAccess access, NFileShare share, HNFileStream * phStream);
#ifndef N_NO_ANSI_FUNC
NResult N_API NFileStreamCreateWithAccessAndShareA(const NAChar * szPath, NFileMode mode, NFileAccess access, NFileShare share, HNFileStream * phStream);
#endif
#ifndef N_NO_UNICODE
NResult N_API NFileStreamCreateWithAccessAndShareW(const NWChar * szPath, NFileMode mode, NFileAccess access, NFileShare share, HNFileStream * phStream);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NFileStreamCreateWithAccessAndShare(const NChar * szPath, NFileMode mode, NFileAccess access, NFileShare share, HNFileStream * phStream);
#endif
#define NFileStreamCreateWithAccessAndShare N_FUNC_AW(NFileStreamCreateWithAccessAndShare)

NResult N_API NFileStreamCreateWithAccessShareAndBufferSizeN(HNString hPath, NFileMode mode, NFileAccess access, NFileShare share, NSizeType bufferSize, HNFileStream * phStream);
#ifndef N_NO_ANSI_FUNC
NResult N_API NFileStreamCreateWithAccessShareAndBufferSizeA(const NAChar * szPath, NFileMode mode, NFileAccess access, NFileShare share, NSizeType bufferSize, HNFileStream * phStream);
#endif
#ifndef N_NO_UNICODE
NResult N_API NFileStreamCreateWithAccessShareAndBufferSizeW(const NWChar * szPath, NFileMode mode, NFileAccess access, NFileShare share, NSizeType bufferSize, HNFileStream * phStream);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NFileStreamCreateWithAccessShareAndBufferSize(const NChar * szPath, NFileMode mode, NFileAccess access, NFileShare share, NSizeType bufferSize, HNFileStream * phStream);
#endif
#define NFileStreamCreateWithAccessShareAndBufferSize N_FUNC_AW(NFileStreamCreateWithAccessShareAndBufferSize)

NResult N_API NFileStreamCreateFromOSHandle(NHandle handle, NBool ownsHandle, NFileAccess access, HNFileStream * phStream);
NResult N_API NFileStreamCreateFromOSHandleWithBufferSize(NHandle handle, NBool ownsHandle, NFileAccess access, NSizeType bufferSize, HNFileStream * phStream);

NResult N_API NFileStreamGetOSHandle(HNFileStream hFileStream, NHandle * phValue);

#ifdef N_CPP
}
#endif

#endif // !N_FILE_STREAM_H_INCLUDED
