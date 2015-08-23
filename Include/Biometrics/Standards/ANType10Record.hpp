#ifndef AN_TYPE_10_RECORD_HPP_INCLUDED
#define AN_TYPE_10_RECORD_HPP_INCLUDED

#include <Biometrics/Standards/ANImageAsciiBinaryRecord.hpp>
#include <Geometry/NGeometry.hpp>
namespace Neurotec { namespace Biometrics { namespace Standards
{
using ::Neurotec::Geometry::NSize_;
#include <Biometrics/Standards/ANType10Record.h>
}}}

N_DEFINE_ENUM_TYPE_TRAITS(Neurotec::Biometrics::Standards, ANImageType)
N_DEFINE_ENUM_TYPE_TRAITS(Neurotec::Biometrics::Standards, ANSubjectPose)
N_DEFINE_ENUM_TYPE_TRAITS(Neurotec::Biometrics::Standards, ANSmtSource)
N_DEFINE_ENUM_TYPE_TRAITS(Neurotec::Biometrics::Standards, ANTattooClass)
N_DEFINE_ENUM_TYPE_TRAITS(Neurotec::Biometrics::Standards, ANTattooSubclass)
N_DEFINE_ENUM_TYPE_TRAITS(Neurotec::Biometrics::Standards, ANColor)

