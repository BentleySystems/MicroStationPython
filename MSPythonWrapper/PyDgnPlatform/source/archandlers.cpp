/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnPlatform\source\archandlers.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <DgnPlatform/ArcHandlers.h>



static const char * __doc_Bentley_DgnPlatform_ArcHandler_CreateArcElement =R"doc(Create a new ARC_ELM with the supplied parameters.

Parameter ``eeh``:
    The new element.

Parameter ``templateEh``:
    Template element to use for symbology; if NULL defaults are used.

Parameter ``center``:
    arc center

Parameter ``axis1``:
    size of the primary arc axis

Parameter ``axis2``:
    size of the secondary arc axis

Parameter ``rotation``:
    arc rotation

Parameter ``start``:
    arc starting angle in radians

Parameter ``sweep``:
    arc sweep angle in radians

Parameter ``is3d``:
    Initialize the 2d or 3d element structure, typically
    modelRef->Is3d ().

Parameter ``modelRef``:
    Model to associate this element with. Required to compute range.

Returns:
    SUCCESS if a valid element is created and range was sucessfully
    calculated. Instance)doc";

static const char * __doc_Bentley_DgnPlatform_EllipseHandler_CreateEllipseElement =R"doc(Create a new ELLIPSE_ELM with the supplied parameters.

Parameter ``eeh``:
    The new element.

Parameter ``templateEh``:
    Template element to use for symbology; if NULL defaults are used.

Parameter ``center``:
    ellipse center

Parameter ``axis1``:
    size of the primary ellipse axis

Parameter ``axis2``:
    size of the secondary ellipse axis

Parameter ``rotation``:
    ellipse rotation

Parameter ``is3d``:
    Initialize the 2d or 3d element structure, typically
    modelRef->Is3d ().

Parameter ``modelRef``:
    Model to associate this element with. Required to compute range.

Returns:
    SUCCESS if a valid element is created and range was sucessfully
    calculated.)doc";

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_ArcHandlers(py::module_& m)
    {
    //===================================================================================
    // struct EllipticArcBaseHandler
    py::class_<EllipticArcBaseHandler, DisplayHandler, ICurvePathEdit> c1(m, "EllipticArcBaseHandler");    

    //===================================================================================
    // struct EllipseHandler
    py::class_<EllipseHandler, EllipticArcBaseHandler, IAreaFillPropertiesEdit> c2(m, "EllipseHandler");

    c2.def_static("CreateEllipseElement",
                  py::overload_cast<EditElementHandleR, ElementHandleCP, DPoint3dCR, double, double, RotMatrixCR, bool, DgnModelRefR>(&EllipseHandler::CreateEllipseElement),
                  "eeh"_a, "templateEh"_a, "center"_a, "axis1"_a, "axis2"_a, "rotation"_a, "is3d"_a, "modelRef"_a, DOC(Bentley, DgnPlatform, EllipseHandler, CreateEllipseElement));

    c2.def_static("CreateEllipseElement",
                  py::overload_cast<EditElementHandleR, ElementHandleCP, DPoint3dCR, double, double, double, bool, DgnModelRefR>(&EllipseHandler::CreateEllipseElement),
                  "eeh"_a, "templateEh"_a, "center"_a, "axis1"_a, "axis2"_a, "rotation"_a, "is3d"_a, "modelRef"_a, DOC(Bentley, DgnPlatform, EllipseHandler, CreateEllipseElement));

    c2.def_static("CreateEllipseElement",
                  py::overload_cast<EditElementHandleR, ElementHandleCP, DEllipse3dCR, bool, DgnModelRefR>(&EllipseHandler::CreateEllipseElement),
                  "eeh"_a, "templateEh"_a, "ellipse"_a, "is3d"_a, "modelRef"_a, DOC(Bentley, DgnPlatform, EllipseHandler, CreateEllipseElement));

    c2.def_property_readonly_static("Instance", [] (py::object const&) { return std::unique_ptr<EllipseHandler, py::nodelete>(&EllipseHandler::GetInstance()); });
    c2.def_static("GetInstance", &EllipseHandler::GetInstance, py::return_value_policy::reference);

    //===================================================================================
    // struct ArcHandler
    py::class_<ArcHandler, EllipticArcBaseHandler> c3(m, "ArcHandler");

    c3.def_static("CreateArcElement",
                  py::overload_cast<EditElementHandleR, ElementHandleCP, DPoint3dCR, double, double, RotMatrixCR, double, double, bool, DgnModelRefR>(&ArcHandler::CreateArcElement),
                  "eeh"_a, "templateEh"_a, "center"_a, "axis1"_a, "axis2"_a, "rotation"_a, "start"_a, "sweep"_a, "is3d"_a, "modelRef"_a, DOC(Bentley, DgnPlatform, ArcHandler, CreateArcElement));

    c3.def_static("CreateArcElement",
                  py::overload_cast<EditElementHandleR, ElementHandleCP, DPoint3dCR, double, double, double, double, double, bool, DgnModelRefR>(&ArcHandler::CreateArcElement),
                  "eeh"_a, "templateEh"_a, "center"_a, "axis1"_a, "axis2"_a, "rotation"_a, "start"_a, "sweep"_a, "is3d"_a, "modelRef"_a, DOC(Bentley, DgnPlatform, ArcHandler, CreateArcElement));

    c3.def_static("CreateArcElement",
                  py::overload_cast<EditElementHandleR, ElementHandleCP, DEllipse3dCR, bool, DgnModelRefR>(&ArcHandler::CreateArcElement),
                  "eeh"_a, "templateEh"_a, "ellipse"_a, "is3d"_a, "modelRef"_a, DOC(Bentley, DgnPlatform, ArcHandler, CreateArcElement));

    c3.def_property_readonly_static("Instance", [] (py::object const&) { return std::unique_ptr<ArcHandler, py::nodelete>(&ArcHandler::GetInstance()); });
    c3.def_static("GetInstance", &ArcHandler::GetInstance, py::return_value_policy::reference);
    }