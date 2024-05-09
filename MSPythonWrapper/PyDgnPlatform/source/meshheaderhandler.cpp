/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnPlatform\source\meshheaderhandler.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <DgnPlatform/MeshHeaderHandler.h>



/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_MeshHeaderHandler(py::module_& m)
    {
    //===================================================================================
    // struct MeshHeaderHandler
    py::class_< MeshHeaderHandler, std::unique_ptr< MeshHeaderHandler, py::nodelete>, DisplayHandler, IMeshEdit> c1(m, "MeshHeaderHandler");

    c1.def_static("CreateMeshElement", [] (EditElementHandleR  eeh,
                                            ElementHandleCP     templateEh,
                                            PolyfaceHeaderCR     meshData,
                                            bool                is3d,
                                            DgnModelRefR        modelRef)
        {
        return MeshHeaderHandler::CreateMeshElement (eeh, templateEh, meshData, is3d, modelRef);
        }, "eeh"_a, "templateEh"_a, "meshData"_a, "is3d"_a, "modelRef"_a);
    c1.def_property_readonly_static("Instance", [] (py::object const&) { return std::unique_ptr<MeshHeaderHandler, py::nodelete>(&MeshHeaderHandler::GetInstance()); });
    c1.def_static("GetInstance", &MeshHeaderHandler::GetInstance, py::return_value_policy::reference);
    }