/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnView\source\iredraw.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <DgnView/IRedraw.h>
#include <DgnView/IViewManager.h>



static const char * __doc_Bentley_DgnPlatform_RedrawElems_DoRedraw =R"doc(Draw a set of elements, such as from an ElementAgenda.)doc";

static const char * __doc_Bentley_DgnPlatform_RedrawElems_AddViewport =R"doc(Add a view to the current list of views to display to.)doc";

static const char * __doc_Bentley_DgnPlatform_RedrawElems_SetDynamicsViews =R"doc(Set views for dynamic display. The cursor view is given priority.)doc";

static const char * __doc_Bentley_DgnPlatform_RedrawElems_SetViews =R"doc(Set a mask of views (0-7) to display to.)doc";

static const char * __doc_Bentley_DgnPlatform_RedrawElems_SetOneView =R"doc(Set an individual viewport to display to by view number.)doc";

static const char * __doc_Bentley_DgnPlatform_RedrawElems_SetViewport =R"doc(Set an individual viewport to display to.)doc";

static const char * __doc_Bentley_DgnPlatform_RedrawElems_SetAbort =R"doc(Supply an optional class to handle CheckStop/abort processing.)doc";

static const char * __doc_Bentley_DgnPlatform_RedrawElems_SetTransform =R"doc(Supply an optional transform to push before displaying elements.)doc";

static const char * __doc_Bentley_DgnPlatform_RedrawElems_SetClipVector =R"doc(Supply an optional ClipVector to push before displaying elements.)doc";

static const char * __doc_Bentley_DgnPlatform_RedrawElems_SetRedrawOp =R"doc(Supply an optional class for element resymbolization and subsitution
events.)doc";

static const char * __doc_Bentley_DgnPlatform_RedrawElems_SetDrawPurpose =R"doc(Set DrawPurpose appropriate to display reason.)doc";

static const char * __doc_Bentley_DgnPlatform_RedrawElems_SetDrawMode =R"doc(Set DgnDrawMode to use for display. Use DRAW_MODE_TempDraw for
dynamics.)doc";

static const char * __doc_Bentley_DgnPlatform_RedrawElems_SetIgnoreHilite =R"doc(Set to ignore locate/selection set hilite symbology when drawing a
persistent element.)doc";

static const char * __doc_Bentley_DgnPlatform_RedrawElems_SetSearchDgnAttachments =R"doc(When drawing an element, or list of elements to a Viewport, sometimes
it is desirable to also search all other DgnModelRefs that are visible
in that Viewport and, if the other modelref points to the same cache
(but most likely with a different transform), also draw the element
through that other modelRef. In general, most users should not enable
this.)doc";

static const char * __doc_Bentley_DgnPlatform_IRedrawAbort__CheckRedrawAbort =R"doc(Return true to abort the current draw operation. Save aborted state
for _WasAborted.)doc";

static const char * __doc_Bentley_DgnPlatform_IRedrawAbort__WasAborted =R"doc(Return current abort status from a previous call to _CheckRedrawAbort.)doc";

static const char * __doc_Bentley_DgnPlatform_IRedrawOperation__OnRedrawComplete =R"doc(Called after drawing all elements (or after aborting draw).)doc";

static const char * __doc_Bentley_DgnPlatform_IRedrawOperation__OnRedrawFinish =R"doc(Called after all elements have been processed but before detaching
viewport.)doc";

static const char * __doc_Bentley_DgnPlatform_IRedrawOperation__OnResymbolize =R"doc(Called for each element, can be used to push display overrides (see
ViewContext::GetOverrideMatSymb).)doc";

static const char * __doc_Bentley_DgnPlatform_IRedrawOperation__OnRedrawOperation =R"doc(Called for each element, can be used to modify the element to be
displayed. When canUseCached is not NULL, it must be initialized. Set
to false if element has been modified and no longer matches it's
persistent state.

Returns (Tuple, 0):
    ERROR to prevent the element from being drawn.

Returns (Tuple, 1):
	canUseCache.

)doc";

static const char * __doc_Bentley_DgnPlatform_IRedrawOperation__OnRedrawInit =R"doc(Called before drawing any elements.)doc";

