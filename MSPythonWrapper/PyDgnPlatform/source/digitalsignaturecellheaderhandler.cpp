/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnPlatform\source\digitalsignaturecellheaderhandler.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <RmgrTools/Tools/ToolSubs.h>
#include <DgnPlatform/DigitalSignatureCellHeaderHandler.h>



static const char * __doc_Bentley_DgnPlatform_DigitalSignatureCellHeaderHandler_GetData =R"doc(Test of an element is a digital signature and, if so, get information
about the signature.

:param sigel:
    element to query

:returns:
    Information about the digital signature @Remarks Call IsValid on
    the returned object. If false, then *sigel* is not a digital
    signature. Bentley Systems +---------------+---------------+------
    ---------+---------------+---------------+------)doc";

static const char * __doc_Bentley_DgnPlatform_DigitalSignatureCellHeaderHandler_GetPrerequisites =R"doc(Query the signatures on which this signature depends

:param prereqs:
    prerequisite signature elements

:param sigel:
    signature element to query @Return non-zero error status if this
    is not a valid signature element Bentley Systems +----------------
    ------------------------------------------------------)doc";

static const char * __doc_Bentley_DgnPlatform_DigitalSignatureCellHeaderHandler_Verify =R"doc(Verify a digital signature. This function returns true if and only if
the contents to which the signature applies are unchanged since the
signature was created and if the signature itself it unchanged. If the
signature has prerequisites, it is verified only of those required
signatures are also verified. @Remarks This function does not verify
the trustworthiness of the signer's certificate.

:param sigref:
    signature element to test @Return SUCCESS if signature is verified
    Bentley Systems +---------------+---------------+---------------+-
    --------------+---------------+------)doc";



/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_DigitalSignatureCellHeaderHandler(py::module_& m)
    {
    //===================================================================================
    // struct DigitalSignatureCellHeaderHandler
    py::class_< DigitalSignatureCellHeaderHandler
        , Type2Handler
        , ITextEdit
    > c1(m, "DigitalSignatureCellHeaderHandler");

    if (true)
        {
        //===================================================================================
        // class DigitalSignatureData
        py::class_< DigitalSignatureCellHeaderHandler::DigitalSignatureData, DsigQuery> c1_1(c1, "DigitalSignatureData");

        c1_1.def(py::init<DigitalSignatureCellHeaderHandler::DigitalSignatureData const&>(), "rhs"_a);

        }

    c1.def_static("ConvertToSignatureElement",
                  [](EditElementHandleR sigEh,
                     py::bytes const& x509Cert,
                     bool includeReferences,
                     ElementAgenda const& prereqs,
                     DsigAnnotationData const& annotations,
                     bool includeCertChain)
                  {
                  std::string strData = (std::string) x509Cert;
                  return DigitalSignatureCellHeaderHandler::ConvertToSignatureElement(sigEh, (const Byte*) strData.data(), (ULong32) strData.size(),
                                                                                      includeReferences, prereqs, annotations, includeCertChain);
                  }, "sigEh"_a, "x509Cert"_a, "includeReferences"_a = false, "prereqs"_a = ElementAgenda(), 
                      "annotation"_a = DsigAnnotationData(), "includeCertChain"_a = true);

    c1.def_static("Verify", &DigitalSignatureCellHeaderHandler::Verify, "sigref"_a, DOC(Bentley, DgnPlatform, DigitalSignatureCellHeaderHandler, Verify));
    c1.def_static("GetPrerequisites", &DigitalSignatureCellHeaderHandler::GetPrerequisites, "prereqs"_a, "sigel"_a, DOC(Bentley, DgnPlatform, DigitalSignatureCellHeaderHandler, GetPrerequisites));
    c1.def_static("GetData", &DigitalSignatureCellHeaderHandler::GetData, "sigel"_a, DOC(Bentley, DgnPlatform, DigitalSignatureCellHeaderHandler, GetData));

    c1.def_property_readonly_static("Instance", [] (py::object const&) { return std::unique_ptr<DigitalSignatureCellHeaderHandler, py::nodelete>(&DigitalSignatureCellHeaderHandler::GetInstance()); });
    c1.def_static("GetInstance", &DigitalSignatureCellHeaderHandler::GetInstance, py::return_value_policy::reference);
    
    //===================================================================================
    // struct FileSignatureCollection
    py::class_< FileSignatureCollection> c2(m, "FileSignatureCollection");

    c2.def(py::init<DgnFileR>(), "file"_a, py::keep_alive<1, 2>());
    c2.def("__iter__", [] (FileSignatureCollection& self) { return py::make_iterator(self.begin(), self.end()); }, py::keep_alive<0, 1>());

    //===================================================================================
    // struct ModelSignatureCollection
    py::class_< ModelSignatureCollection> c3(m, "ModelSignatureCollection");

    c3.def(py::init<DgnModelR>(), "model"_a, py::keep_alive<1, 2>());
    c3.def("__iter__", [] (ModelSignatureCollection& self) { return py::make_iterator(self.begin(), self.end()); }, py::keep_alive<0, 1>());

    //===================================================================================
    // struct ApplicableSignaturesCollection
    py::class_< ApplicableSignaturesCollection> c4(m, "ApplicableSignaturesCollection");

    c4.def(py::init<DgnModelR>(), "model"_a, py::keep_alive<1, 2>());
    c4.def("__iter__", [] (ApplicableSignaturesCollection& self) { return py::make_iterator(self.begin(), self.end()); }, py::keep_alive<0, 1>());
    }