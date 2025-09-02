/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnPlatform\source\symbologyreporter.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <DgnPlatform/SymbologyReporter.h>



static const char * __doc_Bentley_DgnPlatform_SymbologyReporter_IsDimensionElement =R"doc(Return true if the element is a Dimension.)doc";

static const char * __doc_Bentley_DgnPlatform_SymbologyReporter_IsMultiLineElement =R"doc(Return true if the element is a Multi-Line.)doc";

static const char * __doc_Bentley_DgnPlatform_SymbologyReporter_IsDetailingSymbol =R"doc(Return true if the element is a Detailing Symbol.)doc";

static const char * __doc_Bentley_DgnPlatform_SymbologyReporter_IsRenderableElement =R"doc(Return true if the element can be rendered.)doc";

static const char * __doc_Bentley_DgnPlatform_SymbologyReporter_IsClosedElement =R"doc(Return true if the element is close element.)doc";

static const char * __doc_Bentley_DgnPlatform_SymbologyReporter_IsTextNode =R"doc(Return true if the element is a Text Node element.)doc";

static const char * __doc_Bentley_DgnPlatform_SymbologyReporter_IsText =R"doc(Return true if the element is a Text String element.)doc";

static const char * __doc_Bentley_DgnPlatform_SymbologyReporter_Is3dElement =R"doc(Return true if the element is a 3D element.)doc";

static const char * __doc_Bentley_DgnPlatform_SymbologyReporter_IsPointCell =R"doc(Return true if the element is a point cell.)doc";

static const char * __doc_Bentley_DgnPlatform_SymbologyReporter_IsSharedCell =R"doc(Return true if the element is a shared cell instance.)doc";

static const char * __doc_Bentley_DgnPlatform_SymbologyReporter_IsStandardCell =R"doc(Return true if the element is a standard cell instance.)doc";

static const char * __doc_Bentley_DgnPlatform_SymbologyReporter_GetPatternOrigin =R"doc(Return the pattern origin of a patterned closed element.


:param index:
    The index of the property. Pass 0 if the element is not a complex
    element. @Return SUCCESS if the property can be returned from the
    element.
Returns (Tuple, 0):
	retVal.

Returns (Tuple, 1):
	value. The pattern origin 

)doc";

static const char * __doc_Bentley_DgnPlatform_SymbologyReporter_GetPatternParams =R"doc(Return the pattern parameter of a patterned closed element.


:param index:
    The index of the property. Pass 0 if the element is not a complex
    element. 
Returns (Tuple, 0):
	retVal. SUCCESS if the property can be returned from the  element.

Returns (Tuple, 1):
	value.The pattern parameters to return.

)doc";

static const char * __doc_Bentley_DgnPlatform_SymbologyReporter_GetDetailingSymbolStylePath =R"doc(Return the path/name of the Detailing Symbol Style if the element is a
Detailing Symbol.


:param index:
    The index of the property. Pass 0 if the element is not a complex
    element. 
    
Returns (Tuple, 0):
	retVal. SUCCESS if the property can be returned from the  element.

Returns (Tuple, 1):
	value. If name of the detailing symbol style.

)doc";

static const char * __doc_Bentley_DgnPlatform_SymbologyReporter_GetAreaMode =R"doc(Return the AreaMode for a closed element. The Area mode designates the
element either as a solid or a hole.


:param index:
    The index of the property. Pass 0 if the element is not a complex
    element.
Returns (Tuple, 0):
	retVal. SUCCESS if the property can be returned from the  element.

Returns (Tuple, 1):
	value.  If true the element is considered a hole, if false the it is
    considered solid.


)doc";

static const char * __doc_Bentley_DgnPlatform_SymbologyReporter_GetFillColorIdOrGradientSpecification =R"doc(Return the Color Fill specificate if defined for a closed element. If
a fill color is specified it will be either a solid fill color ID or a
Gradient color specification.


:param index:
    The index of the property. Pass 0 if the element is not a complex
    element. 

Returns (Tuple, 0):
	retVal. SUCCESS if the property can be returned from the  element.

Returns (Tuple, 1):
	value. Solid fill color ID to return.
Returns (Tuple, 2):
	value. Gradient color specification return.
)doc";

