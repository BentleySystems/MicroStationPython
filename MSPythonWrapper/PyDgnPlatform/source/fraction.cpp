/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnPlatform\source\fraction.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <DgnPlatform/TextBlock/Fraction.h>



static const char * __doc_Bentley_DgnPlatform_Fraction_GetDenominator =R"doc(Gets the denominator character stream. @note While the numerator and
denominator are represented as character streams, their formatting is
kept in sync, as fractions do not currently support mixed formatting.)doc";

static const char * __doc_Bentley_DgnPlatform_Fraction_GetNumerator =R"doc(Gets the numerator character stream. @note While the numerator and
denominator are represented as character streams, their formatting is
kept in sync, as fractions do not currently support mixed formatting.)doc";

static const char * __doc_Bentley_DgnPlatform_Fraction_SetAlignment =R"doc(Sets the alignment of the fraction with other runs in the line.

See also:
    GetAlignment for additional notes)doc";

static const char * __doc_Bentley_DgnPlatform_Fraction_GetAlignment =R"doc(Gets the alignment of the fraction with other runs in the line. @note
Since stacked fractions are typically much taller then surrounding
runs, this property is important to vertical alignment within the
line.)doc";

static const char * __doc_Bentley_DgnPlatform_Fraction_GetFractionType =R"doc(Gets the type of this fraction. @note This directly corresponds to the
sub-class type, so a dynamic_cast would also suffice.)doc";

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_Fraction(py::module_& m)
    {
    //===================================================================================
    // struct Fraction
    py::class_< Fraction, Run> c1(m, "Fraction");

    c1.def_property_readonly("FractionType", &Fraction::GetFractionType);
    c1.def("GetFractionType", &Fraction::GetFractionType, DOC(Bentley, DgnPlatform, Fraction, GetFractionType));

    c1.def_property("Alignment", &Fraction::GetAlignment, &Fraction::SetAlignment);
    c1.def("GetAlignment", &Fraction::GetAlignment, DOC(Bentley, DgnPlatform, Fraction, GetAlignment));
    c1.def("SetAlignment", &Fraction::SetAlignment, "newVal"_a, DOC(Bentley, DgnPlatform, Fraction, SetAlignment));

    c1.def_property_readonly("Numerator", [] (Fraction const& self)
                             {
                             return std::unique_ptr<CharStream, py::nodelete>(const_cast<CharStreamP>(self.GetNumerator()));
                             });
    c1.def("GetNumerator", [] (Fraction const& self)
                             {
                             return std::unique_ptr<CharStream, py::nodelete>(const_cast<CharStreamP>(self.GetNumerator()));
                             }, DOC(Bentley, DgnPlatform, Fraction, GetNumerator));

    c1.def_property_readonly("Denominator", [] (Fraction const& self)
                             {
                             return std::unique_ptr<CharStream, py::nodelete>(const_cast<CharStreamP>(self.GetDenominator()));
                             });
    c1.def("GetDenominator", [] (Fraction const& self)
                             {
                             return std::unique_ptr<CharStream, py::nodelete>(const_cast<CharStreamP>(self.GetDenominator()));
                             }, DOC(Bentley, DgnPlatform, Fraction, GetDenominator));

    //===================================================================================
    // struct NoBarFraction
    py::class_< NoBarFraction, Fraction> c2(m, "NoBarFraction");

    //===================================================================================
    // struct HorizontalBarFraction
    py::class_< HorizontalBarFraction, Fraction> c3(m, "HorizontalBarFraction");

    //===================================================================================
    // struct DiagonalBarFraction
    py::class_< DiagonalBarFraction, Fraction> c4(m, "DiagonalBarFraction");
    }