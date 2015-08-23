#include <Biometrics/Standards/IirIris.hpp>

#ifndef II_RECORD_HPP_INCLUDED
#define II_RECORD_HPP_INCLUDED

#include <Biometrics/Standards/BdifTypes.hpp>
#include <Images/NImage.hpp>
namespace Neurotec { namespace Biometrics { namespace Standards
{
using ::Neurotec::Images::HNImage;
#include <Biometrics/Standards/IIRecord.h>
}}}

N_DEFINE_ENUM_TYPE_TRAITS(Neurotec::Biometrics::Standards, IirIrisOcclusions)
N_DEFINE_ENUM_TYPE_TRAITS(Neurotec::Biometrics::Standards, IirIrisOcclusionFilling)
N_DEFINE_ENUM_TYPE_TRAITS(Neurotec::Biometrics::Standards, IirIrisBoundary)
N_DEFINE_ENUM_TYPE_TRAITS(Neurotec::Biometrics::Standards, IirImageTransformation)

namespace Neurotec { namespace Biometrics { namespace Standards
{
#include <Core/NNoDeprecate.h>

#undef IIR_VERSION_1_0
#undef IIR_VERSION_2_0
#undef IIR_VERSION_ANSI_1_0
#undef IIR_VERSION_ISO_1_0
#undef IIR_VERSION_ISO_2_0
#undef IIR_MAX_IRIS_IMAGE_COUNT
#undef IIR_PROCESS_IRIS_FIRST_IRIS_IMAGE_ONLY

#undef IIR_VERSION_ANSI_CURRENT
#undef IIR_VERSION_ISO_CURRENT

const NVersion N_DEPRECATED("deprecated, use IIR_VERSION_ANSI_1_0 or IIR_VERSION_ISO_1_0 instead.") IIR_VERSION_1_0(0x0100);
const NVersion N_DEPRECATED("deprecated, use IIR_VERSION_ISO_2_0 instead.") IIR_VERSION_2_0(0x0200);

const NVersion IIR_VERSION_ANSI_1_0(0x0100);
const NVersion IIR_VERSION_ISO_1_0(0x0100);
const NVersion IIR_VERSION_ISO_2_0(0x0200);

const NVersion IIR_VERSION_ANSI_CURRENT(IIR_VERSION_ANSI_1_0);
const NVersion IIR_VERSION_ISO_CURRENT(IIR_VERSION_ISO_2_0);

const NInt IIR_MAX_IRIS_IMAGE_COUNT = (2 * IIRI_MAX_IRIS_IMAGE_COUNT);

const NInt IIR_PROCESS_IRIS_FIRST_IRIS_IMAGE_ONLY = 0x00001000;

class IIRecord : public NObject
{
	N_DECLARE_OBJECT_CLASS(IIRecord, NObject)

public:
	class N_DEPRECATED("collection is deprecated, use IrisImageCollection instead.") IrisCollection : public ::Neurotec::Collections::NCollectionBase<IirIris, IIRecord,
		IIRecordGetIrisCount, IIRecordGetIris>
	{
		IrisCollection(const IIRecord & owner)
		{
			SetOwner(owner);
		}

		friend class IIRecord;
	public:
		NInt GetCapacity() const
		{
			NInt value;
			NCheck(IIRecordGetIrisCapacity(this->GetOwnerHandle(), &value));
			return value;
		}

		void SetCapacity(NInt value)
		{
			NCheck(IIRecordSetIrisCapacity(this->GetOwnerHandle(), value));
		}

		void RemoveAt(NInt index)
		{
			NCheck(IIRecordRemoveIrisAt(this->GetOwnerHandle(), index));
		}

		void Clear()
		{
			NCheck(IIRecordClearIrises(this->GetOwnerHandle()));
		}

		IirIris Add(BdifEyePosition irisPosition, NUInt flags = 0)
		{
			HIirIris hIris;
			NCheck(IIRecordAddIris(this->GetOwnerHandle(), irisPosition, flags | N_OBJECT_REF_RET, &hIris));
			return FromHandle<IirIris>(hIris, true);
		}

		IirIris Add(BdifEyePosition irisPosition, const ::Neurotec::Images::NImage & image, ::Neurotec::Biometrics::Standards::IirImageFormat imageFormat, NUInt flags = 0)
		{
			HIirIris hIris;
			NCheck(IIRecordAddIrisFromNImageEx(this->GetOwnerHandle(), irisPosition, image.GetHandle(), imageFormat, flags | N_OBJECT_REF_RET, &hIris));
			return FromHandle<IirIris>(hIris, true);
		}
	};

