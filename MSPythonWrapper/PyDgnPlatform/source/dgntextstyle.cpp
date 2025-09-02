/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnPlatform\source\dgntextstyle.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <DgnPlatform/DgnTextStyleProperties.r.h>
#include <DgnPlatform/DgnTextStyle.h>



static const char * __doc_Bentley_DgnPlatform_DgnTextStyle_ReplaceSettings =R"doc(Replaces the active text settings in the file with the values provided
by style.

)doc";

static const char * __doc_Bentley_DgnPlatform_DgnTextStyle_GetSettings =R"doc(Returns the values stored in the settings element.

)doc";

static const char * __doc_Bentley_DgnPlatform_DgnTextStyle_CopyValues =R"doc(Copies the values into the current style from another style.

)doc";

static const char * __doc_Bentley_DgnPlatform_DgnTextStyle_Copy =R"doc(Create an exact copy of the current style.

)doc";

static const char * __doc_Bentley_DgnPlatform_DgnTextStyle_Replace =R"doc(* Saves the style to the file.

:param oldName:
    (input) oldName to look up the style if the style was renamed.

:param file:
    (input) If no file is provided, the file pointer in style is used to
    determine the file in which it is saved.

:returns:
    status. Note:it returns ERROR if a style cannot be found or if
    replace fails.

)doc";

static const char * __doc_Bentley_DgnPlatform_DgnTextStyle_RemapDependents =R"doc(Remap all the elements that reference one style to different style.

:param destStyle:
    (input) remap to this style.

:param sourceStyle:
    (input) remap from this style.

:param file:
    (input) file in which to search.

)doc";

static const char * __doc_Bentley_DgnPlatform_DgnTextStyle_HasDependants =R"doc()doc";

static const char * __doc_Bentley_DgnPlatform_DgnTextStyle_Delete =R"doc(Deletes a textstyle from a dgn file. This method will fail if any
elements refer to the style.

:param name:
    (input) name to lookup for.

:param file:
    (input) file in which to search.

See also:
    HasDependents

See also:
    RemapDependents

)doc";

static const char * __doc_Bentley_DgnPlatform_DgnTextStyle_Add =R"doc(Creates a style in the given file.

:param file:
    (input) file pointer for the target style.

:returns:
    status. Note:it returns ERROR if a style is already present

)doc";

static const char * __doc_Bentley_DgnPlatform_DgnTextStyle_BuildList =R"doc(Create a list of all the styles in the specified file.

:param file:
    (input) file in which to search.

:returns:
    list of styles

)doc";

static const char * __doc_Bentley_DgnPlatform_DgnTextStyle_ExistsByName =R"doc(Returns true if a style with the given name exists in the given file.

:param name:
    (input) name to look for.

:param file:
    (input) file in which to search.

:returns:
    true if a style with the specified name exists, else false.

)doc";

static const char * __doc_Bentley_DgnPlatform_DgnTextStyle_GetByName =R"doc(Looks up the style from the given file.

:param name:
    (input) name to lookup for.

:param file:
    (input) file in which to search.

:returns:
    style pointer if found else null.

)doc";

static const char * __doc_Bentley_DgnPlatform_DgnTextStyle_GetByID =R"doc(Looks up the style from the given file.

:param styleID:
    (input) ID to lookup for.

:param file:
    (input) file in which to search.

:returns:
    DgnTextStylePtr (output) style pointer. Null if not found.

)doc";

static const char * __doc_Bentley_DgnPlatform_DgnTextStyle_Compare =R"doc(Compares the style with the provided one.

:param style:
    (input) Style to be comapred against.

:returns:
    TextstylePropertymask Pointer filled with differences.

)doc";

static const char * __doc_Bentley_DgnPlatform_DgnTextStyle_GetFile =R"doc(Gets the file associated with this style.

)doc";

static const char * __doc_Bentley_DgnPlatform_DgnTextStyle_SetID =R"doc(Set the current style ID.

)doc";

static const char * __doc_Bentley_DgnPlatform_DgnTextStyle_GetID =R"doc(Gets the style id

)doc";

