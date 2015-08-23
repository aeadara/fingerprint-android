#include <Biometrics/Standards/ANRecord.hpp>

#ifndef AN_TEMPLATE_HPP_INCLUDED
#define AN_TEMPLATE_HPP_INCLUDED

#include <Biometrics/Standards/ANRecordType.hpp>
#include <Biometrics/Standards/ANType1Record.hpp>
#include <Biometrics/Standards/ANType2Record.hpp>
#include <Biometrics/Standards/ANType3Record.hpp>
#include <Biometrics/Standards/ANType4Record.hpp>
#include <Biometrics/Standards/ANType5Record.hpp>
#include <Biometrics/Standards/ANType6Record.hpp>
#include <Biometrics/Standards/ANType7Record.hpp>
#include <Biometrics/Standards/ANType8Record.hpp>
#include <Biometrics/Standards/ANType9Record.hpp>
#include <Biometrics/Standards/ANType10Record.hpp>
#include <Biometrics/Standards/ANType13Record.hpp>
#include <Biometrics/Standards/ANType14Record.hpp>
#include <Biometrics/Standards/ANType15Record.hpp>
#include <Biometrics/Standards/ANType16Record.hpp>
#include <Biometrics/Standards/ANType17Record.hpp>
#include <Biometrics/Standards/ANType99Record.hpp>
#include <Images/NImage.hpp>
#include <Biometrics/NTemplate.hpp>
namespace Neurotec { namespace Biometrics { namespace Standards
{
using ::Neurotec::Images::HNImage;
using ::Neurotec::Images::HNGrayscaleImage;
using ::Neurotec::Images::HNMonochromeImage;
#include <Biometrics/Standards/ANTemplate.h>
}}}

N_DEFINE_ENUM_TYPE_TRAITS(Neurotec::Biometrics::Standards, ANValidationLevel)

