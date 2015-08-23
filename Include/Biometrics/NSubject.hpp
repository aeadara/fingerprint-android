#include <Biometrics/NFinger.hpp>
#include <Biometrics/NFace.hpp>
#include <Biometrics/NIris.hpp>
#include <Biometrics/NPalm.hpp>
#include <Biometrics/NVoice.hpp>
#include <Biometrics/NMatchingResult.hpp>
#include <Biometrics/Standards/ANTemplate.hpp>
#include <Biometrics/Standards/FCRecord.hpp>
#include <Biometrics/Standards/FIRecord.hpp>
#include <Biometrics/Standards/FMRecord.hpp>
#include <Biometrics/Standards/IIRecord.hpp>
#include <Biometrics/Standards/CbeffRecord.hpp>
#include <Biometrics/Standards/BdifTypes.hpp>

#ifndef N_SUBJECT_HPP_INCLUDED
#define N_SUBJECT_HPP_INCLUDED

#include <Core/NExpandableObject.hpp>
#include <Biometrics/NBiometricTypes.hpp>
#include <Biometrics/NTemplate.hpp>
namespace Neurotec { namespace Biometrics
{
using ::Neurotec::Biometrics::Standards::HANTemplate;
using ::Neurotec::Biometrics::Standards::HFCRecord;
using ::Neurotec::Biometrics::Standards::HFIRecord;
using ::Neurotec::Biometrics::Standards::HFMRecord;
using ::Neurotec::Biometrics::Standards::HIIRecord;
using ::Neurotec::Biometrics::Standards::HCbeffRecord;
using ::Neurotec::Biometrics::Standards::BdifStandard;
#include <Biometrics/NSubject.h>
}}

namespace Neurotec { namespace Biometrics
{
class NSubject : public NExpandableObject
{
	N_DECLARE_OBJECT_CLASS(NSubject, NExpandableObject)

public:
	class FingerCollection : public ::Neurotec::Collections::NCollectionWithChangeNotifications<NFinger, NSubject,
		NSubjectGetFingerCount, NSubjectGetFinger, NSubjectGetFingers,
		NSubjectAddFingersCollectionChanged, NSubjectRemoveFingersCollectionChanged>
	{
		FingerCollection(const NSubject & owner)
		{
			SetOwner(owner);
		}

		friend class NSubject;
	public:
		NInt GetCapacity() const
		{
			NInt result;
			NCheck(NSubjectGetFingerCapacity(this->GetOwnerHandle(), &result));
			return result;
		}

		void SetCapacity(NInt value)
		{
			NCheck(NSubjectSetFingerCapacity(this->GetOwnerHandle(), value));
		}

		void Set(NInt index, const NFinger & value)
		{
			NCheck(NSubjectSetFinger(this->GetOwnerHandle(), index, value.GetHandle()));
		}

		NInt Add(const NFinger & value)
		{
			NInt result;
			NCheck(NSubjectAddFinger(this->GetOwnerHandle(), value.GetHandle(), &result));
			return result;
		}

		void Insert(NInt index, const NFinger & value)
		{
			NCheck(NSubjectInsertFinger(this->GetOwnerHandle(), index, value.GetHandle()));
		}

		void RemoveAt(NInt index)
		{
			NCheck(NSubjectRemoveFingerAt(this->GetOwnerHandle(), index));
		}

		void Clear()
		{
			NCheck(NSubjectClearFingers(this->GetOwnerHandle()));
		}
	};

	class FaceCollection : public ::Neurotec::Collections::NCollectionWithChangeNotifications<NFace, NSubject,
		NSubjectGetFaceCount, NSubjectGetFace, NSubjectGetFaces,
		NSubjectAddFacesCollectionChanged, NSubjectRemoveFacesCollectionChanged>
	{
		FaceCollection(const NSubject & owner)
		{
			SetOwner(owner);
		}

		friend class NSubject;
	public:
		NInt GetCapacity() const
		{
			NInt result;
			NCheck(NSubjectGetFaceCapacity(this->GetOwnerHandle(), &result));
			return result;
		}

		void SetCapacity(NInt value)
		{
			NCheck(NSubjectSetFaceCapacity(this->GetOwnerHandle(), value));
		}

		void Set(NInt index, const NFace & value)
		{
			NCheck(NSubjectSetFace(this->GetOwnerHandle(), index, value.GetHandle()));
		}

		NInt Add(const NFace & value)
		{
			NInt result;
			NCheck(NSubjectAddFace(this->GetOwnerHandle(), value.GetHandle(), &result));
			return result;
		}

		void Insert(NInt index, const NFace & value)
		{
			NCheck(NSubjectInsertFace(this->GetOwnerHandle(), index, value.GetHandle()));
		}

		void RemoveAt(NInt index)
		{
			NCheck(NSubjectRemoveFaceAt(this->GetOwnerHandle(), index));
		}

		void Clear()
		{
			NCheck(NSubjectClearFaces(this->GetOwnerHandle()));
		}

	};

