/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyBentleyGeom\source\DoubleOps.cpp $
|
|  $Copyright: (c) 2024 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/

#include "MSPythonPCH.h"
#include <Geom/DPoint3dOps.h>

#define __EXPAND(x)                                      x
#define __COUNT(_1, _2, _3, _4, _5, _6, _7, COUNT, ...)  COUNT
#define __VA_SIZE(...)                                   __EXPAND(__COUNT(__VA_ARGS__, 7, 6, 5, 4, 3, 2, 1, 0))
#define __CAT1(a, b)                                     a ## b
#define __CAT2(a, b)                                     __CAT1(a, b)
#define __DOC1(n1)                                       __doc_##n1
#define __DOC2(n1, n2)                                   __doc_##n1##_##n2
#define __DOC3(n1, n2, n3)                               __doc_##n1##_##n2##_##n3
#define __DOC4(n1, n2, n3, n4)                           __doc_##n1##_##n2##_##n3##_##n4
#define __DOC5(n1, n2, n3, n4, n5)                       __doc_##n1##_##n2##_##n3##_##n4##_##n5
#define __DOC6(n1, n2, n3, n4, n5, n6)                   __doc_##n1##_##n2##_##n3##_##n4##_##n5##_##n6
#define __DOC7(n1, n2, n3, n4, n5, n6, n7)               __doc_##n1##_##n2##_##n3##_##n4##_##n5##_##n6##_##n7
#define DOC(...)                                         __EXPAND(__EXPAND(__CAT2(__DOC, __VA_SIZE(__VA_ARGS__)))(__VA_ARGS__))

static const char* __doc_Bentley_Geom_VectorOps_Copy = R"doc(@description Copy from source to destination. destination is cleared
first. Either array may be null.)doc";

static const char* __doc_Bentley_Geom_VectorOps_AppendPrefix = R"doc(append source to dest, return first index)doc";

static const char* __doc_Bentley_Geom_VectorOps_Set = R"doc(Set with checked array pointer and index)doc";

static const char* __doc_Bentley_Geom_VectorOps_Get = R"doc(Get with checked array pointer and index)doc";

static const char* __doc_Bentley_Geom_VectorOps_AppendInterpolated = R"doc(Add uniformly spaced interpolated points between limits.

Parameter ``[inout]``:
    dest vector to receive values

Parameter ``[in]``:
    first first value. If {includeFirst} is true, this point is added
    explicitly.

Parameter ``[in]``:
    last last value

Parameter ``[in]``:
    count number of values to add AFTER the optional first point.

Parameter ``[in]``:
    includeFirst true to include the first point directly.

Remark:
    When inserting points on segments of a polyline, settig
    includeFirst false is useful to prevent replication of
    intermediate vertices.)doc";

static const char* __doc_Bentley_Geom_VectorOps_InterpolateAll = R"doc(Interpolate between T values in dataA and dataB.

Parameter ``[inout]``:
    dest returned with min(dataA.size{}, dataB.size()) interpolated
    values.

Parameter ``[in]``:
    dataA first input array

Parameter ``[in]``:
    f interpolation fraction

Parameter ``[in]``:
    dataB second input array)doc";

static const char* __doc_Bentley_Geom_VectorOps_MallocAndCopy = R"doc(Copy data to the heap as allocated by BSIBaseGeom::Malloc.

Parameter ``[in]``:
    source source data.

Returns:
    NULL if empty array, otherwise pointer to allocated and filled
    heap memory.)doc";

static const char* __doc_Bentley_Geom_VectorOps_Compress = R"doc(Inplace removal of near-duplicate points.

Parameter ``[inout]``:
    data soure data. count is reduced when points are eliminated.

Parameter ``[in]``:
    tolerance for comparison via AlmostEqual (a,b,tolerance))doc";

static const char* __doc_Bentley_Geom_VectorOps_CompressCyclic = R"doc(Inplace removal of near-duplicate points via Compress, followed by
removal of trailing points that match source[0]

Parameter ``[inout]``:
    data soure data.

Parameter ``[in]``:
    tolerance for comparison via AlmostEqual (a,b,tolerance))doc";

static const char* __doc_Bentley_Geom_VectorOps_Compress1 = R"doc(Inplace removal of near-duplicate points.

Parameter ``[inout]``:
    source soure data.

Parameter ``[inout]``:
    dest array to be cleared and loaded.

Parameter ``[in]``:
    tolerance for comparison via AlmostEqual (a,b,tolerance))doc";

static const char* __doc_Bentley_Geom_VectorOps_Reverse = R"doc(@description Reverse all points in the vector.)doc";

static const char* __doc_Bentley_Geom_VectorOps_LargestCoordinate = R"doc(@description return the largest absolute coordinate in the array.)doc";

static const char* __doc_Bentley_Geom_VectorOps_Tolerance = R"doc(@description return a tolerance as an absolute tolerance plus relative
tolerance times largest coordinate.)doc";

static const char* __doc_Bentley_Geom_VectorOps_Equal = R"doc(@description Test if all members are exactly equal.)doc";

static const char* __doc_Bentley_Geom_VectorOps_FindNotAlmostEqualAtOrAfter = R"doc(Search for [i0..] for index i1 at which the array value is not
AlmostEqual to the given value.)doc";

static const char* __doc_Bentley_Geom_VectorOps_FindNotAlmostEqualBefore = R"doc(Search for [i0-1..(downward)] for index i1 at which the array value is
not AlmostEqual to the given value.)doc";

static const char* __doc_Bentley_Geom_VectorOps_AlmostEqual = R"doc(Near equality test with default Angle::SmallAngle absolute and
relative tolerances.)doc";

static const char* __doc_Bentley_Geom_VectorOps_AlmostEqual1 = R"doc(Near equality test.

Parameter ``[in]``:
    valueA first value

Parameter ``[in]``:
    valueB second value

Parameter ``[in]``:
    tolerance Allowable variation. If zero or negative, default to
    AlmostEqual(valueA, valueB))doc";

static const char* __doc_Bentley_Geom_VectorOps_AlmostEqual2 = R"doc(Near equality test.

Parameter ``[in]``:
    valueA first array.

Parameter ``[in]``:
    numA first count

Parameter ``[in]``:
    valueB second array

Parameter ``[in]``:
    numB second count

Parameter ``[in]``:
    tolerance Allowable variation. If zero or negative, default to
    AlmostEqual(valueA, valueB))doc";

static const char* __doc_Bentley_Geom_VectorOps_MostDistantIndex = R"doc(Find the index of the value most distance from baseValue. Return
SIZE_MAX if empty array.)doc";

static const char* __doc_Bentley_Geom_DPoint2dOps_AppendXY = R"doc(Append xy parts.)doc";

static const char* __doc_Bentley_Geom_DPoint2dOps_Cluster = R"doc(@description Find nearly-identical points. Pack the coordinates down.

Parameter ``[in]``:
    xyzIn array of points. Coordinates are shuffled and array resized.

