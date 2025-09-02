/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnPlatform\source\dgndocumentmanager.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <DgnPlatform/DgnDocumentManager.h>

static const char * __doc_Bentley_DgnPlatform_DgnFolder_GetPermissions =R"doc(Get the permissions of this DMS folder (for the current user account).)doc";

static const char * __doc_Bentley_DgnPlatform_DgnFolder_IsInSameRepository =R"doc(Check to see whether the specified DgnFolder resides in the same
repository as this DgnFolder of the file, and optionally prompt the
user for whether to overwrite the file or not.

:returns:
    true if both are in the same repository, false if not

:param compareFolder:
    A pointer to a DgnFolder object used for comparison)doc";

static const char * __doc_Bentley_DgnPlatform_DgnFolder_CreateNew =R"doc(Create a new folder in DMS. Returns DgnFolder object if the folder was
successfully created or accepted existing one.

:param status:
    If NULL is returned, this gives an indication why.

:param folderName:
    The name for the new folder.

:param parentFolderMoniker:
    The moniker of the parent folder under which this new folder
    should be created.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnFolder_CreateFromMoniker =R"doc(Create a new DgnFolder object from a moniker object that refers to an
existing folder. This method would typically be used to either query
the contents of a folder or to create additional contents.

:returns:
    A DgnFolder that represents the existing folder. On failure, NULL
    is returned.

:param status:
    If NULL is returned, this gives an indication of why.

:param moniker:
    The moniker string which specifies the location and name of the
    folder.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnFolder_IsDmsFolder =R"doc(Returns true if the folder is stored in a document management system.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnFolder_GetDocuments =R"doc(Get the files within the folder. NULL is returned in case of an error.
An empty list is returned if there is no files.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnFolder_GetSubFolders =R"doc(Get the subfolders within the folder NULL is returned in case of an
error. An empty list is returned if there is no subfolders.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnFolder_GetContents =R"doc(Get the files and subfolders within the folder NULL is returned in
case of an error. An empty list is returned if there is no files and
subfolders.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnFolder_GetFolderName =R"doc(Get the folder name appropriate for name based APIs. All Folder
objects must have a name, although the folder may or may not exist)doc";

static const char * __doc_Bentley_DgnPlatform_DgnFolder_GetMoniker =R"doc(Get reference to the moniker that identifies this document.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnDocument_SetNameForRecentFileList =R"doc(Set or clear the name for the recent file list for this document)doc";

static const char * __doc_Bentley_DgnPlatform_DgnDocument_GetNameForRecentFileList =R"doc(Query the name for the recent file list, if any, that is assigned to
this document.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnDocument_SetReadOnly =R"doc(Mark the document for read-only access in the DMS.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnDocument_IsReadOnly =R"doc(Is the document marked for read-only access in the DMS?

Remark:
    s If the DMS is the native file system, this queries the flag that
    was set by calling SetIsReadOnly to indicate that that file should
    be opened read-only. You must call DgnFile::IsReadOnly to query if
    the file was actually opened read-only.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnDocument_SetLocalFileModifyTime =R"doc(Set the time of the last modification to the local copy of this
document.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnDocument_GetFileName =R"doc(@name Methods to query and set properties of the local copy of the
document. Get the stored filename for the document, if it has one, or
the portable name if not. @See DgnDocumentMoniker::ResolveFileName)doc";

static const char * __doc_Bentley_DgnPlatform_DgnDocument_GetMyAccess =R"doc(Get the current access for this client. My access is the access I have
as a user right now. For example, if the document is checked out to
me, I have exclusive write access; if the document is (input), I have no
access.

Remark:
    s If the DMS is the native file system, this method will always
    return Access::ExclusiveWrite.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnDocument_GetAvailableAccess =R"doc(Get the highest available access for this client. Available access is
the highest access I can get right now. For example, if the document
is out to someone else, I have read-only access; if it is (input), I have
the access based on the document permissions.

Remark:
    s If the DMS is the native file system, this method will always
    return Access::ExclusiveWrite.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnDocument_GetPermissions =R"doc(@name Methods to query access privileges and permissions granted for
the document in the DMS repository. Get the permissions of this DMS
document (for the current user account).

Remark:
    s If the DMS is the native file system, this method returns the
    read-only or read-write status of the disk file if found.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnDocument_IsInSameRepository =R"doc(Check to see whether the specified DgnDocument resides in the same
repository as this DgnDocument of the file, and optionally prompt the
user for whether to overwrite the file or not.

:returns:
    true if both are in the same repository, false if not

:param compareDocument:
    A pointer to a DgnDocument object used for comparison)doc";

static const char * __doc_Bentley_DgnPlatform_DgnDocument_IsSameFile =R"doc(Query if this document and *other* refer to the same file. Calls
DgnBaseMoniker::Compare.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnDocument_HasServerChanges =R"doc(Has the document been changed in the DMS since it was fetched or most
recently put?

Remark:
    s If the DMS is the native file system, this method will always
    return false.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnDocument_GetCommitTime =R"doc(Get the time of the last commit of this document to the DMS

Remark:
    s If the DMS is the native file system, this method returns the
    last time the file was modified.

Returns (Tuple, 0):
	retVal.

Returns (Tuple, 1):
	commitTime.

)doc";


static const char * __doc_Bentley_DgnPlatform_DgnDocument_HasLocalChanges =R"doc(Has the document been changed locally since it was last put?

Remark:
    s If the DMS is the native file system, this method will always
    return false.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnDocument_OnNewFileCreated =R"doc(Call this method after creation of a new file is finished. This tells
the document manager to complete document creation started with
DgnDocument::CreateForNewFile or DgnDocument::CreateNew. In case of
DMS, the file would be stored to the remote repository. After this
method you should assume the document is in the FetchMode::InfoOnly
access mode. If the created file needs to be accessed locally request
the desired access via DgnDocument::Fetch. Note that the original file
name can possibly be modified (DMS case). To retrieve the current file
name call DgnDocument::GetFileName. Don't call this method for a
temporary local file.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnDocument_Put =R"doc(Use the local copy of the document to update the master copy of the
document in the DMS

Remark:
    s If the DMS is the native file system, this method does nothing
    and returns SUCCESS.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnDocument_Fetch =R"doc(@name Methods to synchronize the local copy of the document with the
DMS repository Create a local copy of the document from the master
copy in the DMS

Remark:
    s If the DMS is the native file system, this method does nothing
    and returns SUCCESS.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnDocument_GetMoniker =R"doc(Get reference to the moniker that identifies this document.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnDocument_CreateForLocalFile =R"doc(Create a DgnDocument object that represents a file in the native file
system, without attempting to link it to a document in the DMS.

Remark:
    s Does not check that the file exists.

Remark:
    s This method does not create a disk file. It creates a
    DgnDocument object in memory that represents an existing disk
    file.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnDocument_CreateForEmbeddedFile =R"doc(Create a DgnDocument object that represents an embedded file.

Remark:
    s Does not check that the embedded storage exists.

Remark:
    s This method does not create an embedded storage or a document in
    the DMS repository. It creates a DgnDocument object in memory that
    represents an embedded storage.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnDocument_CreateNew =R"doc(Create a new document in DMS. Returns DgnDocument object if the
document was created.

:param status:
    If NULL is returned, this gives an indication why.

:param documentName:
    The name for the new document.

:param parentFolderMoniker:
    The moniker of the parent folder under which this new folder
    should be created.

:param defFileId:
    Identifies the type of file being created.

:param overwriteMode:
    Specifies what to do if the document already exists.

:param options:
    Create Options.

Returns (Tuple, 0):
	retVal.

Returns (Tuple, 1):
	status.

)doc";

