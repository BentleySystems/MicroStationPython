/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyBentleyGeom\source\msbsplinesurface.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <Geom/MSBsplineSurface.h>
#include <Pybind11/numpy.h>



static const char * __doc_Bentley_Geom_MSBsplineSurface_IsSameStructureAndGeometry =R"doc(Compare all data.)doc";

static const char * __doc_Bentley_Geom_MSBsplineSurface_IsSameStructure =R"doc(Compare all non-coordinate data.)doc";

static const char * __doc_Bentley_Geom_MSBsplineSurface_GetIsoVCurveSegments =R"doc(Get scan line intersections at constant v.)doc";

static const char * __doc_Bentley_Geom_MSBsplineSurface_GetIsoUCurveSegments =R"doc(Get scan line intersections at constant u.)doc";

static const char * __doc_Bentley_Geom_MSBsplineSurface_GetIsoVLineUIntersections =R"doc(Get scan line intersections at constant v.)doc";

static const char * __doc_Bentley_Geom_MSBsplineSurface_GetIsoULineVIntersections =R"doc(Get scan line intersections at constant u.)doc";

static const char * __doc_Bentley_Geom_MSBsplineSurface_GetIsoVCurve =R"doc(Get the (untrimmed) u-direction curve at v)doc";

static const char * __doc_Bentley_Geom_MSBsplineSurface_GetIsoUCurve =R"doc(Get the (untrimmed) v-direction curve at u)doc";

static const char * __doc_Bentley_Geom_MSBsplineSurface_GetPolygonColumnAsCurve =R"doc(Copy poles from a column into a curve structure. index -1 is
understood as " end ")doc";

static const char * __doc_Bentley_Geom_MSBsplineSurface_GetPolygonRowAsCurve =R"doc(Copy poles from a row into a curve structure. index -1 is understood
as " end ")doc";

static const char * __doc_Bentley_Geom_MSBsplineSurface_SetTrim =R"doc(Delete previous trim and add new trim.)doc";

static const char * __doc_Bentley_Geom_MSBsplineSurface_GetUVBoundaryCurves =R"doc(Return current uv boundary data. This returns a parity region.)doc";

static const char * __doc_Bentley_Geom_MSBsplineSurface_FixupBoundaryLoopParity =R"doc(Analyze loop parity among all boundary loops. Replace as " complete "
loop set -- no implicit 01 outer boundary.)doc";

static const char * __doc_Bentley_Geom_MSBsplineSurface_GetNumPointsInBoundary =R"doc(return the number of ponits in a boundary.)doc";

static const char * __doc_Bentley_Geom_MSBsplineSurface_ComputeSecondMomentAreaProducts =R"doc(Return the integrals of products of inertia [xx xy xz x; xy yy yz y;
xz yz zz 1] * dA)doc";

static const char * __doc_Bentley_Geom_MSBsplineSurface_SetVParamsWithUniformKnots =R"doc(Install counts and set up uniform knots in v direction.)doc";

static const char * __doc_Bentley_Geom_MSBsplineSurface_SetUParamsWithUniformKnots =R"doc(Install counts and set up uniform knots in u direction.)doc";

static const char * __doc_Bentley_Geom_MSBsplineSurface_ComputeUniformVKnots =R"doc(Compute uniformly spaced knots. This uses counts from params.

Returns:
    false if param counts are not set.)doc";

static const char * __doc_Bentley_Geom_MSBsplineSurface_ComputeUniformUKnots =R"doc(Compute uniformly spaced knots. This uses counts from params.

Returns:
    false if param counts are not set.)doc";

static const char * __doc_Bentley_Geom_MSBsplineSurface_NormalizeSurface =R"doc(Scale and translate the parameter range of the surface and its
boundary loops so all parameters are between 0 and 1.)doc";

static const char * __doc_Bentley_Geom_MSBsplineSurface_TransformSurface =R"doc(Transform the B-spline surface.)doc";

static const char * __doc_Bentley_Geom_MSBsplineSurface_GetSupport =R"doc(Extract the poles and knots that support a single bezier patch ...

Parameter ``[out]``:
    outPoles{uOrder X vOrder} poles

Parameter ``[out]``:
    outUKnots{2*(uOrder-1)} knots

Parameter ``[out]``:
    outVKnots{2*(vOrder-1)} knots

Parameter ``[in]``:
    uIndex index of bezier to extract.

Parameter ``[in]``:
    vIndex index of bezier to extract. @DotNetMethodExclude)doc";

static const char * __doc_Bentley_Geom_MSBsplineSurface_MakeBeziers =R"doc(Create a series of Bezier surfaces for the B-spline surface.)doc";

static const char * __doc_Bentley_Geom_MSBsplineSurface_MakeBezier =R"doc(Create equivalent Bezier surface for the B-spline surface.)doc";

static const char * __doc_Bentley_Geom_MSBsplineSurface_MakeReversed =R"doc(Reserve the given direction of the surface.)doc";

static const char * __doc_Bentley_Geom_MSBsplineSurface_SwapUV =R"doc(Swap the U/V direction of the surface.)doc";

static const char * __doc_Bentley_Geom_MSBsplineSurface_MakeRational =R"doc(Make an equivalent rational B-spline surface.)doc";

static const char * __doc_Bentley_Geom_MSBsplineSurface_MakeClosed =R"doc(Close the open B-spline surface about the given direction.)doc";

static const char * __doc_Bentley_Geom_MSBsplineSurface_MakeOpen =R"doc(Open the closed B-spline surface about the given direction.)doc";

static const char * __doc_Bentley_Geom_MSBsplineSurface_CreateTubeSurface =R"doc(Create a surface swept along a trace curve.

Parameter ``[in]``:
    baseCurve base contour

Parameter ``[in]``:
    translateBaseCurve true to translate section, false to rotate with
    trace

Parameter ``[in]``:
    traceCurve path to sweep)doc";

static const char * __doc_Bentley_Geom_MSBsplineSurface_CreateTrimmedDisk =R"doc(Create a planar (bilinear) surface for the parallelogram around the
ellipse. Insert a trim curve for the ellipse.

Parameter ``[in]``:
    ellipse space ellipse)doc";

static const char * __doc_Bentley_Geom_MSBsplineSurface_CreateRuled =R"doc(Create a linear sweep from a ruled surface between two curves. Fails
(i.e. returns NULL) if the primitives have children or are not
compatible.

Parameter ``[in]``:
    curveA first curve

Parameter ``[in]``:
    curveB second curve)doc";

static const char * __doc_Bentley_Geom_MSBsplineSurface_CreateLinearSweep =R"doc(Create a linear sweep from a (single) base curve. Fails (i.e. returns
NULL) if the primitive has children.

Parameter ``[in]``:
    primitive base curve to be swept

Parameter ``[in]``:
    delta sweep direction.)doc";

static const char * __doc_Bentley_Geom_MSBsplineSurface_InitFromPointsAndOrder =R"doc(Initialize the B-spline surface from point array and U/V order.)doc";

static const char * __doc_Bentley_Geom_MSBsplineSurface_ClosestPoint =R"doc(Find closest point on surface)doc";

static const char * __doc_Bentley_Geom_MSBsplineSurface_RemoveKnotsBounded =R"doc(Remove all removable knots with the tolerance constraint.)doc";

static const char * __doc_Bentley_Geom_MSBsplineSurface_CleanKnots =R"doc(Clean all unnecessary knots.)doc";

