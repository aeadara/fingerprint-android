#ifndef N_RGB_HPP_INCLUDED
#define N_RGB_HPP_INCLUDED

#include <Core/NTypes.hpp>
namespace Neurotec { namespace Images
{
#include <Images/NRgb.h>
}}

namespace Neurotec { namespace Images
{

class NRgb : public NRgb_
{
	N_DECLARE_STRUCT_CLASS(NRgb)

public:
	NRgb(NByte red, NByte green, NByte blue)
	{
		Red = red;
		Green = green;
		Blue = blue;
	}

	NString ToString(const NStringWrapper & format = NString()) const
	{
		HNString hValue;
		NCheck(NRgbToStringN(this, format.GetHandle(), &hValue));
		return NString(hValue, true);
	}
};

}}

#endif // !N_RGB_HPP_INCLUDED
