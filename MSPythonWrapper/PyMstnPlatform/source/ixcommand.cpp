/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyMstnPlatform\source\ixcommand.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <Mstn/IXCommand.h>



static const char * __doc_Bentley_MstnPlatform_IXCommand_IsAllowed =R"doc(Determines if this command is allowed to execute in the given product
context.

Returns:
    true if this command is allowed to execute in the given product
    context; otherwise, false.

Remark:
    Required Library:mdlbltin.lib)doc";

static const char * __doc_Bentley_MstnPlatform_IXCommand_GetAcceleratorString =R"doc(Gets the string representation of the accelerator value associated
with this command.

Parameter ``accelStr``:
    the string representation of the accelerator.

Returns:
    true if the command has an accelerator

Remark:
    Required Library:mdlbltin.lib)doc";

static const char * __doc_Bentley_MstnPlatform_IXCommand_SetAccelerator =R"doc(Sets the accelerator value associated with this command.

Parameter ``accelerator``:
    the accelerator value associated with this command

Remark:
    Required Library:mdlbltin.lib)doc";

static const char * __doc_Bentley_MstnPlatform_IXCommand_GetAccelerator =R"doc(Gets the accelerator value associated with this command.

Returns:
    the accelerator value associated with this command

Remark:
    Required Library:mdlbltin.lib)doc";

static const char * __doc_Bentley_MstnPlatform_IXCommand_SetAttributes =R"doc(Sets the attributes associated with this command.

Parameter ``attributes``:
    the attributes associated with this command

Remark:
    Required Library:mdlbltin.lib)doc";

static const char * __doc_Bentley_MstnPlatform_IXCommand_GetAttributes =R"doc(Gets the attributes associated with this command.

Returns:
    the attributes associated with this command

Remark:
    Required Library:mdlbltin.lib)doc";

static const char * __doc_Bentley_MstnPlatform_IXCommand_SetFeatureTrackingId =R"doc(Sets the Feature Tracking GUID associated with this command.

Parameter ``featureTrackingId``:
    Feature Tracking GUID.

Remark:
    Required Library:mdlbltin.lib)doc";

static const char * __doc_Bentley_MstnPlatform_IXCommand_GetFeatureTrackingId =R"doc(Gets the Feature Tracking GUID associated with this command.

Parameter ``featureTrackingId``:
    Feature Tracking GUID.

Remark:
    Required Library:mdlbltin.lib)doc";

static const char * __doc_Bentley_MstnPlatform_IXCommand_SetUISyncEvents =R"doc(Sets the UISyncEvent associated with this command.

Parameter ``expression``:
    The UISyncEvent to be associated with this command.

Remark:
    Required Library:mdlbltin.lib)doc";

static const char * __doc_Bentley_MstnPlatform_IXCommand_GetUISyncEvents =R"doc(Gets the UISyncEvent associated with this command.

Parameter ``expression``:
    Receives the UISyncEvent.

Remark:
    Required Library:mdlbltin.lib)doc";

static const char * __doc_Bentley_MstnPlatform_IXCommand_HasMarkExpression =R"doc(Determines if this command has a Named Expression controlling Menu
Mark state for any UI associate with this command.

Returns:
    true if this command has a Named Expression controlling Menu Mark
    state; otherwise, false.

Remark:
    Required Library:mdlbltin.lib)doc";

static const char * __doc_Bentley_MstnPlatform_IXCommand_EvaluateMarkExpression =R"doc(Evaluates the Named Expression controlling Menu Mark state for any UI
associated with this command.

Parameter ``defaultValue``:
    The default MenuMarkType

Remark:
    Required Library:mdlbltin.lib)doc";

static const char * __doc_Bentley_MstnPlatform_IXCommand_SetMarkExpression =R"doc(Sets the Named Expression controlling Menu Mark state for any UI
associated with this command.

Parameter ``expression``:
    the Named Expression controlling Menu Mark state.

Remark:
    Required Library:mdlbltin.lib)doc";

static const char * __doc_Bentley_MstnPlatform_IXCommand_GetMarkExpression =R"doc(Gets the Named Expression controlling Menu Mark state for any UI
associated with this command.

Parameter ``expression``:
    Receives the Named Expression.

Remark:
    Required Library:mdlbltin.lib)doc";

static const char * __doc_Bentley_MstnPlatform_IXCommand_HasToggleExpression =R"doc(Determines if this command has a Named Expression controlling Toggle
state for any UI associate with this command.

