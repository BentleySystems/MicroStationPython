/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnPlatform\source\dropgraphics.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <DgnPlatform/DropGraphics.h>



static const char * __doc_Bentley_DgnPlatform_DraftingElementSchema_ToDroppedElements =R"doc(Create a group of " simple " elements that represent the graphics of the
supplied element.)doc";

static const char * __doc_Bentley_DgnPlatform_DraftingElementSchema_ToElements =R"doc(Populate an ElementAgenda from an CurveVector that represents a
collection of un-related elements (BOUNDARY_TYPE_None).)doc";

static const char * __doc_Bentley_DgnPlatform_DraftingElementSchema_ToElement =R"doc(Create a single element from a CurveVector that represents a point
string, open curve, closed curve, or region.)doc";

static const char * __doc_Bentley_DgnPlatform_DropGraphics_SetPatternBoundary =R"doc(Set pattern boundary drop behavior.)doc";

static const char * __doc_Bentley_DgnPlatform_DropGraphics_GetPatternBoundary =R"doc(Get pattenr boundary drop behavior.)doc";

static const char * __doc_Bentley_DgnPlatform_DropGraphics_SetPatternIndex =R"doc(Set a specific pattern index to drop (multilines only, -1 for all).)doc";

static const char * __doc_Bentley_DgnPlatform_DropGraphics_GetPatternIndex =R"doc(Get current pattern drop index (-1 means all).)doc";

static const char * __doc_Bentley_DgnPlatform_DropGraphics_SetOptions =R"doc(Set graphics specific drop options.)doc";

static const char * __doc_Bentley_DgnPlatform_DropGraphics_GetOptions =R"doc(Get graphics specific drop options.)doc";

static const char * __doc_Bentley_DgnPlatform_DropGeometry_SetSolidsOptions =R"doc(Set solid/surface drop behavior.)doc";

static const char * __doc_Bentley_DgnPlatform_DropGeometry_GetSolidsOptions =R"doc(Get solid/surface drop behavior.)doc";

static const char * __doc_Bentley_DgnPlatform_DropGeometry_SetSharedCellOptions =R"doc(Set shared cell instance drop behavior.)doc";

static const char * __doc_Bentley_DgnPlatform_DropGeometry_GetSharedCellOptions =R"doc(Get shared cell instance drop behavior.)doc";

static const char * __doc_Bentley_DgnPlatform_DropGeometry_SetDimensionOptions =R"doc(Set dimension drop behavior.)doc";

static const char * __doc_Bentley_DgnPlatform_DropGeometry_GetDimensionOptions =R"doc(Get dimension drop behavior.)doc";

static const char * __doc_Bentley_DgnPlatform_DropGeometry_SetOptions =R"doc(Set type/geometry specific drop options.)doc";

