/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyMstnPlatform\source\documentmanager.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <Mstn/DocumentManager.h>



static const char * __doc_Bentley_MstnPlatform_MSDocumentManager_GetManager =R"doc(Obtain a reference to MicroStation's document manager. To call methods
on the document manager, use MSDocumentManager::GetManager().Method

:returns:
    The document manager *

)doc";

static const char * __doc_Bentley_MstnPlatform_MSDocumentManager_GetDocumentWorkspace =R"doc(Retrieves the workspace information for a document.

:returns:
    SUCCESS if workspace info is successfully retrieved.

:param workspaceAssigned:
    Pointer to bool. It will be set to true if workspace is assigned.

:param workspaceInfo:
    Pointer to MSWorkspaceInfo. If non-null, it will contain
    information to workspace for the given document.

:param documentMoniker:
    Moniker to document for workspace to be returned.

:param generatorArgs:
    Arguments for worker process *

)doc";

static const char * __doc_Bentley_MstnPlatform_MSDocumentManager_CompareDocumentWorkspaces =R"doc(Compares workspace of two documents




:param document1:
    Moniker to first document of which workspace is to be compared
    with that of second document.

:param document2:
    Moniker to second document of which workspace is to be compared
    with that of first document.

:param generatorArgs:
    Arguments for worker process *

Returns (Tuple, 0):
    SUCCESS if comparison is done successfully.


Returns (Tuple, 1):
	profilesEqual. Reference to a bool. Its value will be true if workspaces are
    equal.

)doc";

static const char * __doc_Bentley_MstnPlatform_MSDocumentManager_OpenFolderDialog =R"doc(:param attributes:
    MicroStation file list attribues (FILELISTATTR flagword) *

Returns (Tuple, 0):
	retVal.

Returns (Tuple, 1):
	status.

)doc";

static const char * __doc_Bentley_MstnPlatform_MSDocumentManager_OpenDocumentListEditDialog =R"doc(*

)doc";

static const char * __doc_Bentley_MstnPlatform_MSDocumentManager_PutDocumentList =R"doc(commit the local copies of this DgnDocumentList to the DMS *

)doc";

static const char * __doc_Bentley_MstnPlatform_MSDocumentManager_CreateMonikerList =R"doc()doc";

static const char * __doc_Bentley_MstnPlatform_MSDocumentManager_CreateNewDocumentDialog =R"doc(Create a new document, using a dialog to browse for the file name and
location. Optionally, test for the existence of the file, and
optionally prompt the user for whether to overwrite the file or not.



:param params:
    A structure containing file open parameters. The entire structure
    should be memset to 0 and then individual fields set as necessary.

:param overwriteMode:
    Sepcifies what to do if the document already exists *

Returns(Tuple, 0):
    An DgnDocument that represents the file. On failure, NULL is
    Returned.

Returns (Tuple, 1):
	status.  this gives an indication of why.

)doc";

static const char * __doc_Bentley_MstnPlatform_MSDocumentManager_OpenDocumentDialog =R"doc(Browse for a document. This will browse the current repository, if one
is active, and the file system if the current session of MicroStation
is not integrated with a document management system.


:param params:
    A structure containing file open parameters. The entire structure
    should be memset to 0 and then individual fields set as necessary.

:param attributes:
    MicroStation file open dialog attribues (FILEOPENEXTATTR flagword)

:param openMode:
    With what access the DgnDocument should be fetched from the DMS,
    if integrated, or what file access is required of the local file,
    if not integrated.. *

Returns (Tuple, 0):
    An DgnDocument that represents the file. If the file cannot be
    found or cannot be accessed, NULL is returned.

Returns (Tuple, 1):
	status. this gives an indication of why.
)doc";

static const char* __doc_Bentley_DgnPlatform_DgnDocumentManager_OpenFolderBrowser = R"doc(Browse for a folder in the DMS)doc";

static const char* __doc_Bentley_DgnPlatform_DgnDocumentManager_OpenDocumentDialog = R"doc(@name GUI Methods to browse the document repository Browse for a
document in the DMS)doc";

