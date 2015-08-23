#include <Biometrics/NBiometricTask.hpp>
#include <Biometrics/NBiometricEngineTypes.hpp>
#include <Biometrics/NBiographicDataSchema.hpp>

#ifndef N_BIOMETRIC_ENGINE_HPP_INCLUDED
#define N_BIOMETRIC_ENGINE_HPP_INCLUDED

#include <Core/NObject.hpp>
#include <Core/NAsyncOperation.hpp>
#include <Biometrics/NSubject.hpp>
namespace Neurotec { namespace Biometrics
{
#include <Biometrics/NBiometricEngine.h>
}}

namespace Neurotec { namespace Biometrics
{

class NBiometricEngine : public NObject
{
	N_DECLARE_OBJECT_CLASS(NBiometricEngine, NObject)

private:
	static HNBiometricEngine Create()
	{
		HNBiometricEngine handle;
		NCheck(NBiometricEngineCreate(&handle));
		return handle;
	}

public:
	NBiometricEngine()
		: NObject(Create(), true)
	{
	}

	void Initialize()
	{
		NCheck(NBiometricEngineInitialize(GetHandle()));
	}

	NAsyncOperation InitializeAsync()
	{
		HNAsyncOperation hAsyncOperation;
		NCheck(NBiometricEngineInitializeAsync(GetHandle(), &hAsyncOperation));
		return FromHandle<NAsyncOperation>(hAsyncOperation);
	}

	NBiometricTask CreateTask(NBiometricOperations operations, const NSubject & subject, const NSubject & otherSubject = NULL) const
	{
		HNBiometricTask hBiometricTask;
		NCheck(NBiometricEngineCreateTask(GetHandle(), operations, subject.GetHandle(), otherSubject.GetHandle(), &hBiometricTask));
		return FromHandle<NBiometricTask>(hBiometricTask);
	}

	void PerformTask(const NBiometricTask & biometricTask) const
	{
		NCheck(NBiometricEnginePerformTask(GetHandle(), biometricTask.GetHandle()));
	}

	NAsyncOperation PerformTaskAsync(const NBiometricTask & biometricTask) const
	{
		HNAsyncOperation hAsyncOperation;
		NCheck(NBiometricEnginePerformTaskAsync(GetHandle(), biometricTask.GetHandle(), &hAsyncOperation));
		return FromHandle<NAsyncOperation>(hAsyncOperation);
	}

	NBiometricStatus Enroll(const NSubject & subject, bool checkForDuplicates = false)
	{
		NBiometricStatus result;
		NCheck(NBiometricEngineEnroll(GetHandle(), subject.GetHandle(), checkForDuplicates ? NTrue : NFalse, &result));
		return result;
	}

	NAsyncOperation EnrollAsync(const NSubject & subject, bool checkForDuplicates = false)
	{
		HNAsyncOperation hAsyncOperation;
		NCheck(NBiometricEngineEnrollAsync(GetHandle(), subject.GetHandle(), checkForDuplicates ? NTrue : NFalse, &hAsyncOperation));
		return FromHandle<NAsyncOperation>(hAsyncOperation);
	}

	NBiometricStatus CreateTemplate(const NSubject & subject) const
	{
		NBiometricStatus result;
		NCheck(NBiometricEngineCreateTemplate(GetHandle(), subject.GetHandle(), &result));
		return result;
	}

	NAsyncOperation CreateTemplateAsync(const NSubject & subject) const
	{
		HNAsyncOperation hAsyncOperation;
		NCheck(NBiometricEngineCreateTemplateAsync(GetHandle(), subject.GetHandle(), &hAsyncOperation));
		return FromHandle<NAsyncOperation>(hAsyncOperation);
	}

	NBiometricStatus Identify(const NSubject & subject) const
	{
		NBiometricStatus result;
		NCheck(NBiometricEngineIdentify(GetHandle(), subject.GetHandle(), &result));
		return result;
	}

