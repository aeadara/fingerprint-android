#ifndef AN_TYPE_17_RECORD_HPP_INCLUDED
#define AN_TYPE_17_RECORD_HPP_INCLUDED

#include <Biometrics/Standards/ANImageAsciiBinaryRecord.hpp>
namespace Neurotec { namespace Biometrics { namespace Standards
{
#include <Biometrics/Standards/ANType17Record.h>
}}}

N_DEFINE_ENUM_TYPE_TRAITS(Neurotec::Biometrics::Standards, ANIrisAcquisitionLightingSpectrum)

namespace Neurotec { namespace Biometrics { namespace Standards
{

#undef AN_TYPE_17_RECORD_FIELD_LEN
#undef AN_TYPE_17_RECORD_FIELD_IDC

#undef AN_TYPE_17_RECORD_FIELD_FID

#undef AN_TYPE_17_RECORD_FIELD_SRC
#undef AN_TYPE_17_RECORD_FIELD_ICD
#undef AN_TYPE_17_RECORD_FIELD_HLL
#undef AN_TYPE_17_RECORD_FIELD_VLL
#undef AN_TYPE_17_RECORD_FIELD_SLC
#undef AN_TYPE_17_RECORD_FIELD_HPS
#undef AN_TYPE_17_RECORD_FIELD_VPS
#undef AN_TYPE_17_RECORD_FIELD_CGA
#undef AN_TYPE_17_RECORD_FIELD_BPX
#undef AN_TYPE_17_RECORD_FIELD_CSP

#undef AN_TYPE_17_RECORD_FIELD_RAE
#undef AN_TYPE_17_RECORD_FIELD_RAU
#undef AN_TYPE_17_RECORD_FIELD_IPC
#undef AN_TYPE_17_RECORD_FIELD_DUI
#undef AN_TYPE_17_RECORD_FIELD_GUI
#undef AN_TYPE_17_RECORD_FIELD_MMS
#undef AN_TYPE_17_RECORD_FIELD_ECL
#undef AN_TYPE_17_RECORD_FIELD_COM
#undef AN_TYPE_17_RECORD_FIELD_SHPS
#undef AN_TYPE_17_RECORD_FIELD_SVPS

#undef AN_TYPE_17_RECORD_FIELD_IQS

#undef AN_TYPE_17_RECORD_FIELD_ALS
#undef AN_TYPE_17_RECORD_FIELD_IRD

#undef AN_TYPE_17_RECORD_FIELD_DMM

#undef AN_TYPE_17_RECORD_FIELD_UDF_FROM
#undef AN_TYPE_17_RECORD_FIELD_UDF_TO

#undef AN_TYPE_17_RECORD_FIELD_DATA

#undef AN_TYPE_17_RECORD_MAX_IRIS_DIAMETER

#undef AN_TYPE_17_RECORD_MAX_MAKE_LENGTH
#undef AN_TYPE_17_RECORD_MAX_MODEL_LENGTH
#undef AN_TYPE_17_RECORD_MAX_SERIAL_NUMBER_LENGTH

const NInt AN_TYPE_17_RECORD_FIELD_LEN = AN_RECORD_FIELD_LEN;
const NInt AN_TYPE_17_RECORD_FIELD_IDC = AN_RECORD_FIELD_IDC;

const NInt AN_TYPE_17_RECORD_FIELD_FID = 3;

const NInt AN_TYPE_17_RECORD_FIELD_SRC = AN_ASCII_BINARY_RECORD_FIELD_SRC;
const NInt AN_TYPE_17_RECORD_FIELD_ICD = AN_ASCII_BINARY_RECORD_FIELD_DAT;
const NInt AN_TYPE_17_RECORD_FIELD_HLL = AN_IMAGE_ASCII_BINARY_RECORD_FIELD_HLL;
const NInt AN_TYPE_17_RECORD_FIELD_VLL = AN_IMAGE_ASCII_BINARY_RECORD_FIELD_VLL;
const NInt AN_TYPE_17_RECORD_FIELD_SLC = AN_IMAGE_ASCII_BINARY_RECORD_FIELD_SLC;
const NInt AN_TYPE_17_RECORD_FIELD_HPS = AN_IMAGE_ASCII_BINARY_RECORD_FIELD_HPS;
const NInt AN_TYPE_17_RECORD_FIELD_VPS = AN_IMAGE_ASCII_BINARY_RECORD_FIELD_VPS;
const NInt AN_TYPE_17_RECORD_FIELD_CGA = AN_IMAGE_ASCII_BINARY_RECORD_FIELD_CGA;
const NInt AN_TYPE_17_RECORD_FIELD_BPX = AN_IMAGE_ASCII_BINARY_RECORD_FIELD_BPX;
const NInt AN_TYPE_17_RECORD_FIELD_CSP = AN_IMAGE_ASCII_BINARY_RECORD_FIELD_CSP;

const NInt AN_TYPE_17_RECORD_FIELD_RAE = 14;
const NInt AN_TYPE_17_RECORD_FIELD_RAU = 15;
const NInt AN_TYPE_17_RECORD_FIELD_IPC = 16;
const NInt AN_TYPE_17_RECORD_FIELD_DUI = 17;
const NInt AN_TYPE_17_RECORD_FIELD_GUI = 18;
const NInt AN_TYPE_17_RECORD_FIELD_MMS = 19;
const NInt AN_TYPE_17_RECORD_FIELD_ECL = 20;
const NInt AN_TYPE_17_RECORD_FIELD_COM = 21;
const NInt AN_TYPE_17_RECORD_FIELD_SHPS = 22;
const NInt AN_TYPE_17_RECORD_FIELD_SVPS = 23;

const NInt AN_TYPE_17_RECORD_FIELD_IQS = AN_IMAGE_ASCII_BINARY_RECORD_FIELD_IQM;

const NInt AN_TYPE_17_RECORD_FIELD_ALS = 25;
const NInt AN_TYPE_17_RECORD_FIELD_IRD = 26;

const NInt AN_TYPE_17_RECORD_FIELD_DMM = AN_IMAGE_ASCII_BINARY_RECORD_FIELD_DMM;

const NInt AN_TYPE_17_RECORD_FIELD_UDF_FROM = AN_ASCII_BINARY_RECORD_FIELD_UDF_FROM;
const NInt AN_TYPE_17_RECORD_FIELD_UDF_TO = AN_ASCII_BINARY_RECORD_FIELD_UDF_TO;

const NInt AN_TYPE_17_RECORD_FIELD_DATA = AN_RECORD_FIELD_DATA;

const NUShort AN_TYPE_17_RECORD_MAX_IRIS_DIAMETER = 9999;

const NInt AN_TYPE_17_RECORD_MAX_MAKE_LENGTH = 50;
const NInt AN_TYPE_17_RECORD_MAX_MODEL_LENGTH = 50;
const NInt AN_TYPE_17_RECORD_MAX_SERIAL_NUMBER_LENGTH = 50;

class ANIrisImageProperties : public ANIrisImageProperties_
{
	N_DECLARE_STRUCT_CLASS(ANIrisImageProperties)

public:
	ANIrisImageProperties(BdifIrisOrientation horzOrientation, BdifIrisOrientation vertOrientation, BdifIrisScanType scanType)
	{
		HorzOrientation = horzOrientation;
		VertOrientation = vertOrientation;
		ScanType = scanType;
	}
};

class ANMakeModelSerialNumber : public ANMakeModelSerialNumber_
{
	N_DECLARE_DISPOSABLE_STRUCT_CLASS(ANMakeModelSerialNumber)

public:
	ANMakeModelSerialNumber(const NStringWrapper & make, const NStringWrapper & model, const NStringWrapper & serialNumber)
	{
		NCheck(ANMakeModelSerialNumberCreateN(make.GetHandle(), model.GetHandle(), serialNumber.GetHandle(), this));
	}

