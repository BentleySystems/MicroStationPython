/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnPlatform\source\ieditactionsource.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <DgnPlatform/IEditActionSource.h>



static const char * __doc_Bentley_DgnPlatform_DgnActionItemContext_GetRootElement =R"doc(Utility function to get the root element from the hitpath)doc";

static const char * __doc_Bentley_DgnPlatform_DgnActionItemContext_GetPoint =R"doc(The active coordinate location of the mouse)doc";

static const char * __doc_Bentley_DgnPlatform_DgnActionItemContext_GetView =R"doc(The viewport of the mouse)doc";

static const char * __doc_Bentley_DgnPlatform_DgnActionItemContext_GetHitPath =R"doc(When the item context is invoked from the view window, If the mouse is
not over any element, path will be NULL.)doc";

//=======================================================================================
// Publicist class for IEditAction.
// @bsiclass                                                                   02/23
//=======================================================================================
struct IEditActionPub : IEditAction
    {
    public:
        using IEditAction::_ExecuteCmd;
        using IEditAction::_GetCommandId;
        using IEditAction::_GetLabel;
        using IEditAction::_SetLabel;
        using IEditAction::_GetDescription;
        using IEditAction::_SetDescription;
        using IEditAction::_GetImageId;
        using IEditAction::_SetImageId;
        using IEditAction::_GetIsEnabled;
        using IEditAction::_SetIsEnabled;
    };

//=======================================================================================
// Publicist class for IEditActionSource.
// @bsiclass                                                                   02/23
//=======================================================================================
struct IEditActionSourcePub : IEditActionSource
    {
    public:
        using IEditActionSource::_GetProviderId;
        using IEditActionSource::_GetProviderName;
        using IEditActionSource::_GetProviderType;
        using IEditActionSource::_GetCommand;
    };

//=======================================================================================
// Trampoline class for IEditActionSource.
// @bsiclass                                                                   02/23
//=======================================================================================
struct IPyEditActionSource : IEditActionSource
    {
    public:
        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/    
        virtual size_t _GetProviderId(void) const override
            { PYBIND11_OVERRIDE_EXR(size_t, IEditActionSource, _GetProviderId, 0, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual WCharCP _GetProviderName(void) const override
            { PYBIND11_OVERRIDE_PURE_EXR(WCharCP, IEditActionSource, _GetProviderName, nullptr, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual ProviderType _GetProviderType(void) const override
            { PYBIND11_OVERRIDE_PURE_EXR(ProviderType, IEditActionSource, _GetProviderType, CommandService, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual void _GetCommand(bvector<IEditActionPtr>& cmds, DgnActionItemContextCR context, int purpose) override
            { PYBIND11_OVERRIDE_PURE_EX(void, IEditActionSource, _GetCommand, cmds, context, purpose); }
    };



/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_IEditActionSource(py::module_& m)
    {
    //===================================================================================
    // struct DgnActionItemContext
    py::class_< DgnActionItemContext, ECN::IAUIDataContext> c3(m, "DgnActionItemContext");

    c3.def_property_readonly("HitPath", &DgnActionItemContext::GetHitPath);
    c3.def("GetHitPath", &DgnActionItemContext::GetHitPath, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, DgnActionItemContext, GetHitPath));
    
    c3.def_property_readonly("View", &DgnActionItemContext::GetView);
    c3.def("GetView", &DgnActionItemContext::GetView, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, DgnActionItemContext, GetView));
    
    c3.def_property_readonly("Point", &DgnActionItemContext::GetPoint);
    c3.def("GetPoint", &DgnActionItemContext::GetPoint, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, DgnActionItemContext, GetPoint));
    
    c3.def_property_readonly("RootElement", &DgnActionItemContext::GetRootElement);
    c3.def("GetRootElement", &DgnActionItemContext::GetRootElement, DOC(Bentley, DgnPlatform, DgnActionItemContext, GetRootElement));

    }