	class IrisCollection : public ::Neurotec::Collections::NCollectionWithChangeNotifications<NIris, NSubject,
		NSubjectGetIrisCount, NSubjectGetIris, NSubjectGetIrises,
		NSubjectAddIrisesCollectionChanged, NSubjectRemoveIrisesCollectionChanged>
	{
		IrisCollection(const NSubject & owner)
		{
			SetOwner(owner);
		}

		friend class NSubject;
	public:
		NInt GetCapacity() const
		{
			NInt result;
			NCheck(NSubjectGetIrisCapacity(this->GetOwnerHandle(), &result));
			return result;
		}

		void SetCapacity(NInt value)
		{
			NCheck(NSubjectSetIrisCapacity(this->GetOwnerHandle(), value));
		}

		void Set(NInt index, const NIris & value)
		{
			NCheck(NSubjectSetIris(this->GetOwnerHandle(), index, value.GetHandle()));
		}

		NInt Add(const NIris & value)
		{
			NInt result;
			NCheck(NSubjectAddIris(this->GetOwnerHandle(), value.GetHandle(), &result));
			return result;
		}

		void Insert(NInt index, const NIris & value)
		{
			NCheck(NSubjectInsertIris(this->GetOwnerHandle(), index, value.GetHandle()));
		}

		void RemoveAt(NInt index)
		{
			NCheck(NSubjectRemoveIrisAt(this->GetOwnerHandle(), index));
		}

		void Clear()
		{
			NCheck(NSubjectClearIrises(this->GetOwnerHandle()));
		}

	};

	class PalmCollection : public ::Neurotec::Collections::NCollectionWithChangeNotifications<NPalm, NSubject,
		NSubjectGetPalmCount, NSubjectGetPalm, NSubjectGetPalms,
		NSubjectAddPalmsCollectionChanged, NSubjectRemovePalmsCollectionChanged>
	{
		PalmCollection(const NSubject & owner)
		{
			SetOwner(owner);
		}

		friend class NSubject;
	public:
		NInt GetCapacity() const
		{
			NInt result;
			NCheck(NSubjectGetPalmCapacity(this->GetOwnerHandle(), &result));
			return result;
		}

		void SetCapacity(NInt value)
		{
			NCheck(NSubjectSetPalmCapacity(this->GetOwnerHandle(), value));
		}

		void Set(NInt index, const NPalm & value)
		{
			NCheck(NSubjectSetPalm(this->GetOwnerHandle(), index, value.GetHandle()));
		}

		NInt Add(const NPalm & value)
		{
			NInt result;
			NCheck(NSubjectAddPalm(this->GetOwnerHandle(), value.GetHandle(), &result));
			return result;
		}

		void Insert(NInt index, const NPalm & value)
		{
			NCheck(NSubjectInsertPalm(this->GetOwnerHandle(), index, value.GetHandle()));
		}

		void RemoveAt(NInt index)
		{
			NCheck(NSubjectRemovePalmAt(this->GetOwnerHandle(), index));
		}

		void Clear()
		{
			NCheck(NSubjectClearPalms(this->GetOwnerHandle()));
		}

	};

