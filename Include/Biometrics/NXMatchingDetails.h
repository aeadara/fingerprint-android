#ifndef NX_MATCHING_DETAILS_H_INCLUDED
#define NX_MATCHING_DETAILS_H_INCLUDED

#include <Biometrics/NMatchingDetailsBase.h>

#ifdef N_CPP
extern "C"
{
#endif

N_DECLARE_OBJECT_TYPE(NXMatchingDetails, NMatchingDetailsBase)

NResult N_API NXMatchingDetailsGetMatchedIndex(HNXMatchingDetails hMatchingDetails, NInt * pValue);

#ifdef N_CPP
}
#endif

#endif // !NX_MATCHING_DETAILS_H_INCLUDED
