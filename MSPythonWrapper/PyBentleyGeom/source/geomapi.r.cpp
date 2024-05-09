/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyBentleyGeom\source\geomapi.r.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_GeomApi_r(py::module_& m)
    {
    //===================================================================================
    // struct FaceId
    py::class_<FaceId> c1(m, "FaceId");
    py::bind_vector< bvector<FaceId> >(m, "FaceIdArray", py::module_local(false));

    c1.def(py::init<>());
    c1.def_readwrite("nodeId", &FaceId::nodeId);
    c1.def_readwrite("entityId", &FaceId::entityId);
    c1.def(py::self < py::self);
    c1.def(py::self == py::self);
    c1.def("__repr__", [] (FaceId& self) { return "(nodeId:{}, entityId:{})"_s.format(self.nodeId, self.entityId); });
    c1.def("__copy__", [] (const FaceId& self) {return FaceId(self); });
    
    //===================================================================================
    // struct EdgeId
    py::class_<EdgeId> c2(m, "EdgeId");
    py::bind_vector< bvector<EdgeId> >(m, "EdgeIdArray", py::module_local(false));

    c2.def(py::init<>());
    c2.def("GetFaces", [] (EdgeId const& self) { return py::make_tuple(self.faces[0], self.faces[1]); });
    c2.def("SetFaces", [] (EdgeId& self, FaceId& f1, FaceId& f2) { self.faces[0] = f1; self.faces[1] = f2; }, "f1"_a, "f2"_a);
    c2.def("__repr__", [] (EdgeId& self) { return "(face1:{}, face2:{})"_s.format(self.faces[0], self.faces[1]); });
    c2.def("__copy__", [] (const EdgeId& self) { return EdgeId(self); });

    //===================================================================================
    // struct VertexId
    py::class_<VertexId> c3(m, "VertexId");
    py::bind_vector< bvector<VertexId> >(m, "VertexIdArray", py::module_local(false));

    c3.def(py::init<>());
    c3.def("GetFaces", [] (VertexId const& self) { return py::make_tuple(self.faces[0], self.faces[1], self.faces[2]); });
    c3.def("SetFaces", [] (VertexId& self, FaceId const& f1, FaceId const& f2, FaceId const& f3) { self.faces[0] = f1; self.faces[1] = f2; self.faces[2] = f3; }, "f1"_a, "f2"_a, "f3"_a);
    c3.def("__repr__", [] (VertexId& self) { return "(face1:{}, face2:{}, face3:{}"_s.format(self.faces[0], self.faces[1], self.faces[2]); });
    c3.def("__copy__", [] (const VertexId& self) { return VertexId(self); });
    
    //===================================================================================
    // struct FloatRgb
    py::class_<FloatRgb> c4(m, "FloatRgb");
    py::bind_vector< FloatRgbArray >(m, "FloatRgbArray", py::module_local(false));
    bind_BlockedVector<FloatRgb>(m, "BlockedVectorFloatRgb", py::module_local(false));
    
    c4.def(py::init<>());
    c4.def_readwrite("red", &FloatRgb::red);
    c4.def_readwrite("green", &FloatRgb::green);
    c4.def_readwrite("blue", &FloatRgb::blue);
    c4.def("__repr__", [] (FloatRgb& self) { return "(red:{}, green:{}, blue:{})"_s.format(self.red, self.green, self.blue); });
    c4.def("__copy__", [] (const FloatRgb& self) { return FloatRgb(self); });

    //===================================================================================
    // struct RgbFactor
    py::class_<RgbFactor> c5(m, "RgbFactor");
    py::bind_vector< RgbFactorArray >(m, "RgbFactorArray", py::module_local(false));
    bind_BlockedVector<RgbFactor>(m, "BlockedVectorRgbFactor", py::module_local(false));

    c5.def(py::init<>());
    c5.def_readwrite("red", &RgbFactor::red);
    c5.def_readwrite("green", &RgbFactor::green);
    c5.def_readwrite("blue", &RgbFactor::blue);
    c5.def_static("FromIntColor", &RgbFactor::FromIntColor, "intColor"_a);
    c5.def_static("From", py::overload_cast<DPoint3dCR>(&RgbFactor::From), "data"_a);
    c5.def_static("From", py::overload_cast<double, double, double>(&RgbFactor::From), "r"_a, "g"_a, "b"_a);
    c5.def("AddInPlace", &RgbFactor::AddInPlace, "other"_a);
    c5.def("ScaleInPlace", &RgbFactor::ScaleInPlace, "a"_a);    
    c5.def("__repr__", [] (RgbFactor& self) { return "(red:{}, green:{}, blue:{})"_s.format(self.red, self.green, self.blue); });
    c5.def("__copy__", [] (const RgbFactor& self) { return RgbFactor(self); });
    }

