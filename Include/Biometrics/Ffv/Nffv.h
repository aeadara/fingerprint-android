#ifndef NFFV_H_INCLUDED
#define NFFV_H_INCLUDED

#include <Core/NTypes.h>
#include <Core/NModule.h>
#include <Core/NObject.h>
#include <Biometrics/NFRecord.h>
#include <Images/NImage.h>

#ifdef N_CPP
extern "C"
{
#endif

#define NFFV_MAX_USER_COUNT N_INT_MAX

typedef enum NffvStatus_
{
	nfesNone = 0,
	nfesTemplateCreated = 1,
	nfesNoScanner = 2,
	nfesScannerTimeout = 3,
	nfesUserCanceled = 4,
	nfesQualityCheckFailed = 100
} NffvStatus;

N_DECLARE_TYPE(NffvStatus)

N_DECLARE_OBJECT_TYPE(Nffv, NObject)
N_DECLARE_OBJECT_TYPE(NffvUser, NObject)

NResult N_API NffvInitializeExN(HNString hDbName);
#ifndef N_NO_ANSI_FUNC
NResult N_API NffvInitializeExA(const NAChar * szDbName);
#endif
#ifndef N_NO_UNICODE
NResult N_API NffvInitializeExW(const NWChar * szDbName);
#endif
#define NffvInitializeEx N_FUNC_AW(NffvInitializeEx)

NResult N_API NffvUninitialize(void);

NResult N_API NffvGetUserCount(NInt * pValue);
NResult N_API NffvGetUserEx(NInt index, HNffvUser * phValue);
NResult N_API NffvRemoveUser(NInt index);
NResult N_API NffvClearUsers(void);

NResult N_API NffvEnrollEx(NInt timeout, NffvStatus * pStatus, HNffvUser * phUser);
NResult N_API NffvVerify(HNffvUser hUser, NInt timeout, NffvStatus * pStatus, NInt * pScore);
NResult N_API NffvCancel();
NResult N_API NffvGetUserByIdEx(NInt id, HNffvUser * phValue);
NResult N_API NffvGetUserIndexById(NInt id, NInt * pValue);

NResult N_API NffvGetQualityThreshold(NByte * pValue);
NResult N_API NffvSetQualityThreshold(NByte value);
NResult N_API NffvGetMatchingThreshold(NInt * pValue);
NResult N_API NffvSetMatchingThreshold(NInt value);

NResult N_API NffvUserGetId(HNffvUser hUser, NInt * pValue);
NResult N_API NffvUserGetRecord(HNffvUser hUser, HNFRecord * phValue);
NResult N_API NffvUserGetOriginalImage(HNffvUser hUser, HNImage * phValue);
NResult N_API NffvUserGetImageEx(HNffvUser hUser, HNImage * phValue);

#ifdef N_CPP
}
#endif

#endif //NFFV_H_INCLUDED
