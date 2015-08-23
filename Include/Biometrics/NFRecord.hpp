#ifndef NF_RECORD_HPP_INCLUDED
#define NF_RECORD_HPP_INCLUDED

#include <Core/NObject.hpp>
#include <Biometrics/NBiometricTypes.hpp>
#include <Biometrics/NBiometricEngineTypes.hpp>
namespace Neurotec { namespace Biometrics
{
#include <Biometrics/NFRecord.h>
#include <Biometrics/NFRecordV1.h>
}}

N_DEFINE_ENUM_TYPE_TRAITS(Neurotec::Biometrics, NFMinutiaOrder)
N_DEFINE_ENUM_TYPE_TRAITS(Neurotec::Biometrics, NFMinutiaTruncationAlgorithm)

namespace Neurotec { namespace Biometrics
{
#undef NFR_RESOLUTION
#undef NFR_MAX_FINGER_DIMENSION
#undef NFR_MAX_FINGER_MINUTIA_COUNT
#undef NFR_MAX_FINGER_CORE_COUNT
#undef NFR_MAX_FINGER_DELTA_COUNT
#undef NFR_MAX_FINGER_DOUBLE_CORE_COUNT
#undef NFR_MAX_PALM_DIMENSION
#undef NFR_MAX_PALM_MINUTIA_COUNT
#undef NFR_MAX_PALM_CORE_COUNT
#undef NFR_MAX_PALM_DELTA_COUNT
#undef NFR_MAX_PALM_DOUBLE_CORE_COUNT
#undef NFR_MAX_DIMENSION
#undef NFR_MAX_MINUTIA_COUNT
#undef NFR_MAX_CORE_COUNT
#undef NFR_MAX_DELTA_COUNT
#undef NFR_MAX_DOUBLE_CORE_COUNT
#undef NFR_MAX_POSSIBLE_POSITION_COUNT

#undef NFR_SKIP_RIDGE_COUNTS
#undef NFR_SKIP_SINGULAR_POINTS
#undef NFR_SKIP_BLOCKED_ORIENTS
#undef NFR_SAVE_BLOCKED_ORIENTS
#undef NFR_ALLOW_OUT_OF_BOUNDS_FEATURES
#undef NFR_SKIP_QUALITIES
#undef NFR_SKIP_CURVATURES
#undef NFR_SKIP_GS
#undef NFR_SAVE_V1
#undef NFR_SAVE_V2
#undef NFR_SAVE_V3

const NUShort NFR_RESOLUTION = 500;
const NUShort NFR_MAX_FINGER_DIMENSION = 2047;
const NInt NFR_MAX_FINGER_MINUTIA_COUNT = 255;
const NInt NFR_MAX_FINGER_CORE_COUNT = 15;
const NInt NFR_MAX_FINGER_DELTA_COUNT = 15;
const NInt NFR_MAX_FINGER_DOUBLE_CORE_COUNT = 15;
const NUShort NFR_MAX_PALM_DIMENSION = 16383;
const NInt NFR_MAX_PALM_MINUTIA_COUNT = 65535;
const NInt NFR_MAX_PALM_CORE_COUNT = 255;
const NInt NFR_MAX_PALM_DELTA_COUNT = 255;
const NInt NFR_MAX_PALM_DOUBLE_CORE_COUNT = 255;
const NInt NFR_MAX_POSSIBLE_POSITION_COUNT = 255;
const NUInt NFR_SKIP_RIDGE_COUNTS = 0x00010000;
const NUInt NFR_SKIP_SINGULAR_POINTS = 0x00020000;
const NUInt NFR_SKIP_BLOCKED_ORIENTS = 0x00040000;
const NUInt NFR_SAVE_BLOCKED_ORIENTS = 0x00040000;
const NUInt NFR_ALLOW_OUT_OF_BOUNDS_FEATURES = 0x00080000;
const NUInt NFR_SKIP_QUALITIES = 0x00100000;
const NUInt NFR_SKIP_CURVATURES = 0x00200000;
const NUInt NFR_SKIP_GS = 0x00400000;
const NUInt NFR_SAVE_V1 = 0x10000000;
const NUInt NFR_SAVE_V2 = 0x20000000;
const NUInt NFR_SAVE_V3 = 0x30000000;

class NFRecord : public NObject
{
	N_DECLARE_OBJECT_CLASS(NFRecord, NObject)

public:
	class MinutiaCollection : public ::Neurotec::Collections::NCollectionWithAllOutBase<NFMinutia, NFRecord,
		NFRecordGetMinutiaCount, NFRecordGetMinutia, NFRecordGetMinutiae>
	{
		MinutiaCollection(const NFRecord & owner)
		{
			SetOwner(owner);
		}

		friend class NFRecord;

	public:
		NInt GetCapacity() const
		{
			NInt value;
			NCheck(NFRecordGetMinutiaCapacity(this->GetOwnerHandle(), &value));
			return value;
		}

		void SetCapacity(NInt value)
		{
			NCheck(NFRecordSetMinutiaCapacity(this->GetOwnerHandle(), value));
		}

		using ::Neurotec::Collections::NCollectionWithAllOutBase<NFMinutia, NFRecord, NFRecordGetMinutiaCount, NFRecordGetMinutia, NFRecordGetMinutiae>::GetAll;

#include <Core/NNoDeprecate.h>
		N_DEPRECATED("use NArrayWrapper<NFMinutia> GetAll() instead")
		NInt GetAll(NFMinutia * arValues, NInt valuesLength) const
		{
			NInt count;
			NCheck(count = NFRecordGetMinutiaeEx(this->GetOwnerHandle(), arValues, valuesLength));
			return count;
		}
#include <Core/NReDeprecate.h>

		void Set(NInt index, const NFMinutia & value)
		{
			NCheck(NFRecordSetMinutia(this->GetOwnerHandle(), index, &value));
		}

		NInt Add(const NFMinutia & value)
		{
			NInt index;
			NCheck(NFRecordAddMinutiaEx(this->GetOwnerHandle(), &value, &index));
			return index;
		}

		void Insert(NInt index, const NFMinutia & value)
		{
			NCheck(NFRecordInsertMinutia(this->GetOwnerHandle(), index, &value));
		}

		void RemoveAt(NInt index)
		{
			NCheck(NFRecordRemoveMinutiaAt(this->GetOwnerHandle(), index));
		}

		void Clear()
		{
			NCheck(NFRecordClearMinutiae(this->GetOwnerHandle()));
		}
	};