static const char * __doc_Bentley_DgnPlatform_SymbologyReporter_GetCellName =R"doc(Return the Cell Name if the element is a named cell.

:param index:
    For future use. Pass 0 for index, or do not pass paramter and
    allow the default of 0 to be used.    
Returns (Tuple, 0):
	retVal. SUCCESS if the property can be returned from the  element.

Returns (Tuple, 1):
	value. The cell name to return.

)doc";
static const char * __doc_Bentley_DgnPlatform_SymbologyReporter_GetAnnotationScale =R"doc(Return the Annotation Scale of the element if the element supports
annotation scale.

:param index:
    The index of the property. Pass 0 if the element is not a complex
    element.     
Returns (Tuple, 0):
	retVal. SUCCESS if the property can be returned from the  element.

Returns (Tuple, 1):
	value.The scale value to return.

)doc";
static const char * __doc_Bentley_DgnPlatform_SymbologyReporter_GetScale =R"doc(Return the Scale of the element if the element supports scaling.


:param index:
    The index of the property. Pass 0 if the element is not a complex
    element.    
Returns (Tuple, 0):
	retVal. SUCCESS if the property can be returned from the  element.

Returns (Tuple, 1):
	value. The scale value to return.

)doc";
static const char * __doc_Bentley_DgnPlatform_SymbologyReporter_GetElementTemplateID =R"doc(Return the ID of the element template associate with the element.


:param index:
    The index of the property. Pass 0 if the element is not a complex
    element.     
Returns (Tuple, 0):
	retVal. SUCCESS if the property can be returned from the  element.

Returns (Tuple, 1):
	value. The ID of the element template to return.

)doc";
static const char * __doc_Bentley_DgnPlatform_SymbologyReporter_GetTransparency =R"doc(Return the transparency value of the element.


:param index:
    The index of the property. Pass 0 if the element is not a complex
    element.     
Returns (Tuple, 0):
	retVal. SUCCESS if the property can be returned from the  element.

Returns (Tuple, 1):
	value.  The transparency value.

)doc";
static const char * __doc_Bentley_DgnPlatform_SymbologyReporter_GetDisplayPriority =R"doc(Return the display of the element. This is only applicable to elements
in 2D models.

:param index:
    The index of the property. Pass 0 if the element is not a complex
    element.    
Returns (Tuple, 0):
	retVal. SUCCESS if the property can be returned from the  element.

Returns (Tuple, 1):
	value. The display priority of the element.

)doc";
static const char * __doc_Bentley_DgnPlatform_SymbologyReporter_GetElementClass =R"doc(Return the class of the element.


:param index:
    The index of the property. Pass 0 if the element is not a complex
    element.     
Returns (Tuple, 0):
	retVal. SUCCESS if the property can be returned from the  element.

Returns (Tuple, 1):
	value. The element class to return. The possible values are defined in
    the enum .

)doc";
static const char * __doc_Bentley_DgnPlatform_SymbologyReporter_GetWeight =R"doc(Return the line weight.

:param index:
    The index of the property. Pass 0 if the element is not a complex
    element.     
Returns (Tuple, 0):
	retVal. SUCCESS if the property can be returned from the  element.

Returns (Tuple, 1):
	value.  The line weight to return

)doc";
static const char * __doc_Bentley_DgnPlatform_SymbologyReporter_GetMaterialId =R"doc(Return the Material ID if the element contains a material
specification.


:param index:
    The index of the property. Pass 0 if the element is not a complex
    element.    
Returns (Tuple, 0):
	retVal. SUCCESS if the property can be returned from the  element.

Returns (Tuple, 1):
	value. The Material Id to return

)doc";
static const char * __doc_Bentley_DgnPlatform_SymbologyReporter_GetMlineStyleID =R"doc(Return the ID of the Multi-Line Style if the element is a Multi-line
element.


:param index:
    The index of the property. Pass 0 if the element is not a complex
    element.     
Returns (Tuple, 0):
	retVal. SUCCESS if the property can be returned from the  element.

