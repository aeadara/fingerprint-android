#ifndef NFIQ_H_INCLUDED
#define NFIQ_H_INCLUDED

#include <Images/NGrayscaleImage.h>
#include <Biometrics/NBiometricTypes.h>

#ifdef N_CPP
extern "C"
{
#endif

N_DECLARE_STATIC_OBJECT_TYPE(Nfiq)

NResult N_API NfiqCompute(HNGrayscaleImage hImage, NfiqQuality * pQuality);

#ifdef N_CPP
}
#endif

#endif // !NFIQ_H_INCLUDED