	class MinutiaNeighborsCollection : public ::Neurotec::NObjectPartBase<NFRecord>
	{
		MinutiaNeighborsCollection(const NFRecord & owner)
		{
			SetOwner(owner);
		}

		friend class NFRecord;

	public:
		NInt GetCount(NInt baseIndex) const
		{
			NInt value;
			NCheck(NFRecordGetMinutiaNeighborCount(this->GetOwnerHandle(), baseIndex, &value));
			return value;
		}

		void Get(NInt baseIndex, NInt index, NFMinutiaNeighbor * pValue) const
		{
			NCheck(NFRecordGetMinutiaNeighbor(this->GetOwnerHandle(), baseIndex, index, pValue));
		}

		NFMinutiaNeighbor Get(NInt baseIndex, NInt index) const
		{
			NFMinutiaNeighbor value;
			NCheck(NFRecordGetMinutiaNeighbor(this->GetOwnerHandle(), baseIndex, index, &value));
			return value;
		}

		NArrayWrapper<NFMinutiaNeighbor> GetAll(NInt baseIndex) const
		{
			NFMinutiaNeighbor::NativeType * arValues = NULL;
			NInt valueCount = 0;
			NCheck(NFRecordGetMinutiaNeighbors(this->GetOwnerHandle(), baseIndex, &arValues, &valueCount));
			return NArrayWrapper<NFMinutiaNeighbor>(arValues, valueCount);
		}

#include <Core/NNoDeprecate.h>
		N_DEPRECATED("use NArrayWrapper<NFMinutiaNeighbor> GetAll(NInt baseIndex) instead")
		NInt GetAll(NInt baseIndex, NFMinutiaNeighbor * arValues, NInt valuesLength) const
		{
			NInt count;
			NCheck(count = NFRecordGetMinutiaNeighborsEx(this->GetOwnerHandle(), baseIndex, arValues, valuesLength));
			return count;
		}
#include <Core/NReDeprecate.h>

