#ifndef AN_TYPE_9_RECORD_HPP_INCLUDED
#define AN_TYPE_9_RECORD_HPP_INCLUDED

#include <Biometrics/Standards/ANAsciiRecord.hpp>
#include <Biometrics/Standards/BdifTypes.hpp>
#include <Biometrics/NFRecord.hpp>
namespace Neurotec { namespace Biometrics { namespace Standards
{
#include <Biometrics/Standards/ANType9Record.h>
}}}

N_DEFINE_ENUM_TYPE_TRAITS(Neurotec::Biometrics::Standards, ANFPMinutiaeMethod)

namespace Neurotec { namespace Biometrics { namespace Standards
{

#undef AN_TYPE_9_RECORD_FIELD_LEN
#undef AN_TYPE_9_RECORD_FIELD_IDC

#undef AN_TYPE_9_RECORD_FIELD_IMP
#undef AN_TYPE_9_RECORD_FIELD_FMT

#undef AN_TYPE_9_RECORD_FIELD_OFR
#undef AN_TYPE_9_RECORD_FIELD_FGP
#undef AN_TYPE_9_RECORD_FIELD_FPC
#undef AN_TYPE_9_RECORD_FIELD_CRP
#undef AN_TYPE_9_RECORD_FIELD_DLT
#undef AN_TYPE_9_RECORD_FIELD_MIN
#undef AN_TYPE_9_RECORD_FIELD_RDG
#undef AN_TYPE_9_RECORD_FIELD_MRC

#undef AN_TYPE_9_RECORD_FIELD_ALL_FROM
#undef AN_TYPE_9_RECORD_FIELD_ALL_TO

#undef AN_TYPE_9_RECORD_FIELD_STANDARD_FORMAT_FEATURES_FROM
#undef AN_TYPE_9_RECORD_FIELD_STANDARD_FORMAT_FEATURES_TO

#undef AN_TYPE_9_RECORD_FIELD_VENDOR_DEFINED_FEATURES_FROM
#undef AN_TYPE_9_RECORD_FIELD_VENDOR_DEFINED_FEATURES_TO

#undef AN_TYPE_9_RECORD_MAX_FINGERPRINT_X
#undef AN_TYPE_9_RECORD_MAX_FINGERPRINT_Y
#undef AN_TYPE_9_RECORD_MAX_PALMPRINT_X
#undef AN_TYPE_9_RECORD_MAX_PALMPRINT_Y

#undef AN_TYPE_9_RECORD_MINUTIA_QUALITY_MANUAL
#undef AN_TYPE_9_RECORD_MINUTIA_QUALITY_NOT_AVAILABLE
#undef AN_TYPE_9_RECORD_MINUTIA_QUALITY_BEST
#undef AN_TYPE_9_RECORD_MINUTIA_QUALITY_WORST

const NInt AN_TYPE_9_RECORD_FIELD_LEN = AN_RECORD_FIELD_LEN;
const NInt AN_TYPE_9_RECORD_FIELD_IDC = AN_RECORD_FIELD_IDC;

const NInt AN_TYPE_9_RECORD_FIELD_IMP = 3;
const NInt AN_TYPE_9_RECORD_FIELD_FMT = 4;

const NInt AN_TYPE_9_RECORD_FIELD_OFR = 5;
const NInt AN_TYPE_9_RECORD_FIELD_FGP = 6;
const NInt AN_TYPE_9_RECORD_FIELD_FPC = 7;
const NInt AN_TYPE_9_RECORD_FIELD_CRP = 8;
const NInt AN_TYPE_9_RECORD_FIELD_DLT = 9;
const NInt AN_TYPE_9_RECORD_FIELD_MIN = 10;
const NInt AN_TYPE_9_RECORD_FIELD_RDG = 11;
const NInt AN_TYPE_9_RECORD_FIELD_MRC = 12;

const NInt AN_TYPE_9_RECORD_FIELD_ALL_FROM = AN_TYPE_9_RECORD_FIELD_LEN;
const NInt AN_TYPE_9_RECORD_FIELD_ALL_TO = AN_TYPE_9_RECORD_FIELD_FMT;

const NInt AN_TYPE_9_RECORD_FIELD_STANDARD_FORMAT_FEATURES_FROM = AN_TYPE_9_RECORD_FIELD_OFR;
const NInt AN_TYPE_9_RECORD_FIELD_STANDARD_FORMAT_FEATURES_TO = AN_TYPE_9_RECORD_FIELD_MRC;

const NInt AN_TYPE_9_RECORD_FIELD_VENDOR_DEFINED_FEATURES_FROM = (AN_TYPE_9_RECORD_FIELD_MRC + 1);
const NInt AN_TYPE_9_RECORD_FIELD_VENDOR_DEFINED_FEATURES_TO = AN_ASCII_RECORD_MAX_FIELD_NUMBER;

const NUShort AN_TYPE_9_RECORD_MAX_FINGERPRINT_X = 4999;
const NUShort AN_TYPE_9_RECORD_MAX_FINGERPRINT_Y = 4999;
const NUInt AN_TYPE_9_RECORD_MAX_PALMPRINT_X = 13999;
const NUInt AN_TYPE_9_RECORD_MAX_PALMPRINT_Y = 20999;

const NByte AN_TYPE_9_RECORD_MINUTIA_QUALITY_MANUAL = 0;
const NByte AN_TYPE_9_RECORD_MINUTIA_QUALITY_NOT_AVAILABLE = 1;
const NByte AN_TYPE_9_RECORD_MINUTIA_QUALITY_BEST = 2;
const NByte AN_TYPE_9_RECORD_MINUTIA_QUALITY_WORST = 63;

class ANOfrs : public ANOfrs_
{
	N_DECLARE_DISPOSABLE_STRUCT_CLASS(ANOfrs)

public:
	ANOfrs(const NStringWrapper & name, ANFPMinutiaeMethod method, const NStringWrapper & equipment)
	{
		NCheck(ANOfrsCreateN(name.GetHandle(), method, equipment.GetHandle(), this));
	}

