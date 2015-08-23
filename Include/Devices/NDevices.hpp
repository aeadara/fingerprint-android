#ifndef N_DEVICES_HPP_INCLUDED
#define N_DEVICES_HPP_INCLUDED

#include <Media/NMedia.hpp>
#include <Biometrics/NBiometrics.hpp>
namespace Neurotec { namespace Devices
{
#include <Devices/NDevices.h>
}}

namespace Neurotec { namespace Devices
{

class NDevices
{
private:
	NDevices()
	{
	}

	N_DECLARE_MODULE_CLASS(NDevices)
};

}}

#endif // !N_DEVICES_HPP_INCLUDED
