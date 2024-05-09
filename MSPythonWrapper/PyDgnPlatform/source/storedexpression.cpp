/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnPlatform\source\storedexpression.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <DgnPlatform/StoredExpression.h>



static const char * __doc_Bentley_DgnPlatform_StoredExpressionEntry_SetNameAndLabel =R"doc(Parameter ``name``:
    entry name.

Parameter ``label``:
    entry label.)doc";

static const char * __doc_Bentley_DgnPlatform_StoredExpressionEntry_SetLabel =R"doc(Set entry label

Parameter ``label``:
    entry label.)doc";

static const char * __doc_Bentley_DgnPlatform_StoredExpressionEntry_GetLabel =R"doc(Get entry label)doc";

static const char * __doc_Bentley_DgnPlatform_StoredExpressionEntry_SetName =R"doc(Set entry name

Parameter ``name``:
    entry name.)doc";

static const char * __doc_Bentley_DgnPlatform_StoredExpressionEntry_GetName =R"doc(Get entry name)doc";

static const char * __doc_Bentley_DgnPlatform_StoredExpression_GetSymbolSetVector =R"doc(Get a bvector of symbol sets for this Stored Expression.)doc";

static const char * __doc_Bentley_DgnPlatform_StoredExpression_GetKeyWordVector =R"doc(Get a bvector of keywords for this Stored Expression.)doc";

static const char * __doc_Bentley_DgnPlatform_StoredExpression_AddKeyWord =R"doc(Add a Keyword name to the Stored Expression.

Parameter ``keyword``:
    Keyword name to add to the list of Keyword that exposes this
    expression.)doc";

static const char * __doc_Bentley_DgnPlatform_StoredExpression_AddSymbolSet =R"doc(Add a Symbol Set name to the Stored Expression.

Parameter ``symbolSetName``:
    Symbol set name to add to the list of Symbol Set required to
    evaluate the expression.)doc";

static const char * __doc_Bentley_DgnPlatform_StoredExpression_SetExpression =R"doc(Set the Stored Expression's expression string.

Parameter ``expression``:
    New expression string that is processed by the Expression
    Evaluator.)doc";

static const char * __doc_Bentley_DgnPlatform_StoredExpression_SetDescription =R"doc(Set the Description of a Stored Expression.

Parameter ``description``:
    New description for expression. The description is localizable.)doc";

static const char * __doc_Bentley_DgnPlatform_StoredExpression_SetDisplayLabel =R"doc(Set the Display Label of a Stored Expression.

Parameter ``label``:
    New label for expression. The label is localizable and used in to
    identify the expression in the UI.)doc";

static const char * __doc_Bentley_DgnPlatform_StoredExpression_SetName =R"doc(Set the Name of a Stored Expression.

Parameter ``name``:
    New name for expression. This is a non-localizable string that is
    used to identify the expression.)doc";

static const char * __doc_Bentley_DgnPlatform_StoredExpressionHelper_GetElementRef =R"doc(Get the ElementRefP that is associated with the Stored Expressions
XAttributes. All the Stored Expressions in the file are associated
with this one element.

Parameter ``dgnfile``:
    Dgn file to process.)doc";

static const char * __doc_Bentley_DgnPlatform_StoredExpressionHelper_CollectKeywordNames =R"doc(Get bvector of Store Expression Keyword Names.

Parameter ``keywordVector``:
    empty bvector to populate with the names of the Stored Expressions
    Keywords.

Parameter ``dgnfile``:
    Dgn file to process.)doc";

static const char * __doc_Bentley_DgnPlatform_StoredExpressionHelper_CollectExpressionEntries =R"doc(Get bvector of Store Expression Entries, useful for population User
Interface Components.

Parameter ``expressionEntriesVector``:
    bvector to populate with available Expression entries.

Parameter ``dgnfile``:
    Dgn file to process.

Parameter ``limitingKeyword``:
    limit to specific keyword.)doc";

static const char * __doc_Bentley_DgnPlatform_StoredExpressionHelper_CollectExpressionNames =R"doc(Get bvector of Store Expression Names.

Parameter ``expressionVector``:
    empty bvector to populate with the names of the Stored
    Expressions.

Parameter ``dgnfile``:
    Dgn file to process.)doc";

