/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnPlatform\source\colorbook.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <DgnPlatform/ColorBook.h>



static const char * __doc_Bentley_DgnPlatform_ColorBook_GetEntryCount =R"doc(Get the number of entries in the ColorBook.)doc";

static const char * __doc_Bentley_DgnPlatform_ColorBook_GetEntry =R"doc(Get an entry from the ColorBook.)doc";

static const char * __doc_Bentley_DgnPlatform_ColorBook_FindColorByName =R"doc(Find a color by name in the ColorBook.)doc";

static const char * __doc_Bentley_DgnPlatform_ColorBook_AddEntry =R"doc(Add an entry to the ColorBook.)doc";

static const char * __doc_Bentley_DgnPlatform_ColorBook_LoadFromDgn =R"doc(Load the named ColorBook by name from the DgnFile. Optionally look in
DgnLibs for the color book.)doc";

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_ColorBook(py::module_& m)
    {
    //===================================================================================
    // struct ColorBook
    py::class_<ColorBook, ColorBookPtr> c1(m, "ColorBook");
    
    c1.def_static("LoadFromDgn", &ColorBook::LoadFromDgn, "loadedColorBook"_a, "bookName"_a, "dgnFile"_a, "searchDgnLibs"_a, "dgnHost"_a, DOC(Bentley, DgnPlatform, ColorBook, LoadFromDgn));
    c1.def("AddEntry", &ColorBook::AddEntry, "colorName"_a, "red"_a, "green"_a, "blue"_a, DOC(Bentley, DgnPlatform, ColorBook, AddEntry));
    c1.def("FindColorByName", &ColorBook::FindColorByName, "color"_a, "colorName"_a, DOC(Bentley, DgnPlatform, ColorBook, FindColorByName));
    c1.def("GetEntry", &ColorBook::GetEntry, "color"_a, "name"_a, "index"_a, DOC(Bentley, DgnPlatform, ColorBook, GetEntry));
    
    c1.def_property_readonly("EntryCount", &ColorBook::GetEntryCount);
    c1.def("GetEntryCount", &ColorBook::GetEntryCount, DOC(Bentley, DgnPlatform, ColorBook, GetEntryCount));
    }