	class VoiceCollection : public ::Neurotec::Collections::NCollectionWithChangeNotifications<NVoice, NSubject,
		NSubjectGetVoiceCount, NSubjectGetVoice, NSubjectGetVoices,
		NSubjectAddVoicesCollectionChanged, NSubjectRemoveVoicesCollectionChanged>
	{
		VoiceCollection(const NSubject & owner)
		{
			SetOwner(owner);
		}

		friend class NSubject;
	public:
		NInt GetCapacity() const
		{
			NInt result;
			NCheck(NSubjectGetVoiceCapacity(this->GetOwnerHandle(), &result));
			return result;
		}

		void SetCapacity(NInt value)
		{
			NCheck(NSubjectSetVoiceCapacity(this->GetOwnerHandle(), value));
		}

		void Set(NInt index, const NVoice & value)
		{
			NCheck(NSubjectSetVoice(this->GetOwnerHandle(), index, value.GetHandle()));
		}

		NInt Add(const NVoice & value)
		{
			NInt result;
			NCheck(NSubjectAddVoice(this->GetOwnerHandle(), value.GetHandle(), &result));
			return result;
		}

		void Insert(NInt index, const NVoice & value)
		{
			NCheck(NSubjectInsertVoice(this->GetOwnerHandle(), index, value.GetHandle()));
		}

		void RemoveAt(NInt index)
		{
			NCheck(NSubjectRemoveVoiceAt(this->GetOwnerHandle(), index));
		}

		void Clear()
		{
			NCheck(NSubjectClearVoices(this->GetOwnerHandle()));
		}

	};

	class MissingFingerCollection : public ::Neurotec::Collections::NCollectionWithAllOutBase<NFPosition, NSubject,
		NSubjectGetMissingFingerCount, NSubjectGetMissingFinger, NSubjectGetMissingFingers>
	{
		MissingFingerCollection(const NSubject & owner)
		{
			SetOwner(owner);
		}

		friend class NSubject;
	public:
		NInt GetCapacity() const
		{
			NInt result;
			NCheck(NSubjectGetMissingFingerCapacity(this->GetOwnerHandle(), &result));
			return result;
		}

		void SetCapacity(NInt value)
		{
			NCheck(NSubjectSetMissingFingerCapacity(this->GetOwnerHandle(), value));
		}

		void Set(NInt index, NFPosition value)
		{
			NCheck(NSubjectSetMissingFinger(this->GetOwnerHandle(), index, value));
		}

		NInt Add(NFPosition value)
		{
			NInt result;
			NCheck(NSubjectAddMissingFinger(this->GetOwnerHandle(), value, &result));
			return result;
		}

		void Insert(NInt index, NFPosition value)
		{
			NCheck(NSubjectInsertMissingFinger(this->GetOwnerHandle(), index, value));
		}

		void RemoveAt(NInt index)
		{
			NCheck(NSubjectRemoveMissingFingerAt(this->GetOwnerHandle(), index));
		}

		void Clear()
		{
			NCheck(NSubjectClearMissingFingers(this->GetOwnerHandle()));
		}

	};

	class MissingEyeCollection : public ::Neurotec::Collections::NCollectionWithAllOutBase<NEPosition, NSubject,
		NSubjectGetMissingEyeCount, NSubjectGetMissingEye, NSubjectGetMissingEyes>
	{
		MissingEyeCollection(const NSubject & owner)
		{
			SetOwner(owner);
		}

		friend class NSubject;
	public:
		NInt GetCapacity() const
		{
			NInt result;
			NCheck(NSubjectGetMissingEyeCapacity(this->GetOwnerHandle(), &result));
			return result;
		}

		void SetCapacity(NInt value)
		{
			NCheck(NSubjectSetMissingEyeCapacity(this->GetOwnerHandle(), value));
		}

		void Set(NInt index, NEPosition value)
		{
			NCheck(NSubjectSetMissingEye(this->GetOwnerHandle(), index, value));
		}

		NInt Add(NEPosition value)
		{
			NInt result;
			NCheck(NSubjectAddMissingEye(this->GetOwnerHandle(), value, &result));
			return result;
		}

		void Insert(NInt index, NEPosition value)
		{
			NCheck(NSubjectInsertMissingEye(this->GetOwnerHandle(), index, value));
		}

		void RemoveAt(NInt index)
		{
			NCheck(NSubjectRemoveMissingEyeAt(this->GetOwnerHandle(), index));
		}

		void Clear()
		{
			NCheck(NSubjectClearMissingEyes(this->GetOwnerHandle()));
		}

	};

	class RelatedSubjectCollection;

	class MatchingResultCollection : public ::Neurotec::Collections::NCollectionWithAllOutBase<NMatchingResult, NSubject,
		NSubjectGetMatchingResultCount, NSubjectGetMatchingResult, NSubjectGetMatchingResults>
	{
		MatchingResultCollection(const NSubject & owner)
		{
			SetOwner(owner);
		}

		friend class NSubject;
	public:

	};

private:
	static HNSubject Create()
	{
		HNSubject handle;
		NCheck(NSubjectCreate(&handle));
		return handle;
	}

public:
	static NSubject FromFile(const NStringWrapper & fileName, NUInt flags = 0)
	{
		HNSubject hSubject;
		NCheck(NSubjectCreateFromFileN(fileName.GetHandle(), flags, &hSubject));
		return FromHandle<NSubject>(hSubject);
	}

