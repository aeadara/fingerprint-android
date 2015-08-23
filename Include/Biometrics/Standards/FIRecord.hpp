#include <Biometrics/Standards/FirFinger.hpp>

#ifndef FI_RECORD_HPP_INCLUDED
#define FI_RECORD_HPP_INCLUDED

#include <Biometrics/Standards/BdifTypes.hpp>
#include <Images/NImage.hpp>
namespace Neurotec { namespace Biometrics { namespace Standards
{
using ::Neurotec::Images::HNImage;
#include <Biometrics/Standards/FIRecord.h>
}}}

namespace Neurotec { namespace Biometrics { namespace Standards
{

#undef FIR_VERSION_ANSI_1_0
#undef FIR_VERSION_ANSI_2_5
#undef FIR_VERSION_ISO_1_0
#undef FIR_VERSION_ISO_2_0
#undef FIR_VERSION_ANSI_CURRENT
#undef FIR_VERSION_ISO_CURRENT

#undef FIR_MAX_FINGER_VIEW_COUNT_PER_FINGER
#undef FIR_MAX_FINGER_COUNT_2_0
#undef FIR_MAX_FINGER_VIEW_COUNT_2_0

#undef FIR_MAX_FINGER_COUNT
#undef FIR_MAX_FINGER_VIEW_COUNT

#undef FIR_PROCESS_FIRST_FINGER_ONLY
#undef FIR_PROCESS_FIRST_FINGER_VIEW_ONLY

const NVersion FIR_VERSION_ANSI_1_0(0x0100);
const NVersion FIR_VERSION_ANSI_2_5(0x0205);
const NVersion FIR_VERSION_ISO_1_0(0x0100);
const NVersion FIR_VERSION_ISO_2_0(0x0200);

const NVersion FIR_VERSION_ANSI_CURRENT(FIR_VERSION_ANSI_2_5);
const NVersion FIR_VERSION_ISO_CURRENT(FIR_VERSION_ISO_2_0);

const NInt FIR_MAX_FINGER_VIEW_COUNT_PER_FINGER = 16;

const NInt FIR_MAX_FINGER_COUNT = 255;
const NInt FIR_MAX_FINGER_VIEW_COUNT = (FIR_MAX_FINGER_COUNT * FIRF_MAX_FINGER_VIEW_COUNT);

const NInt FIR_MAX_FINGER_COUNT_2_0 = 42;
const NInt FIR_MAX_FINGER_VIEW_COUNT_2_0 = (FIR_MAX_FINGER_COUNT_2_0 * FIR_MAX_FINGER_VIEW_COUNT_PER_FINGER);

const NUInt FIR_PROCESS_FIRST_FINGER_ONLY = 0x00000100;
const NUInt FIR_PROCESS_FIRST_FINGER_VIEW_ONLY = (FIR_PROCESS_FIRST_FINGER_ONLY | FIRF_PROCESS_FIRST_FINGER_VIEW_ONLY);

#include <Core/NNoDeprecate.h>
class FIRecord : public NObject
{
	N_DECLARE_OBJECT_CLASS(FIRecord, NObject)

public:
	class N_DEPRECATED("collection is deprecated, use FingerViewCollection instead.") FingerCollection : public ::Neurotec::Collections::NCollectionBase<FirFinger, FIRecord,
		FIRecordGetFingerCount, FIRecordGetFingerEx>
	{
		FingerCollection(const FIRecord & owner)
		{
			SetOwner(owner);
		}

		friend class FIRecord;
	public:
		NInt GetCapacity() const
		{
			NInt value;
			NCheck(FIRecordGetFingerCapacity(this->GetOwnerHandle(), &value));
			return value;
		}

		void SetCapacity(NInt value)
		{
			NCheck(FIRecordSetFingerCapacity(this->GetOwnerHandle(), value));
		}

		void RemoveAt(NInt index)
		{
			NCheck(FIRecordRemoveFinger(this->GetOwnerHandle(), index));
		}

		void Clear()
		{
			NCheck(FIRecordClearFingers(this->GetOwnerHandle()));
		}

		FirFinger Add(BdifFPPosition fingerPosition, NUInt flags = 0)
		{
			HFirFinger hFinger;
			NCheck(FIRecordAddFinger(this->GetOwnerHandle(), fingerPosition, flags | N_OBJECT_REF_RET, &hFinger));
			return FromHandle<FirFinger>(hFinger, true);
		}

		FirFinger Add(BdifFPPosition fingerPosition, const ::Neurotec::Images::NImage & image, NUInt flags = 0)
		{
			HFirFinger hFinger;
			NCheck(FIRecordAddFingerFromNImage(this->GetOwnerHandle(), fingerPosition, image.GetHandle(), flags | N_OBJECT_REF_RET, &hFinger));
			return FromHandle<FirFinger>(hFinger, true);
		}
	};

