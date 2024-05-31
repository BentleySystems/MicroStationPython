/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyECObjects\source\eccontext.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <ECObjects/ECSchema.h>
#include <ECObjects/ECContext.h>



static const char * __doc_Bentley_ECObjects_ECInstanceReadContext_CreateContext = R"doc(- For use when the caller knows the schema of the instance he is
deserializing.
Returns (Tuple, 0):
	retVal.

Returns (Tuple, 1):
	foundSchema.

)doc";

static const char * __doc_Bentley_ECObjects_ECSchemaReadContext_GetCache = R"doc(Gets the schemas cached by this context.

Returns:
    Schemas cached by this context)doc";

static const char * __doc_Bentley_ECObjects_ECSchemaReadContext_LocateSchema = R"doc(Find the schema matching the schema key and using matchType as the
match criteria. This uses the prioritized list of locators to find the
schema.

Parameter ``key``:
    The SchemaKey that defines the schema (name and version
    information) that is being looked for

Parameter ``matchType``:
    The match type criteria used to locate the requested schema

Returns:
    An ECSchemaPtr. This ptr will return false for IsValid() if the
    schema could not be located.)doc";

static const char * __doc_Bentley_ECObjects_ECSchemaReadContext_SetFinalSchemaLocater = R"doc(Set the last locater to be used when trying to find a schema

Parameter ``locater``:
    Locater that should be used as the last locater when trying to
    find a schema)doc";

static const char * __doc_Bentley_ECObjects_ECSchemaReadContext_GetCultures = R"doc(Gets culture strings)doc";

static const char * __doc_Bentley_ECObjects_ECSchemaReadContext_AddCulture = R"doc(Adds a culture string that will be appended to the existing search
paths when looking for localization supplemental schemas.

Parameter ``culture``:
    string in format cu-CU or just cu)doc";

static const char * __doc_Bentley_ECObjects_ECSchemaReadContext_AddSchemaPath = R"doc(Adds a file path that should be used to search for a matching schema
name

Parameter ``path``:
    Path to the directory where schemas can be found)doc";

static const char * __doc_Bentley_ECObjects_ECSchemaReadContext_RemoveSchemaLocater = R"doc(Removes a schema locater from the current context

Parameter ``locater``:
    Locater to remove from the current context)doc";

static const char * __doc_Bentley_ECObjects_ECSchemaReadContext_AddSchemaLocater = R"doc(Adds a schema locater to the current context

Parameter ``locater``:
    Locater to add to the current context

Parameter ``priority``:
    The priority this locater has when ordering all locaters for
    locating a schema)doc";

static const char * __doc_Bentley_ECObjects_ECSchemaReadContext_CreateContext = R"doc(Creates a context for deserializing ECSchemas

Parameter ``standaloneEnablerLocater``:
    Used to find enablers for instantiating instances of
    ECCustomAttributes used in the read ECSchema

Parameter ``acceptLegacyImperfectLatestCompatibleMatch``:
    If true, LatestCompatible only checks that the major version
    matches. A warning will be logged if minor version is too low, but
    the ECSchema will be accepted