namespace Neurotec { namespace Biometrics { namespace Standards
{

#undef AN_TEMPLATE_VERSION_2_0
#undef AN_TEMPLATE_VERSION_2_1
#undef AN_TEMPLATE_VERSION_3_0
#undef AN_TEMPLATE_VERSION_4_0

#undef AN_TEMPLATE_VERSION_CURRENT

#undef ANT_USE_NIST_MINUTIA_NEIGHBORS
#undef ANT_LEAVE_INVALID_RECORDS_UNVALIDATED
#undef ANT_USE_TWO_DIGIT_IDC
#undef ANT_USE_TWO_DIGIT_FIELD_NUMBER
#undef ANT_USE_TWO_DIGIT_FIELD_NUMBER_TYPE_1

const NVersion AN_TEMPLATE_VERSION_2_0(0x0200);
const NVersion AN_TEMPLATE_VERSION_2_1(0x0201);
const NVersion AN_TEMPLATE_VERSION_3_0(0x0300);
const NVersion AN_TEMPLATE_VERSION_4_0(0x0400);

const NVersion AN_TEMPLATE_VERSION_CURRENT(AN_TEMPLATE_VERSION_4_0);

const NUInt ANT_USE_NIST_MINUTIA_NEIGHBORS = 0x00010000;
const NUInt ANT_LEAVE_INVALID_RECORDS_UNVALIDATED = 0x00020000;
const NUInt ANT_USE_TWO_DIGIT_IDC = 0x00040000;
const NUInt ANT_USE_TWO_DIGIT_FIELD_NUMBER = 0x00080000;
const NUInt ANT_USE_TWO_DIGIT_FIELD_NUMBER_TYPE_1 = 0x00100000;

class ANTemplate : public NObject
{
	N_DECLARE_OBJECT_CLASS(ANTemplate, NObject)

public:
	class RecordCollection : public ::Neurotec::Collections::NCollectionBase<ANRecord, ANTemplate,
		ANTemplateGetRecordCount, ANTemplateGetRecordEx>
	{
		RecordCollection(const ANTemplate & owner)
		{
			SetOwner(owner);
		}

		friend class ANTemplate;
	public:
		NInt GetCapacity() const
		{
			NInt value;
			NCheck(ANTemplateGetRecordCapacity(this->GetOwnerHandle(), &value));
			return value;
		}

		void SetCapacity(NInt value)
		{
			NCheck(ANTemplateSetRecordCapacity(this->GetOwnerHandle(), value));
		}

		void RemoveAt(NInt index)
		{
			NCheck(ANTemplateRemoveRecordAt(this->GetOwnerHandle(), index));
		}

		void Clear()
		{
			NCheck(ANTemplateClearRecords(this->GetOwnerHandle()));
		}


		ANRecord Add(const ANRecordType & recordType, NInt idc, NUInt flags = 0)
		{
			HANRecord hRecord;
			NCheck(ANTemplateAddRecord(this->GetOwnerHandle(), recordType.GetHandle(), idc, flags | N_OBJECT_REF_RET, &hRecord));
			return FromHandle<ANRecord>(hRecord, true);
		}

		ANType2Record AddType2(NInt idc, NUInt flags = 0)
		{
			HANType2Record hRecord;
			NCheck(ANTemplateAddType2Record(this->GetOwnerHandle(), idc, flags | N_OBJECT_REF_RET, &hRecord));
			return FromHandle<ANType2Record>(hRecord, true);
		}

		ANType3Record AddType3(NInt idc, bool isr, NUInt isrValue, NUInt ir, NUShort hll, NUShort vll,
			ANImageCompressionAlgorithm ca, NByte vendorCA, const ::Neurotec::IO::NBuffer & imageData, NUInt flags = 0)
		{
			HANType3Record hRecord;
			NCheck(ANTemplateAddType3RecordN(this->GetOwnerHandle(), idc, isr ? NTrue : NFalse, isrValue, ir, hll, vll,
				ca, vendorCA, imageData.GetHandle(), flags | N_OBJECT_REF_RET, &hRecord));
			return FromHandle<ANType3Record>(hRecord, true);
		}

		ANType3Record AddType3(NInt idc, bool isr, NUInt isrValue, NUInt ir, NUShort hll, NUShort vll,
			ANImageCompressionAlgorithm ca, NByte vendorCA, const void * pImageData, NSizeType imageDataLength, NUInt flags = 0)
		{
			HANType3Record hRecord;
			NCheck(ANTemplateAddType3Record(this->GetOwnerHandle(), idc, isr ? NTrue : NFalse, isrValue, ir, hll, vll,
				ca, vendorCA, pImageData, imageDataLength, flags | N_OBJECT_REF_RET, &hRecord));
			return FromHandle<ANType3Record>(hRecord, true);
		}

		ANType3Record AddType3(NInt idc, bool isr, NUInt isrValue,
			ANImageCompressionAlgorithm ca, const ::Neurotec::Images::NImage & image, NUInt flags = 0)
		{
			HANType3Record hRecord;
			NCheck(ANTemplateAddType3RecordFromNImageEx(this->GetOwnerHandle(), idc, isr ? NTrue : NFalse, isrValue,
				ca, (HNGrayscaleImage)image.GetHandle(), flags | N_OBJECT_REF_RET, &hRecord));
			return FromHandle<ANType3Record>(hRecord, true);
		}

		ANType4Record AddType4(NInt idc, bool isr, NUInt isrValue, NUInt ir, NUShort hll, NUShort vll,
			ANImageCompressionAlgorithm ca, NByte vendorCA, const ::Neurotec::IO::NBuffer & imageData, NUInt flags = 0)
		{
			HANType4Record hRecord;
			NCheck(ANTemplateAddType4RecordN(this->GetOwnerHandle(), idc, isr ? NTrue : NFalse, isrValue, ir, hll, vll,
				ca, vendorCA, imageData.GetHandle(), flags | N_OBJECT_REF_RET, &hRecord));
			return FromHandle<ANType4Record>(hRecord, true);
		}

		ANType4Record AddType4(NInt idc, bool isr, NUInt isrValue, NUInt ir, NUShort hll, NUShort vll,
			ANImageCompressionAlgorithm ca, NByte vendorCA, const void * pImageData, NSizeType imageDataLength, NUInt flags = 0)
		{
			HANType4Record hRecord;
			NCheck(ANTemplateAddType4Record(this->GetOwnerHandle(), idc, isr ? NTrue : NFalse, isrValue, ir, hll, vll,
				ca, vendorCA, pImageData, imageDataLength, flags | N_OBJECT_REF_RET, &hRecord));
			return FromHandle<ANType4Record>(hRecord, true);
		}

		ANType4Record AddType4(NInt idc, bool isr, NUInt isrValue,
			ANImageCompressionAlgorithm ca, const ::Neurotec::Images::NImage & image, NUInt flags = 0)
		{
			HANType4Record hRecord;
			NCheck(ANTemplateAddType4RecordFromNImageEx(this->GetOwnerHandle(), idc, isr ? NTrue : NFalse, isrValue,
				ca, (HNGrayscaleImage)image.GetHandle(), flags | N_OBJECT_REF_RET, &hRecord));
			return FromHandle<ANType4Record>(hRecord, true);
		}

		ANType5Record AddType5(NInt idc, bool isr, NUInt isrValue, NUInt ir, NUShort hll, NUShort vll,
			ANBinaryImageCompressionAlgorithm ca, NByte vendorCA, const ::Neurotec::IO::NBuffer & imageData, NUInt flags = 0)
		{
			HANType5Record hRecord;
			NCheck(ANTemplateAddType5RecordN(this->GetOwnerHandle(), idc, isr ? NTrue : NFalse, isrValue, ir, hll, vll,
				ca, vendorCA, imageData.GetHandle(), flags | N_OBJECT_REF_RET, &hRecord));
			return FromHandle<ANType5Record>(hRecord, true);
		}

		ANType5Record AddType5(NInt idc, bool isr, NUInt isrValue, NUInt ir, NUShort hll, NUShort vll,
			ANBinaryImageCompressionAlgorithm ca, NByte vendorCA, const void * pImageData, NSizeType imageDataLength, NUInt flags = 0)
		{
			HANType5Record hRecord;
			NCheck(ANTemplateAddType5Record(this->GetOwnerHandle(), idc, isr ? NTrue : NFalse, isrValue, ir, hll, vll,
				ca, vendorCA, pImageData, imageDataLength, flags | N_OBJECT_REF_RET, &hRecord));
			return FromHandle<ANType5Record>(hRecord, true);
		}

		ANType5Record AddType5(NInt idc, bool isr, NUInt isrValue,
			ANBinaryImageCompressionAlgorithm ca, const ::Neurotec::Images::NImage & image, NUInt flags = 0)
		{
			HANType5Record hRecord;
			NCheck(ANTemplateAddType5RecordFromNImageEx(this->GetOwnerHandle(), idc, isr ? NTrue : NFalse, isrValue,
				ca, (HNMonochromeImage)image.GetHandle(), flags | N_OBJECT_REF_RET, &hRecord));
			return FromHandle<ANType5Record>(hRecord, true);
		}

		ANType6Record AddType6(NInt idc, bool isr, NUInt isrValue, NUInt ir, NUShort hll, NUShort vll,
			ANBinaryImageCompressionAlgorithm ca, NByte vendorCA, const ::Neurotec::IO::NBuffer & imageData, NUInt flags = 0)
		{
			HANType6Record hRecord;
			NCheck(ANTemplateAddType6RecordN(this->GetOwnerHandle(), idc, isr ? NTrue : NFalse, isrValue, ir, hll, vll,
				ca, vendorCA, imageData.GetHandle(), flags | N_OBJECT_REF_RET, &hRecord));
			return FromHandle<ANType6Record>(hRecord, true);
		}

		ANType6Record AddType6(NInt idc, bool isr, NUInt isrValue, NUInt ir, NUShort hll, NUShort vll,
			ANBinaryImageCompressionAlgorithm ca, NByte vendorCA, const void * pImageData, NSizeType imageDataLength, NUInt flags = 0)
		{
			HANType6Record hRecord;
			NCheck(ANTemplateAddType6Record(this->GetOwnerHandle(), idc, isr ? NTrue : NFalse, isrValue, ir, hll, vll,
				ca, vendorCA, pImageData, imageDataLength, flags | N_OBJECT_REF_RET, &hRecord));
			return FromHandle<ANType6Record>(hRecord, true);
		}

		ANType6Record AddType6(NInt idc, bool isr, NUInt isrValue,
			ANBinaryImageCompressionAlgorithm ca, const ::Neurotec::Images::NImage & image, NUInt flags = 0)
		{
			HANType6Record hRecord;
			NCheck(ANTemplateAddType6RecordFromNImageEx(this->GetOwnerHandle(), idc, isr ? NTrue : NFalse, isrValue,
				ca, (HNMonochromeImage)image.GetHandle(), flags | N_OBJECT_REF_RET, &hRecord));
			return FromHandle<ANType6Record>(hRecord, true);
		}

		ANType7Record AddType7(NInt idc, NUInt isr, NUInt ir, const ::Neurotec::IO::NBuffer & imageData, NUInt flags = 0)
		{
			HANType7Record hRecord;
			NCheck(ANTemplateAddType7RecordN(this->GetOwnerHandle(), idc, isr, ir, imageData.GetHandle(), flags | N_OBJECT_REF_RET, &hRecord));
			return FromHandle<ANType7Record>(hRecord, true);
		}

		ANType7Record AddType7(NInt idc, NUInt isr, NUInt ir, const void * pImageData, NSizeType imageDataLength, NUInt flags = 0)
		{
			HANType7Record hRecord;
			NCheck(ANTemplateAddType7Record(this->GetOwnerHandle(), idc, isr, ir, pImageData, imageDataLength, flags | N_OBJECT_REF_RET, &hRecord));
			return FromHandle<ANType7Record>(hRecord, true);
		}

		ANType8Record AddType8(NInt idc, ANSignatureRepresentationType srt, bool isr, NUInt isrValue, NUInt ir, NUShort hll, NUShort vll,
			const ::Neurotec::IO::NBuffer & imageData, NUInt flags = 0)
		{
			HANType8Record hRecord;
			NCheck(ANTemplateAddType8RecordN(this->GetOwnerHandle(), idc, srt, isr ? NTrue : NFalse, isrValue, ir, hll, vll,
				imageData.GetHandle(), flags | N_OBJECT_REF_RET, &hRecord));
			return FromHandle<ANType8Record>(hRecord, true);
		}

		ANType8Record AddType8(NInt idc, ANSignatureRepresentationType srt, bool isr, NUInt isrValue, NUInt ir, NUShort hll, NUShort vll,
			const void * pImageData, NSizeType imageDataLength, NUInt flags = 0)
		{
			HANType8Record hRecord;
			NCheck(ANTemplateAddType8Record(this->GetOwnerHandle(), idc, srt, isr ? NTrue : NFalse, isrValue, ir, hll, vll,
				pImageData, imageDataLength, flags | N_OBJECT_REF_RET, &hRecord));
			return FromHandle<ANType8Record>(hRecord, true);
		}

		ANType8Record AddType8(NInt idc, NUInt isr, NUInt ir, const ANPenVector * arPenVectors, NInt penVectorCount, NUInt flags = 0)
		{
			HANType8Record hRecord;
			NCheck(ANTemplateAddType8RecordFromVectors(this->GetOwnerHandle(), idc, isr, ir, arPenVectors,
				penVectorCount, flags | N_OBJECT_REF_RET, &hRecord));
			return FromHandle<ANType8Record>(hRecord, true);
		}

		ANType8Record AddType8(NInt idc, ANSignatureRepresentationType srt, bool isr, NUInt isrValue,
			const ::Neurotec::Images::NImage & image, NUInt flags = 0)
		{
			HANType8Record hRecord;
			NCheck(ANTemplateAddType8RecordFromNImageEx(this->GetOwnerHandle(), idc, srt, isr ? NTrue : NFalse, isrValue,
				(HNMonochromeImage)image.GetHandle(), flags | N_OBJECT_REF_RET, &hRecord));
			return FromHandle<ANType8Record>(hRecord, true);
		}

		ANType9Record AddType9(NInt idc, BdifFPImpressionType imp, bool fmt, bool hasMinutiae, bool rdg,
			bool hasMinutiaeRidgeCountsIndicator, NUInt flags = 0)
		{
			HANType9Record hRecord;
			NCheck(ANTemplateAddType9Record(this->GetOwnerHandle(), idc, imp, fmt ? NTrue : NFalse, hasMinutiae ? NTrue : NFalse,
				rdg ? NTrue : NFalse, hasMinutiaeRidgeCountsIndicator ? NTrue : NFalse, flags | N_OBJECT_REF_RET, &hRecord));
			return FromHandle<ANType9Record>(hRecord, true);
		}

		ANType9Record AddType9(NInt idc, bool fmt, const NFRecord & nfRecord, NUInt flags = 0)
		{
			HANType9Record hRecord;
			NCheck(ANTemplateAddType9RecordFromNFRecord(this->GetOwnerHandle(), idc, fmt ? NTrue : NFalse,
				nfRecord.GetHandle(), flags | N_OBJECT_REF_RET, &hRecord));
			return FromHandle<ANType9Record>(hRecord, true);
		}

		ANType10Record AddType10(NInt idc, ANImageType imt, const NStringWrapper & src, NUShort hll, NUShort vll,
			BdifScaleUnits slc, NUShort hps, NUShort vps, ANImageCompressionAlgorithm cga, ANImageColorSpace csp, const NStringWrapper & smt,
			const ::Neurotec::IO::NBuffer & imageData, NUInt flags = 0)
		{
			HANType10Record hRecord;
			NCheck(ANTemplateAddType10RecordN(this->GetOwnerHandle(), idc, imt, src.GetHandle(), hll, vll,
				slc, hps, vps, cga, csp, smt.GetHandle(), imageData.GetHandle(), flags | N_OBJECT_REF_RET, &hRecord));
			return FromHandle<ANType10Record>(hRecord, true);
		}

		ANType10Record AddType10(NInt idc, ANImageType imt, const NStringWrapper & src, NUShort hll, NUShort vll,
			BdifScaleUnits slc, NUShort hps, NUShort vps, ANImageCompressionAlgorithm cga, ANImageColorSpace csp, const NStringWrapper & smt,
			const void * pImageData, NSizeType imageDataLength, NUInt flags = 0)
		{
			HANType10Record hRecord;
			NCheck(ANTemplateAddType10RecordSSN(this->GetOwnerHandle(), idc, imt, src.GetHandle(), hll, vll,
				slc, hps, vps, cga, csp, smt.GetHandle(), pImageData, imageDataLength, flags | N_OBJECT_REF_RET, &hRecord));
			return FromHandle<ANType10Record>(hRecord, true);
		}

		ANType10Record AddType10(NInt idc, ANImageType imt, const NStringWrapper & src,
			BdifScaleUnits slc, ANImageCompressionAlgorithm cga, const NStringWrapper & smt,
			const ::Neurotec::Images::NImage & image, NUInt flags = 0)
		{
			HANType10Record hRecord;
			NCheck(ANTemplateAddType10RecordFromNImageN(this->GetOwnerHandle(), idc, imt, src.GetHandle(),
				slc, cga, smt.GetHandle(), image.GetHandle(), flags | N_OBJECT_REF_RET, &hRecord));
			return FromHandle<ANType10Record>(hRecord, true);
		}

		ANType13Record AddType13(NInt idc, BdifFPImpressionType imp, const NStringWrapper & src, NUShort hll, NUShort vll,
			BdifScaleUnits slc, NUShort hps, NUShort vps, ANImageCompressionAlgorithm cga, NByte bpx,
			const ::Neurotec::IO::NBuffer & imageData, NUInt flags = 0)
		{
			HANType13Record hRecord;
			NCheck(ANTemplateAddType13RecordN(this->GetOwnerHandle(), idc, imp, src.GetHandle(), hll, vll,
				slc, hps, vps, cga, bpx, imageData.GetHandle(), flags | N_OBJECT_REF_RET, &hRecord));
			return FromHandle<ANType13Record>(hRecord, true);
		}

		ANType13Record AddType13(NInt idc, BdifFPImpressionType imp, const NStringWrapper & src, NUShort hll, NUShort vll,
			BdifScaleUnits slc, NUShort hps, NUShort vps, ANImageCompressionAlgorithm cga, NByte bpx,
			const void * pImageData, NSizeType imageDataLength, NUInt flags = 0)
		{
			HANType13Record hRecord;
			NCheck(ANTemplateAddType13RecordSN(this->GetOwnerHandle(), idc, imp, src.GetHandle(), hll, vll,
				slc, hps, vps, cga, bpx, pImageData, imageDataLength, flags | N_OBJECT_REF_RET, &hRecord));
			return FromHandle<ANType13Record>(hRecord, true);
		}

		ANType13Record AddType13(NInt idc, BdifFPImpressionType imp, const NStringWrapper & src,
			BdifScaleUnits slc, ANImageCompressionAlgorithm cga,
			const ::Neurotec::Images::NImage & image, NUInt flags = 0)
		{
			HANType13Record hRecord;
			NCheck(ANTemplateAddType13RecordFromNImageN(this->GetOwnerHandle(), idc, imp, src.GetHandle(),
				slc, cga, image.GetHandle(), flags | N_OBJECT_REF_RET, &hRecord));
			return FromHandle<ANType13Record>(hRecord, true);
		}

		ANType14Record AddType14(NInt idc, const NStringWrapper & src, NUShort hll, NUShort vll,
			BdifScaleUnits slc, NUShort hps, NUShort vps, ANImageCompressionAlgorithm cga, NByte bpx,
			const ::Neurotec::IO::NBuffer & imageData, NUInt flags = 0)
		{
			HANType14Record hRecord;
			NCheck(ANTemplateAddType14RecordN(this->GetOwnerHandle(), idc, src.GetHandle(), hll, vll,
				slc, hps, vps, cga, bpx, imageData.GetHandle(), flags | N_OBJECT_REF_RET, &hRecord));
			return FromHandle<ANType14Record>(hRecord, true);
		}

		ANType14Record AddType14(NInt idc, const NStringWrapper & src, NUShort hll, NUShort vll,
			BdifScaleUnits slc, NUShort hps, NUShort vps, ANImageCompressionAlgorithm cga, NByte bpx,
			const void * pImageData, NSizeType imageDataLength, NUInt flags = 0)
		{
			HANType14Record hRecord;
			NCheck(ANTemplateAddType14RecordSN(this->GetOwnerHandle(), idc, src.GetHandle(), hll, vll,
				slc, hps, vps, cga, bpx, pImageData, imageDataLength, flags | N_OBJECT_REF_RET, &hRecord));
			return FromHandle<ANType14Record>(hRecord, true);
		}

		ANType14Record AddType14(NInt idc, const NStringWrapper & src,
			BdifScaleUnits slc, ANImageCompressionAlgorithm cga,
			const ::Neurotec::Images::NImage & image, NUInt flags = 0)
		{
			HANType14Record hRecord;
			NCheck(ANTemplateAddType14RecordFromNImageN(this->GetOwnerHandle(), idc, src.GetHandle(),
				slc, cga, image.GetHandle(), flags | N_OBJECT_REF_RET, &hRecord));
			return FromHandle<ANType14Record>(hRecord, true);
		}

		ANType15Record AddType15(NInt idc, const NStringWrapper & src, NUShort hll, NUShort vll,
			BdifScaleUnits slc, NUShort hps, NUShort vps, ANImageCompressionAlgorithm cga, NByte bpx,
			const ::Neurotec::IO::NBuffer & imageData, NUInt flags = 0)
		{
			HANType15Record hRecord;
			NCheck(ANTemplateAddType15RecordN(this->GetOwnerHandle(), idc, src.GetHandle(), hll, vll,
				slc, hps, vps, cga, bpx, imageData.GetHandle(), flags | N_OBJECT_REF_RET, &hRecord));
			return FromHandle<ANType15Record>(hRecord, true);
		}

		ANType15Record AddType15(NInt idc, const NStringWrapper & src, NUShort hll, NUShort vll,
			BdifScaleUnits slc, NUShort hps, NUShort vps, ANImageCompressionAlgorithm cga, NByte bpx,
			const void * pImageData, NSizeType imageDataLength, NUInt flags = 0)
		{
			HANType15Record hRecord;
			NCheck(ANTemplateAddType15RecordSN(this->GetOwnerHandle(), idc, src.GetHandle(), hll, vll,
				slc, hps, vps, cga, bpx, pImageData, imageDataLength, flags | N_OBJECT_REF_RET, &hRecord));
			return FromHandle<ANType15Record>(hRecord, true);
		}

		ANType15Record AddType15(NInt idc, const NStringWrapper & src,
			BdifScaleUnits slc, ANImageCompressionAlgorithm cga,
			const ::Neurotec::Images::NImage & image, NUInt flags = 0)
		{
			HANType15Record hRecord;
			NCheck(ANTemplateAddType15RecordFromNImageN(this->GetOwnerHandle(), idc, src.GetHandle(),
				slc, cga, image.GetHandle(), flags | N_OBJECT_REF_RET, &hRecord));
			return FromHandle<ANType15Record>(hRecord, true);
		}

		ANType16Record AddType16(NInt idc, const NStringWrapper & udi, const NStringWrapper & src, NUShort hll, NUShort vll,
			BdifScaleUnits slc, NUShort hps, NUShort vps, ANImageCompressionAlgorithm cga, NByte bpx, ANImageColorSpace csp,
			const ::Neurotec::IO::NBuffer & imageData, NUInt flags = 0)
		{
			HANType16Record hRecord;
			NCheck(ANTemplateAddType16RecordN(this->GetOwnerHandle(), idc, udi.GetHandle(), src.GetHandle(), hll, vll,
				slc, hps, vps, cga, bpx, csp, imageData.GetHandle(), flags | N_OBJECT_REF_RET, &hRecord));
			return FromHandle<ANType16Record>(hRecord, true);
		}

		ANType16Record AddType16(NInt idc, const NStringWrapper & udi, const NStringWrapper & src, NUShort hll, NUShort vll,
			BdifScaleUnits slc, NUShort hps, NUShort vps, ANImageCompressionAlgorithm cga, NByte bpx, ANImageColorSpace csp,
			const void * pImageData, NSizeType imageDataLength, NUInt flags = 0)
		{
			HANType16Record hRecord;
			NCheck(ANTemplateAddType16RecordUSN(this->GetOwnerHandle(), idc, udi.GetHandle(), src.GetHandle(), hll, vll,
				slc, hps, vps, cga, bpx, csp, pImageData, imageDataLength, flags | N_OBJECT_REF_RET, &hRecord));
			return FromHandle<ANType16Record>(hRecord, true);
		}

		ANType16Record AddType16(NInt idc, const NStringWrapper & udi, const NStringWrapper & src,
			BdifScaleUnits slc, ANImageCompressionAlgorithm cga,
			const ::Neurotec::Images::NImage & image, NUInt flags = 0)
		{
			HANType16Record hRecord;
			NCheck(ANTemplateAddType16RecordFromNImageN(this->GetOwnerHandle(), idc, udi.GetHandle(), src.GetHandle(),
				slc, cga, image.GetHandle(), flags | N_OBJECT_REF_RET, &hRecord));
			return FromHandle<ANType16Record>(hRecord, true);
		}

		ANType17Record AddType17(NInt idc, const NStringWrapper & src, NUShort hll, NUShort vll,
			BdifScaleUnits slc, NUShort hps, NUShort vps, ANImageCompressionAlgorithm cga, NByte bpx, ANImageColorSpace csp,
			const ::Neurotec::IO::NBuffer & imageData, NUInt flags = 0)
		{
			HANType17Record hRecord;
			NCheck(ANTemplateAddType17RecordN(this->GetOwnerHandle(), idc, src.GetHandle(), hll, vll,
				slc, hps, vps, cga, bpx, csp, imageData.GetHandle(), flags | N_OBJECT_REF_RET, &hRecord));
			return FromHandle<ANType17Record>(hRecord, true);
		}

		ANType17Record AddType17(NInt idc, const NStringWrapper & src, NUShort hll, NUShort vll,
			BdifScaleUnits slc, NUShort hps, NUShort vps, ANImageCompressionAlgorithm cga, NByte bpx, ANImageColorSpace csp,
			const void * pImageData, NSizeType imageDataLength, NUInt flags = 0)
		{
			HANType17Record hRecord;
			NCheck(ANTemplateAddType17RecordSN(this->GetOwnerHandle(), idc, src.GetHandle(), hll, vll,
				slc, hps, vps, cga, bpx, csp, pImageData, imageDataLength, flags | N_OBJECT_REF_RET, &hRecord));
			return FromHandle<ANType17Record>(hRecord, true);
		}

		ANType17Record AddType17(NInt idc, const NStringWrapper & src,
			BdifScaleUnits slc, ANImageCompressionAlgorithm cga,
			const ::Neurotec::Images::NImage & image, NUInt flags = 0)
		{
			HANType17Record hRecord;
			NCheck(ANTemplateAddType17RecordFromNImageN(this->GetOwnerHandle(), idc, src.GetHandle(),
				slc, cga, image.GetHandle(), flags | N_OBJECT_REF_RET, &hRecord));
			return FromHandle<ANType17Record>(hRecord, true);
		}

		ANType99Record AddType99(NInt idc, const NStringWrapper & src, NVersion hdv, ANBiometricType bty, NUShort bfo, NUShort bft,
			const ::Neurotec::IO::NBuffer & bdb, NUInt flags = 0)
		{
			HANType99Record hRecord;
			NCheck(ANTemplateAddType99RecordN(this->GetOwnerHandle(), idc, src.GetHandle(), hdv.GetValue(),
				bty, bfo, bft, bdb.GetHandle(), flags | N_OBJECT_REF_RET, &hRecord));
			return FromHandle<ANType99Record>(hRecord, true);
		}

		ANType99Record AddType99(NInt idc, const NStringWrapper & src, NVersion hdv, ANBiometricType bty, NUShort bfo, NUShort bft,
			const void * pBdb, NSizeType bdbLength, NUInt flags = 0)
		{
			HANType99Record hRecord;
			NCheck(ANTemplateAddType99RecordSN(this->GetOwnerHandle(), idc, src.GetHandle(), hdv.GetValue(),
				bty, bfo, bft, pBdb, bdbLength, flags | N_OBJECT_REF_RET, &hRecord));
			return FromHandle<ANType99Record>(hRecord, true);
		}
	};

private:
	static HANTemplate Create(NUInt flags)
	{
		HANTemplate handle;
		NCheck(ANTemplateCreateWithMinimalValidation(flags, &handle));
		return handle;
	}

