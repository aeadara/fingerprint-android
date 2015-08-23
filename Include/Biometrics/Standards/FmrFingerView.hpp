#ifndef FMR_FINGER_VIEW_HPP_INCLUDED
#define FMR_FINGER_VIEW_HPP_INCLUDED

#include <Biometrics/Standards/BdifTypes.hpp>
#include <Biometrics/NFRecord.hpp>
namespace Neurotec { namespace Biometrics { namespace Standards
{
#include <Biometrics/Standards/FmrFingerView.h>
}}}

namespace Neurotec { namespace Biometrics { namespace Standards
{
#include <Core/NNoDeprecate.h>

#undef FMRFV_MAX_DIMENSION
#undef FMRFV_MAX_MINUTIA_COUNT
#undef FMRFV_MAX_CORE_COUNT
#undef FMRFV_MAX_DELTA_COUNT

#undef FMRFV_SKIP_RIDGE_COUNTS
#undef FMRFV_SKIP_SINGULAR_POINTS
#undef FMRFV_PROCESS_ALL_EXTENDED_DATA
#undef FMRFV_OLD_CONVERT
#undef FMRFV_SKIP_NEUROTEC_FIELDS
#undef FMRFV_USE_NEUROTEC_FIELDS

#undef FMRFV_NO_NEIGHBOR_MINUTIA
#undef FMRFV_NO_RIDGE_COUNT

const NUShort FMRFV_MAX_DIMENSION = 16383;
const NInt FMRFV_MAX_MINUTIA_COUNT = 255;
const NInt FMRFV_MAX_CORE_COUNT = 15;
const NInt FMRFV_MAX_DELTA_COUNT = 15;

const NUInt FMRFV_SKIP_RIDGE_COUNTS = NFR_SKIP_RIDGE_COUNTS;
const NUInt FMRFV_SKIP_SINGULAR_POINTS = NFR_SKIP_SINGULAR_POINTS;
const NUInt FMRFV_PROCESS_ALL_EXTENDED_DATA = 0x01000000;
const NUInt FMRFV_OLD_CONVERT = 0x20000000;
const NUInt FMRFV_SKIP_NEUROTEC_FIELDS = 0x40000000;
const NUInt FMRFV_USE_NEUROTEC_FIELDS = 0x80000000;

const NInt FMRFV_NO_NEIGHBOR_MINUTIA = -1;
const NByte FMRFV_NO_RIDGE_COUNT     = 255;

class FmrMinutia : public FmrMinutia_
{
	N_DECLARE_EQUATABLE_STRUCT_CLASS(FmrMinutia)

public:
	FmrMinutia(NUShort x, NUShort y, BdifFPMinutiaType type, NByte angle, NByte quality = 0)
	{
		X = x;
		Y = y;
		Type = type;
		Angle = angle;
		Quality = quality;
	}

	NString ToString(const NStringWrapper & format = NString()) const
	{
		HNString hValue;
		NCheck(FmrMinutiaToStringN(this, format.GetHandle(), &hValue));
		return NString(hValue, true);
	}
};

class FmrCore : public FmrCore_
{
	N_DECLARE_EQUATABLE_STRUCT_CLASS(FmrCore)

public:
	FmrCore(NUShort x, NUShort y, NInt angle = -1)
	{
		X = x;
		Y = y;
		Angle = angle;
	}

	NString ToString(const NStringWrapper & format = NString()) const
	{
		HNString hValue;
		NCheck(FmrCoreToStringN(this, format.GetHandle(), &hValue));
		return NString(hValue, true);
	}
};

class FmrDelta : public FmrDelta_
{
	N_DECLARE_EQUATABLE_STRUCT_CLASS(FmrDelta)

public:
	FmrDelta(NUShort x, NUShort y, NInt angle1 = -1, NInt angle2 = -1, NInt angle3 = -1)
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
		NCheck(FmrDeltaToStringN(this, format.GetHandle(), &hValue));
		return NString(hValue, true);
	}
};

}}}

N_DEFINE_STRUCT_TYPE_TRAITS(Neurotec::Biometrics::Standards, FmrMinutia)
N_DEFINE_STRUCT_TYPE_TRAITS(Neurotec::Biometrics::Standards, FmrCore)
N_DEFINE_STRUCT_TYPE_TRAITS(Neurotec::Biometrics::Standards, FmrDelta)

