#include <Biometrics/Client/NSQLiteBiometricConnection.hpp>
#include <Biometrics/Client/NOdbcBiometricConnection.hpp>
#include <Biometrics/Client/NClusterBiometricConnection.hpp>

#ifndef N_BIOMETRIC_CLIENT_HPP_INCLUDED
#define N_BIOMETRIC_CLIENT_HPP_INCLUDED

#include <Biometrics/NBiometrics.hpp>
#include <Devices/NDevices.hpp>
#include <Licensing/NLicensing.hpp>
#include <Devices/NDeviceManager.hpp>
#include <Devices/NCamera.hpp>
#include <Devices/NFScanner.hpp>
#include <Devices/NIrisScanner.hpp>
#include <Devices/NMicrophone.hpp>
#include <Biometrics/NBiometricEngine.hpp>
#include <Biometrics/NSubject.hpp>
namespace Neurotec { namespace Biometrics { namespace Client
{
using ::Neurotec::Devices::HNDeviceManager;
using ::Neurotec::Devices::HNCamera;
using ::Neurotec::Devices::HNMicrophone;
using ::Neurotec::Devices::HNFScanner;
using ::Neurotec::Devices::HNIrisScanner;
#include <Biometrics/Client/NBiometricClient.h>
}}}

namespace Neurotec { namespace Biometrics { namespace Client
{

class NBiometricClient : public NBiometricEngine
{
	N_DECLARE_OBJECT_CLASS(NBiometricClient, NBiometricEngine)

public:
	class RemoteConnectionCollection : public ::Neurotec::Collections::NCollectionWithAllOutBase<NRemoteBiometricConnection, NBiometricClient,
		NBiometricClientGetRemoteConnectionCount, NBiometricClientGetRemoteConnection, NBiometricClientGetRemoteConnections>
	{
		RemoteConnectionCollection(const NBiometricClient & owner)
		{
			SetOwner(owner);
		}

		friend class NBiometricClient;
	public:
		NInt GetCapacity() const
		{
			NInt result;
			NCheck(NBiometricClientGetRemoteConnectionCapacity(this->GetOwnerHandle(), &result));
			return result;
		}

		void SetCapacity(NInt value)
		{
			NCheck(NBiometricClientSetRemoteConnectionCapacity(this->GetOwnerHandle(), value));
		}

		void Set(NInt index, const NRemoteBiometricConnection & value)
		{
			NCheck(NBiometricClientSetRemoteConnection(this->GetOwnerHandle(), index, value.GetHandle()));
		}

		NInt Add(const NRemoteBiometricConnection & value)
		{
			NInt result;
			NCheck(NBiometricClientAddRemoteConnection(this->GetOwnerHandle(), value.GetHandle(), &result));
			return result;
		}

		NClusterBiometricConnection AddToCluster(const NStringWrapper & host, NInt port, NInt adminPort)
		{
			HNClusterBiometricConnection handle;
			NCheck(NBiometricClientAddRemoteConnectionToClusterN(this->GetOwnerHandle(), host.GetHandle(), port, adminPort, &handle));
			return FromHandle<NClusterBiometricConnection>(handle, true);
		}

		void Insert(NInt index, const NRemoteBiometricConnection & value)
		{
			NCheck(NBiometricClientInsertRemoteConnection(this->GetOwnerHandle(), index, value.GetHandle()));
		}

		void RemoveAt(NInt index)
		{
			NCheck(NBiometricClientRemoveRemoteConnectionAt(this->GetOwnerHandle(), index));
		}

		void Clear()
		{
			NCheck(NBiometricClientClearRemoteConnections(this->GetOwnerHandle()));
		}

	};

private:
	static HNBiometricClient Create()
	{
		HNBiometricClient handle;
		NCheck(NBiometricClientCreate(&handle));
		return handle;
	}

public:
	NBiometricClient()
		: NBiometricEngine(Create(), true)
	{
	}

	NSQLiteBiometricConnection SetDatabaseConnectionToSQLite(const NStringWrapper & fileName)
	{
		HNSQLiteBiometricConnection handle;
		NCheck(NBiometricClientSetDatabaseConnectionToSQLiteN(GetHandle(), fileName.GetHandle(), &handle));
		return FromHandle<NSQLiteBiometricConnection>(handle, true);
	}

	NOdbcBiometricConnection SetDatabaseConnectionToOdbc(const NStringWrapper & connectionString, const NStringWrapper & tableName)
	{
		HNOdbcBiometricConnection handle;
		NCheck(NBiometricClientSetDatabaseConnectionToOdbcN(GetHandle(), connectionString.GetHandle(), tableName.GetHandle(), &handle));
		return FromHandle<NOdbcBiometricConnection>(handle, true);
	}