namespace Neurotec { namespace Biometrics { namespace Standards
{

#undef AN_TYPE_10_RECORD_FIELD_LEN
#undef AN_TYPE_10_RECORD_FIELD_IDC

#undef AN_TYPE_10_RECORD_FIELD_IMT

#undef AN_TYPE_10_RECORD_FIELD_SRC
#undef AN_TYPE_10_RECORD_FIELD_PHD
#undef AN_TYPE_10_RECORD_FIELD_HLL
#undef AN_TYPE_10_RECORD_FIELD_VLL
#undef AN_TYPE_10_RECORD_FIELD_SLC
#undef AN_TYPE_10_RECORD_FIELD_HPS
#undef AN_TYPE_10_RECORD_FIELD_VPS
#undef AN_TYPE_10_RECORD_FIELD_CGA

#undef AN_TYPE_10_RECORD_FIELD_CSP
#undef AN_TYPE_10_RECORD_FIELD_SAP

#undef AN_TYPE_10_RECORD_FIELD_SHPS
#undef AN_TYPE_10_RECORD_FIELD_SVPS

#undef AN_TYPE_10_RECORD_FIELD_POS
#undef AN_TYPE_10_RECORD_FIELD_POA
#undef AN_TYPE_10_RECORD_FIELD_PXS
#undef AN_TYPE_10_RECORD_FIELD_PAS

#undef AN_TYPE_10_RECORD_FIELD_SQS

#undef AN_TYPE_10_RECORD_FIELD_SPA
#undef AN_TYPE_10_RECORD_FIELD_SXS
#undef AN_TYPE_10_RECORD_FIELD_SEC
#undef AN_TYPE_10_RECORD_FIELD_SHC
#undef AN_TYPE_10_RECORD_FIELD_FFP

#undef AN_TYPE_10_RECORD_FIELD_DMM

#undef AN_TYPE_10_RECORD_FIELD_SMT
#undef AN_TYPE_10_RECORD_FIELD_SMS
#undef AN_TYPE_10_RECORD_FIELD_SMD
#undef AN_TYPE_10_RECORD_FIELD_COL

#undef AN_TYPE_10_RECORD_FIELD_UDF_FROM
#undef AN_TYPE_10_RECORD_FIELD_UDF_TO

#undef AN_TYPE_10_RECORD_FIELD_DATA

#undef AN_TYPE_10_RECORD_SAP_UNKNOWN
#undef AN_TYPE_10_RECORD_SAP_SURVEILLANCE_FACIAL_IMAGE
#undef AN_TYPE_10_RECORD_SAP_DRIVERS_LICENSE_IMAGE
#undef AN_TYPE_10_RECORD_SAP_ANSI_FULL_FRONTAL_FACIAL_IMAGE
#undef AN_TYPE_10_RECORD_SAP_ANSI_TOKEN_FACIAL_IMAGE
#undef AN_TYPE_10_RECORD_SAP_ISO_FULL_FRONTAL_FACIAL_IMAGE
#undef AN_TYPE_10_RECORD_SAP_ISO_TOKEN_FACIAL_IMAGE
#undef AN_TYPE_10_RECORD_SAP_PIV_FACIAL_IMAGE
#undef AN_TYPE_10_RECORD_SAP_LEGACY_MUGSHOT
#undef AN_TYPE_10_RECORD_SAP_BPA_LEVEL_30
#undef AN_TYPE_10_RECORD_SAP_BPA_LEVEL_40
#undef AN_TYPE_10_RECORD_SAP_BPA_LEVEL_50
#undef AN_TYPE_10_RECORD_SAP_BPA_LEVEL_51

#undef AN_TYPE_10_RECORD_MAX_PHOTO_DESCRIPTION_COUNT
#undef AN_TYPE_10_RECORD_MAX_QUALITY_METRIC_COUNT
#undef AN_TYPE_10_RECORD_MAX_SUBJECT_FACIAL_DESCRIPTION_COUNT
#undef AN_TYPE_10_RECORD_MAX_FACIAL_FEATURE_POINT_COUNT
#undef AN_TYPE_10_RECORD_MAX_NCIC_DESIGNATION_CODE_COUNT
#undef AN_TYPE_10_RECORD_MAX_SMT_COUNT

#undef AN_TYPE_10_RECORD_MAX_PHYSICAL_PHOTO_CHARACTERISTIC_LENGTH
#undef AN_TYPE_10_RECORD_MAX_OTHER_PHOTO_CHARACTERISTIC_LENGTH
#undef AN_TYPE_10_RECORD_MIN_SUBJECT_FACIAL_CHARACTERISTIC_LENGTH
#undef AN_TYPE_10_RECORD_MAX_SUBJECT_FACIAL_CHARACTERISTIC_LENGTH
#undef AN_TYPE_10_RECORD_MAX_VENDOR_PHOTO_ACQUISITION_SOURCE_LENGTH
#undef AN_TYPE_10_RECORD_MIN_NCIC_DESIGNATION_CODE_LENGTH
#undef AN_TYPE_10_RECORD_MAX_NCIC_DESIGNATION_CODE_LENGTH

#undef AN_TYPE_10_RECORD_MAX_SMT_SIZE

const NInt AN_TYPE_10_RECORD_FIELD_LEN = AN_RECORD_FIELD_LEN;
const NInt AN_TYPE_10_RECORD_FIELD_IDC = AN_RECORD_FIELD_IDC;

const NInt AN_TYPE_10_RECORD_FIELD_IMT = 3;

const NInt AN_TYPE_10_RECORD_FIELD_SRC = AN_ASCII_BINARY_RECORD_FIELD_SRC;
const NInt AN_TYPE_10_RECORD_FIELD_PHD = AN_ASCII_BINARY_RECORD_FIELD_DAT;
const NInt AN_TYPE_10_RECORD_FIELD_HLL = AN_IMAGE_ASCII_BINARY_RECORD_FIELD_HLL;
const NInt AN_TYPE_10_RECORD_FIELD_VLL = AN_IMAGE_ASCII_BINARY_RECORD_FIELD_VLL;
const NInt AN_TYPE_10_RECORD_FIELD_SLC = AN_IMAGE_ASCII_BINARY_RECORD_FIELD_SLC;
const NInt AN_TYPE_10_RECORD_FIELD_HPS = AN_IMAGE_ASCII_BINARY_RECORD_FIELD_HPS;
const NInt AN_TYPE_10_RECORD_FIELD_VPS = AN_IMAGE_ASCII_BINARY_RECORD_FIELD_VPS;
const NInt AN_TYPE_10_RECORD_FIELD_CGA = AN_IMAGE_ASCII_BINARY_RECORD_FIELD_CGA;

const NInt AN_TYPE_10_RECORD_FIELD_CSP = 12;
const NInt AN_TYPE_10_RECORD_FIELD_SAP = 13;

const NInt AN_TYPE_10_RECORD_FIELD_SHPS = AN_IMAGE_ASCII_BINARY_RECORD_FIELD_SHPS;
const NInt AN_TYPE_10_RECORD_FIELD_SVPS = AN_IMAGE_ASCII_BINARY_RECORD_FIELD_SVPS;

const NInt AN_TYPE_10_RECORD_FIELD_POS = 20;
const NInt AN_TYPE_10_RECORD_FIELD_POA = 21;
const NInt AN_TYPE_10_RECORD_FIELD_PXS = 22;
const NInt AN_TYPE_10_RECORD_FIELD_PAS = 23;

const NInt AN_TYPE_10_RECORD_FIELD_SQS = AN_IMAGE_ASCII_BINARY_RECORD_FIELD_IQM;

const NInt AN_TYPE_10_RECORD_FIELD_SPA = 25;
const NInt AN_TYPE_10_RECORD_FIELD_SXS = 26;
const NInt AN_TYPE_10_RECORD_FIELD_SEC = 27;
const NInt AN_TYPE_10_RECORD_FIELD_SHC = 28;
const NInt AN_TYPE_10_RECORD_FIELD_FFP = 29;

const NInt AN_TYPE_10_RECORD_FIELD_DMM = AN_IMAGE_ASCII_BINARY_RECORD_FIELD_DMM;

const NInt AN_TYPE_10_RECORD_FIELD_SMT = 40;
const NInt AN_TYPE_10_RECORD_FIELD_SMS = 41;
const NInt AN_TYPE_10_RECORD_FIELD_SMD = 42;
const NInt AN_TYPE_10_RECORD_FIELD_COL = 43;

const NInt AN_TYPE_10_RECORD_FIELD_UDF_FROM = AN_ASCII_BINARY_RECORD_FIELD_UDF_FROM;
const NInt AN_TYPE_10_RECORD_FIELD_UDF_TO = AN_ASCII_BINARY_RECORD_FIELD_UDF_TO;

const NInt AN_TYPE_10_RECORD_FIELD_DATA = AN_RECORD_FIELD_DATA;

const NUShort AN_TYPE_10_RECORD_SAP_UNKNOWN = 0;
const NUShort AN_TYPE_10_RECORD_SAP_SURVEILLANCE_FACIAL_IMAGE = 1;
const NUShort AN_TYPE_10_RECORD_SAP_DRIVERS_LICENSE_IMAGE = 10;
const NUShort AN_TYPE_10_RECORD_SAP_ANSI_FULL_FRONTAL_FACIAL_IMAGE = 11;
const NUShort AN_TYPE_10_RECORD_SAP_ANSI_TOKEN_FACIAL_IMAGE = 12;
const NUShort AN_TYPE_10_RECORD_SAP_ISO_FULL_FRONTAL_FACIAL_IMAGE = 13;
const NUShort AN_TYPE_10_RECORD_SAP_ISO_TOKEN_FACIAL_IMAGE = 14;
const NUShort AN_TYPE_10_RECORD_SAP_PIV_FACIAL_IMAGE = 15;
const NUShort AN_TYPE_10_RECORD_SAP_LEGACY_MUGSHOT = 20;
const NUShort AN_TYPE_10_RECORD_SAP_BPA_LEVEL_30 = 30;
const NUShort AN_TYPE_10_RECORD_SAP_BPA_LEVEL_40 = 40;
const NUShort AN_TYPE_10_RECORD_SAP_BPA_LEVEL_50 = 50;
const NUShort AN_TYPE_10_RECORD_SAP_BPA_LEVEL_51 = 51;

const NInt AN_TYPE_10_RECORD_MAX_PHOTO_DESCRIPTION_COUNT = 9;
const NInt AN_TYPE_10_RECORD_MAX_QUALITY_METRIC_COUNT = 9;
const NInt AN_TYPE_10_RECORD_MAX_SUBJECT_FACIAL_DESCRIPTION_COUNT = 50;
const NInt AN_TYPE_10_RECORD_MAX_FACIAL_FEATURE_POINT_COUNT = 88;
const NInt AN_TYPE_10_RECORD_MAX_NCIC_DESIGNATION_CODE_COUNT = 3;
const NInt AN_TYPE_10_RECORD_MAX_SMT_COUNT = 9;

const NInt AN_TYPE_10_RECORD_MAX_PHYSICAL_PHOTO_CHARACTERISTIC_LENGTH = 11;
const NInt AN_TYPE_10_RECORD_MAX_OTHER_PHOTO_CHARACTERISTIC_LENGTH = 14;
const NInt AN_TYPE_10_RECORD_MIN_SUBJECT_FACIAL_CHARACTERISTIC_LENGTH = 5;
const NInt AN_TYPE_10_RECORD_MAX_SUBJECT_FACIAL_CHARACTERISTIC_LENGTH = 20;
const NInt AN_TYPE_10_RECORD_MAX_VENDOR_PHOTO_ACQUISITION_SOURCE_LENGTH = 7;
const NInt AN_TYPE_10_RECORD_MIN_NCIC_DESIGNATION_CODE_LENGTH = 3;
const NInt AN_TYPE_10_RECORD_MAX_NCIC_DESIGNATION_CODE_LENGTH = 10;

const NInt AN_TYPE_10_RECORD_MAX_SMT_SIZE = 99;

class ANSmt : public ANSmt_
{
	N_DECLARE_EQUATABLE_DISPOSABLE_STRUCT_CLASS(ANSmt)

public:
	ANSmt(ANSmtSource source, ANTattooClass tattooClass, ANTattooSubclass tattooSubclass, const NStringWrapper & description)
	{
		NCheck(ANSmtCreateN(source, tattooClass, tattooSubclass, description.GetHandle(), this));
	}

