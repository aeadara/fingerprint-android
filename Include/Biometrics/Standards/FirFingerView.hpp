#ifndef FIR_FINGER_VIEW_HPP_INCLUDED
#define FIR_FINGER_VIEW_HPP_INCLUDED

#include <Biometrics/Standards/BdifTypes.hpp>
#include <Images/NImage.hpp>

namespace Neurotec { namespace Biometrics { namespace Standards
{
using ::Neurotec::Images::HNImage;
using ::Neurotec::Geometry::NPoint;
#include <Biometrics/Standards/FirFingerView.h>
}}}

N_DEFINE_ENUM_TYPE_TRAITS(Neurotec::Biometrics::Standards, FirImageCompressionAlgorithm)

namespace Neurotec { namespace Biometrics { namespace Standards
{
#include <Core/NNoDeprecate.h>
class FirFingerView;

class FirFingerViewSegment : public NObject
{
	N_DECLARE_OBJECT_CLASS(FirFingerViewSegment, NObject)
public:
	class CoordinateCollection : public ::Neurotec::Collections::NCollectionWithAllOutBase< ::Neurotec::Geometry::NPoint, FirFingerViewSegment,
		FirFingerViewSegmentGetCoordinateCount, FirFingerViewSegmentGetCoordinate, FirFingerViewSegmentGetCoordinates>
	{
		CoordinateCollection(const FirFingerViewSegment & owner)
		{
			SetOwner(owner);
		}

		friend class FirFingerViewSegment;
	public:
		NInt GetCapacity() const
		{
			NInt value;
			NCheck(FirFingerViewSegmentGetCoordinateCapacity(this->GetOwnerHandle(), &value));
			return value;
		}

		void SetCapacity(NInt value)
		{
			NCheck(FirFingerViewSegmentSetCoordinateCapacity(this->GetOwnerHandle(), value));
		}
	
		void Set(NInt index, const ::Neurotec::Geometry::NPoint & value)
		{
			NCheck(FirFingerViewSegmentSetCoordinate(this->GetOwnerHandle(), index, &value));
		}

		NInt Add(const ::Neurotec::Geometry::NPoint & value)
		{
			NInt index;
			NCheck(FirFingerViewSegmentAddCoordinate(this->GetOwnerHandle(), &value, &index));
			return index;
		}

		void Insert(NInt index, const ::Neurotec::Geometry::NPoint & value)
		{
			NCheck(FirFingerViewSegmentInsertCoordinate(this->GetOwnerHandle(), index, &value));
		}

		void RemoveAt(NInt index)
		{
			NCheck(FirFingerViewSegmentRemoveCoordinateAt(this->GetOwnerHandle(), index));
		}

		void Clear()
		{
			NCheck(FirFingerViewSegmentClearCoordinates(this->GetOwnerHandle()));
		}
	};

private:
	static HFirFingerViewSegment Create()
	{
		HFirFingerViewSegment handle;
		NCheck(FirFingerViewSegmentCreate(&handle));
		return handle;
	}

public:
	FirFingerViewSegment()
		: NObject(Create(), true)
	{
	}

	BdifFPPosition GetFingerPosition() const
	{
		BdifFPPosition value;
		NCheck(FirFingerViewSegmentGetFingerPosition(GetHandle(), &value));
		return value;
	}

	void SetFingerPosition(BdifFPPosition value)
	{
		NCheck(FirFingerViewSegmentSetFingerPosition(GetHandle(), value));
	}

	NByte GetFingerQuality() const
	{
		NByte value;
		NCheck(FirFingerViewSegmentGetFingerQuality(GetHandle(), &value));
		return value;
	}

	void SetFingerQuality(NByte value)
	{
		NCheck(FirFingerViewSegmentSetFingerQuality(GetHandle(), value));
	}

	NByte GetFingerOrientation() const
	{
		NByte value;
		NCheck(FirFingerViewSegmentGetFingerOrientation(GetHandle(), &value));
		return value;
	}

	void SetFingerOrientation(NByte value)
	{
		NCheck(FirFingerViewSegmentSetFingerOrientation(GetHandle(), value));
	}