	static HANTemplate Create(const NStringWrapper & tot, const NStringWrapper & dai, const NStringWrapper & ori, const NStringWrapper & tcn, NUInt flags)
	{
		HANTemplate handle;
		NCheck(ANTemplateCreateN(tot.GetHandle(), dai.GetHandle(), ori.GetHandle(), tcn.GetHandle(), flags, &handle));
		return handle;
	}

	static HANTemplate Create(const NStringWrapper & fileName, ANValidationLevel validationLevel, NUInt flags)
	{
		HANTemplate handle;
		NCheck(ANTemplateCreateFromFileN(fileName.GetHandle(), validationLevel, flags, &handle));
		return handle;
	}

	static HANTemplate Create(const ::Neurotec::IO::NBuffer & buffer, ANValidationLevel validationLevel, NUInt flags, NSizeType * pSize)
	{
		HANTemplate handle;
		NCheck(ANTemplateCreateFromMemoryN(buffer.GetHandle(), validationLevel, flags, pSize, &handle));
		return handle;
	}

	static HANTemplate Create(const void * pBuffer, NSizeType bufferSize, ANValidationLevel validationLevel, NUInt flags, NSizeType * pSize)
	{
		HANTemplate handle;
		NCheck(ANTemplateCreateFromMemoryEx(pBuffer, bufferSize, validationLevel, flags, pSize, &handle));
		return handle;
	}

