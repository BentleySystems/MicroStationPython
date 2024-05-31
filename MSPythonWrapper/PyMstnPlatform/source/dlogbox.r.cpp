/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyMstnPlatform\source\dlogbox.r.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <Mstn/MdlApi/dlogbox.r.h>

// Pybind match for Dialog ids.

enum class DialogIds
    {
    PyDIALOGID_Locks                      = -1,
    PyDIALOGID_ToolBoxDummy               = -2, 
    PyDIALOGID_ElementAttributes          = -3,
    PyDIALOGID_CoordReadout               = -4,
    PyDIALOGID_MainWindow                 = -5,    // Changed from PyDIALOGID_CommandWindow
    PyDIALOGID_ReferenceFile              = -7,
    PyDIALOGID_FileProperties             = -9,
    PyDIALOGID_AuxCoordSystems            = -10,
    PyDIALOGID_GetSecurityKey             = -12,
    PyDIALOGID_StandardAlert              = -13,
    PyDIALOGID_ElementQuickInfo           = -15,
    PyDIALOGID_UstnMgr                    = -16,
    PyDIALOGID_AcademicAdvisory           = -17,
    PyDIALOGID_PaletteItems               = -19,   /*Dummy ID for 5.0 palette items*/
    PyDIALOGID_Snaps                      = -20,   /*Dummy ID for snap settings */
    PyDIALOGID_AccuSnap                   = -21,
    PyDIALOGID_GraphicsFileExport         = -22,
    PyDIALOGID_LineStyleSelect            = -23,
    PyDIALOGID_DefineNamedLevelsSort      = -24,
    PyDIALOGID_NamedLevelsTargetGroup     = -25,
    PyDIALOGID_AdvisoryDisplay            = -28,
    PyDIALOGID_CloseToolBoxes             = -29,
    PyDIALOGID_TaskNavigation             = -30,   /* Reserved for CMD_DIALOG_TASKNAVIGATION */
    PyDIALOGID_WorkingUnits               = -31,
    PyDIALOGID_DefineNamedLevels          = -32,
    PyDIALOGID_DBSettings                 = -34,
    PyDIALOGID_ViewRotation               = -35,
    PyDIALOGID_CellMaintenance            = -36,
    PyDIALOGID_CellEdit                   = -37,
    PyDIALOGID_CellCreate                 = -38,
    PyDIALOGID_DesignFileSettings         = -39,
    PyDIALOGID_ActiveAngle                = -40,
    PyDIALOGID_ReferenceAttach            = -41,
    PyDIALOGID_UserPreference             = -42,
    PyDIALOGID_V7DesignFileAlert          = -43,
    PyDIALOGID_AboutDigitalRights         = -44,
    PyDIALOGID_CustomScale                = -45,
    PyDIALOGID_ViewSettings               = -46,
    PyDIALOGID_ViewLevels                 = -47,
    PyDIALOGID_CmdBrowser                 = -48,
    PyDIALOGID_ActiveScale                = -49,
    PyDIALOGID_PatternSettings            = -50,
    PyDIALOGID_ColorSquare                = -51,
    PyDIALOGID_StdFileSeedCreate          = -52,
    PyDIALOGID_KeyinSettings              = -53,
    PyDIALOGID_Font                       = -54,
    PyDIALOGID_ColorPalette               = -55,
    PyDIALOGID_LevSymb                    = -56,
    PyDIALOGID_GridSettings               = -57,
    PyDIALOGID_DesignOptions              = -58,
    PyDIALOGID_CustomSheetSize            = -59,
    PyDIALOGID_Camera                     = -60,
    PyDIALOGID_AboutConfiguration         = -61,
    PyDIALOGID_FunctionKeys               = -62,
    PyDIALOGID_TextStyleEditor            = -63,
    PyDIALOGID_OptionalInfoBox            = -64,
    PyDIALOGID_MDL                        = -65,
    PyDIALOGID_MDLDetail                  = -66,
    PyDIALOGID_CmdBrowserApp              = -67,
    PyDIALOGID_StdFileOpen                = -68,
    PyDIALOGID_Digitizing                 = -70,
    PyDIALOGID_ExtendedFileOpen           = -71,
    PyDIALOGID_PreviewPrint               = -72,
    PyDIALOGID_OptionalOKCancelBox        = -73,
    PyDIALOGID_AboutWorkmode              = -74,
    PyDIALOGID_Display                    = -75,
    PyDIALOGID_MainFrame                  = -76,   // Base ID
    PyDIALOGID_FenceFrame                 = -77,   // Base ID
    PyDIALOGID_FileListDirSingle          = -78,
    PyDIALOGID_ToolSettings               = -79,
    PyDIALOGID_Image                      = -80,
    PyDIALOGID_ReferenceRotate            = -81,
    PyDIALOGID_ReferenceScale             = -82,
    PyDIALOGID_ImageSave                  = -83,
    PyDIALOGID_TextFileDisplay            = -84,
    PyDIALOGID_AboutUstn                  = -85,
    PyDIALOGID_FileList                   = -86,
    PyDIALOGID_BasicLocks                 = -87,
    PyDIALOGID_FileListDirMultiple        = -88,
    PyDIALOGID_FileListMultiple           = -89,
    PyDIALOGID_FileListDDSingle           = -90,
    PyDIALOGID_FileListDDMultiple         = -91,
    PyDIALOGID_LevelEdit                  = -92,
    PyDIALOGID_GroupEdit                  = -93,
    PyDIALOGID_DialogMessages             = -94,
    PyDIALOGID_WindowManMenu              = -95,
    PyDIALOGID_ViewToggles                = -96, /* This is not for an existing dialog but serves as a base for a generic item. */
    PyDIALOGID_StandardInfoBox            = -97,
    PyDIALOGID_Help                       = -98,
    PyDIALOGID_HelpFind                   = -99,
    PyDIALOGID_LargeAlert                 = -100,
    PyDIALOGID_ButtonAssignment           = -101,
    PyDIALOGID_ButtonMap                  = -102,
    PyDIALOGID_ShowClipboard              = -104,
    PyDIALOGID_DrawComp                   = -105,
    PyDIALOGID_CompletionBar              = -106,
    PyDIALOGID_AboutUstnMore              = -107,
    PyDIALOGID_GraphicsFileOpen           = -108,
    PyDIALOGID_GraphicsFileSaveAs         = -109,
    PyDIALOGID_ReferenceFullSettings      = -110,
    PyDIALOGID_ColorInterpolate           = -111,
    PyDIALOGID_MediumAlert                = -112,
    PyDIALOGID_YesNoCancelAlert           = -113,
    PyDIALOGID_ColorPalInfo               = -114,
    PyDIALOGID_NamedLevels                = -115,
    PyDIALOGID_Igen                       = -116,
    PyDIALOGID_SetHiliteColor             = -117,
    PyDIALOGID_SetVectorCursorColor       = -118,
    PyDIALOGID_MediumInfoBox              = -119,
    PyDIALOGID_LargeInfoBox               = -120,
    PyDIALOGID_MsgBoxYesNo                = -121,
    PyDIALOGID_MsgBoxOK                   = PyDIALOGID_StandardInfoBox,   /* -97 */
    PyDIALOGID_MsgBoxYesNoCancel          = PyDIALOGID_YesNoCancelAlert,  /* -113 */
    PyDIALOGID_MsgBoxOKCancel             = PyDIALOGID_StandardAlert,     /* -13 */
    PyDIALOGID_View                       = -122,
    PyDIALOGID_AboutUstnLicenseMore       = -123,
    PyDIALOGID_MsgBoxMediumYesNoCancel    = -124,
    PyDIALOGID_MoreWindows                = -125,
    PyDIALOGID_ElementPreviewDialog       = -126,
    PyDIALOGID_UpdateSequence             = -127,
    PyDIALOGID_HLineSettings              = -128,
    PyDIALOGID_SnapButtonResizable        = -129,
    PyDIALOGID_TrackBar                   = -130,
    PyDIALOGID_BusyBar                    = -131,
    PyDIALOGID_DesignLinksCreate          = -133,
    PyDIALOGID_SelectImagePreview         = -135,
    PyDIALOGID_ModelManager               = -136,
    PyDIALOGID_V7CellLibConvert           = -137,
    PyDIALOGID_YesAllNoCancelAlert        = -138,
    PyDIALOGID_ReferenceFileOpen          = -139,  /* this is actually in ref.ma */
    PyDIALOGID_MsgBoxYesAllNoCancel       = PyDIALOGID_YesAllNoCancelAlert,  /* -138 */
    PyDIALOGID_SubEditor                  = -140,
    PyDIALOGID_ReferenceFileBrowse        = -143,  /* this is actually in ref.ma */
    PyDIALOGID_FileSaveAsOptions          = -144,
    PyDIALOGID_ModelChoose                = -145,
    PyDIALOGID_CfgVars                    = -146,
    PyDIALOGID_DockableTemplate           = -147,
    PyDIALOGID_FramedTemplate             = -148,
    PyDIALOGID_RefColorAdjust             = -149,
    PyDIALOGID_AcceleratorPrefs           = -150,
    PyDIALOGID_ReferenceDragDrop          = -151,
    PyDIALOGID_MultiSnap                  = -152,  /* => cmdtable.r CT_DIALOG {152, .... "MULTISNAP"} */
    PyDIALOGID_AdvancedColors             = -153,
    PyDIALOGID_ViewAreaBackground         = -154,
    PyDIALOGID_TransparencyPriority       = -155,  /* this not actually a dialog, just used to get a base id */
    PyDIALOGID_NamedFences                = -156,
    PyDIALOGID_ToolBoxTemplate            = -157,
    PyDIALOGID_Customize                  = -158,
    PyDIALOGID_ColorBookEditor            = -159,
    PyDIALOGID_CreateColorBook            = -160,
    PyDIALOGID_CellSelectorFileOpen       = -161,
    PyDIALOGID_CellSelectorFileCreate     = -162,
    PyDIALOGID_MsgBoxYesAllNo             = -163,
    PyDIALOGID_ResetMenuOptions           = -164,
    PyDIALOGID_RefPresentation            = -166,
    PyDIALOGID_ViewBrightness             = -167,
    PyDIALOGID_YesAllNoAllCancelAlert     = -168,
    PyDIALOGID_MsgBoxMediumYesNo          = -169,
    PyDIALOGID_HiddenLineSettings         = -170,
    PyDIALOGID_CommonItems                = -171,
    PyDIALOGID_PointCloudFileBrowse       = -172, /* there's no MDL dialog, just winopen */
    PyDIALOGID_CellSelect                 = -173,
    PyDIALOGID_OptionalOKCancelBoxWide    = -174,
    PyDIALOGID_InputManager               = -175,
    PyDIALOGID_Transparency               = -176,
    PyDIALOGID_RasterFileBrowse           = -177,
    PyDIALOGID_SavedViewDragDrop          = -178,
    PyDIALOGID_CachedVisibleEdgeSettings  = -179,
    PyDIALOGID_MsgBoxLargeYesNo           = -180,
    PyDIALOGID_DWGAecFileAlert            = -182,
    PyDIALOGID_DeletingUsedStyles         = -183,
    PyDIALOGID_KeyboardShortcuts          = -184,
    PyDIALOGID_BothValidAndDifferent               = -185,
    PyDIALOGID_UnassociatedFile_ValidActiveWorkSet = -186,
    PyDIALOGID_FileWorkSetNotFound_InvalidActiveWorkSet = -187,
    PyDIALOGID_FileWorkSetNotFound_ValidActiveWorkSet = -188,
    PyDIALOGID_Preprocessor               = -189,
    PyDIALOGID_PropertyBinding            = -190,
    PyDIALOGID_FileWorkSetFound_InvalidActiveWorkSet = -191,
    PyDIALOGID_UnassociatedFile_Product_Mismatch = -192,
    PyDIALOGID_UnsignedAppWarning         = -193,
    PyDIALOGID_VariableDialog             = -194,
    PyDIALOGID_FileWorkSetNotFound_ValidActiveWorkSet_ValidConfig = -195,
    };



