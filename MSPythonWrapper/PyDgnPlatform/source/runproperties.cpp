/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnPlatform\source\runproperties.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <DgnPlatform/TextBlock/RunProperties.h>



static const char * __doc_Bentley_DgnPlatform_RunProperties_ClearHeightOverride =R"doc(Clears the height property override flag and reverts its value from
the underlying style.)doc";

static const char * __doc_Bentley_DgnPlatform_RunProperties_IsHeightOverridden =R"doc(True if the height property is overridden from the underlying style.)doc";

static const char * __doc_Bentley_DgnPlatform_RunProperties_ClearWidthOverride =R"doc(Clears the width property override flag and reverts its value from the
underlying style.)doc";

static const char * __doc_Bentley_DgnPlatform_RunProperties_IsWidthOverridden =R"doc(True if the width property is overridden from the underlying style.)doc";

static const char * __doc_Bentley_DgnPlatform_RunProperties_ClearIsSuperScriptOverride =R"doc(Clears the is superscript property override flag and reverts its value
from the underlying style.)doc";

static const char * __doc_Bentley_DgnPlatform_RunProperties_IsSuperScriptOverridden =R"doc(True if the is superscript property is overridden from the underlying
style.)doc";

static const char * __doc_Bentley_DgnPlatform_RunProperties_ClearIsSubScriptOverride =R"doc(Clears the is subscript property override flag and reverts its value
from the underlying style.)doc";

static const char * __doc_Bentley_DgnPlatform_RunProperties_IsSubScriptOverridden =R"doc(True if the is subscript property is overridden from the underlying
style.)doc";

static const char * __doc_Bentley_DgnPlatform_RunProperties_ClearRunOffsetOverride =R"doc(Clears the run offset property override flag and reverts its value
from the underlying style.)doc";

static const char * __doc_Bentley_DgnPlatform_RunProperties_IsRunOffsetOverridden =R"doc(True if the run offset property is overridden from the underlying
style.)doc";

static const char * __doc_Bentley_DgnPlatform_RunProperties_ClearBackgroundBorderPaddingOverride =R"doc(Clears the background border padding property override flag and
reverts its value from the underlying style.)doc";

static const char * __doc_Bentley_DgnPlatform_RunProperties_IsBackgroundBorderPaddingOverridden =R"doc(True if the background border padding property is overridden from the
underlying style.)doc";

static const char * __doc_Bentley_DgnPlatform_RunProperties_ClearBackgroundBorderWeightOverride =R"doc(Clears the background border weight property override flag and reverts
its value from the underlying style.)doc";

static const char * __doc_Bentley_DgnPlatform_RunProperties_IsBackgroundBorderWeightOverridden =R"doc(True if the background border weight property is overridden from the
underlying style.)doc";

static const char * __doc_Bentley_DgnPlatform_RunProperties_ClearBackgroundBorderLineStyleOverride =R"doc(Clears the background border line style property override flag and
reverts its value from the underlying style.)doc";

static const char * __doc_Bentley_DgnPlatform_RunProperties_IsBackgroundBorderLineStyleOverridden =R"doc(True if the background border line style property is overridden from
the underlying style.)doc";

static const char * __doc_Bentley_DgnPlatform_RunProperties_ClearBackgroundBorderColorOverride =R"doc(Clears the background border color property override flag and reverts
its value from the underlying style.)doc";

static const char * __doc_Bentley_DgnPlatform_RunProperties_IsBackgroundBorderColorOverridden =R"doc(True if the background border color property is overridden from the
underlying style.)doc";

static const char * __doc_Bentley_DgnPlatform_RunProperties_ClearBackgroundFillColorOverride =R"doc(Clears the background fill color property override flag and reverts
its value from the underlying style.)doc";

static const char * __doc_Bentley_DgnPlatform_RunProperties_IsBackgroundFillColorOverridden =R"doc(True if the background fill color property is overridden from the
underlying style.)doc";

