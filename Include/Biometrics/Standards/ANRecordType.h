#ifndef AN_RECORD_TYPE_H_INCLUDED
#define AN_RECORD_TYPE_H_INCLUDED

#include <Core/NObject.h>

#ifdef N_CPP
extern "C"
{
#endif

typedef enum ANRecordDataType_
{
	anrdtBinary = 0,
	anrdtAscii = 1,
	anrdtAsciiBinary = 2
} ANRecordDataType;

N_DECLARE_TYPE(ANRecordDataType)

#define AN_RECORD_TYPE_MAX_NUMBER 99

N_DECLARE_OBJECT_TYPE(ANRecordType, NObject)

NResult N_API ANRecordTypeGetTypeCount(NInt * pValue);
NResult N_API ANRecordTypeGetTypeEx(NInt index, HANRecordType * phValue);

NResult N_API ANRecordTypeGetTypeByNumberEx(NInt number, HANRecordType * phRecordType);

NResult N_API ANRecordTypeGetType1Ex(HANRecordType * phValue);
NResult N_API ANRecordTypeGetType2Ex(HANRecordType * phValue);
NResult N_API ANRecordTypeGetType3Ex(HANRecordType * phValue);
NResult N_API ANRecordTypeGetType4Ex(HANRecordType * phValue);
NResult N_API ANRecordTypeGetType5Ex(HANRecordType * phValue);
NResult N_API ANRecordTypeGetType6Ex(HANRecordType * phValue);
NResult N_API ANRecordTypeGetType7Ex(HANRecordType * phValue);
NResult N_API ANRecordTypeGetType8Ex(HANRecordType * phValue);
NResult N_API ANRecordTypeGetType9Ex(HANRecordType * phValue);
NResult N_API ANRecordTypeGetType10Ex(HANRecordType * phValue);
NResult N_API ANRecordTypeGetType13Ex(HANRecordType * phValue);
NResult N_API ANRecordTypeGetType14Ex(HANRecordType * phValue);
NResult N_API ANRecordTypeGetType15Ex(HANRecordType * phValue);
NResult N_API ANRecordTypeGetType16Ex(HANRecordType * phValue);
NResult N_API ANRecordTypeGetType17Ex(HANRecordType * phValue);
NResult N_API ANRecordTypeGetType99Ex(HANRecordType * phValue);

NResult N_API ANRecordTypeGetMaxFieldNumber(HANRecordType hRecordType, NVersion_ version, NInt * pValue);
NResult N_API ANRecordTypeGetStandardFieldNumbersEx(HANRecordType hRecordType, NVersion_ version, NInt * arValue, NInt valueLength);
NResult N_API ANRecordTypeGetUserDefinedFieldNumbersEx(HANRecordType hRecordType, NVersion_ version, struct NRange_ * arValue, NInt valueLength);

NResult N_API ANRecordTypeGetFieldNumberByIdN(HANRecordType hRecordType, NVersion_ version, HNString hId, NInt * pValue);
#ifndef N_NO_ANSI_FUNC
NResult N_API ANRecordTypeGetFieldNumberByIdA(HANRecordType hRecordType, NVersion_ version, const NAChar * szId, NInt * pValue);
#endif
#ifndef N_NO_UNICODE
NResult N_API ANRecordTypeGetFieldNumberByIdW(HANRecordType hRecordType, NVersion_ version, const NWChar * szId, NInt * pValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API ANRecordTypeGetFieldNumberById(HANRecordType hRecordType, NVersion version, const NChar * szId, NInt * pValue);
#endif
#define ANRecordTypeGetFieldNumberById N_FUNC_AW(ANRecordTypeGetFieldNumberById)

NResult N_API ANRecordTypeIsFieldKnown(HANRecordType hRecordType, NVersion_ version, NInt fieldNumber, NBool * pValue);
NResult N_API ANRecordTypeIsFieldStandard(HANRecordType hRecordType, NVersion_ version, NInt fieldNumber, NBool * pValue);
NResult N_API ANRecordTypeIsFieldMandatory(HANRecordType hRecordType, NVersion_ version, NInt fieldNumber, NBool * pValue);
NResult N_API ANRecordTypeGetFieldIdN(HANRecordType hRecordType, NVersion_ version, NInt fieldNumber, HNString * phValue);
NResult N_API ANRecordTypeGetFieldNameN(HANRecordType hRecordType, NVersion_ version, NInt fieldNumber, HNString * phValue);

NResult N_API ANRecordTypeGetVersion(HANRecordType hRecordType, NVersion_ * pValue);
NResult N_API ANRecordTypeGetNumber(HANRecordType hRecordType, NInt * pValue);
NResult N_API ANRecordTypeGetNameN(HANRecordType hRecordType, HNString * phValue);
NResult N_API ANRecordTypeGetDataType(HANRecordType hRecordType, ANRecordDataType * pValue);

#ifdef N_CPP
}
#endif

#endif // !AN_RECORD_TYPE_H_INCLUDED
