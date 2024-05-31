/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnPlatform\source\dimensionstyle.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <DgnPlatform/DimensionStyle.h>



static const char * __doc_Bentley_DgnPlatform_DimStylePropMask_GetTemplateBit =R"doc(Test the value of a single template bit.)doc";

static const char * __doc_Bentley_DgnPlatform_DimStylePropMask_GetPropertyBit =R"doc(Test the value of a single property bit.)doc";

static const char * __doc_Bentley_DgnPlatform_DimStylePropMask_SetTemplateBit =R"doc(Set the value of a single template bit.)doc";

static const char * __doc_Bentley_DgnPlatform_DimStylePropMask_SetPropertyBit =R"doc(Set the value of a single property bit.)doc";

static const char * __doc_Bentley_DgnPlatform_DimStylePropMask_ClearAllBits =R"doc(Set all bits to off in this mask.)doc";

static const char * __doc_Bentley_DgnPlatform_DimStylePropMask_AnyBitSet =R"doc(Test if any bits are on in this mask.)doc";

static const char * __doc_Bentley_DgnPlatform_DimStylePropMask_From =R"doc(Copy the state of another mask into this one.)doc";

static const char * __doc_Bentley_DgnPlatform_DimensionStyle_SetTemplateFlagProp =R"doc(Change the value of a template flag.)doc";

static const char * __doc_Bentley_DgnPlatform_DimensionStyle_SetTextStyleProp =R"doc(Change the value of a text style type property.)doc";

static const char * __doc_Bentley_DgnPlatform_DimensionStyle_SetOneUnitProp =R"doc(Change the value of a unit type property.)doc";

static const char * __doc_Bentley_DgnPlatform_DimensionStyle_SetLineStyleProp =R"doc(Change the value of a line style type property.)doc";

static const char * __doc_Bentley_DgnPlatform_DimensionStyle_SetWeightProp =R"doc(Change the value of a weight type property.)doc";

static const char * __doc_Bentley_DgnPlatform_DimensionStyle_SetColorProp =R"doc(Change the value of a color type property.)doc";

static const char * __doc_Bentley_DgnPlatform_DimensionStyle_SetFontProp =R"doc(Change the value of a font type property.)doc";

static const char * __doc_Bentley_DgnPlatform_DimensionStyle_SetStringProp =R"doc(Change the value of a string type property.)doc";

static const char * __doc_Bentley_DgnPlatform_DimensionStyle_SetLevelProp =R"doc(Change the value of a level type property.)doc";

static const char * __doc_Bentley_DgnPlatform_DimensionStyle_SetIntegerProp =R"doc(Change the value of an integer type property.)doc";

static const char * __doc_Bentley_DgnPlatform_DimensionStyle_SetDistanceProp =R"doc(Change the value of a distance type property.)doc";

static const char * __doc_Bentley_DgnPlatform_DimensionStyle_SetDoubleProp =R"doc(Change the value of a double type property.)doc";

static const char * __doc_Bentley_DgnPlatform_DimensionStyle_SetCharProp =R"doc(Change the value of a char type property.)doc";

static const char * __doc_Bentley_DgnPlatform_DimensionStyle_SetBooleanProp =R"doc(Change the value of a boolean type property.)doc";

static const char * __doc_Bentley_DgnPlatform_DimensionStyle_SetAccuracyProp =R"doc(Change the value of an accuracy type property.)doc";

static const char * __doc_Bentley_DgnPlatform_DimensionStyle_GetTemplateFlagProp =R"doc(Get the value of a template flag.
Returns (Tuple,0):
	retVal.

Returns (Tuple,1):
	valueOut.

)doc";


static const char * __doc_Bentley_DgnPlatform_DimensionStyle_GetTextStyleProp =R"doc(Get the value of a text style type property.
Returns (Tuple,0):
	retVal.

Returns (Tuple,1):
	valueOut.

)doc";

static const char * __doc_Bentley_DgnPlatform_DimensionStyle_GetOneUnitProp =R"doc(Get the value of a unit type property. To change a unit property use
SetUnitsProp()..
Returns (Tuple,0):
	retVal.

Returns (Tuple,1):
	valueOut.

)doc";

static const char * __doc_Bentley_DgnPlatform_DimensionStyle_GetLineStyleProp =R"doc(Get the value of a linestyle type property.
Returns (Tuple,0):
	retVal.

