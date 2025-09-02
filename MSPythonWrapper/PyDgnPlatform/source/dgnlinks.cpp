/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnPlatform\source\dgnlinks.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <DgnPlatform/DgnLinks.h>



static const char * __doc_Bentley_DgnPlatform_DgnLinkStringUserData_SetString =R"doc(Sets the user data

:param newValue:
    the value which we want to set)doc";

static const char * __doc_Bentley_DgnPlatform_DgnLinkStringUserData_GetString =R"doc(Gets the user data string value

:returns:
    the user data as a string)doc";

static const char * __doc_Bentley_DgnPlatform_PDFRegionLink_GetMatch =R"doc(Get the matching sequence from link

:returns:
    the sequence number)doc";

static const char * __doc_Bentley_DgnPlatform_PDFRegionLink_GetTargetName =R"doc(Gets the target link name.

:returns:
    the target name)doc";

static const char * __doc_Bentley_DgnPlatform_PDFRegionLink_GetTitle =R"doc(Gets the word pdf region title

:returns:
    the pdf region title)doc";

static const char * __doc_Bentley_DgnPlatform_PDFRegionLink_HeadingInfo =R"doc(Gets the word heading informations

:returns:
    the word heading infromations)doc";

static const char * __doc_Bentley_DgnPlatform_PDFRegionLink_SetHeadingInfo =R"doc(Sets the heading info to link

:param info:
    a word heading info)doc";

static const char * __doc_Bentley_DgnPlatform_PDFRegionLink_SetTarget =R"doc(Sets the target link.

:param regionType:
    a pdf region type

:param name:
    pdf region link

:param sequenceNumber:
    a sequence number of heading)doc";

static const char * __doc_Bentley_DgnPlatform_PDFRegionLink_PeekBookmarkTree =R"doc(Gets bookmark of tree

:returns:
    the tree pointer)doc";

static const char * __doc_Bentley_DgnPlatform_PDFRegionLink_SetBranch =R"doc(Sets the branch to which this link will be attached.

:param branch:
    of the tree)doc";

static const char * __doc_Bentley_DgnPlatform_ExcelSheetLink_SetSheetName =R"doc(Sets a sheet name to link

:param name:
    is name of sheet)doc";

static const char * __doc_Bentley_DgnPlatform_ExcelSheetLink_GetSheetName =R"doc(Gets a sheet name from link

:returns:
    sheet name from link)doc";

static const char * __doc_Bentley_DgnPlatform_WordBookmarkLink_GetMatch =R"doc(Gets the matching sequence from link

:returns:
    the sequence number)doc";

static const char * __doc_Bentley_DgnPlatform_WordBookmarkLink_GetStyle =R"doc(Gets the target style of link

:returns:
    the target style)doc";

static const char * __doc_Bentley_DgnPlatform_WordBookmarkLink_GetTargetName =R"doc(Gets the target name of link

:returns:
    the target name)doc";

static const char * __doc_Bentley_DgnPlatform_WordBookmarkLink_GetTitle =R"doc(Gets the word heading title

:returns:
    the heading title)doc";

static const char * __doc_Bentley_DgnPlatform_WordBookmarkLink_SetTarget =R"doc(Sets the target to link

:param regionType:
    a word region type

:param name:
    word heading name

:param sequenceNumber:
    a sequence number of heading)doc";

static const char * __doc_Bentley_DgnPlatform_WordBookmarkLink_GetTargetType =R"doc(Gets the word region type

:returns:
    the word region type)doc";

static const char * __doc_Bentley_DgnPlatform_WordHeadingLink_GetMatch =R"doc(Gets the matching sequence from link

:returns:
    the sequence number)doc";

static const char * __doc_Bentley_DgnPlatform_WordHeadingLink_GetStyle =R"doc(Gets the target style of link

:returns:
    the target style)doc";

static const char * __doc_Bentley_DgnPlatform_WordHeadingLink_GetTargetName =R"doc(Gets the target name of link

:returns:
    the target name)doc";

static const char * __doc_Bentley_DgnPlatform_WordHeadingLink_GetTitle =R"doc(Gets the word heading title

:returns:
    the heading title)doc";

static const char * __doc_Bentley_DgnPlatform_WordHeadingLink_HeadingInfo =R"doc(Gets the word heading informations

:returns:
    the word heading infromations)doc";

static const char * __doc_Bentley_DgnPlatform_WordHeadingLink_SetHeadingInfo =R"doc(Sets the heading info to link

:param info:
    a word heading info)doc";

static const char * __doc_Bentley_DgnPlatform_WordHeadingLink_SetTarget =R"doc(Sets the target to link

:param regionType:
    a word region type

:param headingName:
    word heading name

:param sequenceNumber:
    a sequence number of heading)doc";

static const char * __doc_Bentley_DgnPlatform_WordHeadingLink_GetTargetType =R"doc(Gets the word region type

:returns:
    the word region type)doc";

static const char * __doc_Bentley_DgnPlatform_WordHeadingLink_PeekBookmarkTree =R"doc(Gets the bookmark of tree

:returns:
    the tree pointer)doc";

static const char * __doc_Bentley_DgnPlatform_WordHeadingLink_SetBranch =R"doc(Sets a branch to link where this is going to be attached.

:param branch:
    of the tree)doc";

static const char * __doc_Bentley_DgnPlatform_DgnLinkSetLink_SetLinkTreeKey =R"doc(Set the link key into the link.

:param treeKey:
    key of target linkset)doc";

static const char * __doc_Bentley_DgnPlatform_DgnLinkSetLink_GetLinkTreeKey =R"doc(Get the linkset key.

:returns:
    the tree key of target linkset)doc";

static const char * __doc_Bentley_DgnPlatform_DgnLinkSetLink_SetFileLink =R"doc(Set a file link into the linkset link.

:param fileLink:
    a file link which needs to be attached to linkset link

:returns:
    SUCCESS if it succeeds)doc";