		void Set(NInt baseIndex, NInt index, const NFMinutiaNeighbor & value)
		{
			NCheck(NFRecordSetMinutiaNeighbor(this->GetOwnerHandle(), baseIndex, index, &value));
		}
	};

	class CoreCollection : public ::Neurotec::Collections::NCollectionWithAllOutBase<NFCore, NFRecord,
		NFRecordGetCoreCount, NFRecordGetCore, NFRecordGetCores>
	{
		CoreCollection(const NFRecord & owner)
		{
			SetOwner(owner);
		}

	public:
		NInt GetCapacity() const
		{
			NInt value;
			NCheck(NFRecordGetCoreCapacity(this->GetOwnerHandle(), &value));
			return value;
		}

		void SetCapacity(NInt value)
		{
			NCheck(NFRecordSetCoreCapacity(this->GetOwnerHandle(), value));
		}

		using ::Neurotec::Collections::NCollectionWithAllOutBase<NFCore, NFRecord, NFRecordGetCoreCount, NFRecordGetCore, NFRecordGetCores>::GetAll;

#include <Core/NNoDeprecate.h>
		N_DEPRECATED("use NArrayWrapper<NFCore> GetAll() instead")
		NInt GetAll(NFCore * arValues, NInt valuesLength) const
		{
			NInt count;
			NCheck(count = NFRecordGetCoresEx(this->GetOwnerHandle(), arValues, valuesLength));
			return count;
		}
#include <Core/NReDeprecate.h>

		void Set(NInt index, const NFCore & value)
		{
			NCheck(NFRecordSetCore(this->GetOwnerHandle(), index, &value));
		}

		NInt Add(const NFCore & value)
		{
			NInt index;
			NCheck(NFRecordAddCoreEx(this->GetOwnerHandle(), &value, &index));
			return index;
		}

		void Insert(NInt index, const NFCore & value)
		{
			NCheck(NFRecordInsertCore(this->GetOwnerHandle(), index, &value));
		}

		void RemoveAt(NInt index)
		{
			NCheck(NFRecordRemoveCoreAt(this->GetOwnerHandle(), index));
		}

		void Clear()
		{
			NCheck(NFRecordClearCores(this->GetOwnerHandle()));
		}

		friend class NFRecord;
	};

	class DeltaCollection : public ::Neurotec::Collections::NCollectionWithAllOutBase<NFDelta, NFRecord,
		NFRecordGetDeltaCount, NFRecordGetDelta, NFRecordGetDeltas>
	{
		DeltaCollection(const NFRecord & owner)
		{
			SetOwner(owner);
		}

		friend class NFRecord;
	public:
		NInt GetCapacity() const
		{
			NInt value;
			NCheck(NFRecordGetDeltaCapacity(this->GetOwnerHandle(), &value));
			return value;
		}

		void SetCapacity(NInt value)
		{
			NCheck(NFRecordSetDeltaCapacity(this->GetOwnerHandle(), value));
		}

		using ::Neurotec::Collections::NCollectionWithAllOutBase<NFDelta, NFRecord, NFRecordGetDeltaCount, NFRecordGetDelta, NFRecordGetDeltas>::GetAll;

#include <Core/NNoDeprecate.h>
		N_DEPRECATED("use NArrayWrapper<NFDelta> GetAll() instead")
		NInt GetAll(NFDelta * arValues, NInt valuesLength) const
		{
			NInt count;
			NCheck(count = NFRecordGetDeltasEx(this->GetOwnerHandle(), arValues, valuesLength));
			return count;
		}
#include <Core/NReDeprecate.h>

		void Set(NInt index, const NFDelta & value)
		{
			NCheck(NFRecordSetDelta(this->GetOwnerHandle(), index, &value));
		}

		NInt Add(const NFDelta & value)
		{
			NInt index;
			NCheck(NFRecordAddDeltaEx(this->GetOwnerHandle(), &value, &index));
			return index;
		}

		void Insert(NInt index, const NFDelta & value)
		{
			NCheck(NFRecordInsertDelta(this->GetOwnerHandle(), index, &value));
		}

		void RemoveAt(NInt index)
		{
			NCheck(NFRecordRemoveDeltaAt(this->GetOwnerHandle(), index));
		}

		void Clear()
		{
			NCheck(NFRecordClearDeltas(this->GetOwnerHandle()));
		}
	};

