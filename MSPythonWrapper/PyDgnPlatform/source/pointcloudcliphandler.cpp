/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnPlatform\source\pointcloudcliphandler.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <DgnPlatform/PointCloudClipHandler.h>



static const char * __doc_Bentley_DgnPlatform_PointCloudClipProperties_ClearAllClip =R"doc(Delete all the clip masks and clip boundaries of a point cloud.

:returns:
    always SUCCESS)doc";

static const char * __doc_Bentley_DgnPlatform_PointCloudClipProperties_SetClipMaskList =R"doc(Set the list of clip masks of a point cloud.

:param props:
    PointCloudProperties of the point cloud for which the clip masks
    are set.

:param clipBoxList:
    List of clip masks to set on the point cloud.

:returns:
    always SUCCESS)doc";

static const char * __doc_Bentley_DgnPlatform_PointCloudClipProperties_GetClipMaskList =R"doc(Get the list of clip masks of a point cloud.

:param props:
    PointCloudProperties of the point cloud for which the clip masks
    are requested.

:param clipBoxList:
    List of clip masks of the point cloud.

:returns:
    always SUCCESS)doc";

static const char * __doc_Bentley_DgnPlatform_PointCloudClipProperties_ClearClipMask =R"doc(Delete all the clip masks of a point cloud.

:returns:
    always SUCCESS)doc";

static const char * __doc_Bentley_DgnPlatform_PointCloudClipProperties_ClearClipMaskPolygon =R"doc(Delete the polygon clip masks of a point cloud.

:returns:
    always SUCCESS)doc";

static const char * __doc_Bentley_DgnPlatform_PointCloudClipProperties_ClearClipBoundaryPolygon =R"doc(Delete the polygon clip boundaries of a point cloud.

:returns:
    always SUCCESS)doc";

static const char * __doc_Bentley_DgnPlatform_PointCloudClipProperties_GetClipBoundaryPolygon =R"doc(Get the polygon clip boundaries of a point cloud.

:param props:
    PointCloudProperties of the point cloud for which the clip
    boundary is requested.

:param clipPolygon:
    Clip boundary polygon

:returns:
    ERROR if there is no clip boundary polygon applied to the point
    cloud. SUCCESS otherwise.)doc";

static const char * __doc_Bentley_DgnPlatform_PointCloudClipProperties_SetClipBoundary =R"doc(Set the clip boundary of a point cloud after removing any existing
clip boundary.

:param props:
    PointCloudProperties of the point cloud for which the clip
    boundary is set.

:param clipBox:
    OrientedBox that defines the clip boundary.

:returns:
    always SUCCESS)doc";

static const char * __doc_Bentley_DgnPlatform_PointCloudClipProperties_ClearClipBoundary =R"doc(Delete all the clip boundaries of a point cloud.

:returns:
    always SUCCESS)doc";

static const char * __doc_Bentley_DgnPlatform_PointCloudClipProperties_GetClipBoundary =R"doc(Get the list of clip boundaries of a point cloud.

:param props:
    PointCloudProperties of the point cloud for which the clip
    boundary is requested.

:param clipBox:
    Clip boundary box

:returns:
    ERROR if there is no clip boundary box applied to the point cloud.
    SUCCESS otherwise.)doc";

static const char * __doc_Bentley_DgnPlatform_OrientedBox_GetOrigin =R"doc(Get the origin of this OrientedBox.

:returns:
    origin)doc";

static const char * __doc_Bentley_DgnPlatform_OrientedBox_GetZVec =R"doc(Get the Z vector of this OrientedBox.

:returns:
    Z vector)doc";

static const char * __doc_Bentley_DgnPlatform_OrientedBox_GetYVec =R"doc(Get the Y vector of this OrientedBox.

:returns:
    Y vector)doc";

static const char * __doc_Bentley_DgnPlatform_OrientedBox_GetXVec =R"doc(Get the X vector of this OrientedBox.

