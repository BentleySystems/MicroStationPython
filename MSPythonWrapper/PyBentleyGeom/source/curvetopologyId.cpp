/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyBentleyGeom\source\curvetopologyId.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"



static const char * __doc_Bentley_Geom_CurveTopologyId_GetBRepSheetEdge =R"doc(extract adjacent face of brep edge)doc";

static const char * __doc_Bentley_Geom_CurveTopologyId_GetBRepSharedEdge =R"doc(extract adjacent faces of brep edge)doc";

static const char * __doc_Bentley_Geom_CurveTopologyId_GetBRepIsoline =R"doc(Extract brep isoline.)doc";

static const char * __doc_Bentley_Geom_CurveTopologyId_FromCurveVector =R"doc(construct and return for curve vector)doc";

static const char * __doc_Bentley_Geom_CurveTopologyId_FromVisEdgesIntersection =R"doc(construct and return for intersection curve in visible edges)doc";

static const char * __doc_Bentley_Geom_CurveTopologyId_FromParasolidGPArrayId =R"doc(construct and return from Parasolid parasolid GPArray ID)doc";

static const char * __doc_Bentley_Geom_CurveTopologyId_FromVisEdgesBoundedPlane =R"doc(construct and return for indexed loop in visible edges)doc";

static const char * __doc_Bentley_Geom_CurveTopologyId_FromUnknownCurve =R"doc(construct and return for unknown curve)doc";

static const char * __doc_Bentley_Geom_CurveTopologyId_FromWire =R"doc(construct and return for wire edge)doc";

static const char * __doc_Bentley_Geom_CurveTopologyId_FromGeometryMap =R"doc(construct and return for geometry map.)doc";

static const char * __doc_Bentley_Geom_CurveTopologyId_FromMeshEdgeVertices =R"doc(construct and return for mesh edge with 2 vertices)doc";

static const char * __doc_Bentley_Geom_CurveTopologyId_FromMeshSharedEdge =R"doc(construct and return for mesh edge with 2 faces)doc";

static const char * __doc_Bentley_Geom_CurveTopologyId_FromSweepSilhouette =R"doc(construct and return for silhouette of sweep)doc";

static const char * __doc_Bentley_Geom_CurveTopologyId_FromSweepLateral =R"doc(construct and return for indexed lateral within sweep.)doc";

static const char * __doc_Bentley_Geom_CurveTopologyId_FromSweepProfile =R"doc(construct and return for index of swept profile curve.)doc";

static const char * __doc_Bentley_Geom_CurveTopologyId_FromBRepPlanarFace =R"doc(Construct and return for brep edge with one face.)doc";

static const char * __doc_Bentley_Geom_CurveTopologyId_FromBRepSilhouette =R"doc(Construct and return for brep silhouette edge.)doc";

static const char * __doc_Bentley_Geom_CurveTopologyId_FromBRepSheetEdge =R"doc(Construct and return for brep edge with one face.)doc";

static const char * __doc_Bentley_Geom_CurveTopologyId_FromBRepSharedEdge =R"doc(Construct an return for brep edge with two faces.)doc";

static const char * __doc_Bentley_Geom_CurveTopologyId_FromBRepIsoline =R"doc(construct and return with FaceId and isolineIndex)doc";

static const char * __doc_Bentley_Geom_CurveTopologyId_Clear =R"doc(Clear the id array and set the type code to default unknown value.)doc";

static const char * __doc_Bentley_Geom_CurveTopologyId_IsEmpty =R"doc(Return true if there are no ids.)doc";

static const char * __doc_Bentley_Geom_CurveTopologyId_Pack =R"doc(Return a packed form of the ids.)doc";

static const char * __doc_Bentley_Geom_CurveTopologyId_GetDebugString =R"doc(Return debug string form)doc";

static const char * __doc_Bentley_Geom_CurveTopologyId_GetId =R"doc(Return id by index)doc";