	class IrisImageCollection : public ::Neurotec::Collections::NCollectionBase<IirIrisImage, IIRecord,
		IIRecordGetIrisImageCount, IIRecordGetIrisImage>
	{
		IrisImageCollection(const IIRecord & owner)
		{
			SetOwner(owner);
		}

		friend class IIRecord;
	public:
		NInt GetCapacity() const
		{
			NInt value;
			NCheck(IIRecordGetIrisImageCapacity(this->GetOwnerHandle(), &value));
			return value;
		}

		void SetCapacity(NInt value)
		{
			NCheck(IIRecordSetIrisImageCapacity(this->GetOwnerHandle(), value));
		}

		NInt Add(const IirIrisImage & value)
		{
			NInt index;
			NCheck(IIRecordAddIrisImageEx(this->GetOwnerHandle(), value.GetHandle(), &index));
			return index;
		}

		void RemoveAt(NInt index)
		{
			NCheck(IIRecordRemoveIrisImageAt(this->GetOwnerHandle(), index));
		}

		void Clear()
		{
			NCheck(IIRecordClearIrisImages(this->GetOwnerHandle()));
		}
	};

private:
	static HIIRecord Create(BdifStandard standard, NVersion version, NUInt flags)
	{
		HIIRecord handle;
		NCheck(IIRecordCreateEx2(standard, version.GetValue(), flags, &handle));
		return handle;
	}

	static HIIRecord Create(const ::Neurotec::IO::NBuffer & buffer, BdifStandard standard, NUInt flags, NSizeType * pSize)
	{
		HIIRecord handle;
		NCheck(IIRecordCreateFromMemoryN(buffer.GetHandle(), flags, standard, pSize, &handle));
		return handle;
	}

	static HIIRecord Create(const void * pBuffer, NSizeType bufferSize, BdifStandard standard, NUInt flags, NSizeType * pSize)
	{
		HIIRecord handle;
		NCheck(IIRecordCreateFromMemory(pBuffer, bufferSize, flags, standard, pSize, &handle));
		return handle;
	}

	static HIIRecord Create(const IIRecord & srcRecord, BdifStandard standard, NVersion version, NUInt flags)
	{
		HIIRecord handle;
		NCheck(IIRecordCreateFromIIRecordEx(srcRecord.GetHandle(), flags, standard, version.GetValue(), &handle));
		return handle;
	}

	static HIIRecord Create(const ::Neurotec::Images::NImage & image, IirImageFormat imageFormat, BdifEyePosition irisPosition, BdifStandard standard, NVersion version, NUInt flags)
	{
		HIIRecord handle;
		NCheck(IIRecordCreateFromNImageEx(image.GetHandle(), imageFormat, irisPosition, flags, standard, version.GetValue(), &handle));
		return handle;
	}

public:
	static NType IirIrisOcclusionsNativeTypeOf()
	{
		return NObject::GetObject<NType>(N_TYPE_OF(IirIrisOcclusions), true);
	}

	static NType IirIrisOcclusionFillingNativeTypeOf()
	{
		return NObject::GetObject<NType>(N_TYPE_OF(IirIrisOcclusionFilling), true);
	}

	static NType IirIrisBoundaryNativeTypeOf()
	{
		return NObject::GetObject<NType>(N_TYPE_OF(IirIrisBoundary), true);
	}

	static NType IirImageTransformationNativeTypeOf()
	{
		return NObject::GetObject<NType>(N_TYPE_OF(IirImageTransformation), true);
	}

