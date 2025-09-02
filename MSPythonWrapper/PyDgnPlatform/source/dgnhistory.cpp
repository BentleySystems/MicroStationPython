/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnPlatform\source\dgnhistory.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <DgnPlatform/DgnFileIO/DgnHistory.h>



static const char * __doc_Bentley_DgnPlatform_AuditTrailRecord_GetType =R"doc(Geth the type of change)doc";

static const char * __doc_Bentley_DgnPlatform_AuditTrailRecord_GetEndRevisionNumber =R"doc(Get the end of the range of revisions that were affected by the change)doc";

static const char * __doc_Bentley_DgnPlatform_AuditTrailRecord_GetStartRevisionNumber =R"doc(Get the start of the range of revisions that were affected by the
change)doc";

static const char * __doc_Bentley_DgnPlatform_AuditTrailRecord_GetTime =R"doc(Get the time of the change)doc";

static const char * __doc_Bentley_DgnPlatform_AuditTrailRecord_GetDescription =R"doc(Get the description of the change)doc";

static const char * __doc_Bentley_DgnPlatform_AuditTrailRecord_GetUser =R"doc(Get the name of the user who made the change)doc";

static const char * __doc_Bentley_DgnPlatform_RevisionInfo_GetRevisionNumber =R"doc(Get the RevisionNumber of this revision)doc";

static const char * __doc_Bentley_DgnPlatform_RevisionInfo_GetTime =R"doc(Get the time of day on the user's machine when the revision was
created.)doc";

static const char * __doc_Bentley_DgnPlatform_RevisionInfo_GetDescription =R"doc(Get the description of the changes as supplied by the user who
committed the change)doc";

static const char * __doc_Bentley_DgnPlatform_RevisionInfo_GetUser =R"doc(Get the name of the user who committed the changes that created this
revision)doc";

static const char * __doc_Bentley_DgnPlatform_CommitInfo_IsValid =R"doc(Check if commit parms is in a valid state)doc";

static const char * __doc_Bentley_DgnPlatform_CommitInfo_SetUserName =R"doc(Set the user name)doc";

static const char * __doc_Bentley_DgnPlatform_RevisionNumber_Parse =R"doc(Construct a revision number from a string entered according to the
default n.m format

:param str:
    (input) the string to parse

See also:
    FormatCustom)doc";

static const char * __doc_Bentley_DgnPlatform_RevisionNumber_ParseCustom =R"doc(Construct a revision number from a string entered according to a
custom format

:param fmt:
    (input) the custom format specifier

:param str:
    (input) the string to parse

See also:
    FormatCustom)doc";

static const char * __doc_Bentley_DgnPlatform_RevisionNumber_FormatCustom =R"doc(Format a history revision number according to the specified format

:param fmt:
    The format specifier.

:returns:
    formatted string

See also:
    Format, ParseCustom Bentley Systems +---------------+-------------
    --+---------------+---------------+---------------+------

:param fmt:
    (input) the custom format specifier)doc";

static const char * __doc_Bentley_DgnPlatform_RevisionNumber_Format =R"doc(Format a history revision number using the default n.m format.

:returns:
    formatted string

See also:
    FormatCustom Bentley Systems +---------------+---------------+----
    -----------+---------------+---------------+------)doc";

static const char * __doc_Bentley_DgnPlatform_RevisionNumber_IsValid =R"doc(Query if this is a valid revision number)doc";

static const char * __doc_Bentley_DgnPlatform_RevisionNumber_IsRecent =R"doc(Query if this represents " recent changes ". @See Recent)doc";

