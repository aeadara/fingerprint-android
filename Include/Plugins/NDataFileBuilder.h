#ifndef N_DATA_FILE_BUILDER_H_INCLUDED
#define N_DATA_FILE_BUILDER_H_INCLUDED

#include <Plugins/NDataRecord.h>

#ifdef N_CPP
extern "C"
{
#endif

N_DECLARE_OBJECT_TYPE(NDataFileBuilder, NObject)

NResult N_API NDataFileBuilderCreate(HNDataFileBuilder * phBuilder);
NResult N_API NDataFileBuilderAppendRecord(HNDataFileBuilder hBuilder, HNDataRecord hRecord);

NResult N_API NDataFileBuilderWriteToFileN(HNDataFileBuilder hBuilder, HNString hFileName);
#ifndef N_NO_ANSI_FUNC
NResult N_API NDataFileBuilderWriteToFileA(HNDataFileBuilder hBuilder, const NAChar * szFileName);
#endif
#ifndef N_NO_UNICODE
NResult N_API NDataFileBuilderWriteToFileW(HNDataFileBuilder hBuilder, const NWChar * szFileName);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NDataFileBuilderWriteToFile(HNDataFileBuilder hBuilder, const NChar * szFileName);
#endif
#define NDataFileBuilderWriteToFile N_FUNC_AW(NDataFileBuilderWriteToFile)

#ifdef N_CPP
}
#endif

#endif // !N_DATA_FILE_BUILDER_H_INCLUDED