	NString GetMake() const
	{
		return NString(hMake, false);
	}

	void SetMake(const NStringWrapper & value)
	{
		NCheck(NStringSet(value.GetHandle(), &hMake));
	}

	NString GetModel() const
	{
		return NString(hModel, false);
	}

	void SetModel(const NStringWrapper & value)
	{
		NCheck(NStringSet(value.GetHandle(), &hModel));
	}

	NString GetSerialNumber() const
	{
		return NString(hSerialNumber, false);
	}

	void SetSerialNumber(const NStringWrapper & value)
	{
		NCheck(NStringSet(value.GetHandle(), &hSerialNumber));
	}
};

}}}

N_DEFINE_DISPOSABLE_STRUCT_TYPE_TRAITS(Neurotec::Biometrics::Standards, ANMakeModelSerialNumber)

namespace Neurotec { namespace Biometrics { namespace Standards
{

class ANType17Record : public ANImageAsciiBinaryRecord
{
	N_DECLARE_OBJECT_CLASS(ANType17Record, ANImageAsciiBinaryRecord)

public:
	static NType ANIrisAcquisitionLightingSpectrumNativeTypeOf()
	{
		return NObject::GetObject<NType>(N_TYPE_OF(ANIrisAcquisitionLightingSpectrum), true);
	}

	BdifEyePosition GetFeatureIdentifier() const
	{
		BdifEyePosition value;
		NCheck(ANType17RecordGetFeatureIdentifier(GetHandle(), &value));
		return value;
	}

