/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyBentley\source\wstring.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <Bentley/WString.h>
#include <OpqueTypes_Bentley.h>
#include <pybind11/stl.h>

static const char *__doc_Bentley_WString_AssignA =
R"doc(Define the contents of this WString from a CharCP using the current
system locale

:param in:
    The ASCII string

:returns:
    Reference to this string.)doc";

static const char *__doc_Bentley_WString_AssignUtf8 =
R"doc(Define the contents of this WString from a Utf8CP

Parameter ``in``:
    The Utf8 string. May be NULL.

Returns:
    Reference to this string.)doc";

static const char *__doc_Bentley_WString_AssignUtf16 =
R"doc(Define the contents of this WString from a Utf8CP

:param in:
    The Utf8 string. May be NULL.

:returns:
    Reference to this string.)doc";

static const char *__doc_Bentley_WString_AppendA =
R"doc(Append a null-terminated multibyte, locale-encoded character array to
this WString. This will create a WString internally, so if you are
appending a character constant it is more efficient to use append
(L"string to append").

Parameter ``in``:
    The multibyte string

Returns:
    Reference to this string.)doc";

static const char *__doc_Bentley_WString_AppendUtf8 =
R"doc(Append a Utf8 character array to this WString. This will create a
WString internally, so if you are appending a character constant it is
more efficient to use append (L"string to append").

:param in:
    The multibyte string

:returns:
    Reference to this string.)doc";

static const char *__doc_Bentley_WString_GetMaxLocaleCharBytes =
R"doc(Get the number of bytes required to hold the current string. This is
the value to use to allocate a buffer (e.g. via _alloca) to to call
#ConvertToLocaleChars.)doc";

static const char *__doc_Bentley_WString_GetWCharCP = R"doc(Equivalent to c_str)doc";

static const char *__doc_Bentley_WString_substr =
R"doc(Get a substring.

:param __pos:
    Index of first character (default 0).

:param __n:
    Number of characters in substring (default remainder).

:returns:
    The new string.

Throws:
    std::out_of_range If pos > size().

Construct and return a new string using the *__n* characters starting
at *__pos.* If the string is too short, use the remainder of the
characters. If *__pos* is beyond the end of the string, out_of_range
is thrown.)doc";

static const char *__doc_Bentley_WString_CompareToI =
R"doc(Perform a case-insensitive comparison.

Returns:
    0 if the strings are equal (ignoring case), or -1 or 1 if this
    string should come before or after *other.*

Parameter ``other``:
    The other string.)doc";

static const char *__doc_Bentley_WString_CompareToI_2 =
R"doc(Perform a case-insensitive comparison.

:returns:
    0 if the strings are equal (ignoring case), or -1 or 1 if this
    string should come before or after *other.*

:param other:
    The other string.)doc";

static const char *__doc_Bentley_WString_CompareTo =
R"doc(Perform a (case-sensitive) comparison.

Returns:
    0 if the strings are equal, or -1 or 1 if this string should come
    before or after *other.*

Parameter ``other``:
    The other string.)doc";

static const char *__doc_Bentley_WString_CompareTo_2 =
R"doc(Perform a (case-sensitive) comparison.

:returns:
    0 if the strings are equal, or -1 or 1 if this string should come
    before or after *other.*

:param other:
    The other string.)doc";

static const char *__doc_Bentley_WString_StartsWith = R"doc(Determines if this instance starts with the provided string.)doc";

static const char *__doc_Bentley_WString_Trim =
R"doc(Removes all whitespace from the left and right sides. Whitespace
includes space, line feed, carriage return, and tab (e.g. iswspace).)doc";

static const char *__doc_Bentley_WString_Trim_2 =
R"doc(Removes all instances of any of the given characters from the left and
right sides.)doc";

static const char *__doc_Bentley_WString_PadLeft =
R"doc(Pads, if necessary, to the given totalSize by adding charToPadWith to
the left side.)doc";

static const char *__doc_Bentley_WString_PadRight =
R"doc(Pads, if necessary, to the given totalSize by adding charToPadWith to
the right side.)doc";

static const char *__doc_Bentley_WString_StartsWithI =
R"doc(Determines if this instance starts with the provided string, ignoring
case.)doc";

static const char *__doc_Bentley_WString_EndsWith = R"doc(Determines if this instance ends with the provided string.)doc";

static const char *__doc_Bentley_WString_EndsWithI =
R"doc(Determines if this instance ends with the provided string, ignoring
case.)doc";