	NBiometricStatus Capture(const NBiometric & biometric)
	{
		NBiometricStatus result;
		NCheck(NBiometricClientCaptureBiometric(GetHandle(), biometric.GetHandle(), &result));
		return result;
	}

	NAsyncOperation CaptureAsync(const NBiometric & biometric)
	{
		HNAsyncOperation hAsyncOperation;
		NCheck(NBiometricClientCaptureBiometricAsync(GetHandle(), biometric.GetHandle(), &hAsyncOperation));
		return FromHandle<NAsyncOperation>(hAsyncOperation);
	}

	NBiometricStatus Capture(const NSubject & subject)
	{
		NBiometricStatus result;
		NCheck(NBiometricClientCapture(GetHandle(), subject.GetHandle(), &result));
		return result;
	}

	NAsyncOperation CaptureAsync(const NSubject & subject)
	{
		HNAsyncOperation hAsyncOperation;
		NCheck(NBiometricClientCaptureAsync(GetHandle(), subject.GetHandle(), &hAsyncOperation));
		return FromHandle<NAsyncOperation>(hAsyncOperation);
	}

	void Cancel()
	{
		NCheck(NBiometricClientCancel(GetHandle()));
	}

	void ForceStart()
	{
		NCheck(NBiometricClientForceStart(GetHandle()));
	}

	void Force()
	{
		NCheck(NBiometricClientForce(GetHandle()));
	}

	void Repeat()
	{
		NCheck(NBiometricClientRepeat(GetHandle()));
	}

	void Skip()
	{
		NCheck(NBiometricClientSkip(GetHandle()));
	}

	NInt GetCurrentBiometricCompletedTimeout() const
	{
		return GetProperty<NInt>(N_T("CurrentBiometricCompletedTimeout"));
	}

	void SetCurrentBiometricCompletedTimeout(NInt value)
	{
		SetProperty(N_T("CurrentBiometricCompletedTimeout"), value);
	}

	NBiographicDataSchema GetCustomDataSchema() const
	{
		return GetProperty<NBiographicDataSchema>(N_T("CustomDataSchema"));
	}

	void SetCustomDataSchema(const NBiographicDataSchema & value)
	{
		SetProperty(N_T("CustomDataSchema"), value);
	}

	NBiometricType GetBiometricTypes() const
	{
		NBiometricType value;
		NCheck(NBiometricClientGetBiometricTypes(GetHandle(), &value));
		return value;
	}

	void SetBiometricTypes(NBiometricType value)
	{
		NCheck(NBiometricClientSetBiometricTypes(GetHandle(), value));
	}

	bool GetUseDeviceManager() const
	{
		NBool value;
		NCheck(NBiometricClientGetUseDeviceManager(GetHandle(), &value));
		return value != 0;
	}

	void SetUseDeviceManager(bool value)
	{
		NCheck(NBiometricClientSetUseDeviceManager(GetHandle(), value ? NTrue : NFalse));
	}

	NBiometricOperations GetLocalOperations() const
	{
		NBiometricOperations value;
		NCheck(NBiometricClientGetLocalOperations(GetHandle(), &value));
		return value;
	}

	void SetLocalOperations(NBiometricOperations value)
	{
		NCheck(NBiometricClientSetLocalOperations(GetHandle(), value));
	}

	NDatabaseBiometricConnection GetDatabaseConnection() const
	{
		return GetObject<HandleType, NDatabaseBiometricConnection>(NBiometricClientGetDatabaseConnection, true);
	}

	void SetDatabaseConnection(const NDatabaseBiometricConnection & value)
	{
		return SetObject(NBiometricClientSetDatabaseConnection, value);
	}

	::Neurotec::Devices::NDeviceManager GetDeviceManager() const
	{
		return GetObject<HandleType, ::Neurotec::Devices::NDeviceManager>(NBiometricClientGetDeviceManager, true);
	}

	::Neurotec::Devices::NCamera GetFaceCaptureDevice() const
	{
		return GetObject<HandleType, ::Neurotec::Devices::NCamera>(NBiometricClientGetFaceCaptureDevice, true);
	}

	void SetFaceCaptureDevice(const ::Neurotec::Devices::NCamera & value)
	{
		return SetObject(NBiometricClientSetFaceCaptureDevice, value);
	}

	::Neurotec::Devices::NFScanner GetFingerScanner() const
	{
		return GetObject<HandleType,  ::Neurotec::Devices::NFScanner>(NBiometricClientGetFingerScanner, true);
	}