namespace Neurotec { namespace Biometrics { namespace Standards
{

class FMRecord;

class FmrFingerView : public NObject
{
	N_DECLARE_OBJECT_CLASS(FmrFingerView, NObject)

public:
	class MinutiaCollection : public ::Neurotec::Collections::NCollectionWithAllOutBase<FmrMinutia, FmrFingerView,
		FmrFingerViewGetMinutiaCount, FmrFingerViewGetMinutia, FmrFingerViewGetMinutiae>
	{
		MinutiaCollection(const FmrFingerView & owner)
		{
			SetOwner(owner);
		}

		friend class FmrFingerView;
	public:
		NInt GetCapacity() const
		{
			NInt value;
			NCheck(FmrFingerViewGetMinutiaCapacity(this->GetOwnerHandle(), &value));
			return value;
		}

		void SetCapacity(NInt value)
		{
			NCheck(FmrFingerViewSetMinutiaCapacity(this->GetOwnerHandle(), value));
		}

#include <Core/NNoDeprecate.h>
		N_DEPRECATED("use NArrayWrapper<FmrMinutia> GetAll() instead")
		NInt GetAll(FmrMinutia * arValues, NInt valuesLength) const
		{
			NInt count;
			NCheck(count = FmrFingerViewGetMinutiaeEx(this->GetOwnerHandle(), arValues, valuesLength));
			return count;
		}
#include <Core/NReDeprecate.h>

		using ::Neurotec::Collections::NCollectionWithAllOutBase<FmrMinutia, FmrFingerView,
			FmrFingerViewGetMinutiaCount, FmrFingerViewGetMinutia, FmrFingerViewGetMinutiae>::GetAll;

		void Set(NInt index, const FmrMinutia & value)
		{
			NCheck(FmrFingerViewSetMinutia(this->GetOwnerHandle(), index, &value));
		}

		NInt Add(const FmrMinutia & value)
		{
			NInt index;
			NCheck(FmrFingerViewAddMinutiaEx(this->GetOwnerHandle(), &value, &index));
			return index;
		}

		void Insert(NInt index, const FmrMinutia & value)
		{
			NCheck(FmrFingerViewInsertMinutia(this->GetOwnerHandle(), index, &value));
		}

		void RemoveAt(NInt index)
		{
			NCheck(FmrFingerViewRemoveMinutiaAt(this->GetOwnerHandle(), index));
		}

		void Clear()
		{
			NCheck(FmrFingerViewClearMinutiae(this->GetOwnerHandle()));
		}
	};

	class MinutiaFourNeighborsCollection : public ::Neurotec::NObjectPartBase<FmrFingerView>
	{
		MinutiaFourNeighborsCollection(const FmrFingerView & owner)
		{
			SetOwner(owner);
		}

		friend class FmrFingerView;
	public:
		NInt GetCount(NInt baseIndex) const
		{
			N_UNREFERENCED_PARAMETER(baseIndex);
			return 4;
		}

		void Get(NInt baseIndex, NInt index, BdifFPMinutiaNeighbor * pValue) const
		{
			NCheck(FmrFingerViewGetMinutiaFourNeighbor(this->GetOwnerHandle(), baseIndex, index, pValue));
		}

		BdifFPMinutiaNeighbor Get(NInt baseIndex, NInt index) const
		{
			BdifFPMinutiaNeighbor value;
			NCheck(FmrFingerViewGetMinutiaFourNeighbor(this->GetOwnerHandle(), baseIndex, index, &value));
			return value;
		}

#include <Core/NNoDeprecate.h>
		N_DEPRECATED("use NArrayWrapper<BdifFPMinutiaNeighbor> GetAll(NInt baseIndex) instead")
		NInt GetAll(NInt baseIndex, BdifFPMinutiaNeighbor * arValues, NInt valuesLength) const
		{
			NInt count;
			NCheck(count = FmrFingerViewGetMinutiaFourNeighborsEx(this->GetOwnerHandle(), baseIndex, arValues, valuesLength));
			return count;
		}
#include <Core/NReDeprecate.h>

