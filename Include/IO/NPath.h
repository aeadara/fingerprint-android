#ifndef N_PATH_H_INCLUDED
#define N_PATH_H_INCLUDED

#include <Core/NObject.h>

#ifdef N_CPP
extern "C"
{
#endif

#ifdef N_WINDOWS
	#define N_PATH_DIRECTORY_SEPARATORA '\\'
	#define N_PATH_DIRECTORY_SEPARATOR_STRA "\\"
	#define N_PATH_ALT_DIRECTORY_SEPARATORA '/'
	#define N_PATH_VOLUME_SEPARATORA ':'
	#define N_PATH_PATH_SEPARATORA ';'
	#ifndef N_NO_UNICODE
		#define N_PATH_DIRECTORY_SEPARATORW L'\\'
		#define N_PATH_DIRECTORY_SEPARATOR_STRW L"\\"
		#define N_PATH_ALT_DIRECTORY_SEPARATORW L'/'
		#define N_PATH_VOLUME_SEPARATORW L':'
		#define N_PATH_PATH_SEPARATORW L';'
	#endif
	#define N_PATH_IS_CASE_SENSITIVE NFalse
#else
	#define N_PATH_DIRECTORY_SEPARATORA '/'
	#define N_PATH_DIRECTORY_SEPARATOR_STRA "/"
	#define N_PATH_ALT_DIRECTORY_SEPARATORA N_PATH_DIRECTORY_SEPARATORA
	#define N_PATH_VOLUME_SEPARATORA N_PATH_DIRECTORY_SEPARATORA
	#define N_PATH_PATH_SEPARATORA ';'
	#ifndef N_NO_UNICODE
		#define N_PATH_DIRECTORY_SEPARATORW L'/'
		#define N_PATH_DIRECTORY_SEPARATOR_STRW L"/"
		#define N_PATH_ALT_DIRECTORY_SEPARATORW N_PATH_DIRECTORY_SEPARATORW
		#define N_PATH_VOLUME_SEPARATORW N_PATH_DIRECTORY_SEPARATORW
		#define N_PATH_PATH_SEPARATORW ';'
	#endif
	#define N_PATH_IS_CASE_SENSITIVE NTrue
#endif

#define N_PATH_DIRECTORY_SEPARATOR N_MACRO_AW(N_PATH_DIRECTORY_SEPARATOR)
#define N_PATH_DIRECTORY_SEPARATOR_STR N_MACRO_AW(N_PATH_DIRECTORY_SEPARATOR_STR)
#define N_PATH_ALT_DIRECTORY_SEPARATOR N_MACRO_AW(N_PATH_ALT_DIRECTORY_SEPARATOR)
#define N_PATH_VOLUME_SEPARATOR N_MACRO_AW(N_PATH_VOLUME_SEPARATOR)
#define N_PATH_PATH_SEPARATOR N_MACRO_AW(N_PATH_PATH_SEPARATOR)

#define N_MAX_FILE_NAME 256

N_DECLARE_STATIC_OBJECT_TYPE(NPath)

NResult N_API NPathCheckN(HNString hValue);

#ifndef N_NO_ANSI_FUNC
NResult N_API NPathCheckA(const NAChar * szValue);
#endif
#ifndef N_NO_UNICODE
NResult N_API NPathCheckW(const NWChar * szValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NPathCheck(const NChar * szValue);
#endif
#define NPathCheck N_FUNC_AW(NPathCheck)

NResult N_API NPathIsRootedN(HNString hPath, NBool * pValue);

#ifndef N_NO_ANSI_FUNC
NResult N_API NPathIsRootedA(const NAChar * szPath, NBool * pValue);
#endif
#ifndef N_NO_UNICODE
NResult N_API NPathIsRootedW(const NWChar * szPath, NBool * pValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NPathIsRooted(const NChar * szPath, NBool * pValue);
#endif
#define NPathIsRooted N_FUNC_AW(NPathIsRooted)

NResult N_API NPathGetTempPath(HNString * phPath);
NResult N_API NPathGetTempFileName(HNString * phFileName);

NResult N_API NPathCombineN(HNString hPath1, HNString hPath2, HNString * phValue);

#ifndef N_NO_ANSI_FUNC
NResult N_API NPathCombineP1NA(HNString hPath1, const NAChar * szPath2, HNString * phValue);
#endif
#ifndef N_NO_UNICODE
NResult N_API NPathCombineP1NW(HNString hPath1, const NWChar * szPath2, HNString * phValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NPathCombineP1N(HNString hPath1, const NChar * szPath2, HNString * phValue);
#endif
#define NPathCombineP1N N_FUNC_AW(NPathCombineP1N)

#ifndef N_NO_ANSI_FUNC
NResult N_API NPathCombineP2NA(const NAChar * szPath1, HNString hPath2, HNString * phValue);
#endif
#ifndef N_NO_UNICODE
NResult N_API NPathCombineP2NW(const NWChar * szPath1, HNString hPath2, HNString * phValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NPathCombineP2N(const NChar * szPath1, HNString hPath2, HNString * phValue);
#endif
#define NPathCombineP2N N_FUNC_AW(NPathCombineP2N)

#ifndef N_NO_ANSI_FUNC
NResult N_API NPathCombineA(const NAChar * szPath1, const NAChar * szPath2, HNString * phValue);
#endif
#ifndef N_NO_UNICODE
NResult N_API NPathCombineW(const NWChar * szPath1, const NWChar * szPath2, HNString * phValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NPathCombine(const NChar * szPath1, const NChar * szPath2, HNString * phValue);
#endif
#define NPathCombine N_FUNC_AW(NPathCombine)

NResult N_API NPathGetDirectoryNameN(HNString hPath, HNString * phValue);

#ifndef N_NO_ANSI_FUNC
NResult N_API NPathGetDirectoryNameA(const NAChar * szPath, HNString * phValue);
#endif
#ifndef N_NO_UNICODE
NResult N_API NPathGetDirectoryNameW(const NWChar * szPath, HNString * phValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NPathGetDirectoryName(const NChar * szPath, HNString * phValue);
#endif
#define NPathGetDirectoryName N_FUNC_AW(NPathGetDirectoryName)

NResult N_API NPathGetFileNameN(HNString hPath, HNString * phValue);

#ifndef N_NO_ANSI_FUNC
NResult N_API NPathGetFileNameA(const NAChar * szPath, HNString * phValue);
#endif
#ifndef N_NO_UNICODE
NResult N_API NPathGetFileNameW(const NWChar * szPath, HNString * phValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NPathGetFileName(const NChar * szPath, HNString * phValue);
#endif
#define NPathGetFileName N_FUNC_AW(NPathGetFileName)

NResult N_API NPathGetFileNameWithoutExtensionN(HNString hPath, HNString * phValue);

#ifndef N_NO_ANSI_FUNC
NResult N_API NPathGetFileNameWithoutExtensionA(const NAChar * szPath, HNString * phValue);
#endif
#ifndef N_NO_UNICODE
NResult N_API NPathGetFileNameWithoutExtensionW(const NWChar * szPath, HNString * phValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NPathGetFileNameWithoutExtension(const NChar * szPath, HNString * phValue);
#endif
#define NPathGetFileNameWithoutExtension N_FUNC_AW(NPathGetFileNameWithoutExtension)

NResult N_API NPathGetExtensionN(HNString hPath, HNString * phValue);

#ifndef N_NO_ANSI_FUNC
NResult N_API NPathGetExtensionA(const NAChar * szPath, HNString * phValue);
#endif
#ifndef N_NO_UNICODE
NResult N_API NPathGetExtensionW(const NWChar * szPath, HNString * phValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NPathGetExtension(const NChar * szPath, HNString * phValue);
#endif
#define NPathGetExtension N_FUNC_AW(NPathGetExtension)

NResult N_API NPathHasExtensionN(HNString hPath, NBool * pValue);

#ifndef N_NO_ANSI_FUNC
NResult N_API NPathHasExtensionA(const NAChar * szPath, NBool * pValue);
#endif
#ifndef N_NO_UNICODE
NResult N_API NPathHasExtensionW(const NWChar * szPath, NBool * pValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NPathHasExtension(const NChar * szPath, NBool * pValue);
#endif
#define NPathHasExtension N_FUNC_AW(NPathHasExtension)

NResult N_API NPathChangeExtensionN(HNString hPath, HNString hExtension, HNString * phValue);

#ifndef N_NO_ANSI_FUNC
NResult N_API NPathChangeExtensionPNA(HNString hPath, const NAChar * szExtension, HNString * phValue);
#endif
#ifndef N_NO_UNICODE
NResult N_API NPathChangeExtensionPNW(HNString hPath, const NWChar * szExtension, HNString * phValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NPathChangeExtensionPN(HNString hPath, const NChar * szExtension, HNString * phValue);
#endif
#define NPathChangeExtensionPN N_FUNC_AW(NPathChangeExtensionPN)

#ifndef N_NO_ANSI_FUNC
NResult N_API NPathChangeExtensionA(const NAChar * szPath, const NAChar * szExtension, HNString * phValue);
#endif
#ifndef N_NO_UNICODE
NResult N_API NPathChangeExtensionW(const NWChar * szPath, const NWChar * szExtension, HNString * phValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NPathChangeExtension(const NChar * szPath, const NChar * szExtension, HNString * phValue);
#endif
#define NPathChangeExtension N_FUNC_AW(NPathChangeExtension)

#ifdef N_CPP
}
#endif

#endif // !N_PATH_H_INCLUDED
