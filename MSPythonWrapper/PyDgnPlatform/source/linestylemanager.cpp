/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnPlatform\source\linestylemanager.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <DgnPlatform/LineStyleManager.h>



static const char * __doc_Bentley_DgnPlatform_LineStyleManager_Reinitialize =R"doc(Reinitializes the line style maps. The steps to reinitializing are:
 Close all resource files that are associated with the existing
system map.  Free the system map and design file maps. 
Initialize the system map, calling _GetLocalLineStylePaths to get a
new list of search patterns used to find the RSC files. <p>The design
file maps are loaded as needed.

:returns:
    BSISUCCESS if successul, or BSIERROR otherwise. It fails if the
    LineStyleManager was not previously initialized, or if there are
    any LsResourceFileMap maps open.)doc";

static const char * __doc_Bentley_DgnPlatform_LineStyleManager_GetNumberFromName =R"doc(Gets the number corresponding to the line style name. The case must be
correct for the search to succeed. This searches the design file's
LsMap to find an entry with the specified name and returns the number
that that maps to the name. This returns the appropriate strings for
the standard line codes and for the special numbers listed in
LsKnownStyleNumber.

:param name:
    The name to use as the search key.

:param dgnFile:
    The DgnFile of interest.

:param createIDIfNecessary:
    Add an entry to the file LsDgnFileMap if it is not already there.

:returns:
    style number if found, otherwise STYLE_Invalid.)doc";

static const char * __doc_Bentley_DgnPlatform_LineStyleManager_GetStringFromNumber =R"doc(Gets a name corresponding to the style number. This method will return
printable strings for line codes, ByLevel, and ByCell.

:param styleNumber:
    A style number for one of the special styles.

:param dgnFile:
    The DgnFile of interest.

:returns:
    The name of the style corresponding to the number. If the style
    number corresponds to an entry in the design file's LsMap then
    this returns the name as stored in the map. If the style number is
    one of the standard lines codes (in the range STYLE_MinLineCode
    through STYLE_MaxLineCode), this returns the string generated from
    the number. If style number is STYLE_ByLevel, STYLE_ByCell, or,
    STYLE_Invalid this returns the name of the value. For example, if
    style number is STYLE_ByLevel this returns " STYLE_ByLevel ". The
    string is not localized -- it is the same for any locale.
    Otherwise, this returns a zero-length string.)doc";

static const char * __doc_Bentley_DgnPlatform_LineStyleManager_GetNameFromNumber =R"doc(Gets a name corresponding to the style number. It will return an empty
string if the line style number is a line code (0-7) or ByLevel or
ByCell. If you want strings for those, use GetStringFromNumber().

:param styleNumber:
    A style number for a style known to the design file.

:param dgnFile:
    The DgnFile of interest.

:returns:
    The name of the style corresponding to the number. If the style
    number corresponds to an entry in the design file's LsMap then
    this returns the name as stored in the map. Otherwise, this
    returns a zero-length string.)doc";

static const char * __doc_Bentley_DgnPlatform_LineStyleManager_GetSystemLineStyleMap =R"doc(Get the LsSystemMap.

:returns:
    a reference to the LsSystemMap for the session.)doc";

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_LineStyleManager(py::module_& m)
    {
    //===================================================================================
    // struct LineStyleManager
    py::class_< LineStyleManager, DgnHost::IHostObject> c1(m, "LineStyleManager");
    c1.def_static("GetDgnFile", &LineStyleManager::GetDgnFileP, "modelRef"_a, py::return_value_policy::reference_internal);
    c1.def_static("GetLineStyleMap", py::overload_cast<DgnFileP>(&LineStyleManager::GetLineStyleMapP), "dgnFile"_a, py::return_value_policy::reference);
    c1.def_static("GetLineStyleMap", py::overload_cast<DgnModelRefP>(&LineStyleManager::GetLineStyleMapP), "modelRef"_a, py::return_value_policy::reference);

    c1.def_static("GetSystemLineStyleMap", &LineStyleManager::GetSystemLineStyleMap, py::return_value_policy::reference, DOC(Bentley, DgnPlatform, LineStyleManager, GetSystemLineStyleMap));
    c1.def_static("GetNameFromNumber", &LineStyleManager::GetNameFromNumber, "styleNumber"_a, "dgnFile"_a, DOC(Bentley, DgnPlatform, LineStyleManager, GetNameFromNumber));
    c1.def_static("GetStringFromNumber", &LineStyleManager::GetStringFromNumber, "styleNumber"_a, "dgnFile"_a, DOC(Bentley, DgnPlatform, LineStyleManager, GetStringFromNumber));
    c1.def_static("GetNumberFromName", py::overload_cast<WCharCP, DgnFileR, bool>(&LineStyleManager::GetNumberFromName), "name"_a, "dgnFile"_a, "createIDIfNecessary"_a = false, DOC(Bentley, DgnPlatform, LineStyleManager, GetNumberFromName));
    c1.def_static("GetNumberFromName", py::overload_cast<WCharCP, DgnFileR, bool, bool>(&LineStyleManager::GetNumberFromName), "name"_a, "dgnFile"_a, "createIDIfNecessary"_a, "forceCopyIntoCurrentFile"_a, DOC(Bentley, DgnPlatform, LineStyleManager, GetNumberFromName));
    c1.def_static("Reinitialize", &LineStyleManager::Reinitialize, DOC(Bentley, DgnPlatform, LineStyleManager, Reinitialize));
    }