		NArrayWrapper<BdifFPMinutiaNeighbor> GetAll(NInt baseIndex) const
		{
			BdifFPMinutiaNeighbor::NativeType * arValues = NULL;
			NInt valueCount = 0;
			NCheck(FmrFingerViewGetMinutiaFourNeighbors(this->GetOwnerHandle(), baseIndex, &arValues, &valueCount));
			return NArrayWrapper<BdifFPMinutiaNeighbor>(arValues, valueCount);
		}

		void Set(NInt baseIndex, NInt index, const BdifFPMinutiaNeighbor & value)
		{
			NCheck(FmrFingerViewSetMinutiaFourNeighbor(this->GetOwnerHandle(), baseIndex, index, &value));
		}
	};

	class MinutiaEightNeighborsCollection : public ::Neurotec::NObjectPartBase<FmrFingerView>
	{
		MinutiaEightNeighborsCollection(const FmrFingerView & owner)
		{
			SetOwner(owner);
		}

		friend class FmrFingerView;
	public:
		NInt GetCount(NInt baseIndex) const
		{
			N_UNREFERENCED_PARAMETER(baseIndex);
			return 8;
		}

		void Get(NInt baseIndex, NInt index, BdifFPMinutiaNeighbor * pValue) const
		{
			NCheck(FmrFingerViewGetMinutiaEightNeighbor(this->GetOwnerHandle(), baseIndex, index, pValue));
		}

		BdifFPMinutiaNeighbor Get(NInt baseIndex, NInt index) const
		{
			BdifFPMinutiaNeighbor value;
			NCheck(FmrFingerViewGetMinutiaEightNeighbor(this->GetOwnerHandle(), baseIndex, index, &value));
			return value;
		}

#include <Core/NNoDeprecate.h>
		N_DEPRECATED("use NArrayWrapper<BdifFPMinutiaNeighbor> GetAll(NInt baseIndex) instead")
		NInt GetAll(NInt baseIndex, BdifFPMinutiaNeighbor * arValues, NInt valuesLength) const
		{
			NInt count;
			NCheck(count = FmrFingerViewGetMinutiaEightNeighborsEx(this->GetOwnerHandle(), baseIndex, arValues, valuesLength));
			return count;
		}
#include <Core/NReDeprecate.h>

		NArrayWrapper<BdifFPMinutiaNeighbor> GetAll(NInt baseIndex) const
		{
			BdifFPMinutiaNeighbor::NativeType * arValues = NULL;
			NInt valueCount = 0;
			NCheck(FmrFingerViewGetMinutiaEightNeighbors(this->GetOwnerHandle(), baseIndex, &arValues, &valueCount));
			return NArrayWrapper<BdifFPMinutiaNeighbor>(arValues, valueCount);
		}

		void Set(NInt baseIndex, NInt index, const BdifFPMinutiaNeighbor & value)
		{
			NCheck(FmrFingerViewSetMinutiaEightNeighbor(this->GetOwnerHandle(), baseIndex, index, &value));
		}
	};

	class CoreCollection : public ::Neurotec::Collections::NCollectionWithAllOutBase<FmrCore, FmrFingerView,
		FmrFingerViewGetCoreCount, FmrFingerViewGetCore, FmrFingerViewGetCores>
	{
		CoreCollection(const FmrFingerView & owner)
		{
			SetOwner(owner);
		}

		friend class FmrFingerView;
	public:
		NInt GetCapacity() const
		{
			NInt value;
			NCheck(FmrFingerViewGetCoreCapacity(this->GetOwnerHandle(), &value));
			return value;
		}

		void SetCapacity(NInt value)
		{
			NCheck(FmrFingerViewSetCoreCapacity(this->GetOwnerHandle(), value));
		}

#include <Core/NNoDeprecate.h>
		N_DEPRECATED("use NArrayWrapper<FmrCore> GetAll() instead")
		NInt GetAll(FmrCore * arValues, NInt valuesLength) const
		{
			NInt count;
			NCheck(count = FmrFingerViewGetCoresEx(this->GetOwnerHandle(), arValues, valuesLength));
			return count;
		}
#include <Core/NReDeprecate.h>

		using ::Neurotec::Collections::NCollectionWithAllOutBase<FmrCore, FmrFingerView,
			FmrFingerViewGetCoreCount, FmrFingerViewGetCore, FmrFingerViewGetCores>::GetAll;

		void Set(NInt index, const FmrCore & value)
		{
			NCheck(FmrFingerViewSetCore(this->GetOwnerHandle(), index, &value));
		}

		NInt Add(const FmrCore & value)
		{
			NInt index;
			NCheck(FmrFingerViewAddCoreEx(this->GetOwnerHandle(), &value, &index));
			return index;
		}

		void Insert(NInt index, const FmrCore & value)
		{
			NCheck(FmrFingerViewInsertCore(this->GetOwnerHandle(), index, &value));
		}

		void RemoveAt(NInt index)
		{
			NCheck(FmrFingerViewRemoveCoreAt(this->GetOwnerHandle(), index));
		}

		void Clear()
		{
			NCheck(FmrFingerViewClearCores(this->GetOwnerHandle()));
		}
	};