	NString GetName() const
	{
		return NString(hName, false);
	}

	void SetName(const NStringWrapper & value)
	{
		NCheck(NStringSet(value.GetHandle(), &hName));
	}

	NString GetEquipment() const
	{
		return NString(hEquipment, false);
	}

	void SetEquipment(const NStringWrapper & value)
	{
		NCheck(NStringSet(value.GetHandle(), &hEquipment));
	}
};

class ANFPatternClass : public ANFPatternClass_
{
	N_DECLARE_EQUATABLE_DISPOSABLE_STRUCT_CLASS(ANFPatternClass)

public:
	ANFPatternClass(BdifFPatternClass value, const NStringWrapper & vendorValue)
	{
		NCheck(ANFPatternClassCreateN(value, vendorValue.GetHandle(), this));
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

class ANFCore : public ANFCore_
{
	N_DECLARE_EQUATABLE_STRUCT_CLASS(ANFCore)

public:
	ANFCore(NUShort x, NUShort y)
	{
		X = x;
		Y = y;
	}
};

class ANFDelta : public ANFDelta_
{
	N_DECLARE_EQUATABLE_STRUCT_CLASS(ANFDelta)

public:
	ANFDelta(NUShort x, NUShort y)
	{
		X = x;
		Y = y;
	}
};

class ANFPMinutia : public ANFPMinutia_
{
	N_DECLARE_EQUATABLE_STRUCT_CLASS(ANFPMinutia)

public:
	ANFPMinutia(NUInt x, NUInt y, NUShort theta, NByte quality, BdifFPMinutiaType type)
	{
		X = x;
		Y = y;
		Theta = theta;
		Quality = quality;
		Type = type;
	}
};

}}}

N_DEFINE_DISPOSABLE_STRUCT_TYPE_TRAITS(Neurotec::Biometrics::Standards, ANOfrs)
N_DEFINE_DISPOSABLE_STRUCT_TYPE_TRAITS(Neurotec::Biometrics::Standards, ANFPatternClass)
N_DEFINE_STRUCT_TYPE_TRAITS(Neurotec::Biometrics::Standards, ANFCore)
N_DEFINE_STRUCT_TYPE_TRAITS(Neurotec::Biometrics::Standards, ANFDelta)
N_DEFINE_STRUCT_TYPE_TRAITS(Neurotec::Biometrics::Standards, ANFPMinutia)

namespace Neurotec { namespace Biometrics { namespace Standards
{

class ANType9Record : public ANAsciiRecord
{
	N_DECLARE_OBJECT_CLASS(ANType9Record, ANAsciiRecord)

public:
	class PositionCollection : public ::Neurotec::Collections::NCollectionWithAllOutBase<BdifFPPosition, ANType9Record,
		ANType9RecordGetPositionCount, ANType9RecordGetPosition, ANType9RecordGetPositions>
	{
		PositionCollection(const ANType9Record & owner)
		{
			SetOwner(owner);
		}

		friend class ANType9Record;
	public:
#include <Core/NNoDeprecate.h>
		N_DEPRECATED("use NArrayWrapper<BdifFPPosition> GetAll() instead")
		NInt GetAll(BdifFPPosition * arValues, NInt valuesLength) const
		{
			NInt count;
			NCheck(count = ANType9RecordGetPositionsEx(this->GetOwnerHandle(), arValues, valuesLength));
			return count;
		}
#include <Core/NReDeprecate.h>

		using ::Neurotec::Collections::NCollectionWithAllOutBase<BdifFPPosition, ANType9Record,
			ANType9RecordGetPositionCount, ANType9RecordGetPosition, ANType9RecordGetPositions>::GetAll;

		void Set(NInt index, BdifFPPosition value)
		{
			NCheck(ANType9RecordSetPosition(this->GetOwnerHandle(), index, value));
		}

		NInt Add(BdifFPPosition value)
		{
			NInt index;
			NCheck(ANType9RecordAddPositionEx(this->GetOwnerHandle(), value, &index));
			return index;
		}

		void Insert(NInt index, BdifFPPosition value)
		{
			NCheck(ANType9RecordInsertPosition(this->GetOwnerHandle(), index, value));
		}

		void RemoveAt(NInt index)
		{
			NCheck(ANType9RecordRemovePositionAt(this->GetOwnerHandle(), index));
		}

		void Clear()
		{
			NCheck(ANType9RecordClearPositions(this->GetOwnerHandle()));
		}
	};