	class DoubleCoreCollection : public ::Neurotec::Collections::NCollectionWithAllOutBase<NFDoubleCore, NFRecord,
		NFRecordGetDoubleCoreCount, NFRecordGetDoubleCore, NFRecordGetDoubleCores>
	{
		DoubleCoreCollection(const NFRecord & owner)
		{
			SetOwner(owner);
		}

		friend class NFRecord;
	public:
		NInt GetCapacity() const
		{
			NInt value;
			NCheck(NFRecordGetDoubleCoreCapacity(this->GetOwnerHandle(), &value));
			return value;
		}

		void SetCapacity(NInt value)
		{
			NCheck(NFRecordSetDoubleCoreCapacity(this->GetOwnerHandle(), value));
		}

		using ::Neurotec::Collections::NCollectionWithAllOutBase<NFDoubleCore, NFRecord, NFRecordGetDoubleCoreCount, NFRecordGetDoubleCore, NFRecordGetDoubleCores>::GetAll;

#include <Core/NNoDeprecate.h>
		N_DEPRECATED("use NArrayWrapper<NFDoubleCore> GetAll() instead")
		NInt GetAll(NFDoubleCore * arValues, NInt valuesLength) const
		{
			NInt count;
			NCheck(count = NFRecordGetDoubleCoresEx(this->GetOwnerHandle(), arValues, valuesLength));
			return count;
		}
#include <Core/NReDeprecate.h>

		void Set(NInt index, const NFDoubleCore & value)
		{
			NCheck(NFRecordSetDoubleCore(this->GetOwnerHandle(), index, &value));
		}

		NInt Add(const NFDoubleCore & value)
		{
			NInt index;
			NCheck(NFRecordAddDoubleCoreEx(this->GetOwnerHandle(), &value, &index));
			return index;
		}

		void Insert(NInt index, const NFDoubleCore & value)
		{
			NCheck(NFRecordInsertDoubleCore(this->GetOwnerHandle(), index, &value));
		}

		void RemoveAt(NInt index)
		{
			NCheck(NFRecordRemoveDoubleCoreAt(this->GetOwnerHandle(), index));
		}

		void Clear()
		{
			NCheck(NFRecordClearDoubleCores(this->GetOwnerHandle()));
		}
	};

	class PossiblePositionCollection : public ::Neurotec::Collections::NCollectionWithAllOutBase<NFPosition, NFRecord,
		NFRecordGetPossiblePositionCount, NFRecordGetPossiblePosition, NFRecordGetPossiblePositionsEx>
	{
		PossiblePositionCollection(const NFRecord & owner)
		{
			SetOwner(owner);
		}

		friend class NFRecord;

	public:

		using ::Neurotec::Collections::NCollectionWithAllOutBase<NFPosition, NFRecord, NFRecordGetPossiblePositionCount, NFRecordGetPossiblePosition, NFRecordGetPossiblePositionsEx>::GetAll;

#include <Core/NNoDeprecate.h>
		N_DEPRECATED("use NArrayWrapper<NFPosition> GetAll() instead")
		NInt GetAll(NFPosition * arValues, NInt valuesLength) const
		{
			NInt count;
			NCheck(count = NFRecordGetPossiblePositions(this->GetOwnerHandle(), arValues, valuesLength));
			return count;
		}
#include <Core/NReDeprecate.h>

		void Set(NInt index, NFPosition value)
		{
			NCheck(NFRecordSetPossiblePosition(this->GetOwnerHandle(), index, value));
		}

		NInt Add(NFPosition value)
		{
			NInt index;
			NCheck(NFRecordAddPossiblePositionEx(this->GetOwnerHandle(), value, &index));
			return index;
		}

		void Insert(NInt index, NFPosition value)
		{
			NCheck(NFRecordInsertPossiblePosition(this->GetOwnerHandle(), index, value));
		}

		void RemoveAt(NInt index)
		{
			NCheck(NFRecordRemovePossiblePositionAt(this->GetOwnerHandle(), index));
		}

		void Clear()
		{
			NCheck(NFRecordClearPossiblePositions(this->GetOwnerHandle()));
		}
	};

private:
	static NType NFMinutiaOrderNativeTypeOf()
	{
		return NObject::GetObject<NType>(N_TYPE_OF(NFMinutiaOrder), true);
	}

