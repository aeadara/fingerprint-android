#ifndef SIMPLE_TAG_HPP_INCLUDED
#define SIMPLE_TAG_HPP_INCLUDED

#include <Core/NTypes.hpp>
namespace Neurotec { namespace SmartCards
{
#include <SmartCards/SimpleTag.h>
}}

namespace Neurotec { namespace SmartCards
{

class SimpleTag
{
	N_DECLARE_BASIC_CLASS(SimpleTag)

public:
	bool IsValid() const
	{
		return SimpleTagIsValid(value) != 0;
	}

	NString ToString(const NStringWrapper & format = NString()) const
	{
		HNString hValue;
		NCheck(SimpleTagToStringN(value, format.GetHandle(), &hValue));
		return NString(hValue, true);
	}
};

}}

#endif // !SIMPLE_TAG_HPP_INCLUDED