	NString GetDescription() const
	{
		return NString(hDescription, false);
	}

	void SetDescription(const NStringWrapper & value)
	{
		NCheck(NStringSet(value.GetHandle(), &hDescription));
	}
};

class ANImageSourceType : public ANImageSourceType_
{
	N_DECLARE_DISPOSABLE_STRUCT_CLASS(ANImageSourceType)

public:
	ANImageSourceType(BdifImageSourceType value, const NStringWrapper & vendorValue)
	{
		NCheck(ANImageSourceTypeCreateN(value, vendorValue.GetHandle(), this));
	}

	NString GetVendorValue() const
	{
		return NString(hVendorValue, false);
	}

	void SetVendorValue(const NStringWrapper & value)
	{
		NCheck(NStringSet(value.GetHandle(), &hVendorValue));
	}
};

class ANPoseAngles : public ANPoseAngles_
{
	N_DECLARE_STRUCT_CLASS(ANPoseAngles)

public:
	ANPoseAngles(NInt yaw, NInt pitch, NInt roll, NInt yawUncertainty, NInt pitchUncertainty, NInt rollUncertainty)
	{
		this->yaw = yaw;
		this->pitch = pitch;
		this->roll = roll;
		this->yawUncertainty = yawUncertainty;
		this->pitchUncertainty = pitchUncertainty;
		this->rollUncertainty = rollUncertainty;
	}
};

class ANHairColor : public ANHairColor_
{
	N_DECLARE_STRUCT_CLASS(ANHairColor)

public:
	ANHairColor(BdifHairColor value, BdifHairColor baldValue)
	{
		this->value = value;
		this->baldValue = baldValue;
	}
};

}}}

