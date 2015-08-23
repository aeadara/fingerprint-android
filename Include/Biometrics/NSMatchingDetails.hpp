#ifndef NS_MATCHING_DETAILS_HPP_INCLUDED
#define NS_MATCHING_DETAILS_HPP_INCLUDED

#include <Biometrics/NXMatchingDetails.hpp>
namespace Neurotec { namespace Biometrics
{
#include <Biometrics/NSMatchingDetails.h>
}}

namespace Neurotec { namespace Biometrics
{

class NMatchingDetails;

class NSMatchingDetails : public NXMatchingDetails
{
	N_DECLARE_OBJECT_CLASS(NSMatchingDetails, NXMatchingDetails)
};

}}

#include <Biometrics/NMatchingDetails.hpp>

#endif // !NS_MATCHING_DETAILS_HPP_INCLUDED