static const char * __doc_Bentley_DgnPlatform_DropGeometry_GetOptions =R"doc(Get the current type/geometry specific drop options.)doc";

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_DropGraphics(py::module_& m)
    {
    //===================================================================================
    // struct DropGeometry
    py::class_< DropGeometry, DropGeometryPtr> c1(m, "DropGeometry");

    if (true)
        {
        //===================================================================================
        // enum Options
        py::enum_<DropGeometry::Options>(c1, "Options", py::arithmetic())
            .value("eOPTION_None", DropGeometry::OPTION_None)
            .value("eOPTION_Text", DropGeometry::OPTION_Text)
            .value("eOPTION_Dimensions", DropGeometry::OPTION_Dimensions)
            .value("eOPTION_Mlines", DropGeometry::OPTION_Mlines)
            .value("eOPTION_Complex", DropGeometry::OPTION_Complex)
            .value("eOPTION_LinearSegments", DropGeometry::OPTION_LinearSegments)
            .value("eOPTION_SharedCells", DropGeometry::OPTION_SharedCells)
            .value("eOPTION_Solids", DropGeometry::OPTION_Solids)
            .value("eOPTION_AppData", DropGeometry::OPTION_AppData)
            .export_values();

        //===================================================================================
        // enum Dimensions
        py::enum_<DropGeometry::Dimensions>(c1, "Dimensions", py::arithmetic())
            .value("eDIMENSION_Geometry", DropGeometry::DIMENSION_Geometry)
            .value("eDIMENSION_Segments", DropGeometry::DIMENSION_Segments)
            .export_values();

        //===================================================================================
        // enum SharedCells
        py::enum_<DropGeometry::SharedCells>(c1, "SharedCells", py::arithmetic())
            .value("eSHAREDCELL_Geometry", DropGeometry::SHAREDCELL_Geometry)
            .value("eSHAREDCELL_NormalCell", DropGeometry::SHAREDCELL_NormalCell)
            .value("eSHAREDCELL_NormalCellOneLevel", DropGeometry::SHAREDCELL_NormalCellOneLevel)
            .export_values();

        //===================================================================================
        // enum Solids
        py::enum_<DropGeometry::Solids>(c1, "Solids", py::arithmetic())
            .value("eSOLID_Surfaces", DropGeometry::SOLID_Surfaces)
            .value("eSOLID_Wireframe", DropGeometry::SOLID_Wireframe)
            .export_values();
        }

    c1.def_property("Options", &DropGeometry::GetOptions, &DropGeometry::SetOptions);
    c1.def("GetOptions", &DropGeometry::GetOptions, DOC(Bentley, DgnPlatform, DropGeometry, GetOptions));
    c1.def("SetOptions", &DropGeometry::SetOptions, "options"_a, DOC(Bentley, DgnPlatform, DropGeometry, SetOptions));
    
    c1.def_property("DimensionOptions", &DropGeometry::GetDimensionOptions, &DropGeometry::SetDimensionOptions);
    c1.def("GetDimensionOptions", &DropGeometry::GetDimensionOptions, DOC(Bentley, DgnPlatform, DropGeometry, GetDimensionOptions));
    c1.def("SetDimensionOptions", &DropGeometry::SetDimensionOptions, "options"_a, DOC(Bentley, DgnPlatform, DropGeometry, SetDimensionOptions));
    
    c1.def_property("SharedCellOptions", &DropGeometry::GetSharedCellOptions, &DropGeometry::SetSharedCellOptions);
    c1.def("GetSharedCellOptions", &DropGeometry::GetSharedCellOptions, DOC(Bentley, DgnPlatform, DropGeometry, GetSharedCellOptions));
    c1.def("SetSharedCellOptions", &DropGeometry::SetSharedCellOptions, "options"_a, DOC(Bentley, DgnPlatform, DropGeometry, SetSharedCellOptions));
    
    c1.def_property("SolidsOptions", &DropGeometry::GetSolidsOptions, &DropGeometry::SetSolidsOptions);
    c1.def("GetSolidsOptions", &DropGeometry::GetSolidsOptions, DOC(Bentley, DgnPlatform, DropGeometry, GetSolidsOptions));
    c1.def("SetSolidsOptions", &DropGeometry::SetSolidsOptions, "options"_a, DOC(Bentley, DgnPlatform, DropGeometry, SetSolidsOptions));
    
    c1.def(py::init(&DropGeometry::Create));

    //===================================================================================
    // struct DropGraphics
    py::class_< DropGraphics, DropGraphicsPtr> c2(m, "DropGraphics");

    if (true)
        {
        //===================================================================================
        // enum Options
        py::enum_< DropGraphics::Options>(c2, "Options")
            .value("eOPTION_None", DropGraphics::OPTION_None)
            .value("eOPTION_LineStyles", DropGraphics::OPTION_LineStyles)
            .value("eOPTION_Patterns", DropGraphics::OPTION_Patterns)
            .export_values();

        //===================================================================================
        // enum PatternBoundary
        py::enum_< DropGraphics::PatternBoundary>(c2, "PatternBoundary")
            .value("eBOUNDARY_Include", DropGraphics::BOUNDARY_Include)
            .value("eBOUNDARY_Ignore", DropGraphics::BOUNDARY_Ignore)
            .value("eBOUNDARY_Only", DropGraphics::BOUNDARY_Only)
            .export_values();
        }

    c2.def_property("Options", &DropGraphics::GetOptions, &DropGraphics::SetOptions);
    c2.def("GetOptions", &DropGraphics::GetOptions, DOC(Bentley, DgnPlatform, DropGraphics, GetOptions));
    c2.def("SetOptions", &DropGraphics::SetOptions, "options"_a, DOC(Bentley, DgnPlatform, DropGraphics, SetOptions));
    
    c2.def_property("PatternIndex", &DropGraphics::GetPatternIndex, &DropGraphics::SetPatternIndex);
    c2.def("GetPatternIndex", &DropGraphics::GetPatternIndex, DOC(Bentley, DgnPlatform, DropGraphics, GetPatternIndex));
    c2.def("SetPatternIndex", &DropGraphics::SetPatternIndex, "index"_a, DOC(Bentley, DgnPlatform, DropGraphics, SetPatternIndex));
    
    c2.def_property("PatternBoundary", &DropGraphics::GetPatternBoundary, &DropGraphics::SetPatternBoundary);
    c2.def("GetPatternBoundary", &DropGraphics::GetPatternBoundary, DOC(Bentley, DgnPlatform, DropGraphics, GetPatternBoundary));
    c2.def("SetPatternBoundary", &DropGraphics::SetPatternBoundary, "boundary"_a, DOC(Bentley, DgnPlatform, DropGraphics, SetPatternBoundary));
    
    c2.def(py::init(&DropGraphics::Create));

    //===================================================================================
    // struct DraftingElementSchema
    py::class_< DraftingElementSchema> c5(m, "DraftingElementSchema");

    c5.def_static("ToElement",
           py::overload_cast<EditElementHandleR, CurveVectorCR, ElementHandleCP, bool, DgnModelRefR>(&DraftingElementSchema::ToElement),
           "eeh"_a, "curves"_a, "templateEh"_a, "is3d"_a, "modelRef"_a, DOC(Bentley, DgnPlatform, DraftingElementSchema, ToElement));

    c5.def_static("ToElement",
                  py::overload_cast<EditElementHandleR, ICurvePrimitiveCR, ElementHandleCP, bool, DgnModelRefR>(&DraftingElementSchema::ToElement),
                  "eeh"_a, "curve"_a, "templateEh"_a, "is3d"_a, "modelRef"_a, DOC(Bentley, DgnPlatform, DraftingElementSchema, ToElement));

    c5.def_static("ToElements", &DraftingElementSchema::ToElements, "eeh"_a, "curves"_a, "templateEh"_a, "is3d"_a, "modelRef"_a, DOC(Bentley, DgnPlatform, DraftingElementSchema, ToElements));

    c5.def_static("ToElement",
                  py::overload_cast<EditElementHandleR, ISolidPrimitiveCR, ElementHandleCP, DgnModelRefR>(&DraftingElementSchema::ToElement),
                  "eeh"_a, "solid"_a, "templateEh"_a, "modelRef"_a, DOC(Bentley, DgnPlatform, DraftingElementSchema, ToElement));

    c5.def_static("ToElement",
                  py::overload_cast<EditElementHandleR, MSBsplineSurfaceCR, ElementHandleCP, DgnModelRefR>(&DraftingElementSchema::ToElement),
                  "eeh"_a, "surface"_a, "templateEh"_a, "modelRef"_a, DOC(Bentley, DgnPlatform, DraftingElementSchema, ToElement));

    c5.def_static("ToElement",
                  py::overload_cast<EditElementHandleR, PolyfaceQueryCR, ElementHandleCP, DgnModelRefR>(&DraftingElementSchema::ToElement),
                  "eeh"_a, "meshData"_a, "templateEh"_a, "modelRef"_a, DOC(Bentley, DgnPlatform, DraftingElementSchema, ToElement));

    c5.def_static("ToElement",
                  py::overload_cast<EditElementHandleR, ISolidKernelEntityCR, ElementHandleCP, DgnModelRefR>(&DraftingElementSchema::ToElement),
                  "eeh"_a, "entityData"_a, "templateEh"_a, "modelRef"_a, DOC(Bentley, DgnPlatform, DraftingElementSchema, ToElement));

    c5.def_static("ToElement",
                  py::overload_cast<EditElementHandleR, IGeometryCR, ElementHandleCP, DgnModelRefR>(&DraftingElementSchema::ToElement),
                  "eeh"_a, "geom"_a, "templateEh"_a, "modelRef"_a, DOC(Bentley, DgnPlatform, DraftingElementSchema, ToElement));

    c5.def_static("ToElement",
                  py::overload_cast<EditElementHandleR, IGeometryCR, ElementHandleCP, DgnModelRefR>(&DraftingElementSchema::ToElement),
                  "eeh"_a, "geom"_a, "templateEh"_a, "modelRef"_a, DOC(Bentley, DgnPlatform, DraftingElementSchema, ToElement));

    c5.def_static("ToDroppedElements", &DraftingElementSchema::ToDroppedElements, "eh"_a, "agenda"_a, "graphics"_a, DOC(Bentley, DgnPlatform, DraftingElementSchema, ToDroppedElements));
    }