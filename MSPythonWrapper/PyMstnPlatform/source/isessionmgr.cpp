/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyMstnPlatform\source\isessionmgr.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <Mstn/ISessionMgr.h>



static const char * __doc_Bentley_MstnPlatform_ISessionMgr_RemoveUIItemStateEntry =R"doc(Remove UIItemState entry that matches specified key if one exist.

Parameter ``key``:
    The key used to store UIItem state values.

)doc";

static const char * __doc_Bentley_MstnPlatform_ISessionMgr_GetUIItemMenuMarkState =R"doc(Get the MenuMarkType defined by key.

Parameter ``key``:
    The key used to retrieve UIItem state values.

Parameter ``defaultIfKeyNotFound``:
    The value to return if state value has not been specified.

Returns:
    MenuMarkType associated with key, or defaultIfKeyNotFound if no
    entry is found matching the key.

)doc";

static const char * __doc_Bentley_MstnPlatform_ISessionMgr_SetUIItemMenuMarkState =R"doc(Set the menu mark value for a menu item. This will trigger a
SystemEvent.ApplicationSyncUIItem event.

Parameter ``key``:
    The key that defines the name of the entry to modify or create.

Parameter ``value``:
    The MenuMarkType value.

Parameter ``sendImmediateMessage``:
    If true send immediate sync message, if false the sync message
    will be sent in the next UISync timer cycle.

)doc";

static const char * __doc_Bentley_MstnPlatform_ISessionMgr_GetUIItemState =R"doc(Get the boolean value defined by key and itemState.

Parameter ``key``:
    The key used to retrieve UIItem state values.

Parameter ``itemState``:
    The UIItemStateType that specifies which state value to get.

Parameter ``defaultIfKeyNotFound``:
    The value to return if state value has not been specified.

Returns:
    bool value associated with key, or defaultIfKeyNotFound if no
    entry is found matching the key.

)doc";

static const char * __doc_Bentley_MstnPlatform_ISessionMgr_SetUIItemState =R"doc(Set the boolean value that defines the state of a UI item. This will
trigger a SystemEvent.ApplicationSyncUIItem event.

Parameter ``key``:
    The key that defines the name of the entry to modify or create.

Parameter ``itemState``:
    The UIItemStateType that specifies which state value to set.

Parameter ``value``:
    The boolean value.

Parameter ``sendImmediateMessage``:
    If true send immediate sync message, if false the sync message
    will be sent in the next UISync timer cycle.

)doc";

static const char * __doc_Bentley_MstnPlatform_ISessionMgr_SaveDgnFileChanges =R"doc(Write all in-memory changes to the disk for each DgnFile in the list.

)doc";

static const char * __doc_Bentley_MstnPlatform_ISessionMgr_GetWriteableFiles =R"doc(Returns the list of all writeable files, including any activated
references.

)doc";

static const char * __doc_Bentley_MstnPlatform_ISessionMgr_DropSessionMonitor =R"doc(Drop an existing SessionMonitor.

Parameter ``mon``:
    the SessionMonitor object to remove and deactivate.

Remark:
    s SessionMonitors are automatically removed when MDL applications
    are unloaded.

See also:
    AddSessionMonitor.

)doc";

static const char * __doc_Bentley_MstnPlatform_ISessionMgr_AddSessionMonitor =R"doc(Add a new SessionMonitor.

Parameter ``mon``:
    the new SessionMonitor object. This object will be notified when
    session-related events occur until it is dropped using
    DropSessionMonitor. Ownership of the monitor object is *not*
    transferred to the SessionMgr. The caller must ensure this object
    remains valid until it is dropped.

See also:
    DropSessionMonitor.

)doc";

static const char * __doc_Bentley_MstnPlatform_ISessionMgr_CreateNewDgnFile =R"doc(Prompts the user to create a new DGN file and then optionally makes it
the Master DGN.

Returns:
    SUCCESS if a file was created; otherwise, a non-zero error status
    if the user cancelled, or an error status code based on
    DGNOPEN_STATUS_BASE if the file creation failed.

Parameter ``newName``:
    The file path of the newly created file if successful