static const char * __doc_Bentley_DgnPlatform_StoredExpressionHelper_GetKeywordHandlerID =R"doc(Get XAttributeHandlerId for the Store Expression Keyword XAttributes.)doc";

static const char * __doc_Bentley_DgnPlatform_StoredExpressionHelper_GetExpressionHandlerID =R"doc(Get XAttributeHandlerId for the Store Expression XAttributes.)doc";

static const char * __doc_Bentley_DgnPlatform_StoredExpressionHelper_AddOrUpdateKeywordInFile =R"doc(Add or update the XAttributes that define a Stored Expression Keyword.

Parameter ``keyword``:
    Stored Expression Keyword definition.

Parameter ``dgnfile``:
    Dgn file to process.

Parameter ``originalKeywordName``:
    optional, original name, used when renaming.)doc";

static const char * __doc_Bentley_DgnPlatform_StoredExpressionHelper_UpdateKeyword =R"doc(Update a specific XAttributes to match the supplied Stored Expression
Keyword.

Parameter ``xAttr``:
    Existing XAttributeHandle.

Parameter ``keyword``:
    Stored Expression Keyword definition used to update existing
    XAttribute.)doc";

static const char * __doc_Bentley_DgnPlatform_StoredExpressionHelper_FindKeywordByName =R"doc(Return Stored Expression Keyword found in file by name. If a matching
name is not found the returned pointer .IsValid() method will return
false.

Parameter ``dgnfile``:
    Dgn file to process.

Parameter ``name``:
    Named of Stored Expression Keyword to return.)doc";

static const char * __doc_Bentley_DgnPlatform_StoredExpressionHelper_CreateKeywordFromXAttributes =R"doc(Return Stored Expression Keyword stored in the XAttributes defined be
the input XAttributeHandle.

Parameter ``xAttr``:
    XAttributeHandle containing the Stored Expression Keyword
    XAttributes.)doc";

static const char * __doc_Bentley_DgnPlatform_StoredExpressionHelper_AddOrUpdateExpressionInFile =R"doc(Add or update the XAttribute that define a Stored Expression Keyword.

Parameter ``expression``:
    Stored Expression definition.

Parameter ``dgnfile``:
    Dgn file to process.

Parameter ``originalExpressionName``:
    optional, original name, used when renaming.)doc";

static const char * __doc_Bentley_DgnPlatform_StoredExpressionHelper_UpdateExpression =R"doc(Update a specific XAttribute to match the supplied Stored Expression.

Parameter ``xAttr``:
    Existing XAttributeHandle.

Parameter ``expression``:
    Stored Expression definition used to update existing XAttribute.)doc";

static const char * __doc_Bentley_DgnPlatform_StoredExpressionHelper_FindExpressionByName =R"doc(Return Stored Expression found in file by name. If a matching name is
not found the returned pointer .IsValid() method will return false.

Parameter ``dgnfile``:
    Dgn file to process.

Parameter ``name``:
    Named of Stored Expression to return.)doc";

static const char * __doc_Bentley_DgnPlatform_StoredExpressionHelper_CreateExpressionFromXAttributes =R"doc(Return Stored Expression stored in the XAttributes defined be the
input XAttributeHandle.

