#include <Core/NObject.hpp>

#ifndef N_OBJECT_PART_BASE_HPP_INCLUDED
#define N_OBJECT_PART_BASE_HPP_INCLUDED

namespace Neurotec
{

#include <Core/NNoDeprecate.h>
template<typename TOwner> class NObjectPartBase : public NObjectBase
{
public:
	typedef TOwner OwnerType;
	typedef typename TOwner::HandleType OwnerHandleType;

protected:
	NObject owner;

	NObjectPartBase()
		: owner(NULL)
	{
	}

	void SetOwner(const TOwner & owner)
	{
		this->owner = owner.GetHandle();
	}

public:
	TOwner * GetOwner()
	{
		return reinterpret_cast<TOwner *>(&owner);
	}

	const TOwner * GetOwner() const
	{
		return reinterpret_cast<const TOwner *>(&owner);
	}

	typename TOwner::HandleType GetOwnerHandle() const
	{
		return (typename TOwner::HandleType)owner.GetHandle();
	}

	bool operator==(const NObjectPartBase & other) const
	{
		return this->GetOwnerHandle() == other.GetOwnerHandle();
	}

	bool operator!=(const NObjectPartBase & other) const
	{
		return this->GetOwnerHandle() != other.GetOwnerHandle();
	}
};
#include <Core/NReDeprecate.h>

}

#endif // !N_OBJECT_PART_BASE_HPP_INCLUDED