	FirFingerView GetOwner() const;
};

}}}


namespace Neurotec { namespace Biometrics { namespace Standards
{

class FIRecord;

class FirFingerView : public NObject
{
	N_DECLARE_OBJECT_CLASS(FirFingerView, NObject)
public:
	class QualityBlockCollection : public ::Neurotec::Collections::NCollectionWithAllOutBase<BdifQualityBlock, FirFingerView,
		FirFingerViewGetQualityBlockCount, FirFingerViewGetQualityBlock, FirFingerViewGetQualityBlocks>
	{
		QualityBlockCollection(const FirFingerView & owner)
		{
			SetOwner(owner);
		}

		friend class FirFingerView;
	public:
		NInt GetCapacity() const
		{
			NInt value;
			NCheck(FirFingerViewGetQualityBlockCapacity(this->GetOwnerHandle(), &value));
			return value;
		}

		void SetCapacity(NInt value)
		{
			NCheck(FirFingerViewSetQualityBlockCapacity(this->GetOwnerHandle(), value));
		}
	
		void Set(NInt index, const BdifQualityBlock & value)
		{
			NCheck(FirFingerViewSetQualityBlock(this->GetOwnerHandle(), index, &value));
		}

		NInt Add(const BdifQualityBlock & value)
		{
			NInt index;
			NCheck(FirFingerViewAddQualityBlock(this->GetOwnerHandle(), &value, &index));
			return index;
		}

		void Insert(NInt index, const BdifQualityBlock & value)
		{
			NCheck(FirFingerViewInsertQualityBlock(this->GetOwnerHandle(), index, &value));
		}

		void RemoveAt(NInt index)
		{
			NCheck(FirFingerViewRemoveQualityBlockAt(this->GetOwnerHandle(), index));
		}

		void Clear()
		{
			NCheck(FirFingerViewClearQualityBlocks(this->GetOwnerHandle()));
		}
	};

	class CertificationBlockCollection : public ::Neurotec::Collections::NCollectionWithAllOutBase<BdifCertificationBlock, FirFingerView,
		FirFingerViewGetCertificationBlockCount, FirFingerViewGetCertificationBlock, FirFingerViewGetCertificationBlocks>
	{
		CertificationBlockCollection(const FirFingerView & owner)
		{
			SetOwner(owner);
		}

		friend class FirFingerView;
	public:
		NInt GetCapacity() const
		{
			NInt value;
			NCheck(FirFingerViewGetCertificationBlockCapacity(this->GetOwnerHandle(), &value));
			return value;
		}

		void SetCapacity(NInt value)
		{
			NCheck(FirFingerViewSetCertificationBlockCapacity(this->GetOwnerHandle(), value));
		}
	
		void Set(NInt index, const BdifCertificationBlock & value)
		{
			NCheck(FirFingerViewSetCertificationBlock(this->GetOwnerHandle(), index, &value));
		}

		NInt Add(const BdifCertificationBlock & value)
		{
			NInt index;
			NCheck(FirFingerViewAddCertificationBlock(this->GetOwnerHandle(), &value, &index));
			return index;
		}

		void Insert(NInt index, const BdifCertificationBlock & value)
		{
			NCheck(FirFingerViewInsertCertificationBlock(this->GetOwnerHandle(), index, &value));
		}

		void RemoveAt(NInt index)
		{
			NCheck(FirFingerViewRemoveCertificationBlockAt(this->GetOwnerHandle(), index));
		}

		void Clear()
		{
			NCheck(FirFingerViewClearCertificationBlocks(this->GetOwnerHandle()));
		}
	};