static const char *__doc_Bentley_WString_Equals =
R"doc(Test for equality with another string.

:returns:
    true if the strings are equal.

:param other:
    The other string.)doc";

static const char *__doc_Bentley_WString_Equals_2 =
R"doc(Test for equality with another string.

Returns:
    true if the strings are equal.

Parameter ``other``:
    The other string.)doc";
    
static const char *__doc_Bentley_WString_EqualsI =
R"doc(Test for equality with another string, ignoring case.

:returns:
    true if the strings are equal (ignoring case).

:param other:
    The other string.)doc";

static const char *__doc_Bentley_WString_EqualsI_2 =
R"doc(Test for equality with another string, ignoring case.

Returns:
    true if the strings are equal (ignoring case).

Parameter ``other``:
    The other string.)doc";

static const char *__doc_Bentley_WString_Contains =
R"doc(Test for whether this string contains another string.

:param other:
    The other string.

:returns:
    true if this string contains the other string.)doc";

static const char *__doc_Bentley_WString_Contains_2 =
R"doc(Test for whether this string contains another string.

Parameter ``other``:
    The other string.

Returns:
    true if this string contains the other string.)doc";

static const char *__doc_Bentley_WString_ContainsI =
R"doc(Test for whether this string contains another string, ignoring case.

:param other:
    The other string.

:returns:
    true if this string contains the other string.)doc";

static const char *__doc_Bentley_WString_ContainsI_2 =
R"doc(Test for whether this string contains another string, ignoring case.

Parameter ``other``:
    The other string.

Returns:
    true if this string contains the other string.)doc";


static const char *__doc_Bentley_WString_ToUpper =
R"doc(Remark:
    s A WString can share the string buffer with another WString
    object. Do not try to modify its internal buffer without first
    triggering the copy-on-write mechanism to make sure that this
    object has its own copy.)doc";

static const char *__doc_Bentley_WString_ToLower =
R"doc(Remark:
    s A WString can share the string buffer with another WString
    object. Do not try to modify its internal buffer without first
    triggering the copy-on-write mechanism to make sure that this
    object has its own copy.)doc";

static const char *__doc_Bentley_WString_IsNullOrEmpty = R"doc(True if the provided string is NULL or contains no character data.)doc";

static const char *__doc_Bentley_WString_AddQuotes = R"doc(Put quotes around a string.)doc";

static const char *__doc_Bentley_WString_DropQuotes = R"doc(Remove quotes from around a string.)doc";

static const char *__doc_Bentley_WString_ReplaceAll =
R"doc(Replace all instances of a sub string. Returns the number of
replacements made.)doc";

static const char *__doc_Bentley_WString_ReplaceI =
R"doc(Replace first occurrence of findString with replaceString, ignoring
case.

:param findString:
    The substring to find.

:param replaceString:
    The replacement string.

:returns:
    true is a replacement is made.)doc";

static const char *__doc_Bentley_WString_FindI =
R"doc(Find first occurrence of findString, ignoring case.

Parameter ``findString``:
    The substring to find.

Returns:
    location of substring or std::string::npos if not found.)doc";

static const char *__doc_Bentley_Utf8String_Assign = R"doc(Construct a Utf8String by converting from a wchar_t string.)doc";

static const char *__doc_Bentley_Utf8String_SizeInBytes =
R"doc(Computes the size, in bytes, of this string's data, including its
NULL-terminator.)doc";

static const char *__doc_Bentley_Utf8String_IsAscii =
R"doc(Test if this string contains only characters less than or equal to
127.)doc";

static const char *__doc_Bentley_Utf8String_IsNullOrEmpty =
R"doc(Utility function to test if *value* represents the empty string. This
function interprets NULL to be the empty string.)doc";

static const char *__doc_Bentley_Utf8String_IsAsciiWhiteSpace =
R"doc(Determine whether the supplied character is a whitespace character in
the ascii (below 128) code page. This is necessary since the c
"isspace" function is locale specific and sometimes returns true for
the non-breaking-space character (0xA0), which is not a valid test for
a Utf8 string. Note this does not test for VT, or FF as they are
considered obsolete.)doc";

static const char *__doc_Bentley_Utf8String_CompareToI =
R"doc(Perform a case-insensitive comparison.

:returns:
    0 if the strings are equal (ignoring case), or -1 or 1 if this
    string should come before or after *other.*

:param other:
    The other string.)doc";

