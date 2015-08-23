#ifndef N_BIOMETRIC_TASK_H_INCLUDED
#define N_BIOMETRIC_TASK_H_INCLUDED

#include <Core/NExpandableObject.h>
#include <Core/NTimeSpan.h>
#include <Biometrics/NSubject.h>
#include <Biometrics/NBiometricTypes.h>
#include <Biometrics/NBiometricConnection.h>

#ifdef N_CPP
extern "C"
{
#endif

typedef enum NBiometricOperations_
{
	nboNone = 0,
	nboCapture = 1,
	nboDetect = 2,
	nboDetectSegments = 4,
	nboSegment = 8,
	nboAssessQuality = 16,
	nboCreateTemplate = 32,
	nboEnroll = 64,
	nboEnrollWithDuplicateCheck = 128,
	nboUpdate = 256,
	nboVerifyOffline = 512,
	nboVerify = 1024,
	nboIdentify = 2048,
	nboGet = 4096,
	nboDelete = 8192,
	nboList = 16384,
	nboClear = 32768,
	nboAll = -1
} NBiometricOperations;

N_DECLARE_TYPE(NBiometricOperations)

N_DECLARE_OBJECT_TYPE(NBiometricTask, NExpandableObject)

NResult N_API NBiometricTaskCreate(NBiometricOperations operations, HNBiometricTask * phBiometricTask);

NResult N_API NBiometricTaskGetOperations(HNBiometricTask hBiometricTask, NBiometricOperations * pValue);
NResult N_API NBiometricTaskSetOperations(HNBiometricTask hBiometricTask, NBiometricOperations value);
NResult N_API NBiometricTaskGetStatus(HNBiometricTask hBiometricTask, NBiometricStatus * pValue);
NResult N_API NBiometricTaskGetTimeout(HNBiometricTask hBiometricTask, NTimeSpan_ * pValue);
NResult N_API NBiometricTaskSetTimeout(HNBiometricTask hBiometricTask, NTimeSpan_ value);
NResult N_API NBiometricTaskGetBiometric(HNBiometricTask hBiometricTask, HNBiometric * phValue);
NResult N_API NBiometricTaskSetBiometric(HNBiometricTask hBiometricTask, HNBiometric hValue);
NResult N_API NBiometricTaskGetConnection(HNBiometricTask hBiometricTask, HNBiometricConnection * phValue);
NResult N_API NBiometricTaskSetConnection(HNBiometricTask hBiometricTask, HNBiometricConnection hValue);
NResult N_API NBiometricTaskGetStatistics(HNBiometricTask hBiometricTask, HNPropertyBag * phValue);
NResult N_API NBiometricTaskGetError(HNBiometricTask hBiometricTask, HNError * phValue);

NResult N_API NBiometricTaskGetSubjectCount(HNBiometricTask hBiometricTask, NInt * pValue);
NResult N_API NBiometricTaskGetSubject(HNBiometricTask hBiometricTask, NInt index, HNSubject * phValue);
NResult N_API NBiometricTaskGetSubjects(HNBiometricTask hBiometricTask, HNSubject * * parhValues, NInt * pValueCount);
NResult N_API NBiometricTaskGetSubjectCapacity(HNBiometricTask hBiometricTask, NInt * pValue);
NResult N_API NBiometricTaskSetSubjectCapacity(HNBiometricTask hBiometricTask, NInt value);
NResult N_API NBiometricTaskSetSubject(HNBiometricTask hBiometricTask, NInt index, HNSubject hValue);
NResult N_API NBiometricTaskAddSubject(HNBiometricTask hBiometricTask, HNSubject hValue, NInt * pIndex);
NResult N_API NBiometricTaskInsertSubject(HNBiometricTask hBiometricTask, NInt index, HNSubject hValue);
NResult N_API NBiometricTaskRemoveSubjectAt(HNBiometricTask hBiometricTask, NInt index);
NResult N_API NBiometricTaskClearSubjects(HNBiometricTask hBiometricTask);

#ifdef N_CPP
}
#endif

#endif // !N_BIOMETRIC_TASK_H_INCLUDED
