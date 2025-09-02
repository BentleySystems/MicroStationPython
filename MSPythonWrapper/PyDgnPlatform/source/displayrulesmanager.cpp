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
association doesn't exist. )doc";

static const char * __doc_Bentley_DgnPlatform_DisplayRulesManager_SetDisplayRuleSetToDisplayStyle =R"doc(Sets DisplayRuleSet association to DisplayStyle. DisplayStyle is
modified, but not saved. DisplayRuleSet and DisplayStyle should
be stored in the same file. )doc";

static const char * __doc_Bentley_DgnPlatform_DisplayRulesManager_RemoveDisplayRuleSetFromFile =R"doc(Removes a display rule set from a file. Its ID cannot be re-used at
this point.  When a display rule set is removed, no attempts are
currently made to normalize existing elements. Thus elements may still
attempt to reference a missing display rule set, but must be written
to assume such a display rule set doesn't exist.

:param ruleSetName:
    the rule set which will be removed

:param dgnFile:
    the object of MSDgnFileR from where display rule set will be
    removed )doc";

static const char * __doc_Bentley_DgnPlatform_DisplayRulesManager_RenameDisplayRuleSetInFile =R"doc(Renames a display rule set in a file. Its ID remains the same. 
When a display rule set is renamed, no attempts are currently made to
normalize existing elements. The is acceptable because all current
known elements store display rule set IDs, which are unaffected by
this operation.

:param originalName:
    the old rule set name

:param newName:
    the new rule set name

:param dgnFile:
    the object of MSDgnFileR where it will be renamed )doc";

static const char * __doc_Bentley_DgnPlatform_DisplayRulesManager_WriteDisplayRuleSetToFile =R"doc(Writes the given display rule set to the given file. If one by the
same name already exists, it is replaced. A replaced display rule set
retains the ID of the version already in the file. The persisted
version of the display rule set is returned, and should be used from
this point on.

:param displayRuleSet:
    the object of type DisplayRuleSetCR

:param destinationDgnFile:
    the object of MSDgnFileR

:param notifyListeners:
    pass true if listeners needs to be notified

:returns:
    DisplayRuleSetCP type of object )doc";

static const char * __doc_Bentley_DgnPlatform_DisplayRulesManager_GetDisplayRuleSetByName =R"doc(Returns the display rule set, if present, from the file's display rule
set collection as indicated by the provided name.

:param name:
    DisplayRuleSet

:param dgnFile:
    the object of MSDgnFileP

:returns:
    DisplayRuleSetCP type of object )doc";

static const char * __doc_Bentley_DgnPlatform_DisplayRulesManager_GetDisplayRuleSetByIndex =R"doc(Returns the display rule set, if present, from the file's display rule
set collection as indicated by the provided index.

:param index:
    DisplayRuleSetCPVector::size_type

:param dgnFile:
    the object of MSDgnFileP

:returns:
    DisplayRuleSetCP type of object )doc";

static const char * __doc_Bentley_DgnPlatform_DisplayRulesManager_GetDisplayRuleSetsInFile =R"doc(Returns list of DisplayRuleSets stored in the give file.

:param dgnFile:
    the object of MSDgnFileR where DisplayRuleSets are stored. )doc";


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
    c2.def_static("WriteDisplayRuleSetToFile", &DisplayRulesManager::WriteDisplayRuleSetToFile, "displayRuleSet"_a, "destDgnFile"_a, "notifyListeners"_a, DOC(Bentley, DgnPlatform, DisplayRulesManager, WriteDisplayRuleSetToFile));
    c2.def_static("RenameDisplayRuleSetInFile", &DisplayRulesManager::RenameDisplayRuleSetInFile, "originalName"_a, "newName"_a, "dgnFile"_a, DOC(Bentley, DgnPlatform, DisplayRulesManager, RenameDisplayRuleSetInFile));
    c2.def_static("RemoveDisplayRuleSetFromFile", &DisplayRulesManager::RemoveDisplayRuleSetFromFile, "ruleSetName"_a, "dgnFile"_a, DOC(Bentley, DgnPlatform, DisplayRulesManager, RemoveDisplayRuleSetFromFile));
    c2.def_static("SetDisplayRuleSetToDisplayStyle", &DisplayRulesManager::SetDisplayRuleSetToDisplayStyle, "displayRuleSet"_a, "displayStyle"_a, DOC(Bentley, DgnPlatform, DisplayRulesManager, SetDisplayRuleSetToDisplayStyle));
    c2.def_static("GetDisplayRuleSetFromDisplayStyle", &DisplayRulesManager::GetDisplayRuleSetFromDisplayStyle, "displayStyle"_a, py::return_value_policy::reference, DOC(Bentley, DgnPlatform, DisplayRulesManager, GetDisplayRuleSetFromDisplayStyle));    
    }