Parameter ``xAttr``:
    XAttributeHandle containing the Stored Expression XAttributes.)doc";

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_StoredExpression(py::module_& m)
    {
    //===================================================================================
    // struct StoredExpressionHelper
    py::class_< StoredExpressionHelper> c1(m, "StoredExpressionHelper");

    c1.def_static("CreateExpressionFromXAttributes", &StoredExpressionHelper::CreateExpressionFromXAttributes, "xAttr"_a, DOC(Bentley, DgnPlatform, StoredExpressionHelper, CreateExpressionFromXAttributes));
    c1.def_static("FindExpressionByName", &StoredExpressionHelper::FindExpressionByName, "dgnFile"_a, "name"_a, DOC(Bentley, DgnPlatform, StoredExpressionHelper, FindExpressionByName));
    c1.def_static("UpdateExpression", &StoredExpressionHelper::UpdateExpression, "xAttr"_a, "expression"_a, DOC(Bentley, DgnPlatform, StoredExpressionHelper, UpdateExpression));
    c1.def_static("AddOrUpdateExpressionInFile", &StoredExpressionHelper::AddOrUpdateExpressionInFile, "expression"_a, "dgnFile"_a, "originalExpressionName"_a = nullptr, DOC(Bentley, DgnPlatform, StoredExpressionHelper, AddOrUpdateExpressionInFile));
    c1.def_static("CreateKeywordFromXAttributes", &StoredExpressionHelper::CreateKeywordFromXAttributes, "xAttr"_a, DOC(Bentley, DgnPlatform, StoredExpressionHelper, CreateKeywordFromXAttributes));
    c1.def_static("FindKeywordByName", &StoredExpressionHelper::FindKeywordByName, "dgnFile"_a, "name"_a, DOC(Bentley, DgnPlatform, StoredExpressionHelper, FindKeywordByName));
    c1.def_static("UpdateKeyword", &StoredExpressionHelper::UpdateKeyword, "xAttr"_a, "keyword"_a, DOC(Bentley, DgnPlatform, StoredExpressionHelper, UpdateKeyword));
    c1.def_static("AddOrUpdateKeywordInFile", &StoredExpressionHelper::AddOrUpdateKeywordInFile, "keyword"_a, "dgnFile"_a, "originalKeywordName"_a = nullptr, DOC(Bentley, DgnPlatform, StoredExpressionHelper, AddOrUpdateKeywordInFile));
    
    c1.def_property_readonly_static("ExpressionHandlerID", [] (py::object const&) { return StoredExpressionHelper::GetExpressionHandlerID(); });
    c1.def_static("GetExpressionHandlerID", &StoredExpressionHelper::GetExpressionHandlerID, DOC(Bentley, DgnPlatform, StoredExpressionHelper, GetExpressionHandlerID));
    
    c1.def_property_readonly_static("KeywordHandlerID", [] (py::object const&) { return StoredExpressionHelper::GetKeywordHandlerID(); });
    c1.def_static("GetKeywordHandlerID", &StoredExpressionHelper::GetKeywordHandlerID, DOC(Bentley, DgnPlatform, StoredExpressionHelper, GetKeywordHandlerID));

    c1.def_static("CollectExpressionNames", &StoredExpressionHelper::CollectExpressionNames, "expressionVector"_a, "dgnFile"_a, DOC(Bentley, DgnPlatform, StoredExpressionHelper, CollectExpressionNames));
    c1.def_static("CollectExpressionEntries", &StoredExpressionHelper::CollectExpressionEntries, "expressionEntriesVector"_a, "dgnFile"_a, "limitingKeyword"_a = nullptr, DOC(Bentley, DgnPlatform, StoredExpressionHelper, CollectExpressionEntries));
    c1.def_static("CollectKeywordNames", &StoredExpressionHelper::CollectKeywordNames, "keywordVector"_a, "dgnFile"_a, DOC(Bentley, DgnPlatform, StoredExpressionHelper, CollectKeywordNames));
    c1.def_static("GetElementRef", &StoredExpressionHelper::GetElementRef, "dgnFile"_a, py::return_value_policy::reference, DOC(Bentley, DgnPlatform, StoredExpressionHelper, GetElementRef));

    //===================================================================================
    // struct StoredExpression
    py::class_< StoredExpression, StoredExpressionPtr> c2(m, "StoredExpression");

    c2.def_property("Name", &StoredExpression::GetNameCP, &StoredExpression::SetName);
    c2.def("GetName", &StoredExpression::GetNameCP, py::return_value_policy::reference_internal);
    c2.def("SetName", &StoredExpression::SetName, "name"_a, DOC(Bentley, DgnPlatform, StoredExpression, SetName));
    
    c2.def_property("DisplayLabel", &StoredExpression::GetDisplayLabelCP, &StoredExpression::SetDisplayLabel);
    c2.def("GetDisplayLabel", &StoredExpression::GetDisplayLabelCP, py::return_value_policy::reference_internal);
    c2.def("SetDisplayLabel", &StoredExpression::SetDisplayLabel, "label"_a, DOC(Bentley, DgnPlatform, StoredExpression, SetDisplayLabel));
    
    c2.def_property("Description", &StoredExpression::GetDescriptionCP, &StoredExpression::SetDescription);
    c2.def("GetDescription", &StoredExpression::GetDescriptionCP, py::return_value_policy::reference_internal);
    c2.def("SetDescription", &StoredExpression::SetDescription, "description"_a, DOC(Bentley, DgnPlatform, StoredExpression, SetDescription));
    
    c2.def_property("Expression", &StoredExpression::GetExpressionCP, &StoredExpression::SetExpression);
    c2.def("GetExpression", &StoredExpression::GetExpressionCP, py::return_value_policy::reference_internal);
    c2.def("SetExpression", &StoredExpression::SetExpression, "expr"_a, DOC(Bentley, DgnPlatform, StoredExpression, SetExpression));
    
    c2.def("AddSymbolSet", &StoredExpression::AddSymbolSet, "symbolSetName"_a, DOC(Bentley, DgnPlatform, StoredExpression, AddSymbolSet));
    c2.def("AddKeyWord", &StoredExpression::AddKeyWord, "keyword"_a, DOC(Bentley, DgnPlatform, StoredExpression, AddKeyWord));
    
    c2.def_property_readonly("KeyWordVector", &StoredExpression::GetKeyWordVector);
    c2.def("GetKeyWordVector", &StoredExpression::GetKeyWordVector, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, StoredExpression, GetKeyWordVector));
    
    c2.def_property_readonly("SymbolSetVector", &StoredExpression::GetSymbolSetVector);
    c2.def("GetSymbolSetVector", &StoredExpression::GetSymbolSetVector, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, StoredExpression, GetSymbolSetVector));

    //===================================================================================
    // struct StoredExpressionKeyword
    py::class_< DgnPlatform::StoredExpressionKeyword, StoredExpressionKeywordPtr> c3(m, "StoredExpressionKeyword");

    c3.def_property_readonly("Name", &DgnPlatform::StoredExpressionKeyword::GetNameCP);
    c3.def("GetName", &DgnPlatform::StoredExpressionKeyword::GetNameCP, py::return_value_policy::reference_internal);
    
    c3.def_property_readonly("DisplayLabel", &DgnPlatform::StoredExpressionKeyword::GetDisplayLabelCP);
    c3.def("GetDisplayLabel", &DgnPlatform::StoredExpressionKeyword::GetDisplayLabelCP, py::return_value_policy::reference_internal);
    
    c3.def_property_readonly("Description", &DgnPlatform::StoredExpressionKeyword::GetDescriptionCP);
    c3.def("GetDescription", &DgnPlatform::StoredExpressionKeyword::GetDescriptionCP, py::return_value_policy::reference_internal);
    
    c3.def_property_readonly("IconName", &DgnPlatform::StoredExpressionKeyword::GetIconNameCP);
    c3.def("GetIconName", &DgnPlatform::StoredExpressionKeyword::GetIconNameCP, py::return_value_policy::reference_internal);

    //===================================================================================
    // struct StoredExpressionEntry
    py::class_< StoredExpressionEntry> c4(m, "StoredExpressionEntry");

    c4.def(py::init<>());
    c4.def(py::init<WCharCP, WCharCP>(), "name"_a, "label"_a);
    c4.def(py::self < py::self);
    c4.def(py::self == py::self);

    c4.def_property("Name", &StoredExpressionEntry::GetName, &StoredExpressionEntry::SetName);
    c4.def("GetName", &StoredExpressionEntry::GetName, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, StoredExpressionEntry, GetName));
    c4.def("SetName", &StoredExpressionEntry::SetName, "name"_a, DOC(Bentley, DgnPlatform, StoredExpressionEntry, SetName));
    
    c4.def_property("Label", &StoredExpressionEntry::GetLabel, &StoredExpressionEntry::SetLabel);
    c4.def("GetLabel", &StoredExpressionEntry::GetLabel, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, StoredExpressionEntry, GetLabel));
    c4.def("SetLabel", &StoredExpressionEntry::SetLabel, "label"_a, DOC(Bentley, DgnPlatform, StoredExpressionEntry, SetLabel));
    
    c4.def("SetNameAndLabel", &StoredExpressionEntry::SetNameAndLabel, "name"_a, "label"_a, DOC(Bentley, DgnPlatform, StoredExpressionEntry, SetNameAndLabel));
    }