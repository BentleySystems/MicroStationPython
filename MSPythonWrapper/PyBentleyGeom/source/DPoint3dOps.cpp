#include "MSPythonPCH.h"

void def_DPoint3dOps(py::module_& m)
{
    //===================================================================================
    // struct PolygonOps
    py::class_<PolygonOps> c1(m, "PolygonOps");
    c1.def_static ("AreaNormal", py::overload_cast <bvector<DPoint3d> const&>(&PolygonOps::AreaNormal), "xyz"_a);
    c1.def_static ("AreaNormal", py::overload_cast <bvector<DPoint3d> const&, size_t>(&PolygonOps::AreaNormal), "xyz"_a, "n"_a);
    c1.def_static ("IsConvex", &PolygonOps::IsConvex, "xyz"_a);
    c1.def_static ("FixupAndTriangulateLoopsXY", &PolygonOps::FixupAndTriangulateLoopsXY, "pIndices"_a, "pExteriorLoopIndices"_a, "pXYZOut"_a, "pXYZIn"_a, "xyTolerance"_a, "maxPerFace"_a, "signedOneBasedIndices"_a, "addVerticesAtCrossings"_a);
    c1.def_static ("SplitToConvexPartsXY", &PolygonOps::SplitToConvexPartsXY, "indices"_a, "xyzOut"_a, "xyzIn"_a, "xyTol"_a = -1.0);
    c1.def_static ("FixupAndTriangulateProjectedLoops", py::overload_cast <bvector<int>*, bvector<int>*, bvector<DPoint3d>*, TransformCR, TransformCR, bvector<DPoint3d>*, double, bool>(&PolygonOps::FixupAndTriangulateProjectedLoops), "pIndices"_a, "pExteriorLoopIndices"_a, "pXYZOut"_a, "localToWorld"_a, "worldToLocal"_a, "pXYZIn"_a, "xyTolerance"_a, "bSignedOneBasedIndices"_a);
    c1.def_static ("FixupAndTriangulateProjectedLoops", py::overload_cast <bvector<bvector<DPoint3d>> const&, bvector<DPoint3d> const*, bvector<bvector<DPoint3d>> const*, TransformCR, TransformCR, bvector<DTriangle3d>&>(&PolygonOps::FixupAndTriangulateProjectedLoops), "loops"_a, "extraPoints"_a, "extraChains"_a, "localToWorld"_a, "worldToLocal"_a, "triangles"_a);
    c1.def_static ("FixupAndTriangulateProjectedLoops", py::overload_cast <bvector<bvector<DPoint3d>> const&, TransformCR, TransformCR, bvector<DTriangle3d>&>(PolygonOps::FixupAndTriangulateProjectedLoops), "loops"_a, "localToWorld"_a, "worldToLocal"_a, "triangles"_a);
    c1.def_static ("FixupAndTriangulateProjectedLoopsWithSplits", &PolygonOps::FixupAndTriangulateProjectedLoopsWithSplits, "masterLoop"_a, "extraSegments"_a, "localToWorld"_a, "worldToLocal"_a, "triangulate"_a, "leftOfSplit"_a, "leftOfSplitReversed"_a, "rightOfSplit"_a, "rightOfSplitReversed"_a, "ambiguous"_a);
    c1.def_static ("FixupAndTriangulateSpaceLoops", py::overload_cast <bvector<int>*, bvector<int>*, bvector<DPoint3d>*, TransformR, TransformR, bvector<DPoint3d>*, double, bool>(&PolygonOps::FixupAndTriangulateSpaceLoops), "pIndices"_a, "pExteriorLoopIndices"_a, "pXYZOut"_a, "localToWorld"_a, "worldToLocal"_a, "pXYZIn"_a, "xyTolerance"_a, "bSignedOneBasedIndices"_a);
    c1.def_static ("FixupAndTriangulateSpaceLoops", py::overload_cast <bvector<int>&, bvector<int>&, bvector<DPoint3d>&, TransformR, TransformR, bvector<bvector<DPoint3d>> const&>(&PolygonOps::FixupAndTriangulateSpaceLoops), "triangleIndices"_a, "exteriorLoopIndices"_a, "xyzOut"_a, "localToWorld"_a, "worldToLocal"_a, "loops"_a);
    c1.def_static ("FixupAndTriangulateSpaceLoops", py::overload_cast <bvector<bvector<DPoint3d>> const&, bvector<DTriangle3d>&>(&PolygonOps::FixupAndTriangulateSpaceLoops), "loops"_a, "triangles"_a);
    c1.def_static ("CoordinateFrame", py::overload_cast <bvector<DPoint3d>*, TransformR, TransformR>(&PolygonOps::CoordinateFrame), "pXYZIn"_a, "localToWorld"_a, "worldToLocal"_a);
    c1.def_static ("CoordinateFrame", ([](bvector<DPoint3d>* pXYZIn, TransformR localToWorld, TransformR worldToLocal, enum LocalCoordinateSelect selector)
        {
        return PolygonOps::CoordinateFrame (pXYZIn->data(), pXYZIn->size(), localToWorld, worldToLocal, selector);
        }), "pXYZIn"_a, "localToWorld"_a, "worldToLocal"_a, "selector"_a);
    c1.def_static ("CoordinateFrameAndRank", ([](bvector<DPoint3d>* pXYZIn, TransformR localToWorld, TransformR worldToLocal, enum LocalCoordinateSelect selector)
        {
        return PolygonOps::CoordinateFrameAndRank (pXYZIn->data(), pXYZIn->size(), localToWorld, worldToLocal, selector);
        }), "pXYZIn"_a, "localToWorld"_a, "worldToLocal"_a, "selector"_a);
    c1.def_static ("ReorientTriangulationIndices", ([](bvector<int>& indices, bool bSignedOneBasedIndices)
        {
        bool pbReversed, bRet;
        bRet = PolygonOps::ReorientTriangulationIndices(indices, &pbReversed, bSignedOneBasedIndices);
        return py::make_tuple(bRet, pbReversed);
        }), "indices"_a, "bSignedOneBasedIndices"_a);
    c1.def_static ("AreaXY", py::overload_cast<bvector<DPoint3d> const&>(&PolygonOps::AreaXY), "xyz"_a);
    c1.def_static ("AreaPerpendicularToUpVector", &PolygonOps::AreaPerpendicularToUpVector, "xyz"_a, "unitPerpendicular"_a);
    c1.def_static ("Area", py::overload_cast<bvector<DPoint2d> const&>(&PolygonOps::Area), "xy"_a);
    c1.def_static ("IsPointInOrOnXYTriangle", &PolygonOps::IsPointInOrOnXYTriangle, "xyz"_a, "point0"_a, "point1"_a, "point2"_a);
    c1.def_static ("IsPointInConvexPolygon", ([](DPoint2dCR xy, bvector<DPoint2d> const &points, int sense = 0)
        {
        return PolygonOps::IsPointInConvexPolygon(xy, points.data(), (int)points.size(), sense);
        }),"xy"_a, "points"_a, "sense"_a = 0);
    c1.def_static ("PointPolygonParity", &PolygonOps::PointPolygonParity, "point"_a, "polygonPoints"_a, "tol"_a);
    c1.def_static ("CentroidNormalAndArea", ([](bvector<DPoint3d> const& xyz, DPoint3dR centroid, DVec3dR normal)
        {
        double area;
        bool bRet = PolygonOps::CentroidNormalAndArea(xyz, centroid, normal, area);
        return py::make_tuple (bRet, area);
        }), "xyz"_a, "centroid"_a, "normal"_a);
    c1.def_static ("PickTriangleFromStart", ([](bvector<DPoint3d> const &pXYZ, DRay3dCR ray, DPoint3dR xyz, DPoint3dR triangleFractions)
        {
        double rayFraction;
        size_t edgeBaseIndex;
        bool bRet = PolygonOps::PickTriangleFromStart (pXYZ.data(), pXYZ.size(), ray, xyz, triangleFractions, rayFraction, edgeBaseIndex);
        return py::make_tuple (bRet, rayFraction, edgeBaseIndex);
        }), "pXYZ"_a, "ray"_a, "xyz"_a, "triangleFractions"_a);
    c1.def_static ("ReverseForPreferedNormal", &PolygonOps::ReverseForPreferedNormal, "xyz"_a, "positiveDirection"_a);
    c1.def_static ("PickTriangleFromStart", ([](bvector<DPoint2d> xyPoints, DPoint2dCR xy, size_t& edgeBaseIndex, DPoint3dR uvw, DPoint3dR duvwdX, DPoint3dCR duvwdY)
        {
        return PolygonOps::PickTriangleFromStart(xyPoints.data(), xyPoints.size(), xy, edgeBaseIndex, uvw, duvwdX, duvwdY);
        }), "xyPoints"_a, "xy"_a, "edgeBaseIndex"_a, "uvw"_a, "duvwdX"_a, "duvwdY"_a);
    c1.def_static ("PlaneIntersectionPoints", &PolygonOps::PlaneIntersectionPoints, "points"_a, "plane"_a, "touchTolerance"_a, "trueCrossings"_a, "touchData"_a, "altitudeLimits"_a);

    //===================================================================================
    // struct DPoint3dOps
    py::class_<DPoint3dOps> c2 (m, "DPoint3dOps");
    c2.def_static ("Add", &DPoint3dOps::Add, "xyz"_a, "delta"_a);

    //===================================================================================
    // enum class DayOfWeek
    py::enum_<PlanePolygonSSICode>(m, "PlanePolygonSSICode")
        .value("eUnknown", PlanePolygonSSICode::Unknown)
        .value("eTransverse", PlanePolygonSSICode::Transverse)
        .value("eCoincident", PlanePolygonSSICode::Coincident)
        .export_values();
}