Returns (Tuple, 1):
	value.  The Multi-Line Style Id to return

)doc";
static const char * __doc_Bentley_DgnPlatform_SymbologyReporter_GetLineStyleParams =R"doc(Return the LineStyle Parameters if the element uses a named line
style.


:param index:
    The index of the property. Pass 0 if the element is not a complex
    element.    
Returns (Tuple, 0):
	retVal. SUCCESS if the property can be returned from the  element.

Returns (Tuple, 1):
	value.The LineStyle Parameters to return. 

)doc";
static const char * __doc_Bentley_DgnPlatform_SymbologyReporter_GetDimStyleID =R"doc(Return the ID of the Dimension Style if the element is a dimension
element.


:param index:
    The index of the property. Pass 0 if the element is not a complex
    element.     
Returns (Tuple, 0):
	retVal. SUCCESS if the property can be returned from the  element.

Returns (Tuple, 1):
	value.  The Dimension Style Id to return

)doc";
static const char * __doc_Bentley_DgnPlatform_SymbologyReporter_GetLineStyleID =R"doc(Return the ID of the LineStyle.


:param index:
    The index of the property. Pass 0 if the element is not a complex
    element.    
Returns (Tuple, 0):
	retVal. SUCCESS if the property can be returned from the  element.

Returns (Tuple, 1):
	value.  The LineStyle Id to return

)doc";
static const char * __doc_Bentley_DgnPlatform_SymbologyReporter_GetTextStyleId =R"doc(Return the ID of the TextStyle if the element contains text.

:param index:
    The index of the property. Pass 0 if the element is not a complex
    element.    
Returns (Tuple, 0):
	retVal. SUCCESS if the property can be returned from the  element.

Returns (Tuple, 1):
	value. The TextStyle Id to return

)doc";
static const char * __doc_Bentley_DgnPlatform_SymbologyReporter_GetColorID =R"doc(Return the ID of the element color. This value can be passed as the
element color into DgnColorMap::ExtractElementColorInfo to get more
specific color information.

:param index:
    The index of the property. Pass 0 if the element is not a complex
    element.     
Returns (Tuple, 0):
	retVal. SUCCESS if the property can be returned from the  element.

Returns (Tuple, 1):
	value. The colorID to return

)doc";
static const char * __doc_Bentley_DgnPlatform_SymbologyReporter_GetFontID =R"doc(Return the ID of the font if the element contains text.


:param index:
    The index of the property. Pass 0 if the element is not a complex
    element.     
Returns (Tuple, 0):
	retVal. SUCCESS if the property can be returned from the  element.

Returns (Tuple, 1):
	value.   The FontId to return

)doc";

static const char * __doc_Bentley_DgnPlatform_SymbologyReporter_GetLevelId =R"doc(Return the level ID.

:param index:
    The index of the property. Pass 0 if the element is not a complex
    element.     
Returns (Tuple, 0):
	retVal. SUCCESS if the property can be returned from the  element.