static const char* __doc_Bentley_DgnPlatform_DgnDocumentManager_DeleteFolder = R"doc(Remove the folder from the DMS.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnDocumentManager_DeleteDocument =R"doc(@name Methods to manage documents in the DMS repository Remove the
document from the DMS.

Remark:
    s If the DMS is the native file system, this method deletes the
    disk file.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnDocumentManager_PortableNameFromUserEnteredFileName =R"doc(Creates a portable file name given the data that is keyed in by a
user. A portable name never includes explicit disk drive and path
information.

:param portableName:
    A portable file name that can be used in a moniker that is to be
    persisted in a design file.

:param userEnteredPath:
    The file name that the user keyed in. If not NULL, as much as
    possible of it is used to generate portableName.

:param fullPath:
    Identifies the disk file to which the portable moniker should
    point. This is often the full file name as returned from the File
    Open dialog box.

:param basePath:
    The base path that the caller will use relative searches for the
    file represented by the portable moniker. If the portable moniker
    is to be persisted in a DgnFile, basePath is usually the path of
    that DgnFile.

:param relativePref:
    The preference for relative paths. If Allow, accepts relative
    paths that are in userEnteredPath. If CreateIfPossible, attempts
    to create a relative path. If Never, discards relative paths.
    @note If userEnteredPath does not contain an extension, but
    fullPath does contain an extension, the extension in fullPath will
    be the extension in portableName. @note If userEnteredPath starts
    with a configuration variable name followed by a colon, that
    configuration variable and any path information following it is
    retained, and relativePref is ignored. @note If fullPath and
    basePath are not on the same physical drive, it is not possible to
    create a relative path between them.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnDocumentManager_PortableNameFromFullPath =R"doc(Creates a portable file name given the data that is returned from the
File Open dialog. A portable name never includes explicit disk drive
and path information.

:param portableName:
    A portable file name that can be used in a moniker that is to be
    persisted in a design file.

:param fullPath:
    The full file path to the file for which the portableName is
    generated.

:param basePath:
    The full file path to the file in which the portableName will be
    persisted.

:param dirCfgVar:
    If not NULL, this is a configuration variable whose value is the
    directory in fullPath.

:param relative:
    The preference for relative paths. If Allow or CreateIfPossible,
    and dirCfgVar is NULL, attempts to make the portableName a
    relative path from basePath to fullPath. @note If dirCfgVar is not
    NULL, the portable name will consist of the dirCfgVar and the
    filename and extension from fullPath. @note If fullPath and
    basePath are not on the same physical drive, it is not possible to
    create a relative path between them.)doc";

static const char* __doc_Bentley_DgnPlatform_DgnDocumentManager_GetManager = R"doc(Retrieves the DgnDocumentManager object)doc";

typedef RefCountedPtr <struct PyDocumentOpenDialogParams> PyDocumentOpenDialogParamsPtr;
struct PyDocumentOpenDialogParams : public RefCountedBase
{
private:
    /** @Description    Resource file from which to load a user-specified Dialog Box.
                        Specify NULLRSC to use the default resource file. */
    RscFileHandle   dialogRscH;

    /** @Description    ID of a Dialog Box in the resource file specified by dialogRscH. The first six
                        items in the Dialog Box should match the corresponding items in the standard
                        file open/create Dialog Box. Specify 0 to use the default Dialog Box. */
    RscId           dialogId;

    /** @Description    Controls the attributes of the Dialog Box.  Specify by bitwise or'ing the
                        FILELISTATTR_ constants defined in filelist.h.  Commonly used attribute
                        sets can be used by directly specifying:
                        <br>
                        <table border=0 cellspacing=0 cellpadding=1>
                        <tr><td> FILELISTATTR_OPEN          </td></tr>
                        <tr><td> FILELISTATTR_CREATE        </td></tr>
                        <tr><td> FILELISTATTR_CREATEFROMSEED</td></tr>
                        <tr><td> FILELISTATTR_OPENCREATE    </td></tr>
                        <tr><td> FILELISTATTR_DEFAULT       </td></tr>
                        </table> */
    int             openCreate;

    /** @Description    File name that will be suggested to the user when the Dialog Box is first opened.
                        This value is overridden if the defFileId parameter is provided and resource
                        information for this parameter exists in the file specified by defFileRscH. */
    WString         suggestedFileNameP;

    /** @Description    The filter to use for determining which files to include in the file list. It is
                        useful for limiting files displayed to a particular type. Simple wildcarding is
                        allowed. An asterisk `*' matches any string and a question mark `?' matches any
                        single character. Specify NULL to match all files (*.*). */
    WString         defaultFilterP;

    /** @Description    String which describes defaultFilterP, specify NULL for the default description.
                        For multiple filters, use a comma-seperated string.  For example, to get both
                        DGN and RSC files, you might use:
                        "*.dgn,MicroStation Design Files [*.dgn],*.rsc,MicroStation Resource Files [*.rsc]" */
    WString         filterInfoStrP;


    /** @Description    The directory where the selection process starts. It can also be an environment
                        variable, in which case the directory associated with the variable is used. Will
                        be overriden if suggestedFileNameP contains path information. Specify NULL to
                        use the current working directory. */
    WString         defaultDirP;

    /** @Description    The name of a MicroStation configuration variable which is used to populate the
                        contents of the "Directory" menu in the Dialog Box. */
    WString         dirCfgVarP;    