	class PatternClassCollection : public ::Neurotec::Collections::NCollectionBase<ANFPatternClass, ANType9Record,
		ANType9RecordGetPatternClassCount, ANType9RecordGetPatternClass>
	{
		PatternClassCollection(const ANType9Record & owner)
		{
			SetOwner(owner);
		}

		friend class ANType9Record;
	public:
		void Set(NInt index, const ANFPatternClass & value)
		{
			NCheck(ANType9RecordSetPatternClass(this->GetOwnerHandle(), index, &value));
		}

		NInt Add(const ANFPatternClass & value)
		{
			NInt index;
			NCheck(ANType9RecordAddPatternClassEx(this->GetOwnerHandle(), &value, &index));
			return index;
		}

		void Insert(NInt index, const ANFPatternClass & value)
		{
			NCheck(ANType9RecordInsertPatternClass(this->GetOwnerHandle(), index, &value));
		}

		void RemoveAt(NInt index)
		{
			NCheck(ANType9RecordRemovePatternClassAt(this->GetOwnerHandle(), index));
		}

		void Clear()
		{
			NCheck(ANType9RecordClearPatternClasses(this->GetOwnerHandle()));
		}
	};

	class CoreCollection : public ::Neurotec::Collections::NCollectionWithAllOutBase<ANFCore, ANType9Record,
		ANType9RecordGetCoreCount, ANType9RecordGetCore, ANType9RecordGetCores>
	{
		CoreCollection(const ANType9Record & owner)
		{
			SetOwner(owner);
		}

		friend class ANType9Record;
	public:
#include <Core/NNoDeprecate.h>
		N_DEPRECATED("use NArrayWrapper<ANFCore> GetAll() instead")
		NInt GetAll(ANFCore * arValues, NInt valuesLength) const
		{
			NInt count;
			NCheck(count = ANType9RecordGetCoresEx(this->GetOwnerHandle(), arValues, valuesLength));
			return count;
		}
#include <Core/NReDeprecate.h>

		using ::Neurotec::Collections::NCollectionWithAllOutBase<ANFCore, ANType9Record,
			ANType9RecordGetCoreCount, ANType9RecordGetCore, ANType9RecordGetCores>::GetAll;

		void Set(NInt index, const ANFCore & value)
		{
			NCheck(ANType9RecordSetCore(this->GetOwnerHandle(), index, &value));
		}

		NInt Add(const ANFCore & value)
		{
			NInt index;
			NCheck(ANType9RecordAddCoreEx(this->GetOwnerHandle(), &value, &index));
			return index;
		}

		void Insert(NInt index, const ANFCore & value)
		{
			NCheck(ANType9RecordInsertCore(this->GetOwnerHandle(), index, &value));
		}

		void RemoveAt(NInt index)
		{
			NCheck(ANType9RecordRemoveCoreAt(this->GetOwnerHandle(), index));
		}

		void Clear()
		{
			NCheck(ANType9RecordClearCores(this->GetOwnerHandle()));
		}
	};

