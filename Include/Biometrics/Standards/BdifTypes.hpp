#ifndef BDIF_TYPES_HPP_INCLUDED
#define BDIF_TYPES_HPP_INCLUDED

#include <Core/NTypes.hpp>
namespace Neurotec { namespace Biometrics { namespace Standards
{
#include <Biometrics/Standards/BdifTypes.h>
}}}

#include <Core/NObject.hpp>

N_DEFINE_ENUM_TYPE_TRAITS(Neurotec::Biometrics::Standards, BdifStandard)
N_DEFINE_ENUM_TYPE_TRAITS(Neurotec::Biometrics::Standards, BdifScaleUnits)
N_DEFINE_ENUM_TYPE_TRAITS(Neurotec::Biometrics::Standards, BdifCertificationSchemeId)
N_DEFINE_ENUM_TYPE_TRAITS(Neurotec::Biometrics::Standards, BdifFPPosition)
N_DEFINE_ENUM_TYPE_TRAITS(Neurotec::Biometrics::Standards, BdifFPImpressionType)
N_DEFINE_ENUM_TYPE_TRAITS(Neurotec::Biometrics::Standards, BdifFPatternClass)
N_DEFINE_ENUM_TYPE_TRAITS(Neurotec::Biometrics::Standards, BdifFPCaptureDeviceTechnology)
N_DEFINE_ENUM_TYPE_TRAITS(Neurotec::Biometrics::Standards, BdifFPExtendedDataTypeId)
N_DEFINE_ENUM_TYPE_TRAITS(Neurotec::Biometrics::Standards, BdifFPAnnotationCode)
N_DEFINE_ENUM_TYPE_TRAITS(Neurotec::Biometrics::Standards, BdifFPSegmentationStatus)
N_DEFINE_ENUM_TYPE_TRAITS(Neurotec::Biometrics::Standards, BdifFPMinutiaType)
N_DEFINE_ENUM_TYPE_TRAITS(Neurotec::Biometrics::Standards, BdifFPMinutiaRidgeEndingType)
N_DEFINE_ENUM_TYPE_TRAITS(Neurotec::Biometrics::Standards, BdifGender)
N_DEFINE_ENUM_TYPE_TRAITS(Neurotec::Biometrics::Standards, BdifEyeColor)
N_DEFINE_ENUM_TYPE_TRAITS(Neurotec::Biometrics::Standards, BdifHairColor)
N_DEFINE_ENUM_TYPE_TRAITS(Neurotec::Biometrics::Standards, BdifFaceProperties)
N_DEFINE_ENUM_TYPE_TRAITS(Neurotec::Biometrics::Standards, BdifFaceExpression)
N_DEFINE_ENUM_TYPE_TRAITS(Neurotec::Biometrics::Standards, BdifFaceExpressionBitMask)
N_DEFINE_ENUM_TYPE_TRAITS(Neurotec::Biometrics::Standards, BdifFaceFeaturePointType)
N_DEFINE_ENUM_TYPE_TRAITS(Neurotec::Biometrics::Standards, BdifFaceTemporalSemantics)
N_DEFINE_ENUM_TYPE_TRAITS(Neurotec::Biometrics::Standards, BdifFaceSpatialSamplingRateLevel)
N_DEFINE_ENUM_TYPE_TRAITS(Neurotec::Biometrics::Standards, BdifFacePostAcquisitionProcessing)
N_DEFINE_ENUM_TYPE_TRAITS(Neurotec::Biometrics::Standards, BdifImageSourceType)
N_DEFINE_ENUM_TYPE_TRAITS(Neurotec::Biometrics::Standards, BdifEyePosition)
N_DEFINE_ENUM_TYPE_TRAITS(Neurotec::Biometrics::Standards, BdifIrisOrientation)
N_DEFINE_ENUM_TYPE_TRAITS(Neurotec::Biometrics::Standards, BdifIrisScanType)

