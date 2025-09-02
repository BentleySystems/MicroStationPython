/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyBentleyGeom\source\bsplinestructs.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"



static const char * __doc_Bentley_Geom_BCurveSegment_RefineCloseApproach =R"doc(Run newton iteration to move frctions to closest approach points.
return true if iteration succeeeded.

:param (input):
    curveA first curve

:param (input):
    fractionAin initial fraction on curveA

:param (input):
    curveB second curve

:param (input):
    fractionBin initial fraction on curveB

:param (input):
    useWorkPoles true to iterate with the work poles, false for
    primaries

:param (input):
    xyOnly true to iterate on xy parts, false for xyz

:param (output):
    fractionAOut fraction on curveA

:param (output):
    xyzAOut point on curveA

:param (output):
    fractionBOut fraction on curveB

:param (output):
    xyzBOut point on curveB)doc";

static const char * __doc_Bentley_Geom_BCurveSegment_Index =R"doc(Index (from start) in parent bspline)doc";

static const char * __doc_Bentley_Geom_BCurveSegment_SubdivideToIntersection =R"doc(Find the intersection of the segment UMin, UMax and the given
interval. If empty, return false. If not empty,)doc";

static const char * __doc_Bentley_Geom_BCurveSegment_SetUMax =R"doc(Set upper knot in parent bspline)doc";

static const char * __doc_Bentley_Geom_BCurveSegment_UMax =R"doc(Upper knot in parent bspline)doc";

static const char * __doc_Bentley_Geom_BCurveSegment_SetUMin =R"doc(Set lower knot in parent bspline)doc";

static const char * __doc_Bentley_Geom_BCurveSegment_UMin =R"doc(Lower knot in parent bspline)doc";

static const char * __doc_Bentley_Geom_BCurveSegment_IsNullU =R"doc(return true if the bezier (just extracted from bspline) has zero-
length knot interval.)doc";

static const char * __doc_Bentley_Geom_BCurveSegment_GetKnotP =R"doc(Get a pointer to an indexed knot.)doc";

static const char * __doc_Bentley_Geom_BCurveSegment_GetNumKnots =R"doc(Return knot count)doc";

static const char * __doc_Bentley_Geom_BCurveSegment_GetOrder =R"doc(Return pole count.)doc";

static const char * __doc_Bentley_Geom_BCurveSegment_GetPoleP =R"doc(Return (interior) pointer to indexed pole.)doc";

static const char * __doc_Bentley_Geom_BCurveSegment_TryGetPoleXYZ =R"doc(derference a pole, and drop to xyz.)doc";

static const char * __doc_Bentley_Geom_BCurveSegment_AddExtrema =R"doc(Find minmax params (in some or all dimensions)

:param [in,out]:
    params receiver vector.

:param (output):
    range (optional) range observed at (a) points in the params and
    (b) endpoints.

:param (input):
    mapToKnots if true convert bezier params to knots.

:param (input):
    firstDimension first dimension (0,1,2) to examine.

:param (input):
    lastDimension last dimension (0,1,2) to examine.

:param (input):
    includeStartEnd true to force params 0 and 1 into the results.)doc";

static const char * __doc_Bentley_Geom_BCurveSegment_BuildWorkPoles =R"doc(Transform primary poles into work poles.)doc";

static const char * __doc_Bentley_Geom_BCurveSegment_Multiply =R"doc(Transform primary poles)doc";

static const char * __doc_Bentley_Geom_BCurveSegment_GetWorkPoleP =R"doc(Return a work pole by index.)doc";

static const char * __doc_Bentley_Geom_BCurveSegment_IsRational =R"doc(Query if the bezier has weighted control points. Optionally inspect
the work poles rather than the primaries.)doc";

static const char * __doc_Bentley_Geom_BCurveSegment_AddStrokes =R"doc(Add strokes to point and param arrays.

:param [in,out]:
    points receives points.

:param [in,out]:
    params receives parameters.

:param [in,out]:
    derivatives receives derivatives

:param (input):
    options stroke controls

:param (input):
    fractionA start fraction

:param (input):
    fractionB end fraction

:param (input):
    useWorkPoles true to stroke from work poles, false for primaries.

:param (input):
    curve curve pointer (for use in parameter mapping, if indicated by
    facet options))doc";

static const char * __doc_Bentley_Geom_BCurveSegment_SaturateKnots =R"doc(On input, knots are arbitrary sorted sequence, with{order-1} leading
knots. On output, knots are collapsed to bezier.)doc";

