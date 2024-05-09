/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyBentleyGeom\source\PyBentleyGeom.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <Geom/DTriangle3d.h>

/*---------------------------------------------------------------------------------**//**
* STL-liked container instantiation.
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void bind_container_PyGeom(py::module_& m)
    {
    // ValueSizeSize instantiation
    bind_ValueSizeSize<double>(m, "DoubleSizeSizeT", py::module_local(false));
    bind_OrderedValueSizeSize<double>(m, "DoubleSizeSize", py::module_local(false));

    // ValidatedValue instantiation
    bind_ValidatedValue<double>(m, "ValidatedDouble", py::module_local(false));
    bind_ValidatedValue<size_t>(m, "ValidatedSize", py::module_local(false));

    // BlockVector instantiation
    bind_BlockedVector<int>(m, "BlockedVectorIntT", py::module_local(false));
    bind_BlockedVector<uint32_t>(m, "BlockedVectorUInt32", py::module_local(false));    
    }

/*---------------------------------------------------------------------------------**//**
* Forward declarations for class definition generators.
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_Angle(py::module_&);
void def_BSIQuadrature(py::module_&);
void def_BsplineStructs(py::module_&);
void def_ClipPlane(py::module_&);
void def_ClipPlaneSet(py::module_&);
void def_CompoundDrawState(py::module_&);
void def_CurveDetails(py::module_&);
void def_CurvePrimitive(py::module_&);
void def_CurvePrimitiveId(py::module_&);
void def_CurveTopologyId(py::module_&);
void def_CurveVector(py::module_&);
void def_DBilinearPatch3d(py::module_&);
void def_DEllipse3d(py::module_&);
void def_DMap4d(py::module_&);
void def_DMatrix4d(py::module_&);
void def_DPlane3d(py::module_&);
void def_DPoint2d(py::module_&);
void def_DPoint3d(py::module_&);
void def_DPoint4d(py::module_&);
void def_DRange1d(py::module_&);
void def_DRange2d(py::module_&);
void def_DRange3d(py::module_&);
void def_DRay3d(py::module_&);
void def_DSegment1d(py::module_&);
void def_DSegment3d(py::module_&);
void def_DSpiral2dBase(py::module_&);
void def_DTriangle3d(py::module_&);
void def_DVec2d(py::module_&);
void def_DVec3d(py::module_&);
void def_FacetOptions(py::module_&);
void def_GeomApi(py::module_&);
void def_MSBsplineCurve(py::module_&);
void def_MSBsplineSurface(py::module_&);
void def_MSInterpolationCurve(py::module_&);
void def_Transform(py::module_&);
void def_SolidPrimitive(py::module_&);
void def_RotMatrix(py::module_&);
void def_GeomApi_r(py::module_&);
void def_Polyface(py::module_&);
void def_Point(py::module_&);
void def_GeoPoint(py::module_&);

/*---------------------------------------------------------------------------------**//**
* Module definition.
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
PYBIND11_MODULE(MSPyBentleyGeom, m)
    {
    // Document for module
    m.doc() = "Pybind11 wrapper for BentleyGeom.dll";

    // class defines
    bind_container_PyGeom(m);

    def_Angle(m);
    def_BSIQuadrature(m);
    def_BsplineStructs(m);
    def_ClipPlane(m);
    def_ClipPlaneSet(m);
    def_CompoundDrawState(m);
    def_CurveDetails(m);
    def_CurvePrimitive(m);
    def_CurvePrimitiveId(m);
    def_CurveTopologyId(m);
    def_CurveVector(m);
    def_DBilinearPatch3d(m);
    def_DEllipse3d(m);
    def_DMap4d(m);
    def_DMatrix4d(m);
    def_DPlane3d(m);
    def_DPoint2d(m);
    def_DPoint3d(m);
    def_DPoint4d(m);
    def_DRange1d(m);
    def_DRange2d(m);
    def_DRange3d(m);
    def_DRay3d(m);
    def_DSegment1d(m);
    def_DSegment3d(m);
    def_DSpiral2dBase(m);
    def_DTriangle3d(m);
    def_DVec2d(m);
    def_DVec3d(m);
    def_FacetOptions(m);
    def_GeomApi(m);
    def_MSBsplineCurve(m);
    def_MSBsplineSurface(m);
    def_MSInterpolationCurve(m);
    def_Transform(m);
    def_RotMatrix(m);
    def_SolidPrimitive(m);
    def_GeomApi_r(m);
    def_Polyface(m);
    def_Point(m);
    def_GeoPoint(m);
    }


