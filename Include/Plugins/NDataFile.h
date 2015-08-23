#ifndef N_DATA_FILE_H_INCLUDED
#define N_DATA_FILE_H_INCLUDED

#include <Core/NObject.h>
#include <Plugins/NDataRecord.h>

#ifdef N_CPP
extern "C"
{
#endif

N_DECLARE_OBJECT_TYPE(NDataFile, NObject)

NResult N_API NDataFileGetFileName(HNDataFile hDataFile, HNString * phValue);

NResult N_API NDataFileGetRecordCount(HNDataFile hDataFile, NInt * pValue);
NResult N_API NDataFileGetRecord(HNDataFile hDataFile, NInt index, HNDataRecord * phValue);
NResult N_API NDataFileGetRecords(HNDataFile hDataFile, HNDataRecord * * parhValues, NInt * pValueCount);

#ifdef N_CPP
}
#endif

#endif // !N_DATA_FILE_H_INCLUDED
