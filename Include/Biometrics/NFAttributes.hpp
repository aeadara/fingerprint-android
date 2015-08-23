#ifndef NF_ATTRIBUTES_HPP_INCLUDED
#define NF_ATTRIBUTES_HPP_INCLUDED

#include <Biometrics/NBiometricAttributes.hpp>
#include <Biometrics/NFRecord.hpp>
#include <Geometry/NGeometry.hpp>
namespace Neurotec { namespace Biometrics
{
using ::Neurotec::Geometry::NRect_;
#include <Biometrics/NFAttributes.h>
}}

namespace Neurotec { namespace Biometrics
{

class NFrictionRidge;

class NFAttributes : public NBiometricAttributes
{
	N_DECLARE_OBJECT_CLASS(NFAttributes, NBiometricAttributes)

public:
	class PossiblePositionCollection : public ::Neurotec::Collections::NCollectionWithAllOutBase<NFPosition, NFAttributes,
		NFAttributesGetPossiblePositionCount, NFAttributesGetPossiblePosition, NFAttributesGetPossiblePositions>
	{
		PossiblePositionCollection(const NFAttributes & owner)
		{
			SetOwner(owner);
		}

		friend class NFAttributes;

	public:
		void Set(NInt index, NFPosition value)
		{
			NCheck(NFAttributesSetPossiblePosition(this->GetOwnerHandle(), index, value));
		}

		NInt Add(NFPosition value)
		{
			NInt index;
			NCheck(NFAttributesAddPossiblePosition(this->GetOwnerHandle(), value, &index));
			return index;
		}

		void Insert(NInt index, NFPosition value)
		{
			NCheck(NFAttributesInsertPossiblePosition(this->GetOwnerHandle(), index, value));
		}

		void RemoveAt(NInt index)
		{
			NCheck(NFAttributesRemovePossiblePositionAt(this->GetOwnerHandle(), index));
		}

		void Clear()
		{
			NCheck(NFAttributesClearPossiblePositions(this->GetOwnerHandle()));
		}
	};

private:
	static HNFAttributes Create(NFImpressionType impressionType, NFPosition position)
	{
		HNFAttributes handle;
		NCheck(NFAttributesCreate(impressionType, position, &handle));
		return handle;
	}

public:
	NFAttributes(NFImpressionType impressionType, NFPosition position)
		: NBiometricAttributes(Create(impressionType, position), true)
	{
	}

	NFrictionRidge GetOwner() const;

	NFImpressionType GetImpressionType() const
	{
		NFImpressionType value;
		NCheck(NFAttributesGetImpressionType(GetHandle(), &value));
		return value;
	}

	NFPosition GetPosition() const
	{
		NFPosition value;
		NCheck(NFAttributesGetPosition(GetHandle(), &value));
		return value;
	}

	NInt GetImageIndex() const
	{
		NInt value;
		NCheck(NFAttributesGetImageIndex(GetHandle(), &value));
		return value;
	}

	void SetImageIndex(NInt value)
	{
		NCheck(NFAttributesSetImageIndex(GetHandle(), value));
	}

	::Neurotec::Geometry::NRect GetBoundingRect() const
	{
		::Neurotec::Geometry::NRect value;
		NCheck(NFAttributesGetBoundingRect(GetHandle(), &value));
		return value;
	}

	void SetBoundingRect(const ::Neurotec::Geometry::NRect & value)
	{
		NCheck(NFAttributesSetBoundingRect(GetHandle(), &value));
	}

	NFloat GetRotation() const
	{
		NFloat value;
		NCheck(NFAttributesGetRotation(GetHandle(), &value));
		return value;
	}

	void SetRotation(NFloat value)
	{
		NCheck(NFAttributesSetRotation(GetHandle(), value));
	}

	NFPatternClass GetPatternClass() const
	{
		NFPatternClass value;
		NCheck(NFAttributesGetPatternClass(GetHandle(), &value));
		return value;
	}

	void SetPatternClass(NFPatternClass value)
	{
		NCheck(NFAttributesSetPatternClass(GetHandle(), value));
	}

	NByte GetPatternClassConfidence() const
	{
		NByte value;
		NCheck(NFAttributesGetPatternClassConfidence(GetHandle(), &value));
		return value;
	}

	void SetPatternClassConfidence(NByte value)
	{
		NCheck(NFAttributesSetPatternClassConfidence(GetHandle(), value));
	}

	NfiqQuality GetNfiqQuality() const
	{
		NfiqQuality value;
		NCheck(NFAttributesGetNfiqQuality(GetHandle(), &value));
		return value;
	}

	void SetNfiqQuality(NfiqQuality value)
	{
		NCheck(NFAttributesSetNfiqQuality(GetHandle(), value));
	}

	NFRecord GetTemplate() const
	{
		return GetObject<HandleType, NFRecord>(NFAttributesGetTemplate, true);
	}

	void SetTemplate(const NFRecord & value)
	{
		NCheck(NFAttributesSetTemplate(GetHandle(), value.GetHandle()));
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

#include <Biometrics/NFrictionRidge.hpp>

namespace Neurotec { namespace Biometrics
{

inline NFrictionRidge NFAttributes::GetOwner() const
{
	return NObject::GetOwner<NFrictionRidge>();
}

}}

#endif // !NF_ATTRIBUTES_HPP_INCLUDED
