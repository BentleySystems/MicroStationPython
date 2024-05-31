/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnPlatform\source\notehandler.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <DgnPlatform/NoteHandler.h>



/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_NoteHandler(py::module_& m)
    {
    //===================================================================================
    // struct NoteCellHeaderHandler
    py::class_< NoteCellHeaderHandler
        , std::unique_ptr< NoteCellHeaderHandler, py::nodelete>
        , Type2Handler
        , IAnnotationHandler
        , ITextEdit
    > c1(m, "NoteCellHeaderHandler");

    c1.def_static("CreateNote", 
                  py::overload_cast<EditElementHandleR, EditElementHandleCR, TextBlockCR, bool, DgnModelRefR, DPoint3dCR>(&NoteCellHeaderHandler::CreateNote),
                  "noteElem"_a, "leaderElement"_a, "text"_a, "is3d"_a, "modelRef"_a, "leaderCellOrigin"_a);

    c1.def_static("CreateNote",
                  py::overload_cast<EditElementHandleR, EditElementHandleR, TextBlockCR, DimensionStyleCR, bool, DgnModelRefR, DPoint3dArray const&>(&NoteCellHeaderHandler::CreateNote),
                  "noteElem"_a, "leaderElement"_a, "text"_a, "dimStyle"_a, "is3d"_a, "modelRef"_a, "noteLeaderPoints"_a);
    c1.def_static("AddToModel", &NoteCellHeaderHandler::AddToModel, "noteElement"_a, "leaderElement"_a, "dgnModel"_a);
    c1.def("GetNoteLeader", &NoteCellHeaderHandler::GetNoteLeader, "leader"_a, "noteElement"_a);
    c1.def("GetNoteDimensionStyle", &NoteCellHeaderHandler::GetNoteDimensionStyle, "noteElement"_a);
    c1.def("SetNoteDimensionStyle", &NoteCellHeaderHandler::SetNoteDimensionStyle, "noteElement"_a, "leaderElement"_a, "dimStyle"_a);

    c1.def_property_readonly_static("Instance", [] (py::object const&) { return std::unique_ptr< NoteCellHeaderHandler, py::nodelete>(&NoteCellHeaderHandler::GetInstance()); });
    c1.def_static("GetInstance", &NoteCellHeaderHandler::GetInstance, py::return_value_policy::reference);
    }