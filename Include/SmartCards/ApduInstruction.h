#ifndef APDU_INSTRUCTION_H_INCLUDED
#define APDU_INSTRUCTION_H_INCLUDED

#include <Core/NTypes.h>

#ifdef N_CPP
extern "C"
{
#endif

typedef NByte ApduInstruction_;
#ifndef APDU_INSTRUCTION_HPP_INCLUDED
typedef ApduInstruction_ ApduInstruction;
#endif
N_DECLARE_TYPE(ApduInstruction)

#define APDU_INS_DEACTIVATE_FILE                  0x04
#define APDU_INS_ERASE_RECORD                     0x0C
#define APDU_INS_ERASE_BINARY                     0x0E
#define APDU_INS_ERASE_BINARY_BER_TLV             0x0F
#define APDU_INS_PERFORM_SCQL_OPERATION           0x10
#define APDU_INS_PERFORM_TRANSACTION_OPERATION    0x12
#define APDU_INS_PERFORM_USER_OPERATION           0x14
#define APDU_INS_VERIFY                           0x20
#define APDU_INS_VERIFY_BER_TLV                   0x21
#define APDU_INS_MANAGE_SECURITY_ENVIRONMENT      0x22
#define APDU_INS_CHANGE_REFERENCE_DATA            0x24
#define APDU_INS_DISABLE_VERIFICATION_REQUIREMENT 0x26
#define APDU_INS_ENABLE_VERIFICATION_REQUIREMENT  0x28
#define APDU_INS_PERFORM_SECURITY_OPERATION       0x2A
#define APDU_INS_RESET_RETRY_COUNTER              0x2C
#define APDU_INS_ACTIVATE_FILE                    0x44
#define APDU_INS_GENERATE_ASYMMETRIC_KEY_PAIR     0x46
#define APDU_INS_MANAGE_CHANNEL                   0x70
#define APDU_INS_EXTERNAL_AUTHENTICATE            0x82
#define APDU_INS_GET_CHALLENGE                    0x84
#define APDU_INS_GENERAL_AUTHENTICATE             0x86
#define APDU_INS_GENERAL_AUTHENTICATE_BER_TLV     0x87
#define APDU_INS_INTERNAL_AUTHENTICATE            0x88
#define APDU_INS_SEARCH_BINARY                    0xA0
#define APDU_INS_SEARCH_BINARY_BER_TLV            0xA1
#define APDU_INS_SEARCH_RECORD                    0xA2
#define APDU_INS_SELECT                           0xA4
#define APDU_INS_READ_BINARY                      0xB0
#define APDU_INS_READ_BINARY_BER_TLV              0xB1
#define APDU_INS_READ_RECORD                      0xB2
#define APDU_INS_READ_RECORD_BER_TLV              0xB3
#define APDU_INS_GET_RESPONSE                     0xC0
#define APDU_INS_ENVELOPE                         0xC2
#define APDU_INS_ENVELOPE_BER_TLV                 0xC3
#define APDU_INS_GET_DATA                         0xCA
#define APDU_INS_GET_DATA_BER_TLV                 0xCB
#define APDU_INS_WRITE_BINARY                     0xD0
#define APDU_INS_WRITE_BINARY_BER_TLV             0xD1
#define APDU_INS_WRITE_RECORD                     0xD2
#define APDU_INS_UPDATE_BINARY                    0xD6
#define APDU_INS_UPDATE_BINARY_BER_TLV            0xD7
#define APDU_INS_PUT_DATA                         0xDA
#define APDU_INS_PUT_DATA_BER_TLV                 0xDB
#define APDU_INS_UPDATE_RECORD                    0xDC
#define APDU_INS_UPDATE_RECORD_BER_TLV            0xDD
#define APDU_INS_CREATE_FILE                      0xE0
#define APDU_INS_APPEND_RECORD                    0xE2
#define APDU_INS_DELETE_FILE                      0xE4
#define APDU_INS_TERMINATE_DF                     0xE6
#define APDU_INS_TERMINATE_EF                     0xE8
#define APDU_INS_TERMINATE_CARD_USAGE             0xFE

NBool N_API ApduInstructionIsValid(ApduInstruction_ value);
NBool N_API ApduInstructionIsDataBerTlvEncoded(ApduInstruction_ value);

NResult N_API ApduInstructionToStringN(ApduInstruction_ value, HNString hFormat, HNString * phValue);
NResult N_API ApduInstructionToStringA(ApduInstruction_ value, const NAChar * szFormat, HNString * phValue);
#ifndef N_NO_UNICODE
NResult N_API ApduInstructionToStringW(ApduInstruction_ value, const NWChar * szFormat, HNString * phValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API ApduInstructionToString(ApduInstruction value, const NChar * szFormat, HNString * phValue);
#endif
#define ApduInstructionToString N_FUNC_AW(ApduInstructionToString)

#ifdef N_CPP
}
#endif

#endif // !APDU_INSTRUCTION_H_INCLUDED
