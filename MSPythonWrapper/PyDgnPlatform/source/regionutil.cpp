/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnPlatform\source\regionutil.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <DgnPlatform/RegionUtil.h>



static const char * __doc_Bentley_DgnPlatform_RegionGraphicsContext_Create =R"doc(Create an instance of an RegionGraphicsContext for the purpose of
creating closed regions by flood or boolean operation.

:returns:
    A reference counted pointer to a RegionGraphicsContext.)doc";

static const char * __doc_Bentley_DgnPlatform_RegionGraphicsContext_GetAssociativeRegion =R"doc(Return region result as an associative region element. @note The
supplied boundary candidates must be persistent elements or an
associative region can't be created.)doc";

static const char * __doc_Bentley_DgnPlatform_RegionGraphicsContext_GetRegion =R"doc(Return region result as a CurveVector that represents a closed path,
parity region, or union region.
Returns (Tuple, 0):
	retVal.

Returns (Tuple, 1):
	region.

)doc";

static const char * __doc_Bentley_DgnPlatform_RegionGraphicsContext_InitRegionParams =R"doc(Initialize associative region element parameters from current context
settings for use with GetAssociativeRegion.)doc";

static const char * __doc_Bentley_DgnPlatform_RegionGraphicsContext_Boolean =R"doc(Create closed regions by boolean of curve vectors.)doc";

static const char * __doc_Bentley_DgnPlatform_RegionGraphicsContext_Flood =R"doc(Find closed regions from supplied boundary candidates using flood
parameters and seed point locations. @note inTrans is an array pf size
in.GetCount of tranforms for each boundary candidate, can be NULL if
all boundaries are in the coordinates of the targetModel.)doc";

static const char * __doc_Bentley_DgnPlatform_RegionGraphicsContext_SetFlattenBoundary =R"doc(Set a flatten transform for producing a planar region from non-planar
boundaries.)doc";

static const char * __doc_Bentley_DgnPlatform_RegionGraphicsContext_SetInteriorText =R"doc(Set flood parameters for treating text as holes.)doc";

static const char * __doc_Bentley_DgnPlatform_RegionGraphicsContext_SetFloodParams =R"doc(Set flood parameters for boundary gap tolerance and finding interior
holes.)doc";

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_RegionUtil(py::module_& m)
    {

    //===================================================================================
    // struct RegionGraphicsContext
    py::class_< RegionGraphicsContext> c2(m, "RegionGraphicsContext");

    c2.def("SetFloodParams", &RegionGraphicsContext::SetFloodParams, "regionLops"_a, "gapTolerance"_a, "stepOutOfHoles"_a = false, DOC(Bentley, DgnPlatform, RegionGraphicsContext, SetFloodParams));
    c2.def("SetInteriorText", &RegionGraphicsContext::SetInteriorText, "interiorText"_a, "textMarginFactor"_a, DOC(Bentley, DgnPlatform, RegionGraphicsContext, SetInteriorText));
    c2.def("SetFlattenBoundary", py::overload_cast<TransformCR>(&RegionGraphicsContext::SetFlattenBoundary), "flattenTrans"_a, DOC(Bentley, DgnPlatform, RegionGraphicsContext, SetFlattenBoundary));
    c2.def("SetFlattenBoundary", py::overload_cast<DVec3dCR>(&RegionGraphicsContext::SetFlattenBoundary), "flattenDir"_a, DOC(Bentley, DgnPlatform, RegionGraphicsContext, SetFlattenBoundary));

    c2.def("Flood", [] (RegionGraphicsContext& self, DgnModelRefR targetModel, ElementAgendaCR in, TransformCP inTrans, DPoint3dArray const& seedPoints)
           {
           return self.Flood(targetModel, in, inTrans, seedPoints.data(), seedPoints.size());
           }, "targetModel"_a, "in"_a, "inTrans"_a, "seedPoints"_a, DOC(Bentley, DgnPlatform, RegionGraphicsContext, Flood));

   c2.def("Flood", [] (RegionGraphicsContext& self, DgnModelRefR targetModel, ElementAgendaCR in, TransformCP inTrans, py::list const& seedPoints)
           {
           CONVERT_PYLIST_TO_NEW_CPPARRAY(seedPoints, cppSeedPoints, DPoint3dArray, DPoint3d);
           return self.Flood(targetModel, in, inTrans, cppSeedPoints.data(), cppSeedPoints.size());
           }, "targetModel"_a, "in"_a, "inTrans"_a, "seedPoints"_a, DOC(Bentley, DgnPlatform, RegionGraphicsContext, Flood));

    c2.def("Boolean",
           py::overload_cast<DgnModelRefR, bvector<CurveVectorPtr> const&, RegionType>(&RegionGraphicsContext::Boolean),
           "targetModel"_a, "in"_a, "operation"_a, DOC(Bentley, DgnPlatform, RegionGraphicsContext, Boolean));

    c2.def("Boolean", [](RegionGraphicsContextR self, DgnModelRefR targetModel, py::list const& in, RegionType operation){
       bvector<CurveVectorPtr> cppIn;
       for (const auto& item : in) {
            cppIn.push_back(item.cast<CurveVectorPtr>());
       }
       return self.Boolean(targetModel, cppIn, operation);
    }, "targetModel"_a, "in"_a, "operation"_a, DOC(Bentley, DgnPlatform, RegionGraphicsContext, Boolean));
   
    c2.def("Boolean",
           py::overload_cast<DgnModelRefR, ElementAgendaCR, TransformCP, RegionType>(&RegionGraphicsContext::Boolean),
           "targetModel"_a, "in"_a, "inTrans"_a, "operation"_a, DOC(Bentley, DgnPlatform, RegionGraphicsContext, Boolean));

    c2.def("Boolean",
           py::overload_cast<DgnModelRefR, ElementAgendaCR, ElementAgendaCR, TransformCP, TransformCP, RegionType>(&RegionGraphicsContext::Boolean),
           "targetModel"_a, "target"_a, "tool"_a, "targetTrans"_a, "toolTrans"_a, "operation"_a, DOC(Bentley, DgnPlatform, RegionGraphicsContext, Boolean));

    c2.def("InitRegionParams", &RegionGraphicsContext::InitRegionParams, "params"_a, DOC(Bentley, DgnPlatform, RegionGraphicsContext, InitRegionParams));

    c2.def("GetRegion", [] (RegionGraphicsContext& self)
           {
           CurveVectorPtr region;
           auto retVal = self.GetRegion(region);
           return py::make_tuple(retVal, region);
           }, DOC(Bentley, DgnPlatform, RegionGraphicsContext, GetRegion));

    c2.def("GetRegion", py::overload_cast<EditElementHandleR>(&RegionGraphicsContext::GetRegion), "eeh"_a, DOC(Bentley, DgnPlatform, RegionGraphicsContext, GetRegion));
    c2.def("GetRegion", &RegionGraphicsContext::GetRegions, "out"_a, DOC(Bentley, DgnPlatform, RegionGraphicsContext, GetRegion));
    c2.def("GetAssociativeRegion", &RegionGraphicsContext::GetAssociativeRegion, "eeh"_a, "params"_a, "cellName"_a, DOC(Bentley, DgnPlatform, RegionGraphicsContext, GetAssociativeRegion));

    c2.def_static("Create", &RegionGraphicsContext::Create, DOC(Bentley, DgnPlatform, RegionGraphicsContext, Create));
    }