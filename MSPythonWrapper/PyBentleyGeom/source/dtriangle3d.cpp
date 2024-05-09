/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyBentleyGeom\source\dtriangle3d.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <Geom/DTriangle3d.h>



static const char * __doc_Bentley_Geom_DPlane3dByVectors_ProjectPoint =R"doc(Returns:
    u,v coordinates of the projection. This is marked valid in the
    usual case of independent (nonzero, non-parallel) plane vectors.

Remark:
    if the plane vectors are parallel, the returned parameters do a
    projection to the longer vector, and are marked invalid

Remark:
    if the plane vectors are both zero, the returned parameters are
    zero and are marked invalid.)doc";

static const char * __doc_Bentley_Geom_DPlane3dByVectors_MaxDiff =R"doc(return max difference between corresponding components)doc";

static const char * __doc_Bentley_Geom_DPlane3dByVectors_TransverseIntersection =R"doc(Compute the simple intersection of a segment with the plane. Returns
false in any parallel case (both in-plane and off-plane))doc";

static const char * __doc_Bentley_Geom_DPlane3dByVectors_GetTransformsUnitZ =R"doc(Return coordinate transforms, with unit perpendicular as Z vector in
local to world.)doc";

static const char * __doc_Bentley_Geom_DPlane3dByVectors_EvaluateTangents =R"doc(Evaluate point and tangents at u,v. (Of course, the tangents are just
the originals))doc";

static const char * __doc_Bentley_Geom_DPlane3dByVectors_EvaluateVectorOnly =R"doc(return{u*vectorU + v*vectorV})doc";

static const char * __doc_Bentley_Geom_DPlane3dByVectors_Evaluate =R"doc(return{origin + u * vectorU + v * vectorV})doc";

static const char * __doc_Bentley_Geom_DPlane3dByVectors_GetDPlane3dWithUnitNormal =R"doc(Return DPlane3d form with unit normal.)doc";

static const char * __doc_Bentley_Geom_DPlane3dByVectors_FromOriginAndTargets =R"doc(Return a plane from orgin and u,v target points)doc";

static const char * __doc_Bentley_Geom_DPlane3dByVectors_FromOriginAndParallelToXZ =R"doc(Return a plane parallel to XZ from given origin.)doc";

static const char * __doc_Bentley_Geom_DPlane3dByVectors_FromOriginAndParallelToYZ =R"doc(Return a plane parallel to YZ from given origin.)doc";

static const char * __doc_Bentley_Geom_DPlane3dByVectors_FromOriginAndParallelToXY =R"doc(Return a plane parallel to XY from given origin.)doc";

static const char * __doc_Bentley_Geom_DPlane3dByVectors_FromXYPlane =R"doc(Construct basis for XY plane.)doc";

static const char * __doc_Bentley_Geom_DTriangle3d_CrossVectorsFromOrigin =R"doc(Return the cross product of VectorsFromOrigin)doc";

static const char * __doc_Bentley_Geom_DTriangle3d_AspectRatio =R"doc(Return a measure of triangle quality. The value is 0 for a 0 area
triangle, increases as aspect angles become more equal.)doc";

static const char * __doc_Bentley_Geom_DTriangle3d_GetCCWEdgeDVec3d =R"doc(Return specified edge as a vector Edge order is:bottom, diagonal,
left with CCW loop direction.)doc";

static const char * __doc_Bentley_Geom_DTriangle3d_GetCCWEdgeDRay3d =R"doc(Return specified edge as a ray. Edge order is:bottom, diagonal, left
with CCW loop direction.)doc";

static const char * __doc_Bentley_Geom_DTriangle3d_GetCCWEdgeDSegment3d =R"doc(Return specified edge as a line segment. Edge order is:bottom,
diagonal, left with CCW loop direction.)doc";

static const char * __doc_Bentley_Geom_DTriangle3d_ClosestPointUnbounded =R"doc(return uv and xyz coordinates of the projection to the unbounded plane
of the triangle.

Returns:
    false if axes are not independent.)doc";

static const char * __doc_Bentley_Geom_DTriangle3d_GetVectorsFromOrigin =R"doc(Return the two edge vectors outward from the origin.)doc";

static const char * __doc_Bentley_Geom_DTriangle3d_EvaluateNormal =R"doc(Return surface coordinates and unit normal at u,v parameters)doc";