	static NSubject FromMemory(const ::Neurotec::IO::NBuffer & buffer, NUInt flags = 0, NSizeType * pSize = NULL)
	{
		HNSubject hSubject;
		NCheck(NSubjectCreateFromMemoryN(buffer.GetHandle(), flags, pSize, &hSubject));
		return FromHandle<NSubject>(hSubject);
	}

	static NSubject FromMemory(const void * pBuffer, NSizeType bufferSize, NUInt flags = 0, NSizeType * pSize = NULL)
	{
		HNSubject hSubject;
		NCheck(NSubjectCreateFromMemory(pBuffer, bufferSize, flags, pSize, &hSubject));
		return FromHandle<NSubject>(hSubject);
	}

	static NSubject FromStream(const ::Neurotec::IO::NStream & stream, NUInt flags = 0)
	{
		HNSubject hSubject;
		NCheck(NSubjectCreateFromStream(stream.GetHandle(), flags, &hSubject));
		return FromHandle<NSubject>(hSubject);
	}

	static NSubject FromFile(const NStringWrapper & fileName, NUShort formatOwner, NUShort formatType, NUInt flags = 0)
	{
		HNSubject hSubject;
		NCheck(NSubjectCreateFromFileWithFormatN(fileName.GetHandle(), formatOwner, formatType, flags, &hSubject));
		return FromHandle<NSubject>(hSubject);
	}

	static NSubject FromMemory(const ::Neurotec::IO::NBuffer & buffer, NUShort formatOwner, NUShort formatType, NUInt flags = 0, NSizeType * pSize = NULL)
	{
		HNSubject hSubject;
		NCheck(NSubjectCreateFromMemoryWithFormatN(buffer.GetHandle(), formatOwner, formatType, flags, pSize, &hSubject));
		return FromHandle<NSubject>(hSubject);
	}

	static NSubject FromMemory(const void * pBuffer, NSizeType bufferSize, NUShort formatOwner, NUShort formatType, NUInt flags = 0, NSizeType * pSize = NULL)
	{
		HNSubject hSubject;
		NCheck(NSubjectCreateFromMemoryWithFormat(pBuffer, bufferSize, formatOwner, formatType, flags, pSize, &hSubject));
		return FromHandle<NSubject>(hSubject);
	}

	static NSubject FromStream(const ::Neurotec::IO::NStream & stream, NUShort formatOwner, NUShort formatType, NUInt flags = 0)
	{
		HNSubject hSubject;
		NCheck(NSubjectCreateFromStreamWithFormat(stream.GetHandle(), formatOwner, formatType, flags, &hSubject));
		return FromHandle<NSubject>(hSubject);
	}

	NSubject()
		: NExpandableObject(Create(), true)
	{
	}

	void Clear()
	{
		NCheck(NSubjectClear(GetHandle()));
	}

	NTemplate GetTemplate() const
	{
		HNTemplate hValue;
		NCheck(NSubjectGetTemplate(GetHandle(), &hValue));
		return FromHandle<NTemplate>(hValue);
	}

	void SetTemplate(const NTemplate & value)
	{
		NCheck(NSubjectSetTemplate(GetHandle(), value.GetHandle()));
	}

	void SetTemplate(const ::Neurotec::Biometrics::Standards::ANTemplate & value)
	{
		NCheck(NSubjectSetTemplateAN(GetHandle(), value.GetHandle()));
	}

	void SetTemplate(const ::Neurotec::Biometrics::Standards::FMRecord & value)
	{
		NCheck(NSubjectSetTemplateFM(GetHandle(), value.GetHandle()));
	}

	void SetTemplate(const ::Neurotec::Biometrics::Standards::FIRecord & value)
	{
		NCheck(NSubjectSetTemplateFI(GetHandle(), value.GetHandle()));
	}

	void SetTemplate(const ::Neurotec::Biometrics::Standards::FCRecord & value)
	{
		NCheck(NSubjectSetTemplateFC(GetHandle(), value.GetHandle()));
	}

	void SetTemplate(const ::Neurotec::Biometrics::Standards::IIRecord & value)
	{
		NCheck(NSubjectSetTemplateII(GetHandle(), value.GetHandle()));
	}

