/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnPlatform\source\displayrulesmanager.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <DgnPlatform/DisplayRulesManager.h>



static const char * __doc_Bentley_DgnPlatform_DisplayRulesManager_GetDisplayRuleSetFromDisplayStyle =R"doc(Returns DisplayRuleSet associated to DisplayStyle. Returns nullptr if
association doesn't exist. Bentley Systems +---------------+----------
-----+---------------+---------------+---------------+------)doc";

static const char * __doc_Bentley_DgnPlatform_DisplayRulesManager_SetDisplayRuleSetToDisplayStyle =R"doc(Sets DisplayRuleSet association to DisplayStyle. DisplayStyle is
modified, but not saved. \note DisplayRuleSet and DisplayStyle should
be stored in the same file. Bentley Systems +---------------+---------
------+---------------+---------------+---------------+------)doc";

static const char * __doc_Bentley_DgnPlatform_DisplayRulesManager_RemoveDisplayRuleSetFromFile =R"doc(Removes a display rule set from a file. Its ID cannot be re-used at
this point. \note When a display rule set is removed, no attempts are
currently made to normalize existing elements. Thus elements may still
attempt to reference a missing display rule set, but must be written
to assume such a display rule set doesn't exist.

Parameter ``ruleSetName``:
    the rule set which will be removed

Parameter ``dgnFile``:
    the object of MSDgnFileR from where display rule set will be
    removed Bentley Systems +---------------+---------------+---------
    ------+---------------+---------------+------)doc";

static const char * __doc_Bentley_DgnPlatform_DisplayRulesManager_RenameDisplayRuleSetInFile =R"doc(Renames a display rule set in a file. Its ID remains the same. \note
When a display rule set is renamed, no attempts are currently made to
normalize existing elements. The is acceptable because all current
known elements store display rule set IDs, which are unaffected by
this operation.

Parameter ``originalName``:
    the old rule set name

Parameter ``newName``:
    the new rule set name

Parameter ``dgnFile``:
    the object of MSDgnFileR where it will be renamed Bentley Systems 
    +---------------+---------------+---------------+---------------+-
    --------------+------)doc";

static const char * __doc_Bentley_DgnPlatform_DisplayRulesManager_WriteDisplayRuleSetToFile =R"doc(Writes the given display rule set to the given file. If one by the
same name already exists, it is replaced. A replaced display rule set
retains the ID of the version already in the file. The persisted
version of the display rule set is returned, and should be used from
this point on.

Parameter ``displayRuleSet``:
    the object of type DisplayRuleSetCR

Parameter ``destinationDgnFile``:
    the object of MSDgnFileR

Parameter ``notifyListeners``:
    pass true if listeners needs to be notified

Returns:
    DisplayRuleSetCP type of object Bentley Systems +---------------+-
    --------------+---------------+---------------+---------------+---
    ---)doc";

static const char * __doc_Bentley_DgnPlatform_DisplayRulesManager_GetDisplayRuleSetByName =R"doc(Returns the display rule set, if present, from the file's display rule
set collection as indicated by the provided name.

Parameter ``name``:
    DisplayRuleSet

Parameter ``dgnFile``:
    the object of MSDgnFileP

Returns:
    DisplayRuleSetCP type of object Bentley Systems +---------------+-
    --------------+---------------+---------------+---------------+---
    ---)doc";

static const char * __doc_Bentley_DgnPlatform_DisplayRulesManager_GetDisplayRuleSetByIndex =R"doc(Returns the display rule set, if present, from the file's display rule
set collection as indicated by the provided index.

Parameter ``index``:
    DisplayRuleSetCPVector::size_type

Parameter ``dgnFile``:
    the object of MSDgnFileP

Returns:
    DisplayRuleSetCP type of object Bentley Systems +---------------+-
    --------------+---------------+---------------+---------------+---
    ---)doc";

static const char * __doc_Bentley_DgnPlatform_DisplayRulesManager_GetDisplayRuleSetsInFile =R"doc(Returns list of DisplayRuleSets stored in the give file.

Parameter ``dgnFile``:
    the object of MSDgnFileR where DisplayRuleSets are stored. Bentley
    Systems +---------------+---------------+---------------+---------
    ------+---------------+------)doc";


/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_DisplayRulesManager(py::module_& m)
    {
    //===================================================================================
    // struct DisplayRulesManager
    py::class_< DisplayRulesManager> c2(m, "DisplayRulesManager");

    c2.def_static("GetDisplayRuleSetsInFile", &DisplayRulesManager::GetDisplayRuleSetsInFile, "dgnFile"_a, DOC(Bentley, DgnPlatform, DisplayRulesManager, GetDisplayRuleSetsInFile));
    c2.def_static("GetDisplayRuleSetByIndex", &DisplayRulesManager::GetDisplayRuleSetByIndex, "index"_a, "dgnFile"_a, py::return_value_policy::reference, DOC(Bentley, DgnPlatform, DisplayRulesManager, GetDisplayRuleSetByIndex));
    c2.def_static("GetDisplayRuleSetByName", &DisplayRulesManager::GetDisplayRuleSetByName, "name"_a, "dgnFile"_a, py::return_value_policy::reference, DOC(Bentley, DgnPlatform, DisplayRulesManager, GetDisplayRuleSetByName));
    c2.def_static("WriteDisplayRuleSetToFile", &DisplayRulesManager::WriteDisplayRuleSetToFile, "displayRuleSet"_a, "destDgnFile"_a, "notifyListeners"_a, py::return_value_policy::reference, DOC(Bentley, DgnPlatform, DisplayRulesManager, WriteDisplayRuleSetToFile));
    c2.def_static("RenameDisplayRuleSetInFile", &DisplayRulesManager::RenameDisplayRuleSetInFile, "originalName"_a, "newName"_a, "dgnFile"_a, DOC(Bentley, DgnPlatform, DisplayRulesManager, RenameDisplayRuleSetInFile));
    c2.def_static("RemoveDisplayRuleSetFromFile", &DisplayRulesManager::RemoveDisplayRuleSetFromFile, "ruleSetName"_a, "dgnFile"_a, DOC(Bentley, DgnPlatform, DisplayRulesManager, RemoveDisplayRuleSetFromFile));
    c2.def_static("SetDisplayRuleSetToDisplayStyle", &DisplayRulesManager::SetDisplayRuleSetToDisplayStyle, "displayRuleSet"_a, "displayStyle"_a, DOC(Bentley, DgnPlatform, DisplayRulesManager, SetDisplayRuleSetToDisplayStyle));
    c2.def_static("GetDisplayRuleSetFromDisplayStyle", &DisplayRulesManager::GetDisplayRuleSetFromDisplayStyle, "displayStyle"_a, py::return_value_policy::reference, DOC(Bentley, DgnPlatform, DisplayRulesManager, GetDisplayRuleSetFromDisplayStyle));    
    }