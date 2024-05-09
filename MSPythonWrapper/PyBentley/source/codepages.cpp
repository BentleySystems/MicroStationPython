/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyBentley\source\codepages.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <Bentley/CodePages.h>





/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_CodePages(py::module_& m)
    {
    //===================================================================================
    // enum class LangCodePage
    py::enum_< LangCodePage>(m, "LangCodePage")
        .value("eUnknown", LangCodePage::Unknown)
        .value("eNone", LangCodePage::None)
        .value("eOEM_US", LangCodePage::OEM_US)
        .value("eTransparent_ASMO", LangCodePage::Transparent_ASMO)
        .value("eOEM_Greek", LangCodePage::OEM_Greek)
        .value("eOEM_Baltic", LangCodePage::OEM_Baltic)
        .value("eOEM_Multilingual", LangCodePage::OEM_Multilingual)
        .value("eOEM_LatinII", LangCodePage::OEM_LatinII)
        .value("eOEM_Cryllic", LangCodePage::OEM_Cryllic)
        .value("eOEM_Turkish", LangCodePage::OEM_Turkish)
        .value("eOEM_LatinI", LangCodePage::OEM_LatinI)
        .value("eOEM_Hebrew", LangCodePage::OEM_Hebrew)
        .value("eOEM_Russian", LangCodePage::OEM_Russian)
        .value("eOEM_Thai", LangCodePage::OEM_Thai)
        .value("eJapanese", LangCodePage::Japanese)
        .value("eSimplified_Chinese", LangCodePage::Simplified_Chinese)
        .value("eKorean", LangCodePage::Korean)
        .value("eTraditional_Chinese", LangCodePage::Traditional_Chinese)
        .value("eUnicode", LangCodePage::Unicode)
        .value("eUNICODE_UCS2_Little_Endian", LangCodePage::UNICODE_UCS2_Little_Endian)
        .value("eUNICODE_UCS2_Big_Endian", LangCodePage::UNICODE_UCS2_Big_Endian)
        .value("eCentral_European", LangCodePage::Central_European)
        .value("eCyrillic", LangCodePage::Cyrillic)
        .value("eLatinI", LangCodePage::LatinI)
        .value("eGreek", LangCodePage::Greek)
        .value("eTurkish", LangCodePage::Turkish)
        .value("eHebrew", LangCodePage::Hebrew)
        .value("eArabic", LangCodePage::Arabic)
        .value("eBaltic", LangCodePage::Baltic)
        .value("eVietnamese", LangCodePage::Vietnamese)
        .value("eJohab", LangCodePage::Johab)
        .value("eISO_8859_1", LangCodePage::ISO_8859_1)
        .value("eISO_8859_2", LangCodePage::ISO_8859_2)
        .value("eISO_8859_3", LangCodePage::ISO_8859_3)
        .value("eISO_8859_4", LangCodePage::ISO_8859_4)
        .value("eISO_8859_5", LangCodePage::ISO_8859_5)
        .value("eISO_8859_6", LangCodePage::ISO_8859_6)
        .value("eISO_8859_7", LangCodePage::ISO_8859_7)
        .value("eISO_8859_8", LangCodePage::ISO_8859_8)
        .value("eISO_8859_9", LangCodePage::ISO_8859_9)
        .value("eISO_8859_15", LangCodePage::ISO_8859_15)
        .value("eISCII_UNICODE_UTF_7", LangCodePage::ISCII_UNICODE_UTF_7)
        .value("eISCII_UNICODE_UTF_8", LangCodePage::ISCII_UNICODE_UTF_8)
        .export_values();
    }