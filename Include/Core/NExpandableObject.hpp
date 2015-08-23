#ifndef N_EXPANDABLE_OBJECT_HPP_INCLUDED
#define N_EXPANDABLE_OBJECT_HPP_INCLUDED

#include <Core/NObject.hpp>
#include <Core/NPropertyBag.hpp>
namespace Neurotec
{
#include <Core/NExpandableObject.h>
}

namespace Neurotec
{

class NExpandableObject : public NObject
{
	N_DECLARE_OBJECT_CLASS(NExpandableObject, NObject)

public:
	NPropertyBag GetProperties() const
	{
		return GetObject<HandleType, NPropertyBag>(NExpandableObjectGetProperties, true);
	}
};

}

#endif // !N_EXPANDABLE_OBJECT_HPP_INCLUDED
