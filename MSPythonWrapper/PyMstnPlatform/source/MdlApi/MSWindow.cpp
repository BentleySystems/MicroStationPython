/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyMstnPlatform\source\MdlApi\MSWindow.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <Mstn/MdlApi/MSWindow.h>



static const char * __doc_Bentley_MstnPlatform_MSWindow_GetViewport =R"doc(Returns the Window's Viewport only if the Window is a View window.
@Return A pointer to the IndexedViewport associated with the View
window

See also:
    IndexedViewport

Remark:
    Required Library:mdlbltin.lib)doc";

static const char * __doc_Bentley_MstnPlatform_MSWindow_GetGlobalRectLocal =R"doc(Gets the global rectangle for the Window in local coordinates.
@Remarks Each window has an associated content and global rectangle.
The content rectangle is the window portion on which the application
draws. The global rectangle includes the window's content rectangle
and borders and title rectangle. The GetContentRectLocal and
GetContentRectGlobal methods get the content rectangle for the Window,
and GetGlobalRectLocal and GetGlobalRectGlobal are used to get the
global rectangle for the Window. Get...RectLocal methods return the
rectangle in local coordinates, while the Get...RectGlobal method
return the same information in global coordinates. @Param[out] rect
global rect in local coords @Return SUCCESS or ERROR

Remark:
    Required Library:mdlbltin.lib)doc";

static const char * __doc_Bentley_MstnPlatform_MSWindow_GetGlobalRectGlobal =R"doc(Gets the global rectangle for the Window in global coordinates.
@Remarks Each window has an associated content and global rectangle.
The content rectangle is the window portion on which the application
draws. The global rectangle includes the window's content rectangle
and borders and title rectangle. The GetContentRectLocal and
GetContentRectGlobal methods get the content rectangle for the Window,
and GetGlobalRectLocal and GetGlobalRectGlobal are used to get the
global rectangle for the Window. Get...RectLocal methods return the
rectangle in local coordinates, while the Get...RectGlobal method
return the same information in global coordinates. @Param[out] rect
global rect in global coords @Return SUCCESS or ERROR

Remark:
    Required Library:mdlbltin.lib)doc";

static const char * __doc_Bentley_MstnPlatform_MSWindow_GetContentRectLocal =R"doc(Gets the content rectangle for the Window in local coordinates.
@Remarks Each window has an associated content and global rectangle.
The content rectangle is the window portion on which the application
draws. The global rectangle includes the window's content rectangle
and borders and title rectangle. The GetContentRectLocal and
GetContentRectGlobal methods get the content rectangle for the Window,
and GetGlobalRectLocal and GetGlobalRectGlobal are used to get the
global rectangle for the Window. Get...RectLocal methods return the
rectangle in local coordinates, while the Get...RectGlobal method
return the same information in global coordinates. @Param[out] rect
content rect in local coords @Return SUCCESS or ERROR

Remark:
    Required Library:mdlbltin.lib)doc";

static const char * __doc_Bentley_MstnPlatform_MSWindow_GetContentRectGlobal =R"doc(Gets the content rectangle for the Window in global coordinates.
@Remarks Each window has an associated content and global rectangle.
The content rectangle is the window portion on which the application
draws. The global rectangle includes the window's content rectangle
and borders and title rectangle. The GetContentRectLocal and
GetContentRectGlobal methods get the content rectangle for the Window,
and GetGlobalRectLocal and GetGlobalRectGlobal are used to get the
global rectangle for the Window. Get...RectLocal methods return the
rectangle in local coordinates, while the Get...RectGlobal method
return the same information in global coordinates. @Param[out] rect
content rect in global coords @Return SUCCESS or ERROR

Remark:
    Required Library:mdlbltin.lib)doc";

static const char * __doc_Bentley_MstnPlatform_MSWindow_GetAttributes =R"doc(Returns a reference to the Windows attributes.

See also:
    GuiWAttributes)doc";

static const char * __doc_Bentley_MstnPlatform_MSWindow_ClearRect =R"doc(Clears the rectangle in the Window's background color. The affected
window is passed in rectP. A clipping rectangle can be passed in
clipRectP. If clipRectP is NULL, the rectangle is clipped to the
window's content rectangle. @Param[in] rectP rectangle to clear
@Param[in] clipRectP overriding clip rectangle)doc";

static const char * __doc_Bentley_MstnPlatform_MSWindow_Show =R"doc(Shows the Window, initially or after a hide operation. @Remarks The
Hide method temporarily hides the Window. The Show method brings it
back into view. The Close method hides the window and destroys it.

Parameter ``noInitialUpdate``:
    inhibits the first refresh message normally sent when the Window
    is first displayed. Generally, this argument should be set to
    false. @Return SUCCESS, or ERROR if the Window could not be shown.

Remark:
    Required Library:mdlbltin.lib)doc";

static const char * __doc_Bentley_MstnPlatform_MSWindow_Hide =R"doc(Temporarily hides the Window @Remarks The Show method brings the
Window back into view. The Close method hides the Window and destroys
it. @Param[in] reasonCode reason code for the hide - HideReasonCode
enum found in dlogitem.h. @Param[in] bypassFocusOut bypass the focus
out, usually false @Return SUCCESS, or ERROR if the window refused to
relinquish focus and bypassFocusOut is false.

