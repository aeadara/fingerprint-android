#ifndef APDU_INSTRUCTION_HPP_INCLUDED
#define APDU_INSTRUCTION_HPP_INCLUDED

#include <Core/NTypes.hpp>
namespace Neurotec { namespace SmartCards
{
#include <SmartCards/ApduInstruction.h>
}}

namespace Neurotec { namespace SmartCards
{

#undef APDU_INS_DEACTIVATE_FILE
#undef APDU_INS_ERASE_RECORD
#undef APDU_INS_ERASE_BINARY
#undef APDU_INS_ERASE_BINARY_BER_TLV
#undef APDU_INS_PERFORM_SCQL_OPERATION
#undef APDU_INS_PERFORM_TRANSACTION_OPERATION
#undef APDU_INS_PERFORM_USER_OPERATION
#undef APDU_INS_VERIFY
#undef APDU_INS_VERIFY_BER_TLV
#undef APDU_INS_MANAGE_SECURITY_ENVIRONMENT
#undef APDU_INS_CHANGE_REFERENCE_DATA
#undef APDU_INS_DISABLE_VERIFICATION_REQUIREMENT
#undef APDU_INS_ENABLE_VERIFICATION_REQUIREMENT
#undef APDU_INS_PERFORM_SECURITY_OPERATION
#undef APDU_INS_RESET_RETRY_COUNTER
#undef APDU_INS_ACTIVATE_FILE
#undef APDU_INS_GENERATE_ASYMMETRIC_KEY_PAIR
#undef APDU_INS_MANAGE_CHANNEL
#undef APDU_INS_EXTERNAL_AUTHENTICATE
#undef APDU_INS_GET_CHALLENGE
#undef APDU_INS_GENERAL_AUTHENTICATE
#undef APDU_INS_GENERAL_AUTHENTICATE_BER_TLV
#undef APDU_INS_INTERNAL_AUTHENTICATE
#undef APDU_INS_SEARCH_BINARY
#undef APDU_INS_SEARCH_BINARY_BER_TLV
#undef APDU_INS_SEARCH_RECORD
#undef APDU_INS_SELECT
#undef APDU_INS_READ_BINARY
#undef APDU_INS_READ_BINARY_BER_TLV
#undef APDU_INS_READ_RECORD
#undef APDU_INS_READ_RECORD_BER_TLV
#undef APDU_INS_GET_RESPONSE
#undef APDU_INS_ENVELOPE
#undef APDU_INS_ENVELOPE_BER_TLV
#undef APDU_INS_GET_DATA
#undef APDU_INS_GET_DATA_BER_TLV
#undef APDU_INS_WRITE_BINARY
#undef APDU_INS_WRITE_BINARY_BER_TLV
#undef APDU_INS_WRITE_RECORD
#undef APDU_INS_UPDATE_BINARY
#undef APDU_INS_UPDATE_BINARY_BER_TLV
#undef APDU_INS_PUT_DATA
#undef APDU_INS_PUT_DATA_BER_TLV
#undef APDU_INS_UPDATE_RECORD
#undef APDU_INS_UPDATE_RECORD_BER_TLV
#undef APDU_INS_CREATE_FILE
#undef APDU_INS_APPEND_RECORD
#undef APDU_INS_DELETE_FILE
#undef APDU_INS_TERMINATE_DF
#undef APDU_INS_TERMINATE_EF
#undef APDU_INS_TERMINATE_CARD_USAGE

class ApduInstruction
{
	N_DECLARE_BASIC_CLASS(ApduInstruction)

public:
	bool IsValid() const
	{
		return ApduInstructionIsValid(value) != 0;
	}

	bool IsDataBerTlvEncoded() const
	{
		return ApduInstructionIsDataBerTlvEncoded(value) != 0;
	}

