/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnPlatform\source\inamedviewelementhandler.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <DgnPlatform/INamedViewElementHandler.h>



static const char * __doc_Bentley_DgnPlatform_INamedViewElementHandler_GetViewTypeNameForPersistence =R"doc(Returns:
    View type string

Remark:
    s This is the same as GetViewTypeName () which is a translatable
    string displayed in the UI.)doc";

static const char * __doc_Bentley_DgnPlatform_INamedViewElementHandler_GetViewTypeName =R"doc(Returns:
    View type string

Remark:
    s This is not the same as GetViewTypeNameForPersistence () which
    is a hard-coded string that may be persisted in a DgnFile.)doc";

static const char * __doc_Bentley_DgnPlatform_INamedViewElementHandler_CreateView =R"doc(Call this method to create an object of your view type

Parameter ``destinationFile``:
    reference to DgnFile object

Returns:
    RefCounted pointer to view object)doc";

//=======================================================================================
// Publicist class for INamedViewElementHandler.
// @bsiclass                                                                   02/23
//=======================================================================================
struct INamedViewElementHandlerPub : INamedViewElementHandler
    {
    public:
        using INamedViewElementHandler::_CreateView;
        using INamedViewElementHandler::_IsExpectedRootModelType;
        using INamedViewElementHandler::_IsInternalViewType;
        using INamedViewElementHandler::_GetViewTypeName;
        using INamedViewElementHandler::_GetViewTypeNameForPersistence;
    };

//=======================================================================================
// Trampoline class for INamedViewElementHandler.
// @bsiclass                                                                   02/23
//=======================================================================================
struct IPyNamedViewElementHandler : INamedViewElementHandler
    {
    public:
        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual NamedViewPtr _CreateView(DgnFileR destinationFile) const override
            { PYBIND11_OVERRIDE_PURE_NAME_EXR(NamedViewPtr, INamedViewElementHandler, "_CreateViewForFile", _CreateView, nullptr, destinationFile); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual NamedViewPtr _CreateView(ElementHandleCR elemHandle) const override
            { PYBIND11_OVERRIDE_PURE_NAME_EXR(NamedViewPtr, INamedViewElementHandler, "_CreateViewForElement", _CreateView, nullptr, elemHandle); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual NamedViewPtr _CreateView(ViewInfoCR viewInfo, ViewPortInfoCR viewPortInfo, DgnFileR destinationFile, WCharCP viewName) const override
            { PYBIND11_OVERRIDE_PURE_NAME_EXR(NamedViewPtr, INamedViewElementHandler, "_CreateViewForViewport", _CreateView, nullptr, viewInfo, viewPortInfo, destinationFile, viewName); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _IsExpectedRootModelType(DgnModelType modelType) const override
            { PYBIND11_OVERRIDE_PURE_EXR(bool, INamedViewElementHandler, _IsExpectedRootModelType, false, modelType); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _IsInternalViewType() const override
            { PYBIND11_OVERRIDE_PURE_EXR(bool, INamedViewElementHandler, _IsInternalViewType, false, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual WString _GetViewTypeName() const override
            { PYBIND11_OVERRIDE_PURE_EXR(WString, INamedViewElementHandler, _GetViewTypeName, WString(), ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual WString _GetViewTypeNameForPersistence() const override
            { PYBIND11_OVERRIDE_PURE_EXR(WString, INamedViewElementHandler, _GetViewTypeNameForPersistence, WString(), ); }
    };

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_INamedViewElementHandler(py::module_& m)
    {
    //===================================================================================
    // struct INamedViewElementHandler
    py::class_< INamedViewElementHandler, std::unique_ptr< INamedViewElementHandler, py::nodelete>, IPyNamedViewElementHandler> c1(m, "INamedViewElementHandler");

    c1.def("_CreateViewForFile", [] (INamedViewElementHandler const& self, DgnFileR destinationFile)
           {
           return static_cast<INamedViewElementHandlerPub const&>(self)._CreateView(destinationFile);
           }, "destinationFile"_a);

    c1.def("_CreateViewForElement", [] (INamedViewElementHandler const& self, ElementHandleCR elemHandle)
           {
           return static_cast<INamedViewElementHandlerPub const&>(self)._CreateView(elemHandle);
           }, "elemHandle"_a);

    c1.def("_CreateViewForViewport", [] (INamedViewElementHandler const& self, ViewInfoCR viewInfo, ViewPortInfoCR viewPortInfo, DgnFileR destinationFile, WCharCP viewName)
           {
           return static_cast<INamedViewElementHandlerPub const&>(self)._CreateView(viewInfo, viewPortInfo, destinationFile, viewName);
           }, "viewInfo"_a, "viewPortInfo"_a, "destinationFile"_a, "viewName"_a);

    c1.def("_IsExpectedRootModelType", &INamedViewElementHandlerPub::_IsExpectedRootModelType, "modelType"_a);
    c1.def("_IsInternalViewType", &INamedViewElementHandlerPub::_IsInternalViewType);
    c1.def("_GetViewTypeName", &INamedViewElementHandlerPub::_GetViewTypeName);
    c1.def("_GetViewTypeNameForPersistence", &INamedViewElementHandlerPub::_GetViewTypeNameForPersistence);

    c1.def("CreateView", py::overload_cast<DgnFileR>(&INamedViewElementHandler::CreateView), "destinationFile"_a, DOC(Bentley, DgnPlatform, INamedViewElementHandler, CreateView));
    c1.def("CreateView", py::overload_cast<ElementHandleCR>(&INamedViewElementHandler::CreateView), "elemHandle"_a, DOC(Bentley, DgnPlatform, INamedViewElementHandler, CreateView));
    c1.def("CreateView", py::overload_cast<ViewInfoCR, ViewPortInfoCR, DgnFileR, WCharCP>(&INamedViewElementHandler::CreateView), "viewInfo"_a, "viewPortInfo"_a, "destinationFile"_a, "viewName"_a, DOC(Bentley, DgnPlatform, INamedViewElementHandler, CreateView));
    c1.def_property_readonly("ViewTypeName", &INamedViewElementHandler::GetViewTypeName);
    c1.def("GetViewTypeName", &INamedViewElementHandler::GetViewTypeName, DOC(Bentley, DgnPlatform, INamedViewElementHandler, GetViewTypeName));

    c1.def_property_readonly("ViewTypeNameForPersistence", &INamedViewElementHandler::GetViewTypeNameForPersistence);
    c1.def("GetViewTypeNameForPersistence", &INamedViewElementHandler::GetViewTypeNameForPersistence, DOC(Bentley, DgnPlatform, INamedViewElementHandler, GetViewTypeNameForPersistence));
    }