	class DeltaCollection : public ::Neurotec::Collections::NCollectionWithAllOutBase<FmrDelta, FmrFingerView,
		FmrFingerViewGetDeltaCount, FmrFingerViewGetDelta, FmrFingerViewGetDeltas>
	{
		DeltaCollection(const FmrFingerView & owner)
		{
			SetOwner(owner);
		}

		friend class FmrFingerView;
	public:
		NInt GetCapacity() const
		{
			NInt value;
			NCheck(FmrFingerViewGetDeltaCapacity(this->GetOwnerHandle(), &value));
			return value;
		}

		void SetCapacity(NInt value)
		{
			NCheck(FmrFingerViewSetDeltaCapacity(this->GetOwnerHandle(), value));
		}

#include <Core/NNoDeprecate.h>
		N_DEPRECATED("use NArrayWrapper<FmrDelta> GetAll() instead")
		NInt GetAll(FmrDelta * arValues, NInt valuesLength) const
		{
			NInt count;
			NCheck(count = FmrFingerViewGetDeltasEx(this->GetOwnerHandle(), arValues, valuesLength));
			return count;
		}
#include <Core/NReDeprecate.h>

		using ::Neurotec::Collections::NCollectionWithAllOutBase<FmrDelta, FmrFingerView,
			FmrFingerViewGetDeltaCount, FmrFingerViewGetDelta, FmrFingerViewGetDeltas>::GetAll;

		void Set(NInt index, const FmrDelta & value)
		{
			NCheck(FmrFingerViewSetDelta(this->GetOwnerHandle(), index, &value));
		}

		NInt Add(const FmrDelta & value)
		{
			NInt index;
			NCheck(FmrFingerViewAddDeltaEx(this->GetOwnerHandle(), &value, &index));
			return index;
		}

		void Insert(NInt index, const FmrDelta & value)
		{
			NCheck(FmrFingerViewInsertDelta(this->GetOwnerHandle(), index, &value));
		}

		void RemoveAt(NInt index)
		{
			NCheck(FmrFingerViewRemoveDeltaAt(this->GetOwnerHandle(), index));
		}

		void Clear()
		{
			NCheck(FmrFingerViewClearDeltas(this->GetOwnerHandle()));
		}
	};

	class QualityBlockCollection : public ::Neurotec::Collections::NCollectionWithAllOutBase<BdifQualityBlock, FmrFingerView,
		FmrFingerViewGetQualityBlockCount, FmrFingerViewGetQualityBlock, FmrFingerViewGetQualityBlocks>
	{
		QualityBlockCollection(const FmrFingerView & owner)
		{
			SetOwner(owner);
		}

		friend class FmrFingerView;
	public:
		NInt GetCapacity() const
		{
			NInt value;
			NCheck(FmrFingerViewGetQualityBlockCapacity(this->GetOwnerHandle(), &value));
			return value;
		}

		void SetCapacity(NInt value)
		{
			NCheck(FmrFingerViewSetQualityBlockCapacity(this->GetOwnerHandle(), value));
		}
	
		void Set(NInt index, const BdifQualityBlock & value)
		{
			NCheck(FmrFingerViewSetQualityBlock(this->GetOwnerHandle(), index, &value));
		}

		NInt Add(const BdifQualityBlock & value)
		{
			NInt index;
			NCheck(FmrFingerViewAddQualityBlock(this->GetOwnerHandle(), &value, &index));
			return index;
		}

		void Insert(NInt index, const BdifQualityBlock & value)
		{
			NCheck(FmrFingerViewInsertQualityBlock(this->GetOwnerHandle(), index, &value));
		}

		void RemoveAt(NInt index)
		{
			NCheck(FmrFingerViewRemoveQualityBlockAt(this->GetOwnerHandle(), index));
		}

		void Clear()
		{
			NCheck(FmrFingerViewClearQualityBlocks(this->GetOwnerHandle()));
		}
	};

