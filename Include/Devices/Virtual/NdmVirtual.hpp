#ifndef NDM_VIRTUAL_HPP_INCLUDED
#define NDM_VIRTUAL_HPP_INCLUDED

#include <Devices/NDevices.hpp>
namespace Neurotec { namespace Devices
{
#include <Devices/Virtual/NdmVirtual.h>
}}

namespace Neurotec { namespace Devices
{

class NdmVirtual
{
private:
	NdmVirtual()
	{
	}

	N_DECLARE_MODULE_CLASS(NdmVirtual)
};

}}

#endif // !NDM_VIRTUAL_HPP_INCLUDED
