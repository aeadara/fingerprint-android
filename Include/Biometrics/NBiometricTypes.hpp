#ifndef N_BIOMETRIC_TYPES_HPP_INCLUDED
#define N_BIOMETRIC_TYPES_HPP_INCLUDED

#include <Core/NTypes.hpp>
namespace Neurotec { namespace Biometrics
{
#include <Biometrics/NBiometricTypes.h>
}}

N_DEFINE_ENUM_TYPE_TRAITS(Neurotec::Biometrics, NBiometricType)
N_DEFINE_ENUM_TYPE_TRAITS(Neurotec::Biometrics, NBiometricSubtype)
N_DEFINE_ENUM_TYPE_TRAITS(Neurotec::Biometrics, NBiometricStatus)
N_DEFINE_ENUM_TYPE_TRAITS(Neurotec::Biometrics, NFImpressionType)
N_DEFINE_ENUM_TYPE_TRAITS(Neurotec::Biometrics, NFPosition)
N_DEFINE_ENUM_TYPE_TRAITS(Neurotec::Biometrics, NEPosition)
N_DEFINE_ENUM_TYPE_TRAITS(Neurotec::Biometrics, NFPatternClass)
N_DEFINE_ENUM_TYPE_TRAITS(Neurotec::Biometrics, NFMinutiaFormat)
N_DEFINE_ENUM_TYPE_TRAITS(Neurotec::Biometrics, NFMinutiaType)
N_DEFINE_ENUM_TYPE_TRAITS(Neurotec::Biometrics, NFRidgeCountsType)
N_DEFINE_ENUM_TYPE_TRAITS(Neurotec::Biometrics, NGender)
N_DEFINE_ENUM_TYPE_TRAITS(Neurotec::Biometrics, NLProperties)
N_DEFINE_ENUM_TYPE_TRAITS(Neurotec::Biometrics, NLExpression)
N_DEFINE_ENUM_TYPE_TRAITS(Neurotec::Biometrics, NEImageType)
N_DEFINE_ENUM_TYPE_TRAITS(Neurotec::Biometrics, NfiqQuality)

namespace Neurotec { namespace Biometrics
{
#undef N_BIOMETRIC_QUALITY_MIN
#undef N_BIOMETRIC_QUALITY_MAX
#undef N_BIOMETRIC_QUALITY_UNKNOWN
#undef N_BIOMETRIC_QUALITY_FAILED

#undef N_PHRASE_ID_UNKNOWN

const NByte N_BIOMETRIC_QUALITY_MIN = 0;
const NByte N_BIOMETRIC_QUALITY_MAX = 100;
const NByte N_BIOMETRIC_QUALITY_UNKNOWN = 254;
const NByte N_BIOMETRIC_QUALITY_FAILED = 255;

const NInt N_PHRASE_ID_UNKNOWN = 0;

class NFMinutia : public NFMinutia_
{
	N_DECLARE_STRUCT_CLASS(NFMinutia)

public:
	NFMinutia(NUShort x, NUShort y, NFMinutiaType type, NByte angle, NByte quality = 0, NByte curvature = 255, NByte g = 255)
	{
		X = x;
		Y = y;
		Type = type;
		Angle = angle;
		Quality = quality;
		Curvature = curvature;
		G = g;
	}

	NString ToString(const NStringWrapper & format = NString()) const
	{
		HNString hValue;
		NCheck(NFMinutiaToStringN(this, format.GetHandle(), &hValue));
		return NString(hValue, true);
	}
};

class NFMinutiaNeighbor : public NFMinutiaNeighbor_
{
	N_DECLARE_STRUCT_CLASS(NFMinutiaNeighbor)

public:
	NFMinutiaNeighbor(NInt index, NByte ridgeCount)
	{
		Index = index;
		RidgeCount = ridgeCount;
	}

