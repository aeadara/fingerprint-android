#ifndef _BIOAPI_API_H_INCLUDED
#define _BIOAPI_API_H_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

//*****************************************************************************
// 8.1  Component Management Functions
//*****************************************************************************

    DLLAPI BioAPI_RETURN BioAPI BioAPI_Init (
    /* IN */ BioAPI_VERSION Version);
 
typedef BioAPI_RETURN (BioAPI *BioAPI_Init_PTR) (
    /* IN */ BioAPI_VERSION Version);


DLLAPI BioAPI_RETURN BioAPI BioAPI_Terminate (void);

typedef BioAPI_RETURN (BioAPI *BioAPI_Terminate_PTR) (void);


DLLAPI BioAPI_RETURN BioAPI BioAPI_GetFrameworkInfo (
    /* OUT */ BioAPI_FRAMEWORK_SCHEMA *FrameworkSchema);

typedef BioAPI_RETURN (BioAPI *BioAPI_GetFrameworkInfo_PTR) (
    /* OUT */ BioAPI_FRAMEWORK_SCHEMA *FrameworkSchema);

DLLAPI BioAPI_RETURN BioAPI BioAPI_EnumBSPs (
    /* OUT */ BioAPI_BSP_SCHEMA **BSPSchemaArray,
    /* OUT */ uint32_t *NumberOfElements);


typedef BioAPI_RETURN (BioAPI *BioAPI_EnumBSPs_PTR) (
    /* OUT */ BioAPI_BSP_SCHEMA **BSPSchemaArray,
    /* OUT */ uint32_t *NumberOfElements);

DLLAPI BioAPI_RETURN BioAPI BioAPI_BSPLoad (
    /* IN */ const BioAPI_UUID *BSPUuid,
    /* IN */ OPTIONAL BioAPI_EventHandler AppNotifyCallback,
    /* IN */ OPTIONAL void *AppNotifyCallbackCtx);


typedef BioAPI_RETURN (BioAPI *BioAPI_BSPLoad_PTR) (
    /* IN */ const BioAPI_UUID *BSPUuid,
    /* IN */ OPTIONAL BioAPI_EventHandler AppNotifyCallback,
    /* IN */ OPTIONAL void *AppNotifyCallbackCtx);


DLLAPI BioAPI_RETURN BioAPI BioAPI_BSPUnload (
    /* IN */ const BioAPI_UUID *BSPUuid,
    /* IN */ OPTIONAL BioAPI_EventHandler AppNotifyCallback,
    /* IN */ OPTIONAL void *AppNotifyCallbackCtx);


typedef BioAPI_RETURN (BioAPI *BioAPI_BSPUnload_PTR) (
    /* IN */ const BioAPI_UUID *BSPUuid,
    /* IN */ OPTIONAL BioAPI_EventHandler AppNotifyCallback,
    /* IN */ OPTIONAL void *AppNotifyCallbackCtx);


DLLAPI BioAPI_RETURN BioAPI BioAPI_BSPAttach (
    /* IN */ const BioAPI_UUID *BSPUuid,
    /* IN */ BioAPI_VERSION Version, 
    /* IN */ const BioAPI_UNIT_LIST_ELEMENT *UnitList,
    /* IN */ uint32_t NumUnits,
    /* OUT */ BioAPI_HANDLE *NewBSPHandle);


typedef BioAPI_RETURN (BioAPI *BioAPI_BSPAttach_PTR) (
    /* IN */ const BioAPI_UUID *BSPUuid,
    /* IN */ BioAPI_VERSION Version, 
    /* IN */ const BioAPI_UNIT_LIST_ELEMENT *UnitList,
    /* IN */ uint32_t NumUnits,
    /* OUT */ BioAPI_HANDLE *NewBSPHandle);


DLLAPI BioAPI_RETURN BioAPI BioAPI_BSPDetach (
    /* IN */ BioAPI_HANDLE BSPHandle);


typedef BioAPI_RETURN (BioAPI *BioAPI_BSPDetach_PTR) (
    /* IN */ BioAPI_HANDLE BSPHandle);


DLLAPI BioAPI_RETURN BioAPI BioAPI_QueryUnits (
    /* IN */ const BioAPI_UUID *BSPUuid,
    /* OUT */ BioAPI_UNIT_SCHEMA  **UnitSchemaArray,
    /* OUT */ uint32_t *NumberOfElements);