namespace Neurotec { namespace Biometrics { namespace Standards
{

#undef BDIF_IRIS_DEVICE_UNIQUE_IDENTIFIER_LENGTH

#undef BDIF_NON_STRICT_READ
#undef BDIF_DO_NOT_CHECK_CBEFF_PRODUCT_ID
#undef BDIF_ALLOW_QUALITY
#undef BDIF_ALLOW_OUT_OF_BOUNDS_FEATURES

const NInt BDIF_IRIS_DEVICE_UNIQUE_IDENTIFIER_LENGTH = 16;

const NUInt BDIF_NON_STRICT_READ = 0x00000001;
const NUInt BDIF_DO_NOT_CHECK_CBEFF_PRODUCT_ID = 0x00000002;
const NUInt BDIF_ALLOW_QUALITY = 0x00000004;
const NUInt BDIF_ALLOW_OUT_OF_BOUNDS_FEATURES = 0x00000008;

class BdifQualityBlock : public BdifQualityBlock_
{
	N_DECLARE_EQUATABLE_STRUCT_CLASS(BdifQualityBlock)

public:
	BdifQualityBlock(NByte qualityScore, NUShort qualityAlgorithmVendorId, NUShort qualityAlgorithmId)
	{
		this->qualityScore = qualityScore;
		this->qualityAlgorithmVendorId = qualityAlgorithmVendorId;
		this->qualityAlgorithmId = qualityAlgorithmId;
	}

	NString ToString(const NStringWrapper & format = NString()) const
	{
		HNString hValue;
		NCheck(BdifQualityBlockToStringN(this, format.GetHandle(), &hValue));
		return NString(hValue, true);
	}
};

class BdifCertificationBlock : public BdifCertificationBlock_
{
	N_DECLARE_EQUATABLE_STRUCT_CLASS(BdifCertificationBlock)

public:
	BdifCertificationBlock(NUShort certificationAuthorityId, BdifCertificationSchemeId certificationSchemeId)
	{
		this->certificationAuthorityId = certificationAuthorityId;
		this->certificationSchemeId = certificationSchemeId;
	}

	NString ToString(const NStringWrapper & format = NString()) const
	{
		HNString hValue;
		NCheck(BdifCertificationBlockToStringN(this, format.GetHandle(), &hValue));
		return NString(hValue, true);
	}
};

class BdifCaptureDateTime : public BdifCaptureDateTime_
{
	N_DECLARE_STRUCT_CLASS(BdifCaptureDateTime)

public:
	BdifCaptureDateTime(NUShort year, NByte month, NByte day, NByte hour, NByte minute, NByte second, NUShort millisecond)
	{
		this->year = year;
		this->month = month;
		this->day = day;
		this->hour = hour;
		this->minute = minute;
		this->second = second;
		this->millisecond = millisecond;
	}

	NString ToString(const NStringWrapper & format = NString()) const
	{
		HNString hValue;
		NCheck(BdifCaptureDateTimeToStringN(this, format.GetHandle(), &hValue));
		return NString(hValue, true);
	}
};

class BdifFPAnnotation : public BdifFPAnnotation_
{
	N_DECLARE_EQUATABLE_STRUCT_CLASS(BdifFPAnnotation)

public:
	BdifFPAnnotation(BdifFPPosition fingerPosition, BdifFPAnnotationCode annotationCode)
	{
		this->fingerPosition = fingerPosition;
		this->annotationCode = annotationCode;
	}

	NString ToString(const NStringWrapper & format = NString()) const
	{
		HNString hValue;
		NCheck(BdifFPAnnotationToStringN(this, format.GetHandle(), &hValue));
		return NString(hValue, true);
	}
};

class BdifFPExtendedData : public BdifFPExtendedData_
{
	N_DECLARE_EQUATABLE_DISPOSABLE_STRUCT_CLASS(BdifFPExtendedData)

public:
	BdifFPExtendedData(NUShort code, const ::Neurotec::IO::NBuffer & data)
	{
		NCheck(BdifFPExtendedDataCreateN(code, data.GetHandle(), this));
	}

	NString ToString(const NStringWrapper & format = NString()) const
	{
		HNString hValue;
		NCheck(BdifFPExtendedDataToStringN(this, format.GetHandle(), &hValue));
		return NString(hValue, true);
	}

	::Neurotec::IO::NBuffer GetData() const
	{
		return ::Neurotec::IO::NBuffer(this->hData, false);
	}

	void SetData(const ::Neurotec::IO::NBuffer & value)
	{
		NCheck(NObjectSet(value.GetHandle(), (HNObject *)&this->hData));
	}
};

class BdifFPMinutiaNeighbor : public BdifFPMinutiaNeighbor_
{
	N_DECLARE_STRUCT_CLASS(BdifFPMinutiaNeighbor)

public:
	BdifFPMinutiaNeighbor(NInt index, NByte ridgeCount)
	{
		Index = index;
		RidgeCount = ridgeCount;
	}