	NString ToString(const NStringWrapper & format = NString()) const
	{
		HNString hValue;
		NCheck(NFMinutiaNeighborToStringN(this, format.GetHandle(), &hValue));
		return NString(hValue, true);
	}
};

class NFCore : public NFCore_
{
	N_DECLARE_STRUCT_CLASS(NFCore)

public:
	NFCore(NUShort x, NUShort y, NInt angle = -1)
	{
		X = x;
		Y = y;
		Angle = angle;
	}

	NString ToString(const NStringWrapper & format = NString()) const
	{
		HNString hValue;
		NCheck(NFCoreToStringN(this, format.GetHandle(), &hValue));
		return NString(hValue, true);
	}
};

class NFDelta : public NFDelta_
{
	N_DECLARE_STRUCT_CLASS(NFDelta)

public:
	NFDelta(NUShort x, NUShort y, NInt angle1 = -1, NInt angle2 = -1, NInt angle3 = -1)
	{
		X = x;
		Y = y;
		Angle1 = angle1;
		Angle2 = angle2;
		Angle3 = angle3;
	}

	NString ToString(const NStringWrapper & format = NString()) const
	{
		HNString hValue;
		NCheck(NFDeltaToStringN(this, format.GetHandle(), &hValue));
		return NString(hValue, true);
	}
};

class NFDoubleCore : public NFDoubleCore_
{
	N_DECLARE_STRUCT_CLASS(NFDoubleCore)

public:
	NFDoubleCore(NUShort x, NUShort y)
	{
		X = x;
		Y = y;
	}

	NString ToString(const NStringWrapper & format = NString()) const
	{
		HNString hValue;
		NCheck(NFDoubleCoreToStringN(this, format.GetHandle(), &hValue));
		return NString(hValue, true);
	}
};

class NLFeaturePoint : public NLFeaturePoint_
{
	N_DECLARE_STRUCT_CLASS(NLFeaturePoint)

public:
	NLFeaturePoint(NUShort code, NUShort x, NUShort y, NByte confidence = N_BIOMETRIC_QUALITY_UNKNOWN)
	{
		Code = code;
		X = x;
		Y = y;
		Confidence = confidence;
	}

	NString ToString(const NStringWrapper & format = NString()) const
	{
		HNString hValue;
		NCheck(NLFeaturePointToStringN(this, format.GetHandle(), &hValue));
		return NString(hValue, true);
	}
};

class NBiometricTypes
{
	N_DECLARE_STATIC_OBJECT_CLASS(NBiometricTypes)

public:
	static NType NBiometricTypeNativeTypeOf()
	{
		return NObject::GetObject<NType>(N_TYPE_OF(NBiometricType), true);
	}

	static NType NBiometricSubtypeNativeTypeOf()
	{
		return NObject::GetObject<NType>(N_TYPE_OF(NBiometricSubtype), true);
	}

	static NType NBiometricStatusNativeTypeOf()
	{
		return NObject::GetObject<NType>(N_TYPE_OF(NBiometricStatus), true);
	}

	static NType NFImpressionTypeNativeTypeOf()
	{
		return NObject::GetObject<NType>(N_TYPE_OF(NFImpressionType), true);
	}

	static NType NFPositionNativeTypeOf()
	{
		return NObject::GetObject<NType>(N_TYPE_OF(NFPosition), true);
	}

	static NType NEPositionNativeTypeOf()
	{
		return NObject::GetObject<NType>(N_TYPE_OF(NEPosition), true);
	}

	static NType NFPatternClassNativeTypeOf()
	{
		return NObject::GetObject<NType>(N_TYPE_OF(NFPatternClass), true);
	}

	static NType NFMinutiaFormatNativeTypeOf()
	{
		return NObject::GetObject<NType>(N_TYPE_OF(NFMinutiaFormat), true);
	}

	static NType NFMinutiaTypeNativeTypeOf()
	{
		return NObject::GetObject<NType>(N_TYPE_OF(NFMinutiaType), true);
	}

	static NType NFRidgeCountsTypeNativeTypeOf()
	{
		return NObject::GetObject<NType>(N_TYPE_OF(NFRidgeCountsType), true);
	}

	static NType NGenderNativeTypeOf()
	{
		return NObject::GetObject<NType>(N_TYPE_OF(NGender), true);
	}

