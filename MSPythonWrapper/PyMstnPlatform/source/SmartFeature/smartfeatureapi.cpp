/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyMstnPlatform\source\SmartFeature\smartfeatureapi.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <PSolid/PSolidCoreAPI.h>
#include <Mstn/SmartFeature/SmartFeatureBaseDefs.h>
#include <Mstn/SmartFeature/SmartFeatureAPI.h>



static const char * __doc_Bentley_MstnPlatform_SmartFeatureUtil_DrawDynamicSpinAxis =R"doc(Draw dynamic spin axis.

Parameter ``axis``:
    axis

Parameter ``range``:
    range

Parameter ``normal``:
    normal

Parameter ``viewport``:
    viewport)doc";

static const char * __doc_Bentley_MstnPlatform_SmartFeatureUtil_GetCurveVector =R"doc(Get CurveVector using elementHandle.

Parameter ``curveVector``:
    Output curve vector

Parameter ``eh``:
    Element used to get curve vector

Parameter ``regionsOnly``:
    only regions)doc";

static const char * __doc_Bentley_MstnPlatform_SmartFeatureUtil_GetCurveVectorPlane =R"doc(Get plane of supplied CurveVector.

Parameter ``plane``:
    output plane

Parameter ``curveVector``:
    of which plane has to retrieve

Parameter ``point``:
    Point used on curve vector

Parameter ``parallelIfLinear``:
    Parallel option be used in case of linear)doc";

static const char * __doc_Bentley_MstnPlatform_FeatureCreate_CreateSolidNode =R"doc(Create Parametric Solid Node

Parameter ``Input``:
    element expected to be of type smart solid. Application need to
    ensure that element handle should of type smart solid

Returns:
    Solid feature node)doc";

static const char * __doc_Bentley_MstnPlatform_FeatureCreate_CreateSizeFilter =R"doc(Create Size Filter Smart Feature Node.

Parameter ``settings``:
    Input data for Size Filter creation.

Returns:
    Size Filter feature node)doc";

static const char * __doc_Bentley_MstnPlatform_FeatureCreate_CreateExtrudeAlongFeature =R"doc(Create Extrude Along Smart Feature node

Parameter ``lockDirection``:
    If profile orientation needs to be locked in particular direction.

Parameter ``scalePoint``:
    If extrusion needs scaling about some input point. Please refer
    the structure ExtrudeAlongSetting. User need to specify m_doscale
    and m_scale value in it.

Parameter ``settings``:
    Extrude along setting used to generatate extrusion

Parameter ``createSheet``:
    If true extrusion output will be sheet body in case of false it
    will be solid body.

Returns:
    successfully created ExtrudeAlong parametric feature)doc";

static const char * __doc_Bentley_MstnPlatform_FeatureCreate_CreateCutFeature =R"doc(Create Cut Smart Feature node

Parameter ``cutNode``:
    Newly created cut feature node

Parameter ``depthMode``:
    Various depth options

Parameter ``directionMode``:
    The cut direction

Parameter ``outsideProfile``:
    With respect to profile

Parameter ``depth``:
    Depth distance (not applicable for depthMode = ALL.

Parameter ``defaultNormal``:
    The normal

Returns:
    SUCCESS if Cut creation is successful)doc";

static const char * __doc_Bentley_MstnPlatform_FeatureCreate_CreateTrimFeature =R"doc(Create Trim Smart Feature node

Parameter ``trimNode``:
    Trim feature node

Parameter ``face``:
    Face to trim from

Returns:
    SUCCESS if feature is created successfully)doc";

static const char * __doc_Bentley_MstnPlatform_FeatureCreate_CreateDifferenceFeature =R"doc(Create Boolean-Difference Smart Feature node

Parameter ``booleanNode``:
    Difference feature node

Parameter ``subtractionPoint``:
    Subtraction point. The default argument with nullptr value

Returns:
    SUCCESS if feature is created successfully)doc";

static const char * __doc_Bentley_MstnPlatform_FeatureCreate_CreateIntersectionFeature =R"doc(Create Boolean-Intersection Smart Feature node

Parameter ``booleanNode``:
    Intersection feature node

Returns:
    SUCCESS if feature is created successfully)doc";

static const char * __doc_Bentley_MstnPlatform_FeatureCreate_CreateUnionFeature =R"doc(Create Boolean-Union Smart Feature node

Parameter ``booleanNode``:
    Union feature node

Returns:
    SUCCESS if feature is created successfully)doc";

static const char * __doc_Bentley_MstnPlatform_FeatureCreate_CreateChamferFeature =R"doc(Obsoleted! Please use the another API named as CreateChamferFeature()
from this class itself.)doc";

static const char * __doc_Bentley_MstnPlatform_FeatureCreate_CreateBlendFeature =R"doc(Obsoleted! Please use the another API named as CreateBlendFeature()
from this class itself.)doc";

static const char * __doc_Bentley_MstnPlatform_FeatureCreate_CreateRevolveFeature =R"doc(Create Revolve parametric Feature.

Parameter ``settings``:
    Input data for Revolve creation

Returns:
    Revolve feature node)doc";

static const char * __doc_Bentley_MstnPlatform_FeatureCreate_CreateExtrudeFeature =R"doc(Create Extrude parametric Feature.

Parameter ``settings``:
    Input data for Extrude creation

Returns:
    Extrude feature node)doc";

static const char * __doc_Bentley_MstnPlatform_SmartFeatureElement_DropToLegacy =R"doc(Drop parametric feature to smart solid state

Parameter ``agenda``:
    Dropped elements

Parameter ``featureEh``:
    Parametric solid element to drop

Returns:
    SUCCESS if the drop is successful.)doc";

