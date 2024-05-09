/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnPlatform\source\gparray.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <DgnPlatform/GPArray.h>



static const char * __doc_Bentley_DgnPlatform_GPArray_ToGroupElement =R"doc(Represent the GPArray as a group cell containing simple curve
elements.

Parameter ``eeh``:
    The new element .

Parameter ``templateEh``:
    Template element to use for symbology; if NULL defaults are used.

Parameter ``is3d``:
    Initialize the 2d or 3d element structure, typically
    modelRef->Is3d ().

Parameter ``closePhysicallyClosed``:
    For indivual curves that are physically closed whether to create
    as open or closed type.

Parameter ``model``:
    Model to associate this element with. Required to compute range.

Returns:
    SUCCESS if a valid element is created and range was sucessfully
    calculated.)doc";

static const char * __doc_Bentley_DgnPlatform_GPArray_ToElement =R"doc(Represent the GPArray as a simple curve, path, or region element.

Parameter ``eeh``:
    The new element .

Parameter ``templateEh``:
    Template element to use for symbology; if NULL defaults are used.

Parameter ``is3d``:
    Initialize the 2d or 3d element structure, typically
    modelRef->Is3d ().

Parameter ``closed``:
    True if GPArray represents a closed path and a closed element type
    should be created.

Parameter ``model``:
    Model to associate this element with. Required to compute range.

Returns:
    SUCCESS if a valid element is created and range was sucessfully
    calculated.)doc";

static const char * __doc_Bentley_DgnPlatform_GPArray_ToCurveVector =R"doc(Create CurveVector form of the curves.)doc";

static const char * __doc_Bentley_DgnPlatform_GPArray_IsMajorBreak =R"doc(Query if the supplied index represents a break between curve loops in
a region.

Parameter ``index``:
    Index of point to test.

Returns:
    true if point at index is a major break.)doc";

static const char * __doc_Bentley_DgnPlatform_GPArray_GetCurveType =R"doc(Query the gpa for the curve type starting as the supplied index.

Parameter ``index``:
    Index of point that is the start of a curve segment.

Returns:
    The type of curve segment.)doc";

static const char * __doc_Bentley_DgnPlatform_GPArray_GetPoint =R"doc(Extract a single point from the GPArray.

Parameter ``point``:
    Where to store point

Parameter ``index``:
    Index of point to return.

Returns:
    A pointer to the returned point.)doc";

static const char * __doc_Bentley_DgnPlatform_GPArray_MarkMajorBreak =R"doc(Denote the break between multiple curve loops as in the solid and hole
loops of a region.)doc";

static const char * __doc_Bentley_DgnPlatform_GPArray_MarkBreak =R"doc(Denote a break between disconnected line segments.)doc";

static const char * __doc_Bentley_DgnPlatform_GPArray_Add =R"doc(Add a single point to the GPArray.

Parameter ``pt``:
    point to add.)doc";

static const char * __doc_Bentley_DgnPlatform_GPArray_Append =R"doc(Appends the source GPArray contents to the contents of this instance.

Parameter ``source``:
    GPArray to append.

Returns:
    true if append was successful.)doc";

static const char * __doc_Bentley_DgnPlatform_GPArray_CopyContentsOf =R"doc(Copies the source GPArray contents and replace the contents of this
instance.

Parameter ``source``:
    GPArray to copy.

Returns:
    true if copy was successful.)doc";

static const char * __doc_Bentley_DgnPlatform_GPArray_Transform =R"doc(Transform the contents of the GPArray by the supplied transform.

Parameter ``transform``:
    To apply to GPArray contents.)doc";

static const char * __doc_Bentley_DgnPlatform_GPArray_Stroke =R"doc(Replace the (possibly curved) contents of the array by strokes with
weight 1.

Parameter ``tolerance``:
    Stroke tolerance, to be applied only to the xy values.)doc";

static const char * __doc_Bentley_DgnPlatform_GPArray_IsPointInsideXY =R"doc(Compute an in/out classification of a single point using only xy
coordinates.

Parameter ``point``:
    point to test.

Returns:
    true if point is on or inside the region defined by the gpa (by
    parity rules).)doc";

static const char * __doc_Bentley_DgnPlatform_GPArray_GetPlane =R"doc(Get a plane which contains the geometry in the array.

Parameter ``plane``:
    Where to store the GPArray plane.

Returns:
    true if geometry is planar. If geometry is non-planar the plane is
    arbitrary but may be close.)doc";

static const char * __doc_Bentley_DgnPlatform_GPArray_GetRange =R"doc(Initialize a range from all the point in the array.

Parameter ``range``:
    Where to store the GPArray range.

Returns:
    A pointer to GPArray range.)doc";

static const char * __doc_Bentley_DgnPlatform_GPArray_Length =R"doc(Compute the total length of the curves in the array.

Returns:
    Total curve length.)doc";

static const char * __doc_Bentley_DgnPlatform_GPArray_Empty =R"doc(Remove all points in the array.)doc";

static const char * __doc_Bentley_DgnPlatform_GPArray_GetCount =R"doc(Get the number of points in the array. @note This is not the number of
curves, it's the total number of points for all curves.

