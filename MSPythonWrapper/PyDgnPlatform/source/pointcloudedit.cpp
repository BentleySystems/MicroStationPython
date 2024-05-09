/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnPlatform\source\pointcloudedit.cpp $
|
|  $Copyright: (c) 2024 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <PointCloud/PointCloud.h>
#include <PointCloud/PointCloudEdit.h>

USING_NAMESPACE_BENTLEY_POINTCLOUD

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2024
+---------------+---------------+---------------+---------------+---------------+------*/
void def_PointCloudEdit(py::module_& m)
    {
    //===================================================================================
    // struct PointCloudSelectPoints : RefCountedBase
    py::class_< PointCloudSelectPoints, PointCloudSelectPointsPtr> c1(m, "PointCloudSelectPoints");

    if (true)
        {
        //===============================================================================
        // Enum PointCloudSelectPoints::DENSITYMODE
        py::enum_<PointCloudSelectPoints::DENSITYMODE>(c1, "DENSITYMODE", py::arithmetic())
            .value("eFullDensity", PointCloudSelectPoints::FullDensity)
            .value("eLoadedDensity", PointCloudSelectPoints::LoadedDensity)
            .export_values();

        //===============================================================================
        // Enum PointCloudSelectPoints::SELECTMODE
        py::enum_<PointCloudSelectPoints::SELECTMODE>(c1, "SELECTMODE", py::arithmetic())
            .value("eSelect", PointCloudSelectPoints::Select)
            .value("eUnSelect", PointCloudSelectPoints::UnSelect)
            .export_values();
        }

    c1.def_static("Create", py::overload_cast<ElementHandleCR>(&PointCloudSelectPoints::Create), "eh"_a, py::return_value_policy::reference);
    c1.def_static("SetDrawColor", &PointCloudSelectPoints::SetDrawColor, "color"_a);
    c1.def("BySphere", &PointCloudSelectPoints::BySphere, "centre"_a, "radius"_a);
    c1.def("ByOrientedBox", &PointCloudSelectPoints::ByOrientedBox, "box"_a);
    c1.def("ByPlane", &PointCloudSelectPoints::ByPlane, "pointOnPlane"_a, "normal"_a, "thickness"_a);
    c1.def("ByBlockInView", &PointCloudSelectPoints::ByBlockInView, "origin"_a, "corner"_a, "viewport"_a);
    c1.def("ByPolygonInView", &PointCloudSelectPoints::ByPolygonInView, "polygon"_a, "viewport"_a);
    c1.def("ByPrism", &PointCloudSelectPoints::ByPrism, "polygon"_a, "thickness"_a);
    c1.def("MoveSelectedToLayer", &PointCloudSelectPoints::MoveSelectedToLayer, "layerID"_a);
    c1.def("SetSelectMode", &PointCloudSelectPoints::SetSelectMode, "mode"_a);
    c1.def("SetDensityMode", &PointCloudSelectPoints::SetDensityMode, "mode"_a);
    c1.def("UnselectAll", &PointCloudSelectPoints::UnselectAll);
    c1.def("InvertSelection", &PointCloudSelectPoints::InvertSelection);
    }