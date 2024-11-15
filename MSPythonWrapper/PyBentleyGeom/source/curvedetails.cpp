/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyBentleyGeom\source\curvedetails.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"



static const char * __doc_Bentley_Geom_CurveKeyPoint_ClosestPointCollector_GetResult =R"doc(Access the saved detail)doc";

static const char * __doc_Bentley_Geom_CurveKeyPoint_ClosestPointCollector_AnnouncePoint =R"doc(Announce a keypoint in world form. Derived class override captures as
needed.)doc";

static const char * __doc_Bentley_Geom_CurveKeyPointCollector_GetWorldToLocal =R"doc(Query the worldTolocal matrix.)doc";

static const char * __doc_Bentley_Geom_CurveKeyPointCollector_NeedKeyPointType =R"doc(Ask if a particular KeyPointType is requested.)doc";

static const char * __doc_Bentley_Geom_CurveKeyPointCollector_SetXYOnly =R"doc(Request projection to XY plane.)doc";

static const char * __doc_Bentley_Geom_CurveKeyPointCollector_EnableSingleKeyPointType =R"doc(Indicate keypoint preference, and suppress all others.)doc";

static const char * __doc_Bentley_Geom_CurveKeyPointCollector_EnableKeyPointType =R"doc(Indicate keypoint preference)doc";

static const char * __doc_Bentley_Geom_LocalRange_InitNullRange =R"doc(Initialize with identity transforms and an empty range. Initialize
with identity transforms and an empty range.)doc";

static const char * __doc_Bentley_Geom_CurveGapOptions_SetRemovePriorGapPrimitives =R"doc(Set flag to remove prior gap primitives)doc";

static const char * __doc_Bentley_Geom_CurveGapOptions_GetRemovePriorGapPrimitives =R"doc(Returns:
    flag to remove prior gap primitives)doc";

static const char * __doc_Bentley_Geom_CurveGapOptions_SetMaxAdjustAlongCurve =R"doc(Set max motion along a curve.)doc";

static const char * __doc_Bentley_Geom_CurveGapOptions_GetMaxAdjustAlongCurve =R"doc(Returns:
    max allowable motion along a curve.)doc";

static const char * __doc_Bentley_Geom_CurveGapOptions_SetMaxDirectAdjustTolerance =R"doc(Set max allowable motion of line and linestring endpoints.)doc";

static const char * __doc_Bentley_Geom_CurveGapOptions_GetMaxDirectAdjustTolerance =R"doc(Returns:
    max allowable motion of line and linestring endpoints.)doc";

static const char * __doc_Bentley_Geom_CurveGapOptions_SetEqualPointTolerance =R"doc(Set gap size that does not need to be corrected.)doc";

static const char * __doc_Bentley_Geom_CurveGapOptions_GetEqualPointTolerance =R"doc(Returns:
    tolerance for gaps that do not have to be closed at all.)doc";

static const char * __doc_Bentley_Geom_SolidLocationDetail_MapPickParameterFractionToRange =R"doc(Treat current pick parameter as fractions in new interval. return
false (and leave the pick parameter unchanged) if the range is
undefined.)doc";

static const char * __doc_Bentley_Geom_SolidLocationDetail_TransformInPlace =R"doc(TransformInPlace points and vectors by the transform.)doc";

static const char * __doc_Bentley_Geom_SolidLocationDetail_SetVDirection =R"doc(Set the v direction vector)doc";

static const char * __doc_Bentley_Geom_SolidLocationDetail_GetVDirection =R"doc(Return v direction vector.)doc";

static const char * __doc_Bentley_Geom_SolidLocationDetail_SetUDirection =R"doc(Set the u direction vector)doc";

static const char * __doc_Bentley_Geom_SolidLocationDetail_GetUDirection =R"doc(Return u direction vector.)doc";

static const char * __doc_Bentley_Geom_SolidLocationDetail_SetA =R"doc(Set a.)doc";

static const char * __doc_Bentley_Geom_SolidLocationDetail_GetA =R"doc(query the a parameter)doc";

static const char * __doc_Bentley_Geom_SolidLocationDetail_SetV =R"doc(Set v.)doc";

static const char * __doc_Bentley_Geom_SolidLocationDetail_GetV =R"doc(query the v parameter)doc";

static const char * __doc_Bentley_Geom_SolidLocationDetail_SetU =R"doc(Set u)doc";

static const char * __doc_Bentley_Geom_SolidLocationDetail_GetU =R"doc(query the u parameter)doc";

static const char * __doc_Bentley_Geom_SolidLocationDetail_SetUV =R"doc(Set the u,v, and direction vectors.)doc";

static const char * __doc_Bentley_Geom_SolidLocationDetail_GetUV =R"doc(Return u,v parameter information)doc";

static const char * __doc_Bentley_Geom_SolidLocationDetail_SetXYZ =R"doc(Set the point coordinates.)doc";

static const char * __doc_Bentley_Geom_SolidLocationDetail_GetXYZ =R"doc(Return the pick coordinates)doc";

static const char * __doc_Bentley_Geom_SolidLocationDetail_SetPickParameter =R"doc(set the pick fraction.)doc";

static const char * __doc_Bentley_Geom_SolidLocationDetail_GetPickParameter =R"doc(Return the parameter along the pick ray.)doc";

static const char * __doc_Bentley_Geom_SolidLocationDetail_SetParentId =R"doc(Set the parent id.)doc";

static const char * __doc_Bentley_Geom_SolidLocationDetail_GetParentId =R"doc(Return the parent id.)doc";

static const char * __doc_Bentley_Geom_SolidLocationDetail_GetFaceIndices =R"doc(return a structure with all selector indices.)doc";

static const char * __doc_Bentley_Geom_SolidLocationDetail_GetSecondarySelector =R"doc(Return the secondary selector)doc";

static const char * __doc_Bentley_Geom_SolidLocationDetail_GetPrimarySelector =R"doc(Return the primary selector.)doc";

static const char * __doc_Bentley_Geom_SolidLocationDetail_SetCapSelector =R"doc(Set selectors for cap id (typically 0 or 1))doc";

static const char * __doc_Bentley_Geom_SolidLocationDetail_SetFaceIndices01 =R"doc(Set all face selectors)doc";

