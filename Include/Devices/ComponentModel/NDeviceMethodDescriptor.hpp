#include <ComponentModel/NCustomMethodDescriptor.hpp>
#include <ComponentModel/NCustomParameterDescriptor.hpp>
#include <Devices/NDevice.hpp>

#ifndef N_DEVICE_METHOD_DESCRIPTOR_HPP_INCLUDED
#define N_DEVICE_METHOD_DESCRIPTOR_HPP_INCLUDED

namespace Neurotec { namespace Devices { namespace ComponentModel
{
using ::Neurotec::ComponentModel::HNCustomParameterDescriptor;
using ::Neurotec::ComponentModel::HNCustomMethodDescriptor_;
#include <Devices/ComponentModel/NDeviceMethodDescriptor.h>
}}}

namespace Neurotec { namespace Devices { namespace ComponentModel
{

class NDeviceMethodDescriptor : public ::Neurotec::ComponentModel::NCustomMethodDescriptor
{
	N_DECLARE_OBJECT_CLASS(NDeviceMethodDescriptor, NCustomMethodDescriptor)
};

}}}

#endif // !N_DEVICE_METHOD_DESCRIPTOR_HPP_INCLUDED