	class CertificationBlockCollection : public ::Neurotec::Collections::NCollectionWithAllOutBase<BdifCertificationBlock, FmrFingerView,
		FmrFingerViewGetCertificationBlockCount, FmrFingerViewGetCertificationBlock, FmrFingerViewGetCertificationBlocks>
	{
		CertificationBlockCollection(const FmrFingerView & owner)
		{
			SetOwner(owner);
		}

		friend class FmrFingerView;
	public:
		NInt GetCapacity() const
		{
			NInt value;
			NCheck(FmrFingerViewGetCertificationBlockCapacity(this->GetOwnerHandle(), &value));
			return value;
		}

		void SetCapacity(NInt value)
		{
			NCheck(FmrFingerViewSetCertificationBlockCapacity(this->GetOwnerHandle(), value));
		}
	
		void Set(NInt index, const BdifCertificationBlock & value)
		{
			NCheck(FmrFingerViewSetCertificationBlock(this->GetOwnerHandle(), index, &value));
		}

		NInt Add(const BdifCertificationBlock & value)
		{
			NInt index;
			NCheck(FmrFingerViewAddCertificationBlock(this->GetOwnerHandle(), &value, &index));
			return index;
		}

		void Insert(NInt index, const BdifCertificationBlock & value)
		{
			NCheck(FmrFingerViewInsertCertificationBlock(this->GetOwnerHandle(), index, &value));
		}

		void RemoveAt(NInt index)
		{
			NCheck(FmrFingerViewRemoveCertificationBlockAt(this->GetOwnerHandle(), index));
		}

		void Clear()
		{
			NCheck(FmrFingerViewClearCertificationBlocks(this->GetOwnerHandle()));
		}
	};

private:
	static HFmrFingerView Create(BdifStandard standard, NVersion version)
	{
		HFmrFingerView handle;
		NCheck(FmrFingerViewCreate(standard, version.GetValue(), &handle));
		return handle;
	}

public:
#include <Core/NNoDeprecate.h>
	N_DEPRECATED("method is deprecated, use GetSize() instead.")
	static NSizeType GetMaxSize(BdifStandard standard, NInt minutiaCount, NBool hasFourNeighborRidgeCounts, NBool hasEightNeighborRidgeCounts,
		NInt coreWithAngleCount, NInt coreCount, NInt deltaWithAngleCount, NInt deltaCount)
	{
		NSizeType size;
		NCheck(FmrFingerViewGetMaxSize(standard, minutiaCount, hasFourNeighborRidgeCounts, hasEightNeighborRidgeCounts,
			coreWithAngleCount, coreCount, deltaWithAngleCount, deltaCount, &size));
		return size;
	}

	N_DEPRECATED("method is deprecated, use GetSize() instead.")
	static NSizeType GetMaxSize(BdifStandard standard, NInt minutiaCount, NBool hasFourNeighborRidgeCounts, NBool hasEightNeighborRidgeCounts,
		NInt coreWithAngleCount, NInt coreCount, NInt deltaWithAngleCount, NInt deltaCount,
		NBool hasNeurotecCurvatures, NBool hasNeurotecGs, NInt neurotecBOWidth, NInt neurotecBOHeight)
	{
		NSizeType size;
		NCheck(FmrFingerViewGetMaxSizeEx(standard, minutiaCount, hasFourNeighborRidgeCounts, hasEightNeighborRidgeCounts,
			coreWithAngleCount, coreCount, deltaWithAngleCount, deltaCount, hasNeurotecCurvatures, hasNeurotecGs, neurotecBOWidth, neurotecBOHeight, &size));
		return size;
	}
#include <Core/NReDeprecate.h>

	FmrFingerView(BdifStandard standard, NVersion version)
		: NObject(Create(standard, version), true)
	{
	}

