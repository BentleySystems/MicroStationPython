/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnPlatform\source\dgnfontmanager.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <DgnPlatform/DgnFontManager.h>



static const char * __doc_Bentley_DgnPlatform_DgnGlyph_GetGPA =R"doc(Gets the GPA for this glyph; useful for exporting to other formats.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnFontManager_GetFontForCodePage =R"doc(Given two font numbers, returns the Font that should be used for code
page and encoding conversions.

Remark:
    s The general rule is that the big font is used if present,
    otherwise the small font. The font numbers are always resolved to
    what would be used to render the text for the given DgnFile.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnFontManager_CreateKnownFontList =R"doc(Create a FontList with the fonts in the system FontCatalogs,
optionally limited by a filter.

Parameter ``dgnFile``:
    If this argument is non-NULL, the FontList will also include any
    missing Fonts in the font table of this file.

Parameter ``filter``:
    A filter to limit list to only fonts of a certain category.

Returns:
    A Ptr to the newly created list.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnFontManager_VisitAllSystemFonts =R"doc(Visit all fonts in the system FontCatalogs, optionally with a filter
applied.

Parameter ``visitor``:
    The DgnFontVisitor to be called for each known font in the system.

Parameter ``filter``:
    A filter to limit visits to only fonts of interest.

Returns:
    true of ``visitor`` returned true to stop the traversal, false
    otherwise.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnFontManager_FindSystemFont =R"doc(Find a Font in the system FontCatalogs by name. The system catalogs
are initialized at startup and remain valid for the entire
MicroStation session. That is, for a given ``fontName,`` this method
will always return the same value if the Font exists.

Parameter ``fontName``:
    The name of the Font to find.

Parameter ``filter``:
    Limit the search to specific categories of Fonts.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnFontManager_ResolveFontNum =R"doc(Resolve a Font for a given DgnFile and font number. This is merely a
convenience routine that retrieves the DgnFontNumMap from the DgnFile
and calls DgnFontNumMap::ResolveFont on it.

Parameter ``fontNum``:
    The fontNumber of interest.

Parameter ``dgnFile``:
    The DgnFile of interest.

Returns:
    A reference to the Font or the default font if the font is not
    found.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnFontManager_GetFontByNumber =R"doc(Get a Font for a given DgnFile and font number. This is merely a
convenience routine that retrieves the DgnFontNumMap from the DgnFile
and calls DgnFontNumMap::GetFont on it.

Parameter ``fontNum``:
    The fontNumber of interest.

Parameter ``dgnFile``:
    The DgnFile of interest.

Returns:
    the Font or NULL if not found.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnFontManager_GetDecoratorFont =R"doc(Get a Font that matches the font used in dialog boxes. This can be
useful for decorating graphics in a Viewport with annotations that
appear as user interface components.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnFontManager_GetDefaultTrueTypeFont =R"doc(Get the default TrueType font. This font is specified in the Font
Configuration File and is used to render missing TrueType fonts.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnFontManager_GetDefaultShxFont =R"doc(Get the default SHX font. This font is specified in the Font
Configuration File and is used to render missing SHX fonts.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnFontManager_GetDefaultRscFont =R"doc(Get the default RSC font. This font is specified in the Font
Configuration File and is used to render missing RSC Fonts.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnFontNumMap_CreateUsedFontList =R"doc(Create a FontList with the fonts in this table, optionally limited by
a filter.

Parameter ``filter``:
    A filter to limit list to only fonts of a certain category.

Returns:
    A Ptr to the newly created list.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnFontNumMap_FindFontByName =R"doc(Find a Font in this table by name, optionally limited by a filter.

Parameter ``fontName``:
    Search for the font with this name.

Parameter ``filter``:
    A filter to limit search to only fonts of a certain category.

Returns:
    A pointer to the font with name ``fontName,`` or NULL if not
    found.

Returns (Tuple, 0):
	font.

Returns (Tuple, 1):
	fontNum.

)doc";

static const char * __doc_Bentley_DgnPlatform_DgnFontNumMap_VisitFonts =R"doc(Visit all fonts in this table, optionally with a filter applied.

