/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnPlatform\source\dgncolormap.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <DgnPlatform/DgnColorMap.h>



static const char * __doc_Bentley_DgnPlatform_DgnColorMap_CreateElementColor =R"doc(Get a element color id that can be stored on an element from the
supplied IntColorDef.

:param colorDef:
    Color table name.

:param bookName:
    Color book name for the supplied IntColorDef (can be NULL).

:param colorName:
    Color name in color book of the supplied IntColorDef (can be
    NULL).

:param dgnFile:
    The file for the new element color. @note A valid element color id
    is one of the following: COLOR_BYLEVEL  COLOR_BYCELL  An
    index into a files DgnColorMap (value from 0 to INDEX_Background).
     A color book or rgb color id as returned by
    CreateElementColor.

:returns:
    element color or INVALID_COLOR.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnColorMap_ExtractElementColorInfo =R"doc(Get the color information from the supplied element color id.



:param elementColor:
    The element color to extract the information for.

:param dgnFile:
    The file for the supplied element color.

Returns (Tuple, 0):
    SUCCESS if element color is a valid rgb, book, or DgnColorMap
    index. COLOR_BYLEVEL or COLOR_BYCELL will return ERROR.

Returns (Tuple, 1) :
	colorDef.

Returns (Tuple, 2):
	colorIndex.

Returns (Tuple. 3) :
	isTrueColor.

Returns (Tuple, 4):
	bookName.

Returns (Tuple, 5):
	colorName.
)doc";

static const char * __doc_Bentley_DgnPlatform_DgnColorMap_GetColorTableDescription =R"doc(Called to get the name string associated with the files color table.

:param name:
    color table name.

:param bufferSize:
    length of name buffer.

:param dgnFile:
    The file to return the color map for.

:returns:
    SUCCESS if file isn't using a default color table.
    @DotNetMethodParameterIsReturnString{name,bufferSize})doc";

static const char * __doc_Bentley_DgnPlatform_DgnColorMap_GetForFile =R"doc(Called to get the color map used for a dgn file.

:param dgnFile:
    The file to return the color map for.

Remark:
    s This is the stored or default color map for the file, it is used
    by all models.

:returns:
    The color map, should never be NULL for a valid dgnFile object.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnColorMap_GetForDisplay =R"doc(Called to get the color map used to display the specified modelRef.

:param modelRef:
    The modelRef to return the color map for.

Remark:
    s This color map may differ from the file color map for a
    reference modelRef. A reference can have an adjusted color map,
    also the preference to use the reference color map may be
    disabled.

:returns:
    The color map, should never be NULL for a valid modelRef.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnColorMap_CreateDefaultForFileType =R"doc(Create new default color map for a particular file format type.

:param format:
    type of file, DgnFileFormatType::DWG, DgnFileFormatType::DXF,
    DgnFileFormatType::V8, etc.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnColorMap_CreateFromTbgrColors =R"doc(Create new color map from array of TBGR.

:param colors:
    Array of TBGR of size INDEX_ColorCount.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnColorMap_CreateFromRgbColors =R"doc(Create new color map from array of RgbColorDef.

:param colors:
    Array of RBGColorDef of size INDEX_ColorCount.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnColorMap_SetForFile =R"doc(Called to change the color table for the supplied dgn file.

:param dgnFile:
    The file to set the color map for.

:param name:
    Description to store for color table.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnColorMap_FindClosestMatch =R"doc(Called to return the element color index of the closest matching color
map entry to the supplied IntColorDef.

:param colorDef:
    Color to find the closest match for.

:param preComputedHSVTable:
    Optional hsv map for this color table (will be computed if NULL).

See also:
    GetHsvColors.

:returns:
    Element color index for closest match.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnColorMap_GetColor =R"doc(Called to return the information for a specific color index as an
IntColorDef.

:param index:
    Which color index to return the color information for.

Remark:
    s An index of -1 can also be used to return the background color,
    INDEX_Background. The IntColorDef is convenient for accessing the
    color either as a TBGR or as an RgbColorDef.

:returns:
    IntColor for specified color index.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnColorMap_GetHsvColors =R"doc(Called to return color map entries converted to an array of
HsvColorDef.

:param colors:
    Array of HsvColorDef of size INDEX_ColorCount

Remark:
    s Generally used by some older api functions, background color is
    expected to be index 0.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnColorMap_GetRgbColors =R"doc(Called to return color map entries converted to an array of
RgbColorDef.

:param colors:
    Array of RBGColorDef of size INDEX_ColorCount

