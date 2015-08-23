#ifndef APDU_STATUS_HPP_INCLUDED
#define APDU_STATUS_HPP_INCLUDED

#include <Core/NTypes.hpp>
namespace Neurotec { namespace SmartCards
{
#include <SmartCards/ApduStatus.h>
}}

namespace Neurotec { namespace SmartCards
{

#undef APDU_STATUS_NO_QUALIFICATION
#undef APDU_STATUS_PROPRIETARY_9XXX

#undef APDU_STATUS_DATA_STILL_AVAILABLE_XX

#undef APDU_STATUS_WARNING_SONVMU_XX
#undef APDU_STATUS_WARNING_SONVMU_NO_INFORMATION
#undef APDU_STATUS_WARNING_SONVMU_TRIGGERING_BY_THE_CARD_START
#undef APDU_STATUS_WARNING_SONVMU_TRIGGERING_BY_THE_CARD_END
#undef APDU_STATUS_WARNING_SONVMU_PART_OF_RETURNED_DATA_MAY_BE_CORRUPTED
#undef APDU_STATUS_WARNING_SONVMU_END_OF_FILE_OR_RECORD_BEFORE_READING_NE_BYTES
#undef APDU_STATUS_WARNING_SONVMU_SELECTED_FILE_DEACTIVATED
#undef APDU_STATUS_WARNING_SONVMU_FILE_CONTROL_INFORMATION_INCORRECTY_FORMATTED
#undef APDU_STATUS_WARNING_SONVMU_SELECTED_FILE_IN_TERMINATION_STATE
#undef APDU_STATUS_WARNING_SONVMU_NO_INPUT_DATA_AVAILABLE_FROM_A_SENSOR_ON_THE_CARD

#undef APDU_STATUS_WARNING_SONVMC_XX
#undef APDU_STATUS_WARNING_SONVMC_NO_INFORMATION
#undef APDU_STATUS_WARNING_SONVMC_FILE_FILLED_UP_BY_THE_LAST_WRITE
#undef APDU_STATUS_WARNING_SONVMC_COUNTER_X

#undef APDU_STATUS_ERROR_SONVMU_XX
#undef APDU_STATUS_ERROR_SONVMU_EXECUTION_ERROR
#undef APDU_STATUS_ERROR_SONVMU_IMMEDIATE_RESPONSE_REQUIRED_BY_THE_CARD
#undef APDU_STATUS_ERROR_SONVMU_TRIGGERING_BY_THE_CARD_START
#undef APDU_STATUS_ERROR_SONVMU_TRIGGERING_BY_THE_CARD_END

#undef APDU_STATUS_ERROR_SONVMC_XX
#undef APDU_STATUS_ERROR_SONVMC_NO_INFORMATION
#undef APDU_STATUS_ERROR_SONVMC_MEMORY_FAILURE

#undef APDU_STATUS_ERROR_SECURITY_XX

#undef APDU_STATUS_ERROR_WRONG_LENGTH
#undef APDU_STATUS_ERROR_PROPRIETARY_67XX

#undef APDU_STATUS_ERROR_FICNS_XX
#undef APDU_STATUS_ERROR_FICNS_NO_INFORMATION
#undef APDU_STATUS_ERROR_FICNS_LOGICAL_CHANNEL_NOT_SUPPORTED
#undef APDU_STATUS_ERROR_FICNS_SECURE_MESSAGING_NOT_SUPPORTED
#undef APDU_STATUS_ERROR_FICNS_LAST_COMMAND_OF_THE_CHAIN_EXPECTED
#undef APDU_STATUS_ERROR_FICNS_COMMAND_CHAINING_NOT_SUPPORTED

#undef APDU_STATUS_ERROR_CNA_XX
#undef APDU_STATUS_ERROR_CNA_NO_INFORMATION
#undef APDU_STATUS_ERROR_CNA_COMMAND_INCOMPATIBLE_WITH_FILE_STRUCTURE
#undef APDU_STATUS_ERROR_CNA_SECURITY_STATUS_NOT_SATISFIED
#undef APDU_STATUS_ERROR_CNA_AUTHENTICATION_METHOD_BLOCKED
#undef APDU_STATUS_ERROR_CNA_REFERENCE_DATA_NOT_USABLE
#undef APDU_STATUS_ERROR_CNA_CONDITIONS_OF_USE_NOT_SATISFIED
#undef APDU_STATUS_ERROR_CNA_COMMAND_NOT_ALLOWED
#undef APDU_STATUS_ERROR_CNA_EXPECTED_SECURE_MESSAGING_DATA_OBJECTS_MISSING
#undef APDU_STATUS_ERROR_CNA_INCORRECT_SECURE_MESSAGING_DATA_OBJECTS

#undef APDU_STATUS_ERROR_WP1P2_XX
#undef APDU_STATUS_ERROR_WP1P2_NO_INFORMATION
#undef APDU_STATUS_ERROR_WP1P2_INCORRECT_PARAMETERS_IN_THE_COMMAND_DATA_FIELD
#undef APDU_STATUS_ERROR_WP1P2_FUNCTION_NOT_SUPPORTED
#undef APDU_STATUS_ERROR_WP1P2_FILE_OR_APPLICATION_NOT_FOUND
#undef APDU_STATUS_ERROR_WP1P2_RECORD_NOT_FOUND
#undef APDU_STATUS_ERROR_WP1P2_NOT_ENOUGH_MEMORY_SPACE_IN_THE_FILE
#undef APDU_STATUS_ERROR_WP1P2_NC_INCONSISTENT_WITH_TLV_STRUCTURE
#undef APDU_STATUS_ERROR_WP1P2_INCORRECT_PARAMETERS_P1P2
#undef APDU_STATUS_ERROR_WP1P2_NC_INCONSISTENT_WITH_PARAMETERS_P1P2
#undef APDU_STATUS_ERROR_WP1P2_REFERENCED_DATA_OR_REFERENCE_DATA_NOT_FOUND
#undef APDU_STATUS_ERROR_WP1P2_FILE_ALREADY_EXISTS
#undef APDU_STATUS_ERROR_WP1P2_DF_NAME_ALREADY_EXISTS

#undef APDU_STATUS_ERROR_WP1P2_NO_QUALIFICATION
#undef APDU_STATUS_ERROR_PROPRIETARY_6BXX

#undef APDU_STATUS_ERROR_WRONG_LE_XX

#undef APDU_STATUS_ERROR_INSTRUCTION_NOT_SUPPORTED_OR_INVALID
#undef APDU_STATUS_ERROR_PROPRIETARY_6DXX

#undef APDU_STATUS_ERROR_CLASS_NOT_SUPPORTED
#undef APDU_STATUS_ERROR_PROPRIETARY_6EXX

#undef APDU_STATUS_ERROR_NO_PRECISE_DIAGNOSIS
#undef APDU_STATUS_ERROR_PROPRIETARY_6FXX

class ApduStatus
{
	N_DECLARE_BASIC_CLASS(ApduStatus)

public:
	ApduStatus(NByte sw1, NByte sw2)
		: value((ApduStatus_)((sw1 << 8) | sw2))
	{
	}

