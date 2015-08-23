#ifndef CBEFF_DEVICE_IDENTIFIERS_HPP_INCLUDED
#define CBEFF_DEVICE_IDENTIFIERS_HPP_INCLUDED

#include <Core/NTypes.hpp>
namespace Neurotec { namespace Biometrics { namespace Standards
{
#include <Biometrics/Standards/CbeffDeviceIdentifiers.h>
}}}

namespace Neurotec { namespace Biometrics { namespace Standards
{

#undef CBEFF_DI_VENDOR_UNKNOWN_PRODUCT_UNKNOWN

const NUShort CBEFF_DI_VENDOR_UNKNOWN_PRODUCT_UNKNOWN = 0x0001;

class CbeffDeviceIdentifiers
{
	N_DECLARE_STATIC_OBJECT_CLASS(CbeffDeviceIdentifiers)
};

}}}

#endif // !CBEFF_DEVICE_IDENTIFIERS_HPP_INCLUDED