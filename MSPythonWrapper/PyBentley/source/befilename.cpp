/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyBentley\source\befilename.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <Bentley/BeFileName.h>



static const char * __doc_Bentley_BeFileName_BeGetTempPath = R"doc(Retrieves the path of the directory for temporary files.

:param tempFileName:
    The name for a temporary file.

:returns:
    BeFileNameStatus::Success, if the directory for the temporary file
    exists or was created.)doc";

static const char * __doc_Bentley_BeFileName_BeGetTempFileName = R"doc(Generate a unique name for a temporary file.

:param tempFileName:
    The name for a temporary file.

:param pathName:
    The path to contain the temp file. If NULL, the result of
    BeGetTempPath is used.

:param prefixString:
    up to 3 chars of this will be used in the generated filename

:returns:
    BeFileNameStatus::Success, if the directory for the temporary file
    exists or was created. @note This method does not create a
    temporary file, it merely returns a name that can be used to
    create a temporary file.)doc";

static const char * __doc_Bentley_BeFileName_BeCompactPath = R"doc(Shortens a file path to be no longer than the specified number of
characters.

:param shortened:
    the string shortened to the specified length

:param path:
    the original path

:param length:
    the number of characters to display in the shortened string
    @Return non-zero error status if not successful)doc";

static const char * __doc_Bentley_BeFileName_IsRemovableMedia = R"doc(Check if path is located on a removable storage device.

:param fn:
    The name of a file or directory on the device to check

:returns:
    true if the storage device is removable)doc";

static const char * __doc_Bentley_BeFileName_BeGetDiskFreeSpace = R"doc(Get free space on disk

:param freeBytes:
    The amount of free space on the storage device, in bytes

:param dirName:
    The name of a file or directory on the device to check

:returns:
    BeFileNameStatus::Success, if the query succeeded. Non-zero if the
    directory is invalid or refers to a storage device that does not
    exist.)doc";

static const char * __doc_Bentley_BeFileName_CheckAccess = R"doc(Check user's access to a file

:param fileName:
    The name of an existing file.

:param accs:
    The kinds of access to check for

:returns:
    BeFileNameStatus::Success if all of the specified access rights
    are granted; non-zero if the file does not exist or some of the
    specified rights are not granted.)doc";

static const char * __doc_Bentley_BeFileName_MoveToRecycleBin = R"doc(Move an existing file or an existing directory to Recycle Bin (on
Windows).

:param path:
    The pathname for the file or directory to remove.

:returns:
    DGNFILE_STATUS_Success if the target was successfully removed.)doc";

static const char * __doc_Bentley_BeFileName_SetFileReadOnly = R"doc(Set the read-only status of an existing file

:param fileName:
    The name of an existing file.

:param readOnly:
    the desired read-only status

:returns:
    BeFileNameStatus::Success if the operation was successful or non-
    zero if not)doc";

static const char * __doc_Bentley_BeFileName_BeMoveFile = R"doc(Move or rename an existing file.

:param oldFileName:
    The name of an existing file.

:param newFileName:
    The new name for the file.

:param numRetries:
    the number of times to retry the open in the event of a sharing
    violation

:returns:
    BeFileNameStatus::Success if the file was successfully moved or
    BeFileNameStatus::UnknownError if not.)doc";

static const char * __doc_Bentley_BeFileName_BeDeleteFile = R"doc(Delete an existing file.

:param fileNameP:
    The name of an existing file.

:param removeReadOnlyAttribute:
    Remove read-only attribute for the file before making an
    attempting to delete it.

:returns:
    BeFileNameStatus::Success if the file was successfully deleted or
    BeFileNameStatus::CantDeleteFile if not.)doc";

static const char * __doc_Bentley_BeFileName_BeCopyFile = R"doc(Copy an existing file. If a file with the new name already exists, it
is overwritten.

:param newFileName:
    The name for the newly copied file.

:param existingFileName:
    The name for the source file.

:param failIfFileExists:
    Do not copy and return error if the destination file already
    exists.

:returns:
    DGNFILE_STATUS_Success if the file was successfully copied.)doc";

static const char * __doc_Bentley_BeFileName_CloneDirectory = R"doc(Clone the contents of an existing directory, and optionally its
subdirectories, into a new directory.

:param destDir:
    The name for the new directory.

:param sourceDir:
    The source directory to clone.