//=======================================================================================
// Trampoline class for IRedrawOperation.
// @bsiclass                                                                   02/23
//=======================================================================================
struct IPyRedrawOperation : IRedrawOperation
    {
    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       2/2023
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void _OnRedrawInit(ViewContextR viewContext) override
        { PYBIND11_OVERRIDE_PURE_EX(void, IRedrawOperation, _OnRedrawInit, viewContext); }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       2/2023
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual StatusInt _OnRedrawOperation(EditElementHandleR eeh, ViewContextR viewContext, bool* canUseCached) override
        {
        try
            {
            py::gil_scoped_acquire gil;
            StatusInt retVal = ERROR;
            py::function func = py::get_override(this, "_OnRedrawOperation");
            if (func)
                {
                auto obj = func(eeh, viewContext);
                auto tuple = obj.cast<py::tuple>();
                retVal = tuple[0].cast<StatusInt>();
                if (canUseCached)
                    *canUseCached = tuple[1].cast<bool>();
                }
            else
                pybind11::pybind11_fail("Tried to call pure virtual function IRedrawOperation::_OnRedrawOperation");

            return retVal;
            }
        catch (std::exception& ex)
            {
            ScriptEngineManager::Get().InjectException(ex);
            return ERROR;
            }
        }
    
    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       2/2023
    +---------------+---------------+---------------+---------------+---------------+------*/    
    virtual void _OnResymbolize(ViewContextR viewContext) override
        { PYBIND11_OVERRIDE_PURE_EX(void, IRedrawOperation, _OnResymbolize, viewContext); }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       2/2023
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void _OnRedrawFinish(ViewContextR viewContext) override
        { PYBIND11_OVERRIDE_PURE_EX(void, IRedrawOperation, _OnRedrawFinish, viewContext); }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       2/2023
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual StatusInt _OnRedrawComplete(ViewContextR viewContext) override
        { PYBIND11_OVERRIDE_PURE_EXR(StatusInt, IRedrawOperation, _OnRedrawComplete, ERROR, viewContext); }
    };