	class FingerViewCollection : public ::Neurotec::Collections::NCollectionBase<FirFingerView, FIRecord,
		FIRecordGetFingerViewCount, FIRecordGetFingerView>
	{
		FingerViewCollection(const FIRecord & owner)
		{
			SetOwner(owner);
		}

		friend class FIRecord;
	public:
		NInt GetCapacity() const
		{
			NInt value;
			NCheck(FIRecordGetFingerViewCapacity(this->GetOwnerHandle(), &value));
			return value;
		}

		void SetCapacity(NInt value)
		{
			NCheck(FIRecordSetFingerViewCapacity(this->GetOwnerHandle(), value));
		}

		NInt Add(const FirFingerView & value)
		{
			NInt index;
			NCheck(FIRecordAddFingerView(this->GetOwnerHandle(), value.GetHandle(), &index));
			return index;
		}

		void RemoveAt(NInt index)
		{
			NCheck(FIRecordRemoveFingerViewAt(this->GetOwnerHandle(), index));
		}

		void Clear()
		{
			NCheck(FIRecordClearFingerViews(this->GetOwnerHandle()));
		}
	};

private:
	static HFIRecord Create(BdifStandard standard, NVersion version, NUInt flags)
	{
		HFIRecord handle;
		NCheck(FIRecordCreateEx(standard, version.GetValue(), flags, &handle));
		return handle;
	}

	static HFIRecord Create(NUShort imageAcquisitionLevel, BdifScaleUnits scaleUnits,
		NUShort horzScanResolution, NUShort vertScanResolution, NUShort horzImageResolution, NUShort vertImageResolution,
		NByte pixelDepth, FirImageCompressionAlgorithm imageCompressionAlgorithm, BdifStandard standard, NUInt flags)
	{
		HFIRecord handle;
		NCheck(FIRecordCreate(imageAcquisitionLevel, scaleUnits,
			horzScanResolution, vertScanResolution, horzImageResolution, vertImageResolution,
			pixelDepth, imageCompressionAlgorithm, flags, standard, &handle));
		return handle;
	}

	static HFIRecord Create(const ::Neurotec::IO::NBuffer & buffer, BdifStandard standard, NUInt flags, NSizeType * pSize)
	{
		HFIRecord handle;
		NCheck(FIRecordCreateFromMemoryN(buffer.GetHandle(), flags, standard, pSize, &handle));
		return handle;
	}

	static HFIRecord Create(const void * pBuffer, NSizeType bufferSize, BdifStandard standard, NUInt flags, NSizeType * pSize)
	{
		HFIRecord handle;
		NCheck(FIRecordCreateFromMemory(pBuffer, bufferSize, flags, standard, pSize, &handle));
		return handle;
	}

	static HFIRecord Create(const FIRecord & srcRecord, BdifStandard standard, NUInt flags)
	{
		HFIRecord handle;
		NCheck(FIRecordCreateFromFIRecord(srcRecord.GetHandle(), flags, standard, &handle));
		return handle;
	}

	static HFIRecord Create(const FIRecord & srcRecord, BdifStandard standard, NVersion version, NUInt flags)
	{
		HFIRecord handle;
		NCheck(FIRecordCreateFromFIRecordEx(srcRecord.GetHandle(), flags, standard, version.GetValue(), &handle));
		return handle;
	}

	static HFIRecord Create(const ::Neurotec::Images::NImage & image, NUShort imageAcquisitionLevel, BdifScaleUnits scaleUnits, NUShort horzScanResolution, NUShort vertScanResolution,
		NByte pixelDepth, FirImageCompressionAlgorithm imageCompressionAlgorithm, BdifFPPosition fingerPosition, BdifStandard standard, NUInt flags)
	{
		HFIRecord handle;
		NCheck(FIRecordCreateFromNImage(image.GetHandle(), imageAcquisitionLevel, scaleUnits, horzScanResolution, vertScanResolution,
			pixelDepth, imageCompressionAlgorithm, fingerPosition, flags, standard, &handle));
		return handle;
	}

	static HFIRecord Create(const ::Neurotec::Images::NImage & image, NUShort imageAcquisitionLevel, BdifScaleUnits scaleUnits, NUShort horzScanResolution, NUShort vertScanResolution,
		NByte pixelDepth, FirImageCompressionAlgorithm imageCompressionAlgorithm, BdifFPPosition fingerPosition, BdifStandard standard, NVersion version, NUInt flags)
	{
		HFIRecord handle;
		NCheck(FIRecordCreateFromNImageEx(image.GetHandle(), imageAcquisitionLevel, scaleUnits, horzScanResolution, vertScanResolution,
			pixelDepth, imageCompressionAlgorithm, fingerPosition, flags, standard, version.GetValue(), &handle));
		return handle;
	}

public:
	static NType FirImageCompressionAlgorithmNativeTypeOf()
	{
		return NObject::GetObject<NType>(N_TYPE_OF(FirImageCompressionAlgorithm), true);
	}

