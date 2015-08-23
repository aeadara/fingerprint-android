#ifndef N_MEMORY_HPP_INCLUDED
#define N_MEMORY_HPP_INCLUDED

#include <Core/NTypes.hpp>
#include <memory.h>
#include <string.h>
namespace Neurotec
{
#include <Core/NMemory.h>
}

namespace Neurotec
{

#undef NClear
#undef NAlignedAlloc
#undef NAlignedCAlloc
#undef NAlignedReAlloc
#undef NAlignedAllocArray
#undef NAlignedCAllocArray
#undef NAlignedReAllocArray

inline NResult NClear(void * pBlock, NSizeType size)
{
	return NFill(pBlock, 0, size);
}

inline NResult NAlignedAlloc(NSizeType size, NSizeType alignment, void * * ppBlock)
{
	return NAlignedOffsetAlloc(size, alignment, 0, ppBlock);
}

inline NResult NAlignedCAlloc(NSizeType size, NSizeType alignment, void * * ppBlock)
{
	return NAlignedOffsetCAlloc(size, alignment, 0, ppBlock);
}

inline NResult NAlignedReAlloc(void * * ppBlock, NSizeType size, NSizeType alignment)
{
	return NAlignedOffsetReAlloc(ppBlock, size, alignment, 0);
}

inline NResult NAlignedAllocArray(NSizeType elementSize, NInt length, NSizeType alignment, void * * ppRow)
{
	return NAlignedOffsetAllocArray(elementSize, length, alignment, 0, ppRow);
}

inline NResult NAlignedCAllocArray(NSizeType elementSize, NInt length, NSizeType alignment, void * * ppRow)
{
	return NAlignedOffsetCAllocArray(elementSize, length, alignment, 0, ppRow);
}

inline NResult NAlignedReAllocArray(NSizeType elementSize, void * * ppRow, NInt length, NSizeType alignment)
{
	return NAlignedOffsetReAllocArray(elementSize, ppRow, length, alignment, 0);
}

inline void * NAlloc(NSizeType size)
{
	void * pBlock;
	NCheck(NAlloc(size, &pBlock));
	return pBlock;
}

inline void * NCAlloc(NSizeType size)
{
	void * pBlock;
	NCheck(NCAlloc(size, &pBlock));
	return pBlock;
}

inline void * NReAlloc(void * pBlock, NSizeType size)
{
	NCheck(NReAlloc(&pBlock, size));
	return pBlock;
}

inline void NCopyMemory(void * pDstBlock, const void * pSrcBlock, NSizeType size)
{
	NCheck(NCopy(pDstBlock, pSrcBlock, size));
}

inline void NMoveMemory(void * pDstBlock, const void * pSrcBlock, NSizeType size)
{
	NCheck(NMove(pDstBlock, pSrcBlock, size));
}

inline void NFillMemory(void * pBlock, NByte value, NSizeType size)
{
	NCheck(NFill(pBlock, value, size));
}

inline void NClearMemory(void * pBlock, NSizeType size)
{
	NCheck(NClear(pBlock, size));
}

inline NInt NCompare(const void * pBlock1, const void * pBlock2, NSizeType size)
{
	NInt result;
	NCheck(NCompare(pBlock1, pBlock2, size, &result));
	return result;
}

inline void * NAlignedAlloc(NSizeType size, NSizeType alignment, NSizeType offset = 0)
{
	void * pBlock;
	NCheck(NAlignedOffsetAlloc(size, alignment, offset, &pBlock));
	return pBlock;
}

inline void * NAlignedCAlloc(NSizeType size, NSizeType alignment, NSizeType offset = 0)
{
	void * pBlock;
	NCheck(NAlignedOffsetCAlloc(size, alignment, offset, &pBlock));
	return pBlock;
}

inline void * NAlignedReAlloc(void * pBlock, NSizeType size, NSizeType alignment, NSizeType offset = 0)
{
	NCheck(NAlignedOffsetReAlloc(&pBlock, size, alignment, offset));
	return pBlock;
}


template<typename T> T * NAllocArray(NInt length)
{
	T * pArray;
	NCheck(NAllocArray(sizeof(T), length, (void * *)&pArray));
	return pArray;
}

template<typename T> T * NCAllocArray(NInt length)
{
	T * pArray;
	NCheck(NCAllocArray(sizeof(T), length, (void * *)&pArray));
	return pArray;
}

template<typename T> T * NReAllocArray(T * pArray, NInt length)
{
	NCheck(NReAllocArray(sizeof(T), (void * *)&pArray, length));
	return pArray;
}

template<typename T> void NCopyArray(T * pDstArray, const T * pSrcArray, NInt length)
{
	NCheck(NCopyArray(sizeof(T), pDstArray, pSrcArray, length));
}

template<typename T> void NMoveArray(T * pDstArray, const T * pSrcArray, NInt length)
{
	NCheck(NMoveArray(sizeof(T), pDstArray, pSrcArray, length));
}

template<typename T> void NClearArray(T * pArray, NInt length)
{
	NCheck(NClearArray(sizeof(T), pArray, length));
}

template<typename T> void * NAlignedAllocArray(NInt length, NSizeType alignment, NInt offset = 0)
{
	T * pArray;
	NCheck(NAlignedOffsetAllocArray(sizeof(T), length, alignment, offset, (void**)&pArray));
	return pArray;
}

template<typename T> void * NAlignedCAllocArray(NInt length, NSizeType alignment, NInt offset = 0)
{
	T * pArray;
	NCheck(NAlignedOffsetCAllocArray(sizeof(T), length, alignment, offset, (void**)&pArray));
	return pArray;
}

template<typename T> void * NAlignedReAllocArray(T * pArray, NInt length, NSizeType alignment, NInt offset = 0)
{
	NCheck(NAlignedOffsetReAllocArray(sizeof(T), (void**)&pArray, length, alignment, offset));
	return pArray;
}

template<typename T> NInt NArrayFromArray(const T * pSrcArray, NInt srcLength, T * pDstArray, NInt dstLength)
{
	return NCheck(NGetElements(T, pSrcArray, srcLength, pDstArray, dstLength));
}

template<typename T> T * NArrayFromArray(const T * pSrcArray, NInt srcLength, NInt * pDstValueCount)
{
	T * pDstArray;
	NCheck(NGetArray(T, pSrcArray, srcLength, (void**)&pDstArray, pDstValueCount));
	return pDstArray;
}

struct Clear
{
};

extern const Clear clear;

class NAutoFree
{
private:
	void * ptr;

public:
	explicit NAutoFree(void * ptr = NULL)
		: ptr(ptr)
	{
	}

