#ifndef N_MATCHER_H_INCLUDED
#define N_MATCHER_H_INCLUDED

#include <Biometrics/NMatchingDetails.h>
#include <Biometrics/NMatcherParams.h>
#include <Biometrics/NTemplate.h>
#include <Biometrics/NBiometricEngine.h>

#ifdef N_CPP
extern "C"
{
#endif

N_DECLARE_OBJECT_TYPE(NMatcher, NObject)

NResult N_API NMCreate(HNMatcher * phMatcher);

NResult N_API NMVerifyExN(HNMatcher hMatcher, HNBuffer hTemplate1, HNBuffer hTemplate2, HNMatchingDetails * phMatchingDetails, NInt * pScore);
NResult N_API NMVerifyEx(HNMatcher hMatcher, const void * pTemplate1, NSizeType template1Size, const void * pTemplate2, NSizeType template2Size, HNMatchingDetails * phMatchingDetails, NInt * pScore);
NResult N_API NMIdentifyStartExN(HNMatcher hMatcher, HNBuffer hTemplate, HNMatchingDetails * phMatchingDetails);
NResult N_API NMIdentifyStartEx(HNMatcher hMatcher, const void * pTemplate, NSizeType templateSize, HNMatchingDetails * phMatchingDetails);
NResult N_API NMIdentifyNextExN(HNMatcher hMatcher, HNBuffer hTemplate, HNMatchingDetails hMatchingDetails, NInt * pScore);
NResult N_API NMIdentifyNextEx(HNMatcher hMatcher, const void * pTemplate, NSizeType templateSize, HNMatchingDetails hMatchingDetails, NInt * pScore);
NResult N_API NMIdentifyEnd(HNMatcher hMatcher);

NResult N_API NMPrepareTemplate(HNMatcher hMatcher, HNTemplate hTemplate);

#ifdef N_CPP
}
#endif

#endif // !N_MATCHER_H_INCLUDED