static const char * __doc_Bentley_MstnPlatform_SmartFeatureElement_CollapseHistory =R"doc(Collapse feature tree

Parameter ``eeh``:
    Parametric solid element

Parameter ``featureTree``:
    Feature tree

Parameter ``featureNode``:
    Feature node to collapse

Returns:
    SUCCESS if the operation is successful.)doc";

static const char * __doc_Bentley_MstnPlatform_SmartFeatureElement_WriteSmartFeature =R"doc(Write Smart Feature into the file.

Parameter ``newFeatureEeh``:
    Parametric solid element

Parameter ``featureTree``:
    Feature tree

Parameter ``oldFeatureEeh``:
    Old feature element or Template element

Returns:
    SUCCESS if the operation is successful.)doc";

static const char * __doc_Bentley_MstnPlatform_SmartFeatureElement_ShowExternalLeaf =R"doc(Show external leaf

Parameter ``featureEeh``:
    Parametric solid element

Parameter ``leaf``:
    Element ref of leaf

Returns:
    SUCCESS if the operation is successful.)doc";

static const char * __doc_Bentley_MstnPlatform_SmartFeatureElement_HideExternalLeaf =R"doc(Hide external leaf

Parameter ``featureEeh``:
    Parametric solid element

Parameter ``leaf``:
    Element ref of leaf

Returns:
    SUCCESS if the operation is successful.)doc";

static const char * __doc_Bentley_MstnPlatform_SmartFeatureElement_GetFeaturesFromNodeIds =R"doc(Get feature by using node id

Parameter ``featureTree``:
    Feature tree

Parameter ``features``:
    Features to be returned

Parameter ``featureEh``:
    Parametric Feature element

Parameter ``nodeIdsSet``:
    Features nodes

Returns:
    SUCCESS if the operation is successful.)doc";

static const char * __doc_Bentley_MstnPlatform_SmartFeatureElement_GetFeaturesFromNodeName =R"doc(Get feature by using node name

Parameter ``featureTree``:
    Feature tree

Parameter ``features``:
    Features to be returned

Parameter ``featureEh``:
    Parametric Feature element

Parameter ``nodeName``:
    Feature node name

Returns:
    SUCCESS if the operation is successful.)doc";

static const char * __doc_Bentley_MstnPlatform_SmartFeatureElement_GetFeaturesFromSubEntities =R"doc(Get feature by supplying sub entities captured by UI

Parameter ``featureTree``:
    Feature tree

Parameter ``features``:
    Features to be returned

Parameter ``featureEh``:
    Parametric Feature element

Parameter ``subEntities``:
    Subentity to get feature from

Returns:
    SUCCESS if the operation is successful.)doc";

static const char * __doc_Bentley_MstnPlatform_SmartFeatureElement_GetFeatureName =R"doc(Get feature name

Parameter ``subEntity``:
    subEntity used to precisely locate feature

Parameter ``hostEh``:
    Parametric Solid element

Returns:
    Feature name)doc";

static const char * __doc_Bentley_MstnPlatform_SmartFeatureElement_SaveTree =R"doc(Save smart feature tree on supplied element.

Parameter ``out]``:
    featureEeh Parametric Feature element

Parameter ``featureTree``:
    the tree to save on element

Returns:
    SUCCESS if the operation is successful.)doc";

static const char * __doc_Bentley_MstnPlatform_SmartFeatureElement_ExtractTree =R"doc(Get smart feature tree of supplied element.

Returns:
    SUCCESS if the operation is successful.)doc";

static const char * __doc_Bentley_MstnPlatform_SmartFeatureElement_DumpFeatureTree =R"doc(Print feature tree information for debug purpose

Parameter ``label``:
    E.g. WPrintfString(L" Element:% d ", eh.GetElementId()

Parameter ``eh``:
    Parametric Feature element

Returns:
    SUCCESS if the operation is successful.)doc";

static const char * __doc_Bentley_MstnPlatform_SmartFeatureElement_DoRollBack =R"doc(Rollback feature

Parameter ``out]``:
    eeh Parametric Feature element

Returns:
    SUCCESS if the operation is successful.)doc";

static const char * __doc_Bentley_MstnPlatform_SmartFeatureElement_RemoveFeature =R"doc(Delete parametric feature

Parameter ``eh``:
    Parametric Feature element

Parameter ``tree``:
    Feature tree to use

Parameter ``nodeToDelete``:
    Feature node to delete

Returns:
    SUCCESS if the operation is successful.)doc";

static const char * __doc_Bentley_MstnPlatform_SmartFeatureElement_AddFeature =R"doc(Add parametric feature

Parameter ``out]``:
    eeh Parametric Feature element

Parameter ``feature``:
    Feature node to add

Returns:
    SUCCESS if the operation is successful.)doc";

static const char * __doc_Bentley_MstnPlatform_SmartFeatureElement_GetOrCreateSmartFeature =R"doc(Get existing parametric feature otherwise create a new one.

Parameter ``newFeatureEeh``:
    Parametric solid element

Parameter ``templateEh``:
    Template element

Parameter ``destinationModelRef``:
    Model ref to create parametric feature

Parameter ``oldFeatureEh``:
    existing element handle on which parametric feature has to create

Parameter ``mergeParametrics``:
    Merge Parameter option

Parameter ``visible``:
    Visible

Parameter ``temporary``:
    Temporary

Parameter ``profile``:
    Whether element is profile or not

Returns:
    SUCCESS if the operation is successful.)doc";

static const char * __doc_Bentley_MstnPlatform_SmartFeatureElement_CreateSingleChildSmartFeature =R"doc(Create parametric feature having a single child.