Returns:
    true if this command has a Named Expression controlling Toggle
    state; otherwise, false.

Remark:
    Required Library:mdlbltin.lib)doc";

static const char * __doc_Bentley_MstnPlatform_IXCommand_EvaluateToggleExpression =R"doc(Evaluates the Named Expression controlling Toggle state for any UI
associated with this command.

Parameter ``defaultValue``:
    true if the command's UI should be toggled by default; otherwise,
    false.

Remark:
    Required Library:mdlbltin.lib)doc";

static const char * __doc_Bentley_MstnPlatform_IXCommand_SetToggleExpression =R"doc(Sets the Named Expression controlling Toggle state for any UI
associated with this command.

Parameter ``expression``:
    the Named Expression controlling Toggle state.

Remark:
    Required Library:mdlbltin.lib)doc";

static const char * __doc_Bentley_MstnPlatform_IXCommand_GetToggleExpression =R"doc(Gets the Named Expression controlling Toggle state for any UI
associated with this command.

Parameter ``expression``:
    Receives the Named Expression.

Remark:
    Required Library:mdlbltin.lib)doc";

static const char * __doc_Bentley_MstnPlatform_IXCommand_HasEnableExpression =R"doc(Determines if this command has a Named Expression controlling
Enable/Disable for any UI associate with this command.

Returns:
    true if this command has a Named Expression controlling
    Enable/Disable; otherwise, false.

Remark:
    Required Library:mdlbltin.lib)doc";

static const char * __doc_Bentley_MstnPlatform_IXCommand_EvaluateEnableExpression =R"doc(Evaluates the Named Expression controlling Enable/Disable for any UI
associated with this command.

Parameter ``defaultValue``:
    true if the command's UI should be enabled by default; otherwise,
    false.

Remark:
    Required Library:mdlbltin.lib)doc";

static const char * __doc_Bentley_MstnPlatform_IXCommand_SetEnableExpression =R"doc(Sets the Named Expression controlling Enable/Disable for any UI
associated with this command.

Parameter ``expression``:
    the Named Expression controlling Enable/Disable.

Remark:
    Required Library:mdlbltin.lib)doc";

static const char * __doc_Bentley_MstnPlatform_IXCommand_GetEnableExpression =R"doc(Gets the Named Expression controlling Enable/Disable for any UI
associated with this command.

Parameter ``expression``:
    Receives the Named Expression.

Remark:
    Required Library:mdlbltin.lib)doc";

static const char * __doc_Bentley_MstnPlatform_IXCommand_HasShowExpression =R"doc(Determines if this command has a Named Expression controlling
Show/Hide for any UI associate with this command.

Returns:
    true if this command has a Named Expression controlling Show/Hide;
    otherwise, false.

Remark:
    Required Library:mdlbltin.lib)doc";

static const char * __doc_Bentley_MstnPlatform_IXCommand_EvaluateShowExpression =R"doc(Evaluates the Named Expression controlling Show/Hide for any UI
associated with this command.

Parameter ``defaultValue``:
    true if the command's UI should be shown by default; otherwise,
    false.

Remark:
    Required Library:mdlbltin.lib)doc";

static const char * __doc_Bentley_MstnPlatform_IXCommand_SetShowExpression =R"doc(Sets the Named Expression controlling Show/Hide for any UI associated
with this command.

Parameter ``expression``:
    the Named Expression controlling Show/Hide.

Remark:
    Required Library:mdlbltin.lib)doc";

static const char * __doc_Bentley_MstnPlatform_IXCommand_GetShowExpression =R"doc(Gets the Named Expression controlling Show/Hide for any UI associated
with this command.

Parameter ``expression``:
    Receives the Named Expression.

Remark:
    Required Library:mdlbltin.lib)doc";

static const char * __doc_Bentley_MstnPlatform_IXCommand_GetIconName =R"doc(Gets the icon name for any UI associated with this command.

Parameter ``iconName``:
    Receives the icon name.

Remark:
    Required Library:mdlbltin.lib)doc";

static const char * __doc_Bentley_MstnPlatform_IXCommand_CanDisplayChanged =R"doc(Called when the CanDisplay status changes.

Parameter ``newValue``:
    true if the command's UI can be displayed; otherwise, false.

Remark:
    Required Library:mdlbltin.lib)doc";

