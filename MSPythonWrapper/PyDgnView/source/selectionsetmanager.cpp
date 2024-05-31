/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnView\source\selectionsetmanager.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <DgnView/SelectionSetManager.h>



static const char * __doc_Bentley_DgnPlatform_SelectionSetManager_GetManager =R"doc(Get the manager class for selection sets.

Returns:
    The SelectionSetManager class. Bentley Systems +---------------+--
    -------------+---------------+---------------+---------------+----
    --)doc";

static const char * __doc_Bentley_DgnPlatform_SelectionSetManager_ModifyWithElementSets =R"doc(Modifies current selection by removing and adding sets of elements.

Parameter ``toRemove``:
    IN Elements to remove.

Parameter ``toAdd``:
    IN Elements to add.

Returns:
    SUCCESS if at least one entry was added or removed. @note Remove
    list is processed before add list. Bentley Systems +--------------
    -+---------------+---------------+---------------+---------------+
    ------)doc";

static const char * __doc_Bentley_DgnPlatform_SelectionSetManager_ReplaceWithElementSet =R"doc(Set the current selection set to the supplied set of elements.

Parameter ``elSet``:
    IN Elements to become current selection.

Returns:
    SUCCESS if current selection was changed. Bentley Systems +-------
    --------+---------------+---------------+---------------+---------
    ------+------)doc";

static const char * __doc_Bentley_DgnPlatform_SelectionSetManager_ReplaceWithElement =R"doc(Set the current selection set to the supplied element.

Parameter ``elem``:
    IN Element to become new selection.

Parameter ``elemModel``:
    IN DgnModelRef of replacement element.

Returns:
    SUCCESS if current selection was changed. Bentley Systems +-------
    --------+---------------+---------------+---------------+---------
    ------+------)doc";

static const char * __doc_Bentley_DgnPlatform_SelectionSetManager_InvertElementSet =R"doc(Add elements not currently selected and remove elements currently
selected.

Parameter ``elSet``:
    IN Elements to process.

Returns:
    SUCCESS if current selection was changed. Bentley Systems +-------
    --------+---------------+---------------+---------------+---------
    ------+------)doc";

static const char * __doc_Bentley_DgnPlatform_SelectionSetManager_InvertElement =R"doc(Add element not currently selected and remove element currently
selected.

Parameter ``elem``:
    IN Element to process.

Parameter ``elemModel``:
    IN DgnModelRef of element being processed.

Returns:
    SUCCESS if current selection was changed. Bentley Systems +-------
    --------+---------------+---------------+---------------+---------
    ------+------)doc";

static const char * __doc_Bentley_DgnPlatform_SelectionSetManager_RemoveElementSet =R"doc(Remove a set of elements to the current selection set.

Parameter ``elSet``:
    IN Elements to remove.

Returns:
    SUCCESS if at least one entry was removed. Bentley Systems +------
    ---------+---------------+---------------+---------------+--------
    -------+------)doc";

static const char * __doc_Bentley_DgnPlatform_SelectionSetManager_RemoveElement =R"doc(Remove an element from the current selection set.

Parameter ``elem``:
    IN Element to remove.

Parameter ``elemModel``:
    IN DgnModelRef of element being removed.

Returns:
    SUCCESS if entry was removed. Bentley Systems +---------------+---
    ------------+---------------+---------------+---------------+-----
    -)doc";

static const char * __doc_Bentley_DgnPlatform_SelectionSetManager_AddElementSet =R"doc(Add a set of elements to the current selection set.

Parameter ``elSet``:
    IN Elements to add.

Returns:
    SUCCESS if at least one entry was added. Bentley Systems +--------
    -------+---------------+---------------+---------------+----------
    -----+------)doc";

static const char * __doc_Bentley_DgnPlatform_SelectionSetManager_AddElement =R"doc(Add an element to the current selection set.

Parameter ``elem``:
    IN Element to add.

Parameter ``elemModel``:
    IN DgnModelRef of element being added.

Returns:
    SUCCESS if entry was added. Bentley Systems +---------------+-----
    ----------+---------------+---------------+---------------+------)doc";

static const char * __doc_Bentley_DgnPlatform_SelectionSetManager_ActivatePrevious =R"doc(Make previous selection set current. Bentley Systems +---------------+
---------------+---------------+---------------+---------------+------)doc";

static const char * __doc_Bentley_DgnPlatform_SelectionSetManager_EmptyAll =R"doc(Clear current selection set. Current selection set becomes previous
selection set. Bentley Systems +---------------+---------------+------
---------+---------------+---------------+------)doc";

static const char * __doc_Bentley_DgnPlatform_SelectionSetManager_BuildAgenda =R"doc(Populate an element agenda suitable for modification from the current
selection set.

Parameter ``agenda``:
    IN OUT selection set entries that passed the input criteria.