Parameter ``newFeatureEeh``:
    Parametric solid element

Parameter ``templateEh``:
    Template element

Parameter ``destinationModelRef``:
    Model ref to create parametric feature

Parameter ``oldFeatureEh``:
    existing element handle on which parametric feature has to create

Parameter ``node``:
    Feature node

Returns:
    SUCCESS if the operation is successful.

Remark:
    Chamfer, Blend Feature can be created using it.)doc";

static const char * __doc_Bentley_MstnPlatform_SmartFeatureElement_IsSmartFeature =R"doc(Confirm whether supplied element is parametric feature.

Parameter ``eh``:
    Element to test

Parameter ``templateEh``:
    Template element)doc";

static const char * __doc_Bentley_MstnPlatform_SmartFeatureNode_RelocateFeature =R"doc(Relocate feature node)doc";

static const char * __doc_Bentley_MstnPlatform_SmartFeatureNode_TransformFeatureAndDependents =R"doc(Transform a feature and its dependents)doc";

static const char * __doc_Bentley_MstnPlatform_SmartFeatureNode_GetBasisTransform =R"doc(Get basis transform of feature)doc";

static const char * __doc_Bentley_MstnPlatform_SmartFeatureNode_SetCustomName =R"doc(Set custom name)doc";

static const char * __doc_Bentley_MstnPlatform_SmartFeatureNode_GetCustomName =R"doc(Get custom name)doc";

static const char * __doc_Bentley_MstnPlatform_SmartFeatureNode_ClearMaterialOverride =R"doc(Clear material)doc";

static const char * __doc_Bentley_MstnPlatform_SmartFeatureNode_SetMaterialOverride =R"doc(Set material on the body)doc";

static const char * __doc_Bentley_MstnPlatform_SmartFeatureNode_GetMaterialOverride =R"doc(Get material of body)doc";

static const char * __doc_Bentley_MstnPlatform_SmartFeatureNode_ClearTransparencyOverride =R"doc(Clear transparency)doc";

static const char * __doc_Bentley_MstnPlatform_SmartFeatureNode_SetTransparencyOverride =R"doc(Set transparency)doc";

static const char * __doc_Bentley_MstnPlatform_SmartFeatureNode_GetTransparencyOverride =R"doc(Get transparency)doc";

static const char * __doc_Bentley_MstnPlatform_SmartFeatureNode_ClearColorOverride =R"doc(Clear the color)doc";

static const char * __doc_Bentley_MstnPlatform_SmartFeatureNode_SetColorOverride =R"doc(Set color on the body)doc";

static const char * __doc_Bentley_MstnPlatform_SmartFeatureNode_GetColorOverride =R"doc(Get color of the body)doc";

static const char * __doc_Bentley_MstnPlatform_SmartFeatureNode_GetSingleChildBody =R"doc(Get body of immediate single child.)doc";

static const char * __doc_Bentley_MstnPlatform_SmartFeatureNode_GetSingleChild =R"doc(Returns immediate single child.)doc";

static const char * __doc_Bentley_MstnPlatform_SmartFeatureNode_GetHandlerId =R"doc(Get paramtric feature type. Should be compared with
SmartFeatureHandlerId enum.)doc";

static const char * __doc_Bentley_MstnPlatform_SmartFeatureNode_GetBody =R"doc(Acquire body of parametric feature.

Parameter ``body``:
    Output body

Parameter ``hostEh``:
    Parametric Feature Element

Parameter ``getSolids``:
    solid output is required

Parameter ``getSheets``:
    sheet output is required

Parameter ``applyHostTransform``:
    Apply Host tansform

Parameter ``displayError``:
    Display error)doc";

static const char * __doc_Bentley_MstnPlatform_SmartFeatureNode_GetHighestNodeId =R"doc(Get highest node id in smart feature tree)doc";

static const char * __doc_Bentley_MstnPlatform_SmartFeatureNode_GetLowestNodeId =R"doc(Get lowest node id in smart feature tree)doc";

static const char * __doc_Bentley_MstnPlatform_SmartFeatureNode_GetDisabled =R"doc(Query the disable status of smart feature node.)doc";

static const char * __doc_Bentley_MstnPlatform_SmartFeatureNode_SetDisabled =R"doc(Disable the smart feature node.

Parameter ``disabled``:
    Boolean value to disable)doc";

static const char * __doc_Bentley_MstnPlatform_SmartFeatureNode_CanBeDisabled =R"doc(Whether node can be disabled?)doc";

static const char * __doc_Bentley_MstnPlatform_SmartFeatureNode_GetParent =R"doc(Get parent

Returns:
    SmartFeatureNodePtr of parent node)doc";

static const char * __doc_Bentley_MstnPlatform_SmartFeatureNode_GetAllChildrenRecursively =R"doc(Get all children recursively

Parameter ``allChildren``:
    All children)doc";

static const char * __doc_Bentley_MstnPlatform_SmartFeatureNode_GetChildren =R"doc(Get all children

Returns:
    Smart Feature node vector of children)doc";

static const char * __doc_Bentley_MstnPlatform_SmartFeatureNode_GetChildCount =R"doc(Get child count

Returns:
    Child count)doc";

static const char * __doc_Bentley_MstnPlatform_SmartFeatureNode_GetChild =R"doc(Get child

Parameter ``index``:
    Child index

Returns:
    SmartFeatureNodePtr of child node)doc";

static const char * __doc_Bentley_MstnPlatform_SmartFeatureNode_GetParentOfHiddenExternalLeaf =R"doc(Get parent of hidden external leaf. E.g. Extrude feature is returned;
in case of hidden profile

Parameter ``externalLeafParent``:
    Parent node of external leaf