static const char * __doc_Bentley_DgnPlatform_RevisionNumber_Recent =R"doc(Get the special RevisionNumber that indicates " recent changes ". @See
IsRecent)doc";

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_DgnHistory(py::module_& m)
    {
    using namespace DgnPlatform::DgnHistory;

    //===================================================================================
    // class RevisionNumber
    py::class_< RevisionNumber> c1(m, "DgnHistory");
    py::bind_vector<bvector< RevisionNumber>>(m, "RevisionNumberArray", py::module_local(false));

    c1.def(py::init<>());
    c1.def(py::self < py::self);
    c1.def(py::self <= py::self);
    c1.def(py::self > py::self);
    c1.def(py::self >= py::self);
    c1.def(py::self == py::self);
    c1.def(py::self != py::self);
    c1.def_static("Recent", &RevisionNumber::Recent, DOC(Bentley, DgnPlatform, RevisionNumber, Recent));
    c1.def("IsRecent", &RevisionNumber::IsRecent, DOC(Bentley, DgnPlatform, RevisionNumber, IsRecent));
    c1.def("IsValid", &RevisionNumber::IsValid, DOC(Bentley, DgnPlatform, RevisionNumber, IsValid));
    c1.def("Format", &RevisionNumber::Format, DOC(Bentley, DgnPlatform, RevisionNumber, Format));
    c1.def("FormatCustom", &RevisionNumber::FormatCustom, "fmt"_a, DOC(Bentley, DgnPlatform, RevisionNumber, FormatCustom));
    c1.def_static("ParseCustom", &RevisionNumber::ParseCustom, "fmt"_a, "str"_a, DOC(Bentley, DgnPlatform, RevisionNumber, ParseCustom));
    c1.def_static("Parse", &RevisionNumber::Parse, "str"_a, DOC(Bentley, DgnPlatform, RevisionNumber, Parse));

    //===================================================================================
    // class CommitInfo
    py::class_< CommitInfo> c2(m, "CommitInfo");

    c2.def(py::init<WStringCR>(), "desc"_a);
    c2.def("SetUserName", &CommitInfo::SetUserName, "userName"_a, DOC(Bentley, DgnPlatform, CommitInfo, SetUserName));
    c2.def("IsValid", &CommitInfo::IsValid, DOC(Bentley, DgnPlatform, CommitInfo, IsValid));

    //===================================================================================
    // class RevisionInfo
    py::class_< RevisionInfo> c3(m, "RevisionInfo");

    c3.def(py::init<>());
    c3.def_property_readonly("User", &RevisionInfo::GetUser);
    c3.def("GetUser", &RevisionInfo::GetUser, DOC(Bentley, DgnPlatform, RevisionInfo, GetUser));
    
    c3.def_property_readonly("Description", &RevisionInfo::GetDescription);
    c3.def("GetDescription", &RevisionInfo::GetDescription, DOC(Bentley, DgnPlatform, RevisionInfo, GetDescription));
    
    c3.def_property_readonly("Time", &RevisionInfo::GetTime);
    c3.def("GetTime", &RevisionInfo::GetTime, DOC(Bentley, DgnPlatform, RevisionInfo, GetTime));
    
    c3.def_property_readonly("RevisionNumber", &RevisionInfo::GetRevisionNumber);
    c3.def("GetRevisionNumber", &RevisionInfo::GetRevisionNumber, DOC(Bentley, DgnPlatform, RevisionInfo, GetRevisionNumber));

    //===================================================================================
    // enum AuditTrailRecordType
    py::enum_< AuditTrailRecordType>(m, "AuditTrailRecordType", py::arithmetic())
        .value("eAUDIT_TRAIL_RECORD_TYPE_CombineRevisions", AUDIT_TRAIL_RECORD_TYPE_CombineRevisions)
        .value("eAUDIT_TRAIL_RECORD_TYPE_RetireRevisions", AUDIT_TRAIL_RECORD_TYPE_RetireRevisions)
        .value("eAUDIT_TRAIL_RECORD_TYPE_ChangeDescription", AUDIT_TRAIL_RECORD_TYPE_ChangeDescription)
        .value("eAUDIT_TRAIL_RECORD_TYPE_ChangeUser", AUDIT_TRAIL_RECORD_TYPE_ChangeUser)
        .value("eAUDIT_TRAIL_RECORD_TYPE_MakeShared", AUDIT_TRAIL_RECORD_TYPE_MakeShared)
        .value("eAUDIT_TRAIL_RECORD_TYPE_Create", AUDIT_TRAIL_RECORD_TYPE_Create)
        .export_values();

    //===================================================================================
    // class AuditTrailRecord
    py::class_< AuditTrailRecord, std::unique_ptr<AuditTrailRecord, py::nodelete> > c4(m, "AuditTrailRecord");

    c4.def_property_readonly("User", &AuditTrailRecord::GetUser);
    c4.def("GetUser", &AuditTrailRecord::GetUser, DOC(Bentley, DgnPlatform, AuditTrailRecord, GetUser));
    
    c4.def_property_readonly("Description", &AuditTrailRecord::GetDescription);
    c4.def("GetDescription", &AuditTrailRecord::GetDescription, DOC(Bentley, DgnPlatform, AuditTrailRecord, GetDescription));
    
    c4.def_property_readonly("Time", &AuditTrailRecord::GetTime);
    c4.def("GetTime", &AuditTrailRecord::GetTime, DOC(Bentley, DgnPlatform, AuditTrailRecord, GetTime));
    
    c4.def_property_readonly("StartRevisionNumber", &AuditTrailRecord::GetStartRevisionNumber);
    c4.def("GetStartRevisionNumber", &AuditTrailRecord::GetStartRevisionNumber, DOC(Bentley, DgnPlatform, AuditTrailRecord, GetStartRevisionNumber));
    
    c4.def_property_readonly("EndRevisionNumber", &AuditTrailRecord::GetEndRevisionNumber);
    c4.def("GetEndRevisionNumber", &AuditTrailRecord::GetEndRevisionNumber, DOC(Bentley, DgnPlatform, AuditTrailRecord, GetEndRevisionNumber));
    
    c4.def_property_readonly("Type", &AuditTrailRecord::GetType);
    c4.def("GetType", &AuditTrailRecord::GetType, DOC(Bentley, DgnPlatform, AuditTrailRecord, GetType));

    //===================================================================================
    // class ElementChangeFlags
    py::class_< ElementChangeFlags> c5(m, "ElementChangeFlags");

    c5.def(py::init<>());
    c5.def(py::self == py::self);

    c5.def_property("ChangeType", &ElementChangeFlags::GetChangeType, &ElementChangeFlags::SetChangeType);
    c5.def("GetChangeType", &ElementChangeFlags::GetChangeType);
    c5.def("SetChangeType", &ElementChangeFlags::SetChangeType, "newType"_a);

    //===================================================================================
    // struct ElementChangeRecord
    py::class_< ElementChangeRecord, ElementChangeFlags> c6(m, "ElementChangeRecord");

    c6.def(py::init<>());
    c6.def(py::init<ElementId, ElementChangeFlags>(), "elemId"_a, "flags"_a);
    c6.def(py::init<ElementChangeType, ElementId>(), "changeType"_a, "elemId"_a);

    c6.def_property_readonly("ElementId", &ElementChangeRecord::GetElementId);    
    c6.def("GetElementId", &ElementChangeRecord::GetElementId);    
    }