/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyBentley\source\befile.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <Bentley/BeFile.h>
#include <OpqueTypes_Bentley.h>



static const char * __doc_Bentley_BeFile_ReadEntireFile = R"doc(Reads entire file to a byte vector.)doc";

static const char * __doc_Bentley_BeFile_SetSize = R"doc(Sets the size of the file.

:param length:
    The new size of the file in bytes.

:returns:
    BeFileStatus::Success if the operation was successful or non-zero
    if it failed.)doc";

static const char * __doc_Bentley_BeFile_GetSize = R"doc(Gets the size of the file.

:param length:
    The size of the file in bytes

:returns:
    BeFileStatus::Success if the operation was successful or non-zero
    if it failed.)doc";

static const char * __doc_Bentley_BeFile_Flush = R"doc(Flushes all pending writes to the file

:returns:
    BeFileStatus::Success if the operation was successful or non-zero
    if it failed.)doc";

static const char * __doc_Bentley_BeFile_GetPointer = R"doc(Gets the file read/write position

:param position:
    the current read/write position

:returns:
    BeFileStatus::Success if the operation was successful or non-zero
    if it failed.)doc";

static const char * __doc_Bentley_BeFile_SetPointer = R"doc(Moves the file read/write position.

:param position:
    The new read/write position.

:param origin:
    The origin mode for the move.

:returns:
    BeFileStatus::Success if the operation was successful or non-zero
    if it failed.)doc";

static const char * __doc_Bentley_BeFile_GetLastError = R"doc(Gets the status returned by the last operation that failed.)doc";

static const char * __doc_Bentley_BeFile_GetShareMode = R"doc(Gets the sharing option used to open the disk file.)doc";

static const char * __doc_Bentley_BeFile_GetAccess = R"doc(Gets the access mode used to open the disk file.)doc";

static const char * __doc_Bentley_BeFile_IsOpen = R"doc(Query whether the disk file is open.)doc";

static const char * __doc_Bentley_BeFile_Close = R"doc(Closes the disk file.)doc";

static const char * __doc_Bentley_BeFile_Open = R"doc(Opens an existing file.

:param filename:
    The full path the file to open.

:param mode:
    The file open mode.

:param shareOptions:
    The file sharing options.

:param attributes:
    The file attributes.

:param numRetries:
    The number of times to retry the open in the event of a sharing
    violation.

:returns:
    BeFileStatus::Success if the file was opened or non-zero if open
    failed.)doc";

static const char * __doc_Bentley_BeFile_Create = R"doc(Creates a new disk file

:param filename:
    The full path of the file to create.

:param createAlways:
    If false, returns a status other than BeFileStatus::Success, and
    does not create a new file if *filename* already exists. If true,
    deletes any existing file before creating a new one by the same
    name.

:param attributes:
    File attributes.

:returns:
    BeFileStatus::Success if the file was created or non-zero if
    create failed.)doc";

static const char * __doc_Bentley_BeFile_Swap = R"doc(Swap file handles between two BeFile instances.

:param other:
    The other file.)doc";



