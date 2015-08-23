#include <Reflection/NMemberInfo.h>
#include <Reflection/NMethodInfo.h>

#ifndef N_EVENT_INFO_H_INCLUDED
#define N_EVENT_INFO_H_INCLUDED

#ifdef N_CPP
extern "C"
{
#endif

NResult N_API NEventInfoGetEventType(HNEventInfo hEventInfo, HNType * phValue);
NResult N_API NEventInfoGetAddMethod(HNEventInfo hEventInfo, HNMethodInfo * phValue);
NResult N_API NEventInfoGetAddCallbackMethod(HNEventInfo hEventInfo, HNMethodInfo * phValue);
NResult N_API NEventInfoGetRemoveMethod(HNEventInfo hEventInfo, HNMethodInfo * phValue);
NResult N_API NEventInfoGetRemoveCallbackMethod(HNEventInfo hEventInfo, HNMethodInfo * phValue);
NResult N_API NEventInfoAddHandlerN(HNEventInfo hEventInfo, HNObject hObject, HNValue hCallback);
NResult N_API NEventInfoAddHandler(HNEventInfo hEventInfo, HNObject hObject, HNType hCallbackType, HNCallback hCallback);
NResult N_API NEventInfoAddHandlerP(HNEventInfo hEventInfo, HNObject hObject, NTypeOfProc pCallbackTypeOf, HNCallback hCallback);
NResult N_API NEventInfoRemoveHandlerN(HNEventInfo hEventInfo, HNObject hObject, HNValue hCallback);
NResult N_API NEventInfoRemoveHandler(HNEventInfo hEventInfo, HNObject hObject, HNType hCallbackType, HNCallback hCallback);
NResult N_API NEventInfoRemoveHandlerP(HNEventInfo hEventInfo, HNObject hObject, NTypeOfProc pCallbackTypeOf, HNCallback hCallback);

#ifdef N_CPP
}
#endif

#endif // !N_EVENT_INFO_H_INCLUDED