	static NType NFMinutiaTruncationAlgorithmNativeTypeOf()
	{
		return NObject::GetObject<NType>(N_TYPE_OF(NFMinutiaTruncationAlgorithm), true);
	}

	static HNFRecord Create(bool isPalm, NUShort width, NUShort height,
		NUShort horzResolution, NUShort vertResolution, NUInt flags)
	{
		HNFRecord handle;
		NCheck(NFRecordCreateEx(isPalm, width, height, horzResolution, vertResolution, flags, &handle));
		return handle;
	}

	static HNFRecord Create(const ::Neurotec::IO::NBuffer & buffer, NUInt flags, NSizeType * pSize)
	{
		HNFRecord handle;
		NCheck(NFRecordCreateFromMemoryN(buffer.GetHandle(), flags, pSize, &handle));
		return handle;
	}

	static HNFRecord Create(const void * pBuffer, NSizeType bufferSize, NUInt flags, NSizeType * pSize)
	{
		HNFRecord handle;
		NCheck(NFRecordCreateFromMemory(pBuffer, bufferSize, flags, pSize, &handle));
		return handle;
	}

	static HNFRecord Create(const NFRecord & srcRecord, NTemplateSize dstTemplateSize, NUInt flags)
	{
		HNFRecord handle;
		NCheck(NFRecordCreateFromNFRecord(srcRecord.GetHandle(), dstTemplateSize, flags, &handle));
		return handle;
	}

public:
	using NObject::GetSize;

	static NSizeType GetSize(const ::Neurotec::IO::NBuffer & buffer)
	{
		NSizeType value;
		NCheck(NFRecordGetSizeMemN(buffer.GetHandle(), &value));
		return value;
	}

	static NSizeType GetSize(const void * pBuffer, NSizeType bufferSize)
	{
		NSizeType value;
		NCheck(NFRecordGetSizeMem(pBuffer, bufferSize, &value));
		return value;
	}

	static NUShort GetWidth(const ::Neurotec::IO::NBuffer & buffer)
	{
		NUShort value;
		NCheck(NFRecordGetWidthMemN(buffer.GetHandle(), &value));
		return value;
	}

	static NUShort GetWidth(const void * pBuffer, NSizeType bufferSize)
	{
		NUShort value;
		NCheck(NFRecordGetWidthMem(pBuffer, bufferSize, &value));
		return value;
	}

	static NUShort GetHeight(const ::Neurotec::IO::NBuffer & buffer)
	{
		NUShort value;
		NCheck(NFRecordGetHeightMemN(buffer.GetHandle(), &value));
		return value;
	}

	static NUShort GetHeight(const void * pBuffer, NSizeType bufferSize)
	{
		NUShort value;
		NCheck(NFRecordGetHeightMem(pBuffer, bufferSize, &value));
		return value;
	}

	static NUShort GetHorzResolution(const ::Neurotec::IO::NBuffer & buffer)
	{
		NUShort value;
		NCheck(NFRecordGetHorzResolutionMemN(buffer.GetHandle(), &value));
		return value;
	}

	static NUShort GetHorzResolution(const void * pBuffer, NSizeType bufferSize)
	{
		NUShort value;
		NCheck(NFRecordGetHorzResolutionMem(pBuffer, bufferSize, &value));
		return value;
	}

