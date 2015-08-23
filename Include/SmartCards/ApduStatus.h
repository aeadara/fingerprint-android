#ifndef APDU_STATUS_H_INCLUDED
#define APDU_STATUS_H_INCLUDED

#include <Core/NTypes.h>

#ifdef N_CPP
extern "C"
{
#endif

typedef NUShort ApduStatus_;
#ifndef APDU_STATUS_HPP_INCLUDED
typedef ApduStatus_ ApduStatus;
#endif
N_DECLARE_TYPE(ApduStatus)

#define APDU_STATUS_NO_QUALIFICATION 0x9000
#define APDU_STATUS_PROPRIETARY_9XXX 0x9000

#define APDU_STATUS_DATA_STILL_AVAILABLE_XX 0x6100

#define APDU_STATUS_WARNING_SONVMU_XX                                                0x6200
#define APDU_STATUS_WARNING_SONVMU_NO_INFORMATION                                    0x6200
#define APDU_STATUS_WARNING_SONVMU_TRIGGERING_BY_THE_CARD_START                      0x6202
#define APDU_STATUS_WARNING_SONVMU_TRIGGERING_BY_THE_CARD_END                        0x6280
#define APDU_STATUS_WARNING_SONVMU_PART_OF_RETURNED_DATA_MAY_BE_CORRUPTED            0x6281
#define APDU_STATUS_WARNING_SONVMU_END_OF_FILE_OR_RECORD_BEFORE_READING_NE_BYTES     0x6282
#define APDU_STATUS_WARNING_SONVMU_SELECTED_FILE_DEACTIVATED                         0x6283
#define APDU_STATUS_WARNING_SONVMU_FILE_CONTROL_INFORMATION_INCORRECTY_FORMATTED     0x6284
#define APDU_STATUS_WARNING_SONVMU_SELECTED_FILE_IN_TERMINATION_STATE                0x6285
#define APDU_STATUS_WARNING_SONVMU_NO_INPUT_DATA_AVAILABLE_FROM_A_SENSOR_ON_THE_CARD 0x6286

#define APDU_STATUS_WARNING_SONVMC_XX                               0x6300
#define APDU_STATUS_WARNING_SONVMC_NO_INFORMATION                   0x6300
#define APDU_STATUS_WARNING_SONVMC_FILE_FILLED_UP_BY_THE_LAST_WRITE 0x6381
#define APDU_STATUS_WARNING_SONVMC_COUNTER_X                        0x63C0

#define APDU_STATUS_ERROR_SONVMU_XX                                      0x6400
#define APDU_STATUS_ERROR_SONVMU_EXECUTION_ERROR                         0x6400
#define APDU_STATUS_ERROR_SONVMU_IMMEDIATE_RESPONSE_REQUIRED_BY_THE_CARD 0x6401
#define APDU_STATUS_ERROR_SONVMU_TRIGGERING_BY_THE_CARD_START            0x6402
#define APDU_STATUS_ERROR_SONVMU_TRIGGERING_BY_THE_CARD_END              0x6480

#define APDU_STATUS_ERROR_SONVMC_XX             0x6500
#define APDU_STATUS_ERROR_SONVMC_NO_INFORMATION 0x6500
#define APDU_STATUS_ERROR_SONVMC_MEMORY_FAILURE 0x6581

#define APDU_STATUS_ERROR_SECURITY_XX 0x6600

#define APDU_STATUS_ERROR_WRONG_LENGTH     0x6700
#define APDU_STATUS_ERROR_PROPRIETARY_67XX 0x6700

#define APDU_STATUS_ERROR_FICNS_XX                                 0x6800
#define APDU_STATUS_ERROR_FICNS_NO_INFORMATION                     0x6800
#define APDU_STATUS_ERROR_FICNS_LOGICAL_CHANNEL_NOT_SUPPORTED      0x6881
#define APDU_STATUS_ERROR_FICNS_SECURE_MESSAGING_NOT_SUPPORTED     0x6882
#define APDU_STATUS_ERROR_FICNS_LAST_COMMAND_OF_THE_CHAIN_EXPECTED 0x6883
#define APDU_STATUS_ERROR_FICNS_COMMAND_CHAINING_NOT_SUPPORTED     0x6884

#define APDU_STATUS_ERROR_CNA_XX                                             0x6900
#define APDU_STATUS_ERROR_CNA_NO_INFORMATION                                 0x6900
#define APDU_STATUS_ERROR_CNA_COMMAND_INCOMPATIBLE_WITH_FILE_STRUCTURE       0x6981
#define APDU_STATUS_ERROR_CNA_SECURITY_STATUS_NOT_SATISFIED                  0x6982
#define APDU_STATUS_ERROR_CNA_AUTHENTICATION_METHOD_BLOCKED                  0x6983
#define APDU_STATUS_ERROR_CNA_REFERENCE_DATA_NOT_USABLE                      0x6984
#define APDU_STATUS_ERROR_CNA_CONDITIONS_OF_USE_NOT_SATISFIED                0x6985
#define APDU_STATUS_ERROR_CNA_COMMAND_NOT_ALLOWED                            0x6986
#define APDU_STATUS_ERROR_CNA_EXPECTED_SECURE_MESSAGING_DATA_OBJECTS_MISSING 0x6987
#define APDU_STATUS_ERROR_CNA_INCORRECT_SECURE_MESSAGING_DATA_OBJECTS        0x6988

#define APDU_STATUS_ERROR_WP1P2_XX                                             0x6A00
#define APDU_STATUS_ERROR_WP1P2_NO_INFORMATION                                 0x6A00
#define APDU_STATUS_ERROR_WP1P2_INCORRECT_PARAMETERS_IN_THE_COMMAND_DATA_FIELD 0x6A80
#define APDU_STATUS_ERROR_WP1P2_FUNCTION_NOT_SUPPORTED                         0x6A81
#define APDU_STATUS_ERROR_WP1P2_FILE_OR_APPLICATION_NOT_FOUND                  0x6A82
#define APDU_STATUS_ERROR_WP1P2_RECORD_NOT_FOUND                               0x6A83
#define APDU_STATUS_ERROR_WP1P2_NOT_ENOUGH_MEMORY_SPACE_IN_THE_FILE            0x6A84
#define APDU_STATUS_ERROR_WP1P2_NC_INCONSISTENT_WITH_TLV_STRUCTURE             0x6A85
#define APDU_STATUS_ERROR_WP1P2_INCORRECT_PARAMETERS_P1P2                      0x6A86
#define APDU_STATUS_ERROR_WP1P2_NC_INCONSISTENT_WITH_PARAMETERS_P1P2           0x6A87
#define APDU_STATUS_ERROR_WP1P2_REFERENCED_DATA_OR_REFERENCE_DATA_NOT_FOUND    0x6A88
#define APDU_STATUS_ERROR_WP1P2_FILE_ALREADY_EXISTS                            0x6A89
#define APDU_STATUS_ERROR_WP1P2_DF_NAME_ALREADY_EXISTS                         0x6A8A

#define APDU_STATUS_ERROR_WP1P2_NO_QUALIFICATION 0x6B00
#define APDU_STATUS_ERROR_PROPRIETARY_6BXX       0x6B00

#define APDU_STATUS_ERROR_WRONG_LE_XX 0x6C00

#define APDU_STATUS_ERROR_INSTRUCTION_NOT_SUPPORTED_OR_INVALID 0x6D00
#define APDU_STATUS_ERROR_PROPRIETARY_6DXX                     0x6D00

#define APDU_STATUS_ERROR_CLASS_NOT_SUPPORTED 0x6E00
#define APDU_STATUS_ERROR_PROPRIETARY_6EXX    0x6E00

#define APDU_STATUS_ERROR_NO_PRECISE_DIAGNOSIS 0x6F00
#define APDU_STATUS_ERROR_PROPRIETARY_6FXX     0x6F00

NBool N_API ApduStatusIsValid(ApduStatus_ value);
NBool N_API ApduStatusIsInterindustry(ApduStatus_ value);
NBool N_API ApduStatusIsProprietary(ApduStatus_ value);
NBool N_API ApduStatusIsProcessComplete(ApduStatus_ value);
NBool N_API ApduStatusIsProcessAborted(ApduStatus_ value);
NBool N_API ApduStatusIsNormalProcessing(ApduStatus_ value);
NBool N_API ApduStatusIsWarningProcessing(ApduStatus_ value);
NBool N_API ApduStatusIsExecutionError(ApduStatus_ value);
NBool N_API ApduStatusIsCheckingError(ApduStatus_ value);
NBool N_API ApduStatusIsStateOfNonVolatileMemoryChanged(ApduStatus_ value);
NBool N_API ApduStatusIsStateOfNonVolatileMemoryUnchanged(ApduStatus_ value);

NInt N_API ApduStatusGetDataStillAvailableValue(ApduStatus_ value);
NInt N_API ApduStatusGetWarningSonvmuTriggeringByTheCardValue(ApduStatus_ value);
NInt N_API ApduStatusGetWarningSonvmcCounterValue(ApduStatus_ value);
NInt N_API ApduStatusGetErrorSonvmuTriggeringByTheCardValue(ApduStatus_ value);
NInt N_API ApduStatusGetErrorWrongLeValue(ApduStatus_ value);

#define ApduStatusMake(sw1, sw2) ((ApduStatus_)(((NByte)(sw1) << 8) | (NByte)sw2))
#define ApduStatusGetSW1(value) ((NByte)((value) >> 8))
#define ApduStatusGetSW2(value) ((NByte)(value))

NBool N_API ApduStatusIsProprietary9XXX(ApduStatus_ value);
NBool N_API ApduStatusIsDataStillAvailable(ApduStatus_ value);
NBool N_API ApduStatusIsWarningSonvmu(ApduStatus_ value);
NBool N_API ApduStatusIsWarningSonvmuTriggeringByTheCard(ApduStatus_ value);
NBool N_API ApduStatusIsWarningSonvmc(ApduStatus_ value);
NBool N_API ApduStatusIsWarningSonvmcCounter(ApduStatus_ value);
NBool N_API ApduStatusIsErrorSonvmu(ApduStatus_ value);
NBool N_API ApduStatusIsErrorSonvmuTriggeringByTheCard(ApduStatus_ value);
NBool N_API ApduStatusIsErrorSonvmc(ApduStatus_ value);
NBool N_API ApduStatusIsErrorSecurity(ApduStatus_ value);
NBool N_API ApduStatusIsErrorProprietary67XX(ApduStatus_ value);
NBool N_API ApduStatusIsErrorFicns(ApduStatus_ value);
NBool N_API ApduStatusIsErrorCna(ApduStatus_ value);
NBool N_API ApduStatusIsErrorWP1P2(ApduStatus_ value);
NBool N_API ApduStatusIsErrorProprietary6BXX(ApduStatus_ value);
NBool N_API ApduStatusIsErrorWrongLe(ApduStatus_ value);
NBool N_API ApduStatusIsErrorProprietary6DXX(ApduStatus_ value);
NBool N_API ApduStatusIsErrorProprietary6EXX(ApduStatus_ value);
NBool N_API ApduStatusIsErrorProprietary6FXX(ApduStatus_ value);

NResult N_API ApduStatusToStringN(ApduStatus_ value, HNString hFormat, HNString * phValue);
NResult N_API ApduStatusToStringA(ApduStatus_ value, const NAChar * szFormat, HNString * phValue);
#ifndef N_NO_UNICODE
NResult N_API ApduStatusToStringW(ApduStatus_ value, const NWChar * szFormat, HNString * phValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API ApduStatusToString(ApduStatus value, const NChar * szFormat, HNString * phValue);
#endif
#define ApduStatusToString N_FUNC_AW(ApduStatusToString)

#ifdef N_CPP
}
#endif

#endif // !APDU_STATUS_H_INCLUDED