	NString ToString(const NStringWrapper & format = NString()) const
	{
		HNString hValue;
		NCheck(BdifFPMinutiaNeighborToStringN(this, format.GetHandle(), &hValue));
		return NString(hValue, true);
	}
};

class BdifFaceFeaturePoint : public BdifFaceFeaturePoint_
{
	N_DECLARE_EQUATABLE_STRUCT_CLASS(BdifFaceFeaturePoint)

public:
	BdifFaceFeaturePoint(BdifFaceFeaturePointType type, NByte code, NUShort x, NUShort y)
	{
		Type = type;
		Code = code;
		X = x;
		Y = y;
	}

	NString ToString(const NStringWrapper & format = NString()) const
	{
		HNString hValue;
		NCheck(BdifFaceFeaturePointToStringN(this, format.GetHandle(), &hValue));
		return NString(hValue, true);
	}
};

class BdifTypes
{
	N_DECLARE_STATIC_OBJECT_CLASS(BdifTypes)

public:
	static NType BdifStandardNativeTypeOf()
	{
		return NObject::GetObject<NType>(N_TYPE_OF(BdifStandard), true);
	}

	static NType BdifScaleUnitsNativeTypeOf()
	{
		return NObject::GetObject<NType>(N_TYPE_OF(BdifScaleUnits), true);
	}

	static NType BdifCertificationSchemeIdNativeTypeOf()
	{
		return NObject::GetObject<NType>(N_TYPE_OF(BdifCertificationSchemeId), true);
	}

	static NType BdifFPPositionNativeTypeOf()
	{
		return NObject::GetObject<NType>(N_TYPE_OF(BdifFPPosition), true);
	}

	static NType BdifFPImpressionTypeNativeTypeOf()
	{
		return NObject::GetObject<NType>(N_TYPE_OF(BdifFPImpressionType), true);
	}

	static NType BdifFPatternClassNativeTypeOf()
	{
		return NObject::GetObject<NType>(N_TYPE_OF(BdifFPatternClass), true);
	}

	static NType BdifFPCaptureDeviceTechnologyNativeTypeOf()
	{
		return NObject::GetObject<NType>(N_TYPE_OF(BdifFPCaptureDeviceTechnology), true);
	}

	static NType BdifFPExtendedDataTypeIdNativeTypeOf()
	{
		return NObject::GetObject<NType>(N_TYPE_OF(BdifFPExtendedDataTypeId), true);
	}

	static NType BdifFPAnnotationCodeNativeTypeOf()
	{
		return NObject::GetObject<NType>(N_TYPE_OF(BdifFPAnnotationCode), true);
	}

	static NType BdifFPSegmentationStatusNativeTypeOf()
	{
		return NObject::GetObject<NType>(N_TYPE_OF(BdifFPSegmentationStatus), true);
	}

	static NType BdifFPMinutiaTypeNativeTypeOf()
	{
		return NObject::GetObject<NType>(N_TYPE_OF(BdifFPMinutiaType), true);
	}

	static NType BdifFPMinutiaRidgeEndingTypeNativeTypeOf()
	{
		return NObject::GetObject<NType>(N_TYPE_OF(BdifFPMinutiaRidgeEndingType), true);
	}

	static NType BdifGenderNativeTypeOf()
	{
		return NObject::GetObject<NType>(N_TYPE_OF(BdifGender), true);
	}

	static NType BdifEyeColorTypeNativeTypeOf()
	{
		return NObject::GetObject<NType>(N_TYPE_OF(BdifEyeColor), true);
	}

	static NType BdifHairColorNativeTypeOf()
	{
		return NObject::GetObject<NType>(N_TYPE_OF(BdifHairColor), true);
	}

	static NType BdifFacePropertiesNativeTypeOf()
	{
		return NObject::GetObject<NType>(N_TYPE_OF(BdifFaceProperties), true);
	}

	static NType BdifFaceExpressionNativeTypeOf()
	{
		return NObject::GetObject<NType>(N_TYPE_OF(BdifFaceExpression), true);
	}

