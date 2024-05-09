/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnPlatform\source\dgnfile.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <DgnPlatform/DgnFile.h>



static const char * __doc_Bentley_DgnPlatform_DgnFile_GetLastActiveModelId =R"doc(Get the ModelId of the last active model

Returns:
    The ModelId of the last active model, or INVALID_MODELID if there
    is no active model)doc";

static const char * __doc_Bentley_DgnPlatform_DgnFile_GetModelBackgroundColor =R"doc(Get the background color for all models of the given type.

Returns:
    ERROR if type is not found.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnFile_SetModelBackgroundColor =R"doc(Set the background color for all models of a given type.

Returns:
    ERROR if type is not found.

Remark:
    s If the model type is DgnModelType::Normal, the DgnColorMap's
    background color entry will be updated.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnFile_GetNamedViews =R"doc(Get a const reference to the Named Views in this DgnFile.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnFile_GetViewGroups =R"doc(Get a const reference to the View Groups in this DgnFile.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnFile_IsSameFile =R"doc(Check if two fully qualified file-names represent the same physical
file.

Parameter ``fileName1``:
    Fully qualified name of first file

Parameter ``fileName2``:
    Fully qualified name of second file

Parameter ``compareMask``:
    Mask which controls degree of comparison

Returns:
    true if the two files represent the same file

Remark:
    s The parameter <i>compareMask</i> is the OR'ed mask of one or
    more of the possible values:<DL> <DT>
    <TT>FileCompareMask::BaseNameAndExtension</TT> <DD>Check if base-
    name and extension are different. Set this if you wish to conclude
    that different base-name and extension represent different files.
    If different then return value is false. <DT>
    <TT>FileCompareMask::FileStat</TT> <DD>Check if file-stats are
    different. If different then return value is false. <DT>
    <TT>FileCompareMask::All</TT> <DD>Do all the checks </DL>

Remark:
    s If the fully qualified names are the same, then the function
    will always return that the file-names represent the same file)doc";

static const char * __doc_Bentley_DgnPlatform_DgnFile_FindAppData =R"doc(Search for the DgnFileAppData on this DgnFile with ``key.`` See
discussion of keys in #AddAppData.

Returns:
    A pointer to the DgnFileAppData object with ``key.`` NULL if not
    found. @DotNetMethodExclude)doc";

static const char * __doc_Bentley_DgnPlatform_DgnFile_DropAppData =R"doc(Remove a DgnFileAppData object from this DgnFile by its key.

Parameter ``key``:
    The key to find the appropriate DgnFileAppData. See discussion of
    keys in #AddAppData.

Returns:
    SUCCESS if a DgnFileAppData object with ``key`` was found and was
    dropped. ERROR if no DgnFileAppData with ``key`` exists. @note
    After the DgnFileAppData object is removed, its
    DgnFileAppData::_OnCleanup method is called. @DotNetMethodExclude)doc";

static const char * __doc_Bentley_DgnPlatform_DgnFile_AddAppData =R"doc(Add an application data object onto this DgnFile. After this call, the
``appData`` object will be notified for the events in the
DgnFileAppData interface. This is a useful technique for applications
to store data that is specific to this DgnFile, as it can be retrieved
quickly through a pointer to this DgnFile and because its lifecycle
can be made to match the DgnFile.

Parameter ``key``:
    A unique key to differentiate ``appData`` from all of the other
    DgnFileAppData objects stored on this DgnFile. By convention,
    uniqueness is enforced by using the address of a (any) static
    object in your application. Since all applications share the same
    address space, every key will be unique. Note that this means that
    the value of your key will be different for every session. But
    that's OK, the only thing important about ``key`` is that it be
    unique.

Parameter ``appData``:
    The application's instance of a subclass of DgnFileAppData to
    store on this DgnFile.

Returns:
    SUCCESS if ``appData`` was successfully added to this DgnFile.
    Note that it is not legal to add or drop DgnFileAppData to/from
    this DgnFile from within any of the methods of DgnFileAppData.
    @DotNetMethodExclude)doc";

static const char * __doc_Bentley_DgnPlatform_DgnFile_CopyModelContents =R"doc(Copy the contents of one model into another

Parameter ``destModel``:
    The destination of the copy. Should be a newly created model that
    is empty.

Parameter ``sourceModel``:
    The model to be copied.

Parameter ``dictionaryElements``:
    A list of elements from the dictionaryModel that should be copied.
    Generally, these are ViewGroups or NamedViews.

Remark:
    s To copy a model, first call #CreateNewModel to create a new,
    empty model. Then call #CopyModelContents to copy the contents of
    the source model into the new model.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnFile_DeleteModel =R"doc(Delete a model (calls ITxn::DeleteModel).

Parameter ``model``:
    DgnModel to delete

