/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyBentley\source\bestringutilities.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <Bentley/BeStringUtilities.h>
#include <OpqueTypes_Bentley.h>



static const char * __doc_Bentley_BeStringUtilities_LexicographicCompare = R"doc(Do a lexicographic comparison of specified strings. This is an
alphabetical sort that also takes numbers into account, such that
" file9 " will come before " file11 " in the sort order (even though
alphabetically 1 is before 9). This method always ignores case.
param in  pszName1 (input) first string param in  pszName2 (input) second string
return 0 if strings are equal,<0 if pszName1 is less than pszName2,
else> 0)doc";

static const char * __doc_Bentley_BeStringUtilities_ParseUInt64 = R"doc(Parses a string containing an integer number in decimal format

:param value:
    The resulting integer number

:param string:
    A string representation of a decimal value.

Remark:
    s ``string`` must not contain any extra characters or whitespace.
    This function does not skip leading whitespace or stop at trailing
    characters, as a function like strtoul would do. That kind of
    parsing is for the higher level caller to do.)doc";

static const char * __doc_Bentley_BeStringUtilities_FormatUInt64 = R"doc(Formats an unsigned 64-bit integer using the same options supported by
printf's " % x " and " % X " specifiers.

:param dest:
    The buffer which will hold the string representation of the
    integer. Must not be NULL.

:param numCharsInBuffer:
    The maximum number of characters which can be written to *dest,*
    including the null terminator. Must be at least 1.

:param val:
    The value to format

:param opts:
    Flags indicating how formatting should be applied

:param width:
    The minimum number of characters in the formatted string.
    Additional characters will be added according to *opts.* Width >
    18 will be truncated to 18.

:param precision:
    The minimum number of digits in the formatted string. Leading
    zeros will be prepended to match the precision. Precision> 16
    will be truncated to 16.

:returns:
    Returns the number of characters written to *dest,* not including
    the null terminator

Remark:
    s If the length of the formatted string exceeds
    *numCharsInBuffer,* the string is truncated (i.e.,
    dest\\[numCharsInBuffer-1\\] = 0;)

Remark:
    s This method is provided to produce the same hexadecimal
    formatting as Snwprintf(), but much more efficiently.

Remark:
    s Typical usage:FormatUInt64(dest, count, val,
    HexFormatOptions::None) to produce the minimal representation or
    FormatUInt64(dest, count, val, HexFormatOptions::LeadingZeros, n)
    to produce fixed width (e.g. n=8 or 16) with leading zeros.)doc";



static const char * __doc_Bentley_BeStringUtilities_ParseArguments = R"doc(Default logic for parsing a user supplied argument list. Tokenizes
based on whitespace and does not tokenize within double-quoted
substrings.

:param subStrings:
    The resulting sub strings will be added to this collection

:param inString:
    The string to tokenize; cannot be NULL or empty

:param auxDelimiters:
    (optional) Each character in the string Will be used as a
    delimiter in addition to whitespace.)doc";

static const char * __doc_Bentley_BeStringUtilities_Join = R"doc(Joins a list of strings into a single string, optionally separated by
a delimiter.

:param strings:
    The list of strings to join

:param delimiter:
    The delimiter to be inserted between each string

:returns:
    Returns a string comprised of all strings in the list in input
    order, separated by the supplied delimiter.)doc";

static const char * __doc_Bentley_BeStringUtilities_Split = R"doc(Tokenizes a string based on the provided delimiters, and adds a
WString for each token into the provided collection. This essentially
wraps wcstok for more convenient access.

:param str:
    The string to tokenize; cannot be NULL or empty

:param delimiters:
    One or more delimiters; cannot be NULL or empty

