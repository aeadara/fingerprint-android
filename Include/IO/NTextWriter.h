#ifndef N_TEXT_WRITER_H_INCLUDED
#define N_TEXT_WRITER_H_INCLUDED

#include <Core/NObject.h>
#include <Text/NEncoding.h>

#ifdef N_CPP
extern "C"
{
#endif

N_DECLARE_OBJECT_TYPE(NTextWriter, NObject)

NResult N_API NTextWriterGetNull(HNTextWriter * phValue);
NResult N_API NTextWriterSynchronized(HNTextWriter hWriter, HNTextWriter * phValue);

NResult N_API NTextWriterGetEncoding(HNTextWriter hWriter, NEncoding * pValue);
NResult N_API NTextWriterGetNewLine(HNTextWriter hWriter, HNString * phValue);

NResult N_API NTextWriterSetNewLineN(HNTextWriter hWriter, HNString hValue);
#ifndef N_NO_ANSI_FUNC
NResult N_API NTextWriterSetNewLineA(HNTextWriter hWriter, const NAChar * szValue);
#endif
#ifndef N_NO_UNICODE
NResult N_API NTextWriterSetNewLineW(HNTextWriter hWriter, const NWChar * szValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NTextWriterSetNewLine(HNTextWriter hWriter, const NChar * szValue);
#endif
#define NTextWriterSetNewLine N_FUNC_AW(NTextWriterSetNewLine)

NResult N_API NTextWriterFlush(HNTextWriter hWriter);

#ifndef N_NO_ANSI_FUNC
NResult N_API NTextWriterWriteCharA(HNTextWriter hWriter, NAChar value);
#endif
#ifndef N_NO_UNICODE
NResult N_API NTextWriterWriteCharW(HNTextWriter hWriter, NWChar value);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NTextWriterWriteChar(HNTextWriter hWriter, NChar value);
#endif
#define NTextWriterWriteChar N_FUNC_AW(NTextWriterWriteChar)

#ifndef N_NO_ANSI_FUNC
NResult N_API NTextWriterWriteCharsA(HNTextWriter hWriter, const NAChar * arValue, NInt valueLength);
#endif
#ifndef N_NO_UNICODE
NResult N_API NTextWriterWriteCharsW(HNTextWriter hWriter, const NWChar * arValue, NInt valueLength);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NTextWriterWriteChars(HNTextWriter hWriter, const NChar * arValue, NInt valueLength);
#endif
#define NTextWriterWriteChars N_FUNC_AW(NTextWriterWriteChars)

NResult N_API NTextWriterWriteUInt32(HNTextWriter hWriter, NUInt value);
NResult N_API NTextWriterWriteInt32(HNTextWriter hWriter, NInt value);
NResult N_API NTextWriterWriteUInt64(HNTextWriter hWriter, NULong value);
NResult N_API NTextWriterWriteInt64(HNTextWriter hWriter, NLong value);
NResult N_API NTextWriterWriteSingle(HNTextWriter hWriter, NFloat value);
NResult N_API NTextWriterWriteDouble(HNTextWriter hWriter, NDouble value);
NResult N_API NTextWriterWriteBoolean(HNTextWriter hWriter, NBool value);
NResult N_API NTextWriterWriteSizeType(HNTextWriter hWriter, NSizeType value);
NResult N_API NTextWriterWriteSSizeType(HNTextWriter hWriter, NSSizeType value);
NResult N_API NTextWriterWritePointer(HNTextWriter hWriter, const void * value);
NResult N_API NTextWriterWriteResult(HNTextWriter hWriter, NResult value);
NResult N_API NTextWriterWriteValue(HNTextWriter hWriter, HNType hType, const void * pValue, NSizeType valueSize);
NResult N_API NTextWriterWriteValueP(HNTextWriter hWriter, NTypeOfProc pTypeOf, const void * pValue, NSizeType valueSize);
NResult N_API NTextWriterWriteObject(HNTextWriter hWriter, HNObject hObject);

NResult N_API NTextWriterWriteN(HNTextWriter hWriter, HNString hValue);
#ifndef N_NO_ANSI_FUNC
NResult N_API NTextWriterWriteA(HNTextWriter hWriter, const NAChar * szValue);
#endif
#ifndef N_NO_UNICODE
NResult N_API NTextWriterWriteW(HNTextWriter hWriter, const NWChar * szValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NTextWriterWrite(HNTextWriter hWriter, const NChar * szValue);
#endif
#define NTextWriterWrite N_FUNC_AW(NTextWriterWrite)

NResult N_API NTextWriterWriteFormatN(HNTextWriter hWriter, HNString hFormat, ...);
#ifndef N_NO_ANSI_FUNC
NResult N_API NTextWriterWriteFormatA(HNTextWriter hWriter, const NAChar * szFormat, ...);
#endif
#ifndef N_NO_UNICODE
NResult N_API NTextWriterWriteFormatW(HNTextWriter hWriter, const NWChar * szFormat, ...);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NTextWriterWriteFormat(HNTextWriter hWriter, const NChar * szFormat, ... multipleParameters);
#endif
#define NTextWriterWriteFormat N_FUNC_AW(NTextWriterWriteFormat)

NResult N_API NTextWriterWriteFormatVAN(HNTextWriter hWriter, HNString hFormat, va_list args);
#ifndef N_NO_ANSI_FUNC
NResult N_API NTextWriterWriteFormatVAA(HNTextWriter hWriter, const NAChar * szFormat, va_list args);
#endif
#ifndef N_NO_UNICODE
NResult N_API NTextWriterWriteFormatVAW(HNTextWriter hWriter, const NWChar * szFormat, va_list args);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NTextWriterWriteFormatVA(HNTextWriter hWriter, const NChar * szFormat, va_list args);
#endif
#define NTextWriterWriteFormatVA N_FUNC_AW(NTextWriterWriteFormatVA)

NResult N_API NTextWriterWriteEmptyLine(HNTextWriter hWriter);

#ifndef N_NO_ANSI_FUNC
NResult N_API NTextWriterWriteCharLineA(HNTextWriter hWriter, NAChar value);
#endif
#ifndef N_NO_UNICODE
NResult N_API NTextWriterWriteCharLineW(HNTextWriter hWriter, NWChar value);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NTextWriterWriteCharLine(HNTextWriter hWriter, NChar value);
#endif
#define NTextWriterWriteCharLine N_FUNC_AW(NTextWriterWriteCharLine)

#ifndef N_NO_ANSI_FUNC
NResult N_API NTextWriterWriteCharsLineA(HNTextWriter hWriter, const NAChar * arValue, NInt valueLength);
#endif
#ifndef N_NO_UNICODE
NResult N_API NTextWriterWriteCharsLineW(HNTextWriter hWriter, const NWChar * arValue, NInt valueLength);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NTextWriterWriteCharsLine(HNTextWriter hWriter, const NChar * arValue, NInt valueLength);
#endif
#define NTextWriterWriteCharsLine N_FUNC_AW(NTextWriterWriteCharsLine)

NResult N_API NTextWriterWriteUInt32Line(HNTextWriter hWriter, NUInt value);
NResult N_API NTextWriterWriteInt32Line(HNTextWriter hWriter, NInt value);
NResult N_API NTextWriterWriteUInt64Line(HNTextWriter hWriter, NULong value);
NResult N_API NTextWriterWriteInt64Line(HNTextWriter hWriter, NLong value);
NResult N_API NTextWriterWriteSingleLine(HNTextWriter hWriter, NFloat value);
NResult N_API NTextWriterWriteDoubleLine(HNTextWriter hWriter, NDouble value);
NResult N_API NTextWriterWriteBooleanLine(HNTextWriter hWriter, NBool value);
NResult N_API NTextWriterWriteSizeTypeLine(HNTextWriter hWriter, NSizeType value);
NResult N_API NTextWriterWriteSSizeTypeLine(HNTextWriter hWriter, NSSizeType value);
NResult N_API NTextWriterWritePointerLine(HNTextWriter hWriter, const void * value);
NResult N_API NTextWriterWriteResultLine(HNTextWriter hWriter, NResult value);
NResult N_API NTextWriterWriteValueLine(HNTextWriter hWriter, HNType hType, const void * pValue, NSizeType valueSize);
NResult N_API NTextWriterWriteValueLineP(HNTextWriter hWriter, NTypeOfProc pTypeOf, const void * pValue, NSizeType valueSize);
NResult N_API NTextWriterWriteObjectLine(HNTextWriter hWriter, HNObject hObject);

NResult N_API NTextWriterWriteLineN(HNTextWriter hWriter, HNString hValue);
#ifndef N_NO_ANSI_FUNC
NResult N_API NTextWriterWriteLineA(HNTextWriter hWriter, const NAChar * szValue);
#endif
#ifndef N_NO_UNICODE
NResult N_API NTextWriterWriteLineW(HNTextWriter hWriter, const NWChar * szValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NTextWriterWriteLine(HNTextWriter hWriter, const NChar * szValue);
#endif
#define NTextWriterWriteLine N_FUNC_AW(NTextWriterWriteLine)

NResult N_API NTextWriterWriteFormatLineN(HNTextWriter hWriter, HNString hFormat, ...);
#ifndef N_NO_ANSI_FUNC
NResult N_API NTextWriterWriteFormatLineA(HNTextWriter hWriter, const NAChar * szFormat, ...);
#endif
#ifndef N_NO_UNICODE
NResult N_API NTextWriterWriteFormatLineW(HNTextWriter hWriter, const NWChar * szFormat, ...);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NTextWriterWriteFormatLine(HNTextWriter hWriter, const NChar * szFormat, ... multipleParameters);
#endif
#define NTextWriterWriteFormatLine N_FUNC_AW(NTextWriterWriteFormatLine)

NResult N_API NTextWriterWriteFormatLineVAN(HNTextWriter hWriter, HNString hFormat, va_list args);
#ifndef N_NO_ANSI_FUNC
NResult N_API NTextWriterWriteFormatLineVAA(HNTextWriter hWriter, const NAChar * szFormat, va_list args);
#endif
#ifndef N_NO_UNICODE
NResult N_API NTextWriterWriteFormatLineVAW(HNTextWriter hWriter, const NWChar * szFormat, va_list args);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NTextWriterWriteFormatLineVA(HNTextWriter hWriter, const NChar * szFormat, va_list args);
#endif
#define NTextWriterWriteFormatLineVA N_FUNC_AW(NTextWriterWriteFormatLineVA)

#ifdef N_CPP
}
#endif

#endif // !N_TEXT_WRITER_H_INCLUDED
