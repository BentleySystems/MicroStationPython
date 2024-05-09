/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnPlatform\source\templaterefhandler.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <DgnPlatform/TemplateRefHandler.h>



static const char * __doc_Bentley_DgnPlatform_TemplateRefAttributes_AttachToElementRef =R"doc(Attach a reference to Element Template to the specified specified
element. If the element already contains a reference it will be
replaced. The XAttribute are written immediately.

Parameter ``elemRef``:
    The element to receive the Element Template reference.

Parameter ``templateNode``:
    The template node that defines the Element Template to reference.

Parameter ``applyDefaultSymbology``:
    If true the element is updated to match the default symbology
    specifications in the template. @Return SUCCESS if the Element
    Template reference was attached.)doc";

static const char * __doc_Bentley_DgnPlatform_TemplateRefAttributes_GetReferencedTemplateIDFromHandle =R"doc(Get the ElementId of the element template referenced by an element.

Parameter ``elem``:
    A reference to an element that contains an Element Template
    reference. @Return ElementId of the referenced template or 0 if
    not referenced to an element template.)doc";

static const char * __doc_Bentley_DgnPlatform_TemplateRefAttributes_GetReferencedTemplateID =R"doc(Get the ElementId of the element template referenced by the existing
element.

Parameter ``elemRef``:
    A reference to an existing element that contains an Element
    Template reference. @Return ElementId of the referenced template
    or 0 if not referenced to an element template.)doc";

static const char * __doc_Bentley_DgnPlatform_TemplateRefAttributes_GetReferencedTemplatePath =R"doc(Get the Template Path or the referenced element template.

Parameter ``elementRef``:
    A reference to an existing element that contains an Element
    Template reference.

Parameter ``templatePath``:
    The path of the referenced Element Template. @Return SUCCESS if
    the Element Template path can be returned.)doc";

static const char * __doc_Bentley_DgnPlatform_TemplateRefAttributes_AttachToHandle =R"doc(Attach a reference to Element Template to the specified specified
element. If the element already contains a reference it will be
replaced.

Parameter ``eeh``:
    The element to receive the Element Template reference.

Parameter ``templateNode``:
    The template node that defines the Element Template to reference.

Parameter ``applyDefaultSymbology``:
    If true the element is updated to match the default symbology
    specifications in the template. @Return SUCCESS if the Element
    Template reference was attached.)doc";

static const char * __doc_Bentley_DgnPlatform_TemplateRefAttributes_Remove =R"doc(Remove reference to Element Template from specified element.

Parameter ``elemRef``:
    A reference to an existing element that contains an Element
    Template reference. @Return SUCCESS if the Element Template
    reference was removed.)doc";

static const char * __doc_Bentley_DgnPlatform_ElementTemplateReferenceEventManager_HasRegisteredMonitors =R"doc(Returns true if element template reference monitors are defined.)doc";

static const char * __doc_Bentley_DgnPlatform_ElementTemplateReferenceEventManager_UnregisterEventMonitor =R"doc(Unregister an event monitor

Parameter ``monitor``:
    A monitor class. @Return SUCCESS if the ElementTemplateRef monitor
    was unregistered.)doc";

static const char * __doc_Bentley_DgnPlatform_ElementTemplateReferenceEventManager_RegisterEventMonitor =R"doc(Register an event monitor

Parameter ``monitor``:
    A monitor class. @Return SUCCESS if the ElementTemplateRef monitor
    was registered.)doc";

static const char * __doc_Bentley_DgnPlatform_ElementTemplateReferenceEventManager_GetManager =R"doc(Get the singleton ElementTemplateReferenceEventManager)doc";

static const char * __doc_Bentley_DgnPlatform_IElementTemplateRefMonitor_OnElementTemplateReferenceRemoved =R"doc(Monitor method called when the reference element template is removed.

Parameter ``dependent``:
    Element containing an element template reference.)doc";

static const char * __doc_Bentley_DgnPlatform_IElementTemplateRefMonitor_OnElementTemplateReferenceAdded =R"doc(Monitor method called when the reference element template is added.

Parameter ``dependent``:
    Element containing an element template reference.

Parameter ``templateId``:
    The ElementId of the element template being changed.)doc";

static const char * __doc_Bentley_DgnPlatform_IElementTemplateRefMonitor_OnReferencedElementTemplateChanged =R"doc(Monitor method called when the reference element template is changed.

Parameter ``dependent``:
    Element containing an element template reference.

Parameter ``templateId``:
    The ElementId of the element template being changed.)doc";