static const char * __doc_Bentley_DgnPlatform_DgnLinkSetLink_SetLinkSetName =R"doc(Set the linkset name into the link.

:param linkSetName:
    name of the linkset)doc";

static const char * __doc_Bentley_DgnPlatform_DgnLinkSetLink_GetLinkSetName =R"doc(Get the name of the linkset.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnLinkSetLink_SetLinkSetPath =R"doc(Set the link set path into the link.

:param linksetPath:
    a linkset path)doc";

static const char * __doc_Bentley_DgnPlatform_DgnLinkSetLink_GetLinkSetPath =R"doc(Get the linkset path.

:returns:
    the linkset path of the link)doc";

static const char * __doc_Bentley_DgnPlatform_DgnConfigVarExpressionLink_GetExpressionValue =R"doc(Get the expression value which this link consists of.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnConfigVarExpressionLink_SetFilter =R"doc(Sets the filter expresssion in the link.

:param filterExpression:
    filter string)doc";

static const char * __doc_Bentley_DgnPlatform_DgnConfigVarExpressionLink_GetFilter =R"doc(Gets the filter string from link.

:returns:
    the filter string)doc";

static const char * __doc_Bentley_DgnPlatform_DgnConfigVarExpressionLink_SetExpression =R"doc(Sets the expression to link

:param configVarExpression:
    an expression which needs to be set to link.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnConfigVarExpressionLink_GetExpression =R"doc(Gets the expression from link.

:returns:
    the expression string.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnURLLink_SetAddress =R"doc(Destructor Set the URL address in the link

:param urlAddress:
    a URL address)doc";

static const char * __doc_Bentley_DgnPlatform_DgnRegionLink_SetModelLink =R"doc(:param model:
    a model link)doc";

static const char * __doc_Bentley_DgnPlatform_DgnRegionLink_GetTargetType =R"doc(Gets the type of target link.

:returns:
    the type of target which links have)doc";

static const char * __doc_Bentley_DgnPlatform_DgnRegionLink_GetTargetName =R"doc(Gets the name of the target link.

:returns:
    the name of target)doc";

static const char * __doc_Bentley_DgnPlatform_DgnRegionLink_SetTargetSubType =R"doc(Sets the region Sub Type link to the target link.

:param targetSubType:
    a Sub-type of target(eg. Plan, Elevation etc.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnRegionLink_GetTargetSubType =R"doc(Gets the Sub-Type of target link if it is a Saved View Link

:returns:
    the Sub-Type (Plan, Elevation, Detail etc.) of target link)doc";

static const char * __doc_Bentley_DgnPlatform_DgnRegionLink_SetTarget =R"doc(Sets the region link to the target link.

:param targetType:
    a type of target

:param targetName:
    the name of the target)doc";

static const char * __doc_Bentley_DgnPlatform_DgnModelLink_SetFileLink =R"doc(Set a file link in the model link

:param fileLink:
    a file link which needs to be attached to model link

:returns:
    SUCCESS if it succeeds else it returns FAIL.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnModelLink_SetMarkupModel =R"doc(Set the markup model property in the link

:param isMarkup:
    has the value true/false depending on which the markup status of
    the link is decided.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnModelLink_SetModelType =R"doc(Set the model type in the link)doc";

static const char * __doc_Bentley_DgnPlatform_DgnModelLink_SetModelName =R"doc(Set the model name in the link to which the model has been associated.

:param modelName:
    the name of the model)doc";

static const char * __doc_Bentley_DgnPlatform_DgnModelLink_GetModelName =R"doc(Get the model name from link.

:returns:
    the name of model to which this link is associated)doc";

static const char * __doc_Bentley_DgnPlatform_DgnFolderLink_GetMoniker =R"doc(Get the document moniker from link

:returns:
    the folder moniker in which link has been associated)doc";

static const char * __doc_Bentley_DgnPlatform_DgnFolderLink_SetMoniker =R"doc(Set the folder moniker to a link

:param folderMoniker:
    a folder moniker where this link is going to be attached)doc";

static const char * __doc_Bentley_DgnPlatform_DgnFileLink_SetMoniker =R"doc(Sets the document moniker to a link

:param moniker:
    the document moniker where this links is going to be attached

:param createRelativePath:
    a boolean to specify whether to create a relative path.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnGenericLink_SetMoniker =R"doc(Set the document moniker to a link

:param moniker:
    the document moniker where this link is going to attached

:param createRelativePath:
    by default its going to true, for creating portable path)doc";

static const char * __doc_Bentley_DgnPlatform_DgnGenericLink_GetMoniker =R"doc(Get the document moniker from link

:returns:
    the document moniker in which link has been associated)doc";

static const char * __doc_Bentley_DgnPlatform_DgnGenericLink_IsFileBasedLink =R"doc(Check whether link is file based or not)doc";

static const char * __doc_Bentley_DgnPlatform_DgnLinkBookmarkProvider_LoadBookmarkTree =R"doc(Load the book mark tree

:returns:
    the link tree pointer)doc";

static const char * __doc_Bentley_DgnPlatform_DgnLinkUserData_IsPersistent =R"doc(Check if the user data is persistent.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnLinkUserData_GetSubID =R"doc(Get the sub-application ID for the user data.

:returns:)doc";

static const char * __doc_Bentley_DgnPlatform_DgnLinkUserData_GetAppID =R"doc(Get the application ID

:returns:
    the application ID)doc";

static const char * __doc_Bentley_DgnPlatform_DgnLinkUserData_Copy =R"doc(Copy link user data

:returns:
    the object of type DgnLinkUserData)doc";

static const char * __doc_Bentley_DgnPlatform_DgnLinkSet_Copy =R"doc(Copy the link set to the destination branch)doc";

static const char * __doc_Bentley_DgnPlatform_DgnLink_GetBookmarkProvider =R"doc(It will return the bookmark provider