static const char * __doc_Bentley_Geom_CurveTopologyId_GetCount =R"doc(Return the id data count (in UInt32's))doc";

static const char * __doc_Bentley_Geom_CurveTopologyId_GetType =R"doc(Return the type code)doc";

static const char * __doc_Bentley_Geom_CurveTopologyId_Init =R"doc(Initializer with type code and array of ids.)doc";

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_CurveTopologyId(py::module_& m)
    {
    //===================================================================================
    // struct CurveTopologyId
    py::class_<CurveTopologyId> c1(m, "CurveTopologyId");
    py::bind_vector<CurveTopologyIdArray>(m, "CurveTopologyIdArray", py::module_local(false));
    bind_BlockedVector<CurveTopologyId>(m, "BlockedVectorCurveTopologyId", py::module_local(false));

    if (true)
        {
        py::enum_<CurveTopologyId::Type>(c1, "Type")
            .value("eType_Unknown", CurveTopologyId::Type_Unknown)
            .value("eType_BRepSharedEdge", CurveTopologyId::Type_BRepSharedEdge)
            .value("eType_BRepSheetEdge", CurveTopologyId::Type_BRepSheetEdge)
            .value("eType_BRepSilhouette", CurveTopologyId::Type_BRepSilhouette)
            .value("eType_MeshSharedEdge", CurveTopologyId::Type_MeshSharedEdge)
            .value("eType_MeshSheetEdge", CurveTopologyId::Type_MeshSheetEdge)
            .value("eType_MeshUnknown", CurveTopologyId::Type_MeshUnknown)
            .value("eType_IndexedMeshEdge", CurveTopologyId::Type_IndexedMeshEdge)
            .value("eType_Wire", CurveTopologyId::Type_Wire)
            .value("eType_UnannnouncedSectionShape", CurveTopologyId::Type_UnannnouncedSectionShape)
            .value("eType_UnannouncedSectionWire", CurveTopologyId::Type_UnannouncedSectionWire)
            .value("eType_VisEdgesAnalytic", CurveTopologyId::Type_VisEdgesAnalytic)
            .value("eType_VisEdgesBoundedPlane", CurveTopologyId::Type_VisEdgesBoundedPlane)
            .value("eType_GeometryMap", CurveTopologyId::Type_GeometryMap)
            .value("eType_SweepProfile", CurveTopologyId::Type_SweepProfile)
            .value("eType_SweepLateral", CurveTopologyId::Type_SweepLateral)
            .value("eType_CutWires", CurveTopologyId::Type_CutWires)
            .value("eType_CutFill", CurveTopologyId::Type_CutFill)
            .value("eType_VisEdgesIntersection", CurveTopologyId::Type_VisEdgesIntersection)
            .value("eType_SweepSilhouette", CurveTopologyId::Type_SweepSilhouette)
            .value("eType_BRepIsoIsoline", CurveTopologyId::Type_BRepIsoIsoline)
            .value("eType_CurveVector", CurveTopologyId::Type_CurveVector)
            .value("eType_PolyfaceCut", CurveTopologyId::Type_PolyfaceCut)
            .value("eType_PolyfaceEdge", CurveTopologyId::Type_PolyfaceEdge)
            .value("eType_MeshEdgeVertices", CurveTopologyId::Type_MeshEdgeVertices)
            .value("eType_BRepPlanarFace", CurveTopologyId::Type_BRepPlanarFace)
            .value("eType_Max", CurveTopologyId::Type_Max)
            .export_values();
        }

    c1.def(py::init<>());
    c1.def(py::init<CurveTopologyId::Type>(), "type"_a);
    c1.def(py::init<CurveTopologyId::Type, uint32_t>(), "type"_a, "id"_a);
    c1.def(py::init<CurveTopologyId::Type, uint32_t, uint32_t>(), "type"_a, "id0"_a, "id1"_a);
    c1.def(py::init<CurveTopologyId::Type, uint32_t, uint32_t, uint32_t>(), "type"_a, "id0"_a, "id1"_a, "id2"_a);
    c1.def(py::init<CurveTopologyIdCR>(), "rhs"_a);
    c1.def(py::init<CurveTopologyIdCR, uint32_t>(), "curveId"_a, "id"_a);
    c1.def(py::init<uint32_t, CurveTopologyIdCR>(), "id"_a, "curveId"_a);

    c1.def("Init", 
           [](CurveTopologyId& ct, CurveTopologyId::Type type, UInt32Array const& ids) 
           { 
           ct.Init(type, ids.data(), ids.size()); 
           }, "type"_a, "ids"_a, DOC(Bentley, Geom, CurveTopologyId, Init));

    c1.def("Init",
           [] (CurveTopologyId& ct, UInt32Array const& ids)
           {
           ct.Init(ids.data(), ids.size());
           }, "ids"_a, DOC(Bentley, Geom, CurveTopologyId, Init));

    c1.def_property_readonly("Type", &CurveTopologyId::GetType);
    c1.def("GetType", &CurveTopologyId::GetType, DOC(Bentley, Geom, CurveTopologyId, GetType));

    c1.def_property_readonly("Count", &CurveTopologyId::GetCount);
    c1.def("__len__", &CurveTopologyId::GetCount);
    c1.def("GetCount", &CurveTopologyId::GetCount, DOC(Bentley, Geom, CurveTopologyId, GetCount));

    c1.def("GetId", &CurveTopologyId::GetId, "index"_a, DOC(Bentley, Geom, CurveTopologyId, GetId));
    c1.def("__getitem__", [] (CurveTopologyId& self, size_t index)
           {
           if (index >= self.GetCount())
               throw py::index_error();
           return self.GetId(index);
           });

    c1.def_property_readonly("DebugString", &CurveTopologyId::GetDebugString);
    c1.def("GetDebugString", &CurveTopologyId::GetDebugString, DOC(Bentley, Geom, CurveTopologyId, GetDebugString));

    c1.def("Pack", &CurveTopologyId::Pack, "packed"_a, DOC(Bentley, Geom, CurveTopologyId, Pack));

    c1.def("__bool__", [] (CurveTopologyId& self) { return !self.IsEmpty(); });
    c1.def("IsEmpty", &CurveTopologyId::IsEmpty, DOC(Bentley, Geom, CurveTopologyId, IsEmpty));

    c1.def("Clear", &CurveTopologyId::Clear, DOC(Bentley, Geom, CurveTopologyId, Clear));
            
    c1.def(py::self == py::self);
    c1.def(py::self < py::self);

    c1.def_static("FromBRepIsoline", &CurveTopologyId::FromBRepIsoline, "faceId"_a, "isolineIndex"_a, DOC(Bentley, Geom, CurveTopologyId, FromBRepIsoline));
    c1.def_static("FromBRepSharedEdge", &CurveTopologyId::FromBRepSharedEdge, "faceId0"_a, "faceId1"_a, DOC(Bentley, Geom, CurveTopologyId, FromBRepSharedEdge));            
    c1.def_static("FromBRepSheetEdge", &CurveTopologyId::FromBRepSheetEdge, "edgeId"_a, DOC(Bentley, Geom, CurveTopologyId, FromBRepSheetEdge));            
    c1.def_static("FromBRepSilhouette", &CurveTopologyId::FromBRepSilhouette, "edgeId"_a, DOC(Bentley, Geom, CurveTopologyId, FromBRepSilhouette));            
    c1.def_static("FromBRepPlanarFace", &CurveTopologyId::FromBRepPlanarFace, "faceId"_a, DOC(Bentley, Geom, CurveTopologyId, FromBRepPlanarFace));            
    c1.def_static("FromSweepProfile", &CurveTopologyId::FromSweepProfile, "profileIndex"_a, DOC(Bentley, Geom, CurveTopologyId, FromSweepProfile));            
    c1.def_static("FromSweepLateral", &CurveTopologyId::FromSweepLateral, "lateralIndex"_a, DOC(Bentley, Geom, CurveTopologyId, FromSweepLateral));            
    c1.def_static("FromSweepSilhouette", &CurveTopologyId::FromSweepSilhouette, "silhouetteIndex"_a, DOC(Bentley, Geom, CurveTopologyId, FromSweepSilhouette));            
    c1.def_static("FromMeshSharedEdge", &CurveTopologyId::FromMeshSharedEdge, "faceIndex0"_a, "faceIndex1"_a, DOC(Bentley, Geom, CurveTopologyId, FromMeshSharedEdge));            
    c1.def_static("FromMeshEdgeVertices", &CurveTopologyId::FromMeshEdgeVertices, "vertexIndex0"_a, "vertexIndex1"_a, DOC(Bentley, Geom, CurveTopologyId, FromMeshEdgeVertices));            
    c1.def_static("FromGeometryMap", &CurveTopologyId::FromGeometryMap, DOC(Bentley, Geom, CurveTopologyId, FromGeometryMap));            
    c1.def_static("FromWire", &CurveTopologyId::FromWire, DOC(Bentley, Geom, CurveTopologyId, FromWire));            
    c1.def_static("FromUnknownCurve", &CurveTopologyId::FromUnknownCurve, "curveIndex"_a, DOC(Bentley, Geom, CurveTopologyId, FromUnknownCurve));            
    c1.def_static("FromVisEdgesBoundedPlane", &CurveTopologyId::FromVisEdgesBoundedPlane, DOC(Bentley, Geom, CurveTopologyId, FromVisEdgesBoundedPlane));            
    c1.def_static("FromParasolidGPArrayId", &CurveTopologyId::FromParasolidGPArrayId, DOC(Bentley, Geom, CurveTopologyId, FromParasolidGPArrayId));
    c1.def_static("FromVisEdgesAnalytic", &CurveTopologyId::FromVisEdgesAnalytic, "curveIndex"_a);            
    c1.def_static("FromVisEdgesIntersection", &CurveTopologyId::FromVisEdgesIntersection, DOC(Bentley, Geom, CurveTopologyId, FromVisEdgesIntersection));            
    c1.def_static("FromCurveVector", &CurveTopologyId::FromCurveVector, DOC(Bentley, Geom, CurveTopologyId, FromCurveVector));

    c1.def("GetBRepIsoline", [] (CurveTopologyIdCR self, FaceId* faceId)
           {
           size_t index = 0;
           auto retVal = self.GetBRepIsoline(faceId, &index);
           return py::make_tuple(retVal, index);
           }, "faceId"_a, DOC(Bentley, Geom, CurveTopologyId, GetBRepIsoline));

    c1.def("GetBRepSharedEdge", &CurveTopologyId::GetBRepSharedEdge, "faceId0"_a, "faceId1"_a, DOC(Bentley, Geom, CurveTopologyId, GetBRepSharedEdge));            
    c1.def("GetBRepSheetEdge", &CurveTopologyId::GetBRepSheetEdge, "edgeId"_a, DOC(Bentley, Geom, CurveTopologyId, GetBRepSheetEdge));
    c1.def("GetBRepPlanarFace", &CurveTopologyId::GetBRepPlanarFace, "faceId"_a);
    c1.def_static("AddCurveVectorIds", &CurveTopologyId::AddCurveVectorIds, "curveVector"_a, "type"_a, "id"_a, "cds"_a);

    c1.def("__repr__", [] (CurveTopologyIdR self)
           {
           return "(Type:{}, Count:{})"_s.format(self.GetType(), self.GetCount());
           });

    c1.def("__copy__", [](const CurveTopologyId& self)
        {
        return CurveTopologyId(self);
        });
    }