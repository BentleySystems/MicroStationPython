/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnPlatform\source\elementtemplateutils.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <DgnPlatform/ElementTemplateUtils.h>



static const char * __doc_Bentley_DgnPlatform_ElementTemplateUtils_GetElementTemplateHandlerId =R"doc(Return the HandlerId used to designate an element as a host element
for an Element Template.)doc";

static const char * __doc_Bentley_DgnPlatform_ElementTemplateUtils_WriteTemplateNode =R"doc(Write or Replate the Element Template in the design file. This method
is used to write the template data initially and to write any changes
to the element template data.

:param templateNode:
    The cached ElementTemplateNode that contains the data to write.
    Returns ETSTATUS_Success if the templateNode can be written.)doc";

static const char * __doc_Bentley_DgnPlatform_ElementTemplateUtils_AttachItemToElement =R"doc(Add ECXAttribute data representing the itemInstance to the specified
element. If the schema for the instance is not in the file it will be
added to the file.

:param elemRef:
    The element that is to receive the instance data.

:param itemInstance:
    The IECInstance data to be store on the element. Returns
    ETSTATUS_Success if the itemInstance can be added to the element.)doc";

static const char * __doc_Bentley_DgnPlatform_ElementTemplateUtils_AddItemToTemplate =R"doc(Add ECXAttribute data representing the itemInstance to the specified
element template. If the schema for the instance is not in the file it
will be added to the file.

:param templateNode:
    The element template node that is to receive the instance data.

:param itemInstance:
    The IECInstance data to be store on the element. Returns
    ETSTATUS_Success if the itemInstance can be added to the element.)doc";

static const char * __doc_Bentley_DgnPlatform_ElementTemplateUtils_IsTemplateInUse =R"doc(Return true if the element template is reference by any graphic
element in any loaded model.

:param templateNode:
    The element template node to check.

:param loadAllModels:
    If true then all models in the file containing the template node
    are loaded. This is the safest way to guarantee the template is
    not referenced although it could cause unloaded models to be
    loaded into cache resulting in memory usage.)doc";

static const char * __doc_Bentley_DgnPlatform_ElementTemplateUtils_GetTemplateNodeUsingDependentElement =R"doc(Return a pointer to an existing Element Template that is reference by
the specified element.

:param elementRef:
    The path of the element template to locate. Returns a valid
    ElementTemplateNodePtr if the element contains a template
    reference and the element template can be located.)doc";

static const char * __doc_Bentley_DgnPlatform_ElementTemplateUtils_FindTemplateNodeByPath =R"doc(Return a pointer to an existing Element Template that is specified by
a path and an owner. The owner is used to determine the file that
contains the element template.

:param elementTemplatePath:
    The path of the element template to locate.

:param owner:
    The owner of the XDataTree used to cache the data. This is used to
    determine the DgnFile to search. Returns a valid
    ElementTemplateNodePtr if the template can be located.)doc";

static const char * __doc_Bentley_DgnPlatform_ElementTemplateUtils_CreateByPath =R"doc(Create a new Element Template and return a pointer to the created
node. If needed this method will create the parent template group(s).

:param fullPath:
    The path of the element template to create.

:param owner:
    The XDataTreeOwner that is to hold the element template. The owner
    is used to determine the owning DgnFile. Returns ETSTATUS_Success
    if the template can be created.

Returns (Tuple, 0):
	retVal.

Returns (Tuple, 1):
	templateNode. The created element template node.

)doc";    

static const char * __doc_Bentley_DgnPlatform_ElementTemplateUtils_DeleteTemplateNode =R"doc(Delete an Element Template. The method verifies the template is not
referenced by any elements in any loaded models before deleting.

:param templateNode:
    The cached element template node used to determine template
    ElementId and file. Returns ETSTATUS_Success if the template can
    be deleted.)doc";

static const char * __doc_Bentley_DgnPlatform_ElementTemplateUtils_DeleteFromFile =R"doc(Delete an Element Template. This method does not do the error checking
before trying to delete the template. Caller should verify the
template is not referenced by any graphic elements before deleting.
See method IsTemplateInUse. It is recommended that DeleteTemplateNode
be used.

:param templateNode:
    The cached element template node used to determine template
    ElementId and file. Returns ETSTATUS_Success if the template can
    be deleted.)doc";

static const char * __doc_Bentley_DgnPlatform_ElementTemplateUtils_ScheduleTemplateReferenceAttachment =R"doc(Schedule the attachment of a reference between an element and an
element template.