	class DeltaCollection : public ::Neurotec::Collections::NCollectionWithAllOutBase<ANFDelta, ANType9Record,
		ANType9RecordGetDeltaCount, ANType9RecordGetDelta, ANType9RecordGetDeltas>
	{
		DeltaCollection(const ANType9Record & owner)
		{
			SetOwner(owner);
		}

		friend class ANType9Record;
	public:
#include <Core/NNoDeprecate.h>
		N_DEPRECATED("use NArrayWrapper<ANFDelta> GetAll() instead")
		NInt GetAll(ANFDelta * arValues, NInt valuesLength) const
		{
			NInt count;
			NCheck(count = ANType9RecordGetDeltasEx(this->GetOwnerHandle(), arValues, valuesLength));
			return count;
		}
#include <Core/NReDeprecate.h>

		using ::Neurotec::Collections::NCollectionWithAllOutBase<ANFDelta, ANType9Record,
			ANType9RecordGetDeltaCount, ANType9RecordGetDelta, ANType9RecordGetDeltas>::GetAll;

		void Set(NInt index, const ANFDelta & value)
		{
			NCheck(ANType9RecordSetDelta(this->GetOwnerHandle(), index, &value));
		}

		NInt Add(const ANFDelta & value)
		{
			NInt index;
			NCheck(ANType9RecordAddDeltaEx(this->GetOwnerHandle(), &value, &index));
			return index;
		}

		void Insert(NInt index, const ANFDelta & value)
		{
			NCheck(ANType9RecordInsertDelta(this->GetOwnerHandle(), index, &value));
		}

		void RemoveAt(NInt index)
		{
			NCheck(ANType9RecordRemoveDeltaAt(this->GetOwnerHandle(), index));
		}

		void Clear()
		{
			NCheck(ANType9RecordClearDeltas(this->GetOwnerHandle()));
		}
	};

