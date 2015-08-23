#ifndef NFFV_HPP_INCLUDED
#define NFFV_HPP_INCLUDED

#include <Core/NTypes.hpp>
#include <Images/NImage.hpp>
#include <Biometrics/NFRecord.hpp>
namespace Neurotec { namespace Biometrics { namespace Ffv
{
using Neurotec::Biometrics::HNFRecord;
using Neurotec::Images::HNImage;
#include <Biometrics/Ffv/Nffv.h>
}}}

N_DEFINE_ENUM_TYPE_TRAITS(Neurotec::Biometrics::Ffv, NffvStatus)

namespace Neurotec { namespace Biometrics { namespace Ffv
{

#undef NFFV_MAX_USER_COUNT

const NInt NFFV_MAX_USER_COUNT = N_INT_MAX;

class NffvUser : public NObject
{
	N_DECLARE_OBJECT_CLASS(NffvUser, NObject)

public:
	NInt GetId()
	{
		NInt id;
		NCheck(NffvUserGetId(GetHandle(), &id));
		return id;
	}

	::Neurotec::Biometrics::NFRecord GetRecord()
	{
		return GetObject<HandleType, ::Neurotec::Biometrics::NFRecord>(NffvUserGetRecord);
	}

	::Neurotec::Images::NImage GetOriginalImage()
	{
		return GetObject<HandleType, ::Neurotec::Images::NImage>(NffvUserGetOriginalImage, true);
	}

	::Neurotec::Images::NImage GetImage()
	{
		return GetObject<HandleType, ::Neurotec::Images::NImage>(NffvUserGetImageEx, true);
	}
};

class Nffv
{
	N_DECLARE_STATIC_OBJECT_CLASS(Nffv)

public:
	class UserCollection : public ::Neurotec::Collections::NStaticCollectionBase<NffvUser,
		NffvGetUserCount, NffvGetUserEx>
	{
		UserCollection()
		{
		}

		friend class Nffv;
	public:

		void RemoveAt(NInt index)
		{
			NCheck(NffvRemoveUser(index));
		}

		void Clear()
		{
			NCheck(NffvClearUsers());
		}


		NInt IndexOf(NInt id) const
		{
			NInt index;
			NCheck(NffvGetUserIndexById(id, &index));
			return index;
		}

		bool Contains(NInt id) const
		{
			return IndexOf(id) != -1;
		}

		NffvUser GetById(NInt id) const
		{
			HNffvUser hValue;
			NCheck(NffvGetUserByIdEx(id, &hValue));
			return NObject::FromHandle<NffvUser>(hValue, true);
		}
	};

public:
	static NType NffvStatusNativeTypeOf()
	{
		return NObject::GetObject<NType>(N_TYPE_OF(NffvStatus), true);
	}

	static void Initialize(const NStringWrapper & dbName)
	{
		NCheck(NffvInitializeExN(dbName.GetHandle()));
	}

	static void Uninitialize()
	{
		NCheck(NffvUninitialize());
	}

	static NffvUser Enroll(NInt timeout, NffvStatus * pStatus)
	{
		HNffvUser hUser;
		NCheck(NffvEnrollEx(timeout, pStatus, &hUser));
		return NObject::FromHandle<NffvUser>(hUser, true);
	}

	static NInt Verify(const NffvUser & user, NInt timeout, NffvStatus * pStatus)
	{
		NInt value;
		NCheck(NffvVerify(user.GetHandle(), timeout, pStatus, &value));
		return value;
	}

	static void Cancel()
	{
		NCheck(NffvCancel());
	}

	static NByte GetQualityThreshold()
	{
		NByte value;
		NCheck(NffvGetQualityThreshold(&value));
		return value;
	}

	static void SetQualityThreshold(NByte value)
	{
		NCheck(NffvSetQualityThreshold(value));
	}

	static NInt GetMatchingThreshold()
	{
		NInt value;
		NCheck(NffvGetMatchingThreshold(&value));
		return value;
	}

	static void SetMatchingThreshold(NInt value)
	{
		NCheck(NffvSetMatchingThreshold(value));
	}

	UserCollection GetUsers()
	{
		return UserCollection();
	}
};

}}}

#endif
