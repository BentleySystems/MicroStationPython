/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnPlatform\source\displayrules.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <DgnPlatform/DisplayRules.h>



static const char * __doc_Bentley_DgnPlatform_DisplayRuleSet_IsUsedByDisplayStyle =R"doc(Returns true if DisplayRuleSet is used by given DisplayStyle. Bentley
Systems +---------------+---------------+---------------+-------------
--+---------------+------)doc";

static const char * __doc_Bentley_DgnPlatform_DisplayRuleSet_Clone =R"doc(Creates exact copy of an instance. Bentley Systems +---------------+--
-------------+---------------+---------------+---------------+------)doc";

static const char * __doc_Bentley_DgnPlatform_DisplayRuleSet_GetDisplayRules =R"doc(Returns a list of DisplayRules. Bentley Systems +---------------+-----
----------+---------------+---------------+---------------+------)doc";

static const char * __doc_Bentley_DgnPlatform_DisplayRuleSet_SetName =R"doc(Sets DisplayRuleSet name. Bentley Systems +---------------+-----------
----+---------------+---------------+---------------+------)doc";

static const char * __doc_Bentley_DgnPlatform_DisplayRuleSet_GetName =R"doc(Returns DisplayRuleSet name. Bentley Systems +---------------+--------
-------+---------------+---------------+---------------+------)doc";

static const char * __doc_Bentley_DgnPlatform_DisplayRule_Clone =R"doc(Creates exact copy of an instance. Bentley Systems +---------------+--
-------------+---------------+---------------+---------------+------)doc";

static const char * __doc_Bentley_DgnPlatform_DisplayRule_GetActions =R"doc(Returns actions associated with this DisplayRule.

See also:
    IDisplayRuleAction for more details. Bentley Systems +------------
    ---+---------------+---------------+---------------+--------------
    -+------)doc";

static const char * __doc_Bentley_DgnPlatform_DisplayRule_SetConditionDescription =R"doc(Sets given ECExpression string condition description. Bentley Systems 
+---------------+---------------+---------------+---------------+-----
----------+------)doc";

static const char * __doc_Bentley_DgnPlatform_DisplayRule_GetConditionDescription =R"doc(Returns ECExpression string condition description. Bentley Systems +--
-------------+---------------+---------------+---------------+--------
-------+------)doc";

static const char * __doc_Bentley_DgnPlatform_DisplayRule_SetCondition =R"doc(Sets given ECExpression string condition. Bentley Systems +-----------
----+---------------+---------------+---------------+---------------+-
-----)doc";

static const char * __doc_Bentley_DgnPlatform_DisplayRule_GetCondition =R"doc(Returns ECExpression string condition. Bentley Systems +--------------
-+---------------+---------------+---------------+---------------+----
--)doc";

static const char * __doc_Bentley_DgnPlatform_DisplayRule_SetStopIfTrue =R"doc(Sets StopIfTrue value that controls whether rule processing should
stop then this rule is met. Bentley Systems +---------------+---------
------+---------------+---------------+---------------+------)doc";

static const char * __doc_Bentley_DgnPlatform_DisplayRule_StopIfTrue =R"doc(Returns true if rule processing should stop then this rule is met.
Bentley Systems +---------------+---------------+---------------+-----
----------+---------------+------)doc";

static const char * __doc_Bentley_DgnPlatform_DisplayRule_SetIsEnabled =R"doc(Sets IsEnabled flag to given value. Bentley Systems +---------------+-
--------------+---------------+---------------+---------------+------)doc";

static const char * __doc_Bentley_DgnPlatform_DisplayRule_IsEnabled =R"doc(Identifies whether DisplayRule is enabled.