:param graphicElemHandle:
    The element that is to receive the element template reference.

:param templateNode:
    The cached element template node. If the node is not in the same
    file as the graphicElemHandle then the template is copied to that
    file. Returns ETSTATUS_Success if the template reference can be
    added to the element.)doc";

static const char * __doc_Bentley_DgnPlatform_ElementTemplateUtils_SetReferencedTemplateID =R"doc(Create a reference between an element and an existing element template
in the same file as the element.

:param graphicElemHandle:
    The element that is to receive the element template reference.

:param templateID:
    The ElementId to the type 66 that holds the element template data.

:param applyDefaultSymbology:
    If true the default symbology from the template is applied to the
    element. Returns ETSTATUS_Success if the template reference can be
    added to the element.)doc";

static const char * __doc_Bentley_DgnPlatform_ElementTemplateUtils_GetReferencedTemplateIDFromHandle =R"doc(Return the ElementId for the Element Template referenced by the
specified element.

:param graphicElemHandle:
    The element that contains a reference to an element template.
    Returns 0 if the element does not contain an element template
    reference.)doc";

static const char * __doc_Bentley_DgnPlatform_ElementTemplateUtils_GetReferencedTemplateID =R"doc(Return the ElementId for the Element Template referenced by the
specified element.

:param pTemplateID:
    Pointer to the ElementId of the host Type 66 element. If NULL the
    value is not returned.

:param elemRef:
    The element that contains a reference to an element template.
    Returns ETSTATUS_Success if the template data can be extracted

Returns (Tuple, 0):
	Returns ETSTATUS_Success if the template data can be extracted

Returns (Tuple, 1):
	templateId.

)doc";


static const char * __doc_Bentley_DgnPlatform_ElementTemplateUtils_GetReferencedTemplateData =R"doc(Return both the full path and the ElementId for the Element Template
referenced by the specified element.

:param elementTemplatePath:
    Pointer to the WString to recieve the element template path. If
    NULL the value is not returned.

:param templateId:
    Pointer to the ElementId of the host Type 66 element. If NULL the
    value is not returned.

:param elementRef:
    The element that contains a reference to an element template.
    
Returns (Tuple, 0):
	Returns ETSTATUS_Success if the template data can be extracted.

Returns (Tuple, 1):
	templatePath.

Returns (Tuple, 2):
	templateId.

)doc";
static const char * __doc_Bentley_DgnPlatform_ElementTemplateUtils_GetTemplateIDFromPath =R"doc(Return the ElementId of the host type 66 element that hold element
template data.

:param pTemplateID:
    The ElementId to return

:param wPath:
    The path to the Element Template in the cache XDataTree that holds
    elment template data in the specified file..

:param dgnFileP:
    The file that contains the element template definition. Returns
    
   
Returns (Tuple, 0):
	ETSTATUS_Success if the ElementId of the element template can be
    determined

Returns (Tuple, 1):
	templatePath.

Returns (Tuple, 2):
	templateId.

)doc";    

static const char * __doc_Bentley_DgnPlatform_ElementTemplateUtils_GetPathForTemplate =R"doc(Return the full path for the Element Template referenced by the
specified element.

:param templatePath:
    The element template path.

:param templateID:
    The element of the Element Template host Type 66 element.

:param modelRef:
    The modelRef used to determine the file that contains the element
    template. Returns ETSTATUS_Success if the template path can be
    extracted.)doc";

static const char * __doc_Bentley_DgnPlatform_ElementTemplateUtils_GetReferencedTemplate =R"doc(Return pointer to the Element Template referenced by the specified
element.

:param elemRef:
    The element that contains a reference to an element template.
    Returns ETSTATUS_Success if the template path can be extracted.)doc";

static const char * __doc_Bentley_DgnPlatform_ElementTemplateUtils_GetPathForReferencedTemplate =R"doc(Return the full path for the Element Template referenced by the
specified element.

:param templatePath:
    The element template path.

:param elemRef:
    The element that contains a reference to an element template.
    Returns ETSTATUS_Success if the template path can be extracted.)doc";

static const char * __doc_Bentley_DgnPlatform_ElementTemplateUtils_AttachMaterialLinkages =R"doc(Add Material Linkage for material specified in element template to
specified element.

:param graphicElemHandle:
    The element that is to recieve the material linkage.

:param templateNode:
    The node containing a material specification Returns
    ETSTATUS_Success if material linkage can be attached.)doc";

