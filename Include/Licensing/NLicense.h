#ifndef N_LICENSE_H_INCLUDED
#define N_LICENSE_H_INCLUDED

#include <Core/NObject.h>
#include <Licensing/NLicenseInfo.h>

#ifdef N_CPP
extern "C"
{
#endif

N_DECLARE_STATIC_OBJECT_TYPE(NLicense)

NResult N_API NLicenseObtainN(HNString hAddress, HNString hPort, HNString hProducts, NBool * pAvailable);
#ifndef N_NO_ANSI_FUNC
NResult N_API NLicenseObtainA(const NAChar * szAddress, const NAChar * szPort, const NAChar * szProducts, NBool * pAvailable);
#endif
#ifndef N_NO_UNICODE
NResult N_API NLicenseObtainW(const NWChar * szAddress, const NWChar * szPort, const NWChar * szProducts, NBool * pAvailable);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NLicenseObtain(const NChar * szAddress, const NChar * szPort, const NChar * szProducts, NBool * pAvailable);
#endif
#define NLicenseObtain N_FUNC_AW(NLicenseObtain)

NResult N_API NLicenseReleaseN(HNString hProducts);
#ifndef N_NO_ANSI_FUNC
NResult N_API NLicenseReleaseA(const NAChar * szProducts);
#endif
#ifndef N_NO_UNICODE
NResult N_API NLicenseReleaseW(const NWChar * szProducts);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NLicenseRelease(const NChar * szProducts);
#endif
#define NLicenseRelease N_FUNC_AW(NLicenseRelease)

NResult N_API NLicenseObtainComponentsN(HNString hAddress, HNString hPort, HNString hComponents, NBool * pAvailable);
#ifndef N_NO_ANSI_FUNC
NResult N_API NLicenseObtainComponentsA(const NAChar * szAddress, const NAChar * szPort, const NAChar * szComponents, NBool * pAvailable);
#endif
#ifndef N_NO_UNICODE
NResult N_API NLicenseObtainComponentsW(const NWChar * szAddress, const NWChar * szPort, const NWChar * szComponents, NBool * pAvailable);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NLicenseObtainComponents(const NChar * szAddress, const NChar * szPort, const NChar * szComponents, NBool * pAvailable);
#endif
#define NLicenseObtainComponents N_FUNC_AW(NLicenseObtainComponents)

NResult N_API NLicenseReleaseComponentsN(HNString hComponents);
#ifndef N_NO_ANSI_FUNC
NResult N_API NLicenseReleaseComponentsA(const NAChar * szComponents);
#endif
#ifndef N_NO_UNICODE
NResult N_API NLicenseReleaseComponentsW(const NWChar * szComponents);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NLicenseReleaseComponents(const NChar * szComponents);
#endif
#define NLicenseReleaseComponents N_FUNC_AW(NLicenseReleaseComponents)

NResult N_API NLicenseGetLicenseInfoOnlineN(HNString hLicense, HNLicenseInfo * phLicenseInfo);
#ifndef N_NO_ANSI_FUNC
NResult N_API NLicenseGetLicenseInfoOnlineA(const NAChar * szLicense, HNLicenseInfo * phLicenseInfo);
#endif
#ifndef N_NO_UNICODE
NResult N_API NLicenseGetLicenseInfoOnlineW(const NWChar * szLicense, HNLicenseInfo * phLicenseInfo);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NLicenseGetLicenseInfoOnline(const NChar * szLicense, HNLicenseInfo * phLicenseInfo);
#endif
#define NLicenseGetLicenseInfoOnline N_FUNC_AW(NLicenseGetLicenseInfoOnline)

NResult N_API NLicenseGetObtainedLicenseInfoN(HNString hProduct, HNLicenseInfo * phLicenseInfo);
#ifndef N_NO_ANSI_FUNC
NResult N_API NLicenseGetObtainedLicenseInfoA(const NAChar * szProduct, HNLicenseInfo * phLicenseInfo);
#endif
#ifndef N_NO_UNICODE
NResult N_API NLicenseGetObtainedLicenseInfoW(const NWChar * szProduct, HNLicenseInfo * phLicenseInfo);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NLicenseGetObtainedLicenseInfo(const NChar * szProduct, HNLicenseInfo * phLicenseInfo);
#endif
#define NLicenseGetObtainedLicenseInfo N_FUNC_AW(NLicenseGetObtainedLicenseInfo)

NResult N_API NLicenseGetObtainedLicenseInfoForComponentN(HNString hComponent, HNLicenseInfo * phLicenseInfo);
#ifndef N_NO_ANSI_FUNC
NResult N_API NLicenseGetObtainedLicenseInfoForComponentA(const NAChar * szComponent, HNLicenseInfo * phLicenseInfo);
#endif
#ifndef N_NO_UNICODE
NResult N_API NLicenseGetObtainedLicenseInfoForComponentW(const NWChar * szComponent, HNLicenseInfo * phLicenseInfo);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NLicenseGetObtainedLicenseInfoForComponent(const NChar * szComponent, HNLicenseInfo * phLicenseInfo);
#endif
#define NLicenseGetObtainedLicenseInfoForComponent N_FUNC_AW(NLicenseGetObtainedLicenseInfoForComponent)

NResult N_API NLicenseIsComponentActivatedN(HNString hName, NBool * pValue);
#ifndef N_NO_ANSI_FUNC
NResult N_API NLicenseIsComponentActivatedA(const NAChar * szName, NBool * pValue);
#endif
#ifndef N_NO_UNICODE
NResult N_API NLicenseIsComponentActivatedW(const NWChar * szName, NBool * pValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NLicenseIsComponentActivated(const NChar * szName, NBool * pValue);
#endif
#define NLicenseIsComponentActivated N_FUNC_AW(NLicenseIsComponentActivated)

NResult N_API NLicenseGenerateIdN(HNString hIdGenPath, HNString hSerial, HNString * phId);
#ifndef N_NO_ANSI_FUNC
NResult N_API NLicenseGenerateIdA(const NAChar * szIdGenPath, const NAChar * szSerial, NAChar ** pszId);
#endif
#ifndef N_NO_UNICODE
NResult N_API NLicenseGenerateIdW(const NWChar * szIdGenPath, const NWChar * szSerial, NWChar ** pszId);
#endif
#define NLicenseGenerateId N_FUNC_AW(NLicenseGenerateId)
#ifdef N_DOCUMENTATION
NResult N_API NLicenseGenerateId(const NChar * szIdGenPath, const NChar * szSerial, NChar ** pszId);
#endif

NResult N_API NLicenseGenerateDeactivationIdN(HNString hIdGenPath, HNString hProductName, HNString * phDeactivationId);
#ifndef N_NO_ANSI_FUNC
NResult N_API NLicenseGenerateDeactivationIdA(const NAChar * szIdGenPath, const NAChar * szProductName, NAChar ** pszDeactivationId);
#endif
#ifndef N_NO_UNICODE
NResult N_API NLicenseGenerateDeactivationIdW(const NWChar * szIdGenPath, const NWChar * szProductName, NWChar ** pszDeactivationId);
#endif
#define NLicenseGenerateDeactivationId N_FUNC_AW(NLicenseGenerateDeactivationId)
#ifdef N_DOCUMENTATION
NResult N_API NLicenseGenerateDeactivationId(const NChar * szIdGenPath, const NChar * szProductName, NChar ** pszDeactivationId);
#endif

NResult N_API NLicenseGenerateDeactivationIdForLicenseN(HNString hIdGenPath, HNString hLicense, HNString * phDeactivationId);
#ifndef N_NO_ANSI_FUNC
NResult N_API NLicenseGenerateDeactivationIdForLicenseA(const NAChar * szIdGenPath, const NAChar * szLicense, NAChar ** pszDeactivationId);
#endif
#ifndef N_NO_UNICODE
NResult N_API NLicenseGenerateDeactivationIdForLicenseW(const NWChar * szIdGenPath, const NWChar * szLicense, NWChar ** pszDeactivationId);
#endif
#define NLicenseGenerateDeactivationIdForLicense N_FUNC_AW(NLicenseGenerateDeactivationIdForLicense)
#ifdef N_DOCUMENTATION
NResult N_API NLicenseGenerateDeactivationIdForLicense(const NChar * szIdGenPath, const NChar * szLicense, NChar ** pszDeactivationId);
#endif

NResult N_API NLicenseActivateOnlineN(HNString hId, HNString * phLicense);
#ifndef N_NO_ANSI_FUNC
NResult N_API NLicenseActivateOnlineA(const NAChar * szId, NAChar ** pszLicense);
#endif
#ifndef N_NO_UNICODE
NResult N_API NLicenseActivateOnlineW(const NWChar * szId, NWChar ** pszLicense);
#endif
#define NLicenseActivateOnline N_FUNC_AW(NLicenseActivateOnline)
#ifdef N_DOCUMENTATION
NResult N_API NLicenseActivateOnline(const NChar * szId, NChar ** pszLicense);
#endif

NResult N_API NLicenseDeactivateOnlineN(HNString hIdGenPath, HNString hLicense);
#ifndef N_NO_ANSI_FUNC
NResult N_API NLicenseDeactivateOnlineA(const NAChar * szIdGenPath, const NAChar * szLicense);
#endif
#ifndef N_NO_UNICODE
NResult N_API NLicenseDeactivateOnlineW(const NWChar * szIdGenPath, const NWChar * szLicense);
#endif
#define NLicenseDeactivateOnline N_FUNC_AW(NLicenseDeactivateOnline)
#ifdef N_DOCUMENTATION
NResult N_API NLicenseDeactivateOnline(const NChar * szIdGenPath, const NChar * szLicense);
#endif

NResult N_API NLicenseDeactivateOnlineWithIdN(HNString hLicense, HNString hDeactivationId);
#ifndef N_NO_ANSI_FUNC
NResult N_API NLicenseDeactivateOnlineWithIdA(const NAChar * szLicense, const NAChar * szDeactivationId);
#endif
#ifndef N_NO_UNICODE
NResult N_API NLicenseDeactivateOnlineWithIdW(const NWChar * szLicense, const NWChar * szDeactivationId);
#endif
#define NLicenseDeactivateOnlineWithId N_FUNC_AW(NLicenseDeactivateOnlineWithId)
#ifdef N_DOCUMENTATION
NResult N_API NLicenseDeactivateOnlineWithId(const NChar * szLicense, const NChar * szDeactivationId);
#endif

#ifdef N_CPP
}
#endif

#endif /* N_LICENSE_H_INCLUDED */
