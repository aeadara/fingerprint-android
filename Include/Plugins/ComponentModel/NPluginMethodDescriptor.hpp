#include <ComponentModel/NCustomMethodDescriptor.hpp>
#include <ComponentModel/NCustomParameterDescriptor.hpp>
#include <Plugins/NPlugin.hpp>

#ifndef N_PLUGIN_METHOD_DESCRIPTOR_HPP_INCLUDED
#define N_PLUGIN_METHOD_DESCRIPTOR_HPP_INCLUDED

namespace Neurotec { namespace Plugins { namespace ComponentModel
{
using ::Neurotec::ComponentModel::HNCustomParameterDescriptor;
using ::Neurotec::ComponentModel::HNCustomMethodDescriptor_;
#include <Plugins/ComponentModel/NPluginMethodDescriptor.h>
}}}

namespace Neurotec { namespace Plugins { namespace ComponentModel
{

class NPluginMethodDescriptor : public ::Neurotec::ComponentModel::NCustomMethodDescriptor
{
	N_DECLARE_OBJECT_CLASS(NPluginMethodDescriptor, NCustomMethodDescriptor)
};

}}}

#endif // !N_PLUGIN_METHOD_DESCRIPTOR_HPP_INCLUDED
