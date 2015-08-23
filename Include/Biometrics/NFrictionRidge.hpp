#include <Biometrics/NBiometric.hpp>
#include <Biometrics/NFAttributes.hpp>

#ifndef N_FRICTION_RIDGE_HPP_INCLUDED
#define N_FRICTION_RIDGE_HPP_INCLUDED

#include <Images/NImage.hpp>
namespace Neurotec { namespace Biometrics
{
using ::Neurotec::Images::HNImage;
#include <Biometrics/NFrictionRidge.h>
}}

namespace Neurotec { namespace Biometrics
{

class NFrictionRidge : public NBiometric
{
	N_DECLARE_OBJECT_CLASS(NFrictionRidge, NBiometric)

public:
	class ObjectCollection : public ::Neurotec::Collections::NCollectionWithChangeNotifications<NFAttributes, NFrictionRidge,
		NFrictionRidgeGetObjectCount, NFrictionRidgeGetObject, NFrictionRidgeGetObjects,
		NFrictionRidgeAddObjectsCollectionChanged, NFrictionRidgeRemoveObjectsCollectionChanged>
	{
		ObjectCollection(const NFrictionRidge & owner)
		{
			SetOwner(owner);
		}

		friend class NFrictionRidge;
	};

	class PossiblePositionCollection : public ::Neurotec::Collections::NCollectionWithAllOutBase<NFPosition, NFrictionRidge,
		NFrictionRidgeGetPossiblePositionCount, NFrictionRidgeGetPossiblePosition, NFrictionRidgeGetPossiblePositions>
	{
		PossiblePositionCollection(const NFrictionRidge & owner)
		{
			SetOwner(owner);
		}

		friend class NFrictionRidge;

	public:
		void Set(NInt index, NFPosition value)
		{
			NCheck(NFrictionRidgeSetPossiblePosition(this->GetOwnerHandle(), index, value));
		}

		NInt Add(NFPosition value)
		{
			NInt index;
			NCheck(NFrictionRidgeAddPossiblePosition(this->GetOwnerHandle(), value, &index));
			return index;
		}

		void Insert(NInt index, NFPosition value)
		{
			NCheck(NFrictionRidgeInsertPossiblePosition(this->GetOwnerHandle(), index, value));
		}

		void RemoveAt(NInt index)
		{
			NCheck(NFrictionRidgeRemovePossiblePositionAt(this->GetOwnerHandle(), index));
		}

		void Clear()
		{
			NCheck(NFrictionRidgeClearPossiblePositions(this->GetOwnerHandle()));
		}
	};

public:
	static NFrictionRidge FromPosition(NFPosition position)
	{
		HNFrictionRidge hFrictionRidge;
		NCheck(NFrictionRidgeFromPosition(position, &hFrictionRidge));
		return FromHandle<NFrictionRidge>(hFrictionRidge);
	}

	static NFrictionRidge FromImageAndTemplate(const ::Neurotec::Images::NImage & image, const ::Neurotec::Biometrics::NFRecord & record)
	{
		HNFrictionRidge hFrictionRidge;
		NCheck(NFrictionRidgeFromImageAndTemplate(image.GetHandle(), record.GetHandle(), &hFrictionRidge));
		return FromHandle<NFrictionRidge>(hFrictionRidge);
	}

	::Neurotec::Images::NImage GetImage() const
	{
		HNImage hValue;
		NCheck(NFrictionRidgeGetImage(GetHandle(), &hValue));
		return FromHandle< ::Neurotec::Images::NImage>(hValue, true);
	}

	void SetImage(const ::Neurotec::Images::NImage & value)
	{
		NCheck(NFrictionRidgeSetImage(GetHandle(), value.GetHandle()));
	}

	::Neurotec::Images::NImage GetProcessedImage() const
	{
		HNImage hValue;
		NCheck(NFrictionRidgeGetProcessedImage(GetHandle(), &hValue));
		return FromHandle< ::Neurotec::Images::NImage>(hValue, true);
	}

	NFPosition GetPosition() const
	{
		NFPosition value;
		NCheck(NFrictionRidgeGetPosition(GetHandle(), &value));
		return value;
	}

	void SetPosition(NFPosition value)
	{
		NCheck(NFrictionRidgeSetPosition(GetHandle(), value));
	}

	NFImpressionType GetImpressionType() const
	{
		NFImpressionType value;
		NCheck(NFrictionRidgeGetImpressionType(GetHandle(), &value));
		return value;
	}

	void SetImpressionType(NFImpressionType value)
	{
		NCheck(NFrictionRidgeSetImpressionType(GetHandle(), value));
	}

	ObjectCollection GetObjects()
	{
		return ObjectCollection(*this);
	}

	const ObjectCollection GetObjects() const
	{
		return ObjectCollection(*this);
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

#endif // !N_FRICTION_RIDGE_HPP_INCLUDED
