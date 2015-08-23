#ifndef N_FILE_STREAM_HPP_INCLUDED
#define N_FILE_STREAM_HPP_INCLUDED

#include <IO/NStream.hpp>
namespace Neurotec { namespace IO
{
#include <IO/NFileStream.h>
}}

namespace Neurotec { namespace IO
{

class NFileStream : public NStream
{
	N_DECLARE_OBJECT_CLASS(NFileStream, NStream)

private:
	static HNFileStream Create(const NStringWrapper & path, NFileMode mode)
	{
		HNFileStream handle;
		NCheck(NFileStreamCreateN(path.GetHandle(), mode, &handle));
		return handle;
	}

	static HNFileStream Create(const NStringWrapper & path, NFileMode mode, NFileAccess access)
	{
		HNFileStream handle;
		NCheck(NFileStreamCreateWithAccessN(path.GetHandle(), mode, access, &handle));
		return handle;
	}

	static HNFileStream Create(const NStringWrapper & path, NFileMode mode, NFileAccess access, NFileShare share)
	{
		HNFileStream handle;
		NCheck(NFileStreamCreateWithAccessAndShareN(path.GetHandle(), mode, access, share, &handle));
		return handle;
	}

	static HNFileStream Create(const NStringWrapper & path, NFileMode mode, NFileAccess access, NFileShare share, NSizeType bufferSize)
	{
		HNFileStream handle;
		NCheck(NFileStreamCreateWithAccessShareAndBufferSizeN(path.GetHandle(), mode, access, share, bufferSize, &handle));
		return handle;
	}

	static HNFileStream Create(NHandle handle, bool ownsHandle, NFileAccess access)
	{
		HNFileStream hStream;
		NCheck(NFileStreamCreateFromOSHandle(handle, ownsHandle ? NTrue : NFalse, access, &hStream));
		return hStream;
	}

	static HNFileStream Create(NHandle handle, bool ownsHandle, NFileAccess access, NSizeType bufferSize)
	{
		HNFileStream hStream;
		NCheck(NFileStreamCreateFromOSHandleWithBufferSize(handle, ownsHandle ? NTrue : NFalse, access, bufferSize, &hStream));
		return hStream;
	}

public:
	NFileStream(const NStringWrapper & path, NFileMode mode)
		: NStream(Create(path, mode), true)
	{
	}

	NFileStream(const NStringWrapper & path, NFileMode mode, NFileAccess access)
		: NStream(Create(path, mode, access), true)
	{
	}

	NFileStream(const NStringWrapper & path, NFileMode mode, NFileAccess access, NFileShare share)
		: NStream(Create(path, mode, access, share), true)
	{
	}

	NFileStream(const NStringWrapper & path, NFileMode mode, NFileAccess access, NFileShare share, NSizeType bufferSize)
		: NStream(Create(path, mode, access, share, bufferSize), true)
	{
	}

	NFileStream(NHandle handle, NFileAccess access)
		: NStream(Create(handle, true, access), true)
	{
	}

	NFileStream(NHandle handle, bool ownsHandle, NFileAccess access)
		: NStream(Create(handle, ownsHandle, access), true)
	{
	}

	NFileStream(NHandle handle, NFileAccess access, NSizeType bufferSize)
		: NStream(Create(handle, true, access, bufferSize), true)
	{
	}

	NFileStream(NHandle handle, bool ownsHandle, NFileAccess access, NSizeType bufferSize)
		: NStream(Create(handle, ownsHandle, access, bufferSize), true)
	{
	}

	NHandle GetOSHandle()
	{
		NHandle value;
		NCheck(NFileStreamGetOSHandle(GetHandle(), &value));
		return value;
	}
};

}}

#endif // !N_FILE_STREAM_HPP_INCLUDED