Parameter ``searchList``:
    IN list of acceptable modelRefs to filter selection set entries..

Parameter ``modifyOrig``:
    IN whether agenda will be used to modify original elements.

Parameter ``allowLocked``:
    IN whether to accept locked elements.

Parameter ``callAsynch``:
    IN whether to call GLOBAL_LOCATE_SELECTIONSET filter.

Returns:
    SUCCESS if agenda contains at least one entry. Bentley Systems +--
    -------------+---------------+---------------+---------------+----
    -----------+------)doc";

static const char * __doc_Bentley_DgnPlatform_SelectionSetManager_DropListener =R"doc(Drop selection set changed/event listener.

Parameter ``selectionListener``:
    IN The listener object to drop. Bentley Systems +---------------+-
    --------------+---------------+---------------+---------------+---
    ---)doc";

static const char * __doc_Bentley_DgnPlatform_SelectionSetManager_AddListener =R"doc(Add selection set changed/event listener.

Parameter ``selectionListener``:
    IN The listener object to add. Bentley Systems +---------------+--
    -------------+---------------+---------------+---------------+----
    --)doc";

static const char * __doc_Bentley_DgnPlatform_SelectionSetManager_GetElement =R"doc(Get the ElementRefP and DgnModelRef in the current selection set by
index.

Parameter ``index``:
    IN The index to get the entry for.

Parameter ``elemRef``:
    OUT ElementRefP at index.

Parameter ``modelRef``:
    OUT DgnModelRef at index.

Returns:
    SUCCESS if index was valid. Bentley Systems +---------------+-----
    ----------+---------------+---------------+---------------+------)doc";

static const char * __doc_Bentley_DgnPlatform_SelectionSetManager_NumSelected =R"doc(Get the number of entries in the current selection set.

Returns:
    count of entries in current selection set. Bentley Systems +------
    ---------+---------------+---------------+---------------+--------
    -------+------)doc";

static const char * __doc_Bentley_DgnPlatform_SelectionSetManager_IsActive =R"doc(Check whether there is a current selection set active.

Returns:
    true if current selection set contains at least one entry. Bentley
    Systems +---------------+---------------+---------------+---------
    ------+---------------+------)doc";

static const char * __doc_Bentley_DgnPlatform_ISelectionEvents__OnSelectionEvent =R"doc(Notification of a specific event.

Returns:
    true to stop.)doc";

static const char * __doc_Bentley_DgnPlatform_ISelectionEvents__OnSelectionChanged =R"doc(Called when current selection set is changed in any way. Elements
added, removed, cleared, etc.)doc";