	NFRecord ToNFRecord(NUInt flags = 0) const
	{
		HNFRecord hNFRecord;
		NCheck(FmrFingerViewToNFRecord(GetHandle(), flags, &hNFRecord));
		return FromHandle<NFRecord>(hNFRecord);
	}

	BdifStandard GetStandard() const
	{
		BdifStandard value;
		NCheck(FmrFingerViewGetStandard(GetHandle(), &value));
		return value;
	}

	NVersion GetVersion() const
	{
		NVersion_ value;
		NCheck(FmrFingerViewGetVersion(GetHandle(), &value));
		return NVersion(value);
	}

	BdifCaptureDateTime GetCaptureDateAndTime() const
	{
		BdifCaptureDateTime_ value;
		NCheck(FmrFingerViewGetCaptureDateAndTime(GetHandle(), &value));
		return BdifCaptureDateTime(value);
	}

	void SetCaptureDateAndTime(const BdifCaptureDateTime & value)
	{
		NCheck(FmrFingerViewSetCaptureDateAndTime(GetHandle(), value));
	}

	BdifFPCaptureDeviceTechnology GetCaptureDeviceTechnology() const
	{
		BdifFPCaptureDeviceTechnology value;
		NCheck(FmrFingerViewGetCaptureDeviceTechnology(GetHandle(), &value));
		return value;
	}

	void SetCaptureDeviceTechnology(BdifFPCaptureDeviceTechnology value)
	{
		NCheck(FmrFingerViewSetCaptureDeviceTechnology(GetHandle(), value));
	}

	NUShort GetCaptureDeviceVendorId() const
	{
		NUShort value;
		NCheck(FmrFingerViewGetCaptureDeviceVendorId(GetHandle(), &value));
		return value;
	}

	void SetCaptureDeviceVendorId(NUShort value)
	{
		NCheck(FmrFingerViewSetCaptureDeviceVendorId(GetHandle(), value));
	}

	NUShort GetCaptureDeviceTypeId() const
	{
		NUShort value;
		NCheck(FmrFingerViewGetCaptureDeviceTypeId(GetHandle(), &value));
		return value;
	}

	void SetCaptureDeviceTypeId(NUShort value)
	{
		NCheck(FmrFingerViewSetCaptureDeviceTypeId(GetHandle(), value));
	}

	BdifFPPosition GetFingerPosition() const
	{
		BdifFPPosition value;
		NCheck(FmrFingerViewGetFingerPosition(GetHandle(), &value));
		return value;
	}

	void SetFingerPosition(BdifFPPosition value)
	{
		NCheck(FmrFingerViewSetFingerPosition(GetHandle(), value));
	}

	BdifFPImpressionType GetImpressionType() const
	{
		BdifFPImpressionType value;
		NCheck(FmrFingerViewGetImpressionType(GetHandle(), &value));
		return value;
	}

	void SetImpressionType(BdifFPImpressionType value)
	{
		NCheck(FmrFingerViewSetImpressionType(GetHandle(), value));
	}

	NUShort GetHorzImageResolution() const
	{
		NUShort value;
		NCheck(FmrFingerViewGetHorzImageResolution(GetHandle(), &value));
		return value;
	}

	void SetHorzImageResolution(NUShort value)
	{
		NCheck(FmrFingerViewSetHorzImageResolution(GetHandle(), value));
	}

	NUShort GetVertImageResolution() const
	{
		NUShort value;
		NCheck(FmrFingerViewGetVertImageResolution(GetHandle(), &value));
		return value;
	}

	void SetVertImageResolution(NUShort value)
	{
		NCheck(FmrFingerViewSetVertImageResolution(GetHandle(), value));
	}

	NUShort GetSizeX() const
	{
		NUShort value;
		NCheck(FmrFingerViewGetSizeX(GetHandle(), &value));
		return value;
	}

	void SetSizeX(NUShort value)
	{
		NCheck(FmrFingerViewSetSizeX(GetHandle(), value));
	}

	NUShort GetSizeY() const
	{
		NUShort value;
		NCheck(FmrFingerViewGetSizeY(GetHandle(), &value));
		return value;
	}

	void SetSizeY(NUShort value)
	{
		NCheck(FmrFingerViewSetSizeY(GetHandle(), value));
	}