Remark:
    s Generally used by some older api functions, background color is
    expected to be index 0.)doc";

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_DgnColorMap(py::module_& m)
    {
    //===================================================================================
    // union IntColorDef
    py::class_<IntColorDef> c0(m, "IntColorDef");

    c0.def_property("m_rgb", 
                    [](IntColorDef& self) {return self.m_rgb;}, 
                    [](IntColorDef& self, RgbColorDef const& value){self.m_rgb = value;});
    c0.def_property("m_rgba",
                    [](IntColorDef& self) {return self.m_rgba; },
                    [](IntColorDef& self, RgbaColorDef const& value) {self.m_rgba = value;});
    c0.def_property("m_int",
                    [](IntColorDef& self) {return self.m_int; },
                    [](IntColorDef& self, UInt32 const& value) {self.m_int = value;});

    c0.def("SetColors", &IntColorDef::SetColors, "r"_a, "g"_a, "b"_a, "a"_a);
    c0.def(py::init<>());
    c0.def(py::init<RgbColorDef>(), "rgb"_a);
    c0.def(py::init<UInt32>(), "intval"_a);
    c0.def(py::init<Byte, Byte, Byte>(), "red"_a, "green"_a, "blue"_a);
    c0.def(py::init<Byte, Byte, Byte, Byte>(), "red"_a, "green"_a, "blue"_a, "alpha"_a);
    
    // struct DgnColorMap
    py::class_<DgnColorMap, DgnColorMapPtr> c1(m, "DgnColorMap");

    if (true)
        {
        py::enum_<DgnColorMap::Entries>(c1, "Entries")
            .value("eINDEX_ColorCount", DgnColorMap::INDEX_ColorCount)
            .value("eINDEX_Background", DgnColorMap::INDEX_Background)
            .value("eINDEX_Invalid", DgnColorMap::INDEX_Invalid)
            .export_values();
        }

    c1.def("GetTbgrColors", [](DgnColorMap& self)
        {
        UInt32* colors = self.GetTbgrColorsP();

        BeAssert (colors != nullptr);

        const int INDEX_Count = 268;  //See DgnColorMap::INDEX_Count 
        UInt32Array* colorArrayP = new UInt32Array();

        for (int i = 0; i < INDEX_Count; i++)
            colorArrayP->push_back(*colors++);

        return std::unique_ptr<UInt32Array> (colorArrayP);
        });

    c1.def("SetTbgrColor", [](DgnColorMap& self, UInt32 val, UInt32 idx)
        {
            UInt32* colors = self.GetTbgrColorsP();

            BeAssert(colors != nullptr);

            const int INDEX_Count = 268;  //See DgnColorMap::INDEX_Count 
            if (idx >= INDEX_Count)
                return ERROR;

            colors[idx] = val;
            return SUCCESS;
        });

    c1.def("GetRgbColors", &DgnColorMap::GetRgbColors, "colors"_a, DOC(Bentley, DgnPlatform, DgnColorMap, GetRgbColors));
    c1.def("GetHsvColors", &DgnColorMap::GetHsvColors, "colors"_a, DOC(Bentley, DgnPlatform, DgnColorMap, GetHsvColors));
    c1.def("GetColor", &DgnColorMap::GetColor, py::return_value_policy::reference_internal, "index"_a, DOC(Bentley, DgnPlatform, DgnColorMap, GetColor));
    c1.def("FindClosestMatch", &DgnColorMap::FindClosestMatch, "colorDef"_a, "preComputedHSVTable"_a = nullptr, DOC(Bentley, DgnPlatform, DgnColorMap, FindClosestMatch));
    c1.def("SetForFile", &DgnColorMap::SetForFile, "dgnFile"_a, "name"_a, DOC(Bentley, DgnPlatform, DgnColorMap, SetForFile));

    c1.def_static("CreateFromRgbColors", [](std::vector<RgbColorDef> const& colors)
        {
        return DgnColorMap::CreateFromRgbColors(colors.data ());
        }, "colors"_a, DOC(Bentley, DgnPlatform, DgnColorMap, CreateFromRgbColors));

    c1.def_static("CreateFromRgbColors", [](py::list const& colors)
        {
        CONVERT_PYLIST_TO_NEW_CPPARRAY(colors, cppColors, std::vector<RgbColorDef>, RgbColorDef)
        return DgnColorMap::CreateFromRgbColors(cppColors.data ());
        }, "colors"_a, DOC(Bentley, DgnPlatform, DgnColorMap, CreateFromRgbColors));

    c1.def_static("CreateFromTbgrColors", [](UInt32Array& colors)
        {
        return DgnColorMap::CreateFromTbgrColors(colors.data());
        }, "colors"_a, DOC(Bentley, DgnPlatform, DgnColorMap, CreateFromTbgrColors));

    c1.def_static("CreateDefaultForFileType", &DgnColorMap::CreateDefaultForFileType, "format"_a, DOC(Bentley, DgnPlatform, DgnColorMap, CreateDefaultForFileType));
    c1.def_static("GetForDisplay", &DgnColorMap::GetForDisplay, py::return_value_policy::reference_internal, "modelRef"_a, DOC(Bentley, DgnPlatform, DgnColorMap, GetForDisplay));
    c1.def_static("GetForFile", &DgnColorMap::GetForFile, py::return_value_policy::reference_internal, "dgnFile"_a, DOC(Bentley, DgnPlatform, DgnColorMap, GetForFile));
    
    c1.def_static("GetColorTableDescription", [] (DgnFileP dgnFile)
                  {
                  wchar_t szName[2048] = {0};
                  py::str outVal;
                  auto retVal = DgnColorMap::GetColorTableDescription(szName, _countof(szName), dgnFile);
                  if (retVal == SUCCESS)
                      outVal = py::cast(szName);
                  return outVal;
                  }, "dgnFile"_a, DOC(Bentley, DgnPlatform, DgnColorMap, GetColorTableDescription));  

    c1.def_static("ExtractElementColorInfo", [] (UInt32 elementColor, DgnFileR dgnFile)
                  {
                  IntColorDef colorDef;
                  UInt32 colorIndex = 0;
                  bool isTrueColor = false;
                  WString bookName, colorName;
                  auto retVal = DgnColorMap::ExtractElementColorInfo(&colorDef, &colorIndex, &isTrueColor, &bookName, &colorName, elementColor, dgnFile);
                  return py::make_tuple(retVal, colorDef, colorIndex, isTrueColor, bookName, colorName);
                  }, "elementColor"_a, "dgnFile"_a, DOC(Bentley, DgnPlatform, DgnColorMap, ExtractElementColorInfo));

    c1.def_static("CreateElementColor", &DgnColorMap::CreateElementColor, "colorDef"_a, "bookName"_a, "colorName"_a, "dgnFile"_a, DOC(Bentley, DgnPlatform, DgnColorMap, CreateElementColor));
    }