static const char * __doc_Bentley_DgnPlatform_RunProperties_ClearShouldUseBackgroundOverride =R"doc(Clears the should use background property override flag and reverts
its value from the underlying style.)doc";

static const char * __doc_Bentley_DgnPlatform_RunProperties_IsShouldUseBackgroundOverridden =R"doc(True if the should use background property is overridden from the
underlying style.)doc";

static const char * __doc_Bentley_DgnPlatform_RunProperties_ClearCharacterSpacingValueOverride =R"doc(Clears the character spacing value property override flag and reverts
its value from the underlying style.)doc";

static const char * __doc_Bentley_DgnPlatform_RunProperties_IsCharacterSpacingValueOverridden =R"doc(True if the character spacing value property is overridden from the
underlying style.)doc";

static const char * __doc_Bentley_DgnPlatform_RunProperties_ClearCharacterSpacingTypeOverride =R"doc(Clears the character spacing type property override flag and reverts
its value from the underlying style.)doc";

static const char * __doc_Bentley_DgnPlatform_RunProperties_IsCharacterSpacingTypeOverridden =R"doc(True if the character spacing type property is overridden from the
underlying style.)doc";

static const char * __doc_Bentley_DgnPlatform_RunProperties_ClearOverlineWeightOverride =R"doc(Clears the overline weight property override flag and reverts its
value from the underlying style.)doc";

static const char * __doc_Bentley_DgnPlatform_RunProperties_IsOverlineWeightOverridden =R"doc(True if the overline weight property is overridden from the underlying
style.)doc";

static const char * __doc_Bentley_DgnPlatform_RunProperties_ClearOverlineLineStyleOverride =R"doc(Clears the overline line style property override flag and reverts its
value from the underlying style.)doc";

static const char * __doc_Bentley_DgnPlatform_RunProperties_IsOverlineLineStyleOverridden =R"doc(True if the overline line style property is overridden from the
underlying style.)doc";

static const char * __doc_Bentley_DgnPlatform_RunProperties_ClearOverlineColorOverride =R"doc(Clears the overline color property override flag and reverts its value
from the underlying style.)doc";

static const char * __doc_Bentley_DgnPlatform_RunProperties_IsOverlineColorOverridden =R"doc(True if the overline color property is overridden from the underlying
style.)doc";

static const char * __doc_Bentley_DgnPlatform_RunProperties_ClearOverlineOffsetOverride =R"doc(Clears the overline offset property override flag and reverts its
value from the underlying style.)doc";

static const char * __doc_Bentley_DgnPlatform_RunProperties_IsOverlineOffsetOverridden =R"doc(True if the overline offset property is overridden from the underlying
style.)doc";

static const char * __doc_Bentley_DgnPlatform_RunProperties_ClearShouldUseOverlineStyleOverride =R"doc(Clears the should use overline style property override flag and
reverts its value from the underlying style.)doc";

static const char * __doc_Bentley_DgnPlatform_RunProperties_IsShouldUseOverlineStyleOverridden =R"doc(True if the should use overline style property is overridden from the
underlying style.)doc";

static const char * __doc_Bentley_DgnPlatform_RunProperties_ClearIsOverlinedOverride =R"doc(Clears the is overlined property override flag and reverts its value
from the underlying style.)doc";

static const char * __doc_Bentley_DgnPlatform_RunProperties_IsOverlinedOverridden =R"doc(True if the is overlined property is overridden from the underlying
style.)doc";

static const char * __doc_Bentley_DgnPlatform_RunProperties_ClearUnderlineWeightOverride =R"doc(Clears the underline weight property override flag and reverts its
value from the underlying style.)doc";

static const char * __doc_Bentley_DgnPlatform_RunProperties_IsUnderlineWeightOverridden =R"doc(True if the underline weight property is overridden from the
underlying style.)doc";

