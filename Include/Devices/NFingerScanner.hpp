#include <Devices/NFScanner.hpp>

#ifndef N_FINGER_SCANNER_HPP_INCLUDED
#define N_FINGER_SCANNER_HPP_INCLUDED

namespace Neurotec { namespace Devices
{
#include <Devices/NFingerScanner.h>
}}

namespace Neurotec { namespace Devices
{

class NFingerScanner : public NFScanner
{
	N_DECLARE_OBJECT_CLASS(NFingerScanner, NFScanner)
};

}}

#endif // !N_FINGER_SCANNER_HPP_INCLUDED