/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_BeFile(py::module_& m)
    {
    //===================================================================================
    // enum class BeFileStatus
    py::enum_< BeFileStatus>(m, "BeFileStatus")
        .value("eSuccess", BeFileStatus::Success)
        .value("eFileNotFoundError", BeFileStatus::FileNotFoundError)
        .value("eAccessViolationError", BeFileStatus::AccessViolationError)
        .value("eSharingViolationError", BeFileStatus::SharingViolationError)
        .value("eTooManyOpenFilesError", BeFileStatus::TooManyOpenFilesError)
        .value("eFileNotOpenError", BeFileStatus::FileNotOpenError)
        .value("eNotLockedError", BeFileStatus::NotLockedError)
        .value("eReadError", BeFileStatus::ReadError)
        .value("eUnknownError", BeFileStatus::UnknownError)
        .export_values();

    //===================================================================================
    // enum class BeFileAccess
    py::enum_< BeFileAccess>(m, "BeFileAccess")
        .value("eRead", BeFileAccess::Read)
        .value("eWrite", BeFileAccess::Write)
        .value("eReadWrite", BeFileAccess::ReadWrite)
        .export_values();

    //===================================================================================
    // enum class BeFileSharing
    py::enum_< BeFileSharing>(m, "BeFileSharing")
        .value("eNone", BeFileSharing::None)
        .value("eRead", BeFileSharing::Read)
        .value("eWrite", BeFileSharing::Write)
        .value("eReadWrite", BeFileSharing::ReadWrite)        
        .export_values();

    //===================================================================================
    // enum class BeFileAttributes
    py::enum_< BeFileAttributes>(m, "BeFileAttributes")
        .value("eNormal", BeFileAttributes::Normal)
        .value("eRandomIO", BeFileAttributes::RandomIO)
        .value("eDeleteOnClose", BeFileAttributes::DeleteOnClose)
        .export_values();

    //===================================================================================
    // enum class BeFileSeekOrigin
    py::enum_< BeFileSeekOrigin>(m, "BeFileSeekOrigin")
        .value("eBegin", BeFileSeekOrigin::Begin)
        .value("eCurrent", BeFileSeekOrigin::Current)
        .value("eEnd", BeFileSeekOrigin::End)
        .export_values();

    //===================================================================================
    // struct BeFile
    py::class_< BeFile> c1(m, "BeFile","BeFile provides a way to open a file and methods to access its contents and attributes.");

    c1.def(py::init<>());
    c1.def("Swap", &BeFile::Swap, "other"_a, DOC(Bentley, BeFile, Swap));
    c1.def("Create", &BeFile::Create, "fileName"_a, "createAlways"_a = true, "attribute"_a = BeFileAttributes::Normal , DOC(Bentley, BeFile, Create));
    c1.def("Open", &BeFile::Open, "fileName"_a, "mode"_a, "shareOptions"_a, "attribute"_a = BeFileAttributes::Normal, "numRetries"_a = 0 , DOC(Bentley, BeFile, Open));
    c1.def("Close", &BeFile::Close , DOC(Bentley, BeFile, Close));

    c1.def_property_readonly("HasOpen", &BeFile::IsOpen);
    c1.def("IsOpen", &BeFile::IsOpen , DOC(Bentley, BeFile, IsOpen));

    c1.def_property_readonly("Access", &BeFile::GetAccess);
    c1.def("GetAccess", &BeFile::GetAccess, DOC(Bentley, BeFile, GetAccess));

    c1.def_property_readonly("ShareMode", &BeFile::GetShareMode);
    c1.def("GetShareMode", &BeFile::GetShareMode, DOC(Bentley, BeFile, GetShareMode));

    c1.def_property_readonly("LastError", &BeFile::GetLastError);
    c1.def("GetLastError", &BeFile::GetLastError, DOC(Bentley, BeFile, GetLastError));

    c1.def("SetPointer", &BeFile::SetPointer, "position"_a, "origin"_a, DOC(Bentley, BeFile, SetPointer));
    
    c1.def("GetPointer", [] (BeFile& self)
           {
           UInt64 position = 0;
           auto retVal = self.GetPointer(position);
           return py::make_tuple(retVal, position);
           }, DOC(Bentley, BeFile, GetPointer));

    c1.def("Read", [] (BeFile& self, UInt32 numBytes)
           {
           py::bytes outVal;
           BeFileStatus retVal = BeFileStatus::UnknownError;
           if (numBytes > 0)
               {
               void* buffer = _alloca(numBytes);
               UInt32 bytesRead = 0;
               retVal = self.Read(buffer, &bytesRead, numBytes);
               if (retVal == BeFileStatus::Success && bytesRead > 0)
                   outVal = py::bytes((const char*) buffer, bytesRead);
               }
           return py::make_tuple(retVal, outVal);
           }, "numBytes"_a);

    c1.def("Write", [] (BeFile& self, py::bytes const& data)
           {
           UInt32 bytesWritten = 0;
           UInt32 numBytes = (UInt32)py::len(data);
           BeFileStatus retVal = BeFileStatus::UnknownError;
           if (numBytes > 0)
               {
               std::string strData = data.cast<std::string>();
               retVal = self.Write(&bytesWritten, (const void*) strData.data(), numBytes);
               }
           return py::make_tuple(retVal, bytesWritten);
           }, "data"_a);

    c1.def("Flush", &BeFile::Flush, DOC(Bentley, BeFile, Flush));

    c1.def("GetSize", [] (BeFile& self)
           {
           UInt64 len = 0;
           auto retVal = self.GetSize(len);
           return py::make_tuple(retVal, len);
           }, DOC(Bentley, BeFile, GetSize));

    c1.def("SetSize", py::overload_cast<UInt64>(&BeFile::SetSize), "length"_a, DOC(Bentley, BeFile, SetSize));
    c1.def("ReadEntireFile", py::overload_cast<UInt8Array&>(&BeFile::ReadEntireFile), "buffer"_a, DOC(Bentley, BeFile, ReadEntireFile));
    c1.def("ReadEntireFile", py::overload_cast<ByteStream&>(&BeFile::ReadEntireFile), "byteStream"_a, DOC(Bentley, BeFile, ReadEntireFile));
    }