	NAsyncOperation IdentifyAsync(const NSubject & subject) const
	{
		HNAsyncOperation hAsyncOperation;
		NCheck(NBiometricEngineIdentifyAsync(GetHandle(), subject.GetHandle(), &hAsyncOperation));
		return FromHandle<NAsyncOperation>(hAsyncOperation);
	}

	NBiometricStatus Verify(const NSubject & subject) const
	{
		NBiometricStatus result;
		NCheck(NBiometricEngineVerify(GetHandle(), subject.GetHandle(), &result));
		return result;
	}

	NAsyncOperation VerifyAsync(const NSubject & subject) const
	{
		HNAsyncOperation hAsyncOperation;
		NCheck(NBiometricEngineVerifyAsync(GetHandle(), subject.GetHandle(), &hAsyncOperation));
		return FromHandle<NAsyncOperation>(hAsyncOperation);
	}

	NBiometricStatus Verify(const NSubject & subject, const NSubject & otherSubject) const
	{
		NBiometricStatus result;
		NCheck(NBiometricEngineVerifyOffline(GetHandle(), subject.GetHandle(), otherSubject.GetHandle(), &result));
		return result;
	}

	NAsyncOperation VerifyAsync(const NSubject & subject, const NSubject & otherSubject) const
	{
		HNAsyncOperation hAsyncOperation;
		NCheck(NBiometricEngineVerifyOfflineAsync(GetHandle(), subject.GetHandle(), otherSubject.GetHandle(), &hAsyncOperation));
		return FromHandle<NAsyncOperation>(hAsyncOperation);
	}

	NBiometricStatus Delete(const NStringWrapper & id)
	{
		NBiometricStatus result;
		NCheck(NBiometricEngineDelete(GetHandle(), id.GetHandle(), &result));
		return result;
	}

	NAsyncOperation DeleteAsync(const NStringWrapper & id)
	{
		HNAsyncOperation hAsyncOperation;
		NCheck(NBiometricEngineDeleteAsync(GetHandle(), id.GetHandle(), &hAsyncOperation));
		return FromHandle<NAsyncOperation>(hAsyncOperation);
	}

	NBiometricStatus Clear()
	{
		NBiometricStatus result;
		NCheck(NBiometricEngineClear(GetHandle(), &result));
		return result;
	}

	NAsyncOperation ClearAsync()
	{
		HNAsyncOperation hAsyncOperation;
		NCheck(NBiometricEngineClearAsync(GetHandle(), &hAsyncOperation));
		return FromHandle<NAsyncOperation>(hAsyncOperation);
	}

	NBiometricStatus Get(const NSubject & subject) const
	{
		NBiometricStatus result;
		NCheck(NBiometricEngineGet(GetHandle(), subject.GetHandle(), &result));
		return result;
	}

	NAsyncOperation GetAsync(const NSubject & subject) const
	{
		HNAsyncOperation hAsyncOperation;
		NCheck(NBiometricEngineGetAsync(GetHandle(), subject.GetHandle(), &hAsyncOperation));
		return FromHandle<NAsyncOperation>(hAsyncOperation);
	}

	NArrayWrapper<NSubject> List() const
	{
		HNSubject * arhValues;
		NInt valueCount;
		NCheck(NBiometricEngineList(GetHandle(), &arhValues, &valueCount));
		return NArrayWrapper<NSubject>(arhValues, valueCount);
	}

	NAsyncOperation ListAsync() const
	{
		HNAsyncOperation hAsyncOperation;
		NCheck(NBiometricEngineListAsync(GetHandle(), &hAsyncOperation));
		return FromHandle<NAsyncOperation>(hAsyncOperation);
	}

	NFace DetectFaces(const ::Neurotec::Images::NImage & image) const
	{
		HNFace hResult;
		NCheck(NBiometricEngineDetectFaces(GetHandle(), image.GetHandle(), &hResult));
		return FromHandle<NFace>(hResult);
	}

