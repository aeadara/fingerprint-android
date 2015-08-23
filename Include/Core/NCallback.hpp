#include <Core/NTypes.hpp>

#ifndef N_CALLBACK_HPP_INCLUDED
#define N_CALLBACK_HPP_INCLUDED

namespace Neurotec
{
#include <Core/NCallback.h>
}

namespace Neurotec
{

class NCallback
{
private:
	HNCallback handle;

	void Set(HNCallback hValue)
	{
		if (handle != NULL)
		{
			NCheck(NCallbackFree(handle));
		}
		handle = hValue;
	}

public:
	static bool Equals(const NCallback & value, const NCallback & otherValue)
	{
		NBool r;
		NCheck(NCallbackEquals(value.handle, otherValue.handle, &r));
		return r != 0;
	}

	NCallback()
		: handle(NULL)
	{
	}

	NCallback(const NCallback & other)
		: handle(NULL)
	{
		this->operator=(other);
	}

#ifdef N_CPP11
	NCallback(NCallback && other)
		: handle(other.handle)
	{
		other.handle = nullptr;
	}

	NCallback & operator=(NCallback && other)
	{
		if (this != &other)
		{
			Set(nullptr);
			handle = other.handle;
			other.handle = nullptr;
		}
		return *this;
	}
#endif

	NCallback(HNCallback hValue, bool ownsHandle)
		: handle(ownsHandle ? hValue : NULL)
	{
		if (!ownsHandle) NCheck(NCallbackClone(hValue, &handle));
	}

	NCallback(void * pProc, void * pParam)
		: handle(NULL)
	{
		NCheck(NCallbackCreateRaw(pProc, pParam, &handle));
	}

	template<typename T> NCallback(T pProc, void * pParam)
		: handle(NULL)
	{
		NCheck(NCallbackCreate(pProc, pParam, &handle));
	}

	NCallback(void * pProc, void * pParam, NPointerFreeProc pFree, NPointerGetHashCodeProc pGetHashCode, NPointerEqualsProc pEquals)
		: handle(NULL)
	{
		NCheck(NCallbackCreateCustomRaw(pProc, pParam, pFree, pGetHashCode, pEquals, &handle));
	}

	template<typename T> NCallback(T pProc, void * pParam, NPointerFreeProc pFree, NPointerGetHashCodeProc pGetHashCode, NPointerEqualsProc pEquals)
		: handle(NULL)
	{
		NCheck(NCallbackCreateCustom(pProc, pParam, pFree, pGetHashCode, pEquals, &handle));
	}

	NCallback(void * pProc, const NObject & object);
	template<typename T> NCallback(T pProc, const NObject & object);

	~NCallback()
	{
		Set(NULL);
	}

	HNCallback GetHandle() const
	{
		return handle;
	}

	HNCallback CloneHandle() const
	{
		HNCallback hValue;
		NCheck(NCallbackClone(handle, &hValue));
		return hValue;
	}

	bool IsNull() const
	{
		return handle == NULL;
	}

	NInt GetHashCode() const
	{
		NInt value;
		NCheck(NCallbackGetHashCode(handle, &value));
		return value;
	}

	bool Equals(const NCallback & value) const
	{
		NBool r;
		NCheck(NCallbackEquals(handle, value.handle, &r));
		return r != 0;
	}

	void * GetProcRaw() const
	{
		return NCallbackGetProcRaw(handle);
	}

	template<typename T> T GetProc() const
	{
		return NCallbackGetProc(T, handle);
	}

	void * GetParam() const
	{
		return NCallbackGetParam(handle);
	}

	NCallback & operator=(const NCallback & other)
	{
		return this->operator=(other.handle);
	}

	NCallback & operator=(HNCallback hOtherValue)
	{
		if (handle != hOtherValue)
		{
			HNCallback hValue = NULL;
			if (hOtherValue)
			{
				NCheck(NCallbackClone(hOtherValue, &hValue));
			}
			Set(hValue);
		}
		return *this;
	}
};

inline bool operator==(const NCallback & value1, const NCallback & value2)
{
	return NCallback::Equals(value1, value2);
}

inline bool operator!=(const NCallback & value1, const NCallback & value2)
{
	return !NCallback::Equals(value1, value2);
}

} // namespace Neurotec

#endif // !N_CALLBACK_HPP_INCLUDED