//=======================================================================================
// Trampoline class for IRedrawAbort.
// @bsiclass                                                                   02/23
//=======================================================================================
struct IPyRedrawAbort : IRedrawAbort
    {
    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       2/2023
    +---------------+---------------+---------------+---------------+---------------+------*/        
    virtual bool _WasAborted() const override
        { PYBIND11_OVERRIDE_PURE_EXR(bool, IRedrawAbort, _WasAborted, false, ); }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       2/2023
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual bool _CheckRedrawAbort(ViewContextR viewContext) override
        { PYBIND11_OVERRIDE_PURE_EXR(bool, IRedrawAbort, _CheckRedrawAbort, false, viewContext); }
    };

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_IRedraw(py::module_& m)
    {
    //===================================================================================
    // struct IRedrawOperation
    py::class_< IRedrawOperation, std::unique_ptr<IRedrawOperation, py::nodelete>, IPyRedrawOperation> c1(m, "IRedrawOperation");

    c1.def(py::init<>());
    c1.def("_OnRedrawInit", &IRedrawOperation::_OnRedrawInit, "viewContext"_a, DOC(Bentley, DgnPlatform, IRedrawOperation, _OnRedrawInit));
    
    c1.def("_OnRedrawOperation", [] (IRedrawOperation& self, EditElementHandleR eeh, ViewContextR viewContext)
           {
           bool canUseCache = false;
           auto retVal = self._OnRedrawOperation(eeh, viewContext, &canUseCache);
           return py::make_tuple(retVal, canUseCache);
           }, "eeh"_a, "viewContext"_a, DOC(Bentley, DgnPlatform, IRedrawOperation, _OnRedrawOperation));

    c1.def("_OnResymbolize", &IRedrawOperation::_OnResymbolize, "viewContext"_a, DOC(Bentley, DgnPlatform, IRedrawOperation, _OnResymbolize));
    c1.def("_OnRedrawFinish", &IRedrawOperation::_OnRedrawFinish, "viewContext"_a, DOC(Bentley, DgnPlatform, IRedrawOperation, _OnRedrawFinish));
    c1.def("_OnRedrawComplete", &IRedrawOperation::_OnRedrawComplete, "viewContext"_a, DOC(Bentley, DgnPlatform, IRedrawOperation, _OnRedrawComplete));

    //===================================================================================
    // struct IRedrawAbort
    py::class_< IRedrawAbort, std::unique_ptr<IRedrawAbort, py::nodelete>, IPyRedrawAbort> c2(m, "IRedrawAbort");

    c2.def(py::init<>());
    c2.def("_WasAborted", &IRedrawAbort::_WasAborted, DOC(Bentley, DgnPlatform, IRedrawAbort, _WasAborted));
    c2.def("_CheckRedrawAbort", &IRedrawAbort::_CheckRedrawAbort, "viewContext"_a, DOC(Bentley, DgnPlatform, IRedrawAbort, _CheckRedrawAbort));

    //===================================================================================
    // struct RedrawElems
    py::class_< RedrawElems> c3(m, "RedrawElems");

    c3.def(py::init<>());
    c3.def(py::init<ViewportP, DgnDrawMode, DrawPurpose, bool, IRedrawOperation*, ClipVectorCP, TransformCP, IRedrawAbort*>(),
           "vp"_a, "drawMode"_a, "purpose"_a, "otherAttachments"_a = false, "op"_a = nullptr, "clip"_a = nullptr, "trans"_a = nullptr, "abort"_a = nullptr,
           py::keep_alive<1, 2>(), py::keep_alive<1, 6>(), py::keep_alive<1, 7>(), py::keep_alive<1, 8>(), py::keep_alive<1, 9>());

    c3.def("SetSearchDgnAttachments", &RedrawElems::SetSearchDgnAttachments, "other"_a, DOC(Bentley, DgnPlatform, RedrawElems, SetSearchDgnAttachments));
    c3.def("SetIgnoreHilite", &RedrawElems::SetIgnoreHilite, "ignore"_a, DOC(Bentley, DgnPlatform, RedrawElems, SetIgnoreHilite));
    c3.def("SetDrawMode", &RedrawElems::SetDrawMode, "mode"_a, DOC(Bentley, DgnPlatform, RedrawElems, SetDrawMode));
    c3.def("SetDrawPurpose", &RedrawElems::SetDrawPurpose, "purpose"_a, DOC(Bentley, DgnPlatform, RedrawElems, SetDrawPurpose));
    c3.def("SetRedrawOp", &RedrawElems::SetRedrawOp, "op"_a, py::keep_alive<1, 2>(), DOC(Bentley, DgnPlatform, RedrawElems, SetRedrawOp));
    c3.def("SetClipVector", &RedrawElems::SetClipVector, "clip"_a, py::keep_alive<1, 2>(), DOC(Bentley, DgnPlatform, RedrawElems, SetClipVector));
    c3.def("SetTransform", &RedrawElems::SetTransform, "trans"_a, py::keep_alive<1, 2>(), DOC(Bentley, DgnPlatform, RedrawElems, SetTransform));
    c3.def("SetAbort", &RedrawElems::SetAbort, "abort"_a, py::keep_alive<1, 2>(), DOC(Bentley, DgnPlatform, RedrawElems, SetAbort));

    c3.def("SetViewport", &RedrawElems::SetViewport, "vp"_a, py::keep_alive<1, 2>(), DOC(Bentley, DgnPlatform, RedrawElems, SetViewport));
    c3.def("SetOneView", &RedrawElems::SetOneView, "viewSet"_a, "view"_a, DOC(Bentley, DgnPlatform, RedrawElems, SetOneView));
    c3.def("SetViews", &RedrawElems::SetViews, "viewSet"_a, "viewMask"_a, DOC(Bentley, DgnPlatform, RedrawElems, SetViews));
    c3.def("SetDynamicsViews", &RedrawElems::SetDynamicsViews, "viewSet"_a, "cursorView"_a, DOC(Bentley, DgnPlatform, RedrawElems, SetDynamicsViews));
    c3.def("AddViewport", &RedrawElems::AddViewport, "vp"_a, py::keep_alive<1, 2>(), DOC(Bentley, DgnPlatform, RedrawElems, AddViewport));

    c3.def("DoRedraw",
           py::overload_cast<IElementSetP>(&RedrawElems::DoRedraw),
           "elements"_a, DOC(Bentley, DgnPlatform, RedrawElems, DoRedraw));

    c3.def("DoRedraw",
           py::overload_cast<ElementHandleR>(&RedrawElems::DoRedraw),
           "eh"_a, DOC(Bentley, DgnPlatform, RedrawElems, DoRedraw));

    c3.def("DoRedraw",
           py::overload_cast<ElementRefP, DgnModelRefP>(&RedrawElems::DoRedraw),
           "elemRef"_a, "modelRef"_a = nullptr, DOC(Bentley, DgnPlatform, RedrawElems, DoRedraw));

    c3.def("DoRedraw",
           py::overload_cast<ElementRefP, DgnModelRefP>(&RedrawElems::DoRedraw),
           "elemRef"_a, "modelRef"_a = nullptr, DOC(Bentley, DgnPlatform, RedrawElems, DoRedraw));

    c3.def("DoRedraw",
           py::overload_cast<MSElementDescrCP, DgnModelRefP>(&RedrawElems::DoRedraw),
           "elemDescr"_a, "modelRef"_a = nullptr, DOC(Bentley, DgnPlatform, RedrawElems, DoRedraw));

    c3.def("DoRedraw",
           py::overload_cast<IViewTransientsR, bool>(&RedrawElems::DoRedraw),
           "viewTrans"_a, "isPreUpdate"_a = nullptr, DOC(Bentley, DgnPlatform, RedrawElems, DoRedraw));
    }