	static NType NLPropertiesNativeTypeOf()
	{
		return NObject::GetObject<NType>(N_TYPE_OF(NLProperties), true);
	}

	static NType NLExpressionNativeTypeOf()
	{
		return NObject::GetObject<NType>(N_TYPE_OF(NLExpression), true);
	}

	static NType NEImageTypeNativeTypeOf()
	{
		return NObject::GetObject<NType>(N_TYPE_OF(NEImageType), true);
	}

	static NType NfiqQualityNativeTypeOf()
	{
		return NObject::GetObject<NType>(N_TYPE_OF(NfiqQuality), true);
	}

	static bool IsBiometricTypeValid(NBiometricType value)
	{
		return NBiometricTypeIsValid(value) != 0;
	}

	static bool IsBiometricSubtypeValid(NBiometricSubtype value)
	{
		return NBiometricSubtypeIsValid(value) != 0;
	}

	static bool IsBiometricStatusValid(NBiometricStatus value)
	{
		return NBiometricStatusIsValid(value) != 0;
	}

	static bool IsBiometricStatusFinal(NBiometricStatus value)
	{
		return NBiometricStatusIsFinal(value) != 0;
	}

	static bool IsImpressionTypeValidFinger(NFImpressionType value)
	{
		return NFImpressionTypeIsValidFinger(value) != 0;
	}

	static bool IsImpressionTypeValidPalm(NFImpressionType value)
	{
		return NFImpressionTypeIsValidPalm(value) != 0;
	}

	static bool IsImpressionTypeValid(NFImpressionType value)
	{
		return NFImpressionTypeIsValid(value) != 0;
	}

	static bool IsImpressionTypeGeneric(NFImpressionType value)
	{
		return NFImpressionTypeIsGeneric(value) != 0;
	}

	static bool IsImpressionTypeFinger(NFImpressionType value)
	{
		return NFImpressionTypeIsFinger(value) != 0;
	}

	static bool IsImpressionTypePalm(NFImpressionType value)
	{
		return NFImpressionTypeIsPalm(value) != 0;
	}

	static NFImpressionType ToImpressionTypeFinger(NFImpressionType value)
	{
		return NFImpressionTypeToFinger(value);
	}

	static bool IsImpressionTypePlain(NFImpressionType value)
	{
		return NFImpressionTypeIsPlain(value) != 0;
	}

	static bool IsImpressionTypeRolled(NFImpressionType value)
	{
		return NFImpressionTypeIsRolled(value) != 0;
	}

	static bool IsImpressionTypeSwipe(NFImpressionType value)
	{
		return NFImpressionTypeIsSwipe(value) != 0;
	}

	static bool IsImpressionTypeContactless(NFImpressionType value)
	{
		return NFImpressionTypeIsContactless(value) != 0;
	}

	static bool IsImpressionTypeContact(NFImpressionType value)
	{
		return NFImpressionTypeIsContact(value) != 0;
	}

	static bool IsImpressionTypeLiveScan(NFImpressionType value)
	{
		return NFImpressionTypeIsLiveScan(value) != 0;
	}

	static bool IsImpressionTypeNonliveScan(NFImpressionType value)
	{
		return NFImpressionTypeIsNonliveScan(value) != 0;
	}

	static bool IsImpressionTypeLatent(NFImpressionType value)
	{
		return NFImpressionTypeIsLatent(value) != 0;
	}

	static bool IsImpressionTypeOptical(NFImpressionType value)
	{
		return NFImpressionTypeIsOptical(value) != 0;
	}

	static bool IsImpressionTypeNonOptical(NFImpressionType value)
	{
		return NFImpressionTypeIsNonOptical(value) != 0;
	}

	static bool IsImpressionTypeCompatibleWith(NFImpressionType value, NFImpressionType otherValue)
	{
		return NFImpressionTypeIsCompatibleWith(value, otherValue) != 0;
	}

