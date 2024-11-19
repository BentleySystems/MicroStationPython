/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnPlatform\source\dgnstorehandlers.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <DgnPlatform/DgnStoreHandlers.h>



static const char * __doc_Bentley_DgnPlatform_TagSetHandler_ExtractTagDefs =R"doc(Extract all the tag definitions associated with a given tagset
element.

Parameter ``eh``:
    IN tagset element.

Parameter ``tagDefs``:
    OUT an array of tagset definition pointers.

Remark:
    s The caller must free the allocated memory @See
    TagSetHandler::FreeTagDefs)doc";

static const char * __doc_Bentley_DgnPlatform_TagSetHandler_ExtractTagDefByName =R"doc(Get the tag definition of a tagsetelement by name.

Parameter ``eh``:
    IN tagset element.

Parameter ``tagDef``:
    OUT tagset definition.

Parameter ``name``:
    IN name of the tag set)doc";

static const char * __doc_Bentley_DgnPlatform_TagSetHandler_ExtractTagDefByID =R"doc(Get the tag definition of a tagsetelement by id.

Parameter ``eh``:
    IN tagset element.

Parameter ``tagDef``:
    OUT tagset definition.

Parameter ``tagDefID``:
    IN Id to look up the tagset element.)doc";

static const char * __doc_Bentley_DgnPlatform_TagSetHandler_SetReportName =R"doc(Sets the name of tag set report.

Parameter ``name``:
    IN report name of the tag set

Parameter ``eeh``:
    INOUT tagset element.)doc";

static const char * __doc_Bentley_DgnPlatform_TagSetHandler_SetSetName =R"doc(Sets the name of tag set.

Parameter ``name``:
    IN name of the tag set

Parameter ``eeh``:
    INOUT tagset element.)doc";

static const char * __doc_Bentley_DgnPlatform_TagSetHandler_GetByName =R"doc(Look up a tag set element based on Id.

Parameter ``setName``:
    IN name of the tag set

Parameter ``dgnFile``:
    IN file in which to search for the tagset.

Parameter ``eeh``:
    OUT tagset element.)doc";

static const char * __doc_Bentley_DgnPlatform_TagSetHandler_GetByID =R"doc(Look up a tag set element based on Id.

Parameter ``uniqueId``:
    IN Id to be looked up.

Parameter ``dgnFile``:
    IN file in which to search for the tagset.

