#ifndef N_TEXT_READER_H_INCLUDED
#define N_TEXT_READER_H_INCLUDED

#include <Core/NObject.h>

#ifdef N_CPP
extern "C"
{
#endif

N_DECLARE_OBJECT_TYPE(NTextReader, NObject)

NResult N_API NTextReaderGetNull(HNTextReader * phValue);
NResult N_API NTextReaderSynchronized(HNTextReader hReader, HNTextReader * phValue);

#ifndef N_NO_ANSI_FUNC
NResult N_API NTextReaderPeekCharA(HNTextReader hReader, NInt * pValue);
#endif
#ifndef N_NO_UNICODE
NResult N_API NTextReaderPeekCharW(HNTextReader hReader, NInt * pValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NTextReaderPeekChar(HNTextReader hReader, NInt * pValue);
#endif
#define NTextReaderPeekChar N_FUNC_AW(NTextReaderPeekChar)

#ifndef N_NO_ANSI_FUNC
NResult N_API NTextReaderReadCharA(HNTextReader hReader, NInt * pValue);
#endif
#ifndef N_NO_UNICODE
NResult N_API NTextReaderReadCharW(HNTextReader hReader, NInt * pValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NTextReaderReadChar(HNTextReader hReader, NInt * pValue);
#endif
#define NTextReaderReadChar N_FUNC_AW(NTextReaderReadChar)

#ifndef N_NO_ANSI_FUNC
NResult N_API NTextReaderReadCharsA(HNTextReader hReader, NAChar * szBuffer, NInt count, NInt * pCharsRead);
#endif
#ifndef N_NO_UNICODE
NResult N_API NTextReaderReadCharsW(HNTextReader hReader, NWChar * szBuffer, NInt count, NInt * pCharsRead);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NTextReaderReadChars(HNTextReader hReader, NChar * szBuffer, NInt count, NInt * pCharsRead);
#endif
#define NTextReaderReadChars N_FUNC_AW(NTextReaderReadChars)

NResult N_API NTextReaderReadLine(HNTextReader hReader, HNString * phValue);
NResult N_API NTextReaderReadToEnd(HNTextReader hReader, HNString * phValue);

#ifdef N_CPP
}
#endif

#endif // !N_TEXT_READER_H_INCLUDED
