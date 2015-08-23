#ifndef N_DATA_FILE_MANAGER_H_INCLUDED
#define N_DATA_FILE_MANAGER_H_INCLUDED

#include <Core/NObject.h>
#include <Plugins/NDataFile.h>

#ifdef N_CPP
extern "C"
{
#endif

N_DECLARE_OBJECT_TYPE(NDataFileManager, NObject)

NResult N_API NDataFileManagerGetInstance(HNDataFileManager * phValue);

NResult N_API NDataFileManagerAddFileN(HNDataFileManager hManager, HNString hFileName);
NResult N_API NDataFileManagerAddFromDirectoryN(HNDataFileManager hManager, HNString hDirectory, NBool searchSubDirectories);
NResult N_API NDataFileManagerRemoveFileN(HNDataFileManager hManager, HNString hFileName);
NResult N_API NDataFileManagerClear(HNDataFileManager hManager);

NResult N_API NDataFileManagerGetAllFiles(HNDataFileManager hManager, HNDataFile * * arhFiles, NInt * pFileCount);

#ifdef N_CPP
}
#endif

#endif // !N_DATA_FILE_MANAGER_H_INCLUDED