static const char * __doc_Bentley_Geom_MSBsplineSurface_ElevateDegree =R"doc(Elevate the degree (increases the order) of the B-spline surface in
given direction.)doc";

static const char * __doc_Bentley_Geom_MSBsplineSurface_EvaluateNormalizedFrame =R"doc(Calculate a coordinate frame on the surface.

Parameter ``[in]``:
    u u parameter

Parameter ``[in]``:
    v v parameter.

Parameter ``[out]``:
    transform transform with (a) origin at surface point, (b) x axis
    in u direction, (c) y axis perpendicular to x and in the surface
    tangent plane, (d) z axis normal to surface. Return false if
    tangent vectors are parallel or zero.)doc";

static const char * __doc_Bentley_Geom_MSBsplineSurface_ControlPolygonFractionToControlPolygonDPoint3d =R"doc(Calculate the control polygon point at fractional position within a
control polygon quad.)doc";

static const char * __doc_Bentley_Geom_MSBsplineSurface_ControlPolygonFractionToControlPolygonDPoint4d =R"doc(Calculate the control polygon point at fractional position within a
control polygon quad.)doc";

static const char * __doc_Bentley_Geom_MSBsplineSurface_ControlPolygonFractionToKnot =R"doc(Calculate the knot values at fractional position within a control
polygon quad.)doc";

static const char * __doc_Bentley_Geom_MSBsplineSurface_EvaluatePointAndUnitNormal =R"doc(Calculate the point and unit normal on the B-spline surface at the
input u and v parameter values. Return false if tangent vectors are
parallel or zero.)doc";

static const char * __doc_Bentley_Geom_MSBsplineSurface_IsDegenerateEdge =R"doc(Check whether an edge of the surface degenerates to a single point.)doc";

static const char * __doc_Bentley_Geom_MSBsplineSurface_WeightPoles =R"doc(if the surface is rational, multiply (wx,wy,wz) style poles by the
weights)doc";

static const char * __doc_Bentley_Geom_MSBsplineSurface_UnWeightPoles =R"doc(if the surface is rational, divide (wx,wy,wz) style poles by the
weights)doc";

static const char * __doc_Bentley_Geom_MSBsplineSurface_SetVKnots =R"doc(set vKnotw by index. returns false if any index out of range.
@DotNetMethodExclude)doc";

static const char * __doc_Bentley_Geom_MSBsplineSurface_SetUKnots =R"doc(set uKnotw by index. returns false if any index out of range.
@DotNetMethodExclude)doc";

static const char * __doc_Bentley_Geom_MSBsplineSurface_SetWeights =R"doc(set weight by index. returns false if any index out of range.
@DotNetMethodExclude)doc";

static const char * __doc_Bentley_Geom_MSBsplineSurface_SetWeight =R"doc(set weight by index. returns false if index out of range.
@DotNetMethodExclude)doc";

static const char * __doc_Bentley_Geom_MSBsplineSurface_SetReWeightedPole =R"doc(set pole by index. returns false if index out of range. If the surface
is weighted, the current weight is multiplied into the input pole.)doc";

static const char * __doc_Bentley_Geom_MSBsplineSurface_SetPole =R"doc(set pole by index. returns false if index out of range.
@DotNetMethodExclude)doc";

static const char * __doc_Bentley_Geom_MSBsplineSurface_GetUnWeightedPoles =R"doc(Copy all poles out into caller array, dividing each by its weight)doc";

static const char * __doc_Bentley_Geom_MSBsplineSurface_GetWeights =R"doc(Copy all weights out into caller array.)doc";

static const char * __doc_Bentley_Geom_MSBsplineSurface_GetPoles =R"doc(Copy all poles out into caller array.)doc";

static const char * __doc_Bentley_Geom_MSBsplineSurface_TryGetUnWeightedPole =R"doc(Try to dereference index i,j.)doc";

static const char * __doc_Bentley_Geom_MSBsplineSurface_TransformPoles =R"doc(Transform a block of poles wtih start index i0,j0)doc";

static const char * __doc_Bentley_Geom_MSBsplineSurface_HasWeights =R"doc(ask if this is a " rational " (weighted) surface.)doc";

static const char * __doc_Bentley_Geom_MSBsplineSurface_GetIsVClosed =R"doc(return the v direction periodic state.)doc";

static const char * __doc_Bentley_Geom_MSBsplineSurface_GetIsUClosed =R"doc(return the u direction periodic state.)doc";

static const char * __doc_Bentley_Geom_MSBsplineSurface_GetNumVKnots =R"doc(return the v direction knot count.)doc";

static const char * __doc_Bentley_Geom_MSBsplineSurface_GetNumUKnots =R"doc(return the u direction knot count.)doc";

static const char * __doc_Bentley_Geom_MSBsplineSurface_GetVOrder =R"doc(return the v direction order.)doc";

static const char * __doc_Bentley_Geom_MSBsplineSurface_GetUOrder =R"doc(return the u direction order.)doc";

static const char * __doc_Bentley_Geom_MSBsplineSurface_GetNumVPoles =R"doc(return the v direction pole count.)doc";

static const char * __doc_Bentley_Geom_MSBsplineSurface_GetNumUPoles =R"doc(return the u direction pole count.)doc";

static const char * __doc_Bentley_Geom_MSBsplineSurface_GetNumPoles =R"doc(return the product of u and v direction poles counts.)doc";

static const char * __doc_Bentley_Geom_MSBsplineSurface_AreUKnotsValid =R"doc(Return the true allocated size of the pole array....)doc";

static const char * __doc_Bentley_Geom_MSBsplineSurface_GetPoleRange =R"doc(Get the range of the poles of the B-spline surface.)doc";

static const char * __doc_Bentley_Geom_MSBsplineSurface_Resolution =R"doc(Get the resolution of the B-spline surface.)doc";

static const char * __doc_Bentley_Geom_MSBsplineSurface_IsBidirectionalTranslation =R"doc(Check whether the u curves are all translations of the first u curve.
(If this is true, the v curves are also translations of the first v
curve0)

Parameter ``[in]``:
    relativeTolerance tolerance as a fraction of the largest
    coordinate.)doc";

static const char * __doc_Bentley_Geom_MSBsplineSurface_IsPlanarBilinear =R"doc(Check whether the B-spline surface is bilinear and each face of the
control polygon is planar, with tight system tolerance
(Angle::SmallAngle ()doc";

static const char * __doc_Bentley_Geom_MSBsplineSurface_GetPrincipalExtents =R"doc(Return a transform whose columns are along edges parallel to the
principal axes and sized to include the poles from the translation
point.)doc";

static const char * __doc_Bentley_Geom_MSBsplineSurface_IsPlane =R"doc(Check whether the poles are entirely within a plane. This does not
check for goofy direction changes -- just planarity.)doc";

static const char * __doc_Bentley_Geom_MSBsplineSurface_IsSolid =R"doc(Check whether the B-spline surface encloses a valid space.)doc";

static const char * __doc_Bentley_Geom_MSBsplineSurface_CopyReversed =R"doc(Create B-spline surface by reversing the given direction of surface.)doc";

static const char * __doc_Bentley_Geom_MSBsplineSurface_CopyClosed =R"doc(Create B-spline surface by closing a open B-spline surface.)doc";

static const char * __doc_Bentley_Geom_MSBsplineSurface_CopyOpen =R"doc(Create B-spline surface by opening a closed B-spline surface about
given direction.)doc";

