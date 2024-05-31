/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnPlatform\source\itextedit.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <DgnPlatform/ITextEdit.h>



static const char * __doc_Bentley_DgnPlatform_ITextEditRestrictions_SetPreventStyleNone =R"doc(See also:
    ShouldAllowStyleNone)doc";

static const char * __doc_Bentley_DgnPlatform_ITextEditRestrictions_GetPreventStyleNone =R"doc(Determines whether to prevent Style (None) from being selected in the
style picker. @note Default = false)doc";

static const char * __doc_Bentley_DgnPlatform_ITextQueryOptions_SetShouldRequireFieldSupport =R"doc(Sets whether to restrict to text parts that can support fields.

See also:
    ShouldRequireFieldSupport)doc";

static const char * __doc_Bentley_DgnPlatform_ITextQueryOptions_ShouldRequireFieldSupport =R"doc(By default, all text parts will be returned, regardless of their field
support; this will restrict to ITextPartId objects that represent only
parts that can technically support fields. This does NOT mean that the
returned text parts actually contain fields; merely that they
potential support fields.)doc";

static const char * __doc_Bentley_DgnPlatform_ITextQueryOptions_SetShouldIncludeEmptyParts =R"doc(Sets whether to allow empty text parts.

See also:
    ShouldIncludeEmptyParts)doc";

static const char * __doc_Bentley_DgnPlatform_ITextQueryOptions_ShouldIncludeEmptyParts =R"doc(By default, empty pieces of text are not returned; this will force
ITextPartId objects to be created for them (may result in NULL
TextBlock objects when the text part is requested).)doc";

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_ITextEdit(py::module_& m)
    {
    //===================================================================================
    // struct ITextPartId
    py::class_< ITextPartId, ITextPartIdPtr> c1(m, "ITextPartId");

    //===================================================================================
    // struct ITextQueryOptions
    py::class_< ITextQueryOptions, ITextQueryOptionsPtr> c2(m, "ITextQueryOptions", py::multiple_inheritance());

    c2.def("ShouldIncludeEmptyParts", &ITextQueryOptions::ShouldIncludeEmptyParts, DOC(Bentley, DgnPlatform, ITextQueryOptions, ShouldIncludeEmptyParts));
    c2.def("SetShouldIncludeEmptyParts", &ITextQueryOptions::SetShouldIncludeEmptyParts, "value"_a, DOC(Bentley, DgnPlatform, ITextQueryOptions, SetShouldIncludeEmptyParts));
    
    c2.def("ShouldRequireFieldSupport", &ITextQueryOptions::ShouldRequireFieldSupport, DOC(Bentley, DgnPlatform, ITextQueryOptions, ShouldRequireFieldSupport));
    c2.def("SetShouldRequireFieldSupport", &ITextQueryOptions::SetShouldRequireFieldSupport, "value"_a, DOC(Bentley, DgnPlatform, ITextQueryOptions, SetShouldRequireFieldSupport));

    c2.def(py::init(&ITextQueryOptions::CreateDefault));

    //===================================================================================
    // struct ITextQuery
    py::class_< ITextQuery, std::unique_ptr< ITextQuery, py::nodelete> > c3(m, "ITextQuery");
    py::bind_vector<TextPartIdVector>(m, "TextPartIdVector", py::module_local(false));

    c3.def("IsTextElement", &ITextQuery::IsTextElement, "eh"_a);
    c3.def("DoesSupportFields", &ITextQuery::DoesSupportFields, "eh"_a);
    c3.def("GetTextPartId", &ITextQuery::GetTextPartId, "eh"_a, "path"_a);
    c3.def("GetTextPartIds", &ITextQuery::GetTextPartIds, "eh"_a, "options"_a, "partIds"_a);
    c3.def("GetTextPart", &ITextQuery::GetTextPart, "eh"_a, "partId"_a);

    //===================================================================================
    // struct ITextEditRestrictions
    py::class_< ITextEditRestrictions, ITextEditRestrictionsPtr> c4(m, "ITextEditRestrictions", py::multiple_inheritance());

    c4.def_property("PreventStyleNone", &ITextEditRestrictions::GetPreventStyleNone, &ITextEditRestrictions::SetPreventStyleNone);
    c4.def("GetPreventStyleNone", &ITextEditRestrictions::GetPreventStyleNone, DOC(Bentley, DgnPlatform, ITextEditRestrictions, GetPreventStyleNone));
    c4.def("SetPreventStyleNone", &ITextEditRestrictions::SetPreventStyleNone, "value"_a, DOC(Bentley, DgnPlatform, ITextEditRestrictions, SetPreventStyleNone));

    c4.def(py::init(&ITextEditRestrictions::CreateDefault));

    //===================================================================================
    // struct ITextEdit
    py::class_< ITextEdit, std::unique_ptr< ITextEdit, py::nodelete>, ITextQuery> c5(m, "ITextEdit");

    if (true)
        {
        //===================================================================================
        // enum ReplaceStatus
        py::enum_< ITextEdit::ReplaceStatus>(c5, "ReplaceStatus", py::arithmetic())
            .value("eReplaceStatus_Success", ITextEdit::ReplaceStatus_Success)
            .value("eReplaceStatus_Error", ITextEdit::ReplaceStatus_Error)
            .value("eReplaceStatus_Delete", ITextEdit::ReplaceStatus_Delete)
            .export_values();
        }

    c5.def("GetTextPartEditRestrictions", &ITextEdit::GetTextPartEditRestrictions, "eh"_a, "partId"_a);
    c5.def("ReplaceTextPart", &ITextEdit::ReplaceTextPart, "eh"_a, "partId"_a, "textBlock"_a);
    }