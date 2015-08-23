#include <Biometrics/NBiometric.hpp>
#include <Biometrics/NEAttributes.hpp>

#ifndef N_IRIS_HPP_INCLUDED
#define N_IRIS_HPP_INCLUDED

#include <Images/NImage.hpp>
namespace Neurotec { namespace Biometrics
{
using ::Neurotec::Images::HNImage;
#include <Biometrics/NIris.h>
}}

namespace Neurotec { namespace Biometrics
{

class NIris : public NBiometric
{
	N_DECLARE_OBJECT_CLASS(NIris, NBiometric)

public:
	class ObjectCollection : public ::Neurotec::Collections::NCollectionWithChangeNotifications<NEAttributes, NIris,
		NIrisGetObjectCount, NIrisGetObject, NIrisGetObjects,
		NIrisAddObjectsCollectionChanged, NIrisRemoveObjectsCollectionChanged>
	{
		ObjectCollection(const NIris & owner)
		{
			SetOwner(owner);
		}

		friend class NIris;
	};

private:
	static HNIris Create()
	{
		HNIris handle;
		NCheck(NIrisCreate(&handle));
		return handle;
	}

public:
	NIris()
		: NBiometric(Create(), true)
	{
	}

	static NIris FromImageAndTemplate(const ::Neurotec::Images::NImage & image, const NERecord & record)
	{
		HNIris hIris = NULL;
		NCheck(NIrisFromImageAndTemplate(image.GetHandle(), record.GetHandle(), &hIris));
		return FromHandle<NIris>(hIris);
	}

	::Neurotec::Images::NImage GetImage() const
	{
		HNImage hValue;
		NCheck(NIrisGetImage(GetHandle(), &hValue));
		return FromHandle< ::Neurotec::Images::NImage>(hValue, true);
	}

	void SetImage(const ::Neurotec::Images::NImage & value)
	{
		NCheck(NIrisSetImage(GetHandle(), value.GetHandle()));
	}

	NEPosition GetPosition() const
	{
		NEPosition value;
		NCheck(NIrisGetPosition(GetHandle(), &value));
		return value;
	}

	void SetPosition(NEPosition value)
	{
		NCheck(NIrisSetPosition(GetHandle(), value));
	}

	NEImageType GetImageType() const
	{
		NEImageType value;
		NCheck(NIrisGetImageType(GetHandle(), &value));
		return value;
	}

	void SetImageType(NEImageType value)
	{
		NCheck(NIrisSetImageType(GetHandle(), value));
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

#endif // !N_IRIS_HPP_INCLUDED