	void SetFingerScanner(const ::Neurotec::Devices::NFScanner & value)
	{
		return SetObject(NBiometricClientSetFingerScanner, value);
	}

	::Neurotec::Devices::NIrisScanner GetIrisScanner() const
	{
		return GetObject<HandleType,  ::Neurotec::Devices::NIrisScanner>(NBiometricClientGetIrisScanner, true);
	}

	void SetIrisScanner(const ::Neurotec::Devices::NIrisScanner & value)
	{
		return SetObject(NBiometricClientSetIrisScanner, value);
	}

	::Neurotec::Devices::NFScanner GetPalmScanner() const
	{
		return GetObject<HandleType,  ::Neurotec::Devices::NFScanner>(NBiometricClientGetPalmScanner, true);
	}

	void SetPalmScanner(const ::Neurotec::Devices::NFScanner & value)
	{
		return SetObject(NBiometricClientSetPalmScanner, value);
	}

	::Neurotec::Devices::NMicrophone GetVoiceCaptureDevice() const
	{
		return GetObject<HandleType,  ::Neurotec::Devices::NMicrophone>(NBiometricClientGetVoiceCaptureDevice, true);
	}

	void SetVoiceCaptureDevice(const ::Neurotec::Devices::NMicrophone & value)
	{
		return SetObject(NBiometricClientSetVoiceCaptureDevice, value);
	}

	NBiometric GetCurrentBiometric() const
	{
		return GetObject<HandleType, NBiometric>(NBiometricClientGetCurrentBiometric, true);
	}

	NSubject GetCurrentSubject() const
	{
		return GetObject<HandleType, NSubject>(NBiometricClientGetCurrentSubject, true);
	}

	void AddCurrentBiometricCompletedCallback(const NCallback & callback)
	{
		NCheck(NBiometricClientAddCurrentBiometricCompleted(GetHandle(), callback.GetHandle()));
	}

	template<typename F>
	NCallback AddCurrentBiometricCompletedCallback(const F & callback, void * pParam = NULL)
	{
		NCallback cb = NTypes::CreateCallback<NObject::EventHandler<F> >(callback, pParam);
		AddCurrentBiometricCompletedCallback(cb);
		return cb;
	}

	void RemoveCurrentBiometricCompletedCallback(const NCallback & callback)
	{
		NCheck(NBiometricClientRemoveCurrentBiometricCompleted(GetHandle(), callback.GetHandle()));
	}

	template<typename F>
	NCallback RemoveCurrentBiometricCompletedCallback(const F & callback, void * pParam = NULL)
	{
		NCallback cb = NTypes::CreateCallback<NObject::EventHandler<F> >(callback, pParam);
		RemoveCurrentBiometricCompletedCallback(cb);
		return cb;
	}

	void AddCurrentSubjectCompletedCallback(const NCallback & callback)
	{
		NCheck(NBiometricClientAddCurrentSubjectCompleted(GetHandle(), callback.GetHandle()));
	}

	template<typename F>
	NCallback AddCurrentSubjectCompletedCallback(const F & callback, void * pParam = NULL)
	{
		NCallback cb = NTypes::CreateCallback<NObject::EventHandler<F> >(callback, pParam);
		AddCurrentSubjectCompletedCallback(cb);
		return cb;
	}

	void RemoveCurrentSubjectCompletedCallback(const NCallback & callback)
	{
		NCheck(NBiometricClientRemoveCurrentSubjectCompleted(GetHandle(), callback.GetHandle()));
	}

	template<typename F>
	NCallback RemoveCurrentSubjectCompletedCallback(const F & callback, void * pParam = NULL)
	{
		NCallback cb = NTypes::CreateCallback<NObject::EventHandler<F> >(callback, pParam);
		RemoveCurrentSubjectCompletedCallback(cb);
		return cb;
	}

	RemoteConnectionCollection GetRemoteConnections()
	{
		return RemoteConnectionCollection(*this);
	}

	const RemoteConnectionCollection GetRemoteConnections() const
	{
		return RemoteConnectionCollection(*this);
	}

	bool GetFingersCheckForDuplicatesWhenCapturing() const
	{
		return GetProperty<bool>(N_T("Fingers.CheckForDuplicatesWhenCapturing"));
	}

	void SetFingersCheckForDuplicatesWhenCapturing(bool value)
	{
		SetProperty(N_T("Fingers.CheckForDuplicatesWhenCapturing"), value);
	}
};

}}}

#endif // !N_BIOMETRIC_CLIENT_HPP_INCLUDED
