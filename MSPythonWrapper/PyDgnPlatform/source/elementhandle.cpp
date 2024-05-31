/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnPlatform\source\elementhandle.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <DgnPlatform/ElementHandle.h>



static const char * __doc_Bentley_DgnPlatform_ChildElemIter_ToNext =R"doc(Move to the next sibling element from the current element.

Returns:
    a ChildElemIter pointing to the next sibling element.)doc";

static const char * __doc_Bentley_DgnPlatform_IElementSet_GetNext =R"doc(Get the next ElementHandle in the set.

Parameter ``elHandle``:
    The ElementHandle for the first member.

Returns:
    true if there were more members in the set and *elHandle* was set.
    If false, *elHandle* was not modified.)doc";

static const char * __doc_Bentley_DgnPlatform_IElementSet_GetFirst =R"doc(Reset the iterator to the begining of the set and return the first
member.

Parameter ``elHandle``:
    The ElementHandle for the first member.

Returns:
    true if there was at least one member of the set and *elHandle*
    was set. If false, *elHandle* was not modified.)doc";

static const char * __doc_Bentley_DgnPlatform_IElementSet_GetCount =R"doc(Get the number of entries in the set.)doc";

static const char * __doc_Bentley_DgnPlatform_EditElementHandle_ReplaceInModel =R"doc(Replace the element referred to by the supplied ElementRefP with the
modified MSElementDescr held by this EditElementHandle. The
replacement is via the current transaction (see ITxn::ReplaceElement)
and is always undoable.

Parameter ``oldRef``:
    Element to replace.

Returns:
    SUCCESS if the element was replaced in the model. This method will
    fail if there is no MSElementDescr for this EditElementHandle.

Remark:
    s After the element is successfully replaced in the model, the
    ElementRefP of this EditElementHandle is updated with the
    (potentially new) ElementRefP of replaced element and the
    MSElementDescr is freed.)doc";

static const char * __doc_Bentley_DgnPlatform_EditElementHandle_DeleteFromModel =R"doc(Delete this EditElementHandle from its model. The delete is via the
current transaction (see ITxn::DeleteElement) and is always undoable.
The deletion is via the current transaction (see ITxn::DeleteElement)
and is always undoable.

Returns:
    SUCCESS if the element was deleted from the model.

Remark:
    s After the element is successfully deleted from the model, this
    EditElementHandle becomes invalid (see #IsValid).)doc";

static const char * __doc_Bentley_DgnPlatform_EditElementHandle_AddToModel =R"doc(Add this EditElementHandle to the associated model. The addition is
via the current transaction (see ITxn::AddElement) and is always
undoable.

Returns:
    SUCCESS if the element was added to its model. This method will
    fail if there is no MSElementDescr for this EditElementHandle, or
    if the MSElementDescr is not owned by this EditElementHandle, or
    if this EditElementHandle is not associated with a model.

Remark:
    s This method is just a wrapper for:return
    ITxnManager::GetCurrentTxn().AddElement (*this);

Remark:
    s After the element is successfully added to the model, the
    ElementRefP of this EditElementHandle is set and the
    MSElementDescr is freed.)doc";

static const char * __doc_Bentley_DgnPlatform_EditElementHandle_FindByID =R"doc(@name Read from model)doc";

static const char * __doc_Bentley_DgnPlatform_EditElementHandle_CancelDeleteXAttribute =R"doc(Cancel out the effects of a prior call to ScheduleDeleteXAttribute

Parameter ``h``:
    XAttributeHandler ID

Parameter ``xAttrId``:
    XAttribute ID

Returns:
    non-zero error status if the XAttribute was not scheduled for
    deletion)doc";

static const char * __doc_Bentley_DgnPlatform_EditElementHandle_ScheduleDeleteXAttribute =R"doc(Schedule removal of the specified XAttribute from the MSElementDescr.

Parameter ``h``:
    XAttributeHandler ID