Parameter ``[out]``:
    xyzOut optional array to receive packed points. May NOT alias
    xyzIn.

Parameter ``[out]``:
    oldIndexToPackedIndex For each original index, indicates the
    point's position in the resized array.

Parameter ``[in]``:
    absTol optional absolute tolerance. Negative value requests
    default. Zero is an allowable non-default value.

Parameter ``[in]``:
    relTol optional relative tolerance. Negative value requests
    default. Zero is an allowable non-default value.)doc";

static const char* __doc_Bentley_Geom_DPoint2dOps_Multiply = R"doc(Multiply each (non-disconnect) point in place by a transform.

Parameter ``[out]``:
    xyz array of points, may have disconnects

Parameter ``[in]``:
    transform transform to apply.)doc";

static const char* __doc_Bentley_Geom_DPoint2dOps_LexicalXExtrema = R"doc(Return indices where min and max y of lexical sort order occur.)doc";

static const char* __doc_Bentley_Geom_DPoint2dOps_LexicalYExtrema = R"doc(Return indices where min and max y of lexical sort order occur.)doc";

static const char* __doc_Bentley_Geom_DVec3dOps_Cluster = R"doc(@description Find nearly-identical points. Pack the coordinates down.

Parameter ``[in]``:
    xyzIn array of points. Coordinates are shuffled and array resized.

Parameter ``[out]``:
    xyzOut optional array to receive packed points. May NOT alias
    xyzIn.

Parameter ``[out]``:
    oldIndexToPackedIndex For each original index, indicates the
    point's position in the resized array.

Parameter ``[in]``:
    absTol optional absolute tolerance. Negative value requests
    default. Zero is an allowable non-default value.

Parameter ``[in]``:
    relTol optional relative tolerance. Negative value requests
    default. Zero is an allowable non-default value.)doc";

static const char* __doc_Bentley_Geom_DVec3dOps_MinMaxAngle = R"doc(Find the min and max distances and their index positions.)doc";

static const char* __doc_Bentley_Geom_DoubleOps_Min = R"doc(min of 2 candidates)doc";

static const char* __doc_Bentley_Geom_DoubleOps_Min1 = R"doc(min of 3 candidates)doc";

static const char* __doc_Bentley_Geom_DoubleOps_Min2 = R"doc(min of 4 candidates)doc";

static const char* __doc_Bentley_Geom_DoubleOps_MinAbs = R"doc(min absolute value of 2 candidates)doc";

static const char* __doc_Bentley_Geom_DoubleOps_MinAbs1 = R"doc(min absolute value of 3 candidates)doc";

static const char* __doc_Bentley_Geom_DoubleOps_MinAbs2 = R"doc(min absolute value of 4 candidates)doc";

static const char* __doc_Bentley_Geom_DoubleOps_Max = R"doc(min of 2 candidates)doc";

static const char* __doc_Bentley_Geom_DoubleOps_Max1 = R"doc(min of 3 candidates)doc";

static const char* __doc_Bentley_Geom_DoubleOps_Max2 = R"doc(min of 4 candidates)doc";

static const char* __doc_Bentley_Geom_DoubleOps_MaxAbs = R"doc(min absolute value of 2 candidates)doc";

static const char* __doc_Bentley_Geom_DoubleOps_MaxAbs1 = R"doc(min absolute value of 3 candidates)doc";

static const char* __doc_Bentley_Geom_DoubleOps_MaxAbs2 = R"doc(min absolute value of 4 candidates)doc";

static const char* __doc_Bentley_Geom_DoubleOps_MaxAbs3 = R"doc(min absolute value of 6 candidates)doc";

static const char* __doc_Bentley_Geom_DoubleOps_UpdateMax = R"doc(update an evolving max value.)doc";

static const char* __doc_Bentley_Geom_DoubleOps_WithinTolerance = R"doc(Test if two doubles are equal within tolerance.)doc";

static const char* __doc_Bentley_Geom_DoubleOps_SnapZero = R"doc(snap to zero if within tolerance.)doc";

static const char* __doc_Bentley_Geom_DoubleOps_TolerancedSign = R"doc(Return -1,0,1 according to sign, with 0 case subject to tolerance.)doc";

static const char* __doc_Bentley_Geom_DoubleOps_ComputeTolerance = R"doc(Return a tolerance appropriate for coordinates up to maxSize

Parameter ``[in]``:
    maxSize large number for range of values being compared.

Parameter ``[in]``:
    abstol smallest allowed tolerance. If 0 or negative, a small
    default is used.

Parameter ``[in]``:
    reltol a realtive tolerance. If 0 or negative, a small default is
    used.)doc";

static const char* __doc_Bentley_Geom_DoubleOps_ClampFraction = R"doc(Clamp a single fraction.)doc";

static const char* __doc_Bentley_Geom_DoubleOps_ClampDirectedFractionInterval = R"doc(Clamp two fractions to 0..1 respecting directional relationship.)doc";

static const char* __doc_Bentley_Geom_DoubleOps_Clamp = R"doc(Clamp x so it is between a and b. a is assumed less than or equal to
b.)doc";

static const char* __doc_Bentley_Geom_DoubleOps_IsExact01 = R"doc(Bitwise equality test for exact 01 interval references...)doc";

static const char* __doc_Bentley_Geom_DoubleOps_IsIn01 = R"doc(Test if x is between 0 and 1 inclusive.)doc";

static const char* __doc_Bentley_Geom_DoubleOps_IsAlmostIn01 = R"doc(Test if x is between 0 and 1 inclusive, with AlmostEqualFraction at
each end.)doc";

static const char* __doc_Bentley_Geom_DoubleOps_IsIn01OrExtension = R"doc(Test if x is between 0 and 1 inclusive.)doc";

static const char* __doc_Bentley_Geom_DoubleOps_IsIn01XY = R"doc(Test if x,y are both between 0 and 1 inclusive.)doc";

static const char* __doc_Bentley_Geom_DoubleOps_IsIn01XYZ = R"doc(Test if x,y,z are all between 0 and 1 inclusive.)doc";

static const char* __doc_Bentley_Geom_DoubleOps_Hypotenuse = R"doc(return sqrt (a^2 + b^2))doc";

static const char* __doc_Bentley_Geom_DoubleOps_Hypotenuse1 = R"doc(return sqrt (a^2 + b^2 + c^2))doc";

static const char* __doc_Bentley_Geom_DoubleOps_Hypotenuse2 = R"doc(return sqrt (a^2 + b^2 + c^2 + d^2))doc";

static const char* __doc_Bentley_Geom_DoubleOps_DeterminantXYXY = R"doc(return determinant)doc";

static const char* __doc_Bentley_Geom_DoubleOps_SafeDivideParameter = R"doc(Attempt to divide {numerator/denominator} Return false if result is
larger than 10 digits. This is a very comfortable upper limit for
parameter values (fractions and angles))doc";