	N_DEPRECATED("method is deprecated, use IIRecord(BdifStandard, NVersion, NUInt) instead.")
	IIRecord(NUInt flags = 0)
		: NObject(Create(bsIso, NVersion(2,0), flags), true)
	{
	}

	IIRecord(BdifStandard standard, NVersion version, NUInt flags = 0)
		: NObject(Create(standard, version, flags), true)
	{
	}

	IIRecord(const ::Neurotec::IO::NBuffer & buffer, BdifStandard standard, NUInt flags = 0, NSizeType * pSize = NULL)
		: NObject(Create(buffer, standard, flags, pSize), true)
	{
	}

	IIRecord(const void * pBuffer, NSizeType bufferSize, BdifStandard standard, NUInt flags = 0, NSizeType * pSize = NULL)
		: NObject(Create(pBuffer, bufferSize, standard, flags, pSize), true)
	{
	}

	N_DEPRECATED("method is deprecated, use IIRecord(IIRecord, BdifStandard, NVersion, NUInt) instead.")
	IIRecord(const IIRecord & srcRecord, BdifStandard standard, NUInt flags = 0)
		: NObject(Create(srcRecord, standard, IIR_VERSION_1_0, flags), true)
	{
	}

	IIRecord(const IIRecord & srcRecord, BdifStandard standard, NVersion version, NUInt flags = 0)
		: NObject(Create(srcRecord, standard, version, flags), true)
	{
	}

	IIRecord(const ::Neurotec::Images::NImage & image, IirImageFormat imageFormat, BdifEyePosition irisPosition, 
		BdifStandard standard, NVersion version, NUInt flags = 0)
		: NObject(Create(image, imageFormat, irisPosition, standard, version, flags), true)
	{
	}

	BdifStandard GetStandard() const
	{
		BdifStandard value;
		NCheck(IIRecordGetStandard(GetHandle(), &value));
		return value;
	}

	NVersion GetVersion() const
	{
		NVersion_ value;
		NCheck(IIRecordGetVersion(GetHandle(), &value));
		return NVersion(value);
	}

	NUInt GetCbeffProductId() const
	{
		NUInt value;
		NCheck(IIRecordGetCbeffProductId(GetHandle(), &value));
		return value;
	}

	void SetCbeffProductId(NUInt value)
	{
		NCheck(IIRecordSetCbeffProductId(GetHandle(), value));
	}

	NUShort GetCaptureDeviceId() const
	{
		NUShort value;
		NCheck(IIRecordGetCaptureDeviceId(GetHandle(), &value));
		return value;
	}

	void SetCaptureDeviceId(NUShort value)
	{
		NCheck(IIRecordSetCaptureDeviceId(GetHandle(), value));
	}

	BdifIrisOrientation GetIrisHorzOrientation() const
	{
		BdifIrisOrientation value;
		NCheck(IIRecordGetIrisHorzOrientation(GetHandle(), &value));
		return value;
	}

	void SetIrisHorzOrientation(BdifIrisOrientation value)
	{
		NCheck(IIRecordSetIrisHorzOrientation(GetHandle(), value));
	}

	BdifIrisOrientation GetIrisVertOrientation() const
	{
		BdifIrisOrientation value;
		NCheck(IIRecordGetIrisVertOrientation(GetHandle(), &value));
		return value;
	}

	void SetIrisVertOrientation(BdifIrisOrientation value)
	{
		NCheck(IIRecordSetIrisVertOrientation(GetHandle(), value));
	}

	BdifIrisScanType GetIrisScanType() const
	{
		BdifIrisScanType value;
		NCheck(IIRecordGetIrisScanType(GetHandle(), &value));
		return value;
	}

	void SetIrisScanType(BdifIrisScanType value)
	{
		NCheck(IIRecordSetIrisScanType(GetHandle(), value));
	}

	IirIrisOcclusions GetIrisOcclusions() const
	{
		IirIrisOcclusions value;
		NCheck(IIRecordGetIrisOcclusions(GetHandle(), &value));
		return value;
	}