Returns (Tuple, 1):
	value.   The LevelId

)doc";

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_SymbologyReporter(py::module_& m)
    {
    //===================================================================================
    // struct SymbologyReporter
    py::class_< SymbologyReporter, IQueryProperties> c1(m, "SymbologyReporter");


    c1.def(py::init<ElementHandleCR>(), "eh"_a);

    c1.def("GetLevelId", [] (SymbologyReporter& self, UInt index)
           {
           LevelId value;
           auto retVal = self.GetLevelId(value, index);
           return py::make_tuple(retVal, value);
           }, "index"_a = 0, DOC(Bentley, DgnPlatform, SymbologyReporter, GetLevelId));

    c1.def("GetFontID", [] (SymbologyReporter& self, UInt index)
           {
           UInt32 value;
           auto retVal = self.GetFontID(value, index);
           return py::make_tuple(retVal, value);
           }, "index"_a = 0, DOC(Bentley, DgnPlatform, SymbologyReporter, GetFontID));

    c1.def("GetColorID", [] (SymbologyReporter& self, UInt index)
           {
           UInt32 value;
           auto retVal = self.GetColorID(value, index);
           return py::make_tuple(retVal, value);
           }, "index"_a = 0, DOC(Bentley, DgnPlatform, SymbologyReporter, GetColorID));

    c1.def("GetTextStyleId", [] (SymbologyReporter& self, UInt index)
           {
           UInt32 value;
           auto retVal = self.GetTextStyleId(value, index);
           return py::make_tuple(retVal, value);
           }, "index"_a = 0, DOC(Bentley, DgnPlatform, SymbologyReporter, GetTextStyleId));

    c1.def("GetLineStyleID", [] (SymbologyReporter& self, UInt index)
           {
           Int32 value;
           auto retVal = self.GetLineStyleID(value, index);
           return py::make_tuple(retVal, value);
           }, "index"_a = 0, DOC(Bentley, DgnPlatform, SymbologyReporter, GetLineStyleID));

    c1.def("GetDimStyleID", [] (SymbologyReporter& self, UInt index)
           {
           ElementId value;
           auto retVal = self.GetDimStyleID(value, index);
           return py::make_tuple(retVal, value);
           }, "index"_a = 0, DOC(Bentley, DgnPlatform, SymbologyReporter, GetDimStyleID));

    c1.def("GetLineStyleParams", [] (SymbologyReporter& self, UInt index)
           {
           LineStyleParams value;
           auto retVal = self.GetLineStyleParams(value, index);
           return py::make_tuple(retVal, value);
           }, "index"_a = 0, DOC(Bentley, DgnPlatform, SymbologyReporter, GetLineStyleParams));

    c1.def("GetMlineStyleID", [] (SymbologyReporter& self, UInt index)
           {
           ElementId value;
           auto retVal = self.GetMlineStyleID(value, index);
           return py::make_tuple(retVal, value);
           }, "index"_a = 0, DOC(Bentley, DgnPlatform, SymbologyReporter, GetMlineStyleID));

    c1.def("GetMaterialId", [] (SymbologyReporter& self, UInt index)
           {
           MaterialId value;
           auto retVal = self.GetMaterialId(value, index);
           return py::make_tuple(retVal, value);
           }, "index"_a = 0, DOC(Bentley, DgnPlatform, SymbologyReporter, GetMaterialId));

    c1.def("GetWeight", [] (SymbologyReporter& self, UInt index)
           {
           UInt32 value;
           auto retVal = self.GetWeight(value, index);
           return py::make_tuple(retVal, value);
           }, "index"_a = 0, DOC(Bentley, DgnPlatform, SymbologyReporter, GetWeight));

    c1.def("GetElementClass", [] (SymbologyReporter& self, UInt index)
           {
           DgnElementClass value;
           auto retVal = self.GetElementClass(value, index);
           return py::make_tuple(retVal, value);
           }, "index"_a = 0, DOC(Bentley, DgnPlatform, SymbologyReporter, GetElementClass));

    c1.def("GetDisplayPriority", [] (SymbologyReporter& self, UInt index)
           {
           Int32 value;
           auto retVal = self.GetDisplayPriority(value, index);
           return py::make_tuple(retVal, value);
           }, "index"_a = 0, DOC(Bentley, DgnPlatform, SymbologyReporter, GetDisplayPriority));

    c1.def("GetTransparency", [] (SymbologyReporter& self, UInt index)
           {
           double value;
           auto retVal = self.GetTransparency(value, index);
           return py::make_tuple(retVal, value);
           }, "index"_a = 0, DOC(Bentley, DgnPlatform, SymbologyReporter, GetTransparency));

    c1.def("GetElementTemplateID", [] (SymbologyReporter& self, UInt index)
           {
           ElementId value;
           auto retVal = self.GetElementTemplateID(value, index);
           return py::make_tuple(retVal, value);
           }, "index"_a = 0, DOC(Bentley, DgnPlatform, SymbologyReporter, GetElementTemplateID));

    c1.def("GetScale", [] (SymbologyReporter& self, UInt index)
           {
           DPoint3d value;
           auto retVal = self.GetScale(value, index);
           return py::make_tuple(retVal, value);
           }, "index"_a = 0, DOC(Bentley, DgnPlatform, SymbologyReporter, GetScale));

    c1.def("GetAnnotationScale", [] (SymbologyReporter& self, UInt index)
           {
           double value;
           auto retVal = self.GetAnnotationScale(value, index);
           return py::make_tuple(retVal, value);
           }, "index"_a = 0, DOC(Bentley, DgnPlatform, SymbologyReporter, GetAnnotationScale));

    c1.def("GetCellName", [] (SymbologyReporter& self, UInt index)
           {
           WString value;
           auto retVal = self.GetCellName(value, index);
           return py::make_tuple(retVal, value);
           }, "index"_a = 0, DOC(Bentley, DgnPlatform, SymbologyReporter, GetCellName));

    c1.def("GetFillColorIdOrGradientSpecification", [] (SymbologyReporter& self, UInt index)
           {
           UInt32 value;
           GradientSymbPtr value1;
           auto retVal = self.GetFillColorIdOrGradientSpecification(value, value1, index);
           return py::make_tuple(retVal, value, value1);
           }, "index"_a = 0, DOC(Bentley, DgnPlatform, SymbologyReporter, GetFillColorIdOrGradientSpecification));

    c1.def("GetAreaMode", [] (SymbologyReporter& self, UInt index)
           {
           bool value;
           auto retVal = self.GetAreaMode(value, index);
           return py::make_tuple(retVal, value);
           }, "index"_a = 0, DOC(Bentley, DgnPlatform, SymbologyReporter, GetAreaMode));

    c1.def("GetDetailingSymbolStylePath", [] (SymbologyReporter& self, UInt index)
           {
           WString value;
           auto retVal = self.GetDetailingSymbolStylePath(value, index);
           return py::make_tuple(retVal, value);
           }, "index"_a = 0, DOC(Bentley, DgnPlatform, SymbologyReporter, GetDetailingSymbolStylePath));

    c1.def("GetPatternParams", [] (SymbologyReporter& self, UInt index)
           {
           auto value = PatternParams::Create();
           auto retVal = self.GetPatternParams(*value, index);
           return py::make_tuple(retVal, value);
           }, "index"_a = 0, DOC(Bentley, DgnPlatform, SymbologyReporter, GetPatternParams));

    c1.def("GetPatternOrigin", [] (SymbologyReporter& self, UInt index)
           {
           DPoint3d value;
           auto retVal = self.GetPatternOrigin(value, index);
           return py::make_tuple(retVal, value);
           }, "index"_a = 0, DOC(Bentley, DgnPlatform, SymbologyReporter, GetPatternOrigin));

    c1.def("IsStandardCell", &SymbologyReporter::IsStandardCell, DOC(Bentley, DgnPlatform, SymbologyReporter, IsStandardCell));
    c1.def("IsSharedCell", &SymbologyReporter::IsSharedCell, DOC(Bentley, DgnPlatform, SymbologyReporter, IsSharedCell));
    c1.def("IsPointCell", &SymbologyReporter::IsPointCell, DOC(Bentley, DgnPlatform, SymbologyReporter, IsPointCell));
    c1.def("Is3dElement", &SymbologyReporter::Is3dElement, DOC(Bentley, DgnPlatform, SymbologyReporter, Is3dElement));
    c1.def("IsText", &SymbologyReporter::IsText, DOC(Bentley, DgnPlatform, SymbologyReporter, IsText));
    c1.def("IsTextNode", &SymbologyReporter::IsTextNode, DOC(Bentley, DgnPlatform, SymbologyReporter, IsTextNode));
    c1.def("IsClosedElement", &SymbologyReporter::IsClosedElement, DOC(Bentley, DgnPlatform, SymbologyReporter, IsClosedElement));
    c1.def("IsRenderableElement", &SymbologyReporter::IsRenderableElement, DOC(Bentley, DgnPlatform, SymbologyReporter, IsRenderableElement));
    c1.def("IsDetailingSymbol", &SymbologyReporter::IsDetailingSymbol, DOC(Bentley, DgnPlatform, SymbologyReporter, IsDetailingSymbol));
    c1.def("IsMultiLineElement", &SymbologyReporter::IsMultiLineElement, DOC(Bentley, DgnPlatform, SymbologyReporter, IsMultiLineElement));
    c1.def("IsDimensionElement", &SymbologyReporter::IsDimensionElement, DOC(Bentley, DgnPlatform, SymbologyReporter, IsDimensionElement));
    }