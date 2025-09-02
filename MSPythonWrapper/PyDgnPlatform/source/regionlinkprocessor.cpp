/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnPlatform\source\regionlinkprocessor.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <DgnPlatform/RegionLinkProcessor.h>



static const char * __doc_Bentley_DgnPlatform_RegionLinkProcessor_SyncLinkTreesFromAllViews =R"doc(Synchronize the destination link tree with link trees of all
associated named views

:param destEEH:
    (input) destination element

:param viewEH:
    (input) source named view from which links are copied. If this named
    view is part of a group, then other named views of that group are
    also considered.

:param writeImmediate:
    (input) save changes to element data. If false, these changes are
    scheduled on the element and caller is expected to call
    EditElementHandle.ReplaceInModel () @Returns true if
    synchronization was required)doc";

static const char * __doc_Bentley_DgnPlatform_RegionLinkProcessor_IsSyncRequired =R"doc(Check if a destination link tree branch needs to be synchronized with
source link tree branch

:param source:
    (input) source link tree branch

:param destination:
    (input) destination link tree branch @Returns true if synchronization
    is required)doc";

static const char * __doc_Bentley_DgnPlatform_RegionLinkProcessor_AreLinksDifferent =R"doc(Compare two DgnRegionLinks for equality

:param link1:
    (input) first link to compare

:param link2:
    (input) second link to compare @Returns true if given links match)doc";

static const char * __doc_Bentley_DgnPlatform_RegionLinkProcessor_GetFileName =R"doc(Get file name of given DgnRegionLink's target

:param regionLink:
    (input) region link @Returns file name of region link's target)doc";

static const char * __doc_Bentley_DgnPlatform_RegionLinkProcessor_AddRegionLink =R"doc(Adds a region link on the element held by this processor

:param parentModelRef:
    (input) parent model of link's target region

:param regionType:
    (input) type of region. Choose from DGNLINK_REGIONTYPE_Drawing,
    DGNLINK_REGIONTYPE_Reference, DGNLINK_REGIONTYPE_View,
    DGNLINK_REGIONTYPE_Fence

:param targetName:
    (input) name of target region @Returns SUCCESS if link was added
    successfully)doc";

static const char * __doc_Bentley_DgnPlatform_RegionLinkProcessor_SyncLinkTrees =R"doc(Synchronize links from the given source element's DgnLinkTree to the
DgnLinkTree held by RegionLinkProcessor

:param source:
    (input) source element

:param writeImmediate:
    (input) save changes to element data. If false, these changes are
    scheduled on the element and caller is expected to call
    EditElementHandle.ReplaceInModel () @Returns SUCCESS if link trees
    were synchronized)doc";

static const char * __doc_Bentley_DgnPlatform_RegionLinkProcessor_GetMatchingLinkIndexAndType =R"doc(Find a link that matches the given specifications in the DgnLinkTree
held by RegionLinkProcessor

:param fileName:
    (input) file name of link's target

:param fullFileName:
    (input) full file name of link's target

:param modelName:
    (input) model name of link's target

:param targetName:
    (input) name of link's target (ex:name of view, name of drawing,
    etc.). This is optional. @Returns SUCCESS if valid link was found

Returns (Tuple):
	retVal.

Returns (Tuple) ``(output):
	linkIndex index of link.

Returns (Tuple) ``(output):
	linkType. type of link (DGNLINK_REGIONTYPE_View, DGNLINK_REGIONTYPE_Drawing, etc.)

)doc";    

static const char * __doc_Bentley_DgnPlatform_RegionLinkProcessor_FindValidTargetInModel =R"doc(Find a valid link at a given index in the DgnLinkTree held by
RegionLinkProcessor and return target information

:param fileName:
    (output) file name of link's target

:param modelName:
    (output) model name of link's target

:param targetName:
    (output) name of link's target (ex:name of view, name of drawing,
    etc.)

:param regionType:
    (output) return the link type (DGNLINK_REGIONTYPE_View,
    DGNLINK_REGIONTYPE_Drawing, etc.)

:param linkIndex:
    (input) index of link to check