	NAsyncOperation DetectFacesAsync(const ::Neurotec::Images::NImage & image) const
	{
		HNAsyncOperation hAsyncOperation;
		NCheck(NBiometricEngineDetectFacesAsync(GetHandle(), image.GetHandle(), &hAsyncOperation));
		return FromHandle<NAsyncOperation>(hAsyncOperation);
	}

	NTimeSpan GetTimeout() const
	{
		return GetProperty<NTimeSpan>(N_T("Timeout"));
	}

	void SetTimeout(const NTimeSpan & value)
	{
		SetProperty(N_T("Timeout"), value);
	}

	NInt GetMaximalThreadCount() const
	{
		return GetProperty<NInt>(N_T("MaximalThreadCount"));
	}

	void SetMaximalThreadCount(NInt value)
	{
		SetProperty(N_T("MaximalThreadCount"), value);
	}

	NBiographicDataSchema GetBiographicDataSchema() const
	{
		return GetProperty<NBiographicDataSchema>(N_T("BiographicDataSchema"));
	}

	void SetBiographicDataSchema(const NBiographicDataSchema & value)
	{
		SetProperty(N_T("BiographicDataSchema"), value);
	}

	bool GetFingersDeterminePatternClass() const
	{
		return GetProperty<bool>(N_T("Fingers.DeterminePatternClass"));
	}

	void SetFingersDeterminePatternClass(bool value)
	{
		SetProperty(N_T("Fingers.DeterminePatternClass"), value);
	}

	bool GetFingersCalculateNfiq() const
	{
		return GetProperty<bool>(N_T("Fingers.CalculateNfiq"));
	}

	void SetFingersCalculateNfiq(bool value)
	{
		SetProperty(N_T("Fingers.CalculateNfiq"), value);
	}

	bool GetFingersFastExtraction() const
	{
		return GetProperty<bool>(N_T("Fingers.FastExtraction"));
	}

	void SetFingersFastExtraction(bool value)
	{
		SetProperty(N_T("Fingers.FastExtraction"), value);
	}

	NTemplateSize GetFingersTemplateSize() const
	{
		return GetProperty<NTemplateSize>(N_T("Fingers.TemplateSize"));
	}

	void SetFingersTemplateSize(NTemplateSize value)
	{
		SetProperty(N_T("Fingers.TemplateSize"), value);
	}

	NByte GetFingersQualityThreshold() const
	{
		return GetProperty<NByte>(N_T("Fingers.QualityThreshold"));
	}

	void SetFingersQualityThreshold(NByte value)
	{
		SetProperty(N_T("Fingers.QualityThreshold"), value);
	}

	bool GetFingersReturnProcessedImage() const
	{
		return GetProperty<bool>(N_T("Fingers.ReturnProcessedImage"));
	}

	void SetFingersReturnProcessedImage(bool value)
	{
		SetProperty(N_T("Fingers.ReturnProcessedImage"), value);
	}

	NFloat GetFingersMaximalRotation() const
	{
		return GetProperty<NFloat>(N_T("Fingers.MaximalRotation"));
	}

	void SetFingersMaximalRotation(NFloat value)
	{
		SetProperty(N_T("Fingers.MaximalRotation"), value);
	}

	NMatchingSpeed GetFingersMatchingSpeed() const
	{
		return GetProperty<NMatchingSpeed>(N_T("Fingers.MatchingSpeed"));
	}

	void SetFingersMatchingSpeed(NMatchingSpeed value)
	{
		SetProperty(N_T("Fingers.MatchingSpeed"), value);
	}

	bool GetFacesCreateThumbnailImage() const
	{
		return GetProperty<bool>(N_T("Faces.CreateThumbnailImage"));
	}

	void SetFacesCreateThumbnailImage(bool value)
	{
		SetProperty(N_T("Faces.CreateThumbnailImage"), value);
	}

