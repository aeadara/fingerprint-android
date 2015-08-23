#ifndef N_CONSOLE_H_INCLUDED
#define N_CONSOLE_H_INCLUDED

#include <IO/NTextReader.h>
#include <IO/NTextWriter.h>

#ifdef N_CPP
extern "C"
{
#endif

N_DECLARE_STATIC_OBJECT_TYPE(NConsole)

NResult N_API NConsoleGetIn(HNTextReader * phValue);
NResult N_API NConsoleGetOut(HNTextWriter * phValue);
NResult N_API NConsoleGetError(HNTextWriter * phValue);

NResult N_API NConsoleSetIn(HNTextReader hValue);
NResult N_API NConsoleSetOut(HNTextWriter hValue);
NResult N_API NConsoleSetError(HNTextWriter hValue);

#ifndef N_NO_ANSI_FUNC
NResult N_API NConsoleReadCharA(NInt * pValue);
#endif
#ifndef N_NO_UNICODE
NResult N_API NConsoleReadCharW(NInt * pValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NConsoleReadChar(NInt * pValue);
#endif
#define NConsoleReadChar N_FUNC_AW(NConsoleReadChar)

NResult N_API NConsoleReadLine(HNString * phValue);

#ifndef N_NO_ANSI_FUNC
NResult N_API NConsoleWriteCharA(NAChar value);
#endif
#ifndef N_NO_UNICODE
NResult N_API NConsoleWriteCharW(NWChar value);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NConsoleWriteChar(NChar value);
#endif
#define NConsoleWriteChar N_FUNC_AW(NConsoleWriteChar)

#ifndef N_NO_ANSI_FUNC
NResult N_API NConsoleWriteCharsA(const NAChar * arValue, NInt valueLength);
#endif
#ifndef N_NO_UNICODE
NResult N_API NConsoleWriteCharsW(const NWChar * arValue, NInt valueLength);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NConsoleWriteChars(const NChar * arValue, NInt valueLength);
#endif
#define NConsoleWriteChars N_FUNC_AW(NConsoleWriteChars)

NResult N_API NConsoleWriteUInt32(NUInt value);
NResult N_API NConsoleWriteInt32(NInt value);
NResult N_API NConsoleWriteUInt64(NULong value);
NResult N_API NConsoleWriteInt64(NLong value);
NResult N_API NConsoleWriteSingle(NFloat value);
NResult N_API NConsoleWriteDouble(NDouble value);
NResult N_API NConsoleWriteBoolean(NBool value);
NResult N_API NConsoleWriteSizeType(NSizeType value);
NResult N_API NConsoleWriteSSizeType(NSSizeType value);
NResult N_API NConsoleWritePointer(const void * value);
NResult N_API NConsoleWriteResult(NResult value);
NResult N_API NConsoleWriteValue(HNType hType, const void * pValue, NSizeType valueSize);
NResult N_API NConsoleWriteValueP(NTypeOfProc pTypeOf, const void * pValue, NSizeType valueSize);
NResult N_API NConsoleWriteObject(HNObject hObject);

NResult N_API NConsoleWriteN(HNString hValue);
#ifndef N_NO_ANSI_FUNC
NResult N_API NConsoleWriteA(const NAChar * szValue);
#endif
#ifndef N_NO_UNICODE
NResult N_API NConsoleWriteW(const NWChar * szValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NConsoleWrite(const NChar * szValue);
#endif
#define NConsoleWrite N_FUNC_AW(NConsoleWrite)

NResult N_API NConsoleWriteFormatN(HNString hFormat, ...);
#ifndef N_NO_ANSI_FUNC
NResult N_API NConsoleWriteFormatA(const NAChar * szFormat, ...);
#endif
#ifndef N_NO_UNICODE
NResult N_API NConsoleWriteFormatW(const NWChar * szFormat, ...);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NConsoleWriteFormat(const NChar * szFormat, ... multipleParameters);
#endif
#define NConsoleWriteFormat N_FUNC_AW(NConsoleWriteFormat)

NResult N_API NConsoleWriteFormatVAN(HNString hFormat, va_list args);
#ifndef N_NO_ANSI_FUNC
NResult N_API NConsoleWriteFormatVAA(const NAChar * szFormat, va_list args);
#endif
#ifndef N_NO_UNICODE
NResult N_API NConsoleWriteFormatVAW(const NWChar * szFormat, va_list args);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NConsoleWriteFormatVA(const NChar * szFormat, va_list args);
#endif
#define NConsoleWriteFormatVA N_FUNC_AW(NConsoleWriteFormatVA)

NResult N_API NConsoleWriteEmptyLine();

#ifndef N_NO_ANSI_FUNC
NResult N_API NConsoleWriteCharLineA(NAChar value);
#endif
#ifndef N_NO_UNICODE
NResult N_API NConsoleWriteCharLineW(NWChar value);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NConsoleWriteCharLine(NChar value);
#endif
#define NConsoleWriteCharLine N_FUNC_AW(NConsoleWriteCharLine)

#ifndef N_NO_ANSI_FUNC
NResult N_API NConsoleWriteCharsLineA(const NAChar * arValue, NInt valueLength);
#endif
#ifndef N_NO_UNICODE
NResult N_API NConsoleWriteCharsLineW(const NWChar * arValue, NInt valueLength);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NConsoleWriteCharsLine(const NChar * arValue, NInt valueLength);
#endif
#define NConsoleWriteCharsLine N_FUNC_AW(NConsoleWriteCharsLine)

NResult N_API NConsoleWriteUInt32Line(NUInt value);
NResult N_API NConsoleWriteInt32Line(NInt value);
NResult N_API NConsoleWriteUInt64Line(NULong value);
NResult N_API NConsoleWriteInt64Line(NLong value);
NResult N_API NConsoleWriteSingleLine(NFloat value);
NResult N_API NConsoleWriteDoubleLine(NDouble value);
NResult N_API NConsoleWriteBooleanLine(NBool value);
NResult N_API NConsoleWriteSizeTypeLine(NSizeType value);
NResult N_API NConsoleWriteSSizeTypeLine(NSSizeType value);
NResult N_API NConsoleWritePointerLine(const void * value);
NResult N_API NConsoleWriteResultLine(NResult value);
NResult N_API NConsoleWriteValueLine(HNType hType, const void * pValue, NSizeType valueSize);
NResult N_API NConsoleWriteValueLineP(NTypeOfProc pTypeOf, const void * pValue, NSizeType valueSize);
NResult N_API NConsoleWriteObjectLine(HNObject hObject);

NResult N_API NConsoleWriteLineN(HNString hValue);
#ifndef N_NO_ANSI_FUNC
NResult N_API NConsoleWriteLineA(const NAChar * szValue);
#endif
#ifndef N_NO_UNICODE
NResult N_API NConsoleWriteLineW(const NWChar * szValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NConsoleWriteLine(const NChar * szValue);
#endif
#define NConsoleWriteLine N_FUNC_AW(NConsoleWriteLine)

NResult N_API NConsoleWriteFormatLineN(HNString hFormat, ...);
#ifndef N_NO_ANSI_FUNC
NResult N_API NConsoleWriteFormatLineA(const NAChar * szFormat, ...);
#endif
#ifndef N_NO_UNICODE
NResult N_API NConsoleWriteFormatLineW(const NWChar * szFormat, ...);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NConsoleWriteFormatLine(const NChar * szFormat, ... multipleParameters);
#endif
#define NConsoleWriteFormatLine N_FUNC_AW(NConsoleWriteFormatLine)

NResult N_API NConsoleWriteFormatLineVAN(HNString hFormat, va_list args);
#ifndef N_NO_ANSI_FUNC
NResult N_API NConsoleWriteFormatLineVAA(const NAChar * szFormat, va_list args);
#endif
#ifndef N_NO_UNICODE
NResult N_API NConsoleWriteFormatLineVAW(const NWChar * szFormat, va_list args);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NConsoleWriteFormatLineVA(const NChar * szFormat, va_list args);
#endif
#define NConsoleWriteFormatLineVA N_FUNC_AW(NConsoleWriteFormatLineVA)

#ifdef N_CPP
}
#endif

#endif // !N_CONSOLE_H_INCLUDED