N_DEFINE_DISPOSABLE_STRUCT_TYPE_TRAITS(Neurotec::Biometrics::Standards, ANSmt)
N_DEFINE_DISPOSABLE_STRUCT_TYPE_TRAITS(Neurotec::Biometrics::Standards, ANImageSourceType)
N_DEFINE_STRUCT_TYPE_TRAITS(Neurotec::Biometrics::Standards, ANPoseAngles)
N_DEFINE_STRUCT_TYPE_TRAITS(Neurotec::Biometrics::Standards, ANHairColor)

namespace Neurotec { namespace Biometrics { namespace Standards
{

class ANType10Record : public ANImageAsciiBinaryRecord
{
	N_DECLARE_OBJECT_CLASS(ANType10Record, ANImageAsciiBinaryRecord)

public:
	class PhysicalPhotoCharacteristicCollection : public ::Neurotec::Collections::NCollectionBase<NString, ANType10Record,
		ANType10RecordGetPhysicalPhotoCharacteristicCount, ANType10RecordGetPhysicalPhotoCharacteristicN>
	{
		PhysicalPhotoCharacteristicCollection(const ANType10Record & owner)
		{
			SetOwner(owner);
		}

		friend class ANType10Record;
	public:
		void Set(NInt index, const NStringWrapper & value)
		{
			NCheck(ANType10RecordSetPhysicalPhotoCharacteristicN(this->GetOwnerHandle(), index, value.GetHandle()));
		}

		NInt Add(const NStringWrapper & value)
		{
			NInt index;
			NCheck(ANType10RecordAddPhysicalPhotoCharacteristicExN(this->GetOwnerHandle(), value.GetHandle(), &index));
			return index;
		}

		void Insert(NInt index, const NStringWrapper & value)
		{
			NCheck(ANType10RecordInsertPhysicalPhotoCharacteristicN(this->GetOwnerHandle(), index, value.GetHandle()));
		}

		void RemoveAt(NInt index)
		{
			NCheck(ANType10RecordRemovePhysicalPhotoCharacteristicAt(this->GetOwnerHandle(), index));
		}

		void Clear()
		{
			NCheck(ANType10RecordClearPhysicalPhotoCharacteristics(this->GetOwnerHandle()));
		}
	};

	class OtherPhotoCharacteristicCollection : public ::Neurotec::Collections::NCollectionBase<NString, ANType10Record,
		ANType10RecordGetOtherPhotoCharacteristicCount, ANType10RecordGetOtherPhotoCharacteristicN>
	{
		OtherPhotoCharacteristicCollection(const ANType10Record & owner)
		{
			SetOwner(owner);
		}

		friend class ANType10Record;
	public:
		void Set(NInt index, const NStringWrapper & value)
		{
			NCheck(ANType10RecordSetOtherPhotoCharacteristicN(this->GetOwnerHandle(), index, value.GetHandle()));
		}

		NInt Add(const NStringWrapper & value)
		{
			NInt index;
			NCheck(ANType10RecordAddOtherPhotoCharacteristicExN(this->GetOwnerHandle(), value.GetHandle(), &index));
			return index;
		}

		void Insert(NInt index, const NStringWrapper & value)
		{
			NCheck(ANType10RecordInsertOtherPhotoCharacteristicN(this->GetOwnerHandle(), index, value.GetHandle()));
		}

		void RemoveAt(NInt index)
		{
			NCheck(ANType10RecordRemoveOtherPhotoCharacteristicAt(this->GetOwnerHandle(), index));
		}

		void Clear()
		{
			NCheck(ANType10RecordClearOtherPhotoCharacteristics(this->GetOwnerHandle()));
		}
	};

	class SubjectQualityScoreCollection : public ::Neurotec::Collections::NCollectionWithAllOutBase<ANQualityMetric, ANType10Record,
		ANType10RecordGetSubjectQualityScoreCount, ANType10RecordGetSubjectQualityScore, ANType10RecordGetSubjectQualityScores>
	{
		SubjectQualityScoreCollection(const ANType10Record & owner)
		{
			SetOwner(owner);
		}

		friend class ANType10Record;
	public:
#include <Core/NNoDeprecate.h>
		N_DEPRECATED("use NArrayWrapper<ANQualityMetric> GetAll() instead")
		NInt GetAll(ANQualityMetric * arValues, NInt valuesLength) const
		{
			NInt count;
			NCheck(count = ANType10RecordGetSubjectQualityScoresEx(this->GetOwnerHandle(), arValues, valuesLength));
			return count;
		}
#include <Core/NReDeprecate.h>

		using ::Neurotec::Collections::NCollectionWithAllOutBase<ANQualityMetric, ANType10Record,
			ANType10RecordGetSubjectQualityScoreCount, ANType10RecordGetSubjectQualityScore, ANType10RecordGetSubjectQualityScores>::GetAll;

		void Set(NInt index, const ANQualityMetric & value)
		{
			NCheck(ANType10RecordSetSubjectQualityScore(this->GetOwnerHandle(), index, &value));
		}

		NInt Add(const ANQualityMetric & value)
		{
			NInt index;
			NCheck(ANType10RecordAddSubjectQualityScoreEx(this->GetOwnerHandle(), &value, &index));
			return index;
		}

		void Insert(NInt index, const ANQualityMetric & value)
		{
			NCheck(ANType10RecordInsertSubjectQualityScore(this->GetOwnerHandle(), index, &value));
		}

		void RemoveAt(NInt index)
		{
			NCheck(ANType10RecordRemoveSubjectQualityScoreAt(this->GetOwnerHandle(), index));
		}

		void Clear()
		{
			NCheck(ANType10RecordClearSubjectQualityScores(this->GetOwnerHandle()));
		}
	};