Remark:
    s This more-flexible override is primarily for internal use)doc";

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_ECContext(py::module_& m)
    {
    //===================================================================================
    // struct ECSchemaReadContext
    py::class_< ECSchemaReadContext, ECSchemaReadContextPtr> c1(m, "ECSchemaReadContext");

    if (true)
        {
        //===================================================================================
        // enum PriorityPartiion
        py::enum_< ECSchemaReadContext::PriorityPartiion>(c1, "PriorityPartiion", py::arithmetic())
            .value("eReaderContext", ECSchemaReadContext::ReaderContext)
            .value("eUserSpace", ECSchemaReadContext::UserSpace)
            .value("eExternal", ECSchemaReadContext::External)
            .value("eStandardPaths", ECSchemaReadContext::StandardPaths)
            .value("eFinal", ECSchemaReadContext::Final)
            .export_values();

        }


    c1.def_static("CreateContext",
                  py::overload_cast<IStandaloneEnablerLocaterP, bool>(&ECSchemaReadContext::CreateContext),
                  "standaloneEnablerLocator"_a, "acceptLegacyImperfectLatestCompatibleMatch"_a = false, DOC(Bentley, ECObjects, ECSchemaReadContext, CreateContext));

    c1.def_static("CreateContext",
                  py::overload_cast<bool>(&ECSchemaReadContext::CreateContext),
                  "acceptLegacyImperfectLatestCompatibleMatch"_a = false, DOC(Bentley, ECObjects, ECSchemaReadContext, CreateContext));

    c1.def("AddSchemaLocater", &ECSchemaReadContext::AddSchemaLocater, "locator"_a, "priority"_a = 0, py::keep_alive<1, 2>(), DOC(Bentley, ECObjects, ECSchemaReadContext, AddSchemaLocater));
    c1.def("RemoveSchemaLocater", &ECSchemaReadContext::RemoveSchemaLocater, "locator"_a, DOC(Bentley, ECObjects, ECSchemaReadContext, RemoveSchemaLocater));
    c1.def("AddSchemaPath", &ECSchemaReadContext::AddSchemaPath, "path"_a, DOC(Bentley, ECObjects, ECSchemaReadContext, AddSchemaPath));
    c1.def("AddCulture", &ECSchemaReadContext::AddCulture, "culture"_a, DOC(Bentley, ECObjects, ECSchemaReadContext, AddCulture));
    
    c1.def_property_readonly("Cultures", &ECSchemaReadContext::GetCultures);
    c1.def("GetCultures", &ECSchemaReadContext::GetCultures, py::return_value_policy::reference_internal, DOC(Bentley, ECObjects, ECSchemaReadContext, GetCultures));
    
    c1.def("SetFinalSchemaLocater", &ECSchemaReadContext::SetFinalSchemaLocater, "locator"_a, py::keep_alive<1, 2>(), DOC(Bentley, ECObjects, ECSchemaReadContext, SetFinalSchemaLocater));
    c1.def("LocateSchema", py::overload_cast<SchemaKeyR, SchemaMatchType>(&ECSchemaReadContext::LocateSchema), "key"_a, "matchType"_a, DOC(Bentley, ECObjects, ECSchemaReadContext, LocateSchema));
    
    c1.def_property_readonly("Cache", &ECSchemaReadContext::GetCache);
    c1.def("GetCache", &ECSchemaReadContext::GetCache, py::return_value_policy::reference_internal, DOC(Bentley, ECObjects, ECSchemaReadContext, GetCache));

    //===================================================================================
    // struct ECInstanceReadContext
    py::class_< ECInstanceReadContext, ECInstanceReadContextPtr> c2(m, "ECInstanceReadContext");

    if (true)
        {
        //===================================================================================
        // struct IPrimitiveTypeResolver
        py::class_<ECInstanceReadContext::IPrimitiveTypeResolver, std::unique_ptr< ECInstanceReadContext::IPrimitiveTypeResolver, py::nodelete> > c3(m, "IPrimitiveTypeResolver");
        }


    c2.def_static("CreateContext", [] (ECSchemaCR schema, IStandaloneEnablerLocaterP locator, ECInstanceReadContext::IPrimitiveTypeResolver const* typeResolver)
                  {
                  return ECInstanceReadContext::CreateContext(schema, locator, typeResolver);
                  }, "ecSchema"_a, "locator"_a = nullptr, "typeResolver"_a = nullptr, py::keep_alive<1, 3>(), DOC(Bentley, ECObjects, ECInstanceReadContext, CreateContext));

    c2.def_static("CreateContext", [] (ECSchemaReadContextR context, ECSchemaCR fallBackSchema)
                  {
                  ECSchemaPtr foundSchema;
                  auto retVal = ECInstanceReadContext::CreateContext(context, fallBackSchema, &foundSchema);
                  return py::make_tuple(retVal, foundSchema);
                  }, "readContext"_a, "fallbackSchema"_a, DOC(Bentley, ECObjects, ECInstanceReadContext, CreateContext));
    }