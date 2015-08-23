#ifndef N_IMAGE_FORMAT_H_INCLUDED
#define N_IMAGE_FORMAT_H_INCLUDED

#include <Core/NObject.h>

#ifdef N_CPP
extern "C"
{
#endif

N_DECLARE_OBJECT_TYPE(NImageFormat, NObject)

#ifdef N_CPP
}
#endif

#include <Images/NImage.h>
#include <Images/NImageInfo.h>
#include <Images/NImageReader.h>
#include <Images/NImageWriter.h>

#ifdef N_CPP
extern "C"
{
#endif

NResult N_API NImageFormatGetFormatCount(NInt * pValue);
N_DEPRECATED("function is deprecated, use NImageFormatGetFormatEx instead")
NResult N_API NImageFormatGetFormat(NInt index, HNImageFormat * phValue);
NResult N_API NImageFormatGetFormatEx(NInt index, HNImageFormat * phValue);

NResult N_API NImageFormatSelectExN(HNString hFileName, NFileAccess fileAccess, HNImageFormat * phImageFormat);
#ifndef N_NO_ANSI_FUNC
NResult N_API NImageFormatSelectExA(const NAChar * szFileName, NFileAccess fileAccess, HNImageFormat * phImageFormat);
#endif
#ifndef N_NO_UNICODE
NResult N_API NImageFormatSelectExW(const NWChar * szFileName, NFileAccess fileAccess, HNImageFormat * phImageFormat);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NImageFormatSelectEx(const NChar * szFileName, NFileAccess fileAccess, HNImageFormat * phImageFormat);
#endif
#define NImageFormatSelectEx N_FUNC_AW(NImageFormatSelectEx)

NResult N_API NImageFormatSelectN(HNString hFileName, NFileAccess fileAccess, HNImageFormat * phImageFormat);
#ifndef N_NO_ANSI_FUNC
NResult N_API NImageFormatSelectA(const NAChar * szFileName, NFileAccess fileAccess, HNImageFormat * phImageFormat);
#endif
#ifndef N_NO_UNICODE
NResult N_API NImageFormatSelectW(const NWChar * szFileName, NFileAccess fileAccess, HNImageFormat * phImageFormat);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NImageFormatSelect(const NChar * szFileName, NFileAccess fileAccess, HNImageFormat * phImageFormat);
#endif
#define NImageFormatSelect N_FUNC_AW(NImageFormatSelect)

NResult N_API NImageFormatSelectByInternetMediaTypeN(HNString hInternetMediaType, NFileAccess fileAccess, HNImageFormat * phImageFormat);
#ifndef N_NO_ANSI_FUNC
NResult N_API NImageFormatSelectByInternetMediaTypeA(const NAChar * szInternetMediaType, NFileAccess fileAccess, HNImageFormat * phImageFormat);
#endif
#ifndef N_NO_UNICODE
NResult N_API NImageFormatSelectByInternetMediaTypeW(const NWChar * szInternetMediaType, NFileAccess fileAccess, HNImageFormat * phImageFormat);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NImageFormatSelectByInternetMediaType(const NChar * szInternetMediaType, NFileAccess fileAccess, HNImageFormat * phImageFormat);
#endif
#define NImageFormatSelectByInternetMediaType N_FUNC_AW(NImageFormatSelectByInternetMediaType)

NResult N_API NImageFormatSelectReaderFromFileN(HNString hFileName, NUInt flags, HNImageReader * phReader);
#ifndef N_NO_ANSI_FUNC
NResult N_API NImageFormatSelectReaderFromFileA(const NAChar * szFileName, NUInt flags, HNImageReader * phReader);
#endif
#ifndef N_NO_UNICODE
NResult N_API NImageFormatSelectReaderFromFileW(const NWChar * szFileName, NUInt flags, HNImageReader * phReader);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NImageFormatSelectReaderFromFile(const NChar * szFileName, NUInt flags, HNImageReader * phReader);
#endif
#define NImageFormatSelectReaderFromFile N_FUNC_AW(NImageFormatSelectReaderFromFile)

NResult N_API NImageFormatSelectReaderFromMemoryN(HNBuffer hBuffer, NUInt flags, HNImageReader * phReader);
NResult N_API NImageFormatSelectReaderFromMemory(const void * pBuffer, NSizeType bufferSize, NUInt flags, HNImageReader * phReader);
NResult N_API NImageFormatSelectReaderFromStream(HNStream hStream, NUInt flags, HNImageReader * phReader);

N_DEPRECATED("function is deprecated, use NImageFormatGetTiffEx instead")
NResult N_API NImageFormatGetTiff(HNImageFormat * phValue);
NResult N_API NImageFormatGetTiffEx(HNImageFormat * phValue);
N_DEPRECATED("function is deprecated, use NImageFormatGetJpegEx instead")
NResult N_API NImageFormatGetJpeg(HNImageFormat * phValue);
NResult N_API NImageFormatGetJpegEx(HNImageFormat * phValue);
N_DEPRECATED("function is deprecated, use NImageFormatGetPngEx instead")
NResult N_API NImageFormatGetPng(HNImageFormat * phValue);
NResult N_API NImageFormatGetPngEx(HNImageFormat * phValue);
N_DEPRECATED("function is deprecated, use NImageFormatGetWsqEx instead")
NResult N_API NImageFormatGetWsq(HNImageFormat * phValue);
NResult N_API NImageFormatGetWsqEx(HNImageFormat * phValue);
N_DEPRECATED("function is deprecated, use NImageFormatGetJpeg2KEx instead")
NResult N_API NImageFormatGetJpeg2K(HNImageFormat * phValue);
NResult N_API NImageFormatGetJpeg2KEx(HNImageFormat * phValue);
N_DEPRECATED("function is deprecated, use NImageFormatGetBmpEx instead")
NResult N_API NImageFormatGetBmp(HNImageFormat * phValue);
NResult N_API NImageFormatGetBmpEx(HNImageFormat * phValue);
N_DEPRECATED("function is deprecated, use NImageFormatGetIHeadEx instead")
NResult N_API NImageFormatGetIHead(HNImageFormat * phValue);
NResult N_API NImageFormatGetIHeadEx(HNImageFormat * phValue);

NResult N_API NImageFormatOpenReaderFromFileN(HNImageFormat hImageFormat, HNString hFileName, NUInt flags, HNImageReader * phReader);
#ifndef N_NO_ANSI_FUNC
NResult N_API NImageFormatOpenReaderFromFileA(HNImageFormat hImageFormat, const NAChar * szFileName, NUInt flags, HNImageReader * phReader);
#endif
#ifndef N_NO_UNICODE
NResult N_API NImageFormatOpenReaderFromFileW(HNImageFormat hImageFormat, const NWChar * szFileName, NUInt flags, HNImageReader * phReader);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NImageFormatOpenReaderFromFile(HNImageFormat hImageFormat, const NChar * szFileName, NUInt flags, HNImageReader * phReader);
#endif
#define NImageFormatOpenReaderFromFile N_FUNC_AW(NImageFormatOpenReaderFromFile)

NResult N_API NImageFormatOpenReaderFromMemoryN(HNImageFormat hImageFormat, HNBuffer hBuffer, NUInt flags, HNImageReader * phReader);
NResult N_API NImageFormatOpenReaderFromMemory(HNImageFormat hImageFormat, const void * pBuffer, NSizeType bufferSize, NUInt flags, HNImageReader * phReader);
NResult N_API NImageFormatOpenReaderFromStream(HNImageFormat hImageFormat, HNStream hStream, NUInt flags, HNImageReader * phReader);

NResult N_API NImageFormatCreateInfo(HNImageFormat hImageFormat, HNImage hImage, NUInt flags, HNImageInfo * phInfo);

NResult N_API NImageFormatOpenWriterToFileN(HNImageFormat hImageFormat, HNString hFileName, NUInt flags, HNImageWriter * phWriter);
#ifndef N_NO_ANSI_FUNC
NResult N_API NImageFormatOpenWriterToFileA(HNImageFormat hImageFormat, const NAChar * szFileName, NUInt flags, HNImageWriter * phWriter);
#endif
#ifndef N_NO_UNICODE
NResult N_API NImageFormatOpenWriterToFileW(HNImageFormat hImageFormat, const NWChar * szFileName, NUInt flags, HNImageWriter * phWriter);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NImageFormatOpenWriterToFile(HNImageFormat hImageFormat, const NChar * szFileName, NUInt flags, HNImageWriter * phWriter);
#endif
#define NImageFormatOpenWriterToFile N_FUNC_AW(NImageFormatOpenWriterToFile)

NResult N_API NImageFormatOpenWriterToMemory(HNImageFormat hImageFormat, NUInt flags, HNImageWriter * phWriter);
NResult N_API NImageFormatOpenWriterToStream(HNImageFormat hImageFormat, HNStream hStream, NUInt flags, HNImageWriter * phWriter);

NResult N_API NImageFormatGetNameN(HNImageFormat hImageFormat, HNString * phValue);
#ifndef N_NO_ANSI_FUNC
N_DEPRECATED("function is deprecated, use NImageFormatGetNameN instead")
NResult N_API NImageFormatGetNameExA(HNImageFormat hImageFormat, NAChar * szValue, NInt valueSize);
#endif
#ifndef N_NO_UNICODE
N_DEPRECATED("function is deprecated, use NImageFormatGetNameN instead")
NResult N_API NImageFormatGetNameExW(HNImageFormat hImageFormat, NWChar * szValue, NInt valueSize);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NImageFormatGetNameEx(HNImageFormat hImageFormat, NChar * szValue, NInt valueSize);
#endif
#define NImageFormatGetNameEx N_FUNC_AW(NImageFormatGetNameEx)

NResult N_API NImageFormatGetDefaultFileExtensionN(HNImageFormat hImageFormat, HNString * phValue);
#ifndef N_NO_ANSI_FUNC
N_DEPRECATED("function is deprecated, use NImageFormatGetDefaultFileExtensionN instead")
NResult N_API NImageFormatGetDefaultFileExtensionExA(HNImageFormat hImageFormat, NAChar * szValue, NInt valueSize);
#endif
#ifndef N_NO_UNICODE
N_DEPRECATED("function is deprecated, use NImageFormatGetDefaultFileExtensionN instead")
NResult N_API NImageFormatGetDefaultFileExtensionExW(HNImageFormat hImageFormat, NWChar * szValue, NInt valueSize);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NImageFormatGetDefaultFileExtensionEx(HNImageFormat hImageFormat, NChar * szValue, NInt valueSize);
#endif
#define NImageFormatGetDefaultFileExtensionEx N_FUNC_AW(NImageFormatGetDefaultFileExtensionEx)

NResult N_API NImageFormatGetDefaultInternetMediaTypeN(HNImageFormat hImageFormat, HNString * phValue);
#ifndef N_NO_ANSI_FUNC
N_DEPRECATED("function is deprecated, use NImageFormatGetDefaultInternetMediaTypeN instead")
NResult N_API NImageFormatGetDefaultInternetMediaTypeA(HNImageFormat hImageFormat, NAChar * szValue, NInt valueSize);
#endif
#ifndef N_NO_UNICODE
N_DEPRECATED("function is deprecated, use NImageFormatGetDefaultInternetMediaTypeN instead")
NResult N_API NImageFormatGetDefaultInternetMediaTypeW(HNImageFormat hImageFormat, NWChar * szValue, NInt valueSize);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NImageFormatGetDefaultInternetMediaType(HNImageFormat hImageFormat, NChar * szValue, NInt valueSize);
#endif
#define NImageFormatGetDefaultInternetMediaType N_FUNC_AW(NImageFormatGetDefaultInternetMediaType)

NResult N_API NImageFormatGetFileFilterN(HNImageFormat hImageFormat, HNString * phValue);
#ifndef N_NO_ANSI_FUNC
N_DEPRECATED("function is deprecated, use NImageFormatGetFileFilterN instead")
NResult N_API NImageFormatGetFileFilterExA(HNImageFormat hImageFormat, NAChar * szValue, NInt valueSize);
#endif
#ifndef N_NO_UNICODE
N_DEPRECATED("function is deprecated, use NImageFormatGetFileFilterN instead")
NResult N_API NImageFormatGetFileFilterExW(HNImageFormat hImageFormat, NWChar * szValue, NInt valueSize);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NImageFormatGetFileFilterEx(HNImageFormat hImageFormat, NChar * szValue, NInt valueSize);
#endif
#define NImageFormatGetFileFilterEx N_FUNC_AW(NImageFormatGetFileFilterEx)

NResult N_API NImageFormatGetInternetMediaTypeN(HNImageFormat hImageFormat, HNString * phValue);
#ifndef N_NO_ANSI_FUNC
N_DEPRECATED("function is deprecated, use NImageFormatGetInternetMediaTypeN instead")
NResult N_API NImageFormatGetInternetMediaTypeA(HNImageFormat hImageFormat, NAChar * szValue, NInt valueSize);
#endif
#ifndef N_NO_UNICODE
N_DEPRECATED("function is deprecated, use NImageFormatGetInternetMediaTypeN instead")
NResult N_API NImageFormatGetInternetMediaTypeW(HNImageFormat hImageFormat, NWChar * szValue, NInt valueSize);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NImageFormatGetInternetMediaType(HNImageFormat hImageFormat, NChar * szValue, NInt valueSize);
#endif
#define NImageFormatGetInternetMediaType N_FUNC_AW(NImageFormatGetInternetMediaType)

NResult N_API NImageFormatCanRead(HNImageFormat hImageFormat, NBool * pValue);
NResult N_API NImageFormatCanWrite(HNImageFormat hImageFormat, NBool * pValue);
NResult N_API NImageFormatCanWriteMultiple(HNImageFormat hImageFormat, NBool * pValue);

#ifdef N_CPP
}
#endif

#endif // !N_IMAGE_FORMAT_H_INCLUDED