Parameter ``xAttrId``:
    XAttribute ID

Returns:
    non-zero error status if the change cannot be scheduled. Normally,
    this would only happen in an out-of-memory situation.

Remark:
    s If the XAttribute was previously scheduled for write, this
    request to delete the XAttribute cancels the previous write
    request and schedules the XAttribute to be deleted instead.

Remark:
    s If the XAttribute was previously scheduled for delete, this
    request effectively does nothing; the XAttribute will remain
    scheduled for deletion.)doc";

static const char * __doc_Bentley_DgnPlatform_EditElementHandle_CancelWriteXAttribute =R"doc(Cancel out the effects of a prior call to ScheduleWriteXAttribute

Parameter ``h``:
    XAttributeHandler ID

Parameter ``xAttrId``:
    XAttribute ID

Returns:
    non-zero error status if the XAttribute was not scheduled for
    write)doc";

static const char * __doc_Bentley_DgnPlatform_EditElementHandle_ScheduleWriteXAttribute =R"doc(Schedule the specified XAttribute to be written to the MSElementDescr.

Remark:
    s This function makes a copy of *data*

Parameter ``h``:
    XAttributeHandler ID

Parameter ``xAttrId``:
    XAttribute ID

Parameter ``dataSize``:
    Number of bytes of data in XAttribute data

Parameter ``data``:
    XAttribute data

Returns:
    non-zero error status if the change cannot be scheduled. Normally,
    this would only happen in an out-of-memory situation.

Remark:
    s EditElementHandle does not distinguish between adding a new
    XAttribute and replacing the value of an existing XAttribute. In
    both cases, you call ScheduleWriteXAttribute. If you have an
    ElementRefP, you can use the XAttributeHandle class to test if an
    XAttribute exists or not.

``
Example of how to add an element with XAttributes to a cache
EditElementHandle eh;
eh.SetElementDescr ( ... );
...
eh.ScheduleWriteXAttribute (myXaHandlerId, xaIndex, nbytes, xaBytes);
...
eh.AddToModel ();   // adds the element and the XAttribute to the active model cache
``

Remark:
    s If the XAttribute was previously scheduled for write or delete,
    this request to write the specified data supercedes the previous
    request and schedules the specified data for write instead.)doc";

static const char * __doc_Bentley_DgnPlatform_EditElementHandle_SetElementDescr =R"doc(Assign a new MSElementDescr to this EditElementHandle. The existing
MSElementDescr (if present) is freed.

Remark:
    s This method should not be called on a ChildEditElemIter.

See also:
    ReplaceElementDescr.

Parameter ``elDscr``:
    MSElementDescr to be referenced by this ElementHandle.

Parameter ``owned``:
    If true, destructor will free *elDscr.* Otherwise, caller
    maintains ownership of *elDscr.*

Parameter ``isUnmodified``:
    If true, *elDscr* is an exact image of the element in the cache.

Parameter ``modelRef``:
    Will be used if elDscr.h.dgnModelRef is NULL.

See also:
    ElementHandle::ElementHandle.)doc";

static const char * __doc_Bentley_DgnPlatform_EditElementHandle_ExtractElementDescr =R"doc(Extract and take ownership of the MSElementDescr associated with this
EditElementHandle.

Returns:
    The MSElementDescrP from the EditElementHandle. The MSElementDescr
    is no longer associated with the EditElementHandle, and the caller
    is responsible for freeing it.

Remark:
    s This method will fail if there is no " owned " MSElementDescr
    already associated with this EditElementHandle.

Remark:
    s This method should not be called on a ChildEditElemIter.)doc";

static const char * __doc_Bentley_DgnPlatform_EditElementHandle_ReplaceElementDescr =R"doc(Replace the MSElementDescr associated with the EditElementHandle with
a new MSElementDescr.

Parameter ``elDscr``:
    The new MSElementDescr to be associated with the
    EditElementHandle. After this call, *elDscr* becomes owned by this
    EditElementHandle.

