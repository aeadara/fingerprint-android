#ifndef APDU_CLASS_HPP_INCLUDED
#define APDU_CLASS_HPP_INCLUDED

#include <Core/NTypes.hpp>
namespace Neurotec { namespace SmartCards
{
#include <SmartCards/ApduClass.h>
}}

N_DEFINE_ENUM_TYPE_TRAITS(Neurotec::SmartCards, ApduClassSecureMessaging)

namespace Neurotec { namespace SmartCards
{

class ApduClass
{
	N_DECLARE_BASIC_CLASS(ApduClass)

public:
	static NType ApduClassSecureMessagingNativeTypeOf()
	{
		return NObject::GetObject<NType>(N_TYPE_OF(ApduClassSecureMessaging), true);
	}

	ApduClass(bool isLastOrTheOnly, ApduClassSecureMessaging secureMessaging, NInt channelNumber)
	{
		NCheck(ApduClassCreate(isLastOrTheOnly ? NTrue : NFalse, secureMessaging, channelNumber, &value));
	}

	bool IsValid() const
	{
		return ApduClassIsValid(value) != 0;
	}

	bool IsInterindustry() const
	{
		return ApduClassIsInterindustry(value) != 0;
	}

	bool IsProprietary() const
	{
		return ApduClassIsProprietary(value) != 0;
	}

	bool IsInterindustryFirst() const
	{
		return ApduClassIsInterindustryFirst(value) != 0;
	}

	bool IsInterindustryFurther() const
	{
		return ApduClassIsInterindustryFurther(value) != 0;
	}

	bool IsInterindustryReserved() const
	{
		return ApduClassIsInterindustryReserved(value) != 0;
	}

	bool IsLastOrTheOnly() const
	{
		return ApduClassIsLastOrTheOnly(value) != 0;
	}

	ApduClassSecureMessaging GetSecureMessaging() const
	{
		return ApduClassGetSecureMessaging(value);
	}

	NInt GetChannelNumber() const
	{
		return ApduClassGetChannelNumber(value);
	}

	NString ToString(const NStringWrapper & format = NString()) const
	{
		HNString hValue;
		NCheck(ApduClassToStringN(value, format.GetHandle(), &hValue));
		return NString(hValue, true);
	}
};

}}

#endif // !APDU_CLASS_HPP_INCLUDED