static const char *__doc_Bentley_Utf8String_CompareToI_2 =
R"doc(Perform a case-insensitive comparison.

Returns:
    0 if the strings are equal (ignoring case), or -1 or 1 if this
    string should come before or after *other.*

Parameter ``other``:
    The other string.)doc";



static const char *__doc_Bentley_Utf8String_CompareTo =
R"doc(Perform a (case-sensitive) comparison.

:returns:
    0 if the strings are equal, or -1 or 1 if this string should come
    before or after *other.*

:param other:
    The other string.)doc";

static const char *__doc_Bentley_Utf8String_CompareTo_2 =
R"doc(Perform a (case-sensitive) comparison.

Returns:
    0 if the strings are equal, or -1 or 1 if this string should come
    before or after *other.*

Parameter ``other``:
    The other string.)doc";

static const char *__doc_Bentley_Utf8String_Equals =
R"doc(Test for equality with another string.

:returns:
    true if the strings are equal.

:param other:
    The other string.)doc";

static const char *__doc_Bentley_Utf8String_Equals_2 =
R"doc(Test for equality with another string.

Returns:
    true if the strings are equal.

Parameter ``other``:
    The other string.)doc";

static const char *__doc_Bentley_Utf8String_EqualsI =
R"doc(Test for equality with another string, ignoring case.

:returns:
    true if the strings are equal (ignoring case).

:param other:
    The other string.)doc";

static const char *__doc_Bentley_Utf8String_EqualsI_2 =
R"doc(Test for equality with another string, ignoring case.

Returns:
    true if the strings are equal (ignoring case).

Parameter ``other``:
    The other string.)doc";

static const char *__doc_Bentley_Utf8String_Trim =
R"doc(Removes all whitespace from the left and right sides. Whitespace
includes space, line feed, carriage return, and tab (e.g. iswspace).)doc";

static const char *__doc_Bentley_Utf8String_Trim_2 =
R"doc(Removes all instances of any of the given characters from the left and
right sides.)doc";

static const char *__doc_Bentley_Utf8String_TrimEnd =
R"doc(Removes all whitespace from the end. Whitespace includes space, line
feed, carriage return, and tab (e.g. iswspace).)doc";

static const char *__doc_Bentley_Utf8String_StartsWith = R"doc(Determines if this instance starts with the provided string.)doc";


static const char *__doc_Bentley_Utf8String_ToLower =
R"doc(Converts this string, in-place, to all lower case.

Remark:
    s This function can be very slow if the string contains non-ascii
    characters.)doc";

static const char *__doc_Bentley_Utf8String_AssignOrClear =
R"doc(Update this string to be equal to *in.* If *in* is NULL, clear this
string.)doc";

static const char *__doc_Bentley_Utf8String_ReplaceAll =
R"doc(Replace all instances of a sub string. Returns the number of
replacements made.)doc";

static const char *__doc_Bentley_Utf8String_ToLowerChar = R"doc(Equivalent to tolower)doc";

static const char *__doc_Bentley_Utf8String_GetNextToken =
R"doc(Reads the next token delimited by any character in *delims* or \0.

:param next:
    set to next token, if found, or cleared if not

:param delims:
    the characters that could delimit the tokens

:param offset:
    where to start search

:returns:
    1 beyond the end of the current token or npos if token not found
    Example

``
 Read lines from a string, where each line is delimited by \n. The last line need not have a trailing \n.
    size_t offset = 0;
    Utf8String m;
    while ((offset = m_virtuals.GetNextToken (m, "\n", offset)) != Utf8String::npos)
        {
        printf ("%s\n", m.c_str());
        }
``

