/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnPlatform\source\csvfile.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <DgnPlatform/Tools/CsvFile.h>



static const char * __doc_Bentley_DgnPlatform_CsvFile_Open =R"doc(Open a CSV file for reading. Handle Locale, Utf8 or Utf16 encoding.

Parameter ``status``:
    BeFileStatus::Success on success or the file open error.

Parameter ``fullFileSpec``:
    Name of the file to open.

Returns:
    A pointer to the file. If status is not BeFileStatus::Success then
    the pointer will fail the IsValid() check.)doc";

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_CsvFile(py::module_& m)
    {
    //===================================================================================
    // struct CsvFile
    py::class_< CsvFile, CsvFilePtr, BeTextFile> c3(m, "CsvFile");

    c3.def_static("Open", [] (WCharCP fullFileSpec)
                  {
                  BeFileStatus status = BeFileStatus::UnknownError;
                  auto retVal = CsvFile::Open(status, fullFileSpec);
                  return py::make_tuple(retVal, status);
                  }, "fullFileSpec"_a, DOC(Bentley, DgnPlatform, CsvFile, Open));

    }