static const char * __doc_Bentley_Geom_SolidLocationDetail_SetFaceIndices =R"doc(Set all face selectors)doc";

static const char * __doc_Bentley_Geom_SolidLocationDetail_Init =R"doc(Initialize to zeroed state.)doc";

static const char * __doc_Bentley_Geom_SolidLocationDetail_IsCap1 =R"doc(Ask if a selector pair is the end cap.)doc";

static const char * __doc_Bentley_Geom_SolidLocationDetail_IsCap0 =R"doc(Ask if a selector pair is the start cap.)doc";

static const char * __doc_Bentley_Geom_CurveLocationDetailPair_GetDSegment3d =R"doc(assemble points from detailA, detailB into a DSegment3d.)doc";

static const char * __doc_Bentley_Geom_CurveLocationDetailPair_Set =R"doc(update fractions, points, and a)doc";

static const char * __doc_Bentley_Geom_CurveLocationDetailPair_SameCurveAndFraction =R"doc(Return true if the two details are for (bitwise) identical curve and
fraction.)doc";

static const char * __doc_Bentley_Geom_CurveLocationDetail_SortByCurveAndFraction =R"doc(Sort to gather CurveLocationDetail's with same curve, and then by
fraction within those curves.)doc";

static const char * __doc_Bentley_Geom_CurveLocationDetail_SetComponentFractionFromFraction =R"doc(Set the componentIndex, numComponent, componentFraction, and fraction.
(Component fraction and index are computed from global fraction and
indices) All other data (point, curve pointer, a) is left unchanged.)doc";

static const char * __doc_Bentley_Geom_CurveLocationDetail_SetFractionFromComponentFraction =R"doc(Set the componentIndex, numComponent, componentFraction, and fraction.
(Global fraction is computed as (componentIndex + componentFraction)/
numComponent. All other data (point, curve pointer, a) is left
unchanged.)doc";

static const char * __doc_Bentley_Geom_CurveLocationDetail_AlmostEqualPoint =R"doc(test if point coordinates are AlmostEqual)doc";

static const char * __doc_Bentley_Geom_CurveLocationDetail_TryComponentFractionToPoint =R"doc(Try to evaluate the referenced curve at the detail's component
fraction.)doc";

static const char * __doc_Bentley_Geom_CurveLocationDetail_TryFractionToPoint =R"doc(Try to evaluate the referenced curve at the detail's fraction.)doc";

static const char * __doc_Bentley_Geom_CurveLocationDetail_PointAndUnitTangent =R"doc(Try to evalute the point and unit tangent at the detail's fraction)doc";

static const char * __doc_Bentley_Geom_CurveLocationDetail_Interpolate =R"doc(Use the componentIndex and componentFraction to interpolate doubles.)doc";

static const char * __doc_Bentley_Geom_CurveLocationDetail_Distance =R"doc(Return distance between point fields of this and other.)doc";

static const char * __doc_Bentley_Geom_CurveLocationDetail_SetSingleComponentFractionAndA =R"doc(Set fraction and a fields from parameters. Make the component fraction
match. Set componentIndex and numComponentIndex to 0 and 1.)doc";

static const char * __doc_Bentley_Geom_CurveLocationDetail_SetSingleComponentData =R"doc(copy fraction to componentFraction and set component index and count
for single component.)doc";

static const char * __doc_Bentley_Geom_CurveLocationDetail_SetDistance =R"doc(set distance field ({a}))doc";

static const char * __doc_Bentley_Geom_CurveLocationDetail_SetMaxDistance =R"doc(set distance to very large value.)doc";

static const char * __doc_Bentley_Geom_CurveLocationDetail_SetDistanceFrom =R"doc(set xyz distance from point.)doc";

static const char * __doc_Bentley_Geom_CurveLocationDetail_UpdateIfCloser =R"doc(conditional replace candidate, with minDistance update if needed.)doc";

static const char * __doc_Bentley_Geom_PartialCurveDetail_IsSingleFraction =R"doc(Test if the partial curve fraction range is a single fraction.)doc";

static const char * __doc_Bentley_Geom_PartialCurveDetail_ChildFractionToParentFraction =R"doc(map a local fraction into the parent fraction.)doc";

static const char * __doc_Bentley_Geom_PartialCurveDetail_ParentFractionToChildFraction =R"doc((attempt to) map a parent fraction back to the child interval. This
fails if the child is a single point.)doc";


