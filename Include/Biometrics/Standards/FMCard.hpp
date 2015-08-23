#ifndef FM_CARD_HPP_INCLUDED
#define FM_CARD_HPP_INCLUDED

#include <Biometrics/NFRecord.hpp>
#include <SmartCards/BerTag.hpp>
namespace Neurotec { namespace Biometrics { namespace Standards
{
#include <Biometrics/Standards/FMCard.h>
}}}

N_DEFINE_ENUM_TYPE_TRAITS(Neurotec::Biometrics::Standards, FmcMinutiaOrder)
N_DEFINE_ENUM_TYPE_TRAITS(Neurotec::Biometrics::Standards, FmcFeatureHandling)

namespace Neurotec { namespace Biometrics { namespace Standards
{

#undef FMC_DEFAULT_MIN_ENROLL_MC
#undef FMC_DEFAULT_MIN_VERIFY_MC
#undef FMC_DEFAULT_MAX_ENROLL_MC
#undef FMC_DEFAULT_MAX_VERIFY_MC

#undef FMC_BDT_TAG_FINGER_MINUTIAE_DATA
#undef FMC_BDT_TAG_RIDGE_COUNT_DATA
#undef FMC_BDT_TAG_CORE_POINT_DATA
#undef FMC_BDT_TAG_DELTA_POINT_DATA
#undef FMC_BDT_TAG_CELL_QUALITY_DATA

#undef FMC_BIT_BHT_BAPT_TAG_NUMBER_OF_MINUTIAE
#undef FMC_BIT_BHT_BAPT_TAG_MINUTIAE_ORDER
#undef FMC_BIT_BHT_BAPT_TAG_FEATURE_HANDLING_INDICATOR

const NInt FMC_DEFAULT_MIN_ENROLL_MC = 16;
const NInt FMC_DEFAULT_MIN_VERIFY_MC = 12;
const NInt FMC_DEFAULT_MAX_ENROLL_MC = 60;
const NInt FMC_DEFAULT_MAX_VERIFY_MC = 60;

const ::Neurotec::SmartCards::BerTag FMC_BDT_TAG_FINGER_MINUTIAE_DATA(0x90);
const ::Neurotec::SmartCards::BerTag FMC_BDT_TAG_RIDGE_COUNT_DATA(0x91);
const ::Neurotec::SmartCards::BerTag FMC_BDT_TAG_CORE_POINT_DATA(0x92);
const ::Neurotec::SmartCards::BerTag FMC_BDT_TAG_DELTA_POINT_DATA(0x93);
const ::Neurotec::SmartCards::BerTag FMC_BDT_TAG_CELL_QUALITY_DATA(0x94);

const ::Neurotec::SmartCards::BerTag FMC_BIT_BHT_BAPT_TAG_NUMBER_OF_MINUTIAE(0x81);
const ::Neurotec::SmartCards::BerTag FMC_BIT_BHT_BAPT_TAG_MINUTIAE_ORDER(0x82);
const ::Neurotec::SmartCards::BerTag FMC_BIT_BHT_BAPT_TAG_FEATURE_HANDLING_INDICATOR(0x83);

class FMCard
{
	N_DECLARE_STATIC_OBJECT_CLASS(FMCard)

public:
	static NType FmcMinutiaOrderNativeTypeOf()
	{
		return NObject::GetObject<NType>(N_TYPE_OF(FmcMinutiaOrder), true);
	}

	static NType FmcFeatureHandlingNativeTypeOf()
	{
		return NObject::GetObject<NType>(N_TYPE_OF(FmcFeatureHandling), true);
	}

	static NSizeType WriteNormalSizeMinutiae(const NFRecord & nfRecord, FmcMinutiaOrder order, const ::Neurotec::IO::NBuffer & buffer, NUInt flags = 0)
	{
		NSizeType size;
		NCheck(FMCardWriteNormalSizeMinutiaeN(nfRecord.GetHandle(), order, buffer.GetHandle(), flags, &size));
		return size;
	}