Parameter ``visitor``:
    The DgnFontVisitor to be called for each font in the table

Parameter ``filter``:
    A filter to limit visits to only fonts of interest.

Returns:
    true of ``visitor`` returned true to stop the traversal, false
    otherwise.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnFontNumMap_GetFontNumber =R"doc(Search for a Font in this table and return it's font number if found.
Optionally adds the Font to the table if it does not already exist.


Parameter ``font``:
    The Font whose number is to be determined.

Parameter ``addIfNotFound``:
    If true, and if ``font`` is not already in the table, add it and
    assign it a font number.

Returns (Tuple, 0):
    SUCCESS if ``font`` was found (or added) and fontNum is valid.
    ERROR if ``font`` does not exist in this table.
    

Returns (Tuple, 1):
	fontNum. The Font's number in this table, if SUCCESS is returned. Undefined
    otherwise.

)doc";    

static const char * __doc_Bentley_DgnPlatform_DgnFontNumMap_ResolveFont =R"doc(Get a Font for a given font number. Returns a default Font if no font
exists for that value.

Parameter ``fontNum``:
    The font number to interpret.

Returns:
    A Font for ``fontNum.`` The font will either be the value in this
    table or a default Font.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnFont_ExpandEscapeSequences =R"doc(Scans the input string for backslashes, and replaces them with two
backslashes; this will ensure a call to
DgnFont::CompressEscapeSequences will not disturb them.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnFont_CompressEscapeSequences =R"doc(Scans the input string for character code escape sequences (e.g.
" \ 65 "), and converts them to corresponding characters (e.g. " A ").)doc";

static const char * __doc_Bentley_DgnPlatform_DgnFont_ExpandRscFractions =R"doc(Scans the input string for fraction code points, and converts them to
corresponding fraction strings (e.g. " 1 / 2 "), as identified by this
font. At this time, only RSC fonts support fraction glyphs.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnFont_CompressRscFractions =R"doc(Scans the input string for fraction strings (e.g. " 1 / 2 "), and converts
them to corresponding fraction code points, as identified by this
font. At this time, only RSC fonts support fraction glyphs.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnFont_GetNamedSymbols =R"doc(Gets the named symbols defined for this font. Thus includes the
standard symbols for degree, diameter, and plus/minus, as well as the
custom symbols defined in the font configuration for this font.cd clr)doc";

static const char * __doc_Bentley_DgnPlatform_DgnFont_GetLastCharCode =R"doc(Gets the last present character code; useful if attempting to iterate
over every glyph in the font.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnFont_GetFirstCharCode =R"doc(Gets the first present character code; useful if attempting to iterate
over every glyph in the font.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnFont_GetCodePage =R"doc(Get the CodePage (locale encoding) for this Font. Generally this value
is specified in the Font Configuration File.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnFont_GetFractionFromCharCode =R"doc(Convert a fraction glyph code in this Font into the fraction values.

Parameter ``glyphCode``:
    The glyph code of the fraction to be interpreted.

Returns (Tuple,0):
    SUCCESS if the glyph code was a fraction character and
    ``numerator`` and ``denominator`` are valid. ERROR otherwise.
    
Returns (Tuple,1) :
	numerator. The numerator of the fraction

Returns (Tuple,2):
	denominator. The denominator of the fraction

)doc";



static const char * __doc_Bentley_DgnPlatform_DgnFont_GetCharCodeFromFraction =R"doc(Convert a fraction into a glyph code in this Font, if possible.

Parameter ``numerator``:
    The numerator of the fraction

Parameter ``denominator``:
    The denominator of the fraction

Parameter ``reduce``:
    If true, first reduce the fraction to least common denominator
    before attempting conversion.

Returns:
    the character code of the fraction in this Font, or 0 if no
    appropriate fraction character exists.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnFont_GetMaxFractionDenominator =R"doc(Get the maximum value for the denominator of fractions held in this