Returns:
    SUCCESS if the MSElementDescr was successfully replaced by
    *elDscr,* ERROR otherwise.

Remark:
    s This method will fail if the MSElementDescr is not " owned " by
    this EditElementHandle.

Remark:
    s If the DgnModelRef in *elDscr* is NULL, the value from the
    existing MSElementDescr is copied into *elDscr.*)doc";

static const char * __doc_Bentley_DgnPlatform_EditElementHandle_ReplaceElement =R"doc(Replace the element associated with this EditElementHandle with a new
element.

Parameter ``el``:
    The new element. The element is copied from this buffer and
    allocated in a new MSElementDescr.)doc";

static const char * __doc_Bentley_DgnPlatform_EditElementHandle_Invalidate =R"doc(Mark this EditElementHandle as invalid. If there is an MSElementDescr
associated with this EditElementHandle, it is freed.)doc";

static const char * __doc_Bentley_DgnPlatform_EditElementHandle_SetNonPersistent =R"doc(Turn off the " IsUnmodified " flag for this EditElementHandle. This
EditElementHandle will no longer be treated as an exact image of the
element in the cache.)doc";

static const char * __doc_Bentley_DgnPlatform_EditElementHandle_SetModelRef =R"doc(Change the DgnModelRef for this EditElementHandle.

Parameter ``modelRef``:
    IN new DgnModelRef)doc";

static const char * __doc_Bentley_DgnPlatform_EditElementHandle_Duplicate =R"doc(Duplicate the element descriptor and its scheduled XAttribute changes.)doc";

static const char * __doc_Bentley_DgnPlatform_ElementHandle_GetElementId =R"doc(Get the element ID of the element contained in the ElementHandle.)doc";

static const char * __doc_Bentley_DgnPlatform_ElementHandle_EndElementLinkages =R"doc(Get an iterator that marks the end of the element's user data linkages)doc";

static const char * __doc_Bentley_DgnPlatform_ElementHandle_BeginElementLinkages =R"doc(Get an iterator over the element's user data linkages

Parameter ``rl``:
    Linkage ID filter value identifies the linkages of interest.
    Defaults to all linkages.)doc";

static const char * __doc_Bentley_DgnPlatform_ElementHandle_GetElementType =R"doc(Get the element type of the element referenced by this ElementHandle.

Returns:
    the type of the element referenced by this ElementHandle)doc";

static const char * __doc_Bentley_DgnPlatform_ElementHandle_IsPersistent =R"doc(Determine whether this ElementHandle references an unmodified element
in the cache.

Returns:
    true if ElementHandle is unmodified representation of element in
    the cache.)doc";

static const char * __doc_Bentley_DgnPlatform_ElementHandle_IsValid =R"doc(Determine whether this ElementHandle is currently valid.

Returns:
    true if this ElementHandle references a valid element. If not, all
    other methods on this ElementHandle will either fail or crash.)doc";

static const char * __doc_Bentley_DgnPlatform_ElementHandle_GetModelRef =R"doc(Get the DgnModelRef for this ElementHandle.

Returns:
    the DgnModelRef. @note This method CAN (and often will) return
    NULL.)doc";

static const char * __doc_Bentley_DgnPlatform_ElementHandle_GetElementRef =R"doc(@name Element Data Queries Get the ElementRefP for this ElementHandle.

Returns:
    the ElementRefP, or NULL.)doc";

static const char * __doc_Bentley_DgnPlatform_ElementHandle_GetITextEdit =R"doc(A shortcut method to get the ITextEdit interface on the Handler for
this ElementHandle, or NULL if the element's Handler does not
implement that interface.)doc";

static const char * __doc_Bentley_DgnPlatform_ElementHandle_GetITextQuery =R"doc(A shortcut method to get the ITextQuery interface on the Handler for
this ElementHandle, or NULL if the element's Handler does not
implement that interface.)doc";

