#ifndef N_DATA_FILE_MANAGER_HPP_INCLUDED
#define N_DATA_FILE_MANAGER_HPP_INCLUDED

#include <Core/NObject.hpp>
#include <Plugins/NDataFile.hpp>

namespace Neurotec { namespace Plugins
{
#include <Plugins/NDataFileManager.h>
}}

namespace Neurotec { namespace Plugins
{
class NDataFileManager : public NObject
{
	N_DECLARE_OBJECT_CLASS(NDataFileManager, NObject)

public:
	static NDataFileManager GetInstance()
	{
		HNDataFileManager handle;
		NCheck(NDataFileManagerGetInstance(&handle));
		return FromHandle<NDataFileManager>(handle);
	}

	void AddFile(const NStringWrapper & fileName)
	{
		NCheck(NDataFileManagerAddFileN(GetHandle(), fileName.GetHandle()));
	}

	void AddFromDirectory(const NStringWrapper & directory, NBool searchSubDirectories = NTrue)
	{
		NCheck(NDataFileManagerAddFromDirectoryN(GetHandle(), directory.GetHandle(), searchSubDirectories));
	}

	void RemoveFile(const NStringWrapper & fileName)
	{
		NCheck(NDataFileManagerRemoveFileN(GetHandle(), fileName.GetHandle()));
	}

	void Clear()
	{
		NCheck(NDataFileManagerClear(GetHandle()));
	}

	NArrayWrapper<NDataFile> GetAllFiles()
	{
		HNDataFile * arhAllFiles;
		NInt fileCount;
		NCheck(NDataFileManagerGetAllFiles(GetHandle(), &arhAllFiles, &fileCount));
		return NArrayWrapper<NDataFile>(arhAllFiles, fileCount, true, true);
	}
};
}}

#endif // !N_DATA_FILE_MANAGER_HPP_INCLUDED