	class SubjectFacialCharacteristicCollection : public ::Neurotec::Collections::NCollectionBase<NString, ANType10Record,
		ANType10RecordGetSubjectFacialCharacteristicCount, ANType10RecordGetSubjectFacialCharacteristicN>
	{
		SubjectFacialCharacteristicCollection(const ANType10Record & owner)
		{
			SetOwner(owner);
		}

		friend class ANType10Record;
	public:
		void Set(NInt index, const NStringWrapper & value)
		{
			NCheck(ANType10RecordSetSubjectFacialCharacteristicN(this->GetOwnerHandle(), index, value.GetHandle()));
		}

		NInt Add(const NStringWrapper & value)
		{
			NInt index;
			NCheck(ANType10RecordAddSubjectFacialCharacteristicExN(this->GetOwnerHandle(), value.GetHandle(), &index));
			return index;
		}

		void Insert(NInt index, const NStringWrapper & value)
		{
			NCheck(ANType10RecordInsertSubjectFacialCharacteristicN(this->GetOwnerHandle(), index, value.GetHandle()));
		}

		void RemoveAt(NInt index)
		{
			NCheck(ANType10RecordRemoveSubjectFacialCharacteristicAt(this->GetOwnerHandle(), index));
		}

		void Clear()
		{
			NCheck(ANType10RecordClearSubjectFacialCharacteristics(this->GetOwnerHandle()));
		}
	};

	class FacialFeaturePointCollection : public ::Neurotec::Collections::NCollectionWithAllOutBase<BdifFaceFeaturePoint, ANType10Record,
		ANType10RecordGetFacialFeaturePointCount, ANType10RecordGetFacialFeaturePoint, ANType10RecordGetFacialFeaturePoints>
	{
		FacialFeaturePointCollection(const ANType10Record & owner)
		{
			SetOwner(owner);
		}

		friend class ANType10Record;

	public:
#include <Core/NNoDeprecate.h>
		N_DEPRECATED("use NArrayWrapper<BdifFaceFeaturePoint> GetAll() instead")
		NInt GetAll(BdifFaceFeaturePoint * arValues, NInt valuesLength) const
		{
			NInt count;
			NCheck(count = ANType10RecordGetFacialFeaturePointsEx(this->GetOwnerHandle(), arValues, valuesLength));
			return count;
		}
#include <Core/NReDeprecate.h>

		using ::Neurotec::Collections::NCollectionWithAllOutBase<BdifFaceFeaturePoint, ANType10Record,
			ANType10RecordGetFacialFeaturePointCount, ANType10RecordGetFacialFeaturePoint, ANType10RecordGetFacialFeaturePoints>::GetAll;

		void Set(NInt index, const BdifFaceFeaturePoint & value)
		{
			NCheck(ANType10RecordSetFacialFeaturePoint(this->GetOwnerHandle(), index, &value));
		}

		NInt Add(const BdifFaceFeaturePoint & value)
		{
			NInt index;
			NCheck(ANType10RecordAddFacialFeaturePointEx(this->GetOwnerHandle(), &value, &index));
			return index;
		}

		void Insert(NInt index, const BdifFaceFeaturePoint & value)
		{
			NCheck(ANType10RecordInsertFacialFeaturePoint(this->GetOwnerHandle(), index, &value));
		}

		void RemoveAt(NInt index)
		{
			NCheck(ANType10RecordRemoveFacialFeaturePointAt(this->GetOwnerHandle(), index));
		}

		void Clear()
		{
			NCheck(ANType10RecordClearFacialFeaturePoints(this->GetOwnerHandle()));
		}
	};

	class NcicDesignationCodeCollection : public ::Neurotec::Collections::NCollectionBase<NString, ANType10Record,
		ANType10RecordGetNcicDesignationCodeCount, ANType10RecordGetNcicDesignationCodeN>
	{
		NcicDesignationCodeCollection(const ANType10Record & owner)
		{
			SetOwner(owner);
		}

		friend class ANType10Record;
	public:
		void Set(NInt index, const NStringWrapper & value)
		{
			NCheck(ANType10RecordSetNcicDesignationCodeN(this->GetOwnerHandle(), index, value.GetHandle()));
		}

		NInt Add(const NStringWrapper & value)
		{
			NInt index;
			NCheck(ANType10RecordAddNcicDesignationCodeExN(this->GetOwnerHandle(), value.GetHandle(), &index));
			return index;
		}

		void Insert(NInt index, const NStringWrapper & value)
		{
			NCheck(ANType10RecordInsertNcicDesignationCodeN(this->GetOwnerHandle(), index, value.GetHandle()));
		}

		void RemoveAt(NInt index)
		{
			NCheck(ANType10RecordRemoveNcicDesignationCodeAt(this->GetOwnerHandle(), index));
		}

		void Clear()
		{
			NCheck(ANType10RecordClearNcicDesignationCodes(this->GetOwnerHandle()));
		}
	};