	static NType BdifFaceExpressionBitMaskNativeTypeOf()
	{
		return NObject::GetObject<NType>(N_TYPE_OF(BdifFaceExpressionBitMask), true);
	}

	static NType BdifFaceFeaturePointTypeNativeTypeOf()
	{
		return NObject::GetObject<NType>(N_TYPE_OF(BdifFaceFeaturePointType), true);
	}

	static NType BdifFaceTemporalSemanticsNativeTypeOf()
	{
		return NObject::GetObject<NType>(N_TYPE_OF(BdifFaceTemporalSemantics), true);
	}

	static NType BdifFaceSpatialSamplingRateLevelNativeTypeOf()
	{
		return NObject::GetObject<NType>(N_TYPE_OF(BdifFaceSpatialSamplingRateLevel), true);
	}

	static NType BdifFacePostAcquisitionProcessingNativeTypeOf()
	{
		return NObject::GetObject<NType>(N_TYPE_OF(BdifFacePostAcquisitionProcessing), true);
	}

	static NType BdifImageSourceTypeNativeTypeOf()
	{
		return NObject::GetObject<NType>(N_TYPE_OF(BdifImageSourceType), true);
	}

	static NType BdifEyePositionNativeTypeOf()
	{
		return NObject::GetObject<NType>(N_TYPE_OF(BdifEyePosition), true);
	}

	static NType BdifIrisOrientationNativeTypeOf()
	{
		return NObject::GetObject<NType>(N_TYPE_OF(BdifIrisOrientation), true);
	}

	static NType BdifIrisScanTypeNativeTypeOf()
	{
		return NObject::GetObject<NType>(N_TYPE_OF(BdifIrisScanType), true);
	}

	static bool IsStandardValid(BdifStandard value)
	{
		return BdifStandardIsValid(value) != 0;
	}

	static bool IsCertificationFlagValid(NByte value)
	{
		return BdifCertificationFlagIsValid(value) != 0;
	}

	static NFloat AngleToDegrees(NInt value, BdifStandard standard)
	{
		return BdifAngleToDegrees(value, standard);
	}

	static NInt AngleFromDegrees(NFloat value, BdifStandard standard)
	{
		return BdifAngleFromDegrees(value, standard);
	}

	static NDouble AngleToRadians(NInt value, BdifStandard standard)
	{
		return BdifAngleToRadians(value, standard);
	}

	static NInt AngleFromRadians(NDouble value, BdifStandard standard)
	{
		return BdifAngleFromRadians(value, standard);
	}

	static NString AngleToString(NInt value, const NStringWrapper & format = NString())
	{
		HNString hValue;
		NCheck(BdifAngleToStringN(value, format.GetHandle(), &hValue));
		return NString(hValue, true);
	}

	static NString QualityToString(NByte value, const NStringWrapper & format = NString())
	{
		HNString hValue;
		NCheck(BdifQualityToStringN(value, format.GetHandle(), &hValue));
		return NString(hValue, true);
	}

	static NUInt MakeFormat(NUShort owner, NUShort type)
	{
		return BdifMakeFormat(owner, type);
	}

	static NUShort GetFormatOwner(NUInt format)
	{
		return BdifGetFormatOwner(format);
	}

	static NUShort GetFormatType(NUInt format)
	{
		return BdifGetFormatType(format);
	}
};

}}}

N_DEFINE_STRUCT_TYPE_TRAITS(Neurotec::Biometrics::Standards, BdifQualityBlock);
N_DEFINE_STRUCT_TYPE_TRAITS(Neurotec::Biometrics::Standards, BdifCertificationBlock);
N_DEFINE_STRUCT_TYPE_TRAITS(Neurotec::Biometrics::Standards, BdifCaptureDateTime);
N_DEFINE_STRUCT_TYPE_TRAITS(Neurotec::Biometrics::Standards, BdifFPMinutiaNeighbor);
N_DEFINE_STRUCT_TYPE_TRAITS(Neurotec::Biometrics::Standards, BdifFaceFeaturePoint);
N_DEFINE_STRUCT_TYPE_TRAITS(Neurotec::Biometrics::Standards, BdifFPAnnotation);
N_DEFINE_DISPOSABLE_STRUCT_TYPE_TRAITS(Neurotec::Biometrics::Standards, BdifFPExtendedData);

#endif // !BDIF_TYPES_HPP_INCLUDED
