/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyECObjects\source\ecexpressions.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <ECObjects/ECExpressions.h>

//=======================================================================================
// Publicist class for IECSymbolProvider
// @bsiclass                                                                   02/23
//=======================================================================================
struct IECSymbolProviderPub : IECSymbolProvider
    {
    public:
        using IECSymbolProvider::_GetName;
        using IECSymbolProvider::_PublishSymbols;
    };

//=======================================================================================
// Trampoline class for IECRelationshipEnabler
// @bsiclass                                                                   02/23
//=======================================================================================
struct IPyECSymbolProvider : IECSymbolProvider
    {
    public:
        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual WCharCP _GetName() const override
            { PYBIND11_OVERRIDE_PURE_EXR(WCharCP, IECSymbolProvider, _GetName, nullptr, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual void _PublishSymbols(SymbolExpressionContextR context, bvector<WString> const& requestedSymbolSets) const override
            { PYBIND11_OVERRIDE_PURE_EX(void, IECSymbolProvider, _PublishSymbols, context, requestedSymbolSets); }
    };

//=======================================================================================
// Trampoline class for NodeVisitor
// @bsiclass                                                                   02/23
//=======================================================================================
struct PyNodeVisitor : NodeVisitor
    {
    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       2/2023
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual bool OpenParens() override
        { PYBIND11_OVERRIDE_PURE_EXR(bool, NodeVisitor, OpenParens, false, ); }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       2/2023
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual bool CloseParens() override
        { PYBIND11_OVERRIDE_PURE_EXR(bool, NodeVisitor, CloseParens, false, ); }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       2/2023
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual bool StartArrayIndex(NodeCR node) override
        { PYBIND11_OVERRIDE_PURE_EXR(bool, NodeVisitor, StartArrayIndex, false, node); }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       2/2023
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual bool EndArrayIndex(NodeCR node) override
        { PYBIND11_OVERRIDE_PURE_EXR(bool, NodeVisitor, EndArrayIndex, false, node); }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       2/2023
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual bool StartArguments(NodeCR node) override
        { PYBIND11_OVERRIDE_PURE_EXR(bool, NodeVisitor, StartArguments, false, node); }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       2/2023
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual bool EndArguments(NodeCR node) override
        { PYBIND11_OVERRIDE_PURE_EXR(bool, NodeVisitor, EndArguments, false, node); }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       2/2023
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual bool Comma() override
        { PYBIND11_OVERRIDE_PURE_EXR(bool, NodeVisitor, Comma, false, ); }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       2/2023
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual bool ProcessNode(NodeCR node) override
        { PYBIND11_OVERRIDE_PURE_EXR(bool, NodeVisitor, ProcessNode, false, node); }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       2/2023
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual bool ProcessUnits(UnitSpecCR units) override
        { PYBIND11_OVERRIDE_PURE_EXR(bool, NodeVisitor, ProcessUnits, false, units); }
    };

using IECSymbolProviderPtr = std::unique_ptr< IECSymbolProvider, py::nodelete>;
using NodeVisitorPtr = std::unique_ptr< NodeVisitor, py::nodelete>;

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_ECExpressions(py::module_& m)
    {
    //===================================================================================
    // enum ValueType
    py::enum_<Bentley::ECN::ValueType>(m, "ValueType", py::arithmetic())
        .value("eValType_None", Bentley::ECN::ValueType::ValType_None)
        .value("eValType_ECValue", Bentley::ECN::ValueType::ValType_ECValue)
        .value("eValType_Custom", Bentley::ECN::ValueType::ValType_Custom)
        .value("eValType_InstanceList", Bentley::ECN::ValueType::ValType_InstanceList)
        .value("eValType_ValueList", Bentley::ECN::ValueType::ValType_ValueList)
        .value("eValType_Lambda", Bentley::ECN::ValueType::ValType_Lambda)
        .export_values();

    //===================================================================================
    // struct ExpressionContext
    py::class_< ExpressionContext, ExpressionContextPtr> c1(m, "ExpressionContext");

    c1.def("AllowsTypeConversion", &ExpressionContext::AllowsTypeConversion);
    c1.def("EnforcesUnits", &ExpressionContext::EnforcesUnits);
    c1.def("EnforceGlobalRepresentation", &ExpressionContext::EnforceGlobalRepresentation);

    c1.def_property("EvaluationOptions", &ExpressionContext::GetEvaluationOptions, &ExpressionContext::SetEvaluationOptions);
    c1.def("GetEvaluationOptions", &ExpressionContext::GetEvaluationOptions);
    c1.def("SetEvaluationOptions", &ExpressionContext::SetEvaluationOptions, "options"_a);

    //===================================================================================
    // struct InstanceListExpressionContext
    py::class_< InstanceListExpressionContext, InstanceListExpressionContextPtr, ExpressionContext> c2(m, "InstanceListExpressionContext");

    c2.def(py::init(&InstanceListExpressionContext::Create), "instances"_a, "outer"_a = nullptr);

    //===================================================================================
    // struct InstanceExpressionContext
    py::class_< InstanceExpressionContext, InstanceExpressionContextPtr, InstanceListExpressionContext> c3(m, "InstanceExpressionContext");

    c3.def(py::init(&InstanceExpressionContext::Create), "outer"_a = nullptr);
    c3.def("SetInstance", &InstanceExpressionContext::SetInstance, "instance"_a);
    c3.def("SetInstances", &InstanceExpressionContext::SetInstances, "instances"_a);

    //===================================================================================
    // struct SymbolExpressionContext
    py::class_< SymbolExpressionContext, SymbolExpressionContextPtr, ExpressionContext> c4(m, "SymbolExpressionContext");

    c4.def("AddSymbol", &SymbolExpressionContext::AddSymbol, "symbol"_a);
    c4.def(py::init(py::overload_cast<ExpressionContextP>(&SymbolExpressionContext::Create)), "outer"_a);

    //===================================================================================
    // struct Symbol
    py::class_< Symbol, SymbolPtr> c5(m, "Symbol");

    //===================================================================================
    // struct ContextSymbol
    py::class_< ContextSymbol, ContextSymbolPtr, Symbol> c6(m, "ContextSymbol");

    c6.def(py::init(&ContextSymbol::CreateContextSymbol), "name"_a, "context"_a);

    //===================================================================================
    // struct MethodSymbol
    py::class_< MethodSymbol, MethodSymbolPtr> c7(m, "MethodSymbol");

    c7.def_static("Create", [](WCharCP name,
                               std::function< ExpressionStatus(EvaluationResult&, EvaluationResultVector&)> staticMethod,
                               std::function< ExpressionStatus(EvaluationResult&, ECInstanceListCR, EvaluationResultVector&)> instanceMethod)
                  {
                  return MethodSymbol::Create(name,
                                              staticMethod.target< ExpressionStatus(EvaluationResult&, EvaluationResultVector&)>(),
                                              instanceMethod.target<ExpressionStatus(EvaluationResult&, ECInstanceListCR, EvaluationResultVector&)>());
                  }, "name"_a, "staticMethod"_a, "instanceMethod"_a);

    //===================================================================================
    // struct IECSymbolProvider
    py::class_< IECSymbolProvider, IECSymbolProviderPtr, IPyECSymbolProvider> c8(m, "IECSymbolProvider");

    c8.def(py::init<>());
    c8.def("_GetName", &IECSymbolProviderPub::_GetName);
    c8.def("_PublishSymbols", &IECSymbolProviderPub::_PublishSymbols, "context"_a, "requestedSymbolSets"_a);
    
    c8.def_property_readonly("Name", &IECSymbolProvider::GetName);
    c8.def("GetName", &IECSymbolProvider::GetName, py::return_value_policy::reference_internal);
    
    c8.def("PublishSymbols", &IECSymbolProvider::PublishSymbols, "context"_a, "requestedSymbolSets"_a);

    c8.def_static("RegisterExternalSymbolPublisher", [] (std::function<void(SymbolExpressionContextR, bvector<WString> const&)> externalPublisher)
                  {
                  IECSymbolProvider::RegisterExternalSymbolPublisher(externalPublisher.target<void(SymbolExpressionContextR, bvector<WString> const&)>());
                  }, "externalPublisher"_a, py::keep_alive<1, 2>());

    //===================================================================================
    // enum ExpressionToken
    py::enum_< ExpressionToken>(m, "ExpressionToken", py::arithmetic())
        .value("eTOKEN_None", TOKEN_None)
        .value("eTOKEN_Null", TOKEN_Null)
        .value("eTOKEN_True", TOKEN_True)
        .value("eTOKEN_False", TOKEN_False)
        .value("eTOKEN_Like", TOKEN_Like)
        .value("eTOKEN_Is", TOKEN_Is)
        .value("eTOKEN_Star", TOKEN_Star)
        .value("eTOKEN_Plus", TOKEN_Plus)
        .value("eTOKEN_Minus", TOKEN_Minus)
        .value("eTOKEN_Slash", TOKEN_Slash)
        .value("eTOKEN_Comma", TOKEN_Comma)
        .value("eTOKEN_IntegerDivide", TOKEN_IntegerDivide)
        .value("eTOKEN_LParen", TOKEN_LParen)
        .value("eTOKEN_RParen", TOKEN_RParen)
        .value("eTOKEN_Exponentiation", TOKEN_Exponentiation)
        .value("eTOKEN_And", TOKEN_And)
        .value("eTOKEN_AndAlso", TOKEN_AndAlso)
        .value("eTOKEN_Or", TOKEN_Or)
        .value("eTOKEN_OrElse", TOKEN_OrElse)
        .value("eTOKEN_Concatenate", TOKEN_Concatenate)
        .value("eTOKEN_Mod", TOKEN_Mod)
        .value("eTOKEN_ShiftLeft", TOKEN_ShiftLeft)
        .value("eTOKEN_ShiftRight", TOKEN_ShiftRight)
        .value("eTOKEN_Colon", TOKEN_Colon)
        .value("eTOKEN_LessEqual", TOKEN_LessEqual)
        .value("eTOKEN_GreaterEqual", TOKEN_GreaterEqual)
        .value("eTOKEN_Less", TOKEN_Less)
        .value("eTOKEN_Greater", TOKEN_Greater)
        .value("eTOKEN_Equal", TOKEN_Equal)
        .value("eTOKEN_NotEqual", TOKEN_NotEqual)
        .value("eTOKEN_Not", TOKEN_Not)
        .value("eTOKEN_Xor", TOKEN_Xor)
        .value("eTOKEN_UnsignedShiftRight", TOKEN_UnsignedShiftRight)
        .value("eTOKEN_LeftBracket", TOKEN_LeftBracket)
        .value("eTOKEN_RightBracket", TOKEN_RightBracket)
        .value("eTOKEN_Dot", TOKEN_Dot)
        .value("eTOKEN_IIf", TOKEN_IIf)
        .value("eTOKEN_LCurly", TOKEN_LCurly)
        .value("eTOKEN_RCurly", TOKEN_RCurly)
        .value("eTOKEN_If", TOKEN_If)
        .value("eTOKEN_Else", TOKEN_Else)
        .value("eTOKEN_ElseIf", TOKEN_ElseIf)
        .value("eTOKEN_Select", TOKEN_Select)
        .value("eTOKEN_End", TOKEN_End)
        .value("eTOKEN_EndIf", TOKEN_EndIf)
        .value("eTOKEN_Lambda", TOKEN_Lambda)
        .value("eTOKEN_EqualModify", TOKEN_EqualModify)
        .value("eTOKEN_NotEqualModify", TOKEN_NotEqualModify)
        .value("eTOKEN_NotModify", TOKEN_NotModify)
        .value("eTOKEN_ModModify", TOKEN_ModModify)
        .value("eTOKEN_OrElseModify", TOKEN_OrElseModify)
        .value("eTOKEN_AndAlsoModify", TOKEN_AndAlsoModify)
        .value("eTOKEN_DoubleColon", TOKEN_DoubleColon)
        .value("eTOKEN_Error", TOKEN_Error)
        .value("eTOKEN_Ident", TOKEN_Ident)
        .value("eTOKEN_StringConst", TOKEN_StringConst)
        .value("eTOKEN_PointConst", TOKEN_PointConst)
        .value("eTOKEN_DateTimeConst", TOKEN_DateTimeConst)
        .value("eTOKEN_IntegerConstant", TOKEN_IntegerConstant)
        .value("eTOKEN_HexConstant", TOKEN_HexConstant)
        .value("eTOKEN_FloatConst", TOKEN_FloatConst)
        .value("eTOKEN_UnitsConst", TOKEN_UnitsConst)
        .value("eTOKEN_Unrecognized", TOKEN_Unrecognized)
        .value("eTOKEN_BadNumber", TOKEN_BadNumber)
        .value("eTOKEN_BadOctalNumber", TOKEN_BadOctalNumber)
        .value("eTOKEN_BadHexNumber", TOKEN_BadHexNumber)
        .value("eTOKEN_BadFloatingPointNumber", TOKEN_BadFloatingPointNumber)
        .value("eTOKEN_UnterminatedString", TOKEN_UnterminatedString)
        .value("eTOKEN_PrimaryList", TOKEN_PrimaryList)
        .export_values();

    //===================================================================================
    // struct EvaluationResult
    py::class_< EvaluationResult> c9(m, "EvaluationResult");

    c9.def(py::init<>());
    
    c9.def_property_readonly("ValueType", &EvaluationResult::GetValueType);
    c9.def("GetValueType", &EvaluationResult::GetValueType);
    
    c9.def("IsInstanceList", &EvaluationResult::IsInstanceList);    
    c9.def("IsECValue", &EvaluationResult::IsECValue);    
    c9.def("IsValueList", &EvaluationResult::IsValueList);    
    c9.def("IsLambda", &EvaluationResult::IsLambda);
    
    c9.def("Clear", &EvaluationResult::Clear);
    
    c9.def_property_readonly("ECValue", py::overload_cast<>(&EvaluationResult::GetECValue, py::const_));
    c9.def("GetECValue", py::overload_cast<>(&EvaluationResult::GetECValue, py::const_), py::return_value_policy::reference_internal);
    
    c9.def_property("Units", &EvaluationResult::GetUnits, &EvaluationResult::SetUnits);
    c9.def("GetUnits", &EvaluationResult::GetUnits, py::return_value_policy::reference_internal);
    c9.def("SetUnits", &EvaluationResult::SetUnits, "units"_a);
    
    c9.def_property_readonly("InstanceList", &EvaluationResult::GetInstanceList);
    c9.def("GetInstanceList", &EvaluationResult::GetInstanceList, py::return_value_policy::reference_internal);
    
    c9.def("SetInstanceList", &EvaluationResult::SetInstanceList, "instanceList"_a, "makeCopy"_a);
    c9.def("SetInstance", &EvaluationResult::SetInstance, "instance"_a);

    //===================================================================================
    // struct ValueSymbol
    py::class_< ValueSymbol, ValueSymbolPtr, Symbol> c10(m, "ValueSymbol");

    c10.def(py::init(py::overload_cast<WCharCP, ECValueCR>(&ValueSymbol::Create)), "name"_a, "value"_a);

    //===================================================================================
    // struct NodeVisitor
    py::class_< NodeVisitor, PyNodeVisitor> c11(m, "NodeVisitor");

    c11.def(py::init<>());
    c11.def("OpenParens", &NodeVisitor::OpenParens);
    c11.def("CloseParens", &NodeVisitor::CloseParens);
    c11.def("StartArrayIndex", &NodeVisitor::StartArrayIndex, "node"_a);
    c11.def("EndArrayIndex", &NodeVisitor::EndArrayIndex, "node"_a);
    c11.def("StartArguments", &NodeVisitor::StartArguments, "node"_a);
    c11.def("EndArguments", &NodeVisitor::EndArguments, "node"_a);
    c11.def("Comma", &NodeVisitor::Comma);
    c11.def("ProcessNode", &NodeVisitor::ProcessNode, "node"_a);
    c11.def("ProcessUnits", &NodeVisitor::ProcessUnits, "units"_a);

    //===================================================================================
    // struct ValueResult
    py::class_< ValueResult, ValueResultPtr> c13(m, "ValueResult");

    c13.def("GetECValue", &ValueResult::GetECValue, "ecValue"_a);

    //===================================================================================
    // struct ExpressionResolver
    py::class_< ExpressionResolver, RefCountedPtr<ExpressionResolver> > c14(m, "ExpressionResolver");

    c14.def_property_readonly("ExpressionContext", &ExpressionResolver::GetExpressionContextR);
    c14.def("GetExpressionContext", &ExpressionResolver::GetExpressionContextR, py::return_value_policy::reference_internal);

    //===================================================================================
    // struct Node
    py::class_<Node, NodePtr> c15(m, "Node");

    c15.def("GetValue", [] (Node& self, ExpressionContextR context)
            {
            ValueResultPtr valueResult;
            auto retVal = self.GetValue(valueResult, context);
            return py::make_tuple(retVal, valueResult);
            }, "context"_a);

    c15.def("Traverse", &Node::Traverse, "visitor"_a);
    c15.def("ToString", &Node::ToString);
    c15.def("ToExpressionString", &Node::ToExpressionString);
    }