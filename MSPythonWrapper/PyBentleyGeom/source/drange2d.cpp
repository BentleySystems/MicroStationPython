/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyBentleyGeom\source\drange2d.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"



static const char * __doc_Bentley_Geom_DRange2d_MoveChangesIntersection =R"doc(Test if a modification of the given (instance) range would have a
different touching relationship with outerRange.

Remark:
    This may only be meaningful in context of range tree tests where
    some prior relationship among ranges is known to apply.

:param (input):
    newRange candidate for modified range relationship.

:param (input):
    outerRange containing range

:returns:
    true if touching condition occurs.)doc";

static const char * __doc_Bentley_Geom_DRange2d_IntersectsWith =R"doc(Test if two ranges have strictly non-null overlap (intersection)

:param (input):
    range2 second range

:returns:
    true if ranges overlap, false if not.)doc";

static const char * __doc_Bentley_Geom_DRange2d_Contains =R"doc( Test if a point is contained in a range.

:param (input):
    point point to test. (z is ignored)

:returns:
    true if the point is in (or on boundary of))doc";

static const char * __doc_Bentley_Geom_DRange2d_IsContained =R"doc(Test if the given range is a (possible improper) subset of outerRange.

:param (input):
    outerRange outer range

:returns:
    true if the given range is a (possibly improper) subset of
    outerRange.)doc";

static const char * __doc_Bentley_Geom_DRange2d_TryRangePointToFractions =R"doc(map a range point to the fractional coordinates. (0,0) is low point,
(1,1) is high point.

:param (output):
    fractions fractional coordinates

:param (input):
    xy computed coordinates.

:returns:
    false if range is null range or single point.)doc";

static const char * __doc_Bentley_Geom_DRange2d_TryFractionsToRangePoint =R"doc(map a fractional point to the range coordinates. (0,0) is low point,
(1,1) is high point.

:param (input):
    fractions fractional coordinates

:param (output):
    xy computed coordinates.

:returns:
    false if range is null range.)doc";

static const char * __doc_Bentley_Geom_DRange2d_IsEqual =R"doc( Test if two ranges are exactly equal.

:param (input):
    range1 second range

:returns:
    true if ranges are identical in all components.)doc";

static const char * __doc_Bentley_Geom_DRange2d_IntersectRay =R"doc(Compute the intersection of a range cube and a ray.

If there is not a finite intersection, both params are set to 0 and
and both points to point0.

:param (output):
    param0 ray parameter where cube is entered

:param (output):
    param1 ray parameter where cube is left

:param (output):
    point0 entry point

:param (output):
    point1 exit point

:param (input):
    start start point of ray

:param (input):
    direction direction of ray

:returns:
    true if non-empty intersection.)doc";

static const char * __doc_Bentley_Geom_DRange2d_Get4Corners =R"doc(Generates a 4 point box around around a range cube. Point ordering is
by " x varies fastest " --- 00, 10, 01, 11 for the unit range.

:param (output):
    box array of 4 points of the box)doc";

static const char * __doc_Bentley_Geom_DRange2d_Get4Lines =R"doc(Extract the 4 bounding lines for a range rectangle, in origin normal
form

:param (output):
    originArray array of line origins

:param (output):
    normalArray array of plane normals. Directions down, left, right,
    up.)doc";

static const char * __doc_Bentley_Geom_DRange2d_YLength =R"doc(Returns difference of high and low in y direction -- 0 if high<low.)doc";

static const char * __doc_Bentley_Geom_DRange2d_XLength =R"doc(Returns difference of high and low in x direction -- 0 if high<low.)doc";

static const char * __doc_Bentley_Geom_DRange2d_Area =R"doc(returns product of axis extents. No test for zero or negative axes.)doc";

static const char * __doc_Bentley_Geom_DRange2d_IsPoint =R"doc(:returns:
    true if high is less than or equal to low in every direction.)doc";

static const char * __doc_Bentley_Geom_DRange2d_IsEmpty =R"doc(Test if high component is (strictly) less than low in any direction.
Note that equal components do not indicate empty. returns true if any
low component is less than the corresponding high component)doc";