	static bool IsImpressionTypeOneOf(NFImpressionType value, NFImpressionType * arSupportedImpressionTypes, NInt supportedImressionTypeCount)
	{
		NBool result;
		NCheck(NFImpressionTypeIsOneOf(value, arSupportedImpressionTypes, supportedImressionTypeCount, &result));
		return result != 0;
	}

	static bool IsPositionValidTheFinger(NFPosition value)
	{
		return NFPositionIsValidTheFinger(value) != 0;
	}

	static bool IsPositionValidFinger(NFPosition value)
	{
		return NFPositionIsValidFinger(value) != 0;
	}

	static bool IsPositionValidPalm(NFPosition value)
	{
		return NFPositionIsValidPalm(value) != 0;
	}

	static bool IsPositionValid(NFPosition value)
	{
		return NFPositionIsValid(value) != 0;
	}

	static bool IsPositionTheFinger(NFPosition value)
	{
		return NFPositionIsTheFinger(value) != 0;
	}

	static bool IsPositionFinger(NFPosition value)
	{
		return NFPositionIsFinger(value) != 0;
	}

	static bool IsPositionThePalm(NFPosition value)
	{
		return NFPositionIsThePalm(value) != 0;
	}

	static bool IsPositionPalm(NFPosition value)
	{
		return NFPositionIsPalm(value) != 0;
	}

	static bool IsPositionSingleFinger(NFPosition value)
	{
		return NFPositionIsSingleFinger(value) != 0;
	}

	static bool IsPositionTwoFingers(NFPosition value)
	{
		return NFPositionIsTwoFingers(value) != 0;
	}

	static bool IsPositionThreeFingers(NFPosition value)
	{
		return NFPositionIsThreeFingers(value) != 0;
	}

	static bool IsPositionFourFingers(NFPosition value)
	{
		return NFPositionIsFourFingers(value) != 0;
	}

	static bool IsPositionKnown(NFPosition value)
	{
		return NFPositionIsKnown(value) != 0;
	}

	static bool IsPositionRight(NFPosition value)
	{
		return NFPositionIsRight(value) != 0;
	}

	static bool IsPositionLeft(NFPosition value)
	{
		return NFPositionIsLeft(value) != 0;
	}

	static bool IsPositionLeftAndRight(NFPosition value)
	{
		return NFPositionIsLeftAndRight(value) != 0;
	}

	static bool IsPositionCompatibleWith(NFPosition value, NFPosition otherValue)
	{
		return NFPositionIsCompatibleWith(value, otherValue) != 0;
	}

	static bool IsPositionCompatibleWith(NFPosition value, NFImpressionType imp)
	{
		return NFPositionIsCompatibleWithImpressionType(value, imp) != 0;
	}

	static bool IsPositionOneOf(NFPosition value, NFPosition * arSupportedPositions, NInt supportedPositionCount)
	{
		NBool result;
		NCheck(NFPositionIsOneOf(value, arSupportedPositions, supportedPositionCount, &result));
		return result != 0;
	}

	static NInt GetPositionAvailableParts(NFPosition value, NFPosition * arMissingPositions, NInt missingPositionCount, NFPosition * arResults, NInt resultsLength)
	{
		return NCheck(NFPositionGetAvailableParts(value, arMissingPositions, missingPositionCount, arResults, resultsLength));
	}

	static NArrayWrapper<NFPosition> GetPositionAvailableParts(NFPosition value, NFPosition * arMissingPositions, NInt missingPositionCount)
	{
		NInt count = NCheck(NFPositionGetAvailableParts(value, arMissingPositions, missingPositionCount, NULL, 0));
		NArrayWrapper<NFPosition> results(count);
		count = NCheck(NFPositionGetAvailableParts(value, arMissingPositions, missingPositionCount, results.GetPtr(), count));
		results.SetCount(count);
		return results;
	}

	static bool IsPositionValidTheEye(NEPosition value)
	{
		return NEPositionIsValidTheEye(value) != 0;
	}

	static bool IsPositionValid(NEPosition value)
	{
		return NEPositionIsValid(value) != 0;
	}

	static bool IsPositionSingleEye(NEPosition value)
	{
		return NEPositionIsSingleEye(value) != 0;
	}