static const char* __doc_Bentley_Geom_DoubleOps_ChooseSafeDivideParameter = R"doc(Attempt to divide either of {numerator0/denominator0} or
(numerator1/denominator1) Return false if result is larger than 10
digits. This is a very comfortable upper limit for parameter values
(fractions and angles))doc";

static const char* __doc_Bentley_Geom_DoubleOps_ValidatedDivideDistance = R"doc(Attempt to divide {numerator/denominator}

Parameter ``[in]``:
    a numerator

Parameter ``[in]``:
    b denominator

Parameter ``[in]``:
    defaultResult value to return (in the ValidatedDouble) when the
    actual quotient distance is more than 15 digits

Returns:
    ValidatedDouble with quotient (or defaultResult))doc";

static const char* __doc_Bentley_Geom_DoubleOps_ValidatedDivideDistanceSquared = R"doc(Attempt to divide {numerator/denominator}

Parameter ``[in]``:
    a numerator

Parameter ``[in]``:
    b denominator

Parameter ``[in]``:
    defaultResult value to return (in the ValidatedDouble) when the
    actual quotient distance is more than 30 digits

Returns:
    ValidatedDouble with quotient (or defaultResult))doc";

static const char* __doc_Bentley_Geom_DoubleOps_ValidatedDivideAndDifferentiate = R"doc([in] numerator [in] numerator derivative [in] denominator [in]
denomiinator derivative)doc";

static const char* __doc_Bentley_Geom_DoubleOps_ValidatedDivideParameter = R"doc(Attempt to divide {numerator/denominator}

Parameter ``[in]``:
    a numerator

Parameter ``[in]``:
    b denominator

Parameter ``[in]``:
    defaultResult value to return (in the ValidatedDouble) when the
    actual quotient is more than 10 digits.

Returns:
    ValidatedDouble with quotient (or defaultResult))doc";

static const char* __doc_Bentley_Geom_DoubleOps_ValidatedDivide = R"doc(Attempt to divide {numerator/denominator}

Parameter ``[in]``:
    a numerator

Parameter ``[in]``:
    b denominator

Parameter ``[in]``:
    defaultResult value to return (in the ValidatedDouble) when the {b
    < minRelativeDivisor * a}

Parameter ``[in]``:
    minRelativeDivisor smallest allowed divisor for 1.0. Effectively,
    the largest allowed result is (1/minRelativeDivisor)

Returns:
    ValidatedDouble with quotient (or defaultResult))doc";

static const char* __doc_Bentley_Geom_DoubleOps_SafeDivideDistanceSquared = R"doc(Attempt to divide {numerator/denominator} Return false if result is
larger than 30 digits. This should be used only when the result is
known to be a squared distance.)doc";

static const char* __doc_Bentley_Geom_DoubleOps_SafeDivide = R"doc(Attempt to divide {numerator/denominator} Return false if result is
larger than than 1/safeDivideFraction. Most users should call specific
functions SafeDivideDistance, SafeDivideParameter,
SafeDivideDistanceSquared which provide appropriate fractions.)doc";

static const char* __doc_Bentley_Geom_DoubleOps_LinearTransform = R"doc(Compute a linear transformation f(x) = c + d * x so that a0 maps to b0
and a1 maps to b1.

Returns:
    false if a0, a1 are nearly identical.)doc";

static const char* __doc_Bentley_Geom_DoubleOps_UpperBound = R"doc(Find the Index of value in pData(sorted!!!) which is greater than
searchValue.)doc";

static const char* __doc_Bentley_Geom_DoubleOps_LowerBound = R"doc(Find the Index of value in pData(sorted!!!) which is greater or than
equal to searchValue.)doc";

static const char* __doc_Bentley_Geom_DoubleOps_BoundingValues = R"doc(Search a sorted array for a bracketing interval, preferably lowerBound
&le searchValue &lt upperBound (note the lessThanOrEqual and lessThan
usage). Exceptions: 1) If the searchValue exactly matches an internal
value, the returned lowerBound is the searchValue and the search
interval is "to the right" -- the searchValue and a larger upperBound
2) If the search value is less than the start data, return the first
non-trivial data interval -- i.e. skip over multiple copies of the
start value. 3) If the search value is greater than or equal to the
final data, return the last non-trivial data interval -- i.e. skip
backwards over copies of the last value.

Parameter ``[in]``:
    pData sorted data (e.g. bspline knots)

Parameter ``[in]``:
    n data count

Parameter ``[in]``:
    searchValue value to be bracketed

Parameter ``[out]``:
    lowerIndex index of lowerBound.

Parameter ``[out]``:
    lowerBound left interval bound.

Parameter ``[out]``:
    upperBound right interval bound.

Returns:
    false if the array has only one value. Note that the out-of-bounds
    cases (but within a good array) return true and can be detected by
    testing searchValue against the lower and upper bounds.)doc";

static const char* __doc_Bentley_Geom_DoubleOps_Sort = R"doc(sort flat array of doubles, optionally descending.)doc";

static const char* __doc_Bentley_Geom_DoubleOps_SortTail = R"doc(Sort entries starting at i0.)doc";

static const char* __doc_Bentley_Geom_DoubleOps_Interpolate = R"doc(Interpolate between values)doc";

static const char* __doc_Bentley_Geom_DoubleOps_InverseInterpolate = R"doc(Return the fraction such that Interplate (dataA, fraction, dataB)
equals value. (Return 0 marked invalid if dataA and dataB are
AlmostEqual))doc";

static const char* __doc_Bentley_Geom_DoubleOps_UpdateMinMax = R"doc(update evolving minmax f values with associated x values.)doc";

static const char* __doc_Bentley_Geom_DoubleOps_Magnitude = R"doc(return sqrt (a*a + b*b + c*c))doc";

static const char* __doc_Bentley_Geom_DoubleOps_Magnitude1 = R"doc(return sqrt (a*a + b*b))doc";

static const char* __doc_Bentley_Geom_DoubleOps_AlmostEqualFraction = R"doc(Near-equality test knowing range 0..1 for values...)doc";

static const char* __doc_Bentley_Geom_DoubleOps_TolerancedComparison = R"doc(Return -1,0,1 for less than, AlmostEqual, greater than)doc";

static const char* __doc_Bentley_Geom_DoubleOps_ClearlyIncreasingFraction = R"doc(test knowing range 0..1 for values...)doc";

static const char* __doc_Bentley_Geom_DoubleOps_ClearlyIncreasing = R"doc(test with tolerance for equality)doc";

static const char* __doc_Bentley_Geom_DoubleOps_PreciseSum = R"doc(Sum using Kanane's high precision correction sequence. This takes
roughly 4 times as long as the simple sum but may be significantly
more accurate.)doc";

static const char* __doc_Bentley_Geom_DoubleOps_Normalize = R"doc(replace each value by its fractional position between a0 and a1.
return false and leave unchanged if a0==a1.)doc";

static const char* __doc_Bentley_Geom_DoubleOps_CopyToIndex = R"doc(<summary> make dest[i] = source[index[i]];</summary>
<remarks>index.size () determines the number moved</remarks>)doc";

