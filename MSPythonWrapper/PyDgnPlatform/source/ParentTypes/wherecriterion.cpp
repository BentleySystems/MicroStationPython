/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnPlatform\source\wherecriterion.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <DgnPlatform/WhereCriterion.h>



static const char * __doc_Bentley_DgnPlatform_WhereCriterion_ComparePrimitiveValues =R"doc(Utility to compare two values according to a comparison operator. This
function will call PromoteValueToPrimitiveType in order to convert the
values to compatible types, if possible.

:returns:
    true if the values satisfy the comparison.

:param lhs:
    the value on the left

:param rhs:
    the value on the right

:param op:
    how to compare the values

Remark:
    s false is returned if either value is Null or is uninitialized.

Remark:
    s false is returned if either value is not a primitive type.

Remark:
    s Comparing arrays or structs as such is not supported.)doc";

static const char * __doc_Bentley_DgnPlatform_WhereCriterion_PromoteValueToPrimitiveType =R"doc(Utility to do simple primitive type conversions.

:returns:
    value converted to type type wanted or an *uninitialized* value if
    the conversion could not be done. Supported conversions:
    PRIMITIVETYPE_Boolean -> PRIMITIVETYPE_Integer,
    PRIMITIVETYPE_Double, PRIMITIVETYPE_Long  PRIMITIVETYPE_Integer
    -> PRIMITIVETYPE_Double, PRIMITIVETYPE_Long 
    PRIMITIVETYPE_String -> PRIMITIVETYPE_Integer,
    PRIMITIVETYPE_Double, PRIMITIVETYPE_Long  PRIMITIVETYPE_Long ->
    cannot be converted to any other type. However, a request to
    convert PRIMITIVETYPE_Long to an integer type is not considered an
    error and will return the input value unchanged. 
    PRIMITIVETYPE_Double -> cannot be converted to any other type.
    However, a request to convert PRIMITIVETYPE_Double to an integer
    type is not considered an error and will return the input value
    unchanged. All other conversion requests are errors, and an
    uninitialized value is returned. If the input value is not a
    primitive type, an uninitialized value is returned.)doc";

static const char * __doc_Bentley_DgnPlatform_WhereCriterion_AcceptCollection =R"doc(Apply this WhereCriterion to an instance collection, binding the
expressions in the criterion to the instance and evaluating their
values.)doc";

static const char * __doc_Bentley_DgnPlatform_WhereCriterion_Accept =R"doc(Apply this WhereCriterion to the specified DgnECInstance, binding the
expressions in the criterion to the instance and evaluating their
values for this instance.)doc";

static const char * __doc_Bentley_DgnPlatform_WhereCriterion_CreateLogicalOr =R"doc(Create a WhereCriterion that ORs two criteria together. @See
CreateComparison.

:param lhs:
    a criterion to evalute

:param rhs:
    a criterion to evalute)doc";

static const char * __doc_Bentley_DgnPlatform_WhereCriterion_CreateLogicalAnd =R"doc(Create a WhereCriterion that ANDs two criteria together. @See
CreateComparison.

:param lhs:
    a criterion to evalute

:param rhs:
    a criterion to evalute)doc";

static const char * __doc_Bentley_DgnPlatform_WhereCriterion_CreateLogical =R"doc(Create a WhereCriterion that combines the results of other criteria.
@See CreateComparison, CreateRelatedCriterion

:param lhs:
    a criterion to evalute

:param op:
    how to combine the criteria

:param rhs:
    a criterion to evalute)doc";

static const char * __doc_Bentley_DgnPlatform_WhereCriterion_CreateRelatedCriterion =R"doc(Create a WhereCriterion that applies a criterion to a related
instance. @See CreateLogical

:param lhs:
    a related instance

:param rhs:
    a criterion to apply to the related instance)doc";

static const char * __doc_Bentley_DgnPlatform_WhereCriterion_CreateRelatedInstanceFinder =R"doc(Create an agent that looks up a related instance, nested in another
related instance.

:param source:
    Optional. The nested relationship to start from. If NULL, then
    this function will traverse *targetRelationship* on the current
    instance. If not NULL, then this function will evaluate *source*
    against the current instance in order to get a related instance
    and then traverse *targetRelationship* on the related instance.

:param targetRelationship:
    The kind of relationship to look for

:param relationshipCriterion:
    Optional. How to select instances of the specified relationship
    class.)doc";

static const char * __doc_Bentley_DgnPlatform_WhereCriterion_CreateNonNullPropertyTest =R"doc(Create a WhereCriterion which evaluates true if the specified property
value exists and is not null

:param accessString:
    The access string of the ECProperty

