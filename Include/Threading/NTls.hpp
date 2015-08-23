#ifndef N_TLS_HPP_INCLUDED
#define N_TLS_HPP_INCLUDED

#include <Core/NObject.hpp>
namespace Neurotec { namespace Threading
{
#include <Threading/NTls.h>
}}

namespace Neurotec { namespace Threading
{

class NTls : public NObjectBase
{
private:
	static HNTls Create(NTlsDisposeProc pDispose)
	{
		HNTls hTls;
		NCheck(NTlsCreate(pDispose, &hTls));
		return hTls;
	}

	static HNTls Create()
	{
		HNTls hTls;
		NCheck(NTlsCreateForObject(&hTls));
		return hTls;
	}

	HNTls handle;
	NBool ownsHandle;

public:
	explicit NTls(HNTls handle, bool ownsHandle = true)
		: handle(handle), ownsHandle(ownsHandle)
	{
		if (!handle) NThrowArgumentNullException(N_T("handle"));
	}

	explicit NTls(NTlsDisposeProc pDispose)
		: handle(Create(pDispose)), ownsHandle(true)
	{
	}

	explicit NTls()
		: handle(Create()), ownsHandle(true)
	{
	}

	~NTls()
	{
		if (ownsHandle && handle != NULL) NCheck(NTlsFree(handle));
	}

	HNTls GetHandle() const
	{
		return handle;
	}

	void * GetValue() const
	{
		void * pValue;
		NCheck(NTlsGetValue(GetHandle(), &pValue));
		return pValue;
	}

	void SetValue(void * pValue)
	{
		NCheck(NTlsSetValue(GetHandle(), pValue));
	}

	template<typename T> T GetObject() const;

	void SetObject(const NObject & value)
	{
		NCheck(NTlsSetObject(GetHandle(), value.GetHandle()));
	}
};

template<typename T> inline T NTls::GetObject() const
{
	HNObject hValue;
	NCheck(NTlsGetObject(GetHandle(), &hValue));
	return NObject::FromHandle<T>(hValue, true);
}

}}

#endif // !N_TLS_HPP_INCLUDED
