/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnPlatform\source\pointcloudhandler.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <DgnPlatform/PointCloudHandler.h>



static const char * __doc_Bentley_DgnPlatform_PointCloudHandler_GetPointCloudElementRefsInModel =R"doc(Get the set of point cloud elements in the model.

Parameter ``modelR``:
    Model for which the point clouds set is requested.

Returns:
    A set of point cloud elementRef. Bentley Systems +---------------+
    ---------------+---------------+---------------+---------------+--
    ----)doc";

static const char * __doc_Bentley_DgnPlatform_PointCloudHandler_CreatePointCloudElement =R"doc(Create a new point cloud element using the supplied parameters.

Parameter ``eeh``:
    The new element.

Parameter ``modelRef``:
    Model to associate this element with. Required to compute range.

Parameter ``pointCloudProperties``:
    Properties to assign to the new point cloud element. Use
    PointCloudProperties::Create to create these properties.

Parameter ``range``:
    Range of the element to create. It's important to set the actual
    range of the point cloud element to create because this method
    does not open the point cloud file and thus does not read the
    range from the file.

Returns:
    SUCCESS or ERROR if the range of the element can't be validated.

Bentley Systems +---------------+---------------+---------------+-----
----------+---------------+------)doc";

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_PointCloudHandler(py::module_& m)
    {
    //===================================================================================
    // struct PointCloudCollection

    //===================================================================================
    // struct PointCloudHandler
    py::class_< PointCloudHandler
        , std::unique_ptr< PointCloudHandler, py::nodelete>
        , DisplayHandler
        , ITransactionHandler
        , IPointCloudEdit> c2(m, "PointCloudHandler");

    c2.def_static("CreatePointCloudElement", &PointCloudHandler::CreatePointCloudElement, "eeh"_a, "modelRef"_a, "pointCloudProperties"_a, "range"_a, DOC(Bentley, DgnPlatform, PointCloudHandler, CreatePointCloudElement));
    c2.def_static("GetPointCloudElementRefsInModel", &PointCloudHandler::GetPointCloudElementRefsInModel, "dgnModel"_a, DOC(Bentley, DgnPlatform, PointCloudHandler, GetPointCloudElementRefsInModel));
    c2.def_property_readonly_static("Instance", [] (py::object const&) { return std::unique_ptr< PointCloudHandler, py::nodelete>(&PointCloudHandler::GetInstance()); });
    c2.def_static("GetInstance", &PointCloudHandler::GetInstance, py::return_value_policy::reference);
    }