static const char * __doc_Bentley_DgnPlatform_DgnDocument_CreateForNewFile =R"doc(Create a new DgnDocument object to represent a new file in the native
file system. Optionally, test for the existence of a local file by the
same name, and optionally prompt the user for whether to overwrite the
file or not.  NB:The caller should call
DgnDocument::OnNewFileCreated after creating the new disk file.

:param status:
    If NULL is returned, this gives an indication of why. The possible
    values are:- DGNFETCH_STATUS_FileAlreadyExists - the file already
    exists and overwrite was not specified. -
    DGNFETCH_STATUS_AccessViolation - the file already exists and
    could not be overwritten.

:param documentName:
    The name for the file or document created

:param searchPath:
    The base path used for relative searches or NULL to ignore this
    parameter. A search path may contain one or more configuration
    variables, directory paths, and/or file paths.

:param defFileId:
    Identifies the type of file being created.

:param wDefaultFileName:
    Specifies the default drive, path, filename, and/or extension to
    be used when locating an existing file from a partially specified
    name.

:param overwriteMode:
    Specifies what to do if the document already exists.

:param options:
    Create Options.

Remark:
    s This method does not create a disk file or a document in the DMS
    repository. It creates a DgnDocument object in memory to represent
    a new file.

Remark:
    s After writing out the disk file for the new document, the caller
    must call DgnDocument::OnNewFileCreated.
    
Returns (Tuple, 0):
    a DgnDocument that represents the file. On failure, NULL is
    Returned.

Returns (Tuple, 1):
	status.

    )doc";

static const char * __doc_Bentley_DgnPlatform_DgnDocument_CreateFromFileName =R"doc(Create a DgnDocument object that represents an existing file in the
native file system. This is just a short cut for the following:

``
DgnDocumentMonikerPtr  moniker = CreateMonikerFromFileName (fileName, NULL, envvar);
DgnDocumentP openedDoc = CreateFromMoniker (status, *moniker, defFileId, fetchMode, fetchOptions);
``

:param status:
    If NULL is returned, this gives an indication of why:-
    DGNFETCH_STATUS_FileNotFound:the file could not be found

:param fileName:
    The name of the existing file.

:param searchPath:
    The base path used for relative searches or NULL to ignore this
    parameter. A search path may contain one or more configuration
    variables, directory paths, and/or file paths.

:param defFileId:
    Identifies the type of file being opened.

:param fetchMode:
    Specifies the access that should be requested when fetching the
    DgnDocument from the DMS.

:param fetchOptions:
    Fetch options

Remark:
    s This method does not open a disk file. It creates a DgnDocument
    object in memory that identifies and represents an existing disk
    file that the caller can open if desired.

Returns (Tuple, 0):
    a DgnDocument that represents the file. On failure, NULL is
    Returned.

Returns (Tuple, 1):
	status.
    
    )doc";

static const char * __doc_Bentley_DgnPlatform_DgnDocument_CreateFromMoniker =R"doc(@name Methods to create document objects Create a new DgnDocument
object from a moniker object that refers to an existing file. This
method would typically be used by code that intends to read or write
data from the document. The document manager will optionally fetch the
document from the repository.


:param status:
    If NULL is returned, this gives an indication of why:-
    DGNFETCH_STATUS_FileNotFound:the file could not be found - ERROR:
    the moniker is invalid

:param moniker:
    The moniker string which specifies the location and name of the
    document.

:param defFileId:
    Gives the caller a way to tell the document manager about the
    intended use of this document. See the list of ids in deffiles.h

:param fetchMode:
    Specifies the access that should be requested when fetching the
    DgnDocument from the DMS.

:param fetchOptions:
    Fetch options

Remark:
    s This method does not open a disk file. It creates a DgnDocument
    object in memory that identifies and represents an existing disk
    file that the caller can open if desired.    

Returns (Tuple, 0):
    a DgnDocument that represents the file. On failure, NULL is
    Returned.

Returns (Tuple, 1):
	status.
    
    )doc";

static const char * __doc_Bentley_DgnPlatform_DgnFolderMoniker_TransformTo =R"doc(Transform the moniker to new search path. If the moniker is not
relative, then the same moniker is returned.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnFolderMoniker_ResolveParentFolderMoniker =R"doc(Resolve the parent folder moniker. 

Returns (Tuple, 0):
	retVal.

Returns (Tuple, 1) :
	status.

)doc";

static const char * __doc_Bentley_DgnPlatform_DgnFolderMoniker_ResolveFolderName =R"doc(Get the folder name appropriate for directory based APIs, usually a
fully qualified folder path. Searches the file system. Can fail.

:param status:
    If non-null, a non-zero error status if the search for the file
    failed. Possible values are:- ERROR - the moniker is invalid

:param dontRetryIfFailed:
    This parameter controls what this method will do if it tried and
    failed to find the folder in a previous call. If true, then this
    method will not try again to resolve the directory path. If false,
    then this method will try again to resolve the directory path,
    even if that requires another search.

Remark:
    s If the search path includes network shares, this method may
    spend a significant amount of time doing a search.

Returns  (Tuple, 0):
    The full path of the local directory or the empty string if the
    directory path could not be resolved.

 Returns (Tuple, 1):
	status.
   
    )doc";

static const char * __doc_Bentley_DgnPlatform_DgnFolderMoniker_Clone =R"doc(Create a new DgnDocumentMoniker object that is a copy of the
DgnDocumentMoniker passed in.

:param source:
    The DgnDocumentMoniker to copy.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnFolderMoniker_CreateFromURI =R"doc(Create a folder moniker from the given URI.

:returns:
    Folder moniker. It can be null in case of an error.

:param uri:
    URI for the document.

:param basePath:
    Base path for the moniker)doc";

static const char * __doc_Bentley_DgnPlatform_DgnFolderMoniker_CreateFromFolderName =R"doc(Create a new DgnFolderMoniker object that refers to a folder in the
native file system.

:param folderName:
    Identifies a disk file

:param searchPath:
    The base path used for relative searches or NULL to ignore this
    parameter. A search path may contain one or more configuration
    variables, directory paths, and/or file paths.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnFolderMoniker_Create =R"doc(Create a new DgnFolderMoniker object from externalized state and
additional context information. This method is typically used to find
a document from a previously persisted moniker.

:returns:
    A DgnFolderMoniker object that contains the information stored in
    the given string.

:param externalizedState:
    The externalized state of the moniker. @See
    DgnBaseMoniker::Externalize

:param searchPath:
    The base path used for relative searches or NULL to ignore this
    parameter. A search path may contain one or more configuration
    variables, directory paths, and/or file paths.