static const char * __doc_Bentley_DgnPlatform_DgnTextStyle_SetName =R"doc(Set the name associated with the style.

)doc";

static const char * __doc_Bentley_DgnPlatform_DgnTextStyle_GetName =R"doc(Gets the style name.

)doc";

static const char * __doc_Bentley_DgnPlatform_TextStylePropertyMask_ResetFlags =R"doc(Reset all the property flags to false.

)doc";

static const char * __doc_Bentley_DgnPlatform_TextStylePropertyMask_AnyBitSet =R"doc(Tests whether any of the flags are set.

)doc";

static const char * __doc_Bentley_DgnPlatform_TextStylePropertyMask_SetPropertyFlag =R"doc(Assigns the property value associated with a property.

)doc";

static const char * __doc_Bentley_DgnPlatform_TextStylePropertyMask_GetPropertyFlag =R"doc(Tests whether the specific flag is set.

)doc";

//=======================================================================================
// Trampoline class for ITextStyleTransactionListener.
// @bsiclass                                                                   02/23
//=======================================================================================
struct IPyTextStyleTransactionListener : ITextStyleTransactionListener
    {
    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       2/2023
    +---------------+---------------+---------------+---------------+---------------+------*/        
    virtual void _OnTextStyleChange(DgnTextStyleCP before, DgnTextStyleCP after, StyleEventType type, StyleEventSource source, void* sender)
        {
        try
            {
            py::gil_scoped_acquire gil;
            py::function pyfunc = py::get_override(this, "_OnTextStyleChange");
            if (pyfunc)
                {
                // _OnTextStyleChange(self, before, after, type, source, sender)
                pyfunc(before, after, type, source, py::capsule(sender));
                }
            else
                pybind11::pybind11_fail("Tried to call pure virtual function ITextStyleTransactionListener::_OnTextStyleChange");
            }
        catch (std::exception& err)
            {
            ScriptEngineManager::Get().InjectException(err);
            }
        }
    };

//=======================================================================================
// Trampoline class for TextStyleEvents.
// @bsiclass                                                                   02/23
//=======================================================================================
struct PyTextStyleEvents : TextStyleEvents
    {
    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       2/2023
    +---------------+---------------+---------------+---------------+---------------+------*/        
    virtual void _OnTextStyleChange(DgnTextStyleCP before, DgnTextStyleCP after, StyleEventType type, StyleEventSource source, void* sender)
        {
        try
            {
            py::gil_scoped_acquire gil;
            py::function pyfunc = py::get_override(this, "_OnTextStyleChange");
            if (pyfunc)
                {
                // _OnTextStyleChange(self, before, after, type, source, sender)
                pyfunc(before, after, type, source, py::capsule(sender));
                }
            else
                pybind11::pybind11_fail("Tried to call pure virtual function TextStyleEvents::_OnTextStyleChange");
            }
        catch (std::exception& err)
            {
            ScriptEngineManager::Get().InjectException(err);
            }
        }
    };

