#include <Reflection/NObjectPartInfo.h>

#ifndef N_COLLECTION_INFO_H_INCLUDED
#define N_COLLECTION_INFO_H_INCLUDED

#ifdef N_CPP
extern "C"
{
#endif

NResult N_API NCollectionInfoGetItemType(HNCollectionInfo hCollectionInfo, HNType * phValue);
NResult N_API NCollectionInfoGetItemAttributes(HNCollectionInfo hCollectionInfo, NAttributes * pValue);
NResult N_API NCollectionInfoGetItemFormat(HNCollectionInfo hCollectionInfo, HNString * phValue);
NResult N_API NCollectionInfoGetItemMinValue(HNCollectionInfo hCollectionInfo, HNValue * phValue);
NResult N_API NCollectionInfoGetItemMaxValue(HNCollectionInfo hCollectionInfo, HNValue * phValue);
NResult N_API NCollectionInfoGetItemStdValueCount(HNCollectionInfo hCollectionInfo, NInt * pValue);
NResult N_API NCollectionInfoGetItemStdValue(HNCollectionInfo hCollectionInfo, NInt index, struct NNameValuePair_ * pValue);
NResult N_API NCollectionInfoGetItemStdValues(HNCollectionInfo hCollectionInfo, struct NNameValuePair_ * * parValues, NInt * pValueCount);

NResult N_API NCollectionInfoGetGetCountMethod(HNCollectionInfo hCollectionInfo, HNMethodInfo * phValue);
NResult N_API NCollectionInfoGetGetMethod(HNCollectionInfo hCollectionInfo, HNMethodInfo * phValue);
NResult N_API NCollectionInfoGetToArrayMethod(HNCollectionInfo hCollectionInfo, HNMethodInfo * phValue);
NResult N_API NCollectionInfoGetGetCapacityMethod(HNCollectionInfo hCollectionInfo, HNMethodInfo * phValue);
NResult N_API NCollectionInfoGetSetCapacityMethod(HNCollectionInfo hCollectionInfo, HNMethodInfo * phValue);
NResult N_API NCollectionInfoGetSetMethod(HNCollectionInfo hCollectionInfo, HNMethodInfo * phValue);
NResult N_API NCollectionInfoGetAddMethod(HNCollectionInfo hCollectionInfo, HNMethodInfo * phValue);
NResult N_API NCollectionInfoGetAddRangeMethod(HNCollectionInfo hCollectionInfo, HNMethodInfo * phValue);
NResult N_API NCollectionInfoGetInsertMethod(HNCollectionInfo hCollectionInfo, HNMethodInfo * phValue);
NResult N_API NCollectionInfoGetInsertRangeMethod(HNCollectionInfo hCollectionInfo, HNMethodInfo * phValue);
NResult N_API NCollectionInfoGetRemoveMethod(HNCollectionInfo hCollectionInfo, HNMethodInfo * phValue);
NResult N_API NCollectionInfoGetIndexOfMethod(HNCollectionInfo hCollectionInfo, HNMethodInfo * phValue);
NResult N_API NCollectionInfoGetRemoveAtMethod(HNCollectionInfo hCollectionInfo, HNMethodInfo * phValue);
NResult N_API NCollectionInfoGetRemoveRangeMethod(HNCollectionInfo hCollectionInfo, HNMethodInfo * phValue);
NResult N_API NCollectionInfoGetClearMethod(HNCollectionInfo hCollectionInfo, HNMethodInfo * phValue);
NResult N_API NCollectionInfoGetAddCollectionChangedMethod(HNCollectionInfo hCollectionInfo, HNMethodInfo * phValue);
NResult N_API NCollectionInfoGetAddCollectionChangedCallbackMethod(HNCollectionInfo hCollectionInfo, HNMethodInfo * phValue);
NResult N_API NCollectionInfoGetRemoveCollectionChangedMethod(HNCollectionInfo hCollectionInfo, HNMethodInfo * phValue);
NResult N_API NCollectionInfoGetRemoveCollectionChangedCallbackMethod(HNCollectionInfo hCollectionInfo, HNMethodInfo * phValue);

#ifdef N_CPP
}
#endif

#endif // !N_COLLECTION_INFO_H_INCLUDED
