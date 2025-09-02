/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyBentley\source\dsig.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"

namespace Bentley
{
struct DsigDigitalSignature {};
struct DsigPublicKeyBuf {};
struct DsigCertificate {};
}

#include <RmgrTools/Tools/Dsig.h>

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_Dsig(py::module_& m)
    {
    //===================================================================================
    // struct DsigAnnotationData
    py::class_< DsigAnnotationData> c1(m, "DsigAnnotationData","Signature annotation data. \n@Remarks Annotation data is not certified> by any outside party. \nThe identity and trustworthiness of the signer should be based solely on the certificate stored in the signature.");

    c1.def(py::init<>());
    c1.def_readwrite("signDate", &DsigAnnotationData::signDate);

    c1.def_property("Name",
                    [] (DsigAnnotationData const& self) { return self.name; },
                    py::cpp_function([] (DsigAnnotationData& self, WCharCP newVal) { self.name = newVal; }, py::keep_alive<1, 2>()),"This string may identify the signer.");

    c1.def_property("Purpose",
                    [] (DsigAnnotationData const& self) { return self.purpose; },
                    py::cpp_function([] (DsigAnnotationData& self, WCharCP newVal) { self.purpose = newVal; }, py::keep_alive<1, 2>()),"This string may indicate the signer's purpose in creating the signature.");

    c1.def_property("Location",
                    [] (DsigAnnotationData const& self) { return self.location; },
                    py::cpp_function([] (DsigAnnotationData& self, WCharCP newVal) { self.location = newVal; }, py::keep_alive<1, 2>()),"This string may identify the signer's computer or organization.");

    c1.def_readwrite("expiryDate", &DsigAnnotationData::expiryDate,"If non-zero, date on which the digital signature expires. UTC. Milliseconds since 1970/1/1. ");

    //===================================================================================
    // class DsigQuery
    py::class_< DsigQuery, std::unique_ptr<DsigQuery, py::nodelete> > c2(m, "DsigQuery");

    c2.def("IsValid", &DsigQuery::IsValid);
    
    c2.def_property_readonly("CommonName", &DsigQuery::GetCommonName);
    c2.def("GetCommonName", &DsigQuery::GetCommonName, py::return_value_policy::reference_internal);
    
    c2.def_property_readonly("Email", &DsigQuery::GetEmail);
    c2.def("GetEmail", &DsigQuery::GetEmail, py::return_value_policy::reference_internal);
    
    c2.def("IncludesEntireFile", &DsigQuery::IncludesEntireFile);
    c2.def("IncludesReferences", &DsigQuery::IncludesReferences);
    c2.def("GetCertificate", &DsigQuery::GetCertificate, "x509Cert"_a);
    c2.def("GetCertificateChain", &DsigQuery::GetCertificateChain, "pkcs7"_a);
    c2.def("GetPublicKey", py::overload_cast<bvector<Byte>&>(&DsigQuery::GetPublicKey, py::const_), "x509PublicKeyInfo"_a);
    c2.def("GetAnnotationData", &DsigQuery::GetAnnotationData, py::return_value_policy::reference_internal);
    }
