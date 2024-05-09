/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnPlatform\source\workset.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <DgnPlatform/WorkSet.h>



static const char * __doc_Bentley_DgnPlatform_DgnWorkSetComparer_GetSecondWorkSet =R"doc(Gets the second WorkSet to compare)doc";

static const char * __doc_Bentley_DgnPlatform_DgnWorkSetComparer_GetFirstWorkSet =R"doc(Gets the first WorkSet to compare)doc";

static const char * __doc_Bentley_DgnPlatform_DgnWorkSetComparer_Compare =R"doc(Compares two WorkSet info data and return ComparisonStatus)doc";

static const char * __doc_Bentley_DgnPlatform_DgnWorkSetComparer_SetOption =R"doc(Sets the comparison option. See ComparisonOption.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnWorkSetComparer_SetSecondFile =R"doc(Sets the second dgnfile to extract WorkSet info from, for comparison.
Returns false if WorkSet information is missing.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnWorkSetComparer_SetFirstFile =R"doc(Sets the first dgnfile to extract WorkSet info from, for comparison.
Returns false if WorkSet information is missing.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnWorkSetComparer_SetSecondWorkSet =R"doc(Sets the second WorkSet to compare)doc";

static const char * __doc_Bentley_DgnPlatform_DgnWorkSetComparer_SetFirstWorkSet =R"doc(Sets the first WorkSet to compare)doc";

static const char * __doc_Bentley_DgnPlatform_IDgnWorkSetInfo_Remove =R"doc(Remove the workset properties on the given file (which can be a .dgn
file or a .dgnws file))doc";

static const char * __doc_Bentley_DgnPlatform_IDgnWorkSetInfo_GetNoWorkSetName =R"doc(Get the muti-language string " No WorkSet ")doc";

static const char * __doc_Bentley_DgnPlatform_IDgnWorkSetInfo_DropListener =R"doc(Deregister the listener)doc";

static const char * __doc_Bentley_DgnPlatform_IDgnWorkSetInfo_AddListener =R"doc(Register a listener to be notified of WorkSet-related events)doc";

static const char * __doc_Bentley_DgnPlatform_IDgnWorkSetInfo_ExtractFromDgnFile =R"doc(Extracts WorkSet information from the given file (which can be a .dgn
file or a .dgnws file))doc";

static const char * __doc_Bentley_DgnPlatform_IDgnWorkSetInfo_ExistsOnDgnFile =R"doc(Checks if the given dgnfile contains WorkSet information)doc";

static const char * __doc_Bentley_DgnPlatform_IDgnWorkSetInfo_Clone =R"doc(Makes a copy of the WorkSetInfo)doc";

static const char * __doc_Bentley_DgnPlatform_IDgnWorkSetInfo_Write =R"doc(Stores the WorkSet properties on the given file (which can be a .dgn
file or a .dgnws file))doc";

static const char * __doc_Bentley_DgnPlatform_IDgnWorkSetInfo_IsSameWorkSet =R"doc(Checks of two WorkSets match by comparing their WorkSet name and
connect GUID.)doc";

static const char * __doc_Bentley_DgnPlatform_IDgnWorkSetInfo_GetProperty =R"doc(Gets a custom property)doc";

static const char * __doc_Bentley_DgnPlatform_IDgnWorkSetInfo_RemoveProperty =R"doc(Deletes a custom property)doc";

static const char * __doc_Bentley_DgnPlatform_IDgnWorkSetInfo_AddProperty =R"doc(Adds a custom double property)doc";

static const char * __doc_Bentley_DgnPlatform_IDgnWorkSetInfo_SetAllPropertiesLoaded =R"doc(Set the state to indicate all properties are loaded)doc";

static const char * __doc_Bentley_DgnPlatform_IDgnWorkSetInfo_AreAllPropertiesLoaded =R"doc(Query whether all properties are loaded)doc";

static const char * __doc_Bentley_DgnPlatform_IDgnWorkSetInfo_IsAssociatedWithConnectProject =R"doc(Determines if this WorkSet is in Connect)doc";

static const char * __doc_Bentley_DgnPlatform_IDgnWorkSetInfo_SetProjectName =R"doc(Sets the Connect Project Name.)doc";

