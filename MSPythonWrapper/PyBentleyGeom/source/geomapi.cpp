/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyBentleyGeom\source\geomapi.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"



static const char * __doc_Bentley_Geom_MeshAnnotationVector_GetTotalFail =R"doc(Query the total number of tests failed.)doc";

static const char * __doc_Bentley_Geom_MeshAnnotationVector_GetTotalPass =R"doc(Query the total number of tests passed.)doc";

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_GeomApi(py::module_& m)
    {
    //===================================================================================
    // struct IGeometry
    py::class_<IGeometry, IGeometryPtr> c1(m, "IGeometry");
    if (true)
        {
        py::enum_<IGeometry::GeometryType>(c1, "GeometryType")
            .value("eCurvePrimitive", IGeometry::GeometryType::CurvePrimitive)
            .value("eCurveVector", IGeometry::GeometryType::CurveVector)
            .value("eSolidPrimitive", IGeometry::GeometryType::SolidPrimitive)
            .value("eBsplineSurface", IGeometry::GeometryType::BsplineSurface)
            .value("ePolyface", IGeometry::GeometryType::Polyface)
            .export_values();
        }

    c1.def(py::init(py::overload_cast<ICurvePrimitivePtr const&>(IGeometry::Create)), "source"_a);
    c1.def(py::init(py::overload_cast<CurveVectorPtr const&>(IGeometry::Create)), "source"_a);
    c1.def(py::init(py::overload_cast<ISolidPrimitivePtr const&>(IGeometry::Create)), "source"_a);
    c1.def(py::init(py::overload_cast<MSBsplineSurfacePtr const&>(IGeometry::Create)), "source"_a);
    c1.def(py::init(py::overload_cast<PolyfaceHeaderPtr const&>(IGeometry::Create)), "source"_a);

    c1.def_property_readonly("GeometryType", &IGeometry::GetGeometryType);
    c1.def("GetGeometryType", &IGeometry::GetGeometryType);

    c1.def("GetAsICurvePrimitive", &IGeometry::GetAsICurvePrimitive);
    c1.def("GetAsCurveVector", &IGeometry::GetAsCurveVector);
    c1.def("GetAsISolidPrimitive", &IGeometry::GetAsISolidPrimitive);
    c1.def("GetAsMSBsplineSurface", &IGeometry::GetAsMSBsplineSurface);
    c1.def("GetAsPolyfaceHeader", &IGeometry::GetAsPolyfaceHeader);
    c1.def("Clone", py::overload_cast<>(&IGeometry::Clone, py::const_));
    c1.def("Clone", py::overload_cast<TransformCR>(&IGeometry::Clone, py::const_), "transform"_a);

    c1.def("TryGetRange", py::overload_cast<DRange3dR>(&IGeometry::TryGetRange, py::const_), "range"_a);
    c1.def("TryGetRange", py::overload_cast<DRange3dR, TransformCR>(&IGeometry::TryGetRange, py::const_), "range"_a, "transform"_a);

    c1.def("TryTransformInPlace", &IGeometry::TryTransformInPlace, "transform"_a);
    c1.def("IsSameStructureAndGeometry", &IGeometry::IsSameStructureAndGeometry, "other"_a, "tolerance"_a = 0.0);

    c1.def("__repr__", [] (IGeometry& self) { return "(geometryType:{})"_s.format(self.GetGeometryType()); });

    //===================================================================================
    // struct MeshAnnotation
    py::class_<MeshAnnotation> c2(m, "MeshAnnotation");
    py::bind_vector<MeshAnnotationArray>(m, "MeshAnnotationArray", py::module_local(false));
    
    c2.def(py::init<Utf8CP>(), "name");

    c2.def_readwrite("Pass", &MeshAnnotation::m_pass);
    c2.def_readwrite("Fail", &MeshAnnotation::m_fail);
    c2.def("Description", [] (MeshAnnotation const& m) { return std::string(m.m_description.c_str()); });
    c2.def("IncrementPass", &MeshAnnotation::IncrementPass);
    c2.def("IncrementFail", &MeshAnnotation::IncrementFail);
    c2.def("Record", py::overload_cast<size_t, size_t>(&MeshAnnotation::Record), "index"_a, "tag"_a);
    c2.def("Record", py::overload_cast<size_t, DPoint3dCR>(&MeshAnnotation::Record), "index"_a, "tag"_a);
    c2.def("Record", py::overload_cast<size_t, int>(&MeshAnnotation::Record), "index"_a, "tag"_a);

    //===================================================================================
    // struct MeshAnnotationVector
    py::class_< MeshAnnotationVector, MeshAnnotationArray> c3(m, "MeshAnnotationVector");
    c3.def(py::init<bool>(), "recordAllTestDescriptions"_a);

    c3.def_property_readonly("TotalPass", &MeshAnnotationVector::GetTotalPass);
    c3.def("GetTotalPass", &MeshAnnotationVector::GetTotalPass, DOC(Bentley, Geom, MeshAnnotationVector, GetTotalPass));

    c3.def_property_readonly("TotalFail", &MeshAnnotationVector::GetTotalFail);
    c3.def("GetTotalFail", &MeshAnnotationVector::GetTotalFail, DOC(Bentley, Geom, MeshAnnotationVector, GetTotalFail));

    //===================================================================================
    // Enum CurveParameterMapping
    py::enum_< CurveParameterMapping>(m, "CurveParameterMapping", py::arithmetic())
        .value("eCURVE_PARAMETER_MAPPING_BezierFraction", CURVE_PARAMETER_MAPPING_BezierFraction)
        .value("eCURVE_PARAMETER_MAPPING_CurveKnot", CURVE_PARAMETER_MAPPING_CurveKnot)
        .value("eCURVE_PARAMETER_MAPPING_CurveFraction", CURVE_PARAMETER_MAPPING_CurveFraction)
        .export_values();

    //===================================================================================
    // Enum LocalCoordinateSelect
    py::enum_< LocalCoordinateSelect>(m, "LocalCoordinateSelect", py::arithmetic())
        .value("eLOCAL_COORDINATE_SCALE_UnitAxesAtStart", LOCAL_COORDINATE_SCALE_UnitAxesAtStart)
        .value("eLOCAL_COORDINATE_SCALE_UnitAxesAtLowerLeft", LOCAL_COORDINATE_SCALE_UnitAxesAtLowerLeft)
        .value("eLOCAL_COORDINATE_SCALE_01RangeBothAxes", LOCAL_COORDINATE_SCALE_01RangeBothAxes)
        .value("eLOCAL_COORDINATE_SCALE_01RangeLargerAxis", LOCAL_COORDINATE_SCALE_01RangeLargerAxis)
        .export_values();
    }