static const char * __doc_Bentley_Geom_MSBsplineSurface_BoundaryLoopArea =R"doc(Return the area of a single boundary loop ..)doc";

static const char * __doc_Bentley_Geom_MSBsplineSurface_SetOuterBoundaryActive =R"doc(Parameter ``[in]``:
    active If true, the outer boundary is active as an (implicit) trim
    boundary, so the outermost explict boundary acts as a hole.)doc";

static const char * __doc_Bentley_Geom_MSBsplineSurface_IsOuterBoundaryActive =R"doc(Returns:
    the state of the outer boundary flag.)doc";

static const char * __doc_Bentley_Geom_MSBsplineSurface_DeleteBoundaries =R"doc(Remove all trim boundaries.)doc";

static const char * __doc_Bentley_Geom_MSBsplineSurface_AddTrimBoundary =R"doc(Add a uv polyline trim boundary.)doc";

static const char * __doc_Bentley_Geom_MSBsplineSurface_NormalizeKnots =R"doc(Normalize knots to 01 (both directions))doc";

static const char * __doc_Bentley_Geom_MSBsplineSurface_AddKnot =R"doc(Add a given knot value to the B-spline surface in given direction.
newMultiplicity is the desired final multiplicity of a knot that may
already exist.)doc";

static const char * __doc_Bentley_Geom_MSBsplineSurface_KnotToFraction =R"doc(Return the fractional parameter corresponding to a knot value ...)doc";

static const char * __doc_Bentley_Geom_MSBsplineSurface_FractionToKnot =R"doc(Return the knot value at a fractional parameter about given
direction...)doc";

static const char * __doc_Bentley_Geom_MSBsplineSurface_CreateCopyTransformed =R"doc(Clone as new refcounted pointer.)doc";

static const char * __doc_Bentley_Geom_MSBsplineSurface_CreateCapture =R"doc(Returns a smart pointer to an MSBsplineSurface on the heap. Copy bits
from instance, zero the instance.)doc";

static const char * __doc_Bentley_Geom_MSBsplineSurface_ExtractTo =R"doc(Copy bits into simple structure. Caller instance zeroed.)doc";

static const char * __doc_Bentley_Geom_MSBsplineSurface_CopyFrom =R"doc(Allocate memory for the B-spline surface and copies all data from the
input B-spline surface.)doc";

static const char * __doc_Bentley_Geom_MSBsplineSurface_ReleaseMem =R"doc(Free memory allocated for the poles, weights and knot vector of a
B-spline surface.)doc";

static const char * __doc_Bentley_Geom_MSBsplineSurface_AllocateVKnots =R"doc(Allocate vKnots. Prior knot buffer is freed if present (do not call on
pre-zeroed surface!!))doc";

static const char * __doc_Bentley_Geom_MSBsplineSurface_AllocateUKnots =R"doc(Allocate uKnots. Prior knot buffer is freed if present (do not call on
pre-zeroed surface!!))doc";

static const char * __doc_Bentley_Geom_MSBsplineSurface_Allocate =R"doc(Allocate memory arrays to match the current counts.)doc";