    /** @Description    The title of the Dialog Box. */
    WString         titleP;

    /** @Description    Identifies a resource in the user preference file specified by defFileRscH. This
                        resource is used in two ways.  First, it will be loaded just prior to the display
                        of the Dialog Box to obtain the suggestedFileName and fileFilter used during the
                        last execution of this Dialog Box (using the same defFileId). Second, if the user
                        successfully chooses a file in the Dialog Box (indicated by clicking OK), the new
                        filename and filter are saved back to the resource in the user preference file.
                        For the complete list of defFileId values used by MicroStation dialogs, see
                        deffiles.h */
    RscId           defFileId;

    /** @Description    User preference resource file opened by the calling application.  This is
                        where the default file information, as specified by defFileId, is loaded from
                        and saved after the user makes a new file selection.  Specify NULLRSC to use the
                        MicroStation User Preferences file. */
    RscFileHandle   defFileRscH;

    /** @Description    Unused, pass NULL */
    MdlDesc*        dialogOwnerMD;

    /** @Description    defSeedFileNameP, defSeedDirP, defSeedFilterP and defSeedFileId are identical
                        to suggestedFileNameP, defaultDirP, defaultFilterP and defFileId except that
                        these are used for the seed file Dialog Box. The seed file Dialog Box can
                        be invoked from the create Dialog Box and allows the user to specify which
                        seed file to use in the creation of the design file.  These fields are only
                        used if FILELISTATTR_CREATEFROMSEED is specified by openCreate. */
    WString          defSeedFileNameP;

    /** @Description    see defSeedFileNameP */
    WString         defSeedDirP;

    /** @Description    see defSeedFileNameP */
    WString         defSeedFilterP;

    /** @Description    see defSeedFileNameP */
    RscId           defSeedFileId;

    /** @Description    Specifies the rights that the user must have to allow the application to
                        process the file.  This allows the dialog to check if the user has sufficient
                        rights before returning control back to the application.  Valid values are:
                        <br>
                        <table border=0 cellspacing=0 cellpadding=1>
                        <tr><td> DgnPlatform::DGNFILE_RIGHT_Any          </td></tr>
                        <tr><td> DgnPlatform::DGNFILE_RIGHT_Print        </td></tr>
                        <tr><td> DgnPlatform::DGNFILE_RIGHT_Export       </td></tr>
                        <tr><td> DgnPlatform::DGNFILE_RIGHT_Edit         </td></tr>
                        <tr><td> DgnPlatform::DGNFILE_RIGHT_Unlimited    </td></tr>
                        </table> */
    UInt32          requiredRights;

    /** @Description    mdlDialog_fileOpenExt will set this to a load context that can be used for future
                        access to the file via @ref mdlWorkDgn_openFileWithRights.  Passing a loadContext
                        to that function will avoid prompting the user for the same password multiple
                        times.  */
    DgnFileSupplyRightsP reloadContext;
                            
    /** @Description    Id of String list containing file filters and descriptions. */
    RscId               filterStringListId;
    RscFileHandle       filterStringHandle;

    /** @Description    unused; should be set to zero */
    struct
        {
        UInt32          preIncludeCADFileOpenFilters:1;
        UInt32          postIncludeCADFileOpenFilters:1;
        UInt32          unused:30;
        } filterFlags;
    int             winOpenReturnCode;      // if winopen is used, the return code from it.
    int             futureUse;

    /** @Description    WorkSet for which file and Directory history should be shown*/
    WString         workSetNameP;

    /** @Description    WorkSpace for which file and Directory history should be shown*/
    WString         workSpaceNameP;


public:

    void SetRscFileHandle (RscFileHandle h)         {dialogRscH = h;}
    void SetDialogId (RscId dialogid)               {dialogId = dialogid;}
    void SetOpenCreate (int openC)                  {openCreate = openC;}
    void SetSuggestedFileName (WStringR name)       {suggestedFileNameP =  name;}
    void SetDefaultFilter (WStringR filter)         {defaultFilterP = filter;}
    void SetFilterInfoString (WStringR info)        {filterInfoStrP = info;}
    void SetDefaultDir (WStringR dir)               {defaultDirP = dir;}
    void SetDirCfgVar (WStringR var)                {dirCfgVarP = var;}
    void SetDialogTitle (WStringR title)            {titleP = title;}
    void SetDefFileId (int id)                      {defFileId = id;}
    void SetDefRscFileHandle (RscFileHandle h)      {defFileRscH = h;}
    void SetDialogOwnerMD (MdlDesc* owner)          {dialogOwnerMD = owner;}
    void SetDefSeedFileName (WStringR name)         {defSeedFileNameP = name;}
    void SetDefSeedDir (WStringR dir)               {defSeedDirP = dir;}
    void SetDefSeedFilter (WStringR filter)         {defSeedFilterP = filter;}
    void SetDefSeedFileId (int fileId)              {defSeedFileId = fileId;}
    void SetRequiredRights (UInt32  rights)         {requiredRights = rights;}
    void SetFilterStringListId (int id)             {filterStringListId = id;}
    void SetFilterRscFileHandle (RscFileHandle h)   {filterStringHandle =h;}
    void SetPreIncludeCADFileOpenFilters (bool on)  {filterFlags.preIncludeCADFileOpenFilters = on;}
    void SetPostIncludeCADFileOpenFilters (bool on) {filterFlags.postIncludeCADFileOpenFilters = on;}
    void SetWorkSetName (WStringR workSetName)      {workSetNameP = workSetName;}
    void SetWorkSpaceName (WStringR workSpaceName)  {workSpaceNameP = workSpaceName; }