	N_DEPRECATED("method is deprecated, use GetSize() instead.")
	static NSizeType CalculateSize(BdifStandard standard, const NSizeType * arFingerViewSizes, NInt fingerViewCount)
	{
		NSizeType size;
		NCheck(FIRecordCalculateSize(standard, fingerViewCount, arFingerViewSizes, &size));
		return size;
	}

	N_DEPRECATED("method is deprecated, use GetSize() instead.")
	static NSizeType CalculateSizeWithFingers(BdifStandard standard, const NSizeType * arFingerSizes, NInt fingerCount)
	{
		NSizeType size;
		NCheck(FIRecordCalculateSize(standard, fingerCount, arFingerSizes, &size));
		return size;
	}

	N_DEPRECATED("method is deprecated, use FIRecord(NUInt), SetVersion, SetStandard, SetImageAcquisitionLevel, SetScaleUnits, SetHorzScanResolution, SetVertScanResolution, SetHorzImageResolution, SetVertImageResolution, SetPixelDepth, SetImageCompressionAlgorithm instead.")
	FIRecord(NUShort imageAcquisitionLevel, BdifScaleUnits scaleUnits,
		NUShort horzScanResolution, NUShort vertScanResolution, NUShort horzImageResolution, NUShort vertImageResolution,
		NByte pixelDepth, FirImageCompressionAlgorithm imageCompressionAlgorithm, BdifStandard standard, NUInt flags = 0)
		: NObject(Create(imageAcquisitionLevel, scaleUnits, horzScanResolution, vertScanResolution, horzImageResolution, vertImageResolution,
			pixelDepth, imageCompressionAlgorithm, standard, flags), true)
	{
	}

	explicit FIRecord(BdifStandard standard, NVersion version, NUInt flags = 0)
		: NObject(Create(standard, version, flags), true)
	{
	}

	FIRecord(const ::Neurotec::IO::NBuffer & buffer, BdifStandard standard, NUInt flags = 0, NSizeType * pSize = NULL)
		: NObject(Create(buffer, standard, flags, pSize), true)
	{
	}

	FIRecord(const void * pBuffer, NSizeType bufferSize, BdifStandard standard, NUInt flags = 0, NSizeType * pSize = NULL)
		: NObject(Create(pBuffer, bufferSize, standard, flags, pSize), true)
	{
	}

	N_DEPRECATED("method is deprecated, use FIRecord(FIRecord, BdifStandard, NVersion, NUInt) instead.")
	FIRecord(const FIRecord & srcRecord, BdifStandard standard, NUInt flags = 0)
		: NObject(Create(srcRecord, standard, flags), true)
	{
	}

	FIRecord(const FIRecord & srcRecord, BdifStandard standard, NVersion version, NUInt flags = 0)
		: NObject(Create(srcRecord, standard, version, flags), true)
	{
	}

	N_DEPRECATED("method is deprecated, use FIRecord(NImage, NUShort, BdifScaleUnits, NUShort, NUShort, NByte, FirImageCompressionAlgorithm, BdifFPPosition, BdifStandard, NVersion, NUInt) instead.")
	FIRecord(const ::Neurotec::Images::NImage & image, NUShort imageAcquisitionLevel, BdifScaleUnits scaleUnits, NUShort horzScanResolution, NUShort vertScanResolution,
		NByte pixelDepth, FirImageCompressionAlgorithm imageCompressionAlgorithm, BdifFPPosition fingerPosition, BdifStandard standard, NUInt flags = 0)
		: NObject(Create(image, imageAcquisitionLevel, scaleUnits, horzScanResolution, vertScanResolution, pixelDepth, imageCompressionAlgorithm,
			fingerPosition, standard, flags), true)
	{
	}

	FIRecord(const ::Neurotec::Images::NImage & image, NUShort imageAcquisitionLevel, BdifScaleUnits scaleUnits, NUShort horzScanResolution, NUShort vertScanResolution,
		NByte pixelDepth, FirImageCompressionAlgorithm imageCompressionAlgorithm, BdifFPPosition fingerPosition, BdifStandard standard, NVersion version, NUInt flags = 0)
		: NObject(Create(image, imageAcquisitionLevel, scaleUnits, horzScanResolution, vertScanResolution, pixelDepth, imageCompressionAlgorithm,
			fingerPosition, standard, version, flags), true)
	{
	}