	class FingerSegmentCollection : public ::Neurotec::Collections::NCollectionWithAllOutBase<FirFingerViewSegment, FirFingerView,
		FirFingerViewGetFingerSegmentCount, FirFingerViewGetFingerSegment, FirFingerViewGetFingerSegments>
	{
		FingerSegmentCollection(const FirFingerView & owner)
		{
			SetOwner(owner);
		}

		friend class FirFingerView;
	public:
		NInt GetCapacity() const
		{
			NInt value;
			NCheck(FirFingerViewGetFingerSegmentCapacity(this->GetOwnerHandle(), &value));
			return value;
		}

		void SetCapacity(NInt value)
		{
			NCheck(FirFingerViewSetFingerSegmentCapacity(this->GetOwnerHandle(), value));
		}
	
		void Set(NInt index, const FirFingerViewSegment & value)
		{
			NCheck(FirFingerViewSetFingerSegment(this->GetOwnerHandle(), index, value.GetHandle()));
		}

		NInt Add(const FirFingerViewSegment & value)
		{
			NInt index;
			NCheck(FirFingerViewAddFingerSegment(this->GetOwnerHandle(), value.GetHandle(), &index));
			return index;
		}

		void Insert(NInt index, const FirFingerViewSegment & value)
		{
			NCheck(FirFingerViewInsertFingerSegment(this->GetOwnerHandle(), index, value.GetHandle()));
		}

		void RemoveAt(NInt index)
		{
			NCheck(FirFingerViewRemoveFingerSegmentAt(this->GetOwnerHandle(), index));
		}

		void Clear()
		{
			NCheck(FirFingerViewClearFingerSegments(this->GetOwnerHandle()));
		}
	};

	class AnnotationCollection : public ::Neurotec::Collections::NCollectionWithAllOutBase<BdifFPAnnotation, FirFingerView,
		FirFingerViewGetAnnotationCount, FirFingerViewGetAnnotation, FirFingerViewGetAnnotations>
	{
		AnnotationCollection(const FirFingerView & owner)
		{
			SetOwner(owner);
		}

		friend class FirFingerView;
	public:
		NInt GetCapacity() const
		{
			NInt value;
			NCheck(FirFingerViewGetAnnotationCapacity(this->GetOwnerHandle(), &value));
			return value;
		}

		void SetCapacity(NInt value)
		{
			NCheck(FirFingerViewSetAnnotationCapacity(this->GetOwnerHandle(), value));
		}
	
		void Set(NInt index, const BdifFPAnnotation & value)
		{
			NCheck(FirFingerViewSetAnnotation(this->GetOwnerHandle(), index, &value));
		}

		NInt Add(const BdifFPAnnotation & value)
		{
			NInt index;
			NCheck(FirFingerViewAddAnnotation(this->GetOwnerHandle(), &value, &index));
			return index;
		}

		void Insert(NInt index, const BdifFPAnnotation & value)
		{
			NCheck(FirFingerViewInsertAnnotation(this->GetOwnerHandle(), index, &value));
		}

		void RemoveAt(NInt index)
		{
			NCheck(FirFingerViewRemoveAnnotationAt(this->GetOwnerHandle(), index));
		}

		void Clear()
		{
			NCheck(FirFingerViewClearAnnotations(this->GetOwnerHandle()));
		}
	};

	class VendorExtendedDataCollection : public ::Neurotec::Collections::NCollectionWithAllOutBase<BdifFPExtendedData, FirFingerView,
		FirFingerViewGetVendorExtendedDataCount, FirFingerViewGetVendorExtendedData, FirFingerViewGetVendorExtendedDatas>
	{
		VendorExtendedDataCollection(const FirFingerView & owner)
		{
			SetOwner(owner);
		}

		friend class FirFingerView;
	public:
		NInt GetCapacity() const
		{
			NInt value;
			NCheck(FirFingerViewGetVendorExtendedDataCapacity(this->GetOwnerHandle(), &value));
			return value;
		}

		void SetCapacity(NInt value)
		{
			NCheck(FirFingerViewSetVendorExtendedDataCapacity(this->GetOwnerHandle(), value));
		}
	
		void Set(NInt index, const BdifFPExtendedData & value)
		{
			NCheck(FirFingerViewSetVendorExtendedData(this->GetOwnerHandle(), index, &value));
		}

		NInt Add(const BdifFPExtendedData & value)
		{
			NInt index;
			NCheck(FirFingerViewAddVendorExtendedData(this->GetOwnerHandle(), &value, &index));
			return index;
		}

		void Insert(NInt index, const BdifFPExtendedData & value)
		{
			NCheck(FirFingerViewInsertVendorExtendedData(this->GetOwnerHandle(), index, &value));
		}

		void RemoveAt(NInt index)
		{
			NCheck(FirFingerViewRemoveVendorExtendedDataAt(this->GetOwnerHandle(), index));
		}

		void Clear()
		{
			NCheck(FirFingerViewClearVendorExtendedData(this->GetOwnerHandle()));
		}
	};

private:
	static HFirFingerView Create(BdifStandard standard, NVersion version)
	{
		HFirFingerView handle;
		NCheck(FirFingerViewCreate(standard, version.GetValue(), &handle));
		return handle;
	}

public:
	N_DEPRECATED("method is deprecated, use GetSize() instead.")
	static NSizeType CalculateSize(BdifStandard standard, NSizeType imageDataLength)
	{
		NSizeType size;
		NCheck(FirFingerViewCalculateSize(standard, imageDataLength, &size));
		return size;
	}