static const char * __doc_Bentley_MstnPlatform_IXCommand_SetCanDisplay =R"doc(Sets a flag for whether the command's UI can be displayed.

Parameter ``value``:
    true if the command's UI can be displayed; otherwise, false.

Remark:
    Required Library:mdlbltin.lib)doc";

static const char * __doc_Bentley_MstnPlatform_IXCommand_IsUserDefined =R"doc(Return true if command was loaded via MS_NAMEDCOMMANDSLIST; otherwise,
false.

Remark:
    Required Library:mdlbltin.lib)doc";

static const char * __doc_Bentley_MstnPlatform_IXCommand_CanDisplay =R"doc(Determines if any UI associated with this command can be displayed.

Returns:
    true if the command's UI can be displayed; otherwise, false.

Remark:
    Required Library:mdlbltin.lib)doc";

static const char * __doc_Bentley_MstnPlatform_IXCommand_CanExecuteChanged =R"doc(Called when the CanExecute status changes.

Parameter ``newValue``:
    true if the command can be executed; otherwise, false.

Remark:
    Required Library:mdlbltin.lib)doc";

static const char * __doc_Bentley_MstnPlatform_IXCommand_SetCanExecute =R"doc(Sets a flag for whether the command can be executed.

Parameter ``value``:
    true if the command can be executed; otherwise, false.

Remark:
    Required Library:mdlbltin.lib)doc";

static const char * __doc_Bentley_MstnPlatform_IXCommand_CanExecute =R"doc(Determines if the command can be executed.

Returns:
    true if the command can be executed; otherwise, false.

Remark:
    Required Library:mdlbltin.lib)doc";

static const char * __doc_Bentley_MstnPlatform_IXCommand_ExecuteCmd =R"doc(Executes the command for this IXCommand.

Parameter ``instance``:
    The data context for this execute invocation

Parameter ``unparsed``:
    The string parameter for this execute invocation

Returns:
    SUCCESS if the command was executed, or non-zero if an error
    occurred

Remark:
    Required Library:mdlbltin.lib)doc";