	static NSizeType WriteNormalSizeMinutiae(const NFRecord & nfRecord, FmcMinutiaOrder order, void * pBuffer, NSizeType bufferSize, NUInt flags = 0)
	{
		NSizeType size;
		NCheck(FMCardWriteNormalSizeMinutiae(nfRecord.GetHandle(), order, pBuffer, bufferSize, flags, &size));
		return size;
	}

	static const ::Neurotec::IO::NBuffer WriteNormalSizeMinutiae(const NFRecord & nfRecord, FmcMinutiaOrder order, NUInt flags = 0)
	{
		HNBuffer hBuffer;
		NCheck(FMCardWriteNormalSizeMinutiaeToMemoryN(nfRecord.GetHandle(), order, flags, &hBuffer));
		return NObject::FromHandle< ::Neurotec::IO::NBuffer>(hBuffer);
	}

	static NSizeType WriteCompactSizeMinutiae(const NFRecord & nfRecord, FmcMinutiaOrder order, const ::Neurotec::IO::NBuffer & buffer, NUInt flags = 0)
	{
		NSizeType size;
		NCheck(FMCardWriteCompactSizeMinutiaeN(nfRecord.GetHandle(), order, buffer.GetHandle(), flags, &size));
		return size;
	}

	static NSizeType WriteCompactSizeMinutiae(const NFRecord & nfRecord, FmcMinutiaOrder order, void * pBuffer, NSizeType bufferSize, NUInt flags = 0)
	{
		NSizeType size;
		NCheck(FMCardWriteCompactSizeMinutiae(nfRecord.GetHandle(), order, pBuffer, bufferSize, flags, &size));
		return size;
	}

	static ::Neurotec::IO::NBuffer WriteCompactSizeMinutiae(const NFRecord & nfRecord, FmcMinutiaOrder order, NUInt flags = 0)
	{
		HNBuffer hBuffer;
		NCheck(FMCardWriteCompactSizeMinutiaeToMemoryN(nfRecord.GetHandle(), order, flags, &hBuffer));
		return NObject::FromHandle< ::Neurotec::IO::NBuffer>(hBuffer);
	}

	static NFRecord ReadNormalSizeMinutiae(const ::Neurotec::IO::NBuffer & buffer, FmcMinutiaOrder order, NUInt flags = 0, NSizeType * pSize = NULL)
	{
		HNFRecord hNFRecord;
		NCheck(FMCardReadNormalSizeMinutiaeN(buffer.GetHandle(), order, flags, pSize, &hNFRecord));
		return NObject::FromHandle<NFRecord>(hNFRecord);
	}

	static NFRecord ReadNormalSizeMinutiae(const void * pBuffer, NSizeType bufferSize, FmcMinutiaOrder order, NUInt flags = 0, NSizeType * pSize = NULL)
	{
		HNFRecord hNFRecord;
		NCheck(FMCardReadNormalSizeMinutiaeEx(pBuffer, bufferSize, order, flags, pSize, &hNFRecord));
		return NObject::FromHandle<NFRecord>(hNFRecord);
	}

	static NFRecord ReadCompactSizeMinutiae(const ::Neurotec::IO::NBuffer & buffer, FmcMinutiaOrder order, NUInt flags = 0, NSizeType * pSize = NULL)
	{
		HNFRecord hNFRecord;
		NCheck(FMCardReadCompactSizeMinutiaeN(buffer.GetHandle(), order, flags, pSize, &hNFRecord));
		return NObject::FromHandle<NFRecord>(hNFRecord);
	}

	static NFRecord ReadCompactSizeMinutiae(const void * pBuffer, NSizeType bufferSize, FmcMinutiaOrder order, NUInt flags = 0, NSizeType * pSize = NULL)
	{
		HNFRecord hNFRecord;
		NCheck(FMCardReadCompactSizeMinutiaeEx(pBuffer, bufferSize, order, flags, pSize, &hNFRecord));
		return NObject::FromHandle<NFRecord>(hNFRecord);
	}
};

}}}

#endif // !FM_CARD_HPP_INCLUDED
