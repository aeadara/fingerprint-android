#ifndef NL_MATCHING_DETAILS_HPP_INCLUDED
#define NL_MATCHING_DETAILS_HPP_INCLUDED

#include <Biometrics/NXMatchingDetails.hpp>
namespace Neurotec { namespace Biometrics
{
#include <Biometrics/NLMatchingDetails.h>
}}

namespace Neurotec { namespace Biometrics
{

class NMatchingDetails;

class NLMatchingDetails : public NXMatchingDetails
{
	N_DECLARE_OBJECT_CLASS(NLMatchingDetails, NXMatchingDetails)
};

}}

#include <Biometrics/NMatchingDetails.hpp>

#endif // !NL_MATCHING_DETAILS_HPP_INCLUDED