	static HANTemplate Create(const ::Neurotec::IO::NStream & stream, ANValidationLevel validationLevel, NUInt flags)
	{
		HANTemplate handle;
		NCheck(ANTemplateCreateFromStream(stream.GetHandle(), validationLevel, flags, &handle));
		return handle;
	}

	static HANTemplate Create(const NStringWrapper & tot, const NStringWrapper & dai, const NStringWrapper & ori, const NStringWrapper & tcn,
		bool type9RecordFmt, const NTemplate & nTemplate, NUInt flags)
	{
		HANTemplate handle;
		NCheck(ANTemplateCreateFromNTemplateN(tot.GetHandle(), dai.GetHandle(), ori.GetHandle(), tcn.GetHandle(), type9RecordFmt ? NTrue : NFalse, nTemplate.GetHandle(), flags, &handle));
		return handle;
	}

public:
	static NType ANValidationLevelNativeTypeOf()
	{
		return NObject::GetObject<NType>(N_TYPE_OF(ANValidationLevel), true);
	}

	static NInt GetVersions(NVersion * arValue, NInt valueLength)
	{
		return NCheck(ANTemplateGetVersionsEx(reinterpret_cast<NVersion_ *>(arValue), valueLength));
	}

	static NArrayWrapper<NVersion> GetVersions()
	{
		NInt count = GetVersions(NULL, 0);
		NArrayWrapper<NVersion> values(count);
		count = GetVersions(values.GetPtr(), count);
		values.SetCount(count);
		return values;
	}

