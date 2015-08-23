#ifndef BER_TAG_H_INCLUDED
#define BER_TAG_H_INCLUDED

#include <IO/NBuffer.h>

#ifdef N_CPP
extern "C"
{
#endif

typedef enum BerTagClass_
{
	btcUniversal = 0,
	btcApplication = 1,
	btcContextSpecific = 2,
	btcPrivate = 3
} BerTagClass;

N_DECLARE_TYPE(BerTagClass)

typedef enum BerTagEncoding_
{
	btePrimitive = 0,
	bteConstructed = 1
} BerTagEncoding;

N_DECLARE_TYPE(BerTagEncoding)

typedef NInt BerTag_;
#ifndef BER_TAG_HPP_INCLUDED
typedef BerTag_ BerTag;
#endif
N_DECLARE_TYPE(BerTag)

#define BER_TAG_END_OF_CONTENTS             0
#define BER_TAG_BOOLEAN                     1
#define BER_TAG_INTEGER                     2
#define BER_TAG_BIT_STRING                  3
#define BER_TAG_OCTET_STRING                4
#define BER_TAG_NULL                        5
#define BER_TAG_OBJECT_IDENTIFIER           6
#define BER_TAG_OBJECT_DESCRIPTOR           7
#define BER_TAG_EXTERNAL                    8
#define BER_TAG_INSTANCE_OF                 8
#define BER_TAG_REAL                        9
#define BER_TAG_ENUMERATED                 10
#define BER_TAG_EMBEDDED_PDV               11
#define BER_TAG_UTF8_STRING                12
#define BER_TAG_RELATIVE_OBJECT_IDENTIFIER 13
#define BER_TAG_SEQUENCE                   16
#define BER_TAG_SEQUENCE_OF                16
#define BER_TAG_SET                        17
#define BER_TAG_SET_OF                     17
#define BER_TAG_NUMERIC_STRING             18
#define BER_TAG_PRINTABLE_STRING           19
#define BER_TAG_TELETEX_STRING             20
#define BER_TAG_T61_STRING                 20
#define BER_TAG_VIDEOTEX_STRING            21
#define BER_TAG_IA5_STRING                 22
#define BER_TAG_UTC_TIME                   23
#define BER_TAG_GENERALIZED_TIME           24
#define BER_TAG_GRAPHIC_STRING             25
#define BER_TAG_VISIBLE_STRING             26
#define BER_TAG_ISO646_STRING              26
#define BER_TAG_GENERAL_STRING             27
#define BER_TAG_UNIVERSAL_STRING           28
#define BER_TAG_CHARACTER_STRING           29
#define BER_TAG_BMP_STRING                 30

NResult N_API BerTagReadN(HNBuffer hBuffer, NSizeType * pSize, BerTag_ * pTag);
NResult N_API BerTagReadEx(const void * pBuffer, NSizeType bufferSize, NSizeType * pSize, BerTag_ * pTag);

NResult N_API BerTagCreate(BerTagClass cls, BerTagEncoding encoding, NInt number, BerTag_ * pTag);

NBool N_API BerTagIsValid(BerTag_ tag, NBool ffIsValidForTheFirstByte);
NResult N_API BerTagWriteN(BerTag_ tag, HNBuffer hBuffer, NSizeType * pSize);
NResult N_API BerTagWrite(BerTag_ tag, void * pBuffer, NSizeType bufferSize, NSizeType * pSize);
NResult N_API BerTagSaveToMemoryN(BerTag_ tag, HNBuffer * phBuffer);

NResult N_API BerTagToStringN(BerTag_ value, HNString hFormat, HNString * phValue);
NResult N_API BerTagToStringA(BerTag_ value, const NAChar * szFormat, HNString * phValue);
#ifndef N_NO_UNICODE
NResult N_API BerTagToStringW(BerTag_ value, const NWChar * szFormat, HNString * phValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API BerTagToString(BerTag value, const NChar * szFormat, HNString * phValue);
#endif
#define BerTagToString N_FUNC_AW(BerTagToString)

BerTagClass N_API BerTagGetClass(BerTag_ tag);
BerTagEncoding N_API BerTagGetEncoding(BerTag_ tag);
NInt N_API BerTagGetNumber(BerTag_ tag);
NSizeType N_API BerTagGetLength(BerTag_ tag);

#ifdef N_CPP
}
#endif

#endif // !BER_TAG_H_INCLUDED
