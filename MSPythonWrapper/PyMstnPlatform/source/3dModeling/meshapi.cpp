/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyMstnPlatform\source\3dModeling\meshapi.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <3dModeling/3dModelingApi.h>


struct Mesh {};

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_MeshAPI(py::module_& m)
    {
    py::class_<Mesh> c1(m, "Mesh");

    c1.def_static("ExtrudeVolumeAlongGlobalZ", &mdlMesh_extrudeVolumeAlongGlobalZ, "results"_a, "agenda"_a, "length"_a);
    c1.def_static("ExtrudeVolume", &mdlMesh_extrudeVolume, "results"_a, "agenda"_a, "extrusionVec"_a);
    c1.def_static("ExtrudeToTarget", &mdlMesh_extrudeToTarget, "results"_a, "roofAgenda"_a, "targetAgenda"_a);

    c1.def_static("SubdivideSmoothly", [] (PolyfaceHeaderP mesh, int subdivisionLevel, DgnModelRefR model)
          {
          PolyfaceHeaderPtr result, inMesh(mesh);
          auto retVal = mdlMesh_subdivideSmoothly(result, inMesh, subdivisionLevel, model);
          return py::make_tuple(retVal, result);
          }, "mesh"_a, "subdivisionLevel"_a, "model"_a);

    c1.def_static("SubdivideKeepSharp", [] (PolyfaceHeaderP mesh, int subdivisionLevel, DgnModelRefR model)
          {
          PolyfaceHeaderPtr result, inMesh(mesh);
          auto retVal = mdlMesh_subdivideKeepSharp(result, inMesh, subdivisionLevel, model);
          return py::make_tuple(retVal, result);
          }, "mesh"_a, "subdivisionLevel"_a, "model"_a);

    c1.def_static("Healholes", [] (PolyfaceHeaderP mesh)
          {
          PolyfaceHeaderPtr result, inMesh(mesh);
          auto retVal = mdlMesh_healholes(result, inMesh);
          return py::make_tuple(retVal, result);
          }, "mesh"_a);

    c1.def_static("BooleanUnion", [] (PolyfaceHeaderP mesh1, PolyfaceHeaderP mesh2, DgnModelRefR model)
          {
          PolyfaceHeaderPtr result, inMesh1(mesh1), inMesh2(mesh2);
          auto retVal = mdlMesh_booleanUnion(result, inMesh1, inMesh2, model);
          return py::make_tuple(retVal, result);
          }, "mesh1"_a, "mesh2"_a, "model"_a);

    c1.def_static("BooleanIntersection", [] (PolyfaceHeaderP mesh1, PolyfaceHeaderP mesh2, DgnModelRefR model)
          {
          PolyfaceHeaderPtr result, inMesh1(mesh1), inMesh2(mesh2);
          auto retVal = mdlMesh_booleanIntersection(result, inMesh1, inMesh2, model);
          return py::make_tuple(retVal, result);
          }, "mesh1"_a, "mesh2"_a, "model"_a);

    c1.def_static("BooleanDifference", [] (PolyfaceHeaderP mesh1, PolyfaceHeaderP mesh2, DgnModelRefR model)
          {
          PolyfaceHeaderPtr result, inMesh1(mesh1), inMesh2(mesh2);
          auto retVal = mdlMesh_booleanDifference(result, inMesh1, inMesh2, model);
          return py::make_tuple(retVal, result);
          }, "mesh1"_a, "mesh2"_a, "model"_a);



    }