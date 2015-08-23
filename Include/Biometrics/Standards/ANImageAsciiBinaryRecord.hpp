#ifndef AN_IMAGE_ASCII_BINARY_RECORD_HPP_INCLUDED
#define AN_IMAGE_ASCII_BINARY_RECORD_HPP_INCLUDED

#include <Biometrics/Standards/ANAsciiBinaryRecord.hpp>
#include <Biometrics/Standards/ANImage.hpp>
#include <Biometrics/Standards/BdifTypes.hpp>
namespace Neurotec { namespace Biometrics { namespace Standards
{
#include <Biometrics/Standards/ANImageAsciiBinaryRecord.h>
}}}

N_DEFINE_ENUM_TYPE_TRAITS(Neurotec::Biometrics::Standards, ANDeviceMonitoringMode)

namespace Neurotec { namespace Biometrics { namespace Standards
{

#undef AN_IMAGE_ASCII_BINARY_RECORD_FIELD_HLL
#undef AN_IMAGE_ASCII_BINARY_RECORD_FIELD_VLL
#undef AN_IMAGE_ASCII_BINARY_RECORD_FIELD_SLC
#undef AN_IMAGE_ASCII_BINARY_RECORD_FIELD_HPS
#undef AN_IMAGE_ASCII_BINARY_RECORD_FIELD_VPS
#undef AN_IMAGE_ASCII_BINARY_RECORD_FIELD_CGA
#undef AN_IMAGE_ASCII_BINARY_RECORD_FIELD_BPX
#undef AN_IMAGE_ASCII_BINARY_RECORD_FIELD_CSP
#undef AN_IMAGE_ASCII_BINARY_RECORD_FIELD_SHPS
#undef AN_IMAGE_ASCII_BINARY_RECORD_FIELD_SVPS
#undef AN_IMAGE_ASCII_BINARY_RECORD_FIELD_COM
#undef AN_IMAGE_ASCII_BINARY_RECORD_FIELD_IQM
#undef AN_IMAGE_ASCII_BINARY_RECORD_FIELD_DMM

#undef AN_IMAGE_ASCII_BINARY_RECORD_MAX_LINE_LENGTH
#undef AN_IMAGE_ASCII_BINARY_RECORD_MAX_PIXEL_SCALE

#undef AN_IMAGE_ASCII_BINARY_RECORD_MIN_SCAN_PIXEL_SCALE_PPCM
#undef AN_IMAGE_ASCII_BINARY_RECORD_MIN_SCAN_PIXEL_SCALE_PPI
#undef AN_IMAGE_ASCII_BINARY_RECORD_MIN_LATENT_SCAN_PIXEL_SCALE_PPCM
#undef AN_IMAGE_ASCII_BINARY_RECORD_MIN_LATENT_SCAN_PIXEL_SCALE_PPI
#undef AN_IMAGE_ASCII_BINARY_RECORD_MIN_LATENT_SCAN_PIXEL_SCALE_V4_PPCM
#undef AN_IMAGE_ASCII_BINARY_RECORD_MIN_LATENT_SCAN_PIXEL_SCALE_V4_PPI

#undef AN_IMAGE_ASCII_BINARY_RECORD_MIN_PIXEL_SCALE_PPCM
#undef AN_IMAGE_ASCII_BINARY_RECORD_MIN_PIXEL_SCALE_PPI
#undef AN_IMAGE_ASCII_BINARY_RECORD_MIN_LATENT_PIXEL_SCALE_PPCM
#undef AN_IMAGE_ASCII_BINARY_RECORD_MIN_LATENT_PIXEL_SCALE_PPI
#undef AN_IMAGE_ASCII_BINARY_RECORD_MIN_LATENT_PIXEL_SCALE_V4_PPCM
#undef AN_IMAGE_ASCII_BINARY_RECORD_MIN_LATENT_PIXEL_SCALE_V4_PPI

#undef AN_IMAGE_ASCII_BINARY_RECORD_MIN_VENDOR_COMPRESSION_ALGORITHM_LENGTH
#undef AN_IMAGE_ASCII_BINARY_RECORD_MAX_VENDOR_COMPRESSION_ALGORITHM_LENGTH
#undef AN_IMAGE_ASCII_BINARY_RECORD_MAX_COMMENT_LENGTH

const NInt AN_IMAGE_ASCII_BINARY_RECORD_FIELD_HLL = 6;
const NInt AN_IMAGE_ASCII_BINARY_RECORD_FIELD_VLL = 7;
const NInt AN_IMAGE_ASCII_BINARY_RECORD_FIELD_SLC = 8;
const NInt AN_IMAGE_ASCII_BINARY_RECORD_FIELD_HPS = 9;
const NInt AN_IMAGE_ASCII_BINARY_RECORD_FIELD_VPS = 10;
const NInt AN_IMAGE_ASCII_BINARY_RECORD_FIELD_CGA = 11;
const NInt AN_IMAGE_ASCII_BINARY_RECORD_FIELD_BPX = 12;
const NInt AN_IMAGE_ASCII_BINARY_RECORD_FIELD_CSP = 13;
const NInt AN_IMAGE_ASCII_BINARY_RECORD_FIELD_SHPS = 16;
const NInt AN_IMAGE_ASCII_BINARY_RECORD_FIELD_SVPS = 17;
const NInt AN_IMAGE_ASCII_BINARY_RECORD_FIELD_COM = 20;
const NInt AN_IMAGE_ASCII_BINARY_RECORD_FIELD_IQM = 24;
const NInt AN_IMAGE_ASCII_BINARY_RECORD_FIELD_DMM = 30;

const NUShort AN_IMAGE_ASCII_BINARY_RECORD_MAX_LINE_LENGTH = 9999;
const NUShort AN_IMAGE_ASCII_BINARY_RECORD_MAX_PIXEL_SCALE = 9999;

const NUShort AN_IMAGE_ASCII_BINARY_RECORD_MIN_SCAN_PIXEL_SCALE_PPCM = 195;
const NUShort AN_IMAGE_ASCII_BINARY_RECORD_MIN_SCAN_PIXEL_SCALE_PPI = 495;
const NUShort AN_IMAGE_ASCII_BINARY_RECORD_MIN_LATENT_SCAN_PIXEL_SCALE_PPCM = 195;
const NUShort AN_IMAGE_ASCII_BINARY_RECORD_MIN_LATENT_SCAN_PIXEL_SCALE_PPI = 495;
const NUShort AN_IMAGE_ASCII_BINARY_RECORD_MIN_LATENT_SCAN_PIXEL_SCALE_V4_PPCM = 390;
const NUShort AN_IMAGE_ASCII_BINARY_RECORD_MIN_LATENT_SCAN_PIXEL_SCALE_V4_PPI = 990;

const NUShort AN_IMAGE_ASCII_BINARY_RECORD_MIN_PIXEL_SCALE_PPCM = 195;
const NUShort AN_IMAGE_ASCII_BINARY_RECORD_MIN_PIXEL_SCALE_PPI = 495;
const NUShort AN_IMAGE_ASCII_BINARY_RECORD_MIN_LATENT_PIXEL_SCALE_PPCM = 195;
const NUShort AN_IMAGE_ASCII_BINARY_RECORD_MIN_LATENT_PIXEL_SCALE_PPI = 495;
const NUShort AN_IMAGE_ASCII_BINARY_RECORD_MIN_LATENT_PIXEL_SCALE_V4_PPCM = 390;
const NUShort AN_IMAGE_ASCII_BINARY_RECORD_MIN_LATENT_PIXEL_SCALE_V4_PPI = 990;

const NInt AN_IMAGE_ASCII_BINARY_RECORD_MIN_VENDOR_COMPRESSION_ALGORITHM_LENGTH = 3;
const NInt AN_IMAGE_ASCII_BINARY_RECORD_MAX_VENDOR_COMPRESSION_ALGORITHM_LENGTH = 6;
const NInt AN_IMAGE_ASCII_BINARY_RECORD_MAX_COMMENT_LENGTH = 127;

class ANImageAsciiBinaryRecord : public ANAsciiBinaryRecord
{
	N_DECLARE_OBJECT_CLASS(ANImageAsciiBinaryRecord, ANAsciiBinaryRecord)

public:
	static NType ANDeviceMonitoringModeNativeTypeOf()
	{
		return NObject::GetObject<NType>(N_TYPE_OF(ANDeviceMonitoringMode), true);
	}

