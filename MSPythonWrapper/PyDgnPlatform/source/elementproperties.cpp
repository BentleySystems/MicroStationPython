/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnPlatform\source\elementproperties.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <DgnPlatform/ElementProperties.h>



static const char * __doc_Bentley_DgnPlatform_ElementPropertiesSetter_ApplyTemplate =R"doc(Set element properties to match properties of the supplied template
element.

Parameter ``eeh``:
    The element to change the properties of.

Parameter ``templateEh``:
    The element to match the properties of. @note The template element
    is expected to be from the same model as the element to change.)doc";

static const char * __doc_Bentley_DgnPlatform_ElementPropertiesSetter_ApplyElemDisplayParams =R"doc(Set element properties using the supplied ElemDisplayParams.

Parameter ``eeh``:
    The element to change the properties of.

Parameter ``params``:
    The ElemDisplayParams to apply.)doc";

static const char * __doc_Bentley_DgnPlatform_ElementPropertiesSetter_SetLocked =R"doc(Assign or clear the locked flag of the supplied element.

Parameter ``eeh``:
    The element to change the properties of.

Parameter ``locked``:
    the locked flag to use.)doc";

static const char * __doc_Bentley_DgnPlatform_ElementPropertiesSetter_SetGraphicGroup =R"doc(Assign or clear the graphic group number of the supplied element.

Parameter ``eeh``:
    The element to change the properties of.

Parameter ``gg``:
    the graphic group number to use, 0 to remove element from group.)doc";

static const char * __doc_Bentley_DgnPlatform_ElementPropertiesSetter_SetChangeEntireElement =R"doc(Whether to change just the base property values or all property values
for a specified property type. Some elements like dimensions, text,
and multilines store more than one color, style, etc. It is also
possible that no part of the element displays using the base property
value.

Parameter ``changeAll``:
    true to change all property values. @note The default behavior is
    to just change the base property values,
    PROPSCALLBACK_FLAGS_IsBaseID.

See also:
    PropsCallbackFlags)doc";

static const char * __doc_Bentley_DgnPlatform_ElementPropertiesSetter_SetFont =R"doc(Set remapper object to change the font of an element.

Parameter ``font``:
    the new font to use @note If the element supports and has an SHX
    big font, it will be removed, and the provided font will be the
    sole font used by the element.)doc";

static const char * __doc_Bentley_DgnPlatform_ElementPropertiesSetter_SetThickness =R"doc(Set remapper object to change the thickness of an element. Thickness
is used to display planar elements as extrusions in 3d when the view
is not aligned with the extrude direction bvector.

Parameter ``thickness``:
    New thickness value.

Parameter ``direction``:
    Extrude direction, required for lines, optional for elements with
    well defined normal.

Parameter ``isCapped``:
    true to display closed curves as capped solids instead of surface.

Parameter ``alwaysUseDirection``:
    true to use direction even for elements with a well defined normal
    (skewed extrusions). @note This property is supported by simple
    open and closed curves, text, and multilines.)doc";

static const char * __doc_Bentley_DgnPlatform_ElementPropertiesSetter_SetTransparency =R"doc(Set remapper object to change the transparency of an element.

Parameter ``transparency``:
    New transparency value, 0.0 for fully opaque.)doc";

static const char * __doc_Bentley_DgnPlatform_ElementPropertiesSetter_SetDisplayPriority =R"doc(Set remapper object to change the display priority of an element.

Parameter ``priority``:
    New display priority value. @note Only applicable for 2d elements,
    will be ignored by 3d elements.)doc";

static const char * __doc_Bentley_DgnPlatform_ElementPropertiesSetter_SetElementClass =R"doc(Set remapper object to change the class type of an element.

Parameter ``elmClass``:
    New element class (Typically just primary/construction).)doc";

static const char * __doc_Bentley_DgnPlatform_ElementPropertiesSetter_SetLevel =R"doc(Set remapper object to change the level of an element.

Parameter ``level``:
    New level id.)doc";

static const char * __doc_Bentley_DgnPlatform_ElementPropertiesSetter_SetWeight =R"doc(Set remapper object to change the weight of an element.

Parameter ``weight``:
    New weight value.)doc";

static const char * __doc_Bentley_DgnPlatform_ElementPropertiesSetter_SetLinestyle =R"doc(Set remapper object to change the linestyle of an element.

Parameter ``style``:
    New linestyle id.

Parameter ``lsParams``:
    Modifiers for custom linestyle (or NULL).)doc";

static const char * __doc_Bentley_DgnPlatform_ElementPropertiesSetter_SetFillColor =R"doc(Set remapper object to change just the solid fill color of an element.

Parameter ``fillColor``:
    New fill color value. @note Will not add fill to an element that
    is currently un-filled. Fill colors announced to color callback
    using PROPSCALLBACK_FLAGS_IsBackgroundID.

See also:
    IAreaFillPropertiesEdit)doc";

static const char * __doc_Bentley_DgnPlatform_ElementPropertiesSetter_SetColor =R"doc(Set remapper object to change the colors of an element.