:param arrayIndex:
    The array index, if the property is an array; or else -1)doc";

static const char * __doc_Bentley_DgnPlatform_WhereCriterion_CreateNullPropertyTest =R"doc(Create a WhereCriterion which evaluates true if the specified property
value does not exist or is null

:param accessString:
    The access string of the ECProperty

:param arrayIndex:
    The array index, if the property is an array; or else -1)doc";

static const char * __doc_Bentley_DgnPlatform_WhereCriterion_CreatePropertyComparison =R"doc(Create a WhereCriterion that compares a named ECProperty to a known
value. This is a convenience method that just returns
(*WhereExpression::CreatePropertyExpression (ecPropertyName), op,
*WhereExpression::CreateConstant (value))

:param ecPropertyName:
    Name of the ECProperty

:param op:
    Comparison operator, e.g. WhereCriterion::EQ, etc.

:param value:
    ECValue to compare)doc";

static const char * __doc_Bentley_DgnPlatform_WhereCriterion_CreateComparison =R"doc(Create a WhereCriterion that compares the values of two expressions.

See also:
    CreatePropertyExpression, CreateLogical

:param lhs:
    left side WhereExpression to evaluate

:param op:
    how to compare the values of the expressions, e.g.
    WhereCriterion::EQ, etc

:param rhs:
    right side WhereExpression to evaluate

:param isCaseSensitive:
    If true, the match will do a case sensitive match. Otherwise, it
    will be case insensitive.)doc";

static const char * __doc_Bentley_DgnPlatform_WhereExpression_CreatePartialECInstanceIdExpression =R"doc(Create an WhereExpression that accesses the partial InstanceId of a
DgnElementECInstance. The partial InstanceId @See CreateConstant,
CreateConstantSet, CreateComparison.

Remark:
    s If the value of the property is an array, then the array itself
    is the value of this expression.)doc";

static const char * __doc_Bentley_DgnPlatform_WhereExpression_CreateECInstanceIdExpression =R"doc(Create an WhereExpression that accesses the InstanceId of a
DgnElementECInstance. @See CreateConstant, CreateConstantSet,
CreateComparison.

Remark:
    s If the value of the property is an array, then the array itself
    is the value of this expression.)doc";

static const char * __doc_Bentley_DgnPlatform_WhereExpression_CreatePropertyExpression =R"doc(Create an WhereExpression that accesses the value of the specified
property on a DgnElementECInstance. @See CreateConstant,
CreateConstantSet, CreateComparison.

Remark:
    s If the value of the property is an array, then the array itself
    is the value of this expression.

:param accessString:
    identifies the property

:param useDisplayValue:
    if true, the property value will be round-tripped from its display
    value)doc";

static const char * __doc_Bentley_DgnPlatform_WhereExpression_CreateConstantSet =R"doc(Create an expression that is a set of constant values. A set can be
used as the right side of the IS_IN operator. @See CreateConstant,
CreateComparison.

:param s:
    The set constant values)doc";

static const char * __doc_Bentley_DgnPlatform_WhereExpression_CreateConstant =R"doc(Create an expression that holds a constant value. This is useful for
testing property values. @See CreateConstantSet, CreateComparison.