Returns:
    SUCCESS if the model was successfully deleted)doc";

static const char * __doc_Bentley_DgnPlatform_DgnFile_GetSignatureCount =R"doc(Get the number of digital signatures in this file.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnFile_IsReadOnly =R"doc(Determine whether this file is read only.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnFile_IsOpen =R"doc(Determine whether this file is currently opened. @note Readonly files
are opened, read, and then closed inside the call to LoadDgnFile.
Therefore, readonly files will never return true for this method.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnFile_IsLoaded =R"doc(Determine whether this file is currently " loaded ". This will be true
if LoadDgnFile has been successfully called. @See LoadDgnFile)doc";

static const char * __doc_Bentley_DgnPlatform_DgnFile_IsTransactable =R"doc(Determine whether this file is transactable (journalled by the
ITxnManager and subject to undo/redo).)doc";

static const char * __doc_Bentley_DgnPlatform_DgnFile_GetEmbeddedFileId =R"doc(Get the Embedded Id for this file. If the file is not embedded, the
value will be 0.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnFile_GetEmbeddedName =R"doc(Get the EmbeddedName of this DgnFile. If the file is an embedded file,
this will be just the Embed part of the PackagedFileName. If the file
is not embedded, it will be the same as " GetName ". Therefore this may
or may not be a physical file and may or may not contain path
information, depending on whether this file is embedded.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnFile_GetPackageName =R"doc(Get the PackageName for this DgnFile. If the file is an embedded file
this will be just the Package part of the PackagedFileName. If the
file is not embedded, this will be the same as " GetName ( ) ". It is
always the name of a physical file.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnFile_GetPackagedName =R"doc(Get the PackagedFileName of this DgnFile. This will be in
Package<id>Embed format for embedded files and a filename for non-
embedded files. Note:" Package " will have path information but " Embed "
will not. This string MAY contain the "<> " characters that make it an
illegal filename.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnFile_GetFileName =R"doc(Get the full path of the physical file associated with this file. @See
GetDocument)doc";

static const char * __doc_Bentley_DgnPlatform_DgnFile_GetDocument =R"doc(Get the DgnDocument associated with this file.

Returns:
    the DgnDocument associated with this file, or NULL @note This
    method returns NULL if this DgnFile does not represent a file or
    any actual document. For example, this DgnFile might be a
    temporary buffer used to hold data in memory only.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnFile_GetLastSaveTime =R"doc(Get the time that this file was last saved. The DgnFile must be loaded
before calling this method. @See ProcessChanges)doc";

static const char * __doc_Bentley_DgnPlatform_DgnFile_GetUniqueModelName =R"doc(Generate a model name that is not currently in use in this file

Parameter ``uniqueModelName``:
    unique name that was generated, if possible

Parameter ``baseName``:
    base model name to start with (optional)

Parameter ``forCopy``:
    If the object with the new name is a copy of the object of
    'baseName', then new name will be built with " - Copy " suffix)doc";

static const char * __doc_Bentley_DgnPlatform_DgnFile_SetTransactable =R"doc(Allow ITxnManager to log changes to this file.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnFile_DoSaveTo =R"doc(Save the DgnFile to a new physical file with the given file name.
After this call, this file continues to refer to the original file.

Parameter ``newFileName``:
    The new file name

Parameter ``format``:
    The file format. Only DgnFileFormatType::V8 is supported unless
    hosted by MicroStation.

See also:
    #DoSaveAs)doc";

static const char * __doc_Bentley_DgnPlatform_DgnFile_ProcessChanges =R"doc(Process the changes in all of the DgnModels of this file, saving them
to disk if appropriate. If the " abandon changes " flag is on for this
file, then all of the DgnModels are emptied. After this call,
#HasPendingChanges will return false.

Parameter ``reason``:
    The reason the changes are being processed. This reason will be
    passed to listeners so they can take appropriate action.

Parameter ``timestamp``:
    The time (in milliseconds since 1/1/1970 - see
    BeTimeUtilities::GetCurrentTimeAsUnixMillisDouble) to be saved in
    the header and returned by GetLastFileTime. This is supplied by
    the caller, rather than using the current time, so that it can be
    saved and compared. If timestamp is 0, the current time is used.

See also:
    SetAbandonChangesFlag, HasPendingChanges, GetLastSaveTime)doc";

static const char * __doc_Bentley_DgnPlatform_DgnFile_ClearAbandonChangesFlag =R"doc(Turn off the " abandon changes " flag. When the " abandon " flag is on,
none of the changes are written to the disk, even if #ProcessChanges
is called. @See SetAbandonChangesFlag)doc";

