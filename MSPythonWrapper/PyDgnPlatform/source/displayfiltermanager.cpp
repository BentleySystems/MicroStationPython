/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnPlatform\source\displayfiltermanager.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <DgnPlatform/DisplayFilterManager.h>



static const char * __doc_Bentley_DgnPlatform_DisplayFilterHandlerManager_RegisterHandler =R"doc(Bentley Systems Register a DisplayFilterHandler manager. Should be
called once per session. +---------------+---------------+------------
---+---------------+---------------+------)doc";

static const char * __doc_Bentley_DgnPlatform_DisplayFilterHandlerManager_GetManager =R"doc(Bentley Systems Return reference to (singleton)
DisplayFilterHandlerManager +---------------+---------------+---------
------+---------------+---------------+------)doc";

//=======================================================================================
// Publicist class for DisplayFilterHandler.
// @bsiclass                                                                   02/23
//=======================================================================================
struct DisplayFilterHandlerPub : DisplayFilterHandler
    {
    public:
        using DisplayFilterHandler::_DoConditionalDraw;
        using DisplayFilterHandler::_OnTransform;
        using DisplayFilterHandler::_IsEqual;
        using DisplayFilterHandler::_GetDumpString;
        using DisplayFilterHandler::_ProcessProperties;
    };

//=======================================================================================
// Trampoline class for DisplayFilterHandler.
// @bsiclass                                                                   02/23
//=======================================================================================
struct PyDisplayFilterHandler : DisplayFilterHandler
    {
    public:
        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/    
        virtual bool _DoConditionalDraw(ViewContextR viewContext, ElementHandleCP element, void const* data, size_t dataSize) const override
            {
            try
                {
                py::gil_scoped_acquire gil;
                py::function pyfunc = py::get_override(this, "_DoConditionalDraw");
                bool retVal = false;
                if (pyfunc && data && dataSize > 0)
                    {
                    // _DoConditionalDraw(self, viewContext, element, byteData)-> bool
                    auto obj = pyfunc(viewContext, element, py::bytes((const char*) data, dataSize));
                    if (py::isinstance<py::bool_>(obj))
                        retVal = obj.cast<bool>();
                    }
                else
                    pybind11::pybind11_fail("Tried to call pure virtual function DisplayFilterHandler::_DoConditionalDraw");

                return retVal;
                }
            catch (std::exception& ex)
                {
                ScriptEngineManager::Get().InjectException(ex);
                return false;
                }
            }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/    
        virtual StatusInt _OnTransform(TransformInfoCR transform, void* pData, size_t dataSize) const override
            {
            try
                {
                py::gil_scoped_acquire gil;
                py::function pyfunc = py::get_override(this, "_OnTransform");
                StatusInt retVal = ERROR;
                if (pyfunc && pData && dataSize > 0)
                    {
                    // _OnTransform(self, transform, byteData)-> StatusInt
                    py::bytearray byteData((const char*) pData, dataSize);
                    auto obj = pyfunc(transform, byteData);
                    if (py::isinstance<py::int_>(obj))
                        {
                        retVal = obj.cast<StatusInt>();
                        if (retVal == SUCCESS)
                            {
                            std::string strData = (std::string) byteData;
                            memcpy(pData, (const void*) strData.data(), strData.size());
                            }
                        }
                    }
                else
                    retVal = __super::_OnTransform(transform, pData, dataSize);

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
        virtual bool _IsEqual(void const* data, void const* rhsData, size_t dataSize, double distanceTolerance) const override
            {
            try
                {
                py::gil_scoped_acquire gil;
                py::function pyfunc = py::get_override(this, "_IsEqual");
                bool retVal = false;
                if (pyfunc && data && rhsData && dataSize > 0)
                    {
                    // _IsEqual(self, data, rhsData, distanceTolerance)-> bool
                    auto obj = pyfunc(py::bytes((const char*) data, dataSize), py::bytes((const char*) rhsData, dataSize), distanceTolerance);
                    if (py::isinstance<py::bool_>(obj))
                        retVal = obj.cast<bool>();
                    }
                else
                    retVal = __super::_IsEqual(data, rhsData, dataSize, distanceTolerance);

                return retVal;
                }
            catch (std::exception& ex)
                {
                ScriptEngineManager::Get().InjectException(ex);
                return false;
                }
            }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/    
        virtual WString _GetDumpString(void const* data, size_t dataSize, DgnModelP model) const override
            {
            try
                {
                py::gil_scoped_acquire gil;
                py::function pyfunc = py::get_override(this, "_GetDumpString");
                WString retVal;
                if (pyfunc && data && dataSize > 0)
                    {
                    // _GetDumpString(self, data, model)-> WString
                    auto obj = pyfunc(py::bytes((const char*) data, dataSize), model);
                    if (py::isinstance<WString>(obj))
                        retVal = obj.cast<WString>();
                    }
                else
                    retVal = __super::_GetDumpString(data, dataSize, model);

                return retVal;
                }
            catch (std::exception& ex)
                {
                ScriptEngineManager::Get().InjectException(ex);
                return L"";
                }
            }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/    
        virtual void _ProcessProperties(void* data, size_t dataSize, PropertyContextR context) const override
            {
            try
                {
                py::gil_scoped_acquire gil;
                py::function pyfunc = py::get_override(this, "_ProcessProperties");
                if (pyfunc && data && dataSize > 0)
                    {
                    // _ProcessProperties(self, data, context)-> void
                    py::bytearray byteData((const char*) data, dataSize);
                    pyfunc(byteData, context);

                    std::string strData = (std::string) byteData;
                    memcpy(data, (const void*) strData.data(), strData.size());
                    }
                else
                    __super::_ProcessProperties(data, dataSize, context);
                }
            catch (std::exception& ex)
                {
                ScriptEngineManager::Get().InjectException(ex);                
                }
            }
    };

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_DisplayFilterManager(py::module_& m)
    {
    //===================================================================================
    // enum DisplayFilterHandler_MinorId
    py::enum_< DisplayFilterHandler_MinorId>(m, "DisplayFilterHandler_MinorId", py::arithmetic())
        .value("eDisplayFilterHandlerMinorId_Base", DisplayFilterHandlerMinorId_Base)
        .value("eDisplayFilterHandlerMinorId_ViewXFlag", DisplayFilterHandlerMinorId_ViewXFlag)
        .value("eDisplayFilterHandlerMinorId_ViewXInteger", DisplayFilterHandlerMinorId_ViewXInteger)
        .export_values();        

    //===================================================================================
    // enum DisplayFilterOpCode
    py::enum_< DisplayFilterOpCode>(m, "DisplayFilterOpCode", py::arithmetic())
        .value("eDisplayFilterOpCode_And", DisplayFilterOpCode_And)
        .value("eDisplayFilterOpCode_Or", DisplayFilterOpCode_Or)
        .value("eDisplayFilterOpCode_Not", DisplayFilterOpCode_Not)
        .value("eDisplayFilterOpCode_Parameter", DisplayFilterOpCode_Parameter)
        .value("eDisplayFilterOpCode_ViewFlag", DisplayFilterOpCode_ViewFlag)
        .value("eDisplayFilterOpCode_ViewXFlag", DisplayFilterOpCode_ViewXFlag)
        .value("eDisplayFilterOpCode_ViewSize", DisplayFilterOpCode_ViewSize)
        .value("eDisplayFilterOpCode_Level", DisplayFilterOpCode_Level)
        .value("eDisplayFilterOpCode_ViewAxisAngle", DisplayFilterOpCode_ViewAxisAngle)
        .value("eDisplayFilterOpCode_ViewXInteger", DisplayFilterOpCode_ViewXInteger)
        .value("eDisplayFilterOpCode_PresentationFormId", DisplayFilterOpCode_PresentationFormId)
        .value("eDisplayFilterOpCode_PresentationFormFlag", DisplayFilterOpCode_PresentationFormFlag)
        .value("eDisplayFilterOpCode_ViewContextFlag", DisplayFilterOpCode_ViewContextFlag)
        .export_values();

    //===================================================================================
    // struct DisplayFilterHandlerId
    py::class_< DisplayFilterHandlerId, HandlerId> c1(m, "DisplayFilterHandlerId");

    c1.def(py::init<>());
    c1.def(py::init< DisplayFilterHandler_MinorId>(), "minorId"_a);

    //===================================================================================
    // struct DisplayFilterHandler
    py::class_ < DisplayFilterHandler, std::unique_ptr < DisplayFilterHandler, py::nodelete>, PyDisplayFilterHandler > c2(m, "DisplayFilterHandler");

    c2.def(py::init<>());
    c2.def("_DoConditionalDraw", [] (DisplayFilterHandler const& self, ViewContextR viewContext, ElementHandleCP element, py::bytes const& byteData)
           {
           std::string strData = (std::string) byteData;
           return static_cast<DisplayFilterHandlerPub const&>(self)._DoConditionalDraw(viewContext, element, (const void*) strData.data(), strData.size());
           }, "viewContext"_a, "element"_a, "byteData"_a, py::call_guard<py::gil_scoped_release>());

    c2.def("_OnTransform", [] (DisplayFilterHandler const& self, TransformInfoCR transform, py::bytearray& byteData)
           {
           std::string strData = (std::string) byteData;
           auto retVal = static_cast<DisplayFilterHandlerPub const&>(self)._OnTransform(transform, (void*) strData.data(), strData.size());
           if (retVal == SUCCESS)
               byteData = py::bytearray((const char*) strData.data(), strData.size());
           return retVal;
           }, "transform"_a, "byteData"_a, py::call_guard<py::gil_scoped_release>());

    c2.def("_IsEqual", [] (DisplayFilterHandler const& self, py::bytes const& data, py::bytes const& rhsData, double distanceTolerance)
           {
           std::string strData = (std::string) data;
           std::string strRhsData = (std::string) rhsData;
           return static_cast<DisplayFilterHandlerPub const&>(self)._IsEqual((void const*) strData.data(), (void const*) strRhsData.data(), strData.size(), distanceTolerance);
           }, "data"_a, "rhsData"_a, "distanceTolerance"_a, py::call_guard<py::gil_scoped_release>());

    c2.def("_GetDumpString", [] (DisplayFilterHandler const& self, py::bytes const& data, DgnModelP model)
           {
           std::string strData = (std::string) data;
           return static_cast<DisplayFilterHandlerPub const&>(self)._GetDumpString((void const*) strData.data(), strData.size(), model);
           }, "data"_a, "model"_a, py::call_guard<py::gil_scoped_release>());

    c2.def("_ProcessProperties", [] (DisplayFilterHandler const& self, py::bytearray& data, PropertyContextR context)
           {
           std::string strData = (std::string) data;
           static_cast<DisplayFilterHandlerPub const&>(self)._ProcessProperties((void*) strData.data(), strData.size(), context);
           data = py::bytearray((const char*) strData.data(), strData.size());
           }, "data"_a, "context"_a, py::call_guard<py::gil_scoped_release>());

    c2.def("DoConditionalDraw", [] (DisplayFilterHandler const& self, ViewContextR viewContext, ElementHandleCP element, py::bytes const& byteData)
           {
           std::string strData = (std::string) byteData;
           return self.DoConditionalDraw(viewContext, element, (const void*) strData.data(), strData.size());
           }, "viewContext"_a, "element"_a, "byteData"_a, py::call_guard<py::gil_scoped_release>());

    c2.def("OnTransform", [] (DisplayFilterHandler const& self, TransformInfoCR transform, py::bytearray& byteData)
           {
           std::string strData = (std::string) byteData;
           auto retVal = self.OnTransform(transform, (void*) strData.data(), strData.size());
           if (retVal == SUCCESS)
               byteData = py::bytearray((const char*) strData.data(), strData.size());
           return retVal;
           }, "transform"_a, "byteData"_a, py::call_guard<py::gil_scoped_release>());

    c2.def("IsEqual", [] (DisplayFilterHandler& self, py::bytes const& data, py::bytes const& rhsData, double distanceTolerance)
           {
           std::string strData = (std::string) data;
           std::string strRhsData = (std::string) rhsData;
           return self.IsEqual((void const*) strData.data(), (void const*) strRhsData.data(), strData.size(), distanceTolerance);
           }, "data"_a, "rhsData"_a, "distanceTolerance"_a, py::call_guard<py::gil_scoped_release>());

    c2.def("GetDumpString", [] (DisplayFilterHandler const& self, py::bytes const& data, DgnModelP model)
           {
           std::string strData = (std::string) data;
           return self.GetDumpString((void const*) strData.data(), strData.size(), model);
           }, "data"_a, "model"_a, py::call_guard<py::gil_scoped_release>());

    c2.def("ProcessProperties", [] (DisplayFilterHandler const& self, py::bytearray& data, PropertyContextR context)
           {
           std::string strData = (std::string) data;
           self.ProcessProperties((void*) strData.data(), strData.size(), context);
           data = py::bytearray((const char*) strData.data(), strData.size());
           }, "data"_a, "context"_a, py::call_guard<py::gil_scoped_release>());

    //===================================================================================
    // struct DisplayFilterHandlerManager
    py::class_< DisplayFilterHandlerManager> c3(m, "DisplayFilterHandlerManager");

    c3.def_static("GetManager", &DisplayFilterHandlerManager::GetManager, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, DisplayFilterHandlerManager, GetManager));
    c3.def("RegisterHandler", &DisplayFilterHandlerManager::RegisterHandler, "id"_a, "handler"_a, py::keep_alive<1, 3>(), DOC(Bentley, DgnPlatform, DisplayFilterHandlerManager, RegisterHandler));
    c3.def("GetHandler", &DisplayFilterHandlerManager::GetHandler, "id"_a, py::return_value_policy::reference_internal);
    c3.def("RegisterOperatorHandler", &DisplayFilterHandlerManager::RegisterOperatorHandler, "opCode"_a, "handler"_a, py::keep_alive<1, 3>());
    c3.def("GetOperatorHandler", &DisplayFilterHandlerManager::GetOperatorHandler, "id"_a, py::return_value_policy::reference_internal);

    //===================================================================================
    // struct DisplayFilterKey : RefCountedBase
    py::class_< DisplayFilterKey, DisplayFilterKeyPtr> c4(m, "DisplayFilterKey");

    c4.def(py::init(&DisplayFilterKey::Create));
    c4.def("Matches", &DisplayFilterKey::Matches, "viewContext"_a, "element"_a);
    c4.def("PushState", [] (DisplayFilterKey& self, DisplayFilterHandlerId filterId, py::bytes const& byteData, bool state)
           {
           std::string strData = (std::string) byteData;
           self.PushState(filterId, (void const*) strData.data(), strData.size(), state);
           }, "filterId"_a, "byteData"_a, "state"_a);

    c4.def("IsEmpty", &DisplayFilterKey::IsEmpty);    
    }