	::Neurotec::Images::NImage ToNImage(NUInt flags = 0) const
	{
		HNImage hImage;
		NCheck(ANImageAsciiBinaryRecordToNImage(GetHandle(), flags, &hImage));
		return FromHandle< ::Neurotec::Images::NImage>(hImage);
	}

	NUShort GetHorzLineLength() const
	{
		NUShort value;
		NCheck(ANImageAsciiBinaryRecordGetHorzLineLength(GetHandle(), &value));
		return value;
	}

	NUShort GetVertLineLength() const
	{
		NUShort value;
		NCheck(ANImageAsciiBinaryRecordGetVertLineLength(GetHandle(), &value));
		return value;
	}

	BdifScaleUnits GetScaleUnits() const
	{
		BdifScaleUnits value;
		NCheck(ANImageAsciiBinaryRecordGetScaleUnits(GetHandle(), &value));
		return value;
	}

	NUShort GetHorzPixelScale() const
	{
		NUShort value;
		NCheck(ANImageAsciiBinaryRecordGetHorzPixelScale(GetHandle(), &value));
		return value;
	}

	NUShort GetVertPixelScale() const
	{
		NUShort value;
		NCheck(ANImageAsciiBinaryRecordGetVertPixelScale(GetHandle(), &value));
		return value;
	}

