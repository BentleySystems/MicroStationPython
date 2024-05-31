/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyMstnPlatform\source\MdlApi\expression.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <pybind11/functional.h>
#include <Mstn/PythonMacro/PyCExpression.h>
#include <Mstn\MdlApi\cexpr.h>

USING_NAMESPACE_BENTLEY_MSTNPLATFORM

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                      3/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_msexpression(py::module_& m)
    {
    py::enum_<CExprValueType>(m, "PyCExprValueType")
        .value("ePy_CEXPR_TYPE_POINTER", CEXPR_TYPE_POINTER)
        .value("ePy_CEXPR_TYPE_LONG", CEXPR_TYPE_LONG)
        .value("ePy_CEXPR_TYPE_ULONG", CEXPR_TYPE_ULONG)
        .value("ePy_CEXPR_TYPE_DOUBLE", CEXPR_TYPE_DOUBLE)
        .value("ePy_CEXPR_TYPE_LONG64", CEXPR_TYPE_LONG64);

    py::class_<PyCExprValue> c1(m, "PyCExprValue");    
    c1.def (py::init([](double val) {return new PyCExprValue (val); }));
    c1.def (py::init([](long val) {return new PyCExprValue (val); }));
    c1.def (py::init([](Utf8CP val) {return new PyCExprValue (val); }));

    c1.def_property_readonly ("Type", &PyCExprValue::GetType);

    c1.def ("GetDoubleValue", [](PyCExprValue& obj) {
        double value;
        if (obj.GetDoubleValue (value)) {
            return value;
        }
        else {
            throw std::runtime_error ("Failed to get Double value");
        }
        });

    c1.def ("GetLongValue", [](PyCExprValue& obj) {
        long value;
        if (obj.GetLongValue (value)) {
            return value;
        }
        else {
            throw std::runtime_error ("Failed to get Long value");
        }
        });

    c1.def ("GetUtf8StringValue", [](PyCExprValue& obj) {
        Utf8String value;
        if (obj.GetUtf8StringValue (value)) {
            return value;
        }
        else {
            throw std::runtime_error ("Failed to get Utf8 string value");
        }
        });

    py::class_< PyCExpression> c2(m, "PyCExpression");
    c2.def_static ("SetCExpressionValue", &PyCExpression::SetMdlCExpressionValue, "expression"_a, "value"_a, "taskId"_a);
    c2.def_static ("GetCExpressionValue", &PyCExpression::GetMdlCExpressionValue, "expression"_a, "taskId"_a, "value"_a);
    }