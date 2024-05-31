/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyBentleyGeom\source\dbilinearpatch3d.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <Geom/DBilinearPatch3d.h>



static const char * __doc_Bentley_Geom_DBilinearPatch3d_IsPlanar =R"doc(Test if the patch is planar, with usual system angle tolerances
(tight))doc";

static const char * __doc_Bentley_Geom_DBilinearPatch3d_IsParallelogram =R"doc(Test if the patch is just a parallelogram)doc";

static const char * __doc_Bentley_Geom_DBilinearPatch3d_GetVEdgeVector =R"doc(return vector along v edge (left, right)

Parameter ``[in]``:
    i 0,1 for left, right edge.)doc";

static const char * __doc_Bentley_Geom_DBilinearPatch3d_GetDiagonalFrom01 =R"doc(return diagonal vector starting at 01)doc";

static const char * __doc_Bentley_Geom_DBilinearPatch3d_GetDiagonalFrom00 =R"doc(return diagonal vector starting at 00)doc";

static const char * __doc_Bentley_Geom_DBilinearPatch3d_GetUEdgeVector =R"doc(return vector along u edge (lower or upper)

Parameter ``[in]``:
    i 0,1 for lower, upper edge.)doc";

static const char * __doc_Bentley_Geom_DBilinearPatch3d_GetCCWEdge =R"doc(Return specified edge as a line segment. Edge order is:bottom, right,
top, left with CCW loop direction.)doc";

static const char * __doc_Bentley_Geom_DBilinearPatch3d_PerpendicularsOnBoundedPatch =R"doc(return uv coordinates of projections of xyz onto the (bounded) patch.
This returns only true perpendicular projections (i.e. does not give
" close but nonperpendicular point on edge "))doc";

static const char * __doc_Bentley_Geom_DBilinearPatch3d_EvaluateNormal =R"doc(Return surface coordinates and unit normal at u,v parameters)doc";

static const char * __doc_Bentley_Geom_DBilinearPatch3d_Evaluate =R"doc(Return surface coordinates at u,v parameters)doc";

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_DBilinearPatch3d(py::module_& m)
    {
    //===================================================================================
    // struct DBilinearPatch3d
    py::class_< DBilinearPatch3d> c1(m, "DBilinearPatch3d");

    c1.def(py::init<>());
    c1.def(py::init<DPoint3dCR, DPoint3dCR, DPoint3dCR, DPoint3dCR>(), "xyz0"_a, "xyz10"_a, "xyz01"_a, "xyz11"_a);
    c1.def(py::init<DPoint2dCR, DPoint2dCR, DPoint2dCR, DPoint2dCR>(), "xyz0"_a, "xyz10"_a, "xyz01"_a, "xyz11"_a);
    c1.def(py::init<DSegment3dCR, DSegment3dCR>(), "lowerEdge"_a, "upperEdge"_a);

    c1.def("Evaluate", py::overload_cast<double, double>(&DBilinearPatch3d::Evaluate, py::const_), "u"_a, "v"_a, DOC(Bentley, Geom, DBilinearPatch3d, Evaluate));
    c1.def("Evaluate", py::overload_cast<double, double, DPoint3dR, DVec3dR, DVec3dR>(&DBilinearPatch3d::Evaluate, py::const_), "u"_a, "v"_a, "xyz"_a, "dXdu"_a, "dXdv"_a, DOC(Bentley, Geom, DBilinearPatch3d, Evaluate));        
    
    c1.def("EvaluateNormal", &DBilinearPatch3d::EvaluateNormal, "u"_a, "v"_a, "xyz"_a, "unitNormal"_a, DOC(Bentley, Geom, DBilinearPatch3d, EvaluateNormal));
    c1.def("EvaluateGrid", &DBilinearPatch3d::EvaluateGrid, "numUPoint"_a, "numVPoint"_a, "gridPoints"_a);
    c1.def("PerpendicularsOnBoundedPatch", &DBilinearPatch3d::PerpendicularsOnBoundedPatch, "spacePoint"_a, "uv"_a, DOC(Bentley, Geom, DBilinearPatch3d, PerpendicularsOnBoundedPatch));
        
    c1.def("GetCCWEdge", &DBilinearPatch3d::GetCCWEdge, "i"_a, DOC(Bentley, Geom, DBilinearPatch3d, GetCCWEdge));
    c1.def("GetUEdgeVector", &DBilinearPatch3d::GetUEdgeVector, "i"_a, DOC(Bentley, Geom, DBilinearPatch3d, GetUEdgeVector));
    c1.def("GetDiagonalFrom00", &DBilinearPatch3d::GetDiagonalFrom00, DOC(Bentley, Geom, DBilinearPatch3d, GetDiagonalFrom00));
    c1.def("GetDiagonalFrom01", &DBilinearPatch3d::GetDiagonalFrom01, DOC(Bentley, Geom, DBilinearPatch3d, GetDiagonalFrom01));
    c1.def("GetVEdgeVector", &DBilinearPatch3d::GetVEdgeVector, "i"_a, DOC(Bentley, Geom, DBilinearPatch3d, GetVEdgeVector));

    c1.def("IsParallelogram", &DBilinearPatch3d::IsParallelogram, DOC(Bentley, Geom, DBilinearPatch3d, IsParallelogram));
    c1.def("IsPlanar", py::overload_cast<>(&DBilinearPatch3d::IsPlanar, py::const_), DOC(Bentley, Geom, DBilinearPatch3d, IsPlanar));
    c1.def("IsPlanar", py::overload_cast<double>(&DBilinearPatch3d::IsPlanar, py::const_), "angleTol"_a, DOC(Bentley, Geom, DBilinearPatch3d, IsPlanar));

    c1.def("__repr__", [] (DBilinearPatch3d& self)
           {
           return "(Point00:{}, Point01:{}, Point10:{}, Point11:{})"_s.format(self.point[0][0], self.point[0][1], self.point[1][0], self.point[1][1]);
           });

    c1.def("__copy__", [](const DBilinearPatch3d& self)
        {
        return DBilinearPatch3d(self);
        });
    }