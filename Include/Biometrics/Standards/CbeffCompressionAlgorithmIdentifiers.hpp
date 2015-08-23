#ifndef CBEFF_COMPRESSION_ALGORITHM_IDENTIFIERS_HPP_INCLUDED
#define CBEFF_COMPRESSION_ALGORITHM_IDENTIFIERS_HPP_INCLUDED

#include <Core/NTypes.hpp>
namespace Neurotec { namespace Biometrics { namespace Standards
{
#include <Biometrics/Standards/CbeffCompressionAlgorithmIdentifiers.h>
}}}

namespace Neurotec { namespace Biometrics { namespace Standards
{

#undef CBEFF_CAI_INCITS_TC_M1_BIOMETRICS_WSQ
#undef CBEFF_CAI_INCITS_TC_M1_BIOMETRICS_JPEG
#undef CBEFF_CAI_INCITS_TC_M1_BIOMETRICS_JPEG_2000
#undef CBEFF_CAI_INCITS_TC_M1_BIOMETRICS_PNG

const NUShort CBEFF_CAI_INCITS_TC_M1_BIOMETRICS_WSQ = 0x8001;
const NUShort CBEFF_CAI_INCITS_TC_M1_BIOMETRICS_JPEG = 0x8003;
const NUShort CBEFF_CAI_INCITS_TC_M1_BIOMETRICS_JPEG_2000 = 0x8004;
const NUShort CBEFF_CAI_INCITS_TC_M1_BIOMETRICS_PNG = 0x8007;

class CbeffCompressionAlgorithmIdentifiers
{
	N_DECLARE_STATIC_OBJECT_CLASS(CbeffCompressionAlgorithmIdentifiers)
};

}}}

#endif // !CBEFF_COMPRESSION_ALGORITHM_IDENTIFIERS_HPP_INCLUDED