:param validateTarget:
    (input) optionally validate the link's target @Returns SUCCESS if valid
    link was found)doc";

static const char * __doc_Bentley_DgnPlatform_RegionLinkProcessor_AddLinkTree =R"doc(If element does not have a DgnLinkTree, create one @Returns true if a
new linktree was scheduled for addition)doc";

static const char * __doc_Bentley_DgnPlatform_RegionLinkProcessor_DeleteAllLinks =R"doc(Delete all links from the DgnLinkTree held by RegionLinkProcessor

:param writeChangesImmediately:
    (input) save changes to element data. If false, these changes are
    scheduled on the element and caller is expected to call
    EditElementHandle.ReplaceInModel () @Returns true if links were
    deleted successfully)doc";

static const char * __doc_Bentley_DgnPlatform_RegionLinkProcessor_HasMatchingLink =R"doc(Check if a link with matching data exists in the DgnLinkTree held by
RegionLinkProcessor

:param regionType:
    (input) type of region to find (DGNLINK_REGIONTYPE_View,
    DGNLINK_REGIONTYPE_Drawing, etc.)

:param moniker:
    (input) file name of link's target

:param modelName:
    (input) model name of link's target

:param targetName:
    (input) name of link's target (ex:name of view, name of drawing, etc.)
    @Returns true if matching link exists)doc";

static const char * __doc_Bentley_DgnPlatform_RegionLinkProcessor_GetMatchingLink =R"doc(Find DgnRegionLink with the given specifications

:param indexOut:
    (output) index of the found link

:param regionType:
    (input) type of region to find (DGNLINK_REGIONTYPE_View,
    DGNLINK_REGIONTYPE_Drawing, etc.)

:param moniker:
    (input) file name of link's target

:param modelName:
    (input) model name of link's target

:param targetName:
    (input) name of link's target (ex:name of view, name of drawing, etc.)
    @Returns Pointer to DgnRegionLinkP if found, or NULL @Remarks The
    returned DgnRegionLinkP will be deleted when RegionLinkProcessor
    goes out of scope)doc";

static const char * __doc_Bentley_DgnPlatform_RegionLinkProcessor_DoesLinkExist =R"doc(Check if a link with matching data exists in the DgnLinkTree held by
RegionLinkProcessor

:param linkToMatch:
    (input) region link to compare @Returns true if matching link exists)doc";

static const char * __doc_Bentley_DgnPlatform_RegionLinkProcessor_GetLinkCount =R"doc(Get the count of links in the DgnLinkTree held by RegionLinkProcessor
@Returns count of links)doc";

static const char * __doc_Bentley_DgnPlatform_RegionLinkProcessor_FindRegionLink =R"doc(Find DgnRegionLink with the given specifications

:param regionType:
    (input) type of region to find (DGNLINK_REGIONTYPE_View,
    DGNLINK_REGIONTYPE_Drawing, etc.)

:param index:
    (input) if there are multiple links of regionType, then return the
    index'th link.

