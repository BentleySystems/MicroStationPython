/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnPlatform\source\displaypath.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <DgnPlatform/DisplayPath.h>
#include <DgnView/IViewManager.h>



static const char * __doc_Bentley_DgnPlatform_DisplayPath_SetCursorIndex =R"doc(Set the cursor index for this path.)doc";

static const char * __doc_Bentley_DgnPlatform_DisplayPath_PopPathElem =R"doc(Remove the element from the end of a path. The cursor index will
adjusted if necessary.)doc";

static const char * __doc_Bentley_DgnPlatform_DisplayPath_PushPathElem =R"doc(Add an ElementRefP to the end of a path being constructed. The cursor
index will be set to this ElementRefP.)doc";

static const char * __doc_Bentley_DgnPlatform_DisplayPath_SetRoot =R"doc(Set the root DgnModelRefP for a path being constructed.)doc";

static const char * __doc_Bentley_DgnPlatform_DisplayPath_GetSharedChildElem =R"doc(Return the ElementRefP of the innermost public component of a shared
cell definition element for the given expose reason. Use this method
to get the ElementRefP of the element Handler that owns/manages the
entry referenced by this path. @note If the path is not to a shared
cell definition component this method is the same as GetChildElem.

Remark:
    s For legacy complex types that wish to be treated as a single
    entity (ex. Type 18/19, SmartSolids), this method will return
    their header, not one of their components. Helpful when needing to
    work with components of shared and normal cells where GetHeadElem
    can not be used.)doc";

static const char * __doc_Bentley_DgnPlatform_DisplayPath_GetChildElem =R"doc(Return the ElementRefP of the innermost public component of a complex
element for the given expose reason. Use this method to get the
ElementRefP of the element Handler that owns/manages the entry
referenced by this path. @note If the path is not to a complex
component this method is the same as GetHeadElem.

Remark:
    s For legacy complex types that wish to be treated as a single
    entity (ex. Type 18/19, SmartSolids), this method will return
    their header, not one of their components. Helpful when needing to
    work with components of normal cells where GetHeadElem can not be
    used.)doc";

static const char * __doc_Bentley_DgnPlatform_DisplayPath_GetComponentElem =R"doc(Return the ElementRefP of the innermost component of a complex
element. This method, unlike GetTailElem, stops at a shared cell
instance and won't return a shared cell definition component. @note If
the path is not to a complex component this method is the same as
GetHeadElem.

Remark:
    s Provided to help migrate applications that use to work with a
    component file position.

See also:
    DisplayPath::GetChildElem)doc";

static const char * __doc_Bentley_DgnPlatform_DisplayPath_GetCursorElem =R"doc(Return the ElementRefP at the cursor index.

See also:
    DisplayPath::GetChildElem)doc";

static const char * __doc_Bentley_DgnPlatform_DisplayPath_GetTailElem =R"doc(Return the ElementRefP at the end of the path (i.e. innermost
component of complex element/shared cell defintion) @note Same as
GetPathElem (-1).

See also:
    DisplayPath::GetChildElem)doc";

static const char * __doc_Bentley_DgnPlatform_DisplayPath_GetHeadElem =R"doc(Return the ElementRefP at the head of the path (i.e. outermost header
for a complex element). @note Same as GetPathElem (0).)doc";

static const char * __doc_Bentley_DgnPlatform_DisplayPath_GetPathElem =R"doc(Return the ElementRefP at the supplied path index. -1 will return the
ElementRefP at end of the path.

See also:
    DisplayPath::GetChildElem)doc";

static const char * __doc_Bentley_DgnPlatform_DisplayPath_GetCount =R"doc(Return the number of entries in this path.)doc";

static const char * __doc_Bentley_DgnPlatform_DisplayPath_GetRoot =R"doc(Return the root DgnModelRefP for this path.)doc";

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_DisplayPath(py::module_& m)
    {
    //===================================================================================
    // struct DisplayPath
    py::class_< DisplayPath, DisplayPathPtr> c1(m, "DisplayPath");


    c1.def(py::init(&DisplayPath::Create));
    
    c1.def_property_readonly("Root", &DisplayPath::GetRoot);
    c1.def("GetRoot", &DisplayPath::GetRoot, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, DisplayPath, GetRoot));
    
    c1.def_property_readonly("Count", &DisplayPath::GetCount);
    c1.def("GetCount", &DisplayPath::GetCount, DOC(Bentley, DgnPlatform, DisplayPath, GetCount));
    c1.def("__len__", &DisplayPath::GetCount);
    
    c1.def("GetPathElem", &DisplayPath::GetPathElem, "index"_a, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, DisplayPath, GetPathElem));
    
    c1.def_property_readonly("HeadElem", &DisplayPath::GetHeadElem);
    c1.def("GetHeadElem", &DisplayPath::GetHeadElem, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, DisplayPath, GetHeadElem));
    
    c1.def_property_readonly("TailElem", &DisplayPath::GetTailElem);
    c1.def("GetTailElem", &DisplayPath::GetTailElem, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, DisplayPath, GetTailElem));
    
    c1.def_property_readonly("CursorElem", &DisplayPath::GetCursorElem);
    c1.def("GetCursorElem", &DisplayPath::GetCursorElem, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, DisplayPath, GetCursorElem));
    
    c1.def_property_readonly("ComponentElem", &DisplayPath::GetComponentElem);
    c1.def("GetComponentElem", &DisplayPath::GetComponentElem, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, DisplayPath, GetComponentElem));
    
    c1.def("GetChildElem", &DisplayPath::GetChildElem, "reason"_a = ExposeChildrenReason::Query, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, DisplayPath, GetChildElem));
    c1.def("GetSharedChildElem", &DisplayPath::GetSharedChildElem, "reason"_a = ExposeChildrenReason::Query, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, DisplayPath, GetSharedChildElem));
    c1.def("SetRoot", &DisplayPath::SetRoot, "modelRef"_a, py::keep_alive<1, 2>(), DOC(Bentley, DgnPlatform, DisplayPath, SetRoot));
    c1.def("PushPathElem", &DisplayPath::PushPathElem, "elRef"_a, py::keep_alive<1, 2>(), DOC(Bentley, DgnPlatform, DisplayPath, PushPathElem));
    c1.def("PopPathElem", &DisplayPath::PopPathElem, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, DisplayPath, PopPathElem));
    c1.def("SetCursorIndex", &DisplayPath::SetCursorIndex, "index"_a, DOC(Bentley, DgnPlatform, DisplayPath, SetCursorIndex));
    }