    RscFileHandle  GetRscFileHandle()           {return dialogRscH;}
    RscId          GetDialogId()                {return dialogId;}
    int            GetOpenCreate()              {return openCreate;}
    WStringR       GetSuggestedFileName()       {return suggestedFileNameP;}
    WStringR       GetDefaultFilter()           {return defaultFilterP;}
    WStringR       GetFilterInfoString()        {return filterInfoStrP;}
    WStringR       GetDefaultDir()              {return defaultDirP;}
    WStringR       GetDirCfgVar()               {return dirCfgVarP;}
    WStringR       GetDialogTitle()             {return titleP;}
    RscId          GetDefFileId()               {return defFileId;}
    RscFileHandle  GetDefRscFileHandle()        {return defFileRscH;}
    MdlDesc*       GetDialogOwnerMD()           {return dialogOwnerMD;}
    WStringR       GetDefSeedFileName()         {return defSeedFileNameP;}
    WStringR       GetDefSeedDir()              {return defSeedDirP;}
    WStringR       GetDefSeedFilter()           {return defSeedFilterP;}
    int            GetDefSeedFileId()           {return defSeedFileId;}
    UInt32         GetRequiredRights()          {return requiredRights;}
    RscId          GetFilterStringListId()      {return filterStringListId;}
    RscFileHandle  GetFilterRscFileHandle()     {return filterStringHandle;}
    bool           GetPreIncludeCADFileOpenFilters()   {return (0 != filterFlags.preIncludeCADFileOpenFilters);}
    bool           GetPostIncludeCADFileOpenFilters()  {return (0 != filterFlags.postIncludeCADFileOpenFilters);}
    WStringR       GetWorkSetName ()           {return workSetNameP;}
    WStringR       GetWorkSpaceName ()           {return workSpaceNameP; }

    void toMSDocumentOpenDialogParams(MSDocumentOpenDialogParams& params)
        {
        params.SetRscFileHandle                 (GetRscFileHandle());
        params.SetDialogId(GetDialogId());
        params.SetOpenCreate(GetOpenCreate());
        params.SetSuggestedFileName(GetSuggestedFileName().c_str ());
        params.SetDefaultFilter(GetDefaultFilter().c_str ());
        params.SetFilterInfoString(GetFilterInfoString().c_str ());
        params.SetDefaultDir(GetDefaultDir().c_str ());
        params.SetDirCfgVar(GetDirCfgVar().c_str ());
        params.SetDialogTitle(GetDialogTitle().c_str ());
        params.SetDefFileId(GetDefFileId());
        params.SetDefRscFileHandle(GetDefRscFileHandle());
        params.SetDialogOwnerMD(GetDialogOwnerMD());
        params.SetDefSeedFileName(const_cast <WCharP> (GetDefSeedFileName().c_str ()));
        params.SetDefSeedDir(const_cast <WCharP> (GetDefSeedDir().c_str ()));
        params.SetDefSeedFilter(const_cast <WCharP> (GetDefSeedFilter().c_str ()));
        params.SetDefSeedFileId(GetDefSeedFileId());
        params.SetRequiredRights(GetRequiredRights());
        params.SetFilterStringListId(GetFilterStringListId());
        params.SetFilterRscFileHandle(GetFilterRscFileHandle());
        params.SetPreIncludeCADFileOpenFilters(GetPreIncludeCADFileOpenFilters());
        params.SetPostIncludeCADFileOpenFilters(GetPostIncludeCADFileOpenFilters());
        params.SetWorkSetName(GetWorkSetName().c_str ());
        params.SetWorkSpaceName(GetWorkSpaceName().c_str ());

        }
    PyDocumentOpenDialogParams()
        {
        dialogRscH = 0;
        dialogId = 0;
        openCreate  = 0;
        defFileId = 0;
        defFileRscH = 0;
        dialogOwnerMD = nullptr;
        defSeedFileId = 0;
        requiredRights = 0;
        filterStringListId = 0;
        filterStringHandle = 0;
        memset (&filterFlags, 0, sizeof (filterFlags));
        }