	class SmtCollection : public ::Neurotec::Collections::NCollectionBase<ANSmt, ANType10Record,
		ANType10RecordGetSmtCount, ANType10RecordGetSmt>
	{
		SmtCollection(const ANType10Record & owner)
		{
			SetOwner(owner);
		}

	public:
		void Set(NInt index, const ANSmt & value)
		{
			NCheck(ANType10RecordSetSmtEx(this->GetOwnerHandle(), index, &value));
		}

		NInt Add(const ANSmt & value)
		{
			NInt index;
			NCheck(ANType10RecordAddSmt(this->GetOwnerHandle(), &value, &index));
			return index;
		}

		void Insert(NInt index, const ANSmt & value)
		{
			NCheck(ANType10RecordInsertSmtEx(this->GetOwnerHandle(), index, &value));
		}

		void RemoveAt(NInt index)
		{
			NCheck(ANType10RecordRemoveSmtAt(this->GetOwnerHandle(), index));
		}

		void Clear()
		{
			NCheck(ANType10RecordClearSmts(this->GetOwnerHandle()));
		}

		friend class ANType10Record;
	};

	class SmtColorsCollection : public ::Neurotec::NObjectPartBase<ANType10Record>
	{
		SmtColorsCollection(const ANType10Record & owner)
		{
			SetOwner(owner);
		}

		friend class ANType10Record;
	public:
		NInt GetCount(NInt baseIndex) const
		{
			NInt value;
			NCheck(ANType10RecordGetSmtColorCount(this->GetOwnerHandle(), baseIndex, &value));
			return value;
		}

		ANColor Get(NInt baseIndex, NInt index) const
		{
			ANColor value;
			NCheck(ANType10RecordGetSmtColor(this->GetOwnerHandle(), baseIndex, index, &value));
			return value;
		}

#include <Core/NNoDeprecate.h>
		N_DEPRECATED("use NArrayWrapper<ANColor> GetAll(NInt baseIndex) instead")
		NInt GetAll(NInt baseIndex, ANColor * arValues, NInt valuesLength) const
		{
			NInt count;
			NCheck(count = ANType10RecordGetSmtColorsEx(this->GetOwnerHandle(), baseIndex, arValues, valuesLength));
			return count;
		}
#include <Core/NReDeprecate.h>

		NArrayWrapper<ANColor> GetAll(NInt baseIndex) const
		{
			ANColor * arValues = NULL;
			NInt valueCount = 0;
			NCheck(ANType10RecordGetSmtColors(this->GetOwnerHandle(), baseIndex, &arValues, &valueCount));
			return NArrayWrapper<ANColor>(arValues, valueCount);
		}

		void Set(NInt baseIndex, NInt index, ANColor value)
		{
			NCheck(ANType10RecordSetSmtColor(this->GetOwnerHandle(), baseIndex, index, value));
		}

		NInt Add(NInt baseIndex, ANColor value)
		{
			NInt index;
			NCheck(ANType10RecordAddSmtColorEx(this->GetOwnerHandle(), baseIndex, value, &index));
			return index;
		}

		void Insert(NInt baseIndex, NInt index, ANColor value)
		{
			NCheck(ANType10RecordInsertSmtColor(this->GetOwnerHandle(), baseIndex, index, value));
		}

		void RemoveAt(NInt baseIndex, NInt index)
		{
			NCheck(ANType10RecordRemoveSmtColorAt(this->GetOwnerHandle(), baseIndex, index));
		}

		void Clear(NInt baseIndex)
		{
			NCheck(ANType10RecordClearSmtColors(this->GetOwnerHandle(), baseIndex));
		}
	};

public:
	static NType ANImageTypeNativeTypeOf()
	{
		return NObject::GetObject<NType>(N_TYPE_OF(ANImageType), true);
	}

	static NType ANSubjectPoseNativeTypeOf()
	{
		return NObject::GetObject<NType>(N_TYPE_OF(ANSubjectPose), true);
	}

	static NType ANSmtSourceNativeTypeOf()
	{
		return NObject::GetObject<NType>(N_TYPE_OF(ANSmtSource), true);
	}

	static NType ANTattooClassNativeTypeOf()
	{
		return NObject::GetObject<NType>(N_TYPE_OF(ANTattooClass), true);
	}

	static NType ANTattooSubclassNativeTypeOf()
	{
		return NObject::GetObject<NType>(N_TYPE_OF(ANTattooSubclass), true);
	}

	static NType ANColorNativeTypeOf()
	{
		return NObject::GetObject<NType>(N_TYPE_OF(ANColor), true);
	}