static const char * __doc_Bentley_Geom_MSBsplineSurface_Zero =R"doc(zero out the surface)doc";

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_MSBsplineSurface(py::module_& m)
    {
    //===================================================================================
    // struct MSBsplineSurface
    py::class_<MSBsplineSurface> c1(m, "MSBsplineSurface");
    py::class_<RefCountedMSBsplineSurface, std::unique_ptr<RefCountedMSBsplineSurface, py::nodelete>, MSBsplineSurface> c2(m, "RefCountedMSBsplineSurface", py::multiple_inheritance());
    py::bind_vector<MSBsplineSurfacePtrArray>(m, "MSBsplineSurfacePtrArray", py::module_local(false));

    c1.def_readwrite("type", &MSBsplineSurface::type);
    c1.def_readwrite("rational", &MSBsplineSurface::rational);
    c1.def_readwrite("display", &MSBsplineSurface::display);
    c1.def_readwrite("uParams", &MSBsplineSurface::uParams);
    c1.def_readwrite("vParams", &MSBsplineSurface::vParams);

    c1.def_property("poles",
        [](MSBsplineSurface& self)
        {   
        int  totalPoles = self.uParams.numPoles * self.vParams.numPoles;
        if (totalPoles < 0) totalPoles = 0;
        return py::array_t<DPoint3d>{ totalPoles, self.poles, py::cast(self)};
        },
        [](MSBsplineSurface& self, py::array_t<DPoint3d> const& arr)
        {
        py::buffer_info buf = arr.request();
        auto* ptr = static_cast<DPoint3d*>(buf.ptr);

        int  totalPoles = self.uParams.numPoles * self.vParams.numPoles;
        if (totalPoles <= 0)
            return;

        totalPoles = totalPoles > arr.size() ? arr.size() : totalPoles;
        memcpy(self.poles, ptr, totalPoles * sizeof(DPoint3d));
        });

    c1.def_property("uKnots",
        [](MSBsplineSurface& self)
        {   
        int  knotNum = self.uParams.NumberAllocatedKnots();
        if (knotNum < 0) knotNum = 0;
        return py::array_t<double>{ knotNum, self.uKnots, py::cast(self)};
        },
        [](MSBsplineSurface& self, py::array_t<double> const& arr)
        {
        py::buffer_info buf = arr.request();
        auto* ptr = static_cast<double*>(buf.ptr);

        int  knotNum = self.uParams.NumberAllocatedKnots();
        if (knotNum <= 0) return;

        knotNum = knotNum > arr.size() ? arr.size() : knotNum;
        memcpy(self.uKnots, ptr, knotNum * sizeof(double));
        });

    c1.def_property("vKnots",
        [](MSBsplineSurface& self)
        {   
        int  knotNum = self.vParams.NumberAllocatedKnots();
        if (knotNum <0) knotNum = 0;
        return py::array_t<double>{ knotNum, self.vKnots, py::cast(self)};
        },
        [](MSBsplineSurface& self, py::array_t<double> const& arr)
        {
        py::buffer_info buf = arr.request();
        auto* ptr = static_cast<double*>(buf.ptr);

        int  knotNum = self.vParams.NumberAllocatedKnots();
        if (knotNum <= 0) return;

        knotNum = knotNum > arr.size() ? arr.size() : knotNum;
        memcpy(self.vKnots, ptr, knotNum * sizeof(double));
        });

    c1.def_property("weights",
        [](MSBsplineSurface& self)
        {   
        int  totalPoles = self.uParams.numPoles * self.vParams.numPoles;
        if (!self.rational || totalPoles <= 0)
            totalPoles = 0;

        return py::array_t<double>{ totalPoles, self.weights, py::cast(self)};
        },
        [](MSBsplineSurface& self, py::array_t<double> const& arr)
        {
        py::buffer_info buf = arr.request();
        auto* ptr = static_cast<double*>(buf.ptr);
        int  totalPoles = self.uParams.numPoles * self.vParams.numPoles;

        if (!self.rational || totalPoles <= 0) return;

        totalPoles = totalPoles > arr.size() ?  arr.size() : totalPoles;

        memcpy(self.weights, ptr, totalPoles * sizeof(double));
        });

    c1.def_readwrite("holeOrigin", &MSBsplineSurface::holeOrigin);
    c1.def_readwrite("numBounds", &MSBsplineSurface::numBounds);

    c1.def(py::init([] () { auto retVal = new MSBsplineSurface(); retVal->Zero(); return retVal; }));
    c1.def("Zero", &MSBsplineSurface::Zero, DOC(Bentley, Geom, MSBsplineSurface, Zero));

    c1.def("Allocate", &MSBsplineSurface::Allocate, DOC(Bentley, Geom, MSBsplineSurface, Allocate));
    c1.def("AllocateUKnots", &MSBsplineSurface::AllocateUKnots, DOC(Bentley, Geom, MSBsplineSurface, AllocateUKnots));
    c1.def("AllocateVKnots", &MSBsplineSurface::AllocateVKnots, DOC(Bentley, Geom, MSBsplineSurface, AllocateVKnots));
    c1.def("ReleaseMem", &MSBsplineSurface::ReleaseMem, DOC(Bentley, Geom, MSBsplineSurface, ReleaseMem));
    c1.def("CopyFrom", &MSBsplineSurface::CopyFrom, "source"_a, DOC(Bentley, Geom, MSBsplineSurface, CopyFrom));
    c1.def("ExtractTo", &MSBsplineSurface::ExtractTo, "dest"_a, DOC(Bentley, Geom, MSBsplineSurface, ExtractTo));

    c1.def_static("Create", &MSBsplineSurface::CreatePtr);
    c1.def("CreateCapture", &MSBsplineSurface::CreateCapture, DOC(Bentley, Geom, MSBsplineSurface, CreateCapture));    
    c1.def("CreateCopyTransformed", &MSBsplineSurface::CreateCopyTransformed, "transform"_a, DOC(Bentley, Geom, MSBsplineSurface, CreateCopyTransformed));

    c1.def("GetKnotRange", [] (MSBsplineSurfaceCR self, int direction)
           {
           double minVal, maxVal;
           self.GetKnotRange(minVal, maxVal, direction);
           return py::make_tuple(minVal, maxVal);
           }, "direction"_a);

    c1.def("FractionToKnot", &MSBsplineSurface::FractionToKnot, "f"_a, "direction"_a, DOC(Bentley, Geom, MSBsplineSurface, FractionToKnot));
    c1.def("KnotToFraction", &MSBsplineSurface::KnotToFraction, "knot"_a, "direction"_a, DOC(Bentley, Geom, MSBsplineSurface, KnotToFraction));

    c1.def("GetParameterRegion", [] (MSBsplineSurfaceCR self)
           {
           double uMin, uMax, vMin, vMax;
           self.GetParameterRegion(uMin, uMax, vMin, vMax);
           return py::make_tuple(uMin, uMax, vMin, vMax);
           });
        
    c1.def("AddKnot", &MSBsplineSurface::AddKnot, "unnormalizedKnotValue"_a, "newMultiplicity"_a, "direction"_a, DOC(Bentley, Geom, MSBsplineSurface, AddKnot));

    c1.def("KnotToBlendFunctions", [] (MSBsplineSurfaceCR self, double* blend, double* blendDerivatives, double u, int direction)
           {
           size_t knotIndex = 0;
           self.KnotToBlendFunctions(blend, blendDerivatives, knotIndex, u, direction);
           return knotIndex;
           }, "blend"_a, "blendDerivatives"_a, "u"_a, "direction"_a); //TODO

    c1.def("FindKnotInterval", &MSBsplineSurface::FindKnotInterval, "knotValue"_a, "direction"_a);
    c1.def("NormalizeKnots", &MSBsplineSurface::NormalizeKnots, DOC(Bentley, Geom, MSBsplineSurface, NormalizeKnots));

    c1.def("AddTrimBoundary", py::overload_cast<DPoint2dArray const&>(&MSBsplineSurface::AddTrimBoundary), "uvPoints"_a, DOC(Bentley, Geom, MSBsplineSurface, AddTrimBoundary));
    c1.def("AddTrimBoundary", py::overload_cast<DPoint3dArray const&>(&MSBsplineSurface::AddTrimBoundary), "xyzPoints"_a, DOC(Bentley, Geom, MSBsplineSurface, AddTrimBoundary));
    c1.def("DeleteBoundaries", &MSBsplineSurface::DeleteBoundaries, DOC(Bentley, Geom, MSBsplineSurface, DeleteBoundaries));
    
    c1.def("IsOuterBoundaryActive", &MSBsplineSurface::IsOuterBoundaryActive, DOC(Bentley, Geom, MSBsplineSurface, IsOuterBoundaryActive));
    c1.def("SetOuterBoundaryActive", &MSBsplineSurface::SetOuterBoundaryActive, "active"_a, DOC(Bentley, Geom, MSBsplineSurface, SetOuterBoundaryActive));
    
    c1.def("BoundaryLoopArea", &MSBsplineSurface::BoundaryLoopArea, "boundaryIndex"_a, DOC(Bentley, Geom, MSBsplineSurface, BoundaryLoopArea));
    c1.def("CopyOpen", &MSBsplineSurface::CopyOpen, "source"_a, "unnormalizedKnot"_a, "edge"_a, DOC(Bentley, Geom, MSBsplineSurface, CopyOpen));
    c1.def("CopyClosed", &MSBsplineSurface::CopyClosed, "source"_a, "edge"_a, DOC(Bentley, Geom, MSBsplineSurface, CopyClosed));
    c1.def("CopyReversed", &MSBsplineSurface::CopyReversed, "source"_a, "edge"_a, DOC(Bentley, Geom, MSBsplineSurface, CopyReversed));

    c1.def("IsPhysicallyClosed", [] (MSBsplineSurfaceR self)
           {
           bool uClosed, vClosed;
           self.IsPhysicallyClosed(uClosed, vClosed);
           return py::make_tuple(uClosed, vClosed);
           });

    c1.def("IsSolid", &MSBsplineSurface::IsSolid, "tolerance"_a, DOC(Bentley, Geom, MSBsplineSurface, IsSolid));
    c1.def("IsPlane", &MSBsplineSurface::IsPlane, DOC(Bentley, Geom, MSBsplineSurface, IsPlane));
    c1.def("GetPrincipalExtents", &MSBsplineSurface::GetPrincipalExtents, "extends"_a, DOC(Bentley, Geom, MSBsplineSurface, GetPrincipalExtents));
    c1.def("IsPlanarBilinear", py::overload_cast<>(&MSBsplineSurface::IsPlanarBilinear, py::const_), DOC(Bentley, Geom, MSBsplineSurface, IsPlanarBilinear));
    c1.def("IsPlanarBilinear", py::overload_cast<double>(&MSBsplineSurface::IsPlanarBilinear, py::const_), "angleTol"_a, DOC(Bentley, Geom, MSBsplineSurface, IsPlanarBilinear));
    c1.def("IsBidirectionalTranslation", &MSBsplineSurface::IsBidirectionalTranslation, "relativeTolerance"_a = 0.0, DOC(Bentley, Geom, MSBsplineSurface, IsBidirectionalTranslation));

    c1.def("Resolution", py::overload_cast<>(&MSBsplineSurface::Resolution, py::const_), DOC(Bentley, Geom, MSBsplineSurface, Resolution));
    c1.def("Resolution", py::overload_cast<double, double>(&MSBsplineSurface::Resolution, py::const_), "abstol"_a, "reltol"_a, DOC(Bentley, Geom, MSBsplineSurface, Resolution));
    c1.def("GetPoleRange", py::overload_cast<DRange3dR>(&MSBsplineSurface::GetPoleRange, py::const_), "range"_a, DOC(Bentley, Geom, MSBsplineSurface, GetPoleRange));
    c1.def("GetPoleRange", py::overload_cast<DRange3dR, TransformCR>(&MSBsplineSurface::GetPoleRange, py::const_), "range"_a, "transform"_a, DOC(Bentley, Geom, MSBsplineSurface, GetPoleRange));

    c1.def("AreUKnotsValid", &MSBsplineSurface::AreUKnotsValid, "clampingRequired"_a, DOC(Bentley, Geom, MSBsplineSurface, AreUKnotsValid));
    c1.def("AreVKnotsValid", &MSBsplineSurface::AreVKnotsValid, "clampingRequired"_a);

    c1.def_property_readonly("NumPoles", &MSBsplineSurface::GetNumPoles);
    c1.def("GetNumPoles", &MSBsplineSurface::GetNumPoles, DOC(Bentley, Geom, MSBsplineSurface, GetNumPoles));

    c1.def_property_readonly("NumUPoles", &MSBsplineSurface::GetNumUPoles);
    c1.def("GetNumUPoles", &MSBsplineSurface::GetNumUPoles, DOC(Bentley, Geom, MSBsplineSurface, GetNumUPoles));
    
    c1.def_property_readonly("NumVPoles", &MSBsplineSurface::GetNumVPoles);
    c1.def("GetNumVPoles", &MSBsplineSurface::GetNumVPoles, DOC(Bentley, Geom, MSBsplineSurface, GetNumVPoles));
    
    c1.def_property_readonly("UOrder", &MSBsplineSurface::GetUOrder);
    c1.def("GetUOrder", &MSBsplineSurface::GetUOrder, DOC(Bentley, Geom, MSBsplineSurface, GetUOrder));
    
    c1.def_property_readonly("VOrder", &MSBsplineSurface::GetVOrder);
    c1.def("GetVOrder", &MSBsplineSurface::GetVOrder, DOC(Bentley, Geom, MSBsplineSurface, GetVOrder));
    
    c1.def_property_readonly("NumUKnots", &MSBsplineSurface::GetNumUKnots);
    c1.def("GetNumUKnots", &MSBsplineSurface::GetNumUKnots, DOC(Bentley, Geom, MSBsplineSurface, GetNumUKnots));
    
    c1.def_property_readonly("NumVKnots", &MSBsplineSurface::GetNumVKnots);
    c1.def("GetNumVKnots", &MSBsplineSurface::GetNumVKnots, DOC(Bentley, Geom, MSBsplineSurface, GetNumVKnots));
    
    c1.def_property_readonly("IsUClosed", &MSBsplineSurface::GetIsUClosed);
    c1.def("GetIsUClosed", &MSBsplineSurface::GetIsUClosed, DOC(Bentley, Geom, MSBsplineSurface, GetIsUClosed));
    
    c1.def_property_readonly("IsVClosed", &MSBsplineSurface::GetIsVClosed);
    c1.def("GetIsVClosed", &MSBsplineSurface::GetIsVClosed, DOC(Bentley, Geom, MSBsplineSurface, GetIsVClosed));
    
    c1.def("HasWeights", &MSBsplineSurface::HasWeights, DOC(Bentley, Geom, MSBsplineSurface, HasWeights));

    c1.def("__repr__", [] (MSBsplineSurface& self)
           {
           return "numPoles:{}, numUPoles:{}, numVPoles:{}, uOrder:{}, vOrder:{}, numUKnots:{}, numVKnots:{}, isUClosed:{}, isVClosed:{}, hasWeights:{}"_s
               .format(self.GetNumPoles(), self.GetNumUPoles(), self.GetNumVPoles(), self.GetUOrder(), self.GetVOrder(), self.GetNumUKnots(), self.GetNumVKnots(), 
                       self.GetIsUClosed(), self.GetIsVClosed(), self.HasWeights());
           });
    
    c1.def("SetNumRules", &MSBsplineSurface::SetNumRules, "numU"_a, "numV"_a);

    c1.def_property("SurfaceDisplay", &MSBsplineSurface::GetSurfaceDisplay, &MSBsplineSurface::SetSurfaceDisplay);
    c1.def("GetSurfaceDisplay", &MSBsplineSurface::GetSurfaceDisplay);
    c1.def("SetSurfaceDisplay", &MSBsplineSurface::SetSurfaceDisplay, "display"_a);

    c1.def_property("PolygonDisplay", &MSBsplineSurface::GetPolygonDisplay, &MSBsplineSurface::SetPolygonDisplay);
    c1.def("GetPolygonDisplay", &MSBsplineSurface::GetPolygonDisplay);
    c1.def("SetPolygonDisplay", &MSBsplineSurface::SetPolygonDisplay, "display"_a);

    c1.def("GetPole", py::overload_cast<size_t>(&MSBsplineSurface::GetPole, py::const_), "i"_a);
    c1.def("GetWeight", py::overload_cast<size_t>(&MSBsplineSurface::GetWeight, py::const_), "i"_a);
    c1.def("GetPole", py::overload_cast<size_t, size_t>(&MSBsplineSurface::GetPole, py::const_), "i"_a, "j"_a);
    c1.def("GetUnWeightedPole", py::overload_cast<size_t, size_t>(&MSBsplineSurface::GetUnWeightedPole, py::const_), "i"_a, "j"_a);
    c1.def("GetUnWeightedPole", py::overload_cast<size_t>(&MSBsplineSurface::GetUnWeightedPole, py::const_), "i"_a);
    c1.def("TransformPoles", &MSBsplineSurface::TransformPoles, "transform"_a, "i0"_a, "j0"_a, "numI"_a, "numJ"_a, DOC(Bentley, Geom, MSBsplineSurface, TransformPoles));
    c1.def("TryGetUnWeightedPole", py::overload_cast<size_t, size_t, DPoint3dR>(&MSBsplineSurface::TryGetUnWeightedPole, py::const_), "i"_a, "i"_a, "xyz"_a, DOC(Bentley, Geom, MSBsplineSurface, TryGetUnWeightedPole));
    c1.def("TryGetUnWeightedPole", py::overload_cast<size_t, DPoint3dR>(&MSBsplineSurface::TryGetUnWeightedPole, py::const_), "i"_a, "xyz"_a, DOC(Bentley, Geom, MSBsplineSurface, TryGetUnWeightedPole));
    c1.def("GetWeight", py::overload_cast<size_t, size_t>(&MSBsplineSurface::GetWeight, py::const_), "i"_a, "j"_a);
    c1.def("GetPoleDPoint4d", py::overload_cast<size_t>(&MSBsplineSurface::GetPoleDPoint4d, py::const_), "i"_a);
    c1.def("GetPoleDPoint4d", py::overload_cast<size_t, size_t>(&MSBsplineSurface::GetPoleDPoint4d, py::const_), "i"_a, "j"_a);
    c1.def("GetUKnot", &MSBsplineSurface::GetUKnot, "outData"_a);
    c1.def("GetVKnot", &MSBsplineSurface::GetVKnot, "outData"_a);

    c1.def("GetUKnots", &MSBsplineSurface::GetUKnots, "knots"_a);
    c1.def("GetVKnots", &MSBsplineSurface::GetVKnots, "knots"_a);
    c1.def("GetPoles", &MSBsplineSurface::GetPoles, "outData"_a, DOC(Bentley, Geom, MSBsplineSurface, GetPoles));
    c1.def("GetWeights", &MSBsplineSurface::GetWeights, "outData"_a, DOC(Bentley, Geom, MSBsplineSurface, GetWeights));
    c1.def("GetUnWeightedPoles", &MSBsplineSurface::GetUnWeightedPoles, "outData"_a, DOC(Bentley, Geom, MSBsplineSurface, GetUnWeightedPoles));
        
    c1.def("SetPole", py::overload_cast<size_t, DPoint3dCR>(&MSBsplineSurface::SetPole), "index"_a, "value"_a, DOC(Bentley, Geom, MSBsplineSurface, SetPole));
    c1.def("SetPole", py::overload_cast<size_t, size_t, DPoint3dCR>(&MSBsplineSurface::SetPole), "i"_a, "j"_a, "value"_a, DOC(Bentley, Geom, MSBsplineSurface, SetPole));
    c1.def("SetPole", py::overload_cast<size_t, double, double, double>(&MSBsplineSurface::SetPole), "i"_a, "x"_a, "y"_a, "z"_a, DOC(Bentley, Geom, MSBsplineSurface, SetPole));

    c1.def("SetReWeightedPole", py::overload_cast<size_t, DPoint3dCR>(&MSBsplineSurface::SetReWeightedPole), "index"_a, "value"_a, DOC(Bentley, Geom, MSBsplineSurface, SetReWeightedPole));
    c1.def("SetReWeightedPole", py::overload_cast<size_t, size_t, DPoint3dCR>(&MSBsplineSurface::SetReWeightedPole), "i"_a, "j"_a, "value"_a, DOC(Bentley, Geom, MSBsplineSurface, SetReWeightedPole));    
    
    c1.def("SetWeight", py::overload_cast<size_t, double>(&MSBsplineSurface::SetWeight), "index"_a, "w"_a, DOC(Bentley, Geom, MSBsplineSurface, SetWeight));
    c1.def("SetWeights", &MSBsplineSurface::SetWeights, "index"_a, "value"_a, "n"_a, DOC(Bentley, Geom, MSBsplineSurface, SetWeights));
    c1.def("SetUKnots", &MSBsplineSurface::SetUKnots, "index"_a, "value"_a, "n"_a, DOC(Bentley, Geom, MSBsplineSurface, SetUKnots));
    c1.def("SetVKnots", &MSBsplineSurface::SetVKnots, "index"_a, "value"_a, "n"_a, DOC(Bentley, Geom, MSBsplineSurface, SetVKnots));
    c1.def("UnWeightPoles", &MSBsplineSurface::UnWeightPoles, DOC(Bentley, Geom, MSBsplineSurface, UnWeightPoles));
    c1.def("WeightPoles", &MSBsplineSurface::WeightPoles, DOC(Bentley, Geom, MSBsplineSurface, WeightPoles));

    c1.def("IsDegenerateEdge", &MSBsplineSurface::IsDegenerateEdge, "edgeCode"_a, "tolerance"_a, DOC(Bentley, Geom, MSBsplineSurface, IsDegenerateEdge));
    c1.def("EvaluatePoint", 
           py::overload_cast<DPoint3dR, double, double>(&MSBsplineSurface::EvaluatePoint, py::const_),
           "xyz"_a, "u"_a, "v"_a);

    c1.def("EvaluateUniformGrid", 
           py::overload_cast<size_t, size_t, DoubleArray&, DoubleArray&, DPoint3dArray&>(&MSBsplineSurface::EvaluateUniformGrid, py::const_), 
           "numUPoint"_a, "numVPoint"_a, "uParams"_a, "vParams"_a, "gridPoints"_a);

    c1.def("EvaluateUniformGrid", 
           py::overload_cast<size_t, size_t, DPoint2dArray&, DPoint3dArray&>(&MSBsplineSurface::EvaluateUniformGrid, py::const_), 
           "numUPoint"_a, "numVPoint"_a, "uvParams"_a, "gridPoints"_a);

    c1.def("EvaluatePointAndUnitNormal", &MSBsplineSurface::EvaluatePointAndUnitNormal, "ray"_a, "u"_a, "v"_a, DOC(Bentley, Geom, MSBsplineSurface, EvaluatePointAndUnitNormal));
    c1.def("ControlPolygonFractionToKnot", &MSBsplineSurface::ControlPolygonFractionToKnot, "i"_a, "j"_a, "u"_a, "v"_a, DOC(Bentley, Geom, MSBsplineSurface, ControlPolygonFractionToKnot));
    c1.def("ControlPolygonFractionToControlPolygonDPoint4d", &MSBsplineSurface::ControlPolygonFractionToControlPolygonDPoint4d, "i"_a, "j"_a, "u"_a, "v"_a, DOC(Bentley, Geom, MSBsplineSurface, ControlPolygonFractionToControlPolygonDPoint4d));
    c1.def("ControlPolygonFractionToControlPolygonDPoint3d", &MSBsplineSurface::ControlPolygonFractionToControlPolygonDPoint3d, "i"_a, "j"_a, "u"_a, "v"_a, DOC(Bentley, Geom, MSBsplineSurface, ControlPolygonFractionToControlPolygonDPoint3d));

    c1.def("EvaluateNormalizedFrame", &MSBsplineSurface::EvaluateNormalizedFrame, "transform"_a, "u"_a, "v"_a, DOC(Bentley, Geom, MSBsplineSurface, EvaluateNormalizedFrame));
    c1.def("EvaluatePoint", 
           py::overload_cast<DPoint3dR, DVec3dR, DVec3dR, double, double>(&MSBsplineSurface::EvaluatePoint, py::const_),
           "xyz"_a, "dPdU"_a, "dPdV"_a, "u"_a, "v"_a);

    c1.def("EvaluateAllPartials", &MSBsplineSurface::EvaluateAllPartials, 
           "xyz"_a, "dPdU"_a, "dPdV"_a, "dPdUU"_a, "dPdVV"_a, "dPdUv"_a, "normal"_a, "u"_a, "v"_a);

    c1.def("EvaluatePrincipalCurvature", [] (MSBsplineSurfaceCR self, DPoint3dR xyz, DVec3dR unitA, DVec3dR unitB, double u, double v)
           {
           double curvatureA = 0;
           double curvatureB = 0;
           bool bOk = self.EvaluatePrincipalCurvature(xyz, unitA, curvatureA, unitB, curvatureB, u, v);
           return py::make_tuple(bOk, curvatureA, curvatureB);
           }, "xyz"_a, "unitA"_a, "unitB"_a, "u"_a, "v"_a);

    c1.def("ElevateDegree", &MSBsplineSurface::ElevateDegree, "newDegree"_a, "edge"_a, DOC(Bentley, Geom, MSBsplineSurface, ElevateDegree));
    c1.def("CleanKnots", &MSBsplineSurface::CleanKnots, DOC(Bentley, Geom, MSBsplineSurface, CleanKnots));
    c1.def("RemoveKnotsBounded", &MSBsplineSurface::RemoveKnotsBounded, "dir"_a, "tol"_a, DOC(Bentley, Geom, MSBsplineSurface, RemoveKnotsBounded));
    c1.def("ClosestPoint", &MSBsplineSurface::ClosestPoint, "surfacePoint"_a, "surfaceUV"_a, "spacePoint"_a, DOC(Bentley, Geom, MSBsplineSurface, ClosestPoint));
    c1.def("InitFromPointsAndOrder", &MSBsplineSurface::InitFromPointsAndOrder, "uOrder"_a, "vOrder"_a, "uNumPoles"_a, "vNumPoles"_a, "points"_a, DOC(Bentley, Geom, MSBsplineSurface, InitFromPointsAndOrder));
    c1.def("Clone", &MSBsplineSurface::Clone);
    
    c1.def_static("CreateFromPolesAndOrder", &MSBsplineSurface::CreateFromPolesAndOrder,
                  "pointVector"_a, "weightVector"_a,
                  "uKnotVector"_a, "uOrder"_a, "numUPoints"_a, "uClosed"_a,
                  "vKnotVector"_a, "vOrder"_a, "numVPoints"_a, "vClosed"_a,
                  "inputPolesAlreadyWeighted"_a);
        
    c1.def_static("CreateCatmullRom", &MSBsplineSurface::CreateCatmullRom,
                  "points"_a, "numU"_a, "numV"_a, "uv"_a);

    c1.def_static("CreateLinearSweep", py::overload_cast<ICurvePrimitiveCR, DVec3dCR>(&MSBsplineSurface::CreateLinearSweep), "primitive"_a, "delta"_a, DOC(Bentley, Geom, MSBsplineSurface, CreateLinearSweep));
    c1.def_static("CreateLinearSweep", py::overload_cast<MSBsplineCurveCR, DVec3dCR>(&MSBsplineSurface::CreateLinearSweep), "primitive"_a, "delta"_a, DOC(Bentley, Geom, MSBsplineSurface, CreateLinearSweep));
    c1.def_static("CreateLinearSweep", py::overload_cast<MSBsplineSurfacePtrArray&, CurveVectorCR, DVec3dCR>(&MSBsplineSurface::CreateLinearSweep), "surfaces"_a, "baseCurves"_a, "delta"_a, DOC(Bentley, Geom, MSBsplineSurface, CreateLinearSweep));

    c1.def_static("CreateRuled", &MSBsplineSurface::CreateRuled, "curveA"_a, "curveB"_a, DOC(Bentley, Geom, MSBsplineSurface, CreateRuled));

    c1.def_static("CreateRotationalSweep", 
                  py::overload_cast<ICurvePrimitiveCR, DPoint3dCR, DVec3dCR, double>(&MSBsplineSurface::CreateRotationalSweep), 
                  "primitive"_a, "center"_a, "axis"_a, "sweepRadians"_a);

    c1.def_static("CreateRotationalSweep", 
                  py::overload_cast<MSBsplineCurveCR, DPoint3dCR, DVec3dCR, double>(&MSBsplineSurface::CreateRotationalSweep), 
                  "primitive"_a, "center"_a, "axis"_a, "sweepRadians"_a);

    c1.def_static("CreateRotationalSweep",
                  py::overload_cast<MSBsplineSurfacePtrArray&, CurveVectorCR, DPoint3dCR, DVec3dCR, double>(&MSBsplineSurface::CreateRotationalSweep),
                  "surfaces"_a, "baseCurves"_a, "center"_a, "axis"_a, "sweepRadians"_a);

    c1.def_static("CreateTrimmedDisk", &MSBsplineSurface::CreateTrimmedDisk, "ellipse"_a, DOC(Bentley, Geom, MSBsplineSurface, CreateTrimmedDisk));
    c1.def_static("CreateTubeSurface", &MSBsplineSurface::CreateTubeSurface, "baseCurve"_a, "translateBaseCurve"_a, "traceCurve"_a, DOC(Bentley, Geom, MSBsplineSurface, CreateTubeSurface));

    c1.def("Populate", &MSBsplineSurface::Populate,
           "pointVector"_a, "weightVector"_a,
           "uKnotVector"_a, "uOrder"_a, "numUPoints"_a, "uClosed"_a,
           "vKnotVector"_a, "vOrder"_a, "numVPoints"_a, "vClosed"_a,
           "inputPolesAlreadyWeighted"_a);

    c1.def("MakeOpen", &MSBsplineSurface::MakeOpen, "uv"_a, "direction"_a, DOC(Bentley, Geom, MSBsplineSurface, MakeOpen));
    c1.def("MakeClosed", &MSBsplineSurface::MakeClosed, "direction"_a, DOC(Bentley, Geom, MSBsplineSurface, MakeClosed));
    c1.def("MakeRational", &MSBsplineSurface::MakeRational, DOC(Bentley, Geom, MSBsplineSurface, MakeRational));
    c1.def("SwapUV", &MSBsplineSurface::SwapUV, DOC(Bentley, Geom, MSBsplineSurface, SwapUV));
    c1.def("MakeReversed", &MSBsplineSurface::MakeReversed, "direction"_a, DOC(Bentley, Geom, MSBsplineSurface, MakeReversed));
    c1.def("MakeBezier", &MSBsplineSurface::MakeBezier, "outSurface"_a, DOC(Bentley, Geom, MSBsplineSurface, MakeBezier));
    c1.def("MakeBeziers", &MSBsplineSurface::MakeBeziers, "beziers"_a, DOC(Bentley, Geom, MSBsplineSurface, MakeBeziers));

    c1.def("GetSupport", &MSBsplineSurface::GetSupport, "outPoles"_a, "outUKnots"_a, "outVKnots"_a, "uIndex"_a, "vIndex"_a, DOC(Bentley, Geom, MSBsplineSurface, GetSupport));

    c1.def("GetIntervalCounts", [] (MSBsplineSurfaceCR self)
           {
           size_t numU = 0;
           size_t numV = 0;
           bool bOk = self.GetIntervalCounts(numU, numV);
           return py::make_tuple(bOk, numU, numV);
           });

    c1.def("TransformSurface", py::overload_cast<TransformCR>(&MSBsplineSurface::TransformSurface), "transform"_a, DOC(Bentley, Geom, MSBsplineSurface, TransformSurface));
    c1.def("NormalizeSurface", &MSBsplineSurface::NormalizeSurface, DOC(Bentley, Geom, MSBsplineSurface, NormalizeSurface));
    c1.def("ComputeUniformUKnots", &MSBsplineSurface::ComputeUniformUKnots, DOC(Bentley, Geom, MSBsplineSurface, ComputeUniformUKnots));
    c1.def("ComputeUniformVKnots", &MSBsplineSurface::ComputeUniformVKnots, DOC(Bentley, Geom, MSBsplineSurface, ComputeUniformVKnots));
    c1.def("SetUParamsWithUniformKnots", &MSBsplineSurface::SetUParamsWithUniformKnots, "numPoles"_a, "order"_a, "closed"_a, DOC(Bentley, Geom, MSBsplineSurface, SetUParamsWithUniformKnots));
    c1.def("SetVParamsWithUniformKnots", &MSBsplineSurface::SetVParamsWithUniformKnots, "numPoles"_a, "order"_a, "closed"_a, DOC(Bentley, Geom, MSBsplineSurface, SetVParamsWithUniformKnots));

    c1.def("LoftingSurface", &MSBsplineSurface::LoftingSurface,
           "pCurves"_a, "pStartNormal"_a, "pEndNormal"_a, "numCurves"_a, "approxComp"_a, "closed"_a, "smoothStart"_a, "smoothEnd"_a, "chordLength"_a, "applyComp"_a, "tolerance"_a);
        
    c1.def("ComputePrincipalAreaMoments", [] (MSBsplineSurfaceCR self, DVec3dR centroid, RotMatrixR axes, DVec3dR momentxyz)
           {
           double area = 0;
           bool bOk = self.ComputePrincipalAreaMoments(area, centroid, axes, momentxyz);
           return py::make_tuple(bOk, area);
           }, "centroid"_a, "axes"_a, "momentxyz"_a);

    c1.def("ComputeSecondMomentAreaProducts", py::overload_cast<DMatrix4dR>(&MSBsplineSurface::ComputeSecondMomentAreaProducts, py::const_), "products"_a, DOC(Bentley, Geom, MSBsplineSurface, ComputeSecondMomentAreaProducts));

    c1.def_static("CreateTrimmedSurfaces", 
                  py::overload_cast<MSBsplineSurfacePtrArray&, CurveVectorCR, IFacetOptionsP>(&MSBsplineSurface::CreateTrimmedSurfaces),
                  "surfaces"_a, "source"_a, "options"_a = nullptr);

    c1.def_static("CreateTrimmedSurfaces",
                  py::overload_cast<MSBsplineSurfacePtrArray&, ISolidPrimitiveCR, IFacetOptionsP>(&MSBsplineSurface::CreateTrimmedSurfaces),
                  "surfaces"_a, "source"_a, "options"_a = nullptr);

    c1.def("GetUnstructuredBoundaryCurves",
           py::overload_cast<double, bool>(&MSBsplineSurface::GetUnstructuredBoundaryCurves, py::const_),
           "tolerance"_a, "cubicFit"_a);

    c1.def("GetUnstructuredBoundaryCurves",
           py::overload_cast<double, bool, bool>(&MSBsplineSurface::GetUnstructuredBoundaryCurves, py::const_),
           "tolerance"_a, "cubicFit"_a, "addOuterLoopIfActive"_a);

    c1.def_property_readonly("NumBounds", &MSBsplineSurface::GetNumBounds);
    c1.def("GetNumBounds", &MSBsplineSurface::GetNumBounds);

    c1.def("GetNumPointsInBoundary", &MSBsplineSurface::GetNumPointsInBoundary, "boundaryIndex"_a, DOC(Bentley, Geom, MSBsplineSurface, GetNumPointsInBoundary));

    c1.def("GetBoundaryUV", 
           py::overload_cast<size_t, size_t>(&MSBsplineSurface::GetBoundaryUV, py::const_), 
           "boundaryIndex"_a, "pointIndex"_a);

    c1.def("TryGetBoundaryUV", 
           py::overload_cast<size_t, size_t, DPoint2dR>(&MSBsplineSurface::TryGetBoundaryUV, py::const_), 
           "boundaryIndex"_a, "pointIndex"_a, "uv"_a);

    c1.def("GetUVBoundaryLoops", 
           py::overload_cast<DPoint2dVecArray&, bool>(&MSBsplineSurface::GetUVBoundaryLoops, py::const_), 
           "uvBoundaries"_a, "addOuterLoopsIfActive"_a);

    c1.def("GetUVBoundaryLoops", 
           py::overload_cast<DPoint2dVecArray&, bool, bool>(&MSBsplineSurface::GetUVBoundaryLoops, py::const_), 
           "uvBoundaries"_a, "addOuterLoopsIfActive"_a, "cleanupParity"_a);

    c1.def("FixupBoundaryLoopParity", &MSBsplineSurface::FixupBoundaryLoopParity, DOC(Bentley, Geom, MSBsplineSurface, FixupBoundaryLoopParity));
    c1.def("GetUVBoundaryCurves", &MSBsplineSurface::GetUVBoundaryCurves, "addOuterLoopsIfActive"_a, "preferCurves"_a, DOC(Bentley, Geom, MSBsplineSurface, GetUVBoundaryCurves));
    c1.def("SetTrim", &MSBsplineSurface::SetTrim, "cruves"_a, DOC(Bentley, Geom, MSBsplineSurface, SetTrim));
    c1.def("GetPolygonRowAsCurve", &MSBsplineSurface::GetPolygonRowAsCurve, "index"_a, DOC(Bentley, Geom, MSBsplineSurface, GetPolygonRowAsCurve));
    c1.def("GetPolygonColumnAsCurve", &MSBsplineSurface::GetPolygonColumnAsCurve, "index"_a, DOC(Bentley, Geom, MSBsplineSurface, GetPolygonColumnAsCurve));
    c1.def("GetIsoUCurve", &MSBsplineSurface::GetIsoUCurve, "u"_a, DOC(Bentley, Geom, MSBsplineSurface, GetIsoUCurve));
    c1.def("GetIsoVCurve", &MSBsplineSurface::GetIsoVCurve, "v"_a, DOC(Bentley, Geom, MSBsplineSurface, GetIsoVCurve));
    c1.def("GetIsoULineVIntersections", &MSBsplineSurface::GetIsoULineVIntersections, "u"_a, "vParams"_a, DOC(Bentley, Geom, MSBsplineSurface, GetIsoULineVIntersections));
    c1.def("GetIsoVLineUIntersections", &MSBsplineSurface::GetIsoVLineUIntersections, "v"_a, "uParams"_a, DOC(Bentley, Geom, MSBsplineSurface, GetIsoVLineUIntersections));
    c1.def("GetIsoUCurveSegments", &MSBsplineSurface::GetIsoUCurveSegments, "u"_a, "segments"_a, DOC(Bentley, Geom, MSBsplineSurface, GetIsoUCurveSegments));
    c1.def("GetIsoVCurveSegments", &MSBsplineSurface::GetIsoVCurveSegments, "v"_a, "segments"_a, DOC(Bentley, Geom, MSBsplineSurface, GetIsoVCurveSegments));        

    c1.def("IntersectRay",
           py::overload_cast<DPoint3dArray&, DoubleArray&, DPoint2dArray&, DRay3dCR>(&MSBsplineSurface::IntersectRay, py::const_),
           "intersectionPoints"_a, "rayParameters"_a, "surfaceParameters"_a, "ray"_a);

    c1.def("IntersectRay",
           py::overload_cast<DPoint3dArray&, DoubleArray&, DPoint2dArray&, DRay3dCR, DRange1dCR>(&MSBsplineSurface::IntersectRay, py::const_),
           "intersectionPoints"_a, "rayParameters"_a, "surfaceParameters"_a, "ray"_a, "rayInterval"_a);

    c1.def("HasValidPoleAllocation", &MSBsplineSurface::HasValidPoleAllocation);
    c1.def("HasValidWeightAllocation", &MSBsplineSurface::HasValidWeightAllocation);
    c1.def("HasValidBoundaryAllocation", &MSBsplineSurface::HasValidBoundaryAllocation);
    c1.def("HasValidOrder", &MSBsplineSurface::HasValidOrder);
    c1.def("HasValidPoleCounts", &MSBsplineSurface::HasValidPoleCounts);
    c1.def("HasValidCountsAndAllocations", &MSBsplineSurface::HasValidCountsAndAllocations);

    c1.def("IsSameStructure", &MSBsplineSurface::IsSameStructure, "other"_a, DOC(Bentley, Geom, MSBsplineSurface, IsSameStructure));
    c1.def("IsSameStructureAndGeometry", &MSBsplineSurface::IsSameStructureAndGeometry, "other"_a, "tolerance"_a, DOC(Bentley, Geom, MSBsplineSurface, IsSameStructureAndGeometry));
    c1.def("__copy__", [] (const MSBsplineSurface& self) { return MSBsplineSurface(self); });
    }