#ifndef N_IRIS_H_INCLUDED
#define N_IRIS_H_INCLUDED

#include <Biometrics/NBiometric.h>
#include <Images/NImage.h>
#include <Biometrics/NEAttributes.h>

#ifdef N_CPP
extern "C"
{
#endif

N_DECLARE_OBJECT_TYPE(NIris, NBiometric)

NResult N_API NIrisCreate(HNIris * phIris);
NResult N_API NIrisFromImageAndTemplate(HNImage hImage, HNERecord hTemplate, HNIris * phIris);

NResult N_API NIrisGetImage(HNIris hIris, HNImage * phValue);
NResult N_API NIrisSetImage(HNIris hIris, HNImage hValue);
NResult N_API NIrisGetPosition(HNIris hIris, NEPosition * pValue);
NResult N_API NIrisSetPosition(HNIris hIris, NEPosition value);
NResult N_API NIrisGetImageType(HNIris hIris, NEImageType * pValue);
NResult N_API NIrisSetImageType(HNIris hIris, NEImageType value);

NResult N_API NIrisGetObjectCount(HNIris hIris, NInt * pValue);
NResult N_API NIrisGetObject(HNIris hIris, NInt index, HNEAttributes * phValue);
NResult N_API NIrisGetObjects(HNIris hIris, HNEAttributes * * parhValues, NInt * pValueCount);

NResult N_API NIrisAddObjectsCollectionChanged(HNIris hIris, HNCallback hCallback);
NResult N_API NIrisAddObjectsCollectionChangedCallback(HNIris hIris, N_COLLECTION_CHANGED_CALLBACK_ARG(HNEAttributes, pCallback), void * pParam);
NResult N_API NIrisRemoveObjectsCollectionChanged(HNIris hIris, HNCallback hCallback);
NResult N_API NIrisRemoveObjectsCollectionChangedCallback(HNIris hIris, N_COLLECTION_CHANGED_CALLBACK_ARG(HNEAttributes, pCallback), void * pParam);

#ifdef N_CPP
}
#endif

#endif // !N_IRIS_H_INCLUDED
