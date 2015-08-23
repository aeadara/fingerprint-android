#ifndef _BIOAPI_TYPE_H_INCLUDED
#define _BIOAPI_TYPE_H_INCLUDED

#include "bioapi_porttype.h"

#ifdef __cplusplus
extern "C" {
#endif


/*****************************************************************************
 * BioAPI general purpose types.
 *****************************************************************************/

typedef uint32_t BioAPI_RETURN;
#define BioAPI_OK   (0)

typedef  uint32_t BioAPI_BOOL;
#define BioAPI_FALSE (0)
#define BioAPI_TRUE  (!BioAPI_FALSE)

typedef uint32_t BioAPI_HANDLE;
#define BioAPI_INVALID_HANDLE (0)

typedef uint8_t BioAPI_STRING [269];

typedef struct bioapi_data{
    uint32_t Length; /* in bytes */
    void *Data;
} BioAPI_DATA;


typedef uint32_t BioAPI_CATEGORY;

#define BioAPI_CATEGORY_ARCHIVE        (0x00000001)
#define BioAPI_CATEGORY_MATCHING_ALG   (0x00000002)
#define BioAPI_CATEGORY_PROCESSING_ALG (0x00000004)
#define BioAPI_CATEGORY_SENSOR         (0x00000008)

#define BioAPIRI_CATEGORY_MASK         (0x7FFFFFFF)

typedef uint8_t BioAPI_UUID[16];

typedef uint8_t BioAPI_VERSION;

typedef struct bioapi_date {
    uint16_t Year; ///< valid range: 1900 – 9999 
    uint8_t Month; ///< valid range: 01 – 12 
    uint8_t Day;   ///< valid range: 01 – 31, consistent with associated month/year 
} BioAPI_DATE;

#define BioAPI_NO_YEAR_AVAILABLE  (0)
#define BioAPI_NO_MONTH_AVAILABLE (0)
#define BioAPI_NO_DAY_AVAILABLE   (0)
#define BioAPIRI_NO_DATE_AVAILABLE  {BioAPI_NO_YEAR_AVAILABLE,BioAPI_NO_MONTH_AVAILABLE,BioAPI_NO_DAY_AVAILABLE}

typedef struct bioapi_time {
    uint8_t Hour;    ///< valid range: 00 – 23 
    uint8_t Minute ; ///< valid range: 00 – 59 
    uint8_t Second ; ///< valid range: 00 – 59 
} BioAPI_TIME;

#define BioAPI_NO_HOUR_AVAILABLE   (99)
#define BioAPI_NO_MINUTE_AVAILABLE (99)
#define BioAPI_NO_SECOND_AVAILABLE (99)
#define BioAPIRI_NO_TIME_AVAILABLE   {BioAPI_NO_HOUR_AVAILABLE, BioAPI_NO_MINUTE_AVAILABLE, BioAPI_NO_SECOND_AVAILABLE}


#define BioAPIRI_DEFAULT_TIMEOUT (-1)


/*****************************************************************************
 * BIR data types.
******************************************************************************/

typedef int32_t BioAPI_BIR_HANDLE;

#define BioAPI_INVALID_BIR_HANDLE     (-1)
#define BioAPI_UNSUPPORTED_BIR_HANDLE (-2)



typedef struct bioapi_bir_biometric_data_format {
    uint16_t FormatOwner; ///<  assigned and registered by the CBEFF Registration Authority.  
    uint16_t FormatType;  ///<  assigned by the Format Owner and may optionally be registered. 
} BioAPI_BIR_BIOMETRIC_DATA_FORMAT;

typedef struct bioapi_bir_biometric_product_ID {
    uint16_t ProductOwner;
    uint16_t ProductType;
} BioAPI_BIR_BIOMETRIC_PRODUCT_ID;

#define BioAPI_NO_PRODUCT_OWNER_AVAILABLE (0x0000)
#define BioAPI_NO_PRODUCT_TYPE_AVAILABLE  (0x0000)
#define BioAPIRI_NO_BIR_BIOMETRIC_PRODUCT_ID_AVAILABLE {BioAPI_NO_PRODUCT_OWNER_AVAILABLE, BioAPI_NO_PRODUCT_TYPE_AVAILABLE}

typedef uint32_t BioAPI_BIR_BIOMETRIC_TYPE;

#define BioAPI_NO_TYPE_AVAILABLE       (0x00000000)
#define BioAPI_TYPE_MULTIPLE           (0x00000001)
#define BioAPI_TYPE_FACIAL_FEATURES    (0x00000002)
#define BioAPI_TYPE_VOICE              (0x00000004)
#define BioAPI_TYPE_FINGERPRINT        (0x00000008)
#define BioAPI_TYPE_IRIS               (0x00000010)
#define BioAPI_TYPE_RETINA             (0x00000020)
#define BioAPI_TYPE_HAND_GEOMETRY      (0x00000040)
#define BioAPI_TYPE_SIGNATURE_DYNAMICS (0x00000080)
#define BioAPI_TYPE_KEYSTOKE_DYNAMICS  (0x00000100)
#define BioAPI_TYPE_LIP_MOVEMENT       (0x00000200)
#define BioAPI_TYPE_THERMAL_FACE_IMAGE (0x00000400)
#define BioAPI_TYPE_THERMAL_HAND_IMAGE (0x00000800)
#define BioAPI_TYPE_GAIT               (0x00001000)
#define BioAPI_TYPE_OTHER              (0x40000000)
#define BioAPI_TYPE_PASSWORD           (0x80000000)

typedef uint8_t BioAPI_BIR_DATA_TYPE;

#define BioAPI_BIR_DATA_TYPE_RAW          (0x01)
#define BioAPI_BIR_DATA_TYPE_INTERMEDIATE (0x02)
#define BioAPI_BIR_DATA_TYPE_PROCESSED    (0x04)
#define BioAPI_BIR_DATA_TYPE_ENCRYPTED    (0x10)
#define BioAPI_BIR_DATA_TYPE_SIGNED       (0x20)
#define BioAPI_BIR_INDEX_PRESENT          (0x80)


typedef  int8_t  BioAPI_QUALITY;

#define BioAPIRI_QUALITY_NOTSET           (-1)
#define BioAPIRI_QUALITY_UNSUPPORTED      (-2)
#define BioAPIRI_QUALITY_MIN              0
#define BioAPIRI_QUALITY_MAX              100
#define BioAPIRI_QUALITY_MAX_UNACCEPTABLE 25
#define BioAPIRI_QUALITY_MAX_MARGINAL     50
#define BioAPIRI_QUALITY_MAX_ADEQUATE     75
#define BioAPIRI_QUALITY_MAX_EXCELLENT    100


typedef uint8_t BioAPI_BIR_PURPOSE;

#define BioAPI_PURPOSE_VERIFY                         (1)
#define BioAPI_PURPOSE_IDENTIFY                       (2)
#define BioAPI_PURPOSE_ENROLL                         (3)
#define BioAPI_PURPOSE_ENROLL_FOR_VERIFICATION_ONLY   (4)
#define BioAPI_PURPOSE_ENROLL_FOR_IDENTIFICATION_ONLY (5)
#define BioAPI_PURPOSE_AUDIT                          (6)
#define BioAPI_NO_PURPOSE_AVAILABLE                   (0)

typedef struct bioapi_bir_security_block_format {
    uint16_t SecurityFormatOwner;
    uint16_t SecurityFormatType;
} BioAPI_BIR_SECURITY_BLOCK_FORMAT;
#define BioAPIRI_NO_BIR_SECURITY_BLOCK_FORMAT_AVAILABLE {0,0}

typedef uint8_t BioAPI_BIR_SUBTYPE;

#define BioAPI_BIR_SUBTYPE_LEFT          (0x01)
#define BioAPI_BIR_SUBTYPE_RIGHT         (0x02)
#define BioAPI_BIR_SUBTYPE_THUMB         (0x04)
#define BioAPI_BIR_SUBTYPE_POINTERFINGER (0x08)
#define BioAPI_BIR_SUBTYPE_MIDDLEFINGER  (0x10)
#define BioAPI_BIR_SUBTYPE_RINGFINGER    (0x20)
#define BioAPI_BIR_SUBTYPE_LITTLEFINGER  (0x40)
#define BioAPI_BIR_SUBTYPE_MULTIPLE      (0x80)
#define BioAPI_NO_SUBTYPE_AVAILABLE      (0x00)

typedef struct bioapi_DTG {
    BioAPI_DATE Date;
    BioAPI_TIME Time;
} BioAPI_DTG;


typedef struct bioapi_bir_header {
    BioAPI_VERSION                   HeaderVersion;
    BioAPI_BIR_DATA_TYPE             Type;
    BioAPI_BIR_BIOMETRIC_DATA_FORMAT Format;
    BioAPI_QUALITY                   Quality;
    BioAPI_BIR_PURPOSE               Purpose;
    BioAPI_BIR_BIOMETRIC_TYPE        FactorsMask;
    BioAPI_BIR_BIOMETRIC_PRODUCT_ID  ProductID;
    BioAPI_DTG                       CreationDTG;
    BioAPI_BIR_SUBTYPE               Subtype;
    BioAPI_DATE                      ExpirationDate;
    BioAPI_BIR_SECURITY_BLOCK_FORMAT SBFormat;
    BioAPI_UUID                      Index;
} BioAPI_BIR_HEADER;

typedef struct bioapi_bir {
    BioAPI_BIR_HEADER   Header;
    BioAPI_DATA         BiometricData; ///< type is self delimiting 
    BioAPI_DATA         SecurityBlock; ///< SecurityBlock.Data=NULL if no SB 
} BioAPI_BIR;


typedef struct bioapi_bir_array_population {
    uint32_t NumberOfMembers;
    BioAPI_BIR  *Members; ///< A pointer to an array of BIRs 
} BioAPI_BIR_ARRAY_POPULATION;


/*****************************************************************************
 * BIR database related types.
 *****************************************************************************/

typedef uint32_t BioAPI_DB_ACCESS_TYPE;

#define BioAPI_DB_ACCESS_READ  (0x00000001)
#define BioAPI_DB_ACCESS_WRITE (0x00000002)

typedef uint32_t BioAPI_DB_MARKER_HANDLE;


typedef int32_t BioAPI_DB_HANDLE, *BioAPI_DB_HANDLE_PTR;

#define BioAPI_DB_INVALID_HANDLE   (-1)
#define BioAPI_DB_DEFAULT_HANDLE   (0)
#define BioAPI_DB_DEFAULT_UUID_PTR (NULL)

typedef struct bioapi_dbbir_id {
    BioAPI_DB_HANDLE DbHandle;
    BioAPI_UUID KeyValue;
} BioAPI_DBBIR_ID;



/*****************************************************************************
 * BioAPI biometric operations supporting types.
 *****************************************************************************/

typedef uint8_t BioAPI_INPUT_BIR_FORM;

#define BioAPI_DATABASE_ID_INPUT (1)
#define BioAPI_BIR_HANDLE_INPUT  (2)
#define BioAPI_FULLBIR_INPUT     (3)

typedef struct bioapi_input_bir {
    BioAPI_INPUT_BIR_FORM Form;
    union {
    BioAPI_DBBIR_ID *BIRinDb;
    BioAPI_BIR_HANDLE *BIRinBSP;
    BioAPI_BIR *BIR;
    } InputBIR;
} BioAPI_INPUT_BIR;


typedef uint8_t BioAPI_IDENTIFY_POPULATION_TYPE;
#define BioAPI_DB_TYPE           (1)
#define BioAPI_ARRAY_TYPE        (2) 
#define BioAPI_PRESET_ARRAY_TYPE (3)

typedef struct bioapi_identify_population {
    BioAPI_IDENTIFY_POPULATION_TYPE Type;
    union {
    BioAPI_DB_HANDLE *BIRDataBase;
    BioAPI_BIR_ARRAY_POPULATION *BIRArray;
    } BIRs;
} BioAPI_IDENTIFY_POPULATION;


typedef int32_t BioAPI_FMR;
#define BioAPI_NOT_SET (-1)

typedef struct bioapi_candidate {
    BioAPI_IDENTIFY_POPULATION_TYPE Type;
    union {
    BioAPI_UUID *BIRInDataBase;
    uint32_t *BIRInArray;
    } BIR;
    BioAPI_FMR FMRAchieved;
} BioAPI_CANDIDATE;



/*****************************************************************************
 * BioAPI schemas.
 *****************************************************************************/

typedef uint32_t BioAPI_OPERATIONS_MASK;

#define BioAPI_ENABLEEVENTS             (0x00000001)
#define BioAPI_SETGUICALLBACKS          (0x00000002)
#define BioAPI_CAPTURE                  (0x00000004)
#define BioAPI_CREATETEMPLATE           (0x00000008)
#define BioAPI_PROCESS                  (0x00000010)
#define BioAPI_PROCESSWITHAUXBIR        (0x00000020)
#define BioAPI_VERIFYMATCH              (0x00000040)
#define BioAPI_IDENTIFYMATCH            (0x00000080)
#define BioAPI_ENROLL                   (0x00000100)
#define BioAPI_VERIFY                   (0x00000200)
#define BioAPI_IDENTIFY                 (0x00000400)
#define BioAPI_IMPORT                   (0x00000800)
#define BioAPI_PRESETIDENTIFYPOPULATION (0x00001000)
#define BioAPI_DATABASEOPERATIONS       (0x00002000)
#define BioAPI_SETPOWERMODE             (0x00004000)
#define BioAPI_SETINDICATORSTATUS       (0x00008000)
#define BioAPI_GETINDICATORSTATUS       (0x00010000)
#define BioAPI_CALIBRATESENSOR          (0x00020000)
#define BioAPI_UTILITIES                (0X00040000)
#define BioAPI_QUERYUNITS               (0x00100000)
#define BioAPI_QUERYBFPS                (0x00200000)
#define BioAPI_CONTROLUNIT              (0X00400000)

typedef uint32_t BioAPI_OPTIONS_MASK;

#define BioAPI_RAW                  (0x00000001)
#define BioAPI_QUALITY_RAW          (0x00000002)
#define BioAPI_QUALITY_INTERMEDIATE (0x00000004)
#define BioAPI_QUALITY_PROCESSED    (0x00000008)

#define BioAPI_APP_GUI              (0x00000010)
#define BioAPI_APP_GUI_STREAMING    (0x00000020)

#define BioAPI_SOURCEPRESENT        (0x00000040)
#define BioAPI_PAYLOAD              (0x00000080)
#define BioAPI_BIR_SIGN             (0x00000100)
#define BioAPI_BIR_ENCRYPT          (0x00000200)
#define BioAPI_TEMPLATEUPDATE       (0x00000400)
#define BioAPI_ADAPTATION           (0x00000800)
#define BioAPI_BINNING              (0x00001000)
#define BioAPI_SELFCONTAINEDDEVICE  (0x00002000)
#define BioAPI_MOC                  (0x00004000)
#define BioAPI_SUBTYPE_TO_CAPTURE   (0x00008000)
#define BioAPI_SENSORBFP            (0x00010000)
#define BioAPI_ARCHIVEBFP           (0x00020000)
#define BioAPI_MATCHINGBFP          (0x00040000)
#define BioAPI_PROCESSINGBFP        (0x00080000)
#define BioAPI_COARSESCORES         (0x00100000)

typedef struct bioapi_framework_schema {
    BioAPI_UUID FrameworkUuid;    // UUID of the Framework component.
    BioAPI_STRING FwDescription;  // description of the Framework.
    uint8_t *Path;                // path of the Framework code, including the filename. The path may be a URL.
    BioAPI_VERSION SpecVersion;   // version of the BioAPI specification to which the Framework was implemented.
    BioAPI_STRING ProductVersion; // The version string of the Framework software.
    BioAPI_STRING Vendor;         // name of the Framework vendor.
    BioAPI_UUID FwPropertyId;     // UUID of the format of the following Framework property.
    BioAPI_DATA FwProperty;       // Address and length of a memory buffer containing the Framework property..
} BioAPI_FRAMEWORK_SCHEMA;

typedef struct bioapi_bsp_schema {
    BioAPI_UUID BSPUuid; ///<  UUID of the BSP
    BioAPI_STRING BSPDescription; ///<  description of the BSP
    uint8_t *Path; ///<  Path of the BSP file, including the filename. The path may be a URL.
    BioAPI_VERSION SpecVersion; ///<  version of the BioAPI specification to which the BFP was implemented.
    BioAPI_STRING ProductVersion; ///<  The version string of the BSP software.
    BioAPI_STRING Vendor; ///<  the name of the BSP vendor.
    BioAPI_BIR_BIOMETRIC_DATA_FORMAT *BSPSupportedFormats; ///<  supported BDB formats.
    uint32_t NumSupportedFormats; ///<  Number of supported formats contained in BspSupportedFormats.
    BioAPI_BIR_BIOMETRIC_TYPE FactorsMask; ///<  biometric types are supported by the BSP.
    BioAPI_OPERATIONS_MASK Operations; ///<  operations are supported by the BSP.
    BioAPI_OPTIONS_MASK Options; ///<  options are supported by the BSP.
    BioAPI_FMR PayloadPolicy; ///<  minimum FMR value to release the payload after successful verification.
    uint32_t MaxPayloadSize; ///<  Maximum payload size (in bytes) that the BSP can accept.
    int32_t  DefaultVerifyTimeout; ///<  Milliseconds when no timeout is specified by the application.
    int32_t  DefaultIdentifyTimeout;
    int32_t  DefaultCaptureTimeout;
    int32_t  DefaultEnrollTimeout;
    int32_t  DefaultCalibrateTimeout;
    uint32_t  MaxBSPDbSize; ///<  Maximum size of a BSP-controlled BIR database.
    uint32_t  MaxIdentify; ///<  Largest population. Unlimited = FFFFFFFF.
}BioAPI_BSP_SCHEMA;



typedef struct _bioapi_bfp_list_element {
    BioAPI_CATEGORY BFPCategory; ///< Defines the category of the BioAPI Unit that it supports.
    BioAPI_UUID BFPUuid; ///< UUID of the BFP in the component registry. 
}BioAPI_BFP_LIST_ELEMENT;

typedef struct bioapi_bfp_schema {
    BioAPI_UUID BFPUuid; ///<  UUID of the BFP.
    BioAPI_CATEGORY BFPCategory; ///<  Category of the BFP identified by the BFPUuid.
    BioAPI_STRING BFPDescription; ///<  A NUL-terminated string containing a text description of the BFP.
    uint8_t *Path; ///<  Path of the BFP file, including the filename. The path may be a URL.
    BioAPI_VERSION SpecVersion; ///<  version of the FPI specification to which the BFP was implemented.
    BioAPI_STRING ProductVersion; ///<  The version string of the BFP software.
    BioAPI_STRING Vendor; ///<  the name of the BFP vendor.
    BioAPI_BIR_BIOMETRIC_DATA_FORMAT *BFPSupportedFormats; ///<  A pointer to an array of supported BDB formats.
    uint32_t NumSupportedFormats; ///<  Number of supported formats contained in BfpSupportedFormats.
    BioAPI_BIR_BIOMETRIC_TYPE FactorsMask; ///<  A mask which indicates which biometric types are supported by the BFP.
    BioAPI_UUID BFPPropertyID; ///<  UUID of the format of the following BFP property.
    BioAPI_DATA BFPProperty; ///<  Address and length of a memory buffer containing the BFP property. The format and content can either be 
                             ///<  specified by a vendor or can be specified in a related standard.
}BioAPI_BFP_SCHEMA;


typedef uint32_t BioAPI_UNIT_ID, *BioAPI_UNIT_ID_PTR;
#define BioAPI_DONT_CARE    (0x00000000) 
#define BioAPI_DONT_INCLUDE (0xFFFFFFFF)

typedef struct _bioapi_unit_list_element {
    BioAPI_CATEGORY UnitCategory; ///<  Defines the category of the BioAPI Unit.
    BioAPI_UNIT_ID UnitId; ///<  The ID of a BioAPI Unit to be used in this attach session. 
                           ///<  This will be created by the BSP uniquely.
}BioAPI_UNIT_LIST_ELEMENT;



typedef struct bioapi_unit_schema {
    BioAPI_UUID BSPUuid; ///<  UUID of the BSP supporting this BioAPI Unit
    BioAPI_UUID UnitManagerUuid; ///<  UUID of the component directly managing the Unit (BSP itself or a BFP)
    BioAPI_UNIT_ID UnitId; ///<  ID of the Unit during this attach session, created by the BSP uniquely
    BioAPI_CATEGORY UnitCategory; ///<  Defines the category of the BioAPI Unit
    BioAPI_UUID UnitProperties; ///<  UUID of a set of properties of the BioAPI Unit. 
                                ///<  The set can be either specified by each vendor or following a related standard.
    BioAPI_STRING VendorInformation; ///<  Contains vendor proprietary information.
    uint32_t SupportedEvents; ///<  A mask indicating which types of events are supported by the hardware.
    BioAPI_UUID UnitPropertyID; ///<  UUID of the format of the following structure describing the BioAPI Unit.
                                ///<  The format can be either specified by each vendor or follow a related standard.
    BioAPI_DATA UnitProperty; ///<  A buffer containing vendor or standard information about the BioAPI Unit. 
                              ///<  The memory is allocated by the BSP and has to be freed by the application.
    BioAPI_STRING HardwareVersion; ///<  version number of the hardware.  Zero if not availabl
    BioAPI_STRING FirmwareVersion; ///<  version number of the firmware.  Zero if not available
    BioAPI_STRING SoftwareVersion; ///<  version number of the software (e.g. of the BFP).  Zero if not available.
    BioAPI_STRING HardwareSerialNumber; ///<  vendor defined unique serial number of the hardware component.
    BioAPI_BOOL AuthenticatedHardware; ///<  A boolean value that indicates whether the hardware component has been authenticated
    uint32_t MaxBSPDbSize; ///<  Maximum size database supported by Unit. If zero, no database exists.
    uint32_t MaxIdentify; ///<  Largest identify population supported by Unit. Unlimited = FFFFFFFF.
} BioAPI_UNIT_SCHEMA;



/*****************************************************************************
 * BioAPI events/callback types
******************************************************************************/

typedef uint32_t BioAPI_EVENT;

#define BioAPI_NOTIFY_INSERT         (1)
#define BioAPI_NOTIFY_REMOVE         (2)
#define BioAPI_NOTIFY_FAULT          (3)
#define BioAPI_NOTIFY_SOURCE_PRESENT (4)
#define BioAPI_NOTIFY_SOURCE_REMOVED (5)

typedef uint32_t BioAPI_EVENT_MASK;

#define BioAPI_NOTIFY_INSERT_BIT         (0x00000001)
#define BioAPI_NOTIFY_REMOVE_BIT         (0x00000002)
#define BioAPI_NOTIFY_FAULT_BIT          (0x00000004)
#define BioAPI_NOTIFY_SOURCE_PRESENT_BIT (0x00000008)
#define BioAPI_NOTIFY_SOURCE_REMOVED_BIT (0x00000010)



typedef BioAPI_RETURN (BioAPI *BioAPI_EventHandler) (
    const BioAPI_UUID *BSPUuid, ///<  The UUID of the BSP raising the event.
    BioAPI_UNIT_ID UnitID,      ///<  The unit ID of the BioAPI Unit associated with the event.
    void* AppNotifyCallbackCtx, ///<  The application context specified in BioAPI_BSPLoad( ) 
                                ///<  that established the event handler.
    const BioAPI_UNIT_SCHEMA *UnitSchema, ///<  unit schema if EventType = BioAPI_NOTIFY_INSERT, NULL otherwise
    BioAPI_EVENT EventType);    ///<  The BioAPI_EVENT that has occurred.



/*****************************************************************************
 * GUI supporting types.
 *****************************************************************************/
typedef struct bioapi_gui_bitmap {
    uint32_t Width; /* Width of bitmap in pixels (i.e., number of pixels for each line)*/
    uint32_t Height; /* Height of bitmap in pixels (i.e., number of lines) */
    BioAPI_DATA Bitmap;
} BioAPI_GUI_BITMAP;

typedef uint32_t BioAPI_GUI_MESSAGE;

typedef uint8_t BioAPI_GUI_PROGRESS;

typedef uint8_t BioAPI_GUI_RESPONSE;
#define BioAPI_CAPTURE_SAMPLE (1) /* Instruction to BSP to capture sample */
#define BioAPI_CANCEL         (2) /* User cancelled operation */
#define BioAPI_CONTINUE       (3) /* User or application selects to proceed */
#define BioAPI_VALID_SAMPLE   (4) /* Valid sample received */
#define BioAPI_INVALID_SAMPLE (5) /* Invalid sample received */

typedef uint32_t BioAPI_GUI_STATE;
#define BioAPI_SAMPLE_AVAILABLE  (0x0001) /* Sample captured and available */
#define BioAPI_MESSAGE_PROVIDED  (0x0002) /* BSP provided message for display */
#define BioAPI_PROGRESS_PROVIDED (0x0004) /* BSP provide progress for display */

typedef BioAPI_RETURN (BioAPI *BioAPI_GUI_STATE_CALLBACK) (
    void *GuiStateCallbackCtx,
    BioAPI_GUI_STATE GuiState,
    BioAPI_GUI_RESPONSE *Response,
    BioAPI_GUI_MESSAGE Message,
    BioAPI_GUI_PROGRESS Progress,
    const BioAPI_GUI_BITMAP *SampleBuffer);

typedef BioAPI_RETURN (BioAPI *BioAPI_GUI_STREAMING_CALLBACK) (
    void *GuiStreamingCallbackCtx,
    const BioAPI_GUI_BITMAP *Bitmap);

typedef uint8_t BioAPI_INDICATOR_STATUS, *BioAPI_INDICATOR_STATUS_PTR;

#define BioAPI_INDICATOR_ACCEPT  (1)
#define BioAPI_INDICATOR_REJECT  (2)
#define BioAPI_INDICATOR_READY   (3)
#define BioAPI_INDICATOR_BUSY    (4)
#define BioAPI_INDICATOR_FAILURE (5)



/*****************************************************************************
 * Install/configuration/power supporting types.
 *****************************************************************************/

typedef uint32_t  BioAPI_INSTALL_ACTION;
#define BioAPI_INSTALL_ACTION_INSTALL   (1) 
#define BioAPI_INSTALL_ACTION_REFRESH   (2) 
#define BioAPI_INSTALL_ACTION_UNINSTALL (3) 


typedef struct _install_error {
    BioAPI_RETURN ErrorCode;
    BioAPI_STRING ErrorString;
}BioAPI_INSTALL_ERROR;

typedef uint32_t BioAPI_POWER_MODE;

#define BioAPI_POWER_NORMAL (1)
#define BioAPI_POWER_DETECT (2)
#define BioAPI_POWER_SLEEP  (3)


#ifdef __cplusplus
}
#endif

#endif  /* _BIOAPI_TYPE_H_INCLUDED */
