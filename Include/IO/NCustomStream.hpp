#ifndef N_CUSTOM_STREAM_HPP_INCLUDED
#define N_CUSTOM_STREAM_HPP_INCLUDED

#include <IO/NStream.hpp>
namespace Neurotec { namespace IO
{
#include <IO/NCustomStream.h>
}}

namespace Neurotec { namespace IO
{

class NCustomStream : public NStream
{
	N_DECLARE_OBJECT_CLASS(NCustomStream, NStream)

public:
	typedef void (* FlushProc)(void * pParam);
	typedef NLong (* GetLengthProc)(void * pParam);
	typedef void (* SetLengthProc)(NLong value, void * pParam);
	typedef NLong (* GetPositionProc)(void * pParam);
	typedef void (* SetPositionProc)(NLong value, void * pParam);
	typedef void (* SeekProc)(NLong offset, NSeekOrigin origin, void * pParam);
	typedef NInt (* ReadByteProc)(void * pParam);
	typedef NSizeType (* ReadProc)(void * pBuffer, NSizeType bufferSize, void * pParam);
	typedef void (* WriteByteProc)(NByte value, void * pParam);
	typedef void (* WriteProc)(const void * pBuffer, NSizeType bufferSize, void * pParam);

private:
	static NResult N_API FlushProcImpl(void * pParam)
	{
		NResult result = N_OK;
		try
		{
			NTypes::CallbackParam * p = reinterpret_cast<NTypes::CallbackParam *>(pParam);
			reinterpret_cast<FlushProc>(p->GetCallback())(p->GetCallbackParam());
		}
		N_EXCEPTION_CATCH_AND_SET_LAST(result);
		return result;
	}

	static NResult N_API GetLengthProcImpl(NLong * pValue, void * pParam)
	{
		NResult result = N_OK;
		try
		{
			if (!pValue) NThrowArgumentNullException(N_T("pValue"));
			NTypes::CallbackParam * p = reinterpret_cast<NTypes::CallbackParam *>(pParam);
			*pValue = reinterpret_cast<GetLengthProc>(p->GetCallback())(p->GetCallbackParam());
		}
		N_EXCEPTION_CATCH_AND_SET_LAST(result);
		return result;
	}

	static NResult N_API SetLengthProcImpl(NLong value, void * pParam)
	{
		NResult result = N_OK;
		try
		{
			NTypes::CallbackParam * p = reinterpret_cast<NTypes::CallbackParam *>(pParam);
			reinterpret_cast<SetLengthProc>(p->GetCallback())(value, p->GetCallbackParam());
		}
		N_EXCEPTION_CATCH_AND_SET_LAST(result);
		return result;
	}

	static NResult N_API GetPositionProcImpl(NLong * pValue, void * pParam)
	{
		NResult result = N_OK;
		try
		{
			if (!pValue) NThrowArgumentNullException(N_T("pValue"));
			NTypes::CallbackParam * p = reinterpret_cast<NTypes::CallbackParam *>(pParam);
			*pValue = reinterpret_cast<GetPositionProc>(p->GetCallback())(p->GetCallbackParam());
		}
		N_EXCEPTION_CATCH_AND_SET_LAST(result);
		return result;
	}

	static NResult N_API SetPositionProcImpl(NLong value, void * pParam)
	{
		NResult result = N_OK;
		try
		{
			NTypes::CallbackParam * p = reinterpret_cast<NTypes::CallbackParam *>(pParam);
			reinterpret_cast<SetPositionProc>(p->GetCallback())(value, p->GetCallbackParam());
		}
		N_EXCEPTION_CATCH_AND_SET_LAST(result);
		return result;
	}

	static NResult N_API SeekProcImpl(NLong offset, NSeekOrigin origin, void * pParam)
	{
		NResult result = N_OK;
		try
		{
			NTypes::CallbackParam * p = reinterpret_cast<NTypes::CallbackParam *>(pParam);
			reinterpret_cast<SeekProc>(p->GetCallback())(offset, origin, p->GetCallbackParam());
		}
		N_EXCEPTION_CATCH_AND_SET_LAST(result);
		return result;
	}

	static NResult N_API ReadByteProcImpl(NInt * pValue, void * pParam)
	{
		NResult result = N_OK;
		try
		{
			if (!pValue) NThrowArgumentNullException(N_T("pValue"));
			NTypes::CallbackParam * p = reinterpret_cast<NTypes::CallbackParam *>(pParam);
			*pValue = reinterpret_cast<ReadByteProc>(p->GetCallback())(p->GetCallbackParam());
		}
		N_EXCEPTION_CATCH_AND_SET_LAST(result);
		return result;
	}

