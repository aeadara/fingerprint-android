#ifndef N_BIOMETRIC_ENGINE_H_INCLUDED
#define N_BIOMETRIC_ENGINE_H_INCLUDED

#include <Core/NObject.h>
#include <Core/NAsyncOperation.h>
#include <Biometrics/NSubject.h>
#include <Biometrics/NBiometricTask.h>
#include <Biometrics/NBiometricEngineTypes.h>
#include <Biometrics/NBiographicDataSchema.h>

#ifdef N_CPP
extern "C"
{
#endif

N_DECLARE_OBJECT_TYPE(NBiometricEngine, NObject)

NResult N_API NBiometricEngineCreate(HNBiometricEngine * phBiometricEngine);

NResult N_API NBiometricEngineInitialize(HNBiometricEngine hBiometricEngine);
NResult N_API NBiometricEngineInitializeAsync(HNBiometricEngine hBiometricEngine, HNAsyncOperation * phAsyncOperation);
NResult N_API NBiometricEngineCreateTask(HNBiometricEngine hBiometricEngine, NBiometricOperations operations, HNSubject hSubject, HNSubject hOtherSubject, HNBiometricTask * phBiometricTask);
NResult N_API NBiometricEnginePerformTask(HNBiometricEngine hBiometricEngine, HNBiometricTask hBiometricTask);
NResult N_API NBiometricEnginePerformTaskAsync(HNBiometricEngine hBiometricEngine, HNBiometricTask hBiometricTask, HNAsyncOperation * phAsyncOperation);
NResult N_API NBiometricEngineEnroll(HNBiometricEngine hBiometricEngine, HNSubject hSubject, NBool checkForDuplicates, NBiometricStatus * pResult);
NResult N_API NBiometricEngineEnrollAsync(HNBiometricEngine hBiometricEngine, HNSubject hSubject, NBool checkForDuplicates, HNAsyncOperation * phAsyncOperation);
NResult N_API NBiometricEngineCreateTemplate(HNBiometricEngine hBiometricEngine, HNSubject hSubject, NBiometricStatus * pResult);
NResult N_API NBiometricEngineCreateTemplateAsync(HNBiometricEngine hBiometricEngine, HNSubject hSubject, HNAsyncOperation * phAsyncOperation);
NResult N_API NBiometricEngineIdentify(HNBiometricEngine hBiometricEngine, HNSubject hSubject, NBiometricStatus * pResult);
NResult N_API NBiometricEngineIdentifyAsync(HNBiometricEngine hBiometricEngine, HNSubject hSubject, HNAsyncOperation * phAsyncOperation);
NResult N_API NBiometricEngineVerify(HNBiometricEngine hBiometricEngine, HNSubject hSubject, NBiometricStatus * pResult);
NResult N_API NBiometricEngineVerifyAsync(HNBiometricEngine hBiometricEngine, HNSubject hSubject, HNAsyncOperation * phAsyncOperation);
NResult N_API NBiometricEngineVerifyOffline(HNBiometricEngine hBiometricEngine, HNSubject hSubject, HNSubject hOtherSubject, NBiometricStatus * pResult);
NResult N_API NBiometricEngineVerifyOfflineAsync(HNBiometricEngine hBiometricEngine, HNSubject hSubject, HNSubject hOtherSubject, HNAsyncOperation * phAsyncOperation);
NResult N_API NBiometricEngineDelete(HNBiometricEngine hBiometricEngine, HNString hId, NBiometricStatus * pResult);
NResult N_API NBiometricEngineDeleteAsync(HNBiometricEngine hBiometricEngine, HNString hId, HNAsyncOperation * phAsyncOperation);
NResult N_API NBiometricEngineClear(HNBiometricEngine hBiometricEngine, NBiometricStatus * pResult);
NResult N_API NBiometricEngineClearAsync(HNBiometricEngine hBiometricEngine, HNAsyncOperation * phAsyncOperation);
NResult N_API NBiometricEngineGet(HNBiometricEngine hBiometricEngine, HNSubject hSubject, NBiometricStatus * pResult);
NResult N_API NBiometricEngineGetAsync(HNBiometricEngine hBiometricEngine, HNSubject hSubject, HNAsyncOperation * phAsyncOperation);
NResult N_API NBiometricEngineList(HNBiometricEngine hBiometricEngine, HNSubject * * parhValues, NInt * pValueCount);
NResult N_API NBiometricEngineListAsync(HNBiometricEngine hBiometricEngine, HNAsyncOperation * phAsyncOperation);
NResult N_API NBiometricEngineDetectFaces(HNBiometricEngine hBiometricEngine, HNImage hImage, HNFace * phResult);
NResult N_API NBiometricEngineDetectFacesAsync(HNBiometricEngine hBiometricEngine, HNImage hImage, HNAsyncOperation * phAsyncOperation);

#ifdef N_CPP
}
#endif

#endif // !N_BIOMETRIC_ENGINE_H_INCLUDED
