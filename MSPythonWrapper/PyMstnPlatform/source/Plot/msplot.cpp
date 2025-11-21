/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyMstnPlatform\source\Plot\msplot.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <OpqueTypes_MstnPlatform.h>


static const char* __doc_mdlPlot_getDefaultPltcfg = R"doc(Returns the name of the default printer driver configuration file. The
print dialog user preferences are used in conjunction with
configuration variables to determine the default file.

Parameter ``pltcfgFspec``:
    Default printer driver configuration file.

Returns:
    True if success.)doc";

static const char* __doc_mdlPlot_getDefaultSysPltcfg = R"doc(Returns the name of the default system printer driver configuration
file. The print dialog user preferences are used in conjunction with
configuration variables to determine the default file.

Parameter ``pltcfgFspec``:
    Default system printer driver configuration file.

Returns:
    True if success.)doc";

static const char* __doc_mdlPlot_getDefaultPdfPltcfg = R"doc(Returns the name of the default PDF printer driver configuration file.
The print dialog user preferences are used in conjunction with
configuration variables to determine the default file.

Parameter ``pltcfgFspec``:
    Default PDF printer driver configuration file.

Returns:
    True if success.)doc";

static const char* __doc_mdlPlot_getPaperSizeListFromPrinter = R"doc(Returns a list of paper sizes defined for the specified printer.

Parameter ``paperSizeList``:
    Paper size list.

Parameter ``printerName``:
    Either a .pltcfg file name or a Windows printer name.

Parameter ``orientation``:
    Desired orientation for paper sizes.

Parameter ``units``:
    Desired paper size units.

Returns:
    SUCCESS or ERROR)doc";

static const char* __doc_mdlPlot_getPrintStyleNames = R"doc(Returns a list of print style names available in the current session.

Parameter ``printStyleNames``:
    List of print style names.

Parameter ``fromActiveDgnFile``:
    True to include print styles from the active DGN.

Parameter ``fromDgnLibraries``:
    True to include print styles from dgnlibs.)doc";

static const char* __doc_mdlPlot_getPrintDialogDescHandle = R"doc(Gets the IPrintDescription handle used by the plotdlg application (if
it is loaded). If plotdlg is not loaded, the returned handle is NULL.

Remark:
    s Callers MUST NOT destroy this handle nor modify its contents.
    Use 'print' keyins to change the active Print dialog state.)doc";

static const char* __doc_mdlPlot_getErrno = R"doc(Gets the current global plot error number.)doc";
static const char* __doc_mdlPlot_setErrno = R"doc(Sets the current global plot error number.

Parameter ``value``:
    New error code.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_PlotPropValue_ToString =R"doc(Converts the property value to a string.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_PlotPropValue_IsValid =R"doc(True if the property value is defined.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_PlotPropValue_GetString =R"doc(Gets the property value as a string.

Remark:
    s Returns NULL if property value undefined or is not a string
    type.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_PlotPropValue_GetDouble =R"doc(Gets the property value as a floating-point number.

Remark:
    s Returns zero if property value undefined or is not a floating-
    point type.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_PlotPropValue_GetBool =R"doc(Gets the property value as an boolean.

Remark:
    s Returns false if property value undefined or is not an integer
    type.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_PlotPropValue_GetInt =R"doc(Gets the property value as an integer.

Remark:
    s Returns zero if property value undefined or is not an integer
    type.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_PlotPropValue_Assign =R"doc(Assigns an integer value.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_PlotPropValue_swap = R"doc(Swaps two PlotPropValue instances.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_PlotPropValue_GetType =R"doc(Gets the property value type.)doc";


static const char* __doc_Bentley_MstnPlatform_Print_PlotFileSpec_PlotFileSpec_0 = R"doc(Default constructor.)doc";

static const char* __doc_Bentley_MstnPlatform_Print_PlotFileSpec_PlotFileSpec_1 = R"doc(Constructs a PlotFileSpec from a universal file specification.)doc";

static const char* __doc_Bentley_MstnPlatform_Print_PlotFileSpec_PlotFileSpec_2 = R"doc(Constructs a PlotFileSpec from a universal file specification, while
also optionally setting the host file specification to the same value.)doc";

static const char* __doc_Bentley_MstnPlatform_Print_PlotFileSpec_PlotFileSpec_3 = R"doc(Constructs a PlotFileSpec from a universal file specification.)doc";

static const char* __doc_Bentley_MstnPlatform_Print_PlotFileSpec_PlotFileSpec_4 = R"doc(Constructs a PlotFileSpec from a universal file specification, while
also optionally setting the host file specification to the same value.)doc";