:param fullPathFirst:
    Pass true to give preference to the fullpath in the moniker.
    Usually false.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnFolderMoniker_CreateFromRawData =R"doc(Re-create a folder moniker from its stored data)doc";

static const char * __doc_Bentley_DgnPlatform_DgnDocumentMoniker_TransformTo =R"doc(Transform the moniker to new search path. If the moniker is not
relative, then the same moniker is returned.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnDocumentMoniker_ResolveParentFolderMoniker =R"doc(Resolve the parent folder moniker. This method can fail.
Returns (Tuple, 0):
	retVal.

Returns (Tuple, 1) :
	status.

)doc";

static const char * __doc_Bentley_DgnPlatform_DgnDocumentMoniker_GetSavedFileName =R"doc(Get the saved fully qualified file path.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnDocumentMoniker_ResolveFileName =R"doc(@name Methods to query moniker properties Get the file name
appropriate for filename based APIs, usually a fully qualified file
path. Searches the file system. Can fail.

:param status:
    If non-null, a non-zero error status if the search for the file
    failed. Possible values are:- DGNFETCH_STATUS_FileNotFound - the
    file could not be found - ERROR - the moniker is invalid

:param dontRetryIfFailed:
    This parameter controls what this method will do if it tried and
    failed to find the file in a previous call. If true, then this
    method will not try again to resolve the file. If false, then this
    method will try again to resolve the file, even if that requires
    another search.

Remark:
    s If the search path includes network shares, this method may
    spend a significant amount of time doing a search.
Returns (Tuple, 0):
    The full path of the local file or the empty string if the file
    could not be resolved.
 Returns (Tuple, 1):
	status.   
    
    )doc";

static const char * __doc_Bentley_DgnPlatform_DgnDocumentMoniker_Clone =R"doc(Create a new DgnDocumentMoniker object that is a copy of the
DgnDocumentMoniker passed in.

:param source:
    The DgnDocumentMoniker to copy.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnDocumentMoniker_CreateFromURI =R"doc(Create a document moniker from the given URI.

:returns:
    Document moniker. It can be null in case of an error.

:param uri:
    URI for the document.

:param basePath:
    Base path for the moniker)doc";

static const char * __doc_Bentley_DgnPlatform_DgnDocumentMoniker_CreatePackagedFileMonikerFromPackageFileMoniker =R"doc(Create a new DgnDocumentMoniker object that refers to a packaged file
embedded inside a package file that exists in the native file system.

:returns:
    A DgnDocumentMoniker object that contains the information for a
    packaged file

:param packageMoniker:
    A moniker for the Package file in the file system

:param embeddedId:
    Index for the packaged file embedded in the package

:param embedName:
    Name for packaged file embedded in the package)doc";

static const char * __doc_Bentley_DgnPlatform_DgnDocumentMoniker_CreatePackagedFileMonikerFromFileName =R"doc(Create a new DgnDocumentMoniker object that refers to a packaged file
embedded inside a package file that exists in the native file system.

:returns:
    A DgnDocumentMoniker object that contains the information for a
    packaged file

:param packageFilePortableName:
    Identifies the Package file in the file system

:param packageFilefullPath:
    Identifies the Package file in the file system with the full path
    specified

:param embeddedId:
    Index for the packaged file embedded in the package

:param embedName:
    Name for packaged file embedded in the package

:param providerID:
    provider id of the moniker

:param isRelative:
    true if the path is relative

:param searchPath:
    The base path used for relative searches or NULL to ignore this
    parameter. A search path may contain one or more configuration
    variables, directory paths, and/or file paths.

:param findFullPathFirst:
    Pass true to give preference to the fullpath in the moniker.
    Usually false.

:param customXMLString:
    Optional xml string.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnDocumentMoniker_CreatePortableMoniker =R"doc(Create a DgnDocumentMoniker object that refers to a disk file in the
native file system in a " portable " way.

:param userEnteredPath:
    The file name that the user keyed in. If not NULL, as much as
    possible of it is used to generate the portable name in the
    DgnDocumentMoniker.

:param fullPath:
    Identifies the disk file to which the portable moniker should
    point. This is often the full file name as returned from the File
    Open dialog box.

:param basePath:
    The base path that the caller will use relative searches for the
    file represented by the portable moniker. If the portable moniker
    is to be persisted in a DgnFile, basePath is usually the path of
    that DgnFile.

:param directoryConfigVar:
    A configuration variable that points to the directory that holds
    the file. If this is not NULL, then the portable name is stored as
    directoryConfigVar:filename.ext.

:param searchPath:
    The search path used to locate the file referred to by the
    moniker. This is used to locate the file, particularly when
    fullPath is NULL.

:param relativePref:
    If true, and userEnteredPath is NULL, attempts to make the
    portableName a relative path from basePath to fullPath. If false
    and userEnteredPath is not NULL, removes relative path information
    from it. @note This method creates a moniker that is suitable for
    persisting and finding the file refered to by fullFileName,
    assuming that the user of the moniker passes the correct
    searchPath on the subsequent invocations of the program.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnDocumentMoniker_CreateFromFileName =R"doc(Create a new DgnDocumentMoniker object that refers to disk file in the
native file system.

:param fileName:
    Identifies a disk file

:param searchPath:
    The base path used for relative searches or NULL to ignore this
    parameter. A search path may contain one or more configuration
    variables, directory paths, and/or file paths. @note If the
    DgnDocumentMoniker will be persisted in a design file, use the
    CreatePortableMoniker instead. The CreatePortableMoniker saves a
    " portable " file name that is relative to either a base path or to
    a specified configuration variable that points to a directory. It
    is used for DgnAttachments and other files that are located
    relative to the host design file or to project files that a user
    or administrator might want to move to a different location in the
    future.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnDocumentMoniker_Create =R"doc(Create a new DgnDocumentMoniker object from externalized state and
additional context information. This method is typically used to find
a document from a previously persisted moniker.

:returns:
    A DgnDocumentMoniker object that contains the information stored
    in the given string.

:param externalizedState:
    The externalized state of the moniker. @See
    DgnBaseMoniker::Externalize

:param searchPath:
    The base path used for relative searches or NULL to ignore this
    parameter. A search path may contain one or more configuration
    variables, directory paths, and/or file paths.

