#include <Biometrics/Standards/FirFingerView.hpp>

#ifndef FIR_FINGER_HPP_INCLUDED
#define FIR_FINGER_HPP_INCLUDED

#include <Biometrics/Standards/BdifTypes.hpp>
#include <Images/NImage.hpp>
namespace Neurotec { namespace Biometrics { namespace Standards
{
using ::Neurotec::Images::HNImage;
#include <Biometrics/Standards/FirFinger.h>
}}}

namespace Neurotec { namespace Biometrics { namespace Standards
{

#undef FIRF_MAX_FINGER_VIEW_COUNT

#undef FIRF_PROCESS_FIRST_FINGER_VIEW_ONLY

const NInt FIRF_MAX_FINGER_VIEW_COUNT = 255;

const NUInt FIRF_PROCESS_FIRST_FINGER_VIEW_ONLY = 0x00001000;

class FIRecord;

#include <Core/NNoDeprecate.h>
class N_DEPRECATED("class is deprecated, use FirFingerView instead.") FirFinger : public NObject
{
	N_DECLARE_OBJECT_CLASS(FirFinger, NObject)

public:
	class FingerViewCollection : public ::Neurotec::Collections::NCollectionBase<FirFingerView, FirFinger,
		FirFingerGetFingerViewCount, FirFingerGetFingerViewEx>
	{
		FingerViewCollection(const FirFinger & owner)
		{
			SetOwner(owner);
		}

		friend class FirFinger;
	public:
		NInt GetCapacity() const
		{
			NInt value;
			NCheck(FirFingerGetFingerViewCapacity(this->GetOwnerHandle(), &value));
			return value;
		}

		void SetCapacity(NInt value)
		{
			NCheck(FirFingerSetFingerViewCapacity(this->GetOwnerHandle(), value));
		}

		void RemoveAt(NInt index)
		{
			NCheck(FirFingerRemoveFingerView(this->GetOwnerHandle(), index));
		}

		void Clear()
		{
			NCheck(FirFingerClearFingerViews(this->GetOwnerHandle()));
		}

		FirFingerView Add(NUShort horzLineLength, NUShort vertLineLength, const ::Neurotec::IO::NBuffer & imageData, NUInt flags = 0)
		{
			HFirFingerView hFingerView;
			NCheck(FirFingerAddFingerViewN(this->GetOwnerHandle(), horzLineLength, vertLineLength, imageData.GetHandle(), flags | N_OBJECT_REF_RET, &hFingerView));
			return FromHandle<FirFingerView>(hFingerView, true);
		}

		FirFingerView Add(NUShort horzLineLength, NUShort vertLineLength, const void * pImageData, NSizeType imageDataLength, NUInt flags = 0)
		{
			HFirFingerView hFingerView;
			NCheck(FirFingerAddFingerView(this->GetOwnerHandle(), horzLineLength, vertLineLength, pImageData, imageDataLength, flags | N_OBJECT_REF_RET, &hFingerView));
			return FromHandle<FirFingerView>(hFingerView, true);
		}

		FirFingerView Add(const ::Neurotec::Images::NImage & image, NUInt flags = 0)
		{
			HFirFingerView hFingerView;
			NCheck(FirFingerAddFingerViewFromNImage(this->GetOwnerHandle(), image.GetHandle(), flags | N_OBJECT_REF_RET, &hFingerView));
			return FromHandle<FirFingerView>(hFingerView, true);
		}
	};

public:
	static NSizeType CalculateSize(BdifStandard standard, const NSizeType * arFingerViewSizes, NInt fingerViewCount)
	{
		NSizeType size;
		NCheck(FirFingerCalculateSize(standard, fingerViewCount, arFingerViewSizes, &size));
		return size;
	}

	BdifFPPosition GetPosition() const
	{
		BdifFPPosition value;
		NCheck(FirFingerGetPosition(GetHandle(), &value));
		return value;
	}

	void SetPosition(BdifFPPosition value)
	{
		NCheck(FirFingerSetPosition(GetHandle(), value));
	}

	FingerViewCollection GetFingerViews()
	{
		return FingerViewCollection(*this);
	}

	const FingerViewCollection GetFingerViews() const
	{
		return FingerViewCollection(*this);
	}

	FIRecord GetOwner() const;
};
#include <Core/NReDeprecate.h>

}}}

#include <Biometrics/Standards/FIRecord.hpp>

namespace Neurotec { namespace Biometrics { namespace Standards
{

inline FIRecord FirFinger::GetOwner() const
{
	return NObject::GetOwner<FIRecord>();
}

}}}

#endif // !FIR_FINGER_HPP_INCLUDED
