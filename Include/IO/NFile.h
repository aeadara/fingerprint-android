#ifndef N_FILE_H_INCLUDED
#define N_FILE_H_INCLUDED

#include <IO/NFileStream.h>
#include <IO/NStreamReader.h>
#include <IO/NStreamWriter.h>

#ifdef N_CPP
extern "C"
{
#endif

typedef enum NFileAttributes_
{
	nfatNone = 0,
	nfatDirectory = 1
} NFileAttributes;

N_DECLARE_TYPE(NFileAttributes)

N_DECLARE_STATIC_OBJECT_TYPE(NFile)

NResult N_API NFileGetAttributesN(HNString hPath, NFileAttributes * pValue);
#ifndef N_NO_ANSI_FUNC
NResult N_API NFileGetAttributesA(const NAChar * szPath, NFileAttributes * pValue);
#endif
#ifndef N_NO_UNICODE
NResult N_API NFileGetAttributesW(const NWChar * szPath, NFileAttributes * pValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NFileGetAttributes(const NChar * szPath, NFileAttributes * pValue);
#endif
#define NFileGetAttributes N_FUNC_AW(NFileGetAttributes)

NResult N_API NFileExistsN(HNString hPath, NBool * pValue);
#ifndef N_NO_ANSI_FUNC
NResult N_API NFileExistsA(const NAChar * szPath, NBool * pValue);
#endif
#ifndef N_NO_UNICODE
NResult N_API NFileExistsW(const NWChar * szPath, NBool * pValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NFileExists(const NChar * szPath, NBool * pValue);
#endif
#define NFileExists N_FUNC_AW(NFileExists)

NResult N_API NFileDeleteN(HNString hPath);
#ifndef N_NO_ANSI_FUNC
NResult N_API NFileDeleteA(const NAChar * szPath);
#endif
#ifndef N_NO_UNICODE
NResult N_API NFileDeleteW(const NWChar * szPath);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NFileDelete(const NChar * szPath);
#endif
#define NFileDelete N_FUNC_AW(NFileDelete)

NResult N_API NFileOpenN(HNString hPath, NFileMode mode, HNFileStream * phStream);
#ifndef N_NO_ANSI_FUNC
NResult N_API NFileOpenA(const NAChar * szPath, NFileMode mode, HNFileStream * phStream);
#endif
#ifndef N_NO_UNICODE
NResult N_API NFileOpenW(const NWChar * szPath, NFileMode mode, HNFileStream * phStream);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NFileOpen(const NChar * szPath, NFileMode mode, HNFileStream * phStream);
#endif
#define NFileOpen N_FUNC_AW(NFileOpen)

NResult N_API NFileOpenWithAccessN(HNString hPath, NFileMode mode, NFileAccess access, HNFileStream * phStream);
#ifndef N_NO_ANSI_FUNC
NResult N_API NFileOpenWithAccessA(const NAChar * szPath, NFileMode mode, NFileAccess access, HNFileStream * phStream);
#endif
#ifndef N_NO_UNICODE
NResult N_API NFileOpenWithAccessW(const NWChar * szPath, NFileMode mode, NFileAccess access, HNFileStream * phStream);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NFileOpenWithAccess(const NChar * szPath, NFileMode mode, NFileAccess access, HNFileStream * phStream);
#endif
#define NFileOpenWithAccess N_FUNC_AW(NFileOpenWithAccess)

NResult N_API NFileOpenWithAccessAndShareN(HNString hPath, NFileMode mode, NFileAccess access, NFileShare share, HNFileStream * phStream);
#ifndef N_NO_ANSI_FUNC
NResult N_API NFileOpenWithAccessAndShareA(const NAChar * szPath, NFileMode mode, NFileAccess access, NFileShare share, HNFileStream * phStream);
#endif
#ifndef N_NO_UNICODE
NResult N_API NFileOpenWithAccessAndShareW(const NWChar * szPath, NFileMode mode, NFileAccess access, NFileShare share, HNFileStream * phStream);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NFileOpenWithAccessAndShare(const NChar * szPath, NFileMode mode, NFileAccess access, NFileShare share, HNFileStream * phStream);
#endif
#define NFileOpenWithAccessAndShare N_FUNC_AW(NFileOpenWithAccessAndShare)

NResult N_API NFileCreateN(HNString hPath, HNFileStream * phStream);
#ifndef N_NO_ANSI_FUNC
NResult N_API NFileCreateA(const NAChar * szPath, HNFileStream * phStream);
#endif
#ifndef N_NO_UNICODE
NResult N_API NFileCreateW(const NWChar * szPath, HNFileStream * phStream);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NFileCreate(const NChar * szPath, HNFileStream * phStream);
#endif
#define NFileCreate N_FUNC_AW(NFileCreate)

NResult N_API NFileCreateWithBufferSizeN(HNString hPath, NSizeType bufferSize, HNFileStream * phStream);
#ifndef N_NO_ANSI_FUNC
NResult N_API NFileCreateWithBufferSizeA(const NAChar * szPath, NSizeType bufferSize, HNFileStream * phStream);
#endif
#ifndef N_NO_UNICODE
NResult N_API NFileCreateWithBufferSizeW(const NWChar * szPath, NSizeType bufferSize, HNFileStream * phStream);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NFileCreateWithBufferSize(const NChar * szPath, NSizeType bufferSize, HNFileStream * phStream);
#endif
#define NFileCreateWithBufferSize N_FUNC_AW(NFileCreateWithBufferSize)

NResult N_API NFileOpenReadN(HNString hPath, HNFileStream * phStream);
#ifndef N_NO_ANSI_FUNC
NResult N_API NFileOpenReadA(const NAChar * szPath, HNFileStream * phStream);
#endif
#ifndef N_NO_UNICODE
NResult N_API NFileOpenReadW(const NWChar * szPath, HNFileStream * phStream);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NFileOpenRead(const NChar * szPath, HNFileStream * phStream);
#endif
#define NFileOpenRead N_FUNC_AW(NFileOpenRead)

NResult N_API NFileOpenWriteN(HNString hPath, HNFileStream * phStream);
#ifndef N_NO_ANSI_FUNC
NResult N_API NFileOpenWriteA(const NAChar * szPath, HNFileStream * phStream);
#endif
#ifndef N_NO_UNICODE
NResult N_API NFileOpenWriteW(const NWChar * szPath, HNFileStream * phStream);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NFileOpenWrite(const NChar * szPath, HNFileStream * phStream);
#endif
#define NFileOpenWrite N_FUNC_AW(NFileOpenWrite)

NResult N_API NFileReadAllBytesN(HNString hPath, HNBuffer * phContent);
#ifndef N_NO_ANSI_FUNC
NResult N_API NFileReadAllBytesCNA(const NAChar * szPath, HNBuffer * phContent);
#endif
#ifndef N_NO_UNICODE
NResult N_API NFileReadAllBytesCNW(const NWChar * szPath, HNBuffer * phContent);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NFileReadAllBytesCN(const NChar * szPath, HNBuffer * phContent);
#endif
#define NFileReadAllBytesCN N_FUNC_AW(NFileReadAllBytesCN)

NResult N_API NFileWriteAllBytesN(HNString hPath, HNBuffer hContent);
#ifndef N_NO_ANSI_FUNC
NResult N_API NFileWriteAllBytesCNA(const NAChar * szPath, HNBuffer hContent);
#endif
#ifndef N_NO_UNICODE
NResult N_API NFileWriteAllBytesCNW(const NWChar * szPath, HNBuffer hContent);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NFileWriteAllBytesCN(const NChar * szPath, HNBuffer hContent);
#endif
#define NFileWriteAllBytesCN N_FUNC_AW(NFileWriteAllBytesCN)

NResult N_API NFileWriteAllBytesPN(HNString hPath, const void * pContent, NSizeType contentSize);
#ifndef N_NO_ANSI_FUNC
NResult N_API NFileWriteAllBytesA(const NAChar * szPath, const void * pContent, NSizeType contentSize);
#endif
#ifndef N_NO_UNICODE
NResult N_API NFileWriteAllBytesW(const NWChar * szPath, const void * pContent, NSizeType contentSize);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NFileWriteAllBytes(const NChar * szPath, const void * pContent, NSizeType contentSize);
#endif
#define NFileWriteAllBytes N_FUNC_AW(NFileWriteAllBytes)

NResult N_API NFileOpenTextN(HNString hPath, HNStreamReader * phReader);
#ifndef N_NO_ANSI_FUNC
NResult N_API NFileOpenTextA(const NAChar * szPath, HNStreamReader * phReader);
#endif
#ifndef N_NO_UNICODE
NResult N_API NFileOpenTextW(const NWChar * szPath, HNStreamReader * phReader);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NFileOpenText(const NChar * szPath, HNStreamReader * phReader);
#endif
#define NFileOpenText N_FUNC_AW(NFileOpenText)

NResult N_API NFileAppendTextN(HNString hPath, HNStreamWriter * phWriter);
#ifndef N_NO_ANSI_FUNC
NResult N_API NFileAppendTextA(const NAChar * szPath, HNStreamWriter * phWriter);
#endif
#ifndef N_NO_UNICODE
NResult N_API NFileAppendTextW(const NWChar * szPath, HNStreamWriter * phWriter);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NFileAppendText(const NChar * szPath, HNStreamWriter * phWriter);
#endif
#define NFileAppendText N_FUNC_AW(NFileAppendText)

NResult N_API NFileCreateTextN(HNString hPath, HNStreamWriter * phWriter);
#ifndef N_NO_ANSI_FUNC
NResult N_API NFileCreateTextA(const NAChar * szPath, HNStreamWriter * phWriter);
#endif
#ifndef N_NO_UNICODE
NResult N_API NFileCreateTextW(const NWChar * szPath, HNStreamWriter * phWriter);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NFileCreateText(const NChar * szPath, HNStreamWriter * phWriter);
#endif
#define NFileCreateText N_FUNC_AW(NFileCreateText)

NResult N_API NFileReadAllLinesN(HNString hPath, HNString * * parhContent, NInt * pContentLength);
#ifndef N_NO_ANSI_FUNC
NResult N_API NFileReadAllLinesCNA(const NAChar * szPath, HNString * * parhContent, NInt * pContentLength);
#endif
#ifndef N_NO_UNICODE
NResult N_API NFileReadAllLinesCNW(const NWChar * szPath, HNString * * parhContent, NInt * pContentLength);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NFileReadAllLinesCN(const NChar * szPath, HNString * * parhContent, NInt * pContentLength);
#endif
#define NFileReadAllLinesCN N_FUNC_AW(NFileReadAllLinesCN)

NResult N_API NFileReadAllLinesWithEncodingN(HNString hPath, NEncoding encoding, NBool detectEncodingFromByteOrderMarks, HNString * * parhContent, NInt * pContentLength);
#ifndef N_NO_ANSI_FUNC
NResult N_API NFileReadAllLinesWithEncodingCNA(const NAChar * szPath, NEncoding encoding, NBool detectEncodingFromByteOrderMarks, HNString * * parhContent, NInt * pContentLength);
#endif
#ifndef N_NO_UNICODE
NResult N_API NFileReadAllLinesWithEncodingCNW(const NWChar * szPath, NEncoding encoding, NBool detectEncodingFromByteOrderMarks, HNString * * parhContent, NInt * pContentLength);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NFileReadAllLinesWithEncodingCN(const NChar * szPath, NEncoding encoding, NBool detectEncodingFromByteOrderMarks, HNString * * parhContent, NInt * pContentLength);
#endif
#define NFileReadAllLinesWithEncodingCN N_FUNC_AW(NFileReadAllLinesWithEncodingCN)

NResult N_API NFileReadAllTextN(HNString hPath, HNString * phContent);
#ifndef N_NO_ANSI_FUNC
NResult N_API NFileReadAllTextCNA(const NAChar * szPath, HNString * phContent);
#endif
#ifndef N_NO_UNICODE
NResult N_API NFileReadAllTextCNW(const NWChar * szPath, HNString * phContent);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NFileReadAllTextCN(const NChar * szPath, HNString * phContent);
#endif
#define NFileReadAllTextCN N_FUNC_AW(NFileReadAllTextCN)

NResult N_API NFileReadAllTextWithEncodingN(HNString hPath, NEncoding encoding, NBool detectEncodingFromByteOrderMarks, HNString * phContent);
#ifndef N_NO_ANSI_FUNC
NResult N_API NFileReadAllTextWithEncodingCNA(const NAChar * szPath, NEncoding encoding, NBool detectEncodingFromByteOrderMarks, HNString * phContent);
#endif
#ifndef N_NO_UNICODE
NResult N_API NFileReadAllTextWithEncodingCNW(const NWChar * szPath, NEncoding encoding, NBool detectEncodingFromByteOrderMarks, HNString * phContent);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NFileReadAllTextWithEncodingCN(const NChar * szPath, NEncoding encoding, NBool detectEncodingFromByteOrderMarks, HNString * phContent);
#endif
#define NFileReadAllTextWithEncodingCN N_FUNC_AW(NFileReadAllTextWithEncodingCN)

NResult N_API NFileAppendAllLinesN(HNString hPath, const HNString * arhContent, NInt contentLength);
#ifndef N_NO_ANSI_FUNC
NResult N_API NFileAppendAllLinesPNA(HNString hPath, const NAChar * * arszContent, NInt contentLength);
#endif
#ifndef N_NO_UNICODE
NResult N_API NFileAppendAllLinesPNW(HNString hPath, const NWChar * * arszContent, NInt contentLength);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NFileAppendAllLinesPN(HNString hPath, const NChar * * arszContent, NInt contentLength);
#endif
#define NFileAppendAllLinesPN N_FUNC_AW(NFileAppendAllLinesPN)
#ifndef N_NO_ANSI_FUNC
NResult N_API NFileAppendAllLinesA(const NAChar * szPath, const NAChar * * arszContent, NInt contentLength);
#endif
#ifndef N_NO_UNICODE
NResult N_API NFileAppendAllLinesW(const NWChar * szPath, const NWChar * * arszContent, NInt contentLength);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NFileAppendAllLines(const NChar * szPath, const NChar * * arszContent, NInt contentLength);
#endif
#define NFileAppendAllLines N_FUNC_AW(NFileAppendAllLines)

NResult N_API NFileAppendAllLinesWithEncodingN(HNString hPath, const HNString * arhContent, NInt contentLength, NEncoding encoding);
#ifndef N_NO_ANSI_FUNC
NResult N_API NFileAppendAllLinesWithEncodingPNA(HNString hPath, const NAChar * * arszContent, NInt contentLength, NEncoding encoding);
#endif
#ifndef N_NO_UNICODE
NResult N_API NFileAppendAllLinesWithEncodingPNW(HNString hPath, const NWChar * * arszContent, NInt contentLength, NEncoding encoding);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NFileAppendAllLinesWithEncodingPN(HNString hPath, const NChar * * arszContent, NInt contentLength, NEncoding encoding);
#endif
#define NFileAppendAllLinesWithEncodingPN N_FUNC_AW(NFileAppendAllLinesWithEncodingPN)
#ifndef N_NO_ANSI_FUNC
NResult N_API NFileAppendAllLinesWithEncodingA(const NAChar * szPath, const NAChar * * arszContent, NInt contentLength, NEncoding encoding);
#endif
#ifndef N_NO_UNICODE
NResult N_API NFileAppendAllLinesWithEncodingW(const NWChar * szPath, const NWChar * * arszContent, NInt contentLength, NEncoding encoding);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NFileAppendAllLinesWithEncoding(const NChar * szPath, const NChar * * arszContent, NInt contentLength, NEncoding encoding);
#endif
#define NFileAppendAllLinesWithEncoding N_FUNC_AW(NFileAppendAllLinesWithEncoding)

NResult N_API NFileAppendAllTextN(HNString hPath, HNString hContent);
#ifndef N_NO_ANSI_FUNC
NResult N_API NFileAppendAllTextPNA(HNString hPath, const NAChar * szContent);
#endif
#ifndef N_NO_UNICODE
NResult N_API NFileAppendAllTextPNW(HNString hPath, const NWChar * szContent);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NFileAppendAllTextPN(HNString hPath, const NChar * szContent);
#endif
#define NFileAppendAllTextPN N_FUNC_AW(NFileAppendAllTextPN)
#ifndef N_NO_ANSI_FUNC
NResult N_API NFileAppendAllTextA(const NAChar * szPath, const NAChar * szContent);
#endif
#ifndef N_NO_UNICODE
NResult N_API NFileAppendAllTextW(const NWChar * szPath, const NWChar * szContent);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NFileAppendAllText(const NChar * szPath, const NChar * szContent);
#endif
#define NFileAppendAllText N_FUNC_AW(NFileAppendAllText)

NResult N_API NFileAppendAllTextWithEncodingN(HNString hPath, HNString hContent, NEncoding encoding);
#ifndef N_NO_ANSI_FUNC
NResult N_API NFileAppendAllTextWithEncodingPNA(HNString hPath, const NAChar * szContent, NEncoding encoding);
#endif
#ifndef N_NO_UNICODE
NResult N_API NFileAppendAllTextWithEncodingPNW(HNString hPath, const NWChar * szContent, NEncoding encoding);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NFileAppendAllTextWithEncodingPN(HNString hPath, const NChar * szContent, NEncoding encoding);
#endif
#define NFileAppendAllTextWithEncodingPN N_FUNC_AW(NFileAppendAllTextWithEncodingPN)
#ifndef N_NO_ANSI_FUNC
NResult N_API NFileAppendAllTextWithEncodingA(const NAChar * szPath, const NAChar * szContent, NEncoding encoding);
#endif
#ifndef N_NO_UNICODE
NResult N_API NFileAppendAllTextWithEncodingW(const NWChar * szPath, const NWChar * szContent, NEncoding encoding);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NFileAppendAllTextWithEncoding(const NChar * szPath, const NChar * szContent, NEncoding encoding);
#endif
#define NFileAppendAllTextWithEncoding N_FUNC_AW(NFileAppendAllTextWithEncoding)

NResult N_API NFileWriteAllLinesN(HNString hPath, const HNString * arhContent, NInt contentLength);
#ifndef N_NO_ANSI_FUNC
NResult N_API NFileWriteAllLinesPNA(HNString hPath, const NAChar * * arszContent, NInt contentLength);
#endif
#ifndef N_NO_UNICODE
NResult N_API NFileWriteAllLinesPNW(HNString hPath, const NWChar * * arszContent, NInt contentLength);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NFileWriteAllLinesPN(HNString hPath, const NChar * * arszContent, NInt contentLength);
#endif
#define NFileWriteAllLinesPN N_FUNC_AW(NFileWriteAllLinesPN)
#ifndef N_NO_ANSI_FUNC
NResult N_API NFileWriteAllLinesA(const NAChar * szPath, const NAChar * * arszContent, NInt contentLength);
#endif
#ifndef N_NO_UNICODE
NResult N_API NFileWriteAllLinesW(const NWChar * szPath, const NWChar * * arszContent, NInt contentLength);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NFileWriteAllLines(const NChar * szPath, const NChar * * arszContent, NInt contentLength);
#endif
#define NFileWriteAllLines N_FUNC_AW(NFileWriteAllLines)

NResult N_API NFileWriteAllLinesWithEncodingN(HNString hPath, const HNString * arhContent, NInt contentLength, NEncoding encoding);
#ifndef N_NO_ANSI_FUNC
NResult N_API NFileWriteAllLinesWithEncodingPNA(HNString hPath, const NAChar * * arszContent, NInt contentLength, NEncoding encoding);
#endif
#ifndef N_NO_UNICODE
NResult N_API NFileWriteAllLinesWithEncodingPNW(HNString hPath, const NWChar * * arszContent, NInt contentLength, NEncoding encoding);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NFileWriteAllLinesWithEncodingPN(HNString hPath, const NChar * * arszContent, NInt contentLength, NEncoding encoding);
#endif
#define NFileWriteAllLinesWithEncodingPN N_FUNC_AW(NFileWriteAllLinesWithEncodingPN)
#ifndef N_NO_ANSI_FUNC
NResult N_API NFileWriteAllLinesWithEncodingA(const NAChar * szPath, const NAChar * * arszContent, NInt contentLength, NEncoding encoding);
#endif
#ifndef N_NO_UNICODE
NResult N_API NFileWriteAllLinesWithEncodingW(const NWChar * szPath, const NWChar * * arszContent, NInt contentLength, NEncoding encoding);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NFileWriteAllLinesWithEncoding(const NChar * szPath, const NChar * * arszContent, NInt contentLength, NEncoding encoding);
#endif
#define NFileWriteAllLinesWithEncoding N_FUNC_AW(NFileWriteAllLinesWithEncoding)

NResult N_API NFileWriteAllTextN(HNString hPath, HNString hContent);
#ifndef N_NO_ANSI_FUNC
NResult N_API NFileWriteAllTextPNA(HNString hPath, const NAChar * szContent);
#endif
#ifndef N_NO_UNICODE
NResult N_API NFileWriteAllTextPNW(HNString hPath, const NWChar * szContent);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NFileWriteAllTextPN(HNString hPath, const NChar * szContent);
#endif
#define NFileWriteAllTextPN N_FUNC_AW(NFileWriteAllTextPN)
#ifndef N_NO_ANSI_FUNC
NResult N_API NFileWriteAllTextA(const NAChar * szPath, const NAChar * szContent);
#endif
#ifndef N_NO_UNICODE
NResult N_API NFileWriteAllTextW(const NWChar * szPath, const NWChar * szContent);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NFileWriteAllText(const NChar * szPath, const NChar * szContent);
#endif
#define NFileWriteAllText N_FUNC_AW(NFileWriteAllText)
#ifndef N_NO_ANSI_FUNC
NResult N_API NFileWriteAllTextCNA(const NAChar * szPath, HNString hContent);
#endif
#ifndef N_NO_UNICODE
NResult N_API NFileWriteAllTextCNW(const NWChar * szPath, HNString hContent);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NFileWriteAllTextCN(const NChar * szPath, HNString hContent);
#endif
#define NFileWriteAllTextCN N_FUNC_AW(NFileWriteAllTextCN)

NResult N_API NFileWriteAllTextWithEncodingN(HNString hPath, HNString hContent, NEncoding encoding);
#ifndef N_NO_ANSI_FUNC
NResult N_API NFileWriteAllTextWithEncodingPNA(HNString hPath, const NAChar * szContent, NEncoding encoding);
#endif
#ifndef N_NO_UNICODE
NResult N_API NFileWriteAllTextWithEncodingPNW(HNString hPath, const NWChar * szContent, NEncoding encoding);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NFileWriteAllTextWithEncodingPN(HNString hPath, const NChar * szContent, NEncoding encoding);
#endif
#define NFileWriteAllTextWithEncodingPN N_FUNC_AW(NFileWriteAllTextWithEncodingPN)
#ifndef N_NO_ANSI_FUNC
NResult N_API NFileWriteAllTextWithEncodingA(const NAChar * szPath, const NAChar * szContent, NEncoding encoding);
#endif
#ifndef N_NO_UNICODE
NResult N_API NFileWriteAllTextWithEncodingW(const NWChar * szPath, const NWChar * szContent, NEncoding encoding);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NFileWriteAllTextWithEncoding(const NChar * szPath, const NChar * szContent, NEncoding encoding);
#endif
#define NFileWriteAllTextWithEncoding N_FUNC_AW(NFileWriteAllTextWithEncoding)

#ifdef N_CPP
}
#endif

#endif // !N_FILE_H_INCLUDED
