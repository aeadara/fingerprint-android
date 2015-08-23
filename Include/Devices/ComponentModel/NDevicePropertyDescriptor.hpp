#include <ComponentModel/NCustomPropertyDescriptor.hpp>
#include <Devices/NDevice.hpp>

#ifndef N_DEVICE_PROPERTY_DESCRIPTOR_HPP_INCLUDED
#define N_DEVICE_PROPERTY_DESCRIPTOR_HPP_INCLUDED

namespace Neurotec { namespace Devices { namespace ComponentModel
{
using ::Neurotec::ComponentModel::HNCustomPropertyDescriptor_;
#include <Devices/ComponentModel/NDevicePropertyDescriptor.h>
}}}

namespace Neurotec { namespace Devices { namespace ComponentModel
{

class NDevicePropertyDescriptor : public ::Neurotec::ComponentModel::NCustomPropertyDescriptor
{
	N_DECLARE_OBJECT_CLASS(NDevicePropertyDescriptor, NCustomPropertyDescriptor)
};

}}}

#endif // !N_DEVICE_PROPERTY_DESCRIPTOR_HPP_INCLUDED