static const char * __doc_Bentley_DgnPlatform_ElementTemplateUtils_ScheduleTemplateReferenceRemoval =R"doc(Schedule the removal of the XAttributes that contain a reference to an
Element Template from graphic element. The removal is processed when
the element is written to the file.

:param graphicElemHandle:
    The element that contains a reference to an element template
    Returns ETSTATUS_Success if template reference removal is
    scheduled.)doc";

static const char * __doc_Bentley_DgnPlatform_ElementTemplateUtils_RemoveTemplateReferenceFromElement =R"doc(Remove reference to an Element Template from a persisted graphic
element.

:param elemRef:
    The element that contains a reference to an element template
    Returns ETSTATUS_Success if template reference can be removed.)doc";

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_ElementTemplateUtils(py::module_& m)
    {
    //===================================================================================
    // enum ElementTemplateStatus
    py::enum_<Bentley::DgnPlatform::ElementTemplateStatus>(m, "ElementTemplateStatus", py::arithmetic())
        .value("eETSTATUS_Success", ETSTATUS_Success)
        .value("eETSTATUS_BadArg", ETSTATUS_BadArg)
        .value("eETSTATUS_InvalidFile", ETSTATUS_InvalidFile)
        .value("eETSTATUS_InvalidDataTreeOwner", ETSTATUS_InvalidDataTreeOwner)
        .value("eETSTATUS_InvalidPath", ETSTATUS_InvalidPath)
        .value("eETSTATUS_PathAlreadyDefined", ETSTATUS_PathAlreadyDefined)
        .value("eETSTATUS_UnableToAccessDataTree", ETSTATUS_UnableToAccessDataTree)
        .value("eETSTATUS_UnableToCreateNewGroupNode", ETSTATUS_UnableToCreateNewGroupNode)
        .value("eETSTATUS_UnableToCreateNewTemplateNode", ETSTATUS_UnableToCreateNewTemplateNode)
        .value("eETSTATUS_InvalidArgument", ETSTATUS_InvalidArgument)
        .value("eETSTATUS_UnableToDeleteReadOnly", ETSTATUS_UnableToDeleteReadOnly)
        .value("eETSTATUS_UnableToDeleteReferenceNode", ETSTATUS_UnableToDeleteReferenceNode)
        .value("eETSTATUS_UnableToDeleteNode", ETSTATUS_UnableToDeleteNode)
        .value("eETSTATUS_NoDefaultInstanceFound", ETSTATUS_NoDefaultInstanceFound)
        .value("eETSTATUS_InvalidTemplateParameter", ETSTATUS_InvalidTemplateParameter)
        .value("eETSTATUS_InvalidPropertySpecification", ETSTATUS_InvalidPropertySpecification)
        .value("eETSTATUS_BadPropertyValue", ETSTATUS_BadPropertyValue)
        .value("eETSTATUS_NullPropertyValue", ETSTATUS_NullPropertyValue)
        .value("eETSTATUS_InvalidLevelId", ETSTATUS_InvalidLevelId)
        .value("eETSTATUS_UnableToAddParameter", ETSTATUS_UnableToAddParameter)
        .value("eETSTATUS_NoStructInstanceFound", ETSTATUS_NoStructInstanceFound)
        .value("eETSTATUS_TemplateNotInFile", ETSTATUS_TemplateNotInFile)
        .value("eETSTATUS_InvalidMaterialId", ETSTATUS_InvalidMaterialId)
        .value("eETSTATUS_NullModelRef", ETSTATUS_NullModelRef)
        .value("eETSTATUS_NoTemplateId", ETSTATUS_NoTemplateId)
        .value("eETSTATUS_UnableToAddGradientKeys", ETSTATUS_UnableToAddGradientKeys)
        .value("eETSTATUS_InvalidMlineStyleId", ETSTATUS_InvalidMlineStyleId)
        .value("eETSTATUS_InvalidDimensionStyleId", ETSTATUS_InvalidDimensionStyleId)
        .value("eETSTATUS_UnableToImportItemSchema", ETSTATUS_UnableToImportItemSchema)
        .value("eETSTATUS_InvalidElementRefForNode", ETSTATUS_InvalidElementRefForNode)
        .value("eETSTATUS_InvalidEnabler", ETSTATUS_InvalidEnabler)
        .value("eETSTATUS_UnableToSetParameter", ETSTATUS_UnableToSetParameter)
        .value("eETSTATUS_InvalidArrayIndex", ETSTATUS_InvalidArrayIndex)
        .value("eETSTATUS_UnableToRemoveParameter", ETSTATUS_UnableToRemoveParameter)
        .value("eETSTATUS_LevelNameDoesNotExist", ETSTATUS_LevelNameDoesNotExist)
        .value("eETSTATUS_NoColorTypeSpecified", ETSTATUS_NoColorTypeSpecified)
        .value("eETSTATUS_InvalidLineWeightValue", ETSTATUS_InvalidLineWeightValue)
        .value("eETSTATUS_UnableToLoadMaterialById", ETSTATUS_UnableToLoadMaterialById)
        .value("eETSTATUS_InvalidParameterValue", ETSTATUS_InvalidParameterValue)
        .value("eETSTATUS_NoTemplateReferenceFound", ETSTATUS_NoTemplateReferenceFound)
        .value("eETSTATUS_UnableToWriteToReadOnlyFile", ETSTATUS_UnableToWriteToReadOnlyFile)
        .value("eETSTATUS_Error", ETSTATUS_Error)
        .export_values();

    //===================================================================================
    // struct ElementTemplateUtils
    py::class_< ElementTemplateUtils> c1(m, "ElementTemplateUtils");

    c1.def_static("RemoveTemplateReferenceFromElement", &ElementTemplateUtils::RemoveTemplateReferenceFromElement, "elemRef"_a, DOC(Bentley, DgnPlatform, ElementTemplateUtils, RemoveTemplateReferenceFromElement));
    c1.def_static("ScheduleTemplateReferenceRemoval", &ElementTemplateUtils::ScheduleTemplateReferenceRemoval, "graphicElementHandle"_a, DOC(Bentley, DgnPlatform, ElementTemplateUtils, ScheduleTemplateReferenceRemoval));
    c1.def_static("AttachMaterialLinkages", &ElementTemplateUtils::AttachMaterialLinkages, "graphicElementHandle"_a, "templateNode"_a, DOC(Bentley, DgnPlatform, ElementTemplateUtils, AttachMaterialLinkages));
    c1.def_static("GetPathForReferencedTemplate", &ElementTemplateUtils::GetPathForReferencedTemplate, "templatePath"_a, "elemRef"_a, DOC(Bentley, DgnPlatform, ElementTemplateUtils, GetPathForReferencedTemplate));
    c1.def_static("GetReferencedTemplate", &ElementTemplateUtils::GetReferencedTemplate, "elemRef"_a, DOC(Bentley, DgnPlatform, ElementTemplateUtils, GetReferencedTemplate));
    c1.def_static("GetPathForTemplate", &ElementTemplateUtils::GetPathForTemplate, "templatePath"_a, "templateId"_a, "modelRef"_a, DOC(Bentley, DgnPlatform, ElementTemplateUtils, GetPathForTemplate));
    
    c1.def_static("GetTemplateIDFromPath", [] (WCharCP wPath, DgnFileP dgnFile)
                  {
                  ElementId templateId = 0;
                  auto retVal = ElementTemplateUtils::GetTemplateIDFromPath(&templateId, wPath, dgnFile);
                  return py::make_tuple(retVal, templateId);
                  }, "wPath"_a, "dgnFile"_a, DOC(Bentley, DgnPlatform, ElementTemplateUtils, GetTemplateIDFromPath));

    c1.def_static("GetReferencedTemplateData", [] (ElementRefP elemRef)
                  {
                  WString templatePath;
                  ElementId templateId = 0;
                  auto retVal = ElementTemplateUtils::GetReferencedTemplateData(&templatePath, &templateId, elemRef);
                  return py::make_tuple(retVal, templatePath, templateId);
                  }, "elemRef"_a, DOC(Bentley, DgnPlatform, ElementTemplateUtils, GetReferencedTemplateData));

    c1.def_static("GetReferencedTemplateID", [] (ElementRefP elemRef)
                  {
                  ElementId templateId = 0;
                  auto retVal = ElementTemplateUtils::GetReferencedTemplateID(templateId, elemRef);
                  return py::make_tuple(retVal, templateId);
                  }, "elemRef"_a, DOC(Bentley, DgnPlatform, ElementTemplateUtils, GetReferencedTemplateID));

    c1.def_static("GetReferencedTemplateIDFromHandle", &ElementTemplateUtils::GetReferencedTemplateIDFromHandle, "graphicElemHandle"_a, DOC(Bentley, DgnPlatform, ElementTemplateUtils, GetReferencedTemplateIDFromHandle));
    c1.def_static("SetReferencedTemplateID", py::overload_cast<EditElementHandleR, ElementId, bool>(&ElementTemplateUtils::SetReferencedTemplateID), "graphicElemHandle"_a, "templateId"_a, "applyDefaultSymbology"_a, DOC(Bentley, DgnPlatform, ElementTemplateUtils, SetReferencedTemplateID));
    c1.def_static("SetReferencedTemplateID", py::overload_cast<ElementRefP, ElementId>(&ElementTemplateUtils::SetReferencedTemplateID), "elementRef"_a, "templateId"_a, DOC(Bentley, DgnPlatform, ElementTemplateUtils, SetReferencedTemplateID));
    c1.def_static("ScheduleTemplateReferenceAttachment", &ElementTemplateUtils::ScheduleTemplateReferenceAttachment, "graphicElemHandle"_a, "templateNode"_a, DOC(Bentley, DgnPlatform, ElementTemplateUtils, ScheduleTemplateReferenceAttachment));
    c1.def_static("DeleteFromFile", &ElementTemplateUtils::DeleteFromFile, "templateNode"_a, DOC(Bentley, DgnPlatform, ElementTemplateUtils, DeleteFromFile));
    
    c1.def_static("DeleteTemplateNode", [] (ElementTemplateNodeP templateNode)
                  {
                  ElementTemplateNodePtr node(templateNode);
                  return ElementTemplateUtils::DeleteTemplateNode(node);
                  }, "templateNode"_a, DOC(Bentley, DgnPlatform, ElementTemplateUtils, DeleteTemplateNode));

    c1.def_static("CreateByPath", [] (WCharCP fullPath, XDataTreeOwner& owner)
                  {
                  ElementTemplateNodePtr node;
                  auto retVal = ElementTemplateUtils::CreateByPath(node, fullPath, owner);
                  return py::make_tuple(retVal, node);
                  }, "fullPath"_a, "owner"_a, DOC(Bentley, DgnPlatform, ElementTemplateUtils, CreateByPath));

    c1.def_static("CreateByPath", [] (WCharCP fullPath, DgnFileR dgnFile)
                  {
                  ElementTemplateNodePtr node;
                  auto retVal = ElementTemplateUtils::CreateByPath(node, fullPath, dgnFile);
                  return py::make_tuple(retVal, node);
                  }, "fullPath"_a, "owner"_a, DOC(Bentley, DgnPlatform, ElementTemplateUtils, CreateByPath));

    c1.def_static("FindTemplateNodeByPath", py::overload_cast<WCharCP, XDataTreeOwner&>(&ElementTemplateUtils::FindTemplateNodeByPath), "templatePath"_a, "owner"_a, DOC(Bentley, DgnPlatform, ElementTemplateUtils, FindTemplateNodeByPath));
    c1.def_static("FindTemplateNodeByPath", py::overload_cast<WCharCP, DgnFileR>(&ElementTemplateUtils::FindTemplateNodeByPath), "templatePath"_a, "dgnFile"_a, DOC(Bentley, DgnPlatform, ElementTemplateUtils, FindTemplateNodeByPath));
    c1.def_static("GetTemplateNodeUsingDependentElement", &ElementTemplateUtils::GetTemplateNodeUsingDependentElement, "elemRef"_a, DOC(Bentley, DgnPlatform, ElementTemplateUtils, GetTemplateNodeUsingDependentElement));
    c1.def_static("IsTemplateInUse", &ElementTemplateUtils::IsTemplateInUse, "templateNode"_a, "loadAllModels"_a = false, DOC(Bentley, DgnPlatform, ElementTemplateUtils, IsTemplateInUse));
    c1.def_static("AddItemToTemplate", &ElementTemplateUtils::AddItemToTemplate, "templateNode"_a, "itemInstance"_a, DOC(Bentley, DgnPlatform, ElementTemplateUtils, AddItemToTemplate));
    c1.def_static("AttachItemToElement", &ElementTemplateUtils::AttachItemToElement, "elemRef"_a, "itemInstance"_a, DOC(Bentley, DgnPlatform, ElementTemplateUtils, AttachItemToElement));

    c1.def_static("WriteTemplateNode", &ElementTemplateUtils::WriteTemplateNode, "templateNode"_a, DOC(Bentley, DgnPlatform, ElementTemplateUtils, WriteTemplateNode));
    c1.def_static("GetElementTemplateHandlerId", &ElementTemplateUtils::GetElementTemplateHandlerId, DOC(Bentley, DgnPlatform, ElementTemplateUtils, GetElementTemplateHandlerId));
    }