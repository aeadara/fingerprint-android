#include <ComponentModel/NMemberDescriptor.h>
#include <ComponentModel/NParameterDescriptor.h>
#include <Core/NValue.h>

#ifndef N_METHOD_DESCRIPTOR_H_INCLUDED
#define N_METHOD_DESCRIPTOR_H_INCLUDED

#ifdef N_CPP
extern "C"
{
#endif

N_DECLARE_OBJECT_TYPE(NMethodDescriptor, NMemberDescriptor)

NResult N_API NMethodDescriptorGetParameterCount(HNMethodDescriptor hMethodDescriptor, NInt * pValue);
NResult N_API NMethodDescriptorGetParameter(HNMethodDescriptor hMethodDescriptor, NInt index, HNParameterDescriptor * phValue);
NResult N_API NMethodDescriptorGetParameters(HNMethodDescriptor hMethodDescriptor, HNParameterDescriptor * * parhValues, NInt * pValueCount);

NResult N_API NMethodDescriptorGetReturnParameter(HNMethodDescriptor hMethodDescriptor, HNParameterDescriptor * phValue);

NResult N_API NMethodDescriptorInvoke(HNMethodDescriptor hMethodDescriptor, HNObject hComponent, HNValue * arhParameters, NInt parameterCount, HNValue * phResult);
NResult N_API NMethodDescriptorInvokeWithPropertyBag(HNMethodDescriptor hMethodDescriptor, HNObject hComponent, HNPropertyBag hParameters, HNValue * phResult);
NResult N_API NMethodDescriptorInvokeWithStringN(HNMethodDescriptor hMethodDescriptor, HNObject hComponent, HNString hParameters, HNValue * phResult);
#ifndef N_NO_ANSI_FUNC
NResult N_API NMethodDescriptorInvokeWithStringA(HNMethodDescriptor hMethodDescriptor, HNObject hComponent, const NAChar * szParameters, HNValue * phResult);
#endif
#ifndef N_NO_UNICODE
NResult N_API NMethodDescriptorInvokeWithStringW(HNMethodDescriptor hMethodDescriptor, HNObject hComponent, const NWChar * szParameters, HNValue * phResult);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NMethodDescriptorInvokeWithString(HNMethodDescriptor hMethodDescriptor, HNObject hComponent, const NChar * szParameters, HNValue * phResult);
#endif
#define NMethodDescriptorInvokeWithString N_FUNC_AW(NMethodDescriptorInvokeWithString)

#ifdef N_CPP
}
#endif

#endif // !N_METHOD_DESCRIPTOR_H_INCLUDED
