/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnPlatform\source\dgntextsnippet.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <DgnPlatform/DgnTextSnippet.h>



static const char * __doc_Bentley_DgnPlatform_DgnTextSnippetCategory_IsSame =R"doc(Checks if the input DgnTextSnippetCategory is the same

Returns:
    true if the Categrory is the same else returns false)doc";

static const char * __doc_Bentley_DgnPlatform_DgnTextSnippetCategory_GetECInstance =R"doc(Get ECInstance

Returns:
    ECInstance related to the category.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnTextSnippetCategory_GetTextFavorites =R"doc(Get Text Snippet

Parameter ``snippets``:
    TextFavorites get from file.

Parameter ``category``:
    Category to get TextFavorites from.

Parameter ``file``:
    Assigned file.

Returns:
    Status of GetTextFavorites.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnTextSnippetCategory_BuildCategoryTreeFromFile =R"doc(Get catogories from file.

Parameter ``name``:
    Name of category.

Parameter ``file``:
    Assigned file.

Parameter ``categories``:
    Categories build from file.

Returns:
    Status of BuildCategoryTreeFromFile.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnTextSnippetCategory_Delete =R"doc(Deletes a DgnTextSnippetCategory from the file.

Parameter ``fileIn``:
    Assigned file.

Returns:
    Status of Delete.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnTextSnippetCategory_Replace =R"doc(Replace DgnTextSnippetCategory in file

Parameter ``fileIn``:
    Assigned file.

Returns:
    Status of Replace.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnTextSnippetCategory_Add =R"doc(Add DgnTextSnippetCategory to file

Parameter ``fileIn``:
    Assigned file.

Returns:
    Status of Add.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnTextSnippetCategory_RemoveSubCategory =R"doc(Remove sub-category

Parameter ``name``:
    Category name.

Returns:
    Status of RemoveSubCategory.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnTextSnippetCategory_GetSubCategories =R"doc(Get sub-categories

Returns:
    vector of sub categories.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnTextSnippetCategory_AddSubCategory =R"doc(Add sub-category

Parameter ``subCategory``:
    sub-Category.

Returns:
    Status of AddSubCategory.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnTextSnippetCategory_IsSubCategoryExist =R"doc(Check if sub category exist

Parameter ``subCategory``:
    sub-Category.

Returns:
    True if sub category exists, else False.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnTextSnippetCategory_SetParentCategory =R"doc(Set the name of the parent category.

Parameter ``parent``:
    category.

Returns:
    Status of SetParentCategory.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnTextSnippetCategory_GetParentCategory =R"doc(Get the name of the parent category

Returns:
    Name of parent category.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnTextSnippetCategory_SetName =R"doc(Set the name of this category

Parameter ``name``:
    Name of category.

Returns:
    Status of SetName.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnTextSnippetCategory_GetName =R"doc(Get the name of this category

Returns:
    Name of category.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnTextSnippetCategory_GetFile =R"doc(Get the file associated with this category.