Remark:
    Required Library:mdlbltin.lib)doc";

static const char * __doc_Bentley_MstnPlatform_MSWindow_Close =R"doc(Closes the window by hiding it then destroying it @Param[in]
reasonCode reason code for the close - HideReasonCode enum found in
dlogitem.h. @Param[in] bypassFocusOut bypass the focus out @Return
SUCCESS or ERROR An error may be caused if the window refused to
relinquish focus and bypassFocusOut is false.

Remark:
    Required Library:mdlbltin.lib)doc";

static const char * __doc_Bentley_MstnPlatform_MSWindow_Activate =R"doc(Attempts to set the input focus to the Window.

Parameter ``requestType``:
    should always be set to 1, because the call will not be in
    response to a user button event. @Param[in] bypassFocusOut should
    only be set to true if the focus is to be changed to the specified
    window regardless of whether the current focus window wants to
    relinquish the focus. Dialog boxes, for example, refuse to
    relinquish the focus if the item focus is set to a text item, and
    the input currently in the text item is invalid. In general, MDL
    programs should set this argument to false, to make sure they are
    cooperative with other applications. @Param[in]
    ignoreFocusOutErrors should only be set to true if forcing focus
    to the Window @Return SUCCESS, or a non-zero value if the system
    cannot set the focus to the Window.

Remark:
    Required Library:mdlbltin.lib)doc";

static const char * __doc_Bentley_MstnPlatform_MSWindow_IsResizable =R"doc(Determines whether the Window is resizable)doc";

static const char * __doc_Bentley_MstnPlatform_MSWindow_IsVisible =R"doc(Determines whether the Window is visible)doc";

static const char * __doc_Bentley_MstnPlatform_MSWindow_IsObscured =R"doc(Determines whether the Window is obscured)doc";

static const char * __doc_Bentley_MstnPlatform_MSWindow_IsFocusable =R"doc(Determines whether the Window is focusable)doc";

static const char * __doc_Bentley_MstnPlatform_MSWindow_IsDoubleBuffered =R"doc(Determines whether the Window is double-buffered)doc";

static const char * __doc_Bentley_MstnPlatform_MSWindow_IsActive =R"doc(Determines whether the Window is active)doc";


/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                      9/2024
+---------------+---------------+---------------+---------------+---------------+------*/
void def_MSWindow(py::module_& m)
{
    py::class_<MSWindow, BaseWindow> c1(m, "MSWindow");
    c1.def("IsActive", &MSWindow::IsActive, DOC(Bentley, MstnPlatform, MSWindow, IsActive));
    c1.def("IsDoubleBuffered", &MSWindow::IsDoubleBuffered, DOC(Bentley, MstnPlatform, MSWindow, IsDoubleBuffered));
    c1.def("IsFocusable", &MSWindow::IsFocusable, DOC(Bentley, MstnPlatform, MSWindow, IsFocusable));
    c1.def("IsObscured", &MSWindow::IsObscured, DOC(Bentley, MstnPlatform, MSWindow, IsObscured));
    c1.def("IsVisible", &MSWindow::IsVisible, DOC(Bentley, MstnPlatform, MSWindow, IsVisible));
    c1.def("IsResizable", &MSWindow::IsResizable, DOC(Bentley, MstnPlatform, MSWindow, IsResizable));
    c1.def("Activate", &MSWindow::Activate, "requestType"_a, "bypassFocusOut"_a, "ignoreFocusOutErrors"_a = false, DOC(Bentley, MstnPlatform, MSWindow, Activate));
    c1.def("Close", &MSWindow::Close, "reasonCode"_a, "bypassFocusOut"_a, DOC(Bentley, MstnPlatform, MSWindow, Close));
    c1.def("Hide", &MSWindow::Hide, "reasonCode"_a, "bypassFocusOut"_a, DOC(Bentley, MstnPlatform, MSWindow, Hide));
    c1.def("Show", &MSWindow::Show, "noInitialUpdate"_a, DOC(Bentley, MstnPlatform, MSWindow, Show));
    c1.def("ClearRect", &MSWindow::ClearRect, "rectP"_a, "clipRectP"_a = nullptr, DOC(Bentley, MstnPlatform, MSWindow, ClearRect));
    c1.def("GetAttributes", &MSWindow::GetAttributes, py::return_value_policy::reference_internal, DOC(Bentley, MstnPlatform, MSWindow, GetAttributes));
    c1.def("GetContentRectGlobal", &MSWindow::GetContentRectGlobal, "rect"_a, DOC(Bentley, MstnPlatform, MSWindow, GetContentRectGlobal));
    c1.def("GetContentRectLocal", &MSWindow::GetContentRectLocal, "rect"_a, DOC(Bentley, MstnPlatform, MSWindow, GetContentRectLocal));
    c1.def("GetGlobalRectGlobal", &MSWindow::GetGlobalRectGlobal, "rect"_a, DOC(Bentley, MstnPlatform, MSWindow, GetGlobalRectGlobal));
    c1.def("GetGlobalRectLocal", &MSWindow::GetGlobalRectLocal, "rect"_a, DOC(Bentley, MstnPlatform, MSWindow, GetGlobalRectLocal));
    c1.def("GetViewport", &MSWindow::GetViewport, py::return_value_policy::reference_internal, DOC(Bentley, MstnPlatform, MSWindow, GetViewport));
}