static const char * __doc_Bentley_Geom_DRange2d_IntersectionExtentSquared =R"doc(Compute the intersection of given range with another range and return
the extentSquared of the intersection range.

:param (input):
    range2 second range

:returns:
    extentSquared() for the intersection range.)doc";

static const char * __doc_Bentley_Geom_DRange2d_ExtentSquared =R"doc(:returns:
    0 if null range (as decided by IsNull ()), otherwise sum of
    squared axis extents.)doc";

static const char * __doc_Bentley_Geom_DRange2d_IsNull =R"doc(Check if the range is exactly the same as the null ranges returned by
bsiDRange2d_init. (Note that ranges with other values with low> high
are not necessarily null by this condition.))doc";

static const char * __doc_Bentley_Geom_DRange2d_RestrictToMinMax =R"doc(Returns a range which is the intersection of two ranges. The first
range is treated as a signed range, i.e. decreasing values from low to
high are a nonempty range, and the output will maintain the direction.
In a direction where there is no overlap, pRange high and low values
are identical and are at the limit of pRange1 that is nearer to the
values in range0. (Intended use:range0 is the 'actual' stroking range
of a surface i.e. may go 'backwards'. pRange1 is the nominal full
surface range, i.e. is known a priori to be 'forwards'. The clipping
restricts unreliable range0 to the nominal surface range pRange1.
range0 and pRange may be the same address. minMax must be different.

:param (input):
    range0 range to be restricted

:param (input):
    minMax allowable minmax range. Assumed to have low<high)doc";

static const char * __doc_Bentley_Geom_DRange2d_UnionOf =R"doc(Form the union of two ranges.

:param (input):
    range1 first range.

:param (input):
    range2 second range.)doc";

static const char * __doc_Bentley_Geom_DRange2d_IntersectionOf =R"doc(Compute the intersection of two ranges and test if it is nonempty. If
empty (non overlap), result range null range.

Remark:
    In earlier API (bsiDRange2d_intersect, DRange2d::intersectionOf
    (DRange2dCP, DRange2dCP) the result was uninitialized in the no-
    intersection case)

:param (input):
    range1 first range

:param (input):
    range2 second range

:returns:
    same result as checkOverlap(range1,range2).)doc";

static const char * __doc_Bentley_Geom_DRange2d_InitFromUnitArcSweep =R"doc(Initialize the range from an arc of the unit circle

:param (input):
    theta0 start angle

:param (input):
    sweep angular sweep)doc";

static const char * __doc_Bentley_Geom_DRange2d_FromUnitArcSweep =R"doc(Initialize the range from an arc of the unit circle

:param (input):
    theta0 start angle

:param (input):
    sweep angular sweep)doc";

static const char * __doc_Bentley_Geom_DRange2d_Extend =R"doc(Extends the coordinates of the range cube points in pRange so as to
include the single additional point point.

:param (input):
    point new point to be included in the range.)doc";

static const char * __doc_Bentley_Geom_DRange2d_Init =R"doc(Initializes a range cube with (inverted) large positive and negative
values.)doc";

