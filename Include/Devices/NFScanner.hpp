#include <Devices/NBiometricDevice.hpp>

#ifndef N_F_SCANNER_HPP_INCLUDED
#define N_F_SCANNER_HPP_INCLUDED

#include <Geometry/NGeometry.hpp>
#include <Images/NImage.hpp>
#include <Biometrics/NFAttributes.hpp>
namespace Neurotec { namespace Devices
{
using ::Neurotec::Images::HNImage;
using ::Neurotec::Biometrics::NFImpressionType;
using ::Neurotec::Biometrics::NFPosition;
using ::Neurotec::Biometrics::HNFAttributes;
using ::Neurotec::Biometrics::NBiometricType;
using ::Neurotec::Biometrics::NBiometricStatus;
#include <Devices/NFScanner.h>
}}

namespace Neurotec { namespace Devices
{
class NFScanner : public NBiometricDevice
{
	N_DECLARE_OBJECT_CLASS(NFScanner, NBiometricDevice)

public:
	NInt GetSupportedImpressionTypes(NFImpressionType * arValues, NInt valuesLength) const
	{
		return NCheck(NFScannerGetSupportedImpressionTypes(GetHandle(), arValues, valuesLength));
	}

	NArrayWrapper<NFImpressionType> GetSupportedImpressionTypes() const
	{
		NInt count = GetSupportedImpressionTypes(NULL, 0);
		NArrayWrapper<NFImpressionType> values(count);
		count = GetSupportedImpressionTypes(values.GetPtr(), count);
		values.SetCount(count);
		return values;
	}

	NInt GetSupportedPositions(NFPosition * arValues, NInt valuesLength) const
	{
		return NCheck(NFScannerGetSupportedPositions(GetHandle(), arValues, valuesLength));
	}

	NArrayWrapper<NFPosition> GetSupportedPositions() const
	{
		NInt count = GetSupportedPositions(NULL, 0);
		NArrayWrapper<NFPosition> values(count);
		count = GetSupportedPositions(values.GetPtr(), count);
		values.SetCount(count);
		return values;
	}
};

}}

#endif // !N_F_SCANNER_HPP_INCLUDED
