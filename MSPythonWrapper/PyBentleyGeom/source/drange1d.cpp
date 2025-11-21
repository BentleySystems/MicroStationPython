/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyBentleyGeom\source\drange1d.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"



static const char * __doc_Bentley_Geom_DRange1d_UpdateRay1dIntersection =R"doc(Update a bounding interval of a line based on the variation of that
line within one dimension. The ray parameterized{x = x0+s*dxdx} The
instance is an{s} range that is live. This is usually initialized to
InfiniteRange before clipping.{xA,xB} is an interval of the{x}
space. (xA and xB are not required to be sorted.}

:param (input):
    x0 ray start coordinate in this dimension

:param (input):
    dxds Rate of change of ray in this dimension.

:param (input):
    xA x limit

:param (input):
    xB x limit.

:returns:
    true if interval is nonempty at return.)doc";

static const char * __doc_Bentley_Geom_DRange1d_LengthSum =R"doc( Sum the interval lengths)doc";

static const char * __doc_Bentley_Geom_DRange1d_IsIncreasing =R"doc( Test for increasing relationships, optionally allowing
zero length.)doc";

static const char * __doc_Bentley_Geom_DRange1d_DifferenceSorted =R"doc( Intersect intervals in two pre-sorted sets. Output may
NOT be the same as either input.)doc";

static const char * __doc_Bentley_Geom_DRange1d_UnionSorted =R"doc( Union of intervals in two pre-sorted sets. Output may NOT
be the same as either input.)doc";

static const char * __doc_Bentley_Geom_DRange1d_IntersectSorted =R"doc( Intersect intervals in two pre-sorted sets. Output may
NOT be the same as either input.)doc";

static const char * __doc_Bentley_Geom_DRange1d_ClipInPlace =R"doc( Intersect each range in dataA with clipper. Retain non-
empty result parts.)doc";

static const char * __doc_Bentley_Geom_DRange1d_AppendClips =R"doc( Intersect each range in dataA with clipper. Append non-
empty results to dataOut. Note that if the same array is passed for
dataA and dataOut, all input contents will remain. (Use{ClipInPlace}
to get compaction))doc";

static const char * __doc_Bentley_Geom_DRange1d_FromExtent =R"doc( Return the encompassing single range.)doc";

static const char * __doc_Bentley_Geom_DRange1d_SimplifyInPlace =R"doc( Combine intervals so there are no overlaps.)doc";

static const char * __doc_Bentley_Geom_DRange1d_SortLowInPlace =R"doc( Sort on low values.)doc";

static const char * __doc_Bentley_Geom_DRange1d_GetTolerance =R"doc( return a tolerance computed as{absTol + localRelTol *
Extent() + globalRelTol * MaxAbs ()})doc";

static const char * __doc_Bentley_Geom_DRange1d_DoubleToFraction =R"doc( map real to fraction. Returns false if null range or
single point.)doc";

static const char * __doc_Bentley_Geom_DRange1d_FractionToDouble =R"doc( map fractional coordinate to real. Returns false if null
range.)doc";

static const char * __doc_Bentley_Geom_DRange1d_IsEqualLowHigh =R"doc( Direct equality test for low and high parts.)doc";

static const char * __doc_Bentley_Geom_DRange1d_IsEqualInterval =R"doc( Test if equal intervals in point set sense. Any pair of
empty intervals (even if different low and high) are equal.)doc";

static const char * __doc_Bentley_Geom_DRange1d_MaxAbs =R"doc( return the largest coordinate (absolute value) in the
range.)doc";

static const char * __doc_Bentley_Geom_DRange1d_HasPositiveLengthIntersectionWith =R"doc( Test if the instance range has a positive-length (more
than single point) intersection with{other}.)doc";

static const char * __doc_Bentley_Geom_DRange1d_HasNonEmptyIntersectionWith =R"doc( Test if the instance range is a (possibly complete, but
not empty) subset of{other} range.)doc";