Returns:
    The file associated with this category.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnTextSnippetPropertyMask_ResetFlags =R"doc(Reset all the property flags to false.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnTextSnippetPropertyMask_AnyBitSet =R"doc(Tests whether any of the flags are set.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnTextSnippetPropertyMask_SetPropertyFlag =R"doc(Assigns the property value associated with a property.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnTextSnippetPropertyMask_GetPropertyFlag =R"doc(Tests whether the specific flag is set.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnTextSnippet_Compare =R"doc(Compares the snippet with the provided one.

Parameter ``snippet``:
    IN snippet to be comapred against.

Returns:
    DgnTextSnippetPropertyMaskPtr Pointer filled with differences.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnTextSnippet_CopyValues =R"doc(Copies the values into the current snippet from another snippet.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnTextSnippet_GetByID =R"doc(Looks up the snippet from the given file.

Parameter ``id``:
    IN snippet ID to be fetched.

Parameter ``file``:
    file in which to search.

Returns:
    snippet pointer if found else null.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnTextSnippet_GetByName =R"doc(Looks up the snippet from the given file.

Parameter ``name``:
    IN name to lookup for.

Parameter ``file``:
    IN file in which to search.

Returns:
    snippet pointer if found else null.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnTextSnippet_Replace =R"doc(* Saves the snippet to the file.

Parameter ``oldName``:
    IN oldName to look up the snippet if the snippet was renamed.

Parameter ``file``:
    IN If no file is provided, the file pointer in snippet is used to
    determine the file in which it is saved.

Returns:
    status. Note:it returns ERROR if a snippet cannot be found or if
    replace fails.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnTextSnippet_Delete =R"doc(Deletes a DgnTextSnippet from the snippet file.

Parameter ``name``:
    IN name to lookup for.

Parameter ``file``:
    IN file in which to search.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnTextSnippet_Add =R"doc(Creates a snippet in the given file.

Parameter ``file``:
    IN file pointer for the target snippet.

Returns:
    status. Note:it returns ERROR if a snippet is already present)doc";

static const char * __doc_Bentley_DgnPlatform_DgnTextSnippet_Create =R"doc(Create an in memory representation of any empty snippet with respect
to the given file.

Parameter ``name``:
    IN name of the new snippet. Can be empty.

Parameter ``file``:
    IN The file where the snippet will be stored.

Returns:
    A snippet pointer for the template snippet. NULL if it is
    unsuccessful.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnTextSnippet_SetCategory =R"doc(Set the category of this snippet.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnTextSnippet_GetCategory =R"doc(Get the category of this snippet.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnTextSnippet_SetSnippetText =R"doc(Set the snippet text content.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnTextSnippet_GetSnippetText =R"doc(Get the text associated with this snippet)doc";

static const char * __doc_Bentley_DgnPlatform_DgnTextSnippet_GetDisplayName =R"doc(Get the display name of this snippet)doc";

static const char * __doc_Bentley_DgnPlatform_DgnTextSnippet_GetID =R"doc(Gets the snippet id)doc";

static const char * __doc_Bentley_DgnPlatform_DgnTextSnippet_SetName =R"doc(Set the name of this snippet)doc";

static const char * __doc_Bentley_DgnPlatform_DgnTextSnippet_GetName =R"doc(Get the name of this snippet)doc";

static const char * __doc_Bentley_DgnPlatform_DgnTextSnippet_GetFile =R"doc(Get the file associated with this file)doc";

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_DgnTextSnippet(py::module_& m)
    {
    //===================================================================================
    // struct DgnTextSnippet
    py::class_< DgnTextSnippet, DgnTextSnippetPtr> c1(m, "DgnTextSnippet");
    py::bind_vector<bvector< DgnTextSnippetPtr>>(m, "DgnTextSnippetPtrArray", py::module_local(false));

    if (true)
        {
        //===================================================================================
        // enum DgnTextSnippetProperty
        py::enum_< DgnTextSnippet::DgnTextSnippetProperty>(c1, "DgnTextSnippetProperty", py::arithmetic())
            .value("eSnippetName", DgnTextSnippet::SnippetName)
            .value("eSnippetText", DgnTextSnippet::SnippetText)
            .value("eFromActiveFile", DgnTextSnippet::FromActiveFile)
            .value("eSnippetCategory", DgnTextSnippet::SnippetCategory)
            .value("eSnippetDisplayName", DgnTextSnippet::SnippetDisplayName)
            .export_values();
        }

    c1.def_property_readonly("File", &DgnTextSnippet::GetFile);
    c1.def("GetFile", &DgnTextSnippet::GetFile, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, DgnTextSnippet, GetFile));
    
    c1.def_property("Name", &DgnTextSnippet::GetName, &DgnTextSnippet::SetName);
    c1.def("GetName", &DgnTextSnippet::GetName, DOC(Bentley, DgnPlatform, DgnTextSnippet, GetName));
    c1.def("SetName", &DgnTextSnippet::SetName, "name"_a, DOC(Bentley, DgnPlatform, DgnTextSnippet, SetName));
    
    c1.def_property_readonly("ID", &DgnTextSnippet::GetID);
    c1.def("GetID", &DgnTextSnippet::GetID, DOC(Bentley, DgnPlatform, DgnTextSnippet, GetID));
    
    c1.def_property_readonly("DisplayName", &DgnTextSnippet::GetDisplayName);    
    c1.def("GetDisplayName", &DgnTextSnippet::GetDisplayName, DOC(Bentley, DgnPlatform, DgnTextSnippet, GetDisplayName));    
    
    c1.def_property("SnippetText", &DgnTextSnippet::GetSnippetText, &DgnTextSnippet::SetSnippetText);
    c1.def("GetSnippetText", &DgnTextSnippet::GetSnippetText, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, DgnTextSnippet, GetSnippetText));
    c1.def("SetSnippetText", &DgnTextSnippet::SetSnippetText, "text"_a, DOC(Bentley, DgnPlatform, DgnTextSnippet, SetSnippetText));
    
    c1.def_property("Category", &DgnTextSnippet::GetCategory, py::cpp_function(&DgnTextSnippet::SetCategory, py::keep_alive<1, 2>()));
    c1.def("GetCategory", &DgnTextSnippet::GetCategory, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, DgnTextSnippet, GetCategory));
    c1.def("SetCategory", &DgnTextSnippet::SetCategory, "category"_a, py::keep_alive<1, 2>(), DOC(Bentley, DgnPlatform, DgnTextSnippet, SetCategory));
    
    c1.def_static("Create", &DgnTextSnippet::Create, "name"_a, "file"_a, DOC(Bentley, DgnPlatform, DgnTextSnippet, Create));
    c1.def("Add", &DgnTextSnippet::Add, "file"_a = nullptr, DOC(Bentley, DgnPlatform, DgnTextSnippet, Add));
    c1.def_static("Delete", &DgnTextSnippet::Delete, "name"_a, "file"_a, DOC(Bentley, DgnPlatform, DgnTextSnippet, Delete));
    c1.def("Replace", &DgnTextSnippet::Replace, "oldName"_a = nullptr, "file"_a = nullptr, DOC(Bentley, DgnPlatform, DgnTextSnippet, Replace));
    c1.def_static("GetByName", &DgnTextSnippet::GetByName, "name"_a, "file"_a, DOC(Bentley, DgnPlatform, DgnTextSnippet, GetByName));
    c1.def_static("GetByID", &DgnTextSnippet::GetByID, "id"_a, "file"_a, DOC(Bentley, DgnPlatform, DgnTextSnippet, GetByID));
    c1.def("CopyValues", &DgnTextSnippet::CopyValues, "snippet"_a, DOC(Bentley, DgnPlatform, DgnTextSnippet, CopyValues));
    c1.def("Compare", &DgnTextSnippet::Compare, "snippet"_a, DOC(Bentley, DgnPlatform, DgnTextSnippet, Compare));
    c1.def("IsPersisted", &DgnTextSnippet::IsPersisted);
    c1.def_static("UpgradeSchemaAndInstance", &DgnTextSnippet::UpgradeSchemaAndInstance, "file"_a);        

    //===================================================================================
    // struct DgnTextSnippetPropertyMask
    py::class_< DgnTextSnippetPropertyMask, DgnTextSnippetPropertyMaskPtr> c2(m, "DgnTextSnippetPropertyMask");

    c2.def(py::init(&DgnTextSnippetPropertyMask::CreatePropMask));
    c2.def("GetPropertyFlag", &DgnTextSnippetPropertyMask::GetPropertyFlag, "flag"_a, DOC(Bentley, DgnPlatform, DgnTextSnippetPropertyMask, GetPropertyFlag));
    c2.def("SetPropertyFlag", &DgnTextSnippetPropertyMask::SetPropertyFlag, "flag"_a, "value"_a, DOC(Bentley, DgnPlatform, DgnTextSnippetPropertyMask, SetPropertyFlag));
    c2.def("AnyBitSet", &DgnTextSnippetPropertyMask::AnyBitSet, DOC(Bentley, DgnPlatform, DgnTextSnippetPropertyMask, AnyBitSet));
    c2.def("ResetFlags", &DgnTextSnippetPropertyMask::ResetFlags, DOC(Bentley, DgnPlatform, DgnTextSnippetPropertyMask, ResetFlags));

    //===================================================================================
    // struct DgnTextSnippetCollection
    py::class_< DgnTextSnippetCollection> c3(m, "DgnTextSnippetCollection");

    c3.def(py::init<DgnFileR>(), "file"_a);
    c3.def("__iter__", [] (DgnTextSnippetCollection& self) { return py::make_iterator(self.begin(), self.end()); }, py::keep_alive<0, 1>());

    //===================================================================================
    // struct DgnTextSnippetCategory
    py::class_< DgnTextSnippetCategory, DgnTextSnippetCategoryPtr> c4(m, "DgnTextSnippetCategory");
    py::bind_vector<bvector< DgnTextSnippetCategoryPtr>>(m, "DgnTextSnippetCategoryPtrArray", py::module_local(false));

    c4.def(py::init(&DgnTextSnippetCategory::Create), "name"_a, "file"_a);
    
    c4.def_property_readonly("File", &DgnTextSnippetCategory::GetFile);
    c4.def("GetFile", &DgnTextSnippetCategory::GetFile, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, DgnTextSnippetCategory, GetFile));

    c4.def_property("Name", &DgnTextSnippetCategory::GetName, &DgnTextSnippetCategory::SetName);
    c4.def("GetName", &DgnTextSnippetCategory::GetName, DOC(Bentley, DgnPlatform, DgnTextSnippetCategory, GetName));
    c4.def("SetName", &DgnTextSnippetCategory::SetName, "name"_a, DOC(Bentley, DgnPlatform, DgnTextSnippetCategory, SetName));
    
    c4.def_property("ParentCategory",
                    &DgnTextSnippetCategory::GetParentCategory,
                    [] (DgnTextSnippetCategory& self, DgnTextSnippetCategoryP pCat) { self.SetParentCategory(DgnTextSnippetCategoryPtr(pCat)); });
    c4.def("GetParentCategory", &DgnTextSnippetCategory::GetParentCategory, DOC(Bentley, DgnPlatform, DgnTextSnippetCategory, GetParentCategory));
    c4.def("SetParentCategory", 
           [] (DgnTextSnippetCategory& self, DgnTextSnippetCategoryP pCat)
           { 
           self.SetParentCategory(DgnTextSnippetCategoryPtr(pCat)); 
           }, "category"_a, DOC(Bentley, DgnPlatform, DgnTextSnippetCategory, SetParentCategory));

    c4.def("IsSubCategoryExist", &DgnTextSnippetCategory::IsSubCategoryExist, "subCategory"_a, DOC(Bentley, DgnPlatform, DgnTextSnippetCategory, IsSubCategoryExist));
    c4.def("AddSubCategory", &DgnTextSnippetCategory::AddSubCategory, "subCategory"_a, DOC(Bentley, DgnPlatform, DgnTextSnippetCategory, AddSubCategory));

    c4.def_property_readonly("SubCategories", &DgnTextSnippetCategory::GetSubCategories);
    c4.def("GetSubCategories", &DgnTextSnippetCategory::GetSubCategories, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, DgnTextSnippetCategory, GetSubCategories));
    
    c4.def("RemoveSubCategory", &DgnTextSnippetCategory::RemoveSubCategory, "name"_a, DOC(Bentley, DgnPlatform, DgnTextSnippetCategory, RemoveSubCategory));
    c4.def("Add", &DgnTextSnippetCategory::Add, "fileIn"_a = nullptr, DOC(Bentley, DgnPlatform, DgnTextSnippetCategory, Add));
    c4.def("Replace", &DgnTextSnippetCategory::Replace, "fileIn"_a = nullptr, DOC(Bentley, DgnPlatform, DgnTextSnippetCategory, Replace));
    c4.def("Delete", &DgnTextSnippetCategory::Delete, "fileIn"_a = nullptr, DOC(Bentley, DgnPlatform, DgnTextSnippetCategory, Delete));
    c4.def_static("BuildCategoryTreeFromFile", &DgnTextSnippetCategory::BuildCategoryTreeFromFile, "categories"_a, "file"_a, DOC(Bentley, DgnPlatform, DgnTextSnippetCategory, BuildCategoryTreeFromFile));
    c4.def_static("GetTextFavorites", &DgnTextSnippetCategory::GetTextFavorites, "snippets"_a, "category"_a, "file"_a, DOC(Bentley, DgnPlatform, DgnTextSnippetCategory, GetTextFavorites));

    c4.def_property_readonly("ECInstance", &DgnTextSnippetCategory::GetECInstance);
    c4.def("GetECInstance", &DgnTextSnippetCategory::GetECInstance, DOC(Bentley, DgnPlatform, DgnTextSnippetCategory, GetECInstance));
    
    c4.def("IsSame", &DgnTextSnippetCategory::IsSame, "category"_a, DOC(Bentley, DgnPlatform, DgnTextSnippetCategory, IsSame));

    }