Returns (Tuple,1):
	valueOut.

)doc";

static const char * __doc_Bentley_DgnPlatform_DimensionStyle_GetWeightProp =R"doc(Get the value of a weight type property.
Returns (Tuple,0):
	retVal.

Returns (Tuple,1):
	valueOut.

)doc";

static const char * __doc_Bentley_DgnPlatform_DimensionStyle_GetColorProp =R"doc(Get the value of an accuracy type property.
Returns (Tuple,0):
	retVal.

Returns (Tuple,1):
	valueOut.

)doc";

static const char * __doc_Bentley_DgnPlatform_DimensionStyle_GetFontProp =R"doc(Get the value of a font type property.
Returns (Tuple,0):
	retVal.

Returns (Tuple,1):
	valueOut.

)doc";

static const char * __doc_Bentley_DgnPlatform_DimensionStyle_GetStringProp =R"doc(Get the value of a string type property.
Returns (Tuple,0):
	retVal.

Returns (Tuple,1):
	valueOut.

)doc";

static const char * __doc_Bentley_DgnPlatform_DimensionStyle_GetLevelProp =R"doc(Get the value of a level type property.
Returns (Tuple,0):
	retVal.

Returns (Tuple,1):
	valueOut.

)doc";

static const char * __doc_Bentley_DgnPlatform_DimensionStyle_GetIntegerProp =R"doc(Get the value of an integer type property.
Returns (Tuple,0):
	retVal.

Returns (Tuple,1):
	valueOut.

)doc";

static const char * __doc_Bentley_DgnPlatform_DimensionStyle_GetDistanceProp =R"doc(Get the value of a distance type property.
Returns (Tuple,0):
	retVal.

Returns (Tuple,1):
	valueOut.

)doc";

static const char * __doc_Bentley_DgnPlatform_DimensionStyle_GetDoubleProp =R"doc(Get the value of a double type property.
Returns (Tuple,0):
	retVal.

Returns (Tuple,1):
	valueOut.

)doc";

static const char * __doc_Bentley_DgnPlatform_DimensionStyle_GetCharProp =R"doc(Get the value of a char type property.
Returns (Tuple,0):
	retVal.

Returns (Tuple,1):
	valueOut.

)doc";

static const char * __doc_Bentley_DgnPlatform_DimensionStyle_GetBooleanProp =R"doc(Get the value of a boolean type property.
Returns (Tuple,0):
	retVal.

Returns (Tuple,1):
	valueOut.

)doc";

static const char * __doc_Bentley_DgnPlatform_DimensionStyle_GetAccuracyProp =R"doc(Get the value of an accuracy type property.
Returns (Tuple,0):
	retVal.

Returns (Tuple,1):
	valueOut.

)doc";

static const char * __doc_Bentley_DgnPlatform_DimensionStyle_GetUorScale =R"doc(Obtain a scale factor needed to interpret style distance properties.

Parameter ``destModel``:
    desired context for distance value. For distance properties, the
    method GetDoubleProp returns values in terms of the resolution of
    the default model of the style's file. In order to use that value
    in a different model it should be multiplied be the uor scale.)doc";

static const char * __doc_Bentley_DgnPlatform_DimensionStyle_ConvertToFile =R"doc(Change the context of this style to another DgnFile.)doc";

static const char * __doc_Bentley_DgnPlatform_DimensionStyle_Compare =R"doc(Compare this style object with another one.

Parameter ``otherStyle``:
    The other style.

Parameter ``compareOpts``:
    Options that control the comparison.

Remark:
    s The following compare options are supported:

* DIMSTYLE_COMPAREOPTS_Default Compare every property.

* DIMSTYLE_COMPAREOPTS_IgnoreUnusedDiffs Ignore those properties that
are 'unused'.

An unused property will not affect dimensions placed with this style.
For example, if the style's extension color flag is OFF, that means
the dimension's extension color will come from the header color. In
that case, the style's extension color value is unused.

Returns:
    A mask with 'on' bits representing each difference between the two
    styles. To quickly test if any difference exists use
    DimStylePropMask::AnyBitSet)doc";

static const char * __doc_Bentley_DgnPlatform_DimensionStyle_SetName =R"doc(Set the name of this style.)doc";

static const char * __doc_Bentley_DgnPlatform_DimensionStyle_CopyValues =R"doc(Copy all the properties from another style object into this one.)doc";

