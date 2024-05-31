/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyBentleyGeom\source\graphicspoint.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"



static const char * __doc_Bentley_Geom_GraphicsPoint_Zero =R"doc(Set entire point to zeros.)doc";

static const char * __doc_Bentley_Geom_GraphicsPoint_GetNormalized =R"doc( normalize the (homogenous) point into caller's point.

Parameter ``[out]``:
    xyz receives coordinates

Returns:
    false if weight is zero. (xyz still copied))doc";

static const char * __doc_Bentley_Geom_GraphicsPoint_SetLoopBreak =R"doc(set or clear the flag identifying this point as a loop break. (aka
" Major " break))doc";

static const char * __doc_Bentley_Geom_GraphicsPoint_IsLoopBreak =R"doc(Ask if this point is the end of a looop.)doc";

static const char * __doc_Bentley_Geom_GraphicsPoint_SetCurveBreak =R"doc(Set or clear the flag identifying this point as the end of a
linestring or other extended curve. (aka " minor " break))doc";

static const char * __doc_Bentley_Geom_GraphicsPoint_IsCurveBreak =R"doc(Ask if this point is a curve break.)doc";

static const char * __doc_Bentley_Geom_GraphicsPoint_CheckCurveAndPointType =R"doc(Test)doc";

static const char * __doc_Bentley_Geom_GraphicsPoint_GetPointType =R"doc(Query the point type for this point.)doc";

static const char * __doc_Bentley_Geom_GraphicsPoint_GetCurveType =R"doc(Query the curve type this point is part of.)doc";

static const char * __doc_Bentley_Geom_GraphicsPoint_SetOrder =R"doc(Set mask bits for curve order. Only valid for points within a bspline.)doc";

static const char * __doc_Bentley_Geom_GraphicsPoint_GetOrder =R"doc(Query the order of the curve this point is part of. Only valid for
points within a bspline.)doc";

static const char * __doc_Bentley_Geom_GraphicsPoint_SetPointPreserveWeight =R"doc( Set point, but DIVIDE xyz part by weight. (i.e. caller
has been carrying point as wx,wy,wz,w)

Parameter ``[in]``:
    inputPoint coordinates in wx,wy,wz form.)doc";

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_GraphicsPoint(py::module_& m)
    {
    //===================================================================================
    // struct GraphicsPoint
    py::class_< GraphicsPoint> c1(m, "GraphicsPoint");
    py::bind_vector<GraphicsPointVec>(m, "GraphicsPointVec", py::module_local(false));

    c1.def_readwrite("point", &GraphicsPoint::point);
    c1.def_readwrite("a", &GraphicsPoint::a);
    c1.def_readwrite("mask", &GraphicsPoint::mask);
    c1.def_readwrite("userData", &GraphicsPoint::userData);
    c1.def_readwrite("b", &GraphicsPoint::b);
    c1.def_readwrite("index", &GraphicsPoint::index);

    c1.def(py::init<>());

    c1.def(py::init<DPoint4dCR, double, int, int, double, size_t>(),
           "point"_a, "a"_a = 0.0, "userData"_a = 0, "mask"_a = 0, "b"_a = 0.0, "index"_a = 0);

    c1.def(py::init<DPoint3dCR, double, double, int, int, double, size_t>(),
           "point"_a, "w"_a = 1.0, "a"_a = 0.0, "userData"_a = 0, "mask"_a = 0, "b"_a = 0.0, "index"_a = 0);

    c1.def(py::init<double, double, double, double, double, int, int, double, size_t>(),
           "x"_a, "y"_a, "z"_a = 0.0, "w"_a = 1.0, "a"_a = 0.0, "userData"_a = 0, "mask"_a = 0, "b"_a = 0.0, "index"_a = 0);

    c1.def("SetPointPreserveWeight", &GraphicsPoint::SetPointPreserveWeight, "inputPoint"_a, DOC(Bentley, Geom, GraphicsPoint, SetPointPreserveWeight));

    c1.def_property("Order", &GraphicsPoint::GetOrder, &GraphicsPoint::SetOrder);
    c1.def("GetOrder", &GraphicsPoint::GetOrder, DOC(Bentley, Geom, GraphicsPoint, GetOrder));
    c1.def("SetOrder", &GraphicsPoint::SetOrder, "order"_a, DOC(Bentley, Geom, GraphicsPoint, SetOrder));

    c1.def_property_readonly("CurveType", &GraphicsPoint::GetCurveType);
    c1.def("GetCurveType", &GraphicsPoint::GetCurveType, DOC(Bentley, Geom, GraphicsPoint, GetCurveType));

    c1.def_property_readonly("PointType", &GraphicsPoint::GetPointType);
    c1.def("GetPointType", &GraphicsPoint::GetPointType, DOC(Bentley, Geom, GraphicsPoint, GetPointType));

    c1.def("CheckCurveAndPointType", &GraphicsPoint::CheckCurveAndPointType, "curveType"_a, "pointType"_a, DOC(Bentley, Geom, GraphicsPoint, CheckCurveAndPointType));

    c1.def_property("CurveBreak", &GraphicsPoint::IsCurveBreak, &GraphicsPoint::SetCurveBreak);
    c1.def("IsCurveBreak", &GraphicsPoint::IsCurveBreak, DOC(Bentley, Geom, GraphicsPoint, IsCurveBreak));
    c1.def("SetCurveBreak", &GraphicsPoint::SetCurveBreak, "value"_a = true, DOC(Bentley, Geom, GraphicsPoint, SetCurveBreak));

    c1.def_property("LoopBreak", &GraphicsPoint::IsLoopBreak, &GraphicsPoint::SetLoopBreak);
    c1.def("IsLoopBreak", &GraphicsPoint::IsLoopBreak, DOC(Bentley, Geom, GraphicsPoint, IsLoopBreak));
    c1.def("SetLoopBreak", &GraphicsPoint::SetLoopBreak, "value"_a = true, DOC(Bentley, Geom, GraphicsPoint, SetLoopBreak));

    c1.def("GetNormalized", &GraphicsPoint::GetNormalized, "xyz"_a, DOC(Bentley, Geom, GraphicsPoint, GetNormalized));
    c1.def("Zero", &GraphicsPoint::Zero, DOC(Bentley, Geom, GraphicsPoint, Zero));

    c1.def("__repr__", [] (GraphicsPoint& self)
           {
           return "(point:{}, a:{}, userData:{}, order:{}, curveType:{}, pointType:{}, isCurveBreak:{}, isLoopBreak:{}"_s
               .format(self.point, self.a, self.userData, self.GetOrder(), self.GetCurveType(), self.GetPointType(), self.IsCurveBreak(), self.IsLoopBreak());
           });

    c1.def("__copy__", [](const GraphicsPoint& self)
        {
        return GraphicsPoint(self);
        });
    }