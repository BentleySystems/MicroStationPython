/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnPlatform\source\linestyle.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <DgnPlatform/LineStyle.h>



static const char * __doc_Bentley_DgnPlatform_LsDgnFileMap_GetDgnFile =R"doc(Gets a pointer to the associated DgnFile.

Remark:
    Use LineStyleManager::GetLineStyleMapP to get a pointer to a
    DgnFile's LsDgnFileMap.)doc";

static const char * __doc_Bentley_DgnPlatform_LsSystemMap_GetSystemMap =R"doc(Gets a reference to the system LsMap.)doc";

static const char * __doc_Bentley_DgnPlatform_LsResourceFileMap_GetRscHandle =R"doc(Returns the Resource File Handle associated with this map. Be careful
not to close it.

Returns:
    The resource File Handle or 0 if no file is open.

See also:
    OpenFile)doc";

static const char * __doc_Bentley_DgnPlatform_LsResourceFileMap_CreateNewFile =R"doc(Creates a new line style resource file.

Parameter ``fileName``:
    Name of the file.

Returns:
    LINESTYLE_STATUS_Success if it creates the file; an error
    indicator otherwise

Remark:
    This does not open the file; it merely creates it.

See also:
    OpenFile)doc";

static const char * __doc_Bentley_DgnPlatform_LsResourceFileMap_OpenFile =R"doc(Opens a new resource file and creates an LsResourceFileMap object to
be used to access the line styles and components that file
contains.<p>

Parameter ``status``:
    Set to LINESTYLE_STATUS_Success if able to open the file;
    otherwise set to an appropriate LineStyleStatus error status.

Parameter ``fileName``:
    Name of the file to open.

Parameter ``readonly``:
    Pass true to open the file readonly.

Returns:
    A LsResourceFileMapPtr. If unable to open the file,
    LsResourceFileMapPtr.get() returns NULL and the status parameter
    is set to an appropriate LineStyleStatus error status.

See also:
    OpenFile)doc";

static const char * __doc_Bentley_DgnPlatform_LsMap_GetLineStyleEntry =R"doc(Searches the set of names associated with the LsMap.

Parameter ``lsName``:
    The name of the line style.

Returns:
    The associated LsDefinition object if found. Otherwise, it returns
    NULL; @note If the line style map is a LsDgnFileMap then the
    LsDefinitionP that is returned may point to a line style defined
    in a DGN file or a line style defined in a resource file.)doc";

static const char * __doc_Bentley_DgnPlatform_LsMap_GetFileName =R"doc(Name of file used to load the map.)doc";

static const char * __doc_Bentley_DgnPlatform_LsMap_GetType =R"doc(Type of file used to load the map.)doc";

static const char * __doc_Bentley_DgnPlatform_LsMapEntry_GetStyleNumber =R"doc(Get the line style number. For an LsMapEntry from an LsDgnFileMap this
is the number that is used to translate from the number in an
element's symbology to a line style name. For an LsMapEntry from a
system map, the style number normally is meaningless.)doc";

static const char * __doc_Bentley_DgnPlatform_LsMapEntry_GetStyleName =R"doc(Gets the name of the line style)doc";

static const char * __doc_Bentley_DgnPlatform_LsEntry_GetId =R"doc(Gets the component's resource ID if the definition comes from a
resource file, or element ID if the definition comes from a DgnFile.
INVALID_ELEMENTID if the definition cant be found)doc";

static const char * __doc_Bentley_DgnPlatform_LsEntry_GetSourceFileName =R"doc(Get the source filename for the components associated with this entry,
or an Invalid WString if unknown.)doc";

static const char * __doc_Bentley_DgnPlatform_LsEntry_GetDefinitionLocation =R"doc(When looking at a resource name map this will always return Resource.
From a Dgn name map this may be Resource or DgnFile, depending on
where it is using the line style from.)doc";

static const char * __doc_Bentley_DgnPlatform_LsEntry_GetStyleNumber =R"doc(Get the line style number. For an LsMapEntry from an LsDgnFileMap this
is the number that is used to translate from the number in an
element's symbology to a line style name. For an LsMapEntry from a
system map, the style number normally is meaningless.)doc";