Returns:
    Graphics point array count.)doc";

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_GPArray(py::module_& m)
    {

    //===================================================================================
    // enum class GPCurveType
    py::enum_< Bentley::GPCurveType>(m, "GPCurveType")
        .value("eInvalid", Bentley::GPCurveType::Invalid)
        .value("eLineString", Bentley::GPCurveType::LineString)
        .value("eEllipse", Bentley::GPCurveType::Ellipse)
        .value("eBezier", Bentley::GPCurveType::Bezier)
        .value("eBSpline", Bentley::GPCurveType::BSpline)
        .export_values();

    //===================================================================================
    // struct GPArray
    py::class_< GPArray
        , std::unique_ptr<GPArray, py::nodelete>
    > c2(m, "GPArray");


    c2.def_static("Grab", &GPArray::Grab, py::return_value_policy::reference);
    c2.def("Drop", &GPArray::Drop);
    
    c2.def_property_readonly("Count", &GPArray::GetCount);
    c2.def("GetCount", &GPArray::GetCount, DOC(Bentley, DgnPlatform, GPArray, GetCount));
    
    c2.def("Empty", &GPArray::Empty, DOC(Bentley, DgnPlatform, GPArray, Empty));
    c2.def("EmptyAll", &GPArray::EmptyAll);
    c2.def("Length", &GPArray::Length, DOC(Bentley, DgnPlatform, GPArray, Length));    
    c2.def("GetRange", &GPArray::GetRange, "range"_a, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, GPArray, GetRange));

    c2.def("GetPlane", &GPArray::GetPlane, "plane"_a, DOC(Bentley, DgnPlatform, GPArray, GetPlane));
    c2.def("IsPointInsideXY", &GPArray::IsPointInsideXY, "point"_a, DOC(Bentley, DgnPlatform, GPArray, IsPointInsideXY));
    c2.def("Stroke", &GPArray::Stroke, "tolerance"_a, DOC(Bentley, DgnPlatform, GPArray, Stroke));
    c2.def("Transform", py::overload_cast<TransformCP>(&GPArray::Transform), "transform"_a, DOC(Bentley, DgnPlatform, GPArray, Transform));
    c2.def("Transform", py::overload_cast<DMatrix4dCP>(&GPArray::Transform), "transform"_a, DOC(Bentley, DgnPlatform, GPArray, Transform));
    c2.def("CopyContentsOf", &GPArray::CopyContentsOf, "source"_a, DOC(Bentley, DgnPlatform, GPArray, CopyContentsOf));
    c2.def("Append", &GPArray::Append, "source"_a, DOC(Bentley, DgnPlatform, GPArray, Append));
    c2.def("Add", py::overload_cast<DPoint3dCP>(&GPArray::Add), "pt"_a, DOC(Bentley, DgnPlatform, GPArray, Add));
    
    c2.def("Add", [] (GPArray& self, DPoint3dArray const& points)
           {
           self.Add(points.data(), (int) points.size());
           }, "points"_a);

    c2.def("Add", [] (GPArray& self, DPoint2dArray const& points)
           {
           self.Add(points.data(), (int) points.size());
           }, "points"_a);

    c2.def("Add", py::overload_cast<DEllipse3dCR>(&GPArray::Add), "ellipse"_a, DOC(Bentley, DgnPlatform, GPArray, Add));
    c2.def("Add", py::overload_cast<MSBsplineCurveCR>(&GPArray::Add), "curve"_a, DOC(Bentley, DgnPlatform, GPArray, Add));
    c2.def("MarkBreak", &GPArray::MarkBreak, DOC(Bentley, DgnPlatform, GPArray, MarkBreak));
    c2.def("MarkMajorBreak", &GPArray::MarkMajorBreak, DOC(Bentley, DgnPlatform, GPArray, MarkMajorBreak));
    c2.def("Add", py::overload_cast<CurveVectorCR, bool>(&GPArray::Add), "curves"_a, "splinesAsBezier"_a = false, DOC(Bentley, DgnPlatform, GPArray, Add));
    c2.def("GetPoint", &GPArray::GetPoint, "point"_a, "index"_a, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, GPArray, GetPoint));
    
    c2.def("GetLineString", [] (GPArray const& self, DPoint3dArray& points)
           {
           int index = 0;
           int nPoints = 0;
           auto retVal = self.GetLineString(&index, points.data(), &nPoints, (int) points.size());
           return py::make_tuple(retVal, index, nPoints);
           }, "points"_a);

    c2.def("GetEllipse", [] (GPArray const& self, DEllipse3dP ellipse)
           {
           int index = 0;
           auto retVal = self.GetEllipse(&index, ellipse);
           return py::make_tuple(retVal, index);
           }, "ellipse"_a);

    c2.def("GetBCurve", [] (GPArray const& self, MSBsplineCurveP curve)
           {
           int index = 0;
           auto retVal = self.GetBCurve(&index, curve);
           return py::make_tuple(retVal, index);
           }, "curve"_a);

    c2.def("GetCurveType", &GPArray::GetCurveType, "index"_a, DOC(Bentley, DgnPlatform, GPArray, GetCurveType));
    c2.def("IsMajorBreak", &GPArray::IsMajorBreak, "index"_a, DOC(Bentley, DgnPlatform, GPArray, IsMajorBreak));
    c2.def("ToCurveVector", &GPArray::ToCurveVector, DOC(Bentley, DgnPlatform, GPArray, ToCurveVector));
    c2.def("ToElement", &GPArray::ToElement, "eeh"_a, "templateEh"_a, "is3d"_a, "closed"_a, "modelRef"_a, DOC(Bentley, DgnPlatform, GPArray, ToElement));
    c2.def("ToGroupElement", &GPArray::ToGroupElement, "eeh"_a, "templateEh"_a, "is3d"_a, "closePhysicallyClosed"_a, "modelRef"_a, DOC(Bentley, DgnPlatform, GPArray, ToGroupElement));    

    }