	void SetIrisOcclusions(IirIrisOcclusions value)
	{
		NCheck(IIRecordSetIrisOcclusions(GetHandle(), value));
	}

	IirIrisOcclusionFilling GetIrisOcclusionFilling() const
	{
		IirIrisOcclusionFilling value;
		NCheck(IIRecordGetIrisOcclusionFilling(GetHandle(), &value));
		return value;
	}

	void SetIrisOcclusionFilling(IirIrisOcclusionFilling value)
	{
		NCheck(IIRecordSetIrisOcclusionFilling(GetHandle(), value));
	}

	IirIrisBoundary GetIrisBoundaryExtraction() const
	{
		IirIrisBoundary value;
		NCheck(IIRecordGetIrisBoundaryExtraction(GetHandle(), &value));
		return value;
	}

	void SetIrisBoundaryExtraction(IirIrisBoundary value)
	{
		NCheck(IIRecordSetIrisBoundaryExtraction(GetHandle(), value));
	}

	NUShort GetIrisDiameter() const
	{
		NUShort value;
		NCheck(IIRecordGetIrisDiameter(GetHandle(), &value));
		return value;
	}

	void SetIrisDiameter(NUShort value)
	{
		NCheck(IIRecordSetIrisDiameter(GetHandle(), value));
	}

	IirImageFormat GetImageFormat() const
	{
		IirImageFormat value;
		NCheck(IIRecordGetImageFormat(GetHandle(), &value));
		return value;
	}

	void SetImageFormat(IirImageFormat value)
	{
		NCheck(IIRecordSetImageFormat(GetHandle(), value));
	}

	NUShort GetRawImageWidth() const
	{
		NUShort value;
		NCheck(IIRecordGetRawImageWidth(GetHandle(), &value));
		return value;
	}

	void SetRawImageWidth(NUShort value)
	{
		NCheck(IIRecordSetRawImageWidth(GetHandle(), value));
	}

	NUShort GetRawImageHeight() const
	{
		NUShort value;
		NCheck(IIRecordGetRawImageHeight(GetHandle(), &value));
		return value;
	}

	void SetRawImageHeight(NUShort value)
	{
		NCheck(IIRecordSetRawImageHeight(GetHandle(), value));
	}

	NByte GetIntensityDepth() const
	{
		NByte value;
		NCheck(IIRecordGetIntensityDepth(GetHandle(), &value));
		return value;
	}

	void SetIntensityDepth(NByte value)
	{
		NCheck(IIRecordSetIntensityDepth(GetHandle(), value));
	}

	IirImageTransformation GetImageTransformation() const
	{
		IirImageTransformation value;
		NCheck(IIRecordGetImageTransformation(GetHandle(), &value));
		return value;
	}

	void SetImageTransformation(IirImageTransformation value)
	{
		NCheck(IIRecordSetImageTransformation(GetHandle(), value));
	}

	NString GetDeviceUniqueIdentifier() const
	{
		return GetString(IIRecordGetDeviceUniqueIdentifierN);
	}

	void SetDeviceUniqueIdentifier(const NStringWrapper & value)
	{
		SetString(IIRecordSetDeviceUniqueIdentifierN, value);
	}

	NGuid GetGuid() const
	{
		NGuid value;
		NCheck(IIRecordGetGuid(GetHandle(), &value));
		return value;
	}

	void SetGuid(NGuid value)
	{
		NCheck(IIRecordSetGuid(GetHandle(), &value));
	}

	N_DEPRECATED("method is deprecated, use GetIrisImages() instead.")
	IrisCollection GetIrises()
	{
		return IrisCollection(*this);
	}

	N_DEPRECATED("method is deprecated, use GetIrisImages() instead.")
	const IrisCollection GetIrises() const
	{
		return IrisCollection(*this);
	}

	IrisImageCollection GetIrisImages()
	{
		return IrisImageCollection(*this);
	}

	const IrisImageCollection GetIrisImages() const
	{
		return IrisImageCollection(*this);
	}
};

#include <Core/NReDeprecate.h>
}}}

#endif // !II_RECORD_HPP_INCLUDED
