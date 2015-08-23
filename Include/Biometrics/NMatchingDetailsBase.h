#ifndef N_MATCHING_DETAILS_BASE_H_INCLUDED
#define N_MATCHING_DETAILS_BASE_H_INCLUDED

#include <Core/NObject.h>
#include <Biometrics/NBiometricTypes.h>

#ifdef N_CPP
extern "C"
{
#endif

N_DECLARE_OBJECT_TYPE(NMatchingDetailsBase, NObject)

NResult N_API NMatchingDetailsBaseGetBiometricType(HNMatchingDetailsBase hMatchingDetails, NBiometricType * pValue);
NResult N_API NMatchingDetailsBaseGetScore(HNMatchingDetailsBase hMatchingDetails, NInt * pValue);

#ifdef N_CPP
}
#endif

#endif // !N_MATCHING_DETAILS_BASE_H_INCLUDED