@Note If this string ends with a delimiter, then the last token
returned is the one before the trailing delimiter. If this string does
not end with a delimiter, then the last token is everything following
the last delimiter (if any) and the end of this string. If this string
has no delimiters at all, then the first and only token returned is
the string itself. So, for example, if this string were "abc\n" then
GetNextToken (next, "\n", 0) would set next to "abc" and return 4, and
GetNextToken (next, "\n", 4) would return npos. If this string were
"abc", the two calls would return the same results.)doc";

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_WString(py::module_& m)
    {
    //===================================================================================
    // struct AString
    py::class_<AString> c1(m, "AString","A string class that has many of the same capabilities as std::string, plus\nadditional functions such as conversion");
    py::bind_vector< AStringArray >(m, "AStringArray", py::module_local(false));    

    c1.def(py::init<>());
    c1.def(py::init<CharCP>(), "str"_a);    
    c1.def(py::init<CharCP, size_t>(), "__s"_a, "__n"_a);
    c1.def(py::init<size_t, char>(), "__n"_a, "__c"_a);    

    c1.def("__bool__", [] (AString const& s)->bool { return !s.empty(); });
    c1.def("__len__", &AString::size);
    c1.def("clear", &AString::clear);    
    c1.def("__repr__", [] (AString const& s) { return s.c_str(); });
    c1.def("__iadd__", [] (AString& self, AString const& arg) { self += arg; return self; });
    c1.def("__add__", [] (AString const& arg1, AString const& arg2) { return AString(arg1 + arg2); });
    c1.def("__repr__", [] (AString const& self) { return self.c_str(); });
    c1.def("__eq__", [] (AString const& self, AString const& other) { return self==other; });

    //===================================================================================
    // struct WString
    py::class_<WString> c2(m, "WString","A string class that has many of the same capabilities as std::string, \nplus additional functions such as conversion from UTF-8, UTF-16, and local-encoded strings, \ncase-insensitive compare, trimming, padding, and others.");
    py::bind_vector< WStringArray >(m, "WStringArray", py::module_local(false));
    
    py::bind_map< WStringWStringMap >(m, "WStringWStringMap", py::module_local(false));
    py::bind_map< WStringWCharMap >(m, "WStringWCharMap", py::module_local(false));
    py::bind_map< IntIntMap >(m, "IntIntMap", py::module_local(false));

    c2.def(py::init<>());
    c2.def(py::init<WCharCP>(), "str"_a);
    c2.def(py::init<WCharCP, size_t>(), "__s"_a, "__n"_a);
    c2.def(py::init<size_t, wchar_t>(), "__n"_a, "__c"_a);
    c2.def(py::init<Utf16CP>(), "in"_a, "Construct a WString from a Utf16 encoded Unicode string");
    c2.def(py::init<CharCP, bool>(), "in"_a, "isUtf8"_a = false, "Construct a WString from a CharCP using either the current system locale or Utf8");
    c2.def(py::init<CharCP, BentleyCharEncoding>(), "in"_a, "encoding"_a,"Construct a WString from a CharCP string in the specified encoding");

    c2.def("__bool__", [] (WString const& s)->bool { return !s.empty(); });
    c2.def("__len__", &WString::size);
    c2.def("clear", &WString::clear);
    c2.def("__iadd__", [] (WString& self, WString const& arg) { self += arg; return self; });
    c2.def("__add__", [] (WString const& arg1, WString const& arg2) { return WString(arg1 + arg2); });
    c2.def("__repr__", [] (WString const& self) { return self.c_str(); });
    c2.def("__eq__", [] (WStringCR self, WStringCR other) { return self.Equals(other); });
    
    c2.def("AssignA", &WString::AssignA, py::return_value_policy::reference_internal, "in"_a, DOC(Bentley, WString, AssignA));
    c2.def("AssignUtf8", &WString::AssignUtf8, py::return_value_policy::reference_internal, "in"_a, DOC(Bentley, WString, AssignUtf8));
    c2.def("AssignUtf16", &WString::AssignUtf16,  py::return_value_policy::reference_internal, "in"_a,  DOC(Bentley, WString, AssignUtf16));
    c2.def("AssignOrClear", &WString::AssignOrClear, py::return_value_policy::reference_internal, "in"_a);

    c2.def("AppendA", &WString::AppendA, py::return_value_policy::reference_internal, "in"_a, DOC(Bentley, WString, AppendA));
    c2.def("AppendUtf8", &WString::AppendUtf8, py::return_value_policy::reference_internal, "in"_a, DOC(Bentley, WString, AppendUtf8));
    c2.def("GetMaxLocaleCharBytes", &WString::GetMaxLocaleCharBytes, DOC(Bentley, WString, GetMaxLocaleCharBytes));
    
    c2.def("GetWCharCP", &WString::GetWCharCP, py::return_value_policy::copy, DOC(Bentley, WString, GetWCharCP));
    c2.def("substr", &WString::substr, "pos"_a = 0, "n"_a = WString::npos,  DOC(Bentley, WString, substr));

    c2.def("CompareToI", py::overload_cast<WCharCP>(&WString::CompareToI, py::const_), "other"_a,  DOC(Bentley, WString, CompareToI));
    c2.def("CompareToI", py::overload_cast<WStringCR>(&WString::CompareToI, py::const_), "other"_a, DOC(Bentley, WString, CompareToI, 2));
    c2.def("CompareTo", py::overload_cast<WCharCP>(&WString::CompareTo, py::const_), "other"_a,  DOC(Bentley, WString, CompareTo));
    c2.def("CompareTo", py::overload_cast<WStringCR>(&WString::CompareTo, py::const_), "other"_a,  DOC(Bentley, WString, CompareTo, 2));
    c2.def("Equals", py::overload_cast<WCharCP>(&WString::Equals, py::const_), "other"_a, DOC(Bentley, WString, Equals));
    c2.def("Equals", py::overload_cast<WStringCR>(&WString::Equals, py::const_), "other"_a, DOC(Bentley, WString, Equals, 2));
    c2.def("EqualsI", py::overload_cast<WCharCP>(&WString::EqualsI, py::const_), "other"_a, DOC(Bentley, WString, EqualsI));
    c2.def("EqualsI", py::overload_cast<WStringCR>(&WString::EqualsI, py::const_), "other"_a,  DOC(Bentley, WString, EqualsI, 2));

    c2.def("Trim", py::overload_cast<WCharCP>(&WString::Trim), "trimCharacters"_a, DOC(Bentley, WString, Trim));
    c2.def("Trim", py::overload_cast<>(&WString::Trim), DOC(Bentley, WString, Trim, 2));
    c2.def("PadLeft", &WString::PadLeft, "totalSize"_a, "charToPadWidth"_a, DOC(Bentley, WString, PadLeft));
    c2.def("PadRight", &WString::PadRight, "totalSize"_a, "charToPadWidth"_a,  DOC(Bentley, WString, PadRight));

    c2.def("StartsWith", &WString::StartsWith, "startChars"_a, DOC(Bentley, WString, StartsWith));
    c2.def("StartsWithI", &WString::StartsWithI, "startChars"_a, DOC(Bentley, WString, StartsWithI));

    c2.def("EndsWith", &WString::EndsWith, "endChars"_a,DOC(Bentley, WString, EndsWith));
    c2.def("EndsWithI", &WString::EndsWithI, "endChars"_a,DOC(Bentley, WString, EndsWithI));

    c2.def("Contains", py::overload_cast<WCharCP>(&WString::Contains, py::const_), "other"_a, DOC(Bentley, WString, Contains));
    c2.def("Contains", py::overload_cast<WStringCR>(&WString::Contains, py::const_), "other"_a, DOC(Bentley, WString, Contains, 2));
    c2.def("ContainsI", py::overload_cast<WCharCP>(&WString::ContainsI, py::const_), "other"_a, DOC(Bentley, WString, ContainsI));
    c2.def("ContainsI", py::overload_cast<WStringCR>(&WString::ContainsI, py::const_), "other"_a, DOC(Bentley, WString, ContainsI, 2));    

    c2.def("ToUpper", &WString::ToUpper,DOC(Bentley, WString, ToUpper));
    c2.def("ToLower", &WString::ToLower,DOC(Bentley, WString, ToLower));
    c2.def_static("IsNullOrEmpty", &WString::IsNullOrEmpty, "str"_a, DOC(Bentley, WString, IsNullOrEmpty));

    c2.def("AddQuotes", &WString::AddQuotes, DOC(Bentley, WString, AddQuotes));
    c2.def("DropQuotes", &WString::DropQuotes, DOC(Bentley, WString, DropQuotes));

    c2.def("ReplaceAll", &WString::ReplaceAll, "subStringToReplace"_a, "replacement"_a, DOC(Bentley, WString, ReplaceAll));
    c2.def("FindI", &WString::FindI, "findString"_a, DOC(Bentley, WString, ReplaceAll));
    c2.def("ReplaceI", &WString::ReplaceI, "findString"_a, "replaceString"_a,  DOC(Bentley, WString, ReplaceI));
    c2.def("IsEmpty", [](WString const& s)->bool { return s.empty(); });

    //===================================================================================
    // struct Utf8String
    py::class_<Utf8String> c3(m, "Utf8String","Contains a UTF-8 encoded string. This class has many of the capabilities of a python string\nThis class also defines utility functions for constructing and manipulating the string");
    py::bind_vector< Utf8StringArray >(m, "Utf8StringArray", py::module_local(false));

    c3.def(py::init<>());
    c3.def(py::init<Utf8CP>(), "str"_a);
    c3.def(py::init<CharCP, size_t>(), "__s"_a, "__n"_a);
    c3.def(py::init<size_t, char>(), "__n"_a, "__c"_a);    
    c3.def(py::init<WString>(), "str"_a);

    c3.def("__bool__", [] (Utf8String const& s)->bool { return !s.empty(); });
    c3.def("__len__", &Utf8String::size);
    c3.def("clear", &Utf8String::clear);
    c3.def("__iadd__", [] (Utf8String& self, Utf8String const& arg) { self += arg; return self; });
    c3.def("__add__", [] (Utf8String const& arg1, Utf8String const& arg2) { return Utf8String(arg1 + arg2); });
    c3.def("__repr__", [] (Utf8String const& s) { return s.c_str(); });
    c3.def("__eq__", [] (Utf8StringCR self, Utf8StringCR other) { return self.Equals(other); });

    c3.def("Assign", &Utf8String::Assign, py::return_value_policy::reference, "str"_a, DOC(Bentley, Utf8String, Assign));
    c3.def("SizeInBytes", &Utf8String::SizeInBytes, DOC(Bentley, Utf8String, SizeInBytes));

    c3.def("IsAscii", &Utf8String::IsAscii, DOC(Bentley, Utf8String, IsAscii));
    c3.def_static("IsNullOrEmpty", &Utf8String::IsNullOrEmpty, "value"_a, DOC(Bentley, Utf8String, IsNullOrEmpty));
    c3.def_static("IsAsciiWhiteSpace", &Utf8String::IsAsciiWhiteSpace, "val"_a, DOC(Bentley, Utf8String, IsAsciiWhiteSpace));

    c3.def("CompareToI", py::overload_cast<Utf8CP>(&Utf8String::CompareToI, py::const_), "other"_a, DOC(Bentley, Utf8String, CompareToI));
    c3.def("CompareToI", py::overload_cast<Utf8StringCR>(&Utf8String::CompareToI, py::const_), "other"_a, DOC(Bentley, Utf8String, CompareToI, 2));
    c3.def("CompareTo", py::overload_cast<Utf8CP>(&Utf8String::CompareTo, py::const_), "other"_a,  DOC(Bentley, Utf8String, CompareTo));
    c3.def("CompareTo", py::overload_cast<Utf8StringCR>(&Utf8String::CompareTo, py::const_), "other"_a,   DOC(Bentley, Utf8String, CompareTo, 2));
    
    c3.def("Equals", py::overload_cast<Utf8CP>(&Utf8String::Equals, py::const_), "other"_a, DOC(Bentley, Utf8String, Equals));
    c3.def("Equals", py::overload_cast<Utf8StringCR>(&Utf8String::Equals, py::const_), "other"_a,  DOC(Bentley, Utf8String, Equals, 2));
    c3.def("EqualsI", py::overload_cast<Utf8CP>(&Utf8String::EqualsI, py::const_), "other"_a, DOC(Bentley, Utf8String, EqualsI));
    c3.def("EqualsI", py::overload_cast<Utf8StringCR>(&Utf8String::EqualsI, py::const_), "other"_a,  DOC(Bentley, Utf8String, EqualsI, 2));

    c3.def("Trim", py::overload_cast<>(&Utf8String::Trim),  DOC(Bentley, Utf8String, Trim));
    c3.def("Trim", py::overload_cast<Utf8CP>(&Utf8String::Trim), "trimCharacters"_a, DOC(Bentley, Utf8String, Trim, 2));
    c3.def("TrimEnd", &Utf8String::TrimEnd, py::return_value_policy::reference, DOC(Bentley, Utf8String, TrimEnd));
    
    c3.def("StartsWith", &Utf8String::StartsWith, "startChars"_a, DOC(Bentley, Utf8String, StartsWith));
    c3.def("AssignOrClear", &Utf8String::AssignOrClear, "in"_a, DOC(Bentley, Utf8String, AssignOrClear));
    c3.def("ReplaceAll", &Utf8String::ReplaceAll, "subStringToReplace"_a, "replacement"_a,  DOC(Bentley, Utf8String, ReplaceAll));
    c3.def_static("ToLowerChar", &Utf8String::ToLowerChar, "c"_a, DOC(Bentley, Utf8String, ToLowerChar));
    c3.def("ToLower", &Utf8String::ToLower, DOC(Bentley, Utf8String, ToLower));
    c3.def("GetNextToken", &Utf8String::GetNextToken, "next"_a, "delims"_a, "offset"_a,  DOC(Bentley, Utf8String, GetNextToken)); 


    }
