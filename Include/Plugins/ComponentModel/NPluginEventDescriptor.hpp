#include <ComponentModel/NCustomEventDescriptor.hpp>
#include <Plugins/NPlugin.hpp>

#ifndef N_PLUGIN_EVENT_DESCRIPTOR_HPP_INCLUDED
#define N_PLUGIN_EVENT_DESCRIPTOR_HPP_INCLUDED

namespace Neurotec { namespace Plugins { namespace ComponentModel
{
using ::Neurotec::ComponentModel::HNCustomEventDescriptor_;
#include <Plugins/ComponentModel/NPluginEventDescriptor.h>
}}}

namespace Neurotec { namespace Plugins { namespace ComponentModel
{

class NPluginEventDescriptor : public ::Neurotec::ComponentModel::NCustomEventDescriptor
{
	N_DECLARE_OBJECT_CLASS(NPluginEventDescriptor, NCustomEventDescriptor)
};

}}}

#endif // !N_PLUGIN_EVENT_DESCRIPTOR_HPP_INCLUDED
