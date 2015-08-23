#ifndef NE_MATCHING_DETAILS_HPP_INCLUDED
#define NE_MATCHING_DETAILS_HPP_INCLUDED

#include <Biometrics/NXMatchingDetails.hpp>
namespace Neurotec { namespace Biometrics
{
#include <Biometrics/NEMatchingDetails.h>
}}

namespace Neurotec { namespace Biometrics
{

class NMatchingDetails;

class NEMatchingDetails : public NXMatchingDetails
{
	N_DECLARE_OBJECT_CLASS(NEMatchingDetails, NXMatchingDetails)
};

}}

#include <Biometrics/NMatchingDetails.hpp>

#endif // !NE_MATCHING_DETAILS_HPP_INCLUDED
