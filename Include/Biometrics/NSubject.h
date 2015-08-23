#ifndef N_SUBJECT_H_INCLUDED
#define N_SUBJECT_H_INCLUDED

#include <Core/NExpandableObject.h>
#include <Biometrics/NBiometricTypes.h>
#include <Biometrics/NTemplate.h>
#include <Biometrics/NFinger.h>
#include <Biometrics/NFace.h>
#include <Biometrics/NIris.h>
#include <Biometrics/NPalm.h>
#include <Biometrics/NVoice.h>
#include <Biometrics/NMatchingResult.h>
#include <Biometrics/Standards/ANTemplate.h>
#include <Biometrics/Standards/FCRecord.h>
#include <Biometrics/Standards/FIRecord.h>
#include <Biometrics/Standards/FMRecord.h>
#include <Biometrics/Standards/IIRecord.h>
#include <Biometrics/Standards/BdifTypes.h>
#include <Biometrics/Standards/CbeffRecord.h>

#ifdef N_CPP
extern "C"
{
#endif

NResult N_API NSubjectCreateFromFileN(HNString hFileName, NUInt flags, HNSubject * phSubject);
#ifndef N_NO_ANSI_FUNC
NResult N_API NSubjectCreateFromFileA(const NAChar * szFileName, NUInt flags, HNSubject * phSubject);
#endif
#ifndef N_NO_UNICODE
NResult N_API NSubjectCreateFromFileW(const NWChar * szFileName, NUInt flags, HNSubject * phSubject);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NSubjectCreateFromFile(const NChar * szFileName, NUInt flags, HNSubject * phSubject);
#endif
#define NSubjectCreateFromFile N_FUNC_AW(NSubjectCreateFromFile)

NResult N_API NSubjectCreateFromMemoryN(HNBuffer hBuffer, NUInt flags, NSizeType * pSize, HNSubject * phSubject);
NResult N_API NSubjectCreateFromMemory(const void * pBuffer, NSizeType bufferSize, NUInt flags, NSizeType * pSize, HNSubject * phSubject);
NResult N_API NSubjectCreateFromStream(HNStream hStream, NUInt flags, HNSubject * phSubject);

NResult N_API NSubjectCreateFromFileWithFormatN(HNString hFileName, NUShort formatOwner, NUShort formatType, NUInt flags, HNSubject * phSubject);
#ifndef N_NO_ANSI_FUNC
NResult N_API NSubjectCreateFromFileWithFormatA(const NAChar * szFileName, NUShort formatOwner, NUShort formatType, NUInt flags, HNSubject * phSubject);
#endif
#ifndef N_NO_UNICODE
NResult N_API NSubjectCreateFromFileWithFormatW(const NWChar * szFileName, NUShort formatOwner, NUShort formatType, NUInt flags, HNSubject * phSubject);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NSubjectCreateFromFileWithFormat(const NChar * szFileName, NUShort formatOwner, NUShort formatType, NUInt flags, HNSubject * phSubject);
#endif
#define NSubjectCreateFromFileWithFormat N_FUNC_AW(NSubjectCreateFromFileWithFormat)

NResult N_API NSubjectCreateFromMemoryWithFormatN(HNBuffer hBuffer, NUShort formatOwner, NUShort formatType, NUInt flags, NSizeType * pSize, HNSubject * phSubject);
NResult N_API NSubjectCreateFromMemoryWithFormat(const void * pBuffer, NSizeType bufferSize, NUShort formatOwner, NUShort formatType, NUInt flags, NSizeType * pSize, HNSubject * phSubject);
NResult N_API NSubjectCreateFromStreamWithFormat(HNStream hStream, NUShort formatOwner, NUShort formatType, NUInt flags, HNSubject * phSubject);

NResult N_API NSubjectCreate(HNSubject * phSubject);

NResult N_API NSubjectClear(HNSubject hSubject);
NResult N_API NSubjectGetTemplate(HNSubject hSubject, HNTemplate * phValue);
NResult N_API NSubjectSetTemplate(HNSubject hSubject, HNTemplate hValue);
NResult N_API NSubjectSetTemplateAN(HNSubject hSubject, HANTemplate hValue);
NResult N_API NSubjectSetTemplateFC(HNSubject hSubject, HFCRecord hValue);
NResult N_API NSubjectSetTemplateFI(HNSubject hSubject, HFIRecord hValue);
NResult N_API NSubjectSetTemplateFM(HNSubject hSubject, HFMRecord hValue);
NResult N_API NSubjectSetTemplateII(HNSubject hSubject, HIIRecord hValue);
NResult N_API NSubjectSetTemplateCbeff(HNSubject hSubject, HCbeffRecord hValue);
NResult N_API NSubjectGetTemplateBuffer(HNSubject hSubject, HNBuffer * phValue);
N_DEPRECATED("function is deprecated, use NSubjectGetTemplateBufferWithFormatEx instead")
NResult N_API NSubjectGetTemplateBufferWithFormat(HNSubject hSubject, NUShort formatOwner, NUShort formatType, HNBuffer * phValue);
NResult N_API NSubjectGetTemplateBufferWithFormatEx(HNSubject hSubject, NUShort formatOwner, NUShort formatType, NVersion_ version, HNBuffer * phValue);
NResult N_API NSubjectSetTemplateBuffer(HNSubject hSubject, HNBuffer hValue);
NResult N_API NSubjectSetTemplateBufferWithFormat(HNSubject hSubject, HNBuffer hValue, NUShort formatOwner, NUShort formatType);
NResult N_API NSubjectToANTemplateN(HNSubject hSubject, NVersion_ version, HNString hTot, HNString hDai, HNString hOri, HNString hTcn, HANTemplate * phValue);
#ifndef N_NO_ANSI_FUNC
NResult N_API NSubjectToANTemplateA(HNSubject hSubject, NVersion_ version, const NAChar * szTot, const NAChar * szDai, const NAChar * szOri, const NAChar * szTcn, HANTemplate * phValue);
#endif
#ifndef N_NO_UNICODE
NResult N_API NSubjectToANTemplateW(HNSubject hSubject, NVersion_ version, const NWChar * szTot, const NWChar * szDai, const NWChar * szOri, const NWChar * szTcn, HANTemplate * phValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NSubjectToANTemplate(HNSubject hSubject, NVersion_ version, const NChar * szTot, const NChar * szDai, const NChar * szOri, const NChar * szTcn, HANTemplate * phValue);
#endif
#define NSubjectCreateFromFile N_FUNC_AW(NSubjectCreateFromFile)
NResult N_API NSubjectToFCRecord(HNSubject hSubject, BdifStandard standard, NVersion_ version, HFCRecord * phValue);
NResult N_API NSubjectToFIRecord(HNSubject hSubject, BdifStandard standard, NVersion_ version, HFIRecord * phValue);
NResult N_API NSubjectToFMRecord(HNSubject hSubject, BdifStandard standard, NVersion_ version, HFMRecord * phValue);
NResult N_API NSubjectToIIRecord(HNSubject hSubject, BdifStandard standard, NVersion_ version, HIIRecord * phValue);

NResult N_API NSubjectGetId(HNSubject hSubject, HNString * phValue);
NResult N_API NSubjectSetIdN(HNSubject hSubject, HNString hValue);
#ifndef N_NO_ANSI_FUNC
NResult N_API NSubjectSetIdA(HNSubject hSubject, const NAChar * szValue);
#endif
#ifndef N_NO_UNICODE
NResult N_API NSubjectSetIdW(HNSubject hSubject, const NWChar * szValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NSubjectSetId(HNSubject hSubject, const NChar * szValue);
#endif
#define NSubjectSetId N_FUNC_AW(NSubjectSetId)
NResult N_API NSubjectGetGender(HNSubject hSubject, NGender * pValue);
NResult N_API NSubjectSetGender(HNSubject hSubject, NGender value);
NResult N_API NSubjectGetStatus(HNSubject hSubject, NBiometricStatus * pValue);
NResult N_API NSubjectGetQueryString(HNSubject hSubject, HNString * phValue);
NResult N_API NSubjectSetQueryStringN(HNSubject hSubject, HNString hValue);
#ifndef N_NO_ANSI_FUNC
NResult N_API NSubjectSetQueryStringA(HNSubject hSubject, const NAChar * szValue);
#endif
#ifndef N_NO_UNICODE
NResult N_API NSubjectSetQueryStringW(HNSubject hSubject, const NWChar * szValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NSubjectSetQueryString(HNSubject hSubject, const NChar * szValue);
#endif
#define NSubjectSetQueryString N_FUNC_AW(NSubjectSetQueryString)
NResult N_API NSubjectGetStatistics(HNSubject hSubject, HNPropertyBag * phValue);
NResult N_API NSubjectIsMultipleSubjects(HNSubject hSubject, NBool * pValue);
NResult N_API NSubjectSetMultipleSubjects(HNSubject hSubject, NBool value);
NResult N_API NSubjectGetError(HNSubject hSubject, HNError * phValue);

NResult N_API NSubjectGetFingerCount(HNSubject hSubject, NInt * pValue);
NResult N_API NSubjectGetFinger(HNSubject hSubject, NInt index, HNFinger * phValue);
NResult N_API NSubjectGetFingers(HNSubject hSubject, HNFinger * * parhValues, NInt * pValueCount);
NResult N_API NSubjectGetFingerCapacity(HNSubject hSubject, NInt * pValue);
NResult N_API NSubjectSetFingerCapacity(HNSubject hSubject, NInt value);
NResult N_API NSubjectSetFinger(HNSubject hSubject, NInt index, HNFinger hValue);
NResult N_API NSubjectAddFinger(HNSubject hSubject, HNFinger hValue, NInt * pIndex);
NResult N_API NSubjectInsertFinger(HNSubject hSubject, NInt index, HNFinger hValue);
NResult N_API NSubjectRemoveFingerAt(HNSubject hSubject, NInt index);
NResult N_API NSubjectClearFingers(HNSubject hSubject);

NResult N_API NSubjectAddFingersCollectionChanged(HNSubject hSubject, HNCallback hCallback);
NResult N_API NSubjectAddFingersCollectionChangedCallback(HNSubject hSubject, N_COLLECTION_CHANGED_CALLBACK_ARG(HNFinger, pCallback), void * pParam);
NResult N_API NSubjectRemoveFingersCollectionChanged(HNSubject hSubject, HNCallback hCallback);
NResult N_API NSubjectRemoveFingersCollectionChangedCallback(HNSubject hSubject, N_COLLECTION_CHANGED_CALLBACK_ARG(HNFinger, pCallback), void * pParam);

NResult N_API NSubjectGetFaceCount(HNSubject hSubject, NInt * pValue);
NResult N_API NSubjectGetFace(HNSubject hSubject, NInt index, HNFace * phValue);
NResult N_API NSubjectGetFaces(HNSubject hSubject, HNFace * * parhValues, NInt * pValueCount);
NResult N_API NSubjectGetFaceCapacity(HNSubject hSubject, NInt * pValue);
NResult N_API NSubjectSetFaceCapacity(HNSubject hSubject, NInt value);
NResult N_API NSubjectSetFace(HNSubject hSubject, NInt index, HNFace hValue);
NResult N_API NSubjectAddFace(HNSubject hSubject, HNFace hValue, NInt * pIndex);
NResult N_API NSubjectInsertFace(HNSubject hSubject, NInt index, HNFace hValue);
NResult N_API NSubjectRemoveFaceAt(HNSubject hSubject, NInt index);
NResult N_API NSubjectClearFaces(HNSubject hSubject);

NResult N_API NSubjectAddFacesCollectionChanged(HNSubject hSubject, HNCallback hCallback);
NResult N_API NSubjectAddFacesCollectionChangedCallback(HNSubject hSubject, N_COLLECTION_CHANGED_CALLBACK_ARG(HNFace, pCallback), void * pParam);
NResult N_API NSubjectRemoveFacesCollectionChanged(HNSubject hSubject, HNCallback hCallback);
NResult N_API NSubjectRemoveFacesCollectionChangedCallback(HNSubject hSubject, N_COLLECTION_CHANGED_CALLBACK_ARG(HNFace, pCallback), void * pParam);

NResult N_API NSubjectGetIrisCount(HNSubject hSubject, NInt * pValue);
NResult N_API NSubjectGetIris(HNSubject hSubject, NInt index, HNIris * phValue);
NResult N_API NSubjectGetIrises(HNSubject hSubject, HNIris * * parhValues, NInt * pValueCount);
NResult N_API NSubjectGetIrisCapacity(HNSubject hSubject, NInt * pValue);
NResult N_API NSubjectSetIrisCapacity(HNSubject hSubject, NInt value);
NResult N_API NSubjectSetIris(HNSubject hSubject, NInt index, HNIris hValue);
NResult N_API NSubjectAddIris(HNSubject hSubject, HNIris hValue, NInt * pIndex);
NResult N_API NSubjectInsertIris(HNSubject hSubject, NInt index, HNIris hValue);
NResult N_API NSubjectRemoveIrisAt(HNSubject hSubject, NInt index);
NResult N_API NSubjectClearIrises(HNSubject hSubject);

NResult N_API NSubjectAddIrisesCollectionChanged(HNSubject hSubject, HNCallback hCallback);
NResult N_API NSubjectAddIrisesCollectionChangedCallback(HNSubject hSubject, N_COLLECTION_CHANGED_CALLBACK_ARG(HNIris, pCallback), void * pParam);
NResult N_API NSubjectRemoveIrisesCollectionChanged(HNSubject hSubject, HNCallback hCallback);
NResult N_API NSubjectRemoveIrisesCollectionChangedCallback(HNSubject hSubject, N_COLLECTION_CHANGED_CALLBACK_ARG(HNIris, pCallback), void * pParam);

NResult N_API NSubjectGetPalmCount(HNSubject hSubject, NInt * pValue);
NResult N_API NSubjectGetPalm(HNSubject hSubject, NInt index, HNPalm * phValue);
NResult N_API NSubjectGetPalms(HNSubject hSubject, HNPalm * * parhValues, NInt * pValueCount);
NResult N_API NSubjectGetPalmCapacity(HNSubject hSubject, NInt * pValue);
NResult N_API NSubjectSetPalmCapacity(HNSubject hSubject, NInt value);
NResult N_API NSubjectSetPalm(HNSubject hSubject, NInt index, HNPalm hValue);
NResult N_API NSubjectAddPalm(HNSubject hSubject, HNPalm hValue, NInt * pIndex);
NResult N_API NSubjectInsertPalm(HNSubject hSubject, NInt index, HNPalm hValue);
NResult N_API NSubjectRemovePalmAt(HNSubject hSubject, NInt index);
NResult N_API NSubjectClearPalms(HNSubject hSubject);

NResult N_API NSubjectAddPalmsCollectionChanged(HNSubject hSubject, HNCallback hCallback);
NResult N_API NSubjectAddPalmsCollectionChangedCallback(HNSubject hSubject, N_COLLECTION_CHANGED_CALLBACK_ARG(HNPalm, pCallback), void * pParam);
NResult N_API NSubjectRemovePalmsCollectionChanged(HNSubject hSubject, HNCallback hCallback);
NResult N_API NSubjectRemovePalmsCollectionChangedCallback(HNSubject hSubject, N_COLLECTION_CHANGED_CALLBACK_ARG(HNPalm, pCallback), void * pParam);

NResult N_API NSubjectGetVoiceCount(HNSubject hSubject, NInt * pValue);
NResult N_API NSubjectGetVoice(HNSubject hSubject, NInt index, HNVoice * phValue);
NResult N_API NSubjectGetVoices(HNSubject hSubject, HNVoice * * parhValues, NInt * pValueCount);
NResult N_API NSubjectGetVoiceCapacity(HNSubject hSubject, NInt * pValue);
NResult N_API NSubjectSetVoiceCapacity(HNSubject hSubject, NInt value);
NResult N_API NSubjectSetVoice(HNSubject hSubject, NInt index, HNVoice hValue);
NResult N_API NSubjectAddVoice(HNSubject hSubject, HNVoice hValue, NInt * pIndex);
NResult N_API NSubjectInsertVoice(HNSubject hSubject, NInt index, HNVoice hValue);
NResult N_API NSubjectRemoveVoiceAt(HNSubject hSubject, NInt index);
NResult N_API NSubjectClearVoices(HNSubject hSubject);

NResult N_API NSubjectAddVoicesCollectionChanged(HNSubject hSubject, HNCallback hCallback);
NResult N_API NSubjectAddVoicesCollectionChangedCallback(HNSubject hSubject, N_COLLECTION_CHANGED_CALLBACK_ARG(HNVoice, pCallback), void * pParam);
NResult N_API NSubjectRemoveVoicesCollectionChanged(HNSubject hSubject, HNCallback hCallback);
NResult N_API NSubjectRemoveVoicesCollectionChangedCallback(HNSubject hSubject, N_COLLECTION_CHANGED_CALLBACK_ARG(HNVoice, pCallback), void * pParam);

NResult N_API NSubjectGetMissingFingerCount(HNSubject hSubject, NInt * pValue);
NResult N_API NSubjectGetMissingFinger(HNSubject hSubject, NInt index, NFPosition * pValue);
NResult N_API NSubjectGetMissingFingers(HNSubject hSubject, NFPosition * * parValues, NInt * pValueCount);
NResult N_API NSubjectGetMissingFingerCapacity(HNSubject hSubject, NInt * pValue);
NResult N_API NSubjectSetMissingFingerCapacity(HNSubject hSubject, NInt value);
NResult N_API NSubjectSetMissingFinger(HNSubject hSubject, NInt index, NFPosition value);
NResult N_API NSubjectAddMissingFinger(HNSubject hSubject, NFPosition hValue, NInt * pIndex);
NResult N_API NSubjectInsertMissingFinger(HNSubject hSubject, NInt index, NFPosition value);
NResult N_API NSubjectRemoveMissingFingerAt(HNSubject hSubject, NInt index);
NResult N_API NSubjectClearMissingFingers(HNSubject hSubject);

NResult N_API NSubjectGetMissingEyeCount(HNSubject hSubject, NInt * pValue);
NResult N_API NSubjectGetMissingEye(HNSubject hSubject, NInt index, NEPosition * pValue);
NResult N_API NSubjectGetMissingEyes(HNSubject hSubject, NEPosition * * parValues, NInt * pValueCount);
NResult N_API NSubjectGetMissingEyeCapacity(HNSubject hSubject, NInt * pValue);
NResult N_API NSubjectSetMissingEyeCapacity(HNSubject hSubject, NInt value);
NResult N_API NSubjectSetMissingEye(HNSubject hSubject, NInt index, NEPosition value);
NResult N_API NSubjectAddMissingEye(HNSubject hSubject, NEPosition hValue, NInt * pIndex);
NResult N_API NSubjectInsertMissingEye(HNSubject hSubject, NInt index, NEPosition value);
NResult N_API NSubjectRemoveMissingEyeAt(HNSubject hSubject, NInt index);
NResult N_API NSubjectClearMissingEyes(HNSubject hSubject);

NResult N_API NSubjectGetRelatedSubjectCount(HNSubject hSubject, NInt * pValue);
NResult N_API NSubjectGetRelatedSubject(HNSubject hSubject, NInt index, HNSubject * phValue);
NResult N_API NSubjectGetRelatedSubjects(HNSubject hSubject, HNSubject * * parhValues, NInt * pValueCount);
NResult N_API NSubjectGetRelatedSubjectCapacity(HNSubject hSubject, NInt * pValue);
NResult N_API NSubjectSetRelatedSubjectCapacity(HNSubject hSubject, NInt value);
NResult N_API NSubjectSetRelatedSubject(HNSubject hSubject, NInt index, HNSubject hValue);
NResult N_API NSubjectAddRelatedSubject(HNSubject hSubject, HNSubject hValue, NInt * pIndex);
NResult N_API NSubjectInsertRelatedSubject(HNSubject hSubject, NInt index, HNSubject hValue);
NResult N_API NSubjectRemoveRelatedSubjectAt(HNSubject hSubject, NInt index);
NResult N_API NSubjectClearRelatedSubjects(HNSubject hSubject);

NResult N_API NSubjectAddRelatedSubjectsCollectionChanged(HNSubject hSubject, HNCallback hCallback);
NResult N_API NSubjectAddRelatedSubjectsCollectionChangedCallback(HNSubject hSubject, N_COLLECTION_CHANGED_CALLBACK_ARG(HNSubject, pCallback), void * pParam);
NResult N_API NSubjectRemoveRelatedSubjectsCollectionChanged(HNSubject hSubject, HNCallback hCallback);
NResult N_API NSubjectRemoveRelatedSubjectsCollectionChangedCallback(HNSubject hSubject, N_COLLECTION_CHANGED_CALLBACK_ARG(HNSubject, pCallback), void * pParam);

NResult N_API NSubjectGetMatchingResultCount(HNSubject hSubject, NInt * pValue);
NResult N_API NSubjectGetMatchingResult(HNSubject hSubject, NInt index, HNMatchingResult * phValue);
NResult N_API NSubjectGetMatchingResults(HNSubject hSubject, HNMatchingResult * * parhValues, NInt * pValueCount);

#ifdef N_CPP
}
#endif

#endif // !N_SUBJECT_H_INCLUDED
