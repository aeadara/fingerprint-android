#include <Reflection/NObjectPartInfo.h>

#ifndef N_DICTIONARY_INFO_H_INCLUDED
#define N_DICTIONARY_INFO_H_INCLUDED

#ifdef N_CPP
extern "C"
{
#endif

NResult N_API NDictionaryInfoGetItemType(HNDictionaryInfo hDictionaryInfo, HNType * phValue);
NResult N_API NDictionaryInfoGetItemAttributes(HNDictionaryInfo hDictionaryInfo, NAttributes * pValue);

NResult N_API NDictionaryInfoGetKeyType(HNDictionaryInfo hDictionaryInfo, HNType * phValue);
NResult N_API NDictionaryInfoGetKeyAttributes(HNDictionaryInfo hDictionaryInfo, NAttributes * pValue);
NResult N_API NDictionaryInfoGetKeyFormat(HNDictionaryInfo hDictionaryInfo, HNString * phValue);
NResult N_API NDictionaryInfoGetKeyMinValue(HNDictionaryInfo hDictionaryInfo, HNValue * phValue);
NResult N_API NDictionaryInfoGetKeyMaxValue(HNDictionaryInfo hDictionaryInfo, HNValue * phValue);
NResult N_API NDictionaryInfoGetKeyStdValueCount(HNDictionaryInfo hDictionaryInfo, NInt * pValue);
NResult N_API NDictionaryInfoGetKeyStdValue(HNDictionaryInfo hDictionaryInfo, NInt index, struct NNameValuePair_ * pValue);
NResult N_API NDictionaryInfoGetKeyStdValues(HNDictionaryInfo hDictionaryInfo, struct NNameValuePair_ * * parValues, NInt * pValueCount);

NResult N_API NDictionaryInfoGetValueType(HNDictionaryInfo hDictionaryInfo, HNType * phValue);
NResult N_API NDictionaryInfoGetValueAttributes(HNDictionaryInfo hDictionaryInfo, NAttributes * pValue);
NResult N_API NDictionaryInfoGetValueFormat(HNDictionaryInfo hDictionaryInfo, HNString * phValue);
NResult N_API NDictionaryInfoGetValueMinValue(HNDictionaryInfo hDictionaryInfo, HNValue * phValue);
NResult N_API NDictionaryInfoGetValueMaxValue(HNDictionaryInfo hDictionaryInfo, HNValue * phValue);
NResult N_API NDictionaryInfoGetValueStdValueCount(HNDictionaryInfo hDictionaryInfo, NInt * pValue);
NResult N_API NDictionaryInfoGetValueStdValue(HNDictionaryInfo hDictionaryInfo, NInt index, struct NNameValuePair_ * pValue);
NResult N_API NDictionaryInfoGetValueStdValues(HNDictionaryInfo hDictionaryInfo, struct NNameValuePair_ * * parValues, NInt * pValueCount);

NResult N_API NDictionaryInfoGetGetCountMethod(HNDictionaryInfo hDictionaryInfo, HNMethodInfo * phValue);
NResult N_API NDictionaryInfoGetGetAtMethod(HNDictionaryInfo hDictionaryInfo, HNMethodInfo * phValue);
NResult N_API NDictionaryInfoGetToArrayMethod(HNDictionaryInfo hDictionaryInfo, HNMethodInfo * phValue);
NResult N_API NDictionaryInfoGetGetKeyMethod(HNDictionaryInfo hDictionaryInfo, HNMethodInfo * phValue);
NResult N_API NDictionaryInfoGetToKeyArrayMethod(HNDictionaryInfo hDictionaryInfo, HNMethodInfo * phValue);
NResult N_API NDictionaryInfoGetGetValueMethod(HNDictionaryInfo hDictionaryInfo, HNMethodInfo * phValue);
NResult N_API NDictionaryInfoGetToValueArrayMethod(HNDictionaryInfo hDictionaryInfo, HNMethodInfo * phValue);
NResult N_API NDictionaryInfoGetAddPairMethod(HNDictionaryInfo hDictionaryInfo, HNMethodInfo * phValue);
NResult N_API NDictionaryInfoGetRemoveAtMethod(HNDictionaryInfo hDictionaryInfo, HNMethodInfo * phValue);
NResult N_API NDictionaryInfoGetClearMethod(HNDictionaryInfo hDictionaryInfo, HNMethodInfo * phValue);
NResult N_API NDictionaryInfoGetContainsMethod(HNDictionaryInfo hDictionaryInfo, HNMethodInfo * phValue);
NResult N_API NDictionaryInfoGetGetMethod(HNDictionaryInfo hDictionaryInfo, HNMethodInfo * phValue);
NResult N_API NDictionaryInfoGetTryGetMethod(HNDictionaryInfo hDictionaryInfo, HNMethodInfo * phValue);
NResult N_API NDictionaryInfoGetAddMethod(HNDictionaryInfo hDictionaryInfo, HNMethodInfo * phValue);
NResult N_API NDictionaryInfoGetSetMethod(HNDictionaryInfo hDictionaryInfo, HNMethodInfo * phValue);
NResult N_API NDictionaryInfoGetRemoveMethod(HNDictionaryInfo hDictionaryInfo, HNMethodInfo * phValue);
NResult N_API NDictionaryInfoGetAddCollectionChangedMethod(HNDictionaryInfo hDictionaryInfo, HNMethodInfo * phValue);
NResult N_API NDictionaryInfoGetAddCollectionChangedCallbackMethod(HNDictionaryInfo hDictionaryInfo, HNMethodInfo * phValue);
NResult N_API NDictionaryInfoGetRemoveCollectionChangedMethod(HNDictionaryInfo hDictionaryInfo, HNMethodInfo * phValue);
NResult N_API NDictionaryInfoGetRemoveCollectionChangedCallbackMethod(HNDictionaryInfo hDictionaryInfo, HNMethodInfo * phValue);

#ifdef N_CPP
}
#endif

#endif // !N_DICTIONARY_INFO_H_INCLUDED