/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_dlogbox_r(py::module_& m)
    {
    //===================================================================================
    // enum ActionButtonValue
    py::enum_< ActionButtonValue>(m, "ActionButtonValue", py::arithmetic())
        .value("eACTIONBUTTON_APPLY", ACTIONBUTTON_APPLY)
        .value("eACTIONBUTTON_RESET", ACTIONBUTTON_RESET)
        .value("eACTIONBUTTON_OK", ACTIONBUTTON_OK)
        .value("eACTIONBUTTON_CANCEL", ACTIONBUTTON_CANCEL)
        .value("eACTIONBUTTON_DEFAULT", ACTIONBUTTON_DEFAULT)
        .value("eACTIONBUTTON_YES", ACTIONBUTTON_YES)
        .value("eACTIONBUTTON_NO", ACTIONBUTTON_NO)
        .value("eACTIONBUTTON_RETRY", ACTIONBUTTON_RETRY)
        .value("eACTIONBUTTON_STOP", ACTIONBUTTON_STOP)
        .value("eACTIONBUTTON_HELP", ACTIONBUTTON_HELP)
        .value("eACTIONBUTTON_YESTOALL", ACTIONBUTTON_YESTOALL)
        .value("eACTIONBUTTON_NOTOALL", ACTIONBUTTON_NOTOALL)
        .value("eACTIONBUTTON_OPEN", ACTIONBUTTON_OPEN)
        .export_values();

    //===================================================================================
    // enum MenuMarkType
    py::enum_< MenuMarkType>(m, "MenuMarkType", py::arithmetic())
        .value("eMARK_NONE", MARK_NONE)
        .value("eMARK_TOGGLE_OUT", MARK_TOGGLE_OUT)
        .value("eMARK_TOGGLE_IN", MARK_TOGGLE_IN)
        .value("eMARK_RADIO_OUT", MARK_RADIO_OUT)
        .value("eMARK_RADIO_IN", MARK_RADIO_IN)
        .value("eMARK_RIGHT_ARROW", MARK_RIGHT_ARROW)
        .export_values();

    py::enum_< DialogIds>(m, "DialogIds")
        .value("eDIALOGID_Locks", DialogIds::PyDIALOGID_Locks)
        .value("eDIALOGID_ToolBoxDummy", DialogIds::PyDIALOGID_ToolBoxDummy)
        .value("eDIALOGID_ElementAttributes", DialogIds::PyDIALOGID_ElementAttributes)
        .value("eDIALOGID_CoordReadout", DialogIds::PyDIALOGID_CoordReadout)
        .value("eDIALOGID_MainWindow", DialogIds::PyDIALOGID_MainWindow)
        .value("eDIALOGID_ReferenceFile", DialogIds::PyDIALOGID_ReferenceFile)
        .value("eDIALOGID_FileProperties", DialogIds::PyDIALOGID_FileProperties)
        .value("eDIALOGID_AuxCoordSystems", DialogIds::PyDIALOGID_AuxCoordSystems)
        .value("eDIALOGID_GetSecurityKey", DialogIds::PyDIALOGID_GetSecurityKey)
        .value("eDIALOGID_StandardAlert", DialogIds::PyDIALOGID_StandardAlert)
        .value("eDIALOGID_ElementQuickInfo", DialogIds::PyDIALOGID_ElementQuickInfo)
        .value("eDIALOGID_UstnMgr", DialogIds::PyDIALOGID_UstnMgr)
        .value("eDIALOGID_AcademicAdvisory", DialogIds::PyDIALOGID_AcademicAdvisory)
        .value("eDIALOGID_PaletteItems", DialogIds::PyDIALOGID_PaletteItems)
        .value("eDIALOGID_Snaps", DialogIds::PyDIALOGID_Snaps)
        .value("eDIALOGID_AccuSnap", DialogIds::PyDIALOGID_AccuSnap)
        .value("eDIALOGID_GraphicsFileExport", DialogIds::PyDIALOGID_GraphicsFileExport)
        .value("eDIALOGID_LineStyleSelect", DialogIds::PyDIALOGID_LineStyleSelect)
        .value("eDIALOGID_DefineNamedLevelsSort", DialogIds::PyDIALOGID_DefineNamedLevelsSort)
        .value("eDIALOGID_NamedLevelsTargetGroup", DialogIds::PyDIALOGID_NamedLevelsTargetGroup)
        .value("eDIALOGID_AdvisoryDisplay", DialogIds::PyDIALOGID_AdvisoryDisplay)
        .value("eDIALOGID_CloseToolBoxes", DialogIds::PyDIALOGID_CloseToolBoxes)
        .value("eDIALOGID_TaskNavigation", DialogIds::PyDIALOGID_TaskNavigation)
        .value("eDIALOGID_WorkingUnits", DialogIds::PyDIALOGID_WorkingUnits)
        .value("eDIALOGID_DefineNamedLevels", DialogIds::PyDIALOGID_DefineNamedLevels)
        .value("eDIALOGID_DBSettings", DialogIds::PyDIALOGID_DBSettings)
        .value("eDIALOGID_ViewRotation", DialogIds::PyDIALOGID_ViewRotation)
        .value("eDIALOGID_CellMaintenance", DialogIds::PyDIALOGID_CellMaintenance)
        .value("eDIALOGID_CellEdit", DialogIds::PyDIALOGID_CellEdit)
        .value("eDIALOGID_CellCreate", DialogIds::PyDIALOGID_CellCreate)
        .value("eDIALOGID_DesignFileSettings", DialogIds::PyDIALOGID_DesignFileSettings)
        .value("eDIALOGID_ActiveAngle", DialogIds::PyDIALOGID_ActiveAngle)
        .value("eDIALOGID_ReferenceAttach", DialogIds::PyDIALOGID_ReferenceAttach)
        .value("eDIALOGID_UserPreference", DialogIds::PyDIALOGID_UserPreference)
        .value("eDIALOGID_V7DesignFileAlert", DialogIds::PyDIALOGID_V7DesignFileAlert)
        .value("eDIALOGID_AboutDigitalRights", DialogIds::PyDIALOGID_AboutDigitalRights)
        .value("eDIALOGID_CustomScale", DialogIds::PyDIALOGID_CustomScale)
        .value("eDIALOGID_ViewSettings", DialogIds::PyDIALOGID_ViewSettings)
        .value("eDIALOGID_ViewLevels", DialogIds::PyDIALOGID_ViewLevels)
        .value("eDIALOGID_CmdBrowser", DialogIds::PyDIALOGID_CmdBrowser)
        .value("eDIALOGID_ActiveScale", DialogIds::PyDIALOGID_ActiveScale)
        .value("eDIALOGID_PatternSettings", DialogIds::PyDIALOGID_PatternSettings)
        .value("eDIALOGID_ColorSquare", DialogIds::PyDIALOGID_ColorSquare)
        .value("eDIALOGID_StdFileSeedCreate", DialogIds::PyDIALOGID_StdFileSeedCreate)
        .value("eDIALOGID_KeyinSettings", DialogIds::PyDIALOGID_KeyinSettings)
        .value("eDIALOGID_Font", DialogIds::PyDIALOGID_Font)
        .value("eDIALOGID_ColorPalette", DialogIds::PyDIALOGID_ColorPalette)
        .value("eDIALOGID_LevSymb", DialogIds::PyDIALOGID_LevSymb)
        .value("eDIALOGID_GridSettings", DialogIds::PyDIALOGID_GridSettings)
        .value("eDIALOGID_DesignOptions", DialogIds::PyDIALOGID_DesignOptions)
        .value("eDIALOGID_CustomSheetSize", DialogIds::PyDIALOGID_CustomSheetSize)
        .value("eDIALOGID_Camera", DialogIds::PyDIALOGID_Camera)
        .value("eDIALOGID_AboutConfiguration", DialogIds::PyDIALOGID_AboutConfiguration)
        .value("eDIALOGID_FunctionKeys", DialogIds::PyDIALOGID_FunctionKeys)
        .value("eDIALOGID_TextStyleEditor", DialogIds::PyDIALOGID_TextStyleEditor)
        .value("eDIALOGID_OptionalInfoBox", DialogIds::PyDIALOGID_OptionalInfoBox)
        .value("eDIALOGID_MDL", DialogIds::PyDIALOGID_MDL)
        .value("eDIALOGID_MDLDetail", DialogIds::PyDIALOGID_MDLDetail)
        .value("eDIALOGID_CmdBrowserApp", DialogIds::PyDIALOGID_CmdBrowserApp)
        .value("eDIALOGID_StdFileOpen", DialogIds::PyDIALOGID_StdFileOpen)
        .value("eDIALOGID_Digitizing", DialogIds::PyDIALOGID_Digitizing)
        .value("eDIALOGID_ExtendedFileOpen", DialogIds::PyDIALOGID_ExtendedFileOpen)
        .value("eDIALOGID_PreviewPrint", DialogIds::PyDIALOGID_PreviewPrint)
        .value("eDIALOGID_OptionalOKCancelBox", DialogIds::PyDIALOGID_OptionalOKCancelBox)
        .value("eDIALOGID_AboutWorkmode", DialogIds::PyDIALOGID_AboutWorkmode)
        .value("eDIALOGID_Display", DialogIds::PyDIALOGID_Display)
        .value("eDIALOGID_MainFrame", DialogIds::PyDIALOGID_MainFrame)
        .value("eDIALOGID_FenceFrame", DialogIds::PyDIALOGID_FenceFrame)
        .value("eDIALOGID_FileListDirSingle", DialogIds::PyDIALOGID_FileListDirSingle)
        .value("eDIALOGID_ToolSettings", DialogIds::PyDIALOGID_ToolSettings)
        .value("eDIALOGID_Image", DialogIds::PyDIALOGID_Image)
        .value("eDIALOGID_ReferenceRotate", DialogIds::PyDIALOGID_ReferenceRotate)
        .value("eDIALOGID_ReferenceScale", DialogIds::PyDIALOGID_ReferenceScale)
        .value("eDIALOGID_ImageSave", DialogIds::PyDIALOGID_ImageSave)
        .value("eDIALOGID_TextFileDisplay", DialogIds::PyDIALOGID_TextFileDisplay)
        .value("eDIALOGID_AboutUstn", DialogIds::PyDIALOGID_AboutUstn)
        .value("eDIALOGID_FileList", DialogIds::PyDIALOGID_FileList)
        .value("eDIALOGID_BasicLocks", DialogIds::PyDIALOGID_BasicLocks)
        .value("eDIALOGID_FileListDirMultiple", DialogIds::PyDIALOGID_FileListDirMultiple)
        .value("eDIALOGID_FileListMultiple", DialogIds::PyDIALOGID_FileListMultiple)
        .value("eDIALOGID_FileListDDSingle", DialogIds::PyDIALOGID_FileListDDSingle)
        .value("eDIALOGID_FileListDDMultiple", DialogIds::PyDIALOGID_FileListDDMultiple)
        .value("eDIALOGID_LevelEdit", DialogIds::PyDIALOGID_LevelEdit)
        .value("eDIALOGID_GroupEdit", DialogIds::PyDIALOGID_GroupEdit)
        .value("eDIALOGID_DialogMessages", DialogIds::PyDIALOGID_DialogMessages)
        .value("eDIALOGID_WindowManMenu", DialogIds::PyDIALOGID_WindowManMenu)
        .value("eDIALOGID_ViewToggles", DialogIds::PyDIALOGID_ViewToggles)
        .value("eDIALOGID_StandardInfoBox", DialogIds::PyDIALOGID_StandardInfoBox)
        .value("eDIALOGID_Help", DialogIds::PyDIALOGID_Help)
        .value("eDIALOGID_HelpFind", DialogIds::PyDIALOGID_HelpFind)
        .value("eDIALOGID_LargeAlert", DialogIds::PyDIALOGID_LargeAlert)
        .value("eDIALOGID_ButtonAssignment", DialogIds::PyDIALOGID_ButtonAssignment)
        .value("eDIALOGID_ButtonMap", DialogIds::PyDIALOGID_ButtonMap)
        .value("eDIALOGID_ShowClipboard", DialogIds::PyDIALOGID_ShowClipboard)
        .value("eDIALOGID_DrawComp", DialogIds::PyDIALOGID_DrawComp)
        .value("eDIALOGID_CompletionBar", DialogIds::PyDIALOGID_CompletionBar)
        .value("eDIALOGID_AboutUstnMore", DialogIds::PyDIALOGID_AboutUstnMore)
        .value("eDIALOGID_GraphicsFileOpen", DialogIds::PyDIALOGID_GraphicsFileOpen)
        .value("eDIALOGID_GraphicsFileSaveAs", DialogIds::PyDIALOGID_GraphicsFileSaveAs)
        .value("eDIALOGID_ReferenceFullSettings", DialogIds::PyDIALOGID_ReferenceFullSettings)
        .value("eDIALOGID_ColorInterpolate", DialogIds::PyDIALOGID_ColorInterpolate)
        .value("eDIALOGID_MediumAlert", DialogIds::PyDIALOGID_MediumAlert)
        .value("eDIALOGID_YesNoCancelAlert", DialogIds::PyDIALOGID_YesNoCancelAlert)
        .value("eDIALOGID_ColorPalInfo", DialogIds::PyDIALOGID_ColorPalInfo)
        .value("eDIALOGID_NamedLevels", DialogIds::PyDIALOGID_NamedLevels)
        .value("eDIALOGID_Igen", DialogIds::PyDIALOGID_Igen)
        .value("eDIALOGID_SetHiliteColor", DialogIds::PyDIALOGID_SetHiliteColor)
        .value("eDIALOGID_SetVectorCursorColor", DialogIds::PyDIALOGID_SetVectorCursorColor)
        .value("eDIALOGID_MediumInfoBox", DialogIds::PyDIALOGID_MediumInfoBox)
        .value("eDIALOGID_LargeInfoBox", DialogIds::PyDIALOGID_LargeInfoBox)
        .value("eDIALOGID_MsgBoxYesNo", DialogIds::PyDIALOGID_MsgBoxYesNo)
        .value("eDIALOGID_MsgBoxOK", DialogIds::PyDIALOGID_MsgBoxOK)
        .value("eDIALOGID_MsgBoxYesNoCancel", DialogIds::PyDIALOGID_MsgBoxYesNoCancel)
        .value("eDIALOGID_MsgBoxOKCancel", DialogIds::PyDIALOGID_MsgBoxOKCancel)
        .value("eDIALOGID_View", DialogIds::PyDIALOGID_View)
        .value("eDIALOGID_AboutUstnLicenseMore", DialogIds::PyDIALOGID_AboutUstnLicenseMore)
        .value("eDIALOGID_MsgBoxMediumYesNoCancel", DialogIds::PyDIALOGID_MsgBoxMediumYesNoCancel)
        .value("eDIALOGID_MoreWindows", DialogIds::PyDIALOGID_MoreWindows)
        .value("eDIALOGID_ElementPreviewDialog", DialogIds::PyDIALOGID_ElementPreviewDialog)
        .value("eDIALOGID_UpdateSequence", DialogIds::PyDIALOGID_UpdateSequence)
        .value("eDIALOGID_HLineSettings", DialogIds::PyDIALOGID_HLineSettings)
        .value("eDIALOGID_SnapButtonResizable", DialogIds::PyDIALOGID_SnapButtonResizable)
        .value("eDIALOGID_TrackBar", DialogIds::PyDIALOGID_TrackBar)
        .value("eDIALOGID_BusyBar", DialogIds::PyDIALOGID_BusyBar)
        .value("eDIALOGID_DesignLinksCreate", DialogIds::PyDIALOGID_DesignLinksCreate)
        .value("eDIALOGID_SelectImagePreview", DialogIds::PyDIALOGID_SelectImagePreview)
        .value("eDIALOGID_ModelManager", DialogIds::PyDIALOGID_ModelManager)
        .value("eDIALOGID_V7CellLibConvert", DialogIds::PyDIALOGID_V7CellLibConvert)
        .value("eDIALOGID_YesAllNoCancelAlert", DialogIds::PyDIALOGID_YesAllNoCancelAlert)
        .value("eDIALOGID_ReferenceFileOpen", DialogIds::PyDIALOGID_ReferenceFileOpen)
        .value("eDIALOGID_MsgBoxYesAllNoCancel", DialogIds::PyDIALOGID_MsgBoxYesAllNoCancel)
        .value("eDIALOGID_SubEditor", DialogIds::PyDIALOGID_SubEditor)
        .value("eDIALOGID_ReferenceFileBrowse", DialogIds::PyDIALOGID_ReferenceFileBrowse)
        .value("eDIALOGID_FileSaveAsOptions", DialogIds::PyDIALOGID_FileSaveAsOptions)
        .value("eDIALOGID_ModelChoose", DialogIds::PyDIALOGID_ModelChoose)
        .value("eDIALOGID_CfgVars", DialogIds::PyDIALOGID_CfgVars)
        .value("eDIALOGID_DockableTemplate", DialogIds::PyDIALOGID_DockableTemplate)
        .value("eDIALOGID_FramedTemplate", DialogIds::PyDIALOGID_FramedTemplate)
        .value("eDIALOGID_RefColorAdjust", DialogIds::PyDIALOGID_RefColorAdjust)
        .value("eDIALOGID_AcceleratorPrefs", DialogIds::PyDIALOGID_AcceleratorPrefs)
        .value("eDIALOGID_ReferenceDragDrop", DialogIds::PyDIALOGID_ReferenceDragDrop)
        .value("eDIALOGID_MultiSnap", DialogIds::PyDIALOGID_MultiSnap)
        .value("eDIALOGID_AdvancedColors", DialogIds::PyDIALOGID_AdvancedColors)
        .value("eDIALOGID_ViewAreaBackground", DialogIds::PyDIALOGID_ViewAreaBackground)
        .value("eDIALOGID_TransparencyPriority", DialogIds::PyDIALOGID_TransparencyPriority)
        .value("eDIALOGID_NamedFences", DialogIds::PyDIALOGID_NamedFences)
        .value("eDIALOGID_ToolBoxTemplate", DialogIds::PyDIALOGID_ToolBoxTemplate)
        .value("eDIALOGID_Customize", DialogIds::PyDIALOGID_Customize)
        .value("eDIALOGID_ColorBookEditor", DialogIds::PyDIALOGID_ColorBookEditor)
        .value("eDIALOGID_CreateColorBook", DialogIds::PyDIALOGID_CreateColorBook)
        .value("eDIALOGID_CellSelectorFileOpen", DialogIds::PyDIALOGID_CellSelectorFileOpen)
        .value("eDIALOGID_CellSelectorFileCreate", DialogIds::PyDIALOGID_CellSelectorFileCreate)
        .value("eDIALOGID_MsgBoxYesAllNo", DialogIds::PyDIALOGID_MsgBoxYesAllNo)
        .value("eDIALOGID_ResetMenuOptions", DialogIds::PyDIALOGID_ResetMenuOptions)
        .value("eDIALOGID_RefPresentation", DialogIds::PyDIALOGID_RefPresentation)
        .value("eDIALOGID_ViewBrightness", DialogIds::PyDIALOGID_ViewBrightness)
        .value("eDIALOGID_YesAllNoAllCancelAlert", DialogIds::PyDIALOGID_YesAllNoAllCancelAlert)
        .value("eDIALOGID_MsgBoxMediumYesNo", DialogIds::PyDIALOGID_MsgBoxMediumYesNo)
        .value("eDIALOGID_HiddenLineSettings", DialogIds::PyDIALOGID_HiddenLineSettings)
        .value("eDIALOGID_CommonItems", DialogIds::PyDIALOGID_CommonItems)
        .value("eDIALOGID_PointCloudFileBrowse", DialogIds::PyDIALOGID_PointCloudFileBrowse)
        .value("eDIALOGID_CellSelect", DialogIds::PyDIALOGID_CellSelect)
        .value("eDIALOGID_OptionalOKCancelBoxWide", DialogIds::PyDIALOGID_OptionalOKCancelBoxWide)
        .value("eDIALOGID_InputManager", DialogIds::PyDIALOGID_InputManager)
        .value("eDIALOGID_Transparency", DialogIds::PyDIALOGID_Transparency)
        .value("eDIALOGID_RasterFileBrowse", DialogIds::PyDIALOGID_RasterFileBrowse)
        .value("eDIALOGID_SavedViewDragDrop", DialogIds::PyDIALOGID_SavedViewDragDrop)
        .value("eDIALOGID_CachedVisibleEdgeSettings", DialogIds::PyDIALOGID_CachedVisibleEdgeSettings)
        .value("eDIALOGID_MsgBoxLargeYesNo", DialogIds::PyDIALOGID_MsgBoxLargeYesNo)
        .value("eDIALOGID_DWGAecFileAlert", DialogIds::PyDIALOGID_DWGAecFileAlert)
        .value("eDIALOGID_DeletingUsedStyles", DialogIds::PyDIALOGID_DeletingUsedStyles)
        .value("eDIALOGID_KeyboardShortcuts", DialogIds::PyDIALOGID_KeyboardShortcuts)
        .value("eDIALOGID_BothValidAndDifferent", DialogIds::PyDIALOGID_BothValidAndDifferent)
        .value("eDIALOGID_UnassociatedFile_ValidActiveWorkSet", DialogIds::PyDIALOGID_UnassociatedFile_ValidActiveWorkSet)
        .value("eDIALOGID_FileWorkSetNotFound_InvalidActiveWorkSet", DialogIds::PyDIALOGID_FileWorkSetNotFound_InvalidActiveWorkSet)
        .value("eDIALOGID_FileWorkSetNotFound_ValidActiveWorkSet", DialogIds::PyDIALOGID_FileWorkSetNotFound_ValidActiveWorkSet)
        .value("eDIALOGID_Preprocessor", DialogIds::PyDIALOGID_Preprocessor)
        .value("eDIALOGID_PropertyBinding", DialogIds::PyDIALOGID_PropertyBinding)
        .value("eDIALOGID_FileWorkSetFound_InvalidActiveWorkSet", DialogIds::PyDIALOGID_FileWorkSetFound_InvalidActiveWorkSet)
        .value("eDIALOGID_UnassociatedFile_Product_Mismatch", DialogIds::PyDIALOGID_UnassociatedFile_Product_Mismatch)
        .value("eDIALOGID_UnsignedAppWarning", DialogIds::PyDIALOGID_UnsignedAppWarning)
        .value("eDIALOGID_VariableDialog", DialogIds::PyDIALOGID_VariableDialog)
        .value("eDIALOGID_FileWorkSetNotFound_ValidActiveWorkSet_ValidConfig", DialogIds::PyDIALOGID_FileWorkSetNotFound_ValidActiveWorkSet_ValidConfig)
        .export_values();


    }