:param fullPathFirst:
    Pass true to give preference to the fullpath in the moniker.
    Usually false.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnDocumentMoniker_GetEmbeddedName =R"doc(Get the name of a file embedded in a package.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnDocumentMoniker_GetEmbeddedIndex =R"doc(Get the index for a file embedded in a package.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnDocumentMoniker_GetPackageName =R"doc(Get the package name for files embedded within a package.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnDocumentMoniker_IsEmbedded =R"doc(Return true if the document is embedded within a package file.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnDocumentMoniker_CreateFromRawData =R"doc(Re-create a moniker from stored data.

Remark:
    s This it not the recommended way to create a moniker. The
    preferred method of storing and re-creating a moniker is to call
    DgnDocumentMoniker::Externalize to capture the moniker state and
    then DgnDocumentManager::CreateMoniker to re-create the moniker
    from that state. CreateMonikerFromRawData is used by DgnAttachment
    to re-create monikers because a DgnAttachment cannot store the
    output of DgnDocumentMoniker::Externalize. For backward-
    compatibility reasons, a DgnAttachment must store the parts of a
    moniker's state separately. CreateMonikerFromRawData puts those
    parts back together and then calls CreateMoniker.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnDocumentMoniker_GetProviderId =R"doc(Get the URI or other unique ID that was provided by the document
manager when the moniker was created.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnBaseMoniker_IsRemote =R"doc(Gets a value indicating whether a moniker identifies a remote
document/folder.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnBaseMoniker_GetPortableName =R"doc(Get the portable file name which may include an environment variable
or path fragment. Does not search the filesystem.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnBaseMoniker_GetShortDisplayName =R"doc(Get a friendly display name, not fully qualified. Does not search the
filesystem.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnBaseMoniker_ResolveURI =R"doc(Retrieves the provenance string (URI). Can fail.

Returns (Tuple, 0):
    URI of the moniker. It can be empty if the object cannot be
    located.

Returns (Tuple, 1):
	status.
    )doc";

static const char * __doc_Bentley_DgnPlatform_DgnBaseMoniker_ResolveDisplayName =R"doc(Get a displayable name. Will be fully qualified if possible. May
search the filesystem.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnBaseMoniker_ResolveLocationDisplayName =R"doc(Get a friendly display name of the location. May search the
filesystem. Can fail.

Returns (Tuple, 0):
	retVal.

Returns (Tuple, 1):
	status.
    )doc";

static const char * __doc_Bentley_DgnPlatform_DgnBaseMoniker_ResolveLocation =R"doc(Get a string describing the location. May search the filesystem. Can
fail.
Returns (Tuple, 0):
	retVal.

Returns (Tuple, 1):
	status.
)doc";

static const char * __doc_Bentley_DgnPlatform_DgnBaseMoniker_Clone =R"doc(Create a new moniker object that is a copy of the given moniker
object.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnBaseMoniker_Externalize =R"doc(Get a string that can be used to persist a reference to a document.

See also:
    DgnDocumentManager::CreateMoniker)doc";