typedef BioAPI_RETURN (BioAPI *BioAPI_QueryUnits_PTR) (
    /* IN */ const BioAPI_UUID *BSPUuid,
    /* OUT */ BioAPI_UNIT_SCHEMA  **UnitSchemaArray,
    /* OUT */ uint32_t *NumberOfElements);

DLLAPI BioAPI_RETURN BioAPI BioAPI_EnumBFPs (
    /* OUT */ BioAPI_BFP_SCHEMA **BFPSchemaArray,
    /* OUT */ uint32_t *NumberOfElements);

typedef BioAPI_RETURN ( BioAPI *BioAPI_EnumBFPs_PTR) (
    /* OUT */ BioAPI_BFP_SCHEMA **BFPSchemaArray,
    /* OUT */ uint32_t *NumberOfElements);


DLLAPI BioAPI_RETURN BioAPI BioAPI_QueryBFPs (
    /* IN */ const BioAPI_UUID  *BSPUuid,
    /* OUT */ BioAPI_BFP_LIST_ELEMENT **BFPList,
    /* OUT */ uint32_t *NumberOfElements);


typedef BioAPI_RETURN (BioAPI *BioAPI_QueryBFPs_PTR) (
    /* IN */ const BioAPI_UUID  *BSPUuid,
    /* OUT */ BioAPI_BFP_LIST_ELEMENT **BFPList,
    /* OUT */ uint32_t *NumberOfElements);


DLLAPI BioAPI_RETURN BioAPI BioAPI_ControlUnit (
    /* IN */ BioAPI_HANDLE BSPHandle,
    /* IN */ BioAPI_UNIT_ID UnitID,
    /* IN */ uint32_t ControlCode,
    /* IN */ const BioAPI_DATA *InputData,
    /* OUT */ BioAPI_DATA *OutputData);


typedef BioAPI_RETURN (BioAPI *BioAPI_ControlUnit_PTR) (
    /* IN */ BioAPI_HANDLE BSPHandle,
    /* IN */ BioAPI_UNIT_ID UnitID,
    /* IN */ uint32_t ControlCode,
    /* IN */ const BioAPI_DATA *InputData,
    /* OUT */ BioAPI_DATA *OutputData);


//*****************************************************************************
// 8.2  BIR Handle Operations
//*****************************************************************************


DLLAPI BioAPI_RETURN BioAPI BioAPI_FreeBIRHandle (
    /* IN */ BioAPI_HANDLE BSPHandle,
    /* IN */ BioAPI_BIR_HANDLE   Handle); 


typedef BioAPI_RETURN (BioAPI *BioAPI_FreeBIRHandle_PTR) (
    /* IN */ BioAPI_HANDLE BSPHandle,
    /* IN */ BioAPI_BIR_HANDLE   Handle); 


DLLAPI BioAPI_RETURN BioAPI BioAPI_GetBIRFromHandle (
    /* IN */ BioAPI_HANDLE BSPHandle,
    /* IN */ BioAPI_BIR_HANDLE   Handle,
    /* OUT */ BioAPI_BIR *BIR); 


typedef BioAPI_RETURN (BioAPI *BioAPI_GetBIRFromHandle_PTR) (
    /* IN */ BioAPI_HANDLE BSPHandle,
    /* IN */ BioAPI_BIR_HANDLE   Handle,
    /* OUT */ BioAPI_BIR *BIR); 


DLLAPI BioAPI_RETURN BioAPI BioAPI_GetHeaderFromHandle (
    /* IN */ BioAPI_HANDLE BSPHandle,
    /* IN */ BioAPI_BIR_HANDLE   Handle,
    /* OUT */ BioAPI_BIR_HEADER *Header);


typedef BioAPI_RETURN (BioAPI *BioAPI_GetHeaderFromHandle_PTR) (
    /* IN */ BioAPI_HANDLE BSPHandle,
    /* IN */ BioAPI_BIR_HANDLE   Handle,
    /* OUT */ BioAPI_BIR_HEADER *Header);


//*****************************************************************************
// 8.3  Callback and Event Operations
//*****************************************************************************


DLLAPI BioAPI_RETURN BioAPI BioAPI_EnableEvents (
    /* IN */ BioAPI_HANDLE  BSPHandle,
    /* IN */ BioAPI_EVENT_MASK  Events);


