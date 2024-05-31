/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnPlatform\source\propertycontext.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <DgnPlatform/PropertyContext.h>



static const char * __doc_Bentley_DgnPlatform_EachLevelArg_GetEffectiveValue =R"doc(Get the effective value of the property that is used for display. This
is computed from the stored value considering header overrides.)doc";

static const char * __doc_Bentley_DgnPlatform_EachLevelArg_SetStoredValue =R"doc(Assign a new value in place of the one passed to the callback.)doc";

static const char * __doc_Bentley_DgnPlatform_EachLevelArg_GetStoredValue =R"doc(Get the value of the property that is stored in the element.)doc";

static const char * __doc_Bentley_DgnPlatform_EachPropertyBaseArg_GetPropertyFlags =R"doc(Flags associated with the property value.)doc";

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_PropertyContext(py::module_& m)
    {
    //===================================================================================
    // enum class EditPropertyPurpose
    py::enum_< EditPropertyPurpose>(m, "EditPropertyPurpose")
        .value("eChange", EditPropertyPurpose::Change)
        .value("eRemap", EditPropertyPurpose::Remap)
        .export_values();

    //===================================================================================
    // enum class QueryPropertyPurpose
    py::enum_< QueryPropertyPurpose>(m, "QueryPropertyPurpose")
        .value("eNotSpecified", QueryPropertyPurpose::NotSpecified)
        .value("eMatch", QueryPropertyPurpose::Match)
        .export_values();

    //===================================================================================
    // enum PropsCallbackFlags
    py::enum_< PropsCallbackFlags>(m, "PropsCallbackFlags", py::arithmetic())
        .value("ePROPSCALLBACK_FLAGS_NoFlagsSet", PROPSCALLBACK_FLAGS_NoFlagsSet)
        .value("ePROPSCALLBACK_FLAGS_ElementIgnoresID", PROPSCALLBACK_FLAGS_ElementIgnoresID)
        .value("ePROPSCALLBACK_FLAGS_IsBaseID", PROPSCALLBACK_FLAGS_IsBaseID)
        .value("ePROPSCALLBACK_FLAGS_IsBackgroundID", PROPSCALLBACK_FLAGS_IsBackgroundID)
        .value("ePROPSCALLBACK_FLAGS_IsDecorationID", PROPSCALLBACK_FLAGS_IsDecorationID)
        .value("ePROPSCALLBACK_FLAGS_UndisplayedID", PROPSCALLBACK_FLAGS_UndisplayedID)
        .value("ePROPSCALLBACK_FLAGS_MaterialAssigned", PROPSCALLBACK_FLAGS_MaterialAssigned)
        .export_values();


    //===================================================================================
    // enum class StyleParamsRemapping
    py::enum_< StyleParamsRemapping>(m, "StyleParamsRemapping")
        .value("eInvalid", StyleParamsRemapping::Invalid)
        .value("eNoChange", StyleParamsRemapping::NoChange)
        .value("eApplyStyle", StyleParamsRemapping::ApplyStyle)
        .value("eOverride", StyleParamsRemapping::Override)
        .export_values();

    //===================================================================================
    // enum ElementProperties
    py::enum_< ElementProperties>(m, "ElementProperties", py::arithmetic())
        .value("eELEMENT_PROPERTY_None", ELEMENT_PROPERTY_None)
        .value("eELEMENT_PROPERTY_Level", ELEMENT_PROPERTY_Level)
        .value("eELEMENT_PROPERTY_Color", ELEMENT_PROPERTY_Color)
        .value("eELEMENT_PROPERTY_Linestyle", ELEMENT_PROPERTY_Linestyle)
        .value("eELEMENT_PROPERTY_Font", ELEMENT_PROPERTY_Font)
        .value("eELEMENT_PROPERTY_TextStyle", ELEMENT_PROPERTY_TextStyle)
        .value("eELEMENT_PROPERTY_DimStyle", ELEMENT_PROPERTY_DimStyle)
        .value("eELEMENT_PROPERTY_MLineStyle", ELEMENT_PROPERTY_MLineStyle)
        .value("eELEMENT_PROPERTY_Material", ELEMENT_PROPERTY_Material)
        .value("eELEMENT_PROPERTY_Weight", ELEMENT_PROPERTY_Weight)
        .value("eELEMENT_PROPERTY_ElementClass", ELEMENT_PROPERTY_ElementClass)
        .value("eELEMENT_PROPERTY_Transparency", ELEMENT_PROPERTY_Transparency)
        .value("eELEMENT_PROPERTY_DisplayPriority", ELEMENT_PROPERTY_DisplayPriority)
        .value("eELEMENT_PROPERTY_ElementTemplate", ELEMENT_PROPERTY_ElementTemplate)
        .value("eELEMENT_PROPERTY_Thickness", ELEMENT_PROPERTY_Thickness)
        .value("eELEMENT_PROPERTY_MaterialAssignment", ELEMENT_PROPERTY_MaterialAssignment)
        .value("eELEMENT_PROPERTY_LastValue", ELEMENT_PROPERTY_LastValue)
        .value("eELEMENT_PROPERTY_All", ELEMENT_PROPERTY_All)
        .export_values();

    //===================================================================================
    // class EachPropertyBaseArg
    py::class_< EachPropertyBaseArg> c1(m, "EachPropertyBaseArg");

    c1.def_property_readonly("PropertyFlags", &EachPropertyBaseArg::GetPropertyFlags);
    c1.def("GetPropertyFlags", &EachPropertyBaseArg::GetPropertyFlags, DOC(Bentley, DgnPlatform, EachPropertyBaseArg, GetPropertyFlags));

    //===================================================================================
    // class EachLevelArg
    py::class_< EachLevelArg, EachPropertyBaseArg> c2(m, "EachLevelArg");

    c2.def_property("StoredValue", &EachLevelArg::GetStoredValue, &EachLevelArg::SetStoredValue);
    c2.def("GetStoredValue", &EachLevelArg::GetStoredValue, DOC(Bentley, DgnPlatform, EachLevelArg, GetStoredValue));
    
    c2.def("SetStoredValue", &EachLevelArg::SetStoredValue, "newVal"_a, DOC(Bentley, DgnPlatform, EachLevelArg, SetStoredValue));
    
    c2.def_property_readonly("EffectiveValue", &EachLevelArg::GetEffectiveValue);
    c2.def("GetEffectiveValue", &EachLevelArg::GetEffectiveValue, DOC(Bentley, DgnPlatform, EachLevelArg, GetEffectiveValue));

    //===================================================================================
    // class EachColorArg
    py::class_< DgnPlatform::EachColorArg, EachPropertyBaseArg> c3(m, "EachColorArg");

    c3.def_property("StoredValue", &DgnPlatform::EachColorArg::GetStoredValue, &DgnPlatform::EachColorArg::SetStoredValue);
    c3.def("GetStoredValue", &DgnPlatform::EachColorArg::GetStoredValue);
    c3.def("SetStoredValue", &DgnPlatform::EachColorArg::SetStoredValue, "newVal"_a);

    c3.def_property_readonly("EffectiveValue", &DgnPlatform::EachColorArg::GetEffectiveValue);
    c3.def("GetEffectiveValue", &DgnPlatform::EachColorArg::GetEffectiveValue);

    //===================================================================================
    // class EachLineStyleArg
    py::class_< DgnPlatform::EachLineStyleArg, EachPropertyBaseArg> c4(m, "EachLineStyleArg");

    c4.def_property("StoredValue", &DgnPlatform::EachLineStyleArg::GetStoredValue, &DgnPlatform::EachLineStyleArg::SetStoredValue);
    c4.def("GetStoredValue", &DgnPlatform::EachLineStyleArg::GetStoredValue);
    c4.def("SetStoredValue", &DgnPlatform::EachLineStyleArg::SetStoredValue, "newVal"_a);

    c4.def_property_readonly("EffectiveValue", &DgnPlatform::EachLineStyleArg::GetEffectiveValue);
    c4.def("GetEffectiveValue", &DgnPlatform::EachLineStyleArg::GetEffectiveValue);

    c4.def_property("Params", &DgnPlatform::EachLineStyleArg::GetParams, &DgnPlatform::EachLineStyleArg::SetParams);
    c4.def("GetParams", &DgnPlatform::EachLineStyleArg::GetParams, py::return_value_policy::reference_internal);
    c4.def("SetParams", &DgnPlatform::EachLineStyleArg::SetParams, "newVal"_a, py::keep_alive<1, 2>());
    c4.def("SetParamsChanged", &DgnPlatform::EachLineStyleArg::SetParamsChanged);

    //===================================================================================
    // class EachFontArg
    py::class_< DgnPlatform::EachFontArg, EachPropertyBaseArg> c5(m, "EachFontArg");

    c5.def_property("StoredValue", &DgnPlatform::EachFontArg::GetStoredValue, &DgnPlatform::EachFontArg::SetStoredValue);
    c5.def("GetStoredValue", &DgnPlatform::EachFontArg::GetStoredValue);
    c5.def("SetStoredValue", &DgnPlatform::EachFontArg::SetStoredValue, "newVal"_a);

    //===================================================================================
    // class EachTextStyleArg
    py::class_< DgnPlatform::EachTextStyleArg, EachPropertyBaseArg> c6(m, "EachTextStyleArg");

    c6.def_property("RemappingAction", &DgnPlatform::EachTextStyleArg::GetRemappingAction, &DgnPlatform::EachTextStyleArg::SetRemappingAction);
    c6.def("GetRemappingAction", &DgnPlatform::EachTextStyleArg::GetRemappingAction);
    c6.def("SetRemappingAction", &DgnPlatform::EachTextStyleArg::SetRemappingAction, "remapping"_a);

    c6.def_property("StoredValue", &DgnPlatform::EachTextStyleArg::GetStoredValue, &DgnPlatform::EachTextStyleArg::SetStoredValue);
    c6.def("GetStoredValue", &DgnPlatform::EachTextStyleArg::GetStoredValue);
    c6.def("SetStoredValue", &DgnPlatform::EachTextStyleArg::SetStoredValue, "newVal"_a);

    //===================================================================================
    // class EachDimStyleArg
    py::class_< DgnPlatform::EachDimStyleArg, EachPropertyBaseArg> c7(m, "EachDimStyleArg");

    c7.def_property("RemappingAction", &DgnPlatform::EachDimStyleArg::GetRemappingAction, &DgnPlatform::EachDimStyleArg::SetRemappingAction);
    c7.def("GetRemappingAction", &DgnPlatform::EachDimStyleArg::GetRemappingAction);
    c7.def("SetRemappingAction", &DgnPlatform::EachDimStyleArg::SetRemappingAction, "remapping"_a);

    c7.def_property("StoredValue", &DgnPlatform::EachDimStyleArg::GetStoredValue, &DgnPlatform::EachDimStyleArg::SetStoredValue);
    c7.def("GetStoredValue", &DgnPlatform::EachDimStyleArg::GetStoredValue);
    c7.def("SetStoredValue", &DgnPlatform::EachDimStyleArg::SetStoredValue, "newVal"_a);

    //===================================================================================
    // class EachMLineStyleArg
    py::class_< DgnPlatform::EachMLineStyleArg, EachPropertyBaseArg> c8(m, "EachMLineStyleArg");

    c8.def_property("RemappingAction", &DgnPlatform::EachMLineStyleArg::GetRemappingAction, &DgnPlatform::EachMLineStyleArg::SetRemappingAction);
    c8.def("GetRemappingAction", &DgnPlatform::EachMLineStyleArg::GetRemappingAction);
    c8.def("SetRemappingAction", &DgnPlatform::EachMLineStyleArg::SetRemappingAction, "remapping"_a);

    c8.def_property("StoredValue", &DgnPlatform::EachMLineStyleArg::GetStoredValue, &DgnPlatform::EachMLineStyleArg::SetStoredValue);
    c8.def("GetStoredValue", &DgnPlatform::EachMLineStyleArg::GetStoredValue);
    c8.def("SetStoredValue", &DgnPlatform::EachMLineStyleArg::SetStoredValue, "newVal"_a);

    //===================================================================================
    // class EachMaterialArg
    py::class_< DgnPlatform::EachMaterialArg, EachPropertyBaseArg> c9(m, "EachMaterialArg");

    c9.def_property("StoredValue", &DgnPlatform::EachMaterialArg::GetStoredValue, &DgnPlatform::EachMaterialArg::SetStoredValue);
    c9.def("GetStoredValue", &DgnPlatform::EachMaterialArg::GetStoredValue, py::return_value_policy::reference_internal);
    c9.def("SetStoredValue", &DgnPlatform::EachMaterialArg::SetStoredValue, "newVal"_a);

    //===================================================================================
    // class EachWeightArg
    py::class_< DgnPlatform::EachWeightArg, EachPropertyBaseArg> c10(m, "EachWeightArg");

    c10.def_property_readonly("EffectiveValue", &DgnPlatform::EachWeightArg::GetEffectiveValue);
    c10.def("GetEffectiveValue", &DgnPlatform::EachWeightArg::GetEffectiveValue);

    c10.def_property("StoredValue", &DgnPlatform::EachWeightArg::GetStoredValue, &DgnPlatform::EachWeightArg::SetStoredValue);
    c10.def("GetStoredValue", &DgnPlatform::EachWeightArg::GetStoredValue);
    c10.def("SetStoredValue", &DgnPlatform::EachWeightArg::SetStoredValue, "newVal"_a);

    //===================================================================================
    // class EachElementClassArg
    py::class_< DgnPlatform::EachElementClassArg, EachPropertyBaseArg> c11(m, "EachElementClassArg");

    c11.def_property_readonly("EffectiveValue", &DgnPlatform::EachElementClassArg::GetEffectiveValue);
    c11.def("GetEffectiveValue", &DgnPlatform::EachElementClassArg::GetEffectiveValue);

    c11.def_property("StoredValue", &DgnPlatform::EachElementClassArg::GetStoredValue, &DgnPlatform::EachElementClassArg::SetStoredValue);
    c11.def("GetStoredValue", &DgnPlatform::EachElementClassArg::GetStoredValue);
    c11.def("SetStoredValue", &DgnPlatform::EachElementClassArg::SetStoredValue, "newVal"_a);

    //===================================================================================
    // class EachTransparencyArg
    py::class_< DgnPlatform::EachTransparencyArg, EachPropertyBaseArg> c12(m, "EachTransparencyArg");

    c12.def_property("StoredValue", &DgnPlatform::EachTransparencyArg::GetStoredValue, &DgnPlatform::EachTransparencyArg::SetStoredValue);
    c12.def("GetStoredValue", &DgnPlatform::EachTransparencyArg::GetStoredValue);
    c12.def("SetStoredValue", &DgnPlatform::EachTransparencyArg::SetStoredValue, "newVal"_a);

    //===================================================================================
    // class EachDisplayPriorityArg
    py::class_< DgnPlatform::EachDisplayPriorityArg, EachPropertyBaseArg> c13(m, "EachDisplayPriorityArg");

    c13.def_property_readonly("EffectiveValue", &DgnPlatform::EachDisplayPriorityArg::GetEffectiveValue);
    c13.def("GetEffectiveValue", &DgnPlatform::EachDisplayPriorityArg::GetEffectiveValue);

    c13.def_property("StoredValue", &DgnPlatform::EachDisplayPriorityArg::GetStoredValue, &DgnPlatform::EachDisplayPriorityArg::SetStoredValue);
    c13.def("GetStoredValue", &DgnPlatform::EachDisplayPriorityArg::GetStoredValue);
    c13.def("SetStoredValue", &DgnPlatform::EachDisplayPriorityArg::SetStoredValue, "newVal"_a);

    //===================================================================================
    // class EachElementTemplateArg
    py::class_< DgnPlatform::EachElementTemplateArg, EachPropertyBaseArg> c14(m, "EachElementTemplateArg");

    c14.def_property("ApplyDefaultSymbology", &DgnPlatform::EachElementTemplateArg::GetApplyDefaultSymbology, &DgnPlatform::EachElementTemplateArg::SetApplyDefaultSymbology);
    c14.def("GetApplyDefaultSymbology", &DgnPlatform::EachElementTemplateArg::GetApplyDefaultSymbology);
    c14.def("SetApplyDefaultSymbology", &DgnPlatform::EachElementTemplateArg::SetApplyDefaultSymbology, "apply"_a);

    c14.def_property("StoredValue", &DgnPlatform::EachElementTemplateArg::GetStoredValue, &DgnPlatform::EachElementTemplateArg::SetStoredValue);
    c14.def("GetStoredValue", &DgnPlatform::EachElementTemplateArg::GetStoredValue);
    c14.def("SetStoredValue", &DgnPlatform::EachElementTemplateArg::SetStoredValue, "newVal"_a);

    //===================================================================================
    // class EachThicknessArg
    py::class_< DgnPlatform::EachThicknessArg, EachPropertyBaseArg> c15(m, "EachThicknessArg");

    c15.def_property("Capped", &DgnPlatform::EachThicknessArg::GetCapped, &DgnPlatform::EachThicknessArg::SetCapped);
    c15.def("GetCapped", &DgnPlatform::EachThicknessArg::GetCapped);
    c15.def("SetCapped", &DgnPlatform::EachThicknessArg::SetCapped, "capped"_a);

    c15.def_property("AlwaysUseDirection", &DgnPlatform::EachThicknessArg::GetAlwaysUseDirection, &DgnPlatform::EachThicknessArg::SetAlwaysUseDirection);
    c15.def("GetAlwaysUseDirection", &DgnPlatform::EachThicknessArg::GetAlwaysUseDirection);
    c15.def("SetAlwaysUseDirection", &DgnPlatform::EachThicknessArg::SetAlwaysUseDirection, "alwaysUseDirection"_a);
    
    c15.def_property("StoredValue", &DgnPlatform::EachThicknessArg::GetStoredValue, &DgnPlatform::EachThicknessArg::SetStoredValue);
    c15.def("GetStoredValue", &DgnPlatform::EachThicknessArg::GetStoredValue);
    c15.def("SetStoredValue", &DgnPlatform::EachThicknessArg::SetStoredValue, "newVal"_a);

    c15.def("GetDirection", &DgnPlatform::EachThicknessArg::GetDirection, "direction"_a);
    c15.def("SetDirection", &DgnPlatform::EachThicknessArg::SetDirection, "direction"_a);

    //===================================================================================
    // struct  IProcessProperties
    py::class_< DgnPlatform::IProcessProperties, std::unique_ptr< DgnPlatform::IProcessProperties, py::nodelete> > c16(m, "IProcessProperties");

    c16.def("_EachLevelCallback", &DgnPlatform::IProcessProperties::_EachLevelCallback, "arg"_a);
    c16.def("_EachColorCallback", &DgnPlatform::IProcessProperties::_EachColorCallback, "arg"_a);
    c16.def("_EachLineStyleCallback", &DgnPlatform::IProcessProperties::_EachLineStyleCallback, "arg"_a);
    c16.def("_EachFontCallback", &DgnPlatform::IProcessProperties::_EachFontCallback, "arg"_a);
    c16.def("_EachTextStyleCallback", &DgnPlatform::IProcessProperties::_EachTextStyleCallback, "arg"_a);
    c16.def("_EachDimStyleCallback", &DgnPlatform::IProcessProperties::_EachDimStyleCallback, "arg"_a);
    c16.def("_EachMLineStyleCallback", &DgnPlatform::IProcessProperties::_EachMLineStyleCallback, "arg"_a);
    c16.def("_EachMaterialCallback", &DgnPlatform::IProcessProperties::_EachMaterialCallback, "arg"_a);
    c16.def("_EachWeightCallback", &DgnPlatform::IProcessProperties::_EachWeightCallback, "arg"_a);
    c16.def("_EachElementClassCallback", &DgnPlatform::IProcessProperties::_EachElementClassCallback, "arg"_a);
    c16.def("_EachTransparencyCallback", &DgnPlatform::IProcessProperties::_EachTransparencyCallback, "arg"_a);
    c16.def("_EachThicknessCallback", &DgnPlatform::IProcessProperties::_EachThicknessCallback, "arg"_a);
    c16.def("_EachDisplayPriorityCallback", &DgnPlatform::IProcessProperties::_EachDisplayPriorityCallback, "arg"_a);
    c16.def("_EachElementTemplateCallback", &DgnPlatform::IProcessProperties::_EachElementTemplateCallback, "arg"_a);

    //===================================================================================
    // struct IQueryProperties
    py::class_< DgnPlatform::IQueryProperties, std::unique_ptr< DgnPlatform::IQueryProperties, py::nodelete>, DgnPlatform::IProcessProperties> c17(m, "IQueryProperties");
    c17.def(py::init<>());
    c17.def_property_readonly("PropertiesMask", &DgnPlatform::IQueryProperties::_GetQueryPropertiesMask);
    c17.def("_GetPropertiesMask", &DgnPlatform::IQueryProperties::_GetQueryPropertiesMask);

    c17.def_property_readonly("QueryPropertiesPurpose", &DgnPlatform::IQueryProperties::_GetQueryPropertiesPurpose);
    c17.def("_GetQueryPropertiesPurpose", &DgnPlatform::IQueryProperties::_GetQueryPropertiesPurpose);

    c17.def_property_readonly("WantSharedChildren", &DgnPlatform::IQueryProperties::_WantSharedChildren);
    c17.def("_WantSharedChildren", &DgnPlatform::IQueryProperties::_WantSharedChildren);

    //===================================================================================
    // struct IEditProperties
    py::class_< DgnPlatform::IEditProperties, std::unique_ptr<DgnPlatform::IEditProperties, py::nodelete>, DgnPlatform::IProcessProperties> c18(m, "IEditProperties");
    c18.def(py::init<>());
    c18.def_property_readonly("EditPropertiesMask", &DgnPlatform::IEditProperties::_GetEditPropertiesMask);
    c18.def("_GetEditPropertiesMask", &DgnPlatform::IEditProperties::_GetEditPropertiesMask);
    
    c18.def_property_readonly("EditPropertiesPurpose", &DgnPlatform::IEditProperties::_GetEditPropertiesPurpose);
    c18.def("_GetEditPropertiesPurpose", &DgnPlatform::IEditProperties::_GetEditPropertiesPurpose);
    
    c18.def_property_readonly("DestinationModelRef", &DgnPlatform::IEditProperties::_GetDestinationModelRef);
    c18.def("_GetDestinationModelRef", &DgnPlatform::IEditProperties::_GetDestinationModelRef, py::return_value_policy::reference_internal);

    //===================================================================================
    // struct PropertyContext
    py::class_< PropertyContext> c19(m, "PropertyContext");

    c19.def_static("QueryPathProperties", &PropertyContext::QueryPathProperties, "path"_a, "queryObj"_a);
    c19.def_static("QueryElementProperties", &PropertyContext::QueryElementProperties, "eh"_a, "queryObj"_a);
    c19.def_static("EditElementProperties", &PropertyContext::EditElementProperties, "eeh"_a, "editbj"_a);
    }