	void SetTemplate(const ::Neurotec::Biometrics::Standards::CbeffRecord & value)
	{
		NCheck(NSubjectSetTemplateCbeff(GetHandle(), value.GetHandle()));
	}

	::Neurotec::IO::NBuffer GetTemplateBuffer() const
	{
		HNBuffer hValue;
		NCheck(NSubjectGetTemplateBuffer(GetHandle(), &hValue));
		return FromHandle< ::Neurotec::IO::NBuffer>(hValue);
	}

	N_DEPRECATED("function is deprecated, use GetTemplateBuffer(NUShort, NUShort, NVersion) instead.")
	::Neurotec::IO::NBuffer GetTemplateBuffer(NUShort formatOwner, NUShort formatType) const
	{
		return GetTemplateBuffer(formatOwner, formatType, NVersion(1, 0));
	}

	::Neurotec::IO::NBuffer GetTemplateBuffer(NUShort formatOwner, NUShort formatType, NVersion version) const
	{
		HNBuffer hValue;
		NCheck(NSubjectGetTemplateBufferWithFormatEx(GetHandle(), formatOwner, formatType, version.GetValue(), &hValue));
		return FromHandle< ::Neurotec::IO::NBuffer>(hValue);
	}

	void SetTemplateBuffer(const ::Neurotec::IO::NBuffer & value)
	{
		NCheck(NSubjectSetTemplateBuffer(GetHandle(), value.GetHandle()));
	}

	void SetTemplateBuffer(const ::Neurotec::IO::NBuffer & value, NUShort formatOwner, NUShort formatType)
	{
		NCheck(NSubjectSetTemplateBufferWithFormat(GetHandle(), value.GetHandle(), formatOwner, formatType));
	}

	::Neurotec::Biometrics::Standards::ANTemplate ToANTemplate(const NVersion & version, const NStringWrapper & tot, const NStringWrapper & dai, const NStringWrapper & ori, const NStringWrapper & tcn) const
	{
		HANTemplate hValue;
		NCheck(NSubjectToANTemplateN(GetHandle(), version.GetValue(), tot.GetHandle(), dai.GetHandle(), ori.GetHandle(), tcn.GetHandle(), &hValue));
		return FromHandle< ::Neurotec::Biometrics::Standards::ANTemplate>(hValue);
	}

	::Neurotec::Biometrics::Standards::FCRecord ToFCRecord(BdifStandard standard, const NVersion & version) const
	{
		HFCRecord hValue;
		NCheck(NSubjectToFCRecord(GetHandle(), standard, version.GetValue(), &hValue));
		return FromHandle< ::Neurotec::Biometrics::Standards::FCRecord>(hValue);
	}

	::Neurotec::Biometrics::Standards::FIRecord ToFIRecord(BdifStandard standard, const NVersion & version) const
	{
		HFIRecord hValue;
		NCheck(NSubjectToFIRecord(GetHandle(), standard, version.GetValue(), &hValue));
		return FromHandle< ::Neurotec::Biometrics::Standards::FIRecord>(hValue);
	}

	::Neurotec::Biometrics::Standards::FMRecord ToFMRecord(BdifStandard standard, const NVersion & version) const
	{
		HFMRecord hValue;
		NCheck(NSubjectToFMRecord(GetHandle(), standard, version.GetValue(), &hValue));
		return FromHandle< ::Neurotec::Biometrics::Standards::FMRecord>(hValue);
	}

	::Neurotec::Biometrics::Standards::IIRecord ToIIRecord(BdifStandard standard, const NVersion & version) const
	{
		HIIRecord hValue;
		NCheck(NSubjectToIIRecord(GetHandle(), standard, version.GetValue(), &hValue));
		return FromHandle< ::Neurotec::Biometrics::Standards::IIRecord>(hValue);
	}

	NString GetId() const
	{
		return GetString(NSubjectGetId);
	}

	void SetId(const NStringWrapper & value)
	{
		SetString(NSubjectSetIdN, value);
	}

	NGender GetGender() const
	{
		NGender value;
		NCheck(NSubjectGetGender(GetHandle(), &value));
		return value;
	}

	void SetGender(NGender value)
	{
		NCheck(NSubjectSetGender(GetHandle(), value));
	}

	NBiometricStatus GetStatus() const
	{
		NBiometricStatus value;
		NCheck(NSubjectGetStatus(GetHandle(), &value));
		return value;
	}

	NString GetQueryString() const
	{
		return GetString(NSubjectGetQueryString);
	}

