#ifndef N_MATCHING_DETAILS_HPP_INCLUDED
#define N_MATCHING_DETAILS_HPP_INCLUDED

#include <Biometrics/NFMatchingDetails.hpp>
#include <Biometrics/NLMatchingDetails.hpp>
#include <Biometrics/NEMatchingDetails.hpp>
#include <Biometrics/NSMatchingDetails.hpp>
#include <Core/NObject.hpp>
namespace Neurotec { namespace Biometrics
{
#include <Biometrics/NMatchingDetails.h>
}}

namespace Neurotec { namespace Biometrics
{

class NMatchingDetails : public NMatchingDetailsBase
{
	N_DECLARE_OBJECT_CLASS(NMatchingDetails, NMatchingDetailsBase)

private:

public:
	class FingerCollection : public ::Neurotec::Collections::NCollectionBase<NFMatchingDetails, NMatchingDetails,
		NMatchingDetailsGetFingerCount, NMatchingDetailsGetFingerEx>
	{
		FingerCollection(const NMatchingDetails & owner)
		{
			SetOwner(owner);
		}

		friend class NMatchingDetails;
	};

	class FaceCollection : public ::Neurotec::Collections::NCollectionBase<NLMatchingDetails, NMatchingDetails,
		NMatchingDetailsGetFaceCount, NMatchingDetailsGetFaceEx>
	{
		FaceCollection(const NMatchingDetails & owner)
		{
			SetOwner(owner);
		}

		friend class NMatchingDetails;
	};

	class IrisCollection : public ::Neurotec::Collections::NCollectionBase<NEMatchingDetails, NMatchingDetails,
		NMatchingDetailsGetIrisCount, NMatchingDetailsGetIrisEx>
	{
		IrisCollection(const NMatchingDetails & owner)
		{
			SetOwner(owner);
		}

		friend class NMatchingDetails;
	};

	class PalmCollection : public ::Neurotec::Collections::NCollectionBase<NFMatchingDetails, NMatchingDetails,
		NMatchingDetailsGetPalmCount, NMatchingDetailsGetPalmEx>
	{
		PalmCollection(const NMatchingDetails & owner)
		{
			SetOwner(owner);
		}

		friend class NMatchingDetails;
	};

	class VoiceCollection : public ::Neurotec::Collections::NCollectionBase<NSMatchingDetails, NMatchingDetails,
		NMatchingDetailsGetVoiceCount, NMatchingDetailsGetVoiceEx>
	{
		VoiceCollection(const NMatchingDetails & owner)
		{
			SetOwner(owner);
		}

		friend class NMatchingDetails;
	};

private:
	static HNMatchingDetails Create(const ::Neurotec::IO::NStream & stream, NUInt flags)
	{
		HNMatchingDetails handle;
		NCheck(NMatchingDetailsCreateFromStream(stream.GetHandle(), flags, &handle));
		return handle;
	}

	static HNMatchingDetails Create(const ::Neurotec::IO::NBuffer & buffer, NUInt flags, NSizeType * pSize)
	{
		HNMatchingDetails handle;
		NCheck(NMatchingDetailsCreateFromMemoryN(buffer.GetHandle(), flags, pSize, &handle));
		return handle;
	}

	static HNMatchingDetails Create(const void * pBuffer, NSizeType bufferSize, NUInt flags, NSizeType * pSize)
	{
		HNMatchingDetails handle;
		NCheck(NMatchingDetailsCreateFromMemory(pBuffer, bufferSize, flags, pSize, &handle));
		return handle;
	}

public:
	explicit NMatchingDetails(const ::Neurotec::IO::NStream & stream, NUInt flags = 0)
		: NMatchingDetailsBase(Create(stream, flags), true)
	{
	}

	explicit NMatchingDetails(const ::Neurotec::IO::NBuffer & buffer, NUInt flags = 0, NSizeType * pSize = NULL)
		: NMatchingDetailsBase(Create(buffer, flags, pSize), true)
	{
	}

	NMatchingDetails(const void * pBuffer, NSizeType bufferSize, NUInt flags = 0, NSizeType * pSize = NULL)
		: NMatchingDetailsBase(Create(pBuffer, bufferSize, flags, pSize), true)
	{
	}

	using NObject::Save;

	NInt GetFingersScore() const
	{
		NInt value;
		NCheck(NMatchingDetailsGetFingersScore(GetHandle(), &value));
		return value;
	}

	FingerCollection GetFingers()
	{
		return FingerCollection(*this);
	}

	const FingerCollection GetFingers() const
	{
		return FingerCollection(*this);
	}

	NInt GetFacesScore() const
	{
		NInt value;
		NCheck(NMatchingDetailsGetFacesScore(GetHandle(), &value));
		return value;
	}

	NInt GetFacesMatchedIndex() const
	{
		NInt value;
		NCheck(NMatchingDetailsGetFacesMatchedIndex(GetHandle(), &value));
		return value;
	}

	FaceCollection GetFaces()
	{
		return FaceCollection(*this);
	}

	const FaceCollection GetFaces() const
	{
		return FaceCollection(*this);
	}

	NInt GetIrisesScore() const
	{
		NInt value;
		NCheck(NMatchingDetailsGetIrisesScore(GetHandle(), &value));
		return value;
	}

	IrisCollection GetIrises()
	{
		return IrisCollection(*this);
	}

	const IrisCollection GetIrises() const
	{
		return IrisCollection(*this);
	}

	NInt GetPalmsScore() const
	{
		NInt value;
		NCheck(NMatchingDetailsGetPalmsScore(GetHandle(), &value));
		return value;
	}

	PalmCollection GetPalms()
	{
		return PalmCollection(*this);
	}

	const PalmCollection GetPalms() const
	{
		return PalmCollection(*this);
	}

	NInt GetVoicesScore() const
	{
		NInt value;
		NCheck(NMatchingDetailsGetVoicesScore(GetHandle(), &value));
		return value;
	}

	VoiceCollection GetVoices()
	{
		return VoiceCollection(*this);
	}

	const VoiceCollection GetVoices() const
	{
		return VoiceCollection(*this);
	}
};

}}

#endif // !N_MATCHING_DETAILS_HPP_INCLUDED