	bool IsValid() const
	{
		return ApduStatusIsValid(value) != 0;
	}

	bool IsInterindustry() const
	{
		return ApduStatusIsInterindustry(value) != 0;
	}

	bool IsProprietary() const
	{
		return ApduStatusIsProprietary(value) != 0;
	}

	bool IsProcessComplete() const
	{
		return ApduStatusIsProcessComplete(value) != 0;
	}

	bool IsProcessAborted() const
	{
		return ApduStatusIsProcessAborted(value) != 0;
	}

	bool IsNormalProcessing() const
	{
		return ApduStatusIsNormalProcessing(value) != 0;
	}

	bool IsWarningProcessing() const
	{
		return ApduStatusIsWarningProcessing(value) != 0;
	}

	bool IsExecutionError() const
	{
		return ApduStatusIsExecutionError(value) != 0;
	}

	bool IsCheckingError() const
	{
		return ApduStatusIsCheckingError(value) != 0;
	}

	bool IsStateOfNonVolatileMemoryChanged() const
	{
		return ApduStatusIsStateOfNonVolatileMemoryChanged(value) != 0;
	}

	bool IsStateOfNonVolatileMemoryUnchanged() const
	{
		return ApduStatusIsStateOfNonVolatileMemoryUnchanged(value) != 0;
	}

