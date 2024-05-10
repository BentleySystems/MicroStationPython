/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnPlatform\source\dgnlinkmanager.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <DgnPlatform/DgnLinkManager.h>



static const char * __doc_Bentley_DgnPlatform_DgnLinkManager_FindMatchingLink =R"doc(Find the matching link from given scenarios like for textfiled.

Parameter ``elemHandle``:
    an element handle object

Parameter ``linkTrav``:
    a object of type IDgnLinkTraverser

Returns (Tuple, 0) :
    MatchingLinkState::Found if it find the matching link 

Returns (Tuple, 1):
	linkTreeOut.

)doc";    

static const char * __doc_Bentley_DgnPlatform_DgnLinkManager_GetManager =R"doc(Get DgnLinkManager.

Returns:
    the DgnLinkManager object )doc";

static const char * __doc_Bentley_DgnPlatform_DgnLinkManager_RemoveUserDataHandler =R"doc(Remove the specified link user data handler.

Parameter ``userDataHandler``:
    a inkUserData handler object

Returns:
    a false if not able to remove it)doc";

static const char * __doc_Bentley_DgnPlatform_DgnLinkManager_AddUserDataHandler =R"doc(Add the user data handler.

Parameter ``userDataHandler``:
    a linkUserData handler object

Returns:
    a false if not able to remove it)doc";

static const char * __doc_Bentley_DgnPlatform_DgnLinkManager_RemoveLinkSetHandler =R"doc(Remove the specified link set handler.

Parameter ``linkSetHandlerIn``:
    a linkset handler object

Returns:
    a false if not able to remove it )doc";

static const char * __doc_Bentley_DgnPlatform_DgnLinkManager_RemoveLinkHandler =R"doc(Remove the specified link handler.

Parameter ``linkHandlerIn``:
    a links handler object

Returns:
    a false if not able to remove it )doc";

static const char * __doc_Bentley_DgnPlatform_DgnLinkManager_AddLinkSetHandler =R"doc(Add a link set handler for handling a link set type.

Parameter ``linkHandlerIn``:
    a linkset handler object

Returns:
    a false if not able to add it )doc";

static const char * __doc_Bentley_DgnPlatform_DgnLinkManager_AddLinkHandler =R"doc(Add link handler for handling a link type.

Parameter ``linkHandlerIn``:
    a link handler object

Returns:
    a false if not able to add it)doc";

static const char * __doc_Bentley_DgnPlatform_DgnLinkManager_SetLeafPropertyString =R"doc(Add or replace an optional property string of a leaf node)doc";

static const char * __doc_Bentley_DgnPlatform_DgnLinkManager_GetLeafPropertyString =R"doc(Get the value of the optional property string of a leaf node.

Parameter ``leaf``:
    a leaf of the link tree

Parameter ``propertyID``:
    linktree leaf property ID

Returns:
    nullptr if the property is not found )doc";

static const char * __doc_Bentley_DgnPlatform_DgnLinkManager_ValidateLinkTarget =R"doc(Validate the link target

Parameter ``link``:
    a link object

Parameter ``logger``:
    a object of type DgnLinkValidationCenter

Returns:
    the validation result)doc";

static const char * __doc_Bentley_DgnPlatform_DgnLinkManager_BuildSuggestedName =R"doc(Build the name from given tree and parant

Parameter ``link``:
    a link object

Parameter ``contextParent``:
    the barnch where link is attached

Parameter ``fullContext``:
    a boolean variable

Returns:
    the unique name for given link and parent node.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnLinkManager_CreateLink =R"doc(Create a link from given key, and in this user have to make sure that,
link should be added into tree, so that it can be deleted with tree
object. Otherwise use have call delete to delete this object

Parameter ``key``:
    by which it will create a link set

Returns (Tuple, 0):
    the link tree branch where this link is attached

Returns (Tuple, 1):
	status.

)doc";    

static const char * __doc_Bentley_DgnPlatform_DgnLinkManager_CreateLinkSet =R"doc(Create a linkset from given key