Parameter ``defaultDir``:
    Optional:The default directory.

Parameter ``switchToNewFile``:
    Make the new file the Master DGN?

Remark:
    s This function works with MSDocumentManager to locate and manage
    files. In stand-alone MicroStation, the default directory is
    _DGNDIR, if *defaultDir* is not specified. The default seed file
    is MS_DESIGNSEED or the previously selected seed file and the
    default seed file directory is MS_SEEDFILES.

Remark:
    s If *switchToNewFile* is <code>true</code>, then this function
    will call #FindDesignFile (*allowCancel=<code>true</code>)*
    followed by #SwitchToNewFile.

See also:
    SwitchToNewFile

)doc";

static const char * __doc_Bentley_MstnPlatform_ISessionMgr_OpenDgnFileDialog =R"doc(Prompts the user to select a file.


Remark:
    s This function works with MSDocumentManager to locate and manage
    files. In stand-alone MicroStation, the standard File Open dialog
    is used. The default directory is MS_DEF or the previously
    selected directory.

Remark:
    s The returned DgnDocument object is not open.

See also:
    SwitchToNewFile



Returns  (Tuple, 0):
    NULL, if the user hit Cancel; else, a pointer to a document object
    that stores the path to the file that was chosen.

Returns (Tuple, 1) :
	status.  SUCCESS if a file was chosen; otherwise, the error status returned
    by the document manager.

)doc";

static const char * __doc_Bentley_MstnPlatform_ISessionMgr_FindDesignFile =R"doc(Opens a file from a specified file name or path.

Parameter ``inFileName``:
    The name or path of the file to be opened.

Parameter ``inModelName``:
    Will be non-NULL if a specific model will be opened.

Parameter ``fileType``:
    The format of the file.

Parameter ``allowCancel``:
    Pass <code>true</code> if MicroStation should prompt the user to
    accept or cancel if the file cannot be opened read-write because
    of a sharing violation. If *allowCancel* is <code>false</code>,
    the file is opened read-only without prompting the user.

Remark:
    s This function works with MSDocumentManager to locate and manage
    files. In stand-alone MicroStation, if *inFilename* is not a
    complete file path, this function will look for it in the
    directories defined by MS_DEF.

Remark:
    s The newly opened file does *not* become the MasterDGN. Call
    #SwitchToNewFile to make the resulting document the MasterDGN.

Remark:
    s If the file is read-only on disk, then it will be opened read-
    only. Otherwise, this function will try to open the file read-
    write. If the file cannot be opened read-write because of a
    sharing violation, then it is opened read-only. If the file is not
    in a native MicroStation file format, then it will be opened read-
    only.

Remark:
    s If the file is the same as the MasterDGN, it is first closed and
    the current session is ended.

See also:
    SwitchToNewFile



Returns (Tuple, 0):
    A pointer to the newly opened file if successful, or NULL if the
    file could not be found or opened. See *status.*

Returns (Tuple, 1):
	status. 
    SUCCESS if the file was opened
    )doc";

static const char * __doc_Bentley_MstnPlatform_ISessionMgr_SwitchToNewFile =R"doc(Makes the specified file the Master DGN, opening it if necessary.

Returns:
    SUCCESS if *doc* was opened (if necessary) and has become the new
    Master DGN. See #FindDesignFile for errors that can result from a
    failed attempt to open a file.

Parameter ``doc``:
    Identifies the DGN to become the new master.

Parameter ``inputModelName``:
    The model in *doc* to become active

Parameter ``fileType``:
    The format of the file. Should be one of the GRAPHICSFILE_...
    values.

Parameter ``doUpdate``:
    Pass <code>true</code> if MicroStation should issue the UPDATE ALL
    command after making this file master.

Parameter ``releaseReferences``:
    Pass <code>true</code> to disable reference file load
    optimization. If <code>true</code>, the new master DGN will be
    forced to load all of its references, even those that are already
    loaded by the current master DGN. Normally, you should pass pass
    <code><code>false</code></code> for this parameter.

Parameter ``reopeningAfterSave``:
    Is this open being peformed after a save?

Parameter ``runInitUCM``:
    Runs the user command specified by MS_IT.

