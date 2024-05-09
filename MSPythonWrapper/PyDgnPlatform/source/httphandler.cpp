/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnPlatform\source\httphandler.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <DgnPlatform/HttpHandler.h>



//=======================================================================================
// Publicist class for IHttpRequestCancellationToken.
// @bsiclass                                                                   02/23
//=======================================================================================
struct IHttpRequestCancellationTokenPub : IHttpRequestCancellationToken
    {
    public:
        using IHttpRequestCancellationToken::_ShouldCancelHttpRequest;
        using IHttpRequestCancellationToken::_UpdateProgressInfo;
    };

//=======================================================================================
// Trampoline class for IHttpRequestCancellationToken.
// @bsiclass                                                                   02/23
//=======================================================================================
struct IPyHttpRequestCancellationToken : IHttpRequestCancellationToken
    {
    public:
        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _ShouldCancelHttpRequest() const override
            { PYBIND11_OVERRIDE_PURE_EXR(bool, IHttpRequestCancellationToken, _ShouldCancelHttpRequest, false, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual void _UpdateProgressInfo(int64_t dltotal, int64_t dlnow, int64_t ultotal, int64_t ulnow) override
            { PYBIND11_OVERRIDE_EX(void, IHttpRequestCancellationToken, _UpdateProgressInfo, dltotal, dlnow, ultotal, ulnow); }
    };

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_HttpHandler(py::module_& m)
    {
    //===================================================================================
    // enum class HttpRequestStatus
    py::enum_< HttpRequestStatus>(m, "HttpRequestStatus")
        .value("eUnknownError", HttpRequestStatus::UnknownError)
        .value("eNoConnection", HttpRequestStatus::NoConnection)
        .value("eCouldNotResolveHost", HttpRequestStatus::CouldNotResolveHost)
        .value("eCouldNotResolveProxy", HttpRequestStatus::CouldNotResolveProxy)
        .value("eAborted", HttpRequestStatus::Aborted)
        .value("eSuccess", HttpRequestStatus::Success)
        .export_values();

    //===================================================================================
    // enum class HttpResponseStatus
    py::enum_< HttpResponseStatus>(m, "HttpResponseStatus")
        .value("eUnknown", HttpResponseStatus::Unknown)
        .value("eSuccess", HttpResponseStatus::Success)
        .value("eCreated", HttpResponseStatus::Created)
        .value("eAccepted", HttpResponseStatus::Accepted)
        .value("eNonAuthoritativeInformation", HttpResponseStatus::NonAuthoritativeInformation)
        .value("eNoContent", HttpResponseStatus::NoContent)
        .value("eResetContent", HttpResponseStatus::ResetContent)
        .value("ePartialContent", HttpResponseStatus::PartialContent)
        .value("eMultipleChoices", HttpResponseStatus::MultipleChoices)
        .value("eMovedPermanently", HttpResponseStatus::MovedPermanently)
        .value("eFound", HttpResponseStatus::Found)
        .value("eSeeOther", HttpResponseStatus::SeeOther)
        .value("eNotModified", HttpResponseStatus::NotModified)
        .value("eUseProxy", HttpResponseStatus::UseProxy)
        .value("eTemporaryRedirect", HttpResponseStatus::TemporaryRedirect)
        .value("eBadRequest", HttpResponseStatus::BadRequest)
        .value("eUnauthorized", HttpResponseStatus::Unauthorized)
        .value("ePaymentRequired", HttpResponseStatus::PaymentRequired)
        .value("eForbidden", HttpResponseStatus::Forbidden)
        .value("eNotFound", HttpResponseStatus::NotFound)
        .value("eMethodNotAllowed", HttpResponseStatus::MethodNotAllowed)
        .value("eNotAcceptable", HttpResponseStatus::NotAcceptable)
        .value("eProxyAuthenticationRequired", HttpResponseStatus::ProxyAuthenticationRequired)
        .value("eRequestTimeout", HttpResponseStatus::RequestTimeout)
        .value("eConflict", HttpResponseStatus::Conflict)
        .value("eGone", HttpResponseStatus::Gone)
        .value("eLengthRequired", HttpResponseStatus::LengthRequired)
        .value("ePreconditionFailed", HttpResponseStatus::PreconditionFailed)
        .value("eRequestEntityTooLarge", HttpResponseStatus::RequestEntityTooLarge)
        .value("eRequestUriTooLong", HttpResponseStatus::RequestUriTooLong)
        .value("eUnsupportedMediaType", HttpResponseStatus::UnsupportedMediaType)
        .value("eRequestedRangeNotSatisfyable", HttpResponseStatus::RequestedRangeNotSatisfyable)
        .value("eExpectationFailed", HttpResponseStatus::ExpectationFailed)
        .value("eInternalServerError", HttpResponseStatus::InternalServerError)
        .value("eNotImplemented", HttpResponseStatus::NotImplemented)
        .value("eBadGateway", HttpResponseStatus::BadGateway)
        .value("eServiceUnavailable", HttpResponseStatus::ServiceUnavailable)
        .value("eGatewayTimeout", HttpResponseStatus::GatewayTimeout)
        .value("eHttpVersionNotSupported", HttpResponseStatus::HttpVersionNotSupported)
        .export_values();

    //===================================================================================
    // struct HttpRequest
    py::class_< HttpRequest> c1(m, "HttpRequest");

    c1.def(py::init([] (Utf8CP url, py::dict const& header)
                    {
                    bmap<Utf8String, Utf8String> dictMap;
                    for (auto& it : header)
                        dictMap.insert(make_bpair(it.first.cast<Utf8String>(), it.second.cast<Utf8String>()));

                    return new HttpRequest(url, dictMap);
                    }), "url"_a, "header"_a);

    c1.def_property("Url", &HttpRequest::GetUrl, &HttpRequest::SetUrl);
    c1.def("GetUrl", &HttpRequest::GetUrl);
    c1.def("SetUrl", &HttpRequest::SetUrl, "url"_a);

    c1.def_property("Authentication", &HttpRequest::GetAuthentication, &HttpRequest::SetAuthentication);
    c1.def("GetAuthentication", &HttpRequest::GetAuthentication);
    c1.def("SetAuthentication", &HttpRequest::SetAuthentication, "value"_a);

    c1.def_property("Header", 
                    [] (HttpRequest const& self)
                    {
                    py::dict dict;
                    auto& dictMap = self.GetHeader();
                    for (auto it = dictMap.begin(); it != dictMap.end(); ++it)
                        dict[py::cast(it->first)] = py::cast(it->second);
                    return dict;
                    }, 
                    [] (HttpRequest& self, py::dict const& header)
                        {
                        bmap<Utf8String, Utf8String> dictMap;
                        for (auto& it : header)
                            dictMap.insert(make_bpair(it.first.cast<Utf8String>(), it.second.cast<Utf8String>()));
                        self.SetHeader(dictMap);
                        });
    c1.def("GetHeader", [] (HttpRequest const& self)
           {
           py::dict dict;
           auto& dictMap = self.GetHeader();
           for (auto it = dictMap.begin(); it != dictMap.end(); ++it)
               dict[py::cast(it->first)] = py::cast(it->second);
           return dict;
           });

    c1.def("SetHeader", [] (HttpRequest& self, py::dict const& header)
           {
           bmap<Utf8String, Utf8String> dictMap;
           for (auto& it : header)
               dictMap.insert(make_bpair(it.first.cast<Utf8String>(), it.second.cast<Utf8String>()));
           self.SetHeader(dictMap);
           });

    //===================================================================================
    // struct HttpResponse
    py::class_< HttpResponse, HttpResponsePtr> c2(m, "HttpResponse");

    c2.def_property_readonly("Status", &HttpResponse::GetStatus);
    c2.def("GetStatus", &HttpResponse::GetStatus);

    c2.def_property_readonly("Header", [] (HttpResponse const& self)
                             {
                             auto& dictMap = self.GetHeader();
                             py::dict dict;
                             for (auto it = dictMap.begin(); it != dictMap.end(); ++it)
                                 dict[py::cast(it->first)] = py::cast(it->second);

                             return dict;
                             });
    c2.def("GetHeader", [] (HttpResponse const& self)
                             {
                             auto& dictMap = self.GetHeader();
                             py::dict dict;
                             for (auto it = dictMap.begin(); it != dictMap.end(); ++it)
                                 dict[py::cast(it->first)] = py::cast(it->second);

                             return dict;
                             });

    c2.def_property_readonly("Body", [] (HttpResponse const& self)
                             {
                             auto& data = self.GetBody();
                             return py::bytes((const char*) data.data(), data.size());
                             });
    c2.def("GetBody", [] (HttpResponse const& self)
                             {
                             auto& data = self.GetBody();
                             return py::bytes((const char*) data.data(), data.size());
                             });

    //===================================================================================
    // struct IHttpRequestCancellationToken
    py::class_ < IHttpRequestCancellationToken, std::unique_ptr< IHttpRequestCancellationToken, py::nodelete>, IPyHttpRequestCancellationToken> c3(m, "IHttpRequestCancellationToken");

    c3.def(py::init<>());
    c3.def("_ShouldCancelHttpRequest", &IHttpRequestCancellationTokenPub::_ShouldCancelHttpRequest);
    c3.def("_UpdateProgressInfo", &IHttpRequestCancellationTokenPub::_UpdateProgressInfo, "dltotal"_a, "dlnow"_a, "ultotal"_a, "ulnow"_a);

    //===================================================================================
    // struct HttpHandler
    py::class_< HttpHandler> c4(m, "HttpHandler");

    c4.def_static("Instance", &HttpHandler::Instance, py::return_value_policy::reference_internal);
    c4.def("Request", [] (HttpHandler& self, HttpRequest const& request, IHttpRequestCancellationToken const* cancellationToken)
           {
           HttpResponsePtr response;
           auto retVal = self.Request(response, request, cancellationToken);
           return py::make_tuple(retVal, response);
           }, "request"_a, "cancellationToken"_a);
    }