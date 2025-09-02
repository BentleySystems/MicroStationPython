/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnPlatform\source\linearhandlers.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <DgnPlatform/LinearHandlers.h>



static const char * __doc_Bentley_DgnPlatform_ShapeHandler_CreateShapeElement =R"doc(Create a new SHAPE_ELM with the supplied parameters.

:param eeh:
    The new element.

:param templateEh:
    Template element to use for symbology; if NULL defaults are used.

:param points:
    input point buffer.

:param numVerts:
    number of points.

:param is3d:
    Initialize the 2d or 3d element structure, typically
    modelRef->Is3d ().

:param modelRef:
    Model to associate this element with. Required to compute range.

:returns:
    SUCCESS if a valid element is created and range was sucessfully
    calculated. Bentley Systems +---------------+---------------+-----
    ----------+---------------+---------------+------)doc";

static const char * __doc_Bentley_DgnPlatform_LineStringHandler_CreateLineStringElement =R"doc(Create a new LINE_STRING_ELM with the supplied parameters.

:param eeh:
    The new element.

:param templateEh:
    Template element to use for symbology; if NULL defaults are used.

:param points:
    input point buffer.

:param numVerts:
    number of points.

:param is3d:
    Initialize the 2d or 3d element structure, typically
    modelRef->Is3d ().

:param modelRef:
    Model to associate this element with. Required to compute range.

:returns:
    SUCCESS if a valid element is created and range was sucessfully
    calculated. Bentley Systems +---------------+---------------+-----
    ----------+---------------+---------------+------)doc";

static const char * __doc_Bentley_DgnPlatform_LineHandler_CreateLineElement =R"doc(Create a new LINE_ELM with the supplied parameters.

:param eeh:
    The new element.

:param templateEh:
    Template element to use for symbology; if NULL defaults are used.

:param segment:
    start and end points of line.

:param is3d:
    Initialize the 2d or 3d element structure, typically
    modelRef->Is3d ().

:param modelRef:
    Model to associate this element with. Required to compute range.

:returns:
    SUCCESS if a valid element is created and range was sucessfully
    calculated. Bentley Systems +---------------+---------------+-----
    ----------+---------------+---------------+------)doc";

static const char * __doc_Bentley_DgnPlatform_PointStringHandler_CreatePointStringElement =R"doc(Create a new POINT_STRING_ELM with the supplied parameters.

:param eeh:
    The new element.

:param templateEh:
    Template element to use for symbology; if NULL defaults are used.

:param points:
    input point buffer.

:param matrices:
    optional array of per-point rotations (usually NULL).

:param numVerts:
    number of points (and matrices if not NULL)

:param disjoint:
    Whether point displays as disjoint or a continous linestring.

:param is3d:
    Initialize the 2d or 3d element structure, typically
    modelRef->Is3d ().

:param modelRef:
    Model to associate this element with. Required to compute range.