static const char * __doc_Bentley_DgnPlatform_LsEntry_GetStyleName =R"doc(Gets the name of the line style)doc";

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_LineStyle(py::module_& m)
    {
    //===================================================================================
    // struct LineStyleNameInfo
    py::class_< LineStyleNameInfo> c1(m, "LineStyleNameInfo");

    c1.def_readwrite("rscFile", &LineStyleNameInfo::rscFile);
    c1.def_readwrite("rscType", &LineStyleNameInfo::rscType);
    c1.def_readwrite("rscId", &LineStyleNameInfo::rscID);
    c1.def_readwrite("attributes", &LineStyleNameInfo::attributes);
    c1.def_readwrite("styleId", &LineStyleNameInfo::styleID);

    //===================================================================================
    // enum LsKnownStyleNumber
    py::enum_< DgnPlatform::LsKnownStyleNumber>(m, "LsKnownStyleNumber", py::arithmetic())
        .value("eSTYLE_MinLineCode", DgnPlatform::STYLE_MinLineCode)
        .value("eSTYLE_MaxLineCode", DgnPlatform::STYLE_MaxLineCode)
        .value("eSTYLE_ByLevel", DgnPlatform::STYLE_ByLevel)
        .value("eSTYLE_ByCell", DgnPlatform::STYLE_ByCell)
        .value("eSTYLE_Invalid", DgnPlatform::STYLE_Invalid)
        .export_values();

    //===================================================================================
    // enum class LsElementType
    py::enum_< DgnPlatform::LsElementType>(m, "LsElementType")
        .value("eUnknown", DgnPlatform::LsElementType::Unknown)
        .value("ePointSymbol", DgnPlatform::LsElementType::PointSymbol)
        .value("eCompound", DgnPlatform::LsElementType::Compound)
        .value("eLineCode", DgnPlatform::LsElementType::LineCode)
        .value("eLinePoint", DgnPlatform::LsElementType::LinePoint)
        .value("eInternal", DgnPlatform::LsElementType::Internal)
        .value("eRasterImage", DgnPlatform::LsElementType::RasterImage)
        .export_values();

    //===================================================================================
     // enum class LsLocationType
    py::enum_< DgnPlatform::LsLocationType>(m, "LsLocationType")
        .value("eUnknown", DgnPlatform::LsLocationType::Unknown)
        .value("eResourceFile", DgnPlatform::LsLocationType::ResourceFile)
        .value("eDgnFile_", DgnPlatform::LsLocationType::DgnFile)
        .value("eSystem", DgnPlatform::LsLocationType::System)
        .value("eLinFile", DgnPlatform::LsLocationType::LinFile)
        .value("eImporter", DgnPlatform::LsLocationType::Importer)
        .export_values();

    //===================================================================================
    // enum class LsResourceType
    py::enum_< DgnPlatform::LsResourceType>(m, "LsResourceType")
        .value("eUnknown", DgnPlatform::LsResourceType::Unknown)
        .value("eInternal", DgnPlatform::LsResourceType::Internal)
        .value("eCompound", DgnPlatform::LsResourceType::Compound)
        .value("eLineCode", DgnPlatform::LsResourceType::LineCode)
        .value("eLinePoint", DgnPlatform::LsResourceType::LinePoint)
        .value("ePointSymbol", DgnPlatform::LsResourceType::PointSymbol)
        .value("ePointSymbolV7", DgnPlatform::LsResourceType::PointSymbolV7)
        .value("eRasterImage", DgnPlatform::LsResourceType::RasterImage)
        .value("eNameEntry", DgnPlatform::LsResourceType::NameEntry)
        .export_values();

    //===================================================================================
    // enum class LsCapMode
    py::enum_< DgnPlatform::LsCapMode>(m, "LsCapMode")
        .value("eLCCAP_Closed", DgnPlatform::LsCapMode::LCCAP_Closed)
        .value("eLCCAP_Open", DgnPlatform::LsCapMode::LCCAP_Open)
        .value("eLCCAP_Extended", DgnPlatform::LsCapMode::LCCAP_Extended)
        .value("eLCCAP_Hexagon", DgnPlatform::LsCapMode::LCCAP_Hexagon)
        .value("eLCCAP_Octagon", DgnPlatform::LsCapMode::LCCAP_Octagon)
        .value("eLCCAP_Decagon", DgnPlatform::LsCapMode::LCCAP_Decagon)
        .value("eLCCAP_Arc", DgnPlatform::LsCapMode::LCCAP_Arc)
        .export_values();


    //=======================================================================================
    // enum class LsUnit
    py::enum_< LsUnit>(m, "LsUnit")
        .value("eMaster", LsUnit::Master)
        .value("eUor", LsUnit::Uor)
        .value("eDevice", LsUnit::Device)
        .export_values();


    //=======================================================================================
    // struct LsEntry
    py::class_< LsEntry
        , std::unique_ptr<LsEntry, py::nodelete>
    > c20(m, "LsEntry");

    c20.def_property_readonly("StyleName", &LsEntry::GetStyleName);
    c20.def("GetStyleName", &LsEntry::GetStyleName, DOC(Bentley, DgnPlatform, LsEntry, GetStyleName));
    
    c20.def_property_readonly("StyleNumber", &LsEntry::GetStyleNumber);
    c20.def("GetStyleNumber", &LsEntry::GetStyleNumber, DOC(Bentley, DgnPlatform, LsEntry, GetStyleNumber));
    
    c20.def_property_readonly("DefinitionLocation", &LsEntry::GetDefinitionLocation);
    c20.def("GetDefinitionLocation", &LsEntry::GetDefinitionLocation, DOC(Bentley, DgnPlatform, LsEntry, GetDefinitionLocation));
    
    c20.def_property_readonly("SourceFileName", &LsEntry::GetSourceFileName);
    c20.def("GetSourceFileName", &LsEntry::GetSourceFileName, DOC(Bentley, DgnPlatform, LsEntry, GetSourceFileName));
    
    c20.def("GetId", &LsEntry::GetId, "modelRef"_a, DOC(Bentley, DgnPlatform, LsEntry, GetId));

    //=======================================================================================
    // struct LsMapEntry
    py::class_< LsMapEntry> c21(m, "LsMapEntry");

    c21.def_property_readonly("StyleName", &LsMapEntry::GetStyleName);
    c21.def("GetStyleName", &LsMapEntry::GetStyleName, DOC(Bentley, DgnPlatform, LsMapEntry, GetStyleName));
    
    c21.def_property_readonly("StyleNumber", &LsMapEntry::GetStyleNumber);    
    c21.def("GetStyleNumber", &LsMapEntry::GetStyleNumber, DOC(Bentley, DgnPlatform, LsMapEntry, GetStyleNumber));    
    
    c21.def_property_readonly("LineStyleEntry", [] (LsMapEntry& self) { return std::unique_ptr<LsEntry, py::nodelete>(const_cast<LsEntryP>(self.GetLineStyleEntry())); });
    c21.def("GetLineStyleEntry", [] (LsMapEntry& self) { return std::unique_ptr<LsEntry, py::nodelete>(const_cast<LsEntryP>(self.GetLineStyleEntry())); });

    //=======================================================================================
    // struct LsMap
    py::class_<LsMap, LsMapPtr> c22(m, "LsMap");

    c22.def_property_readonly("Type", &LsMap::GetType);
    c22.def("GetType", &LsMap::GetType, DOC(Bentley, DgnPlatform, LsMap, GetType));

    c22.def_property_readonly("FileName", &LsMap::GetFileName);
    c22.def("GetFileName", &LsMap::GetFileName, DOC(Bentley, DgnPlatform, LsMap, GetFileName));

    c22.def("GetLineStyleEntry", [] (LsMap const& self, WCharCP lsName)
            {
            return std::unique_ptr<LsEntry, py::nodelete>(const_cast<LsEntryP>(self.GetLineStyleEntry(lsName)));
            }, "lsName"_a, DOC(Bentley, DgnPlatform, LsMap, GetLineStyleEntry));

    c22.def("GetLineStyleEntry", [] (LsMap const& self, Int32 styleId)
            {
            return std::unique_ptr<LsEntry, py::nodelete>(const_cast<LsEntryP>(self.GetLineStyleEntry(styleId)));
            }, "styleId"_a, DOC(Bentley, DgnPlatform, LsMap, GetLineStyleEntry));
    
    c22.def("__iter__", [] (LsMap& self) { return py::make_iterator(self.begin(), self.end()); }, py::keep_alive<0, 1>());

    //=======================================================================================
    // struct LsResourceFileMap
    py::class_< LsResourceFileMap, LsResourceFileMapPtr, LsMap> c23(m, "LsResourceFileMap");

    c23.def_static("OpenFile", [] (WCharCP fileName, bool readonly)
                   {
                   LineStyleStatus status;
                   auto retVal = LsResourceFileMap::OpenFile(status, fileName, readonly);
                   return py::make_tuple(retVal, status);
                   }, "fileName"_a, "readonly"_a, DOC(Bentley, DgnPlatform, LsResourceFileMap, OpenFile));

    c23.def_static("CreateNewFile", &LsResourceFileMap::CreateNewFile, "fileName"_a, DOC(Bentley, DgnPlatform, LsResourceFileMap, CreateNewFile));
    c23.def_property_readonly("RscHandle", &LsResourceFileMap::GetRscHandle);
    c23.def("GetRscHandle", &LsResourceFileMap::GetRscHandle, DOC(Bentley, DgnPlatform, LsResourceFileMap, GetRscHandle));

    //=======================================================================================
    // struct LsSystemMap
    py::class_< LsSystemMap, LsSystemMapPtr, LsMap/*, DgnHost::HostObjectBase*/> c24(m, "LsSystemMap", py::multiple_inheritance());

//    c24.def_property_readonly_static("SystemMap", [] (py::object const&) { return LsSystemMapPtr(const_cast<LsSystemMapP>(&LsSystemMap::GetSystemMap())); });
    c24.def_static("GetSystemMap", [] () { return LsSystemMapPtr(const_cast<LsSystemMapP>(&LsSystemMap::GetSystemMap())); }, DOC(Bentley, DgnPlatform, LsSystemMap, GetSystemMap));

    //=======================================================================================
    // struct LsDgnFileMap
    py::class_< LsDgnFileMap, LsDgnFileMapPtr, LsMap> c25(m, "LsDgnFileMap");

    c25.def_property_readonly("DgnFile", &LsDgnFileMap::GetDgnFile);
    c25.def("GetDgnFile", &LsDgnFileMap::GetDgnFile, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, LsDgnFileMap, GetDgnFile));
    }