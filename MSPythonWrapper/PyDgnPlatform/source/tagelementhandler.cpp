/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnPlatform\source\tagelementhandler.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <DgnPlatform/TagElementHandler.h>



static const char * __doc_Bentley_DgnPlatform_TagElementHandler_SetOffset =R"doc(Modify the origin offset stored in the tag element

:param tagElement:
    (input) tag element

:param offset:
    (input) new offset)doc";

static const char * __doc_Bentley_DgnPlatform_TagElementHandler_SetVisibility =R"doc(Modify the visibility of a tag element

:param tagElement:
    (input) tag element

:param hide:
    (input) bool whether to hide the tag element

:param isSharedCell:
    (input) bool whether it is associated with a shared cell)doc";

static const char * __doc_Bentley_DgnPlatform_TagElementHandler_GetAttributeValue =R"doc(Get the attribute value associated with the tag element.

:param tagElement:
    (input) tag element.

:param value:
    (output) value.)doc";

static const char * __doc_Bentley_DgnPlatform_TagElementHandler_SetAttributeValue =R"doc(Modify the attribute value associated with the tag element.

:param tagElement:
    (input) Target element.

:param value:
    (input) The new value to set.)doc";

static const char * __doc_Bentley_DgnPlatform_TagElementHandler_GetTargetElement =R"doc(Get the target element associated with the tag element.

:param targetOut:
    (output) Target element.

:param tagElement:
    (input) Tag element to query on.)doc";

static const char * __doc_Bentley_DgnPlatform_TagElementHandler_Extract =R"doc(Extract the tag definitions associated with a tag element

:param tagDef:
    (output) filled tag definition information

:param in:
    (input) tag element

:param dgnCache:
    (input) the loaded DGN cache to search for tag definition)doc";

static const char * __doc_Bentley_DgnPlatform_TagElementHandler_GetSetName =R"doc(Gets tag set name

:param name:
    (output) tag set name

:param bufferSize:
    (input) sizeof(allocated) name bugger

:param in:
    (input) tag element

:param dgnCache:
    (input) the loaded DGN cache to search for tag definition
    @DotNetMethodParameterIsReturnString{name,bufferSize}
    @DotNetMethodCustomImplementation)doc";

static const char * __doc_Bentley_DgnPlatform_TagElementHandler_SetSetDefinitionID =R"doc(Sets element Id of the tagset associated with this tag element

:param in:
    (input) tag element

:param id:
    (input) tagset element id)doc";

static const char * __doc_Bentley_DgnPlatform_TagElementHandler_GetSetDefinitionID =R"doc(Gets element Id of the tagset associated with this tag element

:param in:
    (input) tag element)doc";

static const char * __doc_Bentley_DgnPlatform_ITagCreateData_SetTagVisibility =R"doc(Set the value associated with the tag

:param hide:
    (input) set true to hide the tag element.)doc";

static const char * __doc_Bentley_DgnPlatform_ITagCreateData_SetAttributeValue =R"doc(Set the value associated with the tag. By default, the value comes
from the default value of tag in the tagset

:param value:
    (input) tag value.)doc";

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_TagElementHandler(py::module_& m)
    {
    //===================================================================================
    // struct ITagCreateData
    py::class_< ITagCreateData, ITagCreateDataPtr> c1(m, "ITagCreateData");

    c1.def(py::init(py::overload_cast<WCharCP, WCharCP, DgnTextStyleCR, DgnFileR>(&ITagCreateData::Create)), "tagName"_a, "tagSetName"_a, "textStyle"_a, "dgnFile"_a);
    c1.def("SetAttributeValue", &ITagCreateData::SetAttributeValue, "value"_a, DOC(Bentley, DgnPlatform, ITagCreateData, SetAttributeValue));
    c1.def("SetTagVisibility", &ITagCreateData::SetTagVisibility, "hide"_a, DOC(Bentley, DgnPlatform, ITagCreateData, SetTagVisibility));

    //===================================================================================
    // struct TagElementHandler
    py::class_< TagElementHandler, std::unique_ptr< TagElementHandler, py::nodelete>, DisplayHandler, ITextEdit, IAnnotationHandler> c2(m, "TagElementHandler");

    c2.def_static("GetSetDefinitionID", &TagElementHandler::GetSetDefinitionID, "eh"_a, DOC(Bentley, DgnPlatform, TagElementHandler, GetSetDefinitionID));
    c2.def_static("SetSetDefinitionID", &TagElementHandler::SetSetDefinitionID, "eeh"_a, "elemId"_a, DOC(Bentley, DgnPlatform, TagElementHandler, SetSetDefinitionID));
    
    c2.def_static("GetSetName", [] (WString& name, ElementHandleCR in, DgnModelR dgnCache)
                  {
                  WChar szName[512] = {0};
                  auto retVal = TagElementHandler::GetSetName(szName, _countof(szName), in, dgnCache);
                  if (retVal == SUCCESS)
                      name.assign(szName);

                  return retVal;
                  }, "name"_a, "tagSetEh"_a, "dgnModel"_a, DOC(Bentley, DgnPlatform, TagElementHandler, GetSetName));

    c2.def_static("Extract", 
                  py::overload_cast<DgnTagDefinitionR, ElementHandleCR, DgnModelR>(&TagElementHandler::Extract),
                  "tagDef"_a, "in"_a, "dgnModel"_a, DOC(Bentley, DgnPlatform, TagElementHandler, Extract));

    c2.def_static("Extract", 
                  py::overload_cast<DgnTagSpec&, ElementHandleCR, DgnModelR>(&TagElementHandler::Extract), 
                  "tagSpec"_a, "in"_a, "dgnModel"_a, DOC(Bentley, DgnPlatform, TagElementHandler, Extract));

    c2.def_static("CreateTagElement",
                  py::overload_cast<EditElementHandleR, ElementHandleCP, ITagCreateDataCR, DgnModelRefR, bool, DPoint3dCR, RotMatrixCR, ElementRefP>(&TagElementHandler::Create),
                  "TagEeh"_a, "templateEh"_a, "tagInfo"_a, "modelRef"_a, "is3d"_a, "origin"_a, "orientation"_a, "target"_a);

    c2.def_static("GetTargetElement", &TagElementHandler::GetTargetElement, "targetOut"_a, "targetElement"_a, DOC(Bentley, DgnPlatform, TagElementHandler, GetTargetElement));
    c2.def_static("SetAttributeValue", &TagElementHandler::SetAttributeValue, "tagElement"_a, "value"_a, DOC(Bentley, DgnPlatform, TagElementHandler, SetAttributeValue));
    c2.def_static("GetAttributeValue", &TagElementHandler::GetAttributeValue, "targetElement"_a, "value"_a, DOC(Bentley, DgnPlatform, TagElementHandler, GetAttributeValue));
    c2.def_static("SetVisibility", &TagElementHandler::SetVisibility, "tagElement"_a, "hide"_a, "isSharedCell"_a, DOC(Bentley, DgnPlatform, TagElementHandler, SetVisibility));
    c2.def_static("SetOffset", &TagElementHandler::SetOffset, "tagElement"_a, "offset"_a, DOC(Bentley, DgnPlatform, TagElementHandler, SetOffset));
    c2.def_property_readonly_static("Instance", [] (py::object const&) { return std::unique_ptr< TagElementHandler, py::nodelete>(&TagElementHandler::GetInstance()); });
    c2.def_static("GetInstance", &TagElementHandler::GetInstance, py::return_value_policy::reference);
    }