:returns:
    SUCCESS if a valid element is created and range was sucessfully
    calculated. Bentley Systems +---------------+---------------+-----
    ----------+---------------+---------------+------)doc";

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_LinearHandlers(py::module_& m)
    {
    //===================================================================================
    // struct PointStringHandler
    py::class_< PointStringHandler, std::unique_ptr< PointStringHandler, py::nodelete>, DisplayHandler, ICurvePathEdit> c1(m, "PointStringHandler");

    c1.def_static("CreatePointStringElement", [] (EditElementHandleR eeh, ElementHandleCP templateEh, DPoint3dArray const& points, bvector<RotMatrix> const& matrices, bool disjoint, bool is3d, DgnModelRefR modelRef)
                  {
                  return PointStringHandler::CreatePointStringElement(eeh, templateEh, points.data(), matrices.data(), points.size(), disjoint, is3d, modelRef);
                  }, "eeh"_a, "templateEh"_a, "points"_a, "matrices"_a, "disjoint"_a, "is3d"_a, "modelRef"_a, DOC(Bentley, DgnPlatform, PointStringHandler, CreatePointStringElement));

    c1.def_static("CreatePointStringElement", [] (EditElementHandleR eeh, ElementHandleCP templateEh, py::list const& points, bvector<RotMatrix> const& matrices, bool disjoint, bool is3d, DgnModelRefR modelRef)
                  {
                  CONVERT_PYLIST_TO_NEW_CPPARRAY(points, cppPoints, DPoint3dArray, DPoint3d);
                  return PointStringHandler::CreatePointStringElement(eeh, templateEh, cppPoints.data(), matrices.data(), cppPoints.size(), disjoint, is3d, modelRef);
                  }, "eeh"_a, "templateEh"_a, "points"_a, "matrices"_a, "disjoint"_a, "is3d"_a, "modelRef"_a, DOC(Bentley, DgnPlatform, PointStringHandler, CreatePointStringElement));


    c1.def_property_readonly_static("Instance", [] (py::object const&) { return std::unique_ptr< PointStringHandler, py::nodelete>(&PointStringHandler::GetInstance()); });
    c1.def_static("GetInstance", &PointStringHandler::GetInstance, py::return_value_policy::reference);

    //===================================================================================
    // struct LineHandler
    py::class_< LineHandler, std::unique_ptr< LineHandler, py::nodelete>, DisplayHandler, ICurvePathEdit> c2(m, "LineHandler");

    c2.def_static("CreateLineElement", &LineHandler::CreateLineElement, "eeh"_a, "templateEh"_a, "segment"_a, "is3d"_a, "modelRef"_a, DOC(Bentley, DgnPlatform, LineHandler, CreateLineElement));
    c2.def_property_readonly_static("Instance", [] (py::object const&) { return std::unique_ptr< LineHandler, py::nodelete>(&LineHandler::GetInstance()); });
    c2.def_static("GetInstance", &LineHandler::GetInstance, py::return_value_policy::reference_internal);

    //===================================================================================
    // struct LineStringBaseHandler
    py::class_< LineStringBaseHandler, std::unique_ptr< LineStringBaseHandler, py::nodelete>, DisplayHandler, ICurvePathEdit> c3(m, "LineStringBaseHandler");
    c3.def_property_readonly_static("Instance", [] (py::object const&) { return std::unique_ptr< LineStringBaseHandler, py::nodelete>(&LineStringBaseHandler::GetInstance()); });
    c3.def_static("GetInstance", &LineStringBaseHandler::GetInstance, py::return_value_policy::reference_internal);

    //===================================================================================
    // struct LineStringHandler
    py::class_< LineStringHandler, std::unique_ptr< LineStringHandler, py::nodelete>, LineStringBaseHandler> c4(m, "LineStringHandler");

    c4.def_static("CreateLineStringElement", [] (EditElementHandleR eeh, ElementHandleCP templateEh, DPoint3dArray const& points, bool is3d, DgnModelRefR modelRef)
                  {
                  return LineStringHandler::CreateLineStringElement(eeh, templateEh, points.data(), points.size(), is3d, modelRef);
                  }, "eeh"_a, "templateEh"_a, "points"_a, "is3d"_a, "modelRef"_a, DOC(Bentley, DgnPlatform, LineStringHandler, CreateLineStringElement));


    c4.def_static("CreateLineStringElement", [] (EditElementHandleR eeh, ElementHandleCP templateEh, py::list const& points, bool is3d, DgnModelRefR modelRef)
                {
                CONVERT_PYLIST_TO_NEW_CPPARRAY(points, dpoints, DPoint3dArray, DPoint3d);
                return LineStringHandler::CreateLineStringElement(eeh, templateEh, dpoints.data(), dpoints.size(), is3d, modelRef);
                }, "eeh"_a, "templateEh"_a, "points"_a, "is3d"_a, "modelRef"_a, DOC(Bentley, DgnPlatform, LineStringHandler, CreateLineStringElement));


    c4.def_property_readonly_static("Instance", [] (py::object const&) { return std::unique_ptr< LineStringHandler, py::nodelete>(&LineStringHandler::GetInstance()); });
    c4.def_static("GetInstance", &LineStringHandler::GetInstance, py::return_value_policy::reference_internal);

    //===================================================================================
    // struct ShapeHandler
    py::class_< ShapeHandler, std::unique_ptr< ShapeHandler, py::nodelete>, LineStringBaseHandler, IAreaFillPropertiesEdit> c5(m, "ShapeHandler");

    c5.def_static("CreateShapeElement", [] (EditElementHandleR eeh, ElementHandleCP templateEh, DPoint3dArray const& points, bool is3d, DgnModelRefR modelRef)
                  {
                  return ShapeHandler::CreateShapeElement(eeh, templateEh, points.data(), points.size(), is3d, modelRef);
                  }, "eeh"_a, "templateEh"_a, "points"_a, "is3d"_a, "modelRef"_a, DOC(Bentley, DgnPlatform, ShapeHandler, CreateShapeElement));

    c5.def_static("CreateShapeElement", [] (EditElementHandleR eeh, ElementHandleCP templateEh, py::list const& points, bool is3d, DgnModelRefR modelRef)
                  {
                  CONVERT_PYLIST_TO_NEW_CPPARRAY(points, cppPoints, DPoint3dArray, DPoint3d);
                  return ShapeHandler::CreateShapeElement(eeh, templateEh, cppPoints.data(), cppPoints.size(), is3d, modelRef);
                  }, "eeh"_a, "templateEh"_a, "points"_a, "is3d"_a, "modelRef"_a, DOC(Bentley, DgnPlatform, ShapeHandler, CreateShapeElement));
    
    c5.def_property_readonly_static("Instance", [] (py::object const&) { return std::unique_ptr< ShapeHandler, py::nodelete>(&ShapeHandler::GetInstance()); });
    c5.def_static("GetInstance", &ShapeHandler::GetInstance, py::return_value_policy::reference_internal);
    }