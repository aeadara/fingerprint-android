#ifndef CBEFF_PRODUCT_IDENTIFIERS_HPP_INCLUDED
#define CBEFF_PRODUCT_IDENTIFIERS_HPP_INCLUDED

#include <Core/NTypes.hpp>
namespace Neurotec { namespace Biometrics { namespace Standards
{
#include <Biometrics/Standards/CbeffProductIdentifiers.h>
}}}

namespace Neurotec { namespace Biometrics { namespace Standards
{

#undef CBEFF_PI_VENDOR_UNKNOWN_PRODUCT_UNKNOWN

const NUShort CBEFF_PI_VENDOR_UNKNOWN_PRODUCT_UNKNOWN = 0x0001;

class CbeffProductIdentifiers
{
	N_DECLARE_STATIC_OBJECT_CLASS(CbeffProductIdentifiers)
};

}}}

#endif // !CBEFF_PRODUCT_IDENTIFIERS_HPP_INCLUDED