Parameter ``key``:
    by which it will create a link set

Returns:
    the link tree branch where this linkset is attached)doc";

static const char * __doc_Bentley_DgnPlatform_DgnLinkManager_CreateTreeSpec =R"doc(Create a tree spec from given tree name

Parameter ``treeName``:
    the name of the tree

Parameter ``moniker``:
    document moniker

Parameter ``key``:
    link tree key. See DgnLinkTreeKey

Returns(Tuple, 0):
    the link tree spec pointer

Returns (Tuple, 1):
	status.

)doc";    

static const char * __doc_Bentley_DgnPlatform_DgnLinkManager_FindProjectTree =R"doc(Find the link tree from given name

Parameter ``treeName``:
    the name of the tree

Parameter ``document``:
    document where tree is present)doc";

static const char * __doc_Bentley_DgnPlatform_DgnLinkManager_ListProjectTrees =R"doc(List out the link tree from give link tree specs and document

Parameter ``treeSpecList``:
    list of tree specs

Parameter ``document``:
    a document where the link tree is present

Parameter ``key``:
    link tree key. See DgnLinkTreeKey

Returns:
    the list of tree specs)doc";

static const char * __doc_Bentley_DgnPlatform_DgnLinkManager_Deserialize =R"doc(Read the link tree from xml string

Parameter ``xmlString``:
    a XML string

Returns:
    the link tree pointer)doc";

static const char * __doc_Bentley_DgnPlatform_DgnLinkManager_Serialize =R"doc(Serialize the link tree in XML formate

Parameter ``xmlString``:
    a XML string

Parameter ``linkTree``:
    link tree object

Returns:
    the status of function)doc";

static const char * __doc_Bentley_DgnPlatform_DgnLinkManager_DeleteProjectTree =R"doc(Delete the specified link tree

Parameter ``treeSpec``:
    is used to find the proper link tree

Returns:
    the status of API)doc";

static const char * __doc_Bentley_DgnPlatform_DgnLinkManager_WriteLinkTree =R"doc(Write a link tree into the memory

Parameter ``linkTree``:
    a tree which needs to written in memory

Returns:
    the status of API in terms of True/false)doc";

static const char * __doc_Bentley_DgnPlatform_DgnLinkManager_ReadLinkTreeFromElement =R"doc(Reads a link tree from given EditElementHandle object This method is
intended to provide link tree from an element which has not been
written in the dgn file so it does not have an ElementId and
elementRef

Parameter ``elemHandle``:
    EditElementHandle of the element

Parameter ``createIfDoesNotExist``:
    create a link tree if it not exist

Returns:
    the links tree pointer)doc";

static const char * __doc_Bentley_DgnPlatform_DgnLinkManager_ReadLinkTree =R"doc(Read a link tree from given tree spec. We can also

Parameter ``treeSpec``:
    a spec of tree by using this we can read a link tree

Parameter ``createIfDoesNotExists``:
    create a link tree if it not exist

Returns:
    the links tree pointer)doc";

static const char * __doc_Bentley_DgnPlatform_DgnLinkValidationCenter_GetInvalidLinkCount =R"doc(Get the count of invalide link

Returns:
    the counts)doc";

static const char * __doc_Bentley_DgnPlatform_DgnLinkValidationCenter_GetTestedLinkCount =R"doc(Get the count of tested link

Returns:
    the counts)doc";

static const char * __doc_Bentley_DgnPlatform_DgnLinkValidationCenter_LogValidationProblem =R"doc(Log the validation problem

Parameter ``link``:
    for which we want log validation

Parameter ``logString``:
    describs the log information)doc";

static const char * __doc_Bentley_DgnPlatform_DgnLinkValidationCenter_GetRecurseFlag =R"doc(Get the flag information for recurse

Returns:
    true/false)doc";

static const char * __doc_Bentley_DgnPlatform_DgnLinkValidationCenter_GetUpdateInvalidationFlag =R"doc(Get the update inavlidateion flag

Returns:
    the status of update invalidation flag)doc";

