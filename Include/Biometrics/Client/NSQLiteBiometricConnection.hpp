#include <Biometrics/Client/NDatabaseBiometricConnection.hpp>

#ifndef N_SQLITE_BIOMETRIC_CONNECTION_HPP_INCLUDED
#define N_SQLITE_BIOMETRIC_CONNECTION_HPP_INCLUDED

namespace Neurotec { namespace Biometrics { namespace Client
{
#include <Biometrics/Client/NSQLiteBiometricConnection.h>
}}}

namespace Neurotec { namespace Biometrics { namespace Client
{

class NSQLiteBiometricConnection : public NDatabaseBiometricConnection
{
	N_DECLARE_OBJECT_CLASS(NSQLiteBiometricConnection, NDatabaseBiometricConnection)

private:
	static HNSQLiteBiometricConnection Create()
	{
		HNSQLiteBiometricConnection handle;
		NCheck(NSQLiteBiometricConnectionCreate(&handle));
		return handle;
	}

	static HNSQLiteBiometricConnection Create(const NStringWrapper & fileName)
	{
		HNSQLiteBiometricConnection handle;
		NCheck(NSQLiteBiometricConnectionCreateWithFileNameN(fileName.GetHandle(), &handle));
		return handle;
	}

public:
	NSQLiteBiometricConnection()
		: NDatabaseBiometricConnection(Create(), true)
	{
	}

	NSQLiteBiometricConnection(const NStringWrapper & fileName)
		: NDatabaseBiometricConnection(Create(fileName), true)
	{
	}

	NString GetFileName() const
	{
		return GetString(NSQLiteBiometricConnectionGetFileName);
	}

	void SetFileName(const NStringWrapper & value)
	{
		SetString(NSQLiteBiometricConnectionSetFileNameN, value);
	}
};

}}}

#endif // !N_SQLITE_BIOMETRIC_CONNECTION_HPP_INCLUDED
