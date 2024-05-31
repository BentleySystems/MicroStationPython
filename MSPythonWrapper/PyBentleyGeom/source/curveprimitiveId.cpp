/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyBentleyGeom\source\curveprimitiveId.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"



static const char * __doc_Bentley_Geom_CurvePrimitiveId_Store =R"doc(Copy the id data into bytes.)doc";

static const char * __doc_Bentley_Geom_CurvePrimitiveId_GetLineStringAssociationIds =R"doc(If this is a Type_PolyfaceCut with exactly nTargetIds id values, copy
out the topology type and the ids.)doc";

static const char * __doc_Bentley_Geom_CurvePrimitiveId_GetSolidPrimitiveId =R"doc(Copy data to target object if this is a solid primitive.)doc";

static const char * __doc_Bentley_Geom_CurvePrimitiveId_GetParasolidBodyId =R"doc(Copy data to target object if this is a parasolid body.)doc";

static const char * __doc_Bentley_Geom_CurvePrimitiveId_Clone =R"doc(Return a copy.)doc";

static const char * __doc_Bentley_Geom_CurvePrimitiveId_GetCurveTopologyId =R"doc(Return the topologyId object. This may fail (and return defaulted
structure) for some types.)doc";

static const char * __doc_Bentley_Geom_CurvePrimitiveId_GetType =R"doc(Get the type code.)doc";

static const char * __doc_Bentley_Geom_CurvePrimitiveId_GetRawIdString =R"doc(Get hex form of the ids)doc";

static const char * __doc_Bentley_Geom_CurvePrimitiveId_GetDebugString =R"doc(Get debug string)doc";

static const char * __doc_Bentley_Geom_CurvePrimitiveId_SetCompoundDrawState =R"doc(Set the compound draw state.)doc";