static const char* __doc_Bentley_Geom_DoubleOps_CopyFromIndex = R"doc(<summary> make dest[index[i]] = source[i];</summary>
<remarks>index.size () determines the number moved</remarks>)doc";

static const char* __doc_Bentley_Geom_DoubleOps_MovingAverages = R"doc(Compute moving averages of blockSize consecutive values, optionally
skipping some leading and trailing values. ul> li>If (numSkip0 +
blockSize + numSkip1) is larger than soruce.size (), the dest array is
returned empty. li>If blockSize is 0, the dest array is returned
empty. ul>)doc";

static const char* __doc_Bentley_Geom_DoubleOps_MovingAverages1 = R"doc(Construct moving averages of blockSize consecutive values of uniformly
spaced original values. Optionally have mutliple copies of first and
last original values. ul> li>dest is returned empty if any count
problem appears. ul>)doc";

static const char* __doc_Bentley_Geom_DoubleOps_ChebyshevPoints = R"doc(Constructs an array of Chebyshev points, optionally adding -1 and +1
end values.)doc";

static const char* __doc_Bentley_Geom_DoubleOps_LinearMapInPlace = R"doc(replace each data[i] by (a + b * data[i]);)doc";

static const char* __doc_Bentley_Geom_DoubleOps_MinusOnePlus1LinearMapInPlace = R"doc(map (-1,1) to (aMinus,aPlus) in place)doc";

static const char* __doc_Bentley_Geom_DoubleOps_LinearMapFrontBackToInterval = R"doc(map first point to a0, last to a1, others proportionally)doc";

static const char* __doc_Bentley_Geom_DoubleOps_ChebyshevPoint = R"doc(Return the ith of n chebyshev points, cos(PI * (2i+1)/(2n)), starting
at i=0)doc";

static const char* __doc_Bentley_Geom_DoubleOps_SmallCoordinateRelTol = R"doc(Relative tolerance for coordinate tests. This is 1e-10, and is coarser
than Angle::SmallAngle.)doc";

static const char* __doc_Bentley_Geom_DoubleOps_SmallMetricDistance = R"doc(Return a distance (1.0e-6) that is essentially zero for typical metric
calculation.)doc";

static const char* __doc_Bentley_Geom_DoubleOps_FloatCoordinateRelTol = R"doc(Relative tolerance for coordinate tests with floats. This is 2.0e-6.)doc";

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
template <typename T>
void declare_VectorOps(py::module_& m, const std::string& typestr) 
    {
    using Class = VectorOps<T>;
    py::class_<Class> c1(m, typestr.c_str());
    c1.def_static ("Copy", [](bvector<T>* dest, bvector<T>* source)
        {
        return Class::Copy (dest, source);
        }, "dest"_a, "source"_a, DOC(Bentley, Geom, VectorOps, Copy));

    c1.def_static ("Copy", [](bvector<T>* dest, T const* source, size_t count)
        {
        return Class::Copy(dest, source, count);
        }, "dest"_a, "source"_a, "count"_a, DOC(Bentley, Geom, VectorOps, Copy));

    c1.def_static ("Append", [](bvector<T>* dest, T const* source, size_t count) -> size_t
        {
        return Class::Append(dest, source, count);
        }, "dest"_a, "source"_a, "count"_a);

    c1.def_static ("Append", [](bvector<T>* dest, bvector<T>* source)->size_t
        {
            return Class::Append(dest, source);
        }, "dest"_a, "source"_a);

    c1.def_static ("Size", &Class::Size, "dest"_a);
    c1.def_static ("Append", [](bvector<T>* dest, T const& data) -> size_t
        {
        return Class::Append(dest, data);
        }, "dest"_a, "data"_a);

    c1.def_static ("AppendDisconnect", &Class::AppendDisconnect, "dest"_a);
    c1.def_static ("Set", &Class::Set, "dest"_a, "data"_a, "index"_a, DOC(Bentley, Geom, VectorOps, Set));
    c1.def_static ("Get", &Class::Get, "dest"_a, "data"_a, "index"_a, DOC(Bentley, Geom, VectorOps, Get));
    c1.def_static ("AppendInterpolated", &Class::AppendInterpolated, "dest"_a, "first"_a, "last"_a, "count"_a, py::arg("includeFirst") = true, DOC(Bentley, Geom, VectorOps, AppendInterpolated));
    c1.def_static ("InterpolateAll", &Class::InterpolateAll, "dest"_a, "dataA"_a, "f"_a, "dataB"_a, DOC(Bentley, Geom, VectorOps, InterpolateAll));
    c1.def_static ("MallocAndCopy", &Class::MallocAndCopy, "source"_a, DOC(Bentley, Geom, VectorOps, MallocAndCopy));
    c1.def_static ("Compress", [](bvector<T>& data, double tolerance)
        {
        return Class::Compress(data, tolerance);
        }, "data"_a, "tolerance"_a, DOC(Bentley, Geom, VectorOps, Compress));
    c1.def_static ("CompressCyclic", &Class::CompressCyclic, "data"_a, "tolerance"_a, DOC(Bentley, Geom, VectorOps, CompressCyclic));
    c1.def_static ("Compress", [](bvector<T> const& source, bvector<T>& dest, double tolerance)
        {
            return Class::Compress(source, dest, tolerance);
        }, "source"_a, "dest"_a, "tolerance"_a, DOC(Bentley, Geom, VectorOps, Compress1));
    c1.def_static ("Reverse", &Class::Reverse, "xyz"_a, DOC(Bentley, Geom, VectorOps, Reverse));
    c1.def_static ("LargestCoordinate", [](bvector<T> const& data) -> double
        {
            return Class::LargestCoordinate (data);
        }, "data"_a, DOC(Bentley, Geom, VectorOps, LargestCoordinate));
    c1.def_static ("LargestCoordinate", [](T const* data, size_t count) -> double
        {
        return Class::LargestCoordinate (data, count);
        }, "data"_a, "count"_a, DOC(Bentley, Geom, VectorOps, LargestCoordinate));
    c1.def_static ("Tolerance", [](bvector<T> const& data, double absTol, double relTol)
        {
        return Class::Tolerance(data, absTol, relTol);
        }, "data"_a, "absTol"_a, "relTol"_a, DOC(Bentley, Geom, VectorOps, Tolerance));
    c1.def_static ("Tolerance", [](T const* data, size_t count, double absTol, double relTol)
        {
        return Class::Tolerance(data, count, absTol, relTol);
        }, "data"_a, "count"_a, "absTol"_a, "relTol"_a, DOC(Bentley, Geom, VectorOps, Tolerance));
    c1.def_static ("Equal", [](bvector<T> const& dataA, bvector<T> const& dataB)
        {
        return Class::Equal(dataA, dataB);
        }, "dataA"_a, "dataB"_a, DOC(Bentley, Geom, VectorOps, Equal));
    c1.def_static ("Equal", [](T const* dataA, size_t countA, T const* dataB, size_t countB)
        {
        return Class::Equal(dataA, countA, dataB, countB);
        }, "dataA"_a, "countA"_a, "dataB"_a, "countB"_a, DOC(Bentley, Geom, VectorOps, Equal));
    c1.def_static ("FindNotAlmostEqualAtOrAfter", [](bvector<T>const& data, T const& baseValue, size_t i0)
        {
        size_t i1 = 0;
        T value;
        bool bRet = Class::FindNotAlmostEqualAtOrAfter(data, baseValue, i0, i1, value);

        return py::make_tuple(bRet, i1, value);
        }, "data"_a, "baseValue"_a, "i0"_a, DOC(Bentley, Geom, VectorOps, FindNotAlmostEqualAtOrAfter));
    c1.def_static ("FindNotAlmostEqualBefore", [](bvector<T>const& data, T const& baseValue, size_t i0)
        {
        size_t i1 = 0;
        T value;
        bool bRet = Class::FindNotAlmostEqualBefore(data, baseValue, i0, i1, value);
        return py::make_tuple(bRet, i1, value);
        }, "data"_a, "baseValue"_a, "i0"_a, DOC(Bentley, Geom, VectorOps, FindNotAlmostEqualBefore));
    c1.def_static ("AlmostEqual", [](T const& valueA, T const& valueB)
        {
        return Class::AlmostEqual(valueA, valueB);
        }, "valueA"_a, "valueB"_a, DOC(Bentley, Geom, VectorOps, AlmostEqual));
    c1.def_static ("AlomostEqual", [](T const& valueA, T const& valueB, double tolerance)
        {
        return Class::AlmostEqual(valueA, valueB, tolerance);
        }, "valueA"_a, "valueB"_a, "tolerance"_a, DOC(Bentley, Geom, VectorOps, AlmostEqual1));
    c1.def_static ("AlmostEqual", [](T const* valueA, size_t numA, T const* valueB, size_t numB, double tolerance)
        {
        return Class::AlmostEqual(valueA, numA, valueB, numB, tolerance);
        }, "valueA"_a, "numA"_a, "valueB"_a, "numB"_a, "tolerance"_a, DOC(Bentley, Geom, VectorOps, AlmostEqual2));
    c1.def_static ("MostDistantIndex", [](bvector<T>const& data, T const& baseValue)
        {
        return Class::MostDistantIndex (data, baseValue);
        }, "data"_a, "tolerance"_a, DOC(Bentley, Geom, VectorOps, MostDistantIndex));
    c1.def_static("MostDistantIndex", [](T const* data, size_t n, T const& baseValue)
        {
        return Class::MostDistantIndex(data, n, baseValue);
        }, "data"_a, "n"_a, "baseValue"_a, DOC(Bentley, Geom, VectorOps, MostDistantIndex));
    }

