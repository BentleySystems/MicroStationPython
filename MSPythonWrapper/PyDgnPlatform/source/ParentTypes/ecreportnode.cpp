/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnPlatform\source\ecreportnode.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <DgnPlatform/ECReportNode.h>



static const char * __doc_Bentley_DgnPlatform_SortingGroupNode_CreateSortingRule =R"doc(Creates and returns a new sorting rule. The column name must refer to
an existing column definition)doc";

static const char * __doc_Bentley_DgnPlatform_SortingGroupNode_GetSortingRules =R"doc(Returns the list of sorting rules)doc";

static const char * __doc_Bentley_DgnPlatform_ColumnGroupNode_CreateColumnDefinition =R"doc(Creates and returns a new column definition)doc";

static const char * __doc_Bentley_DgnPlatform_ColumnGroupNode_GetColumnDefinitions =R"doc(Returns the list of column definitions)doc";

static const char * __doc_Bentley_DgnPlatform_ReportCategoryNode_GenerateReportFromClass =R"doc(Generates a report definition from an ECClass)doc";

static const char * __doc_Bentley_DgnPlatform_ReportCategoryNode_CreateReportDefinition =R"doc(Creates and returns a new report definition with the specified name
and priority)doc";

static const char * __doc_Bentley_DgnPlatform_ReportCategoryNode_FindByName =R"doc(Find a category node by name in the specified DgnFile)doc";

static const char * __doc_Bentley_DgnPlatform_ReportCategoryNode_From =R"doc(Extract a category node from an ECReportNode)doc";

static const char * __doc_Bentley_DgnPlatform_ReportDefinitionNode_SetIncludeItemTypeOption =R"doc(Set IncludeItemTypeOption which is used for selecting used or
all/unreferenced classes for report.

:param IncludeItemTypeOption:
    the IncludeItemTypeOption to be set)doc";

static const char * __doc_Bentley_DgnPlatform_ReportDefinitionNode_GetIncludeItemTypeOption =R"doc(Get IncludeItemTypeOption which is used for selecting used or
all/unreferenced classes for report. Returns the IncludeItemTypeOption)doc";

static const char * __doc_Bentley_DgnPlatform_ReportDefinitionNode_SetSelectionScopeOption =R"doc(Set SelectionScopeOption which is used for report all, by fence, or by
current selection

:param selectionScopeOption:
    the SelectionScopeOption to be set)doc";

static const char * __doc_Bentley_DgnPlatform_ReportDefinitionNode_GetSelectionScopeOption =R"doc(Get SelectionScopeOption which is used for report all, by fence, or by
current selection Returns the SelectionScopeOption)doc";

static const char * __doc_Bentley_DgnPlatform_ReportDefinitionNode_From =R"doc(Extracts a ReportDefinitionNode from an ECReportNode)doc";

static const char * __doc_Bentley_DgnPlatform_ReportDefinitionNode_FindByPath =R"doc(Locate a report definition by its full path (including category name)
within the specified DgnFile)doc";

static const char * __doc_Bentley_DgnPlatform_ReportDefinitionNode_FindById =R"doc(Locate a report definition by ID within the specified DgnFile)doc";

static const char * __doc_Bentley_DgnPlatform_ReportDefinitionNode_SetRowFilter =R"doc(Sets the ECExpression which is used to filter out rows of the report
results based on their ECPropertyValues)doc";

static const char * __doc_Bentley_DgnPlatform_ReportDefinitionNode_GetRowFilter =R"doc(Returns the ECExpression which is used to filter out rows of the
report results based on their ECPropertyValues)doc";

static const char * __doc_Bentley_DgnPlatform_ReportDefinitionNode_SetScope =R"doc(Returns the scope which will be searched to find ECInstances from
which to populated the report results)doc";

static const char * __doc_Bentley_DgnPlatform_ReportDefinitionNode_GetScope =R"doc(Returns the scope which will be searched to find ECInstances from
which to populated the report results)doc";

static const char * __doc_Bentley_DgnPlatform_ReportDefinitionNode_SetHostSpecifications =R"doc(Sets the specifications which define the ECInstances which will be
included in the report results)doc";

static const char * __doc_Bentley_DgnPlatform_ReportDefinitionNode_GetHostSpecifications =R"doc(Extracts the specifications which define the ECInstances which will be
included in the report results)doc";

static const char * __doc_Bentley_DgnPlatform_ReportDefinitionNode_GetColumnByName =R"doc(Returns the column definition with the specified name)doc";

static const char * __doc_Bentley_DgnPlatform_ReportDefinitionNode_CreateSortingRule =R"doc(Creates and returns a new sorting rule with the specified name and
priority. The name must refer to an existing ColumnDefinitionNode)doc";

static const char * __doc_Bentley_DgnPlatform_ReportDefinitionNode_CreateColumnDefinition =R"doc(Creates and returns a new column definition with the specified name
and priority)doc";

static const char * __doc_Bentley_DgnPlatform_ReportDefinitionNode_GetSortingGroupNode =R"doc(Returns the node which holds this report definition's sorting rules)doc";

static const char * __doc_Bentley_DgnPlatform_ReportDefinitionNode_GetColumnGroupNode =R"doc(Returns the node which holds this report definition's column
definitions)doc";

static const char * __doc_Bentley_DgnPlatform_ReportDefinitionNode_GetColumnCount =R"doc(Returns the number of columns defined for this report definition)doc";

static const char * __doc_Bentley_DgnPlatform_ReportDefinitionNode_Import =R"doc(Imports this definition into the specified DgnFile, renaming it if
necessary)doc";

static const char * __doc_Bentley_DgnPlatform_ReportDefinitionNode_GetCategory =R"doc(Returns the category node containing this report definition)doc";

static const char * __doc_Bentley_DgnPlatform_ReportDefinitionNode_IsReferenced =R"doc(Returns true if any TextTable elements exist with an association to
this report definition)doc";

static const char * __doc_Bentley_DgnPlatform_ReportDefinitionNode_GetScopeType =R"doc(Returns the type of this report definition's scope.)doc";

static const char * __doc_Bentley_DgnPlatform_ReportScope_SetIncludeItemTypeOption =R"doc(Set SetIncludeItemTypeOption which is used for selecting used or
all/unreferenced classes for report.

:param includeItemTypeOption:
    the IncludeItemTypeOption to be set)doc";

static const char * __doc_Bentley_DgnPlatform_ReportScope_GetIncludeItemTypeOption =R"doc(Get IncludeItemTypeOption which is used for selecting used or
all/unreferenced classes for report. Returns the IncludeItemTypeOption)doc";

static const char * __doc_Bentley_DgnPlatform_ReportScope_SetSelectionScopeOption =R"doc(Set SelectionScopeOption which is used for report all, by fence, or by
current selection

