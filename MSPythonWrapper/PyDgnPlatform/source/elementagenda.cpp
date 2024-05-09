/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnPlatform\source\elementagenda.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <DgnView/IRedraw.h>
#include <DgnPlatform/ElementAgenda.h>



static const char * __doc_Bentley_DgnPlatform_ElementAgenda_Insert =R"doc(Insert an element into this ElementAgenda.

Parameter ``eeh``:
    The EditElementHandle that is to be inserted into this agenda; if
    it has a descriptor, it will be extracted and used; otherwise an
    element ref will be used. If neither are present, nothing is
    added.

Parameter ``atHead``:
    If true, put this in at the head (front) of the agenda, otherwise
    put it at the end. Passing false is more efficient.

Returns:
    A pointer to the EditElementHandle within the ElementAgenda
    holding ``elDscr.`` @note If the EditElementHandle you provide has
    a descriptor, this will extract and then own the descriptor; you
    can thus not use the EditElementHandle; use this method's return
    value instead. @note For performance reasons, no attempt is made
    to enforce uniqueness of the entries (i.e. this method will allow
    duplicate entries for the same element, even though that's
    generally undesirable.) If you're unsure whether the entry you're
    adding may already be in the agenda, call #Find. Also, see
    #Insert(ElemModelPairSet&) for more efficient technique to enforce
    uniqueness for large sets.

Remark:
    Required library:DgnPlatform<ApiNumber>.lib i.e. DgnPlatform5.lib)doc";

static const char * __doc_Bentley_DgnPlatform_ElementAgenda_Find =R"doc(Attempt to find an ElementRefP/DgnModelRef pair in this ElementAgenda.

Parameter ``elRef``:
    The ElementRefP part of the pair.

Parameter ``modelRef``:
    The DgnModelRef part of the pair.

Parameter ``startIndex``:
    The index of the first entry to be considered for the Find
    operation.

Parameter ``endIndex``:
    The index of the last entry to be considered for the Find
    operation.

Returns:
    A pointer to the EditElementHandle holding the pair, or NULL if
    not found.

Remark:
    Required library:DgnPlatform<ApiNumber>.lib i.e. DgnPlatform5.lib)doc";

static const char * __doc_Bentley_DgnPlatform_ElementAgenda_SetSource =R"doc(Set the source for this ElementAgenda.

See also:
    #GetSource)doc";

static const char * __doc_Bentley_DgnPlatform_ElementAgenda_GetSource =R"doc(Get the source for this ElementAgenda, if applicable. The " source " is
merely an indication of what the collection of elements in this agenda
means. Also, if the source is ModifyElementSource::SelectionSet,
MicroStation internally attempts to keep the Selection Set current
with changes to the agenda.)doc";

static const char * __doc_Bentley_DgnPlatform_ElementAgenda_SetCapacity =R"doc(Set the capacity for this ElementAgenda. If you expect to add a large
number of entries to the agenda, and if you know how many there will
be, then calling this method first can improve performance.

Parameter ``nEntries``:
    Set the array hold at least this number of entries.)doc";

static const char * __doc_Bentley_DgnPlatform_IElementAgendaEvents__OnRedrawGroupEvent =R"doc(Called to allow listener to participate in element set dynamics. See
RedrawGroupInfo for return status meaning.)doc";

static const char * __doc_Bentley_DgnPlatform_IElementAgendaEvents__DoAddDeferredClipboardFormats =R"doc(@cond DONTINCLUDEINDOC Called to allow custom clipboard formats to be
added for the elements in the agenda.)doc";

static const char * __doc_Bentley_DgnPlatform_IElementAgendaEvents__OnPostModifyAgenda =R"doc(Called after the tool operation is applied to the agenda.)doc";

static const char * __doc_Bentley_DgnPlatform_IElementAgendaEvents__OnPreModifyAgenda =R"doc(Called before the tool operation is applied to the agenda.)doc";

static const char * __doc_Bentley_DgnPlatform_IElementAgendaEvents__OnPreCopyAgenda =R"doc(Called to allow listeners to copy additional information from source
to destination not appropriate to tool operation.)doc";