static const char * __doc_Bentley_DgnPlatform_ElementHandle_GetITransactionHandler =R"doc(A shortcut method to get the ITransactionHandler interface on the
Handler for this ElementHandle, or NULL if the element's Handler does
not implement that interface.)doc";

static const char * __doc_Bentley_DgnPlatform_ElementHandle_GetIDependencyHandler =R"doc(A shortcut method to get the IDependencyHandler interface on the
Handler for this ElementHandle, or NULL if the element's Handler does
not implement that interface.)doc";

static const char * __doc_Bentley_DgnPlatform_ElementHandle_GetDisplayHandler =R"doc(A shortcut method to get a DisplayHandler pointer for the Handler of
this ElementHandle, or NULL if the element's Handler does not derive
from DisplayHandler.)doc";

static const char * __doc_Bentley_DgnPlatform_ElementHandle_GetHandler =R"doc(Get the Handler for this ElementHandle. Every element must have a
handler. This method returns a reference to the Handler for this
element. If this ElementHandle has an ElementRefP, its handler is
returned. Otherwise, the MSElementDescr is used.

Parameter ``perm``:
    The requsted permission for the task for which the Handler will be
    used. This is only relevant when the element's Handler is not
    present on the system and no appropriate Enabler can be located.
    In that case, the system will return a Handler that respects the
    " missing handler " permissions specified when the element was
    created. @note If you attempt to get the Handler for an Invalid
    ElementHandle, it will return a " NullHandler " that does nothing.)doc";

