#ifndef N_LICENSING_HPP_INCLUDED
#define N_LICENSING_HPP_INCLUDED

#include <Core/NCore.hpp>
namespace Neurotec { namespace Licensing
{
#include <Licensing/NLicensing.h>
}}

namespace Neurotec { namespace Licensing
{

class NLicensing
{
private:
	NLicensing()
	{
	}

	N_DECLARE_MODULE_CLASS(NLicensing)
};

}}

#endif // !N_LICENSING_HPP_INCLUDED