static const char * __doc_Bentley_DgnPlatform_DimensionStyle_Copy =R"doc(Make a copy of this style object.)doc";

static const char * __doc_Bentley_DgnPlatform_DimensionStyle_GetTextStyleId =R"doc(Get the id of the TextStyle used by this style. If this style does not
refer to a TextStyle this method will return zero.)doc";

static const char * __doc_Bentley_DgnPlatform_DimensionStyle_GetFile =R"doc(Get the file which serves as the context for this style.)doc";

static const char * __doc_Bentley_DgnPlatform_DimensionStyle_GetID =R"doc(Get the id of this style.)doc";

static const char * __doc_Bentley_DgnPlatform_DimensionStyle_GetName =R"doc(Get the name of this style.)doc";

static const char * __doc_Bentley_DgnPlatform_DimensionStyle_SetUnitsProp =R"doc(Change the value of a units type property. The master unit must be
larger than or the same size as the sub unit.)doc";

static const char * __doc_Bentley_DgnPlatform_DimensionStyle_GetUnitsProp =R"doc(Get the value of a units type property.)doc";

static const char * __doc_Bentley_DgnPlatform_DimensionStyle_RemapDependents =R"doc(Remap all the elements that reference one style to different style.

Parameter ``destStyle``:
    IN remap to this style.

Parameter ``sourceStyle``:
    IN remap from this style.

Parameter ``file``:
    IN file in which to search.)doc";

static const char * __doc_Bentley_DgnPlatform_DimensionStyle_Delete =R"doc(Deletes a dimension style from a dgn file. This method will fail if
any elements refer to the style.

Parameter ``name``:
    The name of the style to delete.

Parameter ``file``:
    The file from which to delete the style.

Returns:
    SUCCESS if the style was removed.

See also:
    HasDependents

See also:
    RemapDependents)doc";

static const char * __doc_Bentley_DgnPlatform_DimensionStyle_Replace =R"doc(Replace an existing persistent DimensionStyle in a DgnFile. Will fail
if there is not already a style with the same name.

Parameter ``oldName``:
    The name of the style to replace. If NULL, the style will be
    overwrite the style with the same name as the style object.

Parameter ``file``:
    The file in which to write the style. If NULL, the style will be
    written to the file stored in the style object.

Remark:
    If the style is written to a file different than the file stored
    in the style object, then the style object will be converted to
    the new file.

Returns:
    SUCCESS if the style was written.)doc";

static const char * __doc_Bentley_DgnPlatform_DimensionStyle_Add =R"doc(Add this DimensionStyle to a DgnFile. Will fail if there is already a
style with the same name.

Parameter ``file``:
    The file in which to write the style. If NULL, the style will be
    written to the file stored in the style object.

Remark:
    If the style is written to a file different than the file stored
    in the style object, then the style object will be converted to
    the new file.

Returns:
    SUCCESS if the style was written.)doc";

static const char * __doc_Bentley_DgnPlatform_DimensionStyle_BuildList =R"doc(Create a list of all the styles in the specified file.)doc";

static const char * __doc_Bentley_DgnPlatform_DimensionStyle_ReplaceSettings =R"doc(Overwrite the active dimension settings from a file.)doc";

static const char * __doc_Bentley_DgnPlatform_DimensionStyle_GetSettings =R"doc(Get the active dimension settings from a file.)doc";

static const char * __doc_Bentley_DgnPlatform_DimensionStyle_GetByID =R"doc(Find an existing persistent Named DimensionStyle.)doc";

static const char * __doc_Bentley_DgnPlatform_DimensionStyle_GetByName =R"doc(Find an existing persistent Named DimensionStyle.)doc";

//=======================================================================================
// Trampoline class for IDimStyleTransactionListener.
// @bsiclass                                                                   02/23
//=======================================================================================
struct IPyDimStyleTransactionListener : IDimStyleTransactionListener
    {
    public:
        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual void _OnDimStyleChange(DimensionStyleCP before, DimensionStyleCP after, StyleEventType type, StyleEventSource source) override
            { PYBIND11_OVERRIDE_PURE_EX(void, IDimStyleTransactionListener, _OnDimStyleChange, before, after, type, source); }
    };

