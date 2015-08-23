#ifndef N_LICENSING_SERVICE_H_INCLUDED
#define N_LICENSING_SERVICE_H_INCLUDED

#include <Core/NObject.h>

#ifdef N_CPP
extern "C"
{
#endif

typedef enum NLicensingServiceStatus_
{
	nlssNotInstalled = 0,
	nlssStopped = 0x00000001,
	nlssStartPending = 0x00000002,
	nlssStopPending = 0x00000003,
	nlssRunning = 0x00000004,
	nlssContinuePending = 0x00000005,
	nlssPausePending = 0x00000006,
	nlssPaused = 0x00000007
} NLicensingServiceStatus;

N_DECLARE_TYPE(NLicensingServiceStatus)

N_DECLARE_STATIC_OBJECT_TYPE(NLicensingService)

NResult N_API NLicensingServiceGetStatus(NLicensingServiceStatus * pValue);
NResult N_API NLicensingServiceIsTrial(NBool * pValue);
NResult N_API NLicensingServiceGetConfPath(HNString * phValue);
NResult N_API NLicensingServiceGetBinPath(HNString * phValue);
NResult N_API NLicensingServiceStart(void);
NResult N_API NLicensingServiceStop(void);

NResult N_API NLicensingServiceInstallN(HNString hBinPath, HNString hConf);
#ifndef N_NO_ANSI_FUNC
NResult N_API NLicensingServiceInstallA(const NAChar * szBinPath, const NAChar * szConf);
#endif
#ifndef N_NO_UNICODE
NResult N_API NLicensingServiceInstallW(const NWChar * szBinPath, const NWChar * szConf);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NLicensingServiceInstall(const NChar * szBinPath, const NChar * szConf);
#endif
#define NLicensingServiceInstall N_FUNC_AW(NLicensingServiceInstall)

NResult N_API NLicensingServiceUninstall(void);

#ifdef N_CPP
}
#endif

#endif // N_LICENSING_SERVICE_H_INCLUDED
