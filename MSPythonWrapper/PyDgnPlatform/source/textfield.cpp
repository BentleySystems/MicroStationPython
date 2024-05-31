/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnPlatform\source\textfield.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <DgnPlatform/TextBlock/TextField.h>

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_TextField(py::module_& m)
    {
    //===================================================================================
    // struct TextField
    py::class_< TextField, TextFieldPtr> c1(m, "TextField");

    if (true)
        {
        //===================================================================================
        // enum FieldType
        py::enum_< TextField::FieldType>(c1, "FieldType")
            .value("eFieldType_Element", TextField::FieldType_Element)
            .value("eFieldType_File", TextField::FieldType_File)
            .value("eFieldType_Model", TextField::FieldType_Model)
            .export_values();
        }

    c1.def("GetDisplayValue", py::overload_cast<WStringR>(&TextField::GetDisplayValue, py::const_), "displayValue"_a);
    c1.def("FormatValue", &TextField::FormatValue, "value"_a, "source"_a, "accessString"_a);
    c1.def("SetFieldCreationContext", &TextField::SetFieldCreationContext, "value"_a);
    
    c1.def_property_readonly("Formatter", &TextField::GetFormatter);
    c1.def("GetFormatter", &TextField::GetFormatter, py::return_value_policy::reference_internal);

    c1.def_static("CreateForElement", &TextField::CreateForElement, "instance"_a, "accessString"_a, "formatter"_a, "dgnModel"_a);
    c1.def_static("CreateForModel", &TextField::CreateForModel, "instance"_a, "accessString"_a, "formatter"_a);
    c1.def_static("CreateForFile", &TextField::CreateForFile, "instance"_a, "accessString"_a, "formatter"_a, "dgnModel"_a);
    c1.def_static("CreatePlaceHolderForCell", &TextField::CreatePlaceHolderForCell, "ecProperty"_a, "formatter"_a, "dgnModel"_a);
    c1.def_static("CreatePlaceHolderForSignatureCell", &TextField::CreatePlaceHolderForSignatureCell, "ecProperty"_a, "formatter"_a, "dgnModel"_a);
    c1.def_static("CreatePlaceHolderForLink", &TextField::CreatePlaceHolderForLink, "ecProperty"_a, "formatter"_a, "linkAncestorKey"_a, "dgnModel"_a);
    c1.def_static("CreateForSheetIndex", &TextField::CreateForSheetIndex, "instance"_a, "accessString"_a, "textHostModel"_a, "formatter"_a);
    c1.def_static("CreateForSheetIndexFolder", &TextField::CreateForSheetIndexFolder, "instance"_a, "accessString"_a, "textHostModel"_a, "formatter"_a);
    
    c1.def_property_readonly("FieldType", &TextField::GetFieldType);
    c1.def("GetFieldType", &TextField::GetFieldType);
    
    c1.def_property_readonly("DisplayLabel", &TextField::GetDisplayLabel);
    c1.def("GetDisplayLabel", &TextField::GetDisplayLabel, py::return_value_policy::reference_internal);
    }