	void SetQueryString(const NStringWrapper & value)
	{
		SetString(NSubjectSetQueryStringN, value);
	}

	NPropertyBag GetStatistics() const
	{
		return GetObject<HandleType, NPropertyBag>(NSubjectGetStatistics, true);
	}

	bool IsMultipleSubjects() const
	{
		NBool value;
		NCheck(NSubjectIsMultipleSubjects(GetHandle(), &value));
		return value != 0;
	}

	void SetMultipleSubjects(bool value)
	{
		NCheck(NSubjectSetMultipleSubjects(GetHandle(), value ? NTrue : NFalse));
	}

	NError GetError() const
	{
		HNError hError;
		NCheck(NSubjectGetError(GetHandle(), &hError));
		return FromHandle<NError>(hError);
	}

	FingerCollection GetFingers()
	{
		return FingerCollection(*this);
	}

	const FingerCollection GetFingers() const
	{
		return FingerCollection(*this);
	}

	FaceCollection GetFaces()
	{
		return FaceCollection(*this);
	}

	const FaceCollection GetFaces() const
	{
		return FaceCollection(*this);
	}

	IrisCollection GetIrises()
	{
		return IrisCollection(*this);
	}

	const IrisCollection GetIrises() const
	{
		return IrisCollection(*this);
	}

	PalmCollection GetPalms()
	{
		return PalmCollection(*this);
	}

	const PalmCollection GetPalms() const
	{
		return PalmCollection(*this);
	}

	VoiceCollection GetVoices()
	{
		return VoiceCollection(*this);
	}

	const VoiceCollection GetVoices() const
	{
		return VoiceCollection(*this);
	}

	MissingFingerCollection GetMissingFingers()
	{
		return MissingFingerCollection(*this);
	}

	const MissingFingerCollection GetMissingFingers() const
	{
		return MissingFingerCollection(*this);
	}

	MissingEyeCollection GetMissingEyes()
	{
		return MissingEyeCollection(*this);
	}

	const MissingEyeCollection GetMissingEyes() const
	{
		return MissingEyeCollection(*this);
	}

	RelatedSubjectCollection GetRelatedSubjects();
	const RelatedSubjectCollection GetRelatedSubjects() const;

	const MatchingResultCollection GetMatchingResults() const
	{
		return MatchingResultCollection(*this);
	}
};

class NSubject::RelatedSubjectCollection : public ::Neurotec::Collections::NCollectionWithChangeNotifications<NSubject, NSubject,
	NSubjectGetRelatedSubjectCount, NSubjectGetRelatedSubject, NSubjectGetRelatedSubjects,
	NSubjectAddRelatedSubjectsCollectionChanged, NSubjectRemoveRelatedSubjectsCollectionChanged>
{
	RelatedSubjectCollection(const NSubject & owner)
	{
		SetOwner(owner);
	}

	friend class NSubject;
public:
	NInt GetCapacity() const
	{
		NInt result;
		NCheck(NSubjectGetRelatedSubjectCapacity(this->GetOwnerHandle(), &result));
		return result;
	}

	void SetCapacity(NInt value)
	{
		NCheck(NSubjectSetRelatedSubjectCapacity(this->GetOwnerHandle(), value));
	}

	void Set(NInt index, const NSubject & value)
	{
		NCheck(NSubjectSetRelatedSubject(this->GetOwnerHandle(), index, value.GetHandle()));
	}

	NInt Add(const NSubject & value)
	{
		NInt result;
		NCheck(NSubjectAddRelatedSubject(this->GetOwnerHandle(), value.GetHandle(), &result));
		return result;
	}

	void Insert(NInt index, const NSubject & value)
	{
		NCheck(NSubjectInsertRelatedSubject(this->GetOwnerHandle(), index, value.GetHandle()));
	}

	void RemoveAt(NInt index)
	{
		NCheck(NSubjectRemoveRelatedSubjectAt(this->GetOwnerHandle(), index));
	}

	void Clear()
	{
		NCheck(NSubjectClearRelatedSubjects(this->GetOwnerHandle()));
	}

};

inline NSubject::RelatedSubjectCollection NSubject::GetRelatedSubjects()
{
	return NSubject::RelatedSubjectCollection(*this);
}

inline const NSubject::RelatedSubjectCollection NSubject::GetRelatedSubjects() const
{
	return NSubject::RelatedSubjectCollection(*this);
}

}}

#endif // !N_SUBJECT_HPP_INCLUDED
