#include <Biometrics/Client/NDatabaseBiometricConnection.hpp>

#ifndef N_ODBC_BIOMETRIC_CONNECTION_HPP_INCLUDED
#define N_ODBC_BIOMETRIC_CONNECTION_HPP_INCLUDED

namespace Neurotec { namespace Biometrics { namespace Client
{
#include <Biometrics/Client/NOdbcBiometricConnection.h>
}}}

namespace Neurotec { namespace Biometrics { namespace Client
{

class NOdbcBiometricConnection : public NDatabaseBiometricConnection
{
	N_DECLARE_OBJECT_CLASS(NOdbcBiometricConnection, NDatabaseBiometricConnection)

private:
	static HNOdbcBiometricConnection Create()
	{
		HNOdbcBiometricConnection handle;
		NCheck(NOdbcBiometricConnectionCreate(&handle));
		return handle;
	}

public:
	NOdbcBiometricConnection()
		: NDatabaseBiometricConnection(Create(), true)
	{
	}

	NString GetConnectionString() const
	{
		return GetString(NOdbcBiometricConnectionGetConnectionString);
	}

	void SetConnectionString(const NStringWrapper & value)
	{
		SetString(NOdbcBiometricConnectionSetConnectionStringN, value);
	}
	
	NString GetTableName() const
	{
		return GetString(NOdbcBiometricConnectionGetTableName);
	}

	void SetTableName(const NStringWrapper & value)
	{
		SetString(NOdbcBiometricConnectionSetTableNameN, value);
	}

	NString GetSubjectIdColumn() const
	{
		return GetString(NOdbcBiometricConnectionGetSubjectIdColumn);
	}

	void SetSubjectIdColumn(const NStringWrapper & value)
	{
		SetString(NOdbcBiometricConnectionSetSubjectIdColumnN, value);
	}

	NString GetTemplateColumn() const
	{
		return GetString(NOdbcBiometricConnectionGetTemplateColumn);
	}

	void SetTemplateColumn(const NStringWrapper & value)
	{
		SetString(NOdbcBiometricConnectionSetTemplateColumnN, value);
	}

	NString GetSelectAllQuery() const
	{
		return GetString(NOdbcBiometricConnectionGetSelectAllQuery);
	}

	void SetSelectAllQuery(const NStringWrapper & value)
	{
		SetString(NOdbcBiometricConnectionSetSelectAllQueryN, value);
	}

	NString GetEnrollQuery() const
	{
		return GetString(NOdbcBiometricConnectionGetEnrollQuery);
	}

	void SetEnrollQuery(const NStringWrapper & value)
	{
		SetString(NOdbcBiometricConnectionSetEnrollQueryN, value);
	}

	NString GetDeleteQuery() const
	{
		return GetString(NOdbcBiometricConnectionGetDeleteQuery);
	}

	void SetDeleteQuery(const NStringWrapper & value)
	{
		SetString(NOdbcBiometricConnectionSetDeleteQueryN, value);
	}

	NString GetClearQuery() const
	{
		return GetString(NOdbcBiometricConnectionGetClearQuery);
	}

	void SetClearQuery(const NStringWrapper & value)
	{
		SetString(NOdbcBiometricConnectionSetClearQueryN, value);
	}

	NString GetSelectSubjectQuery() const
	{
		return GetString(NOdbcBiometricConnectionGetSelectSubjectQuery);
	}

	void SetSelectSubjectQuery(const NStringWrapper & value)
	{
		SetString(NOdbcBiometricConnectionSetSelectSubjectQueryN, value);
	}
};

}}}

#endif // !N_ODBC_BIOMETRIC_CONNECTION_HPP_INCLUDED
