#ifndef N_SMART_CARDS_DATA_ELEMENTS_H_INCLUDED
#define N_SMART_CARDS_DATA_ELEMENTS_H_INCLUDED

#include <SmartCards/BerTlv.h>

#ifdef N_CPP
extern "C"
{
#endif

#define SCARD_TAG_COUNTRY_CODE_AND_NATIONAL_DATA                        0x41
#define SCARD_TAG_ISSUER_IDENTIFICATION_NUMBER                          0x42
#define SCARD_TAG_CARD_SERVICE_DATA                                     0x43
#define SCARD_TAG_INITIAL_ACCESS_DATA                                   0x44
#define SCARD_TAG_CARD_ISSUERS_DATA                                     0x45
#define SCARD_TAG_PRE_ISSUING_DATA                                      0x46
#define SCARD_TAG_CARD_CAPABILITIES                                     0x47
#define SCARD_TAG_STATUS_INFORMATION                                    0x48
#define SCARD_TAG_APPLICATION_FAMILY_IDENTIFIER                         0x49
#define SCARD_TAG_EXTENDED_HEADER_LIST                                  0x4D
#define SCARD_TAG_APPLICATION_IDENTIFIER                                0x4F
#define SCARD_TAG_APPLICATION_LABEL                                     0x50
#define SCARD_TAG_FILE_REFERENCE                                        0x51
#define SCARD_TAG_COMMAND_TO_PERFORM                                    0x52
#define SCARD_TAG_DISCRETIONARY_DATA                                    0x53
#define SCARD_TAG_OFFSET_DATA_OBJECT                                    0x54
#define SCARD_TAG_APPLICATION_TRACK_1                                   0x56
#define SCARD_TAG_APPLICATION_TRACK_2                                   0x57
#define SCARD_TAG_APPLICATION_TRACK_3                                   0x58
#define SCARD_TAG_CARD_EXPIRATION_DATE                                  0x59
#define SCARD_TAG_PRIMARY_ACCOUNT_NUMBER                                0x5A
#define SCARD_TAG_NAME                                                  0x5B
#define SCARD_TAG_TAG_LIST                                              0x5C
#define SCARD_TAG_HEADER_LIST                                           0x5D
#define SCARD_TAG_LOGIN_DATA_PROPRIETARY                                0x5E
#define SCARD_TAG_CARDHOLDER_NAME                                       0x5F20
#define SCARD_TAG_CARD_TRACK_1                                          0x5F21
#define SCARD_TAG_CARD_TRACK_2                                          0x5F22
#define SCARD_TAG_CARD_TRACK_3                                          0x5F23
#define SCARD_TAG_APPLICATION_EXPIRATION_DATE                           0x5F24
#define SCARD_TAG_APPLICATION_EFFECTIVE_DATE                            0x5F25
#define SCARD_TAG_CARD_EFFECTIVE_DATE                                   0x5F26
#define SCARD_TAG_INTERCHANGE_CONTROL                                   0x5F27
#define SCARD_TAG_COUNTRY_CODE                                          0x5F28
#define SCARD_TAG_INTERCHANGE_PROFILE                                   0x5F29
#define SCARD_TAG_CURRENCY_CODE                                         0x5F2A
#define SCARD_TAG_DATE_OF_BIRTH                                         0x5F2B
#define SCARD_TAG_CARDHOLDER_NATIONALITY                                0x5F2C
#define SCARD_TAG_LANGUAGE_PREFERENCES                                  0x5F2D
#define SCARD_TAG_CARDHOLDER_BIOMETRIC_DATA                             0x5F2E
#define SCARD_TAG_PIN_USAGE_POLICY                                      0x5F2F
#define SCARD_TAG_SERVICE_CODE                                          0x5F30
#define SCARD_TAG_TRANSACTION_COUNTER                                   0x5F32
#define SCARD_TAG_TRANSACTION_DATE                                      0x5F33
#define SCARD_TAG_CARD_SEQUENCE_NUMBER                                  0x5F34
#define SCARD_TAG_SEX                                                   0x5F35
#define SCARD_TAG_CURRENCY_EXPONENT                                     0x5F36
#define SCARD_TAG_STATIC_INTERNAL_AUTHENTICATION                        0x5F37
#define SCARD_TAG_STATIC_INTERNAL_AUTHENTICATION_FIRST_ASSOCIATED_DATA  0x5F38
#define SCARD_TAG_STATIC_INTERNAL_AUTHENTICATION_SECOND_ASSOCIATED_DATA 0x5F39
#define SCARD_TAG_DYNAMIC_INTERNAL_AUTHENTICATION                       0x5F3A
#define SCARD_TAG_DYNAMIC_EXTERNAL_AUTHENTICATION                       0x5F3B
#define SCARD_TAG_DYNAMIC_MUTUAL_AUTHENTICATION                         0x5F3C
#define SCARD_TAG_CARDHOLDER_PORTRAIT_IMAGE                             0x5F40
#define SCARD_TAG_ELEMENT_LIST                                          0x5F41
#define SCARD_TAG_ADDRESS                                               0x5F42
#define SCARD_TAG_CARDHOLDER_HANDWRITTEN_SIGNATURE_IMAGE                0x5F43
#define SCARD_TAG_APPLICATION_IMAGE                                     0x5F44
#define SCARD_TAG_DISPLAY_MESSAGE                                       0x5F45
#define SCARD_TAG_TIMER                                                 0x5F46
#define SCARD_TAG_MESSAGE_REFERENCE                                     0x5F47
#define SCARD_TAG_CARDHOLDER_PRIVATE_KEY                                0x5F48
#define SCARD_TAG_CARDHOLDER_PUBLIC_KEY                                 0x5F49
#define SCARD_TAG_PUBLIC_KEY_OF_CERTIFICATION_AUTHORITY                 0x5F4A
#define SCARD_TAG_DEPRECATED                                            0x5F4B
#define SCARD_TAG_CERTIFICATE_HOLDER_AUTHORIZATION                      0x5F4C
#define SCARD_TAG_INTEGRATED_CIRCUIT_MANUFACTURER_IDENTIFIER            0x5F4D
#define SCARD_TAG_CERTIFICATE_CONTENT                                   0x5F4E
#define SCARD_TAG_UNIFORM_RESOURCE_LOCATOR                              0x5F50
#define SCARD_TAG_ANSWER_TO_RESET                                       0x5F51
#define SCARD_TAG_HISTORICAL_BYTES                                      0x5F52
#define SCARD_TAG_INTERNATIONAL_BANK_ACCOUNT_NUMBER                     0x5F53
#define SCARD_TAG_BANK_IDENTIFIER_CODE                                  0x5F54
#define SCARD_TAG_COUNTRY_CODE_ALPHA2_FORMAT                            0x5F55
#define SCARD_TAG_COUNTRY_CODE_ALPHA3_FORMAT                            0x5F56
#define SCARD_TAG_ACCOUNT_TYPE                                          0x5F57
#define SCARD_TAG_DIGITAL_SIGNATURE                                     0x5F3D
#define SCARD_TAG_APPLICATION_TEMPLATE                                  0x61
#define SCARD_TAG_FCP_TEMPLATE                                          0x62
#define SCARD_TAG_WRAPPER                                               0x63
#define SCARD_TAG_FMD_TEMPLATE                                          0x64
#define SCARD_TAG_CARDHOLDER_RELATED_DATA                               0x65
#define SCARD_TAG_CARD_DATA                                             0x66
#define SCARD_TAG_AUTHENTICATION_DATA                                   0x67
#define SCARD_TAG_SPECIAL_USER_REQUIREMENTS                             0x68
#define SCARD_TAG_LOGIN_TEMPLATE                                        0x6A
#define SCARD_TAG_QUALIFIED_NAME                                        0x6B
#define SCARD_TAG_CARDHOLDER_IMAGE_TEMPLATE                             0x6C
#define SCARD_TAG_APPLICATION_IMAGE_TEMPLATE                            0x6D
#define SCARD_TAG_APPLICATION_RELATED_DATA                              0x6E
#define SCARD_TAG_FCI_TEMPLATE                                          0x6F
#define SCARD_TAG_NON_INTERINDUSTRY_DATA_OBJECTS_70                     0x70
#define SCARD_TAG_NON_INTERINDUSTRY_DATA_OBJECTS_71                     0x71
#define SCARD_TAG_NON_INTERINDUSTRY_DATA_OBJECTS_72                     0x72
#define SCARD_TAG_DISCRETIONARY_DATA_OBJECTS                            0x73
#define SCARD_TAG_NON_INTERINDUSTRY_DATA_OBJECTS_74                     0x74
#define SCARD_TAG_NON_INTERINDUSTRY_DATA_OBJECTS_75                     0x75
#define SCARD_TAG_NON_INTERINDUSTRY_DATA_OBJECTS_76                     0x76
#define SCARD_TAG_NON_INTERINDUSTRY_DATA_OBJECTS_77                     0x77
#define SCARD_TAG_COMPATIBLE_TAG_ALLOCATION_AUTHORITY                   0x78
#define SCARD_TAG_COEXISTENT_TAG_ALLOCATION_AUTHORITY                   0x79
#define SCARD_TAG_SECURITY_SUPPORT_TEMPLATE                             0x7A
#define SCARD_TAG_SECURITY_ENVIRONMENT_TEMPLATE                         0x7B
#define SCARD_TAG_DYNAMIC_AUTHENTICATION_TEMPLATE                       0x7C
#define SCARD_TAG_SECURE_MESSAGING_TEMPLATE                             0x7D
#define SCARD_TAG_INTERINDUSTRY_DATA_OBJECTS                            0x7E
#define SCARD_TAG_DISPLAY_CONTROL                                       0x7F20
#define SCARD_TAG_CARDHOLDER_CERTIFICATE                                0x7F21
#define SCARD_TAG_CARDHOLDER_REQUIREMENTS_INCLUDED_FEATURES             0x7F22
#define SCARD_TAG_CARDHOLDER_REQUIREMENTS_EXCLUDED_FEATURES             0x7F23
#define SCARD_TAG_BIOMETRIC_DATA_TEMPLATE                               0x7F2E
#define SCARD_TAG_DIGITAL_SIGNATURE_BLOCK                               0x7F3D
#define SCARD_TAG_CARDHOLDER_PRIVATE_KEY_TEMPLATE                       0x7F48
#define SCARD_TAG_CARDHOLDER_PUBLIC_KEY_TEMPLATE                        0x7F49
#define SCARD_TAG_CERTIFICATE_CONTENT_TEMPLATE                          0x7F4E
#define SCARD_TAG_BIOMETRIC_INFORMATION_TEMPLATE                        0x7F60
#define SCARD_TAG_BIOMETRIC_INFORMATION_GROUP_TEMPLATE                  0x7F61

N_DECLARE_STATIC_OBJECT_TYPE(NSmartCardsDataElements)

#ifdef N_CPP
}
#endif

#endif // !N_SMART_CARDS_DATA_ELEMENTS_H_INCLUDED