	BdifStandard GetStandard() const
	{
		BdifStandard value;
		NCheck(FIRecordGetStandard(GetHandle(), &value));
		return value;
	}

	NVersion GetVersion() const
	{
		NVersion_ value;
		NCheck(FIRecordGetVersion(GetHandle(), &value));
		return NVersion(value);
	}

	NBool GetCertificationFlag() const
	{
		NBool value;
		NCheck(FIRecordGetCertificationFlag(GetHandle(), &value));
		return value;
	}

	void SetCertificationFlag(const NBool value)
	{
		NCheck(FIRecordSetCertificationFlag(GetHandle(), value));
	}

	NUInt GetCbeffProductId() const
	{
		NUInt value;
		NCheck(FIRecordGetCbeffProductId(GetHandle(), &value));
		return value;
	}

	void SetCbeffProductId(NUInt value)
	{
		NCheck(FIRecordSetCbeffProductId(GetHandle(), value));
	}

	NUShort GetCaptureDeviceId() const
	{
		NUShort value;
		NCheck(FIRecordGetCaptureDeviceId(GetHandle(), &value));
		return value;
	}

	void SetCaptureDeviceId(NUShort value)
	{
		NCheck(FIRecordSetCaptureDeviceId(GetHandle(), value));
	}

	NUShort GetImageAcquisitionLevel() const
	{
		NUShort value;
		NCheck(FIRecordGetImageAcquisitionLevel(GetHandle(), &value));
		return value;
	}

	void SetImageAcquisitionLevel(NUShort value)
	{
		NCheck(FIRecordSetImageAcquisitionLevel(GetHandle(), value));
	}

	BdifScaleUnits GetScaleUnits() const
	{
		BdifScaleUnits value;
		NCheck(FIRecordGetScaleUnits(GetHandle(), &value));
		return value;
	}

	void SetScaleUnits(BdifScaleUnits value)
	{
		NCheck(FIRecordSetScaleUnits(GetHandle(), value));
	}

	NUShort GetHorzScanResolution() const
	{
		NUShort value;
		NCheck(FIRecordGetHorzScanResolution(GetHandle(), &value));
		return value;
	}

	void SetHorzScanResolution(NUShort value)
	{
		NCheck(FIRecordSetHorzScanResolution(GetHandle(), value));
	}

	NUShort GetVertScanResolution() const
	{
		NUShort value;
		NCheck(FIRecordGetVertScanResolution(GetHandle(), &value));
		return value;
	}

	void SetVertScanResolution(NUShort value)
	{
		NCheck(FIRecordSetVertScanResolution(GetHandle(), value));
	}

	NUShort GetHorzImageResolution() const
	{
		NUShort value;
		NCheck(FIRecordGetHorzImageResolution(GetHandle(), &value));
		return value;
	}

	void SetHorzImageResolution(NUShort value)
	{
		NCheck(FIRecordSetHorzImageResolution(GetHandle(), value));
	}

	NUShort GetVertImageResolution() const
	{
		NUShort value;
		NCheck(FIRecordGetVertImageResolution(GetHandle(), &value));
		return value;
	}

	void SetVertImageResolution(NUShort value)
	{
		NCheck(FIRecordSetVertImageResolution(GetHandle(), value));
	}

	NByte GetPixelDepth() const
	{
		NByte value;
		NCheck(FIRecordGetPixelDepth(GetHandle(), &value));
		return value;
	}

	void SetPixelDepth(NByte value)
	{
		NCheck(FIRecordSetPixelDepth(GetHandle(), value));
	}

	FirImageCompressionAlgorithm GetImageCompressionAlgorithm() const
	{
		FirImageCompressionAlgorithm value;
		NCheck(FIRecordGetImageCompressionAlgorithm(GetHandle(), &value));
		return value;
	}

	void SetImageCompressionAlgorithm(FirImageCompressionAlgorithm value)
	{
		NCheck(FIRecordSetImageCompressionAlgorithm(GetHandle(), value));
	}

	N_DEPRECATED("method is deprecated, use GetFingerViews() instead.")
	FingerCollection GetFingers()
	{
		return FingerCollection(*this);
	}

	N_DEPRECATED("method is deprecated, use GetFingerViews() instead.")
	const FingerCollection GetFingers() const
	{
		return FingerCollection(*this);
	}

	FingerViewCollection GetFingerViews()
	{
		return FingerViewCollection(*this);
	}

	const FingerViewCollection GetFingerViews() const
	{
		return FingerViewCollection(*this);
	}
};
#include <Core/NReDeprecate.h>

}}}

#endif // !FI_RECORD_HPP_INCLUDED