:param selectionScopeOption:
    the SelectionScopeOption to be set)doc";

static const char * __doc_Bentley_DgnPlatform_ReportScope_GetSelectionScopeOption =R"doc(Get SelectionScopeOption which is used for report all, by fence, or by
current selection Returns the SelectionScopeOption)doc";

static const char * __doc_Bentley_DgnPlatform_ReportScope_SetIncludeChildElements =R"doc(Sets whether public children of complex elements will be searched when
populating report results)doc";

static const char * __doc_Bentley_DgnPlatform_ReportScope_SetReferencedModelOption =R"doc(Sets how reference attachments will be searched for
ReportScope::Type::Model)doc";

static const char * __doc_Bentley_DgnPlatform_ReportScope_IncludesChildElements =R"doc(Returns whether public children of complex elements will be searched
when populating report results)doc";

static const char * __doc_Bentley_DgnPlatform_ReportScope_GetReferencedModelOption =R"doc(Returns the options for searching reference attachments for
ReportScope::Type::Model)doc";

static const char * __doc_Bentley_DgnPlatform_ReportScope_GetQualifier =R"doc(Returns the " location qualifier " associated with this scope's
location. Usually the name of a DgnModel.)doc";

static const char * __doc_Bentley_DgnPlatform_ReportScope_GetLocation =R"doc(Returns the location associated with this scope)doc";

static const char * __doc_Bentley_DgnPlatform_ReportScope_GetType =R"doc(Returns the type of this ReportScope)doc";

static const char * __doc_Bentley_DgnPlatform_ReportScope_InitForModel =R"doc(Initializes a ReportScope for a specific model identified by name. If
moniker is null, refers to the active file.)doc";

static const char * __doc_Bentley_DgnPlatform_ReportScope_InitForDefaultModel =R"doc(Initializes a ReportScope for the default model. If moniker is null,
refers to the active file.)doc";

static const char * __doc_Bentley_DgnPlatform_ReportScope_InitForActiveModel =R"doc(Initializes a ReportScope for the active model)doc";

static const char * __doc_Bentley_DgnPlatform_ReportScope_InitForFile =R"doc(Initializes a ReportScope based on the active file (if moniker is
null), or the file specified by the moniker)doc";

static const char * __doc_Bentley_DgnPlatform_ReportScope_InitForPath =R"doc(Initializes a path-based ReportScope for the specified configuration
variable expression)doc";

static const char * __doc_Bentley_DgnPlatform_DgnECHostSpecification_SetRelationships =R"doc(Sets the specifications for ECInstances related to the primary
ECInstances to also be included in the report results)doc";

static const char * __doc_Bentley_DgnPlatform_DgnECHostSpecification_GetRelationships =R"doc(Returns the list of specifications for ECInstances related to the
primary ECInstances to also be included in the report results)doc";

static const char * __doc_Bentley_DgnPlatform_DgnECHostSpecification_SetPrimaryClasses =R"doc(Sets the schema and class names of the primary ECInstances from which
the report results will be populated)doc";

static const char * __doc_Bentley_DgnPlatform_DgnECHostSpecification_GetPrimaryClasses =R"doc(Returns the schema and class names of the primary ECInstances)doc";

static const char * __doc_Bentley_DgnPlatform_DgnECHostRelationshipSpecification_SetDirection =R"doc(Sets the direction in which the ECRelationship will be queried)doc";

static const char * __doc_Bentley_DgnPlatform_DgnECHostRelationshipSpecification_GetDirection =R"doc(Returns the direction in which the ECRelationship will be queried)doc";

static const char * __doc_Bentley_DgnPlatform_DgnECHostRelationshipSpecification_SetRelationshipPolymorphic =R"doc(Sets whether ECRelationships will be queried polymorphically)doc";

static const char * __doc_Bentley_DgnPlatform_DgnECHostRelationshipSpecification_IsRelationshipPolymorphic =R"doc(Returns whether ECRelationships will be queried polymorphically)doc";

static const char * __doc_Bentley_DgnPlatform_DgnECHostRelationshipSpecification_SetRelatedPolymorphic =R"doc(Sets whether related ECInstances will be queried polymorphically)doc";

static const char * __doc_Bentley_DgnPlatform_DgnECHostRelationshipSpecification_IsRelatedPolymorphic =R"doc(Returns whether related ECInstances will be queried polymorphically)doc";

static const char * __doc_Bentley_DgnPlatform_DgnECHostRelationshipSpecification_SetRequired =R"doc(Sets whether failure to find a related ECInstance matching this
specification will exclude the source ECInstance from the report
results)doc";

static const char * __doc_Bentley_DgnPlatform_DgnECHostRelationshipSpecification_IsRequired =R"doc(Returns whether the source ECInstance will be excluded if this
specification fails to find a related ECInstance)doc";

static const char * __doc_Bentley_DgnPlatform_DgnECHostRelationshipSpecification_SetNestedSpecification =R"doc(Sets specifications for any ECInstances related to this ECInstance
which should be included in the report definition)doc";

static const char * __doc_Bentley_DgnPlatform_DgnECHostRelationshipSpecification_GetNestedSpecification =R"doc(Returns the specifications for any ECInstances related to this related
ECInstance which should be included in the report definition.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnECHostRelationshipSpecification_SetRelatedClass =R"doc(Sets the schema and class name of the related ECInstance)doc";

static const char * __doc_Bentley_DgnPlatform_DgnECHostRelationshipSpecification_GetRelatedClass =R"doc(Returns the schema and class name of the related ECClass)doc";

static const char * __doc_Bentley_DgnPlatform_DgnECHostRelationshipSpecification_SetRelationshipClass =R"doc(Sets the schema and class name of the ECRelationshipClass)doc";

static const char * __doc_Bentley_DgnPlatform_DgnECHostRelationshipSpecification_GetRelationshipClass =R"doc(Returns the schema and class name of the ECRelationshipClass)doc";

static const char * __doc_Bentley_DgnPlatform_ColumnDefinitionNode_GetArraySortingOptions =R"doc(Returns the options which will be used to sort within array values for
ArrayOption::AllMembers or ArrayOption::List)doc";

static const char * __doc_Bentley_DgnPlatform_ColumnDefinitionNode_GetFormattingOptions =R"doc(Returns the options which will be used to format values in this column
for display)doc";

static const char * __doc_Bentley_DgnPlatform_ColumnDefinitionNode_SetAccessors =R"doc(Sets the list of accessors from which this column will obtain its
values)doc";

static const char * __doc_Bentley_DgnPlatform_ColumnDefinitionNode_GetAccessors =R"doc(Returns the list of accessors from which this column will obtain its
values)doc";

