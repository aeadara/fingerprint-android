#ifndef N_ERROR_H_INCLUDED
#define N_ERROR_H_INCLUDED

#include <Core/NObject.h>

#ifdef N_CPP
extern "C"
{
#endif

#define N_OK                               0
#define N_E_FAILED                        -1
  #define N_E_CORE                        -2
    #define N_E_ABANDONED_MUTEX          -25
    #define N_E_AGGREGATE                -33
    #define N_E_ARGUMENT                 -10
      #define N_E_ARGUMENT_NULL          -11
      #define N_E_ARGUMENT_OUT_OF_RANGE  -12
      #define N_E_INVALID_ENUM_ARGUMENT  -16
    #define N_E_ARITHMETIC               -17
      #define N_E_OVERFLOW                -8
    #define N_E_BAD_IMAGE_FORMAT         -26
    #define N_E_DLL_NOT_FOUND            -27
    #define N_E_ENTRY_POINT_NOT_FOUND    -28
    #define N_E_FORMAT                   -13
      #define N_E_FILE_FORMAT            -29
    #define N_E_INDEX_OUT_OF_RANGE        -9
    #define N_E_INVALID_CAST             -18
    #define N_E_INVALID_OPERATION         -7
    #define N_E_IO                       -14
      #define N_E_DIRECTORY_NOT_FOUND    -19
      #define N_E_DRIVE_NOT_FOUND        -20
      #define N_E_END_OF_STREAM          -15
      #define N_E_FILE_NOT_FOUND         -21
      #define N_E_FILE_LOAD              -22
      #define N_E_PATH_TOO_LONG          -23
      #define N_E_SOCKET                 -31
    #define N_E_KEY_NOT_FOUND            -32
    #define N_E_NOT_IMPLEMENTED           -5
    #define N_E_NOT_SUPPORTED             -6
    #define N_E_NULL_REFERENCE            -3
    #define N_E_OPERATION_CANCELED       -34
    #define N_E_OUT_OF_MEMORY             -4
    #define N_E_SECURITY                 -24
    #define N_E_TIMEOUT                  -30

    #define N_E_EXTERNAL                 -90
      #define N_E_CLR                    -93
      #define N_E_COM                    -92
      #define N_E_CPP                    -96
      #define N_E_JVM                    -97
      #define N_E_MAC                    -95
      #define N_E_SYS                    -94
      #define N_E_WIN32                  -91

    #define N_E_PARAMETER               -100
      #define N_E_PARAMETER_READ_ONLY   -101

    #define N_E_NOT_ACTIVATED           -200

#define NFailed(result) ((result) < 0)
#define NSucceeded(result) ((result) >= 0)

#define NE_PRESERVE_INNER_ERROR 0x00000001
#define NE_NO_CALL_STACK        0x00000002
#define NE_MERGE_CALL_STACK     0x00000004
#define NE_IS_DIRECTORY_ACCESS  0x00000100
#define NE_SKIP_ONE_FRAME       0x01000000

struct NCallStackEntry_
{
	void * addr;
	HNString hFunction;
	HNString hFile;
	NInt line;
};
#if !defined(N_ERROR_HPP_INCLUDED) && !defined(N_OBJECT_HPP_INCLUDED)
typedef struct NCallStackEntry_ NCallStackEntry;
#endif
N_DECLARE_TYPE(NCallStackEntry)

NResult N_API NCallStackEntryCreateN(void * addr, HNString hFunction, HNString hFile, NInt line, struct NCallStackEntry_ * pValue);
#ifndef N_NO_ANSI_FUNC
NResult N_API NCallStackEntryCreateA(void * addr, const NAChar * szFunction, const NAChar * szFile, NInt line, struct NCallStackEntry_ * pValue);
#endif
#ifndef N_NO_UNICODE
NResult N_API NCallStackEntryCreateW(void * addr, const NWChar * szFunction, const NWChar * szFile, NInt line, struct NCallStackEntry_ * pValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NCallStackEntryCreate(void * addr, const NChar * szFunction, const NChar * szFile, NInt line, NCallStackEntry * pValue);
#endif
#define NCallStackEntryCreate N_FUNC_AW(NCallStackEntryCreate)

NResult N_API NCallStackEntryDispose(struct NCallStackEntry_ * pValue);
NResult N_API NCallStackEntryCopy(const struct NCallStackEntry_ * pSrcValue, struct NCallStackEntry_ * pDstValue);
NResult N_API NCallStackEntrySet(const struct NCallStackEntry_ * pSrcValue, struct NCallStackEntry_ * pDstValue);

N_DECLARE_OBJECT_TYPE(NError, NObject)

NInt N_API NErrorGetLastSysError(void);
NUInt N_API NErrorGetLastWin32Error(void);

NResult N_API NErrorGetDefaultMessageN(NResult code, HNString * phValue);
#ifndef N_NO_ANSI_FUNC
N_DEPRECATED("function is deprecated, use NErrorGetDefaultMessageN instead")
NResult N_API NErrorGetDefaultMessageExA(NResult code, NAChar * szValue, NInt valueSize);
#endif
#ifndef N_NO_UNICODE
N_DEPRECATED("function is deprecated, use NErrorGetDefaultMessageN instead")
NResult N_API NErrorGetDefaultMessageExW(NResult code, NWChar * szValue, NInt valueSize);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NErrorGetDefaultMessageEx(NResult code, NChar * szValue, NInt valueSize);
#endif
#define NErrorGetDefaultMessageEx N_FUNC_AW(NErrorGetDefaultMessageEx)

NResult N_API NErrorGetSysErrorMessageN(NInt errnum, HNString * phValue);
#ifndef N_NO_ANSI_FUNC
N_DEPRECATED("function is deprecated, use NErrorGetSysErrorMessageN instead")
NResult N_API NErrorGetSysErrorMessageExA(NInt errnum, NAChar * szValue, NInt valueSize);
#endif
#ifndef N_NO_UNICODE
N_DEPRECATED("function is deprecated, use NErrorGetSysErrorMessageN instead")
NResult N_API NErrorGetSysErrorMessageExW(NInt errnum, NWChar * szValue, NInt valueSize);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NErrorGetSysErrorMessageEx(NInt errnum, NChar * szValue, NInt valueSize);
#endif
#define NErrorGetSysErrorMessageEx N_FUNC_AW(NErrorGetSysErrorMessageEx)

NResult N_API NErrorGetMachErrorMessageN(NInt err, HNString * phValue);

NResult N_API NErrorGetMacErrorMessageN(NInt err, HNString * phValue);
#ifndef N_NO_ANSI_FUNC
N_DEPRECATED("function is deprecated, use NErrorGetMacErrorMessageN instead")
NResult N_API NErrorGetMacErrorMessageExA(NInt err, NAChar * szValue, NInt valueSize);
#endif
#ifndef N_NO_UNICODE
N_DEPRECATED("function is deprecated, use NErrorGetMacErrorMessageN instead")
NResult N_API NErrorGetMacErrorMessageExW(NInt err, NWChar * szValue, NInt valueSize);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NErrorGetMacErrorMessageEx(NInt err, NChar * szValue, NInt valueSize);
#endif
#define NErrorGetMacErrorMessageEx N_FUNC_AW(NErrorGetMacErrorMessageEx)

NResult N_API NErrorGetWin32ErrorMessageN(NUInt errorCode, HNString * phValue);

NResult N_API NErrorCreateN(NResult code, HNString hMessage, HNString hParam, NInt externalError, HNString hExternalCallStack, const HNError * arhInnerErrors, NInt innerErrorCount, HNError * phError);
NResult N_API NErrorCreateA(NResult code, const NAChar * szMessage, const NAChar * szParam, NInt externalError, const NAChar * szExternalCallStack, const HNError * arhInnerErrors, NInt innerErrorCount, HNError * phError);
#ifndef N_NO_UNICODE
NResult N_API NErrorCreateW(NResult code, const NWChar * szMessage, const NWChar * szParam, NInt externalError, const NWChar * szExternalCallStack, const HNError * arhInnerErrors, NInt innerErrorCount, HNError * phError);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NErrorCreate(NResult code, const NChar * szMessage, const NChar * szParam, NInt externalError, const NChar * szExternalCallStack, const HNError * arhInnerErrors, NInt innerErrorCount, HNError * phError);
#endif
#define NErrorCreate N_FUNC_AW(NErrorCreate)

NResult N_NO_INLINE N_API NErrorSetLastEx(HNError hError, NUInt flags);
NResult N_NO_INLINE N_API NErrorRaise(HNError hError);

NResult N_NO_INLINE N_API NErrorSetLastN(NResult code, HNString hMessage, HNString hParam, NInt externalError, HNString hExternalCallStack, NUInt flags);
NResult N_NO_INLINE N_API NErrorSetLastMPNA(NResult code, HNString hMessage, HNString hParam, NInt externalError, const NAChar * szExternalCallStack, NUInt flags);
#ifndef N_NO_UNICODE
NResult N_NO_INLINE N_API NErrorSetLastMPNW(NResult code, HNString hMessage, HNString hParam, NInt externalError, const NWChar * szExternalCallStack, NUInt flags);
#endif
#ifdef N_DOCUMENTATION
NResult N_NO_INLINE N_API NErrorSetLastMPN(NResult code, HNString hMessage, HNString hParam, NInt externalError, const NChar * szExternalCallStack, NUInt flags);
#endif
#define NErrorSetLastMPN N_FUNC_AW(NErrorSetLastMPN)
NResult N_NO_INLINE N_API NErrorSetLastPNA(NResult code, const NAChar * szMessage, HNString hParam, NInt externalError, const NAChar * szExternalCallStack, NUInt flags);
#ifndef N_NO_UNICODE
NResult N_NO_INLINE N_API NErrorSetLastPNW(NResult code, const NWChar * szMessage, HNString hParam, NInt externalError, const NWChar * szExternalCallStack, NUInt flags);
#endif
#ifdef N_DOCUMENTATION
NResult N_NO_INLINE N_API NErrorSetLastPN(NResult code, const NChar * szMessage, HNString hParam, NInt externalError, const NChar * szExternalCallStack, NUInt flags);
#endif
#define NErrorSetLastPN N_FUNC_AW(NErrorSetLastPN)
NResult N_NO_INLINE N_API NErrorSetLastA(NResult code, const NAChar * szMessage, const NAChar * szParam, NInt externalError, const NAChar * szExternalCallStack, NUInt flags);
#ifndef N_NO_UNICODE
NResult N_NO_INLINE N_API NErrorSetLastW(NResult code, const NWChar * szMessage, const NWChar * szParam, NInt externalError, const NWChar * szExternalCallStack, NUInt flags);
#endif
#ifdef N_DOCUMENTATION
NResult N_NO_INLINE N_API NErrorSetLast(NResult code, const NChar * szMessage, const NChar * szParam, NInt externalError, const NChar * szExternalCallStack, NUInt flags);
#endif
#define NErrorSetLast N_FUNC_AW(NErrorSetLast)

NResult N_NO_INLINE N_API NErrorSetComN(NInt comError, HNString hMessage, HNString hParam, HNString hExternalCallStack, NUInt flags);
NResult N_NO_INLINE N_API NErrorSetComMPNA(NInt comError, HNString hMessage, HNString hParam, const NAChar * szExternalCallStack, NUInt flags);
#ifndef N_NO_UNICODE
NResult N_NO_INLINE N_API NErrorSetComMPNW(NInt comError, HNString hMessage, HNString hParam, const NWChar * szExternalCallStack, NUInt flags);
#endif
#ifdef N_DOCUMENTATION
NResult N_NO_INLINE N_API NErrorSetComMPN(NInt comError, HNString hMessage, HNString hParam, const NChar * szExternalCallStack, NUInt flags);
#endif
#define NErrorSetComMPN N_FUNC_AW(NErrorSetComMPN)
NResult N_NO_INLINE N_API NErrorSetComPNA(NInt comError, const NAChar * szMessage, HNString hParam, const NAChar * szExternalCallStack, NUInt flags);
#ifndef N_NO_UNICODE
NResult N_NO_INLINE N_API NErrorSetComPNW(NInt comError, const NWChar * szMessage, HNString hParam, const NWChar * szExternalCallStack, NUInt flags);
#endif
#ifdef N_DOCUMENTATION
NResult N_NO_INLINE N_API NErrorSetComPN(NInt comError, const NChar * szMessage, HNString hParam, const NChar * szExternalCallStack, NUInt flags);
#endif
#define NErrorSetComPN N_FUNC_AW(NErrorSetComPN)
NResult N_NO_INLINE N_API NErrorSetComA(NInt comError, const NAChar * szMessage, const NAChar * szParam, const NAChar * szExternalCallStack, NUInt flags);
#ifndef N_NO_UNICODE
NResult N_NO_INLINE N_API NErrorSetComW(NInt comError, const NWChar * szMessage, const NWChar * szParam, const NWChar * szExternalCallStack, NUInt flags);
#endif
#ifdef N_DOCUMENTATION
NResult N_NO_INLINE N_API NErrorSetCom(NInt comError, const NChar * szMessage, const NChar * szParam, const NChar * szExternalCallStack, NUInt flags);
#endif
#define NErrorSetCom N_FUNC_AW(NErrorSetCom)

NResult N_NO_INLINE N_API NErrorSetMachN(NInt32 machError, HNString hMessage, HNString hParam, HNString hExternalCallStack, NUInt flags);
NResult N_NO_INLINE N_API NErrorSetMachMPNA(NInt32 machError, HNString hMessage, HNString hParam, const NAChar * szExternalCallStack, NUInt flags);
#ifndef N_NO_UNICODE
NResult N_NO_INLINE N_API NErrorSetMachMPNW(NInt32 machError, HNString hMessage, HNString hParam, const NWChar * szExternalCallStack, NUInt flags);
#endif
#ifdef N_DOCUMENTATION
NResult N_NO_INLINE N_API NErrorSetMachMPN(NInt32 machError, HNString hMessage, HNString hParam, const NChar * szExternalCallStack, NUInt flags);
#endif
#define NErrorSetMachMPN N_FUNC_AW(NErrorSetMachMPN)
NResult N_NO_INLINE N_API NErrorSetMachPNA(NInt32 machError, const NAChar * szMessage, HNString hParam, const NAChar * szExternalCallStack, NUInt flags);
#ifndef N_NO_UNICODE
NResult N_NO_INLINE N_API NErrorSetMachPNW(NInt32 machError, const NWChar * szMessage, HNString hParam, const NWChar * szExternalCallStack, NUInt flags);
#endif
#ifdef N_DOCUMENTATION
NResult N_NO_INLINE N_API NErrorSetMachPN(NInt32 machError, const NChar * szMessage, HNString hParam, const NChar * szExternalCallStack, NUInt flags);
#endif
#define NErrorSetMachPN N_FUNC_AW(NErrorSetMachPN)
NResult N_NO_INLINE N_API NErrorSetMachA(NInt32 machError, const NAChar * szMessage, const NAChar * szParam, const NAChar * szExternalCallStack, NUInt flags);
#ifndef N_NO_UNICODE
NResult N_NO_INLINE N_API NErrorSetMachW(NInt32 machError, const NWChar * szMessage, const NWChar * szParam, const NWChar * szExternalCallStack, NUInt flags);
#endif
#ifdef N_DOCUMENTATION
NResult N_NO_INLINE N_API NErrorSetMach(NInt32 machError, const NChar * szMessage, const NChar * szParam, const NChar * szExternalCallStack, NUInt flags);
#endif
#define NErrorSetMach N_FUNC_AW(NErrorSetMach)

NResult N_NO_INLINE N_API NErrorSetMacN(NInt macError, HNString hMessage, HNString hParam, HNString hExternalCallStack, NUInt flags);
NResult N_NO_INLINE N_API NErrorSetMacMPNA(NInt macError, HNString hMessage, HNString hParam, const NAChar * szExternalCallStack, NUInt flags);
#ifndef N_NO_UNICODE
NResult N_NO_INLINE N_API NErrorSetMacMPNW(NInt macError, HNString hMessage, HNString hParam, const NWChar * szExternalCallStack, NUInt flags);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NErrorSetMacMPN(NInt macError, HNString hMessage, HNString hParam, const NChar * szExternalCallStack, NUInt flags);
#endif
#define NErrorSetMacMPN N_FUNC_AW(NErrorSetMacMPN)
NResult N_NO_INLINE N_API NErrorSetMacPNA(NInt macError, const NAChar * szMessage, HNString hParam, const NAChar * szExternalCallStack, NUInt flags);
#ifndef N_NO_UNICODE
NResult N_NO_INLINE N_API NErrorSetMacPNW(NInt macError, const NWChar * szMessage, HNString hParam, const NWChar * szExternalCallStack, NUInt flags);
#endif
#ifdef N_DOCUMENTATION
NResult N_NO_INLINE N_API NErrorSetMacPN(NInt macError, const NChar * szMessage, HNString hParam, const NChar * szExternalCallStack, NUInt flags);
#endif
#define NErrorSetMacPN N_FUNC_AW(NErrorSetMacPN)
NResult N_NO_INLINE N_API NErrorSetMacA(NInt macError, const NAChar * szMessage, const NAChar * szParam, const NAChar * szExternalCallStack, NUInt flags);
#ifndef N_NO_UNICODE
NResult N_NO_INLINE N_API NErrorSetMacW(NInt macError, const NWChar * szMessage, const NWChar * szParam, const NWChar * szExternalCallStack, NUInt flags);
#endif
#ifdef N_DOCUMENTATION
NResult N_NO_INLINE N_API NErrorSetMac(NInt macError, const NChar * szMessage, const NChar * szParam, const NChar * szExternalCallStack, NUInt flags);
#endif
#define NErrorSetMac N_FUNC_AW(NErrorSetMac)

NResult N_NO_INLINE N_API NErrorSetSysN(NInt sysError, HNString hMessage, HNString hParam, HNString hExternalCallStack, NUInt flags);
NResult N_NO_INLINE N_API NErrorSetSysMPNA(NInt sysError, HNString hMessage, HNString hParam, const NAChar * szExternalCallStack, NUInt flags);
#ifndef N_NO_UNICODE
NResult N_NO_INLINE N_API NErrorSetSysMPNW(NInt sysError, HNString hMessage, HNString hParam, const NWChar * szExternalCallStack, NUInt flags);
#endif
#ifdef N_DOCUMENTATION
NResult N_NO_INLINE N_API NErrorSetSysMPN(NInt sysError, HNString hMessage, HNString hParam, const NChar * szExternalCallStack, NUInt flags);
#endif
#define NErrorSetSysMPN N_FUNC_AW(NErrorSetSysMPN)
NResult N_NO_INLINE N_API NErrorSetSysPNA(NInt sysError, const NAChar * szMessage, HNString hParam, const NAChar * szExternalCallStack, NUInt flags);
#ifndef N_NO_UNICODE
NResult N_NO_INLINE N_API NErrorSetSysPNW(NInt sysError, const NWChar * szMessage, HNString hParam, const NWChar * szExternalCallStack, NUInt flags);
#endif
#ifdef N_DOCUMENTATION
NResult N_NO_INLINE N_API NErrorSetSysPN(NInt sysError, const NChar * szMessage, HNString hParam, const NChar * szExternalCallStack, NUInt flags);
#endif
#define NErrorSetSysPN N_FUNC_AW(NErrorSetSysPN)
NResult N_NO_INLINE N_API NErrorSetSysA(NInt sysError, const NAChar * szMessage, const NAChar * szParam, const NAChar * szExternalCallStack, NUInt flags);
#ifndef N_NO_UNICODE
NResult N_NO_INLINE N_API NErrorSetSysW(NInt sysError, const NWChar * szMessage, const NWChar * szParam, const NWChar * szExternalCallStack, NUInt flags);
#endif
#ifdef N_DOCUMENTATION
NResult N_NO_INLINE N_API NErrorSetSys(NInt sysError, const NChar * szMessage, const NChar * szParam, const NChar * szExternalCallStack, NUInt flags);
#endif
#define NErrorSetSys N_FUNC_AW(NErrorSetSys)

NResult N_NO_INLINE N_API NErrorSetWin32N(NUInt win32Error, HNString hMessage, HNString hParam, HNString hExternalCallStack, NUInt flags);
NResult N_NO_INLINE N_API NErrorSetWin32MPNA(NUInt win32Error, HNString hMessage, HNString hParam, const NAChar * szExternalCallStack, NUInt flags);
#ifndef N_NO_UNICODE
NResult N_NO_INLINE N_API NErrorSetWin32MPNW(NUInt win32Error, HNString hMessage, HNString hParam, const NWChar * szExternalCallStack, NUInt flags);
#endif
#ifdef N_DOCUMENTATION
NResult N_NO_INLINE N_API NErrorSetWin32MPN(NUInt win32Error, HNString hMessage, HNString hParam, const NChar * szExternalCallStack, NUInt flags);
#endif
#define NErrorSetWin32MPN N_FUNC_AW(NErrorSetWin32MPN)
NResult N_NO_INLINE N_API NErrorSetWin32PNA(NUInt win32Error, const NAChar * szMessage, HNString hParam, const NAChar * szExternalCallStack, NUInt flags);
#ifndef N_NO_UNICODE
NResult N_NO_INLINE N_API NErrorSetWin32PNW(NUInt win32Error, const NWChar * szMessage, HNString hParam, const NWChar * szExternalCallStack, NUInt flags);
#endif
#ifdef N_DOCUMENTATION
NResult N_NO_INLINE N_API NErrorSetWin32PN(NUInt win32Error, const NChar * szMessage, HNString hParam, const NChar * szExternalCallStack, NUInt flags);
#endif
#define NErrorSetWin32PN N_FUNC_AW(NErrorSetWin32PN)
NResult N_NO_INLINE N_API NErrorSetWin32A(NUInt win32Error, const NAChar * szMessage, const NAChar * szParam, const NAChar * szExternalCallStack, NUInt flags);
#ifndef N_NO_UNICODE
NResult N_NO_INLINE N_API NErrorSetWin32W(NUInt win32Error, const NWChar * szMessage, const NWChar * szParam, const NWChar * szExternalCallStack, NUInt flags);
#endif
#ifdef N_DOCUMENTATION
NResult N_NO_INLINE N_API NErrorSetWin32(NUInt win32Error, const NChar * szMessage, const NChar * szParam, const NChar * szExternalCallStack, NUInt flags);
#endif
#define NErrorSetWin32 N_FUNC_AW(NErrorSetWin32)

void N_NO_INLINE N_API NErrorAppendN(void * addr, HNString hFunction, HNString hFile, NInt line);
void N_NO_INLINE N_API NErrorAppendA(void * addr, const NAChar * szFunction, const NAChar * szFile, NInt line);
#ifndef N_NO_UNICODE
void N_NO_INLINE N_API NErrorAppendW(void * addr, const NAChar * szFunction, const NWChar * szFile, NInt line);
#endif
#ifdef N_DOCUMENTATION
void N_NO_INLINE N_API NErrorAppend(void * addr, const NAChar * szFunction, const NChar * szFile, NInt line);
#endif
#define NErrorAppend N_FUNC_AW(NErrorAppend)

NResult N_NO_INLINE N_API NErrorReport(NResult res);
NResult N_NO_INLINE N_API NErrorReportEx(NResult errorCode, HNError hError);
void N_NO_INLINE N_API NErrorSuppress(NResult result);

NResult N_API NErrorGetLastEx(NUInt flags, HNError * phError);
NResult N_API NErrorCapture(NResult result, HNError * phError);
NResult N_API NErrorGetCodeEx(HNError hError, NResult * pValue);

NResult N_API NErrorGetMessageN(HNError hError, HNString * phValue);
#ifndef N_NO_ANSI_FUNC
N_DEPRECATED("function is deprecated, use NErrorGetMessageN instead")
NResult N_API NErrorGetMessageExA(HNError hError, NAChar * szValue, NInt valueSize);
#endif
#ifndef N_NO_UNICODE
N_DEPRECATED("function is deprecated, use NErrorGetMessageN instead")
NResult N_API NErrorGetMessageExW(HNError hError, NWChar * szValue, NInt valueSize);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NErrorGetMessageEx(HNError hError, NChar * szValue, NInt valueSize);
#endif
#define NErrorGetMessageEx N_FUNC_AW(NErrorGetMessageEx)

NResult N_API NErrorGetParamN(HNError hError, HNString * phValue);
#ifndef N_NO_ANSI_FUNC
N_DEPRECATED("function is deprecated, use NErrorGetParamN instead")
NResult N_API NErrorGetParamExA(HNError hError, NAChar * szValue, NInt valueSize);
#endif
#ifndef N_NO_UNICODE
N_DEPRECATED("function is deprecated, use NErrorGetParamN instead")
NResult N_API NErrorGetParamExW(HNError hError, NWChar * szValue, NInt valueSize);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NErrorGetParamEx(HNError hError, NChar * szValue, NInt valueSize);
#endif
#define NErrorGetParamEx N_FUNC_AW(NErrorGetParamEx)

NResult N_API NErrorGetExternalErrorEx(HNError hError, NInt * pValue);

NResult N_API NErrorGetExternalCallStackN(HNError hError, HNString * phValue);
#ifndef N_NO_ANSI_FUNC
N_DEPRECATED("function is deprecated, use NErrorGetExternalCallStackN instead")
NResult N_API NErrorGetExternalCallStackExA(HNError hError, NAChar * szValue, NInt valueSize);
#endif
#ifndef N_NO_UNICODE
N_DEPRECATED("function is deprecated, use NErrorGetExternalCallStackN instead")
NResult N_API NErrorGetExternalCallStackExW(HNError hError, NWChar * szValue, NInt valueSize);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NErrorGetExternalCallStackEx(HNError hError, NChar * szValue, NInt valueSize);
#endif
#define NErrorGetExternalCallStackEx N_FUNC_AW(NErrorGetExternalCallStackEx)

NResult N_API NErrorGetCallStackCount(HNError hError, NInt * pValue);
NResult N_API NErrorGetCallStackEntry(HNError hError, NInt index, struct NCallStackEntry_ * pValue);

#ifndef N_NO_ANSI_FUNC
N_DEPRECATED("function is deprecated, use NErrorGetCallStackEntry instead")
NResult N_API NErrorGetCallStackFunctionExA(HNError hError, NInt index, NAChar * szValue, NInt valueSize);
#endif
#ifndef N_NO_UNICODE
N_DEPRECATED("function is deprecated, use NErrorGetCallStackEntry instead")
NResult N_API NErrorGetCallStackFunctionExW(HNError hError, NInt index, NWChar * szValue, NInt valueSize);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NErrorGetCallStackFunctionEx(HNError hError, NInt index, NChar * szValue, NInt valueSize);
#endif
#define NErrorGetCallStackFunctionEx N_FUNC_AW(NErrorGetCallStackFunctionEx)

#ifndef N_NO_ANSI_FUNC
N_DEPRECATED("function is deprecated, use NErrorGetCallStackEntry instead")
NResult N_API NErrorGetCallStackFileExA(HNError hError, NInt index, NAChar * szValue, NInt valueSize);
#endif
#ifndef N_NO_UNICODE
N_DEPRECATED("function is deprecated, use NErrorGetCallStackEntry instead")
NResult N_API NErrorGetCallStackFileExW(HNError hError, NInt index, NWChar * szValue, NInt valueSize);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NErrorGetCallStackFileEx(HNError hError, NInt index, NChar * szValue, NInt valueSize);
#endif
#define NErrorGetCallStackFileEx N_FUNC_AW(NErrorGetCallStackFileEx)

N_DEPRECATED("function is deprecated, use NErrorGetCallStackEntry instead")
NResult N_API NErrorGetCallStackLineEx(HNError hError, NInt index, NInt * pValue);
NResult N_API NErrorGetCallStackN(HNError hError, HNString * phValue);
NResult N_API NErrorGetInnerErrorEx(HNError hError, HNError * phValue);
NResult N_API NErrorGetInnerErrorCount(HNError hError, NInt * pValue);
NResult N_API NErrorGetInnerErrorAt(HNError hError, NInt index, HNError * phValue);

#define N_ERROR_FUNCTION_PREFIXA "   at "
#define N_ERROR_MAKE_EXTERNALL_CALL_STACKA(function) N_ERROR_FUNCTION_PREFIXA N_STRINGIZEA(function) N_NEW_LINEA
#ifndef N_NO_UNICODE
#define N_ERROR_FUNCTION_PREFIXW L"   at "
#define N_ERROR_MAKE_EXTERNALL_CALL_STACKW(function) N_ERROR_FUNCTION_PREFIXW N_STRINGIZEW(function) N_NEW_LINEW
#endif
#define N_ERROR_FUNCTION_PREFIX N_MACRO_AW(N_ERROR_FUNCTION_PREFIX)
#define N_ERROR_MAKE_EXTERNALL_CALL_STACK N_MACRO_AW(N_ERROR_MAKE_EXTERNALL_CALL_STACK)

#ifdef N_DEBUG
	#ifdef N_MSVC
		#define N_ERROR_CONTEXT NULL, __FUNCSIG__, N_T(__FILE__), __LINE__
	#else
		#define N_ERROR_CONTEXT NULL, __FUNCTION__, N_T(__FILE__), __LINE__
	#endif
#else
	#define N_ERROR_CONTEXT NULL, NULL, NULL, 0
#endif

#ifdef N_NO_CALL_STACK
	#define N_ERROR_APPEND { NErrorAppend(N_ERROR_CONTEXT); }
#else
	#define N_ERROR_APPEND
#endif

#define N_TRY \
	NResult N_THE_ERROR = N_OK;\
	NBool N_FINALLY_entered = NFalse;

#define N_TRY_NR \
	N_TRY\
	HNError N_TRY_hError;\
	NResult N_TRY_NR_res = NErrorGetLastEx(0, &N_TRY_hError);

#define N_RESULT(value) \
	{\
		N_THE_ERROR = value;\
		goto N_TRY_End;\
	}

#define N_RETURN N_RESULT(N_OK)

#define N_ERROR_MNPN_(code, hMessage, hParam, flags) \
	{\
		N_THE_ERROR = NErrorSetLastMPNA(code, hMessage, hParam, 0, NULL, flags);\
		N_ERROR_APPEND\
		goto N_TRY_End;\
	}
#define N_ERROR_MNPN(code, hMessage, hParam) N_ERROR_MNPN_(code, hMessage, hParam, 0)
#define N_ERROR_MN(code, hMessage) N_ERROR_MNPN(code, hMessage, NULL)

#define N_ERROR_MPN_A(code, szMessage, hParam, flags) \
	{\
		N_THE_ERROR = NErrorSetLastPNA(code, szMessage, hParam, 0, NULL, flags);\
		N_ERROR_APPEND\
		goto N_TRY_End;\
	}
#define N_ERROR_MPNA(code, szMessage, hParam) N_ERROR_MPN_A(code, szMessage, hParam, 0)
#ifndef N_NO_UNICODE
#define N_ERROR_MPN_W(code, szMessage, hParam, flags) \
	{\
		N_THE_ERROR = NErrorSetLastPNW(code, szMessage, hParam, 0, NULL, flags);\
		N_ERROR_APPEND\
		goto N_TRY_End;\
	}
#define N_ERROR_MPNW(code, szMessage, hParam) N_ERROR_MPN_W(code, szMessage, hParam, 0)
#endif
#define N_ERROR_MPN_ N_MACRO_AW(N_ERROR_MPN_)
#define N_ERROR_MPN N_MACRO_AW(N_ERROR_MPN)
#define N_ERROR_PN(code, hParam) N_ERROR_MNPN(code, NULL, hParam)
#define N_ERROR(code) N_ERROR_MNPN(code, NULL, NULL)

#define N_ERROR_MP_A(code, szMessage, szParam, flags) \
	{\
		N_THE_ERROR = NErrorSetLastA(code, szMessage, szParam, 0, NULL, flags);\
		N_ERROR_APPEND\
		goto N_TRY_End;\
	}
#define N_ERROR_MPA(code, szMessage, szParam) N_ERROR_MP_A(code, szMessage, szParam, 0)
#define N_ERROR_PA(code, szParam) N_ERROR_MPA(code, NULL, szParam)
#define N_ERROR_MA(code, szMessage) N_ERROR_MPA(code, szMessage, NULL)

#ifndef N_NO_UNICODE
#define N_ERROR_MP_W(code, szMessage, szParam, flags) \
	{\
		N_THE_ERROR = NErrorSetLastW(code, szMessage, szParam, 0, NULL, flags);\
		N_ERROR_APPEND\
		goto N_TRY_End;\
	}
#define N_ERROR_MPW(code, szMessage, szParam) N_ERROR_MP_W(code, szMessage, szParam, 0)
#define N_ERROR_PW(code, szParam) N_ERROR_MPW(code, NULL, szParam)
#define N_ERROR_MW(code, szMessage) N_ERROR_MPW(code, szMessage, NULL)
#endif

#define N_ERROR_MP_ N_MACRO_AW(N_ERROR_MP_)
#define N_ERROR_MP N_MACRO_AW(N_ERROR_MP)
#define N_ERROR_P N_MACRO_AW(N_ERROR_P)
#define N_ERROR_M N_MACRO_AW(N_ERROR_M)

#define N_RAISE(result) \
	{\
		N_ERROR_APPEND\
		N_RESULT(result);\
	}\

#define N_CHECK(result) \
	{\
		NResult N_CHECK_result = (result);\
		if (N_UNLIKELY(NFailed(N_CHECK_result))) N_RAISE(N_CHECK_result);\
	}

#define N_CHECK_R(result) \
	{\
		N_THE_ERROR = (result);\
		if (N_UNLIKELY(NFailed(N_THE_ERROR)))\
		{\
			N_ERROR_APPEND\
		}\
		goto N_TRY_End;\
	}

#define N_CHECK_CONTEXT(result, hError) \
	{\
		if (N_UNLIKELY(NFailed(result)))\
		{\
			NErrorSetLastEx(hError, NE_MERGE_CALL_STACK);\
			N_ERROR_APPEND\
			N_THE_ERROR = (result);\
			(result) = N_OK;\
			if (hError) { NObjectUnref(hError); (hError) = NULL; }\
			goto N_TRY_End;\
		}\
	}

#define N_ERROR_FAILED() N_ERROR(N_E_FAILED)
#define N_ERROR_FAILED_MA(szMessage) N_ERROR_MA(N_E_FAILED, szMessage)
#ifndef N_NO_UNICODE
#define N_ERROR_FAILED_MW(szMessage) N_ERROR_MW(N_E_FAILED, szMessage)
#endif
#define N_ERROR_FAILED_M N_MACRO_AW(N_ERROR_FAILED_M)

#define N_ERROR_CORE() N_ERROR(N_E_CORE)
#define N_ERROR_CORE_MA(szMessage) N_ERROR_MA(N_E_CORE, szMessage)
#ifndef N_NO_UNICODE
#define N_ERROR_CORE_MW(szMessage) N_ERROR_MW(N_E_CORE, szMessage)
#endif
#define N_ERROR_CORE_M N_MACRO_AW(N_ERROR_CORE_M)

#define N_ERROR_ABANDONED_MUTEX() N_ERROR(N_E_ABANDONED_MUTEX)
#define N_ERROR_ABANDONED_MUTEX_MA(szMessage) N_ERROR_MA(N_E_ABANDONED_MUTEX, szMessage)
#ifndef N_NO_UNICODE
#define N_ERROR_ABANDONED_MUTEX_MW(szMessage) N_ERROR_MW(N_E_ABANDONED_MUTEX, szMessage)
#endif
#define N_ERROR_ABANDONED_MUTEX_M N_MACRO_AW(N_ERROR_ABANDONED_MUTEX_M)

#define N_ERROR_ARGUMENT() N_ERROR(N_E_ARGUMENT)
#define N_ERROR_ARGUMENT_MA(szMessage) N_ERROR_MA(N_E_ARGUMENT, szMessage)
#define N_ERROR_ARGUMENT_MPA(szMessage, param) N_ERROR_MPA(N_E_ARGUMENT, szMessage, N_STRINGIZEA(param))
#ifndef N_NO_UNICODE
#define N_ERROR_ARGUMENT_MW(szMessage) N_ERROR_MW(N_E_ARGUMENT, szMessage)
#define N_ERROR_ARGUMENT_MPW(szMessage, param) N_ERROR_MPW(N_E_ARGUMENT, szMessage, N_STRINGIZEW(param))
#endif
#define N_ERROR_ARGUMENT_M N_MACRO_AW(N_ERROR_ARGUMENT_M)
#define N_ERROR_ARGUMENT_MP N_MACRO_AW(N_ERROR_ARGUMENT_MP)
#define N_ERROR_ARGUMENT_P(param) N_ERROR_MP(N_E_ARGUMENT, N_STRINGIZE(param) N_T(" is invalid"), N_STRINGIZE(param))
#define N_ERROR_ARGUMENT_NOT_NULL_P(param) N_ERROR_MP(N_E_ARGUMENT, N_STRINGIZE(param) N_T(" is not NULL"), N_STRINGIZE(param))
#define N_ERROR_ARGUMENT_NOT_ZERO_P(param) N_ERROR_MP(N_E_ARGUMENT, N_STRINGIZE(param) N_T(" is not zero"), N_STRINGIZE(param))
#define N_ERROR_ARGUMENT_TYPE_P(param) N_ERROR_MP(N_E_ARGUMENT, N_STRINGIZE(param) N_T(" type is not the one that is expected"), N_STRINGIZE(param))
#define N_ERROR_ARGUMENT_ELEMENT_TYPE_P(param) N_ERROR_MP(N_E_ARGUMENT, N_T("One of ") N_STRINGIZE(param) N_T(" elements type is not the one that is expected"), N_STRINGIZE(param))
#define N_ERROR_EMPTY_STRING_ARGUMENT_P(param) N_ERROR_MP(N_E_ARGUMENT, N_STRINGIZE(param) N_T(" is NULL or an empty string"), N_STRINGIZE(param))
#define N_ERROR_NOT_EMPTY_STRING_ARGUMENT_P(param) N_ERROR_MP(N_E_ARGUMENT, N_STRINGIZE(param) N_T(" is not NULL or an empty string"), N_STRINGIZE(param))
#define N_ERROR_EMPTY_STRING_ARGUMENT_ELEMENT_P(param) N_ERROR_MP(N_E_ARGUMENT, N_T("One of ") N_STRINGIZE(param) N_T(" elements is NULL or an empty string"), N_STRINGIZE(param))
#define N_ERROR_ARGUMENT_ELEMENT_P(param) N_ERROR_MP(N_E_ARGUMENT, N_T("One of ") N_STRINGIZE(param) N_T(" elements is invalid"), N_STRINGIZE(param))
#define N_ERROR_ARGUMENT_INSUFFICIENT_P(param) N_ERROR_MP(N_E_ARGUMENT, N_STRINGIZE(param) N_T(" is insufficient"), N_STRINGIZE(param))
#define N_ERROR_ARGUMENT_POINTER_P(param) N_ERROR_MP(N_E_ARGUMENT, N_T("Value ") N_STRINGIZE(param) N_T(" points to is invalid"), N_STRINGIZE(param))

#define N_ERROR_ARGUMENT_NULL() N_ERROR(N_E_ARGUMENT_NULL)
#define N_ERROR_ARGUMENT_NULL_MA(szMessage) N_ERROR_MA(N_E_ARGUMENT_NULL, szMessage)
#define N_ERROR_ARGUMENT_NULL_MPA(szMessage, param) N_ERROR_MPA(N_E_ARGUMENT_NULL, szMessage, N_STRINGIZEA(param))
#ifndef N_NO_UNICODE
#define N_ERROR_ARGUMENT_NULL_MW(szMessage) N_ERROR_MW(N_E_ARGUMENT_NULL, szMessage)
#define N_ERROR_ARGUMENT_NULL_MPW(szMessage, param) N_ERROR_MPW(N_E_ARGUMENT_NULL, szMessage, N_STRINGIZEW(param))
#endif
#define N_ERROR_ARGUMENT_NULL_M N_MACRO_AW(N_ERROR_ARGUMENT_NULL_M)
#define N_ERROR_ARGUMENT_NULL_MP N_MACRO_AW(N_ERROR_ARGUMENT_NULL_MP)
#define N_ERROR_ARGUMENT_NULL_P(param) N_ERROR_MP(N_E_ARGUMENT_NULL, N_STRINGIZE(param) N_T(" is NULL"), N_STRINGIZE(param))
#define N_ERROR_ARGUMENT_ELEMENT_NULL_P(param) N_ERROR_MP(N_E_ARGUMENT_NULL, N_T("One of ") N_STRINGIZE(param) N_T(" elements is NULL"), N_STRINGIZE(param))

#define N_ERROR_ARGUMENT_OUT_OF_RANGE() N_ERROR(N_E_ARGUMENT_OUT_OF_RANGE)
#define N_ERROR_ARGUMENT_OUT_OF_RANGE_MA(szMessage) N_ERROR_MA(N_E_ARGUMENT_OUT_OF_RANGE, szMessage)
#define N_ERROR_ARGUMENT_OUT_OF_RANGE_MPA(szMessage, param) N_ERROR_MPA(N_E_ARGUMENT_OUT_OF_RANGE, szMessage, N_STRINGIZEA(param))
#ifndef N_NO_UNICODE
#define N_ERROR_ARGUMENT_OUT_OF_RANGE_MW(szMessage) N_ERROR_MW(N_E_ARGUMENT_OUT_OF_RANGE, szMessage)
#define N_ERROR_ARGUMENT_OUT_OF_RANGE_MPW(szMessage, param) N_ERROR_MPW(N_E_ARGUMENT_OUT_OF_RANGE, szMessage, N_STRINGIZEW(param))
#endif
#define N_ERROR_ARGUMENT_OUT_OF_RANGE_M N_MACRO_AW(N_ERROR_ARGUMENT_OUT_OF_RANGE_M)
#define N_ERROR_ARGUMENT_OUT_OF_RANGE_MP N_MACRO_AW(N_ERROR_ARGUMENT_OUT_OF_RANGE_MP)
#define N_ERROR_ARGUMENT_OUT_OF_RANGE_P(param) N_ERROR_MP(N_E_ARGUMENT_OUT_OF_RANGE, N_STRINGIZE(param) N_T(" is out of range"), N_STRINGIZE(param))
#define N_ERROR_ARGUMENT_LESS_THAN_ZERO_P(param) N_ERROR_MP(N_E_ARGUMENT_OUT_OF_RANGE, N_STRINGIZE(param) N_T(" is less than zero"), N_STRINGIZE(param))
#define N_ERROR_ARGUMENT_LESS_THAN_ONE_P(param) N_ERROR_MP(N_E_ARGUMENT_OUT_OF_RANGE, N_STRINGIZE(param) N_T(" is less than one"), N_STRINGIZE(param))
#define N_ERROR_ARGUMENT_LESS_THAN_MINUS_ONE_P(param) N_ERROR_MP(N_E_ARGUMENT_OUT_OF_RANGE, N_STRINGIZE(param) N_T(" is less than minus one"), N_STRINGIZE(param))
#define N_ERROR_ARGUMENT_ZERO_P(param) N_ERROR_MP(N_E_ARGUMENT_OUT_OF_RANGE, N_STRINGIZE(param) N_T(" is zero"), N_STRINGIZE(param))

#define N_ERROR_INVALID_ENUM_ARGUMENT() N_ERROR(N_E_INVALID_ENUM_ARGUMENT)
#define N_ERROR_INVALID_ENUM_ARGUMENT_MA(szMessage) N_ERROR_MA(N_E_INVALID_ENUM_ARGUMENT, szMessage)
#define N_ERROR_INVALID_ENUM_ARGUMENT_MPA(szMessage, param) N_ERROR_MPA(N_E_INVALID_ENUM_ARGUMENT, szMessage, N_STRINGIZEA(param))
#ifndef N_NO_UNICODE
#define N_ERROR_INVALID_ENUM_ARGUMENT_MW(szMessage) N_ERROR_MW(N_E_INVALID_ENUM_ARGUMENT, szMessage)
#define N_ERROR_INVALID_ENUM_ARGUMENT_MPW(szMessage, param) N_ERROR_MPW(N_E_INVALID_ENUM_ARGUMENT, szMessage, N_STRINGIZEW(param))
#endif
#define N_ERROR_INVALID_ENUM_ARGUMENT_M N_MACRO_AW(N_ERROR_INVALID_ENUM_ARGUMENT_M)
#define N_ERROR_INVALID_ENUM_ARGUMENT_MP N_MACRO_AW(N_ERROR_INVALID_ENUM_ARGUMENT_MP)
#define N_ERROR_INVALID_ENUM_ARGUMENT_P(param) N_ERROR_MP(N_E_INVALID_ENUM_ARGUMENT, N_STRINGIZE(param) N_T(" is an invalid enum value"), N_STRINGIZE(param))

#define N_ERROR_ARITHMETIC() N_ERROR(N_E_ARITHMETIC)
#define N_ERROR_ARITHMETIC_MA(szMessage) N_ERROR_MA(N_E_ARITHMETIC, szMessage)
#ifndef N_NO_UNICODE
#define N_ERROR_ARITHMETIC_MW(szMessage) N_ERROR_MW(N_E_ARITHMETIC, szMessage)
#endif
#define N_ERROR_ARITHMETIC_M N_MACRO_AW(N_ERROR_ARITHMETIC_M)

#define N_ERROR_OVERFLOW() N_ERROR(N_E_OVERFLOW)
#define N_ERROR_OVERFLOW_MA(szMessage) N_ERROR_MA(N_E_OVERFLOW, szMessage)
#ifndef N_NO_UNICODE
#define N_ERROR_OVERFLOW_MW(szMessage) N_ERROR_MW(N_E_OVERFLOW, szMessage)
#endif
#define N_ERROR_OVERFLOW_M N_MACRO_AW(N_ERROR_OVERFLOW_M)

#define N_ERROR_BAD_IMAGE_FORMAT() N_ERROR(N_E_BAD_IMAGE_FORMAT)
#define N_ERROR_BAD_IMAGE_FORMAT_MA(szMessage) N_ERROR_MA(N_E_BAD_IMAGE_FORMAT, szMessage)
#define N_ERROR_BAD_IMAGE_FORMAT_MFNA(szMessage, hFileName) N_ERROR_MPNA(N_E_BAD_IMAGE_FORMAT, szMessage, hFileName)
#define N_ERROR_BAD_IMAGE_FORMAT_MFA(szMessage, szFileName) N_ERROR_MPA(N_E_BAD_IMAGE_FORMAT, szMessage, szFileName)
#ifndef N_NO_UNICODE
#define N_ERROR_BAD_IMAGE_FORMAT_MW(szMessage) N_ERROR_MW(N_E_BAD_IMAGE_FORMAT, szMessage)
#define N_ERROR_BAD_IMAGE_FORMAT_MFNW(szMessage, hFileName) N_ERROR_MPNW(N_E_BAD_IMAGE_FORMAT, szMessage, hFileName)
#define N_ERROR_BAD_IMAGE_FORMAT_MFW(szMessage, szFileName) N_ERROR_MPW(N_E_BAD_IMAGE_FORMAT, szMessage, szFileName)
#endif
#define N_ERROR_BAD_IMAGE_FORMAT_M N_MACRO_AW(N_ERROR_BAD_IMAGE_FORMAT_M)
#define N_ERROR_BAD_IMAGE_FORMAT_MFN N_MACRO_AW(N_ERROR_BAD_IMAGE_FORMAT_MFN)
#define N_ERROR_BAD_IMAGE_FORMAT_MF N_MACRO_AW(N_ERROR_BAD_IMAGE_FORMAT_MF)

#define N_ERROR_DLL_NOT_FOUND() N_ERROR(N_E_DLL_NOT_FOUND)
#define N_ERROR_DLL_NOT_FOUND_MA(szMessage) N_ERROR_MA(N_E_DLL_NOT_FOUND, szMessage)
#define N_ERROR_DLL_NOT_FOUND_MFNA(szMessage, hFileName) N_ERROR_MPNA(N_E_DLL_NOT_FOUND, szMessage, hFileName)
#define N_ERROR_DLL_NOT_FOUND_MFA(szMessage, szFileName) N_ERROR_MPA(N_E_DLL_NOT_FOUND, szMessage, szFileName)
#ifndef N_NO_UNICODE
#define N_ERROR_DLL_NOT_FOUND_MW(szMessage) N_ERROR_MW(N_E_DLL_NOT_FOUND, szMessage)
#define N_ERROR_DLL_NOT_FOUND_MFNW(szMessage, hFileName) N_ERROR_MPNW(N_E_DLL_NOT_FOUND, szMessage, hFileName)
#define N_ERROR_DLL_NOT_FOUND_MFW(szMessage, szFileName) N_ERROR_MPW(N_E_DLL_NOT_FOUND, szMessage, szFileName)
#endif
#define N_ERROR_DLL_NOT_FOUND_M N_MACRO_AW(N_ERROR_DLL_NOT_FOUND_M)
#define N_ERROR_DLL_NOT_FOUND_MFN N_MACRO_AW(N_ERROR_DLL_NOT_FOUND_MFN)
#define N_ERROR_DLL_NOT_FOUND_MF N_MACRO_AW(N_ERROR_DLL_NOT_FOUND_MF)

#define N_ERROR_ENTRY_POINT_NOT_FOUND() N_ERROR(N_E_ENTRY_POINT_NOT_FOUND)
#define N_ERROR_ENTRY_POINT_NOT_FOUND_MA(szMessage) N_ERROR_MA(N_E_ENTRY_POINT_NOT_FOUND, szMessage)
#define N_ERROR_ENTRY_POINT_NOT_FOUND_MSNA(szMessage, hSymbolName) N_ERROR_MPNA(N_E_ENTRY_POINT_NOT_FOUND, szMessage, hSymbolName)
#define N_ERROR_ENTRY_POINT_NOT_FOUND_MSA(szMessage, szSymbolName) N_ERROR_MPA(N_E_ENTRY_POINT_NOT_FOUND, szMessage, szSymbolName)
#ifndef N_NO_UNICODE
#define N_ERROR_ENTRY_POINT_NOT_FOUND_MW(szMessage) N_ERROR_MW(N_E_ENTRY_POINT_NOT_FOUND, szMessage)
#define N_ERROR_ENTRY_POINT_NOT_FOUND_MSNW(szMessage, hSymbolName) N_ERROR_MPNW(N_E_ENTRY_POINT_NOT_FOUND, szMessage, hSymbolName)
#define N_ERROR_ENTRY_POINT_NOT_FOUND_MSW(szMessage, szSymbolName) N_ERROR_MPW(N_E_ENTRY_POINT_NOT_FOUND, szMessage, szSymbolName)
#endif
#define N_ERROR_ENTRY_POINT_NOT_FOUND_M N_MACRO_AW(N_ERROR_ENTRY_POINT_NOT_FOUND_M)
#define N_ERROR_ENTRY_POINT_NOT_FOUND_MSN N_MACRO_AW(N_ERROR_ENTRY_POINT_NOT_FOUND_MSN)
#define N_ERROR_ENTRY_POINT_NOT_FOUND_MS N_MACRO_AW(N_ERROR_ENTRY_POINT_NOT_FOUND_MS)

#define N_ERROR_FORMAT() N_ERROR(N_E_FORMAT)
#define N_ERROR_FORMAT_MA(szMessage) N_ERROR_MA(N_E_FORMAT, szMessage)
#define N_ERROR_FORMAT_MPA(szMessage, param) N_ERROR_MPA(N_E_FORMAT, szMessage, N_STRINGIZEA(param))
#ifndef N_NO_UNICODE
#define N_ERROR_FORMAT_MW(szMessage) N_ERROR_MW(N_E_FORMAT, szMessage)
#define N_ERROR_FORMAT_MPW(szMessage, param) N_ERROR_MPW(N_E_FORMAT, szMessage, N_STRINGIZEW(param))
#endif
#define N_ERROR_FORMAT_M N_MACRO_AW(N_ERROR_FORMAT_M)
#define N_ERROR_FORMAT_MP N_MACRO_AW(N_ERROR_FORMAT_MP)
#define N_ERROR_FORMAT_P(param) N_ERROR_MP(N_E_FORMAT, N_STRINGIZE(param) N_T(" format is invalid"), N_STRINGIZE(param))

#define N_ERROR_FILE_FORMAT() N_ERROR(N_E_FILE_FORMAT)
#define N_ERROR_FILE_FORMAT_MA(szMessage) N_ERROR_MA(N_E_FILE_FORMAT, szMessage)
#define N_ERROR_FILE_FORMAT_MFNA(szMessage, hFileName) N_ERROR_MPNA(N_E_FILE_FORMAT, szMessage, hFileName)
#define N_ERROR_FILE_FORMAT_MFA(szMessage, szFileName) N_ERROR_MPA(N_E_FILE_FORMAT, szMessage, szFileName)
#ifndef N_NO_UNICODE
#define N_ERROR_FILE_FORMAT_MW(szMessage) N_ERROR_MW(N_E_FILE_FORMAT, szMessage)
#define N_ERROR_FILE_FORMAT_MFNW(szMessage, hFileName) N_ERROR_MPNW(N_E_FILE_FORMAT, szMessage, hFileName)
#define N_ERROR_FILE_FORMAT_MFW(szMessage, szFileName) N_ERROR_MPW(N_E_FILE_FORMAT, szMessage, szFileName)
#endif
#define N_ERROR_FILE_FORMAT_M N_MACRO_AW(N_ERROR_FILE_FORMAT_M)
#define N_ERROR_FILE_FORMAT_MFN N_MACRO_AW(N_ERROR_FILE_FORMAT_MFN)
#define N_ERROR_FILE_FORMAT_MF N_MACRO_AW(N_ERROR_FILE_FORMAT_FORMAT_MF)

#define N_ERROR_INDEX_OUT_OF_RANGE() N_ERROR(N_E_INDEX_OUT_OF_RANGE)
#define N_ERROR_INDEX_OUT_OF_RANGE_MA(szMessage) N_ERROR_MA(N_E_INDEX_OUT_OF_RANGE, szMessage)
#ifndef N_NO_UNICODE
#define N_ERROR_INDEX_OUT_OF_RANGE_MW(szMessage) N_ERROR_MW(N_E_INDEX_OUT_OF_RANGE, szMessage)
#endif
#define N_ERROR_INDEX_OUT_OF_RANGE_M N_MACRO_AW(N_ERROR_INDEX_OUT_OF_RANGE_M)

#define N_ERROR_INVALID_CAST() N_ERROR(N_E_INVALID_CAST)
#define N_ERROR_INVALID_CAST_MA(szMessage) N_ERROR_MA(N_E_INVALID_CAST, szMessage)
#ifndef N_NO_UNICODE
#define N_ERROR_INVALID_CAST_MW(szMessage) N_ERROR_MW(N_E_INVALID_CAST, szMessage)
#endif
#define N_ERROR_INVALID_CAST_M N_MACRO_AW(N_ERROR_INVALID_CAST_M)

#define N_ERROR_INVALID_OPERATION() N_ERROR(N_E_INVALID_OPERATION)
#define N_ERROR_INVALID_OPERATION_MA(szMessage) N_ERROR_MA(N_E_INVALID_OPERATION, szMessage)
#ifndef N_NO_UNICODE
#define N_ERROR_INVALID_OPERATION_MW(szMessage) N_ERROR_MW(N_E_INVALID_OPERATION, szMessage)
#endif
#define N_ERROR_INVALID_OPERATION_M N_MACRO_AW(N_ERROR_INVALID_OPERATION_M)

#define N_ERROR_IO() N_ERROR(N_E_IO)
#define N_ERROR_IO_MA(szMessage) N_ERROR_MA(N_E_IO, szMessage)
#ifndef N_NO_UNICODE
#define N_ERROR_IO_MW(szMessage) N_ERROR_MW(N_E_IO, szMessage)
#endif
#define N_ERROR_IO_M N_MACRO_AW(N_ERROR_IO_M)

#define N_ERROR_DIRECTORY_NOT_FOUND() N_ERROR(N_E_DIRECTORY_NOT_FOUND)
#define N_ERROR_DIRECTORY_NOT_FOUND_MA(szMessage) N_ERROR_MA(N_E_DIRECTORY_NOT_FOUND, szMessage)
#define N_ERROR_DIRECTORY_NOT_FOUND_MPNA(szMessage, hPath) N_ERROR_MPNA(N_E_DIRECTORY_NOT_FOUND, szMessage, hPath)
#define N_ERROR_DIRECTORY_NOT_FOUND_MPA(szMessage, szPath) N_ERROR_MPA(N_E_DIRECTORY_NOT_FOUND, szMessage, szPath)
#ifndef N_NO_UNICODE
#define N_ERROR_DIRECTORY_NOT_FOUND_MW(szMessage) N_ERROR_MW(N_E_DIRECTORY_NOT_FOUND, szMessage)
#define N_ERROR_DIRECTORY_NOT_FOUND_MPNW(szMessage, hPath) N_ERROR_MPNW(N_E_DIRECTORY_NOT_FOUND, szMessage, hPath)
#define N_ERROR_DIRECTORY_NOT_FOUND_MPW(szMessage, szPath) N_ERROR_MPW(N_E_DIRECTORY_NOT_FOUND, szMessage, szPath)
#endif
#define N_ERROR_DIRECTORY_NOT_FOUND_M N_MACRO_AW(N_ERROR_DIRECTORY_NOT_FOUND_M)
#define N_ERROR_DIRECTORY_NOT_FOUND_MPN N_MACRO_AW(N_ERROR_DIRECTORY_NOT_FOUND_MPN)
#define N_ERROR_DIRECTORY_NOT_FOUND_MP N_MACRO_AW(N_ERROR_DIRECTORY_NOT_FOUND_MP)

#define N_ERROR_DRIVE_NOT_FOUND() N_ERROR(N_E_DRIVE_NOT_FOUND)
#define N_ERROR_DRIVE_NOT_FOUND_MA(szMessage) N_ERROR_MA(N_E_DRIVE_NOT_FOUND, szMessage)
#define N_ERROR_DRIVE_NOT_FOUND_MPNA(szMessage, hPath) N_ERROR_MPNA(N_E_DRIVE_NOT_FOUND, szMessage, hPath)
#define N_ERROR_DRIVE_NOT_FOUND_MPA(szMessage, szPath) N_ERROR_MPA(N_E_DRIVE_NOT_FOUND, szMessage, szPath)
#ifndef N_NO_UNICODE
#define N_ERROR_DRIVE_NOT_FOUND_MW(szMessage) N_ERROR_MW(N_E_DRIVE_NOT_FOUND, szMessage)
#define N_ERROR_DRIVE_NOT_FOUND_MPNW(szMessage, szPath) N_ERROR_MPNW(N_E_DRIVE_NOT_FOUND, szMessage, hPath)
#define N_ERROR_DRIVE_NOT_FOUND_MPW(szMessage, szPath) N_ERROR_MPW(N_E_DRIVE_NOT_FOUND, szMessage, szPath)
#endif
#define N_ERROR_DRIVE_NOT_FOUND_M N_MACRO_AW(N_ERROR_DRIVE_NOT_FOUND_M)
#define N_ERROR_DRIVE_NOT_FOUND_MPN N_MACRO_AW(N_ERROR_DRIVE_NOT_FOUND_MPN)
#define N_ERROR_DRIVE_NOT_FOUND_MP N_MACRO_AW(N_ERROR_DRIVE_NOT_FOUND_MP)

#define N_ERROR_END_OF_STREAM() N_ERROR(N_E_END_OF_STREAM)
#define N_ERROR_END_OF_STREAM_MA(szMessage) N_ERROR_MA(N_E_END_OF_STREAM, szMessage)
#ifndef N_NO_UNICODE
#define N_ERROR_END_OF_STREAM_MW(szMessage) N_ERROR_MW(N_E_END_OF_STREAM, szMessage)
#endif
#define N_ERROR_END_OF_STREAM_M N_MACRO_AW(N_ERROR_END_OF_STREAM_M)

#define N_ERROR_FILE_NOT_FOUND() N_ERROR(N_E_FILE_NOT_FOUND)
#define N_ERROR_FILE_NOT_FOUND_MA(szMessage) N_ERROR_MA(N_E_FILE_NOT_FOUND, szMessage)
#define N_ERROR_FILE_NOT_FOUND_MFNA(szMessage, hFileName) N_ERROR_MPNA(N_E_FILE_NOT_FOUND, szMessage, hFileName)
#define N_ERROR_FILE_NOT_FOUND_MFA(szMessage, szFileName) N_ERROR_MPA(N_E_FILE_NOT_FOUND, szMessage, szFileName)
#ifndef N_NO_UNICODE
#define N_ERROR_FILE_NOT_FOUND_MW(szMessage) N_ERROR_MW(N_E_FILE_NOT_FOUND, szMessage)
#define N_ERROR_FILE_NOT_FOUND_MFNW(szMessage, hFileName) N_ERROR_MPNW(N_E_FILE_NOT_FOUND, szMessage, hFileName)
#define N_ERROR_FILE_NOT_FOUND_MFW(szMessage, szFileName) N_ERROR_MPW(N_E_FILE_NOT_FOUND, szMessage, szFileName)
#endif
#define N_ERROR_FILE_NOT_FOUND_M N_MACRO_AW(N_ERROR_FILE_NOT_FOUND_M)
#define N_ERROR_FILE_NOT_FOUND_MFN N_MACRO_AW(N_ERROR_FILE_NOT_FOUND_MFN)
#define N_ERROR_FILE_NOT_FOUND_MF N_MACRO_AW(N_ERROR_FILE_NOT_FOUND_MF)

#define N_ERROR_FILE_LOAD() N_ERROR(N_E_FILE_LOAD)
#define N_ERROR_FILE_LOAD_MA(szMessage) N_ERROR_MA(N_E_FILE_LOAD, szMessage)
#define N_ERROR_FILE_LOAD_MFNA(szMessage, hFileName) N_ERROR_MPNA(N_E_FILE_LOAD, szMessage, hFileName)
#define N_ERROR_FILE_LOAD_MFA(szMessage, szFileName) N_ERROR_MPA(N_E_FILE_LOAD, szMessage, szFileName)
#ifndef N_NO_UNICODE
#define N_ERROR_FILE_LOAD_MW(szMessage) N_ERROR_MW(N_E_FILE_LOAD, szMessage)
#define N_ERROR_FILE_LOAD_MFNW(szMessage, hFileName) N_ERROR_MPNW(N_E_FILE_LOAD, szMessage, hFileName)
#define N_ERROR_FILE_LOAD_MFW(szMessage, szFileName) N_ERROR_MPW(N_E_FILE_LOAD, szMessage, szFileName)
#endif
#define N_ERROR_FILE_LOAD_M N_MACRO_AW(N_ERROR_FILE_LOAD_M)
#define N_ERROR_FILE_LOAD_MFN N_MACRO_AW(N_ERROR_FILE_LOAD_MFN)
#define N_ERROR_FILE_LOAD_MF N_MACRO_AW(N_ERROR_FILE_LOAD_MF)

#define N_ERROR_PATH_TOO_LONG() N_ERROR(N_E_PATH_TOO_LONG)
#define N_ERROR_PATH_TOO_LONG_MA(szMessage) N_ERROR_MA(N_E_PATH_TOO_LONG, szMessage)
#define N_ERROR_PATH_TOO_LONG_MPNA(szMessage, hPath) N_ERROR_MPNA(N_E_PATH_TOO_LONG, szMessage, hPath)
#define N_ERROR_PATH_TOO_LONG_MPA(szMessage, szPath) N_ERROR_MPA(N_E_PATH_TOO_LONG, szMessage, szPath)
#ifndef N_NO_UNICODE
#define N_ERROR_PATH_TOO_LONG_MW(szMessage) N_ERROR_MW(N_E_PATH_TOO_LONG, szMessage)
#define N_ERROR_PATH_TOO_LONG_MPNW(szMessage, hPath) N_ERROR_MPNW(N_E_PATH_TOO_LONG, szMessage, hPath)
#define N_ERROR_PATH_TOO_LONG_MPW(szMessage, szPath) N_ERROR_MPW(N_E_PATH_TOO_LONG, szMessage, szPath)
#endif
#define N_ERROR_PATH_TOO_LONG_M N_MACRO_AW(N_ERROR_PATH_TOO_LONG_M)
#define N_ERROR_PATH_TOO_LONG_MPN N_MACRO_AW(N_ERROR_PATH_TOO_LONG_MPN)
#define N_ERROR_PATH_TOO_LONG_MP N_MACRO_AW(N_ERROR_PATH_TOO_LONG_MP)

#define N_ERROR_KEY_NOT_FOUND() N_ERROR(N_E_KEY_NOT_FOUND)
#define N_ERROR_KEY_NOT_FOUND_MA(szMessage) N_ERROR_MA(N_E_KEY_NOT_FOUND, szMessage)
#ifndef N_NO_UNICODE
#define N_ERROR_KEY_NOT_FOUND_MW(szMessage) N_ERROR_MW(N_E_KEY_NOT_FOUND, szMessage)
#endif
#define N_ERROR_KEY_NOT_FOUND_M N_MACRO_AW(N_ERROR_KEY_NOT_FOUND_M)

#define N_ERROR_NOT_IMPLEMENTED() N_ERROR(N_E_NOT_IMPLEMENTED)
#define N_ERROR_NOT_IMPLEMENTED_MA(szMessage) N_ERROR_MA(N_E_NOT_IMPLEMENTED, szMessage)
#ifndef N_NO_UNICODE
#define N_ERROR_NOT_IMPLEMENTED_MW(szMessage) N_ERROR_MW(N_E_NOT_IMPLEMENTED, szMessage)
#endif
#define N_ERROR_NOT_IMPLEMENTED_M N_MACRO_AW(N_ERROR_NOT_IMPLEMENTED_M)

#define N_ERROR_NOT_SUPPORTED() N_ERROR(N_E_NOT_SUPPORTED)
#define N_ERROR_NOT_SUPPORTED_MA(szMessage) N_ERROR_MA(N_E_NOT_SUPPORTED, szMessage)
#ifndef N_NO_UNICODE
#define N_ERROR_NOT_SUPPORTED_MW(szMessage) N_ERROR_MW(N_E_NOT_SUPPORTED, szMessage)
#endif
#define N_ERROR_NOT_SUPPORTED_M N_MACRO_AW(N_ERROR_NOT_SUPPORTED_M)

#define N_ERROR_NULL_REFERENCE() N_ERROR(N_E_NULL_REFERENCE)
#define N_ERROR_NULL_REFERENCE_MA(szMessage) N_ERROR_MA(N_E_NULL_REFERENCE, szMessage)
#ifndef N_NO_UNICODE
#define N_ERROR_NULL_REFERENCE_MW(szMessage) N_ERROR_MW(N_E_NULL_REFERENCE, szMessage)
#endif
#define N_ERROR_NULL_REFERENCE_M N_MACRO_AW(N_ERROR_NULL_REFERENCE_M)

#define N_ERROR_OPERATION_CANCELED() N_ERROR(N_E_OPERATION_CANCELED)
#define N_ERROR_OPERATION_CANCELED_MA(szMessage) N_ERROR_MA(N_E_OPERATION_CANCELED, szMessage)
#ifndef N_NO_UNICODE
#define N_ERROR_OPERATION_CANCELED_MW(szMessage) N_ERROR_MW(N_OPERATION_CANCELED, szMessage)
#endif
#define N_ERROR_OPERATION_CANCELED_M N_MACRO_AW(N_ERROR_OPERATION_CANCELED)

#define N_ERROR_OUT_OF_MEMORY() N_ERROR(N_E_OUT_OF_MEMORY)
#define N_ERROR_OUT_OF_MEMORY_MA(szMessage) N_ERROR_MA(N_E_OUT_OF_MEMORY, szMessage)
#ifndef N_NO_UNICODE
#define N_ERROR_OUT_OF_MEMORY_MW(szMessage) N_ERROR_MW(N_E_OUT_OF_MEMORY, szMessage)
#endif
#define N_ERROR_OUT_OF_MEMORY_M N_MACRO_AW(N_ERROR_OUT_OF_MEMORY_M)

#define N_ERROR_SECURITY() N_ERROR(N_E_SECURITY)
#define N_ERROR_SECURITY_MA(szMessage) N_ERROR_MA(N_E_SECURITY, szMessage)
#ifndef N_NO_UNICODE
#define N_ERROR_SECURITY_MW(szMessage) N_ERROR_MW(N_E_SECURITY, szMessage)
#endif
#define N_ERROR_SECURITY_M N_MACRO_AW(N_ERROR_SECURITY_M)

#define N_ERROR_TIMEOUT() N_ERROR(N_E_TIMEOUT)
#define N_ERROR_TIMEOUT_MA(szMessage) N_ERROR_MA(N_E_TIMEOUT, szMessage)
#ifndef N_NO_UNICODE
#define N_ERROR_TIMEOUT_MW(szMessage) N_ERROR_MW(N_E_TIMEOUT, szMessage)
#endif
#define N_ERROR_TIMEOUT_M N_MACRO_AW(N_ERROR_TIMEOUT_M)

#define N_ERROR_EXTERNAL_EMN_(function, externalError, hMessage, flags) \
	{\
		N_THE_ERROR = NErrorSetLastMPN(N_E_EXTERNAL, hMessage, NULL, externalError, N_ERROR_MAKE_EXTERNALL_CALL_STACK(function), flags);\
		N_ERROR_APPEND\
		goto N_TRY_End;\
	}
#define N_ERROR_EXTERNAL_EM_A(function, externalError, szMessage, flags) \
	{\
		N_THE_ERROR = NErrorSetLastA(N_E_EXTERNAL, szMessage, NULL, externalError, N_ERROR_MAKE_EXTERNALL_CALL_STACKA(function), flags);\
		N_ERROR_APPEND\
		goto N_TRY_End;\
	}
#define N_ERROR_EXTERNAL_EMA(function, externalError, szMessage) N_ERROR_EXTERNAL_EM_A(function, externalError, szMessage, 0)
#define N_ERROR_EXTERNAL_MA(function, szMessage) N_ERROR_EXTERNAL_EMA(function, 0, szMessage)
#ifndef N_NO_UNICODE
#define N_ERROR_EXTERNAL_EM_W(function, externalError, szMessage, flags) \
	{\
		N_THE_ERROR = NErrorSetLastW(N_E_EXTERNAL, szMessage, NULL, externalError, N_ERROR_MAKE_EXTERNALL_CALL_STACKW(function), flags);\
		N_ERROR_APPEND\
		goto N_TRY_End;\
	}
#define N_ERROR_EXTERNAL_EMW(function, externalError, szMessage) N_ERROR_EXTERNAL_EM_W(function, externalError, szMessage, 0)
#define N_ERROR_EXTERNAL_MW(function, szMessage) N_ERROR_EXTERNAL_EMW(function, 0, szMessage)
#endif
#define N_ERROR_EXTERNAL_EM_ N_MACRO_AW(N_ERROR_EXTERNAL_EM_)
#define N_ERROR_EXTERNAL_EM N_MACRO_AW(N_ERROR_EXTERNAL_EM)
#define N_ERROR_EXTERNAL_M N_MACRO_AW(N_ERROR_EXTERNAL_M)
#define N_ERROR_EXTERNAL_E(function, comError) N_ERROR_EXTERNAL_EMN_(function, externalError, NULL, 0)
#define N_ERROR_EXTERNAL(function) N_ERROR_EXTERNAL_EMN_(function, 0, NULL, 0)

#define N_ERROR_CLR_EMN_(function, clrError, hMessage, flags) \
	{\
		N_THE_ERROR = NErrorSetMPN(N_E_CLR, hMessage, NULL, clrError, N_ERROR_MAKE_EXTERNALL_CALL_STACK(function), flags);\
		N_ERROR_APPEND\
		goto N_TRY_End;\
	}
#define N_ERROR_CLR_EM_A(function, clrError, szMessage, flags) \
	{\
		N_THE_ERROR = NErrorSetA(N_E_CLR, szMessage, NULL, clrError, N_ERROR_MAKE_EXTERNALL_CALL_STACKA(function), flags);\
		N_ERROR_APPEND\
		goto N_TRY_End;\
	}
#define N_ERROR_CLR_EMA(function, clrError, szMessage) N_ERROR_CLR_EM_A(function, clrError, szMessage, 0)
#ifndef N_NO_UNICODE
#define N_ERROR_CLR_EM_W(function, clrError, szMessage, flags) \
	{\
		N_THE_ERROR = NErrorSetW(N_E_CLR, szMessage, NULL, clrError, N_ERROR_MAKE_EXTERNALL_CALL_STACKW(function), flags);\
		N_ERROR_APPEND\
		goto N_TRY_End;\
	}
#define N_ERROR_CLR_EMW(function, clrError, szMessage) N_ERROR_CLR_EM_W(function, clrError, szMessage, 0)
#endif
#define N_ERROR_CLR_EM_ N_MACRO_AW(N_ERROR_CLR_EM_)
#define N_ERROR_CLR_EM N_MACRO_AW(N_ERROR_CLR_EM)
#define N_ERROR_CLR_E(function, clrError) N_ERROR_CLR_EMN_(function, clrError, NULL, 0)
#define N_ERROR_CLR(function) N_ERROR_CLR_EMN_(function, 0, NULL, 0)

#define N_ERROR_COM_EMNPN_(function, comError, hMessage, hParam, flags) \
	{\
		N_THE_ERROR = NErrorSetComMPN(comError, hMessage, hParam, N_ERROR_MAKE_EXTERNALL_CALL_STACK(function), flags);\
		N_ERROR_APPEND\
		goto N_TRY_End;\
	}
#define N_ERROR_COM_EMPN_A(function, comError, szMessage, hParam, flags) \
	{\
		N_THE_ERROR = NErrorSetComPNA(comError, szMessage, hParam, N_ERROR_MAKE_EXTERNALL_CALL_STACKA(function), flags);\
		N_ERROR_APPEND\
		goto N_TRY_End;\
	}
#define N_ERROR_COM_EMPNA(function, comError, szMessage, hParam) N_ERROR_COM_EMPN_A(function, comError, szMessage, hParam, 0)
#ifndef N_NO_UNICODE
#define N_ERROR_COM_EMPN_W(function, comError, szMessage, hParam, flags) \
	{\
		N_THE_ERROR = NErrorSetComPNW(comError, szMessage, hParam, N_ERROR_MAKE_EXTERNALL_CALL_STACKW(function), flags);\
		N_ERROR_APPEND\
		goto N_TRY_End;\
	}
#define N_ERROR_COM_EMPNW(function, comError, szMessage, hParam) N_ERROR_COM_EMPN_W(function, comError, szMessage, hParam, 0)
#endif
#define N_ERROR_COM_EMPN_ N_MACRO_AW(N_ERROR_COM_EMPN_)
#define N_ERROR_COM_EMPN N_MACRO_AW(N_ERROR_COM_EMPN)
#define N_ERROR_COM_EPN(function, comError, hParam) N_ERROR_COM_EMNPN_(function, comError, NULL, hParam, 0)
#define N_ERROR_COM_EMP_A(function, comError, szMessage, szParam, flags) \
	{\
		N_THE_ERROR = NErrorSetComA(comError, szMessage, szParam, N_ERROR_MAKE_EXTERNALL_CALL_STACKA(function), flags);\
		N_ERROR_APPEND\
		goto N_TRY_End;\
	}
#define N_ERROR_COM_EMPA(function, comError, szMessage, szParam) N_ERROR_COM_EMP_A(function, comError, szMessage, szParam, 0)
#define N_ERROR_COM_EMA(function, comError, szMessage) N_ERROR_COM_EMPA(function, comError, szMessage, NULL)
#define N_ERROR_COM_EPA(function, comError, szParam) N_ERROR_COM_EMPA(function, comError, NULL, szParam)
#ifndef N_NO_UNICODE
#define N_ERROR_COM_EMP_W(function, comError, szMessage, szParam, flags) \
	{\
		N_THE_ERROR = NErrorSetComW(comError, szMessage, szParam, N_ERROR_MAKE_EXTERNALL_CALL_STACKW(function), flags);\
		N_ERROR_APPEND\
		goto N_TRY_End;\
	}
#define N_ERROR_COM_EMPW(function, comError, szMessage, szParam) N_ERROR_COM_EMP_W(function, comError, szMessage, szParam, 0)
#define N_ERROR_COM_EMW(function, comError, szMessage) N_ERROR_COM_EMPW(function, comError, szMessage, NULL)
#define N_ERROR_COM_EPW(function, comError, szParam) N_ERROR_COM_EMPW(function, comError, NULL, szParam)
#endif
#define N_ERROR_COM_EMP_ N_MACRO_AW(N_ERROR_COM_EMP_)
#define N_ERROR_COM_EMP N_MACRO_AW(N_ERROR_COM_EMP)
#define N_ERROR_COM_EM N_MACRO_AW(N_ERROR_COM_EM)
#define N_ERROR_COM_EP N_MACRO_AW(N_ERROR_COM_EP)
#define N_ERROR_COM_E(function, comError) N_ERROR_COM_EMNPN_(function, comError, NULL, NULL, 0)
#define N_ERROR_COM(function) N_ERROR_COM_EMNPN_(function, 0, NULL, NULL, 0)

#define N_CHECK_COM(function, result) \
	{\
		NInt N_CHECK_COM_result = (NInt)(result);\
		if (N_UNLIKELY(N_CHECK_COM_result < 0))\
		{\
			N_ERROR_COM_E(function, N_CHECK_COM_result);\
		}\
	}

#define N_ERROR_CPP_MN_(function, hMessage, flags) \
	{\
		N_THE_ERROR = NErrorSetLastMPN(N_E_CPP, hMessage, NULL, N_ERROR_MAKE_EXTERNALL_CALL_STACK(function), NULL, 0, flags);\
		N_ERROR_APPEND\
		goto N_TRY_End;\
	}
#define N_ERROR_CPP_M_A(function, szMessage, flags) \
	{\
		N_THE_ERROR = NErrorSetLastA(N_E_CPP, szMessage, NULL, N_ERROR_MAKE_EXTERNALL_CALL_STACKA(function), NULL, 0, flags);\
		N_ERROR_APPEND\
		goto N_TRY_End;\
	}
#define N_ERROR_CPP_MA(function, szMessage) N_ERROR_CPP_M_A(function, szMessage, 0)
#ifndef N_NO_UNICODE
#define N_ERROR_CPP_M_W(function, szMessage, flags) \
	{\
		N_THE_ERROR = NErrorSetLastW(N_E_CPP, szMessage, NULL, 0, N_ERROR_MAKE_EXTERNALL_CALL_STACKW(function), flags);\
		N_ERROR_APPEND\
		goto N_TRY_End;\
	}
#define N_ERROR_CPP_MW(function, szMessage) N_ERROR_CPP_M_W(function, szMessage, 0)
#endif
#define N_ERROR_CPP_M_ N_MACRO_AW(N_ERROR_CPP_M_)
#define N_ERROR_CPP_M N_MACRO_AW(N_ERROR_CPP_M)
#define N_ERROR_CPP(function) N_ERROR_CPP_MN_(function, NULL, 0)

#define N_ERROR_JVM_MN_(function, hMessage, flags) \
	{\
		N_THE_ERROR = NErrorSetMPN(N_E_JVM, hMessage, NULL, 0, N_ERROR_MAKE_EXTERNALL_CALL_STACK(function), flags);\
		N_ERROR_APPEND\
		goto N_TRY_End;\
	}
#define N_ERROR_JVM_M_A(function, szMessage, flags) \
	{\
		N_THE_ERROR = NErrorSetA(N_E_JVM, szMessage, NULL, 0, N_ERROR_MAKE_EXTERNALL_CALL_STACKA(function), flags);\
		N_ERROR_APPEND\
		goto N_TRY_End;\
	}
#define N_ERROR_JVM_MA(function, szMessage) N_ERROR_JVM_M_A(function, szMessage, 0)
#ifndef N_NO_UNICODE
#define N_ERROR_JVM_M_W(function, szMessage, flags) \
	{\
		N_THE_ERROR = NErrorSetW(N_E_JVM, szMessage, NULL, 0, N_ERROR_MAKE_EXTERNALL_CALL_STACKW(function), flags);\
		N_ERROR_APPEND\
		goto N_TRY_End;\
	}
#define N_ERROR_JVM_MW(function, szMessage) N_ERROR_JVM_M_W(function, szMessage, 0)
#endif
#define N_ERROR_JVM_M_ N_MACRO_AW(N_ERROR_JVM_M_)
#define N_ERROR_JVM_M N_MACRO_AW(N_ERROR_JVM_M)
#define N_ERROR_JVM(function) N_ERROR_JVM_MN_(function, NULL, 0)

#define N_ERROR_MACH_EMNPN_(function, machError, hMessage, hParam, flags) \
	{\
		N_THE_ERROR = NErrorSetMachMPN(machError, hMessage, hParam, N_ERROR_MAKE_EXTERNALL_CALL_STACK(function), flags);\
		N_ERROR_APPEND\
		goto N_TRY_End;\
	}
#define N_ERROR_MACH_EMPN_A(function, machError, szMessage, hParam, flags) \
	{\
		N_THE_ERROR = NErrorSetMachPNA(machError, szMessage, hParam, N_ERROR_MAKE_EXTERNALL_CALL_STACKA(function), flags);\
		N_ERROR_APPEND\
		goto N_TRY_End;\
	}
#define N_ERROR_MACH_EMPNA(function, machError, szMessage, hParam) N_ERROR_MACH_EMPN_A(function, machError, szMessage, hParam, 0)
#ifndef N_NO_UNICODE
#define N_ERROR_MACH_EMPN_W(function, machError, szMessage, hParam, flags) \
	{\
		N_THE_ERROR = NErrorSetMachPNW(machError, szMessage, hParam, flags);\
		N_ERROR_APPEND\
		goto N_TRY_End;\
	}
#define N_ERROR_MACH_EMPNW(function, machError, szMessage, hParam) N_ERROR_MACH_EMPN_W(function, machError, szMessage, hParam, 0)
#endif
#define N_ERROR_MACH_EMPN_ N_MACRO_AW(N_ERROR_MACH_EMPN_)
#define N_ERROR_MACH_EMPN N_MACRO_AW(N_ERROR_MACH_EMPN)
#define N_ERROR_MACH_EPN(function, machError, hParam) N_ERROR_MACH_EMNPN_(function, machError, NULL, hParam, 0)
#define N_ERROR_MACH_EMP_A(function, machError, szMessage, szParam, flags) \
	{\
		N_THE_ERROR = NErrorSetMachA(machError, szMessage, szParam, N_ERROR_MAKE_EXTERNALL_CALL_STACKA(function), flags);\
		N_ERROR_APPEND\
		goto N_TRY_End;\
	}
#define N_ERROR_MACH_EMPA(function, machError, szMessage, szParam) N_ERROR_MACH_EMP_A(function, machError, szMessage, szParam, 0)
#define N_ERROR_MACH_EMA(function, machError, szMessage) N_ERROR_MACH_EMPA(function, machError, szMessage, NULL)
#define N_ERROR_MACH_EPA(function, machError, szParam) N_ERROR_MACH_EMPA(function, machError, NULL, szParam)
#ifndef N_NO_UNICODE
#define N_ERROR_MACH_EMP_W(function, machError, szMessage, szParam, flags) \
	{\
		N_THE_ERROR = NErrorSetMachW(machError, szMessage, szParam, N_ERROR_MAKE_EXTERNALL_CALL_STACKW(function), flags);\
		N_ERROR_APPEND\
		goto N_TRY_End;\
	}
#define N_ERROR_MACH_EMPW(function, machError, szMessage, szParam) N_ERROR_MACH_EMP_W(function, macHError, szMessage, szParam, 0)
#define N_ERROR_MACH_EMW(function, machError, szMessage) N_ERROR_MACH_EMPW(function, machError, szMessage, NULL)
#define N_ERROR_MACH_EPW(function, machError, szParam) N_ERROR_MACH_EMPW(function, machError, NULL, szParam)
#endif
#define N_ERROR_MACH_EMP_ N_MACRO_AW(N_ERROR_MACH_EMP_)
#define N_ERROR_MACH_EMP N_MACRO_AW(N_ERROR_MACH_EMP)
#define N_ERROR_MACH_EM N_MACRO_AW(N_ERROR_MACH_EM)
#define N_ERROR_MACH_EP N_MACRO_AW(N_ERROR_MACH_EP)
#define N_ERROR_MACH_E(function, machError) N_ERROR_MACH_EMNPN_(function, machError, NULL, NULL, 0)

#define N_CHECK_MACH(function, result) \
	{\
		kern_return_t N_CHECK_MACH_result = (result);\
		if (N_UNLIKELY(N_CHECK_MACH_result != 0))\
		{\
			N_ERROR_MACH_E(function, N_CHECK_MACH_result);\
		}\
	}

#define N_ERROR_MAC_EMNPN_(function, macError, hMessage, hParam, flags) \
	{\
		N_THE_ERROR = NErrorSetMacMPN(macError, hMessage, hParam, N_ERROR_MAKE_EXTERNALL_CALL_STACK(function), flags);\
		N_ERROR_APPEND\
		goto N_TRY_End;\
	}
#define N_ERROR_MAC_EMPN_A(function, macError, szMessage, hParam, flags) \
	{\
		N_THE_ERROR = NErrorSetMacPNA(macError, szMessage, hParam, N_ERROR_MAKE_EXTERNALL_CALL_STACKA(function), flags);\
		N_ERROR_APPEND\
		goto N_TRY_End;\
	}
#define N_ERROR_MAC_EMPNA(function, macError, szMessage, hParam) N_ERROR_MAC_EMPN_A(function, macError, szMessage, hParam, 0)
#ifndef N_NO_UNICODE
#define N_ERROR_MAC_EMPN_W(function, macError, szMessage, hParam, flags) \
	{\
		N_THE_ERROR = NErrorSetMacPNW(macError, szMessage, hParam, N_ERROR_MAKE_EXTERNALL_CALL_STACKW(function), flags);\
		N_ERROR_APPEND\
		goto N_TRY_End;\
	}
#define N_ERROR_MAC_EMPNW(function, macError, szMessage, hParam) N_ERROR_MAC_EMPN_W(function, macError, szMessage, hParam, 0)
#endif
#define N_ERROR_MAC_EMPN_ N_MACRO_AW(N_ERROR_MAC_EMPN_)
#define N_ERROR_MAC_EMPN N_MACRO_AW(N_ERROR_MAC_EMPN)
#define N_ERROR_MAC_EPN(function, macError, hParam) N_ERROR_MAC_EMNPN_(function, macError, NULL, hParam, 0)
#define N_ERROR_MAC_EMP_A(function, macError, szMessage, szParam, flags) \
	{\
		N_THE_ERROR = NErrorSetMacA(macError, szMessage, szParam, N_ERROR_MAKE_EXTERNALL_CALL_STACKA(function), flags);\
		N_ERROR_APPEND\
		goto N_TRY_End;\
	}
#define N_ERROR_MAC_EMPA(function, macError, szMessage, szParam) N_ERROR_MAC_EMP_A(function, macError, szMessage, szParam, isDirectoryAccess, 0)
#define N_ERROR_MAC_EMA(function, macError, szMessage) N_ERROR_MAC_EMPA(function, macError, szMessage, NULL)
#define N_ERROR_MAC_EPA(function, macError, szParam) N_ERROR_MAC_EMPA(function, macError, NULL, szParam)
#ifndef N_NO_UNICODE
#define N_ERROR_MAC_EMP_W(function, macError, szMessage, szParam, flags) \
	{\
		N_THE_ERROR = NErrorSetMacW(macError, szMessage, szParam, N_ERROR_MAKE_EXTERNALL_CALL_STACKW(function), flags);\
		N_ERROR_APPEND\
		goto N_TRY_End;\
	}
#define N_ERROR_MAC_EMPW(function, macError, szMessage, szParam) N_ERROR_MAC_EMP_W(function, macError, szMessage, szParam, 0)
#define N_ERROR_MAC_EMW(function, macError, szMessage) N_ERROR_MAC_EMPW(function, macError, szMessage, NULL)
#define N_ERROR_MAC_EPW(function, macError, szParam) N_ERROR_MAC_EMPW(function, macError, NULL, szParam)
#endif
#define N_ERROR_MAC_EMP_ N_MACRO_AW(N_ERROR_MAC_EMP_)
#define N_ERROR_MAC_EMP N_MACRO_AW(N_ERROR_MAC_EMP)
#define N_ERROR_MAC_EM N_MACRO_AW(N_ERROR_MAC_EM)
#define N_ERROR_MAC_EP N_MACRO_AW(N_ERROR_MAC_EP)
#define N_ERROR_MAC_E(function, macError) N_ERROR_MAC_EMNPN_(function, macError, NULL, NULL, 0)

#define N_CHECK_MAC(function, result) \
	{\
		OSStatus N_CHECK_MAC_result = (result);\
		if (N_UNLIKELY(N_CHECK_MAC_result != 0))\
		{\
			N_ERROR_MAC_E(function, N_CHECK_MAC_result);\
		}\
	}

#define N_ERROR_SYS_EMNPN_(function, sysError, hMessage, hParam, flags) \
	{\
		N_THE_ERROR = NErrorSetSysMPN(sysError, hMessage, hParam, N_ERROR_MAKE_EXTERNALL_CALL_STACK(function), flags);\
		N_ERROR_APPEND\
		goto N_TRY_End;\
	}
#define N_ERROR_SYS_EMPN_A(function, sysError, szMessage, hParam, flags) \
	{\
		N_THE_ERROR = NErrorSetSysPNA(sysError, szMessage, hParam, N_ERROR_MAKE_EXTERNALL_CALL_STACKA(function), flags);\
		N_ERROR_APPEND\
		goto N_TRY_End;\
	}
#define N_ERROR_SYS_EMPNA(function, sysError, szMessage, hParam) N_ERROR_SYS_EMPN_A(function, sysError, szMessage, hParam, 0)
#define N_ERROR_SYS_MPNA(function, szMessage, hParam) N_ERROR_SYS_EMPNA(function, NErrorGetLastSysError(), szMessage, hParam)
#ifndef N_NO_UNICODE
#define N_ERROR_SYS_EMPN_W(function, sysError, szMessage, hParam, flags) \
	{\
		N_THE_ERROR = NErrorSetSysPNW(sysError, szMessage, hParam, N_ERROR_MAKE_EXTERNALL_CALL_STACKW(function), flags);\
		N_ERROR_APPEND\
		goto N_TRY_End;\
	}
#define N_ERROR_SYS_EMPNW(function, sysError, szMessage, hParam) N_ERROR_SYS_EMPN_W(function, sysError, szMessage, hParam, 0)
#define N_ERROR_SYS_MPNW(function, szMessage, hParam) N_ERROR_SYS_EMPNW(function, NErrorGetLastSysError(), szMessage, hParam)
#endif
#define N_ERROR_SYS_EMPN_ N_MACRO_AW(N_ERROR_SYS_EMPN_)
#define N_ERROR_SYS_EMPN N_MACRO_AW(N_ERROR_SYS_EMPN)
#define N_ERROR_SYS_MPN N_MACRO_AW(N_ERROR_SYS_MPN)
#define N_ERROR_SYS_EPN(function, sysError, hParam) N_ERROR_SYS_EMNPN_(function, sysError, NULL, hParam, 0)
#define N_ERROR_SYS_PN(function, hParam) N_ERROR_SYS_EMNPN_(function, NErrorGetLastSysError(), NULL, hParam, 0)
#define N_ERROR_SYS_EMP_A(function, sysError, szMessage, szParam, flags) \
	{\
		N_THE_ERROR = NErrorSetSysA(sysError, szMessage, szParam, N_ERROR_MAKE_EXTERNALL_CALL_STACKA(function), flags);\
		N_ERROR_APPEND\
		goto N_TRY_End;\
	}
#define N_ERROR_SYS_EMPA(function, sysError, szMessage, szParam) N_ERROR_SYS_EMP_A(function, sysError, szMessage, szParam, 0)
#define N_ERROR_SYS_EMA(function, sysError, szMessage) N_ERROR_SYS_EMPA(function, sysError, szMessage, NULL)
#define N_ERROR_SYS_MPA(function, szMessage, szParam) N_ERROR_SYS_EMPA(function, NErrorGetLastSysError(), szMessage, szParam)
#define N_ERROR_SYS_EPA(function, sysError, szParam) N_ERROR_SYS_EMPA(function, sysError, NULL, szParam)
#define N_ERROR_SYS_PA(function, szParam) N_ERROR_SYS_MPA(function, NULL, szParam)
#define N_ERROR_SYS_MA(function, szMessage) N_ERROR_SYS_MPA(function, szMessage, NULL)
#ifndef N_NO_UNICODE
#define N_ERROR_SYS_EMP_W(function, sysError, szMessage, szParam, flags) \
	{\
		N_THE_ERROR = NErrorSetSysW(sysError, szMessage, szParam, N_ERROR_MAKE_EXTERNALL_CALL_STACKW(function), flags);\
		N_ERROR_APPEND\
		goto N_TRY_End;\
	}
#define N_ERROR_SYS_EMPW(function, sysError, szMessage, szParam) N_ERROR_SYS_EMP_W(function, sysError, szMessage, szParam, isDirectoryAccess, 0)
#define N_ERROR_SYS_EMW(function, sysError, szMessage) N_ERROR_SYS_EMPW(function, sysError, szMessage, NULL)
#define N_ERROR_SYS_MPW(function, szMessage, szParam) N_ERROR_SYS_EMPW(function, NErrorGetLastSysError(), szMessage, szParam)
#define N_ERROR_SYS_EPW(function, sysError, szParam) N_ERROR_SYS_EMPW(function, sysError, NULL, szParam)
#define N_ERROR_SYS_PW(function, szParam) N_ERROR_SYS_MPW(function, NULL, szParam)
#define N_ERROR_SYS_MW(function, szMessage) N_ERROR_SYS_MPW(function, szMessage, NULL)
#endif
#define N_ERROR_SYS_EMP_ N_MACRO_AW(N_ERROR_SYS_EMP_)
#define N_ERROR_SYS_EMP N_MACRO_AW(N_ERROR_SYS_EMP)
#define N_ERROR_SYS_EM N_MACRO_AW(N_ERROR_SYS_EM)
#define N_ERROR_SYS_MP N_MACRO_AW(N_ERROR_SYS_MP)
#define N_ERROR_SYS_EP N_MACRO_AW(N_ERROR_SYS_EP)
#define N_ERROR_SYS_P N_MACRO_AW(N_ERROR_SYS_P)
#define N_ERROR_SYS_M N_MACRO_AW(N_ERROR_SYS_M)
#define N_ERROR_SYS_E(function, sysError) N_ERROR_SYS_EMNPN_(function, sysError, NULL, NULL, 0)
#define N_ERROR_SYS(function) N_ERROR_SYS_EMNPN_(function, NErrorGetLastSysError(), NULL, NULL, 0)

#define N_CHECK_SYS(function, result) \
	{\
		if (N_UNLIKELY((result) == 0))\
		{\
			N_ERROR_SYS(function);\
		}\
	}

#define N_CHECK_SYS_RET(function, result) \
	{\
		NInt N_CHECK_SYS_RET_result = (result);\
		if (N_UNLIKELY(N_CHECK_SYS_RET_result != 0))\
		{\
			N_ERROR_SYS_E(function, N_CHECK_SYS_RET_result);\
		}\
	}

#define N_ERROR_WIN32_EMNPN_(function, win32Error, hMessage, hParam, flags) \
	{\
		N_THE_ERROR = NErrorSetWin32MPN(win32Error, hMessage, hParam, N_ERROR_MAKE_EXTERNALL_CALL_STACK(function), flags);\
		N_ERROR_APPEND\
		goto N_TRY_End;\
	}
#define N_ERROR_WIN32_EMPN_A(function, win32Error, szMessage, hParam, flags) \
	{\
		N_THE_ERROR = NErrorSetWin32PNA(win32Error, szMessage, hParam, N_ERROR_MAKE_EXTERNALL_CALL_STACKA(function), flags);\
		N_ERROR_APPEND\
		goto N_TRY_End;\
	}
#define N_ERROR_WIN32_EMPNA(function, win32Error, szMessage, hParam) N_ERROR_WIN32_EMPN_A(function, win32Error, szMessage, hParam, 0)
#define N_ERROR_WIN32_MPNA(function, szMessage, hParam) N_ERROR_WIN32_EMPNA(function, NErrorGetLastWin32Error(), szMessage, hParam)
#ifndef N_NO_UNICODE
#define N_ERROR_WIN32_EMPN_W(function, win32Error, szMessage, hParam, flags) \
	{\
		N_THE_ERROR = NErrorSetWin32PNW(win32Error, szMessage, hParam, N_ERROR_MAKE_EXTERNALL_CALL_STACKW(function), flags);\
		N_ERROR_APPEND\
		goto N_TRY_End;\
	}
#define N_ERROR_WIN32_EMPNW(function, win32Error, szMessage, hParam) N_ERROR_WIN32_EMPN_W(function, win32Error, szMessage, hParam, 0)
#define N_ERROR_WIN32_EMPN_ N_MACRO_AW(N_ERROR_WIN32_EMPN_)
#define N_ERROR_WIN32_EMPN N_MACRO_AW(N_ERROR_WIN32_EMPN)
#define N_ERROR_WIN32_MPNW(function, szMessage, hParam) N_ERROR_WIN32_EMPNW(function, NErrorGetLastWin32Error(), szMessage, hParam)
#endif
#define N_ERROR_WIN32_MPN N_MACRO_AW(N_ERROR_WIN32_MPN)
#define N_ERROR_WIN32_EPN(function, win32Error, hParam) N_ERROR_WIN32_EMNPN_(function, win32Error, NULL, hParam, 0)
#define N_ERROR_WIN32_PN(function, hParam) N_ERROR_WIN32_EMNPN_(function, NErrorGetLastWin32Error(), NULL, hParam, 0)
#define N_ERROR_WIN32_EMP_A(function, win32Error, szMessage, szParam, flags) \
	{\
		N_THE_ERROR = NErrorSetWin32A(win32Error, szMessage, szParam, N_ERROR_MAKE_EXTERNALL_CALL_STACKA(function), flags);\
		N_ERROR_APPEND\
		goto N_TRY_End;\
	}
#define N_ERROR_WIN32_EMPA(function, win32Error, szMessage, szParam) N_ERROR_WIN32_EMP_A(function, win32Error, szMessage, szParam, 0)
#define N_ERROR_WIN32_EMA(function, win32Error, szMessage) N_ERROR_WIN32_EMPA(function, win32Error, szMessage, NULL)
#define N_ERROR_WIN32_MPA(function, szMessage, szParam) N_ERROR_WIN32_EMPA(function, NErrorGetLastWin32Error(), szMessage, szParam)
#define N_ERROR_WIN32_EPA(function, win32Error, szParam) N_ERROR_WIN32_EMPA(function, win32Error, NULL, szParam)
#define N_ERROR_WIN32_PA(function, szParam) N_ERROR_WIN32_MPA(function, NULL, szParam)
#define N_ERROR_WIN32_MA(function, szMessage) N_ERROR_WIN32_MPA(function, szMessage, NULL)
#ifndef N_NO_UNICODE
#define N_ERROR_WIN32_EMP_W(function, win32Error, szMessage, szParam, flags) \
	{\
		N_THE_ERROR = NErrorSetWin32W(win32Error, szMessage, szParam, N_ERROR_MAKE_EXTERNALL_CALL_STACKW(function), NE_PRESERVE_INNER_ERROR);\
		N_ERROR_APPEND\
		goto N_TRY_End;\
	}
#define N_ERROR_WIN32_EMPW(function, win32Error, szMessage, szParam) N_ERROR_WIN32_EMP_W(function, win32Error, szMessage, szParam, 0)
#define N_ERROR_WIN32_EMW(function, win32Error, szMessage) N_ERROR_WIN32_EMPW(function, win32Error, szMessage, NULL)
#define N_ERROR_WIN32_MPW(function, szMessage, szParam) N_ERROR_WIN32_EMPW(function, NErrorGetLastWin32Error(), szMessage, szParam)
#define N_ERROR_WIN32_EPW(function, win32Error, szParam) N_ERROR_WIN32_EMPW(function, win32Error, NULL, szParam)
#define N_ERROR_WIN32_PW(function, szParam) N_ERROR_WIN32_MPW(function, NULL, szParam)
#define N_ERROR_WIN32_MW(function, szMessage) N_ERROR_WIN32_MPW(function, szMessage, NULL)
#endif
#define N_ERROR_WIN32_EMP_ N_MACRO_AW(N_ERROR_WIN32_EMP_)
#define N_ERROR_WIN32_EMP N_MACRO_AW(N_ERROR_WIN32_EMP)
#define N_ERROR_WIN32_EM N_MACRO_AW(N_ERROR_WIN32_EM)
#define N_ERROR_WIN32_MP N_MACRO_AW(N_ERROR_WIN32_MP)
#define N_ERROR_WIN32_EP N_MACRO_AW(N_ERROR_WIN32_EP)
#define N_ERROR_WIN32_P N_MACRO_AW(N_ERROR_WIN32_P)
#define N_ERROR_WIN32_M N_MACRO_AW(N_ERROR_WIN32_M)
#define N_ERROR_WIN32_E(function, win32Error) N_ERROR_WIN32_EMNPN_(function, win32Error, NULL, NULL, 0)
#define N_ERROR_WIN32(function) N_ERROR_WIN32_EMNPN_(function, NErrorGetLastWin32Error(), NULL, NULL, 0)

#define N_CHECK_WIN32(function, result) \
	{\
		if (N_UNLIKELY((result) == 0))\
		{\
			N_ERROR_WIN32(function);\
		}\
	}

#define N_CHECK_WIN32_RET(function, result) \
	{\
		NInt N_CHECK_WIN32_RET_res = (result);\
		if (N_UNLIKELY(N_CHECK_WIN32_RET_res != 0))\
		{\
			N_ERROR_WIN32_E(function, N_CHECK_WIN32_RET_res);\
		}\
	}

#define N_ERROR_PARAMETER() N_ERROR(N_E_PARAMETER)
#define N_ERROR_PARAMETER_MA(szMessage) N_ERROR_MA(N_E_PARAMETER, szMessage)
#ifndef N_NO_UNICODE
#define N_ERROR_PARAMETER_MW(szMessage) N_ERROR_MW(N_E_PARAMETER, szMessage)
#endif
#define N_ERROR_PARAMETER_M N_MACRO_AW(N_ERROR_PARAMETER_M)

#define N_ERROR_PARAMETER_READ_ONLY() N_ERROR(N_E_PARAMETER_READ_ONLY)
#define N_ERROR_PARAMETER_READ_ONLY_MA(szMessage) N_ERROR_MA(N_E_PARAMETER_READ_ONLY, szMessage)
#ifndef N_NO_UNICODE
#define N_ERROR_PARAMETER_READ_ONLY_MW(szMessage) N_ERROR_MW(N_E_PARAMETER_READ_ONLY, szMessage)
#endif
#define N_ERROR_PARAMETER_READ_ONLY_M N_MACRO_AW(N_ERROR_PARAMETER_READ_ONLY_M)

#define N_ERROR_NOT_ACTIVATED() N_ERROR(N_E_NOT_ACTIVATED)
#define N_ERROR_NOT_ACTIVATED_MA(szMessage) N_ERROR_MA(N_E_NOT_ACTIVATED, szMessage)
#ifndef N_NO_UNICODE
#define N_ERROR_NOT_ACTIVATED_MW(szMessage) N_ERROR_MW(N_E_NOT_ACTIVATED, szMessage)
#endif
#define N_ERROR_NOT_ACTIVATED_M N_MACRO_AW(N_ERROR_NOT_ACTIVATED_M)

#define N_FINALLY \
	N_UNREFERENCED_PARAMETER(N_THE_ERROR);\
	N_TRY_End: if (!N_FINALLY_entered) { N_FINALLY_entered = NTrue; {

#define N_TRY_END_RAW } }

#define N_THE_ERROR N_TRY_result
#define N_WAS_ERROR NFailed(N_THE_ERROR)

#define N_TRY_END \
	N_TRY_END_RAW\
	return N_THE_ERROR;

#define N_TRY_ENDNR \
	N_TRY_END_RAW\
	if (N_WAS_ERROR) NErrorSuppress(N_THE_ERROR);\
	if (NSucceeded(N_TRY_NR_res))\
	{\
		NErrorSetLastEx(N_TRY_hError, NE_NO_CALL_STACK);\
		if (N_TRY_hError) NObjectUnref(N_TRY_hError);\
	}

#define N_TRY_ENDC(result, hError) \
	N_TRY_END_RAW\
	if (N_WAS_ERROR)\
	{\
		(result) = N_THE_ERROR;\
		NErrorGetLastEx(0, &(hError));\
	}

#define N_TRY_ENDCNR(useContext, result, hError) \
	N_TRY_END_RAW\
	if (N_WAS_ERROR)\
	{\
		if (useContext) \
		{\
			(result) = N_THE_ERROR;\
			NErrorGetLastEx(0, &(hError));\
		}\
		else\
		{\
			NErrorSuppress(N_THE_ERROR);\
		}\
	}

#define N_TRY_E \
	N_FINALLY\
	N_TRY_END

#define N_TRY_ENR \
	N_FINALLY\
	N_TRY_ENDNR

#define N_TRY_EC(result, hError) \
	N_FINALLY\
	N_TRY_ENDC(result, hError)

#define N_TRY_ECNR(useContext, result, hError) \
	N_FINALLY\
	N_TRY_ENDCNR(useContext, result, hError)

#if !defined(N_ERROR_HPP_INCLUDED) && !defined(N_OBJECT_HPP_INCLUDED)
#ifdef N_MSVC
	#pragma deprecated("N_E_PARAMETER", "N_E_PARAMETER_READ_ONLY")
#endif
#endif

#ifdef N_CPP
}
#endif

#endif // !N_ERROR_H_INCLUDED
