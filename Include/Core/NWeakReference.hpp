#ifndef N_WEAK_REFERENCE_HPP_INCLUDED
#define N_WEAK_REFERENCE_HPP_INCLUDED

#include <Core/NObject.hpp>
namespace Neurotec { namespace Internal
{
#include <Core/NWeakReference.h>
}}

namespace Neurotec
{

class NWeakReference : private Internal::NWeakReference
{
	N_DECLARE_PRIMITIVE_CLASS(NWeakReference)

public:
	NWeakReference()
	{
		NCheck(Internal::NWeakReferenceInit(this));
	}

	NWeakReference(const NObject & value)
	{
		memset(this, 0, sizeof(NWeakReference));
		NCheck(Internal::NWeakReferenceInitWith(this, value.GetHandle()));
	}

	~NWeakReference()
	{
		NCheck(Internal::NWeakReferenceDispose(this));
	}

	NObject Get()
	{
		HNObject hValue;
		NCheck(Internal::NWeakReferenceGet(this, &hValue));
		return NObject::FromHandle<NObject>(hValue, true);
	}

	void Set(const NObject & value)
	{
		NCheck(Internal::NWeakReferenceSet(this, value.GetHandle()));
	}
};

}

#endif // !N_WEAK_REFERENCE_HPP_INCLUDED
