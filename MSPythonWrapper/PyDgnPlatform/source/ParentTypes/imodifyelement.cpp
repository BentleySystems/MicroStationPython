/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnPlatform\source\imodifyelement.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <DgnPlatform/IModifyElement.h>



static const char * __doc_Bentley_DgnPlatform_IModifyElement__CheckStop =R"doc(Called to abort processing for ElementAgenda::ModifyAgenda.)doc";

static const char * __doc_Bentley_DgnPlatform_IModifyElement__ResetStop =R"doc(Called to initialize abort processing for ElementAgenda::ModifyAgenda.)doc";

static const char * __doc_Bentley_DgnPlatform_IModifyElement__OnElementModify =R"doc(Called to apply element modification.

Parameter ``eeh``:
    IN element to apply modification to.

Returns:
    SUCCESS if modify was ok and element should be replaced, deleted,
    or added/copied.)doc";

static const char * __doc_Bentley_DgnPlatform_IModifyElement__DoOperationForModify =R"doc(Called to perform element modification and update element.)doc";

static const char * __doc_Bentley_DgnPlatform_IModifyElement__SetWantGGLock =R"doc(Call to set graphic group number remap option for copy.)doc";

static const char * __doc_Bentley_DgnPlatform_IModifyElement__SetWantMakeCopy =R"doc(Call to set copy option.)doc";

static const char * __doc_Bentley_DgnPlatform_IModifyElement__WantMakeCopy =R"doc(Call to determine whether original element is being modified or
copied.)doc";

static const char * __doc_Bentley_DgnPlatform_IModifyElement__WantCheckGGLock =R"doc(Call to determine whether copied elements will have their graphic
group number remapped or cleared.)doc";

//=======================================================================================
// Trampoline class for IModifyElement.
// @bsiclass                                                                   02/23
//=======================================================================================
struct IPyModifyElement : IModifyElement
    {
    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       2/2023
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual bool _WantCheckGGLock() const override
        { PYBIND11_OVERRIDE_PURE_EXR(bool, IModifyElement, _WantCheckGGLock, false, ); }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       2/2023
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual bool _WantMakeCopy() const override
        { PYBIND11_OVERRIDE_PURE_EXR(bool, IModifyElement, _WantMakeCopy, false, ); }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       2/2023
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void _SetWantMakeCopy(bool makeCopy) override
        { PYBIND11_OVERRIDE_PURE_EX(void, IModifyElement, _SetWantMakeCopy, makeCopy); }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       2/2023
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void _SetWantGGLock(bool checkGGLock) override
        { PYBIND11_OVERRIDE_PURE_EX(void, IModifyElement, _SetWantGGLock, checkGGLock); }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       2/2023
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual StatusInt _DoOperationForModify(EditElementHandleR eeh) override
        { PYBIND11_OVERRIDE_PURE_EXR(StatusInt, IModifyElement, _DoOperationForModify, ERROR, eeh); }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       2/2023
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual StatusInt _OnElementModify(EditElementHandleR eeh) override
        { PYBIND11_OVERRIDE_PURE_EXR(StatusInt, IModifyElement, _OnElementModify, ERROR, eeh); }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       2/2023
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void _ResetStop() override
        { PYBIND11_OVERRIDE_PURE_EX(void, IModifyElement, _ResetStop, ); }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       2/2023
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual bool _CheckStop() override
        { PYBIND11_OVERRIDE_PURE_EXR(bool, IModifyElement, _CheckStop, false, ); }
    };

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_IModifyElement(py::module_& m)
    {
    //===================================================================================
    // struct IModifyElement
    py::class_< IModifyElement, std::unique_ptr< IModifyElement, py::nodelete>, IPyModifyElement> c1(m, "IModifyElement");

    c1.def(py::init<>());
    c1.def("_WantCheckGGLock", &IModifyElement::_WantCheckGGLock, DOC(Bentley, DgnPlatform, IModifyElement, _WantCheckGGLock));
    c1.def("_WantMakeCopy", &IModifyElement::_WantMakeCopy, DOC(Bentley, DgnPlatform, IModifyElement, _WantMakeCopy));
    c1.def("_SetWantMakeCopy", &IModifyElement::_SetWantMakeCopy, "makeCopy"_a, DOC(Bentley, DgnPlatform, IModifyElement, _SetWantMakeCopy));
    c1.def("_SetWantGGLock", &IModifyElement::_SetWantGGLock, "checkGGLock"_a, DOC(Bentley, DgnPlatform, IModifyElement, _SetWantGGLock));
    c1.def("_DoOperationForModify", &IModifyElement::_DoOperationForModify, "eeh"_a, DOC(Bentley, DgnPlatform, IModifyElement, _DoOperationForModify));
    c1.def("_OnElementModify", &IModifyElement::_OnElementModify, "eeh"_a, DOC(Bentley, DgnPlatform, IModifyElement, _OnElementModify));
    c1.def("_ResetStop", &IModifyElement::_ResetStop, DOC(Bentley, DgnPlatform, IModifyElement, _ResetStop));
    c1.def("_CheckStop", &IModifyElement::_CheckStop, DOC(Bentley, DgnPlatform, IModifyElement, _CheckStop));
    }