    static PyDocumentOpenDialogParamsPtr Create () { return new PyDocumentOpenDialogParams ();}
};

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_DocumentManager(py::module_& m)
    {
    enum FileListAttr 
        { 
        Open = FILELISTATTR_OPEN, 
        Create = FILELISTATTR_CREATE, 
        CreateFromSeed = FILELISTATTR_CREATEFROMSEED, 
        OpenCreate = FILELISTATTR_OPENCREATE, 
        _default = FILELISTATTR_DEFAULT};

    py::enum_<FileListAttr> (m, "FileListAttr")
        .value("eOPEN", FileListAttr::Open)
        .value("eCREATE", FileListAttr::Create)
        .value("eCREATEFROMSEED", FileListAttr::CreateFromSeed)
        .value("eOPENCREATE", FileListAttr::OpenCreate)
        .value("eDEFAULT", FileListAttr::_default)
        .export_values();

    //===================================================================================
    // struct PyDocumentOpenDialogParams
    py::class_< PyDocumentOpenDialogParams, RefCountedPtr< PyDocumentOpenDialogParams>> c3(m, "PyDocumentOpenDialogParams");

    c3.def_static("Create", &PyDocumentOpenDialogParams::Create);
    
    c3.def_property("RscFileHandle", &PyDocumentOpenDialogParams::GetRscFileHandle, &PyDocumentOpenDialogParams::SetRscFileHandle);
    c3.def("GetRscFileHandle", &PyDocumentOpenDialogParams::GetRscFileHandle);
    c3.def("SetRscFileHandle", &PyDocumentOpenDialogParams::SetRscFileHandle, "h"_a);
    
    c3.def_property("DialogId", &PyDocumentOpenDialogParams::GetDialogId, &PyDocumentOpenDialogParams::SetDialogId);
    c3.def("GetDialogId", &PyDocumentOpenDialogParams::GetDialogId);
    c3.def("SetDialogId", &PyDocumentOpenDialogParams::SetDialogId, "dlgId"_a);
    
    c3.def_property("OpenCreate", &PyDocumentOpenDialogParams::GetOpenCreate, &PyDocumentOpenDialogParams::SetOpenCreate);
    c3.def("GetOpenCreate", &PyDocumentOpenDialogParams::GetOpenCreate);
    c3.def("SetOpenCreate", &PyDocumentOpenDialogParams::SetOpenCreate, "openCreate"_a);
    
    c3.def_property("SuggestedFileName", &PyDocumentOpenDialogParams::GetSuggestedFileName, &PyDocumentOpenDialogParams::SetSuggestedFileName);
    c3.def("GetSuggestedFileName", &PyDocumentOpenDialogParams::GetSuggestedFileName, py::return_value_policy::reference_internal);
    c3.def("SetSuggestedFileName", &PyDocumentOpenDialogParams::SetSuggestedFileName, "fileName"_a);
    
    c3.def_property("DefaultFilter", &PyDocumentOpenDialogParams::GetDefaultFilter, &PyDocumentOpenDialogParams::SetDefaultFilter);
    c3.def("GetDefaultFilter", &PyDocumentOpenDialogParams::GetDefaultFilter, py::return_value_policy::reference_internal);
    c3.def("SetDefaultFilter", &PyDocumentOpenDialogParams::SetDefaultFilter, "filter"_a);
    
    c3.def_property("FilterInfoString", &PyDocumentOpenDialogParams::GetFilterInfoString, &PyDocumentOpenDialogParams::SetFilterInfoString);
    c3.def("GetFilterInfoString", &PyDocumentOpenDialogParams::GetFilterInfoString, py::return_value_policy::reference_internal);
    c3.def("SetFilterInfoString", &PyDocumentOpenDialogParams::SetFilterInfoString, "infoString"_a);
    
    c3.def_property("DefaultDir", &PyDocumentOpenDialogParams::GetDefaultDir, &PyDocumentOpenDialogParams::SetDefaultDir);
    c3.def("GetDefaultDir", &PyDocumentOpenDialogParams::GetDefaultDir, py::return_value_policy::reference_internal);
    c3.def("SetDefaultDir", &PyDocumentOpenDialogParams::SetDefaultDir, "defDir"_a);
    
    c3.def_property("DirCfgVar", &PyDocumentOpenDialogParams::GetDirCfgVar, &PyDocumentOpenDialogParams::SetDirCfgVar);
    c3.def("GetDirCfgVar", &PyDocumentOpenDialogParams::GetDirCfgVar, py::return_value_policy::reference_internal);
    c3.def("SetDirCfgVar", &PyDocumentOpenDialogParams::SetDirCfgVar, "cfgVar"_a);
    
    c3.def_property("DialogTitle", &PyDocumentOpenDialogParams::GetDialogTitle, &PyDocumentOpenDialogParams::SetDialogTitle);
    c3.def("GetDialogTitle", &PyDocumentOpenDialogParams::GetDialogTitle, py::return_value_policy::reference_internal);
    c3.def("SetDialogTitle", &PyDocumentOpenDialogParams::SetDialogTitle, "title"_a);
    
    c3.def_property("DefFileId", &PyDocumentOpenDialogParams::GetDefFileId, &PyDocumentOpenDialogParams::SetDefFileId);
    c3.def("GetDefFileId", &PyDocumentOpenDialogParams::GetDefFileId);
    c3.def("SetDefFileId", &PyDocumentOpenDialogParams::SetDefFileId, "fileId"_a);
    
    c3.def_property("DefRscFileHandle", &PyDocumentOpenDialogParams::GetDefRscFileHandle, &PyDocumentOpenDialogParams::SetDefRscFileHandle);
    c3.def("GetDefRscFileHandle", &PyDocumentOpenDialogParams::GetDefRscFileHandle);
    c3.def("SetDefRscFileHandle", &PyDocumentOpenDialogParams::SetDefRscFileHandle, "fileHandle"_a);
    
    c3.def_property("DefSeedFileName", &PyDocumentOpenDialogParams::GetDefSeedFileName, &PyDocumentOpenDialogParams::SetDefSeedFileName);
    c3.def("GetDefSeedFileName", &PyDocumentOpenDialogParams::GetDefSeedFileName, py::return_value_policy::reference_internal);
    c3.def("SetDefSeedFileName", &PyDocumentOpenDialogParams::SetDefSeedFileName, "fileName"_a);
    
    c3.def_property("DefSeedDir", &PyDocumentOpenDialogParams::GetDefSeedDir, &PyDocumentOpenDialogParams::SetDefSeedDir);
    c3.def("GetDefSeedDir", &PyDocumentOpenDialogParams::GetDefSeedDir, py::return_value_policy::reference_internal);
    c3.def("SetDefSeedDir", &PyDocumentOpenDialogParams::SetDefSeedDir, "seedDir"_a);
    
    c3.def_property("DefSeedFilter", &PyDocumentOpenDialogParams::GetDefSeedFilter, &PyDocumentOpenDialogParams::SetDefSeedFilter);
    c3.def("GetDefSeedFilter", &PyDocumentOpenDialogParams::GetDefSeedFilter, py::return_value_policy::reference_internal);
    c3.def("SetDefSeedFilter", &PyDocumentOpenDialogParams::SetDefSeedFilter, "seedFilter"_a);
    
    c3.def_property("DefSeedFileId", &PyDocumentOpenDialogParams::GetDefSeedFileId, &PyDocumentOpenDialogParams::SetDefSeedFileId);
    c3.def("GetDefSeedFileId", &PyDocumentOpenDialogParams::GetDefSeedFileId);
    c3.def("SetDefSeedFileId", &PyDocumentOpenDialogParams::SetDefSeedFileId, "fileId"_a);
    
    c3.def_property("RequiredRights", &PyDocumentOpenDialogParams::GetRequiredRights, &PyDocumentOpenDialogParams::SetRequiredRights);
    c3.def("GetRequiredRights", &PyDocumentOpenDialogParams::GetRequiredRights);
    c3.def("SetRequiredRights", &PyDocumentOpenDialogParams::SetRequiredRights, "rights"_a);
    
    c3.def_property("FilterStringListId", &PyDocumentOpenDialogParams::GetFilterStringListId, &PyDocumentOpenDialogParams::SetFilterStringListId);
    c3.def("GetFilterStringListId", &PyDocumentOpenDialogParams::GetFilterStringListId);
    c3.def("SetFilterStringListId", &PyDocumentOpenDialogParams::SetFilterStringListId, "listId"_a);
    
    c3.def_property("FilterRscFileHandle", &PyDocumentOpenDialogParams::GetFilterRscFileHandle, &PyDocumentOpenDialogParams::SetFilterRscFileHandle);
    c3.def("GetFilterRscFileHandle", &PyDocumentOpenDialogParams::GetFilterRscFileHandle);
    c3.def("SetFilterRscFileHandle", &PyDocumentOpenDialogParams::SetFilterRscFileHandle, "fileHandle"_a);
    
    c3.def_property("PreIncludeCADFileOpenFilters", &PyDocumentOpenDialogParams::GetPreIncludeCADFileOpenFilters, &PyDocumentOpenDialogParams::SetPreIncludeCADFileOpenFilters);
    c3.def("GetPreIncludeCADFileOpenFilters", &PyDocumentOpenDialogParams::GetPreIncludeCADFileOpenFilters);
    c3.def("SetPreIncludeCADFileOpenFilters", &PyDocumentOpenDialogParams::SetPreIncludeCADFileOpenFilters, "isOn"_a);
    
    c3.def_property("PostIncludeCADFileOpenFilters", &PyDocumentOpenDialogParams::GetPostIncludeCADFileOpenFilters, &PyDocumentOpenDialogParams::SetPostIncludeCADFileOpenFilters);
    c3.def("GetPostIncludeCADFileOpenFilters", &PyDocumentOpenDialogParams::GetPostIncludeCADFileOpenFilters);
    c3.def("SetPostIncludeCADFileOpenFilters", &PyDocumentOpenDialogParams::SetPostIncludeCADFileOpenFilters, "isOn"_a);
    
    c3.def_property("WorkSetName", &PyDocumentOpenDialogParams::GetWorkSetName, &PyDocumentOpenDialogParams::SetWorkSetName);
    c3.def("GetWorkSetName", &PyDocumentOpenDialogParams::GetWorkSetName, py::return_value_policy::reference_internal);
    c3.def("SetWorkSetName", &PyDocumentOpenDialogParams::SetWorkSetName, "name"_a);
    
    c3.def_property("WorkSpaceName", &PyDocumentOpenDialogParams::GetWorkSpaceName, &PyDocumentOpenDialogParams::SetWorkSpaceName);   
    c3.def("GetWorkSpaceName", &PyDocumentOpenDialogParams::GetWorkSpaceName, py::return_value_policy::reference_internal);
    c3.def("SetWorkSpaceName", &PyDocumentOpenDialogParams::SetWorkSpaceName, "name"_a);
        
    enum FileOpenExtAttr { None = 0, CenterOnScreen = FILEOPENEXTATTR_CENTERONSCREEN, DontDefaultToDefFile = FILEOPENEXTATTR_DONTDEFAULTTODEFFILE};

    py::enum_<FileOpenExtAttr>(m, "FileOpenExtAttr")
        .value("eNONE", FileOpenExtAttr::None)
        .value("eCENTERONSCREEN", FileOpenExtAttr::CenterOnScreen)
        .value("eDONTDEFAULTTODEFFILE", FileOpenExtAttr::DontDefaultToDefFile)
        .export_values();

    //===================================================================================
    // struct DgnDocumentManager
    py::class_< DgnDocumentManager, std::unique_ptr< DgnDocumentManager, py::nodelete> > c10(m, "DgnDocumentManager");

    if (true)
        {
        //===================================================================================
        // enum class DeleteOptions
        py::enum_< DgnDocumentManager::DeleteOptions>(c10, "DeleteOptions")
            .value("eDefault", DgnDocumentManager::DeleteOptions::Default)
            .value("eAllowRestore", DgnDocumentManager::DeleteOptions::AllowRestore)
            .value("eIncludeSubItems", DgnDocumentManager::DeleteOptions::IncludeSubItems)
            .export_values();

        //===================================================================================
        // enum class Permissions
        py::enum_< DgnDocumentManager::DgnBrowserStatus>(c10, "DgnBrowserStatus")
            .value("eSuccess", DgnDocumentManager::DgnBrowserStatus::Success)
            .value("eCancel", DgnDocumentManager::DgnBrowserStatus::Cancel)
            .value("eNoIntegrationLoaded", DgnDocumentManager::DgnBrowserStatus::NoIntegrationLoaded)
            .export_values();
        }    

//    c10.def_property_readonly_static("Manager", [] (py::object const&) { return std::unique_ptr<DgnDocumentManager, py::nodelete>(&DgnDocumentManager::GetManager()); });
    c10.def_static("GetManager", &DgnDocumentManager::GetManager, py::return_value_policy::reference, DOC(Bentley, DgnPlatform, DgnDocumentManager, GetManager));

    c10.def_static("PortableNameFromFullPath", 
                   &DgnDocumentManager::PortableNameFromFullPath, 
                   "portableName"_a, "fullPath"_a, "basePath"_a, "dirCfgVar"_a, "relative"_a, DOC(Bentley, DgnPlatform, DgnDocumentManager, PortableNameFromFullPath));

    c10.def_static("PortableNameFromUserEnteredFileName", 
                   &DgnDocumentManager::PortableNameFromUserEnteredFileName, 
                   "portableName"_a, "userEnteredPath"_a, "fullPath"_a, "basePath"_a, "relativePref"_a, DOC(Bentley, DgnPlatform, DgnDocumentManager, PortableNameFromUserEnteredFileName));

    c10.def("DeleteDocument", &DgnDocumentManager::DeleteDocument, "doc"_a, "options"_a = DgnDocumentManager::DeleteOptions::Default, DOC(Bentley, DgnPlatform, DgnDocumentManager, DeleteDocument));
    c10.def("DeleteFolder", &DgnDocumentManager::DeleteFolder, "folderMoniker"_a, "options"_a = DgnDocumentManager::DeleteOptions::Default, DOC(Bentley, DgnPlatform, DgnDocumentManager, DeleteFolder));
    c10.def("OpenDocumentDialog", &DgnDocumentManager::OpenDocumentDialog, "status"_a, "defaults"_a, DOC(Bentley, DgnPlatform, DgnDocumentManager, OpenDocumentDialog));
    c10.def("OpenFolderBrowser", &DgnDocumentManager::OpenFolderBrowser, "status"_a, "defaults"_a, DOC(Bentley, DgnPlatform, DgnDocumentManager, OpenFolderBrowser));

    //===================================================================================
    // struct MSDocumentManager
    py::class_< MSDocumentManager, DgnDocumentManager> c5(m, "MSDocumentManager");

    c5.def("OpenDocumentDialog", [] (MSDocumentManager& self, PyDocumentOpenDialogParamsPtr pyParams, FileOpenExtAttr attributes, DgnDocument::FetchMode openMode)
           {
           MSDocumentOpenDialogParams params;
           pyParams->toMSDocumentOpenDialogParams (params);
           DgnFileStatus status = DgnFileStatus::DGNFILE_STATUS_UnknownError;
           auto retVal = self.OpenDocumentDialog(status, params, attributes, openMode);
           return py::make_tuple(retVal, status);
           }, "params"_a, "attributes"_a, "openMode"_a, DOC(Bentley, MstnPlatform, MSDocumentManager, OpenDocumentDialog));

    c5.def("CreateNewDocumentDialog", [] (MSDocumentManager& self, PyDocumentOpenDialogParamsPtr pyParams, DgnDocument::OverwriteMode overwriteMode)
           {
           MSDocumentOpenDialogParams params;
           pyParams->toMSDocumentOpenDialogParams (params);
           DgnFileStatus status = DgnFileStatus::DGNFILE_STATUS_UnknownError;
           auto retVal = self.CreateNewDocumentDialog(status, params, overwriteMode);
           return py::make_tuple(retVal, status);
           }, "params"_a, "overwriteMode"_a, DOC(Bentley, MstnPlatform, MSDocumentManager, CreateNewDocumentDialog));

    c5.def("CreateMonikerList", &MSDocumentManager::CreateMonikerList, DOC(Bentley, MstnPlatform, MSDocumentManager, CreateMonikerList));
    c5.def("CreateFolderMonikerList", &MSDocumentManager::CreateFolderMonikerList);
    c5.def("CreateDgnBaseMonikerList", &MSDocumentManager::CreateDgnBaseMonikerList);
    c5.def("PutDocumentList", &MSDocumentManager::PutDocumentList, "docs"_a, "putAction"_a, "putOptions"_a, "comment"_a = nullptr, DOC(Bentley, MstnPlatform, MSDocumentManager, PutDocumentList));

    c5.def("OpenFolderDialog", [] (MSDocumentManager& self, PyDocumentOpenDialogParamsPtr pyParams, int attributes, WCharCP basePath, DgnDocument::FetchMode fetchMode)
           {
           StatusInt status = ERROR;
           MSDocumentOpenDialogParams params;
           pyParams->toMSDocumentOpenDialogParams (params);
           auto retVal = self.OpenFolderDialog(status, params, attributes, basePath, fetchMode);
           return py::make_tuple(retVal, status);
           }, "params"_a, "attributes"_a, "basePath"_a, "fetchMode"_a, DOC(Bentley, MstnPlatform, MSDocumentManager, OpenFolderDialog));

    c5.def("CompareDocumentWorkspaces", [] (MSDocumentManager& self, DgnDocumentMonikerCR document1, DgnDocumentMonikerCR document2, WCharCP generatorArgs)
           {
           bool profilesEqual = false;
           auto retVal = self.CompareDocumentWorkspaces(profilesEqual, document1, document2, generatorArgs);
           return py::make_tuple(retVal, profilesEqual);
           }, "document1"_a, "document2"_a, "generatorArgs"_a, DOC(Bentley, MstnPlatform, MSDocumentManager, CompareDocumentWorkspaces));

    c5.def_static("GetManager", &MSDocumentManager::GetManager, py::return_value_policy::reference, DOC(Bentley, MstnPlatform, MSDocumentManager, GetManager));
    }