	static bool IsPositionTwoEyes(NEPosition value)
	{
		return NEPositionIsTwoEyes(value) != 0;
	}

	static bool IsPositionKnown(NEPosition value)
	{
		return NEPositionIsKnown(value) != 0;
	}

	static bool IsPositionRight(NEPosition value)
	{
		return NEPositionIsRight(value) != 0;
	}

	static bool IsPositionLeft(NEPosition value)
	{
		return NEPositionIsLeft(value) != 0;
	}

	static bool IsPositionRightAndLeft(NEPosition value)
	{
		return NEPositionIsRightAndLeft(value) != 0;
	}

	static bool IsPositionOneOf(NEPosition value, NEPosition * arSupportedPositions, NInt supportedPositionCount)
	{
		NBool result;
		NCheck(NEPositionIsOneOf(value, arSupportedPositions, supportedPositionCount, &result));
		return result != 0;
	}

	static NInt GetPositionAvailableParts(NEPosition value, NEPosition * arMissingPositions, NInt missingPositionCount, NEPosition * arResults, NInt resultsLength)
	{
		return NCheck(NEPositionGetAvailableParts(value, arMissingPositions, missingPositionCount, arResults, resultsLength));
	}

	static NArrayWrapper<NEPosition> GetPositionAvailableParts(NEPosition value, NEPosition * arMissingPositions, NInt missingPositionCount)
	{
		NInt count = GetPositionAvailableParts(value, arMissingPositions, missingPositionCount, NULL, 0);
		NArrayWrapper<NEPosition> results(count);
		count = GetPositionAvailableParts(value, arMissingPositions, missingPositionCount, results.GetPtr(), count);
		results.SetCount(count);
		return results;
	}

	static bool IsPatternClassValid(NFPatternClass value)
	{
		return NFPatternClassIsValid(value) != 0;
	}

	static bool IsPatternClassValidFor(NFPatternClass value, NFPosition pos)
	{
		return NFPatternClassIsValidForPosition(value, pos) != 0;
	}

	static bool IsNfiqQualityValid(NfiqQuality value)
	{
		return NfiqQualityIsValid(value) != 0;
	}

	static NFloat AngleToDegrees(NInt value)
	{
		return NBiometricAngleToDegrees(value);
	}

	static NInt AngleFromRadians(NFloat value)
	{
		return NBiometricAngleFromDegrees(value);
	}

	static NDouble AngleToRadians(NInt value)
	{
		return NBiometricAngleToRadians(value);
	}

	static NInt AngleFromRadians(NDouble value)
	{
		return NBiometricAngleFromRadians(value);
	}

	static NString AngleToString(NInt value, const NStringWrapper & format = NString())
	{
		HNString hValue;
		NCheck(NBiometricAngleToStringN(value, format.GetHandle(), &hValue));
		return NString(hValue, true);
	}

	static bool IsQualityValid(NByte value)
	{
		return NBiometricQualityIsValid(value) != 0;
	}

	static NString QualityToString(NByte value, const NStringWrapper & format = NString())
	{
		HNString hValue;
		NCheck(NBiometricQualityToStringN(value, format.GetHandle(), &hValue));
		return NString(hValue, true);
	}
};

}}

N_DEFINE_STRUCT_TYPE_TRAITS(Neurotec::Biometrics, NFMinutia)
N_DEFINE_STRUCT_TYPE_TRAITS(Neurotec::Biometrics, NFMinutiaNeighbor)
N_DEFINE_STRUCT_TYPE_TRAITS(Neurotec::Biometrics, NFDelta)
N_DEFINE_STRUCT_TYPE_TRAITS(Neurotec::Biometrics, NFCore)
N_DEFINE_STRUCT_TYPE_TRAITS(Neurotec::Biometrics, NFDoubleCore)
N_DEFINE_STRUCT_TYPE_TRAITS(Neurotec::Biometrics, NLFeaturePoint);

#endif // !N_BIOMETRIC_TYPES_HPP_INCLUDED
