#include <Reflection/NCollectionInfo.h>

#ifndef N_ARRAY_COLLECTION_INFO_H_INCLUDED
#define N_ARRAY_COLLECTION_INFO_H_INCLUDED

#ifdef N_CPP
extern "C"
{
#endif

NResult N_API NArrayCollectionInfoGetBaseCollection(HNArrayCollectionInfo hArrayCollectionInfo, HNCollectionInfo * phValue);
NResult N_API NArrayCollectionInfoGetItemType(HNArrayCollectionInfo hArrayCollectionInfo, HNType * phValue);
NResult N_API NArrayCollectionInfoGetItemAttributes(HNArrayCollectionInfo hArrayCollectionInfo, NAttributes * pValue);
NResult N_API NArrayCollectionInfoGetItemFormat(HNArrayCollectionInfo hArrayCollectionInfo, HNString * phValue);
NResult N_API NArrayCollectionInfoGetItemMinValue(HNArrayCollectionInfo hArrayCollectionInfo, HNValue * phValue);
NResult N_API NArrayCollectionInfoGetItemMaxValue(HNArrayCollectionInfo hArrayCollectionInfo, HNValue * phValue);
NResult N_API NArrayCollectionInfoGetItemStdValueCount(HNArrayCollectionInfo hArrayCollectionInfo, NInt * pValue);
NResult N_API NArrayCollectionInfoGetItemStdValue(HNArrayCollectionInfo hArrayCollectionInfo, NInt index, struct NNameValuePair_ * pValue);
NResult N_API NArrayCollectionInfoGetItemStdValues(HNArrayCollectionInfo hArrayCollectionInfo, struct NNameValuePair_ * * parValues, NInt * pValueCount);

NResult N_API NArrayCollectionInfoGetGetCountMethod(HNArrayCollectionInfo hArrayCollectionInfo, HNMethodInfo * phValue);
NResult N_API NArrayCollectionInfoGetGetMethod(HNArrayCollectionInfo hArrayCollectionInfo, HNMethodInfo * phValue);
NResult N_API NArrayCollectionInfoGetToArrayMethod(HNArrayCollectionInfo hArrayCollectionInfo, HNMethodInfo * phValue);
NResult N_API NArrayCollectionInfoGetSetMethod(HNArrayCollectionInfo hArrayCollectionInfo, HNMethodInfo * phValue);
NResult N_API NArrayCollectionInfoGetAddMethod(HNArrayCollectionInfo hArrayCollectionInfo, HNMethodInfo * phValue);
NResult N_API NArrayCollectionInfoGetAddRangeMethod(HNArrayCollectionInfo hArrayCollectionInfo, HNMethodInfo * phValue);
NResult N_API NArrayCollectionInfoGetInsertMethod(HNArrayCollectionInfo hArrayCollectionInfo, HNMethodInfo * phValue);
NResult N_API NArrayCollectionInfoGetInsertRangeMethod(HNArrayCollectionInfo hArrayCollectionInfo, HNMethodInfo * phValue);
NResult N_API NArrayCollectionInfoGetRemoveMethod(HNArrayCollectionInfo hArrayCollectionInfo, HNMethodInfo * phValue);
NResult N_API NArrayCollectionInfoGetIndexOfMethod(HNArrayCollectionInfo hArrayCollectionInfo, HNMethodInfo * phValue);
NResult N_API NArrayCollectionInfoGetRemoveAtMethod(HNArrayCollectionInfo hArrayCollectionInfo, HNMethodInfo * phValue);
NResult N_API NArrayCollectionInfoGetRemoveRangeMethod(HNArrayCollectionInfo hArrayCollectionInfo, HNMethodInfo * phValue);
NResult N_API NArrayCollectionInfoGetClearMethod(HNArrayCollectionInfo hArrayCollectionInfo, HNMethodInfo * phValue);

#ifdef N_CPP
}
#endif

#endif // !N_ARRAY_COLLECTION_INFO_H_INCLUDED