	explicit FirFingerView(BdifStandard standard, NVersion version)
		: NObject(Create(standard, version), true)
	{
	}

	::Neurotec::Images::NImage ToNImage(NUInt flags = 0) const
	{
		HNImage hImage;
		NCheck(FirFingerViewToNImage(GetHandle(), flags, &hImage));
		return FromHandle< ::Neurotec::Images::NImage>(hImage);
	}

	void SetImage(const ::Neurotec::Images::NImage & image, NUInt flags = 0)
	{
		NCheck(FirFingerViewSetImage(GetHandle(), flags, image.GetHandle()));
	}

	BdifStandard GetStandard() const
	{
		BdifStandard value;
		NCheck(FirFingerViewGetStandard(GetHandle(), &value));
		return value;
	}

	NVersion GetVersion() const
	{
		NVersion_ value;
		NCheck(FirFingerViewGetVersion(GetHandle(), &value));
		return NVersion(value);
	}

	BdifCaptureDateTime GetCaptureDateAndTime() const
	{
		BdifCaptureDateTime_ value;
		NCheck(FirFingerViewGetCaptureDateAndTime(GetHandle(), &value));
		return BdifCaptureDateTime(value);
	}

	void SetCaptureDateAndTime(const BdifCaptureDateTime & value)
	{
		NCheck(FirFingerViewSetCaptureDateAndTime(GetHandle(), value));
	}

	BdifFPCaptureDeviceTechnology GetCaptureDeviceTechnology() const
	{
		BdifFPCaptureDeviceTechnology value;
		NCheck(FirFingerViewGetCaptureDeviceTechnology(GetHandle(), &value));
		return value;
	}

	void SetCaptureDeviceTechnology(BdifFPCaptureDeviceTechnology value)
	{
		NCheck(FirFingerViewSetCaptureDeviceTechnology(GetHandle(), value));
	}

	NUShort GetCaptureDeviceVendorId() const
	{
		NUShort value;
		NCheck(FirFingerViewGetCaptureDeviceVendorId(GetHandle(), &value));
		return value;
	}

	void SetCaptureDeviceVendorId(NUShort value)
	{
		NCheck(FirFingerViewSetCaptureDeviceVendorId(GetHandle(), value));
	}

	NUShort GetCaptureDeviceTypeId() const
	{
		NUShort value;
		NCheck(FirFingerViewGetCaptureDeviceTypeId(GetHandle(), &value));
		return value;
	}

	void SetCaptureDeviceTypeId(NUShort value)
	{
		NCheck(FirFingerViewSetCaptureDeviceTypeId(GetHandle(), value));
	}
	
	BdifFPPosition GetPosition() const
	{
		BdifFPPosition value;
		NCheck(FirFingerViewGetPosition(GetHandle(), &value));
		return value;
	}

	void SetPosition(BdifFPPosition value)
	{
		NCheck(FirFingerViewSetPosition(GetHandle(), value));
	}

	N_DEPRECATED("method is deprecated")
	NInt GetViewCount() const
	{
		NInt value;
		NCheck(FirFingerViewGetViewCount(GetHandle(), &value));
		return value;
	}

	NInt GetViewNumber() const
	{
		NInt value;
		NCheck(FirFingerViewGetViewNumber(GetHandle(), &value));
		return value;
	}

