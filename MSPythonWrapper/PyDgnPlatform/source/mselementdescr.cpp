/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnPlatform\source\mselementdescr.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <DgnPlatform/DgnFileIO/MSElementDescr.h>



static const char * __doc_Bentley_DgnPlatform_MSElementDescr_AddToChain =R"doc(Add ``newElem`` to the end of ``this`` msElementDescr. This method can
create a chain of non-complex elements in chainElem, but that
technique is strongly discouraged. Instead, use an ElementAgenda.

Parameter ``newElem``:
    The MSElementDescr to add. @note The difference between
    #AppendDescr and #AddToChain is that #AppendDescr requires the
    MSElementDescr to hold a single complex element and #AddToChain
    does not.

Remark:
    s These methods essentially merge the two MSElementDescrs passed
    to them. Therefore, ``newElem`` should not be referenced after
    either of these functions is called. (Thus, it should not be
    freed).)doc";

static const char * __doc_Bentley_DgnPlatform_MSElementDescr_ClearElementIds =R"doc(Set the ElementIDs of this MSElementDescr, and all of its children, to
zero.)doc";

static const char * __doc_Bentley_DgnPlatform_MSElementDescr_Validate =R"doc(Updates complex header element information based on current
components.

Parameter ``modelRef``:
    Element source.

Parameter ``ignoreIsValid``:
    Perform validation even if h.isValid is true. (ex. Application
    modifies component elements directly)

Remark:
    s Applications rarely need to call this directly, elements are
    always validated when added to a model or displayed in dynamics.

Remark:
    s Sets h.isValid to true when complete.)doc";

static const char * __doc_Bentley_DgnPlatform_MSElementDescr_AppendDescr =R"doc(Adds ``newDscr`` to the end of this msElementDescr.

Parameter ``newDscr``:
    The MSElementDescr to add.

Returns:
    SUCCESS if newDscr is appended to this msElementDescr,
    DGNELEMENT_STATUS_NotCmplxHdr if this msElementDescr does not hold
    a complex header.

See also:
    #AddToChain)doc";

static const char * __doc_Bentley_DgnPlatform_MSElementDescr_AppendElement =R"doc(Allocates a new element descriptor from an existing element and append
to the end of an existing element descriptor

Parameter ``element``:
    Element to append.

Returns:
    A pointer to the new descriptor if the element is successfully
    inserted and NULL otherwise.)doc";

static const char * __doc_Bentley_DgnPlatform_MSElementDescr_ReplaceDescr =R"doc(Replace this MSElementDescr, and all of its children, with a new
MSElementDescr. If this MSElementDescr is a component of a complex
element, its previous/next/etc. pointers are spliced to point to
``newDscr.``

Parameter ``newDscr``:
    The new MSElementDescr to replace this one. @note This
    MSElementDescr is Released (and is no longer valid) after this
    call. @note If the original MSElementDescr has an
    XAttributeChangeSet, it must be transferred to the ``newDscr``
    manually by the caller or it will be lost.)doc";

static const char * __doc_Bentley_DgnPlatform_MSElementDescr_ReplaceElement =R"doc(Replace the element held by this MSElementDescr with a new element. If
the new element is the same size or smaller (in bytes) as the current
element, it is overwritten in place. If thew new element is larger
than the current one, a new MSElementDescr is allocated and returned,
and this MSElementDescr is Released. If this MSElementDescr is a
component of a complex element, the previous/next/etc. pointers are
spliced to the MSElementDescr returned by this method.

Parameter ``element``:
    The new element to be held by a (potentially) new MSElementDescr.

Returns:
    A pointer to the MSElementDescr holding ``element.`` This may
    either point to this MSElementDescr or a new one. @note This
    MSElementDescr is Released (and is no longer valid) after this
    call. @note If the original MSElementDescr has an
    XAttributeChangeSet, it is preserved on the new MSElementDescr, if
    one is created.)doc";

