/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnPlatform\source\elementrefbase.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <RmgrTools/Tools/HeapZone.h>
#include <DgnPlatform/DgnFileIO/ElementRefBase.h>



static const char * __doc_Bentley_DgnPlatform_ElementRefBase_ValidateElementRef =R"doc(Determine whether this ElementRefP is still valid and, if not, attempt
to return the valid ElementRefP for the element. In certain (fairly
rare) cases when elements are rewritten to their DgnModel, their
ElementRefP can change. In that case, the old ElementRefP remains in
the DgnModel, but becomes " invalid ". [N.B. The reason the old
ElementRefP remains is that if the transaction is reversed (undone),
the old ElementRefP becomes valid again.] Call this method to get the
" current " valid ElementRefP for a known previously-valid ElementRefP.
If the element has moved, it uses the ElementId to find the valid
ElementRefP.

Returns:
    The valid ElementRefP for this element. In the common case where
    the element has *not* been moved to a new ElementRefP, this method
    will return itself. If the element or DgnModel has been deleted,
    this method will return NULL. @note It can be somewhat tricky to
    hold ElementRefs across undo/redo boundaries. You must be aware
    that for newly created elements, ElementRefs can be abandoned
    and/or reused after the transaction in which they were born is
    reversed (undone) and then not immediately reinstated (redone).)doc";

static const char * __doc_Bentley_DgnPlatform_ElementRefBase_IsGraphics =R"doc(Determine whether the element held by this ElementRefP is a Graphic
element.)doc";

static const char * __doc_Bentley_DgnPlatform_ElementRefBase_IsComplexComponent =R"doc(Determine whether the element held by this ElementRefP is a complex
component.)doc";

static const char * __doc_Bentley_DgnPlatform_ElementRefBase_GetLastModified =R"doc(Get the last modified time of the element held by this ElementRefP.)doc";

static const char * __doc_Bentley_DgnPlatform_ElementRefBase_GetLevel =R"doc(Get the level of the element held by this ElementRefP.)doc";

static const char * __doc_Bentley_DgnPlatform_ElementRefBase_GetElementType =R"doc(Get the element type of the element held by this ElementRefP.)doc";

static const char * __doc_Bentley_DgnPlatform_ElementRefBase_GetElementId =R"doc(Get the ElementId of the element held by this ElementRefP.)doc";

static const char * __doc_Bentley_DgnPlatform_ElementRefBase_IsDependent =R"doc(Determine whether another ElementRefP is dependent on this ElementRefP
(or, optionally, on any elements that are dependent on this
ElementRefP.)

Parameter ``isThisDependent``:
    Other element to test.

Parameter ``recurse``:
    If true, test whether *isThisDependent* is directly or indirectly
    depenent on this ElementRefP.)doc";

static const char * __doc_Bentley_DgnPlatform_ElementRefBase_GetParentElementRef =R"doc(Get the immediate parent of this ElementRefP. Will return NULL for
non-complex elements.)doc";

static const char * __doc_Bentley_DgnPlatform_ElementRefBase_FindAppData =R"doc(Find ElementRefAppData on this ElementRefP by key.

Parameter ``key``:
    The key for the ElementRefAppData of interest.

Returns:
    the ElementRefAppData for key *key,* or NULL.)doc";

static const char * __doc_Bentley_DgnPlatform_ElementRefBase_DropAppData =R"doc(Drop Application data from this ElementRefP.

Parameter ``key``:
    the key for the ElementRefAppData to drop.

Returns:
    SUCCESS if an entry with *key* is found and dropped.)doc";

static const char * __doc_Bentley_DgnPlatform_ElementRefBase_AddAppData =R"doc(Add Application Data to this ElementRefP.

Parameter ``key``:
    The AppData's key. If an ElementRefAppData with this key already
    exists on this ElementRefP, it is dropped and replaced with
    *appData.*

