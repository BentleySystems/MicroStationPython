/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyBentley\source\valueformat.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <Bentley/ValueFormat.h>



static const char * __doc_Bentley_DoubleFormatter_ToString = R"doc(Use the settings defined in this formatter to convert a double value
to a string.

Parameter ``value``:
    value to format.)doc";

static const char * __doc_Bentley_DoubleFormatter_Clone = R"doc(Construct a formatter which is a duplicate of an existing formatter.)doc";

static const char * __doc_Bentley_DoubleFormatter_Create = R"doc(Construct a formatter with default settings.)doc";

static const char * __doc_Bentley_DoubleFormatter_GetTypeFromPrecision = R"doc(Categorize a precision value.)doc";

static const char * __doc_Bentley_DoubleFormatterBase_SetLeadingZero = R"doc(Set the formatter's leading zero behavior. A leading zero is only
included for values less than 1.0. Ex. " 0.5 " vs. " .5 "

Parameter ``newVal``:
    pass true to include a leading zero for values less than 1.0)doc";

static const char * __doc_Bentley_DoubleFormatterBase_SetThousandsSeparator = R"doc(Set the formatter's thousands separator.)doc";

static const char * __doc_Bentley_DoubleFormatterBase_GetThousandsSeparator = R"doc(Get the thousands separator used by this formatter.)doc";

static const char * __doc_Bentley_DoubleFormatterBase_SetInsertThousandsSeparator = R"doc(Specify if the thousands separator should be inserted or not.)doc";

static const char * __doc_Bentley_DoubleFormatterBase_GetInsertThousandsSeparator = R"doc(Get the value indicating if the thousands separator is inserted by
this formatter.)doc";

static const char * __doc_Bentley_DoubleFormatterBase_SetDecimalSeparator = R"doc(Set the formatter's decimal separator.)doc";

static const char * __doc_Bentley_DoubleFormatterBase_GetDecimalSeparator = R"doc(Get the decimal separator used by this formatter.)doc";

static const char * __doc_Bentley_DoubleFormatterBase_SetPrecision = R"doc(Set the formatter's precision.)doc";

static const char * __doc_Bentley_DoubleFormatterBase_GetPrecision = R"doc(Get the precision used by this formatter.)doc";



/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_ValueFormat(py::module_& m)
    {
    //===================================================================================
    // struct DoubleFormatterBase
    py::class_< DoubleFormatterBase> c1(m, "DoubleFormatterBase");

    c1.def_property("Precision", &DoubleFormatterBase::GetPrecision, py::overload_cast<PrecisionFormat>(&DoubleFormatterBase::SetPrecision));
    c1.def("GetPrecision", &DoubleFormatterBase::GetPrecision, DOC(Bentley, DoubleFormatterBase, GetPrecision));
    c1.def("SetPrecision", py::overload_cast<PrecisionFormat>(&DoubleFormatterBase::SetPrecision), "newVal"_a, DOC(Bentley, DoubleFormatterBase, SetPrecision));

    c1.def_property("DecimalSeparator", &DoubleFormatterBase::GetDecimalSeparator, &DoubleFormatterBase::SetDecimalSeparator);
    c1.def("GetDecimalSeparator", &DoubleFormatterBase::GetDecimalSeparator, DOC(Bentley, DoubleFormatterBase, GetDecimalSeparator));
    c1.def("SetDecimalSeparator", &DoubleFormatterBase::SetDecimalSeparator, "newVal"_a, DOC(Bentley, DoubleFormatterBase, SetDecimalSeparator));

    c1.def_property("InsertThousandsSeparator", &DoubleFormatterBase::GetInsertThousandsSeparator, &DoubleFormatterBase::SetInsertThousandsSeparator);
    c1.def("GetInsertThousandsSeparator", &DoubleFormatterBase::GetInsertThousandsSeparator, DOC(Bentley, DoubleFormatterBase, GetInsertThousandsSeparator));
    c1.def("SetInsertThousandsSeparator", &DoubleFormatterBase::SetInsertThousandsSeparator, "newVal"_a, DOC(Bentley, DoubleFormatterBase, SetInsertThousandsSeparator));

    c1.def_property("ThousandsSeparator", &DoubleFormatterBase::GetThousandsSeparator, &DoubleFormatterBase::SetThousandsSeparator);
    c1.def("GetThousandsSeparator", &DoubleFormatterBase::GetThousandsSeparator, DOC(Bentley, DoubleFormatterBase, GetThousandsSeparator));
    c1.def("SetThousandsSeparator", &DoubleFormatterBase::SetThousandsSeparator, "newVal"_a, DOC(Bentley, DoubleFormatterBase, SetThousandsSeparator));

    c1.def_property("LeadingZero", &DoubleFormatterBase::GetLeadingZero, &DoubleFormatterBase::SetLeadingZero,"The formatter's leading zero behavior.  A leading zero is only included for values less than 1.0.  Ex. \"0.5\" vs. \".5\"");
    c1.def("GetLeadingZero", &DoubleFormatterBase::GetLeadingZero,"Test if this formatter will include a leading zero.  A leading zero is only\nincluded for values less than 1.0.  Ex. \"0.5\" vs. \".5\"");
    c1.def("SetLeadingZero", &DoubleFormatterBase::SetLeadingZero, "newVal"_a, DOC(Bentley, DoubleFormatterBase, SetLeadingZero));

    c1.def_property("TrailingZeros", &DoubleFormatterBase::GetTrailingZeros, &DoubleFormatterBase::SetTrailingZeros);
    c1.def("GetTrailingZeros", &DoubleFormatterBase::GetTrailingZeros,"Test if this formatter will include trailing zeros.  Trailing zeros are only included\nup to the requested precision.  Ex. \"30.500\" vs. \"30.5\"");
    c1.def("SetTrailingZeros", &DoubleFormatterBase::SetTrailingZeros, "newVal"_a,"Set the formatter's trailing zeros behavior.  Trailing zeros are only included\nup to the requested precision.  Ex. \"30.500\" vs. \"30.5\"\n@param in  newVal pass true to zero pad the output string to the requested precision.");

    c1.def("__repr__", [] (DoubleFormatterBase const& self)
           {
           return "[Precision={}, DecimalSeparator={}, InsertThousandsSeparator={}, ThousandsSeparator={}, LeadingZero={}, TrailingZeros={}]"_s
               .format(self.GetPrecision(),
                       self.GetDecimalSeparator(),
                       self.GetInsertThousandsSeparator(),
                       self.GetThousandsSeparator(),
                       self.GetLeadingZero(),
                       self.GetTrailingZeros());
           });

    //===================================================================================
    // struct DoubleFormatter
    py::class_< DoubleFormatter, DoubleFormatterBase> c2(m, "DoubleFormatter", py::multiple_inheritance());

    c2.def_static("GetTypeFromPrecision", &DoubleFormatter::GetTypeFromPrecision, "format"_a, DOC(Bentley, DoubleFormatter, GetTypeFromPrecision));
    c2.def_static("Create", &DoubleFormatter::Create, DOC(Bentley, DoubleFormatter, Create));
    c2.def("Clone", &DoubleFormatter::Clone, DOC(Bentley, DoubleFormatter, Clone));
    c2.def("ToString", &DoubleFormatter::ToString, "value"_a, DOC(Bentley, DoubleFormatter, ToString)); 

    c2.def("__repr__", [] (DoubleFormatterCR self)
           {
           return "[{}]"_s.format((DoubleFormatterBase const&) self);
           });
    }