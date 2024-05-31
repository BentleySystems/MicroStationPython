/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnPlatform\source\picklist.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <DgnPlatform/PickList.h>

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       10/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_PickList(py::module_& m)
    {
    //===================================================================================
    // struct PickListValue
    typedef RefCountedPtr<PickListValue> PickListValuePtr;

    py::class_<PickListValue, PickListValuePtr> c1(m, "PickListValue");

    c1.def(py::init<>());
    c1.def(py::init<PickListValue const&>(), "pickListValue"_a);

    c1.def("GetValue", &PickListValue::GetValue);
    c1.def("GetId", &PickListValue::GetId);
    c1.def("JudgeSame", &PickListValue::JudgeSame, "anotherPickListValue"_a, "judgeId"_a = true);

    //===================================================================================
    // struct PickList
    typedef RefCountedPtr<PickList> PickListPtr;

    py::class_<PickList, PickListPtr> c2(m, "PickList");

    c2.def("__iter__", [](PickList& self) { return py::make_iterator(self.begin(), self.end()); }, py::keep_alive<0, 1>());

    c2.def(py::init<>());
    c2.def(py::init<PickList const&>(), "pickList"_a);

    c2.def_property("Name", &PickList::GetName, &PickList::SetName);
    c2.def("GetName", &PickList::GetName);
    c2.def("SetName", &PickList::SetName, "name"_a);

    c2.def_property("DgnFile", &PickList::GetDgnFile, &PickList::SetDgnFile);
    c2.def("GetDgnFile", &PickList::GetDgnFile);
    c2.def("SetDgnFile", &PickList::SetDgnFile, "dgnFile"_a);

    c2.def("AddValue", py::overload_cast<PickListValue&>(&PickList::AddValue), "value"_a);
    c2.def("AddValue", py::overload_cast<WStringCR>(&PickList::AddValue), "valString"_a);

    c2.def("CanFindValueByString", &PickList::CanFindValueByString, "valString"_a);
    c2.def("CanFindValueById", &PickList::CanFindValueById, "id"_a);
    c2.def("RemoveValueByString", &PickList::RemoveValueByString, "valString"_a);
    c2.def("RemoveValueById", &PickList::RemoveValueById, "id"_a);
    c2.def("RemoveAllValues", &PickList::RemoveAllValues);

    c2.def("HasIntegerValues", &PickList::HasIntegerValues);
    c2.def("HasDoubleValues", &PickList::HasDoubleValues);

    c2.def("GetId", &PickList::GetId);
    c2.def("GetValueCount", &PickList::GetValueCount);

    c2.def("GetPickListValueByValue", &PickList::GetPickListValueByValue, "valString"_a);
    c2.def("GetPickListValueByID", &PickList::GetPickListValueByID, "id"_a);
    c2.def("JudgeSame", &PickList::JudgeSame, "anotherPickList"_a, "judgeId"_a = true, "judgeDgnFile"_a = true);
    c2.def("SortValues", &PickList::SortValues, "ascending"_a);

    //===================================================================================
    // struct PickList
    typedef RefCountedPtr<PickListLibrary> PickListLibraryPtr;

    py::class_<PickListLibrary, PickListLibraryPtr> c3(m, "PickListLibrary");

    c3.def("__iter__", [](PickListLibrary& self) { return py::make_iterator(self.begin(), self.end()); }, py::keep_alive<0, 1>());

    c3.def_static("CreatePickListLibrary", &PickListLibrary::CreatePickListLibrary);
    c3.def ("AddPickList", py::overload_cast<PickList&>(&PickListLibrary::AddPickList), "pickList"_a);
    c3.def ("AddPickList", py::overload_cast<PickList& , DgnFileP>(&PickListLibrary::AddPickList), "pickList"_a, "dgnFile"_a);
    c3.def ("AddPickList", py::overload_cast<WStringCR, DgnFileP>(&PickListLibrary::AddPickList), "name"_a, "dgnFile"_a);
    c3.def("GetPickListByName", &PickListLibrary::GetPickListByName, "name"_a);
    c3.def("GetPickListById", &PickListLibrary::GetPickListById, "id"_a);
    c3.def("RemovePickListByName", &PickListLibrary::RemovePickListByName, "name"_a);
    c3.def("RemovePickListById", &PickListLibrary::RemovePickListById, "id"_a);
    c3.def("GetPickListCount", &PickListLibrary::GetPickListCount);

    c3.def_static("SavePickListLibToDgn", &PickListLibrary::SavePickListLibToDgn, "dgnFile"_a, "pickListLib"_a, "isUpdateRelatedObjects"_a = false);
    c3.def_static("SavePickListLibToDgnWithChanges", &PickListLibrary::SavePickListLibToDgnWithChanges, "dgnFile"_a, "pickListLib"_a, "pickListChangeIds"_a, "pickListValueChangeIds"_a, "isUpdateRelatedObjects"_a = false);
    c3.def_static("GetPickListLibFromDgn", &PickListLibrary::GetPickListLibFromDgn, "dgnFile"_a, "pickListLib"_a);
    c3.def_static("DeletePickListLibFromDgn", &PickListLibrary::DeletePickListLibFromDgn, "dgnFile"_a);

    c3.def_static("GetCountOfPickListInDgn", &PickListLibrary::GetCountOfPickListInDgn, "dgnFile"_a);
    c3.def_static("PickListExistsInDgn", &PickListLibrary::PickListExistsInDgn, "dgnFile"_a, "pickListName"_a);
    c3.def_static("ClearDgnLibList", &PickListLibrary::ClearDgnLibList);
    c3.def_static("IsDgnLibInList", &PickListLibrary::IsDgnLibInList, "dgnLib"_a);
    c3.def_static("IsPickListExistInDgnLibFiles", &PickListLibrary::IsPickListExistInDgnLibFiles);

    c3.def("Clone", &PickListLibrary::Clone);
    c3.def("JudgeSame", &PickListLibrary::JudgeSame, "anotherPickListLibrary"_a, "judgeId"_a=true, "judgeDgnFile"_a = true);

    c3.def_static("IsPickListUsedByElements", &PickListLibrary::IsPickListUsedByElements, "pickListId"_a, "dgnFile"_a);
    }
