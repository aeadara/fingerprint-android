#include <Core/NType.hpp>

#ifndef N_OBJECT_PART_HPP_INCLUDED
#define N_OBJECT_PART_HPP_INCLUDED

namespace Neurotec
{
#include <Core/NObjectPart.h>
}

namespace Neurotec
{

class NObjectPart : public NObject
{
	N_DECLARE_OBJECT_CLASS(NObjectPart, NObject)

public:
	::Neurotec::Reflection::NObjectPartInfo GetObjectPartInfo() const;
};

}

#include <Reflection/NObjectPartInfo.hpp>

namespace Neurotec
{

inline ::Neurotec::Reflection::NObjectPartInfo NObjectPart::GetObjectPartInfo() const
{
	HNObjectPartInfo hValue;
	NCheck(NObjectPartGetObjectPartInfo(GetHandle(), &hValue));
	return FromHandle< ::Neurotec::Reflection::NObjectPartInfo>(hValue);
}

}

#endif // !N_OBJECT_PART_HPP_INCLUDED
