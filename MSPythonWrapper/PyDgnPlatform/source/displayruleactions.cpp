/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnPlatform\source\displayruleaction.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <DgnPlatform/DisplayRuleActions.h>



static const char * __doc_Bentley_DgnPlatform_DisplayStyleOverrideAction_SetDisplayStyleIndex =R"doc(Sets index that represents DisplayStyle in the active file and should
be used by this action. Bentley Systems +---------------+-------------
--+---------------+---------------+---------------+------)doc";

static const char * __doc_Bentley_DgnPlatform_DisplayStyleOverrideAction_GetDisplayStyleIndex =R"doc(Returns index that represents DisplayStyle in the active file and
should be used by this action. Bentley Systems +---------------+------
---------+---------------+---------------+---------------+------)doc";

static const char * __doc_Bentley_DgnPlatform_AreaPatternAction_SetParams =R"doc(Sets AreaPattern of an element that should be applied by this action.
Bentley Systems +---------------+---------------+---------------+-----
----------+---------------+------)doc";

static const char * __doc_Bentley_DgnPlatform_AreaPatternAction_GetParams =R"doc(Returns AreaPatternParams of an element that should be applied by this
action. Bentley Systems +---------------+---------------+-------------
--+---------------+---------------+------)doc";

static const char * __doc_Bentley_DgnPlatform_ElementPriorityAction_SetElementPriority =R"doc(Sets whether element display should be off. Bentley Systems +---------
------+---------------+---------------+---------------+---------------
+------)doc";

static const char * __doc_Bentley_DgnPlatform_ElementPriorityAction_GetElementPriority =R"doc(Returns true if element display is off. Bentley Systems +-------------
--+---------------+---------------+---------------+---------------+---
---)doc";

static const char * __doc_Bentley_DgnPlatform_TransparencyOverrideAction_SetTransparency =R"doc(Sets transparency of an element that should be applied by this action.
Bentley Systems +---------------+---------------+---------------+-----
----------+---------------+------)doc";

static const char * __doc_Bentley_DgnPlatform_TransparencyOverrideAction_GetTransparency =R"doc(Returns transparency of an element that should be applied by this
action. Bentley Systems +---------------+---------------+-------------
--+---------------+---------------+------)doc";

static const char * __doc_Bentley_DgnPlatform_WeightOverrideAction_SetLineWeight =R"doc(Sets line weight of an element that should be applied by this action.
Bentley Systems +---------------+---------------+---------------+-----
----------+---------------+------)doc";

static const char * __doc_Bentley_DgnPlatform_WeightOverrideAction_GetLineWeight =R"doc(Returns line weight of an element that should be applied by this
action. Bentley Systems +---------------+---------------+-------------
--+---------------+---------------+------)doc";

static const char * __doc_Bentley_DgnPlatform_StyleOverrideAction_SetLineStyle =R"doc(Sets line style of an element that should be applied by this action.
Bentley Systems +---------------+---------------+---------------+-----
----------+---------------+------)doc";

static const char * __doc_Bentley_DgnPlatform_StyleOverrideAction_GetLineStyle =R"doc(Returns line style of an element that should be applied by this
action. Bentley Systems +---------------+---------------+-------------
--+---------------+---------------+------)doc";

static const char * __doc_Bentley_DgnPlatform_FillColorOverrideAction_SetElementFillColor =R"doc(Sets fill color of an element that should be applied by this action.
Bentley Systems +---------------+---------------+---------------+-----
----------+---------------+------)doc";

static const char * __doc_Bentley_DgnPlatform_FillColorOverrideAction_GetElementFillColor =R"doc(Returns fill color of an element that should be applied by this
action. Bentley Systems +---------------+---------------+-------------
--+---------------+---------------+------)doc";

static const char * __doc_Bentley_DgnPlatform_ColorOverrideAction_SetElementColor =R"doc(Sets color of an element that should be applied by this action.
Bentley Systems +---------------+---------------+---------------+-----
----------+---------------+------)doc";

static const char * __doc_Bentley_DgnPlatform_ColorOverrideAction_GetElementColor =R"doc(Returns color of an element that should be applied by this action.
Bentley Systems +---------------+---------------+---------------+-----
----------+---------------+------)doc";

static const char * __doc_Bentley_DgnPlatform_ElementDisplayAction_SetIsElementDisplayOff =R"doc(Sets whether element display should be off. Bentley Systems +---------
------+---------------+---------------+---------------+---------------
+------)doc";

