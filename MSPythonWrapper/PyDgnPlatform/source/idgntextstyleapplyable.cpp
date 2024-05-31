/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnPlatform\source\idgntextstyleapplyable.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <DgnPlatform/TextBlock/IDgnTextStyleApplyable.h>



static const char * __doc_Bentley_DgnPlatform_IDgnTextStyleApplyable_RemoveTextStyle =R"doc(Removes any style association with this instance.)doc";

static const char * __doc_Bentley_DgnPlatform_IDgnTextStyleApplyable_ApplyTextStyle =R"doc(Applies a text style to this instance. @note Normal operation is to
provide a text style that is already in the file, and to set
respectOverrides.<br><br> <table cellspacing=" 0 " cellpadding=" 2 "
border=" 1 "> <tr> <td></td> <td>**Style Already in File**</td>
<td>**Style Not Already in File**</td> </tr> <tr>
<td>**respectOverrides**</td> <td>Properties Copied:<i>Non-
Overridden</i><br>Overrides Cleared:<i>No</i><br>Associated:
<i>Yes</i></td> <td>Properties Copied:<i>All</i><br>Overrides
Cleared:<i>Yes</i><br>Associated:<i>No</i></td> </tr> <tr>
<td>**!respectOverrides**</td> <td>Properties Copied:
<i>All</i><br>Overrides Cleared:<i>Yes</i><br>Associated:
<i>Yes</i></td> <td>Properties Copied:<i>All</i><br>Overrides
Cleared:<i>Yes</i><br>Associated:<i>No</i></td> </tr> </table>)doc";

static const char * __doc_Bentley_DgnPlatform_IDgnTextStyleApplyable_GetTextStyleId =R"doc(Gets the text style ID. Zero implies no text style.)doc";

static const char * __doc_Bentley_DgnPlatform_IDgnTextStyleApplyable_HasTextStyle =R"doc(True if this instance has a text style associated with it.)doc";

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_IDgnTextStyleApplyable(py::module_& m)
    {
    //===================================================================================
    // struct IDgnTextStyleApplyable
    py::class_< IDgnTextStyleApplyable> c1(m, "IDgnTextStyleApplyable");

    c1.def("HasTextStyle", &IDgnTextStyleApplyable::HasTextStyle, DOC(Bentley, DgnPlatform, IDgnTextStyleApplyable, HasTextStyle));
    c1.def_property_readonly("TextStyleId", &IDgnTextStyleApplyable::GetTextStyleId);
    c1.def("GetTextStyleId", &IDgnTextStyleApplyable::GetTextStyleId, DOC(Bentley, DgnPlatform, IDgnTextStyleApplyable, GetTextStyleId));
    c1.def("ApplyTextStyle", &IDgnTextStyleApplyable::ApplyTextStyle, "textStyle"_a, "annotationScale"_a, "respectOverrides"_a, DOC(Bentley, DgnPlatform, IDgnTextStyleApplyable, ApplyTextStyle));
    c1.def("RemoveTextStyle", &IDgnTextStyleApplyable::RemoveTextStyle, DOC(Bentley, DgnPlatform, IDgnTextStyleApplyable, RemoveTextStyle));
    }