:returns:
    the DgnLinkBookmarkProvider object)doc";

static const char * __doc_Bentley_DgnPlatform_DgnLink_HasSameTarget =R"doc(To check whether links has same target

:param anotherLink:
    the link which needs to be verified

:returns:
    status in true/false mode)doc";

static const char * __doc_Bentley_DgnPlatform_DgnLink_BuildSuggestedName =R"doc(Build the unique link name in the context of the tree where it is
going to be attached.

:param contextParent:
    tree branch where it is going to attach

:param fullContext:
    it will describes whether it will be in full context or not

:returns:
    the link name)doc";

static const char * __doc_Bentley_DgnPlatform_DgnLink_GetTargetAncestry =R"doc(Get the target sepecifications for the link and its parent target as
well.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnLink_GetTargetSpec =R"doc(Get the target specification.

:returns:
    the target specification)doc";

static const char * __doc_Bentley_DgnPlatform_DgnLink_GetShortDescription =R"doc(Get the short description for this link.

:returns:
    the string which is basically a shrot description of link)doc";

static const char * __doc_Bentley_DgnPlatform_DgnLink_IsTargetFullyQualified =R"doc(Check if target is fully qualified, if not returns a reason.

:param reason:
    String which describes the reason

:returns:
    True/False)doc";

static const char * __doc_Bentley_DgnPlatform_DgnLink_IsTargetValid =R"doc(Check if target is valid.

:param logger:
    A link validation object

:returns:
    the status of function in true/false)doc";

static const char * __doc_Bentley_DgnPlatform_DgnLinkFollowLog_AppendToLogString =R"doc(This method can be used to append a string to existing log object.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnLinkFollowLog_GetLogString =R"doc(It will give the log string which has been generated while calling log
object

:returns:
    the log string)doc";

static const char * __doc_Bentley_DgnPlatform_DgnLinkFollowLog_SetErrorString =R"doc(Set the error string to object from given string)doc";

static const char * __doc_Bentley_DgnPlatform_DgnLinkFollowLog_GetErrorString =R"doc(Get the error string.

:returns:
    string which represents the error.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnLinkTargetSpec_Compare =R"doc(This method can be used to compare the two targets

:param targetSpec:
    A target which can be compared against the other.

:returns:
    comparison result in true/false)doc";

static const char * __doc_Bentley_DgnPlatform_DgnLinkTargetSpec_GetLocationString =R"doc(Get the location string. @ returns the target location)doc";

static const char * __doc_Bentley_DgnPlatform_DgnLinkTargetSpec_GetNameString =R"doc(Get the string that defines the target name

:returns:
    target name)doc";

static const char * __doc_Bentley_DgnPlatform_DgnLinkTargetSpec_GetTypeString =R"doc(Get the string that describes the type

:returns:
    the string which describes the type)doc";

static const char * __doc_Bentley_DgnPlatform_DgnLinkTargetSpec_GetAncestryKey =R"doc(Get the ancestry key

:returns:
    the ancestry key)doc";

static const char * __doc_Bentley_DgnPlatform_DgnLinkECInstanceAdapter_ToECInstance =R"doc(Create the EC instance for the object

:returns:
    a pointr to IECInstancePtr)doc";

static const char * __doc_Bentley_DgnPlatform_DgnLinkECInstanceAdapter_FromECInstance =R"doc(Create object from the EC instance. This method can be used to fill
the Object from given ECinstance and treeSpec

