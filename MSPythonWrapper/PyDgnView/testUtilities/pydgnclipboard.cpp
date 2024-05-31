/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnView\testUtilities\pydgnclipboard.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <DgnView/DgnClipBoard.h>

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       9/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_DgnClipBoardContext(py::module_& m)
    {
    //===================================================================================
    // struct DgnClipBoardContext
    py::class_<DgnClipBoardContext, RefCountedPtr<DgnClipBoardContext> > c0(m, "DgnClipBoardContext");

    py::enum_<DgnClipBoardContext::ClipBoardPurpose>(c0, "ClipBoardPurpose")
        .value("eCopyPaste", DgnClipBoardContext::CopyPaste)
        .value("eDragDrop", DgnClipBoardContext::DragDrop)
        .export_values();

    //===================================================================================
    // struct DgnClipBoardContext
    py::class_<DgnClipBoardContext::ClipInfo> c00(c0, "ClipInfo");
    c00.def_readwrite("m_file", &DgnClipBoardContext::ClipInfo::m_file);
    c00.def_readwrite("m_query", &DgnClipBoardContext::ClipInfo::m_query);

    c0.def_readonly_static ("ELEMENT_CLIPBOARD_FORMAT_NAME", &DgnClipBoardContext::ELEMENT_CLIPBOARD_FORMAT_NAME);
    c0.def_readonly_static("ELEMENT_SELECTION_CLIPBOARD_FORMAT_NAME", &DgnClipBoardContext::ELEMENT_SELECTION_CLIPBOARD_FORMAT_NAME);
    c0.def_readonly_static("DGNEC_CLIPBOARD_FORMAT_NAME", &DgnClipBoardContext::DGNEC_CLIPBOARD_FORMAT_NAME);

    c0.def("GetFileName", &DgnClipBoardContext::GetFileName, "fileName"_a);
    c0.def("GetCopyContext", [](DgnClipBoardContext& self, ElementCopyContextP context){return self.GetCopyContext(context);}, "context"_a);
    c0.def("SaveDgn", [](DgnClipBoardContext& self, ElementCopyContextP context){return self.SaveDgn(context);}, "context"_a);

    c0.def("GetLegacyClipBoardString", [](DgnClipBoardContext& self, WCharCP formatName, WStringR clipString, UInt32 windowId)
        {
        return self.GetLegacyClipBoardString (formatName, clipString, windowId);
        }, "formatName"_a, "clipString"_a, "windowId"_a);

    c0.def("GetClipBoardStringDataNode", &DgnClipBoardContext::GetClipBoardStringDataNode, "dataNodeString"_a, "query"_a);

    c0.def("PrepareClipBoardStringWithDataNodes", &DgnClipBoardContext::PrepareClipBoardStringWithDataNodes, "clipString"_a, "dataNodes"_a, "windowId"_a);

    c0.def_static("GetClipInfos", &DgnClipBoardContext::GetClipInfos, "clipInfos"_a, "windowId"_a, "clipData"_a);

    c0.def_static("CopyElementsToModel", py::overload_cast<DgnModelR, WCharCP>(&DgnClipBoardContext::CopyElementsToModel), "model"_a, "clipData"_a);

    c0.def_static("CopyElementsToModel", py::overload_cast<DgnModelR&, ECQueryCR, DgnFileR>(&DgnClipBoardContext::CopyElementsToModel), "model"_a, "query"_a, "file"_a);

    c0.def_static("GetDgnFile", &DgnClipBoardContext::GetDgnFile, "moniker"_a);

    c0.def_static("CreateDgnFile", &DgnClipBoardContext::CreateDgnFile, "newModel"_a, "seedModel"_a, "path"_a);

    c0.def_static("CreateExternalFileContext", &DgnClipBoardContext::CreateExternalFileContext, "srcModel"_a, "purpose"_a);

    c0.def_static("CreateContext", &DgnClipBoardContext::CreateContext, "file"_a, "purpose"_a);
    }