static const char * __doc_Bentley_DgnPlatform_DgnFile_SetAbandonChangesFlag =R"doc(Set the " abandon changes " flag. When the " abandon " flag is on, none of
the changes are written to the disk, even if #ProcessChanges is
called. @See ClearAbandonChangesFlag)doc";

static const char * __doc_Bentley_DgnPlatform_DgnFile_SetFullSaveFlag =R"doc(Set the " full save " flag. This forces the entire file to be rewritten
on the next call to #ProcessChanges, even if there have been no
changes to it in this session. @See ProcessChanges)doc";

static const char * __doc_Bentley_DgnPlatform_DgnFile_HasPendingChanges =R"doc(Determine whether this file has any changes that need to be written to
the disk. @See ProcessChanges)doc";

static const char * __doc_Bentley_DgnPlatform_DgnFile_LoadModelById =R"doc(Search this file for a model with the specific ModelId, loading from
disk if necessary.

Parameter ``modelID``:
    The ModelId of the model of interest. @See FillSectionsInModel
    @See GetLoadedModelsCollection @See GetModelIndex @See
    GetDictionaryModel

Remark:
    s see DgnFile::AddRootModel

Remark:
    s see DgnFile::LoadRootModelById)doc";

static const char * __doc_Bentley_DgnPlatform_DgnFile_FindLoadedModelById =R"doc(Query if the specified model has already been loaded. @See
GetLoadedModelsCollection @See LoadModelById)doc";

static const char * __doc_Bentley_DgnPlatform_DgnFile_GetDefaultModelId =R"doc(Get the ModelId of the default model in this file.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnFile_FindModelIdByName =R"doc(Find the ModelId of the model with the specified name.

Returns:
    The model's ModelId or INVALID_MODELID if not found.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnFile_GetDictionaryModel =R"doc(Get the dictionary model for this file. @See
FillDictionaryModelSections)doc";

static const char * __doc_Bentley_DgnPlatform_DgnFile_GetLoadedModelsCollection =R"doc(Get the collection that can be used to iterate all models currently
loaded from this file. Does not include the dictionary model.<p>
Example:

``
DgnFileR file = ...
for each (DgnModelP model in file.GetLoadedModelsCollection ())
   {
    file.FillSectionsInModel (model, DgnModelSections::All);
      ...
   }
``

@See LoadModelById @See GetModelIndex @See
DgnModel::GetElementsCollection)doc";

static const char * __doc_Bentley_DgnPlatform_DgnFile_Release =R"doc(Decrement the reference count of this file. If this is the last
reference to the file and if there are no outstanding references to
models loaded from this file, then the associated disk file is close
and this object is deleted.

Returns:
    the new reference count)doc";

static const char * __doc_Bentley_DgnPlatform_DgnFile_AddRef =R"doc(Increment the reference count of this file.

Returns:
    the new reference count)doc";

static const char* __doc_Bentley_DgnPlatform_DgnFile_GetModelIndex = R"doc(Detect what models are stored in a file. @See LoadModelById, GetModelIndex,
DgnModel::GetElementsCollection)doc";

static const char * __doc_Bentley_DgnPlatform_DgnFile_FillDictionaryModel =R"doc(Make sure the dictionary model is filled. @See LoadDgnFile,
GetDictionaryModel)doc";

static const char * __doc_Bentley_DgnPlatform_DgnFileAppData__OnModelsReloaded =R"doc(This method is called when the DgnModels in memory are going to be
reloaded. If your DgnFileAppData contains any ElementRefs, they are
invalid after this call. If the method returns true, the
DgnFileAppData is dropped from the DgnFile. Do not delete your
DgnFileAppData in this method. Instead, return true and delete your
DgnFileAppData in your _OnCleanup method.

Parameter ``host``:
    The host DgnFile on which this DgnFileAppData resides.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnFileAppData__OnModelUnDeleted =R"doc(This method is called after a model has been undeleted from the
DgnFile on which this DgnFileAppData resides.

Parameter ``host``:
    The host DgnFile on which this DgnFileAppData resides.

Parameter ``modelID``:
    The model that is being deleted.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnFileAppData__OnModelDelete =R"doc(This method is called before and after a model is deleted from the
DgnFile on which this DgnFileAppData resides.

Parameter ``host``:
    The host DgnFile on which this DgnFileAppData resides.

Parameter ``when``:
    The phase of the save operation.

Parameter ``modelID``:
    The model that is being deleted.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnFileAppData__OnSave =R"doc(This method is called before and after a " Save " operation is performed
on the DgnFile on which this DgnFileAppData resides.

Parameter ``host``:
    The host DgnFile on which this DgnFileAppData resides.

Parameter ``when``:
    The phase of the save operation.

Parameter ``changesFlag``:
    The type of save operation being performed.

Parameter ``reason``:
    The reason the Save was initiated.