static const char * __doc_Bentley_DgnPlatform_DgnLinkValidationCenter_GetDoValidationFlag =R"doc(Get the doValidation flag

Returns:
    true/false)doc";

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_DgnLinkManager(py::module_& m)
    {
    //===================================================================================
    // Global constants definition
    m.attr("DGNLINK_TYPEKEY_File") = L"FileLink";
    m.attr("DGNLINK_TYPEKEY_Model") = L"ModelLink";
    m.attr("DGNLINK_TYPEKEY_Bookmark") = L"BookmarkLink";
    m.attr("DGNLINK_TYPEKEY_Region") = L"RegionLink";
    m.attr("DGNLINK_TYPEKEY_Drawing") = L"Drawing";
    m.attr("DGNLINK_TYPEKEY_WordFile") = L"WordFile";
    m.attr("DGNLINK_TYPEKEY_WordRegion") = L"WordRegion";
    m.attr("DGNLINK_TYPEKEY_WordHeading") = L"WordHeading";
    m.attr("DGNLINK_TYPEKEY_ExcelFile") = L"ExcelFile";
    m.attr("DGNLINK_TYPEKEY_ExcelSheet") = L"ExcelSheet";
    m.attr("DGNLINK_TYPEKEY_PrintSetFile") = L"PrintSetFile";
    m.attr("DGNLINK_TYPEKEY_PrintDefinition") = L"PrintDefinition";
    m.attr("DGNLINK_TYPEKEY_PlotSetFile") = L"PlotSetFile";
    m.attr("DGNLINK_TYPEKEY_PlotFile") = L"PlotFile";
    m.attr("DGNLINK_TYPEKEY_PlotModel") = L"PlotModel";
    m.attr("DGNLINK_TYPEKEY_PDFFile") = L"PDFFile";
    m.attr("DGNLINK_TYPEKEY_PDFRegion") = L"PDFRegion";
    m.attr("DGNLINK_TYPEKEY_URLLink") = L"URLLink";
    m.attr("DGNLINK_TYPEKEY_Folder") = L"FolderLink";
    m.attr("DGNLINK_TYPEKEY_Link") = L"Link";
    m.attr("DGNLINK_TYPEKEY_LinkLinkSet") = L"LinkLinkSet";
    m.attr("DGNLINK_TYPEKEY_ConfigurationVariable") = L"ConfigurationVariable";
    m.attr("DGNLINKSET_TYPEKEY_Folder") = L"LinkFolder";
    m.attr("DGNLINKSET_TYPEKEY_PrintFolder") = L"LinkPrintFolder";

    m.attr("DGNLINK_REGIONTYPE_View") = L"View";
    m.attr("DGNLINK_REGIONTYPE_Fence") = L"Fence";
    m.attr("DGNLINK_REGIONTYPE_Reference") = L"Refernce";
    m.attr("DGNLINK_REGIONTYPE_Drawing") = L"Drawing";
    m.attr("DGNLINK_REGIONTYPE_NamedBoundary") = L"NamedBoundary";

    m.attr("DGNLINK_TARGETKEY_Address") = L"Address";
    m.attr("DGNLINK_TARGETKEY_File") = L"File";
    m.attr("DGNLINK_TARGETKEY_Model") = L"Model";
    m.attr("DGNLINK_TARGETKEY_Region") = L"Region";
    m.attr("DGNLINK_TARGETKEY_Folder") = L"Folder";
    m.attr("DGNLINK_TARGETKEY_RootFolder") = L"RootFolder";
    m.attr("DGNLINK_TARGETKEY_Link") = L"Link";
    m.attr("DGNLINK_TARGETKEY_System") = L"System";

    m.attr("DGNLINK_ECCLASS_LinkTreeLeaf") = L"LinkTreeLeaf";
    m.attr("DGNLINK_ECCLASS_LinkTreeBranch") = L"LinkTreeBranch";

    m.attr("DGNLINK_XMLTAG_LinkTreeName") = L"LinkTreeName";
    m.attr("DGNLINK_XMLTAG_LinkTreeFullPath") = L"LinkTreeFullPath";

    m.attr("DGNLINK_FILTERTYPE_File") = L"File";
    m.attr("DGNLINK_FILTERTYPE_Model") = L"Model";
    m.attr("DGNLINK_FILTERTYPE_Region_View") = L"View";
    m.attr("DGNLINK_FILTERTYPE_Region_Reference") = L"Refernce";
    m.attr("DGNLINK_FILTERTYPE_Region_Fence") = L"Fence";
    m.attr("DGNLINK_FILTERTYPE_Region_Drawing") = L"Drawing";

    m.attr("DGNLINK_FILTERTYPE_Model_Sheet") = L"Sheet";
    m.attr("DGNLINK_FILTERTYPE_Model_Design") = L"Design";
    m.attr("DGNLINK_FILTERTYPE_Model_Drawing") = L"Drawing";
    m.attr("DGNLINK_FILTERTYPE_Model_Markup") = L"Markup";

    m.attr("DGNLINK_FILTERTYPE_File_DGN") = L"DGN";
    m.attr("DGNLINK_FILTERTYPE_File_DWG") = L"DWG";
    m.attr("DGNLINK_FILTERTYPE_File_DOC") = L"DOC";
    m.attr("DGNLINK_FILTERTYPE_File_XLS") = L"XLS";
    m.attr("DGNLINK_FILTERTYPE_File_PDF") = L"PDF";
    m.attr("DGNLINK_FILTERTYPE_File_PSET") = L"PSET";
    m.attr("DGNLINK_FILTERTYPE_File_Other") = L"OTHER";

    m.attr("DGNLINK_FILTERTYPE_View_Basic") = L"Basic";

    //===================================================================================
    // enum DgnLinkActionType
    py::enum_< DgnLinkActionType>(m, "DgnLinkActionType", py::arithmetic())
        .value("eDGNLINK_ACTION_Invalid", DGNLINK_ACTION_Invalid)
        .value("eDGNLINK_ACTION_Action", DGNLINK_ACTION_Action)
        .value("eDGNLINK_ACTION_Undo", DGNLINK_ACTION_Undo)
        .value("eDGNLINK_ACTION_Redo", DGNLINK_ACTION_Redo)
        .export_values();

    //===================================================================================
    // enum DgnLinkActionProgress
    py::enum_< DgnLinkActionProgress>(m, "DgnLinkActionProgress", py::arithmetic())
        .value("eDGNLINK_PROGRESS_Invalid", DGNLINK_PROGRESS_Invalid)
        .value("eDGNLINK_PROGRESS_PreChange", DGNLINK_PROGRESS_PreChange)
        .value("eDGNLINK_PROGRESS_PostChange", DGNLINK_PROGRESS_PostChange)
        .export_values();

    //===================================================================================
    // enum DgnLinkChangeType
    py::enum_< DgnLinkChangeType>(m, "DgnLinkChangeType", py::arithmetic())
        .value("eDGNLINK_CHANGE_Invalid", DGNLINK_CHANGE_Invalid)
        .value("eDGNLINK_CHANGE_Add", DGNLINK_CHANGE_Add)
        .value("eDGNLINK_CHANGE_Delete", DGNLINK_CHANGE_Delete)
        .value("eDGNLINK_CHANGE_Modify", DGNLINK_CHANGE_Modify)
        .export_values();

    //===================================================================================
    // enum DgnLinkActiveLinkTreeChangeType
    py::enum_< DgnLinkActiveLinkTreeChangeType>(m, "DgnLinkActiveLinkTreeChangeType", py::arithmetic())
        .value("eDGNLINK_ACTIVELINKTREECHANGE_Invalid", DGNLINK_ACTIVELINKTREECHANGE_Invalid)
        .value("eDGNLINK_ACTIVELINKTREECHANGE_PROJECT_PreActive", DGNLINK_ACTIVELINKTREECHANGE_PROJECT_PreActive)
        .value("eDGNLINK_ACTIVELINKTREECHANGE_PROJECT_PostActive", DGNLINK_ACTIVELINKTREECHANGE_PROJECT_PostActive)
        .export_values();

    //===================================================================================
    // enum DgnLinkFollowState
    py::enum_< DgnLinkFollowState>(m, "DgnLinkFollowState", py::arithmetic())
        .value("eDGNLINK_FOLLOWSTATE_Invalid", DGNLINK_FOLLOWSTATE_Invalid)
        .value("eDGNLINK_FOLLOWSTATE_PreFollow", DGNLINK_FOLLOWSTATE_PreFollow)
        .value("eDGNLINK_FOLLOWSTATE_PostFollow", DGNLINK_FOLLOWSTATE_PostFollow)
        .export_values();

    //===================================================================================
    // enum DgnLinkTreePropertyID
    py::enum_< DgnLinkTreePropertyID>(m, "DgnLinkTreePropertyID", py::arithmetic())
        .value("eDGNLINK_TreePropertyID_Dummy", DGNLINK_TreePropertyID_Dummy)
        .export_values();

    //===================================================================================
    // enum DgnLinkLeafPropertyID
    py::enum_<DgnLinkLeafPropertyID>(m, "DgnLinkLeafPropertyID", py::arithmetic())
        .value("eDGNLINK_LeafPropertyID_SynchProblems", DGNLINK_LeafPropertyID_SynchProblems)
        .export_values();

    //===================================================================================
    // enum class MatchingLinkState
    py::enum_< MatchingLinkState>(m, "MatchingLinkState")
        .value("eFound", MatchingLinkState::Found)
        .value("eNoMatchingDataOnField", MatchingLinkState::NoMatchingDataOnField)
        .value("eNoMatchingLink", MatchingLinkState::NoMatchingLink)
        .export_values();

    //===================================================================================    
    // struct DgnLinkValidationCenter
    py::class_< DgnLinkValidationCenter> c1(m, "DgnLinkValidationCenter");

    c1.def(py::init<bool, bool, bool>(), "doValidation"_a, "updateValidation"_a, "recuse"_a);
    
    c1.def_property_readonly("DoValidationFlag", &DgnLinkValidationCenter::GetDoValidationFlag);
    c1.def("GetDoValidationFlag", &DgnLinkValidationCenter::GetDoValidationFlag, DOC(Bentley, DgnPlatform, DgnLinkValidationCenter, GetDoValidationFlag));
    
    c1.def_property_readonly("UpdateInvalidationFlag", &DgnLinkValidationCenter::GetUpdateInvalidationFlag);
    c1.def("GetUpdateInvalidationFlag", &DgnLinkValidationCenter::GetUpdateInvalidationFlag, DOC(Bentley, DgnPlatform, DgnLinkValidationCenter, GetUpdateInvalidationFlag));
    
    c1.def_property_readonly("RecurseFlag", &DgnLinkValidationCenter::GetRecurseFlag);
    c1.def("GetRecurseFlag", &DgnLinkValidationCenter::GetRecurseFlag, DOC(Bentley, DgnPlatform, DgnLinkValidationCenter, GetRecurseFlag));
    
    c1.def("LogValidationProblem", &DgnLinkValidationCenter::LogValidationProblem, "link"_a, "logString"_a, DOC(Bentley, DgnPlatform, DgnLinkValidationCenter, LogValidationProblem));
    
    c1.def_property_readonly("TestedLinkCount", &DgnLinkValidationCenter::GetTestedLinkCount);
    c1.def("GetTestedLinkCount", &DgnLinkValidationCenter::GetTestedLinkCount, DOC(Bentley, DgnPlatform, DgnLinkValidationCenter, GetTestedLinkCount));
    
    c1.def_property_readonly("InvalidLinkCount", &DgnLinkValidationCenter::GetInvalidLinkCount);
    c1.def("GetInvalidLinkCount", &DgnLinkValidationCenter::GetInvalidLinkCount, DOC(Bentley, DgnPlatform, DgnLinkValidationCenter, GetInvalidLinkCount));

    //===================================================================================
    // struct DgnLinkManager
    py::class_< DgnLinkManager> c2(m, "DgnLinkManager");


    c2.def_static("ReadLinkTree", py::overload_cast<DgnLinkTreeSpecCR, bool>(&DgnLinkManager::ReadLinkTree), "treeSpec"_a, "createIfDoesNotExists"_a, DOC(Bentley, DgnPlatform, DgnLinkManager, ReadLinkTree));
    c2.def_static("ReadLinkTreeFromElement", &DgnLinkManager::ReadLinkTreeFromElement, "elementHandle"_a, "createIfDoesNotExists"_a, DOC(Bentley, DgnPlatform, DgnLinkManager, ReadLinkTreeFromElement));
    c2.def_static("WriteLinkTree", py::overload_cast<DgnLinkTreeR>(&DgnLinkManager::WriteLinkTree), "linkTree"_a, DOC(Bentley, DgnPlatform, DgnLinkManager, WriteLinkTree));
    c2.def_static("WriteLinkTree", py::overload_cast<DgnLinkTreeR, EditElementHandleR>(&DgnLinkManager::WriteLinkTree), "linkTree"_a, "elemHandle"_a, DOC(Bentley, DgnPlatform, DgnLinkManager, WriteLinkTree));
    c2.def_static("DeleteProjectTree", &DgnLinkManager::DeleteProjectTree, "treeSpec"_a, DOC(Bentley, DgnPlatform, DgnLinkManager, DeleteProjectTree));
    c2.def_static("Serialize", &DgnLinkManager::Serialize, "xmlString"_a, "linkTree"_a, DOC(Bentley, DgnPlatform, DgnLinkManager, Serialize));
    c2.def_static("Deserialize", &DgnLinkManager::Deserialize, "xmlString"_a, DOC(Bentley, DgnPlatform, DgnLinkManager, Deserialize));
    c2.def_static("ListProjectTrees", &DgnLinkManager::ListProjectTrees, "treeSpecList"_a, "document"_a, "key"_a, DOC(Bentley, DgnPlatform, DgnLinkManager, ListProjectTrees));
    c2.def_static("FindProjectTree", &DgnLinkManager::FindProjectTree, "treeName"_a, "document"_a, DOC(Bentley, DgnPlatform, DgnLinkManager, FindProjectTree));
    c2.def_static("CreateTreeSpec", py::overload_cast<WCharCP, DgnDocumentMonikerR, DgnLinkTreeKey>(&DgnLinkManager::CreateTreeSpec), "treeName"_a, "moniker"_a, "key"_a, DOC(Bentley, DgnPlatform, DgnLinkManager, CreateTreeSpec));
    c2.def_static("CreateTreeSpec", py::overload_cast<ElementId, WCharCP, DgnDocumentMonikerR>(&DgnLinkManager::CreateTreeSpec), "elemId"_a, "modelName"_a, "moniker"_a, DOC(Bentley, DgnPlatform, DgnLinkManager, CreateTreeSpec));
    c2.def_static("CreateTreeSpec", py::overload_cast<ElementRefP>(&DgnLinkManager::CreateTreeSpec), "elemRefP"_a, DOC(Bentley, DgnPlatform, DgnLinkManager, CreateTreeSpec));
    c2.def_static("CreateTreeSpec", py::overload_cast<ElementHandleCR>(&DgnLinkManager::CreateTreeSpec), "elemHandle"_a, DOC(Bentley, DgnPlatform, DgnLinkManager, CreateTreeSpec));
    c2.def_static("CreateTreeSpec", py::overload_cast<EditElementHandleR>(&DgnLinkManager::CreateTreeSpec), "elemHandle"_a, DOC(Bentley, DgnPlatform, DgnLinkManager, CreateTreeSpec));
    c2.def_static("CreateTreeSpec", py::overload_cast<DgnLinkTreeSpecCR>(&DgnLinkManager::CreateTreeSpec), "srcTreeSpec"_a, DOC(Bentley, DgnPlatform, DgnLinkManager, CreateTreeSpec));
    
    c2.def_static("CreateLinkSet", [] (WCharCP key)
                  {
                  StatusInt status = ERROR;
                  auto retVal = DgnLinkManager::CreateLinkSet(status, key);
                  return py::make_tuple(retVal, status);
                  }, "key"_a, DOC(Bentley, DgnPlatform, DgnLinkManager, CreateLinkSet));

    c2.def_static("CreateLink", [] (WCharCP key)
                  {
                  StatusInt status = ERROR;
                  auto retVal = DgnLinkManager::CreateLink(status, key);
                  return py::make_tuple(retVal, status);
                  }, "key"_a, DOC(Bentley, DgnPlatform, DgnLinkManager, CreateLink));
    
    c2.def_static("BuildSuggestedName", &DgnLinkManager::BuildSuggestedName, "link"_a, "contextParent"_a, "fullContext"_a, DOC(Bentley, DgnPlatform, DgnLinkManager, BuildSuggestedName));
    c2.def_static("ValidateLinkTarget", &DgnLinkManager::ValidateLinkTarget, "link"_a, "logger"_a, DOC(Bentley, DgnPlatform, DgnLinkManager, ValidateLinkTarget));
    c2.def_static("GetLeafPropertyString", &DgnLinkManager::GetLeafPropertyString, "leaf"_a, "propertyID"_a, DOC(Bentley, DgnPlatform, DgnLinkManager, GetLeafPropertyString));
    c2.def_static("SetLeafPropertyString", &DgnLinkManager::SetLeafPropertyString, "leaf"_a, "propertyID"_a, "strVal"_a, DOC(Bentley, DgnPlatform, DgnLinkManager, SetLeafPropertyString));

    c2.def_static("AddLinkHandler", &DgnLinkManager::AddLinkHandler, "linkHandlerIn"_a, py::keep_alive<1, 2>(), DOC(Bentley, DgnPlatform, DgnLinkManager, AddLinkHandler));
    c2.def_static("AddLinkSetHandler", &DgnLinkManager::AddLinkSetHandler, "linkSetHandlerIn"_a, py::keep_alive<1, 2>(), DOC(Bentley, DgnPlatform, DgnLinkManager, AddLinkSetHandler));
    c2.def_static("RemoveLinkHandler", &DgnLinkManager::RemoveLinkHandler, "linkHandlerIn"_a, DOC(Bentley, DgnPlatform, DgnLinkManager, RemoveLinkHandler));
    c2.def_static("RemoveLinkSetHandler", &DgnLinkManager::RemoveLinkSetHandler, "linkSetHandlerIn"_a, DOC(Bentley, DgnPlatform, DgnLinkManager, RemoveLinkSetHandler));

    c2.def_static("AddUserDataHandler", &DgnLinkManager::AddUserDataHandler, "userDataHandler"_a, py::keep_alive<1, 2>(), DOC(Bentley, DgnPlatform, DgnLinkManager, AddUserDataHandler));
    c2.def_static("RemoveUserDataHandler", &DgnLinkManager::RemoveUserDataHandler, "userDataHandler"_a, DOC(Bentley, DgnPlatform, DgnLinkManager, RemoveUserDataHandler));
    // N.B if the class is not defined with  std::unique_ptr<DgnLinkManager, py::nodelete>.. the value policy needs to be py::return_value_policy::reference the return type must match
    c2.def_static("GetManager", &DgnLinkManager::GetManager, py::return_value_policy::reference, DOC(Bentley, DgnPlatform, DgnLinkManager, GetManager));
    
    c2.def_static("FindMatchingLink", [] (ElementHandleCR elemHandle, IDgnLinkTraverserR linkTrav)
                  {
                  DgnLinkTreePtr linkTreeOut;
                  auto retVal = DgnLinkManager::FindMatchingLink(linkTreeOut, elemHandle, linkTrav);
                  return py::make_tuple(retVal, linkTreeOut);
                  }, "elemHandle"_a, "linkTrav"_a, DOC(Bentley, DgnPlatform, DgnLinkManager, FindMatchingLink));


    }