static const char * __doc_Bentley_Geom_DTriangle3d_Evaluate =R"doc(Return surface coordinates at u,v parameters)doc";

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_DTriangle3d(py::module_& m)
    {
    //===================================================================================
    // struct DTriangle3d
    py::class_<DTriangle3d> c1(m, "DTriangle3d");
    py::bind_vector< DTriangle3dArray >(m, "DTriangle3dArray", py::module_local(false));

    c1.def(py::init<>());
    c1.def(py::init<DPoint3dCR, DPoint3dCR, DPoint3dCR>(), "xyz0"_a, "xyz10"_a, "xyz01"_a);
    c1.def(py::init<DPoint2dCR, DPoint2dCR, DPoint2dCR>(), "xyz0"_a, "xyz10"_a, "xyz01"_a);

    c1.def("Evaluate", py::overload_cast<double, double>(&DTriangle3d::Evaluate, py::const_), "u"_a, "v"_a, DOC(Bentley, Geom, DTriangle3d, Evaluate));
    c1.def("Evaluate", py::overload_cast<double, double, DPoint3dR, DVec3dR, DVec3dR>(&DTriangle3d::Evaluate, py::const_), "u"_a, "v"_a, "xyz"_a, "dXdu"_a, "dXdv"_a, DOC(Bentley, Geom, DTriangle3d, Evaluate));        
    c1.def("EvaluateNormal", &DTriangle3d::EvaluateNormal, "u"_a, "v"_a, "xyz"_a, "unitNormal"_a, DOC(Bentley, Geom, DTriangle3d, EvaluateNormal));    
    
    c1.def("GetVectorsFromOrigin", &DTriangle3d::GetVectorsFromOrigin, "vectorU"_a, "vectorV"_a, DOC(Bentley, Geom, DTriangle3d, GetVectorsFromOrigin));
        
    c1.def("ClosestPointUnbounded", 
           py::overload_cast<DPoint3dCR, DPoint2dR, DPoint3dR>(&DTriangle3d::ClosestPointUnbounded, py::const_), 
           "spacePoint"_a, "uv"_a, "xyz"_a, DOC(Bentley, Geom, DTriangle3d, ClosestPointUnbounded));

    c1.def("ClosestPointUnbounded",
           py::overload_cast<DPoint3dCR, DPoint2dR>(&DTriangle3d::ClosestPointUnbounded, py::const_),
           "spacePoint"_a, "uv"_a, DOC(Bentley, Geom, DTriangle3d, ClosestPointUnbounded));
        
    c1.def("GetCCWEdgeDSegment3d", &DTriangle3d::GetCCWEdgeDSegment3d, "i"_a, DOC(Bentley, Geom, DTriangle3d, GetCCWEdgeDSegment3d));
    c1.def("GetCCWEdgeDRay3d", &DTriangle3d::GetCCWEdgeDRay3d, "i"_a, DOC(Bentley, Geom, DTriangle3d, GetCCWEdgeDRay3d));
    c1.def("GetCCWEdgeDVec3d", &DTriangle3d::GetCCWEdgeDVec3d, "i"_a, DOC(Bentley, Geom, DTriangle3d, GetCCWEdgeDVec3d));

    c1.def("AspectRatio", &DTriangle3d::AspectRatio, DOC(Bentley, Geom, DTriangle3d, AspectRatio));
    c1.def("CrossVectorsFromOrigin", &DTriangle3d::CrossVectorsFromOrigin, DOC(Bentley, Geom, DTriangle3d, CrossVectorsFromOrigin));   

    c1.def("__repr__", [] (DTriangle3d& self)
           {
           return "(p0:{}, p1:{}, p2:{})"_s.format(self.point[0], self.point[1], self.point[2]);
           });

    c1.def("__copy__", [](const DTriangle3d& self)
        {
        return DTriangle3d(self);
        });

    //===================================================================================
    // struct DPlane3dByVectors
    py::class_<DPlane3dByVectors> c2(m, "DPlane3dByVectors");
    bind_ValidatedValue<DPlane3dByVectors>(m, "ValidatedDPlane3dByVectors", py::module_local(false));

    c2.def_readwrite("origin", &DPlane3dByVectors::origin);
    c2.def_readwrite("vectorU", &DPlane3dByVectors::vectorU);
    c2.def_readwrite("vectorV", &DPlane3dByVectors::vectorV);

    c2.def(py::init<>());
    c2.def(py::init<DPoint3dCR, DVec3dCR, DVec3d>(), "origin"_a, "vectorU"_a, "vectorV"_a);
    c2.def(py::init<double, double, double, double, double, double, double, double, double>(),
           "ax"_a, "ay"_a, "az"_a, "ux"_a, "uy"_a, "uz"_a, "vx"_a, "vy"_a, "vz"_a);
    c2.def(py::init<DEllipse3dCR>(), "ellipse"_a);
    c2.def(py::init<DTriangle3dCR>(), "triangle"_a);

    c2.def_static("FromXYPlane", &DPlane3dByVectors::FromXYPlane, DOC(Bentley, Geom, DPlane3dByVectors, FromXYPlane));
    c2.def_static("FromOriginAndParallelToXY", &DPlane3dByVectors::FromOriginAndParallelToXY, "origin"_a, "sizeU"_a, "sizeV"_a, DOC(Bentley, Geom, DPlane3dByVectors, FromOriginAndParallelToXY));
    c2.def_static("FromOriginAndParallelToYZ", &DPlane3dByVectors::FromOriginAndParallelToYZ, "origin"_a, "sizeU"_a, "sizeV"_a, DOC(Bentley, Geom, DPlane3dByVectors, FromOriginAndParallelToYZ));
    c2.def_static("FromOriginAndParallelToXZ", &DPlane3dByVectors::FromOriginAndParallelToXZ, "origin"_a, "sizeU"_a, "sizeV"_a, DOC(Bentley, Geom, DPlane3dByVectors, FromOriginAndParallelToXZ));
    c2.def_static("FromOriginAndTargets", &DPlane3dByVectors::FromOriginAndTargets, "origin"_a, "UTarget"_a, "VTarget"_a, DOC(Bentley, Geom, DPlane3dByVectors, FromOriginAndTargets));

    c2.def_property_readonly("DPlane3dWithUnitNormal", &DPlane3dByVectors::GetDPlane3dWithUnitNormal);
    c2.def("GetDPlane3dWithUnitNormal", &DPlane3dByVectors::GetDPlane3dWithUnitNormal, DOC(Bentley, Geom, DPlane3dByVectors, GetDPlane3dWithUnitNormal));
        
    c2.def("Evaluate", py::overload_cast<double, double>(&DPlane3dByVectors::Evaluate, py::const_), "u"_a, "v"_a, DOC(Bentley, Geom, DPlane3dByVectors, Evaluate));
    c2.def("Evaluate", py::overload_cast<DPoint2dCR>(&DPlane3dByVectors::Evaluate, py::const_), "uv"_a, DOC(Bentley, Geom, DPlane3dByVectors, Evaluate));
    c2.def("EvaluateVectorOnly", py::overload_cast<double, double>(&DPlane3dByVectors::EvaluateVectorOnly, py::const_), "u"_a, "v"_a, DOC(Bentley, Geom, DPlane3dByVectors, EvaluateVectorOnly));
    c2.def("EvaluateVectorOnly", py::overload_cast<DPoint2dCR>(&DPlane3dByVectors::EvaluateVectorOnly, py::const_), "uv"_a, DOC(Bentley, Geom, DPlane3dByVectors, EvaluateVectorOnly));
        
    c2.def("EvaluateTangents", &DPlane3dByVectors::EvaluateTangents, "u"_a, "v"_a, DOC(Bentley, Geom, DPlane3dByVectors, EvaluateTangents));        
    c2.def("GetTransformsUnitZ", &DPlane3dByVectors::GetTransformsUnitZ, "localToWorld"_a, "worldToLocal"_a, DOC(Bentley, Geom, DPlane3dByVectors, GetTransformsUnitZ));

    c2.def("TransverseIntersection", [] (DPlane3dByVectorsCR self, DSegment3dCR segment, DPoint2dR uv)
           {
           double segmentFraction = 0;
           bool bOk = self.TransverseIntersection(segment, uv, segmentFraction);
           return py::make_tuple(bOk, segmentFraction);
           }, "segment"_a, "uv"_a, DOC(Bentley, Geom, DPlane3dByVectors, TransverseIntersection));

    c2.def("MaxDiff", &DPlane3dByVectors::MaxDiff, "other"_a, DOC(Bentley, Geom, DPlane3dByVectors, MaxDiff));        
    c2.def("ProjectPoint", &DPlane3dByVectors::ProjectPoint, "spacePoint"_a, DOC(Bentley, Geom, DPlane3dByVectors, ProjectPoint));

    c2.def("__repr__", [] (DPlane3dByVectors& self)
           {
           return "(origin:{}, vectorU:{}, vectorV:{})"_s.format(self.origin, self.vectorU, self.vectorV);
           });

    c2.def("__copy__", [](const DPlane3dByVectors& self)
        {
        return DPlane3dByVectors(self);
        });
    }