:param includeSubDirs:
    If true, also clone all subdirectories, recursively.

:returns:
    DGNFILE_STATUS_Success if the directory was successfully cloned.)doc";

static const char * __doc_Bentley_BeFileName_EmptyAndRemoveDirectory = R"doc(Recursively empty all of the contents of an existing directory and
then remove it.

:param path:
    The pathname for the directory to remove.

:returns:
    DGNFILE_STATUS_Success if the directory was successfully removed.)doc";

static const char * __doc_Bentley_BeFileName_CreateNewDirectory = R"doc(Create a new directory.

:param path:
    The pathname for the new directory.

:returns:
    DGNFILE_STATUS_Success if the directory was successfully created.
    @note this method will return an error if the directory already
    exists.)doc";

static const char * __doc_Bentley_BeFileName_IsDirectory = R"doc(Test whether a pathname refers to an existing directory.

:param path:
    The pathname to test.

:returns:
    true if the pathname refers to an existing directory.)doc";

static const char * __doc_Bentley_BeFileName_IsEmpty = R"doc(Determines if the value of this BeFileName is empty (blank).)doc";

static const char * __doc_Bentley_BeFileName_IsUrl = R"doc(Test if a filename is an URL.)doc";

static const char * __doc_Bentley_BeFileName_IsAbsolutePath = R"doc(Test if a filename is an absolute path.)doc";

static const char * __doc_Bentley_BeFileName_DoesPathExist = R"doc(Test whether a pathname refers to an existing file or directory.

:param path:
    The pathname to test.

:returns:
    true if the pathname refers to an existing file or directory.)doc";

static const char * __doc_Bentley_BeFileName_AreSameFile = R"doc(Are two filenames equivalent?

:param file1:
    name of a file

:param file2:
    name of another file

:returns:
    true if the two strings are aliases for the same (existing)
    physical file.)doc";


static const char * __doc_Bentley_BeFileName_GetTargetOfSymbolicLink = R"doc(Determines a symbolic link's target. This recurses, meaning that it
keeps evaluating each incremental target until it reaches a concrete
file, or the target does not exist.)doc";

static const char * __doc_Bentley_BeFileName_IsSymbolicLink = R"doc(Determines if the path is a symbolic link. If the path does not exist,
also returns false.)doc";

static const char * __doc_Bentley_BeFileName_BeGetFullPathName = R"doc(Get the full name of a file

Remark:
    s this function does not check that the file or path exists)doc";

static const char * __doc_Bentley_BeFileName_FixPathName = R"doc(Perform any platform-specific fixes of an input pathname into a
" canonical " pathname. On Windows, this includes converting forward
slashes to backslashes and removing double backslashes. It also
removes " \\ " and " \\ " notation. On other platforms those rules may be
different.

:param path:
    The " fixed " version of the pathname.

:param original:
    The " raw " pathname.

:returns:
    DGNFILE_STATUS_Success if the pathname was successfully " fixed "
    (whether any changes were made or not), or PATH_IllegalName if the
    pathname is invalid for any reason.)doc";

static const char * __doc_Bentley_BeFileName_ResolveRelativePath = R"doc(Generates a fullpath by resolving relativeFileName relative to
basePath.

:param fullPath:
    (output) the full path resolved from the inputs.

:param relativeFileName:
    (input) the relative file name to resolve.

:param basePath:
    (input) used as a root for the expansion. @Return non-zero error status
    if not successful @Remarks This function only performs a string
    manipulation. It does not require or make any use of an actual
    file.)doc";

static const char * __doc_Bentley_BeFileName_FindRelativePath = R"doc(Finds the relative path from a root file to the target file. If the
files are on different devices, targetFileName is copied to
relativePath.

:param relativePath:
    (output) the relative path to the target file

:param targetFileName:
    (input) the full file specification of the file the relative path is
    needed for.

:param rootFileName:
    (input) the full file specification of the root for the relative path.)doc";

static const char * __doc_Bentley_BeFileName_GetDevice = R"doc(Returns the device letter from path - Empty if the path doesn't start
with a device. Always empty on unix.)doc";

static const char * __doc_Bentley_BeFileName_GetFileNameWithoutExtension = R"doc(Returns the base filename from path, with no directory or extension.)doc";

static const char * __doc_Bentley_BeFileName_GetFileNameAndExtension = R"doc(Returns the filename from path, including extension, but not
directory.)doc";