Font. Will be 0 if no fractions exist. @note Only RSC fonts support
fraction characters.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnFont_GetPlusMinusCharCode =R"doc(Get the glyph code used for the plus/minus symbol.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnFont_GetDiameterCharCode =R"doc(Get the glyph code used for the diameter symbol.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnFont_GetDegreeCharCode =R"doc(Get the glyph code used for the degree symbol.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnFont_GetType =R"doc(Get the type of this Font.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnFont_GetName =R"doc(Get the name for this Font.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnFont_IsOutlineFont =R"doc(Determine whether this Font is an outline font. Some RSC and SHX fonts
contain glyph definitions that are " stick fonts ". These characters are
drawn as simple lines and arcs and are *not* outline fonts. If a font
is an " outline " font, then its glyphs are drawn as filled contours.
TrueType fonts are always outline fonts.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnFont_IsValid =R"doc(Determine whether this Font is valid. Some SHX fonts may point to
files that exist on the system but do not contain valid data.
Otherwise, if a Font is valid it is present and vice-versa.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnFont_IsUnicode =R"doc(Determine whether this Font is a Unicode encoded font.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnFont_IsSymbolFont =R"doc(Determine whether this Font is a symbol font.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnFont_IsShxBigFont =R"doc(Determine whether this Font is an SHX BigFont)doc";

static const char * __doc_Bentley_DgnPlatform_DgnFont_IsHidden =R"doc(Determine whether this Font is hidden from Font selection lists. The
Hidden property of a Font is controlled in the Font Configuration
File.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnFont_IsMissingFontReported =R"doc(If the font is " missing " from the system, check whether the user has
been notified about the missing font.

Returns:
    true if the user is notified about the " missing " Font.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnFont_IsPresent =R"doc(Determine whether this Font is present on the system.

Returns:
    true if the Font is present, and false if this is a " missing "
    font.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnFont_IsCharacterPresent =R"doc(Determine whether a character (in the font encoding, commonly called a
" glyph code ") exists in this font.

Parameter ``glyphCode``:
    the glyph code to check.

Returns:
    true if ``glyphCode`` is present)doc";

static const char * __doc_Bentley_DgnPlatform_DgnFontNamedSymbol_GetCodePoint =R"doc(Gets the code point of the symbol; this is specific to the font.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnFontNamedSymbol_GetDisplayName =R"doc(Gets the display name of the named symbol. This is the name to show in
UI pickers.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnFontNamedSymbol_GetKey =R"doc(Gets the non-localized key of the symbol.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnFontNamedSymbol_GetSource =R"doc(Gets the type/source of the named symbol.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnFontVisitor_VisitFont =R"doc(Visit an individual font in the set. Return true to stop processing
additional fonts.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnFontList_Sort =R"doc(Sort the List.)doc";

//=======================================================================================
// Trampoline class for DgnFontVisitor.
// @bsiclass                                                                   02/23
//=======================================================================================
struct PyDgnFontVisitor : DgnFontVisitor
    {
    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       2/2023
    +---------------+---------------+---------------+---------------+---------------+------*/        
    virtual bool VisitFont(DgnFontR font) override
        { PYBIND11_OVERRIDE_PURE_EXR(bool, DgnFontVisitor, VisitFont, false, font); }
    };

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_DgnFontManager(py::module_& m)
    {

    //=======================================================================================
    // enum SpecialCharValues
    py::enum_< SpecialCharValues>(m, "SpecialCharValues", py::arithmetic())
        .value("eSPECIALCHAR_Degree_Shx", SPECIALCHAR_Degree_Shx)
        .value("eSPECIALCHAR_PlusMinus_Shx", SPECIALCHAR_PlusMinus_Shx)
        .value("eSPECIALCHAR_Diameter_Shx", SPECIALCHAR_Diameter_Shx)
        .value("eSPECIALCHAR_Degree_Unicode", SPECIALCHAR_Degree_Unicode)
        .value("eSPECIALCHAR_PlusMinus_Unicode", SPECIALCHAR_PlusMinus_Unicode)
        .value("eSPECIALCHAR_Diameter_Unicode", SPECIALCHAR_Diameter_Unicode)
        .value("eSPECIALCHAR_DiameterSign_Unicode", SPECIALCHAR_DiameterSign_Unicode)
        .value("eSPECIALCHAR_CapitalOWithStroke_Unicode", SPECIALCHAR_CapitalOWithStroke_Unicode)
        .value("eSPECIALCHAR_SmallOWithStroke_Unicode", SPECIALCHAR_SmallOWithStroke_Unicode)
        .value("eSPECIALCHAR_FirstStandardRscFraction", SPECIALCHAR_FirstStandardRscFraction)
        .value("eSPECIALCHAR_LastStandardRscFraction", SPECIALCHAR_LastStandardRscFraction)
        .value("eSPECIALCHAR_UnicodeFraction_1_4", SPECIALCHAR_UnicodeFraction_1_4)
        .value("eSPECIALCHAR_UnicodeFraction_1_2", SPECIALCHAR_UnicodeFraction_1_2)
        .value("eSPECIALCHAR_UnicodeFraction_3_4", SPECIALCHAR_UnicodeFraction_3_4)
        .value("eSPECIALCHAR_UnicodeFraction_1_7", SPECIALCHAR_UnicodeFraction_1_7)
        .value("eSPECIALCHAR_UnicodeFraction_1_9", SPECIALCHAR_UnicodeFraction_1_9)
        .value("eSPECIALCHAR_UnicodeFraction_1_10", SPECIALCHAR_UnicodeFraction_1_10)
        .value("eSPECIALCHAR_UnicodeFraction_1_3", SPECIALCHAR_UnicodeFraction_1_3)
        .value("eSPECIALCHAR_UnicodeFraction_2_3", SPECIALCHAR_UnicodeFraction_2_3)
        .value("eSPECIALCHAR_UnicodeFraction_1_5", SPECIALCHAR_UnicodeFraction_1_5)
        .value("eSPECIALCHAR_UnicodeFraction_2_5", SPECIALCHAR_UnicodeFraction_2_5)
        .value("eSPECIALCHAR_UnicodeFraction_3_5", SPECIALCHAR_UnicodeFraction_3_5)
        .value("eSPECIALCHAR_UnicodeFraction_4_5", SPECIALCHAR_UnicodeFraction_4_5)
        .value("eSPECIALCHAR_UnicodeFraction_1_6", SPECIALCHAR_UnicodeFraction_1_6)
        .value("eSPECIALCHAR_UnicodeFraction_5_6", SPECIALCHAR_UnicodeFraction_5_6)
        .value("eSPECIALCHAR_UnicodeFraction_1_8", SPECIALCHAR_UnicodeFraction_1_8)
        .value("eSPECIALCHAR_UnicodeFraction_3_8", SPECIALCHAR_UnicodeFraction_3_8)
        .value("eSPECIALCHAR_UnicodeFraction_5_8", SPECIALCHAR_UnicodeFraction_5_8)
        .value("eSPECIALCHAR_UnicodeFraction_7_8", SPECIALCHAR_UnicodeFraction_7_8)
        .value("eSPECIALCHAR_PrivateUse_Degree_Unicode", SPECIALCHAR_PrivateUse_Degree_Unicode)
        .value("eSPECIALCHAR_PrivateUse_PlusMinus_Unicode", SPECIALCHAR_PrivateUse_PlusMinus_Unicode)
        .value("eSPECIALCHAR_PrivateUse_Diameter_Unicode", SPECIALCHAR_PrivateUse_Diameter_Unicode)
        .value("eSPECIALCHAR_PrivateUse_FirstRscFraction", SPECIALCHAR_PrivateUse_FirstRscFraction)
        .value("eSPECIALCHAR_PrivateUse_LastRscFraction", SPECIALCHAR_PrivateUse_LastRscFraction)
        .export_values();

    //=======================================================================================
    // enum class DgnFontType
    py::enum_< DgnFontType>(m, "DgnFontType")
        .value("eNone", DgnFontType::None)
        .value("eRsc", DgnFontType::Rsc)
        .value("eTrueType", DgnFontType::TrueType)
        .value("eShx", DgnFontType::Shx)
        .export_values();

    //=======================================================================================
    // enum class DgnFontFilter
    py::enum_< DgnFontFilter>(m, "DgnFontFilter")
        .value("eNone", DgnFontFilter::None)
        .value("eResource", DgnFontFilter::Resource)
        .value("eShx", DgnFontFilter::Shx)
        .value("eShxBig", DgnFontFilter::ShxBig)
        .value("eTrueType", DgnFontFilter::TrueType)
        .value("eMissing", DgnFontFilter::Missing)
        .value("eSymbol", DgnFontFilter::Symbol)
        .value("eHidden", DgnFontFilter::Hidden)
        .value("eNormal", DgnFontFilter::Normal)
        .value("eAllShx", DgnFontFilter::AllShx)
        .value("eAll", DgnFontFilter::All)
        .value("eResourceShx", DgnFontFilter::ResourceShx)
        .export_values();

    //=======================================================================================
    // enum class DgnFontNamedSymbolSource
    py::enum_< DgnFontNamedSymbolSource>(m, "DgnFontNamedSymbolSource")
        .value("eHardCoded", DgnFontNamedSymbolSource::HardCoded)
        .value("eCustomFromFontConfig", DgnFontNamedSymbolSource::CustomFromFontConfig)
        .export_values();

    //=======================================================================================
    // struct DgnFontList
    py::class_< DgnFontList, DgnFontListPtr> c1(m, "DgnFontList");

    if (true)
        {
        //=======================================================================================
        // enum SortOrder
        py::enum_<DgnFontList::SortOrder>(c1, "SortOrder", py::arithmetic())
            .value("eSORT_ByType", DgnFontList::SORT_ByType)
            .value("eSORT_ByName", DgnFontList::SORT_ByName)
            .export_values();
        }
    
    c1.def("__len__", &DgnFontList::GetCount);
    c1.def("GetEntry", &DgnFontList::GetEntryP, py::return_value_policy::reference_internal, "index"_a);
    c1.def("Sort", &DgnFontList::Sort, "order"_a, DOC(Bentley, DgnPlatform, DgnFontList, Sort));


    //=======================================================================================
    // struct DgnFontVisitor
    py::class_< DgnFontVisitor, PyDgnFontVisitor> c5(m, "DgnFontVisitor");

    c5.def(py::init<>());
    c5.def("VisitFont", &DgnFontVisitor::VisitFont, "font"_a, DOC(Bentley, DgnPlatform, DgnFontVisitor, VisitFont));

    //=======================================================================================
    // struct DgnFontNamedSymbol
    py::class_< DgnFontNamedSymbol, DgnFontNamedSymbolPtr> c6(m, "DgnFontNamedSymbol");

    c6.def_property_readonly("Source", &DgnFontNamedSymbol::GetSource);
    c6.def("GetSource", &DgnFontNamedSymbol::GetSource, DOC(Bentley, DgnPlatform, DgnFontNamedSymbol, GetSource));
    
    c6.def_property_readonly("Key", &DgnFontNamedSymbol::GetKey);
    c6.def("GetKey", &DgnFontNamedSymbol::GetKey, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, DgnFontNamedSymbol, GetKey));
    
    c6.def_property_readonly("DisplayName", &DgnFontNamedSymbol::GetDisplayName);
    c6.def("GetDisplayName", &DgnFontNamedSymbol::GetDisplayName, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, DgnFontNamedSymbol, GetDisplayName));
    
    c6.def_property_readonly("CodePoint", &DgnFontNamedSymbol::GetCodePoint);
    c6.def("GetCodePoint", &DgnFontNamedSymbol::GetCodePoint, DOC(Bentley, DgnPlatform, DgnFontNamedSymbol, GetCodePoint));

    //=======================================================================================
    // struct DgnFont
    py::class_< DgnFont, RefCountedPtr<DgnFont> > c7(m, "DgnFont");
    bind_PointerVector<DgnFontP>(m, "DgnFontPArray", py::module_local(false));


    c7.def("IsCharacterPresent", &DgnFont::IsCharacterPresent, "glyphCode"_a, DOC(Bentley, DgnPlatform, DgnFont, IsCharacterPresent));
    c7.def("IsPresent", &DgnFont::IsPresent, DOC(Bentley, DgnPlatform, DgnFont, IsPresent));
    c7.def("IsMissingFontReported", &DgnFont::IsMissingFontReported, DOC(Bentley, DgnPlatform, DgnFont, IsMissingFontReported));
    c7.def("SetMissingFontReported", &DgnFont::SetMissingFontIsReported);    
    c7.def("IsHidden", &DgnFont::IsHidden, DOC(Bentley, DgnPlatform, DgnFont, IsHidden));
    c7.def("IsShxBigFont", &DgnFont::IsShxBigFont, DOC(Bentley, DgnPlatform, DgnFont, IsShxBigFont));
    c7.def("IsSymbolFont", &DgnFont::IsSymbolFont, DOC(Bentley, DgnPlatform, DgnFont, IsSymbolFont));
    c7.def("IsUnicode", &DgnFont::IsUnicode, DOC(Bentley, DgnPlatform, DgnFont, IsUnicode));
    c7.def("IsValid", &DgnFont::IsValid, DOC(Bentley, DgnPlatform, DgnFont, IsValid));
    c7.def("IsOutlineFont", &DgnFont::IsOutlineFont, DOC(Bentley, DgnPlatform, DgnFont, IsOutlineFont));
    
    c7.def_property_readonly("Name", &DgnFont::GetName);
    c7.def("GetName", &DgnFont::GetName, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, DgnFont, GetName));
    
    c7.def_property_readonly("Type", &DgnFont::GetType);
    c7.def("GetType", &DgnFont::GetType, DOC(Bentley, DgnPlatform, DgnFont, GetType));
    
    c7.def_property_readonly("DegreeCharCode", &DgnFont::GetDegreeCharCode);
    c7.def("GetDegreeCharCode", &DgnFont::GetDegreeCharCode, DOC(Bentley, DgnPlatform, DgnFont, GetDegreeCharCode));
    
    c7.def_property_readonly("DiameterCharCode", &DgnFont::GetDiameterCharCode);
    c7.def("GetDiameterCharCode", &DgnFont::GetDiameterCharCode, DOC(Bentley, DgnPlatform, DgnFont, GetDiameterCharCode));
    
    c7.def_property_readonly("PlusMinusCharCode", &DgnFont::GetPlusMinusCharCode);
    c7.def("GetPlusMinusCharCode", &DgnFont::GetPlusMinusCharCode, DOC(Bentley, DgnPlatform, DgnFont, GetPlusMinusCharCode));
    
    c7.def_property_readonly("MaxFractionDenominator", &DgnFont::GetMaxFractionDenominator);
    c7.def("GetMaxFractionDenominator", &DgnFont::GetMaxFractionDenominator, DOC(Bentley, DgnPlatform, DgnFont, GetMaxFractionDenominator));
    
    c7.def("GetCharCodeFromFraction", &DgnFont::GetCharCodeFromFraction, "numerator"_a, "denominator"_a, "reduce"_a = true, DOC(Bentley, DgnPlatform, DgnFont, GetCharCodeFromFraction));
    
    c7.def("GetFractionFromCharCode", [] (DgnFontCR self, UInt16 glyphCode)
           {
           UInt32 numerator, denominator;
           auto retVal = self.GetFractionFromCharCode(numerator, denominator, glyphCode);
           return py::make_tuple(retVal, numerator, denominator);
           }, "glyphCode"_a, DOC(Bentley, DgnPlatform, DgnFont, GetFractionFromCharCode));

    c7.def_property_readonly("CodePage", &DgnFont::GetCodePage);
    c7.def("GetCodePage", &DgnFont::GetCodePage, DOC(Bentley, DgnPlatform, DgnFont, GetCodePage));
    
    c7.def_property_readonly("FirstCharCode", &DgnFont::GetFirstCharCode);
    c7.def("GetFirstCharCode", &DgnFont::GetFirstCharCode, DOC(Bentley, DgnPlatform, DgnFont, GetFirstCharCode));
    
    c7.def_property_readonly("LastCharCode", &DgnFont::GetLastCharCode);
    c7.def("GetLastCharCode", &DgnFont::GetLastCharCode, DOC(Bentley, DgnPlatform, DgnFont, GetLastCharCode));

    c7.def("GetGlyph", &DgnFont::GetGlyphP, "char"_a, py::return_value_policy::reference_internal);
    c7.def("GetNamedSymbols", &DgnFont::GetNamedSymbols, "symbols"_a, DOC(Bentley, DgnPlatform, DgnFont, GetNamedSymbols));
    c7.def("CompressRscFractions", &DgnFont::CompressRscFractions, "outStr"_a, "inStr"_a, DOC(Bentley, DgnPlatform, DgnFont, CompressRscFractions));
    c7.def("ExpandRscFractions", &DgnFont::ExpandRscFractions, "outStr"_a, "inStr"_a, DOC(Bentley, DgnPlatform, DgnFont, ExpandRscFractions));
    c7.def("CompressEscapeSequences", &DgnFont::CompressEscapeSequences, "outStr"_a, "inStr"_a, DOC(Bentley, DgnPlatform, DgnFont, CompressEscapeSequences));
    c7.def("ExpandEscapeSequences", &DgnFont::ExpandEscapeSequences, "outStr"_a, "inStr"_a, DOC(Bentley, DgnPlatform, DgnFont, ExpandEscapeSequences));        

    //=======================================================================================
    // struct DgnFontNumMap
    py::class_< DgnFontNumMap, RefCountedPtr<DgnFontNumMap> > c8(m, "DgnFontNumMap");


    c8.def("GetFont", &DgnFontNumMap::GetFontP, "fontNum"_a, py::return_value_policy::reference_internal);
    c8.def("ResolveFont", &DgnFontNumMap::ResolveFont, "fontNum"_a, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, DgnFontNumMap, ResolveFont));
    
    c8.def("GetFontNumber", [] (DgnFontNumMapR self, DgnFontCR font, bool addIfNotFound)
           {
           UInt32 fontNum = 0;
           auto retVal = self.GetFontNumber(fontNum, font, addIfNotFound);
           return py::make_tuple(retVal, fontNum);
           }, "font"_a, "addIfNotFound"_a, DOC(Bentley, DgnPlatform, DgnFontNumMap, GetFontNumber));

    c8.def("VisitFonts", &DgnFontNumMap::VisitFonts, "visitor"_a, "filter"_a, DOC(Bentley, DgnPlatform, DgnFontNumMap, VisitFonts));

    c8.def("FindFontByName", [] (DgnFontNumMapR self, WCharCP fontName, DgnFontFilter filter)
           {
           UInt32 fontNum = 0;
           RefCountedPtr<DgnFont> font(self.FindFontByName(&fontNum, fontName, filter));
           return py::make_tuple(font, fontNum);
           }, "fontName"_a, "filter"_a = DgnFontFilter::Normal, DOC(Bentley, DgnPlatform, DgnFontNumMap, FindFontByName));

    c8.def("CreateUsedFontList", &DgnFontNumMap::CreateUsedFontList, "filter"_a = DgnFontFilter::Normal, DOC(Bentley, DgnPlatform, DgnFontNumMap, CreateUsedFontList));


     
    //=======================================================================================
    // struct DgnFontManager
    py::class_< DgnFontManager, DgnHost::IHostObject> c9(m, "DgnFontManager");


    c9.def_static("GetDgnFontMap", [] (DgnFileP dgnFile) { return RefCountedPtr<DgnFontNumMap>(DgnFontManager::GetDgnFontMapP(dgnFile)); }, "dgnFile"_a);
    c9.def_static("GetDgnFontMap", [] (DgnModelRefP modelRef) { return RefCountedPtr<DgnFontNumMap>(DgnFontManager::GetDgnFontMapP(modelRef)); }, "modelRef"_a);
    
    c9.def_property_readonly_static("DefaultRscFont", [] (py::object const&) { return RefCountedPtr<DgnFont>(&DgnFontManager::GetDefaultRscFont()); });
    c9.def_static("GetDefaultRscFont", [] () { return RefCountedPtr<DgnFont>(&DgnFontManager::GetDefaultRscFont()); }, DOC(Bentley, DgnPlatform, DgnFontManager, GetDefaultRscFont));
    
    c9.def_property_readonly_static("DefaultShxFont", [] (py::object const&) { return RefCountedPtr<DgnFont>(&DgnFontManager::GetDefaultShxFont()); });
    c9.def_static("GetDefaultShxFont", [] () { return RefCountedPtr<DgnFont>(&DgnFontManager::GetDefaultShxFont()); }, DOC(Bentley, DgnPlatform, DgnFontManager, GetDefaultShxFont));
    
    c9.def_property_readonly_static("DefaultShxBigFont", [] (py::object const&) { return RefCountedPtr<DgnFont>(DgnFontManager::GetDefaultShxBigFont()); });
    c9.def_static("GetDefaultShxBigFont", [] () { return RefCountedPtr<DgnFont>(DgnFontManager::GetDefaultShxBigFont()); });
    
    c9.def_property_readonly_static("DefaultTrueTypeFont", [] (py::object const&) { return RefCountedPtr<DgnFont>(&DgnFontManager::GetDefaultTrueTypeFont()); });
    c9.def_static("GetDefaultTrueTypeFont", [] () { return RefCountedPtr<DgnFont>(&DgnFontManager::GetDefaultTrueTypeFont()); }, DOC(Bentley, DgnPlatform, DgnFontManager, GetDefaultTrueTypeFont));
    
    c9.def_property_readonly_static("DecoratorFont", [] (py::object const&) { return RefCountedPtr<DgnFont>(&DgnFontManager::GetDecoratorFont()); });
    c9.def_static("GetDecoratorFont", [] () { return RefCountedPtr<DgnFont>(&DgnFontManager::GetDecoratorFont()); }, DOC(Bentley, DgnPlatform, DgnFontManager, GetDecoratorFont));
    
    c9.def_static("GetFontByNumber", py::overload_cast<UInt32, DgnFileP>(&DgnFontManager::GetFontByNumber), "fontNum"_a, "dgnFile"_a, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, DgnFontManager, GetFontByNumber));
    c9.def_static("GetFontByNumber", py::overload_cast<UInt32, DgnModelRefP>(&DgnFontManager::GetFontByNumber), "fontNum"_a, "modelRef"_a, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, DgnFontManager, GetFontByNumber));
    c9.def_static("ResolveFontNum", py::overload_cast<UInt32, DgnFileP>(&DgnFontManager::ResolveFontNum), "fontNum"_a, "dgnFile"_a, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, DgnFontManager, ResolveFontNum));
    c9.def_static("ResolveFontNum", py::overload_cast<UInt32, DgnModelRefP>(&DgnFontManager::ResolveFontNum), "fontNum"_a, "modelRef"_a, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, DgnFontManager, ResolveFontNum));
    c9.def_static("FindSystemFont", &DgnFontManager::FindSystemFont, "fontName"_a, "filter"_a = DgnFontFilter::Normal, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, DgnFontManager, FindSystemFont));
    c9.def_static("VisitAllSystemFonts", &DgnFontManager::VisitAllSystemFonts, "visitor"_a, "filter"_a = DgnFontFilter::Normal, DOC(Bentley, DgnPlatform, DgnFontManager, VisitAllSystemFonts));
    c9.def_static("CreateKnownFontList", &DgnFontManager::CreateKnownFontList, "dgnFile"_a = nullptr, "filter"_a = DgnFontFilter::Normal, DOC(Bentley, DgnPlatform, DgnFontManager, CreateKnownFontList));
    c9.def_static("GetFontForCodePage", &DgnFontManager::GetFontForCodePage, "fontNum"_a, "bigFontNum"_a, "dgnFile"_a, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, DgnFontManager, GetFontForCodePage));

    //=======================================================================================
    // struct DgnGlyph
    py::class_ < DgnGlyph, std::unique_ptr < DgnGlyph, py::nodelete> > c10(m, "DgnGlyph");

    c10.def("GetGPA", &DgnGlyph::GetGPA, "gpa"_a, DOC(Bentley, DgnPlatform, DgnGlyph, GetGPA));
    }