	NAutoFree(NAutoFree & value)
		: ptr(value.Release())
	{
	}

	~NAutoFree()
	{
		Reset();
	}

	NAutoFree & operator=(NAutoFree & value)
	{
		Reset(value.Release());
		return (*this);
	}

	void * Get() const
	{
		return ptr;
	}

	void * Release()
	{
		void * ptr = this->ptr;
		this->ptr = NULL;
		return ptr;
	}

	void Reset(void * ptr = NULL)
	{
		if (ptr != this->ptr)
		{
			NFree(this->ptr);
			this->ptr = ptr;
		}
	}
};

class NAutoAlignedFree
{
private:
	void * ptr;

public:
	explicit NAutoAlignedFree(void * ptr = NULL)
		: ptr(ptr)
	{
	}

	NAutoAlignedFree(NAutoAlignedFree & value)
		: ptr(value.Release())
	{
	}

	~NAutoAlignedFree()
	{
		Reset();
	}

	NAutoAlignedFree & operator=(NAutoAlignedFree & value)
	{
		Reset(value.Release());
		return (*this);
	}

	void * Get() const
	{
		return ptr;
	}

	void * Release()
	{
		void * ptr = this->ptr;
		this->ptr = NULL;
		return ptr;
	}

	void Reset(void * ptr = NULL)
	{
		if (ptr != this->ptr)
		{
			NAlignedFree(this->ptr);
			this->ptr = ptr;
		}
	}
};

template<typename T> class NAutoArray
{
private:
	T * ptr;
	NInt count;

public:
	NAutoArray()
		: ptr(NULL), count(0)
	{
	}

	NAutoArray(T * ptr, NInt count)
		: ptr(ptr), count(count)
	{
	}

	NAutoArray(NInt count)
		: ptr(count == 0 ? NULL : (T *)NCAllocArray<T>(count)), count(count)
	{
	}

	NAutoArray(NAutoArray & value)
		: ptr(value.ptr), count(value.count)
	{
		value.Release();
	}

	~NAutoArray()
	{
		Reset();
	}

	NAutoArray & operator=(NAutoArray & value)
	{
		NInt count = value.count;
		Reset(value.Release(), count);
		return (*this);
	}

	T * operator->() const
	{
		return Get();
	}

	T & operator*() const
	{
		return *Get();
	}

	T & operator[](int index) const
	{
		return Get()[index];
	}

	T * Get() const
	{
		return ptr;
	}

	T & Get(int index) const
	{
		return ptr[index];
	}

	int GetCount() const
	{
		return count;
	}

	T * Release()
	{
		T * ptr = this->ptr;
		this->ptr = NULL;
		count = 0;
		return ptr;
	}

	void Reset()
	{
		Reset(NULL, 0);
	}

	void Reset(T * ptr, NInt count)
	{
		if (ptr != this->ptr)
		{
			if (this->ptr)
			{
				NFree(this->ptr);
			}
			this->ptr = ptr;
		}
		this->count = count;
	}
};

template<typename T> class NAutoAlignedArray
{
private:
	T * ptr;
	NInt count;

public:
	NAutoAlignedArray()
		: ptr(NULL), count(0)
	{
	}

	NAutoAlignedArray(T * ptr, NInt count)
		: ptr(ptr), count(count)
	{
	}

	NAutoAlignedArray(NInt count, NSizeType alignment, NInt offset = 0)
		: ptr(count == 0 ? NULL : (T *)NAlignedCAllocArray<T>(count, alignment, offset)), count(count)
	{
	}

	NAutoAlignedArray(NAutoAlignedArray & value)
		: ptr(value.ptr), count(value.count)
	{
		value.Release();
	}

	~NAutoAlignedArray()
	{
		Reset();
	}

	NAutoAlignedArray & operator=(NAutoAlignedArray & value)
	{
		NInt count = value.count;
		Reset(value.Release(), count);
		return (*this);
	}

	T * operator->() const
	{
		return Get();
	}

	T & operator*() const
	{
		return *Get();
	}

	T & operator[](int index) const
	{
		return Get()[index];
	}

	T * Get() const
	{
		return ptr;
	}

	T & Get(int index) const
	{
		return ptr[index];
	}

	int GetCount() const
	{
		return count;
	}

	T * Release()
	{
		T * ptr = this->ptr;
		this->ptr = NULL;
		count = 0;
		return ptr;
	}

	void Reset()
	{
		Reset(NULL, 0);
	}

	void Reset(T * ptr, NInt count)
	{
		if (ptr != this->ptr)
		{
			if (this->ptr)
			{
				NAlignedFree(this->ptr);
			}
			this->ptr = ptr;
		}
		this->count = count;
	}
};

#include <Core/NNoDeprecate.h>
template<typename T> class auto_array
{
private:
	T * ptr;
	int count;

public:
	auto_array()
		: ptr(NULL), count(0)
	{
	}

	auto_array(T * ptr, int count)
		: ptr(ptr), count(count)
	{
	}

	auto_array(int count)
		: ptr(count == 0 ? NULL : new T[count]), count(count)
	{
	}

	auto_array(auto_array<T> & value)
		: ptr(value.ptr), count(value.count)
	{
		value.release();
	}

	~auto_array()
	{
		reset();
	}

	auto_array & operator=(auto_array & value)
	{
		int count = value.count;
		reset(value.release(), count);
		return (*this);
	}

	T * operator->() const
	{
		return get();
	}

	T & operator*() const
	{
		return *get();
	}

	T & operator[](int index) const
	{
		return get()[index];
	}

	T * get() const
	{
		return ptr;
	}

	T & get(int index) const
	{
		return ptr[index];
	}

	int size() const
	{
		return count;
	}

	T * release()
	{
		T * ptr = this->ptr;
		this->ptr = NULL;
		count = 0;
		return ptr;
	}

	void reset()
	{
		reset(NULL, 0);
	}

	void reset(T * ptr, int count)
	{
		if (ptr != this->ptr)
		{
			if (this->ptr)
			{
				delete[] this->ptr;
			}
			this->ptr = ptr;
		}
		this->count = count;
	}
};

template<typename T> class auto_ptr_array
{
private:
	T * * ptrs;
	int count;

public:
	auto_ptr_array()
		: ptrs(NULL), count(0)
	{
	}

	auto_ptr_array(T * * ptrs, int count)
		: ptrs(ptrs), count(count)
	{
	}

	auto_ptr_array(int count)
		: ptrs(count == 0 ? NULL : new T *[count]), count(count)
	{
	}

	auto_ptr_array(auto_ptr_array<T> & value)
		: ptrs(value.get()), count(value.size())
	{
		value.release();
	}

	~auto_ptr_array()
	{
		reset();
	}

	auto_ptr_array & operator=(auto_ptr_array & value)
	{
		reset(value.get(), value.size());
		value.release();
		return (*this);
	}

	T * * operator->() const
	{
		return get();
	}

	T * & operator*() const
	{
		return *get();
	}

	T * & operator[](int index) const
	{
		return get()[index];
	}

	T * * get() const
	{
		return ptrs;
	}

	T * & get(int index) const
	{
		return ptrs[index];
	}

	int size() const
	{
		return count;
	}

	T * * release()
	{
		T * * ptrs = this->ptrs;
		this->ptrs = NULL;
		this->count = 0;
		return ptrs;
	}

	void reset()
	{
		reset(NULL, 0);
	}

	void reset(T * * ptrs, int count)
	{
		if (ptrs != this->ptrs)
		{
			if (this->ptrs)
			{
				for (int i = 0; i < this->count; i++)
				{
					delete this->ptrs[i];
				}
				delete[] this->ptrs;
			}
			this->ptrs = ptrs;
		}
		this->count = count;
	}
};
#include <Core/NReDeprecate.h>

}

#endif // !N_MEMORY_HPP_INCLUDED