static const char* __doc_Bentley_MstnPlatform_Print_PlotFileSpec_PlotFileSpec_5 = R"doc(Constructs a PlotFileSpec from a DgnDocument.

Remark:
    s The FileSpec instance will take ownership of a copy of the input
    DgnDocument. )doc";

static const char* __doc_Bentley_MstnPlatform_Print_PlotFileSpec_PlotFileSpec_6 = R"doc(Constructs a PlotFileSpec from a DgnDocument.

Remark:
    s The FileSpec instance will take ownership of a copy of the input
    DgnDocument. )doc";

static const char* __doc_Bentley_MstnPlatform_Print_PlotFileSpec_PlotFileSpec_7 = R"doc(Copy constructor.)doc";


static const char * __doc_Bentley_MstnPlatform_Print_PlotFileSpec_Equals =R"doc(Tests two PlotFileSpec instances for equality.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_PlotFileSpec_swap = R"doc(Swaps two PlotFileSpec instances.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_PlotFileSpec_RemoveEmbeddedSuffix =R"doc(Removes any embedded suffix from the given path.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_PlotFileSpec_GetEmbeddedSuffix =R"doc(Returns any embedded suffix from the given path.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_PlotFileSpec_ContainsEmbeddedSuffix =R"doc(True if the given path contains an embedded file specification.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_PlotFileSpec_Clear =R"doc(Clears Ufs, Hfs, moniker, and handle.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_PlotFileSpec_ClearHandle =R"doc(Clears the document or folder handle, if defined.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_PlotFileSpec_UpdateFromHandle =R"doc(Updates the FolderSpec from its contained handle, if defined.

Remark:
    s Potentially changes the ufs, hfs, and moniker. )doc";

static const char * __doc_Bentley_MstnPlatform_Print_PlotFileSpec_ToString =R"doc(Gets the display full name, including embedded suffix.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_PlotFileSpec_GetFileName =R"doc(Gets the file name and extension of the Hfs if defined, otherwise that
of the Ufs. Optionally appends the embedded suffix if defined.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_PlotFileSpec_GetDisplayFullName =R"doc(Gets the Ufs if DMS managed, otherwise GetHfsOrUfs
(includeEmbeddedSuffix). Optionally appends the embedded suffix if
defined.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_PlotFileSpec_DisplayFullName =R"doc(Gets the Ufs if DMS managed, otherwise HfsOrUfs(). Does not include
embedded suffix in HFS, if defined.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_PlotFileSpec_IsDms =R"doc(True if this file is DMS managed.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_PlotFileSpec_IsHandleDefined =R"doc(True if DgnDocument or DgnFolder is defined.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_PlotFileSpec_IsEmbeddedSuffixDefined =R"doc(True if the embedded suffix is defined.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_PlotFileSpec_IsMonikerDefined =R"doc(True if the externalized moniker string is defined.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_PlotFileSpec_IsHfsDefined =R"doc(True if the host file specification is defined.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_PlotFileSpec_IsEmpty =R"doc(True if the universal file specification is not defined.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_PlotFileSpec_IsValid =R"doc(True if the universal file specification is defined.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_PlotFileSpec_SetFolder =R"doc(Set the DgnFolder for this folder specification. Adds reference to
folder.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_PlotFileSpec_Folder =R"doc(DgnFolder pointer. May be undefined.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_PlotFileSpec_SetDocument =R"doc(Set the DgnDocument for this file specification. Adds reference to
document.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_PlotFileSpec_Document =R"doc(DgnDocument pointer. May be undefined.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_PlotFileSpec_SetIsNew =R"doc(Sets flag indicating if this specification represents a file or folder
being created. DgnDocument.OnNewFileCreated must be called to finish
creation of files marked as new.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_PlotFileSpec_IsNew =R"doc(Gets flag indicating if this specification represents a file or folder
being created. DgnDocument.OnNewFileCreated must be called to finish
creation of files marked as new.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_PlotFileSpec_SetIsReadOnly =R"doc(Sets flag indicating if this specification represents a read-only file
or folder.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_PlotFileSpec_IsReadOnly =R"doc(Gets flag indicating if this specification represents a read-only file
or folder.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_PlotFileSpec_SetIsFolder =R"doc(Sets flag indicating if this specification is for a folder.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_PlotFileSpec_IsFolder =R"doc(Gets flag indicating if this specification is for a folder.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_PlotFileSpec_ClearEmbeddedSuffix =R"doc(Clears the embedded suffix string.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_PlotFileSpec_SetEmbeddedSuffix =R"doc(Sets the embedded suffix string.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_PlotFileSpec_EmbeddedSuffix =R"doc(Gets the embedded suffix string.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_PlotFileSpec_ClearMoniker =R"doc(Clears the externalized DMS moniker string.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_PlotFileSpec_SetMoniker =R"doc(Sets the externalized DMS moniker string.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_PlotFileSpec_Moniker =R"doc(Gets the externalized DMS moniker string.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_PlotFileSpec_GetHfsOrUfs =R"doc(Gets the host file specification if defined, otherwise the universal
file specification. Optionally includes the embedded suffix in the
HFS, if defined.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_PlotFileSpec_HfsOrUfs =R"doc(Gets the host file specification if defined, otherwise the universal
file specification. Does not include the embedded suffix in the HFS.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_PlotFileSpec_ClearHfs =R"doc(Clears the host file specification.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_PlotFileSpec_SetHfs =R"doc(Sets the host file specification. May also set the universal file
specification and embedded suffix.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_PlotFileSpec_GetHfs =R"doc(Gets the host file specification. Optionally includes the embedded
suffix, if defined.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_PlotFileSpec_Hfs =R"doc(Gets the host file specification, without any embedded suffix.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_PlotFileSpec_SetUfsAndHfs =R"doc(Sets both the universal and host file specifications. Clears the
moniker. Sets of clears the embedded suffix.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_PlotFileSpec_SetUfsOnly =R"doc(Sets the universal file specification without clearing anything.
Intended only for low-level code that manually populates all file
specification fields.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_PlotFileSpec_SetUfs =R"doc(Sets the universal file specification. Clears host file specification
and moniker. May set or clear the embedded suffix.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_PlotFileSpec_GetUfs =R"doc(Gets the universal file specification. Optionally includes the
embedded suffix, if defined.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_PlotFileSpec_Ufs =R"doc(Gets the universal file specification, without any embedded suffix.)doc";





static const char* __doc_Bentley_MstnPlatform_Print_PlotFileSpec_SetFromDgnFolder = R"doc(Populates FileSpec from a DgnFolder.

Remark:
    s The FileSpec instance will take ownership of a copy of the input
    DgnFolder. )doc";

static const char* __doc_Bentley_MstnPlatform_Print_PlotFileSpec_SetFromDgnDocument = R"doc(Populates FileSpec from a DgnDocument.

Remark:
    s The FileSpec instance will take ownership of a copy of the input
    DgnDocument. )doc";

BEGIN_BENTLEY_MSTNPLATFORM_MSPYTHON_NAMESPACE
struct MstnPlot {};
END_BENTLEY_MSTNPLATFORM_MSPYTHON_NAMESPACE

void def_IPrintDescription(py::module_&);
void def_IPlotter(py::module_&);
void def_IPrintEngine(py::module_&);
void def_IPlotHook(py::module_&);
void def_IPrinterDriver(py::module_&);
void def_IPlotElemDisplayParams(py::module_&);

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       6/2024
+---------------+---------------+---------------+---------------+---------------+------*/
void def_msplot(py::module_& m)
{
    def_IPrintDescription(m);
    def_IPlotter(m);
    def_IPrintEngine(m);
    def_IPlotHook(m);

    def_IPrinterDriver(m);
    def_IPlotElemDisplayParams(m);

    //===================================================================================
    // enum class PlotUnits
    py::enum_< PlotUnits>(m, "PlotUnits")
        .value("eUndefined", PlotUnits::Undefined)
        .value("eDefault", PlotUnits::Default)
        .value("em", PlotUnits::m)
        .value("edm", PlotUnits::dm)
        .value("ecm", PlotUnits::cm)
        .value("emm", PlotUnits::mm)
        .value("eft", PlotUnits::ft)
        .value("ein", PlotUnits::in)
        .value("edots", PlotUnits::dots)
        .value("etenthsmm", PlotUnits::tenthsmm)
        .export_values();

    //===================================================================================
    // enum class PlotAreaMode
    py::enum_< PlotAreaMode>(m, "PlotAreaMode")
        .value("eView", PlotAreaMode::View)
        .value("eFence", PlotAreaMode::Fence)
        .value("eSheet", PlotAreaMode::Sheet)
        .export_values();


    //===================================================================================
    // enum class PlotDestination
    py::enum_< PlotDestination>(m, "PlotDestination")
        .value("eUndefined", PlotDestination::Undefined)
        .value("eToDevice", PlotDestination::ToDevice)
        .value("eToPlotFile", PlotDestination::ToPlotFile)
        .value("eToMetaFile", PlotDestination::ToMetaFile)
        .export_values();

    //===================================================================================
    // enum class PlotOrientation
    py::enum_< PlotOrientation>(m, "PlotOrientation")
        .value("eUndefined", PlotOrientation::Undefined)
        .value("ePortrait", PlotOrientation::Portrait)
        .value("eLandscape", PlotOrientation::Landscape)
        .export_values();

    //===================================================================================
    // enum class PlotPropValueType
    py::enum_< PlotPropValueType>(m, "PlotPropValueType")
        .value("eUndefined", PlotPropValueType::Undefined)
        .value("eInteger", PlotPropValueType::Integer)
        .value("eDouble", PlotPropValueType::Double)
        .value("eString", PlotPropValueType::String)
        .export_values();

    //===================================================================================
    // enum class PlotError
    py::enum_< PlotError>(m, "PlotError")
        .value("eNoError", PlotError::NoError)
        .value("eInternal", PlotError::Internal)
        .value("eDiskFull", PlotError::DiskFull)
        .value("eUserAbort", PlotError::UserAbort)
        .value("eMalloc", PlotError::Malloc)
        .value("eOpenFile", PlotError::OpenFile)
        .value("eWriteFile", PlotError::WriteFile)
        .value("eCreateFile", PlotError::CreateFile)
        .value("ePermissionDenied", PlotError::PermissionDenied)
        .value("eInvalidScale", PlotError::InvalidScale)
        .value("eIllegalWrite", PlotError::IllegalWrite)
        .value("eTimeout", PlotError::Timeout)
        .export_values();

    //===================================================================================
    //class PrintStyleName
    py::class_<PrintStyleName> c0(m, "PrintStyleName");
    py::bind_vector<PrintStyleNameArray>(m, "PrintStyleNameArray", py::module_local(false));

    c0.def_readwrite("name", &PrintStyleName::name);
    c0.def_readwrite("sourceFileName", &PrintStyleName::sourceFileName);

    //===================================================================================
    //class PlotPaperSizeInfo
    py::class_<PlotPaperSizeInfo> c1(m, "PlotPaperSizeInfo");
    py::bind_vector<PlotPaperSizeInfoArray>(m, "PlotPaperSizeInfoArray", py::module_local(false));

    c1.def_readwrite("name", &PlotPaperSizeInfo::name);
    c1.def_readwrite("units", &PlotPaperSizeInfo::units);

    c1.def_readwrite("totalSize", &PlotPaperSizeInfo::totalSize);
    c1.def_readwrite("printableSize", &PlotPaperSizeInfo::printableSize);
    c1.def_readwrite("printableOffset", &PlotPaperSizeInfo::printableOffset);

    //===================================================================================
    //class PlotFileSpec
    py::class_<PlotFileSpec> c2(m, "PlotFileSpec");

    c2.def(py::init<>(), __doc_Bentley_MstnPlatform_Print_PlotFileSpec_PlotFileSpec_0);
    c2.def(py::init<WStringCR>(), "ufs"_a, __doc_Bentley_MstnPlatform_Print_PlotFileSpec_PlotFileSpec_1);
    c2.def(py::init<WStringCR, bool>(), "ufs"_a, "isHfs"_a, __doc_Bentley_MstnPlatform_Print_PlotFileSpec_PlotFileSpec_2);
    c2.def(py::init<WCharCP>(), "ufs"_a, __doc_Bentley_MstnPlatform_Print_PlotFileSpec_PlotFileSpec_3);
    c2.def(py::init<WCharCP, bool>(), "ufs"_a, "isHfs"_a, __doc_Bentley_MstnPlatform_Print_PlotFileSpec_PlotFileSpec_4);
    c2.def(py::init<DgnDocumentCP>(), "document"_a, __doc_Bentley_MstnPlatform_Print_PlotFileSpec_PlotFileSpec_5);
    c2.def(py::init<DgnFolderCP>(), "folder"_a, __doc_Bentley_MstnPlatform_Print_PlotFileSpec_PlotFileSpec_6);

    c2.def("__copy__", [](PlotFileSpecCR self) { return PlotFileSpec(self); }, __doc_Bentley_MstnPlatform_Print_PlotFileSpec_PlotFileSpec_7);

    c2.def("Ufs", &PlotFileSpec::Ufs, DOC(Bentley, MstnPlatform, Print, PlotFileSpec, Ufs));
    c2.def("GetUfs", &PlotFileSpec::GetUfs, "includeEmbeddedSuffix"_a = false, DOC(Bentley, MstnPlatform, Print, PlotFileSpec, GetUfs));
    c2.def("SetUfs", &PlotFileSpec::SetUfs, "value"_a, DOC(Bentley, MstnPlatform, Print, PlotFileSpec, SetUfs));
    c2.def("SetUfsOnly", &PlotFileSpec::SetUfsOnly, "value"_a, DOC(Bentley, MstnPlatform, Print, PlotFileSpec, SetUfsOnly));
    c2.def("SetUfsAndHfs", &PlotFileSpec::SetUfsAndHfs, "value"_a, DOC(Bentley, MstnPlatform, Print, PlotFileSpec, SetUfsAndHfs));
    c2.def("Hfs", &PlotFileSpec::Hfs, DOC(Bentley, MstnPlatform, Print, PlotFileSpec, Hfs));
    c2.def("GetHfs", &PlotFileSpec::GetHfs, "includeEmbeddedSuffix"_a = false, DOC(Bentley, MstnPlatform, Print, PlotFileSpec, GetHfs));
    c2.def("SetHfs", &PlotFileSpec::SetHfs, "value"_a, DOC(Bentley, MstnPlatform, Print, PlotFileSpec, SetHfs));
    c2.def("ClearHfs", &PlotFileSpec::ClearHfs, DOC(Bentley, MstnPlatform, Print, PlotFileSpec, ClearHfs));
    c2.def("HfsOrUfs", &PlotFileSpec::HfsOrUfs, DOC(Bentley, MstnPlatform, Print, PlotFileSpec, HfsOrUfs));

    c2.def("GetHfsOrUfs", &PlotFileSpec::GetHfsOrUfs, "includeEmbeddedSuffix"_a = false, DOC(Bentley, MstnPlatform, Print, PlotFileSpec, GetHfsOrUfs));
    c2.def("Moniker", &PlotFileSpec::Moniker, DOC(Bentley, MstnPlatform, Print, PlotFileSpec, Moniker));
    c2.def("SetMoniker", py::overload_cast<WCharCP>(&PlotFileSpec::SetMoniker), "value"_a, DOC(Bentley, MstnPlatform, Print, PlotFileSpec, SetMoniker));
    c2.def("SetMoniker", py::overload_cast<WStringCR>(&PlotFileSpec::SetMoniker), "value"_a, DOC(Bentley, MstnPlatform, Print, PlotFileSpec, SetMoniker));

    c2.def("ClearMoniker", &PlotFileSpec::ClearMoniker, DOC(Bentley, MstnPlatform, Print, PlotFileSpec, ClearMoniker));
    c2.def("EmbeddedSuffix", &PlotFileSpec::EmbeddedSuffix, DOC(Bentley, MstnPlatform, Print, PlotFileSpec, EmbeddedSuffix));
    c2.def("SetEmbeddedSuffix", py::overload_cast<WCharCP>(&PlotFileSpec::SetEmbeddedSuffix), "value"_a, DOC(Bentley, MstnPlatform, Print, PlotFileSpec, SetEmbeddedSuffix));
    c2.def("SetEmbeddedSuffix", py::overload_cast<WStringCR>(&PlotFileSpec::SetEmbeddedSuffix), "value"_a, DOC(Bentley, MstnPlatform, Print, PlotFileSpec, SetEmbeddedSuffix));
    c2.def("ClearEmbeddedSuffix", &PlotFileSpec::ClearEmbeddedSuffix, DOC(Bentley, MstnPlatform, Print, PlotFileSpec, ClearEmbeddedSuffix));
    c2.def("IsFolder", &PlotFileSpec::IsFolder, DOC(Bentley, MstnPlatform, Print, PlotFileSpec, IsFolder));
    c2.def("SetIsFolder", &PlotFileSpec::SetIsFolder, "value"_a, DOC(Bentley, MstnPlatform, Print, PlotFileSpec, SetIsFolder));
    c2.def("IsReadOnly", &PlotFileSpec::IsReadOnly, DOC(Bentley, MstnPlatform, Print, PlotFileSpec, IsReadOnly));
    c2.def("SetIsReadOnly", &PlotFileSpec::SetIsReadOnly, "value"_a, DOC(Bentley, MstnPlatform, Print, PlotFileSpec, SetIsReadOnly));
    c2.def("IsNew", &PlotFileSpec::IsNew, DOC(Bentley, MstnPlatform, Print, PlotFileSpec, IsNew));
    c2.def("SetIsNew", &PlotFileSpec::SetIsNew, "value"_a, DOC(Bentley, MstnPlatform, Print, PlotFileSpec, SetIsNew));
    c2.def("Document", &PlotFileSpec::Document, DOC(Bentley, MstnPlatform, Print, PlotFileSpec, Document));
    c2.def("SetDocument", &PlotFileSpec::SetDocument, "value"_a, DOC(Bentley, MstnPlatform, Print, PlotFileSpec, SetDocument));
    c2.def("Folder", &PlotFileSpec::Folder, DOC(Bentley, MstnPlatform, Print, PlotFileSpec, Folder));
    c2.def("SetFolder", &PlotFileSpec::SetFolder, "value"_a, DOC(Bentley, MstnPlatform, Print, PlotFileSpec, SetFolder));
    c2.def("IsValid", &PlotFileSpec::IsValid, DOC(Bentley, MstnPlatform, Print, PlotFileSpec, IsValid));
    c2.def("IsEmpty", &PlotFileSpec::IsEmpty, DOC(Bentley, MstnPlatform, Print, PlotFileSpec, IsEmpty));
    c2.def("IsHfsDefined", &PlotFileSpec::IsHfsDefined, DOC(Bentley, MstnPlatform, Print, PlotFileSpec, IsHfsDefined));
    c2.def("IsMonikerDefined", &PlotFileSpec::IsMonikerDefined, DOC(Bentley, MstnPlatform, Print, PlotFileSpec, IsMonikerDefined));
    c2.def("IsEmbeddedSuffixDefined", &PlotFileSpec::IsEmbeddedSuffixDefined, DOC(Bentley, MstnPlatform, Print, PlotFileSpec, IsEmbeddedSuffixDefined));
    c2.def("IsHandleDefined", &PlotFileSpec::IsHandleDefined, DOC(Bentley, MstnPlatform, Print, PlotFileSpec, IsHandleDefined));
    c2.def("IsDms", &PlotFileSpec::IsDms, DOC(Bentley, MstnPlatform, Print, PlotFileSpec, IsDms));
    c2.def("DisplayFullName", &PlotFileSpec::DisplayFullName, DOC(Bentley, MstnPlatform, Print, PlotFileSpec, DisplayFullName));
    c2.def("GetDisplayFullName", &PlotFileSpec::GetDisplayFullName, "includeEmbeddedSuffix"_a = false, DOC(Bentley, MstnPlatform, Print, PlotFileSpec, GetDisplayFullName));
    c2.def("GetFileName", &PlotFileSpec::GetFileName, "includeEmbeddedSuffix"_a = false, DOC(Bentley, MstnPlatform, Print, PlotFileSpec, GetFileName));
    c2.def("ToString", &PlotFileSpec::ToString, DOC(Bentley, MstnPlatform, Print, PlotFileSpec, ToString));
    c2.def("UpdateFromHandle", &PlotFileSpec::UpdateFromHandle, DOC(Bentley, MstnPlatform, Print, PlotFileSpec, UpdateFromHandle));
    c2.def("ClearHandle", &PlotFileSpec::ClearHandle, DOC(Bentley, MstnPlatform, Print, PlotFileSpec, ClearHandle));
    c2.def("Clear", &PlotFileSpec::Clear, DOC(Bentley, MstnPlatform, Print, PlotFileSpec, Clear));
    c2.def_static("ContainsEmbeddedSuffix", &PlotFileSpec::ContainsEmbeddedSuffix, "path"_a, DOC(Bentley, MstnPlatform, Print, PlotFileSpec, ContainsEmbeddedSuffix));
    c2.def_static("GetEmbeddedSuffix", &PlotFileSpec::GetEmbeddedSuffix, "path"_a, DOC(Bentley, MstnPlatform, Print, PlotFileSpec, GetEmbeddedSuffix));
    c2.def_static("RemoveEmbeddedSuffix", &PlotFileSpec::RemoveEmbeddedSuffix, "path"_a, DOC(Bentley, MstnPlatform, Print, PlotFileSpec, RemoveEmbeddedSuffix));
    c2.def_static("Equals", &PlotFileSpec::Equals, "comparand1"_a, "comparand2"_a, DOC(Bentley, MstnPlatform, Print, PlotFileSpec, Equals));
    c2.def("SetFromDgnDocument", &PlotFileSpec::SetFromDgnDocument, "document"_a, DOC(Bentley, MstnPlatform, Print, PlotFileSpec, SetFromDgnDocument));
    c2.def("SetFromDgnFolder", &PlotFileSpec::SetFromDgnFolder, "folder"_a, DOC(Bentley, MstnPlatform, Print, PlotFileSpec, SetFromDgnFolder));
    c2.def_static("swap", [](PlotFileSpecR a, PlotFileSpecR b) {return swap(a, b); }, "a"_a, "b"_a, DOC(Bentley, MstnPlatform, Print, PlotFileSpec, swap));

    //===================================================================================
    //class PlotPropValue

    py::class_<PlotPropValue> c3(m, "PlotPropValue");
    c3.def(py::init<>(), R"doc(Default constructor.)doc");

    c3.def(py::init<int>(), "value"_a, R"doc(Constructs from an integer value.)doc");
    c3.def(py::init<double>(), "value"_a, R"doc(Constructs from an double value.)doc");
    c3.def(py::init<WCharCP>(), "value"_a, R"doc(Constructs from a string value.)doc");

    c3.def("__copy__", [](PlotPropValueCR self) { return PlotPropValue(self); }, R"doc(Copy constructor.)doc");
    c3.def("GetType", &PlotPropValue::GetType, DOC(Bentley, MstnPlatform, Print, PlotPropValue, GetType));
    c3.def("Assign", py::overload_cast<int>(&PlotPropValue::Assign), "value"_a, DOC(Bentley, MstnPlatform, Print, PlotPropValue, Assign));
    c3.def("Assign", py::overload_cast<double>(&PlotPropValue::Assign), "value"_a, DOC(Bentley, MstnPlatform, Print, PlotPropValue, Assign));
    c3.def("Assign", py::overload_cast<WCharCP>(&PlotPropValue::Assign), "value"_a, DOC(Bentley, MstnPlatform, Print, PlotPropValue, Assign));
    c3.def("GetInt", &PlotPropValue::GetInt, DOC(Bentley, MstnPlatform, Print, PlotPropValue, GetInt));
    c3.def("GetBool", &PlotPropValue::GetBool, DOC(Bentley, MstnPlatform, Print, PlotPropValue, GetBool));
    c3.def("GetDouble", &PlotPropValue::GetDouble, DOC(Bentley, MstnPlatform, Print, PlotPropValue, GetDouble));
    c3.def("GetString", &PlotPropValue::GetString, DOC(Bentley, MstnPlatform, Print, PlotPropValue, GetString));
    c3.def("IsValid", &PlotPropValue::IsValid, DOC(Bentley, MstnPlatform, Print, PlotPropValue, IsValid));
    c3.def("ToString", &PlotPropValue::ToString, "str"_a, DOC(Bentley, MstnPlatform, Print, PlotPropValue, ToString));
    c3.def_static("swap", [](PlotPropValueR a, PlotPropValueR b) {return swap(a, b); }, "a"_a, "b"_a, DOC(Bentley, MstnPlatform, Print, PlotPropValue, swap));

    //===================================================================================
    //class MstnPlot
    py::class_<MstnPlot> c4(m, "MstnPlot");

    c4.def_static("GetDefaultPltcfg", &mdlPlot_getDefaultPltcfg, "pltcfgFspec"_a, DOC(mdlPlot_getDefaultPltcfg));
    c4.def_static("GetDefaultSysPltcfg", &mdlPlot_getDefaultSysPltcfg, "pltcfgFspec"_a, DOC(mdlPlot_getDefaultSysPltcfg));
    c4.def_static("GetDefaultPdfPltcfg", &mdlPlot_getDefaultPdfPltcfg, "pltcfgFspec"_a, DOC(mdlPlot_getDefaultPdfPltcfg));

    c4.def_static("GetPaperSizeListFromPrinter", &mdlPlot_getPaperSizeListFromPrinter, "paperSizeList"_a, "printerName"_a, "orientation"_a, "units"_a, DOC(mdlPlot_getPaperSizeListFromPrinter));
    c4.def_static("GetPrintStyleNames", &mdlPlot_getPrintStyleNames, "printStyleNames"_a, "fromActiveDgnFile"_a, "fromDgnLibraries"_a, DOC(mdlPlot_getPrintStyleNames));

    c4.def_static("GetErrno", &mdlPlot_getErrno, DOC(mdlPlot_getErrno));
    c4.def_static("SetErrno", &mdlPlot_setErrno, "value"_a, DOC(mdlPlot_setErrno));
}

