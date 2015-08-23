#include <Biometrics/Standards/FmrFingerView.hpp>

#ifndef FMR_FINGER_HPP_INCLUDED
#define FMR_FINGER_HPP_INCLUDED

#include <Biometrics/Standards/BdifTypes.hpp>
#include <Biometrics/NFRecord.hpp>
namespace Neurotec { namespace Biometrics { namespace Standards
{
#include <Biometrics/Standards/FmrFinger.h>
}}}

namespace Neurotec { namespace Biometrics { namespace Standards
{

#undef FMRF_MAX_FINGER_VIEW_COUNT

#undef FMRF_PROCESS_FIRST_FINGER_VIEW_ONLY

const NInt FMRF_MAX_FINGER_VIEW_COUNT = 16;

const NUInt FMRF_PROCESS_FIRST_FINGER_VIEW_ONLY = 0x00001000;

class FMRecord;

#include <Core/NNoDeprecate.h>
class N_DEPRECATED("class is deprecated, use FmrFingerView instead.") FmrFinger : public NObject
{
	N_DECLARE_OBJECT_CLASS(FmrFinger, NObject)

public:
	class FingerViewCollection : public ::Neurotec::Collections::NCollectionBase<FmrFingerView, FmrFinger,
		FmrFingerGetFingerViewCount, FmrFingerGetFingerViewEx>
	{
		FingerViewCollection(const FmrFinger & owner)
		{
			SetOwner(owner);
		}

		friend class FmrFinger;
	protected:
		NInt GetCapacity() const
		{
			NInt value;
			NCheck(FmrFingerGetFingerViewCapacity(this->GetOwnerHandle(), &value));
			return value;
		}

		void SetCapacity(NInt value)
		{
			NCheck(FmrFingerSetFingerViewCapacity(this->GetOwnerHandle(), value));
		}

		void RemoveAt(NInt index)
		{
			NCheck(FmrFingerRemoveFingerView(this->GetOwnerHandle(), index));
		}

		void Clear()
		{
			NCheck(FmrFingerClearFingerViews(this->GetOwnerHandle()));
		}

		FmrFingerView Add(NUInt flags = 0)
		{
			HFmrFingerView hFingerView;
			NCheck(FmrFingerAddFingerView(this->GetOwnerHandle(), flags | N_OBJECT_REF_RET, &hFingerView));
			return FromHandle<FmrFingerView>(hFingerView, true);
		}
	};

public:
	static NSizeType CalculateSize(BdifStandard standard, const NSizeType * arFingerViewSizes, NInt fingerViewCount)
	{
		NSizeType size;
		NCheck(FmrFingerCalculateSize(standard, fingerViewCount, arFingerViewSizes, &size));
		return size;
	}

	BdifFPPosition GetFingerPosition() const
	{
		BdifFPPosition value;
		NCheck(FmrFingerGetFingerPosition(GetHandle(), &value));
		return value;
	}

	void SetFingerPosition(BdifFPPosition value)
	{
		NCheck(FmrFingerSetFingerPosition(GetHandle(), value));
	}

	FingerViewCollection GetFingerViews()
	{
		return FingerViewCollection(*this);
	}

	const FingerViewCollection GetFingerViews() const
	{
		return FingerViewCollection(*this);
	}

	FMRecord GetOwner() const;
};
#include <Core/NReDeprecate.h>

}}}

#include <Biometrics/Standards/FMRecord.hpp>

namespace Neurotec { namespace Biometrics { namespace Standards
{

inline FMRecord FmrFinger::GetOwner() const
{
	return NObject::GetOwner<FMRecord>();
}

}}}

#endif // !FMR_FINGER_HPP_INCLUDED