	int GetFacesThumbnailImageWidth() const
	{
		return GetProperty<int>(N_T("Faces.ThumbnailImageWidth"));
	}

	void SetFacesThumbnailWidth(int value)
	{
		SetProperty(N_T("Faces.ThumbnailImageWidth"), value);
	}

	NInt GetFacesMinimalInterOcularDistance() const
	{
		return GetProperty<NInt>(N_T("Faces.MinimalInterOcularDistance"));
	}

	void SetFacesMinimalInterOcularDistance(NInt value)
	{
		SetProperty(N_T("Faces.MinimalInterOcularDistance"), value);
	}

	NByte GetFacesConfidenceThreshold() const
	{
		return GetProperty<NByte>(N_T("Faces.ConfidenceThreshold"));
	}

	void SetFacesConfidenceThreshold(NByte value)
	{
		SetProperty(N_T("Faces.ConfidenceThreshold"), value);
	}

	NFloat GetFacesMaximalRoll() const
	{
		return GetProperty<NFloat>(N_T("Faces.MaximalRoll"));
	}

	void SetFacesMaximalRoll(NFloat value)
	{
		SetProperty(N_T("Faces.MaximalRoll"), value);
	}

	NFloat GetFacesMaximalYaw() const
	{
		return GetProperty<NFloat>(N_T("Faces.MaximalYaw"));
	}

	void SetFacesMaximalYaw(NFloat value)
	{
		SetProperty(N_T("Faces.MaximalYaw"), value);
	}

	bool GetFacesDetectAllFeaturePoints() const
	{
		return GetProperty<bool>(N_T("Faces.DetectAllFeaturePoints"));
	}

	void SetFacesDetectAllFeaturePoints(bool value)
	{
		SetProperty(N_T("Faces.DetectAllFeaturePoints"), value);
	}

	bool GetFacesDetectBaseFeaturePoints() const
	{
		return GetProperty<bool>(N_T("Faces.DetectBaseFeaturePoints"));
	}

	void SetFacesDetectBaseFeaturePoints(bool value)
	{
		SetProperty(N_T("Faces.DetectBaseFeaturePoints"), value);
	}

	bool GetFacesDetermineGender() const
	{
		return GetProperty<bool>(N_T("Faces.DetermineGender"));
	}

	void SetFacesDetermineGender(bool value)
	{
		SetProperty(N_T("Faces.DetermineGender"), value);
	}

	bool GetFacesDetectProperties() const
	{
		return GetProperty<bool>(N_T("Faces.DetectProperties"));
	}

	void SetFacesDetectProperties(bool value)
	{
		SetProperty(N_T("Faces.DetectProperties"), value);
	}

	bool GetFacesRecognizeExpression() const
	{
		return GetProperty<bool>(N_T("Faces.RecognizeExpression"));
	}

	void SetFacesRecognizeExpression(bool value)
	{
		SetProperty(N_T("Faces.RecognizeExpression"), value);
	}

	bool GetFacesRecognizeEmotion() const
	{
		return GetProperty<bool>(N_T("Faces.RecognizeEmotion"));
	}

	void SetFacesRecognizeEmotion(bool value)
	{
		SetProperty(N_T("Faces.RecognizeEmotion"), value);
	}

	NTemplateSize GetFacesTemplateSize() const
	{
		return GetProperty<NTemplateSize>(N_T("Faces.TemplateSize"));
	}

	void SetFacesTemplateSize(NTemplateSize value)
	{
		SetProperty(N_T("Faces.TemplateSize"), value);
	}

	NByte GetFacesQualityThreshold() const
	{
		return GetProperty<NByte>(N_T("Faces.QualityThreshold"));
	}

	void SetFacesQualityThreshold(NByte value)
	{
		SetProperty(N_T("Faces.QualityThreshold"), value);
	}

	bool GetFacesUseLivenessCheck() const
	{
		return GetProperty<bool>(N_T("Faces.UseLivenessCheck"));
	}

