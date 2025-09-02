/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnPlatform\source\bsplinecurvehandler.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <DgnPlatform/BSplineCurveHandler.h>



static const char * __doc_Bentley_DgnPlatform_BSplineCurveHandler_IsValidInterpolationCurve =R"doc(Quick verification that the input MSInterpolationCurve has all the
required information.

:param curve:
    The curve to check.

:returns:
    true if input curve appears valid. Bentley Systems +--------------
    -+---------------+---------------+---------------+---------------+
    ------)doc";

static const char * __doc_Bentley_DgnPlatform_BSplineCurveHandler_IsValidCurve =R"doc(Quick verification that the input MSBSplineCurve has all the required
information.

:param curve:
    The curve to check.

:returns:
    true if input curve appears valid. Bentley Systems +--------------
    -+---------------+---------------+---------------+---------------+
    ------)doc";

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_BSplineCurveHandler(py::module_& m)
    {
    //===================================================================================
    // struct BSplineCurveHandler
    py::class_<
        BSplineCurveHandler,        
        ComplexHeaderDisplayHandler,
        ICurvePathEdit,
        IAreaFillPropertiesEdit> c1(m, "BSplineCurveHandler");

    c1.def_static("IsValidCurve", &BSplineCurveHandler::IsValidCurve, "curve"_a, DOC(Bentley, DgnPlatform, BSplineCurveHandler, IsValidCurve));

    c1.def_static("CreateBSplineCurveElement", 
                  py::overload_cast<EditElementHandleR, ElementHandleCP, MSBsplineCurveCR, bool, DgnModelRefR>(&BSplineCurveHandler::CreateBSplineCurveElement),
                  "eeh"_a, "templateEh"_a, "curve"_a, "is3d"_a, "modelRef"_a);

    c1.def_static("IsValidInterpolationCurve", &BSplineCurveHandler::IsValidInterpolationCurve, "curve"_a, DOC(Bentley, DgnPlatform, BSplineCurveHandler, IsValidInterpolationCurve));

    c1.def_static("CreateBSplineCurveElement",
                  py::overload_cast<EditElementHandleR, ElementHandleCP, MSInterpolationCurveCR, bool, DgnModelRefR>(&BSplineCurveHandler::CreateBSplineCurveElement),
                  "eeh"_a, "templateEh"_a, "curve"_a, "is3d"_a, "modelRef"_a);

    c1.def_property_readonly_static("Instance", [] (py::object const&) { return std::unique_ptr<BSplineCurveHandler, py::nodelete>(&BSplineCurveHandler::GetInstance()); });
    c1.def_static("GetInstance", &BSplineCurveHandler::GetInstance, py::return_value_policy::reference);
    }