	NByte GetImageQuality() const
	{
		NByte value;
		NCheck(FirFingerViewGetImageQuality(GetHandle(), &value));
		return value;
	}

	void SetImageQuality(NByte value)
	{
		NCheck(FirFingerViewSetImageQuality(GetHandle(), value));
	}

	BdifFPImpressionType GetImpressionType() const
	{
		BdifFPImpressionType value;
		NCheck(FirFingerViewGetImpressionType(GetHandle(), &value));
		return value;
	}

	void SetImpressionType(BdifFPImpressionType value)
	{
		NCheck(FirFingerViewSetImpressionType(GetHandle(), value));
	}

	NUShort GetHorzLineLength() const
	{
		NUShort value;
		NCheck(FirFingerViewGetHorzLineLength(GetHandle(), &value));
		return value;
	}

	void SetHorzLineLength(NUShort value)
	{
		NCheck(FirFingerViewSetHorzLineLength(GetHandle(), value));
	}

	NUShort GetVertLineLength() const
	{
		NUShort value;
		NCheck(FirFingerViewGetVertLineLength(GetHandle(), &value));
		return value;
	}

	void SetVertLineLength(NUShort value)
	{
		NCheck(FirFingerViewSetVertLineLength(GetHandle(), value));
	}

	::Neurotec::IO::NBuffer GetImageData() const
	{
		return GetObject<HandleType, ::Neurotec::IO::NBuffer>(FirFingerViewGetImageDataN, true);
	}

	void SetImageData(const ::Neurotec::IO::NBuffer & value)
	{
		SetObject(FirFingerViewSetImageDataN, value);
	}

	void SetImageData(const void * pValue, NSizeType valueSize, bool copy = true)
	{
		NCheck(FirFingerViewSetImageDataEx(GetHandle(), pValue, valueSize, copy ? NTrue : NFalse));
	}

	BdifScaleUnits GetScaleUnits() const
	{
		BdifScaleUnits value;
		NCheck(FirFingerViewGetScaleUnits(GetHandle(), &value));
		return value;
	}

	void SetScaleUnits(BdifScaleUnits value)
	{
		NCheck(FirFingerViewSetScaleUnits(GetHandle(), value));
	}

	NUShort GetHorzScanResolution() const
	{
		NUShort value;
		NCheck(FirFingerViewGetHorzScanResolution(GetHandle(), &value));
		return value;
	}

	void SetHorzScanResolution(NUShort value)
	{
		NCheck(FirFingerViewSetHorzScanResolution(GetHandle(), value));
	}

	NUShort GetVertScanResolution() const
	{
		NUShort value;
		NCheck(FirFingerViewGetVertScanResolution(GetHandle(), &value));
		return value;
	}

	void SetVertScanResolution(NUShort value)
	{
		NCheck(FirFingerViewSetVertScanResolution(GetHandle(), value));
	}

	NUShort GetHorzImageResolution() const
	{
		NUShort value;
		NCheck(FirFingerViewGetHorzImageResolution(GetHandle(), &value));
		return value;
	}

	void SetHorzImageResolution(NUShort value)
	{
		NCheck(FirFingerViewSetHorzImageResolution(GetHandle(), value));
	}

	NUShort GetVertImageResolution() const
	{
		NUShort value;
		NCheck(FirFingerViewGetVertImageResolution(GetHandle(), &value));
		return value;
	}

	void SetVertImageResolution(NUShort value)
	{
		NCheck(FirFingerViewSetVertImageResolution(GetHandle(), value));
	}

	NByte GetPixelDepth() const
	{
		NByte value;
		NCheck(FirFingerViewGetPixelDepth(GetHandle(), &value));
		return value;
	}

	void SetPixelDepth(NByte value)
	{
		NCheck(FirFingerViewSetPixelDepth(GetHandle(), value));
	}

	BdifFPSegmentationStatus GetSegmentationStatus() const
	{
		BdifFPSegmentationStatus value;
		NCheck(FirFingerViewGetSegmentationStatus(GetHandle(), &value));
		return value;
	}