	void SetFeatureIdentifier(BdifEyePosition value)
	{
		NCheck(ANType17RecordSetFeatureIdentifier(GetHandle(), value));
	}

	NInt GetRotationAngle() const
	{
		NInt value;
		NCheck(ANType17RecordGetRotationAngle(GetHandle(), &value));
		return value;
	}

	void SetRotationAngle(NInt value)
	{
		NCheck(ANType17RecordSetRotationAngle(GetHandle(), value));
	}

	NInt GetRotationAngleUncertainty() const
	{
		NInt value;
		NCheck(ANType17RecordGetRotationAngleUncertainty(GetHandle(), &value));
		return value;
	}

	void SetRotationAngleUncertainty(NInt value)
	{
		NCheck(ANType17RecordSetRotationAngleUncertainty(GetHandle(), value));
	}

	bool GetImageProperties(ANIrisImageProperties * pValue) const
	{
		NBool hasValue;
		NCheck(ANType17RecordGetImageProperties(GetHandle(), pValue, &hasValue));
		return hasValue != 0;
	}

	void SetImageProperties(const ANIrisImageProperties * pValue)
	{
		NCheck(ANType17RecordSetImageProperties(GetHandle(), pValue));
	}

	NString GetDeviceUniqueIdentifier() const
	{
		return GetString(ANType17RecordGetDeviceUniqueIdentifierN);
	}

	void SetDeviceUniqueIdentifier(const NStringWrapper & value)
	{
		return SetString(ANType17RecordSetDeviceUniqueIdentifierN, value);
	}

	bool GetGuid(NGuid * pValue) const
	{
		NBool hasValue;
		NCheck(ANType17RecordGetGuid(GetHandle(), pValue, &hasValue));
		return hasValue != 0;
	}

	void SetGuid(const NGuid * pValue)
	{
		NCheck(ANType17RecordSetGuid(GetHandle(), pValue));
	}

	bool GetMakeModelSerialNumber(ANMakeModelSerialNumber * pValue) const
	{
		NBool hasValue;
		NCheck(ANType17RecordGetMakeModelSerialNumber(GetHandle(), pValue, &hasValue));
		return hasValue != 0;
	}

	NString GetMake() const
	{
		return GetString(ANType17RecordGetMakeN);
	}

	NString GetModel() const
	{
		return GetString(ANType17RecordGetModelN);
	}

	NString GetSerialNumber() const
	{
		return GetString(ANType17RecordGetSerialNumberN);
	}

	void SetMakeModelSerialNumber(const ANMakeModelSerialNumber * pValue)
	{
		NCheck(ANType17RecordSetMakeModelSerialNumberEx(GetHandle(), pValue));
	}

	void SetMakeModelSerialNumber(const NStringWrapper & make, const NStringWrapper & model, const NStringWrapper & serialNumber)
	{
		NCheck(ANType17RecordSetMakeModelSerialNumberN(GetHandle(), make.GetHandle(), model.GetHandle(), serialNumber.GetHandle()));
	}

	BdifEyeColor GetEyeColor() const
	{
		BdifEyeColor value;
		NCheck(ANType17RecordGetEyeColor(GetHandle(), &value));
		return value;
	}

	void SetEyeColor(BdifEyeColor value)
	{
		NCheck(ANType17RecordSetEyeColor(GetHandle(), value));
	}

	bool GetImageQualityScore(ANQualityMetric * pValue) const
	{
		NBool hasValue;
		NCheck(ANType17RecordGetImageQualityScore(GetHandle(), pValue, &hasValue));
		return hasValue != 0;
	}

	void SetImageQualityScore(const ANQualityMetric * pValue)
	{
		NCheck(ANType17RecordSetImageQualityScore(GetHandle(), pValue));
	}

	ANIrisAcquisitionLightingSpectrum GetAcquisitionLightingSpectrum() const
	{
		ANIrisAcquisitionLightingSpectrum value;
		NCheck(ANType17RecordGetAcquisitionLightingSpectrum(GetHandle(), &value));
		return value;
	}

	void SetAcquisitionLightingSpectrum(ANIrisAcquisitionLightingSpectrum value)
	{
		NCheck(ANType17RecordSetAcquisitionLightingSpectrum(GetHandle(), value));
	}

	NInt GetIrisDiameter() const
	{
		NInt value;
		NCheck(ANType17RecordGetIrisDiameter(GetHandle(), &value));
		return value;
	}

	void SetIrisDiameter(NInt value)
	{
		NCheck(ANType17RecordSetIrisDiameter(GetHandle(), value));
	}
};

}}}

#endif // !AN_TYPE_17_RECORD_HPP_INCLUDED