	static NUShort GetVertResolution(const ::Neurotec::IO::NBuffer & buffer)
	{
		NUShort value;
		NCheck(NFRecordGetVertResolutionMemN(buffer.GetHandle(), &value));
		return value;
	}

	static NUShort GetVertResolution(const void * pBuffer, NSizeType bufferSize)
	{
		NUShort value;
		NCheck(NFRecordGetVertResolutionMem(pBuffer, bufferSize, &value));
		return value;
	}

	static NFPosition GetPosition(const ::Neurotec::IO::NBuffer & buffer)
	{
		NFPosition value;
		NCheck(NFRecordGetPositionMemN(buffer.GetHandle(), &value));
		return value;
	}

	static NFPosition GetPosition(const void * pBuffer, NSizeType bufferSize)
	{
		NFPosition value;
		NCheck(NFRecordGetPositionMem(pBuffer, bufferSize, &value));
		return value;
	}

	static NFImpressionType GetImpressionType(const ::Neurotec::IO::NBuffer & buffer)
	{
		NFImpressionType value;
		NCheck(NFRecordGetImpressionTypeMemN(buffer.GetHandle(), &value));
		return value;
	}

	static NFImpressionType GetImpressionType(const void * pBuffer, NSizeType bufferSize)
	{
		NFImpressionType value;
		NCheck(NFRecordGetImpressionTypeMem(pBuffer, bufferSize, &value));
		return value;
	}

	static NFPatternClass GetPatternClass(const ::Neurotec::IO::NBuffer & buffer)
	{
		NFPatternClass value;
		NCheck(NFRecordGetPatternClassMemN(buffer.GetHandle(), &value));
		return value;
	}

	static NFPatternClass GetPatternClass(const void * pBuffer, NSizeType bufferSize)
	{
		NFPatternClass value;
		NCheck(NFRecordGetPatternClassMem(pBuffer, bufferSize, &value));
		return value;
	}

	static NByte GetQuality(const ::Neurotec::IO::NBuffer & buffer)
	{
		NByte value;
		NCheck(NFRecordGetQualityMemN(buffer.GetHandle(), &value));
		return value;
	}

	static NByte GetQuality(const void * pBuffer, NSizeType bufferSize)
	{
		NByte value;
		NCheck(NFRecordGetQualityMem(pBuffer, bufferSize, &value));
		return value;
	}

	static NByte GetG(const ::Neurotec::IO::NBuffer & buffer)
	{
		NByte value;
		NCheck(NFRecordGetGMemN(buffer.GetHandle(), &value));
		return value;
	}

	static NByte GetG(const void * pBuffer, NSizeType bufferSize)
	{
		NByte value;
		NCheck(NFRecordGetGMem(pBuffer, bufferSize, &value));
		return value;
	}

	static NUShort GetCbeffProductType(const ::Neurotec::IO::NBuffer & buffer)
	{
		NUShort value;
		NCheck(NFRecordGetCbeffProductTypeMemN(buffer.GetHandle(), &value));
		return value;
	}

	static NUShort GetCbeffProductType(const void * pBuffer, NSizeType bufferSize)
	{
		NUShort value;
		NCheck(NFRecordGetCbeffProductTypeMem(pBuffer, bufferSize, &value));
		return value;
	}

	static NSizeType GetMaxSize(NInt version, bool isPalm, NFMinutiaFormat minutiaFormat, NInt minutiaCount, NFRidgeCountsType ridgeCountsType,
		NInt coreCount, NInt deltaCount, NInt doubleCoreCount, NInt boWidth = 0, NInt boHeight = 0)
	{
		NSizeType value;
		NCheck(NFRecordGetMaxSize(version, isPalm ? NTrue : NFalse, minutiaFormat, minutiaCount, ridgeCountsType,
			coreCount, deltaCount, doubleCoreCount, boWidth, boHeight, &value));
		return value;
	}

