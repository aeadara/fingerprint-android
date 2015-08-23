#ifndef NF_MATCHING_DETAILS_HPP_INCLUDED
#define NF_MATCHING_DETAILS_HPP_INCLUDED

#include <Biometrics/NXMatchingDetails.hpp>
namespace Neurotec { namespace Biometrics
{
#include <Biometrics/NFMatchingDetails.h>
}}

namespace Neurotec { namespace Biometrics
{

class NMatchingDetails;

class NFMatchingDetails : public NXMatchingDetails
{
	N_DECLARE_OBJECT_CLASS(NFMatchingDetails, NXMatchingDetails)

public:
	NInt GetCenterX() const
	{
		NInt value;
		NCheck(NFMatchingDetailsGetCenterX(GetHandle(), &value));
		return value;
	}

	NInt GetCenterY() const
	{
		NInt value;
		NCheck(NFMatchingDetailsGetCenterY(GetHandle(), &value));
		return value;
	}

	NByte GetRotation() const
	{
		NByte value;
		NCheck(NFMatchingDetailsGetRotation(GetHandle(), &value));
		return value;
	}

	NInt GetTranslationX() const
	{
		NInt value;
		NCheck(NFMatchingDetailsGetTranslationX(GetHandle(), &value));
		return value;
	}

	NInt GetTranslationY() const
	{
		NInt value;
		NCheck(NFMatchingDetailsGetTranslationY(GetHandle(), &value));
		return value;
	}

	NInt GetMatedMinutiae(NIndexPair * arValue, NInt valueLength) const
	{
		return NCheck(NFMatchingDetailsGetMatedMinutiae(GetHandle(), arValue, valueLength));
	}

	NArrayWrapper<NIndexPair> GetMatedMinutiae() const
	{
		NInt count = GetMatedMinutiae(NULL, 0);
		NArrayWrapper<NIndexPair> values(count);
		count = GetMatedMinutiae(values.GetPtr(), count);
		values.SetCount(count);
		return values;
	}
};

}}

#include <Biometrics/NMatchingDetails.hpp>

#endif // !NF_MATCHING_DETAILS_HPP_INCLUDED
