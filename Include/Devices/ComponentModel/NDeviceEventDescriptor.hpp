#include <ComponentModel/NCustomEventDescriptor.hpp>
#include <Devices/NDevice.hpp>

#ifndef N_DEVICE_EVENT_DESCRIPTOR_HPP_INCLUDED
#define N_DEVICE_EVENT_DESCRIPTOR_HPP_INCLUDED

namespace Neurotec { namespace Devices { namespace ComponentModel
{
using ::Neurotec::ComponentModel::HNCustomEventDescriptor_;
#include <Devices/ComponentModel/NDeviceEventDescriptor.h>
}}}

namespace Neurotec { namespace Devices { namespace ComponentModel
{

class NDeviceEventDescriptor : public ::Neurotec::ComponentModel::NCustomEventDescriptor
{
	N_DECLARE_OBJECT_CLASS(NDeviceEventDescriptor, NCustomEventDescriptor)
};

}}}

#endif // !N_DEVICE_EVENT_DESCRIPTOR_HPP_INCLUDED