:param doValidation:
    (input) validate the link's target @Returns Pointer to DgnRegionLinkP
    if found, or NULL @Remarks The returned DgnRegionLinkP will be
    deleted when RegionLinkProcessor goes out of scope)doc";

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_RegionLinkProcessor(py::module_& m)
    {
    //===================================================================================
    // struct RegionLinkProcessor
    py::class_< RegionLinkProcessor> c1(m, "RegionLinkProcessor");

    c1.def(py::init<ElementHandleCR>(), "eh"_a);
    c1.def(py::init<EditElementHandleR, bool>(), "eeh"_a, "editable"_a);
    
    c1.def("FindRegionLink", [] (RegionLinkProcessor& self, WStringCR regionType, int index, bool doValidation)
           {
           return std::unique_ptr< DgnRegionLink, py::nodelete>(self.FindRegionLink(regionType, index, doValidation));
           }, "regionType"_a, "index"_a = -1, "doValidation"_a = false, DOC(Bentley, DgnPlatform, RegionLinkProcessor, FindRegionLink));

    c1.def_property_readonly("LinkCount", &RegionLinkProcessor::GetLinkCount);
    c1.def("GetLinkCount", &RegionLinkProcessor::GetLinkCount, DOC(Bentley, DgnPlatform, RegionLinkProcessor, GetLinkCount));

    c1.def("DoesLinkExist", &RegionLinkProcessor::DoesLinkExist, "linkToMatch"_a, DOC(Bentley, DgnPlatform, RegionLinkProcessor, DoesLinkExist));
    
    c1.def("GetMatchingLink", [] (RegionLinkProcessor& self, WStringCR regionType, DgnDocumentMonikerCR moniker, WStringCR modelName, WStringCR targetName)
           {
           int indexOut = -1;
           auto retVal = self.GetMatchingLink(indexOut, regionType, moniker, modelName, targetName);
           return py::make_tuple(std::unique_ptr<DgnRegionLink, py::nodelete>(retVal), indexOut);
           }, "regionType"_a, "moniker"_a, "modelName"_a, "targetName"_a, DOC(Bentley, DgnPlatform, RegionLinkProcessor, GetMatchingLink));

    c1.def("HasMatchingLink", &RegionLinkProcessor::HasMatchingLink, "regionType"_a, "moniker"_a, "modelName"_a, "targetName"_a, DOC(Bentley, DgnPlatform, RegionLinkProcessor, HasMatchingLink));
    c1.def("DeleteAllLinks", &RegionLinkProcessor::DeleteAllLinks, "deleteAllLinks"_a, DOC(Bentley, DgnPlatform, RegionLinkProcessor, DeleteAllLinks));
    c1.def("AddLinkTree", &RegionLinkProcessor::AddLinkTree, DOC(Bentley, DgnPlatform, RegionLinkProcessor, AddLinkTree));
    c1.def("FindValidTargetInModel", &RegionLinkProcessor::FindValidTargetInModel, "fileName"_a, "modelName"_a, "targetName"_a, "regionType"_a, "linkIndex"_a, "validateTarget"_a, DOC(Bentley, DgnPlatform, RegionLinkProcessor, FindValidTargetInModel));
    c1.def("GetMatchingLinkIndexAndType", [] (RegionLinkProcessor& self, WStringCR fileName, WStringCR fullFileName, WStringCR modelName, WStringCP targetName)
           {
           int linkIndex = -1;
           WString linkType;
           auto retVal = self.GetMatchingLinkIndexAndType(linkIndex, &linkType, fileName, fullFileName, modelName, targetName);
           return py::make_tuple(retVal, linkIndex, linkType);
           }, "fileName"_a, "fullFileName"_a, "modelName"_a, "targetName"_a, DOC(Bentley, DgnPlatform, RegionLinkProcessor, GetMatchingLinkIndexAndType));

    c1.def("SyncLinkTrees", &RegionLinkProcessor::SyncLinkTrees, "source"_a, "writeImmediate"_a, DOC(Bentley, DgnPlatform, RegionLinkProcessor, SyncLinkTrees));
    c1.def("AddRegionLink", &RegionLinkProcessor::AddRegionLink, "parentModelRef"_a, "regionType"_a, "targetName"_a, DOC(Bentley, DgnPlatform, RegionLinkProcessor, AddRegionLink));

    c1.def_static("GetFileName", &RegionLinkProcessor::GetFileName, "regionLink"_a, DOC(Bentley, DgnPlatform, RegionLinkProcessor, GetFileName));
    c1.def_static("AreLinksDifferent", &RegionLinkProcessor::AreLinksDifferent, "link1"_a, "link2"_a, DOC(Bentley, DgnPlatform, RegionLinkProcessor, AreLinksDifferent));
    c1.def_static("IsSyncRequired", &RegionLinkProcessor::IsSyncRequired, "source"_a, "destination"_a, DOC(Bentley, DgnPlatform, RegionLinkProcessor, IsSyncRequired));
    c1.def_static("SyncLinkTreesFromAllViews", &RegionLinkProcessor::SyncLinkTreesFromAllViews, "destEh"_a, "viewEh"_a, "writeImmediate"_a, DOC(Bentley, DgnPlatform, RegionLinkProcessor, SyncLinkTreesFromAllViews));
    }