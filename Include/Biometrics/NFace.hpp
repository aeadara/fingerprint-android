#include <Biometrics/NBiometric.hpp>
#include <Biometrics/NLAttributes.hpp>

#ifndef N_FACE_HPP_INCLUDED
#define N_FACE_HPP_INCLUDED

#include <Images/NImage.hpp>
namespace Neurotec { namespace Biometrics
{
using ::Neurotec::Images::HNImage;
#include <Biometrics/NFace.h>
}}

namespace Neurotec { namespace Biometrics
{

class NFace : public NBiometric
{
	N_DECLARE_OBJECT_CLASS(NFace, NBiometric)

public:
	class ObjectCollection : public ::Neurotec::Collections::NCollectionWithChangeNotifications<NLAttributes, NFace,
		NFaceGetObjectCount, NFaceGetObject, NFaceGetObjects, NFaceAddObjectsCollectionChanged, NFaceRemoveObjectsCollectionChanged>
	{
		ObjectCollection(const NFace & owner)
		{
			SetOwner(owner);
		}

		friend class NFace;
	};

private:
	static HNFace Create()
	{
		HNFace handle;
		NCheck(NFaceCreate(&handle));
		return handle;
	}

public:
	NFace()
		: NBiometric(Create(), true)
	{
	}

	static NFace FromImageAndAttributes(const ::Neurotec::Images::NImage & image, const ::Neurotec::Biometrics::NLAttributes & attributes)
	{
		HNFace hFace;
		NCheck(NFaceFromImageAndAttributes(image.GetHandle(), attributes.GetHandle(), &hFace));
		return FromHandle<NFace>(hFace);
	}

	::Neurotec::Images::NImage GetImage() const
	{
		HNImage hValue;
		NCheck(NFaceGetImage(GetHandle(), &hValue));
		return FromHandle< ::Neurotec::Images::NImage>(hValue, true);
	}

	void SetImage(const ::Neurotec::Images::NImage & value)
	{
		NCheck(NFaceSetImage(GetHandle(), value.GetHandle()));
	}

	ObjectCollection GetObjects()
	{
		return ObjectCollection(*this);
	}

	const ObjectCollection GetObjects() const
	{
		return ObjectCollection(*this);
	}
};

}}

#endif // !N_FACE_HPP_INCLUDED