Remark:
    s Call #FindDesignFile or #OpenDgnFileDialog to open a file and
    obtain a Document.

Remark:
    s This function closes the current Master DGN, if any, and ends
    the previous session. It then begins a new session. See
    SessionManager for a description of what happens when a session
    ends and starts.

Remark:
    s If *doc* is not open, then this function will try to open it
    from the file path of the document. See FindDesignFile for when a
    file is opened read-only or read-write.

Remark:
    s If *doc* is not open and if its file format can be inferred from
    the file extension, then *fileType* will be inferred from the file
    extension. Specifically, if the file extension is found in the
    MS_DESIGNFILTER list, then GRAPHICSFILE_UStn will be inferred.
    File extensions such as DGNLIB, IGES, DXF, CGM, and DWG map to
    like-named GRAPHICSFILE_... values.

Remark:
    s See #FindDesignFile for the case where *fileType* is
    GRAPHICSFILE_IGES or GRAPHICSFILE_CGM.

See also:
    FindDesignFile

)doc";

static const char * __doc_Bentley_MstnPlatform_ISessionMgr_SetActiveModelLocked =R"doc()doc";

static const char * __doc_Bentley_MstnPlatform_ISessionMgr_IsActiveModelLocked =R"doc()doc";

static const char * __doc_Bentley_MstnPlatform_ISessionMgr_SetAutoLockActiveModel =R"doc()doc";

static const char * __doc_Bentley_MstnPlatform_ISessionMgr_InTransactableFile =R"doc(Is this modelRef from a transactable file.

)doc";

static const char * __doc_Bentley_MstnPlatform_ISessionMgr_InActiveFile =R"doc(Is this modelRef from the same file as the active model.

)doc";

static const char * __doc_Bentley_MstnPlatform_ISessionMgr_InMasterFile =R"doc(Is this modelRef from the master file.

)doc";

static const char * __doc_Bentley_MstnPlatform_ISessionMgr_IsActiveModel =R"doc(Is this modelRef the active model.

)doc";

static const char * __doc_Bentley_MstnPlatform_ISessionMgr_IsActiveDgnFile =R"doc(Is this the file of the active model.

)doc";

static const char * __doc_Bentley_MstnPlatform_ISessionMgr_IsMasterDgnFile =R"doc(Is this the master file.

)doc";

static const char * __doc_Bentley_MstnPlatform_ISessionMgr_IsReadyForUIProcessing =R"doc(Return true if Session's active model has been initialized and is
available to populate of model specific data in UI.

)doc";

static const char * __doc_Bentley_MstnPlatform_ISessionMgr_IsDesignFileInitialized =R"doc(Return true if Session is active and design file has been initailized.
Populating of model specific UI items should not happen until this
method returns true.

)doc";

static const char * __doc_Bentley_MstnPlatform_ISessionMgr_IsMasterFileClosing =R"doc(Return true if Session is closing, This allows UI items to ignore
window close events.

)doc";

static const char * __doc_Bentley_MstnPlatform_ISessionMgr_GetActiveDgnFile =R"doc(Get the DgnFileP for the current active model

Returns:
    The DgnFileP for the current active model.

)doc";

static const char * __doc_Bentley_MstnPlatform_ISessionMgr_GetMasterDgnFile =R"doc(Get the DgnFileP for the current Master DGN file

Returns:
    The DgnFileP for the current Master DGN file.

)doc";

static const char * __doc_Bentley_MstnPlatform_ISessionMgr_GetMaster =R"doc(Get the Document for the Master DGN

Returns:
    The document for the current Master DGN file, or NULL.

)doc";

static const char * __doc_Bentley_MstnPlatform_ISessionMgr_GetManager =R"doc()doc";

static const char * __doc_Bentley_MstnPlatform_ISessionMgr_GetMicroStationDgnHost =R"doc()doc";