static const char * __doc_Bentley_DgnPlatform_DgnBaseMoniker_CompareBinary =R"doc(Compare two monikers memberwise.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnBaseMoniker_Compare =R"doc(Lexicographically compare two monikers.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnBaseMoniker_SearchForFile =R"doc(Search for a file in the native file system

:param searchStatus:
    The result of the search

:param inFileName:
    The filename to search for. May be fully qualified or relative.

:param fullPath:
    The last known fully qualified file path of the target file.
    Optional.

:param searchPath:
    A semicolon-delimited list of directory paths to search for a
    relative file name. Optional.

:param fullPathFirst:
    Should the search try *fullPath* first? Otherwise, the search
    looks for *inFileName* in the specified paths first and then falls
    back on *fullPath.*

:param searchAsFolder:
    Search for a folder/directory rather than a file?

Returns (Tuple, 0):
	retVal.

Returns (Tuple, 1):
	searchStatus.    
    
    )doc";

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_DgnDocumentManager(py::module_& m)
    {
    //===================================================================================
    // struct DgnBaseMoniker
    py::class_< DgnBaseMoniker, DgnBaseMonikerPtr> c1(m, "DgnBaseMoniker");
    py::bind_vector<bvector< DgnBaseMonikerPtr>>(m, "DgnBaseMonikerPtrArray", py::module_local(false));

    if (true)
        {
        //===================================================================================
        // enum SearchStatus
        py::enum_<DgnBaseMoniker::SearchStatus>(c1, "SearchStatus")
            .value("eNotAttempted", DgnBaseMoniker::SearchStatus::NotAttempted)
            .value("eFailed", DgnBaseMoniker::SearchStatus::Failed)
            .value("eFoundFull", DgnBaseMoniker::SearchStatus::FoundFull)
            .value("eFoundComplete", DgnBaseMoniker::SearchStatus::FoundComplete)
            .value("eFoundLogical", DgnBaseMoniker::SearchStatus::FoundLogical)
            .value("eFoundRelative", DgnBaseMoniker::SearchStatus::FoundRelative)
            .value("eFoundEnvironment", DgnBaseMoniker::SearchStatus::FoundEnvironment)
            .value("eFoundRelativeFileName", DgnBaseMoniker::SearchStatus::FoundRelativeFileName)
            .value("eFoundEnvironmentFileName", DgnBaseMoniker::SearchStatus::FoundEnvironmentFileName)
            .value("eFoundInPackage", DgnBaseMoniker::SearchStatus::FoundInPackage)
            .export_values();
        }

    c1.def_static("SearchForFile", [] (WCharCP inFileName, WCharCP fullPath, WCharCP searchPath, bool fullPathFirst, bool searchAsFolder)
                  {
                  DgnBaseMoniker::SearchStatus searchStatus = DgnBaseMoniker::SearchStatus::Failed;
                  auto retVal = DgnBaseMoniker::SearchForFile(searchStatus, inFileName, fullPath, searchPath, fullPathFirst, searchAsFolder);
                  return py::make_tuple(retVal, searchStatus);
                  }, "inFileName"_a, "fullPath"_a, "searchPath"_a, "fullPathFirst"_a, "searchAsFolder"_a = false, DOC(Bentley, DgnPlatform, DgnBaseMoniker, SearchForFile));

    c1.def("Compare", &DgnBaseMoniker::Compare, "anotherMoniker"_a, DOC(Bentley, DgnPlatform, DgnBaseMoniker, Compare));
    c1.def("CompareBinary", &DgnBaseMoniker::CompareBinary, "anotherMoniker"_a, DOC(Bentley, DgnPlatform, DgnBaseMoniker, CompareBinary));
    c1.def("Externalize", &DgnBaseMoniker::Externalize, DOC(Bentley, DgnPlatform, DgnBaseMoniker, Externalize));
    c1.def("Clone", &DgnBaseMoniker::Clone, DOC(Bentley, DgnPlatform, DgnBaseMoniker, Clone));

    c1.def("ResolveLocation", [] (DgnBaseMoniker const& self)
           {
           StatusInt status = ERROR;
           auto retVal = self.ResolveLocation(status);
           return py::make_tuple(retVal, status);
           }, DOC(Bentley, DgnPlatform, DgnBaseMoniker, ResolveLocation));
    
    c1.def("ResolveLocationDisplayName", [] (DgnBaseMoniker const& self)
           {
           StatusInt status = ERROR;
           auto retVal = self.ResolveLocationDisplayName(status);
           return py::make_tuple(retVal, status);
           }, DOC(Bentley, DgnPlatform, DgnBaseMoniker, ResolveLocationDisplayName));

    c1.def("ResolveDisplayName", &DgnBaseMoniker::ResolveDisplayName, DOC(Bentley, DgnPlatform, DgnBaseMoniker, ResolveDisplayName));

    c1.def("ResolveURI", [] (DgnBaseMoniker const& self)
           {
           StatusInt status = ERROR;
           auto retVal = self.ResolveURI(&status);
           return py::make_tuple(retVal, status);
           }, DOC(Bentley, DgnPlatform, DgnBaseMoniker, ResolveURI));
    
    c1.def_property_readonly("ShortDisplayName", &DgnBaseMoniker::GetShortDisplayName);
    c1.def("GetShortDisplayName", &DgnBaseMoniker::GetShortDisplayName, DOC(Bentley, DgnPlatform, DgnBaseMoniker, GetShortDisplayName));

    c1.def_property_readonly("PortableName", &DgnBaseMoniker::GetPortableName);
    c1.def("GetPortableName", &DgnBaseMoniker::GetPortableName, DOC(Bentley, DgnPlatform, DgnBaseMoniker, GetPortableName));

    c1.def("IsRemote", &DgnBaseMoniker::IsRemote, DOC(Bentley, DgnPlatform, DgnBaseMoniker, IsRemote));

    //===================================================================================
    // enum class RelativePathPreference
    py::enum_< RelativePathPreference>(m, "RelativePathPreference")
        .value("eNever", RelativePathPreference::Never)
        .value("eAllow", RelativePathPreference::Allow)
        .value("eCreateIfPossible", RelativePathPreference::CreateIfPossible)
        .export_values();

    //===================================================================================
    // struct DgnDocumentMoniker
    py::class_< DgnDocumentMoniker, DgnDocumentMonikerPtr, DgnBaseMoniker> c2(m, "DgnDocumentMoniker");
    py::bind_vector<bvector< DgnDocumentMonikerPtr>>(m, "DgnDocumentMonikerPtrArray", py::module_local(false));

    c2.def(py::init(&DgnDocumentMoniker::CreateEmpty));

    c2.def_property("ParentSearchPath", &DgnDocumentMoniker::GetParentSearchPath, &DgnDocumentMoniker::SetParentSearchPath);
    c2.def("GetParentSearchPath", &DgnDocumentMoniker::GetParentSearchPath);
    c2.def("SetParentSearchPath", &DgnDocumentMoniker::SetParentSearchPath, "newPath"_a);

    c2.def("UpdateSavedFileName", &DgnDocumentMoniker::UpdateSavedFileName, "fulPath"_a);

    c2.def_property_readonly("ProviderId", &DgnDocumentMoniker::GetProviderId);
    c2.def("GetProviderId", &DgnDocumentMoniker::GetProviderId, DOC(Bentley, DgnPlatform, DgnDocumentMoniker, GetProviderId));

    c2.def_static("CreateFromRawData", &DgnDocumentMoniker::CreateFromRawData,
                  "portableName"_a, "fullPath"_a, "providerID"_a, "searchPath"_a, "fullPathFirst"_a, "customXMLStrings"_a, DOC(Bentley, DgnPlatform, DgnDocumentMoniker, CreateFromRawData));

    c2.def("IsEmbedded", &DgnDocumentMoniker::IsEmbedded, DOC(Bentley, DgnPlatform, DgnDocumentMoniker, IsEmbedded));
    
    c2.def_property_readonly("PackageName", &DgnDocumentMoniker::GetPackageName);
    c2.def("GetPackageName", &DgnDocumentMoniker::GetPackageName, DOC(Bentley, DgnPlatform, DgnDocumentMoniker, GetPackageName));
    
    c2.def_property_readonly("EmbeddedIndex", &DgnDocumentMoniker::GetEmbeddedIndex);
    c2.def("GetEmbeddedIndex", &DgnDocumentMoniker::GetEmbeddedIndex, DOC(Bentley, DgnPlatform, DgnDocumentMoniker, GetEmbeddedIndex));
    
    c2.def_property_readonly("EmbeddedName", &DgnDocumentMoniker::GetEmbeddedName);
    c2.def("GetEmbeddedName", &DgnDocumentMoniker::GetEmbeddedName, DOC(Bentley, DgnPlatform, DgnDocumentMoniker, GetEmbeddedName));

    c2.def_static("Create", &DgnDocumentMoniker::Create, "externalizedState"_a, "searchPath"_a = nullptr, "fullPathFirst"_a = false, DOC(Bentley, DgnPlatform, DgnDocumentMoniker, Create));
    c2.def_static("CreateFromFileName", &DgnDocumentMoniker::CreateFromFileName, "fileName"_a, "searchPath"_a = nullptr, DOC(Bentley, DgnPlatform, DgnDocumentMoniker, CreateFromFileName));

    c2.def_static("CreatePortableMoniker", &DgnDocumentMoniker::CreatePortableMoniker,
                  "userEnteredPath"_a, "fullPath"_a, "basePath"_a, "directoryConfigVar"_a, "searchPath"_a, "relativePref"_a, DOC(Bentley, DgnPlatform, DgnDocumentMoniker, CreatePortableMoniker));

    c2.def_static("CreatePackagedFileMonikerFromFileName", &DgnDocumentMoniker::CreatePackagedFileMonikerFromFileName,
                  "packageFilePortableName"_a, "packageFilefullPath"_a, "embeddedId"_a, "embedName"_a, "providerID"_a, "isRelative"_a, "searchPath"_a, "findFullPathFirst"_a, "customXMLString"_a, DOC(Bentley, DgnPlatform, DgnDocumentMoniker, CreatePackagedFileMonikerFromFileName));

    c2.def_static("CreatePackagedFileMonikerFromPackageFileMoniker", &DgnDocumentMoniker::CreatePackagedFileMonikerFromPackageFileMoniker,
                  "packageMoniker"_a, "embeddedId"_a, "embedName"_a, DOC(Bentley, DgnPlatform, DgnDocumentMoniker, CreatePackagedFileMonikerFromPackageFileMoniker));

    c2.def_static("CreateFromURI", &DgnDocumentMoniker::CreateFromURI, "uri"_a, "basePath"_a, DOC(Bentley, DgnPlatform, DgnDocumentMoniker, CreateFromURI));
    c2.def_static("Clone", &DgnDocumentMoniker::Clone, "source"_a, DOC(Bentley, DgnPlatform, DgnDocumentMoniker, Clone));

    c2.def("ResolveFileName", [] (DgnDocumentMoniker const& self, bool dontRetryIfFailed)
           {
           StatusInt status = ERROR;
           auto retVal = self.ResolveFileName(&status, dontRetryIfFailed);
           return py::make_tuple(retVal, status);
           }, "dontRetryIfFailed"_a = true, DOC(Bentley, DgnPlatform, DgnDocumentMoniker, ResolveFileName));
    
    c2.def_property_readonly("SavedFileName", &DgnDocumentMoniker::GetSavedFileName);
    c2.def("GetSavedFileName", &DgnDocumentMoniker::GetSavedFileName, DOC(Bentley, DgnPlatform, DgnDocumentMoniker, GetSavedFileName));

    c2.def("ResolveParentFolderMoniker", [] (DgnDocumentMoniker const& self)
           {
           StatusInt status = ERROR;
           auto retVal = self.ResolveParentFolderMoniker(&status);
           return py::make_tuple(retVal, status);
           }, DOC(Bentley, DgnPlatform, DgnDocumentMoniker, ResolveParentFolderMoniker));

    c2.def("TransformTo", &DgnDocumentMoniker::TransformTo, "base"_a, DOC(Bentley, DgnPlatform, DgnDocumentMoniker, TransformTo));

    //===================================================================================
    // struct DgnFolderMoniker
    py::class_< DgnFolderMoniker, DgnFolderMonikerPtr, DgnBaseMoniker> c3(m, "DgnFolderMoniker");
    py::bind_vector< bvector<DgnFolderMonikerPtr>>(m, "DgnFolderMonikerPtrArray", py::module_local(false));

    c3.def(py::init(&DgnFolderMoniker::CreateEmpty));

    c3.def_static("CreateFromRawData", &DgnFolderMoniker::CreateFromRawData,
                  "portableName"_a, "fullPath"_a, "providerID"_a, "searchPath"_a, "fullPathFirst"_a, "customXMLStrings"_a, DOC(Bentley, DgnPlatform, DgnFolderMoniker, CreateFromRawData));

    c3.def_static("Create", &DgnFolderMoniker::Create, "externalizedState"_a, "searchPath"_a = nullptr, "fullPathFirst"_a = false, DOC(Bentley, DgnPlatform, DgnFolderMoniker, Create));
    c3.def_static("CreateFromFolderName", &DgnFolderMoniker::CreateFromFolderName, "folderName"_a, "searchPath"_a = nullptr, DOC(Bentley, DgnPlatform, DgnFolderMoniker, CreateFromFolderName));
    c3.def_static("CreateFromURI", &DgnFolderMoniker::CreateFromURI, "uri"_a, "basePath"_a, DOC(Bentley, DgnPlatform, DgnFolderMoniker, CreateFromURI));
    c3.def_static("Clone", &DgnFolderMoniker::Clone, DOC(Bentley, DgnPlatform, DgnFolderMoniker, Clone));

    c3.def("ResolveFolderName", [] (DgnFolderMoniker const& self, bool dontRetryIfFailed)
           {
           StatusInt status = ERROR;
           auto retVal = self.ResolveFolderName(&status, dontRetryIfFailed);
           return py::make_tuple(retVal, status);
           }, "dontRetryIfFailed"_a = true, DOC(Bentley, DgnPlatform, DgnFolderMoniker, ResolveFolderName));

    c3.def_property_readonly("SavedFolderName", &DgnFolderMoniker::GetSavedFolderName);   
    c3.def("GetSavedFolderName", &DgnFolderMoniker::GetSavedFolderName);   

    c3.def("ResolveParentFolderMoniker", [] (DgnFolderMoniker const& self)
           {
           StatusInt status = ERROR;
           auto retVal = self.ResolveParentFolderMoniker(&status);
           return py::make_tuple(retVal, status);
           }, DOC(Bentley, DgnPlatform, DgnFolderMoniker, ResolveParentFolderMoniker));

    c3.def("TransformTo", &DgnFolderMoniker::TransformTo, "base"_a, DOC(Bentley, DgnPlatform, DgnFolderMoniker, TransformTo));

    //===================================================================================
    // struct DgnDocumentNameProperty
    py::class_<DgnDocumentNameProperty, RefCountedPtr<DgnDocumentNameProperty> > c4(m, "DgnDocumentNameProperty");

    c4.def(py::init<WCharCP>(), "n"_a);
    c4.def_static("Create", &DgnDocumentNameProperty::Create, "n"_a);

    //===================================================================================
    // struct DgnDocument
    py::class_<DgnDocument, RefCountedPtr<DgnDocument> > c5(m, "DgnDocument");

    if (true)
        {
        //===================================================================================
        // enum class OverwriteMode
        py::enum_< DgnDocument::OverwriteMode>(c5, "OverwriteMode")
            .value("eNever", DgnDocument::OverwriteMode::Never)
            .value("eAlways", DgnDocument::OverwriteMode::Always)
            .value("ePrompt", DgnDocument::OverwriteMode::Prompt)
            .export_values();

        //===================================================================================
        // enum class CreateOptions
        py::enum_< DgnDocument::CreateOptions>(c5, "CreateOptions")
            .value("eDefault", DgnDocument::CreateOptions::Default)
            .value("eSupressFailureNotification", DgnDocument::CreateOptions::SupressFailureNotification)
            .export_values();

        //===================================================================================
        // enum class Access
        py::enum_< DgnDocument::Access>(c5, "Access")
            .value("eNone", DgnDocument::Access::None)
            .value("eReadOnly", DgnDocument::Access::ReadOnly)
            .value("eExclusiveWrite", DgnDocument::Access::ExclusiveWrite)
            .export_values();

        //===================================================================================
        // enum class Permissions
        py::enum_< DgnDocument::Permissions>(c5, "Permissions")
            .value("eNone", DgnDocument::Permissions::None)
            .value("eRead", DgnDocument::Permissions::Read)
            .value("eWrite", DgnDocument::Permissions::Write)
            .value("eReadWrite", DgnDocument::Permissions::ReadWrite)
            .export_values();

        //===================================================================================
        // enum class State
        py::enum_< DgnDocument::State>(c5, "State")
            .value("eDoesNotExist", DgnDocument::State::DoesNotExist)
            .value("eInDMS", DgnDocument::State::InDMS)
            .value("eInFileSystem", DgnDocument::State::InFileSystem)
            .export_values();

        //===================================================================================
        // enum class FetchMode
        py::enum_< DgnDocument::FetchMode>(c5, "FetchMode")
            .value("eInfoOnly", DgnDocument::FetchMode::InfoOnly)
            .value("eRead", DgnDocument::FetchMode::Read)
            .value("eWrite", DgnDocument::FetchMode::Write)
            .export_values();

        //===================================================================================
        // enum class FetchOptions
        py::enum_< DgnDocument::FetchOptions>(c5, "FetchOptions")
            .value("eDefault", DgnDocument::FetchOptions::Default)
            .value("eExport", DgnDocument::FetchOptions::Export)
            .value("eWithSet", DgnDocument::FetchOptions::WithSet)
            .value("eSilent", DgnDocument::FetchOptions::Silent)
            .value("eApplicationReserved", DgnDocument::FetchOptions::ApplicationReserved)
            .export_values();

        //===================================================================================
        // enum class PutAction
        py::enum_< DgnDocument::PutAction>(c5, "PutAction")
            .value("eCheckin", DgnDocument::PutAction::Checkin)
            .value("eUpdateRepository", DgnDocument::PutAction::UpdateRepository)
            .value("eFree", DgnDocument::PutAction::Free)
            .export_values();

        //===================================================================================
        // enum class PutOptions
        py::enum_< DgnDocument::PutOptions>(c5, "PutOptions")
            .value("eDefault", DgnDocument::PutOptions::Default)
            .value("eLeaveLocal", DgnDocument::PutOptions::LeaveLocal)
            .value("ePushSet", DgnDocument::PutOptions::PushSet)
            .value("eSilent", DgnDocument::PutOptions::Silent)
            .value("eApplicationReserved", DgnDocument::PutOptions::ApplicationReserved)
            .export_values();
        }

    c5.def_static("CreateFromMoniker", [] (DgnDocumentMonikerR moniker, int defFileId, DgnDocument::FetchMode fetchMode, DgnDocument::FetchOptions fetchOptions)
                  {
                  StatusInt status = ERROR;
                  auto retVal = DgnDocument::CreateFromMoniker(status, moniker, defFileId, fetchMode, fetchOptions);
                  return py::make_tuple(retVal, status);
                  }, "moniker"_a, "defFileId"_a = (int)DEFDGNFILE_ID, "fetchMode"_a = DgnDocument::FetchMode::Read, "fetchOptions"_a = DgnDocument::FetchOptions::Default, DOC(Bentley, DgnPlatform, DgnDocument, CreateFromMoniker));

    c5.def_static("CreateFromFileName", [] (WCharCP fileName, WCharCP searchPath, int defFileId, DgnDocument::FetchMode fetchMode, DgnDocument::FetchOptions fetchOptions)
                  {
                  DgnFileStatus status = DgnFileStatus::DGNFILE_STATUS_UnknownError;
                  auto retVal = DgnDocument::CreateFromFileName(status, fileName, searchPath, defFileId, fetchMode, fetchOptions);
                  return py::make_tuple(retVal, status);
                  }, "fileName"_a, "searchPath"_a, "defFileId"_a, "fetchMode"_a, "fetchOptions"_a = DgnDocument::FetchOptions::Default, DOC(Bentley, DgnPlatform, DgnDocument, CreateFromFileName));
    
    c5.def_static("CreateForNewFile", [] (WCharCP documentName, WCharCP searchPath, int defFileId, WCharCP wDefaultFileName, DgnDocument::OverwriteMode overwriteMode, DgnDocument::CreateOptions options)
                  {
                  DgnFileStatus status = DgnFileStatus::DGNFILE_STATUS_UnknownError;
                  auto retVal = DgnDocument::CreateForNewFile(status, documentName, searchPath, defFileId, wDefaultFileName, overwriteMode, options);
                  return py::make_tuple(retVal, status);
                  }, "documentName"_a, "searchPath"_a, "defFileId"_a, "defaultFileName"_a, "overwriteMode"_a, "options"_a = DgnDocument::CreateOptions::Default, DOC(Bentley, DgnPlatform, DgnDocument, CreateForNewFile));

    c5.def_static("CreateNew", [] (WCharCP documentName, DgnFolderMonikerR parentFolderMoniker, int defFileId, DgnDocument::OverwriteMode overwriteMode, DgnDocument::CreateOptions options)
                  {
                  DgnFileStatus status = DgnFileStatus::DGNFILE_STATUS_UnknownError;
                  auto retVal = DgnDocument::CreateNew(status, documentName, parentFolderMoniker, defFileId, overwriteMode, options);
                  return py::make_tuple(retVal, status);
                  }, "documentName"_a, "parentFolderMoniker"_a, "defFileId"_a, "overwriteMode"_a, "options"_a = DgnDocument::CreateOptions::Default, DOC(Bentley, DgnPlatform, DgnDocument, CreateNew));

    c5.def_static("CreateForEmbeddedFile", &DgnDocument::CreateForEmbeddedFile, "pseudoFileName"_a, DOC(Bentley, DgnPlatform, DgnDocument, CreateForEmbeddedFile));
    c5.def_static("CreateForLocalFile", &DgnDocument::CreateForLocalFile, "fileName"_a, DOC(Bentley, DgnPlatform, DgnDocument, CreateForLocalFile));

    c5.def_property_readonly("Moniker", &DgnDocument::GetMonikerPtr);
    c5.def("GetMoniker", &DgnDocument::GetMonikerPtr, DOC(Bentley, DgnPlatform, DgnDocument, GetMoniker));

    c5.def("Fetch", &DgnDocument::Fetch, "mode"_a = DgnDocument::FetchMode::Read, "options"_a = DgnDocument::FetchOptions::Default, DOC(Bentley, DgnPlatform, DgnDocument, Fetch));
    c5.def("Put", &DgnDocument::Put, "action"_a = DgnDocument::PutAction::Checkin, "options"_a = DgnDocument::PutOptions::Default, "comment"_a = nullptr, DOC(Bentley, DgnPlatform, DgnDocument, Put));
    c5.def("OnNewFileCreated", &DgnDocument::OnNewFileCreated, DOC(Bentley, DgnPlatform, DgnDocument, OnNewFileCreated));
    c5.def("HasLocalChanges", &DgnDocument::HasLocalChanges, DOC(Bentley, DgnPlatform, DgnDocument, HasLocalChanges));
    
    c5.def("GetCommitTime", [] (DgnDocumentCR self)
           {
           Int64 commitTime = 0;
           auto retVal = self.GetCommitTime(commitTime);
           return py::make_tuple(retVal, commitTime);
           }, DOC(Bentley, DgnPlatform, DgnDocument, GetCommitTime));
    
    c5.def("HasServerChanges", &DgnDocument::HasServerChanges, DOC(Bentley, DgnPlatform, DgnDocument, HasServerChanges));
    c5.def("DocState", &DgnDocument::GetDocState);
    c5.def("IsSameFile", &DgnDocument::IsSameFile, "other"_a, DOC(Bentley, DgnPlatform, DgnDocument, IsSameFile));
    c5.def("IsInSameRepository", py::overload_cast<DgnDocumentCP>(&DgnDocument::IsInSameRepository, py::const_), "compareDocument"_a, DOC(Bentley, DgnPlatform, DgnDocument, IsInSameRepository));
    
    c5.def_property_readonly("Permissions", &DgnDocument::GetPermissions);
    c5.def("GetPermissions", &DgnDocument::GetPermissions, DOC(Bentley, DgnPlatform, DgnDocument, GetPermissions));
    
    c5.def_property_readonly("AvailableAccess", &DgnDocument::GetAvailableAccess);
    c5.def("GetAvailableAccess", &DgnDocument::GetAvailableAccess, DOC(Bentley, DgnPlatform, DgnDocument, GetAvailableAccess));
    
    c5.def_property_readonly("MyAccess", &DgnDocument::GetMyAccess);
    c5.def("GetMyAccess", &DgnDocument::GetMyAccess, DOC(Bentley, DgnPlatform, DgnDocument, GetMyAccess));

    c5.def_property_readonly("FileName", &DgnDocument::GetFileName);
    c5.def("GetFileName", &DgnDocument::GetFileName, DOC(Bentley, DgnPlatform, DgnDocument, GetFileName));

    c5.def("SetLocalFileModifyTime", &DgnDocument::SetLocalFileModifyTime, "newTime"_a, DOC(Bentley, DgnPlatform, DgnDocument, SetLocalFileModifyTime));

    c5.def_property("ReadOnly", &DgnDocument::IsReadOnly, &DgnDocument::SetReadOnly);
    c5.def("IsReadOnly", &DgnDocument::IsReadOnly, DOC(Bentley, DgnPlatform, DgnDocument, IsReadOnly));
    c5.def("SetReadOnly", &DgnDocument::SetReadOnly, "readOnly"_a, DOC(Bentley, DgnPlatform, DgnDocument, SetReadOnly));

    c5.def_property("NameForRecentFileList", &DgnDocument::GetNameForRecentFileList, &DgnDocument::SetNameForRecentFileList);
    c5.def("GetNameForRecentFileList", &DgnDocument::GetNameForRecentFileList, DOC(Bentley, DgnPlatform, DgnDocument, GetNameForRecentFileList));
    c5.def("SetNameForRecentFileList", &DgnDocument::SetNameForRecentFileList, "name"_a, DOC(Bentley, DgnPlatform, DgnDocument, SetNameForRecentFileList));
    c5.def("GetNameForRecentFileList", &DgnDocument::GetNameForRecentFileList, DOC(Bentley, DgnPlatform, DgnDocument, GetNameForRecentFileList));
    c5.def("SetNameForRecentFileList", &DgnDocument::SetNameForRecentFileList, "name"_a, DOC(Bentley, DgnPlatform, DgnDocument, SetNameForRecentFileList));

    //===================================================================================
    // struct DgnFolder
    py::class_<DgnFolder, RefCountedPtr<DgnFolder> > c6(m, "DgnFolder");

    if (true)
        {
        //===================================================================================
        // enum class CreateOptions
        py::enum_< DgnFolder::CreateOptions>(c6, "CreateOptions")
            .value("eDefault", DgnFolder::CreateOptions::Default)
            .value("eAcceptExisting", DgnFolder::CreateOptions::AcceptExisting)
            .export_values();

        //===================================================================================
        // enum class Permissions
        py::enum_< DgnFolder::Permissions>(c6, "Permissions")
            .value("eNone", DgnFolder::Permissions::None)
            .value("eRead", DgnFolder::Permissions::Read)
            .value("eCreateFolder", DgnFolder::Permissions::CreateFolder)
            .value("eCreateDocument", DgnFolder::Permissions::CreateDocument)
            .value("eDelete", DgnFolder::Permissions::Delete)
            .export_values();
        }

    c6.def_property_readonly("Moniker", &DgnFolder::GetMonikerPtr);
    c6.def("GetMoniker", &DgnFolder::GetMonikerPtr, DOC(Bentley, DgnPlatform, DgnFolder, GetMoniker));

    c6.def_property_readonly("FolderName", &DgnFolder::GetFolderName);
    c6.def("GetFolderName", &DgnFolder::GetFolderName, DOC(Bentley, DgnPlatform, DgnFolder, GetFolderName));

    c6.def("GetContents", &DgnFolder::GetContents, "filter"_a = nullptr, DOC(Bentley, DgnPlatform, DgnFolder, GetContents));
    c6.def("GetSubFolders", &DgnFolder::GetSubFolders, "filter"_a = nullptr, DOC(Bentley, DgnPlatform, DgnFolder, GetSubFolders));
    c6.def("GetDocuments", py::overload_cast<WCharCP>(&DgnFolder::GetDocuments, py::const_), "filter"_a = nullptr, DOC(Bentley, DgnPlatform, DgnFolder, GetDocuments));
    c6.def("IsDmsFolder", &DgnFolder::IsDmsFolder, DOC(Bentley, DgnPlatform, DgnFolder, IsDmsFolder));

    c6.def_static("CreateFromMoniker", [] (DgnFolderMonikerR moniker)
                  {
                  StatusInt status;
                  return DgnFolder::CreateFromMoniker(status, moniker);
                  }, "moniker"_a, DOC(Bentley, DgnPlatform, DgnFolder, CreateFromMoniker));

    c6.def_static("CreateNew", [] (WCharCP folderName, DgnFolderMonikerR parentFolderMoniker, DgnFolder::CreateOptions options)
                  {
                  DgnFileStatus status;
                  return DgnFolder::CreateNew(status, folderName, parentFolderMoniker, options);
                  }, "folderName"_a, "parentFolderMoniker"_a, "options"_a = DgnFolder::CreateOptions::Default, DOC(Bentley, DgnPlatform, DgnFolder, CreateNew));

    c6.def("IsInSameRepository", py::overload_cast<DgnFolderCP>(&DgnFolder::IsInSameRepository, py::const_), "compareFolder"_a, DOC(Bentley, DgnPlatform, DgnFolder, IsInSameRepository));
    c6.def("IsInSameRepository", py::overload_cast<DgnDocumentCP>(&DgnFolder::IsInSameRepository, py::const_), "compareDocument"_a, DOC(Bentley, DgnPlatform, DgnFolder, IsInSameRepository));
    
    c6.def_property_readonly("Permissions", &DgnFolder::GetPermissions);
    c6.def("GetPermissions", &DgnFolder::GetPermissions, DOC(Bentley, DgnPlatform, DgnFolder, GetPermissions));

    //===================================================================================
    // struct DgnBaseMonikerList
    py::class_< DgnBaseMonikerList, DgnBaseMonikerListPtr> c7(m, "DgnBaseMonikerList");

    c7.def(py::init(&DgnBaseMonikerList::Create));
    
    c7.def("__iter__", [] (DgnBaseMonikerList& self) { return py::make_iterator(self.begin(), self.end()); }, py::keep_alive<0, 1>());
    c7.def("__len__", &DgnBaseMonikerList::size);
    c7.def("Add", &DgnBaseMonikerList::Add, "moniker"_a);
    c7.def("Remove", &DgnBaseMonikerList::Remove, "moniker"_a);
    c7.def("Clear", &DgnBaseMonikerList::Clear);

    //===================================================================================
    // struct DgnDocumentMonikerList
    py::class_< DgnDocumentMonikerList, DgnDocumentMonikerListPtr> c8(m, "DgnDocumentMonikerList");

    c8.def(py::init(&DgnDocumentMonikerList::Create));

    c8.def("__iter__", [] (DgnDocumentMonikerList& self) { return py::make_iterator(self.begin(), self.end()); }, py::keep_alive<0, 1>());
    c8.def("__len__", &DgnDocumentMonikerList::size);
    c8.def("Add", &DgnDocumentMonikerList::Add, "moniker"_a);
    c8.def("Remove", &DgnDocumentMonikerList::Remove, "moniker"_a);
    c8.def("Clear", &DgnDocumentMonikerList::Clear);
    c8.def("ToDgnBaseMonikerList", &DgnDocumentMonikerList::ToDgnBaseMonikerList);

    //===================================================================================
    // struct DgnFolderMonikerList
    py::class_< DgnFolderMonikerList, DgnFolderMonikerListPtr> c9(m, "DgnFolderMonikerList");

    c9.def(py::init(&DgnFolderMonikerList::Create));

    c9.def("__iter__", [] (DgnFolderMonikerList& self) { return py::make_iterator(self.begin(), self.end()); }, py::keep_alive<0, 1>());
    c9.def("__len__", &DgnFolderMonikerList::size);
    c9.def("Add", &DgnFolderMonikerList::Add, "moniker"_a);
    c9.def("Remove", &DgnFolderMonikerList::Remove, "moniker"_a);
    c9.def("Clear", &DgnFolderMonikerList::Clear);
    c9.def("ToDgnBaseMonikerList", &DgnFolderMonikerList::ToDgnBaseMonikerList);
   }