	NBool GetMinutiaeQualityFlag() const
	{
		NBool value;
		NCheck(FmrFingerViewGetMinutiaeQualityFlag(GetHandle(), &value));
		return value;
	}

	void SetMinutiaeQualityFlag(NBool value)
	{
		NCheck(FmrFingerViewSetMinutiaeQualityFlag(GetHandle(), value));
	}

	BdifFPMinutiaRidgeEndingType GetRidgeEndingType() const
	{
		BdifFPMinutiaRidgeEndingType value;
		NCheck(FmrFingerViewGetRidgeEndingType(GetHandle(), &value));
		return value;
	}

	void SetRidgeEndingType(BdifFPMinutiaRidgeEndingType value)
	{
		NCheck(FmrFingerViewSetRidgeEndingType(GetHandle(), value));
	}

#include <Core/NNoDeprecate.h>
	N_DEPRECATED("method is deprecated")
	NInt GetViewCount() const
	{
		NInt value;
		NCheck(FmrFingerViewGetViewCount(GetHandle(), &value));
		return value;
	}
#include <Core/NReDeprecate.h>

	NInt GetViewNumber() const
	{
		NInt value;
		NCheck(FmrFingerViewGetViewNumber(GetHandle(), &value));
		return value;
	}

	NByte GetFingerQuality() const
	{
		NByte value;
		NCheck(FmrFingerViewGetFingerQuality(GetHandle(), &value));
		return value;
	}

	void SetFingerQuality(NByte value)
	{
		NCheck(FmrFingerViewSetFingerQuality(GetHandle(), value));
	}

	bool GetHasFourNeighborRidgeCounts() const
	{
		NBool value;
		NCheck(FmrFingerViewHasFourNeighborRidgeCounts(GetHandle(), &value));
		return value != 0;
	}

	void SetHasFourNeighborRidgeCounts(bool value)
	{
		NCheck(FmrFingerViewSetHasFourNeighborRidgeCounts(GetHandle(), value ? NTrue : NFalse));
	}

	bool GetHasEightNeighborRidgeCounts() const
	{
		NBool value;
		NCheck(FmrFingerViewHasEightNeighborRidgeCounts(GetHandle(), &value));
		return value != 0;
	}

	void SetHasEightNeighborRidgeCounts(bool value)
	{
		NCheck(FmrFingerViewSetHasEightNeighborRidgeCounts(GetHandle(), value ? NTrue : NFalse));
	}

	bool ValidateMinutiaeUniqueness() const
	{
		NBool value;
		NCheck(FmrFingerViewValidateMinutiaeUniqueness(GetHandle(), &value));
		return value != 0;
	}

	MinutiaCollection GetMinutiae()
	{
		return MinutiaCollection(*this);
	}

	const MinutiaCollection GetMinutiae() const
	{
		return MinutiaCollection(*this);
	}

	MinutiaFourNeighborsCollection GetMinutiaeFourNeighbors()
	{
		return MinutiaFourNeighborsCollection(*this);
	}

	const MinutiaFourNeighborsCollection GetMinutiaeFourNeighbors() const
	{
		return MinutiaFourNeighborsCollection(*this);
	}

	MinutiaEightNeighborsCollection GetMinutiaeEightNeighbors()
	{
		return MinutiaEightNeighborsCollection(*this);
	}

	const MinutiaEightNeighborsCollection GetMinutiaeEightNeighbors() const
	{
		return MinutiaEightNeighborsCollection(*this);
	}

	CoreCollection GetCores()
	{
		return CoreCollection(*this);
	}

	const CoreCollection GetCores() const
	{
		return CoreCollection(*this);
	}

	DeltaCollection GetDeltas()
	{
		return DeltaCollection(*this);
	}

	const DeltaCollection GetDeltas() const
	{
		return DeltaCollection(*this);
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

	FMRecord GetOwner() const;
};

#include <Core/NReDeprecate.h>
}}}

#include <Biometrics/Standards/FMRecord.hpp>

namespace Neurotec { namespace Biometrics { namespace Standards
{

inline FMRecord FmrFingerView::GetOwner() const
{
	return NObject::GetOwner<FMRecord>();
}

}}}

#endif // !FMR_FINGER_VIEW_HPP_INCLUDED
