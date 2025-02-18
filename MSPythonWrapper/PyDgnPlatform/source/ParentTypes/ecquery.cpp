/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnPlatform\source\ecquery.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <DgnPlatform/ECQuery.h>



static const char * __doc_Bentley_DgnPlatform_ECQuery_SetPropertyValuePreFilter =R"doc(How to filter *before* creating instances and applying query where
criteria. How to search for substrings in text-valued properties. A
text search is an attribute of a query. The text to search for is
associated with a query. The query mechanism used to do text searching
is called " property value pre - filtering ". Thus, a text search is
specified by supplying an ECSubstringPropertyValueFilter to the query.
A query containing a text search pre-filter can be set up to search
all classes or only specific classes, as usual. The query can contain
a where criterion that applies additional tests to the instances that
contain the desired text. The query applies its property value pre-
filter after filtering on class and before applying where criteria.
/code FindInstancesScopePtr scope = FindInstancesScope::Create(*model,
true); ECQuery query; query.SetSearchAllClasses ();
ECSubstringPropertyValueFilter textSearch (L" EQRSVD ");
query.SetPropertyValuePreFilter (&textSearch); for each
(DgnElementECInstancePtr inst in dgnECManager.FindElementInstances
(*scope, query, model)) ++haveText; /endcode)doc";

static const char * __doc_Bentley_DgnPlatform_ECQuery_AddPropertyNameToSelect =R"doc(Tell this query to create the instance that contains the following
property.)doc";

static const char * __doc_Bentley_DgnPlatform_ECQuery_SetWhereCriterion =R"doc(Specify the WhereCiterion that this query should apply when used to
choose DgnECInstances.

Parameter ``wh``:
    The where criterion that this query should apply when used to
    choose DgnECInstances)doc";

static const char * __doc_Bentley_DgnPlatform_ECQuery_AddSearchClass =R"doc(Tell this query to choose only instances of the specified class and
any other classes passed to this method.

Parameter ``schemaName``:
    The schema

Parameter ``className``:
    The class

Parameter ``isPolymorphic``:
    True to include derived classes)doc";

static const char * __doc_Bentley_DgnPlatform_ECQuery_SetSelectProperties =R"doc(Set to indicate if found ECInstances should contain ECPropertyValues

Parameter ``value``:
    Pass false to return empty ECInstances (they will still have
    ECInstanceId))doc";

static const char * __doc_Bentley_DgnPlatform_ECQuery_CreateQuery =R"doc(Construct an ECQuery. Specify ECQUERY_PROCESS_SearchAllClasses for the
query to consider instances of all classes. Use ECQUERY_PROCESS_Empty
and then call #AddSearchClass to specify classes. Also, see
#SetWhereCriterion to specify a 'where' clause.)doc";

static const char * __doc_Bentley_DgnPlatform_IECPropertyValueFilter_AddChainedFilter =R"doc(Add a chained filter to be executed on any property values which pass
this filter If a chained filter already exists, it will be replaced

Parameter ``chainedFilter``:
    The filter to add)doc";

static const char * __doc_Bentley_DgnPlatform_IECPropertyValueFilter_GetChainedFilter =R"doc(Get the next filter in the chain, if one exists

Returns:
    The filter executed after this one.)doc";

static const char * __doc_Bentley_DgnPlatform_IECPropertyValueFilter_Accept =R"doc(Applies this filter to the specified property value to determine if it
meets the criterion

Parameter ``propertyValue``:
    The property value to accept or reject

Returns:
    true if the property value meets the criterion of this filter)doc";

static const char * __doc_Bentley_DgnPlatform_IECPropertyValueFilter_ConsiderChildValues =R"doc(Get whether members of the specified array or struct property should
be examined by this filter. This allows arrays and structs to be
trivially skipped in circumstances under which the filter will not
accept any of them

Parameter ``parentPropertyValue``:
    The array or struct property value

Returns:
    true if child values should be examined by the filter.)doc";

static const char * __doc_Bentley_DgnPlatform_IECPropertyValueFilter_GetRequiredPrimitiveType =R"doc(Gets the primitive property type this filter applies to