Parameter ``appData``:
    The appData object to attach to this ElementRefP.

Parameter ``heapZone``:
    HeapZone for this ElementRefP. **Must** be the HeapZone returned
    by #GetHeapZone.

Parameter ``allowOnDeleted``:
    if false (the default), this method will reject adds if the
    ElementRef is deleted.)doc";

static const char * __doc_Bentley_DgnPlatform_ElementRefBase_GetHeapZone =R"doc(@name ElementRefAppData Management Get the HeapZone for the DgnModel
holding this ElementRefP.)doc";

static const char * __doc_Bentley_DgnPlatform_ElementRefBase_GetFilePos =R"doc(Get file pos.

Returns:
    the file pos.)doc";

static const char * __doc_Bentley_DgnPlatform_ElementRefAppData__OnElemChanged =R"doc(Called to allow app data to react to changes to the persisent element
it was added to.

Parameter ``host``:
    ElementRefP that app data was added to.

Parameter ``qvCacheDeleted``:
    Specific to app data used to cache the display representation. of
    the element. Clearing the qvCache invalidates QvElems stored in
    app data.

Parameter ``reason``:
    Why _OnElementChanged is being called.

Returns:
    true to drop this app data entry from the element.)doc";

static const char * __doc_Bentley_DgnPlatform_ElementRefAppData__OnCleanup =R"doc(Called to clean up owned resources and delete the app data.

Parameter ``host``:
    ElementRefP that app data was added to.

Parameter ``unloadingModel``:
    If DgnModel containing host is being unloaded.

Parameter ``zone``:
    HeapZone for the ElementRefP holding the app data.

Remark:
    s If the app data was allocated using ElementRefP::GetHeapZone ()
    there is nothing to free when unloadingCache is true as the entire
    heap zone will be freed with the cache; if unloadingCache is false
    HeapZone::Free needs to be called just for this instance. If a
    heap zone was not used, call delete/release/free as appropriate.)doc";

static const char * __doc_Bentley_DgnPlatform_ElementRefAppData__GetName =R"doc(Return a name for this type of app data.

Remark:
    s Strictly for convenience when debugging, does not need to be
    localized.

Returns:
    The name string or NULL.)doc";

static const char* __doc_Bentley_DgnPlatform_ElementRefBase_SetInDisplaySet = R"doc(Add the element in display set.)doc";
static const char* __doc_Bentley_DgnPlatform_ElementRefBase_IsInDisplaySet = R"doc(Determine whether the element in display set.)doc";