:param tokens:
    One or more tokens)doc";

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_BeStringUtilities(py::module_& m)
    {
    //===================================================================================
    // enum class HexFormatOptions
    py::enum_< HexFormatOptions>(m, "HexFormatOptions", py::arithmetic())
        .value("eNone", HexFormatOptions::None)               
        .value("eLeftJustify", HexFormatOptions::LeftJustify)
        .value("eIncludePrefix", HexFormatOptions::IncludePrefix)
        .value("eUppercase", HexFormatOptions::Uppercase)
        .value("eLeadingZeros", HexFormatOptions::LeadingZeros)
        .value("eUsePrecision", HexFormatOptions::UsePrecision)
         .export_values();

    //===================================================================================
    // struct BeStringUtilities
    py::class_<BeStringUtilities> c1(m, "BeStringUtilities");
    py::bind_vector< bvector<wchar_t> >(m, "WCharArray", py::module_local(false));

    c1.def_readonly_static("NPOS", &BeStringUtilities::NPOS);
    c1.def_readonly_static("AsManyAsPossible", &BeStringUtilities::AsManyAsPossible);

    c1.def_static("Split", [](WStringCR str, WStringCR delimiters, WStringArray& tokens)
                  {
                  BeStringUtilities::Split(str.GetWCharCP(), delimiters.GetWCharCP(), tokens);
                  }, "str"_a, "delimiters"_a, "tokens"_a, DOC(Bentley, BeStringUtilities, Split), DOC(Bentley, BeStringUtilities, Split));

    c1.def_static("Split", [](WStringCR str, WStringCR delimiters, WStringCR escapeChars, WStringArray& tokens)
                  {
                  BeStringUtilities::Split(str.GetWCharCP(), delimiters.GetWCharCP(), tokens);
                  }, "str"_a, "delimiters"_a, "escapeChars"_a,"tokens"_a, DOC(Bentley, BeStringUtilities, Split), DOC(Bentley, BeStringUtilities, Split));

    c1.def_static("Join", &BeStringUtilities::Join, "strings"_a, "delimiter"_a, DOC(Bentley, BeStringUtilities, Join));

    c1.def_static("ParseArguments", [](WStringArray& subStrings, WStringCR inString, WStringCR auxDelimiters)
                  {
                  return BeStringUtilities::ParseArguments(subStrings, inString.GetWCharCP(), auxDelimiters.GetWCharCP());
                  }, "subStrings"_a, "inString"_a, "auxDelimiters"_a, DOC(Bentley, BeStringUtilities, ParseArguments), DOC(Bentley, BeStringUtilities, ParseArguments));

    c1.def_static("FormatUInt64", [](WString& dest, UInt64 val, HexFormatOptions opts, UInt8 width, UInt8 precision)
                  {
                  wchar_t  buf[0x20] = {0};
                  int cnt = BeStringUtilities::FormatUInt64(buf, 0x20, val, opts, width, precision);
                  if(cnt>0)dest.append(buf);
                  return cnt;
                  }, "dest"_a, "val"_a, "opts"_a, "width"_a = 0, "precision"_a = 1, DOC(Bentley, BeStringUtilities, FormatUInt64), DOC(Bentley, BeStringUtilities, FormatUInt64));

    c1.def_static("ParseUInt64", [](uint64_t& value, WStringCR string)
                  {
                  BentleyStatus status = BeStringUtilities::ParseUInt64(value, string.GetWCharCP());
                  return py::make_tuple(value, status);
                  }, "value"_a, "string"_a, DOC(Bentley, BeStringUtilities, ParseUInt64), DOC(Bentley, BeStringUtilities, ParseUInt64));

    c1.def_static("LexicographicCompare", [](WStringCR value0, WStringCR value1)
                  {
                  return BeStringUtilities::LexicographicCompare (value0.GetWCharCP(), value1.GetWCharCP());
                  }, "value0"_a, "value1"_a, DOC(Bentley, BeStringUtilities, LexicographicCompare), DOC(Bentley, BeStringUtilities, LexicographicCompare));

    c1.def_static("WCharToUtf8", &BeStringUtilities::WCharToUtf8, "outStr"_a, "inStr"_a, "_count"_a = BeStringUtilities::AsManyAsPossible);

    m.def("BeGetUserName", &BeGetUserName);
    m.def("BeGetUserNameA", &BeGetUserNameA);
    m.def("BeGetComputerName", &BeGetComputerName);
    m.def("BeGetComputerNameA", &BeGetComputerNameA);

    }