static const char * __doc_Bentley_DgnPlatform_ColumnDefinitionNode_GetNumAccessors =R"doc(Returns the number of accessors (ECPropertyValues) associated with
this column.)doc";

static const char * __doc_Bentley_DgnPlatform_ReportColumnAccessor_GetArrayAccessors =R"doc(Returns the list of accessors for struct array members.)doc";

static const char * __doc_Bentley_DgnPlatform_ReportColumnAccessor_GetArrayOption =R"doc(Returns the options for handling the root ECPropertyValue as an array
property)doc";

static const char * __doc_Bentley_DgnPlatform_ReportColumnAccessor_GetAccessor =R"doc(Returns the accessor for the root ECPropertyValue)doc";

static const char * __doc_Bentley_DgnPlatform_SortingRuleNode_SetHideDuplicateValues =R"doc(Sets whether successive rows with identical values will be shown as
empty)doc";

static const char * __doc_Bentley_DgnPlatform_SortingRuleNode_HideDuplicateValues =R"doc(Returns whether successive rows with identical values will be shown as
empty)doc";

static const char * __doc_Bentley_DgnPlatform_SortingRuleNode_SetApplyBeforeFormatting =R"doc(Sets whether the values are sorted by their internal values, or their
(string) display values)doc";

static const char * __doc_Bentley_DgnPlatform_SortingRuleNode_ApplyBeforeFormatting =R"doc(Returns whether the values are sorted by their internal values, or
their (string) display values)doc";

static const char * __doc_Bentley_DgnPlatform_SortingRuleNode_SetCaseSensitive =R"doc(Sets whether the sorting is applied with case-sensitivity.)doc";

static const char * __doc_Bentley_DgnPlatform_SortingRuleNode_IsCaseSensitive =R"doc(Returns whether the sorting is applied with case-sensitivity)doc";

static const char * __doc_Bentley_DgnPlatform_SortingRuleNode_SetAscending =R"doc(Sets whether the sorting is performed in ascending order)doc";

static const char * __doc_Bentley_DgnPlatform_SortingRuleNode_IsAscending =R"doc(Returns whether the sorting is performed in ascending order)doc";

static const char * __doc_Bentley_DgnPlatform_SortingRuleNode_SetColumnName =R"doc(Sets the name of the column to which this sorting rule applies)doc";

static const char * __doc_Bentley_DgnPlatform_SortingRuleNode_GetColumnName =R"doc(Returns the name of the column to which this sorting rule applies)doc";

static const char * __doc_Bentley_DgnPlatform_ECReportNode_FromXDataTreeNode =R"doc(Extracts an ECReportNode from an XDataTreeNode)doc";

static const char * __doc_Bentley_DgnPlatform_ECReportNode_FindByElementId =R"doc(Locates a node by its ID)doc";

static const char * __doc_Bentley_DgnPlatform_ECReportNode_GetAssociatedReportDefinition =R"doc(Returns the ReportDefinitionNode associated with this node, or nullptr
if this is a category node.)doc";

static const char * __doc_Bentley_DgnPlatform_ECReportNode_GetDgnFile =R"doc(Returns the DgnFile in which this node resides)doc";

static const char * __doc_Bentley_DgnPlatform_ECReportNode_GetDisplayLabel =R"doc(Returns the display label for this node)doc";

static const char * __doc_Bentley_DgnPlatform_ECReportNode_GetChildByName =R"doc(Returns the child node with the specified name)doc";

static const char * __doc_Bentley_DgnPlatform_ECReportNode_GetChildNodes =R"doc(Returns a list of this node's child nodes)doc";

static const char * __doc_Bentley_DgnPlatform_ECReportNode_GetNodeType =R"doc(Returns the type of this node)doc";

