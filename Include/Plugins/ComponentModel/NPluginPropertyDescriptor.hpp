#include <ComponentModel/NCustomPropertyDescriptor.hpp>
#include <Plugins/NPlugin.hpp>

#ifndef N_PLUGIN_PROPERTY_DESCRIPTOR_HPP_INCLUDED
#define N_PLUGIN_PROPERTY_DESCRIPTOR_HPP_INCLUDED

namespace Neurotec { namespace Plugins { namespace ComponentModel
{
using ::Neurotec::ComponentModel::HNCustomPropertyDescriptor_;
#include <Plugins/ComponentModel/NPluginPropertyDescriptor.h>
}}}

namespace Neurotec { namespace Plugins { namespace ComponentModel
{

class NPluginPropertyDescriptor : public ::Neurotec::ComponentModel::NCustomPropertyDescriptor
{
	N_DECLARE_OBJECT_CLASS(NPluginPropertyDescriptor, NCustomPropertyDescriptor)
};

}}}

#endif // !N_PLUGIN_PROPERTY_DESCRIPTOR_HPP_INCLUDED
