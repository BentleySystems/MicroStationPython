#include "MSPythonPCH.h"

void def_PolylineOps(py::module_& m)
    {
    //===================================================================================
    // struct PolylineOps
    py::class_<PolylineOps> c1(m, "PolylineOps");
    c1.def_static("SetPolylinePolylineHeapTrigger", &PolylineOps::SetPolylinePolylineHeapTrigger, "mn"_a);
    c1.def_static("CollectIntersectionsAndCloseApproachesXY", &PolylineOps::CollectIntersectionsAndCloseApproachesXY, "xyzA"_a, "paramA"_a, "xyzB"_a, "paramB"_a, "locationA"_a, "locationB"_a, "maxDist"_a);
    c1.def_static("GreedyTriangulationBetweenLinestrings", py::overload_cast<bvector<DPoint3d> const&, bvector<DPoint3d> const&, bvector<DTriangle3d>&, bvector<int>*> (&PolylineOps::GreedyTriangulationBetweenLinestrings), "linestringA"_a, "lingstringB"_a, "triangles"_a, "oneBasedABIndex"_a = nullptr);
    c1.def_static("GreedyTriangulationBetweenLinestrings", py::overload_cast<bvector<DPoint3d> const&, bvector<DPoint3d> const&, bvector<DTriangle3d>&, bvector<int>*, Angle> (&PolylineOps::GreedyTriangulationBetweenLinestrings), "linestringA"_a, "lingstringB"_a, "triangles"_a, "oneBasedABIndex"_a, "planarityAngle"_a);
    c1.def_static("AddStrokes", py::overload_cast<bvector <DPoint3d> const&, bvector <DPoint3d>&, IFacetOptionsCR, bool, double, double> (PolylineOps::AddStrokes), "points"_a, "strokes"_a, "options"_a, "includeStartPoint"_a = true, "startFraction"_a = 0.0, "endFraction"_a = 1.0);
    c1.def_static("Length", py::overload_cast<bvector<DPoint3d> const&, bool>(&PolylineOps::Length), "xyz"_a, "addClosure"_a = false);
    c1.def_static("Length", py::overload_cast<RotMatrixCP, bvector<DPoint3d> const&, bool>(&PolylineOps::Length), "worldToLocal"_a, "xyz"_a, "addClosure"_a = false);
    c1.def_static("CompressByChordError", &PolylineOps::CompressByChordError, "result"_a, "source"_a, "chordTolerance"_a);
    c1.def_static("IsColinear", py::overload_cast<bvector<DPoint3d> const&, double, double>(&PolylineOps::IsColinear), "points"_a, "absTol"_a = 0, " relTol"_a = 0);

    }