Parameter ``timestamp``:
    The time the save operation was initiated.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnFileAppData__OnCleanup =R"doc(This method is called whenever this object is removed from its host
DgnFile. This can happen either by an explicit call to
DgnFile::DropAppData, or because the DgnFile itself is being deleted
(in which case all of its DgnFileAppData is notified **before** the
DgnFile is deleted).

Parameter ``host``:
    The host DgnFile on which this DgnFileAppData resided.)doc";


//=======================================================================================
// Trampoline class for DgnFileAppData.
// @bsiclass                                                                   02/23
//=======================================================================================
struct PyDgnFileAppData : DgnFileAppData
    {
    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       2/2023
    +---------------+---------------+---------------+---------------+---------------+------*/        
    virtual void _OnCleanup(DgnFileR host) override
        { PYBIND11_OVERRIDE_PURE_EX(void, DgnFileAppData, _OnCleanup, host); }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       2/2023
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void _OnSave(DgnFileR host, ProcessChangesWhen when, DgnFileChanges changesFlag, DgnSaveReason reason, double timestamp) override
        { PYBIND11_OVERRIDE_EX(void, DgnFileAppData, _OnSave, host, when, changesFlag, reason, timestamp); }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       2/2023
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void _OnModelDelete(DgnFileR host, ProcessChangesWhen when, ModelId modelID) override
        { PYBIND11_OVERRIDE_EX(void, DgnFileAppData, _OnModelDelete, host, when, modelID); }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       2/2023
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void _OnModelUnDeleted(DgnFileR host, ModelId modelID) override
        { PYBIND11_OVERRIDE_EX(void, DgnFileAppData, _OnModelUnDeleted, host, modelID); }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       2/2023
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual bool _OnModelsReloaded(DgnFileR host) override
        { PYBIND11_OVERRIDE_EXR(bool, DgnFileAppData, _OnModelsReloaded, false, host); }    
    };

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_DgnFile(py::module_& m)
    {
    //===================================================================================
    // enum DgnFileRights
    py::enum_< DgnFileRights>(m, "DgnFileRights", py::arithmetic())
        .value("eDGNFILE_RIGHT_Any", DGNFILE_RIGHT_Any)
        .value("eDGNFILE_RIGHT_Print", DGNFILE_RIGHT_Print)
        .value("eDGNFILE_RIGHT_Export", DGNFILE_RIGHT_Export)
        .value("eDGNFILE_RIGHT_Edit", DGNFILE_RIGHT_Edit)
        .value("eDGNFILE_RIGHT_Unlimited_Bit", DGNFILE_RIGHT_Unlimited_Bit)
        .value("eDGNFILE_RIGHT_Unlimited", DGNFILE_RIGHT_Unlimited)
        .export_values();

    //===================================================================================
    // enum class ProcessChangesWhen
    py::enum_< ProcessChangesWhen>(m, "ProcessChangesWhen")
        .value("eBeforeProcessing", ProcessChangesWhen::BeforeProcessing)
        .value("eAfterProcessing", ProcessChangesWhen::AfterProcessing)
        .export_values();

    //===================================================================================
    // enum class DgnFileChanges
    py::enum_< DgnFileChanges>(m, "DgnFileChanges")
        .value("eAbandon", DgnFileChanges::Abandon)
        .value("eSave", DgnFileChanges::Save)
        .value("eFullSave", DgnFileChanges::FullSave)
        .export_values();

    //===================================================================================
    // enum class DgnSaveReason
    py::enum_< DgnSaveReason>(m, "DgnSaveReason")
        .value("eUserInitiated", DgnSaveReason::UserInitiated)
        .value("eApplInitiated", DgnSaveReason::ApplInitiated)
        .value("eReferenceFileSave", DgnSaveReason::ReferenceFileSave)
        .value("eFileClose", DgnSaveReason::FileClose)
        .value("eFileCompress", DgnSaveReason::FileCompress)
        .value("eFileSaveAs", DgnSaveReason::FileSaveAs)
        .value("eAutoTime", DgnSaveReason::AutoTime)
        .value("ePreCommit", DgnSaveReason::PreCommit)
        .value("eSaveSettings", DgnSaveReason::SaveSettings)
        .value("eBackup", DgnSaveReason::Backup)
        .value("eEncrypt", DgnSaveReason::Encrypt)
        .value("ePreCompress", DgnSaveReason::PreCompress)
        .export_values();

    //===================================================================================
    // enum class SeedCopyFlags
    py::enum_< SeedCopyFlags>(m, "SeedCopyFlags")
        .value("eNone", SeedCopyFlags::None)
        .value("eTCBData", SeedCopyFlags::TCBData)
        .value("eDefaultViews", SeedCopyFlags::DefaultViews)
        .value("eAllViewGroups", SeedCopyFlags::AllViewGroups)
        .value("eLevelTable", SeedCopyFlags::LevelTable)
        .value("eColorTable", SeedCopyFlags::ColorTable)
        .value("eFontTable", SeedCopyFlags::FontTable)
        .value("eTextStyleTable", SeedCopyFlags::TextStyleTable)
        .value("eDimStyleTable", SeedCopyFlags::DimStyleTable)
        .value("eMlineStyleTable", SeedCopyFlags::MlineStyleTable)
        .value("eLineStyleTable", SeedCopyFlags::LineStyleTable)
        .value("eFilterTable", SeedCopyFlags::FilterTable)
        .value("eDictionaryTable", SeedCopyFlags::DictionaryTable)
        .value("eReferenceAttach", SeedCopyFlags::ReferenceAttach)
        .value("eRasterRefs", SeedCopyFlags::RasterRefs)
        .value("eAllNamedViews", SeedCopyFlags::AllNamedViews)
        .value("eNamedViewsOfSeed", SeedCopyFlags::NamedViewsOfSeed)
        .value("eApplicationInfo", SeedCopyFlags::ApplicationInfo)
        .value("eAuxCoordSystem", SeedCopyFlags::AuxCoordSystem)
        .value("eAllLevelTables", SeedCopyFlags::AllLevelTables)
        .value("eCreateDefaultModel", SeedCopyFlags::CreateDefaultModel)
        .value("eMaterialPalette", SeedCopyFlags::MaterialPalette)
        .value("eGeoCoordinateSystem", SeedCopyFlags::GeoCoordinateSystem)
        .value("eLevelNameDictionary", SeedCopyFlags::LevelNameDictionary)
        .value("eNoViewGroups", SeedCopyFlags::NoViewGroups)
        .value("eDisplayStyles", SeedCopyFlags::DisplayStyles)
        .value("eDefaultData", SeedCopyFlags::DefaultData)
        .value("eAllData", SeedCopyFlags::AllData)
        .export_values();


    //===================================================================================
    // enum class DgnFileOpenMode
    py::enum_< DgnFileOpenMode>(m, "DgnFileOpenMode")
        .value("eReadOnly", DgnFileOpenMode::ReadOnly)
        .value("eReadWrite", DgnFileOpenMode::ReadWrite)
        .value("ePreferablyReadWrite", DgnFileOpenMode::PreferablyReadWrite)
        .value("eReadWriteFromCopiedFile", DgnFileOpenMode::ReadWriteFromCopiedFile)
        .export_values();

    //===================================================================================
    // enum class DgnFilePurpose
    py::enum_< DgnFilePurpose>(m, "DgnFilePurpose")
        .value("eUnknown", DgnFilePurpose::Unknown)
        .value("eMasterFile", DgnFilePurpose::MasterFile)
        .value("eDgnAttachment_", DgnFilePurpose::DgnAttachment)
        .value("eDgnLib", DgnFilePurpose::DgnLib)
        .value("eActivatedAttachment", DgnFilePurpose::ActivatedAttachment)
        .value("eCellLibrary", DgnFilePurpose::CellLibrary)
        .value("eWorkDgn", DgnFilePurpose::WorkDgn)
        .value("eClipboard", DgnFilePurpose::Clipboard)
        .value("eTemporary", DgnFilePurpose::Temporary)
        .value("eIcons", DgnFilePurpose::Icons)
        .value("eLevelLibrary", DgnFilePurpose::LevelLibrary)
        .value("eOverlay", DgnFilePurpose::Overlay)
        .export_values();

    //===================================================================================
    // struct SeedData
    py::class_< SeedData> c1(m, "SeedData");

    c1.def(py::init<DgnFileP, ModelId, SeedCopyFlags, bool>(), "seedFile"_a, "seedModel"_a, "flags"_a, "headerXattributes"_a, py::keep_alive<1, 2>());

    c1.def_property_readonly("SeedFile", [] (SeedData& self) { return self.m_seedFile; });
    c1.def_readonly("SeedModel", &SeedData::m_seedModel);
    c1.def_readonly("CopyFlags", &SeedData::m_flags);
    c1.def_readonly("HeaderXAttributes", &SeedData::m_headerXAttributes);
    c1.def_readonly("SeedHigestId", &SeedData::m_seedHighestId);


    //===================================================================================
    // struct DgnFileAppData
    py::class_<DgnFileAppData, PyDgnFileAppData> c7(m, "DgnFileAppData");

    if (true)
        {
        //===================================================================================
        // struct DgnFileAppData::Key
        py::class_< DgnFileAppData::Key, AppDataKey> c7_1(c7, "Key");
        }

    c7.def(py::init<>());
    c7.def("_OnCleanup", &DgnFileAppData::_OnCleanup, "host"_a, DOC(Bentley, DgnPlatform, DgnFileAppData, _OnCleanup));
    c7.def("_OnSave", &DgnFileAppData::_OnSave, "host"_a, "when"_a, "changesFlag"_a, "reason"_a, "timestamp"_a, DOC(Bentley, DgnPlatform, DgnFileAppData, _OnSave));
    c7.def("_OnModelDelete", &DgnFileAppData::_OnModelDelete, "host"_a, "when"_a, "modelID"_a, DOC(Bentley, DgnPlatform, DgnFileAppData, _OnModelDelete));
    c7.def("_OnModelUnDeleted", &DgnFileAppData::_OnModelUnDeleted, "host"_a, "modelID"_a, DOC(Bentley, DgnPlatform, DgnFileAppData, _OnModelUnDeleted));
    c7.def("_OnModelsReloaded", &DgnFileAppData::_OnModelsReloaded, "host"_a, DOC(Bentley, DgnPlatform, DgnFileAppData, _OnModelsReloaded));

    //=======================================================================================
    // struct DgnFile
    py::class_<DgnFile, DgnFilePtr> c8(m, "DgnFile");
    bind_PointerVector<DgnFileP>(m, "DgnFilePArray", py::module_local(false));
    py::bind_vector<bvector<DgnFilePtr>>(m, "DgnFilePtrArray", py::module_local(false));

    if (true)
        {

        //=======================================================================================
        // struct LoadedModelsCollection
        py::class_< DgnFile::LoadedModelsCollection> c8_2(m, "LoadedModelsCollection");
        c8_2.def("__iter__", [] (DgnFile::LoadedModelsCollection& self) { return py::make_iterator(self.begin(), self.end()); }, py::keep_alive<0, 1>());


        //=======================================================================================
        // struct SignatureCountType
        py::enum_<DgnFile::SignatureCountType>(c8, "SignatureCountType", py::arithmetic())
            .value("eSIGNATURE_COUNT_File", DgnFile::SIGNATURE_COUNT_File)
            .value("eSIGNATURE_COUNT_Model", DgnFile::SIGNATURE_COUNT_Model)
            .value("eSIGNATURE_COUNT_All", DgnFile::SIGNATURE_COUNT_All)
            .export_values();
        }
    

    c8.def("LoadDgnFile", [] (DgnFileR self)
           {
           StatusInt openForWriteStatus = 0;
           auto retVal = self.LoadDgnFile(&openForWriteStatus);
           return py::make_tuple(retVal, openForWriteStatus);
           });

    c8.def("FillSectionsInModel", [](DgnFileR self, DgnModelP model, DgnModelSections sectionsToFill)
        {
        return self.FillSectionsInModel(model, sectionsToFill);
        }, "model"_a, "sectionsToFill"_a = DgnModelSections::Model);

    c8.def("FillDictionaryModel", &DgnFile::FillDictionaryModel, DOC(Bentley, DgnPlatform, DgnFile, FillDictionaryModel));
    c8.def("AddRef", &DgnFile::AddRef, DOC(Bentley, DgnPlatform, DgnFile, AddRef));
    c8.def("Release", &DgnFile::Release, DOC(Bentley, DgnPlatform, DgnFile, Release));
    
    c8.def_property_readonly("LoadedModelsCollection", &DgnFile::GetLoadedModelsCollection);
    c8.def("GetLoadedModelsCollection", &DgnFile::GetLoadedModelsCollection, DOC(Bentley, DgnPlatform, DgnFile, GetLoadedModelsCollection));

    c8.def("GetModelIndex", [](DgnFileR self)
        {
        return std::unique_ptr<const ModelIndex, py::nodelete>(&self.GetModelIndex());
        }, DOC(Bentley, DgnPlatform, DgnFile, GetModelIndex));

    c8.def_property_readonly("DictionaryModel", &DgnFile::GetDictionaryModel);
    c8.def("GetDictionaryModel", &DgnFile::GetDictionaryModel, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, DgnFile, GetDictionaryModel));

    c8.def("FindModelIdByName", &DgnFile::FindModelIdByName, "name"_a, DOC(Bentley, DgnPlatform, DgnFile, FindModelIdByName));
    
    c8.def_property_readonly("DefaultModelId", &DgnFile::GetDefaultModelId);
    c8.def("GetDefaultModelId", &DgnFile::GetDefaultModelId, DOC(Bentley, DgnPlatform, DgnFile, GetDefaultModelId));
    
    c8.def("FindLoadedModelById", &DgnFile::FindLoadedModelById, "modelId"_a, DOC(Bentley, DgnPlatform, DgnFile, FindLoadedModelById));
    c8.def("LoadModelById", &DgnFile::LoadModelById, "modelId"_a, DOC(Bentley, DgnPlatform, DgnFile, LoadModelById));
    c8.def("HasPendingChanges", &DgnFile::HasPendingChanges, DOC(Bentley, DgnPlatform, DgnFile, HasPendingChanges));
    c8.def("SetFullSaveFlag", &DgnFile::SetFullSaveFlag, DOC(Bentley, DgnPlatform, DgnFile, SetFullSaveFlag));
    c8.def("SetAbandonChangesFlag", &DgnFile::SetAbandonChangesFlag, DOC(Bentley, DgnPlatform, DgnFile, SetAbandonChangesFlag));
    c8.def("ClearAbandonChangesFlag", &DgnFile::ClearAbandonChangesFlag, DOC(Bentley, DgnPlatform, DgnFile, ClearAbandonChangesFlag));
    c8.def("ProcessChanges", &DgnFile::ProcessChanges, "reason"_a, "timestamp"_a = 0, DOC(Bentley, DgnPlatform, DgnFile, ProcessChanges));

    c8.def("DoSaveAs", 
           py::overload_cast<DgnDocumentR, DgnFileFormatType, bool, bool>(&DgnFile::DoSaveAs),
           "newDoc"_a, "format"_a = DgnFileFormatType::V8, "saveChanges"_a = false, "doPreSaveAsHooks"_a = true);

    c8.def("DoSaveTo", py::overload_cast<WCharCP, DgnFileFormatType>(&DgnFile::DoSaveTo), "newFileName"_a, "format"_a = DgnFileFormatType::V8, DOC(Bentley, DgnPlatform, DgnFile, DoSaveTo));
    c8.def("SetTransactable", &DgnFile::SetTransactable, "yesNo"_a, DOC(Bentley, DgnPlatform, DgnFile, SetTransactable));
    c8.def("GetUniqueModelName", &DgnFile::GetUniqueModelName, "uniqueModelName"_a, "baseName"_a, "forCopy"_a = false, DOC(Bentley, DgnPlatform, DgnFile, GetUniqueModelName));
    c8.def_property_readonly("LastSaveTime", &DgnFile::GetLastSaveTime);
    c8.def("GetLastSaveTime", &DgnFile::GetLastSaveTime, DOC(Bentley, DgnPlatform, DgnFile, GetLastSaveTime));
    
    c8.def_property_readonly("Document", &DgnFile::GetDocumentPtr);
    c8.def("GetDocument", &DgnFile::GetDocumentPtr, DOC(Bentley, DgnPlatform, DgnFile, GetDocument));
    
    c8.def_property_readonly("FileName", &DgnFile::GetFileName);
    c8.def("GetFileName", &DgnFile::GetFileName, DOC(Bentley, DgnPlatform, DgnFile, GetFileName));
    
    c8.def_property_readonly("PackagedName", &DgnFile::GetPackagedName);
    c8.def("GetPackagedName", &DgnFile::GetPackagedName, DOC(Bentley, DgnPlatform, DgnFile, GetPackagedName));
    
    c8.def_property_readonly("PackageName", &DgnFile::GetPackageName);
    c8.def("GetPackageName", &DgnFile::GetPackageName, DOC(Bentley, DgnPlatform, DgnFile, GetPackageName));
    
    c8.def_property_readonly("EmbeddedName", &DgnFile::GetEmbeddedName);
    c8.def("GetEmbeddedName", &DgnFile::GetEmbeddedName, DOC(Bentley, DgnPlatform, DgnFile, GetEmbeddedName));
    
    c8.def_property_readonly("EmbeddedFileId", &DgnFile::GetEmbeddedFileId);
    c8.def("GetEmbeddedFileId", &DgnFile::GetEmbeddedFileId, DOC(Bentley, DgnPlatform, DgnFile, GetEmbeddedFileId));
    
    c8.def("IsEmbeddedFile", &DgnFile::IsEmbeddedFile);    

    c8.def("GetVersion", [] (DgnFileR self)
           {
           DgnFileFormatType format = DgnFileFormatType::Invalid;
           int majorV = 0;
           int minorV = 0;
           auto retVal = self.GetVersion(&format, &majorV, &minorV);
           return py::make_tuple(retVal, format, majorV, minorV);
           });

    c8.def("IsTransactable", &DgnFile::IsTransactable, DOC(Bentley, DgnPlatform, DgnFile, IsTransactable));
    c8.def("IsLoaded", &DgnFile::IsLoaded, DOC(Bentley, DgnPlatform, DgnFile, IsLoaded));
    c8.def("IsOpen", &DgnFile::IsOpen, DOC(Bentley, DgnPlatform, DgnFile, IsOpen));
    c8.def("IsReadOnly", &DgnFile::IsReadOnly, DOC(Bentley, DgnPlatform, DgnFile, IsReadOnly));

    c8.def_property_readonly("LevelCache", &DgnFile::GetLevelCacheR);
    c8.def("GetLevelCache", &DgnFile::GetLevelCacheR, py::return_value_policy::reference_internal);

    c8.def("GetSignatureCount", &DgnFile::GetSignatureCount, "ct"_a = DgnFile::SIGNATURE_COUNT_All, DOC(Bentley, DgnPlatform, DgnFile, GetSignatureCount));

    c8.def(py::init(&DgnFile::Create), "document"_a, "openMode"_a);
    c8.def_static("CreateNew", [] (DgnDocumentR document, DgnFileOpenMode openMode, SeedDataCR seedData, DgnFileFormatType format, bool threeD)
                  {
                  DgnFileStatus status;
                  auto retVal = DgnFile::CreateNew(status, document, openMode, seedData, format, threeD);
                  return py::make_tuple(retVal, status);
                  }, "document"_a, "openMode"_a, "seedData"_a, "format"_a, "threeD"_a);

    c8.def("CreateNewModel", [] (DgnFileR self, WCharCP name, DgnModelType type, bool is3D, DgnModelCP seedModel, ModelId modelId)
           {
           DgnModelStatus error = DGNMODEL_STATUS_Success;
           return py::make_tuple(self.CreateNewModel(&error, name, type, is3D, seedModel, modelId), error);
           }, "name"_a, "type"_a, "is3D"_a, "seedModel"_a = nullptr, "modelId"_a = INVALID_MODELID, py::return_value_policy::reference_internal);

    c8.def("DeleteModel", &DgnFile::DeleteModel, "model"_a, DOC(Bentley, DgnPlatform, DgnFile, DeleteModel));

    c8.def("LoadRootModelById", [] (DgnFileR self, ModelId modelID, bool fillCache, bool andRefs, bool processAffected)
           {
           StatusInt error;
           auto retVal = self.LoadRootModelById(&error, modelID, fillCache, andRefs, processAffected);
           return py::make_tuple(retVal, error);
           }, "modelID"_a, "fillCache"_a = false, "andRefs"_a = false, "processAffected"_a = false, py::return_value_policy::reference_internal);

    c8.def_static("CopyModelContents", &DgnFile::CopyModelContents, "destModel"_a, "sourceModel"_a, "dictionaryElements"_a, DOC(Bentley, DgnPlatform, DgnFile, CopyModelContents));
    c8.def("AddAppData", &DgnFile::AddAppData, "key"_a, "appData"_a, py::keep_alive<1, 3>(), DOC(Bentley, DgnPlatform, DgnFile, AddAppData));
    c8.def("DropAppData", &DgnFile::DropAppData, "key"_a, DOC(Bentley, DgnPlatform, DgnFile, DropAppData));
    c8.def("FindAppData", &DgnFile::FindAppData, "key"_a, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, DgnFile, FindAppData));
    
    c8.def_property_readonly("ColorMap", &DgnFile::GetColorMapP);
    c8.def("GetColorMap", &DgnFile::GetColorMapP, py::return_value_policy::reference_internal);

    c8.def_property_readonly("LineStyleMap", &DgnFile::GetLineStyleMapP);
    c8.def("GetLineStyleMap", &DgnFile::GetLineStyleMapP, py::return_value_policy::reference_internal);

    c8.def_static("IsSameFile", &DgnFile::IsSameFile, "fileName1"_a, "fileName2"_a, "compareMask"_a, DOC(Bentley, DgnPlatform, DgnFile, IsSameFile));
    
    c8.def_property_readonly("ViewGroups", &DgnFile::GetViewGroups);
    c8.def("GetViewGroups", &DgnFile::GetViewGroups, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, DgnFile, GetViewGroups));
    
    c8.def_property_readonly("NamedViews", &DgnFile::GetNamedViews);
    c8.def("GetNamedViews", &DgnFile::GetNamedViews, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, DgnFile, GetNamedViews));
    
    c8.def("SetModelBackgroundColor", &DgnFile::SetModelBackgroundColor, "color"_a, "type"_a, DOC(Bentley, DgnPlatform, DgnFile, SetModelBackgroundColor));
    c8.def("GetModelBackgroundColor", &DgnFile::GetModelBackgroundColor, "color"_a, "type"_a, DOC(Bentley, DgnPlatform, DgnFile, GetModelBackgroundColor));
    
    c8.def_property_readonly("LastActiveModelId", &DgnFile::GetLastActiveModelId);
    c8.def("GetLastActiveModelId", &DgnFile::GetLastActiveModelId, DOC(Bentley, DgnPlatform, DgnFile, GetLastActiveModelId));
    
    }