Parameter ``color``:
    New color value. @note For opaque filled elements changing the
    element color will also change the fill color so that it continues
    to match the outline color. The same behavior is also true for
    patterns/hatches.)doc";

static const char * __doc_Bentley_DgnPlatform_ElementPropertiesSetter_Apply =R"doc(Apply the property values supplied through the various set methods to
the input element.

Parameter ``eeh``:
    The element to change the properties of.

Returns:
    true if the element was changed.)doc";

static const char * __doc_Bentley_DgnPlatform_ElementPropertiesGetter_GetLocked =R"doc(Get the locked flag of the supplied element.

Parameter ``eh``:
    The element to get the locked property of.

Returns:
    true if locked bit is set.)doc";

static const char * __doc_Bentley_DgnPlatform_ElementPropertiesGetter_GetGraphicGroup =R"doc(Get the graphic group number of the supplied element.

Parameter ``eh``:
    The element to get the graphic group number of.

Returns:
    graphic group number of the supplied element.)doc";

static const char * __doc_Bentley_DgnPlatform_ElementPropertiesGetter_GetThickness =R"doc(Get element extrude thickness.)doc";

static const char * __doc_Bentley_DgnPlatform_ElementPropertiesGetter_GetTransparency =R"doc(Get element transparency.)doc";

static const char * __doc_Bentley_DgnPlatform_ElementPropertiesGetter_GetDisplayPriority =R"doc(Get element display priority (2d only).)doc";

static const char * __doc_Bentley_DgnPlatform_ElementPropertiesGetter_GetElementClass =R"doc(Get element class.)doc";

static const char * __doc_Bentley_DgnPlatform_ElementPropertiesGetter_GetLevel =R"doc(Get element level.)doc";

static const char * __doc_Bentley_DgnPlatform_ElementPropertiesGetter_GetWeight =R"doc(Get element weight.)doc";

static const char * __doc_Bentley_DgnPlatform_ElementPropertiesGetter_GetLineStyle =R"doc(Get element linestyle and modifiers (optional).)doc";