//=======================================================================================
// Trampoline class for IElementTemplateRefMonitor.
// @bsiclass                                                                   02/23
//=======================================================================================
struct IPyElementTemplateRefMonitor : IElementTemplateRefMonitor
    {
    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       2/2023
    +---------------+---------------+---------------+---------------+---------------+------*/        
    virtual void OnReferencedElementTemplateChanged(ElementHandleCR dependent, ElementId templateId) override
        { PYBIND11_OVERRIDE_PURE_EX(void, IElementTemplateRefMonitor, OnReferencedElementTemplateChanged, dependent, templateId); }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       2/2023
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void OnElementTemplateReferenceAdded(ElementHandleCR dependent, ElementId templateId) override
        { PYBIND11_OVERRIDE_PURE_EX(void, IElementTemplateRefMonitor, OnElementTemplateReferenceAdded, dependent, templateId); }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       2/2023
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void OnElementTemplateReferenceRemoved(ElementHandleCR dependent) override
        { PYBIND11_OVERRIDE_PURE_EX(void, IElementTemplateRefMonitor, OnElementTemplateReferenceRemoved, dependent); }
    };

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_TemplateRefHandler(py::module_& m)
    {
    //===================================================================================
    // struct IElementTemplateRefMonitor
    py::class_< IElementTemplateRefMonitor
        , std::unique_ptr< IElementTemplateRefMonitor, py::nodelete>
        , IPyElementTemplateRefMonitor> c1(m, "IElementTemplateRefMonitor");

    c1.def(py::init<>());
    c1.def("OnReferencedElementTemplateChanged", &IElementTemplateRefMonitor::OnReferencedElementTemplateChanged, "dependent"_a, "templateId"_a, DOC(Bentley, DgnPlatform, IElementTemplateRefMonitor, OnReferencedElementTemplateChanged));
    c1.def("OnElementTemplateReferenceAdded", &IElementTemplateRefMonitor::OnElementTemplateReferenceAdded, "dependent"_a, "templateId"_a, DOC(Bentley, DgnPlatform, IElementTemplateRefMonitor, OnElementTemplateReferenceAdded));
    c1.def("OnElementTemplateReferenceRemoved", &IElementTemplateRefMonitor::OnElementTemplateReferenceRemoved, "dependent"_a, DOC(Bentley, DgnPlatform, IElementTemplateRefMonitor, OnElementTemplateReferenceRemoved));

    //===================================================================================
    // struct ElementTemplateReferenceEventManager
    py::class_< ElementTemplateReferenceEventManager
        , std::unique_ptr<ElementTemplateReferenceEventManager, py::nodelete>
        , DgnHost::IHostObject> c2(m, "ElementTemplateReferenceEventManager");

    c2.def_static("GetManager", &ElementTemplateReferenceEventManager::GetManager, py::return_value_policy::reference, DOC(Bentley, DgnPlatform, ElementTemplateReferenceEventManager, GetManager));
    c2.def("RegisterEventMonitor", &ElementTemplateReferenceEventManager::RegisterEventMonitor, "monitor"_a, py::keep_alive<1, 2>(), DOC(Bentley, DgnPlatform, ElementTemplateReferenceEventManager, RegisterEventMonitor));
    c2.def("UnregisterEventMonitor", &ElementTemplateReferenceEventManager::UnregisterEventMonitor, "monitor"_a, DOC(Bentley, DgnPlatform, ElementTemplateReferenceEventManager, UnregisterEventMonitor));
    c2.def("HasRegisteredMonitors", &ElementTemplateReferenceEventManager::HasRegisteredMonitors, DOC(Bentley, DgnPlatform, ElementTemplateReferenceEventManager, HasRegisteredMonitors));

    //===================================================================================
    // struct TemplateRefAttributes
    py::class_< TemplateRefAttributes> c3(m, "TemplateRefAttributes");

    c3.def_static("Remove", &TemplateRefAttributes::Remove, "elemRef"_a, DOC(Bentley, DgnPlatform, TemplateRefAttributes, Remove));
    
    c3.def_static("AttachToHandle", [] (EditElementHandleR eeh, bool applyDefaultSymbology)
                  {
                  ElementTemplateNodePtr templateNode;
                  auto retVal = TemplateRefAttributes::AttachToHandle(eeh, templateNode, applyDefaultSymbology);
                  return py::make_tuple(retVal, templateNode);
                  }, "eeh"_a, "applyDefaultSymbology"_a, DOC(Bentley, DgnPlatform, TemplateRefAttributes, AttachToHandle));

    c3.def_static("GetReferencedTemplatePath", &TemplateRefAttributes::GetReferencedTemplatePath, "elemRef"_a, "templatePath"_a, DOC(Bentley, DgnPlatform, TemplateRefAttributes, GetReferencedTemplatePath));

    c3.def_static("GetReferencedTemplateID", &TemplateRefAttributes::GetReferencedTemplateID, "elemRef"_a, DOC(Bentley, DgnPlatform, TemplateRefAttributes, GetReferencedTemplateID));

    c3.def_static("GetReferencedTemplateIDFromHandle", &TemplateRefAttributes::GetReferencedTemplateIDFromHandle, "eh"_a, DOC(Bentley, DgnPlatform, TemplateRefAttributes, GetReferencedTemplateIDFromHandle));

    c3.def_static("AttachToElementRef", [] (ElementRefP elemRef, bool applyDefaultSymbology)
                  {
                  ElementTemplateNodePtr templateNode;
                  auto retVal = TemplateRefAttributes::AttachToElementRef(elemRef, templateNode, applyDefaultSymbology);
                  return py::make_tuple(retVal, templateNode);
                  }, "elemRef"_a, "applyDefaultSymbology"_a, DOC(Bentley, DgnPlatform, TemplateRefAttributes, AttachToElementRef));
    }