	NInt GetDataStillAvailableValue() const
	{
		return ApduStatusGetDataStillAvailableValue(value);
	}

	NInt GetWarningSonvmuTriggeringByTheCardValue() const
	{
		return ApduStatusGetWarningSonvmuTriggeringByTheCardValue(value);
	}

	NInt GetWarningSonvmcCounterValue() const
	{
		return ApduStatusGetWarningSonvmcCounterValue(value);
	}

	NInt GetErrorSonvmuTriggeringByTheCardValue() const
	{
		return ApduStatusGetErrorSonvmuTriggeringByTheCardValue(value);
	}

	NInt GetErrorWrongLeValue() const
	{
		return ApduStatusGetErrorWrongLeValue(value);
	}

	NByte GetSW1() const
	{
		return (NByte)(value >> 8);
	}

	NByte GetSW2() const
	{
		return (NByte)value;
	}

	bool IsProprietary9XXX() const
	{
		return ApduStatusIsProprietary9XXX(value) != 0;
	}

	bool IsDataStillAvailable() const
	{
		return ApduStatusIsDataStillAvailable(value) != 0;
	}

	bool IsWarningSonvmu() const
	{
		return ApduStatusIsWarningSonvmu(value) != 0;
	}

	bool IsWarningSonvmuTriggeringByTheCard() const
	{
		return ApduStatusIsWarningSonvmuTriggeringByTheCard(value) != 0;
	}

	bool IsWarningSonvmc() const
	{
		return ApduStatusIsWarningSonvmc(value) != 0;
	}

	bool IsWarningSonvmcCounter() const
	{
		return ApduStatusIsWarningSonvmcCounter(value) != 0;
	}

	bool IsErrorSonvmu() const
	{
		return ApduStatusIsErrorSonvmu(value) != 0;
	}

	bool IsErrorSonvmuTriggeringByTheCard() const
	{
		return ApduStatusIsErrorSonvmuTriggeringByTheCard(value) != 0;
	}

	bool IsErrorSonvmc() const
	{
		return ApduStatusIsErrorSonvmc(value) != 0;
	}

	bool IsErrorSecurity() const
	{
		return ApduStatusIsErrorSecurity(value) != 0;
	}

	bool IsErrorProprietary67XX() const
	{
		return ApduStatusIsErrorProprietary67XX(value) != 0;
	}

	bool IsErrorFicns() const
	{
		return ApduStatusIsErrorFicns(value) != 0;
	}

	bool IsErrorCna() const
	{
		return ApduStatusIsErrorCna(value) != 0;
	}

	bool IsErrorWP1P2() const
	{
		return ApduStatusIsErrorWP1P2(value) != 0;
	}

	bool IsErrorProprietary6BXX() const
	{
		return ApduStatusIsErrorProprietary6BXX(value) != 0;
	}

	bool IsErrorWrongLe() const
	{
		return ApduStatusIsErrorWrongLe(value) != 0;
	}

	bool IsErrorProprietary6DXX() const
	{
		return ApduStatusIsErrorProprietary6DXX(value) != 0;
	}

	bool IsErrorProprietary6EXX() const
	{
		return ApduStatusIsErrorProprietary6EXX(value) != 0;
	}

	bool IsErrorProprietary6FXX() const
	{
		return ApduStatusIsErrorProprietary6FXX(value) != 0;
	}

