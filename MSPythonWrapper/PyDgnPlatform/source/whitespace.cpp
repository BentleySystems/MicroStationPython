/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnPlatform\source\whitespace.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <DgnPlatform/TextBlock/WhiteSpace.h>



/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_WhiteSpace(py::module_& m)
    {
    //===================================================================================
    // struct WhiteSpace
    py::class_< WhiteSpace, Run> c1(m, "WhiteSpace");

    //===================================================================================
    // struct ParagraphBreak
    py::class_< ParagraphBreak, WhiteSpace> c2(m, "ParagraphBreak");

    //===================================================================================
    // struct LineBreak
    py::class_< LineBreak, WhiteSpace> c3(m, "LineBreak");

    //===================================================================================
    // struct Tab
    py::class_< Tab, WhiteSpace> c4(m, "Tab");
    }