static const char * __doc_Bentley_DgnPlatform_IDgnWorkSetInfo_GetProjectName =R"doc(Gets the Connect Project Name. Returns nullptr if the WorkSet is not
in Connect)doc";

static const char * __doc_Bentley_DgnPlatform_IDgnWorkSetInfo_SetProjectNumber =R"doc(Sets the Number on Connect.)doc";

static const char * __doc_Bentley_DgnPlatform_IDgnWorkSetInfo_GetProjectNumber =R"doc(Gets the Number on Connect. Returns nullptr if the WorkSet is not in
Connect)doc";

static const char * __doc_Bentley_DgnPlatform_IDgnWorkSetInfo_SetProjectStatus =R"doc(Sets the Connect Status.)doc";

static const char * __doc_Bentley_DgnPlatform_IDgnWorkSetInfo_GetProjectStatus =R"doc(Gets the Connect Status. Returns nullptr if the WorkSet is not in
Connect)doc";

static const char * __doc_Bentley_DgnPlatform_IDgnWorkSetInfo_SetProjectLocation =R"doc(Sets the Location on Connect.)doc";

static const char * __doc_Bentley_DgnPlatform_IDgnWorkSetInfo_GetProjectLocation =R"doc(Gets the Location on Connect. Returns nullptr if the WorkSet is not in
Connect)doc";

static const char * __doc_Bentley_DgnPlatform_IDgnWorkSetInfo_SetProjectIndustry =R"doc(Sets the Industry on Connect.)doc";

static const char * __doc_Bentley_DgnPlatform_IDgnWorkSetInfo_GetProjectIndustry =R"doc(Gets the Industry on Connect. Returns nullptr if the WorkSet is not in
Connect)doc";

static const char * __doc_Bentley_DgnPlatform_IDgnWorkSetInfo_SetProjectAssetType =R"doc(Sets AssetType on Connect.)doc";

static const char * __doc_Bentley_DgnPlatform_IDgnWorkSetInfo_GetProjectAssetType =R"doc(Gets the WorkSet's AssetType on Connect. Returns nullptr if the
WorkSet is not in Connect)doc";

static const char * __doc_Bentley_DgnPlatform_IDgnWorkSetInfo_SetConnectGUID =R"doc(Sets the WorkSet's GUID on Connect)doc";

static const char * __doc_Bentley_DgnPlatform_IDgnWorkSetInfo_GetConnectGUID =R"doc(Gets the WorkSet's GUID on Connect. Returns nullptr if the WorkSet is
not in Connect The returned string is not guaranteed to contain a
valid GUID. The caller is expected to check for validity while parsing
it into a GUID object.)doc";

static const char * __doc_Bentley_DgnPlatform_IDgnWorkSetInfo_SetWorkSpaceName =R"doc(Sets the parnet WorkSpace of the WorkSet)doc";

static const char * __doc_Bentley_DgnPlatform_IDgnWorkSetInfo_GetWorkSpaceName =R"doc(Gets the parent WorkSpace of the WorkSet)doc";

static const char * __doc_Bentley_DgnPlatform_IDgnWorkSetInfo_SetDescription =R"doc(Sets the description of the WorkSet)doc";

static const char * __doc_Bentley_DgnPlatform_IDgnWorkSetInfo_GetDescription =R"doc(Gets the description of the WorkSet)doc";

static const char * __doc_Bentley_DgnPlatform_IDgnWorkSetInfo_SetName =R"doc(Sets the name of the WorkSet)doc";

static const char * __doc_Bentley_DgnPlatform_IDgnWorkSetInfo_GetName =R"doc(Gets the name of the WorkSet)doc";

static const char * __doc_Bentley_DgnPlatform_DgnWorkSet_Write =R"doc(Stores the WorkSet properties on the WorkSet's .dgnws file. returns
WorkSetStatus::Error if .dgnws file doesn't exist or failed to write.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnWorkSet_SetCfgMoniker =R"doc(Sets the path of this WorkSet's cfg file)doc";

static const char * __doc_Bentley_DgnPlatform_DgnWorkSet_GetCfgMoniker =R"doc(Gets the path of this WorkSet's cfg file)doc";