typedef BioAPI_RETURN (BioAPI *BioAPI_EnableEvents_PTR) (
    /* IN */ BioAPI_HANDLE  BSPHandle,
    /* IN */ BioAPI_EVENT_MASK  Events);


DLLAPI BioAPI_RETURN BioAPI BioAPI_SetGUICallbacks (
    /* IN */ BioAPI_HANDLE    BSPHandle,
    /* IN */ OPTIONAL BioAPI_GUI_STREAMING_CALLBACK  GuiStreamingCallback, // optional see C.7.3    
    /* IN */ void   *GuiStreamingCallbackCtx, 
    /* IN */ BioAPI_GUI_STATE_CALLBACK  GuiStateCallback,
    /* IN */ void   *GuiStateCallbackCtx);


typedef BioAPI_RETURN (BioAPI *BioAPI_SetGUICallbacks_PTR) (
    /* IN */ BioAPI_HANDLE    BSPHandle,
    /* IN */ OPTIONAL BioAPI_GUI_STREAMING_CALLBACK  GuiStreamingCallback,
    /* IN */ void   *GuiStreamingCallbackCtx, 
    /* IN */ BioAPI_GUI_STATE_CALLBACK  GuiStateCallback,
    /* IN */ void   *GuiStateCallbackCtx);



//*****************************************************************************
// 8.4  Biometric Operations
//*****************************************************************************


DLLAPI BioAPI_RETURN BioAPI BioAPI_Capture (
    /* IN */ BioAPI_HANDLE BSPHandle,
    /* IN */ BioAPI_BIR_PURPOSE   Purpose,
    /* IN */ OPTIONAL BioAPI_BIR_SUBTYPE Subtype,
    /* IN */ OPTIONAL const BioAPI_BIR_BIOMETRIC_DATA_FORMAT *OutputFormat,
    /* OUT */ BioAPI_BIR_HANDLE *CapturedBIR,
    /* IN */ int32_t Timeout,
    /* OUT */ /* OPTIONAL */ BioAPI_BIR_HANDLE *AuditData);


typedef BioAPI_RETURN (BioAPI *BioAPI_Capture_PTR) (
    /* IN */ BioAPI_HANDLE BSPHandle,
    /* IN */ BioAPI_BIR_PURPOSE   Purpose,
    /* IN */ OPTIONAL BioAPI_BIR_SUBTYPE Subtype,
    /* IN */ OPTIONAL const BioAPI_BIR_BIOMETRIC_DATA_FORMAT *OutputFormat,
    /* OUT */ BioAPI_BIR_HANDLE *CapturedBIR,
    /* IN */ int32_t Timeout,
    /* OUT */ /* OPTIONAL */ BioAPI_BIR_HANDLE *AuditData);

 

DLLAPI BioAPI_RETURN BioAPI BioAPI_CreateTemplate (
    /* IN */ BioAPI_HANDLE BSPHandle,
    /* IN */ const BioAPI_INPUT_BIR *CapturedBIR,
    /* IN */ OPTIONAL const BioAPI_INPUT_BIR  *ReferenceTemplate,
    /* IN */ OPTIONAL const BioAPI_BIR_BIOMETRIC_DATA_FORMAT *OutputFormat,
    /* OUT */ BioAPI_BIR_HANDLE   *NewTemplate,
    /* IN */ OPTIONAL const BioAPI_DATA *Payload,
    /* OUT */ /* OPTIONAL */ BioAPI_UUID *TemplateUUID);


typedef BioAPI_RETURN (BioAPI *BioAPI_CreateTemplate_PTR) (
    /* IN */ BioAPI_HANDLE BSPHandle,
    /* IN */ const BioAPI_INPUT_BIR *CapturedBIR,
    /* IN */ OPTIONAL const BioAPI_INPUT_BIR  *ReferenceTemplate,
    /* IN */ OPTIONAL const BioAPI_BIR_BIOMETRIC_DATA_FORMAT *OutputFormat,
    /* OUT */ BioAPI_BIR_HANDLE   *NewTemplate,
    /* IN */ OPTIONAL const BioAPI_DATA *Payload,
    /* OUT */ /* OPTIONAL */ BioAPI_UUID *TemplateUUID);


DLLAPI BioAPI_RETURN BioAPI BioAPI_Process (
    /* IN */ BioAPI_HANDLE BSPHandle,
    /* IN */ const BioAPI_INPUT_BIR  *CapturedBIR,
    /* IN */ OPTIONAL const BioAPI_BIR_BIOMETRIC_DATA_FORMAT *OutputFormat,
    /* OUT */ BioAPI_BIR_HANDLE *ProcessedBIR);