	void SetSegmentationStatus(BdifFPSegmentationStatus value)
	{
		NCheck(FirFingerViewSetSegmentationStatus(GetHandle(), value));
	}

	NUShort GetSegmentationOwnerId() const
	{
		NUShort value;
		NCheck(FirFingerViewGetSegmentationOwnerId(GetHandle(), &value));
		return value;
	}

	void SetSegmentationOwnerId(NUShort value)
	{
		NCheck(FirFingerViewSetSegmentationOwnerId(GetHandle(), value));
	}

	NUShort GetSegmentationAlgorithmId() const
	{
		NUShort value;
		NCheck(FirFingerViewGetSegmentationAlgorithmId(GetHandle(), &value));
		return value;
	}

	void SetSegmentationAlgorithmId(NUShort value)
	{
		NCheck(FirFingerViewSetSegmentationAlgorithmId(GetHandle(), value));
	}

	NByte GetSegmentationQualityScore() const
	{
		NByte value;
		NCheck(FirFingerViewGetSegmentationQualityScore(GetHandle(), &value));
		return value;
	}

	void SetSegmentationQualityScore(NByte value)
	{
		NCheck(FirFingerViewSetSegmentationQualityScore(GetHandle(), value));
	}

	NUShort GetSegmentationFingerImageQualityAlgorithmOwnerId() const
	{
		NUShort value;
		NCheck(FirFingerViewGetSegmentationFingerImageQualityAlgorithmOwnerId(GetHandle(), &value));
		return value;
	}

	void SetSegmentationFingerImageQualityAlgorithmOwnerId(NUShort value)
	{
		NCheck(FirFingerViewSetSegmentationFingerImageQualityAlgorithmOwnerId(GetHandle(), value));
	}

	NUShort GetSegmentationFingerImageQualityAlgorithmId() const
	{
		NUShort value;
		NCheck(FirFingerViewGetSegmentationFingerImageQualityAlgorithmId(GetHandle(), &value));
		return value;
	}

	void SetSegmentationFingerImageQualityAlgorithmId(NUShort value)
	{
		NCheck(FirFingerViewSetSegmentationFingerImageQualityAlgorithmId(GetHandle(), value));
	}

	NString GetComment() const
	{
		return GetString(FirFingerViewGetComment);
	}

	void SetComment(const NStringWrapper & value)
	{
		SetString(FirFingerViewSetCommentN, value);
	}

	QualityBlockCollection GetQualityBlocks()
	{
		return QualityBlockCollection(*this);
	}

	const QualityBlockCollection GetQualityBlocks() const
	{
		return QualityBlockCollection(*this);
	}

	CertificationBlockCollection GetCertificationBlocks()
	{
		return CertificationBlockCollection(*this);
	}

	const CertificationBlockCollection GetCertificationBlocks() const
	{
		return CertificationBlockCollection(*this);
	}

	FingerSegmentCollection GetFingerSegments()
	{
		return FingerSegmentCollection(*this);
	}

	const FingerSegmentCollection GetFingerSegments() const
	{
		return FingerSegmentCollection(*this);
	}

	AnnotationCollection GetAnnotations()
	{
		return AnnotationCollection(*this);
	}

	const AnnotationCollection GetAnnotations() const
	{
		return AnnotationCollection(*this);
	}

	VendorExtendedDataCollection GetVendorExtendedDatas()
	{
		return VendorExtendedDataCollection(*this);
	}

	const VendorExtendedDataCollection GetVendorExtendedDatas() const
	{
		return VendorExtendedDataCollection(*this);
	}

	FIRecord GetOwner() const;
};

#include <Core/NReDeprecate.h>
}}}

#include <Biometrics/Standards/FIRecord.hpp>

namespace Neurotec { namespace Biometrics { namespace Standards
{

inline FIRecord FirFingerView::GetOwner() const
{
	return NObject::GetOwner<FIRecord>();
}

inline FirFingerView FirFingerViewSegment::GetOwner() const
{
	return NObject::GetOwner<FirFingerView>();
}

}}}

#endif // !FIR_FINGER_VIEW_HPP_INCLUDED