static const char * __doc_Bentley_DgnPlatform_DgnWorkSet_HasDgnwsFile =R"doc(Determines if this WorkSet consists of a .dgnws file. .dgnws file is a
container of custom properties, sheet index and other data related to
the WorkSet.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnWorkSet_HasCfgFile =R"doc(Determines if this WorkSet has a .cfg file (does not check if the file
exists) If false, it represents a new WorkSet that has not been saved.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnWorkSet_GetWorkSpace =R"doc(Gets the parent WorkSpace of this WorkSet)doc";

static const char * __doc_Bentley_DgnPlatform_DgnWorkSet_SetInfo =R"doc(Sets WorkSetInfo of this WorkSet)doc";

static const char * __doc_Bentley_DgnPlatform_DgnWorkSet_GetInfo =R"doc(Gets WorkSetInfo of this WorkSet)doc";

static const char * __doc_Bentley_DgnPlatform_DgnWorkSet_GetWorkSpaceName =R"doc(Gets the parent WorkSpace of the WorkSet)doc";

static const char * __doc_Bentley_DgnPlatform_DgnWorkSet_GetDescription =R"doc(Gets the description of the WorkSet)doc";

static const char * __doc_Bentley_DgnPlatform_DgnWorkSet_GetName =R"doc(Gets the name of the WorkSet)doc";

static const char * __doc_Bentley_DgnPlatform_DgnWorkSet_Read =R"doc(Construct a WorkSet object to represent an existing WorkSet)doc";

static const char * __doc_Bentley_DgnPlatform_DgnWorkSet_Create =R"doc(Construct a WorkSet object to represent a new WorkSet being created)doc";

static const char * __doc_Bentley_DgnPlatform_DgnWorkSpace_Read =R"doc(Construct a WorkSpace object to represent an existing WorkSpace)doc";

static const char * __doc_Bentley_DgnPlatform_DgnWorkSetEvents__OnWorkSetInfoChanged =R"doc(Notifies of change in WorkSet)doc";