typedef BioAPI_RETURN (BioAPI *BioAPI_Process_PTR) (
    /* IN */ BioAPI_HANDLE BSPHandle,
    /* IN */ const BioAPI_INPUT_BIR  *CapturedBIR,
    /* IN */ OPTIONAL const BioAPI_BIR_BIOMETRIC_DATA_FORMAT *OutputFormat,
    /* OUT */ BioAPI_BIR_HANDLE *ProcessedBIR);


DLLAPI BioAPI_RETURN BioAPI BioAPI_ProcessWithAuxBIR (
    /* IN */ BioAPI_HANDLE BSPHandle,
    /* IN */ const BioAPI_INPUT_BIR *CapturedBIR,
    /* IN */ const BioAPI_INPUT_BIR *AuxiliaryData,
    /* IN */ OPTIONAL const BioAPI_BIR_BIOMETRIC_DATA_FORMAT *OutputFormat,
    /* OUT */ BioAPI_BIR_HANDLE *ProcessedBIR); 


typedef BioAPI_RETURN (BioAPI *BioAPI_ProcessWithAuxBIR_PTR) (
    /* IN */ BioAPI_HANDLE BSPHandle,
    /* IN */ const BioAPI_INPUT_BIR *CapturedBIR,
    /* IN */ const BioAPI_INPUT_BIR *AuxiliaryData,
    /* IN */ OPTIONAL const BioAPI_BIR_BIOMETRIC_DATA_FORMAT *OutputFormat,
    /* OUT */ BioAPI_BIR_HANDLE *ProcessedBIR); 


DLLAPI BioAPI_RETURN BioAPI BioAPI_VerifyMatch (
    /* IN */ BioAPI_HANDLE BSPHandle,
    /* IN */ BioAPI_FMR MaxFMRRequested, 
    /* IN */ const BioAPI_INPUT_BIR *ProcessedBIR,
    /* IN */ const BioAPI_INPUT_BIR *ReferenceTemplate,
    /* OUT */ /* OPTIONAL */ BioAPI_BIR_HANDLE *AdaptedBIR,
    /* OUT */ BioAPI_BOOL *Result,
    /* OUT */ BioAPI_FMR *FMRAchieved,
    /* OUT */ /* OPTIONAL */ BioAPI_DATA *Payload);


typedef BioAPI_RETURN (BioAPI *BioAPI_VerifyMatch_PTR) (
    /* IN */ BioAPI_HANDLE BSPHandle,
    /* IN */ BioAPI_FMR MaxFMRRequested, 
    /* IN */ const BioAPI_INPUT_BIR *ProcessedBIR,
    /* IN */ const BioAPI_INPUT_BIR *ReferenceTemplate,
    /* OUT */ /* OPTIONAL */ BioAPI_BIR_HANDLE *AdaptedBIR,
    /* OUT */ BioAPI_BOOL *Result,
    /* OUT */ BioAPI_FMR *FMRAchieved,
    /* OUT */ /* OPTIONAL */ BioAPI_DATA *Payload);


DLLAPI BioAPI_RETURN BioAPI BioAPI_IdentifyMatch (
    /* IN */ BioAPI_HANDLE BSPHandle,
    /* IN */ BioAPI_FMR MaxFMRRequested,
    /* IN */ const BioAPI_INPUT_BIR *ProcessedBIR,
    /* IN */ const BioAPI_IDENTIFY_POPULATION   *Population,
    /* IN */ uint32_t TotalNumberOfTemplates,
    /* IN */ BioAPI_BOOL Binning,
    /* IN */  uint32_t MaxNumberOfResults,
    /* OUT */ uint32_t *NumberOfResults,
    /* OUT */ BioAPI_CANDIDATE **Candidates,
    /* IN */ int32_t Timeout);


typedef BioAPI_RETURN (BioAPI *BioAPI_IdentifyMatch_PTR) (
    /* IN */ BioAPI_HANDLE BSPHandle,
    /* IN */ BioAPI_FMR MaxFMRRequested,
    /* IN */ const BioAPI_INPUT_BIR *ProcessedBIR,
    /* IN */ const BioAPI_IDENTIFY_POPULATION   *Population,
    /* IN */ uint32_t TotalNumberOfTemplates,
    /* IN */ BioAPI_BOOL Binning,
    /* IN */  uint32_t MaxNumberOfResults,
    /* OUT */ uint32_t *NumberOfResults,
    /* OUT */ BioAPI_CANDIDATE **Candidates,
    /* IN */ int32_t Timeout);