	class MinutiaCollection : public ::Neurotec::Collections::NCollectionWithAllOutBase<ANFPMinutia, ANType9Record,
		ANType9RecordGetMinutiaCount, ANType9RecordGetMinutia, ANType9RecordGetMinutiae>
	{
		MinutiaCollection(const ANType9Record & owner)
		{
			SetOwner(owner);
		}

		friend class ANType9Record;
	public:
#include <Core/NNoDeprecate.h>
		N_DEPRECATED("use NArrayWrapper<ANFPMinutia> GetAll() instead")
		NInt GetAll(ANFPMinutia * arValues, NInt valuesLength) const
		{
			NInt count;
			NCheck(count = ANType9RecordGetMinutiaeEx(this->GetOwnerHandle(), arValues, valuesLength));
			return count;
		}
#include <Core/NReDeprecate.h>

		using ::Neurotec::Collections::NCollectionWithAllOutBase<ANFPMinutia, ANType9Record,
			ANType9RecordGetMinutiaCount, ANType9RecordGetMinutia, ANType9RecordGetMinutiae>::GetAll;

		void Set(NInt index, const ANFPMinutia & value)
		{
			NCheck(ANType9RecordSetMinutia(this->GetOwnerHandle(), index, &value));
		}

		NInt Add(const ANFPMinutia & value)
		{
			NInt index;
			NCheck(ANType9RecordAddMinutiaEx(this->GetOwnerHandle(), &value, &index));
			return index;
		}

		void Insert(NInt index, const ANFPMinutia & value)
		{
			NCheck(ANType9RecordInsertMinutia(this->GetOwnerHandle(), index, &value));
		}

		void RemoveAt(NInt index)
		{
			NCheck(ANType9RecordRemoveMinutiaAt(this->GetOwnerHandle(), index));
		}

		void Clear()
		{
			NCheck(ANType9RecordClearMinutiae(this->GetOwnerHandle()));
		}
	};

	class MinutiaNeighborsCollection : public ::Neurotec::NObjectPartBase<ANType9Record>
	{
		MinutiaNeighborsCollection(const ANType9Record & owner)
		{
			SetOwner(owner);
		}

		friend class ANType9Record;
	public:
		NInt GetCount(NInt baseIndex) const
		{
			NInt value;
			NCheck(ANType9RecordGetMinutiaNeighborCount(this->GetOwnerHandle(), baseIndex, &value));
			return value;
		}

		void Get(NInt baseIndex, NInt index, BdifFPMinutiaNeighbor * pValue) const
		{
			NCheck(ANType9RecordGetMinutiaNeighbor(this->GetOwnerHandle(), baseIndex, index, pValue));
		}

		BdifFPMinutiaNeighbor Get(NInt baseIndex, NInt index) const
		{
			BdifFPMinutiaNeighbor value;
			NCheck(ANType9RecordGetMinutiaNeighbor(this->GetOwnerHandle(), baseIndex, index, &value));
			return value;
		}

#include <Core/NNoDeprecate.h>
		N_DEPRECATED("use NArrayWrapper<BdifFPMinutiaNeighbor> GetAll() instead")
		NInt GetAll(NInt baseIndex, BdifFPMinutiaNeighbor * arValues, NInt valuesLength) const
		{
			NInt count;
			NCheck(count = ANType9RecordGetMinutiaNeighborsEx(this->GetOwnerHandle(), baseIndex, arValues, valuesLength));
			return count;
		}
#include <Core/NReDeprecate.h>

		NArrayWrapper<BdifFPMinutiaNeighbor> GetAll(NInt baseIndex) const
		{
			BdifFPMinutiaNeighbor::NativeType * arValues = NULL;
			NInt valueCount = 0;
			NCheck(ANType9RecordGetMinutiaNeighbors(this->GetOwnerHandle(), baseIndex, &arValues, &valueCount));
			return NArrayWrapper<BdifFPMinutiaNeighbor>(arValues, valueCount);
		}

		void Set(NInt baseIndex, NInt index, const BdifFPMinutiaNeighbor & value)
		{
			NCheck(ANType9RecordSetMinutiaNeighbor(this->GetOwnerHandle(), baseIndex, index, &value));
		}

		NInt Add(NInt baseIndex, const BdifFPMinutiaNeighbor & value)
		{
			NInt index;
			NCheck(ANType9RecordAddMinutiaNeighborEx(this->GetOwnerHandle(), baseIndex, &value, &index));
			return index;
		}

