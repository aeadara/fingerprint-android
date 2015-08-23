#ifndef APDU_CLASS_H_INCLUDED
#define APDU_CLASS_H_INCLUDED

#include <Core/NTypes.h>

#ifdef N_CPP
extern "C"
{
#endif

typedef enum ApduClassSecureMessaging_
{
	acsmNone = 0,
	acsmProprietary = 1,
	acsmHeaderNotProcessed = 2,
	acsmHeaderAuthenticated = 3
} ApduClassSecureMessaging;

N_DECLARE_TYPE(ApduClassSecureMessaging)

typedef NByte ApduClass_;
#ifndef APDU_CLASS_HPP_INCLUDED
typedef ApduClass_ ApduClass;
#endif
N_DECLARE_TYPE(ApduClass)

NResult N_API ApduClassCreate(NBool isLastOrTheOnly, ApduClassSecureMessaging secureMessaging, NInt channelNumber, ApduClass_ * pCls);
NBool N_API ApduClassIsValid(ApduClass_ value);
NBool N_API ApduClassIsInterindustry(ApduClass_ value);
NBool N_API ApduClassIsProprietary(ApduClass_ value);
NBool N_API ApduClassIsInterindustryFirst(ApduClass_ value);
NBool N_API ApduClassIsInterindustryFurther(ApduClass_ value);
NBool N_API ApduClassIsInterindustryReserved(ApduClass_ value);
NBool N_API ApduClassIsLastOrTheOnly(ApduClass_ value);
ApduClassSecureMessaging N_API ApduClassGetSecureMessaging(ApduClass_ value);
NInt N_API ApduClassGetChannelNumber(ApduClass_ value);

NResult N_API ApduClassToStringN(ApduClass_ value, HNString hFormat, HNString * phValue);
NResult N_API ApduClassToStringA(ApduClass_ value, const NAChar * szFormat, HNString * phValue);
#ifndef N_NO_UNICODE
NResult N_API ApduClassToStringW(ApduClass_ value, const NWChar * szFormat, HNString * phValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API ApduClassToString(ApduClass value, const NChar * szFormat, HNString * phValue);
#endif
#define ApduClassToString N_FUNC_AW(ApduClassToString)

#ifdef N_CPP
}
#endif

#endif // !APDU_CLASS_H_INCLUDED