void def_DoubleOps (py::module_& m)
    {
    //===================================================================================
    // struct DoubleOps
    declare_VectorOps<double>(m, "VectorOpsDouble");

    py::class_<DoubleOps, VectorOps <double>> c1 (m, "DoubleOps");
    c1.def_static ("SmallCoordinateRelTol", &DoubleOps::SmallCoordinateRelTol);
    
    c1.def_static ("Min", py::overload_cast<double, double>(&DoubleOps::Min), "a1"_a, "a2"_a, DOC(Bentley, Geom, DoubleOps, Min));
    c1.def_static ("Min", py::overload_cast<double, double, double>(&DoubleOps::Min), "a1"_a, "a2"_a, "a3"_a, DOC(Bentley, Geom, DoubleOps, Min1));
    c1.def_static ("Min", py::overload_cast<double, double, double, double>(&DoubleOps::Min), "a1"_a, "a2"_a, "a3"_a, "a4"_a, DOC(Bentley, Geom, DoubleOps, Min2));
    c1.def_static ("Min", py::overload_cast<bvector<double>&>(&DoubleOps::Min), DOC(Bentley, Geom, DoubleOps, Min));
    c1.def_static ("Min", py::overload_cast<double const*, size_t>(&DoubleOps::Min), DOC(Bentley, Geom, DoubleOps, Min));

    c1.def_static ("MinAbs", py::overload_cast<double, double>(&DoubleOps::MinAbs), "a1"_a, "a2"_a, DOC(Bentley, Geom, DoubleOps, MinAbs));
    c1.def_static ("MinAbs", py::overload_cast<double, double, double>(&DoubleOps::MinAbs), "a1"_a, "a2"_a, "a3"_a, DOC(Bentley, Geom, DoubleOps, MinAbs1));
    c1.def_static ("MinAbs", py::overload_cast<double, double, double, double>(&DoubleOps::MinAbs), "a1"_a, "a2"_a, "a3"_a, "a4"_a, DOC(Bentley, Geom, DoubleOps, MinAbs2));
    c1.def_static ("MinAbs", py::overload_cast<bvector<double>&>(&DoubleOps::MinAbs), DOC(Bentley, Geom, DoubleOps, MinAbs));
    c1.def_static ("MinAbs", py::overload_cast<double const*, size_t>(&DoubleOps::MinAbs), DOC(Bentley, Geom, DoubleOps, MinAbs));

    c1.def_static ("Max", py::overload_cast<double, double>(&DoubleOps::Max), "a1"_a, "a2"_a, DOC(Bentley, Geom, DoubleOps, Max));
    c1.def_static ("Max", py::overload_cast<double, double, double>(&DoubleOps::Max), "a1"_a, "a2"_a, "a3"_a, DOC(Bentley, Geom, DoubleOps, Max1));
    c1.def_static ("Max", py::overload_cast<double, double, double, double>(&DoubleOps::Max), "a1"_a, "a2"_a, "a3"_a, "a4"_a, DOC(Bentley, Geom, DoubleOps, Max2));
    c1.def_static ("Max", py::overload_cast<bvector<double>&>(&DoubleOps::Max), DOC(Bentley, Geom, DoubleOps, Max));
    c1.def_static ("Max", py::overload_cast<double const*, size_t>(&DoubleOps::Max), DOC(Bentley, Geom, DoubleOps, Max));

    c1.def_static ("MaxAbs", py::overload_cast<double, double>(&DoubleOps::MaxAbs), "a1"_a, "a2"_a, DOC(Bentley, Geom, DoubleOps, MaxAbs));
    c1.def_static ("MaxAbs", py::overload_cast<double, double, double>(&DoubleOps::MaxAbs), "a1"_a, "a2"_a, "a3"_a, DOC(Bentley, Geom, DoubleOps, MaxAbs1));
    c1.def_static ("MaxAbs", py::overload_cast<double, double, double, double>(&DoubleOps::MaxAbs), "a1"_a, "a2"_a, "a3"_a, "a4"_a, DOC(Bentley, Geom, DoubleOps, MaxAbs2));
    c1.def_static ("MaxAbs", py::overload_cast<double, double, double, double, double, double>(&DoubleOps::MaxAbs), "a1"_a, "a2"_a, "a3"_a, "a4"_a, "a5"_a, "a6"_a, DOC(Bentley, Geom, DoubleOps, MaxAbs3));
    c1.def_static ("MaxAbs", py::overload_cast<bvector<double>&>(&DoubleOps::MaxAbs), DOC(Bentley, Geom, DoubleOps, MaxAbs));
    c1.def_static ("MaxAbs", py::overload_cast<double const*, size_t>(&DoubleOps::MaxAbs), DOC(Bentley, Geom, DoubleOps, MaxAbs));

    c1.def_static ("UpdateMax", [](double& evolvingMax, double testValue)
        {
        DoubleOps::UpdateMax(evolvingMax, testValue);
        return evolvingMax;
        }, "evolvingMax"_a, "testValue"_a, DOC(Bentley, Geom, DoubleOps, UpdateMax));

    c1.def_static ("WithinTolerance", py::overload_cast<double, double, double>(&DoubleOps::WithinTolerance), "a1"_a, "a2"_a, "abstol"_a, DOC(Bentley, Geom, DoubleOps, WithinTolerance));
    c1.def_static ("WithinTolerance", py::overload_cast<double, double, double, double>(&DoubleOps::WithinTolerance), "a1"_a, "a2"_a, "abstol"_a, "relTol"_a, DOC(Bentley, Geom, DoubleOps, WithinTolerance));
    c1.def_static ("SnapZero", &DoubleOps::SnapZero, "a"_a, "abstol"_a, DOC(Bentley, Geom, DoubleOps, SnapZero));
    c1.def_static ("TolerancedSign", &DoubleOps::TolerancedSign, "a"_a, "abstol"_a, DOC(Bentley, Geom, DoubleOps, TolerancedSign));
    c1.def_static ("ComputeTolerance", &DoubleOps::ComputeTolerance, "maxSize"_a, "abstol"_a, "reltol"_a, DOC(Bentley, Geom, DoubleOps, ComputeTolerance));

    c1.def_static ("ScaleArray", py::overload_cast<double*, size_t, double>(&DoubleOps::ScaleArray), "values"_a, "n"_a, "a"_a);
    c1.def_static ("ScaleArray", py::overload_cast<bvector <double>&, double>(&DoubleOps::ScaleArray), "values"_a, "a"_a);
    
    c1.def_static ("ClampFraction", &DoubleOps::ClampFraction, "s"_a, DOC(Bentley, Geom, DoubleOps, ClampFraction));
    c1.def_static ("ClampDirectedFractionInterval", &DoubleOps::ClampDirectedFractionInterval, "t0"_a, "t1"_a, DOC(Bentley, Geom, DoubleOps, ClampDirectedFractionInterval));
    c1.def_static ("Clamp", &DoubleOps::Clamp, "x"_a, "a"_a, "b"_a, DOC(Bentley, Geom, DoubleOps, Clamp));
    c1.def_static ("IsExact01", &DoubleOps::IsExact01, "a0"_a, "a1"_a, DOC(Bentley, Geom, DoubleOps, IsExact01));

    c1.def_static ("IsIn01", py::overload_cast<double>(&DoubleOps::IsIn01),  "x"_a, DOC(Bentley, Geom, DoubleOps, IsIn01));
    c1.def_static ("IsIn01", py::overload_cast<double, double>(&DoubleOps::IsIn01), "x"_a, "y"_a, DOC(Bentley, Geom, DoubleOps, IsIn01XY));
    c1.def_static ("IsIn01", py::overload_cast<DPoint2dCR>(&DoubleOps::IsIn01), "xy"_a, DOC(Bentley, Geom, DoubleOps, IsIn01XY));
    c1.def_static ("IsIn01", py::overload_cast<DPoint3dCR>(&DoubleOps::IsIn01), "xyz"_a, DOC(Bentley, Geom, DoubleOps, IsIn01XYZ));

    c1.def_static ("IsAlmostIn01", &DoubleOps::IsAlmostIn01, "x"_a, DOC(Bentley, Geom, DoubleOps, IsAlmostIn01));
    c1.def_static ("IsIn01OrExtension", &DoubleOps::IsIn01OrExtension, "x"_a, "extend0"_a, "extend1"_a, DOC(Bentley, Geom, DoubleOps, IsIn01OrExtension));

    c1.def_static ("Hypotenuse", py::overload_cast<double, double>(&DoubleOps::Hypotenuse), "a"_a, "b"_a, DOC(Bentley, Geom, DoubleOps, Hypotenuse));
    c1.def_static ("Hypotenuse", py::overload_cast<double, double, double>(&DoubleOps::Hypotenuse), "a"_a, "b"_a, "c"_a, DOC(Bentley, Geom, DoubleOps, Hypotenuse1));

    c1.def_static ("DeterminantXYXY", &DoubleOps::DeterminantXYXY, "x0"_a, "y0"_a, "x1"_a, "y1"_a, DOC(Bentley, Geom, DoubleOps, DeterminantXYXY));
    c1.def_static ("SafeDivideParameter", [](double& result, double numerator, double denominator, double defaultResult = 0.0)
        {
        bool bRet = DoubleOps::SafeDivideParameter (result, numerator, denominator, defaultResult);
        return py::make_tuple(bRet, result);
        }, "result"_a, "numerator"_a, "denominator"_a, py::arg("defaultResult") = 0.0, DOC(Bentley, Geom, DoubleOps, SafeDivideParameter));
    c1.def_static ("ChooseSafeDivideParameter", [](double& result, double numerator0, double denominator0, double numerator1, double denominator1, double defaultResult = 0.0)
        {
        bool bRet = DoubleOps::ChooseSafeDivideParameter(result, numerator0, denominator0, numerator1, denominator1, defaultResult);
        return py::make_tuple(bRet, result);
        }, "result"_a, "numerator0"_a, "denominator0"_a, "numerator1"_a, "denominator1"_a, py::arg("defaultResult") = 0.0, DOC(Bentley, Geom, DoubleOps, ChooseSafeDivideParameter));
    c1.def_static ("SafeDivideDistance", [](double& result, double numerator, double denominator, double defaultResult = 0.0)
        {
        bool bRet = DoubleOps::SafeDivideDistance(result, numerator, denominator, defaultResult);
        return py::make_tuple(bRet, result);
        }, "result"_a, "numerator"_a, "denominator"_a, py::arg("defaultResult") = 0);
    c1.def_static ("ValidatedDivideDistance", &DoubleOps::ValidatedDivideDistance, "a"_a, "b"_a, py::arg("defaultResult") = 0.0, DOC(Bentley, Geom, DoubleOps, ValidatedDivideDistance));
    c1.def_static ("ValidatedDivideDistanceSquared", &DoubleOps::ValidatedDivideDistanceSquared, "a"_a, "b"_a, py::arg("defaultResult") = 0.0, DOC(Bentley, Geom, DoubleOps, ValidatedDivideDistanceSquared));
    c1.def_static ("ValidatedDivideAndDifferentiate", &DoubleOps::ValidatedDivideAndDifferentiate, "f"_a, "df"_a, "g"_a, "dg"_a, DOC(Bentley, Geom, DoubleOps, ValidatedDivideAndDifferentiate));
    c1.def_static ("ValidatedDivideParameter", &DoubleOps::ValidatedDivideParameter, "a"_a, "b"_a, py::arg("defaultResult") = 0.0, DOC(Bentley, Geom, DoubleOps, ValidatedDivideParameter));
    c1.def_static ("ValidatedDivide", &DoubleOps::ValidatedDivide, "a"_a, "b"_a, py::arg("defaultResult") = 0.0, py::arg("minRelativeDivisor") = 1.0e-15, DOC(Bentley, Geom, DoubleOps, ValidatedDivide));
    c1.def_static ("SafeDivideDistanceSquared", [](double& result, double numerator, double denominator, double defaultResult = 0.0)
        {
        bool bRet = DoubleOps::SafeDivideDistanceSquared(result, numerator, denominator, defaultResult);
        return py::make_tuple(bRet, result);
        }, "result"_a, "numerator"_a, "denominator"_a, py::arg("defaultResult") = 0.0, DOC(Bentley, Geom, DoubleOps, SafeDivideDistanceSquared));
    c1.def_static ("SafeDivide", [](double& result, double numerator, double denominator, double defaultResult = 0.0, double smallFraction = 1.0e-15)
        {
        bool bRet = DoubleOps::SafeDivide(result, numerator, denominator, defaultResult, smallFraction);
        return py::make_tuple(bRet, result);
        }, "result"_a, "numerator"_a, "denominator"_a, py::arg("defaultResult") = 0.0, py::arg("smallFraction") = 1.0e-15, DOC(Bentley, Geom, DoubleOps, SafeDivide));
    c1.def_static ("LinearTransform", [](double a0, double a1, double b0, double b1, double& c, double& d)
        {
        bool bRet = DoubleOps::LinearTransform(a0, a1, b0, b1, c, d);
        return py::make_tuple(bRet, c, d);
        }, "a0"_a, "a1"_a, "b0"_a, "b1"_a, "c"_a, "d"_a, DOC(Bentley, Geom, DoubleOps, LinearTransform));
    c1.def_static ("UpperBound", [](double const* pData, size_t n, double searchValue, size_t& index)
        {
        bool bRet = DoubleOps::UpperBound(pData, n, searchValue, index);
        return py::make_tuple(bRet, index);
        }, "pData"_a, "n"_a, "searchValue"_a, "index"_a, DOC(Bentley, Geom, DoubleOps, UpperBound));
    c1.def_static ("LowerBound", [](double const* pData, size_t n, double searchValue, size_t& index)
        {
        bool bRet = DoubleOps::LowerBound(pData, n, searchValue, index);
        return py::make_tuple(bRet, index);
        }, "pData"_a, "n"_a, "searchValue"_a, "index"_a, DOC(Bentley, Geom, DoubleOps, LowerBound));
    
    c1.def_static ("BoundingValues", [](double const* pData, size_t n, double searchValue, size_t& lowerIndex, double& lowerBound, double& upperBound)
        {
        bool bRet = DoubleOps::BoundingValues(pData, n, searchValue, lowerIndex, lowerBound, upperBound);
        return py::make_tuple(bRet, lowerIndex, lowerBound, upperBound);
        }, "pData"_a, "n"_a, "searchValue"_a, "lowerIndex"_a, "lowerBound"_a, "upperBound"_a, DOC(Bentley, Geom, DoubleOps, BoundingValues));
    c1.def_static ("BoundingValues", [](bvector<double>const& data, double searchValue, size_t& lowerIndex, double& lowerBound, double& upperBound)
        {
        bool bRet = DoubleOps::BoundingValues(data, searchValue, lowerIndex, lowerBound, upperBound);
        return py::make_tuple (bRet, lowerIndex, lowerBound, upperBound);
        }, "data"_a, "searchValue"_a, "lowerIndex"_a, "lowerBound"_a, "upperBound"_a, DOC(Bentley, Geom, DoubleOps, BoundingValues));
    c1.def_static ("BoundingValues", [](size_t n, double searchValue, size_t& lowerIndex, double& lowerBound, double& upperBound)
        {
        bool bRet = DoubleOps::BoundingValues(n, searchValue, lowerIndex, lowerBound, upperBound);
        return py::make_tuple (bRet, lowerIndex, lowerBound, upperBound);
        }, "n"_a, "searchValue"_a, "lowerIndex"_a, "lowerBound"_a, "upperBound"_a, DOC(Bentley, Geom, DoubleOps, BoundingValues));

    c1.def_static ("Sort", [](double* data, size_t count, bool ascending = true)
        {
        DoubleOps::Sort(data, count, ascending);
        return data;
        }, "data"_a, "count"_a, py::arg("ascending") = true, DOC(Bentley, Geom, DoubleOps, Sort));
    c1.def_static ("Sort", [](bvector<double>& data, bool ascending = true)
        {
        DoubleOps::Sort(data, ascending);
        return data;
        }, "data"_a, py::arg("ascending") = true, DOC(Bentley, Geom, DoubleOps, Sort));
    c1.def_static ("SortTail", [](bvector<double>& data, size_t i0, bool ascending = true)
        {
        DoubleOps::SortTail(data, i0, ascending);
        return data;
        }, "data"_a, "i0"_a, py::arg("ascending") = true, DOC(Bentley, Geom, DoubleOps, SortTail));

    c1.def_static ("Interpolate", &DoubleOps::Interpolate, "dataA"_a, "fraction"_a, "dataB"_a, DOC(Bentley, Geom, DoubleOps, Interpolate));
    c1.def_static ("InverseInterpolate", &DoubleOps::InverseInterpolate, "dataA"_a, "value"_a, "dataB"_a, DOC(Bentley, Geom, DoubleOps, InverseInterpolate));
    c1.def_static ("Swap", [](double& dataA, double& dataB)
        {
        DoubleOps::Swap(dataA, dataB);
        return py::make_tuple(dataA, dataB);
        }, "dataA"_a, "dataB"_a);
    c1.def_static("UpdateMinMax", [](double x, double f, double& xMin, double& fMin, double& xMax, double& fMax)
        {
        DoubleOps::UpdateMinMax(x, f, xMin, fMin, xMax, fMax);
        return py::make_tuple(xMin, fMin, xMax, fMax);
        }, "x"_a, "f"_a, "xMin"_a, "fMin"_a, "xMax"_a, "fMax"_a, DOC(Bentley, Geom, DoubleOps, UpdateMinMax));

    c1.def_static ("Magnitude", py::overload_cast<double, double, double>(&DoubleOps::Magnitude), "a"_a, "b"_a, "c"_a, DOC(Bentley, Geom, DoubleOps, Magnitude));
    c1.def_static ("Magnitude", py::overload_cast<double, double>(&DoubleOps::Magnitude), "a"_a, "b"_a, DOC(Bentley, Geom, DoubleOps, Magnitude1));

    c1.def_static ("AlmostEqualFraction", &DoubleOps::AlmostEqualFraction, "a"_a, "b"_a, DOC(Bentley, Geom, DoubleOps, AlmostEqualFraction));
    c1.def_static ("TolerancedComparison", &DoubleOps::TolerancedComparison, "a"_a, "b"_a, DOC(Bentley, Geom, DoubleOps, TolerancedComparison));
    c1.def_static ("ClearlyIncreasingFraction", &DoubleOps::ClearlyIncreasingFraction, "a"_a, "b"_a, DOC(Bentley, Geom, DoubleOps, ClearlyIncreasingFraction));
    c1.def_static ("ClearlyIncreasing", &DoubleOps::ClearlyIncreasing, "a"_a, "b"_a, "tol"_a, DOC(Bentley, Geom, DoubleOps, ClearlyIncreasing));
    
    c1.def_static ("Sum", py::overload_cast<double*, int>(&DoubleOps::Sum), "data"_a, "n"_a);
    c1.def_static ("Sum", py::overload_cast<bvector<double> const&>(&DoubleOps::Sum), "data"_a);
    c1.def_static ("SumAbs", py::overload_cast<double*, int>(&DoubleOps::SumAbs), "data"_a, "n"_a);
    c1.def_static ("SumAbs", py::overload_cast<bvector<double> const&>(&DoubleOps::SumAbs), "data"_a);

    c1.def_static ("PreciseSum", py::overload_cast<double*, size_t>(&DoubleOps::PreciseSum), "data"_a, "n"_a, DOC(Bentley, Geom, DoubleOps, PreciseSum));
    c1.def_static ("PreciseSum", py::overload_cast<double, double, double>(&DoubleOps::PreciseSum), "a"_a, "b"_a, "c"_a, DOC(Bentley, Geom, DoubleOps, PreciseSum));
    c1.def_static ("Normalize", [](bvector<double>& data, double a0, double a1)
        {
        bool bRet = DoubleOps::Normalize(data, a0, a1);
        return py::make_tuple(bRet, data);
        },"data"_a, "a0"_a, "a1"_a, DOC(Bentley, Geom, DoubleOps, Normalize));

    c1.def_static("CopyToIndex", [](bvector<double> const& source, bvector<size_t> const& index, bvector<double>& dest)
        {
        DoubleOps::CopyToIndex(source, index, dest);
        return py::make_tuple(dest);
        }, "source"_a, "index"_a, "dest"_a, DOC(Bentley, Geom, DoubleOps, CopyToIndex));

    c1.def_static("CopyFromIndex", [](bvector<double> const& source, bvector<size_t> const& index, bvector<double>& dest)
        {
        DoubleOps::CopyFromIndex (source, index, dest);
        return dest;
        }, "source"_a, "index"_a, "dest"_a, DOC(Bentley, Geom, DoubleOps, CopyFromIndex));

    c1.def_static("SetZeros", [](bvector<double>& dest)
        {
        DoubleOps::SetZeros(dest);
        return dest;
        }, "dest"_a);

    c1.def_static("SetSequential", [](bvector<double>& dest, double a0 = 0.0, double delta = 1.0)
        {
        DoubleOps::SetSequential(dest, a0, delta);
        return dest;
        }, "dest"_a, py::arg("a0") = 0.0, py::arg("delta") = 1.0);

    c1.def_static ("MaxAbsDiff", &DoubleOps::MaxAbsDiff, "x"_a, "y"_a);
    c1.def_static ("MovingAverages", [](bvector<double>& dest, bvector<double> const& source, size_t blockSize, size_t numSkip0 = 0, size_t numSkip1 = 0)
        {
        DoubleOps::MovingAverages(dest, source, blockSize, numSkip0, numSkip1);
        return dest;
        }, "dest"_a, "source"_a, "blockSize"_a, "numSkip0"_a, "numSkip1"_a, DOC(Bentley, Geom, DoubleOps, MovingAverages));

    c1.def_static ("MovingAverages", [](bvector<double>& dest, double value0, double value1, size_t numOut, size_t blockSize, size_t numCopy0 = 1, size_t numCopy1 = 1)
        {
        DoubleOps::MovingAverages(dest, value0, value1, numOut, blockSize, numCopy0, numCopy1);
        return dest;
        }, "dest"_a, "value0"_a, "value1"_a, "numOut"_a, "blockSize"_a, py::arg("numCopy0") = 1, py::arg("numCopy1") = 1, DOC(Bentley, Geom, DoubleOps, MovingAverages1));

    c1.def_static("ChebyshevPoints", [](bvector<double>& dest, size_t numChebyshev, bool addLimitPoints, size_t numCopyLeft = 1, size_t numCopyRight = 1)
        {
        DoubleOps::ChebyshevPoints (dest, numChebyshev, addLimitPoints, numCopyLeft, numCopyRight);
        return dest;
        }, "dest"_a, "numChebyshev"_a, "addLimitPoints"_a, py::arg("numCopyLeft") = 1, py::arg("numCopyRight") = 1, DOC(Bentley, Geom, DoubleOps, ChebyshevPoints));

    c1.def_static ("LinearMapInPlace", [](bvector<double>& data, double a, double b)
        {
        DoubleOps::LinearMapInPlace(data, a, b);
        return data;
        }, "data"_a, "a"_a, "b"_a, DOC(Bentley, Geom, DoubleOps, LinearMapInPlace));

    c1.def_static ("MinusOnePlus1LinearMapInPlace", [](bvector<double>& data, double aMinus, double aPlus)
        {
        DoubleOps::MinusOnePlus1LinearMapInPlace(data, aMinus, aPlus);
        return data;
        }, "data"_a, "aMinus"_a, "aPlus"_a, DOC(Bentley, Geom, DoubleOps, MinusOnePlus1LinearMapInPlace));

    c1.def_static ("LinearMapFrontBackToInterval", [](bvector<double>& data, double a0, double a1)
        {
        DoubleOps::LinearMapFrontBackToInterval(data, a0, a1);
        return data;
        }, "data"_a, "a0"_a, "a1"_a, DOC(Bentley, Geom, DoubleOps, LinearMapFrontBackToInterval));

    c1.def_static ("ChebyshevPoint", &DoubleOps::ChebyshevPoint, "i"_a, "n"_a, DOC(Bentley, Geom, DoubleOps, ChebyshevPoint));
    c1.def_static ("SmallCoordinateRelTol", &DoubleOps::SmallCoordinateRelTol, DOC(Bentley, Geom, DoubleOps, SmallCoordinateRelTol));
    c1.def_static ("SmallMetricDistance", &DoubleOps::SmallMetricDistance, DOC(Bentley, Geom, DoubleOps, SmallMetricDistance));
    c1.def_static ("FloatCoordinateRelTol", &DoubleOps::FloatCoordinateRelTol, DOC(Bentley, Geom, DoubleOps, FloatCoordinateRelTol));
    }