static const char * __doc_Bentley_Geom_DRange2d_NullRange =R"doc(Initializes a range cube with (inverted) large positive and negative
values.)doc";

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_DRange2d(py::module_& m)
    {
    //===================================================================================
    // struct DRange2d
    py::class_<DRange2d> c1(m, "DRange2d");

    c1.def(py::init(&DRange2d::NullRange));
    c1.def_static("NullRange", &DRange2d::NullRange, DOC(Bentley, Geom, DRange2d, NullRange));
    c1.def("Init", &DRange2d::Init, DOC(Bentley, Geom, DRange2d, Init));

    c1.def(py::init(py::overload_cast<DPoint2dCR>(DRange2d::From)), "point_a");
    c1.def(py::init(py::overload_cast<DRange3dCR>(DRange2d::From)), "range"_a);
    c1.def(py::init(py::overload_cast<DPoint3dArray const&>(DRange2d::From)), "points"_a);
    c1.def_static("From", [](py::list const& points) {
        CONVERT_PYLIST_TO_NEW_CPPARRAY(points, cppPoints, DPoint3dArray, DPoint3d);
        return DRange2d::From(cppPoints);
    }, "points"_a);
    c1.def(py::init(py::overload_cast<double, double>(DRange2d::From)), "x"_a, "y"_a);
    c1.def(py::init(py::overload_cast<DPoint2dCR, DPoint2dCR>(DRange2d::From)), "point0"_a, "point1"_a);
    c1.def(py::init(py::overload_cast<double, double, double, double>(DRange2d::From)), "x0"_a, "y0"_a, "x1"_a, "y1"_a);
    c1.def(py::init(py::overload_cast<DPoint2dCR, DPoint2dCR, DPoint2dCR>(DRange2d::From)), "point0"_a, "point1"_a, "point2"_a);
    c1.def(py::init(py::overload_cast<DPoint2dArray const&>(DRange2d::From)), "points"_a);

    c1.def_property("low", [](DRange2d& self) {return self.low; }, [](DRange2d& self, DPoint2dCR low) {return self.low = low; });
    c1.def_property("high", [](DRange2d& self) {return self.high; }, [](DRange2d& self, DPoint2dCR high) {return self.high = high; });

        
    c1.def("Extend", py::overload_cast<DPoint2dCR>(&DRange2d::Extend), "point"_a, DOC(Bentley, Geom, DRange2d, Extend));
    c1.def("Extend", py::overload_cast<DPoint3dCR>(&DRange2d::Extend), "point"_a, DOC(Bentley, Geom, DRange2d, Extend));
    c1.def("Extend", py::overload_cast<DPoint4dCR>(&DRange2d::Extend), "point"_a, DOC(Bentley, Geom, DRange2d, Extend));
    c1.def("Extend", py::overload_cast<double, double>(&DRange2d::Extend), "x"_a, "y"_a, DOC(Bentley, Geom, DRange2d, Extend));

    c1.def("Extend", [] (DRange2dR self, DPoint2dArray const& points)
           {
           if (!points.empty())
               self.Extend(points.data(), (int)points.size());
           }, "points"_a, DOC(Bentley, Geom, DRange2d, Extend));

    c1.def("Extend", py::overload_cast<double>(&DRange2d::Extend), "extend"_a, DOC(Bentley, Geom, DRange2d, Extend));
    c1.def("Extend", py::overload_cast<DRange2dCR>(&DRange2d::Extend), "rangeB"_a, DOC(Bentley, Geom, DRange2d, Extend));

    c1.def_static("FromUnitArcSweep", &DRange2d::FromUnitArcSweep, "theta0"_a, "sweep"_a, DOC(Bentley, Geom, DRange2d, FromUnitArcSweep));
    c1.def("InitFromUnitArcSweep", &DRange2d::InitFromUnitArcSweep, "theta0"_a, "sweep"_a, DOC(Bentley, Geom, DRange2d, InitFromUnitArcSweep));

    c1.def("IntersectionOf", &DRange2d::IntersectionOf, "range1"_a, "range2"_a, DOC(Bentley, Geom, DRange2d, IntersectionOf));

    c1.def("UnionOf", &DRange2d::UnionOf, "range1"_a, "range2"_a, DOC(Bentley, Geom, DRange2d, UnionOf));

    c1.def("RestrictToMinMax", &DRange2d::RestrictToMinMax, "range0"_a, "minMax"_a, DOC(Bentley, Geom, DRange2d, RestrictToMinMax));

    c1.def("IsNull", &DRange2d::IsNull, DOC(Bentley, Geom, DRange2d, IsNull));
    c1.def("ExtentSquared", &DRange2d::ExtentSquared, DOC(Bentley, Geom, DRange2d, ExtentSquared));

    c1.def("IntersectionExtentSquared", &DRange2d::IntersectionExtentSquared, "range2"_a, DOC(Bentley, Geom, DRange2d, IntersectionExtentSquared));

    c1.def("IsEmpty", &DRange2d::IsEmpty, DOC(Bentley, Geom, DRange2d, IsEmpty));
    c1.def("IsPoint", &DRange2d::IsPoint, DOC(Bentley, Geom, DRange2d, IsPoint));
    c1.def("Area", &DRange2d::Area, DOC(Bentley, Geom, DRange2d, Area));
    c1.def("XLength", &DRange2d::XLength, DOC(Bentley, Geom, DRange2d, XLength));
    c1.def("YLength", &DRange2d::YLength, DOC(Bentley, Geom, DRange2d, YLength));

    c1.def("Get4Lines", [] (DRange2dCR self, DPoint2dArray& originArray, DPoint2dArray& normalArray)
           {
           if (originArray.size() < 4)
               originArray.resize(4);
           if (normalArray.size() < 4)
               normalArray.resize(4);

           self.Get4Lines(originArray.data(), normalArray.data());
           }, "originalArray"_a, "normalArray"_a, DOC(Bentley, Geom, DRange2d, Get4Lines));

    c1.def("Get4Corners", [] (DRange2dCR self, DPoint2dArray& box)
           {
           if (box.size() < 4)
               box.resize(4);
           self.Get4Corners(box.data());
           }, "box"_a, DOC(Bentley, Geom, DRange2d, Get4Corners));

    c1.def("IntersectRay", [] (DRange2dCR self, DPoint2dCR start, DPoint2dCR direction)
           {
           double param0 = 0;
           double param1 = 0;
           DPoint2d point0 = DPoint2d::FromZero();
           DPoint2d point1 = DPoint2d::FromZero();
           bool bOk = self.IntersectRay(param0, param1, point0, point1, start, direction);
           return py::make_tuple(bOk, param0, param1, point0, point1);
           }, "start"_a, "direction"_a, DOC(Bentley, Geom, DRange2d, IntersectRay));

    c1.def("IsEqual", py::overload_cast<DRange2dCR>(&DRange2d::IsEqual, py::const_), "range1"_a, DOC(Bentley, Geom, DRange2d, IsEqual));
    c1.def("IsEqual", py::overload_cast<DRange2dCR, double>(&DRange2d::IsEqual, py::const_), "range1"_a, "tolerance"_a, DOC(Bentley, Geom, DRange2d, IsEqual));

    c1.def("TryFractionsToRangePoint", &DRange2d::TryFractionsToRangePoint, "fractions"_a, "xy"_a, DOC(Bentley, Geom, DRange2d, TryFractionsToRangePoint));
    c1.def("TryRangePointToFractions", &DRange2d::TryRangePointToFractions, "xy"_a, "fractions"_a, DOC(Bentley, Geom, DRange2d, TryRangePointToFractions));

    c1.def("IsContained", &DRange2d::IsContained, "outerRange"_a, DOC(Bentley, Geom, DRange2d, IsContained));
    c1.def("Contains", py::overload_cast<DPoint3dCR>(&DRange2d::Contains, py::const_), "point"_a, DOC(Bentley, Geom, DRange2d, Contains));
    c1.def("Contains", py::overload_cast<DPoint2dCR>(&DRange2d::Contains, py::const_), "point"_a, DOC(Bentley, Geom, DRange2d, Contains));
    c1.def("Contains", py::overload_cast<double, double>(&DRange2d::Contains, py::const_), "x"_a, "y"_a, DOC(Bentley, Geom, DRange2d, Contains));

    c1.def("IntersectsWith", py::overload_cast<DRange2dCR>(&DRange2d::IntersectsWith, py::const_), "range2"_a, DOC(Bentley, Geom, DRange2d, IntersectsWith));
    c1.def("MoveChangesIntersection", &DRange2d::MoveChangesIntersection, "newRange"_a, "outerRange"_a, DOC(Bentley, Geom, DRange2d, MoveChangesIntersection));   

    c1.def("__repr__", [] (DRange2d& self) { return "[low:{}, high:{}]"_s.format(self.low, self.high); });
    c1.def("__copy__", [] (const DRange2d& self) { return DRange2d(self); });
    }