	NString ToString(const NStringWrapper & format = NString()) const
	{
		HNString hValue;
		NCheck(ApduInstructionToStringN(value, format.GetHandle(), &hValue));
		return NString(hValue, true);
	}
};

const ApduInstruction APDU_INS_DEACTIVATE_FILE(0x04);
const ApduInstruction APDU_INS_ERASE_RECORD(0x0C);
const ApduInstruction APDU_INS_ERASE_BINARY(0x0E);
const ApduInstruction APDU_INS_ERASE_BINARY_BER_TLV(0x0F);
const ApduInstruction APDU_INS_PERFORM_SCQL_OPERATION(0x10);
const ApduInstruction APDU_INS_PERFORM_TRANSACTION_OPERATION(0x12);
const ApduInstruction APDU_INS_PERFORM_USER_OPERATION(0x14);
const ApduInstruction APDU_INS_VERIFY(0x20);
const ApduInstruction APDU_INS_VERIFY_BER_TLV(0x21);
const ApduInstruction APDU_INS_MANAGE_SECURITY_ENVIRONMENT(0x22);
const ApduInstruction APDU_INS_CHANGE_REFERENCE_DATA(0x24);
const ApduInstruction APDU_INS_DISABLE_VERIFICATION_REQUIREMENT(0x26);
const ApduInstruction APDU_INS_ENABLE_VERIFICATION_REQUIREMENT(0x28);
const ApduInstruction APDU_INS_PERFORM_SECURITY_OPERATION(0x2A);
const ApduInstruction APDU_INS_RESET_RETRY_COUNTER(0x2C);
const ApduInstruction APDU_INS_ACTIVATE_FILE(0x44);
const ApduInstruction APDU_INS_GENERATE_ASYMMETRIC_KEY_PAIR(0x46);
const ApduInstruction APDU_INS_MANAGE_CHANNEL(0x70);
const ApduInstruction APDU_INS_EXTERNAL_AUTHENTICATE(0x82);
const ApduInstruction APDU_INS_GET_CHALLENGE(0x84);
const ApduInstruction APDU_INS_GENERAL_AUTHENTICATE(0x86);
const ApduInstruction APDU_INS_GENERAL_AUTHENTICATE_BER_TLV(0x87);
const ApduInstruction APDU_INS_INTERNAL_AUTHENTICATE(0x88);
const ApduInstruction APDU_INS_SEARCH_BINARY(0xA0);
const ApduInstruction APDU_INS_SEARCH_BINARY_BER_TLV(0xA1);
const ApduInstruction APDU_INS_SEARCH_RECORD(0xA2);
const ApduInstruction APDU_INS_SELECT(0xA4);
const ApduInstruction APDU_INS_READ_BINARY(0xB0);
const ApduInstruction APDU_INS_READ_BINARY_BER_TLV(0xB1);
const ApduInstruction APDU_INS_READ_RECORD(0xB2);
const ApduInstruction APDU_INS_READ_RECORD_BER_TLV(0xB3);
const ApduInstruction APDU_INS_GET_RESPONSE(0xC0);
const ApduInstruction APDU_INS_ENVELOPE(0xC2);
const ApduInstruction APDU_INS_ENVELOPE_BER_TLV(0xC3);
const ApduInstruction APDU_INS_GET_DATA(0xCA);
const ApduInstruction APDU_INS_GET_DATA_BER_TLV(0xCB);
const ApduInstruction APDU_INS_WRITE_BINARY(0xD0);
const ApduInstruction APDU_INS_WRITE_BINARY_BER_TLV(0xD1);
const ApduInstruction APDU_INS_WRITE_RECORD(0xD2);
const ApduInstruction APDU_INS_UPDATE_BINARY(0xD6);
const ApduInstruction APDU_INS_UPDATE_BINARY_BER_TLV(0xD7);
const ApduInstruction APDU_INS_PUT_DATA(0xDA);
const ApduInstruction APDU_INS_PUT_DATA_BER_TLV(0xDB);
const ApduInstruction APDU_INS_UPDATE_RECORD(0xDC);
const ApduInstruction APDU_INS_UPDATE_RECORD_BER_TLV(0xDD);
const ApduInstruction APDU_INS_CREATE_FILE(0xE0);
const ApduInstruction APDU_INS_APPEND_RECORD(0xE2);
const ApduInstruction APDU_INS_DELETE_FILE(0xE4);
const ApduInstruction APDU_INS_TERMINATE_DF(0xE6);
const ApduInstruction APDU_INS_TERMINATE_EF(0xE8);
const ApduInstruction APDU_INS_TERMINATE_CARD_USAGE(0xFE);

}}

#endif // !APDU_INSTRUCTION_HPP_INCLUDED