	NString ToString(const NStringWrapper & format = NString()) const
	{
		HNString hValue;
		NCheck(ApduStatusToStringN(value, format.GetHandle(), &hValue));
		return NString(hValue, true);
	}
};

const ApduStatus APDU_STATUS_NO_QUALIFICATION(0x9000);
const ApduStatus APDU_STATUS_PROPRIETARY_9XXX(0x9000);

const ApduStatus APDU_STATUS_DATA_STILL_AVAILABLE_XX(0x6100);

const ApduStatus APDU_STATUS_WARNING_SONVMU_XX(0x6200);
const ApduStatus APDU_STATUS_WARNING_SONVMU_NO_INFORMATION(0x6200);
const ApduStatus APDU_STATUS_WARNING_SONVMU_TRIGGERING_BY_THE_CARD_START(0x6202);
const ApduStatus APDU_STATUS_WARNING_SONVMU_TRIGGERING_BY_THE_CARD_END(0x6280);
const ApduStatus APDU_STATUS_WARNING_SONVMU_PART_OF_RETURNED_DATA_MAY_BE_CORRUPTED(0x6281);
const ApduStatus APDU_STATUS_WARNING_SONVMU_END_OF_FILE_OR_RECORD_BEFORE_READING_NE_BYTES(0x6282);
const ApduStatus APDU_STATUS_WARNING_SONVMU_SELECTED_FILE_DEACTIVATED(0x6283);
const ApduStatus APDU_STATUS_WARNING_SONVMU_FILE_CONTROL_INFORMATION_INCORRECTY_FORMATTED(0x6284);
const ApduStatus APDU_STATUS_WARNING_SONVMU_SELECTED_FILE_IN_TERMINATION_STATE(0x6285);
const ApduStatus APDU_STATUS_WARNING_SONVMU_NO_INPUT_DATA_AVAILABLE_FROM_A_SENSOR_ON_THE_CARD(0x6286);

const ApduStatus APDU_STATUS_WARNING_SONVMC_XX(0x6300);
const ApduStatus APDU_STATUS_WARNING_SONVMC_NO_INFORMATION(0x6300);
const ApduStatus APDU_STATUS_WARNING_SONVMC_FILE_FILLED_UP_BY_THE_LAST_WRITE(0x6381);
const ApduStatus APDU_STATUS_WARNING_SONVMC_COUNTER_X(0x63C0);

const ApduStatus APDU_STATUS_ERROR_SONVMU_XX(0x6400);
const ApduStatus APDU_STATUS_ERROR_SONVMU_EXECUTION_ERROR(0x6400);
const ApduStatus APDU_STATUS_ERROR_SONVMU_IMMEDIATE_RESPONSE_REQUIRED_BY_THE_CARD(0x6401);
const ApduStatus APDU_STATUS_ERROR_SONVMU_TRIGGERING_BY_THE_CARD_START(0x6402);
const ApduStatus APDU_STATUS_ERROR_SONVMU_TRIGGERING_BY_THE_CARD_END(0x6480);

const ApduStatus APDU_STATUS_ERROR_SONVMC_XX(0x6500);
const ApduStatus APDU_STATUS_ERROR_SONVMC_NO_INFORMATION(0x6500);
const ApduStatus APDU_STATUS_ERROR_SONVMC_MEMORY_FAILURE(0x6581);

const ApduStatus APDU_STATUS_ERROR_SECURITY_XX(0x6600);

const ApduStatus APDU_STATUS_ERROR_WRONG_LENGTH(0x6700);
const ApduStatus APDU_STATUS_ERROR_PROPRIETARY_67XX(0x6700);

const ApduStatus APDU_STATUS_ERROR_FICNS_XX(0x6800);
const ApduStatus APDU_STATUS_ERROR_FICNS_NO_INFORMATION(0x6800);
const ApduStatus APDU_STATUS_ERROR_FICNS_LOGICAL_CHANNEL_NOT_SUPPORTED(0x6881);
const ApduStatus APDU_STATUS_ERROR_FICNS_SECURE_MESSAGING_NOT_SUPPORTED(0x6882);
const ApduStatus APDU_STATUS_ERROR_FICNS_LAST_COMMAND_OF_THE_CHAIN_EXPECTED(0x6883);
const ApduStatus APDU_STATUS_ERROR_FICNS_COMMAND_CHAINING_NOT_SUPPORTED(0x6884);

const ApduStatus APDU_STATUS_ERROR_CNA_XX(0x6900);
const ApduStatus APDU_STATUS_ERROR_CNA_NO_INFORMATION(0x6900);
const ApduStatus APDU_STATUS_ERROR_CNA_COMMAND_INCOMPATIBLE_WITH_FILE_STRUCTURE(0x6981);
const ApduStatus APDU_STATUS_ERROR_CNA_SECURITY_STATUS_NOT_SATISFIED(0x6982);
const ApduStatus APDU_STATUS_ERROR_CNA_AUTHENTICATION_METHOD_BLOCKED(0x6983);
const ApduStatus APDU_STATUS_ERROR_CNA_REFERENCE_DATA_NOT_USABLE(0x6984);
const ApduStatus APDU_STATUS_ERROR_CNA_CONDITIONS_OF_USE_NOT_SATISFIED(0x6985);
const ApduStatus APDU_STATUS_ERROR_CNA_COMMAND_NOT_ALLOWED(0x6986);
const ApduStatus APDU_STATUS_ERROR_CNA_EXPECTED_SECURE_MESSAGING_DATA_OBJECTS_MISSING(0x6987);
const ApduStatus APDU_STATUS_ERROR_CNA_INCORRECT_SECURE_MESSAGING_DATA_OBJECTS(0x6988);

const ApduStatus APDU_STATUS_ERROR_WP1P2_XX(0x6A00);
const ApduStatus APDU_STATUS_ERROR_WP1P2_NO_INFORMATION(0x6A00);
const ApduStatus APDU_STATUS_ERROR_WP1P2_INCORRECT_PARAMETERS_IN_THE_COMMAND_DATA_FIELD(0x6A80);
const ApduStatus APDU_STATUS_ERROR_WP1P2_FUNCTION_NOT_SUPPORTED(0x6A81);
const ApduStatus APDU_STATUS_ERROR_WP1P2_FILE_OR_APPLICATION_NOT_FOUND(0x6A82);
const ApduStatus APDU_STATUS_ERROR_WP1P2_RECORD_NOT_FOUND(0x6A83);
const ApduStatus APDU_STATUS_ERROR_WP1P2_NOT_ENOUGH_MEMORY_SPACE_IN_THE_FILE(0x6A84);
const ApduStatus APDU_STATUS_ERROR_WP1P2_NC_INCONSISTENT_WITH_TLV_STRUCTURE(0x6A85);
const ApduStatus APDU_STATUS_ERROR_WP1P2_INCORRECT_PARAMETERS_P1P2(0x6A86);
const ApduStatus APDU_STATUS_ERROR_WP1P2_NC_INCONSISTENT_WITH_PARAMETERS_P1P2(0x6A87);
const ApduStatus APDU_STATUS_ERROR_WP1P2_REFERENCED_DATA_OR_REFERENCE_DATA_NOT_FOUND(0x6A88);
const ApduStatus APDU_STATUS_ERROR_WP1P2_FILE_ALREADY_EXISTS(0x6A89);
const ApduStatus APDU_STATUS_ERROR_WP1P2_DF_NAME_ALREADY_EXISTS(0x6A8A);

const ApduStatus APDU_STATUS_ERROR_WP1P2_NO_QUALIFICATION(0x6B00);
const ApduStatus APDU_STATUS_ERROR_PROPRIETARY_6BXX(0x6B00);

const ApduStatus APDU_STATUS_ERROR_WRONG_LE_XX(0x6C00);

const ApduStatus APDU_STATUS_ERROR_INSTRUCTION_NOT_SUPPORTED_OR_INVALID(0x6D00);
const ApduStatus APDU_STATUS_ERROR_PROPRIETARY_6DXX(0x6D00);

const ApduStatus APDU_STATUS_ERROR_CLASS_NOT_SUPPORTED(0x6E00);
const ApduStatus APDU_STATUS_ERROR_PROPRIETARY_6EXX(0x6E00);

const ApduStatus APDU_STATUS_ERROR_NO_PRECISE_DIAGNOSIS(0x6F00);
const ApduStatus APDU_STATUS_ERROR_PROPRIETARY_6FXX(0x6F00);

}}

#endif // !APDU_STATUS_HPP_INCLUDED
