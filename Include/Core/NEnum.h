#ifndef N_ENUM_H_INCLUDED
#define N_ENUM_H_INCLUDED

#include <Core/NType.h>

#ifdef N_CPP
extern "C"
{
#endif

NResult N_API NEnumToStringN(HNType hType, NInt value, HNString hFormat, HNString * phValue);
NResult N_API NEnumToStringPA(NTypeOfProc pTypeOf, NInt value, const NAChar * szFormat, HNString * phValue);
#ifndef N_NO_UNICODE
NResult N_API NEnumToStringPW(NTypeOfProc pTypeOf, NInt value, const NWChar * szFormat, HNString * phValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NEnumToStringP(NTypeOfProc pTypeOf, NInt value, const NChar * szFormat, HNString * phValue);
#endif
#define NEnumToStringP N_FUNC_AW(NEnumToStringP)

NResult N_API NEnumTryParseN(HNType hType, HNString hValue, HNString hFormat, NInt * pValue, NBool * pResult);
NResult N_API NEnumTryParsePVNA(NTypeOfProc pTypeOf, HNString hValue, const NAChar * szFormat, NInt * pValue, NBool * pResult);
#ifndef N_NO_UNICODE
NResult N_API NEnumTryParsePVNW(NTypeOfProc pTypeOf, HNString hValue, const NWChar * szFormat, NInt * pValue, NBool * pResult);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NEnumTryParsePVN(NTypeOfProc pTypeOf, HNString hValue, const NChar * szFormat, NInt * pValue, NBool * pResult);
#endif
#define NEnumTryParsePVN N_FUNC_AW(NEnumTryParsePVN)

NResult N_API NEnumTryParsePA(NTypeOfProc pTypeOf, const NAChar * szValue, const NAChar * szFormat, NInt * pValue, NBool * pResult);
#ifndef N_NO_UNICODE
NResult N_API NEnumTryParsePW(NTypeOfProc pTypeOf, const NWChar * szValue, const NWChar * szFormat, NInt * pValue, NBool * pResult);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NEnumTryParseP(NTypeOfProc pTypeOf, const NChar * szValue, const NChar * szFormat, NInt * pValue, NBool * pResult);
#endif
#define NEnumTryParseP N_FUNC_AW(NEnumTryParseP)

NResult N_API NEnumParseN(HNType hType, HNString hValue, HNString hFormat, NInt * pValue);
NResult N_API NEnumParsePVNA(NTypeOfProc pTypeOf, HNString hValue, const NAChar * szFormat, NInt * pValue);
#ifndef N_NO_UNICODE
NResult N_API NEnumParsePVNW(NTypeOfProc pTypeOf, HNString hValue, const NWChar * szFormat, NInt * pValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NEnumParsePVN(NTypeOfProc pTypeOf, HNString hValue, const NChar * szFormat, NInt * pValue);
#endif
#define NEnumParsePVN N_FUNC_AW(NEnumParsePVN)

NResult N_API NEnumParsePA(NTypeOfProc pTypeOf, const NAChar * szValue, const NAChar * szFormat, NInt * pValue);
#ifndef N_NO_UNICODE
NResult N_API NEnumParsePW(NTypeOfProc pTypeOf, const NWChar * szValue, const NWChar * szFormat, NInt * pValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NEnumParseP(NTypeOfProc pTypeOf, const NChar * szValue, const NChar * szFormat, NInt * pValue);
#endif
#define NEnumParseP N_FUNC_AW(NEnumParseP)

NResult N_API NEnumGetValues(HNType hType, NInt * arValues, NInt * pValueCount);
NResult N_API NEnumGetValuesP(NTypeOfProc pTypeOf, NInt * arValues, NInt * pValueCount);

#ifdef N_CPP
}
#endif

#endif // !N_ENUM_H_INCLUDED