Returns:
    true if DisplayRule is enabled. Bentley Systems +---------------+-
    --------------+---------------+---------------+---------------+---
    ---)doc";

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_DisplayRules(py::module_& m)
    {
    //===================================================================================
    // struct DisplayRule
    py::class_< DisplayRule, DisplayRulePtr> c1(m, "DisplayRule");
    py::bind_vector<bvector< DisplayRulePtr>>(m, "DisplayRulePtrArray", py::module_local(false));

    c1.def(py::init(&DisplayRule::Create), "condition"_a, "stopIfTrue"_a, "dgnFile"_a);
    c1.def("__eq__", [] (DisplayRule const& self, DisplayRuleCR displayRule) { return self.Equals(displayRule); });

    c1.def_property("Enabled", &DisplayRule::IsEnabled, &DisplayRule::SetIsEnabled);
    c1.def("IsEnabled", &DisplayRule::IsEnabled, DOC(Bentley, DgnPlatform, DisplayRule, IsEnabled));
    c1.def("SetIsEnabled", &DisplayRule::SetIsEnabled, "enabled"_a, DOC(Bentley, DgnPlatform, DisplayRule, SetIsEnabled));
    
    c1.def("StopIfTrue", &DisplayRule::StopIfTrue, DOC(Bentley, DgnPlatform, DisplayRule, StopIfTrue));
    c1.def("SetStopIfTrue", &DisplayRule::SetStopIfTrue, "stopIfTrue"_a, DOC(Bentley, DgnPlatform, DisplayRule, SetStopIfTrue));
    
    c1.def_property("Condition", &DisplayRule::GetCondition, &DisplayRule::SetCondition);
    c1.def("GetCondition", &DisplayRule::GetCondition, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, DisplayRule, GetCondition));
    c1.def("SetCondition", &DisplayRule::SetCondition, "condition"_a, DOC(Bentley, DgnPlatform, DisplayRule, SetCondition));
    
    c1.def_property("ConditionDescription", &DisplayRule::GetConditionDescription, &DisplayRule::SetConditionDescription);
    c1.def("GetConditionDescription", &DisplayRule::GetConditionDescription, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, DisplayRule, GetConditionDescription));
    c1.def("SetConditionDescription", &DisplayRule::SetConditionDescription, "conditionDescription"_a, DOC(Bentley, DgnPlatform, DisplayRule, SetConditionDescription));
    
    c1.def_property_readonly("Actions", &DisplayRule::GetActions);
    c1.def("GetActions", &DisplayRule::GetActions, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, DisplayRule, GetActions));
    
    c1.def("Clone", &DisplayRule::Clone, DOC(Bentley, DgnPlatform, DisplayRule, Clone));

    //===================================================================================
    // struct DisplayRuleSet
    py::class_< DisplayRuleSet, DisplayRuleSetPtr> c2(m, "DisplayRuleSet");
    bind_PointerVector< DisplayRuleSetCP>(m, "DisplayRuleSetCPArray", py::module_local(false));
    py::bind_vector< bvector<DisplayRuleSetPtr>>(m, "DisplayRuleSetPtrArray", py::module_local(false));

    c2.def(py::init(&DisplayRuleSet::Create), "name"_a, "dgnFile"_a);
    c2.def("__eq__", [] (DisplayRuleSet const& self, DisplayRuleSet displayRuleSet) { return self.Equals(displayRuleSet); });
    
    c2.def_property("Name", &DisplayRuleSet::GetName, &DisplayRuleSet::SetName);
    c2.def("GetName", &DisplayRuleSet::GetName, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, DisplayRuleSet, GetName));
    c2.def("SetName", &DisplayRuleSet::SetName, "name"_a, DOC(Bentley, DgnPlatform, DisplayRuleSet, SetName));
    
    c2.def_property_readonly("DgnFile", &DisplayRuleSet::GetDgnFileR);
    c2.def("GetDgnFile", &DisplayRuleSet::GetDgnFileR, py::return_value_policy::reference_internal);
    
    c2.def_property_readonly("DisplayRules", &DisplayRuleSet::GetDisplayRules);
    c2.def("GetDisplayRules", &DisplayRuleSet::GetDisplayRules, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, DisplayRuleSet, GetDisplayRules));
    
    c2.def("Clone", &DisplayRuleSet::Clone, DOC(Bentley, DgnPlatform, DisplayRuleSet, Clone));
    c2.def("IsUsedByDisplayStyle", &DisplayRuleSet::IsUsedByDisplayStyle, "displayStyle"_a, DOC(Bentley, DgnPlatform, DisplayRuleSet, IsUsedByDisplayStyle));

    }