static const char * __doc_Bentley_DgnPlatform_MSElementDescr_DuplicateSingle =R"doc(Allocates and returns a copy of this MSElementDescr without copying
h.next.)doc";

static const char * __doc_Bentley_DgnPlatform_MSElementDescr_Duplicate =R"doc(Allocates and returns a copy of this MSElementDescr.)doc";

static const char * __doc_Bentley_DgnPlatform_MSElementDescr_Allocate =R"doc(Allocate a new MSElementDescr holding a copy of the supplied
MSElement.

Parameter ``element``:
    The existing element.

Parameter ``modelRef``:
    The value for the dgnModelRef member of the new MSElementDescr.

Parameter ``myHeader``:
    The parent MSElementDescr to which the new MSElementDescr is
    attached. This method sets the myHeader field in the new
    MSElementDescr to this value. Generally this should be NULL unless
    #AppendDescr cannot be used.

Returns:
    A pointer to the new MSElementDescr, or NULL if ``element`` is not
    a valid MicroStation element.)doc";

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_MSElementDescr(py::module_& m)
    {
    using MSElementDescrPtr = RefCountedPtr<MSElementDescr>;
    
    //===================================================================================
    // struct MSElementDescr
    py::class_< MSElementDescr, MSElementDescrPtr > c1(m, "MSElementDescr");

    //struct MSElementDescr::h
    struct MSElementDescr_h
        {
        MSElementDescrP         next;
        MSElementDescrP         previous;
        MSElementDescrP         myHeader;
        MSElementDescrP         firstElem;
        DgnModelRefP            dgnModelRef;
        ElementRefP             elementRef;
        Int32                   isHeader;
        Int32                   isValid;
        MSElementDescrAppData   appData1;
        MSElementDescrAppData   appData2;
        };

    py::class_<MSElementDescr_h> c01(c1, "MSElementDescrHeader");
    c01.def(py::init<>());
    c01.def_readwrite("next", &MSElementDescr_h::next);
    c01.def_readwrite("previous", &MSElementDescr_h::previous);
    c01.def_readwrite("myHeader", &MSElementDescr_h::myHeader);
    c01.def_readwrite("firstElem", &MSElementDescr_h::firstElem);
    c01.def_readwrite("dgnModelRef", &MSElementDescr_h::dgnModelRef);
    c01.def_readwrite("elementRef", &MSElementDescr_h::elementRef);
    c01.def_readwrite("isHeader", &MSElementDescr_h::isHeader);
    c01.def_readwrite("isValid", &MSElementDescr_h::isValid);

    c1.def_property("h",
        [](MSElementDescr& self) {return reinterpret_cast<MSElementDescr_h*>(&self.h); },
        [](MSElementDescr& self, MSElementDescr_h const& value) { memcpy(&self.h, &value, sizeof(MSElementDescr_h)); });

    c1.def_readwrite("el", &MSElementDescr::el);

    c1.def_static("Allocate",
                  py::overload_cast<MSElementCR, DgnModelRefP, MSElementDescrP>(&MSElementDescr::Allocate),
                  "element"_a, "modelRef"_a = nullptr, "myHeader"_a = nullptr, py::return_value_policy::take_ownership, DOC(Bentley, DgnPlatform, MSElementDescr, Allocate));

    c1.def_static("Allocate",
                  py::overload_cast<ElementRefP, DgnModelRefP, MSElementDescrP>(&MSElementDescr::Allocate),
                  "element"_a, "modelRef"_a = nullptr, "myHeader"_a = nullptr, py::return_value_policy::take_ownership, DOC(Bentley, DgnPlatform, MSElementDescr, Allocate));

    c1.def("Duplicate", [] (MSElementDescr const& self, bool copyScheduledXaChanges = true, bool loadPersistentXasAsChanges = false)
           {
           MSElementDescrP newDscr = nullptr;
           auto retVal = self.Duplicate(&newDscr, copyScheduledXaChanges, loadPersistentXasAsChanges);
           return py::make_tuple(retVal, MSElementDescrPtr(newDscr));
           }, "copyScheduledXaChanges"_a = true, "loadPersistentXasAsChanges"_a = false, DOC(Bentley, DgnPlatform, MSElementDescr, Duplicate));

    c1.def("DuplicateSingle", [] (MSElementDescr const& self, bool copyScheduledXaChanges = true, bool loadPersistentXasAsChanges = false)
           {
           MSElementDescrP newDscr = nullptr;
           auto retVal = self.DuplicateSingle(&newDscr, copyScheduledXaChanges, loadPersistentXasAsChanges);
           return py::make_tuple(retVal, MSElementDescrPtr(newDscr));
           }, "copyScheduledXaChanges"_a = true, "loadPersistentXasAsChanges"_a = false, DOC(Bentley, DgnPlatform, MSElementDescr, DuplicateSingle));

    c1.def("ReplaceElement", [] (MSElementDescr& self, MSElementCR element)
           {
           auto retVal = self.ReplaceElement(element);
           return MSElementDescrPtr(retVal);
           }, "element"_a, DOC(Bentley, DgnPlatform, MSElementDescr, ReplaceElement));

    c1.def("ReplaceDescr", [] (MSElementDescr& self, MSElementDescrR newDscr)
           {
           auto retVal = self.ReplaceDescr(newDscr);
           return MSElementDescrPtr(retVal);
           }, "newDscr"_a, DOC(Bentley, DgnPlatform, MSElementDescr, ReplaceDescr));

    c1.def("AppendElement", [] (MSElementDescr& self, MSElementCR element)
           {
           auto retVal = self.AppendElement(element);
           return MSElementDescrPtr(retVal);
           }, "element"_a, DOC(Bentley, DgnPlatform, MSElementDescr, AppendElement));

    c1.def("AppendDescr", &MSElementDescr::AppendDescr, "newDscr"_a, DOC(Bentley, DgnPlatform, MSElementDescr, AppendDescr));
    
    c1.def("RemoveElement", [] (MSElementDescr& self) { return MSElementDescrPtr(self.RemoveElement()); });

    c1.def("Validate", &MSElementDescr::Validate, "modelRef"_a, "ignoreIsValid"_a = false, DOC(Bentley, DgnPlatform, MSElementDescr, Validate));
    c1.def("ClearElementIds", &MSElementDescr::ClearElementIds, DOC(Bentley, DgnPlatform, MSElementDescr, ClearElementIds));
    c1.def("SetModelRef", &MSElementDescr::SetModelRef, "modelRef"_a, py::keep_alive<1, 2>());
    c1.def("CopyXAttributesTo", &MSElementDescr::CopyXAttributesTo, "sink"_a, "copyChildXAttributes"_a);

    c1.def_property_readonly("XAttributeChangeSet", &MSElementDescr::GetXAttributeChangeSet);
    c1.def("GetXAttributeChangeSet", &MSElementDescr::GetXAttributeChangeSet, py::return_value_policy::reference_internal);
    
    c1.def("QueryXAttributeChangeSet", &MSElementDescr::QueryXAttributeChangeSet, py::return_value_policy::reference_internal);
    c1.def("AddToChain", &MSElementDescr::AddToChain, "newElem"_a, DOC(Bentley, DgnPlatform, MSElementDescr, AddToChain));

    c1.def_static("InitOrAddToChainWithTail", [] (MSElementDescrP chainHeaderDescr, MSElementDescrP chainTailDescr, MSElementDescrP newDescr)
                  {
                  MSElementDescrP chainHeaderDescr_ {chainHeaderDescr};
                  MSElementDescrP chainTailDescr_ {chainTailDescr};
                  MSElementDescr::InitOrAddToChainWithTail(&chainHeaderDescr_, &chainTailDescr_, newDescr);
                  return py::make_tuple(MSElementDescrPtr(chainHeaderDescr_), MSElementDescrPtr(chainTailDescr_));
                  }, "chainHeaderDescr"_a, "chainTailDescr"_a, "newDescr"_a);
    }