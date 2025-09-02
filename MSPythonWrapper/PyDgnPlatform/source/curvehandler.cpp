/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnPlatform\source\curvehandler.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <DgnPlatform/CurveHandler.h>



static const char * __doc_Bentley_DgnPlatform_CurveHandler_CreateCurveElement =R"doc(Create a new CURVE_ELM with the supplied parameters.

:param eeh:
    The new element.

:param templateEh:
    Template element to use for symbology; if NULL defaults are used.

:param points:
    curve points. Must be 6 &lt;=numVerts &lt;=MAX_VERTICES. The first
    2 points and last 2 points control the end tangents.

:param numVerts:
    number of curve points.

:param is3d:
    Initialize the 2d or 3d element structure, typically
    modelRef->Is3d ().

:param modelRef:
    Model to associate this element with. Required to compute range.

:returns:
    SUCCESS if a valid element is created and range was sucessfully
    calculated. )doc";

static const char * __doc_Bentley_DgnPlatform_CurveHandler_GetEndTangentPoints =R"doc(Initialize the default end tangent points from the array of curve
points.

:param tangentPts:
    tangent points, supply as index n-1 and n-2 to CreateCurveElement.

:param points:
    curve points.

:param numPoints:
    number of curve points (does not include 4 points for start and
    end tangents).

:returns:
    SUCCESS if tangent points could be calculated from input points.
   )doc";

static const char * __doc_Bentley_DgnPlatform_CurveHandler_GetStartTangentPoints =R"doc(Initialize the default start tangent points from the array of curve
points.

:param tangentPts:
    tangent points, supply as index 0 and 1 to CreateCurveElement.

:param points:
    curve points.

:param numPoints:
    number of curve points (does not include 4 points for start and
    end tangents).

:returns:
    SUCCESS if tangent points could be calculated from input points.
    )doc";

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_CurveHandler(py::module_& m)
    {
    //===================================================================================
    // struct CurveHandler
    py::class_<CurveHandler, DisplayHandler, ICurvePathEdit> c1(m, "CurveHandler");

    c1.def_static("GetStartTangentPoints", [] (DPoint3dArray& tangentPts, DPoint3dArray& points)
                  {
                  if (tangentPts.size() < 2)
                      tangentPts.resize(2);
                  return CurveHandler::GetStartTangentPoints(tangentPts.data(), points.data(), points.size());
                  }, "tangentPts"_a, "points"_a, DOC(Bentley, DgnPlatform, CurveHandler, GetStartTangentPoints));

    c1.def_static("GetStartTangentPoints", [] (py::list& tangentPts, py::list& points)
                  {
                  CONVERT_PYLIST_TO_NEW_CPPARRAY(tangentPts, cppTangentPts, DPoint3dArray, DPoint3d);
                  CONVERT_PYLIST_TO_NEW_CPPARRAY(points, cppPoints, DPoint3dArray, DPoint3d);
                  if (cppTangentPts.size() < 2)
                      cppTangentPts.resize(2);
                  BentleyStatus status = CurveHandler::GetStartTangentPoints(cppTangentPts.data(), cppPoints.data(), cppPoints.size());
                  CONVERT_CPPARRAY_TO_PYLIST(tangentPts, cppTangentPts, DPoint3dArray, DPoint3d);
                  return status;  
                  }, "tangentPts"_a, "points"_a, DOC(Bentley, DgnPlatform, CurveHandler, GetStartTangentPoints));

    c1.def_static("GetEndTangentPoints", [] (DPoint3dArray& tangentPts, DPoint3dArray& points)
                  {
                  if (tangentPts.size() < 2)
                      tangentPts.resize(2);
                  return CurveHandler::GetEndTangentPoints(tangentPts.data(), points.data(), points.size());
                  }, "tangentPts"_a, "points"_a, DOC(Bentley, DgnPlatform, CurveHandler, GetEndTangentPoints));

    c1.def_static("GetEndTangentPoints", [] (py::list& tangentPts, py::list& points)
                  {
                  CONVERT_PYLIST_TO_NEW_CPPARRAY(tangentPts, cppTangentPts, DPoint3dArray, DPoint3d);
                  CONVERT_PYLIST_TO_NEW_CPPARRAY(points, cppPoints, DPoint3dArray, DPoint3d);
                  if (cppTangentPts.size() < 2)
                      cppTangentPts.resize(2);
                  BentleyStatus status =  CurveHandler::GetEndTangentPoints(cppTangentPts.data(), cppPoints.data(), cppPoints.size());
                  CONVERT_CPPARRAY_TO_PYLIST(tangentPts, cppTangentPts, DPoint3dArray, DPoint3d);
                  return status;
                  }, "tangentPts"_a, "points"_a, DOC(Bentley, DgnPlatform, CurveHandler, GetEndTangentPoints));
    
    c1.def_static("CreateCurveElement", [] (EditElementHandleR eeh, ElementHandleCP templateEh, DPoint3dArray const& points, bool is3d, DgnModelRefR modelRef)
                  {
                  return CurveHandler::CreateCurveElement(eeh, templateEh, points.data(), points.size(), is3d, modelRef);
                  }, "eeh"_a, "templateEh"_a, "points"_a, "is3d"_a, "modelRef"_a, DOC(Bentley, DgnPlatform, CurveHandler, CreateCurveElement));

    c1.def_static("CreateCurveElement", [] (EditElementHandleR eeh, ElementHandleCP templateEh, py::list const& points, bool is3d, DgnModelRefR modelRef)
                  {
                  CONVERT_PYLIST_TO_NEW_CPPARRAY(points, cppPoints, DPoint3dArray, DPoint3d);
                  return CurveHandler::CreateCurveElement(eeh, templateEh, cppPoints.data(), cppPoints.size(), is3d, modelRef);
                  }, "eeh"_a, "templateEh"_a, "points"_a, "is3d"_a, "modelRef"_a, DOC(Bentley, DgnPlatform, CurveHandler, CreateCurveElement));

    c1.def_property_readonly_static("Instance", [] (py::object const&) { return std::unique_ptr<CurveHandler, py::nodelete>(&CurveHandler::GetInstance()); });
    c1.def_static("GetInstance", &CurveHandler::GetInstance, py::return_value_policy::reference);
    }