//=======================================================================================
// Trampoline class for ISelectionEvents
// @bsiclass                                                                   02/23
//=======================================================================================
struct IPySelectionEvents : ISelectionEvents
    {
    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       2/2023
    +---------------+---------------+---------------+---------------+---------------+------*/        
    virtual void _OnSelectionChanged() override
        { PYBIND11_OVERRIDE_PURE_EX(void, ISelectionEvents, _OnSelectionChanged, ); }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       2/2023
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual bool _OnSelectionEvent(SelectionSetAction action, ElementRefP elemRef, DgnModelRefP modelRef) override
        { PYBIND11_OVERRIDE_EXR(bool, ISelectionEvents, _OnSelectionEvent, false, action, elemRef, modelRef); }
    };

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_SelectionSetManager(py::module_& m)
    {
    //===================================================================================
    // enum SelectionSetAction
    py::enum_< SelectionSetAction>(m, "SelectionSetAction", py::arithmetic())
        .value("eSELECT_NOTHING", SELECT_NOTHING)
        .value("eSELECT_STRETCH", SELECT_STRETCH)
        .value("eSELECT_WINDOW", SELECT_WINDOW)
        .value("eSELECT_DRAG", SELECT_DRAG)
        .value("eSELECT_DRAG_NEW", SELECT_DRAG_NEW)
        .value("eSELECT_SS_EMPTY", SELECT_SS_EMPTY)
        .value("eSELECT_SS_CHANGED", SELECT_SS_CHANGED)
        .value("eSELECT_DOUBLECLICK_HANDLE", SELECT_DOUBLECLICK_HANDLE)
        .value("eSELECT_DOUBLECLICK_ELEMENT", SELECT_DOUBLECLICK_ELEMENT)
        .export_values();

    //===================================================================================
    // struct ISelectionEvents
    py::class_< ISelectionEvents, std::unique_ptr<ISelectionEvents, py::nodelete>, IPySelectionEvents> c1(m, "ISelectionEvents");

    c1.def("_OnSelectionChanged", &ISelectionEvents::_OnSelectionChanged, DOC(Bentley, DgnPlatform, ISelectionEvents, _OnSelectionChanged));
    c1.def("_OnSelectionEvent", &ISelectionEvents::_OnSelectionEvent, "action"_a, "elemRef"_a, "modelRef"_a, DOC(Bentley, DgnPlatform, ISelectionEvents, _OnSelectionEvent));
    c1.def(py::init<>());

    //===================================================================================
    // struct SelectionSetManager
    py::class_ < SelectionSetManager, std::unique_ptr < SelectionSetManager, py::nodelete>/*, TxnMonitor*/ > c2(m, "SelectionSetManager");

    c2.def("IsActive", &SelectionSetManager::IsActive, DOC(Bentley, DgnPlatform, SelectionSetManager, IsActive));
    c2.def("NumSelected", &SelectionSetManager::NumSelected, DOC(Bentley, DgnPlatform, SelectionSetManager, NumSelected));    
    
    c2.def("GetElement", [] (SelectionSetManager& self, size_t index, ElementHandleR eh)
           {
           ElementRefP elemRef = nullptr;
           DgnModelRefP modelRef = nullptr;
           auto retVal = self.GetElement(index, &elemRef, &modelRef);
           if (retVal == SUCCESS)
               eh = ElementHandle(elemRef, modelRef);
           return retVal;
           }, "index"_a, "eh"_a, DOC(Bentley, DgnPlatform, SelectionSetManager, GetElement));

    c2.def("AddListener", &SelectionSetManager::AddListener, "listener"_a, py::keep_alive<1, 2>(), DOC(Bentley, DgnPlatform, SelectionSetManager, AddListener));
    c2.def("DropListener", &SelectionSetManager::DropListener, "listener"_a, DOC(Bentley, DgnPlatform, SelectionSetManager, DropListener));
    
    c2.def("BuildAgenda", 
           py::overload_cast<ElementAgendaR, DgnModelRefListP, bool, bool, bool>(&SelectionSetManager::BuildAgenda),
           "agenda"_a, "searchList"_a, "modifyOrig"_a, "allowLocked"_a, "callAsynch"_a, DOC(Bentley, DgnPlatform, SelectionSetManager, BuildAgenda));

    c2.def("BuildAgenda",
           py::overload_cast<ElementAgendaR>(&SelectionSetManager::BuildAgenda),
           "agenda"_a, DOC(Bentley, DgnPlatform, SelectionSetManager, BuildAgenda));

    c2.def("EmptyAll", &SelectionSetManager::EmptyAll, DOC(Bentley, DgnPlatform, SelectionSetManager, EmptyAll));
    c2.def("ActivatePrevious", &SelectionSetManager::ActivatePrevious, DOC(Bentley, DgnPlatform, SelectionSetManager, ActivatePrevious));
    c2.def("AddElement", &SelectionSetManager::AddElement, "elemRef"_a, "modelRef"_a, DOC(Bentley, DgnPlatform, SelectionSetManager, AddElement));
    c2.def("AddElementSet", &SelectionSetManager::AddElementSet, "elemSet"_a, DOC(Bentley, DgnPlatform, SelectionSetManager, AddElementSet));
    c2.def("RemoveElement", &SelectionSetManager::RemoveElement, "elemRef"_a, "modelRef"_a, DOC(Bentley, DgnPlatform, SelectionSetManager, RemoveElement));
    c2.def("RemoveElementSet", &SelectionSetManager::RemoveElementSet, "elemSet"_a, DOC(Bentley, DgnPlatform, SelectionSetManager, RemoveElementSet));
    c2.def("InvertElement", &SelectionSetManager::InvertElement, "elemRef"_a, "modelRef"_a, DOC(Bentley, DgnPlatform, SelectionSetManager, InvertElement));
    c2.def("InvertElementSet", &SelectionSetManager::InvertElementSet, "elemSet"_a, DOC(Bentley, DgnPlatform, SelectionSetManager, InvertElementSet));
    c2.def("ReplaceWithElement", &SelectionSetManager::ReplaceWithElement, "elemRef"_a, "modelRef"_a, DOC(Bentley, DgnPlatform, SelectionSetManager, ReplaceWithElement));
    c2.def("ReplaceWithElementSet", &SelectionSetManager::ReplaceWithElementSet, "elemSet"_a, DOC(Bentley, DgnPlatform, SelectionSetManager, ReplaceWithElementSet));
    c2.def("ModifyWithElementSets", &SelectionSetManager::ModifyWithElementSets, "toRemove"_a, "toAdd"_a, DOC(Bentley, DgnPlatform, SelectionSetManager, ModifyWithElementSets));
    c2.def_property_readonly_static("Manager", [] (py::object const&) { return std::unique_ptr<SelectionSetManager, py::nodelete>(&SelectionSetManager::GetManager()); });
    c2.def_static("GetManager", [] () { return std::unique_ptr<SelectionSetManager, py::nodelete>(&SelectionSetManager::GetManager()); }, DOC(Bentley, DgnPlatform, SelectionSetManager, GetManager));
    }