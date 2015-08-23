#ifndef N_MATCHING_RESULT_H_INCLUDED
#define N_MATCHING_RESULT_H_INCLUDED

#include <Core/NObject.h>
#include <Biometrics/NBiometric.h>
#include <Biometrics/NMatchingDetails.h>
#include <Biometrics/NBiometricConnection.h>

#ifdef N_CPP
extern "C"
{
#endif

N_DECLARE_OBJECT_TYPE(NMatchingResult, NObject)

NResult N_API NMatchingResultGetId(HNMatchingResult hMatchingResult, HNString * phValue);
NResult N_API NMatchingResultGetMatchingDetails(HNMatchingResult hMatchingResult, HNMatchingDetails * phValue);
NResult N_API NMatchingResultGetMatchingDetailsBuffer(HNMatchingResult hMatchingResult, HNBuffer * phValue);
NResult N_API NMatchingResultGetScore(HNMatchingResult hMatchingResult, NInt * pValue);
NResult N_API NMatchingResultGetSubject(HNMatchingResult hMatchingResult, HNSubject * phValue);
NResult N_API NMatchingResultGetConnection(HNMatchingResult hMatchingResult, HNBiometricConnection * phValue);

#ifdef N_CPP
}
#endif

#endif // !N_MATCHING_RESULT_H_INCLUDED
