/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyBentley\source\betextfile.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <Bentley/BeTextFile.h>



static const char * __doc_Bentley_BeTextFile_GetPointer = R"doc(Gets the file read/write position.

:param position:
    the current read/write position

:returns:
    BeFileStatus::Success if the operation was successful or non-zero
    if it failed.)doc";

static const char * __doc_Bentley_BeTextFile_SetPointer = R"doc(Moves the file read/write position

Parameter ``position``:
    The new read/write position.

Parameter ``origin``:
    The origin mode for the move.

Returns:
    BeFileStatus::Success if the operation was successful or non-zero
    if it failed.

Remark:
    s Use Rewind to go to the beginning of rthe text data (rather than
    SetPointer (0, BeFileSeekOrigin::Begin) because Rewind accounts
    for the encoding signature that might be at the beginning of the
    file.)doc";

static const char * __doc_Bentley_BeTextFile_Rewind = R"doc(Rewinds the file and prepare for reading from the beginning of the
text data (i.e., just past the encoding signature, if there is one).

:returns:
    BeFileStatus::Success if the operation was successful or non-zero
    if it failed.)doc";

static const char * __doc_Bentley_BeTextFile_GetChar = R"doc(Reads the next character from the file.

:returns:
    The next character or WEOF.)doc";

static const char * __doc_Bentley_BeTextFile_PutLine = R"doc(Writes a line to the file.

:param textLine:
    The buffer to read the line into.

:param addCarriageReturn:
    If true, appends a newline character to the input *textLine.*

Remark:
    s The data will be converted to the encoding specified when
    opening the file.

:returns:
    TextFileWriteStatus::Success if the line was written successfully;
    otherwise an error code.)doc";

static const char * __doc_Bentley_BeTextFile_GetLine = R"doc(Reads a line from the file.

Parameter ``textLine``:
    The buffer to read the line into.

Remark:
    s The line is always converted to Unicode in UTF-16.

Remark:
    s The handling of newlines is controlled by the options when
    opening the file.

Returns:
    TextFileReadStatus::Success if the line was read successfully;
    otherwise TextFileReadStatus::Eof or an error code.)doc";

static const char * __doc_Bentley_BeTextFile_Close = R"doc(Closes the text file.

Remark:
    s This call is not usually necessary, as the file is closed
    automatically when the reference-counted pointer is released.)doc";

static const char * __doc_Bentley_BeTextFile_Open = R"doc(Opens a text file for reading or writing.

:param status:
    BeFileStatus::Success on success or the file open error.

:param fullFileSpec:
    Name of the file to open.

:param openType:
    Whether to open the file for read, write or append.

:param options:
    Options controlling how newline characters are treated on read.

:param encoding:
    Encoding for the file; use TextFileEncoding::CurrentLocale for
    ASCII. This parameter is used only when openType is
    TextFileOpenType::Write.

Remark:
    s When opened for read or append, the text file encoding will be
    read from the beginning of the file (if it is there) and the
    contents will be read and converted from its encoding to Unicode.

Remark:
    s When opened for write, the *encoding* argument indicates how the
    output is to be written. If there is an existing file with the
    same name, that file is replaced by a new file.

:returns:
    A pointer to the file. If status is not BeFileStatus::Success then
    the pointer will fail the IsValid() check.)doc";



/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_BeTextFile(py::module_& m)
    {
    //===================================================================================
    // enum class TextFileOpenType
    py::enum_< TextFileOpenType>(m, "TextFileOpenType")
        .value("eRead", TextFileOpenType::Read)
        .value("eWrite", TextFileOpenType::Write)
        .value("eAppend", TextFileOpenType::Append)
        .export_values();

    //===================================================================================
    // enum class TextFileEncoding
    py::enum_< TextFileEncoding>(m, "TextFileEncoding")
        .value("eCurrentLocale", TextFileEncoding::CurrentLocale)
        .value("eUtf8", TextFileEncoding::Utf8)
        .value("eUtf16", TextFileEncoding::Utf16)
        .export_values();

    //===================================================================================
    // enum class TextFileOptions
    py::enum_< TextFileOptions>(m, "TextFileOptions")
        .value("eNone_", TextFileOptions::None)
        .value("eKeepNewLine", TextFileOptions::KeepNewLine)
        .value("eNewLinesToSpace", TextFileOptions::NewLinesToSpace)
        .export_values();

    //===================================================================================
    // enum class TextFileReadStatus
    py::enum_< TextFileReadStatus>(m, "TextFileReadStatus")
        .value("eSuccess", TextFileReadStatus::Success)
        .value("eEof", TextFileReadStatus::Eof)
        .value("eBadParameter", TextFileReadStatus::BadParameter)
        .export_values();

    //===================================================================================
    // enum class TextFileWriteStatus
    py::enum_< TextFileWriteStatus>(m, "TextFileWriteStatus")
        .value("eSuccess", TextFileWriteStatus::Success)
        .value("eError", TextFileWriteStatus::Error)
        .value("eBadParameter", TextFileWriteStatus::BadParameter)
        .export_values();

    //===================================================================================
    // struct BeTextFile
    py::class_< BeTextFile, BeTextFilePtr> c1(m, "BeTextFile","Reads and Writes Text Files regardless of whether they are encoded on disk as locale-encoded ASCII, UTF8, or UTF16.");

    c1.def_static("Open", [] (WCharCP fullFileSpec, TextFileOpenType openType, TextFileOptions options, TextFileEncoding encoding)
                  {
                  BeFileStatus status = BeFileStatus::UnknownError;
                  auto retVal = BeTextFile::Open(status, fullFileSpec, openType, options, encoding);
                  return py::make_tuple(retVal, status);
                  }, "fullFileSpec"_a, "openType"_a, "options"_a, "encoding"_a = TextFileEncoding::CurrentLocale, DOC(Bentley, BeTextFile, Open));

    c1.def("Close", &BeTextFile::Close, DOC(Bentley, BeTextFile, Close));
    c1.def("GetLine", &BeTextFile::GetLine, "textLine"_a, DOC(Bentley, BeTextFile, GetLine));
    c1.def("PutLine", &BeTextFile::PutLine, "textLine"_a, "addCR"_a, DOC(Bentley, BeTextFile, PutLine));
    c1.def("GetChar", &BeTextFile::GetChar, DOC(Bentley, BeTextFile, GetChar));
    c1.def("Rewind", &BeTextFile::Rewind, DOC(Bentley, BeTextFile, Rewind));
    c1.def("SetPointer", &BeTextFile::SetPointer, "position"_a, "origin"_a, DOC(Bentley, BeTextFile, SetPointer));
    c1.def("GetPointer", [] (BeTextFile& self)
           {
           UInt64 position = 0;
           auto retVal = self.GetPointer(position);
           return py::make_tuple(retVal, position);
           }, DOC(Bentley, BeTextFile, GetPointer));
    }