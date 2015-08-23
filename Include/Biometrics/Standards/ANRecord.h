#ifndef AN_RECORD_H_INCLUDED
#define AN_RECORD_H_INCLUDED

#include <Biometrics/Standards/ANField.h>
#include <Biometrics/Standards/ANRecordType.h>

#ifdef N_CPP
extern "C"
{
#endif

N_DECLARE_OBJECT_TYPE(ANRecord, NObject)

#define AN_RECORD_MAX_FIELD_NUMBER 999

#define AN_RECORD_FIELD_LEN    1
#define AN_RECORD_FIELD_IDC    2
#define AN_RECORD_FIELD_DATA 999

#define AN_RECORD_MAX_IDC 255

#define ANR_MERGE_DUPLICATE_FIELDS   0x00000100
#define ANR_RECOVER_FROM_BINARY_DATA 0x00000200

NResult N_API ANRecordGetFieldCount(HANRecord hRecord, NInt * pValue);
NResult N_API ANRecordGetFieldEx(HANRecord hRecord, NInt index, HANField * phValue);
NResult N_API ANRecordGetFieldCapacity(HANRecord hRecord, NInt * pValue);
NResult N_API ANRecordSetFieldCapacity(HANRecord hRecord, NInt value);

NResult N_API ANRecordAddFieldN(HANRecord hRecord, NInt fieldNumber, HNString hValue, NInt * pFieldIndex, HANField * phField);
#ifndef N_NO_ANSI_FUNC
NResult N_API ANRecordAddFieldExA(HANRecord hRecord, NInt fieldNumber, const NAChar * szValue, NInt * pFieldIndex, HANField * phField);
#endif
#ifndef N_NO_UNICODE
NResult N_API ANRecordAddFieldExW(HANRecord hRecord, NInt fieldNumber, const NWChar * szValue, NInt * pFieldIndex, HANField * phField);
#endif
#ifdef N_DOCUMENTATION
NResult N_API ANRecordAddFieldEx(HANRecord hRecord, NInt fieldNumber, const NChar * szValue, NInt * pFieldIndex, HANField * phField);
#endif
#define ANRecordAddFieldEx N_FUNC_AW(ANRecordAddFieldEx)

NResult N_API ANRecordInsertFieldN(HANRecord hRecord, NInt index, NInt fieldNumber, HNString hValue, HANField * phField);
#ifndef N_NO_ANSI_FUNC
NResult N_API ANRecordInsertFieldA(HANRecord hRecord, NInt index, NInt fieldNumber, const NAChar * szValue, HANField * phField);
#endif
#ifndef N_NO_UNICODE
NResult N_API ANRecordInsertFieldW(HANRecord hRecord, NInt index, NInt fieldNumber, const NWChar * szValue, HANField * phField);
#endif
#ifdef N_DOCUMENTATION
NResult N_API ANRecordInsertField(HANRecord hRecord, NInt index, NInt fieldNumber, const NChar * szValue, HANField * phField);
#endif
#define ANRecordInsertField N_FUNC_AW(ANRecordInsertField)

N_DEPRECATED("function is deprecated, use ANRecordRemoveFieldAt instead")
NResult N_API ANRecordRemoveField(HANRecord hRecord, NInt index);
NResult N_API ANRecordRemoveFieldAt(HANRecord hRecord, NInt index);

NResult N_API ANRecordGetFieldByNumberEx(HANRecord hRecord, NInt fieldNumber, HANField * phField);
NResult N_API ANRecordGetFieldIndexByNumber(HANRecord hRecord, NInt fieldNumber, NInt * pValue);

NResult N_API ANRecordBeginUpdate(HANRecord hRecord);
NResult N_API ANRecordEndUpdate(HANRecord hRecord);

NResult N_API ANRecordGetRecordTypeEx(HANRecord hRecord, HANRecordType * phValue);
NResult N_API ANRecordIsValidated(HANRecord hRecord, NBool * pValue);
NResult N_API ANRecordGetLength(HANRecord hRecord, NSizeType * pValue);
NResult N_API ANRecordGetIdc(HANRecord hRecord, NInt * pValue);
NResult N_API ANRecordSetIdc(HANRecord hRecord, NInt value);
NResult N_API ANRecordGetDataN(HANRecord hRecord, HNBuffer * phValue);
NResult N_API ANRecordSetDataN(HANRecord hRecord, HNBuffer hValue);
NResult N_API ANRecordSetDataEx(HANRecord hRecord, const void * pValue, NSizeType valueSize, NBool copy);

#ifdef N_CPP
}
#endif

#endif // !AN_RECORD_H_INCLUDED
