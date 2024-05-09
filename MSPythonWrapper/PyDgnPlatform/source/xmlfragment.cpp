/*--------------------------------------------------------------------------------------+
|
|     $Source:MSPython\MSPythonWrapper\PyDgnPlatform\source\xmlfragment.cpp
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <DgnPlatform/XMLFragment.h>

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       8/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_XmlFragment(py::module_& m)
{
    //struct XmlFragment:RefCountedBase
    py::class_<XmlFragment, XmlFragmentPtr> c0(m, "XmlFragment");

    c0.def(py::init(py::overload_cast<UShort, UShort>(&XmlFragment::Construct)), "appID"_a, "appType"_a);

    c0.def(py::init([](UShort appID, UShort appType, bool isCompressed, WStringCR wcsSchemaURN, WStringCR wcsText)
                      { return XmlFragment::Construct(appID, appType, isCompressed, wcsSchemaURN.c_str(), wcsText.c_str()); }),
                      "appID"_a, "appType"_a, "isCompressed"_a, "wcsSchemaURN"_a, "wcsText"_a);

    c0.def(py::init([](UShort appID, UShort appType, WStringCR wcsText)
                      { return XmlFragment::Construct(appID, appType, wcsText.c_str()); }),
                      "appID"_a, "appType"_a, "wcsText"_a);

    c0.def(py::init([](UInt8Array& buf, UInt16 appId, UInt16 appType)
                      {
                      size_t ulBufferSize = buf.size();
                      return XmlFragment::ConstructFromBuffer((byte*)buf.data(), (UInt32)ulBufferSize, appId, appType); 
                      }),"buf"_a, "appId"_a, "appType"_a);

    c0.def(py::init(&XmlFragment::ConstructFromXmlFragmentElement), "eh"_a);

    c0.def_static("IsFragmentElement", [](ElementHandleCR eh, boost::optional<UInt16> appID, boost::optional<UInt16> appType)
                                         {
                                         return XmlFragment::IsFragmentElement(eh, appID.get_ptr(), appType.get_ptr());
                                         }, "eh"_a, "appID"_a = nullptr, "appType"_a = nullptr);
    c0.def_static("StripFromElementByAppIDAndType", [](EditElementHandleR eeh, boost::optional<UShort> pAppID, boost::optional<UShort> pAppType)
                                                    {
                                                        return XmlFragment::StripFromElementByAppIDAndType(eeh, pAppID.get_ptr(), pAppType.get_ptr());
                                                    }, "eeh"_a, "pAppID"_a , "pAppType"_a);
    c0.def_static("StripAllFromElement", &XmlFragment::StripAllFromElement, "eeh"_a);
    c0.def_static("ElementHasXmlFragmentLinkage", [](ElementHandleCR  eh, boost::optional<UShort> pAppID, boost::optional<UShort> pAppType)
                                                  {
                                                      return XmlFragment::ElementHasXmlFragmentLinkage(eh, pAppID.get_ptr(), pAppType.get_ptr());
                                                  }, "eh"_a, "pAppID"_a, "pAppType"_a);

    c0.def_property("AppID", &XmlFragment::GetAppID, &XmlFragment::SetAppID);
    c0.def("GetAppID", &XmlFragment::GetAppID);
    c0.def("SetAppID", &XmlFragment::SetAppID);

    c0.def_property("AppType", &XmlFragment::GetAppType, &XmlFragment::SetAppType);
    c0.def("GetAppType", &XmlFragment::GetAppType);
    c0.def("SetAppType", &XmlFragment::SetAppType);

    c0.def_property("SchemaURN",
        [](XmlFragment & self) {return WString(self.GetSchemaURN()); },
        [](XmlFragment & self, WStringCR value) {self.SetSchemaURN(value.c_str()); });
    c0.def("GetSchemaURN", [](XmlFragment & self) {return WString(self.GetSchemaURN());});
    c0.def("SetSchemaURN", [](XmlFragment & self, WStringCR value) {self.SetSchemaURN(value.c_str()); });

    c0.def_property("Text",
        [](XmlFragment& self) {return WString(self.GetText()); },
        [](XmlFragment& self, WStringCR value) {self.SetText(value.c_str()); });
    c0.def("GetText", [](XmlFragment& self) {return WString(self.GetText()); });
    c0.def("SetText", [](XmlFragment& self, WStringCR value) {self.SetText(value.c_str()); });

    c0.def_property("IsCompressed", &XmlFragment::IsCompressed, &XmlFragment::SetIsCompressed);
    c0.def("GetIsCompressed", &XmlFragment::IsCompressed);
    c0.def("SetIsCompressed", &XmlFragment::SetIsCompressed);

    c0.def("GetStreamData", [](XmlFragment& self)
          { 
          byte*  pBuf = nullptr;
          UInt32 bufSize(0);
          StatusInt ret = self.GetStreamData(&pBuf, &bufSize);
          return py::make_tuple(ret, py::cast(pBuf, py::return_value_policy::reference), bufSize);
          });

    c0.def("FreeStreamData", &XmlFragment::FreeStreamData);
    c0.def("AttachToElement", &XmlFragment::AttachToElement, "eeh"_a);
    c0.def("CreateXmlElement", &XmlFragment::CreateXmlElement, "eeh"_a, "model"_a, "setNonModelFlag"_a);

    //struct XmlFragmentList:RefCountedBase
    py::class_<XmlFragmentList, XmlFragmentListPtr> c1(m, "XmlFragmentList");
    py::bind_vector< bvector<XmlFragmentPtr> >(m, "XmlFragmentPtrArray", py::module_local(false));

    c1.def("__iter__", [](XmlFragmentList& self) { return py::make_iterator(self.begin(), self.end()); }, py::keep_alive<0, 1>());

    c1.def(py::init(&XmlFragmentList::ConstructFromFragment), "xmlFragment"_a);

    c1.def(py::init([](WStringCR wcsText, WStringCR wcsSchemaURN, UShort appID, UShort appType)
            { 
            return XmlFragmentList::Construct(const_cast<wchar_t*>(wcsText.c_str()), const_cast<wchar_t*>(wcsSchemaURN.c_str()), appID, appType);
            }),"wcsText"_a, "wcsSchemaURN"_a, "appID"_a, "appType"_a);

    c1.def(py::init([](UInt8Array& buf, UInt16 appId, UInt16 appType)
            { 
            size_t ulBufferSize = buf.size();
            return XmlFragmentList::ConstructFromBuffer((byte*)buf.data(), (UInt32)ulBufferSize, appId, appType);
            }),"buf"_a, "appID"_a = 0, "appType"_a = 0);
    
    c1.def("Append", &XmlFragmentList::Append, "xmlFragment"_a);
    c1.def("Prepend", &XmlFragmentList::Prepend, "xmlFragment"_a);
    c1.def("Remove", &XmlFragmentList::Remove, "index"_a);
    c1.def("GetCount", &XmlFragmentList::GetCount);
    c1.def("GetFragmentAtIndex", &XmlFragmentList::GetFragmentAtIndex, "index"_a);
    c1.def_static("ExtractFromElement", [](ElementHandleCR ehh, boost::optional<UShort> appID, boost::optional<UShort> appType)
                                        {
                                            return XmlFragmentList::ExtractFromElement(ehh, appID.get_ptr(), appType.get_ptr());
                                        }, "eeh"_a, "appID"_a=nullptr, "appType"_a= nullptr);
    c1.def("AttachToElement", &XmlFragmentList::AttachToElement, "eeh"_a);
}