//=======================================================================================
// Trampoline class for DimStyleEvents.
// @bsiclass                                                                   02/23
//=======================================================================================
struct PyDimStyleEvents : DimStyleEvents
    {
    public:
        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/    
        virtual void _OnDimStyleChange(DimensionStyleCP before, DimensionStyleCP after, StyleEventType type, StyleEventSource source) override
            { PYBIND11_OVERRIDE_PURE_EX(void, DimStyleEvents, _OnDimStyleChange, before, after, type, source); }
    };

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_DimensionStyle(py::module_& m)
    {
    //===================================================================================
    // Gloabl constants
    m.attr("DIMSTYLE_COMPAREOPTS_Default") = (UInt32)DIMSTYLE_COMPAREOPTS_Default;
    m.attr("DIMSTYLE_COMPAREOPTS_IgnoreUnusedDiffs") = (UInt32)DIMSTYLE_COMPAREOPTS_IgnoreUnusedDiffs;
    m.attr("DIMSTYLE_COMPAREOPTS_UserInterface") = (UInt32)DIMSTYLE_COMPAREOPTS_UserInterface;
    
    //===================================================================================
    // struct IDimStyleTransactionListener
    py::class_< IDimStyleTransactionListener, std::unique_ptr<IDimStyleTransactionListener, py::nodelete>, IPyDimStyleTransactionListener> c1(m, "IDimStyleTransactionListener");

    c1.def(py::init<>());
    c1.def("_OnDimStyleChange", &IDimStyleTransactionListener::_OnDimStyleChange, "before"_a, "after"_a, "type"_a, "source"_a);

    //===================================================================================
    // struct DimStyleEvents
    py::class_< DimStyleEvents, std::unique_ptr<DimStyleEvents, py::nodelete>, PyDimStyleEvents, IDimStyleTransactionListener> c2(m, "DimStyleEvents");
    
    c2.def(py::init<>());
    c2.def("_OnDimStyleChange", &DimStyleEvents::_OnDimStyleChange, "before"_a, "after"_a, "type"_a, "source"_a);
    //===================================================================================
    // struct DimensionStyle
    py::class_< DimensionStyle, DimensionStylePtr> c3(m, "DimensionStyle");

    c3.def(py::init(&DimensionStyle::Create), "name"_a, "dgnFile"_a);
    c3.def_static("GetByName", py::overload_cast<WCharCP, DgnFileR>(&DimensionStyle::GetByName), "name"_a, "dgnFile"_a, DOC(Bentley, DgnPlatform, DimensionStyle, GetByName));
    c3.def_static("GetByID", &DimensionStyle::GetByID, "elemId"_a, "dgnFile"_a, DOC(Bentley, DgnPlatform, DimensionStyle, GetByID));
    c3.def_static("GetSettings", &DimensionStyle::GetSettings, "dgnFile"_a, DOC(Bentley, DgnPlatform, DimensionStyle, GetSettings));
    c3.def_static("ReplaceSettings", &DimensionStyle::ReplaceSettings, "settings"_a, "dgnFile"_a, DOC(Bentley, DgnPlatform, DimensionStyle, ReplaceSettings));
    c3.def_static("BuildList", py::overload_cast<DgnFileR>(&DimensionStyle::BuildList), "dgnFile"_a, DOC(Bentley, DgnPlatform, DimensionStyle, BuildList));
    c3.def("Add", &DimensionStyle::Add, "dgnFile"_a = nullptr, DOC(Bentley, DgnPlatform, DimensionStyle, Add));
    c3.def("Replace", &DimensionStyle::Replace, "oldName"_a = nullptr, "dgnFile"_a = nullptr, DOC(Bentley, DgnPlatform, DimensionStyle, Replace));
    c3.def_static("Delete", &DimensionStyle::Delete, "name"_a, "dgnFile"_a, DOC(Bentley, DgnPlatform, DimensionStyle, Delete));
    c3.def("HasDependants", &DimensionStyle::HasDependants);
    c3.def_static("RemapDependents", &DimensionStyle::RemapDependents, "destStyle"_a, "sourceStyle"_a, "dgnFile"_a, DOC(Bentley, DgnPlatform, DimensionStyle, RemapDependents));
    c3.def("GetUnitsProp", &DimensionStyle::GetUnitsProp, "master"_a, "sub"_a, "iProp"_a, DOC(Bentley, DgnPlatform, DimensionStyle, GetUnitsProp));
    c3.def("SetUnitsProp", &DimensionStyle::SetUnitsProp, "master"_a, "sub"_a, "iProp"_a, DOC(Bentley, DgnPlatform, DimensionStyle, SetUnitsProp));

    c3.def_property_readonly("Name", &DimensionStyle::GetName);
    c3.def("GetName", &DimensionStyle::GetName, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, DimensionStyle, GetName));
    
    c3.def_property_readonly("ID", &DimensionStyle::GetID);
    c3.def("GetID", &DimensionStyle::GetID, DOC(Bentley, DgnPlatform, DimensionStyle, GetID));
    
    c3.def_property_readonly("File", &DimensionStyle::GetFile);
    c3.def("GetFile", &DimensionStyle::GetFile, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, DimensionStyle, GetFile));

    c3.def_property_readonly("TextStyleId", &DimensionStyle::GetTextStyleId);
    c3.def("GetTextStyleId", &DimensionStyle::GetTextStyleId, DOC(Bentley, DgnPlatform, DimensionStyle, GetTextStyleId));
    
    c3.def("Copy", &DimensionStyle::Copy, DOC(Bentley, DgnPlatform, DimensionStyle, Copy));
    c3.def("CopyValues", &DimensionStyle::CopyValues, "source"_a, DOC(Bentley, DgnPlatform, DimensionStyle, CopyValues));
    c3.def("SetName", &DimensionStyle::SetName, "newName"_a, DOC(Bentley, DgnPlatform, DimensionStyle, SetName));
    c3.def("Compare", &DimensionStyle::Compare, "otherStyle"_a, "compareOpts"_a = (UInt32)DIMSTYLE_COMPAREOPTS_Default, DOC(Bentley, DgnPlatform, DimensionStyle, Compare));
    c3.def("ConvertToFile", &DimensionStyle::ConvertToFile, "dgnFile"_a, DOC(Bentley, DgnPlatform, DimensionStyle, ConvertToFile));
    c3.def("GetUorScale", &DimensionStyle::GetUorScale, "destModel"_a, DOC(Bentley, DgnPlatform, DimensionStyle, GetUorScale));
    
    c3.def("GetAccuracyProp", [] (DimensionStyle const& self, DimStyleProp iProp)
           {
           byte valueOut;
           auto retVal = self.GetAccuracyProp(valueOut, iProp);
           return py::make_tuple(retVal, valueOut);
           }, "iProp"_a, DOC(Bentley, DgnPlatform, DimensionStyle, GetAccuracyProp));

    c3.def("GetBooleanProp", [] (DimensionStyle const& self, DimStyleProp iProp)
           {
           bool valueOut;
           auto retVal = self.GetBooleanProp(valueOut, iProp);
           return py::make_tuple(retVal, valueOut);
           }, "iProp"_a, DOC(Bentley, DgnPlatform, DimensionStyle, GetBooleanProp));

    c3.def("GetCharProp", [] (DimensionStyle const& self, DimStyleProp iProp)
           {
           UShort valueOut;
           auto retVal = self.GetCharProp(valueOut, iProp);
           return py::make_tuple(retVal, valueOut);
           }, "iProp"_a, DOC(Bentley, DgnPlatform, DimensionStyle, GetCharProp));

    c3.def("GetDoubleProp", [] (DimensionStyle const& self, DimStyleProp iProp)
           {
           double valueOut;
           auto retVal = self.GetDoubleProp(valueOut, iProp);
           return py::make_tuple(retVal, valueOut);
           }, "iProp"_a, DOC(Bentley, DgnPlatform, DimensionStyle, GetDoubleProp));

    c3.def("GetDistanceProp", [] (DimensionStyle const& self, DimStyleProp iProp, DgnModelP dgnModel)
           {
           double valueOut;
           auto retVal = self.GetDistanceProp(valueOut, iProp, dgnModel);
           return py::make_tuple(retVal, valueOut);
           }, "iProp"_a, "dgnModel"_a, DOC(Bentley, DgnPlatform, DimensionStyle, GetDistanceProp));

    c3.def("GetIntegerProp", [] (DimensionStyle const& self, DimStyleProp iProp)
           {
           int valueOut;
           auto retVal = self.GetIntegerProp(valueOut, iProp);
           return py::make_tuple(retVal, valueOut);
           }, "iProp"_a, DOC(Bentley, DgnPlatform, DimensionStyle, GetIntegerProp));

    c3.def("GetLevelProp", [] (DimensionStyle const& self, DimStyleProp iProp)
           {
           LevelId valueOut;
           auto retVal = self.GetLevelProp(valueOut, iProp);
           return py::make_tuple(retVal, valueOut);
           }, "iProp"_a, DOC(Bentley, DgnPlatform, DimensionStyle, GetLevelProp));

    c3.def("GetStringProp", [] (DimensionStyle const& self, DimStyleProp iProp)
           {
           WString valueOut;
           auto retVal = self.GetStringProp(valueOut, iProp);
           return py::make_tuple(retVal, valueOut);
           }, "iProp"_a, DOC(Bentley, DgnPlatform, DimensionStyle, GetStringProp));

    c3.def("GetFontProp", [] (DimensionStyle const& self, DimStyleProp iProp)
           {
           UInt32 valueOut;
           auto retVal = self.GetFontProp(valueOut, iProp);
           return py::make_tuple(retVal, valueOut);
           }, "iProp"_a, DOC(Bentley, DgnPlatform, DimensionStyle, GetFontProp));

    c3.def("GetColorProp", [] (DimensionStyle const& self, DimStyleProp iProp)
           {
           UInt32 valueOut;
           auto retVal = self.GetColorProp(valueOut, iProp);
           return py::make_tuple(retVal, valueOut);
           }, "iProp"_a, DOC(Bentley, DgnPlatform, DimensionStyle, GetColorProp));

    c3.def("GetWeightProp", [] (DimensionStyle const& self, DimStyleProp iProp)
           {
           UInt32 valueOut;
           auto retVal = self.GetWeightProp(valueOut, iProp);
           return py::make_tuple(retVal, valueOut);
           }, "iProp"_a, DOC(Bentley, DgnPlatform, DimensionStyle, GetWeightProp));

    c3.def("GetLineStyleProp", [] (DimensionStyle const& self, DimStyleProp iProp)
           {
           Int32 valueOut;
           auto retVal = self.GetLineStyleProp(valueOut, iProp);
           return py::make_tuple(retVal, valueOut);
           }, "iProp"_a, DOC(Bentley, DgnPlatform, DimensionStyle, GetLineStyleProp));

    c3.def("GetOneUnitProp", [] (DimensionStyle const& self, DimStyleProp iProp)
           {
           UnitDefinition valueOut;
           auto retVal = self.GetOneUnitProp(valueOut, iProp);
           return py::make_tuple(retVal, valueOut);
           }, "iProp"_a, DOC(Bentley, DgnPlatform, DimensionStyle, GetOneUnitProp));

    c3.def("GetTextStyleProp", [] (DimensionStyle const& self, DimStyleProp iProp)
           {
           DgnTextStylePtr valueOut;
           auto retVal = self.GetTextStyleProp(valueOut, iProp);
           return py::make_tuple(retVal, valueOut);
           }, "iProp"_a, DOC(Bentley, DgnPlatform, DimensionStyle, GetTextStyleProp));

    c3.def("GetTemplateFlagProp", [] (DimensionStyle const& self, DimensionType dimensionType, DimStyleProp iProp)
           {
           UShort valueOut;
           auto retVal = self.GetTemplateFlagProp(valueOut, dimensionType, iProp);
           return py::make_tuple(retVal, valueOut);
           }, "dimensionType"_a, "iProp"_a, DOC(Bentley, DgnPlatform, DimensionStyle, GetTemplateFlagProp));

    c3.def("SetAccuracyProp", &DimensionStyle::SetAccuracyProp, "valueIn"_a, "iProp"_a, DOC(Bentley, DgnPlatform, DimensionStyle, SetAccuracyProp));
    c3.def("SetBooleanProp", &DimensionStyle::SetBooleanProp, "valueIn"_a, "iProp"_a, DOC(Bentley, DgnPlatform, DimensionStyle, SetBooleanProp));
    c3.def("SetCharProp", &DimensionStyle::SetCharProp, "valueIn"_a, "iProp"_a, DOC(Bentley, DgnPlatform, DimensionStyle, SetCharProp));
    c3.def("SetDoubleProp", &DimensionStyle::SetDoubleProp, "valueIn"_a, "iProp"_a, DOC(Bentley, DgnPlatform, DimensionStyle, SetDoubleProp));
    c3.def("SetDistanceProp", &DimensionStyle::SetDistanceProp, "valueIn"_a, "iProp"_a, "dgnModel"_a, DOC(Bentley, DgnPlatform, DimensionStyle, SetDistanceProp));
    c3.def("SetIntegerProp", &DimensionStyle::SetIntegerProp, "valueIn"_a, "iProp"_a, DOC(Bentley, DgnPlatform, DimensionStyle, SetIntegerProp));
    c3.def("SetLevelProp", &DimensionStyle::SetLevelProp, "valueIn"_a, "iProp"_a, DOC(Bentley, DgnPlatform, DimensionStyle, SetLevelProp));
    c3.def("SetStringProp", &DimensionStyle::SetStringProp, "valueIn"_a, "iProp"_a, DOC(Bentley, DgnPlatform, DimensionStyle, SetStringProp));
    c3.def("SetFontProp", &DimensionStyle::SetFontProp, "valueIn"_a, "iProp"_a, DOC(Bentley, DgnPlatform, DimensionStyle, SetFontProp));
    c3.def("SetColorProp", &DimensionStyle::SetColorProp, "valueIn"_a, "iProp"_a, DOC(Bentley, DgnPlatform, DimensionStyle, SetColorProp));
    c3.def("SetWeightProp", &DimensionStyle::SetWeightProp, "valueIn"_a, "iProp"_a, DOC(Bentley, DgnPlatform, DimensionStyle, SetWeightProp));
    c3.def("SetLineStyleProp", &DimensionStyle::SetLineStyleProp, "valueIn"_a, "iProp"_a, DOC(Bentley, DgnPlatform, DimensionStyle, SetLineStyleProp));
    c3.def("SetOneUnitProp", &DimensionStyle::SetOneUnitProp, "valueIn"_a, "iProp"_a, DOC(Bentley, DgnPlatform, DimensionStyle, SetOneUnitProp));
    c3.def("SetTextStyleProp", &DimensionStyle::SetTextStyleProp, "valueIn"_a, "iProp"_a, DOC(Bentley, DgnPlatform, DimensionStyle, SetTextStyleProp));
    c3.def("SetTemplateFlagProp", &DimensionStyle::SetTemplateFlagProp, "valueIn"_a, "dimensionType"_a, "iProp"_a, DOC(Bentley, DgnPlatform, DimensionStyle, SetTemplateFlagProp));


    //===================================================================================
    // struct DimStyleCollection;
    py::class_< DimStyleCollection> c4(m, "DimStyleCollection");

    c4.def(py::init<DgnFileR>(), "dgnFile"_a);
    c4.def("__iter__", [] (DimStyleCollection& self) { return py::make_iterator(self.begin(), self.end()); }, py::keep_alive<0, 1>());

    //===================================================================================
    // struct DimStylePropMask
    py::class_< DimStylePropMask, DimStylePropMaskPtr> c5(m, "DimStylePropMask");

    c5.def(py::init(&DimStylePropMask::CreatePropMask));    
    c5.def("From", &DimStylePropMask::From, "source"_a, DOC(Bentley, DgnPlatform, DimStylePropMask, From));
    c5.def("AnyBitSet", &DimStylePropMask::AnyBitSet, DOC(Bentley, DgnPlatform, DimStylePropMask, AnyBitSet));
    c5.def("ClearAllBits", &DimStylePropMask::ClearAllBits, DOC(Bentley, DgnPlatform, DimStylePropMask, ClearAllBits));
    c5.def("SetPropertyBit", &DimStylePropMask::SetPropertyBit, "dimStyleProp"_a, "bitValue"_a, DOC(Bentley, DgnPlatform, DimStylePropMask, SetPropertyBit));
    c5.def("SetTemplateBit", &DimStylePropMask::SetTemplateBit, "dimStyleProp"_a, "bitValue"_a, "dimensionType"_a, DOC(Bentley, DgnPlatform, DimStylePropMask, SetTemplateBit));
    c5.def("GetPropertyBit", &DimStylePropMask::GetPropertyBit, "dimStyleProp"_a, DOC(Bentley, DgnPlatform, DimStylePropMask, GetPropertyBit));
    c5.def("GetTemplateBit", &DimStylePropMask::GetTemplateBit, "dimStyleProp"_a, "dimensionType"_a, DOC(Bentley, DgnPlatform, DimStylePropMask, GetTemplateBit));

    }