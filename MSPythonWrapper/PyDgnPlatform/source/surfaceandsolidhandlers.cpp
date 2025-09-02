/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnPlatform\source\surfaceandsolidhandlers.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <DgnPlatform/SurfaceAndSolidHandlers.h>



static const char * __doc_Bentley_DgnPlatform_SurfaceOrSolidHandler_IsValidProfileType =R"doc(Check the supplied element to determine if it is an acceptable type
for use as a projection or revolution profile. Valid elements are open
curve, closed curves, and regions of the following types: LINE_ELM
 LINE_STRING_ELM  SHAPE_ELM  CURVE_ELM  CMPLX_STRING_ELM
 CMPLX_SHAPE_ELM  ELLIPSE_ELM  ARC_ELM  BSPLINE_CURVE_ELM
 CELL_HEADER_ELM that returns true from
GroupedHoleHandler::IsGroupedHole.  SURFACE_ELM when create method
is called to continue an existing surface.  SOLID_ELM when create
method is called to continue an existing solid. <p>

:param eh:
    The element to check.

:returns:
    true if element is valid candidate. Bentley Systems +-------------
    --+---------------+---------------+---------------+---------------
    +------)doc";

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_SurfaceAndSolidHandlers(py::module_& m)
    {
    //===================================================================================
    // struct SurfaceOrSolidHandler
    py::class_< SurfaceOrSolidHandler
        , std::unique_ptr< SurfaceOrSolidHandler, py::nodelete>
        , ComplexHeaderDisplayHandler
        , ISolidPrimitiveEdit> c1(m, "SurfaceOrSolidHandler");


    c1.def_static("IsValidProfileType", &SurfaceOrSolidHandler::IsValidProfileType, "eh"_a, DOC(Bentley, DgnPlatform, SurfaceOrSolidHandler, IsValidProfileType));

    c1.def_static("CreateProjectionElement",
                  py::overload_cast<EditElementHandleR, ElementHandleCP, ElementHandleCR, DPoint3dCR, DVec3dCR, TransformCP, bool, DgnModelRefR>(&SurfaceOrSolidHandler::CreateProjectionElement),
                  "eeh"_a, "templateEh"_a, "profileEh"_a, "origin"_a, "extrudeVector"_a, "transform"_a, "preferSolid"_a, "modelRef"_a);

    c1.def_static("CreateRevolutionElement",
                  &SurfaceOrSolidHandler::CreateRevolutionElement,
                  "eeh"_a, "templateEh"_a, "profileEh"_a, "center"_a, "axis"_a, "sweepAngle"_a, "preferSolid"_a, "modelRef"_a, "numProfileRules"_a = 1);

    c1.def_property_readonly_static("Instance", [] (py::object const&) { return std::unique_ptr< SurfaceOrSolidHandler, py::nodelete>(&SurfaceOrSolidHandler::GetInstance()); });
    c1.def_static("GetInstance", &SurfaceOrSolidHandler::GetInstance, py::return_value_policy::reference);

    //===================================================================================
    // struct SurfaceHandler
    py::class_< SurfaceHandler, std::unique_ptr<SurfaceHandler, py::nodelete>, SurfaceOrSolidHandler> c2(m, "SurfaceHandler");

    c2.def_property_readonly_static("Instance", [] (py::object const&) { return std::unique_ptr< SurfaceHandler, py::nodelete>(&SurfaceHandler::GetInstance()); });
    c2.def_static("GetInstance", &SurfaceHandler::GetInstance, py::return_value_policy::reference);

    //===================================================================================
    // struct SolidHandler
    py::class_< SolidHandler, std::unique_ptr<SolidHandler, py::nodelete>, SurfaceOrSolidHandler> c3(m, "SolidHandler");

    c3.def_property_readonly_static("Instance", [] (py::object const&) { return std::unique_ptr< SolidHandler, py::nodelete>(&SolidHandler::GetInstance()); });
    c3.def_static("GetInstance", &SolidHandler::GetInstance, py::return_value_policy::reference);
    }