:param v:
    The value of the constant)doc";

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_WhereCriterion(py::module_& m)
    {
    //===================================================================================
    // enum ECQueryProcessFlags
    py::enum_< ECQueryProcessFlags>(m, "ECQueryProcessFlags", py::arithmetic())
        .value("eECQUERY_PROCESS_Empty", ECQUERY_PROCESS_Empty)
        .value("eECQUERY_PROCESS_SearchAllIntrinsic", ECQUERY_PROCESS_SearchAllIntrinsic)
        .value("eECQUERY_PROCESS_SearchAllExtrinsic", ECQUERY_PROCESS_SearchAllExtrinsic)
        .value("eECQUERY_PROCESS_SearchSpecifiedClasses", ECQUERY_PROCESS_SearchSpecifiedClasses)
        .value("eECQUERY_PROCESS_SearchAllClasses", ECQUERY_PROCESS_SearchAllClasses)
        .export_values();

    //===================================================================================
    // struct QueryRelatedClassSpecifier
    py::class_< QueryRelatedClassSpecifier, QueryRelatedClassSpecifierPtr> c1(m, "QueryRelatedClassSpecifier");


    c1.def_static("Create",
                  py::overload_cast<ECN::ECRelationshipClassCR, ECN::ECClassCP, ECN::ECRelatedInstanceDirection, bool, bool, ECQueryProcessFlags>(&QueryRelatedClassSpecifier::Create),
                  "relationshipClass"_a, "dc"_a = nullptr, "dir"_a = ECN::STRENGTHDIRECTION_Forward, "isRelationshipPolyMorphic"_a = false, "isRelatedPolyMorphic"_a = false, "process"_a = ECQUERY_PROCESS_SearchAllClasses);
        
    //===================================================================================
    // struct WhereExpression
    py::class_< WhereExpression, WhereExpressionPtr> c2(m, "WhereExpression");

    c2.def_static("CreateConstant", &WhereExpression::CreateConstant, "v"_a, DOC(Bentley, DgnPlatform, WhereExpression, CreateConstant));

    c2.def_static("CreateConstantSet", [] (bvector<WString> const& s)
                  {
                  bset<WString> s_(s.begin(), s.end());
                  return WhereExpression::CreateConstantSet(s_);
                  }, "s"_a, DOC(Bentley, DgnPlatform, WhereExpression, CreateConstantSet));

    c2.def_static("CreateConstantSet", [] (bvector<Int64> const& s)
                  {
                  bset<Int64> s_(s.begin(), s.end());
                  return WhereExpression::CreateConstantSet(s_);
                  }, "s"_a, DOC(Bentley, DgnPlatform, WhereExpression, CreateConstantSet));

    c2.def_static("CreateConstantSet", [] (bvector<double> const& s)
                  {
                  bset<double> s_(s.begin(), s.end());
                  return WhereExpression::CreateConstantSet(s_);
                  }, "s"_a, DOC(Bentley, DgnPlatform, WhereExpression, CreateConstantSet));

    c2.def_static("CreatePropertyExpression",
                  py::overload_cast<WStringCR, bool>(&WhereExpression::CreatePropertyExpression),
                  "accessString"_a, "useDisplayValue"_a = false, DOC(Bentley, DgnPlatform, WhereExpression, CreatePropertyExpression));

    c2.def_static("CreatePropertyExpression",
                  py::overload_cast<WStringCR, UInt32, bool>(&WhereExpression::CreatePropertyExpression),
                  "accessString"_a, "arrayIndex"_a, "useDisplayValue"_a = false, DOC(Bentley, DgnPlatform, WhereExpression, CreatePropertyExpression));

    c2.def_static("CreateECInstanceIdExpression", &WhereExpression::CreateECInstanceIdExpression, DOC(Bentley, DgnPlatform, WhereExpression, CreateECInstanceIdExpression));
    //c2.def_static("CreatePartialECInstanceIdExpression", &WhereExpression::CreatePartialECInstanceIdExpression, DOC(Bentley, DgnPlatform, WhereExpression, CreatePartialECInstanceIdExpression));

    //===================================================================================
    // struct WhereCriterion
    py::class_< WhereCriterion, WhereCriterionPtr> c3(m, "WhereCriterion");

    if (true)
        {
        //===================================================================================
        // enum CompareOp
        py::enum_< WhereCriterion::CompareOp>(c3, "CompareOp", py::arithmetic())
            .value("eEQ", WhereCriterion::EQ)
            .value("eNE", WhereCriterion::NE)
            .value("eGT", WhereCriterion::GT)
            .value("eGE", WhereCriterion::GE)
            .value("eLT", WhereCriterion::LT)
            .value("eLE", WhereCriterion::LE)
            .value("eIS_IN", WhereCriterion::IS_IN)
            .value("eNOT_IN", WhereCriterion::NOT_IN)
            .export_values();

        //===================================================================================
        // enum LogicalOp
        py::enum_< WhereCriterion::LogicalOp>(c3, "LogicalOp", py::arithmetic())
            .value("eLOGICAL_AND", WhereCriterion::LOGICAL_AND)
            .value("eLOGICAL_OR", WhereCriterion::LOGICAL_OR)
            .export_values();

        //===================================================================================
        // enum StringFilterError
        py::enum_< WhereCriterion::StringFilterError>(c3, "StringFilterError", py::arithmetic())
            .value("eSTRING_FILTER_ERROR_InvalidSyntax", WhereCriterion::STRING_FILTER_ERROR_InvalidSyntax)
            .export_values();

        //===================================================================================
        // enum NumberFilterError
        py::enum_< WhereCriterion::NumberFilterError>(c3, "NumberFilterError", py::arithmetic())
            .value("eNUMBER_FILTER_ERROR_InvalidSyntax", WhereCriterion::NUMBER_FILTER_ERROR_InvalidSyntax)
            .export_values();

        //===================================================================================
        // struct RelatedInstanceFinder
        py::class_< WhereCriterion::RelatedInstanceFinder, RefCountedPtr<WhereCriterion::RelatedInstanceFinder> > c3_1(c3, "RelatedInstanceFinder");
        }

    c3.def_static("CreateComparison", &WhereCriterion::CreateComparison, "lhs"_a, "op"_a, "rhs"_a, "isCaseSensitive"_a = false, DOC(Bentley, DgnPlatform, WhereCriterion, CreateComparison));
    c3.def_static("CreatePropertyComparison", &WhereCriterion::CreatePropertyComparison, "ecPropertyName"_a, "op"_a, "value"_a, DOC(Bentley, DgnPlatform, WhereCriterion, CreatePropertyComparison));
    c3.def_static("CreateNullPropertyTest", &WhereCriterion::CreateNullPropertyTest, "accessString"_a, "arrayIndex"_a = -1, DOC(Bentley, DgnPlatform, WhereCriterion, CreateNullPropertyTest));
    c3.def_static("CreateNonNullPropertyTest", &WhereCriterion::CreateNonNullPropertyTest, "accessString"_a, "arrayIndex"_a = -1, DOC(Bentley, DgnPlatform, WhereCriterion, CreateNonNullPropertyTest));
    
    c3.def_static("CreateStringFilter", [] (WhereExpression& lhs, WCharCP filter, bool ifMatch, bool isCaseSensitive)
                  {
                  WhereCriterion::StringFilterError err;
                  auto retVal = WhereCriterion::CreateStringFilter(&err, lhs, filter, ifMatch, isCaseSensitive);
                  return py::make_tuple(retVal, err);
                  }, "lhs"_a, "filter"_a, "ifMatch"_a, "isCaseSensitive"_a);

    c3.def_static("CreateNumberFilter", [] (WhereExpression& lhs, WCharCP filter, bool ifMatch)
                  {
                  WhereCriterion::NumberFilterError err;
                  auto retVal = WhereCriterion::CreateNumberFilter(&err, lhs, filter, ifMatch);
                  return py::make_tuple(retVal, err);
                  }, "lhs"_a, "filter"_a, "ifMatch"_a);

    c3.def_static("CreateRegexFilter", [] (WhereExpression& lhs, WCharCP regexPattern, bool isCaseSensitive)
                  {
                  WhereCriterion::StringFilterError err;
                  auto retVal = WhereCriterion::CreateRegexFilter(&err, lhs, regexPattern, isCaseSensitive);
                  return py::make_tuple(retVal, err);
                  }, "lhs"_a, "regexPattern"_a, "isCaseSensitive"_a);

    c3.def_static("CreateRelatedInstanceFinder", &WhereCriterion::CreateRelatedInstanceFinder, "source"_a, "targetRelationship"_a, "relationshipCriterion"_a = nullptr, DOC(Bentley, DgnPlatform, WhereCriterion, CreateRelatedInstanceFinder));
    c3.def_static("CreateRelatedCriterion", &WhereCriterion::CreateRelatedCriterion, "lhs"_a, "rhs"_a, DOC(Bentley, DgnPlatform, WhereCriterion, CreateRelatedCriterion));
    c3.def_static("CreateLogical", &WhereCriterion::CreateLogical, "lhs"_a, "op"_a, "rhs"_a, DOC(Bentley, DgnPlatform, WhereCriterion, CreateLogical));
    c3.def_static("CreateLogicalAnd", &WhereCriterion::CreateLogicalAnd, "lhs"_a, "rhs"_a, DOC(Bentley, DgnPlatform, WhereCriterion, CreateLogicalAnd));
    c3.def_static("CreateLogicalOr", &WhereCriterion::CreateLogicalOr, "lhs"_a, "rhs"_a, DOC(Bentley, DgnPlatform, WhereCriterion, CreateLogicalOr));
    c3.def("Accept", &WhereCriterion::Accept, "instance"_a, DOC(Bentley, DgnPlatform, WhereCriterion, Accept));
    c3.def("AcceptCollection", &WhereCriterion::AcceptCollection, "iterable"_a, DOC(Bentley, DgnPlatform, WhereCriterion, AcceptCollection));
    c3.def_static("PromoteValueToPrimitiveType", &WhereCriterion::PromoteValueToPrimitiveType, "v"_a, "typeWanted"_a, DOC(Bentley, DgnPlatform, WhereCriterion, PromoteValueToPrimitiveType));
    c3.def_static("ComparePrimitiveValues", &WhereCriterion::ComparePrimitiveValues, "lhs"_a, "op"_a, "rhs"_a, DOC(Bentley, DgnPlatform, WhereCriterion, ComparePrimitiveValues));

    //===================================================================================
    // struct ECExpressionCriterion
    py::class_< ECExpressionCriterion, RefCountedPtr<ECExpressionCriterion>, WhereCriterion> c4(m, "ECExpressionCriterion");
    }