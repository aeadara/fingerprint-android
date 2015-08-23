#include <ComponentModel/NCustomMethodDescriptor.h>
#include <ComponentModel/NCustomParameterDescriptor.h>
#include <Plugins/NPlugin.h>

#ifndef N_PLUGIN_METHOD_DESCRIPTOR_H_INCLUDED
#define N_PLUGIN_METHOD_DESCRIPTOR_H_INCLUDED

#ifdef N_CPP
extern "C"
{
#endif

N_DECLARE_OBJECT_TYPE(NPluginMethodDescriptor, NCustomMethodDescriptor)

typedef NResult (N_CALLBACK NPluginMethodDescriptorInvokeProc)(HNPluginMethodDescriptor hMethodDescriptor, HNValue * arhParameters, NInt parameterCount, HNValue * phResult, void * pParam);

NResult N_API NPluginMethodDescriptorCreate(HNString hName, NAttributes attributes, HNCustomParameterDescriptor hReturnParameter, HNCustomParameterDescriptor * arhParameters, NInt parameterCount,
	HNValue hData, HNCallback hInvoke, HNPluginMethodDescriptor * phMethodDescriptor);

#ifdef N_CPP
}
#endif

#endif // !N_PLUGIN_METHOD_DESCRIPTOR_H_INCLUDED