	void SetFacesUseLivenessCheck(bool value)
	{
		SetProperty(N_T("Faces.UseLivenessCheck"), value);
	}

	NByte GetFacesLivenessThreshold() const
	{
		return GetProperty<NByte>(N_T("Faces.LivenessThreshold"));
	}

	void SetFacesLivenessThreshold(NByte value)
	{
		SetProperty(N_T("Faces.LivenessThreshold"), value);
	}

	NMatchingSpeed GetFacesMatchingSpeed() const
	{
		return GetProperty<NMatchingSpeed>(N_T("Faces.MatchingSpeed"));
	}

	void SetFacesMatchingSpeed(NMatchingSpeed value)
	{
		SetProperty(N_T("Faces.MatchingSpeed"), value);
	}

	NInt GetFacesTokenImageWidth() const
	{
		return GetProperty<NInt>(N_T("Faces.TokenImageWidth"));
	}

	void SetFacesTokenImageWidth(NInt value)
	{
		SetProperty(N_T("Faces.TokenImageWidth"), value);
	}

	NByte GetFacesTokenQualityThreshold() const
	{
		return GetProperty<NByte>(N_T("Faces.TokenQualityThreshold"));
	}

	void SetFacesTokenQualityThreshold(NByte value)
	{
		SetProperty(N_T("Faces.TokenQualityThreshold"), value);
	}

	NByte GetFacesSharpnessThreshold() const
	{
		return GetProperty<NByte>(N_T("Faces.SharpnessThreshold"));
	}

	void SetFacesSharpnessThreshold(NByte value)
	{
		SetProperty(N_T("Faces.SharpnessThreshold"), value);
	}

	NByte GetFacesBackgroundUniformityThreshold() const
	{
		return GetProperty<NByte>(N_T("Faces.BackgroundUniformityThreshold"));
	}

	void SetFacesBackgroundUniformityThreshold(NByte value)
	{
		SetProperty(N_T("Faces.BackgroundUniformityThreshold"), value);
	}

	NByte GetFacesGrayscaleDensityThreshold() const
	{
		return GetProperty<NByte>(N_T("Faces.GrayscaleDensityThreshold"));
	}

	void SetFacesGrayscaleDensityThreshold(NByte value)
	{
		SetProperty(N_T("Faces.GrayscaleDensityThreshold"), value);
	}

	bool GetIrisesFastExtraction() const
	{
		return GetProperty<bool>(N_T("Irises.FastExtraction"));
	}

	void SetIrisesFastExtraction(bool value)
	{
		SetProperty(N_T("Irises.FastExtraction"), value);
	}

	NTemplateSize GetIrisesTemplateSize() const
	{
		return GetProperty<NTemplateSize>(N_T("Irises.TemplateSize"));
	}

	void SetIrisesTemplateSize(NTemplateSize value)
	{
		SetProperty(N_T("Irises.TemplateSize"), value);
	}

	NByte GetIrisesQualityThreshold() const
	{
		return GetProperty<NByte>(N_T("Irises.QualityThreshold"));
	}

	void SetIrisesQualityThreshold(NByte value)
	{
		SetProperty(N_T("Irises.QualityThreshold"), value);
	}

	NMatchingSpeed GetIrisesMatchingSpeed() const
	{
		return GetProperty<NMatchingSpeed>(N_T("Irises.MatchingSpeed"));
	}

	void SetIrisesMatchingSpeed(NMatchingSpeed value)
	{
		SetProperty(N_T("Irises.MatchingSpeed"), value);
	}

	NFloat GetIrisesMaximalRotation() const
	{
		return GetProperty<NFloat>(N_T("Irises.MaximalRotation"));
	}

	void SetIrisesMaximalRotation(NFloat value)
	{
		SetProperty(N_T("Irises.MaximalRotation"), value);
	}

	NTemplateSize GetPalmsTemplateSize() const
	{
		return GetProperty<NTemplateSize>(N_T("Palms.TemplateSize"));
	}

