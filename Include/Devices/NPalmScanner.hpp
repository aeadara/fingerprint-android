#include <Devices/NFScanner.hpp>

#ifndef N_PALM_SCANNER_HPP_INCLUDED
#define N_PALM_SCANNER_HPP_INCLUDED

namespace Neurotec { namespace Devices
{
#include <Devices/NPalmScanner.h>
}}

namespace Neurotec { namespace Devices
{

class NPalmScanner : public NFScanner
{
	N_DECLARE_OBJECT_CLASS(NPalmScanner, NFScanner)
};

}}

#endif // !N_IRIS_SCANNER_HPP_INCLUDED