	static NResult N_API ReadProcImpl(void * pBuffer, NSizeType bufferSize, NSizeType * pSizeRead, void * pParam)
	{
		NResult result = N_OK;
		try
		{
			if (!pSizeRead) NThrowArgumentNullException(N_T("pSizeRead"));
			NTypes::CallbackParam * p = reinterpret_cast<NTypes::CallbackParam *>(pParam);
			*pSizeRead = reinterpret_cast<ReadProc>(p->GetCallback())(pBuffer, bufferSize, p->GetCallbackParam());
		}
		N_EXCEPTION_CATCH_AND_SET_LAST(result);
		return result;
	}

	static NResult N_API WriteByteProcImpl(NByte value, void * pParam)
	{
		NResult result = N_OK;
		try
		{
			NTypes::CallbackParam * p = reinterpret_cast<NTypes::CallbackParam *>(pParam);
			reinterpret_cast<WriteByteProc>(p->GetCallback())(value, p->GetCallbackParam());
		}
		N_EXCEPTION_CATCH_AND_SET_LAST(result);
		return result;
	}

	static NResult N_API WriteProcImpl(const void * pBuffer, NSizeType bufferSize, void * pParam)
	{
		NResult result = N_OK;
		try
		{
			NTypes::CallbackParam * p = reinterpret_cast<NTypes::CallbackParam *>(pParam);
			reinterpret_cast<WriteProc>(p->GetCallback())(pBuffer, bufferSize, p->GetCallbackParam());
		}
		N_EXCEPTION_CATCH_AND_SET_LAST(result);
		return result;
	}


	static HNCustomStream Create(bool canRead, bool canWrite, bool canSeek,
		FlushProc pFlush, void * pFlushParam,
		GetLengthProc pGetLength, void * pGetLengthParam,
		SetLengthProc pSetLength, void * pSetLengthParam,
		GetPositionProc pGetPosition, void * pGetPositionParam,
		SetPositionProc pSetPosition, void * pSetPositionParam,
		SeekProc pSeek, void * pSeekParam,
		ReadByteProc pReadByte, void * pReadByteParam,
		ReadProc pRead, void * pReadParam,
		WriteByteProc pWriteByte, void * pWriteByteParam,
		WriteProc pWrite, void * pWriteParam)
	{
		NCallback flush = NTypes::CreateCallback(FlushProcImpl, pFlush, pFlushParam);
		NCallback getLength = NTypes::CreateCallback(GetLengthProcImpl, pGetLength, pGetLengthParam);
		NCallback setLength = NTypes::CreateCallback(SetLengthProcImpl, pSetLength, pSetLengthParam);
		NCallback getPosition = NTypes::CreateCallback(GetPositionProcImpl, pGetPosition, pGetPositionParam);
		NCallback setPosition = NTypes::CreateCallback(SetPositionProcImpl, pSetPosition, pSetPositionParam);
		NCallback seek = NTypes::CreateCallback(SeekProcImpl, pSeek, pSeekParam);
		NCallback readByte = NTypes::CreateCallback(ReadByteProcImpl, pReadByte, pReadByteParam);
		NCallback read = NTypes::CreateCallback(ReadProcImpl, pRead, pReadParam);
		NCallback writeByte = NTypes::CreateCallback(WriteByteProcImpl, pWriteByte, pWriteByteParam);
		NCallback write = NTypes::CreateCallback(WriteProcImpl, pWrite, pWriteParam);
		HNCustomStream handle;
		NCheck(NCustomStreamCreateN(canRead ? NTrue : NFalse, canWrite ? NTrue : NFalse, canSeek ? NTrue : NFalse,
			flush.GetHandle(), getLength.GetHandle(), setLength.GetHandle(), getPosition.GetHandle(), setPosition.GetHandle(),
			seek.GetHandle(), readByte.GetHandle(), read.GetHandle(), writeByte.GetHandle(), write.GetHandle(), &handle));
		return handle;
	}

public:
	NCustomStream(bool canRead, bool canWrite, bool canSeek,
		FlushProc pFlush, void * pFlushParam,
		GetLengthProc pGetLength, void * pGetLengthParam,
		SetLengthProc pSetLength, void * pSetLengthParam,
		GetPositionProc pGetPosition, void * pGetPositionParam,
		SetPositionProc pSetPosition, void * pSetPositionParam,
		SeekProc pSeek, void * pSeekParam,
		ReadByteProc pReadByte, void * pReadByteParam,
		ReadProc pRead, void * pReadParam,
		WriteByteProc pWriteByte, void * pWriteByteParam,
		WriteProc pWrite, void * pWriteParam)
		: NStream(Create(canRead, canWrite, canSeek,
			pFlush, pFlushParam,
			pGetLength, pGetLengthParam,
			pSetLength, pSetLengthParam,
			pGetPosition, pGetPositionParam,
			pSetPosition, pSetPositionParam,
			pSeek, pSeekParam,
			pReadByte, pReadByteParam,
			pRead, pReadParam,
			pWriteByte, pWriteByteParam,
			pWrite, pWriteParam), true)
	{
	}
};

}}

#endif // !N_CUSTOM_STREAM_HPP_INCLUDED
