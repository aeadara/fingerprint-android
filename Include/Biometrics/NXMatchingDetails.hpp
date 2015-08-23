#ifndef NX_MATCHING_DETAILS_HPP_INCLUDED
#define NX_MATCHING_DETAILS_HPP_INCLUDED

#include <Biometrics/NMatchingDetailsBase.hpp>
namespace Neurotec { namespace Biometrics
{
#include <Biometrics/NXMatchingDetails.h>
}}

namespace Neurotec { namespace Biometrics
{

class NXMatchingDetails : public NMatchingDetailsBase
{
	N_DECLARE_OBJECT_CLASS(NXMatchingDetails, NMatchingDetailsBase)

public:
	NInt GetMatchedIndex() const
	{
		NInt value;
		NCheck(NXMatchingDetailsGetMatchedIndex(GetHandle(), &value));
		return value;
	}
};

}}

#endif // !NX_MATCHING_DETAILS_HPP_INCLUDED
