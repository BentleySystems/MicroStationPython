/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyMstnPlatform\source\elementpropertyutils.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <Mstn/ElementPropertyUtils.h>



static const char * __doc_Bentley_MstnPlatform_ElementPropertyUtils_ApplyActivePattern =R"doc(Apply the active pattern type and settings to the supplied element.

:param eeh:
    The element to modify.

:param paramsP:
    pattern params or NULL.

:param hatchDefLinesP:
    DWG hatch definition or NULL.

:param option:
    pattern type:PATTERN_HATCH, PATTERN_CROSSHATCH, or PATTERN_AREA,
    used if paramsP is NULL.

:param originP:
    pattern origin or NULL.

:param rMatrix:
    pattern rotation or NULL.

:param line1:
    Multiline specific profile index if patterning between specific
    profile lines.

:param line2:
    Multiline specific profile index if patterning between specific
    profile lines.

:param index:
    Pattern index (only for multilines).

:returns:
    true if element was updated.

See also:
    AddPattern Bentley Systems

Remark:)doc";

static const char * __doc_Bentley_MstnPlatform_ElementPropertyUtils_ApplyActiveGradientFill =R"doc(Apply the active gradient fill to the supplied element.

:param eeh:
    The element to modify.

:returns:
    true if element was updated.

See also:
    AddGradientFill Bentley Systems

Remark:)doc";

static const char * __doc_Bentley_MstnPlatform_ElementPropertyUtils_ApplyActiveSolidFill =R"doc(Apply the active solid fill to the supplied element.

:param eeh:
    The element to modify.

:returns:
    true if element was updated.

See also:
    AddSolidFill Bentley Systems

Remark:)doc";

static const char * __doc_Bentley_MstnPlatform_ElementPropertyUtils_ApplyActiveAreaFill =R"doc(Apply the active solid or gradient fill to the supplied element.

:param eeh:
    The element to modify.

:param fillMode:
    0 = none, 1 = opaque fill, -1 to use the active fill settings.

:returns:
    true if element was updated.

See also:
    AddSolidFill AddGradientFill Bentley Systems

Remark:
)doc";

static const char * __doc_Bentley_MstnPlatform_ElementPropertyUtils_ApplyActiveAreaSettings =R"doc(Update the supplied element to the current active fill and area
settings using IAreaFillPropertiesEdit. @note:Does nothing if model
of EditElementHandle is not ACTIVEMODEL. *

Remark:
    )doc";

static const char * __doc_Bentley_MstnPlatform_ElementPropertyUtils_ApplyActiveSettings =R"doc(Update the supplied element to the current active settings. Sets
level, color, style, weight, class, transparency, and display priority
(2d only). @note:Does nothing if model of EditElementHandle is not
ACTIVEMODEL. *

Remark:
    )doc";

USING_NAMESPACE_BENTLEY_MSTNPLATFORM_ELEMENT;

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_ElementPropertyUtils(py::module_& m)
    {
    //===================================================================================
    // struct ElementPropertyUtils
    py::class_< ElementPropertyUtils> c1(m, "ElementPropertyUtils");

    c1.def_static("ApplyActiveSettings", &ElementPropertyUtils::ApplyActiveSettings, "eeh"_a, DOC(Bentley, MstnPlatform, ElementPropertyUtils, ApplyActiveSettings));
    c1.def_static("ApplyActiveAreaSettings", &ElementPropertyUtils::ApplyActiveAreaSettings, "eeh"_a, "fillMode"_a, DOC(Bentley, MstnPlatform, ElementPropertyUtils, ApplyActiveAreaSettings));
    c1.def_static("ApplyActiveAreaFill", &ElementPropertyUtils::ApplyActiveAreaFill, "eeh"_a, "fillMode"_a, DOC(Bentley, MstnPlatform, ElementPropertyUtils, ApplyActiveAreaFill));
    c1.def_static("ApplyActiveSolidFill", &ElementPropertyUtils::ApplyActiveSolidFill, "eeh"_a, DOC(Bentley, MstnPlatform, ElementPropertyUtils, ApplyActiveSolidFill));
    c1.def_static("ApplyActiveGradientFill", &ElementPropertyUtils::ApplyActiveGradientFill, "eeh"_a, DOC(Bentley, MstnPlatform, ElementPropertyUtils, ApplyActiveGradientFill));
    c1.def_static("ApplyActivePattern", &ElementPropertyUtils::ApplyActivePattern, "eeh"_a, "params"_a, "hatchDefLines"_a, "option"_a, "origin"_a, "rMatrix"_a, "line1"_a, "line2"_a, "index"_a = 0, DOC(Bentley, MstnPlatform, ElementPropertyUtils, ApplyActivePattern));
    }