//=======================================================================================
// Trampoline class for ElementRefAppData.
// @bsiclass                                                                   02/23
//=======================================================================================
struct PyElementRefAppData : ElementRefAppData
    {
    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       2/2023
    +---------------+---------------+---------------+---------------+---------------+------*/        
    virtual WCharCP _GetName() override
        { PYBIND11_OVERRIDE_EXR(WCharCP, ElementRefAppData, _GetName, nullptr, ); }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       2/2023
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void _OnCleanup(ElementRefP host, bool unloadingModel, HeapZoneR zone) override
        { PYBIND11_OVERRIDE_PURE_EX(void, ElementRefAppData, _OnCleanup, host, unloadingModel, zone); }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       2/2023
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual bool _OnElemChanged(ElementRefP host, bool qvCacheDeleted, ElemRefChangeReason reason) override
        { PYBIND11_OVERRIDE_EXR(bool, ElementRefAppData, _OnElemChanged, false, host, qvCacheDeleted, reason); }
    };

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_ElementRefBase(py::module_& m)
    {
    //===================================================================================
    // enum ElementRefType
    py::enum_< ElementRefType>(m, "ElementRefType", py::arithmetic())
        .value("eELEMENT_REF_TYPE_Persistent", ELEMENT_REF_TYPE_Persistent)
        .value("eELEMENT_REF_TYPE_TransientElm", ELEMENT_REF_TYPE_TransientElm)
        .value("eELEMENT_REF_TYPE_ViewTemp", ELEMENT_REF_TYPE_ViewTemp)
        .value("eELEMENT_REF_TYPE_ProxyDisplay", ELEMENT_REF_TYPE_ProxyDisplay)
        .export_values();

    //===================================================================================
    // enum ElementHiliteState
    py::enum_< ElementHiliteState>(m, "ElementHiliteState", py::arithmetic())
        .value("eHILITED_None", HILITED_None)
        .value("eHILITED_Normal", HILITED_Normal)
        .value("eHILITED_Bold", HILITED_Bold)
        .value("eHILITED_Dashed", HILITED_Dashed)
        .value("eHILITED_ComponentsNormal", HILITED_ComponentsNormal)
        .value("eHILITED_ComponentsOnly", HILITED_ComponentsOnly)
        .value("eHILITED_Background", HILITED_Background)
        .export_values();

    //===================================================================================
    // enum ElemRefChangeReason
    py::enum_< ElemRefChangeReason>(m, "ElemRefChangeReason", py::arithmetic())
        .value("eELEMREF_CHANGE_REASON_Delete", ELEMREF_CHANGE_REASON_Delete)
        .value("eELEMREF_CHANGE_REASON_Modify", ELEMREF_CHANGE_REASON_Modify)
        .value("eELEMREF_CHANGE_REASON_MovedToNewElemRef", ELEMREF_CHANGE_REASON_MovedToNewElemRef)
        .value("eELEMREF_CHANGE_REASON_ClearQVData", ELEMREF_CHANGE_REASON_ClearQVData)
        .export_values();

    //===================================================================================
    // struct ElementRefAppData
    py::class_< ElementRefAppData, PyElementRefAppData> c1(m, "ElementRefAppData");

    if (true)
        {
        //===================================================================================
        // struct Key
        py::class_< ElementRefAppData::Key, AppDataKey> c1_1(c1, "Key");
        }

    c1.def(py::init<>());
    c1.def("_GetName", &ElementRefAppData::_GetName, DOC(Bentley, DgnPlatform, ElementRefAppData, _GetName));
    c1.def("_OnCleanup", &ElementRefAppData::_OnCleanup, "host"_a, "unloadingModel"_a, "zone"_a, DOC(Bentley, DgnPlatform, ElementRefAppData, _OnCleanup));
    c1.def("_OnElemChanged", &ElementRefAppData::_OnElemChanged, "host"_a, "qvCacheDeleted"_a, "reason"_a, DOC(Bentley, DgnPlatform, ElementRefAppData, _OnElemChanged));

    //===================================================================================
    // struct  ElementRefVec
    py::class_< ElementRefVec> c2(m, "ElementRefVec");
    c2.def(py::init<>());
    c2.def("__bool__", [] (ElementRefVec& self) { return !self.empty(); });
    c2.def("__len__", &ElementRefVec::size);

    c2.def("__getitem__", [] (ElementRefVec const& self, size_t index)
           {
           if (index >= self.size())
               throw py::index_error();
           return std::unique_ptr<ElementRefBase, py::nodelete>(const_cast<ElementRefBaseP>(self[index]));
           }, py::keep_alive<0, 1>());

    c2.def("__setitem__", [] (ElementRefVec& self, size_t index, ElementRefBaseP newValue)
           {
           if (index >= self.size())
               throw py::index_error();
           self[index] = newValue;
           }, py::keep_alive<1, 3>());

    c2.def("push_back", [] (ElementRefVec& self, ElementRefBaseP newValue)
           {
           self.push_back(newValue);
           }, py::keep_alive<1, 2>());

    c2.def("pop_back", &ElementRefVec::pop_back);

    c2.def("resize", [] (ElementRefVec& self, size_t n) { self.resize(n); }, "numItems"_a);

    //===================================================================================
    // struct ElementRefBase
    py::class_< ElementRefBase> c3(m, "ElementRefBase");
    bind_PointerVector<ElementRefP>(m, "ElementRefPArray", py::module_local(false));

    c3.def_property_readonly("FilePos", &ElementRefBase::GetFilePos);
    c3.def("GetFilePos", &ElementRefBase::GetFilePos, DOC(Bentley, DgnPlatform, ElementRefBase, GetFilePos));

    c3.def_property_readonly("HeapZone", &ElementRefBase::GetHeapZone);
    c3.def("GetHeapZone", &ElementRefBase::GetHeapZone, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, ElementRefBase, GetHeapZone));

    c3.def("AddAppData", &ElementRefBase::AddAppData, "key"_a, "appData"_a, "heapZone"_a, "allowOnDeleted"_a = false, py::keep_alive<1, 3>(), DOC(Bentley, DgnPlatform, ElementRefBase, AddAppData));
    c3.def("DropAppData", &ElementRefBase::DropAppData, "key"_a, DOC(Bentley, DgnPlatform, ElementRefBase, DropAppData));
    c3.def("FindAppData", &ElementRefBase::FindAppData, "key"_a, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, ElementRefBase, FindAppData));
    
    c3.def_property_readonly("ParentElementRef", &ElementRefBase::GetParentElementRef);
    c3.def("GetParentElementRef", &ElementRefBase::GetParentElementRef, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, ElementRefBase, GetParentElementRef));
    
    c3.def_property_readonly("DgnModel", &ElementRefBase::GetDgnModelP);
    c3.def("GetDgnModel", &ElementRefBase::GetDgnModelP, py::return_value_policy::reference_internal);
    c3.def("GetDependents", [] (ElementRefBase& self, ElementRefVec& depRefs) { return self.GetDependents(depRefs.data(), (int) depRefs.size()); }, "depRefs"_a);
    c3.def("IsDependent", &ElementRefBase::IsDependent, "isThisDependent"_a, "recurse"_a, DOC(Bentley, DgnPlatform, ElementRefBase, IsDependent));

    c3.def_property_readonly("ElementId", &ElementRefBase::GetElementId);
    c3.def("GetElementId", &ElementRefBase::GetElementId, DOC(Bentley, DgnPlatform, ElementRefBase, GetElementId));
    
    c3.def_property_readonly("ElementType", &ElementRefBase::GetElementType);
    c3.def("GetElementType", &ElementRefBase::GetElementType, DOC(Bentley, DgnPlatform, ElementRefBase, GetElementType));
    
    c3.def_property_readonly("Level", &ElementRefBase::GetLevel);
    c3.def("GetLevel", &ElementRefBase::GetLevel, DOC(Bentley, DgnPlatform, ElementRefBase, GetLevel));
    
    c3.def_property_readonly("LastModified", &ElementRefBase::GetLastModified);
    c3.def("GetLastModified", &ElementRefBase::GetLastModified, DOC(Bentley, DgnPlatform, ElementRefBase, GetLastModified));
    
    c3.def("IsComplexComponent", &ElementRefBase::IsComplexComponent, DOC(Bentley, DgnPlatform, ElementRefBase, IsComplexComponent));
    c3.def("IsGraphics", &ElementRefBase::IsGraphics, DOC(Bentley, DgnPlatform, ElementRefBase, IsGraphics));
    c3.def("ValidateElementRef", &ElementRefBase::ValidateElementRef, DOC(Bentley, DgnPlatform, ElementRefBase, ValidateElementRef));
    c3.def("SetInDisplaySet", &ElementRefBase::SetInDisplaySet, DOC(Bentley, DgnPlatform, ElementRefBase, SetInDisplaySet));
    c3.def("IsInDisplaySet", &ElementRefBase::IsInDisplaySet, DOC(Bentley, DgnPlatform, ElementRefBase, IsInDisplaySet));
    }