Returns:
    The primitive type this filter applies to, or 0 if it applies to
    properties of any type)doc";

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_ECQuery(py::module_& m)
    {
    //===================================================================================
    // struct SearchClass
    py::class_< SearchClass> c1(m, "SearchClass");
    py::bind_vector<bvector< SearchClass>>(m, "SearchClassArray", py::module_local(false));

    c1.def(py::init<WStringCR, WStringCR, bool>(), "schemaName"_a, "className"_a, "isPoly"_a);

    //===================================================================================
    // struct IECPropertyValueFilter
    py::class_< IECPropertyValueFilter, IECPropertyValueFilterPtr> c2(m, "IECPropertyValueFilter");

    c2.def_property_readonly("RequiredPrimitiveType", &IECPropertyValueFilter::GetRequiredPrimitiveType);
    c2.def("GetRequiredPrimitiveType", &IECPropertyValueFilter::GetRequiredPrimitiveType, DOC(Bentley, DgnPlatform, IECPropertyValueFilter, GetRequiredPrimitiveType));

    c2.def("ConsiderChildValues", &IECPropertyValueFilter::ConsiderChildValues, "parentPropertyValue"_a, DOC(Bentley, DgnPlatform, IECPropertyValueFilter, ConsiderChildValues));
    c2.def("Accept", &IECPropertyValueFilter::Accept, "propertyValue"_a, DOC(Bentley, DgnPlatform, IECPropertyValueFilter, Accept));
    
    c2.def_property_readonly("ChainedFilter", &IECPropertyValueFilter::GetChainedFilter);
    c2.def("GetChainedFilter", &IECPropertyValueFilter::GetChainedFilter, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, IECPropertyValueFilter, GetChainedFilter));
    
    c2.def("AddChainedFilter", &IECPropertyValueFilter::AddChainedFilter, "chainedFilter"_a, py::keep_alive<1, 2>(), DOC(Bentley, DgnPlatform, IECPropertyValueFilter, AddChainedFilter));
        
    //===================================================================================
    // struct ECSubstringPropertyValueFilter
    py::class_< ECSubstringPropertyValueFilter, ECSubstringPropertyValueFilterPtr, IECPropertyValueFilter> c3(m, "ECSubstringPropertyValueFilter");

    c3.def(py::init(&ECSubstringPropertyValueFilter::Create), "pv"_a);

    //===================================================================================
    // struct ECQuery
    py::class_< ECQuery, ECQueryPtr> c4(m, "ECQuery");


    c4.def_static("CreateQuery",
                  py::overload_cast<ECQueryCR, bool>(&ECQuery::CreateQuery),
                  "query"_a, "copyWhereCriteria"_a, DOC(Bentley, DgnPlatform, ECQuery, CreateQuery));

    c4.def_static("CreateQuery",
                  py::overload_cast<ECQueryProcessFlags>(&ECQuery::CreateQuery),
                  "flags"_a, DOC(Bentley, DgnPlatform, ECQuery, CreateQuery));

    c4.def_static("CreateQuery",
                  py::overload_cast<WCharCP, WCharCP, bool>(&ECQuery::CreateQuery),
                  "schemaName"_a, "className"_a, "isPolymorphic"_a = false, DOC(Bentley, DgnPlatform, ECQuery, CreateQuery));

    c4.def_static("CreateQuery",
                  py::overload_cast<ECN::ECClassCR, bool>(&ECQuery::CreateQuery),
                  "ecClass"_a, "isPolymorphic"_a = false, DOC(Bentley, DgnPlatform, ECQuery, CreateQuery));

    c4.def("SetSelectProperties", &ECQuery::SetSelectProperties, "value"_a, DOC(Bentley, DgnPlatform, ECQuery, SetSelectProperties));
    c4.def("AddSearchClass", py::overload_cast<WCharCP, WCharCP, bool>(&ECQuery::AddSearchClass), "schemaName"_a, "className"_a, "isPolymorphic"_a = false, DOC(Bentley, DgnPlatform, ECQuery, AddSearchClass));
    c4.def("SetWhereCriterion", &ECQuery::SetWhereCriterion, "wh"_a, py::keep_alive<1, 2>(), DOC(Bentley, DgnPlatform, ECQuery, SetWhereCriterion));
    c4.def("AddPropertyNameToSelect", &ECQuery::AddPropertyNameToSelect, "propertyName"_a, DOC(Bentley, DgnPlatform, ECQuery, AddPropertyNameToSelect));
    c4.def("SetPropertyValuePreFilter", &ECQuery::SetPropertyValuePreFilter, "filter"_a, py::keep_alive<1, 2>(), DOC(Bentley, DgnPlatform, ECQuery, SetPropertyValuePreFilter));
    }