/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_CurveDetails(py::module_& m)
    {
    //===================================================================================
    // struct PartialCurveDetail
    py::class_<PartialCurveDetail> c1(m, "PartialCurveDetail");
    py::bind_vector<bvector<PartialCurveDetail>>(m, "PartialCurveDetailArray", py::module_local(false));
    
    c1.def_readwrite("parentCurve", &PartialCurveDetail::parentCurve);
    c1.def_readwrite("fraction0", &PartialCurveDetail::fraction0);
    c1.def_readwrite("fraction1", &PartialCurveDetail::fraction1);
    c1.def_readwrite("userData", &PartialCurveDetail::userData);

    c1.def(py::init<>());
    c1.def(py::init<ICurvePrimitiveP, double, double, int64_t>(), "parentCurve"_a, "fraction0"_a, "fraction1"_a, "userData"_a);    
    c1.def(py::init<ICurvePrimitiveP, DSegment1dCR, int64_t>(), "parentCurve"_a, "interval"_a, "userData"_a = 0);
    c1.def(py::init<PartialCurveDetailCR, double, double>(), "parent"_a, "f0"_a, "f1"_a);

    c1.def("ParentFractionToChildFraction", [] (PartialCurveDetailCR self, double parentFraction)
           {
           double childFraction = 0.0;
           bool bOk = self.ParentFractionToChildFraction(parentFraction, childFraction);
           return py::make_tuple(bOk, childFraction);
           }, "parentFraction"_a, DOC(Bentley, Geom, PartialCurveDetail, ParentFractionToChildFraction));

    c1.def("ChildFractionToParentFraction", &PartialCurveDetail::ChildFractionToParentFraction, "f"_a, DOC(Bentley, Geom, PartialCurveDetail, ChildFractionToParentFraction));
    c1.def("IsSingleFraction", &PartialCurveDetail::IsSingleFraction, DOC(Bentley, Geom, PartialCurveDetail, IsSingleFraction));
    c1.def("UpdateFraction1AndUserData", &PartialCurveDetail::UpdateFraction1AndUserData, "f1"_a, "newData"_a);

    c1.def("__repr__", [] (PartialCurveDetail& self)
           {
           return "(parentCurve:{}, fraction0:{}, fraction1:{}, userData:{})"_s.format(self.parentCurve, self.fraction0, self.fraction1, self.userData);
           });

    c1.def("__copy__", [](const PartialCurveDetail& self)
        {
        return PartialCurveDetail(self);
        });

    //===================================================================================
    // struct CurveLocationDetail
    py::class_<CurveLocationDetail> c2(m, "CurveLocationDetail");
    py::bind_vector< CurveLocationDetailArray >(m, "CurveLocationDetailArray", py::module_local(false));
    bind_ValidatedValue<CurveLocationDetail>(m, "ValidatedCurveLocationDetail", py::module_local(false));

    c2.def_property_readonly("curve", [](CurveLocationDetail& self) {return std::unique_ptr<const ICurvePrimitive, py::nodelete>(self.curve); });
    c2.def_readwrite("fraction", &CurveLocationDetail::fraction);
    c2.def_readwrite("point", &CurveLocationDetail::point);
    c2.def_readwrite("componentIndex", &CurveLocationDetail::componentIndex);
    c2.def_readwrite("numComponent", &CurveLocationDetail::numComponent);
    c2.def_readwrite("componentFraction", &CurveLocationDetail::componentFraction);
    c2.def_readwrite("a", &CurveLocationDetail::a);

    c2.def(py::init<>());
    c2.def(py::init<ICurvePrimitiveCP, size_t>(), "curve"_a, "numComponent"_a = 1);
    c2.def(py::init<ICurvePrimitiveCP, double, DPoint3dCR>(), "curve"_a, "fraction"_a, "point"_a);
    c2.def(py::init<ICurvePrimitiveCP, double, DPoint3dCR, size_t, size_t, double>(), "curve"_a, "fraction"_a, "point"_a, "componentIndex"_a, "numComponent"_a, "componentFraction"_a);
    c2.def(py::init<ICurvePrimitiveCP, double, DPoint3dCR, size_t, size_t, double, double>(), "curve"_a, "fraction"_a, "point"_a, "componentIndex"_a, "numComponent"_a, "componentFraction"_a, "a"_a);

    c2.def("UpdateIfCloser", &CurveLocationDetail::UpdateIfCloser, "otherDetail"_a, DOC(Bentley, Geom, CurveLocationDetail, UpdateIfCloser));
    c2.def("SetDistanceFrom", &CurveLocationDetail::SetDistanceFrom, "refPoint"_a, DOC(Bentley, Geom, CurveLocationDetail, SetDistanceFrom));
    c2.def("SetMaxDistance", &CurveLocationDetail::SetMaxDistance, DOC(Bentley, Geom, CurveLocationDetail, SetMaxDistance));
    c2.def("SetDistance", &CurveLocationDetail::SetDistance, "value"_a, DOC(Bentley, Geom, CurveLocationDetail, SetDistance));

    c2.def("SetSingleComponentData", &CurveLocationDetail::SetSingleComponentData, DOC(Bentley, Geom, CurveLocationDetail, SetSingleComponentData));
    c2.def("SetSingleComponentFractionAndA", &CurveLocationDetail::SetSingleComponentFractionAndA, "fraction"_a, "a"_a, DOC(Bentley, Geom, CurveLocationDetail, SetSingleComponentFractionAndA));

    c2.def("Distance", &CurveLocationDetail::Distance, "other"_a, DOC(Bentley, Geom, CurveLocationDetail, Distance));

    c2.def("Interpolate", [] (CurveLocationDetailCR self, bvector<double> const& param)
           {
           double result = 0;
           bool bOk = self.Interpolate(param, result);
           return py::make_tuple(bOk, result);
           }, "param"_a, DOC(Bentley, Geom, CurveLocationDetail, Interpolate));

    c2.def("PointAndUnitTangent", &CurveLocationDetail::PointAndUnitTangent, DOC(Bentley, Geom, CurveLocationDetail, PointAndUnitTangent));

    c2.def("TryFractionToPoint", &CurveLocationDetail::TryFractionToPoint, "xyz"_a, "dXdf"_a, DOC(Bentley, Geom, CurveLocationDetail, TryFractionToPoint));
    c2.def("TryComponentFractionToPoint", &CurveLocationDetail::TryComponentFractionToPoint, "xyz"_a, "dXdf"_a, DOC(Bentley, Geom, CurveLocationDetail, TryComponentFractionToPoint));
    c2.def("AlmostEqualPoint", &CurveLocationDetail::AlmostEqualPoint, "other"_a, DOC(Bentley, Geom, CurveLocationDetail, AlmostEqualPoint));
    c2.def("Interpolate", py::overload_cast<double, CurveLocationDetailCR>(&CurveLocationDetail::Interpolate, py::const_), "fraction"_a, "dataB"_a, DOC(Bentley, Geom, CurveLocationDetail, Interpolate));
    c2.def("SetFractionFromComponentFraction", &CurveLocationDetail::SetFractionFromComponentFraction, "componentFraction"_a, "componentIndex"_a, "numComponent"_a, DOC(Bentley, Geom, CurveLocationDetail, SetFractionFromComponentFraction));
    c2.def("SetComponentFractionFromFraction", &CurveLocationDetail::SetComponentFractionFromFraction, "globalFraction"_a, "numComponent"_a, DOC(Bentley, Geom, CurveLocationDetail, SetComponentFractionFromFraction));
    c2.def_static("SortByCurveAndFraction", &CurveLocationDetail::SortByCurveAndFraction, "detail"_a, DOC(Bentley, Geom, CurveLocationDetail, SortByCurveAndFraction));

    c2.def("__repr__", [] (CurveLocationDetail& self)
           {
           return "(curve:{}, fraction:{}, point:{}, componentIndex:{}, numComponent:{}, componentFraction:{}, a:{})"_s
               .format(self.curve, self.fraction, self.point, self.componentIndex, self.numComponent, self.componentFraction, self.a);
           });

    c2.def("__copy__", [](const CurveLocationDetail& self)
        {
        return CurveLocationDetail(self);
        });


    //===================================================================================
    // struct CurveLocationDetailPair
    py::class_<CurveLocationDetailPair> c3(m, "CurveLocationDetailPair");
    py::bind_vector< CurveLocationDetailPairArray >(m, "CurveLocationDetailPairArray", py::module_local(false));

    c3.def_readwrite("detailA", &CurveLocationDetailPair::detailA);
    c3.def_readwrite("detailB", &CurveLocationDetailPair::detailB);

    c3.def(py::init<>());
    c3.def(py::init<CurveLocationDetailCR, CurveLocationDetailCR>(), "detailA"_a, "detailB"_a);
    c3.def(py::init<CurveLocationDetailCR>(), "detailA"_a);
    c3.def(py::init<ICurvePrimitiveCP, double, DPoint3dCR>(), "curve"_a, "fraction0"_a, "point0"_a);
    c3.def(py::init<ICurvePrimitiveCP, double, DPoint3dCR, size_t, size_t, double>(), "curve"_a, "fraction0"_a, "point0"_a, "componentIndex"_a, "numComponent"_a, "componentFraction"_a);
    c3.def(py::init<ICurvePrimitiveCP, double, ICurvePrimitiveCP, double>(), "curve0"_a, "a0"_a, "curve1"_a, "a1"_a);    

    c3.def("SameCurveAndFraction", &CurveLocationDetailPair::SameCurveAndFraction, DOC(Bentley, Geom, CurveLocationDetailPair, SameCurveAndFraction));

    c3.def("Set", py::overload_cast<double, DPoint3dCR, double, double, DPoint3dCR, double>(&CurveLocationDetailPair::Set), "fraction0"_a, "point0"_a, "a0"_a, "fraction1"_a, "point1"_a, "a1"_a, DOC(Bentley, Geom, CurveLocationDetailPair, Set));
    c3.def("Set", py::overload_cast<ICurvePrimitiveP, ICurvePrimitiveP>(&CurveLocationDetailPair::Set), "curveA"_a, "curveB"_a, DOC(Bentley, Geom, CurveLocationDetailPair, Set));

    c3.def("GetDSegment3d", &CurveLocationDetailPair::GetDSegment3d, DOC(Bentley, Geom, CurveLocationDetailPair, GetDSegment3d));

    c3.def("__repr__", [] (CurveLocationDetailPair& self)
           {
           return "(detailA:{}, detailB:{})"_s.format(self.detailA, self.detailB);
           });

    //===================================================================================
    // struct SolidLocationDetail
    py::class_<SolidLocationDetail> c4(m, "SolidLocationDetail");
    py::bind_vector< SolidLocationDetailArray >(m, "SolidLocationDetailArray", py::module_local(false));
    if (true)
        {
        //===================================================================================
        // struct FaceIndices
        py::class_<SolidLocationDetail::FaceIndices> c4_1(c4, "FaceIndices");
        py::bind_vector< FaceIndicesArray >(m, "FaceIndicesArray", py::module_local(false));        

        c4_1.def(py::init<>());
        c4_1.def(py::init<ptrdiff_t, ptrdiff_t, ptrdiff_t>(), "index0"_a, "index1"_a, "index2"_a);

        c4_1.def_static("Cap0", &SolidLocationDetail::FaceIndices::Cap0);
        c4_1.def_static("Cap1", &SolidLocationDetail::FaceIndices::Cap1);

        c4_1.def("Set", &SolidLocationDetail::FaceIndices::Set, "index0"_a, "index1"_a, "index2"_a);
        c4_1.def("SetCap0", &SolidLocationDetail::FaceIndices::SetCap0);
        c4_1.def("SetCap1", &SolidLocationDetail::FaceIndices::SetCap1);

        c4_1.def("Index0", &SolidLocationDetail::FaceIndices::Index0);
        c4_1.def("SetIndex0", &SolidLocationDetail::FaceIndices::SetIndex0, "value"_a);

        c4_1.def("Index1", &SolidLocationDetail::FaceIndices::Index1);
        c4_1.def("SetIndex1", &SolidLocationDetail::FaceIndices::SetIndex1, "value"_a);

        c4_1.def("Index2", &SolidLocationDetail::FaceIndices::Index2);
        c4_1.def("SetIndex2", &SolidLocationDetail::FaceIndices::SetIndex2, "value"_a);

        c4_1.def("IsCap", &SolidLocationDetail::FaceIndices::IsCap);
        c4_1.def("IsCap0", &SolidLocationDetail::FaceIndices::IsCap0, DOC(Bentley, Geom, SolidLocationDetail, IsCap0));
        c4_1.def("IsCap1", &SolidLocationDetail::FaceIndices::IsCap1, DOC(Bentley, Geom, SolidLocationDetail, IsCap1));

        c4_1.def("Is", py::overload_cast<ptrdiff_t, ptrdiff_t, ptrdiff_t>(&SolidLocationDetail::FaceIndices::Is, py::const_), "index0"_a, "index1"_a, "index2"_a);
        c4_1.def("Is", py::overload_cast<ptrdiff_t, ptrdiff_t>(&SolidLocationDetail::FaceIndices::Is, py::const_), "index0"_a, "index1"_a);

        c4_1.def("__repr__", [] (SolidLocationDetail::FaceIndices& self)
                 {
                 return "(index0:{}, index1{}, index2:{})"_s.format(self.Index0(), self.Index1(), self.Index2());
                 });
        }

    c4.def(py::init<>());
    c4.def(py::init<int, double>(), "parentId"_a, "s"_a);
    c4.def(py::init<int, double, DPoint3dCR>(), "parentId"_a, "s"_a, "xyz"_a);
    c4.def(py::init<int, double, DPoint3dCR, double, double, DVec3dCR, DVec3dCR>(), "parentId"_a, "s"_a, "xyz"_a, "u"_a, "v"_a, "uVector"_a, "vVector"_a);

    c4.def("Init", &SolidLocationDetail::Init, DOC(Bentley, Geom, SolidLocationDetail, Init));

    c4.def("SetFaceIndices", py::overload_cast<ptrdiff_t, ptrdiff_t, ptrdiff_t>(&SolidLocationDetail::SetFaceIndices), "id0"_a, "id1"_a, "id2"_a, DOC(Bentley, Geom, SolidLocationDetail, SetFaceIndices));
    c4.def("SetFaceIndices", py::overload_cast<SolidLocationDetail::FaceIndices const&>(&SolidLocationDetail::SetFaceIndices), "indices"_a, DOC(Bentley, Geom, SolidLocationDetail, SetFaceIndices));
    c4.def("SetFaceIndices01", &SolidLocationDetail::SetFaceIndices01, "id0"_a, "id1"_a, DOC(Bentley, Geom, SolidLocationDetail, SetFaceIndices01));

    c4.attr("PrimaryIdCap") = SolidLocationDetail::PrimaryIdCap;

    c4.def("SetCapSelector", &SolidLocationDetail::SetCapSelector, "id"_a, DOC(Bentley, Geom, SolidLocationDetail, SetCapSelector));
    
    c4.def_property_readonly("PrimarySelector", &SolidLocationDetail::GetPrimarySelector);
    c4.def("GetPrimarySelector", &SolidLocationDetail::GetPrimarySelector, DOC(Bentley, Geom, SolidLocationDetail, GetPrimarySelector));

    c4.def_property_readonly("SecondarySelector", &SolidLocationDetail::GetSecondarySelector);
    c4.def("GetSecondarySelector", &SolidLocationDetail::GetSecondarySelector, DOC(Bentley, Geom, SolidLocationDetail, GetSecondarySelector));

    c4.def_property_readonly("FaceIndices", &SolidLocationDetail::GetFaceIndices);
    c4.def("GetFaceIndices", &SolidLocationDetail::GetFaceIndices, DOC(Bentley, Geom, SolidLocationDetail, GetFaceIndices));
    
    c4.def_property("ParentId", &SolidLocationDetail::GetParentId, &SolidLocationDetail::SetParentId);
    c4.def("GetParentId", &SolidLocationDetail::GetParentId, DOC(Bentley, Geom, SolidLocationDetail, GetParentId));
    c4.def("SetParentId", &SolidLocationDetail::SetParentId, "id"_a, DOC(Bentley, Geom, SolidLocationDetail, SetParentId));
    
    c4.def_property("PickParameter", &SolidLocationDetail::GetPickParameter, &SolidLocationDetail::SetPickParameter);
    c4.def("GetPickParameter", &SolidLocationDetail::GetPickParameter, DOC(Bentley, Geom, SolidLocationDetail, GetPickParameter));
    c4.def("SetPickParameter", &SolidLocationDetail::SetPickParameter, "f"_a, DOC(Bentley, Geom, SolidLocationDetail, SetPickParameter));
    
    c4.def_property("XYZ", &SolidLocationDetail::GetXYZ, &SolidLocationDetail::SetXYZ);
    c4.def("GetXYZ", &SolidLocationDetail::GetXYZ, DOC(Bentley, Geom, SolidLocationDetail, GetXYZ));
    c4.def("SetXYZ", &SolidLocationDetail::SetXYZ, DOC(Bentley, Geom, SolidLocationDetail, SetXYZ));
    
    c4.def_property("UV", &SolidLocationDetail::GetUV, py::overload_cast<DPoint2dCR>(&SolidLocationDetail::SetUV));
    c4.def("GetUV", &SolidLocationDetail::GetUV, DOC(Bentley, Geom, SolidLocationDetail, GetUV));
    c4.def("SetUV", py::overload_cast<DPoint2dCR>(&SolidLocationDetail::SetUV), "uv"_a, DOC(Bentley, Geom, SolidLocationDetail, SetUV));
    
    c4.def_property("U", &SolidLocationDetail::GetU, &SolidLocationDetail::SetU);
    c4.def("GetU", &SolidLocationDetail::GetU, DOC(Bentley, Geom, SolidLocationDetail, GetU));
    c4.def("SetU", &SolidLocationDetail::SetU, "u"_a, DOC(Bentley, Geom, SolidLocationDetail, SetU));
    
    c4.def_property("V", &SolidLocationDetail::GetV, &SolidLocationDetail::SetV);
    c4.def("GetV", &SolidLocationDetail::GetV, DOC(Bentley, Geom, SolidLocationDetail, GetV));
    c4.def("SetV", &SolidLocationDetail::SetV, "v"_a, DOC(Bentley, Geom, SolidLocationDetail, SetV));
    
    c4.def_property("A", &SolidLocationDetail::GetA, &SolidLocationDetail::SetA);
    c4.def("GetA", &SolidLocationDetail::GetA, DOC(Bentley, Geom, SolidLocationDetail, GetA));
    c4.def("SetA", &SolidLocationDetail::SetA, "a"_a, DOC(Bentley, Geom, SolidLocationDetail, SetA));
    
    c4.def_property("UDirection", &SolidLocationDetail::GetUDirection, &SolidLocationDetail::SetUDirection);
    c4.def("GetUDirection", &SolidLocationDetail::GetUDirection, DOC(Bentley, Geom, SolidLocationDetail, GetUDirection));
    c4.def("SetUDirection", &SolidLocationDetail::SetUDirection, "dXdv"_a, DOC(Bentley, Geom, SolidLocationDetail, SetUDirection));
    
    c4.def_property("VDirection", &SolidLocationDetail::GetVDirection, &SolidLocationDetail::SetVDirection);
    c4.def("GetVDirection", &SolidLocationDetail::GetVDirection, DOC(Bentley, Geom, SolidLocationDetail, GetVDirection));
    c4.def("SetVDirection", &SolidLocationDetail::SetVDirection, "dXdv"_a, DOC(Bentley, Geom, SolidLocationDetail, SetVDirection));

    c4.def("SetUV", py::overload_cast<double, double, DVec3dCR, DVec3dCR>(&SolidLocationDetail::SetUV), "u"_a, "v"_a, "uDirection"_a, "vDirection"_a, DOC(Bentley, Geom, SolidLocationDetail, SetUV));

    c4.def("IsCapSelect", [] (SolidLocationDetailCR self)
           {
           int capId = -1;
           bool bOk = self.IsCapSelect(capId);
           return py::make_tuple(bOk, capId);
           });

    c4.def_static("IsCap0", &SolidLocationDetail::IsCap0, "selector0"_a, "selector1"_a, DOC(Bentley, Geom, SolidLocationDetail, IsCap0));
    c4.def_static("IsCap1", &SolidLocationDetail::IsCap1, "selector0"_a, "selector1"_a, DOC(Bentley, Geom, SolidLocationDetail, IsCap1));

    c4.def("TransformInPlace", &SolidLocationDetail::TransformInPlace, "transform"_a, DOC(Bentley, Geom, SolidLocationDetail, TransformInPlace));
    c4.def("MapPickParameterFractionToRange", &SolidLocationDetail::MapPickParameterFractionToRange, "range"_a, DOC(Bentley, Geom, SolidLocationDetail, MapPickParameterFractionToRange));
    c4.def("UpdateIfSmallerA", &SolidLocationDetail::UpdateIfSmallerA, "source"_a);

    c4.def("__repr__", [] (SolidLocationDetail& self)
           {
           return "(u:{}, v:{}, a:{}, uDir:{}, vDir:{}, xyz:{})"_s
               .format(self.GetU(), self.GetV(), self.GetA(), self.GetUDirection(), self.GetVDirection(), self.GetXYZ());
           });

    c4.def("__copy__", [](const SolidLocationDetail& self)
        {
        return SolidLocationDetail(self);
        });

    //===================================================================================
    // struct FacetEdgeLocationDetail
    py::class_<FacetEdgeLocationDetail> c5(m, "FacetEdgeLocationDetail");

    c5.def(py::init<>());
    c5.def(py::init<size_t, double>(), "readIndex"_a, "fraction"_a);
    c5.def_readwrite("readIndex", &FacetEdgeLocationDetail::m_readIndex);
    c5.def_readwrite("fraction", &FacetEdgeLocationDetail::m_fraction); 

    c5.def("__repr__", [] (FacetEdgeLocationDetail& self)
           {
           return "(readIndex:{}, fraction:{})"_s.format(self.m_readIndex, self.m_fraction);
           });

    c5.def("__copy__", [](const FacetEdgeLocationDetail& self)
        {
        return FacetEdgeLocationDetail(self);
        });

    //===================================================================================
    // struct CurveOffsetOptions
    py::class_<CurveOffsetOptions> c6(m, "CurveOffsetOptions");
    
    c6.def(py::init<double>(), "offsetDistance"_a);

    c6.def_property("Tolerance", &CurveOffsetOptions::GetTolerance, &CurveOffsetOptions::SetTolerance);
    c6.def("GetTolerance", &CurveOffsetOptions::GetTolerance);
    c6.def("SetTolerance", &CurveOffsetOptions::SetTolerance, "tol"_a);

    c6.def_property("OffsetDistance", &CurveOffsetOptions::GetOffsetDistance, &CurveOffsetOptions::SetOffsetDistance);
    c6.def("GetOffsetDistance", &CurveOffsetOptions::GetOffsetDistance);
    c6.def("SetOffsetDistance", &CurveOffsetOptions::SetOffsetDistance, "distance"_a);

    c6.def_property("ArcAngle", &CurveOffsetOptions::GetArcAngle, &CurveOffsetOptions::SetArcAngle);
    c6.def("GetArcAngle", &CurveOffsetOptions::GetArcAngle);
    c6.def("SetArcAngle", &CurveOffsetOptions::SetArcAngle, "valueRadians"_a);

    c6.def_property("ChamferAngle", &CurveOffsetOptions::GetChamferAngle, &CurveOffsetOptions::SetChamferAngle);
    c6.def("GetChamferAngle", &CurveOffsetOptions::GetChamferAngle);
    c6.def("SetChamferAngle", &CurveOffsetOptions::SetChamferAngle, "value"_a);

    c6.def_property("ForceClosure", &CurveOffsetOptions::GetForceClosure, &CurveOffsetOptions::SetForceClosure);
    c6.def("GetForceClosure", &CurveOffsetOptions::GetForceClosure);
    c6.def("SetForceClosure", &CurveOffsetOptions::SetForceClosure, "value"_a);

    c6.def_property("BCurvePointsPerKnot", &CurveOffsetOptions::GetBCurvePointsPerKnot, &CurveOffsetOptions::SetBCurvePointsPerKnot);
    c6.def("GetBCurvePointsPerKnot", &CurveOffsetOptions::GetBCurvePointsPerKnot);
    c6.def("SetBCurvePointsPerKnot", &CurveOffsetOptions::SetBCurvePointsPerKnot, "n"_a);

    c6.def_property("BCurveMethod", &CurveOffsetOptions::GetBCurveMethod, &CurveOffsetOptions::SetBCurveMethod);
    c6.def("GetBCurveMethod", &CurveOffsetOptions::GetBCurveMethod);
    c6.def("SetBCurveMethod", &CurveOffsetOptions::SetBCurveMethod, "n"_a);

    c6.def("__repr__", [] (CurveOffsetOptions& self)
           {
           return "(Tolerance:{}, OffsetDistance:{}, ArcAngle:{}, ChamferAngle:{}, ForceClosure:{}, BCurvePointsPerKnot:{}, BCurveMethod:{})"_s
               .format(self.GetTolerance(), self.GetOffsetDistance(), self.GetArcAngle(), self.GetChamferAngle(), self.GetForceClosure(), self.GetBCurvePointsPerKnot(), self.GetBCurveMethod());
           });

    c6.def("__copy__", [](const CurveOffsetOptions& self)
        {
        return CurveOffsetOptions(self);
        });


    //===================================================================================
    // struct CurveGapOptions
    py::class_<CurveGapOptions> c7(m, "CurveGapOptions");

    c7.def(py::init<>());
    c7.def(py::init<double, double, double>(), "equalPointTolerance"_a, "maxDirectAdjust"_a, "maxAdjustAlongCurve"_a);
    
    c7.def_property("EqualPointTolerance", &CurveGapOptions::GetEqualPointTolerance, &CurveGapOptions::SetEqualPointTolerance);
    c7.def("GetEqualPointTolerance", &CurveGapOptions::GetEqualPointTolerance, DOC(Bentley, Geom, CurveGapOptions, GetEqualPointTolerance));
    c7.def("SetEqualPointTolerance", &CurveGapOptions::SetEqualPointTolerance, "value"_a, DOC(Bentley, Geom, CurveGapOptions, SetEqualPointTolerance));

    c7.def_property("MaxDirectAdjustTolerance", &CurveGapOptions::GetMaxDirectAdjustTolerance, &CurveGapOptions::SetMaxDirectAdjustTolerance);
    c7.def("GetMaxDirectAdjustTolerance", &CurveGapOptions::GetMaxDirectAdjustTolerance, DOC(Bentley, Geom, CurveGapOptions, GetMaxDirectAdjustTolerance));
    c7.def("SetMaxDirectAdjustTolerance", &CurveGapOptions::SetMaxDirectAdjustTolerance, "value"_a, DOC(Bentley, Geom, CurveGapOptions, SetMaxDirectAdjustTolerance));

    c7.def_property("MaxAdjustAlongCurve", &CurveGapOptions::GetMaxAdjustAlongCurve, &CurveGapOptions::SetMaxAdjustAlongCurve);
    c7.def("GetMaxAdjustAlongCurve", &CurveGapOptions::GetMaxAdjustAlongCurve, DOC(Bentley, Geom, CurveGapOptions, GetMaxAdjustAlongCurve));
    c7.def("SetMaxAdjustAlongCurve", &CurveGapOptions::SetMaxAdjustAlongCurve, "value"_a, DOC(Bentley, Geom, CurveGapOptions, SetMaxAdjustAlongCurve));

    c7.def_property("RemovePriorGapPrimitives", &CurveGapOptions::GetRemovePriorGapPrimitives, &CurveGapOptions::SetRemovePriorGapPrimitives);
    c7.def("GetRemovePriorGapPrimitives", &CurveGapOptions::GetRemovePriorGapPrimitives, DOC(Bentley, Geom, CurveGapOptions, GetRemovePriorGapPrimitives));
    c7.def("SetRemovePriorGapPrimitives", &CurveGapOptions::SetRemovePriorGapPrimitives, "value"_a, DOC(Bentley, Geom, CurveGapOptions, SetRemovePriorGapPrimitives));

    c7.def("__repr__", [] (CurveGapOptions& self)
           {
           return "(EqualPointTolerance:{}, MaxDirectAdjustTolerance:{}, MaxAdjustAlongCurve:{}, RemovePriorGapPrimitives:{}"_s
               .format(self.GetEqualPointTolerance(), self.GetMaxDirectAdjustTolerance(), self.GetMaxAdjustAlongCurve(), self.GetRemovePriorGapPrimitives());
           });

    c7.def("__copy__", [](const CurveGapOptions& self)
        {
        return CurveGapOptions(self);
        });

    //===================================================================================
    // Enum BlendType
    py::enum_<BlendType>(m, "BlendType", py::arithmetic())
        .value("eCURVE_CURVE_BLEND_BisectorParabola", BlendType::CURVE_CURVE_BLEND_BisectorParabola)
        .value("eCURVE_CURVE_BLEND_VerticalAxisParabola", BlendType::CURVE_CURVE_BLEND_VerticalAxisParabola)
        .export_values();

    //===================================================================================
    // Enum AreaSelect
    py::enum_<AreaSelect>(m, "AreaSelect", py::arithmetic())
        .value("eAreaSelect_Parity", AreaSelect::AreaSelect_Parity)
        .value("eAreaSelect_CCWPositiveWindingNumber", AreaSelect::AreaSelect_CCWPositiveWindingNumber)
        .value("eAreaSelect_CCWNonzeroWindingNumber", AreaSelect::AreaSelect_CCWNonzeroWindingNumber)
        .value("eAreaSelect_CCWNegativeWindingNumber", AreaSelect::AreaSelect_CCWNegativeWindingNumber)
        .export_values();

    //===================================================================================
    // Enum BoolSelect
    py::enum_<BoolSelect>(m, "BoolSelect", py::arithmetic())
        .value("eBoolSelect_Parity", BoolSelect::BoolSelect_Parity)
        .value("eBoolSelect_Union", BoolSelect::BoolSelect_Union)
        .value("eBoolSelect_Summed_Parity", BoolSelect::BoolSelect_Summed_Parity)
        .value("eBoolSelect_Summed_Positive", BoolSelect::BoolSelect_Summed_Positive)
        .value("eBoolSelect_Summed_NonZero", BoolSelect::BoolSelect_Summed_NonZero)
        .value("eBoolSelect_Summed_Negative", BoolSelect::BoolSelect_Summed_Negative)
        .value("eBoolSelect_FromStructure", BoolSelect::BoolSelect_FromStructure)
        .export_values();

    //===================================================================================
    // struct BlendDetail
    py::class_<BlendDetail> c8(m, "BlendDetail");
    py::bind_vector< BlendDetailArray >(m, "BlendDetailArray", py::module_local(false));

    c8.def_readwrite("detailA", &BlendDetail::detailA);
    c8.def_readwrite("detailB", &BlendDetail::detailB);
    c8.def_readwrite("geometry", &BlendDetail::geometry);

    c8.def("__repr__", [] (BlendDetail& self)
           {
           return "(detailA:{}, detailB:{}, geometry:{})"_s.format(self.detailA, self.detailB, self.geometry);
           });
    c8.def("__copy__", [](const BlendDetail& self)
        {
        return BlendDetail(self);
        });

    
    //===================================================================================
    // struct LocalRange
    py::class_<LocalRange> c9(m, "LocalRange");
    bind_ValidatedValue<LocalRange>(m, "ValidatedLocalRange", py::module_local(false));

    c9.def_readwrite("localToWorld", &LocalRange::m_localToWorld);
    c9.def_readwrite("worldToLocal", &LocalRange::m_worldToLocal);
    c9.def_readwrite("localRange", &LocalRange::m_localRange);
    c9.def_readwrite("worldRange", &LocalRange::m_worldRange);
    c9.def(py::init<>());
    c9.def(py::init<TransformCR, TransformCR, DRange3dCR>(), "localToWorld"_a, "worldToLocal"_a, "localRange"_a);    

    c9.def("InitNullRange", &LocalRange::InitNullRange, DOC(Bentley, Geom, LocalRange, InitNullRange));        
    c9.def("InitFromPrincipalAxesOfPoints", py::overload_cast<DPoint3dArray const&>(&LocalRange::InitFromPrincipalAxesOfPoints), "xyz"_a);
    c9.def("InitFromPrincipalAxesOfPoints", py::overload_cast<DPoint4dArray const&>(&LocalRange::InitFromPrincipalAxesOfPoints), "xyzw"_a);

    c9.def("DistanceOutside", &LocalRange::DistanceOutside, "spacePoint"_a);

    c9.def("__repr__", [] (LocalRange& self)
           {
           return "(localToWorld:{}, worldToLocal:{}, localRange:{}, worldRange:{})"_s.format(self.m_localToWorld, self.m_worldToLocal, self.m_localRange, self.m_worldRange);
           });

    c9.def("__copy__", [](const LocalRange& self)
        {
        return LocalRange(self);
        });

    //===================================================================================
    // struct TaggedLocalRange
    py::class_<TaggedLocalRange, LocalRange> c10(m, "TaggedLocalRange");
    
    c10.def(py::init<size_t, size_t, double>(), "indexA"_a, "indexB"_a, "a"_a = 0.0);
    c10.def_readwrite("indexA", &TaggedLocalRange::m_indexA);
    c10.def_readwrite("indexB", &TaggedLocalRange::m_indexB);
    c10.def_readwrite("a", &TaggedLocalRange::m_a);    
    c10.def_static("SortByA", &TaggedLocalRange::SortByA, "data"_a);
    c10.def("SetDistanceOutside", &TaggedLocalRange::SetDistanceOutside, "spacePoint"_a);

    c10.def("__repr__", [] (TaggedLocalRange& self)
            {
            return "(indexA:{}, indexB:{}, a:{})"_s.format(self.m_indexA, self.m_indexB, self.m_a);
            });
    c10.def("__copy__", [](const TaggedLocalRange& self)
        {
        return TaggedLocalRange(self);
        });

    //===================================================================================
    // struct CurveAndSolidLocationDetail
    py::class_<CurveAndSolidLocationDetail> c11(m, "CurveAndSolidLocationDetail");
    py::bind_vector< CurveAndSolidLocationDetailArray >(m, "CurveAndSolidLocationDetailArray", py::module_local(false));
    
    c11.def(py::init<CurveLocationDetailCR, SolidLocationDetailCR>(), "curveDetail"_a, "solidDetail"_a);
    c11.def_readwrite("curveDetail", &CurveAndSolidLocationDetail::m_curveDetail);
    c11.def_readwrite("solidDetail", &CurveAndSolidLocationDetail::m_solidDetail);

    c11.def("__repr__", [] (CurveAndSolidLocationDetail& self)
            {
            return "(curveDetail:{}, solidDetail:{})"_s.format(self.m_curveDetail, self.m_solidDetail);
            });
    c11.def("__copy__", [](const CurveAndSolidLocationDetail& self)
        {
        return CurveAndSolidLocationDetail(self);
        });

    //===================================================================================
    // struct CurveKeyPointCollector
    py::class_<CurveKeyPointCollector> c12(m, "CurveKeyPointCollector");
    if (true)
        {
        py::enum_<CurveKeyPointCollector::KeyPointType>(c12, "KeyPointType", py::arithmetic())
            .value("eEndPoint", CurveKeyPointCollector::EndPoint)
            .value("ePerpendicular", CurveKeyPointCollector::Perpendicular)
            .value("eTangency", CurveKeyPointCollector::Tangency)
            .value("eBreakPoint", CurveKeyPointCollector::BreakPoint)
            .value("eNumTypes", CurveKeyPointCollector::NumTypes)
            .export_values();
        }

    c12.def(py::init<>());
    c12.def("EnableKeyPointType", &CurveKeyPointCollector::EnableKeyPointType, "selector"_a, "value"_a, DOC(Bentley, Geom, CurveKeyPointCollector, EnableKeyPointType));
    c12.def("EnableSingleKeyPointType", &CurveKeyPointCollector::EnableSingleKeyPointType, "selector"_a, DOC(Bentley, Geom, CurveKeyPointCollector, EnableSingleKeyPointType));
    c12.def("SetXYOnly", &CurveKeyPointCollector::SetXYOnly, "worldToLocal"_a, DOC(Bentley, Geom, CurveKeyPointCollector, SetXYOnly));
    c12.def("NeedKeyPointType", &CurveKeyPointCollector::NeedKeyPointType, "selector"_a, DOC(Bentley, Geom, CurveKeyPointCollector, NeedKeyPointType));
    c12.def("GetWorldToLocal", &CurveKeyPointCollector::GetWorldToLocal, "worldToLocal"_a, DOC(Bentley, Geom, CurveKeyPointCollector, GetWorldToLocal));

    //===================================================================================
    // struct CurveKeyPoint_ClosestPointCollector
    py::class_<CurveKeyPoint_ClosestPointCollector, CurveKeyPointCollector> c13(m, "CurveKeyPoint_ClosestPointCollector");

    c13.def(py::init<DPoint3dCR>(), "biasPoint"_a);
    c13.def("AnnouncePoint", &CurveKeyPoint_ClosestPointCollector::AnnouncePoint, "worldDetail"_a, "selector"_a, DOC(Bentley, Geom, CurveKeyPoint_ClosestPointCollector, AnnouncePoint));
    c13.def("GetResult", [] (CurveKeyPoint_ClosestPointCollector const& self)
            {
            CurveLocationDetail detail;
            auto selector = CurveKeyPointCollector::EndPoint;
            bool bOk = self.GetResult(detail, selector);
            return py::make_tuple(bOk, detail, selector);
            }, DOC(Bentley, Geom, CurveKeyPoint_ClosestPointCollector, GetResult));

    }