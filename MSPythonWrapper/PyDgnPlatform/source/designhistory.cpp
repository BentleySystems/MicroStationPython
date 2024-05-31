/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnPlatform\source\designhistory.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <DgnPlatform/DesignHistory.h>

using namespace DgnHistory;


//=======================================================================================
// Trampoline class for NopElementQueryResultFilter.
// @bsiclass                                                                          11/2023
//=======================================================================================
template <class QueryResultFilterBase = NopElementQueryResultFilter>
class PyElementQueryResultFilter : public QueryResultFilterBase
{
public:
    using QueryResultFilterBase::QueryResultFilterBase;

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       11/2023
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual bool AcceptElementQueryResult(ElementQueryResult const& result) override
    {
        PYBIND11_OVERRIDE_EXR(bool, QueryResultFilterBase, AcceptElementQueryResult, true, result);
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       11/2023
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual bool AnyClientSideFilter() const override
    {
        PYBIND11_OVERRIDE_EXR(bool, QueryResultFilterBase, AnyClientSideFilter, false,);
    }
};


/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       11/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_DesignHistory(py::module_& m)
{
    //===================================================================================
    // class FarElementID
    py::class_< FarElementID> c1(m, "FarElementID");

    c1.def(py::init<>());
    c1.def(py::init<ModelId, ElementId>());
    c1.def(py::self < py::self);
    c1.def(py::self == py::self);

    //===================================================================================
    // class RevisionNumbersForFile
    py::class_< RevisionNumbersForFile> c2(m, "RevisionNumbersForFile");

    c2.def(py::init<>());
    c2.def(py::self == py::self);
    c2.def("AddRevisionNumberForQuery", &RevisionNumbersForFile::AddRevisionNumberForQuery, "r"_a);
    c2.def("GetDgnFile", &RevisionNumbersForFile::GetDgnFileP);
    c2.def("GetRevisions", &RevisionNumbersForFile::GetRevisions, py::return_value_policy::reference_internal);

    //===================================================================================
    // class ElementQueryResult
    py::class_< ElementQueryResult > c3(m, "ElementQueryResult");
    c3.def("GetElemHandle", &ElementQueryResult::GetElemHandle);
    c3.def("GetModelId", &ElementQueryResult::GetModelId);
    c3.def("GetDgnFile", &ElementQueryResult::GetDgnFileP);

    c3.def("GetChangeType", &ElementQueryResult::GetChangeType);
    c3.def("IsPreChangeVersion", &ElementQueryResult::IsPreChangeVersion);
    c3.def("GetResultsForModel", &ElementQueryResult::GetResultsForModel);

    //===================================================================================
    // struct NopElementQueryResultFilter
    py::class_< NopElementQueryResultFilter, PyElementQueryResultFilter<NopElementQueryResultFilter> > c4(m, "NopElementQueryResultFilter");

    c4.def(py::init<>());
    c4.def("AcceptElementQueryResult", &NopElementQueryResultFilter::AcceptElementQueryResult, "result"_a);
    c4.def("AnyClientSideFilter", &NopElementQueryResultFilter::AnyClientSideFilter);

    //===================================================================================
    // struct ElementQueryResultFilterPipeline
    py::class_< ElementQueryResultFilterPipeline, PyElementQueryResultFilter<ElementQueryResultFilterPipeline> > c5(m, "ElementQueryResultFilterPipeline");

    c5.def(py::init<IElementQueryResultFilter&, IElementQueryResultFilter&>());
    c5.def("AcceptElementQueryResult", &ElementQueryResultFilterPipeline::AcceptElementQueryResult, "result"_a);
    c5.def("AnyClientSideFilter", &ElementQueryResultFilterPipeline::AnyClientSideFilter);

    //===================================================================================
    // class ElementQueryResultsForModel
    py::class_< ElementQueryResultsForModel> c6(m, "ElementQueryResultsForModel");

    c6.def("__iter__", [](ElementQueryResultsForModel& self) { return py::make_iterator(self.begin(), self.end()); });
    c6.def("GetElement", &ElementQueryResultsForModel::GetElement, "ElementId"_a);
    c6.def("GetModelId", &ElementQueryResultsForModel::GetModelId);
    c6.def("GetDgnModel", &ElementQueryResultsForModel::GetDgnModelP);
    c6.def("GetDgnFile", &ElementQueryResultsForModel::GetDgnFileP);
    c6.def("GetResultsForFile", &ElementQueryResultsForModel::GetResultsForFile);

    //===================================================================================
    // class ElementQueryResultsForModel
    py::class_< ElementQueryResultsForFile, RefCountedPtr<ElementQueryResultsForFile> > c7(m, "ElementQueryResultsForFile");

    c7.def("__iter__", [](ElementQueryResultsForFile& self) { return py::make_iterator(self.begin(), self.end()); });
    c7.def("GetDgnFile", &ElementQueryResultsForFile::GetDgnFileP);
    c7.def("FindModelById", &ElementQueryResultsForFile::FindModelById, "modelId"_a);
    c7.def("GetResultsForModel", &ElementQueryResultsForFile::GetResultsForModel, "modelId"_a);
    c7.def("GetChangeType", &ElementQueryResultsForFile::GetChangeType, "modelId"_a, "elementId"_a);
    c7.def("GetElement", &ElementQueryResultsForFile::GetElement, "modelId"_a, "elementId"_a);
    c7.def("GetElemHandle", &ElementQueryResultsForFile::GetElemHandle, "modelId"_a, "elementId"_a);
    c7.def("ComputeElementCount", &ElementQueryResultsForFile::ComputeElementCount);

    //===================================================================================
    // class ElementsAsOfQuery
    py::class_< ElementsAsOfQuery, ElementQueryResultsForFile, RefCountedPtr<ElementsAsOfQuery> >(m, "ElementsAsOfQuery");

    //===================================================================================
    // class DesignHistory
    py::class_< DesignHistory> c8(m, "DesignHistory");

    c8.def(py::init<>());
    c8.def(py::init<DgnFileR>());
    c8.def("GetDgnFile", &DesignHistory::GetDgnFileP);

    c8.def_static("ContainsHistory", &DesignHistory::ContainsHistory, "file"_a);
    c8.def_static("InitializeHistory", &DesignHistory::InitializeHistory, "file"_a, "comment"_a);
    c8.def_static("RemoveHistory", &DesignHistory::RemoveHistory, "file"_a);

    c8.def("CombineRevisions", &DesignHistory::CombineRevisions, "start"_a, "end"_a, "parms"_a);
    c8.def("DeleteEarlyRevisions", &DesignHistory::DeleteEarlyRevisions, "tooOld"_a);
    c8.def("UpdateRevision", &DesignHistory::UpdateRevision, "revNo"_a, "user"_a, "desc"_a);

    c8.def("GetTip", &DesignHistory::GetTip);
    c8.def("GetNextPossibleRevisionNumber", &DesignHistory::GetNextPossibleRevisionNumber, "r"_a);
    c8.def("GetEarliest", &DesignHistory::GetEarliest);

    //===================================================================================
    // class DesignHistory::TagDefinition
    py::class_< DesignHistory::TagDefinition > c8_1(c8, "TagDefinition");
    c8_1.def_readwrite("tag", &DesignHistory::TagDefinition::tag);
    c8_1.def_readwrite("revNo", &DesignHistory::TagDefinition::revNo);

    c8.def("GetRevisionNumbers", [](DesignHistory& self, RevisionNumbersForFile& revNos, 
                                    RevisionNumber const& startRevNo = RevisionNumber(), 
                                    RevisionNumber const& endRevNo = RevisionNumber()) 
                                    {return self.GetRevisionNumbers (revNos, startRevNo, endRevNo); }, "revNos"_a, "startRevNo"_a, "endRevNo"_a);

    //ElementChangeRecordFilter not published
    //c8.def("GetRevisions", &DesignHistory::GetRevisions, "revs"_a, "nums"_a, "ssfilter"_a = NULL, "removeRejectedRevisions"_a = false);
 
    c8.def("GetTags", &DesignHistory::GetTags, "tags"_a);
    c8.def("GetTag", [](DesignHistory& self, WChar const* tag)
                        {
                        DgnHistory::RevisionNumber revNo;
                        StatusInt ret = self.GetTag (&revNo, tag);
                        return py::make_tuple(ret, revNo);
                        }, "tag"_a);

    c8.def("SetTag", &DesignHistory::SetTag, "tag"_a, "revNo"_a, "replaceExisting"_a);
    c8.def("RemoveTag", &DesignHistory::RemoveTag, "tag"_a);
    c8.def("QueryPreChangeState", py::overload_cast<RevisionNumbersForFile const&>(&DesignHistory::QueryPreChangeState), "range"_a);
    c8.def("QueryPostChangeState", py::overload_cast<RevisionNumbersForFile const&>(&DesignHistory::QueryPostChangeState), "range"_a);
    c8.def("QueryElementAsOf", &DesignHistory::QueryElementAsOf, "historicalVersion"_a, "modelId"_a, "elementId"_a, "rev"_a);
    c8.def("CheckUncommittedChanges", &DesignHistory::CheckUncommittedChanges, "force"_a = false);

    c8.def("Commit", &DesignHistory::Commit, "result"_a, "parms"_a, "ignoreVersion"_a = false);

    c8.def("GetRevisionNumberFormat", &DesignHistory::GetRevisionNumberFormat);
    c8.def("SetRevisionNumberFormat", &DesignHistory::SetRevisionNumberFormat, "buf"_a);

    c8.def("FormatRevisionNumber", py::overload_cast<DgnHistory::RevisionNumber const&>(&DesignHistory::FormatRevisionNumber), "revNo"_a);
    c8.def_static("FormatRevisionNumberS", py::overload_cast<DgnHistory::RevisionNumber const&, WChar const*>(&DesignHistory::FormatRevisionNumber), "revNo"_a, "fmt"_a);

    c8.def("ParseRevisionNumber", &DesignHistory::ParseRevisionNumber, "str"_a, "fmt"_a = NULL);

    c8.def_static("ExtractModelElementInfo", &DesignHistory::ExtractModelElementInfo, "pInfo"_a, "modelElement"_a, "dgnFile"_a);

    c8.def("CheckFormatVersion", &DesignHistory::CheckFormatVersion, "prompt"_a);
    c8.def_static("GetLastError", &DesignHistory::GetLastError, "details"_a);


    //===================================================================================
    // enum class HistoryCapabilities
    py::enum_< HistoryCapabilities>(m, "HistoryCapabilities")
        .value("eHistoryCapabilities_Supported", HistoryCapabilities::HistoryCapabilities_Supported)
        .value("eHistoryCapabilities_Create", HistoryCapabilities::HistoryCapabilities_Create)
        .value("eHistoryCapabilities_Combine", HistoryCapabilities::HistoryCapabilities_Combine)
        .value("eHistoryCapabilities_Commit", HistoryCapabilities::HistoryCapabilities_Commit)
        .value("eHistoryCapabilities_Browse", HistoryCapabilities::HistoryCapabilities_Browse)
        .value("eHistoryCapabilities_Delete", HistoryCapabilities::HistoryCapabilities_Delete)
        .value("eHistoryCapabilities_Retire", HistoryCapabilities::HistoryCapabilities_Retire)
        .value("eHistoryCapabilities_Trace", HistoryCapabilities::HistoryCapabilities_Trace)
        .value("eHistoryCapabilities_Tag", HistoryCapabilities::HistoryCapabilities_Tag)
        .value("eHistoryCapabilities_ChangeDesc", HistoryCapabilities::HistoryCapabilities_ChangeDesc)
        .value("eHistoryCapabilities_AutoUpgrade", HistoryCapabilities::HistoryCapabilities_AutoUpgrade)
        .value("eHistoryCapabilities_ChangeAuthor", HistoryCapabilities::HistoryCapabilities_ChangeAuthor)
        .value("eHistoryCapabilities_SetRevisionFormat", HistoryCapabilities::HistoryCapabilities_SetRevisionFormat)
        .value("eHistoryCapabilities_SetVersion", HistoryCapabilities::HistoryCapabilities_SetVersion)
        .value("eHistoryCapabilities_ALL", HistoryCapabilities::HistoryCapabilities_ALL)
        .export_values();
}
