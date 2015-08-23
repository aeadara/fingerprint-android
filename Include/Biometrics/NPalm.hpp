#include <Biometrics/NFrictionRidge.hpp>

#ifndef N_PALM_HPP_INCLUDED
#define N_PALM_HPP_INCLUDED

namespace Neurotec { namespace Biometrics
{
#include <Biometrics/NPalm.h>
}}

namespace Neurotec { namespace Biometrics
{

class NPalm : public NFrictionRidge
{
	N_DECLARE_OBJECT_CLASS(NPalm, NFrictionRidge)

private:
	static HNPalm Create()
	{
		HNPalm handle;
		NCheck(NPalmCreate(&handle));
		return handle;
	}

public:
	NPalm()
		: NFrictionRidge(Create(), true)
	{
	}
};

}}

#endif // !N_PALM_HPP_INCLUDED
