#ifndef N_CUSTOM_STREAM_H_INCLUDED
#define N_CUSTOM_STREAM_H_INCLUDED

#include <IO/NStream.h>

#ifdef N_CPP
extern "C"
{
#endif

N_DECLARE_OBJECT_TYPE(NCustomStream, NStream)

typedef NResult (N_CALLBACK NCustomStreamFlushProc)(void * pParam);
typedef NResult (N_CALLBACK NCustomStreamGetLengthProc)(NLong * pValue, void * pParam);
typedef NResult (N_CALLBACK NCustomStreamSetLengthProc)(NLong value, void * pParam);
typedef NResult (N_CALLBACK NCustomStreamGetPositionProc)(NLong * pValue, void * pParam);
typedef NResult (N_CALLBACK NCustomStreamSetPositionProc)(NLong value, void * pParam);
typedef NResult (N_CALLBACK NCustomStreamSeekProc)(NLong offset, NSeekOrigin origin, void * pParam);
typedef NResult (N_CALLBACK NCustomStreamReadByteProc)(NInt * pValue, void * pParam);
typedef NResult (N_CALLBACK NCustomStreamReadProc)(void * pBuffer, NSizeType bufferSize, NSizeType * pSizeRead, void * pParam);
typedef NResult (N_CALLBACK NCustomStreamWriteByteProc)(NByte value, void * pParam);
typedef NResult (N_CALLBACK NCustomStreamWriteProc)(const void * pBuffer, NSizeType bufferSize, void * pParam);

NResult N_API NCustomStreamCreateN(NBool canRead, NBool canWrite, NBool canSeek,
	HNCallback hFlush, HNCallback hGetLength, HNCallback hSetLength, HNCallback hGetPosition, HNCallback hSetPosition,
	HNCallback hSeek, HNCallback hReadByte, HNCallback hRead, HNCallback hWriteByte, HNCallback hWrite, HNCustomStream * phStream);
NResult N_API NCustomStreamCreate(NBool canRead, NBool canWrite, NBool canSeek,
	NCustomStreamFlushProc pFlush, void * pFlushParam,
	NCustomStreamGetLengthProc pGetLength, void * pGetLengthParam,
	NCustomStreamSetLengthProc pSetLength, void * pSetLengthParam,
	NCustomStreamGetPositionProc pGetPosition, void * pGetPositionParam,
	NCustomStreamSetPositionProc pSetPosition, void * pSetPositionParam,
	NCustomStreamSeekProc pSeek, void * pSeekParam,
	NCustomStreamReadByteProc pReadByte, void * pReadByteParam,
	NCustomStreamReadProc pRead, void * pReadParam,
	NCustomStreamWriteByteProc pWriteByte, void * pWriteByteParam,
	NCustomStreamWriteProc pWrite, void * pWriteParam,
	HNCustomStream * phStream);

#ifdef N_CPP
}
#endif

#endif // !N_CUSTOM_STREAM_H_INCLUDED