static const char * __doc_Bentley_BeFileName_GetExtension = R"doc(Returns the filename extension from path (everything following the
last dot non-inclusive), or empty if there is none.)doc";

static const char * __doc_Bentley_BeFileName_GetDirectoryWithoutDevice = R"doc(Returns the directory (excluding drive) from path. Has terminating
separator.)doc";

static const char * __doc_Bentley_BeFileName_GetDirectoryName = R"doc(Returns the complete directory (including drive, if any) from path.
Has terminating separator.)doc";

static const char * __doc_Bentley_BeFileName_PopDir = R"doc(Remove the right-most component from the path. If this BeFileName
contains a single dirctory (or otherwise contains no directory
separators), it becomes empty as a result of this function.)doc";

static const char * __doc_Bentley_BeFileName_ParseNameNoClear = R"doc(Parse a full filename into WStrings for the device, directory,
filename, and extension. If the input does not contain a file part,
the output is not changed.

:param dev:
    The device part of this filename. May be NULL.

:param dir:
    The directory part of this filename. May be NULL.

:param name:
    The filename part of this filename. May be NULL.

:param ext:
    The extension part of this filename. May be NULL.

:param fullFileName:
    The filename to parse.)doc";

static const char * __doc_Bentley_BeFileName_ParseName = R"doc(Parse a full filename into WStrings for the device, directory,
filename, and extension.

:param dev:
    The device part of this filename. May be NULL.

:param dir:
    The directory part of this filename. May be NULL.

:param name:
    The filename part of this filename. May be NULL.

:param ext:
    The extension part of this filename. May be NULL.

:param fullFileName:
    The filename to parse.)doc";

static const char * __doc_Bentley_BeFileName_GetUri = R"doc(Get the URI for this BeFileName.)doc";

static const char * __doc_Bentley_BeFileName_StripWhiteSpace = R"doc(Remove white space)doc";

static const char * __doc_Bentley_BeFileName_RemoveQuotes = R"doc(Remove enclosing quotes)doc";

static const char * __doc_Bentley_BeFileName_StripSeparatorAtEnd = R"doc(Strip all separators at the end)doc";

static const char * __doc_Bentley_BeFileName_AppendString = R"doc(Append string.)doc";

static const char * __doc_Bentley_BeFileName_AppendSeparator = R"doc(Make sure *dir* ends with a directory separator)doc";

static const char * __doc_Bentley_BeFileName_AppendExtension = R"doc(Append *extension* to this filepath. A period is inserted, if
necessary, before *extension.*)doc";

static const char * __doc_Bentley_BeFileName_AppendToPath = R"doc(Append *additionComponent* to this filepath. A directory separator
character is inserted, if necessary, before *additionComponent.*)doc";

static const char * __doc_Bentley_BeFileName_BuildName = R"doc(Build a BeFileName from parts of a pathname. Any values that are NULL
are omitted.)doc";

static const char * __doc_Bentley_BeFileName_Clear = R"doc(Clear the value of this BeFileName.)doc";

static const char * __doc_Bentley_BeFileName_SetName = R"doc(Change the value of this BeFileName.

:param name:
    The new value for this BeFileName. If NULL, the value is cleared.)doc";

static const char * __doc_Bentley_BeFileName_GetName = R"doc(Copy name into WChar buffer.)doc";



static const char * __doc_Bentley_BeFileName_OverrideNameParts = R"doc(Override values for parts of a file name. If the override name
includes a value for a part of the name, that value is used. Otherwise
the current value is preserved.)doc";

