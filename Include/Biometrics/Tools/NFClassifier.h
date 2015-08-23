#ifndef NF_CLASSIFIER_H_INCLUDED
#define NF_CLASSIFIER_H_INCLUDED

#include <Images/NGrayscaleImage.h>
#include <Biometrics/NFRecord.h>
#include <Biometrics/Tools/NFClassifierParams.h>

#ifdef N_CPP
extern "C"
{
#endif

N_DECLARE_OBJECT_TYPE(NFClassifier, NObject);

NResult N_API NfcCreate(HNFClassifier * phClassifier);

NResult N_API NfcClassify(HNFClassifier hClassifier, HNGrayscaleImage hImage, NFPatternClass * pPatternClass, NDouble * pConfidence);

#ifdef N_CPP
}
#endif

#endif // !NF_CLASSIFIER_H_INCLUDED

