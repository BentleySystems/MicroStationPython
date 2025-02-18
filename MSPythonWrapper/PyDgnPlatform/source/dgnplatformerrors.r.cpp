/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnPlatform\source\dgnplatformerrors.r.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <DgnPlatform/DgnPlatformErrors.r.h>

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_DgnPlatformErrors_r(py::module_& m)
    {
    //===================================================================================
    // enum BentleyStatus
    py::enum_< BentleyStatus>(m, "BentleyStatus", py::arithmetic())
        .value("eSUCCESS", SUCCESS)
        .value("eBSISUCCESS", BSISUCCESS)
        .value("eERROR", ERROR)
        .value("eBSIERROR", BSIERROR)
        .export_values();

    //===================================================================================
    // enum DgnErrorCategories
    py::enum_< DgnErrorCategories>(m, "DgnErrorCategories", py::arithmetic())
        .value("eDGNMODEL_ERROR_BASE", DGNMODEL_ERROR_BASE)
        .value("eDGNLOAD_ERROR_BASE", DGNLOAD_ERROR_BASE)
        .value("eDGNOPEN_STATUS_BASE", DGNOPEN_STATUS_BASE)
        .value("eDGNFILE_ERROR_BASE", DGNFILE_ERROR_BASE)
        .value("eDGNSTREAM_ERROR_BASE", DGNSTREAM_ERROR_BASE)
        .value("eDGNHISTORY_ERROR_BASE", DGNHISTORY_ERROR_BASE)
        .value("eDGNSHAREDFILE_ERROR_BASE", DGNSHAREDFILE_ERROR_BASE)
        .value("eDGNELEMENT_ERROR_BASE", DGNELEMENT_ERROR_BASE)
        .value("eGEOCOORD_ATTACH_ERROR_BASE", GEOCOORD_ATTACH_ERROR_BASE)
        .value("eVIEW_INFO_ERROR_BASE", VIEW_INFO_ERROR_BASE)
        .value("eVIEW_GROUP_ERROR_BASE", VIEW_GROUP_ERROR_BASE)
        .value("eNAMED_VIEW_ERROR_BASE", NAMED_VIEW_ERROR_BASE)
        .value("eVIEW_GROUP_MANAGER_ERROR_BASE", VIEW_GROUP_MANAGER_ERROR_BASE)
        .value("eLINESTYLE_ERROR_BASE", LINESTYLE_ERROR_BASE)
        .value("eNAMED_GROUP_ERROR_BASE", NAMED_GROUP_ERROR_BASE)
        .value("eGEOREFERENCE_ERROR_BASE", GEOREFERENCE_ERROR_BASE)
        .value("eVIEWFRUSTUM_ERROR_BASE", VIEWFRUSTUM_ERROR_BASE)
        .value("eVIEWPORT_ERROR_BASE", VIEWPORT_ERROR_BASE)
        .value("eREGISTERED_APP_ERROR_BASE", REGISTERED_APP_ERROR_BASE)
        .value("ePATHNAME_ERROR_BASE", PATHNAME_ERROR_BASE)
        .value("eANNOTATIONATTACHMENT_ERROR_BASE", ANNOTATIONATTACHMENT_ERROR_BASE)
        .value("eREFRANGEPATH_ERROR_BASE", REFRANGEPATH_ERROR_BASE)
        .value("eDETAILINGSYMBOL_ERROR_BASE", DETAILINGSYMBOL_ERROR_BASE)
        .value("eDCMODEL_ERROR_BASE", DCMODEL_ERROR_BASE)
        .value("eSHEETINDEX_ERROR_BASE", SHEETINDEX_ERROR_BASE)
        .value("eWORKSET_ERROR_BASE", WORKSET_ERROR_BASE)
        .export_values();

    //===================================================================================
    // enum DgnFileStatus
    py::enum_< DgnFileStatus>(m, "DgnFileStatus", py::arithmetic())
        .value("eDGNFILE_STATUS_Success", DGNFILE_STATUS_Success)
        .value("eDGNFILE_STATUS_UnknownError", DGNFILE_STATUS_UnknownError)

        .value("eDGNOPEN_STATUS_SharingViolation", DGNOPEN_STATUS_SharingViolation)
        .value("eDGNOPEN_STATUS_AccessViolation", DGNOPEN_STATUS_AccessViolation)
        .value("eDGNOPEN_STATUS_AlreadyOpen", DGNOPEN_STATUS_AlreadyOpen)
        .value("eDGNOPEN_STATUS_FileAlreadyExists", DGNOPEN_STATUS_FileAlreadyExists)
        .value("eDGNOPEN_STATUS_BadFilename", DGNOPEN_STATUS_BadFilename)
        .value("eDGNOPEN_STATUS_UnrecognizedFormat", DGNOPEN_STATUS_UnrecognizedFormat)
        .value("eDGNOPEN_STATUS_VersionMismatch", DGNOPEN_STATUS_VersionMismatch)

        .value("eDGNOPEN_STATUS_TooManyOpenFiles", DGNOPEN_STATUS_TooManyOpenFiles)
        .value("eDGNOPEN_STATUS_FileNotFound", DGNOPEN_STATUS_FileNotFound)
        .value("eDGNOPEN_STATUS_OpenCanceled", DGNOPEN_STATUS_OpenCanceled)
        .value("eDGNOPEN_STATUS_BAD_FILE", DGNOPEN_STATUS_BAD_FILE)
        .value("eFILE_OPEN_STATUS_UnableToLoadInterface", FILE_OPEN_STATUS_UnableToLoadInterface)
        .value("eFILE_OPEN_STATUS_UnableToOpenSeed", FILE_OPEN_STATUS_UnableToOpenSeed)
        .value("eDWGOPEN_STATUS_InvalidSeed", DWGOPEN_STATUS_InvalidSeed)
        .value("eDGNOPEN_STATUS_InvalidOperationForNestedFile", DGNOPEN_STATUS_InvalidOperationForNestedFile)

        .value("eDGNOPEN_STATUS_InvalidOperationForNonNestedFile", DGNOPEN_STATUS_InvalidOperationForNonNestedFile)
        .value("eDGNOPEN_STATUS_IsEncrypted", DGNOPEN_STATUS_IsEncrypted)
        .value("eDGNOPEN_STATUS_CorruptFile", DGNOPEN_STATUS_CorruptFile)
        .value("eDGNOPEN_STATUS_FileHasNewFeatures", DGNOPEN_STATUS_FileHasNewFeatures)
        .value("eDGNOPEN_STATUS_SaveToPerformed", DGNOPEN_STATUS_SaveToPerformed)
        .value("eDGNOPEN_STATUS_InsecureEnvironment", DGNOPEN_STATUS_InsecureEnvironment)
        .value("eDWGOPEN_STATUS_BadFile", DWGOPEN_STATUS_BadFile)
        .value("eDWGOPEN_STATUS_CannotOpenSeed", DWGOPEN_STATUS_CannotOpenSeed)
        .value("eDWGSAVE_STATUS_UserAbort", DWGSAVE_STATUS_UserAbort)
        .value("eDGNOPEN_STATUS_ProjectMismatch", DGNOPEN_STATUS_ProjectMismatch)

        .value("eDGNFILE_ERROR_NotLoaded", DGNFILE_ERROR_NotLoaded)
        .value("eDGNFILE_ERROR_NotOpen", DGNFILE_ERROR_NotOpen)
        .value("eDGNFILE_ERROR_AlreadyLoaded", DGNFILE_ERROR_AlreadyLoaded)
        .value("eDGNFILE_ERROR_HasChanges", DGNFILE_ERROR_HasChanges)
        .value("eDGNFILE_ERROR_BadArg", DGNFILE_ERROR_BadArg)
        .value("eDGNFILE_ERROR_ReadError", DGNFILE_ERROR_ReadError)
        .value("eDGNFILE_ERROR_WriteError", DGNFILE_ERROR_WriteError)
        .value("eDGNFILE_ERROR_CompressionError", DGNFILE_ERROR_CompressionError)
        .value("eDGNFILE_ERROR_ModelAlreadyLoaded", DGNFILE_ERROR_ModelAlreadyLoaded)
        .value("eDGNFILE_ERROR_UnknownFormat", DGNFILE_ERROR_UnknownFormat)
        .value("eDGNFILE_ERROR_NotOpenForWrite", DGNFILE_ERROR_NotOpenForWrite)
        .value("eDGNFILE_ERROR_NoSuchModel", DGNFILE_ERROR_NoSuchModel)
        .value("eDGNFILE_ERROR_NotLocked", DGNFILE_ERROR_NotLocked)
        .value("eDGNFILE_ERROR_UnableToImportSeed", DGNFILE_ERROR_UnableToImportSeed)
        .value("eDGNFILE_ERROR_ModelLoadError", DGNFILE_ERROR_ModelLoadError)
        .value("eDGNFILE_ERROR_RenameError", DGNFILE_ERROR_RenameError)
        .value("eDGNFILE_ERROR_CopyError", DGNFILE_ERROR_CopyError)
        .value("eDGNFILE_ERROR_ModelNotFilled", DGNFILE_ERROR_ModelNotFilled)

        .value("eDGNFILE_ERROR_NoModel", DGNFILE_ERROR_NoModel)
        .value("eDGNFILE_ERROR_InvalidOperationForNestedFile", DGNFILE_ERROR_InvalidOperationForNestedFile)
        .value("eDGNFILE_ERROR_RightNotGranted", DGNFILE_ERROR_RightNotGranted)
        .value("eDGNFILE_ERROR_PasswordAlreadyUsed", DGNFILE_ERROR_PasswordAlreadyUsed)
        .value("eDGNFILE_ERROR_CertificatePurpose", DGNFILE_ERROR_CertificatePurpose)
        .value("eDGNFILE_ERROR_NeverWriteable", DGNFILE_ERROR_NeverWriteable)
        .value("eDGNFILE_ERROR_NoDictionaryModelReader", DGNFILE_ERROR_NoDictionaryModelReader)

        .value("eDGNLOAD_STATUS_Badname", DGNLOAD_STATUS_Badname)
        .value("eDGNLOAD_STATUS_NotOpened", DGNLOAD_STATUS_NotOpened)
        .value("eDGNLOAD_STATUS_EndOfDgn", DGNLOAD_STATUS_EndOfDgn)
        .value("eDGNLOAD_STATUS_OutOfData", DGNLOAD_STATUS_OutOfData)
        .value("eDGNLOAD_STATUS_BadWtf", DGNLOAD_STATUS_BadWtf)

        .value("eDGNPATHNAME_AlreadyExists", DGNPATHNAME_AlreadyExists)
        .value("eDGNPATHNAME_DoesNotExist", DGNPATHNAME_DoesNotExist)
        .value("eDGNPATHNAME_CantCreate", DGNPATHNAME_CantCreate)
        .value("eDGNPATHNAME_NotEmpty", DGNPATHNAME_NotEmpty)
        .value("eDGNPATHNAME_IllegalName", DGNPATHNAME_IllegalName)
        .value("eDGNPATHNAME_CantDeleteFile", DGNPATHNAME_CantDeleteFile)
        .value("eDGNPATHNAME_CantDeleteDir", DGNPATHNAME_CantDeleteDir)
        .export_values();

    //===================================================================================
    // enum DgnModelStatus
    py::enum_< DgnModelStatus>(m, "DgnModelStatus", py::arithmetic())
        .value("eDGNMODEL_STATUS_Success", DGNMODEL_STATUS_Success)
        .value("eDGNMODEL_STATUS_ReadOnly", DGNMODEL_STATUS_ReadOnly)
        .value("eDGNMODEL_STATUS_BadElement", DGNMODEL_STATUS_BadElement)
        .value("eDGNMODEL_STATUS_BadRequest", DGNMODEL_STATUS_BadRequest)
        .value("eDGNMODEL_STATUS_OutOfMemory", DGNMODEL_STATUS_OutOfMemory)
        .value("eDGNMODEL_STATUS_ElementNotFound", DGNMODEL_STATUS_ElementNotFound)
        .value("eDGNMODEL_STATUS_BadModelPtr", DGNMODEL_STATUS_BadModelPtr)
        .value("eDGNMODEL_STATUS_IdNotFound", DGNMODEL_STATUS_IdNotFound)
        .value("eDGNMODEL_STATUS_IdExists", DGNMODEL_STATUS_IdExists)
        .value("eDGNMODEL_STATUS_InvalidId", DGNMODEL_STATUS_InvalidId)
        .value("eDGNMODEL_STATUS_CircularDependency", DGNMODEL_STATUS_CircularDependency)
        .value("eDGNMODEL_STATUS_NotEnabled", DGNMODEL_STATUS_NotEnabled)
        .value("eDGNMODEL_STATUS_ComplexComponent", DGNMODEL_STATUS_ComplexComponent)
        .value("eDGNMODEL_STATUS_WrongElemId", DGNMODEL_STATUS_WrongElemId)
        .value("eDGNMODEL_STATUS_IsInUse", DGNMODEL_STATUS_IsInUse)
        .value("eDGNMODEL_STATUS_NotFound", DGNMODEL_STATUS_NotFound)
        .value("eDGNMODEL_STATUS_InvalidDependency", DGNMODEL_STATUS_InvalidDependency)
        .value("eDGNMODEL_STATUS_NotComplexHeader", DGNMODEL_STATUS_NotComplexHeader)
        .value("eDGNMODEL_STATUS_2d3dMismatch", DGNMODEL_STATUS_2d3dMismatch)
        .value("eDGNMODEL_STATUS_ReplacingDeleted", DGNMODEL_STATUS_ReplacingDeleted)
        .value("eDGNMODEL_STATUS_OversizeElement", DGNMODEL_STATUS_OversizeElement)
        .value("eDGNMODEL_STATUS_UndersizeElement", DGNMODEL_STATUS_UndersizeElement)
        .value("eDGNMODEL_STATUS_InvalidAttrOffset", DGNMODEL_STATUS_InvalidAttrOffset)
        .value("eDGNMODEL_STATUS_InvalidXattribute", DGNMODEL_STATUS_InvalidXattribute)
        .value("eDGNMODEL_STATUS_InvalidXattributeId", DGNMODEL_STATUS_InvalidXattributeId)
        .value("eDGNMODEL_STATUS_DuplicateModelName", DGNMODEL_STATUS_DuplicateModelName)
        .value("eDGNMODEL_STATUS_NoChange", DGNMODEL_STATUS_NoChange)
        .value("eDGNMODEL_STATUS_DuplicateDependency", DGNMODEL_STATUS_DuplicateDependency)
        .value("eDGNMODEL_STATUS_DuplicateModelID", DGNMODEL_STATUS_DuplicateModelID)
        .value("eDGNMODEL_STATUS_InvalidModelName", DGNMODEL_STATUS_InvalidModelName)
        .value("eDGNMODEL_STATUS_BadArg", DGNMODEL_STATUS_BadArg)
        .value("eDGNMODEL_STATUS_MuNotLargerThanSu", DGNMODEL_STATUS_MuNotLargerThanSu)
        .value("eDGNMODEL_STATUS_NotSameUnitBase", DGNMODEL_STATUS_NotSameUnitBase)
        .value("eDGNMODEL_STATUS_WrongModel", DGNMODEL_STATUS_WrongModel)
        .value("eDGNMODEL_STATUS_DrawingModelMustBe2d", DGNMODEL_STATUS_DrawingModelMustBe2d)
        .value("eDGNMODEL_STATUS_InvalidModelTypeSwitch", DGNMODEL_STATUS_InvalidModelTypeSwitch)
        .value("eDGNMODEL_STATUS_BadFileRefCount", DGNMODEL_STATUS_BadFileRefCount)
        .value("eDGNMODEL_STATUS_ElementListNotFilled", DGNMODEL_STATUS_ElementListNotFilled)
        .export_values();
    bind_TypeWrapper<DgnModelStatus>(m, "MsPyDgnModelStatus");

    //===================================================================================
    // enum DgnFileEmbedStatus
    py::enum_< DgnPlatform::DgnFileEmbedStatus>(m, "DgnFileEmbedStatus", py::arithmetic())
        .value("eDGNEMBED_STATUS_Success", DgnPlatform::DGNEMBED_STATUS_Success)
        .value("eDGNEMBED_STATUS_InvalidContainerFormat", DgnPlatform::DGNEMBED_STATUS_InvalidContainerFormat)
        .value("eDGNEMBED_STATUS_InvalidDonor", DgnPlatform::DGNEMBED_STATUS_InvalidDonor)
        .value("eDGNEMBED_STATUS_InvalidDonorFormat", DgnPlatform::DGNEMBED_STATUS_InvalidDonorFormat)
        .value("eDGNEMBED_STATUS_CopyError", DgnPlatform::DGNEMBED_STATUS_CopyError)
        .value("eDGNEMBED_STATUS_NotFound", DgnPlatform::DGNEMBED_STATUS_NotFound)
        .value("eDGNEMBED_STATUS_WriteError", DgnPlatform::DGNEMBED_STATUS_WriteError)
        .value("eDGNEMBED_STATUS_ReadError", DgnPlatform::DGNEMBED_STATUS_ReadError)
        .value("eDGNEMBED_STATUS_DuplicateFilename", DgnPlatform::DGNEMBED_STATUS_DuplicateFilename)
        .value("eDGNEMBED_STATUS_DuplicateAlias", DgnPlatform::DGNEMBED_STATUS_DuplicateAlias)
        .export_values();

    //===================================================================================
    // enum LineStyleStatus
    py::enum_< DgnPlatform::LineStyleStatus>(m, "LineStyleStatus", py::arithmetic())
        .value("eLINESTYLE_STATUS_Success", DgnPlatform::LINESTYLE_STATUS_Success)
        .value("eLINESTYLE_STATUS_Error", DgnPlatform::LINESTYLE_STATUS_Error)
        .value("eLINESTYLE_STATUS_BadArgument", DgnPlatform::LINESTYLE_STATUS_BadArgument)
        .value("eLINESTYLE_STATUS_UnknownResourceError", DgnPlatform::LINESTYLE_STATUS_UnknownResourceError)
        .value("eLINESTYLE_STATUS_FileNotFound", DgnPlatform::LINESTYLE_STATUS_FileNotFound)
        .value("eLINESTYLE_STATUS_NotSameFile", DgnPlatform::LINESTYLE_STATUS_NotSameFile)
        .value("eLINESTYLE_STATUS_InvalidForV7Symbol", DgnPlatform::LINESTYLE_STATUS_InvalidForV7Symbol)
        .value("eLINESTYLE_STATUS_InvalidForV8Symbol", DgnPlatform::LINESTYLE_STATUS_InvalidForV8Symbol)
        .value("eLINESTYLE_STATUS_FileReadOnly", DgnPlatform::LINESTYLE_STATUS_FileReadOnly)
        .value("eLINESTYLE_STATUS_AlreadyExists", DgnPlatform::LINESTYLE_STATUS_AlreadyExists)
        .value("eLINESTYLE_STATUS_BadFormat", DgnPlatform::LINESTYLE_STATUS_BadFormat)
        .value("eLINESTYLE_STATUS_StyleNotFound", DgnPlatform::LINESTYLE_STATUS_StyleNotFound)
        .value("eLINESTYLE_STATUS_UnsavedSubcomponent", DgnPlatform::LINESTYLE_STATUS_UnsavedSubcomponent)
        .value("eLINESTYLE_STATUS_MissingSubcomponent", DgnPlatform::LINESTYLE_STATUS_MissingSubcomponent)
        .export_values();

    //===================================================================================
    // enum ViewFrustumError
    py::enum_< DgnPlatform::ViewFrustumError>(m, "ViewFrustumError", py::arithmetic())
        .value("eVIEW_FRUSTERR_InvalidWindow", DgnPlatform::VIEW_FRUSTERR_InvalidWindow)
        .value("eVIEW_FRUSTERR_MinWindow", DgnPlatform::VIEW_FRUSTERR_MinWindow)
        .value("eVIEW_FRUSTERR_MaxWindow", DgnPlatform::VIEW_FRUSTERR_MaxWindow)
        .value("eVIEW_FRUSTERR_MinDisplayDepth", DgnPlatform::VIEW_FRUSTERR_MinDisplayDepth)
        .value("eVIEW_FRUSTERR_MaxDisplayDepth", DgnPlatform::VIEW_FRUSTERR_MaxDisplayDepth)
        .export_values();

    //===================================================================================
    // enum DgnHandlersStatus
    py::enum_< DgnPlatform::DgnHandlersStatus>(m, "DgnHandlersStatus", py::arithmetic())
        .value("eDGNHANDLERS_STATUS_Success", DgnPlatform::DGNHANDLERS_STATUS_Success)
        .value("eDGNHANDLERS_STATUS_BadElement", DgnPlatform::DGNHANDLERS_STATUS_BadElement)
        .value("eDGNHANDLERS_STATUS_FileReadonly", DgnPlatform::DGNHANDLERS_STATUS_FileReadonly)
        .value("eDGNHANDLERS_STATUS_WriteInhibit", DgnPlatform::DGNHANDLERS_STATUS_WriteInhibit)
        .value("eDGNHANDLERS_STATUS_BadArg", DgnPlatform::DGNHANDLERS_STATUS_BadArg)
        .value("eDGNHANDLERS_STATUS_UserAbort", DgnPlatform::DGNHANDLERS_STATUS_UserAbort)
        .value("eDGNHANDLERS_STATUS_ElementTooLarge", DgnPlatform::DGNHANDLERS_STATUS_ElementTooLarge)
        .value("eDGNHANDLERS_STATUS_LinkageNotFound", DgnPlatform::DGNHANDLERS_STATUS_LinkageNotFound)
        .value("eDGNHANDLERS_STATUS_AlreadyExists", DgnPlatform::DGNHANDLERS_STATUS_AlreadyExists)
        .value("eDGNHANDLERS_STATUS_NoModel", DgnPlatform::DGNHANDLERS_STATUS_NoModel)
        .value("eDGNHANDLERS_STATUS_NotCmplxHdr", DgnPlatform::DGNHANDLERS_STATUS_NotCmplxHdr)
        .export_values();

    //===================================================================================
    // enum DgnPlatformStatus
    py::enum_< DgnPlatform::DgnPlatformStatus>(m, "DgnPlatformStatus", py::arithmetic())
        .value("eDGNPLATFORM_STATUS_Success", DgnPlatform::DGNPLATFORM_STATUS_Success)
        .value("eDGNPLATFORM_STATUS_BadArg", DgnPlatform::DGNPLATFORM_STATUS_BadArg)
        .value("eDGNPLATFORM_STATUS_InsfMemory", DgnPlatform::DGNPLATFORM_STATUS_InsfMemory)
        .value("eDGNPLATFORM_STATUS_TooLarge", DgnPlatform::DGNPLATFORM_STATUS_TooLarge)
        .value("eDGNPLATFORM_STATUS_LinkageNotFound", DgnPlatform::DGNPLATFORM_STATUS_LinkageNotFound)
        .value("eDGNPLATFORM_STATUS_NoChange", DgnPlatform::DGNPLATFORM_STATUS_NoChange)
        .value("eDGNPLATFORM_STATUS_BadParameter", DgnPlatform::DGNPLATFORM_STATUS_BadParameter)
        .value("eDGNPLATFORM_STATUS_ElemTooLarge", DgnPlatform::DGNPLATFORM_STATUS_ElemTooLarge)
        .value("eDGNPLATFORM_STATUS_ViewNotFound", DgnPlatform::DGNPLATFORM_STATUS_ViewNotFound)
        .export_values();

    //===================================================================================
    // enum GeoCoordAttachmentErrors
    py::enum_< DgnPlatform::GeoCoordAttachmentErrors>(m, "GeoCoordAttachmentErrors", py::arithmetic())
        .value("eGEOCOORD_ERROR_NoGeocode", DgnPlatform::GEOCOORD_ERROR_NoGeocode)
        .value("eGEOCOORD_ERROR_NotGeoTransformed", DgnPlatform::GEOCOORD_ERROR_NotGeoTransformed)
        .export_values();

    //===================================================================================
    // enum BSplineStatus
    py::enum_< BSplineStatus>(m, "BSplineStatus", py::arithmetic())
        .value("eBSPLINE_STATUS_Success", BSPLINE_STATUS_Success)
        .value("eBSPLINE_STATUS_NoPoles", BSPLINE_STATUS_NoPoles)
        .value("eBSPLINE_STATUS_NoKnots", BSPLINE_STATUS_NoKnots)
        .value("eBSPLINE_STATUS_NoWeights", BSPLINE_STATUS_NoWeights)
        .value("eBSPLINE_STATUS_NoBounds", BSPLINE_STATUS_NoBounds)
        .value("eBSPLINE_STATUS_NoNumBounds", BSPLINE_STATUS_NoNumBounds)
        .value("eBSPLINE_STATUS_NoBspHeader", BSPLINE_STATUS_NoBspHeader)
        .value("eBSPLINE_STATUS_TooFewPoles", BSPLINE_STATUS_TooFewPoles)
        .value("eBSPLINE_STATUS_TooManyPoles", BSPLINE_STATUS_TooManyPoles)
        .value("eBSPLINE_STATUS_BadBspElement", BSPLINE_STATUS_BadBspElement)
        .value("eBSPLINE_STATUS_BadParameter", BSPLINE_STATUS_BadParameter)
        .value("eBSPLINE_STATUS_BadOrder", BSPLINE_STATUS_BadOrder)
        .value("eBSPLINE_STATUS_BadPeriodicity", BSPLINE_STATUS_BadPeriodicity)
        .value("eBSPLINE_STATUS_BadPoles", BSPLINE_STATUS_BadPoles)
        .value("eBSPLINE_STATUS_BadKnots", BSPLINE_STATUS_BadKnots)
        .value("eBSPLINE_STATUS_BadWeights", BSPLINE_STATUS_BadWeights)
        .value("eBSPLINE_STATUS_BadSpiralDefinition", BSPLINE_STATUS_BadSpiralDefinition)
        .value("eBSPLINE_STATUS_TooManyKnots", BSPLINE_STATUS_TooManyKnots)
        .value("eBSPLINE_STATUS_NoOffsetIntersection", BSPLINE_STATUS_NoOffsetIntersection)
        .value("eBSPLINE_STATUS_BadContinuity", BSPLINE_STATUS_BadContinuity)
        .value("eBSPLINE_STATUS_RecurseLimit", BSPLINE_STATUS_RecurseLimit)
        .export_values();

    //===================================================================================
    // enum DgnPlatformToolsStatus
    py::enum_< DgnPlatformToolsStatus>(m, "DgnPlatformToolsStatus", py::arithmetic())
        .value("eDGNPLATFORMTOOLS_STATUS_WriteFailed", DGNPLATFORMTOOLS_STATUS_WriteFailed)
        .value("eDGNPLATFORMTOOLS_STATUS_InsfMemory", DGNPLATFORMTOOLS_STATUS_InsfMemory)
        .value("eDGNPLATFORMTOOLS_STATUS_ReadFailed", DGNPLATFORMTOOLS_STATUS_ReadFailed)
        .value("eDGNPLATFORMTOOLS_STATUS_NoMatch", DGNPLATFORMTOOLS_STATUS_NoMatch)
        .value("eDGNPLATFORMTOOLS_STATUS_Ambiguous", DGNPLATFORMTOOLS_STATUS_Ambiguous)
        .value("eDGNPLATFORMTOOLS_STATUS_BadArg", DGNPLATFORMTOOLS_STATUS_BadArg)
        .value("eDGNPLATFORMTOOLS_STATUS_BadStringListIndex", DGNPLATFORMTOOLS_STATUS_BadStringListIndex)
        .value("eDGNPLATFORMTOOLS_STATUS_TooLarge", DGNPLATFORMTOOLS_STATUS_TooLarge)
        .value("eDGNPLATFORMTOOLS_STATUS_FileNotFound", DGNPLATFORMTOOLS_STATUS_FileNotFound)
        .value("eDGNPLATFORMTOOLS_STATUS_NameTooLong", DGNPLATFORMTOOLS_STATUS_NameTooLong)
        .value("eDGNPLATFORMTOOLS_STATUS_BadParameter", DGNPLATFORMTOOLS_STATUS_BadParameter)
        .value("eDGNPLATFORMTOOLS_STATUS_AddressNotValid", DGNPLATFORMTOOLS_STATUS_AddressNotValid)
        .value("eDGNPLATFORMTOOLS_STATUS_BadVariableArraySize", DGNPLATFORMTOOLS_STATUS_BadVariableArraySize)
        .value("eDGNPLATFORMTOOLS_STATUS_NotConversionRules", DGNPLATFORMTOOLS_STATUS_NotConversionRules)
        .value("eDGNPLATFORMTOOLS_STATUS_BadDataDef", DGNPLATFORMTOOLS_STATUS_BadDataDef)
        .value("eDGNPLATFORMTOOLS_STATUS_DataDefNotFound", DGNPLATFORMTOOLS_STATUS_DataDefNotFound)
        .value("eDGNPLATFORMTOOLS_STATUS_BufferAlignmentsDiffer", DGNPLATFORMTOOLS_STATUS_BufferAlignmentsDiffer)
        .value("eDGNPLATFORMTOOLS_STATUS_InvalidPlatformId", DGNPLATFORMTOOLS_STATUS_InvalidPlatformId)
        .value("eDGNPLATFORMTOOLS_STATUS_VoidDataType", DGNPLATFORMTOOLS_STATUS_VoidDataType)
        .value("eDGNPLATFORMTOOLS_STATUS_InvalidDependency", DGNPLATFORMTOOLS_STATUS_InvalidDependency)
        .export_values();

    //===================================================================================
    // enum RscStatus
    py::enum_< RscStatus>(m, "RscStatus", py::arithmetic())
        .value("eRSC_STATUS_Error", RSC_STATUS_Error)
        .value("eRSC_STATUS_FileError", RSC_STATUS_FileError)
        .value("eRSC_STATUS_HandleInvalid", RSC_STATUS_HandleInvalid)
        .value("eRSC_STATUS_FileNotFound", RSC_STATUS_FileNotFound)
        .value("eRSC_STATUS_InsufficientMemory", RSC_STATUS_InsufficientMemory)
        .value("eRSC_STATUS_WriteViolation", RSC_STATUS_WriteViolation)
        .value("eRSC_STATUS_AddressInvalid", RSC_STATUS_AddressInvalid)
        .value("eRSC_STATUS_ResourceTypeInvalid", RSC_STATUS_ResourceTypeInvalid)
        .value("eRSC_STATUS_AlreadyExists", RSC_STATUS_AlreadyExists)
        .value("eRSC_STATUS_InUse", RSC_STATUS_InUse)
        .value("eRSC_STATUS_NotFound", RSC_STATUS_NotFound)
        .value("eRSC_STATUS_StringNotFound", RSC_STATUS_StringNotFound)
        .value("eRSC_STATUS_QueryIdInvalid", RSC_STATUS_QueryIdInvalid)
        .value("eRSC_STATUS_DirectAddPending", RSC_STATUS_DirectAddPending)
        .value("eRSC_STATUS_BadRangeTree", RSC_STATUS_BadRangeTree)
        .value("eRSC_STATUS_FileNotOpen", RSC_STATUS_FileNotOpen)
        .value("eRSC_STATUS_BadResourceSize", RSC_STATUS_BadResourceSize)
        .value("eRSC_STATUS_InvalidFileHandle", RSC_STATUS_InvalidFileHandle)
        .value("eRSC_STATUS_AliasRequired", RSC_STATUS_AliasRequired)
        .value("eRSC_STATUS_ResourceFileCorrupt", RSC_STATUS_ResourceFileCorrupt)
        .value("eRSC_STATUS_FileOpenFailure", RSC_STATUS_FileOpenFailure)
        .value("eRSC_STATUS_FileHandleTableFull", RSC_STATUS_FileHandleTableFull)
        .value("eRSC_STATUS_ConditionFalse", RSC_STATUS_ConditionFalse)
        .export_values();

    //===================================================================================
    // enum AkimaCurveStatus
    py::enum_< DgnPlatform::AkimaCurveStatus>(m, "AkimaCurveStatus", py::arithmetic())
        .value("eAKIMACURVE_STATUS_Success", DgnPlatform::AKIMACURVE_STATUS_Success)
        .value("eAKIMACURVE_STATUS_BadElement", DgnPlatform::AKIMACURVE_STATUS_BadElement)
        .value("eAKIMACURVE_STATUS_NullSolution", DgnPlatform::AKIMACURVE_STATUS_NullSolution)
        .export_values();

    //===================================================================================
    // enum StyleTableErrors
    py::enum_< DgnPlatform::StyleTableErrors>(m, "StyleTableErrors", py::arithmetic())
        .value("eSTYLETABLE_ERROR_NoMatch", DgnPlatform::STYLETABLE_ERROR_NoMatch)
        .value("eSTYLETABLE_ERROR_BadIndex", DgnPlatform::STYLETABLE_ERROR_BadIndex)
        .value("eSTYLETABLE_ERROR_DuplicateName", DgnPlatform::STYLETABLE_ERROR_DuplicateName)
        .value("eSTYLETABLE_ERROR_NoChange", DgnPlatform::STYLETABLE_ERROR_NoChange)
        .value("eSTYLETABLE_ERROR_BadName", DgnPlatform::STYLETABLE_ERROR_BadName)
        .value("eSTYLETABLE_ERROR_StyleNotFound", DgnPlatform::STYLETABLE_ERROR_StyleNotFound)
        .value("eSTYLETABLE_ERROR_StyleIsUsed", DgnPlatform::STYLETABLE_ERROR_StyleIsUsed)
        .export_values();

    //===================================================================================
    // enum DgnAttachmentErrors
    py::enum_< DgnPlatform::DgnAttachmentErrors>(m, "DgnAttachmentErrors", py::arithmetic())
        .value("eDGNATTACHMENT_ERROR_DuplicateLogical", DgnPlatform::DGNATTACHMENT_ERROR_DuplicateLogical)
        .value("eDGNATTACHMENT_ERROR_CantRewriteNewAttachment", DgnPlatform::DGNATTACHMENT_ERROR_CantRewriteNewAttachment)
        .export_values();

    //===================================================================================
    // enum SignatureErrors
    py::enum_< DgnPlatform::SignatureErrors>(m, "SignatureErrors", py::arithmetic())
        .value("eSIGNATURE_STATUS_NotFound", DgnPlatform::SIGNATURE_STATUS_NotFound)
        .value("eSIGNATURE_STATUS_NotVerified", DgnPlatform::SIGNATURE_STATUS_NotVerified)
        .value("eSIGNATURE_STATUS_NotRecognized", DgnPlatform::SIGNATURE_STATUS_NotRecognized)
        .value("eSIGNATURE_STATUS_RightNotGranted", DgnPlatform::SIGNATURE_STATUS_RightNotGranted)
        .value("eSIGNATURE_STATUS_Sileng", DgnPlatform::SIGNATURE_STATUS_Sileng)
        .export_values();    
    }