	void SetPalmsTemplateSize(NTemplateSize value)
	{
		SetProperty(N_T("Palms.TemplateSize"), value);
	}

	NByte GetPalmsQualityThreshold() const
	{
		return GetProperty<NByte>(N_T("Palms.QualityThreshold"));
	}

	void SetPalmsQualityThreshold(NByte value)
	{
		SetProperty(N_T("Palms.QualityThreshold"), value);
	}

	bool GetPalmsReturnProcessedImage() const
	{
		return GetProperty<bool>(N_T("Palms.ReturnProcessedImage"));
	}

	void SetPalmsReturnProcessedImage(bool value)
	{
		SetProperty(N_T("Palms.ReturnProcessedImage"), value);
	}

	NFloat GetPalmsMaximalRotation() const
	{
		return GetProperty<NFloat>(N_T("Palms.MaximalRotation"));
	}

	void SetPalmsMaximalRotation(NFloat value)
	{
		SetProperty(N_T("Palms.MaximalRotation"), value);
	}

	NMatchingSpeed GetPalmsMatchingSpeed() const
	{
		return GetProperty<NMatchingSpeed>(N_T("Palms.MatchingSpeed"));
	}

	void SetPalmsMatchingSpeed(NMatchingSpeed value)
	{
		SetProperty(N_T("Palms.MatchingSpeed"), value);
	}

	NLong GetVoicesMaximalLoadedFileSize() const
	{
		return GetProperty<NLong>(N_T("Voices.MaximalLoadedFileSize"));
	}

	void SetVoicesMaximalLoadedFileSize(NLong value)
	{
		SetProperty(N_T("Voices.MaximalLoadedFileSize"), value);
	}

	bool GetVoicesUniquePhrasesOnly() const
	{
		return GetProperty<bool>(N_T("Voices.UniquePhrasesOnly"));
	}

	void SetVoicesUniquePhrasesOnly(bool value)
	{
		SetProperty(N_T("Voices.UniquePhrasesOnly"), value);
	}

	bool GetVoicesExtractTextDependentFeatures() const
	{
		return GetProperty<bool>(N_T("Voices.ExtractTextDependentFeatures"));
	}

	void SetVoicesExtractTextDependentFeatures(bool value)
	{
		SetProperty(N_T("Voices.ExtractTextDependentFeatures"), value);
	}

	bool GetVoicesExtractTextIndependentFeatures() const
	{
		return GetProperty<bool>(N_T("Voices.ExtractTextIndependentFeatures"));
	}

	void SetVoicesExtractTextIndependentFeatures(bool value)
	{
		SetProperty(N_T("Voices.ExtractTextIndependentFeatures"), value);
	}

	bool GetMatchingWithDetails() const
	{
		return GetProperty<bool>(N_T("Matching.WithDetails"));
	}

	void SetMatchingWithDetails(bool value)
	{
		SetProperty(N_T("Matching.WithDetails"), value);
	}

	NInt GetMatchingMaximalResultCount() const
	{
		return GetProperty<NInt>(N_T("Matching.MaximalResultCount"));
	}

	void SetMatchingMaximalResultCount(NInt value)
	{
		SetProperty(N_T("Matching.MaximalResultCount"), value);
	}

	bool GetFirstResultOnly() const
	{
		return GetProperty<bool>(N_T("Matching.FirstResultOnly"));
	}

	void SetFirstResultOnly(bool value)
	{
		SetProperty(N_T("Matching.FirstResultOnly"), value);
	}

	NInt GetMatchingThreshold() const
	{
		return GetProperty<NInt>(N_T("Matching.Threshold"));
	}

	void SetMatchingThreshold(NInt value)
	{
		SetProperty(N_T("Matching.Threshold"), value);
	}
};

}}

#endif // !N_BIOMETRIC_ENGINE_HPP_INCLUDED
