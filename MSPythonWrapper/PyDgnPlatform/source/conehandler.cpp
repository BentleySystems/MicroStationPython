/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnPlatform\source\conehandler.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <DgnPlatform/ComplexHeaderHandler.h>
#include <DgnPlatform/ConeHandler.h>



static const char * __doc_Bentley_DgnPlatform_ConeHandler_CreateConeElement =R"doc(Create a new CONE_ELM with the supplied parameters.

:param eeh:
    The new element.

:param templateEh:
    Template element to use for symbology; if NULL defaults are used.

:param topRadius:
    cone top radius

:param bottomRadius:
    cone base radius

:param topCenter:
    center point of top

:param bottomCenter:
    center point of base

:param rotation:
    specifies the skew rotation to apply to top/base circles.

:param isCapped:
    true for solid cone.

:param modelRef:
    Model to associate this element with. Required to compute range.

:returns:
    SUCCESS if a valid element is created and range was sucessfully
    calculated. Bentley Systems +--------------+--------------+-------
    --------+----------------+-------------)doc";

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_ConeHander(py::module_& m)
    {
    //===================================================================================
    // struct ConeHandler
    py::class_<ConeHandler, DisplayHandler, ISolidPrimitiveEdit> c1(m, "ConeHandler");


    c1.def_static("CreateConeElement", 
                  &ConeHandler::CreateConeElement, 
                  "eeh"_a, "templateEh"_a, "topRadius"_a, "bottomRadius"_a, "topCenter"_a, "bottomCenter"_a, "rotation"_a, "isCapped"_a, "modelRef"_a, DOC(Bentley, DgnPlatform, ConeHandler, CreateConeElement)); 

    c1.def_property_readonly_static("Instance", [] (py::object const&) { return std::unique_ptr<ConeHandler, py::nodelete>(&ConeHandler::GetInstance()); });
    c1.def_static("GetInstance", &ConeHandler::GetInstance, py::return_value_policy::reference);
    }