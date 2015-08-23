#ifndef N_MATCHING_DETAILS_BASE_HPP_INCLUDED
#define N_MATCHING_DETAILS_BASE_HPP_INCLUDED

#include <Core/NObject.hpp>
#include <Biometrics/NBiometricTypes.hpp>
namespace Neurotec { namespace Biometrics
{
#include <Biometrics/NMatchingDetailsBase.h>
}}

namespace Neurotec { namespace Biometrics
{

class NMatchingDetailsBase : public NObject
{
	N_DECLARE_OBJECT_CLASS(NMatchingDetailsBase, NObject)

public:
	NBiometricType GetBiometricType() const
	{
		NBiometricType value;
		NCheck(NMatchingDetailsBaseGetBiometricType(GetHandle(), &value));
		return value;
	}

	NInt GetScore() const
	{
		NInt value;
		NCheck(NMatchingDetailsBaseGetScore(GetHandle(), &value));
		return value;
	}
};

}}

#endif // !N_MATCHING_DETAILS_BASE_HPP_INCLUDED