	static NSizeType GetMaxSizeV1(NFMinutiaFormat minutiaFormat, NInt minutiaCount,
		NInt coreCount, NInt deltaCount, NInt doubleCoreCount, NInt boWidth = 0, NInt boHeight = 0)
	{
		return GetMaxSize(1, false, minutiaFormat, minutiaCount, nfrctNone, coreCount, deltaCount, doubleCoreCount, boWidth, boHeight);
	}

	static void Check(const ::Neurotec::IO::NBuffer & buffer)
	{
		NCheck(NFRecordCheckN(buffer.GetHandle()));
	}

	static void Check(const void * pBuffer, NSizeType bufferSize)
	{
		NCheck(NFRecordCheck(pBuffer, bufferSize));
	}

	NFRecord(bool isPalm, NUShort width, NUShort height,
		NUShort horzResolution, NUShort vertResolution, NUInt flags = 0)
		: NObject(Create(isPalm, width, height, horzResolution, vertResolution, flags), true)
	{
	}

	NFRecord(NUShort width, NUShort height,
		NUShort horzResolution, NUShort vertResolution, NUInt flags = 0)
		: NObject(Create(false, width, height, horzResolution, vertResolution, flags), true)
	{
	}

	explicit NFRecord(const ::Neurotec::IO::NBuffer & buffer, NUInt flags = 0, NSizeType * pSize = NULL)
		: NObject(Create(buffer, flags, pSize), true)
	{
	}

	NFRecord(const void * pBuffer, NSizeType bufferSize, NUInt flags = 0, NSizeType * pSize = NULL)
		: NObject(Create(pBuffer, bufferSize, flags, pSize), true)
	{
	}

	NFRecord(const NFRecord & srcRecord, NTemplateSize dstTemplateSize, NUInt flags = 0)
		: NObject(Create(srcRecord, dstTemplateSize, flags), true)
	{
	}

	void SortMinutiae(NFMinutiaOrder order)
	{
		NCheck(NFRecordSortMinutiae((HNFRecord)GetHandle(), order));
	}

	void TruncateMinutiae(NInt maxCount)
	{
		NCheck(NFRecordTruncateMinutiae((HNFRecord)GetHandle(), maxCount));
	}

	void TruncateMinutiaeByQuality(NByte threshold, NInt maxCount)
	{
		NCheck(NFRecordTruncateMinutiaeByQuality((HNFRecord)GetHandle(), threshold, maxCount));
	}

	void TruncateMinutiae(NFMinutiaTruncationAlgorithm minutiaeTruncation, NInt maxCount)
	{
		NCheck(NFRecordTruncateMinutiaeEx((HNFRecord)GetHandle(), minutiaeTruncation, maxCount));
	}

	bool GetRequiresUpdate() const
	{
		NBool value;
		NCheck(NFRecordGetRequiresUpdate((HNFRecord)GetHandle(), &value));
		return value != 0;
	}

	void SetRequiresUpdate(bool value)
	{
		NCheck(NFRecordSetRequiresUpdate((HNFRecord)GetHandle(), value ? NTrue : NFalse));
	}

	NUShort GetWidth() const
	{
		NUShort value;
		NCheck(NFRecordGetWidth((HNFRecord)GetHandle(), &value));
		return value;
	}

	NUShort GetHeight() const
	{
		NUShort value;
		NCheck(NFRecordGetHeight((HNFRecord)GetHandle(), &value));
		return value;
	}

	NUShort GetHorzResolution() const
	{
		NUShort value;
		NCheck(NFRecordGetHorzResolution((HNFRecord)GetHandle(), &value));
		return value;
	}

	NUShort GetVertResolution() const
	{
		NUShort value;
		NCheck(NFRecordGetVertResolution((HNFRecord)GetHandle(), &value));
		return value;
	}

	NFPosition GetPosition() const
	{
		NFPosition value;
		NCheck(NFRecordGetPosition((HNFRecord)GetHandle(), &value));
		return value;
	}

	void SetPosition(NFPosition value)
	{
		NCheck(NFRecordSetPosition((HNFRecord)GetHandle(), value));
	}