static const char * __doc_Bentley_DgnPlatform_RunProperties_ClearUnderlineLineStyleOverride =R"doc(Clears the underline line style property override flag and reverts its
value from the underlying style.)doc";

static const char * __doc_Bentley_DgnPlatform_RunProperties_IsUnderlineLineStyleOverridden =R"doc(True if the underline line style property is overridden from the
underlying style.)doc";

static const char * __doc_Bentley_DgnPlatform_RunProperties_ClearUnderlineColorOverride =R"doc(Clears the underline color property override flag and reverts its
value from the underlying style.)doc";

static const char * __doc_Bentley_DgnPlatform_RunProperties_IsUnderlineColorOverridden =R"doc(True if the underline color property is overridden from the underlying
style.)doc";

static const char * __doc_Bentley_DgnPlatform_RunProperties_ClearUnderlineOffsetOverride =R"doc(Clears the underline offset property override flag and reverts its
value from the underlying style.)doc";

static const char * __doc_Bentley_DgnPlatform_RunProperties_IsUnderlineOffsetOverridden =R"doc(True if the underline offset property is overridden from the
underlying style.)doc";

static const char * __doc_Bentley_DgnPlatform_RunProperties_ClearShouldUseUnderlineStyleOverride =R"doc(Clears the should use underline style property override flag and
reverts its value from the underlying style.)doc";

static const char * __doc_Bentley_DgnPlatform_RunProperties_IsShouldUseUnderlineStyleOverridden =R"doc(True if the should use underline style property is overridden from the
underlying style.)doc";

static const char * __doc_Bentley_DgnPlatform_RunProperties_ClearIsUnderlinedOverride =R"doc(Clears the is underlined property override flag and reverts its value
from the underlying style.)doc";

static const char * __doc_Bentley_DgnPlatform_RunProperties_IsUnderlinedOverridden =R"doc(True if the is underlined property is overridden from the underlying
style.)doc";

static const char * __doc_Bentley_DgnPlatform_RunProperties_ClearCustomSlantAngleOverride =R"doc(Clears the custom slant angle property override flag and reverts its
value from the underlying style.)doc";

static const char * __doc_Bentley_DgnPlatform_RunProperties_IsCustomSlantAngleOverridden =R"doc(True if the custom slant angle property is overridden from the
underlying style.)doc";

static const char * __doc_Bentley_DgnPlatform_RunProperties_ClearIsItalicOverride =R"doc(Clears the is italic property override flag and reverts its value from
the underlying style.)doc";

static const char * __doc_Bentley_DgnPlatform_RunProperties_IsItalicOverridden =R"doc(True if the is italic property is overridden from the underlying
style.)doc";

static const char * __doc_Bentley_DgnPlatform_RunProperties_ClearIsBoldOverride =R"doc(Clears the is bold property override flag and reverts its value from
the underlying style.)doc";

static const char * __doc_Bentley_DgnPlatform_RunProperties_IsBoldOverridden =R"doc(True if the is bold property is overridden from the underlying style.)doc";

static const char * __doc_Bentley_DgnPlatform_RunProperties_ClearColorOverride =R"doc(Clears the color property override flag and reverts its value from the
underlying style.)doc";

static const char * __doc_Bentley_DgnPlatform_RunProperties_IsColorOverridden =R"doc(True if the color property is overridden from the underlying style.)doc";

static const char * __doc_Bentley_DgnPlatform_RunProperties_ClearHasColorOverride =R"doc(Clears the has color property override flag and reverts its value from
the underlying style.)doc";

static const char * __doc_Bentley_DgnPlatform_RunProperties_IsHasColorOverridden =R"doc(True if the has color property is overridden from the underlying
style.)doc";

static const char * __doc_Bentley_DgnPlatform_RunProperties_ClearBigFontOverride =R"doc(Clears the big font property override flag and reverts its value from
the underlying style.)doc";