//=======================================================================================
// Trampoline class for SessionMonitor
// @bsiclass                                                                   02/23
//=======================================================================================
struct PySessionMonitor : SessionMonitor
    {
    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       2/2023
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void _OnMasterFileStart(DgnFileR dgnFile) override
        {
        auto tmp = py::cast(dgnFile, py::return_value_policy::reference);   // See : https://github.com/pybind/pybind11/issues/2516  
        PYBIND11_OVERRIDE_EX(void, SessionMonitor, _OnMasterFileStart, dgnFile); 
        }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       2/2023
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void _OnMasterFileStop(DgnFileR dgnFile, bool changingFiles) override
        { 
        auto tmp = py::cast(dgnFile, py::return_value_policy::reference);     
        PYBIND11_OVERRIDE_EX(void, SessionMonitor, _OnMasterFileStop, dgnFile, changingFiles); 
        }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       2/2023
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void _OnModelRefPreActivate(DgnModelRefR modelRef) override
        { 
        auto tmp = py::cast(modelRef, py::return_value_policy::reference);     
        PYBIND11_OVERRIDE_EX(void, SessionMonitor, _OnModelRefPreActivate, modelRef); 
        }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       2/2023
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void _OnModelRefActivate(DgnModelRefR newModelRef, DgnModelRefP oldModelRef) override
        { 
        auto tmpNew = py::cast(newModelRef, py::return_value_policy::reference);     
        auto tmpOld = py::cast(oldModelRef, py::return_value_policy::reference);     
        PYBIND11_OVERRIDE_EX(void, SessionMonitor, _OnModelRefActivate, newModelRef, oldModelRef); 
        }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       2/2023
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void _OnModelRefActivated(DgnModelRefR newModelRef, DgnModelRefP oldModelRef) override
        { 
        auto tmpNew = py::cast(newModelRef, py::return_value_policy::reference);     
        auto tmpOld = py::cast(oldModelRef, py::return_value_policy::reference);     
        PYBIND11_OVERRIDE_EX(void, SessionMonitor, _OnModelRefActivated, newModelRef, oldModelRef); 
        }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       2/2023
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void _OnReleaseWriteLock(T_DgnFilePtrVectorCR dgnFileVector) override
        { 
        auto tmp = py::cast(dgnFileVector, py::return_value_policy::reference);     
        PYBIND11_OVERRIDE_EX(void, SessionMonitor, _OnReleaseWriteLock, dgnFileVector); 
        }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       2/2023
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void _OnReleasedWriteLock(T_DgnFilePtrVectorCR dgnFileVector) override
        { 
        auto tmp = py::cast(dgnFileVector, py::return_value_policy::reference);     
        PYBIND11_OVERRIDE_EX(void, SessionMonitor, _OnReleasedWriteLock, dgnFileVector); 
        }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       2/2023
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void _OnWriteLocked(DgnFileR dgnFile) override
        { 
        auto tmp = py::cast(dgnFile, py::return_value_policy::reference);   // See : https://github.com/pybind/pybind11/issues/2516  
        PYBIND11_OVERRIDE_EX(void, SessionMonitor, _OnWriteLocked, dgnFile); 
        }


    };

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_ISessionMgr(py::module_& m)
    {

    //===================================================================================
    // enum GraphicsFileType
    py::enum_< GraphicsFileType>(m, "GraphicsFileType", py::arithmetic())
        .value("eGRAPHICSFILE_WildCard", GRAPHICSFILE_WildCard)    
        .value("eGRAPHICSFILE_UStn", GRAPHICSFILE_UStn)    
        .value("eGRAPHICSFILE_Sheet", GRAPHICSFILE_Sheet)    
        .value("eGRAPHICSFILE_HLine", GRAPHICSFILE_HLine)    
        .value("eGRAPHICSFILE_DWG", GRAPHICSFILE_DWG)    
        .value("eGRAPHICSFILE_DXF", GRAPHICSFILE_DXF)    
        .value("eGRAPHICSFILE_DXB", GRAPHICSFILE_DXB)    
        .value("eGRAPHICSFILE_IGES", GRAPHICSFILE_IGES)    
        .value("eGRAPHICSFILE_CGM", GRAPHICSFILE_CGM)    
        .value("eGRAPHICSFILE_RDL", GRAPHICSFILE_RDL)    
        .value("eGRAPHICSFILE_TriForma", GRAPHICSFILE_TriForma)    
        .value("eGRAPHICSFILE_UStnV7", GRAPHICSFILE_UStnV7)    
        .value("eGRAPHICSFILE_CAD", GRAPHICSFILE_CAD)    
        .value("eGRAPHICSFILE_CEL", GRAPHICSFILE_CEL)    
        .value("eGRAPHICSFILE_3DStudio", GRAPHICSFILE_3DStudio)    
        .value("eGRAPHICSFILE_DgnLib", GRAPHICSFILE_DgnLib)    
        .value("eGRAPHICSFILE_OBJ", GRAPHICSFILE_OBJ)    
        .value("eGRAPHICSFILE_SKP", GRAPHICSFILE_SKP)    
        .export_values();


    //===================================================================================
    // enum ChooseMasterFileStatus
    py::enum_< ChooseMasterFileStatus>(m, "ChooseMasterFileStatus", py::arithmetic())
        .value("eCHOOSEMASTERFILE_STATUS_Invalid", CHOOSEMASTERFILE_STATUS_Invalid)
        .value("eCHOOSEMASTERFILE_STATUS_Handled", CHOOSEMASTERFILE_STATUS_Handled)
        .value("eCHOOSEMASTERFILE_STATUS_Canceled", CHOOSEMASTERFILE_STATUS_Canceled)
        .export_values();

    //===================================================================================
    // enum class UIItemStateType
    py::enum_< UIItemStateType>(m, "UIItemStateType")
        .value("eNone_", UIItemStateType::None)
        .value("eVisible", UIItemStateType::Visible)
        .value("eEnabled", UIItemStateType::Enabled)
        .value("eChecked", UIItemStateType::Checked)
        .export_values();

    //===================================================================================
    // struct SessionMonitor
    py::class_< SessionMonitor, PySessionMonitor> c1(m, "SessionMonitor");

    c1.def(py::init<>());
    c1.def("_OnMasterFileStart", &SessionMonitor::_OnMasterFileStart, "dgnFile"_a);
    c1.def("_OnMasterFileStop", &SessionMonitor::_OnMasterFileStop, "dgnFile"_a, "changingFiles"_a);
    c1.def("_OnModelRefPreActivate", &SessionMonitor::_OnModelRefPreActivate, "modelRef"_a);
    c1.def("_OnModelRefActivate", &SessionMonitor::_OnModelRefActivate, "newModelRef"_a, "oldModelRef"_a);
    c1.def("_OnModelRefActivated", &SessionMonitor::_OnModelRefActivated, "newModelRef"_a, "oldModelRef"_a);
    c1.def("_OnReleaseWriteLock", &SessionMonitor::_OnReleaseWriteLock, "dgnFileVector"_a);
    c1.def("_OnReleasedWriteLock", &SessionMonitor::_OnReleasedWriteLock, "dgnFileVector"_a);
    c1.def("_OnWriteLocked", &SessionMonitor::_OnWriteLocked, "dgnFile"_a);


    //===================================================================================
    // struct ISessionMgr
    py::class_< ISessionMgr, std::unique_ptr < ISessionMgr, py::nodelete>> c2(m, "ISessionMgr");

    c2.def_property_readonly_static("Manager", [] (py::object const&) { return std::unique_ptr< ISessionMgr, py::nodelete>(&ISessionMgr::GetManager()); });
    c2.def_static("GetManager", [] () { return std::unique_ptr< ISessionMgr, py::nodelete>(&ISessionMgr::GetManager()); }, DOC(Bentley, MstnPlatform, ISessionMgr, GetManager));
    
    c2.def_property_readonly("Master", &ISessionMgr::GetMaster);
    c2.def("GetMaster", &ISessionMgr::GetMaster, py::return_value_policy::reference_internal, DOC(Bentley, MstnPlatform, ISessionMgr, GetMaster));
    
    c2.def_property_readonly_static("MasterDgnFile", [] (py::object const&) { return ISessionMgr::GetMasterDgnFile(); });
    c2.def_static("GetMasterDgnFile", &ISessionMgr::GetMasterDgnFile, py::return_value_policy::reference, DOC(Bentley, MstnPlatform, ISessionMgr, GetMasterDgnFile));
    
    c2.def_property_readonly_static("ActiveDgnFile", [] (py::object const&) { return ISessionMgr::GetActiveDgnFile(); });
    c2.def_static("GetActiveDgnFile", &ISessionMgr::GetActiveDgnFile, py::return_value_policy::reference, DOC(Bentley, MstnPlatform, ISessionMgr, GetActiveDgnFile));
    
    c2.def_property_readonly_static("ActiveDgnModel", [] (py::object const&) { return ISessionMgr::GetActiveDgnModelP(); });
    c2.def_static("GetActiveDgnModel", &ISessionMgr::GetActiveDgnModelP, py::return_value_policy::reference);
    
    c2.def_static("IsMasterFileClosing", &ISessionMgr::IsMasterFileClosing, DOC(Bentley, MstnPlatform, ISessionMgr, IsMasterFileClosing));    
    c2.def_static("IsDesignFileInitialized", &ISessionMgr::IsDesignFileInitialized, DOC(Bentley, MstnPlatform, ISessionMgr, IsDesignFileInitialized));
    
    c2.def("IsReadyForUIProcessing", &ISessionMgr::IsReadyForUIProcessing, DOC(Bentley, MstnPlatform, ISessionMgr, IsReadyForUIProcessing));
    
    c2.def_static("IsMasterDgnFile", &ISessionMgr::IsMasterDgnFile, "dgnFile"_a, DOC(Bentley, MstnPlatform, ISessionMgr, IsMasterDgnFile));
    c2.def_static("IsActiveDgnFile", &ISessionMgr::IsActiveDgnFile, "dgnFile"_a, DOC(Bentley, MstnPlatform, ISessionMgr, IsActiveDgnFile));
    
    c2.def_property_readonly_static("ActiveDgnModelRef", [] (py::object const&) { return ISessionMgr::GetActiveDgnModelRefP(); });
    c2.def_static("GetActiveDgnModelRef", &ISessionMgr::GetActiveDgnModelRefP, py::return_value_policy::reference);
    
    c2.def_static("IsActiveModel", &ISessionMgr::IsActiveModel, "modelRef"_a, DOC(Bentley, MstnPlatform, ISessionMgr, IsActiveModel));
    c2.def_static("InMasterFile", &ISessionMgr::InMasterFile, "modelRef"_a, DOC(Bentley, MstnPlatform, ISessionMgr, InMasterFile));
    c2.def_static("InActiveFile", &ISessionMgr::InActiveFile, "modelRef"_a, DOC(Bentley, MstnPlatform, ISessionMgr, InActiveFile));
    c2.def_static("InTransactableFile", &ISessionMgr::InTransactableFile, "modelRef"_a, DOC(Bentley, MstnPlatform, ISessionMgr, InTransactableFile));
    c2.def_static("SetAutoLockActiveModel", &ISessionMgr::SetAutoLockActiveModel, "value"_a, DOC(Bentley, MstnPlatform, ISessionMgr, SetAutoLockActiveModel));
    
    c2.def_static("IsActiveModelLocked", &ISessionMgr::IsActiveModelLocked, DOC(Bentley, MstnPlatform, ISessionMgr, IsActiveModelLocked));
    c2.def_static("SetActiveModelLocked", &ISessionMgr::SetActiveModelLocked, "locked"_a, DOC(Bentley, MstnPlatform, ISessionMgr, SetActiveModelLocked));

    c2.def("SwitchToNewFile", &ISessionMgr::SwitchToNewFile, "doc"_a, "inoutModelName"_a, "fileType"_a, "doUpdate"_a, "releaseReferences"_a, "reopeningAfterSave"_a = false, "runInitUCM"_a = false, DOC(Bentley, MstnPlatform, ISessionMgr, SwitchToNewFile));
    
    c2.def("FindDesignFile", [] (ISessionMgr& self, WCharCP inFileName, WCharCP inModelName, int fileType, bool allowCancel)
           {
           DgnFileStatus status = DgnFileStatus::DGNFILE_STATUS_UnknownError;
           auto retVal = self.FindDesignFile(status, inFileName, inModelName, fileType, allowCancel);
           return py::make_tuple(retVal, status);
           }, "inFileName"_a, "inModelName"_a, "fileType"_a, "allowCancel"_a, DOC(Bentley, MstnPlatform, ISessionMgr, FindDesignFile));

    c2.def("OpenDgnFileDialog", [] (ISessionMgr& self)
           {
           DgnFileStatus status = DgnFileStatus::DGNFILE_STATUS_UnknownError;
           auto retVal = self.OpenDgnFileDialog(status);
           return py::make_tuple(retVal, status);
           }, DOC(Bentley, MstnPlatform, ISessionMgr, OpenDgnFileDialog));

    c2.def("CreateNewDgnFile", &ISessionMgr::CreateNewDgnFile, "newName"_a, "defaultDir"_a, "switchToNewFile"_a, DOC(Bentley, MstnPlatform, ISessionMgr, CreateNewDgnFile));

    c2.def_static("AddSessionMonitor", [] (SessionMonitor& mon)
        {
        py::str str = py::globals()["__mdlDescr__"];
        WString wstr (std::string (str).c_str ());
        SaveAndSwitchMdlDesc saver (wstr.c_str ());
        ISessionMgr::AddSessionMonitor (mon);
        }, "monitor"_a, DOC(Bentley, MstnPlatform, ISessionMgr, AddSessionMonitor));

    c2.def_static("DropSessionMonitor", [] (SessionMonitor& mon)
        {
        py::str str = py::globals()["__mdlDescr__"];
        WString wstr (std::string (str).c_str ());
        SaveAndSwitchMdlDesc saver (wstr.c_str ());
        ISessionMgr::DropSessionMonitor (mon);
        }, "monitor"_a, DOC(Bentley, MstnPlatform, ISessionMgr, AddSessionMonitor));

    c2.def_property_readonly("WriteableFiles", &ISessionMgr::GetWriteableFiles);
    c2.def("GetWriteableFiles", &ISessionMgr::GetWriteableFiles, py::return_value_policy::reference_internal, DOC(Bentley, MstnPlatform, ISessionMgr, GetWriteableFiles));
    
    c2.def("SaveDgnFileChanges", &ISessionMgr::SaveDgnFileChanges, "dgnFileVector"_a, DOC(Bentley, MstnPlatform, ISessionMgr, SaveDgnFileChanges));
    c2.def("SetUIItemState", &ISessionMgr::SetUIItemState, "key"_a, "itemState"_a, "value"_a, "sendImmediateMessage"_a = false, DOC(Bentley, MstnPlatform, ISessionMgr, SetUIItemState));
    c2.def("GetUIItemState", &ISessionMgr::GetUIItemState, "key"_a, "itemState"_a, "defaultIfKeyNotFound"_a, DOC(Bentley, MstnPlatform, ISessionMgr, GetUIItemState));
    c2.def("SetUIItemMenuMarkState", &ISessionMgr::SetUIItemMenuMarkState, "key"_a, "value"_a = MARK_NONE, "sendimmediateMessage"_a = false, DOC(Bentley, MstnPlatform, ISessionMgr, SetUIItemMenuMarkState));
    c2.def("GetUIItemMenuMarkState", &ISessionMgr::GetUIItemMenuMarkState, "key"_a, "defaultIfKeyNotFound"_a = MARK_NONE, DOC(Bentley, MstnPlatform, ISessionMgr, GetUIItemMenuMarkState));
    c2.def("RemoveUIItemStateEntry", &ISessionMgr::RemoveUIItemStateEntry, "key"_a, DOC(Bentley, MstnPlatform, ISessionMgr, RemoveUIItemStateEntry));
    
    c2.def("IsActiveWorkSetAssociatedToCONNECTProject", &ISessionMgr::IsActiveWorkSetAssociatedToCONNECTProject);    
    c2.def("IsActiveWorkSetNoWorkSet", &ISessionMgr::IsActiveWorkSetNoWorkSet);    
    c2.def("IsActiveWorkSetAssociatedToCONNECTProjectAndDGNMode", &ISessionMgr::IsActiveWorkSetAssociatedToCONNECTProjectAndDGNMode);
    }