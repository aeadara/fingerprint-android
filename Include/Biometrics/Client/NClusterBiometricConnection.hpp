#include <Biometrics/Client/NRemoteBiometricConnection.hpp>

#ifndef N_CLUSTER_BIOMETRIC_CONNECTION_HPP_INCLUDED
#define N_CLUSTER_BIOMETRIC_CONNECTION_HPP_INCLUDED

namespace Neurotec { namespace Biometrics { namespace Client
{
#include <Biometrics/Client/NClusterBiometricConnection.h>
}}}

namespace Neurotec { namespace Biometrics { namespace Client
{

class NClusterAddress : public NClusterAddress_
{
	N_DECLARE_DISPOSABLE_STRUCT_CLASS(NClusterAddress)

public:
	NClusterAddress(const NStringWrapper & host, NInt port, NInt adminPort)
	{
		NCheck(NClusterAddressCreateN(host.GetHandle(), port, adminPort, this));
	}

	NString GetHost() const
	{
		return NString(hHost, false);
	}

	void SetHost(const NStringWrapper & value)
	{
		NCheck(NStringSet(value.GetHandle(), &hHost));
	}
};

}}}

N_DEFINE_DISPOSABLE_STRUCT_TYPE_TRAITS(Neurotec::Biometrics::Client, NClusterAddress);

namespace Neurotec { namespace Biometrics { namespace Client
{

class NClusterBiometricConnection : public NRemoteBiometricConnection
{
	N_DECLARE_OBJECT_CLASS(NClusterBiometricConnection, NRemoteBiometricConnection)

public:
	class AddressCollection : public ::Neurotec::Collections::NCollectionWithAllOutBase<NClusterAddress, NClusterBiometricConnection,
		NClusterBiometricConnectionGetAddressCount, NClusterBiometricConnectionGetAddress, NClusterBiometricConnectionGetAddresses>
	{
		AddressCollection(const NClusterBiometricConnection & owner)
		{
			SetOwner(owner);
		}

		friend class NClusterBiometricConnection;
	public:
		NInt GetCapacity() const
		{
			NInt result;
			NCheck(NClusterBiometricConnectionGetAddressCapacity(this->GetOwnerHandle(), &result));
			return result;
		}

		void SetCapacity(NInt value)
		{
			NCheck(NClusterBiometricConnectionSetAddressCapacity(this->GetOwnerHandle(), value));
		}

		void RemoveAt(NInt index)
		{
			NCheck(NClusterBiometricConnectionRemoveAddressAt(this->GetOwnerHandle(), index));
		}

		void Clear()
		{
			NCheck(NClusterBiometricConnectionClearAddresses(this->GetOwnerHandle()));
		}

	};


private:
	static HNClusterBiometricConnection Create()
	{
		HNClusterBiometricConnection handle;
		NCheck(NClusterBiometricConnectionCreate(&handle));
		return handle;
	}

	static HNClusterBiometricConnection Create(const NClusterAddress & address)
	{
		HNClusterBiometricConnection handle;
		NCheck(NClusterBiometricConnectionCreateWithAddress(&address, &handle));
		return handle;
	}

	static HNClusterBiometricConnection Create(const NStringWrapper & host, NInt port, NInt adminPort)
	{
		HNClusterBiometricConnection handle;
		NCheck(NClusterBiometricConnectionCreateWithHostN(host.GetHandle(), port, adminPort, &handle));
		return handle;
	}

public:
	NClusterBiometricConnection()
		: NRemoteBiometricConnection(Create(), true)
	{
	}

	NClusterBiometricConnection(const NClusterAddress & address)
		: NRemoteBiometricConnection(Create(address), true)
	{
	}

	NClusterBiometricConnection(const NStringWrapper & host, NInt port, NInt adminPort)
		: NRemoteBiometricConnection(Create(host, port, adminPort), true)
	{
	}

	NString GetHost() const
	{
		return GetString(NClusterBiometricConnectionGetHost);
	}

	void SetHost(const NStringWrapper & value)
	{
		SetString(NClusterBiometricConnectionSetHostN, value);
	}

	NInt GetPort() const
	{
		NInt value;
		NCheck(NClusterBiometricConnectionGetPort(GetHandle(), &value));
		return value;
	}

	void SetPort(NInt value)
	{
		NCheck(NClusterBiometricConnectionSetPort(GetHandle(), value));
	}

	NInt GetAdminPort() const
	{
		NInt value;
		NCheck(NClusterBiometricConnectionGetAdminPort(GetHandle(), &value));
		return value;
	}

	void SetAdminPort(NInt value)
	{
		NCheck(NClusterBiometricConnectionSetAdminPort(GetHandle(), value));
	}

	NInt GetRetryCount() const
	{
		NInt value;
		NCheck(NClusterBiometricConnectionGetRetryCount(GetHandle(), &value));
		return value;
	}

	void SetRetryCount(NInt value)
	{
		NCheck(NClusterBiometricConnectionSetRetryCount(GetHandle(), value));
	}

	AddressCollection GetAddresses()
	{
		return AddressCollection(*this);
	}

	const AddressCollection GetAddresses() const
	{
		return AddressCollection(*this);
	}
};

}}}

#endif // !N_CLUSTER_BIOMETRIC_CONNECTION_HPP_INCLUDED