DLLAPI BioAPI_RETURN BioAPI BioAPI_Enroll (
    /* IN */ BioAPI_HANDLE BSPHandle,
    /* IN */ BioAPI_BIR_PURPOSE Purpose,
    /* IN */ OPTIONAL BioAPI_BIR_SUBTYPE Subtype,
    /* IN */ OPTIONAL const BioAPI_BIR_BIOMETRIC_DATA_FORMAT *OutputFormat,
    /* IN */ OPTIONAL const BioAPI_INPUT_BIR  *ReferenceTemplate,
    /* OUT */ BioAPI_BIR_HANDLE *NewTemplate,
    /* IN */ OPTIONAL const BioAPI_DATA *Payload,
    /* IN */ int32_t Timeout,
    /* OUT */ /* OPTIONAL */ BioAPI_BIR_HANDLE *AuditData,
    /* OUT */ /* OPTIONAL */ BioAPI_UUID *TemplateUUID);


typedef BioAPI_RETURN (BioAPI *BioAPI_Enroll_PTR) (
    /* IN */ BioAPI_HANDLE BSPHandle,
    /* IN */ BioAPI_BIR_PURPOSE Purpose,
    /* IN */ OPTIONAL BioAPI_BIR_SUBTYPE Subtype,
    /* IN */ OPTIONAL const BioAPI_BIR_BIOMETRIC_DATA_FORMAT *OutputFormat,
    /* IN */ OPTIONAL const BioAPI_INPUT_BIR  *ReferenceTemplate,
    /* OUT */ BioAPI_BIR_HANDLE *NewTemplate,
    /* IN */ OPTIONAL const BioAPI_DATA *Payload,
    /* IN */ int32_t Timeout,
    /* OUT */ /* OPTIONAL */ BioAPI_BIR_HANDLE *AuditData,
    /* OUT */ /* OPTIONAL */ BioAPI_UUID *TemplateUUID);


DLLAPI BioAPI_RETURN BioAPI BioAPI_Verify (
    /* IN */ BioAPI_HANDLE BSPHandle,
    /* IN */ BioAPI_FMR MaxFMRRequested,
    /* IN */ const BioAPI_INPUT_BIR *ReferenceTemplate,
    /* IN */ OPTIONAL BioAPI_BIR_SUBTYPE Subtype,
    /* OUT */ /* OPTIONAL */ BioAPI_BIR_HANDLE *AdaptedBIR,
    /* OUT */ BioAPI_BOOL *Result,
    /* OUT */ BioAPI_FMR *FMRAchieved,
    /* OUT */ /* OPTIONAL */ BioAPI_DATA *Payload, 
    /* IN */ int32_t Timeout,
    /* OUT */ /* OPTIONAL */ BioAPI_BIR_HANDLE *AuditData);


typedef BioAPI_RETURN (BioAPI *BioAPI_Verify_PTR) (
    /* IN */ BioAPI_HANDLE BSPHandle,
    /* IN */ BioAPI_FMR MaxFMRRequested,
    /* IN */ const BioAPI_INPUT_BIR *ReferenceTemplate,
    /* IN */ OPTIONAL BioAPI_BIR_SUBTYPE Subtype,
    /* OUT */ /* OPTIONAL */ BioAPI_BIR_HANDLE *AdaptedBIR,
    /* OUT */ BioAPI_BOOL *Result,
    /* OUT */ BioAPI_FMR *FMRAchieved,
    /* OUT */ /* OPTIONAL */ BioAPI_DATA *Payload, 
    /* IN */ int32_t Timeout,
    /* OUT */ /* OPTIONAL */ BioAPI_BIR_HANDLE *AuditData);


DLLAPI BioAPI_RETURN BioAPI BioAPI_Identify (
    /* IN */ BioAPI_HANDLE BSPHandle,
    /* IN */ BioAPI_FMR MaxFMRRequested,
    /* IN */ OPTIONAL BioAPI_BIR_SUBTYPE Subtype,
    /* IN */ const BioAPI_IDENTIFY_POPULATION   *Population,
    /* IN */ uint32_t TotalNumberOfTemplates,
    /* IN */ BioAPI_BOOL Binning,
    /* IN */  uint32_t MaxNumberOfResults,
    /* OUT */ uint32_t *NumberOfResults,
    /* OUT */ BioAPI_CANDIDATE **Candidates,
    /* IN */ int32_t Timeout,
    /* OUT */ /* OPTIONAL */ BioAPI_BIR_HANDLE *AuditData);


