/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnPlatform\source\groupedholehandler.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <DgnPlatform/GroupedHoleHandler.h>



static const char * __doc_Bentley_DgnPlatform_GroupedHoleHandler_CreateGroupedHoleElement =R"doc(Create a new grouped hole cell from the supplied solid element and
collection of hole elements. Only closed curves are acceptable for the
solid and hole loops.

:param eeh:
    The new element.

:param solidEeh:
    Element to use for solid loop.

:param holes:
    Elements to use for hole loops, requires a minimum of one.

:returns:
    SUCCESS if a valid element is created and range was sucessfully
    calculated. @note solidEeh and hole agenda entries will be invalid
    after this call unless they represent persistent elements.

See also:
    IsValidGroupedHoleComponentType Bentley Systems +---------------+-
    --------------+---------------+---------------+---------------+---
    ---)doc";

static const char * __doc_Bentley_DgnPlatform_GroupedHoleHandler_IsValidGroupedHoleComponentType =R"doc(Check the supplied element to determine if it is an acceptable type
for inclusion in a grouped hole, either as a solid or hole loop. Valid
components are closed curves of the following types: SHAPE_ELM 
CMPLX_SHAPE_ELM  ELLIPSE_ELM  BSPLINE_CURVE_ELM <p>

:param eh:
    The element to check.

:returns:
    true if element is valid candidate. Bentley Systems +-------------
    --+---------------+---------------+---------------+---------------
    +------)doc";

static const char * __doc_Bentley_DgnPlatform_GroupedHoleHandler_IsGroupedHole =R"doc(Check the supplied element to see if it represents a grouped hole.

:param eh:
    The element to check.

:returns:
    true if element is a grouped hole.

See also:
    IPlanarRegionQuery::HasHoles Bentley Systems +---------------+----
    -----------+---------------+---------------+---------------+------)doc";

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_GroupedHoleHandler(py::module_& m)
    {
    //===================================================================================
    // struct GroupedHoleHandler
    py::class_< GroupedHoleHandler
        , std::unique_ptr< GroupedHoleHandler, py::nodelete>
        , Type2Handler
        , ICurvePathEdit
        , IAreaFillPropertiesEdit
    > c1(m, "GroupedHoleHandler");

    c1.def_static("IsGroupedHole", &GroupedHoleHandler::IsGroupedHole, "eh"_a, DOC(Bentley, DgnPlatform, GroupedHoleHandler, IsGroupedHole));
    c1.def_static("IsValidGroupedHoleComponentType", &GroupedHoleHandler::IsValidGroupedHoleComponentType, "eh"_a, DOC(Bentley, DgnPlatform, GroupedHoleHandler, IsValidGroupedHoleComponentType));
    c1.def_static("CreateGroupedHoleElement", &GroupedHoleHandler::CreateGroupedHoleElement, "eeh"_a, "solidEeh"_a, "holes"_a, DOC(Bentley, DgnPlatform, GroupedHoleHandler, CreateGroupedHoleElement));

    c1.def_property_readonly_static("Instance", [] (py::object const&) { return std::unique_ptr<GroupedHoleHandler, py::nodelete>(&GroupedHoleHandler::GetInstance()); });
    c1.def_static("GetInstance", &GroupedHoleHandler::GetInstance, py::return_value_policy::reference);
    }