using ITextStyleTransactionListenerPtr = std::unique_ptr< ITextStyleTransactionListener, py::nodelete>;
using TextStyleEventsPtr = std::unique_ptr< TextStyleEvents, py::nodelete>;

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_DgnTextStyle(py::module_& m)
    {
    //===================================================================================
    // struct ITextStyleTransactionListener
    py::class_< ITextStyleTransactionListener, ITextStyleTransactionListenerPtr, IPyTextStyleTransactionListener> c1(m, "ITextStyleTransactionListener");

    c1.def(py::init<>());
    c1.def("_OnTextStyleChange", [] (ITextStyleTransactionListener& self, DgnTextStyleCP before, DgnTextStyleCP after, StyleEventType type, StyleEventSource source, py::capsule const& sender)
           {
           self._OnTextStyleChange(before, after, type, source, sender.get_pointer());
           }, "before"_a, "after"_a, "type"_a, "source"_a, "sender"_a);

    //===================================================================================
    // struct TextStyleEvents
    py::class_< TextStyleEvents, TextStyleEventsPtr, PyTextStyleEvents, ITextStyleTransactionListener> c2(m, "TextStyleEvents");

    //===================================================================================
    // struct TextStylePropertyMask
    py::class_< TextStylePropertyMask, TextStylePropertyMaskPtr> c3(m, "TextStylePropertyMask");


    c3.def(py::init(&TextStylePropertyMask::CreatePropMask));
    c3.def("GetPropertyFlag", [] (TextStylePropertyMask const& self, TextStyleProperty flag) 
        {
        return self.GetPropertyFlag (flag);    
        },   "flag"_a);
    c3.def("SetPropertyFlag", [] (TextStylePropertyMask& self, TextStyleProperty flag, bool value) 
        {
        return self.SetPropertyFlag (flag, value);    
        },   "flag"_a, "value"_a);

    c3.def("AnyBitSet", &TextStylePropertyMask::AnyBitSet, DOC(Bentley, DgnPlatform, TextStylePropertyMask, AnyBitSet));
    c3.def("ResetFlags", &TextStylePropertyMask::ResetFlags, DOC(Bentley, DgnPlatform, TextStylePropertyMask, ResetFlags));

    //===================================================================================
    // struct DgnTextStyle
    py::class_< DgnTextStyle, DgnTextStylePtr> c4(m, "DgnTextStyle");
    py::bind_vector<bvector< DgnTextStylePtr>>(m, "DgnTextStylePtrArray", py::module_local(false));

    c4.def(py::init(py::overload_cast<WCharCP, DgnFileR>(&DgnTextStyle::Create)), "name"_a, "file"_a);

    c4.def_property("Name", &DgnTextStyle::GetName, &DgnTextStyle::SetName);
    c4.def("GetName", &DgnTextStyle::GetName, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, DgnTextStyle, GetName));
    c4.def("SetName", &DgnTextStyle::SetName, "name"_a, DOC(Bentley, DgnPlatform, DgnTextStyle, SetName));
    
    c4.def_property("ID", &DgnTextStyle::GetID, &DgnTextStyle::SetID);
    c4.def("GetID", &DgnTextStyle::GetID, DOC(Bentley, DgnPlatform, DgnTextStyle, GetID));
    c4.def("SetID", &DgnTextStyle::SetID, "id"_a, DOC(Bentley, DgnPlatform, DgnTextStyle, SetID));
    
    c4.def_property_readonly("File", &DgnTextStyle::GetFile);
    c4.def("GetFile", &DgnTextStyle::GetFile, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, DgnTextStyle, GetFile));
    
    c4.def("Compare", &DgnTextStyle::Compare, "style"_a, DOC(Bentley, DgnPlatform, DgnTextStyle, Compare));

    c4.def("GetBoolProperty", [] (DgnTextStyle const& self, TextStyleProperty type)
           {
           bool value = false;
           auto retVal = self.GetProperty(type, value);
           return py::make_tuple(retVal, value);
           }, "type"_a);

    c4.def("GetUInt32Property", [] (DgnTextStyle const& self, TextStyleProperty type)
           {
           UInt32 value = 0;
           auto retVal = self.GetProperty(type, value);
           return py::make_tuple(retVal, value);
           }, "type"_a);

    c4.def("GetInt32Property", [] (DgnTextStyle const& self, TextStyleProperty type)
           {
           Int32 value = 0;
           auto retVal = self.GetProperty(type, value);
           return py::make_tuple(retVal, value);
           }, "type"_a);

    c4.def("GetDoubleProperty", [] (DgnTextStyle const& self, TextStyleProperty type)
           {
           double value = 0;
           auto retVal = self.GetProperty(type, value);
           return py::make_tuple(retVal, value);
           }, "type"_a);

    c4.def("GetDPoint2dProperty", [] (DgnTextStyle const& self, TextStyleProperty type)
           {
           DPoint2d value = DPoint2d::FromZero();
           auto retVal = self.GetProperty(type, value);
           return py::make_tuple(retVal, value);
           }, "type"_a);

    c4.def("GetFontProperty", [] (DgnTextStyle const& self, TextStyleProperty type)
           {
           DgnFontCP value = nullptr;
           auto retVal = self.GetProperty(type, value);
           return py::make_tuple(retVal, RefCountedPtr<DgnFont>((DgnFontP)value));
           }, "type"_a);

    c4.def("SetBoolProperty", [] (DgnTextStyle& self, TextStyleProperty type, bool value)
           {
           return self.SetProperty(type, value);
           }, "type"_a, "value"_a);

    c4.def("SetUInt32Property", [] (DgnTextStyle& self, TextStyleProperty type, UInt32 value)
           {
           return self.SetProperty(type, value);
           }, "type"_a, "value"_a);

    c4.def("SetInt32Property", [] (DgnTextStyle& self, TextStyleProperty type, Int32 value)
           {
           return self.SetProperty(type, value);
           }, "type"_a, "value"_a);

    c4.def("SetDoubleProperty", [] (DgnTextStyle& self, TextStyleProperty type, double value)
           {
           return self.SetProperty(type, value);
           }, "type"_a, "value"_a);

    c4.def("SetDPoint2dProperty", [] (DgnTextStyle& self, TextStyleProperty type, DPoint2dCR value)
           {
           return self.SetProperty(type, value);
           }, "type"_a, "value"_a);

    c4.def("SetFontProperty", [] (DgnTextStyle& self, TextStyleProperty type, DgnFontCP value)
           {
           return self.SetProperty(type, value);
           }, "type"_a, "value"_a);
    

    c4.def_static("GetByID", &DgnTextStyle::GetByID, "styleID"_a, "file"_a, DOC(Bentley, DgnPlatform, DgnTextStyle, GetByID));
    c4.def_static("GetByName", py::overload_cast<WCharCP, DgnFileR>(&DgnTextStyle::GetByName), "name"_a, "file"_a, DOC(Bentley, DgnPlatform, DgnTextStyle, GetByName));
    c4.def_static("ExistsByName", &DgnTextStyle::ExistsByName, "name"_a, "file"_a, DOC(Bentley, DgnPlatform, DgnTextStyle, ExistsByName));
    c4.def_static("BuildList", py::overload_cast<DgnFileR>(&DgnTextStyle::BuildList), "file"_a, DOC(Bentley, DgnPlatform, DgnTextStyle, BuildList));
    c4.def("Add", py::overload_cast<DgnFileP>(&DgnTextStyle::Add), "file"_a = nullptr, DOC(Bentley, DgnPlatform, DgnTextStyle, Add));
    c4.def_static("Delete", &DgnTextStyle::Delete, "name"_a, "file"_a, DOC(Bentley, DgnPlatform, DgnTextStyle, Delete));
    c4.def("HasDependants", &DgnTextStyle::HasDependants, DOC(Bentley, DgnPlatform, DgnTextStyle, HasDependants));
    c4.def_static("RemapDependents", &DgnTextStyle::RemapDependents, "destStyle"_a, "sourceStyle"_a, "file"_a, DOC(Bentley, DgnPlatform, DgnTextStyle, RemapDependents));
    c4.def("Replace", &DgnTextStyle::Replace, "oldName"_a = nullptr, "file"_a = nullptr, DOC(Bentley, DgnPlatform, DgnTextStyle, Replace));
    c4.def("Copy", &DgnTextStyle::Copy, DOC(Bentley, DgnPlatform, DgnTextStyle, Copy));
    c4.def("CopyValues", py::overload_cast<DgnTextStyleCR>(&DgnTextStyle::CopyValues), "style"_a, DOC(Bentley, DgnPlatform, DgnTextStyle, CopyValues));
    c4.def_static("GetSettings", &DgnTextStyle::GetSettings, "file"_a, DOC(Bentley, DgnPlatform, DgnTextStyle, GetSettings));
    c4.def_static("ReplaceSettings", &DgnTextStyle::ReplaceSettings, "style"_a, "file"_a, DOC(Bentley, DgnPlatform, DgnTextStyle, ReplaceSettings));

    //===================================================================================
    // struct TextStyleCollection
    py::class_< TextStyleCollection> c5(m, "TextStyleCollection");

    c5.def(py::init<DgnFileR>(), "file"_a);
    c5.def("__iter__", [] (TextStyleCollection& self) { return py::make_iterator(self.begin(), self.end()); }, py::keep_alive<0, 1>());
    }