static const char * __doc_Bentley_DgnPlatform_ECReportNode_GetParentNode =R"doc(Returns the parent of this node, if any)doc";

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_ECReportNode(py::module_& m)
    {
    //===================================================================================
    // enum class ECReportNodeType
    py::enum_< ECReportNodeType>(m, "ECReportNodeType")
        .value("eUnknown", ECReportNodeType::Unknown)
        .value("eCategory", ECReportNodeType::Category)
        .value("eReportDefinition", ECReportNodeType::ReportDefinition)
        .value("eColumnGroup", ECReportNodeType::ColumnGroup)
        .value("eSortingGroup", ECReportNodeType::SortingGroup)
        .value("eColumnDefinition", ECReportNodeType::ColumnDefinition)
        .value("eSortingRule", ECReportNodeType::SortingRule)
        .export_values();

    //===================================================================================
    // enum class ECReportNodeEventType

    //===================================================================================
    // struct ECReportNode
    py::class_< ECReportNode, ECReportNodePtr, XDataTreeNode> c3(m, "ECReportNode");
    py::bind_vector<bvector< ECReportNodePtr>>(m, "ECReportNodePtrArray", py::module_local(false));

    c3.def_property_readonly("ParentNode", py::overload_cast<>(&ECReportNode::GetParentNode));
    c3.def("GetParentNode", py::overload_cast<>(&ECReportNode::GetParentNode), DOC(Bentley, DgnPlatform, ECReportNode, GetParentNode));
    
    c3.def_property_readonly("NodeType", py::overload_cast<>(&ECReportNode::GetNodeType, py::const_));
    c3.def("GetNodeType", py::overload_cast<>(&ECReportNode::GetNodeType, py::const_), DOC(Bentley, DgnPlatform, ECReportNode, GetNodeType));
    
    c3.def_property_readonly("ChildNodes", &ECReportNode::GetChildNodes);
    c3.def("GetChildNodes", &ECReportNode::GetChildNodes, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, ECReportNode, GetChildNodes));
    
    c3.def("GetChildByName", &ECReportNode::GetChildByName, "name"_a, DOC(Bentley, DgnPlatform, ECReportNode, GetChildByName));
    
    c3.def_property_readonly("DisplayLabel", &ECReportNode::GetDisplayLabel);
    c3.def("GetDisplayLabel", &ECReportNode::GetDisplayLabel, DOC(Bentley, DgnPlatform, ECReportNode, GetDisplayLabel));
    
    c3.def_property_readonly("DgnFile", &ECReportNode::GetDgnFile);
    c3.def("GetDgnFile", &ECReportNode::GetDgnFile, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, ECReportNode, GetDgnFile));
    
    c3.def_property_readonly("AssociatedReportDefinition", &ECReportNode::GetAssociatedReportDefinition);
    c3.def("GetAssociatedReportDefinition", &ECReportNode::GetAssociatedReportDefinition, DOC(Bentley, DgnPlatform, ECReportNode, GetAssociatedReportDefinition));
    
    c3.def_static("FindByElementId", py::overload_cast<ElementId, DgnFileR>(&ECReportNode::FindByElementId), "elemId"_a, "dgnFile"_a, DOC(Bentley, DgnPlatform, ECReportNode, FindByElementId));
    c3.def_static("FindByElementId", py::overload_cast<ElementId, XDataTreeOwnerR>(&ECReportNode::FindByElementId), "elemId"_a, "owner"_a, DOC(Bentley, DgnPlatform, ECReportNode, FindByElementId));
    c3.def_static("FromXDataTreeNode", &ECReportNode::FromXDataTreeNode, "node"_a, DOC(Bentley, DgnPlatform, ECReportNode, FromXDataTreeNode));

    //===================================================================================
    // struct SortingRuleNode
    py::class_< SortingRuleNode, SortingRuleNodePtr, ECReportNode> c4(m, "SortingRuleNode");
    py::bind_vector<bvector< SortingRuleNodePtr>>(m, "SortingRuleNodePtrArray", py::module_local(false));

    c4.def(py::init(&SortingRuleNode::From), "node"_a);
    
    c4.def_property("ColumnName", &SortingRuleNode::GetColumnName, &SortingRuleNode::SetColumnName);
    c4.def("GetColumnName", &SortingRuleNode::GetColumnName, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, SortingRuleNode, GetColumnName));
    c4.def("SetColumnName", &SortingRuleNode::SetColumnName, "name"_a, DOC(Bentley, DgnPlatform, SortingRuleNode, SetColumnName));
    
    c4.def_property("Ascending", &SortingRuleNode::IsAscending, &SortingRuleNode::SetAscending);
    c4.def("IsAscending", &SortingRuleNode::IsAscending, DOC(Bentley, DgnPlatform, SortingRuleNode, IsAscending));
    c4.def("SetAscending", &SortingRuleNode::SetAscending, "ascending"_a, DOC(Bentley, DgnPlatform, SortingRuleNode, SetAscending));
    
    c4.def_property("CaseSensitive", &SortingRuleNode::IsCaseSensitive, &SortingRuleNode::SetCaseSensitive);
    c4.def("IsCaseSensitive", &SortingRuleNode::IsCaseSensitive, DOC(Bentley, DgnPlatform, SortingRuleNode, IsCaseSensitive));
    c4.def("SetCaseSensitive", &SortingRuleNode::SetCaseSensitive, "sensitive"_a, DOC(Bentley, DgnPlatform, SortingRuleNode, SetCaseSensitive));
    
    c4.def_property("IsApplyBeforeFormatting", &SortingRuleNode::ApplyBeforeFormatting, &SortingRuleNode::SetApplyBeforeFormatting);
    c4.def("ApplyBeforeFormatting", &SortingRuleNode::ApplyBeforeFormatting, DOC(Bentley, DgnPlatform, SortingRuleNode, ApplyBeforeFormatting));
    c4.def("SetApplyBeforeFormatting", &SortingRuleNode::SetApplyBeforeFormatting, "apply"_a, DOC(Bentley, DgnPlatform, SortingRuleNode, SetApplyBeforeFormatting));
    
    c4.def_property("IsHideDuplicateValues", &SortingRuleNode::HideDuplicateValues, &SortingRuleNode::SetHideDuplicateValues);
    c4.def("HideDuplicateValues", &SortingRuleNode::HideDuplicateValues, DOC(Bentley, DgnPlatform, SortingRuleNode, HideDuplicateValues));
    c4.def("SetHideDuplicateValues", &SortingRuleNode::SetHideDuplicateValues, "hide"_a, DOC(Bentley, DgnPlatform, SortingRuleNode, SetHideDuplicateValues));

    //===================================================================================
    // struct ReportColumnAccessor
    py::class_< ReportColumnAccessor> c5(m, "ReportColumnAccessor");
    py::bind_vector<bvector< ReportColumnAccessor>>(m, "ReportColumnAccessorArray", py::module_local(false));

    if (true)
        {
        //===================================================================================
        // enum class ArrayOption
        py::enum_< ReportColumnAccessor::ArrayOption>(c5, "ArrayOption")
            .value("eAllMembers", ReportColumnAccessor::ArrayOption::AllMembers)
            .value("eFirst", ReportColumnAccessor::ArrayOption::First)
            .value("eLast", ReportColumnAccessor::ArrayOption::Last)
            .value("eCount", ReportColumnAccessor::ArrayOption::Count)
            .value("eList", ReportColumnAccessor::ArrayOption::List)
            .value("eNone", ReportColumnAccessor::ArrayOption::None)
            .export_values();

        //===================================================================================
        // struct ArrayAccessor
        py::class_< ReportColumnAccessor::ArrayAccessor> c5_1(c5, "ArrayAccessor");
        py::bind_vector<bvector< ReportColumnAccessor::ArrayAccessor>>(m, "ArrayAccessorArray", py::module_local(false));

        c5_1.def(py::init<>());
        c5_1.def(py::init<WCharCP, ReportColumnAccessor::ArrayOption>(), "memberAccessor"_a, "option"_a = ReportColumnAccessor::ArrayOption::None);
        
        c5_1.def_property_readonly("Option", &ReportColumnAccessor::ArrayAccessor::GetOption);
        c5_1.def("GetOption", &ReportColumnAccessor::ArrayAccessor::GetOption);

        c5_1.def_property_readonly("AccessString", &ReportColumnAccessor::ArrayAccessor::GetAccessString);
        c5_1.def("GetAccessString", &ReportColumnAccessor::ArrayAccessor::GetAccessString, py::return_value_policy::reference_internal);
        }

    c5.def(py::init<>());
    c5.def(py::init<ECN::QualifiedECAccessorCR, ReportColumnAccessor::ArrayOption>(), "accessor"_a, "option"_a = ReportColumnAccessor::ArrayOption::None);
    c5.def(py::init<WCharCP, WCharCP, WCharCP, ReportColumnAccessor::ArrayOption>(), "schemaName"_a, "className"_a, "accessString"_a, "option"_a = ReportColumnAccessor::ArrayOption::None);
    
    c5.def_property_readonly("Accessor", py::overload_cast<>(&ReportColumnAccessor::GetAccessor));
    c5.def("GetAccessor", py::overload_cast<>(&ReportColumnAccessor::GetAccessor), py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, ReportColumnAccessor, GetAccessor));
    
    c5.def("GetArrayOption", &ReportColumnAccessor::GetArrayOption, DOC(Bentley, DgnPlatform, ReportColumnAccessor, GetArrayOption));
    
    c5.def_property_readonly("ArrayAccessors", py::overload_cast<>(&ReportColumnAccessor::GetArrayAccessors));
    c5.def("GetArrayAccessors", py::overload_cast<>(&ReportColumnAccessor::GetArrayAccessors), py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, ReportColumnAccessor, GetArrayAccessors));

    //===================================================================================
    // struct ColumnDefinitionNode
    py::class_< ColumnDefinitionNode, ColumnDefinitionNodePtr, ECReportNode> c6(m, "ColumnDefinitionNode");
    py::bind_vector<bvector< ColumnDefinitionNodePtr>>(m, "ColumnDefinitionNodePtrArray", py::module_local(false));

    c6.def(py::init(&ColumnDefinitionNode::From), "node"_a);
    
    c6.def_property_readonly("NumAccessors", &ColumnDefinitionNode::GetNumAccessors);
    c6.def("GetNumAccessors", &ColumnDefinitionNode::GetNumAccessors, DOC(Bentley, DgnPlatform, ColumnDefinitionNode, GetNumAccessors));

    c6.def_property("Accessors", &ColumnDefinitionNode::GetAccessors, &ColumnDefinitionNode::SetAccessors);
    c6.def("GetAccessors", &ColumnDefinitionNode::GetAccessors, DOC(Bentley, DgnPlatform, ColumnDefinitionNode, GetAccessors));
    c6.def("SetAccessors", &ColumnDefinitionNode::SetAccessors, "accessors"_a, DOC(Bentley, DgnPlatform, ColumnDefinitionNode, SetAccessors));

    c6.def("GetFormattingOptions", py::overload_cast<bool>(&ColumnDefinitionNode::GetFormattingOptions), "createIfNotFound"_a, DOC(Bentley, DgnPlatform, ColumnDefinitionNode, GetFormattingOptions));
    c6.def("GetFormattingOptions", py::overload_cast<>(&ColumnDefinitionNode::GetFormattingOptions, py::const_), py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, ColumnDefinitionNode, GetFormattingOptions));
    c6.def("GetArraySortingOptions", py::overload_cast<bool>(&ColumnDefinitionNode::GetArraySortingOptions), "createIfNotFound"_a, DOC(Bentley, DgnPlatform, ColumnDefinitionNode, GetArraySortingOptions));
    c6.def("GetArraySortingOptions", py::overload_cast<>(&ColumnDefinitionNode::GetArraySortingOptions, py::const_), py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, ColumnDefinitionNode, GetArraySortingOptions));
    c6.def_property("GetListDelimiter", &ColumnDefinitionNode::GetListDelimiter, &ColumnDefinitionNode::SetListDelimiter);

    //===================================================================================
    // struct DgnECHostRelationshipSpecification
    py::class_< DgnECHostRelationshipSpecification> c7(m, "DgnECHostRelationshipSpecification");
    py::bind_vector<bvector< DgnECHostRelationshipSpecification>>(m, "DgnECHostRelationshipSpecificationArray", py::module_local(false));

    if (true)
        {
        //===================================================================================
        // enum Flags
        py::enum_< DgnECHostRelationshipSpecification::Flags>(c7, "Flags", py::arithmetic())
            .value("ekFlag_Required", DgnECHostRelationshipSpecification::kFlag_Required)
            .value("ekFlag_Backward", DgnECHostRelationshipSpecification::kFlag_Backward)
            .value("ekFlag_RelatedPolymorphic", DgnECHostRelationshipSpecification::kFlag_RelatedPolymorphic)
            .value("ekFlag_RelationshipPolymorphic", DgnECHostRelationshipSpecification::kFlag_RelationshipPolymorphic)
            .value("ekFlags_None", DgnECHostRelationshipSpecification::kFlags_None)
            .value("ekFlags_Default", DgnECHostRelationshipSpecification::kFlags_Default)
            .export_values();
        }

    c7.def(py::init<ECN::SchemaNameClassNamePairCR, ECN::SchemaNameClassNamePairCR, ECN::ECRelatedInstanceDirection, bool, bool, bool>(),
           "relationship"_a, "related"_a, "dir"_a = ECN::STRENGTHDIRECTION_Forward, "required"_a = false, "relationshipPolymorphic"_a = true, "relatedPolymorphic"_a = true);

    c7.def(py::init<DgnECHostRelationshipSpecificationCR>(), "rhs"_a);
    c7.def(py::init<>());

    c7.def_property("RelationshipClass", &DgnECHostRelationshipSpecification::GetRelationshipClass, py::cpp_function(&DgnECHostRelationshipSpecification::SetRelationshipClass, py::keep_alive<1, 2>()));
    c7.def("GetRelationshipClass", &DgnECHostRelationshipSpecification::GetRelationshipClass, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, DgnECHostRelationshipSpecification, GetRelationshipClass));
    c7.def("SetRelationshipClass", &DgnECHostRelationshipSpecification::SetRelationshipClass, "pair"_a, py::keep_alive<1, 2>(), DOC(Bentley, DgnPlatform, DgnECHostRelationshipSpecification, SetRelationshipClass));
    
    c7.def_property("RelatedClass", &DgnECHostRelationshipSpecification::GetRelatedClass, py::cpp_function(&DgnECHostRelationshipSpecification::SetRelatedClass, py::keep_alive<1, 2>()));
    c7.def("GetRelatedClass", &DgnECHostRelationshipSpecification::GetRelatedClass, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, DgnECHostRelationshipSpecification, GetRelatedClass));
    c7.def("SetRelatedClass", &DgnECHostRelationshipSpecification::SetRelatedClass, "pair"_a, py::keep_alive<1, 2>(), DOC(Bentley, DgnPlatform, DgnECHostRelationshipSpecification, SetRelatedClass));
    
    c7.def_property("NestedSpecification", &DgnECHostRelationshipSpecification::GetNestedSpecification, py::cpp_function(&DgnECHostRelationshipSpecification::SetNestedSpecification, py::keep_alive<1, 2>()));
    c7.def("GetNestedSpecification", &DgnECHostRelationshipSpecification::GetNestedSpecification, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, DgnECHostRelationshipSpecification, GetNestedSpecification));
    c7.def("SetNestedSpecification", &DgnECHostRelationshipSpecification::SetNestedSpecification, "spec"_a, py::keep_alive<1, 2>(), DOC(Bentley, DgnPlatform, DgnECHostRelationshipSpecification, SetNestedSpecification));
    
    c7.def("IsRequired", &DgnECHostRelationshipSpecification::IsRequired, DOC(Bentley, DgnPlatform, DgnECHostRelationshipSpecification, IsRequired));
    c7.def("SetRequired", &DgnECHostRelationshipSpecification::SetRequired, "required"_a, DOC(Bentley, DgnPlatform, DgnECHostRelationshipSpecification, SetRequired));
    
    c7.def("IsRelatedPolymorphic", &DgnECHostRelationshipSpecification::IsRelatedPolymorphic, DOC(Bentley, DgnPlatform, DgnECHostRelationshipSpecification, IsRelatedPolymorphic));
    c7.def("SetRelatedPolymorphic", &DgnECHostRelationshipSpecification::SetRelatedPolymorphic, "poly"_a, DOC(Bentley, DgnPlatform, DgnECHostRelationshipSpecification, SetRelatedPolymorphic));
    
    c7.def("IsRelationshipPolymorphic", &DgnECHostRelationshipSpecification::IsRelationshipPolymorphic, DOC(Bentley, DgnPlatform, DgnECHostRelationshipSpecification, IsRelationshipPolymorphic));
    c7.def("SetRelationshipPolymorphic", &DgnECHostRelationshipSpecification::SetRelationshipPolymorphic, "poly"_a, DOC(Bentley, DgnPlatform, DgnECHostRelationshipSpecification, SetRelationshipPolymorphic));
    
    c7.def_property("Direction", &DgnECHostRelationshipSpecification::GetDirection, &DgnECHostRelationshipSpecification::SetDirection);
    c7.def("GetDirection", &DgnECHostRelationshipSpecification::GetDirection, DOC(Bentley, DgnPlatform, DgnECHostRelationshipSpecification, GetDirection));
    c7.def("SetDirection", &DgnECHostRelationshipSpecification::SetDirection, "dir"_a, DOC(Bentley, DgnPlatform, DgnECHostRelationshipSpecification, SetDirection));

    //===================================================================================
    // struct DgnECHostSpecification
    py::class_< DgnECHostSpecification> c8(m, "DgnECHostSpecification");
    py::bind_vector<bvector< DgnECHostSpecification>>(m, "DgnECHostSpecificationArray", py::module_local(false));

    c8.def(py::init<>());
    c8.def_property("PrimaryClasses", py::overload_cast<>(&DgnECHostSpecification::GetPrimaryClasses), py::cpp_function(&DgnECHostSpecification::SetPrimaryClasses, py::keep_alive<1, 2>()));
    c8.def("GetPrimaryClasses", py::overload_cast<>(&DgnECHostSpecification::GetPrimaryClasses), py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, DgnECHostSpecification, GetPrimaryClasses));
    c8.def("SetPrimaryClasses", &DgnECHostSpecification::SetPrimaryClasses, "classes"_a, py::keep_alive<1, 2>(), DOC(Bentley, DgnPlatform, DgnECHostSpecification, SetPrimaryClasses));

    c8.def_property("Relationships", py::overload_cast<>(&DgnECHostSpecification::GetRelationships), py::cpp_function(&DgnECHostSpecification::SetRelationships, py::keep_alive<1, 2>()));
    c8.def("GetRelationships", py::overload_cast<>(&DgnECHostSpecification::GetRelationships), py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, DgnECHostSpecification, GetRelationships));
    c8.def("SetRelationships", &DgnECHostSpecification::SetRelationships, "rels"_a, py::keep_alive<1, 2>(), DOC(Bentley, DgnPlatform, DgnECHostSpecification, SetRelationships));

    //===================================================================================
    // struct DgnECHostSpecificationsContext
    py::class_< DgnECHostSpecificationsContext> c9(m, "DgnECHostSpecificationsContext");

    c9.def(py::init<DgnECHostSpecificationListCR>(), "hostSpecs"_a);

    //===================================================================================
    // struct ReportScope
    py::class_< ReportScope> c10(m, "ReportScope");

    if (true)
        {
        //===================================================================================
        // enum class Type
        py::enum_<ReportScope::Type>(c10, "Type")
            .value("eModel", ReportScope::Type::Model)
            .value("eFile", ReportScope::Type::File)
            .value("ePath", ReportScope::Type::Path)
            .export_values();

        //===================================================================================
        // enum class ReferencedModelOption
        py::enum_<ReportScope::ReferencedModelOption>(c10, "ReferencedModelOption")
            .value("eAll", ReportScope::ReferencedModelOption::All)
            .value("eNone", ReportScope::ReferencedModelOption::None)
            .export_values();

        //===================================================================================
        // enum class SelectionScopeOption
        py::enum_<ReportScope::SelectionScopeOption>(c10, "SelectionScopeOption")
            .value("eAll", ReportScope::SelectionScopeOption::All)
            .value("eByFence", ReportScope::SelectionScopeOption::ByFence)
            .value("eCurrentSelection", ReportScope::SelectionScopeOption::CurrentSelection)
            .export_values();

        //===================================================================================
        // enum class IncludeItemTypeOption
        py::enum_<ReportScope::IncludeItemTypeOption>(c10, "IncludeItemTypeOption")
            .value("eIncludeUsedClasses", ReportScope::IncludeItemTypeOption::IncludeUsedClasses)
            .value("eIncludeAllClasses", ReportScope::IncludeItemTypeOption::IncludeAllClasses)
            .export_values();

        //===================================================================================
        // enum class ReportSummaryOption
        py::enum_<ReportScope::ReportSummaryOption>(c10, "ReportSummaryOption")
            .value("eShow", ReportScope::ReportSummaryOption::Show)
            .value("eHide", ReportScope::ReportSummaryOption::Hide)
            .export_values();
        }

    c10.def(py::init<>());
    c10.def("InitForPath", &ReportScope::InitForPath, "cfgVarExpression"_a, DOC(Bentley, DgnPlatform, ReportScope, InitForPath));
    c10.def("InitForFile", &ReportScope::InitForFile, "moniker"_a, DOC(Bentley, DgnPlatform, ReportScope, InitForFile));
    c10.def("InitForActiveModel", &ReportScope::InitForActiveModel, "refOut"_a = ReportScope::ReferencedModelOption::None, DOC(Bentley, DgnPlatform, ReportScope, InitForActiveModel));
    c10.def("InitForDefaultModel", &ReportScope::InitForDefaultModel, "moniker"_a, "refOut"_a = ReportScope::ReferencedModelOption::None, DOC(Bentley, DgnPlatform, ReportScope, InitForDefaultModel));
    c10.def("InitForModel", &ReportScope::InitForModel, "modelName"_a, "moniker"_a, "refOut"_a = ReportScope::ReferencedModelOption::None, DOC(Bentley, DgnPlatform, ReportScope, InitForModel));
    
    c10.def("GetType", &ReportScope::GetType, DOC(Bentley, DgnPlatform, ReportScope, GetType));
    
    c10.def_property_readonly("Location", &ReportScope::GetLocation);
    c10.def("GetLocation", &ReportScope::GetLocation, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, ReportScope, GetLocation));
    
    c10.def_property_readonly("Qualifier", &ReportScope::GetQualifier);
    c10.def("GetQualifier", &ReportScope::GetQualifier, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, ReportScope, GetQualifier));
    
    c10.def("GetReferencedModelOption", &ReportScope::GetReferencedModelOption, DOC(Bentley, DgnPlatform, ReportScope, GetReferencedModelOption));
    
    c10.def("IncludesChildElements", &ReportScope::IncludesChildElements, DOC(Bentley, DgnPlatform, ReportScope, IncludesChildElements));    
    c10.def("SetReferencedModelOption", &ReportScope::SetReferencedModelOption, "opt"_a, DOC(Bentley, DgnPlatform, ReportScope, SetReferencedModelOption));
    c10.def("SetIncludeChildElements", &ReportScope::SetIncludeChildElements, "include"_a, DOC(Bentley, DgnPlatform, ReportScope, SetIncludeChildElements));
    
    c10.def("GetSelectionScopeOption", &ReportScope::GetSelectionScopeOption, DOC(Bentley, DgnPlatform, ReportScope, GetSelectionScopeOption));
    c10.def("SetSelectionScopeOption", &ReportScope::SetSelectionScopeOption, "options"_a, DOC(Bentley, DgnPlatform, ReportScope, SetSelectionScopeOption));
    
    c10.def("GetIncludeItemTypeOption", &ReportScope::GetIncludeItemTypeOption, DOC(Bentley, DgnPlatform, ReportScope, GetIncludeItemTypeOption));
    c10.def("SetIncludeItemTypeOption", &ReportScope::SetIncludeItemTypeOption, "options"_a, DOC(Bentley, DgnPlatform, ReportScope, SetIncludeItemTypeOption));

    //===================================================================================
    // struct ReportDefinitionNode
    py::class_< ReportDefinitionNode, ReportDefinitionNodePtr, ECReportNode> c11(m, "ReportDefinitionNode");


    c11.def(py::init(&ReportDefinitionNode::From), "node"_a, DOC(Bentley, DgnPlatform, ReportDefinitionNode, From));

    c11.def_property_readonly("ScopeType", &ReportDefinitionNode::GetScopeType);
    c11.def("GetScopeType", &ReportDefinitionNode::GetScopeType, DOC(Bentley, DgnPlatform, ReportDefinitionNode, GetScopeType));
    
    c11.def("IsReferenced", &ReportDefinitionNode::IsReferenced, DOC(Bentley, DgnPlatform, ReportDefinitionNode, IsReferenced));
    
    c11.def_property_readonly("Category", &ReportDefinitionNode::GetCategory);
    c11.def("GetCategory", &ReportDefinitionNode::GetCategory, DOC(Bentley, DgnPlatform, ReportDefinitionNode, GetCategory));
    
    c11.def("Import", &ReportDefinitionNode::Import, "destDgnFile"_a, "renameIfNecessary"_a, DOC(Bentley, DgnPlatform, ReportDefinitionNode, Import));
    
    c11.def_property_readonly("ColumnCount", &ReportDefinitionNode::GetColumnCount);
    c11.def("GetColumnCount", &ReportDefinitionNode::GetColumnCount, DOC(Bentley, DgnPlatform, ReportDefinitionNode, GetColumnCount));

    c11.def("GetColumnGroupNode", py::overload_cast<bool>(&ReportDefinitionNode::GetColumnGroupNode), "createIfNotFound"_a, DOC(Bentley, DgnPlatform, ReportDefinitionNode, GetColumnGroupNode));
    c11.def("GetSortingGroupNode", py::overload_cast<bool>(&ReportDefinitionNode::GetSortingGroupNode), "createIfNotFound"_a, DOC(Bentley, DgnPlatform, ReportDefinitionNode, GetSortingGroupNode));
    c11.def("GetColumnGroupNode", [] (ReportDefinitionNode const& self) { return ColumnGroupNodePtr(const_cast<ColumnGroupNodeP>(self.GetColumnGroupNode())); });
    c11.def("GetSortingGroupNode", [] (ReportDefinitionNode const& self) { return SortingGroupNodePtr(const_cast<SortingGroupNodeP>(self.GetSortingGroupNode())); });
    c11.def("CreateColumnDefinition", &ReportDefinitionNode::CreateColumnDefinition, "name"_a, "sortPriority"_a, DOC(Bentley, DgnPlatform, ReportDefinitionNode, CreateColumnDefinition));
    c11.def("CreateSortingRule", &ReportDefinitionNode::CreateSortingRule, "columnName"_a, "sortPriority"_a, DOC(Bentley, DgnPlatform, ReportDefinitionNode, CreateSortingRule));
    c11.def("GetColumnByName", py::overload_cast<WCharCP>(&ReportDefinitionNode::GetColumnByName), "name"_a, DOC(Bentley, DgnPlatform, ReportDefinitionNode, GetColumnByName));
    c11.def("GetHostSpecifications", &ReportDefinitionNode::GetHostSpecifications, "specs"_a, DOC(Bentley, DgnPlatform, ReportDefinitionNode, GetHostSpecifications));
    c11.def("SetHostSpecifications", &ReportDefinitionNode::SetHostSpecifications, "specs"_a, DOC(Bentley, DgnPlatform, ReportDefinitionNode, SetHostSpecifications));
    c11.def("GetScope", py::overload_cast<>(&ReportDefinitionNode::GetScope, py::const_), DOC(Bentley, DgnPlatform, ReportDefinitionNode, GetScope));
    c11.def("SetScope", &ReportDefinitionNode::SetScope, "scope"_a, DOC(Bentley, DgnPlatform, ReportDefinitionNode, SetScope));

    c11.def_property("RowFilter", &ReportDefinitionNode::GetRowFilter, &ReportDefinitionNode::SetRowFilter);
    c11.def("GetRowFilter", &ReportDefinitionNode::GetRowFilter, DOC(Bentley, DgnPlatform, ReportDefinitionNode, GetRowFilter));
    c11.def("SetRowFilter", &ReportDefinitionNode::SetRowFilter, "expr"_a, DOC(Bentley, DgnPlatform, ReportDefinitionNode, SetRowFilter));
    
    c11.def_static("FindById", &ReportDefinitionNode::FindById, "id"_a, "dgnFile"_a, DOC(Bentley, DgnPlatform, ReportDefinitionNode, FindById));
    c11.def_static("FindByPath", &ReportDefinitionNode::FindByPath, "path"_a, "dgnFile"_a, DOC(Bentley, DgnPlatform, ReportDefinitionNode, FindByPath));
    c11.def("GetSelectionScopeOption", &ReportDefinitionNode::GetSelectionScopeOption, DOC(Bentley, DgnPlatform, ReportDefinitionNode, GetSelectionScopeOption));
    c11.def("SetSelectionScopeOption", &ReportDefinitionNode::SetSelectionScopeOption, "option"_a, DOC(Bentley, DgnPlatform, ReportDefinitionNode, SetSelectionScopeOption));
    c11.def("GetIncludeItemTypeOption", &ReportDefinitionNode::GetIncludeItemTypeOption, DOC(Bentley, DgnPlatform, ReportDefinitionNode, GetIncludeItemTypeOption));
    c11.def("SetIncludeItemTypeOption", &ReportDefinitionNode::SetIncludeItemTypeOption, "option"_a, DOC(Bentley, DgnPlatform, ReportDefinitionNode, SetIncludeItemTypeOption));

    //===================================================================================
    // struct ReportCategoryNode
    py::class_< ReportCategoryNode, ReportCategoryNodePtr, ECReportNode> c12(m, "ReportCategoryNode");

    c12.def(py::init(&ReportCategoryNode::From), "node"_a, DOC(Bentley, DgnPlatform, ReportCategoryNode, From));
    c12.def(py::init(&ReportCategoryNode::Create), "name"_a, "sortPriority"_a, "dgnFile"_a);
    c12.def_static("FindByName", &ReportCategoryNode::FindByName, "name"_a, "dgnFile"_a, DOC(Bentley, DgnPlatform, ReportCategoryNode, FindByName));
    c12.def("CreateReportDefinition", py::overload_cast<WCharCP, int>(&ReportCategoryNode::CreateReportDefinition), "name"_a, "sortPriority"_a, DOC(Bentley, DgnPlatform, ReportCategoryNode, CreateReportDefinition));
    c12.def("CreateReportDefinition", py::overload_cast<WCharCP, int, bool>(&ReportCategoryNode::CreateReportDefinition), "name"_a, "sortPriority"_a, "hideEmptyRow"_a, DOC(Bentley, DgnPlatform, ReportCategoryNode, CreateReportDefinition));
    c12.def("GenerateReportFromClass", &ReportCategoryNode::GenerateReportFromClass, "ecClass"_a, "name"_a, "sortPriority"_a = -1, DOC(Bentley, DgnPlatform, ReportCategoryNode, GenerateReportFromClass));

    //===================================================================================
    // struct ColumnGroupNode
    py::class_< ColumnGroupNode, ColumnGroupNodePtr, ECReportNode> c13(m, "ColumnGroupNode");

    c13.def(py::init(&ColumnGroupNode::From), "node"_a);
    c13.def_property_readonly("ColumnDefinitions", &ColumnGroupNode::GetColumnDefinitions, py::return_value_policy::reference_internal);
    c13.def("GetColumnDefinitions", &ColumnGroupNode::GetColumnDefinitions, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, ColumnGroupNode, GetColumnDefinitions));

    c13.def("CreateColumnDefinition", &ColumnGroupNode::CreateColumnDefinition, "name"_a, "sortPriority"_a, DOC(Bentley, DgnPlatform, ColumnGroupNode, CreateColumnDefinition));


    //===================================================================================
    // struct SortingGroupNode
    py::class_< SortingGroupNode, SortingGroupNodePtr, ECReportNode> c16(m, "SortingGroupNode");

    c16.def(py::init(&SortingGroupNode::From), "node"_a);
    c16.def_property_readonly("SortingRules", &SortingGroupNode::GetSortingRules);
    c16.def("GetSortingRules", &SortingGroupNode::GetSortingRules, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, SortingGroupNode, GetSortingRules));

    c16.def("GetRuleForColumn", [] (SortingGroupNode& self, WCharCP columnName) { return SortingRuleNodePtr(const_cast<SortingRuleNodeP>(self.GetRuleForColumn(columnName))); });
    c16.def("CreateSortingRule", &SortingGroupNode::CreateSortingRule, "columnName"_a, "priority"_a, DOC(Bentley, DgnPlatform, SortingGroupNode, CreateSortingRule));


    //===================================================================================
    // struct DgnECHostIterable
    py::class_< DgnECHostIterable> c18(m, "DgnECHostIterable");

    c18.def(py::init<DgnECInstanceIterable, DgnECHostSpecificationsContextCR>(), "primaryInstances"_a, "context"_a);
    c18.def("__bool__", [] (DgnECHostIterable& self) { return !self.empty(); });
    c18.def("__iter__", [] (DgnECHostIterable& self) { return py::make_iterator(self.begin(), self.end()); });

    //===================================================================================
    // struct HostExpressionCriterion
    py::class_< HostExpressionCriterion, HostExpressionCriterionPtr, ECExpressionCriterion> c20(m, "HostExpressionCriterion");

    c20.def(py::init(&HostExpressionCriterion::Create), "expressionString"_a, "hostSymbolName"_a, "hostSpecContext"_a);

    //===================================================================================
    // struct ReportResultsEntry
    py::class_< ReportResultsEntry, std::unique_ptr<ReportResultsEntry, py::nodelete> > c21(m, "ReportResultsEntry");

    c21.def_property_readonly("Content", &ReportResultsEntry::GetContent);
    c21.def("GetContent", &ReportResultsEntry::GetContent, py::return_value_policy::reference_internal);

    c21.def_property_readonly("SourceInstanceId", &ReportResultsEntry::GetSourceInstanceId);
    c21.def("GetSourceInstanceId", &ReportResultsEntry::GetSourceInstanceId, py::return_value_policy::reference_internal);
    
    c21.def_property_readonly("SourceAccessor", &ReportResultsEntry::GetSourceAccessor);
    c21.def("GetSourceAccessor", &ReportResultsEntry::GetSourceAccessor, py::return_value_policy::reference_internal);
    
    c21.def_property_readonly("SourceFileName", &ReportResultsEntry::GetSourceFileName);
    c21.def("GetSourceFileName", &ReportResultsEntry::GetSourceFileName, py::return_value_policy::reference_internal);

    //===================================================================================
    // struct ReportResults
    py::class_< ReportResults> c22(m, "ReportResults");


    //===================================================================================
    // struct ReportDefinitionCollection
    py::class_< ReportDefinitionCollection> c23(m, "ReportDefinitionCollection");

    c23.def(py::init<>());
    c23.def(py::init<DgnFileR>(), "dgnFile"_a);
    c23.def_property_readonly("Count", [] (ReportDefinitionCollection& self) { return std::distance(self.begin(), self.end()); });
    c23.def("__len__", [] (ReportDefinitionCollection& self) { return std::distance(self.begin(), self.end()); });
    c23.def("GetReportDefinitionAt", [] (ReportDefinitionCollection& self, size_t index)
            {
            if (index >= (size_t)std::distance(self.begin(), self.end()))
                throw py::index_error();

            auto it = self.begin();
            std::advance(it, index);
            return ReportDefinitionNodePtr(*it);
            }, "index"_a);
    }