static const char * __doc_Bentley_Geom_DRange1d_IsSubsetOf =R"doc( Test if the instance range is a (possibly complete,
possibly empty) subset of{other} range.)doc";

static const char * __doc_Bentley_Geom_DRange1d_StrictlyNonEmptyFractionalIntersection =R"doc( Compute intersection of the instance with rangeB. Return
the intersection as fractions of the instance.

:returns:
    true if the fractional intersection is more than single point.)doc";

static const char * __doc_Bentley_Geom_DRange1d_FromUnion =R"doc( return the (possibly null) union of two ranges.)doc";

static const char * __doc_Bentley_Geom_DRange1d_FromIntersection =R"doc( return the (possibly null) intersection of two ranges.)doc";

static const char * __doc_Bentley_Geom_DRange1d_IntersectInPlace =R"doc( Restrict to overlap with another (possibly null!!) range.)doc";

static const char * __doc_Bentley_Geom_DRange1d_ExtendBySignedShift =R"doc(If non empty, shift endpoints by (-tol, +tol). No change if empty !!!)doc";

static const char * __doc_Bentley_Geom_DRange1d_Extend =R"doc( Extend to include a value.)doc";

static const char * __doc_Bentley_Geom_DRange1d_Contains =R"doc( Test if the range contains a given value.)doc";

static const char * __doc_Bentley_Geom_DRange1d_Length =R"doc( Return{MAX(0, high - low)} The DRange1::NullRange
returns 0. A single-point interval returns 0. An interval with{high <
low} returns 0. Normal case returns{high - low})doc";

static const char * __doc_Bentley_Geom_DRange1d_High =R"doc(Get the low limit (unchecked).)doc";

static const char * __doc_Bentley_Geom_DRange1d_Low =R"doc(Get the low limit (unchecked).)doc";

static const char * __doc_Bentley_Geom_DRange1d_IsDoublyInfinite =R"doc( Test if the range has the most negative{low} and most
positive{high})doc";

static const char * __doc_Bentley_Geom_DRange1d_IsInfiniteNegative =R"doc( Test if the range has the most negative possible{low})doc";

static const char * __doc_Bentley_Geom_DRange1d_IsInfinitePositive =R"doc( Test if the range has the largest possible{high})doc";

static const char * __doc_Bentley_Geom_DRange1d_IsPositiveLength =R"doc( Test if the range has{high> low}, i.e. has a non-empty
set of points with properly sorted lower and upper limit.)doc";

static const char * __doc_Bentley_Geom_DRange1d_IsSinglePoint =R"doc( Test if the range is a single point.)doc";

static const char * __doc_Bentley_Geom_DRange1d_IsEmptyOrSinglePoint =R"doc( Test if the range has{high >= low}, i.e. is empty or
just one point.)doc";

static const char * __doc_Bentley_Geom_DRange1d_IsEmpty =R"doc( Test if the range has{low> high}, i.e. there are no x
for which{low &le x && x &le high})doc";

static const char * __doc_Bentley_Geom_DRange1d_IsNull =R"doc( Test if the range is exactly the same as the null ranges
returned by NullRange ().)doc";

static const char * __doc_Bentley_Geom_DRange1d_FromAltitudes =R"doc( Return a (sorted) range of altitudes of points.)doc";

static const char * __doc_Bentley_Geom_DRange1d_From =R"doc( Return a range containing a single value.)doc";

static const char * __doc_Bentley_Geom_DRange1d_InitNull =R"doc( Set this range to the{NullRange})doc";

static const char * __doc_Bentley_Geom_DRange1d_ZeroAndNegativeRange =R"doc( Return a complete 0 and negative range (-DBL_MAX to 0))doc";

static const char * __doc_Bentley_Geom_DRange1d_ZeroAndPositiveRange =R"doc( Return a complete 0 and positive range (0 to DBL_MAX))doc";