	NFImpressionType GetImpressionType() const
	{
		NFImpressionType value;
		NCheck(NFRecordGetImpressionType((HNFRecord)GetHandle(), &value));
		return value;
	}

	void SetImpressionType(NFImpressionType value)
	{
		NCheck(NFRecordSetImpressionType((HNFRecord)GetHandle(), value));
	}

	NFPatternClass GetPatternClass() const
	{
		NFPatternClass value;
		NCheck(NFRecordGetPatternClass((HNFRecord)GetHandle(), &value));
		return value;
	}

	void SetPatternClass(NFPatternClass value)
	{
		NCheck(NFRecordSetPatternClass((HNFRecord)GetHandle(), value));
	}

	NByte GetQuality() const
	{
		NByte value;
		NCheck(NFRecordGetQuality((HNFRecord)GetHandle(), &value));
		return value;
	}

	void SetQuality(NByte value)
	{
		NCheck(NFRecordSetQuality((HNFRecord)GetHandle(), value));
	}

	NByte GetG() const
	{
		NByte value;
		NCheck(NFRecordGetG((HNFRecord)GetHandle(), &value));
		return value;
	}

	void SetG(NByte value)
	{
		NCheck(NFRecordSetG((HNFRecord)GetHandle(), value));
	}

	NUShort GetCbeffProductType() const
	{
		NUShort value;
		NCheck(NFRecordGetCbeffProductType((HNFRecord)GetHandle(), &value));
		return value;
	}

	void SetCbeffProductType(NUShort value)
	{
		NCheck(NFRecordSetCbeffProductType((HNFRecord)GetHandle(), value));
	}

	NFRidgeCountsType GetRidgeCountsType() const
	{
		NFRidgeCountsType value;
		NCheck(NFRecordGetRidgeCountsType((HNFRecord)GetHandle(), &value));
		return value;
	}

	void SetRidgeCountsType(NFRidgeCountsType value)
	{
		NCheck(NFRecordSetRidgeCountsType((HNFRecord)GetHandle(), value));
	}

	NFMinutiaFormat GetMinutiaFormat() const
	{
		NFMinutiaFormat value;
		NCheck(NFRecordGetMinutiaFormat((HNFRecord)GetHandle(), &value));
		return value;
	}

	void SetMinutiaFormat(NFMinutiaFormat value)
	{
		NCheck(NFRecordSetMinutiaFormat((HNFRecord)GetHandle(), value));
	}

	NSizeType GetSizeV1(NUInt flags = 0) const
	{
		return GetSize(NFR_SAVE_V1 | flags);
	}

	::Neurotec::IO::NBuffer  SaveV1(NUInt flags = 0) const
	{
		return Save(NFR_SAVE_V1 | flags);
	}

	NSizeType SaveV1(void * pBuffer, NSizeType bufferSize, NUInt flags = 0) const
	{
		return Save(pBuffer, bufferSize, NFR_SAVE_V1 | flags);
	}

	NSizeType SaveV1(::Neurotec::IO::NBuffer & buffer, NUInt flags = 0) const
	{
		return Save(buffer, NFR_SAVE_V1 | flags);
	}

	MinutiaCollection GetMinutiae()
	{
		return MinutiaCollection(*this);
	}

	const MinutiaCollection GetMinutiae() const
	{
		return MinutiaCollection(*this);
	}

	MinutiaNeighborsCollection GetMinutiaeNeighbors()
	{
		return MinutiaNeighborsCollection(*this);
	}

	const MinutiaNeighborsCollection GetMinutiaeNeighbors() const
	{
		return MinutiaNeighborsCollection(*this);
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

	DoubleCoreCollection GetDoubleCores()
	{
		return DoubleCoreCollection(*this);
	}

	const DoubleCoreCollection GetDoubleCores() const
	{
		return DoubleCoreCollection(*this);
	}

	PossiblePositionCollection GetPossiblePositions()
	{
		return PossiblePositionCollection(*this);
	}

	const PossiblePositionCollection GetPossiblePositions() const
	{
		return PossiblePositionCollection(*this);
	}
};

}}

#endif // !NF_RECORD_HPP_INCLUDED
