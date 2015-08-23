#ifndef N_FACE_H_INCLUDED
#define N_FACE_H_INCLUDED

#include <Biometrics/NBiometric.h>
#include <Images/NImage.h>
#include <Biometrics/NLAttributes.h>

#ifdef N_CPP
extern "C"
{
#endif

N_DECLARE_OBJECT_TYPE(NFace, NBiometric)

NResult N_API NFaceCreate(HNFace * phFace);
NResult N_API NFaceFromImageAndAttributes(HNImage hImage, HNLAttributes hAttributes, HNFace * phFace);

NResult N_API NFaceGetImage(HNFace hFace, HNImage * phValue);
NResult N_API NFaceSetImage(HNFace hFace, HNImage hValue);

NResult N_API NFaceGetObjectCount(HNFace hFace, NInt * pValue);
NResult N_API NFaceGetObject(HNFace hFace, NInt index, HNLAttributes * phValue);
NResult N_API NFaceGetObjects(HNFace hFace, HNLAttributes * * parhValues, NInt * pValueCount);

NResult N_API NFaceAddObjectsCollectionChanged(HNFace hFace, HNCallback hCallback);
NResult N_API NFaceAddObjectsCollectionChangedCallback(HNFace hFace, N_COLLECTION_CHANGED_CALLBACK_ARG(HNLAttributes, pCallback), void * pParam);
NResult N_API NFaceRemoveObjectsCollectionChanged(HNFace hFace, HNCallback hCallback);
NResult N_API NFaceRemoveObjectsCollectionChangedCallback(HNFace hFace, N_COLLECTION_CHANGED_CALLBACK_ARG(HNLAttributes, pCallback), void * pParam);

#ifdef N_CPP
}
#endif

#endif // !N_FACE_H_INCLUDED