	static bool IsVersionSupported(const NVersion & version)
	{
		NBool value;
		NCheck(ANTemplateIsVersionSupported(version.GetValue(), &value));
		return value != 0;
	}

	static NString GetVersionName(const NVersion & version)
	{
		HNString hValue;
		NCheck(ANTemplateGetVersionNameN(version.GetValue(), &hValue));
		return NString(hValue, true);
	}

	explicit ANTemplate(NUInt flags = 0)
		: NObject(Create(flags), true)
	{
		Reset();
	}

	ANTemplate(const NStringWrapper & tot, const NStringWrapper & dai, const NStringWrapper & ori, const NStringWrapper & tcn, NUInt flags = 0)
		: NObject(Create(tot, dai, ori, tcn, flags), true)
	{
		Reset();
	}

	ANTemplate(const NStringWrapper & fileName, ANValidationLevel validationLevel, NUInt flags = 0)
		: NObject(Create(fileName, validationLevel, flags), true)
	{
		Reset();
	}

	ANTemplate(const ::Neurotec::IO::NBuffer & buffer, ANValidationLevel validationLevel, NUInt flags = 0, NSizeType * pSize = NULL)
		: NObject(Create(buffer, validationLevel, flags, pSize), true)
	{
		Reset();
	}

	ANTemplate(const void * pBuffer, NSizeType bufferSize, ANValidationLevel validationLevel, NUInt flags = 0, NSizeType * pSize = NULL)
		: NObject(Create(pBuffer, bufferSize, validationLevel, flags, pSize), true)
	{
		Reset();
	}

