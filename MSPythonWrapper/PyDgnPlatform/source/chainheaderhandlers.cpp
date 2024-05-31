/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnPlatform\source\chainheaderhandler.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <DgnPlatform/ChainHeaderHandlers.h>



static const char * __doc_Bentley_DgnPlatform_ChainHeaderHandler_AddComponentComplete =R"doc(Update the chains's range once all component elements have been added.

Parameter ``eeh``:
    The chain element.

Returns:
    SUCCESS if the chain has components and it's range was sucessfully
    updated. Bentley Systems +---------------+---------------+--------
    -------+---------------+---------------+------)doc";

static const char * __doc_Bentley_DgnPlatform_ChainHeaderHandler_AddComponentElement =R"doc(Add another element as a component of the chain. Only open curves will
be accepted. The components are expected to be properly oriented, head
to tail. A complex chain will stroke across gaps during display.

Parameter ``eeh``:
    The chain to add the component to.

Parameter ``componentEeh``:
    The chain element to add.

Returns:
    SUCCESS if component is suitable for a chain component and was
    successfully added. @note componentEeh will be invalid after this
    call unless it represents a persistent element.

See also:
    IsValidChainComponentType Bentley Systems +---------------+-------
    --------+---------------+---------------+---------------+------)doc";

static const char * __doc_Bentley_DgnPlatform_ChainHeaderHandler_IsValidChainComponentType =R"doc(Check the supplied element to determine if it is an acceptable type
for inclusion in a complex string or shape. Valid components are open
curves of the following types:\li LINE_ELM \li LINE_STRING_ELM \li
CURVE_ELM \li ARC_ELM \li BSPLINE_CURVE_ELM <p>

Parameter ``eh``:
    The element to check.

Returns:
    true if element is valid candidate. Bentley Systems +-------------
    --+---------------+---------------+---------------+---------------
    +------)doc";

static const char * __doc_Bentley_DgnPlatform_ChainHeaderHandler_CreateChainHeaderElement =R"doc(Create a new CMPLX_STRING_ELM or CMPLX_SHAPE_ELM header. After
creating the chain header the application should use
AddComponentElement to add open curve elements to the chain, and
AddComponentComplete once all components have been added to finish the
chain creation.

Parameter ``eeh``:
    The new element.

Parameter ``templateEh``:
    Template element to use for symbology; if NULL defaults are used.

Parameter ``isClosed``:
    true for a CMPLX_SHAPE_ELM and false for a CMPLX_STRING_ELM.

Parameter ``is3d``:
    Initialize the 2d or 3d element structure, typically
    modelRef->Is3d ().

Parameter ``modelRef``:
    Model to associate this element with. Will be returned from
    eeh.GetModelRef () and later used by AddComponentComplete to
    update the chain's range. @note Chain components can only be open
    curves and only non-extended types, this is enforced by
    AddComponentElement. Bentley Systems +---------------+------------
    ---+---------------+---------------+---------------+------)doc";

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_ChainHeaderHandlers(py::module_& m)
    {
    //===================================================================================
    // struct ChainHeaderHandler
    py::class_< 
        ChainHeaderHandler,         
        ComplexHeaderDisplayHandler, 
        ICurvePathEdit> c1(m, "ChainHeaderHandler");
    
    c1.def_static("CreateChainHeaderElement", &ChainHeaderHandler::CreateChainHeaderElement, "eeh"_a, "templateEh"_a, "isClosed"_a, "is3d"_a, "modelRef"_a, DOC(Bentley, DgnPlatform, ChainHeaderHandler, CreateChainHeaderElement));
    c1.def_static("IsValidChainComponentType", &ChainHeaderHandler::IsValidChainComponentType, "eh"_a, DOC(Bentley, DgnPlatform, ChainHeaderHandler, IsValidChainComponentType));
    c1.def_static("AddComponentElement", &ChainHeaderHandler::AddComponentElement, "eeh"_a, "componentEeh"_a, DOC(Bentley, DgnPlatform, ChainHeaderHandler, AddComponentElement));
    c1.def_static("AddComponentComplete", &ChainHeaderHandler::AddComponentComplete, "eeh"_a, DOC(Bentley, DgnPlatform, ChainHeaderHandler, AddComponentComplete));
    c1.def_property_readonly_static("Instance", [] (py::object const&) { return std::unique_ptr<ChainHeaderHandler, py::nodelete>(&ChainHeaderHandler::GetInstance()); });
    c1.def_static("GetInstance", &ChainHeaderHandler::GetInstance, py::return_value_policy::reference);

    //===================================================================================
    // struct ComplexStringHandler
    py::class_< 
        ComplexStringHandler, 
        std::unique_ptr< ComplexStringHandler, py::nodelete>, 
        ChainHeaderHandler> c2(m, "ComplexStringHandler");

    c2.def_property_readonly_static("Instance", [] (py::object const&) { return std::unique_ptr<ComplexStringHandler, py::nodelete>(&ComplexStringHandler::GetInstance()); });
    c2.def_static("GetInstance", &ComplexStringHandler::GetInstance, py::return_value_policy::reference);

    //===================================================================================
    // struct ComplexShapeHandler
    py::class_< 
        ComplexShapeHandler, 
        std::unique_ptr< ComplexShapeHandler, py::nodelete>, 
        ChainHeaderHandler, 
        IAreaFillPropertiesEdit> c3(m, "ComplexShapeHandler");

    c3.def_property_readonly_static("Instance", [] (py::object const&) { return std::unique_ptr<ComplexShapeHandler, py::nodelete>(&ComplexShapeHandler::GetInstance()); });
    c3.def_static("GetInstance", &ComplexShapeHandler::GetInstance, py::return_value_policy::reference);
    }