static const char * __doc_Bentley_Geom_CurvePrimitiveId_GetCompoundDrawState =R"doc(Query the compound draw state (refCounted))doc";

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_CurvePrimitiveId(py::module_& m)
    {
    //===================================================================================
    // struct CurvePrimitiveId
    py::class_<CurvePrimitiveId, CurvePrimitiveIdPtr> c1(m, "CurvePrimitiveId");
    if (true)
        {
        py::enum_<CurvePrimitiveId::Type>(c1, "Type")
            .value("eType_ParaSolidCut", CurvePrimitiveId::Type_ParaSolidCut)
            .value("eType_UnusedWasFacetSet", CurvePrimitiveId::Type_UnusedWasFacetSet)
            .value("eType_ACISCut", CurvePrimitiveId::Type_ACISCut)
            .value("eType_CachedEdge", CurvePrimitiveId::Type_CachedEdge)
            .value("eType_CachedCut", CurvePrimitiveId::Type_CachedCut)
            .value("eType_CachedUnderlay", CurvePrimitiveId::Type_CachedUnderlay)
            .value("eType_ParaSolidBody", CurvePrimitiveId::Type_ParaSolidBody)
            .value("eType_SolidPrimitive", CurvePrimitiveId::Type_SolidPrimitive)
            .value("eType_CurveVector", CurvePrimitiveId::Type_CurveVector)
            .value("eType_PolyfaceCut", CurvePrimitiveId::Type_PolyfaceCut)
            .value("eType_PolyfaceEdge", CurvePrimitiveId::Type_PolyfaceEdge)
            .value("eType_UnspecifiedTopologyId", CurvePrimitiveId::Type_UnspecifiedTopologyId)
            .value("eType_OpenCascadeBody", CurvePrimitiveId::Type_OpenCascadeBody)
            .value("eType_Max", CurvePrimitiveId::Type_Max)
            .value("eType_CutGeometry", CurvePrimitiveId::Type_CutGeometry)
            .export_values();
        }

    c1.def(py::init([] (CurvePrimitiveId::Type type, py::bytes const& data, CompoundDrawStateP cds)
                    {
                    std::string strData = (std::string) data;
                    return CurvePrimitiveId::Create(type, (void const*)strData.data(), strData.size(), cds);
                    }), "type"_a, "data"_a, "cds"_a);

    c1.def(py::init(py::overload_cast<CurvePrimitiveId::Type, CurveTopologyIdCR, CompoundDrawStateP>(&CurvePrimitiveId::Create)), "type"_a, "topologyId"_a, "cds"_a);
    
    c1.def(py::init([] (py::bytes const& data)
                    {
                    std::string strData = (std::string) data;
                    return CurvePrimitiveId::Create((void const*) strData.data(), strData.size());
                    }), "data"_a);

    c1.def(py::init(py::overload_cast<CurvePrimitiveIdCR>(&CurvePrimitiveId::Create)), "id"_a);

    c1.def("GetCompoundDrawState", &CurvePrimitiveId::GetCompoundDrawState, DOC(Bentley, Geom, CurvePrimitiveId, GetCompoundDrawState));
    c1.def("SetCompoundDrawState", [] (CurvePrimitiveId& self, CompoundDrawStateP state)
           {
           CompoundDrawStatePtr statePtr(state);
           self.SetCompoundDrawState(statePtr);
           }, DOC(Bentley, Geom, CurvePrimitiveId, SetCompoundDrawState));

    c1.def_property_readonly("DebugString", &CurvePrimitiveId::GetDebugString);
    c1.def("GetDebugString", &CurvePrimitiveId::GetDebugString, DOC(Bentley, Geom, CurvePrimitiveId, GetDebugString));

    c1.def_property_readonly("RawIdString", &CurvePrimitiveId::GetRawIdString);
    c1.def("GetRawIdString", &CurvePrimitiveId::GetRawIdString, DOC(Bentley, Geom, CurvePrimitiveId, GetRawIdString));

    c1.def_property_readonly("Type", &CurvePrimitiveId::GetType);
    c1.def("GetType", &CurvePrimitiveId::GetType, DOC(Bentley, Geom, CurvePrimitiveId, GetType));

    c1.def_property_readonly("CurveTopologyId", &CurvePrimitiveId::GetCurveTopologyId);
    c1.def("GetCurveTopologyId", &CurvePrimitiveId::GetCurveTopologyId, DOC(Bentley, Geom, CurvePrimitiveId, GetCurveTopologyId));

    c1.def(py::self == py::self);
    c1.def(py::self < py::self);
            
    c1.def("Clone", &CurvePrimitiveId::Clone, DOC(Bentley, Geom, CurvePrimitiveId, Clone));
    c1.def("GetParasolidBodyId", &CurvePrimitiveId::GetParasolidBodyId, "id"_a, DOC(Bentley, Geom, CurvePrimitiveId, GetParasolidBodyId));
    c1.def("GetSolidPrimitiveId", &CurvePrimitiveId::GetSolidPrimitiveId, "id"_a, DOC(Bentley, Geom, CurvePrimitiveId, GetSolidPrimitiveId));

    c1.def("GetLineStringAssociationIds", [] (CurvePrimitiveIdR self, size_t nTargetIds)
           {
           int topologyType = 0;
           UInt32Array ids;
           BentleyStatus retVal = self.GetLineStringAssociationIds(topologyType, ids, nTargetIds);
           return py::make_tuple(retVal, topologyType, ids);
           }, "nTargetIds"_a, DOC(Bentley, Geom, CurvePrimitiveId, GetLineStringAssociationIds));

    c1.def("Store", &CurvePrimitiveId::Store, "data"_a, DOC(Bentley, Geom, CurvePrimitiveId, Store));

    c1.def("__repr__", [] (CurvePrimitiveIdR self) { return self.GetDebugString().c_str(); });
    c1.def("__copy__", [] (const CurvePrimitiveId& self) { return CurvePrimitiveId (self); });
    }