	ANImageCompressionAlgorithm GetCompressionAlgorithm() const
	{
		ANImageCompressionAlgorithm value;
		NCheck(ANImageAsciiBinaryRecordGetCompressionAlgorithm(GetHandle(), &value));
		return value;
	}

	NString GetVendorCompressionAlgorithm() const
	{
		return GetString(ANImageAsciiBinaryRecordGetVendorCompressionAlgorithmN);
	}

	NByte GetBitsPerPixel() const
	{
		NByte value;
		NCheck(ANImageAsciiBinaryRecordGetBitsPerPixel(GetHandle(), &value));
		return value;
	}

	ANImageColorSpace GetColorSpace() const
	{
		ANImageColorSpace value;
		NCheck(ANImageAsciiBinaryRecordGetColorSpace(GetHandle(), &value));
		return value;
	}

	NInt GetScanHorzPixelScale() const
	{
		NInt value;
		NCheck(ANImageAsciiBinaryRecordGetScanHorzPixelScale(GetHandle(), &value));
		return value;
	}

	void SetScanHorzPixelScale(NInt value)
	{
		NCheck(ANImageAsciiBinaryRecordSetScanHorzPixelScale(GetHandle(), value));
	}

	NInt GetScanVertPixelScale() const
	{
		NInt value;
		NCheck(ANImageAsciiBinaryRecordGetScanVertPixelScale(GetHandle(), &value));
		return value;
	}

	void SetScanVertPixelScale(NInt value)
	{
		NCheck(ANImageAsciiBinaryRecordSetScanVertPixelScale(GetHandle(), value));
	}

	NString GetComment() const
	{
		return GetString(ANImageAsciiBinaryRecordGetCommentN);
	}

	void SetComment(const NStringWrapper & value)
	{
		return SetString(ANImageAsciiBinaryRecordSetCommentN, value);
	}

	ANDeviceMonitoringMode GetDeviceMonitoringMode() const
	{
		ANDeviceMonitoringMode value;
		NCheck(ANImageAsciiBinaryRecordGetDeviceMonitoringMode(GetHandle(), &value));
		return value;
	}

	void SetDeviceMonitoringMode(ANDeviceMonitoringMode value)
	{
		NCheck(ANImageAsciiBinaryRecordSetDeviceMonitoringMode(GetHandle(), value));
	}
};

}}}

#endif // !AN_IMAGE_ASCII_BINARY_RECORD_HPP_INCLUDED
