#include <Biometrics/NSubject.hpp>
#include <Biometrics/NBiometricConnection.hpp>

#ifndef N_BIOMETRIC_TASK_HPP_INCLUDED
#define N_BIOMETRIC_TASK_HPP_INCLUDED

#include <Core/NExpandableObject.hpp>
#include <Core/NTimeSpan.hpp>
#include <Biometrics/NBiometricTypes.hpp>
namespace Neurotec { namespace Biometrics
{
#include <Biometrics/NBiometricTask.h>
}}

N_DEFINE_ENUM_TYPE_TRAITS(Neurotec::Biometrics, NBiometricOperations)

namespace Neurotec { namespace Biometrics
{

class NBiometricTask : public NExpandableObject
{
	N_DECLARE_OBJECT_CLASS(NBiometricTask, NExpandableObject)

public:
	class SubjectCollection : public ::Neurotec::Collections::NCollectionWithAllOutBase<NSubject, NBiometricTask,
		NBiometricTaskGetSubjectCount, NBiometricTaskGetSubject, NBiometricTaskGetSubjects>
	{
		SubjectCollection(const NBiometricTask & owner)
		{
			SetOwner(owner);
		}

		friend class NBiometricTask;
	public:
		NInt GetCapacity() const
		{
			NInt result;
			NCheck(NBiometricTaskGetSubjectCapacity(this->GetOwnerHandle(), &result));
			return result;
		}

		void SetCapacity(NInt value)
		{
			NCheck(NBiometricTaskSetSubjectCapacity(this->GetOwnerHandle(), value));
		}

		void Set(NInt index, const NSubject & value)
		{
			NCheck(NBiometricTaskSetSubject(this->GetOwnerHandle(), index, value.GetHandle()));
		}

		NInt Add(const NSubject & value)
		{
			NInt result;
			NCheck(NBiometricTaskAddSubject(this->GetOwnerHandle(), value.GetHandle(), &result));
			return result;
		}

		void Insert(NInt index, const NSubject & value)
		{
			NCheck(NBiometricTaskInsertSubject(this->GetOwnerHandle(), index, value.GetHandle()));
		}

		void RemoveAt(NInt index)
		{
			NCheck(NBiometricTaskRemoveSubjectAt(this->GetOwnerHandle(), index));
		}

		void Clear()
		{
			NCheck(NBiometricTaskClearSubjects(this->GetOwnerHandle()));
		}
	};

private:
	static HNBiometricTask Create(NBiometricOperations operations)
	{
		HNBiometricTask handle;
		NCheck(NBiometricTaskCreate(operations, &handle));
		return handle;
	}

public:
	static NType NBiometricOperationsNativeTypeOf()
	{
		return NObject::GetObject<NType>(N_TYPE_OF(NBiometricOperations), true);
	}

	NBiometricTask(NBiometricOperations operations)
		: NExpandableObject(Create(operations), true)
	{
	}

	NBiometricOperations GetOperations() const
	{
		NBiometricOperations value;
		NCheck(NBiometricTaskGetOperations(GetHandle(), &value));
		return value;
	}

	void SetOperations(NBiometricOperations value)
	{
		NCheck(NBiometricTaskSetOperations(GetHandle(), value));
	}

	NBiometricStatus GetStatus() const
	{
		NBiometricStatus value;
		NCheck(NBiometricTaskGetStatus(GetHandle(), &value));
		return value;
	}

	NTimeSpan GetTimeout() const
	{
		NTimeSpan_ value;
		NCheck(NBiometricTaskGetTimeout(GetHandle(), &value));
		return NTimeSpan(value);
	}

	void SetTimeout(const NTimeSpan & value)
	{
		NCheck(NBiometricTaskSetTimeout(GetHandle(), value.GetValue()));
	}

	NBiometric GetBiometric() const
	{
		return GetObject<HandleType, NBiometric>(NBiometricTaskGetBiometric, true);
	}

	void SetBiometric(const NBiometric & value)
	{
		return SetObject(NBiometricTaskSetBiometric, value);
	}

	NBiometricConnection GetConnection() const
	{
		return GetObject<HandleType, NBiometricConnection>(NBiometricTaskGetConnection, true);
	}

	void SetConnection(const NBiometricConnection & value)
	{
		return SetObject(NBiometricTaskSetConnection, value);
	}

	NPropertyBag GetStatistics() const
	{
		return GetObject<HandleType, NPropertyBag>(NBiometricTaskGetStatistics, true);
	}

	NError GetError() const
	{
		HNError hError;
		NCheck(NBiometricTaskGetError(GetHandle(), &hError));
		return FromHandle<NError>(hError);
	}

	SubjectCollection GetSubjects()
	{
		return SubjectCollection(*this);
	}

	const SubjectCollection GetSubjects() const
	{
		return SubjectCollection(*this);
	}
};

}}

#endif // !N_BIOMETRIC_TASK_HPP_INCLUDED