	ANImageType GetImageType() const
	{
		ANImageType value;
		NCheck(ANType10RecordGetImageType(GetHandle(), &value));
		return value;
	}

	NInt GetSubjectAcquisitionProfile() const
	{
		NInt value;
		NCheck(ANType10RecordGetSubjectAcquisitionProfile(GetHandle(), &value));
		return value;
	}

	void SetSubjectAcquisitionProfile(NInt value)
	{
		NCheck(ANType10RecordSetSubjectAcquisitionProfile(GetHandle(), value));
	}

	ANSubjectPose GetSubjectPose() const
	{
		ANSubjectPose value;
		NCheck(ANType10RecordGetSubjectPose(GetHandle(), &value));
		return value;
	}

	void SetSubjectPose(ANSubjectPose value)
	{
		NCheck(ANType10RecordSetSubjectPose(GetHandle(), value));
	}

	bool GetPoseOffsetAngle(NInt * pValue) const
	{
		NBool hasValue;
		NCheck(ANType10RecordGetPoseOffsetAngle(GetHandle(), pValue, &hasValue));
		return hasValue != 0;
	}

	void SetPoseOffsetAngle(const NInt * pValue)
	{
		NCheck(ANType10RecordSetPoseOffsetAngle(GetHandle(), pValue));
	}

	BdifFaceProperties GetPhotoAttributes() const
	{
		BdifFaceProperties value;
		NCheck(ANType10RecordGetPhotoAttributes(GetHandle(), &value));
		return value;
	}

	void SetPhotoAttributes(BdifFaceProperties value)
	{
		NCheck(ANType10RecordSetPhotoAttributes(GetHandle(), value));
	}

	bool GetPhotoAcquisitionSource(ANImageSourceType * pValue) const
	{
		NBool hasValue;
		NCheck(ANType10RecordGetPhotoAcquisitionSourceEx(GetHandle(), pValue, &hasValue));
		return hasValue != 0;
	}

	BdifImageSourceType GetPhotoAcquisitionSource() const
	{
		BdifImageSourceType value;
		NCheck(ANType10RecordGetPhotoAcquisitionSource(GetHandle(), &value));
		return value;
	}

	NString GetVendorPhotoAcquisitionSource() const
	{
		return GetString(ANType10RecordGetVendorPhotoAcquisitionSourceN);
	}

	void SetPhotoAcquisitionSource(const ANImageSourceType * pValue)
	{
		NCheck(ANType10RecordSetPhotoAcquisitionSourceEx(GetHandle(), pValue));
	}

	void SetPhotoAcquisitionSource(BdifImageSourceType value, const NStringWrapper & vendorValue)
	{
		NCheck(ANType10RecordSetPhotoAcquisitionSourceN(GetHandle(), value, vendorValue.GetHandle()));
	}

	bool GetSubjectPoseAngles(ANPoseAngles * pValue) const
	{
		NBool hasValue;
		NCheck(ANType10RecordGetSubjectPoseAnglesEx(GetHandle(), pValue, &hasValue));
		return hasValue != 0;
	}

	NInt GetSubjectPoseAnglesYaw() const
	{
		NInt value;
		NCheck(ANType10RecordGetSubjectPoseAnglesYaw(GetHandle(), &value));
		return value;
	}

	NInt GetSubjectPoseAnglesPitch() const
	{
		NInt value;
		NCheck(ANType10RecordGetSubjectPoseAnglesPitch(GetHandle(), &value));
		return value;
	}

	NInt GetSubjectPoseAnglesRoll() const
	{
		NInt value;
		NCheck(ANType10RecordGetSubjectPoseAnglesRoll(GetHandle(), &value));
		return value;
	}

	NInt GetSubjectPoseAnglesYawUncertainty() const
	{
		NInt value;
		NCheck(ANType10RecordGetSubjectPoseAnglesYawUncertainty(GetHandle(), &value));
		return value;
	}

	NInt GetSubjectPoseAnglesPitchUncertainty() const
	{
		NInt value;
		NCheck(ANType10RecordGetSubjectPoseAnglesPitchUncertainty(GetHandle(), &value));
		return value;
	}

	NInt GetSubjectPoseAnglesRollUncertainty() const
	{
		NInt value;
		NCheck(ANType10RecordGetSubjectPoseAnglesRollUncertainty(GetHandle(), &value));
		return value;
	}

	void GetSubjectPoseAngles(NInt * pYaw, NInt * pPitch, NInt * pRoll, NInt * pYawUncertainty, NInt * pPitchUncertainty, NInt * pRollUncertainty)
	{
		NCheck(ANType10RecordGetSubjectPoseAngles(GetHandle(), pYaw, pPitch, pRoll, pYawUncertainty, pPitchUncertainty, pRollUncertainty));
	}

	void SetSubjectPoseAngles(const ANPoseAngles * pValue)
	{
		NCheck(ANType10RecordSetSubjectPoseAnglesEx(GetHandle(), pValue));
	}