static const char * __doc_Bentley_DgnPlatform_ElementPropertiesGetter_GetColor =R"doc(Get element color id.)doc";

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_ElementProperties(py::module_& m)
    {
    //===================================================================================
    // struct ElementPropertiesGetter
    py::class_< ElementPropertiesGetter, ElementPropertiesGetterPtr> c1(m, "ElementPropertiesGetter");

    c1.def(py::init(&ElementPropertiesGetter::Create), "eh"_a);
    
    c1.def_property_readonly("Color", &ElementPropertiesGetter::GetColor);
    c1.def("GetColor", &ElementPropertiesGetter::GetColor, DOC(Bentley, DgnPlatform, ElementPropertiesGetter, GetColor));
    
    c1.def_property_readonly("LineStyle", [] (ElementPropertiesGetter const& self) { return self.GetLineStyle(nullptr); });
    c1.def("GetLineStyle", &ElementPropertiesGetter::GetLineStyle, "lsParam"_a = nullptr, DOC(Bentley, DgnPlatform, ElementPropertiesGetter, GetLineStyle));
    
    c1.def_property_readonly("Weight", &ElementPropertiesGetter::GetWeight);
    c1.def("GetWeight", &ElementPropertiesGetter::GetWeight, DOC(Bentley, DgnPlatform, ElementPropertiesGetter, GetWeight));
    
    c1.def_property_readonly("Level", &ElementPropertiesGetter::GetLevel);
    c1.def("GetLevel", &ElementPropertiesGetter::GetLevel, DOC(Bentley, DgnPlatform, ElementPropertiesGetter, GetLevel));
    
    c1.def_property_readonly("ElementClass", &ElementPropertiesGetter::GetElementClass);
    c1.def("GetElementClass", &ElementPropertiesGetter::GetElementClass, DOC(Bentley, DgnPlatform, ElementPropertiesGetter, GetElementClass));
    
    c1.def_property_readonly("DisplayPriority", &ElementPropertiesGetter::GetDisplayPriority);
    c1.def("GetDisplayPriority", &ElementPropertiesGetter::GetDisplayPriority, DOC(Bentley, DgnPlatform, ElementPropertiesGetter, GetDisplayPriority));
    
    c1.def_property_readonly("Transparency", &ElementPropertiesGetter::GetTransparency);
    c1.def("GetTransparency", &ElementPropertiesGetter::GetTransparency, DOC(Bentley, DgnPlatform, ElementPropertiesGetter, GetTransparency));

    c1.def_property_readonly("Thickness", [] (ElementPropertiesGetter const& self)
                             {
                             bool isCapped = false;
                             DVec3d dir = *self.GetThickness(isCapped);
                             return py::make_tuple(dir, isCapped);
                             });
    c1.def("GetThickness", [] (ElementPropertiesGetter const& self)
                             {
                             bool isCapped = false;
                             DVec3d dir = *self.GetThickness(isCapped);
                             return py::make_tuple(dir, isCapped);
                             }, DOC(Bentley, DgnPlatform, ElementPropertiesGetter, GetThickness));

    c1.def_static("GetGraphicGroup", &ElementPropertiesGetter::GetGraphicGroup, "eh"_a, DOC(Bentley, DgnPlatform, ElementPropertiesGetter, GetGraphicGroup));
    c1.def_static("GetLocked", &ElementPropertiesGetter::GetLocked, "eh"_a, DOC(Bentley, DgnPlatform, ElementPropertiesGetter, GetLocked));

    //===================================================================================
    // struct ElementPropertiesSetter
    py::class_< ElementPropertiesSetter, ElementPropertiesSetterPtr> c2(m, "ElementPropertiesSetter");

    c2.def(py::init(&ElementPropertiesSetter::Create));
    c2.def("Apply", &ElementPropertiesSetter::Apply, "eeh"_a, DOC(Bentley, DgnPlatform, ElementPropertiesSetter, Apply));

    c2.def_property("Color", nullptr, &ElementPropertiesSetter::SetColor);
    c2.def("SetColor", &ElementPropertiesSetter::SetColor, "color"_a, DOC(Bentley, DgnPlatform, ElementPropertiesSetter, SetColor));
    
    c2.def_property("FillColor", nullptr, &ElementPropertiesSetter::SetFillColor);
    c2.def("SetFillColor", &ElementPropertiesSetter::SetFillColor, "fillColor"_a, DOC(Bentley, DgnPlatform, ElementPropertiesSetter, SetFillColor));
    
    c2.def("SetLinestyle", &ElementPropertiesSetter::SetLinestyle, "style"_a, "lsParams"_a, DOC(Bentley, DgnPlatform, ElementPropertiesSetter, SetLinestyle));

    c2.def_property("Weight", nullptr, &ElementPropertiesSetter::SetWeight);
    c2.def("SetWeight", &ElementPropertiesSetter::SetWeight, "weight"_a, DOC(Bentley, DgnPlatform, ElementPropertiesSetter, SetWeight));
    
    c2.def_property("Level", nullptr, &ElementPropertiesSetter::SetLevel);
    c2.def("SetLevel", &ElementPropertiesSetter::SetLevel, "level"_a, DOC(Bentley, DgnPlatform, ElementPropertiesSetter, SetLevel));
    
    c2.def_property("ElementClass", nullptr, &ElementPropertiesSetter::SetElementClass);
    c2.def("SetElementClass", &ElementPropertiesSetter::SetElementClass, "elemClass"_a, DOC(Bentley, DgnPlatform, ElementPropertiesSetter, SetElementClass));
    
    c2.def_property("DisplayPriority", nullptr, &ElementPropertiesSetter::SetDisplayPriority);
    c2.def("SetDisplayPriority", &ElementPropertiesSetter::SetDisplayPriority, "priority"_a, DOC(Bentley, DgnPlatform, ElementPropertiesSetter, SetDisplayPriority));
    
    c2.def_property("Transparency", nullptr, &ElementPropertiesSetter::SetTransparency);
    c2.def("SetTransparency", &ElementPropertiesSetter::SetTransparency, "transparency"_a, DOC(Bentley, DgnPlatform, ElementPropertiesSetter, SetTransparency));
    
    c2.def("SetThickness", &ElementPropertiesSetter::SetThickness, "thickness"_a, "direction"_a, "isCapped"_a, "alwaysUseDirection"_a, DOC(Bentley, DgnPlatform, ElementPropertiesSetter, SetThickness));
    
    c2.def_property("Font", nullptr, &ElementPropertiesSetter::SetFont);
    c2.def("SetFont", &ElementPropertiesSetter::SetFont, "font"_a, DOC(Bentley, DgnPlatform, ElementPropertiesSetter, SetFont));
    
    c2.def_property("ChangeEntireElement", nullptr, &ElementPropertiesSetter::SetChangeEntireElement);
    c2.def("SetChangeEntireElement", &ElementPropertiesSetter::SetChangeEntireElement, "value"_a, DOC(Bentley, DgnPlatform, ElementPropertiesSetter, SetChangeEntireElement));
    
    c2.def_static("SetGraphicGroup", &ElementPropertiesSetter::SetGraphicGroup, "eeh"_a, "gg"_a, DOC(Bentley, DgnPlatform, ElementPropertiesSetter, SetGraphicGroup));
    c2.def_static("SetLocked", &ElementPropertiesSetter::SetLocked, "eeh"_a, "locked"_a, DOC(Bentley, DgnPlatform, ElementPropertiesSetter, SetLocked));
    c2.def_static("ApplyElemDisplayParams", &ElementPropertiesSetter::ApplyElemDisplayParams, "eeh"_a, "params"_a, DOC(Bentley, DgnPlatform, ElementPropertiesSetter, ApplyElemDisplayParams));
    c2.def_static("ApplyTemplate", &ElementPropertiesSetter::ApplyTemplate, "eeh"_a, "templateEh"_a, DOC(Bentley, DgnPlatform, ElementPropertiesSetter, ApplyTemplate));
    }