static const char * __doc_Bentley_Geom_BCurveSegment_KnotRange =R"doc(Return uMin,uMax packaged as DRange1d....)doc";

static const char * __doc_Bentley_Geom_BCurveSegment_PolygonLength =R"doc(Compute polygon length)doc";

static const char * __doc_Bentley_Geom_BCurveSegment_Length =R"doc(Compute length between fractions)doc";

static const char * __doc_Bentley_Geom_BCurveSegment_WireCentroid =R"doc(Compute length and centroid of curve as wire.)doc";

static const char * __doc_Bentley_Geom_BCurveSegment_CopyFrom =R"doc(Copy from{source} and apply a 4d (perspective) matrix.)doc";

static const char * __doc_Bentley_Geom_BCurveSegment_FractionToKnot =R"doc(Return the knot value at a fractional parameter)doc";

static const char * __doc_Bentley_Geom_BCurveSegment_FractionToPoint =R"doc(Evalute the point at given fraction)doc";

static const char * __doc_Bentley_Geom_bSplineParam_NumberInteriorKnots =R"doc(Return the number of interior knots, as recorded (for legacy reasons)
in the params structures)doc";

static const char * __doc_Bentley_Geom_bSplineParam_NumberAllocatedKnots =R"doc(Return the number of knots in the allocated knot array. Note that this
number may be different from the value of the numKnots field of this
structure because the numKnots field traditionally indicated only the
number of interior knots.)doc";

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_BsplineStructs(py::module_& m)
    {
    //===================================================================================
    // Global constants    
    /* B-Spline curve types */
    m.attr("BSCURVE_GENERAL") = BSCURVE_GENERAL;
    m.attr("BSCURVE_LINE") = BSCURVE_LINE;
    m.attr("BSCURVE_CIRCULAR_ARC") = BSCURVE_CIRCULAR_ARC;
    m.attr("BSCURVE_CIRCLE") = BSCURVE_CIRCLE;
    m.attr("BSCURVE_ELLIPTICAL_ARC") = BSCURVE_ELLIPTICAL_ARC;
    m.attr("BSCURVE_ELLIPSE") = BSCURVE_ELLIPSE;
    m.attr("BSCURVE_PARABOLIC_ARC") = BSCURVE_PARABOLIC_ARC;
    m.attr("BSCURVE_HYPERBOLIC_ARC") = BSCURVE_HYPERBOLIC_ARC;

    /* B-Spline surface types */
    m.attr("BSSURF_GENERAL") = BSSURF_GENERAL;
    m.attr("BSSURF_PLANE") = BSSURF_PLANE;
    m.attr("BSSURF_RIGHT_CYLINDER") = BSSURF_RIGHT_CYLINDER;
    m.attr("BSSURF_CONE") = BSSURF_CONE;
    m.attr("BSSURF_SPHERE") = BSSURF_SPHERE;
    m.attr("BSSURF_TORUS") = BSSURF_TORUS;
    m.attr("BSSURF_REVOLUTION") = BSSURF_REVOLUTION;
    m.attr("BSSURF_TAB_CYLINDER") = BSSURF_TAB_CYLINDER;
    m.attr("BSSURF_RULED_SURFACE") = BSSURF_RULED_SURFACE;

    /* Constants */
    m.attr("BSSURF_U") = BSSURF_U;
    m.attr("BSSURF_V") = BSSURF_V;

    /* Fit modes */
    m.attr("FIT_POLES") = FIT_POLES;
    m.attr("FIT_POINTS") = FIT_POINTS;
    m.attr("FIT_LEASTSQUARES") = FIT_LEASTSQUARES;
    m.attr("FIT_CATMULLROM") = FIT_CATMULLROM;

    /* Offset cusp treatments */
    m.attr("OFFSET_JUMP_CUSP") = OFFSET_JUMP_CUSP;
    m.attr("OFFSET_CHAMFER_CUSP") = OFFSET_CHAMFER_CUSP;
    m.attr("OFFSET_POINT_CUSP") = OFFSET_POINT_CUSP;
    m.attr("OFFSET_PARABOLA_CUSP") = OFFSET_PARABOLA_CUSP;
    m.attr("OFFSET_ARC_CUSP") = OFFSET_ARC_CUSP;

    /* Continuity degree specifications */
    m.attr("POSITION_CONTINUITY") = POSITION_CONTINUITY;
    m.attr("TANGENT_CONTINUITY") = TANGENT_CONTINUITY;
    m.attr("CURVATURE_CONTINUITY") = CURVATURE_CONTINUITY;
    m.attr("DERIVATIVE_CONTINUITY") = DERIVATIVE_CONTINUITY;

    /* Truncation specifications */
    m.attr("TRUNCATE_BOTH") = TRUNCATE_BOTH;
    m.attr("TRUNCATE_NONE") = TRUNCATE_NONE;
    m.attr("TRUNCATE_SINGLE") = TRUNCATE_SINGLE;

    /* Iso display for silhouette curves */
    m.attr("SILHBND_U") = SILHBND_U;
    m.attr("SILHBND_V") = SILHBND_V;
    m.attr("SILHBND_NONE") = SILHBND_NONE;
    m.attr("SILHBND_BOTH") = SILHBND_BOTH;

    /* Surface edge classification */
    m.attr("NO_EDGE") = NO_EDGE;
    m.attr("U0_EDGE") = U0_EDGE;
    m.attr("U1_EDGE") = U1_EDGE;
    m.attr("V0_EDGE") = V0_EDGE;
    m.attr("V1_EDGE") = V1_EDGE;
    m.attr("ANY_EDGE") = ANY_EDGE;

    m.attr("MSB_SUCCESS") = MSB_SUCCESS;
    m.attr("MSB_ERROR") = MSB_ERROR;

    //===================================================================================
    // struct bSplineParam
    py::class_<bSplineParam> c1(m, "BsplineParam");

    c1.def_readwrite("order", &bSplineParam::order);
    c1.def_readwrite("closed", &bSplineParam::closed);
    c1.def_readwrite("numPoles", &bSplineParam::numPoles);
    c1.def_readwrite("numKnots", &bSplineParam::numKnots);
    c1.def_readwrite("numRules", &bSplineParam::numRules);

    c1.def_static("NumberAllocatedKnots", py::overload_cast<int32_t, int32_t, int32_t>(&bSplineParam::NumberAllocatedKnots), "numPoles"_a, "order"_a, "closed"_a, DOC(Bentley, Geom, bSplineParam, NumberAllocatedKnots));
    c1.def_static("NumberInteriorKnots", &bSplineParam::NumberInteriorKnots, "numPoles"_a, "order"_a, "closed"_a, DOC(Bentley, Geom, bSplineParam, NumberInteriorKnots));
    c1.def("__repr__", [] (bSplineParam& self)
           {
           return "(order:{}, closed:{}, numPoles:{}, numKnots:{}, numRules:{})"_s.format(self.order, self.closed, self.numPoles, self.numKnots, self.numRules);
           });
    c1.def("__copy__", [](const bSplineParam& self)
        {
        return bSplineParam(self);
        });

    //===================================================================================
    // struct interpolationParam
    py::class_<interpolationParam> c2(m, "interpolationParam");
    
    c2.def_readwrite("order", &interpolationParam::order);
    c2.def_readwrite("isPeriodic", &interpolationParam::isPeriodic);
    c2.def_readwrite("numPoints", &interpolationParam::numPoints);
    c2.def_readwrite("numKnots", &interpolationParam::numKnots);
    
    c2.def_readwrite("isChordLenKnots", &interpolationParam::isChordLenKnots);
    c2.def_readwrite("isColinearTangents", &interpolationParam::isColinearTangents);
    c2.def_readwrite("isChordLenTangents", &interpolationParam::isChordLenTangents);
    c2.def_readwrite("isNaturalTangents", &interpolationParam::isNaturalTangents);

    c2.def("__repr__", [] (interpolationParam& self)
           {
           return "(order:{}, isPeriodic:{}, numPoints:{}, numKnots:{}, isChordLenKnots:{}, isColinearTangents:{}, isChordLenTangents:{}, isNaturalTangents:{})"_s
               .format(self.order, self.isPeriodic, self.numPoints, self.numKnots, self.isChordLenKnots, self.isColinearTangents, self.isChordLenTangents, self.isNaturalTangents);
           });
    c2.def("__copy__", [](const interpolationParam& self)
        {
        return interpolationParam(self);
        });

    //===================================================================================
    // struct bsplineDisplay
    py::class_<bsplineDisplay> c4(m, "BsplineDisplay");

    c4.def_readwrite("polygonDisplay", &bsplineDisplay::polygonDisplay);
    c4.def_readwrite("curveDisplay", &bsplineDisplay::curveDisplay);
    c4.def_readwrite("rulesByLength", &bsplineDisplay::rulesByLength);

    c4.def("__repr__", [](bsplineDisplay& self)
        {
            return "(polygonDisplay:{}, curveDisplay:{}, rulesByLength:{})"_s.format(self.polygonDisplay, self.curveDisplay, self.rulesByLength);
        });

    //===================================================================================
    // struct BCurveSegment
    py::class_<BCurveSegment> c3(m, "BCurveSegment");

    c3.def(py::init<>());

    c3.def("__copy__", [](const BCurveSegment& self)
        {
        return BCurveSegment(self);
        });

    c3.def("FractionToPoint", py::overload_cast<DPoint3dR, double>(&BCurveSegment::FractionToPoint, py::const_), "xyz"_a, "f"_a, DOC(Bentley, Geom, BCurveSegment, FractionToPoint));
    c3.def("FractionToPoint", py::overload_cast<double>(&BCurveSegment::FractionToPoint, py::const_), "f"_a, DOC(Bentley, Geom, BCurveSegment, FractionToPoint));    
    c3.def("FractionToPoint", py::overload_cast<DPoint3dR, DVec3dR, double, bool>(&BCurveSegment::FractionToPoint, py::const_), "xyz"_a, "tangent"_a, "f"_a, "applyKnotScale"_a = true, DOC(Bentley, Geom, BCurveSegment, FractionToPoint));
    
    c3.def("FractionToKnot", &BCurveSegment::FractionToKnot, "f"_a, DOC(Bentley, Geom, BCurveSegment, FractionToKnot));

    c3.def("CopyFrom", py::overload_cast<BCurveSegmentCR, DMatrix4dCP>(&BCurveSegment::CopyFrom), "source"_a, "matrix"_a = nullptr, DOC(Bentley, Geom, BCurveSegment, CopyFrom));
    c3.def("CopyFrom", py::overload_cast<BCurveSegmentCR, RotMatrixCR>(&BCurveSegment::CopyFrom), "source"_a, "matrix"_a, DOC(Bentley, Geom, BCurveSegment, CopyFrom));
    c3.def("CopyFrom", py::overload_cast<BCurveSegmentCR, TransformCR>(&BCurveSegment::CopyFrom), "source"_a, "matrix"_a, DOC(Bentley, Geom, BCurveSegment, CopyFrom));
    
    c3.def("WireCentroid", [] (BCurveSegmentR self, DPoint3dR centroid, double fraction0, double fraction1)
          {
          double len = 0;
          self.WireCentroid(len, centroid, fraction0, fraction1);
          return len;
          }, "centroid"_a, "fraction0"_a, "fraction1"_a, DOC(Bentley, Geom, BCurveSegment, WireCentroid));

    c3.def("Length", [] (BCurveSegmentR self, double fraction0, double fraction1)
          {
          double len = 0;
          self.Length(len, fraction0, fraction1);
          return len;
          }, "fraction0"_a, "fraction1"_a, DOC(Bentley, Geom, BCurveSegment, Length));

    c3.def("Length", [] (BCurveSegmentR self, RotMatrixCP worldToLocal, double fraction0, double fraction1)
          {
          double len = 0;
          self.Length(worldToLocal, len, fraction0, fraction1);
          return len;
          }, "worldToLocal"_a, "fraction0"_a, "fraction1"_a, DOC(Bentley, Geom, BCurveSegment, Length));

    c3.def("PolygonLength", &BCurveSegment::PolygonLength, DOC(Bentley, Geom, BCurveSegment, PolygonLength));
    c3.def("KnotRange", &BCurveSegment::KnotRange, DOC(Bentley, Geom, BCurveSegment, KnotRange));
    
    c3.def("SaturateKnots", &BCurveSegment::SaturateKnots, DOC(Bentley, Geom, BCurveSegment, SaturateKnots));
    c3.def("AddStrokes", &BCurveSegment::AddStrokes, "points"_a, "derivatives"_a, "params"_a, "options"_a, "fractionA"_a = 0.0, "fractionB"_a = 1.0, "useWorkPoles"_a = false, "curve"_a = nullptr, DOC(Bentley, Geom, BCurveSegment, AddStrokes));
    c3.def("IsRational", &BCurveSegment::IsRational, "useWorkPoles"_a = false, DOC(Bentley, Geom, BCurveSegment, IsRational));
    c3.def("GetWorkPoleP", &BCurveSegment::GetWorkPoleP, py::return_value_policy::reference_internal, "index"_a, DOC(Bentley, Geom, BCurveSegment, GetWorkPoleP));
    c3.def("Multiply", &BCurveSegment::Multiply, "transform"_a, DOC(Bentley, Geom, BCurveSegment, Multiply));
    c3.def("BuildWorkPoles", &BCurveSegment::BuildWorkPoles, "transform"_a, DOC(Bentley, Geom, BCurveSegment, BuildWorkPoles));
    c3.def("AddExtrema", &BCurveSegment::AddExtrema, "params"_a, "range"_a = nullptr, "mapToKnots"_a = false, "firstDimension"_a = 0, "lastDimension"_a = 2, "includeStartEnd"_a = true, DOC(Bentley, Geom, BCurveSegment, AddExtrema));
    c3.def("TryGetPoleXYZ", &BCurveSegment::TryGetPoleXYZ, "index"_a, "xyz"_a, DOC(Bentley, Geom, BCurveSegment, TryGetPoleXYZ));
    c3.def("GetPoleP", py::overload_cast<size_t>(&BCurveSegment::GetPoleP), py::return_value_policy::reference_internal, "index"_a, DOC(Bentley, Geom, BCurveSegment, GetPoleP));
    c3.def("GetPoleP", py::overload_cast<>(&BCurveSegment::GetPoleP), py::return_value_policy::reference_internal, DOC(Bentley, Geom, BCurveSegment, GetPoleP));
    
    c3.def_property_readonly("Order", &BCurveSegment::GetOrder);
    c3.def("GetOrder", &BCurveSegment::GetOrder, DOC(Bentley, Geom, BCurveSegment, GetOrder));

    c3.def_property_readonly("NumKnots", &BCurveSegment::GetNumKnots);
    c3.def("GetNumKnots", &BCurveSegment::GetNumKnots, DOC(Bentley, Geom, BCurveSegment, GetNumKnots));

    c3.def("GetKnotP", py::overload_cast<size_t>(&BCurveSegment::GetKnotP), py::return_value_policy::reference_internal, "index"_a, DOC(Bentley, Geom, BCurveSegment, GetKnotP));
    c3.def("GetKnotP", py::overload_cast<>(&BCurveSegment::GetKnotP), py::return_value_policy::reference_internal, DOC(Bentley, Geom, BCurveSegment, GetKnotP));
    
    c3.def("IsNullU", &BCurveSegment::IsNullU, DOC(Bentley, Geom, BCurveSegment, IsNullU));

    c3.def("UMin", &BCurveSegment::UMin, DOC(Bentley, Geom, BCurveSegment, UMin));
    c3.def("SetUMin", &BCurveSegment::SetUMin, "u"_a, DOC(Bentley, Geom, BCurveSegment, SetUMin));

    c3.def("UMax", &BCurveSegment::UMax, DOC(Bentley, Geom, BCurveSegment, UMax));
    c3.def("SetUMax", &BCurveSegment::SetUMax, "u"_a, DOC(Bentley, Geom, BCurveSegment, SetUMax));

    c3.def("SubdivideToIntersection", &BCurveSegment::SubdivideToIntersection, "interval"_a, DOC(Bentley, Geom, BCurveSegment, SubdivideToIntersection));

    c3.def("Index", &BCurveSegment::Index, DOC(Bentley, Geom, BCurveSegment, Index));

    c3.def_static("RefineCloseApproach", [] (BCurveSegmentR curveA, double fractionAin, BCurveSegmentR curveB, double fractionBin, bool useWorkPoles, bool xyOnly)
                 {
                 double fractionAout, fractionBout;
                 DPoint3d xyzAOut, xyzBOut;
                 py::tuple outVal;
                 if (BCurveSegment::RefineCloseApproach(curveA, fractionAin, curveB, fractionBin, useWorkPoles, xyOnly, fractionAout, xyzAOut, fractionBout, xyzBOut))
                     outVal = py::cast(std::make_tuple(fractionAout, xyzAOut, fractionBout, xyzBOut));

                 return outVal;
                 }, "curveA"_a, "fractionAin"_a, "curveB"_a, "fractionBin"_a, "useWorkPoles"_a, "xyOnly"_a, DOC(Bentley, Geom, BCurveSegment, RefineCloseApproach));

    c3.def("__repr__", [] (BCurveSegmentR self)
           {
           return "(order:{}, workOrder:{}, numKnots:{}, knotRange:[{}, {}])"_s
               .format(self.GetOrder(), self.GetWorkOrder(), self.GetNumKnots(), self.UMin(), self.UMax());
           });
    }