:returns:
    X vector)doc";

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_PointCloudClipHandler(py::module_& m)
    {
    //===================================================================================
    // struct OrientedBox
    py::class_< OrientedBox> c1(m, "OrientedBox");

    c1.def(py::init<>());
    c1.def(py::init<DVec3dR, DVec3dR, DVec3dR, DPoint3dR>(), "xVec"_a, "yVec"_a, "zVec"_a, "origin"_a);
    
    c1.def_property_readonly("XVec", &OrientedBox::GetXVec);
    c1.def("GetXVec", &OrientedBox::GetXVec, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, OrientedBox, GetXVec));
    
    c1.def_property_readonly("YVec", &OrientedBox::GetYVec);
    c1.def("GetYVec", &OrientedBox::GetYVec, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, OrientedBox, GetYVec));
    
    c1.def_property_readonly("ZVec", &OrientedBox::GetZVec);
    c1.def("GetZVec", &OrientedBox::GetZVec, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, OrientedBox, GetZVec));
    
    c1.def_property_readonly("Origin", &OrientedBox::GetOrigin);
    c1.def("GetOrigin", &OrientedBox::GetOrigin, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, OrientedBox, GetOrigin));
    //===================================================================================
    // struct PointCloudClipProperties
    py::class_< PointCloudClipProperties, PointCloudClipPropertiesPtr> c2(m, "PointCloudClipProperties");

    if (true)
        {
        //===================================================================================
        // enum ClipFormat
        }

    c2.def(py::init(py::overload_cast<>(&PointCloudClipProperties::Create)));    
    c2.def("GetClipBoundary", &PointCloudClipProperties::GetClipBoundary, "props"_a, "clipBox"_a, DOC(Bentley, DgnPlatform, PointCloudClipProperties, GetClipBoundary));    
    c2.def("ClearClipBoundary", &PointCloudClipProperties::ClearClipBoundary, DOC(Bentley, DgnPlatform, PointCloudClipProperties, ClearClipBoundary));
    
    c2.def("SetClipBoundary", 
           py::overload_cast<PointCloudPropertiesCR, OrientedBoxCR>(&PointCloudClipProperties::SetClipBoundary), 
           "props"_a, "clipBox"_a, DOC(Bentley, DgnPlatform, PointCloudClipProperties, SetClipBoundary));

    c2.def("SetClipBoundary", 
           py::overload_cast<PointCloudPropertiesCR, DPoint3dArray const&>(&PointCloudClipProperties::SetClipBoundary), 
           "props"_a, "polygon"_a, DOC(Bentley, DgnPlatform, PointCloudClipProperties, SetClipBoundary));

    c2.def("SetClipBoundary", [](PointCloudClipPropertiesR self, PointCloudPropertiesCR props, py::list const& polygon) 
           {
           CONVERT_PYLIST_TO_NEW_CPPARRAY(polygon, cppPolygon, DPoint3dArray, DPoint3d);
           return self.SetClipBoundary(props, cppPolygon);
           }, "props"_a, "polygon"_a, DOC(Bentley, DgnPlatform, PointCloudClipProperties, SetClipBoundary));     

    c2.def("GetClipBoundaryPolygon", &PointCloudClipProperties::GetClipBoundaryPolygon, "props"_a, "clipPolygon"_a, DOC(Bentley, DgnPlatform, PointCloudClipProperties, GetClipBoundaryPolygon));
    c2.def("ClearClipBoundaryPolygon", &PointCloudClipProperties::ClearClipBoundaryPolygon, DOC(Bentley, DgnPlatform, PointCloudClipProperties, ClearClipBoundaryPolygon));
    c2.def("ClearClipMaskPolygon", &PointCloudClipProperties::ClearClipMaskPolygon, DOC(Bentley, DgnPlatform, PointCloudClipProperties, ClearClipMaskPolygon));
    c2.def("ClearClipMask", &PointCloudClipProperties::ClearClipMask, DOC(Bentley, DgnPlatform, PointCloudClipProperties, ClearClipMask));

    c2.def("GetClipMaskList",
           py::overload_cast<PointCloudPropertiesCR, OrientedBoxListR>(&PointCloudClipProperties::GetClipMaskList, py::const_), 
           "props"_a, "clipBoxList"_a, DOC(Bentley, DgnPlatform, PointCloudClipProperties, GetClipMaskList));

    c2.def("GetClipMaskList", 
           py::overload_cast<PointCloudPropertiesCR, DPoint3dVecArray&>(&PointCloudClipProperties::GetClipMaskList, py::const_), 
           "props"_a, "clipPolygonList"_a, DOC(Bentley, DgnPlatform, PointCloudClipProperties, GetClipMaskList));

    c2.def("GetClipMaskList", [](PointCloudClipPropertiesCR self, PointCloudPropertiesCR props, py::list& clipPolygonList){
        CONVERT_PYLIST_TO_NEW_CPPARRAY(clipPolygonList, cppClipPolygonList, DPoint3dVecArray, DPoint3dArray);
        auto result = self.GetClipMaskList(props, cppClipPolygonList);
        CONVERT_CPPARRAY_TO_PYLIST(clipPolygonList, cppClipPolygonList, DPoint3dVecArray, DPoint3dArray);
        return result;
    }, "props"_a, "clipPolygonList"_a, DOC(Bentley, DgnPlatform, PointCloudClipProperties, GetClipMaskList));

    c2.def("SetClipMaskList", 
           py::overload_cast<PointCloudPropertiesCR, OrientedBoxListCR>(&PointCloudClipProperties::SetClipMaskList),
           "props"_a, "clipBoxList"_a, DOC(Bentley, DgnPlatform, PointCloudClipProperties, SetClipMaskList));

    c2.def("SetClipMaskList",
           py::overload_cast<PointCloudPropertiesCR, DPoint3dVecArray const&>(&PointCloudClipProperties::SetClipMaskList), 
           "props"_a, "clipPolygonList"_a, DOC(Bentley, DgnPlatform, PointCloudClipProperties, SetClipMaskList));

    c2.def("SetClipMaskList", [](PointCloudClipPropertiesR self, PointCloudPropertiesCR props, py::list const& clipPolygonList){
        CONVERT_PYLIST_TO_NEW_CPPARRAY(clipPolygonList, cppClipPolygonList, DPoint3dVecArray, DPoint3dArray);
        self.SetClipMaskList(props, cppClipPolygonList);
    }, "props"_a, "clipPolygonList"_a, DOC(Bentley, DgnPlatform, PointCloudClipProperties, SetClipMaskList));

    c2.def("ClearAllClip", &PointCloudClipProperties::ClearAllClip, DOC(Bentley, DgnPlatform, PointCloudClipProperties, ClearAllClip));

    }
