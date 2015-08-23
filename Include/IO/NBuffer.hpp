#ifndef N_BUFFER_HPP_INCLUDED
#define N_BUFFER_HPP_INCLUDED

#include <Core/NObject.hpp>
namespace Neurotec {
	namespace IO
{
#include <IO/NBuffer.h>
}}

namespace Neurotec { namespace IO
{

class NBuffer : public NObject
{
	N_DECLARE_OBJECT_CLASS(NBuffer, NObject)

private:
	static HNBuffer Create(NSizeType size)
	{
		HNBuffer handle;
		NCheck(NBufferCreate(size, &handle));
		return handle;
	}

	static HNBuffer Create(void * ptr, NSizeType size, bool ownsPtr)
	{
		HNBuffer handle;
		NCheck(NBufferCreateFromPtr(ptr, size, ownsPtr ? NTrue : NFalse, &handle));
		return handle;
	}

	static HNBuffer Create(void * ptr, NSizeType size, NMemoryType ptrType)
	{
		HNBuffer handle;
		NCheck(NBufferCreateFromPtrEx(ptr, size, ptrType, &handle));
		return handle;
	}

	static HNBuffer Create(const void * ptr, NSizeType size)
	{
		HNBuffer handle;
		NCheck(NBufferCreateFromConstPtr(ptr, size, &handle));
		return handle;
	}

	static HNBuffer Create(void * ptr, NSizeType size, NTypes::PointerFreeProc pFree, void * pFreeParam);

	static HNBuffer Create(const NBuffer & srcBuffer, NSizeType offset, NSizeType size)
	{
		HNBuffer handle;
		NCheck(NBufferCreateFromBuffer(srcBuffer.GetHandle(), offset, size, &handle));
		return handle;
	}

public:
	static void Copy(const NBuffer & srcBuffer, NSizeType srcOffset, const NBuffer & dstBuffer, NSizeType dstOffset, NSizeType size)
	{
		NCheck(NBufferCopy(srcBuffer.GetHandle(), srcOffset, dstBuffer.GetHandle(), dstOffset, size));
	}

	static NBuffer GetEmpty()
	{
		HNBuffer hValue;
		NCheck(NBufferGetEmpty(&hValue));
		return FromHandle<NBuffer>(hValue, true);
	}

	explicit NBuffer(NSizeType size)
		: NObject(Create(size), true)
	{
	}

	NBuffer(void * ptr, NSizeType size, bool ownsPtr = true)
		: NObject(Create(ptr, size, ownsPtr), true)
	{
	}

	NBuffer(void * ptr, NSizeType size, NMemoryType ptrType)
		: NObject(Create(ptr, size, ptrType), true)
	{
	}

	NBuffer(const void * ptr, NSizeType size)
		: NObject(Create(ptr, size), true)
	{
	}

	NBuffer(void * ptr, NSizeType size, NTypes::PointerFreeProc pFree, void * pFreeParam)
		: NObject(Create(ptr, size, pFree, pFreeParam), true)
	{
	}

	NBuffer(const NBuffer & srcBuffer, NSizeType offset, NSizeType size)
		: NObject(Create(srcBuffer, offset, size), true)
	{
	}

	void CopyTo(const NBuffer & dstBuffer, NSizeType dstOffset) const
	{
		NCheck(NBufferCopyTo(GetHandle(), dstBuffer.GetHandle(), dstOffset));
	}

	void CopyTo(void * pDstBuffer, NSizeType dstBufferSize) const
	{
		NCheck(NBufferCopyToPtr(GetHandle(), pDstBuffer, dstBufferSize));
	}

	void CopyTo(NSizeType offset, void * pDstBuffer, NSizeType dstBufferSize, NSizeType size) const
	{
		NCheck(NBufferCopyToPtrRange(GetHandle(), offset, pDstBuffer, dstBufferSize, size));
	}

	void CopyFrom(const void * pSrcBuffer, NSizeType srcBufferSize, NSizeType offset)
	{
		NCheck(NBufferCopyFromPtr(GetHandle(), pSrcBuffer, srcBufferSize, offset));
	}

	const void * GetPtr() const
	{
		void * value;
		NCheck(NBufferGetPtr(GetHandle(), &value));
		return value;
	}

	void * ToPtr(NSizeType * pBufferSize)
	{
		void * pBuffer;
		NCheck(NBufferToPtr(GetHandle(), pBufferSize, &pBuffer));
		return pBuffer;
	}

	void * GetPtr()
	{
		void * value;
		NCheck(NBufferGetPtr(GetHandle(), &value));
		return value;
	}

	NSizeType GetSize() const
	{
		NSizeType value;
		NCheck(NBufferGetSize(GetHandle(), &value));
		return value;
	}
};

}}

#include <Core/NTypes.hpp>

namespace Neurotec { namespace IO
{

inline HNBuffer NBuffer::Create(void * ptr, NSizeType size, NTypes::PointerFreeProc pFree, void * pFreeParam)
{
	NCallback free = NTypes::CreateCallback(NTypes::PointerFreeProcImpl, pFree, pFreeParam);
	HNBuffer handle;
	NCheck(NBufferCreateFromPtrWithFree(ptr, size, free.GetHandle(), &handle));
	return handle;
}

}}

#endif // !N_BUFFER_HPP_INCLUDED