typedef BioAPI_RETURN (BioAPI *BioAPI_Identify_PTR) (
    /* IN */ BioAPI_HANDLE BSPHandle,
    /* IN */ BioAPI_FMR MaxFMRRequested,
    /* IN */ OPTIONAL BioAPI_BIR_SUBTYPE Subtype,
    /* IN */ const BioAPI_IDENTIFY_POPULATION   *Population,
    /* IN */ uint32_t TotalNumberOfTemplates,
    /* IN */ BioAPI_BOOL Binning,
    /* IN */  uint32_t MaxNumberOfResults,
    /* OUT */ uint32_t *NumberOfResults,
    /* OUT */ BioAPI_CANDIDATE **Candidates,
    /* IN */ int32_t Timeout,
    /* OUT */ /* OPTIONAL */ BioAPI_BIR_HANDLE *AuditData);


DLLAPI BioAPI_RETURN BioAPI BioAPI_Import (
    /* IN */ BioAPI_HANDLE BSPHandle,
    /* IN */ const BioAPI_DATA *InputData,
    /* IN */ const BioAPI_BIR_BIOMETRIC_DATA_FORMAT *InputFormat,
    /* IN */ OPTIONAL const BioAPI_BIR_BIOMETRIC_DATA_FORMAT *OutputFormat,
    /* IN */ BioAPI_BIR_PURPOSE Purpose,
    /* OUT */ BioAPI_BIR_HANDLE *ConstructedBIR);


typedef BioAPI_RETURN (BioAPI *BioAPI_Import_PTR) (
    /* IN */ BioAPI_HANDLE BSPHandle,
    /* IN */ const BioAPI_DATA *InputData,
    /* IN */ const BioAPI_BIR_BIOMETRIC_DATA_FORMAT *InputFormat,
    /* IN */ OPTIONAL const BioAPI_BIR_BIOMETRIC_DATA_FORMAT *OutputFormat,
    /* IN */ BioAPI_BIR_PURPOSE Purpose,
    /* OUT */ BioAPI_BIR_HANDLE *ConstructedBIR);


DLLAPI BioAPI_RETURN BioAPI BioAPI_PresetIdentifyPopulation (
    /* IN */ BioAPI_HANDLE BSPHandle,
    /* IN */ const BioAPI_IDENTIFY_POPULATION *Population);


typedef BioAPI_RETURN (BioAPI *BioAPI_PresetIdentifyPopulation_PTR) (
    /* IN */ BioAPI_HANDLE BSPHandle,
    /* IN */ const BioAPI_IDENTIFY_POPULATION *Population);


DLLAPI BioAPI_RETURN BioAPI BioAPI_DbOpen (
    /* IN */ BioAPI_HANDLE BSPHandle,
    /* IN */ const BioAPI_UUID *DbUuid,
    /* IN */ BioAPI_DB_ACCESS_TYPE  AccessRequest,
    /* OUT */ BioAPI_DB_HANDLE *DbHandle,
    /* OUT */ BioAPI_DB_MARKER_HANDLE *MarkerHandle);


typedef BioAPI_RETURN (BioAPI *BioAPI_DbOpen_PTR) (
    /* IN */ BioAPI_HANDLE BSPHandle,
    /* IN */ const BioAPI_UUID *DbUuid,
    /* IN */ BioAPI_DB_ACCESS_TYPE  AccessRequest,
    /* OUT */ BioAPI_DB_HANDLE *DbHandle,
    /* OUT */ BioAPI_DB_MARKER_HANDLE *MarkerHandle);

DLLAPI BioAPI_RETURN BioAPI BioAPI_DbClose (
    /* IN */ BioAPI_HANDLE BSPHandle,
    /* IN */ BioAPI_DB_HANDLE DbHandle); 


typedef BioAPI_RETURN (BioAPI *BioAPI_DbClose_PTR) (
    /* IN */ BioAPI_HANDLE BSPHandle,
    /* IN */ BioAPI_DB_HANDLE DbHandle); 