static const char * __doc_Bentley_BeFileName_SupplyDefaultNameParts = R"doc(Supply default values for parts of a file name. If the existing name
includes a value for a part of the name, that value is preserved.
Otherwise the default is used.)doc";

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_BeFileName(py::module_& m)
    {
    //===================================================================================
    // enum class BeFileNameStatus
    py::enum_< BeFileNameStatus>(m, "BeFileNameStatus")
        .value("eSuccess", BeFileNameStatus::Success)
        .value("eIllegalName", BeFileNameStatus::IllegalName)
        .value("eAlreadyExists", BeFileNameStatus::AlreadyExists)
        .value("eCantCreate", BeFileNameStatus::CantCreate)
        .value("eFileNotFound", BeFileNameStatus::FileNotFound)
        .value("eCantDeleteFile", BeFileNameStatus::CantDeleteFile)
        .value("eAccessViolation", BeFileNameStatus::AccessViolation)
        .value("eCantDeleteDir", BeFileNameStatus::CantDeleteDir)
        .value("eUnknownError", BeFileNameStatus::UnknownError)
        .export_values();

    //===================================================================================
    // enum class BeFileNameAccess
    py::enum_< BeFileNameAccess>(m, "BeFileNameAccess")
        .value("eExists", BeFileNameAccess::Exists)
        .value("eRead", BeFileNameAccess::Read)
        .value("eWrite", BeFileNameAccess::Write)
        .value("eReadWrite", BeFileNameAccess::ReadWrite)
        .export_values();

    //===================================================================================
    // struct BeFileName
    py::class_< BeFileName, WString> c1(m, "BeFileName","Represents a filename and provides functions to manipulate the filename and to work with files on disk by name.\nSee DgnFile for a class that works with open files.\n@remarks This implementation handles filenames up to MAX_PATH-1 in length, and it\nguarantees to hold the name in a fixed-length buffer of MAX_PATH chars (including the 0-terminator).");

    if (true)
        {
        //===================================================================================
        // enum FileNameParts
        py::enum_< BeFileName::FileNameParts>(c1, "FileNameParts", py::arithmetic())
            .value("eDevice", BeFileName::Device)
            .value("eDirectory", BeFileName::Directory)
            .value("eBasename", BeFileName::Basename)
            .value("eExtension", BeFileName::Extension)
            .value("eDevAndDir", BeFileName::DevAndDir)
            .value("eNameAndExt", BeFileName::NameAndExt)
            .value("eAll", BeFileName::All)
            .export_values();
        }

    c1.def(py::init<>(),"Construct a blank BeFileName");
    c1.def(py::init<WCharCP>(), "name"_a,"Construct a BeFileName from a null-terminated string.");
    c1.def(py::init<BeFileName::FileNameParts, WCharCP>(), "mask"_a, "fullName"_a,"Construct a BeFileName from parts of another full filename. Only the parts of the name where the corresponding argument is true are copied.\n@param in  mask     Mask of the parts of fullName that will used to construct this BeFileName\n@param in  fullName The full pathname from which this BeFileName is to be constructed.");
    c1.def(py::init<WCharCP, WCharCP, WCharCP, WCharCP>(), "dev"_a, "dir"_a, "name"_a, "ext"_a,"Construct a BeFileName from parts of a pathname. Any values that are NULL are omitted.");

    c1.def("SupplyDefaultNameParts", &BeFileName::SupplyDefaultNameParts, "defaultName"_a, DOC(Bentley, BeFileName, SupplyDefaultNameParts));
    c1.def("OverrideNameParts", &BeFileName::OverrideNameParts, "overrideName"_a, DOC(Bentley, BeFileName, OverrideNameParts));
    
    c1.def_property("Name", py::overload_cast<>(&BeFileName::GetName, py::const_), py::overload_cast<WCharCP>(&BeFileName::SetName),"Get the filename as a string.");
    c1.def("GetName", py::overload_cast<>(&BeFileName::GetName, py::const_), py::return_value_policy::reference_internal, DOC(Bentley, BeFileName, GetName));
    c1.def("SetName", py::overload_cast<WCharCP>(&BeFileName::SetName), "name"_a, DOC(Bentley, BeFileName, SetName));
    
    c1.def("Clear", &BeFileName::Clear, DOC(Bentley, BeFileName, Clear));
    c1.def("BuildName", py::overload_cast<WCharCP, WCharCP, WCharCP, WCharCP>(&BeFileName::BuildName), "dev"_a, "dir"_a, "name"_a, "ext"_a, DOC(Bentley, BeFileName, BuildName));
    c1.def("AppendToPath", py::overload_cast<WCharCP>(&BeFileName::AppendToPath), "additionalComponent"_a, py::return_value_policy::reference_internal, DOC(Bentley, BeFileName, AppendToPath));
    c1.def("AppendExtension", &BeFileName::AppendExtension, "extension"_a, DOC(Bentley, BeFileName, AppendExtension));
    c1.def("AppendSeparator", py::overload_cast<>(&BeFileName::AppendSeparator), DOC(Bentley, BeFileName, AppendSeparator));
    c1.def_static("AppendSeparatorS", py::overload_cast<WStringR>(&BeFileName::AppendSeparator), DOC(Bentley, BeFileName, AppendSeparator));
    c1.def("AppendString", &BeFileName::AppendString, "string"_a, DOC(Bentley, BeFileName, AppendString));
    c1.def("StripSeparatorAtEnd", py::overload_cast<>(&BeFileName::StripSeparatorAtEnd), DOC(Bentley, BeFileName, StripSeparatorAtEnd));
    c1.def_static("StripSeparatorAtEndS", py::overload_cast<WStringR>(&BeFileName::StripSeparatorAtEnd), DOC(Bentley, BeFileName, StripSeparatorAtEnd));
    c1.def("RemoveQuotes", &BeFileName::RemoveQuotes, DOC(Bentley, BeFileName, RemoveQuotes));
    c1.def("StripWhiteSpace", &BeFileName::StripWhiteSpace, DOC(Bentley, BeFileName, StripWhiteSpace));
    c1.def("Abbreviate", &BeFileName::Abbreviate, "maxLength"_a); 

    c1.def_property_readonly("Uri", &BeFileName::GetUri);
    c1.def("GetUri", &BeFileName::GetUri, DOC(Bentley, BeFileName, GetUri));
    
    c1.def("ParseName", py::overload_cast<WStringP, WStringP, WStringP, WStringP>(&BeFileName::ParseName, py::const_), "dev"_a, "dir"_a, "name"_a, "ext"_a, DOC(Bentley, BeFileName, ParseName));
    c1.def("ParseNameNoClear", py::overload_cast<WStringP, WStringP, WStringP, WStringP>(&BeFileName::ParseNameNoClear, py::const_), "dev"_a, "dir"_a, "name"_a, "ext"_a, DOC(Bentley, BeFileName, ParseNameNoClear));
    c1.def("PopDir", &BeFileName::PopDir, DOC(Bentley, BeFileName, PopDir));

    c1.def_static("GetDirectoryName", &BeFileName::GetDirectoryName, "path"_a, DOC(Bentley, BeFileName, GetDirectoryName));
    c1.def_static("GetDirectoryWithoutDevice", &BeFileName::GetDirectoryWithoutDevice, "path"_a, DOC(Bentley, BeFileName, GetDirectoryWithoutDevice));
    c1.def_static("GetExtension", &BeFileName::GetExtension, "path"_a, DOC(Bentley, BeFileName, GetExtension));
    c1.def_static("GetFileNameAndExtension", &BeFileName::GetFileNameAndExtension, "path"_a, DOC(Bentley, BeFileName, GetFileNameAndExtension));
    c1.def_static("GetFileNameWithoutExtension", &BeFileName::GetFileNameWithoutExtension, "path"_a, DOC(Bentley, BeFileName, GetFileNameWithoutExtension));
    c1.def_static("GetDevice", &BeFileName::GetDevice, "path"_a, DOC(Bentley, BeFileName, GetDevice));

    c1.def_static("FindRelativePath", &BeFileName::FindRelativePath, "relativePath"_a, "targetFileName"_a, "rootFileName"_a, DOC(Bentley, BeFileName, FindRelativePath));
    c1.def_static("ResolveRelativePath", &BeFileName::ResolveRelativePath, "fullPath"_a, "relativeFileName"_a, "basePath"_a, DOC(Bentley, BeFileName, ResolveRelativePath));
    c1.def_static("FixPathName", &BeFileName::FixPathName, "path"_a, "original"_a, DOC(Bentley, BeFileName, FixPathName));
    c1.def_static("BeGetFullPathName", py::overload_cast<WStringR, WCharCP>(&BeFileName::BeGetFullPathName), "path"_a, "src"_a, DOC(Bentley, BeFileName, BeGetFullPathName));
    
    c1.def("GetFullPathName", py::overload_cast<>(&BeFileName::BeGetFullPathName));

    c1.def_static("IsSymbolicLink", &BeFileName::IsSymbolicLink, "path"_a, DOC(Bentley, BeFileName, IsSymbolicLink));
    c1.def_static("GetTargetOfSymbolicLink", py::overload_cast<BeFileNameR, WCharCP>(&BeFileName::GetTargetOfSymbolicLink), "targetFileName"_a, "path"_a, DOC(Bentley, BeFileName, GetTargetOfSymbolicLink));
    c1.def_static("GetTargetOfSymbolicLink", py::overload_cast<BeFileNameR, WCharCP, bool>(&BeFileName::GetTargetOfSymbolicLink), "targetFileName"_a, "path"_a, "shouldRecurse"_a, DOC(Bentley, BeFileName, GetTargetOfSymbolicLink));
    c1.def_static("AreSameFile", &BeFileName::AreSameFile, "file1"_a, "file2"_a, DOC(Bentley, BeFileName, AreSameFile));
    c1.def_static("DoesPathExist", &BeFileName::DoesPathExist, "path"_a, DOC(Bentley, BeFileName, DoesPathExist));
    
    c1.def("IsAbsolutePath", &BeFileName::IsAbsolutePath, DOC(Bentley, BeFileName, IsAbsolutePath));    
    c1.def("IsUrl", py::overload_cast<>(&BeFileName::IsUrl, py::const_), DOC(Bentley, BeFileName, IsUrl));    
    c1.def("IsEmpty", &BeFileName::IsEmpty, DOC(Bentley, BeFileName, IsEmpty));

    c1.def_static("IsDirectory", &BeFileName::IsDirectory, "path"_a, DOC(Bentley, BeFileName, IsDirectory));
    c1.def_static("CreateNewDirectory", &BeFileName::CreateNewDirectory, "path"_a, DOC(Bentley, BeFileName, CreateNewDirectory));
    c1.def_static("EmptyAndRemoveDirectory", &BeFileName::EmptyAndRemoveDirectory, "path"_a, DOC(Bentley, BeFileName, EmptyAndRemoveDirectory));
    c1.def_static("CloneDirectory", &BeFileName::CloneDirectory, "sourceDir"_a, "destDir"_a, "includeSubDirs"_a = true, DOC(Bentley, BeFileName, CloneDirectory));

    c1.def_static("BeCopyFile", &BeFileName::BeCopyFile, "existingFileName"_a, "newFileName"_a, "failIfFileExists"_a = false, DOC(Bentley, BeFileName, BeCopyFile));
    c1.def_static("BeDeleteFile", &BeFileName::BeDeleteFile, "fileName"_a, "removeReadOnlyAttribute"_a = false, DOC(Bentley, BeFileName, BeDeleteFile));
    c1.def_static("BeMoveFile", &BeFileName::BeMoveFile, "oldFileName"_a, "newFileName"_a, "numRetries"_a = 0, DOC(Bentley, BeFileName, BeMoveFile));
    c1.def_static("SetFileReadOnly", &BeFileName::SetFileReadOnly, "fileName"_a, "readOnly"_a, DOC(Bentley, BeFileName, SetFileReadOnly));
    c1.def_static("MoveToRecycleBin", &BeFileName::MoveToRecycleBin, "path"_a, DOC(Bentley, BeFileName, MoveToRecycleBin));

    c1.def_static("GetFileSize", [] (WCharCP fileName)
                  {
                  UInt64 size = 0;
                  auto retVal = BeFileName::GetFileSize(size, fileName);
                  return py::make_tuple(retVal, size);
                  }, "fileName"_a, "Get file size\n@param in  fileName The name of an existing file.\n@return the file size");

    c1.def_static("CheckAccess", &BeFileName::CheckAccess, "fileName"_a, "access"_a, DOC(Bentley, BeFileName, CheckAccess));

    c1.def_static("BeGetDiskFreeSpace", [] (WCharCP dirName)
                  {
                  UInt64 size = 0;
                  auto retVal = BeFileName::BeGetDiskFreeSpace(size, dirName);
                  return py::make_tuple(retVal, size);
                  }, "dirName"_a, DOC(Bentley, BeFileName, BeGetDiskFreeSpace));

    c1.def_static("IsRemovableMedia", &BeFileName::IsRemovableMedia, "fileName"_a, DOC(Bentley, BeFileName, IsRemovableMedia));
    c1.def_static("BeCompactPath", &BeFileName::BeCompactPath, "shortened"_a, "path"_a, "length"_a, DOC(Bentley, BeFileName, BeCompactPath));
    c1.def_static("BeGetTempFileName", &BeFileName::BeGetTempFileName, "tempFileName"_a, "pathName"_a, "prefixString"_a, DOC(Bentley, BeFileName, BeGetTempFileName));
    c1.def_static("BeGetTempPath", &BeFileName::BeGetTempPath, "tempFileName"_a, DOC(Bentley, BeFileName, BeGetTempPath));
    }