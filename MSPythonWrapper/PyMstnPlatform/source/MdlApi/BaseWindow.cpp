/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyMstnPlatform\source\MdlApi\BaseWindow.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <Mstn/MdlApi/BaseWindow.h>



static const char * __doc_Bentley_MstnPlatform_BaseWindow_SetTitle =R"doc(Sets the title for the Window. @Param(input) title The new title for the
Window)doc";

static const char * __doc_Bentley_MstnPlatform_BaseWindow_GetTitle =R"doc(Gets the title for the Window. @Param(output) title A WString that
receives a copy of the Window's title)doc";

static const char * __doc_Bentley_MstnPlatform_BaseWindow_GetDoubleBufferContext =R"doc(Returns the double-buffer context for the Window)doc";

static const char * __doc_Bentley_MstnPlatform_BaseWindow_GetScreenContext =R"doc(Returns the screen device context for the Window)doc";

static const char * __doc_Bentley_MstnPlatform_BaseWindow_GetDockPriority =R"doc(Returns the dock priority of the Window

See also:
    DockPriority)doc";

static const char * __doc_Bentley_MstnPlatform_BaseWindow_GetDockPosition =R"doc(Returns the dock position of the Window

See also:
    DockPosition)doc";

static const char * __doc_Bentley_MstnPlatform_BaseWindow_GetDockExtent =R"doc(Returns the size of the Window as docked)doc";

static const char * __doc_Bentley_MstnPlatform_BaseWindow_Minimized =R"doc(Determines whether the Window is currently minimized)doc";

static const char * __doc_Bentley_MstnPlatform_BaseWindow_Maximized =R"doc(Determines whether the Window is currently maximized)doc";

static const char * __doc_Bentley_MstnPlatform_BaseWindow_IsDisplayed =R"doc(Determines whether the Window has been displayed initially)doc";

static const char * __doc_Bentley_MstnPlatform_WindowInfo_GetScreenNumber =R"doc(Returns the screen number for the Window)doc";

static const char * __doc_Bentley_MstnPlatform_WindowInfo_GetGraphHandle =R"doc(Returns the Graphics Handle for the Window. In Microsoft Windows, this
is an HWND.)doc";

static const char * __doc_Bentley_MstnPlatform_WindowInfo_GetPrevious =R"doc(Returns the previous Window in the linked list)doc";

static const char * __doc_Bentley_MstnPlatform_WindowInfo_GetNext =R"doc(Returns the next Window in the linked list)doc";


/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                      9/2024
+---------------+---------------+---------------+---------------+---------------+------*/
void def_BaseWindow(py::module_& m)
{
    py::class_<WindowInfo> c1(m, "WindowInfo");
    c1.def("GetNext", &WindowInfo::GetNext, py::return_value_policy::reference_internal, DOC(Bentley, MstnPlatform, WindowInfo, GetNext));
    c1.def("GetPrevious", &WindowInfo::GetPrevious, py::return_value_policy::reference_internal, DOC(Bentley, MstnPlatform, WindowInfo, GetPrevious));
    c1.def("GetGraphHandle", 
        [](WindowInfo& self) { return reinterpret_cast<uintptr_t>(self.GetGraphHandle()); }, DOC(Bentley, MstnPlatform, WindowInfo, GetGraphHandle));
    c1.def("GetScreenNumber", &WindowInfo::GetScreenNumber, DOC(Bentley, MstnPlatform, WindowInfo, GetScreenNumber));

    py::class_<BaseWindow, WindowInfo> c2(m, "BaseWindow");
    c2.def("IsDisplayed", &BaseWindow::IsDisplayed, DOC(Bentley, MstnPlatform, BaseWindow, IsDisplayed));
    c2.def("Maximized", &BaseWindow::Maximized, DOC(Bentley, MstnPlatform, BaseWindow, Maximized));
    c2.def("Minimized", &BaseWindow::Minimized, DOC(Bentley, MstnPlatform, BaseWindow, Minimized));
    c2.def("GetDockExtent", &BaseWindow::GetDockExtent, DOC(Bentley, MstnPlatform, BaseWindow, GetDockExtent));
    c2.def("GetDockPosition", &BaseWindow::GetDockPosition, DOC(Bentley, MstnPlatform, BaseWindow, GetDockPosition));
    c2.def("GetDockPriority", &BaseWindow::GetDockPriority, DOC(Bentley, MstnPlatform, BaseWindow, GetDockPriority));
    c2.def("GetScreenContext",
        [](BaseWindow& self) { return reinterpret_cast<uintptr_t>(self.GetScreenContext()); }, DOC(Bentley, MstnPlatform, BaseWindow, GetScreenContext));
    c2.def("GetDoubleBufferContext",
        [](BaseWindow& self) { return reinterpret_cast<uintptr_t>(self.GetDoubleBufferContext()); }, DOC(Bentley, MstnPlatform, BaseWindow, GetDoubleBufferContext));
    c2.def("GetTitle", &BaseWindow::GetTitleCP, DOC(Bentley, MstnPlatform, BaseWindow, GetTitle));
    c2.def("SetTitle", &BaseWindow::SetTitle, "title"_a, DOC(Bentley, MstnPlatform, BaseWindow, SetTitle));
}