static const char * __doc_Bentley_DgnPlatform_IElementAgendaEvents__DoModifyAgendaEntries =R"doc(Called to allow listeners to modify the agenda by adding/removing
entries before applying tool operation. Return true if entries added
or invalidated.)doc";

static const char * __doc_Bentley_DgnPlatform_RedrawGroupInfo_GetModifiedElement =R"doc(Remark:
    Required library:DgnPlatform<ApiNumber>.lib i.e. DgnPlatform5.lib)doc";

static const char * __doc_Bentley_DgnPlatform_RedrawGroupInfo_GetOriginalElement =R"doc(Remark:
    Required library:DgnPlatform<ApiNumber>.lib i.e. DgnPlatform5.lib)doc";

static const char * __doc_Bentley_DgnPlatform_RedrawGroupInfo_GetViewContext =R"doc(Remark:
    Required library:DgnPlatform<ApiNumber>.lib i.e. DgnPlatform5.lib)doc";

static const char * __doc_Bentley_DgnPlatform_RedrawGroupInfo_GetEventType =R"doc(Remark:
    Required library:DgnPlatform<ApiNumber>.lib i.e. DgnPlatform5.lib)doc";

//=======================================================================================
// Trampoline class for IElementAgendaEvents.
// @bsiclass                                                                   02/23
//=======================================================================================
struct IPyElementAgendaEvents : IElementAgendaEvents
    {
    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       2/2023
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual bool _DoModifyAgendaEntries(ElementAgendaP agenda, AgendaOperation operation, AgendaModify modify) override
        { PYBIND11_OVERRIDE_EXR(bool, IElementAgendaEvents, _DoModifyAgendaEntries, false, agenda, operation, modify); }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       2/2023
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void _OnPreCopyAgenda(ElementAgendaCP agenda, AgendaOperation operation, AgendaModify modify, ElementCopyContextP context) override
        { PYBIND11_OVERRIDE_EX(void, IElementAgendaEvents, _OnPreCopyAgenda, agenda, operation, modify, context); }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       2/2023
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void _OnPreModifyAgenda(ElementAgendaCP agenda, AgendaOperation operation, AgendaModify modify, bool isGroupOperation) override
        { PYBIND11_OVERRIDE_EX(void, IElementAgendaEvents, _OnPreModifyAgenda, agenda, operation, modify, isGroupOperation); }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       2/2023
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void _OnPostModifyAgenda(ElementAgendaCP agenda, AgendaOperation operation, AgendaModify modify, bool isGroupOperation) override
        { PYBIND11_OVERRIDE_EX(void, IElementAgendaEvents, _OnPostModifyAgenda, agenda, operation, modify, isGroupOperation); }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       2/2023
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void _DoAddDeferredClipboardFormats(ElementAgendaP agenda, AgendaOperation operation, AgendaModify modify, GuiDataObject* dataObj) override
        { PYBIND11_OVERRIDE_EX(void, IElementAgendaEvents, _DoAddDeferredClipboardFormats, agenda, operation, modify, dataObj); }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       2/2023
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual bool _OnRedrawGroupEvent(ElementAgendaCP agenda, AgendaOperation operation, AgendaModify modify, RedrawGroupInfo const* groupInfo) override
        { PYBIND11_OVERRIDE_EXR(bool, IElementAgendaEvents, _OnRedrawGroupEvent, false, agenda, operation, modify, groupInfo); }
    };

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_ElementAgenda(py::module_& m)
    {
    //===================================================================================
    // enum class ModifyElementSource
    py::enum_< ModifyElementSource>(m, "ModifyElementSource")
        .value("eSelected", ModifyElementSource::Selected)
        .value("eSelectionSet", ModifyElementSource::SelectionSet)
        .value("eFence", ModifyElementSource::Fence)
        .value("eWorkingSet", ModifyElementSource::WorkingSet)
        .value("eGraphicGroup", ModifyElementSource::GraphicGroup)
        .value("eNamedGroup_", ModifyElementSource::NamedGroup)
        .value("eDragSelection", ModifyElementSource::DragSelection)
        .value("eUnknown", ModifyElementSource::Unknown)
        .export_values();

    //===================================================================================
    // class T_AgendumVector
    py::class_< T_AgendumVector> c1(m, "T_AgendumVector", py::multiple_inheritance());

    c1.def("IsEmpty", &T_AgendumVector::IsEmpty);
    c1.def("__bool__", [] (T_AgendumVector& self) { return !self.IsEmpty(); });

    c1.def_property_readonly("Count", &T_AgendumVector::GetCount);
    c1.def("GetCount", &T_AgendumVector::GetCount);
    c1.def("__len__", &T_AgendumVector::GetCount);
    
    c1.def_property_readonly("First", &T_AgendumVector::GetFirstP);
    c1.def("GetFirst", &T_AgendumVector::GetFirstP, py::return_value_policy::reference_internal);
    
    c1.def_property_readonly("Last", &T_AgendumVector::GetLastP);
    c1.def("GetLast", &T_AgendumVector::GetLastP, py::return_value_policy::reference_internal);
    
    c1.def("GetEntry", &T_AgendumVector::GetEntryP, "index"_a, py::return_value_policy::reference_internal);
    c1.def("Empty", &T_AgendumVector::Empty, "andFree"_a = true);
    c1.def("DropInvalidEntries", &T_AgendumVector::DropInvalidEntries);
    c1.def("__iter__", [] (T_AgendumVector& self) { return py::make_iterator(self.begin(), self.end()); }, py::keep_alive<0, 1>());

    //===================================================================================
    // struct RedrawGroupInfo
    py::class_< RedrawGroupInfo> c2(m, "RedrawGroupInfo");

    if (true)
        {
        //===================================================================================
        // enum class GroupEvent
        py::enum_< RedrawGroupInfo::GroupEvent>(m, "GroupEvent")
            .value("eOnGroupInit", RedrawGroupInfo::GroupEvent::OnGroupInit)
            .value("eIsElementInGroup", RedrawGroupInfo::GroupEvent::IsElementInGroup)
            .value("eOnPostModifyElement", RedrawGroupInfo::GroupEvent::OnPostModifyElement)
            .value("eOnPostModifyGroup", RedrawGroupInfo::GroupEvent::OnPostModifyGroup)
            .value("eOnGroupComplete", RedrawGroupInfo::GroupEvent::OnGroupComplete)
            .export_values();
        }

    c2.def_property_readonly("EventType", &RedrawGroupInfo::GetEventType);
    c2.def("GetEventType", &RedrawGroupInfo::GetEventType, DOC(Bentley, DgnPlatform, RedrawGroupInfo, GetEventType));
    
    c2.def_property_readonly("ViewContext", &RedrawGroupInfo::GetViewContext);
    c2.def("GetViewContext", &RedrawGroupInfo::GetViewContext, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, RedrawGroupInfo, GetViewContext));
    
    c2.def_property_readonly("OriginalElement", &RedrawGroupInfo::GetOriginalElement);
    c2.def("GetOriginalElement", &RedrawGroupInfo::GetOriginalElement, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, RedrawGroupInfo, GetOriginalElement));
    
    c2.def_property_readonly("ModifiedElement", &RedrawGroupInfo::GetModifiedElement);
    c2.def("GetModifiedElement", &RedrawGroupInfo::GetModifiedElement, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, RedrawGroupInfo, GetModifiedElement));

    //===================================================================================
    // struct IElementAgendaEvents
    py::class_< IElementAgendaEvents, IPyElementAgendaEvents> c3(m, "IElementAgendaEvents");

    c3.def(py::init<>());
    c3.def("_DoModifyAgendaEntries", &IElementAgendaEvents::_DoModifyAgendaEntries, "agenda"_a, "operation"_a, "modify"_a, DOC(Bentley, DgnPlatform, IElementAgendaEvents, _DoModifyAgendaEntries));
    c3.def("_OnPreCopyAgenda", &IElementAgendaEvents::_OnPreCopyAgenda, "agenda"_a, "operation"_a, "modify"_a, "context"_a, DOC(Bentley, DgnPlatform, IElementAgendaEvents, _OnPreCopyAgenda));
    c3.def("_OnPreModifyAgenda", &IElementAgendaEvents::_OnPreModifyAgenda, "agenda"_a, "operation"_a, "modify"_a, "isGroupOperation"_a, DOC(Bentley, DgnPlatform, IElementAgendaEvents, _OnPreModifyAgenda));
    c3.def("_OnPostModifyAgenda", &IElementAgendaEvents::_OnPostModifyAgenda, "agenda"_a, "operation"_a, "modify"_a, "isGroupOperation"_a, DOC(Bentley, DgnPlatform, IElementAgendaEvents, _OnPostModifyAgenda));
    c3.def("_DoAddDeferredClipboardFormats", &IElementAgendaEvents::_DoAddDeferredClipboardFormats, "agenda"_a, "operation"_a, "modify"_a, "guiObj"_a, DOC(Bentley, DgnPlatform, IElementAgendaEvents, _DoAddDeferredClipboardFormats));
    c3.def("_OnRedrawGroupEvent", &IElementAgendaEvents::_OnRedrawGroupEvent, "agenda"_a, "operation"_a, "modify"_a, "groupInfo"_a, DOC(Bentley, DgnPlatform, IElementAgendaEvents, _OnRedrawGroupEvent));        

    //===================================================================================
    // struct ElemAgendaEntry
    py::class_< ElemAgendaEntry, EditElementHandle> c4(m, "ElemAgendaEntry");

    c4.def(py::init<>());
    c4.def(py::init<ElementRefP, DgnModelRefP>(), "elRef"_a, "modelRef"_a);
    c4.def(py::init<ElementHandleCR, bool>(), "from"_a, "duplicateDescr"_a);        

    //===================================================================================
    // enum class AgendaHilitedState
    py::enum_< AgendaHilitedState>(m, "AgendaHilitedState")
        .value("eUnknown", AgendaHilitedState::Unknown)
        .value("eYes", AgendaHilitedState::Yes)
        .value("eNo", AgendaHilitedState::No)
        .export_values();

    //===================================================================================
    using T_AgendumVectorRef = RefCounted< T_AgendumVector>;
    py::class_< T_AgendumVectorRef, std::unique_ptr<T_AgendumVectorRef, py::nodelete>, T_AgendumVector> c4x(m, "T_AgendumVectorRef");

    //===================================================================================
    // struct ElementAgenda
    py::class_< ElementAgenda, T_AgendumVectorRef > c5(m, "ElementAgenda");

    c5.def(py::init<>());
    c5.def("SetCapacity", &ElementAgenda::SetCapacity, "nEntries"_a, DOC(Bentley, DgnPlatform, ElementAgenda, SetCapacity));

    c5.def_property("Source", &ElementAgenda::GetSource, &ElementAgenda::SetSource);
    c5.def("GetSource", &ElementAgenda::GetSource, DOC(Bentley, DgnPlatform, ElementAgenda, GetSource));
    c5.def("SetSource", &ElementAgenda::SetSource, "value"_a, DOC(Bentley, DgnPlatform, ElementAgenda, SetSource));
    
    c5.def("Find", &ElementAgenda::Find, "elRef"_a, "modelRef"_a, "startIndex"_a= 0, "endIndex"_a = -1, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, ElementAgenda, Find));
    c5.def("Insert", py::overload_cast<EditElementHandleR, bool>(&ElementAgenda::Insert), "eeh"_a, "atHead"_a = false, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, ElementAgenda, Insert));
    c5.def("Insert", py::overload_cast<ElementRefP, DgnModelRefP, bool>(&ElementAgenda::Insert), "elRef"_a, "modelRef"_a, "atHead"_a = false, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, ElementAgenda, Insert));
    }