Returns:
    SUCCESS if the operation is successful)doc";

static const char * __doc_Bentley_MstnPlatform_SmartFeatureNode_GetLeaf =R"doc(Get leaf

Parameter ``eh``:
    leaf element handle

Returns:
    SUCCESS if the operation is successful)doc";

static const char * __doc_Bentley_MstnPlatform_SmartFeatureNode_GetNodeId =R"doc(Get node id

Returns:
    Node id)doc";

USING_NAMESPACE_SMARTFEATURE;

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_SmartFeatureAPI(py::module_& m)
    {
    //===================================================================================
    // enum class SmartFeatureHandlerId
    py::enum_< SmartFeatureHandlerId>(m, "SmartFeatureHandlerId")
        .value("eUnspecified", SmartFeatureHandlerId::Unspecified)
        .value("eExternalSolid", SmartFeatureHandlerId::ExternalSolid)
        .value("eBoolean", SmartFeatureHandlerId::Boolean)
        .value("eBlend", SmartFeatureHandlerId::Blend)
        .value("eChamfer", SmartFeatureHandlerId::Chamfer)
        .value("eHollow", SmartFeatureHandlerId::Hollow)
        .value("eCut", SmartFeatureHandlerId::Cut)
        .value("eThicken", SmartFeatureHandlerId::Thicken)
        .value("eOffsetFace", SmartFeatureHandlerId::OffsetFace)
        .value("eTranslateFace", SmartFeatureHandlerId::TranslateFace)
        .value("eImprintElement", SmartFeatureHandlerId::ImprintElement)
        .value("eImprintOffset", SmartFeatureHandlerId::ImprintOffset)
        .value("eExternalProfile", SmartFeatureHandlerId::ExternalProfile)
        .value("eTaperFace", SmartFeatureHandlerId::TaperFace)
        .value("eSpinFace", SmartFeatureHandlerId::SpinFace)
        .value("eEAP1Hole", SmartFeatureHandlerId::EAP1Hole)
        .value("eProtrusion", SmartFeatureHandlerId::Protrusion)
        .value("eRectangularArray", SmartFeatureHandlerId::RectangularArray)
        .value("ePolarArray", SmartFeatureHandlerId::PolarArray)
        .value("eFenceStretch", SmartFeatureHandlerId::FenceStretch)
        .value("eFenceClip", SmartFeatureHandlerId::FenceClip)
        .value("eExtrude", SmartFeatureHandlerId::Extrude)
        .value("eRevolve", SmartFeatureHandlerId::Revolve)
        .value("eLoftSurface", SmartFeatureHandlerId::LoftSurface)
        .value("eModifyVertex", SmartFeatureHandlerId::ModifyVertex)
        .value("eModifyEdge", SmartFeatureHandlerId::ModifyEdge)
        .value("eHole", SmartFeatureHandlerId::Hole)
        .value("eTrim", SmartFeatureHandlerId::Trim)
        .value("eDeleteFace", SmartFeatureHandlerId::DeleteFace)
        .value("eDeleteLump", SmartFeatureHandlerId::DeleteLump)
        .value("eExternalEdgeProfile", SmartFeatureHandlerId::ExternalEdgeProfile)
        .value("eCopyFeature", SmartFeatureHandlerId::CopyFeature)
        .value("eSweepEdge", SmartFeatureHandlerId::SweepEdge)
        .value("eEllipticalCone", SmartFeatureHandlerId::EllipticalCone)
        .value("eEllipsoid", SmartFeatureHandlerId::Ellipsoid)
        .value("eSizeFilter", SmartFeatureHandlerId::SizeFilter)
        .value("eArrayAlongPath", SmartFeatureHandlerId::ArrayAlongPath)
        .value("eAssociativeElement", SmartFeatureHandlerId::AssociativeElement)
        .value("eExtrudeAlongProfile", SmartFeatureHandlerId::ExtrudeAlongProfile)
        .value("eAssociativeElementSymbology", SmartFeatureHandlerId::AssociativeElementSymbology)
        .export_values();

    //===================================================================================
    // struct SmartFeatureNode
    py::class_< SmartFeatureNode, SmartFeatureNodePtr> c1(m, "SmartFeatureNode");
    py::bind_vector< bvector<SmartFeatureNodePtr> >(m, "SmartFeatureNodePtrArray", py::module_local(false));

    c1.def_property_readonly("NodeId", &SmartFeatureNode::GetNodeId);
    c1.def("GetNodeId", &SmartFeatureNode::GetNodeId, DOC(Bentley, MstnPlatform, SmartFeatureNode, GetNodeId));

    c1.def("GetLeaf", &SmartFeatureNode::GetLeaf, "eh"_a, DOC(Bentley, MstnPlatform, SmartFeatureNode, GetLeaf));
    
    c1.def("GetParentOfHiddenExternalLeaf", [] (SmartFeatureNode& self)
           {
           SmartFeatureNodePtr externalLeafParent;
           auto retVal = self.GetParentOfHiddenExternalLeaf(externalLeafParent);
           return py::make_tuple(retVal, externalLeafParent);
           }, DOC(Bentley, MstnPlatform, SmartFeatureNode, GetParentOfHiddenExternalLeaf));

    c1.def("GetChild", &SmartFeatureNode::GetChild, "index"_a, DOC(Bentley, MstnPlatform, SmartFeatureNode, GetChild));
    
    c1.def_property_readonly("ChildCount", &SmartFeatureNode::GetChildCount);
    c1.def("GetChildCount", &SmartFeatureNode::GetChildCount, DOC(Bentley, MstnPlatform, SmartFeatureNode, GetChildCount));
    
    c1.def_property_readonly("Children", py::overload_cast<>(&SmartFeatureNode::GetChildren));
    c1.def("GetChildren", py::overload_cast<>(&SmartFeatureNode::GetChildren), py::return_value_policy::reference_internal, DOC(Bentley, MstnPlatform, SmartFeatureNode, GetChildren));

    c1.def("GetAllChildrenRecursively", &SmartFeatureNode::GetAllChildrenRecursively, "allChildren"_a, DOC(Bentley, MstnPlatform, SmartFeatureNode, GetAllChildrenRecursively));

    c1.def_property_readonly("Parent", py::overload_cast<>(&SmartFeatureNode::GetParent));
    c1.def("GetParent", py::overload_cast<>(&SmartFeatureNode::GetParent), py::return_value_policy::reference_internal, DOC(Bentley, MstnPlatform, SmartFeatureNode, GetParent));

    c1.def("CanBeDisabled", &SmartFeatureNode::CanBeDisabled, DOC(Bentley, MstnPlatform, SmartFeatureNode, CanBeDisabled));
    
    c1.def_property("Disabled", &SmartFeatureNode::GetDisabled, &SmartFeatureNode::SetDisabled);
    c1.def("SetDisabled", &SmartFeatureNode::SetDisabled, "disable"_a, DOC(Bentley, MstnPlatform, SmartFeatureNode, SetDisabled));
    c1.def("GetDisabled", &SmartFeatureNode::GetDisabled, DOC(Bentley, MstnPlatform, SmartFeatureNode, GetDisabled));

    c1.def_property_readonly("LowestNodeId", &SmartFeatureNode::GetLowestNodeId);
    c1.def("GetLowestNodeId", &SmartFeatureNode::GetLowestNodeId, DOC(Bentley, MstnPlatform, SmartFeatureNode, GetLowestNodeId));

    c1.def_property_readonly("HighestNodeId", &SmartFeatureNode::GetHighestNodeId);
    c1.def("GetHighestNodeId", &SmartFeatureNode::GetHighestNodeId, DOC(Bentley, MstnPlatform, SmartFeatureNode, GetHighestNodeId));

    c1.def("GetBody", [] (SmartFeatureNode& self, ElementHandleCR hostEh, bool getSolids, bool getSheets, bool applyHostTransform, bool displayError)
           {
           ISolidKernelEntityPtr body;
           auto retVal = self.GetBody(body, hostEh, getSolids, getSheets, applyHostTransform, displayError);
           return py::make_tuple(retVal, body);
           }, "hostEh"_a, "getSolids"_a, "getSheets"_a, "applyHostTransform"_a, "displayError"_a, DOC(Bentley, MstnPlatform, SmartFeatureNode, GetBody));

    c1.def_property_readonly("HandlerId", &SmartFeatureNode::GetHandlerId);
    c1.def("GetHandlerId", &SmartFeatureNode::GetHandlerId, DOC(Bentley, MstnPlatform, SmartFeatureNode, GetHandlerId));

    c1.def_property_readonly("SingleChild", &SmartFeatureNode::GetSingleChild);
    c1.def("GetSingleChild", &SmartFeatureNode::GetSingleChild, DOC(Bentley, MstnPlatform, SmartFeatureNode, GetSingleChild));

    c1.def("GetSingleChildBody", [] (SmartFeatureNode& self, ElementHandleCR hostEh, bool getSolids, bool getSheets, bool applyHostTransform, bool displayError)
           {
           ISolidKernelEntityPtr body;
           auto retVal = self.GetSingleChildBody(body, hostEh, getSolids, getSheets, applyHostTransform, displayError);
           return py::make_tuple(retVal, body);
           }, "hostEh"_a, "getSolids"_a, "getSheets"_a, "applyHostTransform"_a, "displayError"_a, DOC(Bentley, MstnPlatform, SmartFeatureNode, GetSingleChildBody));

    c1.def("GetColorOverride", [] (SmartFeatureNode& self)
           {
           UInt32 color = 0;
           auto retVal = self.GetColorOverride(color);
           return py::make_tuple(retVal, color);
           }, DOC(Bentley, MstnPlatform, SmartFeatureNode, GetColorOverride));

    c1.def("SetColorOverride", &SmartFeatureNode::SetColorOverride, "color"_a, DOC(Bentley, MstnPlatform, SmartFeatureNode, SetColorOverride));
    c1.def("ClearColorOverride", &SmartFeatureNode::ClearColorOverride, DOC(Bentley, MstnPlatform, SmartFeatureNode, ClearColorOverride));

    c1.def("GetTransparencyOverride", [] (SmartFeatureNode& self)
           {
           double transparencyOverride = 0;
           auto retVal = self.GetTransparencyOverride(transparencyOverride);
           return py::make_tuple(retVal, transparencyOverride);
           }, DOC(Bentley, MstnPlatform, SmartFeatureNode, GetTransparencyOverride));

    c1.def("SetTransparencyOverride", &SmartFeatureNode::SetTransparencyOverride, "transparencyOverride"_a, DOC(Bentley, MstnPlatform, SmartFeatureNode, SetTransparencyOverride));
    c1.def("ClearTransparencyOverride", &SmartFeatureNode::ClearTransparencyOverride, DOC(Bentley, MstnPlatform, SmartFeatureNode, ClearTransparencyOverride));

    c1.def("GetMaterialOverride", [] (SmartFeatureNode& self)
           {
           MaterialId materialOverride;
           auto retVal = self.GetMaterialOverride(materialOverride);
           return py::make_tuple(retVal, materialOverride);
           }, DOC(Bentley, MstnPlatform, SmartFeatureNode, GetMaterialOverride));

    c1.def("SetMaterialOverride", &SmartFeatureNode::SetMaterialOverride, "materialOverride"_a, DOC(Bentley, MstnPlatform, SmartFeatureNode, SetMaterialOverride));
    c1.def("ClearMaterialOverride", &SmartFeatureNode::ClearMaterialOverride, DOC(Bentley, MstnPlatform, SmartFeatureNode, ClearMaterialOverride));

    c1.def_property("CustomName", &SmartFeatureNode::GetCustomName, &SmartFeatureNode::SetCustomName);
    c1.def("GetCustomName", &SmartFeatureNode::GetCustomName, DOC(Bentley, MstnPlatform, SmartFeatureNode, GetCustomName));
    c1.def("SetCustomName", &SmartFeatureNode::SetCustomName, "name"_a, DOC(Bentley, MstnPlatform, SmartFeatureNode, SetCustomName));

    c1.def("GetBasisTransform", &SmartFeatureNode::GetBasisTransform, "transform"_a, "hostEh"_a, "applyTransform"_a = true, DOC(Bentley, MstnPlatform, SmartFeatureNode, GetBasisTransform));
    c1.def("TransformFeatureAndDependents", &SmartFeatureNode::TransformFeatureAndDependents, "transform"_a, DOC(Bentley, MstnPlatform, SmartFeatureNode, TransformFeatureAndDependents));

    c1.def_static("RelocateFeature", [] (SmartFeatureNodeR node, SmartFeatureNodeR target, ElementHandleCR hostEh, WStringR errorStringId)
           {
           SmartFeatureNodePtr tree;
           auto retVal = SmartFeatureNode::RelocateFeature(tree, node, target, hostEh, errorStringId);
           return py::make_tuple(retVal, tree);
           }, "node"_a, "target"_a, "hostEh"_a, "errorStringId"_a, DOC(Bentley, MstnPlatform, SmartFeatureNode, RelocateFeature));

    //===================================================================================
    // struct SmartFeatureElement
    py::class_< SmartFeatureElement> c2(m, "SmartFeatureElement");

    c2.def_static("IsSmartFeature", &SmartFeatureElement::IsSmartFeature, "eh"_a, DOC(Bentley, MstnPlatform, SmartFeatureElement, IsSmartFeature));

    c2.def_static("CreateAndWriteSmartFeatureElement", [] (EditElementHandleR newFeatureEeh, ElementHandleCR targetEh, DgnModelRefP destinationModelRef, SmartFeatureNodeR node,
                                                           py::dict const& childElementToControlFlagsMap, bool mergeParametrics = false)
                  {
                  T_ChildElementToControlFlagsMap childMap;
                  for (auto& it : childElementToControlFlagsMap)
                      {
                      auto elemRef = it.first.cast<ElementRefP>();
                      auto flags = it.second.cast<BoolArray>();
                      childMap.insert(make_bpair(elemRef, flags));
                      }

                  return SmartFeatureElement::CreateAndWriteSmartFeatureElement(newFeatureEeh, targetEh, destinationModelRef, node, childMap, mergeParametrics);
                  }, "newFeatureEeh"_a, "targetEh"_a, "destinationModelRef"_a, "node"_a, "childElementToControlFlagsMap"_a, "mergeParametrics"_a = false);

    c2.def_static("CreateSingleChildSmartFeature",
                  &SmartFeatureElement::CreateSingleChildSmartFeature,
                  "newFeatureEeh"_a, "templateEh"_a, "destinationModelRef"_a, "oldFeatureEh"_a, "node"_a, DOC(Bentley, MstnPlatform, SmartFeatureElement, CreateSingleChildSmartFeature));

    c2.def_static("GetOrCreateSmartFeature",
                  py::overload_cast<EditElementHandleR, ElementHandleCR, DgnModelRefP, ElementHandleCR, bool, bool, bool, bool>(&SmartFeatureElement::GetOrCreateSmartFeature),
                  "newFeatureEeh"_a, "templateEh"_a, "destinationModelRef"_a, "oldFeatureEh"_a, "mergeParametrics"_a, "visible"_a, "temporary"_a, "profile"_a, DOC(Bentley, MstnPlatform, SmartFeatureElement, GetOrCreateSmartFeature));

    c2.def_static("AddFeature", &SmartFeatureElement::AddFeature, "eeh"_a, "feature"_a, DOC(Bentley, MstnPlatform, SmartFeatureElement, AddFeature));

    c2.def_static("RemoveFeature", [] (ElementHandleCR eh, SmartFeatureNodeP tree, SmartFeatureNodeR nodeToDelete)
                  {
                  SmartFeatureNodePtr tree_(tree);
                  return SmartFeatureElement::RemoveFeature(eh, tree_, nodeToDelete);
                  }, "eh"_a, "tree"_a, "nodeToDelete"_a, DOC(Bentley, MstnPlatform, SmartFeatureElement, RemoveFeature));

    c2.def_static("DoRollBack", &SmartFeatureElement::DoRollBack, "eeh"_a, DOC(Bentley, MstnPlatform, SmartFeatureElement, DoRollBack));
    c2.def_static("DumpFeatureTree", &SmartFeatureElement::DumpFeatureTree, "label"_a, "eh"_a, DOC(Bentley, MstnPlatform, SmartFeatureElement, DumpFeatureTree));
    
    c2.def_static("ExtractTree", [] (ElementHandleCR eh)
                  {
                  SmartFeatureNodePtr tree;
                  auto retVal = SmartFeatureElement::ExtractTree(tree, eh);
                  return py::make_tuple(retVal, tree);
                  }, "eh"_a, DOC(Bentley, MstnPlatform, SmartFeatureElement, ExtractTree));

    c2.def_static("SaveTree", &SmartFeatureElement::SaveTree, "featureEeh"_a, "teatureTree"_a, DOC(Bentley, MstnPlatform, SmartFeatureElement, SaveTree));
    c2.def_static("GetFeatureName", &SmartFeatureElement::GetFeatureName, "subEntity"_a, "hostEh"_a, DOC(Bentley, MstnPlatform, SmartFeatureElement, GetFeatureName));

    c2.def_static("GetFeaturesFromSubEntities", [] (T_SmartFeatureVector& features, ElementHandleCR featureEh, bvector<ISubEntityPtr>& subEntities)
                  {
                  SmartFeatureNodePtr featureTree;
                  auto retVal = SmartFeatureElement::GetFeaturesFromSubEntities(featureTree, features, featureEh, subEntities);
                  return py::make_tuple(retVal, featureTree);
                  }, "features"_a, "featureEh"_a, "subEntities"_a, DOC(Bentley, MstnPlatform, SmartFeatureElement, GetFeaturesFromSubEntities));

    c2.def_static("GetFeaturesFromNodeName", [] (T_SmartFeatureVector& features, ElementHandleCR featureEh, WStringCR nodeName)
                  {
                  SmartFeatureNodePtr featureTree;
                  auto retVal = SmartFeatureElement::GetFeaturesFromNodeName(featureTree, features, featureEh, nodeName);
                  return py::make_tuple(retVal, featureTree);
                  }, "features"_a, "featureEh"_a, "nodeName"_a, DOC(Bentley, MstnPlatform, SmartFeatureElement, GetFeaturesFromNodeName));

    c2.def_static("GetFeaturesFromNodeIds", [] (T_SmartFeatureVector& features, ElementHandleCR featureEh, bvector<UInt32>& nodeIdsSet)
                  {
                  SmartFeatureNodePtr featureTree;
                  T_NodeIdSet nodeIdSet_;

                  nodeIdSet_.insert(nodeIdsSet.begin(), nodeIdsSet.end());
                  auto retVal = SmartFeatureElement::GetFeaturesFromNodeIds(featureTree, features, featureEh, nodeIdSet_);
                  return py::make_tuple(retVal, featureTree);
                  }, "features"_a, "featureEh"_a, "nodeIdsSet"_a, DOC(Bentley, MstnPlatform, SmartFeatureElement, GetFeaturesFromNodeIds));

    c2.def_static("HideExternalLeaf", &SmartFeatureElement::HideExternalLeaf, "featureEeh"_a, "leafElemRef"_a, DOC(Bentley, MstnPlatform, SmartFeatureElement, HideExternalLeaf));
    c2.def_static("ShowExternalLeaf", &SmartFeatureElement::ShowExternalLeaf, "featureEeh"_a, "leafElemRef"_a, DOC(Bentley, MstnPlatform, SmartFeatureElement, ShowExternalLeaf));
    
    c2.def_static("WriteSmartFeature", 
                  py::overload_cast<EditElementHandleR, SmartFeatureNodeR, ElementHandleCP>(&SmartFeatureElement::WriteSmartFeature),
                  "newFeatureEeh"_a, "featureTree"_a, "oldFeatureEh"_a, DOC(Bentley, MstnPlatform, SmartFeatureElement, WriteSmartFeature));

    c2.def_static("CollapseHistory", [] (EditElementHandleR eeh, SmartFeatureNodeP featureTree, SmartFeatureNodeR featureNode)
                  {
                  SmartFeatureNodePtr featureTree_(featureTree);
                  auto retVal = SmartFeatureElement::CollapseHistory(eeh, featureTree_, featureNode);
                  return py::make_tuple(retVal, featureTree_);
                  }, "eeh"_a, "featureTree"_a, "featureNode"_a, DOC(Bentley, MstnPlatform, SmartFeatureElement, CollapseHistory));

    c2.def_static("DropToLegacy", &SmartFeatureElement::DropToLegacy, "agenda"_a, "featureEh"_a, DOC(Bentley, MstnPlatform, SmartFeatureElement, DropToLegacy));

    //===================================================================================
    // struct FeatureCreate
    py::class_< FeatureCreate> c3(m, "FeatureCreate");

    c3.def_static("CreateExtrudeFeature", &FeatureCreate::CreateExtrudeFeature, "settings"_a, DOC(Bentley, MstnPlatform, FeatureCreate, CreateExtrudeFeature));
    c3.def_static("CreateRevolveFeature", &FeatureCreate::CreateRevolveFeature, "settings"_a, DOC(Bentley, MstnPlatform, FeatureCreate, CreateRevolveFeature));
    
    c3.def_static("CreateBlendFeature", 
                  py::overload_cast<bvector<EdgeId>&, double, bool>(&FeatureCreate::CreateBlendFeature),
                  "edges"_a, "radius"_a, "isSmooth"_a, DOC(Bentley, MstnPlatform, FeatureCreate, CreateBlendFeature));

    c3.def_static("CreateBlendFeature", [] (bvector<ISubEntityPtr>& edges, double radius, bool propogateSmooth)
                  {
                  SmartFeatureNodePtr blendNode;
                  auto retVal = FeatureCreate::CreateBlendFeature(blendNode, edges, radius, propogateSmooth);
                  return py::make_tuple(retVal, blendNode);
                  }, "edges"_a, "radius"_a, "propogateSmooth"_a, DOC(Bentley, MstnPlatform, FeatureCreate, CreateBlendFeature));

    c3.def_static("CreateChamferFeature", [] (bvector<ISubEntityPtr>& edges, ChamferEdgeSettings& settings)
                  {
                  SmartFeatureNodePtr chamferNode;
                  auto retVal = FeatureCreate::CreateChamferFeature(chamferNode, edges, settings);
                  return py::make_tuple(retVal, chamferNode);
                  }, "edges"_a, "settings"_a, DOC(Bentley, MstnPlatform, FeatureCreate, CreateChamferFeature));

    c3.def_static("CreateUnionFeature", [] ()
                  {
                  SmartFeatureNodePtr booleanNode;
                  auto retVal = FeatureCreate::CreateUnionFeature(booleanNode);
                  return py::make_tuple(retVal, booleanNode);
                  }, DOC(Bentley, MstnPlatform, FeatureCreate, CreateUnionFeature));

    c3.def_static("CreateIntersectionFeature", [] ()
                  {
                  SmartFeatureNodePtr booleanNode;
                  auto retVal = FeatureCreate::CreateIntersectionFeature(booleanNode);
                  return py::make_tuple(retVal, booleanNode);
                  }, DOC(Bentley, MstnPlatform, FeatureCreate, CreateIntersectionFeature));

    c3.def_static("CreateDifferenceFeature", [] (DPoint3dP subtractionPoint)
                  {
                  SmartFeatureNodePtr booleanNode;
                  auto retVal = FeatureCreate::CreateDifferenceFeature(booleanNode, subtractionPoint);
                  return py::make_tuple(retVal, booleanNode);
                  }, "subtractionPoint"_a = nullptr, DOC(Bentley, MstnPlatform, FeatureCreate, CreateDifferenceFeature));

    c3.def_static("CreateTrimFeature", [] (ISubEntityP face)
                  {
                  SmartFeatureNodePtr trimNode;
                  ISubEntityPtr face_(face);
                  auto retVal = FeatureCreate::CreateTrimFeature(trimNode, face_);
                  return py::make_tuple(retVal, trimNode);
                  }, "face"_a, DOC(Bentley, MstnPlatform, FeatureCreate, CreateTrimFeature));

    c3.def_static("CreateCutFeature", [] (SolidUtil::Modify::CutDepthMode depthMode, SolidUtil::Modify::CutDirectionMode directionMode, bool outsideProfile, 
                                          double depth, DVec3dCP defaultNormal)
                  {
                  SmartFeatureNodePtr cutNode;                  
                  auto retVal = FeatureCreate::CreateCutFeature(cutNode, depthMode, directionMode, outsideProfile, depth, defaultNormal);
                  return py::make_tuple(retVal, cutNode);
                  }, "depthMode"_a, "directionMode"_a, "outsideProfile"_a, "depth"_a, "defaultNormal"_a, DOC(Bentley, MstnPlatform, FeatureCreate, CreateCutFeature));

    c3.def_static("CreateCutFeature", [] (SolidUtil::Modify::CutDepthMode depthMode, SolidUtil::Modify::CutDirectionMode directionMode, bool outsideProfile,
                                          double depth, DVec3dCP defaultNormal, DVec3dCP cutDirection)
                  {
                  SmartFeatureNodePtr cutNode;
                  auto retVal = FeatureCreate::CreateCutFeature(cutNode, depthMode, directionMode, outsideProfile, depth, defaultNormal, cutDirection);
                  return py::make_tuple(retVal, cutNode);
                  }, "depthMode"_a, "directionMode"_a, "outsideProfile"_a, "depth"_a, "defaultNormal"_a, "cutDirection"_a, DOC(Bentley, MstnPlatform, FeatureCreate, CreateCutFeature));

    c3.def_static("CreateExtrudeAlongFeature", &FeatureCreate::CreateExtrudeAlongFeature, "lockDirection"_a, "scalePoint"_a, "settings"_a, "createSheet"_a, DOC(Bentley, MstnPlatform, FeatureCreate, CreateExtrudeAlongFeature));
    c3.def_static("CreateSizeFilter", &FeatureCreate::CreateSizeFilter, "settings"_a, DOC(Bentley, MstnPlatform, FeatureCreate, CreateSizeFilter));
    c3.def_static("CreateSolidNode", &FeatureCreate::CreateSolidNode, "eh"_a, DOC(Bentley, MstnPlatform, FeatureCreate, CreateSolidNode));

    //===================================================================================
    // struct SmartFeatureUtil
    py::class_< SmartFeatureUtil> c4(m, "SmartFeatureUtil");


    c4.def_static("GetCurveVectorPlane", &SmartFeatureUtil::GetCurveVectorPlane, "plane"_a, "curveVector"_a, "point"_a = nullptr, "parallelIfLinear"_a = true, DOC(Bentley, MstnPlatform, SmartFeatureUtil, GetCurveVectorPlane));

    c4.def_static("GetCurveVector", [] (ElementHandleCR eh, bool regionsOnly)
                  {
                  CurveVectorPtr curveVector;
                  auto retVal = SmartFeatureUtil::GetCurveVector(curveVector, eh, regionsOnly);
                  return py::make_tuple(retVal, curveVector);
                  }, "eh"_a, "regionsOnly"_a, DOC(Bentley, MstnPlatform, SmartFeatureUtil, GetCurveVector));

    c4.def_static("DrawDynamicSpinAxis", &SmartFeatureUtil::DrawDynamicSpinAxis, "axis"_a, "range"_a, "normal"_a, "viewport"_a, DOC(Bentley, MstnPlatform, SmartFeatureUtil, DrawDynamicSpinAxis));
    c4.def_static("InitSmartFeature", [] ()
                  {
                      if (nullptr != mdlSystem_findMdlDesc(L"SMARTFEATURE"))
                          return (int)SUCCESS;
                      return mdlSystem_loadMdlProgram(L"SMARTFEATURE", L"SMARTFEATURE", L"");
                  });
    }