/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_IXCommand(py::module_& m)
    {
    //===================================================================================
    // struct IXCommand
    py::class_< IXCommand
        , RefCountedPtr< IXCommand>
        , MstnEditAction
    > c1(m, "IXCommand");


    c1.def("ExecuteCmd", &IXCommand::ExecuteCmd, "instance"_a, "unparsed"_a, DOC(Bentley, MstnPlatform, IXCommand, ExecuteCmd));
    c1.def("CanExecute", &IXCommand::CanExecute, DOC(Bentley, MstnPlatform, IXCommand, CanExecute));
    c1.def("SetCanExecute", &IXCommand::SetCanExecute, "value"_a, DOC(Bentley, MstnPlatform, IXCommand, SetCanExecute));
    c1.def("CanExecuteChanged", &IXCommand::CanExecuteChanged, "newValue"_a, DOC(Bentley, MstnPlatform, IXCommand, CanExecuteChanged));
    c1.def("CanDisplay", &IXCommand::CanDisplay, DOC(Bentley, MstnPlatform, IXCommand, CanDisplay));
    c1.def("IsUserDefined", &IXCommand::IsUserDefined, DOC(Bentley, MstnPlatform, IXCommand, IsUserDefined));
    c1.def("SetCanDisplay", &IXCommand::SetCanDisplay, "value"_a, DOC(Bentley, MstnPlatform, IXCommand, SetCanDisplay));
    c1.def("CanDisplayChanged", &IXCommand::CanDisplayChanged, "newValue"_a, DOC(Bentley, MstnPlatform, IXCommand, CanDisplayChanged));
    c1.def("GetIconName", &IXCommand::GetIconName, "iconName"_a, DOC(Bentley, MstnPlatform, IXCommand, GetIconName));
    c1.def("GetShowExpression", &IXCommand::GetShowExpression, "expression"_a, DOC(Bentley, MstnPlatform, IXCommand, GetShowExpression));
    c1.def("SetShowExpression", &IXCommand::SetShowExpression, "expression"_a, DOC(Bentley, MstnPlatform, IXCommand, SetShowExpression));
    c1.def("EvaluateShowExpression", &IXCommand::EvaluateShowExpression, "defaultValue"_a, DOC(Bentley, MstnPlatform, IXCommand, EvaluateShowExpression));
    c1.def("HasShowExpression", &IXCommand::HasShowExpression, DOC(Bentley, MstnPlatform, IXCommand, HasShowExpression));
    c1.def("GetEnableExpression", &IXCommand::GetEnableExpression, "expression"_a, DOC(Bentley, MstnPlatform, IXCommand, GetEnableExpression));
    c1.def("SetEnableExpression", &IXCommand::SetEnableExpression, "expression"_a, DOC(Bentley, MstnPlatform, IXCommand, SetEnableExpression));
    c1.def("EvaluateEnableExpression", &IXCommand::EvaluateEnableExpression, "defaultValue"_a, DOC(Bentley, MstnPlatform, IXCommand, EvaluateEnableExpression));
    c1.def("HasEnableExpression", &IXCommand::HasEnableExpression, DOC(Bentley, MstnPlatform, IXCommand, HasEnableExpression));
    c1.def("GetToggleExpression", &IXCommand::GetToggleExpression, "expression"_a, DOC(Bentley, MstnPlatform, IXCommand, GetToggleExpression));
    c1.def("SetToggleExpression", &IXCommand::SetToggleExpression, "expression"_a, DOC(Bentley, MstnPlatform, IXCommand, SetToggleExpression));
    c1.def("EvaluateToggleExpression", &IXCommand::EvaluateToggleExpression, "defaultValue"_a, DOC(Bentley, MstnPlatform, IXCommand, EvaluateToggleExpression));
    c1.def("HasToggleExpression", &IXCommand::HasToggleExpression, DOC(Bentley, MstnPlatform, IXCommand, HasToggleExpression));
    c1.def("GetMarkExpression", &IXCommand::GetMarkExpression, "expression"_a, DOC(Bentley, MstnPlatform, IXCommand, GetMarkExpression));
    c1.def("SetMarkExpression", &IXCommand::SetMarkExpression, "expression"_a, DOC(Bentley, MstnPlatform, IXCommand, SetMarkExpression));
    c1.def("EvaluateMarkExpression", &IXCommand::EvaluateMarkExpression, "defaultValue"_a, DOC(Bentley, MstnPlatform, IXCommand, EvaluateMarkExpression));
    c1.def("HasMarkExpression", &IXCommand::HasMarkExpression, DOC(Bentley, MstnPlatform, IXCommand, HasMarkExpression));
    c1.def("GetUISyncEvents", &IXCommand::GetUISyncEvents, "value"_a, DOC(Bentley, MstnPlatform, IXCommand, GetUISyncEvents));
    c1.def("SetUISyncEvents", &IXCommand::SetUISyncEvents, "value"_a, DOC(Bentley, MstnPlatform, IXCommand, SetUISyncEvents));
    c1.def("GetFeatureTrackingId", &IXCommand::GetFeatureTrackingId, "featureTrackingId"_a, DOC(Bentley, MstnPlatform, IXCommand, GetFeatureTrackingId));
    c1.def("SetFeatureTrackingId", &IXCommand::SetFeatureTrackingId, "featureTrackingId"_a, DOC(Bentley, MstnPlatform, IXCommand, SetFeatureTrackingId));
    
    c1.def_property("Attributes", &IXCommand::GetAttributes, &IXCommand::SetAttributes);
    c1.def("GetAttributes", &IXCommand::GetAttributes, DOC(Bentley, MstnPlatform, IXCommand, GetAttributes));
    c1.def("SetAttributes", &IXCommand::SetAttributes, "atributes"_a, DOC(Bentley, MstnPlatform, IXCommand, SetAttributes));
    
    c1.def_property("Accelerator", &IXCommand::GetAccelerator, &IXCommand::SetAccelerator);
    c1.def("GetAccelerator", &IXCommand::GetAccelerator, DOC(Bentley, MstnPlatform, IXCommand, GetAccelerator));
    c1.def("SetAccelerator", &IXCommand::SetAccelerator, "accelerator"_a, DOC(Bentley, MstnPlatform, IXCommand, SetAccelerator));
    
    c1.def("GetAcceleratorString", &IXCommand::GetAcceleratorString, "accelStr"_a, DOC(Bentley, MstnPlatform, IXCommand, GetAcceleratorString));
    c1.def("IsAllowed", &IXCommand::IsAllowed, DOC(Bentley, MstnPlatform, IXCommand, IsAllowed));    
    }