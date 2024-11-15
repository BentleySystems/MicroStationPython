/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyMstnPlatform\source\GUI\guiview.cpp $
|
|  $Copyright: (c) 2024 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <DgnPlatform/ViewInfo.h>

static const char* __doc_Bentley_DgnPlatform_ViewPortInfo_From = R"doc(Copies the contents of the numbered ViewPortInfo to the target ViewPortInfo

Parameter ``target``:
    The target ViewPortInfo

Parameter ``viewNumber``:
    The view number, between 0 and MAX_VIEWS-1, inclusive.)doc";

BEGIN_BENTLEY_MSTNPLATFORM_MSPYTHON_NAMESPACE

struct MstnViewPortInfo
    {
    static StatusInt From(ViewPortInfoPtr target, UInt32 viewNumber)
        {
        if (target.IsValid() && SUCCESS == target->From(viewNumber))
            return SUCCESS;

        return  ERROR;
        }
    };

END_BENTLEY_MSTNPLATFORM_MSPYTHON_NAMESPACE

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_GuiView(py::module_& m)
{
    //===================================================================================
    // struct ViewPortInfo
    py::class_< MstnViewPortInfo> c0(m, "MstnViewPortInfo");
    c0.def_static("From", &MstnViewPortInfo::From, "target"_a, "viewNumber"_a, DOC(Bentley, DgnPlatform, ViewPortInfo, From));
}
