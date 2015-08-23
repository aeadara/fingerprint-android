#ifndef N_ODBC_BIOMETRIC_CONNECTION_H_INCLUDED
#define N_ODBC_BIOMETRIC_CONNECTION_H_INCLUDED

#include <Biometrics/Client/NDatabaseBiometricConnection.h>

#ifdef N_CPP
extern "C"
{
#endif

N_DECLARE_OBJECT_TYPE(NOdbcBiometricConnection, NDatabaseBiometricConnection)

NResult N_API NOdbcBiometricConnectionCreate(HNOdbcBiometricConnection * phConnection);

NResult N_API NOdbcBiometricConnectionGetConnectionString(HNOdbcBiometricConnection hConnection, HNString * phValue);
NResult N_API NOdbcBiometricConnectionSetConnectionStringN(HNOdbcBiometricConnection hConnection, HNString hValue);
#ifndef N_NO_ANSI_FUNC
NResult N_API NOdbcBiometricConnectionSetConnectionStringA(HNOdbcBiometricConnection hConnection, const NAChar * szValue);
#endif
#ifndef N_NO_UNICODE
NResult N_API NOdbcBiometricConnectionSetConnectionStringW(HNOdbcBiometricConnection hConnection, const NWChar * szValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NOdbcBiometricConnectionSetConnectionString(HNOdbcBiometricConnection hConnection, const NChar * szValue);
#endif
#define NOdbcBiometricConnectionSetConnectionString N_FUNC_AW(NOdbcBiometricConnectionSetConnectionString)

NResult N_API NOdbcBiometricConnectionGetTableName(HNOdbcBiometricConnection hConnection, HNString * phValue);
NResult N_API NOdbcBiometricConnectionSetTableNameN(HNOdbcBiometricConnection hConnection, HNString hValue);
#ifndef N_NO_ANSI_FUNC
NResult N_API NOdbcBiometricConnectionSetTableNameA(HNOdbcBiometricConnection hConnection, const NAChar * szValue);
#endif
#ifndef N_NO_UNICODE
NResult N_API NOdbcBiometricConnectionSetTableNameW(HNOdbcBiometricConnection hConnection, const NWChar * szValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NOdbcBiometricConnectionSetTableName(HNOdbcBiometricConnection hConnection, const NChar * szValue);
#endif
#define NOdbcBiometricConnectionSetTableName N_FUNC_AW(NOdbcBiometricConnectionSetTableName)

NResult N_API NOdbcBiometricConnectionGetSubjectIdColumn(HNOdbcBiometricConnection hConnection, HNString * phValue);
NResult N_API NOdbcBiometricConnectionSetSubjectIdColumnN(HNOdbcBiometricConnection hConnection, HNString hValue);
#ifndef N_NO_ANSI_FUNC
NResult N_API NOdbcBiometricConnectionSetSubjectIdColumnA(HNOdbcBiometricConnection hConnection, const NAChar * szValue);
#endif
#ifndef N_NO_UNICODE
NResult N_API NOdbcBiometricConnectionSetSubjectIdColumnW(HNOdbcBiometricConnection hConnection, const NWChar * szValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NOdbcBiometricConnectionSetSubjectIdColumn(HNOdbcBiometricConnection hConnection, const NChar * szValue);
#endif
#define NOdbcBiometricConnectionSetSubjectIdColumn N_FUNC_AW(NOdbcBiometricConnectionSetSubjectIdColumn)

NResult N_API NOdbcBiometricConnectionGetTemplateColumn(HNOdbcBiometricConnection hConnection, HNString * phValue);
NResult N_API NOdbcBiometricConnectionSetTemplateColumnN(HNOdbcBiometricConnection hConnection, HNString hValue);
#ifndef N_NO_ANSI_FUNC
NResult N_API NOdbcBiometricConnectionSetTemplateColumnA(HNOdbcBiometricConnection hConnection, const NAChar * szValue);
#endif
#ifndef N_NO_UNICODE
NResult N_API NOdbcBiometricConnectionSetTemplateColumnW(HNOdbcBiometricConnection hConnection, const NWChar * szValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NOdbcBiometricConnectionSetTemplateColumn(HNOdbcBiometricConnection hConnection, const NChar * szValue);
#endif
#define NOdbcBiometricConnectionSetTemplateColumn N_FUNC_AW(NOdbcBiometricConnectionSetTemplateColumn)

NResult N_API NOdbcBiometricConnectionGetSelectAllQuery(HNOdbcBiometricConnection hConnection, HNString * phValue);
NResult N_API NOdbcBiometricConnectionSetSelectAllQueryN(HNOdbcBiometricConnection hConnection, HNString hValue);
#ifndef N_NO_ANSI_FUNC
NResult N_API NOdbcBiometricConnectionSetSelectAllQueryA(HNOdbcBiometricConnection hConnection, const NAChar * szValue);
#endif
#ifndef N_NO_UNICODE
NResult N_API NOdbcBiometricConnectionSetSelectAllQueryW(HNOdbcBiometricConnection hConnection, const NWChar * szValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NOdbcBiometricConnectionSetSelectAllQuery(HNOdbcBiometricConnection hConnection, const NChar * szValue);
#endif
#define NOdbcBiometricConnectionSetSelectAllQuery N_FUNC_AW(NOdbcBiometricConnectionSetSelectAllQuery)

NResult N_API NOdbcBiometricConnectionGetEnrollQuery(HNOdbcBiometricConnection hConnection, HNString * phValue);
NResult N_API NOdbcBiometricConnectionSetEnrollQueryN(HNOdbcBiometricConnection hConnection, HNString hValue);
#ifndef N_NO_ANSI_FUNC
NResult N_API NOdbcBiometricConnectionSetEnrollQueryA(HNOdbcBiometricConnection hConnection, const NAChar * szValue);
#endif
#ifndef N_NO_UNICODE
NResult N_API NOdbcBiometricConnectionSetEnrollQueryW(HNOdbcBiometricConnection hConnection, const NWChar * szValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NOdbcBiometricConnectionSetEnrollQuery(HNOdbcBiometricConnection hConnection, const NChar * szValue);
#endif
#define NOdbcBiometricConnectionSetEnrollQuery N_FUNC_AW(NOdbcBiometricConnectionSetEnrollQuery)

NResult N_API NOdbcBiometricConnectionGetDeleteQuery(HNOdbcBiometricConnection hConnection, HNString * phValue);
NResult N_API NOdbcBiometricConnectionSetDeleteQueryN(HNOdbcBiometricConnection hConnection, HNString hValue);
#ifndef N_NO_ANSI_FUNC
NResult N_API NOdbcBiometricConnectionSetDeleteQueryA(HNOdbcBiometricConnection hConnection, const NAChar * szValue);
#endif
#ifndef N_NO_UNICODE
NResult N_API NOdbcBiometricConnectionSetDeleteQueryW(HNOdbcBiometricConnection hConnection, const NWChar * szValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NOdbcBiometricConnectionSetDeleteQuery(HNOdbcBiometricConnection hConnection, const NChar * szValue);
#endif
#define NOdbcBiometricConnectionSetDeleteQuery N_FUNC_AW(NOdbcBiometricConnectionSetDeleteQuery)

NResult N_API NOdbcBiometricConnectionGetClearQuery(HNOdbcBiometricConnection hConnection, HNString * phValue);
NResult N_API NOdbcBiometricConnectionSetClearQueryN(HNOdbcBiometricConnection hConnection, HNString hValue);
#ifndef N_NO_ANSI_FUNC
NResult N_API NOdbcBiometricConnectionSetClearQueryA(HNOdbcBiometricConnection hConnection, const NAChar * szValue);
#endif
#ifndef N_NO_UNICODE
NResult N_API NOdbcBiometricConnectionSetClearQueryW(HNOdbcBiometricConnection hConnection, const NWChar * szValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NOdbcBiometricConnectionSetClearQuery(HNOdbcBiometricConnection hConnection, const NChar * szValue);
#endif
#define NOdbcBiometricConnectionSetClearQuery N_FUNC_AW(NOdbcBiometricConnectionSetClearQuery)

NResult N_API NOdbcBiometricConnectionGetSelectSubjectQuery(HNOdbcBiometricConnection hConnection, HNString * phValue);
NResult N_API NOdbcBiometricConnectionSetSelectSubjectQueryN(HNOdbcBiometricConnection hConnection, HNString hValue);
#ifndef N_NO_ANSI_FUNC
NResult N_API NOdbcBiometricConnectionSetSelectSubjectQueryA(HNOdbcBiometricConnection hConnection, const NAChar * szValue);
#endif
#ifndef N_NO_UNICODE
NResult N_API NOdbcBiometricConnectionSetSelectSubjectQueryW(HNOdbcBiometricConnection hConnection, const NWChar * szValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NOdbcBiometricConnectionSetSelectSubjectQuery(HNOdbcBiometricConnection hConnection, const NChar * szValue);
#endif
#define NOdbcBiometricConnectionSetSelectSubjectQuery N_FUNC_AW(NOdbcBiometricConnectionSetSelectSubjectQuery)

#ifdef N_CPP
}
#endif

#endif // !N_ODBC_BIOMETRIC_CONNECTION_H_INCLUDED
