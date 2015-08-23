#ifndef N_IO_TYPES_H_INCLUDED
#define N_IO_TYPES_H_INCLUDED

#include <Core/NTypes.h>

#ifdef N_CPP
extern "C"
{
#endif

typedef enum NByteOrder_
{
	nboLittleEndian = 0,
	nboBigEndian = 1,
} NByteOrder;

N_DECLARE_TYPE(NByteOrder)

typedef enum NSeekOrigin_
{
	nsoBegin = 0,
	nsoCurrent = 1,
	nsoEnd = 2
} NSeekOrigin;

N_DECLARE_TYPE(NSeekOrigin)

typedef enum NFileMode_
{
	nfmCreateNew = 1,
	nfmCreate = 2,
	nfmOpen = 3,
	nfmOpenOrCreate = 4,
	nfmTruncate = 5,
	nfmAppend = 6,
} NFileMode;

N_DECLARE_TYPE(NFileMode)

typedef enum NFileAccess_
{
	nfaRead = 1,
	nfaWrite = 2,
	nfaReadWrite = nfaRead | nfaWrite
} NFileAccess;

N_DECLARE_TYPE(NFileAccess)

typedef enum NFileShare_
{
	nfsNone = 0,
	nfsRead = 1,
	nfsWrite = 2,
	nfsReadWrite = nfsRead | nfsWrite
} NFileShare;

N_DECLARE_TYPE(NFileShare)

NBool N_API NByteOrderIsValid(NByteOrder value);
NByteOrder N_API NByteOrderGetSystem(void);
NBool N_API NByteOrderIsReverse(NByteOrder value);

NBool N_API NSeekOriginIsValid(NSeekOrigin value);

NBool N_API NFileModeIsValid(NFileMode value);

NBool N_API NFileAccessIsValid(NFileAccess value);

NBool N_API NFileShareIsValid(NFileShare value);

N_DECLARE_STATIC_OBJECT_TYPE(NIOTypes)

#ifdef N_CPP
}
#endif

#endif // !N_IO_TYPES_H_INCLUDED