	ANTemplate(const ::Neurotec::IO::NStream & stream, ANValidationLevel validationLevel, NUInt flags = 0)
		: NObject(Create(stream, validationLevel, flags), true)
	{
		Reset();
	}

	ANTemplate(const NStringWrapper & tot, const NStringWrapper & dai, const NStringWrapper & ori, const NStringWrapper & tcn,
		bool type9RecordFmt, const NTemplate & nTemplate, NUInt flags = 0)
		: NObject(Create(tot, dai, ori, tcn, type9RecordFmt, nTemplate, flags), true)
	{
		Reset();
	}

	void Save(const NStringWrapper & fileName, NUInt flags = 0) const
	{
		NCheck(ANTemplateSaveToFileN(GetHandle(), fileName.GetHandle(), flags));
	}

	NTemplate ToNTemplate(NUInt flags = 0) const
	{
		HNTemplate hNTemplate;
		NCheck(ANTemplateToNTemplate(GetHandle(), flags, &hNTemplate));
		return FromHandle<NTemplate>(hNTemplate);
	}

	ANValidationLevel GetValidationLevel() const
	{
		ANValidationLevel value;
		NCheck(ANTemplateGetValidationLevel(GetHandle(), &value));
		return value;
	}

	NVersion GetVersion() const
	{
		NVersion_ value;
		NCheck(ANTemplateGetVersion(GetHandle(), &value));
		return NVersion(value);
	}

	void SetVersion(const NVersion & value)
	{
		NCheck(ANTemplateSetVersion(GetHandle(), value.GetValue()));
	}

	RecordCollection GetRecords()
	{
		return RecordCollection(*this);
	}

	const RecordCollection GetRecords() const
	{
		return RecordCollection(*this);
	}
};

}}}

#endif // !AN_TEMPLATE_HPP_INCLUDED