static const char * __doc_Bentley_Geom_DRange1d_InfiniteRange =R"doc( Return a complete range (-DBL_MAX to DBL_MAX))doc";

static const char * __doc_Bentley_Geom_DRange1d_NullRange =R"doc( Return a range which satisfies IsNull ())doc";

static const char * __doc_Bentley_Geom_DRange1d_FromLowHigh =R"doc( Return a range with explicit (possibly reversed) low and
high.)doc";

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_DRange1d(py::module_& m)
    {
    //===================================================================================
    // struct DRange1d
    py::class_<DRange1d> c1(m, "DRange1d");
    py::bind_vector<DRange1dArray>(m, "DRange1dArray", py::module_local(false));

    c1.def(py::init<>());
    c1.def(py::init<double, double>(), "low"_a, "high"_a);
    c1.def(py::init<DRange1dCR>(), "source"_a);
    
    c1.def_static("FromLowHigh", &DRange1d::FromLowHigh, "low"_a, "high"_a, DOC(Bentley, Geom, DRange1d, FromLowHigh));
    c1.def_static("NullRange", &DRange1d::NullRange, DOC(Bentley, Geom, DRange1d, NullRange));
    c1.def_static("InfiniteRange", &DRange1d::InfiniteRange, DOC(Bentley, Geom, DRange1d, InfiniteRange));            
    c1.def_static("ZeroAndPositiveRange", &DRange1d::ZeroAndPositiveRange, DOC(Bentley, Geom, DRange1d, ZeroAndPositiveRange));            
    c1.def_static("ZeroAndNegativeRange", &DRange1d::ZeroAndNegativeRange, DOC(Bentley, Geom, DRange1d, ZeroAndNegativeRange));

    c1.def("InitNull", &DRange1d::InitNull, DOC(Bentley, Geom, DRange1d, InitNull));

    c1.def_static("From", py::overload_cast<double>(&DRange1d::From), "value"_a, DOC(Bentley, Geom, DRange1d, From));
    c1.def_static("From", py::overload_cast<double, double>(&DRange1d::From), "valueA"_a, "valueB"_a, DOC(Bentley, Geom, DRange1d, From));
    c1.def_static("From", py::overload_cast<double, double, double>(&DRange1d::From), "valueA"_a, "valueB"_a, "valueC"_a, DOC(Bentley, Geom, DRange1d, From));
    c1.def_static("From", [] (std::vector<double>& values) { return DRange1d::From(values.data(), values.size()); });
    c1.def_static("FromAltitudes", &DRange1d::FromAltitudes, "points"_a, "plane"_a, DOC(Bentley, Geom, DRange1d, FromAltitudes));

    c1.def("IsNull", &DRange1d::IsNull, DOC(Bentley, Geom, DRange1d, IsNull));
    c1.def("IsEmpty", &DRange1d::IsEmpty, DOC(Bentley, Geom, DRange1d, IsEmpty));
    c1.def("IsEmptyOrSinglePoint", &DRange1d::IsEmptyOrSinglePoint, DOC(Bentley, Geom, DRange1d, IsEmptyOrSinglePoint));
    c1.def("IsSinglePoint", py::overload_cast<>(&DRange1d::IsSinglePoint, py::const_), DOC(Bentley, Geom, DRange1d, IsSinglePoint));
    c1.def("IsSinglePoint", py::overload_cast<double>(&DRange1d::IsSinglePoint, py::const_), "value");
    c1.def("IsPositiveLength", &DRange1d::IsPositiveLength, DOC(Bentley, Geom, DRange1d, IsPositiveLength));
    c1.def("IsInfinitePositive", &DRange1d::IsInfinitePositive, DOC(Bentley, Geom, DRange1d, IsInfinitePositive));
    c1.def("IsInfiniteNegative", &DRange1d::IsInfiniteNegative, DOC(Bentley, Geom, DRange1d, IsInfiniteNegative));
    c1.def("IsDoublyInfinite", &DRange1d::IsDoublyInfinite, DOC(Bentley, Geom, DRange1d, IsDoublyInfinite));

    c1.def("Low", &DRange1d::Low, DOC(Bentley, Geom, DRange1d, Low));
    c1.def("High", &DRange1d::High, DOC(Bentley, Geom, DRange1d, High));
    c1.def("Length", &DRange1d::Length, DOC(Bentley, Geom, DRange1d, Length));

    c1.def("Contains", &DRange1d::Contains, "a"_a, DOC(Bentley, Geom, DRange1d, Contains));

    c1.def("Extend", py::overload_cast<double>(&DRange1d::Extend), "valueA"_a, DOC(Bentley, Geom, DRange1d, Extend));
    c1.def("Extend", py::overload_cast<double, double>(&DRange1d::Extend), "valueA"_a, "valueB"_a, DOC(Bentley, Geom, DRange1d, Extend));
    c1.def("Extend", py::overload_cast<DoubleArray&>(&DRange1d::Extend), "values"_a, DOC(Bentley, Geom, DRange1d, Extend));
    c1.def("Extend", [](DRange1d& self, py::list& values){
        CONVERT_PYLIST_TO_NEW_CPPARRAY(values, cppValues, DoubleArray, double);
        self.Extend(cppValues);
        CONVERT_CPPARRAY_TO_PYLIST(values, cppValues, DoubleArray, double);
    }, "values"_a, DOC(Bentley, Geom, DRange1d, Extend));
    c1.def("Extend", py::overload_cast<DRange1dCR>(&DRange1d::Extend), "other"_a, DOC(Bentley, Geom, DRange1d, Extend));

    c1.def("ExtendBySignedShift", &DRange1d::ExtendBySignedShift, "tol"_a, DOC(Bentley, Geom, DRange1d, ExtendBySignedShift));

    c1.def("IntersectInPlace", &DRange1d::IntersectInPlace, "other"_a, DOC(Bentley, Geom, DRange1d, IntersectInPlace));

    c1.def_static("FromIntersection", py::overload_cast<DRange1dCR, DRange1dCR>(&DRange1d::FromIntersection), "rangeA"_a, "rangeB"_a, DOC(Bentley, Geom, DRange1d, FromIntersection));
    c1.def_static("FromIntersection", py::overload_cast<DRange1dArray&>(&DRange1d::FromIntersection), "data"_a, DOC(Bentley, Geom, DRange1d, FromIntersection));   
    c1.def_static("FromIntersection", [](py::list& data){
        CONVERT_PYLIST_TO_NEW_CPPARRAY(data, cppData, DRange1dArray, DRange1d);
        return DRange1d::FromIntersection(cppData);
    }, "data"_a, DOC(Bentley, Geom, DRange1d, FromIntersection));                     
    c1.def_static("FromUnion", &DRange1d::FromUnion, "rangeA"_a, "rangeB"_a, DOC(Bentley, Geom, DRange1d, FromUnion));

    c1.def("StrictlyNonEmptyFractionalIntersection", &DRange1d::StrictlyNonEmptyFractionalIntersection, "rangeB"_a, "fractionalIntersection"_a, DOC(Bentley, Geom, DRange1d, StrictlyNonEmptyFractionalIntersection));

    c1.def("IsSubsetOf", &DRange1d::IsSubsetOf, "other"_a, DOC(Bentley, Geom, DRange1d, IsSubsetOf));            
    c1.def("HasNonEmptyIntersectionWith", &DRange1d::HasNonEmptyIntersectionWith, "other"_a, DOC(Bentley, Geom, DRange1d, HasNonEmptyIntersectionWith));            
    c1.def("HasPositiveLengthIntersectionWith", &DRange1d::HasPositiveLengthIntersectionWith, "other"_a, DOC(Bentley, Geom, DRange1d, HasPositiveLengthIntersectionWith));

    c1.def("MaxAbs", &DRange1d::MaxAbs, "defaultValeForNullRange"_a = 0.0, DOC(Bentley, Geom, DRange1d, MaxAbs));
    c1.def("IsEqualInterval", &DRange1d::IsEqualInterval, "other"_a, DOC(Bentley, Geom, DRange1d, IsEqualInterval));
    c1.def("IsEqualLowHigh", &DRange1d::IsEqualLowHigh, "other"_a, DOC(Bentley, Geom, DRange1d, IsEqualLowHigh));    
            
    c1.def("FractionToDouble", [] (DRange1dCR self, double fraction, double defaultReturnX)
           {
           double x = 0.0;
           bool bOk = self.FractionToDouble(fraction, x, defaultReturnX);
           return py::make_tuple(bOk, x);
           }, "fraction"_a, "defaultReturnX"_a = 0.0, DOC(Bentley, Geom, DRange1d, FractionToDouble));

    c1.def("DoubleToFraction", [] (DRange1dCR self, double x, double defaultReturnX)
           {
           double fraction = 0.0;
           bool bOk = self.DoubleToFraction(x, fraction, defaultReturnX);
           return py::make_tuple(bOk, fraction);
           }, "x"_a, "defaultReturnX"_a = 0.0, DOC(Bentley, Geom, DRange1d, DoubleToFraction));

    c1.def("GetTolerance", &DRange1d::GetTolerance, "absTol"_a = 1.0e-14, "localRelTol"_a = 1.0e-14, "globalRelTol"_a = 0.0, DOC(Bentley, Geom, DRange1d, GetTolerance));

    c1.def_static("SortLowInPlace", &DRange1d::SortLowInPlace, "data"_a, DOC(Bentley, Geom, DRange1d, SortLowInPlace));
    c1.def_static("SimplifyInPlace", &DRange1d::SimplifyInPlace, "data"_a, DOC(Bentley, Geom, DRange1d, SimplifyInPlace));
    c1.def_static("FromExtent", &DRange1d::FromExtent, "data"_a, DOC(Bentley, Geom, DRange1d, FromExtent));
    c1.def_static("AppendClips", &DRange1d::AppendClips, "dataA"_a, "clipper"_a, "dataOut"_a, DOC(Bentley, Geom, DRange1d, AppendClips));
    c1.def_static("ClipInPlace", &DRange1d::ClipInPlace, "dataA"_a, "clipper"_a, DOC(Bentley, Geom, DRange1d, ClipInPlace));            
    c1.def_static("IntersectSorted", &DRange1d::IntersectSorted, "dataA"_a, "dataB"_a, "dataOut"_a, DOC(Bentley, Geom, DRange1d, IntersectSorted));
    c1.def_static("UnionSorted", &DRange1d::UnionSorted, "dataA"_a, "dataB"_a, "dataOut"_a, DOC(Bentley, Geom, DRange1d, UnionSorted));
    c1.def_static("DifferenceSorted", &DRange1d::DifferenceSorted, "dataA"_a, "dataB"_a, "dataOut"_a, DOC(Bentley, Geom, DRange1d, DifferenceSorted));
    c1.def_static("IsIncreasing", &DRange1d::IsIncreasing, "data"_a, "allowZeroLength"_a = false, "allowZeroGaps"_a = false, DOC(Bentley, Geom, DRange1d, IsIncreasing));
    c1.def_static("LengthSum", &DRange1d::LengthSum, "data"_a, DOC(Bentley, Geom, DRange1d, LengthSum));

    c1.def("UpdateRay1dIntersection", &DRange1d::UpdateRay1dIntersection, "x0"_a, "dxds"_a, "xA"_a, "xB"_a, DOC(Bentley, Geom, DRange1d, UpdateRay1dIntersection));

    c1.def("__repr__", [] (DRange1d& self) { return "[low:{}, high:{}]"_s.format(self.low, self.high); });
    c1.def("__copy__", [](const DRange1d& self) { return DRange1d(self); });
    }