static const char * __doc_Bentley_DgnPlatform_ElementDisplayAction_IsElementDisplayOff =R"doc(Returns true if element display is off. Bentley Systems +-------------
--+---------------+---------------+---------------+---------------+---
---)doc";

static const char * __doc_Bentley_DgnPlatform_IDisplayRuleAction_Clone =R"doc(Creates exact copy of an instance. Bentley Systems +---------------+--
-------------+---------------+---------------+---------------+------)doc";

static const char * __doc_Bentley_DgnPlatform_IDisplayRuleAction_GetActionId =R"doc(GetActionId should return unique Id of an action. Bentley Systems +---
------------+---------------+---------------+---------------+---------
------+------)doc";

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_DisplayRuleActions(py::module_& m)
    {
    //===================================================================================
    // enum class DisplayRuleActionId
    py::enum_< DisplayRuleActionId>(m, "DisplayRuleActionId")
        .value("eElementDisplay", DisplayRuleActionId::ElementDisplay)
        .value("eColorOverride", DisplayRuleActionId::ColorOverride)
        .value("eFillColorOverride", DisplayRuleActionId::FillColorOverride)
        .value("eStyleOverride", DisplayRuleActionId::StyleOverride)
        .value("eWeightOverride", DisplayRuleActionId::WeightOverride)
        .value("eTransparencyOverride", DisplayRuleActionId::TransparencyOverride)
        .value("eElementPriority", DisplayRuleActionId::ElementPriority)
        .value("ePresentationForm", DisplayRuleActionId::PresentationForm)
        .value("eAreaHatch", DisplayRuleActionId::AreaHatch)
        .value("eAreaPattern", DisplayRuleActionId::AreaPattern)
        .value("eMaterialOverride", DisplayRuleActionId::MaterialOverride)
        .value("eLevelOfDetail", DisplayRuleActionId::LevelOfDetail)
        .value("eDisplayStyleOverride", DisplayRuleActionId::DisplayStyleOverride)
        .export_values();

    //===================================================================================
    // struct IDisplayRuleAction
    py::class_< IDisplayRuleAction
        , IDisplayRuleActionPtr
    > c1(m, "IDisplayRuleAction");


    c1.def_property_readonly("ActionId", &IDisplayRuleAction::GetActionId);
    c1.def("GetActionId", &IDisplayRuleAction::GetActionId, DOC(Bentley, DgnPlatform, IDisplayRuleAction, GetActionId));

    c1.def("__eq__", [] (IDisplayRuleActionCR self, IDisplayRuleActionCR other) { return self.Equals(other); });
    c1.def("Clone", &IDisplayRuleAction::Clone, "dgnFile"_a, DOC(Bentley, DgnPlatform, IDisplayRuleAction, Clone));

    //===================================================================================
    // struct ElementDisplayAction
    py::class_< ElementDisplayAction, ElementDisplayActionPtr, IDisplayRuleAction> c2(m, "ElementDisplayAction");

    c2.def(py::init(&ElementDisplayAction::Create), "elementDisplayOff"_a);
    c2.def_property("ElementDisplayOff", &ElementDisplayAction::IsElementDisplayOff, &ElementDisplayAction::SetIsElementDisplayOff);
    c2.def("IsElementDisplayOff", &ElementDisplayAction::IsElementDisplayOff, DOC(Bentley, DgnPlatform, ElementDisplayAction, IsElementDisplayOff));
    c2.def("SetIsElementDisplayOff", &ElementDisplayAction::SetIsElementDisplayOff, "value"_a, DOC(Bentley, DgnPlatform, ElementDisplayAction, SetIsElementDisplayOff));

    //===================================================================================
    // struct ColorOverrideAction
    py::class_< ColorOverrideAction, ColorOverrideActionPtr, IDisplayRuleAction> c3(m, "ColorOverrideAction");

    c3.def(py::init(&ColorOverrideAction::Create), "elementColor"_a, "dgnFile"_a);
    c3.def_property("ElementColor", &ColorOverrideAction::GetElementColor, &ColorOverrideAction::SetElementColor);
    c3.def("GetElementColor", &ColorOverrideAction::GetElementColor, DOC(Bentley, DgnPlatform, ColorOverrideAction, GetElementColor));
    c3.def("SetElementColor", &ColorOverrideAction::SetElementColor, "value"_a, DOC(Bentley, DgnPlatform, ColorOverrideAction, SetElementColor));

    //===================================================================================
    // struct FillColorOverrideAction
    py::class_< FillColorOverrideAction, FillColorOverrideActionPtr, IDisplayRuleAction> c4(m, "FillColorOverrideAction");

    c4.def(py::init(&FillColorOverrideAction::Create), "fillColor"_a, "dgnFile"_a);
    c4.def_property("ElementFillColor", &FillColorOverrideAction::GetElementFillColor, &FillColorOverrideAction::SetElementFillColor);
    c4.def("GetElementFillColor", &FillColorOverrideAction::GetElementFillColor, DOC(Bentley, DgnPlatform, FillColorOverrideAction, GetElementFillColor));
    c4.def("SetElementFillColor", &FillColorOverrideAction::SetElementFillColor, "value"_a, DOC(Bentley, DgnPlatform, FillColorOverrideAction, SetElementFillColor));

    //===================================================================================
    // struct StyleOverrideAction
    py::class_< StyleOverrideAction, StyleOverrideActionPtr, IDisplayRuleAction> c5(m, "StyleOverrideAction");

    c5.def(py::init(&StyleOverrideAction::Create), "lineStyle"_a, "dgnFile"_a);
    c5.def_property("LineStyle", &StyleOverrideAction::GetLineStyle, &StyleOverrideAction::SetLineStyle);
    c5.def("GetLineStyle", &StyleOverrideAction::GetLineStyle, DOC(Bentley, DgnPlatform, StyleOverrideAction, GetLineStyle));
    c5.def("SetLineStyle", &StyleOverrideAction::SetLineStyle, "value"_a, DOC(Bentley, DgnPlatform, StyleOverrideAction, SetLineStyle));

    //===================================================================================
    // struct WeightOverrideAction
    py::class_< WeightOverrideAction, WeightOverrideActionPtr, IDisplayRuleAction> c6(m, "WeightOverrideAction");

    c6.def(py::init(&WeightOverrideAction::Create), "lineWeight"_a);
    c6.def_property("LineWeight", &WeightOverrideAction::GetLineWeight, &WeightOverrideAction::SetLineWeight);
    c6.def("GetLineWeight", &WeightOverrideAction::GetLineWeight, DOC(Bentley, DgnPlatform, WeightOverrideAction, GetLineWeight));
    c6.def("SetLineWeight", &WeightOverrideAction::SetLineWeight, "value"_a, DOC(Bentley, DgnPlatform, WeightOverrideAction, SetLineWeight));

    //===================================================================================
    // struct TransparencyOverrideAction
    py::class_< TransparencyOverrideAction, TransparencyOverrideActionPtr, IDisplayRuleAction> c7(m, "TransparencyOverrideAction");

    c7.def(py::init(&TransparencyOverrideAction::Create), "transparency"_a);
    c7.def_property("Transparency", &TransparencyOverrideAction::GetTransparency, &TransparencyOverrideAction::SetTransparency);
    c7.def("GetTransparency", &TransparencyOverrideAction::GetTransparency, DOC(Bentley, DgnPlatform, TransparencyOverrideAction, GetTransparency));
    c7.def("SetTransparency", &TransparencyOverrideAction::SetTransparency, "value"_a, DOC(Bentley, DgnPlatform, TransparencyOverrideAction, SetTransparency));

    //===================================================================================
    // struct ElementPriorityAction
    py::class_< ElementPriorityAction, ElementPriorityActionPtr, IDisplayRuleAction> c8(m, "ElementPriorityAction");

    c8.def(py::init(&ElementPriorityAction::Create), "elementPriority"_a);
    c8.def_property("ElementPriority", &ElementPriorityAction::GetElementPriority, &ElementPriorityAction::SetElementPriority);
    c8.def("GetElementPriority", &ElementPriorityAction::GetElementPriority, DOC(Bentley, DgnPlatform, ElementPriorityAction, GetElementPriority));
    c8.def("SetElementPriority", &ElementPriorityAction::SetElementPriority, "priority"_a, DOC(Bentley, DgnPlatform, ElementPriorityAction, SetElementPriority));

    //===================================================================================
    // struct AreaHatchAction
    py::class_< AreaHatchAction, AreaHatchActionPtr, IDisplayRuleAction> c9(m, "AreaHatchAction");

    if (true)
        {
        //===================================================================================
        // struct HatchParams
        py::class_< AreaHatchAction::HatchParams> c9_1(c9, "HatchParams");

        c9_1.def(py::init([](double distance1, double angle1, boost::optional<double> distance2, boost::optional<double> angle2,
                             bool annotationScaleOn, boost::optional<UInt32> color, boost::optional<UInt32> weight, boost::optional<Int32> style)
                            {
                            return new AreaHatchAction::HatchParams(distance1, angle1, distance2.get_ptr(), angle2.get_ptr(),
                                                                    annotationScaleOn, color.get_ptr(), weight.get_ptr(), style.get_ptr());
                            }),
                            "distance1"_a, "angle1"_a, "distance2"_a = nullptr, "angle2"_a = nullptr,
                            "annotationScaleOn"_a = false, "color"_a = nullptr, "weight"_a = nullptr, "style"_a = nullptr);
        }
    c9.def(py::init(py::overload_cast<AreaHatchAction::HatchParams const& , DgnFileR>(&AreaHatchAction::Create)), "params"_a, "dgnFile"_a);
    c9.def_property("Params",
                    py::cpp_function(&AreaHatchAction::GetParams, py::return_value_policy::reference_internal),
                    py::cpp_function(&AreaHatchAction::SetParams));

    //===================================================================================
    // struct AreaPatternAction
    py::class_< AreaPatternAction, AreaPatternActionPtr, IDisplayRuleAction> c10(m, "AreaPatternAction");

    if (true)
        {
        //===================================================================================
        // struct AreaPatternParams
        py::class_< AreaPatternAction::AreaPatternParams> c10_1(c10, "AreaPatternParams");

        // NOTE: ALL pointer typed parameters are legal here for Python as they only used for input and with pointer to indicate that is optional.
        c10_1.def(py::init([](ElementId cellId, double scale, bool annotationScaleOn, boost::optional<double> angle,
                           boost::optional<UInt32> color, boost::optional<UInt32> weight, boost::optional<Int32> style)
                           {
                               return new AreaPatternAction::AreaPatternParams(cellId, scale, annotationScaleOn, angle.get_ptr(),
                                                                               color.get_ptr(), weight.get_ptr(), style.get_ptr());
                           }), 
                           "cellId"_a, "scale"_a, "annotationScaleOn"_a = false, "angle"_a = nullptr,
                           "color"_a = nullptr, "weight"_a = nullptr, "style"_a = nullptr);
        }
    c10.def(py::init(py::overload_cast<AreaPatternAction::AreaPatternParams const&, DgnFileR>(&AreaPatternAction::Create)), "params"_a, "dgnFile"_a);
    c10.def_property("Params",
                    py::cpp_function(&AreaPatternAction::GetParams, py::return_value_policy::reference_internal),
                    py::cpp_function(&AreaPatternAction::SetParams));
    c10.def("GetParams", &AreaPatternAction::GetParams, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, AreaPatternAction, GetParams));
    c10.def("SetParams", &AreaPatternAction::SetParams, "params"_a, DOC(Bentley, DgnPlatform, AreaPatternAction, SetParams));

    //===================================================================================
    // struct DisplayStyleOverrideAction
    py::class_< DisplayStyleOverrideAction, DisplayStyleOverrideActionPtr, IDisplayRuleAction> c11(m, "DisplayStyleOverrideAction");

    c11.def(py::init(py::overload_cast<UInt32, DgnFileR>(&DisplayStyleOverrideAction::Create)), "styleIndex"_a, "dgnFile"_a);
    c11.def_property("DisplayStyleIndex", &DisplayStyleOverrideAction::GetDisplayStyleIndex, &DisplayStyleOverrideAction::SetDisplayStyleIndex);
    c11.def("GetDisplayStyleIndex", &DisplayStyleOverrideAction::GetDisplayStyleIndex, DOC(Bentley, DgnPlatform, DisplayStyleOverrideAction, GetDisplayStyleIndex));
    c11.def("SetDisplayStyleIndex", &DisplayStyleOverrideAction::SetDisplayStyleIndex, "styleIndex"_a, DOC(Bentley, DgnPlatform, DisplayStyleOverrideAction, SetDisplayStyleIndex));

    }