//=======================================================================================
// Trampoline class for DgnWorkSetEvents.
// @bsiclass                                                                   02/23
//=======================================================================================
struct PyDgnWorkSetEvents : DgnWorkSetEvents
    {
    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       2/2023
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void _OnWorkSetInfoChanged(IDgnWorkSetInfoCP before, IDgnWorkSetInfoCP after, DgnFileR host) override
        { PYBIND11_OVERRIDE_PURE_EX(void, DgnWorkSetEvents, _OnWorkSetInfoChanged, before, after, host); }
    };

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_WorkSet(py::module_& m)
    {
    //===================================================================================
    // struct WorkSetCollection
    py::class_< WorkSetCollection> c1(m, "WorkSetCollection");

    c1.def("__iter__", [] (WorkSetCollection& self) { return py::make_iterator(self.begin(), self.end()); }, py::keep_alive<0, 1>());
    c1.def("FindByFileName", &WorkSetCollection::FindByFileName, "workSetFileName"_a, "stopHere"_a);
    c1.def("FindByName", &WorkSetCollection::FindByName, "workSetName"_a, "stopHere"_a);

    //===================================================================================
    // enum class WorkSetStatus
    py::enum_< WorkSetStatus>(m, "WorkSetStatus")
        .value("eSuccess", WorkSetStatus::Success)
        .value("eError", WorkSetStatus::Error)
        .value("eInvalidWorkSet", WorkSetStatus::InvalidWorkSet)
        .value("eNameRequired", WorkSetStatus::NameRequired)
        .value("ePropertyNotFound", WorkSetStatus::PropertyNotFound)
        .value("eFailedToWriteData", WorkSetStatus::FailedToWriteData)
        .value("eFileIsReadOnly", WorkSetStatus::FileIsReadOnly)
        .export_values();

    //===================================================================================
    // struct DgnWorkSetEvents
    py::class_< DgnWorkSetEvents, std::unique_ptr< DgnWorkSetEvents, py::nodelete>, PyDgnWorkSetEvents> c2(m, "DgnWorkSetEvents");

    c2.def(py::init<>());
    c2.def("_OnWorkSetInfoChanged", &DgnWorkSetEvents::_OnWorkSetInfoChanged, "before"_a, "after"_a, "host"_a, DOC(Bentley, DgnPlatform, DgnWorkSetEvents, _OnWorkSetInfoChanged));

    //===================================================================================
    // struct DgnWorkSpace
    py::class_< DgnWorkSpace, DgnWorkSpacePtr> c3(m, "DgnWorkSpace");

    c3.def_property_readonly("Name", &DgnWorkSpace::GetName);
    c3.def("GetName", &DgnWorkSpace::GetName, py::return_value_policy::reference_internal);

    c3.def("GetCfgMoniker", &DgnWorkSpace::GetCfgMoniker, py::return_value_policy::reference_internal);

    c3.def_property_readonly("ParentConfigurationFolder", &DgnWorkSpace::GetParentConfigurationFolder);
    c3.def("GetParentConfigurationFolder", &DgnWorkSpace::GetParentConfigurationFolder);
    
    c3.def("AddWorkSet", &DgnWorkSpace::AddWorkSet, "workSet"_a);
    
    c3.def_property_readonly("WorkSets", &DgnWorkSpace::GetWorkSets);
    c3.def("GetWorkSets", &DgnWorkSpace::GetWorkSets, py::return_value_policy::reference_internal);
    
    c3.def("GetWorkSetByName", &DgnWorkSpace::GetWorkSetByName, "workSetName"_a);
    c3.def("ClearWorkSets", &DgnWorkSpace::ClearWorkSets);

    c3.def_static("Read", 
                  py::overload_cast<DgnDocumentMonikerCR, DgnFolderMonikerCR>(&DgnWorkSpace::Read),
                  "cfgMoniker"_a, "configurationFolderRootPath"_a, DOC(Bentley, DgnPlatform, DgnWorkSpace, Read));

    //===================================================================================
    // struct DgnWorkSet
    py::class_< DgnWorkSet, DgnWorkSetPtr> c4(m, "DgnWorkSet");

    c4.def_static("Create",
                  py::overload_cast<DgnWorkSpaceR, DgnDocumentMonikerCR, DgnDocumentMonikerCR, WStringCR, WCharCP>(&DgnWorkSet::Create),
                  "workspace"_a, "cfgMoniker"_a, "dgnwsMoniker"_a, "name"_a, "descr"_a, DOC(Bentley, DgnPlatform, DgnWorkSet, Create));

    c4.def_static("Read",
                  py::overload_cast<DgnWorkSpaceR, DgnDocumentMonikerCR, DgnDocumentMonikerCR>(&DgnWorkSet::Read),
                  "workspace"_a, "cfgMoniker"_a, "dgnwsMoniker"_a, DOC(Bentley, DgnPlatform, DgnWorkSet, Read));

    c4.def_property_readonly("Name", &DgnWorkSet::GetName);
    c4.def("GetName", &DgnWorkSet::GetName, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, DgnWorkSet, GetName));
    
    c4.def_property_readonly("Description", &DgnWorkSet::GetDescription);
    c4.def("GetDescription", &DgnWorkSet::GetDescription, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, DgnWorkSet, GetDescription));
    
    c4.def_property_readonly("WorkSpaceName", &DgnWorkSet::GetWorkSpaceName);
    c4.def("GetWorkSpaceName", &DgnWorkSet::GetWorkSpaceName, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, DgnWorkSet, GetWorkSpaceName));
    
    c4.def_property("Info", &DgnWorkSet::GetInfo, &DgnWorkSet::SetInfo);
    c4.def("GetInfo", &DgnWorkSet::GetInfo, DOC(Bentley, DgnPlatform, DgnWorkSet, GetInfo));
    c4.def("SetInfo", &DgnWorkSet::SetInfo, "info"_a, DOC(Bentley, DgnPlatform, DgnWorkSet, SetInfo));
    
    c4.def_property_readonly("WorkSpace", &DgnWorkSet::GetWorkSpace);
    c4.def("GetWorkSpace", &DgnWorkSet::GetWorkSpace, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, DgnWorkSet, GetWorkSpace));
    
    c4.def("HasCfgFile", &DgnWorkSet::HasCfgFile, DOC(Bentley, DgnPlatform, DgnWorkSet, HasCfgFile));    
    c4.def("HasDgnwsFile", &DgnWorkSet::HasDgnwsFile, DOC(Bentley, DgnPlatform, DgnWorkSet, HasDgnwsFile));
    
    c4.def_property("CfgMoniker", &DgnWorkSet::GetCfgMoniker, &DgnWorkSet::SetCfgMoniker);
    c4.def("GetCfgMoniker", &DgnWorkSet::GetCfgMoniker, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, DgnWorkSet, GetCfgMoniker));
    c4.def("SetCfgMoniker", &DgnWorkSet::SetCfgMoniker, "moniker"_a, DOC(Bentley, DgnPlatform, DgnWorkSet, SetCfgMoniker));
    
    c4.def("__eq__", [] (DgnWorkSetCR self, DgnWorkSetCR other) { return self.Equals(other); });
    c4.def("Write", &DgnWorkSet::Write, DOC(Bentley, DgnPlatform, DgnWorkSet, Write));

    //===================================================================================
    // struct IDgnWorkSetInfo
    py::class_< IDgnWorkSetInfo, IDgnWorkSetInfoPtr> c5(m, "IDgnWorkSetInfo");

    c5.def_property("Name", &IDgnWorkSetInfo::GetName, &IDgnWorkSetInfo::SetName);
    c5.def("GetName", &IDgnWorkSetInfo::GetName, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, IDgnWorkSetInfo, GetName));
    c5.def("SetName", &IDgnWorkSetInfo::SetName, "name"_a, DOC(Bentley, DgnPlatform, IDgnWorkSetInfo, SetName));
    
    c5.def_property("Description", &IDgnWorkSetInfo::GetDescription, &IDgnWorkSetInfo::SetDescription);
    c5.def("GetDescription", &IDgnWorkSetInfo::GetDescription, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, IDgnWorkSetInfo, GetDescription));
    c5.def("SetDescription", &IDgnWorkSetInfo::SetDescription, "description"_a, DOC(Bentley, DgnPlatform, IDgnWorkSetInfo, SetDescription));
    
    c5.def_property("WorkSpaceName", &IDgnWorkSetInfo::GetWorkSpaceName, &IDgnWorkSetInfo::SetWorkSpaceName);
    c5.def("GetWorkSpaceName", &IDgnWorkSetInfo::GetWorkSpaceName, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, IDgnWorkSetInfo, GetWorkSpaceName));
    c5.def("SetWorkSpaceName", &IDgnWorkSetInfo::SetWorkSpaceName, "name"_a, DOC(Bentley, DgnPlatform, IDgnWorkSetInfo, SetWorkSpaceName));
    
    c5.def_property("ConnectGUID", &IDgnWorkSetInfo::GetConnectGUID, &IDgnWorkSetInfo::SetConnectGUID);
    c5.def("GetConnectGUID", &IDgnWorkSetInfo::GetConnectGUID, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, IDgnWorkSetInfo, GetConnectGUID));
    c5.def("SetConnectGUID", &IDgnWorkSetInfo::SetConnectGUID, "guid"_a, DOC(Bentley, DgnPlatform, IDgnWorkSetInfo, SetConnectGUID));
    
    c5.def_property("ProjectAssetType", &IDgnWorkSetInfo::GetProjectAssetType, &IDgnWorkSetInfo::SetProjectAssetType);
    c5.def("GetProjectAssetType", &IDgnWorkSetInfo::GetProjectAssetType, DOC(Bentley, DgnPlatform, IDgnWorkSetInfo, GetProjectAssetType));
    c5.def("SetProjectAssetType", &IDgnWorkSetInfo::SetProjectAssetType, "type"_a, DOC(Bentley, DgnPlatform, IDgnWorkSetInfo, SetProjectAssetType));
    
    c5.def_property("ProjectIndustry", &IDgnWorkSetInfo::GetProjectIndustry, &IDgnWorkSetInfo::SetProjectIndustry);
    c5.def("GetProjectIndustry", &IDgnWorkSetInfo::GetProjectIndustry, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, IDgnWorkSetInfo, GetProjectIndustry));
    c5.def("SetProjectIndustry", &IDgnWorkSetInfo::SetProjectIndustry, "industry"_a, DOC(Bentley, DgnPlatform, IDgnWorkSetInfo, SetProjectIndustry));
    
    c5.def_property("ProjectLocation", &IDgnWorkSetInfo::GetProjectLocation, &IDgnWorkSetInfo::SetProjectLocation);
    c5.def("GetProjectLocation", &IDgnWorkSetInfo::GetProjectLocation, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, IDgnWorkSetInfo, GetProjectLocation));
    c5.def("SetProjectLocation", &IDgnWorkSetInfo::SetProjectLocation, "location"_a, DOC(Bentley, DgnPlatform, IDgnWorkSetInfo, SetProjectLocation));
    
    c5.def_property("ProjectStatus", &IDgnWorkSetInfo::GetProjectStatus, &IDgnWorkSetInfo::SetProjectStatus);
    c5.def("GetProjectStatus", &IDgnWorkSetInfo::GetProjectStatus, DOC(Bentley, DgnPlatform, IDgnWorkSetInfo, GetProjectStatus));
    c5.def("SetProjectStatus", &IDgnWorkSetInfo::SetProjectStatus, "status"_a, DOC(Bentley, DgnPlatform, IDgnWorkSetInfo, SetProjectStatus));
    
    c5.def_property("ProjectNumber", &IDgnWorkSetInfo::GetProjectNumber, &IDgnWorkSetInfo::SetProjectNumber);
    c5.def("GetProjectNumber", &IDgnWorkSetInfo::GetProjectNumber, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, IDgnWorkSetInfo, GetProjectNumber));
    c5.def("SetProjectNumber", &IDgnWorkSetInfo::SetProjectNumber, "number"_a, DOC(Bentley, DgnPlatform, IDgnWorkSetInfo, SetProjectNumber));
    
    c5.def_property("ProjectName", &IDgnWorkSetInfo::GetProjectName, &IDgnWorkSetInfo::SetProjectName);
    c5.def("GetProjectName", &IDgnWorkSetInfo::GetProjectName, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, IDgnWorkSetInfo, GetProjectName));
    c5.def("SetProjectName", &IDgnWorkSetInfo::SetProjectName, "name"_a, DOC(Bentley, DgnPlatform, IDgnWorkSetInfo, SetProjectName));

    c5.def("IsAssociatedWithConnectProject", &IDgnWorkSetInfo::IsAssociatedWithConnectProject, DOC(Bentley, DgnPlatform, IDgnWorkSetInfo, IsAssociatedWithConnectProject));    
    c5.def("AreAllPropertiesLoaded", &IDgnWorkSetInfo::AreAllPropertiesLoaded, DOC(Bentley, DgnPlatform, IDgnWorkSetInfo, AreAllPropertiesLoaded));    
    c5.def("SetAllPropertiesLoaded", &IDgnWorkSetInfo::SetAllPropertiesLoaded, DOC(Bentley, DgnPlatform, IDgnWorkSetInfo, SetAllPropertiesLoaded));

    c5.def("AddProperty", py::overload_cast<WCharCP, double>(&IDgnWorkSetInfo::AddProperty), "name"_a, "value"_a, DOC(Bentley, DgnPlatform, IDgnWorkSetInfo, AddProperty));
    c5.def("AddProperty", py::overload_cast<WCharCP, WCharCP>(&IDgnWorkSetInfo::AddProperty), "name"_a, "value"_a, DOC(Bentley, DgnPlatform, IDgnWorkSetInfo, AddProperty));
    c5.def("AddProperty", py::overload_cast<WCharCP, DateTimeCR>(&IDgnWorkSetInfo::AddProperty), "name"_a, "value"_a, DOC(Bentley, DgnPlatform, IDgnWorkSetInfo, AddProperty));
    c5.def("AddProperty", py::overload_cast<WCharCP, Int32>(&IDgnWorkSetInfo::AddProperty), "name"_a, "value"_a, DOC(Bentley, DgnPlatform, IDgnWorkSetInfo, AddProperty));
    c5.def("AddProperty", py::overload_cast<WCharCP, bool>(&IDgnWorkSetInfo::AddProperty), "name"_a, "value"_a, DOC(Bentley, DgnPlatform, IDgnWorkSetInfo, AddProperty));
    c5.def("AddProperty", py::overload_cast<WCharCP, ECN::ECValueCR>(&IDgnWorkSetInfo::AddProperty), "name"_a, "value"_a, DOC(Bentley, DgnPlatform, IDgnWorkSetInfo, AddProperty));
    c5.def("RemoveProperty", &IDgnWorkSetInfo::RemoveProperty, DOC(Bentley, DgnPlatform, IDgnWorkSetInfo, RemoveProperty));
    c5.def("GetProperty", &IDgnWorkSetInfo::GetProperty, "name"_a, "value"_a, DOC(Bentley, DgnPlatform, IDgnWorkSetInfo, GetProperty));
    c5.def("__eq__", [] (IDgnWorkSetInfoCR self, IDgnWorkSetInfoCR other) { return self.Equals(other); });
    c5.def("IsSameWorkSet", &IDgnWorkSetInfo::IsSameWorkSet, "other"_a, DOC(Bentley, DgnPlatform, IDgnWorkSetInfo, IsSameWorkSet));
    c5.def("Write", py::overload_cast<DgnFileR>(&IDgnWorkSetInfo::Write, py::const_), "dgnFile"_a, DOC(Bentley, DgnPlatform, IDgnWorkSetInfo, Write));
    c5.def("Clone", &IDgnWorkSetInfo::Clone, DOC(Bentley, DgnPlatform, IDgnWorkSetInfo, Clone));

    c5.def_static("ExistsOnDgnFile", &IDgnWorkSetInfo::ExistsOnDgnFile, "dgnFile"_a, DOC(Bentley, DgnPlatform, IDgnWorkSetInfo, ExistsOnDgnFile));
    c5.def_static("ExtractFromDgnFile", &IDgnWorkSetInfo::ExtractFromDgnFile, "dgnFile"_a, DOC(Bentley, DgnPlatform, IDgnWorkSetInfo, ExtractFromDgnFile));
    c5.def_static("AddListener", &IDgnWorkSetInfo::AddListener, "listener"_a, py::keep_alive<1, 2>(), DOC(Bentley, DgnPlatform, IDgnWorkSetInfo, AddListener));
    c5.def_static("DropListener", &IDgnWorkSetInfo::DropListener, "listener"_a, DOC(Bentley, DgnPlatform, IDgnWorkSetInfo, DropListener));

    c5.def_property_readonly_static("NoWorkSetName", [] (py::object const&) { return IDgnWorkSetInfo::GetNoWorkSetName(); });
    c5.def_static("GetNoWorkSetName", &IDgnWorkSetInfo::GetNoWorkSetName, py::return_value_policy::reference, DOC(Bentley, DgnPlatform, IDgnWorkSetInfo, GetNoWorkSetName));
    
    c5.def_static("Remove", &IDgnWorkSetInfo::Remove, "dgnFile"_a, DOC(Bentley, DgnPlatform, IDgnWorkSetInfo, Remove));

    //===================================================================================
    // struct WorkSetCompareFilter
    py::class_< WorkSetCompareFilter> c6(m, "WorkSetCompareFilter");

    //c6.def("SetConfigurationAdmin", &WorkSetCompareFilter::SetConfigurationAdmin, "admin"_a, py::keep_alive<1, 2>());
    c6.def(py::init<>());
    
    c6.def("__setitem__", [] (WorkSetCompareFilter& self, WStringCR key, WStringCR value)
           {
           auto& map = self.GetFilterMap();
           auto it = map.find(key);
           if (it == map.end())
               map.Insert(key, value);
           else
               it->second = value;
           });

    c6.def("__getitem__", [] (WorkSetCompareFilter& self, WStringCR key)
           {
           WString retVal;
           auto& map = self.GetFilterMap();
           auto it = map.find(key);
           if (it != map.end())
               retVal = it->second;
           return retVal;
           });

    c6.def("__delitem__", [] (WorkSetCompareFilter& self, WStringCR key)
           {
           auto& map = self.GetFilterMap();
           auto it = map.find(key);
           if (it != map.end())
               map.erase(it);
           });

    c6.def_static("Get", [] () { return std::unique_ptr< WorkSetCompareFilter, py::nodelete>(&WorkSetCompareFilter::Get()); });

    //===================================================================================
    // struct DgnWorkSetComparer
    py::class_< DgnWorkSetComparer> c7(m, "DgnWorkSetComparer");

    if (true)
        {
        //===================================================================================
        // enum class ComparisonOption
        py::enum_< DgnWorkSetComparer::ComparisonOption>(c7, "ComparisonOption")
            .value("eNone", DgnWorkSetComparer::ComparisonOption::None)
            .value("eName", DgnWorkSetComparer::ComparisonOption::Name)
            .value("eConnectGUID", DgnWorkSetComparer::ComparisonOption::ConnectGUID)
            .value("eCustomProperties", DgnWorkSetComparer::ComparisonOption::CustomProperties)
            .value("eAll", DgnWorkSetComparer::ComparisonOption::All)
            .export_values();

        //===================================================================================
        // enum class ComparisonStatus
        py::enum_< DgnWorkSetComparer::ComparisonStatus>(c7, "ComparisonStatus")
            .value("eMatching", DgnWorkSetComparer::ComparisonStatus::Matching)
            .value("eBothUnassociated", DgnWorkSetComparer::ComparisonStatus::BothUnassociated)
            .value("eBothAssociatedNonMatching", DgnWorkSetComparer::ComparisonStatus::BothAssociatedNonMatching)
            .value("eFirstAssociatedSecondUnassociated", DgnWorkSetComparer::ComparisonStatus::FirstAssociatedSecondUnassociated)
            .value("eFirstUnassociatedSecondAssociated", DgnWorkSetComparer::ComparisonStatus::FirstUnassociatedSecondAssociated)
            .value("eFirstFileFilteredOut", DgnWorkSetComparer::ComparisonStatus::FirstFileFilteredOut)
            .value("eSecondFileFilteredOut", DgnWorkSetComparer::ComparisonStatus::SecondFileFilteredOut)
            .export_values();
        }

    c7.def(py::init<DgnWorkSetComparer::ComparisonOption, WorkSetCompareFilter*>(), "option"_a = DgnWorkSetComparer::ComparisonOption::Name, "fileFilter"_a = nullptr);
    c7.def("SetFirstWorkSet", &DgnWorkSetComparer::SetFirstWorkSet, "workSet"_a, DOC(Bentley, DgnPlatform, DgnWorkSetComparer, SetFirstWorkSet));
    c7.def("SetSecondWorkSet", &DgnWorkSetComparer::SetSecondWorkSet, "workSet"_a, DOC(Bentley, DgnPlatform, DgnWorkSetComparer, SetSecondWorkSet));
    c7.def("SetFirstFile", py::overload_cast<DgnFileR>(&DgnWorkSetComparer::SetFirstFile), "dgnFile"_a, DOC(Bentley, DgnPlatform, DgnWorkSetComparer, SetFirstFile));
    c7.def("SetSecondFile", py::overload_cast<DgnFileR>(&DgnWorkSetComparer::SetSecondFile), "dgnFile"_a, DOC(Bentley, DgnPlatform, DgnWorkSetComparer, SetSecondFile));
    c7.def("SetFirstFile", py::overload_cast<DgnDocumentMonikerR>(&DgnWorkSetComparer::SetFirstFile), "moniker"_a, DOC(Bentley, DgnPlatform, DgnWorkSetComparer, SetFirstFile));
    c7.def("SetSecondFile", py::overload_cast<DgnDocumentMonikerR>(&DgnWorkSetComparer::SetSecondFile), "moniker"_a, DOC(Bentley, DgnPlatform, DgnWorkSetComparer, SetSecondFile));
    c7.def("SetOption", &DgnWorkSetComparer::SetOption, "options"_a, DOC(Bentley, DgnPlatform, DgnWorkSetComparer, SetOption));
    c7.def("Compare", &DgnWorkSetComparer::Compare, DOC(Bentley, DgnPlatform, DgnWorkSetComparer, Compare));

    c7.def_property_readonly("FirstWorkSet", &DgnWorkSetComparer::GetFirstWorkSet);
    c7.def("GetFirstWorkSet", &DgnWorkSetComparer::GetFirstWorkSet, DOC(Bentley, DgnPlatform, DgnWorkSetComparer, GetFirstWorkSet));
    
    c7.def_property_readonly("SecondWorkSet", &DgnWorkSetComparer::GetSecondWorkSet);
    c7.def("GetSecondWorkSet", &DgnWorkSetComparer::GetSecondWorkSet, DOC(Bentley, DgnPlatform, DgnWorkSetComparer, GetSecondWorkSet));

    }