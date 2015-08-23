#ifndef N_BIOMETRICS_HPP_INCLUDED
#define N_BIOMETRICS_HPP_INCLUDED

#include <Media/Processing/NMediaProc.hpp>
namespace Neurotec { namespace Biometrics
{
#include <Biometrics/NBiometrics.h>
}}

namespace Neurotec { namespace Biometrics
{

class NBiometrics
{
private:
	NBiometrics()
	{
	}

	N_DECLARE_MODULE_CLASS(NBiometrics)
};

}}

#endif // !N_BIOMETRICS_HPP_INCLUDED
