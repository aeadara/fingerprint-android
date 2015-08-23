#ifndef CBEFF_QUALITY_ALGORITHM_IDENTIFIERS_HPP_INCLUDED
#define CBEFF_QUALITY_ALGORITHM_IDENTIFIERS_HPP_INCLUDED

#include <Core/NTypes.hpp>
namespace Neurotec { namespace Biometrics { namespace Standards
{
#include <Biometrics/Standards/CbeffQualityAlgorithmIdentifiers.h>
}}}

namespace Neurotec { namespace Biometrics { namespace Standards
{

#undef CBEFF_QAI_INTECH_QM

#undef CBEFF_QAI_NIST_NFIQ

#undef CBEFF_QAI_NEUROTECHNOLOGY_FRQ_1

#undef CBEFF_QAI_VENDOR_UNKNOWN_PRODUCT_UNKNOWN

const NUShort CBEFF_QAI_INTECH_QM = 0x001A;

const NUShort CBEFF_QAI_NIST_NFIQ = 0x377D;

const NUShort CBEFF_QAI_VENDOR_UNKNOWN_PRODUCT_UNKNOWN = 0x0001;

const NUShort CBEFF_QAI_NEUROTECHNOLOGY_FRQ_1 = 0x0100;

class CbeffQualityAlgorithmIdentifiers
{
	N_DECLARE_STATIC_OBJECT_CLASS(CbeffQualityAlgorithmIdentifiers)
};

}}}

#endif // !CBEFF_QUALITY_ALGORITHM_IDENTIFIERS_HPP_INCLUDED