static const char * __doc_Bentley_DgnPlatform_RunProperties_IsBigFontOverridden =R"doc(True if the big font property is overridden from the underlying style.)doc";

static const char * __doc_Bentley_DgnPlatform_RunProperties_ClearFontOverride =R"doc(Clears the font property override flag and reverts its value from the
underlying style.)doc";

static const char * __doc_Bentley_DgnPlatform_RunProperties_IsFontOverridden =R"doc(True if the font property is overridden from the underlying style.)doc";

static const char * __doc_Bentley_DgnPlatform_RunProperties_Clone =R"doc(Creates a new instance as a deep copy of this instance.)doc";

static const char * __doc_Bentley_DgnPlatform_RunProperties_Create =R"doc(Creates a new instance of RunProperties with default (e.g. zero'ed)
values.)doc";

static const char * __doc_Bentley_DgnPlatform_RunProperties_AsIDgnTextStyleApplyable =R"doc(Provides access to the IDgnTextStyleApplyable interface that this
object effectively implements.)doc";

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_RunProperties(py::module_& m)
    {
    //===================================================================================
    // struct RunProperties
    py::class_< RunProperties, RefCountedPtr<RunProperties>, RunPropertiesBase> c1(m, "RunProperties");

    c1.def("AsIDgnTextStyleApplyable", &RunProperties::AsIDgnTextStyleApplyableR, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, RunProperties, AsIDgnTextStyleApplyable));
    c1.def_static("Create", py::overload_cast<DgnFontCR, DPoint2dCR, DgnModelR>(&RunProperties::Create), "font"_a, "fontSize"_a, "dgnModel"_a, DOC(Bentley, DgnPlatform, RunProperties, Create));
    c1.def_static("Create", py::overload_cast<DgnTextStyleCR, DgnModelR>(&RunProperties::Create), "textStyle"_a, "dgnModel"_a, DOC(Bentley, DgnPlatform, RunProperties, Create));
    c1.def_static("Create", py::overload_cast<DgnTextStyleCR, DgnModelR, double>(&RunProperties::Create), "textStyle"_a, "dgnModel"_a, "annotationScale"_a, DOC(Bentley, DgnPlatform, RunProperties, Create));
    c1.def("Clone", &RunProperties::Clone, DOC(Bentley, DgnPlatform, RunProperties, Clone));

    c1.def_property_readonly("DgnModel", &RunProperties::GetDgnModelR);
    c1.def("GetDgnModel", &RunProperties::GetDgnModelR, py::return_value_policy::reference_internal);

    c1.def("IsFontOverridden", &RunProperties::IsFontOverridden, DOC(Bentley, DgnPlatform, RunProperties, IsFontOverridden));
    c1.def("ClearFontOverride", &RunProperties::ClearFontOverride, DOC(Bentley, DgnPlatform, RunProperties, ClearFontOverride));

    c1.def("IsBigFontOverridden", &RunProperties::IsBigFontOverridden, DOC(Bentley, DgnPlatform, RunProperties, IsBigFontOverridden));
    c1.def("ClearBigFontOverride", &RunProperties::ClearBigFontOverride, DOC(Bentley, DgnPlatform, RunProperties, ClearBigFontOverride));

    c1.def("IsHasColorOverridden", &RunProperties::IsHasColorOverridden, DOC(Bentley, DgnPlatform, RunProperties, IsHasColorOverridden));
    c1.def("ClearHasColorOverride", &RunProperties::ClearHasColorOverride, DOC(Bentley, DgnPlatform, RunProperties, ClearHasColorOverride));

    c1.def("IsColorOverridden", &RunProperties::IsColorOverridden, DOC(Bentley, DgnPlatform, RunProperties, IsColorOverridden));
    c1.def("ClearColorOverride", &RunProperties::ClearColorOverride, DOC(Bentley, DgnPlatform, RunProperties, ClearColorOverride));

    c1.def("IsBoldOverridden", &RunProperties::IsBoldOverridden, DOC(Bentley, DgnPlatform, RunProperties, IsBoldOverridden));
    c1.def("ClearIsBoldOverride", &RunProperties::ClearIsBoldOverride, DOC(Bentley, DgnPlatform, RunProperties, ClearIsBoldOverride));

    c1.def("IsItalicOverridden", &RunProperties::IsItalicOverridden, DOC(Bentley, DgnPlatform, RunProperties, IsItalicOverridden));
    c1.def("ClearIsItalicOverride", &RunProperties::ClearIsItalicOverride, DOC(Bentley, DgnPlatform, RunProperties, ClearIsItalicOverride));

    c1.def("IsCustomSlantAngleOverridden", &RunProperties::IsCustomSlantAngleOverridden, DOC(Bentley, DgnPlatform, RunProperties, IsCustomSlantAngleOverridden));
    c1.def("ClearCustomSlantAngleOverride", &RunProperties::ClearCustomSlantAngleOverride, DOC(Bentley, DgnPlatform, RunProperties, ClearCustomSlantAngleOverride));

    c1.def("IsUnderlinedOverridden", &RunProperties::IsUnderlinedOverridden, DOC(Bentley, DgnPlatform, RunProperties, IsUnderlinedOverridden));
    c1.def("ClearIsUnderlinedOverride", &RunProperties::ClearIsUnderlinedOverride, DOC(Bentley, DgnPlatform, RunProperties, ClearIsUnderlinedOverride));

    c1.def("IsShouldUseUnderlineStyleOverridden", &RunProperties::IsShouldUseUnderlineStyleOverridden, DOC(Bentley, DgnPlatform, RunProperties, IsShouldUseUnderlineStyleOverridden));
    c1.def("ClearShouldUseUnderlineStyleOverride", &RunProperties::ClearShouldUseUnderlineStyleOverride, DOC(Bentley, DgnPlatform, RunProperties, ClearShouldUseUnderlineStyleOverride));

    c1.def("IsUnderlineOffsetOverridden", &RunProperties::IsUnderlineOffsetOverridden, DOC(Bentley, DgnPlatform, RunProperties, IsUnderlineOffsetOverridden));
    c1.def("ClearUnderlineOffsetOverride", &RunProperties::ClearUnderlineOffsetOverride, DOC(Bentley, DgnPlatform, RunProperties, ClearUnderlineOffsetOverride));

    c1.def("IsUnderlineColorOverridden", &RunProperties::IsUnderlineColorOverridden, DOC(Bentley, DgnPlatform, RunProperties, IsUnderlineColorOverridden));
    c1.def("ClearUnderlineColorOverride", &RunProperties::ClearUnderlineColorOverride, DOC(Bentley, DgnPlatform, RunProperties, ClearUnderlineColorOverride));

    c1.def("IsUnderlineLineStyleOverridden", &RunProperties::IsUnderlineLineStyleOverridden, DOC(Bentley, DgnPlatform, RunProperties, IsUnderlineLineStyleOverridden));
    c1.def("ClearUnderlineLineStyleOverride", &RunProperties::ClearUnderlineLineStyleOverride, DOC(Bentley, DgnPlatform, RunProperties, ClearUnderlineLineStyleOverride));

    c1.def("IsUnderlineWeightOverridden", &RunProperties::IsUnderlineWeightOverridden, DOC(Bentley, DgnPlatform, RunProperties, IsUnderlineWeightOverridden));
    c1.def("ClearUnderlineWeightOverride", &RunProperties::ClearUnderlineWeightOverride, DOC(Bentley, DgnPlatform, RunProperties, ClearUnderlineWeightOverride));

    c1.def("IsOverlinedOverridden", &RunProperties::IsOverlinedOverridden, DOC(Bentley, DgnPlatform, RunProperties, IsOverlinedOverridden));
    c1.def("ClearIsOverlinedOverride", &RunProperties::ClearIsOverlinedOverride, DOC(Bentley, DgnPlatform, RunProperties, ClearIsOverlinedOverride));

    c1.def("IsShouldUseOverlineStyleOverridden", &RunProperties::IsShouldUseOverlineStyleOverridden, DOC(Bentley, DgnPlatform, RunProperties, IsShouldUseOverlineStyleOverridden));
    c1.def("ClearShouldUseOverlineStyleOverride", &RunProperties::ClearShouldUseOverlineStyleOverride, DOC(Bentley, DgnPlatform, RunProperties, ClearShouldUseOverlineStyleOverride));

    c1.def("IsOverlineOffsetOverridden", &RunProperties::IsOverlineOffsetOverridden, DOC(Bentley, DgnPlatform, RunProperties, IsOverlineOffsetOverridden));
    c1.def("ClearOverlineOffsetOverride", &RunProperties::ClearOverlineOffsetOverride, DOC(Bentley, DgnPlatform, RunProperties, ClearOverlineOffsetOverride));

    c1.def("IsOverlineColorOverridden", &RunProperties::IsOverlineColorOverridden, DOC(Bentley, DgnPlatform, RunProperties, IsOverlineColorOverridden));
    c1.def("ClearOverlineColorOverride", &RunProperties::ClearOverlineColorOverride, DOC(Bentley, DgnPlatform, RunProperties, ClearOverlineColorOverride));

    c1.def("IsOverlineLineStyleOverridden", &RunProperties::IsOverlineLineStyleOverridden, DOC(Bentley, DgnPlatform, RunProperties, IsOverlineLineStyleOverridden));
    c1.def("ClearOverlineLineStyleOverride", &RunProperties::ClearOverlineLineStyleOverride, DOC(Bentley, DgnPlatform, RunProperties, ClearOverlineLineStyleOverride));

    c1.def("IsOverlineWeightOverridden", &RunProperties::IsOverlineWeightOverridden, DOC(Bentley, DgnPlatform, RunProperties, IsOverlineWeightOverridden));
    c1.def("ClearOverlineWeightOverride", &RunProperties::ClearOverlineWeightOverride, DOC(Bentley, DgnPlatform, RunProperties, ClearOverlineWeightOverride));

    c1.def("IsCharacterSpacingTypeOverridden", &RunProperties::IsCharacterSpacingTypeOverridden, DOC(Bentley, DgnPlatform, RunProperties, IsCharacterSpacingTypeOverridden));
    c1.def("ClearCharacterSpacingTypeOverride", &RunProperties::ClearCharacterSpacingTypeOverride, DOC(Bentley, DgnPlatform, RunProperties, ClearCharacterSpacingTypeOverride));

    c1.def("IsCharacterSpacingValueOverridden", &RunProperties::IsCharacterSpacingValueOverridden, DOC(Bentley, DgnPlatform, RunProperties, IsCharacterSpacingValueOverridden));
    c1.def("ClearCharacterSpacingValueOverride", &RunProperties::ClearCharacterSpacingValueOverride, DOC(Bentley, DgnPlatform, RunProperties, ClearCharacterSpacingValueOverride));

    c1.def("IsShouldUseBackgroundOverridden", &RunProperties::IsShouldUseBackgroundOverridden, DOC(Bentley, DgnPlatform, RunProperties, IsShouldUseBackgroundOverridden));
    c1.def("ClearShouldUseBackgroundOverride", &RunProperties::ClearShouldUseBackgroundOverride, DOC(Bentley, DgnPlatform, RunProperties, ClearShouldUseBackgroundOverride));

    c1.def("IsBackgroundFillColorOverridden", &RunProperties::IsBackgroundFillColorOverridden, DOC(Bentley, DgnPlatform, RunProperties, IsBackgroundFillColorOverridden));
    c1.def("ClearBackgroundFillColorOverride", &RunProperties::ClearBackgroundFillColorOverride, DOC(Bentley, DgnPlatform, RunProperties, ClearBackgroundFillColorOverride));

    c1.def("IsBackgroundBorderColorOverridden", &RunProperties::IsBackgroundBorderColorOverridden, DOC(Bentley, DgnPlatform, RunProperties, IsBackgroundBorderColorOverridden));
    c1.def("ClearBackgroundBorderColorOverride", &RunProperties::ClearBackgroundBorderColorOverride, DOC(Bentley, DgnPlatform, RunProperties, ClearBackgroundBorderColorOverride));

    c1.def("IsBackgroundBorderLineStyleOverridden", &RunProperties::IsBackgroundBorderLineStyleOverridden, DOC(Bentley, DgnPlatform, RunProperties, IsBackgroundBorderLineStyleOverridden));
    c1.def("ClearBackgroundBorderLineStyleOverride", &RunProperties::ClearBackgroundBorderLineStyleOverride, DOC(Bentley, DgnPlatform, RunProperties, ClearBackgroundBorderLineStyleOverride));

    c1.def("IsBackgroundBorderWeightOverridden", &RunProperties::IsBackgroundBorderWeightOverridden, DOC(Bentley, DgnPlatform, RunProperties, IsBackgroundBorderWeightOverridden));
    c1.def("ClearBackgroundBorderWeightOverride", &RunProperties::ClearBackgroundBorderWeightOverride, DOC(Bentley, DgnPlatform, RunProperties, ClearBackgroundBorderWeightOverride));

    c1.def("IsBackgroundBorderPaddingOverridden", &RunProperties::IsBackgroundBorderPaddingOverridden, DOC(Bentley, DgnPlatform, RunProperties, IsBackgroundBorderPaddingOverridden));
    c1.def("ClearBackgroundBorderPaddingOverride", &RunProperties::ClearBackgroundBorderPaddingOverride, DOC(Bentley, DgnPlatform, RunProperties, ClearBackgroundBorderPaddingOverride));

    c1.def("IsRunOffsetOverridden", &RunProperties::IsRunOffsetOverridden, DOC(Bentley, DgnPlatform, RunProperties, IsRunOffsetOverridden));
    c1.def("ClearRunOffsetOverride", &RunProperties::ClearRunOffsetOverride, DOC(Bentley, DgnPlatform, RunProperties, ClearRunOffsetOverride));

    c1.def("IsSubScriptOverridden", &RunProperties::IsSubScriptOverridden, DOC(Bentley, DgnPlatform, RunProperties, IsSubScriptOverridden));
    c1.def("ClearIsSubScriptOverride", &RunProperties::ClearIsSubScriptOverride, DOC(Bentley, DgnPlatform, RunProperties, ClearIsSubScriptOverride));

    c1.def("IsSuperScriptOverridden", &RunProperties::IsSuperScriptOverridden, DOC(Bentley, DgnPlatform, RunProperties, IsSuperScriptOverridden));
    c1.def("ClearIsSuperScriptOverride", &RunProperties::ClearIsSuperScriptOverride, DOC(Bentley, DgnPlatform, RunProperties, ClearIsSuperScriptOverride));

    c1.def("IsWidthOverridden", &RunProperties::IsWidthOverridden, DOC(Bentley, DgnPlatform, RunProperties, IsWidthOverridden));
    c1.def("ClearWidthOverride", &RunProperties::ClearWidthOverride, DOC(Bentley, DgnPlatform, RunProperties, ClearWidthOverride));

    c1.def("IsHeightOverridden", &RunProperties::IsHeightOverridden, DOC(Bentley, DgnPlatform, RunProperties, IsHeightOverridden));
    c1.def("ClearHeightOverride", &RunProperties::ClearHeightOverride, DOC(Bentley, DgnPlatform, RunProperties, ClearHeightOverride));
    }