DLLAPI BioAPI_RETURN BioAPI BioAPI_DbCreate (
    /* IN */ BioAPI_HANDLE BSPHandle,
    /* IN */ const BioAPI_UUID *DbUuid,
    /* IN */ uint32_t NumberOfRecords,
    /* IN */ BioAPI_DB_ACCESS_TYPE AccessRequest,
    /* OUT */ BioAPI_DB_HANDLE *DbHandle);


typedef BioAPI_RETURN (BioAPI *BioAPI_DbCreate_PTR) (
    /* IN */ BioAPI_HANDLE BSPHandle,
    /* IN */ const BioAPI_UUID *DbUuid,
    /* IN */ uint32_t NumberOfRecords,
    /* IN */ BioAPI_DB_ACCESS_TYPE AccessRequest,
    /* OUT */ BioAPI_DB_HANDLE *DbHandle);

DLLAPI BioAPI_RETURN BioAPI BioAPI_DbDelete (
    /* IN */ BioAPI_HANDLE BSPHandle,
    /* IN */ const BioAPI_UUID *DbUuid);


typedef BioAPI_RETURN (BioAPI *BioAPI_DbDelete_PTR) (
    /* IN */ BioAPI_HANDLE BSPHandle,
    /* IN */ const BioAPI_UUID *DbUuid);


DLLAPI BioAPI_RETURN BioAPI BioAPI_DbSetMarker (
    /* IN */ BioAPI_HANDLE BSPHandle,
    /* IN */ BioAPI_DB_HANDLE DbHandle,
    /* IN */ const BioAPI_UUID *KeyValue,
    /* IN */  BioAPI_DB_MARKER_HANDLE MarkerHandle);


typedef BioAPI_RETURN (BioAPI *BioAPI_DbSetMarker_PTR) (
    /* IN */ BioAPI_HANDLE BSPHandle,
    /* IN */ BioAPI_DB_HANDLE DbHandle,
    /* IN */ const BioAPI_UUID *KeyValue,
    /* IN */  BioAPI_DB_MARKER_HANDLE MarkerHandle);


DLLAPI BioAPI_RETURN BioAPI BioAPI_DbFreeMarker (
    /* IN */ BioAPI_HANDLE BSPHandle,
    /* IN */ BioAPI_DB_MARKER_HANDLE MarkerHandle); 


typedef BioAPI_RETURN (BioAPI *BioAPI_DbFreeMarker_PTR) (
    /* IN */ BioAPI_HANDLE BSPHandle,
    /* IN */ BioAPI_DB_MARKER_HANDLE MarkerHandle); 


DLLAPI BioAPI_RETURN BioAPI BioAPI_DbStoreBIR (
    /* IN */ BioAPI_HANDLE BSPHandle,
    /* IN */ const BioAPI_INPUT_BIR *BIRToStore,
    /* IN */ BioAPI_DB_HANDLE DbHandle,
    /* OUT */ BioAPI_UUID *BirUuid);


typedef BioAPI_RETURN (BioAPI *BioAPI_DbStoreBIR_PTR) (
    /* IN */ BioAPI_HANDLE BSPHandle,
    /* IN */ const BioAPI_INPUT_BIR *BIRToStore,
    /* IN */ BioAPI_DB_HANDLE DbHandle,
    /* OUT */ BioAPI_UUID *BirUuid);


DLLAPI BioAPI_RETURN BioAPI BioAPI_DbGetBIR (
    /* IN */ BioAPI_HANDLE BSPHandle,
    /* IN */ BioAPI_DB_HANDLE DbHandle,
    /* IN */ const BioAPI_UUID *KeyValue,
    /* OUT */ BioAPI_BIR_HANDLE   *RetrievedBIR,
    /* OUT */ BioAPI_DB_MARKER_HANDLE *MarkerHandle);


typedef BioAPI_RETURN (BioAPI *BioAPI_DbGetBIR_PTR) (
    /* IN */ BioAPI_HANDLE BSPHandle,
    /* IN */ BioAPI_DB_HANDLE DbHandle,
    /* IN */ const BioAPI_UUID *KeyValue,
    /* OUT */ BioAPI_BIR_HANDLE   *RetrievedBIR,
    /* OUT */ BioAPI_DB_MARKER_HANDLE *MarkerHandle);


