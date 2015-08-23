#include <Devices/NBiometricDevice.hpp>

#ifndef N_IRIS_SCANNER_HPP_INCLUDED
#define N_IRIS_SCANNER_HPP_INCLUDED

#include <Images/NImage.hpp>
#include <Biometrics/NEAttributes.hpp>
namespace Neurotec { namespace Devices
{
using ::Neurotec::Images::HNImage;
using ::Neurotec::Biometrics::NEPosition;
using ::Neurotec::Biometrics::HNEAttributes;
using ::Neurotec::Biometrics::NBiometricType;
using ::Neurotec::Biometrics::NBiometricStatus;
#include <Devices/NIrisScanner.h>
}}

namespace Neurotec { namespace Devices
{

class NIrisScanner : public NBiometricDevice
{
	N_DECLARE_OBJECT_CLASS(NIrisScanner, NBiometricDevice)

public:
	NInt GetSupportedPositions(NEPosition * arValues, NInt valuesLength) const
	{
		return NCheck(NIrisScannerGetSupportedPositions(GetHandle(), arValues, valuesLength));
	}

	NArrayWrapper<NEPosition> GetSupportedPositions() const
	{
		NInt count = GetSupportedPositions(NULL, 0);
		NArrayWrapper<NEPosition> values(count);
		count = GetSupportedPositions(values.GetPtr(), count);
		values.SetCount(count);
		return values;
	}
};

}}

#endif // !N_IRIS_SCANNER_HPP_INCLUDED
