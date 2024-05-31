/*--------------------------------------------------------------------------------------+
|
|  $Source: \MSPython\MSPythonWrapper\PyDgnPlatform\testUtilities\pyECTestHelpers.cpp $
|
|  $Copyright: (c) 2024 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include "ECTestHelpers.h"
USING_NAMESPACE_EC

/*---------------------------------------------------------------------------------**//**
* Class generator for ECTestHelpers.
* @bsimethod                                                                       02/2024
+---------------+---------------+---------------+---------------+---------------+------*/
void def_ECTestHelpers (py::module_& m)
{
    //===================================================================================
    // struct ECTestHelpers created for ECXAttribute API tests
    py::class_<ECTestHelpers> c1(m, "ECTestHelpers");

    c1.def_static("CountInstances", &ECTestHelpers::CountInstances, "instances"_a);

    c1.def_static("FindInstance", &ECTestHelpers::FindInstance, "scope"_a, "query"_a);

    c1.def_static("GetValue", &ECTestHelpers::GetValue, "v"_a, "instance"_a, "accessString"_a, "arrayIndex"_a = -1);

    c1.def_static("SetValue", &ECTestHelpers::SetValue, "v"_a, "instance"_a, "accessString"_a, "arrayIndex"_a = -1);

    c1.def_static("ValuesAreEqual", &ECTestHelpers::ValuesAreEqual, "a"_a, "b"_a);

    c1.def_static("InstanceHasValue", &ECTestHelpers::InstanceHasValue,"instance"_a, "expectedValue"_a, "accessString"_a, "arrayIndex"_a = -1);
}