Parameter ``eeh``:
    OUT tagset element.)doc";

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_DgnStoreHandlers(py::module_& m)
    {
    //===================================================================================
    // struct DgnStoreHdrHandler
    py::class_< DgnStoreHdrHandler, Handler> c1(m, "DgnStoreHdrHandler");   


    c1.def_static("IsDgnStoreElement", &DgnStoreHdrHandler::IsDgnStoreElement, "in"_a, "dgnStoreId"_a = 0, "applicationId"_a = 0);

    c1.def_static("GetDgnStoreIds", [] (ElementHandleCR in)
                  {
                  UInt32 dgnStoreId = 0;
                  UInt32 applicationId = 0;
                  auto retVal = DgnStoreHdrHandler::GetDgnStoreIds(&dgnStoreId, &applicationId, in);
                  return py::make_tuple(retVal, dgnStoreId, applicationId);
                  }, "in"_a);

    c1.def_static("Extract", [] (UInt32 dgnStoreId, UInt32 applicationId, ElementHandleCR eh)
                  {
                  void* pData = nullptr;
                  UInt32 dataSize = 0;
                  py::tuple outVal;
                  auto retVal = DgnStoreHdrHandler::Extract(&pData, &dataSize, dgnStoreId, applicationId, eh);
                  if (retVal == SUCCESS && nullptr != pData && dataSize > 0)
                      {
                      outVal = py::make_tuple(retVal, py::bytes((const char*) pData, dataSize));
                      DgnStoreHdrHandler::FreeExtractedData(pData);
                      }
                  else
                      outVal = py::make_tuple(retVal, py::bytes());

                  return outVal;
                  }, "dgnStoreId"_a, "applicationId"_a, "eh"_a);

    c1.def_static("ExtractFromCell", [] (UInt32 dgnStoreId, UInt32 applicationId, ElementHandleCR eh)
                  {
                  void* pData = nullptr;
                  UInt32 dataSize = 0;
                  py::tuple outVal;
                  auto retVal = DgnStoreHdrHandler::ExtractFromCell(&pData, &dataSize, dgnStoreId, applicationId, eh);
                  if (retVal == SUCCESS && nullptr != pData && dataSize > 0)
                      {
                      outVal = py::make_tuple(retVal, py::bytes((const char*) pData, dataSize));
                      DgnStoreHdrHandler::FreeExtractedData(pData);
                      }
                  else
                      outVal = py::make_tuple(retVal, py::bytes());

                  return outVal;
                  }, "dgnStoreId"_a, "applicationId"_a, "eh"_a);

    c1.def_static("Create", [] (EditElementHandleR eeh, py::bytes const& byteData, UInt32 dgnStoreId, UInt32 applicationId, DgnModelRefP modelRef)
                  {
                  std::string strData = (std::string) byteData;
                  return DgnStoreHdrHandler::Create(eeh, (void*) strData.data(), (UInt32) strData.size(), dgnStoreId, applicationId, modelRef);
                  }, "eeh"_a, "byteData"_a, "dgnStoreId"_a, "applicationId"_a, "modelRef"_a);

    c1.def_static("AppendToCell", [] (EditElementHandleR eeh, py::bytes const& byteData, UInt32 dgnStoreId, UInt32 applicationId)
                  {
                  std::string strData = (std::string) byteData;
                  return DgnStoreHdrHandler::AppendToCell(eeh, (void*) strData.data(), (UInt32) strData.size(), dgnStoreId, applicationId);
                  }, "eeh"_a, "byteData"_a, "dgnStoreId"_a, "applicationId"_a);

    c1.def_static("RemoveFromCell", &DgnStoreHdrHandler::RemoveFromCell, "CellEeh"_a, "dgnStoreId"_a, "applicationId"_a);
    
    c1.def_property_readonly_static("Instance", [] (py::object const&) { return std::unique_ptr<DgnStoreHdrHandler, py::nodelete>(&DgnStoreHdrHandler::GetInstance()); });
    c1.def_static("GetInstance", &DgnStoreHdrHandler::GetInstance);
        
    //===================================================================================
    py::class_< TagSetHandler
        , DgnStoreHdrHandler
    > c2(m, "TagSetHandler");

    c2.def_static("GetByID", &TagSetHandler::GetByID, "eeh"_a, "uniqueId"_a, "dgnFile"_a, DOC(Bentley, DgnPlatform, TagSetHandler, GetByID));
    c2.def_static("GetByName", &TagSetHandler::GetByName, "eeh"_a, "setName"_a, "dgnFile"_a, DOC(Bentley, DgnPlatform, TagSetHandler, GetByName));
    
    c2.def_static("GetSetName", [] (WStringR name, ElementHandleCR elm)
                  {
                  WChar szName[1024] = {0};
                  auto retVal = TagSetHandler::GetSetName(szName, _countof(szName), elm);
                  if (retVal == SUCCESS)
                      name.assign(szName);
                  }, "name"_a, "elm"_a);

    c2.def_static("GetReportName", [] (WStringR name, ElementHandleCR elm)
                  {
                  WChar szName[1024] = {0};
                  auto retVal = TagSetHandler::GetReportName(szName, _countof(szName), elm);
                  if (retVal == SUCCESS)
                      name.assign(szName);
                  }, "name"_a, "elm"_a);

    c2.def_static("SetSetName", &TagSetHandler::SetSetName, "eeh"_a, "name"_a, DOC(Bentley, DgnPlatform, TagSetHandler, SetSetName));
    c2.def_static("SetReportName", &TagSetHandler::SetReportName, "eeh"_a, "name"_a, DOC(Bentley, DgnPlatform, TagSetHandler, SetReportName));
    c2.def_static("ExtractTagDefByID", &TagSetHandler::ExtractTagDefByID, "eh"_a, "tagDef"_a, "tagDefID"_a, DOC(Bentley, DgnPlatform, TagSetHandler, ExtractTagDefByID));
    c2.def_static("ExtractTagDefByName", &TagSetHandler::ExtractTagDefByName, "eh"_a, "tagDef"_a, "name"_a, DOC(Bentley, DgnPlatform, TagSetHandler, ExtractTagDefByName));
    c2.def_static("ExtractTagDefs", &TagSetHandler::ExtractTagDefs, "eh"_a, "tagDefs"_a, DOC(Bentley, DgnPlatform, TagSetHandler, ExtractTagDefs));
    c2.def_static("Create", [] (EditElementHandleR eeh, bvector<DgnTagDefinition>& tagDefs, UInt32 numTagDefs, WCharCP setName, WCharCP reportName, bool assignNewIds, DgnFileR file, int ownerID)
                  {
                  return TagSetHandler::Create(eeh, &tagDefs[0], numTagDefs, setName, reportName, assignNewIds, file, ownerID);
                  }, "eeh"_a, "tagDefs"_a, "numTagDefs"_a, "setName"_a, "reportName"_a, "assignNewIds"_a, "file"_a, "ownerID"_a = 0);

    c2.def_static("GetByID", &TagSetHandler::GetByID, "eeh"_a, "uniqueId"_a, "dgnFile"_a, DOC(Bentley, DgnPlatform, TagSetHandler, GetByID));

    c2.def_property_readonly_static("Instance", [] (py::object const&) { return std::unique_ptr<TagSetHandler, py::nodelete>(&TagSetHandler::GetInstance()); });
    c2.def_static("GetInstance", &TagSetHandler::GetInstance);
        
    //===================================================================================
    // struct TagSetCollection
    py::class_< TagSetCollection> c3(m, "TagSetCollection");

    c3.def(py::init<DgnFileR>(), "dgnFile"_a);
    c3.def("__iter__", [] (TagSetCollection& self) { return py::make_iterator(self.begin(), self.end()); }, py::keep_alive<0, 1>());
        
    //===================================================================================
    // struct TagDefCollection
    py::class_< TagDefCollection, TagDefCollectionPtr> c4(m, "TagDefCollection");

    c4.def(py::init(&TagDefCollection::Create), "element"_a);
    c4.def("__iter__", [] (TagDefCollection& self) { return py::make_iterator(self.begin(), self.end()); }, py::keep_alive<0, 1>());
        
    }