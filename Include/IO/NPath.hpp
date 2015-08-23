#ifndef N_PATH_HPP_INCLUDED
#define N_PATH_HPP_INCLUDED

#include <Core/NObject.hpp>
namespace Neurotec { namespace IO
{
#include <IO/NPath.h>
}}

namespace Neurotec { namespace IO
{

#undef N_PATH_DIRECTORY_SEPARATORA
#undef N_PATH_ALT_DIRECTORY_SEPARATORA
#undef N_PATH_VOLUME_SEPARATORA
#undef N_PATH_PATH_SEPARATORA
#ifndef N_NO_UNICODE
	#undef N_PATH_DIRECTORY_SEPARATORW
	#undef N_PATH_ALT_DIRECTORY_SEPARATORW
	#undef N_PATH_VOLUME_SEPARATORW
	#undef N_PATH_PATH_SEPARATORW
#endif
#undef N_PATH_IS_CASE_SENSITIVE
#undef N_PATH_DIRECTORY_SEPARATOR
#undef N_PATH_ALT_DIRECTORY_SEPARATOR
#undef N_PATH_VOLUME_SEPARATOR
#undef N_PATH_PATH_SEPARATOR
#undef N_MAX_FILE_NAME

#ifdef N_WINDOWS
	const NAChar N_PATH_DIRECTORY_SEPARATORA = '\\';
	const NAChar N_PATH_ALT_DIRECTORY_SEPARATORA = '/';
	const NAChar N_PATH_VOLUME_SEPARATORA = ':';
	const NAChar N_PATH_PATH_SEPARATORA = ';';
	#ifndef N_NO_UNICODE
		const NWChar N_PATH_DIRECTORY_SEPARATORW = L'\\';
		const NWChar N_PATH_ALT_DIRECTORY_SEPARATORW = L'/';
		const NWChar N_PATH_VOLUME_SEPARATORW = L':';
		const NWChar N_PATH_PATH_SEPARATORW = L';';
	#endif
	const bool N_PATH_IS_CASE_SENSITIVE = false;
#else
	const NAChar N_PATH_DIRECTORY_SEPARATORA = '/';
	const NAChar N_PATH_ALT_DIRECTORY_SEPARATORA = N_PATH_DIRECTORY_SEPARATORA;
	const NAChar N_PATH_VOLUME_SEPARATORA = N_PATH_DIRECTORY_SEPARATORA;
	const NAChar N_PATH_PATH_SEPARATORA = ';';
	#ifndef N_NO_UNICODE
		const NWChar N_PATH_DIRECTORY_SEPARATORW = L'/';
		const NWChar N_PATH_ALT_DIRECTORY_SEPARATORW = N_PATH_DIRECTORY_SEPARATORW;
		const NWChar N_PATH_VOLUME_SEPARATORW = N_PATH_DIRECTORY_SEPARATORW;
		const NWChar N_PATH_PATH_SEPARATORW = ';';
	#endif
	const bool N_PATH_IS_CASE_SENSITIVE = true;
#endif

const NChar N_PATH_DIRECTORY_SEPARATOR = N_VAR_AW(N_PATH_DIRECTORY_SEPARATOR);
const NChar N_PATH_ALT_DIRECTORY_SEPARATOR = N_VAR_AW(N_PATH_ALT_DIRECTORY_SEPARATOR);
const NChar N_PATH_VOLUME_SEPARATOR = N_VAR_AW(N_PATH_VOLUME_SEPARATOR);
const NChar N_PATH_PATH_SEPARATOR = N_VAR_AW(N_PATH_PATH_SEPARATOR);

const NInt N_MAX_FILE_NAME = 256;

class NPath
{
	N_DECLARE_STATIC_OBJECT_CLASS(NPath)

public:
	static void Check(const NStringWrapper & path)
	{
		NCheck(NPathCheckN(path.GetHandle()));
	}

	static bool IsRooted(const NStringWrapper & path)
	{
		NBool value;
		NCheck(NPathIsRootedN(path.GetHandle(), &value));
		return value != 0;
	}

	static NString GetTempPath()
	{
		HNString hPath;
		NCheck(NPathGetTempPath(&hPath));
		return NString(hPath, true);
	}

	static NString GetTempFileName()
	{
		HNString hFileName;
		NCheck(NPathGetTempFileName(&hFileName));
		return NString(hFileName, true);
	}

	static NString Combine(const NStringWrapper & path1, const NStringWrapper & path2)
	{
		HNString hValue;
		NCheck(NPathCombineN(path1.GetHandle(), path2.GetHandle(), &hValue));
		return NString(hValue, true);
	}

	static NString GetDirectoryName(const NStringWrapper & path)
	{
		HNString hValue;
		NCheck(NPathGetDirectoryNameN(path.GetHandle(), &hValue));
		return NString(hValue, true);
	}

	static NString GetFileName(const NStringWrapper & path)
	{
		HNString hValue;
		NCheck(NPathGetFileNameN(path.GetHandle(), &hValue));
		return NString(hValue, true);
	}

	static NString GetFileNameWithoutExtension(const NStringWrapper & path)
	{
		HNString hValue;
		NCheck(NPathGetFileNameWithoutExtensionN(path.GetHandle(), &hValue));
		return NString(hValue, true);
	}

	static NString GetExtension(const NStringWrapper & path)
	{
		HNString hValue;
		NCheck(NPathGetExtensionN(path.GetHandle(), &hValue));
		return NString(hValue, true);
	}

	static bool HasExtension(const NStringWrapper & path)
	{
		NBool value;
		NCheck(NPathHasExtensionN(path.GetHandle(), &value));
		return value != 0;
	}

	static NString ChangeExtension(const NStringWrapper & path, const NStringWrapper & extension)
	{
		HNString hValue;
		NCheck(NPathChangeExtensionN(path.GetHandle(),extension.GetHandle(), &hValue));
		return NString(hValue, true);
	}
};

}}

#endif // !N_PATH_HPP_INCLUDED