static const char * __doc_Bentley_DgnPlatform_ElementHandle_ResetHandler =R"doc(@name Handler Queries)doc";

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_ElementHandle(py::module_& m)
    {
    //===================================================================================
    // enum MissingHandlerPermissions
    py::enum_< MissingHandlerPermissions>(m, "MissingHandlerPermissions", py::arithmetic())
        .value("eMISSING_HANDLER_PERMISSION_None", MISSING_HANDLER_PERMISSION_None)
        .value("eMISSING_HANDLER_PERMISSION_Delete", MISSING_HANDLER_PERMISSION_Delete)
        .value("eMISSING_HANDLER_PERMISSION_Copy", MISSING_HANDLER_PERMISSION_Copy)
        .value("eMISSING_HANDLER_PERMISSION_Draw", MISSING_HANDLER_PERMISSION_Draw)
        .value("eMISSING_HANDLER_PERMISSION_Manipulators", MISSING_HANDLER_PERMISSION_Manipulators)
        .value("eMISSING_HANDLER_PERMISSION_Transform", MISSING_HANDLER_PERMISSION_Transform)
        .value("eMISSING_HANDLER_PERMISSION_CurveEdit", MISSING_HANDLER_PERMISSION_CurveEdit)
        .value("eMISSING_HANDLER_PERMISSION_ChangeAttrib", MISSING_HANDLER_PERMISSION_ChangeAttrib)
        .value("eMISSING_HANDLER_PERMISSION_All_", MISSING_HANDLER_PERMISSION_All_)
        .export_values();

    //===================================================================================
    // struct IElementState
    py::class_< IElementState, std::unique_ptr<IElementState, py::nodelete>/*, IRefCounted*/> c2(m, "IElementState");

    //===================================================================================
    // struct ElementHandle
    py::class_< ElementHandle> c3(m, "ElementHandle");
    py::bind_vector<bvector<ElementHandle>>(m, "ElementHandleArray", py::module_local(false));

    c3.def(py::init<>());
    c3.def(py::init<ElementRefP, DgnModelRefP>(), "elRef"_a, "modelRef"_a = nullptr);
    c3.def(py::init<ElementId, DgnModelRefP>(), "id"_a, "modelRef"_a);
    c3.def(py::init<MSElementDescrCP, bool, bool, DgnModelRefP>(), "elDscr"_a, "owned"_a, "isUnmodified"_a = false, "modelRef"_a = nullptr);
    c3.def(py::init<MSElementCP, DgnModelRefP>(), "el"_a, "modelRef"_a);
    c3.def(py::init<ElementHandleCR>(), "from"_a);
    c3.def("ResetHandler", &ElementHandle::ResetHandler, DOC(Bentley, DgnPlatform, ElementHandle, ResetHandler));
    c3.def("GetHandler", &ElementHandle::GetHandler, "permit"_a = MISSING_HANDLER_PERMISSION_None, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, ElementHandle, GetHandler));
    
    c3.def_property_readonly("DisplayHandler", &ElementHandle::GetDisplayHandler);
    c3.def("GetDisplayHandler", &ElementHandle::GetDisplayHandler, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, ElementHandle, GetDisplayHandler));
    
    c3.def_property_readonly("IDependencyHandler", &ElementHandle::GetIDependencyHandler);
    c3.def("GetIDependencyHandler", &ElementHandle::GetIDependencyHandler, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, ElementHandle, GetIDependencyHandler));
    
    c3.def_property_readonly("ITransactionHandler", &ElementHandle::GetITransactionHandler);
    c3.def("GetITransactionHandler", &ElementHandle::GetITransactionHandler, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, ElementHandle, GetITransactionHandler));
    
    c3.def_property_readonly("ITextQuery", &ElementHandle::GetITextQuery);
    c3.def("GetITextQuery", &ElementHandle::GetITextQuery, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, ElementHandle, GetITextQuery));
    
    c3.def_property_readonly("ITextEdit", &ElementHandle::GetITextEdit);
    c3.def("GetITextEdit", &ElementHandle::GetITextEdit, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, ElementHandle, GetITextEdit));

    c3.def("GetIMeshQuery", [] (ElementHandleCR self)
           {
            return dynamic_cast <IMeshQuery*> (&self.GetHandler());
           }, py::return_value_policy::reference_internal);
    c3.def("GetIMeshEdit", [] (ElementHandleCR self)
           {
            return dynamic_cast <IMeshEdit*> (&self.GetHandler());
           }, py::return_value_policy::reference_internal);           
    c3.def("GetICurvePathQuery", [] (ElementHandleCR self)
           {
            return dynamic_cast <ICurvePathQuery*> (&self.GetHandler());
           }, py::return_value_policy::reference_internal);           

    c3.def("GetICurvePathEdit", [] (ElementHandleCR self)
           {
            return dynamic_cast <ICurvePathEdit*> (&self.GetHandler());
           }, py::return_value_policy::reference_internal);           
    c3.def("GetIBsplineSurfaceQuery", [] (ElementHandleCR self)
           {
            return dynamic_cast <IBsplineSurfaceQuery*> (&self.GetHandler());
           }, py::return_value_policy::reference_internal);           
    c3.def("GetIBsplineSurfaceEdit", [] (ElementHandleCR self)
           {
            return dynamic_cast <IBsplineSurfaceEdit*> (&self.GetHandler());
           }, py::return_value_policy::reference_internal);           

    c3.def("GetISolidPrimitiveQuery", [] (ElementHandleCR self)
           {
            return dynamic_cast <ISolidPrimitiveQuery*> (&self.GetHandler());
           }, py::return_value_policy::reference_internal);           

    c3.def("GetISolidPrimitiveEdit", [] (ElementHandleCR self)
           {
            return dynamic_cast <ISolidPrimitiveEdit*> (&self.GetHandler());
           }, py::return_value_policy::reference_internal);           
    c3.def("GetIBRepQuery", [] (ElementHandleCR self)
           {
            return dynamic_cast <IBRepQuery*> (&self.GetHandler());
           }, py::return_value_policy::reference_internal);           
    c3.def("GetIBRepEdit", [] (ElementHandleCR self)
           {
            return dynamic_cast <IBRepEdit*> (&self.GetHandler());
           }, py::return_value_policy::reference_internal);           

    c3.def("GetICellQuery", [] (ElementHandleCR self)
           {
            return dynamic_cast <ICellQuery*> (&self.GetHandler());
           }, py::return_value_policy::reference_internal);           

    c3.def("GetISharedCellQuery", [] (ElementHandleCR self)
           {
            return dynamic_cast <ISharedCellQuery*> (&self.GetHandler());
           }, py::return_value_policy::reference_internal);           


    c3.def_property_readonly("ElementRef", &ElementHandle::GetElementRef);
    c3.def("GetElementRef", &ElementHandle::GetElementRef, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, ElementHandle, GetElementRef));
    
    c3.def_property_readonly("DgnModel", &ElementHandle::GetDgnModelP);
    c3.def("GetDgnModel", &ElementHandle::GetDgnModelP, py::return_value_policy::reference_internal);
    
    c3.def_property_readonly("DgnFile", &ElementHandle::GetDgnFileP);
    c3.def("GetDgnFile", &ElementHandle::GetDgnFileP, py::return_value_policy::reference_internal);
    
    c3.def_property_readonly("ModelRef", &ElementHandle::GetModelRef);
    c3.def("GetModelRef", &ElementHandle::GetModelRef, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, ElementHandle, GetModelRef));
    
    c3.def_property_readonly("Element", &ElementHandle::GetElementCP);
    c3.def("GetElement", &ElementHandle::GetElementCP, py::return_value_policy::reference_internal);
    
    c3.def("IsValid", &ElementHandle::IsValid, DOC(Bentley, DgnPlatform, ElementHandle, IsValid));
    c3.def("__bool__", [] (ElementHandle& self) { return self.IsValid(); });
    c3.def("IsPersistent", &ElementHandle::IsPersistent, DOC(Bentley, DgnPlatform, ElementHandle, IsPersistent));
    
    c3.def_property_readonly("ElementType", &ElementHandle::GetElementType);
    c3.def("GetElementType", &ElementHandle::GetElementType, DOC(Bentley, DgnPlatform, ElementHandle, GetElementType));
    
    c3.def("PeekElementDescr", &ElementHandle::PeekElementDescrCP, py::return_value_policy::reference_internal);
    c3.def("GetElementDescr", &ElementHandle::GetElementDescrCP, py::return_value_policy::reference_internal);
    c3.def("BeginElementLinkages", &ElementHandle::BeginElementLinkages, DOC(Bentley, DgnPlatform, ElementHandle, BeginElementLinkages));
    c3.def("EndElementLinkages", &ElementHandle::EndElementLinkages, DOC(Bentley, DgnPlatform, ElementHandle, EndElementLinkages));

    c3.def_property_readonly("ElementId", &ElementHandle::GetElementId);
    c3.def("GetElementId", &ElementHandle::GetElementId, DOC(Bentley, DgnPlatform, ElementHandle, GetElementId));
    
    c3.def("__repr__", [] (ElementHandleCR self)
           {
           if (nullptr == self.GetElementCP())
                return "(ElementId:{}, ModelId:{}, FileName:{})"_s.format(0, 0, "null");

           ElementId elemId = self.GetElementId();
           ModelId modelId = nullptr == self.GetDgnModelP() ? INVALID_MODELID : self.GetDgnModelP()->GetModelId();
           WString fileName = nullptr == self.GetDgnFileP() ? L"" : self.GetDgnFileP()->GetFileName();
           return "(ElementId:{}, ModelId:{}, FileName:{})"_s.format(elemId, modelId, fileName);
           });

    c3.def("__iter__", [](ElementHandleCR self)
        { 
        return py::make_iterator(self.BeginElementLinkages(), self.EndElementLinkages());
        }, py::keep_alive<0, 1>());

    //===================================================================================
    // struct EditElementHandle
    py::class_< EditElementHandle, ElementHandle> c4(m, "EditElementHandle");

    c4.def(py::init<>());
    
    c4.def(py::init([] (MSElementDescrP descr, bool owned, bool isUnmodified, DgnModelRefP modelRef)
                    {
                    return new EditElementHandle(descr, owned, isUnmodified, modelRef);
                    }), "descr"_a, "owned"_a, "isUnmodified"_a, "modelRef"_a = nullptr, py::keep_alive<1, 2>(), py::keep_alive<1, 5>());

    c4.def(py::init<ElementRefP, DgnModelRefP>(), "elRef"_a, "modelRef"_a = nullptr, py::keep_alive<1, 2>(), py::keep_alive<1, 3>());
    c4.def(py::init<MSElementCP, DgnModelRefP>(), "el"_a, "modelRef"_a, py::keep_alive<1, 2>(), py::keep_alive<1, 3>());
    c4.def(py::init<ElementId, DgnModelRefP>(), "id"_a, "modelRef"_a, py::keep_alive<1, 3>());
    c4.def(py::init<ElementHandleCR, bool>(), "from"_a, "duplicateDescr"_a);
    c4.def("Duplicate", &EditElementHandle::Duplicate, "eh"_a, DOC(Bentley, DgnPlatform, EditElementHandle, Duplicate));
    c4.def("SetModelRef", &EditElementHandle::SetModelRef, "modelRef"_a, py::keep_alive<1, 2>(), DOC(Bentley, DgnPlatform, EditElementHandle, SetModelRef));
    c4.def("SetNonPersistent", &EditElementHandle::SetNonPersistent, DOC(Bentley, DgnPlatform, EditElementHandle, SetNonPersistent));
    c4.def("Invalidate", &EditElementHandle::Invalidate, DOC(Bentley, DgnPlatform, EditElementHandle, Invalidate));
    
    c4.def_property("IElementState", &EditElementHandle::GetIElementState, py::cpp_function(&EditElementHandle::SetIElementState, py::keep_alive<1, 2>()));
    c4.def("GetIElementState", &EditElementHandle::GetIElementState, py::return_value_policy::reference_internal);
    c4.def("SetIElementState", &EditElementHandle::SetIElementState, "state"_a, py::keep_alive<1, 2>());
    
    c4.def_property_readonly("ElementDescr", &EditElementHandle::GetElementDescrP);
    c4.def("GetElementDescr", &EditElementHandle::GetElementDescrP, py::return_value_policy::reference_internal);
    
    c4.def_property_readonly("Element", &EditElementHandle::GetElementP);
    c4.def("GetElement", &EditElementHandle::GetElementP, py::return_value_policy::reference_internal);
    
    c4.def("ReplaceElement", &EditElementHandle::ReplaceElement, "el"_a, DOC(Bentley, DgnPlatform, EditElementHandle, ReplaceElement));
    c4.def("ReplaceElementDescr", &EditElementHandle::ReplaceElementDescr, "elDscr"_a, py::keep_alive<1, 2>(), DOC(Bentley, DgnPlatform, EditElementHandle, ReplaceElementDescr));
    c4.def("ExtractElementDescr", &EditElementHandle::ExtractElementDescr, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, EditElementHandle, ExtractElementDescr));
    c4.def("SetElementDescr", &EditElementHandle::SetElementDescr, "elDscr"_a, "owned"_a, "isUnmodified"_a, "modelRef"_a = nullptr, py::keep_alive<1, 2>(), py::keep_alive<1, 5>(), DOC(Bentley, DgnPlatform, EditElementHandle, SetElementDescr));
    c4.def("ScheduleWriteXAttribute", [] (EditElementHandle& self, XAttributeHandlerIdCR h, UInt32 xAttrId, py::bytes const& data)
           {
           std::string strData = (std::string) data;
           return self.ScheduleWriteXAttribute(h, xAttrId, strData.size(), (void const*) strData.data());
           }, "handlerId"_a, "xAttrId"_a, "data"_a, DOC(Bentley, DgnPlatform, EditElementHandle, ScheduleWriteXAttribute));

    c4.def("CancelWriteXAttribute", &EditElementHandle::CancelWriteXAttribute, "handlerId"_a, "xAttrId"_a, DOC(Bentley, DgnPlatform, EditElementHandle, CancelWriteXAttribute));
    c4.def("ScheduleDeleteXAttribute", &EditElementHandle::ScheduleDeleteXAttribute, "handlerId"_a, "xAttrId"_a, DOC(Bentley, DgnPlatform, EditElementHandle, ScheduleDeleteXAttribute));
    c4.def("CancelDeleteXAttribute", &EditElementHandle::CancelDeleteXAttribute, "handlerId"_a, "xAttrId"_a, DOC(Bentley, DgnPlatform, EditElementHandle, CancelDeleteXAttribute));
    c4.def("FindByID", py::overload_cast<ElementId, DgnModelP, bool>(&EditElementHandle::FindByID), "elemId"_a, "dgnCache"_a, "allowDeleted"_a = false, DOC(Bentley, DgnPlatform, EditElementHandle, FindByID));
    c4.def("FindByID", py::overload_cast<ElementId, DgnModelRefP, bool>(&EditElementHandle::FindByID), "elemId"_a, "modelRef"_a, "allowDeleted"_a = false, DOC(Bentley, DgnPlatform, EditElementHandle, FindByID));
    c4.def("AddToModel", &EditElementHandle::AddToModel, DOC(Bentley, DgnPlatform, EditElementHandle, AddToModel));
    c4.def("DeleteFromModel", &EditElementHandle::DeleteFromModel, DOC(Bentley, DgnPlatform, EditElementHandle, DeleteFromModel));
    c4.def("ReplaceInModel", &EditElementHandle::ReplaceInModel, "oldRef"_a, DOC(Bentley, DgnPlatform, EditElementHandle, ReplaceInModel));
    
    c4.def("__iter__", [](EditElementHandle& self)
        { 
        return py::make_iterator(self.BeginElementLinkages(), self.EndElementLinkages());
        }, py::keep_alive<0, 1>());

    //===================================================================================
    // struct IElementSet
    py::class_< IElementSet, std::unique_ptr< IElementSet, py::nodelete> > c5(m, "IElementSet");

    c5.def_property_readonly("Count", &IElementSet::GetCount);
    c5.def("GetCount", &IElementSet::GetCount, DOC(Bentley, DgnPlatform, IElementSet, GetCount));
    c5.def("__len__", &IElementSet::GetCount);
    c5.def("GetFirst", &IElementSet::GetFirst, "elHandle"_a, DOC(Bentley, DgnPlatform, IElementSet, GetFirst));
    c5.def("GetNext", &IElementSet::GetNext, "elHandle"_a, DOC(Bentley, DgnPlatform, IElementSet, GetNext));

    //===================================================================================
    // struct ChildElemIter
    py::class_< ChildElemIter, ElementHandle> c6(m, "ChildElemIter");

    c6.def(py::init<>());
    c6.def(py::init<ElementHandleCR, ExposeChildrenReason>(), "from"_a, "reason"_a = ExposeChildrenReason::Query);
    c6.def("ToNext", &ChildElemIter::ToNext, DOC(Bentley, DgnPlatform, ChildElemIter, ToNext));

    //===================================================================================
    // struct ChildEditElemIter
    py::class_< DgnPlatform::ChildEditElemIter, EditElementHandle> c7(m, "ChildEditElemIter");

    c7.def(py::init<>());

    c7.def(py::init(
        [] (EditElementHandleR from)
        {
        return new DgnPlatform::ChildEditElemIter(from);
        }), "from"_a);

    c7.def("ToNext", &DgnPlatform::ChildEditElemIter::ToNext);    
    }