DLLAPI BioAPI_RETURN BioAPI BioAPI_DbGetNextBIR (
    /* IN */ BioAPI_HANDLE BSPHandle,
    /* IN */ BioAPI_DB_HANDLE DbHandle,
    /* IN */ BioAPI_DB_MARKER_HANDLE MarkerHandle,
    /* OUT */ BioAPI_BIR_HANDLE *RetrievedBIR,
    /* OUT */ BioAPI_UUID *BirUuid);


typedef BioAPI_RETURN (BioAPI *BioAPI_DbGetNextBIR_PTR) (
    /* IN */ BioAPI_HANDLE BSPHandle,
    /* IN */ BioAPI_DB_HANDLE DbHandle,
    /* IN */ BioAPI_DB_MARKER_HANDLE MarkerHandle,
    /* OUT */ BioAPI_BIR_HANDLE *RetrievedBIR,
    /* OUT */ BioAPI_UUID *BirUuid);


DLLAPI BioAPI_RETURN BioAPI BioAPI_DbDeleteBIR (
    /* IN */ BioAPI_HANDLE BSPHandle,
    /* IN */ BioAPI_DB_HANDLE DbHandle,
    /* IN */ const BioAPI_UUID *KeyValue);


typedef BioAPI_RETURN (BioAPI *BioAPI_DbDeleteBIR_PTR) (
    /* IN */ BioAPI_HANDLE BSPHandle,
    /* IN */ BioAPI_DB_HANDLE DbHandle,
    /* IN */ const BioAPI_UUID *KeyValue);



DLLAPI BioAPI_RETURN BioAPI BioAPI_SetPowerMode (
    /* IN */ BioAPI_HANDLE BSPHandle,
    /* IN */ BioAPI_UNIT_ID UnitId,
    /* IN */ BioAPI_POWER_MODE   PowerMode);


typedef BioAPI_RETURN (BioAPI *BioAPI_SetPowerMode_PTR) (
    /* IN */ BioAPI_HANDLE BSPHandle,
    /* IN */ BioAPI_UNIT_ID UnitId,
    /* IN */ BioAPI_POWER_MODE   PowerMode);


DLLAPI BioAPI_RETURN BioAPI BioAPI_SetIndicatorStatus (
    /* IN */ BioAPI_HANDLE BSPHandle,
    /* IN */ BioAPI_UNIT_ID UnitId,
    /* IN */ BioAPI_INDICATOR_STATUS   IndicatorStatus);


typedef BioAPI_RETURN (BioAPI *BioAPI_SetIndicatorStatus_PTR) (
    /* IN */ BioAPI_HANDLE BSPHandle,
    /* IN */ BioAPI_UNIT_ID UnitId,
    /* IN */ BioAPI_INDICATOR_STATUS   IndicatorStatus);


DLLAPI BioAPI_RETURN BioAPI BioAPI_GetIndicatorStatus (
    /* IN */ BioAPI_HANDLE BSPHandle,
    /* IN */ BioAPI_UNIT_ID UnitId,
    /* OUT */ BioAPI_INDICATOR_STATUS *IndicatorStatus);


typedef BioAPI_RETURN (BioAPI *BioAPI_GetIndicatorStatus_PTR) (
    /* IN */ BioAPI_HANDLE BSPHandle,
    /* IN */ BioAPI_UNIT_ID UnitId,
    /* OUT */ BioAPI_INDICATOR_STATUS *IndicatorStatus);


DLLAPI BioAPI_RETURN BioAPI BioAPI_CalibrateSensor (
    /* IN */ BioAPI_HANDLE BSPHandle,
    /* IN */ int32_t Timeout);


typedef BioAPI_RETURN (BioAPI *BioAPI_CalibrateSensor_PTR) (
    /* IN */ BioAPI_HANDLE BSPHandle,
    /* IN */ int32_t Timeout);



DLLAPI BioAPI_RETURN BioAPI BioAPI_Cancel (
    /* IN */ BioAPI_HANDLE BSPHandle);


typedef BioAPI_RETURN (BioAPI *BioAPI_Cancel_PTR) (
    /* IN */ BioAPI_HANDLE BSPHandle);


DLLAPI BioAPI_RETURN BioAPI BioAPI_Free (
    /* IN */ void* Ptr);

typedef BioAPI_RETURN (BioAPI *BioAPI_Free_PTR) (
    void* Ptr);


#ifdef __cplusplus
}
#endif

#endif  /* _BIOAPI_API_H_INCLUDED */
