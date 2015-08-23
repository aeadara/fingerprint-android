#include <Biometrics/NBiometricConnection.hpp>

#ifndef N_MATCHING_RESULT_HPP_INCLUDED
#define N_MATCHING_RESULT_HPP_INCLUDED

#include <Core/NObject.hpp>
#include <Biometrics/NMatchingDetails.hpp>
#include <Biometrics/NBiometric.hpp>
namespace Neurotec { namespace Biometrics
{
#include <Biometrics/NMatchingResult.h>
}}

namespace Neurotec { namespace Biometrics
{

class NMatchingResult : public NObject
{
	N_DECLARE_OBJECT_CLASS(NMatchingResult, NObject)

public:
	NSubject GetOwner() const;

	NString GetId() const
	{
		return GetString(NMatchingResultGetId);
	}

	NMatchingDetails GetMatchingDetails() const
	{
		return GetObject<HandleType, NMatchingDetails>(NMatchingResultGetMatchingDetails, true);
	}

	::Neurotec::IO::NBuffer GetMatchingDetailsBuffer() const
	{
		return GetObject<HandleType, ::Neurotec::IO::NBuffer>(NMatchingResultGetMatchingDetailsBuffer, true);
	}

	NInt GetScore() const
	{
		NInt value;
		NCheck(NMatchingResultGetScore(GetHandle(), &value));
		return value;
	}

	NSubject GetSubject() const;

	NBiometricConnection GetConnection() const
	{
		return GetObject<HandleType, NBiometricConnection>(NMatchingResultGetConnection, true);
	}
};

}}


#include <Biometrics/NSubject.hpp>

namespace Neurotec { namespace Biometrics
{

inline NSubject NMatchingResult::GetOwner() const
{
	return NObject::GetOwner<NSubject>();
}

inline NSubject NMatchingResult::GetSubject() const
{
	return GetObject<HandleType, NSubject>(NMatchingResultGetSubject, true);
}

}}

#endif // !N_MATCHING_RESULT_HPP_INCLUDED