:returns:
    SUCCESS if it is properly able to fill the data)doc";

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_DgnLinks(py::module_& m)
    {
    //===================================================================================
    // struct DgnLinkECInstanceAdapter
    py::class_< DgnLinkECInstanceAdapter, std::unique_ptr<DgnLinkECInstanceAdapter, py::nodelete> > c1(m, "DgnLinkECInstanceAdapter");

    c1.def("FromECInstance", &DgnLinkECInstanceAdapter::FromECInstance, "instance"_a, "treeSpec"_a, DOC(Bentley, DgnPlatform, DgnLinkECInstanceAdapter, FromECInstance));
    c1.def("ToECInstance", &DgnLinkECInstanceAdapter::ToECInstance, DOC(Bentley, DgnPlatform, DgnLinkECInstanceAdapter, ToECInstance));

    //===================================================================================
    // struct DgnLinkTargetSpec
    py::class_< DgnLinkTargetSpec, DgnLinkTargetSpecPtr> c2(m, "DgnLinkTargetSpec");

    c2.def(py::init(&DgnLinkTargetSpec::Create), "ancestryKey"_a, "targetType"_a, "targetName"_a, "targetLocation"_a);
    
    c2.def_property_readonly("AncestryKey", &DgnLinkTargetSpec::GetAncestryKey);
    c2.def("GetAncestryKey", &DgnLinkTargetSpec::GetAncestryKey, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, DgnLinkTargetSpec, GetAncestryKey));
    
    c2.def_property_readonly("TypeString", &DgnLinkTargetSpec::GetTypeString);
    c2.def("GetTypeString", &DgnLinkTargetSpec::GetTypeString, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, DgnLinkTargetSpec, GetTypeString));
    
    c2.def_property_readonly("NameString", &DgnLinkTargetSpec::GetNameString);
    c2.def("GetNameString", &DgnLinkTargetSpec::GetNameString, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, DgnLinkTargetSpec, GetNameString));
    
    c2.def_property_readonly("LocationString", &DgnLinkTargetSpec::GetLocationString);
    c2.def("GetLocationString", &DgnLinkTargetSpec::GetLocationString, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, DgnLinkTargetSpec, GetLocationString));
    
    c2.def("Compare", &DgnLinkTargetSpec::Compare, "targetSpec"_a, DOC(Bentley, DgnPlatform, DgnLinkTargetSpec, Compare));

    //===================================================================================
    // struct DgnLinkFollowLog
    py::class_< DgnLinkFollowLog, DgnLinkFollowLogPtr> c3(m, "DgnLinkFollowLog");

    c3.def(py::init<>());

    c3.def_property("ErrorString", &DgnLinkFollowLog::GetErrorString, &DgnLinkFollowLog::SetErrorString);
    c3.def("GetErrorString", &DgnLinkFollowLog::GetErrorString, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, DgnLinkFollowLog, GetErrorString));
    c3.def("SetErrorString", &DgnLinkFollowLog::SetErrorString, "error"_a, DOC(Bentley, DgnPlatform, DgnLinkFollowLog, SetErrorString));

    c3.def_property_readonly("LogString", &DgnLinkFollowLog::GetLogString);
    c3.def("GetLogString", &DgnLinkFollowLog::GetLogString, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, DgnLinkFollowLog, GetLogString));

    c3.def("AppendToLogString", &DgnLinkFollowLog::AppendToLogString, "logString"_a, DOC(Bentley, DgnPlatform, DgnLinkFollowLog, AppendToLogString));

    //===================================================================================
    // struct DgnLink
    py::class_<DgnLink
        , std::unique_ptr<DgnLink, py::nodelete>
    > c4(m, "DgnLink");

    c4.def_property_readonly("TreeNode", &DgnLink::GetTreeNodeP);
    c4.def("GetTreeNode", &DgnLink::GetTreeNodeP, py::return_value_policy::reference_internal);

    c4.def("IsTargetValid", &DgnLink::IsTargetValid, "logger"_a, DOC(Bentley, DgnPlatform, DgnLink, IsTargetValid));
    c4.def("IsTargetFullyQualified", &DgnLink::IsTargetFullyQualified, "reason"_a, DOC(Bentley, DgnPlatform, DgnLink, IsTargetFullyQualified));
    
    c4.def_property_readonly("ShortDescription", &DgnLink::GetShortDescription);
    c4.def("GetShortDescription", &DgnLink::GetShortDescription, DOC(Bentley, DgnPlatform, DgnLink, GetShortDescription));
    
    c4.def_property_readonly("TargetSpec", &DgnLink::GetTargetSpec);
    c4.def("GetTargetSpec", &DgnLink::GetTargetSpec, DOC(Bentley, DgnPlatform, DgnLink, GetTargetSpec));
    
    c4.def("GetTargetAncestry", &DgnLink::GetTargetAncestry, "specList"_a, DOC(Bentley, DgnPlatform, DgnLink, GetTargetAncestry));
    c4.def("BuildSuggestedName", &DgnLink::BuildSuggestedName, "contextParent"_a, "fullContext"_a, DOC(Bentley, DgnPlatform, DgnLink, BuildSuggestedName));
    c4.def("HasSameTarget", &DgnLink::HasSameTarget, "anotherLink"_a, DOC(Bentley, DgnPlatform, DgnLink, HasSameTarget));

    c4.def("GetECTarget", [] (DgnLink const& self, WCharCP ancestorKey, DgnECInstanceCreateOptionsCR options)
           {
           FindInstancesScopePtr scope;
           ECQueryPtr query;
           auto retVal = self.GetECTarget(scope, query, ancestorKey, options);
           return py::make_tuple(retVal, scope, query);
           }, "ancestorKey"_a, "options"_a);
    
    c4.def_property_readonly("BookmarkProvider", &DgnLink::GetBookmarkProvider);
    c4.def("GetBookmarkProvider", &DgnLink::GetBookmarkProvider, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, DgnLink, GetBookmarkProvider));

    //===================================================================================
    // struct DgnLinkSet
    py::class_< DgnLinkSet
        , DgnLinkSetPtr
    > c5(m, "DgnLinkSet", py::multiple_inheritance());

    c5.def("Copy", &DgnLinkSet::Copy, "treeBranch"_a, DOC(Bentley, DgnPlatform, DgnLinkSet, Copy));
    
    c5.def_property_readonly("TreeNode", &DgnLinkSet::GetTreeNodeP);
    c5.def("GetTreeNode", &DgnLinkSet::GetTreeNodeP, py::return_value_policy::reference_internal);

    c5.def("InvalidChildCount", &DgnLinkSet::GetInvalidChildCount, "logger"_a);

    //===================================================================================
    // struct DgnLinkUserData
    py::class_< DgnLinkUserData
        , DgnLinkUserDataPtr
    > c6(m, "DgnLinkUserData", py::multiple_inheritance());

    c6.def("Copy", &DgnLinkUserData::Copy, DOC(Bentley, DgnPlatform, DgnLinkUserData, Copy));
    
    c6.def_property_readonly("AppID", &DgnLinkUserData::GetAppID);
    c6.def("GetAppID", &DgnLinkUserData::GetAppID, DOC(Bentley, DgnPlatform, DgnLinkUserData, GetAppID));

    c6.def_property_readonly("SubID", &DgnLinkUserData::GetSubID);
    c6.def("GetSubID", &DgnLinkUserData::GetSubID, DOC(Bentley, DgnPlatform, DgnLinkUserData, GetSubID));

    c6.def("IsPersistent", &DgnLinkUserData::IsPersistent, DOC(Bentley, DgnPlatform, DgnLinkUserData, IsPersistent));

    //===================================================================================
    // struct DgnLinkBookmarkProvider
    py::class_< DgnLinkBookmarkProvider, std::unique_ptr<DgnLinkBookmarkProvider, py::nodelete> > c7(m, "DgnLinkBookmarkProvider");

    c7.def("LoadBookmarkTree", &DgnLinkBookmarkProvider::LoadBookmarkTree, DOC(Bentley, DgnPlatform, DgnLinkBookmarkProvider, LoadBookmarkTree));

    //===================================================================================
    // struct DgnGenericLink
    py::class_< DgnGenericLink, DgnLink> c8(m, "DgnGenericLink");

    c8.def("IsFileBasedLink", &DgnGenericLink::IsFileBasedLink, DOC(Bentley, DgnPlatform, DgnGenericLink, IsFileBasedLink));

    c8.def_property_readonly("Moniker", &DgnGenericLink::GetMonikerPtr);
    c8.def("GetMoniker", &DgnGenericLink::GetMonikerPtr, DOC(Bentley, DgnPlatform, DgnGenericLink, GetMoniker));
    
    c8.def("SetMoniker", &DgnGenericLink::SetMoniker, "moniker"_a, "createRelativePath"_a = true, DOC(Bentley, DgnPlatform, DgnGenericLink, SetMoniker));

    //===================================================================================
    // struct DgnFileLink
    py::class_< DgnFileLink
        , std::unique_ptr<DgnFileLink, py::nodelete>
        , DgnLink
    > c9(m, "DgnFileLink");

    c9.def("SetMoniker", &DgnFileLink::SetMoniker, "moniker"_a, "createRelativePath"_a = true, DOC(Bentley, DgnPlatform, DgnFileLink, SetMoniker));
    c9.def_property_readonly("Moniker", &DgnFileLink::GetMonikerPtr);


    //===================================================================================
    // struct DgnFolderLink
    py::class_< DgnFolderLink
        , DgnLink
    > c10(m, "DgnFolderLink");

    c10.def("SetMoniker", &DgnFolderLink::SetMoniker, "folderMoniker"_a, DOC(Bentley, DgnPlatform, DgnFolderLink, SetMoniker));
    c10.def_property_readonly("Moniker", &DgnFolderLink::GetMonikerPtr);
    c10.def("GetMoniker", &DgnFolderLink::GetMonikerPtr, DOC(Bentley, DgnPlatform, DgnFolderLink, GetMoniker));

    //===================================================================================
    // struct DgnLinkComposition
    py::class_< DgnLinkComposition, std::unique_ptr<DgnLinkComposition, py::nodelete>, DgnLink> c11(m, "DgnLinkComposition");


    //===================================================================================
    // struct DgnModelLink
    py::class_< DgnModelLink
        , std::unique_ptr<DgnModelLink, py::nodelete>
        , DgnLinkComposition
    > c12(m, "DgnModelLink");

    c12.def_property("ModelName", &DgnModelLink::GetModelName, &DgnModelLink::SetModelName);
    c12.def("GetModelName", &DgnModelLink::GetModelName, DOC(Bentley, DgnPlatform, DgnModelLink, GetModelName));
    c12.def("SetModelName", &DgnModelLink::SetModelName, "modelName"_a, DOC(Bentley, DgnPlatform, DgnModelLink, SetModelName));

    c12.def("GetModelType", [] (DgnModelLinkCR self)
            {
            StatusInt status;
            auto retVal = self.GetModelType(status);
            return py::make_tuple(retVal, status);
            });

    c12.def("SetModelType", &DgnModelLink::SetModelType, "modelType"_a, DOC(Bentley, DgnPlatform, DgnModelLink, SetModelType));

    c12.def("GetMarkupModel", [] (DgnModelLinkCR self)
            {
            StatusInt status;
            auto retVal = self.GetMarkupModel(status);
            return py::make_tuple(retVal, status);
            });

    c12.def("SetMarkupModel", &DgnModelLink::SetMarkupModel, "isMarkup"_a, DOC(Bentley, DgnPlatform, DgnModelLink, SetMarkupModel));
    
    c12.def_property_readonly("FileLink", &DgnModelLink::GetFileLinkP);
    c12.def("GetFileLink", &DgnModelLink::GetFileLinkP, py::return_value_policy::reference_internal);
    
    c12.def("SetFileLink", &DgnModelLink::SetFileLink, "fileLink"_a, py::keep_alive<1, 2>(), DOC(Bentley, DgnPlatform, DgnModelLink, SetFileLink));

    //===================================================================================
    // struct DgnRegionLink
    py::class_< DgnRegionLink, std::unique_ptr<DgnRegionLink, py::nodelete>, DgnLinkComposition> c13(m, "DgnRegionLink");

    c13.def("SetTarget", &DgnRegionLink::SetTarget, "targetType"_a, "targetName"_a, DOC(Bentley, DgnPlatform, DgnRegionLink, SetTarget));

    c13.def_property("TargetSubType", &DgnRegionLink::GetTargetSubType, &DgnRegionLink::SetTargetSubType);
    c13.def("GetTargetSubType", &DgnRegionLink::GetTargetSubType, DOC(Bentley, DgnPlatform, DgnRegionLink, GetTargetSubType));
    c13.def("SetTargetSubType", &DgnRegionLink::SetTargetSubType, "subType"_a, DOC(Bentley, DgnPlatform, DgnRegionLink, SetTargetSubType));
    
    c13.def_property_readonly("TargetName", &DgnRegionLink::GetTargetName);
    c13.def("GetTargetName", &DgnRegionLink::GetTargetName, DOC(Bentley, DgnPlatform, DgnRegionLink, GetTargetName));

    c13.def_property_readonly("TargetType", &DgnRegionLink::GetTargetType);
    c13.def("GetTargetType", &DgnRegionLink::GetTargetType, DOC(Bentley, DgnPlatform, DgnRegionLink, GetTargetType));

    c13.def_property_readonly("ModelLink", [] (DgnRegionLink& self) { return std::unique_ptr<DgnModelLink, py::nodelete>(self.GetModelLinkP()); });
    c13.def("GetModelLink", [] (DgnRegionLink& self) { return std::unique_ptr<DgnModelLink, py::nodelete>(self.GetModelLinkP()); });

    c13.def("SetModelLink", &DgnRegionLink::SetModelLink, "model"_a, py::keep_alive<1, 2>(), DOC(Bentley, DgnPlatform, DgnRegionLink, SetModelLink));

    c13.def_property_readonly("FileLink", &DgnRegionLink::GetFileLinkP);
    c13.def("GetFileLink", &DgnRegionLink::GetFileLinkP, py::return_value_policy::reference_internal);

    //===================================================================================
    // struct DgnURLLink
    py::class_< DgnURLLink, std::unique_ptr<DgnURLLink, py::nodelete>, DgnLink> c14(m, "DgnURLLink");

    if (true)
        {
        //===================================================================================
        // enum Schema
        py::enum_<DgnURLLink::Schema>(c14, "Schema", py::arithmetic())
            .value("eSCHEMA_unrecognized", DgnURLLink::SCHEMA_unrecognized)
            .value("eSCHEMA_http", DgnURLLink::SCHEMA_http)
            .value("eSCHEMA_https", DgnURLLink::SCHEMA_https)
            .value("eSCHEMA_ftp", DgnURLLink::SCHEMA_ftp)
            .value("eSCHEMA_mailto", DgnURLLink::SCHEMA_mailto)
            .value("eSCHEMA_MSTN_keyin", DgnURLLink::SCHEMA_MSTN_keyin)
            .value("eSCHEMA_file", DgnURLLink::SCHEMA_file)
            .export_values();
        }

    c14.def("SetAddress", &DgnURLLink::SetAddress, "urlAddress"_a, DOC(Bentley, DgnPlatform, DgnURLLink, SetAddress));
    c14.def_property_readonly("Address", &DgnURLLink::GetAddress);
    c14.def_property_readonly("Schema", &DgnURLLink::GetSchema);

    //===================================================================================
    // struct DgnConfigVarExpressionLink
    py::class_< DgnConfigVarExpressionLink, DgnLink> c15(m, "DgnConfigVarExpressionLink");
    
    c15.def_property("Expression", &DgnConfigVarExpressionLink::GetExpression, &DgnConfigVarExpressionLink::SetExpression);
    c15.def("GetExpression", &DgnConfigVarExpressionLink::GetExpression, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, DgnConfigVarExpressionLink, GetExpression));
    c15.def("SetExpression", &DgnConfigVarExpressionLink::SetExpression, "expression"_a, DOC(Bentley, DgnPlatform, DgnConfigVarExpressionLink, SetExpression));
    
    c15.def_property("Filter", &DgnConfigVarExpressionLink::GetFilter, &DgnConfigVarExpressionLink::SetFilter);
    c15.def("GetFilter", &DgnConfigVarExpressionLink::GetFilter, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, DgnConfigVarExpressionLink, GetFilter));
    c15.def("SetFilter", &DgnConfigVarExpressionLink::SetFilter, "expression"_a, DOC(Bentley, DgnPlatform, DgnConfigVarExpressionLink, SetFilter));
    
    c15.def_property("FileFilter", &DgnConfigVarExpressionLink::GetFileFilter, &DgnConfigVarExpressionLink::SetFileFilter);
    c15.def("GetFileFilter", &DgnConfigVarExpressionLink::GetFileFilter, py::return_value_policy::reference_internal);
    c15.def("SetFileFilter", &DgnConfigVarExpressionLink::SetFileFilter, "fileFilter"_a);
    
    c15.def("GetExpressionValue", &DgnConfigVarExpressionLink::GetExpressionValue, "exprVal"_a, DOC(Bentley, DgnPlatform, DgnConfigVarExpressionLink, GetExpressionValue));
    
    c15.def_property("ProcessSubDirectories", &DgnConfigVarExpressionLink::GetProcessSubDirectories, &DgnConfigVarExpressionLink::SetProcessSubDirectories);    
    c15.def("GetProcessSubDirectories", &DgnConfigVarExpressionLink::GetProcessSubDirectories);
    c15.def("SetProcessSubDirectories", &DgnConfigVarExpressionLink::SetProcessSubDirectories, "process"_a);    

    //===================================================================================
    // struct HarvestingLogger
    py::class_< HarvestingLogger> c16(m, "HarvestingLogger");

    if (true)
        {
        //===================================================================================
        // enum HarvestingLoggerValues
        py::enum_<HarvestingLogger::HarvestingLoggerValues>(c16, "HarvestingLogger")
            .value("eNone", HarvestingLogger::HarvestingLoggerValues::None)
            .value("eIndexerBasedHarevest", HarvestingLogger::HarvestingLoggerValues::IndexerBasedHarevest)
            .value("euStationBasedHarevest", HarvestingLogger::HarvestingLoggerValues::uStationBasedHarevest)
            .export_values();
        }

    c16.def(py::init<>());

    
    c16.def_property("Strategy", &HarvestingLogger::GetStrategy, &HarvestingLogger::SetStrategy);
    c16.def("GetStrategy", &HarvestingLogger::GetStrategy);
    c16.def("SetStrategy", &HarvestingLogger::SetStrategy, "strategy"_a);
    
    c16.def_property("ExecuteQueryStatus", &HarvestingLogger::GetExecuteQueryStatus, &HarvestingLogger::SetExecuteQueryStatus);
    c16.def("GetExecuteQueryStatus", &HarvestingLogger::GetExecuteQueryStatus);
    c16.def("SetExecuteQueryStatus", &HarvestingLogger::SetExecuteQueryStatus, "status"_a);
    
    c16.def("SetLogMessage", &HarvestingLogger::SetLogMessage, "logMsg"_a);
    c16.def("GetLogMessage", &HarvestingLogger::GetLogMessage, py::return_value_policy::reference_internal);
    c16.def("LoggerStorageClear", &HarvestingLogger::LoggerStorageClear);

    //===================================================================================
    // struct DgnLinkSetLink
    py::class_< DgnLinkSetLink
        , DgnLinkComposition
    > c17(m, "DgnLinkSetLink");

    c17.def_property("LinkSetPath", &DgnLinkSetLink::GetLinkSetPath, &DgnLinkSetLink::SetLinkSetPath);
    c17.def("GetLinkSetPath", &DgnLinkSetLink::GetLinkSetPath, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, DgnLinkSetLink, GetLinkSetPath));
    c17.def("SetLinkSetPath", &DgnLinkSetLink::SetLinkSetPath, "linkSetPath"_a, DOC(Bentley, DgnPlatform, DgnLinkSetLink, SetLinkSetPath));
    
    c17.def_property("LinkSetName", &DgnLinkSetLink::GetLinkSetName, &DgnLinkSetLink::SetLinkSetName);
    c17.def("GetLinkSetName", &DgnLinkSetLink::GetLinkSetName, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, DgnLinkSetLink, GetLinkSetName));
    c17.def("SetLinkSetName", &DgnLinkSetLink::SetLinkSetName, "linkSetName"_a, DOC(Bentley, DgnPlatform, DgnLinkSetLink, SetLinkSetName));
    
    c17.def_property("FileLink", &DgnLinkSetLink::GetFileLinkP, py::cpp_function(&DgnLinkSetLink::SetFileLink, py::keep_alive<1, 2>()));
    c17.def("GetFileLink", &DgnLinkSetLink::GetFileLinkP, py::return_value_policy::reference_internal);
    c17.def("SetFileLink", &DgnLinkSetLink::SetFileLink, py::keep_alive<1, 2>(), "fileLink"_a, DOC(Bentley, DgnPlatform, DgnLinkSetLink, SetFileLink));
    
    c17.def_property("LinkTreeKey", &DgnLinkSetLink::GetLinkTreeKey, &DgnLinkSetLink::SetLinkTreeKey);    
    c17.def("GetLinkTreeKey", &DgnLinkSetLink::GetLinkTreeKey, DOC(Bentley, DgnPlatform, DgnLinkSetLink, GetLinkTreeKey));
    c17.def("SetLinkTreeKey", &DgnLinkSetLink::SetLinkTreeKey, "treeKey"_a, DOC(Bentley, DgnPlatform, DgnLinkSetLink, SetLinkTreeKey));    

    //===================================================================================
    // struct WordHeadingInfo
    py::class_< WordHeadingInfo, WordHeadingInfoPtr> c18(m, "WordHeadingInfo");
    py::bind_vector<bvector< WordHeadingInfoPtr>>(m, "WordHeadingInfoPtrArray", py::module_local(false));

    //===================================================================================
    // enum class WordRegionType
    py::enum_< WordRegionType>(m, "WordRegionType")
        .value("eInvalid", WordRegionType::Invalid)
        .value("eBookmark", WordRegionType::Bookmark)
        .value("eHeading", WordRegionType::Heading)
        .export_values();

    //===================================================================================
    // struct WordHeadingLink
    py::class_< WordHeadingLink
        , std::unique_ptr<WordHeadingLink, py::nodelete>
        , DgnLinkComposition
    > c19(m, "WordHeadingLink");

    c19.def_property_readonly("GetFileLink", &WordHeadingLink::GetFileLinkP);

    c19.def("SetData",
            &WordHeadingLink::SetData,
            "title"_a, "style"_a, "sequenceNumber"_a, "parentLink"_a, "worldFileLink"_a,
            py::keep_alive<1, 5>(), py::keep_alive<1, 6>());

    c19.def("SetBranch", &WordHeadingLink::SetBranch, "branch"_a, py::keep_alive<1, 2>(), DOC(Bentley, DgnPlatform, WordHeadingLink, SetBranch));
    c19.def("PeekBookmarkTree", &WordHeadingLink::PeekBookmarkTree, DOC(Bentley, DgnPlatform, WordHeadingLink, PeekBookmarkTree));

    c19.def_property_readonly("TargetType", &WordHeadingLink::GetTargetType);
    c19.def("GetTargetType", &WordHeadingLink::GetTargetType, DOC(Bentley, DgnPlatform, WordHeadingLink, GetTargetType));
    
    c19.def("SetTarget", &WordHeadingLink::SetTarget, "regionType"_a, "headingName"_a, "sequenceNumber"_a, DOC(Bentley, DgnPlatform, WordHeadingLink, SetTarget));
    c19.def("SetHeadingInfo", &WordHeadingLink::SetHeadingInfo, "info"_a, DOC(Bentley, DgnPlatform, WordHeadingLink, SetHeadingInfo));    
    c19.def("HeadingInfo", &WordHeadingLink::HeadingInfoR, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, WordHeadingLink, HeadingInfo));
    
    c19.def_property_readonly("Title", &WordHeadingLink::GetTitle);
    c19.def("GetTitle", &WordHeadingLink::GetTitle, DOC(Bentley, DgnPlatform, WordHeadingLink, GetTitle));
    
    c19.def_property_readonly("TargetName", &WordHeadingLink::GetTargetName);
    c19.def("GetTargetName", &WordHeadingLink::GetTargetName, DOC(Bentley, DgnPlatform, WordHeadingLink, GetTargetName));
    
    c19.def_property_readonly("Style", &WordHeadingLink::GetStyle);
    c19.def("GetStyle", &WordHeadingLink::GetStyle, DOC(Bentley, DgnPlatform, WordHeadingLink, GetStyle));
    
    c19.def_property_readonly("Match", &WordHeadingLink::GetMatch);
    c19.def("GetMatch", &WordHeadingLink::GetMatch, DOC(Bentley, DgnPlatform, WordHeadingLink, GetMatch));

    //===================================================================================
    // struct WordBookmarkLink
    py::class_< WordBookmarkLink, std::unique_ptr<WordBookmarkLink, py::nodelete>, DgnLinkComposition> c20(m, "WordBookmarkLink");

    c20.def_property_readonly("FileLink", &WordBookmarkLink::GetFileLinkP);
    c20.def("GetFileLink", &WordBookmarkLink::GetFileLinkP, py::return_value_policy::reference_internal);
    
    c20.def_property_readonly("TargetType", &WordBookmarkLink::GetTargetType);
    c20.def("GetTargetType", &WordBookmarkLink::GetTargetType, DOC(Bentley, DgnPlatform, WordBookmarkLink, GetTargetType));
    
    c20.def("SetTarget", &WordBookmarkLink::SetTarget, "regionType"_a, "name"_a, "sequenceNumber"_a, DOC(Bentley, DgnPlatform, WordBookmarkLink, SetTarget));
    
    c20.def_property_readonly("Title", &WordBookmarkLink::GetTitle);
    c20.def("GetTitle", &WordBookmarkLink::GetTitle, DOC(Bentley, DgnPlatform, WordBookmarkLink, GetTitle));
    
    c20.def_property_readonly("TargetName", &WordBookmarkLink::GetTargetName);
    c20.def("GetTargetName", &WordBookmarkLink::GetTargetName, DOC(Bentley, DgnPlatform, WordBookmarkLink, GetTargetName));
    
    c20.def_property_readonly("Style", &WordBookmarkLink::GetStyle);
    c20.def("GetStyle", &WordBookmarkLink::GetStyle, DOC(Bentley, DgnPlatform, WordBookmarkLink, GetStyle));
    
    c20.def_property_readonly("Match", &WordBookmarkLink::GetMatch);
    c20.def("GetMatch", &WordBookmarkLink::GetMatch, DOC(Bentley, DgnPlatform, WordBookmarkLink, GetMatch));

    //===================================================================================
    // struct ExcelSheetLink
    py::class_< ExcelSheetLink, std::unique_ptr<ExcelSheetLink, py::nodelete>, DgnLinkComposition> c21(m, "ExcelSheetLink");

    c21.def_property_readonly("FileLink", &ExcelSheetLink::GetFileLinkP);
    c21.def("GetFileLink", &ExcelSheetLink::GetFileLinkP, py::return_value_policy::reference_internal);

    c21.def_property("SheetName", &ExcelSheetLink::GetSheetName, &ExcelSheetLink::SetSheetName);
    c21.def("GetSheetName", &ExcelSheetLink::GetSheetName, DOC(Bentley, DgnPlatform, ExcelSheetLink, GetSheetName));
    c21.def("SetSheetName", &ExcelSheetLink::SetSheetName, "name"_a, DOC(Bentley, DgnPlatform, ExcelSheetLink, SetSheetName));

    //===================================================================================
    // enum class WordRegionType
    py::enum_< PDFRegionType>(m, "PDFRegionType")
        .value("eInvalid", PDFRegionType::Invalid)
        .value("eBookmark", PDFRegionType::Bookmark)
        .export_values();

    //===================================================================================
    // struct PDFRegionInfo
    py::class_< PDFRegionInfo, PDFRegionInfoPtr> c22(m, "PDFRegionInfo");
    py::bind_vector<bvector< PDFRegionInfoPtr>>(m, "PDFRegionInfoPtrArray", py::module_local(false));

    //===================================================================================
    // struct PDFRegionLink
    py::class_< PDFRegionLink
        , std::unique_ptr<PDFRegionLink, py::nodelete>
        , DgnLinkComposition
    > c23(m, "PDFRegionLink");

    c23.def_property_readonly("FileLink", &PDFRegionLink::GetFileLinkP);
    c23.def("GetFileLink", &PDFRegionLink::GetFileLinkP, py::return_value_policy::reference_internal);

    c23.def("SetData",
            &PDFRegionLink::SetData,
            "title"_a, "sequenceNumber"_a, "parentLink"_a, "pdfFileLink"_a,
            py::keep_alive<1, 4>(), py::keep_alive<1, 5>());

    c23.def("SetBranch", &PDFRegionLink::SetBranch, "branch"_a, py::keep_alive<1, 2>(), DOC(Bentley, DgnPlatform, PDFRegionLink, SetBranch));
    c23.def("PeekBookmarkTree", &PDFRegionLink::PeekBookmarkTree, DOC(Bentley, DgnPlatform, PDFRegionLink, PeekBookmarkTree));
    c23.def("SetTarget", &PDFRegionLink::SetTarget, "regionType"_a, "name"_a, "sequenceNumber"_a, DOC(Bentley, DgnPlatform, PDFRegionLink, SetTarget));
    c23.def("SetHeadingInfo", &PDFRegionLink::SetHeadingInfo, "info"_a, DOC(Bentley, DgnPlatform, PDFRegionLink, SetHeadingInfo));
    c23.def("HeadingInfo", &PDFRegionLink::HeadingInfoR, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, PDFRegionLink, HeadingInfo));
    
    c23.def_property_readonly("Title", &PDFRegionLink::GetTitle);
    c23.def("GetTitle", &PDFRegionLink::GetTitle, DOC(Bentley, DgnPlatform, PDFRegionLink, GetTitle));
    
    c23.def_property_readonly("TargetName", &PDFRegionLink::GetTargetName);
    c23.def("GetTargetName", &PDFRegionLink::GetTargetName, DOC(Bentley, DgnPlatform, PDFRegionLink, GetTargetName));
    
    c23.def_property_readonly("Match", &PDFRegionLink::GetMatch);
    c23.def("GetMatch", &PDFRegionLink::GetMatch, DOC(Bentley, DgnPlatform, PDFRegionLink, GetMatch));

    //===================================================================================
    // struct DgnLinkStringUserData
    py::class_< DgnLinkStringUserData, DgnLinkStringUserDataPtr, DgnLinkUserData> c24(m, "DgnLinkStringUserData");

    c24.def(py::init(&DgnLinkStringUserData::Create), "subID"_a, "value"_a);

    c24.def_property("String", &DgnLinkStringUserData::GetString, &DgnLinkStringUserData::SetString);
    c24.def("GetString", &DgnLinkStringUserData::GetString, DOC(Bentley, DgnPlatform, DgnLinkStringUserData, GetString));
    c24.def("SetString", &DgnLinkStringUserData::SetString, "newVal"_a, DOC(Bentley, DgnPlatform, DgnLinkStringUserData, SetString));
    }