/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnPlatform\source\displayfilter.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <DgnPlatform/DisplayFilter.h>



static const char * __doc_Bentley_DgnPlatform_DisplayFilter_CreatePresentationFormFlagTest =R"doc(Creates a new DisplayFilter operator to test for a existence of the to
the supplied form flag.

:param formFlag:
    The form flag to test against.)doc";

static const char * __doc_Bentley_DgnPlatform_DisplayFilter_CreatePresentationFormIdTest =R"doc(Creates a new DisplayFilter operator to test for a match to the
supplied formId.

:param formId:
    The form Id to test against.)doc";

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_DisplayFilter(py::module_& m)
    {
    //===================================================================================    
    // struct DisplayFilter
    py::class_< DisplayFilter> c1(m, "DisplayFilter");

    if (true)
        {
        //===================================================================================    
        // enum TestMode
        py::enum_< DisplayFilter::TestMode>(c1, "TestMode", py::arithmetic())
            .value("eTestMode_Equal", DisplayFilter::TestMode_Equal)
            .value("eTestMode_NotEqual", DisplayFilter::TestMode_NotEqual)
            .value("eTestMode_LessThan", DisplayFilter::TestMode_LessThan)
            .value("eTestMode_GreaterThan", DisplayFilter::TestMode_GreaterThan)
            .export_values();

        //===================================================================================
        // enum Orientation
        py::enum_< DisplayFilter::Orientation>(c1, "Orientation", py::arithmetic())
            .value("eOrientation_Top", DisplayFilter::Orientation_Top)
            .value("eOrientation_Elevation", DisplayFilter::Orientation_Elevation)
            .export_values();

        //===================================================================================
        // enum ViewFlag
        py::enum_< DisplayFilter::ViewFlag>(c1, "ViewFlag", py::arithmetic())
            .value("eViewFlag_BoundaryDisplay", DisplayFilter::ViewFlag_BoundaryDisplay)
            .value("eViewFlag_Constructions", DisplayFilter::ViewFlag_Constructions)
            .value("eViewFlag_Dimensions", DisplayFilter::ViewFlag_Dimensions)
            .value("eViewFlag_DataFields", DisplayFilter::ViewFlag_DataFields)
            .value("eViewFlag_Fill", DisplayFilter::ViewFlag_Fill)
            .value("eViewFlag_Grid", DisplayFilter::ViewFlag_Grid)
            .value("eViewFlag_LevelOverrides", DisplayFilter::ViewFlag_LevelOverrides)
            .value("eViewFlag_LineStyles", DisplayFilter::ViewFlag_LineStyles)
            .value("eViewFlag_LineWeights", DisplayFilter::ViewFlag_LineWeights)
            .value("eViewFlag_Patterns", DisplayFilter::ViewFlag_Patterns)
            .value("eViewFlag_Tags", DisplayFilter::ViewFlag_Tags)
            .value("eViewFlag_Text", DisplayFilter::ViewFlag_Text)
            .value("eViewFlag_Textnodes", DisplayFilter::ViewFlag_Textnodes)
            .value("eViewFlag_Transparency", DisplayFilter::ViewFlag_Transparency)
            .value("eViewFlag_HideNamedPresentation", DisplayFilter::ViewFlag_HideNamedPresentation)
            .value("eViewFlag_DisableHeightMaps", DisplayFilter::ViewFlag_DisableHeightMaps)
            .value("eViewFlag_PlacementPointDisplay", DisplayFilter::ViewFlag_PlacementPointDisplay)
            .export_values();

        //===================================================================================
        // enum ViewXFlag
        py::enum_< DisplayFilter::ViewXFlag>(c1, "ViewXFlag", py::arithmetic())
            .value("eViewXFlag_ExampleCenterline", DisplayFilter::ViewXFlag_ExampleCenterline)
            .export_values();

        //===================================================================================
        // enum ViewXInteger
        py::enum_< DisplayFilter::ViewXInteger>(c1, "ViewXInteger", py::arithmetic())
            .value("eViewXInteger_LevelOfDetail", DisplayFilter::ViewXInteger_LevelOfDetail)
            .export_values();

        //===================================================================================
        // enum ViewContextFlag
        py::enum_< DisplayFilter::ViewContextFlag>(c1, "ViewContextFlag", py::arithmetic())
            .value("eViewContextFlag_ShowFieldBackground", DisplayFilter::ViewContextFlag_ShowFieldBackground)
            .value("eViewContextFlag_ShowFieldBackgroundFromTextStyle", DisplayFilter::ViewContextFlag_ShowFieldBackgroundFromTextStyle)
            .export_values();

        //===================================================================================
        // enum DrawingAttachmentType
        py::enum_< DisplayFilter::DrawingAttachmentType>(c1, "DrawingAttachmentType", py::arithmetic())
            .value("eDrawingAttachmentType_None", DisplayFilter::DrawingAttachmentType_None)
            .value("eDrawingAttachmentType_Plan", DisplayFilter::DrawingAttachmentType_Plan)
            .value("eDrawingAttachmentType_Elevation", DisplayFilter::DrawingAttachmentType_Elevation)
            .value("eDrawingAttachmentType_Section", DisplayFilter::DrawingAttachmentType_Section)
            .value("eDrawingAttachmentType_Detail", DisplayFilter::DrawingAttachmentType_Detail)
            .value("eDrawingAttachmentType_Markup", DisplayFilter::DrawingAttachmentType_Markup)
            .value("eDrawingAttachmentType_Other", DisplayFilter::DrawingAttachmentType_Other)
            .export_values();

        //===================================================================================
        // enum LevelOfDetail
        py::enum_< DisplayFilter::LevelOfDetail>(c1, "LevelOfDetail", py::arithmetic())
            .value("eLevelOfDetail_Fine", DisplayFilter::LevelOfDetail_Fine)
            .value("eLevelOfDetail_Medium", DisplayFilter::LevelOfDetail_Medium)
            .value("eLevelOfDetail_Coarse", DisplayFilter::LevelOfDetail_Coarse)
            .export_values();

        //===================================================================================
        // struct Operator
        py::class_<DisplayFilter::Operator, DisplayFilter::OperatorPtr> c1_1(c1, "Operator");        
        }

    c1.def_static("And", &DisplayFilter::And, "op1"_a, "op2"_a);
    c1.def_static("Or", &DisplayFilter::Or, "op1"_a, "op2"_a);
    c1.def_static("Not", &DisplayFilter::Not, "operand"_a);

    c1.def_static("CreateDrawPurposeTest", &DisplayFilter::CreateDrawPurposeTest, "purpose"_a, "testMode"_a);
    c1.def_static("CreateRenderModeTest", &DisplayFilter::CreateRenderModeTest, "renderMode"_a, "testMode"_a);

    c1.def_static("CreateViewFlagTest", &DisplayFilter::CreateViewFlagTest, "viewFlag"_a, "testState"_a);
    c1.def_static("CreateViewXFlagTest", &DisplayFilter::CreateViewXFlagTest, "viewFlag"_a, "trueIfXAttributePresent"_a, "testState"_a);
    c1.def_static("CreateViewXIntegerTest", &DisplayFilter::CreateViewXIntegerTest, "viewXInteger"_a, "testValue"_a, "testMode"_a);
    c1.def_static("CreateLevelOfDetailTest", &DisplayFilter::CreateLevelOfDetailTest, "load"_a, "testMode"_a);
    c1.def_static("CreateViewSizeTest", &DisplayFilter::CreateViewSizeTest, "origin"_a, "pixelSize"_a, "largerThan"_a);
    c1.def_static("CreateClipVolumePassTest", &DisplayFilter::CreateClipVolumePassTest, "pass"_a, "testMode"_a);
    c1.def_static("CreateLevelTest", &DisplayFilter::CreateLevelTest, "levelId"_a);
    c1.def_static("CreateInViewletTest", &DisplayFilter::CreateInViewletTest, "testState"_a);
    c1.def_static("CreateViewOrientationTest", &DisplayFilter::CreateViewOrientationTest, "orientation"_a, "testMode"_a);
    c1.def_static("CreateDrawingAttachmentTypeTest", &DisplayFilter::CreateDrawingAttachmentTypeTest, "attachmentType"_a, "testMode"_a);
    c1.def_static("CreateViewAxisAngleTest", &DisplayFilter::CreateViewAxisAngleTest, "axis"_a, "angle"_a, "testMode"_a);
    c1.def_static("CreateViewContextFlagTest", &DisplayFilter::CreateViewContextFlagTest, "flag"_a, "testState"_a);
    c1.def_static("CreatePresentationFormIdTest", &DisplayFilter::CreatePresentationFormIdTest, "formId"_a, DOC(Bentley, DgnPlatform, DisplayFilter, CreatePresentationFormIdTest));
    c1.def_static("CreatePresentationFormFlagTest", &DisplayFilter::CreatePresentationFormFlagTest, "formFlag"_a, DOC(Bentley, DgnPlatform, DisplayFilter, CreatePresentationFormFlagTest));

    c1.def_static("If", &DisplayFilter::If, "viewContext"_a, "element"_a, "filterOperator"_a);
    c1.def_static("ElseIf", &DisplayFilter::ElseIf, "viewContext"_a, "element"_a, "filterOperator"_a);
    c1.def_static("Else", &DisplayFilter::Else, "viewContext"_a);
    c1.def_static("End", &DisplayFilter::End, "viewContext"_a);
    c1.def_static("SetViewXFlag", &DisplayFilter::SetViewXFlag, "dvSettings"_a, "xFlag"_a, "state"_a, "trueIfXAttributePresent"_a);
    c1.def_static("GetViewXFlag", &DisplayFilter::GetViewXFlag, "dvSettings"_a, "xFlag"_a, "trueIfXAttributePresent"_a);
    c1.def_static("SetViewXInteger", &DisplayFilter::SetViewXInteger, "dvSettings"_a, "xInteger"_a, "value"_a);
    c1.def_static("GetViewXInteger", &DisplayFilter::GetViewXInteger, "dvSettings"_a, "xInteger"_a);    
    }