		void Insert(NInt baseIndex, NInt index, const BdifFPMinutiaNeighbor & value)
		{
			NCheck(ANType9RecordInsertMinutiaNeighbor(this->GetOwnerHandle(), baseIndex, index, &value));
		}

		void RemoveAt(NInt baseIndex, NInt index)
		{
			NCheck(ANType9RecordRemoveMinutiaNeighborAt(this->GetOwnerHandle(), baseIndex, index));
		}

		void Clear(NInt baseIndex)
		{
			NCheck(ANType9RecordClearMinutiaNeighbors(this->GetOwnerHandle(), baseIndex));
		}
	};

public:
	static NType ANFPMinutiaeMethodNativeTypeOf()
	{
		return NObject::GetObject<NType>(N_TYPE_OF(ANFPMinutiaeMethod), true);
	}

	NFRecord ToNFRecord(NUInt flags = 0) const
	{
		HNFRecord hNFRecord;
		NCheck(ANType9RecordToNFRecord(GetHandle(), flags, &hNFRecord));
		return FromHandle<NFRecord>(hNFRecord);
	}

	BdifFPImpressionType GetImpressionType() const
	{
		BdifFPImpressionType value;
		NCheck(ANType9RecordGetImpressionType(GetHandle(), &value));
		return value;
	}

	void SetImpressionType(BdifFPImpressionType value)
	{
		NCheck(ANType9RecordSetImpressionType(GetHandle(), value));
	}

	bool GetMinutiaeFormat() const
	{
		NBool value;
		NCheck(ANType9RecordGetMinutiaeFormat(GetHandle(), &value));
		return value != 0;
	}

	bool GetHasMinutiae() const
	{
		NBool value;
		NCheck(ANType9RecordHasMinutiae(GetHandle(), &value));
		return value != 0;
	}

	bool GetHasMinutiaeRidgeCounts() const
	{
		NBool value;
		NCheck(ANType9RecordHasMinutiaeRidgeCounts(GetHandle(), &value));
		return value != 0;
	}

	bool GetHasMinutiaeRidgeCountsIndicator() const
	{
		NBool value;
		NCheck(ANType9RecordHasMinutiaeRidgeCountsIndicator(GetHandle(), &value));
		return value != 0;
	}

	bool GetOfrs(ANOfrs * pValue) const
	{
		NBool hasValue;
		NCheck(ANType9RecordGetOfrs(GetHandle(), pValue, &hasValue));
		return hasValue != 0;
	}

	NString GetOfrsName() const
	{
		return GetString(ANType9RecordGetOfrsNameN);
	}

	ANFPMinutiaeMethod GetOfrsMethod() const
	{
		ANFPMinutiaeMethod value;
		NCheck(ANType9RecordGetOfrsMethod(GetHandle(), &value));
		return value;
	}

	NString GetOfrsEquipment() const
	{
		return GetString(ANType9RecordGetOfrsEquipmentN);
	}

	void SetOfrs(const ANOfrs * pValue)
	{
		NCheck(ANType9RecordSetOfrsEx(GetHandle(), pValue));
	}

	void SetOfrs(const NStringWrapper & name, ANFPMinutiaeMethod method, const NStringWrapper & equipment)
	{
		NCheck(ANType9RecordSetOfrsN(GetHandle(), name.GetHandle(), method, equipment.GetHandle()));
	}

	PositionCollection GetPositions()
	{
		return PositionCollection(*this);
	}

	const PositionCollection GetPositions() const
	{
		return PositionCollection(*this);
	}

	PatternClassCollection GetPatternClasses()
	{
		return PatternClassCollection(*this);
	}

	const PatternClassCollection GetPatternClasses() const
	{
		return PatternClassCollection(*this);
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
};

}}}

#endif // !AN_TYPE_9_RECORD_HPP_INCLUDED