	void SetSubjectPoseAngles(NInt yaw, NInt pitch, NInt roll, NInt yawUncertainty, NInt pitchUncertainty, NInt rollUncertainty)
	{
		NCheck(ANType10RecordSetSubjectPoseAngles(GetHandle(), yaw, pitch, roll, yawUncertainty, pitchUncertainty, rollUncertainty));
	}

	BdifFaceExpression GetSubjectFacialExpression() const
	{
		BdifFaceExpression value;
		NCheck(ANType10RecordGetSubjectFacialExpression(GetHandle(), &value));
		return value;
	}

	void SetSubjectFacialExpression(BdifFaceExpression value)
	{
		NCheck(ANType10RecordSetSubjectFacialExpression(GetHandle(), value));
	}

	BdifFaceProperties GetSubjectFacialAttributes() const
	{
		BdifFaceProperties value;
		NCheck(ANType10RecordGetSubjectFacialAttributes(GetHandle(), &value));
		return value;
	}

	void SetSubjectFacialAttributes(BdifFaceProperties value)
	{
		NCheck(ANType10RecordSetSubjectFacialAttributes(GetHandle(), value));
	}

	BdifEyeColor GetSubjectEyeColor() const
	{
		BdifEyeColor value;
		NCheck(ANType10RecordGetSubjectEyeColor(GetHandle(), &value));
		return value;
	}

	void SetSubjectEyeColor(BdifEyeColor value)
	{
		NCheck(ANType10RecordSetSubjectEyeColor(GetHandle(), value));
	}

	bool GetSubjectHairColor(ANHairColor * pValue) const
	{
		NBool hasValue;
		NCheck(ANType10RecordGetSubjectHairColorEx(GetHandle(), pValue, &hasValue));
		return hasValue != 0;
	}

	BdifHairColor GetSubjectHairColor() const
	{
		BdifHairColor value;
		NCheck(ANType10RecordGetSubjectHairColor(GetHandle(), &value));
		return value;
	}

	BdifHairColor GetBaldSubjectHairColor() const
	{
		BdifHairColor value;
		NCheck(ANType10RecordGetBaldSubjectHairColor(GetHandle(), &value));
		return value;
	}

	void SetSubjectHairColorEx(const ANHairColor * pValue)
	{
		NCheck(ANType10RecordSetSubjectHairColorEx(GetHandle(), pValue));
	}

	void SetSubjectHairColorEx(BdifHairColor value, BdifHairColor baldValue)
	{
		NCheck(ANType10RecordSetSubjectHairColor(GetHandle(), value, baldValue));
	}

	bool GetSmtSize(::Neurotec::Geometry::NSize * pValue) const
	{
		NBool hasValue;
		NCheck(ANType10RecordGetSmtSize(GetHandle(), pValue, &hasValue));
		return hasValue != 0;
	}

	void SetSmtSize(const ::Neurotec::Geometry::NSize * pValue)
	{
		NCheck(ANType10RecordSetSmtSize(GetHandle(), pValue));
	}

	PhysicalPhotoCharacteristicCollection GetPhysicalPhotoCharacteristics()
	{
		return PhysicalPhotoCharacteristicCollection(*this);
	}

	const PhysicalPhotoCharacteristicCollection GetPhysicalPhotoCharacteristics() const
	{
		return PhysicalPhotoCharacteristicCollection(*this);
	}

	OtherPhotoCharacteristicCollection GetOtherPhotoCharacteristics()
	{
		return OtherPhotoCharacteristicCollection(*this);
	}

	const OtherPhotoCharacteristicCollection GetOtherPhotoCharacteristics() const
	{
		return OtherPhotoCharacteristicCollection(*this);
	}

	SubjectQualityScoreCollection GetSubjectQualityScores()
	{
		return SubjectQualityScoreCollection(*this);
	}

	const SubjectQualityScoreCollection GetSubjectQualityScores() const
	{
		return SubjectQualityScoreCollection(*this);
	}

	SubjectFacialCharacteristicCollection GetSubjectFacialCharacteristics()
	{
		return SubjectFacialCharacteristicCollection(*this);
	}

	const SubjectFacialCharacteristicCollection GetSubjectFacialCharacteristics() const
	{
		return SubjectFacialCharacteristicCollection(*this);
	}

	FacialFeaturePointCollection GetFacialFeaturePoints()
	{
		return FacialFeaturePointCollection(*this);
	}

	const FacialFeaturePointCollection GetFacialFeaturePoints() const
	{
		return FacialFeaturePointCollection(*this);
	}

	NcicDesignationCodeCollection GetNcicDesignationCode()
	{
		return NcicDesignationCodeCollection(*this);
	}

	const NcicDesignationCodeCollection GetNcicDesignationCode() const
	{
		return NcicDesignationCodeCollection(*this);
	}

	SmtCollection GetSmts()
	{
		return SmtCollection(*this);
	}

	const SmtCollection GetSmts() const
	{
		return SmtCollection(*this);
	}

	SmtColorsCollection GetSmtsColors()
	{
		return SmtColorsCollection(*this);
	}

	const SmtColorsCollection GetSmtsColors() const
	{
		return SmtColorsCollection(*this);
	}
};

}}}

#endif // !AN_TYPE_10_RECORD_HPP_INCLUDED
